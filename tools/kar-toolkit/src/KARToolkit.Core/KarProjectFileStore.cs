using HSDRaw;
using KARToolkit.Core.AirRide;
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

        public HSDRawFile OpenHsdFile(string relativePath)
        {
            return new HSDRawFile(GetReadPath(relativePath));
        }

        public bool TryOpenA2DPackage(string relativePath, out A2DPackage package, out string error)
        {
            return A2DPackage.TryOpen(GetReadPath(relativePath), out package, out error);
        }

        public A2DPackage OpenA2DPackage(string relativePath)
        {
            A2DPackage package;
            string error;
            if (!TryOpenA2DPackage(relativePath, out package, out error))
                throw new InvalidDataException(error);

            return package;
        }

        public string SaveHsdFile(string relativePath, HSDRawFile file, bool bufferAlign = true, bool optimize = true, bool trim = false)
        {
            if (file == null)
                throw new ArgumentNullException(nameof(file));

            return _workspace.SaveOutputFile(relativePath, tempPath => file.Save(tempPath, bufferAlign, optimize, trim));
        }

        public string SaveA2DPackage(string relativePath, A2DPackage package)
        {
            if (package == null)
                throw new ArgumentNullException(nameof(package));

            return _workspace.SaveOutputFile(relativePath, package.Save);
        }
    }
}
