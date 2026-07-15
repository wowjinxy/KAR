using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarDataReferenceEntry
    {
        internal KarDataReferenceEntry(
            int index,
            int offset,
            IEnumerable<KarDataFieldValue> fieldValues)
        {
            if (index < 0)
                throw new ArgumentOutOfRangeException(nameof(index), "Entry index cannot be negative.");
            if (offset < 0)
                throw new ArgumentOutOfRangeException(nameof(offset), "Entry offset cannot be negative.");

            Index = index;
            Offset = offset;
            FieldValues = (fieldValues ?? Enumerable.Empty<KarDataFieldValue>())
                .ToList()
                .AsReadOnly();
        }

        public int Index { get; }

        public int Offset { get; }

        public string OffsetHex => "0x" + Offset.ToString("X");

        public IReadOnlyList<KarDataFieldValue> FieldValues { get; }

        public bool HasFieldValues => FieldValues.Count != 0;

        public KarDataFieldValue GetFieldValue(string fieldName)
        {
            KarDataFieldValue value;
            if (!TryGetFieldValue(fieldName, out value))
                throw new KeyNotFoundException("KAR reference entry field value was not found: " + fieldName);

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
    }
}
