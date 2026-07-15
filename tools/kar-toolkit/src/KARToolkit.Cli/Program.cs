namespace KARToolkit.Cli;

internal static class Program
{
    private static int Main(string[] args)
    {
        if (args.Length == 0 || IsHelp(args[0]))
        {
            PrintHelp();
            return 0;
        }

        try
        {
            string command = args[0].ToLowerInvariant();
            KarCliOptions options = KarCliOptions.Parse(args.Skip(1));

            return command switch
            {
                "project" => KarCliInspectionCommands.ShowProject(options),
                "report" => KarCliInspectionCommands.ShowReport(options),
                "project-report" => KarCliInspectionCommands.ShowReport(options),
                "outputs" => KarCliInspectionCommands.ShowOutputs(options),
                "output-files" => KarCliInspectionCommands.ShowOutputs(options),
                "map-outputs" => KarCliInspectionCommands.ShowMapOutputs(options),
                "map-output-status" => KarCliInspectionCommands.ShowMapOutputs(options),
                "files" => KarCliInspectionCommands.ShowFiles(options),
                "file" => KarCliInspectionCommands.ShowFile(options),
                "archives" => KarCliInspectionCommands.ShowArchives(options),
                "roots" => KarCliInspectionCommands.ShowRoots(options),
                "schema-usage" => KarCliInspectionCommands.ShowSchemaUsage(options),
                "data-definition-usage" => KarCliInspectionCommands.ShowSchemaUsage(options),
                "fields" => KarCliInspectionCommands.ShowFields(options),
                "field-values" => KarCliInspectionCommands.ShowFields(options),
                "field-summary" => KarCliInspectionCommands.ShowFieldSummaries(options),
                "field-summaries" => KarCliInspectionCommands.ShowFieldSummaries(options),
                "maps" => KarCliInspectionCommands.ShowMaps(options),
                "map" => KarCliInspectionCommands.ShowMap(options),
                "relationships" => KarCliInspectionCommands.ShowRelationships(options),
                "links" => KarCliInspectionCommands.ShowRelationships(options),
                "resources" => KarCliInspectionCommands.ShowResources(options),
                "resource" => KarCliInspectionCommands.ShowResource(options),
                "a2d-entries" => KarCliInspectionCommands.ShowA2DEntries(options),
                "a2d-entry-outputs" => KarCliInspectionCommands.ShowA2DEntryOutputs(options),
                "a2d-output-status" => KarCliInspectionCommands.ShowA2DEntryOutputs(options),
                "script-tables" => KarCliInspectionCommands.ShowScriptTables(options),
                "archive" => KarCliInspectionCommands.ShowArchive(options),
                "a2d" => KarCliInspectionCommands.ShowA2D(options),
                "extract-a2d-entry" => KarCliA2DCommands.ExtractEntry(options),
                "a2d-extract" => KarCliA2DCommands.ExtractEntry(options),
                "replace-a2d-entry" => KarCliA2DCommands.ReplaceEntry(options),
                "a2d-replace" => KarCliA2DCommands.ReplaceEntry(options),
                "apply-a2d-entry-outputs" => KarCliA2DCommands.ApplyEntryOutputs(options),
                "a2d-apply" => KarCliA2DCommands.ApplyEntryOutputs(options),
                "copy" => KarCliCopyCommands.CopyFile(options),
                "copy-map" => KarCliCopyCommands.CopyMap(options),
                "export-resource" => KarCliCopyCommands.ExportResource(options),
                "resource-export" => KarCliCopyCommands.ExportResource(options),
                "import-resource" => KarCliCopyCommands.ImportResource(options),
                "resource-import" => KarCliCopyCommands.ImportResource(options),
                "set-scalar" => KarCliEditCommands.SetScalar(options),
                "set-resource-scalar" => KarCliEditCommands.SetResourceScalar(options),
                "resource-set-scalar" => KarCliEditCommands.SetResourceScalar(options),
                "validate" => KarCliInspectionCommands.ValidateProject(options),
                "validate-schemas" => KarCliInspectionCommands.ValidateSchemas(options),
                "definitions" => KarCliInspectionCommands.ShowDefinitions(options),
                "definition" => KarCliInspectionCommands.ShowDefinition(options),
                _ => Fail("Unknown command: " + args[0]),
            };
        }
        catch (Exception ex)
        {
            Console.Error.WriteLine("error: " + ex.Message);
            return 1;
        }
    }

    private static bool IsHelp(string value)
    {
        return value == "-h" || value == "--help" || value.Equals("help", StringComparison.OrdinalIgnoreCase);
    }

    private static void PrintHelp()
    {
        Console.WriteLine("KARToolkit CLI");
        Console.WriteLine();
        Console.WriteLine("Usage:");
        Console.WriteLine("  kar-toolkit project <source-folder> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit report <source-folder> [definition-id-or-accessor-type] [field-name] [--kind <file-kind>] [--category <category>] [--root-name <name>] [--summary]");
        Console.WriteLine("  kar-toolkit outputs <source-folder> [--output <mod-folder>] [--kind <file-kind>] [--category <category>] [--modified|--unchanged|--orphan]");
        Console.WriteLine("  kar-toolkit map-outputs <source-folder> [map-name-or-file] [--output <mod-folder>] [--modified|--unchanged]");
        Console.WriteLine("  kar-toolkit files <source-folder> [--output <mod-folder>] [--kind <file-kind>] [--category <category>] [--output-copy|--source-only]");
        Console.WriteLine("  kar-toolkit file <source-folder> <relative-path> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit archives <source-folder> [--kind <file-kind>] [--category <category>]");
        Console.WriteLine("  kar-toolkit roots <source-folder> [--kind <file-kind>] [--category <category>] [--known|--unknown] [--root-name <name>] [--summary]");
        Console.WriteLine("  kar-toolkit schema-usage <source-folder> [--kind <file-kind>] [--category <category>] [--root-name <name>]");
        Console.WriteLine("  kar-toolkit fields <source-folder> [definition-id-or-accessor-type] [field-name] [--kind <file-kind>] [--category <category>] [--root-name <name>]");
        Console.WriteLine("  kar-toolkit field-summary <source-folder> [definition-id-or-accessor-type] [field-name] [--kind <file-kind>] [--category <category>] [--root-name <name>]");
        Console.WriteLine("  kar-toolkit maps <source-folder> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit map <source-folder> <map-name-or-file> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit relationships <source-folder> [map-name-or-file] [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit resources <source-folder> [resource-address] [--output <mod-folder>] [--resource-kind <file|root|a2d-entry>] [--kind <file-kind>] [--category <category>]");
        Console.WriteLine("  kar-toolkit resource <source-folder> <resource-address> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit a2d-entries <source-folder> [package-relative-path] [entry-name] [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit a2d-entry-outputs <source-folder> [package-relative-path] [entry-name] [--output <mod-folder>] [--modified|--unchanged|--source-only]");
        Console.WriteLine("  kar-toolkit script-tables <source-folder> [package-relative-path] [entry-name] [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit archive <source-folder> <relative-path> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit a2d <source-folder> <relative-path> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit extract-a2d-entry <source-folder> <package#entry> [--output <mod-folder>] [--overwrite]");
        Console.WriteLine("  kar-toolkit replace-a2d-entry <source-folder> <package#entry> <same-size-replacement-file> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit apply-a2d-entry-outputs <source-folder> [package-relative-path] [entry-name] [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit copy <source-folder> <relative-path> [--output <mod-folder>] [--overwrite]");
        Console.WriteLine("  kar-toolkit copy-map <source-folder> <map-name-or-file> [--output <mod-folder>] [--overwrite]");
        Console.WriteLine("  kar-toolkit export-resource <source-folder> <resource-address> [--output <mod-folder>] [--overwrite]");
        Console.WriteLine("  kar-toolkit import-resource <source-folder> <resource-address> <input-file> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit set-scalar <source-folder> <relative-path> <root-name> <field-name> <value> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit set-scalar <source-folder> <relative-path> <definition-id-or-accessor-type> <field-name> <value> --schema [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit set-resource-scalar <source-folder> <archive:root> <field-name> <value> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit validate <source-folder> [--output <mod-folder>] [--no-unknown-roots] [--no-hsd-archives] [--no-a2d-packages] [--no-schema-validation]");
        Console.WriteLine("  kar-toolkit validate-schemas");
        Console.WriteLine("  kar-toolkit definitions");
        Console.WriteLine("  kar-toolkit definition <definition-id-or-accessor-type>");
        Console.WriteLine();
        Console.WriteLine("Global options:");
        Console.WriteLine("  --json");
        Console.WriteLine("  --max-reference-depth <count>");
        Console.WriteLine("  --max-reference-entries <count>");
        Console.WriteLine("  --no-hsd-archives");
        Console.WriteLine("  --no-a2d-packages");
        Console.WriteLine("  --no-missing-map-models");
        Console.WriteLine("  --no-schema-validation");
        Console.WriteLine("  --kind <file-kind>");
        Console.WriteLine("  --resource-kind <file|root|a2d-entry>");
        Console.WriteLine("  --category <category>");
        Console.WriteLine("  --output-copy");
        Console.WriteLine("  --source-only");
        Console.WriteLine("  --modified");
        Console.WriteLine("  --unchanged");
        Console.WriteLine("  --orphan");
        Console.WriteLine("  --known");
        Console.WriteLine("  --unknown");
        Console.WriteLine("  --root-name <name>");
        Console.WriteLine("  --summary");
    }

    private static int Fail(string message)
    {
        Console.Error.WriteLine("error: " + message);
        PrintHelp();
        return 1;
    }
}
