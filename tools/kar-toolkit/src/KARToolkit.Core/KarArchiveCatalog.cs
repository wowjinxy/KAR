using System.IO;
using static KARToolkit.Core.KarArchiveDefinitionFactory;

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
                    return KarVehicleArchiveDefinitions.DefineVehicle(name, kind);
                case KarFileKind.RiderData:
                    return KarRiderArchiveDefinitions.DefineRider(name, kind);
                case KarFileKind.VersusData:
                    return KarVersusArchiveDefinitions.DefineVersus(name, kind);
                case KarFileKind.ItemData:
                    return KarItemArchiveDefinitions.DefineItem(name, kind);
                case KarFileKind.EnemyData:
                    return KarEnemyArchiveDefinitions.DefineEnemy(name, kind);
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

    }
}
