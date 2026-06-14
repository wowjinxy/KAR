#!/usr/bin/env python3

"""Import conservative symbol upgrades from doldecomp/kar.

The upstream repository does not ship a decomp-toolkit symbols.txt file; its
addressed names live in assembly labels. This helper extracts global labels
with concrete addresses and updates local symbols only when the local name is
still generic by default.

Game asm labels are intentionally excluded unless --include-game-asm is passed.
The user's stated trust boundary is upstream src plus SDK/runtime library
provenance, not every asm-only game label.
"""

from __future__ import annotations

import argparse
import re
from dataclasses import dataclass
from pathlib import Path


GENERIC_RE = re.compile(
    r"^(fn|lbl|jumptable|jtbl|float|double|str|data|byte|word|gap|unk)_?"
    r"[0-9A-Fa-f]{6,8}$"
)
SYMBOL_RE = re.compile(
    r"^(?P<name>[^\s=]+)(?P<rest>\s*=\s*(?P<section>[^:]+):0x"
    r"(?P<addr>[0-9A-Fa-f]+);\s*//\s*(?P<comment>.*))$"
)
GLOBAL_RE = re.compile(r"\s*\.global\s+([A-Za-z_.$@][\w.$@]*)")
LABEL_RE = re.compile(r"^([A-Za-z_.$@][\w.$@]*):\s*$")
ADDR_RE = re.compile(r"/\*\s*([0-9A-Fa-f]{8})\s+")

DEFAULT_CATEGORIES = {"sysdolphin", "dolphin_sdk", "runtime_sdk"}


@dataclass(frozen=True)
class UpstreamLabel:
    address: str
    name: str
    source: str
    category: str


@dataclass(frozen=True)
class ReportRow:
    action: str
    category: str
    address: str
    old_name: str
    new_name: str
    source: str
    reason: str


def classify_source(path: str) -> str:
    if path.startswith("asm/sysdolphin/"):
        return "sysdolphin"
    if path.startswith("asm/dolphin/") or path.startswith("asm/Dolphin/"):
        return "dolphin_sdk"
    if path.startswith("asm/runtime/") or path.startswith("asm/Runtime.PPCEABI.H/"):
        return "runtime_sdk"
    if path in {
        "asm/abort_exit.s",
        "asm/cstring.s",
        "asm/PPCArch.s",
        "asm/os/__ppc_eabi_init.s",
        "asm/init/__ppc_eabi_init.s",
    }:
        return "runtime_sdk"
    if path in {"asm/IPSocket.s", "asm/IPIgmp.s"}:
        return "network_sdk"
    return "game_asm"


def is_generic_name(name: str) -> bool:
    return (
        bool(GENERIC_RE.match(name))
        or name.startswith("@et")
        or name.startswith("auto_")
    )


def extract_upstream_labels(upstream: Path) -> dict[str, UpstreamLabel]:
    labels: dict[str, UpstreamLabel] = {}
    asm_root = upstream / "asm"
    for path in sorted(asm_root.rglob("*.s")):
        rel = path.relative_to(upstream).as_posix()
        lines = path.read_text(errors="ignore").splitlines()
        last_global: str | None = None
        for i, line in enumerate(lines):
            global_match = GLOBAL_RE.match(line)
            if global_match:
                last_global = global_match.group(1)
                continue

            label_match = LABEL_RE.match(line)
            if not label_match:
                continue
            name = label_match.group(1)
            is_global = last_global == name
            last_global = None
            if not is_global or name.startswith(("lbl_", "func_")):
                continue

            address = None
            for probe in lines[i + 1 : i + 6]:
                addr_match = ADDR_RE.search(probe)
                if addr_match:
                    address = addr_match.group(1).lower()
                    break
            if address is None:
                continue

            # Keep the first label at an address. Duplicate globals in upstream
            # should be reviewed manually rather than silently replacing each
            # other.
            labels.setdefault(
                address,
                UpstreamLabel(address, name, rel, classify_source(rel)),
            )
    return labels


def update_symbols(
    symbol_path: Path,
    upstream_labels: dict[str, UpstreamLabel],
    allowed_categories: set[str],
    include_conflicts: bool,
) -> tuple[list[str], list[ReportRow]]:
    output: list[str] = []
    report: list[ReportRow] = []
    seen_addresses: set[str] = set()

    for line in symbol_path.read_text(errors="ignore").splitlines():
        match = SYMBOL_RE.match(line)
        if not match:
            output.append(line)
            continue

        old_name = match.group("name")
        address = match.group("addr").lower()
        seen_addresses.add(address)
        upstream = upstream_labels.get(address)
        if upstream is None:
            output.append(line)
            continue

        if upstream.category not in allowed_categories:
            output.append(line)
            report.append(
                ReportRow(
                    "skip",
                    upstream.category,
                    address,
                    old_name,
                    upstream.name,
                    upstream.source,
                    "category not enabled",
                )
            )
            continue

        if old_name == upstream.name:
            output.append(line)
            report.append(
                ReportRow(
                    "same",
                    upstream.category,
                    address,
                    old_name,
                    upstream.name,
                    upstream.source,
                    "already named",
                )
            )
            continue

        if not is_generic_name(old_name) and not include_conflicts:
            output.append(line)
            report.append(
                ReportRow(
                    "skip",
                    upstream.category,
                    address,
                    old_name,
                    upstream.name,
                    upstream.source,
                    "local name is non-generic",
                )
            )
            continue

        output.append(f"{upstream.name}{match.group('rest')}")
        report.append(
            ReportRow(
                "rename",
                upstream.category,
                address,
                old_name,
                upstream.name,
                upstream.source,
                "generic local name" if is_generic_name(old_name) else "conflict override",
            )
        )

    for address, upstream in sorted(upstream_labels.items()):
        if address in seen_addresses or upstream.category not in allowed_categories:
            continue
        report.append(
            ReportRow(
                "skip",
                upstream.category,
                address,
                "",
                upstream.name,
                upstream.source,
                "address not present in local symbols",
            )
        )

    return output, report


def write_report(path: Path, report: list[ReportRow]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    lines = ["action\tcategory\taddress\told_name\tnew_name\tsource\treason"]
    for row in report:
        lines.append(
            "\t".join(
                [
                    row.action,
                    row.category,
                    row.address,
                    row.old_name,
                    row.new_name,
                    row.source,
                    row.reason,
                ]
            )
        )
    path.write_text("\n".join(lines) + "\n")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--upstream",
        type=Path,
        default=Path("../external/doldecomp-kar"),
        help="path to a cloned doldecomp/kar checkout",
    )
    parser.add_argument(
        "--version",
        default="GKYE01",
        help="local config version to update (default: GKYE01)",
    )
    parser.add_argument(
        "--symbols",
        type=Path,
        help="symbols.txt path; defaults to config/<version>/symbols.txt",
    )
    parser.add_argument(
        "--report",
        type=Path,
        default=Path("docs/doldecomp_kar_symbol_sync.tsv"),
        help="TSV report path",
    )
    parser.add_argument(
        "--include-game-asm",
        action="store_true",
        help="also consider upstream asm-only game labels",
    )
    parser.add_argument(
        "--include-network-sdk",
        action="store_true",
        help="also consider upstream IP/network SDK labels",
    )
    parser.add_argument(
        "--include-conflicts",
        action="store_true",
        help="allow replacing non-generic local names",
    )
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    repo_root = Path.cwd()
    upstream = args.upstream
    if not upstream.is_absolute():
        upstream = (repo_root / upstream).resolve()
    if not upstream.exists():
        raise SystemExit(f"upstream checkout not found: {upstream}")

    symbol_path = args.symbols or Path("config") / args.version / "symbols.txt"
    if not symbol_path.is_absolute():
        symbol_path = repo_root / symbol_path
    if not symbol_path.exists():
        raise SystemExit(f"symbols file not found: {symbol_path}")

    allowed_categories = set(DEFAULT_CATEGORIES)
    if args.include_game_asm:
        allowed_categories.add("game_asm")
    if args.include_network_sdk:
        allowed_categories.add("network_sdk")

    upstream_labels = extract_upstream_labels(upstream)
    new_lines, report = update_symbols(
        symbol_path,
        upstream_labels,
        allowed_categories,
        args.include_conflicts,
    )

    rename_count = sum(row.action == "rename" for row in report)
    skip_count = sum(row.action == "skip" for row in report)
    same_count = sum(row.action == "same" for row in report)

    if not args.dry_run:
        symbol_path.write_text("\n".join(new_lines) + "\n")
        report_path = args.report
        if not report_path.is_absolute():
            report_path = repo_root / report_path
        write_report(report_path, report)

    print(f"upstream labels: {len(upstream_labels)}")
    print(f"renamed: {rename_count}")
    print(f"same: {same_count}")
    print(f"skipped: {skip_count}")
    if args.dry_run:
        print("dry run: no files written")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
