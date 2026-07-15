namespace KARToolkit.Core
{
    public sealed class KarDataDefinitionValidationIssue
    {
        internal KarDataDefinitionValidationIssue(
            KarValidationSeverity severity,
            string code,
            string message,
            string definitionId,
            string fieldName,
            string referencedDataDefinitionId)
        {
            Severity = severity;
            Code = code;
            Message = message;
            DefinitionId = definitionId;
            FieldName = fieldName;
            ReferencedDataDefinitionId = referencedDataDefinitionId;
        }

        public KarValidationSeverity Severity { get; }

        public string Code { get; }

        public string Message { get; }

        public string DefinitionId { get; }

        public string FieldName { get; }

        public string ReferencedDataDefinitionId { get; }
    }
}
