namespace KARToolkit.Core
{
    public sealed class KarValidationIssue
    {
        internal KarValidationIssue(
            KarValidationSeverity severity,
            string code,
            string message,
            string relativePath,
            string mapName,
            string rootName)
        {
            Severity = severity;
            Code = code;
            Message = message;
            RelativePath = relativePath;
            MapName = mapName;
            RootName = rootName;
        }

        public KarValidationSeverity Severity { get; }

        public string Code { get; }

        public string Message { get; }

        public string RelativePath { get; }

        public string MapName { get; }

        public string RootName { get; }
    }
}
