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
                "file-kinds" => KarCliInspectionCommands.ShowFileKinds(options),
                "kinds" => KarCliInspectionCommands.ShowFileKinds(options),
                "resource-handlers" => KarCliInspectionCommands.ShowResourceHandlers(options),
                "resource-kinds" => KarCliInspectionCommands.ShowResourceHandlers(options),
                "report" => KarCliInspectionCommands.ShowReport(options),
                "project-report" => KarCliInspectionCommands.ShowReport(options),
                "schema-gaps" => KarCliInspectionCommands.ShowDataCoverage(options),
                "data-coverage" => KarCliInspectionCommands.ShowDataCoverage(options),
                "schema-coverage" => KarCliInspectionCommands.ShowDataCoverage(options),
                "outputs" => KarCliInspectionCommands.ShowOutputs(options),
                "output-files" => KarCliInspectionCommands.ShowOutputs(options),
                "toolkit" => KarCliInspectionCommands.ShowToolkitSnapshot(options),
                "project-toolkit" => KarCliInspectionCommands.ShowToolkitSnapshot(options),
                "toolkit-context" => KarCliInspectionCommands.ShowToolkitSnapshot(options),
                "mod-workspace" => KarCliInspectionCommands.ShowModWorkspace(options),
                "mod-status" => KarCliInspectionCommands.ShowModWorkspace(options),
                "map-outputs" => KarCliInspectionCommands.ShowMapOutputs(options),
                "map-output-status" => KarCliInspectionCommands.ShowMapOutputs(options),
                "files" => KarCliInspectionCommands.ShowFiles(options),
                "file" => KarCliInspectionCommands.ShowFile(options),
                "archives" => KarCliInspectionCommands.ShowArchives(options),
                "archive-contexts" => KarCliInspectionCommands.ShowArchiveContexts(options),
                "archive-context" => KarCliInspectionCommands.ShowArchiveContexts(options),
                "archive-status" => KarCliInspectionCommands.ShowArchiveContexts(options),
                "archive-schemas" => KarCliInspectionCommands.ShowArchiveSchemas(options),
                "file-schemas" => KarCliInspectionCommands.ShowArchiveSchemas(options),
                "roots" => KarCliInspectionCommands.ShowRoots(options),
                "schema-usage" => KarCliInspectionCommands.ShowSchemaUsage(options),
                "data-definition-usage" => KarCliInspectionCommands.ShowSchemaUsage(options),
                "fields" => KarCliInspectionCommands.ShowFields(options),
                "field-values" => KarCliInspectionCommands.ShowFields(options),
                "field-summary" => KarCliInspectionCommands.ShowFieldSummaries(options),
                "field-summaries" => KarCliInspectionCommands.ShowFieldSummaries(options),
                "maps" => KarCliInspectionCommands.ShowMaps(options),
                "map" => KarCliInspectionCommands.ShowMap(options),
                "map-scripts" => KarCliInspectionCommands.ShowMapScripts(options),
                "map-context" => KarCliInspectionCommands.ShowMapContext(options),
                "map-toolkit" => KarCliInspectionCommands.ShowMapContext(options),
                "map-script-context" => KarCliInspectionCommands.ShowMapContext(options),
                "vehicles" => KarCliInspectionCommands.ShowVehicles(options),
                "vehicle" => KarCliInspectionCommands.ShowVehicleContext(options),
                "vehicle-context" => KarCliInspectionCommands.ShowVehicleContext(options),
                "relationships" => KarCliInspectionCommands.ShowRelationships(options),
                "links" => KarCliInspectionCommands.ShowRelationships(options),
                "resource-graph" => KarCliInspectionCommands.ShowResourceGraph(options),
                "graph" => KarCliInspectionCommands.ShowResourceGraph(options),
                "resources" => KarCliInspectionCommands.ShowResources(options),
                "resource" => KarCliInspectionCommands.ShowResource(options),
                "resolve" => KarCliInspectionCommands.ShowResolvedResource(options),
                "resolve-resource" => KarCliInspectionCommands.ShowResolvedResource(options),
                "resource-resolve" => KarCliInspectionCommands.ShowResolvedResource(options),
                "resolve-detail" => KarCliInspectionCommands.ShowResolvedResourceDetail(options),
                "inspect-resource" => KarCliInspectionCommands.ShowResolvedResourceDetail(options),
                "resource-context" => KarCliInspectionCommands.ShowResolvedResourceDetail(options),
                "resource-toolkit" => KarCliInspectionCommands.ShowResolvedResourceDetail(options),
                "resource-detail" => KarCliInspectionCommands.ShowResourceDetail(options),
                "resource-info" => KarCliInspectionCommands.ShowResourceDetail(options),
                "resource-outputs" => KarCliInspectionCommands.ShowResourceOutputs(options),
                "resource-output" => KarCliInspectionCommands.ShowResourceOutput(options),
                "resource-status" => KarCliInspectionCommands.ShowResourceOutput(options),
                "resource-bytes" => KarCliInspectionCommands.ShowResourceBytes(options),
                "resource-byte-dumps" => KarCliInspectionCommands.ShowResourceBytes(options),
                "resource-byte-status" => KarCliInspectionCommands.ShowResourceBytes(options),
                "resource-fields" => KarCliInspectionCommands.ShowResourceFields(options),
                "resource-field-values" => KarCliInspectionCommands.ShowResourceFields(options),
                "a2d-packages" => KarCliInspectionCommands.ShowA2DPackageContexts(options),
                "a2d-package-context" => KarCliInspectionCommands.ShowA2DPackageContexts(options),
                "a2d-package-status" => KarCliInspectionCommands.ShowA2DPackageContexts(options),
                "a2d-entries" => KarCliInspectionCommands.ShowA2DEntries(options),
                "a2d-entry-outputs" => KarCliInspectionCommands.ShowA2DEntryOutputs(options),
                "a2d-output-status" => KarCliInspectionCommands.ShowA2DEntryOutputs(options),
                "script-tables" => KarCliInspectionCommands.ShowScriptTables(options),
                "scripts" => KarCliInspectionCommands.ShowScriptTables(options),
                "script-contexts" => KarCliInspectionCommands.ShowScriptContexts(options),
                "script-context" => KarCliInspectionCommands.ShowScriptContexts(options),
                "script-status" => KarCliInspectionCommands.ShowScriptContexts(options),
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
                "dump-resource-bytes" => KarCliCopyCommands.DumpResourceBytes(options),
                "resource-dump" => KarCliCopyCommands.DumpResourceBytes(options),
                "export-resource-bytes" => KarCliCopyCommands.DumpResourceBytes(options),
                "import-resource" => KarCliCopyCommands.ImportResource(options),
                "resource-import" => KarCliCopyCommands.ImportResource(options),
                "apply-resource-outputs" => KarCliCopyCommands.ApplyResourceOutputs(options),
                "resource-apply" => KarCliCopyCommands.ApplyResourceOutputs(options),
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
        Console.WriteLine("  kar-toolkit file-kinds");
        Console.WriteLine("  kar-toolkit resource-handlers");
        Console.WriteLine("  kar-toolkit report <source-folder> [definition-id-or-accessor-type] [field-name] [--kind <file-kind>] [--category <category>] [--root-name <name>] [--search <text>] [--summary]");
        Console.WriteLine("  kar-toolkit schema-gaps <source-folder> [relative-path] [--kind <file-kind>] [--category <category>] [--search <text>] [--json]");
        Console.WriteLine("  kar-toolkit outputs <source-folder> [--output <mod-folder>] [--kind <file-kind>] [--category <category>] [--modified|--unchanged|--orphan]");
        Console.WriteLine("  kar-toolkit toolkit <source-folder> [--output <mod-folder>] [--json]");
        Console.WriteLine("  kar-toolkit mod-workspace <source-folder> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit map-outputs <source-folder> [map-name-or-file] [--output <mod-folder>] [--modified|--unchanged]");
        Console.WriteLine("  kar-toolkit files <source-folder> [--output <mod-folder>] [--kind <file-kind>] [--category <category>] [--search <text>] [--output-copy|--source-only]");
        Console.WriteLine("  kar-toolkit file <source-folder> <relative-path> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit archives <source-folder> [--kind <file-kind>] [--category <category>] [--search <text>]");
        Console.WriteLine("  kar-toolkit archive-contexts <source-folder> [relative-path] [--output <mod-folder>] [--kind <file-kind>] [--category <category>] [--search <text>] [--modified|--unchanged|--source-only]");
        Console.WriteLine("  kar-toolkit archive-schemas <source-folder> [--kind <file-kind>] [--category <category>] [--search <text>]");
        Console.WriteLine("  kar-toolkit roots <source-folder> [--kind <file-kind>] [--category <category>] [--known|--unknown] [--root-name <name>] [--search <text>] [--summary]");
        Console.WriteLine("  kar-toolkit schema-usage <source-folder> [--kind <file-kind>] [--category <category>] [--root-name <name>] [--search <text>]");
        Console.WriteLine("  kar-toolkit fields <source-folder> [definition-id-or-accessor-type] [field-name] [--kind <file-kind>] [--category <category>] [--root-name <name>] [--search <text>]");
        Console.WriteLine("  kar-toolkit field-summary <source-folder> [definition-id-or-accessor-type] [field-name] [--kind <file-kind>] [--category <category>] [--root-name <name>] [--search <text>]");
        Console.WriteLine("  kar-toolkit maps <source-folder> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit map <source-folder> <map-name-or-file> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit map-scripts <source-folder> [map-name-or-file] [script-table-name-or-address] [--output <mod-folder>] [--search <text>]");
        Console.WriteLine("  kar-toolkit map-context <source-folder> [map-name-or-file] [script-table-name-or-address] [--output <mod-folder>] [--search <text>]");
        Console.WriteLine("  kar-toolkit vehicles <source-folder> [vehicle-name-or-file] [--output <mod-folder>] [--search <text>]");
        Console.WriteLine("  kar-toolkit vehicle <source-folder> <vehicle-name-or-file> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit relationships <source-folder> [map-name-or-file] [--output <mod-folder>] [--search <text>]");
        Console.WriteLine("  kar-toolkit resource-graph <source-folder> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit resources <source-folder> [resource-address] [--output <mod-folder>] [--resource-kind <file|root|a2d-entry>] [--kind <file-kind>] [--category <category>] [--search <text>]");
        Console.WriteLine("  kar-toolkit resource <source-folder> <resource-address> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit resolve <source-folder> <resource-address> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit resolve-detail <source-folder> <resource-address> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit resource-context <source-folder> <resource-address> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit resource-detail <source-folder> <resource-address> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit resource-outputs <source-folder> [resource-address] [--output <mod-folder>] [--resource-kind <file|root|a2d-entry>] [--search <text>] [--modified|--unchanged|--source-only]");
        Console.WriteLine("  kar-toolkit resource-output <source-folder> <resource-address> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit resource-bytes <source-folder> [resource-address] [--output <mod-folder>] [--resource-kind <file|root|a2d-entry>] [--search <text>] [--modified|--unchanged|--source-only]");
        Console.WriteLine("  kar-toolkit resource-fields <source-folder> [archive:root] [field-name] [--output <mod-folder>] [--kind <file-kind>] [--category <category>] [--search <text>]");
        Console.WriteLine("  kar-toolkit a2d-packages <source-folder> [package-relative-path] [--output <mod-folder>] [--search <text>] [--output-copy|--source-only] [--modified]");
        Console.WriteLine("  kar-toolkit a2d-entries <source-folder> [package-relative-path] [entry-name] [--output <mod-folder>] [--search <text>]");
        Console.WriteLine("  kar-toolkit a2d-entry-outputs <source-folder> [package-relative-path] [entry-name] [--output <mod-folder>] [--search <text>] [--modified|--unchanged|--source-only]");
        Console.WriteLine("  kar-toolkit script-tables <source-folder> [resource-address|package-relative-path] [table-name] [--output <mod-folder>] [--search <text>]");
        Console.WriteLine("  kar-toolkit script-contexts <source-folder> [resource-address|package-relative-path] [table-name] [--output <mod-folder>] [--search <text>] [--modified|--unchanged]");
        Console.WriteLine("  kar-toolkit archive <source-folder> <relative-path> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit a2d <source-folder> <relative-path> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit extract-a2d-entry <source-folder> <package#entry> [--output <mod-folder>] [--overwrite]");
        Console.WriteLine("  kar-toolkit replace-a2d-entry <source-folder> <package#entry> <same-size-replacement-file> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit apply-a2d-entry-outputs <source-folder> [package-relative-path] [entry-name] [--output <mod-folder>] [--search <text>]");
        Console.WriteLine("  kar-toolkit copy <source-folder> <relative-path> [--output <mod-folder>] [--overwrite]");
        Console.WriteLine("  kar-toolkit copy-map <source-folder> <map-name-or-file> [--output <mod-folder>] [--overwrite]");
        Console.WriteLine("  kar-toolkit export-resource <source-folder> <resource-address> [--output <mod-folder>] [--overwrite]");
        Console.WriteLine("  kar-toolkit dump-resource-bytes <source-folder> [resource-address] [--output <mod-folder>] [--resource-kind <file|root|a2d-entry>] [--search <text>] [--modified|--unchanged|--source-only] [--overwrite]");
        Console.WriteLine("  kar-toolkit import-resource <source-folder> <resource-address> <input-file> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit apply-resource-outputs <source-folder> [resource-address] [--output <mod-folder>] [--resource-kind <file|root|a2d-entry>] [--search <text>]");
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
        Console.WriteLine("  --search <text>");
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
