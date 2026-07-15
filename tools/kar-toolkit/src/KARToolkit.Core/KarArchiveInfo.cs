using System;
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

        public KarArchiveRootInfo GetRoot(string name)
        {
            KarArchiveRootInfo root;
            if (!TryGetRoot(name, out root))
                throw new KeyNotFoundException("KAR archive root was not found: " + name);

            return root;
        }

        public bool TryGetRoot(string name, out KarArchiveRootInfo root)
        {
            root = null;
            if (string.IsNullOrWhiteSpace(name))
                return false;

            root = Roots.FirstOrDefault(candidate =>
                string.Equals(candidate.Name, name, StringComparison.Ordinal));
            return root != null;
        }

        public KarArchiveRootInfo GetRootByDataDefinition(string idOrAccessorTypeName)
        {
            KarArchiveRootInfo root;
            if (!TryGetRootByDataDefinition(idOrAccessorTypeName, out root))
                throw new KeyNotFoundException("KAR archive root data definition was not found: " + idOrAccessorTypeName);

            return root;
        }

        public bool TryGetRootByDataDefinition(string idOrAccessorTypeName, out KarArchiveRootInfo root)
        {
            root = GetRootsByDataDefinition(idOrAccessorTypeName).FirstOrDefault();
            return root != null;
        }

        public IReadOnlyList<KarArchiveRootInfo> GetRootsByDataDefinition(string idOrAccessorTypeName)
        {
            if (string.IsNullOrWhiteSpace(idOrAccessorTypeName))
                return Array.Empty<KarArchiveRootInfo>();

            return Roots
                .Where(root => root.MatchesDataDefinition(idOrAccessorTypeName))
                .ToList()
                .AsReadOnly();
        }
    }
}
