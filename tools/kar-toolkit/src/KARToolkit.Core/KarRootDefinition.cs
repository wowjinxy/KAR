using System;

namespace KARToolkit.Core
{
    public sealed class KarRootDefinition
    {
        private readonly string _exactName;
        private readonly string _prefix;
        private readonly string _suffix;

        private KarRootDefinition(
            string pattern,
            string description,
            string accessorTypeName,
            string dataDefinitionId,
            bool isRequired,
            string exactName,
            string prefix,
            string suffix)
        {
            Pattern = pattern;
            Description = description;
            AccessorTypeName = accessorTypeName;
            DataDefinitionId = dataDefinitionId;
            IsRequired = isRequired;
            _exactName = exactName;
            _prefix = prefix;
            _suffix = suffix;
        }

        public string Pattern { get; }

        public string Description { get; }

        public string AccessorTypeName { get; }

        public string DataDefinitionId { get; }

        public KarDataDefinition DataDefinition
        {
            get
            {
                KarDataDefinition definition;
                if (!string.IsNullOrWhiteSpace(DataDefinitionId) &&
                    KarDataDefinitionCatalog.TryGet(DataDefinitionId, out definition))
                {
                    return definition;
                }

                if (KarDataDefinitionCatalog.TryGetByAccessorTypeName(AccessorTypeName, out definition))
                    return definition;

                return null;
            }
        }

        public bool IsRequired { get; }

        public static KarRootDefinition Exact(string name, string description, string accessorTypeName, bool isRequired = true)
        {
            return new KarRootDefinition(name, description, accessorTypeName, null, isRequired, name, null, null);
        }

        public static KarRootDefinition ExactData(string name, string description, string accessorTypeName, string dataDefinitionId, bool isRequired = true)
        {
            return new KarRootDefinition(name, description, accessorTypeName, dataDefinitionId, isRequired, name, null, null);
        }

        public static KarRootDefinition Prefix(string prefix, string description, string accessorTypeName, bool isRequired = false)
        {
            return new KarRootDefinition(prefix + "*", description, accessorTypeName, null, isRequired, null, prefix, null);
        }

        public static KarRootDefinition PrefixData(string prefix, string description, string accessorTypeName, string dataDefinitionId, bool isRequired = false)
        {
            return new KarRootDefinition(prefix + "*", description, accessorTypeName, dataDefinitionId, isRequired, null, prefix, null);
        }

        public static KarRootDefinition Suffix(string suffix, string description, string accessorTypeName, bool isRequired = false)
        {
            return new KarRootDefinition("*" + suffix, description, accessorTypeName, null, isRequired, null, null, suffix);
        }

        public static KarRootDefinition SuffixData(string suffix, string description, string accessorTypeName, string dataDefinitionId, bool isRequired = false)
        {
            return new KarRootDefinition("*" + suffix, description, accessorTypeName, dataDefinitionId, isRequired, null, null, suffix);
        }

        public static KarRootDefinition PrefixSuffix(string prefix, string suffix, string description, string accessorTypeName, bool isRequired = false)
        {
            return new KarRootDefinition(prefix + "*" + suffix, description, accessorTypeName, null, isRequired, null, prefix, suffix);
        }

        public static KarRootDefinition PrefixSuffixData(string prefix, string suffix, string description, string accessorTypeName, string dataDefinitionId, bool isRequired = false)
        {
            return new KarRootDefinition(prefix + "*" + suffix, description, accessorTypeName, dataDefinitionId, isRequired, null, prefix, suffix);
        }

        public bool Matches(string rootName)
        {
            if (string.IsNullOrEmpty(rootName))
                return false;

            if (_exactName != null)
                return string.Equals(rootName, _exactName, StringComparison.Ordinal);

            if (_prefix != null && !rootName.StartsWith(_prefix, StringComparison.Ordinal))
                return false;

            if (_suffix != null && !rootName.EndsWith(_suffix, StringComparison.Ordinal))
                return false;

            return true;
        }
    }
}
