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
            _actions = CreateActions(capabilities)
                .ToList()
                .AsReadOnly();
        }

        public KarResourceKind Kind { get; }

        public string Id { get; }

        public string DisplayName { get; }

        public string Description { get; }

        public KarProjectResourceCapability Capabilities { get; }

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

        private static IEnumerable<KarProjectResourceAction> CreateActions(KarProjectResourceCapability capabilities)
        {
            if (HasCapability(capabilities, KarProjectResourceCapability.QueryOutput))
            {
                yield return new KarProjectResourceAction(
                    "output-status",
                    "Output Status",
                    "Report output-side status for a resource.",
                    KarProjectResourceCapability.QueryOutput,
                    "resource-outputs",
                    "[resource-address]",
                    isReadOnly: true,
                    writesOutput: false,
                    requiresInputFile: false,
                    requiresFieldName: false,
                    requiresValue: false,
                    supportsBatch: true);
            }

            if (HasCapability(capabilities, KarProjectResourceCapability.ReadBytes))
            {
                yield return new KarProjectResourceAction(
                    "byte-status",
                    "Byte Dump Status",
                    "Report active resource byte length, hash, and dump status.",
                    KarProjectResourceCapability.ReadBytes,
                    "resource-bytes",
                    "[resource-address]",
                    isReadOnly: true,
                    writesOutput: false,
                    requiresInputFile: false,
                    requiresFieldName: false,
                    requiresValue: false,
                    supportsBatch: true);

                yield return new KarProjectResourceAction(
                    "dump-bytes",
                    "Dump Bytes",
                    "Write a raw resource byte copy under the output folder.",
                    KarProjectResourceCapability.ReadBytes,
                    "dump-resource-bytes",
                    "[resource-address]",
                    isReadOnly: false,
                    writesOutput: true,
                    requiresInputFile: false,
                    requiresFieldName: false,
                    requiresValue: false,
                    supportsBatch: true);
            }

            if (HasCapability(capabilities, KarProjectResourceCapability.ExportToOutput))
            {
                yield return new KarProjectResourceAction(
                    "export-output",
                    "Export To Output",
                    "Stage an editable output-side copy for the resource.",
                    KarProjectResourceCapability.ExportToOutput,
                    "export-resource",
                    "<resource-address>",
                    isReadOnly: false,
                    writesOutput: true,
                    requiresInputFile: false,
                    requiresFieldName: false,
                    requiresValue: false,
                    supportsBatch: false);
            }

            if (HasCapability(capabilities, KarProjectResourceCapability.ImportFromFile))
            {
                yield return new KarProjectResourceAction(
                    "import-file",
                    "Import File",
                    "Import replacement bytes from a file into the output folder.",
                    KarProjectResourceCapability.ImportFromFile,
                    "import-resource",
                    "<resource-address> <input-file>",
                    isReadOnly: false,
                    writesOutput: true,
                    requiresInputFile: true,
                    requiresFieldName: false,
                    requiresValue: false,
                    supportsBatch: false);
            }

            if (HasCapability(capabilities, KarProjectResourceCapability.QueryFieldValues))
            {
                yield return new KarProjectResourceAction(
                    "field-values",
                    "Field Values",
                    "Read labeled HSD root field values.",
                    KarProjectResourceCapability.QueryFieldValues,
                    "resource-fields",
                    "[resource-address] [field-name]",
                    isReadOnly: true,
                    writesOutput: false,
                    requiresInputFile: false,
                    requiresFieldName: false,
                    requiresValue: false,
                    supportsBatch: true);
            }

            if (HasCapability(capabilities, KarProjectResourceCapability.SetScalarFields))
            {
                yield return new KarProjectResourceAction(
                    "set-scalar",
                    "Set Scalar",
                    "Edit an HSD root scalar field in the output folder.",
                    KarProjectResourceCapability.SetScalarFields,
                    "set-resource-scalar",
                    "<resource-address> <field-name> <value>",
                    isReadOnly: false,
                    writesOutput: true,
                    requiresInputFile: false,
                    requiresFieldName: true,
                    requiresValue: true,
                    supportsBatch: false);
            }

            if (HasCapability(capabilities, KarProjectResourceCapability.ApplyOutput))
            {
                yield return new KarProjectResourceAction(
                    "apply-output",
                    "Apply Output",
                    "Pack modified output-side resource data back into output packages.",
                    KarProjectResourceCapability.ApplyOutput,
                    "apply-resource-outputs",
                    "[resource-address]",
                    isReadOnly: false,
                    writesOutput: true,
                    requiresInputFile: false,
                    requiresFieldName: false,
                    requiresValue: false,
                    supportsBatch: true);
            }
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
