using KARToolkit.Core;

namespace KARToolkit.Cli;

internal static class KarCliQueryFactory
{
    public static KarProjectFileQueryOptions CreateFileQuery(KarCliOptions options)
    {
        return CreateFileQuery(options, includeSearch: true);
    }

    public static KarProjectFileQueryOptions CreateFileQuery(KarCliOptions options, bool includeSearch)
    {
        KarProjectFileQueryOptions query = new KarProjectFileQueryOptions
        {
            Category = options.FileCategory,
            Text = includeSearch ? options.SearchText : null,
            HasOutputCopy = options.FileHasOutputCopy,
        };

        if (!string.IsNullOrWhiteSpace(options.FileKind))
        {
            KarFileKind kind;
            if (!Enum.TryParse(options.FileKind, true, out kind))
                throw new ArgumentException("Unknown file kind: " + options.FileKind);

            query.Kind = kind;
        }

        return query;
    }

    public static KarProjectResourceQueryOptions CreateResourceQuery(KarCliOptions options)
    {
        KarProjectFileQueryOptions parentFiles = CreateResourceParentFileQuery(options);
        KarProjectResourceQueryOptions query = new KarProjectResourceQueryOptions
        {
            Address = options.Positionals.Count >= 2 ? options.Positionals[1] : null,
            Category = options.FileCategory,
            Text = options.SearchText,
            Files = parentFiles,
            Roots = new KarProjectRootQueryOptions
            {
                Files = parentFiles,
                IsKnown = options.RootKnown,
                RootName = options.RootName,
            },
            A2DEntries = new KarProjectA2DEntryQueryOptions
            {
                Packages = parentFiles,
            },
        };

        if (!string.IsNullOrWhiteSpace(options.ResourceKind))
            query.Kind = ParseResourceKind(options.ResourceKind);

        return query;
    }

    public static KarProjectResourceOutputQueryOptions CreateResourceOutputQuery(KarCliOptions options)
    {
        KarProjectFileQueryOptions parentFiles = CreateResourceParentFileQuery(options, includeOutputCopyFilter: false);
        KarProjectResourceQueryOptions resources = new KarProjectResourceQueryOptions
        {
            Address = options.Positionals.Count >= 2 ? options.Positionals[1] : null,
            Category = options.FileCategory,
            Text = options.SearchText,
            Files = parentFiles,
            Roots = new KarProjectRootQueryOptions
            {
                Files = parentFiles,
                IsKnown = options.RootKnown,
                RootName = options.RootName,
            },
            A2DEntries = new KarProjectA2DEntryQueryOptions
            {
                Packages = parentFiles,
            },
        };

        if (!string.IsNullOrWhiteSpace(options.ResourceKind))
            resources.Kind = ParseResourceKind(options.ResourceKind);

        return new KarProjectResourceOutputQueryOptions
        {
            Resources = resources,
            HasOutput = options.FileHasOutputCopy,
        };
    }

    public static KarProjectResourceFieldQueryOptions CreateResourceFieldQuery(KarCliOptions options)
    {
        KarProjectFileQueryOptions parentFiles = CreateResourceParentFileQuery(options);
        return new KarProjectResourceFieldQueryOptions
        {
            Resources = new KarProjectResourceQueryOptions
            {
                Address = options.Positionals.Count >= 2 ? options.Positionals[1] : null,
                Kind = KarResourceKind.HsdRoot,
                Category = options.FileCategory,
                Files = parentFiles,
                Roots = new KarProjectRootQueryOptions
                {
                    Files = parentFiles,
                    IsKnown = options.RootKnown,
                    RootName = options.RootName,
                },
            },
            FieldName = options.Positionals.Count >= 3 ? options.Positionals[2] : null,
            Text = options.SearchText,
        };
    }

    public static bool MatchesResourceOutputStatusOption(KarProjectResourceOutputInfo output, KarProjectOutputFileStatus? status)
    {
        if (!status.HasValue)
            return true;

        switch (status.Value)
        {
            case KarProjectOutputFileStatus.DiffersFromSource:
                return output.IsModified;
            case KarProjectOutputFileStatus.MatchesSource:
                return output.IsUnchanged;
            case KarProjectOutputFileStatus.SourceMissing:
                return output.Status == KarProjectResourceOutputStatus.SourceMissing;
            default:
                return false;
        }
    }

    public static KarResourceKind ParseResourceKind(string value)
    {
        KarResourceKind kind;
        if (Enum.TryParse(value, true, out kind))
            return kind;

        string normalized = value.Replace("-", "").Replace("_", "").ToLowerInvariant();
        switch (normalized)
        {
            case "file":
                return KarResourceKind.File;
            case "root":
            case "hsd":
            case "hsdroot":
                return KarResourceKind.HsdRoot;
            case "entry":
            case "a2d":
            case "a2dentry":
                return KarResourceKind.A2DEntry;
            default:
                throw new ArgumentException("Unknown resource kind: " + value);
        }
    }

    public static KarProjectRootQueryOptions CreateRootQuery(KarCliOptions options)
    {
        return CreateRootQuery(options, includeSearch: true);
    }

    public static KarProjectRootQueryOptions CreateRootQuery(KarCliOptions options, bool includeSearch)
    {
        return new KarProjectRootQueryOptions
        {
            Files = CreateFileQuery(options, includeSearch: false),
            IsKnown = options.RootKnown,
            RootName = options.RootName,
            Text = includeSearch ? options.SearchText : null,
        };
    }

    public static KarProjectA2DEntryQueryOptions CreateA2DEntryQuery(KarCliOptions options)
    {
        return CreateA2DEntryQuery(options, includeSearch: true);
    }

    public static KarProjectA2DEntryQueryOptions CreateA2DEntryQuery(KarCliOptions options, bool includeSearch)
    {
        return new KarProjectA2DEntryQueryOptions
        {
            Packages = CreateFileQuery(options, includeSearch: false),
            PackagePath = options.Positionals.Count >= 2 ? options.Positionals[1] : null,
            EntryName = options.Positionals.Count >= 3 ? options.Positionals[2] : null,
            Text = includeSearch ? options.SearchText : null,
        };
    }

    public static KarProjectA2DEntryOutputQueryOptions CreateA2DEntryOutputQuery(KarCliOptions options)
    {
        return new KarProjectA2DEntryOutputQueryOptions
        {
            Entries = CreateA2DEntryQuery(options),
            Status = ToA2DEntryOutputStatus(options.OutputStatus),
            HasOutput = options.FileHasOutputCopy,
        };
    }

    public static KarProjectA2DPackageContextQueryOptions CreateA2DPackageContextQuery(KarCliOptions options)
    {
        return new KarProjectA2DPackageContextQueryOptions
        {
            Packages = CreateFileQuery(options, includeSearch: false),
            PackagePath = options.Positionals.Count >= 2 ? options.Positionals[1] : null,
            Text = options.SearchText,
            HasEntryOutputs = options.FileHasOutputCopy,
            HasModifiedEntryOutputs = ToA2DEntryOutputStatus(options.OutputStatus) == KarProjectA2DEntryOutputStatus.DiffersFromEntry ? true : null,
        };
    }

    public static KarProjectA2DEntryOutputStatus? ToA2DEntryOutputStatus(KarProjectOutputFileStatus? status)
    {
        if (!status.HasValue)
            return null;

        switch (status.Value)
        {
            case KarProjectOutputFileStatus.DiffersFromSource:
                return KarProjectA2DEntryOutputStatus.DiffersFromEntry;
            case KarProjectOutputFileStatus.MatchesSource:
                return KarProjectA2DEntryOutputStatus.MatchesEntry;
            default:
                return null;
        }
    }

    public static KarProjectScriptTableQueryOptions CreateScriptTableQuery(KarCliOptions options)
    {
        KarProjectFileQueryOptions parentFiles = CreateResourceParentFileQuery(options);
        KarProjectResourceQueryOptions resources = new KarProjectResourceQueryOptions
        {
            Category = options.FileCategory,
            Files = parentFiles,
            A2DEntries = new KarProjectA2DEntryQueryOptions
            {
                Packages = parentFiles,
            },
        };

        if (!string.IsNullOrWhiteSpace(options.ResourceKind))
            resources.Kind = ParseResourceKind(options.ResourceKind);

        KarProjectScriptTableQueryOptions query = new KarProjectScriptTableQueryOptions
        {
            Resources = resources,
            Text = options.SearchText,
        };

        if (options.Positionals.Count >= 2)
        {
            string selector = options.Positionals[1];
            if (selector.IndexOf('#') >= 0)
            {
                query.Address = selector;
                resources.Address = selector;
            }
            else if (options.Positionals.Count >= 3)
            {
                query.PackagePath = selector;
                query.Name = options.Positionals[2];
                resources.A2DEntries.PackagePath = selector;
                resources.A2DEntries.EntryName = options.Positionals[2];
            }
            else if (selector.EndsWith(".tm", StringComparison.OrdinalIgnoreCase))
            {
                query.Name = selector;
            }
            else
            {
                query.PackagePath = selector;
                resources.A2DEntries.PackagePath = selector;
            }
        }

        return query;
    }

    public static KarProjectScriptTableContextQueryOptions CreateScriptTableContextQuery(KarCliOptions options)
    {
        return new KarProjectScriptTableContextQueryOptions
        {
            Tables = CreateScriptTableQuery(options),
        };
    }

    public static KarProjectMapScriptQueryOptions CreateMapScriptQuery(KarCliOptions options)
    {
        KarProjectFileQueryOptions parentFiles = CreateResourceParentFileQuery(options);
        KarProjectResourceQueryOptions resources = new KarProjectResourceQueryOptions
        {
            Category = options.FileCategory,
            Files = parentFiles,
            A2DEntries = new KarProjectA2DEntryQueryOptions
            {
                Packages = parentFiles,
            },
        };

        if (!string.IsNullOrWhiteSpace(options.ResourceKind))
            resources.Kind = ParseResourceKind(options.ResourceKind);

        KarProjectScriptTableQueryOptions scriptTables = new KarProjectScriptTableQueryOptions
        {
            Resources = resources,
            Text = options.SearchText,
        };

        if (options.Positionals.Count >= 3)
        {
            string selector = options.Positionals[2];
            if (selector.IndexOf('#') >= 0)
            {
                scriptTables.Address = selector;
                resources.Address = selector;
            }
            else
            {
                scriptTables.Name = selector;
            }
        }

        return new KarProjectMapScriptQueryOptions
        {
            MapNameOrPath = options.Positionals.Count >= 2 ? options.Positionals[1] : null,
            ScriptTables = scriptTables,
        };
    }

    public static KarProjectVehicleQueryOptions CreateVehicleQuery(KarCliOptions options)
    {
        return new KarProjectVehicleQueryOptions
        {
            VehicleNameOrPath = options.Positionals.Count >= 2 ? options.Positionals[1] : null,
            Text = options.SearchText,
        };
    }

    public static KarProjectFieldQueryOptions CreateFieldQuery(KarCliOptions options)
    {
        return new KarProjectFieldQueryOptions
        {
            Roots = CreateRootQuery(options, includeSearch: false),
            DataDefinitionIdOrAccessorTypeName = options.Positionals.Count >= 2 ? options.Positionals[1] : null,
            FieldName = options.Positionals.Count >= 3 ? options.Positionals[2] : null,
            Text = options.SearchText,
        };
    }

    public static KarProjectRelationshipQueryOptions CreateRelationshipQuery(KarCliOptions options)
    {
        return new KarProjectRelationshipQueryOptions
        {
            Text = options.SearchText,
        };
    }

    public static KarProjectReportOptions CreateReportOptions(KarCliOptions options)
    {
        return new KarProjectReportOptions
        {
            Files = CreateFileQuery(options),
            OutputFiles = CreateOutputQuery(options),
            Roots = CreateRootQuery(options),
            Fields = CreateFieldQuery(options),
            IncludeFieldSummaries = options.RootSummary,
        };
    }

    public static KarProjectModWorkspaceOptions CreateModWorkspaceOptions(KarCliOptions options)
    {
        KarProjectOutputFileQueryOptions outputFiles = CreateOutputQuery(options);
        return new KarProjectModWorkspaceOptions
        {
            OutputFiles = outputFiles,
            ResourceOutputs = new KarProjectResourceOutputQueryOptions
            {
                Resources = CreateResourceQuery(options),
            },
            A2DEntryOutputs = new KarProjectA2DEntryOutputQueryOptions
            {
                Entries = CreateA2DEntryQuery(options),
            },
            MapOutputs = new KarProjectMapOutputQueryOptions
            {
                Outputs = outputFiles,
                HasOutput = true,
            },
        };
    }

    public static KarProjectToolkitSnapshotOptions CreateToolkitSnapshotOptions(KarCliOptions options)
    {
        return new KarProjectToolkitSnapshotOptions
        {
            ModWorkspace = CreateModWorkspaceOptions(options),
            MapContexts = CreateMapScriptQuery(options),
            VehicleContexts = CreateVehicleQuery(options),
            A2DPackageContexts = CreateA2DPackageContextQuery(options),
            ScriptTableContexts = CreateScriptTableContextQuery(options),
        };
    }

    public static KarProjectOutputFileQueryOptions CreateOutputQuery(KarCliOptions options)
    {
        KarProjectOutputFileQueryOptions query = new KarProjectOutputFileQueryOptions
        {
            Category = options.FileCategory,
            Status = options.OutputStatus,
        };

        if (!string.IsNullOrWhiteSpace(options.FileKind))
        {
            KarFileKind kind;
            if (!Enum.TryParse(options.FileKind, true, out kind))
                throw new ArgumentException("Unknown file kind: " + options.FileKind);

            query.Kind = kind;
        }

        return query;
    }

    public static KarProjectMapOutputQueryOptions CreateMapOutputQuery(KarCliOptions options, KarProject project)
    {
        return new KarProjectMapOutputQueryOptions
        {
            Outputs = CreateOutputQuery(options),
            MapName = options.Positionals.Count >= 2 ? project.MapService.Get(options.Positionals[1]).Name : null,
            HasOutput = true,
        };
    }

    private static KarProjectFileQueryOptions CreateResourceParentFileQuery(KarCliOptions options)
    {
        return CreateResourceParentFileQuery(options, includeOutputCopyFilter: true);
    }

    private static KarProjectFileQueryOptions CreateResourceParentFileQuery(KarCliOptions options, bool includeOutputCopyFilter)
    {
        KarProjectFileQueryOptions query = new KarProjectFileQueryOptions
        {
            HasOutputCopy = includeOutputCopyFilter ? options.FileHasOutputCopy : null,
        };

        if (!string.IsNullOrWhiteSpace(options.FileKind))
        {
            KarFileKind kind;
            if (!Enum.TryParse(options.FileKind, true, out kind))
                throw new ArgumentException("Unknown file kind: " + options.FileKind);

            query.Kind = kind;
        }

        return query;
    }
}
