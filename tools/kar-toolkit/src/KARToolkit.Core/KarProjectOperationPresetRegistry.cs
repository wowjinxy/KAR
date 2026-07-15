using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectOperationPresetRegistry
    {
        public static KarProjectOperationPresetRegistry Default { get; } =
            new KarProjectOperationPresetRegistry(CreateDefaultDefinitions());

        private readonly IReadOnlyList<KarProjectOperationPresetDefinition> _definitions;
        private readonly Dictionary<string, KarProjectOperationPresetDefinition> _definitionsById;

        public KarProjectOperationPresetRegistry(IEnumerable<KarProjectOperationPresetDefinition> definitions)
        {
            if (definitions == null)
                throw new ArgumentNullException(nameof(definitions));

            _definitions = definitions
                .ToList()
                .AsReadOnly();
            _definitionsById = new Dictionary<string, KarProjectOperationPresetDefinition>(StringComparer.OrdinalIgnoreCase);

            foreach (KarProjectOperationPresetDefinition definition in _definitions)
            {
                if (definition == null)
                    throw new ArgumentException("Operation preset definitions cannot contain null entries.", nameof(definitions));
                if (_definitionsById.ContainsKey(definition.Id))
                    throw new ArgumentException("Duplicate operation preset id: " + definition.Id, nameof(definitions));

                _definitionsById.Add(definition.Id, definition);
            }
        }

        public IReadOnlyList<KarProjectOperationPresetDefinition> Definitions => _definitions;

        public KarProjectOperationPresetDefinition FindDefinition(string id)
        {
            KarProjectOperationPresetDefinition definition;
            if (!TryFindDefinition(id, out definition))
                throw new KeyNotFoundException("KAR operation preset definition was not found: " + id);

            return definition;
        }

        public bool TryFindDefinition(string id, out KarProjectOperationPresetDefinition definition)
        {
            definition = null;
            return !string.IsNullOrWhiteSpace(id) && _definitionsById.TryGetValue(id, out definition);
        }

        private static IReadOnlyList<KarProjectOperationPresetDefinition> CreateDefaultDefinitions()
        {
            return new[]
            {
                Define(
                    "script-byte-status",
                    "script-tables",
                    "Script Byte Status",
                    "Report active byte and output dump status for loose and packaged script tables.",
                    "byte-status",
                    null,
                    isReadOnly: true,
                    writesOutput: false,
                    supportsBatch: true,
                    requiresInputFile: false,
                    requiresFieldName: false,
                    requiresValue: false,
                    canRun: true,
                    wouldWriteOutput: false,
                    hasModifiedOutputs: null),
                Define(
                    "dump-script-bytes",
                    "script-tables",
                    "Dump Script Bytes",
                    "Write raw bytes for loose and packaged script tables under resource-bytes/ in the output folder.",
                    "dump-bytes",
                    null,
                    isReadOnly: false,
                    writesOutput: true,
                    supportsBatch: true,
                    requiresInputFile: false,
                    requiresFieldName: false,
                    requiresValue: false,
                    canRun: true,
                    wouldWriteOutput: true,
                    hasModifiedOutputs: null),
                Define(
                    "dump-all-resource-bytes",
                    "resources",
                    "Dump All Resource Bytes",
                    "Write raw bytes for every readable project resource under resource-bytes/ in the output folder.",
                    "dump-bytes",
                    null,
                    isReadOnly: false,
                    writesOutput: true,
                    supportsBatch: true,
                    requiresInputFile: false,
                    requiresFieldName: false,
                    requiresValue: false,
                    canRun: true,
                    wouldWriteOutput: true,
                    hasModifiedOutputs: null),
                Define(
                    "resource-output-status",
                    "resources",
                    "Resource Output Status",
                    "Report output-side status for resources that can be staged or applied.",
                    "output-status",
                    null,
                    isReadOnly: true,
                    writesOutput: false,
                    supportsBatch: true,
                    requiresInputFile: false,
                    requiresFieldName: false,
                    requiresValue: false,
                    canRun: true,
                    wouldWriteOutput: false,
                    hasModifiedOutputs: null),
                Define(
                    "root-field-values",
                    "resources",
                    "Root Field Values",
                    "Read labeled field values from HSD root resources with known schemas.",
                    "field-values",
                    KarResourceKind.HsdRoot,
                    isReadOnly: true,
                    writesOutput: false,
                    supportsBatch: true,
                    requiresInputFile: false,
                    requiresFieldName: false,
                    requiresValue: false,
                    canRun: true,
                    wouldWriteOutput: false,
                    hasModifiedOutputs: null),
                Define(
                    "apply-modified-resource-outputs",
                    "mod-output",
                    "Apply Modified Resource Outputs",
                    "Pack modified output-side sidecars back into output package copies.",
                    "apply-output",
                    null,
                    isReadOnly: false,
                    writesOutput: true,
                    supportsBatch: true,
                    requiresInputFile: false,
                    requiresFieldName: false,
                    requiresValue: false,
                    canRun: true,
                    wouldWriteOutput: true,
                    hasModifiedOutputs: true),
            };
        }

        private static KarProjectOperationPresetDefinition Define(
            string id,
            string domainId,
            string displayName,
            string description,
            string actionId,
            KarResourceKind? resourceKind,
            bool isReadOnly,
            bool writesOutput,
            bool supportsBatch,
            bool requiresInputFile,
            bool requiresFieldName,
            bool requiresValue,
            bool? canRun,
            bool? wouldWriteOutput,
            bool? hasModifiedOutputs)
        {
            return new KarProjectOperationPresetDefinition(
                id,
                domainId,
                displayName,
                description,
                actionId,
                resourceKind,
                isReadOnly,
                writesOutput,
                supportsBatch,
                requiresInputFile,
                requiresFieldName,
                requiresValue,
                canRun,
                wouldWriteOutput,
                hasModifiedOutputs);
        }
    }
}
