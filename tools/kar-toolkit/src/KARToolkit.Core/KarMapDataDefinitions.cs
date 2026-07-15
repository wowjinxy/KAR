using System.Collections.Generic;
using static KARToolkit.Core.KarDataDefinitionFactory;

namespace KARToolkit.Core
{
    internal static class KarMapDataDefinitions
    {
        public static IReadOnlyList<KarDataDefinition> All { get; } = new[]
        {
            Define(
                "kar.stage.table",
                "Stage Table",
                "Maps",
                "KAR_stData",
                "Top-level stage table. Entries resolve map ids, music ids, spawn tables, and gameplay feature toggles.",
                "HSDRaw/AirRide/KAR_stData.cs",
                Field("stageKinds", 0x00, "HSDArrayAccessor<KAR_stKind>", "Array of stage kind records.", true, "kar.stage.kind")),
            Define(
                "kar.stage.kind",
                "Stage Kind Entry",
                "Maps",
                "KAR_stKind",
                "One stage descriptor inside Stage.dat.",
                "HSDRaw/AirRide/KAR_stData.cs",
                Field("groundId", 0x00, "s32", "Map/ground id."),
                Field("bgmId", 0x04, "s32", "Primary BGM id."),
                Field("uraBgmId", 0x08, "s32", "Alternate BGM id."),
                Field("bgmChance", 0x0C, "s32", "Chance or selector for alternate BGM."),
                Field("defaultBgmId", 0x10, "s32", "Default BGM id."),
                Field("renderCam", 0x14, "s32", "Render camera id."),
                Field("maxPlayers", 0x18, "s32", "Maximum player count."),
                Field("startId", 0x1C, "s32", "Start position table id."),
                Field("enemyId", 0x20, "s32", "Enemy table id."),
                Field("itemId", 0x24, "s32", "Item table id."),
                Field("itemAreaId", 0x28, "s32", "Item area table id."),
                Field("vehicleId", 0x2C, "s32", "Vehicle table id."),
                Field("hasItem", 0x38, "s32", "Item enable flag."),
                Field("hasYakumono", 0x3C, "s32", "Yakumono/object enable flag."),
                Field("unknownArray", 0x40, "HSDShortArray", "Unknown short array.", true)),
            Define(
                "kar.gr.data",
                "Map Gameplay Data",
                "Maps",
                "KAR_grData",
                "Top-level map gameplay data root used by Gr*.dat archives.",
                "HSDRaw/AirRide/Gr/Data/KAR_grData.cs",
                Field("unknown1", 0x00, "s32", "Unknown map header value."),
                Field("stageNode", 0x04, "KAR_grStageNode", "Stage setup node.", true),
                Field("stageParam", 0x08, "HSDAccessor", "Map-specific stage parameter block.", true),
                Field("lightNode", 0x14, "KAR_grLightGroup", "Lighting setup.", true),
                Field("collisionNode", 0x18, "KAR_grCollisionNode", "Collision geometry and collision metadata.", true),
                Field("splineNode", 0x1C, "KAR_grSplineNode", "Spline/path setup.", true),
                Field("positionNode", 0x20, "KAR_grPositionNode", "Spawn/death/item/vehicle position tables.", true),
                Field("subAnimNode", 0x24, "KAR_grSubAnimNode", "Map sub-animation table.", true),
                Field("enemyNode", 0x28, "HSDAccessor", "Enemy placement data.", true),
                Field("itemNode", 0x2C, "HSDArrayAccessor<KAR_grItemNode>", "Item timing and spawn data.", true),
                Field("fogNode", 0x34, "KAR_grFogNode", "Fog setup.", true),
                Field("railCollNode", 0x38, "KAR_grRailCollNode", "Rail collision data.", true),
                Field("fgmNode", 0x3C, "KAR_grFGMNode", "Map sound effect data.", true),
                Field("yakumonoNode", 0x40, "KAR_YakumonoNode", "Interactive map object data.", true),
                Field("replayNode", 0x44, "HSDAccessor", "Replay data.", true),
                Field("partitionNode", 0x48, "KAR_grCollisionTreeNode", "Collision partition tree.", true),
                Field("respawnNode", 0x4C, "KAR_grRespawnNode", "Respawn/dead-position lookup.", true),
                Field("stadiumNode", 0x50, "HSDAccessor", "Stadium-specific data.", true)),
            Define(
                "kar.gr.eventDataAll",
                "Map Event/Script Data",
                "Maps",
                null,
                "Top-level event/script root tied to a map bundle. The decomp names these roots grEventDataAll*.",
                "Map event archives and grEventDataAll* root naming",
                Field("eventScripts", null, "unknown", "Map event and script payloads. Exact structure still needs decomp/Ghidra backing.")),
        };
    }
}
