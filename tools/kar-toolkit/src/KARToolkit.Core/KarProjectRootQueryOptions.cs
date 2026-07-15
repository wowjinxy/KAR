using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectRootQueryOptions
    {
        public KarProjectFileQueryOptions Files { get; set; }

        public bool? IsKnown { get; set; }

        public string RootName { get; set; }

        public string Text { get; set; }

        public bool Matches(KarProjectRootInfo root)
        {
            if (root == null)
                throw new ArgumentNullException(nameof(root));

            if (IsKnown.HasValue && root.IsKnown != IsKnown.Value)
                return false;

            if (!string.IsNullOrWhiteSpace(RootName) &&
                !string.Equals(root.RootName, RootName, StringComparison.Ordinal))
            {
                return false;
            }

            if (!string.IsNullOrWhiteSpace(Text) && !MatchesSearchText(root, Text))
                return false;

            return true;
        }

        internal static bool MatchesSearchText(KarProjectRootInfo root, string text)
        {
            return root != null &&
                (KarProjectFileQueryOptions.MatchesSearchText(root.File, text) ||
                KarProjectFileQueryOptions.Contains(root.RootName, text) ||
                KarProjectFileQueryOptions.Contains(root.RootPath, text) ||
                KarProjectFileQueryOptions.Contains(root.DisplayName, text) ||
                KarProjectFileQueryOptions.Contains(root.Role, text) ||
                KarProjectFileQueryOptions.Contains(root.Category, text) ||
                KarProjectFileQueryOptions.Contains(root.Description, text) ||
                KarProjectFileQueryOptions.Contains(root.AccessorTypeName, text) ||
                KarProjectFileQueryOptions.Contains(root.DisplayAccessorTypeName, text) ||
                KarProjectFileQueryOptions.Contains(root.DataDefinitionId, text) ||
                KarProjectFileQueryOptions.Contains(root.SchemaDisplayName, text) ||
                KarProjectFileQueryOptions.Contains(root.SchemaDescription, text));
        }
    }
}
