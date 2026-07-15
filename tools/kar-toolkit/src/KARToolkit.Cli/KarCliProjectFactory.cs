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
            DataInspection = CreateDataInspectionOptions(options),
        });
    }

    private static KarDataInspectionOptions CreateDataInspectionOptions(KarCliOptions options)
    {
        if (!options.HasDataInspectionOptions)
            return null;

        KarDataInspectionOptions dataInspection = new KarDataInspectionOptions();
        if (options.MaxReferenceDepth.HasValue)
            dataInspection.MaxReferenceDepth = options.MaxReferenceDepth.Value;
        if (options.MaxReferenceEntries.HasValue)
            dataInspection.MaxReferenceEntries = options.MaxReferenceEntries.Value;

        return dataInspection;
    }
}
