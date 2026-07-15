using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectToolkitWorkflowQueryOptions
    {
        public string Id { get; set; }

        public string DomainId { get; set; }

        public string Command { get; set; }

        public string Text { get; set; }

        public bool? IsReadOnly { get; set; }

        public bool? WritesOutput { get; set; }

        public bool? SupportsBatch { get; set; }

        public bool? RequiresInputFile { get; set; }

        public bool? RequiresValue { get; set; }

        public bool? HasTargets { get; set; }

        public bool? HasOutputs { get; set; }

        public bool? HasModifiedOutputs { get; set; }

        public bool? HasInspectionIssues { get; set; }

        public bool Matches(KarProjectToolkitWorkflow workflow)
        {
            if (workflow == null)
                throw new ArgumentNullException(nameof(workflow));

            if (!string.IsNullOrWhiteSpace(Id) &&
                !string.Equals(workflow.Id, Id, StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }

            if (!MatchesDomain(workflow, DomainId))
                return false;
            if (!string.IsNullOrWhiteSpace(Command) &&
                !string.Equals(workflow.Command, Command, StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }
            if (IsReadOnly.HasValue && workflow.IsReadOnly != IsReadOnly.Value)
                return false;
            if (WritesOutput.HasValue && workflow.WritesOutput != WritesOutput.Value)
                return false;
            if (SupportsBatch.HasValue && workflow.SupportsBatch != SupportsBatch.Value)
                return false;
            if (RequiresInputFile.HasValue && workflow.RequiresInputFile != RequiresInputFile.Value)
                return false;
            if (RequiresValue.HasValue && workflow.RequiresValue != RequiresValue.Value)
                return false;
            if (HasTargets.HasValue && workflow.HasTargets != HasTargets.Value)
                return false;
            if (HasOutputs.HasValue && workflow.HasOutputs != HasOutputs.Value)
                return false;
            if (HasModifiedOutputs.HasValue && workflow.HasModifiedOutputs != HasModifiedOutputs.Value)
                return false;
            if (HasInspectionIssues.HasValue && workflow.HasInspectionIssues != HasInspectionIssues.Value)
                return false;

            return string.IsNullOrWhiteSpace(Text) || MatchesSearchText(workflow, Text);
        }

        private static bool MatchesDomain(KarProjectToolkitWorkflow workflow, string domainId)
        {
            if (string.IsNullOrWhiteSpace(domainId))
                return true;

            string normalized = NormalizeDomain(domainId);
            return normalized == "all" ||
                normalized == NormalizeDomain(workflow.DomainId) ||
                (normalized == "scripts" && NormalizeDomain(workflow.DomainId) == "script-tables") ||
                (normalized == "a2d" && NormalizeDomain(workflow.DomainId) == "a2d-packages") ||
                (normalized == "archives" && NormalizeDomain(workflow.DomainId) == "files") ||
                (normalized == "outputs" && NormalizeDomain(workflow.DomainId) == "mod-output");
        }

        private static bool MatchesSearchText(KarProjectToolkitWorkflow workflow, string text)
        {
            return KarProjectFileQueryOptions.Contains(workflow.Id, text) ||
                KarProjectFileQueryOptions.Contains(workflow.DomainId, text) ||
                KarProjectFileQueryOptions.Contains(workflow.DisplayName, text) ||
                KarProjectFileQueryOptions.Contains(workflow.Description, text) ||
                KarProjectFileQueryOptions.Contains(workflow.Command, text) ||
                KarProjectFileQueryOptions.Contains(workflow.ArgumentHint, text) ||
                KarProjectFileQueryOptions.Contains(workflow.Mode, text);
        }

        private static string NormalizeDomain(string value)
        {
            return (value ?? "").Replace("_", "-").ToLowerInvariant();
        }
    }
}
