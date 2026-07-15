using System;
using System.Collections.Generic;

namespace KARToolkit.Core
{
    public class KarProjectFileCatalog
    {
        public static KarProjectFileCatalog Default { get; } = new KarProjectFileCatalog();

        private readonly KarFileKindRegistry _fileKinds;
        private readonly KarArchiveDefinitionProvider _archiveDefinitions;

        public KarProjectFileCatalog()
            : this(KarArchiveDefinitionProvider.Default, KarFileKindRegistry.Default)
        {
        }

        public KarProjectFileCatalog(KarArchiveDefinitionProvider archiveDefinitions)
            : this(archiveDefinitions, KarFileKindRegistry.Default)
        {
        }

        public KarProjectFileCatalog(KarFileKindRegistry fileKinds)
            : this(KarArchiveDefinitionProvider.Default, fileKinds)
        {
        }

        public KarProjectFileCatalog(KarArchiveDefinitionProvider archiveDefinitions, KarFileKindRegistry fileKinds)
        {
            _archiveDefinitions = archiveDefinitions ?? throw new ArgumentNullException(nameof(archiveDefinitions));
            _fileKinds = fileKinds ?? throw new ArgumentNullException(nameof(fileKinds));
        }

        public KarFileKindRegistry FileKindRegistry => _fileKinds;

        public IReadOnlyList<KarFileKindDescriptor> FileKindDescriptors => _fileKinds.Descriptors;

        public KarArchiveDefinitionProvider ArchiveDefinitions => _archiveDefinitions;

        public virtual KarFileKindMatch Classify(string relativePath)
        {
            return _fileKinds.Classify(relativePath);
        }

        public virtual KarFileKind ClassifyKind(string relativePath)
        {
            return Classify(relativePath).Kind;
        }

        public virtual KarFileKindDescriptor DescribeKind(KarFileKind kind)
        {
            return _fileKinds.GetDescriptor(kind);
        }

        public virtual KarArchiveDefinition GetArchiveDefinition(string relativePath)
        {
            return GetArchiveDefinition(Classify(relativePath));
        }

        public virtual KarArchiveDefinition GetArchiveDefinition(KarFileKindMatch match)
        {
            if (match == null)
                throw new ArgumentNullException(nameof(match));

            return _archiveDefinitions.GetDefinition(match.RelativePath, match.Kind, match.MapName);
        }

        public virtual KarArchiveDefinition GetArchiveDefinition(string relativePath, KarFileKind kind)
        {
            string mapName;
            if (TryGetMapName(relativePath, kind, out mapName))
                return _archiveDefinitions.GetDefinition(relativePath, kind, mapName);

            return _archiveDefinitions.GetDefinition(relativePath, kind, null);
        }

        public virtual bool IsHsdArchiveKind(KarFileKind kind)
        {
            return _fileKinds.IsHsdArchiveKind(kind);
        }

        public virtual bool IsA2DPackageKind(KarFileKind kind)
        {
            return _fileKinds.IsA2DPackageKind(kind);
        }

        public virtual bool IsScriptTableKind(KarFileKind kind)
        {
            return _fileKinds.IsScriptTableKind(kind);
        }

        public virtual bool TryGetMapName(string relativePath, KarFileKind kind, out string mapName)
        {
            return _fileKinds.TryGetMapName(relativePath, kind, out mapName);
        }
    }
}
