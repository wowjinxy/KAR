using HSDRaw;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;

namespace KARToolkit.Core
{
    public static class KarDataInspector
    {
        public static IReadOnlyList<KarDataFieldValue> InspectFields(HSDAccessor accessor, KarDataDefinition definition)
        {
            return InspectFields(accessor, definition, null, null);
        }

        public static IReadOnlyList<KarDataFieldValue> InspectFields(
            HSDAccessor accessor,
            KarDataDefinition definition,
            KarDataDefinitionRegistry dataDefinitions,
            KarDataInspectionOptions options = null)
        {
            int maxReferenceDepth = options == null ? 1 : Math.Max(0, options.MaxReferenceDepth);
            int maxReferenceEntries = options == null ? 8 : Math.Max(0, options.MaxReferenceEntries);
            return InspectFields(accessor, definition, dataDefinitions, maxReferenceDepth, maxReferenceEntries, new HashSet<HSDStruct>());
        }

        private static IReadOnlyList<KarDataFieldValue> InspectFields(
            HSDAccessor accessor,
            KarDataDefinition definition,
            KarDataDefinitionRegistry dataDefinitions,
            int remainingReferenceDepth,
            int maxReferenceEntries,
            HashSet<HSDStruct> visited)
        {
            if (accessor == null || accessor._s == null || definition == null)
                return Array.Empty<KarDataFieldValue>();
            if (!visited.Add(accessor._s))
                return Array.Empty<KarDataFieldValue>();

            return definition.Fields
                .Select(field => InspectField(accessor, field, dataDefinitions, remainingReferenceDepth, maxReferenceEntries, visited))
                .ToList()
                .AsReadOnly();
        }

        public static KarDataFieldValue InspectField(HSDAccessor accessor, KarDataFieldDefinition field)
        {
            return InspectField(accessor, field, null, 0, 0, new HashSet<HSDStruct>());
        }

        private static KarDataFieldValue InspectField(
            HSDAccessor accessor,
            KarDataFieldDefinition field,
            KarDataDefinitionRegistry dataDefinitions,
            int remainingReferenceDepth,
            int maxReferenceEntries,
            HashSet<HSDStruct> visited)
        {
            if (!field.Offset.HasValue)
                return new KarDataFieldValue(field, false, "unknown", "<not mapped>");

            int offset = field.Offset.Value;
            if (offset < 0)
                return new KarDataFieldValue(field, false, "error", "<invalid offset>", error: "Field offset is negative.");

            if (field.IsPointer)
                return InspectReference(accessor, field, offset, dataDefinitions, remainingReferenceDepth, maxReferenceEntries, visited);

            KarDataScalarKind kind;
            int size;
            if (!KarDataScalarTypes.TryResolve(field.TypeName, out kind, out size))
                return new KarDataFieldValue(field, false, "unread", "<unsupported type>");

            try
            {
                switch (kind)
                {
                    case KarDataScalarKind.Signed:
                        return ReadSigned(accessor, field, offset, size);
                    case KarDataScalarKind.Unsigned:
                        return ReadUnsigned(accessor, field, offset, size);
                    case KarDataScalarKind.Float:
                        return ReadFloat(accessor, field, offset);
                    default:
                        return new KarDataFieldValue(field, false, "unread", "<unsupported type>");
                }
            }
            catch (Exception ex)
            {
                return new KarDataFieldValue(field, false, "error", "<read failed>", error: ex.Message);
            }
        }

        private static KarDataFieldValue InspectReference(
            HSDAccessor accessor,
            KarDataFieldDefinition field,
            int offset,
            KarDataDefinitionRegistry dataDefinitions,
            int remainingReferenceDepth,
            int maxReferenceEntries,
            HashSet<HSDStruct> visited)
        {
            if (!IsInRange(accessor, offset, 4))
                return new KarDataFieldValue(field, false, "reference", "<out of range>", hasReference: false);

            HSDStruct reference;
            if (!accessor._s.References.TryGetValue(offset, out reference) || reference == null)
                return new KarDataFieldValue(field, true, "reference", "null", hasReference: false);

            KarDataDefinition referenceDefinition = ResolveReferenceDefinition(field, dataDefinitions);
            IReadOnlyList<KarDataFieldValue> referenceFieldValues = Array.Empty<KarDataFieldValue>();
            IReadOnlyList<KarDataReferenceEntry> referenceEntries = Array.Empty<KarDataReferenceEntry>();
            int? referenceEntryTotalCount = null;
            if (referenceDefinition != null && !visited.Contains(reference))
            {
                if (CanInspectReferenceEntries(field, referenceDefinition, reference, maxReferenceEntries))
                {
                    referenceEntries = InspectReferenceEntries(
                        reference,
                        referenceDefinition,
                        dataDefinitions,
                        remainingReferenceDepth,
                        maxReferenceEntries,
                        visited,
                        out referenceEntryTotalCount);
                }
                else if (remainingReferenceDepth > 0)
                {
                    referenceFieldValues = InspectFields(
                        new HSDAccessor { _s = reference },
                        referenceDefinition,
                        dataDefinitions,
                        remainingReferenceDepth - 1,
                        maxReferenceEntries,
                        visited);
                }
            }

            return new KarDataFieldValue(
                field,
                true,
                "reference",
                "ref length=" + FormatHex(reference.Length),
                hasReference: true,
                referenceLength: reference.Length,
                referenceDataDefinition: referenceDefinition,
                referenceFieldValues: referenceFieldValues,
                referenceEntries: referenceEntries,
                referenceEntryTotalCount: referenceEntryTotalCount);
        }

        private static bool CanInspectReferenceEntries(
            KarDataFieldDefinition field,
            KarDataDefinition referenceDefinition,
            HSDStruct reference,
            int maxReferenceEntries)
        {
            if (maxReferenceEntries == 0 ||
                referenceDefinition == null ||
                !referenceDefinition.Size.HasValue ||
                referenceDefinition.Size.Value <= 0 ||
                reference == null)
            {
                return false;
            }

            int entrySize = referenceDefinition.Size.Value;
            if (reference.Length < entrySize || reference.Length % entrySize != 0)
                return false;

            return reference.Length != entrySize || LooksLikeReferenceTable(field.TypeName);
        }

        private static IReadOnlyList<KarDataReferenceEntry> InspectReferenceEntries(
            HSDStruct reference,
            KarDataDefinition referenceDefinition,
            KarDataDefinitionRegistry dataDefinitions,
            int remainingReferenceDepth,
            int maxReferenceEntries,
            HashSet<HSDStruct> visited,
            out int? referenceEntryTotalCount)
        {
            int entrySize = referenceDefinition.Size.Value;
            int totalEntryCount = reference.Length / entrySize;
            int entryCount = Math.Min(totalEntryCount, maxReferenceEntries);
            List<KarDataReferenceEntry> entries = new List<KarDataReferenceEntry>();

            referenceEntryTotalCount = totalEntryCount;
            for (int i = 0; i < entryCount; i++)
            {
                int offset = i * entrySize;
                HSDStruct entryStruct = reference.GetEmbeddedStruct(offset, entrySize);
                IReadOnlyList<KarDataFieldValue> fieldValues = InspectFields(
                    new HSDAccessor { _s = entryStruct },
                    referenceDefinition,
                    dataDefinitions,
                    remainingReferenceDepth,
                    maxReferenceEntries,
                    visited);

                entries.Add(new KarDataReferenceEntry(i, offset, fieldValues));
            }

            return entries.AsReadOnly();
        }

        private static bool LooksLikeReferenceTable(string typeName)
        {
            if (string.IsNullOrWhiteSpace(typeName))
                return false;

            return typeName.IndexOf("Array", StringComparison.OrdinalIgnoreCase) >= 0;
        }

        private static KarDataDefinition ResolveReferenceDefinition(KarDataFieldDefinition field, KarDataDefinitionRegistry dataDefinitions)
        {
            if (dataDefinitions == null)
                return null;

            KarDataDefinition definition;
            if (!string.IsNullOrWhiteSpace(field.DataDefinitionId) &&
                dataDefinitions.TryGet(field.DataDefinitionId, out definition))
            {
                return definition;
            }

            if (dataDefinitions.TryFind(field.TypeName, out definition))
                return definition;

            return null;
        }

        private static KarDataFieldValue ReadSigned(HSDAccessor accessor, KarDataFieldDefinition field, int offset, int size)
        {
            if (!IsInRange(accessor, offset, size))
                return new KarDataFieldValue(field, false, "signed", "<out of range>");

            long value;
            switch (size)
            {
                case 1:
                    value = unchecked((sbyte)accessor._s.GetByte(offset));
                    break;
                case 2:
                    value = accessor._s.GetInt16(offset);
                    break;
                case 4:
                    value = accessor._s.GetInt32(offset);
                    break;
                default:
                    throw new NotSupportedException("Unsupported signed integer size: " + size);
            }

            return new KarDataFieldValue(
                field,
                true,
                "signed",
                value.ToString(CultureInfo.InvariantCulture) + " (" + FormatHex(unchecked((ulong)value), size) + ")",
                signedValue: value,
                unsignedValue: unchecked((ulong)value));
        }

        private static KarDataFieldValue ReadUnsigned(HSDAccessor accessor, KarDataFieldDefinition field, int offset, int size)
        {
            if (!IsInRange(accessor, offset, size))
                return new KarDataFieldValue(field, false, "unsigned", "<out of range>");

            ulong value;
            switch (size)
            {
                case 1:
                    value = accessor._s.GetByte(offset);
                    break;
                case 2:
                    value = accessor._s.GetUInt16(offset);
                    break;
                case 4:
                    value = accessor._s.GetUInt32(offset);
                    break;
                default:
                    throw new NotSupportedException("Unsupported unsigned integer size: " + size);
            }

            return new KarDataFieldValue(
                field,
                true,
                "unsigned",
                value.ToString(CultureInfo.InvariantCulture) + " (" + FormatHex(value, size) + ")",
                unsignedValue: value);
        }

        private static KarDataFieldValue ReadFloat(HSDAccessor accessor, KarDataFieldDefinition field, int offset)
        {
            if (!IsInRange(accessor, offset, 4))
                return new KarDataFieldValue(field, false, "float", "<out of range>");

            float value = accessor._s.GetFloat(offset);
            return new KarDataFieldValue(
                field,
                true,
                "float",
                value.ToString("R", CultureInfo.InvariantCulture),
                floatValue: value);
        }

        private static bool IsInRange(HSDAccessor accessor, int offset, int size)
        {
            return accessor != null &&
                accessor._s != null &&
                offset >= 0 &&
                size >= 0 &&
                offset + size <= accessor._s.Length;
        }

        private static string FormatHex(int value)
        {
            return "0x" + value.ToString("X", CultureInfo.InvariantCulture);
        }

        private static string FormatHex(ulong value, int size)
        {
            int width = Math.Max(size * 2, 2);
            ulong mask;
            switch (size)
            {
                case 1:
                    mask = 0xFF;
                    break;
                case 2:
                    mask = 0xFFFF;
                    break;
                case 4:
                    mask = 0xFFFFFFFF;
                    break;
                default:
                    mask = ulong.MaxValue;
                    break;
            }

            return "0x" + (value & mask).ToString("X" + width, CultureInfo.InvariantCulture);
        }
    }
}
