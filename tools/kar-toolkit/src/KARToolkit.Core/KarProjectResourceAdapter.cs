using KARToolkit.Core.AirRide;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace KARToolkit.Core
{
    public abstract class KarProjectResourceAdapter
    {
        protected KarProjectResourceAdapter(KarProject project, KarProjectResourceHandler handler)
        {
            Project = project ?? throw new ArgumentNullException(nameof(project));
            Handler = handler ?? throw new ArgumentNullException(nameof(handler));
        }

        public KarProject Project { get; }

        public KarProjectResourceHandler Handler { get; }

        public KarResourceKind Kind => Handler.Kind;

        public virtual KarProjectResourceOutputInfo CreateOutputInfo(KarProjectResourceInfo resource)
        {
            EnsureResourceCapability(resource, KarProjectResourceCapability.QueryOutput);
            throw Unsupported(resource, KarProjectResourceCapability.QueryOutput);
        }

        public virtual byte[] ReadBytes(KarProjectResourceInfo resource)
        {
            EnsureResourceCapability(resource, KarProjectResourceCapability.ReadBytes);
            throw Unsupported(resource, KarProjectResourceCapability.ReadBytes);
        }

        public virtual KarProjectResourceExportResult ExportToOutput(KarProjectResourceInfo resource, bool overwrite = false)
        {
            EnsureResourceCapability(resource, KarProjectResourceCapability.ExportToOutput);
            throw Unsupported(resource, KarProjectResourceCapability.ExportToOutput);
        }

        public virtual KarProjectResourceImportResult ImportFromFile(KarProjectResourceInfo resource, string inputPath)
        {
            EnsureResourceCapability(resource, KarProjectResourceCapability.ImportFromFile);
            throw Unsupported(resource, KarProjectResourceCapability.ImportFromFile);
        }

        public virtual KarProjectResourceScalarEditResult SetScalarFieldFromText(
            KarProjectResourceInfo resource,
            string fieldName,
            string rawValue,
            bool bufferAlign = true,
            bool optimize = true,
            bool trim = false)
        {
            EnsureResourceCapability(resource, KarProjectResourceCapability.SetScalarFields);
            throw Unsupported(resource, KarProjectResourceCapability.SetScalarFields);
        }

        public virtual KarProjectResourceOutputApplyResult ApplyOutput(KarProjectResourceOutputInfo output)
        {
            if (output == null)
                throw new ArgumentNullException(nameof(output));

            EnsureResourceCapability(output.Resource, KarProjectResourceCapability.ApplyOutput);
            throw Unsupported(output.Resource, KarProjectResourceCapability.ApplyOutput);
        }

        protected void EnsureResourceCapability(KarProjectResourceInfo resource, KarProjectResourceCapability capability)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));
            if (resource.Kind != Kind)
                throw new ArgumentException("Resource adapter " + Kind + " cannot handle resource kind " + resource.Kind + ".", nameof(resource));
            if (!resource.Handler.HasCapability(capability))
                throw Unsupported(resource, capability);
        }

        protected KarProjectResourceOutputInfo CreateProjectFileOutputInfo(KarProjectResourceInfo resource)
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

        protected KarProjectResourceExportResult ExportContainingFile(KarProjectResourceInfo resource, bool overwrite)
        {
            if (resource == null)
                throw new ArgumentNullException(nameof(resource));
            if (resource.File == null)
                throw new InvalidOperationException("Resource does not have a containing project file: " + resource.Address);

            bool wroteOutput = overwrite || !File.Exists(resource.File.OutputPath);
            KarProjectFileCopyResult copy = Project.FileService.CopyFileToOutput(resource.File.RelativePath, overwrite);
            return new KarProjectResourceExportResult(
                resource,
                KarProjectResourceOutputKind.ProjectFile,
                resource.File.RelativePath,
                copy.OutputPath,
                wroteOutput,
                copy,
                null);
        }

        protected KarProjectOutputFileInfo GetProjectFileOutputOrNull(KarProjectFile file)
        {
            if (file == null || !File.Exists(file.OutputPath))
                return null;

            return Project.OutputService.GetFile(file.RelativePath);
        }

        protected static KarProjectResourceOutputStatus ToResourceStatus(KarProjectOutputFileStatus status)
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

        private static NotSupportedException Unsupported(KarProjectResourceInfo resource, KarProjectResourceCapability capability)
        {
            return new NotSupportedException("Resource " + resource.Address + " does not support " + capability + ".");
        }

        internal static IReadOnlyList<KarProjectResourceAdapter> CreateDefaultAdapters(KarProject project)
        {
            return new KarProjectResourceAdapter[]
            {
                new KarProjectFileResourceAdapter(project, project.ResourceHandlerRegistry.GetHandler(KarResourceKind.File)),
                new KarProjectHsdRootResourceAdapter(project, project.ResourceHandlerRegistry.GetHandler(KarResourceKind.HsdRoot)),
                new KarProjectA2DEntryResourceAdapter(project, project.ResourceHandlerRegistry.GetHandler(KarResourceKind.A2DEntry)),
            };
        }

        private sealed class KarProjectFileResourceAdapter : KarProjectResourceAdapter
        {
            public KarProjectFileResourceAdapter(KarProject project, KarProjectResourceHandler handler)
                : base(project, handler)
            {
            }

            public override KarProjectResourceOutputInfo CreateOutputInfo(KarProjectResourceInfo resource)
            {
                EnsureResourceCapability(resource, KarProjectResourceCapability.QueryOutput);
                return CreateProjectFileOutputInfo(resource);
            }

            public override byte[] ReadBytes(KarProjectResourceInfo resource)
            {
                EnsureResourceCapability(resource, KarProjectResourceCapability.ReadBytes);
                return Project.FileService.ReadBytes(resource.RelativePath);
            }

            public override KarProjectResourceExportResult ExportToOutput(KarProjectResourceInfo resource, bool overwrite = false)
            {
                EnsureResourceCapability(resource, KarProjectResourceCapability.ExportToOutput);
                return ExportContainingFile(resource, overwrite);
            }

            public override KarProjectResourceImportResult ImportFromFile(KarProjectResourceInfo resource, string inputPath)
            {
                EnsureResourceCapability(resource, KarProjectResourceCapability.ImportFromFile);
                byte[] data = File.ReadAllBytes(inputPath);
                KarProjectFileWriteResult write = Project.FileService.WriteFileBytes(resource.RelativePath, data);
                return new KarProjectResourceImportResult(
                    resource,
                    inputPath,
                    KarProjectResourceOutputKind.ProjectFile,
                    write.RelativePath,
                    write.OutputPath,
                    data.Length,
                    write,
                    null);
            }
        }

        private sealed class KarProjectHsdRootResourceAdapter : KarProjectResourceAdapter
        {
            public KarProjectHsdRootResourceAdapter(KarProject project, KarProjectResourceHandler handler)
                : base(project, handler)
            {
            }

            public override KarProjectResourceOutputInfo CreateOutputInfo(KarProjectResourceInfo resource)
            {
                EnsureResourceCapability(resource, KarProjectResourceCapability.QueryOutput);
                return CreateProjectFileOutputInfo(resource);
            }

            public override byte[] ReadBytes(KarProjectResourceInfo resource)
            {
                EnsureResourceCapability(resource, KarProjectResourceCapability.ReadBytes);
                var archive = Project.ArchiveService.OpenHsdFile(resource.RelativePath);
                var root = archive.Roots.FirstOrDefault(candidate =>
                    string.Equals(candidate.Name, resource.Reference.RootName, StringComparison.Ordinal));
                if (root == null)
                    throw new FileNotFoundException("HSD root was not found.", resource.Reference.RootName);
                if (root.Data == null || root.Data._s == null)
                    return Array.Empty<byte>();

                return root.Data._s.GetBytes(0, root.Data._s.Length);
            }

            public override KarProjectResourceExportResult ExportToOutput(KarProjectResourceInfo resource, bool overwrite = false)
            {
                EnsureResourceCapability(resource, KarProjectResourceCapability.ExportToOutput);
                return ExportContainingFile(resource, overwrite);
            }

            public override KarProjectResourceScalarEditResult SetScalarFieldFromText(
                KarProjectResourceInfo resource,
                string fieldName,
                string rawValue,
                bool bufferAlign = true,
                bool optimize = true,
                bool trim = false)
            {
                EnsureResourceCapability(resource, KarProjectResourceCapability.SetScalarFields);
                KarProjectScalarEditResult edit = Project.EditService.SetScalarFieldFromText(
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
        }

        private sealed class KarProjectA2DEntryResourceAdapter : KarProjectResourceAdapter
        {
            public KarProjectA2DEntryResourceAdapter(KarProject project, KarProjectResourceHandler handler)
                : base(project, handler)
            {
            }

            public override KarProjectResourceOutputInfo CreateOutputInfo(KarProjectResourceInfo resource)
            {
                EnsureResourceCapability(resource, KarProjectResourceCapability.QueryOutput);
                KarProjectA2DEntryOutputInfo sidecar = Project.A2DService.GetEntryOutput(resource.Address);
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

            public override byte[] ReadBytes(KarProjectResourceInfo resource)
            {
                EnsureResourceCapability(resource, KarProjectResourceCapability.ReadBytes);
                return Project.A2DService.ReadEntryData(resource.RelativePath, resource.Reference.EntryName);
            }

            public override KarProjectResourceExportResult ExportToOutput(KarProjectResourceInfo resource, bool overwrite = false)
            {
                EnsureResourceCapability(resource, KarProjectResourceCapability.ExportToOutput);
                KarProjectA2DEntryExtractResult extract = Project.A2DService.ExtractEntryToOutput(resource.Address, overwrite);
                return new KarProjectResourceExportResult(
                    resource,
                    KarProjectResourceOutputKind.OutputAsset,
                    extract.OutputRelativePath,
                    extract.OutputPath,
                    extract.WroteOutput,
                    null,
                    extract);
            }

            public override KarProjectResourceImportResult ImportFromFile(KarProjectResourceInfo resource, string inputPath)
            {
                EnsureResourceCapability(resource, KarProjectResourceCapability.ImportFromFile);
                KarProjectA2DEntryReplaceResult replace = Project.A2DService.ReplaceEntryFromFile(
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
            }

            public override KarProjectResourceOutputApplyResult ApplyOutput(KarProjectResourceOutputInfo output)
            {
                if (output == null)
                    throw new ArgumentNullException(nameof(output));

                EnsureResourceCapability(output.Resource, KarProjectResourceCapability.ApplyOutput);
                if (output.OutputKind != KarProjectResourceOutputKind.OutputAsset)
                    throw new NotSupportedException("Only A2D entry sidecar output resources can be applied.");
                if (output.A2DEntryOutput == null || !output.A2DEntryOutput.HasOutput)
                    throw new FileNotFoundException("A2D entry sidecar output was not found.", output.OutputPath);

                KarProjectA2DEntryApplyResult apply = Project.A2DService.ApplyEntryOutput(output.Address);
                return new KarProjectResourceOutputApplyResult(output, apply);
            }

            private KarProjectResourceOutputStatus GetA2DEntryPackageOutputStatus(KarProjectResourceInfo resource)
            {
                if (!File.Exists(resource.File.SourcePath))
                    return KarProjectResourceOutputStatus.SourceMissing;

                byte[] active = Project.A2DService.ReadEntryData(resource.RelativePath, resource.Reference.EntryName);
                byte[] source = ReadSourceA2DEntryData(resource.RelativePath, resource.Reference.EntryName);
                return active.SequenceEqual(source)
                    ? KarProjectResourceOutputStatus.MatchesSource
                    : KarProjectResourceOutputStatus.DiffersFromSource;
            }

            private byte[] ReadSourceA2DEntryData(string packageRelativePath, string entryName)
            {
                A2DPackage package;
                string error;
                if (!A2DPackage.TryOpen(Project.FileService.GetSourcePath(packageRelativePath), out package, out error))
                    throw new InvalidDataException(error);

                A2DPackageEntry entry = package.Entries.FirstOrDefault(candidate =>
                    string.Equals(candidate.Name, entryName, StringComparison.OrdinalIgnoreCase));
                if (entry == null)
                    throw new FileNotFoundException("Source A2D package entry was not found.", entryName);

                return package.GetEntryData(entry.Index);
            }
        }
    }
}
