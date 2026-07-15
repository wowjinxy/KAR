using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectA2DPackageContextService
    {
        private readonly KarProject _project;

        internal KarProjectA2DPackageContextService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public IReadOnlyList<KarProjectA2DPackageContext> Query(KarProjectA2DPackageContextQueryOptions options = null)
        {
            IEnumerable<KarProjectFile> packageFiles = _project.FileService.Query(options == null ? null : options.Packages)
                .Where(file => file.IsA2DPackage);

            List<KarProjectA2DPackageContext> contexts = new List<KarProjectA2DPackageContext>();
            foreach (KarProjectFile file in packageFiles)
            {
                KarProjectA2DPackageContext context = CreateContext(file);
                if (options == null || options.Matches(context))
                    contexts.Add(context);
            }

            return contexts
                .OrderBy(context => context.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public IReadOnlyList<KarProjectA2DPackageContextSummaryContract> QueryContracts(KarProjectA2DPackageContextQueryOptions options = null)
        {
            return Query(options)
                .Select(context => context.CreateContract())
                .ToList()
                .AsReadOnly();
        }

        public KarProjectA2DPackageContext Get(string packageRelativePath)
        {
            return Query(new KarProjectA2DPackageContextQueryOptions
            {
                PackagePath = packageRelativePath,
            }).Single();
        }

        public KarProjectA2DPackageContextSummaryContract GetContract(string packageRelativePath)
        {
            return Get(packageRelativePath).CreateContract();
        }

        private KarProjectA2DPackageContext CreateContext(KarProjectFile file)
        {
            KarProjectA2DPackage package;
            string error;
            bool isOpen = _project.ArchiveService.TryOpenProjectA2DPackage(file.RelativePath, out package, out error);

            IReadOnlyList<KarProjectA2DEntryInfo> entries = isOpen
                ? _project.A2DService.QueryEntries(new KarProjectA2DEntryQueryOptions
                {
                    PackagePath = file.RelativePath,
                })
                : Array.Empty<KarProjectA2DEntryInfo>();
            IReadOnlyList<KarProjectA2DEntryOutputInfo> entryOutputs = isOpen
                ? _project.A2DService.QueryEntryOutputs(new KarProjectA2DEntryOutputQueryOptions
                {
                    Entries = new KarProjectA2DEntryQueryOptions
                    {
                        PackagePath = file.RelativePath,
                    },
                })
                : Array.Empty<KarProjectA2DEntryOutputInfo>();
            IReadOnlyList<KarProjectScriptTableContext> scriptContexts = isOpen
                ? _project.ScriptContextService.Query(new KarProjectScriptTableContextQueryOptions
                {
                    Tables = new KarProjectScriptTableQueryOptions
                    {
                        PackagePath = file.RelativePath,
                    },
                })
                : Array.Empty<KarProjectScriptTableContext>();

            KarProjectResourceInfo resource = null;
            _project.ResourceService.TryGet(file.RelativePath, out resource);

            return new KarProjectA2DPackageContext(
                file,
                isOpen ? package : null,
                isOpen ? null : error,
                resource,
                resource != null && resource.CanQueryOutput ? _project.ResourceService.GetOutput(file.RelativePath) : null,
                entries,
                entryOutputs,
                scriptContexts);
        }
    }
}
