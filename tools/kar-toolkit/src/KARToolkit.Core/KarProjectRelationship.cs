namespace KARToolkit.Core
{
    public sealed class KarProjectRelationship
    {
        internal KarProjectRelationship(
            string kind,
            string role,
            string category,
            string description,
            KarMapBundle map,
            KarProjectFile file,
            KarProjectFile packageFile,
            string packageEntryName,
            int? packageEntryIndex,
            int? packageEntryOffset,
            int? packageEntrySize)
        {
            Kind = kind;
            Role = role;
            Category = category;
            Description = description;
            Map = map;
            File = file;
            PackageFile = packageFile;
            PackageEntryName = packageEntryName;
            PackageEntryIndex = packageEntryIndex;
            PackageEntryOffset = packageEntryOffset;
            PackageEntrySize = packageEntrySize;
        }

        public string Kind { get; }

        public string Role { get; }

        public string Category { get; }

        public string Description { get; }

        public KarMapBundle Map { get; }

        public string MapName => Map == null ? null : Map.Name;

        public KarProjectFile File { get; }

        public KarProjectFile PackageFile { get; }

        public string PackageEntryName { get; }

        public int? PackageEntryIndex { get; }

        public int? PackageEntryOffset { get; }

        public string PackageEntryOffsetHex => PackageEntryOffset.HasValue ? "0x" + PackageEntryOffset.Value.ToString("X") : null;

        public int? PackageEntrySize { get; }

        public string PackageEntrySizeHex => PackageEntrySize.HasValue ? "0x" + PackageEntrySize.Value.ToString("X") : null;

        public bool IsMapScoped => Map != null;

        public bool IsPackageEntry => PackageFile != null && PackageEntryName != null;

        public string RelativePath
        {
            get
            {
                if (File != null)
                    return File.RelativePath;

                if (IsPackageEntry)
                    return PackageFile.RelativePath + "#" + PackageEntryName;

                return null;
            }
        }

        public string DisplayName
        {
            get
            {
                if (!string.IsNullOrEmpty(PackageEntryName))
                    return PackageEntryName;

                return File == null ? Role : File.DisplayName;
            }
        }
    }
}
