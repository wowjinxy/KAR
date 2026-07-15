using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectModManifestArtifact
    {
        internal KarProjectModManifestArtifact(
            KarProjectModManifestArtifactKind kind,
            string outputRelativePath,
            string outputPath,
            string projectRelativePath,
            string resourceAddress,
            string referenceKind,
            string referenceAddress,
            string referencePath,
            long? referenceLength,
            string referenceSha256,
            string status,
            long outputLength,
            DateTime outputLastWriteTimeUtc,
            string outputSha256,
            bool isModified,
            bool isUnchanged,
            bool isOutputOnly,
            bool isSidecar,
            bool needsApply)
        {
            Kind = kind;
            OutputRelativePath = outputRelativePath ?? throw new ArgumentNullException(nameof(outputRelativePath));
            OutputPath = outputPath ?? throw new ArgumentNullException(nameof(outputPath));
            ProjectRelativePath = projectRelativePath;
            ResourceAddress = resourceAddress;
            ReferenceKind = referenceKind;
            ReferenceAddress = referenceAddress;
            ReferencePath = referencePath;
            ReferenceLength = referenceLength;
            ReferenceSha256 = referenceSha256;
            Status = status ?? throw new ArgumentNullException(nameof(status));
            OutputLength = outputLength;
            OutputLastWriteTimeUtc = outputLastWriteTimeUtc;
            OutputSha256 = outputSha256;
            IsModified = isModified;
            IsUnchanged = isUnchanged;
            IsOutputOnly = isOutputOnly;
            IsSidecar = isSidecar;
            NeedsApply = needsApply;
        }

        public KarProjectModManifestArtifactKind Kind { get; }

        public string OutputRelativePath { get; }

        public string OutputPath { get; }

        public string ProjectRelativePath { get; }

        public string ResourceAddress { get; }

        public string ReferenceKind { get; }

        public string ReferenceAddress { get; }

        public string ReferencePath { get; }

        public long? ReferenceLength { get; }

        public string ReferenceSha256 { get; }

        public string Status { get; }

        public long OutputLength { get; }

        public DateTime OutputLastWriteTimeUtc { get; }

        public string OutputSha256 { get; }

        public bool IsModified { get; }

        public bool IsUnchanged { get; }

        public bool IsOutputOnly { get; }

        public bool IsSidecar { get; }

        public bool NeedsApply { get; }
    }
}
