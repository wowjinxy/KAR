using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceAdapterProvider
    {
        private readonly Func<KarProject, KarProjectResourceAdapter> _createAdapter;

        public KarProjectResourceAdapterProvider(
            string id,
            KarResourceKind kind,
            string displayName,
            string description,
            Func<KarProject, KarProjectResourceAdapter> createAdapter)
        {
            if (string.IsNullOrWhiteSpace(id))
                throw new ArgumentException("Resource adapter provider id cannot be empty.", nameof(id));
            if (string.IsNullOrWhiteSpace(displayName))
                throw new ArgumentException("Resource adapter provider display name cannot be empty.", nameof(displayName));

            Id = id;
            Kind = kind;
            DisplayName = displayName;
            Description = description ?? "";
            _createAdapter = createAdapter ?? throw new ArgumentNullException(nameof(createAdapter));
        }

        public string Id { get; }

        public KarResourceKind Kind { get; }

        public string DisplayName { get; }

        public string Description { get; }

        public KarProjectResourceAdapter CreateAdapter(KarProject project)
        {
            if (project == null)
                throw new ArgumentNullException(nameof(project));

            KarProjectResourceAdapter adapter = _createAdapter(project);
            if (adapter == null)
                throw new InvalidOperationException("Resource adapter provider returned a null adapter: " + Id);
            if (adapter.Kind != Kind)
                throw new InvalidOperationException("Resource adapter provider " + Id + " returned adapter kind " + adapter.Kind + " for provider kind " + Kind + ".");

            return adapter;
        }

        public KarProjectResourceAdapterProviderContract CreateContract()
        {
            return KarProjectResourceAdapterProviderContract.Create(this);
        }
    }
}
