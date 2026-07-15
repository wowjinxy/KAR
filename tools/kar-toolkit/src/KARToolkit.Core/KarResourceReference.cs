using System;

namespace KARToolkit.Core
{
    public sealed class KarResourceReference : IEquatable<KarResourceReference>
    {
        private KarResourceReference(KarResourceKind kind, string relativePath, string rootName, string entryName)
        {
            Kind = kind;
            RelativePath = KarProjectWorkspace.NormalizeRelativePath(relativePath);
            RootName = NormalizeName(rootName, nameof(rootName));
            EntryName = NormalizeName(entryName, nameof(entryName));

            if (Kind == KarResourceKind.HsdRoot && RootName == null)
                throw new ArgumentException("HSD root references require a root name.", nameof(rootName));
            if (Kind == KarResourceKind.A2DEntry && EntryName == null)
                throw new ArgumentException("A2D entry references require an entry name.", nameof(entryName));
            if (Kind == KarResourceKind.File && (RootName != null || EntryName != null))
                throw new ArgumentException("File references cannot include subresource names.");
        }

        public KarResourceKind Kind { get; }

        public string RelativePath { get; }

        public string RootName { get; }

        public string EntryName { get; }

        public string Address
        {
            get
            {
                switch (Kind)
                {
                    case KarResourceKind.HsdRoot:
                        return RelativePath + ":" + RootName;
                    case KarResourceKind.A2DEntry:
                        return RelativePath + "#" + EntryName;
                    default:
                        return RelativePath;
                }
            }
        }

        public string ParentAddress => Kind == KarResourceKind.File ? null : RelativePath;

        public static KarResourceReference File(string relativePath)
        {
            return new KarResourceReference(KarResourceKind.File, relativePath, null, null);
        }

        public static KarResourceReference HsdRoot(string relativePath, string rootName)
        {
            return new KarResourceReference(KarResourceKind.HsdRoot, relativePath, rootName, null);
        }

        public static KarResourceReference A2DEntry(string packageRelativePath, string entryName)
        {
            return new KarResourceReference(KarResourceKind.A2DEntry, packageRelativePath, null, entryName);
        }

        public static KarResourceReference Parse(string address)
        {
            KarResourceReference reference;
            if (!TryParse(address, out reference))
                throw new ArgumentException("KAR resource reference is invalid: " + address, nameof(address));

            return reference;
        }

        public static bool TryParse(string address, out KarResourceReference reference)
        {
            reference = null;
            if (string.IsNullOrWhiteSpace(address))
                return false;

            try
            {
                int entrySeparator = address.IndexOf('#');
                if (entrySeparator >= 0)
                {
                    if (entrySeparator == 0 || entrySeparator == address.Length - 1)
                        return false;

                    reference = A2DEntry(
                        address.Substring(0, entrySeparator),
                        address.Substring(entrySeparator + 1));
                    return true;
                }

                int rootSeparator = address.IndexOf(':');
                if (rootSeparator >= 0)
                {
                    if (rootSeparator == 0 || rootSeparator == address.Length - 1)
                        return false;

                    reference = HsdRoot(
                        address.Substring(0, rootSeparator),
                        address.Substring(rootSeparator + 1));
                    return true;
                }

                reference = File(address);
                return true;
            }
            catch (ArgumentException)
            {
                reference = null;
                return false;
            }
        }

        public override string ToString()
        {
            return Address;
        }

        public override bool Equals(object obj)
        {
            return Equals(obj as KarResourceReference);
        }

        public bool Equals(KarResourceReference other)
        {
            if (other == null)
                return false;

            return Kind == other.Kind &&
                string.Equals(RelativePath, other.RelativePath, StringComparison.OrdinalIgnoreCase) &&
                string.Equals(RootName, other.RootName, StringComparison.Ordinal) &&
                string.Equals(EntryName, other.EntryName, StringComparison.OrdinalIgnoreCase);
        }

        public override int GetHashCode()
        {
            int hash = 17;
            hash = hash * 31 + Kind.GetHashCode();
            hash = hash * 31 + StringComparer.OrdinalIgnoreCase.GetHashCode(RelativePath);
            hash = hash * 31 + (RootName == null ? 0 : StringComparer.Ordinal.GetHashCode(RootName));
            hash = hash * 31 + (EntryName == null ? 0 : StringComparer.OrdinalIgnoreCase.GetHashCode(EntryName));
            return hash;
        }

        private static string NormalizeName(string name, string parameterName)
        {
            if (name == null)
                return null;

            string trimmed = name.Trim();
            if (trimmed.Length == 0)
                throw new ArgumentException("Resource names cannot be empty.", parameterName);
            if (trimmed.IndexOf('/') >= 0 || trimmed.IndexOf('\\') >= 0)
                throw new ArgumentException("Resource names cannot contain path separators.", parameterName);

            return trimmed;
        }
    }
}
