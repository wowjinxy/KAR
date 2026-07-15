using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceByteDumpResult
    {
        internal KarProjectResourceByteDumpResult(
            KarProjectResourceInfo resource,
            string outputRelativePath,
            string outputPath,
            int length,
            string sha256,
            bool wroteOutput)
        {
            Resource = resource ?? throw new ArgumentNullException(nameof(resource));
            OutputRelativePath = outputRelativePath ?? throw new ArgumentNullException(nameof(outputRelativePath));
            OutputPath = outputPath ?? throw new ArgumentNullException(nameof(outputPath));
            Length = length;
            Sha256 = sha256 ?? throw new ArgumentNullException(nameof(sha256));
            WroteOutput = wroteOutput;
        }

        public KarProjectResourceInfo Resource { get; }

        public KarResourceReference Reference => Resource.Reference;

        public KarResourceKind Kind => Resource.Kind;

        public string Address => Resource.Address;

        public string OutputRelativePath { get; }

        public string OutputPath { get; }

        public int Length { get; }

        public string Sha256 { get; }

        public bool WroteOutput { get; }
    }
}
