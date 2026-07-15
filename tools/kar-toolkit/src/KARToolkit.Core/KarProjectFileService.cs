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
            return _project.FileStore.CopyFileToOutput(relativePath, overwrite);
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
            return _project.FileStore.WriteFileBytes(relativePath, data);
        }
    }
}
