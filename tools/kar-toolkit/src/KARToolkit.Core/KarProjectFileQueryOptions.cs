using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectFileQueryOptions
    {
        public KarFileKind? Kind { get; set; }

        public string Category { get; set; }

        public bool? HasOutputCopy { get; set; }

        public bool Matches(KarProjectFile file)
        {
            if (file == null)
                throw new ArgumentNullException(nameof(file));

            if (Kind.HasValue && file.Kind != Kind.Value)
                return false;

            if (!string.IsNullOrWhiteSpace(Category) &&
                !string.Equals(file.Category, Category, StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }

            if (HasOutputCopy.HasValue && file.HasOutputCopy != HasOutputCopy.Value)
                return false;

            return true;
        }
    }
}
