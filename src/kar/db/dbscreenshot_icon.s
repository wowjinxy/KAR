.include "macros.inc"
.file "dbscreenshot_icon.s"

.data
.balign 8

# Two 32x32 RGB5A3 debug screenshot/save icon frames.
	.global kar_dbscreenshot_save_icon_rgb5a3
	.type kar_dbscreenshot_save_icon_rgb5a3, @object
kar_dbscreenshot_save_icon_rgb5a3:
	.incbin "assets/kar/db/dbscreenshot_icon_rgb5a3.bin"
	.size kar_dbscreenshot_save_icon_rgb5a3, . - kar_dbscreenshot_save_icon_rgb5a3
