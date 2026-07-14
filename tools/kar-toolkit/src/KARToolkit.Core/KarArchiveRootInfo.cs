namespace KARToolkit.Core
{
    public sealed class KarArchiveRootInfo
    {
        internal KarArchiveRootInfo(string name, string accessorTypeName, KarRootDefinition definition)
        {
            Name = name;
            AccessorTypeName = accessorTypeName;
            Definition = definition;
        }

        public string Name { get; }

        public string AccessorTypeName { get; }

        public KarRootDefinition Definition { get; }

        public bool IsKnown => Definition != null;

        public string ExpectedAccessorTypeName => Definition == null ? null : Definition.AccessorTypeName;

        public string DisplayAccessorTypeName
        {
            get
            {
                if (!string.IsNullOrEmpty(ExpectedAccessorTypeName))
                    return ExpectedAccessorTypeName;

                return AccessorTypeName;
            }
        }
    }
}
