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

            return true;
        }

        private static bool MatchesText(string expected, string actual)
        {
            return string.IsNullOrWhiteSpace(expected) ||
                string.Equals(expected, actual, StringComparison.OrdinalIgnoreCase);
        }
    }
}
