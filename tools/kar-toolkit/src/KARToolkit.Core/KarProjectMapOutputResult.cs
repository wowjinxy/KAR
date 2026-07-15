using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectMapOutputResult
    {
        public KarProjectMapOutputResult(
            KarMapBundle bundle,
            IEnumerable<KarProjectFileCopyResult> copyResults,
            IEnumerable<KarProjectFileWriteResult> writeResults)
        {
            Bundle = bundle ?? throw new ArgumentNullException(nameof(bundle));
            CopyResults = (copyResults ?? Enumerable.Empty<KarProjectFileCopyResult>())
                .ToList()
                .AsReadOnly();
            WriteResults = (writeResults ?? Enumerable.Empty<KarProjectFileWriteResult>())
                .ToList()
                .AsReadOnly();
            OutputPaths = CopyResults
                .Select(result => result.OutputPath)
                .Concat(WriteResults.Select(result => result.OutputPath))
                .ToList()
                .AsReadOnly();
        }

        public KarMapBundle Bundle { get; }

        public string Name => Bundle.Name;

        public IReadOnlyList<KarProjectFileCopyResult> CopyResults { get; }

        public IReadOnlyList<KarProjectFileWriteResult> WriteResults { get; }

        public IReadOnlyList<string> OutputPaths { get; }

        public int FileCount => OutputPaths.Count;

        public bool HasCopyResults => CopyResults.Count != 0;

        public bool HasWriteResults => WriteResults.Count != 0;

        public KarProjectFileCopyResult DataCopyResult => FindCopyResult(Bundle.DataFile);

        public KarProjectFileCopyResult ModelCopyResult => FindCopyResult(Bundle.ModelFile);

        public KarProjectFileCopyResult EventCopyResult => FindCopyResult(Bundle.EventFile);

        public KarProjectFileCopyResult ScriptCopyResult => EventCopyResult;

        public KarProjectFileWriteResult DataWriteResult => FindWriteResult(Bundle.DataFile);

        public KarProjectFileWriteResult ModelWriteResult => FindWriteResult(Bundle.ModelFile);

        public KarProjectFileWriteResult EventWriteResult => FindWriteResult(Bundle.EventFile);

        public KarProjectFileWriteResult ScriptWriteResult => EventWriteResult;

        private KarProjectFileCopyResult FindCopyResult(KarProjectFile file)
        {
            if (file == null)
                return null;

            return CopyResults.FirstOrDefault(result =>
                ReferenceEquals(result.File, file) ||
                string.Equals(result.File.RelativePath, file.RelativePath, StringComparison.OrdinalIgnoreCase));
        }

        private KarProjectFileWriteResult FindWriteResult(KarProjectFile file)
        {
            if (file == null)
                return null;

            return WriteResults.FirstOrDefault(result =>
                IsWriteResultForFile(result, file) ||
                string.Equals(result.RelativePath, file.RelativePath, StringComparison.OrdinalIgnoreCase));
        }

        private static bool IsWriteResultForFile(KarProjectFileWriteResult result, KarProjectFile file)
        {
            if (result.File == null)
                return false;

            return ReferenceEquals(result.File, file) ||
                string.Equals(result.File.RelativePath, file.RelativePath, StringComparison.OrdinalIgnoreCase);
        }
    }
}
