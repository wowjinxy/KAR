# Building a Wii-format Kirby Air Ride disc

This guide covers the complete source-built disc path for the experimental KAR
Wii-memory loader: what each component does, why the original DOL is preserved
as `files/orig.dol`, how to build and install the generated files, and how to
compose and test a Wii-format ISO.

This is a compatibility layer around the original GameCube executable, not a
native Wii port. It does not contain, install, or depend on the Homebrew
Channel. Dolphin can boot the resulting ISO directly. Launching a modified,
fake-signed disc on real hardware requires a suitable environment supplied by
the user; this repository does not install one, and real Wii hardware has not
yet been tested.

## Current status

- `GKYE01` (USA) has been tested with Dolphin 2407 through normal save setup,
  with encrypted partition reads continuing through IOS `/dev/di`.
- `GKYJ01` (Japan) and `GKYP01` (Europe) pass the same structural build checks,
  but have not received equivalent runtime testing.
- Only the ordinary DVD data-read operation is translated. Other GameCube DI
  commands, audio streaming/DTK operations, cover state, reset, seek, and
  hardware behavior remain outside the tested surface.
- The merged-disc builder currently accepts only an exact retail DOL. It does
  not accept an arbitrary rebuilt or relocated DOL.

## The pieces and their roles

An extracted disc layout used by this workflow looks like this:

```text
KAR-Wii/
|-- files/
|   |-- orig.dol              exact retail DOL, preserved build input
|   |-- debug_level_0.ini     real zero-byte KAR runtime marker
|   |-- dist_XX.ini           region marker (us, jp, or eu)
|   `-- ...                   all other original game files
`-- sys/
    |-- apploader.img         generated OSS Wii apploader
    |-- bi2.bin               original disc metadata
    |-- boot.bin              original game header
    |-- fst.bin               original extracted FST metadata
    `-- main.dol              generated merged DOL installed for boot
```

The similarly named DOL files have different jobs:

| File | Purpose | Read at boot/runtime? |
| --- | --- | --- |
| Original `sys/main.dol` | The unmodified regional KAR executable from the user's disc. | Yes, before this workflow changes the layout. |
| `files/orig.dol` | A safe copy of that exact original, passed to `--target-dol` when building the merged DOL. | No. It is a build/rebuild input only. |
| Generated `build/.../wii-loader-merged/boot.dol` | KAR's original MEM1 sections plus the resident loader's MEM2 sections in one DOL. | Installed as `sys/main.dol` and loaded by the apploader. |

There are two deliberately different loader paths:

| Path | Purpose | Mounted/embedded disc | Apploader | Ready flags |
| --- | --- | --- | --- | --- |
| Standalone `boot.dol` | Dolphin diagnostics and layout-preserving mod development | Matching GameCube disc/layout mounted separately | Retail GameCube apploader | `0x3` |
| Merged Wii ISO | Self-contained Wii-format disc image | Encrypted Wii DATA partition | Repository OSS apploader | `0xF` |

The standalone path takes direct ownership of DI and cannot simply be dropped
into an encrypted Wii partition. The merged path leaves DI with IOS, converts
the Wii FST offsets, and translates normal reads through `/dev/di`.

The boot sequence is:

```text
Wii boot environment or Dolphin
  -> opens the Wii data partition
  -> runs sys/apploader.img
  -> apploader loads merged sys/main.dol and the disc FST
  -> merged DOL enters the resident loader in MEM2
  -> loader initializes the MEM2 API, normalizes the Wii FST,
     opens IOS /dev/di, and patches KAR's fixed hook points
  -> loader jumps to KAR's original entry point in MEM1
```

## Why `files/orig.dol` is needed

Copy `sys/main.dol` to `files/orig.dol` **before** replacing anything in
`sys/`. The merged-DOL builder needs the original executable so it can:

1. verify the selected region by exact SHA-1;
2. copy KAR's original text and data sections into the merged DOL;
3. preserve KAR's original BSS range and entry point; and
4. add the resident loader's sections and make the loader the new first entry
   point.

After the merge, `sys/main.dol` is no longer the original executable. Keeping
the untouched copy under `files/` makes the extracted layout self-contained
and allows the merged DOL to be regenerated later without re-extracting the
disc. The name and location are a documented convention—the builder can accept
an exact original DOL from another path—but every command below intentionally
uses `files/orig.dol` so the wrong file is not selected accidentally.

Neither the OSS apploader nor the resident loader looks up `orig.dol` by name.
The apploader loads only the DOL installed as `sys/main.dol`; the original
KAR sections are already embedded in that merged file. Consequently:

- keep `files/orig.dol` in the working layout for repeatable rebuilds;
- it may be omitted from a final ISO without changing boot behavior;
- never point `--target-dol` at the generated/merged `sys/main.dol`; and
- never commit or redistribute `orig.dol`. It is proprietary game code that
  users must obtain from their own matching disc. The repository ignores
  `*.dol` files for this reason.

This is different from `files/debug_level_0.ini`. Every supported retail region
actually looks for that zero-byte marker at runtime, so it must remain in the
`files` tree. Preserve the matching zero-byte region marker too:
`dist_us.ini`, `dist_jp.ini`, or `dist_eu.ini`. A missing debug marker can send
KAR into its crash/debug loop even when the loader and apploader are otherwise
correct.

The accepted original DOL SHA-1 values are:

| Version | Region | Size | SHA-1 |
| --- | --- | ---: | --- |
| `GKYE01` | USA | 5,514,016 bytes | `977533bb96e6a16e127946396489be1b4164ac42` |
| `GKYJ01` | Japan | 5,492,224 bytes | `e901b9912af1b622c1f6d16fab6efe6cf505f108` |
| `GKYP01` | Europe | 5,459,328 bytes | `14e43ef2e3d971bbb6aae596a175ac485ff242a8` |

These are hashes and sizes of the clean extracted `sys/main.dol`, not an ISO,
decomp output, standalone `boot.dol`, or previously merged DOL.

## Why the OSS apploader is needed

The apploader is a small program stored at `sys/apploader.img`. After the Wii
data partition is opened, the boot environment calls the apploader repeatedly
to load `main.dol`, the FST, and BI2 data, then asks it for the executable entry
point.

Nintendo's retail apploader and the unmodified 2008 OSS apploader expect an
ordinary MEM1 DOL. The KAR merged DOL also contains a resident loader in the
reserved MEM2 range `0x93000000-0x933D0000`; the upstream OSS bounds check
rejects those sections. The repository's GPLv2 apploader therefore:

- permits DOL sections wholly inside ordinary MEM1 or that narrow MEM2 range;
- validates section addresses, BSS, DOL file bounds, alignment, and overflow;
- clears BSS before initialized sections are loaded, because retail KAR has
  initialized data inside its broad BSS span; and
- creates a clean `0x3020`-byte image with zero-only padding.

The apploader only performs boot-time loading. The resident loader is a
separate MIT-licensed program responsible for ARAM-to-MEM2 compatibility, the
mod heap/API, FST conversion, fixed KAR patches, and runtime IOS DVD reads.

Normal matching GameCube builds do not need this apploader. The standalone-DOL
diagnostic path described in [wii_mode_loader.md](wii_mode_loader.md) also uses
the mounted GameCube disc's own apploader instead.

## Prerequisites

You need:

- a legally obtained, fully extracted Kirby Air Ride disc matching `GKYE01`,
  `GKYJ01`, or `GKYP01`;
- Python 3 and Ninja;
- the repository's normal decomp build prerequisites;
- [devkitPPC](https://devkitpro.org/wiki/Getting_Started/devkitPPC) for
  `powerpc-eabi-gcc` and `powerpc-eabi-objcopy`; and
- [Wiimms ISO Tools](https://wit.wiimm.de/) (`wit`) to compose and verify the
  Wii-format image.

Initialize the repository's submodule after cloning:

```powershell
git submodule update --init --recursive
```

Run all repository commands from the repository root. The examples below use
PowerShell variables so paths containing spaces are handled safely:

```powershell
$Version = 'GKYE01'
$Layout = 'E:\path\to\KAR-Wii'
$LoaderOut = "build\$Version\wii-loader-merged"
$ApploaderOut = "build\$Version\wii-apploader"
$Iso = 'E:\path\to\KAR-Wii.iso'
```

Substitute the correct version and paths for your disc. Always work on a copy
of the extracted layout and write the ISO to a new path.

## 1. Prepare and verify the extracted layout

Start with a fresh, complete GameCube disc extraction containing the usual
`sys/` and `files/` directories. Do not hand-edit `boot.bin` or try to change
its GameCube magic: WIT creates the outer Wii disc header, encrypted DATA
partition, ticket, and TMD when it composes the final image. The original KAR
`boot.bin` remains inside that partition and is intentionally preserved.

Before installing any generated files, preserve the original DOL:

```powershell
New-Item -ItemType Directory -Force -Path "$Layout\files" | Out-Null

$OriginalDol = "$Layout\files\orig.dol"
if (Test-Path -LiteralPath $OriginalDol) {
    throw 'files/orig.dol already exists; verify it instead of overwriting it'
}

Copy-Item -LiteralPath "$Layout\sys\main.dol" -Destination $OriginalDol
(Get-FileHash -Algorithm SHA1 -LiteralPath $OriginalDol).Hash.ToLowerInvariant()
```

Compare the printed hash with the regional table above. The loader builder
will repeat this check and stop on any mismatch. If the hash is wrong, start
again from the correct unmodified regional extraction; do not rename another
region's DOL or use a previously merged DOL.

Confirm the rest of the original layout is still present:

```powershell
@(
    "$Layout\sys\boot.bin",
    "$Layout\sys\bi2.bin",
    "$Layout\sys\fst.bin",
    "$Layout\files\opening.bnr"
) | ForEach-Object {
    if (-not (Test-Path -LiteralPath $_)) { throw "Missing extracted file: $_" }
}
```

Confirm the retail runtime markers for the selected region exist and are empty:

```powershell
$RegionMarker = @{
    GKYE01 = 'dist_us.ini'
    GKYJ01 = 'dist_jp.ini'
    GKYP01 = 'dist_eu.ini'
}[$Version]

@('debug_level_0.ini', $RegionMarker) | ForEach-Object {
    $Marker = Get-Item -LiteralPath "$Layout\files\$_"
    if ($Marker.Length -ne 0) { throw "$_ should be zero bytes" }
}
```

Do not delete or selectively copy the game file tree. KAR streams assets after
boot, and a successful apploader handoff does not prove that the extraction is
complete.

## 2. Fetch the loader toolchain and build the standalone target

Configure the opt-in Wii mode once. This also gives Ninja enough information
to fetch/build the CodeWarrior and decomp-toolkit dependencies used by the
lower-level loader builder:

```powershell
python configure.py --version $Version --non-matching --wii-mode
ninja wii-loader
```

This first produces the standalone loader under
`build/<VERSION>/wii-loader/`. It is useful as a regression/diagnostic target,
but it is not the merged `sys/main.dol` used by the Wii-format ISO.

## 3. Build the merged KAR + MEM2 loader DOL

Pass the preserved retail DOL explicitly:

```powershell
python tools/build_kar_wii_loader.py `
  --version $Version `
  --target-dol $OriginalDol `
  --output-dir $LoaderOut
```

Outputs include:

- `boot.dol` — the merged DOL to install as `sys/main.dol`;
- `kar-wii-loader.elf` — the resident loader ELF for inspection; and
- `manifest.json` — standalone/merged mode, selected version, input and
  toolchain hashes, target filename/hash, target entry and BSS, resolved hook
  addresses, memory map, merged sections, and output hash. Absolute local paths
  are intentionally omitted.

The builder rejects the wrong regional SHA-1, malformed or overlapping DOL
sections, unsafe MEM1/MEM2 ranges, too many DOL sections, invalid entry/BSS
ranges, and a merged image whose sections change during serialization. It also
pads the final DOL to the cache-line reads expected by the apploader.

## 4. Build the GPLv2 OSS apploader

If devkitPPC is installed at its usual Windows path:

```powershell
python tools/build_kar_wii_apploader.py `
  --devkitppc C:\devkitPro\devkitPPC `
  --output-dir $ApploaderOut
```

You may instead set `DEVKITPPC`, put the tools on `PATH`, or pass explicit
`--gcc` and `--objcopy` paths.

Outputs include:

- `apploader.img` — the validated, padded image for `sys/apploader.img`;
- `apploader.bin` — the unpadded rebuilt binary;
- `kar-wii-apploader.elf` — the ELF for inspection; and
- `apploader-manifest.json` — source, toolchain, header, and output hashes.

The builder parses the big-endian apploader header, requires its advertised
`0x2000` body and `0x1000` trailer, verifies the entry is inside the loaded
body, rejects overflow, and creates all padding itself.

## 5. Install the generated boot files

Only after `files/orig.dol` has been copied and verified, replace the two boot
components in the working layout:

```powershell
Copy-Item -Force -LiteralPath "$LoaderOut\boot.dol" `
  -Destination "$Layout\sys\main.dol"
Copy-Item -Force -LiteralPath "$ApploaderOut\apploader.img" `
  -Destination "$Layout\sys\apploader.img"
```

Leave the original `boot.bin`, `bi2.bin`, `fst.bin`, and game `files/` contents
in place. At this point:

- `sys/main.dol` must be the generated merged file;
- `files/orig.dol` must still be the exact original file; and
- those two files must not have the same hash or size.

The generated manifests make that distinction explicit. In merged mode,
`manifest.json` contains both a top-level `dol` object for the generated output
and a `target_dol` object for the preserved retail input.

## 6. Compose and verify a Wii-format ISO

Compose a new encrypted Wii data-partition image from the extracted layout:

```powershell
wit --allow-fst=on --iso copy "$Layout" "$Iso"
wit verify "$Iso"
wit dump "$Iso"
```

`wit dump` should identify the result as `ISO/WII` with a Wii data partition,
and `wit verify` should finish with `+OK`. The tested result contains one
encrypted DATA partition with fake-signed ticket/TMD metadata and the matching
game ID. WIT composes a new FST from the working `files/` tree. Dolphin uses
the outer Wii disc/partition format to classify the game; the original
GameCube `boot.bin` is intentionally preserved inside the data partition.

Structural verification is not a gameplay test. If Dolphin cached the old
platform icon, rescan the game directory or remove and re-add the new ISO path.

If `files/orig.dol` remains in the working tree, WIT includes it as an ordinary
unused FST file. That is convenient for a private, self-contained rebuild
layout but adds a duplicate copy of the original executable. You may remove it
from a separate final-ISO staging copy after both generated files have been
built. Keep the canonical copy somewhere safe for future rebuilds.

Do not distribute the resulting ISO, `files/orig.dol`, or any other extracted
Nintendo game data. Distribute source changes, patches, and these build
instructions so each user can rebuild from their own disc.

## 7. Test in Dolphin

Add or open the generated ISO in Dolphin. It should be classified as a Wii
disc. A successful `GKYE01` merged boot reaches normal game UI rather than
remaining in a loader loop, and the fixed MEM2 API page reports:

- magic `KAR2` (`0x4B415232`);
- ABI version `1`;
- loader status `5` (`KAR_WII_LOADER_RUNNING_GAME`); and
- flags `0xF` (ARAM emulation, ARQ CPU copies, byte-normalized FST offsets,
  and IOS DI reads).

The public API and memory map are documented in
[wii_mode_loader.md](wii_mode_loader.md) and declared in
`include/kar/wii_mem2.h`.

### MEM2 API flags

The API page is at `0x91EFF000`; loader status is at offset `+0x8` and flags
are at `+0xC`:

| Flag | Meaning |
| --- | --- |
| `0x1` | The 16 MiB GameCube ARAM space is emulated in MEM2. |
| `0x2` | ARQ transfers use the loader's CPU-copy compatibility path. |
| `0x4` | Wii FST word offsets were converted to KAR byte offsets. |
| `0x8` | Runtime normal reads are routed through IOS `/dev/di`. |

Standalone readiness is normally `0x3`; merged-disc readiness is `0xF`.

## Runtime DVD translation

The OSS apploader performs only the boot-time reads. Wii disc data partitions
are encrypted, so letting KAR issue its original GameCube A8 DI reads after
boot returns the wrong raw data. Before entering KAR, the merged loader:

1. converts Wii FST file offsets from word units to the byte units KAR expects;
2. leaves IOS in control of the drive and opens `/dev/di`;
3. patches KAR's low-level normal-read issuer;
4. sends decrypted IOS DI ioctl `0x71` reads; and
5. polls completion with short `OSAlarm` callbacks so optical latency does not
   block KAR while its alarm scheduler context has interrupts constrained.

The shim supports one in-flight normal read. Its destination and length must be
32-byte aligned and its byte offset must be four-byte aligned, matching the
covered KAR path. It preserves KAR's callback/cancellation bookkeeping for
that path and retains buffer ownership until a late IOS reply is reaped after
timeout. It does not provide general translation for audio streaming, cover or
disc-change state, reset, seek, unrelated cancellation/error commands, or
other GameCube DI operations.

## Loader status and troubleshooting

The loader publishes the following statuses at the fixed MEM2 API page:

| Value | Name | Meaning |
| --- | --- | --- |
| `0` | `BOOTING` | Loader initialization began. |
| `1` | `WAITING_FOR_DISC` | Standalone path is waiting for a disc. |
| `2` | `WRONG_DISC` | Disc ID, number, or revision does not match the build. |
| `3` | `LOADING_GAME` | Loader is preparing KAR. |
| `4` | `PATCHING_GAME` | Fixed instruction/signature checks are running. |
| `5` | `RUNNING_GAME` | Patches succeeded and control entered KAR. |
| `6` | `PATCH_FAILED` | A fixed hook or SDK signature did not match. |
| `7` | `FST_FAILED` | Wii FST validation/conversion failed. |
| `8` | `IOS_DI_INIT_FAILED` | `/dev/di` could not be opened. |
| `9` | `IOS_DI_READ_FAILED` | A runtime IOS read failed or timed out. |

Common failure cases:

- **Loop at `0x8043f8ac`:** this address is KAR's crash/debug-console idle
  loop, not the original cause. Inspect the first exception or OSReport message
  before the loop. In the tested USA layout, a missing zero-byte
  `files/debug_level_0.ini` first produced the `gmmain.c:137` assertion and
  then reached this loop.
- **Data faults after the first file read:** confirm the merged DOL—not a
  standalone loader or stale earlier build—is installed, and check for status
  `8` or `9`. During development, encrypted bytes reaching KAR's direct
  GameCube DI path produced the later `devcom.c:560` failure. Raw GameCube DI
  reads cannot read decrypted Wii partition data.
- **Black screen before API magic appears:** the failure is probably in the
  boot environment or apploader, before the resident loader ran. Enable
  Dolphin `OSREPORT_HLE`, `BOOT`, `IOS_DI`, and `WII_IPC` logging and inspect
  the earliest error.
- **Target SHA-1 mismatch:** restore the exact original DOL for the selected
  region. Do not hash the generated `sys/main.dol`.
- **`segment past DOL file size`:** rebuild with the current builder; it pads
  merged sections for the apploader's cache-line-sized reads.
- **Status `2` or `6`:** the version, disc identity, or fixed executable layout
  differs from the selected build. The loader does not discover relocated hook
  addresses dynamically.
- **Dolphin still lists a GameCube game:** inspect the new output with
  `wit dump`; it must say `ISO/WII`. Make sure Dolphin is scanning the new ISO,
  not the original disc or extracted folder.

`wit verify` reporting `+OK` proves disc structure and hashes, not gameplay.
The merged USA path has only been exercised through normal save setup and
decrypted asset reads. The longer live-race test applies to the standalone
path; Japanese, PAL, and real Wii hardware remain runtime-untested.

## Modder-facing constraints

`python configure.py --wii-mode` defines `KAR_WII_MEM2_TARGET=1` for Wii-mode
C/C++ translation units, enabling the guarded API in `include/kar/wii_mem2.h`.
MEM2 is not mapped in GameCube mode, so do not enable or probe this API from a
binary that may run directly as a normal GameCube executable.

The first 16 MiB of the reserved MEM2 space backs emulated ARAM. The API exposes
the following roughly 14.98 MiB as a persistent mod heap
(`0x91004000-0x91EFF000`). Mods allocate from that heap through `alloc`; they
cannot treat it as a place to link arbitrary initialized DOL sections.

For ABI version 1:

- alignment `0` selects `0x20`; any explicit alignment must be a power of two;
- `alloc` returns `NULL` for invalid alignment, overflow, or exhaustion;
- allocations persist for the process lifetime and there is no `free`;
- allocation is not safe to call concurrently from multiple game threads;
- `available()` reports raw remaining bytes and does not subtract alignment
  padding that the next allocation may require; and
- DMA or hardware clients remain responsible for the required cache
  maintenance around their own buffers.

`KARWiiMem2IsReady()` checks only the magic and ABI version. Code that requires
the merged-disc services must also check status `5` and the needed flags, such
as `0xC` for normalized FST offsets plus IOS DI reads.

The merged-disc path still requires the exact retail target DOL because its
patch points and shared SDK helper signatures are fixed per region.
Layout-preserving hooks/mods can use the API after the loader is ready;
arbitrary relocated decomp outputs require future loader work.

## License, source, and redistribution

The two boot components have different licenses:

- `tools/kar_wii_loader` is adapted from Pablo Stebler's `dol2rvl` proof of
  concept and retains its MIT license.
- `tools/kar_wii_apploader` is a modified copy of the 2008 OSS Wii apploader by
  marcan and bushing, based on work by Albert Herranz and the GameCube Linux
  Team. It is GPL-2.0-only and includes `README.md` and `COPYING`.

The repository root's CC0 license does not relicense either separately marked
subtree. See `THIRD_PARTY_NOTICES.md` for the combined notice.

If you distribute `apploader.img` or another binary containing the GPLv2
apploader, make the corresponding modified apploader source, copyright notices,
GPLv2 license, and build instructions available with it. The simplest source
release is this repository revision. Do not bundle Nintendo's original DOL,
game files, or a rebuilt ISO with the source release.

## Release checklist

Before sharing a patch or source release:

- build the standalone loader, merged loader, and apploader from a clean tree;
- verify `manifest.json` identifies the intended region and original SHA-1;
- verify `apploader-manifest.json` and both generated output hashes;
- install only generated `boot.dol` and `apploader.img` into the staging copy;
- run `wit verify` and confirm `wit dump` reports `ISO/WII`;
- test through at least save setup and a runtime asset read in Dolphin;
- keep `files/orig.dol`, all extracted assets, and the ISO out of Git; and
- include the MIT/GPL notices and point users to this guide.
