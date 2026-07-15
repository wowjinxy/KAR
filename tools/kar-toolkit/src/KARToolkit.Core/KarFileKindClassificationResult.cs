namespace KARToolkit.Core
{
    public sealed class KarFileKindClassificationResult
    {
        public KarFileKindClassificationResult(KarFileKind kind, string mapName = null)
        {
            Kind = kind;
            MapName = string.IsNullOrWhiteSpace(mapName) ? null : mapName;
        }

        public KarFileKind Kind { get; }

        public string MapName { get; }

        public bool HasMapName => MapName != null;
    }
}
