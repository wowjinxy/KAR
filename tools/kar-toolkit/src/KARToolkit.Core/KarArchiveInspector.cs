using HSDRaw;
using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarArchiveInspector
    {
        public static KarArchiveInspector Default { get; } = new KarArchiveInspector();

        private readonly KarDataDefinitionRegistry _dataDefinitions;
        private readonly KarDataInspectionOptions _dataInspectionOptions;

        public KarArchiveInspector()
            : this(KarDataDefinitionCatalog.BuiltIn, null)
        {
        }

        public KarArchiveInspector(KarDataDefinitionRegistry dataDefinitions)
            : this(dataDefinitions, null)
        {
        }

        public KarArchiveInspector(KarDataDefinitionRegistry dataDefinitions, KarDataInspectionOptions dataInspectionOptions)
        {
            _dataDefinitions = dataDefinitions ?? throw new ArgumentNullException(nameof(dataDefinitions));
            _dataInspectionOptions = dataInspectionOptions ?? new KarDataInspectionOptions();
        }

        public KarDataDefinitionRegistry DataDefinitions => _dataDefinitions;

        public KarDataInspectionOptions DataInspectionOptions => _dataInspectionOptions;

        public KarArchiveInfo Inspect(KarProjectFile file)
        {
            if (file == null)
                throw new ArgumentNullException(nameof(file));

            return Inspect(file, new HSDRawFile(file.ReadPath));
        }

        public KarArchiveInfo Inspect(KarProjectFile file, HSDRawFile hsdFile)
        {
            if (file == null)
                throw new ArgumentNullException(nameof(file));
            if (hsdFile == null)
                throw new ArgumentNullException(nameof(hsdFile));

            KarArchiveDefinition definition = file.ArchiveDefinition;
            List<KarArchiveRootInfo> roots = hsdFile.Roots
                .Select(root =>
                {
                    KarRootDefinition rootDefinition = definition.FindRoot(root.Name);
                    string accessorTypeName = root.Data == null ? null : root.Data.GetType().Name;
                    KarDataDefinition dataDefinition = ResolveDataDefinition(rootDefinition, accessorTypeName);
                    return new KarArchiveRootInfo(
                        root.Name,
                        accessorTypeName,
                        root.Data == null || root.Data._s == null ? (int?)null : root.Data._s.Length,
                        rootDefinition,
                        dataDefinition,
                        KarDataInspector.InspectFields(root.Data, dataDefinition, _dataDefinitions, _dataInspectionOptions));
                })
                .ToList();

            return new KarArchiveInfo(file, definition, roots);
        }

        private KarDataDefinition ResolveDataDefinition(KarRootDefinition rootDefinition, string accessorTypeName)
        {
            if (rootDefinition != null)
            {
                KarDataDefinition rootDefinitionData = rootDefinition.ResolveDataDefinition(_dataDefinitions);
                if (rootDefinitionData != null)
                    return rootDefinitionData;
            }

            KarDataDefinition definition;
            if (_dataDefinitions.TryGetByAccessorTypeName(accessorTypeName, out definition))
                return definition;

            return null;
        }
    }
}
