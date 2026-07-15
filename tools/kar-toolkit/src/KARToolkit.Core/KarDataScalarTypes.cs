namespace KARToolkit.Core
{
    internal static class KarDataScalarTypes
    {
        public static bool TryResolve(string typeName, out KarDataScalarKind kind, out int size)
        {
            switch (Normalize(typeName))
            {
                case "s8":
                    kind = KarDataScalarKind.Signed;
                    size = 1;
                    return true;
                case "u8":
                case "byte":
                    kind = KarDataScalarKind.Unsigned;
                    size = 1;
                    return true;
                case "s16":
                    kind = KarDataScalarKind.Signed;
                    size = 2;
                    return true;
                case "u16":
                    kind = KarDataScalarKind.Unsigned;
                    size = 2;
                    return true;
                case "s32":
                case "int":
                case "int32":
                    kind = KarDataScalarKind.Signed;
                    size = 4;
                    return true;
                case "u32":
                case "uint":
                case "uint32":
                    kind = KarDataScalarKind.Unsigned;
                    size = 4;
                    return true;
                case "f32":
                case "float":
                case "single":
                    kind = KarDataScalarKind.Float;
                    size = 4;
                    return true;
                default:
                    kind = KarDataScalarKind.Signed;
                    size = 0;
                    return false;
            }
        }

        private static string Normalize(string typeName)
        {
            return (typeName ?? "").Trim().ToLowerInvariant();
        }
    }
}
