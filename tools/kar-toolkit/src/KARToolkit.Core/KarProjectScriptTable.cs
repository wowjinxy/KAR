using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectScriptTable
    {
        internal KarProjectScriptTable(
            KarProjectResourceInfo resource,
            KarScriptTableInfo tableInfo,
            KarProjectRelationship relationship)
        {
            Resource = resource ?? throw new ArgumentNullException(nameof(resource));
            TableInfo = tableInfo ?? throw new ArgumentNullException(nameof(tableInfo));
            Relationship = relationship;
        }

        public KarProjectResourceInfo Resource { get; }

        public KarScriptTableInfo TableInfo { get; }

        public KarProjectRelationship Relationship { get; }

        public KarResourceReference Reference => Resource.Reference;

        public string Address => Resource.Address;

        public string ParentAddress => Resource.ParentAddress;

        public string RelativePath => Resource.RelativePath;

        public string Name => TableInfo.Name;

        public string Role => TableInfo.Role;

        public string Category => TableInfo.Category;

        public string Description => TableInfo.Description;

        public KarProjectFile File => Resource.File;

        public KarProjectA2DEntryInfo A2DEntry => Resource.A2DEntry;

        public KarProjectFile PackageFile => A2DEntry == null ? null : A2DEntry.PackageFile;

        public string PackageRelativePath => A2DEntry == null ? null : A2DEntry.PackageRelativePath;

        public int? PackageEntryIndex => A2DEntry == null ? (int?)null : A2DEntry.Index;

        public int? PackageEntryOffset => A2DEntry == null ? (int?)null : A2DEntry.DataOffset;

        public string PackageEntryOffsetHex => A2DEntry == null ? null : A2DEntry.DataOffsetHex;

        public int? PackageEntrySize => A2DEntry == null ? (int?)null : A2DEntry.Size;

        public string PackageEntrySizeHex => A2DEntry == null ? null : A2DEntry.SizeHex;

        public bool IsLooseFile => Resource.Kind == KarResourceKind.File;

        public bool IsPackageEntry => Resource.Kind == KarResourceKind.A2DEntry;
    }
}
