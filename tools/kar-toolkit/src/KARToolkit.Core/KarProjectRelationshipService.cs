using System;
using System.Collections.Generic;

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
            return _project.CreateResourceGraph().QueryRelationships(options);
        }

        public IReadOnlyList<KarProjectRelationship> QueryMap(string mapNameOrPath)
        {
            KarMapBundle map = _project.MapService.Get(mapNameOrPath);
            return _project.CreateResourceGraph().QueryRelationships(new KarProjectRelationshipQueryOptions
            {
                MapName = map.Name,
            });
        }
    }
}
