using System.Collections.Generic;

namespace KARToolkit.Core
{
    public static class KarDataDefinitionCatalog
    {
        private static readonly KarDataDefinitionRegistry Registry =
            new KarDataDefinitionRegistry(KarBuiltInDataDefinitions.All);

        public static IReadOnlyList<KarDataDefinition> All => Registry.All;

        public static KarDataDefinition Get(string id)
        {
            return Registry.Get(id);
        }

        public static bool TryGet(string id, out KarDataDefinition definition)
        {
            return Registry.TryGet(id, out definition);
        }

        public static bool TryGetByAccessorTypeName(string accessorTypeName, out KarDataDefinition definition)
        {
            return Registry.TryGetByAccessorTypeName(accessorTypeName, out definition);
        }

        public static bool TryFind(string idOrAccessorTypeName, out KarDataDefinition definition)
        {
            return Registry.TryFind(idOrAccessorTypeName, out definition);
        }
    }
}
