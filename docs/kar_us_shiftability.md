# GKYE01 Shiftability Checkpoint

This project uses the USA `GKYE01` DOL as the first split target. The current
`config/GKYE01/splits.txt` pass is hash-clean and has no auto-owned sections in
the generated report.

## Compiler Baseline

- CodeWarrior for GameCube 2.4.2 build 81 (`GC/1.3.2`)
- Game-code flags:
  `-O4,p -nodefaults -fp hard -Cpp_exceptions off -enum int -fp_contract on -inline auto`

## Current Split Pass

The USA split started from `KAR_Source_File_Function_Boundaries.tsv` and
`KAR_Source_Boundary_Rename_Pass.tsv`, then widened source files across
anonymous code gaps when local boundary evidence, imported symbol names,
strings, xrefs, or conservative runtime/backend buckets identified the owner.

The current pass also assigns `.init`, `.ctors`, `.dtors`, `.rodata`, `.data`,
`.sdata`, `.sdata2`, `.bss`, `.sbss`, and `.sbss2` ranges to source-named
objects. The final runtime exception island is claimed as
`Runtime.PPCEABI.H/__init_cpp_exceptions.cpp`, including its coupled ctor/dtor
records and `fragmentID` small-data record.

## Verified State

Strict verification command:

```sh
python configure.py --version GKYE01
ninja build/GKYE01/ok
```

Result:

```text
build/GKYE01/main.dol: OK
```

Nonmatching/link verification command:

```sh
python configure.py --version GKYE01 --non-matching --no-progress
ninja build/GKYE01/main.dol
```

Result: `build/GKYE01/main.dol` links successfully from checked-in
`asm/kar` overrides and source-owned objects.

Temporary shifted-link probe:

- Inserted one `nop` after the first `.fn` in each checked-in `asm/kar` file
  with code, covering all 193 asm files.
- Rebuilt the nonmatching DOL with those temporary offsets active.
- Restored every checked-in asm file from `build/GKYE01/asm` and rebuilt the
  unshifted nonmatching DOL.
- Re-ran the strict hash check afterward.

Result: the fully shifted asm probe linked successfully, no probe `nop`s remain
in the working tree, the restored nonmatching build links, and the strict build
is hash-clean.

Coverage after this pass:

- Source-named `.text`: 4,733,988 bytes across 210 units
- Source-named `.init`: 9,284 bytes
- Remaining auto code: 0 bytes across 0 units
- Source-named data/BSS/small-data/ctor/dtor: 1,429,227 bytes
- Remaining auto data: 0 bytes
- Current workbench claimable gaps: 0
- Raw checked-in asm operands inside split ranges: 22 unaligned constants, 0
  aligned DOL-range operands

## Shiftability Notes

The split now survives a broad link-only shifted asm test: every checked-in asm
unit was temporarily moved by at least one instruction, and the DOL still linked.
Normal builds also no longer depend on anonymous auto buckets to preserve
layout. That does not mean every owner name is final. Some `.sdata`, `.sdata2`,
BSS, runtime, SDK, and HSD boundaries are source-owned by ordering, xrefs,
strings, and conservative bucket placement rather than by recovered source
files.

Keep future movement tests focused on finding hidden ownership mistakes. If a
shifted build breaks, prefer tightening the owning split range or symbol label
over adding filler assembly. The next useful escalation is a runtime smoke test
of a shifted DOL in emulator or hardware, because raw linkability will not catch
all possible data-as-code or resource-format assumptions.

If a runtime probe is first made as a direct DOL or Ghidra byte patch, port it
back into checked-in asm as a symbolic reference before judging shiftability.
For example, an inserted `bl kar_lbaudio__near_80061658` after
`kar_gmglobal__near_800088c8+0x18` receives an `R_PPC_REL24` relocation and
links to the shifted function entry automatically; hardcoding the shifted target
address only proves that a binary patch was tied to one layout.

## Next Refinement Targets

- Run shifted DOLs in emulator or hardware and tighten any ownership that fails
  under execution.
- Add narrower shifted-layout probes for source-compiled runtime/SDK/HSD
  buckets as those files gain real source.
- Replace broad runtime/SDK/HSD buckets with more specific object names as more
  source or map evidence appears.
- Promote the same split strategy to other game versions only after the USA
  shifted tests stay stable.

See also:

- `docs/kar_us_auto_text_audit.md` for the generated auto-section audit.
- `docs/kar_shiftability_checklist.md` for the cross-version readiness list.
- `docs/kar_data_split_notes.md` for the data and small-data split notes.
