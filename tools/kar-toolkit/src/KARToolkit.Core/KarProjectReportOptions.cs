namespace KARToolkit.Core
{
    public sealed class KarProjectReportOptions
    {
        public KarProjectFileQueryOptions Files { get; set; }

        public KarProjectOutputFileQueryOptions OutputFiles { get; set; }

        public KarProjectRootQueryOptions Roots { get; set; }

        public KarProjectFieldQueryOptions Fields { get; set; }

        public bool IncludeFieldSummaries { get; set; }
    }
}
