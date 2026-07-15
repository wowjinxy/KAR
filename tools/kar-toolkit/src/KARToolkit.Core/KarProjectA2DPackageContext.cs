using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectA2DPackageContext
    {
        internal KarProjectA2DPackageContext(
            KarProjectFile packageFile,
            KarProjectA2DPackage package,
            string openError,
            KarProjectResourceInfo resource,
            KarProjectResourceOutputInfo output,
            IReadOnlyList<KarProjectA2DEntryInfo> entries,
            IReadOnlyList<KarProjectA2DEntryOutputInfo> entryOutputs,
            IReadOnlyList<KarProjectScriptTableContext> scriptContexts)
        {
            PackageFile = packageFile ?? throw new ArgumentNullException(nameof(packageFile));
            Package = package;
            OpenError = openError;
            Resource = resource;
            Output = output;
            Entries = entries ?? throw new ArgumentNullException(nameof(entries));
            EntryOutputs = entryOutputs ?? throw new ArgumentNullException(nameof(entryOutputs));
            ScriptContexts = scriptContexts ?? throw new ArgumentNullException(nameof(scriptContexts));

            _entryOutputsByEntryPath = EntryOutputs.ToDictionary(outputInfo => outputInfo.EntryPath, StringComparer.OrdinalIgnoreCase);
        }

        private readonly Dictionary<string, KarProjectA2DEntryOutputInfo> _entryOutputsByEntryPath;

        public KarProjectFile PackageFile { get; }

        public KarProjectA2DPackage Package { get; }

        public string OpenError { get; }

        public KarProjectResourceInfo Resource { get; }

        public KarProjectResourceOutputInfo Output { get; }

        public IReadOnlyList<KarProjectA2DEntryInfo> Entries { get; }

        public IReadOnlyList<KarProjectA2DEntryOutputInfo> EntryOutputs { get; }

        public IReadOnlyList<KarProjectScriptTableContext> ScriptContexts { get; }

        public string RelativePath => PackageFile.RelativePath;

        public string ReadPath => Package == null ? PackageFile.ReadPath : Package.ReadPath;

        public bool IsOpen => Package != null;

        public bool HasOpenError => !string.IsNullOrEmpty(OpenError);

        public int EntryCount => Entries.Count;

        public int ScriptTableCount => ScriptContexts.Count;

        public int EntryOutputCount => EntryOutputs.Count(output => output.HasOutput);

        public int ModifiedEntryOutputCount => EntryOutputs.Count(output => output.Status == KarProjectA2DEntryOutputStatus.DiffersFromEntry);

        public int MatchingEntryOutputCount => EntryOutputs.Count(output => output.Status == KarProjectA2DEntryOutputStatus.MatchesEntry);

        public bool HasEntries => Entries.Count != 0;

        public bool HasScriptTables => ScriptContexts.Count != 0;

        public bool HasOutput => Output != null && Output.HasOutput;

        public bool HasModifiedOutput => Output != null && Output.IsModified;

        public bool HasEntryOutputs => EntryOutputCount != 0;

        public bool HasModifiedEntryOutputs => ModifiedEntryOutputCount != 0;

        public KarProjectResourceOutputStatus? OutputStatus => Output == null ? (KarProjectResourceOutputStatus?)null : Output.Status;

        public KarProjectResourceOutputKind? OutputKind => Output == null ? (KarProjectResourceOutputKind?)null : Output.OutputKind;

        public KarProjectA2DEntryOutputInfo GetEntryOutput(KarProjectA2DEntryInfo entry)
        {
            if (entry == null)
                throw new ArgumentNullException(nameof(entry));

            KarProjectA2DEntryOutputInfo output;
            return _entryOutputsByEntryPath.TryGetValue(entry.EntryPath, out output) ? output : null;
        }

        public KarProjectA2DPackageContextSummaryContract CreateContract()
        {
            return KarProjectA2DPackageContextSummaryContract.Create(this);
        }
    }
}
