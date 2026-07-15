using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectDomainContextProvider
    {
        private readonly Func<KarProjectToolkitSnapshot, KarProjectResourceGraph, int> _itemCount;
        private readonly Func<KarProjectToolkitSnapshot, KarProjectResourceGraph, int> _resourceCount;
        private readonly Func<KarProjectToolkitSnapshot, KarProjectResourceGraph, int> _outputCount;
        private readonly Func<KarProjectToolkitSnapshot, KarProjectResourceGraph, int> _modifiedOutputCount;
        private readonly Func<KarProjectToolkitSnapshot, KarProjectResourceGraph, int> _inspectionIssueCount;

        public KarProjectDomainContextProvider(
            string id,
            string displayName,
            string description,
            string listCommand,
            string contextCommand,
            Func<KarProjectToolkitSnapshot, KarProjectResourceGraph, int> itemCount,
            Func<KarProjectToolkitSnapshot, KarProjectResourceGraph, int> resourceCount,
            Func<KarProjectToolkitSnapshot, KarProjectResourceGraph, int> outputCount,
            Func<KarProjectToolkitSnapshot, KarProjectResourceGraph, int> modifiedOutputCount,
            Func<KarProjectToolkitSnapshot, KarProjectResourceGraph, int> inspectionIssueCount)
        {
            if (string.IsNullOrWhiteSpace(id))
                throw new ArgumentException("Domain context provider id cannot be empty.", nameof(id));
            if (string.IsNullOrWhiteSpace(displayName))
                throw new ArgumentException("Domain context provider display name cannot be empty.", nameof(displayName));

            Id = id;
            DisplayName = displayName;
            Description = description ?? "";
            ListCommand = listCommand ?? "";
            ContextCommand = contextCommand ?? "";
            _itemCount = itemCount ?? throw new ArgumentNullException(nameof(itemCount));
            _resourceCount = resourceCount ?? throw new ArgumentNullException(nameof(resourceCount));
            _outputCount = outputCount ?? throw new ArgumentNullException(nameof(outputCount));
            _modifiedOutputCount = modifiedOutputCount ?? throw new ArgumentNullException(nameof(modifiedOutputCount));
            _inspectionIssueCount = inspectionIssueCount ?? throw new ArgumentNullException(nameof(inspectionIssueCount));
        }

        public string Id { get; }

        public string DisplayName { get; }

        public string Description { get; }

        public string ListCommand { get; }

        public string ContextCommand { get; }

        public KarProjectDomainContext CreateContext(
            KarProjectToolkitSnapshot snapshot,
            KarProjectResourceGraph graph)
        {
            if (snapshot == null)
                throw new ArgumentNullException(nameof(snapshot));
            if (graph == null)
                throw new ArgumentNullException(nameof(graph));

            return new KarProjectDomainContext(
                Id,
                DisplayName,
                Description,
                ListCommand,
                ContextCommand,
                _itemCount(snapshot, graph),
                _resourceCount(snapshot, graph),
                _outputCount(snapshot, graph),
                _modifiedOutputCount(snapshot, graph),
                _inspectionIssueCount(snapshot, graph));
        }

        public KarProjectDomainContextProviderContract CreateContract()
        {
            return KarProjectDomainContextProviderContract.Create(this);
        }
    }
}
