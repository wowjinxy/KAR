# GKYE01 Shiftability Checkpoint

This project uses the USA `GKYE01` DOL as the first split target. The current
`config/GKYE01/splits.txt` pass is provisional but hash-clean.

## Compiler Baseline

- CodeWarrior for GameCube 2.4.2 build 81 (`GC/1.3.2`)
- Game-code flags:
  `-O4,p -nodefaults -fp hard -Cpp_exceptions off -enum int -fp_contract on -inline auto`

## Current Split Pass

The USA `.text` split is based on
`KAR_Source_File_Function_Boundaries.tsv` and
`KAR_Source_Boundary_Rename_Pass.tsv`.

The first pass kept only tight known spans. The current pass widens a source
file across an adjacent anonymous gap only when the rename-pass evidence inside
that gap points to one neighboring source file. Large gaps without source
evidence are deliberately left as `auto_*` units.

This avoids the known bad case where `fl_indirectload.cpp` can accidentally
swallow Metrowerks/runtime code near `__init_cpp_exceptions`.

## Verified State

Verification command:

```sh
python configure.py --version GKYE01
ninja
```

Result:

```text
build/GKYE01/main.dol: OK
```

Coverage after this pass:

- Source-named `.text`: 1,563,796 bytes across 193 files
- Remaining auto `.text`: 3,170,192 bytes across 65 auto units
- Source-named data: 4 bytes
- Remaining auto data: 1,429,223 bytes

## Largest Remaining Auto Text Gaps

These are the main areas that still need better boundary evidence before the
project should be considered comfortably shiftable:

- `8011D0D0-8017B778` (386,728 bytes), between `ifround.c` and `mndialoguebg.c`
- `8018DB84-801DEC44` (331,968 bytes), between `clobject.c` and `vcgenerator.c`
- `80397080-803DAD1C` runtime/HSD/Metrowerks-adjacent region; keep split
  conservatively until identified in detail
- `802BA0DC-802EED00` (216,100 bytes), between `a2d_gamesession.cpp` and
  `a2d_cpu_kirby.cpp`
- `803DB46C-8040F00C` (211,872 bytes), after `OSThread.c`
- `80014D5C-8004788C` (207,664 bytes), between `gmracenormal.c` and
  `gmdialogue.c`
- `802EFD8C-803215F8` (202,860 bytes), between `a2d_kirbyjointanim.cpp` and
  `a2d_lavabomb.cpp`

## Next Refinement Targets

- Split `.rodata`, `.data`, `.sdata`, and BSS sections by source file.
- Promote low-confidence source-boundary rows once backed by strings, xrefs, or
  map/symbol neighborhood evidence.
- Identify the large anonymous gameplay and Air Ride 2D regions before trying
  to make their boundaries version-shiftable.

See also:

- `docs/kar_us_auto_text_audit.md` for the full ranked auto text gap list.
- `docs/kar_shiftability_checklist.md` for the cross-version readiness list.
- `docs/kar_data_split_notes.md` for the conservative data split plan.
