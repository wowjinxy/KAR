using HSDRaw;
using KARToolkit.Core.AirRide;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProject
    {
        private KarProject(
            KarProjectWorkspace workspace,
            KarProjectIndex index)
        {
            Workspace = workspace ?? throw new ArgumentNullException(nameof(workspace));
            Index = index ?? throw new ArgumentNullException(nameof(index));
            ArchiveInspector = KarArchiveInspector.Default;
            MapInspector = new KarMapInspector(ArchiveInspector);
        }

        public KarProjectWorkspace Workspace { get; }

        public KarProjectIndex Index { get; }

        public KarArchiveInspector ArchiveInspector { get; }

        public KarMapInspector MapInspector { get; }

        public string SourceRoot => Workspace.SourceRoot;

        public string Name => Workspace.Name;

        public string SourceFilesRoot => Workspace.SourceFilesRoot;

        public string OutputRoot => Workspace.OutputRoot;

        public string OutputFilesRoot => Workspace.OutputFilesRoot;

        public bool SourceHasFilesDirectory => Workspace.SourceHasFilesDirectory;

        public IReadOnlyList<KarProjectFile> Files => Index.Files;

        public IReadOnlyList<KarMapBundle> Maps => Index.Maps;

        public IReadOnlyDictionary<string, KarProjectFile> FilesByPath => Index.FilesByPath;

        public IReadOnlyDictionary<string, KarMapBundle> MapsByName => Index.MapsByName;

        public static KarProject Open(string sourceRoot)
        {
            return Open(sourceRoot, null);
        }

        public static KarProject Open(string sourceRoot, string outputRoot)
        {
            KarProjectWorkspace workspace = KarProjectWorkspace.Open(sourceRoot, outputRoot);
            KarProjectIndex index = KarProjectIndexer.Default.Build(workspace);
            return new KarProject(workspace, index);
        }

        public KarProjectFile GetFile(string relativePath)
        {
            return Index.GetFile(relativePath);
        }

        public bool TryGetFile(string relativePath, out KarProjectFile file)
        {
            return Index.TryGetFile(relativePath, out file);
        }

        public KarMapBundle GetMap(string mapNameOrPath)
        {
            return Index.GetMap(mapNameOrPath);
        }

        public bool TryGetMap(string mapNameOrPath, out KarMapBundle map)
        {
            return Index.TryGetMap(mapNameOrPath, out map);
        }

        public string GetReadPath(string relativePath)
        {
            return GetFile(relativePath).ReadPath;
        }

        public string GetSourcePath(string relativePath)
        {
            return GetFile(relativePath).SourcePath;
        }

        public string GetOutputPath(string relativePath)
        {
            return Workspace.GetOutputPath(relativePath);
        }

        public string CopyToOutput(string relativePath, bool overwrite = false)
        {
            var file = GetFile(relativePath);
            return Workspace.CopyToOutput(file.RelativePath, overwrite);
        }

        public IReadOnlyList<string> CopyMapToOutput(string mapNameOrPath, bool overwrite = false)
        {
            return CopyMapToOutput(GetMap(mapNameOrPath), overwrite);
        }

        public IReadOnlyList<string> CopyMapToOutput(KarMapBundle map, bool overwrite = false)
        {
            if (map == null)
                throw new ArgumentNullException(nameof(map));

            return map.Files
                .Select(file => CopyToOutput(file.RelativePath, overwrite))
                .ToList()
                .AsReadOnly();
        }

        public byte[] ReadBytes(string relativePath)
        {
            return File.ReadAllBytes(GetReadPath(relativePath));
        }

        public void WriteBytes(string relativePath, byte[] data)
        {
            if (data == null)
                throw new ArgumentNullException(nameof(data));

            Workspace.WriteBytes(relativePath, data);
        }

        public HSDRawFile OpenHsdFile(string relativePath)
        {
            return new HSDRawFile(GetReadPath(relativePath));
        }

        public KarArchiveInfo InspectHsdArchive(string relativePath)
        {
            KarProjectFile file = GetFile(relativePath);
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
            return InspectMap(GetMap(mapNameOrPath));
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

        public KarValidationReport Validate(KarValidationOptions options = null)
        {
            return new KarProjectValidator(this, options).Validate();
        }

        public bool TryOpenA2DPackage(string relativePath, out A2DPackage package, out string error)
        {
            return A2DPackage.TryOpen(GetReadPath(relativePath), out package, out error);
        }

        public A2DPackage OpenA2DPackage(string relativePath)
        {
            if (!TryOpenA2DPackage(relativePath, out A2DPackage package, out string error))
                throw new InvalidDataException(error);

            return package;
        }

        public string SaveHsdFile(string relativePath, HSDRawFile file, bool bufferAlign = true, bool optimize = true, bool trim = false)
        {
            if (file == null)
                throw new ArgumentNullException(nameof(file));

            return Workspace.SaveOutputFile(relativePath, tempPath => file.Save(tempPath, bufferAlign, optimize, trim));
        }

        public string SaveA2DPackage(string relativePath, A2DPackage package)
        {
            if (package == null)
                throw new ArgumentNullException(nameof(package));

            return Workspace.SaveOutputFile(relativePath, package.Save);
        }
    }
}
