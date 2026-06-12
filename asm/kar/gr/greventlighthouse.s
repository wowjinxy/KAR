.include "macros.inc"
.file "greventlighthouse.c"

# 0x80111F00..0x80111FB0 | size: 0xB0
.text
.balign 4

# .text:0x0 | 0x80111F00 | size: 0xB0
.fn kar_greventlighthouse_event_arm_kind68_handle_and_mark_param_vec, global
/* 80111F00 0010ED00  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80111F04 0010ED04  7C 08 02 A6 */	mflr r0
/* 80111F08 0010ED08  90 01 00 24 */	stw r0, 0x24(r1)
/* 80111F0C 0010ED0C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80111F10 0010ED10  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80111F14 0010ED14  7C 7E 1B 78 */	mr r30, r3
/* 80111F18 0010ED18  4B FD C8 25 */	bl kar_greventgenerator_get_current_event_param
/* 80111F1C 0010ED1C  80 8D 12 50 */	lwz r4, lbl_805DE330@sda21(r0)
/* 80111F20 0010ED20  7C 7F 1B 78 */	mr r31, r3
/* 80111F24 0010ED24  80 04 00 20 */	lwz r0, 0x20(r4)
/* 80111F28 0010ED28  90 0D 06 70 */	stw r0, lbl_805DD750@sda21(r0)
/* 80111F2C 0010ED2C  48 00 00 1C */	b .L_80111F48
.L_80111F30:
/* 80111F30 0010ED30  4B FE 5B 35 */	bl kar_gryakulib_get_yaku_data_checked
/* 80111F34 0010ED34  2C 03 00 44 */	cmpwi r3, 0x44
/* 80111F38 0010ED38  41 82 00 1C */	beq .L_80111F54
/* 80111F3C 0010ED3C  80 6D 06 70 */	lwz r3, lbl_805DD750@sda21(r0)
/* 80111F40 0010ED40  80 03 00 0C */	lwz r0, 0xc(r3)
/* 80111F44 0010ED44  90 0D 06 70 */	stw r0, lbl_805DD750@sda21(r0)
.L_80111F48:
/* 80111F48 0010ED48  80 6D 06 70 */	lwz r3, lbl_805DD750@sda21(r0)
/* 80111F4C 0010ED4C  28 03 00 00 */	cmplwi r3, 0x0
/* 80111F50 0010ED50  40 82 FF E0 */	bne .L_80111F30
.L_80111F54:
/* 80111F54 0010ED54  80 0D 06 70 */	lwz r0, lbl_805DD750@sda21(r0)
/* 80111F58 0010ED58  28 00 00 00 */	cmplwi r0, 0x0
/* 80111F5C 0010ED5C  40 82 00 1C */	bne .L_80111F78
/* 80111F60 0010ED60  3C 60 80 4A */	lis r3, kar_src_greventlighthouse_c@ha
/* 80111F64 0010ED64  3C A0 80 4A */	lis r5, kar_greventlighthouse_assert_lighthouse_gobj@ha
/* 80111F68 0010ED68  38 63 7A 20 */	addi r3, r3, kar_src_greventlighthouse_c@l
/* 80111F6C 0010ED6C  38 80 00 31 */	li r4, 0x31
/* 80111F70 0010ED70  38 A5 7A 34 */	addi r5, r5, kar_greventlighthouse_assert_lighthouse_gobj@l
/* 80111F74 0010ED74  48 31 65 45 */	bl __assert
.L_80111F78:
/* 80111F78 0010ED78  80 6D 06 70 */	lwz r3, lbl_805DD750@sda21(r0)
/* 80111F7C 0010ED7C  7F C4 F3 78 */	mr r4, r30
/* 80111F80 0010ED80  4B FF B7 41 */	bl kar_gryakubreakhpcoll_arm_kind68_lighthouse_event_handle
/* 80111F84 0010ED84  80 7F 00 00 */	lwz r3, 0x0(r31)
/* 80111F88 0010ED88  38 81 00 08 */	addi r4, r1, 0x8
/* 80111F8C 0010ED8C  4B FC 2C 69 */	bl kar_grcommon__near_800d4bf4
/* 80111F90 0010ED90  38 61 00 08 */	addi r3, r1, 0x8
/* 80111F94 0010ED94  48 00 20 7D */	bl fn_80114010
/* 80111F98 0010ED98  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80111F9C 0010ED9C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80111FA0 0010EDA0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80111FA4 0010EDA4  7C 08 03 A6 */	mtlr r0
/* 80111FA8 0010EDA8  38 21 00 20 */	addi r1, r1, 0x20
/* 80111FAC 0010EDAC  4E 80 00 20 */	blr
.endfn kar_greventlighthouse_event_arm_kind68_handle_and_mark_param_vec
