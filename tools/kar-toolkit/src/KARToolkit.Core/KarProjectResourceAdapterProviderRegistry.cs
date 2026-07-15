using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceAdapterProviderRegistry
    {
        public static KarProjectResourceAdapterProviderRegistry Default { get; } =
            new KarProjectResourceAdapterProviderRegistry(CreateDefaultProviders());

        private readonly IReadOnlyList<KarProjectResourceAdapterProvider> _providers;
        private readonly Dictionary<KarResourceKind, KarProjectResourceAdapterProvider> _providersByKind;
        private readonly Dictionary<string, KarProjectResourceAdapterProvider> _providersById;

        public KarProjectResourceAdapterProviderRegistry(IEnumerable<KarProjectResourceAdapterProvider> providers)
        {
            if (providers == null)
                throw new ArgumentNullException(nameof(providers));

            _providers = providers
                .ToList()
                .AsReadOnly();
            _providersByKind = new Dictionary<KarResourceKind, KarProjectResourceAdapterProvider>();
            _providersById = new Dictionary<string, KarProjectResourceAdapterProvider>(StringComparer.OrdinalIgnoreCase);

            foreach (KarProjectResourceAdapterProvider provider in _providers)
            {
                if (provider == null)
                    throw new ArgumentException("Resource adapter providers cannot contain null entries.", nameof(providers));
                if (_providersByKind.ContainsKey(provider.Kind))
                    throw new ArgumentException("Duplicate resource adapter provider kind: " + provider.Kind, nameof(providers));
                if (_providersById.ContainsKey(provider.Id))
                    throw new ArgumentException("Duplicate resource adapter provider id: " + provider.Id, nameof(providers));

                _providersByKind.Add(provider.Kind, provider);
                _providersById.Add(provider.Id, provider);
            }
        }

        public IReadOnlyList<KarProjectResourceAdapterProvider> Providers => _providers;

        public KarProjectResourceAdapterProvider GetProvider(KarResourceKind kind)
        {
            KarProjectResourceAdapterProvider provider;
            if (!TryGetProvider(kind, out provider))
                throw new KeyNotFoundException("KAR resource adapter provider was not found: " + kind);

            return provider;
        }

        public bool TryGetProvider(KarResourceKind kind, out KarProjectResourceAdapterProvider provider)
        {
            return _providersByKind.TryGetValue(kind, out provider);
        }

        public KarProjectResourceAdapterProvider FindProvider(string idOrKind)
        {
            KarProjectResourceAdapterProvider provider;
            if (!TryFindProvider(idOrKind, out provider))
                throw new KeyNotFoundException("KAR resource adapter provider was not found: " + idOrKind);

            return provider;
        }

        public bool TryFindProvider(string idOrKind, out KarProjectResourceAdapterProvider provider)
        {
            provider = null;
            if (string.IsNullOrWhiteSpace(idOrKind))
                return false;

            if (_providersById.TryGetValue(idOrKind, out provider))
                return true;

            KarResourceKind kind;
            return Enum.TryParse(idOrKind, true, out kind) && TryGetProvider(kind, out provider);
        }

        public IReadOnlyList<KarProjectResourceAdapter> CreateAdapters(KarProject project)
        {
            if (project == null)
                throw new ArgumentNullException(nameof(project));

            return _providers
                .Select(provider => provider.CreateAdapter(project))
                .ToList()
                .AsReadOnly();
        }

        private static IReadOnlyList<KarProjectResourceAdapterProvider> CreateDefaultProviders()
        {
            return new[]
            {
                new KarProjectResourceAdapterProvider(
                    "file-resource-adapter",
                    KarResourceKind.File,
                    "File Resource Adapter",
                    "Reads, exports, imports, and reports output status for whole project files.",
                    KarProjectResourceAdapter.CreateFileAdapter),
                new KarProjectResourceAdapterProvider(
                    "hsd-root-resource-adapter",
                    KarResourceKind.HsdRoot,
                    "HSD Root Resource Adapter",
                    "Reads, exports, reports output status, and edits scalar fields for HSD archive roots.",
                    KarProjectResourceAdapter.CreateHsdRootAdapter),
                new KarProjectResourceAdapterProvider(
                    "a2d-entry-resource-adapter",
                    KarResourceKind.A2DEntry,
                    "A2D Entry Resource Adapter",
                    "Reads, exports, imports, applies sidecars, and reports output status for A2D package entries.",
                    KarProjectResourceAdapter.CreateA2DEntryAdapter),
            };
        }
    }
}
