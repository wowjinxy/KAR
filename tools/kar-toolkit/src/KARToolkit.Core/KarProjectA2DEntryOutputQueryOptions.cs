using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectA2DEntryOutputQueryOptions
    {
        public KarProjectA2DEntryQueryOptions Entries { get; set; }

        public KarProjectA2DEntryOutputStatus? Status { get; set; }

        public bool? HasOutput { get; set; }

        public bool Matches(KarProjectA2DEntryOutputInfo output)
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
