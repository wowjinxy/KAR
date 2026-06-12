.include "macros.inc"
.file "gobjobject.c"

# 0x80429C14..0x80429C80 | size: 0x6C
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
