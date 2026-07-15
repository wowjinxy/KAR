using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectToolkitWorkflowProviderRegistry
    {
        public static KarProjectToolkitWorkflowProviderRegistry Default { get; } =
            new KarProjectToolkitWorkflowProviderRegistry(CreateDefaultProviders());

        private readonly IReadOnlyList<KarProjectToolkitWorkflowProvider> _providers;
        private readonly Dictionary<string, KarProjectToolkitWorkflowProvider> _providersById;

        public KarProjectToolkitWorkflowProviderRegistry(IEnumerable<KarProjectToolkitWorkflowProvider> providers)
        {
            if (providers == null)
                throw new ArgumentNullException(nameof(providers));

            _providers = providers
                .ToList()
                .AsReadOnly();
            _providersById = new Dictionary<string, KarProjectToolkitWorkflowProvider>(StringComparer.OrdinalIgnoreCase);

            foreach (KarProjectToolkitWorkflowProvider provider in _providers)
            {
                if (provider == null)
                    throw new ArgumentException("Toolkit workflow providers cannot contain null entries.", nameof(providers));
                if (_providersById.ContainsKey(provider.Id))
                    throw new ArgumentException("Duplicate toolkit workflow provider id: " + provider.Id, nameof(providers));

                _providersById.Add(provider.Id, provider);
            }
        }

        public IReadOnlyList<KarProjectToolkitWorkflowProvider> Providers => _providers;

        public KarProjectToolkitWorkflowProvider FindProvider(string id)
        {
            KarProjectToolkitWorkflowProvider provider;
            if (!TryFindProvider(id, out provider))
                throw new KeyNotFoundException("KAR toolkit workflow provider was not found: " + id);

            return provider;
        }

        public bool TryFindProvider(string id, out KarProjectToolkitWorkflowProvider provider)
        {
            provider = null;
            return !string.IsNullOrWhiteSpace(id) && _providersById.TryGetValue(id, out provider);
        }

        public IReadOnlyList<KarProjectToolkitWorkflow> CreateWorkflows(
            KarProject project,
            KarProjectToolkitSnapshot snapshot,
            KarProjectResourceGraph graph,
            IReadOnlyList<KarProjectDomainContext> domains)
        {
            KarProjectToolkitWorkflowProviderContext context =
                new KarProjectToolkitWorkflowProviderContext(project, snapshot, graph, domains);
            List<KarProjectToolkitWorkflow> workflows = new List<KarProjectToolkitWorkflow>();
            HashSet<string> workflowIds = new HashSet<string>(StringComparer.OrdinalIgnoreCase);

            foreach (KarProjectToolkitWorkflowProvider provider in _providers)
            {
                foreach (KarProjectToolkitWorkflow workflow in provider.CreateWorkflows(context))
                {
                    if (workflow == null)
                        throw new InvalidOperationException("Toolkit workflow provider returned a null workflow: " + provider.Id);
                    if (!workflowIds.Add(workflow.Id))
                        throw new InvalidOperationException("Duplicate toolkit workflow id: " + workflow.Id);

                    workflows.Add(workflow);
                }
            }

            return workflows.AsReadOnly();
        }

        private static IReadOnlyList<KarProjectToolkitWorkflowProvider> CreateDefaultProviders()
        {
            return new[]
            {
                new KarProjectToolkitWorkflowProvider(
                    "built-in-workflows",
                    "Built-in Workflows",
                    "Built-in KAR project, file, resource, map, vehicle, A2D, script, and mod-output workflow launchers.",
                    KarProjectToolkitWorkflowCatalog.CreateBuiltIn),
            };
        }
    }
}
