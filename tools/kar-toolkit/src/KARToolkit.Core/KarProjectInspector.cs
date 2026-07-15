using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectInspector
    {
        private readonly KarProjectIndex _index;

        public KarProjectInspector(KarProjectIndex index)
            : this(index, KarArchiveInspector.Default)
        {
        }

        public KarProjectInspector(KarProjectIndex index, KarArchiveInspector archiveInspector)
        {
            _index = index ?? throw new ArgumentNullException(nameof(index));
            ArchiveInspector = archiveInspector ?? throw new ArgumentNullException(nameof(archiveInspector));
            MapInspector = new KarMapInspector(ArchiveInspector);
        }

        public KarArchiveInspector ArchiveInspector { get; }

        public KarMapInspector MapInspector { get; }

        public KarArchiveInfo InspectHsdArchive(string relativePath)
        {
            KarProjectFile file = _index.GetFile(relativePath);
            return ArchiveInspector.Inspect(file);
        }

        public bool TryInspectHsdArchive(string relativePath, out KarArchiveInfo info, out string error)
        {
            try
            {
                info = InspectHsdArchive(relativePath);
                error = null;
                return true;
            }
            catch (Exception ex)
            {
                info = null;
                error = ex.Message;
                return false;
            }
        }

        public KarMapInfo InspectMap(string mapNameOrPath)
        {
            return InspectMap(_index.GetMap(mapNameOrPath));
        }

        public KarMapInfo InspectMap(KarMapBundle map)
        {
            return MapInspector.Inspect(map);
        }

        public bool TryInspectMap(string mapNameOrPath, out KarMapInfo info, out string error)
        {
            try
            {
                info = InspectMap(mapNameOrPath);
                error = null;
                return true;
            }
            catch (Exception ex)
            {
                info = null;
                error = ex.Message;
                return false;
            }
        }
    }
}
