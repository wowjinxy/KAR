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
                    return KarGeneralArchiveDefinitions.DefineA2dPackage(kind);
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
                    return KarGeneralArchiveDefinitions.DefineEffect(name, kind);
                case KarFileKind.UiData:
                    return KarGeneralArchiveDefinitions.DefineUi(name, kind);
                case KarFileKind.Audio:
                    return KarGeneralArchiveDefinitions.DefineAudio(fileName, kind);
                case KarFileKind.Movie:
                    return KarGeneralArchiveDefinitions.DefineMovie(fileName, kind);
                case KarFileKind.Config:
                    return KarGeneralArchiveDefinitions.DefineConfig(fileName, kind);
                default:
                    return KarGeneralArchiveDefinitions.DefineFallback(relativePath, kind);
            }
        }

        public static bool TryGetMapName(string relativePath, KarFileKind kind, out string mapName)
        {
            return KarProjectFileClassifier.TryGetMapName(relativePath, kind, out mapName);
        }
    }
}
