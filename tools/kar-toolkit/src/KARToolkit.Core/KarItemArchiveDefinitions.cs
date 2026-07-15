using System;
using static KARToolkit.Core.KarArchiveDefinitionFactory;

namespace KARToolkit.Core
{
    internal static class KarItemArchiveDefinitions
    {
        public static KarArchiveDefinition DefineItem(string name, KarFileKind kind)
        {
            if (name.Equals("ItCommon", StringComparison.OrdinalIgnoreCase))
                return Define(kind, "Item Common Data", "Items", "Shared item data.", Root("itCommonDataAll", "Shared item data", null));
            if (name.Equals("Item", StringComparison.OrdinalIgnoreCase))
                return Define(kind, "Item Data", "Items", "Item data table.", Root("itData", "Item data table", "HSDArrayAccessor<KAR_Item>"));

            return Define(kind, name + " Item Data", "Items", "Item data archive.");
        }
    }
}
