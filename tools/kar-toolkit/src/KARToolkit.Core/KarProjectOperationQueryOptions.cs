using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectOperationQueryOptions
    {
        public bool IncludeWorkflows { get; set; } = true;

        public bool IncludeResourceActions { get; set; } = true;

        public KarProjectOperationKind? Kind { get; set; }

        public string Id { get; set; }

        public string DomainId { get; set; }

        public string Command { get; set; }

        public string ActionId { get; set; }

        public string ResourceAddress { get; set; }

        public KarResourceKind? ResourceKind { get; set; }

        public string Text { get; set; }

        public bool? IsReadOnly { get; set; }

        public bool? WritesOutput { get; set; }

        public bool? SupportsBatch { get; set; }

        public bool? RequiresInputFile { get; set; }

        public bool? RequiresFieldName { get; set; }

        public bool? RequiresValue { get; set; }

        public bool? HasTargets { get; set; }

        public bool? HasOutputs { get; set; }

        public bool? HasModifiedOutputs { get; set; }

        public bool? HasInspectionIssues { get; set; }

        public bool? CanRun { get; set; }

        public bool? WouldWriteOutput { get; set; }

        public bool Overwrite { get; set; }

        public KarProjectToolkitSnapshotOptions SnapshotOptions { get; set; }

        public bool Matches(KarProjectOperation operation)
        {
            if (operation == null)
                throw new ArgumentNullException(nameof(operation));

            if (Kind.HasValue && operation.Kind != Kind.Value)
                return false;
            if (!string.IsNullOrWhiteSpace(Id) &&
                !string.Equals(Id, operation.Id, StringComparison.OrdinalIgnoreCase) &&
                !string.Equals(Id, StripKindPrefix(operation.Id), StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }
            if (!MatchesDomain(operation, DomainId))
                return false;
            if (!string.IsNullOrWhiteSpace(Command) &&
                !string.Equals(Command, operation.Command, StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }
            if (!string.IsNullOrWhiteSpace(ActionId) &&
                !string.Equals(ActionId, operation.ActionId, StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }
            if (!string.IsNullOrWhiteSpace(ResourceAddress) &&
                !string.Equals(ResourceAddress, operation.ResourceAddress, StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }
            if (ResourceKind.HasValue && operation.ResourceKind != ResourceKind.Value)
                return false;
            if (IsReadOnly.HasValue && operation.IsReadOnly != IsReadOnly.Value)
                return false;
            if (WritesOutput.HasValue && operation.WritesOutput != WritesOutput.Value)
                return false;
            if (SupportsBatch.HasValue && operation.SupportsBatch != SupportsBatch.Value)
                return false;
            if (RequiresInputFile.HasValue && operation.RequiresInputFile != RequiresInputFile.Value)
                return false;
            if (RequiresFieldName.HasValue && operation.RequiresFieldName != RequiresFieldName.Value)
                return false;
            if (RequiresValue.HasValue && operation.RequiresValue != RequiresValue.Value)
                return false;
            if (HasTargets.HasValue && operation.HasTargets != HasTargets.Value)
                return false;
            if (HasOutputs.HasValue && operation.HasOutputs != HasOutputs.Value)
                return false;
            if (HasModifiedOutputs.HasValue && operation.HasModifiedOutputs != HasModifiedOutputs.Value)
                return false;
            if (HasInspectionIssues.HasValue && operation.HasInspectionIssues != HasInspectionIssues.Value)
                return false;
            if (CanRun.HasValue && operation.CanRun.GetValueOrDefault() != CanRun.Value)
                return false;
            if (WouldWriteOutput.HasValue && operation.WouldWriteOutput.GetValueOrDefault() != WouldWriteOutput.Value)
                return false;

            return string.IsNullOrWhiteSpace(Text) || MatchesSearchText(operation, Text);
        }

        internal KarProjectResourceActionPlanQueryOptions CreateResourceActionPlanQuery()
        {
            return new KarProjectResourceActionPlanQueryOptions
            {
                Resources = new KarProjectResourceQueryOptions
                {
                    Address = ResourceAddress,
                    Domain = DomainId,
                    Kind = ResourceKind,
                },
                ActionId = ActionId,
                IsReadOnly = IsReadOnly,
                WritesOutput = WritesOutput,
                CanRun = CanRun,
                WouldWriteOutput = WouldWriteOutput,
                Overwrite = Overwrite,
            };
        }

        private static bool MatchesDomain(KarProjectOperation operation, string domainId)
        {
            if (string.IsNullOrWhiteSpace(domainId))
                return true;

            string normalized = KarProjectFileQueryOptions.NormalizeDomain(domainId);
            return normalized == "all" ||
                normalized == NormalizeOperationDomain(operation.DomainId) ||
                normalized == NormalizeOperationDomain(operation.TargetDomainId);
        }

        private static string NormalizeOperationDomain(string domainId)
        {
            return string.IsNullOrWhiteSpace(domainId)
                ? null
                : KarProjectFileQueryOptions.NormalizeDomain(domainId);
        }

        private static bool MatchesSearchText(KarProjectOperation operation, string text)
        {
            return KarProjectFileQueryOptions.Contains(operation.Id, text) ||
                KarProjectFileQueryOptions.Contains(operation.DomainId, text) ||
                KarProjectFileQueryOptions.Contains(operation.TargetDomainId, text) ||
                KarProjectFileQueryOptions.Contains(operation.DisplayName, text) ||
                KarProjectFileQueryOptions.Contains(operation.Description, text) ||
                KarProjectFileQueryOptions.Contains(operation.Command, text) ||
                KarProjectFileQueryOptions.Contains(operation.ArgumentHint, text) ||
                KarProjectFileQueryOptions.Contains(operation.CommandLine, text) ||
                KarProjectFileQueryOptions.Contains(operation.Usage, text) ||
                KarProjectFileQueryOptions.Contains(operation.JsonUsage, text) ||
                KarProjectFileQueryOptions.Contains(operation.Mode, text) ||
                KarProjectFileQueryOptions.Contains(operation.ResourceAddress, text) ||
                KarProjectFileQueryOptions.Contains(operation.ActionId, text) ||
                KarProjectFileQueryOptions.Contains(operation.OutputRelativePath, text) ||
                KarProjectFileQueryOptions.Contains(operation.Reason, text);
        }

        private static string StripKindPrefix(string id)
        {
            int separator = id == null ? -1 : id.IndexOf(':');
            return separator < 0 ? id : id.Substring(separator + 1);
        }
    }
}
