using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarMapInfo
    {
        internal KarMapInfo(
            KarMapBundle bundle,
            KarArchiveInfo dataArchive,
            KarArchiveInfo modelArchive,
            KarArchiveInfo eventArchive)
        {
            Bundle = bundle;
            DataArchive = dataArchive;
            ModelArchive = modelArchive;
            EventArchive = eventArchive;

            List<KarArchiveInfo> archives = new List<KarArchiveInfo>();
            if (DataArchive != null)
                archives.Add(DataArchive);
            if (ModelArchive != null)
                archives.Add(ModelArchive);
            if (EventArchive != null)
                archives.Add(EventArchive);

            Archives = archives.AsReadOnly();
            MissingRequiredRoots = Archives
                .SelectMany(archive => archive.MissingRequiredRoots)
                .ToList()
                .AsReadOnly();
        }

        public KarMapBundle Bundle { get; }

        public string Name => Bundle.Name;

        public KarProjectFile DataFile => Bundle.DataFile;

        public KarProjectFile ModelFile => Bundle.ModelFile;

        public KarProjectFile EventFile => Bundle.EventFile;

        public KarProjectFile ScriptFile => Bundle.ScriptFile;

        public KarArchiveInfo DataArchive { get; }

        public KarArchiveInfo ModelArchive { get; }

        public KarArchiveInfo EventArchive { get; }

        public KarArchiveInfo ScriptArchive => EventArchive;

        public IReadOnlyList<KarArchiveInfo> Archives { get; }

        public IReadOnlyList<KarRootDefinition> MissingRequiredRoots { get; }

        public bool HasEventArchive => EventArchive != null;

        public bool HasScriptArchive => ScriptArchive != null;

        public bool HasMissingRequiredRoots => MissingRequiredRoots.Count != 0;

        public IReadOnlyList<KarArchiveRootInfo> EventRoots
        {
            get
            {
                if (EventArchive == null)
                    return System.Array.Empty<KarArchiveRootInfo>();

                return EventArchive.Roots;
            }
        }

        public IReadOnlyList<KarArchiveRootInfo> ScriptRoots => EventRoots;
    }
}
