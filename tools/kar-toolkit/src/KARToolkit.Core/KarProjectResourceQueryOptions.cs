using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceQueryOptions
    {
        public KarResourceKind? Kind { get; set; }

        public string Domain { get; set; }

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

            if (!MatchesDomain(resource, Domain))
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

        public static bool MatchesDomain(KarProjectResourceInfo resource, string domain)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));
            if (string.IsNullOrWhiteSpace(domain))
                return true;

            switch (KarProjectFileQueryOptions.NormalizeDomain(domain))
            {
                case "all":
                case "resources":
                    return true;
                case "files":
                    return resource.IsFile;
                case "archives":
                case "maps":
                case "vehicles":
                    return resource.File != null && KarProjectFileQueryOptions.MatchesDomain(resource.File, domain);
                case "a2d-packages":
                    return resource.IsA2DEntry || (resource.File != null && resource.File.IsA2DPackage);
                case "script-tables":
                    return string.Equals(resource.Category, "Scripts", StringComparison.OrdinalIgnoreCase) ||
                        (resource.File != null && resource.File.IsScriptTable) ||
                        (resource.A2DEntry != null && resource.A2DEntry.IsScriptTable);
                case "mod-output":
                    return resource.CanQueryOutput || resource.CanReadBytes;
                default:
                    throw new ArgumentException("Unknown KAR project domain: " + domain);
            }
        }

        private static bool MatchesText(string expected, string actual)
        {
            return string.IsNullOrWhiteSpace(expected) ||
                string.Equals(expected, actual, StringComparison.OrdinalIgnoreCase);
        }

        internal static bool MatchesSearchText(KarProjectResourceInfo resource, string text)
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
            return KarProjectFileQueryOptions.MatchesSearchText(file, text);
        }

        private static bool MatchesRoot(KarProjectRootInfo root, string text)
        {
            return KarProjectRootQueryOptions.MatchesSearchText(root, text);
        }

        private static bool MatchesA2DEntry(KarProjectA2DEntryInfo entry, string text)
        {
            return KarProjectA2DEntryQueryOptions.MatchesSearchText(entry, text);
        }

        private static bool Contains(string value, string text)
        {
            return value != null &&
                value.IndexOf(text, StringComparison.OrdinalIgnoreCase) >= 0;
        }
    }
}
