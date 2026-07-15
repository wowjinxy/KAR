using KARToolkit.Core.AirRide;
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
            return _project.CreateResourceGraph().QueryResources(options);
        }

        public KarProjectResourceInfo Get(string address)
        {
            KarProjectResourceInfo resource;
            if (!TryGet(address, out resource))
                throw new KeyNotFoundException("KAR project resource was not found: " + address);

            return resource;
        }

        public IReadOnlyList<KarProjectResourceOutputInfo> QueryOutputs(KarProjectResourceOutputQueryOptions options = null)
        {
            IEnumerable<KarProjectResourceOutputInfo> query = Query(options == null ? null : options.Resources)
                .Select(CreateOutputInfo);

            if (options != null)
                query = query.Where(options.Matches);

            return query
                .OrderBy(output => output.Resource.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ThenBy(output => output.Kind)
                .ThenBy(output => output.Address, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public KarProjectResourceOutputInfo GetOutput(string address)
        {
            return CreateOutputInfo(Get(address));
        }

        public IReadOnlyList<KarProjectResourceFieldInfo> QueryFieldValues(KarProjectResourceFieldQueryOptions options = null)
        {
            IEnumerable<KarProjectResourceInfo> resources = Query(options == null ? null : options.Resources)
                .Where(resource => resource.CanQueryFieldValues);
            List<KarProjectResourceFieldInfo> fields = new List<KarProjectResourceFieldInfo>();

            foreach (KarProjectResourceInfo resource in resources)
            {
                if (resource.Root.Root.DataDefinition == null || !resource.Root.Root.HasFieldValues)
                    continue;

                foreach (KarDataFieldValue value in resource.Root.Root.FieldValues)
                {
                    KarProjectFieldInfo fieldInfo = new KarProjectFieldInfo(resource.Root, value);
                    KarProjectResourceFieldInfo field = new KarProjectResourceFieldInfo(resource, fieldInfo);
                    if (options == null || options.Matches(field))
                        fields.Add(field);
                }
            }

            return fields
                .OrderBy(field => field.Address, StringComparer.OrdinalIgnoreCase)
                .ThenBy(field => field.Field.Offset ?? int.MaxValue)
                .ThenBy(field => field.FieldName, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public KarProjectResourceFieldInfo GetFieldValue(string rootAddress, string fieldName)
        {
            KarProjectResourceFieldInfo field = QueryFieldValues(new KarProjectResourceFieldQueryOptions
            {
                Resources = new KarProjectResourceQueryOptions
                {
                    Address = rootAddress,
                    Kind = KarResourceKind.HsdRoot,
                },
                FieldName = fieldName,
            }).FirstOrDefault();

            if (field == null)
                throw new KeyNotFoundException("KAR project resource field was not found: " + rootAddress + " " + fieldName);

            return field;
        }

        public bool TryGet(string address, out KarProjectResourceInfo resource)
        {
            resource = null;

            KarResourceReference reference;
            if (!KarResourceReference.TryParse(address, out reference))
                return false;

            try
            {
                return _project.CreateResourceGraph().TryGetResource(reference.Address, out resource);
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
            EnsureCapability(resource, KarProjectResourceCapability.ReadBytes);
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
            EnsureCapability(resource, KarProjectResourceCapability.ExportToOutput);
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
            EnsureCapability(resource, KarProjectResourceCapability.ImportFromFile);
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
            if (!resource.CanSetScalarFields)
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

        public KarProjectResourceOutputApplyResult ApplyOutput(string address)
        {
            KarProjectResourceOutputInfo output = GetOutput(address);
            return ApplyOutput(output);
        }

        public IReadOnlyList<KarProjectResourceOutputApplyResult> ApplyModifiedOutputs(KarProjectResourceOutputQueryOptions options = null)
        {
            KarProjectResourceOutputQueryOptions query = new KarProjectResourceOutputQueryOptions
            {
                Resources = options == null ? null : options.Resources,
                Status = KarProjectResourceOutputStatus.SidecarDiffersFromEntry,
                HasOutput = true,
            };

            return QueryOutputs(query)
                .Select(ApplyOutput)
                .ToList()
                .AsReadOnly();
        }

        private KarProjectResourceOutputApplyResult ApplyOutput(KarProjectResourceOutputInfo output)
        {
            if (output == null)
                throw new ArgumentNullException(nameof(output));
            EnsureCapability(output.Resource, KarProjectResourceCapability.ApplyOutput);
            if (output.Kind != KarResourceKind.A2DEntry || output.OutputKind != KarProjectResourceOutputKind.OutputAsset)
                throw new NotSupportedException("Only A2D entry sidecar output resources can be applied.");
            if (output.A2DEntryOutput == null || !output.A2DEntryOutput.HasOutput)
                throw new FileNotFoundException("A2D entry sidecar output was not found.", output.OutputPath);

            KarProjectA2DEntryApplyResult apply = _project.A2DService.ApplyEntryOutput(output.Address);
            return new KarProjectResourceOutputApplyResult(output, apply);
        }

        private KarProjectResourceOutputInfo CreateOutputInfo(KarProjectResourceInfo resource)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));
            EnsureCapability(resource, KarProjectResourceCapability.QueryOutput);

            switch (resource.Kind)
            {
                case KarResourceKind.File:
                case KarResourceKind.HsdRoot:
                    return CreateProjectFileOutputInfo(resource);

                case KarResourceKind.A2DEntry:
                    return CreateA2DEntryResourceOutputInfo(resource);

                default:
                    throw new ArgumentOutOfRangeException(nameof(resource));
            }
        }

        private KarProjectResourceOutputInfo CreateProjectFileOutputInfo(KarProjectResourceInfo resource)
        {
            KarProjectOutputFileInfo output = GetProjectFileOutputOrNull(resource.File);
            return new KarProjectResourceOutputInfo(
                resource,
                KarProjectResourceOutputKind.ProjectFile,
                output == null ? KarProjectResourceOutputStatus.Missing : ToResourceStatus(output.Status),
                resource.File.RelativePath,
                resource.File.OutputPath,
                output,
                null);
        }

        private KarProjectResourceOutputInfo CreateA2DEntryResourceOutputInfo(KarProjectResourceInfo resource)
        {
            KarProjectA2DEntryOutputInfo sidecar = _project.A2DService.GetEntryOutput(resource.Address);
            KarProjectOutputFileInfo packageOutput = GetProjectFileOutputOrNull(resource.File);

            if (sidecar.HasOutput)
            {
                return new KarProjectResourceOutputInfo(
                    resource,
                    KarProjectResourceOutputKind.OutputAsset,
                    sidecar.Status == KarProjectA2DEntryOutputStatus.MatchesEntry
                        ? KarProjectResourceOutputStatus.SidecarMatchesEntry
                        : KarProjectResourceOutputStatus.SidecarDiffersFromEntry,
                    sidecar.OutputRelativePath,
                    sidecar.OutputPath,
                    packageOutput,
                    sidecar);
            }

            if (packageOutput != null)
            {
                return new KarProjectResourceOutputInfo(
                    resource,
                    KarProjectResourceOutputKind.ProjectFile,
                    GetA2DEntryPackageOutputStatus(resource),
                    resource.File.RelativePath,
                    resource.File.OutputPath,
                    packageOutput,
                    sidecar);
            }

            return new KarProjectResourceOutputInfo(
                resource,
                KarProjectResourceOutputKind.OutputAsset,
                KarProjectResourceOutputStatus.Missing,
                sidecar.OutputRelativePath,
                sidecar.OutputPath,
                null,
                sidecar);
        }

        private KarProjectOutputFileInfo GetProjectFileOutputOrNull(KarProjectFile file)
        {
            if (file == null || !File.Exists(file.OutputPath))
                return null;

            return _project.OutputService.GetFile(file.RelativePath);
        }

        private KarProjectResourceOutputStatus GetA2DEntryPackageOutputStatus(KarProjectResourceInfo resource)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));

            if (!File.Exists(resource.File.SourcePath))
                return KarProjectResourceOutputStatus.SourceMissing;

            byte[] active = _project.A2DService.ReadEntryData(resource.RelativePath, resource.Reference.EntryName);
            byte[] source = ReadSourceA2DEntryData(resource.RelativePath, resource.Reference.EntryName);
            return active.SequenceEqual(source)
                ? KarProjectResourceOutputStatus.MatchesSource
                : KarProjectResourceOutputStatus.DiffersFromSource;
        }

        private byte[] ReadSourceA2DEntryData(string packageRelativePath, string entryName)
        {
            A2DPackage package;
            string error;
            if (!A2DPackage.TryOpen(_project.FileService.GetSourcePath(packageRelativePath), out package, out error))
                throw new InvalidDataException(error);

            A2DPackageEntry entry = package.Entries.FirstOrDefault(candidate =>
                string.Equals(candidate.Name, entryName, StringComparison.OrdinalIgnoreCase));
            if (entry == null)
                throw new FileNotFoundException("Source A2D package entry was not found.", entryName);

            return package.GetEntryData(entry.Index);
        }

        private static KarProjectResourceOutputStatus ToResourceStatus(KarProjectOutputFileStatus status)
        {
            switch (status)
            {
                case KarProjectOutputFileStatus.MatchesSource:
                    return KarProjectResourceOutputStatus.MatchesSource;
                case KarProjectOutputFileStatus.DiffersFromSource:
                    return KarProjectResourceOutputStatus.DiffersFromSource;
                case KarProjectOutputFileStatus.SourceMissing:
                    return KarProjectResourceOutputStatus.SourceMissing;
                default:
                    return KarProjectResourceOutputStatus.Missing;
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

        private static void EnsureCapability(KarProjectResourceInfo resource, KarProjectResourceCapability capability)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));
            if (!resource.Handler.HasCapability(capability))
                throw new NotSupportedException("Resource " + resource.Address + " does not support " + capability + ".");
        }
    }
}
