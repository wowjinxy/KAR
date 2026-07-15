using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceHandler
    {
        private static readonly KarProjectResourceCapability[] CapabilityValues = Enum
            .GetValues(typeof(KarProjectResourceCapability))
            .Cast<KarProjectResourceCapability>()
            .Where(capability => capability != KarProjectResourceCapability.None)
            .ToArray();
        private readonly IReadOnlyList<KarProjectResourceCapability> _capabilityList;

        public KarProjectResourceHandler(
            KarResourceKind kind,
            string id,
            string displayName,
            string description,
            KarProjectResourceCapability capabilities)
        {
            Kind = kind;
            Id = RequireText(id, nameof(id));
            DisplayName = RequireText(displayName, nameof(displayName));
            Description = description ?? "";
            Capabilities = capabilities;
            _capabilityList = CapabilityValues
                .Where(HasCapability)
                .ToList()
                .AsReadOnly();
        }

        public KarResourceKind Kind { get; }

        public string Id { get; }

        public string DisplayName { get; }

        public string Description { get; }

        public KarProjectResourceCapability Capabilities { get; }

        public IReadOnlyList<KarProjectResourceCapability> CapabilityList => _capabilityList;

        public bool CanQueryOutput => HasCapability(KarProjectResourceCapability.QueryOutput);

        public bool CanReadBytes => HasCapability(KarProjectResourceCapability.ReadBytes);

        public bool CanExportToOutput => HasCapability(KarProjectResourceCapability.ExportToOutput);

        public bool CanImportFromFile => HasCapability(KarProjectResourceCapability.ImportFromFile);

        public bool CanQueryFieldValues => HasCapability(KarProjectResourceCapability.QueryFieldValues);

        public bool CanSetScalarFields => HasCapability(KarProjectResourceCapability.SetScalarFields);

        public bool CanApplyOutput => HasCapability(KarProjectResourceCapability.ApplyOutput);

        public bool HasCapability(KarProjectResourceCapability capability)
        {
            return capability != KarProjectResourceCapability.None &&
                (Capabilities & capability) == capability;
        }

        private static string RequireText(string value, string parameterName)
        {
            if (string.IsNullOrWhiteSpace(value))
                throw new ArgumentException("Value cannot be empty.", parameterName);

            return value;
        }
    }
}
