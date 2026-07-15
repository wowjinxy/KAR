using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectDataCoverageOptions
    {
        public KarProjectArchiveContextQueryOptions Archives { get; set; }

        public KarProjectDataCoverageIssueKind? IssueKind { get; set; }

        public string Text { get; set; }

        public bool ReportInspectionErrors { get; set; } = true;

        public bool ReportMissingRequiredRoots { get; set; } = true;

        public bool ReportUnknownRoots { get; set; } = true;

        public bool ReportMissingDataDefinitions { get; set; } = true;

        public bool ReportMissingFieldValues { get; set; } = true;

        internal bool MatchesIssue(KarProjectDataCoverageIssue issue)
        {
            if (issue == null)
                throw new ArgumentNullException(nameof(issue));

            if (IssueKind.HasValue && issue.Kind != IssueKind.Value)
                return false;
            if (!string.IsNullOrWhiteSpace(Text) && !MatchesSearchText(issue, Text))
                return false;

            return true;
        }

        private static bool MatchesSearchText(KarProjectDataCoverageIssue issue, string text)
        {
            return KarProjectFileQueryOptions.MatchesSearchText(issue.File, text) ||
                KarProjectFileQueryOptions.Contains(issue.Code, text) ||
                KarProjectFileQueryOptions.Contains(issue.Message, text) ||
                KarProjectFileQueryOptions.Contains(issue.RelativePath, text) ||
                KarProjectFileQueryOptions.Contains(issue.RootName, text) ||
                KarProjectFileQueryOptions.Contains(issue.MissingRootPattern, text) ||
                KarProjectFileQueryOptions.Contains(issue.AccessorTypeName, text) ||
                KarProjectFileQueryOptions.Contains(issue.ExpectedAccessorTypeName, text) ||
                KarProjectFileQueryOptions.Contains(issue.DisplayAccessorTypeName, text) ||
                KarProjectFileQueryOptions.Contains(issue.DataDefinitionId, text) ||
                KarProjectFileQueryOptions.Contains(issue.Category, text);
        }
    }
}
