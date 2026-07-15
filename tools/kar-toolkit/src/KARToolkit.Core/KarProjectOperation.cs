using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectOperation
    {
        private KarProjectOperation(
            KarProjectOperationKind kind,
            string id,
            string domainId,
            string targetDomainId,
            string displayName,
            string description,
            string command,
            string argumentHint,
            bool isReadOnly,
            bool writesOutput,
            bool supportsBatch,
            bool requiresInputFile,
            bool requiresFieldName,
            bool requiresValue,
            int targetCount,
            int outputCount,
            int modifiedOutputCount,
            int inspectionIssueCount,
            bool? canRun,
            bool? wouldWriteOutput,
            string reason,
            KarProjectToolkitWorkflow workflow,
            KarProjectResourceActionPlan resourceActionPlan)
        {
            if (string.IsNullOrWhiteSpace(id))
                throw new ArgumentException("Operation id cannot be empty.", nameof(id));
            if (string.IsNullOrWhiteSpace(displayName))
                throw new ArgumentException("Operation display name cannot be empty.", nameof(displayName));
            if (string.IsNullOrWhiteSpace(command))
                throw new ArgumentException("Operation command cannot be empty.", nameof(command));

            Kind = kind;
            Id = id;
            DomainId = domainId ?? "";
            TargetDomainId = targetDomainId ?? DomainId;
            DisplayName = displayName;
            Description = description ?? "";
            Command = command;
            ArgumentHint = argumentHint ?? "";
            IsReadOnly = isReadOnly;
            WritesOutput = writesOutput;
            SupportsBatch = supportsBatch;
            RequiresInputFile = requiresInputFile;
            RequiresFieldName = requiresFieldName;
            RequiresValue = requiresValue;
            TargetCount = targetCount;
            OutputCount = outputCount;
            ModifiedOutputCount = modifiedOutputCount;
            InspectionIssueCount = inspectionIssueCount;
            CanRun = canRun;
            WouldWriteOutput = wouldWriteOutput;
            Reason = reason ?? "";
            Workflow = workflow;
            ResourceActionPlan = resourceActionPlan;
        }

        public KarProjectOperationKind Kind { get; }

        public string Id { get; }

        public string DomainId { get; }

        public string TargetDomainId { get; }

        public string DisplayName { get; }

        public string Description { get; }

        public string Command { get; }

        public string ArgumentHint { get; }

        public string ExecutableName => "kar-toolkit";

        public string CommandLine => ExecutableName + " " + Command;

        public string Usage => string.IsNullOrWhiteSpace(ArgumentHint)
            ? CommandLine
            : CommandLine + " " + ArgumentHint;

        public string JsonUsage => Usage + " [--json]";

        public bool IsReadOnly { get; }

        public bool WritesOutput { get; }

        public bool SupportsBatch { get; }

        public bool RequiresInputFile { get; }

        public bool RequiresFieldName { get; }

        public bool RequiresValue { get; }

        public int TargetCount { get; }

        public int OutputCount { get; }

        public int ModifiedOutputCount { get; }

        public int InspectionIssueCount { get; }

        public bool? CanRun { get; }

        public bool? WouldWriteOutput { get; }

        public string Reason { get; }

        public KarProjectToolkitWorkflow Workflow { get; }

        public KarProjectResourceActionPlan ResourceActionPlan { get; }

        public KarProjectResourceInfo Resource => ResourceActionPlan == null ? null : ResourceActionPlan.Resource;

        public KarProjectResourceAction Action => ResourceActionPlan == null ? null : ResourceActionPlan.Action;

        public string ResourceAddress => Resource == null ? null : Resource.Address;

        public KarResourceKind? ResourceKind => Resource == null ? (KarResourceKind?)null : Resource.Kind;

        public string ActionId => Action == null ? null : Action.Id;

        public KarProjectResourceOutputKind? OutputKind => ResourceActionPlan == null ? null : ResourceActionPlan.OutputKind;

        public KarProjectResourceOutputStatus? OutputStatus => ResourceActionPlan == null ? null : ResourceActionPlan.OutputStatus;

        public KarProjectResourceByteOutputStatus? ByteStatus => ResourceActionPlan == null ? null : ResourceActionPlan.ByteStatus;

        public string OutputRelativePath => ResourceActionPlan == null ? null : ResourceActionPlan.OutputRelativePath;

        public string OutputPath => ResourceActionPlan == null ? null : ResourceActionPlan.OutputPath;

        public string Mode => IsReadOnly ? "read" : "write";

        public bool IsWorkflow => Kind == KarProjectOperationKind.Workflow;

        public bool IsResourceAction => Kind == KarProjectOperationKind.ResourceAction;

        public bool HasTargets => TargetCount != 0;

        public bool HasOutputs => OutputCount != 0;

        public bool HasModifiedOutputs => ModifiedOutputCount != 0;

        public bool HasInspectionIssues => InspectionIssueCount != 0;

        public bool HasReason => !string.IsNullOrWhiteSpace(Reason);

        public KarProjectOperationContract CreateContract()
        {
            return KarProjectOperationContract.Create(this);
        }

        internal static KarProjectOperation FromWorkflow(KarProjectToolkitWorkflow workflow)
        {
            if (workflow == null)
                throw new ArgumentNullException(nameof(workflow));

            return new KarProjectOperation(
                KarProjectOperationKind.Workflow,
                "workflow:" + workflow.Id,
                workflow.DomainId,
                workflow.DomainId,
                workflow.DisplayName,
                workflow.Description,
                workflow.Command,
                workflow.ArgumentHint,
                workflow.IsReadOnly,
                workflow.WritesOutput,
                workflow.SupportsBatch,
                workflow.RequiresInputFile,
                requiresFieldName: false,
                workflow.RequiresValue,
                workflow.TargetCount,
                workflow.OutputCount,
                workflow.ModifiedOutputCount,
                workflow.InspectionIssueCount,
                workflow.HasTargets,
                workflow.WritesOutput && workflow.HasTargets,
                "",
                workflow,
                null);
        }

        internal static KarProjectOperation FromResourceActionPlan(
            KarProjectResourceActionPlan plan,
            string targetDomainId)
        {
            if (plan == null)
                throw new ArgumentNullException(nameof(plan));

            int outputCount = HasPlanOutput(plan) ? 1 : 0;
            int modifiedOutputCount = HasModifiedPlanOutput(plan) ? 1 : 0;

            return new KarProjectOperation(
                KarProjectOperationKind.ResourceAction,
                "resource-action:" + plan.Address + ":" + plan.ActionId,
                "resources",
                targetDomainId,
                plan.Action.DisplayName,
                plan.Action.Description,
                plan.Command,
                CreateResourceActionArgumentHint(plan),
                plan.IsReadOnly,
                plan.WritesOutput,
                plan.SupportsBatch,
                plan.RequiresInputFile,
                plan.RequiresFieldName,
                plan.RequiresValue,
                targetCount: 1,
                outputCount,
                modifiedOutputCount,
                inspectionIssueCount: 0,
                plan.CanRun,
                plan.WouldWriteOutput,
                plan.Reason,
                null,
                plan);
        }

        private static bool HasPlanOutput(KarProjectResourceActionPlan plan)
        {
            if (plan.Output != null)
                return plan.Output.HasOutput;
            if (plan.ByteInfo != null)
                return plan.ByteInfo.HasOutput;

            return false;
        }

        private static bool HasModifiedPlanOutput(KarProjectResourceActionPlan plan)
        {
            if (plan.Output != null)
                return plan.Output.IsModified;
            if (plan.ByteInfo != null)
                return plan.ByteInfo.DiffersFromActive;

            return false;
        }

        private static string CreateResourceActionArgumentHint(KarProjectResourceActionPlan plan)
        {
            string hint = plan.Action.ArgumentHint ?? "";
            if (hint.Length == 0)
                return "<source-folder>";

            hint = hint
                .Replace("<resource-address>", plan.Address)
                .Replace("[resource-address]", plan.Address);
            return "<source-folder> " + hint;
        }
    }
}
