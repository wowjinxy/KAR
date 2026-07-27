# Decompilation source quality

KAR source should explain the recovered program, not manipulate the compiler
through opaque source tricks.

## Required practice

- Model known layouts with named structs, unions, and fields.
- Use a small typed view when only part of a layout is understood.
- Leave honest work marked `NONMATCHING` while its code generation is still
  being investigated.
- Keep version-specific names and constants explicit.

## Prohibited practice

- Generic byte-offset access macros such as `GET_U32`, `LOAD_F32`, `FIELD`, or
  domain-named equivalents.
- Cast-through-address wrappers that force a scalar load only to change code
  generation.
- Dead locals, fake branches, volatile qualifiers, or other constructs added
  only to influence register allocation or instruction selection.
- Hiding an unknown layout behind repeated untyped pointer arithmetic when a
  typed partial view can document the same knowledge.

Run `python tools/check_decomp_source_quality.py` before submitting changes.
CI runs the same check.

The low-level networking sources have a frozen set of legacy accessor macros
for byte-oriented protocol structures. The check names every exception by file
and macro: the list may shrink, but new exceptions must not be added.
