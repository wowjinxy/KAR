using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceFieldQueryOptions
    {
        public KarProjectResourceQueryOptions Resources { get; set; }

        public string DataDefinitionIdOrAccessorTypeName { get; set; }

        public string FieldName { get; set; }

        public string Text { get; set; }

        public bool? IsAvailable { get; set; }

        public bool Matches(KarProjectResourceFieldInfo field)
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
            if (!string.IsNullOrWhiteSpace(Text) && !KarProjectFieldQueryOptions.MatchesSearchText(field.FieldInfo, Text))
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
