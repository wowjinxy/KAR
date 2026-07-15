using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectOperationPresetCatalogContract
    {
        public KarProjectContract Project { get; set; }

        public int PresetCount { get; set; }

        public int AvailablePresetCount { get; set; }

        public int RunnablePresetCount { get; set; }

        public int OutputPresetCount { get; set; }

        public int ModifiedOutputPresetCount { get; set; }

        public bool HasPresets { get; set; }

        public bool HasAvailablePresets { get; set; }

        public bool HasRunnablePresets { get; set; }

        public bool HasOutputPresets { get; set; }

        public bool HasModifiedOutputPresets { get; set; }

        public IReadOnlyList<KarProjectOperationPresetContract> Presets { get; set; }

        public static KarProjectOperationPresetCatalogContract Create(KarProjectOperationPresetCatalog catalog)
        {
            if (catalog == null)
                throw new ArgumentNullException(nameof(catalog));

            return new KarProjectOperationPresetCatalogContract
            {
                Project = catalog.Project.CreateContract(),
                PresetCount = catalog.PresetCount,
                AvailablePresetCount = catalog.AvailablePresetCount,
                RunnablePresetCount = catalog.RunnablePresetCount,
                OutputPresetCount = catalog.OutputPresetCount,
                ModifiedOutputPresetCount = catalog.ModifiedOutputPresetCount,
                HasPresets = catalog.HasPresets,
                HasAvailablePresets = catalog.HasAvailablePresets,
                HasRunnablePresets = catalog.HasRunnablePresets,
                HasOutputPresets = catalog.HasOutputPresets,
                HasModifiedOutputPresets = catalog.HasModifiedOutputPresets,
                Presets = catalog.Presets.Select(KarProjectOperationPresetContract.Create).ToList().AsReadOnly(),
            };
        }
    }

    public sealed class KarProjectOperationPresetContract
    {
        public string Id { get; set; }

        public string DomainId { get; set; }

        public string DisplayName { get; set; }

        public string Description { get; set; }

        public string ActionId { get; set; }

        public string ResourceKind { get; set; }

        public string Mode { get; set; }

        public bool IsReadOnly { get; set; }

        public bool WritesOutput { get; set; }

        public bool SupportsBatch { get; set; }

        public bool RequiresInputFile { get; set; }

        public bool RequiresFieldName { get; set; }

        public bool RequiresValue { get; set; }

        public bool? CanRun { get; set; }

        public bool? WouldWriteOutput { get; set; }

        public bool? HasModifiedOutputs { get; set; }

        public string OperationUsage { get; set; }

        public string OperationJsonUsage { get; set; }

        public string BatchUsage { get; set; }

        public string BatchJsonUsage { get; set; }

        public int OperationCount { get; set; }

        public int RunnableOperationCount { get; set; }

        public int OutputOperationCount { get; set; }

        public int ModifiedOutputOperationCount { get; set; }

        public bool HasOperations { get; set; }

        public bool HasRunnableOperations { get; set; }

        public bool HasOutputOperations { get; set; }

        public bool HasModifiedOutputOperations { get; set; }

        public static KarProjectOperationPresetContract Create(KarProjectOperationPreset preset)
        {
            if (preset == null)
                throw new ArgumentNullException(nameof(preset));

            return new KarProjectOperationPresetContract
            {
                Id = preset.Id,
                DomainId = preset.DomainId,
                DisplayName = preset.DisplayName,
                Description = preset.Description,
                ActionId = preset.ActionId,
                ResourceKind = preset.ResourceKind == null ? null : preset.ResourceKind.ToString(),
                Mode = preset.Mode,
                IsReadOnly = preset.IsReadOnly,
                WritesOutput = preset.WritesOutput,
                SupportsBatch = preset.SupportsBatch,
                RequiresInputFile = preset.RequiresInputFile,
                RequiresFieldName = preset.RequiresFieldName,
                RequiresValue = preset.RequiresValue,
                CanRun = preset.CanRun,
                WouldWriteOutput = preset.WouldWriteOutput,
                HasModifiedOutputs = preset.HasModifiedOutputs,
                OperationUsage = preset.OperationUsage,
                OperationJsonUsage = preset.OperationJsonUsage,
                BatchUsage = preset.BatchUsage,
                BatchJsonUsage = preset.BatchJsonUsage,
                OperationCount = preset.OperationCount,
                RunnableOperationCount = preset.RunnableOperationCount,
                OutputOperationCount = preset.OutputOperationCount,
                ModifiedOutputOperationCount = preset.ModifiedOutputOperationCount,
                HasOperations = preset.HasOperations,
                HasRunnableOperations = preset.HasRunnableOperations,
                HasOutputOperations = preset.HasOutputOperations,
                HasModifiedOutputOperations = preset.HasModifiedOutputOperations,
            };
        }
    }
}
