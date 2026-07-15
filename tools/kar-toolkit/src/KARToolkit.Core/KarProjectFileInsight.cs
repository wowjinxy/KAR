using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectFileInsight
    {
        internal KarProjectFileInsight(
            KarProjectFile file,
            KarProjectResourceInfo resource,
            KarArchiveInfo archive,
            string inspectionError,
            KarProjectA2DPackageContext a2dPackage,
            IEnumerable<KarMapBundle> maps,
            IEnumerable<KarVehicleBundle> vehicles,
            IEnumerable<KarProjectResourceInfo> childResources,
            IEnumerable<KarProjectRelationship> relationships,
            KarProjectOutputFileInfo output)
        {
            File = file ?? throw new ArgumentNullException(nameof(file));
            Resource = resource;
            Archive = archive;
            A2DPackage = a2dPackage;
            InspectionError = inspectionError ?? (A2DPackage == null ? null : A2DPackage.OpenError);
            Maps = (maps ?? Enumerable.Empty<KarMapBundle>()).ToList().AsReadOnly();
            Vehicles = (vehicles ?? Enumerable.Empty<KarVehicleBundle>()).ToList().AsReadOnly();
            ChildResources = (childResources ?? Enumerable.Empty<KarProjectResourceInfo>()).ToList().AsReadOnly();
            Relationships = (relationships ?? Enumerable.Empty<KarProjectRelationship>()).ToList().AsReadOnly();
            Output = output;
            DomainIds = CreateDomainIds().AsReadOnly();
        }

        public KarProjectFile File { get; }

        public KarProjectResourceInfo Resource { get; }

        public KarArchiveInfo Archive { get; }

        public string InspectionError { get; }

        public KarProjectA2DPackageContext A2DPackage { get; }

        public IReadOnlyList<KarMapBundle> Maps { get; }

        public IReadOnlyList<KarVehicleBundle> Vehicles { get; }

        public IReadOnlyList<KarProjectResourceInfo> ChildResources { get; }

        public IReadOnlyList<KarProjectRelationship> Relationships { get; }

        public KarProjectOutputFileInfo Output { get; }

        public IReadOnlyList<string> DomainIds { get; }

        public string RelativePath => File.RelativePath;

        public string ResourceAddress => File.ResourceAddress;

        public KarFileKind Kind => File.Kind;

        public string KindId => File.KindId;

        public string DisplayName => File.DisplayName;

        public string Category => File.Category;

        public string PrimaryDomainId
        {
            get
            {
                if (HasMaps)
                    return "maps";
                if (HasVehicles)
                    return "vehicles";
                if (IsA2DPackage)
                    return "a2d-packages";
                if (IsScriptTable || ScriptTableResourceCount != 0)
                    return "script-tables";
                if (IsHsdArchive)
                    return "archives";

                return "files";
            }
        }

        public bool IsHsdArchive => File.IsHsdArchive;

        public bool IsA2DPackage => File.IsA2DPackage;

        public bool IsScriptTable => File.IsScriptTable;

        public bool IsMapBundlePart => File.IsMapBundlePart;

        public bool IsVehicleData => Kind == KarFileKind.VehicleData;

        public string MapName => File.MapName ?? (Maps.Count == 1 ? Maps[0].Name : null);

        public string MapBundleRole => File.MapBundleRole;

        public int MapCount => Maps.Count;

        public bool HasMaps => MapCount != 0 || IsMapBundlePart;

        public string VehicleName => Vehicles.Count == 1 ? Vehicles[0].Name : null;

        public string VehicleFamily => Vehicles.Count == 1 ? Vehicles[0].Family : null;

        public string VehicleRole => Vehicles.Count == 1 ? Vehicles[0].Role : null;

        public int VehicleBundleCount => Vehicles.Count;

        public bool HasVehicles => VehicleBundleCount != 0 || IsVehicleData;

        public bool HasResource => Resource != null;

        public int ResourceCount => (HasResource ? 1 : 0) + ChildResourceCount;

        public int ChildResourceCount => ChildResources.Count;

        public int RootResourceCount => ChildResources.Count(resource => resource.IsHsdRoot);

        public int A2DEntryResourceCount => A2DPackage == null
            ? ChildResources.Count(resource => resource.IsA2DEntry)
            : A2DPackage.EntryCount;

        public int ScriptTableResourceCount
        {
            get
            {
                int count = IsScriptTable ? 1 : 0;
                count += ChildResources.Count(IsScriptTableResource);

                if (A2DPackage != null && A2DPackage.ScriptTableCount > count)
                    count = A2DPackage.ScriptTableCount;

                return count;
            }
        }

        public int RelationshipCount => Relationships.Count;

        public int RootCount => Archive == null ? RootResourceCount : Archive.Roots.Count;

        public int KnownRootCount => Archive == null ? RootResourceCount : Archive.KnownRoots.Count;

        public int UnknownRootCount => Archive == null ? 0 : Archive.UnknownRoots.Count;

        public int MissingRequiredRootCount => Archive == null ? 0 : Archive.MissingRequiredRoots.Count;

        public bool HasInspection => Archive != null || (A2DPackage != null && A2DPackage.IsOpen);

        public bool HasInspectionError => !string.IsNullOrEmpty(InspectionError) ||
            (A2DPackage != null && A2DPackage.HasOpenError);

        public bool HasMissingRequiredRoots => MissingRequiredRootCount != 0;

        public bool HasOutputCopy => File.HasOutputCopy;

        public bool HasOutputInfo => Output != null;

        public bool HasOutput => Output != null;

        public bool HasModifiedOutput => Output != null && Output.IsModifiedProjectFile;

        public bool HasUnchangedOutput => Output != null && Output.IsUnchangedProjectFile;

        public string OutputStatus => Output == null ? null : Output.Status.ToString();

        public string OutputPath => Output == null ? null : Output.OutputPath;

        public KarProjectFileInsightContract CreateContract()
        {
            return KarProjectFileInsightContract.Create(this);
        }

        private List<string> CreateDomainIds()
        {
            List<string> domains = new List<string> { "files" };
            if (HasResource || ChildResourceCount != 0)
                AddUnique(domains, "resources");
            if (IsHsdArchive)
                AddUnique(domains, "archives");
            if (HasMaps)
                AddUnique(domains, "maps");
            if (HasVehicles)
                AddUnique(domains, "vehicles");
            if (IsA2DPackage)
                AddUnique(domains, "a2d-packages");
            if (IsScriptTable || ScriptTableResourceCount != 0)
                AddUnique(domains, "script-tables");
            if (HasOutputCopy)
                AddUnique(domains, "mod-output");

            return domains;
        }

        private static void AddUnique(List<string> values, string value)
        {
            if (!values.Contains(value, StringComparer.OrdinalIgnoreCase))
                values.Add(value);
        }

        private static bool IsScriptTableResource(KarProjectResourceInfo resource)
        {
            return resource != null &&
                ((resource.File != null && resource.File.IsScriptTable) ||
                (resource.A2DEntry != null && resource.A2DEntry.IsScriptTable) ||
                string.Equals(resource.Category, "Scripts", StringComparison.OrdinalIgnoreCase));
        }
    }
}
