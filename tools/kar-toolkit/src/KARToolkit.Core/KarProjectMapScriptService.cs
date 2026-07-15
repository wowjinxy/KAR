using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectMapScriptService
    {
        private readonly KarProject _project;

        internal KarProjectMapScriptService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public IReadOnlyList<KarProjectMapScriptBundle> Query(KarProjectMapScriptQueryOptions options = null)
        {
            IEnumerable<KarMapBundle> maps = _project.MapService.Bundles;
            if (options != null && !string.IsNullOrWhiteSpace(options.MapNameOrPath))
                maps = new[] { _project.MapService.Get(options.MapNameOrPath) };

            List<KarProjectMapScriptBundle> bundles = new List<KarProjectMapScriptBundle>();
            foreach (KarMapBundle map in maps)
            {
                KarProjectMapScriptBundle bundle = CreateBundle(map, options == null ? null : options.ScriptTables);
                if (options == null || options.Matches(bundle))
                    bundles.Add(bundle);
            }

            return bundles
                .OrderBy(bundle => bundle.MapName, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public KarProjectMapScriptBundle Get(string mapNameOrPath, KarProjectScriptTableQueryOptions scriptTables = null)
        {
            return Query(new KarProjectMapScriptQueryOptions
            {
                MapNameOrPath = mapNameOrPath,
                ScriptTables = scriptTables,
            }).Single();
        }

        public KarProjectResourceExportResult ExportScriptArchiveToOutput(string mapNameOrPath, bool overwrite = false)
        {
            KarProjectMapScriptBundle bundle = Get(mapNameOrPath);
            if (bundle.ScriptArchiveResource == null)
                throw new KeyNotFoundException("KAR map does not have a script archive: " + bundle.MapName);

            return _project.ResourceService.ExportToOutput(bundle.ScriptArchiveResource.Address, overwrite);
        }

        private KarProjectMapScriptBundle CreateBundle(KarMapBundle map, KarProjectScriptTableQueryOptions scriptTableOptions)
        {
            IReadOnlyList<KarProjectRelationship> relationships = _project.RelationshipService.QueryMap(map.Name);
            return new KarProjectMapScriptBundle(
                map,
                GetFileResourceOrNull(map.DataFile),
                GetFileResourceOrNull(map.ModelFile),
                GetFileResourceOrNull(map.ScriptFile),
                relationships,
                _project.ScriptContextService.Query(new KarProjectScriptTableContextQueryOptions
                {
                    Tables = scriptTableOptions,
                }));
        }

        private KarProjectResourceInfo GetFileResourceOrNull(KarProjectFile file)
        {
            if (file == null)
                return null;

            return _project.ResourceService.Get(file.RelativePath);
        }
    }
}
