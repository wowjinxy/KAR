using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectMapScriptBundle
    {
        internal KarProjectMapScriptBundle(
            KarMapBundle map,
            KarProjectResourceInfo dataResource,
            KarProjectResourceInfo modelResource,
            KarProjectResourceInfo scriptArchiveResource,
            IReadOnlyList<KarProjectRelationship> mapRelationships,
            IReadOnlyList<KarProjectScriptTableContext> scriptContexts)
        {
            Map = map ?? throw new ArgumentNullException(nameof(map));
            DataResource = dataResource;
            ModelResource = modelResource;
            ScriptArchiveResource = scriptArchiveResource;
            MapRelationships = mapRelationships ?? throw new ArgumentNullException(nameof(mapRelationships));
            ScriptContexts = scriptContexts ?? throw new ArgumentNullException(nameof(scriptContexts));
            ScriptTables = ScriptContexts
                .Select(context => context.Table)
                .ToList()
                .AsReadOnly();

            List<KarProjectResourceInfo> resources = new List<KarProjectResourceInfo>();
            if (DataResource != null)
                resources.Add(DataResource);
            if (ModelResource != null)
                resources.Add(ModelResource);
            if (ScriptArchiveResource != null)
                resources.Add(ScriptArchiveResource);
            MapResources = resources.AsReadOnly();
        }

        public KarMapBundle Map { get; }

        public string MapName => Map.Name;

        public KarProjectFile DataFile => Map.DataFile;

        public KarProjectFile ModelFile => Map.ModelFile;

        public KarProjectFile ScriptFile => Map.ScriptFile;

        public KarProjectResourceInfo DataResource { get; }

        public KarProjectResourceInfo ModelResource { get; }

        public KarProjectResourceInfo ScriptArchiveResource { get; }

        public IReadOnlyList<KarProjectResourceInfo> MapResources { get; }

        public IReadOnlyList<KarProjectRelationship> MapRelationships { get; }

        public IReadOnlyList<KarProjectScriptTableContext> ScriptContexts { get; }

        public IReadOnlyList<KarProjectScriptTable> ScriptTables { get; }

        public int MapResourceCount => MapResources.Count;

        public int RelationshipCount => MapRelationships.Count;

        public int ScriptTableCount => ScriptTables.Count;

        public bool HasScriptArchive => ScriptArchiveResource != null;

        public bool HasScriptTables => ScriptTables.Count != 0;
    }
}
