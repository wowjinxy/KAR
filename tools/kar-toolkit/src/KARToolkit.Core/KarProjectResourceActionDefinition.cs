using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceActionDefinition
    {
        public KarProjectResourceActionDefinition(
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

        public KarProjectResourceActionPlanStateKind PlanStateKind { get; }

        public string PlanStateKindName => PlanStateKind.ToString();

        public KarProjectResourceActionWritePolicy WritePolicy { get; }

        public string WritePolicyName => WritePolicy.ToString();

        public bool RequiresOutputInfo => PlanStateKind == KarProjectResourceActionPlanStateKind.Output;

        public bool RequiresByteInfo => PlanStateKind == KarProjectResourceActionPlanStateKind.Bytes;

        internal KarProjectResourceAction CreateAction()
        {
            return new KarProjectResourceAction(this);
        }
    }
}
