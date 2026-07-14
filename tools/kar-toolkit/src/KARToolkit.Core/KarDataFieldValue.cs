using System;

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

        public string Error { get; }
    }
}
