using KARToolkit.Core.AirRide;
using System;
using System.Collections.Generic;

namespace KARToolkit.Core
{
    public sealed class KarProjectValidator
    {
        private readonly KarProject _project;
        private readonly KarProjectIndex _index;
        private readonly KarProjectFileCatalog _fileCatalog;
        private readonly KarProjectInspector _inspector;
        private readonly KarProjectArchiveStore _archiveStore;
        private readonly KarValidationOptions _defaultOptions;

        public KarProjectValidator(KarProject project, KarValidationOptions options = null)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
            _index = project.Index;
            _fileCatalog = project.FileCatalog;
            _inspector = project.Inspector;
            _archiveStore = project.ArchiveStore;
            _defaultOptions = options;
        }

        public KarValidationReport Validate()
        {
            return Validate(_defaultOptions);
        }

        public KarValidationReport Validate(KarValidationOptions options)
        {
            return new ValidationRun(
                _project,
                _index,
                _fileCatalog,
                _inspector,
                _archiveStore,
                options ?? _defaultOptions ?? new KarValidationOptions())
                .Validate();
        }

        private sealed class ValidationRun
        {
            private readonly KarProject _project;
            private readonly KarProjectIndex _index;
            private readonly KarProjectFileCatalog _fileCatalog;
            private readonly KarProjectInspector _inspector;
            private readonly KarProjectArchiveStore _archiveStore;
            private readonly KarValidationOptions _options;
            private readonly List<KarValidationIssue> _issues = new List<KarValidationIssue>();
            private int _hsdArchiveCount;
            private int _a2dPackageCount;

            public ValidationRun(
                KarProject project,
                KarProjectIndex index,
                KarProjectFileCatalog fileCatalog,
                KarProjectInspector inspector,
                KarProjectArchiveStore archiveStore,
                KarValidationOptions options)
            {
                _project = project ?? throw new ArgumentNullException(nameof(project));
                _index = index ?? throw new ArgumentNullException(nameof(index));
                _fileCatalog = fileCatalog ?? throw new ArgumentNullException(nameof(fileCatalog));
                _inspector = inspector ?? throw new ArgumentNullException(nameof(inspector));
                _archiveStore = archiveStore ?? throw new ArgumentNullException(nameof(archiveStore));
                _options = options ?? throw new ArgumentNullException(nameof(options));
            }

            public KarValidationReport Validate()
            {
                ValidateMaps();

                foreach (KarProjectFile file in _index.Files)
                {
                    if (_options.InspectHsdArchives && _fileCatalog.IsHsdArchiveKind(file.Kind))
                        ValidateHsdArchive(file);
                    else if (_options.InspectA2DPackages && file.Kind == KarFileKind.A2dPackage)
                        ValidateA2DPackage(file);
                }

                return new KarValidationReport(_project, _hsdArchiveCount, _a2dPackageCount, _issues);
            }

            private void ValidateMaps()
            {
                foreach (KarMapBundle map in _index.Maps)
                {
                    if (!map.HasDataFile)
                        Add(KarValidationSeverity.Error, "map-missing-data", "Map bundle has no data file.", null, map.Name, null);
                    if (_options.ReportMissingMapModels && !map.HasModelFile)
                        Add(KarValidationSeverity.Warning, "map-missing-model", "Map bundle has no model file.", null, map.Name, null);
                }
            }

            private void ValidateHsdArchive(KarProjectFile file)
            {
                _hsdArchiveCount++;

                KarArchiveInfo info;
                string error;
                if (!_inspector.TryInspectHsdArchive(file.RelativePath, out info, out error))
                {
                    Add(KarValidationSeverity.Error, "hsd-open-failed", "Could not open HSD archive: " + error, file.RelativePath, null, null);
                    return;
                }

                foreach (KarRootDefinition missing in info.MissingRequiredRoots)
                    Add(KarValidationSeverity.Error, "missing-required-root", "Missing required root: " + missing.Pattern, file.RelativePath, null, missing.Pattern);

                if (_options.ReportUnknownRoots)
                {
                    foreach (KarArchiveRootInfo root in info.UnknownRoots)
                        Add(KarValidationSeverity.Info, "unknown-root", "Root is not yet cataloged: " + root.Name, file.RelativePath, null, root.Name);
                }
            }

            private void ValidateA2DPackage(KarProjectFile file)
            {
                _a2dPackageCount++;

                A2DPackage package;
                string error;
                if (!_archiveStore.TryOpenA2DPackage(file.RelativePath, out package, out error))
                {
                    Add(KarValidationSeverity.Error, "a2d-open-failed", "Could not open A2D package: " + error, file.RelativePath, null, null);
                    return;
                }

                if (package.Entries.Count == 0)
                    Add(KarValidationSeverity.Warning, "a2d-empty", "A2D package has no entries.", file.RelativePath, null, null);
            }

            private void Add(KarValidationSeverity severity, string code, string message, string relativePath, string mapName, string rootName)
            {
                _issues.Add(new KarValidationIssue(severity, code, message, relativePath, mapName, rootName));
            }
        }
    }
}
