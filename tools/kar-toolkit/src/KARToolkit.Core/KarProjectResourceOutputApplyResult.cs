using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceOutputApplyResult
    {
        internal KarProjectResourceOutputApplyResult(
            KarProjectResourceOutputInfo output,
            KarProjectA2DEntryApplyResult a2dApplyResult)
        {
            Output = output ?? throw new ArgumentNullException(nameof(output));
            A2DApplyResult = a2dApplyResult ?? throw new ArgumentNullException(nameof(a2dApplyResult));
        }

        public KarProjectResourceOutputInfo Output { get; }

        public KarProjectResourceInfo Resource => Output.Resource;

        public KarResourceReference Reference => Resource.Reference;

        public string Address => Resource.Address;

        public KarResourceKind Kind => Resource.Kind;

        public KarProjectA2DEntryApplyResult A2DApplyResult { get; }

        public KarProjectFile PackageFile => A2DApplyResult.PackageFile;

        public string PackageRelativePath => A2DApplyResult.PackageRelativePath;

        public string SidecarOutputPath => A2DApplyResult.SidecarOutputPath;

        public string PackageOutputPath => A2DApplyResult.PackageOutputPath;

        public int ReplacementLength => A2DApplyResult.ReplacementLength;
    }
}
