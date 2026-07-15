using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectFileQueryOptions
    {
        public KarFileKind? Kind { get; set; }

        public string Category { get; set; }

        public string Text { get; set; }

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
            if (!string.IsNullOrWhiteSpace(Text) && !MatchesSearchText(file, Text))
                return false;

            return true;
        }

        internal static bool MatchesSearchText(KarProjectFile file, string text)
        {
            return file != null &&
                (Contains(file.RelativePath, text) ||
                Contains(file.Kind.ToString(), text) ||
                Contains(file.KindId, text) ||
                Contains(file.DisplayName, text) ||
                Contains(file.Category, text) ||
                Contains(file.ArchiveDefinition == null ? null : file.ArchiveDefinition.Description, text) ||
                Contains(file.KindDescriptor == null ? null : file.KindDescriptor.DisplayName, text) ||
                Contains(file.KindDescriptor == null ? null : file.KindDescriptor.Description, text) ||
                Contains(file.Handler == null ? null : file.Handler.DisplayName, text) ||
                Contains(file.MapName, text) ||
                Contains(file.MapBundleRole, text));
        }

        internal static bool Contains(string value, string text)
        {
            return value != null &&
                value.IndexOf(text, StringComparison.OrdinalIgnoreCase) >= 0;
        }
    }
}
