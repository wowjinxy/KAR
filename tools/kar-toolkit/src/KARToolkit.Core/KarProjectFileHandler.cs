using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectFileHandler
    {
        private static readonly KarProjectFileCapability[] CapabilityValues = Enum
            .GetValues(typeof(KarProjectFileCapability))
            .Cast<KarProjectFileCapability>()
            .Where(capability => capability != KarProjectFileCapability.None)
            .ToArray();
        private readonly IReadOnlyList<KarProjectFileCapability> _capabilityList;

        public KarProjectFileHandler(KarFileKindDescriptor descriptor, KarProjectFileCapability capabilities)
        {
            Descriptor = descriptor ?? throw new ArgumentNullException(nameof(descriptor));
            Capabilities = capabilities;
            _capabilityList = CapabilityValues
                .Where(HasCapability)
                .ToList()
                .AsReadOnly();
        }

        public KarFileKindDescriptor Descriptor { get; }

        public KarFileKind Kind => Descriptor.Kind;

        public string Id => Descriptor.Id;

        public string DisplayName => Descriptor.DisplayName;

        public string Category => Descriptor.Category;

        public KarProjectFileCapability Capabilities { get; }

        public IReadOnlyList<KarProjectFileCapability> CapabilityList => _capabilityList;

        public bool CanReadBytes => HasCapability(KarProjectFileCapability.ReadBytes);

        public bool CanCopyToOutput => HasCapability(KarProjectFileCapability.CopyToOutput);

        public bool CanReplaceFileInOutput => HasCapability(KarProjectFileCapability.ReplaceFileInOutput);

        public bool CanInspectHsdArchive => HasCapability(KarProjectFileCapability.InspectHsdArchive);

        public bool CanQueryHsdRoots => HasCapability(KarProjectFileCapability.QueryHsdRoots);

        public bool CanEditHsdScalarFields => HasCapability(KarProjectFileCapability.EditHsdScalarFields);

        public bool CanOpenA2DPackage => HasCapability(KarProjectFileCapability.OpenA2DPackage);

        public bool CanListA2DEntries => HasCapability(KarProjectFileCapability.ListA2DEntries);

        public bool CanExtractA2DEntries => HasCapability(KarProjectFileCapability.ExtractA2DEntries);

        public bool CanReplaceA2DEntries => HasCapability(KarProjectFileCapability.ReplaceA2DEntries);

        public bool CanListScriptTables => HasCapability(KarProjectFileCapability.ListScriptTables);

        public bool CanGroupWithMap => HasCapability(KarProjectFileCapability.GroupWithMap);

        public bool CanInspectMapArchive => HasCapability(KarProjectFileCapability.InspectMapArchive);

        public bool HasCapability(KarProjectFileCapability capability)
        {
            return capability != KarProjectFileCapability.None &&
                (Capabilities & capability) == capability;
        }

        public static KarProjectFileHandler CreateDefault(KarFileKindDescriptor descriptor)
        {
            if (descriptor == null)
                throw new ArgumentNullException(nameof(descriptor));

            KarProjectFileCapability capabilities =
                KarProjectFileCapability.ReadBytes |
                KarProjectFileCapability.CopyToOutput |
                KarProjectFileCapability.ReplaceFileInOutput;

            if (descriptor.IsHsdArchive)
            {
                capabilities |=
                    KarProjectFileCapability.InspectHsdArchive |
                    KarProjectFileCapability.QueryHsdRoots |
                    KarProjectFileCapability.EditHsdScalarFields;
            }

            if (descriptor.IsA2DPackage)
            {
                capabilities |=
                    KarProjectFileCapability.OpenA2DPackage |
                    KarProjectFileCapability.ListA2DEntries |
                    KarProjectFileCapability.ExtractA2DEntries |
                    KarProjectFileCapability.ReplaceA2DEntries |
                    KarProjectFileCapability.ListScriptTables;
            }

            if (descriptor.IsScriptTable)
                capabilities |= KarProjectFileCapability.ListScriptTables;

            if (descriptor.IsMapBundlePart)
            {
                capabilities |= KarProjectFileCapability.GroupWithMap;
                if (descriptor.IsHsdArchive)
                    capabilities |= KarProjectFileCapability.InspectMapArchive;
            }

            return new KarProjectFileHandler(descriptor, capabilities);
        }
    }
}
