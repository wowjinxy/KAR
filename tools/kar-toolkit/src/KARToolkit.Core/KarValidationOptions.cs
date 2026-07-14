namespace KARToolkit.Core
{
    public sealed class KarValidationOptions
    {
        public bool InspectHsdArchives { get; set; } = true;

        public bool InspectA2DPackages { get; set; } = true;

        public bool ReportUnknownRoots { get; set; } = true;

        public bool ReportMissingMapModels { get; set; } = true;
    }
}
