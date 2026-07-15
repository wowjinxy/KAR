using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectToolkitWorkflow
    {
        internal KarProjectToolkitWorkflow(
            string id,
            string domainId,
            string displayName,
            string description,
            string command,
            string argumentHint,
            bool isReadOnly,
            bool writesOutput,
            bool supportsBatch,
            bool requiresInputFile = false,
            bool requiresValue = false,
            int targetCount = 0,
            int outputCount = 0,
            int modifiedOutputCount = 0,
            int inspectionIssueCount = 0)
        {
            if (string.IsNullOrWhiteSpace(id))
                throw new ArgumentException("Toolkit workflow id cannot be empty.", nameof(id));
            if (string.IsNullOrWhiteSpace(displayName))
                throw new ArgumentException("Toolkit workflow display name cannot be empty.", nameof(displayName));
            if (string.IsNullOrWhiteSpace(command))
                throw new ArgumentException("Toolkit workflow command cannot be empty.", nameof(command));

            Id = id;
            DomainId = domainId ?? "";
            DisplayName = displayName;
            Description = description ?? "";
            Command = command;
            ArgumentHint = argumentHint ?? "";
            IsReadOnly = isReadOnly;
            WritesOutput = writesOutput;
            SupportsBatch = supportsBatch;
            RequiresInputFile = requiresInputFile;
            RequiresValue = requiresValue;
            TargetCount = targetCount;
            OutputCount = outputCount;
            ModifiedOutputCount = modifiedOutputCount;
            InspectionIssueCount = inspectionIssueCount;
        }

        public string Id { get; }

        public string DomainId { get; }

        public string DisplayName { get; }

        public string Description { get; }

        public string Command { get; }

        public string ArgumentHint { get; }

        public bool IsReadOnly { get; }

        public bool WritesOutput { get; }

        public bool SupportsBatch { get; }

        public bool RequiresInputFile { get; }

        public bool RequiresValue { get; }

        public int TargetCount { get; }

        public int OutputCount { get; }

        public int ModifiedOutputCount { get; }

        public int InspectionIssueCount { get; }

        public string Mode => IsReadOnly ? "read" : "write";

        public bool HasTargets => TargetCount != 0;

        public bool HasOutputs => OutputCount != 0;

        public bool HasModifiedOutputs => ModifiedOutputCount != 0;

        public bool HasInspectionIssues => InspectionIssueCount != 0;
    }
}
