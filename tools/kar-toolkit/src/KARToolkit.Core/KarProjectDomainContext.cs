using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectDomainContext
    {
        internal KarProjectDomainContext(
            string id,
            string displayName,
            string description,
            string listCommand,
            string contextCommand,
            int itemCount,
            int resourceCount,
            int outputCount,
            int modifiedOutputCount,
            int inspectionIssueCount)
        {
            if (string.IsNullOrWhiteSpace(id))
                throw new ArgumentException("Domain id cannot be empty.", nameof(id));
            if (string.IsNullOrWhiteSpace(displayName))
                throw new ArgumentException("Domain display name cannot be empty.", nameof(displayName));

            Id = id;
            DisplayName = displayName;
            Description = description ?? "";
            ListCommand = listCommand;
            ContextCommand = contextCommand;
            ItemCount = itemCount;
            ResourceCount = resourceCount;
            OutputCount = outputCount;
            ModifiedOutputCount = modifiedOutputCount;
            InspectionIssueCount = inspectionIssueCount;
        }

        public string Id { get; }

        public string DisplayName { get; }

        public string Description { get; }

        public string ListCommand { get; }

        public string ContextCommand { get; }

        public int ItemCount { get; }

        public int ResourceCount { get; }

        public int OutputCount { get; }

        public int ModifiedOutputCount { get; }

        public int InspectionIssueCount { get; }

        public bool HasItems => ItemCount != 0;

        public bool HasResources => ResourceCount != 0;

        public bool HasOutputs => OutputCount != 0;

        public bool HasModifiedOutputs => ModifiedOutputCount != 0;

        public bool HasInspectionIssues => InspectionIssueCount != 0;
    }
}
