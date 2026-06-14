.section .bss
.balign 4

# MWCC emits lbarealightzone.c's BSS contribution with 8-byte alignment, but
# the original object starts this block at 0x805529A4. Keep these storage
# symbols in asm so the BSS block stays 4-byte aligned and matches the DOL.
.global lbl_805529A4
lbl_805529A4:
    .skip 0x2C

.global lbl_805529D0
lbl_805529D0:
    .skip 0x30

.global lbl_80552A00
lbl_80552A00:
    .skip 0x30
