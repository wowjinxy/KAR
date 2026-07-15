using HSDRaw;
using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarArchiveInspector
    {
        public static KarArchiveInspector Default { get; } = new KarArchiveInspector();

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

            KarArchiveDefinition definition = file.ArchiveDefinition ?? KarArchiveCatalog.GetDefinition(file.RelativePath, file.Kind);
            List<KarArchiveRootInfo> roots = hsdFile.Roots
                .Select(root =>
                {
                    KarRootDefinition rootDefinition = definition.FindRoot(root.Name);
                    string accessorTypeName = root.Data == null ? null : root.Data.GetType().Name;
                    KarDataDefinition dataDefinition = ResolveDataDefinition(rootDefinition, accessorTypeName);
                    return new KarArchiveRootInfo(
                        root.Name,
                        accessorTypeName,
                        rootDefinition,
                        KarDataInspector.InspectFields(root.Data, dataDefinition));
                })
                .ToList();

            return new KarArchiveInfo(file, definition, roots);
        }

        private static KarDataDefinition ResolveDataDefinition(KarRootDefinition rootDefinition, string accessorTypeName)
        {
            if (rootDefinition != null && rootDefinition.DataDefinition != null)
                return rootDefinition.DataDefinition;

            KarDataDefinition definition;
            if (KarDataDefinitionCatalog.TryGetByAccessorTypeName(accessorTypeName, out definition))
                return definition;

            return null;
        }
    }
}
