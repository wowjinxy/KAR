using HSDRaw;
using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectHsdArchive
    {
        private readonly KarProjectArchiveStore _archiveStore;
        private readonly KarArchiveInspector _archiveInspector;

        internal KarProjectHsdArchive(
            KarProjectArchiveStore archiveStore,
            KarArchiveInspector archiveInspector,
            KarProjectFile file,
            string readPath,
            HSDRawFile archive)
        {
            _archiveStore = archiveStore ?? throw new ArgumentNullException(nameof(archiveStore));
            _archiveInspector = archiveInspector ?? throw new ArgumentNullException(nameof(archiveInspector));
            File = file ?? throw new ArgumentNullException(nameof(file));
            ReadPath = readPath ?? throw new ArgumentNullException(nameof(readPath));
            Archive = archive ?? throw new ArgumentNullException(nameof(archive));
        }

        public KarProjectFile File { get; }

        public string RelativePath => File.RelativePath;

        public string ReadPath { get; }

        public HSDRawFile Archive { get; }

        public KarArchiveInfo Inspect()
        {
            return _archiveInspector.Inspect(File, Archive);
        }

        public KarDataFieldEditResult SetScalarField(string rootName, string fieldName, long value)
        {
            return SetScalarField(Inspect().GetRoot(rootName), fieldName, value);
        }

        public KarDataFieldEditResult SetScalarField(string rootName, string fieldName, double value)
        {
            return SetScalarField(Inspect().GetRoot(rootName), fieldName, value);
        }

        public KarDataFieldEditResult SetScalarFieldByDataDefinition(string idOrAccessorTypeName, string fieldName, long value)
        {
            return SetScalarField(Inspect().GetRootByDataDefinition(idOrAccessorTypeName), fieldName, value);
        }

        public KarDataFieldEditResult SetScalarFieldByDataDefinition(string idOrAccessorTypeName, string fieldName, double value)
        {
            return SetScalarField(Inspect().GetRootByDataDefinition(idOrAccessorTypeName), fieldName, value);
        }

        public KarProjectFileWriteResult SaveToOutput(bool bufferAlign = true, bool optimize = true, bool trim = false)
        {
            return _archiveStore.SaveHsdFileToOutput(RelativePath, Archive, bufferAlign, optimize, trim);
        }

        private KarDataFieldEditResult SetScalarField(KarArchiveRootInfo rootInfo, string fieldName, long value)
        {
            HSDRootNode root = GetEditableRootNode(rootInfo);
            return KarDataEditor.SetScalarField(root.Data, rootInfo.Name, rootInfo.DataDefinition, fieldName, value);
        }

        private KarDataFieldEditResult SetScalarField(KarArchiveRootInfo rootInfo, string fieldName, double value)
        {
            HSDRootNode root = GetEditableRootNode(rootInfo);
            return KarDataEditor.SetScalarField(root.Data, rootInfo.Name, rootInfo.DataDefinition, fieldName, value);
        }

        private HSDRootNode GetEditableRootNode(KarArchiveRootInfo rootInfo)
        {
            if (rootInfo.DataDefinition == null)
                throw new InvalidOperationException("KAR archive root has no data definition: " + rootInfo.Name);

            return GetRootNode(rootInfo.Name);
        }

        private HSDRootNode GetRootNode(string rootName)
        {
            HSDRootNode root = Archive.Roots.FirstOrDefault(candidate =>
                string.Equals(candidate.Name, rootName, StringComparison.Ordinal));
            if (root == null)
                throw new KeyNotFoundException("KAR archive root was not found: " + rootName);
            if (root.Data == null)
                throw new InvalidOperationException("KAR archive root has no accessor data: " + rootName);

            return root;
        }
    }
}
