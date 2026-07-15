using KARToolkit.Core;
using KARToolkit.Core.AirRide;
using static KARToolkit.Cli.KarCliDtoFactory;
using static KARToolkit.Cli.KarCliJsonWriter;
using static KARToolkit.Cli.KarCliProjectFactory;
using static KARToolkit.Cli.KarCliTextWriter;

namespace KARToolkit.Cli;

internal static class KarCliInspectionCommands
{
    public static int ShowProject(KarCliOptions options)
    {
        options.RequirePositionals("project", 1);
        KarProject project = OpenProject(options);

        if (options.Json)
        {
            WriteJson(ToProjectDto(project));
            return 0;
        }

        Console.WriteLine("Project: " + project.Name);
        Console.WriteLine("Source: " + project.SourceRoot);
        Console.WriteLine("Source files: " + project.SourceFilesRoot);
        Console.WriteLine("Output: " + project.OutputRoot);
        Console.WriteLine("Output files: " + project.OutputFilesRoot);
        Console.WriteLine("Files: " + project.Files.Count);
        Console.WriteLine("Maps: " + project.Maps.Count);

        foreach (IGrouping<string, KarProjectFile> group in project.Files.GroupBy(file => file.Category).OrderBy(group => group.Key))
            Console.WriteLine("  " + group.Key + ": " + group.Count());

        return 0;
    }

    public static int ShowMaps(KarCliOptions options)
    {
        options.RequirePositionals("maps", 1);
        KarProject project = OpenProject(options);

        if (options.Json)
        {
            WriteJson(project.Maps.Select(ToMapBundleDto).ToList());
            return 0;
        }

        foreach (KarMapBundle map in project.Maps)
        {
            string pieces = string.Join(", ", map.Files.Select(file => file.RelativePath));
            Console.WriteLine(map.Name + ": " + pieces);
        }

        return 0;
    }

    public static int ShowMap(KarCliOptions options)
    {
        options.RequirePositionals("map", 2);
        KarProject project = OpenProject(options);
        KarMapInfo map = project.Inspector.InspectMap(options.Positionals[1]);

        if (options.Json)
        {
            WriteJson(ToMapInfoDto(map));
            return 0;
        }

        Console.WriteLine("Map: " + map.Name);
        PrintArchiveSlot("Data", map.DataArchive);
        PrintArchiveSlot("Model", map.ModelArchive);
        PrintArchiveSlot("Event/Script", map.ScriptArchive);

        if (map.HasMissingRequiredRoots)
        {
            Console.WriteLine("Missing required roots:");
            foreach (KarRootDefinition root in map.MissingRequiredRoots)
                Console.WriteLine("  " + root.Pattern);
        }

        return 0;
    }

    public static int ShowArchive(KarCliOptions options)
    {
        options.RequirePositionals("archive", 2);
        KarProject project = OpenProject(options);
        KarArchiveInfo archive = project.Inspector.InspectHsdArchive(options.Positionals[1]);

        if (options.Json)
        {
            WriteJson(ToArchiveDto(archive));
            return 0;
        }

        PrintArchive(archive, "");
        return 0;
    }

    public static int ShowA2D(KarCliOptions options)
    {
        options.RequirePositionals("a2d", 2);
        KarProject project = OpenProject(options);
        A2DPackage package = project.ArchiveStore.OpenA2DPackage(options.Positionals[1]);

        if (options.Json)
        {
            WriteJson(new
            {
                path = options.Positionals[1],
                entryCount = package.Entries.Count,
                entries = package.Entries.Select(ToA2DEntryDto).ToList(),
            });
            return 0;
        }

        Console.WriteLine("A2D: " + options.Positionals[1]);
        Console.WriteLine("Entries: " + package.Entries.Count);
        foreach (A2DPackageEntry entry in package.Entries)
            Console.WriteLine("  [" + entry.Index + "] " + entry.Name + " offset=0x" + entry.DataOffset.ToString("X") + " size=0x" + entry.Size.ToString("X"));

        return 0;
    }

    public static int ValidateProject(KarCliOptions options)
    {
        options.RequirePositionals("validate", 1);
        KarProject project = OpenProject(options);
        KarValidationReport report = project.Validator.Validate(new KarValidationOptions
        {
            ReportUnknownRoots = !options.NoUnknownRoots,
        });

        if (options.Json)
        {
            WriteJson(ToValidationReportDto(report));
            return report.IsValid ? 0 : 2;
        }

        Console.WriteLine("Project: " + project.Name);
        Console.WriteLine("Files: " + report.FileCount);
        Console.WriteLine("Maps: " + report.MapCount);
        Console.WriteLine("HSD archives checked: " + report.HsdArchiveCount);
        Console.WriteLine("A2D packages checked: " + report.A2DPackageCount);
        Console.WriteLine("Errors: " + report.Errors.Count);
        Console.WriteLine("Warnings: " + report.Warnings.Count);
        Console.WriteLine("Info: " + report.Infos.Count);

        foreach (KarValidationIssue issue in report.Issues)
            PrintValidationIssue(issue);

        return report.IsValid ? 0 : 2;
    }

    public static int ValidateSchemas(KarCliOptions options)
    {
        options.RequirePositionals("validate-schemas", 0);
        KarDataDefinitionValidationReport report = KarDataDefinitionValidator.ValidateBuiltIn();

        if (options.Json)
        {
            WriteJson(ToDataDefinitionValidationReportDto(report));
            return report.IsValid ? 0 : 2;
        }

        Console.WriteLine("Schemas: " + report.DefinitionCount);
        Console.WriteLine("Errors: " + report.ErrorCount);
        Console.WriteLine("Warnings: " + report.WarningCount);
        Console.WriteLine("Info: " + report.InfoCount);

        foreach (KarDataDefinitionValidationIssue issue in report.Issues)
            PrintDataDefinitionValidationIssue(issue);

        return report.IsValid ? 0 : 2;
    }

    public static int ShowDefinitions(KarCliOptions options)
    {
        options.RequirePositionals("definitions", 0);
        List<KarDataDefinition> definitions = KarDataDefinitionCatalog.All
            .OrderBy(definition => definition.Category)
            .ThenBy(definition => definition.DisplayName)
            .ToList();

        if (options.Json)
        {
            WriteJson(definitions.Select(ToDataDefinitionDto).ToList());
            return 0;
        }

        foreach (KarDataDefinition definition in definitions)
            Console.WriteLine(definition.Id + " (" + definition.Category + "): " + definition.DisplayName + " - " + definition.Fields.Count + " field(s)");

        return 0;
    }

    public static int ShowDefinition(KarCliOptions options)
    {
        options.RequirePositionals("definition", 1);
        KarDataDefinition definition;
        if (!KarDataDefinitionCatalog.TryFind(options.Positionals[0], out definition))
            throw new KeyNotFoundException("KAR data definition was not found: " + options.Positionals[0]);

        if (options.Json)
        {
            WriteJson(ToDataDefinitionDto(definition));
            return 0;
        }

        PrintDataDefinition(definition, "");
        return 0;
    }
}
