#!/usr/bin/env python3
"""Reject compiler-output accessor macros in KAR source files."""

from __future__ import annotations

import re
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SOURCE_ROOT = ROOT / "src" / "kar"

# These macros predate this check and parse byte-oriented socket data. Keep the
# exception exact so the list can only shrink; no other file or macro is exempt.
LEGACY_EXCEPTIONS = {
    ("src/kar/lb/lbnet.c", "FU32"),
    ("src/kar/lb/lbnet.c", "FS32"),
    ("src/kar/lb/lbnet.c", "FF32"),
    ("src/kar/lb/lbnet.c", "FU8"),
    ("src/kar/lb/lbnet.c", "FS8"),
    ("src/kar/lb/lbnet.c", "FU16"),
    ("src/kar/lb/lbnet.c", "FP"),
    ("src/kar/network/IPIgmp.c", "FU8"),
    ("src/kar/network/IPIgmp.c", "FS8"),
    ("src/kar/network/IPIgmp.c", "FU16"),
    ("src/kar/network/IPIgmp.c", "FS16"),
    ("src/kar/network/IPIgmp.c", "FU32"),
    ("src/kar/network/IPIgmp.c", "FS32"),
    ("src/kar/network/IPSocket.c", "FS8"),
    ("src/kar/network/IPSocket.c", "FU8"),
    ("src/kar/network/IPSocket.c", "FS16"),
    ("src/kar/network/IPSocket.c", "FU16"),
    ("src/kar/network/IPSocket.c", "FS32"),
    ("src/kar/network/IPSocket.c", "FU32"),
    ("src/kar/network/IPSocket.c", "FPTR"),
}

DEFINE_RE = re.compile(
    r"^\s*#\s*define\s+([A-Za-z_][A-Za-z0-9_]*)"
    r"(?:\s*\([^)]*\))?\s*(.*)$",
    re.DOTALL,
)
RAW_BYTE_CAST_RE = re.compile(r"\(\s*(?:u8|char)\s*\*\s*\)")
RAW_DEREFERENCE_RE = re.compile(
    r"\*\s*\(\s*(?:const\s+)?"
    r"(?:void|u8|s8|u16|s16|u32|s32|u64|s64|f32|f64|Vec|[A-Za-z_][A-Za-z0-9_]*)"
    r"\s*\*+"
)
ACCESSOR_NAME_RE = re.compile(
    r"^(?:GET|LOAD|STORE|COPY|READ|WRITE)(?:_|$)|"
    r"^(?:FIELD|VEC_FIELD|F32_FIELD|S32_FIELD|U8_FIELD|PTR_FIELD)$"
)


def logical_directives(text: str) -> list[tuple[int, str]]:
    directives: list[tuple[int, str]] = []
    lines = text.splitlines()
    index = 0

    while index < len(lines):
        start = index
        parts = [lines[index]]
        while parts[-1].rstrip().endswith("\\") and index + 1 < len(lines):
            parts[-1] = parts[-1].rstrip()[:-1]
            index += 1
            parts.append(lines[index])
        directives.append((start + 1, " ".join(parts)))
        index += 1

    return directives


def is_forbidden_accessor(name: str, body: str) -> bool:
    body = body.lstrip()
    if not body.startswith(("(*", "*(")):
        return False

    has_raw_dereference = RAW_DEREFERENCE_RE.search(body) is not None
    has_byte_cast = RAW_BYTE_CAST_RE.search(body) is not None

    if ACCESSOR_NAME_RE.search(name) and has_raw_dereference:
        return True
    return has_raw_dereference and has_byte_cast


def main() -> int:
    violations: list[str] = []

    for path in sorted(SOURCE_ROOT.rglob("*.c")):
        relative = path.relative_to(ROOT).as_posix()
        text = path.read_text(encoding="utf-8", errors="surrogateescape")

        for line_number, directive in logical_directives(text):
            match = DEFINE_RE.match(directive)
            if match is None:
                continue

            name, body = match.groups()
            if not is_forbidden_accessor(name, body):
                continue
            if (relative, name) in LEGACY_EXCEPTIONS:
                continue

            violations.append(
                f"{relative}:{line_number}: raw accessor macro {name} is "
                "forbidden; describe the layout with a typed struct or union"
            )

    if violations:
        print("Decomp source-quality check failed:", file=sys.stderr)
        for violation in violations:
            print(f"  {violation}", file=sys.stderr)
        return 1

    print(
        "Decomp source-quality check passed "
        f"({len(LEGACY_EXCEPTIONS)} frozen legacy socket exceptions)."
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
