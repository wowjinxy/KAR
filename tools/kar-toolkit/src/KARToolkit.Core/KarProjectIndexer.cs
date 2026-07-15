using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectIndexer
    {
        public static KarProjectIndexer Default { get; } = new KarProjectIndexer();

        public KarProjectIndex Build(KarProjectWorkspace workspace)
        {
            if (workspace == null)
                throw new ArgumentNullException(nameof(workspace));

            IReadOnlyList<KarProjectFile> files = BuildFileIndex(workspace);
            IReadOnlyList<KarMapBundle> maps = BuildMapIndex(files);
            return new KarProjectIndex(files, maps);
        }

        private static IReadOnlyList<KarProjectFile> BuildFileIndex(KarProjectWorkspace workspace)
        {
            return Directory
                .EnumerateFiles(workspace.SourceFilesRoot, "*", SearchOption.AllDirectories)
                .Select(path =>
                {
                    string relativePath = workspace.GetRelativeSourcePath(path);
                    return new KarProjectFile(
                        relativePath,
                        path,
                        workspace.GetOutputPath(relativePath),
                        KarProjectFileClassifier.ClassifyKind(relativePath));
                })
                .OrderBy(file => file.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        private static IReadOnlyList<KarMapBundle> BuildMapIndex(IReadOnlyList<KarProjectFile> files)
        {
            Dictionary<string, MapBundleBuilder> builders = new Dictionary<string, MapBundleBuilder>(StringComparer.OrdinalIgnoreCase);

            foreach (KarProjectFile file in files)
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
            return KarProjectFileClassifier.TryGetMapName(file.RelativePath, file.Kind, out mapName);
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
