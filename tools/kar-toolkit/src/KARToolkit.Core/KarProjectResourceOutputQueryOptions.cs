using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceOutputQueryOptions
    {
        public KarProjectResourceQueryOptions Resources { get; set; }

        public KarProjectResourceOutputStatus? Status { get; set; }

        public bool? HasOutput { get; set; }

        public bool Matches(KarProjectResourceOutputInfo output)
        {
            if (output == null)
                throw new ArgumentNullException(nameof(output));

            if (Status.HasValue && output.Status != Status.Value)
                return false;
            if (HasOutput.HasValue && output.HasOutput != HasOutput.Value)
                return false;

            return true;
        }
    }
}
