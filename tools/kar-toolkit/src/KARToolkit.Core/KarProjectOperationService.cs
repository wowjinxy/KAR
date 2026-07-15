using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectOperationService
    {
        private readonly KarProject _project;

        internal KarProjectOperationService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public KarProjectOperationCatalog CreateCatalog(KarProjectOperationQueryOptions options = null)
        {
            options = options ?? new KarProjectOperationQueryOptions();
            KarProjectToolkitSurface surface = options.IncludeWorkflows
                ? _project.ToolkitService.CreateSurface(options.SnapshotOptions)
                : null;
            List<KarProjectOperation> operations = new List<KarProjectOperation>();

            if (surface != null)
            {
                operations.AddRange(surface.Workflows
                    .Select(KarProjectOperation.FromWorkflow)
                    .Where(options.Matches));
            }

            if (options.IncludeResourceActions)
            {
                operations.AddRange(_project.ResourceService.QueryActionPlans(options.CreateResourceActionPlanQuery())
                    .Select(plan => KarProjectOperation.FromResourceActionPlan(plan, InferTargetDomain(plan.Resource)))
                    .Where(options.Matches));
            }

            return new KarProjectOperationCatalog(_project, surface, operations);
        }

        public IReadOnlyList<KarProjectOperation> Query(KarProjectOperationQueryOptions options = null)
        {
            return CreateCatalog(options).Operations;
        }

        public KarProjectOperationPresetCatalog CreatePresetCatalog(KarProjectOperationPresetQueryOptions options = null)
        {
            options = options ?? new KarProjectOperationPresetQueryOptions();
            return new KarProjectOperationPresetCatalog(_project, CreateBuiltInPresets()
                .Where(options.Matches));
        }

        public IReadOnlyList<KarProjectOperationPreset> QueryPresets(KarProjectOperationPresetQueryOptions options = null)
        {
            return CreatePresetCatalog(options).Presets;
        }

        public KarProjectOperation Get(string operationId, KarProjectOperationQueryOptions options = null)
        {
            if (string.IsNullOrWhiteSpace(operationId))
                throw new ArgumentException("Operation id cannot be empty.", nameof(operationId));

            options = options ?? new KarProjectOperationQueryOptions();
            options.Id = operationId;

            IReadOnlyList<KarProjectOperation> operations = Query(options);
            if (operations.Count == 0)
                throw new ArgumentException("KAR project operation was not found: " + operationId, nameof(operationId));
            if (operations.Count > 1)
                throw new InvalidOperationException("KAR project operation id is ambiguous: " + operationId);

            return operations[0];
        }

        public KarProjectOperationExecutionResult Execute(
            string operationId,
            KarProjectResourceActionExecutionOptions executionOptions = null,
            KarProjectOperationQueryOptions queryOptions = null)
        {
            return Execute(Get(operationId, queryOptions), executionOptions);
        }

        public KarProjectOperationExecutionResult Execute(
            KarProjectOperation operation,
            KarProjectResourceActionExecutionOptions executionOptions = null)
        {
            if (operation == null)
                throw new ArgumentNullException(nameof(operation));
            if (!operation.IsResourceAction)
                throw new NotSupportedException("Only resource-action operations can be executed directly: " + operation.Id);

            KarProjectResourceActionExecutionResult result = _project.ResourceActionExecutor.Execute(
                operation.ResourceAddress,
                operation.ActionId,
                executionOptions);

            return new KarProjectOperationExecutionResult(operation, result);
        }

        public KarProjectOperationBatchResult ExecuteBatch(
            KarProjectOperationQueryOptions queryOptions,
            KarProjectResourceActionExecutionOptions executionOptions = null)
        {
            if (queryOptions == null)
                throw new ArgumentNullException(nameof(queryOptions));

            executionOptions = executionOptions ?? new KarProjectResourceActionExecutionOptions();
            KarProjectOperationQueryOptions effectiveQuery = CreateBatchQuery(queryOptions, executionOptions);
            List<KarProjectOperationExecutionResult> results = new List<KarProjectOperationExecutionResult>();

            foreach (KarProjectOperation operation in Query(effectiveQuery))
            {
                if (!operation.SupportsBatch)
                {
                    NotSupportedException error = new NotSupportedException("KAR project operation does not support batch execution: " + operation.Id);
                    if (!executionOptions.ContinueOnError)
                        throw error;

                    results.Add(CreateFailedOperationResult(operation, error));
                    continue;
                }

                if (operation.CanRun == false)
                {
                    InvalidOperationException error = new InvalidOperationException("KAR project operation cannot run: " + operation.Id + ". " + operation.Reason);
                    if (!executionOptions.ContinueOnError)
                        throw error;

                    results.Add(CreateFailedOperationResult(operation, error));
                    continue;
                }

                try
                {
                    results.Add(Execute(operation, executionOptions));
                }
                catch (Exception ex)
                {
                    if (!executionOptions.ContinueOnError)
                        throw;

                    results.Add(CreateFailedOperationResult(operation, ex));
                }
            }

            IReadOnlyList<KarProjectOperationExecutionResult> orderedResults = results
                .OrderBy(result => result.Operation.TargetDomainId, StringComparer.OrdinalIgnoreCase)
                .ThenBy(result => result.Operation.Command, StringComparer.OrdinalIgnoreCase)
                .ThenBy(result => result.Operation.ResourceAddress, StringComparer.OrdinalIgnoreCase)
                .ThenBy(result => result.Operation.Id, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();

            return new KarProjectOperationBatchResult(
                executionOptions.Overwrite,
                executionOptions.ContinueOnError,
                orderedResults);
        }

        private static KarProjectOperationQueryOptions CreateBatchQuery(
            KarProjectOperationQueryOptions queryOptions,
            KarProjectResourceActionExecutionOptions executionOptions)
        {
            return new KarProjectOperationQueryOptions
            {
                IncludeWorkflows = false,
                IncludeResourceActions = true,
                Kind = KarProjectOperationKind.ResourceAction,
                Id = queryOptions.Id,
                DomainId = queryOptions.DomainId,
                Command = queryOptions.Command,
                ActionId = queryOptions.ActionId,
                ResourceAddress = queryOptions.ResourceAddress,
                ResourceKind = queryOptions.ResourceKind,
                Text = queryOptions.Text,
                IsReadOnly = queryOptions.IsReadOnly,
                WritesOutput = queryOptions.WritesOutput,
                SupportsBatch = queryOptions.SupportsBatch,
                RequiresInputFile = queryOptions.RequiresInputFile,
                RequiresFieldName = queryOptions.RequiresFieldName,
                RequiresValue = queryOptions.RequiresValue,
                HasTargets = queryOptions.HasTargets,
                HasOutputs = queryOptions.HasOutputs,
                HasModifiedOutputs = queryOptions.HasModifiedOutputs,
                HasInspectionIssues = queryOptions.HasInspectionIssues,
                CanRun = queryOptions.CanRun ?? true,
                WouldWriteOutput = queryOptions.WouldWriteOutput,
                Overwrite = queryOptions.Overwrite || executionOptions.Overwrite,
                SnapshotOptions = queryOptions.SnapshotOptions,
            };
        }

        private IReadOnlyList<KarProjectOperationPreset> CreateBuiltInPresets()
        {
            return new[]
            {
                CreatePreset(
                    "script-byte-status",
                    "script-tables",
                    "Script Byte Status",
                    "Report active byte and output dump status for loose and packaged script tables.",
                    "byte-status",
                    null,
                    isReadOnly: true,
                    writesOutput: false,
                    supportsBatch: true,
                    requiresInputFile: false,
                    requiresFieldName: false,
                    requiresValue: false,
                    canRun: true,
                    wouldWriteOutput: false,
                    hasModifiedOutputs: null),
                CreatePreset(
                    "dump-script-bytes",
                    "script-tables",
                    "Dump Script Bytes",
                    "Write raw bytes for loose and packaged script tables under resource-bytes/ in the output folder.",
                    "dump-bytes",
                    null,
                    isReadOnly: false,
                    writesOutput: true,
                    supportsBatch: true,
                    requiresInputFile: false,
                    requiresFieldName: false,
                    requiresValue: false,
                    canRun: true,
                    wouldWriteOutput: true,
                    hasModifiedOutputs: null),
                CreatePreset(
                    "dump-all-resource-bytes",
                    "resources",
                    "Dump All Resource Bytes",
                    "Write raw bytes for every readable project resource under resource-bytes/ in the output folder.",
                    "dump-bytes",
                    null,
                    isReadOnly: false,
                    writesOutput: true,
                    supportsBatch: true,
                    requiresInputFile: false,
                    requiresFieldName: false,
                    requiresValue: false,
                    canRun: true,
                    wouldWriteOutput: true,
                    hasModifiedOutputs: null),
                CreatePreset(
                    "resource-output-status",
                    "resources",
                    "Resource Output Status",
                    "Report output-side status for resources that can be staged or applied.",
                    "output-status",
                    null,
                    isReadOnly: true,
                    writesOutput: false,
                    supportsBatch: true,
                    requiresInputFile: false,
                    requiresFieldName: false,
                    requiresValue: false,
                    canRun: true,
                    wouldWriteOutput: false,
                    hasModifiedOutputs: null),
                CreatePreset(
                    "root-field-values",
                    "resources",
                    "Root Field Values",
                    "Read labeled field values from HSD root resources with known schemas.",
                    "field-values",
                    KarResourceKind.HsdRoot,
                    isReadOnly: true,
                    writesOutput: false,
                    supportsBatch: true,
                    requiresInputFile: false,
                    requiresFieldName: false,
                    requiresValue: false,
                    canRun: true,
                    wouldWriteOutput: false,
                    hasModifiedOutputs: null),
                CreatePreset(
                    "apply-modified-resource-outputs",
                    "mod-output",
                    "Apply Modified Resource Outputs",
                    "Pack modified output-side sidecars back into output package copies.",
                    "apply-output",
                    null,
                    isReadOnly: false,
                    writesOutput: true,
                    supportsBatch: true,
                    requiresInputFile: false,
                    requiresFieldName: false,
                    requiresValue: false,
                    canRun: true,
                    wouldWriteOutput: true,
                    hasModifiedOutputs: true),
            };
        }

        private KarProjectOperationPreset CreatePreset(
            string id,
            string domainId,
            string displayName,
            string description,
            string actionId,
            KarResourceKind? resourceKind,
            bool isReadOnly,
            bool writesOutput,
            bool supportsBatch,
            bool requiresInputFile,
            bool requiresFieldName,
            bool requiresValue,
            bool? canRun,
            bool? wouldWriteOutput,
            bool? hasModifiedOutputs)
        {
            return new KarProjectOperationPreset(
                id,
                domainId,
                displayName,
                description,
                actionId,
                resourceKind,
                isReadOnly,
                writesOutput,
                supportsBatch,
                requiresInputFile,
                requiresFieldName,
                requiresValue,
                canRun,
                wouldWriteOutput,
                hasModifiedOutputs,
                CreateCatalog(CreatePresetQueryOptions(
                    domainId,
                    actionId,
                    resourceKind,
                    isReadOnly,
                    writesOutput,
                    supportsBatch,
                    requiresInputFile,
                    requiresFieldName,
                    requiresValue,
                    canRun,
                    wouldWriteOutput,
                    hasModifiedOutputs)));
        }

        private static KarProjectOperationQueryOptions CreatePresetQueryOptions(
            string domainId,
            string actionId,
            KarResourceKind? resourceKind,
            bool isReadOnly,
            bool writesOutput,
            bool supportsBatch,
            bool requiresInputFile,
            bool requiresFieldName,
            bool requiresValue,
            bool? canRun,
            bool? wouldWriteOutput,
            bool? hasModifiedOutputs)
        {
            return new KarProjectOperationQueryOptions
            {
                IncludeWorkflows = false,
                IncludeResourceActions = true,
                Kind = KarProjectOperationKind.ResourceAction,
                DomainId = domainId,
                ActionId = actionId,
                ResourceKind = resourceKind,
                IsReadOnly = isReadOnly,
                WritesOutput = writesOutput,
                SupportsBatch = supportsBatch,
                RequiresInputFile = requiresInputFile,
                RequiresFieldName = requiresFieldName,
                RequiresValue = requiresValue,
                CanRun = canRun,
                WouldWriteOutput = wouldWriteOutput,
                HasModifiedOutputs = hasModifiedOutputs,
            };
        }

        private static KarProjectOperationExecutionResult CreateFailedOperationResult(
            KarProjectOperation operation,
            Exception error)
        {
            if (operation.ResourceActionPlan == null)
                throw new NotSupportedException("Only resource-action operations can be executed directly: " + operation.Id, error);

            return new KarProjectOperationExecutionResult(
                operation,
                new KarProjectResourceActionExecutionResult(operation.ResourceActionPlan, null, error));
        }

        private static string InferTargetDomain(KarProjectResourceInfo resource)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));

            if (resource.Category != null && string.Equals(resource.Category, "Scripts", StringComparison.OrdinalIgnoreCase))
                return "script-tables";
            if (resource.A2DEntry != null)
                return resource.A2DEntry.IsScriptTable ? "script-tables" : "a2d-packages";
            if (resource.File != null)
            {
                if (resource.File.IsScriptTable)
                    return "script-tables";
                if (resource.File.IsA2DPackage)
                    return "a2d-packages";
                if (resource.File.IsMapBundlePart)
                    return "maps";
                if (resource.File.Kind == KarFileKind.VehicleData)
                    return "vehicles";
                if (resource.File.IsHsdArchive)
                    return "archives";
            }

            return resource.IsFile ? "files" : "resources";
        }
    }
}
