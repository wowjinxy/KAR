using KARToolkit.Core;
using KARToolkit.Core.AirRide;
using System.Text.Json;
using System.Text.Json.Serialization;
using static KARToolkit.Cli.KarCliDtoFactory;
using static KARToolkit.Cli.KarCliTextWriter;

namespace KARToolkit.Cli;

internal static class Program
{
    private static readonly JsonSerializerOptions JsonOptions = new()
    {
        WriteIndented = true,
        DefaultIgnoreCondition = JsonIgnoreCondition.WhenWritingNull,
    };

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
            CliOptions options = CliOptions.Parse(args.Skip(1));

            return command switch
            {
                "project" => ShowProject(options),
                "maps" => ShowMaps(options),
                "map" => ShowMap(options),
                "archive" => ShowArchive(options),
                "a2d" => ShowA2D(options),
                "copy" => CopyFile(options),
                "copy-map" => CopyMap(options),
                "validate" => ValidateProject(options),
                "definitions" => ShowDefinitions(options),
                "definition" => ShowDefinition(options),
                _ => Fail("Unknown command: " + args[0]),
            };
        }
        catch (Exception ex)
        {
            Console.Error.WriteLine("error: " + ex.Message);
            return 1;
        }
    }

    private static int ShowProject(CliOptions options)
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

    private static int ShowMaps(CliOptions options)
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

    private static int ShowMap(CliOptions options)
    {
        options.RequirePositionals("map", 2);
        KarProject project = OpenProject(options);
        KarMapInfo map = project.InspectMap(options.Positionals[1]);

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

    private static int ShowArchive(CliOptions options)
    {
        options.RequirePositionals("archive", 2);
        KarProject project = OpenProject(options);
        KarArchiveInfo archive = project.InspectHsdArchive(options.Positionals[1]);

        if (options.Json)
        {
            WriteJson(ToArchiveDto(archive));
            return 0;
        }

        PrintArchive(archive, "");
        return 0;
    }

    private static int ShowA2D(CliOptions options)
    {
        options.RequirePositionals("a2d", 2);
        KarProject project = OpenProject(options);
        A2DPackage package = project.OpenA2DPackage(options.Positionals[1]);

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

    private static int CopyFile(CliOptions options)
    {
        options.RequirePositionals("copy", 2);
        KarProject project = OpenProject(options);
        KarProjectFile file = project.GetFile(options.Positionals[1]);
        DateTime sourceWriteTime = File.GetLastWriteTimeUtc(file.SourcePath);
        string outputPath = project.CopyToOutput(file.RelativePath, options.Overwrite);

        if (File.GetLastWriteTimeUtc(file.SourcePath) != sourceWriteTime)
            throw new InvalidOperationException("Source file timestamp changed while copying.");

        if (options.Json)
        {
            WriteJson(new
            {
                copied = ToProjectFileDto(file),
                outputPath,
            });
            return 0;
        }

        Console.WriteLine("Copied: " + file.RelativePath);
        Console.WriteLine("Source: " + file.SourcePath);
        Console.WriteLine("Output: " + outputPath);
        return 0;
    }

    private static int CopyMap(CliOptions options)
    {
        options.RequirePositionals("copy-map", 2);
        KarProject project = OpenProject(options);
        KarMapBundle map = project.GetMap(options.Positionals[1]);
        Dictionary<string, DateTime> sourceWriteTimes = map.Files.ToDictionary(file => file.RelativePath, file => File.GetLastWriteTimeUtc(file.SourcePath));
        IReadOnlyList<string> outputPaths = project.CopyMapToOutput(map, options.Overwrite);

        foreach (KarProjectFile file in map.Files)
        {
            if (File.GetLastWriteTimeUtc(file.SourcePath) != sourceWriteTimes[file.RelativePath])
                throw new InvalidOperationException("Source file timestamp changed while copying: " + file.RelativePath);
        }

        if (options.Json)
        {
            WriteJson(new
            {
                map = map.Name,
                files = map.Files.Select((file, index) => new
                {
                    file = ToProjectFileDto(file),
                    outputPath = outputPaths[index],
                }).ToList(),
            });
            return 0;
        }

        Console.WriteLine("Copied map: " + map.Name);
        for (int i = 0; i < map.Files.Count; i++)
            Console.WriteLine("  " + map.Files[i].RelativePath + " -> " + outputPaths[i]);

        return 0;
    }

    private static int ValidateProject(CliOptions options)
    {
        options.RequirePositionals("validate", 1);
        KarProject project = OpenProject(options);
        KarValidationReport report = project.Validate(new KarValidationOptions
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

    private static int ShowDefinitions(CliOptions options)
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

    private static int ShowDefinition(CliOptions options)
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

    private static KarProject OpenProject(CliOptions options)
    {
        string sourceRoot = options.Positionals[0];
        return string.IsNullOrWhiteSpace(options.OutputRoot)
            ? KarProject.Open(sourceRoot)
            : KarProject.Open(sourceRoot, options.OutputRoot);
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
        Console.WriteLine("  kar-toolkit maps <source-folder> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit map <source-folder> <map-name-or-file> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit archive <source-folder> <relative-path> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit a2d <source-folder> <relative-path> [--output <mod-folder>]");
        Console.WriteLine("  kar-toolkit copy <source-folder> <relative-path> [--output <mod-folder>] [--overwrite]");
        Console.WriteLine("  kar-toolkit copy-map <source-folder> <map-name-or-file> [--output <mod-folder>] [--overwrite]");
        Console.WriteLine("  kar-toolkit validate <source-folder> [--output <mod-folder>] [--no-unknown-roots]");
        Console.WriteLine("  kar-toolkit definitions");
        Console.WriteLine("  kar-toolkit definition <definition-id-or-accessor-type>");
        Console.WriteLine();
        Console.WriteLine("Global options:");
        Console.WriteLine("  --json");
    }

    private static int Fail(string message)
    {
        Console.Error.WriteLine("error: " + message);
        PrintHelp();
        return 1;
    }

    private static void WriteJson(object value)
    {
        Console.WriteLine(JsonSerializer.Serialize(value, JsonOptions));
    }

    private sealed class CliOptions
    {
        private CliOptions(List<string> positionals, string outputRoot, bool overwrite, bool noUnknownRoots, bool json)
        {
            Positionals = positionals;
            OutputRoot = outputRoot;
            Overwrite = overwrite;
            NoUnknownRoots = noUnknownRoots;
            Json = json;
        }

        public List<string> Positionals { get; }

        public string OutputRoot { get; }

        public bool Overwrite { get; }

        public bool NoUnknownRoots { get; }

        public bool Json { get; }

        public static CliOptions Parse(IEnumerable<string> args)
        {
            List<string> positionals = new();
            string outputRoot = null;
            bool overwrite = false;
            bool noUnknownRoots = false;
            bool json = false;
            using IEnumerator<string> enumerator = args.GetEnumerator();

            while (enumerator.MoveNext())
            {
                string arg = enumerator.Current;
                if (arg == "--output" || arg == "-o")
                {
                    if (!enumerator.MoveNext())
                        throw new ArgumentException(arg + " requires a path.");

                    outputRoot = enumerator.Current;
                    continue;
                }

                if (arg == "--overwrite")
                {
                    overwrite = true;
                    continue;
                }

                if (arg == "--no-unknown-roots")
                {
                    noUnknownRoots = true;
                    continue;
                }

                if (arg == "--json")
                {
                    json = true;
                    continue;
                }

                positionals.Add(arg);
            }

            return new CliOptions(positionals, outputRoot, overwrite, noUnknownRoots, json);
        }

        public void RequirePositionals(string command, int count)
        {
            if (Positionals.Count < count)
                throw new ArgumentException(command + " expected at least " + count + " positional argument(s).");
        }
    }
}
