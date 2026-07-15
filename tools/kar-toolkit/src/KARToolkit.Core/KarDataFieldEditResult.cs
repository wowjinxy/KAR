using System;

namespace KARToolkit.Core
{
    public sealed class KarDataFieldEditResult
    {
        public KarDataFieldEditResult(
            string rootName,
            KarDataDefinition dataDefinition,
            KarDataFieldDefinition field,
            KarDataFieldValue previousValue,
            KarDataFieldValue newValue)
        {
            RootName = rootName;
            DataDefinition = dataDefinition;
            Field = field ?? throw new ArgumentNullException(nameof(field));
            PreviousValue = previousValue ?? throw new ArgumentNullException(nameof(previousValue));
            NewValue = newValue ?? throw new ArgumentNullException(nameof(newValue));
        }

        public string RootName { get; }

        public KarDataDefinition DataDefinition { get; }

        public string DataDefinitionId => DataDefinition == null ? null : DataDefinition.Id;

        public KarDataFieldDefinition Field { get; }

        public KarDataFieldValue PreviousValue { get; }

        public KarDataFieldValue NewValue { get; }

        public bool IsChanged => !string.Equals(PreviousValue.DisplayValue, NewValue.DisplayValue, StringComparison.Ordinal);
    }
}
