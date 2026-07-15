using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceInfo
    {
        private KarProjectResourceInfo(
            KarResourceReference reference,
            KarProjectFile file,
            KarProjectRootInfo root,
            KarProjectA2DEntryInfo a2dEntry,
            string displayName,
            string role,
            string category,
            string description)
        {
            Reference = reference ?? throw new ArgumentNullException(nameof(reference));
            File = file;
            Root = root;
            A2DEntry = a2dEntry;
            DisplayName = displayName;
            Role = role;
            Category = category;
            Description = description;
        }

        public KarResourceReference Reference { get; }

        public KarResourceKind Kind => Reference.Kind;

        public string Address => Reference.Address;

        public string RelativePath => Reference.RelativePath;

        public string ParentAddress => Reference.ParentAddress;

        public KarProjectFile File { get; }

        public KarProjectRootInfo Root { get; }

        public KarProjectA2DEntryInfo A2DEntry { get; }

        public string DisplayName { get; }

        public string Role { get; }

        public string Category { get; }

        public string Description { get; }

        public bool IsFile => Kind == KarResourceKind.File;

        public bool IsHsdRoot => Kind == KarResourceKind.HsdRoot;

        public bool IsA2DEntry => Kind == KarResourceKind.A2DEntry;

        public bool CanReadBytes => Kind == KarResourceKind.File || Kind == KarResourceKind.A2DEntry;

        public bool CanExportToOutput => true;

        public bool CanImportFromFile => Kind == KarResourceKind.File || Kind == KarResourceKind.A2DEntry;

        internal static KarProjectResourceInfo FromFile(KarProjectFile file)
        {
            if (file == null)
                throw new ArgumentNullException(nameof(file));

            return new KarProjectResourceInfo(
                file.ResourceReference,
                file,
                null,
                null,
                file.DisplayName,
                file.Kind.ToString(),
                file.Category,
                file.ArchiveDefinition.Description);
        }

        internal static KarProjectResourceInfo FromRoot(KarProjectRootInfo root)
        {
            if (root == null)
                throw new ArgumentNullException(nameof(root));

            string description = root.Root.Definition == null
                ? root.Root.DataDefinition == null ? "HSD archive root." : root.Root.DataDefinition.Description
                : root.Root.Definition.Description;

            return new KarProjectResourceInfo(
                root.ResourceReference,
                root.File,
                root,
                null,
                root.RootName,
                root.DataDefinitionId ?? root.DisplayAccessorTypeName,
                root.Root.DataDefinition == null ? root.File.Category : root.Root.DataDefinition.Category,
                description);
        }

        internal static KarProjectResourceInfo FromA2DEntry(KarProjectA2DEntryInfo entry)
        {
            if (entry == null)
                throw new ArgumentNullException(nameof(entry));

            return new KarProjectResourceInfo(
                entry.ResourceReference,
                entry.PackageFile,
                null,
                entry,
                entry.Name,
                entry.Role,
                entry.Category,
                entry.Description);
        }
    }
}
