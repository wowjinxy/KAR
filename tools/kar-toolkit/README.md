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
```

All copy/save helpers go through `KarProjectWorkspace`, which reads from the extracted source folder and writes only under the configured output folder.
Project file discovery and map grouping go through `KarProjectIndexer`, with lookup results held by `KarProjectIndex`.
Project asset paths, byte reads/writes, and copies go through `KarProjectFileStore`.
Typed HSD archive and A2D package opens/saves go through `KarProjectArchiveStore`.
Project-level archive and map inspection goes through `KarProjectInspector`.
Project validation goes through `KarProjectValidator`, which creates a fresh validation run for each report.
Archive metadata lives in `KarArchiveCatalog`; live HSD root inspection goes through `KarArchiveInspector`.
Map bundle inspection goes through `KarMapInspector`, which ties each map's data, model, and event/script archives together.

Use `definitions` to list known KAR data schemas. Archive and map inspection attach schema details to known roots when the toolkit has decomp-backed field information.
Known root schemas also include read-only field values for mapped scalar fields and pointer presence/length, which is useful for quick archive comparison before writing editor code.
Add new decomp-backed data schemas to the domain definition files (`KarMapDataDefinitions`, `KarVehicleDataDefinitions`, `KarVersusDataDefinitions`) and let `KarDataDefinitionCatalog` handle lookup/indexing.
