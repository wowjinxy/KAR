using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectScriptService
    {
        private readonly KarProject _project;

        internal KarProjectScriptService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public IReadOnlyList<KarProjectScriptTable> QueryTables(KarProjectScriptTableQueryOptions options = null)
        {
            KarProjectResourceGraph graph = _project.CreateResourceGraph();
            IEnumerable<KarProjectResourceInfo> resources = graph.QueryResources(options == null ? null : options.Resources)
                .Where(IsScriptTableResource);
            Dictionary<string, KarProjectRelationship> relationshipsByAddress = graph.Relationships
                .Where(relationship => relationship.ResourceReference != null)
                .GroupBy(relationship => relationship.ResourceReference.Address, StringComparer.OrdinalIgnoreCase)
                .ToDictionary(group => group.Key, group => group.First(), StringComparer.OrdinalIgnoreCase);

            List<KarProjectScriptTable> tables = new List<KarProjectScriptTable>();
            foreach (KarProjectResourceInfo resource in resources)
            {
                KarProjectRelationship relationship;
                relationshipsByAddress.TryGetValue(resource.Address, out relationship);

                KarProjectScriptTable table = new KarProjectScriptTable(
                    resource,
                    KarScriptTableCatalog.Describe(GetScriptTableName(resource)),
                    relationship);
                if (options == null || options.Matches(table))
                    tables.Add(table);
            }

            return tables
                .OrderBy(table => table.Role, StringComparer.OrdinalIgnoreCase)
                .ThenBy(table => table.Address, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public KarProjectScriptTable GetTable(string address)
        {
            KarProjectScriptTable table = QueryTables(new KarProjectScriptTableQueryOptions
            {
                Address = address,
            }).FirstOrDefault();

            if (table == null)
                throw new KeyNotFoundException("KAR project script table was not found: " + address);

            return table;
        }

        public byte[] ReadTableBytes(string address)
        {
            return _project.ResourceService.ReadBytes(GetTable(address).Address);
        }

        public KarProjectResourceExportResult ExportTableToOutput(string address, bool overwrite = false)
        {
            return _project.ResourceService.ExportToOutput(GetTable(address).Address, overwrite);
        }

        public KarProjectResourceImportResult ImportTableFromFile(string address, string inputPath)
        {
            return _project.ResourceService.ImportFromFile(GetTable(address).Address, inputPath);
        }

        private static bool IsScriptTableResource(KarProjectResourceInfo resource)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));

            if (resource.Kind == KarResourceKind.File)
                return resource.File != null && resource.File.Kind == KarFileKind.ScriptTable;

            return resource.Kind == KarResourceKind.A2DEntry &&
                resource.A2DEntry != null &&
                resource.A2DEntry.IsScriptTable;
        }

        private static string GetScriptTableName(KarProjectResourceInfo resource)
        {
            if (resource.Kind == KarResourceKind.A2DEntry)
                return resource.A2DEntry.Name;

            return Path.GetFileName(resource.RelativePath);
        }
    }
}
