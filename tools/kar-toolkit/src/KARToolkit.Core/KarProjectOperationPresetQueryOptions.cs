using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectOperationPresetQueryOptions
    {
        public string Id { get; set; }

        public string DomainId { get; set; }

        public string ActionId { get; set; }

        public string Text { get; set; }

        public bool? IsReadOnly { get; set; }

        public bool? WritesOutput { get; set; }

        public bool? SupportsBatch { get; set; }

        public bool? RequiresInputFile { get; set; }

        public bool? RequiresFieldName { get; set; }

        public bool? RequiresValue { get; set; }

        public bool? HasOperations { get; set; }

        public bool? HasRunnableOperations { get; set; }

        public bool? HasModifiedOutputOperations { get; set; }

        public bool Matches(KarProjectOperationPreset preset)
        {
            if (preset == null)
                throw new ArgumentNullException(nameof(preset));

            if (!string.IsNullOrWhiteSpace(Id) &&
                !string.Equals(Id, preset.Id, StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }
            if (!MatchesDomain(preset, DomainId))
                return false;
            if (!string.IsNullOrWhiteSpace(ActionId) &&
                !string.Equals(ActionId, preset.ActionId, StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }
            if (IsReadOnly.HasValue && preset.IsReadOnly != IsReadOnly.Value)
                return false;
            if (WritesOutput.HasValue && preset.WritesOutput != WritesOutput.Value)
                return false;
            if (SupportsBatch.HasValue && preset.SupportsBatch != SupportsBatch.Value)
                return false;
            if (RequiresInputFile.HasValue && preset.RequiresInputFile != RequiresInputFile.Value)
                return false;
            if (RequiresFieldName.HasValue && preset.RequiresFieldName != RequiresFieldName.Value)
                return false;
            if (RequiresValue.HasValue && preset.RequiresValue != RequiresValue.Value)
                return false;
            if (HasOperations.HasValue && preset.HasOperations != HasOperations.Value)
                return false;
            if (HasRunnableOperations.HasValue && preset.HasRunnableOperations != HasRunnableOperations.Value)
                return false;
            if (HasModifiedOutputOperations.HasValue && preset.HasModifiedOutputOperations != HasModifiedOutputOperations.Value)
                return false;

            return string.IsNullOrWhiteSpace(Text) || MatchesSearchText(preset, Text);
        }

        private static bool MatchesDomain(KarProjectOperationPreset preset, string domainId)
        {
            if (string.IsNullOrWhiteSpace(domainId))
                return true;

            string normalized = KarProjectFileQueryOptions.NormalizeDomain(domainId);
            return normalized == "all" ||
                normalized == KarProjectFileQueryOptions.NormalizeDomain(preset.DomainId);
        }

        private static bool MatchesSearchText(KarProjectOperationPreset preset, string text)
        {
            return KarProjectFileQueryOptions.Contains(preset.Id, text) ||
                KarProjectFileQueryOptions.Contains(preset.DomainId, text) ||
                KarProjectFileQueryOptions.Contains(preset.DisplayName, text) ||
                KarProjectFileQueryOptions.Contains(preset.Description, text) ||
                KarProjectFileQueryOptions.Contains(preset.ActionId, text) ||
                KarProjectFileQueryOptions.Contains(preset.Mode, text) ||
                KarProjectFileQueryOptions.Contains(preset.OperationUsage, text) ||
                KarProjectFileQueryOptions.Contains(preset.BatchUsage, text);
        }
    }
}
