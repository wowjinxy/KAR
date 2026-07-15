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

        public string AccessorTypeName => Root.AccessorTypeName;

        public string DisplayAccessorTypeName => Root.DisplayAccessorTypeName;

        public string DataDefinitionId => Root.DataDefinitionId;
    }
}
