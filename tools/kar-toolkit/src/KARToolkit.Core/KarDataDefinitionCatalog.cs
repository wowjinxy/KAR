using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public static class KarDataDefinitionCatalog
    {
        private static readonly IReadOnlyList<KarDataDefinition> Definitions = new[]
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
            Define(
                "kar.vs.legendary",
                "Legendary Machine Versus Data",
                "Versus",
                "KAR_vsLegendaryData",
                "Hydra/Dragoon versus-mode data root. The first three pointers are model animation, alternate/secondary model animation, and assembly effect resources.",
                "HSDRaw/AirRide/KAR_vsLegendaryData.cs; roots vsDataHydra/vsDataDragoon",
                Field("primaryModelAnimation", 0x00, "KAR_vsLegendaryModelAnimation", "Primary model, spline, and material animation bundle.", true, "kar.vs.legendary.modelAnimation"),
                Field("secondaryModelAnimation", 0x04, "KAR_vsLegendaryModelAnimation", "Secondary model, spline, and material animation bundle.", true, "kar.vs.legendary.modelAnimation"),
                Field("assemblyEffectResource", 0x08, "KAR_vsLegendaryEffectResource", "Effect resource used while the legendary machine assembles.", true, "kar.vs.legendary.effectResource"),
                Field("x0C", 0x0C, "s32", "Unknown scalar value."),
                Field("x10", 0x10, "s32", "Unknown scalar value.")),
            Define(
                "kar.vs.legendary.modelAnimation",
                "Legendary Model Animation",
                "Versus",
                "KAR_vsLegendaryModelAnimation",
                "Model and animation bundle used by legendary machine versus data.",
                "HSDRaw/AirRide/KAR_vsLegendaryData.cs",
                Field("rootJoint", 0x00, "HSD_JOBJ", "Root model joint.", true),
                Field("splineAnimation", 0x04, "KAR_vsLegendarySplineAnimation", "Spline animation data.", true),
                Field("materialAnimation", 0x08, "HSD_MatAnimJoint", "Material animation joint.", true)),
            Define(
                "kar.vs.legendary.effectResource",
                "Legendary Effect Resource",
                "Versus",
                "KAR_vsLegendaryEffectResource",
                "Pointer wrapper for legendary machine assembly effect data.",
                "HSDRaw/AirRide/KAR_vsLegendaryData.cs",
                Field("effectData", 0x00, "HSDAccessor", "Effect data resource.", true)),
        };

        private static readonly IReadOnlyDictionary<string, KarDataDefinition> DefinitionsById =
            Definitions.ToDictionary(definition => definition.Id, StringComparer.OrdinalIgnoreCase);

        private static readonly IReadOnlyDictionary<string, KarDataDefinition> DefinitionsByAccessor =
            Definitions
                .Where(definition => !string.IsNullOrWhiteSpace(definition.AccessorTypeName))
                .GroupBy(definition => definition.AccessorTypeName, StringComparer.Ordinal)
                .ToDictionary(group => group.Key, group => group.First(), StringComparer.Ordinal);

        public static IReadOnlyList<KarDataDefinition> All => Definitions;

        public static KarDataDefinition Get(string id)
        {
            KarDataDefinition definition;
            if (!TryGet(id, out definition))
                throw new KeyNotFoundException("KAR data definition was not found: " + id);

            return definition;
        }

        public static bool TryGet(string id, out KarDataDefinition definition)
        {
            definition = null;
            if (string.IsNullOrWhiteSpace(id))
                return false;

            return DefinitionsById.TryGetValue(id, out definition);
        }

        public static bool TryGetByAccessorTypeName(string accessorTypeName, out KarDataDefinition definition)
        {
            definition = null;
            if (string.IsNullOrWhiteSpace(accessorTypeName))
                return false;

            return DefinitionsByAccessor.TryGetValue(accessorTypeName, out definition);
        }

        public static bool TryFind(string idOrAccessorTypeName, out KarDataDefinition definition)
        {
            return TryGet(idOrAccessorTypeName, out definition) ||
                TryGetByAccessorTypeName(idOrAccessorTypeName, out definition);
        }

        private static KarDataDefinition Define(
            string id,
            string displayName,
            string category,
            string accessorTypeName,
            string description,
            string source,
            params KarDataFieldDefinition[] fields)
        {
            return new KarDataDefinition(id, displayName, category, accessorTypeName, description, source, fields);
        }

        private static KarDataFieldDefinition Field(
            string name,
            int? offset,
            string typeName,
            string description,
            bool isPointer = false,
            string dataDefinitionId = null)
        {
            return new KarDataFieldDefinition(name, offset, typeName, description, isPointer, dataDefinitionId);
        }
    }
}
