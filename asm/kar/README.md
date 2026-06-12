# KAR assembly overrides

Non-matching assembly overrides live here using the same area layout as the
KAR source map in `configure.py`. For example:

```text
asm/kar/gm/gmmain.s
asm/kar/gr/grcity1.s
asm/kar/hsd/base/initialize.s
```

The split object names in `config/*/splits.txt` remain flat so decomp-toolkit
can continue matching the generated units.
