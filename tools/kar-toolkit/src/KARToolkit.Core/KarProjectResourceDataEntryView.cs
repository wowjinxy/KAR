using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceDataEntryView
    {
        internal KarProjectResourceDataEntryView(
            KarProjectResourceInfo resource,
            string parentFieldPath,
            KarDataReferenceEntry entry,
            int depth)
        {
            Resource = resource ?? throw new ArgumentNullException(nameof(resource));
            Entry = entry ?? throw new ArgumentNullException(nameof(entry));
            ParentFieldPath = parentFieldPath ?? throw new ArgumentNullException(nameof(parentFieldPath));
            Depth = depth;
            EntryPath = ParentFieldPath + "[" + entry.Index.ToString(CultureInfo.InvariantCulture) + "]";
            Fields = entry.FieldValues
                .Select(value => new KarProjectResourceDataFieldView(
                    resource,
                    value,
                    EntryPath + "." + value.Field.Name,
                    depth + 1,
                    false))
                .ToList()
                .AsReadOnly();
        }

        public KarProjectResourceInfo Resource { get; }

        public KarResourceReference Reference => Resource.Reference;

        public string Address => Resource.Address;

        public KarDataReferenceEntry Entry { get; }

        public string ParentFieldPath { get; }

        public string EntryPath { get; }

        public int Depth { get; }

        public int Index => Entry.Index;

        public int Offset => Entry.Offset;

        public string OffsetHex => Entry.OffsetHex;

        public IReadOnlyList<KarProjectResourceDataFieldView> Fields { get; }

        public int FieldCount => Fields.Count;

        public int TotalFieldCount => Fields.Sum(field => field.TotalFieldCount);

        public bool HasFields => FieldCount != 0;
    }
}
