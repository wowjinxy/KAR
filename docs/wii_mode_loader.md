# Experimental Wii-mode build

This is a KAR-specific compatibility loader derived from Pablo Stebler's
[dol2rvl proof of concept](https://gist.github.com/stblr/c99aa7bcdc26a0be78b4a50d6dc3359b).
It is not a native Wii port and does not alter the normal matching GameCube
build.

The loader starts in Wii mode, uses the original disc apploader to load Kirby
Air Ride into MEM1, redirects the GameCube ARAM interface into Wii MEM2, and
publishes a small allocation API for mod code. It supports `GKYE01`, `GKYJ01`,
and `GKYP01`; the inserted or mounted disc ID must match the loader build.

The `GKYE01` build has been exercised on Dolphin 2407 through save setup, the
title and menus, and more than 20 seconds of a live race with graphics, audio,
and disc streaming active. The Japanese and PAL builds pass the same structural
build validation but have not yet received equivalent runtime testing. Real Wii
hardware remains untested.

## Build

Configure the decomp with the opt-in flag, then build:

```sh
python configure.py --version GKYE01 --non-matching --wii-mode
ninja
```

The `--non-matching` option is needed when the build contains modded or
non-matching source. `--wii-mode` itself does not imply it. After configuring,
`ninja wii-loader` builds only the standalone loader.

The outputs are:

- `build/GKYE01/wii-loader/boot.dol`
- `build/GKYE01/wii-loader/manifest.json`

The normal decomp output remains `build/GKYE01/main.dol`. Wii-mode C and C++
translation units receive `KAR_WII_MEM2_TARGET=1`, which exposes the fixed MEM2
API in `include/kar/wii_mem2.h`.

Use `GKYJ01` or `GKYP01` for another region. The lower-level builder remains
available for a Dolphin diagnostic loader that enables KAR's `OSReport` output:

```sh
python tools/build_kar_wii_loader.py --version GKYE01 --dolphin-osreport
```

Diagnostic builds default to `build/GKYE01/wii-loader-debug`, keeping the
Ninja-managed release loader untouched.

The builder uses the repository's `Wii/1.0` CodeWarrior compiler, converts the
ELF with decomp-toolkit, and validates that all loader sections and the entry
point stay inside the reserved MEM2 range.

## Run in Dolphin

Dolphin needs both the loader DOL and a matching disc mounted. An extracted
disc is supported when `DefaultISO` points to its `sys/main.dol`; the sibling
`boot.bin`, `bi2.bin`, `apploader.img`, `fst.bin`, and `files` directory must be
present.

```powershell
Dolphin.exe -b `
  -e build\GKYE01\wii-loader\boot.dol `
  -C "Dolphin.Core.DefaultISO=E:\path\to\GKYE01\sys\main.dol"
```

This also provides a path for testing a locally rebuilt `main.dol`: place it in
a complete extracted-disc layout and mount that layout as above. A rebuilt or
modded DOL must preserve the reference link map for the fixed hook, SDK helper,
and AR-global addresses. The loader checks the disc number/revision and the
expected instruction signatures before patching, then stops with
`KAR_WII_LOADER_PATCH_FAILED` if those checks do not match; it does not discover
relocated symbols dynamically.

## MEM2 layout

| Range | Purpose |
| --- | --- |
| `0x90004000-0x91004000` | 16 MiB backing store for emulated ARAM |
| `0x91004000-0x91EFF000` | Persistent mod heap (about 14.98 MiB) |
| `0x91EFF000-0x91F00000` | Fixed API page |
| `0x91F00000-0x92000000` | Loader stack reservation |
| `0x93000000-0x933D0000` | Resident loader reservation |

The initial heap is intentionally conservative. The unused MEM2 gap between
the stack and loader may be evaluated later after gameplay stress testing.

Mod code can use the fixed ABI in `include/kar/wii_mem2.h`:

```c
#include "kar/wii_mem2.h"

void* AllocateModData(u32 size)
{
    if (!KARWiiMem2IsReady()) {
        return NULL;
    }
    return KAR_WII_MEM2_API->alloc(size, 0x20);
}
```

ABI version 1 is a persistent bump allocator. It has no `free` operation and is
not intended for concurrent allocation from multiple game threads. This must be
a loader-only mod target: MEM2 is unmapped in GameCube mode, so the header does
not expose the API or readiness probe unless `KAR_WII_MEM2_TARGET` is defined.
The `--wii-mode` configure flag supplies that definition. A single binary
cannot use this probe to distinguish a normal GameCube launch from a loader
launch safely.

## Compatibility patches

The loader deliberately keeps KAR's original `ARAlloc`, `ARFree`, `ARReset`,
`ARGetSize`, `ARQInit`, and `ARQPostRequest` implementations. It patches only:

- `ARInit`, to relocate the original allocator's base into MEM2;
- `ARStartDMA`, to perform the transfer as a CPU copy and defer the original ARQ
  completion callback through an `OSAlarm`;
- one KAR heap instruction, to convert the 16 MiB AR size into the relocated
  absolute end address; and
- one `GXInitTlutObj` instruction, to clear bits that are significant in Wii
  mode.

The complete eight-byte disc identity, both patch opcodes, both AR function
prologues, and the four SDK helper signatures are checked before control is
passed to the game. A failed check leaves loader status
`KAR_WII_LOADER_PATCH_FAILED` in the fixed API page instead of running a
partially patched game.

The adapted loader source retains dol2rvl's MIT notice. See
`tools/kar_wii_loader/LICENSE`.
