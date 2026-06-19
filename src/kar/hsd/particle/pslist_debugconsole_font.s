.include "macros.inc"
.file "pslist_debugconsole_font.s"

.data
.balign 8

	.global kar_debugconsole_font_i4_8x14
	.type kar_debugconsole_font_i4_8x14, @object
kar_debugconsole_font_i4_8x14:
	.incbin "build/GKYE01/bin/kar/debug/debugconsole_font_i4_8x14.bin"
	.size kar_debugconsole_font_i4_8x14, . - kar_debugconsole_font_i4_8x14
