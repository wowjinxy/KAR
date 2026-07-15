using System;
using System.Globalization;

namespace KARToolkit.Core
{
    public sealed class KarProjectEditService
    {
        private readonly KarProject _project;

        internal KarProjectEditService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public KarProjectScalarEditResult SetScalarField(
            string relativePath,
            string rootName,
            string fieldName,
            long value,
            bool bufferAlign = true,
            bool optimize = true,
            bool trim = false)
        {
            KarProjectHsdArchive archive = _project.ArchiveService.OpenHsdArchive(relativePath);
            KarDataFieldEditResult edit = archive.SetScalarField(rootName, fieldName, value);
            return SaveResult(archive, edit, bufferAlign, optimize, trim);
        }

        public KarProjectScalarEditResult SetScalarField(
            string relativePath,
            string rootName,
            string fieldName,
            double value,
            bool bufferAlign = true,
            bool optimize = true,
            bool trim = false)
        {
            KarProjectHsdArchive archive = _project.ArchiveService.OpenHsdArchive(relativePath);
            KarDataFieldEditResult edit = archive.SetScalarField(rootName, fieldName, value);
            return SaveResult(archive, edit, bufferAlign, optimize, trim);
        }

        public KarProjectScalarEditResult SetScalarFieldByDataDefinition(
            string relativePath,
            string idOrAccessorTypeName,
            string fieldName,
            long value,
            bool bufferAlign = true,
            bool optimize = true,
            bool trim = false)
        {
            KarProjectHsdArchive archive = _project.ArchiveService.OpenHsdArchive(relativePath);
            KarDataFieldEditResult edit = archive.SetScalarFieldByDataDefinition(idOrAccessorTypeName, fieldName, value);
            return SaveResult(archive, edit, bufferAlign, optimize, trim);
        }

        public KarProjectScalarEditResult SetScalarFieldByDataDefinition(
            string relativePath,
            string idOrAccessorTypeName,
            string fieldName,
            double value,
            bool bufferAlign = true,
            bool optimize = true,
            bool trim = false)
        {
            KarProjectHsdArchive archive = _project.ArchiveService.OpenHsdArchive(relativePath);
            KarDataFieldEditResult edit = archive.SetScalarFieldByDataDefinition(idOrAccessorTypeName, fieldName, value);
            return SaveResult(archive, edit, bufferAlign, optimize, trim);
        }

        public KarProjectScalarEditResult SetScalarFieldFromText(
            string relativePath,
            string rootOrDataDefinition,
            string fieldName,
            string rawValue,
            bool byDataDefinition = false,
            bool bufferAlign = true,
            bool optimize = true,
            bool trim = false)
        {
            KarProjectHsdArchive archive = _project.ArchiveService.OpenHsdArchive(relativePath);
            KarDataFieldDefinition field = ResolveWritableScalarField(archive, rootOrDataDefinition, fieldName, byDataDefinition);
            KarDataFieldEditResult edit = field.IsFloatScalar
                ? SetFloatScalar(archive, byDataDefinition, rootOrDataDefinition, field.Name, rawValue)
                : SetIntegerScalar(archive, byDataDefinition, rootOrDataDefinition, field.Name, rawValue);
            return SaveResult(archive, edit, bufferAlign, optimize, trim);
        }

        private static KarDataFieldDefinition ResolveWritableScalarField(
            KarProjectHsdArchive archive,
            string rootOrDataDefinition,
            string fieldName,
            bool byDataDefinition)
        {
            KarArchiveInfo archiveInfo = archive.Inspect();
            KarArchiveRootInfo rootInfo = byDataDefinition
                ? archiveInfo.GetRootByDataDefinition(rootOrDataDefinition)
                : archiveInfo.GetRoot(rootOrDataDefinition);

            if (rootInfo.DataDefinition == null)
                throw new InvalidOperationException("KAR archive root has no data definition: " + rootInfo.Name);

            KarDataFieldDefinition field = rootInfo.DataDefinition.GetField(fieldName);
            if (!field.IsScalar)
                throw new InvalidOperationException("Field is not a writable scalar field: " + field.Name);

            return field;
        }

        private static KarDataFieldEditResult SetIntegerScalar(
            KarProjectHsdArchive archive,
            bool byDataDefinition,
            string rootOrDataDefinition,
            string fieldName,
            string rawValue)
        {
            long value = ParseInteger(rawValue);
            return byDataDefinition
                ? archive.SetScalarFieldByDataDefinition(rootOrDataDefinition, fieldName, value)
                : archive.SetScalarField(rootOrDataDefinition, fieldName, value);
        }

        private static KarDataFieldEditResult SetFloatScalar(
            KarProjectHsdArchive archive,
            bool byDataDefinition,
            string rootOrDataDefinition,
            string fieldName,
            string rawValue)
        {
            double value = double.Parse(rawValue, NumberStyles.Float, CultureInfo.InvariantCulture);
            return byDataDefinition
                ? archive.SetScalarFieldByDataDefinition(rootOrDataDefinition, fieldName, value)
                : archive.SetScalarField(rootOrDataDefinition, fieldName, value);
        }

        private static long ParseInteger(string rawValue)
        {
            if (string.IsNullOrWhiteSpace(rawValue))
                throw new ArgumentException("Integer value cannot be empty.", nameof(rawValue));

            string value = rawValue.Trim();
            bool negative = value.StartsWith("-", StringComparison.Ordinal);
            string unsigned = negative ? value.Substring(1) : value;
            if (unsigned.StartsWith("0x", StringComparison.OrdinalIgnoreCase))
            {
                long parsed = Convert.ToInt64(unsigned.Substring(2), 16);
                return negative ? -parsed : parsed;
            }

            return long.Parse(value, NumberStyles.Integer, CultureInfo.InvariantCulture);
        }

        private KarProjectScalarEditResult SaveResult(
            KarProjectHsdArchive archive,
            KarDataFieldEditResult edit,
            bool bufferAlign,
            bool optimize,
            bool trim)
        {
            KarProjectFileWriteResult write = archive.SaveToOutput(bufferAlign, optimize, trim);
            return new KarProjectScalarEditResult(archive, edit, write);
        }
    }
}
