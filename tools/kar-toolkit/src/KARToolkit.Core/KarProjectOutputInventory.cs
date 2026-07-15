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
        }

        public KarProject Project { get; }

        public IReadOnlyList<KarProjectOutputFileInfo> Files { get; }

        public IReadOnlyList<KarProjectOutputFileInfo> ProjectFiles { get; }

        public IReadOnlyList<KarProjectOutputFileInfo> OrphanFiles { get; }

        public int Count => Files.Count;

        public int ProjectFileCount => ProjectFiles.Count;

        public int OrphanFileCount => OrphanFiles.Count;

        public long TotalOutputLength => Files.Sum(file => file.OutputLength);
    }
}
