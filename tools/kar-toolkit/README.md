# KAR Toolkit

`tools/kar-toolkit` is the KAR-owned tooling layer built on top of HSDLib.

## Layout

- `src/KARToolkit.Core`: project-safe workspace access, KAR file indexing, archive catalogs/inspection, map bundle grouping, copy-to-output helpers, and validation.
- `src/KARToolkit.Cli`: thin command-line dispatch, read-only inspection commands, safe copy commands, and JSON/text output helpers for batch inspection, validation, and mod output operations.
- `external/HSDLib`: external HSD parsing/viewer dependency. KAR-specific workflows should live here only when they are viewer UI glue or low-level HSD support.

## Build

```powershell
dotnet build .\tools\kar-toolkit\KARToolkit.slnx --no-restore /p:UseSharedCompilation=false
```

## Tests

```powershell
dotnet run --project .\tools\kar-toolkit\tests\KARToolkit.Core.Tests\KARToolkit.Core.Tests.csproj
```

## CLI

```powershell
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll validate .\GKYE01 --no-unknown-roots
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll validate .\GKYE01 --no-hsd-archives --no-a2d-packages --no-schema-validation
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll file-kinds --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll resource-handlers --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll report .\GKYE01 --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll outputs .\GKYE01 --output .\mod-output
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll mod-workspace .\GKYE01 --output .\mod-output --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll map-outputs .\GKYE01 --output .\mod-output --modified
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll files .\GKYE01 --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll files .\GKYE01 --kind MapData --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll file .\GKYE01 GrCity1.dat
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll archives .\GKYE01 --kind MapData --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll roots .\GKYE01 --kind MapData --unknown
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll roots .\GKYE01 --unknown --summary
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll schema-usage .\GKYE01 --kind MapData --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll fields .\GKYE01 kar.gr.data unknown1 --kind MapData --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll field-summary .\GKYE01 kar.gr.data --kind MapData
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll map .\GKYE01 City1
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll map-scripts .\GKYE01 City1 ScInfGo2D.tm --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll map-context .\GKYE01 City1 --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll vehicles .\GKYE01 --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll vehicle .\GKYE01 Warp --output .\mod-output --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll relationships .\GKYE01 --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll resource-graph .\GKYE01 --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll resources .\GKYE01 --resource-kind a2d-entry --category Scripts --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll resource .\GKYE01 VsHydra.dat:vsDataHydra --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll resource-fields .\GKYE01 VsHydra.dat:vsDataHydra x0C --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll resource-outputs .\GKYE01 --modified --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll export-resource .\GKYE01 A2Info.dat#ScInfGo2D.tm --output .\mod-output
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll apply-resource-outputs .\GKYE01 A2Info.dat#ScInfGo2D.tm --output .\mod-output
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll import-resource .\GKYE01 A2Info.dat#ScInfGo2D.tm .\edited\ScInfGo2D.tm --output .\mod-output
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll set-resource-scalar .\GKYE01 VsHydra.dat:vsDataHydra x0C 1 --output .\mod-output
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll a2d-entries .\GKYE01 A2Info.dat
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll a2d-entry-outputs .\GKYE01 A2Info.dat --output .\mod-output
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll script-tables .\GKYE01 A2Info.dat
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll script-contexts .\GKYE01 A2Info.dat --output .\mod-output --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll extract-a2d-entry .\GKYE01 A2Info.dat#ScInfGo2D.tm --output .\mod-output
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll apply-a2d-entry-outputs .\GKYE01 A2Info.dat --output .\mod-output
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll script-tables .\GKYE01 ScInfGo2D.tm --json
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll definition kar.vs.legendary
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll validate-schemas
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll archive .\GKYE01 VcCommon.dat --json --max-reference-depth 2 --max-reference-entries 16
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll set-scalar .\GKYE01 VsHydra.dat kar.vs.legendary x0C 1 --schema --output .\mod-output
```

All copy/save helpers go through `KarProjectWorkspace`, which reads from the extracted source folder and writes only under the configured output folder.
Use `KarProject.Open(KarProjectOptions)` when a tool needs custom output roots, project indexing, archive inspection, or data schema registries.
Toolkit resources use stable addresses across the CLI and JSON output: project files use `Relative/Path.dat`, HSD roots use `Archive.dat:rootName`, and A2D entries use `Package.dat#EntryName`.
Project resource workflow capability discovery goes through `KarProjectResourceHandlerRegistry`, which maps file, HSD root, and A2D entry resources to supported operations such as byte reads, output export/import, scalar edits, field queries, and sidecar apply. `KarProjectResourceService` delegates those operations through per-kind `KarProjectResourceAdapter` instances, which are also exposed for lower-level toolkit callers. The `resource-handlers` CLI command exposes those resource handlers for tools and scripts.
Project resource graph snapshots go through `KarProject.CreateResourceGraph`, and the `resource-graph` CLI command exposes one project-wide view of resource addresses, parent/child resources, and known relationships.
Project script table workflows go through `KarProject.ScriptService`, and the `script-tables` CLI command lists loose `.tm` files and A2D-contained `.tm` entries as the same kind of script table resource.
Project script table toolkit contexts go through `KarProject.ScriptContextService`, and the `script-contexts` CLI command combines loose or packaged script-table metadata, resource-output status, sidecar/project output paths, and graph relationships in one project-level view.
Project-wide resource inventory, address resolution, field inspection, output status, byte reads, safe output exports, safe imports, output-side applies, and resource-address scalar edits go through `KarProject.ResourceService`; the `resources`/`resource` CLI commands expose mixed file, HSD root, and A2D entry resources, `resource-fields` reads labeled HSD root fields by resource address, `resource-outputs` reports file/root package outputs and A2D sidecar or package-entry status, `export-resource` stages file/root archives or A2D sidecars under the configured output folder, `apply-resource-outputs` packs modified A2D sidecars into output packages, `import-resource` writes file replacements or same-size A2D entry replacements only into output packages, and `set-resource-scalar` edits HSD root resources by address.
Project-wide report snapshots go through `KarProject.CreateReport`, and the `report` CLI command aggregates file groups, map completeness, archive/root health, schema usage, and optional field summaries.
Mod workspace snapshots go through `KarProject.ModWorkspaceService`, and the `mod-workspace` CLI command summarizes staged project files, resource outputs, A2D sidecars, and map output completeness for the configured output folder.
Project output/mod-state inventory goes through `KarProject.OutputService` or the compatibility wrappers `KarProject.CreateOutputInventory` and `KarProject.QueryOutputFiles`, and the `outputs` CLI command reports staged project files, modified/unchanged source matches, and output-only orphan files.
Map output/mod-state inventory goes through `KarProject.MapService.QueryOutputs` or the compatibility wrapper `KarProject.QueryMapOutputs`, and the `map-outputs` CLI command groups staged output files by map data/model/event-script bundles.
Map-focused workflows go through `KarProject.MapService`, which groups map lookup, staged map output status, output-only map copying, editable map archive opens, and map inspection.
Map script contexts go through `KarProject.MapScriptService`, and the `map-scripts` CLI command groups a selected map's data/model/event-script resources with known project script-table contexts.
Map toolkit contexts go through `KarProject.MapContextService`, and the `map-context` CLI command combines a map's data/model/event-script archive inspection, map resources, script-table resources, relationships, and output-copy state in one project-level view.
Vehicle toolkit workflows go through `KarProject.VehicleService`, which groups `VcCommon`, `VcStar`, `VcWheel`, and per-machine `VcStar*`/`VcWheel*`/`VcWing*` files into reusable bundles. The `vehicles` CLI command lists those bundles, while `vehicle`/`vehicle-context` combines machine/shared archive inspection, vehicle resources, and staged output-copy state for one vehicle.
Project relationship discovery goes through `KarProject.RelationshipService`, and the `relationships` CLI command lists map bundle files plus script-table resources found as loose `.tm` files or A2D package entries such as `A2Info.dat#ScInfGo2D.tm`.
A2D entry inventory goes through `KarProject.A2DService.QueryEntries`, and the `a2d-entries` CLI command lists package entries across a project or inside one package.
A2D sidecar output status goes through `KarProject.A2DService.QueryEntryOutputs`, and the `a2d-entry-outputs` CLI command compares output-side extracted entries against the current package entry bytes.
A2D entry workflows go through `KarProject.A2DService`; `extract-a2d-entry` writes package entries to the output-side `a2d-entries` workspace, `apply-a2d-entry-outputs` packs modified sidecars into output packages, and `replace-a2d-entry` saves same-size replacements only through the configured output folder.
Project file kind discovery goes through `KarFileKindRegistry`, which describes each known file kind, its stable id, category, and traits such as HSD archive, A2D package, script table, media, config, or map-bundle role. Project file workflow capability discovery goes through `KarProjectFileHandlerRegistry`, which maps those file kinds to supported operations such as HSD root inspection, A2D entry workflows, script-table listing, and map grouping. The `file-kinds` CLI command exposes the handler registry for tools and scripts.
Project file discovery and map grouping go through `KarProjectIndexer`, with lookup results held by `KarProjectIndex`.
The `files` and `file` CLI commands expose the project index without opening every archive, and `files` can filter by kind, category, or output-copy state.
Project-wide archive inventory goes through `KarProject.ArchiveService.QueryHsdArchives` or the compatibility wrapper `KarProject.QueryArchives`, and the `archives` CLI command reports compact known/unknown/missing root counts.
Project-wide root discovery goes through `KarProject.DataService.QueryRoots`, grouped root discovery goes through `KarProject.DataService.QueryRootSummaries`, and the `roots` CLI command can filter by file kind/category and known/unknown root state.
Project-wide schema usage goes through `KarProject.DataService.QueryDataDefinitionUsage`, and the `schema-usage` CLI command reports where known schemas appear.
Project-wide labeled field discovery goes through `KarProject.DataService.QueryFieldValues`, and the `fields` CLI command can filter by schema id/accessor type, field name, file kind/category, and root name.
Project-wide labeled field comparison goes through `KarProject.DataService.QueryFieldSummaries`, and the `field-summary` CLI command groups values by schema field.
Project file kind classification and map-name extraction go through `KarFileKindRegistry`; `KarProjectFileClassifier` remains as a compatibility wrapper.
`KarProjectFileCatalog` is the replaceable service that connects file kind descriptors, file handlers/capabilities, HSD/A2D/script traits, archive metadata lookup, and map-name extraction.
`KarArchiveDefinitionProvider` is the replaceable service that turns file kind, path, and optional map name into archive/root metadata.
Project file lookup, filtering, asset paths, byte reads/writes, and single-file copies go through `KarProject.FileService`, which wraps the lower-level `KarProjectFileStore`.
Copy operations can return `KarProjectFileCopyResult` when tools need both the copied file metadata and destination path.
Write/save operations can return `KarProjectFileWriteResult` when tools need normalized project paths and output metadata.
Map copy/save operations can return `KarProjectMapOutputResult` when tools need the output paths grouped by data, model, and event/script file.
Typed HSD archive and A2D package opens/saves go through `KarProject.ArchiveService`, which wraps the lower-level `KarProjectArchiveStore`.
Editable project archive handles (`KarProjectHsdArchive`, `KarProjectA2DPackage`) keep project metadata attached while saving through the safe output folder.
Editable map archive bundles (`KarProjectMapArchiveBundle`) group a map's data, model, and event/script archives for project-level workflows.
Project-level archive and map inspection goes through `KarProjectInspector`.
Project validation goes through `KarProjectValidator`, which creates a fresh validation run for each report.
Project validation includes schema integrity preflight through `KarDataDefinitionValidator`, and the schema report is included in validation output.
The `validate` CLI command can skip HSD archive scans, A2D package scans, missing map-model warnings, unknown-root reports, or schema validation for narrower batch checks.
Archive metadata lookup lives in `KarArchiveDefinitionProvider`; `KarArchiveCatalog` provides static compatibility wrappers; live HSD root inspection goes through `KarArchiveInspector`.
Map archive/root definitions are grouped in `KarMapArchiveDefinitions`; `KarArchiveDefinitionProvider` handles lookup.
Vehicle, rider, versus, item, and enemy archive/root definitions live in their matching domain definition modules.
General package/media/UI/effect/fallback archive definitions live in `KarGeneralArchiveDefinitions`.
Map bundle inspection goes through `KarMapInspector`, which ties each map's data, model, and event/script archives together.

Use `definitions` to list known KAR data schemas. Archive and map inspection attach schema details to known roots when the toolkit has decomp-backed field information.
Known root schemas also include read-only field values for mapped scalar fields and pointer presence/length, which is useful for quick archive comparison before writing editor code.
Archive, root, and schema results expose lookup helpers for roots by name/schema and field values by name, so tools do not need to hand-walk inspection lists.
Pointer fields with a known nested schema expose reference definitions and one bounded level of nested field values for quick table navigation.
Pointer fields whose nested schema has a fixed size can also expose bounded `ReferenceEntries`, which split flat referenced tables into labeled rows for text/JSON inspection.
Use `--max-reference-depth` and `--max-reference-entries` with archive/map inspection when a command needs deeper nested fields or more table rows.
Map gameplay schemas include position nodes, position-list rows, coordinate rows for event/item/vehicle/dead-position/area tables, and item timing/spawn tables.
Schema-backed scalar fields can be edited safely through `KarProject.EditService`, which opens HSD archives, applies edits, and saves only to the configured output folder.
Lower-level scalar edits remain available through `KarDataEditor` and `KarProjectHsdArchive.SetScalarField*` for tools that need in-memory control.
The `set-scalar` CLI command exposes the same safe output-only scalar edit path for quick mod experiments.
Schema integrity checks go through `KarDataDefinitionValidator`, and the `validate-schemas` CLI command exposes the built-in schema report.
`KarDataDefinitionRegistry` owns schema indexing by id and accessor type; `KarDataDefinitionCatalog` exposes the built-in KAR registry.
`KarArchiveInspector` can be constructed with a custom `KarDataDefinitionRegistry`; `Default` uses the built-in KAR registry.
Add new decomp-backed data schemas to the domain definition files (`KarMapDataDefinitions`, `KarVehicleDataDefinitions`, `KarVersusDataDefinitions`) and let `KarDataDefinitionCatalog` handle lookup/indexing.
