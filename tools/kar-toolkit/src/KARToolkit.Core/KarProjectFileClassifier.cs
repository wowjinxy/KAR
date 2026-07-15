using System;
using System.IO;

namespace KARToolkit.Core
{
    public static class KarProjectFileClassifier
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

        private static bool IsAudioExtension(string extension)
        {
            return extension.Equals(".hps", StringComparison.OrdinalIgnoreCase) ||
                extension.Equals(".ssm", StringComparison.OrdinalIgnoreCase) ||
                extension.Equals(".aw", StringComparison.OrdinalIgnoreCase);
        }
    }
}
