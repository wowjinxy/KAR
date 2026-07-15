using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectOperationExecutionSummary
    {
        internal KarProjectOperationExecutionSummary(KarProjectOperationExecutionResult result)
        {
            if (result == null)
                throw new ArgumentNullException(nameof(result));

            OperationId = result.Operation.Id;
            OperationKind = result.Operation.Kind;
            DomainId = result.Operation.DomainId;
            TargetDomainId = result.Operation.TargetDomainId;
            DisplayName = result.Operation.DisplayName;
            Command = result.Operation.Command;
            ResourceAddress = result.Operation.ResourceAddress;
            ResourceActionSummary = result.ResourceActionResult.Summary;
        }

        public string OperationId { get; }

        public KarProjectOperationKind OperationKind { get; }

        public string OperationKindName => OperationKind.ToString();

        public string DomainId { get; }

        public string TargetDomainId { get; }

        public string DisplayName { get; }

        public string Command { get; }

        public string ResourceAddress { get; }

        public KarProjectResourceActionExecutionSummary ResourceActionSummary { get; }

        public string ActionId => ResourceActionSummary.ActionId;

        public KarProjectResourceActionExecutionKind ExecutionKind => ResourceActionSummary.ExecutionKind;

        public string ExecutionKindName => ResourceActionSummary.ExecutionKindName;

        public string ResultKind => ResourceActionSummary.ResultKind;

        public bool Succeeded => ResourceActionSummary.Succeeded;

        public bool Failed => ResourceActionSummary.Failed;

        public bool IsReadOnly => ResourceActionSummary.IsReadOnly;

        public bool WritesOutput => ResourceActionSummary.WritesOutput;

        public bool WouldWriteOutput => ResourceActionSummary.WouldWriteOutput;

        public bool WroteOutput => ResourceActionSummary.WroteOutput;

        public bool SkippedOutputWrite => ResourceActionSummary.SkippedOutputWrite;

        public string OutputRelativePath => ResourceActionSummary.OutputRelativePath;

        public string OutputPath => ResourceActionSummary.OutputPath;

        public string ErrorType => ResourceActionSummary.ErrorType;

        public string ErrorMessage => ResourceActionSummary.ErrorMessage;
    }
}
