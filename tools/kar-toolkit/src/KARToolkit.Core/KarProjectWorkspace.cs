using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace KARToolkit.Core
{
    public sealed class KarProjectWorkspace
    {
        private KarProjectWorkspace(
            string sourceRoot,
            string sourceFilesRoot,
            string outputRoot,
            string outputFilesRoot,
            bool sourceHasFilesDirectory)
        {
            SourceRoot = sourceRoot;
            SourceFilesRoot = sourceFilesRoot;
            OutputRoot = outputRoot;
            OutputFilesRoot = outputFilesRoot;
            SourceHasFilesDirectory = sourceHasFilesDirectory;
        }

        public string SourceRoot { get; }

        public string Name => Path.GetFileName(SourceRoot.TrimEnd(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar));

        public string SourceFilesRoot { get; }

        public string OutputRoot { get; }

        public string OutputFilesRoot { get; }

        public bool SourceHasFilesDirectory { get; }

        public static KarProjectWorkspace Open(string sourceRoot)
        {
            return Open(sourceRoot, null);
        }

        public static KarProjectWorkspace Open(string sourceRoot, string outputRoot)
        {
            if (string.IsNullOrWhiteSpace(sourceRoot))
                throw new ArgumentException("Source root cannot be empty.", nameof(sourceRoot));

            string fullSourceRoot = Path.GetFullPath(sourceRoot);
            if (!Directory.Exists(fullSourceRoot))
                throw new DirectoryNotFoundException(fullSourceRoot);

            bool sourceHasFilesDirectory;
            string sourceFilesRoot = ResolveSourceFilesRoot(fullSourceRoot, out sourceHasFilesDirectory);
            string fullOutputRoot = string.IsNullOrWhiteSpace(outputRoot)
                ? GetDefaultOutputRoot(fullSourceRoot, sourceHasFilesDirectory)
                : Path.GetFullPath(outputRoot);
            string outputFilesRoot = sourceHasFilesDirectory
                ? Path.Combine(fullOutputRoot, "files")
                : fullOutputRoot;

            EnsureSeparateRoot(sourceFilesRoot, outputFilesRoot, "Output files root cannot be inside the source files root.");
            EnsureSeparateRoot(fullSourceRoot, fullOutputRoot, "Output root cannot be inside the source root.");
            EnsureSeparateRoot(fullOutputRoot, fullSourceRoot, "Source root cannot be inside the output root.");

            return new KarProjectWorkspace(
                fullSourceRoot,
                sourceFilesRoot,
                fullOutputRoot,
                outputFilesRoot,
                sourceHasFilesDirectory);
        }

        public string GetSourcePath(string relativePath)
        {
            return ResolveUnderRoot(SourceFilesRoot, NormalizeRelativePath(relativePath));
        }

        public string GetOutputPath(string relativePath)
        {
            return ResolveUnderRoot(OutputFilesRoot, NormalizeRelativePath(relativePath));
        }

        public string GetOutputAssetPath(string relativePath)
        {
            return ResolveUnderRoot(OutputRoot, NormalizeRelativePath(relativePath));
        }

        public string GetReadPath(string relativePath)
        {
            string outputPath = GetOutputPath(relativePath);
            return File.Exists(outputPath) ? outputPath : GetSourcePath(relativePath);
        }

        public IReadOnlyList<string> EnumerateOutputRelativePaths()
        {
            if (!Directory.Exists(OutputFilesRoot))
                return Array.Empty<string>();

            return Directory.GetFiles(OutputFilesRoot, "*", SearchOption.AllDirectories)
                .Select(GetRelativeOutputPath)
                .OrderBy(path => path, StringComparer.OrdinalIgnoreCase)
                .ToList()
                .AsReadOnly();
        }

        public string GetRelativeSourcePath(string sourcePath)
        {
            string fullSourcePath = Path.GetFullPath(sourcePath);
            if (!IsSameOrChildPath(SourceFilesRoot, fullSourcePath))
                throw new InvalidOperationException("Source path escaped its project source root.");

            return GetRelativePath(SourceFilesRoot, fullSourcePath);
        }

        public string GetRelativeOutputPath(string outputPath)
        {
            string fullOutputPath = Path.GetFullPath(outputPath);
            if (!IsSameOrChildPath(OutputFilesRoot, fullOutputPath))
                throw new InvalidOperationException("Output path escaped its project output root.");

            return GetRelativePath(OutputFilesRoot, fullOutputPath);
        }

        public string PrepareOutputPath(string relativePath)
        {
            string outputPath = GetOutputPath(relativePath);
            string parent = Path.GetDirectoryName(outputPath);
            if (!string.IsNullOrEmpty(parent))
                Directory.CreateDirectory(parent);
            return outputPath;
        }

        public string PrepareOutputAssetPath(string relativePath)
        {
            string outputPath = GetOutputAssetPath(relativePath);
            string parent = Path.GetDirectoryName(outputPath);
            if (!string.IsNullOrEmpty(parent))
                Directory.CreateDirectory(parent);
            return outputPath;
        }

        public string CopyToOutput(string relativePath, bool overwrite = false)
        {
            string sourcePath = GetSourcePath(relativePath);
            string outputPath = PrepareOutputPath(relativePath);

            if (overwrite || !File.Exists(outputPath))
                File.Copy(sourcePath, outputPath, overwrite);

            return outputPath;
        }

        public byte[] ReadBytes(string relativePath)
        {
            return File.ReadAllBytes(GetReadPath(relativePath));
        }

        public string WriteBytes(string relativePath, byte[] data)
        {
            if (data == null)
                throw new ArgumentNullException(nameof(data));

            return SaveOutputFile(relativePath, tempPath => File.WriteAllBytes(tempPath, data));
        }

        public string SaveOutputFile(string relativePath, Action<string> saveToTempPath)
        {
            if (saveToTempPath == null)
                throw new ArgumentNullException(nameof(saveToTempPath));

            string outputPath = PrepareOutputPath(relativePath);
            return SavePreparedOutputPath(outputPath, saveToTempPath);
        }

        public string SaveOutputAsset(string relativePath, Action<string> saveToTempPath)
        {
            if (saveToTempPath == null)
                throw new ArgumentNullException(nameof(saveToTempPath));

            string outputPath = PrepareOutputAssetPath(relativePath);
            return SavePreparedOutputPath(outputPath, saveToTempPath);
        }

        private static string SavePreparedOutputPath(string outputPath, Action<string> saveToTempPath)
        {
            string tempPath = outputPath + ".tmp";

            if (File.Exists(tempPath))
                File.Delete(tempPath);

            saveToTempPath(tempPath);
            ReplaceFile(tempPath, outputPath);
            return outputPath;
        }

        public static string NormalizeRelativePath(string relativePath)
        {
            if (string.IsNullOrWhiteSpace(relativePath))
                throw new ArgumentException("Relative path cannot be empty.", nameof(relativePath));
            if (Path.IsPathRooted(relativePath))
                throw new ArgumentException("Project paths must be relative.", nameof(relativePath));

            string[] parts = relativePath
                .Replace('\\', '/')
                .Split(new[] { '/' }, StringSplitOptions.RemoveEmptyEntries);

            if (parts.Length == 0)
                throw new ArgumentException("Relative path cannot be empty.", nameof(relativePath));

            foreach (string part in parts)
            {
                if (part == "." || part == "..")
                    throw new ArgumentException("Project paths cannot contain traversal segments.", nameof(relativePath));
            }

            return string.Join("/", parts);
        }

        private static string ResolveSourceFilesRoot(string sourceRoot, out bool sourceHasFilesDirectory)
        {
            string filesRoot = Path.Combine(sourceRoot, "files");
            if (Directory.Exists(filesRoot))
            {
                sourceHasFilesDirectory = true;
                return filesRoot;
            }

            sourceHasFilesDirectory = false;
            return sourceRoot;
        }

        private static string GetDefaultOutputRoot(string sourceRoot, bool sourceHasFilesDirectory)
        {
            if (sourceHasFilesDirectory)
                return sourceRoot + "_mod";

            string directoryName = Path.GetFileName(sourceRoot.TrimEnd(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar));
            DirectoryInfo parent = Directory.GetParent(sourceRoot);
            if (string.Equals(directoryName, "files", StringComparison.OrdinalIgnoreCase) && parent != null && parent.Parent != null)
                return Path.Combine(parent.Parent.FullName, parent.Name + "_mod", "files");

            return sourceRoot + "_mod";
        }

        private static void ReplaceFile(string tempPath, string outputPath)
        {
            if (File.Exists(outputPath))
                File.Delete(outputPath);
            File.Move(tempPath, outputPath);
        }

        private static string ResolveUnderRoot(string root, string relativePath)
        {
            string normalized = NormalizeRelativePath(relativePath);
            string platformPath = normalized.Replace('/', Path.DirectorySeparatorChar);
            string fullPath = Path.GetFullPath(Path.Combine(root, platformPath));

            if (!IsSameOrChildPath(root, fullPath))
                throw new InvalidOperationException("Resolved path escaped its project root.");

            return fullPath;
        }

        private static string GetRelativePath(string root, string path)
        {
            Uri rootUri = new Uri(AppendDirectorySeparator(Path.GetFullPath(root)));
            Uri pathUri = new Uri(Path.GetFullPath(path));
            Uri relativeUri = rootUri.MakeRelativeUri(pathUri);
            return Uri.UnescapeDataString(relativeUri.ToString()).Replace('\\', '/');
        }

        private static string AppendDirectorySeparator(string path)
        {
            if (path.EndsWith(Path.DirectorySeparatorChar.ToString()) ||
                path.EndsWith(Path.AltDirectorySeparatorChar.ToString()))
            {
                return path;
            }

            return path + Path.DirectorySeparatorChar;
        }

        private static void EnsureSeparateRoot(string sourceRoot, string outputRoot, string message)
        {
            if (IsSameOrChildPath(sourceRoot, outputRoot))
                throw new InvalidOperationException(message);
        }

        private static bool IsSameOrChildPath(string root, string path)
        {
            string fullRoot = AppendDirectorySeparator(Path.GetFullPath(root));
            string fullPath = Path.GetFullPath(path);

            return fullPath.Equals(fullRoot.TrimEnd(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar), StringComparison.OrdinalIgnoreCase) ||
                fullPath.StartsWith(fullRoot, StringComparison.OrdinalIgnoreCase);
        }
    }
}
