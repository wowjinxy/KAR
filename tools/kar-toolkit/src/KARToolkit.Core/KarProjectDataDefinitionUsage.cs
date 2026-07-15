using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectDataDefinitionUsage
    {
        internal KarProjectDataDefinitionUsage(
            KarDataDefinition dataDefinition,
            IEnumerable<KarProjectRootInfo> roots)
        {
            DataDefinition = dataDefinition ?? throw new ArgumentNullException(nameof(dataDefinition));
            Roots = (roots ?? throw new ArgumentNullException(nameof(roots)))
                .ToList()
                .AsReadOnly();
            Files = Roots
                .Select(root => root.File)
                .GroupBy(file => file.RelativePath, StringComparer.OrdinalIgnoreCase)
                .Select(group => group.First())
                .OrderBy(file => file.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public KarDataDefinition DataDefinition { get; }

        public string DataDefinitionId => DataDefinition.Id;

        public string DisplayName => DataDefinition.DisplayName;

        public string Category => DataDefinition.Category;

        public string AccessorTypeName => DataDefinition.AccessorTypeName;

        public IReadOnlyList<KarProjectRootInfo> Roots { get; }

        public IReadOnlyList<KarProjectFile> Files { get; }

        public int Count => Roots.Count;

        public int FileCount => Files.Count;
    }
}
