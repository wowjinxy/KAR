using KARToolkit.Core;

namespace KARToolkit.Cli;

internal static class KarCliProjectFactory
{
    public static KarProject OpenProject(KarCliOptions options)
    {
        return KarProject.Open(new KarProjectOptions
        {
            SourceRoot = options.Positionals[0],
            OutputRoot = options.OutputRoot,
        });
    }
}
