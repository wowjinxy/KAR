using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectToolkitWorkflowProvider
    {
        private readonly Func<KarProjectToolkitWorkflowProviderContext, IEnumerable<KarProjectToolkitWorkflow>> _createWorkflows;

        public KarProjectToolkitWorkflowProvider(
            string id,
            string displayName,
            string description,
            Func<KarProjectToolkitWorkflowProviderContext, IEnumerable<KarProjectToolkitWorkflow>> createWorkflows)
        {
            if (string.IsNullOrWhiteSpace(id))
                throw new ArgumentException("Toolkit workflow provider id cannot be empty.", nameof(id));
            if (string.IsNullOrWhiteSpace(displayName))
                throw new ArgumentException("Toolkit workflow provider display name cannot be empty.", nameof(displayName));

            Id = id;
            DisplayName = displayName;
            Description = description ?? "";
            _createWorkflows = createWorkflows ?? throw new ArgumentNullException(nameof(createWorkflows));
        }

        public string Id { get; }

        public string DisplayName { get; }

        public string Description { get; }

        public IReadOnlyList<KarProjectToolkitWorkflow> CreateWorkflows(KarProjectToolkitWorkflowProviderContext context)
        {
            if (context == null)
                throw new ArgumentNullException(nameof(context));

            return _createWorkflows(context)
                .ToList()
                .AsReadOnly();
        }

        public KarProjectToolkitWorkflowProviderContract CreateContract()
        {
            return KarProjectToolkitWorkflowProviderContract.Create(this);
        }
    }
}
