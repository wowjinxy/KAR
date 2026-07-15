using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectOperationCatalog
    {
        internal KarProjectOperationCatalog(
            KarProject project,
            KarProjectToolkitSurface surface,
            IEnumerable<KarProjectOperation> operations)
        {
            Project = project ?? throw new ArgumentNullException(nameof(project));
            Surface = surface;
            Operations = (operations ?? throw new ArgumentNullException(nameof(operations)))
                .OrderBy(operation => operation.Kind)
                .ThenBy(operation => operation.DomainId, StringComparer.OrdinalIgnoreCase)
                .ThenBy(operation => operation.TargetDomainId, StringComparer.OrdinalIgnoreCase)
                .ThenBy(operation => operation.Command, StringComparer.OrdinalIgnoreCase)
                .ThenBy(operation => operation.ResourceAddress, StringComparer.OrdinalIgnoreCase)
                .ThenBy(operation => operation.Id, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
            WorkflowOperations = Operations
                .Where(operation => operation.IsWorkflow)
                .ToList()
                .AsReadOnly();
            ResourceActionOperations = Operations
                .Where(operation => operation.IsResourceAction)
                .ToList()
                .AsReadOnly();
            RunnableOperations = Operations
                .Where(operation => operation.CanRun == true)
                .ToList()
                .AsReadOnly();
            OutputOperations = Operations
                .Where(operation => operation.WritesOutput)
                .ToList()
                .AsReadOnly();
            ModifiedOutputOperations = Operations
                .Where(operation => operation.HasModifiedOutputs)
                .ToList()
                .AsReadOnly();
        }

        public KarProject Project { get; }

        public KarProjectToolkitSurface Surface { get; }

        public IReadOnlyList<KarProjectOperation> Operations { get; }

        public IReadOnlyList<KarProjectOperation> WorkflowOperations { get; }

        public IReadOnlyList<KarProjectOperation> ResourceActionOperations { get; }

        public IReadOnlyList<KarProjectOperation> RunnableOperations { get; }

        public IReadOnlyList<KarProjectOperation> OutputOperations { get; }

        public IReadOnlyList<KarProjectOperation> ModifiedOutputOperations { get; }

        public int OperationCount => Operations.Count;

        public int WorkflowOperationCount => WorkflowOperations.Count;

        public int ResourceActionOperationCount => ResourceActionOperations.Count;

        public int RunnableOperationCount => RunnableOperations.Count;

        public int OutputOperationCount => OutputOperations.Count;

        public int ModifiedOutputOperationCount => ModifiedOutputOperations.Count;

        public bool HasOperations => OperationCount != 0;

        public bool HasRunnableOperations => RunnableOperationCount != 0;

        public bool HasOutputOperations => OutputOperationCount != 0;

        public bool HasModifiedOutputOperations => ModifiedOutputOperationCount != 0;

        public KarProjectOperationCatalogContract CreateContract()
        {
            return KarProjectOperationCatalogContract.Create(this);
        }
    }
}
