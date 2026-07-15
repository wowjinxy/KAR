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
            WorkflowGroups = CreateWorkflowGroups(Domains, Workflows);
        }

        public KarProject Project { get; }

        public KarProjectToolkitSnapshot Snapshot { get; }

        public IReadOnlyList<KarProjectDomainContext> Domains { get; }

        public IReadOnlyList<KarProjectToolkitWorkflow> Workflows { get; }

        public IReadOnlyList<KarProjectToolkitWorkflowGroup> WorkflowGroups { get; }

        public string Name => Project.Name;

        public string SourceRoot => Project.SourceRoot;

        public string OutputRoot => Project.OutputRoot;

        public int DomainCount => Domains.Count;

        public int WorkflowCount => Workflows.Count;

        public int WorkflowGroupCount => WorkflowGroups.Count;

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

        private static IReadOnlyList<KarProjectToolkitWorkflowGroup> CreateWorkflowGroups(
            IReadOnlyList<KarProjectDomainContext> domains,
            IReadOnlyList<KarProjectToolkitWorkflow> workflows)
        {
            Dictionary<string, KarProjectDomainContext> domainsById = domains
                .ToDictionary(domain => domain.Id, StringComparer.OrdinalIgnoreCase);
            Dictionary<string, List<KarProjectToolkitWorkflow>> workflowsByDomain = new Dictionary<string, List<KarProjectToolkitWorkflow>>(StringComparer.OrdinalIgnoreCase);

            foreach (KarProjectToolkitWorkflow workflow in workflows)
            {
                List<KarProjectToolkitWorkflow> groupWorkflows;
                if (!workflowsByDomain.TryGetValue(workflow.DomainId, out groupWorkflows))
                {
                    groupWorkflows = new List<KarProjectToolkitWorkflow>();
                    workflowsByDomain.Add(workflow.DomainId, groupWorkflows);
                }

                groupWorkflows.Add(workflow);
            }

            List<string> domainIds = new List<string>();
            if (workflowsByDomain.ContainsKey("project"))
                domainIds.Add("project");

            domainIds.AddRange(domains
                .Where(domain => workflowsByDomain.ContainsKey(domain.Id))
                .Select(domain => domain.Id));
            domainIds.AddRange(workflowsByDomain.Keys
                .Where(domainId => !domainIds.Contains(domainId, StringComparer.OrdinalIgnoreCase))
                .OrderBy(domainId => domainId, StringComparer.OrdinalIgnoreCase));

            return domainIds
                .Select(domainId => CreateWorkflowGroup(domainId, domainsById, workflowsByDomain[domainId]))
                .ToList()
                .AsReadOnly();
        }

        private static KarProjectToolkitWorkflowGroup CreateWorkflowGroup(
            string domainId,
            Dictionary<string, KarProjectDomainContext> domainsById,
            IReadOnlyList<KarProjectToolkitWorkflow> workflows)
        {
            KarProjectDomainContext domain;
            domainsById.TryGetValue(domainId, out domain);

            return new KarProjectToolkitWorkflowGroup(
                domainId,
                domain == null ? CreateDomainDisplayName(domainId) : domain.DisplayName,
                domain == null ? "Project-level toolkit commands." : domain.Description,
                domain == null ? null : domain.ListCommand,
                domain == null ? null : domain.ContextCommand,
                domain,
                workflows);
        }

        private static string CreateDomainDisplayName(string domainId)
        {
            if (string.Equals(domainId, "project", StringComparison.OrdinalIgnoreCase))
                return "Project";

            return domainId;
        }
    }
}
