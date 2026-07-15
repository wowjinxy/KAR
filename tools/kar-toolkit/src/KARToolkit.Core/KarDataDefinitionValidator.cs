using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public static class KarDataDefinitionValidator
    {
        public static KarDataDefinitionValidationReport ValidateBuiltIn()
        {
            return Validate(KarDataDefinitionCatalog.BuiltIn);
        }

        public static KarDataDefinitionValidationReport Validate(KarDataDefinitionRegistry registry)
        {
            if (registry == null)
                throw new ArgumentNullException(nameof(registry));

            return Validate(registry.All);
        }

        public static KarDataDefinitionValidationReport Validate(IEnumerable<KarDataDefinition> definitions)
        {
            if (definitions == null)
                throw new ArgumentNullException(nameof(definitions));

            List<KarDataDefinition> definitionList = definitions.ToList();
            List<KarDataDefinitionValidationIssue> issues = new List<KarDataDefinitionValidationIssue>();

            Dictionary<string, List<KarDataDefinition>> definitionsById = GroupDefinitionsById(definitionList);
            ValidateDefinitionIds(definitionsById, issues);
            ValidateAccessorTypeNames(definitionList, issues);

            foreach (KarDataDefinition definition in definitionList)
            {
                ValidateFieldNames(definition, issues);
                ValidateFields(definition, definitionsById, issues);
            }

            return new KarDataDefinitionValidationReport(definitionList.Count, issues);
        }

        private static Dictionary<string, List<KarDataDefinition>> GroupDefinitionsById(IEnumerable<KarDataDefinition> definitions)
        {
            Dictionary<string, List<KarDataDefinition>> definitionsById =
                new Dictionary<string, List<KarDataDefinition>>(StringComparer.OrdinalIgnoreCase);

            foreach (KarDataDefinition definition in definitions)
            {
                List<KarDataDefinition> group;
                if (!definitionsById.TryGetValue(definition.Id, out group))
                {
                    group = new List<KarDataDefinition>();
                    definitionsById.Add(definition.Id, group);
                }

                group.Add(definition);
            }

            return definitionsById;
        }

        private static void ValidateDefinitionIds(
            Dictionary<string, List<KarDataDefinition>> definitionsById,
            List<KarDataDefinitionValidationIssue> issues)
        {
            foreach (KeyValuePair<string, List<KarDataDefinition>> group in definitionsById)
            {
                if (group.Value.Count > 1)
                {
                    issues.Add(Issue(
                        KarValidationSeverity.Error,
                        "DuplicateDefinitionId",
                        "Duplicate KAR data definition id: " + group.Key,
                        group.Key));
                }
            }
        }

        private static void ValidateAccessorTypeNames(
            IEnumerable<KarDataDefinition> definitions,
            List<KarDataDefinitionValidationIssue> issues)
        {
            foreach (IGrouping<string, KarDataDefinition> group in definitions
                .Where(definition => !string.IsNullOrWhiteSpace(definition.AccessorTypeName))
                .GroupBy(definition => definition.AccessorTypeName, StringComparer.Ordinal))
            {
                if (group.Count() <= 1)
                    continue;

                string definitionIds = string.Join(", ", group.Select(definition => definition.Id));
                issues.Add(Issue(
                    KarValidationSeverity.Error,
                    "DuplicateAccessorTypeName",
                    "Duplicate KAR data definition accessor type " + group.Key + " used by: " + definitionIds,
                    group.First().Id));
            }
        }

        private static void ValidateFieldNames(
            KarDataDefinition definition,
            List<KarDataDefinitionValidationIssue> issues)
        {
            foreach (IGrouping<string, KarDataFieldDefinition> group in definition.Fields
                .GroupBy(field => field.Name, StringComparer.OrdinalIgnoreCase))
            {
                if (group.Count() <= 1)
                    continue;

                issues.Add(Issue(
                    KarValidationSeverity.Error,
                    "DuplicateFieldName",
                    definition.Id + " contains duplicate field name: " + group.Key,
                    definition.Id,
                    group.Key));
            }
        }

        private static void ValidateFields(
            KarDataDefinition definition,
            Dictionary<string, List<KarDataDefinition>> definitionsById,
            List<KarDataDefinitionValidationIssue> issues)
        {
            foreach (KarDataFieldDefinition field in definition.Fields)
            {
                if (field.Offset.HasValue && field.Offset.Value < 0)
                {
                    issues.Add(Issue(
                        KarValidationSeverity.Error,
                        "NegativeFieldOffset",
                        definition.Id + "." + field.Name + " has a negative offset.",
                        definition.Id,
                        field.Name));
                }

                ValidateReferencedDefinition(definition, field, definitionsById, issues);
                ValidateFixedSizeField(definition, field, issues);
            }
        }

        private static void ValidateReferencedDefinition(
            KarDataDefinition definition,
            KarDataFieldDefinition field,
            Dictionary<string, List<KarDataDefinition>> definitionsById,
            List<KarDataDefinitionValidationIssue> issues)
        {
            if (string.IsNullOrWhiteSpace(field.DataDefinitionId))
                return;

            if (!field.IsPointer)
            {
                issues.Add(Issue(
                    KarValidationSeverity.Error,
                    "NonPointerReferenceField",
                    definition.Id + "." + field.Name + " references nested schema " + field.DataDefinitionId + " but is not marked as a pointer.",
                    definition.Id,
                    field.Name,
                    field.DataDefinitionId));
            }

            List<KarDataDefinition> referencedDefinitions;
            if (!definitionsById.TryGetValue(field.DataDefinitionId, out referencedDefinitions))
            {
                issues.Add(Issue(
                    KarValidationSeverity.Error,
                    "MissingReferenceDataDefinition",
                    definition.Id + "." + field.Name + " references missing schema " + field.DataDefinitionId + ".",
                    definition.Id,
                    field.Name,
                    field.DataDefinitionId));
                return;
            }

            if (referencedDefinitions.Count > 1)
            {
                issues.Add(Issue(
                    KarValidationSeverity.Error,
                    "AmbiguousReferenceDataDefinition",
                    definition.Id + "." + field.Name + " references ambiguous schema " + field.DataDefinitionId + ".",
                    definition.Id,
                    field.Name,
                    field.DataDefinitionId));
            }
        }

        private static void ValidateFixedSizeField(
            KarDataDefinition definition,
            KarDataFieldDefinition field,
            List<KarDataDefinitionValidationIssue> issues)
        {
            if (!definition.Size.HasValue || !field.Offset.HasValue || field.Offset.Value < 0)
                return;

            int fieldSize;
            if (!TryGetFixedFieldSize(field, out fieldSize))
                return;

            int endOffset = field.Offset.Value + fieldSize;
            if (endOffset <= definition.Size.Value)
                return;

            issues.Add(Issue(
                KarValidationSeverity.Error,
                "FieldExceedsDefinitionSize",
                definition.Id + "." + field.Name + " ends at 0x" + endOffset.ToString("X") +
                    ", past definition size " + definition.SizeHex + ".",
                definition.Id,
                field.Name));
        }

        private static bool TryGetFixedFieldSize(KarDataFieldDefinition field, out int size)
        {
            if (field.IsPointer)
            {
                size = 4;
                return true;
            }

            KarDataScalarKind kind;
            return KarDataScalarTypes.TryResolve(field.TypeName, out kind, out size);
        }

        private static KarDataDefinitionValidationIssue Issue(
            KarValidationSeverity severity,
            string code,
            string message,
            string definitionId,
            string fieldName = null,
            string referencedDataDefinitionId = null)
        {
            return new KarDataDefinitionValidationIssue(
                severity,
                code,
                message,
                definitionId,
                fieldName,
                referencedDataDefinitionId);
        }
    }
}
