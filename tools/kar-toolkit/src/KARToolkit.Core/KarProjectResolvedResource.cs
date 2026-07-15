using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResolvedResource
    {
        internal KarProjectResolvedResource(KarProjectResourceInfo resource, KarProjectScriptTable scriptTable)
        {
            Resource = resource ?? throw new ArgumentNullException(nameof(resource));
            ScriptTable = scriptTable;
        }

        public KarProjectResourceInfo Resource { get; }

        public KarProjectScriptTable ScriptTable { get; }

        public KarResourceReference Reference => Resource.Reference;

        public KarResourceKind Kind => Resource.Kind;

        public string Address => Resource.Address;

        public string ParentAddress => Resource.ParentAddress;

        public string RelativePath => Resource.RelativePath;

        public KarProjectFile File => Resource.File;

        public KarProjectRootInfo Root => Resource.Root;

        public KarProjectA2DEntryInfo A2DEntry => Resource.A2DEntry;

        public string DisplayName => Resource.DisplayName;

        public string Role => ScriptTable == null ? Resource.Role : ScriptTable.Role;

        public string Category => ScriptTable == null ? Resource.Category : ScriptTable.Category;

        public string Description => ScriptTable == null ? Resource.Description : ScriptTable.Description;

        public KarDataDefinition DataDefinition => Root == null ? null : Root.DataDefinition;

        public string DataDefinitionId => Root == null ? null : Root.DataDefinitionId;

        public bool HasDataDefinition => DataDefinition != null;

        public bool IsFile => Resource.IsFile;

        public bool IsHsdRoot => Resource.IsHsdRoot;

        public bool IsA2DEntry => Resource.IsA2DEntry;

        public bool IsScriptTable => ScriptTable != null;

        public bool IsLooseScriptTable => ScriptTable != null && ScriptTable.IsLooseFile;

        public bool IsPackageScriptTable => ScriptTable != null && ScriptTable.IsPackageEntry;

        public bool CanQueryOutput => Resource.CanQueryOutput;

        public bool CanReadBytes => Resource.CanReadBytes;

        public bool CanExportToOutput => Resource.CanExportToOutput;

        public bool CanImportFromFile => Resource.CanImportFromFile;

        public bool CanSetScalarFields => Resource.CanSetScalarFields;

        public bool CanQueryFieldValues => Resource.CanQueryFieldValues;

        public bool CanApplyOutput => Resource.CanApplyOutput;
    }
}
