using HSDRaw;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace KARToolkit.Core
{
    public static class KarArchiveCatalog
    {
        public static KarFileKind ClassifyKind(string relativePath)
        {
            string fileName = Path.GetFileName(relativePath);
            string name = Path.GetFileNameWithoutExtension(fileName);
            string extension = Path.GetExtension(fileName);

            if (extension.Equals(".ini", StringComparison.OrdinalIgnoreCase))
                return KarFileKind.Config;
            if (extension.Equals(".h4m", StringComparison.OrdinalIgnoreCase))
                return KarFileKind.Movie;
            if (IsAudioExtension(extension))
                return KarFileKind.Audio;
            if (!extension.Equals(".dat", StringComparison.OrdinalIgnoreCase))
                return KarFileKind.Unknown;

            if (fileName.Equals("Stage.dat", StringComparison.OrdinalIgnoreCase))
                return KarFileKind.StageTable;
            if (name.StartsWith("A2Ef", StringComparison.OrdinalIgnoreCase))
                return KarFileKind.EffectData;
            if (name.StartsWith("A2", StringComparison.OrdinalIgnoreCase))
                return KarFileKind.A2dPackage;
            if (name.Equals("GrCommon", StringComparison.OrdinalIgnoreCase))
                return KarFileKind.MapCommon;
            if (name.StartsWith("Gr", StringComparison.OrdinalIgnoreCase))
            {
                if (name.EndsWith("Model", StringComparison.OrdinalIgnoreCase))
                    return KarFileKind.MapModel;
                if (name.EndsWith("Event", StringComparison.OrdinalIgnoreCase))
                    return KarFileKind.MapEvent;
                return KarFileKind.MapData;
            }
            if (name.StartsWith("Rd", StringComparison.OrdinalIgnoreCase))
                return KarFileKind.RiderData;
            if (name.StartsWith("Vc", StringComparison.OrdinalIgnoreCase))
                return KarFileKind.VehicleData;
            if (name.StartsWith("Ef", StringComparison.OrdinalIgnoreCase))
                return KarFileKind.EffectData;
            if (name.StartsWith("It", StringComparison.OrdinalIgnoreCase) || name.Equals("Item", StringComparison.OrdinalIgnoreCase))
                return KarFileKind.ItemData;
            if (name.StartsWith("Em", StringComparison.OrdinalIgnoreCase) || name.Equals("Enemy", StringComparison.OrdinalIgnoreCase))
                return KarFileKind.EnemyData;
            if (name.StartsWith("Mn", StringComparison.OrdinalIgnoreCase) ||
                name.StartsWith("If", StringComparison.OrdinalIgnoreCase) ||
                name.StartsWith("Sis", StringComparison.OrdinalIgnoreCase) ||
                name.StartsWith("Ending", StringComparison.OrdinalIgnoreCase))
            {
                return KarFileKind.UiData;
            }
            if (name.StartsWith("Vs", StringComparison.OrdinalIgnoreCase))
                return KarFileKind.VersusData;

            return KarFileKind.HsdArchive;
        }

        public static KarArchiveDefinition GetDefinition(string relativePath)
        {
            return GetDefinition(relativePath, ClassifyKind(relativePath));
        }

        public static bool IsHsdArchiveKind(KarFileKind kind)
        {
            switch (kind)
            {
                case KarFileKind.HsdArchive:
                case KarFileKind.MapData:
                case KarFileKind.MapModel:
                case KarFileKind.MapEvent:
                case KarFileKind.MapCommon:
                case KarFileKind.StageTable:
                case KarFileKind.RiderData:
                case KarFileKind.VehicleData:
                case KarFileKind.EffectData:
                case KarFileKind.ItemData:
                case KarFileKind.EnemyData:
                case KarFileKind.UiData:
                case KarFileKind.VersusData:
                    return true;
                default:
                    return false;
            }
        }

        public static KarArchiveDefinition GetDefinition(string relativePath, KarFileKind kind)
        {
            string fileName = Path.GetFileName(relativePath);
            string name = Path.GetFileNameWithoutExtension(fileName);

            switch (kind)
            {
                case KarFileKind.StageTable:
                    return Define(kind, "Stage Table", "Maps", "Global stage table.", Root("stData", "Stage table", "KAR_stData", dataDefinitionId: "kar.stage.table"));
                case KarFileKind.MapCommon:
                    return Define(kind, "Map Common Data", "Maps", "Shared map data used by stages.", Root("grDataCommon", "Shared map data", "KAR_grDataCommon"));
                case KarFileKind.MapData:
                    return DefineMapData(relativePath, kind);
                case KarFileKind.MapModel:
                    return DefineMapModel(relativePath, kind);
                case KarFileKind.MapEvent:
                    return DefineMapEvent(relativePath, kind);
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
            mapName = null;

            if (kind != KarFileKind.MapData &&
                kind != KarFileKind.MapModel &&
                kind != KarFileKind.MapEvent)
            {
                return false;
            }

            string name = Path.GetFileNameWithoutExtension(relativePath);
            if (!name.StartsWith("Gr", StringComparison.OrdinalIgnoreCase))
                return false;

            mapName = name.Substring(2);

            if (kind == KarFileKind.MapModel && mapName.EndsWith("Model", StringComparison.OrdinalIgnoreCase))
                mapName = mapName.Substring(0, mapName.Length - "Model".Length);
            else if (kind == KarFileKind.MapEvent && mapName.EndsWith("Event", StringComparison.OrdinalIgnoreCase))
                mapName = mapName.Substring(0, mapName.Length - "Event".Length);

            return mapName.Length > 0;
        }

        public static KarArchiveInfo Inspect(KarProjectFile file, HSDRawFile hsdFile)
        {
            if (file == null)
                throw new ArgumentNullException(nameof(file));
            if (hsdFile == null)
                throw new ArgumentNullException(nameof(hsdFile));

            KarArchiveDefinition definition = file.ArchiveDefinition ?? GetDefinition(file.RelativePath, file.Kind);
            List<KarArchiveRootInfo> roots = hsdFile.Roots
                .Select(root =>
                {
                    KarRootDefinition rootDefinition = definition.FindRoot(root.Name);
                    string accessorTypeName = root.Data == null ? null : root.Data.GetType().Name;
                    KarDataDefinition dataDefinition = ResolveDataDefinition(rootDefinition, accessorTypeName);
                    return new KarArchiveRootInfo(
                        root.Name,
                        accessorTypeName,
                        rootDefinition,
                        KarDataInspector.InspectFields(root.Data, dataDefinition));
                })
                .ToList();

            return new KarArchiveInfo(file, definition, roots);
        }

        private static KarDataDefinition ResolveDataDefinition(KarRootDefinition rootDefinition, string accessorTypeName)
        {
            if (rootDefinition != null && rootDefinition.DataDefinition != null)
                return rootDefinition.DataDefinition;

            KarDataDefinition definition;
            if (KarDataDefinitionCatalog.TryGetByAccessorTypeName(accessorTypeName, out definition))
                return definition;

            return null;
        }

        private static KarArchiveDefinition DefineMapData(string relativePath, KarFileKind kind)
        {
            if (!TryGetMapName(relativePath, kind, out string mapName))
                return GetDefinitionFallback(relativePath, kind);

            return Define(kind, "Map Data: " + mapName, "Maps", "Map gameplay data and stage setup.", Root("grData" + mapName, "Map gameplay data", "KAR_grData", dataDefinitionId: "kar.gr.data"));
        }

        private static KarArchiveDefinition DefineMapModel(string relativePath, KarFileKind kind)
        {
            if (!TryGetMapName(relativePath, kind, out string mapName))
                return GetDefinitionFallback(relativePath, kind);

            return Define(
                kind,
                "Map Model: " + mapName,
                "Maps",
                "Map model and map model motion data.",
                Root("grModel" + mapName, "Map model data", "KAR_grModel"),
                Root("grModelMotion" + mapName, "Map model motion data", "HSDArrayAccessor<KAR_grModelMotion>", false));
        }

        private static KarArchiveDefinition DefineMapEvent(string relativePath, KarFileKind kind)
        {
            if (!TryGetMapName(relativePath, kind, out string mapName))
                return GetDefinitionFallback(relativePath, kind);

            return Define(kind, "Map Events: " + mapName, "Maps", "Map event/script archive tied to the map bundle.", Root("grEventDataAll" + mapName, "Map event/script data", null, dataDefinitionId: "kar.gr.eventDataAll"));
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

        private static bool IsAudioExtension(string extension)
        {
            return extension.Equals(".hps", StringComparison.OrdinalIgnoreCase) ||
                extension.Equals(".ssm", StringComparison.OrdinalIgnoreCase) ||
                extension.Equals(".aw", StringComparison.OrdinalIgnoreCase);
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
