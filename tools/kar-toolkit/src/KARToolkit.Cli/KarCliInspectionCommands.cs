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
        Console.WriteLine("Files: " + project.FileService.Files.Count);
        Console.WriteLine("Maps: " + project.Maps.Count);

        foreach (IGrouping<string, KarProjectFile> group in project.FileService.Files.GroupBy(file => file.Category).OrderBy(group => group.Key))
            Console.WriteLine("  " + group.Key + ": " + group.Count());

        return 0;
    }

    public static int ShowReport(KarCliOptions options)
    {
        options.RequirePositionals("report", 1);
        KarProject project = OpenProject(options);
        KarProjectReport report = project.CreateReport(CreateReportOptions(options));

        if (options.Json)
        {
            WriteJson(ToProjectReportDto(report));
            return 0;
        }

        PrintProjectReport(report);
        return 0;
    }

    public static int ShowOutputs(KarCliOptions options)
    {
        options.RequirePositionals("outputs", 1);
        KarProject project = OpenProject(options);
        KarProjectOutputInventory inventory = project.OutputService.CreateInventory(CreateOutputQuery(options));

        if (options.Json)
        {
            WriteJson(ToProjectOutputInventoryDto(inventory));
            return 0;
        }

        Console.WriteLine("Output: " + project.OutputRoot);
        Console.WriteLine("Output files: " + inventory.Count + " project=" + inventory.ProjectFileCount + " modified=" + inventory.ModifiedProjectFileCount + " unchanged=" + inventory.UnchangedProjectFileCount + " orphan=" + inventory.OrphanFileCount);
        foreach (KarProjectOutputFileInfo file in inventory.Files)
            PrintProjectOutputFile(file);

        return 0;
    }

    public static int ShowMapOutputs(KarCliOptions options)
    {
        options.RequirePositionals("map-outputs", 1);
        KarProject project = OpenProject(options);
        List<KarProjectMapOutputInfo> mapOutputs = project.MapService.QueryOutputs(CreateMapOutputQuery(options, project))
            .OrderBy(map => map.Name)
            .ToList();

        if (options.Json)
        {
            WriteJson(mapOutputs.Select(ToProjectMapOutputDto).ToList());
            return 0;
        }

        Console.WriteLine("Output: " + project.OutputRoot);
        Console.WriteLine("Map outputs: " + mapOutputs.Count + " modified=" + mapOutputs.Count(map => map.HasModifiedOutput) + " complete=" + mapOutputs.Count(map => map.HasCompleteOutputSet));
        foreach (KarProjectMapOutputInfo mapOutput in mapOutputs)
            PrintProjectMapOutput(mapOutput);

        return 0;
    }

    public static int ShowMaps(KarCliOptions options)
    {
        options.RequirePositionals("maps", 1);
        KarProject project = OpenProject(options);

        if (options.Json)
        {
            WriteJson(project.MapService.Bundles.Select(ToMapBundleDto).ToList());
            return 0;
        }

        foreach (KarMapBundle map in project.MapService.Bundles)
        {
            string pieces = string.Join(", ", map.Files.Select(file => file.RelativePath));
            Console.WriteLine(map.Name + ": " + pieces);
        }

        return 0;
    }

    public static int ShowRelationships(KarCliOptions options)
    {
        options.RequirePositionals("relationships", 1);
        KarProject project = OpenProject(options);
        List<KarProjectRelationship> relationships = options.Positionals.Count >= 2
            ? project.RelationshipService.QueryMap(options.Positionals[1]).ToList()
            : project.RelationshipService.Query().ToList();

        if (options.Json)
        {
            WriteJson(relationships.Select(ToProjectRelationshipDto).ToList());
            return 0;
        }

        foreach (KarProjectRelationship relationship in relationships)
        {
            string map = relationship.MapName == null ? "project" : relationship.MapName;
            string package = relationship.PackageFile == null ? "" : " package=" + relationship.PackageFile.RelativePath;
            string entry = relationship.PackageEntryName == null ? "" : " entry=" + relationship.PackageEntryName;
            string size = relationship.PackageEntrySizeHex == null ? "" : " size=" + relationship.PackageEntrySizeHex;
            Console.WriteLine(map + ": " + relationship.Kind + "/" + relationship.Role + " " + relationship.RelativePath + package + entry + size);
        }

        return 0;
    }

    public static int ShowA2DEntries(KarCliOptions options)
    {
        return ShowA2DEntriesCore(options, false);
    }

    public static int ShowA2DEntryOutputs(KarCliOptions options)
    {
        options.RequirePositionals("a2d-entry-outputs", 1);
        KarProject project = OpenProject(options);
        List<KarProjectA2DEntryOutputInfo> outputs = project.A2DService.QueryEntryOutputs(CreateA2DEntryOutputQuery(options))
            .ToList();

        if (options.Json)
        {
            WriteJson(outputs.Select(ToA2DEntryOutputDto).ToList());
            return 0;
        }

        foreach (KarProjectA2DEntryOutputInfo output in outputs)
            Console.WriteLine(output.EntryPath + " [" + output.Status + "] " + output.OutputRelativePath);

        return 0;
    }

    public static int ShowScriptTables(KarCliOptions options)
    {
        return ShowA2DEntriesCore(options, true);
    }

    private static int ShowA2DEntriesCore(KarCliOptions options, bool scriptTablesOnly)
    {
        options.RequirePositionals(scriptTablesOnly ? "script-tables" : "a2d-entries", 1);
        KarProject project = OpenProject(options);
        KarProjectA2DEntryQueryOptions query = CreateA2DEntryQuery(options);
        query.IsScriptTable = scriptTablesOnly ? true : query.IsScriptTable;
        List<KarProjectA2DEntryInfo> entries = project.A2DService.QueryEntries(query)
            .ToList();

        if (options.Json)
        {
            WriteJson(entries.Select(ToProjectA2DEntryDto).ToList());
            return 0;
        }

        foreach (KarProjectA2DEntryInfo entry in entries)
            Console.WriteLine(entry.EntryPath + " [" + entry.Role + "] offset=" + entry.DataOffsetHex + " size=" + entry.SizeHex);

        return 0;
    }

    public static int ShowFiles(KarCliOptions options)
    {
        options.RequirePositionals("files", 1);
        KarProject project = OpenProject(options);
        List<KarProjectFile> files = project.FileService.Query(CreateFileQuery(options))
            .OrderBy(file => file.Category)
            .ThenBy(file => file.RelativePath)
            .ToList();

        if (options.Json)
        {
            WriteJson(files.Select(ToProjectFileDto).ToList());
            return 0;
        }

        foreach (KarProjectFile file in files)
            PrintProjectFileSummary(file);

        return 0;
    }

    public static int ShowRoots(KarCliOptions options)
    {
        options.RequirePositionals("roots", 1);
        KarProject project = OpenProject(options);

        if (options.RootSummary)
            return ShowRootSummaries(project, options);

        List<KarProjectRootInfo> roots = project.DataService.QueryRoots(CreateRootQuery(options))
            .OrderBy(root => root.File.RelativePath)
            .ThenBy(root => root.Root.Name)
            .ToList();

        if (options.Json)
        {
            WriteJson(roots.Select(ToProjectRootDto).ToList());
            return 0;
        }

        foreach (KarProjectRootInfo root in roots)
            PrintProjectRootSummary(root);

        return 0;
    }

    public static int ShowArchives(KarCliOptions options)
    {
        options.RequirePositionals("archives", 1);
        KarProject project = OpenProject(options);
        List<KarArchiveInfo> archives = project.ArchiveService.QueryHsdArchives(CreateFileQuery(options))
            .OrderBy(archive => archive.File.Category)
            .ThenBy(archive => archive.File.RelativePath)
            .ToList();

        if (options.Json)
        {
            WriteJson(archives.Select(ToArchiveInventoryDto).ToList());
            return 0;
        }

        foreach (KarArchiveInfo archive in archives)
            PrintArchiveInventory(archive);

        return 0;
    }

    private static int ShowRootSummaries(KarProject project, KarCliOptions options)
    {
        List<KarProjectRootSummary> summaries = project.DataService.QueryRootSummaries(CreateRootQuery(options))
            .OrderByDescending(summary => summary.Count)
            .ThenBy(summary => summary.RootName)
            .ToList();

        if (options.Json)
        {
            WriteJson(summaries.Select(ToProjectRootSummaryDto).ToList());
            return 0;
        }

        foreach (KarProjectRootSummary summary in summaries)
            PrintProjectRootSummaryGroup(summary);

        return 0;
    }

    public static int ShowSchemaUsage(KarCliOptions options)
    {
        options.RequirePositionals("schema-usage", 1);
        KarProject project = OpenProject(options);
        List<KarProjectDataDefinitionUsage> usages = project.DataService.QueryDataDefinitionUsage(CreateRootQuery(options))
            .OrderByDescending(usage => usage.Count)
            .ThenBy(usage => usage.DataDefinitionId)
            .ToList();

        if (options.Json)
        {
            WriteJson(usages.Select(ToDataDefinitionUsageDto).ToList());
            return 0;
        }

        foreach (KarProjectDataDefinitionUsage usage in usages)
            PrintDataDefinitionUsage(usage);

        return 0;
    }

    public static int ShowFields(KarCliOptions options)
    {
        options.RequirePositionals("fields", 1);
        if (options.RootSummary)
            return ShowFieldSummaries(options);

        KarProject project = OpenProject(options);
        List<KarProjectFieldInfo> fields = project.DataService.QueryFieldValues(CreateFieldQuery(options))
            .OrderBy(field => field.RelativePath)
            .ThenBy(field => field.RootName)
            .ThenBy(field => field.Field.Offset ?? int.MaxValue)
            .ThenBy(field => field.FieldName)
            .ToList();

        if (options.Json)
        {
            WriteJson(fields.Select(ToProjectFieldValueDto).ToList());
            return 0;
        }

        foreach (KarProjectFieldInfo field in fields)
            PrintProjectFieldValue(field);

        return 0;
    }

    public static int ShowFieldSummaries(KarCliOptions options)
    {
        options.RequirePositionals("field-summary", 1);
        KarProject project = OpenProject(options);
        List<KarProjectFieldSummary> summaries = project.DataService.QueryFieldSummaries(CreateFieldQuery(options))
            .OrderByDescending(summary => summary.Count)
            .ThenByDescending(summary => summary.DistinctValueCount)
            .ThenBy(summary => summary.DataDefinitionId)
            .ThenBy(summary => summary.Field.Offset ?? int.MaxValue)
            .ThenBy(summary => summary.FieldName)
            .ToList();

        if (options.Json)
        {
            WriteJson(summaries.Select(ToProjectFieldSummaryDto).ToList());
            return 0;
        }

        foreach (KarProjectFieldSummary summary in summaries)
            PrintProjectFieldSummary(summary);

        return 0;
    }

    private static KarProjectFileQueryOptions CreateFileQuery(KarCliOptions options)
    {
        KarProjectFileQueryOptions query = new KarProjectFileQueryOptions
        {
            Category = options.FileCategory,
            HasOutputCopy = options.FileHasOutputCopy,
        };

        if (!string.IsNullOrWhiteSpace(options.FileKind))
        {
            KarFileKind kind;
            if (!Enum.TryParse(options.FileKind, true, out kind))
                throw new ArgumentException("Unknown file kind: " + options.FileKind);

            query.Kind = kind;
        }

        return query;
    }

    private static KarProjectRootQueryOptions CreateRootQuery(KarCliOptions options)
    {
        return new KarProjectRootQueryOptions
        {
            Files = CreateFileQuery(options),
            IsKnown = options.RootKnown,
            RootName = options.RootName,
        };
    }

    private static KarProjectA2DEntryQueryOptions CreateA2DEntryQuery(KarCliOptions options)
    {
        return new KarProjectA2DEntryQueryOptions
        {
            Packages = CreateFileQuery(options),
            PackagePath = options.Positionals.Count >= 2 ? options.Positionals[1] : null,
            EntryName = options.Positionals.Count >= 3 ? options.Positionals[2] : null,
        };
    }

    private static KarProjectA2DEntryOutputQueryOptions CreateA2DEntryOutputQuery(KarCliOptions options)
    {
        return new KarProjectA2DEntryOutputQueryOptions
        {
            Entries = CreateA2DEntryQuery(options),
            Status = ToA2DEntryOutputStatus(options.OutputStatus),
            HasOutput = options.FileHasOutputCopy,
        };
    }

    private static KarProjectA2DEntryOutputStatus? ToA2DEntryOutputStatus(KarProjectOutputFileStatus? status)
    {
        if (!status.HasValue)
            return null;

        switch (status.Value)
        {
            case KarProjectOutputFileStatus.DiffersFromSource:
                return KarProjectA2DEntryOutputStatus.DiffersFromEntry;
            case KarProjectOutputFileStatus.MatchesSource:
                return KarProjectA2DEntryOutputStatus.MatchesEntry;
            default:
                return null;
        }
    }

    private static KarProjectFieldQueryOptions CreateFieldQuery(KarCliOptions options)
    {
        return new KarProjectFieldQueryOptions
        {
            Roots = CreateRootQuery(options),
            DataDefinitionIdOrAccessorTypeName = options.Positionals.Count >= 2 ? options.Positionals[1] : null,
            FieldName = options.Positionals.Count >= 3 ? options.Positionals[2] : null,
        };
    }

    private static KarProjectReportOptions CreateReportOptions(KarCliOptions options)
    {
        return new KarProjectReportOptions
        {
            Files = CreateFileQuery(options),
            OutputFiles = CreateOutputQuery(options),
            Roots = CreateRootQuery(options),
            Fields = CreateFieldQuery(options),
            IncludeFieldSummaries = options.RootSummary,
        };
    }

    private static KarProjectOutputFileQueryOptions CreateOutputQuery(KarCliOptions options)
    {
        KarProjectOutputFileQueryOptions query = new KarProjectOutputFileQueryOptions
        {
            Category = options.FileCategory,
            Status = options.OutputStatus,
        };

        if (!string.IsNullOrWhiteSpace(options.FileKind))
        {
            KarFileKind kind;
            if (!Enum.TryParse(options.FileKind, true, out kind))
                throw new ArgumentException("Unknown file kind: " + options.FileKind);

            query.Kind = kind;
        }

        return query;
    }

    private static KarProjectMapOutputQueryOptions CreateMapOutputQuery(KarCliOptions options, KarProject project)
    {
        return new KarProjectMapOutputQueryOptions
        {
            Outputs = CreateOutputQuery(options),
            MapName = options.Positionals.Count >= 2 ? project.MapService.Get(options.Positionals[1]).Name : null,
            HasOutput = true,
        };
    }

    public static int ShowFile(KarCliOptions options)
    {
        options.RequirePositionals("file", 2);
        KarProject project = OpenProject(options);
        KarProjectFile file = project.FileService.Get(options.Positionals[1]);

        if (options.Json)
        {
            WriteJson(ToProjectFileDto(file));
            return 0;
        }

        PrintProjectFile(file);
        return 0;
    }

    public static int ShowMap(KarCliOptions options)
    {
        options.RequirePositionals("map", 2);
        KarProject project = OpenProject(options);
        KarMapInfo map = project.MapService.Inspect(options.Positionals[1]);

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
        KarArchiveInfo archive = project.ArchiveService.InspectHsdArchive(options.Positionals[1]);

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
        A2DPackage package = project.ArchiveService.OpenA2DPackage(options.Positionals[1]);

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
            InspectHsdArchives = !options.NoHsdArchives,
            InspectA2DPackages = !options.NoA2DPackages,
            ReportUnknownRoots = !options.NoUnknownRoots,
            ReportMissingMapModels = !options.NoMissingMapModels,
            ValidateDataDefinitions = !options.NoSchemaValidation,
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
        if (report.HasDataDefinitionValidation)
        {
            Console.WriteLine("Schemas checked: " + report.DataDefinitionValidation.DefinitionCount);
            Console.WriteLine("Schema errors: " + report.DataDefinitionValidation.ErrorCount);
            Console.WriteLine("Schema warnings: " + report.DataDefinitionValidation.WarningCount);
            Console.WriteLine("Schema info: " + report.DataDefinitionValidation.InfoCount);
        }

        Console.WriteLine("Errors: " + report.ErrorCount);
        Console.WriteLine("Warnings: " + report.WarningCount);
        Console.WriteLine("Info: " + report.InfoCount);

        if (report.HasDataDefinitionValidation)
        {
            foreach (KarDataDefinitionValidationIssue issue in report.DataDefinitionValidation.Issues)
                PrintDataDefinitionValidationIssue(issue);
        }

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
