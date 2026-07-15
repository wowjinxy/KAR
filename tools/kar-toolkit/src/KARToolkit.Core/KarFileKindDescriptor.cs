using System;

namespace KARToolkit.Core
{
    public sealed class KarFileKindDescriptor
    {
        public KarFileKindDescriptor(
            KarFileKind kind,
            string id,
            string displayName,
            string category,
            string description,
            bool isHsdArchive = false,
            bool isA2DPackage = false,
            bool isScriptTable = false,
            bool isMedia = false,
            bool isConfig = false,
            string mapBundleRole = null)
        {
            Kind = kind;
            Id = RequireText(id, nameof(id));
            DisplayName = RequireText(displayName, nameof(displayName));
            Category = RequireText(category, nameof(category));
            Description = description ?? "";
            IsHsdArchive = isHsdArchive;
            IsA2DPackage = isA2DPackage;
            IsScriptTable = isScriptTable;
            IsMedia = isMedia;
            IsConfig = isConfig;
            MapBundleRole = string.IsNullOrWhiteSpace(mapBundleRole) ? null : mapBundleRole;
        }

        public KarFileKind Kind { get; }

        public string Id { get; }

        public string DisplayName { get; }

        public string Category { get; }

        public string Description { get; }

        public bool IsHsdArchive { get; }

        public bool IsA2DPackage { get; }

        public bool IsScriptTable { get; }

        public bool IsMedia { get; }

        public bool IsConfig { get; }

        public string MapBundleRole { get; }

        public bool IsMapBundlePart => MapBundleRole != null;

        public bool IsContainer => IsHsdArchive || IsA2DPackage;

        private static string RequireText(string value, string parameterName)
        {
            if (string.IsNullOrWhiteSpace(value))
                throw new ArgumentException("Value cannot be empty.", parameterName);

            return value;
        }
    }
}
