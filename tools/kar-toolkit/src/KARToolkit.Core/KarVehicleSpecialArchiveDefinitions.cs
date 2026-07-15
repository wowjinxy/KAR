using static KARToolkit.Core.KarArchiveDefinitionFactory;
using static KARToolkit.Core.KarArchiveNameUtility;

namespace KARToolkit.Core
{
    internal static class KarVehicleSpecialArchiveDefinitions
    {
        public static KarArchiveDefinition DefineVehicleSpecial(string name, KarFileKind kind)
        {
            return Define(kind, name + " Data", "Vehicle Special", "Legendary machine vehicle special data.", Root("vsData" + StripPrefix(name, "Vs"), "Legendary machine data", "KAR_vsLegendaryData", dataDefinitionId: "kar.vs.legendary"));
        }
    }
}
