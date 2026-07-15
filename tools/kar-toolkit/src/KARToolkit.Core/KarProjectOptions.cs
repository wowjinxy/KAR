namespace KARToolkit.Core
{
    public sealed class KarProjectOptions
    {
        public string SourceRoot { get; set; }

        public string OutputRoot { get; set; }

        public KarProjectIndexer Indexer { get; set; }

        public KarProjectFileCatalog FileCatalog { get; set; }

        public KarFileKindRegistry FileKindRegistry { get; set; }

        public KarProjectFileHandlerRegistry FileHandlerRegistry { get; set; }

        public KarProjectResourceActionRegistry ResourceActionRegistry { get; set; }

        public KarProjectResourceHandlerRegistry ResourceHandlerRegistry { get; set; }

        public KarProjectOperationDomainRegistry OperationDomainRegistry { get; set; }

        public KarProjectDomainContextProviderRegistry DomainContextProviderRegistry { get; set; }

        public KarProjectOperationPresetRegistry OperationPresetRegistry { get; set; }

        public KarArchiveDefinitionProvider ArchiveDefinitions { get; set; }

        public KarArchiveInspector ArchiveInspector { get; set; }

        public KarDataDefinitionRegistry DataDefinitions { get; set; }

        public KarDataInspectionOptions DataInspection { get; set; }

        internal KarProjectIndexer ResolveIndexer()
        {
            if (Indexer != null)
                return Indexer;

            if (FileCatalog != null)
                return new KarProjectIndexer(FileCatalog);

            if (FileHandlerRegistry != null && ArchiveDefinitions != null)
                return new KarProjectIndexer(new KarProjectFileCatalog(ArchiveDefinitions, FileHandlerRegistry));

            if (FileHandlerRegistry != null)
                return new KarProjectIndexer(new KarProjectFileCatalog(FileHandlerRegistry));

            if (FileKindRegistry != null && ArchiveDefinitions != null)
                return new KarProjectIndexer(new KarProjectFileCatalog(ArchiveDefinitions, FileKindRegistry));

            if (FileKindRegistry != null)
                return new KarProjectIndexer(new KarProjectFileCatalog(FileKindRegistry));

            if (ArchiveDefinitions != null)
                return new KarProjectIndexer(new KarProjectFileCatalog(ArchiveDefinitions));

            return KarProjectIndexer.Default;
        }

        internal KarArchiveInspector ResolveArchiveInspector()
        {
            if (ArchiveInspector != null)
                return ArchiveInspector;

            if (DataDefinitions != null)
                return new KarArchiveInspector(DataDefinitions, DataInspection);

            if (DataInspection != null)
                return new KarArchiveInspector(KarDataDefinitionCatalog.BuiltIn, DataInspection);

            return KarArchiveInspector.Default;
        }

        internal KarProjectResourceHandlerRegistry ResolveResourceHandlerRegistry()
        {
            if (ResourceHandlerRegistry != null)
                return ResourceHandlerRegistry;

            if (ResourceActionRegistry != null)
                return KarProjectResourceHandlerRegistry.CreateDefault(ResourceActionRegistry);

            return KarProjectResourceHandlerRegistry.Default;
        }

        internal KarProjectOperationDomainRegistry ResolveOperationDomainRegistry()
        {
            return OperationDomainRegistry ?? KarProjectOperationDomainRegistry.Default;
        }

        internal KarProjectDomainContextProviderRegistry ResolveDomainContextProviderRegistry()
        {
            return DomainContextProviderRegistry ?? KarProjectDomainContextProviderRegistry.Default;
        }

        internal KarProjectOperationPresetRegistry ResolveOperationPresetRegistry()
        {
            return OperationPresetRegistry ?? KarProjectOperationPresetRegistry.Default;
        }
    }
}
