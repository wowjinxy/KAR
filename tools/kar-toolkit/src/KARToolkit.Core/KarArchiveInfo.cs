using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarArchiveInfo
    {
        internal KarArchiveInfo(
            KarProjectFile file,
            KarArchiveDefinition definition,
            IEnumerable<KarArchiveRootInfo> roots)
        {
            File = file;
            Definition = definition;
            Roots = roots.ToList().AsReadOnly();
            MissingRequiredRoots = definition.Roots
                .Where(expected => expected.IsRequired)
                .Where(expected => !Roots.Any(actual => expected.Matches(actual.Name)))
                .ToList()
                .AsReadOnly();
            KnownRoots = Roots
                .Where(root => root.IsKnown)
                .ToList()
                .AsReadOnly();
            UnknownRoots = Roots
                .Where(root => !root.IsKnown)
                .ToList()
                .AsReadOnly();
        }

        public KarProjectFile File { get; }

        public KarArchiveDefinition Definition { get; }

        public IReadOnlyList<KarArchiveRootInfo> Roots { get; }

        public IReadOnlyList<KarArchiveRootInfo> KnownRoots { get; }

        public IReadOnlyList<KarArchiveRootInfo> UnknownRoots { get; }

        public IReadOnlyList<KarRootDefinition> MissingRequiredRoots { get; }

        public bool HasMissingRequiredRoots => MissingRequiredRoots.Count != 0;
    }
}
