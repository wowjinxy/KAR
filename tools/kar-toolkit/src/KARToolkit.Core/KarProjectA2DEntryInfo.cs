using System;
using KARToolkit.Core.AirRide;

namespace KARToolkit.Core
{
    public sealed class KarProjectA2DEntryInfo
    {
        internal KarProjectA2DEntryInfo(KarProjectFile packageFile, A2DPackageEntry entry)
        {
            PackageFile = packageFile ?? throw new ArgumentNullException(nameof(packageFile));
            if (entry == null)
                throw new ArgumentNullException(nameof(entry));

            Index = entry.Index;
            Name = entry.Name;
            NameOffset = entry.NameOffset;
            DataOffset = entry.DataOffset;
            Size = entry.Size;
            Kind = entry.Kind;

            KarScriptTableInfo scriptTable = KarScriptTableCatalog.Describe(Name);
            Role = string.Equals(Kind, "tm", StringComparison.OrdinalIgnoreCase)
                ? scriptTable.Role
                : Kind;
            Category = string.Equals(Kind, "tm", StringComparison.OrdinalIgnoreCase)
                ? scriptTable.Category
                : "A2D";
            Description = string.Equals(Kind, "tm", StringComparison.OrdinalIgnoreCase)
                ? scriptTable.Description
                : "A2D package resource.";
        }

        public KarProjectFile PackageFile { get; }

        public string PackageRelativePath => PackageFile.RelativePath;

        public KarResourceReference ResourceReference => KarResourceReference.A2DEntry(PackageRelativePath, Name);

        public string EntryPath => ResourceReference.Address;

        public int Index { get; }

        public string Name { get; }

        public int NameOffset { get; }

        public string NameOffsetHex => "0x" + NameOffset.ToString("X");

        public int DataOffset { get; }

        public string DataOffsetHex => "0x" + DataOffset.ToString("X");

        public int Size { get; }

        public string SizeHex => "0x" + Size.ToString("X");

        public string Kind { get; }

        public bool IsScriptTable => string.Equals(Kind, "tm", StringComparison.OrdinalIgnoreCase);

        public string Role { get; }

        public string Category { get; }

        public string Description { get; }
    }
}
