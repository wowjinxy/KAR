using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectFileContract
    {
        public KarResourceReferenceContract Resource { get; set; }

        public string RelativePath { get; set; }

        public string ResourceAddress { get; set; }

        public string Kind { get; set; }

        public string KindId { get; set; }

        public KarFileKindDescriptorContract KindInfo { get; set; }

        public KarProjectFileHandlerContract Handler { get; set; }

        public IReadOnlyList<string> Capabilities { get; set; }

        public string MapName { get; set; }

        public string MapBundleRole { get; set; }

        public string DisplayName { get; set; }

        public string Category { get; set; }

        public string SourcePath { get; set; }

        public string OutputPath { get; set; }

        public string ReadPath { get; set; }

        public bool HasOutputCopy { get; set; }

        public KarArchiveDefinitionSummaryContract ArchiveDefinition { get; set; }

        public static KarProjectFileContract Create(KarProjectFile file)
        {
            if (file == null)
                throw new ArgumentNullException(nameof(file));

            return new KarProjectFileContract
            {
                Resource = KarResourceReferenceContract.Create(file.ResourceReference),
                RelativePath = file.RelativePath,
                ResourceAddress = file.ResourceAddress,
                Kind = file.Kind.ToString(),
                KindId = file.KindId,
                KindInfo = KarFileKindDescriptorContract.Create(file.KindDescriptor),
                Handler = KarProjectFileHandlerContract.Create(file.Handler),
                Capabilities = file.Handler.CapabilityList.Select(capability => capability.ToString()).ToList().AsReadOnly(),
                MapName = file.MapName,
                MapBundleRole = file.MapBundleRole,
                DisplayName = file.DisplayName,
                Category = file.Category,
                SourcePath = file.SourcePath,
                OutputPath = file.OutputPath,
                ReadPath = file.ReadPath,
                HasOutputCopy = file.HasOutputCopy,
                ArchiveDefinition = KarArchiveDefinitionSummaryContract.Create(file.ArchiveDefinition),
            };
        }
    }

    public sealed class KarArchiveDefinitionSummaryContract
    {
        public string Kind { get; set; }

        public string DisplayName { get; set; }

        public string Category { get; set; }

        public string Description { get; set; }

        public int RootDefinitionCount { get; set; }

        public static KarArchiveDefinitionSummaryContract Create(KarArchiveDefinition definition)
        {
            if (definition == null)
                return null;

            return new KarArchiveDefinitionSummaryContract
            {
                Kind = definition.Kind.ToString(),
                DisplayName = definition.DisplayName,
                Category = definition.Category,
                Description = definition.Description,
                RootDefinitionCount = definition.Roots.Count,
            };
        }
    }

    public sealed class KarProjectFileInsightContract
    {
        public KarProjectFileContract File { get; set; }

        public string RelativePath { get; set; }

        public string ResourceAddress { get; set; }

        public string Kind { get; set; }

        public string KindId { get; set; }

        public string DisplayName { get; set; }

        public string Category { get; set; }

        public string PrimaryDomainId { get; set; }

        public IReadOnlyList<string> DomainIds { get; set; }

        public bool IsHsdArchive { get; set; }

        public bool IsA2DPackage { get; set; }

        public bool IsScriptTable { get; set; }

        public bool IsMapBundlePart { get; set; }

        public bool IsVehicleData { get; set; }

        public string MapName { get; set; }

        public string MapBundleRole { get; set; }

        public int MapCount { get; set; }

        public bool HasMaps { get; set; }

        public string VehicleName { get; set; }

        public string VehicleFamily { get; set; }

        public string VehicleRole { get; set; }

        public int VehicleBundleCount { get; set; }

        public bool HasVehicles { get; set; }

        public bool HasResource { get; set; }

        public int ResourceCount { get; set; }

        public int ChildResourceCount { get; set; }

        public int RootResourceCount { get; set; }

        public int A2DEntryResourceCount { get; set; }

        public int ScriptTableResourceCount { get; set; }

        public int RelationshipCount { get; set; }

        public int RootCount { get; set; }

        public int KnownRootCount { get; set; }

        public int UnknownRootCount { get; set; }

        public int MissingRequiredRootCount { get; set; }

        public bool HasInspection { get; set; }

        public bool HasInspectionError { get; set; }

        public string InspectionError { get; set; }

        public bool HasMissingRequiredRoots { get; set; }

        public bool HasOutputCopy { get; set; }

        public bool HasOutputInfo { get; set; }

        public bool HasOutput { get; set; }

        public bool HasModifiedOutput { get; set; }

        public bool HasUnchangedOutput { get; set; }

        public string OutputStatus { get; set; }

        public string OutputPath { get; set; }

        public static KarProjectFileInsightContract Create(KarProjectFileInsight insight)
        {
            if (insight == null)
                throw new ArgumentNullException(nameof(insight));

            return new KarProjectFileInsightContract
            {
                File = KarProjectFileContract.Create(insight.File),
                RelativePath = insight.RelativePath,
                ResourceAddress = insight.ResourceAddress,
                Kind = insight.Kind.ToString(),
                KindId = insight.KindId,
                DisplayName = insight.DisplayName,
                Category = insight.Category,
                PrimaryDomainId = insight.PrimaryDomainId,
                DomainIds = insight.DomainIds.ToList().AsReadOnly(),
                IsHsdArchive = insight.IsHsdArchive,
                IsA2DPackage = insight.IsA2DPackage,
                IsScriptTable = insight.IsScriptTable,
                IsMapBundlePart = insight.IsMapBundlePart,
                IsVehicleData = insight.IsVehicleData,
                MapName = insight.MapName,
                MapBundleRole = insight.MapBundleRole,
                MapCount = insight.MapCount,
                HasMaps = insight.HasMaps,
                VehicleName = insight.VehicleName,
                VehicleFamily = insight.VehicleFamily,
                VehicleRole = insight.VehicleRole,
                VehicleBundleCount = insight.VehicleBundleCount,
                HasVehicles = insight.HasVehicles,
                HasResource = insight.HasResource,
                ResourceCount = insight.ResourceCount,
                ChildResourceCount = insight.ChildResourceCount,
                RootResourceCount = insight.RootResourceCount,
                A2DEntryResourceCount = insight.A2DEntryResourceCount,
                ScriptTableResourceCount = insight.ScriptTableResourceCount,
                RelationshipCount = insight.RelationshipCount,
                RootCount = insight.RootCount,
                KnownRootCount = insight.KnownRootCount,
                UnknownRootCount = insight.UnknownRootCount,
                MissingRequiredRootCount = insight.MissingRequiredRootCount,
                HasInspection = insight.HasInspection,
                HasInspectionError = insight.HasInspectionError,
                InspectionError = insight.InspectionError,
                HasMissingRequiredRoots = insight.HasMissingRequiredRoots,
                HasOutputCopy = insight.HasOutputCopy,
                HasOutputInfo = insight.HasOutputInfo,
                HasOutput = insight.HasOutput,
                HasModifiedOutput = insight.HasModifiedOutput,
                HasUnchangedOutput = insight.HasUnchangedOutput,
                OutputStatus = insight.OutputStatus,
                OutputPath = insight.OutputPath,
            };
        }
    }
}
