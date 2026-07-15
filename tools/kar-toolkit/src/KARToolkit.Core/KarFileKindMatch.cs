using System;
using System.IO;

namespace KARToolkit.Core
{
    public sealed class KarFileKindMatch
    {
        internal KarFileKindMatch(string relativePath, KarFileKindDescriptor descriptor, string mapName)
        {
            RelativePath = relativePath ?? throw new ArgumentNullException(nameof(relativePath));
            Descriptor = descriptor ?? throw new ArgumentNullException(nameof(descriptor));
            FileName = Path.GetFileName(relativePath);
            NameWithoutExtension = Path.GetFileNameWithoutExtension(FileName);
            Extension = Path.GetExtension(FileName);
            MapName = string.IsNullOrWhiteSpace(mapName) ? null : mapName;
        }

        public string RelativePath { get; }

        public string FileName { get; }

        public string NameWithoutExtension { get; }

        public string Extension { get; }

        public KarFileKind Kind => Descriptor.Kind;

        public KarFileKindDescriptor Descriptor { get; }

        public string MapName { get; }

        public bool HasMapName => MapName != null;
    }
}
