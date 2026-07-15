namespace KARToolkit.Core
{
    public sealed class KarProjectModWorkspaceOptions
    {
        public KarProjectOutputFileQueryOptions OutputFiles { get; set; }

        public KarProjectResourceOutputQueryOptions ResourceOutputs { get; set; }

        public KarProjectResourceByteQueryOptions ResourceByteOutputs { get; set; }

        public KarProjectA2DEntryOutputQueryOptions A2DEntryOutputs { get; set; }

        public KarProjectMapOutputQueryOptions MapOutputs { get; set; }
    }
}
