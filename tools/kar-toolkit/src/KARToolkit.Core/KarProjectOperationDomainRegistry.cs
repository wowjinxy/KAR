using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectOperationDomainRegistry
    {
        public static KarProjectOperationDomainRegistry Default { get; } =
            new KarProjectOperationDomainRegistry(CreateDefaultRules());

        private readonly IReadOnlyList<KarProjectOperationDomainRule> _rules;
        private readonly Dictionary<string, KarProjectOperationDomainRule> _rulesById;

        public KarProjectOperationDomainRegistry(IEnumerable<KarProjectOperationDomainRule> rules)
            : this(rules, "resources")
        {
        }

        public KarProjectOperationDomainRegistry(
            IEnumerable<KarProjectOperationDomainRule> rules,
            string defaultDomainId)
        {
            if (rules == null)
                throw new ArgumentNullException(nameof(rules));

            DefaultDomainId = RequireText(defaultDomainId, nameof(defaultDomainId));
            _rules = rules
                .ToList()
                .AsReadOnly();
            _rulesById = new Dictionary<string, KarProjectOperationDomainRule>(StringComparer.OrdinalIgnoreCase);

            foreach (KarProjectOperationDomainRule rule in _rules)
            {
                if (rule == null)
                    throw new ArgumentException("Operation domain rules cannot contain null entries.", nameof(rules));
                if (_rulesById.ContainsKey(rule.Id))
                    throw new ArgumentException("Duplicate operation domain rule id: " + rule.Id, nameof(rules));

                _rulesById.Add(rule.Id, rule);
            }
        }

        public IReadOnlyList<KarProjectOperationDomainRule> Rules => _rules;

        public string DefaultDomainId { get; }

        public KarProjectOperationDomainRule FindRule(string id)
        {
            KarProjectOperationDomainRule rule;
            if (!TryFindRule(id, out rule))
                throw new KeyNotFoundException("KAR operation domain rule was not found: " + id);

            return rule;
        }

        public bool TryFindRule(string id, out KarProjectOperationDomainRule rule)
        {
            rule = null;
            return !string.IsNullOrWhiteSpace(id) && _rulesById.TryGetValue(id, out rule);
        }

        public string ResolveTargetDomain(KarProjectResourceInfo resource)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));

            foreach (KarProjectOperationDomainRule rule in _rules)
            {
                if (rule.Matches(resource))
                    return rule.Id;
            }

            return DefaultDomainId;
        }

        private static IReadOnlyList<KarProjectOperationDomainRule> CreateDefaultRules()
        {
            return new[]
            {
                Define(
                    "script-tables",
                    "Script Tables",
                    "Loose and packaged .tm script table resources.",
                    resource =>
                        string.Equals(resource.Category, "Scripts", StringComparison.OrdinalIgnoreCase) ||
                        (resource.A2DEntry != null && resource.A2DEntry.IsScriptTable) ||
                        (resource.File != null && resource.File.IsScriptTable)),
                Define(
                    "a2d-packages",
                    "A2D Packages",
                    "A2D package files and non-script package entries.",
                    resource =>
                        resource.A2DEntry != null ||
                        (resource.File != null && resource.File.IsA2DPackage)),
                Define(
                    "maps",
                    "Maps",
                    "Map data, model, and event/script bundle resources.",
                    resource => resource.File != null && resource.File.IsMapBundlePart),
                Define(
                    "vehicles",
                    "Vehicles",
                    "Vehicle data resources.",
                    resource => resource.File != null && resource.File.Kind == KarFileKind.VehicleData),
                Define(
                    "archives",
                    "Archives",
                    "Generic HSD archive resources.",
                    resource => resource.File != null && resource.File.IsHsdArchive),
                Define(
                    "files",
                    "Files",
                    "Whole project file resources that are not covered by a richer domain.",
                    resource => resource.IsFile),
            };
        }

        private static KarProjectOperationDomainRule Define(
            string id,
            string displayName,
            string description,
            Func<KarProjectResourceInfo, bool> matches)
        {
            return new KarProjectOperationDomainRule(id, displayName, description, matches);
        }

        private static string RequireText(string value, string parameterName)
        {
            if (string.IsNullOrWhiteSpace(value))
                throw new ArgumentException("Value cannot be empty.", parameterName);

            return value;
        }
    }
}
