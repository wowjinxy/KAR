using KARToolkit.Core;
using static KARToolkit.Cli.KarCliDtoFactory;
using static KARToolkit.Cli.KarCliJsonWriter;
using static KARToolkit.Cli.KarCliProjectFactory;

namespace KARToolkit.Cli;

internal static class KarCliEditCommands
{
    public static int SetScalar(KarCliOptions options)
    {
        options.RequirePositionals("set-scalar", 5);
        KarProject project = OpenProject(options);
        string relativePath = options.Positionals[1];
        string rootOrSchema = options.Positionals[2];
        string fieldName = options.Positionals[3];
        string rawValue = options.Positionals[4];

        KarProjectScalarEditResult result = project.EditService.SetScalarFieldFromText(
            relativePath,
            rootOrSchema,
            fieldName,
            rawValue,
            options.Schema);
        KarDataFieldEditResult edit = result.Edit;
        KarProjectFileWriteResult write = result.WriteResult;

        if (options.Json)
        {
            WriteJson(ToProjectScalarEditResultDto(result));
            return 0;
        }

        Console.WriteLine("Edited scalar: " + result.RelativePath);
        Console.WriteLine("Root: " + edit.RootName);
        Console.WriteLine("Field: " + edit.Field.Name);
        Console.WriteLine("Previous: " + edit.PreviousValue.DisplayValue);
        Console.WriteLine("New: " + edit.NewValue.DisplayValue);
        Console.WriteLine("Output: " + write.OutputPath);
        return 0;
    }

    public static int SetResourceScalar(KarCliOptions options)
    {
        options.RequirePositionals("set-resource-scalar", 4);
        KarProject project = OpenProject(options);
        string rootAddress = options.Positionals[1];
        string fieldName = options.Positionals[2];
        string rawValue = options.Positionals[3];

        KarProjectResourceScalarEditResult result = project.ResourceAddressService.SetScalarFieldFromText(
            rootAddress,
            fieldName,
            rawValue);
        KarDataFieldEditResult edit = result.Edit;

        if (options.Json)
        {
            WriteJson(ToProjectResourceScalarEditResultDto(result));
            return 0;
        }

        Console.WriteLine("Edited resource scalar: " + result.Address);
        Console.WriteLine("Root: " + edit.RootName);
        Console.WriteLine("Field: " + edit.Field.Name);
        Console.WriteLine("Previous: " + edit.PreviousValue.DisplayValue);
        Console.WriteLine("New: " + edit.NewValue.DisplayValue);
        Console.WriteLine("Output: " + result.OutputPath);
        return 0;
    }

    public static int SetResourceDataField(KarCliOptions options)
    {
        options.RequirePositionals("resource-data-edit", 4);
        KarProject project = OpenProject(options);
        string address = options.Positionals[1];
        string fieldPathOrName = options.Positionals[2];
        string value = options.Positionals[3];

        KarProjectResourceActionExecutionResult result = project.ExecuteResourceDataFieldEdit(
            address,
            fieldPathOrName,
            value);

        return KarCliResourceActionCommands.WriteActionResult(options, result);
    }
}
