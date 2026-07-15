using HSDRaw;
using KARToolkit.Core.AirRide;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectArchiveService
    {
        private readonly KarProject _project;

        internal KarProjectArchiveService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public KarArchiveInspector Inspector => _project.ArchiveInspector;

        public IReadOnlyList<KarArchiveInfo> QueryArchives(KarProjectFileQueryOptions options = null)
        {
            return QueryHsdArchives(options);
        }

        public IReadOnlyList<KarArchiveInfo> QueryHsdArchives(KarProjectFileQueryOptions options = null)
        {
            return _project.FileService.Query(options)
                .Where(file => file.IsHsdArchive)
                .Select(Inspect)
                .ToList()
                .AsReadOnly();
        }

        public KarArchiveInfo Inspect(KarProjectFile file)
        {
            if (file == null)
                throw new ArgumentNullException(nameof(file));

            return Inspector.Inspect(file);
        }

        public KarArchiveInfo InspectHsdArchive(string relativePath)
        {
            return Inspect(_project.FileService.Get(relativePath));
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

        public HSDRawFile OpenHsdFile(string relativePath)
        {
            return _project.ArchiveStore.OpenHsdFile(relativePath);
        }

        public KarProjectHsdArchive OpenHsdArchive(string relativePath)
        {
            return _project.ArchiveStore.OpenHsdArchive(relativePath);
        }

        public KarProjectMapArchiveBundle OpenMapArchives(KarMapBundle map)
        {
            return _project.ArchiveStore.OpenMapArchives(map);
        }

        public bool TryOpenA2DPackage(string relativePath, out A2DPackage package, out string error)
        {
            return _project.ArchiveStore.TryOpenA2DPackage(relativePath, out package, out error);
        }

        public bool TryOpenProjectA2DPackage(string relativePath, out KarProjectA2DPackage package, out string error)
        {
            return _project.ArchiveStore.TryOpenProjectA2DPackage(relativePath, out package, out error);
        }

        public A2DPackage OpenA2DPackage(string relativePath)
        {
            return _project.ArchiveStore.OpenA2DPackage(relativePath);
        }

        public KarProjectA2DPackage OpenProjectA2DPackage(string relativePath)
        {
            return _project.ArchiveStore.OpenProjectA2DPackage(relativePath);
        }

        public string SaveHsdFile(string relativePath, HSDRawFile file, bool bufferAlign = true, bool optimize = true, bool trim = false)
        {
            return SaveHsdFileToOutput(relativePath, file, bufferAlign, optimize, trim).OutputPath;
        }

        public KarProjectFileWriteResult SaveHsdFileToOutput(string relativePath, HSDRawFile file, bool bufferAlign = true, bool optimize = true, bool trim = false)
        {
            return _project.ArchiveStore.SaveHsdFileToOutput(relativePath, file, bufferAlign, optimize, trim);
        }

        public string SaveA2DPackage(string relativePath, A2DPackage package)
        {
            return SaveA2DPackageToOutput(relativePath, package).OutputPath;
        }

        public KarProjectFileWriteResult SaveA2DPackageToOutput(string relativePath, A2DPackage package)
        {
            return _project.ArchiveStore.SaveA2DPackageToOutput(relativePath, package);
        }
    }
}
