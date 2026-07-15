using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectToolkitWorkflowGroup
    {
        internal KarProjectToolkitWorkflowGroup(
            string domainId,
            string displayName,
            string description,
            string listCommand,
            string contextCommand,
            KarProjectDomainContext domain,
            IReadOnlyList<KarProjectToolkitWorkflow> workflows)
        {
            if (string.IsNullOrWhiteSpace(domainId))
                throw new ArgumentException("Toolkit workflow group domain id cannot be empty.", nameof(domainId));
            if (string.IsNullOrWhiteSpace(displayName))
                throw new ArgumentException("Toolkit workflow group display name cannot be empty.", nameof(displayName));

            DomainId = domainId;
            DisplayName = displayName;
            Description = description ?? "";
            ListCommand = listCommand;
            ContextCommand = contextCommand;
            Domain = domain;
            Workflows = workflows ?? throw new ArgumentNullException(nameof(workflows));
        }

        public string DomainId { get; }

        public string DisplayName { get; }

        public string Description { get; }

        public string ListCommand { get; }

        public string ContextCommand { get; }

        public KarProjectDomainContext Domain { get; }

        public IReadOnlyList<KarProjectToolkitWorkflow> Workflows { get; }

        public bool HasDomain => Domain != null;

        public int WorkflowCount => Workflows.Count;

        public int AvailableWorkflowCount => Workflows.Count(workflow => workflow.HasTargets);

        public int ReadOnlyWorkflowCount => Workflows.Count(workflow => workflow.IsReadOnly);

        public int WriteWorkflowCount => Workflows.Count(workflow => !workflow.IsReadOnly);

        public int OutputWorkflowCount => Workflows.Count(workflow => workflow.WritesOutput);

        public int BatchWorkflowCount => Workflows.Count(workflow => workflow.SupportsBatch);

        public int InputWorkflowCount => Workflows.Count(workflow => workflow.RequiresInputFile);

        public int ValueWorkflowCount => Workflows.Count(workflow => workflow.RequiresValue);

        public int ModifiedOutputWorkflowCount => Workflows.Count(workflow => workflow.HasModifiedOutputs);

        public int InspectionIssueWorkflowCount => Workflows.Count(workflow => workflow.HasInspectionIssues);

        public bool HasWorkflows => WorkflowCount != 0;

        public bool HasWriteWorkflows => WriteWorkflowCount != 0;

        public bool HasOutputWorkflows => OutputWorkflowCount != 0;

        public bool HasModifiedOutputWorkflows => ModifiedOutputWorkflowCount != 0;

        public bool HasInspectionIssueWorkflows => InspectionIssueWorkflowCount != 0;
    }
}
