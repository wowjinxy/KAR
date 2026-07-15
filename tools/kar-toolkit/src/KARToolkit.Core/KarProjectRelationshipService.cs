using KARToolkit.Core.AirRide;
using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectRelationshipService
    {
        private readonly KarProject _project;

        internal KarProjectRelationshipService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public IReadOnlyList<KarProjectRelationship> Query(KarProjectRelationshipQueryOptions options = null)
        {
            List<KarProjectRelationship> relationships = new List<KarProjectRelationship>();
            AddMapRelationships(relationships);
            AddLooseScriptTableRelationships(relationships);
            AddA2DPackageEntryRelationships(relationships);

            IEnumerable<KarProjectRelationship> query = relationships;
            if (options != null)
                query = query.Where(options.Matches);

            return query
                .OrderBy(relationship => relationship.MapName ?? "")
                .ThenBy(relationship => relationship.PackageFile == null ? "" : relationship.PackageFile.RelativePath)
                .ThenBy(relationship => relationship.RelativePath ?? "")
                .ThenBy(relationship => relationship.PackageEntryIndex ?? int.MaxValue)
                .ToList()
                .AsReadOnly();
        }

        public IReadOnlyList<KarProjectRelationship> QueryMap(string mapNameOrPath)
        {
            KarMapBundle map = _project.MapService.Get(mapNameOrPath);
            return Query(new KarProjectRelationshipQueryOptions
            {
                MapName = map.Name,
            });
        }

        private void AddMapRelationships(List<KarProjectRelationship> relationships)
        {
            foreach (KarMapBundle map in _project.MapService.Bundles)
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

        private void AddLooseScriptTableRelationships(List<KarProjectRelationship> relationships)
        {
            foreach (KarProjectFile file in _project.FileService.Query(new KarProjectFileQueryOptions { Kind = KarFileKind.ScriptTable }))
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

        private void AddA2DPackageEntryRelationships(List<KarProjectRelationship> relationships)
        {
            foreach (KarProjectFile file in _project.FileService.Query(new KarProjectFileQueryOptions { Kind = KarFileKind.A2dPackage }))
            {
                KarProjectA2DPackage package;
                string error;
                if (!_project.ArchiveService.TryOpenProjectA2DPackage(file.RelativePath, out package, out error))
                    continue;

                foreach (A2DPackageEntry entry in package.Package.Entries)
                {
                    if (!string.Equals(entry.Kind, "tm", StringComparison.OrdinalIgnoreCase))
                        continue;

                    KarScriptTableInfo info = KarScriptTableCatalog.Describe(entry.Name);
                    relationships.Add(new KarProjectRelationship(
                        "A2DPackageEntry",
                        info.Role,
                        info.Category,
                        info.Description,
                        null,
                        null,
                        file,
                        entry.Name,
                        entry.Index,
                        entry.DataOffset,
                        entry.Size));
                }
            }
        }
    }
}
