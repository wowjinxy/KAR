using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectDomainContextContract
    {
        public string Id { get; set; }

        public string DisplayName { get; set; }

        public string Description { get; set; }

        public string ListCommand { get; set; }

        public string ContextCommand { get; set; }

        public int ItemCount { get; set; }

        public int ResourceCount { get; set; }

        public int OutputCount { get; set; }

        public int ModifiedOutputCount { get; set; }

        public int InspectionIssueCount { get; set; }

        public bool HasItems { get; set; }

        public bool HasResources { get; set; }

        public bool HasOutputs { get; set; }

        public bool HasModifiedOutputs { get; set; }

        public bool HasInspectionIssues { get; set; }

        public static KarProjectDomainContextContract Create(KarProjectDomainContext context)
        {
            if (context == null)
                throw new ArgumentNullException(nameof(context));

            return new KarProjectDomainContextContract
            {
                Id = context.Id,
                DisplayName = context.DisplayName,
                Description = context.Description,
                ListCommand = context.ListCommand,
                ContextCommand = context.ContextCommand,
                ItemCount = context.ItemCount,
                ResourceCount = context.ResourceCount,
                OutputCount = context.OutputCount,
                ModifiedOutputCount = context.ModifiedOutputCount,
                InspectionIssueCount = context.InspectionIssueCount,
                HasItems = context.HasItems,
                HasResources = context.HasResources,
                HasOutputs = context.HasOutputs,
                HasModifiedOutputs = context.HasModifiedOutputs,
                HasInspectionIssues = context.HasInspectionIssues,
            };
        }
    }

    public sealed class KarProjectToolkitWorkflowContract
    {
        public string Id { get; set; }

        public string DomainId { get; set; }

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

        public bool RequiresValue { get; set; }

        public int TargetCount { get; set; }

        public int OutputCount { get; set; }

        public int ModifiedOutputCount { get; set; }

        public int InspectionIssueCount { get; set; }

        public bool HasTargets { get; set; }

        public bool HasOutputs { get; set; }

        public bool HasModifiedOutputs { get; set; }

        public bool HasInspectionIssues { get; set; }

        public static KarProjectToolkitWorkflowContract Create(KarProjectToolkitWorkflow workflow)
        {
            if (workflow == null)
                throw new ArgumentNullException(nameof(workflow));

            return new KarProjectToolkitWorkflowContract
            {
                Id = workflow.Id,
                DomainId = workflow.DomainId,
                DisplayName = workflow.DisplayName,
                Description = workflow.Description,
                Command = workflow.Command,
                ArgumentHint = workflow.ArgumentHint,
                ExecutableName = workflow.ExecutableName,
                CommandLine = workflow.CommandLine,
                Usage = workflow.Usage,
                JsonUsage = workflow.JsonUsage,
                Mode = workflow.Mode,
                IsReadOnly = workflow.IsReadOnly,
                WritesOutput = workflow.WritesOutput,
                SupportsBatch = workflow.SupportsBatch,
                RequiresInputFile = workflow.RequiresInputFile,
                RequiresValue = workflow.RequiresValue,
                TargetCount = workflow.TargetCount,
                OutputCount = workflow.OutputCount,
                ModifiedOutputCount = workflow.ModifiedOutputCount,
                InspectionIssueCount = workflow.InspectionIssueCount,
                HasTargets = workflow.HasTargets,
                HasOutputs = workflow.HasOutputs,
                HasModifiedOutputs = workflow.HasModifiedOutputs,
                HasInspectionIssues = workflow.HasInspectionIssues,
            };
        }
    }

    public sealed class KarProjectToolkitWorkflowGroupContract
    {
        public string DomainId { get; set; }

        public string DisplayName { get; set; }

        public string Description { get; set; }

        public string ListCommand { get; set; }

        public string ContextCommand { get; set; }

        public bool HasDomain { get; set; }

        public KarProjectDomainContextContract Domain { get; set; }

        public int WorkflowCount { get; set; }

        public int AvailableWorkflowCount { get; set; }

        public int ReadOnlyWorkflowCount { get; set; }

        public int WriteWorkflowCount { get; set; }

        public int OutputWorkflowCount { get; set; }

        public int BatchWorkflowCount { get; set; }

        public int InputWorkflowCount { get; set; }

        public int ValueWorkflowCount { get; set; }

        public int ModifiedOutputWorkflowCount { get; set; }

        public int InspectionIssueWorkflowCount { get; set; }

        public bool HasWorkflows { get; set; }

        public bool HasWriteWorkflows { get; set; }

        public bool HasOutputWorkflows { get; set; }

        public bool HasModifiedOutputWorkflows { get; set; }

        public bool HasInspectionIssueWorkflows { get; set; }

        public IReadOnlyList<KarProjectToolkitWorkflowContract> Workflows { get; set; }

        public static KarProjectToolkitWorkflowGroupContract Create(KarProjectToolkitWorkflowGroup group)
        {
            if (group == null)
                throw new ArgumentNullException(nameof(group));

            return new KarProjectToolkitWorkflowGroupContract
            {
                DomainId = group.DomainId,
                DisplayName = group.DisplayName,
                Description = group.Description,
                ListCommand = group.ListCommand,
                ContextCommand = group.ContextCommand,
                HasDomain = group.HasDomain,
                Domain = group.Domain == null ? null : KarProjectDomainContextContract.Create(group.Domain),
                WorkflowCount = group.WorkflowCount,
                AvailableWorkflowCount = group.AvailableWorkflowCount,
                ReadOnlyWorkflowCount = group.ReadOnlyWorkflowCount,
                WriteWorkflowCount = group.WriteWorkflowCount,
                OutputWorkflowCount = group.OutputWorkflowCount,
                BatchWorkflowCount = group.BatchWorkflowCount,
                InputWorkflowCount = group.InputWorkflowCount,
                ValueWorkflowCount = group.ValueWorkflowCount,
                ModifiedOutputWorkflowCount = group.ModifiedOutputWorkflowCount,
                InspectionIssueWorkflowCount = group.InspectionIssueWorkflowCount,
                HasWorkflows = group.HasWorkflows,
                HasWriteWorkflows = group.HasWriteWorkflows,
                HasOutputWorkflows = group.HasOutputWorkflows,
                HasModifiedOutputWorkflows = group.HasModifiedOutputWorkflows,
                HasInspectionIssueWorkflows = group.HasInspectionIssueWorkflows,
                Workflows = group.Workflows.Select(KarProjectToolkitWorkflowContract.Create).ToList().AsReadOnly(),
            };
        }
    }
}
