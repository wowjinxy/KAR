using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceOutputInfo
    {
        internal KarProjectResourceOutputInfo(
            KarProjectResourceInfo resource,
            KarProjectResourceOutputKind outputKind,
            KarProjectResourceOutputStatus status,
            string outputRelativePath,
            string outputPath,
            KarProjectOutputFileInfo projectFileOutput,
            KarProjectA2DEntryOutputInfo a2dEntryOutput)
        {
            Resource = resource ?? throw new ArgumentNullException(nameof(resource));
            OutputKind = outputKind;
            Status = status;
            OutputRelativePath = outputRelativePath ?? throw new ArgumentNullException(nameof(outputRelativePath));
            OutputPath = outputPath ?? throw new ArgumentNullException(nameof(outputPath));
            ProjectFileOutput = projectFileOutput;
            A2DEntryOutput = a2dEntryOutput;
        }

        public KarProjectResourceInfo Resource { get; }

        public KarResourceReference Reference => Resource.Reference;

        public KarResourceKind Kind => Resource.Kind;

        public string Address => Resource.Address;

        public KarProjectResourceOutputKind OutputKind { get; }

        public KarProjectResourceOutputStatus Status { get; }

        public string OutputRelativePath { get; }

        public string OutputPath { get; }

        public KarProjectOutputFileInfo ProjectFileOutput { get; }

        public KarProjectA2DEntryOutputInfo A2DEntryOutput { get; }

        public bool HasProjectFileOutput => ProjectFileOutput != null;

        public bool HasOutputAsset => A2DEntryOutput != null && A2DEntryOutput.HasOutput;

        public bool HasOutput => Status != KarProjectResourceOutputStatus.Missing;

        public bool IsMissing => Status == KarProjectResourceOutputStatus.Missing;

        public bool IsModified =>
            Status == KarProjectResourceOutputStatus.DiffersFromSource ||
            Status == KarProjectResourceOutputStatus.SidecarDiffersFromEntry;

        public bool IsUnchanged =>
            Status == KarProjectResourceOutputStatus.MatchesSource ||
            Status == KarProjectResourceOutputStatus.SidecarMatchesEntry;

        public bool IsProjectFileOutput => OutputKind == KarProjectResourceOutputKind.ProjectFile;

        public bool IsOutputAsset => OutputKind == KarProjectResourceOutputKind.OutputAsset;
    }
}
