using System;
using System.IO;

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

            if (ProjectFile != null && File.Exists(ProjectFile.SourcePath))
            {
                FileInfo sourceInfo = new FileInfo(ProjectFile.SourcePath);
                SourceLength = sourceInfo.Length;
                SourceLastWriteTimeUtc = sourceInfo.LastWriteTimeUtc;
            }
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

        public long? SourceLength { get; }

        public DateTime? SourceLastWriteTimeUtc { get; }

        public bool HasSourceFile => SourceLength.HasValue;

        public bool? IsSameLengthAsSource => SourceLength.HasValue ? SourceLength.Value == OutputLength : (bool?)null;
    }
}
