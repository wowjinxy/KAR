#!/usr/bin/env python3

"""Audit and reproduce the provisional KAR split-widening pass."""

from __future__ import annotations

from argparse import ArgumentParser
from collections import Counter
from dataclasses import dataclass
import csv
import json
from pathlib import Path
import re


PROJECT_ROOT = Path(__file__).resolve().parents[1]
DATA_SECTION_NAMES = {
    ".rodata",
    ".data",
    ".sdata",
    ".sdata2",
    ".bss",
    ".sbss",
    ".sbss2",
    ".ctors",
    ".dtors",
}


@dataclass
class SplitEntry:
    file: str
    start: int
    end: int


@dataclass
class FunctionRange:
    addr: int
    end: int
    name: str


@dataclass
class Assignment:
    file: str
    confidence: str
    reason: str
    name: str


@dataclass
class TextUnit:
    name: str
    start: int
    end: int
    size: int
    auto: bool


@dataclass
class ClaimedGap:
    file: str
    start: int
    end: int
    function_count: int
    assigned_count: int
    reason: str


def parse_int(value: str | int) -> int:
    if isinstance(value, int):
        return value
    return int(value, 0)


def default_evidence_path(name: str) -> Path:
    candidates = [
        PROJECT_ROOT.parent / name,
        PROJECT_ROOT.parent / "docs" / "ghidra" / name,
    ]
    for candidate in candidates:
        if candidate.exists():
            return candidate
    return candidates[0]


def parse_splits(path: Path) -> tuple[list[str], list[SplitEntry]]:
    lines = path.read_text().splitlines()
    header: list[str] = []
    entries: list[SplitEntry] = []
    current_file: str | None = None
    in_header = True

    for line in lines:
        if in_header:
            header.append(line)
            if line.strip() == "" and header and header[0].strip() == "Sections:":
                in_header = False
            continue

        if line.endswith(":") and not line.startswith("\t"):
            current_file = line[:-1]
            continue

        match = re.search(
            r"\.text\s+start:0x([0-9A-Fa-f]+) end:0x([0-9A-Fa-f]+)", line
        )
        if match and current_file:
            entries.append(
                SplitEntry(
                    current_file,
                    int(match.group(1), 16),
                    int(match.group(2), 16),
                )
            )

    return header, entries


def write_splits(path: Path, header: list[str], entries: list[SplitEntry]) -> None:
    out: list[str] = list(header)
    if out and out[-1].strip():
        out.append("")

    for entry in entries:
        out.append(f"{entry.file}:")
        out.append(f"\t.text       start:0x{entry.start:08X} end:0x{entry.end:08X}")
        out.append("")

    path.write_text("\n".join(out).rstrip() + "\n")


def load_functions(path: Path) -> list[FunctionRange]:
    functions: list[FunctionRange] = []
    with path.open(newline="") as f:
        for row in csv.DictReader(f, delimiter="\t"):
            functions.append(
                FunctionRange(
                    int(row["entry"], 16),
                    int(row["max"], 16) + 1,
                    row["name"],
                )
            )
    return sorted(functions, key=lambda item: item.addr)


def load_assignments(path: Path) -> dict[int, Assignment]:
    assignments: dict[int, Assignment] = {}
    with path.open(newline="") as f:
        for row in csv.DictReader(f, delimiter="\t"):
            assignments[int(row["addr"], 16)] = Assignment(
                row["file"],
                row["confidence"],
                row["reason"],
                row["new_name"],
            )
    return assignments


def load_report(path: Path) -> tuple[list[TextUnit], list[dict[str, int | str | bool]]]:
    report = json.loads(path.read_text())
    text_units: list[TextUnit] = []
    data_sections: list[dict[str, int | str | bool]] = []

    for unit in report["units"]:
        unit_name = unit["name"].removeprefix("main/")
        auto = unit.get("metadata", {}).get("auto_generated", False) or unit_name.startswith(
            "auto_"
        )
        for section in unit.get("sections", []):
            size = parse_int(section["size"])
            start = parse_int(section.get("metadata", {}).get("virtual_address", 0))
            section_name = section["name"]
            if section_name == ".text":
                text_units.append(TextUnit(unit_name, start, start + size, size, auto))
            elif section_name in DATA_SECTION_NAMES:
                data_sections.append(
                    {
                        "unit": unit_name,
                        "section": section_name,
                        "start": start,
                        "end": start + size,
                        "size": size,
                        "auto": auto,
                    }
                )

    return (
        sorted(text_units, key=lambda item: item.start),
        sorted(data_sections, key=lambda item: (str(item["section"]), int(item["start"]))),
    )


def range_functions(
    functions: list[FunctionRange], start: int, end: int
) -> list[FunctionRange]:
    return [func for func in functions if start <= func.addr < end]


def assignment_summary(
    functions: list[FunctionRange],
    assignments: dict[int, Assignment],
    start: int,
    end: int,
) -> tuple[list[FunctionRange], Counter[str], int | None, int | None]:
    gap_functions = range_functions(functions, start, end)
    assigned = [func for func in gap_functions if func.addr in assignments]
    counts = Counter(assignments[func.addr].file for func in assigned)
    first_assigned = assigned[0].addr if assigned else None
    last_assigned_end = assigned[-1].end if assigned else None
    return gap_functions, counts, first_assigned, last_assigned_end


def claimable_gap(
    prev_entry: SplitEntry,
    next_entry: SplitEntry,
    functions: list[FunctionRange],
    assignments: dict[int, Assignment],
) -> tuple[str, str, int, int] | None:
    start = prev_entry.end
    end = next_entry.start
    if start >= end:
        return None

    if prev_entry.file == "fl_indirectload.cpp" and next_entry.file == "OSThread.c":
        return None

    gap_functions, counts, first_assigned, last_assigned_end = assignment_summary(
        functions, assignments, start, end
    )
    if not gap_functions or not counts or first_assigned is None or last_assigned_end is None:
        return None

    files = set(counts)
    lead = first_assigned - start
    trail = end - last_assigned_end

    if files <= {prev_entry.file} and lead <= 0x4000 and trail <= 0x800:
        return "prev", "only-prev-assign", len(gap_functions), sum(counts.values())
    if files <= {next_entry.file} and lead <= 0x800 and trail <= 0x4000:
        return "next", "only-next-assign", len(gap_functions), sum(counts.values())
    if files <= {prev_entry.file} and len(gap_functions) <= 20 and lead <= 0x8000 and trail <= 0x4000:
        return "prev", "small-prev-gap", len(gap_functions), sum(counts.values())
    if files <= {next_entry.file} and len(gap_functions) <= 20 and lead <= 0x4000 and trail <= 0x8000:
        return "next", "small-next-gap", len(gap_functions), sum(counts.values())

    return None


def widen_entries(
    entries: list[SplitEntry],
    functions: list[FunctionRange],
    assignments: dict[int, Assignment],
) -> list[ClaimedGap]:
    claims: list[ClaimedGap] = []
    for prev_entry, next_entry in zip(entries, entries[1:]):
        result = claimable_gap(prev_entry, next_entry, functions, assignments)
        if result is None:
            continue

        owner, reason, function_count, assigned_count = result
        if owner == "prev":
            claim = ClaimedGap(
                prev_entry.file,
                prev_entry.end,
                next_entry.start,
                function_count,
                assigned_count,
                reason,
            )
            prev_entry.end = next_entry.start
        else:
            claim = ClaimedGap(
                next_entry.file,
                prev_entry.end,
                next_entry.start,
                function_count,
                assigned_count,
                reason,
            )
            next_entry.start = prev_entry.end
        claims.append(claim)

    for prev_entry, next_entry in zip(entries, entries[1:]):
        if prev_entry.end > next_entry.start:
            raise RuntimeError(
                f"split overlap after widening: {prev_entry.file} and {next_entry.file}"
            )

    return claims


def explicit_neighbors(
    text_units: list[TextUnit], auto_unit: TextUnit
) -> tuple[TextUnit | None, TextUnit | None]:
    explicit = [unit for unit in text_units if not unit.auto]
    prev_unit = None
    next_unit = None
    for unit in explicit:
        if unit.end <= auto_unit.start:
            prev_unit = unit
        elif unit.start >= auto_unit.end:
            next_unit = unit
            break
    return prev_unit, next_unit


def classify_auto_gap(auto_unit: TextUnit, prev_unit: TextUnit | None, next_unit: TextUnit | None) -> str:
    prev_name = prev_unit.name if prev_unit else ""
    next_name = next_unit.name if next_unit else ""
    start = auto_unit.start
    end = auto_unit.end

    if start < 0x80005898:
        return "init/runtime"
    if start < 0x8040F00C and end > 0x80397080:
        return "runtime/sdk-risk"
    if "OSThread.c" in {prev_name, next_name} or "displayfunc.c" in {prev_name, next_name}:
        return "runtime/sdk-risk"
    if start >= 0x8040F00C:
        return "HSD/backend/network"
    if prev_name.startswith("a2d_") or next_name.startswith("a2d_"):
        return "Air Ride 2D/gameplay"
    if 0x80170000 <= start < 0x80280000:
        return "menu/object/gameplay"
    if start < 0x80170000:
        return "core gameplay"
    return "unknown gameplay/library"


def format_assignments(counts: Counter[str]) -> str:
    if not counts:
        return "-"
    return ", ".join(f"{name}:{count}" for name, count in counts.most_common(3))


def markdown_escape(value: str) -> str:
    return value.replace("|", "\\|")


def generate_audit_markdown(
    version: str,
    text_units: list[TextUnit],
    data_sections: list[dict[str, int | str | bool]],
    functions: list[FunctionRange],
    assignments: dict[int, Assignment],
    remaining_claims: list[ClaimedGap],
) -> str:
    explicit_text = [unit for unit in text_units if not unit.auto]
    auto_text = [unit for unit in text_units if unit.auto]
    explicit_code = sum(unit.size for unit in explicit_text)
    auto_code = sum(unit.size for unit in auto_text)

    explicit_data = sum(int(sec["size"]) for sec in data_sections if not bool(sec["auto"]))
    auto_data = sum(int(sec["size"]) for sec in data_sections if bool(sec["auto"]))

    lines: list[str] = [
        f"# {version} Auto Text Audit",
        "",
        "Generated by `tools/kar_split_workbench.py` from the current build report",
        "and the local KAR boundary/rename evidence TSVs.",
        "",
        "## Summary",
        "",
        f"- Source-named `.text`: {explicit_code:,} bytes across {len(explicit_text)} units",
        f"- Remaining auto `.text`: {auto_code:,} bytes across {len(auto_text)} units",
        f"- Source-named data: {explicit_data:,} bytes",
        f"- Remaining auto data: {auto_data:,} bytes",
        f"- Currently claimable text gaps under the widening heuristic: {len(remaining_claims)}",
        "",
        "## Remaining Auto Text Units",
        "",
        "| Rank | Range | Size | Category | Previous explicit | Next explicit | Rename evidence |",
        "| ---: | --- | ---: | --- | --- | --- | --- |",
    ]

    ranked_auto = sorted(auto_text, key=lambda unit: unit.size, reverse=True)
    for index, unit in enumerate(ranked_auto, start=1):
        prev_unit, next_unit = explicit_neighbors(text_units, unit)
        _, counts, _, _ = assignment_summary(functions, assignments, unit.start, unit.end)
        category = classify_auto_gap(unit, prev_unit, next_unit)
        prev_name = prev_unit.name if prev_unit else "-"
        next_name = next_unit.name if next_unit else "-"
        lines.append(
            "| "
            f"{index} | "
            f"`{unit.start:08X}-{unit.end:08X}` | "
            f"{unit.size:,} | "
            f"{markdown_escape(category)} | "
            f"`{markdown_escape(prev_name)}` | "
            f"`{markdown_escape(next_name)}` | "
            f"{markdown_escape(format_assignments(counts))} |"
        )

    auto_data_sections = [
        sec for sec in data_sections if bool(sec["auto"]) and int(sec["size"]) > 0
    ]
    data_note = (
        "No auto-owned data sections remain in the current report."
        if not auto_data_sections
        else "The largest remaining auto-owned data sections are listed below."
    )

    lines.extend(
        [
            "",
            "## Auto Data Snapshot",
            "",
            data_note,
            "",
            "| Section | Range | Size | Unit |",
            "| --- | --- | ---: | --- |",
        ]
    )
    for sec in sorted(auto_data_sections, key=lambda item: int(item["size"]), reverse=True)[:20]:
        lines.append(
            "| "
            f"`{sec['section']}` | "
            f"`{int(sec['start']):08X}-{int(sec['end']):08X}` | "
            f"{int(sec['size']):,} | "
            f"`{markdown_escape(str(sec['unit']))}` |"
        )

    lines.extend(
        [
            "",
            "## Notes",
            "",
            "- `runtime/sdk-risk` ranges should stay conservative until the runtime, HSD,",
            "  and exception-support objects are identified in detail.",
            "- Rows with rename evidence should be checked before promoting any new split",
            "  boundary; rows without evidence need strings, xrefs, or version-shift",
            "  comparisons before ownership is claimed.",
        ]
    )

    return "\n".join(lines) + "\n"


def print_claims(claims: list[ClaimedGap]) -> None:
    print(f"claimable gaps: {len(claims)}")
    print(f"claimable bytes: {sum(claim.end - claim.start for claim in claims)}")
    for claim in sorted(claims, key=lambda item: item.end - item.start, reverse=True)[:30]:
        print(
            f"{claim.file:28s} "
            f"{claim.start:08X}-{claim.end:08X} "
            f"+{claim.end - claim.start:6d} "
            f"funcs {claim.function_count:3d} "
            f"assigned {claim.assigned_count:3d} "
            f"{claim.reason}"
        )


def main() -> None:
    parser = ArgumentParser(description=__doc__)
    parser.add_argument("--version", default="GKYE01")
    parser.add_argument("--project-root", type=Path, default=PROJECT_ROOT)
    parser.add_argument("--splits", type=Path)
    parser.add_argument("--report", type=Path)
    parser.add_argument(
        "--function-ranges",
        type=Path,
        default=default_evidence_path("KAR_Function_Ranges.tsv"),
    )
    parser.add_argument(
        "--rename-pass",
        type=Path,
        default=default_evidence_path("KAR_Source_Boundary_Rename_Pass.tsv"),
    )
    parser.add_argument("--apply-widening", action="store_true")
    parser.add_argument("--write-audit", type=Path)
    args = parser.parse_args()

    project_root = args.project_root.resolve()
    splits_path = args.splits or project_root / "config" / args.version / "splits.txt"
    report_path = args.report or project_root / "build" / args.version / "report.json"

    header, entries = parse_splits(splits_path)
    functions = load_functions(args.function_ranges)
    assignments = load_assignments(args.rename_pass)

    widened_entries = [SplitEntry(entry.file, entry.start, entry.end) for entry in entries]
    claims = widen_entries(widened_entries, functions, assignments)
    print_claims(claims)

    if args.apply_widening:
        write_splits(splits_path, header, widened_entries)
        print(f"wrote {splits_path}")

    if args.write_audit:
        text_units, data_sections = load_report(report_path)
        remaining_entries = widened_entries if args.apply_widening else entries
        remaining_claims = widen_entries(
            [SplitEntry(entry.file, entry.start, entry.end) for entry in remaining_entries],
            functions,
            assignments,
        )
        markdown = generate_audit_markdown(
            args.version,
            text_units,
            data_sections,
            functions,
            assignments,
            remaining_claims,
        )
        args.write_audit.write_text(markdown)
        print(f"wrote {args.write_audit}")


if __name__ == "__main__":
    main()
