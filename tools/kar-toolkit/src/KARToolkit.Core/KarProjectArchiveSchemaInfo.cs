using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectArchiveSchemaInfo
    {
        internal KarProjectArchiveSchemaInfo(KarProjectFile file)
        {
            File = file ?? throw new ArgumentNullException(nameof(file));
            Definition = file.ArchiveDefinition;
            RootDefinitions = Definition.Roots;
        }

        public KarProjectFile File { get; }

        public string RelativePath => File.RelativePath;

        public KarFileKind Kind => File.Kind;

        public string KindId => File.KindId;

        public string Category => Definition.Category;

        public string DisplayName => Definition.DisplayName;

        public string Description => Definition.Description;

        public KarArchiveDefinition Definition { get; }

        public IReadOnlyList<KarRootDefinition> RootDefinitions { get; }

        public int RootDefinitionCount => RootDefinitions.Count;

        public int RequiredRootDefinitionCount => RootDefinitions.Count(root => root.IsRequired);
    }
}
