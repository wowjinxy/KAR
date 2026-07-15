using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarDataDefinitionValidationReport
    {
        internal KarDataDefinitionValidationReport(
            int definitionCount,
            IEnumerable<KarDataDefinitionValidationIssue> issues)
        {
            DefinitionCount = definitionCount;
            Issues = issues.ToList().AsReadOnly();
            Errors = Issues.Where(issue => issue.Severity == KarValidationSeverity.Error).ToList().AsReadOnly();
            Warnings = Issues.Where(issue => issue.Severity == KarValidationSeverity.Warning).ToList().AsReadOnly();
            Infos = Issues.Where(issue => issue.Severity == KarValidationSeverity.Info).ToList().AsReadOnly();
        }

        public int DefinitionCount { get; }

        public IReadOnlyList<KarDataDefinitionValidationIssue> Issues { get; }

        public IReadOnlyList<KarDataDefinitionValidationIssue> Errors { get; }

        public IReadOnlyList<KarDataDefinitionValidationIssue> Warnings { get; }

        public IReadOnlyList<KarDataDefinitionValidationIssue> Infos { get; }

        public int ErrorCount => Errors.Count;

        public int WarningCount => Warnings.Count;

        public int InfoCount => Infos.Count;

        public bool IsValid => Errors.Count == 0;
    }
}
