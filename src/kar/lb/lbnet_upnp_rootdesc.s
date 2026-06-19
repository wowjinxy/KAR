.include "macros.inc"
.file "lbnet_upnp_rootdesc.s"

.data
.balign 8

	.global kar_upnp_rootdesc_xml_8049ae10
	.type kar_upnp_rootdesc_xml_8049ae10, @object
kar_upnp_rootdesc_xml_8049ae10:
	.incbin "assets/kar/lb/lbnet/upnp_rootdesc.xml"
	.byte 0x00
	.size kar_upnp_rootdesc_xml_8049ae10, . - kar_upnp_rootdesc_xml_8049ae10
	.balign 8
