namespace KARToolkit.Core
{
    internal static class KarDataDefinitionFactory
    {
        public static KarDataDefinition Define(
            string id,
            string displayName,
            string category,
            string accessorTypeName,
            string description,
            string source,
            params KarDataFieldDefinition[] fields)
        {
            return new KarDataDefinition(id, displayName, category, accessorTypeName, description, source, fields);
        }

        public static KarDataDefinition DefineSized(
            string id,
            string displayName,
            string category,
            string accessorTypeName,
            int size,
            string description,
            string source,
            params KarDataFieldDefinition[] fields)
        {
            return new KarDataDefinition(id, displayName, category, accessorTypeName, description, source, fields, size);
        }

        public static KarDataFieldDefinition Field(
            string name,
            int? offset,
            string typeName,
            string description,
            bool isPointer = false,
            string dataDefinitionId = null)
        {
            return new KarDataFieldDefinition(name, offset, typeName, description, isPointer, dataDefinitionId);
        }
    }
}
