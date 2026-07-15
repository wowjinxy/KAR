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

    public static void PrintProjectResourceHandler(KarProjectResourceHandler handler)
    {
        string capabilities = string.Join(",", handler.CapabilityList);
        string actions = string.Join(",", handler.Actions.Select(action => action.Id));
        Console.WriteLine(handler.Id + " [" + handler.Kind + "] capabilities=" + capabilities + " actions=" + actions + " - " + handler.DisplayName);
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

    public static void PrintProjectSession(KarProjectSession session)
    {
        Console.WriteLine("KAR project session: " + session.Name);
        Console.WriteLine("Source: " + session.SourceRoot);
        Console.WriteLine("Source files: " + session.SourceFilesRoot);
        Console.WriteLine("Output: " + session.OutputRoot);
        Console.WriteLine("Output files: " + session.OutputFilesRoot);
        Console.WriteLine("Read policy: " + session.ReadPolicy);
        Console.WriteLine("Write policy: " + session.WritePolicy);
        Console.WriteLine("Workspace safe: source/output=" + session.SourceAndOutputRootsAreSeparate + " files=" + session.SourceFilesAndOutputFilesRootsAreSeparate);
        Console.WriteLine("Project: files=" + session.FileCount + " maps=" + session.MapCount);
        Console.WriteLine("Registries: file-kinds=" + session.FileKindCount + " file-handlers=" + session.FileHandlerCount + " resource-handlers=" + session.ResourceHandlerCount + " actions=" + session.ResourceActionDefinitionCount + " domains=" + session.OperationDomainRuleCount + " presets=" + session.OperationPresetDefinitionCount);
        Console.WriteLine("Toolkit: domains=" + session.DomainCount + " workflows=" + session.WorkflowCount + " available=" + session.AvailableWorkflowCount + " output=" + session.OutputWorkflowCount);
        Console.WriteLine("Mod outputs: present=" + session.HasOutputs + " modified=" + session.HasModifiedOutputs);
    }

    public static void PrintProjectToolkitRegistryCatalog(KarProjectToolkitRegistryCatalog catalog)
    {
        string scope = catalog.HasProject ? catalog.ProjectName : "default";
        Console.WriteLine("KAR toolkit registries: " + scope);
        Console.WriteLine("Registries: " + catalog.RegistryCount + " file-kinds=" + catalog.FileKindCount + " file-handlers=" + catalog.FileHandlerCount + " resource-handlers=" + catalog.ResourceHandlerCount + " actions=" + catalog.ResourceActionDefinitionCount + " domains=" + catalog.OperationDomainRuleCount + " presets=" + catalog.OperationPresetDefinitionCount);

        Console.WriteLine("File kinds:");
        foreach (KarFileKindDescriptor descriptor in catalog.FileKinds)
            Console.WriteLine("  " + descriptor.Id + " [" + descriptor.Kind + ", " + descriptor.Category + "] " + FormatFileKindTraits(descriptor) + " - " + descriptor.DisplayName);

        Console.WriteLine("File handlers:");
        foreach (KarProjectFileHandler handler in catalog.FileHandlers)
            PrintProjectFileHandler(handler);

        Console.WriteLine("Resource handlers:");
        foreach (KarProjectResourceHandler handler in catalog.ResourceHandlers)
            PrintProjectResourceHandler(handler);

        Console.WriteLine("Resource action definitions:");
        foreach (KarProjectResourceActionDefinition definition in catalog.ResourceActionDefinitions)
            PrintProjectResourceActionDefinition(definition);

        Console.WriteLine("Operation domain rules:");
        foreach (KarProjectOperationDomainRule rule in catalog.OperationDomainRules)
            PrintProjectOperationDomainRule(rule);

        Console.WriteLine("Operation preset definitions:");
        foreach (KarProjectOperationPresetDefinition definition in catalog.OperationPresetDefinitions)
            PrintProjectOperationPresetDefinition(definition);
    }

    public static void PrintProjectModManifest(KarProjectModManifest manifest)
    {
        Console.WriteLine("Mod manifest: " + manifest.Name);
        Console.WriteLine("Output: " + manifest.OutputRoot);
        Console.WriteLine("Policy: " + manifest.WritePolicy);
        Console.WriteLine("Artifacts: " + manifest.ArtifactCount + " project-files=" + manifest.ProjectFileArtifactCount + " sidecars=" + manifest.A2DEntrySidecarArtifactCount + " resource-bytes=" + manifest.ResourceByteDumpArtifactCount + " modified=" + manifest.ModifiedArtifactCount + " needs-apply=" + manifest.NeedsApplyArtifactCount);

        foreach (KarProjectModManifestArtifact artifact in manifest.Artifacts)
            PrintProjectModManifestArtifact(artifact);
    }

    public static void PrintProjectModManifestArtifact(KarProjectModManifestArtifact artifact)
    {
        string resource = string.IsNullOrEmpty(artifact.ResourceAddress) ? "" : " resource=" + artifact.ResourceAddress;
        string projectPath = string.IsNullOrEmpty(artifact.ProjectRelativePath) ? "" : " project=" + artifact.ProjectRelativePath;
        string flags = "";
        if (artifact.IsModified)
            flags += " modified";
        if (artifact.IsOutputOnly)
            flags += " output-only";
        if (artifact.IsSidecar)
            flags += " sidecar";
        if (artifact.NeedsApply)
            flags += " needs-apply";

        Console.WriteLine("  " + artifact.OutputRelativePath + " [" + artifact.Kind + ", " + artifact.Status + "] size=" + artifact.OutputLength + resource + projectPath + flags);
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
        Console.WriteLine("Actions: " + string.Join(",", resource.Actions.Select(action => action.Id)));

        if (resource.File != null)
        {
            Console.WriteLine("File: " + resource.File.RelativePath);
            Console.WriteLine("Read: " + resource.File.ReadPath);
            Console.WriteLine("Has output copy: " + resource.File.HasOutputCopy);
        }

        if (resource.Root != null)
        {
            Console.WriteLine("Root: " + resource.Root.RootName);
            Console.WriteLine("Root role: " + resource.Root.Role);
            Console.WriteLine("Accessor: " + resource.Root.DisplayAccessorTypeName);
            string schema = resource.Root.DataDefinitionId ?? "<none>";
            if (!string.IsNullOrEmpty(resource.Root.SchemaDisplayName))
                schema += " (" + resource.Root.SchemaDisplayName + ")";
            Console.WriteLine("Schema: " + schema);
        }

        if (resource.A2DEntry != null)
        {
            Console.WriteLine("A2D entry: " + resource.A2DEntry.Name);
            Console.WriteLine("Index: " + resource.A2DEntry.Index);
            Console.WriteLine("Offset: " + resource.A2DEntry.DataOffsetHex);
            Console.WriteLine("Size: " + resource.A2DEntry.SizeHex);
        }
    }

    public static void PrintProjectResourceActions(KarProjectResourceInfo resource)
    {
        Console.WriteLine(resource.Address + " [" + resource.Kind + ", " + resource.Category + "] actions=" + resource.ActionCount);
        foreach (KarProjectResourceAction action in resource.Actions)
        {
            string mode = action.IsReadOnly ? "read" : "write";
            string batch = action.SupportsBatch ? " batch" : "";
            string input = action.RequiresInputFile ? " input-file" : "";
            string field = action.RequiresFieldName ? " field" : "";
            string value = action.RequiresValue ? " value" : "";
            Console.WriteLine("  " + action.Id + " command=" + action.Command + " " + mode + batch + input + field + value + " " + action.ArgumentHint);
        }
    }

    public static void PrintProjectResourceActionDefinition(KarProjectResourceActionDefinition definition)
    {
        string mode = definition.IsReadOnly ? "read" : "write";
        string planning = " execution=" + definition.ExecutionKindName + " state=" + definition.PlanStateKindName + " write-policy=" + definition.WritePolicyName;
        Console.WriteLine(definition.Id + " [" + definition.CapabilityName + ", " + mode + "] command=" + definition.Command + planning);
        if (!string.IsNullOrEmpty(definition.Description))
            Console.WriteLine("  " + definition.Description);
    }

    public static void PrintProjectOperationDomainRule(KarProjectOperationDomainRule rule)
    {
        Console.WriteLine(rule.Id + " - " + rule.DisplayName);
        if (!string.IsNullOrEmpty(rule.Description))
            Console.WriteLine("  " + rule.Description);
    }

    public static void PrintProjectOperationPresetDefinition(KarProjectOperationPresetDefinition definition)
    {
        string mode = definition.IsReadOnly ? "read" : "write";
        string resourceKind = definition.ResourceKind == null ? "" : " resource-kind=" + definition.ResourceKind;
        Console.WriteLine(definition.Id + " [" + definition.DomainId + ", " + mode + "] action=" + definition.ActionId + resourceKind);
        if (!string.IsNullOrEmpty(definition.Description))
            Console.WriteLine("  " + definition.Description);
    }

    public static void PrintProjectResourceActionPlan(KarProjectResourceActionPlan plan)
    {
        string output = plan.OutputRelativePath == null ? "" : " output=" + plan.OutputRelativePath;
        string outputStatus = plan.OutputStatus == null ? "" : " status=" + plan.OutputStatus;
        string byteStatus = plan.ByteStatus == null ? "" : " bytes=" + plan.ByteStatus;
        string reason = string.IsNullOrEmpty(plan.Reason) ? "" : " reason=\"" + plan.Reason + "\"";
        Console.WriteLine(plan.Address + " " + plan.ActionId + " can-run=" + plan.CanRun + " would-write=" + plan.WouldWriteOutput + output + outputStatus + byteStatus + reason);
    }

    public static void PrintProjectResolvedResource(KarProjectResolvedResource resolved)
    {
        Console.WriteLine("Resolved: " + resolved.Address);
        PrintProjectResource(resolved.Resource);

        if (resolved.ScriptTable != null)
        {
            Console.WriteLine("Script table: yes");
            Console.WriteLine("Script name: " + resolved.ScriptTable.Name);
            Console.WriteLine("Script role: " + resolved.ScriptTable.Role);
            Console.WriteLine("Script category: " + resolved.ScriptTable.Category);
            Console.WriteLine("Script storage: " + (resolved.ScriptTable.IsPackageEntry ? "a2d-entry" : "file"));
            if (resolved.ScriptTable.IsPackageEntry)
            {
                Console.WriteLine("Script package: " + resolved.ScriptTable.PackageRelativePath);
                Console.WriteLine("Script index: " + resolved.ScriptTable.PackageEntryIndex);
                Console.WriteLine("Script offset: " + resolved.ScriptTable.PackageEntryOffsetHex);
                Console.WriteLine("Script size: " + resolved.ScriptTable.PackageEntrySizeHex);
            }
        }
        else
        {
            Console.WriteLine("Script table: no");
        }
    }

    public static void PrintProjectResolvedResourceDetail(KarProjectResolvedResourceDetail detail)
    {
        PrintProjectResolvedResource(detail.Resolved);

        if (detail.HasDataDefinition)
            Console.WriteLine("Data definition: " + detail.DataDefinitionId + " (" + detail.DataDefinition.DisplayName + ")");
        else
            Console.WriteLine("Data definition: <none>");

        if (detail.Output != null)
            Console.WriteLine("Output: " + detail.Output.Status + " [" + detail.Output.OutputKind + "] " + detail.Output.OutputRelativePath);
        if (detail.ByteInfo != null)
            PrintProjectResourceByteInfo("Bytes", detail.ByteInfo);

        Console.WriteLine("Children: " + detail.ChildResourceCount);
        foreach (KarProjectResourceInfo child in detail.ChildResources)
            Console.WriteLine("  " + child.Address + " [" + child.Kind + ", " + child.Category + "] - " + child.DisplayName);

        Console.WriteLine("Fields: " + detail.FieldCount);
        foreach (KarProjectResourceFieldInfo field in detail.Fields)
            PrintProjectResourceFieldValueIndented(field, "  ");

        Console.WriteLine("Relationships: " + detail.RelationshipCount);
        foreach (KarProjectRelationship relationship in detail.Relationships)
            Console.WriteLine("  " + relationship.Kind + "/" + relationship.Role + " " + relationship.RelativePath);
    }

    public static void PrintProjectResourceDetail(KarProjectResourceDetail detail)
    {
        PrintProjectResource(detail.Resource);

        if (detail.Output != null)
            Console.WriteLine("Output: " + detail.Output.Status + " [" + detail.Output.OutputKind + "] " + detail.Output.OutputRelativePath);
        if (detail.ByteInfo != null)
            PrintProjectResourceByteInfo("Bytes", detail.ByteInfo);

        Console.WriteLine("Children: " + detail.ChildResourceCount);
        foreach (KarProjectResourceInfo child in detail.ChildResources)
            Console.WriteLine("  " + child.Address + " [" + child.Kind + ", " + child.Category + "] - " + child.DisplayName);

        Console.WriteLine("Fields: " + detail.FieldCount);
        foreach (KarProjectResourceFieldInfo field in detail.Fields)
            PrintProjectResourceFieldValueIndented(field, "  ");

        Console.WriteLine("Relationships: " + detail.RelationshipCount);
        foreach (KarProjectRelationship relationship in detail.Relationships)
            Console.WriteLine("  " + relationship.Kind + "/" + relationship.Role + " " + relationship.RelativePath);
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

    public static void PrintProjectResourceByteInfo(KarProjectResourceByteInfo info)
    {
        PrintProjectResourceByteInfo(info.Address, info);
    }

    private static void PrintProjectResourceByteInfo(string label, KarProjectResourceByteInfo info)
    {
        string output = info.HasOutput ? info.OutputRelativePath : "<missing>";
        Console.WriteLine(label + ": [" + info.Status + "] active=" + info.ActiveLength + " output=" + output);
    }

    public static void PrintProjectResourceFieldValue(KarProjectResourceFieldInfo field)
    {
        PrintProjectResourceFieldValueIndented(field, "");
    }

    private static void PrintProjectResourceFieldValueIndented(KarProjectResourceFieldInfo field, string indent)
    {
        string offset = field.Field.OffsetHex ?? "n/a";
        string schema = string.IsNullOrEmpty(field.DataDefinitionId) ? "<unschematized>" : field.DataDefinitionId;
        string error = string.IsNullOrEmpty(field.Value.Error) ? "" : " (" + field.Value.Error + ")";
        Console.WriteLine(indent + field.Address + " " + schema + "." + field.FieldName + " " + offset + " = " + field.Value.DisplayValue + error);
    }

    public static void PrintProjectResourceDataView(KarProjectResourceDataView view)
    {
        string schema = string.IsNullOrEmpty(view.DataDefinitionId) ? "<unschematized>" : view.DataDefinitionId;
        Console.WriteLine(view.Address + " [" + schema + "] fields=" + view.FieldCount + " total=" + view.TotalFieldCount + " editable=" + view.EditableScalarFieldCount + " pointers=" + view.PointerFieldCount);
        foreach (KarProjectResourceDataFieldView field in view.Fields)
            PrintProjectResourceDataFieldIndented(field, "  ");
    }

    public static void PrintProjectResourceDataField(KarProjectResourceDataFieldView field)
    {
        PrintProjectResourceDataFieldIndented(field, "");
    }

    private static void PrintProjectResourceDataFieldIndented(KarProjectResourceDataFieldView field, string indent)
    {
        string offset = field.OffsetHex ?? "n/a";
        string schema = field.Resource.Root == null || string.IsNullOrEmpty(field.Resource.Root.DataDefinitionId)
            ? "<unschematized>"
            : field.Resource.Root.DataDefinitionId;
        string flags = "";
        if (field.CanSetScalar)
            flags += " editable command=" + field.ScalarEdit.Command;
        if (field.IsPointer)
            flags += " pointer";
        if (field.HasReferenceEntries)
            flags += " entries=" + field.ReferenceEntryCount;
        string error = string.IsNullOrEmpty(field.Error) ? "" : " (" + field.Error + ")";
        Console.WriteLine(indent + field.Address + " " + schema + "." + field.FieldPath + " " + offset + " " + field.TypeName + " = " + field.DisplayValue + flags + error);

        foreach (KarProjectResourceDataFieldView child in field.ReferenceFields)
            PrintProjectResourceDataFieldIndented(child, indent + "  ");
        foreach (KarProjectResourceDataEntryView entry in field.ReferenceEntries)
        {
            Console.WriteLine(indent + "  " + entry.EntryPath + " offset=" + entry.OffsetHex + " fields=" + entry.FieldCount);
            foreach (KarProjectResourceDataFieldView child in entry.Fields)
                PrintProjectResourceDataFieldIndented(child, indent + "    ");
        }
    }

    public static void PrintProjectScriptTable(KarProjectScriptTable table)
    {
        string storage = table.IsPackageEntry ? "a2d-entry" : "file";
        string details = table.IsPackageEntry
            ? " index=" + table.PackageEntryIndex + " offset=" + table.PackageEntryOffsetHex + " size=" + table.PackageEntrySizeHex
            : "";
        Console.WriteLine(table.Address + " [" + table.Role + ", " + storage + "]" + details + " - " + table.Description);
    }

    public static void PrintProjectScriptTableContext(KarProjectScriptTableContext context)
    {
        string storage = context.IsPackageEntry ? "a2d-entry" : "file";
        string output = context.Output == null ? "output=<none>" : "output=" + context.Output.Status + "/" + context.Output.OutputKind;
        Console.WriteLine(context.Address + " [" + context.Role + ", " + storage + "] relationships=" + context.RelationshipCount + " " + output + " - " + context.Description);
    }

    public static void PrintProjectA2DPackageContext(KarProjectA2DPackageContext context)
    {
        string output = context.Output == null ? "output=<none>" : "output=" + context.Output.Status + "/" + context.Output.OutputKind;
        Console.WriteLine(context.RelativePath + ": entries=" + context.EntryCount + " scripts=" + context.ScriptTableCount + " sidecars=" + context.EntryOutputCount + " modified-sidecars=" + context.ModifiedEntryOutputCount + " " + output);
        if (context.HasOpenError)
            Console.WriteLine("  open error: " + context.OpenError);
    }

    public static void PrintProjectMapScriptBundle(KarProjectMapScriptBundle bundle)
    {
        Console.WriteLine("Map scripts: " + bundle.MapName);
        Console.WriteLine("  Map resources: " + bundle.MapResourceCount + " relationships=" + bundle.RelationshipCount);
        PrintProjectMapScriptResourceSlot("Data", bundle.DataResource);
        PrintProjectMapScriptResourceSlot("Model", bundle.ModelResource);
        PrintProjectMapScriptResourceSlot("Script", bundle.ScriptArchiveResource);
        Console.WriteLine("  Script tables: " + bundle.ScriptTableCount);
        foreach (KarProjectScriptTableContext context in bundle.ScriptContexts)
        {
            string output = context.OutputStatus == null ? "" : " output=" + context.OutputStatus;
            Console.WriteLine("    " + context.Address + " [" + context.Role + "] relationships=" + context.RelationshipCount + output);
        }
    }

    public static void PrintProjectMapContext(KarProjectMapContext context)
    {
        Console.WriteLine("Map context: " + context.MapName);
        Console.WriteLine("  Files: " + string.Join(", ", context.Map.Files.Select(file => file.RelativePath)));
        Console.WriteLine("  Archives: " + context.ArchiveCount + " missing-required=" + context.MissingRequiredRootCount);
        if (context.HasInspectionError)
            Console.WriteLine("  Inspection error: " + context.InspectionError);
        Console.WriteLine("  Output: " + context.OutputFileCount + "/" + context.ExpectedOutputFileCount + " modified=" + context.ModifiedOutputFileCount + " missing=" + context.MissingOutputFileCount);
        PrintProjectMapScriptBundle(context.Scripts);
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

    public static void PrintProjectResourceByteDumpResult(KarProjectResourceByteDumpResult result)
    {
        Console.WriteLine("Dumped resource bytes: " + result.Address);
        Console.WriteLine("Output relative path: " + result.OutputRelativePath);
        Console.WriteLine("Output: " + result.OutputPath);
        Console.WriteLine("Length: " + result.Length);
        Console.WriteLine("SHA256: " + result.Sha256);
        Console.WriteLine("Wrote: " + result.WroteOutput);
    }

    public static void PrintProjectResourceByteDumpResultSummary(KarProjectResourceByteDumpResult result)
    {
        string action = result.WroteOutput ? "wrote" : "skipped";
        Console.WriteLine(result.Address + " -> " + result.OutputRelativePath + " [" + action + ", length=" + result.Length + "]");
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

    public static void PrintProjectResourceScalarEditResult(KarProjectResourceScalarEditResult result)
    {
        KarDataFieldEditResult edit = result.Edit;
        Console.WriteLine("Edited resource scalar: " + result.Address);
        Console.WriteLine("Root: " + edit.RootName);
        Console.WriteLine("Field: " + edit.Field.Name);
        Console.WriteLine("Previous: " + edit.PreviousValue.DisplayValue);
        Console.WriteLine("New: " + edit.NewValue.DisplayValue);
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

    public static void PrintProjectDataCoverageReport(KarProjectDataCoverageReport report)
    {
        Console.WriteLine("Data coverage: " + report.Project.Name);
        Console.WriteLine("Archives: " + report.ArchiveCount + " inspected=" + report.InspectableArchiveCount + " errors=" + report.InspectionErrorCount);
        Console.WriteLine("Roots: " + report.RootCount + " known=" + report.KnownRootCount + " unknown=" + report.UnknownRootCount + " data-definitions=" + report.DataDefinitionRootCount + " field-backed=" + report.FieldBackedRootCount);
        Console.WriteLine("Gaps: " + report.IssueCount + " groups=" + report.IssueGroupCount + " inspect=" + report.ArchiveInspectionIssueCount + " missing-required=" + report.MissingRequiredRootIssueCount + " unknown=" + report.UnknownRootIssueCount + " no-schema=" + report.MissingDataDefinitionIssueCount + " no-fields=" + report.MissingFieldValueIssueCount);

        if (report.IssueGroups.Count != 0)
        {
            Console.WriteLine("Gap groups:");
            foreach (KarProjectDataCoverageIssueGroup group in report.IssueGroups)
                PrintProjectDataCoverageIssueGroup(group);
        }

        foreach (KarProjectDataCoverageIssue issue in report.Issues)
            PrintProjectDataCoverageIssue(issue);
    }

    public static void PrintProjectDataCoverageIssueGroup(KarProjectDataCoverageIssueGroup group)
    {
        string schema = string.IsNullOrEmpty(group.DataDefinitionId) ? "" : " schema=" + group.DataDefinitionId;
        string accessor = string.IsNullOrEmpty(group.DisplayAccessorTypeName) ? "" : " accessor=" + group.DisplayAccessorTypeName;
        string size = group.MinStructLength.HasValue && group.MaxStructLength.HasValue
            ? group.MinStructLength.Value == group.MaxStructLength.Value
                ? " size=" + group.MinStructLengthHex
                : " size=" + group.MinStructLengthHex + "-" + group.MaxStructLengthHex
            : "";
        Console.WriteLine("  " + group.DisplayName + " [" + group.Kind + "] files=" + group.FileCount + " issues=" + group.Count + schema + accessor + size);
    }

    public static void PrintProjectDataCoverageIssue(KarProjectDataCoverageIssue issue)
    {
        string target = issue.RelativePath;
        if (!string.IsNullOrEmpty(issue.RootName))
            target += ":" + issue.RootName;
        else if (!string.IsNullOrEmpty(issue.MissingRootPattern))
            target += ":" + issue.MissingRootPattern;

        string schema = string.IsNullOrEmpty(issue.DataDefinitionId) ? "" : " schema=" + issue.DataDefinitionId;
        string accessor = string.IsNullOrEmpty(issue.DisplayAccessorTypeName) ? "" : " accessor=" + issue.DisplayAccessorTypeName;
        string size = string.IsNullOrEmpty(issue.StructLengthHex) ? "" : " size=" + issue.StructLengthHex;
        Console.WriteLine("  " + target + " [" + issue.Kind + "]" + schema + accessor + size + " - " + issue.Message);
    }

    public static void PrintProjectModWorkspace(KarProjectModWorkspace workspace)
    {
        Console.WriteLine("Mod workspace: " + workspace.Project.OutputRoot);
        Console.WriteLine("Output files: " + workspace.OutputFileCount + " project=" + workspace.ProjectOutputFileCount + " modified=" + workspace.ModifiedProjectOutputFileCount + " unchanged=" + workspace.UnchangedProjectOutputFileCount + " orphan=" + workspace.OrphanOutputFileCount);
        Console.WriteLine("Resource outputs: " + workspace.ResourceOutputCount + " project-file=" + workspace.ProjectFileResourceOutputCount + " assets=" + workspace.OutputAssetResourceOutputCount + " modified=" + workspace.ModifiedResourceOutputCount + " unchanged=" + workspace.UnchangedResourceOutputCount);
        Console.WriteLine("Resource byte dumps: " + workspace.ResourceByteOutputCount + " modified=" + workspace.ModifiedResourceByteOutputCount + " matching=" + workspace.MatchingResourceByteOutputCount);
        Console.WriteLine("A2D sidecars: " + workspace.A2DEntryOutputCount + " modified=" + workspace.ModifiedA2DEntryOutputCount + " matching=" + workspace.MatchingA2DEntryOutputCount);
        Console.WriteLine("Map outputs: " + workspace.MapOutputCount + " modified=" + workspace.ModifiedMapOutputCount + " complete=" + workspace.CompleteMapOutputCount);

        if (workspace.ModifiedResourceOutputs.Count != 0)
        {
            Console.WriteLine("Modified resources:");
            foreach (KarProjectResourceOutputInfo output in workspace.ModifiedResourceOutputs)
                Console.WriteLine("  " + output.Address + " [" + output.Status + "] " + output.OutputRelativePath);
        }

        if (workspace.ModifiedResourceByteOutputs.Count != 0)
        {
            Console.WriteLine("Modified resource byte dumps:");
            foreach (KarProjectResourceByteInfo output in workspace.ModifiedResourceByteOutputs)
                Console.WriteLine("  " + output.Address + " [" + output.Status + "] " + output.OutputRelativePath);
        }
    }

    public static void PrintProjectToolkitSnapshot(KarProjectToolkitSnapshot snapshot)
    {
        Console.WriteLine("KAR toolkit: " + snapshot.Name);
        Console.WriteLine("Source: " + snapshot.SourceRoot);
        Console.WriteLine("Output: " + snapshot.OutputRoot);
        Console.WriteLine("Files: " + snapshot.FileCount);
        Console.WriteLine("Domains: maps=" + snapshot.MapContextCount + " vehicles=" + snapshot.VehicleContextCount + " a2d-packages=" + snapshot.A2DPackageContextCount + " script-tables=" + snapshot.ScriptTableContextCount);
        Console.WriteLine("Outputs: files=" + snapshot.OutputFileCount + " resources=" + snapshot.ResourceOutputCount + " resource-bytes=" + snapshot.ResourceByteOutputCount + " a2d-sidecars=" + snapshot.A2DEntryOutputCount + " modified=" + snapshot.HasModifiedOutputs);
        Console.WriteLine("Inspection issues: " + snapshot.DomainInspectionIssueCount + " maps=" + snapshot.MapInspectionErrorCount + " vehicles=" + snapshot.VehicleInspectionErrorCount + " a2d=" + snapshot.A2DPackageOpenErrorCount);
    }

    public static void PrintProjectToolkitSurface(KarProjectToolkitSurface surface)
    {
        Console.WriteLine("KAR toolkit surface: " + surface.Name);
        Console.WriteLine("Domains: " + surface.DomainCount + " workflow-groups=" + surface.WorkflowGroupCount);
        Console.WriteLine("Workflows: " + surface.WorkflowCount + " read=" + surface.ReadOnlyWorkflowCount + " write=" + surface.WriteWorkflowCount + " output=" + surface.OutputWorkflowCount + " batch=" + surface.BatchWorkflowCount);
        Console.WriteLine("Workflow issues: modified-output=" + surface.ModifiedOutputWorkflowCount + " inspection=" + surface.InspectionIssueWorkflowCount);
        foreach (KarProjectToolkitWorkflowGroup group in surface.WorkflowGroups)
            PrintProjectToolkitWorkflowGroup(group);
    }

    public static void PrintProjectToolkitWorkflowGroup(KarProjectToolkitWorkflowGroup group)
    {
        string commands = "";
        if (!string.IsNullOrWhiteSpace(group.ListCommand))
            commands += " list=" + group.ListCommand;
        if (!string.IsNullOrWhiteSpace(group.ContextCommand))
            commands += " context=" + group.ContextCommand;

        Console.WriteLine(group.DomainId + ": workflows=" + group.WorkflowCount + " read=" + group.ReadOnlyWorkflowCount + " write=" + group.WriteWorkflowCount + " output=" + group.OutputWorkflowCount + " batch=" + group.BatchWorkflowCount + commands);
        foreach (KarProjectToolkitWorkflow workflow in group.Workflows)
            PrintProjectToolkitWorkflow("  ", workflow);
    }

    public static void PrintProjectToolkitWorkflow(KarProjectToolkitWorkflow workflow)
    {
        PrintProjectToolkitWorkflow("", workflow);
    }

    public static void PrintProjectOperationCatalog(KarProjectOperationCatalog catalog)
    {
        Console.WriteLine("KAR operations: " + catalog.OperationCount + " workflows=" + catalog.WorkflowOperationCount + " resource-actions=" + catalog.ResourceActionOperationCount + " runnable=" + catalog.RunnableOperationCount + " output=" + catalog.OutputOperationCount);
        foreach (KarProjectOperation operation in catalog.Operations)
            PrintProjectOperation(operation);
    }

    public static void PrintProjectOperationPresetCatalog(KarProjectOperationPresetCatalog catalog)
    {
        Console.WriteLine("KAR operation presets: " + catalog.PresetCount + " available=" + catalog.AvailablePresetCount + " runnable=" + catalog.RunnablePresetCount + " output=" + catalog.OutputPresetCount);
        foreach (KarProjectOperationPreset preset in catalog.Presets)
            PrintProjectOperationPreset(preset);
    }

    public static void PrintProjectOperationPreset(KarProjectOperationPreset preset)
    {
        string mode = preset.IsReadOnly ? "read" : "write";
        string batch = preset.SupportsBatch ? " batch" : "";
        string input = preset.RequiresInputFile ? " input" : "";
        string field = preset.RequiresFieldName ? " field" : "";
        string value = preset.RequiresValue ? " value" : "";
        string modified = preset.ModifiedOutputOperationCount == 0 ? "" : " modified=" + preset.ModifiedOutputOperationCount;
        string batchUsage = preset.BatchUsage == null ? "" : " batch-usage=\"" + preset.BatchUsage + "\"";
        Console.WriteLine(preset.Id + " [" + preset.DomainId + ", " + mode + batch + input + field + value + "] operations=" + preset.OperationCount + " runnable=" + preset.RunnableOperationCount + modified + " usage=\"" + preset.OperationUsage + "\"" + batchUsage);
    }

    public static void PrintProjectOperation(KarProjectOperation operation)
    {
        string mode = operation.IsReadOnly ? "read" : "write";
        string targetDomain = string.IsNullOrWhiteSpace(operation.TargetDomainId) || operation.TargetDomainId == operation.DomainId
            ? ""
            : " target-domain=" + operation.TargetDomainId;
        string resource = string.IsNullOrWhiteSpace(operation.ResourceAddress) ? "" : " resource=" + operation.ResourceAddress;
        string action = string.IsNullOrWhiteSpace(operation.ActionId) ? "" : " action=" + operation.ActionId;
        string run = operation.CanRun.HasValue ? " can-run=" + operation.CanRun.Value : "";
        string write = operation.WouldWriteOutput.HasValue ? " would-write=" + operation.WouldWriteOutput.Value : "";
        string output = string.IsNullOrWhiteSpace(operation.OutputRelativePath) ? "" : " output=" + operation.OutputRelativePath;
        string reason = operation.HasReason ? " reason=\"" + operation.Reason + "\"" : "";

        Console.WriteLine(operation.Id + " [" + operation.Kind + ", " + operation.DomainId + ", " + mode + "] targets=" + operation.TargetCount + targetDomain + resource + action + run + write + output + reason + " usage=\"" + operation.Usage + "\"");
    }

    private static void PrintProjectToolkitWorkflow(string indent, KarProjectToolkitWorkflow workflow)
    {
        string mode = workflow.IsReadOnly ? "read" : "write";
        string batch = workflow.SupportsBatch ? " batch" : "";
        string input = workflow.RequiresInputFile ? " input" : "";
        string value = workflow.RequiresValue ? " value" : "";
        string outputs = workflow.OutputCount == 0 && workflow.ModifiedOutputCount == 0
            ? ""
            : " outputs=" + workflow.OutputCount + " modified=" + workflow.ModifiedOutputCount;
        string issues = workflow.InspectionIssueCount == 0 ? "" : " issues=" + workflow.InspectionIssueCount;
        Console.WriteLine(indent + workflow.Id + " [" + workflow.DomainId + ", " + mode + batch + input + value + "] targets=" + workflow.TargetCount + outputs + issues + " usage=\"" + workflow.Usage + "\"");
    }

    public static void PrintProjectDomainContext(KarProjectDomainContext context)
    {
        string commands = "";
        if (!string.IsNullOrWhiteSpace(context.ListCommand))
            commands += " list=" + context.ListCommand;
        if (!string.IsNullOrWhiteSpace(context.ContextCommand))
            commands += " context=" + context.ContextCommand;

        Console.WriteLine(context.Id + ": items=" + context.ItemCount + " resources=" + context.ResourceCount + " outputs=" + context.OutputCount + " modified=" + context.ModifiedOutputCount + " issues=" + context.InspectionIssueCount + commands);
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

    public static void PrintVehicleBundle(KarVehicleBundle vehicle)
    {
        string shared = vehicle.HasSharedFiles ? " shared=" + string.Join(",", vehicle.SharedFiles.Select(file => file.RelativePath)) : "";
        Console.WriteLine(vehicle.Name + " [" + vehicle.Family + ", " + vehicle.Role + "] " + vehicle.DataFile.RelativePath + shared);
    }

    public static void PrintProjectVehicleContext(KarProjectVehicleContext context)
    {
        Console.WriteLine("Vehicle context: " + context.Name + " [" + context.Family + ", " + context.Role + "]");
        Console.WriteLine("  Files: " + string.Join(", ", context.Files.Select(file => file.RelativePath)));
        Console.WriteLine("  Archives: " + context.ArchiveCount + " roots=" + context.KnownRootCount + "/" + context.RootCount + " missing-required=" + context.MissingRequiredRootCount);
        if (context.HasInspectionErrors)
        {
            Console.WriteLine("  Inspection errors:");
            foreach (string error in context.InspectionErrors)
                Console.WriteLine("    " + error);
        }
        Console.WriteLine("  Resources: " + context.ResourceCount);
        Console.WriteLine("  Output: " + context.OutputFileCount + "/" + context.ExpectedOutputFileCount + " modified=" + context.ModifiedOutputFileCount + " missing=" + context.MissingOutputFileCount);
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
        Console.WriteLine(root.RelativePath + ":" + root.RootName + " [" + known + ", " + type + schema + "] - " + root.DisplayName);
    }

    public static void PrintProjectRootSummaryGroup(KarProjectRootSummary summary)
    {
        string known = summary.IsKnown ? "known" : "unknown";
        string type = string.IsNullOrEmpty(summary.DisplayAccessorTypeName) ? "<untyped>" : summary.DisplayAccessorTypeName;
        string schema = string.IsNullOrEmpty(summary.DataDefinitionId) ? "" : ", " + summary.DataDefinitionId;
        Console.WriteLine(summary.RootName + " [" + known + ", " + type + schema + "] x" + summary.Count + " - " + summary.DisplayName);
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

    public static void PrintProjectArchiveContext(KarProjectArchiveContext context)
    {
        string output = context.Output == null ? "output=<none>" : "output=" + context.Output.Status + "/" + context.Output.OutputKind;
        Console.WriteLine(
            context.RelativePath +
            " [" + context.Kind + ", " + context.Category + "] roots=" + context.RootCount +
            " known=" + context.KnownRootCount +
            " unknown=" + context.UnknownRootCount +
            " missing=" + context.MissingRequiredRootCount +
            " fields=" + context.FieldCount +
            " relationships=" + context.RelationshipCount +
            " " + output);

        if (context.HasInspectionError)
            Console.WriteLine("  inspection error: " + context.InspectionError);

        foreach (KarRootDefinition missing in context.MissingRequiredRoots)
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
            string size = string.IsNullOrEmpty(root.StructLengthHex) ? "" : ", size=" + root.StructLengthHex;
            string description = root.Definition == null || string.IsNullOrEmpty(root.Definition.Description)
                ? ""
                : " - " + root.Definition.Description;

            Console.WriteLine(indent + "  " + root.Name + " [" + known + ", " + type + size + "]" + description);

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

    public static void PrintProjectArchiveSchema(KarProjectArchiveSchemaInfo schema)
    {
        Console.WriteLine(schema.RelativePath + " [" + schema.Kind + ", " + schema.Category + "] expected-roots=" + schema.RootDefinitionCount + " required=" + schema.RequiredRootDefinitionCount + " - " + schema.DisplayName);
        foreach (KarRootDefinition root in schema.RootDefinitions)
        {
            string required = root.IsRequired ? "required" : "optional";
            string type = string.IsNullOrEmpty(root.AccessorTypeName) ? "<untyped>" : root.AccessorTypeName;
            string dataDefinition = string.IsNullOrEmpty(root.DataDefinitionId) ? "" : ", " + root.DataDefinitionId;
            Console.WriteLine("  " + root.Pattern + " [" + required + ", " + type + dataDefinition + "] - " + root.Description);
        }
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
