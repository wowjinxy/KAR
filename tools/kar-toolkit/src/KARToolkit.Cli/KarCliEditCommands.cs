using KARToolkit.Core;
using System.Globalization;
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

        KarProjectHsdArchive archive = project.ArchiveService.OpenHsdArchive(relativePath);
        KarArchiveInfo archiveInfo = archive.Inspect();
        KarArchiveRootInfo rootInfo = options.Schema
            ? archiveInfo.GetRootByDataDefinition(rootOrSchema)
            : archiveInfo.GetRoot(rootOrSchema);

        if (rootInfo.DataDefinition == null)
            throw new InvalidOperationException("KAR archive root has no data definition: " + rootInfo.Name);

        KarDataFieldDefinition field = rootInfo.DataDefinition.GetField(fieldName);
        if (!field.IsScalar)
            throw new InvalidOperationException("Field is not a writable scalar field: " + field.Name);

        KarDataFieldEditResult edit = field.IsFloatScalar
            ? SetFloatScalar(archive, options.Schema, rootOrSchema, field.Name, rawValue)
            : SetIntegerScalar(archive, options.Schema, rootOrSchema, field.Name, rawValue);
        KarProjectFileWriteResult write = archive.SaveToOutput();

        if (options.Json)
        {
            WriteJson(new
            {
                file = ToProjectFileDto(archive.File),
                rootName = edit.RootName,
                dataDefinitionId = edit.DataDefinitionId,
                field = ToDataFieldDto(edit.Field),
                previousValue = ToFieldValueDto(edit.PreviousValue),
                newValue = ToFieldValueDto(edit.NewValue),
                outputPath = write.OutputPath,
            });
            return 0;
        }

        Console.WriteLine("Edited scalar: " + archive.RelativePath);
        Console.WriteLine("Root: " + edit.RootName);
        Console.WriteLine("Field: " + edit.Field.Name);
        Console.WriteLine("Previous: " + edit.PreviousValue.DisplayValue);
        Console.WriteLine("New: " + edit.NewValue.DisplayValue);
        Console.WriteLine("Output: " + write.OutputPath);
        return 0;
    }

    private static KarDataFieldEditResult SetIntegerScalar(
        KarProjectHsdArchive archive,
        bool bySchema,
        string rootOrSchema,
        string fieldName,
        string rawValue)
    {
        long value = ParseInteger(rawValue);
        return bySchema
            ? archive.SetScalarFieldByDataDefinition(rootOrSchema, fieldName, value)
            : archive.SetScalarField(rootOrSchema, fieldName, value);
    }

    private static KarDataFieldEditResult SetFloatScalar(
        KarProjectHsdArchive archive,
        bool bySchema,
        string rootOrSchema,
        string fieldName,
        string rawValue)
    {
        double value = double.Parse(rawValue, NumberStyles.Float, CultureInfo.InvariantCulture);
        return bySchema
            ? archive.SetScalarFieldByDataDefinition(rootOrSchema, fieldName, value)
            : archive.SetScalarField(rootOrSchema, fieldName, value);
    }

    private static long ParseInteger(string rawValue)
    {
        if (string.IsNullOrWhiteSpace(rawValue))
            throw new ArgumentException("Integer value cannot be empty.");

        string value = rawValue.Trim();
        bool negative = value.StartsWith("-", StringComparison.Ordinal);
        string unsigned = negative ? value.Substring(1) : value;
        if (unsigned.StartsWith("0x", StringComparison.OrdinalIgnoreCase))
        {
            long parsed = Convert.ToInt64(unsigned.Substring(2), 16);
            return negative ? -parsed : parsed;
        }

        return long.Parse(value, NumberStyles.Integer, CultureInfo.InvariantCulture);
    }
}
