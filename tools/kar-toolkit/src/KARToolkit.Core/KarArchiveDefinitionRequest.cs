using System;
using System.IO;

namespace KARToolkit.Core
{
    public sealed class KarArchiveDefinitionRequest
    {
        public KarArchiveDefinitionRequest(string relativePath, KarFileKind kind, string mapName)
        {
            if (string.IsNullOrWhiteSpace(relativePath))
                throw new ArgumentException("Archive definition relative path cannot be empty.", nameof(relativePath));

            RelativePath = relativePath;
            Kind = kind;
            MapName = mapName;
            FileName = Path.GetFileName(relativePath);
            Name = Path.GetFileNameWithoutExtension(FileName);
        }

        public string RelativePath { get; }

        public string FileName { get; }

        public string Name { get; }

        public KarFileKind Kind { get; }

        public string MapName { get; }

        public bool HasMapName => !string.IsNullOrEmpty(MapName);
    }
}
