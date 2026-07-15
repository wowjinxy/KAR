using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectOperationBatchResult
    {
        private readonly IReadOnlyList<KarProjectOperationExecutionResult> _results;
        private readonly IReadOnlyList<KarProjectOperationExecutionResult> _succeededResults;
        private readonly IReadOnlyList<KarProjectOperationExecutionResult> _failedResults;

        internal KarProjectOperationBatchResult(
            bool overwrite,
            bool continueOnError,
            IReadOnlyList<KarProjectOperationExecutionResult> results)
        {
            Overwrite = overwrite;
            ContinueOnError = continueOnError;
            _results = (results ?? throw new ArgumentNullException(nameof(results))).ToList().AsReadOnly();
            _succeededResults = _results.Where(result => result.Succeeded).ToList().AsReadOnly();
            _failedResults = _results.Where(result => result.Failed).ToList().AsReadOnly();
        }

        public bool Overwrite { get; }

        public bool ContinueOnError { get; }

        public IReadOnlyList<KarProjectOperationExecutionResult> Results => _results;

        public IReadOnlyList<KarProjectOperationExecutionResult> SucceededResults => _succeededResults;

        public IReadOnlyList<KarProjectOperationExecutionResult> FailedResults => _failedResults;

        public int ResultCount => Results.Count;

        public int SucceededCount => SucceededResults.Count;

        public int FailedCount => FailedResults.Count;

        public int ReadOnlyCount => Results.Count(result => result.IsReadOnly);

        public int WriteActionCount => Results.Count(result => result.WritesOutput);

        public int WouldWriteOutputCount => Results.Count(result => result.WouldWriteOutput);

        public int WroteOutputCount => Results.Count(result => result.WroteOutput);

        public int SkippedOutputWriteCount => Results.Count(result => result.SkippedOutputWrite);

        public bool HasResults => ResultCount != 0;

        public bool HasFailures => FailedCount != 0;

        public bool AllSucceeded => FailedCount == 0;
    }
}
