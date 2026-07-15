using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectOperationCatalogContract
    {
        public KarProjectContract Project { get; set; }

        public int OperationCount { get; set; }

        public int WorkflowOperationCount { get; set; }

        public int ResourceActionOperationCount { get; set; }

        public int RunnableOperationCount { get; set; }

        public int OutputOperationCount { get; set; }

        public int ModifiedOutputOperationCount { get; set; }

        public bool HasOperations { get; set; }

        public bool HasRunnableOperations { get; set; }

        public bool HasOutputOperations { get; set; }

        public bool HasModifiedOutputOperations { get; set; }

        public IReadOnlyList<KarProjectOperationContract> Operations { get; set; }

        public static KarProjectOperationCatalogContract Create(KarProjectOperationCatalog catalog)
        {
            if (catalog == null)
                throw new ArgumentNullException(nameof(catalog));

            return new KarProjectOperationCatalogContract
            {
                Project = catalog.Project.CreateContract(),
                OperationCount = catalog.OperationCount,
                WorkflowOperationCount = catalog.WorkflowOperationCount,
                ResourceActionOperationCount = catalog.ResourceActionOperationCount,
                RunnableOperationCount = catalog.RunnableOperationCount,
                OutputOperationCount = catalog.OutputOperationCount,
                ModifiedOutputOperationCount = catalog.ModifiedOutputOperationCount,
                HasOperations = catalog.HasOperations,
                HasRunnableOperations = catalog.HasRunnableOperations,
                HasOutputOperations = catalog.HasOutputOperations,
                HasModifiedOutputOperations = catalog.HasModifiedOutputOperations,
                Operations = catalog.Operations.Select(KarProjectOperationContract.Create).ToList().AsReadOnly(),
            };
        }
    }

    public sealed class KarProjectOperationContract
    {
        public string Kind { get; set; }

        public string Id { get; set; }

        public string DomainId { get; set; }

        public string TargetDomainId { get; set; }

        public string DisplayName { get; set; }

        public string Description { get; set; }

        public string Command { get; set; }

        public string ArgumentHint { get; set; }

        public string ExecutableName { get; set; }

        public string CommandLine { get; set; }

        public string Usage { get; set; }

        public string JsonUsage { get; set; }

        public string Mode { get; set; }

        public bool IsReadOnly { get; set; }

        public bool WritesOutput { get; set; }

        public bool SupportsBatch { get; set; }

        public bool RequiresInputFile { get; set; }

        public bool RequiresFieldName { get; set; }

        public bool RequiresValue { get; set; }

        public int TargetCount { get; set; }

        public int OutputCount { get; set; }

        public int ModifiedOutputCount { get; set; }

        public int InspectionIssueCount { get; set; }

        public bool? CanRun { get; set; }

        public bool? WouldWriteOutput { get; set; }

        public string Reason { get; set; }

        public string ResourceAddress { get; set; }

        public string ResourceKind { get; set; }

        public string ActionId { get; set; }

        public string OutputKind { get; set; }

        public string OutputStatus { get; set; }

        public string ByteStatus { get; set; }

        public string OutputRelativePath { get; set; }

        public string OutputPath { get; set; }

        public bool HasTargets { get; set; }

        public bool HasOutputs { get; set; }

        public bool HasModifiedOutputs { get; set; }

        public bool HasInspectionIssues { get; set; }

        public bool HasReason { get; set; }

        public KarProjectToolkitWorkflowContract Workflow { get; set; }

        public KarProjectResourceActionPlanContract ResourceActionPlan { get; set; }

        public static KarProjectOperationContract Create(KarProjectOperation operation)
        {
            if (operation == null)
                throw new ArgumentNullException(nameof(operation));

            return new KarProjectOperationContract
            {
                Kind = operation.Kind.ToString(),
                Id = operation.Id,
                DomainId = operation.DomainId,
                TargetDomainId = operation.TargetDomainId,
                DisplayName = operation.DisplayName,
                Description = operation.Description,
                Command = operation.Command,
                ArgumentHint = operation.ArgumentHint,
                ExecutableName = operation.ExecutableName,
                CommandLine = operation.CommandLine,
                Usage = operation.Usage,
                JsonUsage = operation.JsonUsage,
                Mode = operation.Mode,
                IsReadOnly = operation.IsReadOnly,
                WritesOutput = operation.WritesOutput,
                SupportsBatch = operation.SupportsBatch,
                RequiresInputFile = operation.RequiresInputFile,
                RequiresFieldName = operation.RequiresFieldName,
                RequiresValue = operation.RequiresValue,
                TargetCount = operation.TargetCount,
                OutputCount = operation.OutputCount,
                ModifiedOutputCount = operation.ModifiedOutputCount,
                InspectionIssueCount = operation.InspectionIssueCount,
                CanRun = operation.CanRun,
                WouldWriteOutput = operation.WouldWriteOutput,
                Reason = operation.Reason,
                ResourceAddress = operation.ResourceAddress,
                ResourceKind = operation.ResourceKind == null ? null : operation.ResourceKind.ToString(),
                ActionId = operation.ActionId,
                OutputKind = operation.OutputKind == null ? null : operation.OutputKind.ToString(),
                OutputStatus = operation.OutputStatus == null ? null : operation.OutputStatus.ToString(),
                ByteStatus = operation.ByteStatus == null ? null : operation.ByteStatus.ToString(),
                OutputRelativePath = operation.OutputRelativePath,
                OutputPath = operation.OutputPath,
                HasTargets = operation.HasTargets,
                HasOutputs = operation.HasOutputs,
                HasModifiedOutputs = operation.HasModifiedOutputs,
                HasInspectionIssues = operation.HasInspectionIssues,
                HasReason = operation.HasReason,
                Workflow = operation.Workflow == null ? null : operation.Workflow.CreateContract(),
                ResourceActionPlan = operation.ResourceActionPlan == null ? null : operation.ResourceActionPlan.CreateContract(),
            };
        }
    }

    public sealed class KarProjectResourceActionPlanContract
    {
        public KarProjectResourceSummaryContract Resource { get; set; }

        public KarProjectResourceActionContract Action { get; set; }

        public KarResourceReferenceContract Reference { get; set; }

        public string Address { get; set; }

        public string Kind { get; set; }

        public string ActionId { get; set; }

        public string Command { get; set; }

        public string ExecutionKind { get; set; }

        public string PlanStateKind { get; set; }

        public bool RequiresOutputInfo { get; set; }

        public bool RequiresByteInfo { get; set; }

        public string WritePolicy { get; set; }

        public bool Overwrite { get; set; }

        public bool CanRun { get; set; }

        public bool WouldWriteOutput { get; set; }

        public bool IsReadOnly { get; set; }

        public bool WritesOutput { get; set; }

        public bool RequiresInputFile { get; set; }

        public bool RequiresFieldName { get; set; }

        public bool RequiresValue { get; set; }

        public bool SupportsBatch { get; set; }

        public bool HasOutputInfo { get; set; }

        public bool HasByteInfo { get; set; }

        public string OutputKind { get; set; }

        public string OutputStatus { get; set; }

        public string ByteStatus { get; set; }

        public string OutputRelativePath { get; set; }

        public string OutputPath { get; set; }

        public string Reason { get; set; }

        public static KarProjectResourceActionPlanContract Create(KarProjectResourceActionPlan plan)
        {
            if (plan == null)
                throw new ArgumentNullException(nameof(plan));

            return new KarProjectResourceActionPlanContract
            {
                Resource = KarProjectResourceSummaryContract.Create(plan.Resource),
                Action = plan.Action.CreateContract(),
                Reference = KarResourceReferenceContract.Create(plan.Reference),
                Address = plan.Address,
                Kind = plan.Kind.ToString(),
                ActionId = plan.ActionId,
                Command = plan.Command,
                ExecutionKind = plan.Action.ExecutionKindName,
                PlanStateKind = plan.Action.PlanStateKindName,
                RequiresOutputInfo = plan.Action.RequiresOutputInfo,
                RequiresByteInfo = plan.Action.RequiresByteInfo,
                WritePolicy = plan.Action.WritePolicyName,
                Overwrite = plan.Overwrite,
                CanRun = plan.CanRun,
                WouldWriteOutput = plan.WouldWriteOutput,
                IsReadOnly = plan.IsReadOnly,
                WritesOutput = plan.WritesOutput,
                RequiresInputFile = plan.RequiresInputFile,
                RequiresFieldName = plan.RequiresFieldName,
                RequiresValue = plan.RequiresValue,
                SupportsBatch = plan.SupportsBatch,
                HasOutputInfo = plan.HasOutputInfo,
                HasByteInfo = plan.HasByteInfo,
                OutputKind = plan.OutputKind == null ? null : plan.OutputKind.ToString(),
                OutputStatus = plan.OutputStatus == null ? null : plan.OutputStatus.ToString(),
                ByteStatus = plan.ByteStatus == null ? null : plan.ByteStatus.ToString(),
                OutputRelativePath = plan.OutputRelativePath,
                OutputPath = plan.OutputPath,
                Reason = plan.Reason,
            };
        }
    }

    public sealed class KarProjectResourceSummaryContract
    {
        public KarResourceReferenceContract Resource { get; set; }

        public string Kind { get; set; }

        public string Address { get; set; }

        public string ParentAddress { get; set; }

        public string RelativePath { get; set; }

        public string HandlerId { get; set; }

        public IReadOnlyList<string> Capabilities { get; set; }

        public int ActionCount { get; set; }

        public string DisplayName { get; set; }

        public string Role { get; set; }

        public string Category { get; set; }

        public string Description { get; set; }

        public bool IsFile { get; set; }

        public bool IsHsdRoot { get; set; }

        public bool IsA2DEntry { get; set; }

        public bool CanQueryOutput { get; set; }

        public bool CanReadBytes { get; set; }

        public bool CanExportToOutput { get; set; }

        public bool CanImportFromFile { get; set; }

        public bool CanSetScalarFields { get; set; }

        public bool CanQueryFieldValues { get; set; }

        public bool CanApplyOutput { get; set; }

        public static KarProjectResourceSummaryContract Create(KarProjectResourceInfo resource)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));

            return new KarProjectResourceSummaryContract
            {
                Resource = KarResourceReferenceContract.Create(resource.Reference),
                Kind = resource.Kind.ToString(),
                Address = resource.Address,
                ParentAddress = resource.ParentAddress,
                RelativePath = resource.RelativePath,
                HandlerId = resource.HandlerId,
                Capabilities = resource.Handler.CapabilityList.Select(capability => capability.ToString()).ToList().AsReadOnly(),
                ActionCount = resource.ActionCount,
                DisplayName = resource.DisplayName,
                Role = resource.Role,
                Category = resource.Category,
                Description = resource.Description,
                IsFile = resource.IsFile,
                IsHsdRoot = resource.IsHsdRoot,
                IsA2DEntry = resource.IsA2DEntry,
                CanQueryOutput = resource.CanQueryOutput,
                CanReadBytes = resource.CanReadBytes,
                CanExportToOutput = resource.CanExportToOutput,
                CanImportFromFile = resource.CanImportFromFile,
                CanSetScalarFields = resource.CanSetScalarFields,
                CanQueryFieldValues = resource.CanQueryFieldValues,
                CanApplyOutput = resource.CanApplyOutput,
            };
        }
    }

    public sealed class KarResourceReferenceContract
    {
        public string Kind { get; set; }

        public string Address { get; set; }

        public string ParentAddress { get; set; }

        public string RelativePath { get; set; }

        public string RootName { get; set; }

        public string EntryName { get; set; }

        public static KarResourceReferenceContract Create(KarResourceReference reference)
        {
            if (reference == null)
                throw new ArgumentNullException(nameof(reference));

            return new KarResourceReferenceContract
            {
                Kind = reference.Kind.ToString(),
                Address = reference.Address,
                ParentAddress = reference.ParentAddress,
                RelativePath = reference.RelativePath,
                RootName = reference.RootName,
                EntryName = reference.EntryName,
            };
        }
    }
}
