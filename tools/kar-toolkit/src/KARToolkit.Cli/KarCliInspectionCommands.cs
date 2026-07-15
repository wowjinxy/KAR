using KARToolkit.Core;
using KARToolkit.Core.AirRide;
using static KARToolkit.Cli.KarCliDtoFactory;
using static KARToolkit.Cli.KarCliJsonWriter;
using static KARToolkit.Cli.KarCliProjectFactory;
using static KARToolkit.Cli.KarCliQueryFactory;
using static KARToolkit.Cli.KarCliTextWriter;

namespace KARToolkit.Cli;

internal static class KarCliInspectionCommands
{
    public static int ShowProject(KarCliOptions options)
    {
        options.RequirePositionals("project", 1);
        KarProject project = OpenProject(options);

        if (options.Json)
        {
            WriteJson(ToProjectDto(project));
            return 0;
        }

        Console.WriteLine("Project: " + project.Name);
        Console.WriteLine("Source: " + project.SourceRoot);
        Console.WriteLine("Source files: " + project.SourceFilesRoot);
        Console.WriteLine("Output: " + project.OutputRoot);
        Console.WriteLine("Output files: " + project.OutputFilesRoot);
        Console.WriteLine("Files: " + project.FileService.Files.Count);
        Console.WriteLine("Maps: " + project.Maps.Count);

        foreach (IGrouping<string, KarProjectFile> group in project.FileService.Files.GroupBy(file => file.Category).OrderBy(group => group.Key))
            Console.WriteLine("  " + group.Key + ": " + group.Count());

        return 0;
    }

    public static int ShowFileKinds(KarCliOptions options)
    {
        options.RequirePositionals("file-kinds", 0);
        List<KarProjectFileHandler> handlers = KarProjectFileHandlerRegistry.Default.Handlers
            .OrderBy(handler => handler.Category)
            .ThenBy(handler => handler.DisplayName)
            .ToList();

        if (options.Json)
        {
            WriteJson(handlers.Select(ToProjectFileHandlerDto).ToList());
            return 0;
        }

        foreach (KarProjectFileHandler handler in handlers)
            PrintProjectFileHandler(handler);

        return 0;
    }

    public static int ShowResourceHandlers(KarCliOptions options)
    {
        options.RequirePositionals("resource-handlers", 0);
        List<KarProjectResourceHandler> handlers = KarProjectResourceHandlerRegistry.Default.Handlers
            .OrderBy(handler => handler.Kind)
            .ToList();

        if (options.Json)
        {
            WriteJson(handlers.Select(ToProjectResourceHandlerDto).ToList());
            return 0;
        }

        foreach (KarProjectResourceHandler handler in handlers)
            PrintProjectResourceHandler(handler);

        return 0;
    }

    public static int ShowResourceActions(KarCliOptions options)
    {
        options.RequirePositionals("resource-actions", 1);
        KarProject project = OpenProject(options);
        List<KarProjectResourceInfo> resources = project.ResourceService.Query(CreateResourceQuery(options))
            .ToList();

        if (options.Json)
        {
            WriteJson(resources.Select(ToProjectResourceActionSetDto).ToList());
            return 0;
        }

        foreach (KarProjectResourceInfo resource in resources)
            PrintProjectResourceActions(resource);

        return 0;
    }

    public static int ShowResourceActionPlans(KarCliOptions options)
    {
        options.RequirePositionals("resource-action-plans", 1);
        KarProject project = OpenProject(options);
        List<KarProjectResourceActionPlan> plans = project.ResourceService.QueryActionPlans(CreateResourceActionPlanQuery(options))
            .ToList();

        if (options.Json)
        {
            WriteJson(plans.Select(ToProjectResourceActionPlanDto).ToList());
            return 0;
        }

        foreach (KarProjectResourceActionPlan plan in plans)
            PrintProjectResourceActionPlan(plan);

        return 0;
    }

    public static int ShowReport(KarCliOptions options)
    {
        options.RequirePositionals("report", 1);
        KarProject project = OpenProject(options);
        KarProjectReport report = project.CreateReport(CreateReportOptions(options));

        if (options.Json)
        {
            WriteJson(ToProjectReportDto(report));
            return 0;
        }

        PrintProjectReport(report);
        return 0;
    }

    public static int ShowDataCoverage(KarCliOptions options)
    {
        options.RequirePositionals("schema-gaps", 1);
        KarProject project = OpenProject(options);
        KarProjectDataCoverageReport report = project.SchemaService.CreateDataCoverageReport(CreateDataCoverageOptions(options));

        if (options.Json)
        {
            WriteJson(ToProjectDataCoverageReportDto(report));
            return 0;
        }

        PrintProjectDataCoverageReport(report);
        return 0;
    }

    public static int ShowOutputs(KarCliOptions options)
    {
        options.RequirePositionals("outputs", 1);
        KarProject project = OpenProject(options);
        KarProjectOutputInventory inventory = project.OutputService.CreateInventory(CreateOutputQuery(options));

        if (options.Json)
        {
            WriteJson(ToProjectOutputInventoryDto(inventory));
            return 0;
        }

        Console.WriteLine("Output: " + project.OutputRoot);
        Console.WriteLine("Output files: " + inventory.Count + " project=" + inventory.ProjectFileCount + " modified=" + inventory.ModifiedProjectFileCount + " unchanged=" + inventory.UnchangedProjectFileCount + " orphan=" + inventory.OrphanFileCount);
        foreach (KarProjectOutputFileInfo file in inventory.Files)
            PrintProjectOutputFile(file);

        return 0;
    }

    public static int ShowModWorkspace(KarCliOptions options)
    {
        options.RequirePositionals("mod-workspace", 1);
        KarProject project = OpenProject(options);
        KarProjectModWorkspace workspace = project.ModWorkspaceService.CreateSnapshot(CreateModWorkspaceOptions(options));

        if (options.Json)
        {
            WriteJson(ToProjectModWorkspaceDto(workspace));
            return 0;
        }

        PrintProjectModWorkspace(workspace);
        return 0;
    }

    public static int ShowToolkitSnapshot(KarCliOptions options)
    {
        options.RequirePositionals("toolkit", 1);
        KarProject project = OpenProject(options);
        KarProjectToolkitSnapshot snapshot = project.ToolkitService.CreateSnapshot(CreateToolkitSnapshotOptions(options));

        if (options.Json)
        {
            WriteJson(ToProjectToolkitSnapshotDto(snapshot));
            return 0;
        }

        PrintProjectToolkitSnapshot(snapshot);
        return 0;
    }

    public static int ShowToolkitSurface(KarCliOptions options)
    {
        options.RequirePositionals("toolkit-surface", 1);
        KarProject project = OpenProject(options);
        KarProjectToolkitSurface surface = project.ToolkitService.CreateSurface(CreateToolkitSnapshotOptions(options));

        if (options.Json)
        {
            WriteJson(ToProjectToolkitSurfaceDto(surface));
            return 0;
        }

        PrintProjectToolkitSurface(surface);
        return 0;
    }

    public static int ShowDomainContexts(KarCliOptions options)
    {
        options.RequirePositionals("domains", 1);
        KarProject project = OpenProject(options);
        List<KarProjectDomainContext> contexts = project.ToolkitService.QueryDomainContexts(CreateToolkitSnapshotOptions(options))
            .ToList();

        if (options.Json)
        {
            WriteJson(contexts.Select(ToProjectDomainContextDto).ToList());
            return 0;
        }

        foreach (KarProjectDomainContext context in contexts)
            PrintProjectDomainContext(context);

        return 0;
    }

    public static int ShowMapOutputs(KarCliOptions options)
    {
        options.RequirePositionals("map-outputs", 1);
        KarProject project = OpenProject(options);
        List<KarProjectMapOutputInfo> mapOutputs = project.MapService.QueryOutputs(CreateMapOutputQuery(options, project))
            .OrderBy(map => map.Name)
            .ToList();

        if (options.Json)
        {
            WriteJson(mapOutputs.Select(ToProjectMapOutputDto).ToList());
            return 0;
        }

        Console.WriteLine("Output: " + project.OutputRoot);
        Console.WriteLine("Map outputs: " + mapOutputs.Count + " modified=" + mapOutputs.Count(map => map.HasModifiedOutput) + " complete=" + mapOutputs.Count(map => map.HasCompleteOutputSet));
        foreach (KarProjectMapOutputInfo mapOutput in mapOutputs)
            PrintProjectMapOutput(mapOutput);

        return 0;
    }

    public static int ShowMaps(KarCliOptions options)
    {
        options.RequirePositionals("maps", 1);
        KarProject project = OpenProject(options);

        if (options.Json)
        {
            WriteJson(project.MapService.Bundles.Select(ToMapBundleDto).ToList());
            return 0;
        }

        foreach (KarMapBundle map in project.MapService.Bundles)
        {
            string pieces = string.Join(", ", map.Files.Select(file => file.RelativePath));
            Console.WriteLine(map.Name + ": " + pieces);
        }

        return 0;
    }

    public static int ShowVehicles(KarCliOptions options)
    {
        options.RequirePositionals("vehicles", 1);
        KarProject project = OpenProject(options);
        List<KarVehicleBundle> vehicles = project.VehicleService.Query(CreateVehicleQuery(options))
            .ToList();

        if (options.Json)
        {
            WriteJson(vehicles.Select(ToVehicleBundleDto).ToList());
            return 0;
        }

        foreach (KarVehicleBundle vehicle in vehicles)
            PrintVehicleBundle(vehicle);

        return 0;
    }

    public static int ShowRelationships(KarCliOptions options)
    {
        options.RequirePositionals("relationships", 1);
        KarProject project = OpenProject(options);
        List<KarProjectRelationship> relationships = options.Positionals.Count >= 2
            ? project.RelationshipService.QueryMap(options.Positionals[1]).ToList()
            : project.RelationshipService.Query().ToList();
        KarProjectRelationshipQueryOptions query = CreateRelationshipQuery(options);
        relationships = relationships.Where(query.Matches).ToList();

        if (options.Json)
        {
            WriteJson(relationships.Select(ToProjectRelationshipDto).ToList());
            return 0;
        }

        foreach (KarProjectRelationship relationship in relationships)
        {
            string map = relationship.MapName == null ? "project" : relationship.MapName;
            string package = relationship.PackageFile == null ? "" : " package=" + relationship.PackageFile.RelativePath;
            string entry = relationship.PackageEntryName == null ? "" : " entry=" + relationship.PackageEntryName;
            string size = relationship.PackageEntrySizeHex == null ? "" : " size=" + relationship.PackageEntrySizeHex;
            Console.WriteLine(map + ": " + relationship.Kind + "/" + relationship.Role + " " + relationship.RelativePath + package + entry + size);
        }

        return 0;
    }

    public static int ShowResourceGraph(KarCliOptions options)
    {
        options.RequirePositionals("resource-graph", 1);
        KarProject project = OpenProject(options);
        KarProjectResourceGraph graph = project.ResourceGraphService.Snapshot;

        if (options.Json)
        {
            WriteJson(ToProjectResourceGraphDto(graph));
            return 0;
        }

        PrintProjectResourceGraph(graph);
        return 0;
    }

    public static int ShowResources(KarCliOptions options)
    {
        options.RequirePositionals("resources", 1);
        KarProject project = OpenProject(options);
        List<KarProjectResourceInfo> resources = project.ResourceService.Query(CreateResourceQuery(options))
            .ToList();

        if (options.Json)
        {
            WriteJson(resources.Select(ToProjectResourceDto).ToList());
            return 0;
        }

        foreach (KarProjectResourceInfo resource in resources)
            PrintProjectResourceSummary(resource);

        return 0;
    }

    public static int ShowResource(KarCliOptions options)
    {
        options.RequirePositionals("resource", 2);
        KarProject project = OpenProject(options);
        KarProjectResourceInfo resource = project.ResourceService.Get(options.Positionals[1]);

        if (options.Json)
        {
            WriteJson(ToProjectResourceDto(resource));
            return 0;
        }

        PrintProjectResource(resource);
        return 0;
    }

    public static int ShowResolvedResource(KarCliOptions options)
    {
        options.RequirePositionals("resolve", 2);
        KarProject project = OpenProject(options);
        KarProjectResolvedResource resolved = project.ResourceAddressService.Resolve(options.Positionals[1]);

        if (options.Json)
        {
            WriteJson(ToProjectResolvedResourceDto(resolved));
            return 0;
        }

        PrintProjectResolvedResource(resolved);
        return 0;
    }

    public static int ShowResolvedResourceDetail(KarCliOptions options)
    {
        options.RequirePositionals("resolve-detail", 2);
        KarProject project = OpenProject(options);
        KarProjectResolvedResourceDetail detail = project.ResourceAddressService.GetDetail(options.Positionals[1]);

        if (options.Json)
        {
            WriteJson(ToProjectResolvedResourceDetailDto(detail));
            return 0;
        }

        PrintProjectResolvedResourceDetail(detail);
        return 0;
    }

    public static int ShowResolvedResourceDetails(KarCliOptions options)
    {
        options.RequirePositionals("resource-contexts", 1);
        KarProject project = OpenProject(options);
        List<KarProjectResolvedResourceDetail> details = project.ResourceAddressService.QueryDetails(CreateResourceQuery(options))
            .Where(detail => !options.OutputStatus.HasValue || (detail.Output != null && MatchesResourceOutputStatusOption(detail.Output, options.OutputStatus)))
            .ToList();

        if (options.Json)
        {
            WriteJson(details.Select(ToProjectResolvedResourceDetailDto).ToList());
            return 0;
        }

        foreach (KarProjectResolvedResourceDetail detail in details)
        {
            PrintProjectResolvedResourceDetail(detail);
            Console.WriteLine();
        }

        return 0;
    }

    public static int ShowResourceDetail(KarCliOptions options)
    {
        options.RequirePositionals("resource-detail", 2);
        KarProject project = OpenProject(options);
        KarProjectResourceDetail detail = project.ResourceService.GetDetail(options.Positionals[1]);

        if (options.Json)
        {
            WriteJson(ToProjectResourceDetailDto(detail));
            return 0;
        }

        PrintProjectResourceDetail(detail);
        return 0;
    }

    public static int ShowResourceDetails(KarCliOptions options)
    {
        options.RequirePositionals("resource-details", 1);
        KarProject project = OpenProject(options);
        List<KarProjectResourceDetail> details = project.ResourceService.QueryDetails(CreateResourceQuery(options))
            .Where(detail => !options.OutputStatus.HasValue || (detail.Output != null && MatchesResourceOutputStatusOption(detail.Output, options.OutputStatus)))
            .ToList();

        if (options.Json)
        {
            WriteJson(details.Select(ToProjectResourceDetailDto).ToList());
            return 0;
        }

        foreach (KarProjectResourceDetail detail in details)
        {
            PrintProjectResourceDetail(detail);
            Console.WriteLine();
        }

        return 0;
    }

    public static int ShowResourceDataViews(KarCliOptions options)
    {
        options.RequirePositionals("resource-data", 1);
        KarProject project = OpenProject(options);
        List<KarProjectResourceDataView> views = project.ResourceService.QueryDataViews(CreateResourceDataViewQuery(options))
            .Where(view => options.Positionals.Count >= 2 || view.HasFields)
            .ToList();

        if (options.Json)
        {
            WriteJson(views.Select(ToProjectResourceDataViewDto).ToList());
            return 0;
        }

        foreach (KarProjectResourceDataView view in views)
        {
            PrintProjectResourceDataView(view);
            Console.WriteLine();
        }

        return 0;
    }

    public static int ShowResourceDataFields(KarCliOptions options)
    {
        options.RequirePositionals("resource-data-fields", 1);
        KarProject project = OpenProject(options);
        List<KarProjectResourceDataFieldView> fields = project.ResourceService.QueryDataFields(CreateResourceDataFieldQuery(options))
            .ToList();

        if (options.Json)
        {
            WriteJson(fields.Select(ToProjectResourceDataFieldSummaryDto).ToList());
            return 0;
        }

        foreach (KarProjectResourceDataFieldView field in fields)
            PrintProjectResourceDataField(field);

        return 0;
    }

    public static int ShowResourceOutputs(KarCliOptions options)
    {
        options.RequirePositionals("resource-outputs", 1);
        KarProject project = OpenProject(options);
        List<KarProjectResourceOutputInfo> outputs = project.ResourceService.QueryOutputs(CreateResourceOutputQuery(options))
            .Where(output => MatchesResourceOutputStatusOption(output, options.OutputStatus))
            .ToList();

        if (options.Json)
        {
            WriteJson(outputs.Select(ToProjectResourceOutputDto).ToList());
            return 0;
        }

        foreach (KarProjectResourceOutputInfo output in outputs)
            PrintProjectResourceOutput(output);

        return 0;
    }

    public static int ShowResourceOutput(KarCliOptions options)
    {
        options.RequirePositionals("resource-output", 2);
        KarProject project = OpenProject(options);
        KarProjectResourceOutputInfo output = project.ResourceService.GetOutput(options.Positionals[1]);

        if (options.Json)
        {
            WriteJson(ToProjectResourceOutputDto(output));
            return 0;
        }

        PrintProjectResourceOutput(output);
        return 0;
    }

    public static int ShowResourceBytes(KarCliOptions options)
    {
        options.RequirePositionals("resource-bytes", 1);
        KarProject project = OpenProject(options);
        List<KarProjectResourceByteInfo> infos = project.ResourceService.QueryByteInfo(CreateResourceByteQuery(options))
            .ToList();

        if (options.Json)
        {
            WriteJson(infos.Select(ToProjectResourceByteInfoDto).ToList());
            return 0;
        }

        foreach (KarProjectResourceByteInfo info in infos)
            PrintProjectResourceByteInfo(info);

        return 0;
    }

    public static int ShowResourceFields(KarCliOptions options)
    {
        options.RequirePositionals("resource-fields", 1);
        KarProject project = OpenProject(options);
        List<KarProjectResourceFieldInfo> fields = project.ResourceService.QueryFieldValues(CreateResourceFieldQuery(options))
            .ToList();

        if (options.Json)
        {
            WriteJson(fields.Select(ToProjectResourceFieldValueDto).ToList());
            return 0;
        }

        foreach (KarProjectResourceFieldInfo field in fields)
            PrintProjectResourceFieldValue(field);

        return 0;
    }

    public static int ShowA2DEntries(KarCliOptions options)
    {
        return ShowA2DEntriesCore(options, false);
    }

    public static int ShowA2DEntryOutputs(KarCliOptions options)
    {
        options.RequirePositionals("a2d-entry-outputs", 1);
        KarProject project = OpenProject(options);
        List<KarProjectA2DEntryOutputInfo> outputs = project.A2DService.QueryEntryOutputs(CreateA2DEntryOutputQuery(options))
            .ToList();

        if (options.Json)
        {
            WriteJson(outputs.Select(ToA2DEntryOutputDto).ToList());
            return 0;
        }

        foreach (KarProjectA2DEntryOutputInfo output in outputs)
            Console.WriteLine(output.EntryPath + " [" + output.Status + "] " + output.OutputRelativePath);

        return 0;
    }

    public static int ShowA2DPackageContexts(KarCliOptions options)
    {
        options.RequirePositionals("a2d-packages", 1);
        KarProject project = OpenProject(options);
        List<KarProjectA2DPackageContext> contexts = project.A2DPackageContextService.Query(CreateA2DPackageContextQuery(options))
            .ToList();

        if (options.Json)
        {
            WriteJson(contexts.Select(ToProjectA2DPackageContextDto).ToList());
            return 0;
        }

        foreach (KarProjectA2DPackageContext context in contexts)
            PrintProjectA2DPackageContext(context);

        return 0;
    }

    public static int ShowScriptTables(KarCliOptions options)
    {
        options.RequirePositionals("script-tables", 1);
        KarProject project = OpenProject(options);
        List<KarProjectScriptTable> tables = project.ScriptService.QueryTables(CreateScriptTableQuery(options))
            .ToList();

        if (options.Json)
        {
            WriteJson(tables.Select(ToProjectScriptTableDto).ToList());
            return 0;
        }

        foreach (KarProjectScriptTable table in tables)
            PrintProjectScriptTable(table);

        return 0;
    }

    public static int ShowScriptContexts(KarCliOptions options)
    {
        options.RequirePositionals("script-contexts", 1);
        KarProject project = OpenProject(options);
        List<KarProjectScriptTableContext> contexts = project.ScriptContextService.Query(CreateScriptTableContextQuery(options))
            .Where(context => !options.OutputStatus.HasValue || (context.Output != null && MatchesResourceOutputStatusOption(context.Output, options.OutputStatus)))
            .ToList();

        if (options.Json)
        {
            WriteJson(contexts.Select(ToProjectScriptTableContextDto).ToList());
            return 0;
        }

        foreach (KarProjectScriptTableContext context in contexts)
            PrintProjectScriptTableContext(context);

        return 0;
    }

    private static int ShowA2DEntriesCore(KarCliOptions options, bool scriptTablesOnly)
    {
        options.RequirePositionals(scriptTablesOnly ? "script-tables" : "a2d-entries", 1);
        KarProject project = OpenProject(options);
        KarProjectA2DEntryQueryOptions query = CreateA2DEntryQuery(options);
        query.IsScriptTable = scriptTablesOnly ? true : query.IsScriptTable;
        List<KarProjectA2DEntryInfo> entries = project.A2DService.QueryEntries(query)
            .ToList();

        if (options.Json)
        {
            WriteJson(entries.Select(ToProjectA2DEntryDto).ToList());
            return 0;
        }

        foreach (KarProjectA2DEntryInfo entry in entries)
            Console.WriteLine(entry.EntryPath + " [" + entry.Role + "] offset=" + entry.DataOffsetHex + " size=" + entry.SizeHex);

        return 0;
    }

    public static int ShowFiles(KarCliOptions options)
    {
        options.RequirePositionals("files", 1);
        KarProject project = OpenProject(options);
        List<KarProjectFile> files = project.FileService.Query(CreateFileQuery(options))
            .OrderBy(file => file.Category)
            .ThenBy(file => file.RelativePath)
            .ToList();

        if (options.Json)
        {
            WriteJson(files.Select(ToProjectFileDto).ToList());
            return 0;
        }

        foreach (KarProjectFile file in files)
            PrintProjectFileSummary(file);

        return 0;
    }

    public static int ShowRoots(KarCliOptions options)
    {
        options.RequirePositionals("roots", 1);
        KarProject project = OpenProject(options);

        if (options.RootSummary)
            return ShowRootSummaries(project, options);

        List<KarProjectRootInfo> roots = project.DataService.QueryRoots(CreateRootQuery(options))
            .OrderBy(root => root.File.RelativePath)
            .ThenBy(root => root.Root.Name)
            .ToList();

        if (options.Json)
        {
            WriteJson(roots.Select(ToProjectRootDto).ToList());
            return 0;
        }

        foreach (KarProjectRootInfo root in roots)
            PrintProjectRootSummary(root);

        return 0;
    }

    public static int ShowArchives(KarCliOptions options)
    {
        options.RequirePositionals("archives", 1);
        KarProject project = OpenProject(options);
        List<KarArchiveInfo> archives = project.ArchiveService.QueryHsdArchives(CreateFileQuery(options))
            .OrderBy(archive => archive.File.Category)
            .ThenBy(archive => archive.File.RelativePath)
            .ToList();

        if (options.Json)
        {
            WriteJson(archives.Select(ToArchiveInventoryDto).ToList());
            return 0;
        }

        foreach (KarArchiveInfo archive in archives)
            PrintArchiveInventory(archive);

        return 0;
    }

    public static int ShowArchiveContexts(KarCliOptions options)
    {
        options.RequirePositionals("archive-contexts", 1);
        KarProject project = OpenProject(options);
        List<KarProjectArchiveContext> contexts = project.ArchiveContextService.Query(CreateArchiveContextQuery(options))
            .ToList();

        if (options.Json)
        {
            WriteJson(contexts.Select(ToProjectArchiveContextDto).ToList());
            return 0;
        }

        foreach (KarProjectArchiveContext context in contexts)
            PrintProjectArchiveContext(context);

        return 0;
    }

    public static int ShowArchiveSchemas(KarCliOptions options)
    {
        options.RequirePositionals("archive-schemas", 1);
        KarProject project = OpenProject(options);
        List<KarProjectArchiveSchemaInfo> schemas = project.SchemaService.QueryArchiveSchemas(CreateFileQuery(options))
            .OrderBy(schema => schema.Category)
            .ThenBy(schema => schema.RelativePath)
            .ToList();

        if (options.Json)
        {
            WriteJson(schemas.Select(ToProjectArchiveSchemaDto).ToList());
            return 0;
        }

        foreach (KarProjectArchiveSchemaInfo schema in schemas)
            PrintProjectArchiveSchema(schema);

        return 0;
    }

    private static int ShowRootSummaries(KarProject project, KarCliOptions options)
    {
        List<KarProjectRootSummary> summaries = project.DataService.QueryRootSummaries(CreateRootQuery(options))
            .OrderByDescending(summary => summary.Count)
            .ThenBy(summary => summary.RootName)
            .ToList();

        if (options.Json)
        {
            WriteJson(summaries.Select(ToProjectRootSummaryDto).ToList());
            return 0;
        }

        foreach (KarProjectRootSummary summary in summaries)
            PrintProjectRootSummaryGroup(summary);

        return 0;
    }

    public static int ShowSchemaUsage(KarCliOptions options)
    {
        options.RequirePositionals("schema-usage", 1);
        KarProject project = OpenProject(options);
        List<KarProjectDataDefinitionUsage> usages = project.SchemaService.QueryDataDefinitionUsage(CreateRootQuery(options))
            .OrderByDescending(usage => usage.Count)
            .ThenBy(usage => usage.DataDefinitionId)
            .ToList();

        if (options.Json)
        {
            WriteJson(usages.Select(ToDataDefinitionUsageDto).ToList());
            return 0;
        }

        foreach (KarProjectDataDefinitionUsage usage in usages)
            PrintDataDefinitionUsage(usage);

        return 0;
    }

    public static int ShowFields(KarCliOptions options)
    {
        options.RequirePositionals("fields", 1);
        if (options.RootSummary)
            return ShowFieldSummaries(options);

        KarProject project = OpenProject(options);
        List<KarProjectFieldInfo> fields = project.DataService.QueryFieldValues(CreateFieldQuery(options))
            .OrderBy(field => field.RelativePath)
            .ThenBy(field => field.RootName)
            .ThenBy(field => field.Field.Offset ?? int.MaxValue)
            .ThenBy(field => field.FieldName)
            .ToList();

        if (options.Json)
        {
            WriteJson(fields.Select(ToProjectFieldValueDto).ToList());
            return 0;
        }

        foreach (KarProjectFieldInfo field in fields)
            PrintProjectFieldValue(field);

        return 0;
    }

    public static int ShowFieldSummaries(KarCliOptions options)
    {
        options.RequirePositionals("field-summary", 1);
        KarProject project = OpenProject(options);
        List<KarProjectFieldSummary> summaries = project.DataService.QueryFieldSummaries(CreateFieldQuery(options))
            .OrderByDescending(summary => summary.Count)
            .ThenByDescending(summary => summary.DistinctValueCount)
            .ThenBy(summary => summary.DataDefinitionId)
            .ThenBy(summary => summary.Field.Offset ?? int.MaxValue)
            .ThenBy(summary => summary.FieldName)
            .ToList();

        if (options.Json)
        {
            WriteJson(summaries.Select(ToProjectFieldSummaryDto).ToList());
            return 0;
        }

        foreach (KarProjectFieldSummary summary in summaries)
            PrintProjectFieldSummary(summary);

        return 0;
    }

    public static int ShowFile(KarCliOptions options)
    {
        options.RequirePositionals("file", 2);
        KarProject project = OpenProject(options);
        KarProjectFile file = project.FileService.Get(options.Positionals[1]);

        if (options.Json)
        {
            WriteJson(ToProjectFileDto(file));
            return 0;
        }

        PrintProjectFile(file);
        return 0;
    }

    public static int ShowMap(KarCliOptions options)
    {
        options.RequirePositionals("map", 2);
        KarProject project = OpenProject(options);
        KarMapInfo map = project.MapService.Inspect(options.Positionals[1]);

        if (options.Json)
        {
            WriteJson(ToMapInfoDto(map));
            return 0;
        }

        Console.WriteLine("Map: " + map.Name);
        PrintArchiveSlot("Data", map.DataArchive);
        PrintArchiveSlot("Model", map.ModelArchive);
        PrintArchiveSlot("Event/Script", map.ScriptArchive);

        if (map.HasMissingRequiredRoots)
        {
            Console.WriteLine("Missing required roots:");
            foreach (KarRootDefinition root in map.MissingRequiredRoots)
                Console.WriteLine("  " + root.Pattern);
        }

        return 0;
    }

    public static int ShowMapScripts(KarCliOptions options)
    {
        options.RequirePositionals("map-scripts", 1);
        KarProject project = OpenProject(options);
        List<KarProjectMapScriptBundle> bundles = project.MapScriptService.Query(CreateMapScriptQuery(options))
            .ToList();

        if (options.Json)
        {
            WriteJson(bundles.Select(ToProjectMapScriptBundleDto).ToList());
            return 0;
        }

        foreach (KarProjectMapScriptBundle bundle in bundles)
            PrintProjectMapScriptBundle(bundle);

        return 0;
    }

    public static int ShowMapContext(KarCliOptions options)
    {
        options.RequirePositionals("map-context", 1);
        KarProject project = OpenProject(options);
        List<KarProjectMapContext> contexts = project.MapContextService.Query(CreateMapScriptQuery(options))
            .ToList();

        if (options.Json)
        {
            WriteJson(contexts.Select(ToProjectMapContextDto).ToList());
            return 0;
        }

        foreach (KarProjectMapContext context in contexts)
            PrintProjectMapContext(context);

        return 0;
    }

    public static int ShowVehicleContext(KarCliOptions options)
    {
        options.RequirePositionals("vehicle-context", 1);
        KarProject project = OpenProject(options);
        List<KarProjectVehicleContext> contexts = project.VehicleService.QueryContexts(CreateVehicleQuery(options))
            .ToList();

        if (options.Json)
        {
            WriteJson(contexts.Select(ToProjectVehicleContextDto).ToList());
            return 0;
        }

        foreach (KarProjectVehicleContext context in contexts)
            PrintProjectVehicleContext(context);

        return 0;
    }

    public static int ShowArchive(KarCliOptions options)
    {
        options.RequirePositionals("archive", 2);
        KarProject project = OpenProject(options);
        KarArchiveInfo archive = project.ArchiveService.InspectHsdArchive(options.Positionals[1]);

        if (options.Json)
        {
            WriteJson(ToArchiveDto(archive));
            return 0;
        }

        PrintArchive(archive, "");
        return 0;
    }

    public static int ShowA2D(KarCliOptions options)
    {
        options.RequirePositionals("a2d", 2);
        KarProject project = OpenProject(options);
        A2DPackage package = project.ArchiveService.OpenA2DPackage(options.Positionals[1]);

        if (options.Json)
        {
            WriteJson(new
            {
                path = options.Positionals[1],
                entryCount = package.Entries.Count,
                entries = package.Entries.Select(ToA2DEntryDto).ToList(),
            });
            return 0;
        }

        Console.WriteLine("A2D: " + options.Positionals[1]);
        Console.WriteLine("Entries: " + package.Entries.Count);
        foreach (A2DPackageEntry entry in package.Entries)
            Console.WriteLine("  [" + entry.Index + "] " + entry.Name + " offset=0x" + entry.DataOffset.ToString("X") + " size=0x" + entry.Size.ToString("X"));

        return 0;
    }

    public static int ValidateProject(KarCliOptions options)
    {
        options.RequirePositionals("validate", 1);
        KarProject project = OpenProject(options);
        KarValidationReport report = project.Validator.Validate(new KarValidationOptions
        {
            InspectHsdArchives = !options.NoHsdArchives,
            InspectA2DPackages = !options.NoA2DPackages,
            ReportUnknownRoots = !options.NoUnknownRoots,
            ReportMissingMapModels = !options.NoMissingMapModels,
            ValidateDataDefinitions = !options.NoSchemaValidation,
        });

        if (options.Json)
        {
            WriteJson(ToValidationReportDto(report));
            return report.IsValid ? 0 : 2;
        }

        Console.WriteLine("Project: " + project.Name);
        Console.WriteLine("Files: " + report.FileCount);
        Console.WriteLine("Maps: " + report.MapCount);
        Console.WriteLine("HSD archives checked: " + report.HsdArchiveCount);
        Console.WriteLine("A2D packages checked: " + report.A2DPackageCount);
        if (report.HasDataDefinitionValidation)
        {
            Console.WriteLine("Schemas checked: " + report.DataDefinitionValidation.DefinitionCount);
            Console.WriteLine("Schema errors: " + report.DataDefinitionValidation.ErrorCount);
            Console.WriteLine("Schema warnings: " + report.DataDefinitionValidation.WarningCount);
            Console.WriteLine("Schema info: " + report.DataDefinitionValidation.InfoCount);
        }

        Console.WriteLine("Errors: " + report.ErrorCount);
        Console.WriteLine("Warnings: " + report.WarningCount);
        Console.WriteLine("Info: " + report.InfoCount);

        if (report.HasDataDefinitionValidation)
        {
            foreach (KarDataDefinitionValidationIssue issue in report.DataDefinitionValidation.Issues)
                PrintDataDefinitionValidationIssue(issue);
        }

        foreach (KarValidationIssue issue in report.Issues)
            PrintValidationIssue(issue);

        return report.IsValid ? 0 : 2;
    }

    public static int ValidateSchemas(KarCliOptions options)
    {
        options.RequirePositionals("validate-schemas", 0);
        KarDataDefinitionValidationReport report = KarDataDefinitionValidator.ValidateBuiltIn();

        if (options.Json)
        {
            WriteJson(ToDataDefinitionValidationReportDto(report));
            return report.IsValid ? 0 : 2;
        }

        Console.WriteLine("Schemas: " + report.DefinitionCount);
        Console.WriteLine("Errors: " + report.ErrorCount);
        Console.WriteLine("Warnings: " + report.WarningCount);
        Console.WriteLine("Info: " + report.InfoCount);

        foreach (KarDataDefinitionValidationIssue issue in report.Issues)
            PrintDataDefinitionValidationIssue(issue);

        return report.IsValid ? 0 : 2;
    }

    public static int ShowDefinitions(KarCliOptions options)
    {
        options.RequirePositionals("definitions", 0);
        List<KarDataDefinition> definitions = KarDataDefinitionCatalog.All
            .OrderBy(definition => definition.Category)
            .ThenBy(definition => definition.DisplayName)
            .ToList();

        if (options.Json)
        {
            WriteJson(definitions.Select(ToDataDefinitionDto).ToList());
            return 0;
        }

        foreach (KarDataDefinition definition in definitions)
            Console.WriteLine(definition.Id + " (" + definition.Category + "): " + definition.DisplayName + " - " + definition.Fields.Count + " field(s)");

        return 0;
    }

    public static int ShowDefinition(KarCliOptions options)
    {
        options.RequirePositionals("definition", 1);
        KarDataDefinition definition;
        if (!KarDataDefinitionCatalog.TryFind(options.Positionals[0], out definition))
            throw new KeyNotFoundException("KAR data definition was not found: " + options.Positionals[0]);

        if (options.Json)
        {
            WriteJson(ToDataDefinitionDto(definition));
            return 0;
        }

        PrintDataDefinition(definition, "");
        return 0;
    }
}
