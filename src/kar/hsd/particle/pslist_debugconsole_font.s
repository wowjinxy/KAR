.include "macros.inc"
.file "pslist_debugconsole_font.s"

.data
.balign 8

	.global kar_debugconsole_font_i4_8x14
	.type kar_debugconsole_font_i4_8x14, @object
kar_debugconsole_font_i4_8x14:
.if BUILD_VERSION == 0
	.incbin "build/GKYE01/bin/kar/debug/debugconsole_font_i4_8x14.bin"
.endif
.if BUILD_VERSION == 1
	.incbin "build/GKYJ01/bin/kar/debug/debugconsole_font_i4_8x14.bin"
.endif
.if BUILD_VERSION == 2
	.incbin "build/GKYP01/bin/kar/debug/debugconsole_font_i4_8x14.bin"
.endif
	.size kar_debugconsole_font_i4_8x14, . - kar_debugconsole_font_i4_8x14
