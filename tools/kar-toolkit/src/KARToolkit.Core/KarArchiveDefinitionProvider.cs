using System;
using System.Collections.Generic;

namespace KARToolkit.Core
{
    public class KarArchiveDefinitionProvider
    {
        public static KarArchiveDefinitionProvider Default { get; } =
            new KarArchiveDefinitionProvider(KarArchiveDefinitionRuleRegistry.Default);

        public KarArchiveDefinitionProvider()
            : this(KarArchiveDefinitionRuleRegistry.Default)
        {
        }

        public KarArchiveDefinitionProvider(KarArchiveDefinitionRuleRegistry ruleRegistry)
        {
            RuleRegistry = ruleRegistry ?? throw new ArgumentNullException(nameof(ruleRegistry));
        }

        public KarArchiveDefinitionRuleRegistry RuleRegistry { get; }

        public IReadOnlyList<KarArchiveDefinitionRule> Rules => RuleRegistry.Rules;

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
            return RuleRegistry.ResolveDefinition(relativePath, kind, mapName);
        }
    }
}
