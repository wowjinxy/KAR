using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarArchiveDefinition
    {
        internal KarArchiveDefinition(
            KarFileKind kind,
            string displayName,
            string category,
            string description,
            IEnumerable<KarRootDefinition> roots)
        {
            Kind = kind;
            DisplayName = displayName;
            Category = category;
            Description = description;
            Roots = roots.ToList().AsReadOnly();
        }

        public KarFileKind Kind { get; }

        public string DisplayName { get; }

        public string Category { get; }

        public string Description { get; }

        public IReadOnlyList<KarRootDefinition> Roots { get; }

        public KarRootDefinition FindRoot(string rootName)
        {
            return Roots.FirstOrDefault(root => root.Matches(rootName));
        }
    }
}
