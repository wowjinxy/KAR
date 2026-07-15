using System;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceDataFieldEditInfo
    {
        internal KarProjectResourceDataFieldEditInfo(KarProjectResourceDataFieldView field)
        {
            Field = field ?? throw new ArgumentNullException(nameof(field));
        }

        public KarProjectResourceDataFieldView Field { get; }

        public KarProjectResourceInfo Resource => Field.Resource;

        public KarResourceReference Reference => Field.Reference;

        public string Address => Field.Address;

        public string FieldName => Field.FieldName;

        public string FieldPath => Field.FieldPath;

        public KarProjectResourceAction Action => Resource.Actions
            .FirstOrDefault(action => string.Equals(action.Id, ActionId, StringComparison.OrdinalIgnoreCase));

        public string ActionId => "set-scalar";

        public string Command => Action == null ? "set-resource-scalar" : Action.Command;

        public string DisplayName => Action == null ? "Set Scalar" : Action.DisplayName;

        public string Description => Action == null ? "Edit an HSD root scalar field in the output folder." : Action.Description;

        public string ArgumentHint => Action == null ? "<resource-address> <field-name> <value>" : Action.ArgumentHint;

        public bool CanRun => Field.CanSetScalar;

        public bool WritesOutput => true;

        public bool RequiresValue => true;

        public KarProjectResourceActionExecutionOptions CreateExecutionOptions(string value)
        {
            return new KarProjectResourceActionExecutionOptions
            {
                FieldName = FieldName,
                Value = value,
            };
        }
    }
}
