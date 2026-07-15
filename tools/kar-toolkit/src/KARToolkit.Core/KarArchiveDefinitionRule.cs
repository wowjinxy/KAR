using System;

namespace KARToolkit.Core
{
    public sealed class KarArchiveDefinitionRule
    {
        private readonly Func<KarArchiveDefinitionRequest, KarArchiveDefinition> _resolveDefinition;

        public KarArchiveDefinitionRule(
            string id,
            string displayName,
            string description,
            Func<KarArchiveDefinitionRequest, KarArchiveDefinition> resolveDefinition)
        {
            if (string.IsNullOrWhiteSpace(id))
                throw new ArgumentException("Archive definition rule id cannot be empty.", nameof(id));
            if (string.IsNullOrWhiteSpace(displayName))
                throw new ArgumentException("Archive definition rule display name cannot be empty.", nameof(displayName));

            Id = id;
            DisplayName = displayName;
            Description = description ?? "";
            _resolveDefinition = resolveDefinition ?? throw new ArgumentNullException(nameof(resolveDefinition));
        }

        public string Id { get; }

        public string DisplayName { get; }

        public string Description { get; }

        public KarArchiveDefinition ResolveDefinition(KarArchiveDefinitionRequest request)
        {
            if (request == null)
                throw new ArgumentNullException(nameof(request));

            return _resolveDefinition(request);
        }

        public KarArchiveDefinitionRuleContract CreateContract()
        {
            return KarArchiveDefinitionRuleContract.Create(this);
        }
    }
}
