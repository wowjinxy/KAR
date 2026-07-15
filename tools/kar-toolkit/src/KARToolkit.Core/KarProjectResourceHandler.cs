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
        private readonly IReadOnlyList<KarProjectResourceAction> _actions;

        public KarProjectResourceHandler(
            KarResourceKind kind,
            string id,
            string displayName,
            string description,
            KarProjectResourceCapability capabilities)
            : this(
                kind,
                id,
                displayName,
                description,
                capabilities,
                null)
        {
        }

        public KarProjectResourceHandler(
            KarResourceKind kind,
            string id,
            string displayName,
            string description,
            KarProjectResourceCapability capabilities,
            KarProjectResourceActionRegistry actionRegistry)
        {
            Kind = kind;
            Id = RequireText(id, nameof(id));
            DisplayName = RequireText(displayName, nameof(displayName));
            Description = description ?? "";
            Capabilities = capabilities;
            ActionRegistry = actionRegistry ?? KarProjectResourceActionRegistry.Default;
            _capabilityList = CapabilityValues
                .Where(HasCapability)
                .ToList()
                .AsReadOnly();
            _actions = ActionRegistry.CreateActions(capabilities);
        }

        public KarResourceKind Kind { get; }

        public string Id { get; }

        public string DisplayName { get; }

        public string Description { get; }

        public KarProjectResourceCapability Capabilities { get; }

        public KarProjectResourceActionRegistry ActionRegistry { get; }

        public IReadOnlyList<KarProjectResourceCapability> CapabilityList => _capabilityList;

        public IReadOnlyList<KarProjectResourceAction> Actions => _actions;

        public int ActionCount => Actions.Count;

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

        private static bool HasCapability(KarProjectResourceCapability capabilities, KarProjectResourceCapability capability)
        {
            return capability != KarProjectResourceCapability.None &&
                (capabilities & capability) == capability;
        }

        private static string RequireText(string value, string parameterName)
        {
            if (string.IsNullOrWhiteSpace(value))
                throw new ArgumentException("Value cannot be empty.", parameterName);

            return value;
        }
    }
}
