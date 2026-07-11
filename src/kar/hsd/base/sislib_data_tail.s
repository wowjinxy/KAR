.include "macros.inc"
.file "sislib_data_tail.s"

.data
.balign 8

	.global kar_debug_romfont_end_gcpmemcard_strings_80531e40
	.type kar_debug_romfont_end_gcpmemcard_strings_80531e40, @object
kar_debug_romfont_end_gcpmemcard_strings_80531e40:
.if BUILD_VERSION == 0
	.incbin "build/GKYE01/bin/kar/hsd/base/kar_debug_romfont_end_gcpmemcard_strings_80531e40.bin"
.endif
.if BUILD_VERSION == 1
	.incbin "build/GKYJ01/bin/kar/hsd/base/kar_debug_romfont_end_gcpmemcard_strings_80531e40.bin"
.endif
	.size kar_debug_romfont_end_gcpmemcard_strings_80531e40, . - kar_debug_romfont_end_gcpmemcard_strings_80531e40

	.hidden gap_07_80531E5D_data
	.type gap_07_80531E5D_data, @object
gap_07_80531E5D_data:
	.byte 0x00, 0x00, 0x00
	.size gap_07_80531E5D_data, . - gap_07_80531E5D_data

	.global lbl_80531E60
	.type lbl_80531E60, @object
lbl_80531E60:
.if BUILD_VERSION == 0
	.incbin "build/GKYE01/bin/kar/hsd/base/lbl_80531E60.bin"
.endif
.if BUILD_VERSION == 1
	.incbin "build/GKYJ01/bin/kar/hsd/base/lbl_80531E60.bin"
.endif
	.size lbl_80531E60, . - lbl_80531E60

	.global lbl_80531EB0
	.type lbl_80531EB0, @object
lbl_80531EB0:
.if BUILD_VERSION == 0
	.incbin "build/GKYE01/bin/kar/hsd/base/lbl_80531EB0.bin"
.endif
.if BUILD_VERSION == 1
	.incbin "build/GKYJ01/bin/kar/hsd/base/lbl_80531EB0.bin"
.endif
	.size lbl_80531EB0, . - lbl_80531EB0

	.global lbl_805320C4
	.type lbl_805320C4, @object
lbl_805320C4:
.if BUILD_VERSION == 0
	.incbin "build/GKYE01/bin/kar/hsd/base/lbl_805320C4.bin"
.endif
.if BUILD_VERSION == 1
	.incbin "build/GKYJ01/bin/kar/hsd/base/lbl_805320C4.bin"
.endif
	.size lbl_805320C4, . - lbl_805320C4

	.global lbl_8053210C
	.type lbl_8053210C, @object
lbl_8053210C:
.if BUILD_VERSION == 0
	.incbin "build/GKYE01/bin/kar/hsd/base/lbl_8053210C.bin"
.endif
.if BUILD_VERSION == 1
	.incbin "build/GKYJ01/bin/kar/hsd/base/lbl_8053210C.bin"
.endif
	.size lbl_8053210C, . - lbl_8053210C

	.hidden gap_07_8053213D_data
	.type gap_07_8053213D_data, @object
gap_07_8053213D_data:
	.byte 0x00, 0x00, 0x00
	.size gap_07_8053213D_data, . - gap_07_8053213D_data

	.global lbl_80532140
	.type lbl_80532140, @object
lbl_80532140:
.if BUILD_VERSION == 0
	.incbin "build/GKYE01/bin/kar/hsd/base/lbl_80532140.bin"
.endif
.if BUILD_VERSION == 1
	.incbin "build/GKYJ01/bin/kar/hsd/base/lbl_80532140.bin"
.endif
	.size lbl_80532140, . - lbl_80532140

	.hidden gap_07_80532169_data
	.type gap_07_80532169_data, @object
gap_07_80532169_data:
	.byte 0x00, 0x00, 0x00
	.size gap_07_80532169_data, . - gap_07_80532169_data

	.global lbl_8053216C
	.type lbl_8053216C, @object
lbl_8053216C:
.if BUILD_VERSION == 0
	.incbin "build/GKYE01/bin/kar/hsd/base/lbl_8053216C.bin"
.endif
.if BUILD_VERSION == 1
	.incbin "build/GKYJ01/bin/kar/hsd/base/lbl_8053216C.bin"
.endif
	.size lbl_8053216C, . - lbl_8053216C
