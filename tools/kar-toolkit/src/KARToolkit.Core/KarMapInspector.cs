using System;

namespace KARToolkit.Core
{
    public sealed class KarMapInspector
    {
        private readonly KarArchiveInspector _archiveInspector;

        public KarMapInspector()
            : this(KarArchiveInspector.Default)
        {
        }

        public KarMapInspector(KarArchiveInspector archiveInspector)
        {
            _archiveInspector = archiveInspector ?? throw new ArgumentNullException(nameof(archiveInspector));
        }

        public KarMapInfo Inspect(KarMapBundle map)
        {
            if (map == null)
                throw new ArgumentNullException(nameof(map));

            return new KarMapInfo(
                map,
                InspectOptionalArchive(map.DataFile),
                InspectOptionalArchive(map.ModelFile),
                InspectOptionalArchive(map.EventFile));
        }

        private KarArchiveInfo InspectOptionalArchive(KarProjectFile file)
        {
            if (file == null)
                return null;

            return _archiveInspector.Inspect(file);
        }
    }
}
