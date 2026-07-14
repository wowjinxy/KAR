using KARToolkit.Core.AirRide;
using System;
using System.Collections.Generic;

namespace KARToolkit.Core
{
    public sealed class KarProjectValidator
    {
        private readonly KarProject _project;
        private readonly KarValidationOptions _options;
        private readonly List<KarValidationIssue> _issues = new List<KarValidationIssue>();
        private int _hsdArchiveCount;
        private int _a2dPackageCount;

        public KarProjectValidator(KarProject project, KarValidationOptions options = null)
        {
            _project = project ?? throw new ArgumentNullException(nameof(project));
            _options = options ?? new KarValidationOptions();
        }

        public KarValidationReport Validate()
        {
            ValidateMaps();

            foreach (KarProjectFile file in _project.Files)
            {
                if (_options.InspectHsdArchives && KarArchiveCatalog.IsHsdArchiveKind(file.Kind))
                    ValidateHsdArchive(file);
                else if (_options.InspectA2DPackages && file.Kind == KarFileKind.A2dPackage)
                    ValidateA2DPackage(file);
            }

            return new KarValidationReport(_project, _hsdArchiveCount, _a2dPackageCount, _issues);
        }

        private void ValidateMaps()
        {
            foreach (KarMapBundle map in _project.Maps)
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
            if (!_project.TryInspectHsdArchive(file.RelativePath, out info, out error))
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
            if (!_project.TryOpenA2DPackage(file.RelativePath, out package, out error))
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
