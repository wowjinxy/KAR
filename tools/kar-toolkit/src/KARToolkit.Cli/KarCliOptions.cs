using System.Globalization;

namespace KARToolkit.Cli;

internal sealed class KarCliOptions
{
    private KarCliOptions(
        List<string> positionals,
        string outputRoot,
        bool overwrite,
        bool noUnknownRoots,
        bool schema,
        bool json,
        int? maxReferenceDepth,
        int? maxReferenceEntries)
    {
        Positionals = positionals;
        OutputRoot = outputRoot;
        Overwrite = overwrite;
        NoUnknownRoots = noUnknownRoots;
        Schema = schema;
        Json = json;
        MaxReferenceDepth = maxReferenceDepth;
        MaxReferenceEntries = maxReferenceEntries;
    }

    public List<string> Positionals { get; }

    public string OutputRoot { get; }

    public bool Overwrite { get; }

    public bool NoUnknownRoots { get; }

    public bool Schema { get; }

    public bool Json { get; }

    public int? MaxReferenceDepth { get; }

    public int? MaxReferenceEntries { get; }

    public bool HasDataInspectionOptions => MaxReferenceDepth.HasValue || MaxReferenceEntries.HasValue;

    public static KarCliOptions Parse(IEnumerable<string> args)
    {
        List<string> positionals = new();
        string outputRoot = null;
        bool overwrite = false;
        bool noUnknownRoots = false;
        bool schema = false;
        bool json = false;
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
            schema,
            json,
            maxReferenceDepth,
            maxReferenceEntries);
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
