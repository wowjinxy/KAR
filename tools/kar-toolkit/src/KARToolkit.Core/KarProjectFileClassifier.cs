namespace KARToolkit.Core
{
    public static class KarProjectFileClassifier
    {
        public static KarFileKindMatch Classify(string relativePath)
        {
            return KarFileKindRegistry.Default.Classify(relativePath);
        }

        public static KarFileKind ClassifyKind(string relativePath)
        {
            return KarFileKindRegistry.Default.ClassifyKind(relativePath);
        }

        public static bool IsHsdArchiveKind(KarFileKind kind)
        {
            return KarFileKindRegistry.Default.IsHsdArchiveKind(kind);
        }

        public static bool TryGetMapName(string relativePath, KarFileKind kind, out string mapName)
        {
            return KarFileKindRegistry.Default.TryGetMapName(relativePath, kind, out mapName);
        }
    }
}
