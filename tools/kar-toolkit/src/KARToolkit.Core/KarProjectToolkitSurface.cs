using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectToolkitSurface
    {
        internal KarProjectToolkitSurface(
            KarProject project,
            KarProjectToolkitSnapshot snapshot,
            IReadOnlyList<KarProjectDomainContext> domains,
            IReadOnlyList<KarProjectToolkitWorkflow> workflows)
        {
            Project = project ?? throw new ArgumentNullException(nameof(project));
            Snapshot = snapshot ?? throw new ArgumentNullException(nameof(snapshot));
            Domains = domains ?? throw new ArgumentNullException(nameof(domains));
            Workflows = workflows ?? throw new ArgumentNullException(nameof(workflows));
        }

        public KarProject Project { get; }

        public KarProjectToolkitSnapshot Snapshot { get; }

        public IReadOnlyList<KarProjectDomainContext> Domains { get; }

        public IReadOnlyList<KarProjectToolkitWorkflow> Workflows { get; }

        public string Name => Project.Name;

        public string SourceRoot => Project.SourceRoot;

        public string OutputRoot => Project.OutputRoot;

        public int DomainCount => Domains.Count;

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

        public bool HasWriteWorkflows => WriteWorkflowCount != 0;

        public bool HasOutputWorkflows => OutputWorkflowCount != 0;

        public bool HasModifiedOutputWorkflows => ModifiedOutputWorkflowCount != 0;

        public bool HasInspectionIssueWorkflows => InspectionIssueWorkflowCount != 0;
    }
}
