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
            KarFileKindDescriptor kindDescriptor,
            string mapName,
            KarArchiveDefinition archiveDefinition)
        {
            RelativePath = relativePath;
            SourcePath = sourcePath;
            OutputPath = outputPath;
            Kind = kind;
            KindDescriptor = kindDescriptor ?? throw new ArgumentNullException(nameof(kindDescriptor));
            if (KindDescriptor.Kind != Kind)
                throw new ArgumentException("File kind descriptor does not match file kind.", nameof(kindDescriptor));
            MapName = string.IsNullOrWhiteSpace(mapName) ? null : mapName;
            ArchiveDefinition = archiveDefinition ?? throw new ArgumentNullException(nameof(archiveDefinition));
        }

        public string RelativePath { get; }

        public KarResourceReference ResourceReference => KarResourceReference.File(RelativePath);

        public string ResourceAddress => ResourceReference.Address;

        public string SourcePath { get; }

        public string OutputPath { get; }

        public KarFileKind Kind { get; }

        public KarFileKindDescriptor KindDescriptor { get; }

        public string KindId => KindDescriptor.Id;

        public bool IsHsdArchive => KindDescriptor.IsHsdArchive;

        public bool IsA2DPackage => KindDescriptor.IsA2DPackage;

        public bool IsScriptTable => KindDescriptor.IsScriptTable;

        public bool IsMapBundlePart => KindDescriptor.IsMapBundlePart;

        public string MapBundleRole => KindDescriptor.MapBundleRole;

        public string MapName { get; }

        public bool HasMapName => MapName != null;

        public KarArchiveDefinition ArchiveDefinition { get; }

        public string DisplayName => ArchiveDefinition.DisplayName;

        public string Category => ArchiveDefinition.Category;

        public bool HasOutputCopy => File.Exists(OutputPath);

        public string ReadPath => HasOutputCopy ? OutputPath : SourcePath;
    }
}
