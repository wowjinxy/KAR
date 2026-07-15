using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarFileKindRegistry
    {
        public static KarFileKindRegistry Default { get; } = new KarFileKindRegistry(CreateDefaultDescriptors());

        private readonly IReadOnlyList<KarFileKindDescriptor> _descriptors;
        private readonly Dictionary<KarFileKind, KarFileKindDescriptor> _descriptorsByKind;
        private readonly Dictionary<string, KarFileKindDescriptor> _descriptorsById;

        public KarFileKindRegistry(IEnumerable<KarFileKindDescriptor> descriptors)
        {
            if (descriptors == null)
                throw new ArgumentNullException(nameof(descriptors));

            _descriptors = descriptors
                .ToList()
                .AsReadOnly();
            _descriptorsByKind = new Dictionary<KarFileKind, KarFileKindDescriptor>();
            _descriptorsById = new Dictionary<string, KarFileKindDescriptor>(StringComparer.OrdinalIgnoreCase);

            foreach (KarFileKindDescriptor descriptor in _descriptors)
            {
                if (_descriptorsByKind.ContainsKey(descriptor.Kind))
                    throw new ArgumentException("Duplicate file kind descriptor: " + descriptor.Kind, nameof(descriptors));
                if (_descriptorsById.ContainsKey(descriptor.Id))
                    throw new ArgumentException("Duplicate file kind id: " + descriptor.Id, nameof(descriptors));

                _descriptorsByKind.Add(descriptor.Kind, descriptor);
                _descriptorsById.Add(descriptor.Id, descriptor);
            }

            foreach (KarFileKind kind in Enum.GetValues(typeof(KarFileKind)))
            {
                if (!_descriptorsByKind.ContainsKey(kind))
                    throw new ArgumentException("Missing file kind descriptor: " + kind, nameof(descriptors));
            }
        }

        public IReadOnlyList<KarFileKindDescriptor> Descriptors => _descriptors;

        public KarFileKindDescriptor GetDescriptor(KarFileKind kind)
        {
            KarFileKindDescriptor descriptor;
            if (!TryGetDescriptor(kind, out descriptor))
                throw new KeyNotFoundException("KAR file kind descriptor was not found: " + kind);

            return descriptor;
        }

        public bool TryGetDescriptor(KarFileKind kind, out KarFileKindDescriptor descriptor)
        {
            return _descriptorsByKind.TryGetValue(kind, out descriptor);
        }

        public KarFileKindDescriptor FindDescriptor(string idOrKind)
        {
            KarFileKindDescriptor descriptor;
            if (!TryFindDescriptor(idOrKind, out descriptor))
                throw new KeyNotFoundException("KAR file kind descriptor was not found: " + idOrKind);

            return descriptor;
        }

        public bool TryFindDescriptor(string idOrKind, out KarFileKindDescriptor descriptor)
        {
            descriptor = null;
            if (string.IsNullOrWhiteSpace(idOrKind))
                return false;

            if (_descriptorsById.TryGetValue(idOrKind, out descriptor))
                return true;

            KarFileKind kind;
            return Enum.TryParse(idOrKind, true, out kind) && TryGetDescriptor(kind, out descriptor);
        }

        public KarFileKindMatch Classify(string relativePath)
        {
            if (relativePath == null)
                throw new ArgumentNullException(nameof(relativePath));

            KarFileKind kind = ClassifyKind(relativePath);
            string mapName;
            TryGetMapName(relativePath, kind, out mapName);
            return new KarFileKindMatch(relativePath, GetDescriptor(kind), mapName);
        }

        public KarFileKind ClassifyKind(string relativePath)
        {
            if (relativePath == null)
                throw new ArgumentNullException(nameof(relativePath));

            string fileName = Path.GetFileName(relativePath);
            string name = Path.GetFileNameWithoutExtension(fileName);
            string extension = Path.GetExtension(fileName);

            if (extension.Equals(".ini", StringComparison.OrdinalIgnoreCase))
                return KarFileKind.Config;
            if (extension.Equals(".tm", StringComparison.OrdinalIgnoreCase))
                return KarFileKind.ScriptTable;
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

        public bool IsHsdArchiveKind(KarFileKind kind)
        {
            return GetDescriptor(kind).IsHsdArchive;
        }

        public bool IsA2DPackageKind(KarFileKind kind)
        {
            return GetDescriptor(kind).IsA2DPackage;
        }

        public bool IsScriptTableKind(KarFileKind kind)
        {
            return GetDescriptor(kind).IsScriptTable;
        }

        public bool TryGetMapName(string relativePath, KarFileKind kind, out string mapName)
        {
            mapName = null;

            if (!GetDescriptor(kind).IsMapBundlePart)
                return false;

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

        private static IReadOnlyList<KarFileKindDescriptor> CreateDefaultDescriptors()
        {
            return new[]
            {
                Define(KarFileKind.Unknown, "unknown", "Unknown File", "Other", "Unclassified project file."),
                Define(KarFileKind.HsdArchive, "hsd-archive", "HSD Archive", "Archives", "Generic HSD archive.", isHsdArchive: true),
                Define(KarFileKind.A2dPackage, "a2d-package", "A2D Package", "A2D", "Air Ride 2D package with embedded entries.", isA2DPackage: true),
                Define(KarFileKind.MapData, "map-data", "Map Data", "Maps", "Map gameplay data archive.", isHsdArchive: true, mapBundleRole: "data"),
                Define(KarFileKind.MapModel, "map-model", "Map Model", "Maps", "Map model archive.", isHsdArchive: true, mapBundleRole: "model"),
                Define(KarFileKind.MapEvent, "map-event", "Map Event/Script", "Maps", "Map event and script archive.", isHsdArchive: true, mapBundleRole: "event"),
                Define(KarFileKind.MapCommon, "map-common", "Map Common", "Maps", "Shared map archive.", isHsdArchive: true),
                Define(KarFileKind.StageTable, "stage-table", "Stage Table", "Maps", "Global stage table archive.", isHsdArchive: true),
                Define(KarFileKind.RiderData, "rider-data", "Rider Data", "Riders", "Rider data archive.", isHsdArchive: true),
                Define(KarFileKind.VehicleData, "vehicle-data", "Vehicle Data", "Vehicles", "Vehicle data archive.", isHsdArchive: true),
                Define(KarFileKind.EffectData, "effect-data", "Effect Data", "Effects", "Effect data archive.", isHsdArchive: true),
                Define(KarFileKind.ItemData, "item-data", "Item Data", "Items", "Item data archive.", isHsdArchive: true),
                Define(KarFileKind.EnemyData, "enemy-data", "Enemy Data", "Enemies", "Enemy data archive.", isHsdArchive: true),
                Define(KarFileKind.UiData, "ui-data", "UI Data", "UI", "User interface archive.", isHsdArchive: true),
                Define(KarFileKind.VersusData, "versus-data", "Versus Data", "Versus", "Versus mode data archive.", isHsdArchive: true),
                Define(KarFileKind.ScriptTable, "script-table", "Script Table", "Scripts", "Loose 2D script/table resource.", isScriptTable: true),
                Define(KarFileKind.Audio, "audio", "Audio", "Audio", "Audio stream or sound bank.", isMedia: true),
                Define(KarFileKind.Movie, "movie", "Movie", "Movies", "Movie stream.", isMedia: true),
                Define(KarFileKind.Config, "config", "Config", "Config", "Game configuration file.", isConfig: true),
            };
        }

        private static KarFileKindDescriptor Define(
            KarFileKind kind,
            string id,
            string displayName,
            string category,
            string description,
            bool isHsdArchive = false,
            bool isA2DPackage = false,
            bool isScriptTable = false,
            bool isMedia = false,
            bool isConfig = false,
            string mapBundleRole = null)
        {
            return new KarFileKindDescriptor(
                kind,
                id,
                displayName,
                category,
                description,
                isHsdArchive,
                isA2DPackage,
                isScriptTable,
                isMedia,
                isConfig,
                mapBundleRole);
        }

        private static bool IsAudioExtension(string extension)
        {
            return extension.Equals(".hps", StringComparison.OrdinalIgnoreCase) ||
                extension.Equals(".ssm", StringComparison.OrdinalIgnoreCase) ||
                extension.Equals(".aw", StringComparison.OrdinalIgnoreCase);
        }
    }
}
