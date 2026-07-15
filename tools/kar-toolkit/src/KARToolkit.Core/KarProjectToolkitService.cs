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
            List<KarProjectDomainContext> domains = new List<KarProjectDomainContext>
            {
                new KarProjectDomainContext(
                    "files",
                    "Files",
                    "Extracted project files grouped by KAR file kind.",
                    "files",
                    "archive-contexts",
                    snapshot.FileCount,
                    graph.FileCount,
                    snapshot.OutputFileCount,
                    snapshot.ModifiedProjectOutputFileCount,
                    0),
                new KarProjectDomainContext(
                    "resources",
                    "Resources",
                    "Addressable file, HSD root, and A2D entry resources.",
                    "resources",
                    "resource-contexts",
                    graph.ResourceCount,
                    graph.ResourceCount,
                    snapshot.ResourceOutputCount + snapshot.ResourceByteOutputCount,
                    snapshot.ModifiedResourceOutputCount + snapshot.ModifiedResourceByteOutputCount,
                    0),
                new KarProjectDomainContext(
                    "maps",
                    "Maps",
                    "Map data, model, and event/script bundles.",
                    "maps",
                    "map-context",
                    snapshot.MapContextCount,
                    snapshot.MapContexts.Sum(context => context.MapResourceCount),
                    snapshot.MapContexts.Sum(context => context.OutputFileCount),
                    snapshot.MapContexts.Sum(context => context.ModifiedOutputFileCount),
                    snapshot.MapInspectionErrorCount),
                new KarProjectDomainContext(
                    "vehicles",
                    "Vehicles",
                    "Vehicle data bundles with shared common and kind-table archives.",
                    "vehicles",
                    "vehicle-context",
                    snapshot.VehicleContextCount,
                    snapshot.VehicleContexts.Sum(context => context.ResourceCount),
                    snapshot.VehicleContexts.Sum(context => context.OutputFileCount),
                    snapshot.VehicleContexts.Sum(context => context.ModifiedOutputFileCount),
                    snapshot.VehicleInspectionErrorCount),
                new KarProjectDomainContext(
                    "a2d-packages",
                    "A2D Packages",
                    "A2D packages, package entries, sidecar outputs, and packaged script tables.",
                    "a2d-packages",
                    "a2d-packages",
                    snapshot.A2DPackageContextCount,
                    snapshot.A2DPackageContexts.Sum(context => (context.Resource == null ? 0 : 1) + context.EntryCount),
                    snapshot.A2DPackageContexts.Count(context => context.HasOutput) + snapshot.A2DPackageContexts.Sum(context => context.EntryOutputCount),
                    snapshot.A2DPackageContexts.Count(context => context.HasModifiedOutput) + snapshot.A2DPackageContexts.Sum(context => context.ModifiedEntryOutputCount),
                    snapshot.A2DPackageOpenErrorCount),
                new KarProjectDomainContext(
                    "script-tables",
                    "Script Tables",
                    "Loose and packaged .tm script tables resolved as toolkit resources.",
                    "script-tables",
                    "script-contexts",
                    snapshot.ScriptTableContextCount,
                    snapshot.ScriptTableContextCount,
                    snapshot.ScriptTableOutputCount,
                    snapshot.ModifiedScriptTableOutputCount,
                    0),
                new KarProjectDomainContext(
                    "mod-output",
                    "Mod Output",
                    "Output-folder inventory, resource exports, byte dumps, and sidecars.",
                    "outputs",
                    "mod-workspace",
                    snapshot.OutputFileCount + snapshot.ResourceByteOutputCount + snapshot.A2DEntryOutputCount,
                    0,
                    snapshot.OutputFileCount + snapshot.ResourceByteOutputCount + snapshot.A2DEntryOutputCount,
                    snapshot.ModifiedProjectOutputFileCount + snapshot.ModifiedResourceByteOutputCount + snapshot.ModifiedA2DEntryOutputCount,
                    0),
            };

            return domains.AsReadOnly();
        }
    }
}
