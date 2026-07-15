using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectVehicleService
    {
        private readonly KarProject _project;

        internal KarProjectVehicleService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public IReadOnlyList<KarVehicleBundle> Bundles => Query();

        public IReadOnlyDictionary<string, KarVehicleBundle> ByName => Query()
            .GroupBy(bundle => bundle.Name, StringComparer.OrdinalIgnoreCase)
            .ToDictionary(group => group.Key, group => group.First(), StringComparer.OrdinalIgnoreCase);

        public IReadOnlyList<KarVehicleBundle> Query(KarProjectVehicleQueryOptions options = null)
        {
            List<KarProjectFile> vehicleFiles = _project.FileService.Query(new KarProjectFileQueryOptions
            {
                Kind = KarFileKind.VehicleData,
            }).ToList();
            Dictionary<string, KarProjectFile> filesByName = vehicleFiles.ToDictionary(
                file => Path.GetFileNameWithoutExtension(file.RelativePath),
                StringComparer.OrdinalIgnoreCase);

            KarProjectFile commonFile = GetFileOrNull(filesByName, "VcCommon");
            KarProjectFile starKindTable = GetFileOrNull(filesByName, "VcStar");
            KarProjectFile wheelKindTable = GetFileOrNull(filesByName, "VcWheel");

            List<KarVehicleBundle> bundles = new List<KarVehicleBundle>();
            foreach (KarProjectFile file in vehicleFiles)
            {
                KarVehicleBundle bundle = CreateBundle(file, commonFile, starKindTable, wheelKindTable);
                if (options != null &&
                    !string.IsNullOrWhiteSpace(options.VehicleNameOrPath) &&
                    !MatchesSelector(bundle, options.VehicleNameOrPath))
                {
                    continue;
                }

                if (options == null || options.Matches(bundle))
                    bundles.Add(bundle);
            }

            return bundles
                .OrderBy(bundle => bundle.Family, StringComparer.OrdinalIgnoreCase)
                .ThenBy(bundle => bundle.Name, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public KarVehicleBundle Get(string vehicleNameOrPath)
        {
            KarVehicleBundle bundle;
            if (!TryGet(vehicleNameOrPath, out bundle))
                throw new KeyNotFoundException("KAR vehicle was not found: " + vehicleNameOrPath);

            return bundle;
        }

        public bool TryGet(string vehicleNameOrPath, out KarVehicleBundle bundle)
        {
            bundle = null;
            if (string.IsNullOrWhiteSpace(vehicleNameOrPath))
                return false;

            string normalizedPath = KarProjectWorkspace.NormalizeRelativePath(vehicleNameOrPath);

            foreach (KarVehicleBundle candidate in Query())
            {
                if (MatchesSelector(candidate, normalizedPath))
                {
                    bundle = candidate;
                    return true;
                }
            }

            return false;
        }

        public IReadOnlyList<KarProjectVehicleContext> QueryContexts(KarProjectVehicleQueryOptions options = null)
        {
            if (options != null && !string.IsNullOrWhiteSpace(options.VehicleNameOrPath))
                return new[] { GetContext(options.VehicleNameOrPath) }
                    .Where(context => options.Matches(context))
                    .ToList()
                    .AsReadOnly();

            Dictionary<string, KarProjectOutputFileInfo> outputsByPath = _project.OutputService.QueryFiles(new KarProjectOutputFileQueryOptions
            {
                IsProjectFile = true,
                Kind = KarFileKind.VehicleData,
            }).ToDictionary(output => output.RelativePath, StringComparer.OrdinalIgnoreCase);

            List<KarProjectVehicleContext> contexts = new List<KarProjectVehicleContext>();
            foreach (KarVehicleBundle bundle in Query(options))
            {
                KarProjectVehicleContext context = CreateContext(bundle, outputsByPath);
                if (options == null || options.Matches(context))
                    contexts.Add(context);
            }

            return contexts.AsReadOnly();
        }

        public KarProjectVehicleContext GetContext(string vehicleNameOrPath)
        {
            return CreateContext(Get(vehicleNameOrPath), null);
        }

        public IReadOnlyList<KarProjectFileCopyResult> CopyFilesToOutput(string vehicleNameOrPath, bool overwrite = false)
        {
            return CopyFilesToOutput(Get(vehicleNameOrPath), overwrite);
        }

        public IReadOnlyList<KarProjectFileCopyResult> CopyFilesToOutput(KarVehicleBundle bundle, bool overwrite = false)
        {
            if (bundle == null)
                throw new ArgumentNullException(nameof(bundle));

            return bundle.Files
                .Select(file => _project.FileService.CopyFileToOutput(file.RelativePath, overwrite))
                .ToList()
                .AsReadOnly();
        }

        private KarProjectVehicleContext CreateContext(
            KarVehicleBundle bundle,
            IReadOnlyDictionary<string, KarProjectOutputFileInfo> outputsByPath)
        {
            List<string> inspectionErrors = new List<string>();
            KarArchiveInfo dataArchive = InspectOrNull(bundle.DataFile, inspectionErrors);
            KarArchiveInfo commonArchive = ReferenceEquals(bundle.CommonFile, bundle.DataFile) ? dataArchive : InspectOrNull(bundle.CommonFile, inspectionErrors);
            KarArchiveInfo kindTableArchive = ReferenceEquals(bundle.KindTableFile, bundle.DataFile) ? dataArchive : InspectOrNull(bundle.KindTableFile, inspectionErrors);

            List<KarProjectResourceInfo> resources = new List<KarProjectResourceInfo>();
            foreach (KarProjectFile file in bundle.Files)
                resources.Add(_project.ResourceService.Get(file.RelativePath));

            List<KarProjectOutputFileInfo> outputFiles = new List<KarProjectOutputFileInfo>();
            foreach (KarProjectFile file in bundle.Files)
            {
                KarProjectOutputFileInfo output;
                if (outputsByPath != null)
                {
                    if (outputsByPath.TryGetValue(file.RelativePath, out output))
                        outputFiles.Add(output);
                }
                else if (_project.OutputService.TryGetFile(file.RelativePath, out output))
                {
                    outputFiles.Add(output);
                }
            }

            return new KarProjectVehicleContext(
                bundle,
                dataArchive,
                commonArchive,
                kindTableArchive,
                inspectionErrors.AsReadOnly(),
                resources.AsReadOnly(),
                outputFiles.AsReadOnly());
        }

        private KarArchiveInfo InspectOrNull(KarProjectFile file, List<string> errors)
        {
            if (file == null)
                return null;

            try
            {
                return _project.ArchiveService.InspectHsdArchive(file.RelativePath);
            }
            catch (Exception ex)
            {
                errors.Add(file.RelativePath + ": " + ex.Message);
                return null;
            }
        }

        private static KarVehicleBundle CreateBundle(
            KarProjectFile file,
            KarProjectFile commonFile,
            KarProjectFile starKindTable,
            KarProjectFile wheelKindTable)
        {
            string archiveName = Path.GetFileNameWithoutExtension(file.RelativePath);
            if (archiveName.Equals("VcCommon", StringComparison.OrdinalIgnoreCase))
                return new KarVehicleBundle("Common", "Common", "Common", file, file, null);
            if (archiveName.Equals("VcStar", StringComparison.OrdinalIgnoreCase))
                return new KarVehicleBundle("Star", "Star", "KindTable", file, commonFile, file);
            if (archiveName.Equals("VcWheel", StringComparison.OrdinalIgnoreCase))
                return new KarVehicleBundle("Wheel", "Wheel", "KindTable", file, commonFile, file);
            if (archiveName.StartsWith("VcStar", StringComparison.OrdinalIgnoreCase))
                return new KarVehicleBundle(StripPrefix(archiveName, "VcStar"), "Star", "Machine", file, commonFile, starKindTable);
            if (archiveName.StartsWith("VcWheel", StringComparison.OrdinalIgnoreCase))
                return new KarVehicleBundle(StripPrefix(archiveName, "Vc"), "Wheel", "Machine", file, commonFile, wheelKindTable);
            if (archiveName.StartsWith("VcWing", StringComparison.OrdinalIgnoreCase))
                return new KarVehicleBundle(StripPrefix(archiveName, "Vc"), "Wing", "Machine", file, commonFile, null);

            return new KarVehicleBundle(StripPrefix(archiveName, "Vc"), "Other", "Data", file, commonFile, null);
        }

        private static bool MatchesSelector(KarVehicleBundle bundle, string selector)
        {
            string normalizedPath = KarProjectWorkspace.NormalizeRelativePath(selector);
            string normalizedName = Path.GetFileNameWithoutExtension(normalizedPath);

            return string.Equals(bundle.Name, selector, StringComparison.OrdinalIgnoreCase) ||
                string.Equals(bundle.DataFile.RelativePath, normalizedPath, StringComparison.OrdinalIgnoreCase) ||
                string.Equals(Path.GetFileNameWithoutExtension(bundle.DataFile.RelativePath), normalizedName, StringComparison.OrdinalIgnoreCase);
        }

        private static KarProjectFile GetFileOrNull(IReadOnlyDictionary<string, KarProjectFile> filesByName, string name)
        {
            KarProjectFile file;
            return filesByName.TryGetValue(name, out file) ? file : null;
        }

        private static string StripPrefix(string value, string prefix)
        {
            return value.StartsWith(prefix, StringComparison.OrdinalIgnoreCase)
                ? value.Substring(prefix.Length)
                : value;
        }
    }
}
