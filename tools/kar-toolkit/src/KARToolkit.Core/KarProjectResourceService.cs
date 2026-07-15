using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

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

        public IReadOnlyList<KarProjectResourceDetail> QueryDetails(KarProjectResourceQueryOptions options = null)
        {
            return Query(options)
                .Select(CreateDetail)
                .ToList()
                .AsReadOnly();
        }

        public KarProjectResourceDetail GetDetail(string address)
        {
            return CreateDetail(Get(address));
        }

        public IReadOnlyList<KarProjectResourceDataView> QueryDataViews(KarProjectResourceQueryOptions options = null)
        {
            return Query(options)
                .Select(CreateDataView)
                .ToList()
                .AsReadOnly();
        }

        public KarProjectResourceDataView GetDataView(string address)
        {
            return CreateDataView(Get(address));
        }

        public IReadOnlyList<KarProjectResourceDataFieldView> QueryDataFields(
            KarProjectResourceDataFieldQueryOptions options = null)
        {
            options = options ?? new KarProjectResourceDataFieldQueryOptions();
            List<KarProjectResourceDataFieldView> fields = new List<KarProjectResourceDataFieldView>();

            foreach (KarProjectResourceDataView view in QueryDataViews(options.Resources))
            {
                foreach (KarProjectResourceDataFieldView field in view.FlattenedFields)
                {
                    if (options.Matches(view, field))
                        fields.Add(field);
                }
            }

            return fields
                .OrderBy(field => field.Address, StringComparer.OrdinalIgnoreCase)
                .ThenBy(field => field.Depth)
                .ThenBy(field => field.FieldPath, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public KarProjectResourceDataFieldView GetDataField(string address, string fieldPathOrName)
        {
            if (string.IsNullOrWhiteSpace(fieldPathOrName))
                throw new ArgumentException("KAR project resource data field path or name cannot be empty.", nameof(fieldPathOrName));

            KarProjectResourceDataView view = GetDataView(address);
            KarProjectResourceDataFieldView field = view.FlattenedFields
                .FirstOrDefault(candidate => string.Equals(candidate.FieldPath, fieldPathOrName, StringComparison.OrdinalIgnoreCase));
            if (field == null)
            {
                field = view.Fields
                    .FirstOrDefault(candidate => string.Equals(candidate.FieldName, fieldPathOrName, StringComparison.OrdinalIgnoreCase));
            }
            if (field == null)
            {
                field = view.FlattenedFields
                    .FirstOrDefault(candidate => string.Equals(candidate.FieldName, fieldPathOrName, StringComparison.OrdinalIgnoreCase));
            }
            if (field == null)
                throw new KeyNotFoundException("KAR project resource data field was not found: " + address + " " + fieldPathOrName);

            return field;
        }

        public KarProjectResourceActionPlan GetDataFieldEditPlan(
            string address,
            string fieldPathOrName,
            string value = null,
            bool overwrite = false)
        {
            KarProjectResourceDataFieldView field = GetEditableDataField(address, fieldPathOrName);
            KarProjectResourceActionExecutionOptions options = field.ScalarEdit.CreateExecutionOptions(value);
            options.Overwrite = overwrite;
            return GetActionPlan(address, field.ScalarEdit.ActionId, options);
        }

        public KarProjectResourceActionExecutionResult ExecuteDataFieldEdit(
            string address,
            string fieldPathOrName,
            string value)
        {
            KarProjectResourceDataFieldView field = GetEditableDataField(address, fieldPathOrName);
            return _project.ResourceActionExecutor.Execute(
                address,
                field.ScalarEdit.ActionId,
                field.ScalarEdit.CreateExecutionOptions(value));
        }

        public IReadOnlyList<KarProjectResourceActionPlan> QueryActionPlans(KarProjectResourceActionPlanQueryOptions options = null)
        {
            options = options ?? new KarProjectResourceActionPlanQueryOptions();
            List<KarProjectResourceActionPlan> plans = new List<KarProjectResourceActionPlan>();

            foreach (KarProjectResourceInfo resource in Query(options.Resources))
            {
                foreach (KarProjectResourceAction action in resource.Actions)
                {
                    if (!options.Matches(action))
                        continue;

                    KarProjectResourceActionPlan plan = CreateActionPlan(resource, action, options.Overwrite);
                    if (options.Matches(plan))
                        plans.Add(plan);
                }
            }

            return plans
                .OrderBy(plan => plan.Resource.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ThenBy(plan => plan.Kind)
                .ThenBy(plan => plan.Address, StringComparer.OrdinalIgnoreCase)
                .ThenBy(plan => plan.ActionId, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public KarProjectResourceActionPlan GetActionPlan(string address, string actionId, bool overwrite = false)
        {
            return GetActionPlan(address, actionId, new KarProjectResourceActionExecutionOptions
            {
                Overwrite = overwrite,
            });
        }

        public KarProjectResourceActionPlan GetActionPlan(
            string address,
            string actionId,
            KarProjectResourceActionExecutionOptions options)
        {
            if (string.IsNullOrWhiteSpace(actionId))
                throw new ArgumentException("KAR resource action id cannot be empty.", nameof(actionId));

            options = options ?? new KarProjectResourceActionExecutionOptions();
            KarProjectResourceInfo resource = Get(address);
            KarProjectResourceAction action = resource.Actions
                .FirstOrDefault(candidate => string.Equals(candidate.Id, actionId, StringComparison.OrdinalIgnoreCase));
            if (action == null)
                throw new KeyNotFoundException("KAR resource action was not found: " + resource.Address + " " + actionId);

            return CreateActionPlan(
                resource,
                action,
                options.Overwrite,
                options.HasInputPath,
                options.HasFieldName,
                options.HasValue);
        }

        public KarProjectResourceActionExecutionResult ExecuteAction(
            string address,
            string actionId,
            KarProjectResourceActionExecutionOptions options = null)
        {
            return _project.ResourceActionExecutor.Execute(address, actionId, options);
        }

        public IReadOnlyList<KarProjectResourceActionExecutionResult> ExecuteActions(
            KarProjectResourceActionPlanQueryOptions options,
            KarProjectResourceActionExecutionOptions executionOptions = null)
        {
            return _project.ResourceActionExecutor.ExecuteBatch(options, executionOptions);
        }

        public KarProjectResourceActionBatchResult ExecuteActionBatch(
            KarProjectResourceActionPlanQueryOptions options,
            KarProjectResourceActionExecutionOptions executionOptions = null)
        {
            return _project.ResourceActionExecutor.ExecuteBatchResult(options, executionOptions);
        }

        public IReadOnlyList<KarProjectResourceByteInfo> QueryByteInfo(KarProjectResourceByteQueryOptions options = null)
        {
            IEnumerable<KarProjectResourceByteInfo> query = Query(options == null ? null : options.Resources)
                .Where(resource => resource.CanReadBytes)
                .Select(CreateByteInfo);

            if (options != null)
                query = query.Where(options.Matches);

            return query
                .OrderBy(info => info.Resource.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ThenBy(info => info.Kind)
                .ThenBy(info => info.Address, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public KarProjectResourceByteInfo GetByteInfo(string address)
        {
            return CreateByteInfo(Get(address));
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

        public IReadOnlyList<KarProjectResourceByteDumpResult> DumpBytesToOutput(KarProjectResourceByteQueryOptions options, bool overwrite = false)
        {
            return QueryByteInfo(options)
                .Select(info => DumpBytesToOutput(info.Resource, overwrite))
                .ToList()
                .AsReadOnly();
        }

        public KarProjectResourceByteDumpResult DumpBytesToOutput(KarProjectResourceInfo resource, bool overwrite = false)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));
            if (!resource.CanReadBytes)
                throw new NotSupportedException("Resource " + resource.Address + " does not support byte dumps.");

            byte[] data = GetAdapter(resource).ReadBytes(resource);
            KarProjectResourceByteInfo info = CreateByteInfo(resource, data);
            bool wroteOutput = overwrite || !info.HasOutput;
            string outputPath = info.OutputPath;
            if (wroteOutput)
                outputPath = _project.Workspace.SaveOutputAsset(info.OutputRelativePath, tempPath => File.WriteAllBytes(tempPath, data));

            return new KarProjectResourceByteDumpResult(
                resource,
                info.OutputRelativePath,
                outputPath,
                data.Length,
                info.ActiveSha256,
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
                resource.CanReadBytes ? CreateByteInfo(resource) : null,
                _project.ResourceGraphService.QueryChildResources(resource.Address),
                fields,
                _project.ResourceGraphService.QueryResourceRelationships(resource.Address));
        }

        private KarProjectResourceDataView CreateDataView(KarProjectResourceInfo resource)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));

            return new KarProjectResourceDataView(resource, CreateDataFields(resource));
        }

        private static IReadOnlyList<KarProjectResourceFieldInfo> CreateDataFields(KarProjectResourceInfo resource)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));
            if (!resource.CanQueryFieldValues ||
                resource.Root == null ||
                resource.Root.Root.DataDefinition == null ||
                !resource.Root.Root.HasFieldValues)
            {
                return Array.Empty<KarProjectResourceFieldInfo>();
            }

            List<KarProjectResourceFieldInfo> fields = new List<KarProjectResourceFieldInfo>();
            foreach (KarDataFieldValue value in resource.Root.Root.FieldValues)
            {
                KarProjectFieldInfo fieldInfo = new KarProjectFieldInfo(resource.Root, value);
                fields.Add(new KarProjectResourceFieldInfo(resource, fieldInfo));
            }

            return fields.AsReadOnly();
        }

        private KarProjectResourceDataFieldView GetEditableDataField(string address, string fieldPathOrName)
        {
            KarProjectResourceDataFieldView field = GetDataField(address, fieldPathOrName);
            if (!field.HasScalarEdit)
                throw new NotSupportedException("KAR project resource data field does not support scalar edits: " + address + " " + fieldPathOrName);

            return field;
        }

        private KarProjectResourceActionPlan CreateActionPlan(KarProjectResourceInfo resource, KarProjectResourceAction action, bool overwrite)
        {
            return CreateActionPlan(
                resource,
                action,
                overwrite,
                hasInputPath: false,
                hasFieldName: false,
                hasValue: false);
        }

        private KarProjectResourceActionPlan CreateActionPlan(
            KarProjectResourceInfo resource,
            KarProjectResourceAction action,
            bool overwrite,
            bool hasInputPath,
            bool hasFieldName,
            bool hasValue)
        {
            KarProjectResourceOutputInfo output = action.RequiresOutputInfo && resource.CanQueryOutput
                ? CreateOutputInfo(resource)
                : null;
            KarProjectResourceByteInfo byteInfo = action.RequiresByteInfo && resource.CanReadBytes
                ? CreateByteInfo(resource)
                : null;
            bool canRun = true;
            string reason = "";

            if (action.RequiresInputFile)
            {
                canRun = hasInputPath;
                if (!canRun)
                    reason = "Requires an input file.";
            }
            else if (action.RequiresFieldName && !hasFieldName && action.RequiresValue && !hasValue)
            {
                canRun = false;
                reason = "Requires a field name and value.";
            }
            else if (action.RequiresFieldName && !hasFieldName)
            {
                canRun = false;
                reason = "Requires a field name.";
            }
            else if (action.RequiresValue && !hasValue)
            {
                canRun = false;
                reason = "Requires a value.";
            }
            else if (action.WritePolicy == KarProjectResourceActionWritePolicy.ModifiedResourceOutput)
            {
                canRun = output != null && output.Status == KarProjectResourceOutputStatus.SidecarDiffersFromEntry;
                if (!canRun)
                    reason = "Requires a modified A2D sidecar output.";
            }

            bool wouldWriteOutput = GetWouldWriteOutput(action, output, byteInfo, overwrite, canRun);
            if (string.IsNullOrEmpty(reason) && action.WritesOutput && !wouldWriteOutput)
                reason = overwrite ? "No output write is required." : "Output already exists; use overwrite to write again.";

            return new KarProjectResourceActionPlan(
                resource,
                action,
                output,
                byteInfo,
                overwrite,
                canRun,
                wouldWriteOutput,
                reason);
        }

        private static bool GetWouldWriteOutput(
            KarProjectResourceAction action,
            KarProjectResourceOutputInfo output,
            KarProjectResourceByteInfo byteInfo,
            bool overwrite,
            bool canRun)
        {
            if (!action.WritesOutput)
                return false;

            switch (action.WritePolicy)
            {
                case KarProjectResourceActionWritePolicy.None:
                    return false;
                case KarProjectResourceActionWritePolicy.Always:
                    return true;
                case KarProjectResourceActionWritePolicy.MissingByteDump:
                    return byteInfo != null && (overwrite || !byteInfo.HasOutput);
                case KarProjectResourceActionWritePolicy.MissingResourceOutput:
                    return output != null && (overwrite || !output.HasOutput);
                case KarProjectResourceActionWritePolicy.ModifiedResourceOutput:
                    return canRun;
                default:
                    throw new ArgumentOutOfRangeException(nameof(action.WritePolicy), "Unsupported resource action write policy.");
            }
        }

        private KarProjectResourceOutputInfo CreateOutputInfo(KarProjectResourceInfo resource)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));

            return GetAdapter(resource).CreateOutputInfo(resource);
        }

        private KarProjectResourceByteInfo CreateByteInfo(KarProjectResourceInfo resource)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));
            if (!resource.CanReadBytes)
                throw new NotSupportedException("Resource " + resource.Address + " does not support byte info.");

            return CreateByteInfo(resource, GetAdapter(resource).ReadBytes(resource));
        }

        private KarProjectResourceByteInfo CreateByteInfo(KarProjectResourceInfo resource, byte[] data)
        {
            string outputRelativePath = CreateByteDumpRelativePath(resource);
            return new KarProjectResourceByteInfo(
                resource,
                outputRelativePath,
                _project.Workspace.GetOutputAssetPath(outputRelativePath),
                data);
        }

        private static string CreateByteDumpRelativePath(KarProjectResourceInfo resource)
        {
            List<string> parts = new List<string> { "resource-bytes" };
            List<string> resourcePathParts = KarProjectWorkspace.NormalizeRelativePath(resource.RelativePath)
                .Split('/')
                .Select(SanitizePathSegment)
                .ToList();

            if (resource.Kind == KarResourceKind.File)
            {
                resourcePathParts[resourcePathParts.Count - 1] += ".bin";
                parts.AddRange(resourcePathParts);
            }
            else
            {
                parts.AddRange(resourcePathParts);
            }

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

    }
}
