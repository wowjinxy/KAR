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
            string sourceRoot,
            string sourceFilesRoot,
            string outputRoot,
            string outputFilesRoot,
            bool sourceHasFilesDirectory,
            IReadOnlyList<KarProjectFile> files,
            IReadOnlyList<KarMapBundle> maps)
        {
            SourceRoot = sourceRoot;
            SourceFilesRoot = sourceFilesRoot;
            OutputRoot = outputRoot;
            OutputFilesRoot = outputFilesRoot;
            SourceHasFilesDirectory = sourceHasFilesDirectory;
            Files = files;
            Maps = maps;
            _filesByPath = files.ToDictionary(f => f.RelativePath, StringComparer.OrdinalIgnoreCase);
            _mapsByName = maps.ToDictionary(map => map.Name, StringComparer.OrdinalIgnoreCase);
        }

        public string SourceRoot { get; }

        public string Name => Path.GetFileName(SourceRoot.TrimEnd(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar));

        public string SourceFilesRoot { get; }

        public string OutputRoot { get; }

        public string OutputFilesRoot { get; }

        public bool SourceHasFilesDirectory { get; }

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
            if (string.IsNullOrWhiteSpace(sourceRoot))
                throw new ArgumentException("Source root cannot be empty.", nameof(sourceRoot));

            var fullSourceRoot = Path.GetFullPath(sourceRoot);
            if (!Directory.Exists(fullSourceRoot))
                throw new DirectoryNotFoundException(fullSourceRoot);

            bool sourceHasFilesDirectory;
            var sourceFilesRoot = ResolveSourceFilesRoot(fullSourceRoot, out sourceHasFilesDirectory);
            var fullOutputRoot = string.IsNullOrWhiteSpace(outputRoot)
                ? GetDefaultOutputRoot(fullSourceRoot, sourceHasFilesDirectory)
                : Path.GetFullPath(outputRoot);
            var outputFilesRoot = sourceHasFilesDirectory
                ? Path.Combine(fullOutputRoot, "files")
                : fullOutputRoot;

            EnsureSeparateRoot(sourceFilesRoot, outputFilesRoot, "Output files root cannot be inside the source files root.");
            EnsureSeparateRoot(fullSourceRoot, fullOutputRoot, "Output root cannot be inside the source root.");
            EnsureSeparateRoot(fullOutputRoot, fullSourceRoot, "Source root cannot be inside the output root.");

            var files = BuildFileIndex(sourceFilesRoot, outputFilesRoot);
            var maps = BuildMapIndex(files);

            return new KarProject(
                fullSourceRoot,
                sourceFilesRoot,
                fullOutputRoot,
                outputFilesRoot,
                sourceHasFilesDirectory,
                files,
                maps);
        }

        public KarProjectFile GetFile(string relativePath)
        {
            KarProjectFile file;
            var normalized = NormalizeRelativePath(relativePath);
            if (!_filesByPath.TryGetValue(normalized, out file))
                throw new FileNotFoundException("Project file was not found.", normalized);
            return file;
        }

        public bool TryGetFile(string relativePath, out KarProjectFile file)
        {
            var normalized = NormalizeRelativePath(relativePath);
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
            return ResolveUnderRoot(OutputFilesRoot, NormalizeRelativePath(relativePath));
        }

        public string CopyToOutput(string relativePath, bool overwrite = false)
        {
            var file = GetFile(relativePath);
            var outputPath = PrepareOutputPath(file.RelativePath);

            if (overwrite || !File.Exists(outputPath))
                File.Copy(file.SourcePath, outputPath, overwrite);

            return outputPath;
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

            var normalized = NormalizeRelativePath(relativePath);
            var outputPath = PrepareOutputPath(normalized);
            var tempPath = outputPath + ".tmp";

            File.WriteAllBytes(tempPath, data);
            ReplaceFile(tempPath, outputPath);
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

            var normalized = NormalizeRelativePath(relativePath);
            var outputPath = PrepareOutputPath(normalized);
            var tempPath = outputPath + ".tmp";

            file.Save(tempPath, bufferAlign, optimize, trim);
            ReplaceFile(tempPath, outputPath);
            return outputPath;
        }

        public string SaveA2DPackage(string relativePath, A2DPackage package)
        {
            if (package == null)
                throw new ArgumentNullException(nameof(package));

            var normalized = NormalizeRelativePath(relativePath);
            var outputPath = PrepareOutputPath(normalized);
            var tempPath = outputPath + ".tmp";

            package.Save(tempPath);
            ReplaceFile(tempPath, outputPath);
            return outputPath;
        }

        private static string ResolveSourceFilesRoot(string sourceRoot, out bool sourceHasFilesDirectory)
        {
            var filesRoot = Path.Combine(sourceRoot, "files");
            if (Directory.Exists(filesRoot))
            {
                sourceHasFilesDirectory = true;
                return filesRoot;
            }

            sourceHasFilesDirectory = false;
            return sourceRoot;
        }

        private static string GetDefaultOutputRoot(string sourceRoot, bool sourceHasFilesDirectory)
        {
            if (sourceHasFilesDirectory)
                return sourceRoot + "_mod";

            var directoryName = Path.GetFileName(sourceRoot.TrimEnd(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar));
            var parent = Directory.GetParent(sourceRoot);
            if (string.Equals(directoryName, "files", StringComparison.OrdinalIgnoreCase) && parent != null && parent.Parent != null)
                return Path.Combine(parent.Parent.FullName, parent.Name + "_mod", "files");

            return sourceRoot + "_mod";
        }

        private static IReadOnlyList<KarProjectFile> BuildFileIndex(string sourceFilesRoot, string outputFilesRoot)
        {
            return Directory
                .EnumerateFiles(sourceFilesRoot, "*", SearchOption.AllDirectories)
                .Select(path =>
                {
                    var relativePath = GetRelativePath(sourceFilesRoot, path);
                    return new KarProjectFile(
                        relativePath,
                        path,
                        ResolveUnderRoot(outputFilesRoot, relativePath),
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

        private string PrepareOutputPath(string relativePath)
        {
            var outputPath = ResolveUnderRoot(OutputFilesRoot, relativePath);
            var parent = Path.GetDirectoryName(outputPath);
            if (!string.IsNullOrEmpty(parent))
                Directory.CreateDirectory(parent);
            return outputPath;
        }

        private static void ReplaceFile(string tempPath, string outputPath)
        {
            if (File.Exists(outputPath))
                File.Delete(outputPath);
            File.Move(tempPath, outputPath);
        }

        private static string NormalizeRelativePath(string relativePath)
        {
            if (string.IsNullOrWhiteSpace(relativePath))
                throw new ArgumentException("Relative path cannot be empty.", nameof(relativePath));
            if (Path.IsPathRooted(relativePath))
                throw new ArgumentException("Project paths must be relative.", nameof(relativePath));

            var parts = relativePath
                .Replace('\\', '/')
                .Split(new[] { '/' }, StringSplitOptions.RemoveEmptyEntries);

            if (parts.Length == 0)
                throw new ArgumentException("Relative path cannot be empty.", nameof(relativePath));

            foreach (var part in parts)
            {
                if (part == "." || part == "..")
                    throw new ArgumentException("Project paths cannot contain traversal segments.", nameof(relativePath));
            }

            return string.Join("/", parts);
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

        private static string ResolveUnderRoot(string root, string relativePath)
        {
            var normalized = NormalizeRelativePath(relativePath);
            var platformPath = normalized.Replace('/', Path.DirectorySeparatorChar);
            var fullPath = Path.GetFullPath(Path.Combine(root, platformPath));

            if (!IsSameOrChildPath(root, fullPath))
                throw new InvalidOperationException("Resolved path escaped its project root.");

            return fullPath;
        }

        private static string GetRelativePath(string root, string path)
        {
            var rootUri = new Uri(AppendDirectorySeparator(Path.GetFullPath(root)));
            var pathUri = new Uri(Path.GetFullPath(path));
            var relativeUri = rootUri.MakeRelativeUri(pathUri);
            return Uri.UnescapeDataString(relativeUri.ToString()).Replace('\\', '/');
        }

        private static string AppendDirectorySeparator(string path)
        {
            if (path.EndsWith(Path.DirectorySeparatorChar.ToString()) ||
                path.EndsWith(Path.AltDirectorySeparatorChar.ToString()))
            {
                return path;
            }

            return path + Path.DirectorySeparatorChar;
        }

        private static void EnsureSeparateRoot(string sourceRoot, string outputRoot, string message)
        {
            if (IsSameOrChildPath(sourceRoot, outputRoot))
                throw new InvalidOperationException(message);
        }

        private static bool IsSameOrChildPath(string root, string path)
        {
            var fullRoot = AppendDirectorySeparator(Path.GetFullPath(root));
            var fullPath = Path.GetFullPath(path);

            return fullPath.Equals(fullRoot.TrimEnd(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar), StringComparison.OrdinalIgnoreCase) ||
                fullPath.StartsWith(fullRoot, StringComparison.OrdinalIgnoreCase);
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
