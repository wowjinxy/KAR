using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectDomainContextProviderRegistry
    {
        public static KarProjectDomainContextProviderRegistry Default { get; } =
            new KarProjectDomainContextProviderRegistry(CreateDefaultProviders());

        private readonly IReadOnlyList<KarProjectDomainContextProvider> _providers;
        private readonly Dictionary<string, KarProjectDomainContextProvider> _providersById;

        public KarProjectDomainContextProviderRegistry(IEnumerable<KarProjectDomainContextProvider> providers)
        {
            if (providers == null)
                throw new ArgumentNullException(nameof(providers));

            _providers = providers
                .ToList()
                .AsReadOnly();
            _providersById = new Dictionary<string, KarProjectDomainContextProvider>(StringComparer.OrdinalIgnoreCase);

            foreach (KarProjectDomainContextProvider provider in _providers)
            {
                if (provider == null)
                    throw new ArgumentException("Domain context providers cannot contain null entries.", nameof(providers));
                if (_providersById.ContainsKey(provider.Id))
                    throw new ArgumentException("Duplicate domain context provider id: " + provider.Id, nameof(providers));

                _providersById.Add(provider.Id, provider);
            }
        }

        public IReadOnlyList<KarProjectDomainContextProvider> Providers => _providers;

        public KarProjectDomainContextProvider FindProvider(string id)
        {
            KarProjectDomainContextProvider provider;
            if (!TryFindProvider(id, out provider))
                throw new KeyNotFoundException("KAR domain context provider was not found: " + id);

            return provider;
        }

        public bool TryFindProvider(string id, out KarProjectDomainContextProvider provider)
        {
            provider = null;
            return !string.IsNullOrWhiteSpace(id) && _providersById.TryGetValue(id, out provider);
        }

        public IReadOnlyList<KarProjectDomainContext> CreateContexts(
            KarProjectToolkitSnapshot snapshot,
            KarProjectResourceGraph graph)
        {
            return _providers
                .Select(provider => provider.CreateContext(snapshot, graph))
                .ToList()
                .AsReadOnly();
        }

        private static IReadOnlyList<KarProjectDomainContextProvider> CreateDefaultProviders()
        {
            return new[]
            {
                Define(
                    "files",
                    "Files",
                    "Extracted project files grouped by KAR file kind.",
                    "files",
                    "archive-contexts",
                    (snapshot, graph) => snapshot.FileCount,
                    (snapshot, graph) => graph.FileCount,
                    (snapshot, graph) => snapshot.OutputFileCount,
                    (snapshot, graph) => snapshot.ModifiedProjectOutputFileCount,
                    (snapshot, graph) => 0),
                Define(
                    "resources",
                    "Resources",
                    "Addressable file, HSD root, and A2D entry resources.",
                    "resources",
                    "resource-contexts",
                    (snapshot, graph) => graph.ResourceCount,
                    (snapshot, graph) => graph.ResourceCount,
                    (snapshot, graph) => snapshot.ResourceOutputCount + snapshot.ResourceByteOutputCount,
                    (snapshot, graph) => snapshot.ModifiedResourceOutputCount + snapshot.ModifiedResourceByteOutputCount,
                    (snapshot, graph) => 0),
                Define(
                    "maps",
                    "Maps",
                    "Map data, model, and event/script bundles.",
                    "maps",
                    "map-context",
                    (snapshot, graph) => snapshot.MapContextCount,
                    (snapshot, graph) => snapshot.MapContexts.Sum(context => context.MapResourceCount),
                    (snapshot, graph) => snapshot.MapContexts.Sum(context => context.OutputFileCount),
                    (snapshot, graph) => snapshot.MapContexts.Sum(context => context.ModifiedOutputFileCount),
                    (snapshot, graph) => snapshot.MapInspectionErrorCount),
                Define(
                    "vehicles",
                    "Vehicles",
                    "Vehicle data bundles with shared common and kind-table archives.",
                    "vehicles",
                    "vehicle-context",
                    (snapshot, graph) => snapshot.VehicleContextCount,
                    (snapshot, graph) => snapshot.VehicleContexts.Sum(context => context.ResourceCount),
                    (snapshot, graph) => snapshot.VehicleContexts.Sum(context => context.OutputFileCount),
                    (snapshot, graph) => snapshot.VehicleContexts.Sum(context => context.ModifiedOutputFileCount),
                    (snapshot, graph) => snapshot.VehicleInspectionErrorCount),
                Define(
                    "a2d-packages",
                    "A2D Packages",
                    "A2D packages, package entries, sidecar outputs, and packaged script tables.",
                    "a2d-packages",
                    "a2d-packages",
                    (snapshot, graph) => snapshot.A2DPackageContextCount,
                    (snapshot, graph) => snapshot.A2DPackageContexts.Sum(context => (context.Resource == null ? 0 : 1) + context.EntryCount),
                    (snapshot, graph) => snapshot.A2DPackageContexts.Count(context => context.HasOutput) + snapshot.A2DPackageContexts.Sum(context => context.EntryOutputCount),
                    (snapshot, graph) => snapshot.A2DPackageContexts.Count(context => context.HasModifiedOutput) + snapshot.A2DPackageContexts.Sum(context => context.ModifiedEntryOutputCount),
                    (snapshot, graph) => snapshot.A2DPackageOpenErrorCount),
                Define(
                    "script-tables",
                    "Script Tables",
                    "Loose and packaged .tm script tables resolved as toolkit resources.",
                    "script-tables",
                    "script-contexts",
                    (snapshot, graph) => snapshot.ScriptTableContextCount,
                    (snapshot, graph) => snapshot.ScriptTableContextCount,
                    (snapshot, graph) => snapshot.ScriptTableOutputCount,
                    (snapshot, graph) => snapshot.ModifiedScriptTableOutputCount,
                    (snapshot, graph) => 0),
                Define(
                    "mod-output",
                    "Mod Output",
                    "Output-folder inventory, resource exports, byte dumps, and sidecars.",
                    "outputs",
                    "mod-workspace",
                    (snapshot, graph) => snapshot.OutputFileCount + snapshot.ResourceByteOutputCount + snapshot.A2DEntryOutputCount,
                    (snapshot, graph) => 0,
                    (snapshot, graph) => snapshot.OutputFileCount + snapshot.ResourceByteOutputCount + snapshot.A2DEntryOutputCount,
                    (snapshot, graph) => snapshot.ModifiedProjectOutputFileCount + snapshot.ModifiedResourceByteOutputCount + snapshot.ModifiedA2DEntryOutputCount,
                    (snapshot, graph) => 0),
            };
        }

        private static KarProjectDomainContextProvider Define(
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
            return new KarProjectDomainContextProvider(
                id,
                displayName,
                description,
                listCommand,
                contextCommand,
                itemCount,
                resourceCount,
                outputCount,
                modifiedOutputCount,
                inspectionIssueCount);
        }
    }
}
