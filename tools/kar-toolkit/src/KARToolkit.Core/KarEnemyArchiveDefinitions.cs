using System;
using static KARToolkit.Core.KarArchiveDefinitionFactory;
using static KARToolkit.Core.KarArchiveNameUtility;

namespace KARToolkit.Core
{
    internal static class KarEnemyArchiveDefinitions
    {
        public static KarArchiveDefinition DefineEnemy(string name, KarFileKind kind)
        {
            if (name.Equals("Enemy", StringComparison.OrdinalIgnoreCase))
                return Define(kind, "Enemy Data", "Enemies", "Enemy data table.", Root("emDataAll", "Enemy data table", null));

            string rootName = LowercaseFirst(name) + "Group";
            return Define(kind, "Enemy Data: " + StripPrefix(name, "Em"), "Enemies", "Enemy data group.", Root(rootName, "Enemy data group", "KAR_emData"));
        }
    }
}
