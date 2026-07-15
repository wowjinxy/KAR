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
            fileCount = project.FileService.Files.Count,
            mapCount = project.Maps.Count,
            categories = project.FileService.Files
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

    public static object ToProjectReportDto(KarProjectReport report)
    {
        return new
        {
            project = ToProjectDto(report.Project),
            fileCount = report.FileCount,
            outputFileCount = report.OutputFileCount,
            projectOutputFileCount = report.ProjectOutputFileCount,
            orphanOutputFileCount = report.OrphanOutputFileCount,
            modifiedProjectOutputFileCount = report.ModifiedProjectOutputFileCount,
            unchangedProjectOutputFileCount = report.UnchangedProjectOutputFileCount,
            missingSourceOutputFileCount = report.MissingSourceOutputFileCount,
            mapOutputCount = report.MapOutputCount,
            modifiedMapOutputCount = report.ModifiedMapOutputCount,
            completeMapOutputCount = report.CompleteMapOutputCount,
            mapCount = report.MapCount,
            completeMapCount = report.CompleteMapCount,
            incompleteMapCount = report.IncompleteMapCount,
            hsdArchiveCount = report.HsdArchiveCount,
            a2dPackageCount = report.A2DPackageCount,
            rootCount = report.RootCount,
            knownRootCount = report.KnownRootCount,
            unknownRootCount = report.UnknownRootCount,
            missingRequiredRootCount = report.MissingRequiredRootCount,
            dataDefinitionUsageCount = report.DataDefinitionUsageCount,
            fieldSummaryCount = report.FieldSummaryCount,
            fileCategories = report.FileCategories.Select(ToProjectFileGroupSummaryDto).ToList(),
            fileKinds = report.FileKinds.Select(ToProjectFileGroupSummaryDto).ToList(),
            outputs = ToProjectOutputInventoryDto(report.OutputInventory),
            mapOutputs = report.MapOutputs.Select(ToProjectMapOutputDto).ToList(),
            rootSummaries = report.RootSummaries.Select(ToProjectRootSummaryDto).ToList(),
            dataDefinitionUsage = report.DataDefinitionUsage.Select(ToDataDefinitionUsageDto).ToList(),
            fieldSummaries = report.FieldSummaries.Select(ToProjectFieldSummaryDto).ToList(),
        };
    }

    public static object ToProjectMapOutputDto(KarProjectMapOutputInfo map)
    {
        return new
        {
            name = map.Name,
            expectedOutputFileCount = map.ExpectedOutputFileCount,
            outputFileCount = map.OutputFileCount,
            missingOutputFileCount = map.MissingOutputFileCount,
            modifiedOutputFileCount = map.ModifiedOutputFileCount,
            unchangedOutputFileCount = map.UnchangedOutputFileCount,
            missingSourceOutputFileCount = map.MissingSourceOutputFileCount,
            hasOutput = map.HasOutput,
            hasModifiedOutput = map.HasModifiedOutput,
            hasCompleteOutputSet = map.HasCompleteOutputSet,
            dataFile = ToProjectFileDtoOrNull(map.DataFile),
            modelFile = ToProjectFileDtoOrNull(map.ModelFile),
            eventFile = ToProjectFileDtoOrNull(map.EventFile),
            dataOutput = ToProjectOutputFileDtoOrNull(map.DataOutput),
            modelOutput = ToProjectOutputFileDtoOrNull(map.ModelOutput),
            eventOutput = ToProjectOutputFileDtoOrNull(map.EventOutput),
            scriptOutput = ToProjectOutputFileDtoOrNull(map.ScriptOutput),
            outputs = map.OutputFiles.Select(ToProjectOutputFileDto).ToList(),
        };
    }

    public static object ToProjectFileGroupSummaryDto(KarProjectFileGroupSummary group)
    {
        return new
        {
            name = group.Name,
            count = group.Count,
            files = group.Files
                .Select(file => new
                {
                    resource = ToResourceReferenceDto(file.ResourceReference),
                    relativePath = file.RelativePath,
                    resourceAddress = file.ResourceAddress,
                    kind = file.Kind.ToString(),
                    category = file.Category,
                    displayName = file.DisplayName,
                })
                .ToList(),
        };
    }

    public static object ToProjectOutputInventoryDto(KarProjectOutputInventory inventory)
    {
        return new
        {
            outputRoot = inventory.Project.OutputRoot,
            outputFilesRoot = inventory.Project.OutputFilesRoot,
            count = inventory.Count,
            projectFileCount = inventory.ProjectFileCount,
            orphanFileCount = inventory.OrphanFileCount,
            modifiedProjectFileCount = inventory.ModifiedProjectFileCount,
            unchangedProjectFileCount = inventory.UnchangedProjectFileCount,
            missingSourceFileCount = inventory.MissingSourceFileCount,
            totalOutputLength = inventory.TotalOutputLength,
            files = inventory.Files.Select(ToProjectOutputFileDto).ToList(),
        };
    }

    public static object ToProjectOutputFileDto(KarProjectOutputFileInfo file)
    {
        return new
        {
            resource = ToResourceReferenceDto(file.ResourceReference),
            relativePath = file.RelativePath,
            resourceAddress = file.ResourceAddress,
            sourcePath = file.SourcePath,
            outputPath = file.OutputPath,
            kind = file.Kind.ToString(),
            displayName = file.DisplayName,
            category = file.Category,
            status = file.Status.ToString(),
            isProjectFile = file.IsProjectFile,
            isOrphan = file.IsOrphan,
            isModifiedProjectFile = file.IsModifiedProjectFile,
            isUnchangedProjectFile = file.IsUnchangedProjectFile,
            outputLength = file.OutputLength,
            outputLastWriteTimeUtc = file.OutputLastWriteTimeUtc,
            outputSha256 = file.OutputSha256,
            sourceLength = file.SourceLength,
            sourceLastWriteTimeUtc = file.SourceLastWriteTimeUtc,
            sourceSha256 = file.SourceSha256,
            isSameLengthAsSource = file.IsSameLengthAsSource,
            isSameContentAsSource = file.IsSameContentAsSource,
        };
    }

    public static object ToProjectOutputFileDtoOrNull(KarProjectOutputFileInfo file)
    {
        return file == null ? null : ToProjectOutputFileDto(file);
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

    public static object ToProjectRelationshipDto(KarProjectRelationship relationship)
    {
        return new
        {
            kind = relationship.Kind,
            role = relationship.Role,
            category = relationship.Category,
            description = relationship.Description,
            mapName = relationship.MapName,
            resource = ToResourceReferenceDtoOrNull(relationship.ResourceReference),
            relativePath = relationship.RelativePath,
            displayName = relationship.DisplayName,
            isMapScoped = relationship.IsMapScoped,
            isPackageEntry = relationship.IsPackageEntry,
            file = ToProjectFileDtoOrNull(relationship.File),
            packageFile = ToProjectFileDtoOrNull(relationship.PackageFile),
            packageEntryName = relationship.PackageEntryName,
            packageEntryIndex = relationship.PackageEntryIndex,
            packageEntryOffset = relationship.PackageEntryOffset,
            packageEntryOffsetHex = relationship.PackageEntryOffsetHex,
            packageEntrySize = relationship.PackageEntrySize,
            packageEntrySizeHex = relationship.PackageEntrySizeHex,
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

    public static object ToArchiveInventoryDto(KarArchiveInfo archive)
    {
        return new
        {
            file = ToProjectFileDto(archive.File),
            rootCount = archive.Roots.Count,
            knownRootCount = archive.KnownRoots.Count,
            unknownRootCount = archive.UnknownRoots.Count,
            missingRequiredRootCount = archive.MissingRequiredRoots.Count,
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

    public static object ToProjectRootDto(KarProjectRootInfo root)
    {
        return new
        {
            resource = ToResourceReferenceDto(root.ResourceReference),
            rootPath = root.RootPath,
            file = new
            {
                resource = ToResourceReferenceDto(root.File.ResourceReference),
                relativePath = root.File.RelativePath,
                resourceAddress = root.File.ResourceAddress,
                kind = root.File.Kind.ToString(),
                category = root.File.Category,
                displayName = root.File.DisplayName,
            },
            root = new
            {
                name = root.Root.Name,
                isKnown = root.Root.IsKnown,
                accessorTypeName = root.Root.AccessorTypeName,
                expectedAccessorTypeName = root.Root.ExpectedAccessorTypeName,
                displayAccessorTypeName = root.Root.DisplayAccessorTypeName,
                description = root.Root.Definition == null ? null : root.Root.Definition.Description,
                dataDefinitionId = root.Root.DataDefinitionId,
            },
        };
    }

    public static object ToProjectRootSummaryDto(KarProjectRootSummary summary)
    {
        return new
        {
            rootName = summary.RootName,
            isKnown = summary.IsKnown,
            displayAccessorTypeName = summary.DisplayAccessorTypeName,
            dataDefinitionId = summary.DataDefinitionId,
            count = summary.Count,
            files = summary.Roots
                .Select(root => new
                {
                    resource = ToResourceReferenceDto(root.File.ResourceReference),
                    relativePath = root.File.RelativePath,
                    resourceAddress = root.File.ResourceAddress,
                    kind = root.File.Kind.ToString(),
                    category = root.File.Category,
                    displayName = root.File.DisplayName,
                })
                .ToList(),
        };
    }

    public static object ToDataDefinitionUsageDto(KarProjectDataDefinitionUsage usage)
    {
        return new
        {
            dataDefinitionId = usage.DataDefinitionId,
            displayName = usage.DisplayName,
            category = usage.Category,
            accessorTypeName = usage.AccessorTypeName,
            count = usage.Count,
            fileCount = usage.FileCount,
            files = usage.Files
                .Select(file => new
                {
                    relativePath = file.RelativePath,
                    kind = file.Kind.ToString(),
                    category = file.Category,
                    displayName = file.DisplayName,
                })
                .ToList(),
            roots = usage.Roots
                .Select(root => new
                {
                    relativePath = root.RelativePath,
                    rootName = root.RootName,
                })
                .ToList(),
        };
    }

    public static object ToProjectFieldValueDto(KarProjectFieldInfo field)
    {
        return new
        {
            file = new
            {
                relativePath = field.File.RelativePath,
                kind = field.File.Kind.ToString(),
                category = field.File.Category,
                displayName = field.File.DisplayName,
            },
            root = new
            {
                name = field.RootName,
                accessorTypeName = field.ArchiveRoot.AccessorTypeName,
                displayAccessorTypeName = field.ArchiveRoot.DisplayAccessorTypeName,
                dataDefinitionId = field.DataDefinitionId,
            },
            fieldName = field.FieldName,
            fieldValue = ToFieldValueDto(field.Value),
        };
    }

    public static object ToProjectFieldSummaryDto(KarProjectFieldSummary summary)
    {
        return new
        {
            dataDefinitionId = summary.DataDefinitionId,
            displayName = summary.DisplayName,
            category = summary.Category,
            accessorTypeName = summary.AccessorTypeName,
            field = ToDataFieldDto(summary.Field),
            count = summary.Count,
            fileCount = summary.FileCount,
            availableCount = summary.AvailableCount,
            unavailableCount = summary.UnavailableCount,
            distinctValueCount = summary.DistinctValueCount,
            hasValueVariation = summary.HasValueVariation,
            distinctValues = summary.DistinctValues.Select(ToProjectFieldDistinctValueDto).ToList(),
        };
    }

    public static object ToProjectFieldDistinctValueDto(KarProjectFieldDistinctValue value)
    {
        return new
        {
            valueKind = value.ValueKind,
            displayValue = value.DisplayValue,
            signedValue = value.SignedValue,
            unsignedValue = value.UnsignedValue,
            floatValue = value.FloatValue,
            hasReference = value.HasReference,
            referenceLength = value.ReferenceLength,
            referenceLengthHex = value.ReferenceLengthHex,
            referenceDataDefinitionId = value.ReferenceDataDefinitionId,
            error = value.Error,
            count = value.Count,
            fileCount = value.FileCount,
            occurrences = value.Fields
                .Select(field => new
                {
                    relativePath = field.RelativePath,
                    rootName = field.RootName,
                })
                .ToList(),
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
            size = definition.Size,
            sizeHex = definition.SizeHex,
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

    public static object ToDataDefinitionValidationReportDto(KarDataDefinitionValidationReport report)
    {
        return new
        {
            definitionCount = report.DefinitionCount,
            isValid = report.IsValid,
            errorCount = report.ErrorCount,
            warningCount = report.WarningCount,
            infoCount = report.InfoCount,
            issues = report.Issues.Select(ToDataDefinitionValidationIssueDto).ToList(),
        };
    }

    public static object ToDataDefinitionValidationIssueDto(KarDataDefinitionValidationIssue issue)
    {
        return new
        {
            severity = issue.Severity.ToString(),
            code = issue.Code,
            message = issue.Message,
            definitionId = issue.DefinitionId,
            fieldName = issue.FieldName,
            referencedDataDefinitionId = issue.ReferencedDataDefinitionId,
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
            referenceDataDefinition = ToDataDefinitionDtoOrNull(value.ReferenceDataDefinition),
            referenceFieldValues = value.ReferenceFieldValues.Select(ToFieldValueDto).ToList(),
            referenceEntryCount = value.ReferenceEntryCount,
            referenceEntryTotalCount = value.ReferenceEntryTotalCount,
            referenceEntries = value.ReferenceEntries.Select(ToReferenceEntryDto).ToList(),
            error = value.Error,
        };
    }

    public static object ToReferenceEntryDto(KarDataReferenceEntry entry)
    {
        return new
        {
            index = entry.Index,
            offset = entry.Offset,
            offsetHex = entry.OffsetHex,
            fieldValues = entry.FieldValues.Select(ToFieldValueDto).ToList(),
        };
    }

    public static object ToResourceReferenceDto(KarResourceReference reference)
    {
        return new
        {
            kind = reference.Kind.ToString(),
            address = reference.Address,
            parentAddress = reference.ParentAddress,
            relativePath = reference.RelativePath,
            rootName = reference.RootName,
            entryName = reference.EntryName,
        };
    }

    public static object ToResourceReferenceDtoOrNull(KarResourceReference reference)
    {
        return reference == null ? null : ToResourceReferenceDto(reference);
    }

    public static object ToProjectFileDto(KarProjectFile file)
    {
        return new
        {
            resource = ToResourceReferenceDto(file.ResourceReference),
            relativePath = file.RelativePath,
            resourceAddress = file.ResourceAddress,
            kind = file.Kind.ToString(),
            displayName = file.DisplayName,
            category = file.Category,
            sourcePath = file.SourcePath,
            outputPath = file.OutputPath,
            readPath = file.ReadPath,
            hasOutputCopy = file.HasOutputCopy,
            archiveDefinition = new
            {
                displayName = file.ArchiveDefinition.DisplayName,
                category = file.ArchiveDefinition.Category,
                description = file.ArchiveDefinition.Description,
                rootCount = file.ArchiveDefinition.Roots.Count,
            },
        };
    }

    public static object ToProjectFileDtoOrNull(KarProjectFile file)
    {
        return file == null ? null : ToProjectFileDto(file);
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

    public static object ToProjectA2DEntryDto(KarProjectA2DEntryInfo entry)
    {
        return new
        {
            resource = ToResourceReferenceDto(entry.ResourceReference),
            packageFile = ToProjectFileDto(entry.PackageFile),
            packageRelativePath = entry.PackageRelativePath,
            entryPath = entry.EntryPath,
            index = entry.Index,
            name = entry.Name,
            nameOffset = entry.NameOffset,
            nameOffsetHex = entry.NameOffsetHex,
            dataOffset = entry.DataOffset,
            dataOffsetHex = entry.DataOffsetHex,
            size = entry.Size,
            sizeHex = entry.SizeHex,
            kind = entry.Kind,
            isScriptTable = entry.IsScriptTable,
            role = entry.Role,
            category = entry.Category,
            description = entry.Description,
        };
    }

    public static object ToA2DEntryExtractResultDto(KarProjectA2DEntryExtractResult result)
    {
        return new
        {
            entry = ToProjectA2DEntryDto(result.Entry),
            outputRelativePath = result.OutputRelativePath,
            outputPath = result.OutputPath,
            wroteOutput = result.WroteOutput,
        };
    }

    public static object ToA2DEntryOutputDto(KarProjectA2DEntryOutputInfo output)
    {
        return new
        {
            entry = ToProjectA2DEntryDto(output.Entry),
            entryPath = output.EntryPath,
            outputRelativePath = output.OutputRelativePath,
            outputPath = output.OutputPath,
            hasOutput = output.HasOutput,
            status = output.Status.ToString(),
            outputLength = output.OutputLength,
            outputLastWriteTimeUtc = output.OutputLastWriteTimeUtc,
            outputSha256 = output.OutputSha256,
            entryLength = output.EntryLength,
            entrySha256 = output.EntrySha256,
            isSameLengthAsEntry = output.IsSameLengthAsEntry,
            isSameContentAsEntry = output.IsSameContentAsEntry,
        };
    }

    public static object ToA2DEntryReplaceResultDto(KarProjectA2DEntryReplaceResult result)
    {
        return new
        {
            entry = ToProjectA2DEntryDto(result.Entry),
            packageFile = ToProjectFileDto(result.PackageFile),
            packageRelativePath = result.PackageRelativePath,
            replacementLength = result.ReplacementLength,
            writeResult = new
            {
                relativePath = result.WriteResult.RelativePath,
                outputPath = result.WriteResult.OutputPath,
                outputLastWriteTimeUtc = result.WriteResult.OutputLastWriteTimeUtc,
            },
            outputPath = result.OutputPath,
        };
    }

    public static object ToA2DEntryApplyResultDto(KarProjectA2DEntryApplyResult result)
    {
        return new
        {
            entry = ToProjectA2DEntryDto(result.Entry),
            output = ToA2DEntryOutputDto(result.Output),
            packageFile = ToProjectFileDto(result.PackageFile),
            packageRelativePath = result.PackageRelativePath,
            sidecarOutputPath = result.SidecarOutputPath,
            replacementLength = result.ReplacementLength,
            writeResult = new
            {
                relativePath = result.WriteResult.RelativePath,
                outputPath = result.WriteResult.OutputPath,
                outputLastWriteTimeUtc = result.WriteResult.OutputLastWriteTimeUtc,
            },
            packageOutputPath = result.PackageOutputPath,
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
            dataDefinitionValidation = ToDataDefinitionValidationReportDtoOrNull(report.DataDefinitionValidation),
            isValid = report.IsValid,
            errorCount = report.ErrorCount,
            warningCount = report.WarningCount,
            infoCount = report.InfoCount,
            projectErrorCount = report.Errors.Count,
            projectWarningCount = report.Warnings.Count,
            projectInfoCount = report.Infos.Count,
            issues = report.Issues.Select(ToValidationIssueDto).ToList(),
        };
    }

    public static object ToDataDefinitionValidationReportDtoOrNull(KarDataDefinitionValidationReport report)
    {
        return report == null ? null : ToDataDefinitionValidationReportDto(report);
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
