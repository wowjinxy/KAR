using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectModManifest
    {
        internal KarProjectModManifest(KarProject project, KarProjectModWorkspace workspace)
        {
            Project = project ?? throw new ArgumentNullException(nameof(project));
            Workspace = workspace ?? throw new ArgumentNullException(nameof(workspace));
            Artifacts = CreateArtifacts(project, workspace);
            ProjectFileArtifacts = Filter(KarProjectModManifestArtifactKind.ProjectFile);
            OutputOnlyFileArtifacts = Filter(KarProjectModManifestArtifactKind.OutputOnlyFile);
            A2DEntrySidecarArtifacts = Filter(KarProjectModManifestArtifactKind.A2DEntrySidecar);
            ResourceByteDumpArtifacts = Filter(KarProjectModManifestArtifactKind.ResourceByteDump);
            ModifiedArtifacts = Artifacts
                .Where(artifact => artifact.IsModified)
                .ToList()
                .AsReadOnly();
            NeedsApplyArtifacts = Artifacts
                .Where(artifact => artifact.NeedsApply)
                .ToList()
                .AsReadOnly();
        }

        public KarProject Project { get; }

        public KarProjectModWorkspace Workspace { get; }

        public string Name => Project.Name;

        public string SourceRoot => Project.SourceRoot;

        public string OutputRoot => Project.OutputRoot;

        public string OutputFilesRoot => Project.OutputFilesRoot;

        public string ReadPolicy => Project.Workspace.ReadPolicy;

        public string WritePolicy => Project.Workspace.WritePolicy;

        public bool WritesOnlyToOutput => Project.Workspace.WritesOnlyToOutput;

        public bool SourceAndOutputRootsAreSeparate => Project.Workspace.SourceAndOutputRootsAreSeparate;

        public IReadOnlyList<KarProjectModManifestArtifact> Artifacts { get; }

        public IReadOnlyList<KarProjectModManifestArtifact> ProjectFileArtifacts { get; }

        public IReadOnlyList<KarProjectModManifestArtifact> OutputOnlyFileArtifacts { get; }

        public IReadOnlyList<KarProjectModManifestArtifact> A2DEntrySidecarArtifacts { get; }

        public IReadOnlyList<KarProjectModManifestArtifact> ResourceByteDumpArtifacts { get; }

        public IReadOnlyList<KarProjectModManifestArtifact> ModifiedArtifacts { get; }

        public IReadOnlyList<KarProjectModManifestArtifact> NeedsApplyArtifacts { get; }

        public int ArtifactCount => Artifacts.Count;

        public int ProjectFileArtifactCount => ProjectFileArtifacts.Count;

        public int OutputOnlyFileArtifactCount => OutputOnlyFileArtifacts.Count;

        public int A2DEntrySidecarArtifactCount => A2DEntrySidecarArtifacts.Count;

        public int ResourceByteDumpArtifactCount => ResourceByteDumpArtifacts.Count;

        public int ModifiedArtifactCount => ModifiedArtifacts.Count;

        public int NeedsApplyArtifactCount => NeedsApplyArtifacts.Count;

        public long TotalOutputLength => Artifacts.Sum(artifact => artifact.OutputLength);

        public bool HasArtifacts => ArtifactCount != 0;

        public bool HasModifiedArtifacts => ModifiedArtifactCount != 0;

        public bool HasArtifactsNeedingApply => NeedsApplyArtifactCount != 0;

        private IReadOnlyList<KarProjectModManifestArtifact> Filter(KarProjectModManifestArtifactKind kind)
        {
            return Artifacts
                .Where(artifact => artifact.Kind == kind)
                .ToList()
                .AsReadOnly();
        }

        private static IReadOnlyList<KarProjectModManifestArtifact> CreateArtifacts(
            KarProject project,
            KarProjectModWorkspace workspace)
        {
            List<KarProjectModManifestArtifact> artifacts = new List<KarProjectModManifestArtifact>();
            HashSet<string> richerArtifactPaths = CreateRicherArtifactPathSet(workspace);

            foreach (KarProjectOutputFileInfo output in workspace.OutputInventory.Files)
            {
                if (richerArtifactPaths.Contains(NormalizeFullPath(output.OutputPath)))
                    continue;

                artifacts.Add(CreateOutputFileArtifact(project, output));
            }

            foreach (KarProjectA2DEntryOutputInfo output in workspace.A2DEntryOutputs)
                artifacts.Add(CreateA2DEntrySidecarArtifact(project, output));

            foreach (KarProjectResourceByteInfo output in workspace.ResourceByteOutputs)
                artifacts.Add(CreateResourceByteDumpArtifact(project, output));

            return artifacts
                .OrderBy(artifact => artifact.OutputRelativePath, StringComparer.OrdinalIgnoreCase)
                .ThenBy(artifact => artifact.Kind.ToString(), StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        private static HashSet<string> CreateRicherArtifactPathSet(KarProjectModWorkspace workspace)
        {
            HashSet<string> paths = new HashSet<string>(StringComparer.OrdinalIgnoreCase);

            foreach (KarProjectA2DEntryOutputInfo output in workspace.A2DEntryOutputs)
                paths.Add(NormalizeFullPath(output.OutputPath));
            foreach (KarProjectResourceByteInfo output in workspace.ResourceByteOutputs)
                paths.Add(NormalizeFullPath(output.OutputPath));

            return paths;
        }

        private static KarProjectModManifestArtifact CreateOutputFileArtifact(
            KarProject project,
            KarProjectOutputFileInfo output)
        {
            return new KarProjectModManifestArtifact(
                output.IsProjectFile ? KarProjectModManifestArtifactKind.ProjectFile : KarProjectModManifestArtifactKind.OutputOnlyFile,
                project.Workspace.GetRelativeOutputAssetPath(output.OutputPath),
                output.OutputPath,
                output.ProjectFile == null ? null : output.ProjectFile.RelativePath,
                output.IsProjectFile ? output.ResourceAddress : null,
                output.IsProjectFile ? "source-file" : "output-only",
                output.IsProjectFile ? output.ResourceAddress : null,
                output.SourcePath,
                output.SourceLength,
                output.SourceSha256,
                output.Status.ToString(),
                output.OutputLength,
                output.OutputLastWriteTimeUtc,
                output.OutputSha256,
                output.IsModifiedProjectFile,
                output.IsUnchangedProjectFile,
                output.IsOrphan,
                false,
                false);
        }

        private static KarProjectModManifestArtifact CreateA2DEntrySidecarArtifact(
            KarProject project,
            KarProjectA2DEntryOutputInfo output)
        {
            return new KarProjectModManifestArtifact(
                KarProjectModManifestArtifactKind.A2DEntrySidecar,
                project.Workspace.GetRelativeOutputAssetPath(output.OutputPath),
                output.OutputPath,
                output.PackageRelativePath,
                output.EntryPath,
                "a2d-entry",
                output.EntryPath,
                output.Entry.PackageFile.ReadPath,
                output.EntryLength,
                output.EntrySha256,
                output.Status.ToString(),
                output.OutputLength,
                output.OutputLastWriteTimeUtc,
                output.OutputSha256,
                output.DiffersFromEntry,
                output.MatchesEntry,
                false,
                true,
                output.DiffersFromEntry);
        }

        private static KarProjectModManifestArtifact CreateResourceByteDumpArtifact(
            KarProject project,
            KarProjectResourceByteInfo output)
        {
            return new KarProjectModManifestArtifact(
                KarProjectModManifestArtifactKind.ResourceByteDump,
                project.Workspace.GetRelativeOutputAssetPath(output.OutputPath),
                output.OutputPath,
                output.Resource.RelativePath,
                output.Address,
                "active-resource",
                output.Address,
                null,
                output.ActiveLength,
                output.ActiveSha256,
                output.Status.ToString(),
                output.OutputLength,
                output.OutputLastWriteTimeUtc,
                output.OutputSha256,
                output.DiffersFromActive,
                output.MatchesActive,
                false,
                false,
                false);
        }

        private static string NormalizeFullPath(string path)
        {
            return Path.GetFullPath(path);
        }
    }
}
