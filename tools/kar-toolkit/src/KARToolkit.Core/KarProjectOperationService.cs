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
                    .Select(plan => KarProjectOperation.FromResourceActionPlan(
                        plan,
                        _project.OperationDomainRegistry.ResolveTargetDomain(plan.Resource)))
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
            return new KarProjectOperationPresetCatalog(_project, _project.OperationPresetRegistry.Definitions
                .Select(CreatePreset)
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

        private KarProjectOperationPreset CreatePreset(KarProjectOperationPresetDefinition definition)
        {
            return new KarProjectOperationPreset(
                definition,
                CreateCatalog(definition.CreateQueryOptions()));
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

    }
}
