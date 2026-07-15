using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectToolkitSurfaceContract
    {
        public KarProjectContract Project { get; set; }

        public string Name { get; set; }

        public string SourceRoot { get; set; }

        public string OutputRoot { get; set; }

        public int DomainCount { get; set; }

        public int WorkflowCount { get; set; }

        public int WorkflowGroupCount { get; set; }

        public int AvailableWorkflowCount { get; set; }

        public int ReadOnlyWorkflowCount { get; set; }

        public int WriteWorkflowCount { get; set; }

        public int OutputWorkflowCount { get; set; }

        public int BatchWorkflowCount { get; set; }

        public int InputWorkflowCount { get; set; }

        public int ValueWorkflowCount { get; set; }

        public int ModifiedOutputWorkflowCount { get; set; }

        public int InspectionIssueWorkflowCount { get; set; }

        public bool HasWriteWorkflows { get; set; }

        public bool HasOutputWorkflows { get; set; }

        public bool HasModifiedOutputWorkflows { get; set; }

        public bool HasInspectionIssueWorkflows { get; set; }

        public bool HasOutputs { get; set; }

        public bool HasModifiedOutputs { get; set; }

        public bool HasDomainInspectionIssues { get; set; }

        public IReadOnlyList<KarProjectDomainContextContract> Domains { get; set; }

        public IReadOnlyList<KarProjectToolkitWorkflowContract> Workflows { get; set; }

        public IReadOnlyList<KarProjectToolkitWorkflowGroupContract> WorkflowGroups { get; set; }

        public static KarProjectToolkitSurfaceContract Create(KarProjectToolkitSurface surface)
        {
            if (surface == null)
                throw new ArgumentNullException(nameof(surface));

            return new KarProjectToolkitSurfaceContract
            {
                Project = KarProjectContract.Create(surface.Project),
                Name = surface.Name,
                SourceRoot = surface.SourceRoot,
                OutputRoot = surface.OutputRoot,
                DomainCount = surface.DomainCount,
                WorkflowCount = surface.WorkflowCount,
                WorkflowGroupCount = surface.WorkflowGroupCount,
                AvailableWorkflowCount = surface.AvailableWorkflowCount,
                ReadOnlyWorkflowCount = surface.ReadOnlyWorkflowCount,
                WriteWorkflowCount = surface.WriteWorkflowCount,
                OutputWorkflowCount = surface.OutputWorkflowCount,
                BatchWorkflowCount = surface.BatchWorkflowCount,
                InputWorkflowCount = surface.InputWorkflowCount,
                ValueWorkflowCount = surface.ValueWorkflowCount,
                ModifiedOutputWorkflowCount = surface.ModifiedOutputWorkflowCount,
                InspectionIssueWorkflowCount = surface.InspectionIssueWorkflowCount,
                HasWriteWorkflows = surface.HasWriteWorkflows,
                HasOutputWorkflows = surface.HasOutputWorkflows,
                HasModifiedOutputWorkflows = surface.HasModifiedOutputWorkflows,
                HasInspectionIssueWorkflows = surface.HasInspectionIssueWorkflows,
                HasOutputs = surface.Snapshot.HasOutputs,
                HasModifiedOutputs = surface.Snapshot.HasModifiedOutputs,
                HasDomainInspectionIssues = surface.Snapshot.HasDomainInspectionIssues,
                Domains = surface.Domains.Select(KarProjectDomainContextContract.Create).ToList().AsReadOnly(),
                Workflows = surface.Workflows.Select(KarProjectToolkitWorkflowContract.Create).ToList().AsReadOnly(),
                WorkflowGroups = surface.WorkflowGroups.Select(KarProjectToolkitWorkflowGroupContract.Create).ToList().AsReadOnly(),
            };
        }
    }

    public sealed class KarProjectSessionContract
    {
        public string Name { get; set; }

        public KarProjectContract Project { get; set; }

        public KarProjectWorkspaceContract Workspace { get; set; }

        public string SourceRoot { get; set; }

        public string SourceFilesRoot { get; set; }

        public string OutputRoot { get; set; }

        public string OutputFilesRoot { get; set; }

        public string ReadPolicy { get; set; }

        public string WritePolicy { get; set; }

        public bool ReadsPreferOutputCopies { get; set; }

        public bool WritesOnlyToOutput { get; set; }

        public bool SourceAndOutputRootsAreSeparate { get; set; }

        public bool SourceFilesAndOutputFilesRootsAreSeparate { get; set; }

        public int FileCount { get; set; }

        public int MapCount { get; set; }

        public int DomainCount { get; set; }

        public int WorkflowCount { get; set; }

        public int WorkflowGroupCount { get; set; }

        public int AvailableWorkflowCount { get; set; }

        public int OutputWorkflowCount { get; set; }

        public int RegistryCount { get; set; }

        public int FileKindCount { get; set; }

        public int FileHandlerCount { get; set; }

        public int ResourceHandlerCount { get; set; }

        public int ResourceActionDefinitionCount { get; set; }

        public int OperationDomainRuleCount { get; set; }

        public int DomainContextProviderCount { get; set; }

        public int OperationPresetDefinitionCount { get; set; }

        public bool HasOutputs { get; set; }

        public bool HasModifiedOutputs { get; set; }

        public KarProjectToolkitRegistryCatalogContract RegistryCatalog { get; set; }

        public KarProjectToolkitSurfaceContract Surface { get; set; }

        public static KarProjectSessionContract Create(KarProjectSession session)
        {
            if (session == null)
                throw new ArgumentNullException(nameof(session));

            return new KarProjectSessionContract
            {
                Name = session.Name,
                Project = KarProjectContract.Create(session.Project),
                Workspace = KarProjectWorkspaceContract.Create(session.Workspace),
                SourceRoot = session.SourceRoot,
                SourceFilesRoot = session.SourceFilesRoot,
                OutputRoot = session.OutputRoot,
                OutputFilesRoot = session.OutputFilesRoot,
                ReadPolicy = session.ReadPolicy,
                WritePolicy = session.WritePolicy,
                ReadsPreferOutputCopies = session.ReadsPreferOutputCopies,
                WritesOnlyToOutput = session.WritesOnlyToOutput,
                SourceAndOutputRootsAreSeparate = session.SourceAndOutputRootsAreSeparate,
                SourceFilesAndOutputFilesRootsAreSeparate = session.SourceFilesAndOutputFilesRootsAreSeparate,
                FileCount = session.FileCount,
                MapCount = session.MapCount,
                DomainCount = session.DomainCount,
                WorkflowCount = session.WorkflowCount,
                WorkflowGroupCount = session.Surface.WorkflowGroupCount,
                AvailableWorkflowCount = session.AvailableWorkflowCount,
                OutputWorkflowCount = session.OutputWorkflowCount,
                RegistryCount = session.RegistryCount,
                FileKindCount = session.FileKindCount,
                FileHandlerCount = session.FileHandlerCount,
                ResourceHandlerCount = session.ResourceHandlerCount,
                ResourceActionDefinitionCount = session.ResourceActionDefinitionCount,
                OperationDomainRuleCount = session.OperationDomainRuleCount,
                DomainContextProviderCount = session.DomainContextProviderCount,
                OperationPresetDefinitionCount = session.OperationPresetDefinitionCount,
                HasOutputs = session.HasOutputs,
                HasModifiedOutputs = session.HasModifiedOutputs,
                RegistryCatalog = session.RegistryCatalog.CreateContract(),
                Surface = session.Surface.CreateContract(),
            };
        }
    }
}
