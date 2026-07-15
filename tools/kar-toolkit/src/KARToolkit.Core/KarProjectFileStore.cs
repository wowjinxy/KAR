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
            return GetFile(relativePath).ReadPath;
        }

        public KarProjectFile GetFile(string relativePath)
        {
            return _index.GetFile(relativePath);
        }

        public bool TryGetFile(string relativePath, out KarProjectFile file)
        {
            return _index.TryGetFile(relativePath, out file);
        }

        public string GetSourcePath(string relativePath)
        {
            return GetFile(relativePath).SourcePath;
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
            KarProjectFile file = GetFile(relativePath);
            DateTime sourceLastWriteTimeUtc = File.GetLastWriteTimeUtc(file.SourcePath);
            string outputPath = _workspace.CopyToOutput(file.RelativePath, overwrite);

            if (File.GetLastWriteTimeUtc(file.SourcePath) != sourceLastWriteTimeUtc)
                throw new InvalidOperationException("Source file timestamp changed while copying: " + file.RelativePath);

            return new KarProjectFileCopyResult(file, outputPath, sourceLastWriteTimeUtc);
        }

        public IReadOnlyList<string> CopyMapToOutput(string mapNameOrPath, bool overwrite = false)
        {
            return CopyMapToOutputResult(mapNameOrPath, overwrite).OutputPaths;
        }

        public IReadOnlyList<string> CopyMapToOutput(KarMapBundle map, bool overwrite = false)
        {
            return CopyMapToOutputResult(map, overwrite).OutputPaths;
        }

        public KarProjectMapOutputResult CopyMapToOutputResult(string mapNameOrPath, bool overwrite = false)
        {
            return CopyMapToOutputResult(_index.GetMap(mapNameOrPath), overwrite);
        }

        public KarProjectMapOutputResult CopyMapToOutputResult(KarMapBundle map, bool overwrite = false)
        {
            return new KarProjectMapOutputResult(map, CopyMapFilesToOutputCore(map, overwrite), null);
        }

        public IReadOnlyList<KarProjectFileCopyResult> CopyMapFilesToOutput(string mapNameOrPath, bool overwrite = false)
        {
            return CopyMapToOutputResult(mapNameOrPath, overwrite).CopyResults;
        }

        public IReadOnlyList<KarProjectFileCopyResult> CopyMapFilesToOutput(KarMapBundle map, bool overwrite = false)
        {
            return CopyMapToOutputResult(map, overwrite).CopyResults;
        }

        private IReadOnlyList<KarProjectFileCopyResult> CopyMapFilesToOutputCore(KarMapBundle map, bool overwrite)
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
