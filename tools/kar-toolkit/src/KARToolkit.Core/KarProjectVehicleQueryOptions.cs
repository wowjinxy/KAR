using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectVehicleQueryOptions
    {
        public string VehicleNameOrPath { get; set; }

        public string Family { get; set; }

        public string Text { get; set; }

        public bool? HasOutput { get; set; }

        public bool? HasModifiedOutput { get; set; }

        public bool? HasCompleteOutputSet { get; set; }

        public bool Matches(KarVehicleBundle bundle)
        {
            if (bundle == null)
                throw new ArgumentNullException(nameof(bundle));

            if (!string.IsNullOrWhiteSpace(Family) &&
                !string.Equals(bundle.Family, Family, StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }

            if (!string.IsNullOrWhiteSpace(Text) && !MatchesSearchText(bundle, Text))
                return false;

            return true;
        }

        public bool Matches(KarProjectVehicleContext context)
        {
            if (context == null)
                throw new ArgumentNullException(nameof(context));

            if (!Matches(context.Bundle))
                return false;

            if (HasOutput.HasValue && context.HasOutput != HasOutput.Value)
                return false;
            if (HasModifiedOutput.HasValue && context.HasModifiedOutput != HasModifiedOutput.Value)
                return false;
            if (HasCompleteOutputSet.HasValue && context.HasCompleteOutputSet != HasCompleteOutputSet.Value)
                return false;

            return true;
        }

        private static bool MatchesSearchText(KarVehicleBundle bundle, string text)
        {
            if (KarProjectFileQueryOptions.Contains(bundle.Name, text) ||
                KarProjectFileQueryOptions.Contains(bundle.Family, text) ||
                KarProjectFileQueryOptions.Contains(bundle.Role, text))
            {
                return true;
            }

            foreach (KarProjectFile file in bundle.Files)
            {
                if (KarProjectFileQueryOptions.MatchesSearchText(file, text))
                    return true;
            }

            return false;
        }
    }
}
