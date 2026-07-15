using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceExportResult
    {
        internal KarProjectResourceExportResult(
            KarProjectResourceInfo resource,
            KarProjectResourceOutputKind outputKind,
            string outputRelativePath,
            string outputPath,
            bool wroteOutput,
            KarProjectFileCopyResult fileCopyResult,
            KarProjectA2DEntryExtractResult a2dExtractResult)
        {
            Resource = resource ?? throw new ArgumentNullException(nameof(resource));
            OutputKind = outputKind;
            OutputRelativePath = outputRelativePath ?? throw new ArgumentNullException(nameof(outputRelativePath));
            OutputPath = outputPath ?? throw new ArgumentNullException(nameof(outputPath));
            WroteOutput = wroteOutput;
            FileCopyResult = fileCopyResult;
            A2DExtractResult = a2dExtractResult;
        }

        public KarProjectResourceInfo Resource { get; }

        public KarResourceReference Reference => Resource.Reference;

        public KarResourceKind Kind => Resource.Kind;

        public string Address => Resource.Address;

        public KarProjectResourceOutputKind OutputKind { get; }

        public string OutputRelativePath { get; }

        public string OutputPath { get; }

        public bool WroteOutput { get; }

        public KarProjectFileCopyResult FileCopyResult { get; }

        public KarProjectA2DEntryExtractResult A2DExtractResult { get; }

        public bool IsProjectFileOutput => OutputKind == KarProjectResourceOutputKind.ProjectFile;

        public bool IsOutputAsset => OutputKind == KarProjectResourceOutputKind.OutputAsset;
    }
}
