#!/usr/bin/env python3
"""Build and validate the GPLv2 KAR Wii disc apploader."""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import shutil
import struct
import subprocess
import sys
from pathlib import Path
from typing import Dict, List, Optional, Sequence


ROOT = Path(__file__).resolve().parent.parent
SOURCE_DIR = ROOT / "tools" / "kar_wii_apploader"
SOURCE_FILES = (
    SOURCE_DIR / "apploader.c",
    SOURCE_DIR / "apploader.lds",
    SOURCE_DIR / "start.s",
    SOURCE_DIR / "dol.h",
    SOURCE_DIR / "gcm.h",
)
UPSTREAM_ARCHIVE_SHA256 = (
    "6f3ee1e6fb25f709511f78615ac79794fd02a9ab8a6f6abdb32258aa3a3335a7"
)
APPLOADER_HEADER_SIZE = 0x20
APPLOADER_LOAD_ADDRESS = 0x81200000
EXPECTED_BODY_SIZE = 0x2000
EXPECTED_TRAILER_SIZE = 0x1000


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--devkitppc",
        type=Path,
        help=(
            "devkitPPC root (otherwise use DEVKITPPC, "
            "DEVKITPRO/devkitPPC, PATH, or C:/devkitPro/devkitPPC)"
        ),
    )
    parser.add_argument(
        "--gcc",
        type=Path,
        help="explicit powerpc-eabi-gcc executable",
    )
    parser.add_argument(
        "--objcopy",
        type=Path,
        help="explicit powerpc-eabi-objcopy executable",
    )
    parser.add_argument(
        "--output-dir",
        type=Path,
        default=ROOT / "build" / "wii-apploader",
        help="output directory (default: build/wii-apploader)",
    )
    return parser.parse_args()


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        while chunk := stream.read(1024 * 1024):
            digest.update(chunk)
    return digest.hexdigest()


def executable_name(name: str) -> str:
    return name + (".exe" if sys.platform == "win32" else "")


def candidate_toolchain_roots(explicit: Optional[Path]) -> List[Path]:
    roots: List[Path] = []
    if explicit is not None:
        roots.append(explicit)
    env_devkitppc = os.environ.get("DEVKITPPC")
    if env_devkitppc:
        roots.append(Path(env_devkitppc))
    env_devkitpro = os.environ.get("DEVKITPRO")
    if env_devkitpro:
        roots.append(Path(env_devkitpro) / "devkitPPC")
    if sys.platform == "win32":
        roots.append(Path("C:/devkitPro/devkitPPC"))
    return roots


def resolve_tool(
    explicit: Optional[Path], name: str, toolchain_roots: Sequence[Path]
) -> Path:
    if explicit is not None:
        if explicit.is_file():
            return explicit.resolve()
        resolved = shutil.which(str(explicit))
        if resolved:
            return Path(resolved).resolve()
        raise SystemExit(f"{name} not found: {explicit}")

    filename = executable_name(name)
    for root in toolchain_roots:
        candidate = root / "bin" / filename
        if candidate.is_file():
            return candidate.resolve()

    resolved = shutil.which(name)
    if resolved:
        return Path(resolved).resolve()
    raise SystemExit(
        f"{name} not found; install devkitPPC or pass --devkitppc/--{name.split('-')[-1]}"
    )


def run(command: Sequence[str], cwd: Path) -> None:
    print("+", subprocess.list2cmdline(list(command)))
    subprocess.run(list(command), cwd=cwd, check=True)


def tool_version(tool: Path) -> str:
    result = subprocess.run(
        [str(tool), "--version"],
        check=True,
        capture_output=True,
        text=True,
    )
    return result.stdout.splitlines()[0]


def gcc_reported_path(gcc: Path, option: str, description: str) -> Path:
    result = subprocess.run(
        [str(gcc), option],
        check=True,
        capture_output=True,
        text=True,
    )
    value = result.stdout.strip()
    path = Path(value)
    if path.is_file():
        return path.resolve()
    adjacent = gcc.parent / value
    if adjacent.is_file():
        return adjacent.resolve()
    resolved = shutil.which(value)
    if resolved:
        return Path(resolved).resolve()
    raise SystemExit(f"{description} reported by {gcc.name} was not found: {value}")


def validate_and_pad(raw_path: Path, image_path: Path) -> Dict[str, object]:
    raw = raw_path.read_bytes()
    if len(raw) < APPLOADER_HEADER_SIZE:
        raise SystemExit("apploader binary is smaller than its 0x20-byte header")

    try:
        revision = raw[:10].decode("ascii")
    except UnicodeDecodeError as error:
        raise SystemExit("apploader revision is not ASCII") from error
    if raw[10:16] != bytes(6):
        raise SystemExit("apploader revision padding is not zero-filled")

    entry, body_size, trailer_size, reserved = struct.unpack_from(">IIII", raw, 0x10)
    if body_size != EXPECTED_BODY_SIZE or trailer_size != EXPECTED_TRAILER_SIZE:
        raise SystemExit(
            "unexpected apploader header sizes: "
            f"body=0x{body_size:X}, trailer=0x{trailer_size:X}"
        )
    if reserved != 0:
        raise SystemExit("apploader header reserved word is not zero")
    if not APPLOADER_LOAD_ADDRESS <= entry < APPLOADER_LOAD_ADDRESS + body_size:
        raise SystemExit(f"apploader entry is outside its loaded body: 0x{entry:08X}")

    body_end = APPLOADER_HEADER_SIZE + body_size
    image_size = body_end + trailer_size
    if len(raw) > body_end:
        raise SystemExit(
            f"apploader binary is {len(raw)} bytes and exceeds its advertised body"
        )

    image = raw + bytes(image_size - len(raw))
    if any(image[len(raw) :]):
        raise SystemExit("apploader padding is not zero-filled")
    if b"homebrew channel" in image.lower():
        raise SystemExit("unexpected Homebrew Channel string in apploader image")
    image_path.write_bytes(image)

    return {
        "revision": revision,
        "entry": f"0x{entry:08X}",
        "body_size": body_size,
        "trailer_size": trailer_size,
        "raw_size": len(raw),
        "image_size": len(image),
    }


def main() -> None:
    args = parse_args()
    for source in SOURCE_FILES:
        if not source.is_file():
            raise SystemExit(f"apploader source not found: {source}")

    roots = candidate_toolchain_roots(args.devkitppc)
    gcc = resolve_tool(args.gcc, "powerpc-eabi-gcc", roots)
    objcopy = resolve_tool(args.objcopy, "powerpc-eabi-objcopy", roots)
    linker = gcc_reported_path(gcc, "-print-prog-name=ld", "linker")
    libgcc = gcc_reported_path(gcc, "-print-libgcc-file-name", "libgcc")
    output_dir = args.output_dir.resolve()
    output_dir.mkdir(parents=True, exist_ok=True)

    start_object = output_dir / "start.o"
    apploader_object = output_dir / "apploader.o"
    elf_path = output_dir / "kar-wii-apploader.elf"
    raw_path = output_dir / "apploader.bin"
    image_path = output_dir / "apploader.img"
    manifest_path = output_dir / "apploader-manifest.json"

    common_flags = [
        "-Wall",
        "-W",
        "-Os",
        "-ffreestanding",
        "-fno-asynchronous-unwind-tables",
        "-fno-unwind-tables",
        "-mno-eabi",
        "-mno-sdata",
    ]
    run(
        [
            str(gcc),
            *common_flags,
            "-c",
            str(SOURCE_DIR / "start.s"),
            "-o",
            start_object.name,
        ],
        output_dir,
    )
    run(
        [
            str(gcc),
            *common_flags,
            "-mmultiple",
            "-c",
            str(SOURCE_DIR / "apploader.c"),
            "-o",
            apploader_object.name,
        ],
        output_dir,
    )
    run(
        [
            str(gcc),
            "-nostdlib",
            f"-Wl,-T,{SOURCE_DIR / 'apploader.lds'}",
            start_object.name,
            apploader_object.name,
            "-lgcc",
            "-o",
            elf_path.name,
        ],
        output_dir,
    )
    run(
        [str(objcopy), "-O", "binary", elf_path.name, raw_path.name],
        output_dir,
    )

    header = validate_and_pad(raw_path, image_path)
    outputs = {
        path.name: {"size": path.stat().st_size, "sha256": sha256(path)}
        for path in (elf_path, raw_path, image_path)
    }
    manifest = {
        "format_version": 2,
        "build_mode": "wii-disc-apploader",
        "license": "GPL-2.0-only",
        "upstream": {
            "article": "https://hackmii.com/2008/08/open-source-apploader-iso-template/",
            "archive": "https://static.hackmii.com/wii-apploader.tar.gz",
            "archive_sha256": UPSTREAM_ARCHIVE_SHA256,
        },
        "patches": [
            "strict MEM1 and KAR resident-loader MEM2 section allowlists",
            "DOL file-bound and address-overflow validation",
            "FST size, alignment, and apploader-workspace validation",
            "clear BSS before loading initialized sections",
            "zero-only image padding",
        ],
        "toolchain": {
            "gcc": {
                "name": gcc.name,
                "version": tool_version(gcc),
                "sha256": sha256(gcc),
            },
            "objcopy": {
                "name": objcopy.name,
                "sha256": sha256(objcopy),
            },
            "linker": {
                "name": linker.name,
                "sha256": sha256(linker),
            },
            "libgcc": {
                "name": libgcc.name,
                "sha256": sha256(libgcc),
            },
        },
        "header": header,
        "sources": {
            path.relative_to(ROOT).as_posix(): sha256(path)
            for path in SOURCE_FILES
        },
        "outputs": outputs,
    }
    manifest_path.write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")

    print(f"Built {image_path}")
    print(f"Manifest {manifest_path}")


if __name__ == "__main__":
    try:
        main()
    except subprocess.CalledProcessError as error:
        raise SystemExit(error.returncode) from error
