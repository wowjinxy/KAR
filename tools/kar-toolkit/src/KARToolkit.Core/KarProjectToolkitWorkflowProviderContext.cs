using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectToolkitWorkflowProviderContext
    {
        internal KarProjectToolkitWorkflowProviderContext(
            KarProject project,
            KarProjectToolkitSnapshot snapshot,
            KarProjectResourceGraph graph,
            IReadOnlyList<KarProjectDomainContext> domains)
        {
            Project = project ?? throw new ArgumentNullException(nameof(project));
            Snapshot = snapshot ?? throw new ArgumentNullException(nameof(snapshot));
            Graph = graph ?? throw new ArgumentNullException(nameof(graph));
            Domains = domains ?? throw new ArgumentNullException(nameof(domains));
            DataFieldCount = Project.ResourceService.QueryDataFields().Count;
            EditableDataFieldCount = Project.ResourceService.QueryDataFields(new KarProjectResourceDataFieldQueryOptions
            {
                CanSetScalar = true,
            }).Count;
            ImportResourceCount = Graph.Resources.Count(resource => resource.CanImportFromFile);
            ReadableResourceCount = Graph.Resources.Count(resource => resource.CanReadBytes);
            ExportableResourceCount = Graph.Resources.Count(resource => resource.CanExportToOutput);
            A2DEntryCount = Graph.A2DEntryCount;
        }

        public KarProject Project { get; }

        public KarProjectToolkitSnapshot Snapshot { get; }

        public KarProjectResourceGraph Graph { get; }

        public IReadOnlyList<KarProjectDomainContext> Domains { get; }

        public int DataFieldCount { get; }

        public int EditableDataFieldCount { get; }

        public int ImportResourceCount { get; }

        public int ReadableResourceCount { get; }

        public int ExportableResourceCount { get; }

        public int A2DEntryCount { get; }
    }
}
