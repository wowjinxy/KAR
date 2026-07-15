using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectRelationshipQueryOptions
    {
        public string Kind { get; set; }

        public string Role { get; set; }

        public string Category { get; set; }

        public string MapName { get; set; }

        public string RelativePath { get; set; }

        public string PackagePath { get; set; }

        public string PackageEntryName { get; set; }

        public string Text { get; set; }

        public bool? IsMapScoped { get; set; }

        public bool? IsPackageEntry { get; set; }

        public bool Matches(KarProjectRelationship relationship)
        {
            if (relationship == null)
                throw new ArgumentNullException(nameof(relationship));

            if (!MatchesText(Kind, relationship.Kind))
                return false;
            if (!MatchesText(Role, relationship.Role))
                return false;
            if (!MatchesText(Category, relationship.Category))
                return false;
            if (!MatchesText(MapName, relationship.MapName))
                return false;
            if (!MatchesText(RelativePath, relationship.RelativePath))
                return false;
            if (!MatchesText(PackagePath, relationship.PackageFile == null ? null : relationship.PackageFile.RelativePath))
                return false;
            if (!MatchesText(PackageEntryName, relationship.PackageEntryName))
                return false;
            if (IsMapScoped.HasValue && relationship.IsMapScoped != IsMapScoped.Value)
                return false;
            if (IsPackageEntry.HasValue && relationship.IsPackageEntry != IsPackageEntry.Value)
                return false;
            if (!string.IsNullOrWhiteSpace(Text) && !MatchesSearchText(relationship, Text))
                return false;

            return true;
        }

        private static bool MatchesText(string expected, string actual)
        {
            return string.IsNullOrWhiteSpace(expected) ||
                string.Equals(expected, actual, StringComparison.OrdinalIgnoreCase);
        }

        internal static bool MatchesSearchText(KarProjectRelationship relationship, string text)
        {
            return relationship != null &&
                (KarProjectFileQueryOptions.MatchesSearchText(relationship.File, text) ||
                KarProjectFileQueryOptions.MatchesSearchText(relationship.PackageFile, text) ||
                KarProjectFileQueryOptions.Contains(relationship.Kind, text) ||
                KarProjectFileQueryOptions.Contains(relationship.Role, text) ||
                KarProjectFileQueryOptions.Contains(relationship.Category, text) ||
                KarProjectFileQueryOptions.Contains(relationship.Description, text) ||
                KarProjectFileQueryOptions.Contains(relationship.MapName, text) ||
                KarProjectFileQueryOptions.Contains(relationship.RelativePath, text) ||
                KarProjectFileQueryOptions.Contains(relationship.DisplayName, text) ||
                KarProjectFileQueryOptions.Contains(relationship.PackageEntryName, text) ||
                KarProjectFileQueryOptions.Contains(relationship.PackageEntryOffsetHex, text) ||
                KarProjectFileQueryOptions.Contains(relationship.PackageEntrySizeHex, text));
        }
    }
}
