using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceAddressService
    {
        private readonly KarProject _project;

        internal KarProjectResourceAddressService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public IReadOnlyList<KarProjectResolvedResource> Query(KarProjectResourceQueryOptions options = null)
        {
            Dictionary<string, KarProjectScriptTable> scriptTablesByAddress = _project.ScriptService.QueryTables()
                .GroupBy(table => table.Address, StringComparer.OrdinalIgnoreCase)
                .ToDictionary(group => group.Key, group => group.First(), StringComparer.OrdinalIgnoreCase);

            return _project.ResourceService.Query(options)
                .Select(resource =>
                {
                    KarProjectScriptTable scriptTable;
                    scriptTablesByAddress.TryGetValue(resource.Address, out scriptTable);
                    return new KarProjectResolvedResource(resource, scriptTable);
                })
                .ToList()
                .AsReadOnly();
        }

        public KarProjectResolvedResource Resolve(string address)
        {
            KarProjectResolvedResource resolved;
            if (!TryResolve(address, out resolved))
                throw new KeyNotFoundException("KAR project resource address was not found: " + address);

            return resolved;
        }

        public bool TryResolve(string address, out KarProjectResolvedResource resolved)
        {
            resolved = null;

            KarProjectResourceInfo resource;
            if (!_project.ResourceService.TryGet(address, out resource))
                return false;

            KarProjectScriptTable scriptTable;
            _project.ScriptService.TryGetTable(resource.Address, out scriptTable);
            resolved = new KarProjectResolvedResource(resource, scriptTable);
            return true;
        }
    }
}
