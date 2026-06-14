# doldecomp/kar Symbol Sync

Date: 2026-06-13

Upstream checkout: `external/doldecomp-kar`

Upstream commit: `3ed51a1`

## Scope

This pass imports conservative symbol upgrades from `doldecomp/kar` into the
local `GKYE01` symbol map. The upstream repository does not provide a
decomp-toolkit `symbols.txt`; names are extracted from global assembly labels
that have concrete instruction addresses.

The default import policy is intentionally narrow:

- Trust SysDolphin labels and runtime/SDK labels with concrete addresses.
- Trust Dolphin SDK names as SDK/library evidence, but compile SDK-shaped
  source objects with the SDK compiler slot instead of the KAR game compiler.
- Replace only generic local names such as `fn_803C3458`.
- Leave asm-only game labels disabled by default.
- Leave non-generic local names untouched unless a future run explicitly uses
  `--include-conflicts`.

This sync also mirrors the upstream `src/sysdolphin`, `src/os`, `src/Dolphin`,
and `include` files into this repo. The current KAR split map still groups much
of the early SysDolphin code, so only existing split objects are wired directly
to those sources for now; the remaining granular files are present for later
split refinement. `src/sysdolphin/objalloc.c` is mirrored but not wired as a
compiled source because the upstream file is currently an incomplete stub.

## Result

| Category | Renamed | Already named |
|---|---:|---:|
| Dolphin SDK | 97 | 236 |
| Runtime/SDK | 25 | 66 |
| SysDolphin | 11 | 236 |
| Total | 133 | 538 |

The import also wrote `docs/doldecomp_kar_symbol_sync.tsv`, which includes
renamed, already-named, and skipped labels. Notably, asm-only game labels such
as `Pad_InitCallback @ 80005800` are reported as skipped rather than applied.

## Build Configuration

`configure.py` now keeps the imported source assumptions separate:

- KAR game-code baseline remains `GC/1.3.2`.
- Source-backed `doldecomp/kar` objects use upstream-style source flags,
  including `-cwd source`, `-I-`, and `-inline all`.
- Dolphin SDK-shaped objects use `GC/1.0` through
  `DOLPHIN_SDK_COMPILER_VERSION`.

Verification:

- `python -m py_compile configure.py tools/import_doldecomp_kar_symbols.py`
- `python configure.py --version GKYE01`
- `python configure.py --version GKYJ01 --build-dir build-test-jp`
- `python configure.py --version GKYP01 --build-dir build-test-eu`
- `ninja -n`
