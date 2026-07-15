using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectFileStore
    {
        private readonly KarProjectWorkspace _workspace;
        private readonly KarProjectIndex _index;

        public KarProjectFileStore(KarProjectWorkspace workspace, KarProjectIndex index)
        {
            _workspace = workspace ?? throw new ArgumentNullException(nameof(workspace));
            _index = index ?? throw new ArgumentNullException(nameof(index));
        }

        public string GetReadPath(string relativePath)
        {
            return _index.GetFile(relativePath).ReadPath;
        }

        public string GetSourcePath(string relativePath)
        {
            return _index.GetFile(relativePath).SourcePath;
        }

        public string GetOutputPath(string relativePath)
        {
            return _workspace.GetOutputPath(relativePath);
        }

        public string CopyToOutput(string relativePath, bool overwrite = false)
        {
            return CopyFileToOutput(relativePath, overwrite).OutputPath;
        }

        public KarProjectFileCopyResult CopyFileToOutput(string relativePath, bool overwrite = false)
        {
            KarProjectFile file = _index.GetFile(relativePath);
            DateTime sourceLastWriteTimeUtc = File.GetLastWriteTimeUtc(file.SourcePath);
            string outputPath = _workspace.CopyToOutput(file.RelativePath, overwrite);

            if (File.GetLastWriteTimeUtc(file.SourcePath) != sourceLastWriteTimeUtc)
                throw new InvalidOperationException("Source file timestamp changed while copying: " + file.RelativePath);

            return new KarProjectFileCopyResult(file, outputPath, sourceLastWriteTimeUtc);
        }

        public IReadOnlyList<string> CopyMapToOutput(string mapNameOrPath, bool overwrite = false)
        {
            return CopyMapFilesToOutput(mapNameOrPath, overwrite)
                .Select(result => result.OutputPath)
                .ToList()
                .AsReadOnly();
        }

        public IReadOnlyList<string> CopyMapToOutput(KarMapBundle map, bool overwrite = false)
        {
            return CopyMapFilesToOutput(map, overwrite)
                .Select(result => result.OutputPath)
                .ToList()
                .AsReadOnly();
        }

        public IReadOnlyList<KarProjectFileCopyResult> CopyMapFilesToOutput(string mapNameOrPath, bool overwrite = false)
        {
            return CopyMapFilesToOutput(_index.GetMap(mapNameOrPath), overwrite);
        }

        public IReadOnlyList<KarProjectFileCopyResult> CopyMapFilesToOutput(KarMapBundle map, bool overwrite = false)
        {
            if (map == null)
                throw new ArgumentNullException(nameof(map));

            return map.Files
                .Select(file => CopyFileToOutput(file.RelativePath, overwrite))
                .ToList()
                .AsReadOnly();
        }

        public byte[] ReadBytes(string relativePath)
        {
            return File.ReadAllBytes(GetReadPath(relativePath));
        }

        public string WriteBytes(string relativePath, byte[] data)
        {
            return WriteFileBytes(relativePath, data).OutputPath;
        }

        public KarProjectFileWriteResult WriteFileBytes(string relativePath, byte[] data)
        {
            if (data == null)
                throw new ArgumentNullException(nameof(data));

            string outputPath = _workspace.WriteBytes(relativePath, data);
            return CreateWriteResult(relativePath, outputPath);
        }

        internal KarProjectFileWriteResult CreateWriteResult(string relativePath, string outputPath)
        {
            string normalized = KarProjectWorkspace.NormalizeRelativePath(relativePath);
            KarProjectFile file;
            _index.TryGetFile(normalized, out file);
            return new KarProjectFileWriteResult(file, normalized, outputPath, File.GetLastWriteTimeUtc(outputPath));
        }
    }
}
