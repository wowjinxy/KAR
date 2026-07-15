using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceActionExecutionSummary
    {
        internal KarProjectResourceActionExecutionSummary(KarProjectResourceActionExecutionResult result)
        {
            if (result == null)
                throw new ArgumentNullException(nameof(result));

            Address = result.Address;
            Kind = result.Kind;
            ActionId = result.ActionId;
            Command = result.Plan.Command;
            ExecutionKind = result.Action.ExecutionKind;
            ResultKind = result.ResultKind;
            Succeeded = result.Succeeded;
            Failed = result.Failed;
            IsReadOnly = result.IsReadOnly;
            WritesOutput = result.WritesOutput;
            WouldWriteOutput = result.WouldWriteOutput;
            WroteOutput = result.WroteOutput;
            SkippedOutputWrite = result.SkippedOutputWrite;
            OutputRelativePath = result.OutputRelativePath;
            OutputPath = result.OutputPath;
            ErrorType = result.ErrorType;
            ErrorMessage = result.ErrorMessage;
        }

        public string Address { get; }

        public KarResourceKind Kind { get; }

        public string KindName => Kind.ToString();

        public string ActionId { get; }

        public string Command { get; }

        public KarProjectResourceActionExecutionKind ExecutionKind { get; }

        public string ExecutionKindName => ExecutionKind.ToString();

        public string ResultKind { get; }

        public bool Succeeded { get; }

        public bool Failed { get; }

        public bool IsReadOnly { get; }

        public bool WritesOutput { get; }

        public bool WouldWriteOutput { get; }

        public bool WroteOutput { get; }

        public bool SkippedOutputWrite { get; }

        public string OutputRelativePath { get; }

        public string OutputPath { get; }

        public string ErrorType { get; }

        public string ErrorMessage { get; }
    }
}
