using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectIndex
    {
        private readonly Dictionary<string, KarProjectFile> _filesByPath;
        private readonly Dictionary<string, KarMapBundle> _mapsByName;

        internal KarProjectIndex(IReadOnlyList<KarProjectFile> files, IReadOnlyList<KarMapBundle> maps)
        {
            Files = files ?? throw new ArgumentNullException(nameof(files));
            Maps = maps ?? throw new ArgumentNullException(nameof(maps));
            _filesByPath = Files.ToDictionary(file => file.RelativePath, StringComparer.OrdinalIgnoreCase);
            _mapsByName = Maps.ToDictionary(map => map.Name, StringComparer.OrdinalIgnoreCase);
        }

        public IReadOnlyList<KarProjectFile> Files { get; }

        public IReadOnlyList<KarMapBundle> Maps { get; }

        public IReadOnlyDictionary<string, KarProjectFile> FilesByPath => _filesByPath;

        public IReadOnlyDictionary<string, KarMapBundle> MapsByName => _mapsByName;

        public KarProjectFile GetFile(string relativePath)
        {
            KarProjectFile file;
            string normalized = KarProjectWorkspace.NormalizeRelativePath(relativePath);
            if (!_filesByPath.TryGetValue(normalized, out file))
                throw new FileNotFoundException("Project file was not found.", normalized);

            return file;
        }

        public bool TryGetFile(string relativePath, out KarProjectFile file)
        {
            string normalized = KarProjectWorkspace.NormalizeRelativePath(relativePath);
            return _filesByPath.TryGetValue(normalized, out file);
        }

        public IReadOnlyList<KarProjectFile> QueryFiles(KarProjectFileQueryOptions options)
        {
            if (options == null)
                return Files;

            return Files
                .Where(options.Matches)
                .ToList()
                .AsReadOnly();
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
    }
}
