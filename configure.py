#!/usr/bin/env python3

###
# Generates build files for the project.
# This file also includes the project configuration,
# such as compiler flags and the object matching status.
#
# Usage:
#   python3 configure.py
#   ninja
#
# Append --help to see available options.
###

import argparse
import sys
from pathlib import Path
from typing import Any, Dict, List

from tools.project import (
    Object,
    ProgressCategory,
    ProjectConfig,
    calculate_progress,
    generate_build,
    is_windows,
)

# Game versions
DEFAULT_VERSION = 0
VERSIONS = [
    "GKYE01",  # 0: USA
    "GKYJ01",  # 1: Japan
    "GKYP01",  # 2: Europe
]

parser = argparse.ArgumentParser()
parser.add_argument(
    "mode",
    choices=["configure", "progress"],
    default="configure",
    help="script mode (default: configure)",
    nargs="?",
)
parser.add_argument(
    "-v",
    "--version",
    choices=VERSIONS,
    type=str.upper,
    default=VERSIONS[DEFAULT_VERSION],
    help="version to build",
)
parser.add_argument(
    "--build-dir",
    metavar="DIR",
    type=Path,
    default=Path("build"),
    help="base build directory (default: build)",
)
parser.add_argument(
    "--binutils",
    metavar="BINARY",
    type=Path,
    help="path to binutils (optional)",
)
parser.add_argument(
    "--compilers",
    metavar="DIR",
    type=Path,
    help="path to compilers (optional)",
)
parser.add_argument(
    "--map",
    action="store_true",
    help="generate map file(s)",
)
parser.add_argument(
    "--debug",
    action="store_true",
    help="build with debug info (non-matching)",
)
if not is_windows():
    parser.add_argument(
        "--wrapper",
        metavar="BINARY",
        type=Path,
        help="path to wibo or wine (optional)",
    )
parser.add_argument(
    "--dtk",
    metavar="BINARY | DIR",
    type=Path,
    help="path to decomp-toolkit binary or source (optional)",
)
parser.add_argument(
    "--objdiff",
    metavar="BINARY | DIR",
    type=Path,
    help="path to objdiff-cli binary or source (optional)",
)
parser.add_argument(
    "--sjiswrap",
    metavar="EXE",
    type=Path,
    help="path to sjiswrap.exe (optional)",
)
parser.add_argument(
    "--ninja",
    metavar="BINARY",
    type=Path,
    help="path to ninja binary (optional)",
)
parser.add_argument(
    "--verbose",
    action="store_true",
    help="print verbose output",
)
parser.add_argument(
    "--non-matching",
    dest="non_matching",
    action="store_true",
    help="builds equivalent (but non-matching) or modded objects",
)
parser.add_argument(
    "--warn",
    dest="warn",
    type=str,
    choices=["all", "off", "error"],
    help="how to handle warnings",
)
parser.add_argument(
    "--no-progress",
    dest="progress",
    action="store_false",
    help="disable progress calculation",
)
args = parser.parse_args()

config = ProjectConfig()
config.version = str(args.version)
version_num = VERSIONS.index(config.version)

# Apply arguments
config.build_dir = args.build_dir
config.dtk_path = args.dtk
config.objdiff_path = args.objdiff
config.binutils_path = args.binutils
config.compilers_path = args.compilers
config.generate_map = args.map
config.non_matching = args.non_matching
config.sjiswrap_path = args.sjiswrap
config.ninja_path = args.ninja
config.progress = args.progress
config.progress_use_fancy = True
config.progress_code_fancy_frac = 360
config.progress_code_fancy_item = "checkboxes"
config.progress_code_fancy_extra_files = [
    "assets/kar/db/dbscreenshot_icon_rgb5a3.bin",
    "assets/kar/debug/debugconsole_font_i4_8x14.bin",
    "assets/kar/hsd/base/sislib_romfont_glyphs_i4_32x32.bin",
    "assets/kar/lb/lbnet/upnp_rootdesc.xml",
]
if not is_windows():
    config.wrapper = args.wrapper
# Don't build asm unless we're --non-matching
if not config.non_matching:
    config.asm_dir = None

# Tool versions
config.binutils_tag = "2.42-2"
config.compilers_tag = "20251118"
config.dtk_tag = "v1.8.3"
config.objdiff_tag = "v3.6.1"
config.sjiswrap_tag = "v1.2.2"
config.wibo_tag = "1.0.3"

# Project
config.config_path = Path("config") / config.version / "config.yml"
config.check_sha_path = Path("config") / config.version / "build.sha1"
config.asflags = [
    "-mgekko",
    "--strip-local-absolute",
    "-I include",
    f"-I build/{config.version}/include",
    f"--defsym BUILD_VERSION={version_num}",
]
config.ldflags = [
    "-fp hard",
    "-nodefaults",
]
if args.debug:
    config.ldflags.append("-g")  # Or -gdwarf-2 for Wii linkers
if args.map:
    config.ldflags.append("-mapunused")
    # config.ldflags.append("-listclosure") # For Wii linkers

# Use for any additional files that should cause a re-configure when modified
config.reconfig_deps = []

# Optional numeric ID for decomp.me preset
# Can be overridden in libraries or objects
config.scratch_preset_id = None

# Compiler: CodeWarrior for GameCube 2.4.2 build 81 (GC MW 1.3.2).
# The first group is the observed KAR game-code flag set.
DOLPHIN_SDK_COMPILER_VERSION = "GC/1.0"

cflags_base = [
    "-O4,p",
    "-nodefaults",
    "-fp hard",
    "-Cpp_exceptions off",
    "-enum int",
    "-fp_contract on",
    "-inline auto",
    # Project support flags.
    "-proc gekko",
    "-align powerpc",
    "-nosyspath",
    "-multibyte",  # For Wii compilers, replace with `-enc SJIS`
    "-i include",
    f"-i build/{config.version}/include",
    f"-DBUILD_VERSION={version_num}",
    f"-DVERSION_{config.version}",
]

# Debug flags
if args.debug:
    # Or -sym dwarf-2 for Wii compilers
    cflags_base.extend(["-sym on", "-DDEBUG=1"])
else:
    cflags_base.append("-DNDEBUG=1")

# Warning flags
if args.warn == "all":
    cflags_base.append("-W all")
elif args.warn == "off":
    cflags_base.append("-W off")
elif args.warn == "error":
    cflags_base.append("-W error")

# Flags used by doldecomp/kar for the source-backed SysDolphin and SDK files.
# Keep this separate from the broader game-code baseline: upstream's src files
# are trusted, but Dolphin SDK objects were not built with the same compiler as
# the KAR game objects.
cflags_doldecomp_src = [
    "-cwd source",
    "-Cpp_exceptions off",
    "-proc gekko",
    "-fp hard",
    "-O4,p",
    "-nodefaults",
    "-I-",
    "-i include",
    f"-i build/{config.version}/include",
    "-inline all",
    "-nosyspath",
    "-multibyte",
    f"-DBUILD_VERSION={version_num}",
    f"-DVERSION_{config.version}",
]

if args.debug:
    cflags_doldecomp_src.extend(["-sym on", "-DDEBUG=1"])
else:
    cflags_doldecomp_src.append("-DNDEBUG=1")

if args.warn == "all":
    cflags_doldecomp_src.append("-W all")
elif args.warn == "off":
    cflags_doldecomp_src.append("-W off")
elif args.warn == "error":
    cflags_doldecomp_src.append("-W error")

cflags_dolphin_sdk = list(cflags_doldecomp_src)

# Metrowerks library flags
cflags_runtime = [
    *cflags_base,
    "-use_lmw_stmw on",
    "-str reuse,pool,readonly",
    "-gccinc",
    "-common off",
    "-inline auto",
]

# REL flags
cflags_rel = [
    *cflags_base,
    "-sdata 0",
    "-sdata2 0",
]

config.linker_version = "GC/1.3.2"


# Helper function for Dolphin libraries
def DolphinLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": DOLPHIN_SDK_COMPILER_VERSION,
        "cflags": cflags_dolphin_sdk,
        "progress_category": "sdk",
        "objects": objects,
    }


# Helper function for REL script objects
def Rel(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.3.2",
        "cflags": cflags_rel,
        "progress_category": "game",
        "objects": objects,
    }


Matching = True                   # Object matches and should be linked
NonMatching = False               # Object does not match and should not be linked
Equivalent = config.non_matching  # Object should be linked when configured with --non-matching


# Object is only matching for specific versions
def MatchingFor(*versions):
    return config.version in versions


KAR_SOURCE_EXACT = {
    "textlib.c": "if",
    "camera.c": "cm",
    "ground.c": "gr",
    "effect.c": "ef",
    "OSThread.c": "os",
    "displayfunc.c": "hsd/base",
    "initialize.c": "hsd/base",
    "objalloc.c": "hsd/base",
    "memory.c": "hsd/base",
    "shadow.c": "hsd/base",
    "bytecode.c": "hsd/base",
    "texpdag.c": "hsd/base",
    "gobjproc.c": "hsd/base",
    "gobjplink.c": "hsd/base",
    "gobjgxlink.c": "hsd/base",
    "gobjobject.c": "hsd/base",
    "gobjuserdata.c": "hsd/base",
    "particle.c": "hsd/particle",
    "psinterpret.c": "hsd/particle",
    "generator.c": "hsd/particle",
    "psdisp.c": "hsd/particle",
    "pslist.c": "hsd/particle",
    "debugconsole_main.c": "debug",
    "axdriver.c": "audio_ax",
    "devcom.c": "audio_ax",
    "dvdsche.c": "audio_ax",
    "sislib.c": "hsd/base",
    "gcpmemcard.c": "card",
    "HVQM4PlayerDx.c": "hvqm",
    "IPSocket.c": "network",
    "IPIgmp.c": "network",
}

KAR_SOURCE_PREFIXES = [
    ("a2d_", "a2d"),
    ("fl_", "fl"),
    ("gm", "gm"),
    ("lb", "lb"),
    ("db", "db"),
    ("cm", "cm"),
    ("gr", "gr"),
    ("if", "if"),
    ("mn", "mn"),
    ("cl", "cl"),
    ("vc", "vc"),
    ("em", "em"),
    ("wn", "wn"),
    ("pl", "pl"),
    ("ef", "ef"),
    ("mp", "mp"),
    ("it", "it"),
    ("cp", "cp"),
]

DOLDECOMP_SYSDOLPHIN_SOURCE_OBJECTS = {
    "aobj.c",
    "archive.c",
    "class.c",
    "displayfunc.c",
    "dobj.c",
    "fobj.c",
    "fog.c",
    "gobjobject.c",
    "gobjgxlink.c",
    "gobjplink.c",
    "gobjproc.c",
    "gobjuserdata.c",
    "id.c",
    "initialize.c",
    "list.c",
    "lobj.c",
    "memory.c",
    "mobj.c",
    "objalloc.c",
    "object.c",
    "pobj.c",
    "robj.c",
    "shadow.c",
    "util.c",
    "wobj.c",
}

DOLPHIN_SDK_SOURCE_OBJECTS = {
    "OSThread.c",
    "dolphin_sdk.c",
    "dolphin_sdk2.c",
}


def kar_source_path(name: str) -> str:
    path = Path(name)
    if len(path.parts) > 1:
        return str(Path("kar") / path).replace("\\", "/")

    subdir = KAR_SOURCE_EXACT.get(name)
    if subdir is None:
        stem = path.stem
        subdir = next(
            (
                directory
                for prefix, directory in KAR_SOURCE_PREFIXES
                if stem.startswith(prefix)
            ),
            "misc",
        )
    return str(Path("kar") / subdir / name).replace("\\", "/")


config.warn_missing_config = True
config.warn_missing_source = False
kar_objects = [
    Object(NonMatching, "gmmain.c"),
    Object(NonMatching, "gmglobal.c"),
    Object(NonMatching, "gmautodemo.c"),
    Object(NonMatching, "gmracecommon.c"),
    Object(NonMatching, "gmracenormal.c"),
    Object(NonMatching, "gmdialogue.c"),
    Object(NonMatching, "gmdialoguestatus.c"),
    Object(NonMatching, "gmspecialmovie.c"),
    Object(Matching, "gmclearchecker.c", extra_cflags=["-str reuse"]),
    Object(NonMatching, "gmclearchecker_8004a648.c", extra_cflags=["-str reuse"]),
    Object(Matching, "gmviconfigure.c"),
    Object(NonMatching, "gmlanmenu.c"),
    Object(NonMatching, "lbairride.c"),
    Object(Matching, "lblight.c"),
    Object(NonMatching, "lbmemory.c"),
    Object(NonMatching, "lbheap.c"),
    Object(NonMatching, "lbfile.c"),
    Object(NonMatching, "lbarchive.c"),
    Object(NonMatching, "lbaudio.c"),
    Object(NonMatching, "lbvector.c"),
    Object(NonMatching, "lbfade.c"),
    Object(NonMatching, "lbcamera.c"),
    Object(NonMatching, "lbcolanim.c"),
    Object(NonMatching, "lbspline.c"),
    Object(NonMatching, "lbkdtree.c"),
    Object(NonMatching, "lbkdcoll.c"),
    Object(NonMatching, "lbhvqm.c"),
    Object(NonMatching, "lbarealight.c"),
    Object(NonMatching, "lbarealightuser.c"),
    Object(
        Matching,
        "lbarealightzone.c",
        extra_cflags=["-pooldata off", "-sdata 0"],
    ),
    Object(NonMatching, "lbshadow.c"),
    Object(NonMatching, "lbnet.c"),
    Object(NonMatching, "dbposition.c"),
    Object(NonMatching, "dbscreenshot.c"),
    Object(NonMatching, "dbcamera.c"),
    Object(NonMatching, "dbmapspline.c"),
    Object(NonMatching, "dbmapzone.c"),
    Object(NonMatching, "dbmapmpcoll.c"),
    Object(NonMatching, "dbmapdispbbox.c"),
    Object(NonMatching, "dbmapgravity.c"),
    Object(NonMatching, "textlib.c"),
    Object(NonMatching, "smsoundtest.c"),
    Object(NonMatching, "kar_objalloc.c"),
    Object(NonMatching, "camera.c"),
    Object(NonMatching, "cmreplay.c"),
    Object(NonMatching, "cmanimation.c"),
    Object(NonMatching, "ground.c"),
    Object(NonMatching, "grdata.c"),
    Object(NonMatching, "grlib2.c"),
    Object(NonMatching, "grcoll.c"),
    Object(NonMatching, "grparts.c"),
    Object(NonMatching, "grcommon.c"),
    Object(NonMatching, "granim.c"),
    Object(NonMatching, "grrough.c"),
    Object(NonMatching, "grzone.c"),
    Object(NonMatching, "grzonecover.c"),
    Object(NonMatching, "grkdtree.c"),
    Object(NonMatching, "grcoursespline.c"),
    Object(NonMatching, "grrangespline.c"),
    Object(NonMatching, "grnullpos.c"),
    Object(NonMatching, "grdispbbox.c"),
    Object(NonMatching, "grgravity.c"),
    Object(NonMatching, "grairflow.c"),
    Object(NonMatching, "grconveyer.c"),
    Object(NonMatching, "grswitch.c"),
    Object(NonMatching, "grrail.c"),
    Object(NonMatching, "graudio.c"),
    Object(NonMatching, "grboxgenerator.c"),
    Object(NonMatching, "greventgenerator.c"),
    Object(Matching, "grglobaldead.c"),
    Object(NonMatching, "grpointstrike.c"),
    Object(NonMatching, "grairglider.c"),
    Object(NonMatching, "gryaku.c"),
    Object(NonMatching, "gryakuanim.c"),
    Object(NonMatching, "gryakueffect.c"),
    Object(Matching, "gryakuaudio.c"),
    Object(NonMatching, "gryakulib.c"),
    Object(NonMatching, "gryakucommon.c"),
    Object(NonMatching, "gryakudownforcezone.c"),
    Object(NonMatching, "gryakucatchzone.c"),
    Object(NonMatching, "gryakurecoveryzone.c"),
    Object(NonMatching, "gryakurotjumphill.c"),
    Object(NonMatching, "gryakuinvisibleball.c"),
    Object(NonMatching, "gryakurisingcube.c"),
    Object(NonMatching, "gryakugondola.c"),
    Object(NonMatching, "gryakucannon.c"),
    Object(NonMatching, "gryakupushoutwall.c"),
    Object(NonMatching, "gryakulighttunnel.c"),
    Object(NonMatching, "gryakupillar.c"),
    Object(NonMatching, "gryakubreakrock.c"),
    Object(NonMatching, "gryakubreakhouse.c"),
    Object(NonMatching, "gryakuanimfloor.c"),
    Object(NonMatching, "gryakubreakcoral.c"),
    Object(NonMatching, "gryakubreakicicle.c"),
    Object(NonMatching, "gryakubreakcommon.c"),
    Object(NonMatching, "gryakulasergate.c"),
    Object(NonMatching, "gryakubreakfloor.c"),
    Object(NonMatching, "gryakubreakfan.c"),
    Object(NonMatching, "gryakubreakcoll.c"),
    Object(NonMatching, "gryakubreakhpcoll.c"),
    Object(NonMatching, "gryakuwhispywoods.c"),
    Object(Matching, "grheat2.c"),
    Object(NonMatching, "grdesert1.c"),
    Object(Matching, "grvalley2.c"),
    Object(Matching, "grmachine2.c"),
    Object(Matching, "grsky2.c"),
    Object(NonMatching, "grice1.c"),
    Object(NonMatching, "grcity1.c"),
    Object(NonMatching, "grcolosseum1.c"),
    Object(NonMatching, "greventrock.c"),
    Object(NonMatching, "greventlighthouse.c"),
    Object(NonMatching, "ifround.c"),
    Object(NonMatching, "mnselrule.c"),
    Object(Matching, "mntitle.c"),
    Object(NonMatching, "mndialoguebg.c"),
    Object(NonMatching, "mnclearchecker.c"),
    Object(Matching, "mnlannumber.c"),
    Object(NonMatching, "mnlandialogue.c"),
    Object(NonMatching, "mnbestrapbg.c"),
    Object(NonMatching, "mnbestrapsicon.c"),
    Object(NonMatching, "clobject.c"),
    Object(NonMatching, "vcgenerator.c"),
    Object(NonMatching, "vcdevice.c"),
    Object(NonMatching, "emanim.c"),
    Object(NonMatching, "emparts.c"),
    Object(NonMatching, "emupdate.c"),
    Object(NonMatching, "emcamera.c"),
    Object(NonMatching, "empass.c"),
    Object(NonMatching, "wnanim.c"),
    Object(NonMatching, "wnparts.c"),
    Object(NonMatching, "wneffect.c"),
    Object(NonMatching, "wnguided.c"),
    Object(NonMatching, "plclearchecker.c"),
    Object(NonMatching, "plclearcheckerlib.c"),
    Object(NonMatching, "pltrick.c"),
    Object(NonMatching, "effect.c"),
    Object(NonMatching, "efcallback.c"),
    Object(NonMatching, "efdata.c"),
    Object(NonMatching, "efrequest.c"),
    Object(NonMatching, "efrequest2.c"),
    Object(NonMatching, "efcontrol.c"),
    Object(NonMatching, "efanime.c"),
    Object(NonMatching, "efargs.c"),
    Object(NonMatching, "mpcoll.c"),
    Object(NonMatching, "mpcollreport.c"),
    Object(NonMatching, "mpresponse.c"),
    Object(NonMatching, "mpzone.c"),
    Object(NonMatching, "mpairflow.c"),
    Object(NonMatching, "itdata.c"),
    Object(NonMatching, "itanim.c"),
    Object(NonMatching, "itparts.c"),
    Object(NonMatching, "cpcmdscript.c"),
    Object(NonMatching, "cpdata.c"),
    Object(NonMatching, "cpmapdata.c"),
    Object(NonMatching, "a2d_game_lib.cpp"),
    Object(NonMatching, "a2d_gamehistory.cpp"),
    Object(NonMatching, "a2d_gamesession.cpp"),
    Object(NonMatching, "a2d_cpu_kirby.cpp"),
    Object(NonMatching, "a2d_kirbyjointanim.cpp"),
    Object(NonMatching, "a2d_lavabomb.cpp"),
    Object(NonMatching, "a2d_grindrail.cpp"),
    Object(NonMatching, "a2d_bg3000.cpp"),
    Object(NonMatching, "a2d_bg4000.cpp"),
    Object(NonMatching, "a2d_bg5000.cpp"),
    Object(NonMatching, "a2d_bg8000.cpp"),
    Object(NonMatching, "a2d_kurakko.cpp"),
    Object(NonMatching, "a2d_game_audio.cpp"),
    Object(NonMatching, "a2d_soundhandle.cpp"),
    Object(NonMatching, "a2d_game_effect.cpp"),
    Object(NonMatching, "a2d_effecthandle.cpp"),
    Object(NonMatching, "a2d_wipeeffect.cpp"),
    Object(NonMatching, "a2d_effect_slideblur.cpp"),
    Object(NonMatching, "a2d_kirbydisp.cpp"),
    Object(NonMatching, "a2d_refract.cpp"),
    Object(NonMatching, "fl_indirectload.cpp"),
    Object(NonMatching, "OSThread.c"),
    Object(NonMatching, "displayfunc.c"),
    Object(NonMatching, "initialize.c"),
    Object(NonMatching, "objalloc.c"),
    Object(NonMatching, "memory.c"),
    Object(NonMatching, "shadow.c"),
    Object(NonMatching, "bytecode.c"),
    Object(NonMatching, "texpdag.c"),
    Object(NonMatching, "gobjproc.c"),
    Object(Matching, "gobjplink.c"),
    Object(Matching, "gobjgxlink.c"),
    Object(Matching, "gobjobject.c"),
    Object(Matching, "gobjuserdata.c"),
    Object(NonMatching, "particle.c"),
    Object(NonMatching, "psinterpret.c"),
    Object(NonMatching, "generator.c"),
    Object(NonMatching, "psdisp.c"),
    Object(NonMatching, "pslist.c"),
    Object(NonMatching, "debugconsole_main.c"),
    Object(NonMatching, "axdriver.c"),
    Object(NonMatching, "devcom.c"),
    Object(NonMatching, "dvdsche.c"),
    Object(NonMatching, "sislib.c"),
    Object(NonMatching, "gcpmemcard.c"),
    Object(NonMatching, "HVQM4PlayerDx.c"),
    Object(NonMatching, "IPSocket.c"),
    Object(NonMatching, "IPIgmp.c"),
]

for obj in kar_objects:
    obj.options["source"] = kar_source_path(obj.name)
    if obj.name in DOLDECOMP_SYSDOLPHIN_SOURCE_OBJECTS:
        obj.options["source"] = str(Path("sysdolphin") / obj.name).replace("\\", "/")
        obj.options["cflags"] = cflags_doldecomp_src
    if obj.name in DOLPHIN_SDK_SOURCE_OBJECTS:
        obj.options["mw_version"] = DOLPHIN_SDK_COMPILER_VERSION
        obj.options["cflags"] = cflags_dolphin_sdk
        obj.options["progress_category"] = "sdk"

config.libs = [
    {
        "lib": "KAR",
        "mw_version": config.linker_version,
        "cflags": cflags_base,
        "progress_category": "game",
        "objects": kar_objects,
    },
    {
        "lib": "Runtime.PPCEABI.H",
        "mw_version": config.linker_version,
        "cflags": cflags_runtime,
        "progress_category": "sdk",  # str | List[str]
        "objects": [
            Object(NonMatching, "runtime.c"),
            Object(NonMatching, "Runtime.PPCEABI.H/global_destructor_chain.c"),
            Object(NonMatching, "runtime_support.c"),
            Object(NonMatching, "Runtime.PPCEABI.H/__init_cpp_exceptions.cpp"),
            Object(NonMatching, "runtime_libc.c"),
            Object(NonMatching, "metrotrk.c"),
            Object(
                NonMatching,
                "dolphin_sdk.c",
                mw_version=DOLPHIN_SDK_COMPILER_VERSION,
                cflags=cflags_dolphin_sdk,
            ),
            Object(
                NonMatching,
                "dolphin_sdk2.c",
                mw_version=DOLPHIN_SDK_COMPILER_VERSION,
                cflags=cflags_dolphin_sdk,
            ),
            Object(NonMatching, "metrotrk_bridge.c"),
            Object(NonMatching, "hsd_runtime.c"),
        ],
    },
]


# Optional callback to adjust link order. This can be used to add, remove, or reorder objects.
# This is called once per module, with the module ID and the current link order.
#
# For example, this adds "dummy.c" to the end of the DOL link order if configured with --non-matching.
# "dummy.c" *must* be configured as a Matching (or Equivalent) object in order to be linked.
def link_order_callback(module_id: int, objects: List[str]) -> List[str]:
    # Don't modify the link order for matching builds
    if not config.non_matching:
        return objects
    if module_id == 0:  # DOL
        return objects + ["dummy.c"]
    return objects


# Uncomment to enable the link order callback.
# config.link_order_callback = link_order_callback


# Optional extra categories for progress tracking
# Adjust as desired for your project
config.progress_categories = [
    ProgressCategory("game", "Game Code"),
    ProgressCategory("sdk", "SDK Code"),
]
config.progress_each_module = args.verbose
# Optional extra arguments to `objdiff-cli report generate`
config.progress_report_args = [
    # Marks relocations as mismatching if the target value is different
    # Default is "functionRelocDiffs=none", which is most lenient
    # "--config functionRelocDiffs=data_value",
]

if args.mode == "configure":
    # Write build.ninja and objdiff.json
    generate_build(config)
elif args.mode == "progress":
    # Print progress information
    calculate_progress(config)
else:
    sys.exit("Unknown mode: " + args.mode)
