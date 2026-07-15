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
        private readonly Dictionary<string, KarProjectFile> _filesByPath;
        private readonly Dictionary<string, KarMapBundle> _mapsByName;

        private KarProject(
            KarProjectWorkspace workspace,
            IReadOnlyList<KarProjectFile> files,
            IReadOnlyList<KarMapBundle> maps)
        {
            Workspace = workspace ?? throw new ArgumentNullException(nameof(workspace));
            Files = files;
            Maps = maps;
            _filesByPath = files.ToDictionary(f => f.RelativePath, StringComparer.OrdinalIgnoreCase);
            _mapsByName = maps.ToDictionary(map => map.Name, StringComparer.OrdinalIgnoreCase);
        }

        public KarProjectWorkspace Workspace { get; }

        public string SourceRoot => Workspace.SourceRoot;

        public string Name => Workspace.Name;

        public string SourceFilesRoot => Workspace.SourceFilesRoot;

        public string OutputRoot => Workspace.OutputRoot;

        public string OutputFilesRoot => Workspace.OutputFilesRoot;

        public bool SourceHasFilesDirectory => Workspace.SourceHasFilesDirectory;

        public IReadOnlyList<KarProjectFile> Files { get; }

        public IReadOnlyList<KarMapBundle> Maps { get; }

        public IReadOnlyDictionary<string, KarProjectFile> FilesByPath => _filesByPath;

        public IReadOnlyDictionary<string, KarMapBundle> MapsByName => _mapsByName;

        public static KarProject Open(string sourceRoot)
        {
            return Open(sourceRoot, null);
        }

        public static KarProject Open(string sourceRoot, string outputRoot)
        {
            KarProjectWorkspace workspace = KarProjectWorkspace.Open(sourceRoot, outputRoot);
            var files = BuildFileIndex(workspace);
            var maps = BuildMapIndex(files);

            return new KarProject(workspace, files, maps);
        }

        public KarProjectFile GetFile(string relativePath)
        {
            KarProjectFile file;
            var normalized = KarProjectWorkspace.NormalizeRelativePath(relativePath);
            if (!_filesByPath.TryGetValue(normalized, out file))
                throw new FileNotFoundException("Project file was not found.", normalized);
            return file;
        }

        public bool TryGetFile(string relativePath, out KarProjectFile file)
        {
            var normalized = KarProjectWorkspace.NormalizeRelativePath(relativePath);
            return _filesByPath.TryGetValue(normalized, out file);
        }

        public KarMapBundle GetMap(string mapNameOrPath)
        {
            KarMapBundle map;
            if (!TryGetMap(mapNameOrPath, out map))
                throw new KeyNotFoundException("Project map was not found: " + mapNameOrPath);

            return map;
        }

        public bool TryGetMap(string mapNameOrPath, out KarMapBundle map)
        {
            map = null;
            if (string.IsNullOrWhiteSpace(mapNameOrPath))
                return false;

            string normalized = NormalizeMapName(mapNameOrPath);
            return _mapsByName.TryGetValue(normalized, out map);
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
            return KarArchiveCatalog.Inspect(file, OpenHsdFile(file.RelativePath));
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
            if (map == null)
                throw new ArgumentNullException(nameof(map));

            return new KarMapInfo(
                map,
                InspectOptionalArchive(map.DataFile),
                InspectOptionalArchive(map.ModelFile),
                InspectOptionalArchive(map.EventFile));
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

        private static IReadOnlyList<KarProjectFile> BuildFileIndex(KarProjectWorkspace workspace)
        {
            return Directory
                .EnumerateFiles(workspace.SourceFilesRoot, "*", SearchOption.AllDirectories)
                .Select(path =>
                {
                    var relativePath = workspace.GetRelativeSourcePath(path);
                    return new KarProjectFile(
                        relativePath,
                        path,
                        workspace.GetOutputPath(relativePath),
                        KarArchiveCatalog.ClassifyKind(relativePath));
                })
                .OrderBy(file => file.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        private static IReadOnlyList<KarMapBundle> BuildMapIndex(IReadOnlyList<KarProjectFile> files)
        {
            var builders = new Dictionary<string, MapBundleBuilder>(StringComparer.OrdinalIgnoreCase);

            foreach (var file in files)
            {
                string mapName;
                if (!TryGetMapName(file, out mapName))
                    continue;

                MapBundleBuilder builder;
                if (!builders.TryGetValue(mapName, out builder))
                {
                    builder = new MapBundleBuilder(mapName);
                    builders.Add(mapName, builder);
                }

                builder.Add(file);
            }

            return builders
                .Values
                .Select(builder => builder.Build())
                .OrderBy(map => map.Name, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        private static bool TryGetMapName(KarProjectFile file, out string mapName)
        {
            return KarArchiveCatalog.TryGetMapName(file.RelativePath, file.Kind, out mapName);
        }

        private KarArchiveInfo InspectOptionalArchive(KarProjectFile file)
        {
            if (file == null)
                return null;

            return InspectHsdArchive(file.RelativePath);
        }

        private static string NormalizeMapName(string mapNameOrPath)
        {
            string name = Path.GetFileNameWithoutExtension(mapNameOrPath.Trim());
            if (string.IsNullOrWhiteSpace(name))
                return name;

            if (name.StartsWith("Gr", StringComparison.OrdinalIgnoreCase))
                name = name.Substring(2);

            if (name.EndsWith("Model", StringComparison.OrdinalIgnoreCase))
                name = name.Substring(0, name.Length - "Model".Length);
            else if (name.EndsWith("Event", StringComparison.OrdinalIgnoreCase))
                name = name.Substring(0, name.Length - "Event".Length);

            return name;
        }

        private sealed class MapBundleBuilder
        {
            public MapBundleBuilder(string name)
            {
                Name = name;
            }

            public string Name { get; }

            public KarProjectFile DataFile { get; private set; }

            public KarProjectFile ModelFile { get; private set; }

            public KarProjectFile EventFile { get; private set; }

            public void Add(KarProjectFile file)
            {
                switch (file.Kind)
                {
                    case KarFileKind.MapData:
                        DataFile = file;
                        break;
                    case KarFileKind.MapModel:
                        ModelFile = file;
                        break;
                    case KarFileKind.MapEvent:
                        EventFile = file;
                        break;
                }
            }

            public KarMapBundle Build()
            {
                return new KarMapBundle(Name, DataFile, ModelFile, EventFile);
            }
        }
    }
}
