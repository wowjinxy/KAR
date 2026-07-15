using System;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarDataDefinitionQueryOptions
    {
        public string Id { get; set; }

        public string AccessorTypeName { get; set; }

        public string Category { get; set; }

        public string Text { get; set; }

        public bool? HasFields { get; set; }

        public bool Matches(KarDataDefinition definition)
        {
            if (definition == null)
                throw new ArgumentNullException(nameof(definition));

            if (!string.IsNullOrWhiteSpace(Id) &&
                !string.Equals(definition.Id, Id, StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }

            if (!string.IsNullOrWhiteSpace(AccessorTypeName) &&
                !string.Equals(definition.AccessorTypeName, AccessorTypeName, StringComparison.Ordinal))
            {
                return false;
            }

            if (!string.IsNullOrWhiteSpace(Category) &&
                !string.Equals(definition.Category, Category, StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }

            if (HasFields.HasValue && (definition.Fields.Count != 0) != HasFields.Value)
                return false;

            if (!string.IsNullOrWhiteSpace(Text) && !MatchesText(definition, Text))
                return false;

            return true;
        }

        private static bool MatchesText(KarDataDefinition definition, string text)
        {
            return Contains(definition.Id, text) ||
                Contains(definition.DisplayName, text) ||
                Contains(definition.Category, text) ||
                Contains(definition.AccessorTypeName, text) ||
                Contains(definition.Description, text) ||
                Contains(definition.Source, text) ||
                definition.Fields.Any(field => MatchesText(field, text));
        }

        private static bool MatchesText(KarDataFieldDefinition field, string text)
        {
            return Contains(field.Name, text) ||
                Contains(field.TypeName, text) ||
                Contains(field.Description, text) ||
                Contains(field.DataDefinitionId, text);
        }

        private static bool Contains(string value, string text)
        {
            return value != null &&
                value.IndexOf(text, StringComparison.OrdinalIgnoreCase) >= 0;
        }
    }
}
