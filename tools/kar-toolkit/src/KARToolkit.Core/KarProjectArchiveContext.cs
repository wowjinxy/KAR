using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectArchiveContext
    {
        internal KarProjectArchiveContext(
            KarProjectFile file,
            KarArchiveInfo archive,
            string inspectionError,
            KarProjectResourceInfo resource,
            KarProjectResourceOutputInfo output,
            IEnumerable<KarProjectResourceInfo> rootResources,
            IEnumerable<KarProjectResourceFieldInfo> fields,
            IEnumerable<KarProjectRelationship> relationships)
        {
            File = file ?? throw new ArgumentNullException(nameof(file));
            Archive = archive;
            InspectionError = inspectionError;
            Resource = resource;
            Output = output;
            RootResources = (rootResources ?? Enumerable.Empty<KarProjectResourceInfo>())
                .ToList()
                .AsReadOnly();
            Fields = (fields ?? Enumerable.Empty<KarProjectResourceFieldInfo>())
                .ToList()
                .AsReadOnly();
            Relationships = (relationships ?? Enumerable.Empty<KarProjectRelationship>())
                .ToList()
                .AsReadOnly();
        }

        public KarProjectFile File { get; }

        public KarArchiveInfo Archive { get; }

        public string InspectionError { get; }

        public KarProjectResourceInfo Resource { get; }

        public KarProjectResourceOutputInfo Output { get; }

        public IReadOnlyList<KarProjectResourceInfo> RootResources { get; }

        public IReadOnlyList<KarProjectResourceFieldInfo> Fields { get; }

        public IReadOnlyList<KarProjectRelationship> Relationships { get; }

        public string RelativePath => File.RelativePath;

        public string ReadPath => File.ReadPath;

        public KarFileKind Kind => File.Kind;

        public string KindId => File.KindId;

        public string Category => File.Category;

        public string DisplayName => File.DisplayName;

        public IReadOnlyList<KarArchiveRootInfo> Roots => Archive == null ? Array.Empty<KarArchiveRootInfo>() : Archive.Roots;

        public IReadOnlyList<KarArchiveRootInfo> KnownRoots => Archive == null ? Array.Empty<KarArchiveRootInfo>() : Archive.KnownRoots;

        public IReadOnlyList<KarArchiveRootInfo> UnknownRoots => Archive == null ? Array.Empty<KarArchiveRootInfo>() : Archive.UnknownRoots;

        public IReadOnlyList<KarRootDefinition> MissingRequiredRoots => Archive == null ? Array.Empty<KarRootDefinition>() : Archive.MissingRequiredRoots;

        public int RootCount => Roots.Count;

        public int KnownRootCount => KnownRoots.Count;

        public int UnknownRootCount => UnknownRoots.Count;

        public int MissingRequiredRootCount => MissingRequiredRoots.Count;

        public int RootResourceCount => RootResources.Count;

        public int ResourceCount => (Resource == null ? 0 : 1) + RootResourceCount;

        public int FieldCount => Fields.Count;

        public int RelationshipCount => Relationships.Count;

        public bool HasInspection => Archive != null;

        public bool HasInspectionError => !string.IsNullOrEmpty(InspectionError);

        public bool HasMissingRequiredRoots => MissingRequiredRootCount != 0;

        public bool HasRootResources => RootResourceCount != 0;

        public bool HasFields => FieldCount != 0;

        public bool HasRelationships => RelationshipCount != 0;

        public bool HasOutputInfo => Output != null;

        public bool HasOutput => Output != null && Output.HasOutput;

        public bool HasModifiedOutput => Output != null && Output.IsModified;

        public bool HasUnchangedOutput => Output != null && Output.IsUnchanged;

        public KarProjectResourceOutputKind? OutputKind => Output == null ? (KarProjectResourceOutputKind?)null : Output.OutputKind;

        public KarProjectResourceOutputStatus? OutputStatus => Output == null ? (KarProjectResourceOutputStatus?)null : Output.Status;

        public string OutputRelativePath => Output == null ? null : Output.OutputRelativePath;

        public string OutputPath => Output == null ? null : Output.OutputPath;
    }
}
