using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectModWorkspace
    {
        internal KarProjectModWorkspace(
            KarProject project,
            KarProjectOutputInventory outputInventory,
            IEnumerable<KarProjectResourceOutputInfo> resourceOutputs,
            IEnumerable<KarProjectResourceByteInfo> resourceByteOutputs,
            IEnumerable<KarProjectA2DEntryOutputInfo> a2dEntryOutputs,
            IEnumerable<KarProjectMapOutputInfo> mapOutputs)
        {
            Project = project ?? throw new ArgumentNullException(nameof(project));
            OutputInventory = outputInventory ?? throw new ArgumentNullException(nameof(outputInventory));
            ResourceOutputs = (resourceOutputs ?? throw new ArgumentNullException(nameof(resourceOutputs)))
                .OrderBy(output => output.Address, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
            ResourceByteOutputs = (resourceByteOutputs ?? throw new ArgumentNullException(nameof(resourceByteOutputs)))
                .OrderBy(output => output.Address, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
            A2DEntryOutputs = (a2dEntryOutputs ?? throw new ArgumentNullException(nameof(a2dEntryOutputs)))
                .OrderBy(output => output.EntryPath, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
            MapOutputs = (mapOutputs ?? throw new ArgumentNullException(nameof(mapOutputs)))
                .OrderBy(output => output.Name, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
            ProjectFileResourceOutputs = ResourceOutputs
                .Where(output => output.IsProjectFileOutput)
                .ToList()
                .AsReadOnly();
            OutputAssetResourceOutputs = ResourceOutputs
                .Where(output => output.IsOutputAsset)
                .ToList()
                .AsReadOnly();
            ModifiedResourceOutputs = ResourceOutputs
                .Where(output => output.IsModified)
                .ToList()
                .AsReadOnly();
            UnchangedResourceOutputs = ResourceOutputs
                .Where(output => output.IsUnchanged)
                .ToList()
                .AsReadOnly();
            ModifiedResourceByteOutputs = ResourceByteOutputs
                .Where(output => output.DiffersFromActive)
                .ToList()
                .AsReadOnly();
            MatchingResourceByteOutputs = ResourceByteOutputs
                .Where(output => output.MatchesActive)
                .ToList()
                .AsReadOnly();
            ModifiedA2DEntryOutputs = A2DEntryOutputs
                .Where(output => output.DiffersFromEntry)
                .ToList()
                .AsReadOnly();
            MatchingA2DEntryOutputs = A2DEntryOutputs
                .Where(output => output.MatchesEntry)
                .ToList()
                .AsReadOnly();
            ModifiedMapOutputs = MapOutputs
                .Where(output => output.HasModifiedOutput)
                .ToList()
                .AsReadOnly();
            CompleteMapOutputs = MapOutputs
                .Where(output => output.HasCompleteOutputSet)
                .ToList()
                .AsReadOnly();
        }

        public KarProject Project { get; }

        public KarProjectOutputInventory OutputInventory { get; }

        public IReadOnlyList<KarProjectResourceOutputInfo> ResourceOutputs { get; }

        public IReadOnlyList<KarProjectResourceOutputInfo> ProjectFileResourceOutputs { get; }

        public IReadOnlyList<KarProjectResourceOutputInfo> OutputAssetResourceOutputs { get; }

        public IReadOnlyList<KarProjectResourceOutputInfo> ModifiedResourceOutputs { get; }

        public IReadOnlyList<KarProjectResourceOutputInfo> UnchangedResourceOutputs { get; }

        public IReadOnlyList<KarProjectResourceByteInfo> ResourceByteOutputs { get; }

        public IReadOnlyList<KarProjectResourceByteInfo> ModifiedResourceByteOutputs { get; }

        public IReadOnlyList<KarProjectResourceByteInfo> MatchingResourceByteOutputs { get; }

        public IReadOnlyList<KarProjectA2DEntryOutputInfo> A2DEntryOutputs { get; }

        public IReadOnlyList<KarProjectA2DEntryOutputInfo> ModifiedA2DEntryOutputs { get; }

        public IReadOnlyList<KarProjectA2DEntryOutputInfo> MatchingA2DEntryOutputs { get; }

        public IReadOnlyList<KarProjectMapOutputInfo> MapOutputs { get; }

        public IReadOnlyList<KarProjectMapOutputInfo> ModifiedMapOutputs { get; }

        public IReadOnlyList<KarProjectMapOutputInfo> CompleteMapOutputs { get; }

        public int OutputFileCount => OutputInventory.Count;

        public int ProjectOutputFileCount => OutputInventory.ProjectFileCount;

        public int ModifiedProjectOutputFileCount => OutputInventory.ModifiedProjectFileCount;

        public int UnchangedProjectOutputFileCount => OutputInventory.UnchangedProjectFileCount;

        public int OrphanOutputFileCount => OutputInventory.OrphanFileCount;

        public int MissingSourceOutputFileCount => OutputInventory.MissingSourceFileCount;

        public int ResourceOutputCount => ResourceOutputs.Count;

        public int ProjectFileResourceOutputCount => ProjectFileResourceOutputs.Count;

        public int OutputAssetResourceOutputCount => OutputAssetResourceOutputs.Count;

        public int ModifiedResourceOutputCount => ModifiedResourceOutputs.Count;

        public int UnchangedResourceOutputCount => UnchangedResourceOutputs.Count;

        public int ResourceByteOutputCount => ResourceByteOutputs.Count;

        public int ModifiedResourceByteOutputCount => ModifiedResourceByteOutputs.Count;

        public int MatchingResourceByteOutputCount => MatchingResourceByteOutputs.Count;

        public int A2DEntryOutputCount => A2DEntryOutputs.Count;

        public int ModifiedA2DEntryOutputCount => ModifiedA2DEntryOutputs.Count;

        public int MatchingA2DEntryOutputCount => MatchingA2DEntryOutputs.Count;

        public int MapOutputCount => MapOutputs.Count;

        public int ModifiedMapOutputCount => ModifiedMapOutputs.Count;

        public int CompleteMapOutputCount => CompleteMapOutputs.Count;

        public bool HasOutputs => OutputFileCount != 0 || OutputAssetResourceOutputCount != 0 || ResourceByteOutputCount != 0;

        public bool HasModifiedOutputs =>
            ModifiedProjectOutputFileCount != 0 ||
            ModifiedResourceOutputCount != 0 ||
            ModifiedResourceByteOutputCount != 0 ||
            ModifiedA2DEntryOutputCount != 0 ||
            ModifiedMapOutputCount != 0;
    }
}
