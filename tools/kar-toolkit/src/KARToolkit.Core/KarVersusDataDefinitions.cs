using System.Collections.Generic;
using static KARToolkit.Core.KarDataDefinitionFactory;

namespace KARToolkit.Core
{
    internal static class KarVersusDataDefinitions
    {
        public static IReadOnlyList<KarDataDefinition> All { get; } = new[]
        {
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
    }
}
