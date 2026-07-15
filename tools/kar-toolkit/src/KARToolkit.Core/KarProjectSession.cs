using System;
using System.Collections.Generic;

namespace KARToolkit.Core
{
    public sealed class KarProjectSession
    {
        private KarProjectSession(KarProject project, KarProjectToolkitSurface surface)
        {
            Project = project ?? throw new ArgumentNullException(nameof(project));
            Surface = surface ?? throw new ArgumentNullException(nameof(surface));
            RegistryCatalog = Project.ToolkitService.CreateRegistryCatalog();
        }

        public KarProject Project { get; }

        public KarProjectWorkspace Workspace => Project.Workspace;

        public KarProjectToolkitRegistryCatalog RegistryCatalog { get; }

        public KarProjectToolkitSurface Surface { get; }

        public KarProjectToolkitSnapshot Snapshot => Surface.Snapshot;

        public KarProjectModWorkspace ModWorkspace => Snapshot.ModWorkspace;

        public KarProjectModManifest ModManifest => ModWorkspace == null ? null : new KarProjectModManifest(Project, ModWorkspace);

        public IReadOnlyList<KarProjectDomainContext> Domains => Surface.Domains;

        public IReadOnlyList<KarProjectToolkitWorkflow> Workflows => Surface.Workflows;

        public IReadOnlyList<KarProjectToolkitWorkflowGroup> WorkflowGroups => Surface.WorkflowGroups;

        public KarProjectOperationCatalog OperationCatalog => Project.OperationService.CreateCatalog(new KarProjectOperationQueryOptions
        {
            SnapshotOptions = new KarProjectToolkitSnapshotOptions
            {
                IncludeModWorkspace = Snapshot.HasModWorkspace,
                IncludeMapContexts = Snapshot.MapContextCount != 0,
                IncludeVehicleContexts = Snapshot.VehicleContextCount != 0,
                IncludeA2DPackageContexts = Snapshot.A2DPackageContextCount != 0,
                IncludeScriptTableContexts = Snapshot.ScriptTableContextCount != 0,
            },
        });

        public string Name => Project.Name;

        public string SourceRoot => Project.SourceRoot;

        public string SourceFilesRoot => Project.SourceFilesRoot;

        public string OutputRoot => Project.OutputRoot;

        public string OutputFilesRoot => Project.OutputFilesRoot;

        public string ReadPolicy => Workspace.ReadPolicy;

        public string WritePolicy => Workspace.WritePolicy;

        public bool ReadsPreferOutputCopies => Workspace.ReadsPreferOutputCopies;

        public bool WritesOnlyToOutput => Workspace.WritesOnlyToOutput;

        public bool SourceAndOutputRootsAreSeparate => Workspace.SourceAndOutputRootsAreSeparate;

        public bool SourceFilesAndOutputFilesRootsAreSeparate => Workspace.SourceFilesAndOutputFilesRootsAreSeparate;

        public int FileCount => Project.Files.Count;

        public int MapCount => Project.Maps.Count;

        public int DomainCount => Surface.DomainCount;

        public int WorkflowCount => Surface.WorkflowCount;

        public int AvailableWorkflowCount => Surface.AvailableWorkflowCount;

        public int OutputWorkflowCount => Surface.OutputWorkflowCount;

        public int RegistryCount => RegistryCatalog.RegistryCount;

        public int ArchiveDefinitionRuleCount => RegistryCatalog.ArchiveDefinitionRuleCount;

        public int DataDefinitionProviderCount => RegistryCatalog.DataDefinitionProviderCount;

        public int FileKindClassificationRuleCount => RegistryCatalog.FileKindClassificationRuleCount;

        public int FileKindCount => RegistryCatalog.FileKindCount;

        public int FileHandlerCount => RegistryCatalog.FileHandlerCount;

        public int ResourceHandlerCount => RegistryCatalog.ResourceHandlerCount;

        public int ResourceAdapterProviderCount => RegistryCatalog.ResourceAdapterProviderCount;

        public int RelationshipProviderCount => RegistryCatalog.RelationshipProviderCount;

        public int ResourceActionDefinitionCount => RegistryCatalog.ResourceActionDefinitionCount;

        public int OperationDomainRuleCount => RegistryCatalog.OperationDomainRuleCount;

        public int DomainContextProviderCount => RegistryCatalog.DomainContextProviderCount;

        public int ToolkitWorkflowProviderCount => RegistryCatalog.ToolkitWorkflowProviderCount;

        public int OperationPresetDefinitionCount => RegistryCatalog.OperationPresetDefinitionCount;

        public bool HasOutputs => Snapshot.HasOutputs;

        public bool HasModifiedOutputs => Snapshot.HasModifiedOutputs;

        public static KarProjectSession Open(string sourceRoot)
        {
            return Open(sourceRoot, null, null);
        }

        public static KarProjectSession Open(string sourceRoot, string outputRoot)
        {
            return Open(sourceRoot, outputRoot, null);
        }

        public static KarProjectSession Open(
            string sourceRoot,
            string outputRoot,
            KarProjectToolkitSnapshotOptions toolkitOptions)
        {
            return Open(
                new KarProjectOptions
                {
                    SourceRoot = sourceRoot,
                    OutputRoot = outputRoot,
                },
                toolkitOptions);
        }

        public static KarProjectSession Open(
            KarProjectOptions projectOptions,
            KarProjectToolkitSnapshotOptions toolkitOptions = null)
        {
            if (projectOptions == null)
                throw new ArgumentNullException(nameof(projectOptions));

            return Create(KarProject.Open(projectOptions), toolkitOptions);
        }

        public static KarProjectSession Create(
            KarProject project,
            KarProjectToolkitSnapshotOptions toolkitOptions = null)
        {
            if (project == null)
                throw new ArgumentNullException(nameof(project));

            return new KarProjectSession(project, project.ToolkitService.CreateSurface(toolkitOptions));
        }

        public KarProjectSession Refresh(KarProjectToolkitSnapshotOptions toolkitOptions = null)
        {
            return Create(Project, toolkitOptions);
        }

        public KarProjectSessionContract CreateContract()
        {
            return KarProjectSessionContract.Create(this);
        }

        public KarProjectModManifest CreateModManifest(KarProjectModWorkspaceOptions options = null)
        {
            if (options == null && ModWorkspace != null)
                return new KarProjectModManifest(Project, ModWorkspace);

            return Project.ModWorkspaceService.CreateManifest(options);
        }

        public KarProjectOperationCatalog CreateOperationCatalog(KarProjectOperationQueryOptions options = null)
        {
            return Project.OperationService.CreateCatalog(options);
        }

        public KarProjectOperationCatalogContract CreateOperationCatalogContract(KarProjectOperationQueryOptions options = null)
        {
            return Project.OperationService.CreateCatalogContract(options);
        }

        public KarProjectOperationPresetCatalog CreateOperationPresetCatalog(KarProjectOperationPresetQueryOptions options = null)
        {
            return Project.OperationService.CreatePresetCatalog(options);
        }

        public KarProjectOperationExecutionResult ExecuteOperation(
            string operationId,
            KarProjectResourceActionExecutionOptions executionOptions = null,
            KarProjectOperationQueryOptions queryOptions = null)
        {
            return Project.OperationService.Execute(operationId, executionOptions, queryOptions);
        }

        public KarProjectOperationBatchResult ExecuteOperationBatch(
            KarProjectOperationQueryOptions queryOptions,
            KarProjectResourceActionExecutionOptions executionOptions = null)
        {
            return Project.OperationService.ExecuteBatch(queryOptions, executionOptions);
        }
    }
}
