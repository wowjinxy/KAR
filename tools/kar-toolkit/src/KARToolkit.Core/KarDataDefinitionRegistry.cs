using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarDataDefinitionRegistry
    {
        private readonly IReadOnlyList<KarDataDefinition> _definitions;
        private readonly IReadOnlyDictionary<string, KarDataDefinition> _definitionsById;
        private readonly IReadOnlyDictionary<string, KarDataDefinition> _definitionsByAccessor;

        public KarDataDefinitionRegistry(IEnumerable<KarDataDefinition> definitions)
        {
            if (definitions == null)
                throw new ArgumentNullException(nameof(definitions));

            _definitions = definitions.ToList().AsReadOnly();
            _definitionsById = _definitions.ToDictionary(definition => definition.Id, StringComparer.OrdinalIgnoreCase);
            _definitionsByAccessor = _definitions
                .Where(definition => !string.IsNullOrWhiteSpace(definition.AccessorTypeName))
                .GroupBy(definition => definition.AccessorTypeName, StringComparer.Ordinal)
                .ToDictionary(group => group.Key, group => group.First(), StringComparer.Ordinal);
        }

        public IReadOnlyList<KarDataDefinition> All => _definitions;

        public KarDataDefinition Get(string id)
        {
            KarDataDefinition definition;
            if (!TryGet(id, out definition))
                throw new KeyNotFoundException("KAR data definition was not found: " + id);

            return definition;
        }

        public bool TryGet(string id, out KarDataDefinition definition)
        {
            definition = null;
            if (string.IsNullOrWhiteSpace(id))
                return false;

            return _definitionsById.TryGetValue(id, out definition);
        }

        public bool TryGetByAccessorTypeName(string accessorTypeName, out KarDataDefinition definition)
        {
            definition = null;
            if (string.IsNullOrWhiteSpace(accessorTypeName))
                return false;

            return _definitionsByAccessor.TryGetValue(accessorTypeName, out definition);
        }

        public bool TryFind(string idOrAccessorTypeName, out KarDataDefinition definition)
        {
            return TryGet(idOrAccessorTypeName, out definition) ||
                TryGetByAccessorTypeName(idOrAccessorTypeName, out definition);
        }
    }
}
