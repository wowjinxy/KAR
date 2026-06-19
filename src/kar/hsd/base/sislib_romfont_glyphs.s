.include "macros.inc"
.file "sislib_romfont_glyphs.s"

.data
.balign 8

	.global kar_sislib_romfont_glyphs_i4_32x32
	.type kar_sislib_romfont_glyphs_i4_32x32, @object
kar_sislib_romfont_glyphs_i4_32x32:
	.incbin "build/GKYE01/bin/kar/hsd/base/sislib_romfont_glyphs_i4_32x32.bin"
	.size kar_sislib_romfont_glyphs_i4_32x32, . - kar_sislib_romfont_glyphs_i4_32x32
