using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarDataDefinition
    {
        public KarDataDefinition(
            string id,
            string displayName,
            string category,
            string accessorTypeName,
            string description,
            string source,
            IEnumerable<KarDataFieldDefinition> fields)
        {
            if (string.IsNullOrWhiteSpace(id))
                throw new ArgumentException("Definition id cannot be empty.", nameof(id));
            if (string.IsNullOrWhiteSpace(displayName))
                throw new ArgumentException("Display name cannot be empty.", nameof(displayName));

            Id = id;
            DisplayName = displayName;
            Category = category;
            AccessorTypeName = accessorTypeName;
            Description = description;
            Source = source;
            Fields = (fields ?? Enumerable.Empty<KarDataFieldDefinition>())
                .ToList()
                .AsReadOnly();
        }

        public string Id { get; }

        public string DisplayName { get; }

        public string Category { get; }

        public string AccessorTypeName { get; }

        public string Description { get; }

        public string Source { get; }

        public IReadOnlyList<KarDataFieldDefinition> Fields { get; }

        public KarDataFieldDefinition GetField(string name)
        {
            KarDataFieldDefinition field;
            if (!TryGetField(name, out field))
                throw new KeyNotFoundException("KAR data field was not found: " + name);

            return field;
        }

        public bool TryGetField(string name, out KarDataFieldDefinition field)
        {
            field = null;
            if (string.IsNullOrWhiteSpace(name))
                return false;

            field = Fields.FirstOrDefault(candidate =>
                string.Equals(candidate.Name, name, StringComparison.OrdinalIgnoreCase));
            return field != null;
        }
    }
}
