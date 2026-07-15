using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectRootSummary
    {
        internal KarProjectRootSummary(
            string rootName,
            bool isKnown,
            string displayAccessorTypeName,
            string dataDefinitionId,
            IEnumerable<KarProjectRootInfo> roots)
        {
            RootName = rootName;
            IsKnown = isKnown;
            DisplayAccessorTypeName = displayAccessorTypeName;
            DataDefinitionId = dataDefinitionId;
            Roots = (roots ?? throw new ArgumentNullException(nameof(roots)))
                .ToList()
                .AsReadOnly();
        }

        public string RootName { get; }

        public bool IsKnown { get; }

        public string DisplayAccessorTypeName { get; }

        public string DataDefinitionId { get; }

        public IReadOnlyList<KarProjectRootInfo> Roots { get; }

        public int Count => Roots.Count;
    }
}
