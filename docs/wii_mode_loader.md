# Experimental Wii-mode build

This is a KAR-specific compatibility loader derived from Pablo Stebler's
[dol2rvl proof of concept](https://gist.github.com/stblr/c99aa7bcdc26a0be78b4a50d6dc3359b).
It is not a native Wii port and does not alter the normal matching GameCube
build.

The loader starts in Wii mode, redirects the GameCube ARAM interface into Wii
MEM2, and publishes a small allocation API for mod code. In standalone-DOL
tests it uses the mounted GameCube disc's original apploader to load Kirby Air
Ride into MEM1. A merged Wii-format disc instead uses the repository's patched
[OSS Wii apploader](wii_apploader.md), with no Homebrew Channel dependency. It
supports `GKYE01`, `GKYJ01`, and `GKYP01`; the inserted or mounted disc ID must
match the loader build.

The standalone `GKYE01` build has been exercised on Dolphin 2407 through save
setup, the title and menus, and more than 20 seconds of a live race with
graphics, audio, and disc streaming active. The merged Wii-disc build has also
reached normal save setup while streaming decrypted assets through IOS. The
Japanese and PAL builds pass the same structural build validation but have not
yet received equivalent runtime testing. Real Wii hardware remains untested.

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

`ninja wii-loader` builds only the standalone loader. It does not build the GPL
apploader, create the merged DOL, change an extracted disc, or compose an ISO.
Those are separate, explicit steps in [wii_apploader.md](wii_apploader.md).

Use `GKYJ01` or `GKYP01` for another region. The lower-level builder remains
available for a Dolphin diagnostic loader that enables KAR's `OSReport` output:

```sh
python tools/build_kar_wii_loader.py --version GKYE01 --dolphin-osreport
```

Diagnostic builds default to `build/GKYE01/wii-loader-debug`, keeping the
Ninja-managed release loader untouched.

To make a single DOL whose Wii apploader preloads both the compatibility loader
and an exact KAR executable, preserve the original regional `sys/main.dol` as
`files/orig.dol` **before** overwriting the extracted layout, then pass that copy
explicitly:

```sh
python tools/build_kar_wii_loader.py --version GKYE01 \
  --target-dol "path/to/layout/files/orig.dol" \
  --output-dir build/GKYE01/wii-loader-merged
```

The builder rejects a target whose SHA-1 does not match the selected region,
preserves the target's BSS, and records its entry point and hashes in the
manifest. The resulting `boot.dol` enters the resident loader first, patches
the already-loaded KAR image, and then jumps to KAR.

`files/orig.dol` is a build-time canonical copy, not a runtime payload. The
merged `boot.dol` already contains all original KAR sections, and neither the
apploader nor the resident loader opens `orig.dol`. Keeping it in the working
layout makes later rebuilds repeatable after `sys/main.dol` has become the
merged output. It may be removed from a separate final-ISO staging copy, but it
must never be committed or redistributed. By contrast, every supported retail
region reads its original zero-byte `files/debug_level_0.ini` marker at runtime,
so that marker and the matching `dist_us.ini`, `dist_jp.ini`, or `dist_eu.ini`
must remain.

Merged-target mode normalizes Wii FST word offsets before entering KAR. It also
keeps IOS in control of DI, opens `/dev/di`, and replaces KAR's low-level DVD
read issuer with an IOS ioctl `0x71` path so runtime reads receive decrypted
partition data. The original DVD callback is deferred through an `OSAlarm` to
preserve asynchronous completion behavior.

Only the normal data-read path is translated. Other GameCube DI commands and
real Wii hardware remain untested. The merged builder currently accepts only
the exact retail target DOL: arbitrary relocated decomp outputs are not yet a
supported ISO input because the loader depends on fixed regional hooks and SDK
signatures. See [wii_apploader.md](wii_apploader.md) for the complete
apploader, layout, ISO, test, troubleshooting, licensing, and distribution
workflow.

The builder uses the repository's `Wii/1.0` CodeWarrior compiler, converts the
ELF with decomp-toolkit, and validates that all loader sections and the entry
point stay inside the reserved MEM2 range.

## Run the standalone loader in Dolphin

Dolphin needs both the loader DOL and a matching disc mounted. An extracted
disc is supported when `DefaultISO` points to its `sys/main.dol`; the sibling
`boot.bin`, `bi2.bin`, `apploader.img`, `fst.bin`, and `files` directory must be
present.

```powershell
Dolphin.exe -b `
  -e build\GKYE01\wii-loader\boot.dol `
  -C "Dolphin.Core.DefaultISO=E:\path\to\GKYE01\sys\main.dol"
```

This also provides a diagnostic path for a locally rebuilt `main.dol`: place it
in a complete extracted GameCube disc layout and mount that layout as above. A
rebuilt or modded DOL must preserve the reference link map for the fixed hook,
SDK helper, and AR-global addresses. The loader checks the disc number/revision
and expected instruction signatures before patching, then stops with
`KAR_WII_LOADER_PATCH_FAILED` if those checks do not match; it does not discover
relocated symbols dynamically.

For the merged Wii ISO, open the ISO itself in Dolphin instead of launching the
standalone DOL. Follow [wii_apploader.md](wii_apploader.md) so that both
`sys/main.dol` and `sys/apploader.img` are installed correctly.

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
    if (!KARWiiMem2IsReady() ||
        KAR_WII_MEM2_API->loader_status != KAR_WII_LOADER_RUNNING_GAME) {
        return NULL;
    }
    return KAR_WII_MEM2_API->alloc(size, 0x20);
}
```

ABI version 1 is a persistent bump allocator. Alignment `0` selects `0x20`; an
explicit alignment must be a power of two. `alloc` returns `NULL` for invalid
alignment, arithmetic overflow, or exhaustion. It has no `free` operation and
is not intended for concurrent allocation from multiple game threads.
`available()` reports raw remaining bytes before any alignment padding needed
by the next allocation. DMA or hardware clients are responsible for cache
coherency around their own buffers.

`KARWiiMem2IsReady()` checks the magic and ABI version only. Code should also
check loader status `5`; merged-disc code that relies on the FST/IOS shim should
require flags `0xC`. The full flag and status tables are in
[wii_apploader.md](wii_apploader.md#mem2-api-flags).

This must be a loader-only mod target: MEM2 is unmapped in GameCube mode, so the
header does not expose the API or readiness probe unless
`KAR_WII_MEM2_TARGET` is defined. The `--wii-mode` configure flag supplies that
definition. A single binary cannot use this probe to distinguish a normal
GameCube launch from a loader launch safely. Initialized DOL sections also
cannot simply be linked into the bump-allocator range; obtain dynamic mod data
through the API.

The build flag exposes the API to source code; it does not by itself package a
rebuilt `main.dol` into the exact-retail merged ISO path. Until nonmatching
targets gain safe hook discovery/validation, use layout-preserving mods with
the loader ABI or the standalone extracted-disc diagnostic path.

## Compatibility patches

The loader deliberately keeps KAR's original `ARAlloc`, `ARFree`, `ARReset`,
`ARGetSize`, `ARQInit`, and `ARQPostRequest` implementations. It patches only:

- `ARInit`, to relocate the original allocator's base into MEM2;
- `ARStartDMA`, to perform the transfer as a CPU copy and defer the original ARQ
  completion callback through an `OSAlarm`;
- one KAR heap instruction, to convert the 16 MiB AR size into the relocated
  absolute end address;
- one `GXInitTlutObj` instruction, to clear bits that are significant in Wii
  mode; and
- in merged-target mode, KAR's low-level DVD read issuer, to route partition
  reads through IOS `/dev/di`.

Merged-target mode also rewrites the loaded FST's file offsets from Wii word
units to the byte units KAR expects before entering the game.

The complete eight-byte disc identity, both patch opcodes, both AR function
prologues, and the four shared SDK helper signatures are checked before control
is passed to the game. Merged-target mode additionally checks the DVD
read-issuer prologue before installing its hook. A failed check leaves loader
status `KAR_WII_LOADER_PATCH_FAILED` in the fixed API page instead of running
a partially patched game.

The adapted loader source retains dol2rvl's MIT notice. See
`tools/kar_wii_loader/LICENSE`.
