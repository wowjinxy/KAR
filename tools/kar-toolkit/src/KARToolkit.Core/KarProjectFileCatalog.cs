using System;
using System.Collections.Generic;

namespace KARToolkit.Core
{
    public class KarProjectFileCatalog
    {
        public static KarProjectFileCatalog Default { get; } = new KarProjectFileCatalog();

        private readonly KarFileKindRegistry _fileKinds;
        private readonly KarProjectFileHandlerRegistry _fileHandlers;
        private readonly KarArchiveDefinitionProvider _archiveDefinitions;

        public KarProjectFileCatalog()
            : this(KarArchiveDefinitionProvider.Default, KarProjectFileHandlerRegistry.Default)
        {
        }

        public KarProjectFileCatalog(KarArchiveDefinitionProvider archiveDefinitions)
            : this(archiveDefinitions, KarProjectFileHandlerRegistry.Default)
        {
        }

        public KarProjectFileCatalog(KarFileKindRegistry fileKinds)
            : this(KarArchiveDefinitionProvider.Default, new KarProjectFileHandlerRegistry(fileKinds))
        {
        }

        public KarProjectFileCatalog(KarProjectFileHandlerRegistry fileHandlers)
            : this(KarArchiveDefinitionProvider.Default, fileHandlers)
        {
        }

        public KarProjectFileCatalog(KarArchiveDefinitionProvider archiveDefinitions, KarFileKindRegistry fileKinds)
            : this(archiveDefinitions, new KarProjectFileHandlerRegistry(fileKinds))
        {
        }

        public KarProjectFileCatalog(KarArchiveDefinitionProvider archiveDefinitions, KarProjectFileHandlerRegistry fileHandlers)
        {
            _archiveDefinitions = archiveDefinitions ?? throw new ArgumentNullException(nameof(archiveDefinitions));
            _fileHandlers = fileHandlers ?? throw new ArgumentNullException(nameof(fileHandlers));
            _fileKinds = _fileHandlers.FileKindRegistry;
        }

        public KarFileKindRegistry FileKindRegistry => _fileKinds;

        public KarProjectFileHandlerRegistry FileHandlerRegistry => _fileHandlers;

        public IReadOnlyList<KarFileKindDescriptor> FileKindDescriptors => _fileKinds.Descriptors;

        public IReadOnlyList<KarProjectFileHandler> FileHandlers => _fileHandlers.Handlers;

        public KarArchiveDefinitionProvider ArchiveDefinitions => _archiveDefinitions;

        public virtual KarFileKindMatch Classify(string relativePath)
        {
            return _fileKinds.Classify(relativePath);
        }

        public virtual KarFileKind ClassifyKind(string relativePath)
        {
            return Classify(relativePath).Kind;
        }

        public virtual KarFileKindDescriptor DescribeKind(KarFileKind kind)
        {
            return _fileKinds.GetDescriptor(kind);
        }

        public virtual KarProjectFileHandler GetHandler(KarFileKind kind)
        {
            return _fileHandlers.GetHandler(kind);
        }

        public virtual KarProjectFileHandler GetHandler(KarFileKindMatch match)
        {
            return _fileHandlers.GetHandler(match);
        }

        public virtual KarArchiveDefinition GetArchiveDefinition(string relativePath)
        {
            return GetArchiveDefinition(Classify(relativePath));
        }

        public virtual KarArchiveDefinition GetArchiveDefinition(KarFileKindMatch match)
        {
            if (match == null)
                throw new ArgumentNullException(nameof(match));

            return _archiveDefinitions.GetDefinition(match.RelativePath, match.Kind, match.MapName);
        }

        public virtual KarArchiveDefinition GetArchiveDefinition(string relativePath, KarFileKind kind)
        {
            string mapName;
            if (TryGetMapName(relativePath, kind, out mapName))
                return _archiveDefinitions.GetDefinition(relativePath, kind, mapName);

            return _archiveDefinitions.GetDefinition(relativePath, kind, null);
        }

        public virtual bool IsHsdArchiveKind(KarFileKind kind)
        {
            return _fileKinds.IsHsdArchiveKind(kind);
        }

        public virtual bool IsA2DPackageKind(KarFileKind kind)
        {
            return _fileKinds.IsA2DPackageKind(kind);
        }

        public virtual bool IsScriptTableKind(KarFileKind kind)
        {
            return _fileKinds.IsScriptTableKind(kind);
        }

        public virtual bool TryGetMapName(string relativePath, KarFileKind kind, out string mapName)
        {
            return _fileKinds.TryGetMapName(relativePath, kind, out mapName);
        }
    }
}
