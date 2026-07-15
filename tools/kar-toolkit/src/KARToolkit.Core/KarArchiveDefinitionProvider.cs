using System.IO;

namespace KARToolkit.Core
{
    public class KarArchiveDefinitionProvider
    {
        public static KarArchiveDefinitionProvider Default { get; } = new KarArchiveDefinitionProvider();

        public KarArchiveDefinition GetDefinition(string relativePath)
        {
            return GetDefinition(relativePath, KarProjectFileClassifier.ClassifyKind(relativePath));
        }

        public KarArchiveDefinition GetDefinition(string relativePath, KarFileKind kind)
        {
            string mapName;
            if (KarProjectFileClassifier.TryGetMapName(relativePath, kind, out mapName))
                return GetDefinition(relativePath, kind, mapName);

            return GetDefinition(relativePath, kind, null);
        }

        public virtual KarArchiveDefinition GetDefinition(string relativePath, KarFileKind kind, string mapName)
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
                    return string.IsNullOrEmpty(mapName)
                        ? KarGeneralArchiveDefinitions.DefineFallback(relativePath, kind)
                        : KarMapArchiveDefinitions.DefineMapData(kind, mapName);
                case KarFileKind.MapModel:
                    return string.IsNullOrEmpty(mapName)
                        ? KarGeneralArchiveDefinitions.DefineFallback(relativePath, kind)
                        : KarMapArchiveDefinitions.DefineMapModel(kind, mapName);
                case KarFileKind.MapEvent:
                    return string.IsNullOrEmpty(mapName)
                        ? KarGeneralArchiveDefinitions.DefineFallback(relativePath, kind)
                        : KarMapArchiveDefinitions.DefineMapEvent(kind, mapName);
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
    }
}
