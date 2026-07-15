using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectScriptTableQueryOptions
    {
        public KarProjectResourceQueryOptions Resources { get; set; }

        public string Address { get; set; }

        public string Name { get; set; }

        public string Role { get; set; }

        public string Category { get; set; }

        public string PackagePath { get; set; }

        public string Text { get; set; }

        public bool? IsLooseFile { get; set; }

        public bool? IsPackageEntry { get; set; }

        public bool Matches(KarProjectScriptTable table)
        {
            if (table == null)
                throw new ArgumentNullException(nameof(table));

            if (!string.IsNullOrWhiteSpace(Address))
            {
                KarResourceReference reference;
                if (!KarResourceReference.TryParse(Address, out reference) || !reference.Equals(table.Reference))
                    return false;
            }

            if (!MatchesText(Name, table.Name))
                return false;
            if (!MatchesText(Role, table.Role))
                return false;
            if (!MatchesText(Category, table.Category))
                return false;
            if (!MatchesText(PackagePath, table.PackageRelativePath))
                return false;
            if (IsLooseFile.HasValue && table.IsLooseFile != IsLooseFile.Value)
                return false;
            if (IsPackageEntry.HasValue && table.IsPackageEntry != IsPackageEntry.Value)
                return false;
            if (!string.IsNullOrWhiteSpace(Text) && !MatchesSearchText(table, Text))
                return false;

            return true;
        }

        private static bool MatchesText(string expected, string actual)
        {
            return string.IsNullOrWhiteSpace(expected) ||
                string.Equals(expected, actual, StringComparison.OrdinalIgnoreCase);
        }

        internal static bool MatchesSearchText(KarProjectScriptTable table, string text)
        {
            return table != null &&
                (KarProjectResourceQueryOptions.MatchesSearchText(table.Resource, text) ||
                KarProjectFileQueryOptions.Contains(table.Address, text) ||
                KarProjectFileQueryOptions.Contains(table.ParentAddress, text) ||
                KarProjectFileQueryOptions.Contains(table.RelativePath, text) ||
                KarProjectFileQueryOptions.Contains(table.Name, text) ||
                KarProjectFileQueryOptions.Contains(table.Role, text) ||
                KarProjectFileQueryOptions.Contains(table.Category, text) ||
                KarProjectFileQueryOptions.Contains(table.Description, text) ||
                KarProjectFileQueryOptions.Contains(table.PackageRelativePath, text) ||
                KarProjectFileQueryOptions.Contains(table.PackageEntryOffsetHex, text) ||
                KarProjectFileQueryOptions.Contains(table.PackageEntrySizeHex, text));
        }
    }
}
