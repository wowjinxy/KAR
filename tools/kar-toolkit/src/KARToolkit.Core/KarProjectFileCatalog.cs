using System;

namespace KARToolkit.Core
{
    public class KarProjectFileCatalog
    {
        public static KarProjectFileCatalog Default { get; } = new KarProjectFileCatalog();

        private readonly KarArchiveDefinitionProvider _archiveDefinitions;

        public KarProjectFileCatalog()
            : this(KarArchiveDefinitionProvider.Default)
        {
        }

        public KarProjectFileCatalog(KarArchiveDefinitionProvider archiveDefinitions)
        {
            _archiveDefinitions = archiveDefinitions ?? throw new ArgumentNullException(nameof(archiveDefinitions));
        }

        public KarArchiveDefinitionProvider ArchiveDefinitions => _archiveDefinitions;

        public virtual KarFileKind ClassifyKind(string relativePath)
        {
            return KarProjectFileClassifier.ClassifyKind(relativePath);
        }

        public virtual KarArchiveDefinition GetArchiveDefinition(string relativePath)
        {
            return GetArchiveDefinition(relativePath, ClassifyKind(relativePath));
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
            return KarProjectFileClassifier.IsHsdArchiveKind(kind);
        }

        public virtual bool TryGetMapName(string relativePath, KarFileKind kind, out string mapName)
        {
            return KarProjectFileClassifier.TryGetMapName(relativePath, kind, out mapName);
        }
    }
}
