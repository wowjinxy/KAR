using System;

namespace KARToolkit.Core
{
    public sealed class KarProjectArchiveContextQueryOptions
    {
        public KarProjectFileQueryOptions Files { get; set; }

        public string RelativePath { get; set; }

        public string Text { get; set; }

        public bool? HasInspection { get; set; }

        public bool? HasInspectionError { get; set; }

        public bool? HasFields { get; set; }

        public bool? HasOutput { get; set; }

        public bool? HasModifiedOutput { get; set; }

        public KarProjectResourceOutputStatus? OutputStatus { get; set; }

        public bool Matches(KarProjectArchiveContext context)
        {
            if (context == null)
                throw new ArgumentNullException(nameof(context));

            if (!string.IsNullOrWhiteSpace(RelativePath) &&
                !string.Equals(KarProjectWorkspace.NormalizeRelativePath(RelativePath), context.RelativePath, StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }

            if (HasInspection.HasValue && context.HasInspection != HasInspection.Value)
                return false;
            if (HasInspectionError.HasValue && context.HasInspectionError != HasInspectionError.Value)
                return false;
            if (HasFields.HasValue && context.HasFields != HasFields.Value)
                return false;
            if (HasOutput.HasValue && context.HasOutput != HasOutput.Value)
                return false;
            if (HasModifiedOutput.HasValue && context.HasModifiedOutput != HasModifiedOutput.Value)
                return false;
            if (OutputStatus.HasValue && context.OutputStatus != OutputStatus.Value)
                return false;
            if (!string.IsNullOrWhiteSpace(Text) && !MatchesSearchText(context, Text))
                return false;

            return true;
        }

        private static bool MatchesSearchText(KarProjectArchiveContext context, string text)
        {
            if (KarProjectFileQueryOptions.MatchesSearchText(context.File, text) ||
                KarProjectFileQueryOptions.Contains(context.RelativePath, text) ||
                KarProjectFileQueryOptions.Contains(context.InspectionError, text))
            {
                return true;
            }

            foreach (KarArchiveRootInfo root in context.Roots)
            {
                if (KarProjectFileQueryOptions.Contains(root.Name, text) ||
                    KarProjectFileQueryOptions.Contains(root.AccessorTypeName, text) ||
                    KarProjectFileQueryOptions.Contains(root.DisplayAccessorTypeName, text) ||
                    KarProjectFileQueryOptions.Contains(root.DataDefinitionId, text) ||
                    KarProjectFileQueryOptions.Contains(root.DataDefinition == null ? null : root.DataDefinition.DisplayName, text) ||
                    KarProjectFileQueryOptions.Contains(root.DataDefinition == null ? null : root.DataDefinition.Description, text))
                {
                    return true;
                }
            }

            foreach (KarProjectResourceInfo resource in context.RootResources)
            {
                if (KarProjectResourceQueryOptions.MatchesSearchText(resource, text))
                    return true;
            }

            foreach (KarProjectResourceFieldInfo field in context.Fields)
            {
                if (KarProjectFileQueryOptions.Contains(field.FieldName, text) ||
                    KarProjectFileQueryOptions.Contains(field.DataDefinitionId, text) ||
                    KarProjectFileQueryOptions.Contains(field.Value.DisplayValue, text) ||
                    KarProjectFileQueryOptions.Contains(field.Value.Error, text))
                {
                    return true;
                }
            }

            foreach (KarProjectRelationship relationship in context.Relationships)
            {
                if (KarProjectRelationshipQueryOptions.MatchesSearchText(relationship, text))
                    return true;
            }

            return false;
        }
    }
}
