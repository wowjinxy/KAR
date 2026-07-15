using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectDataCoverageIssueGroup
    {
        internal KarProjectDataCoverageIssueGroup(
            KarProjectDataCoverageIssueKind kind,
            string key,
            string displayName,
            string category,
            string accessorTypeName,
            string expectedAccessorTypeName,
            string displayAccessorTypeName,
            string dataDefinitionId,
            IEnumerable<KarProjectDataCoverageIssue> issues)
        {
            Kind = kind;
            Key = key ?? throw new ArgumentNullException(nameof(key));
            DisplayName = displayName ?? throw new ArgumentNullException(nameof(displayName));
            Category = category;
            AccessorTypeName = accessorTypeName;
            ExpectedAccessorTypeName = expectedAccessorTypeName;
            DisplayAccessorTypeName = displayAccessorTypeName;
            DataDefinitionId = dataDefinitionId;
            Issues = (issues ?? throw new ArgumentNullException(nameof(issues)))
                .OrderBy(issue => issue.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ThenBy(issue => issue.RootName ?? issue.MissingRootPattern ?? "", StringComparer.Ordinal)
                .ToList()
                .AsReadOnly();
            Files = Issues
                .GroupBy(issue => issue.RelativePath, StringComparer.OrdinalIgnoreCase)
                .Select(group => group.First().File)
                .OrderBy(file => file.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
            RootNames = Issues
                .Select(issue => issue.RootName)
                .Where(value => !string.IsNullOrEmpty(value))
                .Distinct(StringComparer.Ordinal)
                .OrderBy(value => value, StringComparer.Ordinal)
                .ToList()
                .AsReadOnly();
            MissingRootPatterns = Issues
                .Select(issue => issue.MissingRootPattern)
                .Where(value => !string.IsNullOrEmpty(value))
                .Distinct(StringComparer.Ordinal)
                .OrderBy(value => value, StringComparer.Ordinal)
                .ToList()
                .AsReadOnly();
        }

        public KarProjectDataCoverageIssueKind Kind { get; }

        public string Code => Kind.ToString();

        public string Key { get; }

        public string DisplayName { get; }

        public string Category { get; }

        public string AccessorTypeName { get; }

        public string ExpectedAccessorTypeName { get; }

        public string DisplayAccessorTypeName { get; }

        public string DataDefinitionId { get; }

        public IReadOnlyList<KarProjectDataCoverageIssue> Issues { get; }

        public IReadOnlyList<KarProjectFile> Files { get; }

        public IReadOnlyList<string> RootNames { get; }

        public IReadOnlyList<string> MissingRootPatterns { get; }

        public int Count => Issues.Count;

        public int FileCount => Files.Count;

        public int RootNameCount => RootNames.Count;

        public int MissingRootPatternCount => MissingRootPatterns.Count;
    }
}
