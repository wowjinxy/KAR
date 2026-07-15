using HSDRaw;
using KARToolkit.Core.AirRide;
using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProject
    {
        private KarProject(
            KarProjectWorkspace workspace,
            KarProjectIndex index,
            KarProjectFileCatalog fileCatalog,
            KarArchiveInspector archiveInspector)
        {
            Workspace = workspace ?? throw new ArgumentNullException(nameof(workspace));
            Index = index ?? throw new ArgumentNullException(nameof(index));
            FileCatalog = fileCatalog ?? throw new ArgumentNullException(nameof(fileCatalog));
            FileStore = new KarProjectFileStore(Workspace, Index);
            Inspector = new KarProjectInspector(Index, archiveInspector ?? KarArchiveInspector.Default);
            ArchiveStore = new KarProjectArchiveStore(Workspace, FileStore, Inspector.ArchiveInspector);
            ArchiveService = new KarProjectArchiveService(this);
            OutputService = new KarProjectOutputService(this);
            MapService = new KarProjectMapService(this);
            Validator = new KarProjectValidator(this);
        }

        public KarProjectWorkspace Workspace { get; }

        public KarProjectIndex Index { get; }

        public KarProjectFileCatalog FileCatalog { get; }

        public KarProjectFileStore FileStore { get; }

        public KarProjectArchiveStore ArchiveStore { get; }

        public KarProjectArchiveService ArchiveService { get; }

        public KarProjectOutputService OutputService { get; }

        public KarProjectMapService MapService { get; }

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
            return Open(new KarProjectOptions
            {
                SourceRoot = sourceRoot,
                OutputRoot = outputRoot,
            });
        }

        public static KarProject Open(KarProjectOptions options)
        {
            if (options == null)
                throw new ArgumentNullException(nameof(options));

            KarProjectWorkspace workspace = KarProjectWorkspace.Open(options.SourceRoot, options.OutputRoot);
            KarProjectIndexer indexer = options.ResolveIndexer();
            KarProjectIndex index = indexer.Build(workspace);
            return new KarProject(workspace, index, indexer.FileCatalog, options.ResolveArchiveInspector());
        }

        public KarProjectFile GetFile(string relativePath)
        {
            return Index.GetFile(relativePath);
        }

        public bool TryGetFile(string relativePath, out KarProjectFile file)
        {
            return Index.TryGetFile(relativePath, out file);
        }

        public IReadOnlyList<KarProjectFile> QueryFiles(KarProjectFileQueryOptions options)
        {
            return Index.QueryFiles(options);
        }

        public IReadOnlyList<KarArchiveInfo> QueryArchives(KarProjectFileQueryOptions options)
        {
            return ArchiveService.QueryHsdArchives(options);
        }

        public IReadOnlyList<KarProjectRootInfo> QueryRoots(KarProjectRootQueryOptions options)
        {
            List<KarProjectRootInfo> roots = new List<KarProjectRootInfo>();

            foreach (KarArchiveInfo archive in QueryArchives(options == null ? null : options.Files))
            {
                foreach (KarArchiveRootInfo root in archive.Roots)
                {
                    KarProjectRootInfo projectRoot = new KarProjectRootInfo(archive.File, root);
                    if (options == null || options.Matches(projectRoot))
                        roots.Add(projectRoot);
                }
            }

            return roots.AsReadOnly();
        }

        public IReadOnlyList<KarProjectRootSummary> QueryRootSummaries(KarProjectRootQueryOptions options)
        {
            return QueryRoots(options)
                .GroupBy(root => new
                {
                    root.RootName,
                    root.IsKnown,
                    root.DisplayAccessorTypeName,
                    root.DataDefinitionId,
                })
                .Select(group => new KarProjectRootSummary(
                    group.Key.RootName,
                    group.Key.IsKnown,
                    group.Key.DisplayAccessorTypeName,
                    group.Key.DataDefinitionId,
                    group.OrderBy(root => root.RelativePath, StringComparer.OrdinalIgnoreCase)))
                .ToList()
                .AsReadOnly();
        }

        public IReadOnlyList<KarProjectDataDefinitionUsage> QueryDataDefinitionUsage(KarProjectRootQueryOptions options)
        {
            return QueryRoots(options)
                .Where(root => root.Root.DataDefinition != null)
                .GroupBy(root => root.Root.DataDefinition.Id, StringComparer.OrdinalIgnoreCase)
                .Select(group => new KarProjectDataDefinitionUsage(
                    group.First().Root.DataDefinition,
                    group.OrderBy(root => root.RelativePath, StringComparer.OrdinalIgnoreCase)
                        .ThenBy(root => root.RootName, StringComparer.Ordinal)))
                .ToList()
                .AsReadOnly();
        }

        public IReadOnlyList<KarProjectFieldInfo> QueryFieldValues(KarProjectFieldQueryOptions options)
        {
            List<KarProjectFieldInfo> fields = new List<KarProjectFieldInfo>();

            foreach (KarProjectRootInfo root in QueryRoots(options == null ? null : options.Roots))
            {
                if (root.Root.DataDefinition == null || !root.Root.HasFieldValues)
                    continue;

                foreach (KarDataFieldValue value in root.Root.FieldValues)
                {
                    KarProjectFieldInfo field = new KarProjectFieldInfo(root, value);
                    if (options == null || options.Matches(field))
                        fields.Add(field);
                }
            }

            return fields.AsReadOnly();
        }

        public IReadOnlyList<KarProjectFieldSummary> QueryFieldSummaries(KarProjectFieldQueryOptions options)
        {
            return QueryFieldValues(options)
                .GroupBy(field => field.DataDefinitionId + "\u001F" + field.FieldName, StringComparer.OrdinalIgnoreCase)
                .Select(group => new KarProjectFieldSummary(
                    group.First().ArchiveRoot.DataDefinition,
                    group.First().Field,
                    group))
                .ToList()
                .AsReadOnly();
        }

        public KarProjectReport CreateReport(KarProjectReportOptions options = null)
        {
            return new KarProjectReport(this, options);
        }

        public IReadOnlyList<KarProjectOutputFileInfo> QueryOutputFiles(KarProjectOutputFileQueryOptions options)
        {
            return OutputService.QueryFiles(options);
        }

        public KarProjectOutputInventory CreateOutputInventory(KarProjectOutputFileQueryOptions options = null)
        {
            return OutputService.CreateInventory(options);
        }

        public IReadOnlyList<KarProjectMapOutputInfo> QueryMapOutputs(KarProjectMapOutputQueryOptions options)
        {
            return MapService.QueryOutputs(options);
        }

        public KarMapBundle GetMap(string mapNameOrPath)
        {
            return MapService.Get(mapNameOrPath);
        }

        public bool TryGetMap(string mapNameOrPath, out KarMapBundle map)
        {
            return MapService.TryGet(mapNameOrPath, out map);
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

        public KarProjectFileCopyResult CopyFileToOutput(string relativePath, bool overwrite = false)
        {
            return FileStore.CopyFileToOutput(relativePath, overwrite);
        }

        public IReadOnlyList<string> CopyMapToOutput(string mapNameOrPath, bool overwrite = false)
        {
            return MapService.CopyToOutput(mapNameOrPath, overwrite);
        }

        public IReadOnlyList<string> CopyMapToOutput(KarMapBundle map, bool overwrite = false)
        {
            return MapService.CopyToOutput(map, overwrite);
        }

        public KarProjectMapOutputResult CopyMapToOutputResult(string mapNameOrPath, bool overwrite = false)
        {
            return MapService.CopyToOutputResult(mapNameOrPath, overwrite);
        }

        public KarProjectMapOutputResult CopyMapToOutputResult(KarMapBundle map, bool overwrite = false)
        {
            return MapService.CopyToOutputResult(map, overwrite);
        }

        public IReadOnlyList<KarProjectFileCopyResult> CopyMapFilesToOutput(string mapNameOrPath, bool overwrite = false)
        {
            return MapService.CopyFilesToOutput(mapNameOrPath, overwrite);
        }

        public IReadOnlyList<KarProjectFileCopyResult> CopyMapFilesToOutput(KarMapBundle map, bool overwrite = false)
        {
            return MapService.CopyFilesToOutput(map, overwrite);
        }

        public byte[] ReadBytes(string relativePath)
        {
            return FileStore.ReadBytes(relativePath);
        }

        public void WriteBytes(string relativePath, byte[] data)
        {
            FileStore.WriteBytes(relativePath, data);
        }

        public KarProjectFileWriteResult WriteFileBytes(string relativePath, byte[] data)
        {
            return FileStore.WriteFileBytes(relativePath, data);
        }

        public HSDRawFile OpenHsdFile(string relativePath)
        {
            return ArchiveService.OpenHsdFile(relativePath);
        }

        public KarProjectHsdArchive OpenHsdArchive(string relativePath)
        {
            return ArchiveService.OpenHsdArchive(relativePath);
        }

        public KarProjectMapArchiveBundle OpenMapArchives(string mapNameOrPath)
        {
            return MapService.OpenArchives(mapNameOrPath);
        }

        public KarProjectMapArchiveBundle OpenMapArchives(KarMapBundle map)
        {
            return MapService.OpenArchives(map);
        }

        public KarArchiveInfo InspectHsdArchive(string relativePath)
        {
            return ArchiveService.InspectHsdArchive(relativePath);
        }

        public bool TryInspectHsdArchive(string relativePath, out KarArchiveInfo info, out string error)
        {
            return ArchiveService.TryInspectHsdArchive(relativePath, out info, out error);
        }

        public KarMapInfo InspectMap(string mapNameOrPath)
        {
            return MapService.Inspect(mapNameOrPath);
        }

        public KarMapInfo InspectMap(KarMapBundle map)
        {
            return MapService.Inspect(map);
        }

        public bool TryInspectMap(string mapNameOrPath, out KarMapInfo info, out string error)
        {
            return MapService.TryInspect(mapNameOrPath, out info, out error);
        }

        public KarValidationReport Validate(KarValidationOptions options = null)
        {
            return Validator.Validate(options);
        }

        public bool TryOpenA2DPackage(string relativePath, out A2DPackage package, out string error)
        {
            return ArchiveService.TryOpenA2DPackage(relativePath, out package, out error);
        }

        public bool TryOpenProjectA2DPackage(string relativePath, out KarProjectA2DPackage package, out string error)
        {
            return ArchiveService.TryOpenProjectA2DPackage(relativePath, out package, out error);
        }

        public A2DPackage OpenA2DPackage(string relativePath)
        {
            return ArchiveService.OpenA2DPackage(relativePath);
        }

        public KarProjectA2DPackage OpenProjectA2DPackage(string relativePath)
        {
            return ArchiveService.OpenProjectA2DPackage(relativePath);
        }

        public string SaveHsdFile(string relativePath, HSDRawFile file, bool bufferAlign = true, bool optimize = true, bool trim = false)
        {
            return ArchiveService.SaveHsdFile(relativePath, file, bufferAlign, optimize, trim);
        }

        public KarProjectFileWriteResult SaveHsdFileToOutput(string relativePath, HSDRawFile file, bool bufferAlign = true, bool optimize = true, bool trim = false)
        {
            return ArchiveService.SaveHsdFileToOutput(relativePath, file, bufferAlign, optimize, trim);
        }

        public string SaveA2DPackage(string relativePath, A2DPackage package)
        {
            return ArchiveService.SaveA2DPackage(relativePath, package);
        }

        public KarProjectFileWriteResult SaveA2DPackageToOutput(string relativePath, A2DPackage package)
        {
            return ArchiveService.SaveA2DPackageToOutput(relativePath, package);
        }
    }
}
