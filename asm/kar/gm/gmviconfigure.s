.include "macros.inc"
.file "gmviconfigure.c"

# 0x8004F5E0..0x8004F85C | size: 0x27C
.text
.balign 4

# .text:0x0 | 0x8004F5E0 | size: 0x74
.fn kar_gmviconfigure__near_8004f5e0, global
/* 8004F5E0 0004C3E0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8004F5E4 0004C3E4  7C 08 02 A6 */	mflr r0
/* 8004F5E8 0004C3E8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8004F5EC 0004C3EC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8004F5F0 0004C3F0  7C 7F 1B 78 */	mr r31, r3
/* 8004F5F4 0004C3F4  2C 1F 00 03 */	cmpwi r31, 0x3
/* 8004F5F8 0004C3F8  41 80 00 18 */	blt .L_8004F610
/* 8004F5FC 0004C3FC  3C 60 80 49 */	lis r3, kar_srcfile_gmviconfigure_c_80497ba8@ha
/* 8004F600 0004C400  38 80 00 A7 */	li r4, 0xa7
/* 8004F604 0004C404  38 63 7B A8 */	addi r3, r3, kar_srcfile_gmviconfigure_c_80497ba8@l
/* 8004F608 0004C408  38 AD 80 F8 */	li r5, lbl_805D51D8@sda21
/* 8004F60C 0004C40C  48 3D 8E AD */	bl __assert
.L_8004F610:
/* 8004F610 0004C410  2C 1F 00 03 */	cmpwi r31, 0x3
/* 8004F614 0004C414  41 80 00 18 */	blt .L_8004F62C
/* 8004F618 0004C418  3C 60 80 49 */	lis r3, kar_srcfile_gmviconfigure_c_80497ba8@ha
/* 8004F61C 0004C41C  38 80 00 86 */	li r4, 0x86
/* 8004F620 0004C420  38 63 7B A8 */	addi r3, r3, kar_srcfile_gmviconfigure_c_80497ba8@l
/* 8004F624 0004C424  38 AD 80 F8 */	li r5, lbl_805D51D8@sda21
/* 8004F628 0004C428  48 3D 8E 91 */	bl __assert
.L_8004F62C:
/* 8004F62C 0004C42C  3C 60 80 49 */	lis r3, lbl_80497B9C@ha
/* 8004F630 0004C430  57 E0 10 3A */	slwi r0, r31, 2
/* 8004F634 0004C434  38 63 7B 9C */	addi r3, r3, lbl_80497B9C@l
/* 8004F638 0004C438  7C 63 00 2E */	lwzx r3, r3, r0
/* 8004F63C 0004C43C  48 3C 23 A9 */	bl HSD_VISetConfigure
/* 8004F640 0004C440  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8004F644 0004C444  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8004F648 0004C448  7C 08 03 A6 */	mtlr r0
/* 8004F64C 0004C44C  38 21 00 10 */	addi r1, r1, 0x10
/* 8004F650 0004C450  4E 80 00 20 */	blr
.endfn kar_gmviconfigure__near_8004f5e0

# .text:0x74 | 0x8004F654 | size: 0xC0
.fn kar_gmviconfigure__near_8004f654, global
/* 8004F654 0004C454  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8004F658 0004C458  7C 08 02 A6 */	mflr r0
/* 8004F65C 0004C45C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8004F660 0004C460  39 61 00 20 */	addi r11, r1, 0x20
/* 8004F664 0004C464  48 35 E4 ED */	bl _savegpr_26
/* 8004F668 0004C468  48 02 BF E9 */	bl kar_shadow__near_8007b650
/* 8004F66C 0004C46C  2C 03 00 00 */	cmpwi r3, 0x0
/* 8004F670 0004C470  40 82 00 8C */	bne .L_8004F6FC
/* 8004F674 0004C474  3C 60 80 49 */	lis r3, lbl_804895D8@ha
/* 8004F678 0004C478  3C 80 80 53 */	lis r4, lbl_80537430@ha
/* 8004F67C 0004C47C  3B 63 95 D8 */	addi r27, r3, lbl_804895D8@l
/* 8004F680 0004C480  83 9B 00 00 */	lwz r28, 0x0(r27)
/* 8004F684 0004C484  3B 44 74 30 */	addi r26, r4, lbl_80537430@l
/* 8004F688 0004C488  83 BB 00 04 */	lwz r29, 0x4(r27)
/* 8004F68C 0004C48C  83 DB 00 08 */	lwz r30, 0x8(r27)
/* 8004F690 0004C490  83 FB 00 0C */	lwz r31, 0xc(r27)
/* 8004F694 0004C494  81 9B 00 10 */	lwz r12, 0x10(r27)
/* 8004F698 0004C498  81 7B 00 14 */	lwz r11, 0x14(r27)
/* 8004F69C 0004C49C  81 5B 00 18 */	lwz r10, 0x18(r27)
/* 8004F6A0 0004C4A0  81 3B 00 1C */	lwz r9, 0x1c(r27)
/* 8004F6A4 0004C4A4  81 1B 00 20 */	lwz r8, 0x20(r27)
/* 8004F6A8 0004C4A8  80 FB 00 24 */	lwz r7, 0x24(r27)
/* 8004F6AC 0004C4AC  80 DB 00 28 */	lwz r6, 0x28(r27)
/* 8004F6B0 0004C4B0  80 BB 00 2C */	lwz r5, 0x2c(r27)
/* 8004F6B4 0004C4B4  80 9B 00 30 */	lwz r4, 0x30(r27)
/* 8004F6B8 0004C4B8  80 7B 00 34 */	lwz r3, 0x34(r27)
/* 8004F6BC 0004C4BC  80 1B 00 38 */	lwz r0, 0x38(r27)
/* 8004F6C0 0004C4C0  93 9A 00 00 */	stw r28, 0x0(r26)
/* 8004F6C4 0004C4C4  93 BA 00 04 */	stw r29, 0x4(r26)
/* 8004F6C8 0004C4C8  93 DA 00 08 */	stw r30, 0x8(r26)
/* 8004F6CC 0004C4CC  93 FA 00 0C */	stw r31, 0xc(r26)
/* 8004F6D0 0004C4D0  91 9A 00 10 */	stw r12, 0x10(r26)
/* 8004F6D4 0004C4D4  91 7A 00 14 */	stw r11, 0x14(r26)
/* 8004F6D8 0004C4D8  91 5A 00 18 */	stw r10, 0x18(r26)
/* 8004F6DC 0004C4DC  91 3A 00 1C */	stw r9, 0x1c(r26)
/* 8004F6E0 0004C4E0  91 1A 00 20 */	stw r8, 0x20(r26)
/* 8004F6E4 0004C4E4  90 FA 00 24 */	stw r7, 0x24(r26)
/* 8004F6E8 0004C4E8  90 DA 00 28 */	stw r6, 0x28(r26)
/* 8004F6EC 0004C4EC  90 BA 00 2C */	stw r5, 0x2c(r26)
/* 8004F6F0 0004C4F0  90 9A 00 30 */	stw r4, 0x30(r26)
/* 8004F6F4 0004C4F4  90 7A 00 34 */	stw r3, 0x34(r26)
/* 8004F6F8 0004C4F8  90 1A 00 38 */	stw r0, 0x38(r26)
.L_8004F6FC:
/* 8004F6FC 0004C4FC  39 61 00 20 */	addi r11, r1, 0x20
/* 8004F700 0004C500  48 35 E4 9D */	bl _restgpr_26
/* 8004F704 0004C504  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8004F708 0004C508  7C 08 03 A6 */	mtlr r0
/* 8004F70C 0004C50C  38 21 00 20 */	addi r1, r1, 0x20
/* 8004F710 0004C510  4E 80 00 20 */	blr
.endfn kar_gmviconfigure__near_8004f654

# .text:0x134 | 0x8004F714 | size: 0x68
.fn kar_gmviconfigure__near_8004f714, global
/* 8004F714 0004C514  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8004F718 0004C518  7C 08 02 A6 */	mflr r0
/* 8004F71C 0004C51C  3C 60 80 53 */	lis r3, lbl_80537430@ha
/* 8004F720 0004C520  90 01 00 14 */	stw r0, 0x14(r1)
/* 8004F724 0004C524  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8004F728 0004C528  3B E3 74 30 */	addi r31, r3, lbl_80537430@l
/* 8004F72C 0004C52C  88 1F 00 11 */	lbz r0, 0x11(r31)
/* 8004F730 0004C530  7C 00 07 75 */	extsb. r0, r0
/* 8004F734 0004C534  41 82 00 18 */	beq .L_8004F74C
/* 8004F738 0004C538  38 60 00 00 */	li r3, 0x0
/* 8004F73C 0004C53C  38 00 00 01 */	li r0, 0x1
/* 8004F740 0004C540  98 7F 00 11 */	stb r3, 0x11(r31)
/* 8004F744 0004C544  98 1F 00 10 */	stb r0, 0x10(r31)
/* 8004F748 0004C548  48 00 00 20 */	b .L_8004F768
.L_8004F74C:
/* 8004F74C 0004C54C  88 1F 00 10 */	lbz r0, 0x10(r31)
/* 8004F750 0004C550  7C 00 07 75 */	extsb. r0, r0
/* 8004F754 0004C554  41 82 00 14 */	beq .L_8004F768
/* 8004F758 0004C558  38 60 00 28 */	li r3, 0x28
/* 8004F75C 0004C55C  4B FB 91 6D */	bl kar_gmglobal__near_800088c8
/* 8004F760 0004C560  38 00 00 00 */	li r0, 0x0
/* 8004F764 0004C564  98 1F 00 10 */	stb r0, 0x10(r31)
.L_8004F768:
/* 8004F768 0004C568  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8004F76C 0004C56C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8004F770 0004C570  7C 08 03 A6 */	mtlr r0
/* 8004F774 0004C574  38 21 00 10 */	addi r1, r1, 0x10
/* 8004F778 0004C578  4E 80 00 20 */	blr
.endfn kar_gmviconfigure__near_8004f714

# .text:0x19C | 0x8004F77C | size: 0xC0
.fn kar_gmviconfigure__near_8004f77c, global
/* 8004F77C 0004C57C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8004F780 0004C580  7C 08 02 A6 */	mflr r0
/* 8004F784 0004C584  3C 60 80 53 */	lis r3, lbl_80537430@ha
/* 8004F788 0004C588  90 01 00 14 */	stw r0, 0x14(r1)
/* 8004F78C 0004C58C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8004F790 0004C590  3B E3 74 30 */	addi r31, r3, lbl_80537430@l
/* 8004F794 0004C594  48 0E 99 4D */	bl fn_801390E0
/* 8004F798 0004C598  48 0E 99 F1 */	bl fn_80139188
/* 8004F79C 0004C59C  48 0E 9A 2D */	bl fn_801391C8
/* 8004F7A0 0004C5A0  48 13 3B 25 */	bl kar_gmlanmenu_show_lan_bg_panel
/* 8004F7A4 0004C5A4  48 13 40 A1 */	bl kar_mnlannumber_show_panel
/* 8004F7A8 0004C5A8  48 13 4B 95 */	bl kar_mnlandialogue_show_panel
/* 8004F7AC 0004C5AC  48 13 50 7D */	bl kar_mnlandialogue_show_connect_panel
/* 8004F7B0 0004C5B0  48 13 54 5D */	bl kar_mnlandialogue_show_wait_panel
/* 8004F7B4 0004C5B4  48 13 56 DD */	bl kar_mnlandialogue_show_select_panel
/* 8004F7B8 0004C5B8  48 13 58 F1 */	bl kar_mnlandialogue_show_airride_panel
/* 8004F7BC 0004C5BC  48 13 5B 9D */	bl kar_mnlandialogue_show_city_panel
/* 8004F7C0 0004C5C0  48 13 5E 95 */	bl kar_mnlandialogue_show_time_panel
/* 8004F7C4 0004C5C4  38 60 00 07 */	li r3, 0x7
/* 8004F7C8 0004C5C8  48 12 D1 45 */	bl kar_gmlanmenu_set_sis_lan_box0_message_id_adjusted
/* 8004F7CC 0004C5CC  38 60 00 07 */	li r3, 0x7
/* 8004F7D0 0004C5D0  48 12 D1 C1 */	bl kar_gmlanmenu_set_sis_lan_box1_message_id
/* 8004F7D4 0004C5D4  38 60 00 07 */	li r3, 0x7
/* 8004F7D8 0004C5D8  48 12 D2 61 */	bl kar_gmlanmenu_set_sis_lan_box4_message_id
/* 8004F7DC 0004C5DC  38 60 00 07 */	li r3, 0x7
/* 8004F7E0 0004C5E0  48 12 D1 E9 */	bl kar_gmlanmenu_set_sis_lan_box2_message_id
/* 8004F7E4 0004C5E4  38 60 00 07 */	li r3, 0x7
/* 8004F7E8 0004C5E8  48 12 D2 19 */	bl kar_gmlanmenu_set_sis_lan_box3_message_id
/* 8004F7EC 0004C5EC  48 13 4D 45 */	bl kar_mnlandialogue_request_connect_panel_state0_anim
/* 8004F7F0 0004C5F0  48 02 32 B1 */	bl kar_lbkdcoll__near_80072aa0
/* 8004F7F4 0004C5F4  48 02 32 75 */	bl kar_lbfile_wait_for_group6_loads
/* 8004F7F8 0004C5F8  48 1E 31 65 */	bl kar_pltrick__near_8023295c
/* 8004F7FC 0004C5FC  48 22 7F 4D */	bl kar_gmlanmenu__80277748
/* 8004F800 0004C600  3C 60 80 53 */	lis r3, lbl_80537430@ha
/* 8004F804 0004C604  38 63 74 30 */	addi r3, r3, lbl_80537430@l
/* 8004F808 0004C608  80 03 00 14 */	lwz r0, 0x14(r3)
/* 8004F80C 0004C60C  2C 00 00 02 */	cmpwi r0, 0x2
/* 8004F810 0004C610  40 82 00 18 */	bne .L_8004F828
/* 8004F814 0004C614  48 02 95 11 */	bl kar_lbhvqm__near_80078d24
/* 8004F818 0004C618  2C 03 00 00 */	cmpwi r3, 0x0
/* 8004F81C 0004C61C  40 82 00 0C */	bne .L_8004F828
/* 8004F820 0004C620  38 00 00 01 */	li r0, 0x1
/* 8004F824 0004C624  90 1F 00 14 */	stw r0, 0x14(r31)
.L_8004F828:
/* 8004F828 0004C628  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8004F82C 0004C62C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8004F830 0004C630  7C 08 03 A6 */	mtlr r0
/* 8004F834 0004C634  38 21 00 10 */	addi r1, r1, 0x10
/* 8004F838 0004C638  4E 80 00 20 */	blr
.endfn kar_gmviconfigure__near_8004f77c

# .text:0x25C | 0x8004F83C | size: 0x20
.fn kar_gmviconfigure__near_8004f83c, global
/* 8004F83C 0004C63C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8004F840 0004C640  7C 08 02 A6 */	mflr r0
/* 8004F844 0004C644  90 01 00 14 */	stw r0, 0x14(r1)
/* 8004F848 0004C648  48 0E 99 A9 */	bl fn_801391F0
/* 8004F84C 0004C64C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8004F850 0004C650  7C 08 03 A6 */	mtlr r0
/* 8004F854 0004C654  38 21 00 10 */	addi r1, r1, 0x10
/* 8004F858 0004C658  4E 80 00 20 */	blr
.endfn kar_gmviconfigure__near_8004f83c

# 0x80489480..0x80489618 | size: 0x198
.rodata
.balign 8

# .rodata:0x0 | 0x80489480 | size: 0x20
.obj lbl_80489480, global
	.4byte 0xFFAABD00
	.4byte 0xFFE85200
	.4byte 0x5AC9FF00
	.4byte 0xA8FA8200
	.4byte 0xFFFFFF00
	.4byte 0xE260FF00
	.4byte 0x5E3D2500
	.4byte 0xFF293600
.endobj lbl_80489480

# .rodata:0x20 | 0x804894A0 | size: 0x4C
.obj lbl_804894A0, global
	.4byte 0x3FEF5C29
	.4byte 0x3FEF5C29
	.4byte 0x3FEF5C29
	.4byte 0x3FEF5C29
	.4byte 0x40666666
	.4byte 0x40933333
	.4byte 0x400CCCCD
	.4byte 0x4019999A
	.4byte 0x40C00000
	.4byte 0x41066666
	.4byte 0x3FEF5C29
	.4byte 0x40400000
	.4byte 0x3FEF5C29
	.4byte 0x403A5E35
	.4byte 0x3FEF5C29
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804894A0

# .rodata:0x6C | 0x804894EC | size: 0x1C
.obj lbl_804894EC, global
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x40E66666
	.4byte 0x41499999
	.4byte 0x40A66666
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804894EC

# .rodata:0x88 | 0x80489508 | size: 0x28
.obj lbl_80489508, global
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x3F800000
	.4byte 0x00000000
	.4byte 0x3F800000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_80489508

# .rodata:0xB0 | 0x80489530 | size: 0x28
.obj lbl_80489530, global
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x3F800000
	.4byte 0x00000000
	.4byte 0x3F800000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_80489530

# .rodata:0xD8 | 0x80489558 | size: 0x80
.obj lbl_80489558, global
	.4byte 0x40BBD70A
	.4byte 0x40BBD70A
	.4byte 0x40BBD70A
	.4byte 0x40BBD70A
	.4byte 0x40666666
	.4byte 0x40A66666
	.4byte 0x40BBD70A
	.4byte 0x40BBD70A
	.4byte 0x40C00000
	.4byte 0x41066666
	.4byte 0x40BBD70A
	.4byte 0x40DBD70A
	.4byte 0x40BBD70A
	.4byte 0x40BBD70A
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x41000000
	.4byte 0x41400000
	.4byte 0x41100000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x3F800000
	.4byte 0x00000000
	.4byte 0x3F800000
	.4byte 0x00000000
.endobj lbl_80489558

# .rodata:0x158 | 0x804895D8 | size: 0x40
.obj lbl_804895D8, global
	.4byte 0x01010000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000002
	.4byte 0x00000002
	.4byte 0x00000001
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000001
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804895D8

# 0x80497BA8..0x80497BB8 | size: 0x10
.data
.balign 8

# .data:0x0 | 0x80497BA8 | size: 0x10
.obj kar_srcfile_gmviconfigure_c_80497ba8, global
	.string "gmviconfigure.c"
.endobj kar_srcfile_gmviconfigure_c_80497ba8

# 0x80537430..0x80537470 | size: 0x40
.section .bss, "wa", @nobits
.balign 8

# .bss:0x0 | 0x80537430 | size: 0x40
.obj lbl_80537430, global
	.skip 0x40
.endobj lbl_80537430

# 0x805D51D8..0x805D51E0 | size: 0x8
.section .sdata, "wa"
.balign 8

# .sdata:0x0 | 0x805D51D8 | size: 0x2
.obj lbl_805D51D8, global
	.string "0"
.endobj lbl_805D51D8

# .sdata:0x2 | 0x805D51DA | size: 0x6
.obj gap_09_805D51DA_sdata, global
.hidden gap_09_805D51DA_sdata
	.4byte 0x00000000
	.2byte 0x0000
.endobj gap_09_805D51DA_sdata
