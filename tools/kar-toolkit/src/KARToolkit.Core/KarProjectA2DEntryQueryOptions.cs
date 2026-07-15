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

        public string Text { get; set; }

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
            if (!string.IsNullOrWhiteSpace(Text) && !MatchesSearchText(entry, Text))
                return false;

            return true;
        }

        private static bool MatchesText(string expected, string actual)
        {
            return string.IsNullOrWhiteSpace(expected) ||
                string.Equals(expected, actual, StringComparison.OrdinalIgnoreCase);
        }

        internal static bool MatchesSearchText(KarProjectA2DEntryInfo entry, string text)
        {
            return entry != null &&
                (KarProjectFileQueryOptions.MatchesSearchText(entry.PackageFile, text) ||
                KarProjectFileQueryOptions.Contains(entry.EntryPath, text) ||
                KarProjectFileQueryOptions.Contains(entry.PackageRelativePath, text) ||
                KarProjectFileQueryOptions.Contains(entry.Name, text) ||
                KarProjectFileQueryOptions.Contains(entry.Kind, text) ||
                KarProjectFileQueryOptions.Contains(entry.Role, text) ||
                KarProjectFileQueryOptions.Contains(entry.Category, text) ||
                KarProjectFileQueryOptions.Contains(entry.Description, text) ||
                KarProjectFileQueryOptions.Contains(entry.DataOffsetHex, text) ||
                KarProjectFileQueryOptions.Contains(entry.SizeHex, text));
        }
    }
}
