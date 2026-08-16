# KAR Wii OSS apploader source

This directory contains a modified copy of the GPLv2 Wii disc apploader
published by marcan and bushing in 2008. It is based on `cubeboot-tools` work
by Albert Herranz and the GameCube Linux Team.

Upstream:

- <https://hackmii.com/2008/08/open-source-apploader-iso-template/>
- <https://static.hackmii.com/wii-apploader.tar.gz>
- Archive SHA-256:
  `6f3ee1e6fb25f709511f78615ac79794fd02a9ab8a6f6abdb32258aa3a3335a7`

This copy was modified by KAR project contributors on 2026-08-15. The files
with functional changes relative to that archive are `apploader.c` and
`apploader.lds`; both carry a dated modification notice. Unchanged upstream
headers and startup code are retained with their original notices.

KAR changes are intentionally limited to the merged Wii-disc boot path:

- DOL sections must fit wholly in ordinary MEM1 or the reserved resident
  loader range at `0x93000000-0x933D0000`.
- DOL and BSS ranges are checked for overflow and against those allowlists.
- The DOL file bound is derived from the Wii DOL/FST word offsets; nonempty
  sections cannot overlap the DOL header, and cache-line-rounded reads must
  remain inside the file.
- FST size and alignment are checked before subtracting from the top of MEM1,
  and the loaded FST cannot overlap the apploader workspace.
- BSS is cleared before initialized sections are loaded. Retail KAR has
  initialized data within its broad BSS span, so the upstream ordering would
  erase valid data.
- The generated `apploader.img` is padded with zeroes to the size advertised by
  its header. No historical ISO-template padding is reused.

Build it with `python tools/build_kar_wii_apploader.py`. Generated binaries go
under `build/` and are not checked in. The complete disc-layout, preserved
`files/orig.dol`, ISO composition, verification, testing, and redistribution
workflow is documented in [`docs/wii_apploader.md`](../../docs/wii_apploader.md).

Runtime FST conversion and IOS `/dev/di` redirection are implemented by
`tools/kar_wii_loader`, not by this GPL apploader subtree.

This component is GPL-2.0-only; see [COPYING](COPYING). The repository's root
CC0 license does not relicense this subtree. If you distribute a generated
`apploader.img` or an ISO containing it, keep the corresponding source,
copyright notices, license, and build instructions available with it.

This is a disc apploader, not the Homebrew Channel. The source and generated
image contain no HBC executable or installation path.
