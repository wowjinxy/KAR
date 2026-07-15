using KARToolkit.Core;

namespace KARToolkit.Cli;

internal static class KarCliTextWriter
{
    public static void PrintArchiveSlot(string label, KarArchiveInfo archive)
    {
        Console.WriteLine(label + ":");
        if (archive == null)
        {
            Console.WriteLine("  <missing>");
            return;
        }

        PrintArchive(archive, "  ");
    }

    public static void PrintArchive(KarArchiveInfo archive, string indent)
    {
        Console.WriteLine(indent + archive.File.RelativePath + " (" + archive.Definition.DisplayName + ")");
        Console.WriteLine(indent + "Known roots: " + archive.KnownRoots.Count + "/" + archive.Roots.Count);

        foreach (KarArchiveRootInfo root in archive.Roots)
        {
            string known = root.IsKnown ? "known" : "unknown";
            string type = string.IsNullOrEmpty(root.DisplayAccessorTypeName) ? "<untyped>" : root.DisplayAccessorTypeName;
            string description = root.Definition == null || string.IsNullOrEmpty(root.Definition.Description)
                ? ""
                : " - " + root.Definition.Description;

            Console.WriteLine(indent + "  " + root.Name + " [" + known + ", " + type + "]" + description);

            if (root.DataDefinition != null)
                PrintDataDefinition(root.DataDefinition, indent + "    ");

            if (root.HasFieldValues)
                PrintFieldValues(root.FieldValues, indent + "    ");
        }

        if (archive.HasMissingRequiredRoots)
        {
            Console.WriteLine(indent + "Missing required roots:");
            foreach (KarRootDefinition root in archive.MissingRequiredRoots)
                Console.WriteLine(indent + "  " + root.Pattern);
        }
    }

    public static void PrintValidationIssue(KarValidationIssue issue)
    {
        string location = "";
        if (!string.IsNullOrEmpty(issue.RelativePath))
            location = " " + issue.RelativePath;
        else if (!string.IsNullOrEmpty(issue.MapName))
            location = " map:" + issue.MapName;

        Console.WriteLine(issue.Severity + " " + issue.Code + location + " - " + issue.Message);
    }

    public static void PrintDataDefinitionValidationIssue(KarDataDefinitionValidationIssue issue)
    {
        string location = "";
        if (!string.IsNullOrEmpty(issue.DefinitionId))
            location = " " + issue.DefinitionId;
        if (!string.IsNullOrEmpty(issue.FieldName))
            location += "." + issue.FieldName;

        Console.WriteLine(issue.Severity + " " + issue.Code + location + " - " + issue.Message);
    }

    public static void PrintDataDefinition(KarDataDefinition definition, string indent)
    {
        Console.WriteLine(indent + "schema: " + definition.Id + " (" + definition.DisplayName + ")");
        if (definition.Size.HasValue)
            Console.WriteLine(indent + "  size: " + definition.SizeHex);
        if (!string.IsNullOrEmpty(definition.Description))
            Console.WriteLine(indent + "  " + definition.Description);

        foreach (KarDataFieldDefinition field in definition.Fields)
        {
            string offset = field.OffsetHex ?? "n/a";
            string pointer = field.IsPointer ? " ptr" : "";
            string description = string.IsNullOrEmpty(field.Description) ? "" : " - " + field.Description;
            Console.WriteLine(indent + "  " + offset + " " + field.Name + ": " + field.TypeName + pointer + description);
        }
    }

    private static void PrintFieldValues(IReadOnlyList<KarDataFieldValue> values, string indent)
    {
        Console.WriteLine(indent + "values:");
        foreach (KarDataFieldValue value in values)
        {
            string offset = value.Field.OffsetHex ?? "n/a";
            string error = string.IsNullOrEmpty(value.Error) ? "" : " (" + value.Error + ")";
            Console.WriteLine(indent + "  " + offset + " " + value.Field.Name + " = " + value.DisplayValue + error);

            if (value.ReferenceDataDefinition != null)
                Console.WriteLine(indent + "    ref schema: " + value.ReferenceDataDefinition.Id + " (" + value.ReferenceDataDefinition.DisplayName + ")");
            if (value.HasReferenceFieldValues)
                PrintFieldValues(value.ReferenceFieldValues, indent + "    ");
            if (value.HasReferenceEntries)
            {
                string total = value.ReferenceEntryTotalCount.HasValue
                    ? "/" + value.ReferenceEntryTotalCount.Value
                    : "";
                Console.WriteLine(indent + "    ref entries: " + value.ReferenceEntryCount + total);
                foreach (KarDataReferenceEntry entry in value.ReferenceEntries)
                {
                    Console.WriteLine(indent + "      [" + entry.Index + "] offset=" + entry.OffsetHex);
                    if (entry.HasFieldValues)
                        PrintFieldValues(entry.FieldValues, indent + "        ");
                }
            }
        }
    }
}
