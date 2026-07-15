using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceActionExecutor
    {
        private readonly KarProject _project;

        internal KarProjectResourceActionExecutor(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public KarProjectResourceActionExecutionResult Execute(
            string address,
            string actionId,
            KarProjectResourceActionExecutionOptions options = null)
        {
            options = options ?? new KarProjectResourceActionExecutionOptions();
            KarProjectResourceActionPlan plan = _project.ResourceService.GetActionPlan(address, actionId, options);
            if (!plan.CanRun)
                throw new InvalidOperationException("KAR resource action cannot run: " + plan.Address + " " + plan.ActionId + ". " + plan.Reason);

            object result;
            switch (plan.Action.ExecutionKind)
            {
                case KarProjectResourceActionExecutionKind.OutputStatus:
                    result = _project.ResourceService.GetOutput(address);
                    break;

                case KarProjectResourceActionExecutionKind.ByteStatus:
                    result = _project.ResourceService.GetByteInfo(address);
                    break;

                case KarProjectResourceActionExecutionKind.DumpBytes:
                    result = _project.ResourceService.DumpBytesToOutput(address, options.Overwrite);
                    break;

                case KarProjectResourceActionExecutionKind.ExportOutput:
                    result = _project.ResourceAddressService.ExportToOutput(address, options.Overwrite);
                    break;

                case KarProjectResourceActionExecutionKind.ImportFile:
                    result = _project.ResourceAddressService.ImportFromFile(address, options.InputPath);
                    break;

                case KarProjectResourceActionExecutionKind.FieldValues:
                    result = options.HasFieldName
                        ? (object)_project.ResourceAddressService.GetFieldValue(address, options.FieldName)
                        : _project.ResourceAddressService.QueryFieldValues(address);
                    break;

                case KarProjectResourceActionExecutionKind.SetScalar:
                    result = _project.ResourceAddressService.SetScalarFieldFromText(address, options.FieldName, options.Value);
                    break;

                case KarProjectResourceActionExecutionKind.ApplyOutput:
                    result = _project.ResourceService.ApplyOutput(address);
                    break;

                default:
                    throw new ArgumentException("Unsupported KAR resource action execution kind: " + plan.Action.ExecutionKindName + " (" + plan.ActionId + ")", nameof(actionId));
            }

            return new KarProjectResourceActionExecutionResult(plan, result);
        }

        public IReadOnlyList<KarProjectResourceActionExecutionResult> ExecuteBatch(
            KarProjectResourceActionPlanQueryOptions options,
            KarProjectResourceActionExecutionOptions executionOptions = null)
        {
            return ExecuteBatchResult(options, executionOptions).Results;
        }

        public KarProjectResourceActionBatchResult ExecuteBatchResult(
            KarProjectResourceActionPlanQueryOptions options,
            KarProjectResourceActionExecutionOptions executionOptions = null)
        {
            if (options == null)
                throw new ArgumentNullException(nameof(options));
            if (string.IsNullOrWhiteSpace(options.ActionId))
                throw new ArgumentException("Batch resource action execution requires a single action id.", nameof(options));

            executionOptions = executionOptions ?? new KarProjectResourceActionExecutionOptions();
            bool overwrite = options.Overwrite || executionOptions.Overwrite;
            executionOptions.Overwrite = overwrite;

            KarProjectResourceActionPlanQueryOptions effectiveOptions = new KarProjectResourceActionPlanQueryOptions
            {
                Resources = options.Resources,
                ActionId = options.ActionId,
                IsReadOnly = options.IsReadOnly,
                WritesOutput = options.WritesOutput,
                CanRun = options.CanRun ?? true,
                WouldWriteOutput = options.WouldWriteOutput,
                Overwrite = overwrite,
            };

            List<KarProjectResourceActionExecutionResult> results = new List<KarProjectResourceActionExecutionResult>();
            foreach (KarProjectResourceActionPlan plan in _project.ResourceService.QueryActionPlans(effectiveOptions))
            {
                if (!plan.SupportsBatch)
                {
                    NotSupportedException error = new NotSupportedException("KAR resource action does not support batch execution: " + plan.ActionId);
                    if (!executionOptions.ContinueOnError)
                        throw error;

                    results.Add(new KarProjectResourceActionExecutionResult(plan, null, error));
                    continue;
                }

                if (!plan.CanRun)
                {
                    InvalidOperationException error = new InvalidOperationException("KAR resource action cannot run: " + plan.Address + " " + plan.ActionId + ". " + plan.Reason);
                    if (!executionOptions.ContinueOnError)
                        throw error;

                    results.Add(new KarProjectResourceActionExecutionResult(plan, null, error));
                    continue;
                }

                try
                {
                    results.Add(Execute(plan.Address, plan.ActionId, executionOptions));
                }
                catch (Exception ex)
                {
                    if (!executionOptions.ContinueOnError)
                        throw;

                    results.Add(new KarProjectResourceActionExecutionResult(plan, null, ex));
                }
            }

            IReadOnlyList<KarProjectResourceActionExecutionResult> orderedResults = results
                .OrderBy(result => result.Resource.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ThenBy(result => result.Kind)
                .ThenBy(result => result.Address, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();

            return new KarProjectResourceActionBatchResult(
                effectiveOptions.ActionId,
                overwrite,
                executionOptions.ContinueOnError,
                orderedResults);
        }
    }
}
