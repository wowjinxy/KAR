namespace KARToolkit.Core
{
    public class KarProjectFileCatalog
    {
        public static KarProjectFileCatalog Default { get; } = new KarProjectFileCatalog();

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
            return KarArchiveCatalog.GetDefinition(relativePath, kind);
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
