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
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, List, Optional, Sequence, Tuple


ROOT = Path(__file__).resolve().parent.parent
LOADER_DIR = ROOT / "tools" / "kar_wii_loader"
LOADER_SOURCE = LOADER_DIR / "loader.c"
LOADER_LCF = LOADER_DIR / "loader.lcf"
LOADER_MIN = 0x93000000
LOADER_MAX = 0x933D0000
TARGET_MIN = 0x80003100
TARGET_MAX = 0x81200000
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
    "__OSMaskInterrupts": "KAR_ADDR_OS_MASK_INTERRUPTS",
    "fn_803C4470": "KAR_ADDR_DVD_READ_ISSUE",
    "Callback": "KAR_ADDR_DVD_CALLBACK",
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


@dataclass(frozen=True)
class DolSection:
    kind: str
    index: int
    offset: int
    address: int
    data: bytes
    source: str

    @property
    def size(self) -> int:
        return len(self.data)

    @property
    def end(self) -> int:
        return self.address + self.size

    @property
    def name(self) -> str:
        return f"{self.source}.{self.kind}[{self.index}]"


@dataclass(frozen=True)
class DolImage:
    path: Path
    data: bytes
    text: Tuple[DolSection, ...]
    data_sections: Tuple[DolSection, ...]
    bss_address: int
    bss_size: int
    entry: int

    @property
    def sections(self) -> Tuple[DolSection, ...]:
        return self.text + self.data_sections


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
            "output directory (default: build/<version>/wii-loader for "
            "standalone mode, wii-loader-merged with --target-dol; append "
            "-debug when --dolphin-osreport is used)"
        ),
    )
    parser.add_argument(
        "--dolphin-osreport",
        action="store_true",
        help="set the development console type so KAR OSReport reaches Dolphin",
    )
    parser.add_argument(
        "--target-dol",
        type=Path,
        help=(
            "preserved exact retail DOL for this region (conventionally "
            "files/orig.dol); merge its sections into boot.dol so the Wii "
            "apploader preloads KAR before entering the compatibility loader; "
            "this is a build input, not a runtime file"
        ),
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


def sha256_file(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        while chunk := stream.read(1024 * 1024):
            digest.update(chunk)
    return digest.hexdigest()


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


def write_u32(data: bytearray, offset: int, value: int) -> None:
    struct.pack_into(">I", data, offset, value)


def align_up(value: int, alignment: int) -> int:
    return (value + alignment - 1) // alignment * alignment


def ranges_overlap(
    first_start: int, first_size: int, second_start: int, second_size: int
) -> bool:
    return (
        first_start < second_start + second_size
        and second_start < first_start + first_size
    )


def validate_section_overlaps(
    sections: Sequence[DolSection], description: str, check_file: bool = True
) -> None:
    for index, first in enumerate(sections):
        for second in sections[index + 1 :]:
            if ranges_overlap(first.address, first.size, second.address, second.size):
                raise SystemExit(
                    f"{description} sections overlap in memory: {first.name} "
                    f"0x{first.address:08X}-0x{first.end:08X} and {second.name} "
                    f"0x{second.address:08X}-0x{second.end:08X}"
                )
            if check_file and ranges_overlap(
                first.offset, first.size, second.offset, second.size
            ):
                raise SystemExit(
                    f"{description} sections overlap in the file: {first.name} and "
                    f"{second.name}"
                )


def parse_dol(path: Path, source: str) -> DolImage:
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

    text: List[DolSection] = []
    data_sections: List[DolSection] = []
    for kind, offsets, addresses, sizes in (
        ("text", text_offsets, text_addresses, text_sizes),
        ("data", data_offsets, data_addresses, data_sizes),
    ):
        for index, (offset, address, size) in enumerate(zip(offsets, addresses, sizes)):
            if size == 0:
                continue
            if offset < 0x100 or offset + size > len(data):
                raise SystemExit(f"{path}: {kind}[{index}] lies outside the DOL file")
            if address + size > 0x100000000:
                raise SystemExit(
                    f"{path}: {kind}[{index}] wraps the 32-bit address space"
                )
            section = DolSection(
                kind=kind,
                index=index,
                offset=offset,
                address=address,
                data=data[offset : offset + size],
                source=source,
            )
            (text if kind == "text" else data_sections).append(section)

    if bss_address + bss_size > 0x100000000:
        raise SystemExit(f"{path}: BSS wraps the 32-bit address space")

    sections = text + data_sections
    validate_section_overlaps(sections, str(path))
    if not any(section.address <= entry < section.end for section in text):
        raise SystemExit(f"{path}: entry point 0x{entry:08X} is not in a text section")

    return DolImage(
        path=path,
        data=data,
        text=tuple(text),
        data_sections=tuple(data_sections),
        bss_address=bss_address,
        bss_size=bss_size,
        entry=entry,
    )


def validate_image_range(
    image: DolImage, minimum: int, maximum: int, description: str
) -> None:
    for section in image.sections:
        if section.address < minimum or section.end > maximum:
            raise SystemExit(
                f"{section.name} lies outside the {description} range: "
                f"0x{section.address:08X}-0x{section.end:08X}"
            )
    if image.bss_size and (
        image.bss_address < minimum or image.bss_address + image.bss_size > maximum
    ):
        raise SystemExit(
            f"{image.path}: BSS lies outside the {description} range: "
            f"0x{image.bss_address:08X}-0x{image.bss_address + image.bss_size:08X}"
        )


def describe_dol(image: DolImage, require_hid4: bool = False) -> Dict[str, object]:
    sections: List[Dict[str, object]] = [
        {
            "name": f"{section.kind}[{section.index}]",
            "address": f"0x{section.address:08X}",
            "size": section.size,
        }
        for section in image.sections
    ]
    if image.bss_size:
        sections.append(
            {
                "name": "bss",
                "address": f"0x{image.bss_address:08X}",
                "size": image.bss_size,
            }
        )

    if require_hid4 and not any(
        b"\x7C\x73\xFB\xA6" in section.data for section in image.text
    ):
        raise SystemExit("Dolphin Wii-mode HID4 sentinel is missing from the DOL")

    return {"entry": f"0x{image.entry:08X}", "sections": sections}


def validate_loader_dol(image: DolImage) -> Dict[str, object]:
    validate_image_range(image, LOADER_MIN, LOADER_MAX, "loader reservation")
    return describe_dol(image, require_hid4=True)


def validate_target_dol(image: DolImage) -> Dict[str, object]:
    validate_image_range(image, TARGET_MIN, TARGET_MAX, "KAR MEM1")
    return describe_dol(image)


def materialize_loader_bss(loader: DolImage) -> List[DolSection]:
    sections = list(loader.data_sections)
    if loader.bss_size == 0:
        return sections

    for section in loader.sections:
        if ranges_overlap(
            section.address, section.size, loader.bss_address, loader.bss_size
        ):
            raise SystemExit(
                f"loader BSS overlaps {section.name}; it cannot be safely materialized"
            )

    for index, section in enumerate(sections):
        if section.end == loader.bss_address:
            sections[index] = DolSection(
                kind="data",
                index=section.index,
                offset=section.offset,
                address=section.address,
                data=section.data + bytes(loader.bss_size),
                source=section.source,
            )
            validate_section_overlaps(
                list(loader.text) + sections,
                "materialized loader",
                check_file=False,
            )
            return sections

    next_index = max((section.index for section in sections), default=-1) + 1
    sections.append(
        DolSection(
            kind="data",
            index=next_index,
            offset=0,
            address=loader.bss_address,
            data=bytes(loader.bss_size),
            source="loader-bss",
        )
    )
    validate_section_overlaps(
        list(loader.text) + sections, "materialized loader", check_file=False
    )
    return sections


def validate_cross_image_ranges(
    target: DolImage, loader_sections: Sequence[DolSection]
) -> None:
    for target_section in target.sections:
        for loader_section in loader_sections:
            if ranges_overlap(
                target_section.address,
                target_section.size,
                loader_section.address,
                loader_section.size,
            ):
                raise SystemExit(
                    f"target and loader sections overlap: {target_section.name} and "
                    f"{loader_section.name}"
                )

    # DOL BSS may overlap that same DOL's initialized data; retail KAR does.
    # Preserve that layout and reject only overlaps with the resident loader.
    if target.bss_size:
        for loader_section in loader_sections:
            if ranges_overlap(
                target.bss_address,
                target.bss_size,
                loader_section.address,
                loader_section.size,
            ):
                raise SystemExit(
                    f"target BSS overlaps {loader_section.name}: "
                    f"0x{loader_section.address:08X}-0x{loader_section.end:08X}"
                )


def append_dol_section(
    output: bytearray,
    header_offset_base: int,
    header_address_base: int,
    header_size_base: int,
    index: int,
    section: DolSection,
) -> None:
    section_offset = align_up(len(output), 0x20)
    output.extend(bytes(section_offset - len(output)))
    write_u32(output, header_offset_base + index * 4, section_offset)
    write_u32(output, header_address_base + index * 4, section.address)
    write_u32(output, header_size_base + index * 4, section.size)
    output.extend(section.data)


def merge_dols(target: DolImage, loader: DolImage, output_path: Path) -> DolImage:
    loader_data = materialize_loader_bss(loader)
    text = list(target.text) + list(loader.text)
    data_sections = list(target.data_sections) + loader_data

    if len(text) > 7:
        raise SystemExit(f"merged DOL needs {len(text)} text slots; only 7 exist")
    if len(data_sections) > 11:
        raise SystemExit(
            f"merged DOL needs {len(data_sections)} data slots; only 11 exist"
        )

    all_sections = text + data_sections
    validate_section_overlaps(all_sections, "merged DOL", check_file=False)
    validate_cross_image_ranges(target, list(loader.text) + loader_data)

    output = bytearray(0x100)
    for index, section in enumerate(text):
        append_dol_section(output, 0x00, 0x48, 0x90, index, section)
    for index, section in enumerate(data_sections):
        append_dol_section(output, 0x1C, 0x64, 0xAC, index, section)
    write_u32(output, 0xD8, target.bss_address)
    write_u32(output, 0xDC, target.bss_size)
    write_u32(output, 0xE0, loader.entry)
    # The Wii apploader rounds every section read to a cache line. Keep the
    # FST from starting inside that final rounded read when the last section
    # itself ends only four-byte aligned.
    output.extend(bytes(align_up(len(output), 0x20) - len(output)))
    output_path.write_bytes(output)

    merged = parse_dol(output_path, "merged")
    if merged.entry != loader.entry:
        raise SystemExit("merged DOL entry does not match the loader entry")
    if (merged.bss_address, merged.bss_size) != (
        target.bss_address,
        target.bss_size,
    ):
        raise SystemExit("merged DOL did not preserve the target BSS")
    if len(merged.sections) != len(all_sections):
        raise SystemExit("merged DOL section count changed during serialization")
    for expected, actual in zip(all_sections, merged.sections):
        if (
            actual.address != expected.address
            or actual.size != expected.size
            or actual.data != expected.data
        ):
            raise SystemExit(f"merged DOL changed {expected.name}")
    describe_dol(merged, require_hid4=True)
    return merged


def main() -> None:
    args = parse_args()
    version = args.version
    region = VERSIONS[version]
    target_path: Optional[Path] = None
    target: Optional[DolImage] = None
    target_info: Optional[Dict[str, object]] = None
    target_sha1: Optional[str] = None
    if args.target_dol:
        target_path = require_file(args.target_dol, "target DOL")
        target = parse_dol(target_path, "target")
        target_sha1 = hashlib.sha1(target.data).hexdigest()
        expected_sha1 = str(region["original_dol_sha1"])
        if target_sha1 != expected_sha1:
            raise SystemExit(
                f"target DOL does not match {version}: expected SHA-1 "
                f"{expected_sha1}, got {target_sha1}"
            )
        target_info = validate_target_dol(target)

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

    default_output_name = "wii-loader-merged" if target else "wii-loader"
    if args.dolphin_osreport:
        default_output_name += "-debug"
    output_dir = (
        args.output_dir.resolve()
        if args.output_dir
        else ROOT / "build" / version / default_output_name
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
    if target:
        macros["KAR_TARGET_DOL_ENTRY"] = target.entry

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
    loader = parse_dol(dol_path, "loader")
    validate_loader_dol(loader)
    if target:
        final_dol = merge_dols(target, loader, dol_path)
        dol_info = describe_dol(final_dol, require_hid4=True)
    else:
        final_dol = loader
        dol_info = validate_loader_dol(final_dol)

    manifest_inputs = (
        Path(__file__).resolve(),
        LOADER_SOURCE,
        LOADER_LCF,
        ROOT / "include" / "kar" / "wii_mem2.h",
        ROOT / "include" / "dolphin" / "types.h",
        ROOT / "config" / version / "symbols.txt",
    )
    manifest = {
        "format_version": 2,
        "build_mode": "merged" if target else "standalone",
        "game_version": version,
        "reference_original_dol_sha1": region["original_dol_sha1"],
        "toolchain": {
            "compiler": {
                "name": compiler.name,
                "sha256": sha256_file(compiler),
            },
            "dtk": {
                "name": dtk.name,
                "sha256": sha256_file(dtk),
            },
            "wrapper": (
                {
                    "name": Path(wrapper).name,
                    "sha256": sha256_file(Path(wrapper)),
                }
                if wrapper
                else None
            ),
        },
        "inputs": {
            path.relative_to(ROOT).as_posix(): sha256_file(path)
            for path in manifest_inputs
        },
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
            "sha256": sha256_file(dol_path),
        },
    }
    if target and target_path and target_info and target_sha1:
        manifest["target_dol"] = {
            **target_info,
            "input_filename": target_path.name,
            "documented_layout_path": "files/orig.dol",
            "size": len(target.data),
            "sha1": target_sha1,
            "sha256": hashlib.sha256(target.data).hexdigest(),
            "bss": {
                "address": f"0x{target.bss_address:08X}",
                "size": target.bss_size,
            },
        }
    manifest_path.write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")

    print(f"Built {dol_path}")
    if target_path:
        print(f"Merged target {target_path}")
    print(f"Manifest {manifest_path}")


if __name__ == "__main__":
    try:
        main()
    except subprocess.CalledProcessError as error:
        raise SystemExit(error.returncode) from error
