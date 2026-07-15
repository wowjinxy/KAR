using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectRootQueryOptions
    {
        public KarProjectFileQueryOptions Files { get; set; }

        public bool? IsKnown { get; set; }

        public string RootName { get; set; }

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

            return true;
        }
    }
}
