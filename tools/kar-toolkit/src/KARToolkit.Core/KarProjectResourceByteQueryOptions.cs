using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceByteQueryOptions
    {
        public KarProjectResourceQueryOptions Resources { get; set; }

        public KarProjectResourceByteOutputStatus? Status { get; set; }

        public bool? HasOutput { get; set; }

        public bool Matches(KarProjectResourceByteInfo info)
        {
            if (info == null)
                throw new ArgumentNullException(nameof(info));

            if (Status.HasValue && info.Status != Status.Value)
                return false;
            if (HasOutput.HasValue && info.HasOutput != HasOutput.Value)
                return false;

            return true;
        }
    }
}
