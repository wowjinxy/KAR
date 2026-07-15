using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectToolkitRegistryCatalogContract
    {
        public KarProjectContract Project { get; set; }

        public bool HasProject { get; set; }

        public string ProjectName { get; set; }

        public string SourceRoot { get; set; }

        public string OutputRoot { get; set; }

        public int RegistryCount { get; set; }

        public int DataDefinitionProviderCount { get; set; }

        public int FileKindCount { get; set; }

        public int FileHandlerCount { get; set; }

        public int ResourceHandlerCount { get; set; }

        public int ResourceAdapterProviderCount { get; set; }

        public int RelationshipProviderCount { get; set; }

        public int ResourceActionDefinitionCount { get; set; }

        public int OperationDomainRuleCount { get; set; }

        public int DomainContextProviderCount { get; set; }

        public int ToolkitWorkflowProviderCount { get; set; }

        public int OperationPresetDefinitionCount { get; set; }

        public bool HasDataDefinitionProviders { get; set; }

        public bool HasFileKinds { get; set; }

        public bool HasFileHandlers { get; set; }

        public bool HasResourceHandlers { get; set; }

        public bool HasResourceAdapterProviders { get; set; }

        public bool HasRelationshipProviders { get; set; }

        public bool HasResourceActionDefinitions { get; set; }

        public bool HasOperationDomainRules { get; set; }

        public bool HasDomainContextProviders { get; set; }

        public bool HasToolkitWorkflowProviders { get; set; }

        public bool HasOperationPresetDefinitions { get; set; }

        public IReadOnlyList<KarDataDefinitionProviderContract> DataDefinitionProviders { get; set; }

        public IReadOnlyList<KarFileKindDescriptorContract> FileKinds { get; set; }

        public IReadOnlyList<KarProjectFileHandlerContract> FileHandlers { get; set; }

        public IReadOnlyList<KarProjectResourceHandlerContract> ResourceHandlers { get; set; }

        public IReadOnlyList<KarProjectResourceAdapterProviderContract> ResourceAdapterProviders { get; set; }

        public IReadOnlyList<KarProjectRelationshipProviderContract> RelationshipProviders { get; set; }

        public IReadOnlyList<KarProjectResourceActionDefinitionContract> ResourceActionDefinitions { get; set; }

        public IReadOnlyList<KarProjectOperationDomainRuleContract> OperationDomainRules { get; set; }

        public IReadOnlyList<KarProjectDomainContextProviderContract> DomainContextProviders { get; set; }

        public IReadOnlyList<KarProjectToolkitWorkflowProviderContract> ToolkitWorkflowProviders { get; set; }

        public IReadOnlyList<KarProjectOperationPresetDefinitionContract> OperationPresetDefinitions { get; set; }

        public static KarProjectToolkitRegistryCatalogContract Create(KarProjectToolkitRegistryCatalog catalog)
        {
            if (catalog == null)
                throw new ArgumentNullException(nameof(catalog));

            return new KarProjectToolkitRegistryCatalogContract
            {
                Project = catalog.Project == null ? null : KarProjectContract.Create(catalog.Project),
                HasProject = catalog.HasProject,
                ProjectName = catalog.ProjectName,
                SourceRoot = catalog.SourceRoot,
                OutputRoot = catalog.OutputRoot,
                RegistryCount = catalog.RegistryCount,
                DataDefinitionProviderCount = catalog.DataDefinitionProviderCount,
                FileKindCount = catalog.FileKindCount,
                FileHandlerCount = catalog.FileHandlerCount,
                ResourceHandlerCount = catalog.ResourceHandlerCount,
                ResourceAdapterProviderCount = catalog.ResourceAdapterProviderCount,
                RelationshipProviderCount = catalog.RelationshipProviderCount,
                ResourceActionDefinitionCount = catalog.ResourceActionDefinitionCount,
                OperationDomainRuleCount = catalog.OperationDomainRuleCount,
                DomainContextProviderCount = catalog.DomainContextProviderCount,
                ToolkitWorkflowProviderCount = catalog.ToolkitWorkflowProviderCount,
                OperationPresetDefinitionCount = catalog.OperationPresetDefinitionCount,
                HasDataDefinitionProviders = catalog.HasDataDefinitionProviders,
                HasFileKinds = catalog.HasFileKinds,
                HasFileHandlers = catalog.HasFileHandlers,
                HasResourceHandlers = catalog.HasResourceHandlers,
                HasResourceAdapterProviders = catalog.HasResourceAdapterProviders,
                HasRelationshipProviders = catalog.HasRelationshipProviders,
                HasResourceActionDefinitions = catalog.HasResourceActionDefinitions,
                HasOperationDomainRules = catalog.HasOperationDomainRules,
                HasDomainContextProviders = catalog.HasDomainContextProviders,
                HasToolkitWorkflowProviders = catalog.HasToolkitWorkflowProviders,
                HasOperationPresetDefinitions = catalog.HasOperationPresetDefinitions,
                DataDefinitionProviders = catalog.DataDefinitionProviders.Select(KarDataDefinitionProviderContract.Create).ToList().AsReadOnly(),
                FileKinds = catalog.FileKinds.Select(KarFileKindDescriptorContract.Create).ToList().AsReadOnly(),
                FileHandlers = catalog.FileHandlers.Select(KarProjectFileHandlerContract.Create).ToList().AsReadOnly(),
                ResourceHandlers = catalog.ResourceHandlers.Select(KarProjectResourceHandlerContract.Create).ToList().AsReadOnly(),
                ResourceAdapterProviders = catalog.ResourceAdapterProviders.Select(KarProjectResourceAdapterProviderContract.Create).ToList().AsReadOnly(),
                RelationshipProviders = catalog.RelationshipProviders.Select(KarProjectRelationshipProviderContract.Create).ToList().AsReadOnly(),
                ResourceActionDefinitions = catalog.ResourceActionDefinitions.Select(KarProjectResourceActionDefinitionContract.Create).ToList().AsReadOnly(),
                OperationDomainRules = catalog.OperationDomainRules.Select(KarProjectOperationDomainRuleContract.Create).ToList().AsReadOnly(),
                DomainContextProviders = catalog.DomainContextProviders.Select(KarProjectDomainContextProviderContract.Create).ToList().AsReadOnly(),
                ToolkitWorkflowProviders = catalog.ToolkitWorkflowProviders.Select(KarProjectToolkitWorkflowProviderContract.Create).ToList().AsReadOnly(),
                OperationPresetDefinitions = catalog.OperationPresetDefinitions.Select(KarProjectOperationPresetDefinitionContract.Create).ToList().AsReadOnly(),
            };
        }
    }

    public sealed class KarProjectContract
    {
        public string Name { get; set; }

        public KarProjectWorkspaceContract Workspace { get; set; }

        public string SourceRoot { get; set; }

        public string SourceFilesRoot { get; set; }

        public string OutputRoot { get; set; }

        public string OutputFilesRoot { get; set; }

        public bool SourceHasFilesDirectory { get; set; }

        public int FileCount { get; set; }

        public int MapCount { get; set; }

        public IReadOnlyList<KarProjectCategoryContract> Categories { get; set; }

        public static KarProjectContract Create(KarProject project)
        {
            if (project == null)
                throw new ArgumentNullException(nameof(project));

            return new KarProjectContract
            {
                Name = project.Name,
                Workspace = KarProjectWorkspaceContract.Create(project.Workspace),
                SourceRoot = project.SourceRoot,
                SourceFilesRoot = project.SourceFilesRoot,
                OutputRoot = project.OutputRoot,
                OutputFilesRoot = project.OutputFilesRoot,
                SourceHasFilesDirectory = project.SourceHasFilesDirectory,
                FileCount = project.FileService.Files.Count,
                MapCount = project.Maps.Count,
                Categories = project.FileService.Files
                    .GroupBy(file => file.Category)
                    .OrderBy(group => group.Key, StringComparer.OrdinalIgnoreCase)
                    .Select(group => new KarProjectCategoryContract
                    {
                        Category = group.Key,
                        Count = group.Count(),
                    })
                    .ToList()
                    .AsReadOnly(),
            };
        }
    }

    public sealed class KarProjectCategoryContract
    {
        public string Category { get; set; }

        public int Count { get; set; }
    }

    public sealed class KarProjectWorkspaceContract
    {
        public string Name { get; set; }

        public string SourceRoot { get; set; }

        public string SourceFilesRoot { get; set; }

        public string OutputRoot { get; set; }

        public string OutputFilesRoot { get; set; }

        public bool SourceHasFilesDirectory { get; set; }

        public string ReadPolicy { get; set; }

        public string WritePolicy { get; set; }

        public bool ReadsPreferOutputCopies { get; set; }

        public bool WritesOnlyToOutput { get; set; }

        public bool SourceAndOutputRootsAreSeparate { get; set; }

        public bool SourceFilesAndOutputFilesRootsAreSeparate { get; set; }

        public static KarProjectWorkspaceContract Create(KarProjectWorkspace workspace)
        {
            if (workspace == null)
                throw new ArgumentNullException(nameof(workspace));

            return new KarProjectWorkspaceContract
            {
                Name = workspace.Name,
                SourceRoot = workspace.SourceRoot,
                SourceFilesRoot = workspace.SourceFilesRoot,
                OutputRoot = workspace.OutputRoot,
                OutputFilesRoot = workspace.OutputFilesRoot,
                SourceHasFilesDirectory = workspace.SourceHasFilesDirectory,
                ReadPolicy = workspace.ReadPolicy,
                WritePolicy = workspace.WritePolicy,
                ReadsPreferOutputCopies = workspace.ReadsPreferOutputCopies,
                WritesOnlyToOutput = workspace.WritesOnlyToOutput,
                SourceAndOutputRootsAreSeparate = workspace.SourceAndOutputRootsAreSeparate,
                SourceFilesAndOutputFilesRootsAreSeparate = workspace.SourceFilesAndOutputFilesRootsAreSeparate,
            };
        }
    }

    public sealed class KarFileKindDescriptorContract
    {
        public string Kind { get; set; }

        public string Id { get; set; }

        public string DisplayName { get; set; }

        public string Category { get; set; }

        public string Description { get; set; }

        public bool IsHsdArchive { get; set; }

        public bool IsA2DPackage { get; set; }

        public bool IsScriptTable { get; set; }

        public bool IsMedia { get; set; }

        public bool IsConfig { get; set; }

        public bool IsMapBundlePart { get; set; }

        public string MapBundleRole { get; set; }

        public bool IsContainer { get; set; }

        public static KarFileKindDescriptorContract Create(KarFileKindDescriptor descriptor)
        {
            if (descriptor == null)
                throw new ArgumentNullException(nameof(descriptor));

            return new KarFileKindDescriptorContract
            {
                Kind = descriptor.Kind.ToString(),
                Id = descriptor.Id,
                DisplayName = descriptor.DisplayName,
                Category = descriptor.Category,
                Description = descriptor.Description,
                IsHsdArchive = descriptor.IsHsdArchive,
                IsA2DPackage = descriptor.IsA2DPackage,
                IsScriptTable = descriptor.IsScriptTable,
                IsMedia = descriptor.IsMedia,
                IsConfig = descriptor.IsConfig,
                IsMapBundlePart = descriptor.IsMapBundlePart,
                MapBundleRole = descriptor.MapBundleRole,
                IsContainer = descriptor.IsContainer,
            };
        }
    }

    public sealed class KarDataDefinitionProviderContract
    {
        public string Id { get; set; }

        public string DisplayName { get; set; }

        public string Description { get; set; }

        public int DefinitionCount { get; set; }

        public static KarDataDefinitionProviderContract Create(KarDataDefinitionProvider provider)
        {
            if (provider == null)
                throw new ArgumentNullException(nameof(provider));

            return new KarDataDefinitionProviderContract
            {
                Id = provider.Id,
                DisplayName = provider.DisplayName,
                Description = provider.Description,
                DefinitionCount = provider.DefinitionCount,
            };
        }
    }

    public sealed class KarProjectFileHandlerContract
    {
        public string Kind { get; set; }

        public string Id { get; set; }

        public string DisplayName { get; set; }

        public string Category { get; set; }

        public KarFileKindDescriptorContract Descriptor { get; set; }

        public IReadOnlyList<string> Capabilities { get; set; }

        public bool CanReadBytes { get; set; }

        public bool CanCopyToOutput { get; set; }

        public bool CanReplaceFileInOutput { get; set; }

        public bool CanInspectHsdArchive { get; set; }

        public bool CanQueryHsdRoots { get; set; }

        public bool CanEditHsdScalarFields { get; set; }

        public bool CanOpenA2DPackage { get; set; }

        public bool CanListA2DEntries { get; set; }

        public bool CanExtractA2DEntries { get; set; }

        public bool CanReplaceA2DEntries { get; set; }

        public bool CanListScriptTables { get; set; }

        public bool CanGroupWithMap { get; set; }

        public bool CanInspectMapArchive { get; set; }

        public static KarProjectFileHandlerContract Create(KarProjectFileHandler handler)
        {
            if (handler == null)
                throw new ArgumentNullException(nameof(handler));

            return new KarProjectFileHandlerContract
            {
                Kind = handler.Kind.ToString(),
                Id = handler.Id,
                DisplayName = handler.DisplayName,
                Category = handler.Category,
                Descriptor = KarFileKindDescriptorContract.Create(handler.Descriptor),
                Capabilities = handler.CapabilityList.Select(capability => capability.ToString()).ToList().AsReadOnly(),
                CanReadBytes = handler.CanReadBytes,
                CanCopyToOutput = handler.CanCopyToOutput,
                CanReplaceFileInOutput = handler.CanReplaceFileInOutput,
                CanInspectHsdArchive = handler.CanInspectHsdArchive,
                CanQueryHsdRoots = handler.CanQueryHsdRoots,
                CanEditHsdScalarFields = handler.CanEditHsdScalarFields,
                CanOpenA2DPackage = handler.CanOpenA2DPackage,
                CanListA2DEntries = handler.CanListA2DEntries,
                CanExtractA2DEntries = handler.CanExtractA2DEntries,
                CanReplaceA2DEntries = handler.CanReplaceA2DEntries,
                CanListScriptTables = handler.CanListScriptTables,
                CanGroupWithMap = handler.CanGroupWithMap,
                CanInspectMapArchive = handler.CanInspectMapArchive,
            };
        }
    }

    public sealed class KarProjectResourceHandlerContract
    {
        public string Kind { get; set; }

        public string Id { get; set; }

        public string DisplayName { get; set; }

        public string Description { get; set; }

        public IReadOnlyList<string> Capabilities { get; set; }

        public int ActionCount { get; set; }

        public IReadOnlyList<KarProjectResourceActionContract> Actions { get; set; }

        public bool CanQueryOutput { get; set; }

        public bool CanReadBytes { get; set; }

        public bool CanExportToOutput { get; set; }

        public bool CanImportFromFile { get; set; }

        public bool CanQueryFieldValues { get; set; }

        public bool CanSetScalarFields { get; set; }

        public bool CanApplyOutput { get; set; }

        public static KarProjectResourceHandlerContract Create(KarProjectResourceHandler handler)
        {
            if (handler == null)
                throw new ArgumentNullException(nameof(handler));

            return new KarProjectResourceHandlerContract
            {
                Kind = handler.Kind.ToString(),
                Id = handler.Id,
                DisplayName = handler.DisplayName,
                Description = handler.Description,
                Capabilities = handler.CapabilityList.Select(capability => capability.ToString()).ToList().AsReadOnly(),
                ActionCount = handler.ActionCount,
                Actions = handler.Actions.Select(KarProjectResourceActionContract.Create).ToList().AsReadOnly(),
                CanQueryOutput = handler.CanQueryOutput,
                CanReadBytes = handler.CanReadBytes,
                CanExportToOutput = handler.CanExportToOutput,
                CanImportFromFile = handler.CanImportFromFile,
                CanQueryFieldValues = handler.CanQueryFieldValues,
                CanSetScalarFields = handler.CanSetScalarFields,
                CanApplyOutput = handler.CanApplyOutput,
            };
        }
    }

    public sealed class KarProjectResourceActionContract
    {
        public string Id { get; set; }

        public string DisplayName { get; set; }

        public string Description { get; set; }

        public string Capability { get; set; }

        public string Command { get; set; }

        public string ArgumentHint { get; set; }

        public bool IsReadOnly { get; set; }

        public bool WritesOutput { get; set; }

        public bool RequiresInputFile { get; set; }

        public bool RequiresFieldName { get; set; }

        public bool RequiresValue { get; set; }

        public bool SupportsBatch { get; set; }

        public string ExecutionKind { get; set; }

        public string PlanStateKind { get; set; }

        public bool RequiresOutputInfo { get; set; }

        public bool RequiresByteInfo { get; set; }

        public string WritePolicy { get; set; }

        public static KarProjectResourceActionContract Create(KarProjectResourceAction action)
        {
            if (action == null)
                throw new ArgumentNullException(nameof(action));

            return new KarProjectResourceActionContract
            {
                Id = action.Id,
                DisplayName = action.DisplayName,
                Description = action.Description,
                Capability = action.CapabilityName,
                Command = action.Command,
                ArgumentHint = action.ArgumentHint,
                IsReadOnly = action.IsReadOnly,
                WritesOutput = action.WritesOutput,
                RequiresInputFile = action.RequiresInputFile,
                RequiresFieldName = action.RequiresFieldName,
                RequiresValue = action.RequiresValue,
                SupportsBatch = action.SupportsBatch,
                ExecutionKind = action.ExecutionKindName,
                PlanStateKind = action.PlanStateKindName,
                RequiresOutputInfo = action.RequiresOutputInfo,
                RequiresByteInfo = action.RequiresByteInfo,
                WritePolicy = action.WritePolicyName,
            };
        }
    }

    public sealed class KarProjectResourceAdapterProviderContract
    {
        public string Kind { get; set; }

        public string Id { get; set; }

        public string DisplayName { get; set; }

        public string Description { get; set; }

        public static KarProjectResourceAdapterProviderContract Create(KarProjectResourceAdapterProvider provider)
        {
            if (provider == null)
                throw new ArgumentNullException(nameof(provider));

            return new KarProjectResourceAdapterProviderContract
            {
                Kind = provider.Kind.ToString(),
                Id = provider.Id,
                DisplayName = provider.DisplayName,
                Description = provider.Description,
            };
        }
    }

    public sealed class KarProjectRelationshipProviderContract
    {
        public string Id { get; set; }

        public string DisplayName { get; set; }

        public string Description { get; set; }

        public static KarProjectRelationshipProviderContract Create(KarProjectRelationshipProvider provider)
        {
            if (provider == null)
                throw new ArgumentNullException(nameof(provider));

            return new KarProjectRelationshipProviderContract
            {
                Id = provider.Id,
                DisplayName = provider.DisplayName,
                Description = provider.Description,
            };
        }
    }

    public sealed class KarProjectResourceActionDefinitionContract
    {
        public string Id { get; set; }

        public string DisplayName { get; set; }

        public string Description { get; set; }

        public string Capability { get; set; }

        public string Command { get; set; }

        public string ArgumentHint { get; set; }

        public bool IsReadOnly { get; set; }

        public bool WritesOutput { get; set; }

        public bool RequiresInputFile { get; set; }

        public bool RequiresFieldName { get; set; }

        public bool RequiresValue { get; set; }

        public bool SupportsBatch { get; set; }

        public string ExecutionKind { get; set; }

        public string PlanStateKind { get; set; }

        public bool RequiresOutputInfo { get; set; }

        public bool RequiresByteInfo { get; set; }

        public string WritePolicy { get; set; }

        public static KarProjectResourceActionDefinitionContract Create(KarProjectResourceActionDefinition definition)
        {
            if (definition == null)
                throw new ArgumentNullException(nameof(definition));

            return new KarProjectResourceActionDefinitionContract
            {
                Id = definition.Id,
                DisplayName = definition.DisplayName,
                Description = definition.Description,
                Capability = definition.CapabilityName,
                Command = definition.Command,
                ArgumentHint = definition.ArgumentHint,
                IsReadOnly = definition.IsReadOnly,
                WritesOutput = definition.WritesOutput,
                RequiresInputFile = definition.RequiresInputFile,
                RequiresFieldName = definition.RequiresFieldName,
                RequiresValue = definition.RequiresValue,
                SupportsBatch = definition.SupportsBatch,
                ExecutionKind = definition.ExecutionKindName,
                PlanStateKind = definition.PlanStateKindName,
                RequiresOutputInfo = definition.RequiresOutputInfo,
                RequiresByteInfo = definition.RequiresByteInfo,
                WritePolicy = definition.WritePolicyName,
            };
        }
    }

    public sealed class KarProjectOperationDomainRuleContract
    {
        public string Id { get; set; }

        public string DisplayName { get; set; }

        public string Description { get; set; }

        public static KarProjectOperationDomainRuleContract Create(KarProjectOperationDomainRule rule)
        {
            if (rule == null)
                throw new ArgumentNullException(nameof(rule));

            return new KarProjectOperationDomainRuleContract
            {
                Id = rule.Id,
                DisplayName = rule.DisplayName,
                Description = rule.Description,
            };
        }
    }

    public sealed class KarProjectDomainContextProviderContract
    {
        public string Id { get; set; }

        public string DisplayName { get; set; }

        public string Description { get; set; }

        public string ListCommand { get; set; }

        public string ContextCommand { get; set; }

        public static KarProjectDomainContextProviderContract Create(KarProjectDomainContextProvider provider)
        {
            if (provider == null)
                throw new ArgumentNullException(nameof(provider));

            return new KarProjectDomainContextProviderContract
            {
                Id = provider.Id,
                DisplayName = provider.DisplayName,
                Description = provider.Description,
                ListCommand = provider.ListCommand,
                ContextCommand = provider.ContextCommand,
            };
        }
    }

    public sealed class KarProjectToolkitWorkflowProviderContract
    {
        public string Id { get; set; }

        public string DisplayName { get; set; }

        public string Description { get; set; }

        public static KarProjectToolkitWorkflowProviderContract Create(KarProjectToolkitWorkflowProvider provider)
        {
            if (provider == null)
                throw new ArgumentNullException(nameof(provider));

            return new KarProjectToolkitWorkflowProviderContract
            {
                Id = provider.Id,
                DisplayName = provider.DisplayName,
                Description = provider.Description,
            };
        }
    }

    public sealed class KarProjectOperationPresetDefinitionContract
    {
        public string Id { get; set; }

        public string DomainId { get; set; }

        public string DisplayName { get; set; }

        public string Description { get; set; }

        public string ActionId { get; set; }

        public string ResourceKind { get; set; }

        public bool IsReadOnly { get; set; }

        public bool WritesOutput { get; set; }

        public bool SupportsBatch { get; set; }

        public bool RequiresInputFile { get; set; }

        public bool RequiresFieldName { get; set; }

        public bool RequiresValue { get; set; }

        public bool? CanRun { get; set; }

        public bool? WouldWriteOutput { get; set; }

        public bool? HasModifiedOutputs { get; set; }

        public static KarProjectOperationPresetDefinitionContract Create(KarProjectOperationPresetDefinition definition)
        {
            if (definition == null)
                throw new ArgumentNullException(nameof(definition));

            return new KarProjectOperationPresetDefinitionContract
            {
                Id = definition.Id,
                DomainId = definition.DomainId,
                DisplayName = definition.DisplayName,
                Description = definition.Description,
                ActionId = definition.ActionId,
                ResourceKind = definition.ResourceKind == null ? null : definition.ResourceKind.ToString(),
                IsReadOnly = definition.IsReadOnly,
                WritesOutput = definition.WritesOutput,
                SupportsBatch = definition.SupportsBatch,
                RequiresInputFile = definition.RequiresInputFile,
                RequiresFieldName = definition.RequiresFieldName,
                RequiresValue = definition.RequiresValue,
                CanRun = definition.CanRun,
                WouldWriteOutput = definition.WouldWriteOutput,
                HasModifiedOutputs = definition.HasModifiedOutputs,
            };
        }
    }
}
