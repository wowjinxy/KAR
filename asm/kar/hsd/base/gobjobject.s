.include "macros.inc"
.file "gobjobject.c"

# 0x80429C14..0x80429D0C | size: 0xF8
.text
.balign 4

# .text:0x0 | 0x80429C14 | size: 0x6C
.fn HSD_GObjObjectLink, global
/* 80429C14 00426A14  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80429C18 00426A18  7C 08 02 A6 */	mflr r0
/* 80429C1C 00426A1C  90 01 00 24 */	stw r0, 0x24(r1)
/* 80429C20 00426A20  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80429C24 00426A24  7C BF 2B 78 */	mr r31, r5
/* 80429C28 00426A28  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80429C2C 00426A2C  7C 9E 23 78 */	mr r30, r4
/* 80429C30 00426A30  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80429C34 00426A34  7C 7D 1B 78 */	mr r29, r3
/* 80429C38 00426A38  88 03 00 06 */	lbz r0, 0x6(r3)
/* 80429C3C 00426A3C  28 00 00 FF */	cmplwi r0, 0xff
/* 80429C40 00426A40  41 82 00 1C */	beq .L_80429C5C
/* 80429C44 00426A44  3C 60 80 50 */	lis r3, kar_src_gobjobject_80504e78@ha
/* 80429C48 00426A48  3C A0 80 50 */	lis r5, lbl_80504E88@ha
/* 80429C4C 00426A4C  38 63 4E 78 */	addi r3, r3, kar_src_gobjobject_80504e78@l
/* 80429C50 00426A50  38 80 00 2A */	li r4, 0x2a
/* 80429C54 00426A54  38 A5 4E 88 */	addi r5, r5, lbl_80504E88@l
/* 80429C58 00426A58  4B FF E8 61 */	bl __assert
.L_80429C5C:
/* 80429C5C 00426A5C  9B DD 00 06 */	stb r30, 0x6(r29)
/* 80429C60 00426A60  93 FD 00 28 */	stw r31, 0x28(r29)
/* 80429C64 00426A64  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80429C68 00426A68  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80429C6C 00426A6C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80429C70 00426A70  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80429C74 00426A74  7C 08 03 A6 */	mtlr r0
/* 80429C78 00426A78  38 21 00 20 */	addi r1, r1, 0x20
/* 80429C7C 00426A7C  4E 80 00 20 */	blr
.endfn HSD_GObjObjectLink

# .text:0x6C | 0x80429C80 | size: 0x30
.fn HSD_GObjObjectUnlink, global
/* 80429C80 00426A80  88 03 00 06 */	lbz r0, 0x6(r3)
/* 80429C84 00426A84  28 00 00 FF */	cmplwi r0, 0xff
/* 80429C88 00426A88  41 82 00 1C */	beq .L_80429CA4
/* 80429C8C 00426A8C  38 80 00 FF */	li r4, 0xff
/* 80429C90 00426A90  38 00 00 00 */	li r0, 0x0
/* 80429C94 00426A94  98 83 00 06 */	stb r4, 0x6(r3)
/* 80429C98 00426A98  80 83 00 28 */	lwz r4, 0x28(r3)
/* 80429C9C 00426A9C  90 03 00 28 */	stw r0, 0x28(r3)
/* 80429CA0 00426AA0  48 00 00 08 */	b .L_80429CA8
.L_80429CA4:
/* 80429CA4 00426AA4  38 80 00 00 */	li r4, 0x0
.L_80429CA8:
/* 80429CA8 00426AA8  7C 83 23 78 */	mr r3, r4
/* 80429CAC 00426AAC  4E 80 00 20 */	blr
.endfn HSD_GObjObjectUnlink

# .text:0x9C | 0x80429CB0 | size: 0x5C
.fn HSD_GObjObjectRemove, global
/* 80429CB0 00426AB0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80429CB4 00426AB4  7C 08 02 A6 */	mflr r0
/* 80429CB8 00426AB8  90 01 00 14 */	stw r0, 0x14(r1)
/* 80429CBC 00426ABC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80429CC0 00426AC0  7C 7F 1B 78 */	mr r31, r3
/* 80429CC4 00426AC4  88 03 00 06 */	lbz r0, 0x6(r3)
/* 80429CC8 00426AC8  28 00 00 FF */	cmplwi r0, 0xff
/* 80429CCC 00426ACC  41 82 00 2C */	beq .L_80429CF8
/* 80429CD0 00426AD0  80 8D 12 38 */	lwz r4, lbl_805DE318@sda21(r0)
/* 80429CD4 00426AD4  54 00 15 BA */	clrlslwi r0, r0, 24, 2
/* 80429CD8 00426AD8  80 7F 00 28 */	lwz r3, 0x28(r31)
/* 80429CDC 00426ADC  7D 84 00 2E */	lwzx r12, r4, r0
/* 80429CE0 00426AE0  7D 89 03 A6 */	mtctr r12
/* 80429CE4 00426AE4  4E 80 04 21 */	bctrl
/* 80429CE8 00426AE8  38 60 00 FF */	li r3, 0xff
/* 80429CEC 00426AEC  38 00 00 00 */	li r0, 0x0
/* 80429CF0 00426AF0  98 7F 00 06 */	stb r3, 0x6(r31)
/* 80429CF4 00426AF4  90 1F 00 28 */	stw r0, 0x28(r31)
.L_80429CF8:
/* 80429CF8 00426AF8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80429CFC 00426AFC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80429D00 00426B00  7C 08 03 A6 */	mtlr r0
/* 80429D04 00426B04  38 21 00 10 */	addi r1, r1, 0x10
/* 80429D08 00426B08  4E 80 00 20 */	blr
.endfn HSD_GObjObjectRemove

# 0x80504E78..0x80504EB0 | size: 0x38
.data
.balign 8

# .data:0x0 | 0x80504E78 | size: 0xD
.obj kar_src_gobjobject_80504e78, global
	.string "gobjobject.c"
.endobj kar_src_gobjobject_80504e78

# .data:0xD | 0x80504E85 | size: 0x3
.obj gap_07_80504E85_data, global
.hidden gap_07_80504E85_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_80504E85_data

# .data:0x10 | 0x80504E88 | size: 0x24
.obj lbl_80504E88, global
	.string "gobj->obj_kind == HSD_GOBJ_OBJ_NONE"
.endobj lbl_80504E88

# .data:0x34 | 0x80504EAC | size: 0x4
.obj gap_07_80504EAC_data, global
.hidden gap_07_80504EAC_data
	.4byte 0x00000000
.endobj gap_07_80504EAC_data
