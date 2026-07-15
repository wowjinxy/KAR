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
        IReadOnlyList<KarProjectResourceActionExecutionResult> results = project.ResourceActionExecutor.ExecuteBatch(query, executionOptions);

        if (options.Json)
        {
            WriteJson(results.Select(ToResourceActionExecutionResultDto).ToList());
            return 0;
        }

        Console.WriteLine("Executed resource actions: " + results.Count);
        foreach (KarProjectResourceActionExecutionResult result in results)
        {
            PrintProjectResourceActionPlan(result.Plan);
            PrintResourceActionResult(result);
        }

        return 0;
    }

    private static KarProjectResourceActionExecutionOptions CreateExecutionOptions(KarCliOptions options, string actionId)
    {
        KarProjectResourceActionExecutionOptions executionOptions = new KarProjectResourceActionExecutionOptions
        {
            Overwrite = options.Overwrite,
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
        };

        if (actionId.Equals("field-values", StringComparison.OrdinalIgnoreCase) && options.Positionals.Count >= 3)
            executionOptions.FieldName = options.Positionals[2];

        return executionOptions;
    }

    private static int WriteActionResult(
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
            plan = ToProjectResourceActionPlanDto(result.Plan),
            result = ToResourceActionResultDto(result),
        };
    }

    private static object ToResourceActionResultDto(KarProjectResourceActionExecutionResult result)
    {
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
        if (result.OutputInfo != null)
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
