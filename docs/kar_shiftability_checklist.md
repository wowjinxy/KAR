# KAR Shiftability Checklist

This checklist tracks what has to be true before the project should be treated
as shiftable across `GKYE01`, `GKYJ01`, and `GKYP01`.

## Current Status

- `GKYE01`: provisional `.text` split, hash-clean.
- `GKYJ01`: baseline analysis present, source-file split work not ported.
- `GKYP01`: baseline analysis present, source-file split work not ported.
- Compiler baseline: CodeWarrior for GameCube 2.4.2 build 81 (`GC/1.3.2`).

## Required Before Calling It Shiftable

- All three versions configure and build with `main.dol: OK`.
- The split-widening heuristic reports zero newly claimable `GKYE01` gaps:
  `python tools/kar_split_workbench.py --version GKYE01`.
- Large anonymous text gaps are either named, intentionally bracketed, or
  documented as runtime/SDK/HSD risk.
- `.rodata`, `.data`, `.sdata`, `.sdata2`, and BSS are no longer monolithic
  auto sections.
- The `fl_indirectload.cpp` to `OSThread` runtime region stays conservative
  until exception/runtime ownership is identified.
- Version-shift checks compare the same source-file order across USA, Japan,
  and Europe before split ranges are ported.

## Current High-Priority Text Gaps

Use `docs/kar_us_auto_text_audit.md` for the full list. The first refinement
targets are the large non-runtime ranges:

- `8011D0D0-8017B778`, between `ifround` and `mndialoguebg`
- `8018DB84-801DEC44`, between `clobject` and `vcgenerator`
- `802BA0DC-802EED00`, between `a2d_gamesession` and `a2d_cpu_kirby`
- `80014D5C-8004788C`, between `gmracenormal` and `gmdialogue`
- `802EFD8C-803215F8`, between `a2d_kirbyjointanim` and `a2d_lavabomb`
- `8028B974-802B5E3C`, between `a2d_game_lib` and `a2d_gamehistory`
- `803448A4-8036E92C`, between `a2d_bg8000` and `a2d_kurakko`

## Useful Commands

Regenerate the current auto-text audit:

```sh
python tools/kar_split_workbench.py --version GKYE01 --write-audit docs/kar_us_auto_text_audit.md
```

Dry-run the widening heuristic:

```sh
python tools/kar_split_workbench.py --version GKYE01
```

Apply the widening heuristic after resetting to tighter ranges or after adding
new evidence:

```sh
python tools/kar_split_workbench.py --version GKYE01 --apply-widening
python configure.py --version GKYE01
ninja
```
