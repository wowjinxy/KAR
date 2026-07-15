using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectReport
    {
        internal KarProjectReport(KarProject project, KarProjectReportOptions options)
        {
            Project = project ?? throw new ArgumentNullException(nameof(project));
            options = options ?? new KarProjectReportOptions();

            Files = project.QueryFiles(options.Files)
                .OrderBy(file => file.Category, StringComparer.OrdinalIgnoreCase)
                .ThenBy(file => file.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
            FileCategories = BuildFileGroups(Files, file => file.Category);
            FileKinds = BuildFileGroups(Files, file => file.Kind.ToString());
            OutputFiles = project.QueryOutputFiles(options.OutputFiles);
            OutputInventory = new KarProjectOutputInventory(project, OutputFiles);
            Maps = project.Maps
                .OrderBy(map => map.Name, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
            Archives = BuildArchives(project, Files);
            Roots = BuildRoots(Archives, options.Roots);
            RootSummaries = BuildRootSummaries(Roots);
            DataDefinitionUsage = BuildDataDefinitionUsage(Roots);
            FieldSummaries = options.IncludeFieldSummaries
                ? BuildFieldSummaries(BuildFields(Roots, options.Fields))
                : Array.Empty<KarProjectFieldSummary>();
        }

        public KarProject Project { get; }

        public IReadOnlyList<KarProjectFile> Files { get; }

        public IReadOnlyList<KarProjectFileGroupSummary> FileCategories { get; }

        public IReadOnlyList<KarProjectFileGroupSummary> FileKinds { get; }

        public IReadOnlyList<KarProjectOutputFileInfo> OutputFiles { get; }

        public KarProjectOutputInventory OutputInventory { get; }

        public IReadOnlyList<KarMapBundle> Maps { get; }

        public IReadOnlyList<KarArchiveInfo> Archives { get; }

        public IReadOnlyList<KarProjectRootInfo> Roots { get; }

        public IReadOnlyList<KarProjectRootSummary> RootSummaries { get; }

        public IReadOnlyList<KarProjectDataDefinitionUsage> DataDefinitionUsage { get; }

        public IReadOnlyList<KarProjectFieldSummary> FieldSummaries { get; }

        public int FileCount => Files.Count;

        public int OutputFileCount => OutputInventory.Count;

        public int ProjectOutputFileCount => OutputInventory.ProjectFileCount;

        public int OrphanOutputFileCount => OutputInventory.OrphanFileCount;

        public int MapCount => Maps.Count;

        public int CompleteMapCount => Maps.Count(map => map.HasDataFile && map.HasModelFile && map.HasScriptFile);

        public int IncompleteMapCount => MapCount - CompleteMapCount;

        public int HsdArchiveCount => Archives.Count;

        public int A2DPackageCount => Files.Count(file => file.Kind == KarFileKind.A2dPackage);

        public int RootCount => Roots.Count;

        public int KnownRootCount => Roots.Count(root => root.IsKnown);

        public int UnknownRootCount => RootCount - KnownRootCount;

        public int MissingRequiredRootCount => Archives.Sum(archive => archive.MissingRequiredRoots.Count);

        public int DataDefinitionUsageCount => DataDefinitionUsage.Count;

        public int FieldSummaryCount => FieldSummaries.Count;

        public bool HasFieldSummaries => FieldSummaries.Count != 0;

        private static IReadOnlyList<KarProjectFileGroupSummary> BuildFileGroups(
            IEnumerable<KarProjectFile> files,
            Func<KarProjectFile, string> keySelector)
        {
            return files
                .GroupBy(keySelector, StringComparer.OrdinalIgnoreCase)
                .Select(group => new KarProjectFileGroupSummary(group.Key, group))
                .OrderBy(group => group.Name, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        private static IReadOnlyList<KarArchiveInfo> BuildArchives(KarProject project, IEnumerable<KarProjectFile> files)
        {
            return files
                .Where(file => project.FileCatalog.IsHsdArchiveKind(file.Kind))
                .Select(file => project.ArchiveInspector.Inspect(file))
                .OrderBy(archive => archive.File.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        private static IReadOnlyList<KarProjectRootInfo> BuildRoots(
            IEnumerable<KarArchiveInfo> archives,
            KarProjectRootQueryOptions options)
        {
            List<KarProjectRootInfo> roots = new List<KarProjectRootInfo>();

            foreach (KarArchiveInfo archive in archives)
            {
                if (options != null && options.Files != null && !options.Files.Matches(archive.File))
                    continue;

                foreach (KarArchiveRootInfo root in archive.Roots)
                {
                    KarProjectRootInfo projectRoot = new KarProjectRootInfo(archive.File, root);
                    if (options == null || options.Matches(projectRoot))
                        roots.Add(projectRoot);
                }
            }

            return roots
                .OrderBy(root => root.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ThenBy(root => root.RootName, StringComparer.Ordinal)
                .ToList()
                .AsReadOnly();
        }

        private static IReadOnlyList<KarProjectRootSummary> BuildRootSummaries(IEnumerable<KarProjectRootInfo> roots)
        {
            return roots
                .GroupBy(root => new
                {
                    root.RootName,
                    root.IsKnown,
                    root.DisplayAccessorTypeName,
                    root.DataDefinitionId,
                })
                .Select(group => new KarProjectRootSummary(
                    group.Key.RootName,
                    group.Key.IsKnown,
                    group.Key.DisplayAccessorTypeName,
                    group.Key.DataDefinitionId,
                    group.OrderBy(root => root.RelativePath, StringComparer.OrdinalIgnoreCase)))
                .OrderByDescending(summary => summary.Count)
                .ThenBy(summary => summary.RootName, StringComparer.Ordinal)
                .ToList()
                .AsReadOnly();
        }

        private static IReadOnlyList<KarProjectDataDefinitionUsage> BuildDataDefinitionUsage(IEnumerable<KarProjectRootInfo> roots)
        {
            return roots
                .Where(root => root.Root.DataDefinition != null)
                .GroupBy(root => root.Root.DataDefinition.Id, StringComparer.OrdinalIgnoreCase)
                .Select(group => new KarProjectDataDefinitionUsage(
                    group.First().Root.DataDefinition,
                    group.OrderBy(root => root.RelativePath, StringComparer.OrdinalIgnoreCase)
                        .ThenBy(root => root.RootName, StringComparer.Ordinal)))
                .OrderByDescending(usage => usage.Count)
                .ThenBy(usage => usage.DataDefinitionId, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        private static IReadOnlyList<KarProjectFieldInfo> BuildFields(
            IEnumerable<KarProjectRootInfo> roots,
            KarProjectFieldQueryOptions options)
        {
            List<KarProjectFieldInfo> fields = new List<KarProjectFieldInfo>();

            foreach (KarProjectRootInfo root in roots)
            {
                if (options != null && options.Roots != null)
                {
                    if (options.Roots.Files != null && !options.Roots.Files.Matches(root.File))
                        continue;
                    if (!options.Roots.Matches(root))
                        continue;
                }

                if (root.Root.DataDefinition == null || !root.Root.HasFieldValues)
                    continue;

                foreach (KarDataFieldValue value in root.Root.FieldValues)
                {
                    KarProjectFieldInfo field = new KarProjectFieldInfo(root, value);
                    if (options == null || options.Matches(field))
                        fields.Add(field);
                }
            }

            return fields.AsReadOnly();
        }

        private static IReadOnlyList<KarProjectFieldSummary> BuildFieldSummaries(IEnumerable<KarProjectFieldInfo> fields)
        {
            return fields
                .GroupBy(field => field.DataDefinitionId + "\u001F" + field.FieldName, StringComparer.OrdinalIgnoreCase)
                .Select(group => new KarProjectFieldSummary(
                    group.First().ArchiveRoot.DataDefinition,
                    group.First().Field,
                    group))
                .OrderByDescending(summary => summary.Count)
                .ThenByDescending(summary => summary.DistinctValueCount)
                .ThenBy(summary => summary.DataDefinitionId, StringComparer.OrdinalIgnoreCase)
                .ThenBy(summary => summary.Field.Offset ?? int.MaxValue)
                .ThenBy(summary => summary.FieldName, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }
    }
}
