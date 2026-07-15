using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceDataFieldQueryOptions
    {
        public KarProjectResourceQueryOptions Resources { get; set; }

        public string DataDefinitionIdOrAccessorTypeName { get; set; }

        public string FieldPathOrName { get; set; }

        public string Text { get; set; }

        public bool? IsTopLevel { get; set; }

        public bool? IsScalar { get; set; }

        public bool? IsPointer { get; set; }

        public bool? CanSetScalar { get; set; }

        public bool? IsAvailable { get; set; }

        public bool? HasReference { get; set; }

        public bool? HasError { get; set; }

        public bool Matches(KarProjectResourceDataView view, KarProjectResourceDataFieldView field)
        {
            if (view == null)
                throw new ArgumentNullException(nameof(view));
            if (field == null)
                throw new ArgumentNullException(nameof(field));

            if (!MatchesDataDefinition(view.DataDefinition))
                return false;
            if (!MatchesFieldPathOrName(field))
                return false;
            if (IsTopLevel.HasValue && field.IsTopLevel != IsTopLevel.Value)
                return false;
            if (IsScalar.HasValue && field.IsScalar != IsScalar.Value)
                return false;
            if (IsPointer.HasValue && field.IsPointer != IsPointer.Value)
                return false;
            if (CanSetScalar.HasValue && field.CanSetScalar != CanSetScalar.Value)
                return false;
            if (IsAvailable.HasValue && field.IsAvailable != IsAvailable.Value)
                return false;
            if (HasReference.HasValue &&
                (!field.HasReference.HasValue || field.HasReference.Value != HasReference.Value))
            {
                return false;
            }
            if (HasError.HasValue && field.HasError != HasError.Value)
                return false;
            if (!string.IsNullOrWhiteSpace(Text) && !MatchesSearchText(view, field, Text))
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

        private bool MatchesFieldPathOrName(KarProjectResourceDataFieldView field)
        {
            if (string.IsNullOrWhiteSpace(FieldPathOrName))
                return true;

            return string.Equals(field.FieldPath, FieldPathOrName, StringComparison.OrdinalIgnoreCase) ||
                string.Equals(field.FieldName, FieldPathOrName, StringComparison.OrdinalIgnoreCase);
        }

        internal static bool MatchesSearchText(
            KarProjectResourceDataView view,
            KarProjectResourceDataFieldView field,
            string text)
        {
            if (view == null || field == null)
                return false;

            KarDataDefinition definition = view.DataDefinition;
            KarDataFieldDefinition fieldDefinition = field.Field;

            return KarProjectFileQueryOptions.Contains(view.Address, text) ||
                KarProjectFileQueryOptions.Contains(view.DisplayName, text) ||
                KarProjectFileQueryOptions.Contains(view.Category, text) ||
                KarProjectFileQueryOptions.Contains(view.Description, text) ||
                KarProjectFileQueryOptions.Contains(view.DataDefinitionId, text) ||
                KarProjectFileQueryOptions.Contains(definition == null ? null : definition.AccessorTypeName, text) ||
                KarProjectFileQueryOptions.Contains(field.FieldPath, text) ||
                KarProjectFileQueryOptions.Contains(field.FieldName, text) ||
                KarProjectFileQueryOptions.Contains(fieldDefinition.TypeName, text) ||
                KarProjectFileQueryOptions.Contains(fieldDefinition.Description, text) ||
                KarProjectFileQueryOptions.Contains(fieldDefinition.DataDefinitionId, text) ||
                KarProjectFileQueryOptions.Contains(field.ValueKind, text) ||
                KarProjectFileQueryOptions.Contains(field.DisplayValue, text) ||
                KarProjectFileQueryOptions.Contains(field.Error, text) ||
                KarProjectFileQueryOptions.Contains(field.ReferenceDataDefinitionId, text) ||
                KarProjectFileQueryOptions.Contains(field.ReferenceDataDefinition == null ? null : field.ReferenceDataDefinition.DisplayName, text);
        }
    }
}
