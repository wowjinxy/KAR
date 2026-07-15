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
            KarProjectFile file = _index.GetFile(relativePath);
            return _workspace.CopyToOutput(file.RelativePath, overwrite);
        }

        public IReadOnlyList<string> CopyMapToOutput(string mapNameOrPath, bool overwrite = false)
        {
            return CopyMapToOutput(_index.GetMap(mapNameOrPath), overwrite);
        }

        public IReadOnlyList<string> CopyMapToOutput(KarMapBundle map, bool overwrite = false)
        {
            if (map == null)
                throw new ArgumentNullException(nameof(map));

            return map.Files
                .Select(file => CopyToOutput(file.RelativePath, overwrite))
                .ToList()
                .AsReadOnly();
        }

        public byte[] ReadBytes(string relativePath)
        {
            return File.ReadAllBytes(GetReadPath(relativePath));
        }

        public string WriteBytes(string relativePath, byte[] data)
        {
            if (data == null)
                throw new ArgumentNullException(nameof(data));

            return _workspace.WriteBytes(relativePath, data);
        }
    }
}
