using System;
using System.Collections.Generic;

namespace KARToolkit.Core
{
    public sealed class KarVehicleBundle
    {
        internal KarVehicleBundle(
            string name,
            string family,
            string role,
            KarProjectFile dataFile,
            KarProjectFile commonFile,
            KarProjectFile kindTableFile)
        {
            Name = string.IsNullOrWhiteSpace(name) ? throw new ArgumentException("Vehicle name is required.", nameof(name)) : name;
            Family = string.IsNullOrWhiteSpace(family) ? "Other" : family;
            Role = string.IsNullOrWhiteSpace(role) ? "Data" : role;
            DataFile = dataFile ?? throw new ArgumentNullException(nameof(dataFile));
            CommonFile = commonFile;
            KindTableFile = kindTableFile;

            List<KarProjectFile> files = new List<KarProjectFile>();
            AddUnique(files, DataFile);
            AddUnique(files, CommonFile);
            AddUnique(files, KindTableFile);
            Files = files.AsReadOnly();

            List<KarProjectFile> sharedFiles = new List<KarProjectFile>();
            if (!ReferenceEquals(CommonFile, DataFile))
                AddUnique(sharedFiles, CommonFile);
            if (!ReferenceEquals(KindTableFile, DataFile))
                AddUnique(sharedFiles, KindTableFile);
            SharedFiles = sharedFiles.AsReadOnly();
        }

        public string Name { get; }

        public string Family { get; }

        public string Role { get; }

        public KarProjectFile DataFile { get; }

        public KarProjectFile CommonFile { get; }

        public KarProjectFile KindTableFile { get; }

        public IReadOnlyList<KarProjectFile> Files { get; }

        public IReadOnlyList<KarProjectFile> SharedFiles { get; }

        public int FileCount => Files.Count;

        public int SharedFileCount => SharedFiles.Count;

        public bool HasCommonFile => CommonFile != null;

        public bool HasKindTableFile => KindTableFile != null;

        public bool HasSharedFiles => SharedFiles.Count != 0;

        public bool IsCommonData => string.Equals(Role, "Common", StringComparison.OrdinalIgnoreCase);

        public bool IsKindTable => string.Equals(Role, "KindTable", StringComparison.OrdinalIgnoreCase);

        public bool IsMachineData => string.Equals(Role, "Machine", StringComparison.OrdinalIgnoreCase);

        private static void AddUnique(List<KarProjectFile> files, KarProjectFile file)
        {
            if (file == null)
                return;

            foreach (KarProjectFile existing in files)
            {
                if (string.Equals(existing.RelativePath, file.RelativePath, StringComparison.OrdinalIgnoreCase))
                    return;
            }

            files.Add(file);
        }
    }
}
