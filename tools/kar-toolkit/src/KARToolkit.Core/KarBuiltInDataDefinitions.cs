using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    internal static class KarBuiltInDataDefinitions
    {
        public static IReadOnlyList<KarDataDefinition> All { get; } =
            KarMapDataDefinitions.All
                .Concat(KarVehicleDataDefinitions.All)
                .Concat(KarVersusDataDefinitions.All)
                .ToList()
                .AsReadOnly();
    }
}
