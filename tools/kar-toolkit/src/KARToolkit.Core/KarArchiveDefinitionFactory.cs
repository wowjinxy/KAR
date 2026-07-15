namespace KARToolkit.Core
{
    internal static class KarArchiveDefinitionFactory
    {
        public static KarArchiveDefinition Define(KarFileKind kind, string displayName, string category, string description, params KarRootDefinition[] roots)
        {
            return new KarArchiveDefinition(kind, displayName, category, description, roots);
        }

        public static KarRootDefinition Root(string name, string description, string accessorTypeName, bool isRequired = true, string dataDefinitionId = null)
        {
            if (!string.IsNullOrWhiteSpace(dataDefinitionId))
                return KarRootDefinition.ExactData(name, description, accessorTypeName, dataDefinitionId, isRequired);

            return KarRootDefinition.Exact(name, description, accessorTypeName, isRequired);
        }
    }
}
