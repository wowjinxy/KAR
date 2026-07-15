using KARToolkit.Core;

namespace KARToolkit.Cli;

internal static class KarCliProjectFactory
{
    public static KarProject OpenProject(KarCliOptions options)
    {
        string sourceRoot = options.Positionals[0];
        return string.IsNullOrWhiteSpace(options.OutputRoot)
            ? KarProject.Open(sourceRoot)
            : KarProject.Open(sourceRoot, options.OutputRoot);
    }
}
