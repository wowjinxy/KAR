using System;
using System.Collections.Generic;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceGraphService
    {
        private readonly KarProject _project;
        private KarProjectResourceGraph _snapshot;

        internal KarProjectResourceGraphService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public bool HasSnapshot => _snapshot != null;

        public KarProjectResourceGraph Snapshot
        {
            get
            {
                if (_snapshot == null)
                    _snapshot = BuildFresh();

                return _snapshot;
            }
        }

        public KarProjectResourceGraph Refresh()
        {
            _snapshot = BuildFresh();
            return _snapshot;
        }

        public void Invalidate()
        {
            _snapshot = null;
        }

        public IReadOnlyList<KarProjectResourceInfo> QueryResources(KarProjectResourceQueryOptions options = null)
        {
            return Snapshot.QueryResources(options);
        }

        public KarProjectResourceInfo GetResource(string address)
        {
            return Snapshot.GetResource(address);
        }

        public bool TryGetResource(string address, out KarProjectResourceInfo resource)
        {
            return Snapshot.TryGetResource(address, out resource);
        }

        public IReadOnlyList<KarProjectResourceInfo> QueryChildResources(string address)
        {
            return Snapshot.QueryChildResources(address);
        }

        public IReadOnlyList<KarProjectRelationship> QueryRelationships(KarProjectRelationshipQueryOptions options = null)
        {
            return Snapshot.QueryRelationships(options);
        }

        public IReadOnlyList<KarProjectRelationship> QueryResourceRelationships(string address)
        {
            return Snapshot.QueryResourceRelationships(address);
        }

        private KarProjectResourceGraph BuildFresh()
        {
            return KarProjectResourceGraph.Build(_project);
        }
    }
}
