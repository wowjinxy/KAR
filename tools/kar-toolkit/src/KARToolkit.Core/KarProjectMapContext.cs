using System;
using System.Collections.Generic;

namespace KARToolkit.Core
{
    public sealed class KarProjectMapContext
    {
        internal KarProjectMapContext(
            KarMapBundle map,
            KarMapInfo inspection,
            string inspectionError,
            KarProjectMapOutputInfo output,
            KarProjectMapScriptBundle scripts)
        {
            Map = map ?? throw new ArgumentNullException(nameof(map));
            Inspection = inspection;
            InspectionError = inspectionError;
            Output = output;
            Scripts = scripts ?? throw new ArgumentNullException(nameof(scripts));
        }

        public KarMapBundle Map { get; }

        public KarMapInfo Inspection { get; }

        public string InspectionError { get; }

        public KarProjectMapOutputInfo Output { get; }

        public KarProjectMapScriptBundle Scripts { get; }

        public string MapName => Map.Name;

        public KarProjectFile DataFile => Map.DataFile;

        public KarProjectFile ModelFile => Map.ModelFile;

        public KarProjectFile EventFile => Map.EventFile;

        public KarProjectFile ScriptFile => Map.ScriptFile;

        public KarArchiveInfo DataArchive => Inspection == null ? null : Inspection.DataArchive;

        public KarArchiveInfo ModelArchive => Inspection == null ? null : Inspection.ModelArchive;

        public KarArchiveInfo EventArchive => Inspection == null ? null : Inspection.EventArchive;

        public KarArchiveInfo ScriptArchive => Inspection == null ? null : Inspection.ScriptArchive;

        public IReadOnlyList<KarArchiveInfo> Archives => Inspection == null ? Array.Empty<KarArchiveInfo>() : Inspection.Archives;

        public IReadOnlyList<KarRootDefinition> MissingRequiredRoots => Inspection == null ? Array.Empty<KarRootDefinition>() : Inspection.MissingRequiredRoots;

        public IReadOnlyList<KarProjectResourceInfo> MapResources => Scripts.MapResources;

        public IReadOnlyList<KarProjectRelationship> MapRelationships => Scripts.MapRelationships;

        public IReadOnlyList<KarProjectScriptTable> ScriptTables => Scripts.ScriptTables;

        public IReadOnlyList<KarProjectOutputFileInfo> OutputFiles => Output == null ? Array.Empty<KarProjectOutputFileInfo>() : Output.OutputFiles;

        public int ArchiveCount => Archives.Count;

        public int MissingRequiredRootCount => MissingRequiredRoots.Count;

        public int MapResourceCount => MapResources.Count;

        public int RelationshipCount => MapRelationships.Count;

        public int ScriptTableCount => ScriptTables.Count;

        public int ExpectedOutputFileCount => Output == null ? Map.Files.Count : Output.ExpectedOutputFileCount;

        public int OutputFileCount => OutputFiles.Count;

        public int ModifiedOutputFileCount => Output == null ? 0 : Output.ModifiedOutputFileCount;

        public int MissingOutputFileCount => Output == null ? ExpectedOutputFileCount : Output.MissingOutputFileCount;

        public bool HasInspection => Inspection != null;

        public bool HasInspectionError => !string.IsNullOrEmpty(InspectionError);

        public bool HasMissingRequiredRoots => MissingRequiredRootCount != 0;

        public bool HasOutput => Output != null && Output.HasOutput;

        public bool HasModifiedOutput => Output != null && Output.HasModifiedOutput;

        public bool HasCompleteOutputSet => Output != null && Output.HasCompleteOutputSet;

        public bool HasScriptArchive => Scripts.HasScriptArchive;

        public bool HasScriptTables => Scripts.HasScriptTables;

        public KarProjectMapContextSummaryContract CreateContract()
        {
            return KarProjectMapContextSummaryContract.Create(this);
        }
    }
}
