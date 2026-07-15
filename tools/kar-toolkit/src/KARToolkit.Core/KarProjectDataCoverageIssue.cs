using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectDataCoverageIssue
    {
        internal KarProjectDataCoverageIssue(
            KarProjectDataCoverageIssueKind kind,
            string message,
            KarProjectFile file,
            KarArchiveRootInfo root,
            KarRootDefinition missingRoot)
        {
            Kind = kind;
            Message = message ?? throw new ArgumentNullException(nameof(message));
            File = file ?? throw new ArgumentNullException(nameof(file));
            Root = root;
            MissingRoot = missingRoot;
        }

        public KarProjectDataCoverageIssueKind Kind { get; }

        public string Code => Kind.ToString();

        public string Message { get; }

        public KarProjectFile File { get; }

        public KarArchiveRootInfo Root { get; }

        public KarRootDefinition MissingRoot { get; }

        public string RelativePath => File.RelativePath;

        public string RootName => Root == null ? null : Root.Name;

        public string MissingRootPattern => MissingRoot == null ? null : MissingRoot.Pattern;

        public string AccessorTypeName => Root == null ? null : Root.AccessorTypeName;

        public int? StructLength => Root == null ? (int?)null : Root.StructLength;

        public string StructLengthHex => Root == null ? null : Root.StructLengthHex;

        public string ExpectedAccessorTypeName
        {
            get
            {
                if (Root != null)
                    return Root.ExpectedAccessorTypeName;

                return MissingRoot == null ? null : MissingRoot.AccessorTypeName;
            }
        }

        public string DisplayAccessorTypeName
        {
            get
            {
                if (Root != null)
                    return Root.DisplayAccessorTypeName;

                return MissingRoot == null ? null : MissingRoot.AccessorTypeName;
            }
        }

        public string DataDefinitionId
        {
            get
            {
                if (Root != null)
                    return Root.DataDefinitionId;

                return MissingRoot == null ? null : MissingRoot.DataDefinitionId;
            }
        }

        public string Category
        {
            get
            {
                if (Root != null && Root.DataDefinition != null)
                    return Root.DataDefinition.Category;

                return File.Category;
            }
        }

        public bool HasRoot => Root != null;

        public bool IsArchiveIssue => Root == null && MissingRoot == null;

        public bool IsMissingRequiredRoot => MissingRoot != null;

        public bool IsRootIssue => Root != null;
    }
}
