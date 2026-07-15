using System;

namespace KARToolkit.Core
{
    public sealed class KarFileKindClassificationRule
    {
        private readonly Func<KarFileKindClassificationRequest, KarFileKindClassificationResult> _classify;

        public KarFileKindClassificationRule(
            string id,
            string displayName,
            string description,
            Func<KarFileKindClassificationRequest, KarFileKindClassificationResult> classify)
        {
            if (string.IsNullOrWhiteSpace(id))
                throw new ArgumentException("File kind classification rule id cannot be empty.", nameof(id));
            if (string.IsNullOrWhiteSpace(displayName))
                throw new ArgumentException("File kind classification rule display name cannot be empty.", nameof(displayName));

            Id = id;
            DisplayName = displayName;
            Description = description ?? "";
            _classify = classify ?? throw new ArgumentNullException(nameof(classify));
        }

        public string Id { get; }

        public string DisplayName { get; }

        public string Description { get; }

        public KarFileKindClassificationResult Classify(KarFileKindClassificationRequest request)
        {
            if (request == null)
                throw new ArgumentNullException(nameof(request));

            return _classify(request);
        }

        public KarFileKindClassificationRuleContract CreateContract()
        {
            return KarFileKindClassificationRuleContract.Create(this);
        }
    }
}
