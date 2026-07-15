using KARToolkit.Core;
using static KARToolkit.Cli.KarCliDtoFactory;
using static KARToolkit.Cli.KarCliJsonWriter;
using static KARToolkit.Cli.KarCliProjectFactory;

namespace KARToolkit.Cli;

internal static class KarCliA2DCommands
{
    public static int ExtractEntry(KarCliOptions options)
    {
        options.RequirePositionals("extract-a2d-entry", 2);
        KarProject project = OpenProject(options);
        KarProjectA2DEntryExtractResult result = options.Positionals.Count >= 3
            ? project.A2DService.ExtractEntryToOutput(options.Positionals[1], options.Positionals[2], options.Overwrite)
            : project.A2DService.ExtractEntryToOutput(options.Positionals[1], options.Overwrite);

        if (options.Json)
        {
            WriteJson(ToA2DEntryExtractResultDto(result));
            return 0;
        }

        Console.WriteLine("Extracted A2D entry: " + result.Entry.EntryPath);
        Console.WriteLine("Output: " + result.OutputPath);
        Console.WriteLine("Wrote: " + result.WroteOutput);
        return 0;
    }

    public static int ReplaceEntry(KarCliOptions options)
    {
        options.RequirePositionals("replace-a2d-entry", 3);
        KarProject project = OpenProject(options);
        KarProjectA2DEntryReplaceResult result = options.Positionals.Count >= 4
            ? project.A2DService.ReplaceEntryFromFile(options.Positionals[1], options.Positionals[2], options.Positionals[3])
            : project.A2DService.ReplaceEntryFromFile(options.Positionals[1], options.Positionals[2]);

        if (options.Json)
        {
            WriteJson(ToA2DEntryReplaceResultDto(result));
            return 0;
        }

        Console.WriteLine("Replaced A2D entry: " + result.Entry.EntryPath);
        Console.WriteLine("Replacement length: " + result.ReplacementLength);
        Console.WriteLine("Output package: " + result.OutputPath);
        return 0;
    }

    public static int ApplyEntryOutputs(KarCliOptions options)
    {
        options.RequirePositionals("apply-a2d-entry-outputs", 1);
        KarProject project = OpenProject(options);
        KarProjectA2DEntryOutputQueryOptions query = new KarProjectA2DEntryOutputQueryOptions
        {
            Entries = new KarProjectA2DEntryQueryOptions
            {
                PackagePath = options.Positionals.Count >= 2 ? options.Positionals[1] : null,
                EntryName = options.Positionals.Count >= 3 ? options.Positionals[2] : null,
            },
        };
        IReadOnlyList<KarProjectA2DEntryApplyResult> results = project.A2DService.ApplyModifiedEntryOutputs(query);

        if (options.Json)
        {
            WriteJson(results.Select(ToA2DEntryApplyResultDto).ToList());
            return 0;
        }

        Console.WriteLine("Applied A2D entry outputs: " + results.Count);
        foreach (KarProjectA2DEntryApplyResult result in results)
            Console.WriteLine("  " + result.EntryPath + " -> " + result.PackageOutputPath);

        return 0;
    }
}
