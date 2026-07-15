using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceDataFieldView
    {
        internal KarProjectResourceDataFieldView(
            KarProjectResourceInfo resource,
            KarDataFieldValue value,
            string fieldPath,
            int depth,
            bool isTopLevel)
        {
            Resource = resource ?? throw new ArgumentNullException(nameof(resource));
            Value = value ?? throw new ArgumentNullException(nameof(value));
            FieldPath = string.IsNullOrWhiteSpace(fieldPath) ? value.Field.Name : fieldPath;
            Depth = depth;
            IsTopLevel = isTopLevel;
            ReferenceFields = value.ReferenceFieldValues
                .Select(child => new KarProjectResourceDataFieldView(
                    resource,
                    child,
                    FieldPath + "." + child.Field.Name,
                    depth + 1,
                    false))
                .ToList()
                .AsReadOnly();
            ReferenceEntries = value.ReferenceEntries
                .Select(entry => new KarProjectResourceDataEntryView(resource, FieldPath, entry, depth))
                .ToList()
                .AsReadOnly();
            ScalarEdit = CanSetScalar ? new KarProjectResourceDataFieldEditInfo(this) : null;
        }

        public KarProjectResourceInfo Resource { get; }

        public KarResourceReference Reference => Resource.Reference;

        public string Address => Resource.Address;

        public KarDataFieldValue Value { get; }

        public KarDataFieldDefinition Field => Value.Field;

        public string FieldName => Field.Name;

        public string FieldPath { get; }

        public int Depth { get; }

        public bool IsTopLevel { get; }

        public int? Offset => Field.Offset;

        public string OffsetHex => Field.OffsetHex;

        public string TypeName => Field.TypeName;

        public string Description => Field.Description;

        public bool IsPointer => Field.IsPointer;

        public bool IsScalar => Field.IsScalar;

        public bool IsFloatScalar => Field.IsFloatScalar;

        public string DataDefinitionId => Field.DataDefinitionId;

        public bool IsAvailable => Value.IsAvailable;

        public string ValueKind => Value.ValueKind;

        public string DisplayValue => Value.DisplayValue;

        public long? SignedValue => Value.SignedValue;

        public ulong? UnsignedValue => Value.UnsignedValue;

        public double? FloatValue => Value.FloatValue;

        public bool? HasReference => Value.HasReference;

        public int? ReferenceLength => Value.ReferenceLength;

        public string ReferenceLengthHex => Value.ReferenceLengthHex;

        public KarDataDefinition ReferenceDataDefinition => Value.ReferenceDataDefinition;

        public string ReferenceDataDefinitionId => Value.ReferenceDataDefinitionId;

        public bool HasReferenceDataDefinition => Value.HasReferenceDataDefinition;

        public IReadOnlyList<KarProjectResourceDataFieldView> ReferenceFields { get; }

        public int ReferenceFieldCount => ReferenceFields.Count;

        public bool HasReferenceFields => ReferenceFieldCount != 0;

        public IReadOnlyList<KarProjectResourceDataEntryView> ReferenceEntries { get; }

        public int ReferenceEntryCount => ReferenceEntries.Count;

        public int? ReferenceEntryTotalCount => Value.ReferenceEntryTotalCount;

        public bool HasReferenceEntries => ReferenceEntryCount != 0;

        public bool HasReferenceEntryOverflow => Value.HasReferenceEntryOverflow;

        public string Error => Value.Error;

        public bool HasError => !string.IsNullOrEmpty(Error);

        public bool CanSetScalar => IsTopLevel && Resource.CanSetScalarFields && IsScalar && IsAvailable;

        public KarProjectResourceDataFieldEditInfo ScalarEdit { get; }

        public bool HasScalarEdit => ScalarEdit != null;

        public int TotalFieldCount => 1 +
            ReferenceFields.Sum(field => field.TotalFieldCount) +
            ReferenceEntries.Sum(entry => entry.TotalFieldCount);

        public IEnumerable<KarProjectResourceDataFieldView> SelfAndDescendants()
        {
            yield return this;

            foreach (KarProjectResourceDataFieldView field in ReferenceFields)
            {
                foreach (KarProjectResourceDataFieldView descendant in field.SelfAndDescendants())
                    yield return descendant;
            }

            foreach (KarProjectResourceDataEntryView entry in ReferenceEntries)
            {
                foreach (KarProjectResourceDataFieldView field in entry.Fields)
                {
                    foreach (KarProjectResourceDataFieldView descendant in field.SelfAndDescendants())
                        yield return descendant;
                }
            }
        }
    }
}
