using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectMapOutputQueryOptions
    {
        public KarProjectOutputFileQueryOptions Outputs { get; set; }

        public string MapName { get; set; }

        public bool? HasOutput { get; set; }

        public bool? HasModifiedOutput { get; set; }

        public bool? HasCompleteOutputSet { get; set; }

        public bool Matches(KarProjectMapOutputInfo mapOutput)
        {
            if (mapOutput == null)
                throw new ArgumentNullException(nameof(mapOutput));

            if (!string.IsNullOrWhiteSpace(MapName) &&
                !string.Equals(mapOutput.Name, MapName, StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }

            if (HasOutput.HasValue && mapOutput.HasOutput != HasOutput.Value)
                return false;

            if (HasModifiedOutput.HasValue && mapOutput.HasModifiedOutput != HasModifiedOutput.Value)
                return false;

            if (HasCompleteOutputSet.HasValue && mapOutput.HasCompleteOutputSet != HasCompleteOutputSet.Value)
                return false;

            return true;
        }
    }
}
