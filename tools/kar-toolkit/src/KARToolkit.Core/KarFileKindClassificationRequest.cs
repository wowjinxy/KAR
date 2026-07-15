using System;
using System.IO;

namespace KARToolkit.Core
{
    public sealed class KarFileKindClassificationRequest
    {
        public KarFileKindClassificationRequest(string relativePath)
        {
            if (relativePath == null)
                throw new ArgumentNullException(nameof(relativePath));

            RelativePath = relativePath;
            FileName = Path.GetFileName(relativePath);
            Name = Path.GetFileNameWithoutExtension(FileName);
            Extension = Path.GetExtension(FileName);
        }

        public string RelativePath { get; }

        public string FileName { get; }

        public string Name { get; }

        public string Extension { get; }

        public bool HasExtension(string extension)
        {
            return Extension.Equals(extension, StringComparison.OrdinalIgnoreCase);
        }

        public bool NameEquals(string name)
        {
            return Name.Equals(name, StringComparison.OrdinalIgnoreCase);
        }

        public bool FileNameEquals(string fileName)
        {
            return FileName.Equals(fileName, StringComparison.OrdinalIgnoreCase);
        }

        public bool NameStartsWith(string prefix)
        {
            return Name.StartsWith(prefix, StringComparison.OrdinalIgnoreCase);
        }

        public bool NameEndsWith(string suffix)
        {
            return Name.EndsWith(suffix, StringComparison.OrdinalIgnoreCase);
        }
    }
}
