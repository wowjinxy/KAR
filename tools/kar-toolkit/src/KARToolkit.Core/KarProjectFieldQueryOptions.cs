using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectFieldQueryOptions
    {
        public KarProjectRootQueryOptions Roots { get; set; }

        public string DataDefinitionIdOrAccessorTypeName { get; set; }

        public string FieldName { get; set; }

        public string Text { get; set; }

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
            if (!string.IsNullOrWhiteSpace(Text) && !MatchesSearchText(field, Text))
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

        internal static bool MatchesSearchText(KarProjectFieldInfo field, string text)
        {
            if (field == null)
                return false;

            KarDataDefinition definition = field.ArchiveRoot.DataDefinition;
            KarDataFieldDefinition fieldDefinition = field.Field;
            KarDataFieldValue value = field.Value;

            return Contains(field.RelativePath, text) ||
                Contains(field.RootName, text) ||
                Contains(field.Root.DisplayName, text) ||
                Contains(field.Root.Role, text) ||
                Contains(field.Root.Category, text) ||
                Contains(field.Root.Description, text) ||
                Contains(field.DataDefinitionId, text) ||
                Contains(definition == null ? null : definition.DisplayName, text) ||
                Contains(definition == null ? null : definition.AccessorTypeName, text) ||
                Contains(definition == null ? null : definition.Description, text) ||
                Contains(fieldDefinition.Name, text) ||
                Contains(fieldDefinition.TypeName, text) ||
                Contains(fieldDefinition.Description, text) ||
                Contains(fieldDefinition.DataDefinitionId, text) ||
                Contains(value.ValueKind, text) ||
                Contains(value.DisplayValue, text) ||
                Contains(value.Error, text) ||
                Contains(value.ReferenceDataDefinitionId, text) ||
                Contains(value.ReferenceDataDefinition == null ? null : value.ReferenceDataDefinition.DisplayName, text);
        }

        private static bool Contains(string value, string text)
        {
            return value != null &&
                value.IndexOf(text, StringComparison.OrdinalIgnoreCase) >= 0;
        }
    }
}
