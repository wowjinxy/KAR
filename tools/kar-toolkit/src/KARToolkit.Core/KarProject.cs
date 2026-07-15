using HSDRaw;
using KARToolkit.Core.AirRide;
using System;
using System.Collections.Generic;

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
            FileStore = new KarProjectFileStore(Workspace, Index);
            Inspector = new KarProjectInspector(Index);
            Validator = new KarProjectValidator(this);
        }

        public KarProjectWorkspace Workspace { get; }

        public KarProjectIndex Index { get; }

        public KarProjectFileStore FileStore { get; }

        public KarProjectInspector Inspector { get; }

        public KarProjectValidator Validator { get; }

        public KarArchiveInspector ArchiveInspector => Inspector.ArchiveInspector;

        public KarMapInspector MapInspector => Inspector.MapInspector;

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
            return FileStore.GetReadPath(relativePath);
        }

        public string GetSourcePath(string relativePath)
        {
            return FileStore.GetSourcePath(relativePath);
        }

        public string GetOutputPath(string relativePath)
        {
            return FileStore.GetOutputPath(relativePath);
        }

        public string CopyToOutput(string relativePath, bool overwrite = false)
        {
            return FileStore.CopyToOutput(relativePath, overwrite);
        }

        public IReadOnlyList<string> CopyMapToOutput(string mapNameOrPath, bool overwrite = false)
        {
            return FileStore.CopyMapToOutput(mapNameOrPath, overwrite);
        }

        public IReadOnlyList<string> CopyMapToOutput(KarMapBundle map, bool overwrite = false)
        {
            return FileStore.CopyMapToOutput(map, overwrite);
        }

        public byte[] ReadBytes(string relativePath)
        {
            return FileStore.ReadBytes(relativePath);
        }

        public void WriteBytes(string relativePath, byte[] data)
        {
            FileStore.WriteBytes(relativePath, data);
        }

        public HSDRawFile OpenHsdFile(string relativePath)
        {
            return FileStore.OpenHsdFile(relativePath);
        }

        public KarArchiveInfo InspectHsdArchive(string relativePath)
        {
            return Inspector.InspectHsdArchive(relativePath);
        }

        public bool TryInspectHsdArchive(string relativePath, out KarArchiveInfo info, out string error)
        {
            return Inspector.TryInspectHsdArchive(relativePath, out info, out error);
        }

        public KarMapInfo InspectMap(string mapNameOrPath)
        {
            return Inspector.InspectMap(mapNameOrPath);
        }

        public KarMapInfo InspectMap(KarMapBundle map)
        {
            return Inspector.InspectMap(map);
        }

        public bool TryInspectMap(string mapNameOrPath, out KarMapInfo info, out string error)
        {
            return Inspector.TryInspectMap(mapNameOrPath, out info, out error);
        }

        public KarValidationReport Validate(KarValidationOptions options = null)
        {
            return Validator.Validate(options);
        }

        public bool TryOpenA2DPackage(string relativePath, out A2DPackage package, out string error)
        {
            return FileStore.TryOpenA2DPackage(relativePath, out package, out error);
        }

        public A2DPackage OpenA2DPackage(string relativePath)
        {
            return FileStore.OpenA2DPackage(relativePath);
        }

        public string SaveHsdFile(string relativePath, HSDRawFile file, bool bufferAlign = true, bool optimize = true, bool trim = false)
        {
            return FileStore.SaveHsdFile(relativePath, file, bufferAlign, optimize, trim);
        }

        public string SaveA2DPackage(string relativePath, A2DPackage package)
        {
            return FileStore.SaveA2DPackage(relativePath, package);
        }
    }
}
