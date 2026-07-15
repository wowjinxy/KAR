using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceFieldInfo
    {
        internal KarProjectResourceFieldInfo(KarProjectResourceInfo resource, KarProjectFieldInfo field)
        {
            Resource = resource ?? throw new ArgumentNullException(nameof(resource));
            FieldInfo = field ?? throw new ArgumentNullException(nameof(field));
        }

        public KarProjectResourceInfo Resource { get; }

        public KarResourceReference Reference => Resource.Reference;

        public string Address => Resource.Address;

        public KarProjectFieldInfo FieldInfo { get; }

        public KarProjectFile File => FieldInfo.File;

        public KarProjectRootInfo Root => FieldInfo.Root;

        public KarArchiveRootInfo ArchiveRoot => FieldInfo.ArchiveRoot;

        public KarDataFieldValue Value => FieldInfo.Value;

        public KarDataFieldDefinition Field => FieldInfo.Field;

        public string RelativePath => FieldInfo.RelativePath;

        public string RootName => FieldInfo.RootName;

        public string DataDefinitionId => FieldInfo.DataDefinitionId;

        public string FieldName => FieldInfo.FieldName;
    }
}
