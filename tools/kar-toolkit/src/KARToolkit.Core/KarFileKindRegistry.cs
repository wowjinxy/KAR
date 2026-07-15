using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarFileKindRegistry
    {
        public static KarFileKindRegistry Default { get; } =
            new KarFileKindRegistry(CreateDefaultDescriptors(), KarFileKindClassificationRuleRegistry.Default);

        private readonly IReadOnlyList<KarFileKindDescriptor> _descriptors;
        private readonly Dictionary<KarFileKind, KarFileKindDescriptor> _descriptorsByKind;
        private readonly Dictionary<string, KarFileKindDescriptor> _descriptorsById;

        public KarFileKindRegistry(IEnumerable<KarFileKindDescriptor> descriptors)
            : this(descriptors, KarFileKindClassificationRuleRegistry.Default)
        {
        }

        public KarFileKindRegistry(
            IEnumerable<KarFileKindDescriptor> descriptors,
            KarFileKindClassificationRuleRegistry classificationRules)
        {
            if (descriptors == null)
                throw new ArgumentNullException(nameof(descriptors));

            ClassificationRules = classificationRules ?? throw new ArgumentNullException(nameof(classificationRules));
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

        public KarFileKindClassificationRuleRegistry ClassificationRules { get; }

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

            KarFileKindClassificationResult classification = ClassificationRules.Classify(relativePath);
            return new KarFileKindMatch(relativePath, GetDescriptor(classification.Kind), classification.MapName);
        }

        public KarFileKind ClassifyKind(string relativePath)
        {
            return Classify(relativePath).Kind;
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

            KarFileKindClassificationRequest request = new KarFileKindClassificationRequest(relativePath);
            KarFileKindClassificationResult classification;
            if (ClassificationRules.TryClassify(request, out classification) &&
                classification.Kind == kind &&
                classification.HasMapName)
            {
                mapName = classification.MapName;
                return true;
            }

            if (!GetDescriptor(kind).IsMapBundlePart)
                return false;

            if (!request.NameStartsWith("Gr"))
                return false;

            mapName = request.Name.Substring(2);

            if (kind == KarFileKind.MapModel && request.NameEndsWith("Model"))
                mapName = mapName.Substring(0, mapName.Length - "Model".Length);
            else if (kind == KarFileKind.MapEvent && request.NameEndsWith("Event"))
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
                Define(KarFileKind.VehicleSpecialData, "vehicle-special-data", "Vehicle Special Data", "Vehicles", "Vehicle special data archive.", isHsdArchive: true),
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
    }
}
