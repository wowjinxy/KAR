using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectSchemaService
    {
        private readonly KarProject _project;

        internal KarProjectSchemaService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public KarDataDefinitionRegistry DataDefinitions => _project.ArchiveInspector.DataDefinitions;

        public KarArchiveDefinitionProvider ArchiveDefinitions => _project.FileCatalog.ArchiveDefinitions;

        public IReadOnlyList<KarFileKindDescriptor> FileKinds => _project.FileCatalog.FileKindDescriptors;

        public IReadOnlyList<KarProjectFileHandler> FileHandlers => _project.FileCatalog.FileHandlers;

        public IReadOnlyList<KarProjectResourceHandler> ResourceHandlers => _project.ResourceHandlerRegistry.Handlers;

        public IReadOnlyList<KarProjectResourceActionDefinition> ResourceActionDefinitions => _project.ResourceActionRegistry.Definitions;

        public IReadOnlyList<KarProjectOperationDomainRule> OperationDomainRules => _project.OperationDomainRegistry.Rules;

        public IReadOnlyList<KarProjectOperationPresetDefinition> OperationPresetDefinitions => _project.OperationPresetRegistry.Definitions;

        public KarProjectToolkitRegistryCatalog CreateToolkitRegistryCatalog()
        {
            return new KarProjectToolkitRegistryCatalog(
                _project,
                FileKinds,
                FileHandlers,
                ResourceHandlers,
                ResourceActionDefinitions,
                OperationDomainRules,
                OperationPresetDefinitions);
        }

        public IReadOnlyList<KarDataDefinition> QueryDataDefinitions(KarDataDefinitionQueryOptions options = null)
        {
            IEnumerable<KarDataDefinition> definitions = DataDefinitions.All;
            if (options != null)
                definitions = definitions.Where(options.Matches);

            return definitions
                .OrderBy(definition => definition.Category, StringComparer.OrdinalIgnoreCase)
                .ThenBy(definition => definition.DisplayName, StringComparer.OrdinalIgnoreCase)
                .ThenBy(definition => definition.Id, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public KarDataDefinition GetDataDefinition(string idOrAccessorTypeName)
        {
            KarDataDefinition definition;
            if (!TryFindDataDefinition(idOrAccessorTypeName, out definition))
                throw new KeyNotFoundException("KAR data definition was not found: " + idOrAccessorTypeName);

            return definition;
        }

        public bool TryGetDataDefinition(string id, out KarDataDefinition definition)
        {
            return DataDefinitions.TryGet(id, out definition);
        }

        public bool TryFindDataDefinition(string idOrAccessorTypeName, out KarDataDefinition definition)
        {
            return DataDefinitions.TryFind(idOrAccessorTypeName, out definition);
        }

        public KarDataDefinitionValidationReport ValidateDataDefinitions()
        {
            return KarDataDefinitionValidator.Validate(DataDefinitions);
        }

        public IReadOnlyList<KarProjectArchiveSchemaInfo> QueryArchiveSchemas(KarProjectFileQueryOptions options = null)
        {
            return _project.FileService.Query(options)
                .Select(file => new KarProjectArchiveSchemaInfo(file))
                .ToList()
                .AsReadOnly();
        }

        public KarProjectArchiveSchemaInfo GetArchiveSchema(string relativePath)
        {
            return new KarProjectArchiveSchemaInfo(_project.FileService.Get(relativePath));
        }

        public IReadOnlyList<KarProjectDataDefinitionUsage> QueryDataDefinitionUsage(KarProjectRootQueryOptions options = null)
        {
            return _project.DataService.QueryDataDefinitionUsage(options);
        }

        public KarProjectDataCoverageReport CreateDataCoverageReport(KarProjectDataCoverageOptions options = null)
        {
            return new KarProjectDataCoverageReport(_project, options);
        }
    }
}
