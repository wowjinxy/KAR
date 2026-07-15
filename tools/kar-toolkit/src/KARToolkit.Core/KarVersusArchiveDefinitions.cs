using static KARToolkit.Core.KarArchiveDefinitionFactory;
using static KARToolkit.Core.KarArchiveNameUtility;

namespace KARToolkit.Core
{
    internal static class KarVersusArchiveDefinitions
    {
        public static KarArchiveDefinition DefineVersus(string name, KarFileKind kind)
        {
            return Define(kind, name + " Data", "Versus", "Legendary machine versus data.", Root("vsData" + StripPrefix(name, "Vs"), "Legendary machine data", "KAR_vsLegendaryData", dataDefinitionId: "kar.vs.legendary"));
        }
    }
}
