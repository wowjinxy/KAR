using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceActionRegistry
    {
        public static IReadOnlyList<KarProjectResourceActionDefinition> BuiltInDefinitions { get; } =
            CreateDefaultDefinitions();

        public static KarProjectResourceActionRegistry Default { get; } =
            new KarProjectResourceActionRegistry(BuiltInDefinitions);

        private readonly IReadOnlyList<KarProjectResourceActionDefinition> _definitions;
        private readonly Dictionary<string, KarProjectResourceActionDefinition> _definitionsById;

        public KarProjectResourceActionRegistry(IEnumerable<KarProjectResourceActionDefinition> definitions)
        {
            if (definitions == null)
                throw new ArgumentNullException(nameof(definitions));

            _definitions = definitions
                .ToList()
                .AsReadOnly();
            _definitionsById = new Dictionary<string, KarProjectResourceActionDefinition>(StringComparer.OrdinalIgnoreCase);

            foreach (KarProjectResourceActionDefinition definition in _definitions)
            {
                if (definition == null)
                    throw new ArgumentException("Resource action definitions cannot contain null entries.", nameof(definitions));
                if (_definitionsById.ContainsKey(definition.Id))
                    throw new ArgumentException("Duplicate resource action id: " + definition.Id, nameof(definitions));

                _definitionsById.Add(definition.Id, definition);
            }
        }

        public IReadOnlyList<KarProjectResourceActionDefinition> Definitions => _definitions;

        public KarProjectResourceActionDefinition FindDefinition(string id)
        {
            KarProjectResourceActionDefinition definition;
            if (!TryFindDefinition(id, out definition))
                throw new KeyNotFoundException("KAR resource action definition was not found: " + id);

            return definition;
        }

        public bool TryFindDefinition(string id, out KarProjectResourceActionDefinition definition)
        {
            definition = null;
            return !string.IsNullOrWhiteSpace(id) && _definitionsById.TryGetValue(id, out definition);
        }

        public IReadOnlyList<KarProjectResourceActionDefinition> QueryDefinitions(KarProjectResourceCapability capabilities)
        {
            return _definitions
                .Where(definition => HasCapability(capabilities, definition.Capability))
                .ToList()
                .AsReadOnly();
        }

        public IReadOnlyList<KarProjectResourceAction> CreateActions(KarProjectResourceCapability capabilities)
        {
            return QueryDefinitions(capabilities)
                .Select(definition => definition.CreateAction())
                .ToList()
                .AsReadOnly();
        }

        private static IReadOnlyList<KarProjectResourceActionDefinition> CreateDefaultDefinitions()
        {
            return new[]
            {
                Define(
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
                    supportsBatch: true,
                    planStateKind: KarProjectResourceActionPlanStateKind.Output,
                    writePolicy: KarProjectResourceActionWritePolicy.None),
                Define(
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
                    supportsBatch: true,
                    planStateKind: KarProjectResourceActionPlanStateKind.Bytes,
                    writePolicy: KarProjectResourceActionWritePolicy.None),
                Define(
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
                    supportsBatch: true,
                    planStateKind: KarProjectResourceActionPlanStateKind.Bytes,
                    writePolicy: KarProjectResourceActionWritePolicy.MissingByteDump),
                Define(
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
                    supportsBatch: false,
                    planStateKind: KarProjectResourceActionPlanStateKind.Output,
                    writePolicy: KarProjectResourceActionWritePolicy.MissingResourceOutput),
                Define(
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
                    supportsBatch: false,
                    planStateKind: KarProjectResourceActionPlanStateKind.Output,
                    writePolicy: KarProjectResourceActionWritePolicy.Always),
                Define(
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
                    supportsBatch: true,
                    planStateKind: KarProjectResourceActionPlanStateKind.None,
                    writePolicy: KarProjectResourceActionWritePolicy.None),
                Define(
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
                    supportsBatch: false,
                    planStateKind: KarProjectResourceActionPlanStateKind.Output,
                    writePolicy: KarProjectResourceActionWritePolicy.Always),
                Define(
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
                    supportsBatch: true,
                    planStateKind: KarProjectResourceActionPlanStateKind.Output,
                    writePolicy: KarProjectResourceActionWritePolicy.ModifiedResourceOutput),
            };
        }

        private static KarProjectResourceActionDefinition Define(
            string id,
            string displayName,
            string description,
            KarProjectResourceCapability capability,
            string command,
            string argumentHint,
            bool isReadOnly,
            bool writesOutput,
            bool requiresInputFile,
            bool requiresFieldName,
            bool requiresValue,
            bool supportsBatch,
            KarProjectResourceActionPlanStateKind planStateKind,
            KarProjectResourceActionWritePolicy writePolicy)
        {
            return new KarProjectResourceActionDefinition(
                id,
                displayName,
                description,
                capability,
                command,
                argumentHint,
                isReadOnly,
                writesOutput,
                requiresInputFile,
                requiresFieldName,
                requiresValue,
                supportsBatch,
                planStateKind,
                writePolicy);
        }

        private static bool HasCapability(KarProjectResourceCapability capabilities, KarProjectResourceCapability capability)
        {
            return capability != KarProjectResourceCapability.None &&
                (capabilities & capability) == capability;
        }
    }
}
