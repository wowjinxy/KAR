using System.Collections.Generic;

namespace KARToolkit.Core
{
    public sealed class KarMapBundle
    {
        internal KarMapBundle(string name, KarProjectFile dataFile, KarProjectFile modelFile, KarProjectFile eventFile)
        {
            Name = name;
            DataFile = dataFile;
            ModelFile = modelFile;
            EventFile = eventFile;

            var files = new List<KarProjectFile>();
            if (DataFile != null)
                files.Add(DataFile);
            if (ModelFile != null)
                files.Add(ModelFile);
            if (EventFile != null)
                files.Add(EventFile);
            Files = files.AsReadOnly();
        }

        public string Name { get; }

        public KarProjectFile DataFile { get; }

        public KarProjectFile ModelFile { get; }

        public KarProjectFile EventFile { get; }

        public KarProjectFile ScriptFile => EventFile;

        public IReadOnlyList<KarProjectFile> Files { get; }

        public bool HasDataFile => DataFile != null;

        public bool HasModelFile => ModelFile != null;

        public bool HasEventFile => EventFile != null;

        public bool HasScriptFile => ScriptFile != null;
    }
}
