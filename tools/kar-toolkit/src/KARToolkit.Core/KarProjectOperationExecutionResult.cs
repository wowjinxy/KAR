using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectOperationExecutionResult
    {
        internal KarProjectOperationExecutionResult(
            KarProjectOperation operation,
            KarProjectResourceActionExecutionResult resourceActionResult)
        {
            Operation = operation ?? throw new ArgumentNullException(nameof(operation));
            ResourceActionResult = resourceActionResult ?? throw new ArgumentNullException(nameof(resourceActionResult));
        }

        public KarProjectOperation Operation { get; }

        public KarProjectResourceActionExecutionResult ResourceActionResult { get; }

        public KarProjectOperationExecutionSummary Summary => new KarProjectOperationExecutionSummary(this);

        public bool Succeeded => ResourceActionResult.Succeeded;

        public bool Failed => ResourceActionResult.Failed;

        public string ResultKind => ResourceActionResult.ResultKind;

        public bool IsReadOnly => ResourceActionResult.IsReadOnly;

        public bool WritesOutput => ResourceActionResult.WritesOutput;

        public bool WouldWriteOutput => ResourceActionResult.WouldWriteOutput;

        public bool WroteOutput => ResourceActionResult.WroteOutput;

        public bool SkippedOutputWrite => ResourceActionResult.SkippedOutputWrite;

        public string OutputRelativePath => ResourceActionResult.OutputRelativePath;

        public string OutputPath => ResourceActionResult.OutputPath;

        public string ErrorType => ResourceActionResult.ErrorType;

        public string ErrorMessage => ResourceActionResult.ErrorMessage;
    }
}
