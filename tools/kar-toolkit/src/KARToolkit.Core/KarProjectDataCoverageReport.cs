using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectDataCoverageReport
    {
        internal KarProjectDataCoverageReport(KarProject project, KarProjectDataCoverageOptions options)
        {
            Project = project ?? throw new ArgumentNullException(nameof(project));
            Options = options ?? new KarProjectDataCoverageOptions();
            ArchiveContexts = project.ArchiveContextService.Query(Options.Archives)
                .OrderBy(context => context.Category, StringComparer.OrdinalIgnoreCase)
                .ThenBy(context => context.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
            Issues = BuildIssues(ArchiveContexts, Options)
                .Where(Options.MatchesIssue)
                .OrderBy(issue => issue.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ThenBy(issue => issue.RootName ?? issue.MissingRootPattern ?? "", StringComparer.Ordinal)
                .ThenBy(issue => issue.Kind)
                .ToList()
                .AsReadOnly();
        }

        public KarProject Project { get; }

        public KarProjectDataCoverageOptions Options { get; }

        public IReadOnlyList<KarProjectArchiveContext> ArchiveContexts { get; }

        public IReadOnlyList<KarProjectDataCoverageIssue> Issues { get; }

        public int ArchiveCount => ArchiveContexts.Count;

        public int InspectableArchiveCount => ArchiveContexts.Count(context => context.HasInspection);

        public int InspectionErrorCount => ArchiveContexts.Count(context => context.HasInspectionError);

        public int RootCount => ArchiveContexts.Sum(context => context.RootCount);

        public int KnownRootCount => ArchiveContexts.Sum(context => context.KnownRootCount);

        public int UnknownRootCount => ArchiveContexts.Sum(context => context.UnknownRootCount);

        public int MissingRequiredRootCount => ArchiveContexts.Sum(context => context.MissingRequiredRootCount);

        public int DataDefinitionRootCount => ArchiveContexts.Sum(context => context.Roots.Count(root => root.DataDefinition != null));

        public int MissingDataDefinitionRootCount => ArchiveContexts.Sum(context => context.Roots.Count(root => root.IsKnown && root.DataDefinition == null));

        public int FieldBackedRootCount => ArchiveContexts.Sum(context => context.Roots.Count(root => root.DataDefinition != null && root.HasFieldValues));

        public int MissingFieldValueRootCount => ArchiveContexts.Sum(context => context.Roots.Count(NeedsFieldValues));

        public int IssueCount => Issues.Count;

        public int ArchiveInspectionIssueCount => CountIssues(KarProjectDataCoverageIssueKind.ArchiveInspectionFailed);

        public int MissingRequiredRootIssueCount => CountIssues(KarProjectDataCoverageIssueKind.MissingRequiredRoot);

        public int UnknownRootIssueCount => CountIssues(KarProjectDataCoverageIssueKind.UnknownRoot);

        public int MissingDataDefinitionIssueCount => CountIssues(KarProjectDataCoverageIssueKind.MissingDataDefinition);

        public int MissingFieldValueIssueCount => CountIssues(KarProjectDataCoverageIssueKind.MissingFieldValues);

        public bool HasIssues => IssueCount != 0;

        public bool HasCompleteFieldCoverage =>
            InspectionErrorCount == 0 &&
            UnknownRootCount == 0 &&
            MissingDataDefinitionRootCount == 0 &&
            MissingFieldValueRootCount == 0;

        private int CountIssues(KarProjectDataCoverageIssueKind kind)
        {
            return Issues.Count(issue => issue.Kind == kind);
        }

        private static IReadOnlyList<KarProjectDataCoverageIssue> BuildIssues(
            IEnumerable<KarProjectArchiveContext> contexts,
            KarProjectDataCoverageOptions options)
        {
            List<KarProjectDataCoverageIssue> issues = new List<KarProjectDataCoverageIssue>();

            foreach (KarProjectArchiveContext context in contexts)
            {
                if (options.ReportInspectionErrors && context.HasInspectionError)
                {
                    issues.Add(new KarProjectDataCoverageIssue(
                        KarProjectDataCoverageIssueKind.ArchiveInspectionFailed,
                        "Archive could not be inspected: " + context.InspectionError,
                        context.File,
                        null,
                        null));
                }

                if (options.ReportMissingRequiredRoots)
                {
                    foreach (KarRootDefinition missing in context.MissingRequiredRoots)
                    {
                        issues.Add(new KarProjectDataCoverageIssue(
                            KarProjectDataCoverageIssueKind.MissingRequiredRoot,
                            "Missing required root: " + missing.Pattern,
                            context.File,
                            null,
                            missing));
                    }
                }

                foreach (KarArchiveRootInfo root in context.Roots)
                {
                    if (options.ReportUnknownRoots && !root.IsKnown)
                    {
                        issues.Add(new KarProjectDataCoverageIssue(
                            KarProjectDataCoverageIssueKind.UnknownRoot,
                            "Unknown HSD root: " + root.Name,
                            context.File,
                            root,
                            null));
                        continue;
                    }

                    if (options.ReportMissingDataDefinitions && root.IsKnown && root.DataDefinition == null)
                    {
                        issues.Add(new KarProjectDataCoverageIssue(
                            KarProjectDataCoverageIssueKind.MissingDataDefinition,
                            "Known root has no KAR data definition: " + root.Name,
                            context.File,
                            root,
                            null));
                        continue;
                    }

                    if (options.ReportMissingFieldValues && NeedsFieldValues(root))
                    {
                        issues.Add(new KarProjectDataCoverageIssue(
                            KarProjectDataCoverageIssueKind.MissingFieldValues,
                            "Root has a KAR data definition but no labeled field values: " + root.Name,
                            context.File,
                            root,
                            null));
                    }
                }
            }

            return issues.AsReadOnly();
        }

        private static bool NeedsFieldValues(KarArchiveRootInfo root)
        {
            return root.DataDefinition != null &&
                root.DataDefinition.Fields.Count != 0 &&
                !root.HasFieldValues;
        }
    }
}
