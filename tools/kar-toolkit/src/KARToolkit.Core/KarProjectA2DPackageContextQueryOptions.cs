using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectA2DPackageContextQueryOptions
    {
        public KarProjectFileQueryOptions Packages { get; set; }

        public string PackagePath { get; set; }

        public string Text { get; set; }

        public bool? IsOpen { get; set; }

        public bool? HasScriptTables { get; set; }

        public bool? HasEntryOutputs { get; set; }

        public bool? HasModifiedEntryOutputs { get; set; }

        public bool Matches(KarProjectA2DPackageContext context)
        {
            if (context == null)
                throw new ArgumentNullException(nameof(context));

            if (!string.IsNullOrWhiteSpace(PackagePath) &&
                !string.Equals(KarProjectWorkspace.NormalizeRelativePath(PackagePath), context.RelativePath, StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }

            if (IsOpen.HasValue && context.IsOpen != IsOpen.Value)
                return false;
            if (HasScriptTables.HasValue && context.HasScriptTables != HasScriptTables.Value)
                return false;
            if (HasEntryOutputs.HasValue && context.HasEntryOutputs != HasEntryOutputs.Value)
                return false;
            if (HasModifiedEntryOutputs.HasValue && context.HasModifiedEntryOutputs != HasModifiedEntryOutputs.Value)
                return false;
            if (!string.IsNullOrWhiteSpace(Text) && !MatchesSearchText(context, Text))
                return false;

            return true;
        }

        private static bool MatchesSearchText(KarProjectA2DPackageContext context, string text)
        {
            if (KarProjectFileQueryOptions.MatchesSearchText(context.PackageFile, text) ||
                KarProjectFileQueryOptions.Contains(context.RelativePath, text) ||
                KarProjectFileQueryOptions.Contains(context.OpenError, text))
            {
                return true;
            }

            foreach (KarProjectA2DEntryInfo entry in context.Entries)
            {
                if (KarProjectFileQueryOptions.Contains(entry.EntryPath, text) ||
                    KarProjectFileQueryOptions.Contains(entry.Name, text) ||
                    KarProjectFileQueryOptions.Contains(entry.Kind, text) ||
                    KarProjectFileQueryOptions.Contains(entry.Role, text) ||
                    KarProjectFileQueryOptions.Contains(entry.Category, text) ||
                    KarProjectFileQueryOptions.Contains(entry.Description, text))
                {
                    return true;
                }
            }

            return false;
        }
    }
}
