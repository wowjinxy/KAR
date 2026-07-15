using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectFieldDistinctValue
    {
        internal KarProjectFieldDistinctValue(KarDataFieldValue value, IEnumerable<KarProjectFieldInfo> fields)
        {
            Value = value ?? throw new ArgumentNullException(nameof(value));
            Fields = (fields ?? throw new ArgumentNullException(nameof(fields)))
                .ToList()
                .AsReadOnly();
            Files = Fields
                .Select(field => field.File)
                .GroupBy(file => file.RelativePath, StringComparer.OrdinalIgnoreCase)
                .Select(group => group.First())
                .OrderBy(file => file.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public KarDataFieldValue Value { get; }

        public string ValueKind => Value.ValueKind;

        public string DisplayValue => Value.DisplayValue;

        public long? SignedValue => Value.SignedValue;

        public ulong? UnsignedValue => Value.UnsignedValue;

        public double? FloatValue => Value.FloatValue;

        public bool? HasReference => Value.HasReference;

        public int? ReferenceLength => Value.ReferenceLength;

        public string ReferenceLengthHex => Value.ReferenceLengthHex;

        public string ReferenceDataDefinitionId => Value.ReferenceDataDefinitionId;

        public string Error => Value.Error;

        public IReadOnlyList<KarProjectFieldInfo> Fields { get; }

        public IReadOnlyList<KarProjectFile> Files { get; }

        public int Count => Fields.Count;

        public int FileCount => Files.Count;
    }
}
