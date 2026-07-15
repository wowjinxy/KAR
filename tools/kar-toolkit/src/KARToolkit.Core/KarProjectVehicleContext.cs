using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectVehicleContext
    {
        private readonly Dictionary<string, KarProjectOutputFileInfo> _outputsByRelativePath;

        internal KarProjectVehicleContext(
            KarVehicleBundle bundle,
            KarArchiveInfo dataArchive,
            KarArchiveInfo commonArchive,
            KarArchiveInfo kindTableArchive,
            IReadOnlyList<string> inspectionErrors,
            IReadOnlyList<KarProjectResourceInfo> resources,
            IReadOnlyList<KarProjectOutputFileInfo> outputFiles)
        {
            Bundle = bundle ?? throw new ArgumentNullException(nameof(bundle));
            DataArchive = dataArchive;
            CommonArchive = commonArchive;
            KindTableArchive = kindTableArchive;
            InspectionErrors = inspectionErrors ?? throw new ArgumentNullException(nameof(inspectionErrors));
            Resources = resources ?? throw new ArgumentNullException(nameof(resources));
            OutputFiles = outputFiles ?? throw new ArgumentNullException(nameof(outputFiles));
            _outputsByRelativePath = OutputFiles.ToDictionary(file => file.RelativePath, StringComparer.OrdinalIgnoreCase);

            List<KarArchiveInfo> archives = new List<KarArchiveInfo>();
            AddUnique(archives, DataArchive);
            AddUnique(archives, CommonArchive);
            AddUnique(archives, KindTableArchive);
            Archives = archives.AsReadOnly();

            MissingRequiredRoots = Archives
                .SelectMany(archive => archive.MissingRequiredRoots)
                .ToList()
                .AsReadOnly();
        }

        public KarVehicleBundle Bundle { get; }

        public string Name => Bundle.Name;

        public string Family => Bundle.Family;

        public string Role => Bundle.Role;

        public KarProjectFile DataFile => Bundle.DataFile;

        public KarProjectFile CommonFile => Bundle.CommonFile;

        public KarProjectFile KindTableFile => Bundle.KindTableFile;

        public IReadOnlyList<KarProjectFile> Files => Bundle.Files;

        public IReadOnlyList<KarProjectFile> SharedFiles => Bundle.SharedFiles;

        public KarArchiveInfo DataArchive { get; }

        public KarArchiveInfo CommonArchive { get; }

        public KarArchiveInfo KindTableArchive { get; }

        public IReadOnlyList<KarArchiveInfo> Archives { get; }

        public IReadOnlyList<KarRootDefinition> MissingRequiredRoots { get; }

        public IReadOnlyList<string> InspectionErrors { get; }

        public IReadOnlyList<KarProjectResourceInfo> Resources { get; }

        public IReadOnlyList<KarProjectOutputFileInfo> OutputFiles { get; }

        public KarProjectOutputFileInfo DataOutput => GetOutput(DataFile);

        public KarProjectOutputFileInfo CommonOutput => GetOutput(CommonFile);

        public KarProjectOutputFileInfo KindTableOutput => GetOutput(KindTableFile);

        public int FileCount => Files.Count;

        public int SharedFileCount => SharedFiles.Count;

        public int ArchiveCount => Archives.Count;

        public int ResourceCount => Resources.Count;

        public int RootCount => Archives.Sum(archive => archive.Roots.Count);

        public int KnownRootCount => Archives.Sum(archive => archive.KnownRoots.Count);

        public int UnknownRootCount => Archives.Sum(archive => archive.UnknownRoots.Count);

        public int MissingRequiredRootCount => MissingRequiredRoots.Count;

        public int InspectionErrorCount => InspectionErrors.Count;

        public int ExpectedOutputFileCount => Files.Count;

        public int OutputFileCount => OutputFiles.Count;

        public int ModifiedOutputFileCount => OutputFiles.Count(file => file.Status == KarProjectOutputFileStatus.DiffersFromSource);

        public int MissingOutputFileCount => ExpectedOutputFileCount - OutputFileCount;

        public bool HasSharedFiles => SharedFiles.Count != 0;

        public bool HasInspectionErrors => InspectionErrors.Count != 0;

        public bool HasMissingRequiredRoots => MissingRequiredRoots.Count != 0;

        public bool HasOutput => OutputFiles.Count != 0;

        public bool HasModifiedOutput => ModifiedOutputFileCount != 0;

        public bool HasCompleteOutputSet => ExpectedOutputFileCount != 0 && MissingOutputFileCount == 0;

        private KarProjectOutputFileInfo GetOutput(KarProjectFile file)
        {
            if (file == null)
                return null;

            KarProjectOutputFileInfo output;
            return _outputsByRelativePath.TryGetValue(file.RelativePath, out output) ? output : null;
        }

        public KarProjectVehicleContextSummaryContract CreateContract()
        {
            return KarProjectVehicleContextSummaryContract.Create(this);
        }

        private static void AddUnique(List<KarArchiveInfo> archives, KarArchiveInfo archive)
        {
            if (archive == null)
                return;

            foreach (KarArchiveInfo existing in archives)
            {
                if (string.Equals(existing.File.RelativePath, archive.File.RelativePath, StringComparison.OrdinalIgnoreCase))
                    return;
            }

            archives.Add(archive);
        }
    }
}
