using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectToolkitRegistryCatalog
    {
        public static KarProjectToolkitRegistryCatalog Default { get; } = CreateDefault();

        internal KarProjectToolkitRegistryCatalog(
            KarProject project,
            IEnumerable<KarFileKindDescriptor> fileKinds,
            IEnumerable<KarProjectFileHandler> fileHandlers,
            IEnumerable<KarProjectResourceHandler> resourceHandlers,
            IEnumerable<KarProjectResourceActionDefinition> resourceActionDefinitions,
            IEnumerable<KarProjectOperationDomainRule> operationDomainRules,
            IEnumerable<KarProjectOperationPresetDefinition> operationPresetDefinitions)
        {
            Project = project;
            FileKinds = OrderFileKinds(fileKinds);
            FileHandlers = OrderFileHandlers(fileHandlers);
            ResourceHandlers = OrderResourceHandlers(resourceHandlers);
            ResourceActionDefinitions = OrderResourceActionDefinitions(resourceActionDefinitions);
            OperationDomainRules = OrderOperationDomainRules(operationDomainRules);
            OperationPresetDefinitions = OrderOperationPresetDefinitions(operationPresetDefinitions);
        }

        public KarProject Project { get; }

        public IReadOnlyList<KarFileKindDescriptor> FileKinds { get; }

        public IReadOnlyList<KarProjectFileHandler> FileHandlers { get; }

        public IReadOnlyList<KarProjectResourceHandler> ResourceHandlers { get; }

        public IReadOnlyList<KarProjectResourceActionDefinition> ResourceActionDefinitions { get; }

        public IReadOnlyList<KarProjectOperationDomainRule> OperationDomainRules { get; }

        public IReadOnlyList<KarProjectOperationPresetDefinition> OperationPresetDefinitions { get; }

        public bool HasProject => Project != null;

        public string ProjectName => Project == null ? null : Project.Name;

        public string SourceRoot => Project == null ? null : Project.SourceRoot;

        public string OutputRoot => Project == null ? null : Project.OutputRoot;

        public int RegistryCount => 6;

        public int FileKindCount => FileKinds.Count;

        public int FileHandlerCount => FileHandlers.Count;

        public int ResourceHandlerCount => ResourceHandlers.Count;

        public int ResourceActionDefinitionCount => ResourceActionDefinitions.Count;

        public int OperationDomainRuleCount => OperationDomainRules.Count;

        public int OperationPresetDefinitionCount => OperationPresetDefinitions.Count;

        public bool HasFileKinds => FileKindCount != 0;

        public bool HasFileHandlers => FileHandlerCount != 0;

        public bool HasResourceHandlers => ResourceHandlerCount != 0;

        public bool HasResourceActionDefinitions => ResourceActionDefinitionCount != 0;

        public bool HasOperationDomainRules => OperationDomainRuleCount != 0;

        public bool HasOperationPresetDefinitions => OperationPresetDefinitionCount != 0;

        public KarProjectToolkitRegistryCatalogContract CreateContract()
        {
            return KarProjectToolkitRegistryCatalogContract.Create(this);
        }

        public static KarProjectToolkitRegistryCatalog CreateDefault()
        {
            return new KarProjectToolkitRegistryCatalog(
                null,
                KarFileKindRegistry.Default.Descriptors,
                KarProjectFileHandlerRegistry.Default.Handlers,
                KarProjectResourceHandlerRegistry.Default.Handlers,
                KarProjectResourceActionRegistry.Default.Definitions,
                KarProjectOperationDomainRegistry.Default.Rules,
                KarProjectOperationPresetRegistry.Default.Definitions);
        }

        private static IReadOnlyList<KarFileKindDescriptor> OrderFileKinds(IEnumerable<KarFileKindDescriptor> fileKinds)
        {
            if (fileKinds == null)
                throw new ArgumentNullException(nameof(fileKinds));

            return fileKinds
                .OrderBy(descriptor => descriptor.Category, StringComparer.OrdinalIgnoreCase)
                .ThenBy(descriptor => descriptor.DisplayName, StringComparer.OrdinalIgnoreCase)
                .ThenBy(descriptor => descriptor.Id, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        private static IReadOnlyList<KarProjectFileHandler> OrderFileHandlers(IEnumerable<KarProjectFileHandler> fileHandlers)
        {
            if (fileHandlers == null)
                throw new ArgumentNullException(nameof(fileHandlers));

            return fileHandlers
                .OrderBy(handler => handler.Category, StringComparer.OrdinalIgnoreCase)
                .ThenBy(handler => handler.DisplayName, StringComparer.OrdinalIgnoreCase)
                .ThenBy(handler => handler.Id, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        private static IReadOnlyList<KarProjectResourceHandler> OrderResourceHandlers(IEnumerable<KarProjectResourceHandler> resourceHandlers)
        {
            if (resourceHandlers == null)
                throw new ArgumentNullException(nameof(resourceHandlers));

            return resourceHandlers
                .OrderBy(handler => handler.Kind)
                .ToList()
                .AsReadOnly();
        }

        private static IReadOnlyList<KarProjectResourceActionDefinition> OrderResourceActionDefinitions(IEnumerable<KarProjectResourceActionDefinition> definitions)
        {
            if (definitions == null)
                throw new ArgumentNullException(nameof(definitions));

            return definitions
                .OrderBy(definition => definition.Capability)
                .ThenBy(definition => definition.Id, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        private static IReadOnlyList<KarProjectOperationDomainRule> OrderOperationDomainRules(IEnumerable<KarProjectOperationDomainRule> rules)
        {
            if (rules == null)
                throw new ArgumentNullException(nameof(rules));

            return rules
                .OrderBy(rule => rule.Id, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        private static IReadOnlyList<KarProjectOperationPresetDefinition> OrderOperationPresetDefinitions(IEnumerable<KarProjectOperationPresetDefinition> definitions)
        {
            if (definitions == null)
                throw new ArgumentNullException(nameof(definitions));

            return definitions
                .OrderBy(definition => definition.DomainId, StringComparer.OrdinalIgnoreCase)
                .ThenBy(definition => definition.Id, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }
    }
}
