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
            KarProjectRootInfo first = Roots.FirstOrDefault();
            DisplayName = first == null ? rootName : first.DisplayName;
            Role = first == null ? displayAccessorTypeName : first.Role;
            Category = first == null ? null : first.Category;
            Description = first == null ? null : first.Description;
        }

        public string RootName { get; }

        public bool IsKnown { get; }

        public string DisplayAccessorTypeName { get; }

        public string DataDefinitionId { get; }

        public string DisplayName { get; }

        public string Role { get; }

        public string Category { get; }

        public string Description { get; }

        public IReadOnlyList<KarProjectRootInfo> Roots { get; }

        public int Count => Roots.Count;
    }
}
