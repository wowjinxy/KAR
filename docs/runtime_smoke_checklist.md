# KAR Runtime Smoke Checklist

Use this checklist to catch runtime-only layout and ownership mistakes that a
hash-clean or link-clean build cannot prove away. Record results in
`docs/project_backlog.md`.

## Prerequisites

- Build the target version before testing:

```sh
python configure.py --map --version <GAMEID>
ninja build/<GAMEID>/ok build/<GAMEID>/report.json
```

- Local Dolphin executable:

```text
E:\GPT5\Twitchy-Dolphin\dolphin\Binary\x64\Dolphin.exe
```

- Normal DOL path:

```text
build/<GAMEID>/main.dol
```

- Shifted DOL path: record the exact probe or patch that produced it before
  testing. If the probe starts as a direct binary patch, port useful findings
  back to symbolic source/split changes before treating it as proof.

## Launch

Preferred command-line launch, if supported by the local Dolphin build:

```powershell
& "E:\GPT5\Twitchy-Dolphin\dolphin\Binary\x64\Dolphin.exe" -e "E:\GPT5\KAR-5.5\kar-decomp\build\<GAMEID>\main.dol"
```

If command-line launch is not reliable, open Dolphin manually and load the DOL
from the UI.

Do not treat a bare `build/<GAMEID>/main.dol` launch as equivalent to a launch
from an extracted disc tree. A real-video probe on July 10, 2026 showed that a
bare `build/GKYE01/main.dol` launch can hit an invalid-read panic while the
byte-identical original DOL launched from `orig/GKYE01/sys/main.dol` reaches the
save-data prompt. Prefer an extracted-disc-context harness for visual smoke:
the tested DOL should live as `sys/main.dol` beside the matching extracted
`sys` metadata and `files` tree.

Automation note: on July 10, 2026 this Codex session could verify that
`Dolphin.exe` exists, but Computer Use failed during bootstrap with an internal
`@oai/sky` package export error before any emulator window could be launched or
captured. Later retries, including one at local machine time
`2026-07-10 22:55:42 -05:00`, failed with the same error before app discovery.
Treat the visual/gameplay parts of the result matrix below as still untested
until Dolphin is run manually or the Windows app-control runtime is repaired.

## CLI Boot Probe

On July 10, 2026 a batch-only boot probe was run with an isolated Dolphin user
folder and the null video backend:

```powershell
& "E:\GPT5\Twitchy-Dolphin\dolphin\Binary\x64\Dolphin.exe" `
  -u "E:\GPT5\KAR-5.5\kar-decomp\build\runtime_smoke\<GAMEID>-<LAYOUT>-user" `
  -b -e "<DOL path>" `
  -v Null -a HLE
```

Normal DOL probes used `build/<GAMEID>/main.dol`. Shifted DOL probes used copied
artifacts produced from explicit nonmatching configs, then exact mapped DOLs
were rebuilt for all three versions and `build.ninja` was restored to
`--map --version GKYE01`.

All normal and shifted probes were still running after 45 seconds and were
killed by the probe; stdout and stderr were empty for all six runs. This is only
no-immediate-exit evidence under a null-video batch boot. It does not verify
title/menu, race start, input, audio, or rendering.

Probe artifacts:

- `build/runtime_smoke/GKYE01-normal.result.txt`
- `build/runtime_smoke/GKYJ01-normal.result.txt`
- `build/runtime_smoke/GKYP01-normal.result.txt`
- `build/runtime_smoke/GKYE01-shifted.result.txt`
- `build/runtime_smoke/GKYJ01-shifted.result.txt`
- `build/runtime_smoke/GKYP01-shifted.result.txt`

Shifted DOL hashes:

- `GKYE01`: `build/runtime_smoke/GKYE01-shifted-main.dol`, SHA256
  `6F082ECAC759E3699521CAD00ECC7E9750FEE00C28409FA294A7A4F71838D08C`
- `GKYJ01`: `build/runtime_smoke/GKYJ01-shifted-main.dol`, SHA256
  `C761F319311497AE875476B08D35E29CD363F0EAE1C051F89C3797F95E2D1506`
- `GKYP01`: `build/runtime_smoke/GKYP01-shifted-main.dol`, SHA256
  `1C6BFBB78F06FE957F359A294F8B271F3A8B4681BA8D06DA01281D23A189756C`

## Headless Media Dump Probe

On July 10, 2026 a follow-up attempt checked whether Dolphin batch mode could
produce stronger visual/audio evidence without Windows window capture. The
first attempt used the wrong command-line config prefixes (`Main`/`GFX`), then
the source config map showed that the correct prefixes are `Dolphin` and
`Graphics`.

With corrected prefixes, `GKYE01` normal DOL was run with D3D, frame dumping,
and audio dumping:

```powershell
& "E:\GPT5\Twitchy-Dolphin\dolphin\Binary\x64\Dolphin.exe" `
  -u "E:\GPT5\KAR-5.5\kar-decomp\build\runtime_smoke\GKYE01-normal-media-d3d-v2-user" `
  -b -e "E:\GPT5\KAR-5.5\kar-decomp\build\GKYE01\main.dol" `
  -v D3D -a HLE `
  -C "Dolphin.General.DumpPath=E:\GPT5\KAR-5.5\kar-decomp\build\runtime_smoke\GKYE01-normal-media-d3d-v2-dump" `
  -C Dolphin.Movie.DumpFrames=True `
  -C Dolphin.Movie.DumpFramesSilent=True `
  -C Graphics.Settings.DumpFramesAsImages=True `
  -C Dolphin.DSP.DumpAudio=True `
  -C Dolphin.DSP.DumpAudioSilent=True
```

That run stayed alive for 45 seconds and produced two WAV files, but both were
silent (`rms = 0`, `peak = 0`) and no frame PNGs were produced. A second D3D
run with `Graphics.Settings.DumpXFBTarget=True`,
`Graphics.Settings.DumpEFBTarget=True`, and texture dumping stayed alive for 60
seconds and produced D3D shader-cache files, but no frame, XFB, EFB, texture,
or other render-image artifacts. This path is parked; use manual Dolphin visual
testing or repaired Windows app capture for title/menu, gameplay, input, audio,
and render proof.

## Window Capture Probe

On July 10, 2026 a PowerShell `PrintWindow` fallback successfully captured
Dolphin Qt windows without the Computer Use plugin. First-run analytics prompts
must be pre-seeded away in the isolated user folder:

```ini
[Analytics]
Enabled = False
PermissionAsked = True
[Interface]
ConfirmStop = False
```

Findings:

- Bare `build/GKYE01/main.dol` with D3D produced a Dolphin warning dialog:
  `Invalid read from 0x00000008, PC = ... crashed on real hardware.`
  The render window remained black. Artifacts:
  `build/runtime_smoke/window_capture/GKYE01-normal-warning-dialog-printwindow.png`,
  `build/runtime_smoke/window_capture/GKYE01-normal-render-printwindow.png`, and
  `build/runtime_smoke/window_capture/GKYE01-normal-printwindow.result.txt`.
- `orig/GKYE01/sys/main.dol` has the same SHA1 as `build/GKYE01/main.dol`
  (`977533BB96E6A16E127946396489BE1B4164AC42`) but, when launched from the
  extracted disc context, reached the save-data prompt with no warning. Artifact:
  `build/runtime_smoke/window_capture/GKYE01-orig-normal-render-printwindow.png`.
- The corrected extracted-disc-context harness lives under
  `build/runtime_smoke/disc_layout_exactname/<GAMEID>` for exact DOLs and
  `build/runtime_smoke/disc_layout_shifted/<GAMEID>` for shifted DOLs. Each
  layout copies the matching `orig/<GAMEID>/sys` metadata, overwrites
  `sys/main.dol` with the DOL under test, and points `files` at the matching
  extracted file tree. The earlier failed temp harness used a literal wildcard
  copy and did not copy all support `sys` files.
- Exact rebuilt DOLs for `GKYE01`, `GKYJ01`, and `GKYP01` reached their first
  regional prompt with no warning and nonblank captures. Artifacts:
  `build/runtime_smoke/window_capture/GKYE01-normal-fixedlayout-attached-render.png`,
  `build/runtime_smoke/window_capture/GKYJ01-normal-fixedlayout-attached-render.png`,
  `build/runtime_smoke/window_capture/GKYP01-normal-fixedlayout-attached-render.png`,
  plus the matching `*-normal-fixedlayout-attached.result.txt` files.
- Shifted DOLs for `GKYE01`, `GKYJ01`, and `GKYP01` also reached their first
  regional prompt with no warning and nonblank captures. Artifacts:
  `build/runtime_smoke/window_capture/GKYE01-shifted-fixedlayout-render.png`,
  `build/runtime_smoke/window_capture/GKYJ01-shifted-fixedlayout-render.png`,
  `build/runtime_smoke/window_capture/GKYP01-shifted-fixedlayout-render.png`,
  plus the matching `*-shifted-fixedlayout.result.txt` files.

Conclusion: the previous null-video probes are still useful no-immediate-exit
evidence, but visual smoke must use an extracted-disc-context harness. Do not
diagnose a bare-DOL invalid-read panic as a split regression until the same DOL
has been tested as `sys/main.dol` with the matching extracted `sys` metadata and
`files` tree. The extracted-context first-prompt check is still not a full
runtime pass: title/menu progression, race start, input, and audio remain
pending until a manual or automated interaction path drives past the first
prompt.

## Interactive Race Probe

On July 11, 2026 a temporary PowerShell interaction probe under
`build/runtime_smoke/run_interaction_probe.ps1` drove the USA exact and shifted
extracted-disc-context harnesses with keyboard scancodes through the configured
GameCube pad mapping (`A=X`, `B=Z`, `Start=RETURN`, main stick on arrows).
Plain virtual-key input and too-early prompts were insufficient; waiting for the
first prompt and sending scancode key events proved that input reached Dolphin.

`GKYE01` normal and shifted both followed this path:

1. Create a new save file in the isolated Dolphin user folder.
2. Reach the title screen.
3. Enter the main mode menu.
4. Enter Air Ride `Start Game`.
5. Join player entry as P1 with Warpstar.
6. Start a race and remain in coherent in-race rendering for roughly 18 seconds.

Normal artifacts:

- `build/runtime_smoke/window_capture/GKYE01-normal-raceprobe1.result.txt`
- `build/runtime_smoke/window_capture/GKYE01-normal-raceprobe1-04-A_title.png`
- `build/runtime_smoke/window_capture/GKYE01-normal-raceprobe1-05-A_menu.png`
- `build/runtime_smoke/window_capture/GKYE01-normal-raceprobe1-14-Start_ready.png`
- `build/runtime_smoke/window_capture/GKYE01-normal-raceprobe1-15-A_race_start.png`

Shifted artifacts:

- `build/runtime_smoke/window_capture/GKYE01-shifted-raceprobe1.result.txt`
- `build/runtime_smoke/window_capture/GKYE01-shifted-raceprobe1-04-A_title.png`
- `build/runtime_smoke/window_capture/GKYE01-shifted-raceprobe1-05-A_menu.png`
- `build/runtime_smoke/window_capture/GKYE01-shifted-raceprobe1-14-Start_ready.png`
- `build/runtime_smoke/window_capture/GKYE01-shifted-raceprobe1-15-A_race_start.png`

Audio evidence came from Dolphin's DSP dump. The DTK dump remained silent in
both runs, but the DSP dump was non-silent:

- Normal DSP WAV: `rms = 3166`, `peak = 32768`.
- Shifted DSP WAV: `rms = 3220`, `peak = 32768`.

This proves title/menu progression, race start, input delivery, non-silent DSP
audio, and an 18-second gameplay render sample for `GKYE01` normal and shifted.
It does not yet satisfy the 60-second gameplay render step. `GKYJ01` and
`GKYP01` still need the same interaction path, with PAL's video-mode prompt
handled explicitly before the save/title flow.

## Smoke Steps

Run these checks for each version and for each layout being tested:

1. Boot the DOL and watch for an immediate crash, black screen, or Dolphin error.
2. Reach the title/menu without hangs or corrupted obvious UI.
3. Start one Air Ride race or the closest available short gameplay path.
4. Confirm input works in menu and gameplay.
5. Confirm audio starts and does not immediately loop, silence, or distort.
6. Confirm rendering remains coherent for at least 60 seconds in gameplay.
7. Exit cleanly or stop emulation without a hang.

## Result Matrix

| Version | Layout | DOL path | Boot | Title/menu | Race start | Input | Audio | Render | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `GKYE01` | normal | `build/runtime_smoke/disc_layout_exactname/GKYE01/sys/main.dol` | D3D race OK | title/menu OK | race OK | scancode GCPad OK | DSP non-silent | gameplay 18s OK | No warning; see `build/runtime_smoke/window_capture/GKYE01-normal-raceprobe1.result.txt`, final capture `GKYE01-normal-raceprobe1-15-A_race_start.png`, DSP `rms=3166`, `peak=32768`. |
| `GKYJ01` | normal | `build/runtime_smoke/disc_layout_exactname/GKYJ01/sys/main.dol` | D3D prompt OK | pending after first prompt | pending | pending | pending | prompt nonblank | No warning; see `build/runtime_smoke/window_capture/GKYJ01-normal-fixedlayout-attached.result.txt` and `*-render.png`. |
| `GKYP01` | normal | `build/runtime_smoke/disc_layout_exactname/GKYP01/sys/main.dol` | D3D prompt OK | pending after first prompt | pending | pending | pending | prompt nonblank | No warning; see `build/runtime_smoke/window_capture/GKYP01-normal-fixedlayout-attached.result.txt` and `*-render.png`. |
| `GKYE01` | shifted | `build/runtime_smoke/disc_layout_shifted/GKYE01/sys/main.dol` | D3D race OK | title/menu OK | race OK | scancode GCPad OK | DSP non-silent | gameplay 18s OK | No warning; see `build/runtime_smoke/window_capture/GKYE01-shifted-raceprobe1.result.txt`, final capture `GKYE01-shifted-raceprobe1-15-A_race_start.png`, DSP `rms=3220`, `peak=32768`. |
| `GKYJ01` | shifted | `build/runtime_smoke/disc_layout_shifted/GKYJ01/sys/main.dol` | D3D prompt OK | pending after first prompt | pending | pending | pending | prompt nonblank | No warning; see `build/runtime_smoke/window_capture/GKYJ01-shifted-fixedlayout.result.txt` and `*-render.png`. |
| `GKYP01` | shifted | `build/runtime_smoke/disc_layout_shifted/GKYP01/sys/main.dol` | D3D prompt OK | pending after first prompt | pending | pending | pending | prompt nonblank | No warning; see `build/runtime_smoke/window_capture/GKYP01-shifted-fixedlayout.result.txt` and `*-render.png`. |

## Failure Capture

For every failure, add or update a row in `docs/project_backlog.md` with:

- Version and layout tested.
- Exact build and launch commands.
- DOL path and how it was produced.
- Last successful screen/action.
- Visible symptom and whether it reproduces.
- Any Dolphin log, screenshot, or minimal reproduction note available.

If a normal DOL passes but the shifted DOL fails, treat split ownership as the
primary suspect. Tighten the owning split range or symbol label before trying
support assembly.
