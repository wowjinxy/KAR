#!/usr/bin/env python3
"""Build and validate the experimental KAR Wii-mode compatibility loader."""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import shutil
import struct
import subprocess
import sys
from pathlib import Path
from typing import Dict, List, Sequence


ROOT = Path(__file__).resolve().parent.parent
LOADER_DIR = ROOT / "tools" / "kar_wii_loader"
LOADER_SOURCE = LOADER_DIR / "loader.c"
LOADER_LCF = LOADER_DIR / "loader.lcf"
LOADER_MIN = 0x93000000
LOADER_MAX = 0x933D0000
EXECUTABLE_SUFFIX = ".exe" if sys.platform == "win32" else ""

SYMBOL_MACROS = {
    "ARStartDMA": "KAR_ADDR_AR_START_DMA",
    "ARInit": "KAR_ADDR_AR_INIT",
    "__AR_Callback": "KAR_ADDR_AR_CALLBACK",
    "__AR_Size": "KAR_ADDR_AR_SIZE",
    "__AR_InternalSize": "KAR_ADDR_AR_INTERNAL_SIZE",
    "__AR_ExpansionSize": "KAR_ADDR_AR_EXPANSION_SIZE",
    "__AR_StackPointer": "KAR_ADDR_AR_STACK_POINTER",
    "__AR_FreeBlocks": "KAR_ADDR_AR_FREE_BLOCKS",
    "__AR_BlockLength": "KAR_ADDR_AR_BLOCK_LENGTH",
    "__AR_init_flag": "KAR_ADDR_AR_INIT_FLAG",
    "OSCreateAlarm": "KAR_ADDR_OS_CREATE_ALARM",
    "OSSetAlarm": "KAR_ADDR_OS_SET_ALARM",
    "OSDisableInterrupts": "KAR_ADDR_OS_DISABLE_INTERRUPTS",
    "OSRestoreInterrupts": "KAR_ADDR_OS_RESTORE_INTERRUPTS",
}

VERSIONS = {
    "GKYE01": {
        "lbmemory_aram_limit": 0x80058314,
        "gx_tlut_clear_bits": 0x803CDE58,
        "original_dol_sha1": "977533bb96e6a16e127946396489be1b4164ac42",
    },
    "GKYJ01": {
        "lbmemory_aram_limit": 0x80057A3C,
        "gx_tlut_clear_bits": 0x803C8D78,
        "original_dol_sha1": "e901b9912af1b622c1f6d16fab6efe6cf505f108",
    },
    "GKYP01": {
        "lbmemory_aram_limit": 0x800589B4,
        "gx_tlut_clear_bits": 0x803D0318,
        "original_dol_sha1": "14e43ef2e3d971bbb6aae596a175ac485ff242a8",
    },
}

SYMBOL_RE = re.compile(
    r"^(?P<name>[A-Za-z_][A-Za-z0-9_]*)\s*=\s*[^:;]+:" r"(?P<address>0x[0-9A-Fa-f]+);"
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--version",
        choices=VERSIONS,
        default="GKYE01",
        help="KAR disc revision to target (default: GKYE01)",
    )
    parser.add_argument(
        "--compiler",
        type=Path,
        default=ROOT / "build" / "compilers" / "Wii" / "1.0" / "mwcceppc.exe",
        help="path to the Wii CodeWarrior compiler driver",
    )
    parser.add_argument(
        "--dtk",
        type=Path,
        default=ROOT / "build" / "tools" / f"dtk{EXECUTABLE_SUFFIX}",
        help="path to decomp-toolkit",
    )
    parser.add_argument(
        "--wrapper",
        type=Path,
        help="optional wibo/wine executable used to run CodeWarrior",
    )
    parser.add_argument(
        "--output-dir",
        type=Path,
        help=(
            "output directory (default: build/<version>/wii-loader, or "
            "wii-loader-debug with --dolphin-osreport)"
        ),
    )
    parser.add_argument(
        "--dolphin-osreport",
        action="store_true",
        help="set the development console type so KAR OSReport reaches Dolphin",
    )
    return parser.parse_args()


def require_file(path: Path, description: str) -> Path:
    path = path.resolve()
    if not path.is_file():
        raise SystemExit(f"{description} not found: {path}")
    return path


def require_executable(path: Path, description: str) -> str:
    if path.is_file():
        return str(path.resolve())
    resolved = shutil.which(str(path))
    if resolved is None:
        raise SystemExit(f"{description} not found: {path}")
    return resolved


def read_symbols(version: str) -> Dict[str, int]:
    path = ROOT / "config" / version / "symbols.txt"
    symbols: Dict[str, int] = {}
    for line in path.read_text(encoding="utf-8").splitlines():
        match = SYMBOL_RE.match(line)
        if match:
            symbols[match.group("name")] = int(match.group("address"), 16)
    missing = [name for name in SYMBOL_MACROS if name not in symbols]
    if missing:
        raise SystemExit(
            f"{path} is missing required symbols: {', '.join(sorted(missing))}"
        )
    return symbols


def run(command: Sequence[str], cwd: Path = ROOT) -> None:
    print("+", subprocess.list2cmdline(list(command)))
    subprocess.run(list(command), cwd=cwd, check=True)


def read_u32(data: bytes, offset: int) -> int:
    return struct.unpack_from(">I", data, offset)[0]


def validate_dol(path: Path) -> Dict[str, object]:
    data = path.read_bytes()
    if len(data) < 0x100:
        raise SystemExit(f"DOL is too small to contain a header: {path}")

    text_offsets = [read_u32(data, 0x00 + index * 4) for index in range(7)]
    data_offsets = [read_u32(data, 0x1C + index * 4) for index in range(11)]
    text_addresses = [read_u32(data, 0x48 + index * 4) for index in range(7)]
    data_addresses = [read_u32(data, 0x64 + index * 4) for index in range(11)]
    text_sizes = [read_u32(data, 0x90 + index * 4) for index in range(7)]
    data_sizes = [read_u32(data, 0xAC + index * 4) for index in range(11)]
    bss_address = read_u32(data, 0xD8)
    bss_size = read_u32(data, 0xDC)
    entry = read_u32(data, 0xE0)

    sections: List[Dict[str, object]] = []
    hid4_sentinel_found = False
    for kind, offsets, addresses, sizes in (
        ("text", text_offsets, text_addresses, text_sizes),
        ("data", data_offsets, data_addresses, data_sizes),
    ):
        for index, (offset, address, size) in enumerate(zip(offsets, addresses, sizes)):
            if size == 0:
                continue
            if offset < 0x100 or offset + size > len(data):
                raise SystemExit(f"{kind}[{index}] lies outside the DOL file")
            if address < LOADER_MIN or address + size > LOADER_MAX:
                raise SystemExit(
                    f"{kind}[{index}] lies outside the loader reservation: "
                    f"0x{address:08X}-0x{address + size:08X}"
                )
            sections.append(
                {
                    "name": f"{kind}[{index}]",
                    "address": f"0x{address:08X}",
                    "size": size,
                }
            )
            if kind == "text" and b"\x7C\x73\xFB\xA6" in data[offset : offset + size]:
                hid4_sentinel_found = True

    if bss_size:
        if bss_address < LOADER_MIN or bss_address + bss_size > LOADER_MAX:
            raise SystemExit(
                "BSS lies outside the loader reservation: "
                f"0x{bss_address:08X}-0x{bss_address + bss_size:08X}"
            )
        sections.append(
            {"name": "bss", "address": f"0x{bss_address:08X}", "size": bss_size}
        )

    text_ranges = [
        (address, address + size)
        for address, size in zip(text_addresses, text_sizes)
        if size
    ]
    if not any(start <= entry < end for start, end in text_ranges):
        raise SystemExit(f"entry point 0x{entry:08X} is not in a text section")

    if not hid4_sentinel_found:
        raise SystemExit("Dolphin Wii-mode HID4 sentinel is missing from the DOL")

    return {"entry": f"0x{entry:08X}", "sections": sections}


def main() -> None:
    args = parse_args()
    version = args.version
    region = VERSIONS[version]
    symbols = read_symbols(version)
    compiler = require_file(args.compiler, "Wii CodeWarrior compiler")
    dtk = require_file(args.dtk, "decomp-toolkit")
    wrapper_arg = args.wrapper
    if wrapper_arg is None and sys.platform != "win32":
        bundled_wibo = ROOT / "build" / "tools" / "wibo"
        wrapper_arg = bundled_wibo if bundled_wibo.is_file() else Path("wine")
    wrapper = (
        require_executable(wrapper_arg, "CodeWarrior wrapper") if wrapper_arg else None
    )

    output_dir = (
        args.output_dir.resolve()
        if args.output_dir
        else ROOT
        / "build"
        / version
        / ("wii-loader-debug" if args.dolphin_osreport else "wii-loader")
    )
    output_dir.mkdir(parents=True, exist_ok=True)
    elf_path = output_dir / "kar-wii-loader.elf"
    dol_path = output_dir / "boot.dol"
    manifest_path = output_dir / "manifest.json"

    macros = {
        SYMBOL_MACROS[name]: address
        for name, address in symbols.items()
        if name in SYMBOL_MACROS
    }
    macros["KAR_ADDR_LBMEMORY_ARAM_LIMIT"] = int(region["lbmemory_aram_limit"])
    macros["KAR_ADDR_GX_TLUT_CLEAR_BITS"] = int(region["gx_tlut_clear_bits"])
    for index, character in enumerate(version.encode("ascii")):
        macros[f"KAR_DISC_ID_{index}"] = character
    macros["KAR_DISC_NUMBER"] = 0
    macros["KAR_DISC_REVISION"] = 0
    macros["KAR_ENABLE_DOLPHIN_OSREPORT"] = int(args.dolphin_osreport)

    command = []
    if wrapper:
        command.append(wrapper)
    command.extend(
        [
            str(compiler),
            "-lcf",
            str(LOADER_LCF),
            "-Cpp_exceptions",
            "off",
            "-lang",
            "c99",
            "-m",
            "Start",
            "-O4,p",
            "-sdata",
            "0",
            "-sdata2",
            "0",
            "-use_lmw_stmw",
            "on",
            "-proc",
            "gekko",
            "-fp",
            "hard",
            "-i",
            str(ROOT / "include"),
        ]
    )
    command.extend(f"-D{name}=0x{value:X}" for name, value in sorted(macros.items()))
    command.extend([str(LOADER_SOURCE), "-o", str(elf_path)])

    run(command)
    run([str(dtk), "elf2dol", str(elf_path), str(dol_path)])
    dol_info = validate_dol(dol_path)

    manifest = {
        "format_version": 1,
        "game_version": version,
        "reference_original_dol_sha1": region["original_dol_sha1"],
        "compiler": str(compiler),
        "compiler_sha256": hashlib.sha256(compiler.read_bytes()).hexdigest(),
        "dolphin_osreport": args.dolphin_osreport,
        "addresses": {name: f"0x{value:08X}" for name, value in sorted(macros.items())},
        "memory": {
            "emulated_aram": "0x90004000-0x91004000",
            "mod_heap": "0x91004000-0x91EFF000",
            "api_page": "0x91EFF000-0x91F00000",
            "loader_stack": "0x91F00000-0x92000000",
            "loader": "0x93000000-0x933D0000",
        },
        "dol": {
            **dol_info,
            "size": dol_path.stat().st_size,
            "sha256": hashlib.sha256(dol_path.read_bytes()).hexdigest(),
        },
    }
    manifest_path.write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")

    print(f"Built {dol_path}")
    print(f"Manifest {manifest_path}")


if __name__ == "__main__":
    try:
        main()
    except subprocess.CalledProcessError as error:
        raise SystemExit(error.returncode) from error
