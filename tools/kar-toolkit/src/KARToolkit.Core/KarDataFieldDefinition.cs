using System;

namespace KARToolkit.Core
{
    public sealed class KarDataFieldDefinition
    {
        public KarDataFieldDefinition(
            string name,
            int? offset,
            string typeName,
            string description,
            bool isPointer = false,
            string dataDefinitionId = null)
        {
            if (string.IsNullOrWhiteSpace(name))
                throw new ArgumentException("Field name cannot be empty.", nameof(name));

            Name = name;
            Offset = offset;
            TypeName = typeName;
            Description = description;
            IsPointer = isPointer;
            DataDefinitionId = dataDefinitionId;
        }

        public string Name { get; }

        public int? Offset { get; }

        public string OffsetHex => Offset.HasValue ? "0x" + Offset.Value.ToString("X2") : null;

        public string TypeName { get; }

        public string Description { get; }

        public bool IsPointer { get; }

        public string DataDefinitionId { get; }

        public bool IsScalar
        {
            get
            {
                KarDataScalarKind kind;
                int size;
                return !IsPointer && KarDataScalarTypes.TryResolve(TypeName, out kind, out size);
            }
        }

        public bool IsFloatScalar
        {
            get
            {
                KarDataScalarKind kind;
                int size;
                return !IsPointer &&
                    KarDataScalarTypes.TryResolve(TypeName, out kind, out size) &&
                    kind == KarDataScalarKind.Float;
            }
        }
    }
}
