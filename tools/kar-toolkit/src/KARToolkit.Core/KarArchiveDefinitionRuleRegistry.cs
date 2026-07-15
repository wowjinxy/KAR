using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarArchiveDefinitionRuleRegistry
    {
        public static KarArchiveDefinitionRuleRegistry Default { get; } =
            new KarArchiveDefinitionRuleRegistry(CreateDefaultRules());

        private readonly IReadOnlyList<KarArchiveDefinitionRule> _rules;
        private readonly Dictionary<string, KarArchiveDefinitionRule> _rulesById;

        public KarArchiveDefinitionRuleRegistry(IEnumerable<KarArchiveDefinitionRule> rules)
        {
            if (rules == null)
                throw new ArgumentNullException(nameof(rules));

            _rules = rules
                .ToList()
                .AsReadOnly();
            _rulesById = new Dictionary<string, KarArchiveDefinitionRule>(StringComparer.OrdinalIgnoreCase);

            foreach (KarArchiveDefinitionRule rule in _rules)
            {
                if (rule == null)
                    throw new ArgumentException("Archive definition rules cannot contain null entries.", nameof(rules));
                if (_rulesById.ContainsKey(rule.Id))
                    throw new ArgumentException("Duplicate archive definition rule id: " + rule.Id, nameof(rules));

                _rulesById.Add(rule.Id, rule);
            }
        }

        public IReadOnlyList<KarArchiveDefinitionRule> Rules => _rules;

        public KarArchiveDefinitionRule FindRule(string id)
        {
            KarArchiveDefinitionRule rule;
            if (!TryFindRule(id, out rule))
                throw new KeyNotFoundException("KAR archive definition rule was not found: " + id);

            return rule;
        }

        public bool TryFindRule(string id, out KarArchiveDefinitionRule rule)
        {
            rule = null;
            return !string.IsNullOrWhiteSpace(id) && _rulesById.TryGetValue(id, out rule);
        }

        public KarArchiveDefinition ResolveDefinition(string relativePath, KarFileKind kind, string mapName)
        {
            return ResolveDefinition(new KarArchiveDefinitionRequest(relativePath, kind, mapName));
        }

        public KarArchiveDefinition ResolveDefinition(KarArchiveDefinitionRequest request)
        {
            if (request == null)
                throw new ArgumentNullException(nameof(request));

            foreach (KarArchiveDefinitionRule rule in _rules)
            {
                KarArchiveDefinition definition = rule.ResolveDefinition(request);
                if (definition != null)
                    return definition;
            }

            throw new InvalidOperationException("No KAR archive definition rule resolved a definition for: " + request.RelativePath);
        }

        private static IReadOnlyList<KarArchiveDefinitionRule> CreateDefaultRules()
        {
            return new[]
            {
                Rule("stage-table-archive-definitions", "Stage Table Archive Definitions", "Defines global stage table archive roots.", request =>
                    request.Kind == KarFileKind.StageTable ? KarMapArchiveDefinitions.DefineStageTable(request.Kind) : null),
                Rule("map-common-archive-definitions", "Map Common Archive Definitions", "Defines shared map archive roots.", request =>
                    request.Kind == KarFileKind.MapCommon ? KarMapArchiveDefinitions.DefineMapCommon(request.Kind) : null),
                Rule("map-data-archive-definitions", "Map Data Archive Definitions", "Defines map data archive roots when a map name can be resolved.", request =>
                    request.Kind == KarFileKind.MapData && request.HasMapName ? KarMapArchiveDefinitions.DefineMapData(request.Kind, request.MapName) : null),
                Rule("map-model-archive-definitions", "Map Model Archive Definitions", "Defines map model archive roots when a map name can be resolved.", request =>
                    request.Kind == KarFileKind.MapModel && request.HasMapName ? KarMapArchiveDefinitions.DefineMapModel(request.Kind, request.MapName) : null),
                Rule("map-event-archive-definitions", "Map Event Archive Definitions", "Defines map event/script archive roots when a map name can be resolved.", request =>
                    request.Kind == KarFileKind.MapEvent && request.HasMapName ? KarMapArchiveDefinitions.DefineMapEvent(request.Kind, request.MapName) : null),
                Rule("a2d-package-archive-definitions", "A2D Package Archive Definitions", "Defines A2D package file metadata.", request =>
                    request.Kind == KarFileKind.A2dPackage ? KarGeneralArchiveDefinitions.DefineA2dPackage(request.Kind) : null),
                Rule("vehicle-archive-definitions", "Vehicle Archive Definitions", "Defines vehicle data archive roots.", request =>
                    request.Kind == KarFileKind.VehicleData ? KarVehicleArchiveDefinitions.DefineVehicle(request.Name, request.Kind) : null),
                Rule("rider-archive-definitions", "Rider Archive Definitions", "Defines rider data archive roots.", request =>
                    request.Kind == KarFileKind.RiderData ? KarRiderArchiveDefinitions.DefineRider(request.Name, request.Kind) : null),
                Rule("versus-archive-definitions", "Versus Archive Definitions", "Defines versus data archive roots.", request =>
                    request.Kind == KarFileKind.VersusData ? KarVersusArchiveDefinitions.DefineVersus(request.Name, request.Kind) : null),
                Rule("item-archive-definitions", "Item Archive Definitions", "Defines item data archive roots.", request =>
                    request.Kind == KarFileKind.ItemData ? KarItemArchiveDefinitions.DefineItem(request.Name, request.Kind) : null),
                Rule("enemy-archive-definitions", "Enemy Archive Definitions", "Defines enemy data archive roots.", request =>
                    request.Kind == KarFileKind.EnemyData ? KarEnemyArchiveDefinitions.DefineEnemy(request.Name, request.Kind) : null),
                Rule("effect-archive-definitions", "Effect Archive Definitions", "Defines effect archive roots.", request =>
                    request.Kind == KarFileKind.EffectData ? KarGeneralArchiveDefinitions.DefineEffect(request.Name, request.Kind) : null),
                Rule("ui-archive-definitions", "UI Archive Definitions", "Defines UI archive roots.", request =>
                    request.Kind == KarFileKind.UiData ? KarGeneralArchiveDefinitions.DefineUi(request.Name, request.Kind) : null),
                Rule("script-table-archive-definitions", "Script Table Archive Definitions", "Defines loose script/table resource metadata.", request =>
                    request.Kind == KarFileKind.ScriptTable ? KarGeneralArchiveDefinitions.DefineScriptTable(request.FileName, request.Kind) : null),
                Rule("audio-archive-definitions", "Audio Archive Definitions", "Defines audio file metadata.", request =>
                    request.Kind == KarFileKind.Audio ? KarGeneralArchiveDefinitions.DefineAudio(request.FileName, request.Kind) : null),
                Rule("movie-archive-definitions", "Movie Archive Definitions", "Defines movie file metadata.", request =>
                    request.Kind == KarFileKind.Movie ? KarGeneralArchiveDefinitions.DefineMovie(request.FileName, request.Kind) : null),
                Rule("config-archive-definitions", "Config Archive Definitions", "Defines config file metadata.", request =>
                    request.Kind == KarFileKind.Config ? KarGeneralArchiveDefinitions.DefineConfig(request.FileName, request.Kind) : null),
                Rule("fallback-archive-definitions", "Fallback Archive Definitions", "Defines fallback metadata for unknown or partially resolved archive kinds.", request =>
                    KarGeneralArchiveDefinitions.DefineFallback(request.RelativePath, request.Kind)),
            };
        }

        private static KarArchiveDefinitionRule Rule(
            string id,
            string displayName,
            string description,
            Func<KarArchiveDefinitionRequest, KarArchiveDefinition> resolveDefinition)
        {
            return new KarArchiveDefinitionRule(id, displayName, description, resolveDefinition);
        }
    }
}
