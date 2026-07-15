namespace KARToolkit.Core
{
    public sealed class KarProjectToolkitSnapshotOptions
    {
        public bool IncludeModWorkspace { get; set; } = true;

        public bool IncludeMapContexts { get; set; } = true;

        public bool IncludeVehicleContexts { get; set; } = true;

        public bool IncludeA2DPackageContexts { get; set; } = true;

        public bool IncludeScriptTableContexts { get; set; } = true;

        public KarProjectModWorkspaceOptions ModWorkspace { get; set; }

        public KarProjectMapScriptQueryOptions MapContexts { get; set; }

        public KarProjectVehicleQueryOptions VehicleContexts { get; set; }

        public KarProjectA2DPackageContextQueryOptions A2DPackageContexts { get; set; }

        public KarProjectScriptTableContextQueryOptions ScriptTableContexts { get; set; }
    }
}
