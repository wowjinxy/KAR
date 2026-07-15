using System;
using System.IO;

namespace KARToolkit.Core
{
    public sealed class KarProjectFile
    {
        internal KarProjectFile(
            string relativePath,
            string sourcePath,
            string outputPath,
            KarFileKind kind,
            KarArchiveDefinition archiveDefinition)
        {
            RelativePath = relativePath;
            SourcePath = sourcePath;
            OutputPath = outputPath;
            Kind = kind;
            ArchiveDefinition = archiveDefinition ?? throw new ArgumentNullException(nameof(archiveDefinition));
        }

        public string RelativePath { get; }

        public string SourcePath { get; }

        public string OutputPath { get; }

        public KarFileKind Kind { get; }

        public KarArchiveDefinition ArchiveDefinition { get; }

        public string DisplayName => ArchiveDefinition.DisplayName;

        public string Category => ArchiveDefinition.Category;

        public bool HasOutputCopy => File.Exists(OutputPath);

        public string ReadPath => HasOutputCopy ? OutputPath : SourcePath;
    }
}
