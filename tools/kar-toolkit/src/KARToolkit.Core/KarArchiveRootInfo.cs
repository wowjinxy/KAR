using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarArchiveRootInfo
    {
        internal KarArchiveRootInfo(
            string name,
            string accessorTypeName,
            KarRootDefinition definition,
            KarDataDefinition dataDefinition,
            IEnumerable<KarDataFieldValue> fieldValues)
        {
            Name = name;
            AccessorTypeName = accessorTypeName;
            Definition = definition;
            DataDefinition = dataDefinition;
            FieldValues = (fieldValues ?? Enumerable.Empty<KarDataFieldValue>())
                .ToList()
                .AsReadOnly();
        }

        public string Name { get; }

        public string AccessorTypeName { get; }

        public KarRootDefinition Definition { get; }

        public IReadOnlyList<KarDataFieldValue> FieldValues { get; }

        public bool HasFieldValues => FieldValues.Count != 0;

        public bool IsKnown => Definition != null;

        public bool HasDataDefinition => DataDefinition != null;

        public string ExpectedAccessorTypeName => Definition == null ? null : Definition.AccessorTypeName;

        public string DataDefinitionId => DataDefinition == null ? null : DataDefinition.Id;

        public KarDataDefinition DataDefinition { get; }

        public string DisplayAccessorTypeName
        {
            get
            {
                if (!string.IsNullOrEmpty(ExpectedAccessorTypeName))
                    return ExpectedAccessorTypeName;

                return AccessorTypeName;
            }
        }

        public KarDataFieldValue GetFieldValue(string fieldName)
        {
            KarDataFieldValue value;
            if (!TryGetFieldValue(fieldName, out value))
                throw new KeyNotFoundException("KAR data field value was not found: " + fieldName);

            return value;
        }

        public bool TryGetFieldValue(string fieldName, out KarDataFieldValue value)
        {
            value = null;
            if (string.IsNullOrWhiteSpace(fieldName))
                return false;

            value = FieldValues.FirstOrDefault(candidate =>
                string.Equals(candidate.Field.Name, fieldName, StringComparison.OrdinalIgnoreCase));
            return value != null;
        }

        public bool MatchesDataDefinition(string idOrAccessorTypeName)
        {
            if (string.IsNullOrWhiteSpace(idOrAccessorTypeName) || DataDefinition == null)
                return false;

            return string.Equals(DataDefinition.Id, idOrAccessorTypeName, StringComparison.OrdinalIgnoreCase) ||
                string.Equals(DataDefinition.AccessorTypeName, idOrAccessorTypeName, StringComparison.Ordinal);
        }
    }
}
