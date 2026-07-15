using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectOutputFileQueryOptions
    {
        public KarFileKind? Kind { get; set; }

        public string Category { get; set; }

        public bool? IsProjectFile { get; set; }

        public bool Matches(KarProjectOutputFileInfo file)
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

            if (IsProjectFile.HasValue && file.IsProjectFile != IsProjectFile.Value)
                return false;

            return true;
        }
    }
}
