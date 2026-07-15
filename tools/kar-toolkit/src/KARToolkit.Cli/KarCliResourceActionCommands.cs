using KARToolkit.Core;
using static KARToolkit.Cli.KarCliDtoFactory;
using static KARToolkit.Cli.KarCliJsonWriter;
using static KARToolkit.Cli.KarCliProjectFactory;
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
        KarProjectResourceActionPlan plan = project.ResourceService.GetActionPlan(address, actionId, options.Overwrite);

        switch (plan.ActionId)
        {
            case "output-status":
                return WriteActionResult(options, plan, project.ResourceService.GetOutput(address), ToProjectResourceOutputDto, PrintProjectResourceOutput);

            case "byte-status":
                return WriteActionResult(options, plan, project.ResourceService.GetByteInfo(address), ToProjectResourceByteInfoDto, PrintProjectResourceByteInfo);

            case "dump-bytes":
                return WriteActionResult(options, plan, project.DumpResourceBytesToOutput(address, options.Overwrite), ToProjectResourceByteDumpResultDto, PrintProjectResourceByteDumpResult);

            case "export-output":
                return WriteActionResult(options, plan, project.ExportResourceToOutput(address, options.Overwrite), ToProjectResourceExportResultDto, PrintProjectResourceExportResult);

            case "import-file":
                options.RequirePositionals("resource-action import-file", 4);
                return WriteActionResult(options, plan, project.ImportResourceFromFile(address, options.Positionals[3]), ToProjectResourceImportResultDto, PrintProjectResourceImportResult);

            case "field-values":
                return ExecuteFieldValues(options, project, plan, address);

            case "set-scalar":
                options.RequirePositionals("resource-action set-scalar", 5);
                return WriteActionResult(options, plan, project.SetResourceScalarFieldFromText(address, options.Positionals[3], options.Positionals[4]), ToProjectResourceScalarEditResultDto, PrintProjectResourceScalarEditResult);

            case "apply-output":
                return WriteActionResult(options, plan, project.ApplyResourceOutput(address), ToProjectResourceOutputApplyResultDto, PrintProjectResourceOutputApplyResult);

            default:
                throw new ArgumentException("Unsupported resource action: " + plan.ActionId);
        }
    }

    private static int ExecuteFieldValues(
        KarCliOptions options,
        KarProject project,
        KarProjectResourceActionPlan plan,
        string address)
    {
        if (options.Positionals.Count >= 4)
        {
            KarProjectResourceFieldInfo field = project.GetResourceFieldValue(address, options.Positionals[3]);
            return WriteActionResult(options, plan, field, ToProjectResourceFieldValueDto, PrintProjectResourceFieldValue);
        }

        IReadOnlyList<KarProjectResourceFieldInfo> fields = project.QueryResourceFieldValues(new KarProjectResourceFieldQueryOptions
        {
            Resources = new KarProjectResourceQueryOptions
            {
                Address = address,
                Kind = KarResourceKind.HsdRoot,
            },
        });

        if (options.Json)
        {
            WriteJson(new
            {
                plan = ToProjectResourceActionPlanDto(plan),
                result = fields.Select(ToProjectResourceFieldValueDto).ToList(),
            });
            return 0;
        }

        PrintProjectResourceActionPlan(plan);
        foreach (KarProjectResourceFieldInfo field in fields)
            PrintProjectResourceFieldValue(field);
        return 0;
    }

    private static int WriteActionResult<T>(
        KarCliOptions options,
        KarProjectResourceActionPlan plan,
        T result,
        Func<T, object> toDto,
        Action<T> print)
    {
        if (options.Json)
        {
            WriteJson(new
            {
                plan = ToProjectResourceActionPlanDto(plan),
                result = toDto(result),
            });
            return 0;
        }

        PrintProjectResourceActionPlan(plan);
        print(result);
        return 0;
    }
}
