using KARToolkit.Core.AirRide;
using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectA2DPackage
    {
        private readonly KarProjectArchiveStore _archiveStore;

        internal KarProjectA2DPackage(
            KarProjectArchiveStore archiveStore,
            KarProjectFile file,
            string readPath,
            A2DPackage package)
        {
            _archiveStore = archiveStore ?? throw new ArgumentNullException(nameof(archiveStore));
            File = file ?? throw new ArgumentNullException(nameof(file));
            ReadPath = readPath ?? throw new ArgumentNullException(nameof(readPath));
            Package = package ?? throw new ArgumentNullException(nameof(package));
        }

        public KarProjectFile File { get; }

        public string RelativePath => File.RelativePath;

        public string ReadPath { get; }

        public A2DPackage Package { get; }

        public KarProjectFileWriteResult SaveToOutput()
        {
            return _archiveStore.SaveA2DPackageToOutput(RelativePath, Package);
        }
    }
}
