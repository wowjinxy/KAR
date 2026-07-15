using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectOperationPresetCatalog
    {
        internal KarProjectOperationPresetCatalog(KarProject project, IEnumerable<KarProjectOperationPreset> presets)
        {
            Project = project ?? throw new ArgumentNullException(nameof(project));
            Presets = (presets ?? throw new ArgumentNullException(nameof(presets)))
                .OrderBy(preset => preset.DomainId, StringComparer.OrdinalIgnoreCase)
                .ThenBy(preset => preset.WritesOutput)
                .ThenBy(preset => preset.DisplayName, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
            AvailablePresets = Presets
                .Where(preset => preset.HasOperations)
                .ToList()
                .AsReadOnly();
            RunnablePresets = Presets
                .Where(preset => preset.HasRunnableOperations)
                .ToList()
                .AsReadOnly();
            OutputPresets = Presets
                .Where(preset => preset.WritesOutput)
                .ToList()
                .AsReadOnly();
            ModifiedOutputPresets = Presets
                .Where(preset => preset.HasModifiedOutputOperations)
                .ToList()
                .AsReadOnly();
        }

        public KarProject Project { get; }

        public IReadOnlyList<KarProjectOperationPreset> Presets { get; }

        public IReadOnlyList<KarProjectOperationPreset> AvailablePresets { get; }

        public IReadOnlyList<KarProjectOperationPreset> RunnablePresets { get; }

        public IReadOnlyList<KarProjectOperationPreset> OutputPresets { get; }

        public IReadOnlyList<KarProjectOperationPreset> ModifiedOutputPresets { get; }

        public int PresetCount => Presets.Count;

        public int AvailablePresetCount => AvailablePresets.Count;

        public int RunnablePresetCount => RunnablePresets.Count;

        public int OutputPresetCount => OutputPresets.Count;

        public int ModifiedOutputPresetCount => ModifiedOutputPresets.Count;

        public bool HasPresets => PresetCount != 0;

        public bool HasAvailablePresets => AvailablePresetCount != 0;

        public bool HasRunnablePresets => RunnablePresetCount != 0;

        public bool HasOutputPresets => OutputPresetCount != 0;

        public bool HasModifiedOutputPresets => ModifiedOutputPresetCount != 0;
    }
}
