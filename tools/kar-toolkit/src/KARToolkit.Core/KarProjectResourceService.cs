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
    }
}
