using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceActionPlanQueryOptions
    {
        public KarProjectResourceQueryOptions Resources { get; set; }

        public string ActionId { get; set; }

        public bool? IsReadOnly { get; set; }

        public bool? WritesOutput { get; set; }

        public bool? CanRun { get; set; }

        public bool? WouldWriteOutput { get; set; }

        public bool Overwrite { get; set; }

        public bool Matches(KarProjectResourceAction action)
        {
            if (action == null)
                throw new ArgumentNullException(nameof(action));

            if (!string.IsNullOrWhiteSpace(ActionId) &&
                !string.Equals(ActionId, action.Id, StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }

            if (IsReadOnly.HasValue && action.IsReadOnly != IsReadOnly.Value)
                return false;
            if (WritesOutput.HasValue && action.WritesOutput != WritesOutput.Value)
                return false;

            return true;
        }

        public bool Matches(KarProjectResourceActionPlan plan)
        {
            if (plan == null)
                throw new ArgumentNullException(nameof(plan));
            if (!Matches(plan.Action))
                return false;
            if (CanRun.HasValue && plan.CanRun != CanRun.Value)
                return false;
            if (WouldWriteOutput.HasValue && plan.WouldWriteOutput != WouldWriteOutput.Value)
                return false;

            return true;
        }
    }
}
