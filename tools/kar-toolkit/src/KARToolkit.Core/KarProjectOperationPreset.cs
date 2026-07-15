using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectOperationPreset
    {
        internal KarProjectOperationPreset(
            KarProjectOperationPresetDefinition definition,
            KarProjectOperationCatalog operations)
            : this(
                RequireDefinition(definition).Id,
                definition.DomainId,
                definition.DisplayName,
                definition.Description,
                definition.ActionId,
                definition.ResourceKind,
                definition.IsReadOnly,
                definition.WritesOutput,
                definition.SupportsBatch,
                definition.RequiresInputFile,
                definition.RequiresFieldName,
                definition.RequiresValue,
                definition.CanRun,
                definition.WouldWriteOutput,
                definition.HasModifiedOutputs,
                operations)
        {
        }

        internal KarProjectOperationPreset(
            string id,
            string domainId,
            string displayName,
            string description,
            string actionId,
            KarResourceKind? resourceKind,
            bool isReadOnly,
            bool writesOutput,
            bool supportsBatch,
            bool requiresInputFile,
            bool requiresFieldName,
            bool requiresValue,
            bool? canRun,
            bool? wouldWriteOutput,
            bool? hasModifiedOutputs,
            KarProjectOperationCatalog operations)
        {
            if (string.IsNullOrWhiteSpace(id))
                throw new ArgumentException("Operation preset id cannot be empty.", nameof(id));
            if (string.IsNullOrWhiteSpace(displayName))
                throw new ArgumentException("Operation preset display name cannot be empty.", nameof(displayName));
            if (string.IsNullOrWhiteSpace(actionId))
                throw new ArgumentException("Operation preset action id cannot be empty.", nameof(actionId));

            Id = id;
            DomainId = domainId ?? "";
            DisplayName = displayName;
            Description = description ?? "";
            ActionId = actionId;
            ResourceKind = resourceKind;
            IsReadOnly = isReadOnly;
            WritesOutput = writesOutput;
            SupportsBatch = supportsBatch;
            RequiresInputFile = requiresInputFile;
            RequiresFieldName = requiresFieldName;
            RequiresValue = requiresValue;
            CanRun = canRun;
            WouldWriteOutput = wouldWriteOutput;
            HasModifiedOutputs = hasModifiedOutputs;
            Operations = operations ?? throw new ArgumentNullException(nameof(operations));
        }

        public string Id { get; }

        public string DomainId { get; }

        public string DisplayName { get; }

        public string Description { get; }

        public string ActionId { get; }

        public KarResourceKind? ResourceKind { get; }

        public bool IsReadOnly { get; }

        public bool WritesOutput { get; }

        public bool SupportsBatch { get; }

        public bool RequiresInputFile { get; }

        public bool RequiresFieldName { get; }

        public bool RequiresValue { get; }

        public bool? CanRun { get; }

        public bool? WouldWriteOutput { get; }

        public bool? HasModifiedOutputs { get; }

        public KarProjectOperationCatalog Operations { get; }

        public string Mode => IsReadOnly ? "read" : "write";

        public string OperationUsage => CreateOperationUsage();

        public string OperationJsonUsage => OperationUsage + " --json";

        public string BatchUsage => SupportsBatch
            ? "kar-toolkit operation-batch <source-folder> " + ActionId + CreateBatchFilterUsage()
            : null;

        public string BatchJsonUsage => BatchUsage == null ? null : BatchUsage + " --json";

        public int OperationCount => Operations.OperationCount;

        public int RunnableOperationCount => Operations.RunnableOperationCount;

        public int OutputOperationCount => Operations.OutputOperationCount;

        public int ModifiedOutputOperationCount => Operations.ModifiedOutputOperationCount;

        public bool HasOperations => Operations.HasOperations;

        public bool HasRunnableOperations => Operations.HasRunnableOperations;

        public bool HasOutputOperations => Operations.HasOutputOperations;

        public bool HasModifiedOutputOperations => Operations.HasModifiedOutputOperations;

        public KarProjectOperationPresetContract CreateContract()
        {
            return KarProjectOperationPresetContract.Create(this);
        }

        public KarProjectOperationQueryOptions CreateQueryOptions()
        {
            return new KarProjectOperationPresetDefinition(
                Id,
                DomainId,
                DisplayName,
                Description,
                ActionId,
                ResourceKind,
                IsReadOnly,
                WritesOutput,
                SupportsBatch,
                RequiresInputFile,
                RequiresFieldName,
                RequiresValue,
                CanRun,
                WouldWriteOutput,
                HasModifiedOutputs)
                .CreateQueryOptions();
        }

        private string CreateOperationUsage()
        {
            string usage = "kar-toolkit operations <source-folder>";
            usage += CreateFilterUsage();
            return usage;
        }

        private string CreateBatchFilterUsage()
        {
            string usage = "";
            if (!string.IsNullOrWhiteSpace(DomainId))
                usage += " --domain " + DomainId;
            if (ResourceKind.HasValue)
                usage += " --resource-kind " + ResourceKind.Value.ToString().ToLowerInvariant();
            if (WouldWriteOutput == true)
                usage += " --would-write";
            if (WouldWriteOutput == false)
                usage += " --would-skip";

            return usage;
        }

        private string CreateFilterUsage()
        {
            string usage = CreateBatchFilterUsage();
            usage += " --action " + ActionId;
            if (IsReadOnly)
                usage += " --read-only";
            else if (WritesOutput)
                usage += " --writes-output";
            if (SupportsBatch)
                usage += " --batch";
            else
                usage += " --single";
            if (CanRun == true)
                usage += " --can-run";
            if (CanRun == false)
                usage += " --cannot-run";
            if (HasModifiedOutputs == true)
                usage += " --modified";

            return usage;
        }

        private static KarProjectOperationPresetDefinition RequireDefinition(KarProjectOperationPresetDefinition definition)
        {
            if (definition == null)
                throw new ArgumentNullException(nameof(definition));

            return definition;
        }
    }
}
