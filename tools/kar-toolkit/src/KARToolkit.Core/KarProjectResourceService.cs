using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceService
    {
        private readonly KarProject _project;

        internal KarProjectResourceService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public IReadOnlyList<KarProjectResourceInfo> Query(KarProjectResourceQueryOptions options = null)
        {
            if (options != null && !string.IsNullOrWhiteSpace(options.Address))
            {
                KarProjectResourceInfo resource;
                if (!TryGet(options.Address, out resource) || !options.Matches(resource))
                    return Array.Empty<KarProjectResourceInfo>();

                return new[] { resource };
            }

            List<KarProjectResourceInfo> resources = new List<KarProjectResourceInfo>();

            if (options == null || !options.Kind.HasValue || options.Kind.Value == KarResourceKind.File)
            {
                foreach (KarProjectFile file in _project.FileService.Query(options == null ? null : options.Files))
                    resources.Add(KarProjectResourceInfo.FromFile(file));
            }

            if (options == null || !options.Kind.HasValue || options.Kind.Value == KarResourceKind.HsdRoot)
            {
                foreach (KarProjectRootInfo root in _project.DataService.QueryRoots(options == null ? null : options.Roots))
                    resources.Add(KarProjectResourceInfo.FromRoot(root));
            }

            if (options == null || !options.Kind.HasValue || options.Kind.Value == KarResourceKind.A2DEntry)
            {
                foreach (KarProjectA2DEntryInfo entry in _project.A2DService.QueryEntries(options == null ? null : options.A2DEntries))
                    resources.Add(KarProjectResourceInfo.FromA2DEntry(entry));
            }

            IEnumerable<KarProjectResourceInfo> query = resources;
            if (options != null)
                query = query.Where(options.Matches);

            return query
                .OrderBy(resource => resource.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ThenBy(resource => resource.Kind)
                .ThenBy(resource => resource.Address, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public KarProjectResourceInfo Get(string address)
        {
            KarProjectResourceInfo resource;
            if (!TryGet(address, out resource))
                throw new KeyNotFoundException("KAR project resource was not found: " + address);

            return resource;
        }

        public bool TryGet(string address, out KarProjectResourceInfo resource)
        {
            resource = null;

            KarResourceReference reference;
            if (!KarResourceReference.TryParse(address, out reference))
                return false;

            try
            {
                resource = Resolve(reference);
                return resource != null;
            }
            catch (ArgumentException)
            {
                resource = null;
                return false;
            }
            catch (FileNotFoundException)
            {
                resource = null;
                return false;
            }
            catch (KeyNotFoundException)
            {
                resource = null;
                return false;
            }
            catch (IndexOutOfRangeException)
            {
                resource = null;
                return false;
            }
        }

        public byte[] ReadBytes(string address)
        {
            KarProjectResourceInfo resource = Get(address);
            switch (resource.Kind)
            {
                case KarResourceKind.File:
                    return _project.FileService.ReadBytes(resource.RelativePath);

                case KarResourceKind.A2DEntry:
                    return _project.A2DService.ReadEntryData(resource.RelativePath, resource.Reference.EntryName);

                case KarResourceKind.HsdRoot:
                    throw new NotSupportedException("HSD root resources do not have standalone byte ranges. Export the resource to stage its containing archive.");

                default:
                    throw new ArgumentOutOfRangeException(nameof(address));
            }
        }

        public KarProjectResourceExportResult ExportToOutput(string address, bool overwrite = false)
        {
            KarProjectResourceInfo resource = Get(address);
            switch (resource.Kind)
            {
                case KarResourceKind.File:
                case KarResourceKind.HsdRoot:
                    return ExportContainingFile(resource, overwrite);

                case KarResourceKind.A2DEntry:
                    KarProjectA2DEntryExtractResult extract = _project.A2DService.ExtractEntryToOutput(resource.Address, overwrite);
                    return new KarProjectResourceExportResult(
                        resource,
                        KarProjectResourceOutputKind.OutputAsset,
                        extract.OutputRelativePath,
                        extract.OutputPath,
                        extract.WroteOutput,
                        null,
                        extract);

                default:
                    throw new ArgumentOutOfRangeException(nameof(address));
            }
        }

        public KarProjectResourceImportResult ImportFromFile(string address, string inputPath)
        {
            if (string.IsNullOrWhiteSpace(inputPath))
                throw new ArgumentException("Input path cannot be empty.", nameof(inputPath));

            KarProjectResourceInfo resource = Get(address);
            switch (resource.Kind)
            {
                case KarResourceKind.File:
                    byte[] data = File.ReadAllBytes(inputPath);
                    KarProjectFileWriteResult write = _project.FileService.WriteFileBytes(resource.RelativePath, data);
                    return new KarProjectResourceImportResult(
                        resource,
                        inputPath,
                        KarProjectResourceOutputKind.ProjectFile,
                        write.RelativePath,
                        write.OutputPath,
                        data.Length,
                        write,
                        null);

                case KarResourceKind.A2DEntry:
                    KarProjectA2DEntryReplaceResult replace = _project.A2DService.ReplaceEntryFromFile(
                        resource.RelativePath,
                        resource.Reference.EntryName,
                        inputPath);
                    return new KarProjectResourceImportResult(
                        resource,
                        inputPath,
                        KarProjectResourceOutputKind.ProjectFile,
                        replace.PackageRelativePath,
                        replace.OutputPath,
                        replace.ReplacementLength,
                        replace.WriteResult,
                        replace);

                case KarResourceKind.HsdRoot:
                    throw new NotSupportedException("HSD root imports require structured archive editing. Import a whole file resource or use a typed edit command.");

                default:
                    throw new ArgumentOutOfRangeException(nameof(address));
            }
        }

        public KarProjectResourceScalarEditResult SetScalarFieldFromText(
            string rootAddress,
            string fieldName,
            string rawValue,
            bool bufferAlign = true,
            bool optimize = true,
            bool trim = false)
        {
            KarProjectResourceInfo resource = Get(rootAddress);
            if (resource.Kind != KarResourceKind.HsdRoot)
                throw new NotSupportedException("Scalar edits require an HSD root resource address.");

            KarProjectScalarEditResult edit = _project.EditService.SetScalarFieldFromText(
                resource.RelativePath,
                resource.Reference.RootName,
                fieldName,
                rawValue,
                byDataDefinition: false,
                bufferAlign: bufferAlign,
                optimize: optimize,
                trim: trim);
            return new KarProjectResourceScalarEditResult(resource, edit);
        }

        private KarProjectResourceInfo Resolve(KarResourceReference reference)
        {
            switch (reference.Kind)
            {
                case KarResourceKind.File:
                    KarProjectFile file;
                    return _project.FileService.TryGet(reference.RelativePath, out file)
                        ? KarProjectResourceInfo.FromFile(file)
                        : null;

                case KarResourceKind.HsdRoot:
                    KarArchiveInfo archive = _project.ArchiveService.InspectHsdArchive(reference.RelativePath);
                    KarArchiveRootInfo root;
                    return archive.TryGetRoot(reference.RootName, out root)
                        ? KarProjectResourceInfo.FromRoot(new KarProjectRootInfo(archive.File, root))
                        : null;

                case KarResourceKind.A2DEntry:
                    return KarProjectResourceInfo.FromA2DEntry(
                        _project.A2DService.GetEntry(reference.RelativePath, reference.EntryName));

                default:
                    throw new ArgumentOutOfRangeException(nameof(reference));
            }
        }

        private KarProjectResourceExportResult ExportContainingFile(KarProjectResourceInfo resource, bool overwrite)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));
            if (resource.File == null)
                throw new InvalidOperationException("Resource does not have a containing project file: " + resource.Address);

            bool wroteOutput = overwrite || !File.Exists(resource.File.OutputPath);
            KarProjectFileCopyResult copy = _project.FileService.CopyFileToOutput(resource.File.RelativePath, overwrite);
            return new KarProjectResourceExportResult(
                resource,
                KarProjectResourceOutputKind.ProjectFile,
                resource.File.RelativePath,
                copy.OutputPath,
                wroteOutput,
                copy,
                null);
        }
    }
}
