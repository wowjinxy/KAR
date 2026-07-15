using KARToolkit.Core;
using static KARToolkit.Cli.KarCliDtoFactory;
using static KARToolkit.Cli.KarCliJsonWriter;
using static KARToolkit.Cli.KarCliProjectFactory;
using static KARToolkit.Cli.KarCliQueryFactory;
using static KARToolkit.Cli.KarCliTextWriter;

namespace KARToolkit.Cli;

internal static class KarCliResourceActionCommands
{
    public static int Execute(KarCliOptions options)
    {
        options.RequirePositionals("resource-action", 3);
        KarProject project = OpenProject(options);
        string address = options.Positionals[1];
        string actionId = options.Positionals[2];
        KarProjectResourceActionExecutionOptions executionOptions = CreateExecutionOptions(options, actionId);
        KarProjectResourceActionExecutionResult result = project.ResourceActionExecutor.Execute(address, actionId, executionOptions);

        return WriteActionResult(options, result);
    }

    public static int ExecuteBatch(KarCliOptions options)
    {
        options.RequirePositionals("resource-action-batch", 2);
        KarProject project = OpenProject(options);
        string actionId = options.Positionals[1];
        KarProjectResourceActionExecutionOptions executionOptions = CreateBatchExecutionOptions(options, actionId);
        KarProjectResourceActionPlanQueryOptions query = CreateResourceActionBatchPlanQuery(options, actionId);
        KarProjectResourceActionBatchResult batch = project.ResourceActionExecutor.ExecuteBatchResult(query, executionOptions);

        if (options.Json)
        {
            WriteJson(ToResourceActionBatchResultDto(batch));
            return batch.HasFailures ? 1 : 0;
        }

        Console.WriteLine("Executed resource actions: " + batch.ResultCount + " succeeded=" + batch.SucceededCount + " failed=" + batch.FailedCount);
        foreach (KarProjectResourceActionExecutionResult result in batch.Results)
        {
            PrintProjectResourceActionPlan(result.Plan);
            PrintResourceActionResult(result);
        }

        return batch.HasFailures ? 1 : 0;
    }

    private static KarProjectResourceActionExecutionOptions CreateExecutionOptions(KarCliOptions options, string actionId)
    {
        KarProjectResourceActionExecutionOptions executionOptions = new KarProjectResourceActionExecutionOptions
        {
            Overwrite = options.Overwrite,
            ContinueOnError = options.ContinueOnError,
        };

        switch (actionId.ToLowerInvariant())
        {
            case "import-file":
                options.RequirePositionals("resource-action import-file", 4);
                executionOptions.InputPath = options.Positionals[3];
                break;

            case "field-values":
                if (options.Positionals.Count >= 4)
                    executionOptions.FieldName = options.Positionals[3];
                break;

            case "set-scalar":
                options.RequirePositionals("resource-action set-scalar", 5);
                executionOptions.FieldName = options.Positionals[3];
                executionOptions.Value = options.Positionals[4];
                break;
        }

        return executionOptions;
    }

    private static KarProjectResourceActionExecutionOptions CreateBatchExecutionOptions(KarCliOptions options, string actionId)
    {
        KarProjectResourceActionExecutionOptions executionOptions = new KarProjectResourceActionExecutionOptions
        {
            Overwrite = options.Overwrite,
            ContinueOnError = options.ContinueOnError,
        };

        if (actionId.Equals("field-values", StringComparison.OrdinalIgnoreCase) && options.Positionals.Count >= 3)
            executionOptions.FieldName = options.Positionals[2];

        return executionOptions;
    }

    internal static int WriteActionResult(
        KarCliOptions options,
        KarProjectResourceActionExecutionResult result)
    {
        if (options.Json)
        {
            WriteJson(ToResourceActionExecutionResultDto(result));
            return 0;
        }

        PrintProjectResourceActionPlan(result.Plan);
        PrintResourceActionResult(result);
        return 0;
    }

    private static object ToResourceActionExecutionResultDto(KarProjectResourceActionExecutionResult result)
    {
        return new
        {
            succeeded = result.Succeeded,
            resultKind = result.ResultKind,
            isReadOnly = result.IsReadOnly,
            writesOutput = result.WritesOutput,
            wouldWriteOutput = result.WouldWriteOutput,
            wroteOutput = result.WroteOutput,
            skippedOutputWrite = result.SkippedOutputWrite,
            outputRelativePath = result.OutputRelativePath,
            outputPath = result.OutputPath,
            plan = ToProjectResourceActionPlanDto(result.Plan),
            errorType = result.ErrorType,
            errorMessage = result.ErrorMessage,
            result = result.Failed ? null : ToResourceActionResultDto(result),
        };
    }

    private static object ToResourceActionBatchResultDto(KarProjectResourceActionBatchResult batch)
    {
        return new
        {
            actionId = batch.ActionId,
            overwrite = batch.Overwrite,
            continueOnError = batch.ContinueOnError,
            resultCount = batch.ResultCount,
            succeededCount = batch.SucceededCount,
            failedCount = batch.FailedCount,
            readOnlyCount = batch.ReadOnlyCount,
            writeActionCount = batch.WriteActionCount,
            wouldWriteOutputCount = batch.WouldWriteOutputCount,
            wroteOutputCount = batch.WroteOutputCount,
            skippedOutputWriteCount = batch.SkippedOutputWriteCount,
            hasFailures = batch.HasFailures,
            results = batch.Results.Select(ToResourceActionExecutionResultDto).ToList(),
        };
    }

    private static object ToResourceActionResultDto(KarProjectResourceActionExecutionResult result)
    {
        if (result.Failed)
            return null;
        if (result.OutputInfo != null)
            return ToProjectResourceOutputDto(result.OutputInfo);
        if (result.ByteInfo != null)
            return ToProjectResourceByteInfoDto(result.ByteInfo);
        if (result.ByteDumpResult != null)
            return ToProjectResourceByteDumpResultDto(result.ByteDumpResult);
        if (result.ExportResult != null)
            return ToProjectResourceExportResultDto(result.ExportResult);
        if (result.ImportResult != null)
            return ToProjectResourceImportResultDto(result.ImportResult);
        if (result.FieldValue != null)
            return ToProjectResourceFieldValueDto(result.FieldValue);
        if (result.FieldValues != null)
            return result.FieldValues.Select(ToProjectResourceFieldValueDto).ToList();
        if (result.ScalarEditResult != null)
            return ToProjectResourceScalarEditResultDto(result.ScalarEditResult);
        if (result.OutputApplyResult != null)
            return ToProjectResourceOutputApplyResultDto(result.OutputApplyResult);

        throw new ArgumentException("Unsupported resource action result: " + result.ActionId, nameof(result));
    }

    private static void PrintResourceActionResult(KarProjectResourceActionExecutionResult result)
    {
        if (result.Failed)
        {
            Console.WriteLine("Error: " + result.ErrorType + " - " + result.ErrorMessage);
        }
        else if (result.OutputInfo != null)
            PrintProjectResourceOutput(result.OutputInfo);
        else if (result.ByteInfo != null)
            PrintProjectResourceByteInfo(result.ByteInfo);
        else if (result.ByteDumpResult != null)
            PrintProjectResourceByteDumpResult(result.ByteDumpResult);
        else if (result.ExportResult != null)
            PrintProjectResourceExportResult(result.ExportResult);
        else if (result.ImportResult != null)
            PrintProjectResourceImportResult(result.ImportResult);
        else if (result.FieldValue != null)
            PrintProjectResourceFieldValue(result.FieldValue);
        else if (result.FieldValues != null)
        {
            foreach (KarProjectResourceFieldInfo field in result.FieldValues)
                PrintProjectResourceFieldValue(field);
        }
        else if (result.ScalarEditResult != null)
            PrintProjectResourceScalarEditResult(result.ScalarEditResult);
        else if (result.OutputApplyResult != null)
            PrintProjectResourceOutputApplyResult(result.OutputApplyResult);
        else
            throw new ArgumentException("Unsupported resource action result: " + result.ActionId, nameof(result));
    }
}
