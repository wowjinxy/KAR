using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectMapArchiveBundle
    {
        internal KarProjectMapArchiveBundle(
            KarMapBundle bundle,
            KarProjectHsdArchive dataArchive,
            KarProjectHsdArchive modelArchive,
            KarProjectHsdArchive eventArchive)
        {
            Bundle = bundle ?? throw new ArgumentNullException(nameof(bundle));
            DataArchive = dataArchive;
            ModelArchive = modelArchive;
            EventArchive = eventArchive;

            List<KarProjectHsdArchive> archives = new List<KarProjectHsdArchive>();
            if (DataArchive != null)
                archives.Add(DataArchive);
            if (ModelArchive != null)
                archives.Add(ModelArchive);
            if (EventArchive != null)
                archives.Add(EventArchive);
            Archives = archives.AsReadOnly();
        }

        public KarMapBundle Bundle { get; }

        public string Name => Bundle.Name;

        public KarProjectHsdArchive DataArchive { get; }

        public KarProjectHsdArchive ModelArchive { get; }

        public KarProjectHsdArchive EventArchive { get; }

        public KarProjectHsdArchive ScriptArchive => EventArchive;

        public IReadOnlyList<KarProjectHsdArchive> Archives { get; }

        public bool HasDataArchive => DataArchive != null;

        public bool HasModelArchive => ModelArchive != null;

        public bool HasEventArchive => EventArchive != null;

        public bool HasScriptArchive => ScriptArchive != null;

        public IReadOnlyList<KarProjectFileWriteResult> SaveToOutput(bool bufferAlign = true, bool optimize = true, bool trim = false)
        {
            return SaveToOutputResult(bufferAlign, optimize, trim).WriteResults;
        }

        public KarProjectMapOutputResult SaveToOutputResult(bool bufferAlign = true, bool optimize = true, bool trim = false)
        {
            IReadOnlyList<KarProjectFileWriteResult> writeResults = Archives
                .Select(archive => archive.SaveToOutput(bufferAlign, optimize, trim))
                .ToList()
                .AsReadOnly();
            return new KarProjectMapOutputResult(Bundle, null, writeResults);
        }
    }
}
