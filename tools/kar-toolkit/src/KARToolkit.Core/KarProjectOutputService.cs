using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectOutputService
    {
        private readonly KarProject _project;

        internal KarProjectOutputService(KarProject project)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
        }

        public KarProject Project => _project;

        public string Root => _project.OutputRoot;

        public string FilesRoot => _project.OutputFilesRoot;

        public IReadOnlyList<KarProjectOutputFileInfo> QueryFiles(KarProjectOutputFileQueryOptions options = null)
        {
            List<KarProjectOutputFileInfo> outputFiles = new List<KarProjectOutputFileInfo>();

            foreach (string relativePath in _project.Workspace.EnumerateOutputRelativePaths())
            {
                KarProjectOutputFileInfo outputFile = CreateFileInfo(relativePath);
                if (options == null || options.Matches(outputFile))
                    outputFiles.Add(outputFile);
            }

            return outputFiles
                .OrderBy(file => file.RelativePath, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public KarProjectOutputInventory CreateInventory(KarProjectOutputFileQueryOptions options = null)
        {
            return CreateInventory(QueryFiles(options));
        }

        internal KarProjectOutputInventory CreateInventory(IEnumerable<KarProjectOutputFileInfo> files)
        {
            return new KarProjectOutputInventory(_project, files);
        }

        public KarProjectOutputFileInfo GetFile(string relativePath)
        {
            KarProjectOutputFileInfo file;
            if (!TryGetFile(relativePath, out file))
                throw new FileNotFoundException("Project output file was not found.", KarProjectWorkspace.NormalizeRelativePath(relativePath));

            return file;
        }

        public bool TryGetFile(string relativePath, out KarProjectOutputFileInfo file)
        {
            string normalized = KarProjectWorkspace.NormalizeRelativePath(relativePath);
            string outputPath = _project.Workspace.GetOutputPath(normalized);
            if (!File.Exists(outputPath))
            {
                file = null;
                return false;
            }

            file = CreateFileInfo(normalized);
            return true;
        }

        public bool HasFile(string relativePath)
        {
            KarProjectOutputFileInfo file;
            return TryGetFile(relativePath, out file);
        }

        public IReadOnlyList<KarProjectOutputFileInfo> QueryModifiedProjectFiles()
        {
            return QueryFiles(new KarProjectOutputFileQueryOptions
            {
                IsProjectFile = true,
                Status = KarProjectOutputFileStatus.DiffersFromSource,
            });
        }

        public IReadOnlyList<KarProjectOutputFileInfo> QueryUnchangedProjectFiles()
        {
            return QueryFiles(new KarProjectOutputFileQueryOptions
            {
                IsProjectFile = true,
                Status = KarProjectOutputFileStatus.MatchesSource,
            });
        }

        public IReadOnlyList<KarProjectOutputFileInfo> QueryOrphanFiles()
        {
            return QueryFiles(new KarProjectOutputFileQueryOptions
            {
                IsProjectFile = false,
                Status = KarProjectOutputFileStatus.Orphan,
            });
        }

        public IReadOnlyList<KarProjectOutputFileInfo> QueryMissingSourceFiles()
        {
            return QueryFiles(new KarProjectOutputFileQueryOptions
            {
                IsProjectFile = true,
                Status = KarProjectOutputFileStatus.SourceMissing,
            });
        }

        private KarProjectOutputFileInfo CreateFileInfo(string relativePath)
        {
            KarProjectFile projectFile;
            _project.FileService.TryGet(relativePath, out projectFile);

            KarFileKindMatch match = projectFile == null
                ? _project.FileCatalog.Classify(relativePath)
                : null;
            KarFileKind kind = projectFile == null ? match.Kind : projectFile.Kind;
            KarFileKindDescriptor kindDescriptor = projectFile == null ? match.Descriptor : projectFile.KindDescriptor;
            string mapName = projectFile == null ? match.MapName : projectFile.MapName;
            KarArchiveDefinition archiveDefinition = projectFile == null
                ? _project.FileCatalog.GetArchiveDefinition(match)
                : projectFile.ArchiveDefinition;

            return new KarProjectOutputFileInfo(
                projectFile,
                relativePath,
                _project.Workspace.GetOutputPath(relativePath),
                kind,
                kindDescriptor,
                mapName,
                archiveDefinition);
        }
    }
}
