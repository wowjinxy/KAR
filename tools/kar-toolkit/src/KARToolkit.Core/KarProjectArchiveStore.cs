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
            return SaveHsdFileToOutput(relativePath, file, bufferAlign, optimize, trim).OutputPath;
        }

        public KarProjectFileWriteResult SaveHsdFileToOutput(string relativePath, HSDRawFile file, bool bufferAlign = true, bool optimize = true, bool trim = false)
        {
            if (file == null)
                throw new ArgumentNullException(nameof(file));

            string outputPath = _workspace.SaveOutputFile(relativePath, tempPath => file.Save(tempPath, bufferAlign, optimize, trim));
            return _fileStore.CreateWriteResult(relativePath, outputPath);
        }

        public string SaveA2DPackage(string relativePath, A2DPackage package)
        {
            return SaveA2DPackageToOutput(relativePath, package).OutputPath;
        }

        public KarProjectFileWriteResult SaveA2DPackageToOutput(string relativePath, A2DPackage package)
        {
            if (package == null)
                throw new ArgumentNullException(nameof(package));

            string outputPath = _workspace.SaveOutputFile(relativePath, package.Save);
            return _fileStore.CreateWriteResult(relativePath, outputPath);
        }
    }
}
