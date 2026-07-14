using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarValidationReport
    {
        internal KarValidationReport(
            KarProject project,
            int hsdArchiveCount,
            int a2dPackageCount,
            IEnumerable<KarValidationIssue> issues)
        {
            Project = project;
            HsdArchiveCount = hsdArchiveCount;
            A2DPackageCount = a2dPackageCount;
            Issues = issues.ToList().AsReadOnly();
            Errors = Issues.Where(issue => issue.Severity == KarValidationSeverity.Error).ToList().AsReadOnly();
            Warnings = Issues.Where(issue => issue.Severity == KarValidationSeverity.Warning).ToList().AsReadOnly();
            Infos = Issues.Where(issue => issue.Severity == KarValidationSeverity.Info).ToList().AsReadOnly();
        }

        public KarProject Project { get; }

        public int FileCount => Project.Files.Count;

        public int MapCount => Project.Maps.Count;

        public int HsdArchiveCount { get; }

        public int A2DPackageCount { get; }

        public IReadOnlyList<KarValidationIssue> Issues { get; }

        public IReadOnlyList<KarValidationIssue> Errors { get; }

        public IReadOnlyList<KarValidationIssue> Warnings { get; }

        public IReadOnlyList<KarValidationIssue> Infos { get; }

        public bool IsValid => Errors.Count == 0;
    }
}
