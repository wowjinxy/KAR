using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceInfo
    {
        private KarProjectResourceInfo(
            KarResourceReference reference,
            KarProjectResourceHandler handler,
            KarProjectFile file,
            KarProjectRootInfo root,
            KarProjectA2DEntryInfo a2dEntry,
            string displayName,
            string role,
            string category,
            string description)
        {
            Reference = reference ?? throw new ArgumentNullException(nameof(reference));
            Handler = handler ?? throw new ArgumentNullException(nameof(handler));
            if (Handler.Kind != Reference.Kind)
                throw new ArgumentException("Resource handler does not match resource kind.", nameof(handler));
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

        public KarProjectResourceHandler Handler { get; }

        public string HandlerId => Handler.Id;

        public KarProjectResourceCapability Capabilities => Handler.Capabilities;

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

        public bool CanQueryOutput => Handler.CanQueryOutput;

        public bool CanReadBytes => Handler.CanReadBytes;

        public bool CanExportToOutput => Handler.CanExportToOutput;

        public bool CanImportFromFile => Handler.CanImportFromFile;

        public bool CanSetScalarFields => Handler.CanSetScalarFields;

        public bool CanQueryFieldValues => Handler.CanQueryFieldValues;

        public bool CanApplyOutput => Handler.CanApplyOutput;

        internal static KarProjectResourceInfo FromFile(KarProjectFile file, KarProjectResourceHandler handler)
        {
            if (file == null)
                throw new ArgumentNullException(nameof(file));

            return new KarProjectResourceInfo(
                file.ResourceReference,
                handler,
                file,
                null,
                null,
                file.DisplayName,
                file.Kind.ToString(),
                file.Category,
                file.ArchiveDefinition.Description);
        }

        internal static KarProjectResourceInfo FromRoot(KarProjectRootInfo root, KarProjectResourceHandler handler)
        {
            if (root == null)
                throw new ArgumentNullException(nameof(root));

            return new KarProjectResourceInfo(
                root.ResourceReference,
                handler,
                root.File,
                root,
                null,
                root.DisplayName,
                root.Role,
                root.Category,
                root.Description);
        }

        internal static KarProjectResourceInfo FromA2DEntry(KarProjectA2DEntryInfo entry, KarProjectResourceHandler handler)
        {
            if (entry == null)
                throw new ArgumentNullException(nameof(entry));

            return new KarProjectResourceInfo(
                entry.ResourceReference,
                handler,
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
