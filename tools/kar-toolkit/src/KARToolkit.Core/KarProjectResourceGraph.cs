using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceGraph
    {
        private readonly Dictionary<string, KarProjectResourceInfo> _resourcesByAddress;

        private KarProjectResourceGraph(
            KarProject project,
            IReadOnlyList<KarProjectResourceInfo> resources,
            IReadOnlyList<KarProjectRelationship> relationships)
        {
            Project = project ?? throw new ArgumentNullException(nameof(project));
            Resources = resources ?? throw new ArgumentNullException(nameof(resources));
            Relationships = relationships ?? throw new ArgumentNullException(nameof(relationships));
            _resourcesByAddress = new Dictionary<string, KarProjectResourceInfo>(StringComparer.OrdinalIgnoreCase);

            foreach (KarProjectResourceInfo resource in resources)
            {
                if (!_resourcesByAddress.ContainsKey(resource.Address))
                    _resourcesByAddress.Add(resource.Address, resource);
            }
        }

        public KarProject Project { get; }

        public IReadOnlyList<KarProjectResourceInfo> Resources { get; }

        public IReadOnlyList<KarProjectRelationship> Relationships { get; }

        public IReadOnlyDictionary<string, KarProjectResourceInfo> ResourcesByAddress => _resourcesByAddress;

        public int ResourceCount => Resources.Count;

        public int FileCount => Resources.Count(resource => resource.Kind == KarResourceKind.File);

        public int HsdRootCount => Resources.Count(resource => resource.Kind == KarResourceKind.HsdRoot);

        public int A2DEntryCount => Resources.Count(resource => resource.Kind == KarResourceKind.A2DEntry);

        public int RelationshipCount => Relationships.Count;

        public static KarProjectResourceGraph Build(KarProject project)
        {
            if (project == null)
                throw new ArgumentNullException(nameof(project));

            return new KarProjectResourceGraph(
                project,
                BuildResources(project),
                BuildRelationships(project));
        }

        public IReadOnlyList<KarProjectResourceInfo> QueryResources(KarProjectResourceQueryOptions options = null)
        {
            if (options != null && !string.IsNullOrWhiteSpace(options.Address))
            {
                KarProjectResourceInfo resource;
                if (!TryGetResource(options.Address, out resource) || !MatchesResourceQuery(resource, options))
                    return Array.Empty<KarProjectResourceInfo>();

                return new[] { resource };
            }

            return Resources
                .Where(resource => MatchesResourceQuery(resource, options))
                .ToList()
                .AsReadOnly();
        }

        public KarProjectResourceInfo GetResource(string address)
        {
            KarProjectResourceInfo resource;
            if (!TryGetResource(address, out resource))
                throw new KeyNotFoundException("KAR project resource was not found: " + address);

            return resource;
        }

        public bool TryGetResource(string address, out KarProjectResourceInfo resource)
        {
            resource = null;

            KarResourceReference reference;
            if (!KarResourceReference.TryParse(address, out reference))
                return false;

            return _resourcesByAddress.TryGetValue(reference.Address, out resource);
        }

        public IReadOnlyList<KarProjectResourceInfo> QueryChildResources(string address)
        {
            KarProjectResourceInfo parent = GetResource(address);
            return Resources
                .Where(resource => string.Equals(resource.ParentAddress, parent.Address, StringComparison.OrdinalIgnoreCase))
                .ToList()
                .AsReadOnly();
        }

        public IReadOnlyList<KarProjectRelationship> QueryRelationships(KarProjectRelationshipQueryOptions options = null)
        {
            IEnumerable<KarProjectRelationship> query = Relationships;
            if (options != null)
                query = query.Where(options.Matches);

            return query
                .ToList()
                .AsReadOnly();
        }

        public IReadOnlyList<KarProjectRelationship> QueryResourceRelationships(string address)
        {
            KarProjectResourceInfo resource = GetResource(address);
            return Relationships
                .Where(relationship => relationship.ResourceReference != null && relationship.ResourceReference.Equals(resource.Reference))
                .ToList()
                .AsReadOnly();
        }

        private static IReadOnlyList<KarProjectResourceInfo> BuildResources(KarProject project)
        {
            List<KarProjectResourceInfo> resources = new List<KarProjectResourceInfo>();

            foreach (KarProjectFile file in project.FileService.Files)
                resources.Add(KarProjectResourceInfo.FromFile(file));

            foreach (KarProjectFile file in project.FileService.Files.Where(file => file.IsHsdArchive))
            {
                KarArchiveInfo archive;
                string error;
                if (!project.ArchiveService.TryInspectHsdArchive(file.RelativePath, out archive, out error))
                    continue;

                foreach (KarArchiveRootInfo root in archive.Roots)
                    resources.Add(KarProjectResourceInfo.FromRoot(new KarProjectRootInfo(archive.File, root)));
            }

            foreach (KarProjectA2DEntryInfo entry in project.A2DService.QueryEntries())
                resources.Add(KarProjectResourceInfo.FromA2DEntry(entry));

            return resources
                .OrderBy(resource => resource.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ThenBy(resource => resource.Kind)
                .ThenBy(resource => resource.Address, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        private static IReadOnlyList<KarProjectRelationship> BuildRelationships(KarProject project)
        {
            List<KarProjectRelationship> relationships = new List<KarProjectRelationship>();
            AddMapRelationships(project, relationships);
            AddLooseScriptTableRelationships(project, relationships);
            AddA2DPackageEntryRelationships(project, relationships);

            return relationships
                .OrderBy(relationship => relationship.MapName ?? "")
                .ThenBy(relationship => relationship.PackageFile == null ? "" : relationship.PackageFile.RelativePath)
                .ThenBy(relationship => relationship.RelativePath ?? "")
                .ThenBy(relationship => relationship.PackageEntryIndex ?? int.MaxValue)
                .ToList()
                .AsReadOnly();
        }

        private static void AddMapRelationships(KarProject project, List<KarProjectRelationship> relationships)
        {
            foreach (KarMapBundle map in project.MapService.Bundles)
            {
                AddMapFileRelationship(relationships, map, map.DataFile, "MapData", "Map data archive.");
                AddMapFileRelationship(relationships, map, map.ModelFile, "MapModel", "Map model archive.");
                AddMapFileRelationship(relationships, map, map.EventFile, "MapEventScript", "Map event/script archive.");
            }
        }

        private static void AddMapFileRelationship(
            List<KarProjectRelationship> relationships,
            KarMapBundle map,
            KarProjectFile file,
            string role,
            string description)
        {
            if (file == null)
                return;

            relationships.Add(new KarProjectRelationship(
                "MapBundleFile",
                role,
                "Maps",
                description,
                map,
                file,
                null,
                null,
                null,
                null,
                null));
        }

        private static void AddLooseScriptTableRelationships(KarProject project, List<KarProjectRelationship> relationships)
        {
            foreach (KarProjectFile file in project.FileService.Query(new KarProjectFileQueryOptions { Kind = KarFileKind.ScriptTable }))
            {
                KarScriptTableInfo info = KarScriptTableCatalog.Describe(file.RelativePath);
                relationships.Add(new KarProjectRelationship(
                    "ScriptTableFile",
                    info.Role,
                    info.Category,
                    info.Description,
                    null,
                    file,
                    null,
                    null,
                    null,
                    null,
                    null));
            }
        }

        private static void AddA2DPackageEntryRelationships(KarProject project, List<KarProjectRelationship> relationships)
        {
            foreach (KarProjectA2DEntryInfo entry in project.A2DService.QueryScriptTableEntries())
            {
                relationships.Add(new KarProjectRelationship(
                    "A2DPackageEntry",
                    entry.Role,
                    entry.Category,
                    entry.Description,
                    null,
                    null,
                    entry.PackageFile,
                    entry.Name,
                    entry.Index,
                    entry.DataOffset,
                    entry.Size));
            }
        }

        private static bool MatchesResourceQuery(KarProjectResourceInfo resource, KarProjectResourceQueryOptions options)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));
            if (options == null)
                return true;
            if (!options.Matches(resource))
                return false;

            switch (resource.Kind)
            {
                case KarResourceKind.File:
                    return options.Files == null || options.Files.Matches(resource.File);

                case KarResourceKind.HsdRoot:
                    if (options.Files != null && !options.Files.Matches(resource.File))
                        return false;
                    if (options.Roots != null)
                    {
                        if (options.Roots.Files != null && !options.Roots.Files.Matches(resource.File))
                            return false;
                        if (!options.Roots.Matches(resource.Root))
                            return false;
                    }
                    return true;

                case KarResourceKind.A2DEntry:
                    if (options.Files != null && !options.Files.Matches(resource.File))
                        return false;
                    if (options.A2DEntries != null)
                    {
                        if (options.A2DEntries.Packages != null && !options.A2DEntries.Packages.Matches(resource.File))
                            return false;
                        if (!options.A2DEntries.Matches(resource.A2DEntry))
                            return false;
                    }
                    return true;

                default:
                    throw new ArgumentOutOfRangeException(nameof(resource));
            }
        }
    }
}
