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
            WriteJson(new
            {
                file = ToProjectFileDto(result.File),
                rootName = edit.RootName,
                dataDefinitionId = edit.DataDefinitionId,
                field = ToDataFieldDto(edit.Field),
                previousValue = ToFieldValueDto(edit.PreviousValue),
                newValue = ToFieldValueDto(edit.NewValue),
                outputPath = write.OutputPath,
            });
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
}
