using HSDRaw;
using System;

namespace KARToolkit.Core
{
    public static class KarDataEditor
    {
        public static KarDataFieldEditResult SetScalarField(
            HSDAccessor accessor,
            KarDataDefinition dataDefinition,
            string fieldName,
            long value)
        {
            return SetScalarField(accessor, null, dataDefinition, fieldName, value);
        }

        public static KarDataFieldEditResult SetScalarField(
            HSDAccessor accessor,
            KarDataDefinition dataDefinition,
            string fieldName,
            double value)
        {
            return SetScalarField(accessor, null, dataDefinition, fieldName, value);
        }

        internal static KarDataFieldEditResult SetScalarField(
            HSDAccessor accessor,
            string rootName,
            KarDataDefinition dataDefinition,
            string fieldName,
            long value)
        {
            if (dataDefinition == null)
                throw new ArgumentNullException(nameof(dataDefinition));

            return SetScalarField(accessor, rootName, dataDefinition, dataDefinition.GetField(fieldName), value);
        }

        internal static KarDataFieldEditResult SetScalarField(
            HSDAccessor accessor,
            string rootName,
            KarDataDefinition dataDefinition,
            string fieldName,
            double value)
        {
            if (dataDefinition == null)
                throw new ArgumentNullException(nameof(dataDefinition));

            return SetScalarField(accessor, rootName, dataDefinition, dataDefinition.GetField(fieldName), value);
        }

        public static KarDataFieldEditResult SetScalarField(
            HSDAccessor accessor,
            KarDataDefinition dataDefinition,
            KarDataFieldDefinition field,
            long value)
        {
            return SetScalarField(accessor, null, dataDefinition, field, value);
        }

        public static KarDataFieldEditResult SetScalarField(
            HSDAccessor accessor,
            KarDataDefinition dataDefinition,
            KarDataFieldDefinition field,
            double value)
        {
            return SetScalarField(accessor, null, dataDefinition, field, value);
        }

        internal static KarDataFieldEditResult SetScalarField(
            HSDAccessor accessor,
            string rootName,
            KarDataDefinition dataDefinition,
            KarDataFieldDefinition field,
            long value)
        {
            KarDataScalarKind kind;
            int size;
            int offset = ValidateWritableScalar(accessor, field, out kind, out size);
            if (kind == KarDataScalarKind.Float)
                throw new InvalidOperationException("Use the floating-point overload to edit field: " + field.Name);

            KarDataFieldValue previousValue = KarDataInspector.InspectField(accessor, field);
            if (kind == KarDataScalarKind.Signed)
                WriteSigned(accessor, offset, size, value);
            else
                WriteUnsigned(accessor, offset, size, value);

            return new KarDataFieldEditResult(
                rootName,
                dataDefinition,
                field,
                previousValue,
                KarDataInspector.InspectField(accessor, field));
        }

        internal static KarDataFieldEditResult SetScalarField(
            HSDAccessor accessor,
            string rootName,
            KarDataDefinition dataDefinition,
            KarDataFieldDefinition field,
            double value)
        {
            KarDataScalarKind kind;
            int size;
            int offset = ValidateWritableScalar(accessor, field, out kind, out size);
            if (kind != KarDataScalarKind.Float)
                throw new InvalidOperationException("Use the integer overload to edit field: " + field.Name);

            if (double.IsNaN(value) || double.IsInfinity(value) || value < -float.MaxValue || value > float.MaxValue)
                throw new ArgumentOutOfRangeException(nameof(value), "Floating-point field value is outside the supported f32 range.");

            KarDataFieldValue previousValue = KarDataInspector.InspectField(accessor, field);
            accessor._s.SetFloat(offset, (float)value);

            return new KarDataFieldEditResult(
                rootName,
                dataDefinition,
                field,
                previousValue,
                KarDataInspector.InspectField(accessor, field));
        }

        private static int ValidateWritableScalar(
            HSDAccessor accessor,
            KarDataFieldDefinition field,
            out KarDataScalarKind kind,
            out int size)
        {
            if (accessor == null)
                throw new ArgumentNullException(nameof(accessor));
            if (accessor._s == null)
                throw new InvalidOperationException("Accessor has no backing HSD struct.");
            if (field == null)
                throw new ArgumentNullException(nameof(field));
            if (!field.Offset.HasValue)
                throw new InvalidOperationException("Field does not have a mapped offset: " + field.Name);
            if (field.IsPointer)
                throw new InvalidOperationException("Pointer fields are not editable through scalar writes: " + field.Name);
            if (!KarDataScalarTypes.TryResolve(field.TypeName, out kind, out size))
                throw new NotSupportedException("Field type is not a supported scalar type: " + field.TypeName);

            int offset = field.Offset.Value;
            if (offset < 0 || size <= 0 || offset > accessor._s.Length - size)
                throw new ArgumentOutOfRangeException(nameof(field), "Field offset is outside the backing HSD struct.");

            return offset;
        }

        private static void WriteSigned(HSDAccessor accessor, int offset, int size, long value)
        {
            long min;
            long max;
            switch (size)
            {
                case 1:
                    min = sbyte.MinValue;
                    max = sbyte.MaxValue;
                    break;
                case 2:
                    min = short.MinValue;
                    max = short.MaxValue;
                    break;
                case 4:
                    min = int.MinValue;
                    max = int.MaxValue;
                    break;
                default:
                    throw new NotSupportedException("Unsupported signed scalar size: " + size);
            }

            if (value < min || value > max)
                throw new ArgumentOutOfRangeException(nameof(value), "Signed field value is outside the supported range.");

            switch (size)
            {
                case 1:
                    accessor._s.SetByte(offset, unchecked((byte)(sbyte)value));
                    break;
                case 2:
                    accessor._s.SetInt16(offset, (short)value);
                    break;
                case 4:
                    accessor._s.SetInt32(offset, (int)value);
                    break;
            }
        }

        private static void WriteUnsigned(HSDAccessor accessor, int offset, int size, long value)
        {
            ulong max;
            switch (size)
            {
                case 1:
                    max = byte.MaxValue;
                    break;
                case 2:
                    max = ushort.MaxValue;
                    break;
                case 4:
                    max = uint.MaxValue;
                    break;
                default:
                    throw new NotSupportedException("Unsupported unsigned scalar size: " + size);
            }

            if (value < 0 || (ulong)value > max)
                throw new ArgumentOutOfRangeException(nameof(value), "Unsigned field value is outside the supported range.");

            switch (size)
            {
                case 1:
                    accessor._s.SetByte(offset, (byte)value);
                    break;
                case 2:
                    accessor._s.SetUInt16(offset, (ushort)value);
                    break;
                case 4:
                    accessor._s.SetUInt32(offset, (uint)value);
                    break;
            }
        }
    }
}
