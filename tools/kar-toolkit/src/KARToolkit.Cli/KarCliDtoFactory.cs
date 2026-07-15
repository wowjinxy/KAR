using KARToolkit.Core;
using KARToolkit.Core.AirRide;

namespace KARToolkit.Cli;

internal static class KarCliDtoFactory
{
    public static object ToProjectDto(KarProject project)
    {
        return new
        {
            name = project.Name,
            sourceRoot = project.SourceRoot,
            sourceFilesRoot = project.SourceFilesRoot,
            outputRoot = project.OutputRoot,
            outputFilesRoot = project.OutputFilesRoot,
            sourceHasFilesDirectory = project.SourceHasFilesDirectory,
            fileCount = project.Files.Count,
            mapCount = project.Maps.Count,
            categories = project.Files
                .GroupBy(file => file.Category)
                .OrderBy(group => group.Key)
                .Select(group => new
                {
                    category = group.Key,
                    count = group.Count(),
                })
                .ToList(),
        };
    }

    public static object ToMapInfoDto(KarMapInfo map)
    {
        return new
        {
            name = map.Name,
            files = map.Bundle.Files.Select(ToProjectFileDto).ToList(),
            hasScriptArchive = map.HasScriptArchive,
            dataArchive = ToArchiveDtoOrNull(map.DataArchive),
            modelArchive = ToArchiveDtoOrNull(map.ModelArchive),
            eventArchive = ToArchiveDtoOrNull(map.EventArchive),
            missingRequiredRoots = map.MissingRequiredRoots.Select(root => root.Pattern).ToList(),
        };
    }

    public static object ToMapBundleDto(KarMapBundle map)
    {
        return new
        {
            name = map.Name,
            hasDataFile = map.HasDataFile,
            hasModelFile = map.HasModelFile,
            hasScriptFile = map.HasScriptFile,
            files = map.Files.Select(ToProjectFileDto).ToList(),
        };
    }

    public static object ToArchiveDtoOrNull(KarArchiveInfo archive)
    {
        return archive == null ? null : ToArchiveDto(archive);
    }

    public static object ToArchiveDto(KarArchiveInfo archive)
    {
        return new
        {
            file = ToProjectFileDto(archive.File),
            definition = new
            {
                displayName = archive.Definition.DisplayName,
                category = archive.Definition.Category,
                description = archive.Definition.Description,
            },
            rootCount = archive.Roots.Count,
            knownRootCount = archive.KnownRoots.Count,
            unknownRootCount = archive.UnknownRoots.Count,
            roots = archive.Roots.Select(ToRootDto).ToList(),
            missingRequiredRoots = archive.MissingRequiredRoots.Select(root => root.Pattern).ToList(),
        };
    }

    public static object ToRootDto(KarArchiveRootInfo root)
    {
        return new
        {
            name = root.Name,
            isKnown = root.IsKnown,
            accessorTypeName = root.AccessorTypeName,
            expectedAccessorTypeName = root.ExpectedAccessorTypeName,
            displayAccessorTypeName = root.DisplayAccessorTypeName,
            description = root.Definition == null ? null : root.Definition.Description,
            dataDefinition = ToDataDefinitionDtoOrNull(root.DataDefinition),
            fieldValues = root.FieldValues.Select(ToFieldValueDto).ToList(),
        };
    }

    public static object ToDataDefinitionDtoOrNull(KarDataDefinition definition)
    {
        return definition == null ? null : ToDataDefinitionDto(definition);
    }

    public static object ToDataDefinitionDto(KarDataDefinition definition)
    {
        return new
        {
            id = definition.Id,
            displayName = definition.DisplayName,
            category = definition.Category,
            accessorTypeName = definition.AccessorTypeName,
            description = definition.Description,
            source = definition.Source,
            fieldCount = definition.Fields.Count,
            fields = definition.Fields.Select(ToDataFieldDto).ToList(),
        };
    }

    public static object ToDataFieldDto(KarDataFieldDefinition field)
    {
        return new
        {
            name = field.Name,
            offset = field.Offset,
            offsetHex = field.OffsetHex,
            typeName = field.TypeName,
            description = field.Description,
            isPointer = field.IsPointer,
            isScalar = field.IsScalar,
            isFloatScalar = field.IsFloatScalar,
            dataDefinitionId = field.DataDefinitionId,
        };
    }

    public static object ToFieldValueDto(KarDataFieldValue value)
    {
        return new
        {
            field = ToDataFieldDto(value.Field),
            isAvailable = value.IsAvailable,
            valueKind = value.ValueKind,
            displayValue = value.DisplayValue,
            signedValue = value.SignedValue,
            unsignedValue = value.UnsignedValue,
            floatValue = value.FloatValue,
            hasReference = value.HasReference,
            referenceLength = value.ReferenceLength,
            referenceLengthHex = value.ReferenceLengthHex,
            error = value.Error,
        };
    }

    public static object ToProjectFileDto(KarProjectFile file)
    {
        return new
        {
            relativePath = file.RelativePath,
            kind = file.Kind.ToString(),
            displayName = file.DisplayName,
            category = file.Category,
            hasOutputCopy = file.HasOutputCopy,
        };
    }

    public static object ToA2DEntryDto(A2DPackageEntry entry)
    {
        return new
        {
            index = entry.Index,
            name = entry.Name,
            kind = entry.Kind,
            nameOffset = entry.NameOffset,
            dataOffset = entry.DataOffset,
            size = entry.Size,
        };
    }

    public static object ToValidationReportDto(KarValidationReport report)
    {
        return new
        {
            project = ToProjectDto(report.Project),
            fileCount = report.FileCount,
            mapCount = report.MapCount,
            hsdArchiveCount = report.HsdArchiveCount,
            a2dPackageCount = report.A2DPackageCount,
            isValid = report.IsValid,
            errorCount = report.Errors.Count,
            warningCount = report.Warnings.Count,
            infoCount = report.Infos.Count,
            issues = report.Issues.Select(ToValidationIssueDto).ToList(),
        };
    }

    public static object ToValidationIssueDto(KarValidationIssue issue)
    {
        return new
        {
            severity = issue.Severity.ToString(),
            code = issue.Code,
            message = issue.Message,
            relativePath = issue.RelativePath,
            mapName = issue.MapName,
            rootName = issue.RootName,
        };
    }
}
