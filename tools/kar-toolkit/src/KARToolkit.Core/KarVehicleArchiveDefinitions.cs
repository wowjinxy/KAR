using System;
using static KARToolkit.Core.KarArchiveDefinitionFactory;
using static KARToolkit.Core.KarArchiveNameUtility;

namespace KARToolkit.Core
{
    internal static class KarVehicleArchiveDefinitions
    {
        public static KarArchiveDefinition DefineVehicle(string name, KarFileKind kind)
        {
            if (name.Equals("VcCommon", StringComparison.OrdinalIgnoreCase))
                return Define(kind, "Vehicle Common Data", "Vehicles", "Shared vehicle data.", Root("vcDataCommon", "Shared vehicle data", "KAR_vcDataCommon", dataDefinitionId: "kar.vc.common"));
            if (name.Equals("VcStar", StringComparison.OrdinalIgnoreCase))
                return Define(kind, "Star Kind Table", "Vehicles", "Vehicle kind table for stars.", Root("vcDataKindStar", "Star kind table", "KAR_vcDataKindStar"), KarRootDefinition.Suffix("_cmpatree", "Vehicle animation tree", "HSD_FigaTree", false));
            if (name.Equals("VcWheel", StringComparison.OrdinalIgnoreCase))
                return Define(kind, "Wheel Kind Table", "Vehicles", "Vehicle kind table for wheels.", Root("vcDataKindWheel", "Wheel kind table", "KAR_vcDataKindWheel"));
            if (name.StartsWith("VcStar", StringComparison.OrdinalIgnoreCase))
                return Define(kind, "Star Data: " + StripPrefix(name, "VcStar"), "Vehicles", "Star vehicle data.", Root("vcDataStar" + StripPrefix(name, "VcStar"), "Star vehicle data", "KAR_vcDataStar"));
            if (name.StartsWith("VcWheel", StringComparison.OrdinalIgnoreCase))
                return Define(kind, "Wheel Data: " + StripPrefix(name, "VcWheel"), "Vehicles", "Wheel vehicle data.", Root("vcDataWheel" + StripPrefix(name, "VcWheel"), "Wheel vehicle data", "KAR_vcDataWheel"), KarRootDefinition.Suffix("_cmpatree", "Vehicle animation tree", "HSD_FigaTree", false));
            if (name.StartsWith("VcWing", StringComparison.OrdinalIgnoreCase))
                return Define(kind, "Wing Data: " + StripPrefix(name, "VcWing"), "Vehicles", "Wing vehicle data.", Root("vcDataWing" + StripPrefix(name, "VcWing"), "Wing vehicle data", null), KarRootDefinition.Suffix("_cmpatree", "Vehicle animation tree", "HSD_FigaTree", false));

            return Define(kind, name + " Vehicle Data", "Vehicles", "Vehicle data archive.");
        }
    }
}
