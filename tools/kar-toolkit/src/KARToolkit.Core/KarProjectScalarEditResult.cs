using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectScalarEditResult
    {
        public KarProjectScalarEditResult(
            KarProjectHsdArchive archive,
            KarDataFieldEditResult edit,
            KarProjectFileWriteResult writeResult)
        {
            Archive = archive ?? throw new ArgumentNullException(nameof(archive));
            Edit = edit ?? throw new ArgumentNullException(nameof(edit));
            WriteResult = writeResult ?? throw new ArgumentNullException(nameof(writeResult));
        }

        public KarProjectHsdArchive Archive { get; }

        public KarProjectFile File => Archive.File;

        public string RelativePath => Archive.RelativePath;

        public KarDataFieldEditResult Edit { get; }

        public KarProjectFileWriteResult WriteResult { get; }

        public string OutputPath => WriteResult.OutputPath;
    }
}
