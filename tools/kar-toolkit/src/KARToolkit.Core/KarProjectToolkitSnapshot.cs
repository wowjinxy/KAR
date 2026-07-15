using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectToolkitSnapshot
    {
        internal KarProjectToolkitSnapshot(
            KarProject project,
            KarProjectModWorkspace modWorkspace,
            IReadOnlyList<KarProjectMapContext> mapContexts,
            IReadOnlyList<KarProjectVehicleContext> vehicleContexts,
            IReadOnlyList<KarProjectA2DPackageContext> a2dPackageContexts,
            IReadOnlyList<KarProjectScriptTableContext> scriptTableContexts)
        {
            Project = project ?? throw new ArgumentNullException(nameof(project));
            ModWorkspace = modWorkspace;
            MapContexts = mapContexts ?? throw new ArgumentNullException(nameof(mapContexts));
            VehicleContexts = vehicleContexts ?? throw new ArgumentNullException(nameof(vehicleContexts));
            A2DPackageContexts = a2dPackageContexts ?? throw new ArgumentNullException(nameof(a2dPackageContexts));
            ScriptTableContexts = scriptTableContexts ?? throw new ArgumentNullException(nameof(scriptTableContexts));
        }

        public KarProject Project { get; }

        public KarProjectModWorkspace ModWorkspace { get; }

        public IReadOnlyList<KarProjectMapContext> MapContexts { get; }

        public IReadOnlyList<KarProjectVehicleContext> VehicleContexts { get; }

        public IReadOnlyList<KarProjectA2DPackageContext> A2DPackageContexts { get; }

        public IReadOnlyList<KarProjectScriptTableContext> ScriptTableContexts { get; }

        public string Name => Project.Name;

        public string SourceRoot => Project.SourceRoot;

        public string OutputRoot => Project.OutputRoot;

        public int FileCount => Project.Files.Count;

        public int MapCount => Project.Maps.Count;

        public int MapContextCount => MapContexts.Count;

        public int VehicleContextCount => VehicleContexts.Count;

        public int A2DPackageContextCount => A2DPackageContexts.Count;

        public int ScriptTableContextCount => ScriptTableContexts.Count;

        public int ScriptTableOutputCount => ScriptTableContexts.Count(context => context.HasOutput);

        public int ModifiedScriptTableOutputCount => ScriptTableContexts.Count(context => context.HasModifiedOutput);

        public int A2DPackageOpenErrorCount => A2DPackageContexts.Count(context => context.HasOpenError);

        public int MapInspectionErrorCount => MapContexts.Count(context => context.HasInspectionError);

        public int VehicleInspectionErrorCount => VehicleContexts.Sum(context => context.InspectionErrorCount);

        public int DomainInspectionIssueCount => A2DPackageOpenErrorCount + MapInspectionErrorCount + VehicleInspectionErrorCount;

        public int OutputFileCount => ModWorkspace == null ? 0 : ModWorkspace.OutputFileCount;

        public int ModifiedProjectOutputFileCount => ModWorkspace == null ? 0 : ModWorkspace.ModifiedProjectOutputFileCount;

        public int ResourceOutputCount => ModWorkspace == null ? 0 : ModWorkspace.ResourceOutputCount;

        public int ModifiedResourceOutputCount => ModWorkspace == null ? 0 : ModWorkspace.ModifiedResourceOutputCount;

        public int ResourceByteOutputCount => ModWorkspace == null ? 0 : ModWorkspace.ResourceByteOutputCount;

        public int ModifiedResourceByteOutputCount => ModWorkspace == null ? 0 : ModWorkspace.ModifiedResourceByteOutputCount;

        public int A2DEntryOutputCount => ModWorkspace == null ? 0 : ModWorkspace.A2DEntryOutputCount;

        public int ModifiedA2DEntryOutputCount => ModWorkspace == null ? 0 : ModWorkspace.ModifiedA2DEntryOutputCount;

        public int CompleteMapOutputCount => ModWorkspace == null ? 0 : ModWorkspace.CompleteMapOutputCount;

        public bool HasModWorkspace => ModWorkspace != null;

        public bool HasDomainInspectionIssues => DomainInspectionIssueCount != 0;

        public bool HasOutputs => ModWorkspace != null && ModWorkspace.HasOutputs;

        public bool HasModifiedOutputs =>
            (ModWorkspace != null && ModWorkspace.HasModifiedOutputs) ||
            ModifiedScriptTableOutputCount != 0;
    }
}
