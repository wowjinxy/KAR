using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectA2DEntryApplyResult
    {
        internal KarProjectA2DEntryApplyResult(
            KarProjectA2DEntryOutputInfo output,
            KarProjectA2DEntryReplaceResult replaceResult)
        {
            Output = output ?? throw new ArgumentNullException(nameof(output));
            ReplaceResult = replaceResult ?? throw new ArgumentNullException(nameof(replaceResult));
        }

        public KarProjectA2DEntryOutputInfo Output { get; }

        public KarProjectA2DEntryInfo Entry => Output.Entry;

        public string EntryPath => Entry.EntryPath;

        public string SidecarOutputPath => Output.OutputPath;

        public KarProjectA2DEntryReplaceResult ReplaceResult { get; }

        public KarProjectFile PackageFile => ReplaceResult.PackageFile;

        public string PackageRelativePath => ReplaceResult.PackageRelativePath;

        public KarProjectFileWriteResult WriteResult => ReplaceResult.WriteResult;

        public string PackageOutputPath => ReplaceResult.OutputPath;

        public int ReplacementLength => ReplaceResult.ReplacementLength;
    }
}
