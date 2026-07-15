using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectArchiveContextService
    {
        private readonly KarProject _project;

        internal KarProjectArchiveContextService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public IReadOnlyList<KarProjectArchiveContext> Query(KarProjectArchiveContextQueryOptions options = null)
        {
            IEnumerable<KarProjectFile> archiveFiles = _project.FileService.Query(options == null ? null : options.Files)
                .Where(file => file.IsHsdArchive);

            List<KarProjectArchiveContext> contexts = new List<KarProjectArchiveContext>();
            foreach (KarProjectFile file in archiveFiles)
            {
                KarProjectArchiveContext context = CreateContext(file);
                if (options == null || options.Matches(context))
                    contexts.Add(context);
            }

            return contexts
                .OrderBy(context => context.Category, StringComparer.OrdinalIgnoreCase)
                .ThenBy(context => context.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public IReadOnlyList<KarProjectArchiveContextSummaryContract> QueryContracts(KarProjectArchiveContextQueryOptions options = null)
        {
            return Query(options)
                .Select(context => context.CreateContract())
                .ToList()
                .AsReadOnly();
        }

        public KarProjectArchiveContext Get(string relativePath)
        {
            return Query(new KarProjectArchiveContextQueryOptions
            {
                RelativePath = relativePath,
            }).Single();
        }

        public KarProjectArchiveContextSummaryContract GetContract(string relativePath)
        {
            return Get(relativePath).CreateContract();
        }

        public bool TryGet(string relativePath, out KarProjectArchiveContext context)
        {
            context = Query(new KarProjectArchiveContextQueryOptions
            {
                RelativePath = relativePath,
            }).SingleOrDefault();
            return context != null;
        }

        private KarProjectArchiveContext CreateContext(KarProjectFile file)
        {
            KarArchiveInfo archive;
            string inspectionError;
            bool inspected = _project.ArchiveService.TryInspectHsdArchive(file.RelativePath, out archive, out inspectionError);
            if (inspected)
                inspectionError = null;

            KarProjectResourceInfo resource = null;
            _project.ResourceService.TryGet(file.RelativePath, out resource);

            return new KarProjectArchiveContext(
                file,
                inspected ? archive : null,
                inspected ? null : inspectionError,
                resource,
                GetOutput(resource),
                QueryRootResources(file),
                QueryFields(file),
                QueryRelationships(resource));
        }

        private KarProjectResourceOutputInfo GetOutput(KarProjectResourceInfo resource)
        {
            if (resource == null || !resource.CanQueryOutput)
                return null;

            try
            {
                return _project.ResourceService.GetOutput(resource.Address);
            }
            catch (ArgumentException)
            {
                return null;
            }
            catch (FileNotFoundException)
            {
                return null;
            }
            catch (KeyNotFoundException)
            {
                return null;
            }
            catch (IndexOutOfRangeException)
            {
                return null;
            }
        }

        private IReadOnlyList<KarProjectResourceInfo> QueryRootResources(KarProjectFile file)
        {
            try
            {
                return _project.ResourceGraphService.QueryChildResources(file.RelativePath)
                    .Where(resource => resource.Kind == KarResourceKind.HsdRoot)
                    .ToList()
                    .AsReadOnly();
            }
            catch (ArgumentException)
            {
                return Array.Empty<KarProjectResourceInfo>();
            }
            catch (FileNotFoundException)
            {
                return Array.Empty<KarProjectResourceInfo>();
            }
            catch (KeyNotFoundException)
            {
                return Array.Empty<KarProjectResourceInfo>();
            }
            catch (IndexOutOfRangeException)
            {
                return Array.Empty<KarProjectResourceInfo>();
            }
        }

        private IReadOnlyList<KarProjectResourceFieldInfo> QueryFields(KarProjectFile file)
        {
            try
            {
                return _project.ResourceService.QueryFieldValues(new KarProjectResourceFieldQueryOptions
                {
                    Resources = new KarProjectResourceQueryOptions
                    {
                        Kind = KarResourceKind.HsdRoot,
                        RelativePath = file.RelativePath,
                    },
                });
            }
            catch (ArgumentException)
            {
                return Array.Empty<KarProjectResourceFieldInfo>();
            }
            catch (FileNotFoundException)
            {
                return Array.Empty<KarProjectResourceFieldInfo>();
            }
            catch (KeyNotFoundException)
            {
                return Array.Empty<KarProjectResourceFieldInfo>();
            }
            catch (IndexOutOfRangeException)
            {
                return Array.Empty<KarProjectResourceFieldInfo>();
            }
        }

        private IReadOnlyList<KarProjectRelationship> QueryRelationships(KarProjectResourceInfo resource)
        {
            if (resource == null)
                return Array.Empty<KarProjectRelationship>();

            try
            {
                return _project.ResourceGraphService.QueryResourceRelationships(resource.Address);
            }
            catch (ArgumentException)
            {
                return Array.Empty<KarProjectRelationship>();
            }
            catch (FileNotFoundException)
            {
                return Array.Empty<KarProjectRelationship>();
            }
            catch (KeyNotFoundException)
            {
                return Array.Empty<KarProjectRelationship>();
            }
            catch (IndexOutOfRangeException)
            {
                return Array.Empty<KarProjectRelationship>();
            }
        }
    }
}
