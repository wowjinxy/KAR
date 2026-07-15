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

        public byte[] ReadBytes(string address)
        {
            return ReadBytes(Resolve(address));
        }

        public byte[] ReadBytes(KarProjectResolvedResource resolved)
        {
            if (resolved == null)
                throw new ArgumentNullException(nameof(resolved));

            return GetAdapter(resolved).ReadBytes(resolved.Resource);
        }

        public KarProjectResourceExportResult ExportToOutput(string address, bool overwrite = false)
        {
            return ExportToOutput(Resolve(address), overwrite);
        }

        public KarProjectResourceExportResult ExportToOutput(KarProjectResolvedResource resolved, bool overwrite = false)
        {
            if (resolved == null)
                throw new ArgumentNullException(nameof(resolved));

            return GetAdapter(resolved).ExportToOutput(resolved.Resource, overwrite);
        }

        public KarProjectResourceImportResult ImportFromFile(string address, string inputPath)
        {
            return ImportFromFile(Resolve(address), inputPath);
        }

        public KarProjectResourceImportResult ImportFromFile(KarProjectResolvedResource resolved, string inputPath)
        {
            if (resolved == null)
                throw new ArgumentNullException(nameof(resolved));
            if (string.IsNullOrWhiteSpace(inputPath))
                throw new ArgumentException("Input path cannot be empty.", nameof(inputPath));

            return GetAdapter(resolved).ImportFromFile(resolved.Resource, inputPath);
        }

        public KarProjectResourceScalarEditResult SetScalarFieldFromText(
            string rootAddress,
            string fieldName,
            string rawValue,
            bool bufferAlign = true,
            bool optimize = true,
            bool trim = false)
        {
            return SetScalarFieldFromText(
                Resolve(rootAddress),
                fieldName,
                rawValue,
                bufferAlign,
                optimize,
                trim);
        }

        public KarProjectResourceScalarEditResult SetScalarFieldFromText(
            KarProjectResolvedResource resolved,
            string fieldName,
            string rawValue,
            bool bufferAlign = true,
            bool optimize = true,
            bool trim = false)
        {
            if (resolved == null)
                throw new ArgumentNullException(nameof(resolved));

            return GetAdapter(resolved).SetScalarFieldFromText(
                resolved.Resource,
                fieldName,
                rawValue,
                bufferAlign,
                optimize,
                trim);
        }

        private KarProjectResourceAdapter GetAdapter(KarProjectResolvedResource resolved)
        {
            return _project.ResourceService.GetAdapter(resolved.Resource);
        }
    }
}
