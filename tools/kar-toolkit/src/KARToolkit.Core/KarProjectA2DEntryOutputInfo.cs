using System;
using System.IO;
using System.Linq;
using System.Security.Cryptography;

namespace KARToolkit.Core
{
    public sealed class KarProjectA2DEntryOutputInfo
    {
        internal KarProjectA2DEntryOutputInfo(
            KarProjectA2DEntryInfo entry,
            string outputRelativePath,
            string outputPath,
            byte[] entryData)
        {
            Entry = entry ?? throw new ArgumentNullException(nameof(entry));
            OutputRelativePath = KarProjectWorkspace.NormalizeRelativePath(outputRelativePath);
            OutputPath = outputPath ?? throw new ArgumentNullException(nameof(outputPath));
            EntryLength = entryData == null ? 0 : entryData.Length;
            EntrySha256 = entryData == null ? null : ComputeSha256(entryData);

            FileInfo outputInfo = new FileInfo(OutputPath);
            HasOutput = outputInfo.Exists;
            OutputLength = outputInfo.Exists ? outputInfo.Length : 0;
            OutputLastWriteTimeUtc = outputInfo.Exists ? outputInfo.LastWriteTimeUtc : DateTime.MinValue;
            OutputSha256 = outputInfo.Exists ? ComputeSha256(OutputPath) : null;
            Status = GetStatus();
        }

        public KarProjectA2DEntryInfo Entry { get; }

        public string PackageRelativePath => Entry.PackageRelativePath;

        public string EntryName => Entry.Name;

        public string EntryPath => Entry.EntryPath;

        public string OutputRelativePath { get; }

        public string OutputPath { get; }

        public bool HasOutput { get; }

        public long OutputLength { get; }

        public DateTime OutputLastWriteTimeUtc { get; }

        public string OutputSha256 { get; }

        public int EntryLength { get; }

        public string EntrySha256 { get; }

        public bool? IsSameLengthAsEntry => HasOutput ? OutputLength == EntryLength : (bool?)null;

        public bool? IsSameContentAsEntry
        {
            get
            {
                if (OutputSha256 == null || EntrySha256 == null)
                    return null;

                return string.Equals(OutputSha256, EntrySha256, StringComparison.OrdinalIgnoreCase);
            }
        }

        public KarProjectA2DEntryOutputStatus Status { get; }

        public bool IsMissing => Status == KarProjectA2DEntryOutputStatus.Missing;

        public bool MatchesEntry => Status == KarProjectA2DEntryOutputStatus.MatchesEntry;

        public bool DiffersFromEntry => Status == KarProjectA2DEntryOutputStatus.DiffersFromEntry;

        private KarProjectA2DEntryOutputStatus GetStatus()
        {
            if (!HasOutput)
                return KarProjectA2DEntryOutputStatus.Missing;

            return IsSameContentAsEntry == true
                ? KarProjectA2DEntryOutputStatus.MatchesEntry
                : KarProjectA2DEntryOutputStatus.DiffersFromEntry;
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
