using System.Globalization;
using KARToolkit.Core;

namespace KARToolkit.Cli;

internal sealed class KarCliOptions
{
    private KarCliOptions(
        List<string> positionals,
        string outputRoot,
        bool overwrite,
        bool noUnknownRoots,
        bool noHsdArchives,
        bool noA2DPackages,
        bool noMissingMapModels,
        bool noSchemaValidation,
        bool schema,
        bool json,
        string fileKind,
        string resourceKind,
        string domain,
        string searchText,
        string fileCategory,
        bool? fileHasOutputCopy,
        KarProjectOutputFileStatus? outputStatus,
        bool? rootKnown,
        string rootName,
        bool rootSummary,
        int? maxReferenceDepth,
        int? maxReferenceEntries)
    {
        Positionals = positionals;
        OutputRoot = outputRoot;
        Overwrite = overwrite;
        NoUnknownRoots = noUnknownRoots;
        NoHsdArchives = noHsdArchives;
        NoA2DPackages = noA2DPackages;
        NoMissingMapModels = noMissingMapModels;
        NoSchemaValidation = noSchemaValidation;
        Schema = schema;
        Json = json;
        FileKind = fileKind;
        ResourceKind = resourceKind;
        Domain = domain;
        SearchText = searchText;
        FileCategory = fileCategory;
        FileHasOutputCopy = fileHasOutputCopy;
        OutputStatus = outputStatus;
        RootKnown = rootKnown;
        RootName = rootName;
        RootSummary = rootSummary;
        MaxReferenceDepth = maxReferenceDepth;
        MaxReferenceEntries = maxReferenceEntries;
    }

    public List<string> Positionals { get; }

    public string OutputRoot { get; }

    public bool Overwrite { get; }

    public bool NoUnknownRoots { get; }

    public bool NoHsdArchives { get; }

    public bool NoA2DPackages { get; }

    public bool NoMissingMapModels { get; }

    public bool NoSchemaValidation { get; }

    public bool Schema { get; }

    public bool Json { get; }

    public string FileKind { get; }

    public string ResourceKind { get; }

    public string Domain { get; }

    public string SearchText { get; }

    public string FileCategory { get; }

    public bool? FileHasOutputCopy { get; }

    public KarProjectOutputFileStatus? OutputStatus { get; }

    public bool? RootKnown { get; }

    public string RootName { get; }

    public bool RootSummary { get; }

    public int? MaxReferenceDepth { get; }

    public int? MaxReferenceEntries { get; }

    public bool HasDataInspectionOptions => MaxReferenceDepth.HasValue || MaxReferenceEntries.HasValue;

    public static KarCliOptions Parse(IEnumerable<string> args)
    {
        List<string> positionals = new();
        string outputRoot = null;
        bool overwrite = false;
        bool noUnknownRoots = false;
        bool noHsdArchives = false;
        bool noA2DPackages = false;
        bool noMissingMapModels = false;
        bool noSchemaValidation = false;
        bool schema = false;
        bool json = false;
        string fileKind = null;
        string resourceKind = null;
        string domain = null;
        string searchText = null;
        string fileCategory = null;
        bool? fileHasOutputCopy = null;
        KarProjectOutputFileStatus? outputStatus = null;
        bool? rootKnown = null;
        string rootName = null;
        bool rootSummary = false;
        int? maxReferenceDepth = null;
        int? maxReferenceEntries = null;
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

            if (arg == "--no-hsd-archives" || arg == "--skip-hsd-archives")
            {
                noHsdArchives = true;
                continue;
            }

            if (arg == "--no-a2d-packages" || arg == "--skip-a2d-packages")
            {
                noA2DPackages = true;
                continue;
            }

            if (arg == "--no-missing-map-models")
            {
                noMissingMapModels = true;
                continue;
            }

            if (arg == "--no-schema-validation" || arg == "--no-data-definition-validation")
            {
                noSchemaValidation = true;
                continue;
            }

            if (arg == "--schema" || arg == "--data-definition")
            {
                schema = true;
                continue;
            }

            if (arg == "--json")
            {
                json = true;
                continue;
            }

            if (arg == "--kind" || arg == "--file-kind")
            {
                fileKind = ReadValue(enumerator, arg);
                continue;
            }

            if (arg == "--resource-kind" || arg == "--resource-type")
            {
                resourceKind = ReadValue(enumerator, arg);
                continue;
            }

            if (arg == "--domain" || arg == "--toolkit-domain")
            {
                domain = ReadValue(enumerator, arg);
                continue;
            }

            if (arg == "--search" || arg == "--text")
            {
                searchText = ReadValue(enumerator, arg);
                continue;
            }

            if (arg == "--category" || arg == "--file-category")
            {
                fileCategory = ReadValue(enumerator, arg);
                continue;
            }

            if (arg == "--output-copy" || arg == "--has-output-copy" || arg == "--output-only")
            {
                fileHasOutputCopy = true;
                continue;
            }

            if (arg == "--source-only" || arg == "--no-output-copy")
            {
                fileHasOutputCopy = false;
                continue;
            }

            if (arg == "--modified" || arg == "--changed" || arg == "--modified-output")
            {
                outputStatus = KarProjectOutputFileStatus.DiffersFromSource;
                continue;
            }

            if (arg == "--unchanged" || arg == "--same-as-source" || arg == "--unchanged-output")
            {
                outputStatus = KarProjectOutputFileStatus.MatchesSource;
                continue;
            }

            if (arg == "--orphan" || arg == "--orphan-output")
            {
                outputStatus = KarProjectOutputFileStatus.Orphan;
                continue;
            }

            if (arg == "--known")
            {
                rootKnown = true;
                continue;
            }

            if (arg == "--unknown")
            {
                rootKnown = false;
                continue;
            }

            if (arg == "--root-name")
            {
                rootName = ReadValue(enumerator, arg);
                continue;
            }

            if (arg == "--summary" || arg == "--summarize" || arg == "--group")
            {
                rootSummary = true;
                continue;
            }

            if (arg == "--max-reference-depth" || arg == "--reference-depth" || arg == "--ref-depth")
            {
                maxReferenceDepth = ReadNonNegativeInt(enumerator, arg);
                continue;
            }

            if (arg == "--max-reference-entries" || arg == "--reference-entries" || arg == "--ref-entries")
            {
                maxReferenceEntries = ReadNonNegativeInt(enumerator, arg);
                continue;
            }

            positionals.Add(arg);
        }

        return new KarCliOptions(
            positionals,
            outputRoot,
            overwrite,
            noUnknownRoots,
            noHsdArchives,
            noA2DPackages,
            noMissingMapModels,
            noSchemaValidation,
            schema,
            json,
            fileKind,
            resourceKind,
            domain,
            searchText,
            fileCategory,
            fileHasOutputCopy,
            outputStatus,
            rootKnown,
            rootName,
            rootSummary,
            maxReferenceDepth,
            maxReferenceEntries);
    }

    private static string ReadValue(IEnumerator<string> enumerator, string optionName)
    {
        if (!enumerator.MoveNext())
            throw new ArgumentException(optionName + " requires a value.");

        return enumerator.Current;
    }

    private static int ReadNonNegativeInt(IEnumerator<string> enumerator, string optionName)
    {
        if (!enumerator.MoveNext())
            throw new ArgumentException(optionName + " requires a non-negative integer.");

        string rawValue = enumerator.Current;
        int value;
        if (!int.TryParse(rawValue, NumberStyles.None, CultureInfo.InvariantCulture, out value) || value < 0)
            throw new ArgumentException(optionName + " requires a non-negative integer.");

        return value;
    }

    public void RequirePositionals(string command, int count)
    {
        if (Positionals.Count < count)
            throw new ArgumentException(command + " expected at least " + count + " positional argument(s).");
    }
}
