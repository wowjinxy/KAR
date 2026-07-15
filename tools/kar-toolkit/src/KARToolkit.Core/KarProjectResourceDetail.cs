using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceDetail
    {
        internal KarProjectResourceDetail(
            KarProjectResourceInfo resource,
            KarProjectResourceOutputInfo output,
            KarProjectResourceByteInfo byteInfo,
            IEnumerable<KarProjectResourceInfo> childResources,
            IEnumerable<KarProjectResourceFieldInfo> fields,
            IEnumerable<KarProjectRelationship> relationships)
        {
            Resource = resource ?? throw new ArgumentNullException(nameof(resource));
            Output = output;
            ByteInfo = byteInfo;
            ChildResources = (childResources ?? Enumerable.Empty<KarProjectResourceInfo>())
                .ToList()
                .AsReadOnly();
            Fields = (fields ?? Enumerable.Empty<KarProjectResourceFieldInfo>())
                .ToList()
                .AsReadOnly();
            Relationships = (relationships ?? Enumerable.Empty<KarProjectRelationship>())
                .ToList()
                .AsReadOnly();
            DataView = new KarProjectResourceDataView(this);
        }

        public KarProjectResourceInfo Resource { get; }

        public IReadOnlyList<KarProjectResourceAction> Actions => Resource.Actions;

        public int ActionCount => Resource.ActionCount;

        public KarResourceReference Reference => Resource.Reference;

        public KarResourceKind Kind => Resource.Kind;

        public string Address => Resource.Address;

        public string ParentAddress => Resource.ParentAddress;

        public KarProjectResourceOutputInfo Output { get; }

        public bool HasOutputInfo => Output != null;

        public KarProjectResourceByteInfo ByteInfo { get; }

        public bool HasByteInfo => ByteInfo != null;

        public IReadOnlyList<KarProjectResourceInfo> ChildResources { get; }

        public int ChildResourceCount => ChildResources.Count;

        public bool HasChildResources => ChildResourceCount != 0;

        public IReadOnlyList<KarProjectResourceFieldInfo> Fields { get; }

        public int FieldCount => Fields.Count;

        public bool HasFields => FieldCount != 0;

        public KarProjectResourceDataView DataView { get; }

        public bool HasDataView => DataView != null;

        public IReadOnlyList<KarProjectRelationship> Relationships { get; }

        public int RelationshipCount => Relationships.Count;

        public bool HasRelationships => RelationshipCount != 0;

        public KarProjectResourceDetailSummaryContract CreateContract()
        {
            return KarProjectResourceDetailSummaryContract.Create(this);
        }
    }
}
