using System.Collections.Generic;
using KARToolkit.Core;

namespace KARToolkit.Cli;

internal static class KarCliTextWriter
{
    public static void PrintArchiveSlot(string label, KarArchiveInfo archive)
    {
        Console.WriteLine(label + ":");
        if (archive == null)
        {
            Console.WriteLine("  <missing>");
            return;
        }

        PrintArchive(archive, "  ");
    }

    public static void PrintProjectFileSummary(KarProjectFile file)
    {
        string output = file.HasOutputCopy ? " output-copy" : "";
        Console.WriteLine(file.RelativePath + " [" + file.Kind + ", " + file.Category + "]" + output + " - " + file.DisplayName);
    }

    public static void PrintProjectFileHandler(KarProjectFileHandler handler)
    {
        string traits = FormatFileKindTraits(handler.Descriptor);
        string capabilities = string.Join(",", handler.CapabilityList);
        Console.WriteLine(handler.Id + " [" + handler.Kind + ", " + handler.Category + "] " + traits + " capabilities=" + capabilities + " - " + handler.DisplayName);
    }

    public static void PrintProjectFile(KarProjectFile file)
    {
        Console.WriteLine("File: " + file.RelativePath);
        Console.WriteLine("Kind: " + file.Kind);
        Console.WriteLine("Kind id: " + file.KindId);
        Console.WriteLine("Kind traits: " + FormatFileKindTraits(file.KindDescriptor));
        Console.WriteLine("Capabilities: " + string.Join(",", file.Handler.CapabilityList));
        if (file.HasMapName)
            Console.WriteLine("Map: " + file.MapName + " (" + file.MapBundleRole + ")");
        Console.WriteLine("Category: " + file.Category);
        Console.WriteLine("Display: " + file.DisplayName);
        if (!string.IsNullOrEmpty(file.ArchiveDefinition.Description))
            Console.WriteLine("Description: " + file.ArchiveDefinition.Description);
        Console.WriteLine("Source: " + file.SourcePath);
        Console.WriteLine("Output: " + file.OutputPath);
        Console.WriteLine("Read: " + file.ReadPath);
        Console.WriteLine("Has output copy: " + file.HasOutputCopy);
        Console.WriteLine("Known root definitions: " + file.ArchiveDefinition.Roots.Count);
    }

    private static string FormatFileKindTraits(KarFileKindDescriptor descriptor)
    {
        List<string> traits = new List<string>();
        if (descriptor.IsHsdArchive)
            traits.Add("hsd");
        if (descriptor.IsA2DPackage)
            traits.Add("a2d");
        if (descriptor.IsScriptTable)
            traits.Add("script-table");
        if (descriptor.IsMedia)
            traits.Add("media");
        if (descriptor.IsConfig)
            traits.Add("config");
        if (descriptor.IsMapBundlePart)
            traits.Add("map-" + descriptor.MapBundleRole);

        return traits.Count == 0 ? "plain" : string.Join(",", traits);
    }

    public static void PrintProjectResourceSummary(KarProjectResourceInfo resource)
    {
        string role = string.IsNullOrEmpty(resource.Role) ? "" : ", " + resource.Role;
        Console.WriteLine(resource.Address + " [" + resource.Kind + ", " + resource.Category + role + "] - " + resource.DisplayName);
    }

    public static void PrintProjectResource(KarProjectResourceInfo resource)
    {
        Console.WriteLine("Resource: " + resource.Address);
        Console.WriteLine("Kind: " + resource.Kind);
        Console.WriteLine("Category: " + resource.Category);
        Console.WriteLine("Role: " + resource.Role);
        Console.WriteLine("Display: " + resource.DisplayName);
        if (!string.IsNullOrEmpty(resource.Description))
            Console.WriteLine("Description: " + resource.Description);
        if (!string.IsNullOrEmpty(resource.ParentAddress))
            Console.WriteLine("Parent: " + resource.ParentAddress);

        if (resource.File != null)
        {
            Console.WriteLine("File: " + resource.File.RelativePath);
            Console.WriteLine("Read: " + resource.File.ReadPath);
            Console.WriteLine("Has output copy: " + resource.File.HasOutputCopy);
        }

        if (resource.Root != null)
        {
            Console.WriteLine("Root: " + resource.Root.RootName);
            Console.WriteLine("Accessor: " + resource.Root.DisplayAccessorTypeName);
            Console.WriteLine("Schema: " + (resource.Root.DataDefinitionId ?? "<none>"));
        }

        if (resource.A2DEntry != null)
        {
            Console.WriteLine("A2D entry: " + resource.A2DEntry.Name);
            Console.WriteLine("Index: " + resource.A2DEntry.Index);
            Console.WriteLine("Offset: " + resource.A2DEntry.DataOffsetHex);
            Console.WriteLine("Size: " + resource.A2DEntry.SizeHex);
        }
    }

    public static void PrintProjectResourceGraph(KarProjectResourceGraph graph)
    {
        Console.WriteLine("Resource graph: resources=" + graph.ResourceCount + " files=" + graph.FileCount + " roots=" + graph.HsdRootCount + " a2d-entries=" + graph.A2DEntryCount + " relationships=" + graph.RelationshipCount);

        Console.WriteLine("Resources:");
        foreach (KarProjectResourceInfo resource in graph.Resources)
            Console.WriteLine("  " + resource.Address + " [" + resource.Kind + ", " + resource.Category + "] " + resource.DisplayName);

        Console.WriteLine("Relationships:");
        foreach (KarProjectRelationship relationship in graph.Relationships)
        {
            string map = relationship.MapName == null ? "project" : relationship.MapName;
            string package = relationship.PackageFile == null ? "" : " package=" + relationship.PackageFile.RelativePath;
            string entry = relationship.PackageEntryName == null ? "" : " entry=" + relationship.PackageEntryName;
            string size = relationship.PackageEntrySizeHex == null ? "" : " size=" + relationship.PackageEntrySizeHex;
            Console.WriteLine("  " + map + ": " + relationship.Kind + "/" + relationship.Role + " " + relationship.RelativePath + package + entry + size);
        }
    }

    public static void PrintProjectResourceOutput(KarProjectResourceOutputInfo output)
    {
        Console.WriteLine(output.Address + " [" + output.Status + ", " + output.OutputKind + "] " + output.OutputRelativePath);
    }

    public static void PrintProjectResourceFieldValue(KarProjectResourceFieldInfo field)
    {
        string offset = field.Field.OffsetHex ?? "n/a";
        string schema = string.IsNullOrEmpty(field.DataDefinitionId) ? "<unschematized>" : field.DataDefinitionId;
        string error = string.IsNullOrEmpty(field.Value.Error) ? "" : " (" + field.Value.Error + ")";
        Console.WriteLine(field.Address + " " + schema + "." + field.FieldName + " " + offset + " = " + field.Value.DisplayValue + error);
    }

    public static void PrintProjectScriptTable(KarProjectScriptTable table)
    {
        string storage = table.IsPackageEntry ? "a2d-entry" : "file";
        string details = table.IsPackageEntry
            ? " index=" + table.PackageEntryIndex + " offset=" + table.PackageEntryOffsetHex + " size=" + table.PackageEntrySizeHex
            : "";
        Console.WriteLine(table.Address + " [" + table.Role + ", " + storage + "]" + details + " - " + table.Description);
    }

    public static void PrintProjectMapScriptBundle(KarProjectMapScriptBundle bundle)
    {
        Console.WriteLine("Map scripts: " + bundle.MapName);
        Console.WriteLine("  Map resources: " + bundle.MapResourceCount + " relationships=" + bundle.RelationshipCount);
        PrintProjectMapScriptResourceSlot("Data", bundle.DataResource);
        PrintProjectMapScriptResourceSlot("Model", bundle.ModelResource);
        PrintProjectMapScriptResourceSlot("Script", bundle.ScriptArchiveResource);
        Console.WriteLine("  Script tables: " + bundle.ScriptTableCount);
        foreach (KarProjectScriptTable table in bundle.ScriptTables)
            Console.WriteLine("    " + table.Address + " [" + table.Role + "]");
    }

    private static void PrintProjectMapScriptResourceSlot(string label, KarProjectResourceInfo resource)
    {
        if (resource == null)
        {
            Console.WriteLine("  " + label + ": <missing>");
            return;
        }

        Console.WriteLine("  " + label + ": " + resource.Address + " [" + resource.Role + "]");
    }

    public static void PrintProjectResourceOutputApplyResult(KarProjectResourceOutputApplyResult result)
    {
        Console.WriteLine("Applied resource output: " + result.Address);
        Console.WriteLine("Sidecar: " + result.SidecarOutputPath);
        Console.WriteLine("Package output: " + result.PackageOutputPath);
        Console.WriteLine("Replacement length: " + result.ReplacementLength);
    }

    public static void PrintProjectResourceExportResult(KarProjectResourceExportResult result)
    {
        Console.WriteLine("Exported resource: " + result.Address);
        Console.WriteLine("Output kind: " + result.OutputKind);
        Console.WriteLine("Output relative path: " + result.OutputRelativePath);
        Console.WriteLine("Output: " + result.OutputPath);
        Console.WriteLine("Wrote: " + result.WroteOutput);
    }

    public static void PrintProjectResourceImportResult(KarProjectResourceImportResult result)
    {
        Console.WriteLine("Imported resource: " + result.Address);
        Console.WriteLine("Input: " + result.InputPath);
        Console.WriteLine("Input length: " + result.InputLength);
        Console.WriteLine("Output kind: " + result.OutputKind);
        Console.WriteLine("Output relative path: " + result.OutputRelativePath);
        Console.WriteLine("Output: " + result.OutputPath);
    }

    public static void PrintProjectReport(KarProjectReport report)
    {
        Console.WriteLine("Project: " + report.Project.Name);
        Console.WriteLine("Source: " + report.Project.SourceRoot);
        Console.WriteLine("Output: " + report.Project.OutputRoot);
        Console.WriteLine("Files: " + report.FileCount);
        Console.WriteLine("Output files: " + report.OutputFileCount + " project=" + report.ProjectOutputFileCount + " modified=" + report.ModifiedProjectOutputFileCount + " unchanged=" + report.UnchangedProjectOutputFileCount + " orphan=" + report.OrphanOutputFileCount);
        Console.WriteLine("Map outputs: " + report.MapOutputCount + " modified=" + report.ModifiedMapOutputCount + " complete=" + report.CompleteMapOutputCount);
        Console.WriteLine("Maps: " + report.MapCount + " complete=" + report.CompleteMapCount + " incomplete=" + report.IncompleteMapCount);
        Console.WriteLine("HSD archives: " + report.HsdArchiveCount);
        Console.WriteLine("A2D packages: " + report.A2DPackageCount);
        Console.WriteLine("Roots: " + report.RootCount + " known=" + report.KnownRootCount + " unknown=" + report.UnknownRootCount + " missing-required=" + report.MissingRequiredRootCount);
        Console.WriteLine("Schemas used: " + report.DataDefinitionUsageCount);

        Console.WriteLine("Files by category:");
        foreach (KarProjectFileGroupSummary group in report.FileCategories)
            Console.WriteLine("  " + group.Name + ": " + group.Count);

        Console.WriteLine("Files by kind:");
        foreach (KarProjectFileGroupSummary group in report.FileKinds)
            Console.WriteLine("  " + group.Name + ": " + group.Count);

        if (report.DataDefinitionUsage.Count != 0)
        {
            Console.WriteLine("Schema usage:");
            foreach (KarProjectDataDefinitionUsage usage in report.DataDefinitionUsage)
                Console.WriteLine("  " + usage.DataDefinitionId + ": roots=" + usage.Count + " files=" + usage.FileCount + " - " + usage.DisplayName);
        }

        if (report.HasFieldSummaries)
        {
            Console.WriteLine("Field summaries:");
            foreach (KarProjectFieldSummary summary in report.FieldSummaries)
                PrintProjectFieldSummary(summary);
        }
    }

    public static void PrintProjectModWorkspace(KarProjectModWorkspace workspace)
    {
        Console.WriteLine("Mod workspace: " + workspace.Project.OutputRoot);
        Console.WriteLine("Output files: " + workspace.OutputFileCount + " project=" + workspace.ProjectOutputFileCount + " modified=" + workspace.ModifiedProjectOutputFileCount + " unchanged=" + workspace.UnchangedProjectOutputFileCount + " orphan=" + workspace.OrphanOutputFileCount);
        Console.WriteLine("Resource outputs: " + workspace.ResourceOutputCount + " project-file=" + workspace.ProjectFileResourceOutputCount + " assets=" + workspace.OutputAssetResourceOutputCount + " modified=" + workspace.ModifiedResourceOutputCount + " unchanged=" + workspace.UnchangedResourceOutputCount);
        Console.WriteLine("A2D sidecars: " + workspace.A2DEntryOutputCount + " modified=" + workspace.ModifiedA2DEntryOutputCount + " matching=" + workspace.MatchingA2DEntryOutputCount);
        Console.WriteLine("Map outputs: " + workspace.MapOutputCount + " modified=" + workspace.ModifiedMapOutputCount + " complete=" + workspace.CompleteMapOutputCount);

        if (workspace.ModifiedResourceOutputs.Count != 0)
        {
            Console.WriteLine("Modified resources:");
            foreach (KarProjectResourceOutputInfo output in workspace.ModifiedResourceOutputs)
                Console.WriteLine("  " + output.Address + " [" + output.Status + "] " + output.OutputRelativePath);
        }
    }

    public static void PrintProjectOutputFile(KarProjectOutputFileInfo file)
    {
        string status = file.Status.ToString();
        string length = file.HasSourceFile && file.IsSameLengthAsSource.HasValue
            ? " size=" + file.OutputLength + "/" + file.SourceLength.Value
            : " size=" + file.OutputLength;
        Console.WriteLine(file.RelativePath + " [" + file.Kind + ", " + file.Category + ", " + status + "]" + length + " -> " + file.OutputPath);
    }

    public static void PrintProjectMapOutput(KarProjectMapOutputInfo map)
    {
        Console.WriteLine(map.Name + ": outputs=" + map.OutputFileCount + "/" + map.ExpectedOutputFileCount + " modified=" + map.ModifiedOutputFileCount + " unchanged=" + map.UnchangedOutputFileCount + " missing=" + map.MissingOutputFileCount);
        PrintProjectMapOutputSlot("Data", map.DataFile, map.DataOutput);
        PrintProjectMapOutputSlot("Model", map.ModelFile, map.ModelOutput);
        PrintProjectMapOutputSlot("Event/Script", map.EventFile, map.EventOutput);
    }

    private static void PrintProjectMapOutputSlot(string label, KarProjectFile file, KarProjectOutputFileInfo output)
    {
        if (file == null)
        {
            Console.WriteLine("  " + label + ": <missing source file>");
            return;
        }

        if (output == null)
        {
            Console.WriteLine("  " + label + ": " + file.RelativePath + " <no output>");
            return;
        }

        Console.WriteLine("  " + label + ": " + output.RelativePath + " [" + output.Status + "] -> " + output.OutputPath);
    }

    public static void PrintProjectRootSummary(KarProjectRootInfo root)
    {
        string known = root.IsKnown ? "known" : "unknown";
        string type = string.IsNullOrEmpty(root.DisplayAccessorTypeName) ? "<untyped>" : root.DisplayAccessorTypeName;
        string schema = string.IsNullOrEmpty(root.DataDefinitionId) ? "" : ", " + root.DataDefinitionId;
        Console.WriteLine(root.RelativePath + ":" + root.RootName + " [" + known + ", " + type + schema + "]");
    }

    public static void PrintProjectRootSummaryGroup(KarProjectRootSummary summary)
    {
        string known = summary.IsKnown ? "known" : "unknown";
        string type = string.IsNullOrEmpty(summary.DisplayAccessorTypeName) ? "<untyped>" : summary.DisplayAccessorTypeName;
        string schema = string.IsNullOrEmpty(summary.DataDefinitionId) ? "" : ", " + summary.DataDefinitionId;
        Console.WriteLine(summary.RootName + " [" + known + ", " + type + schema + "] x" + summary.Count);
        foreach (KarProjectRootInfo root in summary.Roots)
            Console.WriteLine("  " + root.RelativePath);
    }

    public static void PrintArchiveInventory(KarArchiveInfo archive)
    {
        Console.WriteLine(
            archive.File.RelativePath +
            " [" + archive.File.Kind + ", " + archive.File.Category + "] roots=" + archive.Roots.Count +
            " known=" + archive.KnownRoots.Count +
            " unknown=" + archive.UnknownRoots.Count +
            " missing=" + archive.MissingRequiredRoots.Count);

        foreach (KarRootDefinition missing in archive.MissingRequiredRoots)
            Console.WriteLine("  missing " + missing.Pattern);
    }

    public static void PrintDataDefinitionUsage(KarProjectDataDefinitionUsage usage)
    {
        string accessor = string.IsNullOrEmpty(usage.AccessorTypeName) ? "<untyped>" : usage.AccessorTypeName;
        Console.WriteLine(usage.DataDefinitionId + " [" + usage.Category + ", " + accessor + "] roots=" + usage.Count + " files=" + usage.FileCount + " - " + usage.DisplayName);
        foreach (KarProjectRootInfo root in usage.Roots)
            Console.WriteLine("  " + root.RelativePath + ":" + root.RootName);
    }

    public static void PrintProjectFieldValue(KarProjectFieldInfo field)
    {
        string offset = field.Field.OffsetHex ?? "n/a";
        string schema = string.IsNullOrEmpty(field.DataDefinitionId) ? "<unschematized>" : field.DataDefinitionId;
        string error = string.IsNullOrEmpty(field.Value.Error) ? "" : " (" + field.Value.Error + ")";
        Console.WriteLine(field.RelativePath + ":" + field.RootName + " " + schema + "." + field.FieldName + " " + offset + " = " + field.Value.DisplayValue + error);

        if (field.Value.ReferenceDataDefinition != null)
            Console.WriteLine("  ref schema: " + field.Value.ReferenceDataDefinition.Id + " (" + field.Value.ReferenceDataDefinition.DisplayName + ")");
        if (field.Value.HasReferenceEntries)
        {
            string total = field.Value.ReferenceEntryTotalCount.HasValue
                ? "/" + field.Value.ReferenceEntryTotalCount.Value
                : "";
            Console.WriteLine("  ref entries: " + field.Value.ReferenceEntryCount + total);
        }
    }

    public static void PrintProjectFieldSummary(KarProjectFieldSummary summary)
    {
        string offset = summary.Field.OffsetHex ?? "n/a";
        string variation = summary.HasValueVariation ? " varied" : "";
        Console.WriteLine(
            summary.DataDefinitionId + "." + summary.FieldName +
            " " + offset + " " + summary.TypeName +
            " roots=" + summary.Count +
            " files=" + summary.FileCount +
            " values=" + summary.DistinctValueCount +
            " available=" + summary.AvailableCount + "/" + summary.Count +
            variation);

        foreach (KarProjectFieldDistinctValue value in summary.DistinctValues)
        {
            string error = string.IsNullOrEmpty(value.Error) ? "" : " (" + value.Error + ")";
            Console.WriteLine("  " + value.DisplayValue + " x" + value.Count + error);
        }
    }

    public static void PrintArchive(KarArchiveInfo archive, string indent)
    {
        Console.WriteLine(indent + archive.File.RelativePath + " (" + archive.Definition.DisplayName + ")");
        Console.WriteLine(indent + "Known roots: " + archive.KnownRoots.Count + "/" + archive.Roots.Count);

        foreach (KarArchiveRootInfo root in archive.Roots)
        {
            string known = root.IsKnown ? "known" : "unknown";
            string type = string.IsNullOrEmpty(root.DisplayAccessorTypeName) ? "<untyped>" : root.DisplayAccessorTypeName;
            string description = root.Definition == null || string.IsNullOrEmpty(root.Definition.Description)
                ? ""
                : " - " + root.Definition.Description;

            Console.WriteLine(indent + "  " + root.Name + " [" + known + ", " + type + "]" + description);

            if (root.DataDefinition != null)
                PrintDataDefinition(root.DataDefinition, indent + "    ");

            if (root.HasFieldValues)
                PrintFieldValues(root.FieldValues, indent + "    ");
        }

        if (archive.HasMissingRequiredRoots)
        {
            Console.WriteLine(indent + "Missing required roots:");
            foreach (KarRootDefinition root in archive.MissingRequiredRoots)
                Console.WriteLine(indent + "  " + root.Pattern);
        }
    }

    public static void PrintValidationIssue(KarValidationIssue issue)
    {
        string location = "";
        if (!string.IsNullOrEmpty(issue.RelativePath))
            location = " " + issue.RelativePath;
        else if (!string.IsNullOrEmpty(issue.MapName))
            location = " map:" + issue.MapName;

        Console.WriteLine(issue.Severity + " " + issue.Code + location + " - " + issue.Message);
    }

    public static void PrintDataDefinitionValidationIssue(KarDataDefinitionValidationIssue issue)
    {
        string location = "";
        if (!string.IsNullOrEmpty(issue.DefinitionId))
            location = " " + issue.DefinitionId;
        if (!string.IsNullOrEmpty(issue.FieldName))
            location += "." + issue.FieldName;

        Console.WriteLine(issue.Severity + " " + issue.Code + location + " - " + issue.Message);
    }

    public static void PrintDataDefinition(KarDataDefinition definition, string indent)
    {
        Console.WriteLine(indent + "schema: " + definition.Id + " (" + definition.DisplayName + ")");
        if (definition.Size.HasValue)
            Console.WriteLine(indent + "  size: " + definition.SizeHex);
        if (!string.IsNullOrEmpty(definition.Description))
            Console.WriteLine(indent + "  " + definition.Description);

        foreach (KarDataFieldDefinition field in definition.Fields)
        {
            string offset = field.OffsetHex ?? "n/a";
            string pointer = field.IsPointer ? " ptr" : "";
            string description = string.IsNullOrEmpty(field.Description) ? "" : " - " + field.Description;
            Console.WriteLine(indent + "  " + offset + " " + field.Name + ": " + field.TypeName + pointer + description);
        }
    }

    private static void PrintFieldValues(IReadOnlyList<KarDataFieldValue> values, string indent)
    {
        Console.WriteLine(indent + "values:");
        foreach (KarDataFieldValue value in values)
        {
            string offset = value.Field.OffsetHex ?? "n/a";
            string error = string.IsNullOrEmpty(value.Error) ? "" : " (" + value.Error + ")";
            Console.WriteLine(indent + "  " + offset + " " + value.Field.Name + " = " + value.DisplayValue + error);

            if (value.ReferenceDataDefinition != null)
                Console.WriteLine(indent + "    ref schema: " + value.ReferenceDataDefinition.Id + " (" + value.ReferenceDataDefinition.DisplayName + ")");
            if (value.HasReferenceFieldValues)
                PrintFieldValues(value.ReferenceFieldValues, indent + "    ");
            if (value.HasReferenceEntries)
            {
                string total = value.ReferenceEntryTotalCount.HasValue
                    ? "/" + value.ReferenceEntryTotalCount.Value
                    : "";
                Console.WriteLine(indent + "    ref entries: " + value.ReferenceEntryCount + total);
                foreach (KarDataReferenceEntry entry in value.ReferenceEntries)
                {
                    Console.WriteLine(indent + "      [" + entry.Index + "] offset=" + entry.OffsetHex);
                    if (entry.HasFieldValues)
                        PrintFieldValues(entry.FieldValues, indent + "        ");
                }
            }
        }
    }
}
