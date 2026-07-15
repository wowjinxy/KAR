using HSDRaw;
using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectHsdArchive
    {
        private readonly KarProjectArchiveStore _archiveStore;

        internal KarProjectHsdArchive(
            KarProjectArchiveStore archiveStore,
            KarProjectFile file,
            string readPath,
            HSDRawFile archive)
        {
            _archiveStore = archiveStore ?? throw new ArgumentNullException(nameof(archiveStore));
            File = file ?? throw new ArgumentNullException(nameof(file));
            ReadPath = readPath ?? throw new ArgumentNullException(nameof(readPath));
            Archive = archive ?? throw new ArgumentNullException(nameof(archive));
        }

        public KarProjectFile File { get; }

        public string RelativePath => File.RelativePath;

        public string ReadPath { get; }

        public HSDRawFile Archive { get; }

        public KarProjectFileWriteResult SaveToOutput(bool bufferAlign = true, bool optimize = true, bool trim = false)
        {
            return _archiveStore.SaveHsdFileToOutput(RelativePath, Archive, bufferAlign, optimize, trim);
        }
    }
}
