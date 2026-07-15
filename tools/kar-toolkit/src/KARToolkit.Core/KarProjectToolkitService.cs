using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectToolkitService
    {
        private readonly KarProject _project;

        internal KarProjectToolkitService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public KarProjectToolkitRegistryCatalog CreateRegistryCatalog()
        {
            return _project.SchemaService.CreateToolkitRegistryCatalog();
        }

        public KarProjectToolkitRegistryCatalogContract CreateRegistryCatalogContract()
        {
            return CreateRegistryCatalog().CreateContract();
        }

        public KarProjectToolkitSnapshot CreateSnapshot(KarProjectToolkitSnapshotOptions options = null)
        {
            options = options ?? new KarProjectToolkitSnapshotOptions();

            return new KarProjectToolkitSnapshot(
                _project,
                options.IncludeModWorkspace ? _project.ModWorkspaceService.CreateSnapshot(options.ModWorkspace) : null,
                options.IncludeMapContexts ? _project.MapContextService.Query(options.MapContexts) : Array.Empty<KarProjectMapContext>(),
                options.IncludeVehicleContexts ? _project.VehicleService.QueryContexts(options.VehicleContexts) : Array.Empty<KarProjectVehicleContext>(),
                options.IncludeA2DPackageContexts ? _project.A2DPackageContextService.Query(options.A2DPackageContexts) : Array.Empty<KarProjectA2DPackageContext>(),
                options.IncludeScriptTableContexts ? _project.ScriptContextService.Query(options.ScriptTableContexts) : Array.Empty<KarProjectScriptTableContext>());
        }

        public KarProjectToolkitSurface CreateSurface(KarProjectToolkitSnapshotOptions options = null)
        {
            KarProjectToolkitSnapshot snapshot = CreateSnapshot(options);
            KarProjectResourceGraph graph = _project.ResourceGraphService.Snapshot;
            IReadOnlyList<KarProjectDomainContext> domains = CreateDomainContexts(snapshot, graph);
            IReadOnlyList<KarProjectToolkitWorkflow> workflows = KarProjectToolkitWorkflowCatalog.Create(_project, snapshot, graph, domains);
            return new KarProjectToolkitSurface(_project, snapshot, domains, workflows);
        }

        public KarProjectToolkitSurfaceContract CreateSurfaceContract(KarProjectToolkitSnapshotOptions options = null)
        {
            return CreateSurface(options).CreateContract();
        }

        public IReadOnlyList<KarProjectDomainContext> QueryDomainContexts(KarProjectToolkitSnapshotOptions options = null)
        {
            KarProjectToolkitSnapshot snapshot = CreateSnapshot(options);
            KarProjectResourceGraph graph = _project.ResourceGraphService.Snapshot;
            return CreateDomainContexts(snapshot, graph);
        }

        public IReadOnlyList<KarProjectToolkitWorkflow> QueryWorkflows(
            KarProjectToolkitWorkflowQueryOptions options = null,
            KarProjectToolkitSnapshotOptions snapshotOptions = null)
        {
            options = options ?? new KarProjectToolkitWorkflowQueryOptions();
            return CreateSurface(snapshotOptions).Workflows
                .Where(options.Matches)
                .ToList()
                .AsReadOnly();
        }

        private IReadOnlyList<KarProjectDomainContext> CreateDomainContexts(
            KarProjectToolkitSnapshot snapshot,
            KarProjectResourceGraph graph)
        {
            return _project.DomainContextProviderRegistry.CreateContexts(snapshot, graph);
        }
    }
}
