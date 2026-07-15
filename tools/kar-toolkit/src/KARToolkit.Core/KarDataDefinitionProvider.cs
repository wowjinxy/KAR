using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarDataDefinitionProvider
    {
        private readonly Func<IEnumerable<KarDataDefinition>> _createDefinitions;

        public KarDataDefinitionProvider(
            string id,
            string displayName,
            string description,
            Func<IEnumerable<KarDataDefinition>> createDefinitions)
        {
            if (string.IsNullOrWhiteSpace(id))
                throw new ArgumentException("Data definition provider id cannot be empty.", nameof(id));
            if (string.IsNullOrWhiteSpace(displayName))
                throw new ArgumentException("Data definition provider display name cannot be empty.", nameof(displayName));

            Id = id;
            DisplayName = displayName;
            Description = description ?? "";
            _createDefinitions = createDefinitions ?? throw new ArgumentNullException(nameof(createDefinitions));
        }

        public string Id { get; }

        public string DisplayName { get; }

        public string Description { get; }

        public int DefinitionCount => CreateDefinitions().Count;

        public IReadOnlyList<KarDataDefinition> CreateDefinitions()
        {
            IEnumerable<KarDataDefinition> definitions = _createDefinitions();
            if (definitions == null)
                throw new InvalidOperationException("Data definition provider returned null definitions: " + Id);

            List<KarDataDefinition> definitionList = definitions.ToList();
            if (definitionList.Any(definition => definition == null))
                throw new InvalidOperationException("Data definition provider returned a null definition: " + Id);

            return definitionList.AsReadOnly();
        }

        public KarDataDefinitionProviderContract CreateContract()
        {
            return KarDataDefinitionProviderContract.Create(this);
        }
    }
}
