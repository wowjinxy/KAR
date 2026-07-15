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
            KarFileKindDescriptor kindDescriptor,
            KarProjectFileHandler handler,
            string mapName,
            KarArchiveDefinition archiveDefinition)
        {
            ProjectFile = projectFile;
            RelativePath = KarProjectWorkspace.NormalizeRelativePath(relativePath);
            OutputPath = outputPath ?? throw new ArgumentNullException(nameof(outputPath));
            Kind = kind;
            KindDescriptor = kindDescriptor ?? throw new ArgumentNullException(nameof(kindDescriptor));
            if (KindDescriptor.Kind != Kind)
                throw new ArgumentException("File kind descriptor does not match file kind.", nameof(kindDescriptor));
            Handler = handler ?? throw new ArgumentNullException(nameof(handler));
            if (Handler.Kind != Kind)
                throw new ArgumentException("File handler does not match file kind.", nameof(handler));
            MapName = string.IsNullOrWhiteSpace(mapName) ? null : mapName;
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

        public KarResourceReference ResourceReference => KarResourceReference.File(RelativePath);

        public string ResourceAddress => ResourceReference.Address;

        public string SourcePath => ProjectFile == null ? null : ProjectFile.SourcePath;

        public string OutputPath { get; }

        public KarFileKind Kind { get; }

        public KarFileKindDescriptor KindDescriptor { get; }

        public KarProjectFileHandler Handler { get; }

        public string KindId => KindDescriptor.Id;

        public KarProjectFileCapability Capabilities => Handler.Capabilities;

        public bool IsHsdArchive => KindDescriptor.IsHsdArchive;

        public bool IsA2DPackage => KindDescriptor.IsA2DPackage;

        public bool IsScriptTable => KindDescriptor.IsScriptTable;

        public bool IsMapBundlePart => KindDescriptor.IsMapBundlePart;

        public string MapBundleRole => KindDescriptor.MapBundleRole;

        public bool CanReadBytes => Handler.CanReadBytes;

        public bool CanCopyToOutput => Handler.CanCopyToOutput;

        public bool CanReplaceFileInOutput => Handler.CanReplaceFileInOutput;

        public bool CanInspectHsdArchive => Handler.CanInspectHsdArchive;

        public bool CanQueryHsdRoots => Handler.CanQueryHsdRoots;

        public bool CanEditHsdScalarFields => Handler.CanEditHsdScalarFields;

        public bool CanOpenA2DPackage => Handler.CanOpenA2DPackage;

        public bool CanListA2DEntries => Handler.CanListA2DEntries;

        public bool CanExtractA2DEntries => Handler.CanExtractA2DEntries;

        public bool CanReplaceA2DEntries => Handler.CanReplaceA2DEntries;

        public bool CanListScriptTables => Handler.CanListScriptTables;

        public bool CanGroupWithMap => Handler.CanGroupWithMap;

        public bool CanInspectMapArchive => Handler.CanInspectMapArchive;

        public string MapName { get; }

        public bool HasMapName => MapName != null;

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
