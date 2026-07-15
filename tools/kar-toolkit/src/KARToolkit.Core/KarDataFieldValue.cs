using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarDataFieldValue
    {
        internal KarDataFieldValue(
            KarDataFieldDefinition field,
            bool isAvailable,
            string valueKind,
            string displayValue,
            long? signedValue = null,
            ulong? unsignedValue = null,
            double? floatValue = null,
            bool? hasReference = null,
            int? referenceLength = null,
            KarDataDefinition referenceDataDefinition = null,
            IEnumerable<KarDataFieldValue> referenceFieldValues = null,
            IEnumerable<KarDataReferenceEntry> referenceEntries = null,
            int? referenceEntryTotalCount = null,
            string error = null)
        {
            Field = field ?? throw new ArgumentNullException(nameof(field));
            IsAvailable = isAvailable;
            ValueKind = valueKind;
            DisplayValue = displayValue;
            SignedValue = signedValue;
            UnsignedValue = unsignedValue;
            FloatValue = floatValue;
            HasReference = hasReference;
            ReferenceLength = referenceLength;
            ReferenceDataDefinition = referenceDataDefinition;
            ReferenceFieldValues = (referenceFieldValues ?? Enumerable.Empty<KarDataFieldValue>())
                .ToList()
                .AsReadOnly();
            ReferenceEntries = (referenceEntries ?? Enumerable.Empty<KarDataReferenceEntry>())
                .ToList()
                .AsReadOnly();
            ReferenceEntryTotalCount = referenceEntryTotalCount;
            Error = error;
        }

        public KarDataFieldDefinition Field { get; }

        public bool IsAvailable { get; }

        public string ValueKind { get; }

        public string DisplayValue { get; }

        public long? SignedValue { get; }

        public ulong? UnsignedValue { get; }

        public double? FloatValue { get; }

        public bool? HasReference { get; }

        public int? ReferenceLength { get; }

        public string ReferenceLengthHex => ReferenceLength.HasValue ? "0x" + ReferenceLength.Value.ToString("X") : null;

        public KarDataDefinition ReferenceDataDefinition { get; }

        public string ReferenceDataDefinitionId => ReferenceDataDefinition == null ? null : ReferenceDataDefinition.Id;

        public IReadOnlyList<KarDataFieldValue> ReferenceFieldValues { get; }

        public IReadOnlyList<KarDataReferenceEntry> ReferenceEntries { get; }

        public int ReferenceEntryCount => ReferenceEntries.Count;

        public int? ReferenceEntryTotalCount { get; }

        public bool HasReferenceDataDefinition => ReferenceDataDefinition != null;

        public bool HasReferenceFieldValues => ReferenceFieldValues.Count != 0;

        public bool HasReferenceEntries => ReferenceEntries.Count != 0;

        public bool HasReferenceEntryOverflow => ReferenceEntryTotalCount.HasValue && ReferenceEntryTotalCount.Value > ReferenceEntryCount;

        public string Error { get; }

        public KarDataReferenceEntry GetReferenceEntry(int index)
        {
            KarDataReferenceEntry entry;
            if (!TryGetReferenceEntry(index, out entry))
                throw new KeyNotFoundException("KAR referenced data entry was not found: " + index);

            return entry;
        }

        public bool TryGetReferenceEntry(int index, out KarDataReferenceEntry entry)
        {
            entry = ReferenceEntries.FirstOrDefault(candidate => candidate.Index == index);
            return entry != null;
        }

        public KarDataFieldValue GetReferenceFieldValue(string fieldName)
        {
            KarDataFieldValue value;
            if (!TryGetReferenceFieldValue(fieldName, out value))
                throw new KeyNotFoundException("KAR referenced data field value was not found: " + fieldName);

            return value;
        }

        public bool TryGetReferenceFieldValue(string fieldName, out KarDataFieldValue value)
        {
            value = null;
            if (string.IsNullOrWhiteSpace(fieldName))
                return false;

            value = ReferenceFieldValues.FirstOrDefault(candidate =>
                string.Equals(candidate.Field.Name, fieldName, StringComparison.OrdinalIgnoreCase));
            return value != null;
        }
    }
}
