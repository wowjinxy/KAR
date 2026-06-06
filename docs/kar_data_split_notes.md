# KAR Data Split Notes

The current `GKYE01` split is text-heavy. Data ownership is still the main
reason the project is only provisionally shiftable.

## Current Auto Data Blocks

- `.data`: `80494E60-805352FC`, 656,540 bytes
- `.bss`: `80535300-805D50D0`, 654,800 bytes
- `.rodata`: `80489480-80494E48`, 47,560 bytes
- `.sdata`: `805D50E0-805DD51F`, 33,855 bytes
- `.sdata2`: `805DE700-805E62D0`, 31,696 bytes
- `.sbss`: `805DD520-805DDE68`, 2,376 bytes
- `.sbss`: `805DDE68-805DE700`, 2,200 bytes
- `.sbss2`: `805E62E0-805E6390`, 176 bytes

## Conservative Split Order

1. Split `.rodata` first using filename strings, nearby string clusters, and
   direct xrefs from already source-named `.text`.
2. Pair `.data` ranges with the source files that reference their strings,
   tables, or object records. Do not split large arrays by visual pattern alone.
3. Split `.sdata` and `.sdata2` only after their access functions are known;
   small-data ordering mistakes are painful to port.
4. Split `.bss`, `.sbss`, and `.sbss2` after global object ownership is clearer.
   BSS can look clean while still being wrong because there are no bytes to
   compare.
5. Leave exception metadata and runtime-adjacent records alone until the
   `80397080-803DAD1C` runtime region is identified in detail.

## First Evidence Sources To Use

- `KAR_Linked_File_String_Report.md`
- `KAR_Source_File_Xrefs_Report.md`
- `KAR_Source_File_Function_Boundaries.tsv`
- `KAR_Source_Boundary_Rename_Pass.tsv`
- Current `build/GKYE01/report.json`

## Definition Of Done For A Data Split Pass

- `python configure.py --version GKYE01` succeeds without missing object config
  warnings introduced by the pass.
- `ninja` reports `build/GKYE01/main.dol: OK`.
- The data split can be explained by xrefs, string adjacency, or version-shift
  evidence.
- Any intentionally unresolved range is still left as an `auto_*` unit.
