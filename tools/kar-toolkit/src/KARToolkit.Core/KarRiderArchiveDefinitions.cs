using System;
using static KARToolkit.Core.KarArchiveDefinitionFactory;
using static KARToolkit.Core.KarArchiveNameUtility;

namespace KARToolkit.Core
{
    internal static class KarRiderArchiveDefinitions
    {
        public static KarArchiveDefinition DefineRider(string name, KarFileKind kind)
        {
            if (name.Equals("RdCommon", StringComparison.OrdinalIgnoreCase))
                return Define(kind, "Rider Common Data", "Riders", "Shared rider data.", Root("rdDataCommon", "Shared rider data", "KAR_RdDataCommon"));
            if (name.StartsWith("Rd", StringComparison.OrdinalIgnoreCase) &&
                name.IndexOf("Motion", StringComparison.OrdinalIgnoreCase) >= 0)
            {
                string motionName = ToRiderMotionName(StripPrefix(name, "Rd"));
                return Define(kind, "Rider Motion: " + motionName, "Riders", "Rider motion table.", Root("rdMotion" + motionName, "Rider motion table", "HSDArrayAccessor<KAR_RdMotion>"));
            }

            return Define(kind, "Rider Data: " + StripPrefix(name, "Rd"), "Riders", "Rider data and rider animation resources.", Root("rdData" + StripPrefix(name, "Rd"), "Rider data", "KAR_RdData"), KarRootDefinition.Suffix("_cmpatree", "Rider animation tree", "HSD_FigaTree", false));
        }
    }
}
