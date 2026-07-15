using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectFileCopyResult
    {
        public KarProjectFileCopyResult(KarProjectFile file, string outputPath, DateTime sourceLastWriteTimeUtc)
        {
            File = file ?? throw new ArgumentNullException(nameof(file));
            OutputPath = outputPath ?? throw new ArgumentNullException(nameof(outputPath));
            SourceLastWriteTimeUtc = sourceLastWriteTimeUtc;
        }

        public KarProjectFile File { get; }

        public string OutputPath { get; }

        public DateTime SourceLastWriteTimeUtc { get; }
    }
}
