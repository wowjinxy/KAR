using System;

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
    }
}
