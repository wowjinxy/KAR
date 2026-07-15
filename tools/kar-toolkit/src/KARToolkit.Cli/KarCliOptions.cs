namespace KARToolkit.Cli;

internal sealed class KarCliOptions
{
    private KarCliOptions(List<string> positionals, string outputRoot, bool overwrite, bool noUnknownRoots, bool json)
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

    public static KarCliOptions Parse(IEnumerable<string> args)
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

        return new KarCliOptions(positionals, outputRoot, overwrite, noUnknownRoots, json);
    }

    public void RequirePositionals(string command, int count)
    {
        if (Positionals.Count < count)
            throw new ArgumentException(command + " expected at least " + count + " positional argument(s).");
    }
}
