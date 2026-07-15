using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectOperationDomainRule
    {
        private readonly Func<KarProjectResourceInfo, bool> _matches;

        public KarProjectOperationDomainRule(
            string id,
            string displayName,
            string description,
            Func<KarProjectResourceInfo, bool> matches)
        {
            Id = RequireText(id, nameof(id));
            DisplayName = RequireText(displayName, nameof(displayName));
            Description = description ?? "";
            _matches = matches ?? throw new ArgumentNullException(nameof(matches));
        }

        public string Id { get; }

        public string DisplayName { get; }

        public string Description { get; }

        public bool Matches(KarProjectResourceInfo resource)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));

            return _matches(resource);
        }

        private static string RequireText(string value, string parameterName)
        {
            if (string.IsNullOrWhiteSpace(value))
                throw new ArgumentException("Value cannot be empty.", parameterName);

            return value;
        }
    }
}
