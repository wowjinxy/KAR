using System;
using System.Collections.Generic;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectMapService
    {
        private readonly KarProject _project;

        internal KarProjectMapService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public IReadOnlyList<KarMapBundle> Bundles => _project.Index.Maps;

        public IReadOnlyDictionary<string, KarMapBundle> ByName => _project.Index.MapsByName;

        public KarMapBundle Get(string mapNameOrPath)
        {
            return _project.Index.GetMap(mapNameOrPath);
        }

        public bool TryGet(string mapNameOrPath, out KarMapBundle map)
        {
            return _project.Index.TryGetMap(mapNameOrPath, out map);
        }

        public IReadOnlyList<KarProjectMapOutputInfo> QueryOutputs(KarProjectMapOutputQueryOptions options = null)
        {
            IReadOnlyList<KarProjectOutputFileInfo> outputFiles = _project.QueryOutputFiles(options == null ? null : options.Outputs);
            return KarProjectMapOutputInfo.BuildMany(Bundles, outputFiles, options);
        }

        public KarProjectMapOutputInfo GetOutput(string mapNameOrPath, KarProjectOutputFileQueryOptions outputOptions = null)
        {
            KarMapBundle map = Get(mapNameOrPath);
            KarProjectMapOutputQueryOptions query = new KarProjectMapOutputQueryOptions
            {
                Outputs = outputOptions,
                MapName = map.Name,
            };

            return QueryOutputs(query).Single();
        }

        public IReadOnlyList<string> CopyToOutput(string mapNameOrPath, bool overwrite = false)
        {
            return CopyToOutputResult(mapNameOrPath, overwrite).OutputPaths;
        }

        public IReadOnlyList<string> CopyToOutput(KarMapBundle map, bool overwrite = false)
        {
            return CopyToOutputResult(map, overwrite).OutputPaths;
        }

        public KarProjectMapOutputResult CopyToOutputResult(string mapNameOrPath, bool overwrite = false)
        {
            return CopyToOutputResult(Get(mapNameOrPath), overwrite);
        }

        public KarProjectMapOutputResult CopyToOutputResult(KarMapBundle map, bool overwrite = false)
        {
            return _project.FileStore.CopyMapToOutputResult(map, overwrite);
        }

        public IReadOnlyList<KarProjectFileCopyResult> CopyFilesToOutput(string mapNameOrPath, bool overwrite = false)
        {
            return CopyToOutputResult(mapNameOrPath, overwrite).CopyResults;
        }

        public IReadOnlyList<KarProjectFileCopyResult> CopyFilesToOutput(KarMapBundle map, bool overwrite = false)
        {
            return CopyToOutputResult(map, overwrite).CopyResults;
        }

        public KarProjectMapArchiveBundle OpenArchives(string mapNameOrPath)
        {
            return OpenArchives(Get(mapNameOrPath));
        }

        public KarProjectMapArchiveBundle OpenArchives(KarMapBundle map)
        {
            return _project.ArchiveStore.OpenMapArchives(map);
        }

        public KarMapInfo Inspect(string mapNameOrPath)
        {
            return Inspect(Get(mapNameOrPath));
        }

        public KarMapInfo Inspect(KarMapBundle map)
        {
            return _project.Inspector.InspectMap(map);
        }

        public bool TryInspect(string mapNameOrPath, out KarMapInfo info, out string error)
        {
            try
            {
                info = Inspect(mapNameOrPath);
                error = null;
                return true;
            }
            catch (Exception ex)
            {
                info = null;
                error = ex.Message;
                return false;
            }
        }
    }
}
