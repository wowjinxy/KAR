using System;
using System.Collections.Generic;

namespace KARToolkit.Core
{
    public sealed class KarProjectScriptTableContext
    {
        internal KarProjectScriptTableContext(
            KarProjectScriptTable table,
            KarProjectResourceOutputInfo output,
            IReadOnlyList<KarProjectRelationship> relationships)
        {
            Table = table ?? throw new ArgumentNullException(nameof(table));
            Output = output;
            Relationships = relationships ?? throw new ArgumentNullException(nameof(relationships));
        }

        public KarProjectScriptTable Table { get; }

        public KarProjectResourceOutputInfo Output { get; }

        public IReadOnlyList<KarProjectRelationship> Relationships { get; }

        public KarProjectResourceInfo Resource => Table.Resource;

        public KarResourceReference Reference => Table.Reference;

        public string Address => Table.Address;

        public string ParentAddress => Table.ParentAddress;

        public string RelativePath => Table.RelativePath;

        public string Name => Table.Name;

        public string Role => Table.Role;

        public string Category => Table.Category;

        public string Description => Table.Description;

        public bool IsLooseFile => Table.IsLooseFile;

        public bool IsPackageEntry => Table.IsPackageEntry;

        public KarProjectFile File => Table.File;

        public KarProjectFile PackageFile => Table.PackageFile;

        public string PackageRelativePath => Table.PackageRelativePath;

        public int? PackageEntryIndex => Table.PackageEntryIndex;

        public int? PackageEntryOffset => Table.PackageEntryOffset;

        public string PackageEntryOffsetHex => Table.PackageEntryOffsetHex;

        public int? PackageEntrySize => Table.PackageEntrySize;

        public string PackageEntrySizeHex => Table.PackageEntrySizeHex;

        public KarProjectRelationship PrimaryRelationship => Table.Relationship;

        public int RelationshipCount => Relationships.Count;

        public bool HasRelationships => Relationships.Count != 0;

        public bool HasOutput => Output != null && Output.HasOutput;

        public bool HasModifiedOutput => Output != null && Output.IsModified;

        public bool HasUnchangedOutput => Output != null && Output.IsUnchanged;

        public KarProjectResourceOutputKind? OutputKind => Output == null ? (KarProjectResourceOutputKind?)null : Output.OutputKind;

        public KarProjectResourceOutputStatus? OutputStatus => Output == null ? (KarProjectResourceOutputStatus?)null : Output.Status;

        public string OutputRelativePath => Output == null ? null : Output.OutputRelativePath;

        public string OutputPath => Output == null ? null : Output.OutputPath;

        public KarProjectScriptTableContextSummaryContract CreateContract()
        {
            return KarProjectScriptTableContextSummaryContract.Create(this);
        }
    }
}
