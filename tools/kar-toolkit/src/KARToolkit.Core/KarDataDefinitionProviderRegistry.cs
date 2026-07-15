using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarDataDefinitionProviderRegistry
    {
        public static KarDataDefinitionProviderRegistry Default { get; } =
            new KarDataDefinitionProviderRegistry(CreateDefaultProviders());

        private readonly IReadOnlyList<KarDataDefinitionProvider> _providers;
        private readonly Dictionary<string, KarDataDefinitionProvider> _providersById;

        public KarDataDefinitionProviderRegistry(IEnumerable<KarDataDefinitionProvider> providers)
        {
            if (providers == null)
                throw new ArgumentNullException(nameof(providers));

            _providers = providers
                .ToList()
                .AsReadOnly();
            _providersById = new Dictionary<string, KarDataDefinitionProvider>(StringComparer.OrdinalIgnoreCase);

            foreach (KarDataDefinitionProvider provider in _providers)
            {
                if (provider == null)
                    throw new ArgumentException("Data definition providers cannot contain null entries.", nameof(providers));
                if (_providersById.ContainsKey(provider.Id))
                    throw new ArgumentException("Duplicate data definition provider id: " + provider.Id, nameof(providers));

                _providersById.Add(provider.Id, provider);
            }
        }

        public IReadOnlyList<KarDataDefinitionProvider> Providers => _providers;

        public KarDataDefinitionProvider FindProvider(string id)
        {
            KarDataDefinitionProvider provider;
            if (!TryFindProvider(id, out provider))
                throw new KeyNotFoundException("KAR data definition provider was not found: " + id);

            return provider;
        }

        public bool TryFindProvider(string id, out KarDataDefinitionProvider provider)
        {
            provider = null;
            return !string.IsNullOrWhiteSpace(id) && _providersById.TryGetValue(id, out provider);
        }

        public IReadOnlyList<KarDataDefinition> CreateDefinitions()
        {
            List<KarDataDefinition> definitions = new List<KarDataDefinition>();
            foreach (KarDataDefinitionProvider provider in _providers)
                definitions.AddRange(provider.CreateDefinitions());

            return definitions.AsReadOnly();
        }

        public KarDataDefinitionRegistry CreateDefinitionRegistry()
        {
            return new KarDataDefinitionRegistry(CreateDefinitions());
        }

        public static KarDataDefinitionProviderRegistry FromDefinitions(
            string id,
            string displayName,
            string description,
            IEnumerable<KarDataDefinition> definitions)
        {
            if (definitions == null)
                throw new ArgumentNullException(nameof(definitions));

            IReadOnlyList<KarDataDefinition> definitionList = definitions
                .ToList()
                .AsReadOnly();

            return new KarDataDefinitionProviderRegistry(new[]
            {
                new KarDataDefinitionProvider(
                    id,
                    displayName,
                    description,
                    () => definitionList),
            });
        }

        private static IReadOnlyList<KarDataDefinitionProvider> CreateDefaultProviders()
        {
            return new[]
            {
                new KarDataDefinitionProvider(
                    "map-data-definitions",
                    "Map Data Definitions",
                    "Built-in schemas for map data, item nodes, camera routes, and related map structures.",
                    () => KarMapDataDefinitions.All),
                new KarDataDefinitionProvider(
                    "vehicle-data-definitions",
                    "Vehicle Data Definitions",
                    "Built-in schemas for vehicle data and common vehicle parameter structures.",
                    () => KarVehicleDataDefinitions.All),
                new KarDataDefinitionProvider(
                    "versus-data-definitions",
                    "Versus Data Definitions",
                    "Built-in schemas for versus-mode legendary machine data.",
                    () => KarVersusDataDefinitions.All),
            };
        }
    }
}
