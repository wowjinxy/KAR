using HSDRaw;
using KARToolkit.Core.AirRide;
using System;
using System.IO;

namespace KARToolkit.Core
{
    public sealed class KarProjectArchiveStore
    {
        private readonly KarProjectWorkspace _workspace;
        private readonly KarProjectFileStore _fileStore;

        public KarProjectArchiveStore(KarProjectWorkspace workspace, KarProjectFileStore fileStore)
        {
            _workspace = workspace ?? throw new ArgumentNullException(nameof(workspace));
            _fileStore = fileStore ?? throw new ArgumentNullException(nameof(fileStore));
        }

        public HSDRawFile OpenHsdFile(string relativePath)
        {
            return new HSDRawFile(_fileStore.GetReadPath(relativePath));
        }

        public bool TryOpenA2DPackage(string relativePath, out A2DPackage package, out string error)
        {
            return A2DPackage.TryOpen(_fileStore.GetReadPath(relativePath), out package, out error);
        }

        public A2DPackage OpenA2DPackage(string relativePath)
        {
            A2DPackage package;
            string error;
            if (!TryOpenA2DPackage(relativePath, out package, out error))
                throw new InvalidDataException(error);

            return package;
        }

        public string SaveHsdFile(string relativePath, HSDRawFile file, bool bufferAlign = true, bool optimize = true, bool trim = false)
        {
            if (file == null)
                throw new ArgumentNullException(nameof(file));

            return _workspace.SaveOutputFile(relativePath, tempPath => file.Save(tempPath, bufferAlign, optimize, trim));
        }

        public string SaveA2DPackage(string relativePath, A2DPackage package)
        {
            if (package == null)
                throw new ArgumentNullException(nameof(package));

            return _workspace.SaveOutputFile(relativePath, package.Save);
        }
    }
}
