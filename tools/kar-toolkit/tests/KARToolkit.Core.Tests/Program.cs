using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using HSDRaw;
using HSDRaw.AirRide;
using HSDRaw.AirRide.Gr.Data;
using KARToolkit.Core;

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

                KarProjectOutputInventory inventory = project.CreateOutputInventory();

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

                AssertTrue(project.QueryOutputFiles(new KarProjectOutputFileQueryOptions { Kind = KarFileKind.MapData }).Count == 1, "output query should filter by kind");
                AssertTrue(project.QueryOutputFiles(new KarProjectOutputFileQueryOptions { IsProjectFile = false }).Count == 1, "output query should filter orphan files");
                AssertTrue(project.QueryOutputFiles(new KarProjectOutputFileQueryOptions { Status = KarProjectOutputFileStatus.DiffersFromSource }).Count == 1, "output query should filter modified files");

                KarProjectReport report = project.CreateReport(new KarProjectReportOptions
                {
                    OutputFiles = new KarProjectOutputFileQueryOptions { Kind = KarFileKind.MapData },
                });

                AssertTrue(report.OutputFileCount == 1, "project report should include filtered output inventory counts");
                AssertTrue(report.ProjectOutputFileCount == 1, "project report should count filtered project output files");
                AssertTrue(report.OrphanOutputFileCount == 0, "project report should count filtered orphan output files");
                AssertTrue(report.UnchangedProjectOutputFileCount == 1, "project report should count filtered unchanged project outputs");
                AssertTrue(report.ModifiedProjectOutputFileCount == 0, "project report should count filtered modified project outputs");
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
                IReadOnlyList<KarProjectDataDefinitionUsage> usages = project.QueryDataDefinitionUsage(null);
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
                IReadOnlyList<KarProjectFieldInfo> mapUnknowns = project.QueryFieldValues(new KarProjectFieldQueryOptions
                {
                    DataDefinitionIdOrAccessorTypeName = "kar.gr.data",
                    FieldName = "unknown1",
                });

                AssertTrue(mapUnknowns.Count == 2, "field query should find map unknown1 values across project files");
                AssertTrue(mapUnknowns.All(field => field.FieldName == "unknown1"), "field query should filter by field name");
                AssertTrue(mapUnknowns.Any(field => field.RelativePath == "GrCity1.dat" && field.Value.SignedValue == 101), "field query should read GrCity1 scalar values");
                AssertTrue(mapUnknowns.Any(field => field.RelativePath == "GrSimple.dat" && field.Value.SignedValue == 202), "field query should read GrSimple scalar values");

                IReadOnlyList<KarProjectFieldInfo> hydraFields = project.QueryFieldValues(new KarProjectFieldQueryOptions
                {
                    DataDefinitionIdOrAccessorTypeName = "KAR_vsLegendaryData",
                    FieldName = "x0C",
                });

                AssertTrue(hydraFields.Count == 1, "field query should match schemas by accessor type");
                AssertTrue(hydraFields[0].RelativePath == "VsHydra.dat", "field query should keep file context");
                AssertTrue(hydraFields[0].Value.SignedValue == 303, "field query should read versus scalar values");

                IReadOnlyList<KarProjectFieldInfo> mapOnly = project.QueryFieldValues(new KarProjectFieldQueryOptions
                {
                    Roots = new KarProjectRootQueryOptions
                    {
                        Files = new KarProjectFileQueryOptions { Kind = KarFileKind.MapData },
                    },
                    FieldName = "unknown1",
                });

                AssertTrue(mapOnly.Count == 2, "field query should respect root file filters");
                AssertTrue(mapOnly.All(field => field.File.Kind == KarFileKind.MapData), "field query file filters should keep map data only");
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
                IReadOnlyList<KarProjectFieldSummary> summaries = project.QueryFieldSummaries(new KarProjectFieldQueryOptions
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

                IReadOnlyList<KarProjectFieldSummary> hydraSummaries = project.QueryFieldSummaries(new KarProjectFieldQueryOptions
                {
                    DataDefinitionIdOrAccessorTypeName = "KAR_vsLegendaryData",
                    FieldName = "x0C",
                });

                AssertTrue(hydraSummaries.Count == 1, "field summary should match schemas by accessor type");
                AssertTrue(hydraSummaries[0].DistinctValueCount == 1, "field summary should group identical versus values");
                AssertTrue(!hydraSummaries[0].HasValueVariation, "field summary should not flag single values as varying");
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
