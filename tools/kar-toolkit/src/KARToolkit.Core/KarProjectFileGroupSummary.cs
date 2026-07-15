using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectFileGroupSummary
    {
        internal KarProjectFileGroupSummary(string name, IEnumerable<KarProjectFile> files)
        {
            Name = string.IsNullOrWhiteSpace(name) ? "<unknown>" : name;
            Files = (files ?? throw new ArgumentNullException(nameof(files)))
                .OrderBy(file => file.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public string Name { get; }

        public IReadOnlyList<KarProjectFile> Files { get; }

        public int Count => Files.Count;
    }
}
