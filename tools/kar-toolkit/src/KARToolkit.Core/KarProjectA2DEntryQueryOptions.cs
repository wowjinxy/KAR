using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectA2DEntryQueryOptions
    {
        public KarProjectFileQueryOptions Packages { get; set; }

        public string PackagePath { get; set; }

        public string EntryName { get; set; }

        public string Kind { get; set; }

        public string Role { get; set; }

        public string Category { get; set; }

        public bool? IsScriptTable { get; set; }

        public bool Matches(KarProjectA2DEntryInfo entry)
        {
            if (entry == null)
                throw new ArgumentNullException(nameof(entry));

            if (!MatchesText(PackagePath, entry.PackageRelativePath))
                return false;
            if (!MatchesText(EntryName, entry.Name))
                return false;
            if (!MatchesText(Kind, entry.Kind))
                return false;
            if (!MatchesText(Role, entry.Role))
                return false;
            if (!MatchesText(Category, entry.Category))
                return false;
            if (IsScriptTable.HasValue && entry.IsScriptTable != IsScriptTable.Value)
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
