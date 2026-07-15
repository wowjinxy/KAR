using System.IO;
using static KARToolkit.Core.KarArchiveDefinitionFactory;

namespace KARToolkit.Core
{
    internal static class KarMapArchiveDefinitions
    {
        public static KarArchiveDefinition DefineStageTable(KarFileKind kind)
        {
            return Define(kind, "Stage Table", "Maps", "Global stage table.", Root("stData", "Stage table", "KAR_stData", dataDefinitionId: "kar.stage.table"));
        }

        public static KarArchiveDefinition DefineMapCommon(KarFileKind kind)
        {
            return Define(kind, "Map Common Data", "Maps", "Shared map data used by stages.", Root("grDataCommon", "Shared map data", "KAR_grDataCommon"));
        }

        public static KarArchiveDefinition DefineMapData(string relativePath, KarFileKind kind)
        {
            if (!KarProjectFileClassifier.TryGetMapName(relativePath, kind, out string mapName))
                return DefineFallback(relativePath, kind);

            return DefineMapData(kind, mapName);
        }

        public static KarArchiveDefinition DefineMapData(KarFileKind kind, string mapName)
        {
            return Define(kind, "Map Data: " + mapName, "Maps", "Map gameplay data and stage setup.", Root("grData" + mapName, "Map gameplay data", "KAR_grData", dataDefinitionId: "kar.gr.data"));
        }

        public static KarArchiveDefinition DefineMapModel(string relativePath, KarFileKind kind)
        {
            if (!KarProjectFileClassifier.TryGetMapName(relativePath, kind, out string mapName))
                return DefineFallback(relativePath, kind);

            return DefineMapModel(kind, mapName);
        }

        public static KarArchiveDefinition DefineMapModel(KarFileKind kind, string mapName)
        {
            return Define(
                kind,
                "Map Model: " + mapName,
                "Maps",
                "Map model and map model motion data.",
                Root("grModel" + mapName, "Map model data", "KAR_grModel"),
                Root("grModelMotion" + mapName, "Map model motion data", "HSDArrayAccessor<KAR_grModelMotion>", false));
        }

        public static KarArchiveDefinition DefineMapEvent(string relativePath, KarFileKind kind)
        {
            if (!KarProjectFileClassifier.TryGetMapName(relativePath, kind, out string mapName))
                return DefineFallback(relativePath, kind);

            return DefineMapEvent(kind, mapName);
        }

        public static KarArchiveDefinition DefineMapEvent(KarFileKind kind, string mapName)
        {
            return Define(kind, "Map Events: " + mapName, "Maps", "Map event/script archive tied to the map bundle.", Root("grEventDataAll" + mapName, "Map event/script data", null, dataDefinitionId: "kar.gr.eventDataAll"));
        }

        private static KarArchiveDefinition DefineFallback(string relativePath, KarFileKind kind)
        {
            return Define(kind, Path.GetFileName(relativePath), kind.ToString(), "KAR project file.");
        }
    }
}
