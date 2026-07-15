using System.Collections.Generic;

namespace KARToolkit.Core
{
    public static class KarDataDefinitionCatalog
    {
        public static KarDataDefinitionRegistry BuiltIn { get; } =
            new KarDataDefinitionRegistry(KarBuiltInDataDefinitions.All);

        public static IReadOnlyList<KarDataDefinition> All => BuiltIn.All;

        public static KarDataDefinition Get(string id)
        {
            return BuiltIn.Get(id);
        }

        public static bool TryGet(string id, out KarDataDefinition definition)
        {
            return BuiltIn.TryGet(id, out definition);
        }

        public static bool TryGetByAccessorTypeName(string accessorTypeName, out KarDataDefinition definition)
        {
            return BuiltIn.TryGetByAccessorTypeName(accessorTypeName, out definition);
        }

        public static bool TryFind(string idOrAccessorTypeName, out KarDataDefinition definition)
        {
            return BuiltIn.TryFind(idOrAccessorTypeName, out definition);
        }
    }
}
