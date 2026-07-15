using System.Collections.Generic;

namespace KARToolkit.Core
{
    public static class KarArchiveCatalog
    {
        public static IReadOnlyList<KarFileKindDescriptor> FileKinds => KarFileKindRegistry.Default.Descriptors;

        public static IReadOnlyList<KarProjectFileHandler> FileHandlers => KarProjectFileHandlerRegistry.Default.Handlers;

        public static KarFileKindMatch Classify(string relativePath)
        {
            return KarProjectFileClassifier.Classify(relativePath);
        }

        public static KarFileKindDescriptor DescribeKind(KarFileKind kind)
        {
            return KarFileKindRegistry.Default.GetDescriptor(kind);
        }

        public static KarProjectFileHandler GetHandler(KarFileKind kind)
        {
            return KarProjectFileHandlerRegistry.Default.GetHandler(kind);
        }

        public static KarFileKind ClassifyKind(string relativePath)
        {
            return KarProjectFileClassifier.ClassifyKind(relativePath);
        }

        public static KarArchiveDefinition GetDefinition(string relativePath)
        {
            return GetDefinition(relativePath, ClassifyKind(relativePath));
        }

        public static bool IsHsdArchiveKind(KarFileKind kind)
        {
            return KarProjectFileClassifier.IsHsdArchiveKind(kind);
        }

        public static KarArchiveDefinition GetDefinition(string relativePath, KarFileKind kind)
        {
            return KarArchiveDefinitionProvider.Default.GetDefinition(relativePath, kind);
        }

        public static bool TryGetMapName(string relativePath, KarFileKind kind, out string mapName)
        {
            return KarProjectFileClassifier.TryGetMapName(relativePath, kind, out mapName);
        }
    }
}
