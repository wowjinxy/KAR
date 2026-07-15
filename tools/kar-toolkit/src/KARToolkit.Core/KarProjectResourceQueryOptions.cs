using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceQueryOptions
    {
        public KarResourceKind? Kind { get; set; }

        public string Address { get; set; }

        public string RelativePath { get; set; }

        public string Category { get; set; }

        public string Role { get; set; }

        public string Text { get; set; }

        public KarProjectFileQueryOptions Files { get; set; }

        public KarProjectRootQueryOptions Roots { get; set; }

        public KarProjectA2DEntryQueryOptions A2DEntries { get; set; }

        public bool Matches(KarProjectResourceInfo resource)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));

            if (Kind.HasValue && resource.Kind != Kind.Value)
                return false;

            if (!string.IsNullOrWhiteSpace(Address))
            {
                KarResourceReference reference;
                if (!KarResourceReference.TryParse(Address, out reference) || !reference.Equals(resource.Reference))
                    return false;
            }

            if (!string.IsNullOrWhiteSpace(RelativePath) &&
                !string.Equals(KarProjectWorkspace.NormalizeRelativePath(RelativePath), resource.RelativePath, StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }

            if (!MatchesText(Category, resource.Category))
                return false;
            if (!MatchesText(Role, resource.Role))
                return false;
            if (!string.IsNullOrWhiteSpace(Text) && !MatchesSearchText(resource, Text))
                return false;

            return true;
        }

        private static bool MatchesText(string expected, string actual)
        {
            return string.IsNullOrWhiteSpace(expected) ||
                string.Equals(expected, actual, StringComparison.OrdinalIgnoreCase);
        }

        private static bool MatchesSearchText(KarProjectResourceInfo resource, string text)
        {
            return Contains(resource.Address, text) ||
                Contains(resource.RelativePath, text) ||
                Contains(resource.ParentAddress, text) ||
                Contains(resource.DisplayName, text) ||
                Contains(resource.Role, text) ||
                Contains(resource.Category, text) ||
                Contains(resource.Description, text) ||
                Contains(resource.HandlerId, text) ||
                MatchesFile(resource.File, text) ||
                MatchesRoot(resource.Root, text) ||
                MatchesA2DEntry(resource.A2DEntry, text);
        }

        private static bool MatchesFile(KarProjectFile file, string text)
        {
            return file != null &&
                (Contains(file.RelativePath, text) ||
                Contains(file.Kind.ToString(), text) ||
                Contains(file.KindId, text) ||
                Contains(file.DisplayName, text) ||
                Contains(file.Category, text) ||
                Contains(file.MapName, text) ||
                Contains(file.MapBundleRole, text));
        }

        private static bool MatchesRoot(KarProjectRootInfo root, string text)
        {
            return root != null &&
                (Contains(root.RootName, text) ||
                Contains(root.RootPath, text) ||
                Contains(root.DisplayName, text) ||
                Contains(root.Role, text) ||
                Contains(root.Category, text) ||
                Contains(root.Description, text) ||
                Contains(root.AccessorTypeName, text) ||
                Contains(root.DisplayAccessorTypeName, text) ||
                Contains(root.DataDefinitionId, text) ||
                Contains(root.SchemaDisplayName, text) ||
                Contains(root.SchemaDescription, text));
        }

        private static bool MatchesA2DEntry(KarProjectA2DEntryInfo entry, string text)
        {
            return entry != null &&
                (Contains(entry.EntryPath, text) ||
                Contains(entry.Name, text) ||
                Contains(entry.Kind, text) ||
                Contains(entry.Role, text) ||
                Contains(entry.Category, text) ||
                Contains(entry.Description, text) ||
                Contains(entry.PackageRelativePath, text));
        }

        private static bool Contains(string value, string text)
        {
            return value != null &&
                value.IndexOf(text, StringComparison.OrdinalIgnoreCase) >= 0;
        }
    }
}
