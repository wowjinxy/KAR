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
            Run("ProjectFileQueryFiltersFiles", ProjectFileQueryFiltersFiles);
            Run("ProjectOutputInventoryTracksModFiles", ProjectOutputInventoryTracksModFiles);
            Run("ProjectMapOutputQueryGroupsModFiles", ProjectMapOutputQueryGroupsModFiles);
            Run("ProjectMapServiceCoordinatesMapWorkflows", ProjectMapServiceCoordinatesMapWorkflows);
            Run("ProjectArchiveServiceCoordinatesArchiveWorkflows", ProjectArchiveServiceCoordinatesArchiveWorkflows);
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

                AssertTrue(project.QueryFiles(new KarProjectFileQueryOptions { Kind = KarFileKind.MapData }).Count == 1, "file query should filter by kind");
                AssertTrue(project.QueryFiles(new KarProjectFileQueryOptions { Category = "maps" }).Count == 1, "file query should filter by category case-insensitively");
                AssertTrue(project.QueryFiles(new KarProjectFileQueryOptions { HasOutputCopy = true }).Count == 0, "file query should filter files with output copies");

                project.CopyToOutput("GrCity1.dat", true);

                AssertTrue(project.QueryFiles(new KarProjectFileQueryOptions { HasOutputCopy = true }).Count == 1, "file query should see newly created output copies");
                AssertTrue(project.QueryFiles(new KarProjectFileQueryOptions { HasOutputCopy = false }).Count == project.Files.Count - 1, "file query should filter source-only files");
                AssertTrue(project.QueryFiles(new KarProjectFileQueryOptions
                {
                    Kind = KarFileKind.MapData,
                    HasOutputCopy = true,
                }).Count == 1, "file query should combine filters");
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
            byte[] data = new byte[0x24];
            WriteUInt32BigEndian(data, 0x00, 0);
            WriteUInt32BigEndian(data, 0x04, 1);
            WriteUInt32BigEndian(data, 0x08, 0x10);
            WriteUInt32BigEndian(data, 0x0C, 0x20);

            byte[] name = Encoding.ASCII.GetBytes("entry.bin");
            Buffer.BlockCopy(name, 0, data, 0x10, name.Length);
            data[0x20] = 0xAA;
            data[0x21] = 0xBB;
            data[0x22] = 0xCC;
            data[0x23] = 0xDD;

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
