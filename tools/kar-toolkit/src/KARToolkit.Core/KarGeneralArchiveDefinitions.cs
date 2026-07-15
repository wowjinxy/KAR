using System.IO;
using static KARToolkit.Core.KarArchiveDefinitionFactory;

namespace KARToolkit.Core
{
    internal static class KarGeneralArchiveDefinitions
    {
        public static KarArchiveDefinition DefineA2dPackage(KarFileKind kind)
        {
            return Define(kind, "A2D Package", "A2D", "Air Ride 2D package containing one or more embedded resources.");
        }

        public static KarArchiveDefinition DefineEffect(string name, KarFileKind kind)
        {
            return Define(
                kind,
                name + " Effects",
                "Effects",
                "Effect archive.",
                KarRootDefinition.Suffix("_texg", "Texture graphics", "HSD_TEXGraphicBank"),
                KarRootDefinition.Suffix("_ptcl", "Particle group", "HSD_ParticleGroup"));
        }

        public static KarArchiveDefinition DefineUi(string name, KarFileKind kind)
        {
            return Define(
                kind,
                name + " UI",
                "UI",
                "UI scene/model archive.",
                KarRootDefinition.Suffix("_scene_models", "Scene model list", "HSDNullPointerArrayAccessor<HSD_JOBJDesc>"),
                KarRootDefinition.Suffix("_scene_data", "Scene object", "HSD_SOBJ"));
        }

        public static KarArchiveDefinition DefineScriptTable(string fileName, KarFileKind kind)
        {
            KarScriptTableInfo info = KarScriptTableCatalog.Describe(fileName);
            return Define(kind, info.Name, info.Category, info.Description);
        }

        public static KarArchiveDefinition DefineAudio(string fileName, KarFileKind kind)
        {
            return Define(kind, fileName, "Audio", "Audio stream or sound bank.");
        }

        public static KarArchiveDefinition DefineMovie(string fileName, KarFileKind kind)
        {
            return Define(kind, fileName, "Movies", "Movie stream.");
        }

        public static KarArchiveDefinition DefineConfig(string fileName, KarFileKind kind)
        {
            return Define(kind, fileName, "Config", "Game configuration file.");
        }

        public static KarArchiveDefinition DefineFallback(string relativePath, KarFileKind kind)
        {
            return Define(kind, Path.GetFileName(relativePath), "Other", "HSD archive or unclassified project file.");
        }
    }
}
