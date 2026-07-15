using System;
using System.Collections.Generic;

namespace KARToolkit.Core
{
    public sealed class KarProjectResolvedResourceDetail
    {
        internal KarProjectResolvedResourceDetail(
            KarProjectResolvedResource resolved,
            KarProjectResourceDetail detail)
        {
            Resolved = resolved ?? throw new ArgumentNullException(nameof(resolved));
            Detail = detail ?? throw new ArgumentNullException(nameof(detail));
        }

        public KarProjectResolvedResource Resolved { get; }

        public KarProjectResourceDetail Detail { get; }

        public KarProjectResourceInfo Resource => Resolved.Resource;

        public KarResourceReference Reference => Resolved.Reference;

        public KarResourceKind Kind => Resolved.Kind;

        public string Address => Resolved.Address;

        public string ParentAddress => Resolved.ParentAddress;

        public KarDataDefinition DataDefinition => Resolved.DataDefinition;

        public string DataDefinitionId => Resolved.DataDefinitionId;

        public bool HasDataDefinition => Resolved.HasDataDefinition;

        public KarProjectResourceOutputInfo Output => Detail.Output;

        public bool HasOutputInfo => Detail.HasOutputInfo;

        public IReadOnlyList<KarProjectResourceInfo> ChildResources => Detail.ChildResources;

        public int ChildResourceCount => Detail.ChildResourceCount;

        public bool HasChildResources => Detail.HasChildResources;

        public IReadOnlyList<KarProjectResourceFieldInfo> Fields => Detail.Fields;

        public int FieldCount => Detail.FieldCount;

        public bool HasFields => Detail.HasFields;

        public IReadOnlyList<KarProjectRelationship> Relationships => Detail.Relationships;

        public int RelationshipCount => Detail.RelationshipCount;

        public bool HasRelationships => Detail.HasRelationships;
    }
}
