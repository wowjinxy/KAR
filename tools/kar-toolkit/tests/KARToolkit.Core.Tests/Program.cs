using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using HSDRaw;
using HSDRaw.AirRide;
using HSDRaw.AirRide.Gr.Data;
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
            Run("FileKindRegistryDescribesProjectHandlers", FileKindRegistryDescribesProjectHandlers);
            Run("ResourceHandlerRegistryDescribesResourceOperations", ResourceHandlerRegistryDescribesResourceOperations);
            Run("ProjectFileQueryFiltersFiles", ProjectFileQueryFiltersFiles);
            Run("ResourceReferencesAddressProjectObjects", ResourceReferencesAddressProjectObjects);
            Run("ProjectResourceGraphIndexesResourcesAndRelationships", ProjectResourceGraphIndexesResourcesAndRelationships);
            Run("ProjectResourceServiceQueriesAndResolvesAddresses", ProjectResourceServiceQueriesAndResolvesAddresses);
            Run("ProjectResourceServiceQueriesFieldValues", ProjectResourceServiceQueriesFieldValues);
            Run("ProjectResourceServiceReadsAndExportsResourcesSafely", ProjectResourceServiceReadsAndExportsResourcesSafely);
            Run("ProjectResourceServiceImportsResourcesSafely", ProjectResourceServiceImportsResourcesSafely);
            Run("ProjectResourceServiceWritesScalarEditsToOutput", ProjectResourceServiceWritesScalarEditsToOutput);
            Run("ProjectResourceServiceReportsUnifiedOutputStatus", ProjectResourceServiceReportsUnifiedOutputStatus);
            Run("ProjectResourceServiceAppliesModifiedResourceOutputs", ProjectResourceServiceAppliesModifiedResourceOutputs);
            Run("ProjectOutputInventoryTracksModFiles", ProjectOutputInventoryTracksModFiles);
            Run("ProjectModWorkspaceSummarizesOutputState", ProjectModWorkspaceSummarizesOutputState);
            Run("ProjectMapOutputQueryGroupsModFiles", ProjectMapOutputQueryGroupsModFiles);
            Run("ProjectMapServiceCoordinatesMapWorkflows", ProjectMapServiceCoordinatesMapWorkflows);
            Run("ProjectMapScriptServiceGroupsMapAndScriptResources", ProjectMapScriptServiceGroupsMapAndScriptResources);
            Run("ProjectRelationshipServiceConnectsMapsAndScriptTables", ProjectRelationshipServiceConnectsMapsAndScriptTables);
            Run("ProjectScriptServiceQueriesScriptTables", ProjectScriptServiceQueriesScriptTables);
            Run("ProjectA2DServiceQueriesProjectEntries", ProjectA2DServiceQueriesProjectEntries);
            Run("ProjectA2DServiceExtractsAndReplacesEntriesSafely", ProjectA2DServiceExtractsAndReplacesEntriesSafely);
            Run("ProjectArchiveServiceCoordinatesArchiveWorkflows", ProjectArchiveServiceCoordinatesArchiveWorkflows);
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

            KarProjectResourceHandler rootHandler = registry.GetHandler(KarResourceKind.HsdRoot);
            AssertTrue(rootHandler.CanQueryFieldValues && rootHandler.CanSetScalarFields, "HSD root resources should support field and scalar workflows");
            AssertTrue(rootHandler.CanExportToOutput && !rootHandler.CanReadBytes && !rootHandler.CanImportFromFile, "HSD root resources should stage containing archives without standalone byte imports");

            KarProjectResourceHandler entryHandler = registry.GetHandler(KarResourceKind.A2DEntry);
            AssertTrue(entryHandler.CanReadBytes && entryHandler.CanImportFromFile, "A2D entry resources should support byte reads and imports");
            AssertTrue(entryHandler.CanApplyOutput && !entryHandler.CanSetScalarFields, "A2D entry resources should support sidecar apply but not scalar edits");

            KarProjectResourceHandler found;
            AssertTrue(registry.TryFindHandler("a2d-entry", out found) && found.Kind == KarResourceKind.A2DEntry, "resource handlers should resolve by stable id");
            AssertTrue(registry.TryFindHandler("HsdRoot", out found) && found.Id == "hsd-root", "resource handlers should resolve by enum name");
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
                AssertTrue(files.Query(new KarProjectFileQueryOptions { HasOutputCopy = true }).Count == 0, "file query should filter files with output copies");

                KarProjectFileCopyResult copyResult = files.CopyFileToOutput("GrCity1.dat", true);

                AssertTrue(copyResult.File.RelativePath == "GrCity1.dat", "file service should return copied file metadata");
                AssertTrue(File.Exists(copyResult.OutputPath), "file service should copy project files to output");
                AssertTrue(files.GetReadPath("GrCity1.dat") == files.GetOutputPath("GrCity1.dat"), "file service should read from output after copies exist");
                AssertTrue(project.OutputService.GetFile("GrCity1.dat").CanInspectMapArchive, "output file records should expose handler capabilities");
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
                KarProjectResourceGraph graph = project.CreateResourceGraph();

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

                KarProjectResourceInfo rootResource = resources.Get("VsHydra.dat:vsDataHydra");
                AssertTrue(rootResource.IsHsdRoot, "resource get should resolve HSD root addresses");
                AssertTrue(rootResource.Root.RootName == "vsDataHydra", "resolved HSD root resources should expose root metadata");
                AssertTrue(rootResource.File.RelativePath == "VsHydra.dat", "resolved HSD root resources should expose parent file metadata");

                KarProjectResourceInfo entryResource = project.GetResource("A2Info.dat#ScInfGo2D.tm");
                AssertTrue(entryResource.IsA2DEntry, "project resource wrapper should resolve A2D entry addresses");
                AssertTrue(entryResource.A2DEntry.Index == 0, "resolved A2D resources should expose entry metadata");
                AssertTrue(project.QueryResources(new KarProjectResourceQueryOptions
                {
                    Address = "A2Info.dat#ScInfGo2D.tm",
                }).Single().Address == entryResource.Address, "project resource query wrapper should filter by address");

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

                resources.SetScalarFieldFromText("VsHydra.dat:vsDataHydra", "x0C", "0x1F4");
                AssertTrue(resources.GetFieldValue("VsHydra.dat:vsDataHydra", "x0C").Value.SignedValue == 500, "resource field query should read edited values from output copies");
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
                AssertTrue(resources.ReadBytes("A2Info.dat").SequenceEqual(packageBytes), "resource reads should return active file bytes");
                AssertTrue(project.ReadResourceBytes("A2Info.dat#ScInfGo2D.tm").SequenceEqual(new byte[] { 0xA0, 0xB0, 0xC0, 0xD0 }), "project resource read wrapper should return A2D entry bytes");
                AssertThrows<NotSupportedException>(
                    () => resources.ReadBytes("VsHydra.dat:vsDataHydra"),
                    "resource reads should reject non-byte-addressable HSD roots");

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

                KarProjectFieldInfo editedField = project.DataService.QueryFieldValues(new KarProjectFieldQueryOptions
                {
                    DataDefinitionIdOrAccessorTypeName = "kar.vs.legendary",
                    FieldName = "x0C",
                }).Single(field => field.RelativePath == "VsHydra.dat");
                AssertTrue(editedField.Value.SignedValue == 500, "project data queries should read resource scalar edits from output copies");

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

                KarProjectModWorkspace workspace = mods.CreateSnapshot();
                AssertTrue(object.ReferenceEquals(mods.Project, project), "mod workspace service should retain project context");
                AssertTrue(object.ReferenceEquals(workspace.Project, project), "mod workspace snapshots should retain project context");
                AssertTrue(workspace.HasOutputs, "mod workspace snapshots should detect staged outputs");
                AssertTrue(workspace.HasModifiedOutputs, "mod workspace snapshots should detect modified outputs");
                AssertTrue(workspace.OutputFileCount == 5, "mod workspace snapshots should count project-file outputs and output assets");
                AssertTrue(workspace.ProjectOutputFileCount == 4, "mod workspace snapshots should count staged project files");
                AssertTrue(workspace.OrphanOutputFileCount == 1, "mod workspace snapshots should count output assets as output-only files when they share the output files root");
                AssertTrue(workspace.ModifiedProjectOutputFileCount == 1, "mod workspace snapshots should count modified project files");
                AssertTrue(workspace.UnchangedProjectOutputFileCount == 3, "mod workspace snapshots should count unchanged project files");
                AssertTrue(workspace.ResourceOutputCount == 5, "mod workspace snapshots should count resource outputs with staged data");
                AssertTrue(workspace.ProjectFileResourceOutputCount == 4, "mod workspace snapshots should count project-file resource outputs");
                AssertTrue(workspace.OutputAssetResourceOutputCount == 1, "mod workspace snapshots should count output asset resource outputs");
                AssertTrue(workspace.ModifiedResourceOutputCount == 2, "mod workspace snapshots should count modified project resources and sidecars");
                AssertTrue(workspace.A2DEntryOutputCount == 1, "mod workspace snapshots should count staged A2D sidecars");
                AssertTrue(workspace.ModifiedA2DEntryOutputCount == 1, "mod workspace snapshots should count modified A2D sidecars");
                AssertTrue(workspace.MapOutputCount == 1, "mod workspace snapshots should count maps with staged outputs");
                AssertTrue(workspace.CompleteMapOutputCount == 1, "mod workspace snapshots should count complete staged map outputs");
                AssertTrue(workspace.ModifiedMapOutputCount == 0, "mod workspace snapshots should count modified map outputs");
                AssertTrue(workspace.ModifiedResourceOutputs.Any(output => output.Address == "Loose.bin"), "mod workspace snapshots should include modified file resources");
                AssertTrue(workspace.ModifiedResourceOutputs.Any(output => output.Address == "A2Info.dat#ScInfGo2D.tm"), "mod workspace snapshots should include modified A2D sidecars");

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

                IReadOnlyList<KarProjectScriptTable> screenInfoTables = scripts.QueryTables(new KarProjectScriptTableQueryOptions
                {
                    Role = "ScreenInfoTable",
                });
                AssertTrue(screenInfoTables.Count == 2, "script service should filter script tables by role");

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
