using System;
using System.IO;

namespace KARToolkit.Core
{
    public static class KarScriptTableCatalog
    {
        public static KarScriptTableInfo Describe(string tableNameOrPath)
        {
            string name = Path.GetFileName(tableNameOrPath);
            if (string.IsNullOrWhiteSpace(name))
                name = tableNameOrPath;

            if (StartsWith(name, "ScInf"))
                return new KarScriptTableInfo(name, "ScreenInfoTable", "Scripts", "2D screen information table. Names such as ScInfGo2D.tm are referenced by the game and stored in A2Info.dat.");

            if (StartsWith(name, "ScMen"))
                return new KarScriptTableInfo(name, "MenuTable", "Scripts", "2D menu table stored in an A2D package.");

            if (StartsWith(name, "a2dBG_"))
                return new KarScriptTableInfo(name, "BackgroundTable", "Scripts", "A2D background table stored in a matching A2a2dBG package.");

            if (StartsWith(name, "AC"))
                return new KarScriptTableInfo(name, "ActorTable", "Scripts", "Actor or character table stored in A2Kirby.dat.");

            if (StartsWith(name, "A2DOB_") || StartsWith(name, "OB"))
                return new KarScriptTableInfo(name, "ObjectTable", "Scripts", "Object table stored in an A2D package. OB1800.tm is loaded through the decomp-observed table lookup path.");

            if (StartsWith(name, "STAR"))
                return new KarScriptTableInfo(name, "VehicleTable", "Scripts", "Vehicle/star table stored in A2Kirby.dat.");

            if (EqualsName(name, "KIRBY.tm"))
                return new KarScriptTableInfo(name, "KirbyTable", "Scripts", "Kirby 2D table stored in A2Kirby.dat.");

            if (EqualsName(name, "GHOST.tm"))
                return new KarScriptTableInfo(name, "GhostTable", "Scripts", "Ghost 2D table stored in A2Kirby.dat.");

            return new KarScriptTableInfo(name, "ScriptTable", "Scripts", "2D script/table resource.");
        }

        private static bool StartsWith(string value, string prefix)
        {
            return value.StartsWith(prefix, StringComparison.OrdinalIgnoreCase);
        }

        private static bool EqualsName(string left, string right)
        {
            return string.Equals(left, right, StringComparison.OrdinalIgnoreCase);
        }
    }
}
