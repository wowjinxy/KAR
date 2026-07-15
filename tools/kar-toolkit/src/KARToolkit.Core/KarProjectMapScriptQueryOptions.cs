using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectMapScriptQueryOptions
    {
        public string MapNameOrPath { get; set; }

        public KarProjectScriptTableQueryOptions ScriptTables { get; set; }

        public bool? HasScriptArchive { get; set; }

        public bool? HasScriptTables { get; set; }

        public bool Matches(KarProjectMapScriptBundle bundle)
        {
            if (bundle == null)
                throw new ArgumentNullException(nameof(bundle));

            if (HasScriptArchive.HasValue && bundle.HasScriptArchive != HasScriptArchive.Value)
                return false;
            if (HasScriptTables.HasValue && bundle.HasScriptTables != HasScriptTables.Value)
                return false;

            return true;
        }
    }
}
