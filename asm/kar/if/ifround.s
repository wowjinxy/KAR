.include "macros.inc"
.file "ifround.c"

# 0x8011CFF0..0x8011D0D0 | size: 0xE0
.text
.balign 4

# .text:0x0 | 0x8011CFF0 | size: 0xE0
.fn kar_ifround_create_round_number_panel, global
/* 8011CFF0 00119DF0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8011CFF4 00119DF4  7C 08 02 A6 */	mflr r0
/* 8011CFF8 00119DF8  3C 80 80 4B */	lis r4, kar_ifround_round1_scene_models_name@ha
/* 8011CFFC 00119DFC  90 01 00 24 */	stw r0, 0x24(r1)
/* 8011D000 00119E00  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8011D004 00119E04  3B E4 83 78 */	addi r31, r4, kar_ifround_round1_scene_models_name@l
/* 8011D008 00119E08  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8011D00C 00119E0C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8011D010 00119E10  93 81 00 10 */	stw r28, 0x10(r1)
/* 8011D014 00119E14  7C 7C 1B 78 */	mr r28, r3
/* 8011D018 00119E18  4B FF 50 2D */	bl kar_greventlighthouse_get_ui_work_state_block
/* 8011D01C 00119E1C  7F 84 07 74 */	extsb r4, r28
/* 8011D020 00119E20  3B C3 07 14 */	addi r30, r3, 0x714
/* 8011D024 00119E24  2C 04 00 02 */	cmpwi r4, 0x2
/* 8011D028 00119E28  40 81 00 20 */	ble .L_8011D048
/* 8011D02C 00119E2C  38 7F 00 54 */	addi r3, r31, 0x54
/* 8011D030 00119E30  4C C6 31 82 */	crclr cr1eq
/* 8011D034 00119E34  48 2B 7C B5 */	bl OSReport
/* 8011D038 00119E38  38 7F 00 74 */	addi r3, r31, 0x74
/* 8011D03C 00119E3C  38 BF 00 80 */	addi r5, r31, 0x80
/* 8011D040 00119E40  38 80 00 75 */	li r4, 0x75
/* 8011D044 00119E44  48 30 B4 75 */	bl __assert
.L_8011D048:
/* 8011D048 00119E48  7F 80 07 74 */	extsb r0, r28
/* 8011D04C 00119E4C  38 80 00 1A */	li r4, 0x1a
/* 8011D050 00119E50  54 00 10 3A */	slwi r0, r0, 2
/* 8011D054 00119E54  38 A0 00 15 */	li r5, 0x15
/* 8011D058 00119E58  7F FE 00 2E */	lwzx r31, r30, r0
/* 8011D05C 00119E5C  38 C0 00 02 */	li r6, 0x2
/* 8011D060 00119E60  80 7F 00 00 */	lwz r3, 0x0(r31)
/* 8011D064 00119E64  80 63 00 00 */	lwz r3, 0x0(r3)
/* 8011D068 00119E68  4B FF 77 75 */	bl fn_801147DC
/* 8011D06C 00119E6C  3C 80 80 12 */	lis r4, kar_ifround_proc_update_round_number_panel@ha
/* 8011D070 00119E70  83 83 00 28 */	lwz r28, 0x28(r3)
/* 8011D074 00119E74  7C 7D 1B 78 */	mr r29, r3
/* 8011D078 00119E78  38 A0 00 14 */	li r5, 0x14
/* 8011D07C 00119E7C  38 84 CF 3C */	addi r4, r4, kar_ifround_proc_update_round_number_panel@l
/* 8011D080 00119E80  48 30 B8 25 */	bl HSD_GObjProcCreate
/* 8011D084 00119E84  80 9F 00 00 */	lwz r4, 0x0(r31)
/* 8011D088 00119E88  7F 83 E3 78 */	mr r3, r28
/* 8011D08C 00119E8C  C0 22 96 10 */	lfs f1, lbl_805DFD10@sda21(r0)
/* 8011D090 00119E90  C0 42 96 14 */	lfs f2, lbl_805DFD14@sda21(r0)
/* 8011D094 00119E94  4B FF 7D 09 */	bl fn_80114D9C
/* 8011D098 00119E98  7F A3 EB 78 */	mr r3, r29
/* 8011D09C 00119E9C  38 80 00 12 */	li r4, 0x12
/* 8011D0A0 00119EA0  38 A0 00 00 */	li r5, 0x0
/* 8011D0A4 00119EA4  38 C0 00 00 */	li r6, 0x0
/* 8011D0A8 00119EA8  4B FF 7D 7D */	bl kar_diag__80114e24
/* 8011D0AC 00119EAC  93 BE 00 0C */	stw r29, 0xc(r30)
/* 8011D0B0 00119EB0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8011D0B4 00119EB4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8011D0B8 00119EB8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8011D0BC 00119EBC  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8011D0C0 00119EC0  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8011D0C4 00119EC4  7C 08 03 A6 */	mtlr r0
/* 8011D0C8 00119EC8  38 21 00 20 */	addi r1, r1, 0x20
/* 8011D0CC 00119ECC  4E 80 00 20 */	blr
.endfn kar_ifround_create_round_number_panel
