using KARToolkit.Core;
using static KARToolkit.Cli.KarCliDtoFactory;
using static KARToolkit.Cli.KarCliJsonWriter;
using static KARToolkit.Cli.KarCliProjectFactory;

namespace KARToolkit.Cli;

internal static class KarCliCopyCommands
{
    public static int CopyFile(KarCliOptions options)
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

    public static int CopyMap(KarCliOptions options)
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
}
