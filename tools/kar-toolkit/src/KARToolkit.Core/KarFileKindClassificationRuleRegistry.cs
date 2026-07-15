using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarFileKindClassificationRuleRegistry
    {
        public static KarFileKindClassificationRuleRegistry Default { get; } =
            new KarFileKindClassificationRuleRegistry(CreateDefaultRules());

        private readonly IReadOnlyList<KarFileKindClassificationRule> _rules;
        private readonly Dictionary<string, KarFileKindClassificationRule> _rulesById;

        public KarFileKindClassificationRuleRegistry(IEnumerable<KarFileKindClassificationRule> rules)
        {
            if (rules == null)
                throw new ArgumentNullException(nameof(rules));

            _rules = rules
                .ToList()
                .AsReadOnly();
            _rulesById = new Dictionary<string, KarFileKindClassificationRule>(StringComparer.OrdinalIgnoreCase);

            foreach (KarFileKindClassificationRule rule in _rules)
            {
                if (rule == null)
                    throw new ArgumentException("File kind classification rules cannot contain null entries.", nameof(rules));
                if (_rulesById.ContainsKey(rule.Id))
                    throw new ArgumentException("Duplicate file kind classification rule id: " + rule.Id, nameof(rules));

                _rulesById.Add(rule.Id, rule);
            }
        }

        public IReadOnlyList<KarFileKindClassificationRule> Rules => _rules;

        public KarFileKindClassificationRule FindRule(string id)
        {
            KarFileKindClassificationRule rule;
            if (!TryFindRule(id, out rule))
                throw new KeyNotFoundException("KAR file kind classification rule was not found: " + id);

            return rule;
        }

        public bool TryFindRule(string id, out KarFileKindClassificationRule rule)
        {
            rule = null;
            return !string.IsNullOrWhiteSpace(id) && _rulesById.TryGetValue(id, out rule);
        }

        public KarFileKindClassificationResult Classify(string relativePath)
        {
            return Classify(new KarFileKindClassificationRequest(relativePath));
        }

        public KarFileKindClassificationResult Classify(KarFileKindClassificationRequest request)
        {
            if (request == null)
                throw new ArgumentNullException(nameof(request));

            KarFileKindClassificationResult result;
            if (TryClassify(request, out result))
                return result;

            throw new InvalidOperationException("No KAR file kind classification rule matched: " + request.RelativePath);
        }

        public bool TryClassify(string relativePath, out KarFileKindClassificationResult result)
        {
            return TryClassify(new KarFileKindClassificationRequest(relativePath), out result);
        }

        public bool TryClassify(KarFileKindClassificationRequest request, out KarFileKindClassificationResult result)
        {
            if (request == null)
                throw new ArgumentNullException(nameof(request));

            foreach (KarFileKindClassificationRule rule in _rules)
            {
                result = rule.Classify(request);
                if (result != null)
                    return true;
            }

            result = null;
            return false;
        }

        private static IReadOnlyList<KarFileKindClassificationRule> CreateDefaultRules()
        {
            return new[]
            {
                Rule("config-extension-classification", "Config Extension Classification", "Classifies .ini files as config resources.", request =>
                    request.HasExtension(".ini") ? Kind(KarFileKind.Config) : null),
                Rule("script-table-extension-classification", "Script Table Extension Classification", "Classifies .tm files as loose script table resources.", request =>
                    request.HasExtension(".tm") ? Kind(KarFileKind.ScriptTable) : null),
                Rule("movie-extension-classification", "Movie Extension Classification", "Classifies .h4m files as movie resources.", request =>
                    request.HasExtension(".h4m") ? Kind(KarFileKind.Movie) : null),
                Rule("audio-extension-classification", "Audio Extension Classification", "Classifies known audio extensions as audio resources.", request =>
                    IsAudioExtension(request.Extension) ? Kind(KarFileKind.Audio) : null),
                Rule("unknown-extension-classification", "Unknown Extension Classification", "Classifies non-DAT files without richer matches as unknown resources.", request =>
                    !request.HasExtension(".dat") ? Kind(KarFileKind.Unknown) : null),
                Rule("stage-table-classification", "Stage Table Classification", "Classifies Stage.dat as the global stage table.", request =>
                    request.FileNameEquals("Stage.dat") ? Kind(KarFileKind.StageTable) : null),
                Rule("a2-effect-classification", "A2 Effect Classification", "Classifies A2Ef DAT files as effect data before A2D package fallback.", request =>
                    request.NameStartsWith("A2Ef") ? Kind(KarFileKind.EffectData) : null),
                Rule("a2d-package-classification", "A2D Package Classification", "Classifies A2 DAT files as A2D packages.", request =>
                    request.NameStartsWith("A2") ? Kind(KarFileKind.A2dPackage) : null),
                Rule("map-common-classification", "Map Common Classification", "Classifies GrCommon.dat as shared map data.", request =>
                    request.NameEquals("GrCommon") ? Kind(KarFileKind.MapCommon) : null),
                Rule("map-bundle-classification", "Map Bundle Classification", "Classifies Gr*.dat map data, model, and event/script bundle files.", ClassifyMapBundle),
                Rule("rider-data-classification", "Rider Data Classification", "Classifies Rd DAT files as rider data.", request =>
                    request.NameStartsWith("Rd") ? Kind(KarFileKind.RiderData) : null),
                Rule("vehicle-data-classification", "Vehicle Data Classification", "Classifies Vc DAT files as vehicle data.", request =>
                    request.NameStartsWith("Vc") ? Kind(KarFileKind.VehicleData) : null),
                Rule("effect-data-classification", "Effect Data Classification", "Classifies Ef DAT files as effect data.", request =>
                    request.NameStartsWith("Ef") ? Kind(KarFileKind.EffectData) : null),
                Rule("item-data-classification", "Item Data Classification", "Classifies item DAT files as item data.", request =>
                    request.NameStartsWith("It") || request.NameEquals("Item") ? Kind(KarFileKind.ItemData) : null),
                Rule("enemy-data-classification", "Enemy Data Classification", "Classifies enemy DAT files as enemy data.", request =>
                    request.NameStartsWith("Em") || request.NameEquals("Enemy") ? Kind(KarFileKind.EnemyData) : null),
                Rule("ui-data-classification", "UI Data Classification", "Classifies menu, interface, SIS, and ending DAT files as UI data.", request =>
                    request.NameStartsWith("Mn") || request.NameStartsWith("If") || request.NameStartsWith("Sis") || request.NameStartsWith("Ending") ? Kind(KarFileKind.UiData) : null),
                Rule("vehicle-special-data-classification", "Vehicle Special Data Classification", "Classifies Vs DAT files as vehicle special data.", request =>
                    request.NameStartsWith("Vs") ? Kind(KarFileKind.VehicleSpecialData) : null),
                Rule("hsd-archive-fallback-classification", "HSD Archive Fallback Classification", "Classifies unmatched DAT files as generic HSD archives.", request =>
                    Kind(KarFileKind.HsdArchive)),
            };
        }

        private static KarFileKindClassificationResult ClassifyMapBundle(KarFileKindClassificationRequest request)
        {
            if (!request.NameStartsWith("Gr"))
                return null;

            KarFileKind kind = KarFileKind.MapData;
            string mapName = request.Name.Substring(2);
            if (request.NameEndsWith("Model"))
            {
                kind = KarFileKind.MapModel;
                mapName = mapName.Substring(0, mapName.Length - "Model".Length);
            }
            else if (request.NameEndsWith("Event"))
            {
                kind = KarFileKind.MapEvent;
                mapName = mapName.Substring(0, mapName.Length - "Event".Length);
            }

            return new KarFileKindClassificationResult(kind, mapName);
        }

        private static KarFileKindClassificationResult Kind(KarFileKind kind)
        {
            return new KarFileKindClassificationResult(kind);
        }

        private static KarFileKindClassificationRule Rule(
            string id,
            string displayName,
            string description,
            Func<KarFileKindClassificationRequest, KarFileKindClassificationResult> classify)
        {
            return new KarFileKindClassificationRule(id, displayName, description, classify);
        }

        private static bool IsAudioExtension(string extension)
        {
            return extension.Equals(".hps", StringComparison.OrdinalIgnoreCase) ||
                extension.Equals(".ssm", StringComparison.OrdinalIgnoreCase) ||
                extension.Equals(".aw", StringComparison.OrdinalIgnoreCase);
        }
    }
}
