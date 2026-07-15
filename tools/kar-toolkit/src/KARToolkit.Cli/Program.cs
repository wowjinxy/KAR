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
                "project" => KarCliCommands.ShowProject(options),
                "maps" => KarCliCommands.ShowMaps(options),
                "map" => KarCliCommands.ShowMap(options),
                "archive" => KarCliCommands.ShowArchive(options),
                "a2d" => KarCliCommands.ShowA2D(options),
                "copy" => KarCliCommands.CopyFile(options),
                "copy-map" => KarCliCommands.CopyMap(options),
                "validate" => KarCliCommands.ValidateProject(options),
                "definitions" => KarCliCommands.ShowDefinitions(options),
                "definition" => KarCliCommands.ShowDefinition(options),
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
}
