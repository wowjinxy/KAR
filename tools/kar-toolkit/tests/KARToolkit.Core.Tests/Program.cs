using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using HSDRaw;
using HSDRaw.AirRide;
using HSDRaw.AirRide.Gr.Data;
using HSDRaw.AirRide.Vc;
using KARToolkit.Core;
using KARToolkit.Core.AirRide;

namespace KARToolkit.Core.Tests
{
    internal static class Program
    {
        private static readonly List<string> Failures = new List<string>();
        private static int _assertionCount;

        public static int Main()
        {
            Run("BuiltInCatalogHasExpectedCoreSchemas", BuiltInCatalogHasExpectedCoreSchemas);
            Run("BuiltInSchemasPassValidation", BuiltInSchemasPassValidation);
            Run("SchemaValidatorReportsInvalidDefinitions", SchemaValidatorReportsInvalidDefinitions);
            Run("ProjectValidationIncludesSchemaPreflight", ProjectValidationIncludesSchemaPreflight);
            Run("ProjectSchemaServiceExposesActiveProjectCatalogs", ProjectSchemaServiceExposesActiveProjectCatalogs);
            Run("ProjectDataCoverageReportIdentifiesSchemaGaps", ProjectDataCoverageReportIdentifiesSchemaGaps);
            Run("FileKindRegistryDescribesProjectHandlers", FileKindRegistryDescribesProjectHandlers);
            Run("ResourceHandlerRegistryDescribesResourceOperations", ResourceHandlerRegistryDescribesResourceOperations);
            Run("ProjectFileQueryFiltersFiles", ProjectFileQueryFiltersFiles);
            Run("ResourceReferencesAddressProjectObjects", ResourceReferencesAddressProjectObjects);
            Run("ProjectResourceGraphIndexesResourcesAndRelationships", ProjectResourceGraphIndexesResourcesAndRelationships);
            Run("ProjectResourceServiceQueriesAndResolvesAddresses", ProjectResourceServiceQueriesAndResolvesAddresses);
            Run("ProjectResourceActionExecutorRunsPlannedResourceActions", ProjectResourceActionExecutorRunsPlannedResourceActions);
            Run("ProjectOperationServiceIndexesWorkflowsAndResourceActions", ProjectOperationServiceIndexesWorkflowsAndResourceActions);
            Run("ProjectResourceServiceQueriesFieldValues", ProjectResourceServiceQueriesFieldValues);
            Run("ProjectResourceDataViewsExposeLabeledFieldTrees", ProjectResourceDataViewsExposeLabeledFieldTrees);
            Run("ProjectResourceServiceReadsAndExportsResourcesSafely", ProjectResourceServiceReadsAndExportsResourcesSafely);
            Run("ProjectResourceServiceImportsResourcesSafely", ProjectResourceServiceImportsResourcesSafely);
            Run("ProjectResourceServiceWritesScalarEditsToOutput", ProjectResourceServiceWritesScalarEditsToOutput);
            Run("ProjectResourceServiceReportsUnifiedOutputStatus", ProjectResourceServiceReportsUnifiedOutputStatus);
            Run("ProjectResourceServiceAppliesModifiedResourceOutputs", ProjectResourceServiceAppliesModifiedResourceOutputs);
            Run("ProjectOutputInventoryTracksModFiles", ProjectOutputInventoryTracksModFiles);
            Run("ProjectModWorkspaceSummarizesOutputState", ProjectModWorkspaceSummarizesOutputState);
            Run("ProjectSessionExposesToolkitWorkspaceBoundary", ProjectSessionExposesToolkitWorkspaceBoundary);
            Run("ProjectModManifestIndexesOutputArtifacts", ProjectModManifestIndexesOutputArtifacts);
            Run("ProjectToolkitSnapshotAggregatesDomainContexts", ProjectToolkitSnapshotAggregatesDomainContexts);
            Run("ProjectMapOutputQueryGroupsModFiles", ProjectMapOutputQueryGroupsModFiles);
            Run("ProjectMapServiceCoordinatesMapWorkflows", ProjectMapServiceCoordinatesMapWorkflows);
            Run("ProjectMapScriptServiceGroupsMapAndScriptResources", ProjectMapScriptServiceGroupsMapAndScriptResources);
            Run("ProjectMapContextServiceCombinesMapToolkitState", ProjectMapContextServiceCombinesMapToolkitState);
            Run("ProjectVehicleServiceCombinesVehicleToolkitState", ProjectVehicleServiceCombinesVehicleToolkitState);
            Run("ProjectRelationshipServiceConnectsMapsAndScriptTables", ProjectRelationshipServiceConnectsMapsAndScriptTables);
            Run("ProjectScriptServiceQueriesScriptTables", ProjectScriptServiceQueriesScriptTables);
            Run("ProjectScriptContextServiceReportsScriptOutputState", ProjectScriptContextServiceReportsScriptOutputState);
            Run("ProjectA2DServiceQueriesProjectEntries", ProjectA2DServiceQueriesProjectEntries);
            Run("ProjectA2DPackageContextsSummarizePackages", ProjectA2DPackageContextsSummarizePackages);
            Run("ProjectA2DServiceExtractsAndReplacesEntriesSafely", ProjectA2DServiceExtractsAndReplacesEntriesSafely);
            Run("ProjectArchiveServiceCoordinatesArchiveWorkflows", ProjectArchiveServiceCoordinatesArchiveWorkflows);
            Run("ProjectArchiveContextServiceCombinesArchiveToolkitState", ProjectArchiveContextServiceCombinesArchiveToolkitState);
            Run("ProjectEditServiceWritesScalarEditsToOutput", ProjectEditServiceWritesScalarEditsToOutput);
            Run("ProjectSchemaUsageGroupsKnownRoots", ProjectSchemaUsageGroupsKnownRoots);
            Run("ProjectFieldQueryReturnsLabeledValues", ProjectFieldQueryReturnsLabeledValues);
            Run("ProjectFieldSummariesGroupDistinctValues", ProjectFieldSummariesGroupDistinctValues);
            Run("ProjectReportAggregatesInventories", ProjectReportAggregatesInventories);
            Run("RegistryRejectsAmbiguousDefinitions", RegistryRejectsAmbiguousDefinitions);
            Run("DefinitionRejectsAmbiguousFields", DefinitionRejectsAmbiguousFields);

            if (Failures.Count > 0)
            {
                Console.Error.WriteLine("KARToolkit.Core.Tests failed:");
                foreach (string failure in Failures)
                    Console.Error.WriteLine("  " + failure);
                return 1;
            }

            Console.WriteLine("KARToolkit.Core.Tests passed: " + _assertionCount + " assertions.");
            return 0;
        }

        private static void BuiltInCatalogHasExpectedCoreSchemas()
        {
            KarDataDefinitionRegistry registry = KarDataDefinitionCatalog.BuiltIn;
            AssertTrue(KarDataDefinitionCatalog.All.Count >= 32, "built-in catalog should contain the current schema set");
            AssertResolves(registry, "kar.gr.data", "KAR_grData");
            AssertResolves(registry, "kar.gr.itemNode", "KAR_grItemNode");
            AssertResolves(registry, "kar.gr.itemCityTrial", "KAR_grItemNodeCityTrial");
            AssertResolves(registry, "kar.vs.legendary", "KAR_vsLegendaryData");
            AssertResolves(registry, "kar.vc.common", "KAR_vcDataCommon");
        }

        private static void BuiltInSchemasPassValidation()
        {
            KarDataDefinitionValidationReport report = KarDataDefinitionValidator.ValidateBuiltIn();

            AssertTrue(report.DefinitionCount >= 32, "schema validation should inspect the built-in schema set");
            AssertTrue(report.IsValid, "built-in schemas should pass validation");
            AssertTrue(report.ErrorCount == 0, "built-in schemas should have no validation errors");
        }

        private static void SchemaValidatorReportsInvalidDefinitions()
        {
            KarDataDefinitionValidationReport report = KarDataDefinitionValidator.Validate(new[]
            {
                new KarDataDefinition(
                    "kar.test.invalid",
                    "Invalid Definition",
                    "Tests",
                    "InvalidAccessor",
                    "Invalid definition.",
                    "tests",
                    new[]
                    {
                        new KarDataFieldDefinition("missingReference", 0, "HSDAccessor", "Missing reference.", true, "kar.test.missing"),
                        new KarDataFieldDefinition("nonPointerReference", 4, "s32", "Non-pointer reference.", false, "kar.test.invalid"),
                        new KarDataFieldDefinition("pastEnd", 8, "s32", "Past fixed size."),
                    },
                    8),
                new KarDataDefinition(
                    "kar.test.invalid",
                    "Duplicate Definition Id",
                    "Tests",
                    "OtherAccessor",
                    "Duplicate definition id.",
                    "tests",
                    new[] { new KarDataFieldDefinition("x00", 0, "s32", "Test field.") },
                    4),
                new KarDataDefinition(
                    "kar.test.other",
                    "Duplicate Accessor",
                    "Tests",
                    "InvalidAccessor",
                    "Duplicate accessor.",
                    "tests",
                    new[] { new KarDataFieldDefinition("x00", 0, "s32", "Test field.") },
                    4),
            });

            AssertTrue(!report.IsValid, "invalid schemas should fail validation");
            AssertIssue(report, "DuplicateDefinitionId");
            AssertIssue(report, "DuplicateAccessorTypeName");
            AssertIssue(report, "MissingReferenceDataDefinition");
            AssertIssue(report, "NonPointerReferenceField");
            AssertIssue(report, "FieldExceedsDefinitionSize");
        }

        private static void ProjectValidationIncludesSchemaPreflight()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-empty-project-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(tempRoot);

            try
            {
                KarProject project = KarProject.Open(tempRoot);
                KarValidationReport report = project.Validate(new KarValidationOptions
                {
                    InspectHsdArchives = false,
                    InspectA2DPackages = false,
                    ReportMissingMapModels = false,
                });

                AssertTrue(report.HasDataDefinitionValidation, "project validation should include schema preflight by default");
                AssertTrue(report.DataDefinitionValidation.DefinitionCount >= 32, "project schema preflight should inspect the active schema registry");
                AssertTrue(report.ErrorCount == report.Errors.Count + report.DataDefinitionValidation.ErrorCount, "project validation error count should include schema errors");
                AssertTrue(report.IsValid, "empty project with valid schemas should validate cleanly when archive scans are disabled");

                KarValidationReport reportWithoutSchemas = project.Validate(new KarValidationOptions
                {
                    InspectHsdArchives = false,
                    InspectA2DPackages = false,
                    ReportMissingMapModels = false,
                    ValidateDataDefinitions = false,
                });

                AssertTrue(!reportWithoutSchemas.HasDataDefinitionValidation, "schema preflight should be optional for focused callers");
                AssertTrue(reportWithoutSchemas.ErrorCount == reportWithoutSchemas.Errors.Count, "focused validation error count should omit skipped schema validation");
            }
            finally
            {
                Directory.Delete(tempRoot, true);
            }
        }

        private static void ProjectSchemaServiceExposesActiveProjectCatalogs()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-schema-service-project-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(tempRoot);

            try
            {
                KAR_vsLegendaryData customData = new KAR_vsLegendaryData();
                customData.x0C = 77;
                WriteHsdFile(Path.Combine(tempRoot, "Custom.dat"), "customRoot", customData);

                KarDataDefinition customDefinition = new KarDataDefinition(
                    "kar.test.custom",
                    "Custom Test Schema",
                    "Tests",
                    "KAR_vsLegendaryData",
                    "Custom scalar schema for project-level registry tests.",
                    "tests",
                    new[] { new KarDataFieldDefinition("x0C", 0x0C, "s32", "Custom scalar value.") },
                    0x14);
                KarProject project = KarProject.Open(new KarProjectOptions
                {
                    SourceRoot = tempRoot,
                    DataDefinitions = new KarDataDefinitionRegistry(new[] { customDefinition }),
                    ArchiveDefinitions = new TestArchiveDefinitionProvider(),
                });
                KarProjectSchemaService schema = project.SchemaService;

                AssertTrue(object.ReferenceEquals(schema.Project, project), "schema service should retain project context");
                AssertTrue(object.ReferenceEquals(schema.DataDefinitions, project.DataService.Definitions), "data service should expose the active project schema registry");
                AssertTrue(schema.DataDefinitions.All.Count == 1, "schema service should expose custom project schema registries");
                AssertTrue(schema.FileKinds.Count > 0 && schema.FileHandlers.Count > 0 && schema.ResourceHandlers.Count > 0, "schema service should expose active handler catalogs");
                AssertTrue(schema.ResourceActionDefinitions.Count >= 8 && schema.OperationDomainRules.Count >= 6 && schema.DomainContextProviders.Count >= 7 && schema.ToolkitWorkflowProviders.Count >= 1 && schema.OperationPresetDefinitions.Count >= 6, "schema service should expose active toolkit registry catalogs");
                KarProjectToolkitRegistryCatalog registryCatalog = schema.CreateToolkitRegistryCatalog();
                AssertTrue(object.ReferenceEquals(registryCatalog.Project, project), "toolkit registry catalog should retain project context");
                AssertTrue(registryCatalog.FileKindCount == schema.FileKinds.Count && registryCatalog.FileHandlerCount == schema.FileHandlers.Count && registryCatalog.ResourceHandlerCount == schema.ResourceHandlers.Count, "toolkit registry catalog should expose active handler counts");
                AssertTrue(registryCatalog.ResourceActionDefinitionCount == schema.ResourceActionDefinitions.Count && registryCatalog.OperationDomainRuleCount == schema.OperationDomainRules.Count && registryCatalog.DomainContextProviderCount == schema.DomainContextProviders.Count && registryCatalog.ToolkitWorkflowProviderCount == schema.ToolkitWorkflowProviders.Count && registryCatalog.OperationPresetDefinitionCount == schema.OperationPresetDefinitions.Count, "toolkit registry catalog should expose active action, context, workflow, and operation counts");
                KarProjectToolkitRegistryCatalogContract registryContract = registryCatalog.CreateContract();
                AssertTrue(registryContract.Project.Name == project.Name && registryContract.Project.Workspace.WritesOnlyToOutput, "toolkit registry contracts should expose project and workspace metadata");
                AssertTrue(registryContract.FileKindCount == registryCatalog.FileKindCount && registryContract.FileHandlers.Count == registryCatalog.FileHandlerCount, "toolkit registry contracts should preserve file registry counts");
                AssertTrue(registryContract.ResourceHandlers.Any(handler => handler.Actions.Any(action => action.Id == "dump-bytes")), "toolkit registry contracts should expose nested resource action metadata");
                AssertTrue(registryContract.DomainContextProviderCount == registryCatalog.DomainContextProviderCount && registryContract.DomainContextProviders.Any(provider => provider.Id == "maps" && provider.ContextCommand == "map-context"), "toolkit registry contracts should expose domain context provider metadata");
                AssertTrue(registryContract.ToolkitWorkflowProviderCount == registryCatalog.ToolkitWorkflowProviderCount && registryContract.ToolkitWorkflowProviders.Any(provider => provider.Id == "built-in-workflows"), "toolkit registry contracts should expose workflow provider metadata");
                AssertTrue(KarProjectToolkitRegistryCatalog.Default.ResourceActionDefinitionCount >= 8 && KarProjectToolkitRegistryCatalog.Default.DomainContextProviderCount >= 7 && KarProjectToolkitRegistryCatalog.Default.ToolkitWorkflowProviderCount >= 1 && KarProjectToolkitRegistryCatalog.Default.OperationPresetDefinitionCount >= 6, "default toolkit registry catalog should expose built-in action, context, workflow, and preset registries");
                AssertTrue(schema.QueryDataDefinitions(null).Single().Id == "kar.test.custom", "schema service should query active data definitions");
                AssertTrue(schema.QueryDataDefinitions(new KarDataDefinitionQueryOptions { Category = "Tests" }).Count == 1, "schema service should filter data definitions by category");
                AssertTrue(schema.QueryDataDefinitions(new KarDataDefinitionQueryOptions { Text = "scalar" }).Count == 1, "schema service should search data definition text");
                AssertTrue(project.GetDataDefinition("KAR_vsLegendaryData").Id == "kar.test.custom", "project data definition lookup should resolve active accessor types");

                KarProjectArchiveSchemaInfo archiveSchema = schema.GetArchiveSchema("Custom.dat");
                AssertTrue(archiveSchema.RelativePath == "Custom.dat", "archive schema info should keep file context");
                AssertTrue(archiveSchema.Category == "Tests", "archive schema info should expose archive definition metadata");
                AssertTrue(archiveSchema.RootDefinitionCount == 1 && archiveSchema.RequiredRootDefinitionCount == 1, "archive schema info should expose expected root counts");
                AssertTrue(archiveSchema.RootDefinitions[0].DataDefinitionId == "kar.test.custom", "archive schema info should expose expected root schema ids");
                AssertTrue(project.QueryArchiveSchemas(null).Single().RelativePath == "Custom.dat", "project archive schema wrapper should delegate to schema service");

                KarProjectRootInfo root = project.QueryRoots(null).Single();
                AssertTrue(root.DisplayName == "Custom Test Schema", "project roots should expose active schema display names");
                AssertTrue(root.Role == "Custom test root", "project roots should expose archive-specific root roles");
                AssertTrue(root.Category == "Tests", "project roots should expose active schema categories");
                AssertTrue(root.Description == "Custom scalar schema for project-level registry tests.", "project roots should expose active schema descriptions");
                AssertTrue(root.SchemaDisplayName == "Custom Test Schema", "project roots should expose schema display names separately");
                KarProjectRootSummary rootSummary = project.QueryRootSummaries(null).Single();
                AssertTrue(rootSummary.DisplayName == root.DisplayName && rootSummary.Role == root.Role, "project root summaries should retain schema labels");

                KarProjectDataDefinitionUsage usage = schema.QueryDataDefinitionUsage(null).Single();
                AssertTrue(usage.DataDefinitionId == "kar.test.custom" && usage.Count == 1, "schema service should query active schema usage");
                AssertTrue(usage.Roots.Single().DisplayName == "Custom Test Schema", "schema usage roots should carry schema labels");
                KarProjectResourceInfo resource = project.ResourceService.Get("Custom.dat:customRoot");
                AssertTrue(resource.DisplayName == "Custom Test Schema", "HSD root resources should use schema display names");
                AssertTrue(resource.Role == "Custom test root", "HSD root resources should use root roles");
                AssertTrue(resource.Description == "Custom scalar schema for project-level registry tests.", "HSD root resources should use schema descriptions");
                KarProjectFieldInfo field = project.QueryFieldValues(new KarProjectFieldQueryOptions
                {
                    DataDefinitionIdOrAccessorTypeName = "kar.test.custom",
                    FieldName = "x0C",
                }).Single();
                AssertTrue(field.Value.SignedValue == 77, "project field queries should read values through custom active schemas");
                AssertTrue(schema.ValidateDataDefinitions().IsValid && project.ValidateDataDefinitions().IsValid, "schema validation wrappers should validate active project schemas");
            }
            finally
            {
                Directory.Delete(tempRoot, true);
            }
        }

        private static void ProjectDataCoverageReportIdentifiesSchemaGaps()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-data-coverage-project-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(tempRoot);

            WriteHsdFile(Path.Combine(tempRoot, "VsHydra.dat"), "vsDataHydra", new KAR_vsLegendaryData());
            WriteHsdFile(Path.Combine(tempRoot, "VsMissing.dat"), "unexpectedRoot", new HSDAccessor { _s = new HSDStruct(4) });
            WriteHsdFile(Path.Combine(tempRoot, "EfDemo.dat"), "demo_texg", new HSDAccessor { _s = new HSDStruct(4) });
            WriteHsdFile(Path.Combine(tempRoot, "EfOther.dat"), "other_texg", new HSDAccessor { _s = new HSDStruct(4) });
            File.WriteAllBytes(Path.Combine(tempRoot, "VsBroken.dat"), new byte[] { 0x10 });

            try
            {
                KarProject project = KarProject.Open(tempRoot);
                KarProjectDataCoverageReport report = project.SchemaService.CreateDataCoverageReport();

                AssertTrue(report.ArchiveCount == 5, "data coverage should scan HSD archive contexts");
                AssertTrue(report.InspectableArchiveCount == 4 && report.InspectionErrorCount == 1, "data coverage should count inspection failures");
                AssertTrue(report.RootCount == 4 && report.KnownRootCount == 3 && report.UnknownRootCount == 1, "data coverage should count known and unknown roots");
                AssertTrue(report.DataDefinitionRootCount == 1 && report.FieldBackedRootCount == 1, "data coverage should count field-backed data definitions");
                AssertTrue(report.MissingDataDefinitionRootCount == 2, "data coverage should count known roots without KAR data definitions");
                AssertTrue(report.MissingRequiredRootCount == 1, "data coverage should count missing required roots");
                AssertTrue(report.IssueCount == 5 && report.IssueGroupCount == 4, "data coverage should report and group all schema gaps");
                AssertTrue(report.ArchiveInspectionIssueCount == 1, "data coverage should report archive inspection failures");
                AssertTrue(report.MissingRequiredRootIssueCount == 1, "data coverage should report missing required roots");
                AssertTrue(report.UnknownRootIssueCount == 1, "data coverage should report unknown roots");
                AssertTrue(report.MissingDataDefinitionIssueCount == 2, "data coverage should report known roots without data definitions");
                AssertTrue(!report.HasCompleteFieldCoverage, "data coverage should flag incomplete field coverage");
                AssertTrue(report.Issues.Any(issue => issue.RelativePath == "EfDemo.dat" && issue.RootName == "demo_texg" && issue.Kind == KarProjectDataCoverageIssueKind.MissingDataDefinition), "data coverage should retain root issue metadata");
                KarProjectDataCoverageIssueGroup missingDefinitionGroup = report.IssueGroups.Single(group => group.Kind == KarProjectDataCoverageIssueKind.MissingDataDefinition);
                AssertTrue(missingDefinitionGroup.DisplayName == "HSD_TEXGraphicBank" && missingDefinitionGroup.Count == 2 && missingDefinitionGroup.FileCount == 2, "data coverage should group repeated missing schema targets");
                AssertTrue(missingDefinitionGroup.RootNameCount == 2 && missingDefinitionGroup.RootNames.Contains("demo_texg") && missingDefinitionGroup.RootNames.Contains("other_texg"), "data coverage issue groups should retain contributing root names");
                AssertTrue(missingDefinitionGroup.MinStructLength == 4 && missingDefinitionGroup.MaxStructLength == 4 && missingDefinitionGroup.StructLengthHexes.Single() == "0x4", "data coverage issue groups should summarize contributing root struct sizes");
                AssertTrue(report.Issues.Single(issue => issue.RelativePath == "EfDemo.dat").StructLength == 4, "data coverage issues should expose root struct sizes");
                AssertTrue(project.CreateDataCoverageReport().IssueCount == report.IssueCount, "project data coverage wrapper should delegate to schema service");

                KarProjectDataCoverageReport filtered = project.CreateDataCoverageReport(new KarProjectDataCoverageOptions
                {
                    Archives = new KarProjectArchiveContextQueryOptions
                    {
                        Text = "texg",
                    },
                    Text = "texg",
                });
                AssertTrue(filtered.ArchiveCount == 2 && filtered.IssueCount == 2 && filtered.IssueGroupCount == 1 && filtered.MissingDataDefinitionIssueCount == 2, "data coverage options should filter archives and issues by text");
                AssertTrue(filtered.IssueGroups.Single().StructLengths.Single() == 4, "filtered data coverage issue groups should retain struct size summaries");

                KarProjectDataCoverageReport noUnknownRoots = project.CreateDataCoverageReport(new KarProjectDataCoverageOptions
                {
                    ReportUnknownRoots = false,
                });
                AssertTrue(noUnknownRoots.UnknownRootIssueCount == 0 && noUnknownRoots.IssueCount == 4, "data coverage options should allow callers to hide issue kinds");
            }
            finally
            {
                Directory.Delete(tempRoot, true);
            }
        }

        private static void FileKindRegistryDescribesProjectHandlers()
        {
            KarFileKindRegistry registry = KarFileKindRegistry.Default;
            KarProjectFileHandlerRegistry handlers = KarProjectFileHandlerRegistry.Default;
            int enumCount = Enum.GetValues(typeof(KarFileKind)).Length;
            AssertTrue(registry.Descriptors.Count == enumCount, "file kind registry should describe every public file kind");
            AssertTrue(handlers.Handlers.Count == enumCount, "file handler registry should provide every public file kind handler");

            KarFileKindMatch mapData = registry.Classify("GrCity1.dat");
            AssertTrue(mapData.Kind == KarFileKind.MapData, "registry should classify map data archives");
            AssertTrue(mapData.MapName == "City1", "registry should extract map data names");
            AssertTrue(mapData.Descriptor.IsHsdArchive, "map data should be marked as HSD archives");
            AssertTrue(mapData.Descriptor.MapBundleRole == "data", "map data should carry its map bundle role");
            KarProjectFileHandler mapDataHandler = handlers.GetHandler(mapData);
            AssertTrue(mapDataHandler.CanInspectHsdArchive, "map data handlers should support HSD archive inspection");
            AssertTrue(mapDataHandler.CanQueryHsdRoots, "map data handlers should support HSD root queries");
            AssertTrue(mapDataHandler.CanGroupWithMap && mapDataHandler.CanInspectMapArchive, "map data handlers should support map workflows");

            KarFileKindMatch mapModel = registry.Classify("GrCity1Model.dat");
            AssertTrue(mapModel.Kind == KarFileKind.MapModel && mapModel.MapName == "City1", "registry should classify map model archives and extract map names");

            KarFileKindMatch a2d = registry.Classify("A2a2dBG_000F.dat");
            AssertTrue(a2d.Kind == KarFileKind.A2dPackage, "registry should classify A2D packages");
            AssertTrue(a2d.Descriptor.IsA2DPackage && !a2d.Descriptor.IsHsdArchive, "A2D packages should be package resources instead of HSD archives");
            KarProjectFileHandler a2dHandler = handlers.GetHandler(a2d);
            AssertTrue(a2dHandler.CanOpenA2DPackage && a2dHandler.CanListA2DEntries, "A2D handlers should support package entry workflows");
            AssertTrue(a2dHandler.CanExtractA2DEntries && a2dHandler.CanReplaceA2DEntries, "A2D handlers should support safe entry output workflows");
            AssertTrue(!a2dHandler.CanInspectHsdArchive, "A2D handlers should not support HSD archive inspection");

            KarFileKindMatch effect = registry.Classify("A2EfCommon.dat");
            AssertTrue(effect.Kind == KarFileKind.EffectData && effect.Descriptor.IsHsdArchive, "A2Ef files should remain effect HSD archives");

            KarFileKindMatch script = registry.Classify("ScInfGo2D.tm");
            AssertTrue(script.Kind == KarFileKind.ScriptTable && script.Descriptor.IsScriptTable, "loose .tm files should be script table resources");
            AssertTrue(handlers.GetHandler(script).CanListScriptTables, "script table handlers should expose script table capability");

            KarFileKindDescriptor descriptor;
            AssertTrue(registry.TryFindDescriptor("map-data", out descriptor) && descriptor.Kind == KarFileKind.MapData, "registry should resolve descriptors by stable id");
            AssertTrue(registry.TryFindDescriptor("MapData", out descriptor) && descriptor.Id == "map-data", "registry should resolve descriptors by enum name");
            AssertTrue(!registry.IsHsdArchiveKind(KarFileKind.A2dPackage), "A2D packages should not be treated as HSD archives");

            string mapName;
            AssertTrue(registry.TryGetMapName("GrCity1Event.dat", KarFileKind.MapEvent, out mapName) && mapName == "City1", "registry should extract event map names");
            AssertTrue(!registry.TryGetMapName("A2Info.dat", KarFileKind.A2dPackage, out mapName), "non-map file kinds should not expose map names");
            AssertTrue(KarProjectFileClassifier.Classify("GrCity1.dat").Descriptor.Id == "map-data", "compatibility classifier should delegate to the registry");
            AssertTrue(KarArchiveCatalog.GetHandler(KarFileKind.MapData).Id == "map-data", "archive catalog compatibility wrappers should expose file handlers");
        }

        private static void ResourceHandlerRegistryDescribesResourceOperations()
        {
            KarProjectResourceHandlerRegistry registry = KarProjectResourceHandlerRegistry.Default;
            int enumCount = Enum.GetValues(typeof(KarResourceKind)).Length;
            AssertTrue(registry.Handlers.Count == enumCount, "resource handler registry should describe every public resource kind");

            KarProjectResourceHandler fileHandler = registry.GetHandler(KarResourceKind.File);
            AssertTrue(fileHandler.Id == "file", "file resource handlers should expose stable ids");
            AssertTrue(fileHandler.CanReadBytes && fileHandler.CanExportToOutput && fileHandler.CanImportFromFile, "file resources should support byte and output workflows");
            AssertTrue(!fileHandler.CanSetScalarFields && !fileHandler.CanApplyOutput, "file resources should not expose root or sidecar-only workflows");
            AssertTrue(fileHandler.ActionCount == 5 && fileHandler.Actions.Any(action => action.Id == "import-file" && action.RequiresInputFile), "file resource handlers should expose import action metadata");

            KarProjectResourceHandler rootHandler = registry.GetHandler(KarResourceKind.HsdRoot);
            AssertTrue(rootHandler.CanQueryFieldValues && rootHandler.CanSetScalarFields, "HSD root resources should support field and scalar workflows");
            AssertTrue(rootHandler.CanReadBytes && rootHandler.CanExportToOutput && !rootHandler.CanImportFromFile, "HSD root resources should expose struct byte reads and stage containing archives without standalone byte imports");
            AssertTrue(rootHandler.Actions.Any(action => action.Id == "set-scalar" && action.RequiresFieldName && action.RequiresValue && action.Command == "set-resource-scalar"), "HSD root handlers should expose scalar edit action metadata");

            KarProjectResourceHandler entryHandler = registry.GetHandler(KarResourceKind.A2DEntry);
            AssertTrue(entryHandler.CanReadBytes && entryHandler.CanImportFromFile, "A2D entry resources should support byte reads and imports");
            AssertTrue(entryHandler.CanApplyOutput && !entryHandler.CanSetScalarFields, "A2D entry resources should support sidecar apply but not scalar edits");
            AssertTrue(entryHandler.Actions.Any(action => action.Id == "apply-output" && action.SupportsBatch && action.WritesOutput), "A2D entry handlers should expose apply action metadata");

            KarProjectResourceHandler found;
            AssertTrue(registry.TryFindHandler("a2d-entry", out found) && found.Kind == KarResourceKind.A2DEntry, "resource handlers should resolve by stable id");
            AssertTrue(registry.TryFindHandler("HsdRoot", out found) && found.Id == "hsd-root", "resource handlers should resolve by enum name");

            KarProjectResourceActionDefinition dumpDefinition = registry.ActionRegistry.FindDefinition("dump-bytes");
            AssertTrue(dumpDefinition.Command == "dump-resource-bytes" && dumpDefinition.SupportsBatch, "resource action registries should expose reusable action definitions");
            AssertTrue(dumpDefinition.ExecutionKind == KarProjectResourceActionExecutionKind.DumpBytes && dumpDefinition.RequiresByteInfo && dumpDefinition.WritePolicy == KarProjectResourceActionWritePolicy.MissingByteDump, "resource action definitions should describe execution, planning state, and write policy");

            KarProjectResourceActionRegistry customActions = new KarProjectResourceActionRegistry(
                KarProjectResourceActionRegistry.BuiltInDefinitions.Select(definition =>
                    definition.Id == "dump-bytes"
                        ? new KarProjectResourceActionDefinition(
                            definition.Id,
                            "Custom Dump Bytes",
                            definition.Description,
                            definition.Capability,
                            definition.Command,
                            definition.ArgumentHint,
                            definition.IsReadOnly,
                            definition.WritesOutput,
                            definition.RequiresInputFile,
                            definition.RequiresFieldName,
                            definition.RequiresValue,
                            definition.SupportsBatch,
                            definition.ExecutionKind,
                            definition.PlanStateKind,
                            definition.WritePolicy)
                        : definition)
                    .Concat(new[]
                    {
                        new KarProjectResourceActionDefinition(
                            "custom-dump-bytes",
                            "Custom Dump Alias",
                            "Caller-owned byte dump action id.",
                            KarProjectResourceCapability.ReadBytes,
                            "custom-dump-resource-bytes",
                            "[resource-address]",
                            isReadOnly: false,
                            writesOutput: true,
                            requiresInputFile: false,
                            requiresFieldName: false,
                            requiresValue: false,
                            supportsBatch: true,
                            executionKind: KarProjectResourceActionExecutionKind.DumpBytes,
                            planStateKind: KarProjectResourceActionPlanStateKind.Bytes,
                            writePolicy: KarProjectResourceActionWritePolicy.MissingByteDump),
                    }));
            KarProjectResourceHandlerRegistry customHandlers = KarProjectResourceHandlerRegistry.CreateDefault(customActions);
            AssertTrue(customHandlers.GetHandler(KarResourceKind.File).Actions.Any(action => action.Id == "dump-bytes" && action.DisplayName == "Custom Dump Bytes"), "resource handler registries should use caller-provided action metadata");
            AssertTrue(customHandlers.GetHandler(KarResourceKind.File).Actions.Any(action => action.Id == "custom-dump-bytes" && action.ExecutionKind == KarProjectResourceActionExecutionKind.DumpBytes), "resource handler registries should support caller-owned action ids with known execution kinds");

            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-custom-action-registry-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);
            try
            {
                File.WriteAllBytes(Path.Combine(tempRoot, "ScInfPause.tm"), new byte[] { 0x40 });
                KarProject project = KarProject.Open(new KarProjectOptions
                {
                    SourceRoot = tempRoot,
                    OutputRoot = outputRoot,
                    ResourceActionRegistry = customActions,
                });
                KarProjectResourceActionPlan plan = project.GetResourceActionPlan("ScInfPause.tm", "dump-bytes");
                AssertTrue(object.ReferenceEquals(project.ResourceActionRegistry, customActions), "project options should expose custom resource action registries");
                AssertTrue(project.SchemaService.ResourceActionDefinitions.Any(definition => definition.Id == "custom-dump-bytes"), "schema service should expose custom resource action definitions");
                AssertTrue(project.CreateToolkitRegistryCatalog().ResourceActionDefinitions.Any(definition => definition.Id == "custom-dump-bytes"), "toolkit registry catalog should expose custom resource action definitions");
                AssertTrue(plan.Action.DisplayName == "Custom Dump Bytes" && plan.Action.RequiresByteInfo && plan.Action.WritePolicy == KarProjectResourceActionWritePolicy.MissingByteDump && plan.CanRun && plan.WouldWriteOutput, "custom resource action metadata should flow into project action plans");
                KarProjectResourceActionExecutionResult aliasResult = project.ExecuteResourceAction("ScInfPause.tm", "custom-dump-bytes");
                AssertTrue(aliasResult.ActionId == "custom-dump-bytes" && aliasResult.ResultKind == "byte-dump" && aliasResult.WroteOutput, "custom resource action ids should execute through their declared execution kind");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectFileQueryFiltersFiles()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-query-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            string filesRoot = Path.Combine(tempRoot, "files");
            Directory.CreateDirectory(filesRoot);
            Directory.CreateDirectory(Path.Combine(filesRoot, "audio"));

            File.WriteAllBytes(Path.Combine(filesRoot, "GrCity1.dat"), new byte[] { 0 });
            File.WriteAllBytes(Path.Combine(filesRoot, "A2Demo.dat"), new byte[] { 0 });
            File.WriteAllBytes(Path.Combine(filesRoot, "audio", "test.hps"), new byte[] { 0 });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectFileService files = project.FileService;

                AssertTrue(object.ReferenceEquals(files.Project, project), "file service should retain project context");
                AssertTrue(files.Files.Count == project.Files.Count, "file service should expose indexed project files");
                AssertTrue(files.ByPath.ContainsKey("GrCity1.dat"), "file service should expose file lookup index");
                AssertTrue(files.Get("GrCity1.dat").Kind == KarFileKind.MapData, "file service should resolve project files by path");
                AssertTrue(files.Get("GrCity1.dat").KindId == "map-data", "project files should expose stable file kind ids");
                AssertTrue(files.Get("GrCity1.dat").IsHsdArchive && files.Get("GrCity1.dat").MapBundleRole == "data", "project files should expose file kind traits");
                AssertTrue(files.Get("GrCity1.dat").MapName == "City1", "project files should expose path-specific map names");
                AssertTrue(files.Get("GrCity1.dat").CanInspectHsdArchive && files.Get("GrCity1.dat").CanGroupWithMap, "project files should expose handler capabilities");
                KarProjectFile tryFile;
                AssertTrue(files.TryGet("A2Demo.dat", out tryFile), "file service should try-resolve project files by path");
                AssertTrue(tryFile.Kind == KarFileKind.A2dPackage, "file service try-get should return project file metadata");
                AssertTrue(tryFile.IsA2DPackage && !tryFile.IsHsdArchive, "A2D project files should expose package traits");
                AssertTrue(tryFile.CanOpenA2DPackage && tryFile.CanListA2DEntries, "A2D project files should expose package handler capabilities");
                AssertTrue(files.GetSourcePath("GrCity1.dat") == Path.Combine(filesRoot, "GrCity1.dat"), "file service should resolve source paths");
                AssertTrue(files.GetOutputPath("GrCity1.dat") == Path.Combine(outputRoot, "files", "GrCity1.dat"), "file service should resolve output paths");
                AssertTrue(files.GetReadPath("GrCity1.dat") == files.GetSourcePath("GrCity1.dat"), "file service should read from source before output copies exist");

                AssertTrue(files.Query(new KarProjectFileQueryOptions { Kind = KarFileKind.MapData }).Count == 1, "file query should filter by kind");
                AssertTrue(files.Query(new KarProjectFileQueryOptions { Category = "maps" }).Count == 1, "file query should filter by category case-insensitively");
                AssertTrue(files.Query(new KarProjectFileQueryOptions { Domain = "maps" }).Single().RelativePath == "GrCity1.dat", "file query should filter by toolkit domain");
                AssertTrue(files.Query(new KarProjectFileQueryOptions { Domain = "a2d" }).Single().RelativePath == "A2Demo.dat", "file query should normalize toolkit domain aliases");
                AssertTrue(files.Query(new KarProjectFileQueryOptions { Domain = "archives" }).Single().RelativePath == "GrCity1.dat", "file query should filter HSD archive domains");
                AssertTrue(files.Query(new KarProjectFileQueryOptions { Domain = "script-tables" }).Count == 0, "file query should return empty domain matches safely");
                IReadOnlyList<KarProjectFile> mapDescriptionFiles = files.Query(new KarProjectFileQueryOptions { Text = "map gameplay" });
                AssertTrue(mapDescriptionFiles.Count == 1 && mapDescriptionFiles[0].RelativePath == "GrCity1.dat", "file query should search metadata text");
                AssertTrue(files.Query(new KarProjectFileQueryOptions { HasOutputCopy = true }).Count == 0, "file query should filter files with output copies");

                KarProjectFileCopyResult copyResult = files.CopyFileToOutput("GrCity1.dat", true);

                AssertTrue(copyResult.File.RelativePath == "GrCity1.dat", "file service should return copied file metadata");
                AssertTrue(File.Exists(copyResult.OutputPath), "file service should copy project files to output");
                AssertTrue(files.GetReadPath("GrCity1.dat") == files.GetOutputPath("GrCity1.dat"), "file service should read from output after copies exist");
                AssertTrue(project.OutputService.GetFile("GrCity1.dat").CanInspectMapArchive, "output file records should expose handler capabilities");
                AssertTrue(files.Query(new KarProjectFileQueryOptions { Domain = "mod-output" }).Single().RelativePath == "GrCity1.dat", "file query should filter output-domain files");
                AssertTrue(files.Query(new KarProjectFileQueryOptions { HasOutputCopy = true }).Count == 1, "file query should see newly created output copies");
                AssertTrue(files.Query(new KarProjectFileQueryOptions { HasOutputCopy = false }).Count == project.Files.Count - 1, "file query should filter source-only files");
                AssertTrue(files.Query(new KarProjectFileQueryOptions
                {
                    Kind = KarFileKind.MapData,
                    HasOutputCopy = true,
                }).Count == 1, "file query should combine filters");

                byte[] sourceBytes = files.ReadBytes("GrCity1.dat");
                AssertTrue(sourceBytes.Length == 1 && sourceBytes[0] == 0, "file service should read bytes through the active read path");
                KarProjectFileWriteResult writeResult = files.WriteFileBytes("A2Demo.dat", new byte[] { 0x44, 0x55 });
                AssertTrue(writeResult.RelativePath == "A2Demo.dat", "file service should return write metadata");
                AssertTrue(File.Exists(writeResult.OutputPath), "file service should write bytes to output");
                AssertTrue(files.ReadBytes("A2Demo.dat").SequenceEqual(new byte[] { 0x44, 0x55 }), "file service reads should prefer newly written output bytes");

                AssertTrue(project.QueryFiles(new KarProjectFileQueryOptions { Kind = KarFileKind.MapData }).Count == files.Query(new KarProjectFileQueryOptions { Kind = KarFileKind.MapData }).Count, "project file query compatibility wrapper should delegate to file service");
                AssertTrue(object.ReferenceEquals(project.GetFile("GrCity1.dat"), files.Get("GrCity1.dat")), "project file get compatibility wrapper should delegate to file service");
                AssertTrue(project.GetReadPath("A2Demo.dat") == files.GetReadPath("A2Demo.dat"), "project read path compatibility wrapper should delegate to file service");
                AssertTrue(project.CopyToOutput("GrCity1.dat", true) == files.GetOutputPath("GrCity1.dat"), "project copy compatibility wrapper should delegate to file service");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
                if (Directory.Exists(outputRoot + "_custom"))
                    Directory.Delete(outputRoot + "_custom", true);
            }
        }

        private static void ResourceReferencesAddressProjectObjects()
        {
            KarResourceReference fileReference = KarResourceReference.Parse("maps\\GrCity1.dat");
            AssertTrue(fileReference.Kind == KarResourceKind.File, "resource reference parser should classify plain paths as files");
            AssertTrue(fileReference.Address == "maps/GrCity1.dat", "resource reference parser should normalize project paths");
            AssertTrue(fileReference.ParentAddress == null, "file resource references should not have parent addresses");

            KarResourceReference rootReference = KarResourceReference.Parse("VsHydra.dat:vsDataHydra");
            AssertTrue(rootReference.Kind == KarResourceKind.HsdRoot, "resource reference parser should classify root addresses");
            AssertTrue(rootReference.RelativePath == "VsHydra.dat", "root resource references should expose archive paths");
            AssertTrue(rootReference.RootName == "vsDataHydra", "root resource references should expose root names");
            AssertTrue(rootReference.Address == "VsHydra.dat:vsDataHydra", "root resource references should preserve address syntax");

            KarResourceReference entryReference = KarResourceReference.Parse("A2Info.dat#ScInfGo2D.tm");
            AssertTrue(entryReference.Kind == KarResourceKind.A2DEntry, "resource reference parser should classify A2D entry addresses");
            AssertTrue(entryReference.EntryName == "ScInfGo2D.tm", "A2D resource references should expose entry names");
            AssertTrue(entryReference.ParentAddress == "A2Info.dat", "A2D resource references should expose package parent addresses");
            AssertTrue(entryReference.Equals(KarResourceReference.A2DEntry("a2info.dat", "scinfgo2d.tm")), "A2D resource references should compare paths and entries case-insensitively");

            KarResourceReference invalidReference;
            AssertTrue(!KarResourceReference.TryParse("../bad.dat", out invalidReference), "resource references should reject path traversal");
            AssertTrue(!KarResourceReference.TryParse("A2Info.dat#", out invalidReference), "resource references should reject missing subresource names");

            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-resource-reference-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            WriteHsdFile(Path.Combine(tempRoot, "VsHydra.dat"), "vsDataHydra", new KAR_vsLegendaryData());
            WriteA2DPackage(Path.Combine(tempRoot, "A2Info.dat"), new[] { "ScInfGo2D.tm", "readme.bin" });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);

                KarProjectFile file = project.FileService.Get("VsHydra.dat");
                AssertTrue(file.ResourceAddress == "VsHydra.dat", "project files should expose resource addresses");
                AssertTrue(file.ResourceReference.Equals(KarResourceReference.File("VsHydra.dat")), "project files should expose file resource references");

                KarProjectRootInfo root = project.DataService.QueryRoots(new KarProjectRootQueryOptions
                {
                    RootName = "vsDataHydra",
                }).Single();
                AssertTrue(root.RootPath == "VsHydra.dat:vsDataHydra", "project roots should expose archive-root resource addresses");
                AssertTrue(root.ResourceReference.Equals(rootReference), "project roots should expose parse-compatible resource references");

                KarProjectA2DEntryInfo entry = project.A2DService.GetEntry("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(entry.EntryPath == "A2Info.dat#ScInfGo2D.tm", "A2D entries should expose package-entry resource addresses");
                AssertTrue(entry.ResourceReference.Equals(entryReference), "A2D entries should expose parse-compatible resource references");

                KarProjectResourceInfo fileResource = project.ResourceService.Get("VsHydra.dat");
                AssertTrue(fileResource.HandlerId == "file" && fileResource.CanReadBytes && fileResource.CanImportFromFile, "file resources should expose file handler capabilities");
                KarProjectResourceInfo rootResource = project.ResourceService.Get("VsHydra.dat:vsDataHydra");
                AssertTrue(rootResource.HandlerId == "hsd-root" && rootResource.CanQueryFieldValues && rootResource.CanSetScalarFields, "HSD root resources should expose root handler capabilities");
                KarProjectResourceInfo entryResource = project.ResourceService.Get("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(entryResource.HandlerId == "a2d-entry" && entryResource.CanReadBytes && entryResource.CanApplyOutput, "A2D entry resources should expose entry handler capabilities");

                KarProjectResolvedResource resolvedFile = project.ResourceAddressService.Resolve("VsHydra.dat");
                AssertTrue(resolvedFile.IsFile && !resolvedFile.IsScriptTable && resolvedFile.Resource.Address == fileResource.Address, "resource address service should resolve file addresses");
                KarProjectResolvedResource resolvedRoot = project.ResolveResourceAddress("VsHydra.dat:vsDataHydra");
                AssertTrue(resolvedRoot.IsHsdRoot && resolvedRoot.Root.RootName == "vsDataHydra", "project resource address wrapper should resolve HSD roots");
                AssertTrue(resolvedRoot.HasDataDefinition && resolvedRoot.DataDefinitionId == "kar.vs.legendary", "resolved HSD roots should expose data definitions");
                KarProjectResolvedResourceDetail resolvedRootDetail = project.GetResolvedResourceDetail("VsHydra.dat:vsDataHydra");
                AssertTrue(resolvedRootDetail.HasDataDefinition && resolvedRootDetail.DataDefinition.DisplayName == "Legendary Machine Versus Data", "resolved resource details should expose root schemas");
                AssertTrue(resolvedRootDetail.FieldCount >= 5, "resolved resource details should expose root fields");
                AssertTrue(resolvedRootDetail.HasByteInfo && resolvedRootDetail.ByteInfo.ActiveLength > 0, "resolved resource details should expose active byte info");
                IReadOnlyList<KarProjectResourceFieldInfo> resolvedFields = project.QueryResolvedResourceFieldValues("VsHydra.dat:vsDataHydra");
                AssertTrue(resolvedFields.Count == resolvedRootDetail.FieldCount, "resolved resource field queries should match resolved detail fields");
                AssertTrue(project.GetResolvedResourceFieldValue("VsHydra.dat:vsDataHydra", "x0C").FieldName == "x0C", "resolved resource field lookups should find root fields");
                KarProjectResolvedResource resolvedScript = project.ResolveResourceAddress("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(resolvedScript.IsA2DEntry && resolvedScript.IsScriptTable, "resource address resolution should identify script-table entries");
                AssertTrue(resolvedScript.ScriptTable.Role == "ScreenInfoTable" && resolvedScript.IsPackageScriptTable, "resolved script tables should expose script metadata");
                KarProjectResolvedResourceDetail resolvedScriptDetail = project.ResourceAddressService.GetDetail("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(resolvedScriptDetail.Resolved.IsScriptTable && !resolvedScriptDetail.HasDataDefinition, "resolved script table details should keep script metadata separate from root schemas");
                AssertTrue(resolvedScriptDetail.RelationshipCount == 1 && resolvedScriptDetail.FieldCount == 0, "resolved script table details should expose relationships without root fields");
                AssertTrue(resolvedScriptDetail.ByteInfo.ActiveLength == 4, "resolved script table details should expose packaged entry bytes");
                AssertTrue(project.QueryResolvedResourceFieldValues("A2Info.dat#ScInfGo2D.tm").Count == 0, "resolved non-root field queries should be empty");
                IReadOnlyList<KarProjectResolvedResource> scriptResolved = project.QueryResolvedResources(new KarProjectResourceQueryOptions
                {
                    Category = "Scripts",
                });
                AssertTrue(scriptResolved.Count == 1 && scriptResolved[0].IsScriptTable, "resolved resource queries should enrich script table resources");
                KarProjectResolvedResource missingResolved;
                AssertTrue(!project.TryResolveResourceAddress("../bad.dat", out missingResolved), "project resource address try-resolve should reject invalid addresses");

                KarProjectRelationship relationship = project.RelationshipService.Query(new KarProjectRelationshipQueryOptions
                {
                    RelativePath = "A2Info.dat#ScInfGo2D.tm",
                }).Single();
                AssertTrue(relationship.ResourceReference.Equals(entryReference), "relationships should expose resource references for package entries");
                AssertTrue(relationship.RelativePath == relationship.ResourceReference.Address, "relationship relative paths should mirror resource addresses");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectResourceGraphIndexesResourcesAndRelationships()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-resource-graph-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            KAR_grData city = new KAR_grData();
            city.Unknown1 = 101;
            WriteHsdFile(Path.Combine(tempRoot, "GrCity1.dat"), "grDataCity1", city);
            File.WriteAllBytes(Path.Combine(tempRoot, "GrCity1Model.dat"), new byte[] { 0x20 });
            File.WriteAllBytes(Path.Combine(tempRoot, "GrCity1Event.dat"), new byte[] { 0x30 });
            File.WriteAllBytes(Path.Combine(tempRoot, "ScInfPause.tm"), new byte[] { 0x40 });
            WriteA2DPackage(Path.Combine(tempRoot, "A2Info.dat"), new[] { "ScInfGo2D.tm", "readme.bin" });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                AssertTrue(!project.ResourceGraphService.HasSnapshot, "resource graph services should start without a cached snapshot");
                KarProjectResourceGraph graph = project.ResourceGraphService.Snapshot;
                AssertTrue(project.ResourceGraphService.HasSnapshot, "resource graph services should cache the first snapshot");
                AssertTrue(object.ReferenceEquals(graph, project.CreateResourceGraph()), "project resource graph compatibility wrapper should return the cached snapshot");
                AssertTrue(object.ReferenceEquals(graph, project.ResourceGraphService.Snapshot), "resource graph services should reuse cached snapshots");
                AssertTrue(!object.ReferenceEquals(graph, project.RefreshResourceGraph()), "resource graph services should refresh snapshots on request");
                graph = project.ResourceGraphService.Snapshot;

                AssertTrue(object.ReferenceEquals(graph.Project, project), "resource graphs should retain project context");
                AssertTrue(graph.FileCount == project.FileService.Files.Count, "resource graphs should index project files");
                AssertTrue(graph.HsdRootCount == 1, "resource graphs should index inspectable HSD roots");
                AssertTrue(graph.A2DEntryCount == 2, "resource graphs should index A2D package entries");
                AssertTrue(graph.ResourceCount == graph.FileCount + graph.HsdRootCount + graph.A2DEntryCount, "resource graph counts should describe indexed resources");
                AssertTrue(graph.ResourcesByAddress.ContainsKey("GrCity1.dat:grDataCity1"), "resource graphs should expose address lookup dictionaries");
                AssertTrue(graph.GetResource("A2Info.dat#ScInfGo2D.tm").IsA2DEntry, "resource graphs should resolve A2D entry addresses");

                IReadOnlyList<KarProjectResourceInfo> packageChildren = graph.QueryChildResources("A2Info.dat");
                AssertTrue(packageChildren.Count == 2 && packageChildren.All(resource => resource.IsA2DEntry), "resource graphs should expose package child resources");
                AssertTrue(graph.QueryChildResources("GrCity1.dat").Single().Address == "GrCity1.dat:grDataCity1", "resource graphs should expose HSD root child resources");

                IReadOnlyList<KarProjectResourceInfo> scriptResources = graph.QueryResources(new KarProjectResourceQueryOptions
                {
                    Kind = KarResourceKind.A2DEntry,
                    Category = "Scripts",
                });
                AssertTrue(scriptResources.Count == 1 && scriptResources[0].Address == "A2Info.dat#ScInfGo2D.tm", "resource graph queries should filter resources");
                AssertTrue(project.ResourceService.Query(new KarProjectResourceQueryOptions
                {
                    Address = "A2Info.dat#ScInfGo2D.tm",
                    Kind = KarResourceKind.A2DEntry,
                }).Single().Address == "A2Info.dat#ScInfGo2D.tm", "resource services should query through the resource graph");

                IReadOnlyList<KarProjectRelationship> mapRelationships = graph.QueryRelationships(new KarProjectRelationshipQueryOptions
                {
                    MapName = "City1",
                });
                AssertTrue(mapRelationships.Count == 3, "resource graphs should retain map bundle relationships");

                IReadOnlyList<KarProjectRelationship> screenInfoTables = graph.QueryRelationships(new KarProjectRelationshipQueryOptions
                {
                    Role = "ScreenInfoTable",
                });
                AssertTrue(screenInfoTables.Count == 2, "resource graphs should retain loose and packaged script table relationships");
                AssertTrue(graph.QueryResourceRelationships("A2Info.dat#ScInfGo2D.tm").Single().Role == "ScreenInfoTable", "resource graphs should query relationships by resource address");
                AssertTrue(project.RelationshipService.QueryMap("City1").Count == 3, "relationship services should query through the resource graph");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectResourceServiceQueriesAndResolvesAddresses()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-resource-service-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            WriteHsdFile(Path.Combine(tempRoot, "VsHydra.dat"), "vsDataHydra", new KAR_vsLegendaryData());
            WriteA2DPackage(Path.Combine(tempRoot, "A2Info.dat"), new[] { "ScInfGo2D.tm", "readme.bin" });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectResourceService resources = project.ResourceService;

                AssertTrue(object.ReferenceEquals(resources.Project, project), "resource service should retain project context");

                IReadOnlyList<KarProjectResourceInfo> all = resources.Query();
                AssertTrue(all.Any(resource => resource.Address == "VsHydra.dat" && resource.Kind == KarResourceKind.File), "resource query should include project files");
                AssertTrue(all.Any(resource => resource.Address == "VsHydra.dat:vsDataHydra" && resource.Kind == KarResourceKind.HsdRoot), "resource query should include HSD roots");
                AssertTrue(all.Any(resource => resource.Address == "A2Info.dat#ScInfGo2D.tm" && resource.Kind == KarResourceKind.A2DEntry), "resource query should include A2D package entries");

                IReadOnlyList<KarProjectResourceInfo> fileResources = resources.Query(new KarProjectResourceQueryOptions
                {
                    Kind = KarResourceKind.File,
                });
                AssertTrue(fileResources.Count == 2 && fileResources.All(resource => resource.IsFile), "resource query should filter by resource kind");

                IReadOnlyList<KarProjectResourceInfo> scriptResources = resources.Query(new KarProjectResourceQueryOptions
                {
                    Category = "Scripts",
                });
                AssertTrue(scriptResources.Count == 1 && scriptResources[0].Address == "A2Info.dat#ScInfGo2D.tm", "resource query should filter by resource category");
                AssertTrue(resources.Query(new KarProjectResourceQueryOptions { Domain = "files" }).Count == 2, "resource query should filter file-domain resources");
                IReadOnlyList<KarProjectResourceInfo> a2dDomainResources = resources.Query(new KarProjectResourceQueryOptions { Domain = "a2d" });
                AssertTrue(a2dDomainResources.Count == 3 && a2dDomainResources.Any(resource => resource.Address == "A2Info.dat#ScInfGo2D.tm"), "resource query should filter A2D package domains");
                IReadOnlyList<KarProjectResourceInfo> scriptDomainResources = resources.Query(new KarProjectResourceQueryOptions { Domain = "scripts" });
                AssertTrue(scriptDomainResources.Count == 1 && scriptDomainResources[0].Address == "A2Info.dat#ScInfGo2D.tm", "resource query should filter script-table domains");

                IReadOnlyList<KarProjectResourceInfo> legendaryResources = resources.Query(new KarProjectResourceQueryOptions
                {
                    Text = "legendary",
                });
                AssertTrue(legendaryResources.Any(resource => resource.Address == "VsHydra.dat"), "resource text search should match file descriptions");
                AssertTrue(legendaryResources.Any(resource => resource.Address == "VsHydra.dat:vsDataHydra"), "resource text search should match schema labels");

                IReadOnlyList<KarProjectResourceInfo> screenInfoResources = project.QueryResources(new KarProjectResourceQueryOptions
                {
                    Text = "screen information",
                });
                AssertTrue(screenInfoResources.Count == 1 && screenInfoResources[0].Address == "A2Info.dat#ScInfGo2D.tm", "resource text search should match A2D entry descriptions");

                KarProjectResourceInfo rootResource = resources.Get("VsHydra.dat:vsDataHydra");
                AssertTrue(rootResource.IsHsdRoot, "resource get should resolve HSD root addresses");
                AssertTrue(rootResource.Root.RootName == "vsDataHydra", "resolved HSD root resources should expose root metadata");
                AssertTrue(rootResource.File.RelativePath == "VsHydra.dat", "resolved HSD root resources should expose parent file metadata");
                AssertTrue(rootResource.Actions.Any(action => action.Id == "set-scalar" && action.Command == "set-resource-scalar"), "resources should expose action metadata through handlers");

                KarProjectResourceDetail fileDetail = resources.GetDetail("VsHydra.dat");
                AssertTrue(fileDetail.Address == "VsHydra.dat" && fileDetail.Kind == KarResourceKind.File, "resource details should retain resource identity");
                AssertTrue(fileDetail.Output.Status == KarProjectResourceOutputStatus.Missing, "resource details should include output status");
                AssertTrue(fileDetail.HasByteInfo && fileDetail.ByteInfo.ActiveLength == File.ReadAllBytes(fileDetail.Resource.File.SourcePath).Length, "resource details should include active file byte info");
                AssertTrue(fileDetail.ActionCount == fileDetail.Resource.ActionCount && fileDetail.Actions.Any(action => action.Id == "dump-bytes"), "resource details should expose resource action metadata");
                AssertTrue(fileDetail.ChildResourceCount == 1 && fileDetail.ChildResources[0].Address == "VsHydra.dat:vsDataHydra", "resource details should include child resources");
                AssertTrue(fileDetail.FieldCount == 0, "file resource details should not report HSD fields directly");

                KarProjectResourceDetail rootDetail = project.GetResourceDetail("VsHydra.dat:vsDataHydra");
                AssertTrue(rootDetail.Resource.DisplayName == "Legendary Machine Versus Data", "project resource detail wrapper should expose labeled root resources");
                AssertTrue(rootDetail.FieldCount >= 5, "root resource details should include schema field values");
                AssertTrue(rootDetail.ByteInfo.Status == KarProjectResourceByteOutputStatus.Missing && rootDetail.ByteInfo.ActiveLength > 0, "root resource details should include root byte dump status");
                AssertTrue(rootDetail.ChildResourceCount == 0, "root resource details should only include direct child resources");
                KarProjectResourceActionPlan rootDumpPlan = resources.GetActionPlan("VsHydra.dat:vsDataHydra", "dump-bytes");
                AssertTrue(rootDumpPlan.CanRun && rootDumpPlan.WouldWriteOutput && rootDumpPlan.ByteStatus == KarProjectResourceByteOutputStatus.Missing, "resource action plans should preview missing byte dumps");
                KarProjectResourceActionPlan scalarPlan = project.GetResourceActionPlan("VsHydra.dat:vsDataHydra", "set-scalar");
                AssertTrue(!scalarPlan.CanRun && scalarPlan.WouldWriteOutput && scalarPlan.RequiresFieldName && scalarPlan.RequiresValue, "resource action plans should flag required scalar edit inputs");
                IReadOnlyList<KarProjectResourceDetail> rootDetails = project.QueryResourceDetails(new KarProjectResourceQueryOptions
                {
                    Kind = KarResourceKind.HsdRoot,
                });
                AssertTrue(rootDetails.Count == 1 && rootDetails[0].Address == "VsHydra.dat:vsDataHydra", "project resource detail queries should filter roots");
                AssertTrue(rootDetails[0].HasByteInfo && rootDetails[0].FieldCount >= 5, "project resource detail queries should include byte and schema context");

                KarProjectResourceInfo entryResource = project.GetResource("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(entryResource.IsA2DEntry, "project resource wrapper should resolve A2D entry addresses");
                AssertTrue(entryResource.A2DEntry.Index == 0, "resolved A2D resources should expose entry metadata");
                KarProjectResourceDetail entryDetail = resources.GetDetail("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(entryDetail.ByteInfo.ActiveLength == 4 && entryDetail.ByteInfo.Status == KarProjectResourceByteOutputStatus.Missing, "A2D entry resource details should include entry byte dump status");
                AssertTrue(entryDetail.RelationshipCount == 1 && entryDetail.Relationships[0].Role == "ScreenInfoTable", "resource details should include graph relationships");
                IReadOnlyList<KarProjectResourceDetail> scriptDetails = resources.QueryDetails(new KarProjectResourceQueryOptions
                {
                    Category = "Scripts",
                });
                AssertTrue(scriptDetails.Count == 1 && scriptDetails[0].Address == "A2Info.dat#ScInfGo2D.tm", "resource detail queries should filter by category");
                AssertTrue(scriptDetails[0].ByteInfo.ActiveLength == 4 && scriptDetails[0].RelationshipCount == 1, "resource detail queries should include byte and relationship context");
                AssertTrue(project.QueryResources(new KarProjectResourceQueryOptions
                {
                    Address = "A2Info.dat#ScInfGo2D.tm",
                }).Single().Address == entryResource.Address, "project resource query wrapper should filter by address");

                IReadOnlyList<KarProjectResolvedResourceDetail> resolvedScriptDetails = project.QueryResolvedResourceDetails(new KarProjectResourceQueryOptions
                {
                    Category = "Scripts",
                });
                AssertTrue(resolvedScriptDetails.Count == 1 && resolvedScriptDetails[0].Resolved.IsScriptTable, "resolved resource detail queries should include script table context");
                AssertTrue(resolvedScriptDetails[0].ByteInfo.ActiveLength == 4 && resolvedScriptDetails[0].RelationshipCount == 1, "resolved resource detail queries should include resource detail context");

                KarProjectResourceInfo missing;
                AssertTrue(!resources.TryGet("VsHydra.dat:missingRoot", out missing), "resource try-get should return false for missing roots");
                AssertTrue(!project.TryGetResource("../bad.dat", out missing), "project resource try-get wrapper should reject invalid addresses");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectResourceActionExecutorRunsPlannedResourceActions()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-resource-action-executor-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            string inputRoot = tempRoot + "_inputs";
            Directory.CreateDirectory(tempRoot);
            Directory.CreateDirectory(inputRoot);

            try
            {
                WriteFieldQueryFixture(tempRoot);
                File.WriteAllBytes(Path.Combine(tempRoot, "ScInfPause.tm"), new byte[] { 0x40, 0x41 });
                WriteA2DPackage(Path.Combine(tempRoot, "A2Info.dat"), new[] { "ScInfGo2D.tm", "readme.bin" });

                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectResourceActionExecutor executor = project.ResourceActionExecutor;
                AssertTrue(object.ReferenceEquals(executor.Project, project), "resource action executors should retain project context");

                KarProjectResourceActionPlan scalarPreview = project.GetResourceActionPlan("VsHydra.dat:vsDataHydra", "set-scalar");
                AssertTrue(!scalarPreview.CanRun && scalarPreview.Reason.Contains("field name"), "resource action previews should report missing scalar edit arguments");

                KarProjectResourceActionPlan scalarExecutionPlan = project.ResourceService.GetActionPlan(
                    "VsHydra.dat:vsDataHydra",
                    "set-scalar",
                    new KarProjectResourceActionExecutionOptions
                    {
                        FieldName = "x0C",
                        Value = "0x1F4",
                    });
                AssertTrue(scalarExecutionPlan.CanRun && scalarExecutionPlan.WouldWriteOutput, "resource action execution plans should honor supplied scalar edit arguments");

                KarProjectResourceActionExecutionResult byteStatus = executor.Execute("ScInfPause.tm", "byte-status");
                AssertTrue(byteStatus.Plan.CanRun && byteStatus.ByteInfo.ActiveLength == 2, "resource action executors should return byte status results");
                AssertTrue(byteStatus.ResultKind == "byte-status" && byteStatus.IsReadOnly && !byteStatus.WritesOutput && !byteStatus.WroteOutput, "resource action execution results should summarize read-only status actions");

                KarProjectResourceActionExecutionResult dump = project.ExecuteResourceAction("ScInfPause.tm", "dump-bytes");
                AssertTrue(dump.ByteDumpResult.WroteOutput, "project resource action wrappers should execute byte dump actions");
                AssertTrue(File.ReadAllBytes(dump.ByteDumpResult.OutputPath).SequenceEqual(new byte[] { 0x40, 0x41 }), "resource action byte dumps should write active bytes to output assets");
                AssertTrue(dump.ResultKind == "byte-dump" && dump.WritesOutput && dump.WouldWriteOutput && dump.WroteOutput && !dump.SkippedOutputWrite, "resource action execution results should summarize byte dump writes");
                AssertTrue(dump.Summary.ActionId == "dump-bytes" && dump.Summary.ExecutionKind == KarProjectResourceActionExecutionKind.DumpBytes && dump.Summary.ResultKind == dump.ResultKind && dump.Summary.OutputPath == dump.OutputPath, "resource action execution summaries should expose stable automation metadata");
                AssertTrue(dump.OutputRelativePath == dump.ByteDumpResult.OutputRelativePath && dump.OutputPath == dump.ByteDumpResult.OutputPath, "resource action execution results should expose common output paths");

                KarProjectResourceActionExecutionResult skippedDump = project.ResourceService.ExecuteAction("ScInfPause.tm", "dump-bytes");
                AssertTrue(!skippedDump.Plan.WouldWriteOutput && !skippedDump.ByteDumpResult.WroteOutput, "resource action executors should keep skip/write state in the execution plan and result");
                AssertTrue(skippedDump.WritesOutput && !skippedDump.WouldWriteOutput && !skippedDump.WroteOutput && skippedDump.SkippedOutputWrite, "resource action execution results should summarize skipped output writes");

                IReadOnlyList<KarProjectResourceActionExecutionResult> scriptDumps = project.ExecuteResourceActions(new KarProjectResourceActionPlanQueryOptions
                {
                    ActionId = "dump-bytes",
                    Resources = new KarProjectResourceQueryOptions
                    {
                        Domain = "script-tables",
                    },
                });
                AssertTrue(scriptDumps.Count == 2, "resource action batch execution should run batch-safe actions over filtered resource sets");
                AssertTrue(scriptDumps.Any(result => result.Address == "ScInfPause.tm" && !result.ByteDumpResult.WroteOutput), "resource action batch execution should include skipped existing outputs");
                AssertTrue(scriptDumps.Any(result => result.Address == "A2Info.dat#ScInfGo2D.tm" && result.ByteDumpResult.WroteOutput), "resource action batch execution should write missing outputs");
                KarProjectResourceActionBatchResult scriptDumpReport = project.ExecuteResourceActionBatch(new KarProjectResourceActionPlanQueryOptions
                {
                    ActionId = "dump-bytes",
                    Resources = new KarProjectResourceQueryOptions
                    {
                        Domain = "script-tables",
                    },
                    Overwrite = true,
                });
                AssertTrue(scriptDumpReport.ActionId == "dump-bytes" && scriptDumpReport.Overwrite, "resource action batch reports should keep execution metadata");
                AssertTrue(scriptDumpReport.ResultCount == 2 && scriptDumpReport.SucceededCount == 2 && !scriptDumpReport.HasFailures, "resource action batch reports should summarize successful batches");
                AssertTrue(scriptDumpReport.WriteActionCount == 2 && scriptDumpReport.WroteOutputCount == 2 && scriptDumpReport.SkippedOutputWriteCount == 0, "resource action batch reports should summarize output write outcomes");
                AssertTrue(scriptDumpReport.Results.All(result => result.Succeeded), "resource action batch reports should retain ordered execution results");

                KarProjectResourceActionExecutionResult fields = executor.Execute("VsHydra.dat:vsDataHydra", "field-values");
                AssertTrue(fields.FieldValues.Any(field => field.FieldName == "x0C" && field.Value.SignedValue == 303), "resource action executors should return field-list results");

                KarProjectResourceActionExecutionResult field = executor.Execute(
                    "VsHydra.dat:vsDataHydra",
                    "field-values",
                    new KarProjectResourceActionExecutionOptions { FieldName = "x0C" });
                AssertTrue(field.FieldValue.Value.SignedValue == 303, "resource action executors should return single field results when field names are supplied");

                IReadOnlyList<KarProjectResourceActionExecutionResult> mapUnknowns = executor.ExecuteBatch(
                    new KarProjectResourceActionPlanQueryOptions
                    {
                        ActionId = "field-values",
                        Resources = new KarProjectResourceQueryOptions
                        {
                            Kind = KarResourceKind.HsdRoot,
                            Files = new KarProjectFileQueryOptions { Kind = KarFileKind.MapData },
                        },
                    },
                    new KarProjectResourceActionExecutionOptions { FieldName = "unknown1" });
                AssertTrue(mapUnknowns.Count == 2, "resource action batch execution should support shared field-value arguments");
                AssertTrue(mapUnknowns.All(result => result.FieldValue.FieldName == "unknown1"), "resource action field batches should return the selected field for each resource");

                KarProjectResourceActionExecutionResult scalarEdit = executor.Execute(
                    "VsHydra.dat:vsDataHydra",
                    "set-scalar",
                    new KarProjectResourceActionExecutionOptions
                    {
                        FieldName = "x0C",
                        Value = "0x1F4",
                    });
                AssertTrue(scalarEdit.Plan.CanRun && scalarEdit.ScalarEditResult.Edit.NewValue.SignedValue == 500, "resource action executors should run scalar edit actions through safe output writes");
                AssertTrue(scalarEdit.ResultKind == "scalar-edit" && scalarEdit.WroteOutput && scalarEdit.OutputPath == scalarEdit.ScalarEditResult.OutputPath, "resource action execution results should summarize scalar edit output writes");

                KarProjectResourceActionExecutionResult outputStatus = executor.Execute("VsHydra.dat:vsDataHydra", "output-status");
                AssertTrue(outputStatus.OutputInfo.Status == KarProjectResourceOutputStatus.DiffersFromSource, "resource action output status should reflect earlier action writes");

                string entryReplacementPath = Path.Combine(inputRoot, "ScInfGo2D.tm");
                File.WriteAllBytes(entryReplacementPath, new byte[] { 0x21, 0x22, 0x23, 0x24 });
                KarProjectResourceActionExecutionResult import = executor.Execute(
                    "A2Info.dat#ScInfGo2D.tm",
                    "import-file",
                    new KarProjectResourceActionExecutionOptions { InputPath = entryReplacementPath });
                AssertTrue(import.Plan.CanRun && import.ImportResult.OutputKind == KarProjectResourceOutputKind.ProjectFile, "resource action executors should run input-file imports through safe package outputs");
                AssertTrue(project.ReadResourceBytes("A2Info.dat#ScInfGo2D.tm").SequenceEqual(new byte[] { 0x21, 0x22, 0x23, 0x24 }), "resource action imports should update active reads without mutating source packages");

                AssertThrows<InvalidOperationException>(
                    () => executor.Execute("A2Info.dat#ScInfGo2D.tm", "import-file"),
                    "resource action executors should reject missing input-file arguments");
                AssertThrows<InvalidOperationException>(
                    () => executor.Execute(
                        "VsHydra.dat:vsDataHydra",
                        "set-scalar",
                        new KarProjectResourceActionExecutionOptions { FieldName = "x0C" }),
                    "resource action executors should reject incomplete scalar edit arguments");
                AssertThrows<ArgumentException>(
                    () => executor.ExecuteBatch(new KarProjectResourceActionPlanQueryOptions()),
                    "resource action batch execution should require a single action id");
                AssertThrows<NotSupportedException>(
                    () => executor.ExecuteBatch(new KarProjectResourceActionPlanQueryOptions
                    {
                        ActionId = "export-output",
                        Resources = new KarProjectResourceQueryOptions { Kind = KarResourceKind.File },
                    }),
                    "resource action batch execution should reject actions that are not marked batch-safe");
                KarProjectResourceActionBatchResult tolerantFailureReport = executor.ExecuteBatchResult(
                    new KarProjectResourceActionPlanQueryOptions
                    {
                        ActionId = "export-output",
                        Resources = new KarProjectResourceQueryOptions { Kind = KarResourceKind.File },
                    },
                    new KarProjectResourceActionExecutionOptions { ContinueOnError = true });
                IReadOnlyList<KarProjectResourceActionExecutionResult> tolerantFailures = tolerantFailureReport.Results;
                AssertTrue(tolerantFailureReport.ContinueOnError && tolerantFailureReport.HasFailures, "tolerant resource action batch reports should expose failure summary state");
                AssertTrue(tolerantFailureReport.ResultCount == 5 && tolerantFailureReport.SucceededCount == 0 && tolerantFailureReport.FailedCount == 5, "tolerant resource action batch reports should count failed executions");
                AssertTrue(tolerantFailureReport.FailedResults.Count == 5 && tolerantFailureReport.SucceededResults.Count == 0, "tolerant resource action batch reports should group failed executions");
                AssertTrue(tolerantFailureReport.WriteActionCount == 5 && tolerantFailureReport.WroteOutputCount == 0, "tolerant resource action batch reports should not count failed writes as written output");
                AssertTrue(tolerantFailures.Count == 5, "tolerant resource action batches should keep per-resource failures");
                AssertTrue(tolerantFailures.All(result => result.Failed && result.ResultKind == "error" && result.ErrorType == "NotSupportedException"), "tolerant resource action batches should expose failure metadata");
                AssertTrue(tolerantFailures.All(result => result.Result == null), "failed resource action results should not expose success payloads");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
                if (Directory.Exists(inputRoot))
                    Directory.Delete(inputRoot, true);
            }
        }

        private static void ProjectOperationServiceIndexesWorkflowsAndResourceActions()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-operation-service-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            try
            {
                WriteFieldQueryFixture(tempRoot);
                File.WriteAllBytes(Path.Combine(tempRoot, "ScInfPause.tm"), new byte[] { 0x40, 0x41 });
                WriteA2DPackage(Path.Combine(tempRoot, "A2Info.dat"), new[] { "ScInfGo2D.tm", "readme.bin" });

                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectOperationService operations = project.OperationService;
                AssertTrue(object.ReferenceEquals(operations.Project, project), "operation services should retain project context");

                KarProjectToolkitSurface surface = project.CreateToolkitSurface();
                KarProjectOperationCatalog catalog = project.CreateOperationCatalog();
                AssertTrue(catalog.WorkflowOperationCount == surface.WorkflowCount, "operation catalogs should include toolkit workflow operations");
                AssertTrue(catalog.ResourceActionOperationCount > 0, "operation catalogs should include resource action operations");
                AssertTrue(catalog.OperationCount == catalog.WorkflowOperationCount + catalog.ResourceActionOperationCount, "operation catalogs should count all operation kinds");
                AssertTrue(catalog.OutputOperationCount != 0 && catalog.RunnableOperationCount != 0, "operation catalogs should summarize writable and runnable operations");
                KarProjectOperationCatalogContract catalogContract = catalog.CreateContract();
                AssertTrue(catalogContract.OperationCount == catalog.OperationCount && catalogContract.Operations.Count == catalog.OperationCount, "operation catalog contracts should preserve operation counts");
                AssertTrue(project.CreateOperationCatalogContract(new KarProjectOperationQueryOptions { IncludeResourceActions = false }).WorkflowOperationCount == surface.WorkflowCount, "project wrappers should expose operation catalog contracts");

                KarProjectOperation workflow = catalog.WorkflowOperations.Single(operation => operation.Id == "workflow:edit-resource-data-field");
                AssertTrue(workflow.Workflow != null && workflow.ResourceActionPlan == null, "workflow operations should keep workflow payloads only");
                AssertTrue(workflow.DomainId == "resources" && workflow.RequiresValue && workflow.WritesOutput, "workflow operations should expose workflow metadata");
                AssertTrue(workflow.Usage.Contains("kar-toolkit resource-data-edit"), "workflow operations should expose CLI usage");
                KarProjectOperationContract workflowContract = workflow.CreateContract();
                AssertTrue(workflowContract.Workflow.Id == workflow.Workflow.Id && workflowContract.ResourceActionPlan == null && workflowContract.JsonUsage.EndsWith("[--json]"), "workflow operation contracts should preserve workflow metadata and usage");

                IReadOnlyList<KarProjectOperation> workflowOnly = project.QueryOperations(new KarProjectOperationQueryOptions
                {
                    IncludeResourceActions = false,
                });
                AssertTrue(workflowOnly.Count == surface.WorkflowCount && workflowOnly.All(operation => operation.IsWorkflow), "operation queries should support workflow-only catalogs");

                IReadOnlyList<KarProjectOperation> scriptDumps = project.QueryOperations(new KarProjectOperationQueryOptions
                {
                    IncludeWorkflows = false,
                    DomainId = "script-tables",
                    ActionId = "dump-bytes",
                    CanRun = true,
                    WouldWriteOutput = true,
                });
                AssertTrue(scriptDumps.Count == 2, "operation queries should find runnable script-table byte dump actions");
                AssertTrue(scriptDumps.All(operation => operation.IsResourceAction && operation.TargetDomainId == "script-tables"), "resource action operations should expose target domains");
                AssertTrue(scriptDumps.Any(operation => operation.ResourceAddress == "ScInfPause.tm"), "operation queries should include loose script table actions");
                AssertTrue(scriptDumps.Any(operation => operation.ResourceAddress == "A2Info.dat#ScInfGo2D.tm"), "operation queries should include A2D script table actions");
                AssertTrue(scriptDumps.All(operation => operation.Usage.Contains(operation.ResourceAddress)), "resource action operations should expose target-specific usage");
                KarProjectOperationContract scriptDumpContract = scriptDumps.Single(operation => operation.ResourceAddress == "ScInfPause.tm").CreateContract();
                AssertTrue(scriptDumpContract.ResourceActionPlan.Address == "ScInfPause.tm" && scriptDumpContract.ResourceActionPlan.ActionId == "dump-bytes" && scriptDumpContract.ResourceActionPlan.CanRun, "resource action operation contracts should preserve compact action plan metadata");
                AssertTrue(scriptDumpContract.ResourceActionPlan.Resource.Address == "ScInfPause.tm" && scriptDumpContract.ResourceActionPlan.Reference.Address == "ScInfPause.tm", "resource action operation contracts should preserve resource references");

                KarProjectOperationPresetCatalog presetCatalog = project.CreateOperationPresetCatalog();
                AssertTrue(presetCatalog.PresetCount >= 6, "operation preset catalogs should expose reusable toolkit operation queries");
                AssertTrue(presetCatalog.AvailablePresetCount != 0 && presetCatalog.OutputPresetCount != 0, "operation preset catalogs should summarize availability and output-writing presets");
                KarProjectOperationPresetCatalogContract presetCatalogContract = presetCatalog.CreateContract();
                AssertTrue(presetCatalogContract.PresetCount == presetCatalog.PresetCount && presetCatalogContract.Presets.Count == presetCatalog.PresetCount, "operation preset catalog contracts should preserve preset counts");
                KarProjectOperationPreset dumpScriptPreset = project.QueryOperationPresets(new KarProjectOperationPresetQueryOptions
                {
                    Id = "dump-script-bytes",
                }).Single();
                AssertTrue(dumpScriptPreset.ActionId == "dump-bytes" && dumpScriptPreset.DomainId == "script-tables", "operation presets should describe action and domain filters");
                AssertTrue(dumpScriptPreset.OperationCount == scriptDumps.Count && dumpScriptPreset.RunnableOperationCount == scriptDumps.Count, "operation presets should attach live operation counts");
                AssertTrue(dumpScriptPreset.OperationUsage.Contains("--domain script-tables") && dumpScriptPreset.BatchUsage.Contains("operation-batch"), "operation presets should expose reusable CLI usage strings");
                KarProjectOperationPresetContract dumpScriptPresetContract = dumpScriptPreset.CreateContract();
                AssertTrue(dumpScriptPresetContract.OperationCount == dumpScriptPreset.OperationCount && dumpScriptPresetContract.OperationJsonUsage.EndsWith("--json") && dumpScriptPresetContract.BatchUsage.Contains("operation-batch"), "operation preset contracts should preserve live counts and launcher usage");
                AssertTrue(project.QueryOperations(dumpScriptPreset.CreateQueryOptions()).Count == scriptDumps.Count, "operation presets should create operation queries matching their live counts");
                AssertTrue(project.QueryOperationPresets(new KarProjectOperationPresetQueryOptions { WritesOutput = true, HasOperations = true }).Any(preset => preset.Id == "dump-script-bytes"), "operation preset queries should filter writable available presets");

                KarProjectOperation scalarPreview = project.QueryOperations(new KarProjectOperationQueryOptions
                {
                    IncludeWorkflows = false,
                    ResourceKind = KarResourceKind.HsdRoot,
                    ActionId = "set-scalar",
                    Text = "VsHydra",
                    CanRun = false,
                }).Single();
                AssertTrue(scalarPreview.ResourceAddress == "VsHydra.dat:vsDataHydra", "operation queries should search resource action target addresses");
                AssertTrue(scalarPreview.RequiresFieldName && scalarPreview.RequiresValue && scalarPreview.HasReason, "resource action operations should expose missing argument requirements");
                AssertTrue(scalarPreview.Reason.Contains("field name"), "resource action operations should preserve plan reasons");

                KarProjectOperation byId = project.QueryOperations(new KarProjectOperationQueryOptions
                {
                    Id = scalarPreview.Id,
                    IncludeWorkflows = false,
                }).Single();
                AssertTrue(byId.ResourceAddress == scalarPreview.ResourceAddress && byId.ActionId == scalarPreview.ActionId, "operation queries should filter by stable operation id");

                IReadOnlyList<KarProjectOperation> usageSearch = project.QueryOperations(new KarProjectOperationQueryOptions
                {
                    IncludeWorkflows = false,
                    Text = "kar-toolkit dump-resource-bytes",
                });
                AssertTrue(usageSearch.Any(operation => operation.ActionId == "dump-bytes"), "operation queries should search assembled usage strings");

                KarProjectSession session = project.CreateSession();
                AssertTrue(session.RegistryCatalog.ResourceActionDefinitions.Any(definition => definition.Id == "dump-bytes"), "project sessions should expose resource action registry metadata alongside operations");
                AssertTrue(session.CreateOperationCatalog(new KarProjectOperationQueryOptions { IncludeResourceActions = false }).WorkflowOperationCount == surface.WorkflowCount, "project sessions should expose operation catalog creation");
                AssertTrue(session.CreateOperationCatalogContract(new KarProjectOperationQueryOptions { IncludeResourceActions = false }).WorkflowOperationCount == surface.WorkflowCount, "project sessions should expose operation catalog contract creation");

                KarProjectOperation looseDump = scriptDumps.Single(operation => operation.ResourceAddress == "ScInfPause.tm");
                KarProjectOperationExecutionResult dumpResult = project.ExecuteOperation(looseDump);
                AssertTrue(dumpResult.Operation.Id == looseDump.Id, "operation execution results should retain the requested operation");
                AssertTrue(dumpResult.Succeeded && dumpResult.ResultKind == "byte-dump", "operation execution should run resource-action operations through the existing executor");
                AssertTrue(dumpResult.Summary.OperationId == looseDump.Id && dumpResult.Summary.TargetDomainId == "script-tables" && dumpResult.Summary.ActionId == "dump-bytes" && dumpResult.Summary.ExecutionKind == KarProjectResourceActionExecutionKind.DumpBytes, "operation execution summaries should expose operation and underlying resource action metadata");
                AssertTrue(dumpResult.WroteOutput && File.Exists(dumpResult.OutputPath), "operation execution should write outputs through safe resource actions");
                AssertTrue(File.ReadAllBytes(dumpResult.OutputPath).SequenceEqual(new byte[] { 0x40, 0x41 }), "operation execution should write active resource bytes");

                KarProjectOperationExecutionResult scalarResult = project.ExecuteOperation(
                    scalarPreview.Id,
                    new KarProjectResourceActionExecutionOptions
                    {
                        FieldName = "x0C",
                        Value = "0x222",
                    },
                    new KarProjectOperationQueryOptions
                    {
                        IncludeWorkflows = false,
                    });
                AssertTrue(scalarResult.Succeeded && scalarResult.ResultKind == "scalar-edit", "operation execution by id should accept resource action arguments");
                AssertTrue(scalarResult.ResourceActionResult.ScalarEditResult.Edit.NewValue.SignedValue == 0x222, "operation execution should return typed resource action results");

                KarProjectOperationExecutionResult sessionDump = session.ExecuteOperation(scriptDumps.Single(operation => operation.ResourceAddress == "A2Info.dat#ScInfGo2D.tm").Id);
                AssertTrue(sessionDump.Succeeded && sessionDump.WroteOutput, "project sessions should execute operation ids");

                KarProjectOperationBatchResult overwriteBatch = project.ExecuteOperationBatch(
                    new KarProjectOperationQueryOptions
                    {
                        DomainId = "script-tables",
                        ActionId = "dump-bytes",
                    },
                    new KarProjectResourceActionExecutionOptions
                    {
                        Overwrite = true,
                    });
                AssertTrue(overwriteBatch.Overwrite && !overwriteBatch.ContinueOnError, "operation batch results should keep execution options");
                AssertTrue(overwriteBatch.ResultCount == 2 && overwriteBatch.SucceededCount == 2 && overwriteBatch.AllSucceeded, "operation batches should execute matching resource-action operations");
                AssertTrue(overwriteBatch.WriteActionCount == 2 && overwriteBatch.WroteOutputCount == 2 && overwriteBatch.SkippedOutputWriteCount == 0, "operation batches should summarize output writes");
                AssertTrue(overwriteBatch.Results.All(result => result.Operation.IsResourceAction && result.ResultKind == "byte-dump"), "operation batches should keep operation metadata with each result");

                KarProjectOperationBatchResult statusBatch = session.ExecuteOperationBatch(new KarProjectOperationQueryOptions
                {
                    DomainId = "script-tables",
                    ActionId = "byte-status",
                });
                AssertTrue(statusBatch.ResultCount == 2 && statusBatch.ReadOnlyCount == 2 && statusBatch.WroteOutputCount == 0, "project sessions should execute read-only operation batches");
                KarProjectOperationPreset statusPreset = project.QueryOperationPresets(new KarProjectOperationPresetQueryOptions { Id = "script-byte-status" }).Single();
                KarProjectOperationBatchResult presetStatusBatch = project.ExecuteOperationBatch(statusPreset.CreateQueryOptions());
                AssertTrue(presetStatusBatch.ResultCount == statusPreset.OperationCount && presetStatusBatch.ReadOnlyCount == statusPreset.OperationCount, "operation preset queries should be executable through operation batches");

                KarProject customOperationProject = KarProject.Open(new KarProjectOptions
                {
                    SourceRoot = tempRoot,
                    OutputRoot = outputRoot + "_custom",
                    OperationDomainRegistry = new KarProjectOperationDomainRegistry(
                        new[]
                        {
                            new KarProjectOperationDomainRule(
                                "custom-scripts",
                                "Custom Scripts",
                                "Custom caller-owned script resource grouping.",
                                resource => resource.File != null && resource.File.IsScriptTable),
                        },
                        "custom-resources"),
                    OperationPresetRegistry = new KarProjectOperationPresetRegistry(new[]
                    {
                        new KarProjectOperationPresetDefinition(
                            "custom-script-status",
                            "custom-scripts",
                            "Custom Script Status",
                            "Caller-owned reusable script status query.",
                            "byte-status",
                            null,
                            isReadOnly: true,
                            writesOutput: false,
                            supportsBatch: true,
                            requiresInputFile: false,
                            requiresFieldName: false,
                            requiresValue: false,
                            canRun: true,
                            wouldWriteOutput: false,
                            hasModifiedOutputs: null),
                    }),
                });
                AssertTrue(customOperationProject.OperationDomainRegistry.ResolveTargetDomain(customOperationProject.ResourceService.Get("ScInfPause.tm")) == "custom-scripts", "project options should allow custom operation domain rules");
                AssertTrue(customOperationProject.SchemaService.OperationDomainRules.Single().Id == "custom-scripts", "schema service should expose custom operation domain rules");
                AssertTrue(customOperationProject.SchemaService.OperationPresetDefinitions.Single().Id == "custom-script-status", "schema service should expose custom operation preset definitions");
                KarProjectToolkitRegistryCatalog customRegistryCatalog = customOperationProject.CreateToolkitRegistryCatalog();
                AssertTrue(customRegistryCatalog.OperationDomainRules.Single().Id == "custom-scripts", "toolkit registry catalog should expose custom operation domain rules");
                AssertTrue(customRegistryCatalog.OperationPresetDefinitions.Single().Id == "custom-script-status", "toolkit registry catalog should expose custom operation preset definitions");
                KarProjectOperationPreset customPreset = customOperationProject.QueryOperationPresets(null).Single();
                AssertTrue(customPreset.Id == "custom-script-status" && customPreset.OperationCount == 1, "project options should allow custom operation preset registries with live counts");
                AssertTrue(customOperationProject.QueryOperations(customPreset.CreateQueryOptions()).Single().ResourceAddress == "ScInfPause.tm", "custom preset queries should use custom operation domain rules");

                KarProject customDomainProject = KarProject.Open(new KarProjectOptions
                {
                    SourceRoot = tempRoot,
                    DomainContextProviderRegistry = new KarProjectDomainContextProviderRegistry(new[]
                    {
                        new KarProjectDomainContextProvider(
                            "custom-domain",
                            "Custom Domain",
                            "Custom domain context provider for toolkit tests.",
                            "files",
                            "file-context",
                            (snapshot, graph) => snapshot.FileCount,
                            (snapshot, graph) => graph.ResourceCount,
                            (snapshot, graph) => snapshot.OutputFileCount,
                            (snapshot, graph) => snapshot.ModifiedProjectOutputFileCount,
                            (snapshot, graph) => snapshot.DomainInspectionIssueCount),
                    }),
                    ToolkitWorkflowProviderRegistry = new KarProjectToolkitWorkflowProviderRegistry(new[]
                    {
                        new KarProjectToolkitWorkflowProvider(
                            "custom-workflows",
                            "Custom Workflows",
                            "Custom workflow provider for toolkit tests.",
                            context => new[]
                            {
                                new KarProjectToolkitWorkflow(
                                    "custom-workflow",
                                    "custom-domain",
                                    "Custom Workflow",
                                    "Caller-owned reusable toolkit workflow.",
                                    "custom-command",
                                    "<source-folder>",
                                    isReadOnly: true,
                                    writesOutput: false,
                                    supportsBatch: true,
                                    targetCount: context.Snapshot.FileCount),
                            }),
                    }),
                });
                KarProjectDomainContext customDomain = customDomainProject.QueryDomainContexts().Single();
                AssertTrue(customDomain.Id == "custom-domain" && customDomain.ItemCount == customDomainProject.Files.Count, "project options should allow custom domain context providers");
                KarProjectToolkitSurface customSurface = customDomainProject.CreateToolkitSurface();
                KarProjectToolkitWorkflow customWorkflow = customSurface.Workflows.Single();
                AssertTrue(customWorkflow.Id == "custom-workflow" && customWorkflow.DomainId == "custom-domain" && customWorkflow.TargetCount == customDomainProject.Files.Count, "project options should allow custom toolkit workflow providers");
                AssertTrue(customSurface.WorkflowGroups.Single().Domain.Id == "custom-domain", "custom workflow providers should group against custom domain context providers");
                AssertTrue(customDomainProject.SchemaService.DomainContextProviders.Single().Id == "custom-domain", "schema service should expose custom domain context providers");
                AssertTrue(customDomainProject.SchemaService.ToolkitWorkflowProviders.Single().Id == "custom-workflows", "schema service should expose custom toolkit workflow providers");
                AssertTrue(customDomainProject.CreateToolkitRegistryCatalog().DomainContextProviders.Single().Id == "custom-domain", "toolkit registry catalog should expose custom domain context providers");
                AssertTrue(customDomainProject.CreateToolkitRegistryCatalog().ToolkitWorkflowProviders.Single().Id == "custom-workflows", "toolkit registry catalog should expose custom toolkit workflow providers");
                AssertTrue(customDomainProject.QueryOperations(new KarProjectOperationQueryOptions { IncludeResourceActions = false }).Single().Id == "workflow:custom-workflow", "custom workflow providers should feed operation discovery");

                AssertThrows<NotSupportedException>(
                    () => project.ExecuteOperationBatch(new KarProjectOperationQueryOptions
                    {
                        IncludeWorkflows = false,
                        ResourceKind = KarResourceKind.File,
                        ActionId = "export-output",
                    }),
                    "operation batches should reject non-batch resource actions");

                KarProjectOperationBatchResult tolerantBatch = project.ExecuteOperationBatch(
                    new KarProjectOperationQueryOptions
                    {
                        IncludeWorkflows = false,
                        ResourceKind = KarResourceKind.File,
                        ActionId = "export-output",
                    },
                    new KarProjectResourceActionExecutionOptions
                    {
                        ContinueOnError = true,
                    });
                AssertTrue(tolerantBatch.ContinueOnError && tolerantBatch.HasFailures, "tolerant operation batches should keep non-batch failures");
                AssertTrue(tolerantBatch.FailedResults.All(result => result.Failed && result.ErrorType == "NotSupportedException"), "tolerant operation batches should expose failure metadata");

                AssertThrows<NotSupportedException>(
                    () => project.ExecuteOperation(workflow),
                    "operation execution should reject workflow descriptors that are not direct resource actions");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectResourceServiceQueriesFieldValues()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-resource-field-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            try
            {
                WriteFieldQueryFixture(tempRoot);
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectResourceService resources = project.ResourceService;

                IReadOnlyList<KarProjectResourceFieldInfo> hydraFields = resources.QueryFieldValues(new KarProjectResourceFieldQueryOptions
                {
                    Resources = new KarProjectResourceQueryOptions
                    {
                        Address = "VsHydra.dat:vsDataHydra",
                        Kind = KarResourceKind.HsdRoot,
                    },
                });
                AssertTrue(hydraFields.Any(field => field.FieldName == "x0C"), "resource field query should return fields for addressed HSD roots");

                KarProjectResourceFieldInfo x0C = resources.GetFieldValue("VsHydra.dat:vsDataHydra", "x0C");
                AssertTrue(x0C.Address == "VsHydra.dat:vsDataHydra", "resource field get should preserve root resource addresses");
                AssertTrue(x0C.DataDefinitionId == "kar.vs.legendary", "resource field query should retain schema ids");
                AssertTrue(x0C.Value.SignedValue == 303, "resource field query should expose field values");
                AssertTrue(project.GetResourceFieldValue("VsHydra.dat:vsDataHydra", "x0C").Value.SignedValue == 303, "project resource field wrapper should delegate to resource service");

                IReadOnlyList<KarProjectResourceFieldInfo> scalarFields = resources.QueryFieldValues(new KarProjectResourceFieldQueryOptions
                {
                    Resources = new KarProjectResourceQueryOptions
                    {
                        Address = "VsHydra.dat:vsDataHydra",
                        Kind = KarResourceKind.HsdRoot,
                    },
                    Text = "unknown scalar",
                });
                AssertTrue(scalarFields.Count == 2 && scalarFields.Any(field => field.FieldName == "x0C"), "resource field text search should match field descriptions");

                IReadOnlyList<KarProjectResourceFieldInfo> mapFields = resources.QueryFieldValues(new KarProjectResourceFieldQueryOptions
                {
                    Resources = new KarProjectResourceQueryOptions
                    {
                        Kind = KarResourceKind.HsdRoot,
                        Files = new KarProjectFileQueryOptions { Kind = KarFileKind.MapData },
                    },
                    FieldName = "unknown1",
                });
                AssertTrue(mapFields.Count == 2, "resource field query should combine resource parent file and field filters");

                IReadOnlyList<KarProjectResourceFieldInfo> fileFields = resources.QueryFieldValues(new KarProjectResourceFieldQueryOptions
                {
                    Resources = new KarProjectResourceQueryOptions
                    {
                        Address = "VsHydra.dat",
                    },
                });
                AssertTrue(fileFields.Count == 0, "resource field query should ignore non-root resources");

                KarProjectResourceGraph cachedGraph = project.ResourceGraphService.Snapshot;
                resources.SetScalarFieldFromText("VsHydra.dat:vsDataHydra", "x0C", "0x1F4");
                AssertTrue(!project.ResourceGraphService.HasSnapshot, "resource graph services should invalidate after scalar edits write output archives");
                AssertTrue(resources.GetFieldValue("VsHydra.dat:vsDataHydra", "x0C").Value.SignedValue == 500, "resource field query should read edited values from output copies");
                AssertTrue(project.ResourceGraphService.HasSnapshot && !object.ReferenceEquals(cachedGraph, project.ResourceGraphService.Snapshot), "resource graph services should rebuild after invalidation");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectResourceDataViewsExposeLabeledFieldTrees()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-resource-data-view-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            try
            {
                WriteFieldQueryFixture(tempRoot);
                KarProject project = KarProject.Open(tempRoot, outputRoot);

                KarProjectResourceDataView hydra = project.GetResourceDataView("VsHydra.dat:vsDataHydra");
                AssertTrue(hydra.Address == "VsHydra.dat:vsDataHydra" && hydra.Kind == KarResourceKind.HsdRoot, "resource data views should retain resource identity");
                AssertTrue(hydra.HasDataDefinition && hydra.DataDefinitionId == "kar.vs.legendary", "resource data views should expose root data definitions");
                AssertTrue(hydra.FieldCount >= 5 && hydra.TotalFieldCount >= hydra.FieldCount, "resource data views should expose labeled field counts");
                AssertTrue(hydra.FlattenedFields.Count == hydra.TotalFieldCount, "resource data views should expose flattened field trees");

                KarProjectResourceDataFieldView x0C = hydra.Fields.Single(field => field.FieldName == "x0C");
                AssertTrue(x0C.FieldPath == "x0C" && x0C.OffsetHex == "0x0C", "resource data fields should expose stable field paths and offsets");
                AssertTrue(x0C.IsScalar && x0C.CanSetScalar && x0C.SignedValue == 303, "resource data fields should expose editable scalar metadata and values");
                AssertTrue(x0C.HasScalarEdit && x0C.ScalarEdit.ActionId == "set-scalar" && x0C.ScalarEdit.Command == "set-resource-scalar", "editable resource data fields should expose scalar edit action metadata");
                AssertTrue(x0C.ScalarEdit.Address == "VsHydra.dat:vsDataHydra" && x0C.ScalarEdit.FieldName == "x0C", "scalar edit field metadata should retain resource and field selectors");
                KarProjectResourceActionExecutionOptions editOptions = x0C.ScalarEdit.CreateExecutionOptions("0x200");
                AssertTrue(editOptions.FieldName == "x0C" && editOptions.Value == "0x200", "scalar edit metadata should create resource action execution options");
                AssertTrue(project.GetResourceDataField("VsHydra.dat:vsDataHydra", "x0C").SignedValue == 303, "project resource data field wrappers should look up fields by path or name");
                KarProjectResourceActionPlan missingValuePlan = project.GetResourceDataFieldEditPlan("VsHydra.dat:vsDataHydra", "x0C");
                AssertTrue(!missingValuePlan.CanRun && missingValuePlan.Reason == "Requires a value.", "resource data field edit plans should require edit values");
                KarProjectResourceActionPlan editPlan = project.ResourceService.GetDataFieldEditPlan("VsHydra.dat:vsDataHydra", "x0C", "0x210");
                AssertTrue(editPlan.CanRun && editPlan.ActionId == "set-scalar" && editPlan.WouldWriteOutput, "resource data field edit plans should preview executable scalar writes");
                KarProjectResourceActionExecutionResult editResult = project.ExecuteResourceDataFieldEdit("VsHydra.dat:vsDataHydra", "x0C", "0x210");
                AssertTrue(editResult.ResultKind == "scalar-edit" && editResult.WroteOutput && File.Exists(editResult.OutputPath), "resource data field edit execution should write through the resource action executor");
                AssertTrue(editResult.ScalarEditResult.Edit.NewValue.SignedValue == 528, "resource data field edit execution should parse scalar values through existing edit rules");
                AssertTrue(project.GetResourceDataField("VsHydra.dat:vsDataHydra", "x0C").SignedValue == 528, "resource data field queries should read edits from output copies");

                KarProjectResourceDataFieldView pointer = hydra.Fields.Single(field => field.FieldName == "primaryModelAnimation");
                AssertTrue(pointer.IsPointer && !pointer.CanSetScalar && !pointer.HasScalarEdit && pointer.DataDefinitionId == "kar.vs.legendary.modelAnimation", "resource data fields should retain pointer target schema ids");
                AssertThrows<NotSupportedException>(
                    () => project.GetResourceDataFieldEditPlan("VsHydra.dat:vsDataHydra", "primaryModelAnimation", "1"),
                    "resource data field edit plans should reject non-scalar field selectors");
                AssertTrue(hydra.EditableScalarFieldCount >= 2 && hydra.PointerFieldCount >= 3, "resource data views should summarize scalar and pointer fields");

                IReadOnlyList<KarProjectResourceDataFieldView> editable = project.QueryResourceDataFields(new KarProjectResourceDataFieldQueryOptions
                {
                    Resources = new KarProjectResourceQueryOptions
                    {
                        Address = "VsHydra.dat:vsDataHydra",
                        Kind = KarResourceKind.HsdRoot,
                    },
                    CanSetScalar = true,
                });
                AssertTrue(editable.Count >= 2 && editable.All(field => field.CanSetScalar), "resource data field queries should filter editable scalar fields");

                IReadOnlyList<KarProjectResourceDataFieldView> selected = project.ResourceService.QueryDataFields(new KarProjectResourceDataFieldQueryOptions
                {
                    Resources = new KarProjectResourceQueryOptions
                    {
                        Address = "VsHydra.dat:vsDataHydra",
                        Kind = KarResourceKind.HsdRoot,
                    },
                    FieldPathOrName = "primaryModelAnimation",
                    Text = "model",
                });
                AssertTrue(selected.Count == 1 && selected[0].FieldPath == "primaryModelAnimation", "resource data field queries should select by field path or name and search text");

                KarProjectResourceDetail detail = project.GetResourceDetail("VsHydra.dat:vsDataHydra");
                AssertTrue(detail.HasDataView && object.ReferenceEquals(detail.DataView.Resource, detail.Resource), "resource details should carry a data view for the detailed resource");
                KarProjectResolvedResourceDetail resolved = project.GetResolvedResourceDetail("VsHydra.dat:vsDataHydra");
                AssertTrue(resolved.HasDataView && resolved.DataView.DataDefinitionId == hydra.DataDefinitionId, "resolved resource details should expose data views");

                IReadOnlyList<KarProjectResourceDataView> mapViews = project.QueryResourceDataViews(new KarProjectResourceQueryOptions
                {
                    Kind = KarResourceKind.HsdRoot,
                    Files = new KarProjectFileQueryOptions { Kind = KarFileKind.MapData },
                });
                AssertTrue(mapViews.Count == 2 && mapViews.All(view => view.HasFields), "resource data view queries should filter through resource query options");

                KarProjectResourceDataView file = project.ResourceService.GetDataView("VsHydra.dat");
                AssertTrue(!file.HasFields && file.FieldCount == 0 && file.TotalFieldCount == 0, "resource data views should be empty for resources without field data");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectResourceServiceReadsAndExportsResourcesSafely()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-resource-export-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            string archivePath = Path.Combine(tempRoot, "VsHydra.dat");
            string packagePath = Path.Combine(tempRoot, "A2Info.dat");
            WriteHsdFile(archivePath, "vsDataHydra", new KAR_vsLegendaryData());
            WriteA2DPackage(packagePath, new[] { "ScInfGo2D.tm", "readme.bin" });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectResourceService resources = project.ResourceService;

                byte[] packageBytes = File.ReadAllBytes(packagePath);
                AssertTrue(resources.Adapters.Count == Enum.GetValues(typeof(KarResourceKind)).Length, "resource services should expose default resource adapters");
                KarProjectResourceInfo packageResource = resources.Get("A2Info.dat");
                AssertTrue(resources.GetAdapter(packageResource).ReadBytes(packageResource).SequenceEqual(packageBytes), "resource adapters should expose file byte reads");
                byte[] rootBytes = resources.GetAdapter(KarResourceKind.HsdRoot).ReadBytes(resources.Get("VsHydra.dat:vsDataHydra"));
                int rootLength = project.GetArchiveContext("VsHydra.dat").Roots.Single().StructLength.Value;
                AssertTrue(rootBytes.Length == rootLength && rootBytes.Length > 0, "resource adapters should expose HSD root struct byte reads");
                AssertTrue(resources.ReadBytes("A2Info.dat").SequenceEqual(packageBytes), "resource reads should return active file bytes");
                AssertTrue(project.ResourceAddressService.ReadBytes("A2Info.dat").SequenceEqual(packageBytes), "resource address services should read file bytes");
                AssertTrue(project.ReadResourceBytes("A2Info.dat#ScInfGo2D.tm").SequenceEqual(new byte[] { 0xA0, 0xB0, 0xC0, 0xD0 }), "project resource read wrapper should return A2D entry bytes");
                KarProjectResolvedResource resolvedEntry = project.ResolveResourceAddress("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(resolvedEntry.CanReadBytes && project.ResourceAddressService.ReadBytes(resolvedEntry).SequenceEqual(new byte[] { 0xA0, 0xB0, 0xC0, 0xD0 }), "resource address services should read resolved entry bytes");
                AssertTrue(project.ReadResourceBytes("VsHydra.dat:vsDataHydra").SequenceEqual(rootBytes), "project resource read wrapper should return HSD root struct bytes");
                byte originalFirstByte = rootBytes[0];
                rootBytes[0] ^= 0xFF;
                AssertTrue(resources.ReadBytes("VsHydra.dat:vsDataHydra")[0] == originalFirstByte, "HSD root byte reads should return a defensive copy");
                rootBytes[0] = originalFirstByte;

                KarProjectResourceByteInfo missingRootBytes = project.GetResourceByteInfo("VsHydra.dat:vsDataHydra");
                AssertTrue(missingRootBytes.Status == KarProjectResourceByteOutputStatus.Missing, "resource byte info should report missing dump outputs");
                AssertTrue(missingRootBytes.ActiveLength == rootBytes.Length && missingRootBytes.ActiveSha256.Length == 64, "resource byte info should expose active byte length and hash");

                KarProjectResourceByteDumpResult rootDump = project.DumpResourceBytesToOutput("VsHydra.dat:vsDataHydra");
                AssertTrue(rootDump.Address == "VsHydra.dat:vsDataHydra", "project resource byte dumps should preserve root resource addresses");
                AssertTrue(rootDump.OutputRelativePath == "resource-bytes/VsHydra.dat/vsDataHydra.bin", "HSD root byte dumps should use stable output asset paths");
                AssertTrue(rootDump.WroteOutput && rootDump.Length == rootBytes.Length, "HSD root byte dumps should write root struct bytes");
                AssertTrue(rootDump.Sha256.Length == 64, "resource byte dumps should include a content hash");
                AssertTrue(File.ReadAllBytes(rootDump.OutputPath).SequenceEqual(rootBytes), "HSD root byte dumps should write the raw struct payload");
                KarProjectResourceActionPlan skippedDumpPlan = resources.GetActionPlan("VsHydra.dat:vsDataHydra", "dump-bytes");
                AssertTrue(skippedDumpPlan.CanRun && !skippedDumpPlan.WouldWriteOutput && skippedDumpPlan.Reason.Contains("overwrite"), "resource action plans should preview skipped existing byte dumps");
                KarProjectResourceActionPlan overwriteDumpPlan = resources.GetActionPlan("VsHydra.dat:vsDataHydra", "dump-bytes", overwrite: true);
                AssertTrue(overwriteDumpPlan.WouldWriteOutput && overwriteDumpPlan.Overwrite, "resource action plans should honor overwrite previews");

                KarProjectResourceByteInfo matchingRootBytes = resources.GetByteInfo("VsHydra.dat:vsDataHydra");
                AssertTrue(matchingRootBytes.Status == KarProjectResourceByteOutputStatus.MatchesActive, "resource byte info should compare dumps against active bytes");
                AssertTrue(matchingRootBytes.HasOutput && matchingRootBytes.OutputSha256 == matchingRootBytes.ActiveSha256, "resource byte info should expose matching output hashes");

                File.WriteAllBytes(rootDump.OutputPath, new byte[] { 0x99 });
                KarProjectResourceByteInfo staleRootBytes = resources.GetByteInfo("VsHydra.dat:vsDataHydra");
                AssertTrue(staleRootBytes.Status == KarProjectResourceByteOutputStatus.DiffersFromActive, "resource byte info should detect stale dump outputs");
                IReadOnlyList<KarProjectResourceByteInfo> staleDumps = project.QueryResourceByteInfo(new KarProjectResourceByteQueryOptions
                {
                    Status = KarProjectResourceByteOutputStatus.DiffersFromActive,
                });
                AssertTrue(staleDumps.Count == 1 && staleDumps[0].Address == "VsHydra.dat:vsDataHydra", "resource byte info queries should filter stale dump outputs");

                KarProjectResourceByteDumpResult skippedRootDump = resources.DumpBytesToOutput("VsHydra.dat:vsDataHydra");
                AssertTrue(!skippedRootDump.WroteOutput, "resource byte dumps should skip existing outputs unless overwrite is requested");
                KarProjectResourceByteDumpResult overwrittenRootDump = resources.DumpBytesToOutput("VsHydra.dat:vsDataHydra", overwrite: true);
                AssertTrue(overwrittenRootDump.WroteOutput, "resource byte dumps should overwrite outputs when requested");
                AssertTrue(resources.GetByteInfo("VsHydra.dat:vsDataHydra").Status == KarProjectResourceByteOutputStatus.MatchesActive, "overwritten byte dumps should match active bytes");

                KarProjectResourceByteDumpResult entryDump = resources.DumpBytesToOutput("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(entryDump.OutputRelativePath == "resource-bytes/A2Info.dat/ScInfGo2D.tm.bin", "A2D entry byte dumps should use stable output asset paths");
                AssertTrue(File.ReadAllBytes(entryDump.OutputPath).SequenceEqual(new byte[] { 0xA0, 0xB0, 0xC0, 0xD0 }), "A2D entry byte dumps should write the selected entry bytes");
                AssertTrue(resources.QueryByteInfo(new KarProjectResourceByteQueryOptions
                {
                    Resources = new KarProjectResourceQueryOptions
                    {
                        Kind = KarResourceKind.A2DEntry,
                    },
                    HasOutput = true,
                }).Count == 1, "resource byte info queries should filter dump outputs by resource kind and output presence");

                IReadOnlyList<KarProjectResourceByteDumpResult> fileByteDumps = resources.DumpBytesToOutput(new KarProjectResourceByteQueryOptions
                {
                    Resources = new KarProjectResourceQueryOptions
                    {
                        Kind = KarResourceKind.File,
                    },
                    HasOutput = false,
                });
                AssertTrue(fileByteDumps.Count == 2 && fileByteDumps.All(result => result.WroteOutput), "resource byte dump batches should write missing file byte outputs");
                AssertTrue(fileByteDumps.Any(result => result.OutputRelativePath == "resource-bytes/A2Info.dat.bin"), "resource byte dump batches should preserve file resource paths without colliding with child resources");

                IReadOnlyList<KarProjectResourceByteDumpResult> entryByteDumps = project.DumpResourceBytesToOutput(new KarProjectResourceByteQueryOptions
                {
                    Resources = new KarProjectResourceQueryOptions
                    {
                        Kind = KarResourceKind.A2DEntry,
                    },
                }, overwrite: true);
                AssertTrue(entryByteDumps.Count == 2 && entryByteDumps.All(result => result.WroteOutput), "project resource byte dump batches should overwrite selected resource kinds");

                KarProjectResourceExportResult fileExport = resources.ExportToOutput("A2Info.dat");
                AssertTrue(fileExport.Address == "A2Info.dat", "resource file export should report resource address");
                AssertTrue(fileExport.OutputKind == KarProjectResourceOutputKind.ProjectFile, "resource file export should write project file outputs");
                AssertTrue(fileExport.OutputRelativePath == "A2Info.dat", "resource file export should report output-relative project path");
                AssertTrue(fileExport.WroteOutput, "resource file export should write missing project outputs");
                AssertTrue(File.ReadAllBytes(fileExport.OutputPath).SequenceEqual(packageBytes), "resource file export should copy source bytes to output");

                KarProjectResourceExportResult skippedFileExport = resources.ExportToOutput("A2Info.dat");
                AssertTrue(!skippedFileExport.WroteOutput, "resource file export should skip existing outputs unless overwrite is requested");

                KarProjectResourceExportResult rootExport = project.ExportResourceToOutput("VsHydra.dat:vsDataHydra");
                AssertTrue(rootExport.Address == "VsHydra.dat:vsDataHydra", "project resource export wrapper should preserve root resource addresses");
                AssertTrue(rootExport.OutputKind == KarProjectResourceOutputKind.ProjectFile, "HSD root resource export should stage its containing archive");
                AssertTrue(File.Exists(rootExport.OutputPath), "HSD root resource export should create an output archive");
                AssertTrue(project.OutputService.GetFile("VsHydra.dat").Status == KarProjectOutputFileStatus.MatchesSource, "HSD root resource export should register as an unchanged staged archive");

                KarProjectResourceExportResult entryExport = resources.ExportToOutput("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(entryExport.OutputKind == KarProjectResourceOutputKind.OutputAsset, "A2D resource export should write output assets");
                AssertTrue(entryExport.OutputRelativePath == "a2d-entries/A2Info.dat/ScInfGo2D.tm", "A2D resource export should report stable sidecar paths");
                AssertTrue(entryExport.WroteOutput, "A2D resource export should write missing sidecar outputs");
                AssertTrue(File.ReadAllBytes(entryExport.OutputPath).SequenceEqual(new byte[] { 0xA0, 0xB0, 0xC0, 0xD0 }), "A2D resource export should extract entry bytes to output sidecars");
                AssertTrue(!File.Exists(project.FileService.GetOutputPath("A2Info.dat")) || File.ReadAllBytes(project.FileService.GetOutputPath("A2Info.dat")).SequenceEqual(packageBytes), "A2D resource export should not mutate source packages");
                KarProjectResourceExportResult resolvedExport = project.ResourceAddressService.ExportToOutput(resolvedEntry, overwrite: true);
                AssertTrue(resolvedExport.Address == "A2Info.dat#ScInfGo2D.tm" && resolvedExport.WroteOutput, "resource address services should export resolved resources");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectResourceServiceImportsResourcesSafely()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-resource-import-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            string inputRoot = tempRoot + "_inputs";
            Directory.CreateDirectory(tempRoot);
            Directory.CreateDirectory(inputRoot);

            string packagePath = Path.Combine(tempRoot, "A2Info.dat");
            string loosePath = Path.Combine(tempRoot, "Loose.bin");
            WriteHsdFile(Path.Combine(tempRoot, "VsHydra.dat"), "vsDataHydra", new KAR_vsLegendaryData());
            WriteA2DPackage(packagePath, new[] { "ScInfGo2D.tm", "readme.bin" });
            File.WriteAllBytes(loosePath, new byte[] { 0x44, 0x55 });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectResourceService resources = project.ResourceService;

                string fileReplacementPath = Path.Combine(inputRoot, "loose-replacement.bin");
                File.WriteAllBytes(fileReplacementPath, new byte[] { 0x66, 0x77, 0x88 });
                KarProjectResourceImportResult fileImport = resources.ImportFromFile("Loose.bin", fileReplacementPath);
                AssertTrue(fileImport.OutputKind == KarProjectResourceOutputKind.ProjectFile, "file resource imports should write project file outputs");
                AssertTrue(fileImport.OutputRelativePath == "Loose.bin", "file resource imports should report output-relative file paths");
                AssertTrue(fileImport.InputLength == 3, "file resource imports should report input lengths");
                AssertTrue(File.ReadAllBytes(fileImport.OutputPath).SequenceEqual(new byte[] { 0x66, 0x77, 0x88 }), "file resource imports should write replacement bytes to output");
                AssertTrue(File.ReadAllBytes(loosePath).SequenceEqual(new byte[] { 0x44, 0x55 }), "file resource imports should not mutate source files");

                string entryReplacementPath = Path.Combine(inputRoot, "ScInfGo2D.tm");
                File.WriteAllBytes(entryReplacementPath, new byte[] { 0x11, 0x22, 0x33, 0x44 });
                KarProjectResourceImportResult entryImport = project.ImportResourceFromFile("A2Info.dat#ScInfGo2D.tm", entryReplacementPath);
                AssertTrue(entryImport.Address == "A2Info.dat#ScInfGo2D.tm", "project resource import wrapper should preserve resource addresses");
                AssertTrue(entryImport.OutputKind == KarProjectResourceOutputKind.ProjectFile, "A2D resource imports should write output packages");
                AssertTrue(entryImport.OutputRelativePath == "A2Info.dat", "A2D resource imports should report package output paths");
                AssertTrue(entryImport.A2DReplaceResult.ReplacementLength == 4, "A2D resource imports should report replacement lengths");
                AssertTrue(resources.ReadBytes("A2Info.dat#ScInfGo2D.tm").SequenceEqual(new byte[] { 0x11, 0x22, 0x33, 0x44 }), "A2D resource reads should see imported output package bytes");

                KarProjectResolvedResource resolvedEntry = project.ResolveResourceAddress("A2Info.dat#ScInfGo2D.tm");
                File.WriteAllBytes(entryReplacementPath, new byte[] { 0x21, 0x22, 0x23, 0x24 });
                KarProjectResourceImportResult resolvedImport = project.ResourceAddressService.ImportFromFile(resolvedEntry, entryReplacementPath);
                AssertTrue(resolvedImport.Address == "A2Info.dat#ScInfGo2D.tm", "resource address services should import resolved resources");
                AssertTrue(project.ResourceAddressService.ReadBytes(resolvedEntry).SequenceEqual(new byte[] { 0x21, 0x22, 0x23, 0x24 }), "resolved resource reads should see imported output bytes");

                A2DPackage sourceOnlyPackage;
                string error;
                AssertTrue(A2DPackage.TryOpen(packagePath, out sourceOnlyPackage, out error), "source A2D package should still parse after resource import");
                AssertTrue(sourceOnlyPackage.GetEntryData(0).SequenceEqual(new byte[] { 0xA0, 0xB0, 0xC0, 0xD0 }), "A2D resource imports should not mutate source packages");

                AssertThrows<NotSupportedException>(
                    () => resources.ImportFromFile("VsHydra.dat:vsDataHydra", entryReplacementPath),
                    "HSD root resource imports should require structured editing");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
                if (Directory.Exists(inputRoot))
                    Directory.Delete(inputRoot, true);
            }
        }

        private static void ProjectResourceServiceWritesScalarEditsToOutput()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-resource-edit-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            try
            {
                WriteFieldQueryFixture(tempRoot);

                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectResourceService resources = project.ResourceService;

                KarProjectResourceScalarEditResult result = resources.SetScalarFieldFromText(
                    "VsHydra.dat:vsDataHydra",
                    "x0C",
                    "0x1F4");

                AssertTrue(result.Address == "VsHydra.dat:vsDataHydra", "resource scalar edits should report resource addresses");
                AssertTrue(result.Resource.IsHsdRoot, "resource scalar edits should retain HSD root resources");
                AssertTrue(result.Edit.RootName == "vsDataHydra", "resource scalar edits should edit the addressed root");
                AssertTrue(result.Edit.Field.Name == "x0C", "resource scalar edits should retain edited field metadata");
                AssertTrue(result.Edit.PreviousValue.SignedValue == 303, "resource scalar edits should report previous values");
                AssertTrue(result.Edit.NewValue.SignedValue == 500, "resource scalar edits should parse text values through the edit service");
                AssertTrue(File.Exists(result.OutputPath), "resource scalar edits should save edited archives to output");
                AssertTrue(project.OutputService.GetFile("VsHydra.dat").Status == KarProjectOutputFileStatus.DiffersFromSource, "resource scalar edits should register modified output archives");

                KarProjectResolvedResource resolvedHydra = project.ResolveResourceAddress("VsHydra.dat:vsDataHydra");
                AssertTrue(resolvedHydra.CanSetScalarFields, "resolved HSD roots should expose scalar edit capability");
                KarProjectResourceScalarEditResult addressResult = project.ResourceAddressService.SetScalarFieldFromText(
                    resolvedHydra,
                    "x0C",
                    "0x259");
                AssertTrue(addressResult.Edit.NewValue.SignedValue == 601, "resource address services should edit scalar fields on resolved roots");

                KarProjectFieldInfo editedField = project.DataService.QueryFieldValues(new KarProjectFieldQueryOptions
                {
                    DataDefinitionIdOrAccessorTypeName = "kar.vs.legendary",
                    FieldName = "x0C",
                }).Single(field => field.RelativePath == "VsHydra.dat");
                AssertTrue(editedField.Value.SignedValue == 601, "project data queries should read address-service scalar edits from output copies");

                KarArchiveInfo sourceInfo = project.ArchiveInspector.Inspect(
                    project.FileService.Get("VsHydra.dat"),
                    new HSDRawFile(project.FileService.GetSourcePath("VsHydra.dat")));
                AssertTrue(sourceInfo.GetRootByDataDefinition("kar.vs.legendary").GetFieldValue("x0C").SignedValue == 303, "resource scalar edits should not mutate source files");

                KarProjectResourceScalarEditResult wrapperResult = project.SetResourceScalarFieldFromText(
                    "GrCity1.dat:grDataCity1",
                    "unknown1",
                    "808");
                AssertTrue(wrapperResult.Edit.NewValue.SignedValue == 808, "project resource scalar edit wrapper should delegate to resource service");
                AssertTrue(project.OutputService.GetFile("GrCity1.dat").Status == KarProjectOutputFileStatus.DiffersFromSource, "resource scalar edits by root address should save modified output files");

                AssertThrows<NotSupportedException>(
                    () => resources.SetScalarFieldFromText("VsHydra.dat", "x0C", "1"),
                    "resource scalar edits should reject non-root resource addresses");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectResourceServiceReportsUnifiedOutputStatus()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-resource-output-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            string inputRoot = tempRoot + "_inputs";
            Directory.CreateDirectory(tempRoot);
            Directory.CreateDirectory(inputRoot);

            WriteHsdFile(Path.Combine(tempRoot, "VsHydra.dat"), "vsDataHydra", new KAR_vsLegendaryData());
            WriteA2DPackage(Path.Combine(tempRoot, "A2Info.dat"), new[] { "ScInfGo2D.tm", "readme.bin" });
            File.WriteAllBytes(Path.Combine(tempRoot, "Loose.bin"), new byte[] { 0x44, 0x55 });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectResourceService resources = project.ResourceService;

                KarProjectResourceOutputInfo missingFile = resources.GetOutput("Loose.bin");
                AssertTrue(missingFile.Status == KarProjectResourceOutputStatus.Missing, "resource output status should report missing file outputs");
                AssertTrue(!missingFile.HasOutput, "resource output status should flag missing outputs");

                KarProjectResourceExportResult fileExport = resources.ExportToOutput("Loose.bin");
                KarProjectResourceOutputInfo copiedFile = resources.GetOutput("Loose.bin");
                AssertTrue(copiedFile.Status == KarProjectResourceOutputStatus.MatchesSource, "resource output status should report copied files as unchanged");
                AssertTrue(copiedFile.ProjectFileOutput.OutputPath == fileExport.OutputPath, "resource output status should include project file output metadata");

                string looseReplacementPath = Path.Combine(inputRoot, "Loose.bin");
                File.WriteAllBytes(looseReplacementPath, new byte[] { 0x66, 0x77, 0x88 });
                resources.ImportFromFile("Loose.bin", looseReplacementPath);
                AssertTrue(project.GetResourceOutput("Loose.bin").Status == KarProjectResourceOutputStatus.DiffersFromSource, "project resource output wrapper should report file imports as modified");

                KarProjectResourceOutputInfo missingEntry = resources.GetOutput("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(missingEntry.Status == KarProjectResourceOutputStatus.Missing, "resource output status should report missing A2D sidecars and package edits");

                KarProjectResourceExportResult entryExport = resources.ExportToOutput("A2Info.dat#ScInfGo2D.tm");
                KarProjectResourceOutputInfo extractedEntry = resources.GetOutput("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(extractedEntry.Status == KarProjectResourceOutputStatus.SidecarMatchesEntry, "resource output status should report extracted A2D sidecars that match active entries");
                AssertTrue(extractedEntry.OutputKind == KarProjectResourceOutputKind.OutputAsset, "resource output status should report A2D sidecars as output assets");
                AssertTrue(extractedEntry.A2DEntryOutput.OutputPath == entryExport.OutputPath, "resource output status should include A2D sidecar output metadata");

                File.WriteAllBytes(entryExport.OutputPath, new byte[] { 0x11, 0x22, 0x33, 0x44 });
                AssertTrue(resources.GetOutput("A2Info.dat#ScInfGo2D.tm").Status == KarProjectResourceOutputStatus.SidecarDiffersFromEntry, "resource output status should detect modified A2D sidecars");

                File.Delete(entryExport.OutputPath);
                string entryReplacementPath = Path.Combine(inputRoot, "ScInfGo2D.tm");
                File.WriteAllBytes(entryReplacementPath, new byte[] { 0x11, 0x22, 0x33, 0x44 });
                resources.ImportFromFile("A2Info.dat#ScInfGo2D.tm", entryReplacementPath);
                KarProjectResourceOutputInfo importedEntry = resources.GetOutput("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(importedEntry.Status == KarProjectResourceOutputStatus.DiffersFromSource, "resource output status should compare A2D output package entries against source entries");
                AssertTrue(importedEntry.OutputKind == KarProjectResourceOutputKind.ProjectFile, "resource output status should report imported A2D entries as package outputs");
                AssertTrue(importedEntry.HasProjectFileOutput, "resource output status should include containing package output metadata");

                resources.ExportToOutput("VsHydra.dat:vsDataHydra");
                KarProjectResourceOutputInfo rootOutput = resources.GetOutput("VsHydra.dat:vsDataHydra");
                AssertTrue(rootOutput.Status == KarProjectResourceOutputStatus.MatchesSource, "resource output status should report exported HSD root archives through their containing file");

                IReadOnlyList<KarProjectResourceOutputInfo> modified = resources.QueryOutputs(new KarProjectResourceOutputQueryOptions
                {
                    Status = KarProjectResourceOutputStatus.DiffersFromSource,
                });
                AssertTrue(modified.Any(output => output.Address == "Loose.bin"), "resource output queries should filter modified file resources");
                AssertTrue(modified.Any(output => output.Address == "A2Info.dat#ScInfGo2D.tm"), "resource output queries should filter modified A2D entry resources");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
                if (Directory.Exists(inputRoot))
                    Directory.Delete(inputRoot, true);
            }
        }

        private static void ProjectResourceServiceAppliesModifiedResourceOutputs()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-resource-apply-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            string packagePath = Path.Combine(tempRoot, "A2Info.dat");
            WriteA2DPackage(packagePath, new[] { "ScInfGo2D.tm", "readme.bin" });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectResourceService resources = project.ResourceService;

                KarProjectResourceExportResult export = resources.ExportToOutput("A2Info.dat#ScInfGo2D.tm");
                File.WriteAllBytes(export.OutputPath, new byte[] { 0x11, 0x22, 0x33, 0x44 });
                AssertTrue(resources.GetOutput("A2Info.dat#ScInfGo2D.tm").Status == KarProjectResourceOutputStatus.SidecarDiffersFromEntry, "resource output status should find sidecars that need applying");

                IReadOnlyList<KarProjectResourceOutputApplyResult> applyResults = resources.ApplyModifiedOutputs(new KarProjectResourceOutputQueryOptions
                {
                    Resources = new KarProjectResourceQueryOptions
                    {
                        Address = "A2Info.dat#ScInfGo2D.tm",
                    },
                });
                AssertTrue(applyResults.Count == 1, "resource output apply should process modified sidecars");
                KarProjectResourceOutputApplyResult applied = applyResults[0];
                AssertTrue(applied.Address == "A2Info.dat#ScInfGo2D.tm", "resource output apply should report resource addresses");
                AssertTrue(applied.PackageRelativePath == "A2Info.dat", "resource output apply should report package paths");
                AssertTrue(applied.ReplacementLength == 4, "resource output apply should report replacement lengths");
                AssertTrue(File.Exists(applied.PackageOutputPath), "resource output apply should write output packages");
                AssertTrue(resources.ReadBytes("A2Info.dat#ScInfGo2D.tm").SequenceEqual(new byte[] { 0x11, 0x22, 0x33, 0x44 }), "resource reads should see applied sidecar bytes from output packages");
                AssertTrue(resources.GetOutput("A2Info.dat#ScInfGo2D.tm").Status == KarProjectResourceOutputStatus.SidecarMatchesEntry, "resource output status should settle after sidecar apply");

                File.WriteAllBytes(export.OutputPath, new byte[] { 0x21, 0x22, 0x23, 0x24 });
                KarProjectResourceOutputApplyResult singleApply = project.ApplyResourceOutput("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(singleApply.ReplacementLength == 4, "project resource output apply wrapper should delegate to resource service");
                AssertTrue(project.ReadResourceBytes("A2Info.dat#ScInfGo2D.tm").SequenceEqual(new byte[] { 0x21, 0x22, 0x23, 0x24 }), "project resource reads should see single applied sidecar bytes");
                AssertTrue(project.ApplyModifiedResourceOutputs().Count == 0, "resource output apply should find no modified sidecars after apply");

                A2DPackage sourcePackage;
                string error;
                AssertTrue(A2DPackage.TryOpen(packagePath, out sourcePackage, out error), "source package should still parse after resource output apply");
                AssertTrue(sourcePackage.GetEntryData(0).SequenceEqual(new byte[] { 0xA0, 0xB0, 0xC0, 0xD0 }), "resource output apply should not mutate source packages");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectOutputInventoryTracksModFiles()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-output-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            WriteHsdFile(Path.Combine(tempRoot, "GrCity1.dat"), "grDataCity1", new KAR_grData());
            File.WriteAllBytes(Path.Combine(tempRoot, "A2Demo.dat"), new byte[] { 0x22 });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                project.CopyToOutput("GrCity1.dat", true);
                project.WriteFileBytes("A2Demo.dat", new byte[] { 0x66, 0x77 });
                project.WriteFileBytes("Loose.dat", new byte[] { 0x33, 0x44, 0x55 });

                KarProjectOutputService outputs = project.OutputService;
                KarProjectOutputInventory inventory = outputs.CreateInventory();

                AssertTrue(object.ReferenceEquals(outputs.Project, project), "output service should retain project context");
                AssertTrue(outputs.Root == project.OutputRoot, "output service should expose the project output root");
                AssertTrue(outputs.FilesRoot == project.OutputFilesRoot, "output service should expose the project output files root");
                AssertTrue(inventory.Count == 3, "output inventory should count staged output files");
                AssertTrue(inventory.ProjectFileCount == 2, "output inventory should count output files tied to source project files");
                AssertTrue(inventory.OrphanFileCount == 1, "output inventory should count output-only files");
                AssertTrue(inventory.UnchangedProjectFileCount == 1, "output inventory should count unchanged project outputs");
                AssertTrue(inventory.ModifiedProjectFileCount == 1, "output inventory should count modified project outputs");

                KarProjectOutputFileInfo projectOutput = inventory.ProjectFiles.Single(file => file.RelativePath == "GrCity1.dat");
                AssertTrue(projectOutput.Kind == KarFileKind.MapData, "output inventory should keep source file kind for project files");
                AssertTrue(projectOutput.HasSourceFile, "output inventory should attach source metadata for project files");
                AssertTrue(projectOutput.IsSameLengthAsSource == true, "output inventory should compare source/output lengths");
                AssertTrue(projectOutput.IsSameContentAsSource == true, "output inventory should compare source/output hashes");
                AssertTrue(projectOutput.Status == KarProjectOutputFileStatus.MatchesSource, "output inventory should mark copied files as unchanged");

                KarProjectOutputFileInfo modified = inventory.ProjectFiles.Single(file => file.RelativePath == "A2Demo.dat");
                AssertTrue(modified.Status == KarProjectOutputFileStatus.DiffersFromSource, "output inventory should mark edited project outputs as modified");
                AssertTrue(modified.IsSameContentAsSource == false, "output inventory should expose modified content comparison");
                AssertTrue(!string.IsNullOrEmpty(modified.OutputSha256), "output inventory should hash output files");
                AssertTrue(!string.IsNullOrEmpty(modified.SourceSha256), "output inventory should hash source files");

                KarProjectOutputFileInfo orphan = inventory.OrphanFiles.Single(file => file.RelativePath == "Loose.dat");
                AssertTrue(orphan.Kind == KarFileKind.HsdArchive, "output inventory should classify output-only files");
                AssertTrue(!orphan.HasSourceFile, "output inventory should leave source metadata empty for orphan files");
                AssertTrue(orphan.Status == KarProjectOutputFileStatus.Orphan, "output inventory should mark output-only files as orphan");
                AssertTrue(inventory.TotalOutputLength == projectOutput.OutputLength + modified.OutputLength + orphan.OutputLength, "output inventory should sum output file lengths");

                KarProjectOutputFileInfo outputByPath = outputs.GetFile("GrCity1.dat");
                AssertTrue(outputByPath.Status == KarProjectOutputFileStatus.MatchesSource, "output service should resolve output info by path");
                AssertTrue(outputs.HasFile("Loose.dat"), "output service should detect output-only files by path");
                KarProjectOutputFileInfo tryFile;
                AssertTrue(!outputs.TryGetFile("Missing.dat", out tryFile), "output service should report missing output files");
                AssertThrows<FileNotFoundException>(
                    () => outputs.GetFile("Missing.dat"),
                    "output service should throw for missing output files");

                AssertTrue(outputs.QueryFiles(new KarProjectOutputFileQueryOptions { Kind = KarFileKind.MapData }).Count == 1, "output query should filter by kind");
                AssertTrue(outputs.QueryFiles(new KarProjectOutputFileQueryOptions { IsProjectFile = false }).Count == 1, "output query should filter orphan files");
                AssertTrue(outputs.QueryFiles(new KarProjectOutputFileQueryOptions { Status = KarProjectOutputFileStatus.DiffersFromSource }).Count == 1, "output query should filter modified files");
                AssertTrue(outputs.QueryModifiedProjectFiles().Count == 1, "output service should query modified project files");
                AssertTrue(outputs.QueryUnchangedProjectFiles().Count == 1, "output service should query unchanged project files");
                AssertTrue(outputs.QueryOrphanFiles().Count == 1, "output service should query orphan output files");
                AssertTrue(outputs.QueryMissingSourceFiles().Count == 0, "output service should query missing-source output files");
                AssertTrue(project.QueryOutputFiles(new KarProjectOutputFileQueryOptions { Status = KarProjectOutputFileStatus.DiffersFromSource }).Count == 1, "project output query compatibility wrapper should delegate to output service");
                AssertTrue(project.CreateOutputInventory().Count == inventory.Count, "project output inventory compatibility wrapper should delegate to output service");

                KarProjectReport report = project.CreateReport(new KarProjectReportOptions
                {
                    OutputFiles = new KarProjectOutputFileQueryOptions { Kind = KarFileKind.MapData },
                });

                AssertTrue(report.OutputFileCount == 1, "project report should include filtered output inventory counts");
                AssertTrue(report.ProjectOutputFileCount == 1, "project report should count filtered project output files");
                AssertTrue(report.OrphanOutputFileCount == 0, "project report should count filtered orphan output files");
                AssertTrue(report.UnchangedProjectOutputFileCount == 1, "project report should count filtered unchanged project outputs");
                AssertTrue(report.ModifiedProjectOutputFileCount == 0, "project report should count filtered modified project outputs");
                AssertTrue(report.MapOutputCount == 1, "project report should count map outputs");
                AssertTrue(report.ModifiedMapOutputCount == 0, "project report should count modified map outputs");
                AssertTrue(report.CompleteMapOutputCount == 1, "project report should count complete filtered map outputs");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectModWorkspaceSummarizesOutputState()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-mod-workspace-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            File.WriteAllBytes(Path.Combine(tempRoot, "GrCity1.dat"), new byte[] { 0x10 });
            File.WriteAllBytes(Path.Combine(tempRoot, "GrCity1Model.dat"), new byte[] { 0x20 });
            File.WriteAllBytes(Path.Combine(tempRoot, "GrCity1Event.dat"), new byte[] { 0x30 });
            File.WriteAllBytes(Path.Combine(tempRoot, "Loose.bin"), new byte[] { 0x44, 0x55 });
            WriteA2DPackage(Path.Combine(tempRoot, "A2Info.dat"), new[] { "ScInfGo2D.tm", "readme.bin" });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectModWorkspaceService mods = project.ModWorkspaceService;

                project.CopyMapToOutput("City1");
                project.WriteFileBytes("Loose.bin", new byte[] { 0x66, 0x77, 0x88 });
                KarProjectA2DEntryExtractResult extract = project.ExtractA2DEntryToOutput("A2Info.dat#ScInfGo2D.tm");
                File.WriteAllBytes(extract.OutputPath, new byte[] { 0x11, 0x22, 0x33, 0x44 });
                KarProjectResourceByteDumpResult looseBytes = project.DumpResourceBytesToOutput("Loose.bin");
                File.WriteAllBytes(looseBytes.OutputPath, new byte[] { 0x99 });

                KarProjectModWorkspace workspace = mods.CreateSnapshot();
                AssertTrue(object.ReferenceEquals(mods.Project, project), "mod workspace service should retain project context");
                AssertTrue(object.ReferenceEquals(workspace.Project, project), "mod workspace snapshots should retain project context");
                AssertTrue(workspace.HasOutputs, "mod workspace snapshots should detect staged outputs");
                AssertTrue(workspace.HasModifiedOutputs, "mod workspace snapshots should detect modified outputs");
                AssertTrue(workspace.OutputFileCount == 6, "mod workspace snapshots should count project-file outputs and output assets");
                AssertTrue(workspace.ProjectOutputFileCount == 4, "mod workspace snapshots should count staged project files");
                AssertTrue(workspace.OrphanOutputFileCount == 2, "mod workspace snapshots should count output assets as output-only files when they share the output files root");
                AssertTrue(workspace.ModifiedProjectOutputFileCount == 1, "mod workspace snapshots should count modified project files");
                AssertTrue(workspace.UnchangedProjectOutputFileCount == 3, "mod workspace snapshots should count unchanged project files");
                AssertTrue(workspace.ResourceOutputCount == 5, "mod workspace snapshots should count resource outputs with staged data");
                AssertTrue(workspace.ProjectFileResourceOutputCount == 4, "mod workspace snapshots should count project-file resource outputs");
                AssertTrue(workspace.OutputAssetResourceOutputCount == 1, "mod workspace snapshots should count output asset resource outputs");
                AssertTrue(workspace.ModifiedResourceOutputCount == 2, "mod workspace snapshots should count modified project resources and sidecars");
                AssertTrue(workspace.ResourceByteOutputCount == 1, "mod workspace snapshots should count resource byte dumps");
                AssertTrue(workspace.ModifiedResourceByteOutputCount == 1 && workspace.MatchingResourceByteOutputCount == 0, "mod workspace snapshots should classify stale resource byte dumps");
                AssertTrue(workspace.A2DEntryOutputCount == 1, "mod workspace snapshots should count staged A2D sidecars");
                AssertTrue(workspace.ModifiedA2DEntryOutputCount == 1, "mod workspace snapshots should count modified A2D sidecars");
                AssertTrue(workspace.MapOutputCount == 1, "mod workspace snapshots should count maps with staged outputs");
                AssertTrue(workspace.CompleteMapOutputCount == 1, "mod workspace snapshots should count complete staged map outputs");
                AssertTrue(workspace.ModifiedMapOutputCount == 0, "mod workspace snapshots should count modified map outputs");
                AssertTrue(workspace.ModifiedResourceOutputs.Any(output => output.Address == "Loose.bin"), "mod workspace snapshots should include modified file resources");
                AssertTrue(workspace.ModifiedResourceOutputs.Any(output => output.Address == "A2Info.dat#ScInfGo2D.tm"), "mod workspace snapshots should include modified A2D sidecars");
                AssertTrue(workspace.ModifiedResourceByteOutputs.Single().Address == "Loose.bin", "mod workspace snapshots should include modified resource byte dumps");

                KarProjectModWorkspace wrapper = project.CreateModWorkspace(new KarProjectModWorkspaceOptions
                {
                    OutputFiles = new KarProjectOutputFileQueryOptions
                    {
                        Status = KarProjectOutputFileStatus.DiffersFromSource,
                    },
                });
                AssertTrue(wrapper.OutputFileCount == 1, "project mod workspace wrapper should delegate filtered output inventories");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectSessionExposesToolkitWorkspaceBoundary()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-session-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            byte[] sourceBytes = new byte[] { 0x10, 0x20, 0x30 };
            File.WriteAllBytes(Path.Combine(tempRoot, "Loose.bin"), sourceBytes);

            try
            {
                KarProjectSession session = KarProjectSession.Open(tempRoot, outputRoot);
                AssertTrue(session.Name == Path.GetFileName(tempRoot), "project sessions should expose project identity");
                AssertTrue(session.WritesOnlyToOutput && session.ReadsPreferOutputCopies, "project sessions should expose workspace read/write policy flags");
                AssertTrue(session.SourceAndOutputRootsAreSeparate && session.SourceFilesAndOutputFilesRootsAreSeparate, "project sessions should expose separated source/output roots");
                AssertTrue(session.WritePolicy.Contains("only under the configured output folder"), "project sessions should describe output-only writes");
                KarProjectContract projectContract = session.Project.CreateContract();
                AssertTrue(projectContract.Name == session.Name && projectContract.FileCount == session.FileCount && projectContract.Workspace.WritesOnlyToOutput, "project contracts should expose reusable project and workspace metadata");
                AssertTrue(session.Workspace.CreateContract().OutputRoot == session.OutputRoot, "workspace contracts should expose reusable workspace roots");
                KarProjectSessionContract sessionContract = session.CreateContract();
                AssertTrue(sessionContract.Name == session.Name && sessionContract.Project.Name == session.Name && sessionContract.Workspace.WritesOnlyToOutput, "project session contracts should expose reusable session and workspace metadata");
                AssertTrue(sessionContract.RegistryCatalog.ResourceActionDefinitionCount == session.ResourceActionDefinitionCount && sessionContract.Surface.WorkflowCount == session.WorkflowCount, "project session contracts should include registry and toolkit surface contracts");
                AssertTrue(sessionContract.Surface.WorkflowGroups.Count == session.Surface.WorkflowGroupCount && sessionContract.Surface.Domains.Any(domain => domain.Id == "files"), "project session contracts should preserve grouped toolkit workflows and domains");
                AssertTrue(session.Project.CreateSessionContract().Surface.WorkflowGroupCount == session.Surface.WorkflowGroupCount, "project wrappers should expose session contracts");
                AssertTrue(object.ReferenceEquals(session.Surface.Project, session.Project), "project sessions should attach a toolkit surface for the same project");
                AssertTrue(object.ReferenceEquals(session.RegistryCatalog.Project, session.Project), "project sessions should attach the active registry catalog for the same project");
                AssertTrue(session.RegistryCount == session.RegistryCatalog.RegistryCount && session.ResourceActionDefinitionCount == session.RegistryCatalog.ResourceActionDefinitionCount, "project sessions should expose registry catalog counts");
                AssertTrue(session.Project.ToolkitService.CreateRegistryCatalogContract().ProjectName == session.Name, "toolkit service should expose reusable registry catalog contracts");
                AssertTrue(session.FileKindCount > 0 && session.FileHandlerCount > 0 && session.ResourceHandlerCount > 0, "project sessions should expose file and resource toolkit registries");
                AssertTrue(session.OperationDomainRuleCount >= 6 && session.DomainContextProviderCount >= 7 && session.ToolkitWorkflowProviderCount >= 1 && session.OperationPresetDefinitionCount >= 6, "project sessions should expose operation, context, and workflow toolkit registries");
                AssertTrue(session.DomainCount == session.Domains.Count && session.WorkflowCount == session.Workflows.Count, "project sessions should expose toolkit domains and workflows");
                AssertTrue(session.WorkflowGroups.Count == session.Surface.WorkflowGroupCount, "project sessions should expose grouped workflows");

                session.Project.WriteFileBytes("Loose.bin", new byte[] { 0x99 });

                AssertTrue(File.ReadAllBytes(Path.Combine(tempRoot, "Loose.bin")).SequenceEqual(sourceBytes), "project session writes should not mutate source files");
                AssertTrue(File.ReadAllBytes(Path.Combine(outputRoot, "Loose.bin")).SequenceEqual(new byte[] { 0x99 }), "project session writes should stage changed copies under output");
                KarProjectFileInsight looseInsight = session.Project.GetFileInsight("Loose.bin");
                AssertTrue(looseInsight.HasOutputCopy && looseInsight.HasModifiedOutput && looseInsight.DomainIds.Contains("mod-output"), "file insights should expose output-copy state without mutating source files");
                KarProjectFileInsightContract looseInsightContract = session.Project.GetFileInsightContract("Loose.bin");
                AssertTrue(looseInsightContract.File.RelativePath == "Loose.bin" && looseInsightContract.HasModifiedOutput, "file insight contracts should preserve compact file and output state");

                KarProjectSession refreshed = session.Refresh();
                AssertTrue(refreshed.HasOutputs && refreshed.HasModifiedOutputs, "refreshed project sessions should report output state");

                KarProjectSession wrapper = session.Project.CreateSession(new KarProjectToolkitSnapshotOptions
                {
                    IncludeModWorkspace = false,
                });
                AssertTrue(object.ReferenceEquals(wrapper.Project, session.Project), "project session wrappers should reuse the existing project");
                AssertTrue(!wrapper.Snapshot.HasModWorkspace, "project session wrappers should honor snapshot options");

                KarProjectSession openedByProject = KarProject.OpenSession(tempRoot, outputRoot, new KarProjectToolkitSnapshotOptions
                {
                    IncludeMapContexts = false,
                    IncludeVehicleContexts = false,
                    IncludeA2DPackageContexts = false,
                    IncludeScriptTableContexts = false,
                });
                AssertTrue(openedByProject.SourceRoot == session.SourceRoot && openedByProject.OutputRoot == session.OutputRoot, "project session open wrappers should preserve workspace roots");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectModManifestIndexesOutputArtifacts()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-manifest-project-" + Guid.NewGuid().ToString("N"));
            string filesRoot = Path.Combine(tempRoot, "files");
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(filesRoot);

            byte[] sourceBytes = new byte[] { 0x10, 0x20, 0x30 };
            File.WriteAllBytes(Path.Combine(filesRoot, "Loose.bin"), sourceBytes);
            WriteA2DPackage(Path.Combine(filesRoot, "A2Info.dat"), new[] { "ScInfGo2D.tm", "readme.bin" });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                project.WriteFileBytes("Loose.bin", new byte[] { 0x66, 0x77 });
                KarProjectA2DEntryExtractResult extract = project.ExtractA2DEntryToOutput("A2Info.dat#ScInfGo2D.tm");
                File.WriteAllBytes(extract.OutputPath, new byte[] { 0x01, 0x02, 0x03, 0x04 });
                KarProjectResourceByteDumpResult byteDump = project.DumpResourceBytesToOutput("Loose.bin");
                File.WriteAllBytes(byteDump.OutputPath, new byte[] { 0x99 });

                KarProjectModManifest manifest = project.CreateModManifest();
                AssertTrue(manifest.ArtifactCount == 3, "mod manifests should flatten project files, A2D sidecars, and resource byte dumps");
                AssertTrue(manifest.ProjectFileArtifactCount == 1, "mod manifests should count project-file artifacts");
                AssertTrue(manifest.A2DEntrySidecarArtifactCount == 1, "mod manifests should count A2D sidecar artifacts");
                AssertTrue(manifest.ResourceByteDumpArtifactCount == 1, "mod manifests should count resource byte dump artifacts");
                AssertTrue(manifest.OutputOnlyFileArtifactCount == 0, "mod manifests should not duplicate richer output assets as orphan files");
                AssertTrue(manifest.ModifiedArtifactCount == 3, "mod manifests should count modified/stale artifacts");
                AssertTrue(manifest.NeedsApplyArtifactCount == 1, "mod manifests should flag modified A2D sidecars that need package apply");
                AssertTrue(manifest.TotalOutputLength == 7, "mod manifests should sum artifact output lengths");
                AssertTrue(manifest.WritesOnlyToOutput && manifest.SourceAndOutputRootsAreSeparate, "mod manifests should carry workspace safety flags");

                KarProjectModManifestArtifact projectFile = manifest.ProjectFileArtifacts.Single();
                AssertTrue(projectFile.OutputRelativePath == "files/Loose.bin", "project file artifacts should be relative to the output root");
                AssertTrue(projectFile.ProjectRelativePath == "Loose.bin", "project file artifacts should keep project-relative paths");
                AssertTrue(projectFile.ReferenceKind == "source-file" && projectFile.ReferenceLength == sourceBytes.Length, "project file artifacts should reference source files");
                AssertTrue(projectFile.IsModified && !projectFile.IsOutputOnly && !projectFile.NeedsApply, "project file artifacts should expose modified source comparison");

                KarProjectModManifestArtifact sidecar = manifest.A2DEntrySidecarArtifacts.Single();
                AssertTrue(sidecar.OutputRelativePath == "a2d-entries/A2Info.dat/ScInfGo2D.tm", "A2D sidecar artifacts should be output-root relative");
                AssertTrue(sidecar.ResourceAddress == "A2Info.dat#ScInfGo2D.tm", "A2D sidecar artifacts should keep resource addresses");
                AssertTrue(sidecar.ReferenceKind == "a2d-entry" && sidecar.IsSidecar && sidecar.NeedsApply, "A2D sidecar artifacts should flag sidecar apply state");

                KarProjectModManifestArtifact resourceBytes = manifest.ResourceByteDumpArtifacts.Single();
                AssertTrue(resourceBytes.OutputRelativePath == "resource-bytes/Loose.bin.bin", "resource byte artifacts should be output-root relative");
                AssertTrue(resourceBytes.ResourceAddress == "Loose.bin", "resource byte artifacts should keep resource addresses");
                AssertTrue(resourceBytes.ReferenceKind == "active-resource" && resourceBytes.ReferenceLength == 2, "resource byte artifacts should reference active resource bytes");
                AssertTrue(resourceBytes.IsModified && !resourceBytes.NeedsApply, "resource byte artifacts should flag stale dumps without apply requirements");

                KarProjectSession session = project.CreateSession();
                AssertTrue(session.ModManifest.ArtifactCount == manifest.ArtifactCount, "project sessions should expose the current mod manifest");
                AssertTrue(project.CreateModManifest(new KarProjectModWorkspaceOptions
                {
                    ResourceByteOutputs = new KarProjectResourceByteQueryOptions { HasOutput = true },
                }).ResourceByteDumpArtifactCount == 1, "project manifest wrappers should accept workspace filters");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectToolkitSnapshotAggregatesDomainContexts()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-snapshot-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            WriteHsdFile(Path.Combine(tempRoot, "GrCity1.dat"), "grDataCity1", new KAR_grData());
            WriteHsdFile(Path.Combine(tempRoot, "GrCity1Model.dat"), "grModelCity1", new KAR_grData());
            WriteHsdFile(Path.Combine(tempRoot, "GrCity1Event.dat"), "grEventDataAllCity1", new KAR_grData());
            WriteHsdFile(Path.Combine(tempRoot, "VcCommon.dat"), "vcDataCommon", new KAR_vcDataCommon());
            WriteHsdFile(Path.Combine(tempRoot, "VcStar.dat"), "vcDataKindStar", new KAR_vcDataKindStar());
            WriteHsdFile(Path.Combine(tempRoot, "VcStarWarp.dat"), "vcDataStarWarp", new KAR_vcDataStar());
            File.WriteAllBytes(Path.Combine(tempRoot, "ScInfPause.tm"), new byte[] { 0x40, 0x41 });
            WriteA2DPackage(Path.Combine(tempRoot, "A2Info.dat"), new[] { "ScInfGo2D.tm", "readme.bin" });
            File.WriteAllBytes(Path.Combine(tempRoot, "A2Broken.dat"), new byte[] { 0x10 });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                AssertTrue(object.ReferenceEquals(project.ToolkitService.Project, project), "toolkit service should retain project context");

                KarProjectResourceExportResult export = project.ExportScriptTableToOutput("A2Info.dat#ScInfGo2D.tm");
                File.WriteAllBytes(export.OutputPath, new byte[] { 0x11, 0x22, 0x33, 0x44 });
                project.DumpResourceBytesToOutput("ScInfPause.tm");

                KarProjectToolkitSnapshot snapshot = project.CreateToolkitSnapshot();
                AssertTrue(snapshot.FileCount == 9, "toolkit snapshots should expose project file counts");
                AssertTrue(snapshot.MapContextCount == 1, "toolkit snapshots should include map contexts");
                AssertTrue(snapshot.VehicleContextCount == 3, "toolkit snapshots should include vehicle contexts");
                AssertTrue(snapshot.A2DPackageContextCount == 2, "toolkit snapshots should include A2D package contexts");
                AssertTrue(snapshot.ScriptTableContextCount == 2, "toolkit snapshots should include script table contexts");
                AssertTrue(snapshot.A2DPackageOpenErrorCount == 1 && snapshot.HasDomainInspectionIssues, "toolkit snapshots should preserve domain inspection issues");
                AssertTrue(snapshot.ScriptTableOutputCount == 1 && snapshot.ModifiedScriptTableOutputCount == 1, "toolkit snapshots should summarize script output state");
                AssertTrue(snapshot.ResourceByteOutputCount == 1 && snapshot.ModifiedResourceByteOutputCount == 0, "toolkit snapshots should summarize resource byte dump state");
                AssertTrue(snapshot.HasOutputs && snapshot.HasModifiedOutputs, "toolkit snapshots should summarize mod output state");
                AssertTrue(snapshot.A2DPackageContexts.Single(context => context.RelativePath == "A2Info.dat").HasModifiedEntryOutputs, "toolkit snapshots should include package sidecar state");

                IReadOnlyList<KarProjectDomainContext> domains = project.QueryDomainContexts();
                AssertTrue(domains.Count == 7, "domain contexts should expose the current toolkit domain set");
                AssertTrue(project.DomainContextProviderRegistry.Providers.Select(provider => provider.Id).SequenceEqual(domains.Select(domain => domain.Id)), "domain context provider order should drive toolkit domain order");
                AssertTrue(project.DomainContextProviderRegistry.FindProvider("maps").CreateContract().ContextCommand == "map-context", "domain context providers should expose reusable provider contracts");
                AssertTrue(project.ToolkitWorkflowProviderRegistry.FindProvider("built-in-workflows").CreateContract().DisplayName == "Built-in Workflows", "toolkit workflow providers should expose reusable provider contracts");
                KarProjectDomainContext mapDomain = domains.Single(domain => domain.Id == "maps");
                AssertTrue(mapDomain.ItemCount == 1 && mapDomain.ResourceCount == 3 && mapDomain.ContextCommand == "map-context", "domain contexts should summarize map toolkit entry points");
                KarProjectDomainContextContract mapDomainContract = mapDomain.CreateContract();
                AssertTrue(mapDomainContract.Id == "maps" && mapDomainContract.ResourceCount == mapDomain.ResourceCount && mapDomainContract.ContextCommand == "map-context", "domain context contracts should preserve frontend-facing domain metadata");
                KarProjectDomainContext a2dDomain = domains.Single(domain => domain.Id == "a2d-packages");
                AssertTrue(a2dDomain.ItemCount == 2 && a2dDomain.ModifiedOutputCount == 1 && a2dDomain.HasInspectionIssues, "domain contexts should summarize A2D output and issue state");
                KarProjectDomainContext scriptDomain = domains.Single(domain => domain.Id == "script-tables");
                AssertTrue(scriptDomain.ItemCount == 2 && scriptDomain.ModifiedOutputCount == 1 && scriptDomain.ListCommand == "script-tables", "domain contexts should summarize script table outputs");
                KarProjectDomainContext outputDomain = project.ToolkitService.QueryDomainContexts().Single(domain => domain.Id == "mod-output");
                AssertTrue(outputDomain.HasOutputs && outputDomain.HasModifiedOutputs && outputDomain.ContextCommand == "mod-workspace", "domain contexts should summarize mod workspace state");

                IReadOnlyList<KarProjectFileInsight> fileInsights = project.QueryFileInsights();
                AssertTrue(fileInsights.Count == project.Files.Count, "file insights should cover the project file inventory");
                KarProjectFileInsight mapInsight = fileInsights.Single(insight => insight.RelativePath == "GrCity1.dat");
                AssertTrue(mapInsight.PrimaryDomainId == "maps" && mapInsight.DomainIds.Contains("archives") && mapInsight.MapName == "City1" && mapInsight.MapCount == 1, "file insights should classify map archives with map bundle metadata");
                KarProjectFileInsight a2dInsight = project.FileService.GetInsight("A2Info.dat");
                AssertTrue(a2dInsight.PrimaryDomainId == "a2d-packages" && a2dInsight.A2DEntryResourceCount == 2 && a2dInsight.ScriptTableResourceCount == 1, "file insights should summarize A2D packages and packaged script tables");
                AssertTrue(a2dInsight.DomainIds.Contains("script-tables") && a2dInsight.RelationshipCount == 1, "file insights should connect A2D script entries to toolkit domains and relationships");
                KarProjectFileInsight brokenA2DInsight = project.GetFileInsight("A2Broken.dat");
                AssertTrue(brokenA2DInsight.IsA2DPackage && brokenA2DInsight.HasInspectionError && brokenA2DInsight.A2DEntryResourceCount == 0, "file insights should keep broken A2D packages visible with inspection errors");
                KarProjectFileInsight scriptInsight = project.GetFileInsight("ScInfPause.tm");
                AssertTrue(scriptInsight.PrimaryDomainId == "script-tables" && scriptInsight.ScriptTableResourceCount == 1 && scriptInsight.DomainIds.Contains("script-tables"), "file insights should classify loose script tables");
                KarProjectFileInsight vehicleInsight = project.GetFileInsight("VcCommon.dat");
                AssertTrue(vehicleInsight.PrimaryDomainId == "vehicles" && vehicleInsight.VehicleBundleCount >= 2 && vehicleInsight.DomainIds.Contains("vehicles"), "file insights should attach shared vehicle bundle membership");
                KarProjectFileInsightContract a2dInsightContract = a2dInsight.CreateContract();
                AssertTrue(a2dInsightContract.File.KindInfo.IsA2DPackage && a2dInsightContract.A2DEntryResourceCount == 2 && a2dInsightContract.DomainIds.Contains("script-tables"), "file insight contracts should preserve domain labels and file-kind metadata");
                AssertTrue(project.FileService.QueryInsightContracts(new KarProjectFileQueryOptions { Domain = "script-tables" }).Any(insight => insight.RelativePath == "ScInfPause.tm"), "file services should expose reusable file insight contracts");
                KarProjectFileToolkitContext mapFileContext = project.GetFileToolkitContext("GrCity1.dat");
                AssertTrue(mapFileContext.HasArchiveContext && mapFileContext.MapContextCount == 1 && mapFileContext.ScriptTableContextCount >= 1 && mapFileContext.ResourceDetail != null, "file toolkit contexts should compose archive, map, script, and resource detail contexts");
                AssertTrue(mapFileContext.ArchiveContext.CreateContract().RootCount == mapFileContext.ArchiveContext.RootCount, "archive context contracts should preserve archive summary counts");
                AssertTrue(project.GetArchiveContextContract("GrCity1.dat").RelativePath == "GrCity1.dat", "project wrappers should expose archive context contracts");
                AssertTrue(project.QueryArchiveContextContracts(new KarProjectArchiveContextQueryOptions { RelativePath = "GrCity1.dat" }).Single().RootCount == mapFileContext.ArchiveContext.RootCount, "project wrappers should expose archive context contract queries");
                KarProjectFileToolkitContext a2dFileContext = project.FileService.GetToolkitContext("A2Info.dat");
                AssertTrue(a2dFileContext.HasA2DPackageContext && a2dFileContext.A2DPackageContext.EntryCount == 2 && a2dFileContext.ScriptTableContextCount == 1, "file toolkit contexts should compose A2D package and packaged script contexts");
                AssertTrue(a2dFileContext.CreateContract().A2DPackageContext.EntryCount == 2 && a2dFileContext.CreateContract().ScriptTableContexts.Any(script => script.Address == "A2Info.dat#ScInfGo2D.tm"), "file toolkit context contracts should expose compact A2D and script summaries");
                AssertTrue(project.GetA2DPackageContextContract("A2Info.dat").ScriptTableCount == 1 && project.QueryA2DPackageContextContracts().Any(context => context.RelativePath == "A2Info.dat"), "project wrappers should expose A2D package context contracts");
                KarProjectFileToolkitContext brokenA2DContext = project.GetFileToolkitContext("A2Broken.dat");
                AssertTrue(brokenA2DContext.HasA2DPackageContext && brokenA2DContext.HasInspectionIssues && brokenA2DContext.A2DPackageContext.EntryCount == 0, "file toolkit contexts should keep broken A2D package context errors visible");
                KarProjectFileToolkitContext scriptFileContext = project.GetFileToolkitContext("ScInfPause.tm");
                AssertTrue(scriptFileContext.ScriptTableContextCount == 1 && scriptFileContext.ScriptTableContexts.Single().IsLooseFile, "file toolkit contexts should compose loose script table contexts");
                AssertTrue(project.GetScriptTableContextContract("ScInfPause.tm").IsLooseFile && project.QueryScriptTableContextContracts().Any(context => context.Address == "ScInfPause.tm"), "project wrappers should expose script table context contracts");
                KarProjectFileToolkitContext vehicleFileContext = project.GetFileToolkitContext("VcCommon.dat");
                AssertTrue(vehicleFileContext.HasArchiveContext && vehicleFileContext.VehicleContextCount >= 2 && vehicleFileContext.CreateContract().VehicleContexts.Any(vehicle => vehicle.Name == "Common"), "file toolkit contexts should compose shared vehicle contexts");
                AssertTrue(project.GetMapContextContract("City1").MapName == "City1" && project.QueryMapContextContracts().Any(context => context.MapName == "City1"), "project wrappers should expose map context contracts");
                AssertTrue(project.GetVehicleContextContract("Common").Name == "Common" && project.QueryVehicleContextContracts().Any(context => context.Name == "Common"), "project wrappers should expose vehicle context contracts");
                AssertTrue(project.GetResourceDetailContract("ScInfPause.tm").Resource.Address == "ScInfPause.tm" && project.QueryResourceDetailContracts(new KarProjectResourceQueryOptions { Address = "ScInfPause.tm" }).Single().ActionCount != 0, "project wrappers should expose resource detail contracts");

                KarProjectToolkitSurface surface = project.CreateToolkitSurface();
                AssertTrue(surface.DomainCount == domains.Count && surface.WorkflowCount >= 20, "toolkit surfaces should combine domains with a workflow catalog");
                AssertTrue(surface.WorkflowCount == project.ToolkitWorkflowProviderRegistry.CreateWorkflows(project, snapshot, project.ResourceGraphService.Snapshot, domains).Count, "toolkit surfaces should compose workflows through the active workflow provider registry");
                AssertTrue(surface.WriteWorkflowCount != 0 && surface.OutputWorkflowCount >= surface.WriteWorkflowCount, "toolkit surfaces should summarize write-capable workflows");
                AssertTrue(surface.WorkflowGroupCount == surface.DomainCount + 1 && surface.WorkflowGroups.Sum(group => group.WorkflowCount) == surface.WorkflowCount, "toolkit surfaces should group workflows by domain plus project-level commands");
                KarProjectToolkitSurfaceContract surfaceContract = surface.CreateContract();
                AssertTrue(surfaceContract.Project.Name == project.Name && surfaceContract.WorkflowCount == surface.WorkflowCount && surfaceContract.WorkflowGroups.Count == surface.WorkflowGroupCount, "toolkit surface contracts should preserve project and grouped workflow metadata");
                AssertTrue(surfaceContract.HasOutputs && surfaceContract.HasModifiedOutputs && surfaceContract.HasDomainInspectionIssues, "toolkit surface contracts should expose compact output and issue state");
                AssertTrue(surfaceContract.Domains.Any(domain => domain.Id == "a2d-packages") && surfaceContract.Workflows.Any(workflow => workflow.Id == "apply-a2d-entry-outputs"), "toolkit surface contracts should include domain and workflow launcher metadata");
                AssertTrue(project.ToolkitService.CreateSurfaceContract().WorkflowCount == surface.WorkflowCount, "toolkit services should expose surface contracts");
                AssertTrue(project.CreateToolkitSurfaceContract().WorkflowGroupCount == surface.WorkflowGroupCount, "project wrappers should expose toolkit surface contracts");
                KarProjectToolkitWorkflowGroup projectGroup = surface.WorkflowGroups.First();
                AssertTrue(projectGroup.DomainId == "project" && !projectGroup.HasDomain && projectGroup.WorkflowCount >= 3, "toolkit workflow groups should expose project-level commands separately");
                KarProjectToolkitWorkflowGroup resourceGroup = surface.WorkflowGroups.Single(group => group.DomainId == "resources");
                AssertTrue(resourceGroup.HasDomain && resourceGroup.Domain.ContextCommand == "resource-contexts" && resourceGroup.Workflows.Any(workflow => workflow.Id == "edit-resource-data-field"), "toolkit workflow groups should attach domain metadata to grouped workflows");
                KarProjectToolkitWorkflowGroupContract resourceGroupContract = resourceGroup.CreateContract();
                AssertTrue(resourceGroupContract.Domain.Id == "resources" && resourceGroupContract.WorkflowCount == resourceGroup.WorkflowCount && resourceGroupContract.Workflows.Any(workflow => workflow.Id == "edit-resource-data-field"), "toolkit workflow group contracts should preserve domain and nested workflow metadata");
                KarProjectToolkitWorkflow editWorkflow = surface.Workflows.Single(workflow => workflow.Id == "edit-resource-data-field");
                AssertTrue(editWorkflow.Command == "resource-data-edit" && editWorkflow.WritesOutput && editWorkflow.RequiresValue && editWorkflow.TargetCount != 0, "toolkit workflows should expose resource data field edit commands");
                AssertTrue(editWorkflow.CommandLine == "kar-toolkit resource-data-edit" && editWorkflow.Usage.Contains("<field-path-or-name>") && editWorkflow.JsonUsage.EndsWith("[--json]"), "toolkit workflows should expose assembled CLI usage strings");
                KarProjectToolkitWorkflowContract editWorkflowContract = editWorkflow.CreateContract();
                AssertTrue(editWorkflowContract.CommandLine == editWorkflow.CommandLine && editWorkflowContract.JsonUsage == editWorkflow.JsonUsage && editWorkflowContract.RequiresValue, "toolkit workflow contracts should preserve assembled usage and argument metadata");
                KarProjectToolkitWorkflow dataFieldsWorkflow = surface.Workflows.Single(workflow => workflow.Id == "resource-data-fields");
                AssertTrue(dataFieldsWorkflow.IsReadOnly && dataFieldsWorkflow.TargetCount >= editWorkflow.TargetCount, "toolkit workflows should pair editable field writes with field discovery");
                KarProjectToolkitWorkflow importWorkflow = surface.Workflows.Single(workflow => workflow.Id == "import-resource-output");
                AssertTrue(importWorkflow.RequiresInputFile && importWorkflow.WritesOutput, "toolkit workflows should expose input-file requirements for import commands");
                KarProjectToolkitWorkflow applyA2DWorkflow = surface.Workflows.Single(workflow => workflow.Id == "apply-a2d-entry-outputs");
                AssertTrue(applyA2DWorkflow.SupportsBatch && applyA2DWorkflow.TargetCount == snapshot.ModifiedA2DEntryOutputCount, "toolkit workflows should surface batch apply targets for modified A2D sidecars");
                IReadOnlyList<KarProjectToolkitWorkflow> workflows = project.QueryToolkitWorkflows();
                AssertTrue(workflows.Count == surface.WorkflowCount && workflows.Any(workflow => workflow.Id == "map-context"), "project toolkit workflow wrappers should delegate to the toolkit service");
                IReadOnlyList<KarProjectToolkitWorkflow> resourceWrites = project.QueryToolkitWorkflows(new KarProjectToolkitWorkflowQueryOptions
                {
                    DomainId = "resources",
                    WritesOutput = true,
                });
                AssertTrue(resourceWrites.Count >= 4 && resourceWrites.All(workflow => workflow.DomainId == "resources" && workflow.WritesOutput), "toolkit workflow queries should filter writable workflows by domain");
                AssertTrue(project.ToolkitService.QueryWorkflows(new KarProjectToolkitWorkflowQueryOptions { Command = "resource-data-edit" }).Single().Id == "edit-resource-data-field", "toolkit workflow queries should filter by command");
                AssertTrue(project.QueryToolkitWorkflows(new KarProjectToolkitWorkflowQueryOptions { Text = "kar-toolkit resource-data-edit" }).Single().Id == "edit-resource-data-field", "toolkit workflow queries should search assembled CLI usage");
                AssertTrue(project.QueryToolkitWorkflows(new KarProjectToolkitWorkflowQueryOptions { RequiresInputFile = true }).All(workflow => workflow.RequiresInputFile), "toolkit workflow queries should filter input-file workflows");
                AssertTrue(project.QueryToolkitWorkflows(new KarProjectToolkitWorkflowQueryOptions { SupportsBatch = true, Text = "A2D" }).Any(workflow => workflow.Id == "apply-a2d-entry-outputs"), "toolkit workflow queries should combine batch filters and search text");
                AssertTrue(project.QueryToolkitWorkflows(new KarProjectToolkitWorkflowQueryOptions { RequiresValue = true, HasTargets = true }).Single().Id == "edit-resource-data-field", "toolkit workflow queries should filter value-taking available workflows");

                KarProjectToolkitSnapshot trimmed = project.ToolkitService.CreateSnapshot(new KarProjectToolkitSnapshotOptions
                {
                    IncludeMapContexts = false,
                    IncludeVehicleContexts = false,
                    IncludeA2DPackageContexts = false,
                    IncludeScriptTableContexts = false,
                    IncludeModWorkspace = false,
                });
                AssertTrue(!trimmed.HasModWorkspace && trimmed.MapContextCount == 0 && trimmed.ScriptTableContextCount == 0, "toolkit snapshot options should allow narrower snapshots");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectMapOutputQueryGroupsModFiles()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-map-output-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            File.WriteAllBytes(Path.Combine(tempRoot, "GrCity1.dat"), new byte[] { 0x10 });
            File.WriteAllBytes(Path.Combine(tempRoot, "GrCity1Model.dat"), new byte[] { 0x20 });
            File.WriteAllBytes(Path.Combine(tempRoot, "GrCity1Event.dat"), new byte[] { 0x30 });
            File.WriteAllBytes(Path.Combine(tempRoot, "GrSimple.dat"), new byte[] { 0x40 });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                project.CopyToOutput("GrCity1.dat", true);
                project.WriteFileBytes("GrCity1Event.dat", new byte[] { 0x31, 0x32 });

                IReadOnlyList<KarProjectMapOutputInfo> allMapOutputs = project.QueryMapOutputs(null);
                AssertTrue(allMapOutputs.Count == 2, "map output query should include all maps by default");
                AssertTrue(allMapOutputs.Single(map => map.Name == "Simple").OutputFileCount == 0, "map output query should keep maps without staged outputs");

                IReadOnlyList<KarProjectMapOutputInfo> mapOutputs = project.QueryMapOutputs(new KarProjectMapOutputQueryOptions
                {
                    HasOutput = true,
                });

                AssertTrue(mapOutputs.Count == 1, "map output query should filter maps with staged outputs");
                KarProjectMapOutputInfo city = mapOutputs.Single(map => map.Name == "City1");
                AssertTrue(city.ExpectedOutputFileCount == 3, "map output should know how many source bundle files exist");
                AssertTrue(city.OutputFileCount == 2, "map output should count staged bundle files");
                AssertTrue(city.MissingOutputFileCount == 1, "map output should count unstaged bundle files");
                AssertTrue(city.ModifiedOutputFileCount == 1, "map output should count modified bundle files");
                AssertTrue(city.UnchangedOutputFileCount == 1, "map output should count unchanged bundle files");
                AssertTrue(city.HasDataOutput, "map output should expose the staged data file");
                AssertTrue(!city.HasModelOutput, "map output should expose missing model output");
                AssertTrue(city.HasScriptOutput, "map output should expose staged event/script file");
                AssertTrue(city.DataOutput.Status == KarProjectOutputFileStatus.MatchesSource, "map output should keep data output status");
                AssertTrue(city.ScriptOutput.Status == KarProjectOutputFileStatus.DiffersFromSource, "map output should keep script output status");
                AssertTrue(city.HasModifiedOutput, "map output should flag modified outputs");
                AssertTrue(!city.HasCompleteOutputSet, "map output should flag incomplete staged map bundles");

                IReadOnlyList<KarProjectMapOutputInfo> modifiedOnly = project.QueryMapOutputs(new KarProjectMapOutputQueryOptions
                {
                    Outputs = new KarProjectOutputFileQueryOptions { Status = KarProjectOutputFileStatus.DiffersFromSource },
                    HasOutput = true,
                });

                AssertTrue(modifiedOnly.Count == 1, "map output query should filter output file status");
                AssertTrue(modifiedOnly[0].OutputFileCount == 1, "map output status filtering should keep only matching output files");
                AssertTrue(modifiedOnly[0].ScriptOutput != null, "map output status filtering should keep the modified script output");
                AssertTrue(modifiedOnly[0].DataOutput == null, "map output status filtering should omit unchanged data output");

                IReadOnlyList<KarProjectMapOutputInfo> modifiedMaps = project.QueryMapOutputs(new KarProjectMapOutputQueryOptions
                {
                    HasModifiedOutput = true,
                });

                AssertTrue(modifiedMaps.Count == 1, "map output query should filter maps with modified outputs");
                AssertTrue(modifiedMaps[0].Name == "City1", "map output modified filter should keep the edited map");

                IReadOnlyList<KarProjectMapOutputInfo> namedMaps = project.QueryMapOutputs(new KarProjectMapOutputQueryOptions
                {
                    MapName = "city1",
                });

                AssertTrue(namedMaps.Count == 1, "map output query should filter map names case-insensitively");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectMapServiceCoordinatesMapWorkflows()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-map-service-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            WriteHsdFile(Path.Combine(tempRoot, "GrCity1.dat"), "grDataCity1", new KAR_grData());
            WriteHsdFile(Path.Combine(tempRoot, "GrCity1Model.dat"), "grModelCity1", new KAR_grData());
            WriteHsdFile(Path.Combine(tempRoot, "GrCity1Event.dat"), "grEventDataAllCity1", new KAR_grData());

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectMapService maps = project.MapService;

                AssertTrue(object.ReferenceEquals(maps.Project, project), "map service should retain project context");
                AssertTrue(maps.Bundles.Count == 1, "map service should expose indexed map bundles");
                AssertTrue(maps.ByName.ContainsKey("City1"), "map service should expose map lookup index");

                KarMapBundle map = maps.Get("GrCity1Event.dat");
                AssertTrue(map.Name == "City1", "map service should resolve maps from event/script filenames");
                AssertTrue(object.ReferenceEquals(project.GetMap("City1"), map), "project map compatibility wrapper should use the same map bundle");

                KarMapBundle tryMap;
                AssertTrue(maps.TryGet("GrCity1Model.dat", out tryMap), "map service should try-resolve maps from model filenames");
                AssertTrue(object.ReferenceEquals(tryMap, map), "map service try-get should return the indexed map bundle");

                KarProjectMapOutputResult copyResult = maps.CopyToOutputResult("GrCity1.dat", true);
                AssertTrue(copyResult.FileCount == 3, "map service should copy every file in a map bundle");
                AssertTrue(copyResult.DataCopyResult != null, "map service copy result should expose data output");
                AssertTrue(copyResult.ModelCopyResult != null, "map service copy result should expose model output");
                AssertTrue(copyResult.ScriptCopyResult != null, "map service copy result should expose script output");
                AssertTrue(copyResult.OutputPaths.All(File.Exists), "map service copy result should point at written output files");

                KarProjectMapOutputInfo output = maps.GetOutput("City1");
                AssertTrue(output.HasCompleteOutputSet, "map service output lookup should detect complete staged map bundles");
                AssertTrue(output.UnchangedOutputFileCount == 3, "map service output lookup should compare copied files to source files");

                IReadOnlyList<KarProjectMapOutputInfo> wrapperOutputs = project.QueryMapOutputs(new KarProjectMapOutputQueryOptions { HasOutput = true });
                AssertTrue(wrapperOutputs.Count == 1 && wrapperOutputs[0].HasCompleteOutputSet, "project map output compatibility wrapper should delegate to map service");

                KarProjectMapArchiveBundle archives = maps.OpenArchives("City1");
                AssertTrue(archives.HasDataArchive, "map service should open map data archives");
                AssertTrue(archives.HasModelArchive, "map service should open map model archives");
                AssertTrue(archives.HasScriptArchive, "map service should open map script archives");
                AssertTrue(archives.Archives.Count == 3, "map service archive bundle should include every available map archive");

                KarMapInfo info = maps.Inspect("GrCity1.dat");
                AssertTrue(info.Name == "City1", "map service should inspect maps by file path");
                AssertTrue(info.HasScriptArchive, "map service inspection should include event/script archives");
                AssertTrue(info.Archives.Count == 3, "map service inspection should include every available archive");

                KarMapInfo tryInfo;
                string error;
                AssertTrue(maps.TryInspect("City1", out tryInfo, out error), "map service should expose try-inspection");
                AssertTrue(tryInfo != null && error == null, "successful map service try-inspection should return info without an error");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectMapScriptServiceGroupsMapAndScriptResources()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-map-script-service-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            File.WriteAllBytes(Path.Combine(tempRoot, "GrCity1.dat"), new byte[] { 0x10 });
            File.WriteAllBytes(Path.Combine(tempRoot, "GrCity1Model.dat"), new byte[] { 0x20 });
            File.WriteAllBytes(Path.Combine(tempRoot, "GrCity1Event.dat"), new byte[] { 0x30 });
            File.WriteAllBytes(Path.Combine(tempRoot, "ScInfPause.tm"), new byte[] { 0x40 });
            WriteA2DPackage(Path.Combine(tempRoot, "A2Info.dat"), new[] { "ScInfGo2D.tm", "readme.bin" });
            WriteA2DPackage(Path.Combine(tempRoot, "A2Kirby.dat"), new[] { "OB1800.tm", "KIRBY.tm" });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectMapScriptService mapScripts = project.MapScriptService;

                AssertTrue(object.ReferenceEquals(mapScripts.Project, project), "map script service should retain project context");

                KarProjectMapScriptBundle city = mapScripts.Get("City1");
                AssertTrue(city.MapName == "City1", "map script service should resolve map script bundles by map name");
                AssertTrue(city.MapResourceCount == 3, "map script bundles should include map data, model, and script resources");
                AssertTrue(city.ScriptArchiveResource.Address == "GrCity1Event.dat", "map script bundles should expose map event archives as script archives");
                AssertTrue(city.RelationshipCount == 3, "map script bundles should include map file relationships");
                AssertTrue(city.ScriptTableCount == 4, "map script bundles should include project script table resources");
                AssertTrue(city.ScriptTables.Any(table => table.Address == "ScInfPause.tm" && table.IsLooseFile), "map script bundles should include loose script table files");
                AssertTrue(city.ScriptTables.Any(table => table.Address == "A2Info.dat#ScInfGo2D.tm" && table.IsPackageEntry), "map script bundles should include packaged script table entries");
                AssertTrue(city.ScriptContexts.Count == city.ScriptTableCount, "map script bundles should expose script table contexts alongside table metadata");
                AssertTrue(city.ScriptContexts.Any(context => context.Address == "A2Info.dat#ScInfGo2D.tm" && context.OutputKind == KarProjectResourceOutputKind.OutputAsset), "map script contexts should include output-kind information for packaged scripts");

                KarProjectMapScriptBundle filtered = project.GetMapScripts("GrCity1Event.dat", new KarProjectScriptTableQueryOptions
                {
                    Name = "ScInfGo2D.tm",
                });
                AssertTrue(filtered.ScriptTableCount == 1 && filtered.ScriptTables[0].Address == "A2Info.dat#ScInfGo2D.tm", "project map script wrapper should filter script tables for a map context");

                IReadOnlyList<KarProjectMapScriptBundle> queried = project.QueryMapScripts(new KarProjectMapScriptQueryOptions
                {
                    MapNameOrPath = "City1",
                    ScriptTables = new KarProjectScriptTableQueryOptions
                    {
                        Role = "ObjectTable",
                    },
                    HasScriptArchive = true,
                });
                AssertTrue(queried.Count == 1 && queried[0].ScriptTables.Single().Address == "A2Kirby.dat#OB1800.tm", "map script queries should combine map and script-table filters");

                KarProjectResourceExportResult export = project.ExportMapScriptArchiveToOutput("City1");
                AssertTrue(export.Address == "GrCity1Event.dat", "map script archive exports should target the event/script archive");
                AssertTrue(export.OutputKind == KarProjectResourceOutputKind.ProjectFile, "map script archive exports should stage project file outputs");
                AssertTrue(File.Exists(export.OutputPath), "map script archive exports should write output-side files");
                AssertTrue(File.Exists(project.FileService.GetOutputPath("GrCity1Event.dat")), "map script archive exports should not write outside the configured output folder");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectMapContextServiceCombinesMapToolkitState()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-map-context-service-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            WriteHsdFile(Path.Combine(tempRoot, "GrCity1.dat"), "grDataCity1", new KAR_grData());
            WriteHsdFile(Path.Combine(tempRoot, "GrCity1Model.dat"), "grModelCity1", new KAR_grData());
            WriteHsdFile(Path.Combine(tempRoot, "GrCity1Event.dat"), "grEventDataAllCity1", new KAR_grData());
            File.WriteAllBytes(Path.Combine(tempRoot, "ScInfPause.tm"), new byte[] { 0x40 });
            WriteA2DPackage(Path.Combine(tempRoot, "A2Info.dat"), new[] { "ScInfGo2D.tm", "readme.bin" });
            WriteA2DPackage(Path.Combine(tempRoot, "A2Kirby.dat"), new[] { "OB1800.tm", "KIRBY.tm" });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectMapContextService contexts = project.MapContextService;

                AssertTrue(object.ReferenceEquals(contexts.Project, project), "map context service should retain project context");

                KarProjectMapContext city = contexts.Get("GrCity1Event.dat");
                AssertTrue(city.MapName == "City1", "map contexts should resolve by map file names");
                AssertTrue(city.HasInspection && !city.HasInspectionError, "map contexts should include successful archive inspection state");
                AssertTrue(city.ArchiveCount == 3, "map contexts should include data, model, and event/script archives");
                AssertTrue(city.MapResourceCount == 3, "map contexts should include map file resources");
                AssertTrue(city.RelationshipCount == 3, "map contexts should include map-scoped relationships");
                AssertTrue(city.ScriptTableCount == 4, "map contexts should include loose and packaged project script tables");
                AssertTrue(city.HasScriptArchive && city.ScriptArchive.File.RelativePath == "GrCity1Event.dat", "map contexts should expose event archives as script archives");
                AssertTrue(!city.HasOutput && city.OutputFileCount == 0, "map contexts should include missing output state before staging files");

                IReadOnlyList<KarProjectMapContext> objectContexts = project.QueryMapContexts(new KarProjectMapScriptQueryOptions
                {
                    MapNameOrPath = "City1",
                    ScriptTables = new KarProjectScriptTableQueryOptions
                    {
                        Role = "ObjectTable",
                    },
                    HasScriptTables = true,
                });
                AssertTrue(objectContexts.Count == 1 && objectContexts[0].ScriptTables.Single().Address == "A2Kirby.dat#OB1800.tm", "project map context wrapper should combine map and script-table filters");

                project.CopyMapToOutputResult("City1", true);
                KarProjectMapContext staged = project.GetMapContext("City1");
                AssertTrue(staged.HasOutput && staged.HasCompleteOutputSet, "map contexts should reflect staged map output copies");
                AssertTrue(staged.OutputFileCount == 3 && staged.ModifiedOutputFileCount == 0, "map contexts should summarize staged output state");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectVehicleServiceCombinesVehicleToolkitState()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-vehicle-service-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            WriteHsdFile(Path.Combine(tempRoot, "VcCommon.dat"), "vcDataCommon", new KAR_vcDataCommon());
            WriteHsdFile(Path.Combine(tempRoot, "VcStar.dat"), "vcDataKindStar", new KAR_vcDataKindStar());
            WriteHsdFile(Path.Combine(tempRoot, "VcWheel.dat"), "vcDataKindWheel", new KAR_vcDataKindWheel());
            WriteHsdFile(Path.Combine(tempRoot, "VcStarWarp.dat"), "vcDataStarWarp", new KAR_vcDataStar());
            WriteHsdFile(Path.Combine(tempRoot, "VcWheelieBike.dat"), "vcDataWheelieBike", new KAR_vcDataWheel());

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectVehicleService vehicles = project.VehicleService;

                AssertTrue(object.ReferenceEquals(vehicles.Project, project), "vehicle service should retain project context");
                AssertTrue(vehicles.Bundles.Count == 5, "vehicle service should expose indexed vehicle bundles");
                AssertTrue(vehicles.ByName.ContainsKey("Warp"), "vehicle service should expose vehicle lookup by machine name");

                KarVehicleBundle warp = vehicles.Get("VcStarWarp.dat");
                AssertTrue(warp.Name == "Warp" && warp.Family == "Star", "vehicle service should resolve star machine files");
                AssertTrue(warp.DataFile.RelativePath == "VcStarWarp.dat", "vehicle bundles should expose machine data files");
                AssertTrue(warp.CommonFile.RelativePath == "VcCommon.dat", "vehicle bundles should link shared common data");
                AssertTrue(warp.KindTableFile.RelativePath == "VcStar.dat", "vehicle bundles should link star kind tables");
                AssertTrue(warp.Files.Count == 3 && warp.SharedFileCount == 2, "vehicle bundles should include machine and shared vehicle files");
                AssertTrue(project.GetVehicle("Warp").DataFile.RelativePath == "VcStarWarp.dat", "project vehicle wrapper should resolve by machine name");
                AssertTrue(project.QueryVehicles(new KarProjectVehicleQueryOptions { VehicleNameOrPath = "Warp" }).Single().DataFile.RelativePath == "VcStarWarp.dat", "vehicle queries should filter by machine name or file path");

                KarProjectVehicleContext context = vehicles.GetContext("Warp");
                AssertTrue(context.Name == "Warp" && context.Family == "Star", "vehicle contexts should retain vehicle identity");
                AssertTrue(context.ArchiveCount == 3, "vehicle contexts should inspect machine, common, and kind table archives");
                AssertTrue(context.ResourceCount == 3, "vehicle contexts should include vehicle file resources");
                AssertTrue(context.KnownRootCount == 3 && context.RootCount == 3, "vehicle contexts should include known roots from every vehicle archive");
                AssertTrue(!context.HasInspectionErrors, "vehicle contexts should keep inspection errors separate from successful context creation");
                AssertTrue(!context.HasOutput && context.OutputFileCount == 0, "vehicle contexts should expose missing output state before staging files");

                IReadOnlyList<KarProjectVehicleContext> queried = project.QueryVehicleContexts(new KarProjectVehicleQueryOptions
                {
                    VehicleNameOrPath = "WheelieBike",
                    HasCompleteOutputSet = false,
                });
                AssertTrue(queried.Count == 1 && queried[0].DataFile.RelativePath == "VcWheelieBike.dat", "project vehicle context wrapper should combine vehicle and output filters");

                IReadOnlyList<KarProjectFileCopyResult> copies = vehicles.CopyFilesToOutput("Warp", true);
                AssertTrue(copies.Count == 3 && copies.All(copy => File.Exists(copy.OutputPath)), "vehicle service should copy machine bundles only to output files");

                KarProjectVehicleContext staged = project.GetVehicleContext("Warp");
                AssertTrue(staged.HasOutput && staged.HasCompleteOutputSet, "vehicle contexts should reflect staged vehicle bundle outputs");
                AssertTrue(staged.OutputFileCount == 3 && staged.ModifiedOutputFileCount == 0, "vehicle contexts should summarize staged vehicle output state");
                AssertTrue(!File.Exists(Path.Combine(tempRoot, "files", "VcStarWarp.dat")), "vehicle output copies should not write into the source folder");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectRelationshipServiceConnectsMapsAndScriptTables()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-relationship-service-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            File.WriteAllBytes(Path.Combine(tempRoot, "GrCity1.dat"), new byte[] { 0x10 });
            File.WriteAllBytes(Path.Combine(tempRoot, "GrCity1Model.dat"), new byte[] { 0x20 });
            File.WriteAllBytes(Path.Combine(tempRoot, "GrCity1Event.dat"), new byte[] { 0x30 });
            File.WriteAllBytes(Path.Combine(tempRoot, "ScInfPause.tm"), new byte[] { 0x40 });
            WriteA2DPackage(Path.Combine(tempRoot, "A2Info.dat"), new[] { "ScInfGo2D.tm", "readme.bin" });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectRelationshipService relationships = project.RelationshipService;

                AssertTrue(object.ReferenceEquals(relationships.Project, project), "relationship service should retain project context");
                AssertTrue(project.FileService.Get("ScInfPause.tm").Kind == KarFileKind.ScriptTable, "project files should classify loose tm resources as script tables");

                IReadOnlyList<KarProjectRelationship> mapRelationships = relationships.QueryMap("City1");
                AssertTrue(mapRelationships.Count == 3, "map relationships should expose data, model, and event/script files");
                AssertTrue(mapRelationships.Any(relationship => relationship.Role == "MapEventScript" && relationship.RelativePath == "GrCity1Event.dat"), "map relationships should label event archives as scripts");

                IReadOnlyList<KarProjectRelationship> allRelationships = relationships.Query();
                KarProjectRelationship looseTable = allRelationships.Single(relationship => relationship.RelativePath == "ScInfPause.tm");
                AssertTrue(looseTable.Kind == "ScriptTableFile", "relationship service should expose loose script table files");
                AssertTrue(looseTable.Role == "ScreenInfoTable", "relationship service should classify ScInf loose table roles");

                KarProjectRelationship packageTable = allRelationships.Single(relationship => relationship.PackageEntryName == "ScInfGo2D.tm");
                AssertTrue(packageTable.Kind == "A2DPackageEntry", "relationship service should expose A2D-contained script table entries");
                AssertTrue(packageTable.PackageFile.RelativePath == "A2Info.dat", "A2D script table relationships should retain their package file");
                AssertTrue(packageTable.RelativePath == "A2Info.dat#ScInfGo2D.tm", "A2D script table relationships should expose stable package entry paths");
                AssertTrue(packageTable.PackageEntryIndex == 0, "A2D script table relationships should expose entry indexes");
                AssertTrue(packageTable.PackageEntrySize == 4, "A2D script table relationships should expose entry sizes");
                AssertTrue(packageTable.Role == "ScreenInfoTable", "A2D script table relationships should use script table metadata");

                IReadOnlyList<KarProjectRelationship> screenInfoTables = project.QueryRelationships(new KarProjectRelationshipQueryOptions
                {
                    Role = "ScreenInfoTable",
                });
                AssertTrue(screenInfoTables.Count == 2, "project relationship compatibility wrapper should support role filtering");
                IReadOnlyList<KarProjectRelationship> screenInfoText = relationships.Query(new KarProjectRelationshipQueryOptions
                {
                    Text = "screen information",
                });
                AssertTrue(screenInfoText.Count == 2, "relationship queries should search script table metadata text");
                AssertTrue(project.QueryMapRelationships("GrCity1Event.dat").Count == 3, "project map relationship wrapper should resolve maps by file path");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectScriptServiceQueriesScriptTables()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-script-service-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            File.WriteAllBytes(Path.Combine(tempRoot, "ScInfPause.tm"), new byte[] { 0x40, 0x41 });
            WriteA2DPackage(Path.Combine(tempRoot, "A2Info.dat"), new[] { "ScInfGo2D.tm", "readme.bin" });
            WriteA2DPackage(Path.Combine(tempRoot, "A2Kirby.dat"), new[] { "OB1800.tm", "KIRBY.tm" });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectScriptService scripts = project.ScriptService;

                AssertTrue(object.ReferenceEquals(scripts.Project, project), "script service should retain project context");

                IReadOnlyList<KarProjectScriptTable> allTables = scripts.QueryTables();
                AssertTrue(allTables.Count == 4, "script service should include loose tm files and A2D-contained tm entries");
                AssertTrue(allTables.All(table => table.Category == "Scripts"), "script tables should expose script categories");

                KarProjectScriptTable looseTable = scripts.GetTable("ScInfPause.tm");
                AssertTrue(looseTable.IsLooseFile && !looseTable.IsPackageEntry, "script service should identify loose script table files");
                AssertTrue(looseTable.Role == "ScreenInfoTable", "script service should attach script table metadata to loose files");
                AssertTrue(scripts.ReadTableBytes("ScInfPause.tm").SequenceEqual(new byte[] { 0x40, 0x41 }), "script service should read loose table bytes");

                KarProjectScriptTable packageTable = scripts.GetTable("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(packageTable.IsPackageEntry && !packageTable.IsLooseFile, "script service should identify packaged script table entries");
                AssertTrue(packageTable.PackageRelativePath == "A2Info.dat", "packaged script tables should expose package paths");
                AssertTrue(packageTable.PackageEntrySize == 4, "packaged script tables should expose entry sizes");
                AssertTrue(scripts.ReadTableBytes("A2Info.dat#ScInfGo2D.tm").SequenceEqual(new byte[] { 0xA0, 0xB0, 0xC0, 0xD0 }), "script service should read A2D table bytes");
                KarProjectScriptTable tryTable;
                AssertTrue(scripts.TryGetTable("A2Info.dat#ScInfGo2D.tm", out tryTable) && tryTable.Address == packageTable.Address, "script service should try-resolve script table addresses");
                AssertTrue(!scripts.TryGetTable("A2Info.dat#readme.bin", out tryTable), "script service try-get should reject non-script A2D entries");

                IReadOnlyList<KarProjectScriptTable> screenInfoTables = scripts.QueryTables(new KarProjectScriptTableQueryOptions
                {
                    Role = "ScreenInfoTable",
                });
                AssertTrue(screenInfoTables.Count == 2, "script service should filter script tables by role");
                IReadOnlyList<KarProjectScriptTable> screenInfoText = scripts.QueryTables(new KarProjectScriptTableQueryOptions
                {
                    Text = "screen information",
                });
                AssertTrue(screenInfoText.Count == 2, "script service should search script table metadata text");

                IReadOnlyList<KarProjectScriptTable> infoPackageTables = scripts.QueryTables(new KarProjectScriptTableQueryOptions
                {
                    PackagePath = "A2Info.dat",
                });
                AssertTrue(infoPackageTables.Count == 1 && infoPackageTables[0].Address == "A2Info.dat#ScInfGo2D.tm", "script service should filter script tables by package path");

                KarProjectScriptTable kirbyTable = project.QueryScriptTables(new KarProjectScriptTableQueryOptions
                {
                    Name = "KIRBY.tm",
                }).Single();
                AssertTrue(kirbyTable.Role == "KirbyTable", "project script table wrapper should delegate to the script service");

                KarProjectResourceExportResult export = project.ExportScriptTableToOutput("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(export.OutputKind == KarProjectResourceOutputKind.OutputAsset, "script table exports should use safe resource output workflows");
                AssertTrue(File.Exists(export.OutputPath), "script table exports should write output-side files");
                AssertTrue(!File.Exists(project.FileService.GetOutputPath("A2Info.dat")), "script table sidecar exports should not rewrite source packages");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectScriptContextServiceReportsScriptOutputState()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-script-context-service-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            File.WriteAllBytes(Path.Combine(tempRoot, "ScInfPause.tm"), new byte[] { 0x40, 0x41 });
            WriteA2DPackage(Path.Combine(tempRoot, "A2Info.dat"), new[] { "ScInfGo2D.tm", "readme.bin" });
            WriteA2DPackage(Path.Combine(tempRoot, "A2Kirby.dat"), new[] { "OB1800.tm", "KIRBY.tm" });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectScriptContextService contexts = project.ScriptContextService;

                AssertTrue(object.ReferenceEquals(contexts.Project, project), "script context service should retain project context");

                IReadOnlyList<KarProjectScriptTableContext> screenInfo = contexts.Query(new KarProjectScriptTableContextQueryOptions
                {
                    Tables = new KarProjectScriptTableQueryOptions
                    {
                        Role = "ScreenInfoTable",
                    },
                });
                AssertTrue(screenInfo.Count == 2, "script contexts should filter by script table metadata");

                KarProjectScriptTableContext loose = contexts.Get("ScInfPause.tm");
                AssertTrue(loose.IsLooseFile && loose.OutputKind == KarProjectResourceOutputKind.ProjectFile, "script contexts should include loose-file output kind");
                AssertTrue(loose.OutputStatus == KarProjectResourceOutputStatus.Missing, "script contexts should report missing loose-file outputs");
                AssertTrue(loose.RelationshipCount == 1 && loose.PrimaryRelationship.Role == "ScreenInfoTable", "script contexts should include graph relationships");

                KarProjectScriptTableContext package = project.GetScriptTableContext("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(package.IsPackageEntry && package.OutputKind == KarProjectResourceOutputKind.OutputAsset, "project script context wrapper should resolve packaged scripts");
                AssertTrue(package.OutputStatus == KarProjectResourceOutputStatus.Missing, "script contexts should report missing A2D sidecars");

                KarProjectResourceExportResult export = project.ExportScriptTableToOutput("A2Info.dat#ScInfGo2D.tm");
                KarProjectScriptTableContext exported = contexts.Get("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(exported.HasOutput && exported.HasUnchangedOutput, "script contexts should reflect exported sidecars");
                AssertTrue(exported.OutputStatus == KarProjectResourceOutputStatus.SidecarMatchesEntry, "script contexts should compare sidecars to active package entries");

                File.WriteAllBytes(export.OutputPath, new byte[] { 0x11, 0x22, 0x33, 0x44 });
                KarProjectScriptTableContext modified = contexts.Get("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(modified.HasModifiedOutput && modified.OutputStatus == KarProjectResourceOutputStatus.SidecarDiffersFromEntry, "script contexts should detect modified sidecar outputs");

                IReadOnlyList<KarProjectScriptTableContext> modifiedContexts = project.QueryScriptTableContexts(new KarProjectScriptTableContextQueryOptions
                {
                    Tables = new KarProjectScriptTableQueryOptions
                    {
                        PackagePath = "A2Info.dat",
                    },
                    HasModifiedOutput = true,
                });
                AssertTrue(modifiedContexts.Count == 1 && modifiedContexts[0].Address == "A2Info.dat#ScInfGo2D.tm", "project script context queries should combine script and output filters");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectA2DServiceQueriesProjectEntries()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-a2d-query-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            WriteA2DPackage(Path.Combine(tempRoot, "A2Info.dat"), new[] { "ScInfGo2D.tm", "readme.bin" });
            WriteA2DPackage(Path.Combine(tempRoot, "A2Kirby.dat"), new[] { "OB1800.tm", "KIRBY.tm" });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectA2DService a2d = project.A2DService;

                IReadOnlyList<KarProjectA2DEntryInfo> allEntries = a2d.QueryEntries();
                AssertTrue(allEntries.Count == 4, "A2D entry query should include entries from every project package");
                AssertTrue(allEntries[0].EntryPath == "A2Info.dat#ScInfGo2D.tm", "A2D entry query should order entries by package path and index");
                AssertTrue(allEntries.Any(entry => entry.EntryPath == "A2Kirby.dat#OB1800.tm" && entry.Role == "ObjectTable"), "A2D entry query should attach script table metadata");

                IReadOnlyList<KarProjectA2DEntryInfo> infoEntries = a2d.QueryEntries(new KarProjectA2DEntryQueryOptions
                {
                    PackagePath = "A2Info.dat",
                });
                AssertTrue(infoEntries.Count == 2, "A2D entry query should filter by package path");

                IReadOnlyList<KarProjectA2DEntryInfo> scriptTables = a2d.QueryScriptTableEntries();
                AssertTrue(scriptTables.Count == 3, "A2D entry query should filter script-table entries");
                AssertTrue(scriptTables.All(entry => entry.IsScriptTable), "script-table entry query should only return tm resources");

                IReadOnlyList<KarProjectA2DEntryInfo> screenInfoTables = project.QueryA2DEntries(new KarProjectA2DEntryQueryOptions
                {
                    Role = "ScreenInfoTable",
                });
                AssertTrue(screenInfoTables.Count == 1 && screenInfoTables[0].Name == "ScInfGo2D.tm", "project A2D entry wrapper should support role filters");
                IReadOnlyList<KarProjectA2DEntryInfo> screenInfoText = a2d.QueryEntries(new KarProjectA2DEntryQueryOptions
                {
                    Text = "screen information",
                });
                AssertTrue(screenInfoText.Count == 1 && screenInfoText[0].Name == "ScInfGo2D.tm", "A2D entry query should search entry metadata text");

                IReadOnlyList<KarProjectA2DEntryInfo> namedEntries = a2d.QueryEntries(new KarProjectA2DEntryQueryOptions
                {
                    EntryName = "KIRBY.tm",
                });
                AssertTrue(namedEntries.Count == 1 && namedEntries[0].PackageRelativePath == "A2Kirby.dat", "A2D entry query should filter by entry name");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectA2DPackageContextsSummarizePackages()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-a2d-package-context-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            WriteA2DPackage(Path.Combine(tempRoot, "A2Info.dat"), new[] { "ScInfGo2D.tm", "readme.bin" });
            WriteA2DPackage(Path.Combine(tempRoot, "A2Kirby.dat"), new[] { "OB1800.tm", "KIRBY.tm" });
            File.WriteAllBytes(Path.Combine(tempRoot, "A2Broken.dat"), new byte[] { 0x10 });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectA2DPackageContextService packages = project.A2DPackageContextService;

                AssertTrue(object.ReferenceEquals(packages.Project, project), "A2D package context service should retain project context");

                IReadOnlyList<KarProjectA2DPackageContext> contexts = packages.Query();
                AssertTrue(contexts.Count == 3, "A2D package contexts should include every package file, even malformed packages");

                KarProjectA2DPackageContext info = project.GetA2DPackageContext("A2Info.dat");
                AssertTrue(info.IsOpen && !info.HasOpenError, "A2D package contexts should report successful package opens");
                AssertTrue(info.EntryCount == 2, "A2D package contexts should expose package entries");
                AssertTrue(info.ScriptTableCount == 1 && info.ScriptContexts[0].Address == "A2Info.dat#ScInfGo2D.tm", "A2D package contexts should include script table contexts for tm entries");
                AssertTrue(info.EntryOutputs.Count == 2 && info.EntryOutputCount == 0, "A2D package contexts should include missing sidecar status for every entry");
                AssertTrue(info.OutputStatus == KarProjectResourceOutputStatus.Missing, "A2D package contexts should include package output status");

                KarProjectA2DPackageContext broken = packages.Get("A2Broken.dat");
                AssertTrue(!broken.IsOpen && broken.HasOpenError, "A2D package contexts should preserve open errors without throwing");
                AssertTrue(broken.EntryCount == 0 && broken.ScriptTableCount == 0, "malformed A2D package contexts should not invent entries");

                KarProjectResourceExportResult export = project.ExportScriptTableToOutput("A2Info.dat#ScInfGo2D.tm");
                KarProjectA2DPackageContext exported = packages.Get("A2Info.dat");
                AssertTrue(exported.HasEntryOutputs && exported.MatchingEntryOutputCount == 1, "A2D package contexts should reflect exported sidecars");
                AssertTrue(exported.ScriptContexts[0].OutputStatus == KarProjectResourceOutputStatus.SidecarMatchesEntry, "A2D package script contexts should share sidecar output status");

                File.WriteAllBytes(export.OutputPath, new byte[] { 0x11, 0x22, 0x33, 0x44 });
                KarProjectA2DPackageContext modified = packages.Get("A2Info.dat");
                AssertTrue(modified.HasModifiedEntryOutputs && modified.ModifiedEntryOutputCount == 1, "A2D package contexts should detect modified sidecars");

                IReadOnlyList<KarProjectA2DPackageContext> modifiedPackages = project.QueryA2DPackageContexts(new KarProjectA2DPackageContextQueryOptions
                {
                    HasModifiedEntryOutputs = true,
                });
                AssertTrue(modifiedPackages.Count == 1 && modifiedPackages[0].RelativePath == "A2Info.dat", "project A2D package context wrapper should filter modified packages");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectA2DServiceExtractsAndReplacesEntriesSafely()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-a2d-service-project-" + Guid.NewGuid().ToString("N"));
            string filesRoot = Path.Combine(tempRoot, "files");
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(filesRoot);

            string packagePath = Path.Combine(filesRoot, "A2Info.dat");
            WriteA2DPackage(packagePath, new[] { "ScInfGo2D.tm", "readme.bin" });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectA2DService a2d = project.A2DService;

                AssertTrue(object.ReferenceEquals(a2d.Project, project), "A2D service should retain project context");

                KarProjectA2DEntryInfo entry = a2d.GetEntry("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(entry.EntryPath == "A2Info.dat#ScInfGo2D.tm", "A2D entry info should expose stable package entry paths");
                AssertTrue(entry.Size == 4, "A2D entry info should expose entry sizes");
                AssertTrue(entry.Role == "ScreenInfoTable", "A2D entry info should classify tm entries through the script table catalog");

                KarProjectA2DEntryOutputInfo missingOutput = a2d.GetEntryOutput("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(missingOutput.Status == KarProjectA2DEntryOutputStatus.Missing, "A2D entry output status should report missing sidecar assets");
                AssertTrue(!missingOutput.HasOutput, "A2D entry output status should flag missing output assets");

                KarProjectA2DEntryExtractResult extract = a2d.ExtractEntryToOutput("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(extract.WroteOutput, "A2D entry extraction should write missing output assets");
                AssertTrue(File.Exists(extract.OutputPath), "A2D entry extraction should create an output-side asset file");
                AssertTrue(extract.OutputRelativePath == "a2d-entries/A2Info.dat/ScInfGo2D.tm", "A2D entry extraction should use stable sidecar paths");
                AssertTrue(File.ReadAllBytes(extract.OutputPath).SequenceEqual(new byte[] { 0xA0, 0xB0, 0xC0, 0xD0 }), "A2D entry extraction should write the selected entry bytes");
                AssertTrue(!File.Exists(project.FileService.GetOutputPath("A2Info.dat")), "A2D entry extraction should not stage a modified package");

                KarProjectA2DEntryOutputInfo matchingOutput = a2d.GetEntryOutput("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(matchingOutput.Status == KarProjectA2DEntryOutputStatus.MatchesEntry, "A2D entry output status should compare extracted sidecars to package entries");
                AssertTrue(matchingOutput.IsSameContentAsEntry == true, "A2D entry output status should expose content comparison");

                KarProjectA2DEntryExtractResult skippedExtract = a2d.ExtractEntryToOutput("A2Info.dat#0");
                AssertTrue(!skippedExtract.WroteOutput, "A2D entry extraction should skip existing assets unless overwrite is requested");

                File.WriteAllBytes(extract.OutputPath, new byte[] { 0x11, 0x22, 0x33, 0x44 });
                KarProjectA2DEntryOutputInfo modifiedOutput = a2d.GetEntryOutput("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(modifiedOutput.Status == KarProjectA2DEntryOutputStatus.DiffersFromEntry, "A2D entry output status should detect modified sidecar assets");
                AssertTrue(a2d.QueryEntryOutputs(new KarProjectA2DEntryOutputQueryOptions
                {
                    Status = KarProjectA2DEntryOutputStatus.DiffersFromEntry,
                }).Count == 1, "A2D entry output query should filter modified sidecars");
                AssertTrue(project.QueryA2DEntryOutputs(new KarProjectA2DEntryOutputQueryOptions
                {
                    HasOutput = true,
                }).Count == 1, "project A2D entry output wrapper should delegate to A2D service");

                IReadOnlyList<KarProjectA2DEntryApplyResult> applyResults = a2d.ApplyModifiedEntryOutputs(new KarProjectA2DEntryOutputQueryOptions
                {
                    Entries = new KarProjectA2DEntryQueryOptions
                    {
                        PackagePath = "A2Info.dat",
                    },
                });
                AssertTrue(applyResults.Count == 1, "A2D entry apply should process modified sidecar assets");
                KarProjectA2DEntryApplyResult apply = applyResults[0];
                AssertTrue(apply.EntryPath == "A2Info.dat#ScInfGo2D.tm", "A2D entry apply should report the sidecar entry path");
                AssertTrue(apply.PackageRelativePath == "A2Info.dat", "A2D entry apply should report the package path");
                AssertTrue(apply.SidecarOutputPath == extract.OutputPath, "A2D entry apply should report the sidecar path");
                AssertTrue(apply.ReplacementLength == 4, "A2D entry apply should report replacement length");
                AssertTrue(File.Exists(apply.PackageOutputPath), "A2D entry apply should save the modified package to output");
                AssertTrue(project.OutputService.GetFile("A2Info.dat").Status == KarProjectOutputFileStatus.DiffersFromSource, "A2D entry replacement should register as a modified project output");
                AssertTrue(a2d.GetEntryOutput("A2Info.dat#ScInfGo2D.tm").Status == KarProjectA2DEntryOutputStatus.MatchesEntry, "A2D entry output status should compare sidecars to staged package edits");
                AssertTrue(project.ApplyModifiedA2DEntryOutputs().Count == 0, "project A2D entry apply wrapper should find no modified sidecars after apply");

                KarProjectA2DPackage sourcePackage = project.ArchiveService.OpenProjectA2DPackage("A2Info.dat");
                AssertTrue(sourcePackage.ReadPath == project.FileService.GetOutputPath("A2Info.dat"), "project A2D opens should prefer modified output packages after replacement");
                AssertTrue(sourcePackage.Package.GetEntryData(0).SequenceEqual(new byte[] { 0x11, 0x22, 0x33, 0x44 }), "project A2D reads should see output package replacements");

                A2DPackage sourceOnlyPackage;
                string error;
                AssertTrue(A2DPackage.TryOpen(project.FileService.GetSourcePath("A2Info.dat"), out sourceOnlyPackage, out error), "source package should still parse after output-only replacement");
                AssertTrue(sourceOnlyPackage.GetEntryData(0).SequenceEqual(new byte[] { 0xA0, 0xB0, 0xC0, 0xD0 }), "A2D entry replacement should not mutate source packages");

                KarProjectA2DEntryExtractResult overwrittenExtract = a2d.ExtractEntryToOutput("A2Info.dat#ScInfGo2D.tm", overwrite: true);
                AssertTrue(overwrittenExtract.WroteOutput, "A2D entry extraction should overwrite sidecar assets when requested");
                AssertTrue(File.ReadAllBytes(overwrittenExtract.OutputPath).SequenceEqual(new byte[] { 0x11, 0x22, 0x33, 0x44 }), "A2D entry extraction should read from modified output packages");

                string wrongSizePath = Path.Combine(tempRoot, "wrong-size.tm");
                File.WriteAllBytes(wrongSizePath, new byte[] { 0x55 });
                AssertThrows<InvalidDataException>(
                    () => a2d.ReplaceEntryFromFile("A2Info.dat#ScInfGo2D.tm", wrongSizePath),
                    "A2D entry replacement should reject size-changing replacements for now");

                AssertTrue(project.GetA2DEntry("A2Info.dat#ScInfGo2D.tm").Name == "ScInfGo2D.tm", "project A2D entry compatibility wrapper should delegate to A2D service");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectArchiveServiceCoordinatesArchiveWorkflows()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-archive-service-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            WriteHsdFile(Path.Combine(tempRoot, "GrCity1.dat"), "grDataCity1", new KAR_grData());
            WriteA2DPackage(Path.Combine(tempRoot, "A2Demo.dat"));

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectArchiveService archives = project.ArchiveService;

                AssertTrue(object.ReferenceEquals(archives.Project, project), "archive service should retain project context");
                AssertTrue(object.ReferenceEquals(archives.Inspector, project.ArchiveInspector), "archive service should expose the project archive inspector");

                IReadOnlyList<KarArchiveInfo> hsdArchives = archives.QueryHsdArchives(null);
                AssertTrue(hsdArchives.Count == 1, "archive service should query HSD archive files");
                AssertTrue(hsdArchives[0].File.RelativePath == "GrCity1.dat", "archive service should keep HSD archive file context");
                AssertTrue(project.QueryArchives(null).Count == 1, "project archive query compatibility wrapper should delegate to archive service");

                KarArchiveInfo info = archives.InspectHsdArchive("GrCity1.dat");
                AssertTrue(info.Roots.Count == 1, "archive service should inspect HSD roots");
                AssertTrue(info.KnownRoots.Count == 1, "archive service should attach known root definitions");
                AssertTrue(archives.Inspect(project.GetFile("GrCity1.dat")).Roots.Count == info.Roots.Count, "archive service should inspect project file handles");

                KarArchiveInfo tryInfo;
                string error;
                AssertTrue(!archives.TryInspectHsdArchive("Missing.dat", out tryInfo, out error), "archive service should expose failed HSD inspections");
                AssertTrue(tryInfo == null && !string.IsNullOrEmpty(error), "failed HSD inspection should include an error");

                KarProjectHsdArchive hsdArchive = archives.OpenHsdArchive("GrCity1.dat");
                AssertTrue(hsdArchive.RelativePath == "GrCity1.dat", "archive service should open editable HSD archive handles");
                AssertTrue(hsdArchive.Inspect().Roots.Count == 1, "editable HSD archive handles should inspect through the project service setup");
                AssertTrue(archives.OpenHsdFile("GrCity1.dat").Roots.Count == 1, "archive service should open raw HSD files");

                KarProjectFileWriteResult hsdWrite = archives.SaveHsdFileToOutput("GrCity1.dat", hsdArchive.Archive);
                AssertTrue(File.Exists(hsdWrite.OutputPath), "archive service should save HSD archives to output");
                AssertTrue(project.OutputService.HasFile("GrCity1.dat"), "archive HSD saves should register as output files");
                AssertTrue(project.OpenHsdArchive("GrCity1.dat").RelativePath == "GrCity1.dat", "project HSD open compatibility wrapper should delegate to archive service");

                A2DPackage package;
                AssertTrue(archives.TryOpenA2DPackage("A2Demo.dat", out package, out error), "archive service should try-open A2D packages");
                AssertTrue(package.Entries.Count == 1, "archive service should parse A2D package entries");
                AssertTrue(package.Entries[0].Name == "entry.bin", "archive service should preserve A2D package entry names");

                KarProjectA2DPackage projectPackage = archives.OpenProjectA2DPackage("A2Demo.dat");
                AssertTrue(projectPackage.RelativePath == "A2Demo.dat", "archive service should open editable project A2D package handles");
                AssertTrue(project.OpenA2DPackage("A2Demo.dat").Entries.Count == 1, "project A2D open compatibility wrapper should delegate to archive service");

                KarProjectFileWriteResult a2dWrite = archives.SaveA2DPackageToOutput("A2Demo.dat", package);
                AssertTrue(File.Exists(a2dWrite.OutputPath), "archive service should save A2D packages to output");
                AssertTrue(project.OutputService.HasFile("A2Demo.dat"), "archive A2D saves should register as output files");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectArchiveContextServiceCombinesArchiveToolkitState()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-archive-context-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            WriteHsdFile(Path.Combine(tempRoot, "VsHydra.dat"), "vsDataHydra", new KAR_vsLegendaryData());
            File.WriteAllBytes(Path.Combine(tempRoot, "VsBroken.dat"), new byte[] { 0x10 });

            try
            {
                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectArchiveContextService contexts = project.ArchiveContextService;

                AssertTrue(object.ReferenceEquals(contexts.Project, project), "archive context service should retain project context");

                IReadOnlyList<KarProjectArchiveContext> all = contexts.Query();
                AssertTrue(all.Count == 2, "archive contexts should include every HSD archive file");

                KarProjectArchiveContext hydra = contexts.Get("VsHydra.dat");
                AssertTrue(hydra.RelativePath == "VsHydra.dat", "archive contexts should preserve file identity");
                AssertTrue(hydra.HasInspection && !hydra.HasInspectionError, "valid archive contexts should include inspection state");
                AssertTrue(hydra.RootCount == 1 && hydra.KnownRootCount == 1, "valid archive contexts should expose root counts");
                AssertTrue(hydra.Resource.Address == "VsHydra.dat", "archive contexts should include file resources");
                AssertTrue(hydra.RootResources.Single().Address == "VsHydra.dat:vsDataHydra", "archive contexts should include root resources");
                AssertTrue(hydra.FieldCount >= 5, "archive contexts should include labeled root fields");
                AssertTrue(hydra.OutputStatus == KarProjectResourceOutputStatus.Missing, "archive contexts should include missing output status");
                AssertTrue(project.GetArchiveContext("VsHydra.dat").RootCount == 1, "project archive context wrapper should delegate to the context service");
                AssertTrue(project.QueryArchiveContexts(new KarProjectArchiveContextQueryOptions { Text = "legendary" }).Any(context => context.RelativePath == "VsHydra.dat"), "archive context search should include schema and resource labels");

                project.CopyToOutput("VsHydra.dat", true);
                KarProjectArchiveContext copied = contexts.Get("VsHydra.dat");
                AssertTrue(copied.HasOutput && copied.OutputStatus == KarProjectResourceOutputStatus.MatchesSource, "archive contexts should report copied output files");

                project.SetResourceScalarFieldFromText("VsHydra.dat:vsDataHydra", "x0C", "0x190");
                KarProjectArchiveContext modified = contexts.Get("VsHydra.dat");
                AssertTrue(modified.HasModifiedOutput && modified.OutputStatus == KarProjectResourceOutputStatus.DiffersFromSource, "archive contexts should report modified output files");
                AssertTrue(project.QueryArchiveContexts(new KarProjectArchiveContextQueryOptions
                {
                    OutputStatus = KarProjectResourceOutputStatus.DiffersFromSource,
                }).Single().RelativePath == "VsHydra.dat", "archive context queries should filter by output status");

                KarProjectArchiveContext broken = contexts.Get("VsBroken.dat");
                AssertTrue(!broken.HasInspection && broken.HasInspectionError, "broken archive contexts should retain inspection errors without throwing");
                AssertTrue(broken.RootCount == 0 && broken.FieldCount == 0, "broken archive contexts should not invent roots or fields");
                AssertTrue(broken.Resource.Address == "VsBroken.dat", "broken archive contexts should still include file resources");
                AssertTrue(project.QueryArchiveContexts(new KarProjectArchiveContextQueryOptions { HasInspectionError = true }).Single().RelativePath == "VsBroken.dat", "archive context queries should filter inspection errors");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectEditServiceWritesScalarEditsToOutput()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-edit-service-project-" + Guid.NewGuid().ToString("N"));
            string outputRoot = tempRoot + "_mod";
            Directory.CreateDirectory(tempRoot);

            try
            {
                WriteFieldQueryFixture(tempRoot);

                KarProject project = KarProject.Open(tempRoot, outputRoot);
                KarProjectEditService edits = project.EditService;

                AssertTrue(object.ReferenceEquals(edits.Project, project), "edit service should retain project context");

                KarProjectScalarEditResult result = edits.SetScalarFieldFromText(
                    "VsHydra.dat",
                    "kar.vs.legendary",
                    "x0C",
                    "0x190",
                    byDataDefinition: true);

                AssertTrue(result.RelativePath == "VsHydra.dat", "edit service should report the edited project path");
                AssertTrue(result.File.RelativePath == "VsHydra.dat", "edit service should retain edited file metadata");
                AssertTrue(result.Edit.RootName == "vsDataHydra", "edit service should resolve schema edits to the archive root");
                AssertTrue(result.Edit.Field.Name == "x0C", "edit service should retain edited field metadata");
                AssertTrue(result.Edit.PreviousValue.SignedValue == 303, "edit service should report the previous scalar value");
                AssertTrue(result.Edit.NewValue.SignedValue == 400, "edit service should report the new scalar value");
                AssertTrue(result.Edit.IsChanged, "edit service should flag changed scalar values");
                AssertTrue(File.Exists(result.OutputPath), "edit service should save edited archives to output");
                AssertTrue(project.OutputService.GetFile("VsHydra.dat").Status == KarProjectOutputFileStatus.DiffersFromSource, "edit service output should be marked modified");

                KarProjectFieldInfo editedField = project.DataService.QueryFieldValues(new KarProjectFieldQueryOptions
                {
                    DataDefinitionIdOrAccessorTypeName = "kar.vs.legendary",
                    FieldName = "x0C",
                }).Single(field => field.RelativePath == "VsHydra.dat");
                AssertTrue(editedField.Value.SignedValue == 400, "project data queries should read scalar edits from output copies");

                KarArchiveInfo sourceInfo = project.ArchiveInspector.Inspect(
                    project.FileService.Get("VsHydra.dat"),
                    new HSDRawFile(project.FileService.GetSourcePath("VsHydra.dat")));
                AssertTrue(sourceInfo.GetRootByDataDefinition("kar.vs.legendary").GetFieldValue("x0C").SignedValue == 303, "edit service should not mutate source files");

                KarProjectScalarEditResult rootResult = edits.SetScalarField(
                    "GrCity1.dat",
                    "grDataCity1",
                    "unknown1",
                    707);
                AssertTrue(rootResult.Edit.NewValue.SignedValue == 707, "edit service should edit scalar fields by root name");
                AssertTrue(project.OutputService.GetFile("GrCity1.dat").Status == KarProjectOutputFileStatus.DiffersFromSource, "root-name scalar edits should save modified output files");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
                if (Directory.Exists(outputRoot))
                    Directory.Delete(outputRoot, true);
            }
        }

        private static void ProjectSchemaUsageGroupsKnownRoots()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-schema-usage-project-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(tempRoot);

            try
            {
                WriteFieldQueryFixture(tempRoot);

                KarProject project = KarProject.Open(tempRoot);
                KarProjectDataService data = project.DataService;
                AssertTrue(object.ReferenceEquals(data.Project, project), "data service should retain project context");
                AssertTrue(data.Definitions.All.Count >= 32, "data service should expose the active data definition registry");

                IReadOnlyList<KarProjectDataDefinitionUsage> usages = data.QueryDataDefinitionUsage(null);
                KarProjectDataDefinitionUsage mapUsage = usages.FirstOrDefault(usage => usage.DataDefinitionId == "kar.gr.data");
                KarProjectDataDefinitionUsage versusUsage = usages.FirstOrDefault(usage => usage.DataDefinitionId == "kar.vs.legendary");

                AssertTrue(mapUsage != null, "schema usage should include map data roots");
                if (mapUsage != null)
                {
                    AssertTrue(mapUsage.Count == 2, "schema usage should count each map data root");
                    AssertTrue(mapUsage.FileCount == 2, "schema usage should count unique map data files");
                    AssertTrue(mapUsage.Files[0].RelativePath == "GrCity1.dat", "schema usage files should be ordered by relative path");
                }

                AssertTrue(versusUsage != null, "schema usage should include versus legendary roots");
                if (versusUsage != null)
                {
                    AssertTrue(versusUsage.Count == 1, "schema usage should count versus roots");
                    AssertTrue(versusUsage.FileCount == 1, "schema usage should count unique versus files");
                }

                IReadOnlyList<KarProjectDataDefinitionUsage> mapOnly = project.QueryDataDefinitionUsage(new KarProjectRootQueryOptions
                {
                    Files = new KarProjectFileQueryOptions { Kind = KarFileKind.MapData },
                });

                AssertTrue(mapOnly.Count == 1, "schema usage should respect file-kind filters");
                AssertTrue(mapOnly[0].DataDefinitionId == "kar.gr.data", "schema usage file-kind filter should keep map data");
                IReadOnlyList<KarProjectRootInfo> legendaryRoots = data.QueryRoots(new KarProjectRootQueryOptions
                {
                    Text = "Legendary Machine Versus",
                });
                AssertTrue(legendaryRoots.Count == 1 && legendaryRoots[0].RootPath == "VsHydra.dat:vsDataHydra", "root queries should search schema labels");
                IReadOnlyList<KarProjectDataDefinitionUsage> legendaryOnly = project.QueryDataDefinitionUsage(new KarProjectRootQueryOptions
                {
                    Text = "Legendary Machine Versus",
                });
                AssertTrue(legendaryOnly.Count == 1 && legendaryOnly[0].DataDefinitionId == "kar.vs.legendary", "schema usage should respect root text search");
                AssertTrue(project.QueryDataDefinitionUsage(null).Count == usages.Count, "project schema usage compatibility wrapper should delegate to data service");
                AssertTrue(project.QueryRoots(null).Count == data.QueryRoots(null).Count, "project root compatibility wrapper should delegate to data service");
                AssertTrue(project.QueryRootSummaries(null).Count == data.QueryRootSummaries(null).Count, "project root summary compatibility wrapper should delegate to data service");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
            }
        }

        private static void ProjectFieldQueryReturnsLabeledValues()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-field-query-project-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(tempRoot);

            try
            {
                WriteFieldQueryFixture(tempRoot);

                KarProject project = KarProject.Open(tempRoot);
                KarProjectDataService data = project.DataService;
                IReadOnlyList<KarProjectFieldInfo> mapUnknowns = data.QueryFieldValues(new KarProjectFieldQueryOptions
                {
                    DataDefinitionIdOrAccessorTypeName = "kar.gr.data",
                    FieldName = "unknown1",
                });

                AssertTrue(mapUnknowns.Count == 2, "field query should find map unknown1 values across project files");
                AssertTrue(mapUnknowns.All(field => field.FieldName == "unknown1"), "field query should filter by field name");
                AssertTrue(mapUnknowns.Any(field => field.RelativePath == "GrCity1.dat" && field.Value.SignedValue == 101), "field query should read GrCity1 scalar values");
                AssertTrue(mapUnknowns.Any(field => field.RelativePath == "GrSimple.dat" && field.Value.SignedValue == 202), "field query should read GrSimple scalar values");

                IReadOnlyList<KarProjectFieldInfo> hydraFields = data.QueryFieldValues(new KarProjectFieldQueryOptions
                {
                    DataDefinitionIdOrAccessorTypeName = "KAR_vsLegendaryData",
                    FieldName = "x0C",
                });

                AssertTrue(hydraFields.Count == 1, "field query should match schemas by accessor type");
                AssertTrue(hydraFields[0].RelativePath == "VsHydra.dat", "field query should keep file context");
                AssertTrue(hydraFields[0].Value.SignedValue == 303, "field query should read versus scalar values");

                IReadOnlyList<KarProjectFieldInfo> spawnFields = data.QueryFieldValues(new KarProjectFieldQueryOptions
                {
                    Roots = new KarProjectRootQueryOptions
                    {
                        Files = new KarProjectFileQueryOptions { Kind = KarFileKind.MapData },
                    },
                    Text = "spawn/death",
                });
                AssertTrue(spawnFields.Count == 2 && spawnFields.All(field => field.FieldName == "positionNode"), "field text search should match field descriptions across project roots");

                IReadOnlyList<KarProjectFieldInfo> mapOnly = data.QueryFieldValues(new KarProjectFieldQueryOptions
                {
                    Roots = new KarProjectRootQueryOptions
                    {
                        Files = new KarProjectFileQueryOptions { Kind = KarFileKind.MapData },
                    },
                    FieldName = "unknown1",
                });

                AssertTrue(mapOnly.Count == 2, "field query should respect root file filters");
                AssertTrue(mapOnly.All(field => field.File.Kind == KarFileKind.MapData), "field query file filters should keep map data only");
                AssertTrue(project.QueryFieldValues(null).Count == data.QueryFieldValues(null).Count, "project field query compatibility wrapper should delegate to data service");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
            }
        }

        private static void ProjectFieldSummariesGroupDistinctValues()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-field-summary-project-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(tempRoot);

            try
            {
                WriteFieldQueryFixture(tempRoot);

                KarProject project = KarProject.Open(tempRoot);
                KarProjectDataService data = project.DataService;
                IReadOnlyList<KarProjectFieldSummary> summaries = data.QueryFieldSummaries(new KarProjectFieldQueryOptions
                {
                    DataDefinitionIdOrAccessorTypeName = "kar.gr.data",
                    FieldName = "unknown1",
                });

                AssertTrue(summaries.Count == 1, "field summary query should group matching schema fields");
                KarProjectFieldSummary summary = summaries[0];
                AssertTrue(summary.DataDefinitionId == "kar.gr.data", "field summary should keep schema id");
                AssertTrue(summary.FieldName == "unknown1", "field summary should keep field name");
                AssertTrue(summary.Count == 2, "field summary should count roots");
                AssertTrue(summary.FileCount == 2, "field summary should count unique files");
                AssertTrue(summary.AvailableCount == 2, "field summary should count available values");
                AssertTrue(summary.UnavailableCount == 0, "field summary should count unavailable values");
                AssertTrue(summary.DistinctValueCount == 2, "field summary should count distinct values");
                AssertTrue(summary.HasValueVariation, "field summary should flag varying values");
                AssertTrue(summary.DistinctValues.Any(value => value.SignedValue == 101 && value.Count == 1), "field summary should bucket GrCity1 value");
                AssertTrue(summary.DistinctValues.Any(value => value.SignedValue == 202 && value.Count == 1), "field summary should bucket GrSimple value");

                IReadOnlyList<KarProjectFieldSummary> hydraSummaries = data.QueryFieldSummaries(new KarProjectFieldQueryOptions
                {
                    DataDefinitionIdOrAccessorTypeName = "KAR_vsLegendaryData",
                    FieldName = "x0C",
                });

                AssertTrue(hydraSummaries.Count == 1, "field summary should match schemas by accessor type");
                AssertTrue(hydraSummaries[0].DistinctValueCount == 1, "field summary should group identical versus values");
                AssertTrue(!hydraSummaries[0].HasValueVariation, "field summary should not flag single values as varying");
                AssertTrue(project.QueryFieldSummaries(null).Count == data.QueryFieldSummaries(null).Count, "project field summary compatibility wrapper should delegate to data service");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
            }
        }

        private static void ProjectReportAggregatesInventories()
        {
            string tempRoot = Path.Combine(Path.GetTempPath(), "kar-toolkit-report-project-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(tempRoot);

            try
            {
                WriteFieldQueryFixture(tempRoot);

                KarProject project = KarProject.Open(tempRoot);
                KarProjectReport report = project.CreateReport(new KarProjectReportOptions
                {
                    IncludeFieldSummaries = true,
                    Fields = new KarProjectFieldQueryOptions
                    {
                        DataDefinitionIdOrAccessorTypeName = "kar.gr.data",
                        FieldName = "unknown1",
                    },
                });

                AssertTrue(report.FileCount == 3, "project report should count indexed files");
                AssertTrue(report.HsdArchiveCount == 3, "project report should inspect HSD archives");
                AssertTrue(report.RootCount == 3, "project report should count archive roots");
                AssertTrue(report.KnownRootCount == 3, "project report should count known roots");
                AssertTrue(report.UnknownRootCount == 0, "project report should count unknown roots");
                AssertTrue(report.DataDefinitionUsageCount == 2, "project report should group schema usage");
                AssertTrue(report.FieldSummaryCount == 1, "project report should include requested field summaries");
                AssertTrue(report.FieldSummaries[0].HasValueVariation, "project report field summaries should retain value variation");
                AssertTrue(report.FileCategories.Any(group => group.Name == "Maps" && group.Count == 2), "project report should summarize map files by category");
                AssertTrue(report.FileKinds.Any(group => group.Name == KarFileKind.VersusData.ToString() && group.Count == 1), "project report should summarize files by kind");
                AssertTrue(report.MapCount == 2, "project report should count map bundles");
                AssertTrue(report.IncompleteMapCount == 2, "project report should count incomplete map bundles");
            }
            finally
            {
                if (Directory.Exists(tempRoot))
                    Directory.Delete(tempRoot, true);
            }
        }

        private static void RegistryRejectsAmbiguousDefinitions()
        {
            KarDataDefinition first = MakeDefinition("kar.test.first", "TestAccessor");
            KarDataDefinition duplicateId = MakeDefinition("kar.test.first", "OtherAccessor");
            KarDataDefinition duplicateAccessor = MakeDefinition("kar.test.second", "TestAccessor");

            AssertThrows<ArgumentException>(
                () => new KarDataDefinitionRegistry(new[] { first, duplicateId }),
                "duplicate definition ids should fail");
            AssertThrows<ArgumentException>(
                () => new KarDataDefinitionRegistry(new[] { first, duplicateAccessor }),
                "duplicate accessor mappings should fail");
        }

        private static void DefinitionRejectsAmbiguousFields()
        {
            AssertThrows<ArgumentException>(
                () => new KarDataDefinition(
                    "kar.test.definition",
                    "Test Definition",
                    "Tests",
                    "TestAccessor",
                    "Test definition.",
                    "tests",
                    new[]
                    {
                        new KarDataFieldDefinition("x00", 0, "s32", "First field."),
                        new KarDataFieldDefinition("X00", 4, "s32", "Duplicate field."),
                    }),
                "duplicate field names should fail");
        }

        private static void AssertResolves(KarDataDefinitionRegistry registry, string id, string accessorTypeName)
        {
            KarDataDefinition byId;
            KarDataDefinition byAccessor;
            KarDataDefinition byFind;

            AssertTrue(registry.TryGet(id, out byId), "registry should resolve " + id + " by id");
            AssertTrue(registry.TryGetByAccessorTypeName(accessorTypeName, out byAccessor), "registry should resolve " + accessorTypeName + " by accessor");
            AssertTrue(registry.TryFind(accessorTypeName, out byFind), "registry should find " + accessorTypeName);
            AssertTrue(object.ReferenceEquals(byId, byAccessor), id + " id/accessor lookup should return the same definition");
            AssertTrue(object.ReferenceEquals(byId, byFind), id + " find lookup should return the same definition");
        }

        private static KarDataDefinition MakeDefinition(string id, string accessorTypeName)
        {
            return new KarDataDefinition(
                id,
                "Test Definition",
                "Tests",
                accessorTypeName,
                "Test definition.",
                "tests",
                new[] { new KarDataFieldDefinition("x00", 0, "s32", "Test field.") },
                4);
        }

        private static void WriteFieldQueryFixture(string tempRoot)
        {
            KAR_grData city = new KAR_grData();
            city.Unknown1 = 101;
            WriteHsdFile(Path.Combine(tempRoot, "GrCity1.dat"), "grDataCity1", city);

            KAR_grData simple = new KAR_grData();
            simple.Unknown1 = 202;
            WriteHsdFile(Path.Combine(tempRoot, "GrSimple.dat"), "grDataSimple", simple);

            KAR_vsLegendaryData hydra = new KAR_vsLegendaryData();
            hydra.x0C = 303;
            WriteHsdFile(Path.Combine(tempRoot, "VsHydra.dat"), "vsDataHydra", hydra);
        }

        private sealed class TestArchiveDefinitionProvider : KarArchiveDefinitionProvider
        {
            public override KarArchiveDefinition GetDefinition(string relativePath, KarFileKind kind, string mapName)
            {
                return new KarArchiveDefinition(
                    kind,
                    "Custom Test Archive",
                    "Tests",
                    "Custom archive definition for project-level schema tests.",
                    new[]
                    {
                        KarRootDefinition.ExactData("customRoot", "Custom test root", "KAR_vsLegendaryData", "kar.test.custom"),
                    });
            }
        }

        private static void WriteHsdFile(string path, string rootName, HSDAccessor data)
        {
            HSDRawFile file = new HSDRawFile();
            file.Roots.Add(new HSDRootNode
            {
                Name = rootName,
                Data = data,
            });
            file.Save(path);
        }

        private static void WriteA2DPackage(string path)
        {
            WriteA2DPackage(path, new[] { "entry.bin" });
        }

        private static void WriteA2DPackage(string path, string[] entryNames)
        {
            if (entryNames == null || entryNames.Length == 0)
                throw new ArgumentException("A2D test package needs at least one entry.", nameof(entryNames));

            List<byte> bytes = new List<byte>(new byte[8 + entryNames.Length * 8]);
            int[] nameOffsets = new int[entryNames.Length];
            int[] dataOffsets = new int[entryNames.Length];

            for (int i = 0; i < entryNames.Length; i++)
            {
                nameOffsets[i] = bytes.Count;
                bytes.AddRange(Encoding.ASCII.GetBytes(entryNames[i]));
                bytes.Add(0);
            }

            for (int i = 0; i < entryNames.Length; i++)
            {
                dataOffsets[i] = bytes.Count;
                bytes.Add((byte)(0xA0 + i));
                bytes.Add((byte)(0xB0 + i));
                bytes.Add((byte)(0xC0 + i));
                bytes.Add((byte)(0xD0 + i));
            }

            byte[] data = bytes.ToArray();
            WriteUInt32BigEndian(data, 0x00, 0);
            WriteUInt32BigEndian(data, 0x04, (uint)entryNames.Length);
            for (int i = 0; i < entryNames.Length; i++)
            {
                int pairOffset = 8 + i * 8;
                WriteUInt32BigEndian(data, pairOffset, (uint)nameOffsets[i]);
                WriteUInt32BigEndian(data, pairOffset + 4, (uint)dataOffsets[i]);
            }

            File.WriteAllBytes(path, data);
        }

        private static void WriteUInt32BigEndian(byte[] data, int offset, uint value)
        {
            data[offset] = (byte)(value >> 24);
            data[offset + 1] = (byte)(value >> 16);
            data[offset + 2] = (byte)(value >> 8);
            data[offset + 3] = (byte)value;
        }

        private static void AssertIssue(KarDataDefinitionValidationReport report, string code)
        {
            AssertTrue(report.Issues.Any(issue => issue.Code == code), "schema validation should report " + code);
        }

        private static void Run(string name, Action test)
        {
            try
            {
                test();
            }
            catch (Exception ex)
            {
                Failures.Add(name + ": unexpected " + ex.GetType().Name + ": " + ex.Message);
            }
        }

        private static void AssertTrue(bool condition, string message)
        {
            _assertionCount++;
            if (!condition)
                Failures.Add(message);
        }

        private static void AssertThrows<TException>(Action action, string message)
            where TException : Exception
        {
            _assertionCount++;
            try
            {
                action();
                Failures.Add(message + " (no exception thrown)");
            }
            catch (TException)
            {
            }
            catch (Exception ex)
            {
                Failures.Add(message + " (threw " + ex.GetType().Name + ")");
            }
        }
    }
}
