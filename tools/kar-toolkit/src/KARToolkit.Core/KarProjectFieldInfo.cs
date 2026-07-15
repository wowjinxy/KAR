using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectFieldInfo
    {
        internal KarProjectFieldInfo(KarProjectRootInfo root, KarDataFieldValue value)
        {
            Root = root ?? throw new ArgumentNullException(nameof(root));
            Value = value ?? throw new ArgumentNullException(nameof(value));
        }

        public KarProjectRootInfo Root { get; }

        public KarProjectFile File => Root.File;

        public KarArchiveRootInfo ArchiveRoot => Root.Root;

        public KarDataFieldValue Value { get; }

        public KarDataFieldDefinition Field => Value.Field;

        public string RelativePath => Root.RelativePath;

        public string RootName => Root.RootName;

        public string DataDefinitionId => ArchiveRoot.DataDefinitionId;

        public string FieldName => Field.Name;
    }
}
