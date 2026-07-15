using System;
using System.IO;

namespace KARToolkit.Core
{
    public static class KarArchiveCatalog
    {
        public static KarFileKind ClassifyKind(string relativePath)
        {
            return KarProjectFileClassifier.ClassifyKind(relativePath);
        }

        public static KarArchiveDefinition GetDefinition(string relativePath)
        {
            return GetDefinition(relativePath, ClassifyKind(relativePath));
        }

        public static bool IsHsdArchiveKind(KarFileKind kind)
        {
            return KarProjectFileClassifier.IsHsdArchiveKind(kind);
        }

        public static KarArchiveDefinition GetDefinition(string relativePath, KarFileKind kind)
        {
            string fileName = Path.GetFileName(relativePath);
            string name = Path.GetFileNameWithoutExtension(fileName);

            switch (kind)
            {
                case KarFileKind.StageTable:
                    return KarMapArchiveDefinitions.DefineStageTable(kind);
                case KarFileKind.MapCommon:
                    return KarMapArchiveDefinitions.DefineMapCommon(kind);
                case KarFileKind.MapData:
                    return KarMapArchiveDefinitions.DefineMapData(relativePath, kind);
                case KarFileKind.MapModel:
                    return KarMapArchiveDefinitions.DefineMapModel(relativePath, kind);
                case KarFileKind.MapEvent:
                    return KarMapArchiveDefinitions.DefineMapEvent(relativePath, kind);
                case KarFileKind.A2dPackage:
                    return Define(kind, "A2D Package", "A2D", "Air Ride 2D package containing one or more embedded resources.");
                case KarFileKind.VehicleData:
                    return DefineVehicle(name, kind);
                case KarFileKind.RiderData:
                    return DefineRider(name, kind);
                case KarFileKind.VersusData:
                    return Define(kind, name + " Data", "Versus", "Legendary machine versus data.", Root("vsData" + StripPrefix(name, "Vs"), "Legendary machine data", "KAR_vsLegendaryData", dataDefinitionId: "kar.vs.legendary"));
                case KarFileKind.ItemData:
                    return DefineItem(name, kind);
                case KarFileKind.EnemyData:
                    return DefineEnemy(name, kind);
                case KarFileKind.EffectData:
                    return Define(kind, name + " Effects", "Effects", "Effect archive.", KarRootDefinition.Suffix("_texg", "Texture graphics", "HSD_TEXGraphicBank"), KarRootDefinition.Suffix("_ptcl", "Particle group", "HSD_ParticleGroup"));
                case KarFileKind.UiData:
                    return Define(kind, name + " UI", "UI", "UI scene/model archive.", KarRootDefinition.Suffix("_scene_models", "Scene model list", "HSDNullPointerArrayAccessor<HSD_JOBJDesc>"), KarRootDefinition.Suffix("_scene_data", "Scene object", "HSD_SOBJ"));
                case KarFileKind.Audio:
                    return Define(kind, fileName, "Audio", "Audio stream or sound bank.");
                case KarFileKind.Movie:
                    return Define(kind, fileName, "Movies", "Movie stream.");
                case KarFileKind.Config:
                    return Define(kind, fileName, "Config", "Game configuration file.");
                default:
                    return Define(kind, fileName, "Other", "HSD archive or unclassified project file.");
            }
        }

        public static bool TryGetMapName(string relativePath, KarFileKind kind, out string mapName)
        {
            return KarProjectFileClassifier.TryGetMapName(relativePath, kind, out mapName);
        }

        private static KarArchiveDefinition DefineVehicle(string name, KarFileKind kind)
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

        private static KarArchiveDefinition DefineRider(string name, KarFileKind kind)
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

        private static KarArchiveDefinition DefineItem(string name, KarFileKind kind)
        {
            if (name.Equals("ItCommon", StringComparison.OrdinalIgnoreCase))
                return Define(kind, "Item Common Data", "Items", "Shared item data.", Root("itCommonDataAll", "Shared item data", null));
            if (name.Equals("Item", StringComparison.OrdinalIgnoreCase))
                return Define(kind, "Item Data", "Items", "Item data table.", Root("itData", "Item data table", "HSDArrayAccessor<KAR_Item>"));

            return Define(kind, name + " Item Data", "Items", "Item data archive.");
        }

        private static KarArchiveDefinition DefineEnemy(string name, KarFileKind kind)
        {
            if (name.Equals("Enemy", StringComparison.OrdinalIgnoreCase))
                return Define(kind, "Enemy Data", "Enemies", "Enemy data table.", Root("emDataAll", "Enemy data table", null));

            string rootName = LowercaseFirst(name) + "Group";
            return Define(kind, "Enemy Data: " + StripPrefix(name, "Em"), "Enemies", "Enemy data group.", Root(rootName, "Enemy data group", "KAR_emData"));
        }

        private static KarArchiveDefinition GetDefinitionFallback(string relativePath, KarFileKind kind)
        {
            return Define(kind, Path.GetFileName(relativePath), kind.ToString(), "KAR project file.");
        }

        private static KarArchiveDefinition Define(KarFileKind kind, string displayName, string category, string description, params KarRootDefinition[] roots)
        {
            return new KarArchiveDefinition(kind, displayName, category, description, roots);
        }

        private static KarRootDefinition Root(string name, string description, string accessorTypeName, bool isRequired = true, string dataDefinitionId = null)
        {
            if (!string.IsNullOrWhiteSpace(dataDefinitionId))
                return KarRootDefinition.ExactData(name, description, accessorTypeName, dataDefinitionId, isRequired);

            return KarRootDefinition.Exact(name, description, accessorTypeName, isRequired);
        }

        private static string StripPrefix(string value, string prefix)
        {
            if (value.StartsWith(prefix, StringComparison.OrdinalIgnoreCase))
                return value.Substring(prefix.Length);

            return value;
        }

        private static string LowercaseFirst(string value)
        {
            if (string.IsNullOrEmpty(value))
                return value;

            return char.ToLowerInvariant(value[0]) + value.Substring(1);
        }

        private static string ToRiderMotionName(string value)
        {
            int motionIndex = value.IndexOf("Motion", StringComparison.OrdinalIgnoreCase);
            if (motionIndex < 0)
                return value;

            string before = value.Substring(0, motionIndex);
            string after = value.Substring(motionIndex + "Motion".Length);
            return before + after;
        }
    }
}
