# KAR Data Split Notes

The current `GKYE01` split has no auto-owned data, BSS, small-data, ctor, or
dtor sections in `build/GKYE01/report.json`.

## Current Data Coverage

All listed bytes are assigned to source-named objects:

- `.rodata`: 47,560 bytes
- `.data`: 656,540 bytes
- `.sdata`: 33,855 bytes
- `.sdata2`: 31,696 bytes
- `.bss`: 654,800 bytes
- `.sbss`: 4,576 bytes
- `.sbss2`: 176 bytes
- `.ctors`: 12 bytes
- `.dtors`: 12 bytes

## Evidence Used

- Filename strings and neighboring string clusters
- Direct xrefs from source-named `.text`
- Existing source-order and split-order adjacency
- Known CodeWarrior runtime exception metadata
- Conservative runtime, SDK, HSD, audio, and network buckets where source-level
  names are not yet recovered

## Remaining Risk

Some small-data and BSS ownership is still provisional because those sections do
not always carry enough bytes or xrefs to prove exact source-file provenance.
The normal build is hash-clean, and a temporary all-asm shifted link test passes.
Runtime shifted tests should still be used to expose hidden boundary mistakes
that a linker-only probe cannot catch.

When a shifted build fails, keep the fix in the split metadata: move ownership
to the source object that actually owns the bytes, or split a range more tightly.
Do not add support assembly just to preserve the original layout.

## Definition Of Done For Future Data Refinement

- `python configure.py --version GKYE01` succeeds without new object-config
  warnings.
- `ninja build/GKYE01/ok` reports `build/GKYE01/main.dol: OK`.
- A shifted-layout test still builds and, where an emulator or hardware check is
  available, runs.
- The changed range can be explained by xrefs, string adjacency, symbol
  neighborhood, source-order evidence, or version-shift evidence.
