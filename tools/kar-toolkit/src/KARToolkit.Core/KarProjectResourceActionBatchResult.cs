using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectResourceActionBatchResult
    {
        private readonly IReadOnlyList<KarProjectResourceActionExecutionResult> _results;
        private readonly IReadOnlyList<KarProjectResourceActionExecutionResult> _succeededResults;
        private readonly IReadOnlyList<KarProjectResourceActionExecutionResult> _failedResults;

        internal KarProjectResourceActionBatchResult(
            string actionId,
            bool overwrite,
            bool continueOnError,
            IReadOnlyList<KarProjectResourceActionExecutionResult> results)
        {
            if (string.IsNullOrWhiteSpace(actionId))
                throw new ArgumentException("Batch resource action id cannot be empty.", nameof(actionId));

            ActionId = actionId;
            Overwrite = overwrite;
            ContinueOnError = continueOnError;
            _results = (results ?? throw new ArgumentNullException(nameof(results))).ToList().AsReadOnly();
            _succeededResults = _results.Where(result => result.Succeeded).ToList().AsReadOnly();
            _failedResults = _results.Where(result => result.Failed).ToList().AsReadOnly();
        }

        public string ActionId { get; }

        public bool Overwrite { get; }

        public bool ContinueOnError { get; }

        public IReadOnlyList<KarProjectResourceActionExecutionResult> Results => _results;

        public IReadOnlyList<KarProjectResourceActionExecutionResult> SucceededResults => _succeededResults;

        public IReadOnlyList<KarProjectResourceActionExecutionResult> FailedResults => _failedResults;

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
