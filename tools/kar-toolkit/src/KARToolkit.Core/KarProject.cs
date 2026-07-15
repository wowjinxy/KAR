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
            KarProjectResourceHandlerRegistry resourceHandlers,
            KarArchiveInspector archiveInspector)
        {
            Workspace = workspace ?? throw new ArgumentNullException(nameof(workspace));
            Index = index ?? throw new ArgumentNullException(nameof(index));
            FileCatalog = fileCatalog ?? throw new ArgumentNullException(nameof(fileCatalog));
            ResourceHandlerRegistry = resourceHandlers ?? throw new ArgumentNullException(nameof(resourceHandlers));
            FileStore = new KarProjectFileStore(Workspace, Index);
            FileService = new KarProjectFileService(this);
            Inspector = new KarProjectInspector(Index, archiveInspector ?? KarArchiveInspector.Default);
            ResourceGraphService = new KarProjectResourceGraphService(this);
            ArchiveStore = new KarProjectArchiveStore(Workspace, FileStore, Inspector.ArchiveInspector, ResourceGraphService.Invalidate);
            ArchiveService = new KarProjectArchiveService(this);
            A2DService = new KarProjectA2DService(this);
            OutputService = new KarProjectOutputService(this);
            MapService = new KarProjectMapService(this);
            DataService = new KarProjectDataService(this);
            EditService = new KarProjectEditService(this);
            RelationshipService = new KarProjectRelationshipService(this);
            ResourceService = new KarProjectResourceService(this);
            ScriptService = new KarProjectScriptService(this);
            MapScriptService = new KarProjectMapScriptService(this);
            ModWorkspaceService = new KarProjectModWorkspaceService(this);
            Validator = new KarProjectValidator(this);
        }

        public KarProjectWorkspace Workspace { get; }

        public KarProjectIndex Index { get; }

        public KarProjectFileCatalog FileCatalog { get; }

        public KarProjectResourceHandlerRegistry ResourceHandlerRegistry { get; }

        public KarProjectFileStore FileStore { get; }

        public KarProjectFileService FileService { get; }

        public KarProjectArchiveStore ArchiveStore { get; }

        public KarProjectArchiveService ArchiveService { get; }

        public KarProjectA2DService A2DService { get; }

        public KarProjectOutputService OutputService { get; }

        public KarProjectMapService MapService { get; }

        public KarProjectDataService DataService { get; }

        public KarProjectEditService EditService { get; }

        public KarProjectResourceGraphService ResourceGraphService { get; }

        public KarProjectRelationshipService RelationshipService { get; }

        public KarProjectResourceService ResourceService { get; }

        public KarProjectScriptService ScriptService { get; }

        public KarProjectMapScriptService MapScriptService { get; }

        public KarProjectModWorkspaceService ModWorkspaceService { get; }

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
            return new KarProject(
                workspace,
                index,
                indexer.FileCatalog,
                options.ResolveResourceHandlerRegistry(),
                options.ResolveArchiveInspector());
        }

        public KarProjectFile GetFile(string relativePath)
        {
            return FileService.Get(relativePath);
        }

        public bool TryGetFile(string relativePath, out KarProjectFile file)
        {
            return FileService.TryGet(relativePath, out file);
        }

        public IReadOnlyList<KarProjectFile> QueryFiles(KarProjectFileQueryOptions options)
        {
            return FileService.Query(options);
        }

        public IReadOnlyList<KarArchiveInfo> QueryArchives(KarProjectFileQueryOptions options)
        {
            return ArchiveService.QueryHsdArchives(options);
        }

        public IReadOnlyList<KarProjectRootInfo> QueryRoots(KarProjectRootQueryOptions options)
        {
            return DataService.QueryRoots(options);
        }

        public IReadOnlyList<KarProjectRootSummary> QueryRootSummaries(KarProjectRootQueryOptions options)
        {
            return DataService.QueryRootSummaries(options);
        }

        public IReadOnlyList<KarProjectDataDefinitionUsage> QueryDataDefinitionUsage(KarProjectRootQueryOptions options)
        {
            return DataService.QueryDataDefinitionUsage(options);
        }

        public IReadOnlyList<KarProjectFieldInfo> QueryFieldValues(KarProjectFieldQueryOptions options)
        {
            return DataService.QueryFieldValues(options);
        }

        public IReadOnlyList<KarProjectFieldSummary> QueryFieldSummaries(KarProjectFieldQueryOptions options)
        {
            return DataService.QueryFieldSummaries(options);
        }

        public IReadOnlyList<KarProjectA2DEntryInfo> QueryA2DEntries(KarProjectA2DEntryQueryOptions options = null)
        {
            return A2DService.QueryEntries(options);
        }

        public IReadOnlyList<KarProjectA2DEntryOutputInfo> QueryA2DEntryOutputs(KarProjectA2DEntryOutputQueryOptions options = null)
        {
            return A2DService.QueryEntryOutputs(options);
        }

        public IReadOnlyList<KarProjectA2DEntryApplyResult> ApplyModifiedA2DEntryOutputs(KarProjectA2DEntryOutputQueryOptions options = null)
        {
            return A2DService.ApplyModifiedEntryOutputs(options);
        }

        public IReadOnlyList<KarProjectRelationship> QueryRelationships(KarProjectRelationshipQueryOptions options = null)
        {
            return RelationshipService.Query(options);
        }

        public IReadOnlyList<KarProjectRelationship> QueryMapRelationships(string mapNameOrPath)
        {
            return RelationshipService.QueryMap(mapNameOrPath);
        }

        public KarProjectResourceGraph CreateResourceGraph()
        {
            return ResourceGraphService.Snapshot;
        }

        public KarProjectResourceGraph RefreshResourceGraph()
        {
            return ResourceGraphService.Refresh();
        }

        public void InvalidateResourceGraph()
        {
            ResourceGraphService.Invalidate();
        }

        public IReadOnlyList<KarProjectResourceInfo> QueryResources(KarProjectResourceQueryOptions options = null)
        {
            return ResourceService.Query(options);
        }

        public IReadOnlyList<KarProjectResourceOutputInfo> QueryResourceOutputs(KarProjectResourceOutputQueryOptions options = null)
        {
            return ResourceService.QueryOutputs(options);
        }

        public KarProjectResourceInfo GetResource(string address)
        {
            return ResourceService.Get(address);
        }

        public KarProjectResourceOutputInfo GetResourceOutput(string address)
        {
            return ResourceService.GetOutput(address);
        }

        public IReadOnlyList<KarProjectResourceFieldInfo> QueryResourceFieldValues(KarProjectResourceFieldQueryOptions options = null)
        {
            return ResourceService.QueryFieldValues(options);
        }

        public KarProjectResourceFieldInfo GetResourceFieldValue(string rootAddress, string fieldName)
        {
            return ResourceService.GetFieldValue(rootAddress, fieldName);
        }

        public KarProjectResourceOutputApplyResult ApplyResourceOutput(string address)
        {
            return ResourceService.ApplyOutput(address);
        }

        public IReadOnlyList<KarProjectResourceOutputApplyResult> ApplyModifiedResourceOutputs(KarProjectResourceOutputQueryOptions options = null)
        {
            return ResourceService.ApplyModifiedOutputs(options);
        }

        public bool TryGetResource(string address, out KarProjectResourceInfo resource)
        {
            return ResourceService.TryGet(address, out resource);
        }

        public IReadOnlyList<KarProjectScriptTable> QueryScriptTables(KarProjectScriptTableQueryOptions options = null)
        {
            return ScriptService.QueryTables(options);
        }

        public KarProjectScriptTable GetScriptTable(string address)
        {
            return ScriptService.GetTable(address);
        }

        public IReadOnlyList<KarProjectMapScriptBundle> QueryMapScripts(KarProjectMapScriptQueryOptions options = null)
        {
            return MapScriptService.Query(options);
        }

        public KarProjectMapScriptBundle GetMapScripts(string mapNameOrPath, KarProjectScriptTableQueryOptions scriptTables = null)
        {
            return MapScriptService.Get(mapNameOrPath, scriptTables);
        }

        public byte[] ReadScriptTableBytes(string address)
        {
            return ScriptService.ReadTableBytes(address);
        }

        public byte[] ReadResourceBytes(string address)
        {
            return ResourceService.ReadBytes(address);
        }

        public KarProjectResourceExportResult ExportResourceToOutput(string address, bool overwrite = false)
        {
            return ResourceService.ExportToOutput(address, overwrite);
        }

        public KarProjectResourceExportResult ExportScriptTableToOutput(string address, bool overwrite = false)
        {
            return ScriptService.ExportTableToOutput(address, overwrite);
        }

        public KarProjectResourceExportResult ExportMapScriptArchiveToOutput(string mapNameOrPath, bool overwrite = false)
        {
            return MapScriptService.ExportScriptArchiveToOutput(mapNameOrPath, overwrite);
        }

        public KarProjectResourceImportResult ImportResourceFromFile(string address, string inputPath)
        {
            return ResourceService.ImportFromFile(address, inputPath);
        }

        public KarProjectResourceImportResult ImportScriptTableFromFile(string address, string inputPath)
        {
            return ScriptService.ImportTableFromFile(address, inputPath);
        }

        public KarProjectResourceScalarEditResult SetResourceScalarFieldFromText(string rootAddress, string fieldName, string rawValue)
        {
            return ResourceService.SetScalarFieldFromText(rootAddress, fieldName, rawValue);
        }

        public KarProjectReport CreateReport(KarProjectReportOptions options = null)
        {
            return new KarProjectReport(this, options);
        }

        public KarProjectModWorkspace CreateModWorkspace(KarProjectModWorkspaceOptions options = null)
        {
            return ModWorkspaceService.CreateSnapshot(options);
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
            return FileService.GetReadPath(relativePath);
        }

        public string GetSourcePath(string relativePath)
        {
            return FileService.GetSourcePath(relativePath);
        }

        public string GetOutputPath(string relativePath)
        {
            return FileService.GetOutputPath(relativePath);
        }

        public string CopyToOutput(string relativePath, bool overwrite = false)
        {
            return FileService.CopyToOutput(relativePath, overwrite);
        }

        public KarProjectFileCopyResult CopyFileToOutput(string relativePath, bool overwrite = false)
        {
            return FileService.CopyFileToOutput(relativePath, overwrite);
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
            return FileService.ReadBytes(relativePath);
        }

        public void WriteBytes(string relativePath, byte[] data)
        {
            FileService.WriteBytes(relativePath, data);
        }

        public KarProjectFileWriteResult WriteFileBytes(string relativePath, byte[] data)
        {
            return FileService.WriteFileBytes(relativePath, data);
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

        public KarProjectA2DEntryInfo GetA2DEntry(string packageEntryPath)
        {
            return A2DService.GetEntry(packageEntryPath);
        }

        public KarProjectA2DEntryExtractResult ExtractA2DEntryToOutput(string packageEntryPath, bool overwrite = false)
        {
            return A2DService.ExtractEntryToOutput(packageEntryPath, overwrite);
        }

        public KarProjectA2DEntryReplaceResult ReplaceA2DEntryFromFile(string packageEntryPath, string replacementPath)
        {
            return A2DService.ReplaceEntryFromFile(packageEntryPath, replacementPath);
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
