using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceDataView
    {
        internal KarProjectResourceDataView(KarProjectResourceDetail detail)
            : this(
                detail == null ? null : detail.Resource,
                detail == null ? null : detail.Fields)
        {
            Detail = detail ?? throw new ArgumentNullException(nameof(detail));
        }

        internal KarProjectResourceDataView(
            KarProjectResourceInfo resource,
            IEnumerable<KarProjectResourceFieldInfo> fields)
        {
            Resource = resource ?? throw new ArgumentNullException(nameof(resource));
            DataDefinition = Resource.Root == null ? null : Resource.Root.DataDefinition;
            Fields = (fields ?? Enumerable.Empty<KarProjectResourceFieldInfo>())
                .Select(field => new KarProjectResourceDataFieldView(
                    field.Resource,
                    field.Value,
                    field.FieldName,
                    0,
                    true))
                .ToList()
                .AsReadOnly();
            FlattenedFields = Fields
                .SelectMany(field => field.SelfAndDescendants())
                .ToList()
                .AsReadOnly();
        }

        public KarProjectResourceDetail Detail { get; }

        public bool HasDetail => Detail != null;

        public KarProjectResourceInfo Resource { get; }

        public KarResourceReference Reference => Resource.Reference;

        public KarResourceKind Kind => Resource.Kind;

        public string Address => Resource.Address;

        public string ParentAddress => Resource.ParentAddress;

        public KarDataDefinition DataDefinition { get; }

        public string DataDefinitionId => DataDefinition == null ? null : DataDefinition.Id;

        public string DisplayName => DataDefinition == null ? Resource.DisplayName : DataDefinition.DisplayName;

        public string Category => DataDefinition == null ? Resource.Category : DataDefinition.Category;

        public string Description => DataDefinition == null ? Resource.Description : DataDefinition.Description;

        public bool HasDataDefinition => DataDefinition != null;

        public IReadOnlyList<KarProjectResourceDataFieldView> Fields { get; }

        public IReadOnlyList<KarProjectResourceDataFieldView> FlattenedFields { get; }

        public int FieldCount => Fields.Count;

        public int TotalFieldCount => FlattenedFields.Count;

        public int NestedFieldCount => Math.Max(0, TotalFieldCount - FieldCount);

        public int ScalarFieldCount => FlattenedFields.Count(field => field.IsScalar);

        public int EditableScalarFieldCount => FlattenedFields.Count(field => field.CanSetScalar);

        public int PointerFieldCount => FlattenedFields.Count(field => field.IsPointer);

        public int ReferenceFieldCount => FlattenedFields.Count(field => field.HasReferenceFields || field.HasReferenceEntries);

        public int ReferenceEntryCount => FlattenedFields.Sum(field => field.ReferenceEntryCount);

        public int AvailableFieldCount => FlattenedFields.Count(field => field.IsAvailable);

        public int UnavailableFieldCount => FlattenedFields.Count(field => !field.IsAvailable);

        public int ErrorFieldCount => FlattenedFields.Count(field => field.HasError);

        public bool HasFields => FieldCount != 0;

        public bool HasNestedFields => NestedFieldCount != 0;

        public bool HasEditableScalarFields => EditableScalarFieldCount != 0;
    }
}
