using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectFileInsightService
    {
        private readonly KarProject _project;

        internal KarProjectFileInsightService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public IReadOnlyList<KarProjectFileInsight> Query(KarProjectFileQueryOptions options = null)
        {
            IReadOnlyList<KarProjectFile> files = _project.FileService.Query(options);
            KarProjectResourceGraph graph = _project.ResourceGraphService.Snapshot;
            IReadOnlyDictionary<string, IReadOnlyList<KarMapBundle>> mapsByPath = CreateMapsByPath();
            IReadOnlyDictionary<string, IReadOnlyList<KarVehicleBundle>> vehiclesByPath = CreateVehiclesByPath();

            return files
                .Select(file => CreateInsight(file, graph, mapsByPath, vehiclesByPath))
                .ToList()
                .AsReadOnly();
        }

        public IReadOnlyList<KarProjectFileInsightContract> QueryContracts(KarProjectFileQueryOptions options = null)
        {
            return Query(options)
                .Select(insight => insight.CreateContract())
                .ToList()
                .AsReadOnly();
        }

        public KarProjectFileInsight Get(string relativePath)
        {
            return CreateInsight(
                _project.FileService.Get(relativePath),
                _project.ResourceGraphService.Snapshot,
                CreateMapsByPath(),
                CreateVehiclesByPath());
        }

        public KarProjectFileInsightContract GetContract(string relativePath)
        {
            return Get(relativePath).CreateContract();
        }

        private KarProjectFileInsight CreateInsight(
            KarProjectFile file,
            KarProjectResourceGraph graph,
            IReadOnlyDictionary<string, IReadOnlyList<KarMapBundle>> mapsByPath,
            IReadOnlyDictionary<string, IReadOnlyList<KarVehicleBundle>> vehiclesByPath)
        {
            KarProjectResourceInfo resource = null;
            graph.TryGetResource(file.RelativePath, out resource);

            KarArchiveInfo archive = null;
            string inspectionError = null;
            if (file.IsHsdArchive)
                _project.ArchiveService.TryInspectHsdArchive(file.RelativePath, out archive, out inspectionError);

            KarProjectA2DPackageContext a2dPackage = null;
            if (file.IsA2DPackage)
                a2dPackage = _project.A2DPackageContextService.Get(file.RelativePath);

            KarProjectOutputFileInfo output = null;
            _project.OutputService.TryGetFile(file.RelativePath, out output);

            return new KarProjectFileInsight(
                file,
                resource,
                archive,
                inspectionError,
                a2dPackage,
                GetOrEmpty(mapsByPath, file.RelativePath),
                GetOrEmpty(vehiclesByPath, file.RelativePath),
                GetChildResources(graph, file),
                GetRelationships(graph, file),
                output);
        }

        private static IReadOnlyList<KarProjectResourceInfo> GetChildResources(
            KarProjectResourceGraph graph,
            KarProjectFile file)
        {
            try
            {
                return graph.QueryChildResources(file.RelativePath);
            }
            catch (ArgumentException)
            {
                return Array.Empty<KarProjectResourceInfo>();
            }
            catch (KeyNotFoundException)
            {
                return Array.Empty<KarProjectResourceInfo>();
            }
        }

        private static IReadOnlyList<KarProjectRelationship> GetRelationships(
            KarProjectResourceGraph graph,
            KarProjectFile file)
        {
            return graph.Relationships
                .Where(relationship => IsRelationshipForFile(relationship, file))
                .ToList()
                .AsReadOnly();
        }

        private static bool IsRelationshipForFile(KarProjectRelationship relationship, KarProjectFile file)
        {
            return IsSameFile(relationship.File, file) ||
                IsSameFile(relationship.PackageFile, file);
        }

        private static bool IsSameFile(KarProjectFile left, KarProjectFile right)
        {
            return left != null &&
                right != null &&
                string.Equals(left.RelativePath, right.RelativePath, StringComparison.OrdinalIgnoreCase);
        }

        private IReadOnlyDictionary<string, IReadOnlyList<KarMapBundle>> CreateMapsByPath()
        {
            Dictionary<string, List<KarMapBundle>> map = new Dictionary<string, List<KarMapBundle>>(StringComparer.OrdinalIgnoreCase);
            foreach (KarMapBundle bundle in _project.MapService.Bundles)
            {
                foreach (KarProjectFile file in bundle.Files)
                    Add(map, file.RelativePath, bundle);
            }

            return Freeze(map);
        }

        private IReadOnlyDictionary<string, IReadOnlyList<KarVehicleBundle>> CreateVehiclesByPath()
        {
            Dictionary<string, List<KarVehicleBundle>> map = new Dictionary<string, List<KarVehicleBundle>>(StringComparer.OrdinalIgnoreCase);
            foreach (KarVehicleBundle bundle in _project.VehicleService.Query())
            {
                foreach (KarProjectFile file in bundle.Files)
                    Add(map, file.RelativePath, bundle);
            }

            return Freeze(map);
        }

        private static void Add<T>(Dictionary<string, List<T>> map, string relativePath, T value)
        {
            List<T> values;
            if (!map.TryGetValue(relativePath, out values))
            {
                values = new List<T>();
                map.Add(relativePath, values);
            }

            values.Add(value);
        }

        private static IReadOnlyDictionary<string, IReadOnlyList<T>> Freeze<T>(Dictionary<string, List<T>> map)
        {
            return map.ToDictionary(
                pair => pair.Key,
                pair => (IReadOnlyList<T>)pair.Value.AsReadOnly(),
                StringComparer.OrdinalIgnoreCase);
        }

        private static IReadOnlyList<T> GetOrEmpty<T>(
            IReadOnlyDictionary<string, IReadOnlyList<T>> map,
            string relativePath)
        {
            IReadOnlyList<T> values;
            return map.TryGetValue(relativePath, out values) ? values : Array.Empty<T>();
        }
    }
}
