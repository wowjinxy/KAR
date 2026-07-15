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
            return OpenHsdArchive(relativePath).Archive;
        }

        public KarProjectHsdArchive OpenHsdArchive(string relativePath)
        {
            KarProjectFile file = _fileStore.GetFile(relativePath);
            string readPath = file.ReadPath;
            return new KarProjectHsdArchive(this, file, readPath, new HSDRawFile(readPath));
        }

        public bool TryOpenA2DPackage(string relativePath, out A2DPackage package, out string error)
        {
            KarProjectA2DPackage projectPackage;
            if (!TryOpenProjectA2DPackage(relativePath, out projectPackage, out error))
            {
                package = null;
                return false;
            }

            package = projectPackage.Package;
            return true;
        }

        public bool TryOpenProjectA2DPackage(string relativePath, out KarProjectA2DPackage projectPackage, out string error)
        {
            projectPackage = null;
            KarProjectFile file = _fileStore.GetFile(relativePath);
            string readPath = file.ReadPath;

            A2DPackage package;
            if (!A2DPackage.TryOpen(readPath, out package, out error))
                return false;

            projectPackage = new KarProjectA2DPackage(this, file, readPath, package);
            return true;
        }

        public A2DPackage OpenA2DPackage(string relativePath)
        {
            return OpenProjectA2DPackage(relativePath).Package;
        }

        public KarProjectA2DPackage OpenProjectA2DPackage(string relativePath)
        {
            KarProjectA2DPackage projectPackage;
            string error;
            if (!TryOpenProjectA2DPackage(relativePath, out projectPackage, out error))
                throw new InvalidDataException(error);

            return projectPackage;
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
