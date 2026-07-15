using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectFieldSummary
    {
        internal KarProjectFieldSummary(
            KarDataDefinition dataDefinition,
            KarDataFieldDefinition field,
            IEnumerable<KarProjectFieldInfo> fields)
        {
            DataDefinition = dataDefinition ?? throw new ArgumentNullException(nameof(dataDefinition));
            Field = field ?? throw new ArgumentNullException(nameof(field));
            Fields = (fields ?? throw new ArgumentNullException(nameof(fields)))
                .OrderBy(value => value.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ThenBy(value => value.RootName, StringComparer.Ordinal)
                .ToList()
                .AsReadOnly();
            Files = Fields
                .Select(value => value.File)
                .GroupBy(file => file.RelativePath, StringComparer.OrdinalIgnoreCase)
                .Select(group => group.First())
                .OrderBy(file => file.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
            DistinctValues = Fields
                .GroupBy(value => CreateValueKey(value.Value), StringComparer.Ordinal)
                .Select(group => new KarProjectFieldDistinctValue(group.First().Value, group))
                .OrderByDescending(value => value.Count)
                .ThenBy(value => value.DisplayValue, StringComparer.Ordinal)
                .ToList()
                .AsReadOnly();
        }

        public KarDataDefinition DataDefinition { get; }

        public string DataDefinitionId => DataDefinition.Id;

        public string DisplayName => DataDefinition.DisplayName;

        public string Category => DataDefinition.Category;

        public string AccessorTypeName => DataDefinition.AccessorTypeName;

        public KarDataFieldDefinition Field { get; }

        public string FieldName => Field.Name;

        public string TypeName => Field.TypeName;

        public IReadOnlyList<KarProjectFieldInfo> Fields { get; }

        public IReadOnlyList<KarProjectFile> Files { get; }

        public IReadOnlyList<KarProjectFieldDistinctValue> DistinctValues { get; }

        public int Count => Fields.Count;

        public int FileCount => Files.Count;

        public int AvailableCount => Fields.Count(value => value.Value.IsAvailable);

        public int UnavailableCount => Count - AvailableCount;

        public int DistinctValueCount => DistinctValues.Count;

        public bool HasValueVariation => DistinctValueCount > 1;

        private static string CreateValueKey(KarDataFieldValue value)
        {
            return (value.ValueKind ?? "") +
                "\u001F" + (value.DisplayValue ?? "") +
                "\u001F" + (value.Error ?? "");
        }
    }
}
