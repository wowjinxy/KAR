using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectA2DEntryReplaceResult
    {
        internal KarProjectA2DEntryReplaceResult(
            KarProjectA2DEntryInfo entry,
            KarProjectFileWriteResult writeResult,
            int replacementLength)
        {
            Entry = entry ?? throw new ArgumentNullException(nameof(entry));
            WriteResult = writeResult ?? throw new ArgumentNullException(nameof(writeResult));
            ReplacementLength = replacementLength;
        }

        public KarProjectA2DEntryInfo Entry { get; }

        public KarProjectFile PackageFile => Entry.PackageFile;

        public string PackageRelativePath => Entry.PackageRelativePath;

        public KarProjectFileWriteResult WriteResult { get; }

        public string OutputPath => WriteResult.OutputPath;

        public int ReplacementLength { get; }
    }
}
