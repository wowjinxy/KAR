using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectFileWriteResult
    {
        public KarProjectFileWriteResult(
            KarProjectFile file,
            string relativePath,
            string outputPath,
            DateTime outputLastWriteTimeUtc)
        {
            RelativePath = KarProjectWorkspace.NormalizeRelativePath(relativePath);
            File = file;
            OutputPath = outputPath ?? throw new ArgumentNullException(nameof(outputPath));
            OutputLastWriteTimeUtc = outputLastWriteTimeUtc;
        }

        public KarProjectFile File { get; }

        public bool HasProjectFile => File != null;

        public string RelativePath { get; }

        public string OutputPath { get; }

        public DateTime OutputLastWriteTimeUtc { get; }
    }
}
