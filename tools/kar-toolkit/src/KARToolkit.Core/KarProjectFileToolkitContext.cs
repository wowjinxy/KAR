using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectFileToolkitContext
    {
        internal KarProjectFileToolkitContext(
            KarProject project,
            KarProjectFileInsight insight,
            KarProjectArchiveContext archiveContext,
            KarProjectA2DPackageContext a2dPackageContext,
            IEnumerable<KarProjectMapContext> mapContexts,
            IEnumerable<KarProjectVehicleContext> vehicleContexts,
            IEnumerable<KarProjectScriptTableContext> scriptTableContexts,
            KarProjectResourceDetail resourceDetail)
        {
            Project = project ?? throw new ArgumentNullException(nameof(project));
            Insight = insight ?? throw new ArgumentNullException(nameof(insight));
            ArchiveContext = archiveContext;
            A2DPackageContext = a2dPackageContext;
            MapContexts = (mapContexts ?? Enumerable.Empty<KarProjectMapContext>())
                .ToList()
                .AsReadOnly();
            VehicleContexts = (vehicleContexts ?? Enumerable.Empty<KarProjectVehicleContext>())
                .ToList()
                .AsReadOnly();
            ScriptTableContexts = (scriptTableContexts ?? Enumerable.Empty<KarProjectScriptTableContext>())
                .ToList()
                .AsReadOnly();
            ResourceDetail = resourceDetail;
        }

        public KarProject Project { get; }

        public KarProjectFileInsight Insight { get; }

        public KarProjectFile File => Insight.File;

        public KarProjectArchiveContext ArchiveContext { get; }

        public KarProjectA2DPackageContext A2DPackageContext { get; }

        public IReadOnlyList<KarProjectMapContext> MapContexts { get; }

        public IReadOnlyList<KarProjectVehicleContext> VehicleContexts { get; }

        public IReadOnlyList<KarProjectScriptTableContext> ScriptTableContexts { get; }

        public KarProjectResourceDetail ResourceDetail { get; }

        public string RelativePath => Insight.RelativePath;

        public string ResourceAddress => Insight.ResourceAddress;

        public string PrimaryDomainId => Insight.PrimaryDomainId;

        public IReadOnlyList<string> DomainIds => Insight.DomainIds;

        public bool HasArchiveContext => ArchiveContext != null;

        public bool HasA2DPackageContext => A2DPackageContext != null;

        public bool HasMapContexts => MapContextCount != 0;

        public bool HasVehicleContexts => VehicleContextCount != 0;

        public bool HasScriptTableContexts => ScriptTableContextCount != 0;

        public bool HasResourceDetail => ResourceDetail != null;

        public int ArchiveContextCount => HasArchiveContext ? 1 : 0;

        public int A2DPackageContextCount => HasA2DPackageContext ? 1 : 0;

        public int MapContextCount => MapContexts.Count;

        public int VehicleContextCount => VehicleContexts.Count;

        public int ScriptTableContextCount => ScriptTableContexts.Count;

        public int ResourceDetailCount => HasResourceDetail ? 1 : 0;

        public int ContextCount =>
            ArchiveContextCount +
            A2DPackageContextCount +
            MapContextCount +
            VehicleContextCount +
            ScriptTableContextCount +
            ResourceDetailCount;

        public bool HasDomainContexts =>
            HasArchiveContext ||
            HasA2DPackageContext ||
            HasMapContexts ||
            HasVehicleContexts ||
            HasScriptTableContexts;

        public bool HasToolkitContext => ContextCount != 0;

        public bool HasInspectionIssues =>
            Insight.HasInspectionError ||
            (ArchiveContext != null && ArchiveContext.HasInspectionError) ||
            (A2DPackageContext != null && A2DPackageContext.HasOpenError) ||
            MapContexts.Any(context => context.HasInspectionError) ||
            VehicleContexts.Any(context => context.HasInspectionErrors);

        public KarProjectFileToolkitContextContract CreateContract()
        {
            return KarProjectFileToolkitContextContract.Create(this);
        }
    }

    public sealed class KarProjectFileToolkitContextContract
    {
        public KarProjectFileInsightContract Insight { get; set; }

        public string RelativePath { get; set; }

        public string ResourceAddress { get; set; }

        public string PrimaryDomainId { get; set; }

        public IReadOnlyList<string> DomainIds { get; set; }

        public int ContextCount { get; set; }

        public int ArchiveContextCount { get; set; }

        public int A2DPackageContextCount { get; set; }

        public int MapContextCount { get; set; }

        public int VehicleContextCount { get; set; }

        public int ScriptTableContextCount { get; set; }

        public int ResourceDetailCount { get; set; }

        public bool HasToolkitContext { get; set; }

        public bool HasDomainContexts { get; set; }

        public bool HasInspectionIssues { get; set; }

        public KarProjectArchiveContextSummaryContract ArchiveContext { get; set; }

        public KarProjectA2DPackageContextSummaryContract A2DPackageContext { get; set; }

        public IReadOnlyList<KarProjectMapContextSummaryContract> MapContexts { get; set; }

        public IReadOnlyList<KarProjectVehicleContextSummaryContract> VehicleContexts { get; set; }

        public IReadOnlyList<KarProjectScriptTableContextSummaryContract> ScriptTableContexts { get; set; }

        public KarProjectResourceDetailSummaryContract ResourceDetail { get; set; }

        public static KarProjectFileToolkitContextContract Create(KarProjectFileToolkitContext context)
        {
            if (context == null)
                throw new ArgumentNullException(nameof(context));

            return new KarProjectFileToolkitContextContract
            {
                Insight = context.Insight.CreateContract(),
                RelativePath = context.RelativePath,
                ResourceAddress = context.ResourceAddress,
                PrimaryDomainId = context.PrimaryDomainId,
                DomainIds = context.DomainIds.ToList().AsReadOnly(),
                ContextCount = context.ContextCount,
                ArchiveContextCount = context.ArchiveContextCount,
                A2DPackageContextCount = context.A2DPackageContextCount,
                MapContextCount = context.MapContextCount,
                VehicleContextCount = context.VehicleContextCount,
                ScriptTableContextCount = context.ScriptTableContextCount,
                ResourceDetailCount = context.ResourceDetailCount,
                HasToolkitContext = context.HasToolkitContext,
                HasDomainContexts = context.HasDomainContexts,
                HasInspectionIssues = context.HasInspectionIssues,
                ArchiveContext = KarProjectArchiveContextSummaryContract.Create(context.ArchiveContext),
                A2DPackageContext = KarProjectA2DPackageContextSummaryContract.Create(context.A2DPackageContext),
                MapContexts = context.MapContexts.Select(KarProjectMapContextSummaryContract.Create).ToList().AsReadOnly(),
                VehicleContexts = context.VehicleContexts.Select(KarProjectVehicleContextSummaryContract.Create).ToList().AsReadOnly(),
                ScriptTableContexts = context.ScriptTableContexts.Select(KarProjectScriptTableContextSummaryContract.Create).ToList().AsReadOnly(),
                ResourceDetail = KarProjectResourceDetailSummaryContract.Create(context.ResourceDetail),
            };
        }
    }

    public sealed class KarProjectArchiveContextSummaryContract
    {
        public string RelativePath { get; set; }

        public string Kind { get; set; }

        public string KindId { get; set; }

        public string Category { get; set; }

        public string DisplayName { get; set; }

        public int RootCount { get; set; }

        public int KnownRootCount { get; set; }

        public int UnknownRootCount { get; set; }

        public int MissingRequiredRootCount { get; set; }

        public int RootResourceCount { get; set; }

        public int FieldCount { get; set; }

        public int RelationshipCount { get; set; }

        public bool HasInspection { get; set; }

        public bool HasInspectionError { get; set; }

        public string InspectionError { get; set; }

        public bool HasOutput { get; set; }

        public bool HasModifiedOutput { get; set; }

        public string OutputStatus { get; set; }

        public static KarProjectArchiveContextSummaryContract Create(KarProjectArchiveContext context)
        {
            if (context == null)
                return null;

            return new KarProjectArchiveContextSummaryContract
            {
                RelativePath = context.RelativePath,
                Kind = context.Kind.ToString(),
                KindId = context.KindId,
                Category = context.Category,
                DisplayName = context.DisplayName,
                RootCount = context.RootCount,
                KnownRootCount = context.KnownRootCount,
                UnknownRootCount = context.UnknownRootCount,
                MissingRequiredRootCount = context.MissingRequiredRootCount,
                RootResourceCount = context.RootResourceCount,
                FieldCount = context.FieldCount,
                RelationshipCount = context.RelationshipCount,
                HasInspection = context.HasInspection,
                HasInspectionError = context.HasInspectionError,
                InspectionError = context.InspectionError,
                HasOutput = context.HasOutput,
                HasModifiedOutput = context.HasModifiedOutput,
                OutputStatus = context.OutputStatus == null ? null : context.OutputStatus.ToString(),
            };
        }
    }

    public sealed class KarProjectA2DPackageContextSummaryContract
    {
        public string RelativePath { get; set; }

        public bool IsOpen { get; set; }

        public bool HasOpenError { get; set; }

        public string OpenError { get; set; }

        public int EntryCount { get; set; }

        public int ScriptTableCount { get; set; }

        public int EntryOutputCount { get; set; }

        public int ModifiedEntryOutputCount { get; set; }

        public bool HasOutput { get; set; }

        public bool HasModifiedOutput { get; set; }

        public bool HasEntryOutputs { get; set; }

        public bool HasModifiedEntryOutputs { get; set; }

        public string OutputStatus { get; set; }

        public static KarProjectA2DPackageContextSummaryContract Create(KarProjectA2DPackageContext context)
        {
            if (context == null)
                return null;

            return new KarProjectA2DPackageContextSummaryContract
            {
                RelativePath = context.RelativePath,
                IsOpen = context.IsOpen,
                HasOpenError = context.HasOpenError,
                OpenError = context.OpenError,
                EntryCount = context.EntryCount,
                ScriptTableCount = context.ScriptTableCount,
                EntryOutputCount = context.EntryOutputCount,
                ModifiedEntryOutputCount = context.ModifiedEntryOutputCount,
                HasOutput = context.HasOutput,
                HasModifiedOutput = context.HasModifiedOutput,
                HasEntryOutputs = context.HasEntryOutputs,
                HasModifiedEntryOutputs = context.HasModifiedEntryOutputs,
                OutputStatus = context.OutputStatus == null ? null : context.OutputStatus.ToString(),
            };
        }
    }

    public sealed class KarProjectMapContextSummaryContract
    {
        public string MapName { get; set; }

        public int ArchiveCount { get; set; }

        public int MapResourceCount { get; set; }

        public int RelationshipCount { get; set; }

        public int ScriptTableCount { get; set; }

        public int OutputFileCount { get; set; }

        public int ModifiedOutputFileCount { get; set; }

        public bool HasInspection { get; set; }

        public bool HasInspectionError { get; set; }

        public string InspectionError { get; set; }

        public bool HasOutput { get; set; }

        public bool HasModifiedOutput { get; set; }

        public bool HasScriptArchive { get; set; }

        public bool HasScriptTables { get; set; }

        public static KarProjectMapContextSummaryContract Create(KarProjectMapContext context)
        {
            if (context == null)
                throw new ArgumentNullException(nameof(context));

            return new KarProjectMapContextSummaryContract
            {
                MapName = context.MapName,
                ArchiveCount = context.ArchiveCount,
                MapResourceCount = context.MapResourceCount,
                RelationshipCount = context.RelationshipCount,
                ScriptTableCount = context.ScriptTableCount,
                OutputFileCount = context.OutputFileCount,
                ModifiedOutputFileCount = context.ModifiedOutputFileCount,
                HasInspection = context.HasInspection,
                HasInspectionError = context.HasInspectionError,
                InspectionError = context.InspectionError,
                HasOutput = context.HasOutput,
                HasModifiedOutput = context.HasModifiedOutput,
                HasScriptArchive = context.HasScriptArchive,
                HasScriptTables = context.HasScriptTables,
            };
        }
    }

    public sealed class KarProjectVehicleContextSummaryContract
    {
        public string Name { get; set; }

        public string Family { get; set; }

        public string Role { get; set; }

        public int FileCount { get; set; }

        public int SharedFileCount { get; set; }

        public int ArchiveCount { get; set; }

        public int ResourceCount { get; set; }

        public int RootCount { get; set; }

        public int InspectionErrorCount { get; set; }

        public int OutputFileCount { get; set; }

        public int ModifiedOutputFileCount { get; set; }

        public bool HasInspectionErrors { get; set; }

        public bool HasOutput { get; set; }

        public bool HasModifiedOutput { get; set; }

        public static KarProjectVehicleContextSummaryContract Create(KarProjectVehicleContext context)
        {
            if (context == null)
                throw new ArgumentNullException(nameof(context));

            return new KarProjectVehicleContextSummaryContract
            {
                Name = context.Name,
                Family = context.Family,
                Role = context.Role,
                FileCount = context.FileCount,
                SharedFileCount = context.SharedFileCount,
                ArchiveCount = context.ArchiveCount,
                ResourceCount = context.ResourceCount,
                RootCount = context.RootCount,
                InspectionErrorCount = context.InspectionErrorCount,
                OutputFileCount = context.OutputFileCount,
                ModifiedOutputFileCount = context.ModifiedOutputFileCount,
                HasInspectionErrors = context.HasInspectionErrors,
                HasOutput = context.HasOutput,
                HasModifiedOutput = context.HasModifiedOutput,
            };
        }
    }

    public sealed class KarProjectScriptTableContextSummaryContract
    {
        public string Address { get; set; }

        public string ParentAddress { get; set; }

        public string RelativePath { get; set; }

        public string Name { get; set; }

        public string Role { get; set; }

        public string Category { get; set; }

        public bool IsLooseFile { get; set; }

        public bool IsPackageEntry { get; set; }

        public int RelationshipCount { get; set; }

        public bool HasOutput { get; set; }

        public bool HasModifiedOutput { get; set; }

        public string OutputStatus { get; set; }

        public static KarProjectScriptTableContextSummaryContract Create(KarProjectScriptTableContext context)
        {
            if (context == null)
                throw new ArgumentNullException(nameof(context));

            return new KarProjectScriptTableContextSummaryContract
            {
                Address = context.Address,
                ParentAddress = context.ParentAddress,
                RelativePath = context.RelativePath,
                Name = context.Name,
                Role = context.Role,
                Category = context.Category,
                IsLooseFile = context.IsLooseFile,
                IsPackageEntry = context.IsPackageEntry,
                RelationshipCount = context.RelationshipCount,
                HasOutput = context.HasOutput,
                HasModifiedOutput = context.HasModifiedOutput,
                OutputStatus = context.OutputStatus == null ? null : context.OutputStatus.ToString(),
            };
        }
    }

    public sealed class KarProjectResourceDetailSummaryContract
    {
        public KarProjectResourceSummaryContract Resource { get; set; }

        public int ActionCount { get; set; }

        public int ChildResourceCount { get; set; }

        public int FieldCount { get; set; }

        public int RelationshipCount { get; set; }

        public bool HasOutputInfo { get; set; }

        public bool HasByteInfo { get; set; }

        public bool HasChildResources { get; set; }

        public bool HasFields { get; set; }

        public bool HasRelationships { get; set; }

        public string OutputKind { get; set; }

        public string OutputStatus { get; set; }

        public string ByteStatus { get; set; }

        public static KarProjectResourceDetailSummaryContract Create(KarProjectResourceDetail detail)
        {
            if (detail == null)
                return null;

            return new KarProjectResourceDetailSummaryContract
            {
                Resource = KarProjectResourceSummaryContract.Create(detail.Resource),
                ActionCount = detail.ActionCount,
                ChildResourceCount = detail.ChildResourceCount,
                FieldCount = detail.FieldCount,
                RelationshipCount = detail.RelationshipCount,
                HasOutputInfo = detail.HasOutputInfo,
                HasByteInfo = detail.HasByteInfo,
                HasChildResources = detail.HasChildResources,
                HasFields = detail.HasFields,
                HasRelationships = detail.HasRelationships,
                OutputKind = detail.Output == null ? null : detail.Output.OutputKind.ToString(),
                OutputStatus = detail.Output == null ? null : detail.Output.Status.ToString(),
                ByteStatus = detail.ByteInfo == null ? null : detail.ByteInfo.Status.ToString(),
            };
        }
    }
}
