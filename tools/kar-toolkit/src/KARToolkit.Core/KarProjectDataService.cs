using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectDataService
    {
        private readonly KarProject _project;

        internal KarProjectDataService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public KarDataDefinitionRegistry Definitions => _project.ArchiveInspector.DataDefinitions;

        public IReadOnlyList<KarProjectRootInfo> QueryRoots(KarProjectRootQueryOptions options = null)
        {
            return BuildRoots(_project.ArchiveService.QueryHsdArchives(options == null ? null : options.Files), options);
        }

        public IReadOnlyList<KarProjectRootSummary> QueryRootSummaries(KarProjectRootQueryOptions options = null)
        {
            return BuildRootSummaries(QueryRoots(options));
        }

        public IReadOnlyList<KarProjectDataDefinitionUsage> QueryDataDefinitionUsage(KarProjectRootQueryOptions options = null)
        {
            return BuildDataDefinitionUsage(QueryRoots(options));
        }

        public IReadOnlyList<KarProjectFieldInfo> QueryFieldValues(KarProjectFieldQueryOptions options = null)
        {
            return BuildFields(QueryRoots(options == null ? null : options.Roots), options);
        }

        public IReadOnlyList<KarProjectFieldSummary> QueryFieldSummaries(KarProjectFieldQueryOptions options = null)
        {
            return BuildFieldSummaries(QueryFieldValues(options));
        }

        internal static IReadOnlyList<KarProjectRootInfo> BuildRoots(
            IEnumerable<KarArchiveInfo> archives,
            KarProjectRootQueryOptions options)
        {
            if (archives == null)
                throw new ArgumentNullException(nameof(archives));

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

            return roots.AsReadOnly();
        }

        internal static IReadOnlyList<KarProjectRootSummary> BuildRootSummaries(IEnumerable<KarProjectRootInfo> roots)
        {
            if (roots == null)
                throw new ArgumentNullException(nameof(roots));

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
                .ToList()
                .AsReadOnly();
        }

        internal static IReadOnlyList<KarProjectDataDefinitionUsage> BuildDataDefinitionUsage(IEnumerable<KarProjectRootInfo> roots)
        {
            if (roots == null)
                throw new ArgumentNullException(nameof(roots));

            return roots
                .Where(root => root.Root.DataDefinition != null)
                .GroupBy(root => root.Root.DataDefinition.Id, StringComparer.OrdinalIgnoreCase)
                .Select(group => new KarProjectDataDefinitionUsage(
                    group.First().Root.DataDefinition,
                    group.OrderBy(root => root.RelativePath, StringComparer.OrdinalIgnoreCase)
                        .ThenBy(root => root.RootName, StringComparer.Ordinal)))
                .ToList()
                .AsReadOnly();
        }

        internal static IReadOnlyList<KarProjectFieldInfo> BuildFields(
            IEnumerable<KarProjectRootInfo> roots,
            KarProjectFieldQueryOptions options)
        {
            if (roots == null)
                throw new ArgumentNullException(nameof(roots));

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

        internal static IReadOnlyList<KarProjectFieldSummary> BuildFieldSummaries(IEnumerable<KarProjectFieldInfo> fields)
        {
            if (fields == null)
                throw new ArgumentNullException(nameof(fields));

            return fields
                .GroupBy(field => field.DataDefinitionId + "\u001F" + field.FieldName, StringComparer.OrdinalIgnoreCase)
                .Select(group => new KarProjectFieldSummary(
                    group.First().ArchiveRoot.DataDefinition,
                    group.First().Field,
                    group))
                .ToList()
                .AsReadOnly();
        }
    }
}
