using KARToolkit.Core.AirRide;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectA2DService
    {
        private readonly KarProject _project;

        internal KarProjectA2DService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public IReadOnlyList<KarProjectA2DEntryInfo> QueryEntries(KarProjectA2DEntryQueryOptions options = null)
        {
            IEnumerable<KarProjectFile> packageFiles = _project.FileService.Query(options == null ? null : options.Packages)
                .Where(file => file.IsA2DPackage);

            List<KarProjectA2DEntryInfo> entries = new List<KarProjectA2DEntryInfo>();
            foreach (KarProjectFile file in packageFiles)
            {
                KarProjectA2DPackage package;
                string error;
                if (!_project.ArchiveService.TryOpenProjectA2DPackage(file.RelativePath, out package, out error))
                    continue;

                foreach (A2DPackageEntry entry in package.Package.Entries)
                    entries.Add(new KarProjectA2DEntryInfo(package.File, entry));
            }

            IEnumerable<KarProjectA2DEntryInfo> query = entries;
            if (options != null)
                query = query.Where(options.Matches);

            return query
                .OrderBy(entry => entry.PackageRelativePath, StringComparer.OrdinalIgnoreCase)
                .ThenBy(entry => entry.Index)
                .ToList()
                .AsReadOnly();
        }

        public IReadOnlyList<KarProjectA2DEntryInfo> QueryScriptTableEntries(KarProjectA2DEntryQueryOptions options = null)
        {
            KarProjectA2DEntryQueryOptions query = new KarProjectA2DEntryQueryOptions
            {
                Packages = options == null ? null : options.Packages,
                PackagePath = options == null ? null : options.PackagePath,
                EntryName = options == null ? null : options.EntryName,
                Kind = options == null ? null : options.Kind,
                Role = options == null ? null : options.Role,
                Category = options == null ? null : options.Category,
                IsScriptTable = true,
            };

            return QueryEntries(query);
        }

        public IReadOnlyList<KarProjectA2DEntryOutputInfo> QueryEntryOutputs(KarProjectA2DEntryOutputQueryOptions options = null)
        {
            IEnumerable<KarProjectA2DEntryOutputInfo> query = QueryEntries(options == null ? null : options.Entries)
                .Select(CreateEntryOutputInfo);

            if (options != null)
                query = query.Where(options.Matches);

            return query
                .OrderBy(output => output.PackageRelativePath, StringComparer.OrdinalIgnoreCase)
                .ThenBy(output => output.Entry.Index)
                .ToList()
                .AsReadOnly();
        }

        public KarProjectA2DEntryOutputInfo GetEntryOutput(string packageEntryPath)
        {
            return CreateEntryOutputInfo(GetEntry(packageEntryPath));
        }

        public KarProjectA2DEntryInfo GetEntry(string packageEntryPath)
        {
            ParsedEntryPath path = ParseEntryPath(packageEntryPath);
            return GetEntry(path.PackageRelativePath, path.EntryNameOrIndex);
        }

        public KarProjectA2DEntryInfo GetEntry(string packageRelativePath, string entryNameOrIndex)
        {
            KarProjectA2DPackage package = _project.ArchiveService.OpenProjectA2DPackage(packageRelativePath);
            A2DPackageEntry entry = ResolveEntry(package.Package, entryNameOrIndex);
            return new KarProjectA2DEntryInfo(package.File, entry);
        }

        public byte[] ReadEntryData(string packageEntryPath)
        {
            ParsedEntryPath path = ParseEntryPath(packageEntryPath);
            return ReadEntryData(path.PackageRelativePath, path.EntryNameOrIndex);
        }

        public byte[] ReadEntryData(string packageRelativePath, string entryNameOrIndex)
        {
            KarProjectA2DPackage package = _project.ArchiveService.OpenProjectA2DPackage(packageRelativePath);
            A2DPackageEntry entry = ResolveEntry(package.Package, entryNameOrIndex);
            return package.Package.GetEntryData(entry.Index);
        }

        public KarProjectA2DEntryExtractResult ExtractEntryToOutput(string packageEntryPath, bool overwrite = false)
        {
            ParsedEntryPath path = ParseEntryPath(packageEntryPath);
            return ExtractEntryToOutput(path.PackageRelativePath, path.EntryNameOrIndex, overwrite);
        }

        public KarProjectA2DEntryExtractResult ExtractEntryToOutput(string packageRelativePath, string entryNameOrIndex, bool overwrite = false)
        {
            KarProjectA2DPackage package = _project.ArchiveService.OpenProjectA2DPackage(packageRelativePath);
            A2DPackageEntry entry = ResolveEntry(package.Package, entryNameOrIndex);
            KarProjectA2DEntryInfo info = new KarProjectA2DEntryInfo(package.File, entry);
            string outputRelativePath = GetEntryOutputRelativePath(info);
            string outputPath = _project.Workspace.GetOutputAssetPath(outputRelativePath);
            bool wroteOutput = false;

            if (overwrite || !File.Exists(outputPath))
            {
                byte[] data = package.Package.GetEntryData(entry.Index);
                _project.Workspace.SaveOutputAsset(outputRelativePath, tempPath => File.WriteAllBytes(tempPath, data));
                wroteOutput = true;
            }

            return new KarProjectA2DEntryExtractResult(info, outputRelativePath, outputPath, wroteOutput);
        }

        public KarProjectA2DEntryReplaceResult ReplaceEntryFromFile(string packageEntryPath, string replacementPath)
        {
            if (string.IsNullOrWhiteSpace(replacementPath))
                throw new ArgumentException("Replacement path cannot be empty.", nameof(replacementPath));

            return ReplaceEntry(packageEntryPath, File.ReadAllBytes(replacementPath));
        }

        public KarProjectA2DEntryReplaceResult ReplaceEntryFromFile(string packageRelativePath, string entryNameOrIndex, string replacementPath)
        {
            if (string.IsNullOrWhiteSpace(replacementPath))
                throw new ArgumentException("Replacement path cannot be empty.", nameof(replacementPath));

            return ReplaceEntry(packageRelativePath, entryNameOrIndex, File.ReadAllBytes(replacementPath));
        }

        public KarProjectA2DEntryReplaceResult ReplaceEntry(string packageEntryPath, byte[] replacement)
        {
            ParsedEntryPath path = ParseEntryPath(packageEntryPath);
            return ReplaceEntry(path.PackageRelativePath, path.EntryNameOrIndex, replacement);
        }

        public KarProjectA2DEntryReplaceResult ReplaceEntry(string packageRelativePath, string entryNameOrIndex, byte[] replacement)
        {
            if (replacement == null)
                throw new ArgumentNullException(nameof(replacement));

            KarProjectA2DPackage package = _project.ArchiveService.OpenProjectA2DPackage(packageRelativePath);
            A2DPackageEntry entry = ResolveEntry(package.Package, entryNameOrIndex);
            KarProjectA2DEntryInfo info = new KarProjectA2DEntryInfo(package.File, entry);

            string error;
            if (!package.Package.ReplaceEntry(entry.Index, replacement, out error))
                throw new InvalidDataException(error);

            KarProjectFileWriteResult write = package.SaveToOutput();
            return new KarProjectA2DEntryReplaceResult(info, write, replacement.Length);
        }

        public KarProjectA2DEntryApplyResult ApplyEntryOutput(string packageEntryPath)
        {
            KarProjectA2DEntryOutputInfo output = GetEntryOutput(packageEntryPath);
            return ApplyEntryOutput(output);
        }

        public IReadOnlyList<KarProjectA2DEntryApplyResult> ApplyModifiedEntryOutputs(KarProjectA2DEntryOutputQueryOptions options = null)
        {
            KarProjectA2DEntryOutputQueryOptions query = new KarProjectA2DEntryOutputQueryOptions
            {
                Entries = options == null ? null : options.Entries,
                Status = KarProjectA2DEntryOutputStatus.DiffersFromEntry,
                HasOutput = true,
            };

            return QueryEntryOutputs(query)
                .Select(ApplyEntryOutput)
                .ToList()
                .AsReadOnly();
        }

        private KarProjectA2DEntryApplyResult ApplyEntryOutput(KarProjectA2DEntryOutputInfo output)
        {
            if (output == null)
                throw new ArgumentNullException(nameof(output));
            if (!output.HasOutput)
                throw new FileNotFoundException("A2D entry sidecar output was not found.", output.OutputPath);

            KarProjectA2DEntryReplaceResult replace = ReplaceEntryFromFile(
                output.PackageRelativePath,
                output.EntryName,
                output.OutputPath);
            return new KarProjectA2DEntryApplyResult(output, replace);
        }

        private static A2DPackageEntry ResolveEntry(A2DPackage package, string entryNameOrIndex)
        {
            if (package == null)
                throw new ArgumentNullException(nameof(package));
            if (string.IsNullOrWhiteSpace(entryNameOrIndex))
                throw new ArgumentException("A2D entry name or index cannot be empty.", nameof(entryNameOrIndex));

            string selector = entryNameOrIndex.Trim();
            int index;
            if (int.TryParse(selector, out index))
            {
                if (index < 0 || index >= package.Entries.Count)
                    throw new IndexOutOfRangeException("A2D entry index is outside the package entry table: " + index);

                return package.Entries[index];
            }

            A2DPackageEntry entry = package.Entries.FirstOrDefault(candidate =>
                string.Equals(candidate.Name, selector, StringComparison.OrdinalIgnoreCase));
            if (entry == null)
                throw new FileNotFoundException("A2D package entry was not found.", selector);

            return entry;
        }

        private static ParsedEntryPath ParseEntryPath(string packageEntryPath)
        {
            if (string.IsNullOrWhiteSpace(packageEntryPath))
                throw new ArgumentException("A2D entry path cannot be empty.", nameof(packageEntryPath));

            string value = packageEntryPath.Trim();
            int separator = value.IndexOf('#');
            if (separator <= 0 || separator == value.Length - 1 || value.IndexOf('#', separator + 1) >= 0)
                throw new ArgumentException("A2D entry paths must use '<package-relative-path>#<entry-name-or-index>'.", nameof(packageEntryPath));

            return new ParsedEntryPath(value.Substring(0, separator), value.Substring(separator + 1));
        }

        private KarProjectA2DEntryOutputInfo CreateEntryOutputInfo(KarProjectA2DEntryInfo entry)
        {
            string outputRelativePath = GetEntryOutputRelativePath(entry);
            string outputPath = _project.Workspace.GetOutputAssetPath(outputRelativePath);
            byte[] entryData = ReadEntryData(entry.PackageRelativePath, entry.Name);
            return new KarProjectA2DEntryOutputInfo(entry, outputRelativePath, outputPath, entryData);
        }

        private static string GetEntryOutputRelativePath(KarProjectA2DEntryInfo entry)
        {
            string packagePath = KarProjectWorkspace.NormalizeRelativePath(entry.PackageRelativePath);
            string entryPath = KarProjectWorkspace.NormalizeRelativePath(entry.Name);
            return KarProjectWorkspace.NormalizeRelativePath("a2d-entries/" + packagePath + "/" + entryPath);
        }

        private readonly struct ParsedEntryPath
        {
            public ParsedEntryPath(string packageRelativePath, string entryNameOrIndex)
            {
                PackageRelativePath = packageRelativePath;
                EntryNameOrIndex = entryNameOrIndex;
            }

            public string PackageRelativePath { get; }

            public string EntryNameOrIndex { get; }
        }
    }
}
