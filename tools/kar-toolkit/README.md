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

## CLI

```powershell
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll validate .\GKYE01 --no-unknown-roots
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll map .\GKYE01 City1
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll definition kar.vs.legendary
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll archive .\GKYE01 VcCommon.dat --json --max-reference-depth 2 --max-reference-entries 16
dotnet .\tools\kar-toolkit\src\KARToolkit.Cli\bin\Debug\net8.0\kar-toolkit.dll set-scalar .\GKYE01 VsHydra.dat kar.vs.legendary x0C 1 --schema --output .\mod-output
```

All copy/save helpers go through `KarProjectWorkspace`, which reads from the extracted source folder and writes only under the configured output folder.
Use `KarProject.Open(KarProjectOptions)` when a tool needs custom output roots, project indexing, archive inspection, or data schema registries.
Project file discovery and map grouping go through `KarProjectIndexer`, with lookup results held by `KarProjectIndex`.
Project file kind classification and map-name extraction go through `KarProjectFileClassifier`.
`KarProjectFileCatalog` is the replaceable service that connects file classification, HSD-kind checks, and map-name extraction.
`KarArchiveDefinitionProvider` is the replaceable service that turns file kind, path, and optional map name into archive/root metadata.
Project asset paths, byte reads/writes, and copies go through `KarProjectFileStore`.
Copy operations can return `KarProjectFileCopyResult` when tools need both the copied file metadata and destination path.
Write/save operations can return `KarProjectFileWriteResult` when tools need normalized project paths and output metadata.
Map copy/save operations can return `KarProjectMapOutputResult` when tools need the output paths grouped by data, model, and event/script file.
Typed HSD archive and A2D package opens/saves go through `KarProjectArchiveStore`.
Editable project archive handles (`KarProjectHsdArchive`, `KarProjectA2DPackage`) keep project metadata attached while saving through the safe output folder.
Editable map archive bundles (`KarProjectMapArchiveBundle`) group a map's data, model, and event/script archives for project-level workflows.
Project-level archive and map inspection goes through `KarProjectInspector`.
Project validation goes through `KarProjectValidator`, which creates a fresh validation run for each report.
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
Map gameplay schemas include position nodes, position-list rows, and coordinate rows for event, item, vehicle, dead-position, and area tables.
Schema-backed scalar fields can be edited in memory through `KarDataEditor` or `KarProjectHsdArchive.SetScalarField*`, then saved through the output-only project archive APIs.
The `set-scalar` CLI command exposes that same safe output-only scalar edit path for quick mod experiments.
`KarDataDefinitionRegistry` owns schema indexing by id and accessor type; `KarDataDefinitionCatalog` exposes the built-in KAR registry.
`KarArchiveInspector` can be constructed with a custom `KarDataDefinitionRegistry`; `Default` uses the built-in KAR registry.
Add new decomp-backed data schemas to the domain definition files (`KarMapDataDefinitions`, `KarVehicleDataDefinitions`, `KarVersusDataDefinitions`) and let `KarDataDefinitionCatalog` handle lookup/indexing.
