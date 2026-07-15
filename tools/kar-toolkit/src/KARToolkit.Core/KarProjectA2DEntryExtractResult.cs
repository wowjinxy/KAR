using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectA2DEntryExtractResult
    {
        internal KarProjectA2DEntryExtractResult(
            KarProjectA2DEntryInfo entry,
            string outputRelativePath,
            string outputPath,
            bool wroteOutput)
        {
            Entry = entry ?? throw new ArgumentNullException(nameof(entry));
            OutputRelativePath = outputRelativePath ?? throw new ArgumentNullException(nameof(outputRelativePath));
            OutputPath = outputPath ?? throw new ArgumentNullException(nameof(outputPath));
            WroteOutput = wroteOutput;
        }

        public KarProjectA2DEntryInfo Entry { get; }

        public string OutputRelativePath { get; }

        public string OutputPath { get; }

        public bool WroteOutput { get; }
    }
}
