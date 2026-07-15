using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceScalarEditResult
    {
        internal KarProjectResourceScalarEditResult(
            KarProjectResourceInfo resource,
            KarProjectScalarEditResult scalarEditResult)
        {
            Resource = resource ?? throw new ArgumentNullException(nameof(resource));
            ScalarEditResult = scalarEditResult ?? throw new ArgumentNullException(nameof(scalarEditResult));
        }

        public KarProjectResourceInfo Resource { get; }

        public KarResourceReference Reference => Resource.Reference;

        public string Address => Resource.Address;

        public KarProjectScalarEditResult ScalarEditResult { get; }

        public KarDataFieldEditResult Edit => ScalarEditResult.Edit;

        public KarProjectFile File => ScalarEditResult.File;

        public string RelativePath => ScalarEditResult.RelativePath;

        public KarProjectFileWriteResult WriteResult => ScalarEditResult.WriteResult;

        public string OutputPath => ScalarEditResult.OutputPath;
    }
}
