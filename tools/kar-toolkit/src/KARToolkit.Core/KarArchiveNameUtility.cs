using System;

namespace KARToolkit.Core
{
    internal static class KarArchiveNameUtility
    {
        public static string StripPrefix(string value, string prefix)
        {
            if (value.StartsWith(prefix, StringComparison.OrdinalIgnoreCase))
                return value.Substring(prefix.Length);

            return value;
        }

        public static string LowercaseFirst(string value)
        {
            if (string.IsNullOrEmpty(value))
                return value;

            return char.ToLowerInvariant(value[0]) + value.Substring(1);
        }

        public static string ToRiderMotionName(string value)
        {
            int motionIndex = value.IndexOf("Motion", StringComparison.OrdinalIgnoreCase);
            if (motionIndex < 0)
                return value;

            string before = value.Substring(0, motionIndex);
            string after = value.Substring(motionIndex + "Motion".Length);
            return before + after;
        }
    }
}
