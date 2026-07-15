using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectRelationshipProviderRegistry
    {
        public static KarProjectRelationshipProviderRegistry Default { get; } =
            new KarProjectRelationshipProviderRegistry(CreateDefaultProviders());

        private readonly IReadOnlyList<KarProjectRelationshipProvider> _providers;
        private readonly Dictionary<string, KarProjectRelationshipProvider> _providersById;

        public KarProjectRelationshipProviderRegistry(IEnumerable<KarProjectRelationshipProvider> providers)
        {
            if (providers == null)
                throw new ArgumentNullException(nameof(providers));

            _providers = providers
                .ToList()
                .AsReadOnly();
            _providersById = new Dictionary<string, KarProjectRelationshipProvider>(StringComparer.OrdinalIgnoreCase);

            foreach (KarProjectRelationshipProvider provider in _providers)
            {
                if (provider == null)
                    throw new ArgumentException("Relationship providers cannot contain null entries.", nameof(providers));
                if (_providersById.ContainsKey(provider.Id))
                    throw new ArgumentException("Duplicate relationship provider id: " + provider.Id, nameof(providers));

                _providersById.Add(provider.Id, provider);
            }
        }

        public IReadOnlyList<KarProjectRelationshipProvider> Providers => _providers;

        public KarProjectRelationshipProvider FindProvider(string id)
        {
            KarProjectRelationshipProvider provider;
            if (!TryFindProvider(id, out provider))
                throw new KeyNotFoundException("KAR relationship provider was not found: " + id);

            return provider;
        }

        public bool TryFindProvider(string id, out KarProjectRelationshipProvider provider)
        {
            provider = null;
            return !string.IsNullOrWhiteSpace(id) && _providersById.TryGetValue(id, out provider);
        }

        public IReadOnlyList<KarProjectRelationship> CreateRelationships(KarProject project)
        {
            if (project == null)
                throw new ArgumentNullException(nameof(project));

            List<KarProjectRelationship> relationships = new List<KarProjectRelationship>();
            foreach (KarProjectRelationshipProvider provider in _providers)
            {
                foreach (KarProjectRelationship relationship in provider.CreateRelationships(project))
                {
                    if (relationship == null)
                        throw new InvalidOperationException("Relationship provider returned a null relationship: " + provider.Id);

                    relationships.Add(relationship);
                }
            }

            return relationships
                .OrderBy(relationship => relationship.MapName ?? "")
                .ThenBy(relationship => relationship.PackageFile == null ? "" : relationship.PackageFile.RelativePath)
                .ThenBy(relationship => relationship.RelativePath ?? "")
                .ThenBy(relationship => relationship.PackageEntryIndex ?? int.MaxValue)
                .ToList()
                .AsReadOnly();
        }

        private static IReadOnlyList<KarProjectRelationshipProvider> CreateDefaultProviders()
        {
            return new[]
            {
                new KarProjectRelationshipProvider(
                    "map-bundle-relationships",
                    "Map Bundle Relationships",
                    "Links map data, model, and event/script files to their map bundles.",
                    CreateMapRelationships),
                new KarProjectRelationshipProvider(
                    "loose-script-table-relationships",
                    "Loose Script Table Relationships",
                    "Links loose .tm script table files to script metadata roles.",
                    CreateLooseScriptTableRelationships),
                new KarProjectRelationshipProvider(
                    "a2d-script-table-relationships",
                    "A2D Script Table Relationships",
                    "Links packaged .tm script table A2D entries to script metadata roles.",
                    CreateA2DPackageEntryRelationships),
            };
        }

        private static IEnumerable<KarProjectRelationship> CreateMapRelationships(KarProject project)
        {
            foreach (KarMapBundle map in project.MapService.Bundles)
            {
                KarProjectRelationship data = CreateMapFileRelationship(map, map.DataFile, "MapData", "Map data archive.");
                if (data != null)
                    yield return data;

                KarProjectRelationship model = CreateMapFileRelationship(map, map.ModelFile, "MapModel", "Map model archive.");
                if (model != null)
                    yield return model;

                KarProjectRelationship events = CreateMapFileRelationship(map, map.EventFile, "MapEventScript", "Map event/script archive.");
                if (events != null)
                    yield return events;
            }
        }

        private static KarProjectRelationship CreateMapFileRelationship(
            KarMapBundle map,
            KarProjectFile file,
            string role,
            string description)
        {
            if (file == null)
                return null;

            return new KarProjectRelationship(
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
                null);
        }

        private static IEnumerable<KarProjectRelationship> CreateLooseScriptTableRelationships(KarProject project)
        {
            foreach (KarProjectFile file in project.FileService.Query(new KarProjectFileQueryOptions { Kind = KarFileKind.ScriptTable }))
            {
                KarScriptTableInfo info = KarScriptTableCatalog.Describe(file.RelativePath);
                yield return new KarProjectRelationship(
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
                    null);
            }
        }

        private static IEnumerable<KarProjectRelationship> CreateA2DPackageEntryRelationships(KarProject project)
        {
            foreach (KarProjectA2DEntryInfo entry in project.A2DService.QueryScriptTableEntries())
            {
                yield return new KarProjectRelationship(
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
                    entry.Size);
            }
        }
    }
}
