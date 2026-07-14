using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarArchiveRootInfo
    {
        internal KarArchiveRootInfo(
            string name,
            string accessorTypeName,
            KarRootDefinition definition,
            IEnumerable<KarDataFieldValue> fieldValues)
        {
            Name = name;
            AccessorTypeName = accessorTypeName;
            Definition = definition;
            FieldValues = (fieldValues ?? Enumerable.Empty<KarDataFieldValue>())
                .ToList()
                .AsReadOnly();
        }

        public string Name { get; }

        public string AccessorTypeName { get; }

        public KarRootDefinition Definition { get; }

        public IReadOnlyList<KarDataFieldValue> FieldValues { get; }

        public bool HasFieldValues => FieldValues.Count != 0;

        public bool IsKnown => Definition != null;

        public string ExpectedAccessorTypeName => Definition == null ? null : Definition.AccessorTypeName;

        public string DataDefinitionId => DataDefinition == null ? null : DataDefinition.Id;

        public KarDataDefinition DataDefinition
        {
            get
            {
                if (Definition != null && Definition.DataDefinition != null)
                    return Definition.DataDefinition;

                KarDataDefinition definition;
                if (KarDataDefinitionCatalog.TryGetByAccessorTypeName(DisplayAccessorTypeName, out definition))
                    return definition;

                return null;
            }
        }

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
