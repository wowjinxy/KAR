using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceActionExecutionOptions
    {
        public bool Overwrite { get; set; }

        public bool ContinueOnError { get; set; }

        public string InputPath { get; set; }

        public string FieldName { get; set; }

        public string Value { get; set; }

        public bool HasInputPath => !string.IsNullOrWhiteSpace(InputPath);

        public bool HasFieldName => !string.IsNullOrWhiteSpace(FieldName);

        public bool HasValue => !string.IsNullOrWhiteSpace(Value);
    }
}
