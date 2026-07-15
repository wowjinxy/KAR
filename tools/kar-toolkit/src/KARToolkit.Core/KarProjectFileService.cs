using System;
using System.Collections.Generic;

namespace KARToolkit.Core
{
    public sealed class KarProjectFileService
    {
        private readonly KarProject _project;

        internal KarProjectFileService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public IReadOnlyList<KarProjectFile> Files => _project.Index.Files;

        public IReadOnlyDictionary<string, KarProjectFile> ByPath => _project.Index.FilesByPath;

        public KarProjectFile Get(string relativePath)
        {
            return _project.Index.GetFile(relativePath);
        }

        public bool TryGet(string relativePath, out KarProjectFile file)
        {
            return _project.Index.TryGetFile(relativePath, out file);
        }

        public IReadOnlyList<KarProjectFile> Query(KarProjectFileQueryOptions options = null)
        {
            return _project.Index.QueryFiles(options);
        }

        public KarProjectFileInsight GetInsight(string relativePath)
        {
            return _project.FileInsightService.Get(relativePath);
        }

        public KarProjectFileInsightContract GetInsightContract(string relativePath)
        {
            return _project.FileInsightService.GetContract(relativePath);
        }

        public IReadOnlyList<KarProjectFileInsight> QueryInsights(KarProjectFileQueryOptions options = null)
        {
            return _project.FileInsightService.Query(options);
        }

        public IReadOnlyList<KarProjectFileInsightContract> QueryInsightContracts(KarProjectFileQueryOptions options = null)
        {
            return _project.FileInsightService.QueryContracts(options);
        }

        public string GetReadPath(string relativePath)
        {
            return _project.FileStore.GetReadPath(relativePath);
        }

        public string GetSourcePath(string relativePath)
        {
            return _project.FileStore.GetSourcePath(relativePath);
        }

        public string GetOutputPath(string relativePath)
        {
            return _project.FileStore.GetOutputPath(relativePath);
        }

        public string CopyToOutput(string relativePath, bool overwrite = false)
        {
            return CopyFileToOutput(relativePath, overwrite).OutputPath;
        }

        public KarProjectFileCopyResult CopyFileToOutput(string relativePath, bool overwrite = false)
        {
            KarProjectFileCopyResult result = _project.FileStore.CopyFileToOutput(relativePath, overwrite);
            _project.ResourceGraphService.Invalidate();
            return result;
        }

        public byte[] ReadBytes(string relativePath)
        {
            return _project.FileStore.ReadBytes(relativePath);
        }

        public string WriteBytes(string relativePath, byte[] data)
        {
            return WriteFileBytes(relativePath, data).OutputPath;
        }

        public KarProjectFileWriteResult WriteFileBytes(string relativePath, byte[] data)
        {
            KarProjectFileWriteResult result = _project.FileStore.WriteFileBytes(relativePath, data);
            _project.ResourceGraphService.Invalidate();
            return result;
        }
    }
}
