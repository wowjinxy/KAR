namespace KARToolkit.Core
{
    public sealed class KarProjectOptions
    {
        public string SourceRoot { get; set; }

        public string OutputRoot { get; set; }

        public KarProjectIndexer Indexer { get; set; }

        public KarArchiveInspector ArchiveInspector { get; set; }

        public KarDataDefinitionRegistry DataDefinitions { get; set; }

        internal KarProjectIndexer ResolveIndexer()
        {
            return Indexer ?? KarProjectIndexer.Default;
        }

        internal KarArchiveInspector ResolveArchiveInspector()
        {
            if (ArchiveInspector != null)
                return ArchiveInspector;

            if (DataDefinitions != null)
                return new KarArchiveInspector(DataDefinitions);

            return KarArchiveInspector.Default;
        }
    }
}
