using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectScriptTableContextQueryOptions
    {
        public KarProjectScriptTableQueryOptions Tables { get; set; }

        public KarProjectResourceOutputStatus? OutputStatus { get; set; }

        public bool? HasOutput { get; set; }

        public bool? HasModifiedOutput { get; set; }

        public bool Matches(KarProjectScriptTableContext context)
        {
            if (context == null)
                throw new ArgumentNullException(nameof(context));

            if (Tables != null && !Tables.Matches(context.Table))
                return false;
            if (OutputStatus.HasValue && context.OutputStatus != OutputStatus.Value)
                return false;
            if (HasOutput.HasValue && context.HasOutput != HasOutput.Value)
                return false;
            if (HasModifiedOutput.HasValue && context.HasModifiedOutput != HasModifiedOutput.Value)
                return false;

            return true;
        }
    }
}
