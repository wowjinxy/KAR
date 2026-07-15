namespace KARToolkit.Core
{
    public sealed class KarProjectOptions
    {
        public string SourceRoot { get; set; }

        public string OutputRoot { get; set; }

        public KarProjectIndexer Indexer { get; set; }

        public KarProjectFileCatalog FileCatalog { get; set; }

        public KarArchiveInspector ArchiveInspector { get; set; }

        public KarDataDefinitionRegistry DataDefinitions { get; set; }

        internal KarProjectIndexer ResolveIndexer()
        {
            if (Indexer != null)
                return Indexer;

            if (FileCatalog != null)
                return new KarProjectIndexer(FileCatalog);

            return KarProjectIndexer.Default;
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
