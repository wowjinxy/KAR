using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectRootInfo
    {
        internal KarProjectRootInfo(KarProjectFile file, KarArchiveRootInfo root)
        {
            File = file ?? throw new ArgumentNullException(nameof(file));
            Root = root ?? throw new ArgumentNullException(nameof(root));
        }

        public KarProjectFile File { get; }

        public KarArchiveRootInfo Root { get; }

        public string RelativePath => File.RelativePath;

        public string RootName => Root.Name;

        public KarResourceReference ResourceReference => KarResourceReference.HsdRoot(RelativePath, RootName);

        public string RootPath => ResourceReference.Address;

        public bool IsKnown => Root.IsKnown;

        public KarRootDefinition Definition => Root.Definition;

        public KarDataDefinition DataDefinition => Root.DataDefinition;

        public string AccessorTypeName => Root.AccessorTypeName;

        public string DisplayAccessorTypeName => Root.DisplayAccessorTypeName;

        public string DataDefinitionId => Root.DataDefinitionId;

        public string Role
        {
            get
            {
                if (Definition != null && !string.IsNullOrEmpty(Definition.Description))
                    return Definition.Description;

                if (DataDefinition != null)
                    return DataDefinition.DisplayName;

                return DisplayAccessorTypeName ?? "HSD archive root";
            }
        }

        public string DisplayName => DataDefinition == null ? RootName : DataDefinition.DisplayName;

        public string Category => DataDefinition == null ? File.Category : DataDefinition.Category;

        public string Description
        {
            get
            {
                if (DataDefinition != null && !string.IsNullOrEmpty(DataDefinition.Description))
                    return DataDefinition.Description;

                if (Definition != null && !string.IsNullOrEmpty(Definition.Description))
                    return Definition.Description;

                return "HSD archive root.";
            }
        }

        public string SchemaDisplayName => DataDefinition == null ? null : DataDefinition.DisplayName;

        public string SchemaDescription => DataDefinition == null ? null : DataDefinition.Description;
    }
}
