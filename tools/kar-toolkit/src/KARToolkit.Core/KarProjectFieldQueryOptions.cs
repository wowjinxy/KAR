using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectFieldQueryOptions
    {
        public KarProjectRootQueryOptions Roots { get; set; }

        public string DataDefinitionIdOrAccessorTypeName { get; set; }

        public string FieldName { get; set; }

        public bool? IsAvailable { get; set; }

        public bool Matches(KarProjectFieldInfo field)
        {
            if (field == null)
                throw new ArgumentNullException(nameof(field));

            if (!MatchesDataDefinition(field.ArchiveRoot.DataDefinition))
                return false;

            if (!string.IsNullOrWhiteSpace(FieldName) &&
                !string.Equals(field.FieldName, FieldName, StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }

            if (IsAvailable.HasValue && field.Value.IsAvailable != IsAvailable.Value)
                return false;

            return true;
        }

        private bool MatchesDataDefinition(KarDataDefinition definition)
        {
            if (string.IsNullOrWhiteSpace(DataDefinitionIdOrAccessorTypeName))
                return true;

            if (definition == null)
                return false;

            return string.Equals(definition.Id, DataDefinitionIdOrAccessorTypeName, StringComparison.OrdinalIgnoreCase) ||
                string.Equals(definition.AccessorTypeName, DataDefinitionIdOrAccessorTypeName, StringComparison.Ordinal);
        }
    }
}
