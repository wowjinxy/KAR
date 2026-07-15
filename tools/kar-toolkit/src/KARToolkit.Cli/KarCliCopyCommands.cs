using KARToolkit.Core;
using static KARToolkit.Cli.KarCliDtoFactory;
using static KARToolkit.Cli.KarCliJsonWriter;
using static KARToolkit.Cli.KarCliProjectFactory;
using static KARToolkit.Cli.KarCliTextWriter;

namespace KARToolkit.Cli;

internal static class KarCliCopyCommands
{
    public static int CopyFile(KarCliOptions options)
    {
        options.RequirePositionals("copy", 2);
        KarProject project = OpenProject(options);
        KarProjectFileCopyResult result = project.FileService.CopyFileToOutput(options.Positionals[1], options.Overwrite);
        KarProjectFile file = result.File;

        if (options.Json)
        {
            WriteJson(new
            {
                copied = ToProjectFileDto(file),
                outputPath = result.OutputPath,
            });
            return 0;
        }

        Console.WriteLine("Copied: " + file.RelativePath);
        Console.WriteLine("Source: " + file.SourcePath);
        Console.WriteLine("Output: " + result.OutputPath);
        return 0;
    }

    public static int CopyMap(KarCliOptions options)
    {
        options.RequirePositionals("copy-map", 2);
        KarProject project = OpenProject(options);
        KarMapBundle map = project.MapService.Get(options.Positionals[1]);
        IReadOnlyList<KarProjectFileCopyResult> results = project.MapService.CopyFilesToOutput(map, options.Overwrite);

        if (options.Json)
        {
            WriteJson(new
            {
                map = map.Name,
                files = results.Select(result => new
                {
                    file = ToProjectFileDto(result.File),
                    outputPath = result.OutputPath,
                }).ToList(),
            });
            return 0;
        }

        Console.WriteLine("Copied map: " + map.Name);
        foreach (KarProjectFileCopyResult result in results)
            Console.WriteLine("  " + result.File.RelativePath + " -> " + result.OutputPath);

        return 0;
    }

    public static int ExportResource(KarCliOptions options)
    {
        options.RequirePositionals("export-resource", 2);
        KarProject project = OpenProject(options);
        KarProjectResourceExportResult result = project.ResourceService.ExportToOutput(options.Positionals[1], options.Overwrite);

        if (options.Json)
        {
            WriteJson(ToProjectResourceExportResultDto(result));
            return 0;
        }

        PrintProjectResourceExportResult(result);
        return 0;
    }
}
