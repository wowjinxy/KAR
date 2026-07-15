using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceImportResult
    {
        internal KarProjectResourceImportResult(
            KarProjectResourceInfo resource,
            string inputPath,
            KarProjectResourceOutputKind outputKind,
            string outputRelativePath,
            string outputPath,
            int inputLength,
            KarProjectFileWriteResult fileWriteResult,
            KarProjectA2DEntryReplaceResult a2dReplaceResult)
        {
            Resource = resource ?? throw new ArgumentNullException(nameof(resource));
            InputPath = inputPath ?? throw new ArgumentNullException(nameof(inputPath));
            OutputKind = outputKind;
            OutputRelativePath = outputRelativePath ?? throw new ArgumentNullException(nameof(outputRelativePath));
            OutputPath = outputPath ?? throw new ArgumentNullException(nameof(outputPath));
            InputLength = inputLength;
            FileWriteResult = fileWriteResult;
            A2DReplaceResult = a2dReplaceResult;
        }

        public KarProjectResourceInfo Resource { get; }

        public KarResourceReference Reference => Resource.Reference;

        public KarResourceKind Kind => Resource.Kind;

        public string Address => Resource.Address;

        public string InputPath { get; }

        public KarProjectResourceOutputKind OutputKind { get; }

        public string OutputRelativePath { get; }

        public string OutputPath { get; }

        public int InputLength { get; }

        public KarProjectFileWriteResult FileWriteResult { get; }

        public KarProjectA2DEntryReplaceResult A2DReplaceResult { get; }

        public bool IsProjectFileOutput => OutputKind == KarProjectResourceOutputKind.ProjectFile;

        public bool IsOutputAsset => OutputKind == KarProjectResourceOutputKind.OutputAsset;
    }
}
