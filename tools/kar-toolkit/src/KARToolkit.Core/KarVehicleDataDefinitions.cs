using System.Collections.Generic;
using static KARToolkit.Core.KarDataDefinitionFactory;

namespace KARToolkit.Core
{
    internal static class KarVehicleDataDefinitions
    {
        public static IReadOnlyList<KarDataDefinition> All { get; } = new[]
        {
            Define(
                "kar.vc.common",
                "Vehicle Common Data",
                "Vehicles",
                "KAR_vcDataCommon",
                "Shared City Trial vehicle tables, common parameters, resource references, sound tables, and spawn data.",
                "HSDRaw/AirRide/Vc/KAR_vcDataCommon.cs",
                Field("commonParameterTable", 0x00, "KAR_vcCommonWordArray", "Shared vehicle parameter words.", true),
                Field("resourceTable", 0x04, "HSDArrayAccessor<KAR_vcCommonResourceEntry>", "Shared vehicle resource table.", true),
                Field("physicsParameterTable", 0x08, "KAR_vcCommonWordArray", "Shared physics parameter words.", true),
                Field("machineClassSfxParams", 0x0C, "HSDArrayAccessor<KAR_vcCommonMachineClassSfxParam>", "Machine-class sound effect parameters.", true),
                Field("vehicleSoundTable", 0x10, "HSDFixedLengthPointerArrayAccessor<HSDArrayAccessor<KAR_vcCommonSoundEntry>>", "Per-machine sound id tables.", true),
                Field("x14", 0x14, "HSDFixedLengthPointerArrayAccessor<HSDAccessor>", "Unknown shared pointer table.", true),
                Field("x18", 0x18, "HSDAccessor", "Unknown shared data block.", true),
                Field("x1C", 0x1C, "KAR_vcCommonWordArray", "Unknown shared parameter words.", true),
                Field("spawnData", 0x20, "KAR_vcCommonSpawnData", "City Trial machine spawn setup.", true, "kar.vc.common.spawnData"),
                Field("x24", 0x24, "KAR_vcCommonWordArray", "Unknown shared parameter words.", true),
                Field("x28", 0x28, "KAR_vcCommonWordArray", "Unknown shared parameter words.", true),
                Field("x2C", 0x2C, "KAR_vcCommonWordArray", "Unknown shared parameter words.", true)),
            Define(
                "kar.vc.common.spawnData",
                "Vehicle Spawn Data",
                "Vehicles",
                "KAR_vcCommonSpawnData",
                "City Trial machine spawn timing, chance, weighted kind, and maximum spawn tables.",
                "HSDRaw/AirRide/Vc/KAR_vcDataCommon.cs",
                Field("spawnParamTableA", 0x00, "KAR_vcCommonWordArray", "Spawn parameter table A.", true),
                Field("spawnParamTableB", 0x04, "KAR_vcCommonWordArray", "Spawn parameter table B.", true),
                Field("spawnDesc", 0x08, "HSDArrayAccessor<KAR_vcCommonSpawnDesc>", "Progress-based machine spawn chances.", true),
                Field("weightedSpawnKindTable", 0x0C, "HSDArrayAccessor<KAR_vcCommonWeightedSpawnKind>", "Weighted machine kind entries.", true),
                Field("maxSpawnWeights", 0x10, "HSDArrayAccessor<KAR_vcCommonMaxSpawnWeights>", "Maximum additional-machine spawn weights.", true)),
        };
    }
}
