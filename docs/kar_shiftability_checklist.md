# KAR Shiftability Checklist

This checklist tracks what has to be true before the project should be treated
as shiftable across `GKYE01`, `GKYJ01`, and `GKYP01`.

## Current Status

- `GKYE01`: source-owned code/data split, hash-clean, zero workbench gaps,
  and all-asm shifted-link probe passes.
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
- Shifted DOLs run in emulator or hardware without hidden absolute-address or
  data-owner failures.
- Version-shift checks compare the same source-file order across USA, Japan,
  and Europe before split ranges are ported.

## Current High-Priority Text Gaps

None in the current `GKYE01` report. Use `docs/kar_us_auto_text_audit.md` for
the generated audit; it currently reports zero auto-owned text and zero
claimable widening gaps.

## Useful Commands

Regenerate the current auto-text audit:

```sh
python tools/kar_split_workbench.py --version GKYE01 --write-audit docs/kar_us_auto_text_audit.md
```

Dry-run the widening heuristic:

```sh
python tools/kar_split_workbench.py --version GKYE01
```

Verify the current exact and nonmatching builds:

```sh
python configure.py --version GKYE01
ninja build/GKYE01/ok
python configure.py --version GKYE01 --non-matching --no-progress
ninja build/GKYE01/main.dol
```
