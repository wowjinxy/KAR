using System;
using System.IO;
using System.Linq;
using System.Security.Cryptography;

namespace KARToolkit.Core
{
    public sealed class KarProjectOutputFileInfo
    {
        internal KarProjectOutputFileInfo(
            KarProjectFile projectFile,
            string relativePath,
            string outputPath,
            KarFileKind kind,
            KarArchiveDefinition archiveDefinition)
        {
            ProjectFile = projectFile;
            RelativePath = KarProjectWorkspace.NormalizeRelativePath(relativePath);
            OutputPath = outputPath ?? throw new ArgumentNullException(nameof(outputPath));
            Kind = kind;
            ArchiveDefinition = archiveDefinition ?? throw new ArgumentNullException(nameof(archiveDefinition));

            FileInfo outputInfo = new FileInfo(OutputPath);
            OutputLength = outputInfo.Exists ? outputInfo.Length : 0;
            OutputLastWriteTimeUtc = outputInfo.Exists ? outputInfo.LastWriteTimeUtc : DateTime.MinValue;
            OutputSha256 = outputInfo.Exists ? ComputeSha256(OutputPath) : null;

            if (ProjectFile != null && File.Exists(ProjectFile.SourcePath))
            {
                FileInfo sourceInfo = new FileInfo(ProjectFile.SourcePath);
                SourceLength = sourceInfo.Length;
                SourceLastWriteTimeUtc = sourceInfo.LastWriteTimeUtc;
                SourceSha256 = ComputeSha256(ProjectFile.SourcePath);
            }

            Status = GetStatus();
        }

        public KarProjectFile ProjectFile { get; }

        public bool IsProjectFile => ProjectFile != null;

        public bool IsOrphan => ProjectFile == null;

        public string RelativePath { get; }

        public string SourcePath => ProjectFile == null ? null : ProjectFile.SourcePath;

        public string OutputPath { get; }

        public KarFileKind Kind { get; }

        public KarArchiveDefinition ArchiveDefinition { get; }

        public string DisplayName => ArchiveDefinition.DisplayName;

        public string Category => ArchiveDefinition.Category;

        public long OutputLength { get; }

        public DateTime OutputLastWriteTimeUtc { get; }

        public string OutputSha256 { get; }

        public long? SourceLength { get; }

        public DateTime? SourceLastWriteTimeUtc { get; }

        public string SourceSha256 { get; }

        public bool HasSourceFile => SourceLength.HasValue;

        public bool? IsSameLengthAsSource => SourceLength.HasValue ? SourceLength.Value == OutputLength : (bool?)null;

        public bool? IsSameContentAsSource
        {
            get
            {
                if (SourceSha256 == null || OutputSha256 == null)
                    return null;

                return string.Equals(SourceSha256, OutputSha256, StringComparison.OrdinalIgnoreCase);
            }
        }

        public KarProjectOutputFileStatus Status { get; }

        public bool IsModifiedProjectFile => Status == KarProjectOutputFileStatus.DiffersFromSource;

        public bool IsUnchangedProjectFile => Status == KarProjectOutputFileStatus.MatchesSource;

        private KarProjectOutputFileStatus GetStatus()
        {
            if (ProjectFile == null)
                return KarProjectOutputFileStatus.Orphan;

            if (!SourceLength.HasValue || SourceSha256 == null)
                return KarProjectOutputFileStatus.SourceMissing;

            return IsSameContentAsSource == true
                ? KarProjectOutputFileStatus.MatchesSource
                : KarProjectOutputFileStatus.DiffersFromSource;
        }

        private static string ComputeSha256(string path)
        {
            using (SHA256 sha256 = SHA256.Create())
            using (FileStream stream = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.ReadWrite))
            {
                return string.Concat(sha256.ComputeHash(stream).Select(value => value.ToString("x2")));
            }
        }
    }
}
