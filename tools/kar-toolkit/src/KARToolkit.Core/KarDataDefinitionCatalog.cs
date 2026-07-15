using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public static class KarDataDefinitionCatalog
    {
        private static readonly IReadOnlyList<KarDataDefinition> Definitions =
            KarMapDataDefinitions.All
                .Concat(KarVehicleDataDefinitions.All)
                .Concat(KarVersusDataDefinitions.All)
                .ToList()
                .AsReadOnly();

        private static readonly IReadOnlyDictionary<string, KarDataDefinition> DefinitionsById =
            Definitions.ToDictionary(definition => definition.Id, StringComparer.OrdinalIgnoreCase);

        private static readonly IReadOnlyDictionary<string, KarDataDefinition> DefinitionsByAccessor =
            Definitions
                .Where(definition => !string.IsNullOrWhiteSpace(definition.AccessorTypeName))
                .GroupBy(definition => definition.AccessorTypeName, StringComparer.Ordinal)
                .ToDictionary(group => group.Key, group => group.First(), StringComparer.Ordinal);

        public static IReadOnlyList<KarDataDefinition> All => Definitions;

        public static KarDataDefinition Get(string id)
        {
            KarDataDefinition definition;
            if (!TryGet(id, out definition))
                throw new KeyNotFoundException("KAR data definition was not found: " + id);

            return definition;
        }

        public static bool TryGet(string id, out KarDataDefinition definition)
        {
            definition = null;
            if (string.IsNullOrWhiteSpace(id))
                return false;

            return DefinitionsById.TryGetValue(id, out definition);
        }

        public static bool TryGetByAccessorTypeName(string accessorTypeName, out KarDataDefinition definition)
        {
            definition = null;
            if (string.IsNullOrWhiteSpace(accessorTypeName))
                return false;

            return DefinitionsByAccessor.TryGetValue(accessorTypeName, out definition);
        }

        public static bool TryFind(string idOrAccessorTypeName, out KarDataDefinition definition)
        {
            return TryGet(idOrAccessorTypeName, out definition) ||
                TryGetByAccessorTypeName(idOrAccessorTypeName, out definition);
        }
    }
}
