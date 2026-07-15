using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectFileQueryOptions
    {
        public KarFileKind? Kind { get; set; }

        public string Domain { get; set; }

        public string Category { get; set; }

        public string Text { get; set; }

        public bool? HasOutputCopy { get; set; }

        public bool Matches(KarProjectFile file)
        {
            if (file == null)
                throw new ArgumentNullException(nameof(file));

            if (Kind.HasValue && file.Kind != Kind.Value)
                return false;

            if (!MatchesDomain(file, Domain))
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

        public static bool MatchesDomain(KarProjectFile file, string domain)
        {
            if (file == null)
                throw new ArgumentNullException(nameof(file));
            if (string.IsNullOrWhiteSpace(domain))
                return true;

            switch (NormalizeDomain(domain))
            {
                case "all":
                case "files":
                case "resources":
                    return true;
                case "archives":
                    return file.IsHsdArchive;
                case "maps":
                    return file.IsMapBundlePart;
                case "vehicles":
                    return file.Kind == KarFileKind.VehicleData;
                case "a2d-packages":
                    return file.IsA2DPackage;
                case "script-tables":
                    return file.IsScriptTable;
                case "mod-output":
                    return file.HasOutputCopy;
                default:
                    throw new ArgumentException("Unknown KAR project domain: " + domain);
            }
        }

        public static string NormalizeDomain(string domain)
        {
            if (string.IsNullOrWhiteSpace(domain))
                return null;

            string normalized = domain.Replace("-", "").Replace("_", "").ToLowerInvariant();
            switch (normalized)
            {
                case "all":
                case "project":
                    return "all";
                case "file":
                case "files":
                    return "files";
                case "resource":
                case "resources":
                    return "resources";
                case "archive":
                case "archives":
                case "hsd":
                case "hsdarchive":
                case "hsdarchives":
                    return "archives";
                case "map":
                case "maps":
                case "stage":
                case "stages":
                    return "maps";
                case "vehicle":
                case "vehicles":
                case "machine":
                case "machines":
                    return "vehicles";
                case "a2d":
                case "a2dpackage":
                case "a2dpackages":
                case "package":
                case "packages":
                    return "a2d-packages";
                case "script":
                case "scripts":
                case "scripttable":
                case "scripttables":
                case "tm":
                    return "script-tables";
                case "mod":
                case "modoutput":
                case "output":
                case "outputs":
                    return "mod-output";
                default:
                    throw new ArgumentException("Unknown KAR project domain: " + domain);
            }
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
