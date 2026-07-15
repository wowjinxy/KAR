using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceService
    {
        private readonly KarProject _project;
        private readonly IReadOnlyList<KarProjectResourceAdapter> _adapters;
        private readonly Dictionary<KarResourceKind, KarProjectResourceAdapter> _adaptersByKind;

        internal KarProjectResourceService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
            _adapters = KarProjectResourceAdapter.CreateDefaultAdapters(project);
            _adaptersByKind = _adapters.ToDictionary(adapter => adapter.Kind);
        }

        public KarProject Project => _project;

        public IReadOnlyList<KarProjectResourceAdapter> Adapters => _adapters;

        public KarProjectResourceAdapter GetAdapter(KarResourceKind kind)
        {
            KarProjectResourceAdapter adapter;
            if (!_adaptersByKind.TryGetValue(kind, out adapter))
                throw new KeyNotFoundException("KAR resource adapter was not found: " + kind);

            return adapter;
        }

        public KarProjectResourceAdapter GetAdapter(KarProjectResourceInfo resource)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));

            return GetAdapter(resource.Kind);
        }

        public IReadOnlyList<KarProjectResourceInfo> Query(KarProjectResourceQueryOptions options = null)
        {
            return _project.ResourceGraphService.QueryResources(options);
        }

        public KarProjectResourceInfo Get(string address)
        {
            KarProjectResourceInfo resource;
            if (!TryGet(address, out resource))
                throw new KeyNotFoundException("KAR project resource was not found: " + address);

            return resource;
        }

        public IReadOnlyList<KarProjectResourceOutputInfo> QueryOutputs(KarProjectResourceOutputQueryOptions options = null)
        {
            IEnumerable<KarProjectResourceOutputInfo> query = Query(options == null ? null : options.Resources)
                .Select(CreateOutputInfo);

            if (options != null)
                query = query.Where(options.Matches);

            return query
                .OrderBy(output => output.Resource.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ThenBy(output => output.Kind)
                .ThenBy(output => output.Address, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public KarProjectResourceOutputInfo GetOutput(string address)
        {
            return CreateOutputInfo(Get(address));
        }

        public KarProjectResourceDetail GetDetail(string address)
        {
            return CreateDetail(Get(address));
        }

        public IReadOnlyList<KarProjectResourceFieldInfo> QueryFieldValues(KarProjectResourceFieldQueryOptions options = null)
        {
            IEnumerable<KarProjectResourceInfo> resources = Query(options == null ? null : options.Resources)
                .Where(resource => resource.CanQueryFieldValues);
            List<KarProjectResourceFieldInfo> fields = new List<KarProjectResourceFieldInfo>();

            foreach (KarProjectResourceInfo resource in resources)
            {
                if (resource.Root.Root.DataDefinition == null || !resource.Root.Root.HasFieldValues)
                    continue;

                foreach (KarDataFieldValue value in resource.Root.Root.FieldValues)
                {
                    KarProjectFieldInfo fieldInfo = new KarProjectFieldInfo(resource.Root, value);
                    KarProjectResourceFieldInfo field = new KarProjectResourceFieldInfo(resource, fieldInfo);
                    if (options == null || options.Matches(field))
                        fields.Add(field);
                }
            }

            return fields
                .OrderBy(field => field.Address, StringComparer.OrdinalIgnoreCase)
                .ThenBy(field => field.Field.Offset ?? int.MaxValue)
                .ThenBy(field => field.FieldName, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public KarProjectResourceFieldInfo GetFieldValue(string rootAddress, string fieldName)
        {
            KarProjectResourceFieldInfo field = QueryFieldValues(new KarProjectResourceFieldQueryOptions
            {
                Resources = new KarProjectResourceQueryOptions
                {
                    Address = rootAddress,
                    Kind = KarResourceKind.HsdRoot,
                },
                FieldName = fieldName,
            }).FirstOrDefault();

            if (field == null)
                throw new KeyNotFoundException("KAR project resource field was not found: " + rootAddress + " " + fieldName);

            return field;
        }

        public bool TryGet(string address, out KarProjectResourceInfo resource)
        {
            resource = null;

            KarResourceReference reference;
            if (!KarResourceReference.TryParse(address, out reference))
                return false;

            try
            {
                return _project.ResourceGraphService.TryGetResource(reference.Address, out resource);
            }
            catch (ArgumentException)
            {
                resource = null;
                return false;
            }
            catch (FileNotFoundException)
            {
                resource = null;
                return false;
            }
            catch (KeyNotFoundException)
            {
                resource = null;
                return false;
            }
            catch (IndexOutOfRangeException)
            {
                resource = null;
                return false;
            }
        }

        public byte[] ReadBytes(string address)
        {
            KarProjectResourceInfo resource = Get(address);
            return GetAdapter(resource).ReadBytes(resource);
        }

        public KarProjectResourceByteDumpResult DumpBytesToOutput(string address, bool overwrite = false)
        {
            KarProjectResourceInfo resource = Get(address);
            return DumpBytesToOutput(resource, overwrite);
        }

        public KarProjectResourceByteDumpResult DumpBytesToOutput(KarProjectResourceInfo resource, bool overwrite = false)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));
            if (!resource.CanReadBytes)
                throw new NotSupportedException("Resource " + resource.Address + " does not support byte dumps.");

            byte[] data = GetAdapter(resource).ReadBytes(resource);
            string outputRelativePath = CreateByteDumpRelativePath(resource);
            string outputPath = _project.Workspace.GetOutputAssetPath(outputRelativePath);
            bool wroteOutput = overwrite || !File.Exists(outputPath);
            if (wroteOutput)
                outputPath = _project.Workspace.SaveOutputAsset(outputRelativePath, tempPath => File.WriteAllBytes(tempPath, data));

            return new KarProjectResourceByteDumpResult(
                resource,
                outputRelativePath,
                outputPath,
                data.Length,
                ComputeSha256(data),
                wroteOutput);
        }

        public KarProjectResourceExportResult ExportToOutput(string address, bool overwrite = false)
        {
            KarProjectResourceInfo resource = Get(address);
            return GetAdapter(resource).ExportToOutput(resource, overwrite);
        }

        public KarProjectResourceImportResult ImportFromFile(string address, string inputPath)
        {
            if (string.IsNullOrWhiteSpace(inputPath))
                throw new ArgumentException("Input path cannot be empty.", nameof(inputPath));

            KarProjectResourceInfo resource = Get(address);
            return GetAdapter(resource).ImportFromFile(resource, inputPath);
        }

        public KarProjectResourceScalarEditResult SetScalarFieldFromText(
            string rootAddress,
            string fieldName,
            string rawValue,
            bool bufferAlign = true,
            bool optimize = true,
            bool trim = false)
        {
            KarProjectResourceInfo resource = Get(rootAddress);
            return GetAdapter(resource).SetScalarFieldFromText(
                resource,
                fieldName,
                rawValue,
                bufferAlign,
                optimize,
                trim);
        }

        public KarProjectResourceOutputApplyResult ApplyOutput(string address)
        {
            KarProjectResourceOutputInfo output = GetOutput(address);
            return ApplyOutput(output);
        }

        public IReadOnlyList<KarProjectResourceOutputApplyResult> ApplyModifiedOutputs(KarProjectResourceOutputQueryOptions options = null)
        {
            KarProjectResourceOutputQueryOptions query = new KarProjectResourceOutputQueryOptions
            {
                Resources = options == null ? null : options.Resources,
                Status = KarProjectResourceOutputStatus.SidecarDiffersFromEntry,
                HasOutput = true,
            };

            return QueryOutputs(query)
                .Select(ApplyOutput)
                .ToList()
                .AsReadOnly();
        }

        private KarProjectResourceOutputApplyResult ApplyOutput(KarProjectResourceOutputInfo output)
        {
            if (output == null)
                throw new ArgumentNullException(nameof(output));

            return GetAdapter(output.Resource).ApplyOutput(output);
        }

        private KarProjectResourceDetail CreateDetail(KarProjectResourceInfo resource)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));

            IReadOnlyList<KarProjectResourceFieldInfo> fields = resource.CanQueryFieldValues
                ? QueryFieldValues(new KarProjectResourceFieldQueryOptions
                {
                    Resources = new KarProjectResourceQueryOptions
                    {
                        Address = resource.Address,
                        Kind = resource.Kind,
                    },
                })
                : Array.Empty<KarProjectResourceFieldInfo>();

            return new KarProjectResourceDetail(
                resource,
                resource.CanQueryOutput ? CreateOutputInfo(resource) : null,
                _project.ResourceGraphService.QueryChildResources(resource.Address),
                fields,
                _project.ResourceGraphService.QueryResourceRelationships(resource.Address));
        }

        private KarProjectResourceOutputInfo CreateOutputInfo(KarProjectResourceInfo resource)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));

            return GetAdapter(resource).CreateOutputInfo(resource);
        }

        private static string CreateByteDumpRelativePath(KarProjectResourceInfo resource)
        {
            List<string> parts = new List<string> { "resource-bytes" };
            parts.AddRange(KarProjectWorkspace.NormalizeRelativePath(resource.RelativePath)
                .Split('/')
                .Select(SanitizePathSegment));

            if (resource.Kind == KarResourceKind.HsdRoot)
                parts.Add(SanitizePathSegment(resource.Reference.RootName) + ".bin");
            else if (resource.Kind == KarResourceKind.A2DEntry)
                parts.Add(SanitizePathSegment(resource.Reference.EntryName) + ".bin");

            return string.Join("/", parts);
        }

        private static string SanitizePathSegment(string value)
        {
            if (string.IsNullOrWhiteSpace(value))
                return "_";

            char[] invalid = Path.GetInvalidFileNameChars();
            char[] chars = value.Trim().ToCharArray();
            for (int i = 0; i < chars.Length; i++)
            {
                if (invalid.Contains(chars[i]) || chars[i] == '/' || chars[i] == '\\')
                    chars[i] = '_';
            }

            string sanitized = new string(chars);
            if (sanitized == "." || sanitized == "..")
                return "_";

            return sanitized.Length == 0 ? "_" : sanitized;
        }

        private static string ComputeSha256(byte[] data)
        {
            using (SHA256 sha256 = SHA256.Create())
                return string.Concat(sha256.ComputeHash(data).Select(value => value.ToString("x2")));
        }
    }
}
