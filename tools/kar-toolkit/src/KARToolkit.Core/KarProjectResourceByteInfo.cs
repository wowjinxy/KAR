using System;
using System.IO;
using System.Linq;
using System.Security.Cryptography;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceByteInfo
    {
        internal KarProjectResourceByteInfo(
            KarProjectResourceInfo resource,
            string outputRelativePath,
            string outputPath,
            byte[] activeData)
        {
            Resource = resource ?? throw new ArgumentNullException(nameof(resource));
            OutputRelativePath = KarProjectWorkspace.NormalizeRelativePath(outputRelativePath);
            OutputPath = outputPath ?? throw new ArgumentNullException(nameof(outputPath));
            ActiveLength = activeData == null ? 0 : activeData.Length;
            ActiveSha256 = activeData == null ? null : ComputeSha256(activeData);

            FileInfo outputInfo = new FileInfo(OutputPath);
            HasOutput = outputInfo.Exists;
            OutputLength = outputInfo.Exists ? outputInfo.Length : 0;
            OutputLastWriteTimeUtc = outputInfo.Exists ? outputInfo.LastWriteTimeUtc : DateTime.MinValue;
            OutputSha256 = outputInfo.Exists ? ComputeSha256(OutputPath) : null;
            Status = GetStatus();
        }

        public KarProjectResourceInfo Resource { get; }

        public KarResourceReference Reference => Resource.Reference;

        public KarResourceKind Kind => Resource.Kind;

        public string Address => Resource.Address;

        public string OutputRelativePath { get; }

        public string OutputPath { get; }

        public int ActiveLength { get; }

        public string ActiveSha256 { get; }

        public bool HasOutput { get; }

        public long OutputLength { get; }

        public DateTime OutputLastWriteTimeUtc { get; }

        public string OutputSha256 { get; }

        public bool? IsSameLengthAsActive => HasOutput ? OutputLength == ActiveLength : (bool?)null;

        public bool? IsSameContentAsActive
        {
            get
            {
                if (OutputSha256 == null || ActiveSha256 == null)
                    return null;

                return string.Equals(OutputSha256, ActiveSha256, StringComparison.OrdinalIgnoreCase);
            }
        }

        public KarProjectResourceByteOutputStatus Status { get; }

        public bool IsMissing => Status == KarProjectResourceByteOutputStatus.Missing;

        public bool MatchesActive => Status == KarProjectResourceByteOutputStatus.MatchesActive;

        public bool DiffersFromActive => Status == KarProjectResourceByteOutputStatus.DiffersFromActive;

        private KarProjectResourceByteOutputStatus GetStatus()
        {
            if (!HasOutput)
                return KarProjectResourceByteOutputStatus.Missing;

            return IsSameContentAsActive == true
                ? KarProjectResourceByteOutputStatus.MatchesActive
                : KarProjectResourceByteOutputStatus.DiffersFromActive;
        }

        private static string ComputeSha256(string path)
        {
            using (SHA256 sha256 = SHA256.Create())
            using (FileStream stream = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.ReadWrite))
            {
                return string.Concat(sha256.ComputeHash(stream).Select(value => value.ToString("x2")));
            }
        }

        private static string ComputeSha256(byte[] data)
        {
            using (SHA256 sha256 = SHA256.Create())
            {
                return string.Concat(sha256.ComputeHash(data).Select(value => value.ToString("x2")));
            }
        }
    }
}
