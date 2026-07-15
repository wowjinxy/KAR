using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceAction
    {
        internal KarProjectResourceAction(KarProjectResourceActionDefinition definition)
            : this(
                RequireDefinition(definition).Id,
                definition.DisplayName,
                definition.Description,
                definition.Capability,
                definition.Command,
                definition.ArgumentHint,
                definition.IsReadOnly,
                definition.WritesOutput,
                definition.RequiresInputFile,
                definition.RequiresFieldName,
                definition.RequiresValue,
                definition.SupportsBatch,
                definition.ExecutionKind,
                definition.PlanStateKind,
                definition.WritePolicy)
        {
        }

        internal KarProjectResourceAction(
            string id,
            string displayName,
            string description,
            KarProjectResourceCapability capability,
            string command,
            string argumentHint,
            bool isReadOnly,
            bool writesOutput,
            bool requiresInputFile,
            bool requiresFieldName,
            bool requiresValue,
            bool supportsBatch,
            KarProjectResourceActionExecutionKind executionKind = KarProjectResourceActionExecutionKind.None,
            KarProjectResourceActionPlanStateKind planStateKind = KarProjectResourceActionPlanStateKind.None,
            KarProjectResourceActionWritePolicy writePolicy = KarProjectResourceActionWritePolicy.None)
        {
            if (string.IsNullOrWhiteSpace(id))
                throw new ArgumentException("Resource action id cannot be empty.", nameof(id));
            if (string.IsNullOrWhiteSpace(displayName))
                throw new ArgumentException("Resource action display name cannot be empty.", nameof(displayName));
            if (capability == KarProjectResourceCapability.None)
                throw new ArgumentException("Resource action capability cannot be None.", nameof(capability));

            Id = id;
            DisplayName = displayName;
            Description = description ?? "";
            Capability = capability;
            Command = command;
            ArgumentHint = argumentHint;
            IsReadOnly = isReadOnly;
            WritesOutput = writesOutput;
            RequiresInputFile = requiresInputFile;
            RequiresFieldName = requiresFieldName;
            RequiresValue = requiresValue;
            SupportsBatch = supportsBatch;
            ExecutionKind = executionKind;
            PlanStateKind = planStateKind;
            WritePolicy = writePolicy;
        }

        public string Id { get; }

        public string DisplayName { get; }

        public string Description { get; }

        public KarProjectResourceCapability Capability { get; }

        public string CapabilityName => Capability.ToString();

        public string Command { get; }

        public string ArgumentHint { get; }

        public bool IsReadOnly { get; }

        public bool WritesOutput { get; }

        public bool RequiresInputFile { get; }

        public bool RequiresFieldName { get; }

        public bool RequiresValue { get; }

        public bool SupportsBatch { get; }

        public KarProjectResourceActionExecutionKind ExecutionKind { get; }

        public string ExecutionKindName => ExecutionKind.ToString();

        public KarProjectResourceActionPlanStateKind PlanStateKind { get; }

        public string PlanStateKindName => PlanStateKind.ToString();

        public KarProjectResourceActionWritePolicy WritePolicy { get; }

        public string WritePolicyName => WritePolicy.ToString();

        public bool RequiresOutputInfo => PlanStateKind == KarProjectResourceActionPlanStateKind.Output;

        public bool RequiresByteInfo => PlanStateKind == KarProjectResourceActionPlanStateKind.Bytes;

        private static KarProjectResourceActionDefinition RequireDefinition(KarProjectResourceActionDefinition definition)
        {
            if (definition == null)
                throw new ArgumentNullException(nameof(definition));

            return definition;
        }
    }
}
