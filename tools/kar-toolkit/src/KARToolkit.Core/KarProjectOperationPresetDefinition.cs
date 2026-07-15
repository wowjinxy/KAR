using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectOperationPresetDefinition
    {
        public KarProjectOperationPresetDefinition(
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
            bool? hasModifiedOutputs)
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

        public KarProjectOperationQueryOptions CreateQueryOptions()
        {
            return new KarProjectOperationQueryOptions
            {
                IncludeWorkflows = false,
                IncludeResourceActions = true,
                Kind = KarProjectOperationKind.ResourceAction,
                DomainId = DomainId,
                ActionId = ActionId,
                ResourceKind = ResourceKind,
                IsReadOnly = IsReadOnly,
                WritesOutput = WritesOutput,
                SupportsBatch = SupportsBatch,
                RequiresInputFile = RequiresInputFile,
                RequiresFieldName = RequiresFieldName,
                RequiresValue = RequiresValue,
                CanRun = CanRun,
                WouldWriteOutput = WouldWriteOutput,
                HasModifiedOutputs = HasModifiedOutputs,
            };
        }
    }
}
