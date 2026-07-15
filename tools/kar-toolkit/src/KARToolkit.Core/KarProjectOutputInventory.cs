using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectOutputInventory
    {
        internal KarProjectOutputInventory(KarProject project, IEnumerable<KarProjectOutputFileInfo> files)
        {
            Project = project ?? throw new ArgumentNullException(nameof(project));
            Files = (files ?? throw new ArgumentNullException(nameof(files)))
                .OrderBy(file => file.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
            ProjectFiles = Files
                .Where(file => file.IsProjectFile)
                .ToList()
                .AsReadOnly();
            OrphanFiles = Files
                .Where(file => file.IsOrphan)
                .ToList()
                .AsReadOnly();
            ModifiedProjectFiles = Files
                .Where(file => file.Status == KarProjectOutputFileStatus.DiffersFromSource)
                .ToList()
                .AsReadOnly();
            UnchangedProjectFiles = Files
                .Where(file => file.Status == KarProjectOutputFileStatus.MatchesSource)
                .ToList()
                .AsReadOnly();
            MissingSourceFiles = Files
                .Where(file => file.Status == KarProjectOutputFileStatus.SourceMissing)
                .ToList()
                .AsReadOnly();
        }

        public KarProject Project { get; }

        public IReadOnlyList<KarProjectOutputFileInfo> Files { get; }

        public IReadOnlyList<KarProjectOutputFileInfo> ProjectFiles { get; }

        public IReadOnlyList<KarProjectOutputFileInfo> OrphanFiles { get; }

        public IReadOnlyList<KarProjectOutputFileInfo> ModifiedProjectFiles { get; }

        public IReadOnlyList<KarProjectOutputFileInfo> UnchangedProjectFiles { get; }

        public IReadOnlyList<KarProjectOutputFileInfo> MissingSourceFiles { get; }

        public int Count => Files.Count;

        public int ProjectFileCount => ProjectFiles.Count;

        public int OrphanFileCount => OrphanFiles.Count;

        public int ModifiedProjectFileCount => ModifiedProjectFiles.Count;

        public int UnchangedProjectFileCount => UnchangedProjectFiles.Count;

        public int MissingSourceFileCount => MissingSourceFiles.Count;

        public long TotalOutputLength => Files.Sum(file => file.OutputLength);
    }
}
