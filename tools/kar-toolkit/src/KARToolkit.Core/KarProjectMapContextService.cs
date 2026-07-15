using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectMapContextService
    {
        private readonly KarProject _project;

        internal KarProjectMapContextService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public IReadOnlyList<KarProjectMapContext> Query(KarProjectMapScriptQueryOptions options = null)
        {
            IEnumerable<KarMapBundle> maps = _project.MapService.Bundles;
            if (options != null && !string.IsNullOrWhiteSpace(options.MapNameOrPath))
                maps = new[] { _project.MapService.Get(options.MapNameOrPath) };

            Dictionary<string, KarProjectMapOutputInfo> outputsByMapName = _project.MapService.QueryOutputs()
                .ToDictionary(output => output.Name, StringComparer.OrdinalIgnoreCase);

            List<KarProjectMapContext> contexts = new List<KarProjectMapContext>();
            foreach (KarMapBundle map in maps)
            {
                KarProjectMapContext context = CreateContext(map, options == null ? null : options.ScriptTables, outputsByMapName);
                if (options == null || options.Matches(context.Scripts))
                    contexts.Add(context);
            }

            return contexts
                .OrderBy(context => context.MapName, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public KarProjectMapContext Get(string mapNameOrPath, KarProjectScriptTableQueryOptions scriptTables = null)
        {
            return CreateContext(_project.MapService.Get(mapNameOrPath), scriptTables, null);
        }

        private KarProjectMapContext CreateContext(
            KarMapBundle map,
            KarProjectScriptTableQueryOptions scriptTables,
            IReadOnlyDictionary<string, KarProjectMapOutputInfo> outputsByMapName)
        {
            KarMapInfo inspection;
            string inspectionError;
            TryInspectMap(map, out inspection, out inspectionError);

            KarProjectMapOutputInfo output = null;
            if (outputsByMapName == null || !outputsByMapName.TryGetValue(map.Name, out output))
                output = _project.MapService.GetOutput(map.Name);

            return new KarProjectMapContext(
                map,
                inspection,
                inspectionError,
                output,
                _project.MapScriptService.Get(map.Name, scriptTables));
        }

        private bool TryInspectMap(KarMapBundle map, out KarMapInfo inspection, out string error)
        {
            try
            {
                inspection = _project.MapService.Inspect(map);
                error = null;
                return true;
            }
            catch (Exception ex)
            {
                inspection = null;
                error = ex.Message;
                return false;
            }
        }
    }
}
