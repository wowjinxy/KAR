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

            return true;
        }

        private static bool MatchesText(string expected, string actual)
        {
            return string.IsNullOrWhiteSpace(expected) ||
                string.Equals(expected, actual, StringComparison.OrdinalIgnoreCase);
        }
    }
}
