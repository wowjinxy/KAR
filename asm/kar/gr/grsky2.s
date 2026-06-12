.include "macros.inc"
.file "grsky2.c"

# 0x8010EC10..0x8010EC90 | size: 0x80
.text
.balign 4

# .text:0x0 | 0x8010EC10 | size: 0x80
.fn kar_grsky2_init_loop_anim, global
/* 8010EC10 0010BA10  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010EC14 0010BA14  7C 08 02 A6 */	mflr r0
/* 8010EC18 0010BA18  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010EC1C 0010BA1C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010EC20 0010BA20  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8010EC24 0010BA24  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8010EC28 0010BA28  38 60 00 00 */	li r3, 0x0
/* 8010EC2C 0010BA2C  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 8010EC30 0010BA30  83 C4 00 08 */	lwz r30, 0x8(r4)
/* 8010EC34 0010BA34  28 1E 00 00 */	cmplwi r30, 0x0
/* 8010EC38 0010BA38  41 82 00 14 */	beq .L_8010EC4C
/* 8010EC3C 0010BA3C  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 8010EC40 0010BA40  28 00 00 00 */	cmplwi r0, 0x0
/* 8010EC44 0010BA44  41 82 00 08 */	beq .L_8010EC4C
/* 8010EC48 0010BA48  38 60 00 01 */	li r3, 0x1
.L_8010EC4C:
/* 8010EC4C 0010BA4C  2C 03 00 00 */	cmpwi r3, 0x0
/* 8010EC50 0010BA50  40 82 00 1C */	bne .L_8010EC6C
/* 8010EC54 0010BA54  3C 60 80 4A */	lis r3, kar_src_grsky2_c@ha
/* 8010EC58 0010BA58  3C A0 80 4A */	lis r5, kar_grsky2_assert_loop_anim_param_present@ha
/* 8010EC5C 0010BA5C  38 63 77 3C */	addi r3, r3, kar_src_grsky2_c@l
/* 8010EC60 0010BA60  38 80 00 28 */	li r4, 0x28
/* 8010EC64 0010BA64  38 A5 77 48 */	addi r5, r5, kar_grsky2_assert_loop_anim_param_present@l
/* 8010EC68 0010BA68  48 31 98 51 */	bl __assert
.L_8010EC6C:
/* 8010EC6C 0010BA6C  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 8010EC70 0010BA70  7F E3 FB 78 */	mr r3, r31
/* 8010EC74 0010BA74  4B FC D1 D5 */	bl kar_granim__800dbe48
/* 8010EC78 0010BA78  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010EC7C 0010BA7C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010EC80 0010BA80  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8010EC84 0010BA84  7C 08 03 A6 */	mtlr r0
/* 8010EC88 0010BA88  38 21 00 10 */	addi r1, r1, 0x10
/* 8010EC8C 0010BA8C  4E 80 00 20 */	blr
.endfn kar_grsky2_init_loop_anim
