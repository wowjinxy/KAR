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
            KarProjectFileHandler handler,
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
            Handler = handler ?? throw new ArgumentNullException(nameof(handler));
            if (Handler.Kind != Kind)
                throw new ArgumentException("File handler does not match file kind.", nameof(handler));
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

        public bool HasOutputCopy => File.Exists(OutputPath);

        public string ReadPath => HasOutputCopy ? OutputPath : SourcePath;
    }
}
