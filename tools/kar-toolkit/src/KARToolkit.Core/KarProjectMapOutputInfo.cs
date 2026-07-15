using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectMapOutputInfo
    {
        private readonly Dictionary<string, KarProjectOutputFileInfo> _outputsByRelativePath;

        internal KarProjectMapOutputInfo(KarMapBundle map, IEnumerable<KarProjectOutputFileInfo> outputFiles)
        {
            Map = map ?? throw new ArgumentNullException(nameof(map));
            OutputFiles = (outputFiles ?? throw new ArgumentNullException(nameof(outputFiles)))
                .OrderBy(file => file.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
            _outputsByRelativePath = OutputFiles.ToDictionary(file => file.RelativePath, StringComparer.OrdinalIgnoreCase);
        }

        public KarMapBundle Map { get; }

        public string Name => Map.Name;

        public KarProjectFile DataFile => Map.DataFile;

        public KarProjectFile ModelFile => Map.ModelFile;

        public KarProjectFile EventFile => Map.EventFile;

        public KarProjectFile ScriptFile => Map.ScriptFile;

        public IReadOnlyList<KarProjectOutputFileInfo> OutputFiles { get; }

        public KarProjectOutputFileInfo DataOutput => GetOutput(DataFile);

        public KarProjectOutputFileInfo ModelOutput => GetOutput(ModelFile);

        public KarProjectOutputFileInfo EventOutput => GetOutput(EventFile);

        public KarProjectOutputFileInfo ScriptOutput => GetOutput(ScriptFile);

        public int ExpectedOutputFileCount => Map.Files.Count;

        public int OutputFileCount => OutputFiles.Count;

        public int ModifiedOutputFileCount => OutputFiles.Count(file => file.Status == KarProjectOutputFileStatus.DiffersFromSource);

        public int UnchangedOutputFileCount => OutputFiles.Count(file => file.Status == KarProjectOutputFileStatus.MatchesSource);

        public int MissingSourceOutputFileCount => OutputFiles.Count(file => file.Status == KarProjectOutputFileStatus.SourceMissing);

        public int MissingOutputFileCount => ExpectedOutputFileCount - OutputFileCount;

        public bool HasOutput => OutputFileCount != 0;

        public bool HasModifiedOutput => ModifiedOutputFileCount != 0;

        public bool HasCompleteOutputSet => ExpectedOutputFileCount != 0 && MissingOutputFileCount == 0;

        public bool HasDataOutput => DataOutput != null;

        public bool HasModelOutput => ModelOutput != null;

        public bool HasEventOutput => EventOutput != null;

        public bool HasScriptOutput => ScriptOutput != null;

        internal static IReadOnlyList<KarProjectMapOutputInfo> BuildMany(
            IEnumerable<KarMapBundle> maps,
            IEnumerable<KarProjectOutputFileInfo> outputFiles,
            KarProjectMapOutputQueryOptions options)
        {
            if (maps == null)
                throw new ArgumentNullException(nameof(maps));
            if (outputFiles == null)
                throw new ArgumentNullException(nameof(outputFiles));

            Dictionary<string, KarProjectOutputFileInfo> outputsByPath = outputFiles
                .Where(file => file.IsProjectFile)
                .ToDictionary(file => file.RelativePath, StringComparer.OrdinalIgnoreCase);
            List<KarProjectMapOutputInfo> mapOutputs = new List<KarProjectMapOutputInfo>();

            foreach (KarMapBundle map in maps)
            {
                List<KarProjectOutputFileInfo> outputs = new List<KarProjectOutputFileInfo>();

                foreach (KarProjectFile file in map.Files)
                {
                    KarProjectOutputFileInfo output;
                    if (outputsByPath.TryGetValue(file.RelativePath, out output))
                        outputs.Add(output);
                }

                KarProjectMapOutputInfo mapOutput = new KarProjectMapOutputInfo(map, outputs);
                if (options == null || options.Matches(mapOutput))
                    mapOutputs.Add(mapOutput);
            }

            return mapOutputs
                .OrderBy(map => map.Name, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        private KarProjectOutputFileInfo GetOutput(KarProjectFile file)
        {
            if (file == null)
                return null;

            KarProjectOutputFileInfo output;
            return _outputsByRelativePath.TryGetValue(file.RelativePath, out output) ? output : null;
        }
    }
}
