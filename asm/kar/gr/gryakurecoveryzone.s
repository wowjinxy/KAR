.include "macros.inc"
.file "gryakurecoveryzone.c"

# 0x800FAC9C..0x800FC0F0 | size: 0x1454
.text
.balign 4

# .text:0x0 | 0x800FAC9C | size: 0x24C
.fn kar_gryakurecoveryzone_enter_recovery_sequence, global
/* 800FAC9C 000F7A9C  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800FACA0 000F7AA0  7C 08 02 A6 */	mflr r0
/* 800FACA4 000F7AA4  90 01 00 34 */	stw r0, 0x34(r1)
/* 800FACA8 000F7AA8  39 61 00 30 */	addi r11, r1, 0x30
/* 800FACAC 000F7AAC  48 2B 2E A9 */	bl _savegpr_27
/* 800FACB0 000F7AB0  7C 7F 1B 78 */	mr r31, r3
/* 800FACB4 000F7AB4  83 83 00 2C */	lwz r28, 0x2c(r3)
/* 800FACB8 000F7AB8  80 9C 00 08 */	lwz r4, 0x8(r28)
/* 800FACBC 000F7ABC  80 7C 00 64 */	lwz r3, 0x64(r28)
/* 800FACC0 000F7AC0  83 C4 00 00 */	lwz r30, 0x0(r4)
/* 800FACC4 000F7AC4  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 800FACC8 000F7AC8  54 00 18 38 */	slwi r0, r0, 3
/* 800FACCC 000F7ACC  7C 63 00 2E */	lwzx r3, r3, r0
/* 800FACD0 000F7AD0  4B F5 9B 11 */	bl kar_gmlanmenu__near_800547e0
/* 800FACD4 000F7AD4  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FACD8 000F7AD8  40 82 01 F8 */	bne .L_800FAED0
/* 800FACDC 000F7ADC  80 1E 00 24 */	lwz r0, 0x24(r30)
/* 800FACE0 000F7AE0  2C 00 00 03 */	cmpwi r0, 0x3
/* 800FACE4 000F7AE4  40 81 00 1C */	ble .L_800FAD00
/* 800FACE8 000F7AE8  3C 60 80 4A */	lis r3, kar_src_gryakurecoveryzone_c@ha
/* 800FACEC 000F7AEC  3C A0 80 4A */	lis r5, kar_gryakurecoveryzone_assert_effect_loop_count@ha
/* 800FACF0 000F7AF0  38 63 60 44 */	addi r3, r3, kar_src_gryakurecoveryzone_c@l
/* 800FACF4 000F7AF4  38 80 01 2E */	li r4, 0x12e
/* 800FACF8 000F7AF8  38 A5 60 5C */	addi r5, r5, kar_gryakurecoveryzone_assert_effect_loop_count@l
/* 800FACFC 000F7AFC  48 32 D7 BD */	bl __assert
.L_800FAD00:
/* 800FAD00 000F7B00  7F 9D E3 78 */	mr r29, r28
/* 800FAD04 000F7B04  3B 60 00 00 */	li r27, 0x0
/* 800FAD08 000F7B08  3B 80 00 00 */	li r28, 0x0
/* 800FAD0C 000F7B0C  48 00 00 3C */	b .L_800FAD48
.L_800FAD10:
/* 800FAD10 000F7B10  80 1E 00 20 */	lwz r0, 0x20(r30)
/* 800FAD14 000F7B14  7F E3 FB 78 */	mr r3, r31
/* 800FAD18 000F7B18  80 BE 00 00 */	lwz r5, 0x0(r30)
/* 800FAD1C 000F7B1C  38 C0 00 00 */	li r6, 0x0
/* 800FAD20 000F7B20  7C 80 E2 14 */	add r4, r0, r28
/* 800FAD24 000F7B24  38 E0 00 00 */	li r7, 0x0
/* 800FAD28 000F7B28  39 00 00 00 */	li r8, 0x0
/* 800FAD2C 000F7B2C  39 20 00 01 */	li r9, 0x1
/* 800FAD30 000F7B30  4B FF C3 15 */	bl kar_gryakueffect_request_by_entry_mode
/* 800FAD34 000F7B34  90 9D 01 44 */	stw r4, 0x144(r29)
/* 800FAD38 000F7B38  3B 9C 00 1C */	addi r28, r28, 0x1c
/* 800FAD3C 000F7B3C  3B 7B 00 01 */	addi r27, r27, 0x1
/* 800FAD40 000F7B40  90 7D 01 40 */	stw r3, 0x140(r29)
/* 800FAD44 000F7B44  3B BD 00 08 */	addi r29, r29, 0x8
.L_800FAD48:
/* 800FAD48 000F7B48  80 1E 00 24 */	lwz r0, 0x24(r30)
/* 800FAD4C 000F7B4C  7C 1B 00 00 */	cmpw r27, r0
/* 800FAD50 000F7B50  41 80 FF C0 */	blt .L_800FAD10
/* 800FAD54 000F7B54  83 BF 00 2C */	lwz r29, 0x2c(r31)
/* 800FAD58 000F7B58  7F E3 FB 78 */	mr r3, r31
/* 800FAD5C 000F7B5C  80 BD 00 08 */	lwz r5, 0x8(r29)
/* 800FAD60 000F7B60  80 9D 00 64 */	lwz r4, 0x64(r29)
/* 800FAD64 000F7B64  83 C5 00 00 */	lwz r30, 0x0(r5)
/* 800FAD68 000F7B68  80 1E 00 08 */	lwz r0, 0x8(r30)
/* 800FAD6C 000F7B6C  54 00 18 38 */	slwi r0, r0, 3
/* 800FAD70 000F7B70  7F 84 00 2E */	lwzx r28, r4, r0
/* 800FAD74 000F7B74  4B FF CD 45 */	bl kar_gryakulib_get_yaku_state_or_none
/* 800FAD78 000F7B78  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FAD7C 000F7B7C  40 82 00 98 */	bne .L_800FAE14
/* 800FAD80 000F7B80  C0 22 91 D4 */	lfs f1, lbl_805DF8D4@sda21(r0)
/* 800FAD84 000F7B84  7F A3 EB 78 */	mr r3, r29
/* 800FAD88 000F7B88  80 BE 00 10 */	lwz r5, 0x10(r30)
/* 800FAD8C 000F7B8C  38 80 00 01 */	li r4, 0x1
/* 800FAD90 000F7B90  FC 60 08 90 */	fmr f3, f1
/* 800FAD94 000F7B94  C0 42 91 D8 */	lfs f2, lbl_805DF8D8@sda21(r0)
/* 800FAD98 000F7B98  38 C0 FF FF */	li r6, -0x1
/* 800FAD9C 000F7B9C  38 E0 00 00 */	li r7, 0x0
/* 800FADA0 000F7BA0  4B FF A7 A9 */	bl kar_gryaku_set_path_node_motion
/* 800FADA4 000F7BA4  C0 22 91 D4 */	lfs f1, lbl_805DF8D4@sda21(r0)
/* 800FADA8 000F7BA8  7F E3 FB 78 */	mr r3, r31
/* 800FADAC 000F7BAC  80 9E 00 18 */	lwz r4, 0x18(r30)
/* 800FADB0 000F7BB0  38 C0 00 00 */	li r6, 0x0
/* 800FADB4 000F7BB4  FC 40 08 90 */	fmr f2, f1
/* 800FADB8 000F7BB8  80 BE 00 08 */	lwz r5, 0x8(r30)
/* 800FADBC 000F7BBC  38 E0 00 00 */	li r7, 0x0
/* 800FADC0 000F7BC0  4B FF A9 DD */	bl kar_gryaku_play_anim_entry
/* 800FADC4 000F7BC4  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 800FADC8 000F7BC8  7F E3 FB 78 */	mr r3, r31
/* 800FADCC 000F7BCC  4B FF AE 9D */	bl kar_gryakuanim_step_jobj_slot_anim
/* 800FADD0 000F7BD0  3C 80 80 10 */	lis r4, kar_gryakucatchzone_get_entry_offset_c_float@ha
/* 800FADD4 000F7BD4  7F 83 E3 78 */	mr r3, r28
/* 800FADD8 000F7BD8  38 84 AC 5C */	addi r4, r4, kar_gryakucatchzone_get_entry_offset_c_float@l
/* 800FADDC 000F7BDC  4B FF B3 59 */	bl kar_gryakuanim_get_jobj_aobj_value
/* 800FADE0 000F7BE0  D0 3D 01 38 */	stfs f1, 0x138(r29)
/* 800FADE4 000F7BE4  7F A3 EB 78 */	mr r3, r29
/* 800FADE8 000F7BE8  C0 22 91 D4 */	lfs f1, lbl_805DF8D4@sda21(r0)
/* 800FADEC 000F7BEC  38 C0 00 01 */	li r6, 0x1
/* 800FADF0 000F7BF0  80 FE 00 30 */	lwz r7, 0x30(r30)
/* 800FADF4 000F7BF4  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 800FADF8 000F7BF8  80 BE 00 14 */	lwz r5, 0x14(r30)
/* 800FADFC 000F7BFC  C0 47 00 08 */	lfs f2, 0x8(r7)
/* 800FAE00 000F7C00  4B FF B1 89 */	bl kar_gryakuanim_start_dobj_anim_for_entry
/* 800FAE04 000F7C04  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 800FAE08 000F7C08  7F A3 EB 78 */	mr r3, r29
/* 800FAE0C 000F7C0C  4B FF B2 25 */	bl kar_gryakuanim_step_dobj_anim_for_slot
/* 800FAE10 000F7C10  48 00 00 C0 */	b .L_800FAED0
.L_800FAE14:
/* 800FAE14 000F7C14  7F 83 E3 78 */	mr r3, r28
/* 800FAE18 000F7C18  38 81 00 08 */	addi r4, r1, 0x8
/* 800FAE1C 000F7C1C  4B FF B2 75 */	bl kar_gryakuanim_find_dobj_anim_data
/* 800FAE20 000F7C20  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FAE24 000F7C24  40 82 00 18 */	bne .L_800FAE3C
/* 800FAE28 000F7C28  3C 60 80 4A */	lis r3, kar_src_gryakurecoveryzone_c@ha
/* 800FAE2C 000F7C2C  38 80 00 BC */	li r4, 0xbc
/* 800FAE30 000F7C30  38 63 60 44 */	addi r3, r3, kar_src_gryakurecoveryzone_c@l
/* 800FAE34 000F7C34  38 AD 91 40 */	li r5, lbl_805D6220@sda21
/* 800FAE38 000F7C38  48 32 D6 81 */	bl __assert
.L_800FAE3C:
/* 800FAE3C 000F7C3C  80 9E 00 30 */	lwz r4, 0x30(r30)
/* 800FAE40 000F7C40  7F E3 FB 78 */	mr r3, r31
/* 800FAE44 000F7C44  C0 3D 01 34 */	lfs f1, 0x134(r29)
/* 800FAE48 000F7C48  38 C0 00 00 */	li r6, 0x0
/* 800FAE4C 000F7C4C  C0 04 00 00 */	lfs f0, 0x0(r4)
/* 800FAE50 000F7C50  38 E0 00 00 */	li r7, 0x0
/* 800FAE54 000F7C54  C0 42 91 D8 */	lfs f2, lbl_805DF8D8@sda21(r0)
/* 800FAE58 000F7C58  EC 01 00 24 */	fdivs f0, f1, f0
/* 800FAE5C 000F7C5C  C0 7D 01 38 */	lfs f3, 0x138(r29)
/* 800FAE60 000F7C60  80 9E 00 18 */	lwz r4, 0x18(r30)
/* 800FAE64 000F7C64  80 BE 00 08 */	lwz r5, 0x8(r30)
/* 800FAE68 000F7C68  C0 22 91 D4 */	lfs f1, lbl_805DF8D4@sda21(r0)
/* 800FAE6C 000F7C6C  EC 02 00 28 */	fsubs f0, f2, f0
/* 800FAE70 000F7C70  EC 43 00 32 */	fmuls f2, f3, f0
/* 800FAE74 000F7C74  4B FF A9 29 */	bl kar_gryaku_play_anim_entry
/* 800FAE78 000F7C78  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 800FAE7C 000F7C7C  7F E3 FB 78 */	mr r3, r31
/* 800FAE80 000F7C80  4B FF AD E9 */	bl kar_gryakuanim_step_jobj_slot_anim
/* 800FAE84 000F7C84  80 9E 00 30 */	lwz r4, 0x30(r30)
/* 800FAE88 000F7C88  7F A3 EB 78 */	mr r3, r29
/* 800FAE8C 000F7C8C  C0 3D 01 34 */	lfs f1, 0x134(r29)
/* 800FAE90 000F7C90  38 C0 00 01 */	li r6, 0x1
/* 800FAE94 000F7C94  C0 04 00 00 */	lfs f0, 0x0(r4)
/* 800FAE98 000F7C98  C0 84 00 08 */	lfs f4, 0x8(r4)
/* 800FAE9C 000F7C9C  EC 41 00 24 */	fdivs f2, f1, f0
/* 800FAEA0 000F7CA0  C0 62 91 D8 */	lfs f3, lbl_805DF8D8@sda21(r0)
/* 800FAEA4 000F7CA4  C0 04 00 0C */	lfs f0, 0xc(r4)
/* 800FAEA8 000F7CA8  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 800FAEAC 000F7CAC  80 BE 00 14 */	lwz r5, 0x14(r30)
/* 800FAEB0 000F7CB0  C0 21 00 08 */	lfs f1, 0x8(r1)
/* 800FAEB4 000F7CB4  EC 43 10 28 */	fsubs f2, f3, f2
/* 800FAEB8 000F7CB8  EC 00 20 28 */	fsubs f0, f0, f4
/* 800FAEBC 000F7CBC  EC 42 20 3A */	fmadds f2, f2, f0, f4
/* 800FAEC0 000F7CC0  4B FF B0 C9 */	bl kar_gryakuanim_start_dobj_anim_for_entry
/* 800FAEC4 000F7CC4  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 800FAEC8 000F7CC8  7F A3 EB 78 */	mr r3, r29
/* 800FAECC 000F7CCC  4B FF B1 65 */	bl kar_gryakuanim_step_dobj_anim_for_slot
.L_800FAED0:
/* 800FAED0 000F7CD0  39 61 00 30 */	addi r11, r1, 0x30
/* 800FAED4 000F7CD4  48 2B 2C CD */	bl _restgpr_27
/* 800FAED8 000F7CD8  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800FAEDC 000F7CDC  7C 08 03 A6 */	mtlr r0
/* 800FAEE0 000F7CE0  38 21 00 30 */	addi r1, r1, 0x30
/* 800FAEE4 000F7CE4  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_enter_recovery_sequence

# .text:0x24C | 0x800FAEE8 | size: 0xE8
.fn kar_gryakurecoveryzone_enter_enabled_state_sequence, global
/* 800FAEE8 000F7CE8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800FAEEC 000F7CEC  7C 08 02 A6 */	mflr r0
/* 800FAEF0 000F7CF0  90 01 00 24 */	stw r0, 0x24(r1)
/* 800FAEF4 000F7CF4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800FAEF8 000F7CF8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800FAEFC 000F7CFC  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800FAF00 000F7D00  93 81 00 10 */	stw r28, 0x10(r1)
/* 800FAF04 000F7D04  7C 7C 1B 78 */	mr r28, r3
/* 800FAF08 000F7D08  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FAF0C 000F7D0C  80 83 00 08 */	lwz r4, 0x8(r3)
/* 800FAF10 000F7D10  80 63 00 64 */	lwz r3, 0x64(r3)
/* 800FAF14 000F7D14  83 E4 00 00 */	lwz r31, 0x0(r4)
/* 800FAF18 000F7D18  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 800FAF1C 000F7D1C  54 00 18 38 */	slwi r0, r0, 3
/* 800FAF20 000F7D20  7C 63 00 2E */	lwzx r3, r3, r0
/* 800FAF24 000F7D24  4B F5 98 BD */	bl kar_gmlanmenu__near_800547e0
/* 800FAF28 000F7D28  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FAF2C 000F7D2C  40 82 00 84 */	bne .L_800FAFB0
/* 800FAF30 000F7D30  3B A0 00 00 */	li r29, 0x0
/* 800FAF34 000F7D34  3B C0 00 00 */	li r30, 0x0
/* 800FAF38 000F7D38  48 00 00 30 */	b .L_800FAF68
.L_800FAF3C:
/* 800FAF3C 000F7D3C  80 1F 00 28 */	lwz r0, 0x28(r31)
/* 800FAF40 000F7D40  7F 83 E3 78 */	mr r3, r28
/* 800FAF44 000F7D44  80 BF 00 00 */	lwz r5, 0x0(r31)
/* 800FAF48 000F7D48  38 C0 00 00 */	li r6, 0x0
/* 800FAF4C 000F7D4C  7C 80 F2 14 */	add r4, r0, r30
/* 800FAF50 000F7D50  38 E0 00 00 */	li r7, 0x0
/* 800FAF54 000F7D54  39 00 00 00 */	li r8, 0x0
/* 800FAF58 000F7D58  39 20 00 01 */	li r9, 0x1
/* 800FAF5C 000F7D5C  4B FF C0 E9 */	bl kar_gryakueffect_request_by_entry_mode
/* 800FAF60 000F7D60  3B DE 00 1C */	addi r30, r30, 0x1c
/* 800FAF64 000F7D64  3B BD 00 01 */	addi r29, r29, 0x1
.L_800FAF68:
/* 800FAF68 000F7D68  80 1F 00 2C */	lwz r0, 0x2c(r31)
/* 800FAF6C 000F7D6C  7C 1D 00 00 */	cmpw r29, r0
/* 800FAF70 000F7D70  41 80 FF CC */	blt .L_800FAF3C
/* 800FAF74 000F7D74  83 DC 00 2C */	lwz r30, 0x2c(r28)
/* 800FAF78 000F7D78  38 80 00 00 */	li r4, 0x0
/* 800FAF7C 000F7D7C  80 BE 00 08 */	lwz r5, 0x8(r30)
/* 800FAF80 000F7D80  7F C3 F3 78 */	mr r3, r30
/* 800FAF84 000F7D84  83 E5 00 00 */	lwz r31, 0x0(r5)
/* 800FAF88 000F7D88  4B FF B3 D9 */	bl kar_gryakuanim_apply_zone_enabled_state
/* 800FAF8C 000F7D8C  C0 22 91 D4 */	lfs f1, lbl_805DF8D4@sda21(r0)
/* 800FAF90 000F7D90  7F C3 F3 78 */	mr r3, r30
/* 800FAF94 000F7D94  80 BF 00 1C */	lwz r5, 0x1c(r31)
/* 800FAF98 000F7D98  38 80 00 03 */	li r4, 0x3
/* 800FAF9C 000F7D9C  FC 60 08 90 */	fmr f3, f1
/* 800FAFA0 000F7DA0  C0 42 91 D8 */	lfs f2, lbl_805DF8D8@sda21(r0)
/* 800FAFA4 000F7DA4  38 C0 FF FF */	li r6, -0x1
/* 800FAFA8 000F7DA8  38 E0 00 04 */	li r7, 0x4
/* 800FAFAC 000F7DAC  4B FF A5 9D */	bl kar_gryaku_set_path_node_motion
.L_800FAFB0:
/* 800FAFB0 000F7DB0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FAFB4 000F7DB4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800FAFB8 000F7DB8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800FAFBC 000F7DBC  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800FAFC0 000F7DC0  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800FAFC4 000F7DC4  7C 08 03 A6 */	mtlr r0
/* 800FAFC8 000F7DC8  38 21 00 20 */	addi r1, r1, 0x20
/* 800FAFCC 000F7DCC  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_enter_enabled_state_sequence

# .text:0x334 | 0x800FAFD0 | size: 0x2EC
.fn kar_gryakurecoveryzone_update_recovery_progress, global
/* 800FAFD0 000F7DD0  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 800FAFD4 000F7DD4  7C 08 02 A6 */	mflr r0
/* 800FAFD8 000F7DD8  90 01 00 54 */	stw r0, 0x54(r1)
/* 800FAFDC 000F7DDC  DB E1 00 40 */	stfd f31, 0x40(r1)
/* 800FAFE0 000F7DE0  F3 E1 00 48 */	psq_st f31, 0x48(r1), 0, qr0
/* 800FAFE4 000F7DE4  39 61 00 40 */	addi r11, r1, 0x40
/* 800FAFE8 000F7DE8  48 2B 2B 5D */	bl _savegpr_23
/* 800FAFEC 000F7DEC  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800FAFF0 000F7DF0  7C 7D 1B 78 */	mr r29, r3
/* 800FAFF4 000F7DF4  C0 02 91 D4 */	lfs f0, lbl_805DF8D4@sda21(r0)
/* 800FAFF8 000F7DF8  7C 9E 23 78 */	mr r30, r4
/* 800FAFFC 000F7DFC  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800FB000 000F7E00  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800FB004 000F7E04  80 63 00 00 */	lwz r3, 0x0(r3)
/* 800FB008 000F7E08  40 81 02 90 */	ble .L_800FB298
/* 800FB00C 000F7E0C  80 63 00 30 */	lwz r3, 0x30(r3)
/* 800FB010 000F7E10  C0 03 00 04 */	lfs f0, 0x4(r3)
/* 800FB014 000F7E14  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800FB018 000F7E18  40 80 00 08 */	bge .L_800FB020
/* 800FB01C 000F7E1C  48 00 00 08 */	b .L_800FB024
.L_800FB020:
/* 800FB020 000F7E20  FC 20 00 90 */	fmr f1, f0
.L_800FB024:
/* 800FB024 000F7E24  C0 1F 01 34 */	lfs f0, 0x134(r31)
/* 800FB028 000F7E28  FF E0 08 90 */	fmr f31, f1
/* 800FB02C 000F7E2C  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 800FB030 000F7E30  40 81 01 A4 */	ble .L_800FB1D4
/* 800FB034 000F7E34  EC 00 08 28 */	fsubs f0, f0, f1
/* 800FB038 000F7E38  D0 1F 01 34 */	stfs f0, 0x134(r31)
/* 800FB03C 000F7E3C  88 1F 01 58 */	lbz r0, 0x158(r31)
/* 800FB040 000F7E40  54 00 CF FF */	extrwi. r0, r0, 1, 24
/* 800FB044 000F7E44  41 82 00 10 */	beq .L_800FB054
/* 800FB048 000F7E48  7F A3 EB 78 */	mr r3, r29
/* 800FB04C 000F7E4C  48 00 04 01 */	bl kar_gryakurecoveryzone_start_state1_path_motion
/* 800FB050 000F7E50  48 00 02 40 */	b .L_800FB290
.L_800FB054:
/* 800FB054 000F7E54  83 7D 00 2C */	lwz r27, 0x2c(r29)
/* 800FB058 000F7E58  7F A3 EB 78 */	mr r3, r29
/* 800FB05C 000F7E5C  80 BB 00 08 */	lwz r5, 0x8(r27)
/* 800FB060 000F7E60  80 9B 00 64 */	lwz r4, 0x64(r27)
/* 800FB064 000F7E64  83 45 00 00 */	lwz r26, 0x0(r5)
/* 800FB068 000F7E68  80 1A 00 08 */	lwz r0, 0x8(r26)
/* 800FB06C 000F7E6C  54 00 18 38 */	slwi r0, r0, 3
/* 800FB070 000F7E70  7F 04 00 2E */	lwzx r24, r4, r0
/* 800FB074 000F7E74  4B FF CA 45 */	bl kar_gryakulib_get_yaku_state_or_none
/* 800FB078 000F7E78  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FB07C 000F7E7C  40 82 00 98 */	bne .L_800FB114
/* 800FB080 000F7E80  C0 22 91 D4 */	lfs f1, lbl_805DF8D4@sda21(r0)
/* 800FB084 000F7E84  7F 63 DB 78 */	mr r3, r27
/* 800FB088 000F7E88  80 BA 00 10 */	lwz r5, 0x10(r26)
/* 800FB08C 000F7E8C  38 80 00 01 */	li r4, 0x1
/* 800FB090 000F7E90  FC 60 08 90 */	fmr f3, f1
/* 800FB094 000F7E94  C0 42 91 D8 */	lfs f2, lbl_805DF8D8@sda21(r0)
/* 800FB098 000F7E98  38 C0 FF FF */	li r6, -0x1
/* 800FB09C 000F7E9C  38 E0 00 00 */	li r7, 0x0
/* 800FB0A0 000F7EA0  4B FF A4 A9 */	bl kar_gryaku_set_path_node_motion
/* 800FB0A4 000F7EA4  C0 22 91 D4 */	lfs f1, lbl_805DF8D4@sda21(r0)
/* 800FB0A8 000F7EA8  7F A3 EB 78 */	mr r3, r29
/* 800FB0AC 000F7EAC  80 9A 00 18 */	lwz r4, 0x18(r26)
/* 800FB0B0 000F7EB0  38 C0 00 00 */	li r6, 0x0
/* 800FB0B4 000F7EB4  FC 40 08 90 */	fmr f2, f1
/* 800FB0B8 000F7EB8  80 BA 00 08 */	lwz r5, 0x8(r26)
/* 800FB0BC 000F7EBC  38 E0 00 00 */	li r7, 0x0
/* 800FB0C0 000F7EC0  4B FF A6 DD */	bl kar_gryaku_play_anim_entry
/* 800FB0C4 000F7EC4  80 9A 00 08 */	lwz r4, 0x8(r26)
/* 800FB0C8 000F7EC8  7F A3 EB 78 */	mr r3, r29
/* 800FB0CC 000F7ECC  4B FF AB 9D */	bl kar_gryakuanim_step_jobj_slot_anim
/* 800FB0D0 000F7ED0  3C 80 80 10 */	lis r4, kar_gryakucatchzone_get_entry_offset_c_float@ha
/* 800FB0D4 000F7ED4  7F 03 C3 78 */	mr r3, r24
/* 800FB0D8 000F7ED8  38 84 AC 5C */	addi r4, r4, kar_gryakucatchzone_get_entry_offset_c_float@l
/* 800FB0DC 000F7EDC  4B FF B0 59 */	bl kar_gryakuanim_get_jobj_aobj_value
/* 800FB0E0 000F7EE0  D0 3B 01 38 */	stfs f1, 0x138(r27)
/* 800FB0E4 000F7EE4  7F 63 DB 78 */	mr r3, r27
/* 800FB0E8 000F7EE8  C0 22 91 D4 */	lfs f1, lbl_805DF8D4@sda21(r0)
/* 800FB0EC 000F7EEC  38 C0 00 01 */	li r6, 0x1
/* 800FB0F0 000F7EF0  80 FA 00 30 */	lwz r7, 0x30(r26)
/* 800FB0F4 000F7EF4  80 9A 00 08 */	lwz r4, 0x8(r26)
/* 800FB0F8 000F7EF8  80 BA 00 14 */	lwz r5, 0x14(r26)
/* 800FB0FC 000F7EFC  C0 47 00 08 */	lfs f2, 0x8(r7)
/* 800FB100 000F7F00  4B FF AE 89 */	bl kar_gryakuanim_start_dobj_anim_for_entry
/* 800FB104 000F7F04  80 9A 00 08 */	lwz r4, 0x8(r26)
/* 800FB108 000F7F08  7F 63 DB 78 */	mr r3, r27
/* 800FB10C 000F7F0C  4B FF AF 25 */	bl kar_gryakuanim_step_dobj_anim_for_slot
/* 800FB110 000F7F10  48 00 01 80 */	b .L_800FB290
.L_800FB114:
/* 800FB114 000F7F14  7F 03 C3 78 */	mr r3, r24
/* 800FB118 000F7F18  38 81 00 08 */	addi r4, r1, 0x8
/* 800FB11C 000F7F1C  4B FF AF 75 */	bl kar_gryakuanim_find_dobj_anim_data
/* 800FB120 000F7F20  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FB124 000F7F24  40 82 00 18 */	bne .L_800FB13C
/* 800FB128 000F7F28  3C 60 80 4A */	lis r3, kar_src_gryakurecoveryzone_c@ha
/* 800FB12C 000F7F2C  38 80 00 BC */	li r4, 0xbc
/* 800FB130 000F7F30  38 63 60 44 */	addi r3, r3, kar_src_gryakurecoveryzone_c@l
/* 800FB134 000F7F34  38 AD 91 40 */	li r5, lbl_805D6220@sda21
/* 800FB138 000F7F38  48 32 D3 81 */	bl __assert
.L_800FB13C:
/* 800FB13C 000F7F3C  80 9A 00 30 */	lwz r4, 0x30(r26)
/* 800FB140 000F7F40  7F A3 EB 78 */	mr r3, r29
/* 800FB144 000F7F44  C0 3B 01 34 */	lfs f1, 0x134(r27)
/* 800FB148 000F7F48  38 C0 00 00 */	li r6, 0x0
/* 800FB14C 000F7F4C  C0 04 00 00 */	lfs f0, 0x0(r4)
/* 800FB150 000F7F50  38 E0 00 00 */	li r7, 0x0
/* 800FB154 000F7F54  C0 42 91 D8 */	lfs f2, lbl_805DF8D8@sda21(r0)
/* 800FB158 000F7F58  EC 01 00 24 */	fdivs f0, f1, f0
/* 800FB15C 000F7F5C  C0 7B 01 38 */	lfs f3, 0x138(r27)
/* 800FB160 000F7F60  80 9A 00 18 */	lwz r4, 0x18(r26)
/* 800FB164 000F7F64  80 BA 00 08 */	lwz r5, 0x8(r26)
/* 800FB168 000F7F68  C0 22 91 D4 */	lfs f1, lbl_805DF8D4@sda21(r0)
/* 800FB16C 000F7F6C  EC 02 00 28 */	fsubs f0, f2, f0
/* 800FB170 000F7F70  EC 43 00 32 */	fmuls f2, f3, f0
/* 800FB174 000F7F74  4B FF A6 29 */	bl kar_gryaku_play_anim_entry
/* 800FB178 000F7F78  80 9A 00 08 */	lwz r4, 0x8(r26)
/* 800FB17C 000F7F7C  7F A3 EB 78 */	mr r3, r29
/* 800FB180 000F7F80  4B FF AA E9 */	bl kar_gryakuanim_step_jobj_slot_anim
/* 800FB184 000F7F84  80 9A 00 30 */	lwz r4, 0x30(r26)
/* 800FB188 000F7F88  7F 63 DB 78 */	mr r3, r27
/* 800FB18C 000F7F8C  C0 3B 01 34 */	lfs f1, 0x134(r27)
/* 800FB190 000F7F90  38 C0 00 01 */	li r6, 0x1
/* 800FB194 000F7F94  C0 04 00 00 */	lfs f0, 0x0(r4)
/* 800FB198 000F7F98  C0 84 00 08 */	lfs f4, 0x8(r4)
/* 800FB19C 000F7F9C  EC 41 00 24 */	fdivs f2, f1, f0
/* 800FB1A0 000F7FA0  C0 62 91 D8 */	lfs f3, lbl_805DF8D8@sda21(r0)
/* 800FB1A4 000F7FA4  C0 04 00 0C */	lfs f0, 0xc(r4)
/* 800FB1A8 000F7FA8  80 9A 00 08 */	lwz r4, 0x8(r26)
/* 800FB1AC 000F7FAC  80 BA 00 14 */	lwz r5, 0x14(r26)
/* 800FB1B0 000F7FB0  C0 21 00 08 */	lfs f1, 0x8(r1)
/* 800FB1B4 000F7FB4  EC 43 10 28 */	fsubs f2, f3, f2
/* 800FB1B8 000F7FB8  EC 00 20 28 */	fsubs f0, f0, f4
/* 800FB1BC 000F7FBC  EC 42 20 3A */	fmadds f2, f2, f0, f4
/* 800FB1C0 000F7FC0  4B FF AD C9 */	bl kar_gryakuanim_start_dobj_anim_for_entry
/* 800FB1C4 000F7FC4  80 9A 00 08 */	lwz r4, 0x8(r26)
/* 800FB1C8 000F7FC8  7F 63 DB 78 */	mr r3, r27
/* 800FB1CC 000F7FCC  4B FF AE 65 */	bl kar_gryakuanim_step_dobj_anim_for_slot
/* 800FB1D0 000F7FD0  48 00 00 C0 */	b .L_800FB290
.L_800FB1D4:
/* 800FB1D4 000F7FD4  88 1F 01 58 */	lbz r0, 0x158(r31)
/* 800FB1D8 000F7FD8  FF E0 00 90 */	fmr f31, f0
/* 800FB1DC 000F7FDC  54 00 CF FF */	extrwi. r0, r0, 1, 24
/* 800FB1E0 000F7FE0  41 82 00 10 */	beq .L_800FB1F0
/* 800FB1E4 000F7FE4  7F A3 EB 78 */	mr r3, r29
/* 800FB1E8 000F7FE8  48 00 02 AD */	bl kar_gryakurecoveryzone_start_state2_path_motion
/* 800FB1EC 000F7FEC  48 00 00 A4 */	b .L_800FB290
.L_800FB1F0:
/* 800FB1F0 000F7FF0  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800FB1F4 000F7FF4  3B 20 00 00 */	li r25, 0x0
/* 800FB1F8 000F7FF8  C0 02 91 D4 */	lfs f0, lbl_805DF8D4@sda21(r0)
/* 800FB1FC 000F7FFC  7F F7 FB 78 */	mr r23, r31
/* 800FB200 000F8000  83 03 00 00 */	lwz r24, 0x0(r3)
/* 800FB204 000F8004  7F 3A CB 78 */	mr r26, r25
/* 800FB208 000F8008  7F 3B CB 78 */	mr r27, r25
/* 800FB20C 000F800C  7F 3C CB 78 */	mr r28, r25
/* 800FB210 000F8010  D0 1F 01 34 */	stfs f0, 0x134(r31)
/* 800FB214 000F8014  7F 3D CB 78 */	mr r29, r25
.L_800FB218:
/* 800FB218 000F8018  80 77 01 40 */	lwz r3, 0x140(r23)
/* 800FB21C 000F801C  80 97 01 44 */	lwz r4, 0x144(r23)
/* 800FB220 000F8020  7C 60 DA 78 */	xor r0, r3, r27
/* 800FB224 000F8024  7C 85 D2 78 */	xor r5, r4, r26
/* 800FB228 000F8028  7C A0 03 79 */	or. r0, r5, r0
/* 800FB22C 000F802C  41 82 00 10 */	beq .L_800FB23C
/* 800FB230 000F8030  4B FF C0 7D */	bl kar_gryakueffect_destroy_effect_by_key
/* 800FB234 000F8034  93 97 01 44 */	stw r28, 0x144(r23)
/* 800FB238 000F8038  93 B7 01 40 */	stw r29, 0x140(r23)
.L_800FB23C:
/* 800FB23C 000F803C  3B 39 00 01 */	addi r25, r25, 0x1
/* 800FB240 000F8040  3A F7 00 08 */	addi r23, r23, 0x8
/* 800FB244 000F8044  2C 19 00 03 */	cmpwi r25, 0x3
/* 800FB248 000F8048  41 80 FF D0 */	blt .L_800FB218
/* 800FB24C 000F804C  80 1F 01 1C */	lwz r0, 0x11c(r31)
/* 800FB250 000F8050  2C 00 00 01 */	cmpwi r0, 0x1
/* 800FB254 000F8054  40 81 00 10 */	ble .L_800FB264
/* 800FB258 000F8058  38 7F 01 18 */	addi r3, r31, 0x118
/* 800FB25C 000F805C  38 80 00 01 */	li r4, 0x1
/* 800FB260 000F8060  4B FE EE 25 */	bl kar_graudio_play_fgm_entry_id
.L_800FB264:
/* 800FB264 000F8064  7F C3 F3 78 */	mr r3, r30
/* 800FB268 000F8068  48 13 4D 41 */	bl kar_plclearcheckerlib__near_8022ffa8
/* 800FB26C 000F806C  C0 22 91 D4 */	lfs f1, lbl_805DF8D4@sda21(r0)
/* 800FB270 000F8070  7F E3 FB 78 */	mr r3, r31
/* 800FB274 000F8074  80 B8 00 1C */	lwz r5, 0x1c(r24)
/* 800FB278 000F8078  38 80 00 02 */	li r4, 0x2
/* 800FB27C 000F807C  FC 60 08 90 */	fmr f3, f1
/* 800FB280 000F8080  C0 42 91 D8 */	lfs f2, lbl_805DF8D8@sda21(r0)
/* 800FB284 000F8084  38 C0 FF FF */	li r6, -0x1
/* 800FB288 000F8088  38 E0 00 00 */	li r7, 0x0
/* 800FB28C 000F808C  4B FF A2 BD */	bl kar_gryaku_set_path_node_motion
.L_800FB290:
/* 800FB290 000F8090  FC 20 F8 90 */	fmr f1, f31
/* 800FB294 000F8094  48 00 00 08 */	b .L_800FB29C
.L_800FB298:
/* 800FB298 000F8098  FC 20 00 90 */	fmr f1, f0
.L_800FB29C:
/* 800FB29C 000F809C  E3 E1 00 48 */	psq_l f31, 0x48(r1), 0, qr0
/* 800FB2A0 000F80A0  39 61 00 40 */	addi r11, r1, 0x40
/* 800FB2A4 000F80A4  CB E1 00 40 */	lfd f31, 0x40(r1)
/* 800FB2A8 000F80A8  48 2B 28 E9 */	bl _restgpr_23
/* 800FB2AC 000F80AC  80 01 00 54 */	lwz r0, 0x54(r1)
/* 800FB2B0 000F80B0  7C 08 03 A6 */	mtlr r0
/* 800FB2B4 000F80B4  38 21 00 50 */	addi r1, r1, 0x50
/* 800FB2B8 000F80B8  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_update_recovery_progress

# .text:0x620 | 0x800FB2BC | size: 0xBC
.fn kar_gryakurecoveryzone_try_update_player_slot_recovery, global
/* 800FB2BC 000F80BC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800FB2C0 000F80C0  7C 08 02 A6 */	mflr r0
/* 800FB2C4 000F80C4  90 01 00 24 */	stw r0, 0x24(r1)
/* 800FB2C8 000F80C8  DB E1 00 10 */	stfd f31, 0x10(r1)
/* 800FB2CC 000F80CC  F3 E1 00 18 */	psq_st f31, 0x18(r1), 0, qr0
/* 800FB2D0 000F80D0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FB2D4 000F80D4  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800FB2D8 000F80D8  80 AD 05 EC */	lwz r5, lbl_805DD6CC@sda21(r0)
/* 800FB2DC 000F80DC  1C 03 01 40 */	mulli r0, r3, 0x140
/* 800FB2E0 000F80E0  FF E0 08 90 */	fmr f31, f1
/* 800FB2E4 000F80E4  7C 9E 23 78 */	mr r30, r4
/* 800FB2E8 000F80E8  80 65 00 74 */	lwz r3, 0x74(r5)
/* 800FB2EC 000F80EC  7C 63 02 14 */	add r3, r3, r0
/* 800FB2F0 000F80F0  80 63 01 38 */	lwz r3, 0x138(r3)
/* 800FB2F4 000F80F4  28 03 00 00 */	cmplwi r3, 0x0
/* 800FB2F8 000F80F8  41 82 00 5C */	beq .L_800FB354
/* 800FB2FC 000F80FC  7C 7F 1B 78 */	mr r31, r3
/* 800FB300 000F8100  4B FF C7 65 */	bl kar_gryakulib_get_yaku_data_checked
/* 800FB304 000F8104  2C 03 00 14 */	cmpwi r3, 0x14
/* 800FB308 000F8108  41 82 00 1C */	beq .L_800FB324
/* 800FB30C 000F810C  3C 60 80 4A */	lis r3, kar_src_gryakurecoveryzone_c@ha
/* 800FB310 000F8110  3C A0 80 4A */	lis r5, kar_gryakurecoveryzone_assert_kind_recoveryzone@ha
/* 800FB314 000F8114  38 63 60 44 */	addi r3, r3, kar_src_gryakurecoveryzone_c@l
/* 800FB318 000F8118  38 80 01 9D */	li r4, 0x19d
/* 800FB31C 000F811C  38 A5 60 90 */	addi r5, r5, kar_gryakurecoveryzone_assert_kind_recoveryzone@l
/* 800FB320 000F8120  48 32 D1 99 */	bl __assert
.L_800FB324:
/* 800FB324 000F8124  7F E3 FB 78 */	mr r3, r31
/* 800FB328 000F8128  4B FF C7 91 */	bl kar_gryakulib_get_yaku_state_or_none
/* 800FB32C 000F812C  2C 03 00 01 */	cmpwi r3, 0x1
/* 800FB330 000F8130  41 82 00 08 */	beq .L_800FB338
/* 800FB334 000F8134  48 00 00 18 */	b .L_800FB34C
.L_800FB338:
/* 800FB338 000F8138  FC 20 F8 90 */	fmr f1, f31
/* 800FB33C 000F813C  7F E3 FB 78 */	mr r3, r31
/* 800FB340 000F8140  7F C4 F3 78 */	mr r4, r30
/* 800FB344 000F8144  4B FF FC 8D */	bl kar_gryakurecoveryzone_update_recovery_progress
/* 800FB348 000F8148  48 00 00 10 */	b .L_800FB358
.L_800FB34C:
/* 800FB34C 000F814C  C0 22 91 D4 */	lfs f1, lbl_805DF8D4@sda21(r0)
/* 800FB350 000F8150  48 00 00 08 */	b .L_800FB358
.L_800FB354:
/* 800FB354 000F8154  C0 22 91 D4 */	lfs f1, lbl_805DF8D4@sda21(r0)
.L_800FB358:
/* 800FB358 000F8158  E3 E1 00 18 */	psq_l f31, 0x18(r1), 0, qr0
/* 800FB35C 000F815C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FB360 000F8160  CB E1 00 10 */	lfd f31, 0x10(r1)
/* 800FB364 000F8164  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FB368 000F8168  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800FB36C 000F816C  7C 08 03 A6 */	mtlr r0
/* 800FB370 000F8170  38 21 00 20 */	addi r1, r1, 0x20
/* 800FB374 000F8174  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_try_update_player_slot_recovery

# .text:0x6DC | 0x800FB378 | size: 0x38
.fn kar_gryakurecoveryzone_create_stage_linked_recoveryzone_yaku, global
/* 800FB378 000F8178  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FB37C 000F817C  7C 08 02 A6 */	mflr r0
/* 800FB380 000F8180  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FB384 000F8184  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FB388 000F8188  7C 7F 1B 78 */	mr r31, r3
/* 800FB38C 000F818C  38 60 00 14 */	li r3, 0x14
/* 800FB390 000F8190  4B FF 90 DD */	bl kar_gryaku_create_yaku_from_main_kind
/* 800FB394 000F8194  7F E4 FB 78 */	mr r4, r31
/* 800FB398 000F8198  48 00 00 19 */	bl kar_gryakurecoveryzone_init_stage_linked_recoveryzone_yaku
/* 800FB39C 000F819C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FB3A0 000F81A0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FB3A4 000F81A4  7C 08 03 A6 */	mtlr r0
/* 800FB3A8 000F81A8  38 21 00 10 */	addi r1, r1, 0x10
/* 800FB3AC 000F81AC  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_create_stage_linked_recoveryzone_yaku

# .text:0x714 | 0x800FB3B0 | size: 0x9C
.fn kar_gryakurecoveryzone_init_stage_linked_recoveryzone_yaku, global
/* 800FB3B0 000F81B0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800FB3B4 000F81B4  7C 08 02 A6 */	mflr r0
/* 800FB3B8 000F81B8  38 A0 00 00 */	li r5, 0x0
/* 800FB3BC 000F81BC  90 01 00 24 */	stw r0, 0x24(r1)
/* 800FB3C0 000F81C0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800FB3C4 000F81C4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800FB3C8 000F81C8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800FB3CC 000F81CC  7C 7D 1B 78 */	mr r29, r3
/* 800FB3D0 000F81D0  83 FD 00 2C */	lwz r31, 0x2c(r29)
/* 800FB3D4 000F81D4  80 64 00 2C */	lwz r3, 0x2c(r4)
/* 800FB3D8 000F81D8  80 FF 00 08 */	lwz r7, 0x8(r31)
/* 800FB3DC 000F81DC  80 83 01 04 */	lwz r4, 0x104(r3)
/* 800FB3E0 000F81E0  83 C7 00 00 */	lwz r30, 0x0(r7)
/* 800FB3E4 000F81E4  80 CD 05 EC */	lwz r6, lbl_805DD6CC@sda21(r0)
/* 800FB3E8 000F81E8  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 800FB3EC 000F81EC  38 66 00 54 */	addi r3, r6, 0x54
/* 800FB3F0 000F81F0  54 00 18 38 */	slwi r0, r0, 3
/* 800FB3F4 000F81F4  7C 84 00 2E */	lwzx r4, r4, r0
/* 800FB3F8 000F81F8  4B FD C5 C9 */	bl kar_grcoll__800d79c0
/* 800FB3FC 000F81FC  90 7F 01 30 */	stw r3, 0x130(r31)
/* 800FB400 000F8200  38 80 00 01 */	li r4, 0x1
/* 800FB404 000F8204  7F A3 EB 78 */	mr r3, r29
/* 800FB408 000F8208  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 800FB40C 000F820C  80 BF 01 30 */	lwz r5, 0x130(r31)
/* 800FB410 000F8210  90 05 01 38 */	stw r0, 0x138(r5)
/* 800FB414 000F8214  80 BE 00 30 */	lwz r5, 0x30(r30)
/* 800FB418 000F8218  C0 05 00 00 */	lfs f0, 0x0(r5)
/* 800FB41C 000F821C  D0 1F 01 34 */	stfs f0, 0x134(r31)
/* 800FB420 000F8220  88 1F 01 58 */	lbz r0, 0x158(r31)
/* 800FB424 000F8224  50 80 3E 30 */	rlwimi r0, r4, 7, 24, 24
/* 800FB428 000F8228  98 1F 01 58 */	stb r0, 0x158(r31)
/* 800FB42C 000F822C  48 00 00 21 */	bl kar_gryakurecoveryzone_start_state1_path_motion
/* 800FB430 000F8230  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FB434 000F8234  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800FB438 000F8238  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800FB43C 000F823C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800FB440 000F8240  7C 08 03 A6 */	mtlr r0
/* 800FB444 000F8244  38 21 00 20 */	addi r1, r1, 0x20
/* 800FB448 000F8248  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_init_stage_linked_recoveryzone_yaku

# .text:0x7B0 | 0x800FB44C | size: 0x48
.fn kar_gryakurecoveryzone_start_state1_path_motion, global
/* 800FB44C 000F824C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FB450 000F8250  7C 08 02 A6 */	mflr r0
/* 800FB454 000F8254  C0 22 91 D4 */	lfs f1, lbl_805DF8D4@sda21(r0)
/* 800FB458 000F8258  38 80 00 01 */	li r4, 0x1
/* 800FB45C 000F825C  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FB460 000F8260  38 A0 FF FF */	li r5, -0x1
/* 800FB464 000F8264  FC 40 08 90 */	fmr f2, f1
/* 800FB468 000F8268  38 E0 00 00 */	li r7, 0x0
/* 800FB46C 000F826C  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FB470 000F8270  FC 60 08 90 */	fmr f3, f1
/* 800FB474 000F8274  80 C3 00 08 */	lwz r6, 0x8(r3)
/* 800FB478 000F8278  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 800FB47C 000F827C  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 800FB480 000F8280  4B FF A0 C9 */	bl kar_gryaku_set_path_node_motion
/* 800FB484 000F8284  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FB488 000F8288  7C 08 03 A6 */	mtlr r0
/* 800FB48C 000F828C  38 21 00 10 */	addi r1, r1, 0x10
/* 800FB490 000F8290  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_start_state1_path_motion

# .text:0x7F8 | 0x800FB494 | size: 0x4C
.fn kar_gryakurecoveryzone_start_state2_path_motion, global
/* 800FB494 000F8294  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FB498 000F8298  7C 08 02 A6 */	mflr r0
/* 800FB49C 000F829C  C0 22 91 D4 */	lfs f1, lbl_805DF8D4@sda21(r0)
/* 800FB4A0 000F82A0  38 80 00 02 */	li r4, 0x2
/* 800FB4A4 000F82A4  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FB4A8 000F82A8  38 A0 FF FF */	li r5, -0x1
/* 800FB4AC 000F82AC  FC 40 08 90 */	fmr f2, f1
/* 800FB4B0 000F82B0  38 E0 00 00 */	li r7, 0x0
/* 800FB4B4 000F82B4  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FB4B8 000F82B8  FC 60 08 90 */	fmr f3, f1
/* 800FB4BC 000F82BC  80 C3 00 08 */	lwz r6, 0x8(r3)
/* 800FB4C0 000F82C0  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 800FB4C4 000F82C4  D0 23 01 34 */	stfs f1, 0x134(r3)
/* 800FB4C8 000F82C8  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 800FB4CC 000F82CC  4B FF A0 7D */	bl kar_gryaku_set_path_node_motion
/* 800FB4D0 000F82D0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FB4D4 000F82D4  7C 08 03 A6 */	mtlr r0
/* 800FB4D8 000F82D8  38 21 00 10 */	addi r1, r1, 0x10
/* 800FB4DC 000F82DC  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_start_state2_path_motion

# .text:0x844 | 0x800FB4E0 | size: 0xF0
.fn kar_gryakurecoveryzone_find_nearest_active_recoveryzone_pos, global
/* 800FB4E0 000F82E0  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 800FB4E4 000F82E4  7C 08 02 A6 */	mflr r0
/* 800FB4E8 000F82E8  90 01 00 44 */	stw r0, 0x44(r1)
/* 800FB4EC 000F82EC  DB E1 00 30 */	stfd f31, 0x30(r1)
/* 800FB4F0 000F82F0  F3 E1 00 38 */	psq_st f31, 0x38(r1), 0, qr0
/* 800FB4F4 000F82F4  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 800FB4F8 000F82F8  93 C1 00 28 */	stw r30, 0x28(r1)
/* 800FB4FC 000F82FC  93 A1 00 24 */	stw r29, 0x24(r1)
/* 800FB500 000F8300  80 AD 12 50 */	lwz r5, lbl_805DE330@sda21(r0)
/* 800FB504 000F8304  3C C0 80 5E */	lis r6, lbl_805DC8BC@ha
/* 800FB508 000F8308  C3 E6 C8 BC */	lfs f31, lbl_805DC8BC@l(r6)
/* 800FB50C 000F830C  7C 7D 1B 78 */	mr r29, r3
/* 800FB510 000F8310  83 E5 00 20 */	lwz r31, 0x20(r5)
/* 800FB514 000F8314  7C 9E 23 78 */	mr r30, r4
/* 800FB518 000F8318  48 00 00 70 */	b .L_800FB588
.L_800FB51C:
/* 800FB51C 000F831C  7F E3 FB 78 */	mr r3, r31
/* 800FB520 000F8320  4B FF C5 45 */	bl kar_gryakulib_get_yaku_data_checked
/* 800FB524 000F8324  2C 03 00 14 */	cmpwi r3, 0x14
/* 800FB528 000F8328  40 82 00 5C */	bne .L_800FB584
/* 800FB52C 000F832C  7F E3 FB 78 */	mr r3, r31
/* 800FB530 000F8330  4B FF C5 89 */	bl kar_gryakulib_get_yaku_state_or_none
/* 800FB534 000F8334  2C 03 00 02 */	cmpwi r3, 0x2
/* 800FB538 000F8338  40 80 00 4C */	bge .L_800FB584
/* 800FB53C 000F833C  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FB540 000F8340  40 80 00 08 */	bge .L_800FB548
/* 800FB544 000F8344  48 00 00 40 */	b .L_800FB584
.L_800FB548:
/* 800FB548 000F8348  7F E3 FB 78 */	mr r3, r31
/* 800FB54C 000F834C  38 81 00 08 */	addi r4, r1, 0x8
/* 800FB550 000F8350  4B FF C5 89 */	bl kar_gryakulib_get_model_root_position
/* 800FB554 000F8354  7F A3 EB 78 */	mr r3, r29
/* 800FB558 000F8358  38 81 00 08 */	addi r4, r1, 0x8
/* 800FB55C 000F835C  48 2D 6D 99 */	bl fn_803D22F4
/* 800FB560 000F8360  FC 01 F8 40 */	fcmpo cr0, f1, f31
/* 800FB564 000F8364  40 80 00 20 */	bge .L_800FB584
/* 800FB568 000F8368  80 61 00 08 */	lwz r3, 0x8(r1)
/* 800FB56C 000F836C  FF E0 08 90 */	fmr f31, f1
/* 800FB570 000F8370  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800FB574 000F8374  90 7E 00 00 */	stw r3, 0x0(r30)
/* 800FB578 000F8378  90 1E 00 04 */	stw r0, 0x4(r30)
/* 800FB57C 000F837C  80 01 00 10 */	lwz r0, 0x10(r1)
/* 800FB580 000F8380  90 1E 00 08 */	stw r0, 0x8(r30)
.L_800FB584:
/* 800FB584 000F8384  83 FF 00 0C */	lwz r31, 0xc(r31)
.L_800FB588:
/* 800FB588 000F8388  28 1F 00 00 */	cmplwi r31, 0x0
/* 800FB58C 000F838C  40 82 FF 90 */	bne .L_800FB51C
/* 800FB590 000F8390  3C 60 80 5E */	lis r3, lbl_805DC8BC@ha
/* 800FB594 000F8394  C0 03 C8 BC */	lfs f0, lbl_805DC8BC@l(r3)
/* 800FB598 000F8398  FC 1F 00 40 */	fcmpo cr0, f31, f0
/* 800FB59C 000F839C  40 80 00 0C */	bge .L_800FB5A8
/* 800FB5A0 000F83A0  38 60 00 01 */	li r3, 0x1
/* 800FB5A4 000F83A4  48 00 00 08 */	b .L_800FB5AC
.L_800FB5A8:
/* 800FB5A8 000F83A8  38 60 00 00 */	li r3, 0x0
.L_800FB5AC:
/* 800FB5AC 000F83AC  E3 E1 00 38 */	psq_l f31, 0x38(r1), 0, qr0
/* 800FB5B0 000F83B0  80 01 00 44 */	lwz r0, 0x44(r1)
/* 800FB5B4 000F83B4  CB E1 00 30 */	lfd f31, 0x30(r1)
/* 800FB5B8 000F83B8  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800FB5BC 000F83BC  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 800FB5C0 000F83C0  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 800FB5C4 000F83C4  7C 08 03 A6 */	mtlr r0
/* 800FB5C8 000F83C8  38 21 00 40 */	addi r1, r1, 0x40
/* 800FB5CC 000F83CC  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_find_nearest_active_recoveryzone_pos

# .text:0x934 | 0x800FB5D0 | size: 0x48
.fn kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku, global
/* 800FB5D0 000F83D0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FB5D4 000F83D4  7C 08 02 A6 */	mflr r0
/* 800FB5D8 000F83D8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FB5DC 000F83DC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FB5E0 000F83E0  7C BF 2B 78 */	mr r31, r5
/* 800FB5E4 000F83E4  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800FB5E8 000F83E8  7C 7E 1B 78 */	mr r30, r3
/* 800FB5EC 000F83EC  38 60 00 29 */	li r3, 0x29
/* 800FB5F0 000F83F0  4B FF 8E 7D */	bl kar_gryaku_create_yaku_from_main_kind
/* 800FB5F4 000F83F4  7F C4 F3 78 */	mr r4, r30
/* 800FB5F8 000F83F8  7F E5 FB 78 */	mr r5, r31
/* 800FB5FC 000F83FC  48 00 00 1D */	bl kar_gryakurecoveryzone_init_stage_indexed_kind41_joint_yaku
/* 800FB600 000F8400  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FB604 000F8404  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FB608 000F8408  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800FB60C 000F840C  7C 08 03 A6 */	mtlr r0
/* 800FB610 000F8410  38 21 00 10 */	addi r1, r1, 0x10
/* 800FB614 000F8414  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku

# .text:0x97C | 0x800FB618 | size: 0x184
.fn kar_gryakurecoveryzone_init_stage_indexed_kind41_joint_yaku, global
/* 800FB618 000F8418  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800FB61C 000F841C  7C 08 02 A6 */	mflr r0
/* 800FB620 000F8420  90 01 00 34 */	stw r0, 0x34(r1)
/* 800FB624 000F8424  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 800FB628 000F8428  F3 E1 00 28 */	psq_st f31, 0x28(r1), 0, qr0
/* 800FB62C 000F842C  39 61 00 20 */	addi r11, r1, 0x20
/* 800FB630 000F8430  48 2B 25 25 */	bl _savegpr_27
/* 800FB634 000F8434  7C 7C 1B 78 */	mr r28, r3
/* 800FB638 000F8438  80 64 00 2C */	lwz r3, 0x2c(r4)
/* 800FB63C 000F843C  83 FC 00 2C */	lwz r31, 0x2c(r28)
/* 800FB640 000F8440  7C BD 2B 78 */	mr r29, r5
/* 800FB644 000F8444  80 63 01 04 */	lwz r3, 0x104(r3)
/* 800FB648 000F8448  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 800FB64C 000F844C  83 C4 00 00 */	lwz r30, 0x0(r4)
/* 800FB650 000F8450  80 1E 00 04 */	lwz r0, 0x4(r30)
/* 800FB654 000F8454  54 00 18 38 */	slwi r0, r0, 3
/* 800FB658 000F8458  7F 63 00 2E */	lwzx r27, r3, r0
/* 800FB65C 000F845C  28 1B 00 00 */	cmplwi r27, 0x0
/* 800FB660 000F8460  40 82 00 14 */	bne .L_800FB674
/* 800FB664 000F8464  38 6D 91 58 */	li r3, kar_srcfile_jobj_h_805d6238@sda21
/* 800FB668 000F8468  38 80 02 EC */	li r4, 0x2ec
/* 800FB66C 000F846C  38 AD 91 60 */	li r5, lbl_805D6240@sda21
/* 800FB670 000F8470  48 32 CE 49 */	bl __assert
.L_800FB674:
/* 800FB674 000F8474  80 7E 00 00 */	lwz r3, 0x0(r30)
/* 800FB678 000F8478  28 1B 00 00 */	cmplwi r27, 0x0
/* 800FB67C 000F847C  C0 42 91 E0 */	lfs f2, lbl_805DF8E0@sda21(r0)
/* 800FB680 000F8480  C0 23 00 04 */	lfs f1, 0x4(r3)
/* 800FB684 000F8484  C0 1B 00 1C */	lfs f0, 0x1c(r27)
/* 800FB688 000F8488  EF E2 00 7A */	fmadds f31, f2, f1, f0
/* 800FB68C 000F848C  40 82 00 14 */	bne .L_800FB6A0
/* 800FB690 000F8490  38 6D 91 58 */	li r3, kar_srcfile_jobj_h_805d6238@sda21
/* 800FB694 000F8494  38 80 02 A4 */	li r4, 0x2a4
/* 800FB698 000F8498  38 AD 91 60 */	li r5, lbl_805D6240@sda21
/* 800FB69C 000F849C  48 32 CE 1D */	bl __assert
.L_800FB6A0:
/* 800FB6A0 000F84A0  80 1B 00 14 */	lwz r0, 0x14(r27)
/* 800FB6A4 000F84A4  54 00 03 9D */	rlwinm. r0, r0, 0, 14, 14
/* 800FB6A8 000F84A8  41 82 00 18 */	beq .L_800FB6C0
/* 800FB6AC 000F84AC  3C 80 80 4A */	lis r4, kar_gryakurecoveryzone_assert_jobj_not_quaternion@ha
/* 800FB6B0 000F84B0  38 6D 91 58 */	li r3, kar_srcfile_jobj_h_805d6238@sda21
/* 800FB6B4 000F84B4  38 A4 61 48 */	addi r5, r4, kar_gryakurecoveryzone_assert_jobj_not_quaternion@l
/* 800FB6B8 000F84B8  38 80 02 A5 */	li r4, 0x2a5
/* 800FB6BC 000F84BC  48 32 CD FD */	bl __assert
.L_800FB6C0:
/* 800FB6C0 000F84C0  D3 FB 00 1C */	stfs f31, 0x1c(r27)
/* 800FB6C4 000F84C4  80 1B 00 14 */	lwz r0, 0x14(r27)
/* 800FB6C8 000F84C8  54 00 01 8D */	rlwinm. r0, r0, 0, 6, 6
/* 800FB6CC 000F84CC  40 82 00 4C */	bne .L_800FB718
/* 800FB6D0 000F84D0  28 1B 00 00 */	cmplwi r27, 0x0
/* 800FB6D4 000F84D4  41 82 00 44 */	beq .L_800FB718
/* 800FB6D8 000F84D8  40 82 00 14 */	bne .L_800FB6EC
/* 800FB6DC 000F84DC  38 6D 91 58 */	li r3, kar_srcfile_jobj_h_805d6238@sda21
/* 800FB6E0 000F84E0  38 80 02 5D */	li r4, 0x25d
/* 800FB6E4 000F84E4  38 AD 91 60 */	li r5, lbl_805D6240@sda21
/* 800FB6E8 000F84E8  48 32 CD D1 */	bl __assert
.L_800FB6EC:
/* 800FB6EC 000F84EC  80 9B 00 14 */	lwz r4, 0x14(r27)
/* 800FB6F0 000F84F0  38 60 00 00 */	li r3, 0x0
/* 800FB6F4 000F84F4  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 800FB6F8 000F84F8  40 82 00 10 */	bne .L_800FB708
/* 800FB6FC 000F84FC  54 80 06 73 */	rlwinm. r0, r4, 0, 25, 25
/* 800FB700 000F8500  41 82 00 08 */	beq .L_800FB708
/* 800FB704 000F8504  38 60 00 01 */	li r3, 0x1
.L_800FB708:
/* 800FB708 000F8508  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FB70C 000F850C  40 82 00 0C */	bne .L_800FB718
/* 800FB710 000F8510  7F 63 DB 78 */	mr r3, r27
/* 800FB714 000F8514  48 31 22 19 */	bl HSD_JObjSetMtxDirtySub
.L_800FB718:
/* 800FB718 000F8518  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 800FB71C 000F851C  7F 64 DB 78 */	mr r4, r27
/* 800FB720 000F8520  38 63 00 54 */	addi r3, r3, 0x54
/* 800FB724 000F8524  4B FD C2 31 */	bl kar_grcoll__800d7954
/* 800FB728 000F8528  90 7F 01 30 */	stw r3, 0x130(r31)
/* 800FB72C 000F852C  38 80 00 00 */	li r4, 0x0
/* 800FB730 000F8530  C0 02 91 E4 */	lfs f0, lbl_805DF8E4@sda21(r0)
/* 800FB734 000F8534  D0 1F 01 34 */	stfs f0, 0x134(r31)
/* 800FB738 000F8538  90 9F 01 40 */	stw r4, 0x140(r31)
/* 800FB73C 000F853C  88 1F 01 44 */	lbz r0, 0x144(r31)
/* 800FB740 000F8540  53 A0 3E 30 */	rlwimi r0, r29, 7, 24, 24
/* 800FB744 000F8544  98 1F 01 44 */	stb r0, 0x144(r31)
/* 800FB748 000F8548  88 1F 01 44 */	lbz r0, 0x144(r31)
/* 800FB74C 000F854C  50 80 36 72 */	rlwimi r0, r4, 6, 25, 25
/* 800FB750 000F8550  98 1F 01 44 */	stb r0, 0x144(r31)
/* 800FB754 000F8554  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800FB758 000F8558  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800FB75C 000F855C  28 00 00 00 */	cmplwi r0, 0x0
/* 800FB760 000F8560  41 82 00 14 */	beq .L_800FB774
/* 800FB764 000F8564  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 800FB768 000F8568  7F 83 E3 78 */	mr r3, r28
/* 800FB76C 000F856C  38 A0 00 00 */	li r5, 0x0
/* 800FB770 000F8570  4B FF C1 01 */	bl kar_gryakuaudio_configure_fgm_track_from_joint
.L_800FB774:
/* 800FB774 000F8574  7F 83 E3 78 */	mr r3, r28
/* 800FB778 000F8578  48 00 00 25 */	bl kar_gryakurecoveryzone_start_kind41_joint_idle_motion
/* 800FB77C 000F857C  E3 E1 00 28 */	psq_l f31, 0x28(r1), 0, qr0
/* 800FB780 000F8580  39 61 00 20 */	addi r11, r1, 0x20
/* 800FB784 000F8584  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 800FB788 000F8588  48 2B 24 19 */	bl _restgpr_27
/* 800FB78C 000F858C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800FB790 000F8590  7C 08 03 A6 */	mtlr r0
/* 800FB794 000F8594  38 21 00 30 */	addi r1, r1, 0x30
/* 800FB798 000F8598  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_init_stage_indexed_kind41_joint_yaku

# .text:0xB00 | 0x800FB79C | size: 0x74
.fn kar_gryakurecoveryzone_start_kind41_joint_idle_motion, global
/* 800FB79C 000F859C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FB7A0 000F85A0  7C 08 02 A6 */	mflr r0
/* 800FB7A4 000F85A4  38 80 00 00 */	li r4, 0x0
/* 800FB7A8 000F85A8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FB7AC 000F85AC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FB7B0 000F85B0  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800FB7B4 000F85B4  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800FB7B8 000F85B8  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800FB7BC 000F85BC  83 C3 00 00 */	lwz r30, 0x0(r3)
/* 800FB7C0 000F85C0  80 7E 00 00 */	lwz r3, 0x0(r30)
/* 800FB7C4 000F85C4  80 03 00 18 */	lwz r0, 0x18(r3)
/* 800FB7C8 000F85C8  90 1F 01 40 */	stw r0, 0x140(r31)
/* 800FB7CC 000F85CC  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 800FB7D0 000F85D0  4B FD C3 01 */	bl kar_grcoll__near_800d7ad0
/* 800FB7D4 000F85D4  C0 22 91 E4 */	lfs f1, lbl_805DF8E4@sda21(r0)
/* 800FB7D8 000F85D8  7F E3 FB 78 */	mr r3, r31
/* 800FB7DC 000F85DC  80 BE 00 0C */	lwz r5, 0xc(r30)
/* 800FB7E0 000F85E0  38 80 00 00 */	li r4, 0x0
/* 800FB7E4 000F85E4  FC 40 08 90 */	fmr f2, f1
/* 800FB7E8 000F85E8  80 DE 00 08 */	lwz r6, 0x8(r30)
/* 800FB7EC 000F85EC  FC 60 08 90 */	fmr f3, f1
/* 800FB7F0 000F85F0  38 E0 00 00 */	li r7, 0x0
/* 800FB7F4 000F85F4  4B FF 9D 55 */	bl kar_gryaku_set_path_node_motion
/* 800FB7F8 000F85F8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FB7FC 000F85FC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FB800 000F8600  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800FB804 000F8604  7C 08 03 A6 */	mtlr r0
/* 800FB808 000F8608  38 21 00 10 */	addi r1, r1, 0x10
/* 800FB80C 000F860C  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_start_kind41_joint_idle_motion

# .text:0xB74 | 0x800FB810 | size: 0xCC
.fn kar_gryakurecoveryzone_update_kind41_wait_then_extend, global
/* 800FB810 000F8610  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FB814 000F8614  7C 08 02 A6 */	mflr r0
/* 800FB818 000F8618  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FB81C 000F861C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FB820 000F8620  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800FB824 000F8624  80 A3 00 2C */	lwz r5, 0x2c(r3)
/* 800FB828 000F8628  80 85 01 40 */	lwz r4, 0x140(r5)
/* 800FB82C 000F862C  2C 04 00 00 */	cmpwi r4, 0x0
/* 800FB830 000F8630  40 81 00 0C */	ble .L_800FB83C
/* 800FB834 000F8634  38 04 FF FF */	subi r0, r4, 0x1
/* 800FB838 000F8638  90 05 01 40 */	stw r0, 0x140(r5)
.L_800FB83C:
/* 800FB83C 000F863C  88 05 01 44 */	lbz r0, 0x144(r5)
/* 800FB840 000F8640  54 00 CF FF */	extrwi. r0, r0, 1, 24
/* 800FB844 000F8644  41 82 00 10 */	beq .L_800FB854
/* 800FB848 000F8648  80 05 01 40 */	lwz r0, 0x140(r5)
/* 800FB84C 000F864C  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FB850 000F8650  40 81 00 10 */	ble .L_800FB860
.L_800FB854:
/* 800FB854 000F8654  88 05 01 44 */	lbz r0, 0x144(r5)
/* 800FB858 000F8658  54 00 D7 FF */	extrwi. r0, r0, 1, 25
/* 800FB85C 000F865C  41 82 00 68 */	beq .L_800FB8C4
.L_800FB860:
/* 800FB860 000F8660  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 800FB864 000F8664  38 60 00 00 */	li r3, 0x0
/* 800FB868 000F8668  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 800FB86C 000F866C  83 E4 00 00 */	lwz r31, 0x0(r4)
/* 800FB870 000F8670  80 9F 00 00 */	lwz r4, 0x0(r31)
/* 800FB874 000F8674  80 04 00 10 */	lwz r0, 0x10(r4)
/* 800FB878 000F8678  90 1E 01 40 */	stw r0, 0x140(r30)
/* 800FB87C 000F867C  88 1E 01 44 */	lbz r0, 0x144(r30)
/* 800FB880 000F8680  50 60 36 72 */	rlwimi r0, r3, 6, 25, 25
/* 800FB884 000F8684  98 1E 01 44 */	stb r0, 0x144(r30)
/* 800FB888 000F8688  80 1E 01 1C */	lwz r0, 0x11c(r30)
/* 800FB88C 000F868C  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FB890 000F8690  40 81 00 10 */	ble .L_800FB8A0
/* 800FB894 000F8694  38 7E 01 18 */	addi r3, r30, 0x118
/* 800FB898 000F8698  38 80 00 00 */	li r4, 0x0
/* 800FB89C 000F869C  4B FE E7 E9 */	bl kar_graudio_play_fgm_entry_id
.L_800FB8A0:
/* 800FB8A0 000F86A0  C0 22 91 E4 */	lfs f1, lbl_805DF8E4@sda21(r0)
/* 800FB8A4 000F86A4  7F C3 F3 78 */	mr r3, r30
/* 800FB8A8 000F86A8  80 BF 00 0C */	lwz r5, 0xc(r31)
/* 800FB8AC 000F86AC  38 80 00 01 */	li r4, 0x1
/* 800FB8B0 000F86B0  FC 60 08 90 */	fmr f3, f1
/* 800FB8B4 000F86B4  80 DF 00 08 */	lwz r6, 0x8(r31)
/* 800FB8B8 000F86B8  C0 42 91 E8 */	lfs f2, lbl_805DF8E8@sda21(r0)
/* 800FB8BC 000F86BC  38 E0 00 00 */	li r7, 0x0
/* 800FB8C0 000F86C0  4B FF 9C 89 */	bl kar_gryaku_set_path_node_motion
.L_800FB8C4:
/* 800FB8C4 000F86C4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FB8C8 000F86C8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FB8CC 000F86CC  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800FB8D0 000F86D0  7C 08 03 A6 */	mtlr r0
/* 800FB8D4 000F86D4  38 21 00 10 */	addi r1, r1, 0x10
/* 800FB8D8 000F86D8  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_update_kind41_wait_then_extend

# .text:0xC40 | 0x800FB8DC | size: 0x128
.fn kar_gryakurecoveryzone_begin_kind41_extend_angle, global
/* 800FB8DC 000F86DC  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800FB8E0 000F86E0  7C 08 02 A6 */	mflr r0
/* 800FB8E4 000F86E4  90 01 00 34 */	stw r0, 0x34(r1)
/* 800FB8E8 000F86E8  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 800FB8EC 000F86EC  F3 E1 00 28 */	psq_st f31, 0x28(r1), 0, qr0
/* 800FB8F0 000F86F0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800FB8F4 000F86F4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800FB8F8 000F86F8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800FB8FC 000F86FC  80 A3 00 2C */	lwz r5, 0x2c(r3)
/* 800FB900 000F8700  80 85 01 40 */	lwz r4, 0x140(r5)
/* 800FB904 000F8704  2C 04 00 00 */	cmpwi r4, 0x0
/* 800FB908 000F8708  40 81 00 D8 */	ble .L_800FB9E0
/* 800FB90C 000F870C  38 04 FF FF */	subi r0, r4, 0x1
/* 800FB910 000F8710  90 05 01 40 */	stw r0, 0x140(r5)
/* 800FB914 000F8714  80 05 01 40 */	lwz r0, 0x140(r5)
/* 800FB918 000F8718  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FB91C 000F871C  41 81 00 C4 */	bgt .L_800FB9E0
/* 800FB920 000F8720  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 800FB924 000F8724  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 800FB928 000F8728  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 800FB92C 000F872C  C8 42 91 F0 */	lfd f2, lbl_805DF8F0@sda21(r0)
/* 800FB930 000F8730  83 E4 00 00 */	lwz r31, 0x0(r4)
/* 800FB934 000F8734  80 83 01 04 */	lwz r4, 0x104(r3)
/* 800FB938 000F8738  80 7F 00 00 */	lwz r3, 0x0(r31)
/* 800FB93C 000F873C  80 1F 00 04 */	lwz r0, 0x4(r31)
/* 800FB940 000F8740  C0 03 00 08 */	lfs f0, 0x8(r3)
/* 800FB944 000F8744  54 00 18 38 */	slwi r0, r0, 3
/* 800FB948 000F8748  C0 22 91 E0 */	lfs f1, lbl_805DF8E0@sda21(r0)
/* 800FB94C 000F874C  FC 60 02 10 */	fabs f3, f0
/* 800FB950 000F8750  C0 03 00 00 */	lfs f0, 0x0(r3)
/* 800FB954 000F8754  7F A4 00 2E */	lwzx r29, r4, r0
/* 800FB958 000F8758  EC 01 00 32 */	fmuls f0, f1, f0
/* 800FB95C 000F875C  FF E2 00 F2 */	fmul f31, f2, f3
/* 800FB960 000F8760  28 1D 00 00 */	cmplwi r29, 0x0
/* 800FB964 000F8764  D0 1E 01 34 */	stfs f0, 0x134(r30)
/* 800FB968 000F8768  FF E0 F8 18 */	frsp f31, f31
/* 800FB96C 000F876C  40 82 00 14 */	bne .L_800FB980
/* 800FB970 000F8770  38 6D 91 58 */	li r3, kar_srcfile_jobj_h_805d6238@sda21
/* 800FB974 000F8774  38 80 02 EC */	li r4, 0x2ec
/* 800FB978 000F8778  38 AD 91 60 */	li r5, lbl_805D6240@sda21
/* 800FB97C 000F877C  48 32 CB 3D */	bl __assert
.L_800FB980:
/* 800FB980 000F8780  C0 5E 01 34 */	lfs f2, 0x134(r30)
/* 800FB984 000F8784  C0 3D 00 1C */	lfs f1, 0x1c(r29)
/* 800FB988 000F8788  C0 02 91 E4 */	lfs f0, lbl_805DF8E4@sda21(r0)
/* 800FB98C 000F878C  EC 22 08 28 */	fsubs f1, f2, f1
/* 800FB990 000F8790  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800FB994 000F8794  4C 41 13 82 */	cror eq, gt, eq
/* 800FB998 000F8798  40 82 00 08 */	bne .L_800FB9A0
/* 800FB99C 000F879C  48 00 00 08 */	b .L_800FB9A4
.L_800FB9A0:
/* 800FB9A0 000F87A0  FF E0 F8 50 */	fneg f31, f31
.L_800FB9A4:
/* 800FB9A4 000F87A4  D3 FE 01 38 */	stfs f31, 0x138(r30)
/* 800FB9A8 000F87A8  38 00 00 00 */	li r0, 0x0
/* 800FB9AC 000F87AC  38 80 00 01 */	li r4, 0x1
/* 800FB9B0 000F87B0  90 1E 01 40 */	stw r0, 0x140(r30)
/* 800FB9B4 000F87B4  80 7E 01 30 */	lwz r3, 0x130(r30)
/* 800FB9B8 000F87B8  4B FD C1 19 */	bl kar_grcoll__near_800d7ad0
/* 800FB9BC 000F87BC  C0 22 91 E4 */	lfs f1, lbl_805DF8E4@sda21(r0)
/* 800FB9C0 000F87C0  7F C3 F3 78 */	mr r3, r30
/* 800FB9C4 000F87C4  80 BF 00 0C */	lwz r5, 0xc(r31)
/* 800FB9C8 000F87C8  38 80 00 02 */	li r4, 0x2
/* 800FB9CC 000F87CC  FC 60 08 90 */	fmr f3, f1
/* 800FB9D0 000F87D0  80 DF 00 08 */	lwz r6, 0x8(r31)
/* 800FB9D4 000F87D4  C0 42 91 E8 */	lfs f2, lbl_805DF8E8@sda21(r0)
/* 800FB9D8 000F87D8  38 E0 00 04 */	li r7, 0x4
/* 800FB9DC 000F87DC  4B FF 9B 6D */	bl kar_gryaku_set_path_node_motion
.L_800FB9E0:
/* 800FB9E0 000F87E0  E3 E1 00 28 */	psq_l f31, 0x28(r1), 0, qr0
/* 800FB9E4 000F87E4  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800FB9E8 000F87E8  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 800FB9EC 000F87EC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800FB9F0 000F87F0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800FB9F4 000F87F4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800FB9F8 000F87F8  7C 08 03 A6 */	mtlr r0
/* 800FB9FC 000F87FC  38 21 00 30 */	addi r1, r1, 0x30
/* 800FBA00 000F8800  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_begin_kind41_extend_angle

# .text:0xD68 | 0x800FBA04 | size: 0x200
.fn kar_gryakurecoveryzone_update_kind41_extend_angle, global
/* 800FBA04 000F8804  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800FBA08 000F8808  7C 08 02 A6 */	mflr r0
/* 800FBA0C 000F880C  90 01 00 34 */	stw r0, 0x34(r1)
/* 800FBA10 000F8810  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 800FBA14 000F8814  F3 E1 00 28 */	psq_st f31, 0x28(r1), 0, qr0
/* 800FBA18 000F8818  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800FBA1C 000F881C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800FBA20 000F8820  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800FBA24 000F8824  93 81 00 10 */	stw r28, 0x10(r1)
/* 800FBA28 000F8828  7C 7F 1B 78 */	mr r31, r3
/* 800FBA2C 000F882C  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 800FBA30 000F8830  83 BF 00 2C */	lwz r29, 0x2c(r31)
/* 800FBA34 000F8834  80 63 01 04 */	lwz r3, 0x104(r3)
/* 800FBA38 000F8838  80 9D 00 08 */	lwz r4, 0x8(r29)
/* 800FBA3C 000F883C  83 84 00 00 */	lwz r28, 0x0(r4)
/* 800FBA40 000F8840  80 1C 00 04 */	lwz r0, 0x4(r28)
/* 800FBA44 000F8844  54 00 18 38 */	slwi r0, r0, 3
/* 800FBA48 000F8848  7F C3 00 2E */	lwzx r30, r3, r0
/* 800FBA4C 000F884C  28 1E 00 00 */	cmplwi r30, 0x0
/* 800FBA50 000F8850  40 82 00 14 */	bne .L_800FBA64
/* 800FBA54 000F8854  38 6D 91 58 */	li r3, kar_srcfile_jobj_h_805d6238@sda21
/* 800FBA58 000F8858  38 80 02 EC */	li r4, 0x2ec
/* 800FBA5C 000F885C  38 AD 91 60 */	li r5, lbl_805D6240@sda21
/* 800FBA60 000F8860  48 32 CA 59 */	bl __assert
.L_800FBA64:
/* 800FBA64 000F8864  80 7C 00 00 */	lwz r3, 0x0(r28)
/* 800FBA68 000F8868  C3 FD 01 34 */	lfs f31, 0x134(r29)
/* 800FBA6C 000F886C  C0 5E 00 1C */	lfs f2, 0x1c(r30)
/* 800FBA70 000F8870  C0 22 91 E0 */	lfs f1, lbl_805DF8E0@sda21(r0)
/* 800FBA74 000F8874  C0 03 00 08 */	lfs f0, 0x8(r3)
/* 800FBA78 000F8878  EC 5F 10 28 */	fsubs f2, f31, f2
/* 800FBA7C 000F887C  EC 01 00 32 */	fmuls f0, f1, f0
/* 800FBA80 000F8880  FC 20 12 10 */	fabs f1, f2
/* 800FBA84 000F8884  FC 00 02 10 */	fabs f0, f0
/* 800FBA88 000F8888  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800FBA8C 000F888C  4C 40 13 82 */	cror eq, lt, eq
/* 800FBA90 000F8890  40 82 00 D0 */	bne .L_800FBB60
/* 800FBA94 000F8894  28 1E 00 00 */	cmplwi r30, 0x0
/* 800FBA98 000F8898  40 82 00 14 */	bne .L_800FBAAC
/* 800FBA9C 000F889C  38 6D 91 58 */	li r3, kar_srcfile_jobj_h_805d6238@sda21
/* 800FBAA0 000F88A0  38 80 02 A4 */	li r4, 0x2a4
/* 800FBAA4 000F88A4  38 AD 91 60 */	li r5, lbl_805D6240@sda21
/* 800FBAA8 000F88A8  48 32 CA 11 */	bl __assert
.L_800FBAAC:
/* 800FBAAC 000F88AC  80 1E 00 14 */	lwz r0, 0x14(r30)
/* 800FBAB0 000F88B0  54 00 03 9D */	rlwinm. r0, r0, 0, 14, 14
/* 800FBAB4 000F88B4  41 82 00 18 */	beq .L_800FBACC
/* 800FBAB8 000F88B8  3C 80 80 4A */	lis r4, kar_gryakurecoveryzone_assert_jobj_not_quaternion@ha
/* 800FBABC 000F88BC  38 6D 91 58 */	li r3, kar_srcfile_jobj_h_805d6238@sda21
/* 800FBAC0 000F88C0  38 A4 61 48 */	addi r5, r4, kar_gryakurecoveryzone_assert_jobj_not_quaternion@l
/* 800FBAC4 000F88C4  38 80 02 A5 */	li r4, 0x2a5
/* 800FBAC8 000F88C8  48 32 C9 F1 */	bl __assert
.L_800FBACC:
/* 800FBACC 000F88CC  D3 FE 00 1C */	stfs f31, 0x1c(r30)
/* 800FBAD0 000F88D0  80 1E 00 14 */	lwz r0, 0x14(r30)
/* 800FBAD4 000F88D4  54 00 01 8D */	rlwinm. r0, r0, 0, 6, 6
/* 800FBAD8 000F88D8  40 82 00 4C */	bne .L_800FBB24
/* 800FBADC 000F88DC  28 1E 00 00 */	cmplwi r30, 0x0
/* 800FBAE0 000F88E0  41 82 00 44 */	beq .L_800FBB24
/* 800FBAE4 000F88E4  40 82 00 14 */	bne .L_800FBAF8
/* 800FBAE8 000F88E8  38 6D 91 58 */	li r3, kar_srcfile_jobj_h_805d6238@sda21
/* 800FBAEC 000F88EC  38 80 02 5D */	li r4, 0x25d
/* 800FBAF0 000F88F0  38 AD 91 60 */	li r5, lbl_805D6240@sda21
/* 800FBAF4 000F88F4  48 32 C9 C5 */	bl __assert
.L_800FBAF8:
/* 800FBAF8 000F88F8  80 9E 00 14 */	lwz r4, 0x14(r30)
/* 800FBAFC 000F88FC  38 60 00 00 */	li r3, 0x0
/* 800FBB00 000F8900  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 800FBB04 000F8904  40 82 00 10 */	bne .L_800FBB14
/* 800FBB08 000F8908  54 80 06 73 */	rlwinm. r0, r4, 0, 25, 25
/* 800FBB0C 000F890C  41 82 00 08 */	beq .L_800FBB14
/* 800FBB10 000F8910  38 60 00 01 */	li r3, 0x1
.L_800FBB14:
/* 800FBB14 000F8914  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FBB18 000F8918  40 82 00 0C */	bne .L_800FBB24
/* 800FBB1C 000F891C  7F C3 F3 78 */	mr r3, r30
/* 800FBB20 000F8920  48 31 1E 0D */	bl HSD_JObjSetMtxDirtySub
.L_800FBB24:
/* 800FBB24 000F8924  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 800FBB28 000F8928  38 80 00 03 */	li r4, 0x3
/* 800FBB2C 000F892C  C0 22 91 E4 */	lfs f1, lbl_805DF8E4@sda21(r0)
/* 800FBB30 000F8930  38 E0 00 04 */	li r7, 0x4
/* 800FBB34 000F8934  80 A3 00 08 */	lwz r5, 0x8(r3)
/* 800FBB38 000F8938  FC 60 08 90 */	fmr f3, f1
/* 800FBB3C 000F893C  C0 42 91 E8 */	lfs f2, lbl_805DF8E8@sda21(r0)
/* 800FBB40 000F8940  80 C5 00 00 */	lwz r6, 0x0(r5)
/* 800FBB44 000F8944  80 A6 00 00 */	lwz r5, 0x0(r6)
/* 800FBB48 000F8948  80 05 00 14 */	lwz r0, 0x14(r5)
/* 800FBB4C 000F894C  90 03 01 40 */	stw r0, 0x140(r3)
/* 800FBB50 000F8950  80 A6 00 0C */	lwz r5, 0xc(r6)
/* 800FBB54 000F8954  80 C6 00 08 */	lwz r6, 0x8(r6)
/* 800FBB58 000F8958  4B FF 99 F1 */	bl kar_gryaku_set_path_node_motion
/* 800FBB5C 000F895C  48 00 00 80 */	b .L_800FBBDC
.L_800FBB60:
/* 800FBB60 000F8960  28 1E 00 00 */	cmplwi r30, 0x0
/* 800FBB64 000F8964  C3 FD 01 38 */	lfs f31, 0x138(r29)
/* 800FBB68 000F8968  40 82 00 14 */	bne .L_800FBB7C
/* 800FBB6C 000F896C  38 6D 91 58 */	li r3, kar_srcfile_jobj_h_805d6238@sda21
/* 800FBB70 000F8970  38 80 04 12 */	li r4, 0x412
/* 800FBB74 000F8974  38 AD 91 60 */	li r5, lbl_805D6240@sda21
/* 800FBB78 000F8978  48 32 C9 41 */	bl __assert
.L_800FBB7C:
/* 800FBB7C 000F897C  C0 1E 00 1C */	lfs f0, 0x1c(r30)
/* 800FBB80 000F8980  EC 00 F8 2A */	fadds f0, f0, f31
/* 800FBB84 000F8984  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 800FBB88 000F8988  80 1E 00 14 */	lwz r0, 0x14(r30)
/* 800FBB8C 000F898C  54 00 01 8D */	rlwinm. r0, r0, 0, 6, 6
/* 800FBB90 000F8990  40 82 00 4C */	bne .L_800FBBDC
/* 800FBB94 000F8994  28 1E 00 00 */	cmplwi r30, 0x0
/* 800FBB98 000F8998  41 82 00 44 */	beq .L_800FBBDC
/* 800FBB9C 000F899C  40 82 00 14 */	bne .L_800FBBB0
/* 800FBBA0 000F89A0  38 6D 91 58 */	li r3, kar_srcfile_jobj_h_805d6238@sda21
/* 800FBBA4 000F89A4  38 80 02 5D */	li r4, 0x25d
/* 800FBBA8 000F89A8  38 AD 91 60 */	li r5, lbl_805D6240@sda21
/* 800FBBAC 000F89AC  48 32 C9 0D */	bl __assert
.L_800FBBB0:
/* 800FBBB0 000F89B0  80 9E 00 14 */	lwz r4, 0x14(r30)
/* 800FBBB4 000F89B4  38 60 00 00 */	li r3, 0x0
/* 800FBBB8 000F89B8  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 800FBBBC 000F89BC  40 82 00 10 */	bne .L_800FBBCC
/* 800FBBC0 000F89C0  54 80 06 73 */	rlwinm. r0, r4, 0, 25, 25
/* 800FBBC4 000F89C4  41 82 00 08 */	beq .L_800FBBCC
/* 800FBBC8 000F89C8  38 60 00 01 */	li r3, 0x1
.L_800FBBCC:
/* 800FBBCC 000F89CC  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FBBD0 000F89D0  40 82 00 0C */	bne .L_800FBBDC
/* 800FBBD4 000F89D4  7F C3 F3 78 */	mr r3, r30
/* 800FBBD8 000F89D8  48 31 1D 55 */	bl HSD_JObjSetMtxDirtySub
.L_800FBBDC:
/* 800FBBDC 000F89DC  E3 E1 00 28 */	psq_l f31, 0x28(r1), 0, qr0
/* 800FBBE0 000F89E0  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800FBBE4 000F89E4  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 800FBBE8 000F89E8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800FBBEC 000F89EC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800FBBF0 000F89F0  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800FBBF4 000F89F4  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800FBBF8 000F89F8  7C 08 03 A6 */	mtlr r0
/* 800FBBFC 000F89FC  38 21 00 30 */	addi r1, r1, 0x30
/* 800FBC00 000F8A00  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_update_kind41_extend_angle

# .text:0xF68 | 0x800FBC04 | size: 0x14C
.fn kar_gryakurecoveryzone_begin_kind41_return_angle, global
/* 800FBC04 000F8A04  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800FBC08 000F8A08  7C 08 02 A6 */	mflr r0
/* 800FBC0C 000F8A0C  90 01 00 34 */	stw r0, 0x34(r1)
/* 800FBC10 000F8A10  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 800FBC14 000F8A14  F3 E1 00 28 */	psq_st f31, 0x28(r1), 0, qr0
/* 800FBC18 000F8A18  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800FBC1C 000F8A1C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800FBC20 000F8A20  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800FBC24 000F8A24  80 A3 00 2C */	lwz r5, 0x2c(r3)
/* 800FBC28 000F8A28  80 85 01 40 */	lwz r4, 0x140(r5)
/* 800FBC2C 000F8A2C  2C 04 00 00 */	cmpwi r4, 0x0
/* 800FBC30 000F8A30  40 81 00 FC */	ble .L_800FBD2C
/* 800FBC34 000F8A34  38 04 FF FF */	subi r0, r4, 0x1
/* 800FBC38 000F8A38  90 05 01 40 */	stw r0, 0x140(r5)
/* 800FBC3C 000F8A3C  80 05 01 40 */	lwz r0, 0x140(r5)
/* 800FBC40 000F8A40  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FBC44 000F8A44  41 81 00 E8 */	bgt .L_800FBD2C
/* 800FBC48 000F8A48  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 800FBC4C 000F8A4C  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 800FBC50 000F8A50  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 800FBC54 000F8A54  C8 42 91 F0 */	lfd f2, lbl_805DF8F0@sda21(r0)
/* 800FBC58 000F8A58  83 E4 00 00 */	lwz r31, 0x0(r4)
/* 800FBC5C 000F8A5C  80 83 01 04 */	lwz r4, 0x104(r3)
/* 800FBC60 000F8A60  80 7F 00 00 */	lwz r3, 0x0(r31)
/* 800FBC64 000F8A64  80 1F 00 04 */	lwz r0, 0x4(r31)
/* 800FBC68 000F8A68  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 800FBC6C 000F8A6C  54 00 18 38 */	slwi r0, r0, 3
/* 800FBC70 000F8A70  C0 22 91 E0 */	lfs f1, lbl_805DF8E0@sda21(r0)
/* 800FBC74 000F8A74  FC 60 02 10 */	fabs f3, f0
/* 800FBC78 000F8A78  C0 03 00 04 */	lfs f0, 0x4(r3)
/* 800FBC7C 000F8A7C  7F A4 00 2E */	lwzx r29, r4, r0
/* 800FBC80 000F8A80  EC 01 00 32 */	fmuls f0, f1, f0
/* 800FBC84 000F8A84  FF E2 00 F2 */	fmul f31, f2, f3
/* 800FBC88 000F8A88  28 1D 00 00 */	cmplwi r29, 0x0
/* 800FBC8C 000F8A8C  D0 1E 01 34 */	stfs f0, 0x134(r30)
/* 800FBC90 000F8A90  FF E0 F8 18 */	frsp f31, f31
/* 800FBC94 000F8A94  40 82 00 14 */	bne .L_800FBCA8
/* 800FBC98 000F8A98  38 6D 91 58 */	li r3, kar_srcfile_jobj_h_805d6238@sda21
/* 800FBC9C 000F8A9C  38 80 02 EC */	li r4, 0x2ec
/* 800FBCA0 000F8AA0  38 AD 91 60 */	li r5, lbl_805D6240@sda21
/* 800FBCA4 000F8AA4  48 32 C8 15 */	bl __assert
.L_800FBCA8:
/* 800FBCA8 000F8AA8  C0 5E 01 34 */	lfs f2, 0x134(r30)
/* 800FBCAC 000F8AAC  C0 3D 00 1C */	lfs f1, 0x1c(r29)
/* 800FBCB0 000F8AB0  C0 02 91 E4 */	lfs f0, lbl_805DF8E4@sda21(r0)
/* 800FBCB4 000F8AB4  EC 22 08 28 */	fsubs f1, f2, f1
/* 800FBCB8 000F8AB8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800FBCBC 000F8ABC  4C 41 13 82 */	cror eq, gt, eq
/* 800FBCC0 000F8AC0  40 82 00 08 */	bne .L_800FBCC8
/* 800FBCC4 000F8AC4  48 00 00 08 */	b .L_800FBCCC
.L_800FBCC8:
/* 800FBCC8 000F8AC8  FF E0 F8 50 */	fneg f31, f31
.L_800FBCCC:
/* 800FBCCC 000F8ACC  D3 FE 01 38 */	stfs f31, 0x138(r30)
/* 800FBCD0 000F8AD0  38 00 00 00 */	li r0, 0x0
/* 800FBCD4 000F8AD4  90 1E 01 40 */	stw r0, 0x140(r30)
/* 800FBCD8 000F8AD8  80 BF 00 10 */	lwz r5, 0x10(r31)
/* 800FBCDC 000F8ADC  2C 05 FF FF */	cmpwi r5, -0x1
/* 800FBCE0 000F8AE0  41 82 00 28 */	beq .L_800FBD08
/* 800FBCE4 000F8AE4  C0 22 91 E4 */	lfs f1, lbl_805DF8E4@sda21(r0)
/* 800FBCE8 000F8AE8  7F C3 F3 78 */	mr r3, r30
/* 800FBCEC 000F8AEC  80 DF 00 08 */	lwz r6, 0x8(r31)
/* 800FBCF0 000F8AF0  38 80 00 04 */	li r4, 0x4
/* 800FBCF4 000F8AF4  FC 60 08 90 */	fmr f3, f1
/* 800FBCF8 000F8AF8  C0 42 91 E8 */	lfs f2, lbl_805DF8E8@sda21(r0)
/* 800FBCFC 000F8AFC  38 E0 00 00 */	li r7, 0x0
/* 800FBD00 000F8B00  4B FF 98 49 */	bl kar_gryaku_set_path_node_motion
/* 800FBD04 000F8B04  48 00 00 28 */	b .L_800FBD2C
.L_800FBD08:
/* 800FBD08 000F8B08  C0 22 91 E4 */	lfs f1, lbl_805DF8E4@sda21(r0)
/* 800FBD0C 000F8B0C  7F C3 F3 78 */	mr r3, r30
/* 800FBD10 000F8B10  80 BF 00 0C */	lwz r5, 0xc(r31)
/* 800FBD14 000F8B14  38 80 00 04 */	li r4, 0x4
/* 800FBD18 000F8B18  FC 60 08 90 */	fmr f3, f1
/* 800FBD1C 000F8B1C  80 DF 00 08 */	lwz r6, 0x8(r31)
/* 800FBD20 000F8B20  C0 42 91 E8 */	lfs f2, lbl_805DF8E8@sda21(r0)
/* 800FBD24 000F8B24  38 E0 00 04 */	li r7, 0x4
/* 800FBD28 000F8B28  4B FF 98 21 */	bl kar_gryaku_set_path_node_motion
.L_800FBD2C:
/* 800FBD2C 000F8B2C  E3 E1 00 28 */	psq_l f31, 0x28(r1), 0, qr0
/* 800FBD30 000F8B30  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800FBD34 000F8B34  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 800FBD38 000F8B38  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800FBD3C 000F8B3C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800FBD40 000F8B40  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800FBD44 000F8B44  7C 08 03 A6 */	mtlr r0
/* 800FBD48 000F8B48  38 21 00 30 */	addi r1, r1, 0x30
/* 800FBD4C 000F8B4C  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_begin_kind41_return_angle

# .text:0x10B4 | 0x800FBD50 | size: 0x210
.fn kar_gryakurecoveryzone_update_kind41_return_angle, global
/* 800FBD50 000F8B50  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800FBD54 000F8B54  7C 08 02 A6 */	mflr r0
/* 800FBD58 000F8B58  90 01 00 34 */	stw r0, 0x34(r1)
/* 800FBD5C 000F8B5C  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 800FBD60 000F8B60  F3 E1 00 28 */	psq_st f31, 0x28(r1), 0, qr0
/* 800FBD64 000F8B64  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800FBD68 000F8B68  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800FBD6C 000F8B6C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800FBD70 000F8B70  93 81 00 10 */	stw r28, 0x10(r1)
/* 800FBD74 000F8B74  7C 7F 1B 78 */	mr r31, r3
/* 800FBD78 000F8B78  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 800FBD7C 000F8B7C  83 BF 00 2C */	lwz r29, 0x2c(r31)
/* 800FBD80 000F8B80  80 63 01 04 */	lwz r3, 0x104(r3)
/* 800FBD84 000F8B84  80 9D 00 08 */	lwz r4, 0x8(r29)
/* 800FBD88 000F8B88  83 84 00 00 */	lwz r28, 0x0(r4)
/* 800FBD8C 000F8B8C  80 1C 00 04 */	lwz r0, 0x4(r28)
/* 800FBD90 000F8B90  54 00 18 38 */	slwi r0, r0, 3
/* 800FBD94 000F8B94  7F C3 00 2E */	lwzx r30, r3, r0
/* 800FBD98 000F8B98  28 1E 00 00 */	cmplwi r30, 0x0
/* 800FBD9C 000F8B9C  40 82 00 14 */	bne .L_800FBDB0
/* 800FBDA0 000F8BA0  38 6D 91 58 */	li r3, kar_srcfile_jobj_h_805d6238@sda21
/* 800FBDA4 000F8BA4  38 80 02 EC */	li r4, 0x2ec
/* 800FBDA8 000F8BA8  38 AD 91 60 */	li r5, lbl_805D6240@sda21
/* 800FBDAC 000F8BAC  48 32 C7 0D */	bl __assert
.L_800FBDB0:
/* 800FBDB0 000F8BB0  80 7C 00 00 */	lwz r3, 0x0(r28)
/* 800FBDB4 000F8BB4  C3 FD 01 34 */	lfs f31, 0x134(r29)
/* 800FBDB8 000F8BB8  C0 5E 00 1C */	lfs f2, 0x1c(r30)
/* 800FBDBC 000F8BBC  C0 22 91 E0 */	lfs f1, lbl_805DF8E0@sda21(r0)
/* 800FBDC0 000F8BC0  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 800FBDC4 000F8BC4  EC 5F 10 28 */	fsubs f2, f31, f2
/* 800FBDC8 000F8BC8  EC 01 00 32 */	fmuls f0, f1, f0
/* 800FBDCC 000F8BCC  FC 20 12 10 */	fabs f1, f2
/* 800FBDD0 000F8BD0  FC 00 02 10 */	fabs f0, f0
/* 800FBDD4 000F8BD4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800FBDD8 000F8BD8  4C 40 13 82 */	cror eq, lt, eq
/* 800FBDDC 000F8BDC  40 82 00 E0 */	bne .L_800FBEBC
/* 800FBDE0 000F8BE0  28 1E 00 00 */	cmplwi r30, 0x0
/* 800FBDE4 000F8BE4  40 82 00 14 */	bne .L_800FBDF8
/* 800FBDE8 000F8BE8  38 6D 91 58 */	li r3, kar_srcfile_jobj_h_805d6238@sda21
/* 800FBDEC 000F8BEC  38 80 02 A4 */	li r4, 0x2a4
/* 800FBDF0 000F8BF0  38 AD 91 60 */	li r5, lbl_805D6240@sda21
/* 800FBDF4 000F8BF4  48 32 C6 C5 */	bl __assert
.L_800FBDF8:
/* 800FBDF8 000F8BF8  80 1E 00 14 */	lwz r0, 0x14(r30)
/* 800FBDFC 000F8BFC  54 00 03 9D */	rlwinm. r0, r0, 0, 14, 14
/* 800FBE00 000F8C00  41 82 00 18 */	beq .L_800FBE18
/* 800FBE04 000F8C04  3C 80 80 4A */	lis r4, kar_gryakurecoveryzone_assert_jobj_not_quaternion@ha
/* 800FBE08 000F8C08  38 6D 91 58 */	li r3, kar_srcfile_jobj_h_805d6238@sda21
/* 800FBE0C 000F8C0C  38 A4 61 48 */	addi r5, r4, kar_gryakurecoveryzone_assert_jobj_not_quaternion@l
/* 800FBE10 000F8C10  38 80 02 A5 */	li r4, 0x2a5
/* 800FBE14 000F8C14  48 32 C6 A5 */	bl __assert
.L_800FBE18:
/* 800FBE18 000F8C18  D3 FE 00 1C */	stfs f31, 0x1c(r30)
/* 800FBE1C 000F8C1C  80 1E 00 14 */	lwz r0, 0x14(r30)
/* 800FBE20 000F8C20  54 00 01 8D */	rlwinm. r0, r0, 0, 6, 6
/* 800FBE24 000F8C24  40 82 00 4C */	bne .L_800FBE70
/* 800FBE28 000F8C28  28 1E 00 00 */	cmplwi r30, 0x0
/* 800FBE2C 000F8C2C  41 82 00 44 */	beq .L_800FBE70
/* 800FBE30 000F8C30  40 82 00 14 */	bne .L_800FBE44
/* 800FBE34 000F8C34  38 6D 91 58 */	li r3, kar_srcfile_jobj_h_805d6238@sda21
/* 800FBE38 000F8C38  38 80 02 5D */	li r4, 0x25d
/* 800FBE3C 000F8C3C  38 AD 91 60 */	li r5, lbl_805D6240@sda21
/* 800FBE40 000F8C40  48 32 C6 79 */	bl __assert
.L_800FBE44:
/* 800FBE44 000F8C44  80 9E 00 14 */	lwz r4, 0x14(r30)
/* 800FBE48 000F8C48  38 60 00 00 */	li r3, 0x0
/* 800FBE4C 000F8C4C  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 800FBE50 000F8C50  40 82 00 10 */	bne .L_800FBE60
/* 800FBE54 000F8C54  54 80 06 73 */	rlwinm. r0, r4, 0, 25, 25
/* 800FBE58 000F8C58  41 82 00 08 */	beq .L_800FBE60
/* 800FBE5C 000F8C5C  38 60 00 01 */	li r3, 0x1
.L_800FBE60:
/* 800FBE60 000F8C60  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FBE64 000F8C64  40 82 00 0C */	bne .L_800FBE70
/* 800FBE68 000F8C68  7F C3 F3 78 */	mr r3, r30
/* 800FBE6C 000F8C6C  48 31 1A C1 */	bl HSD_JObjSetMtxDirtySub
.L_800FBE70:
/* 800FBE70 000F8C70  83 DF 00 2C */	lwz r30, 0x2c(r31)
/* 800FBE74 000F8C74  38 80 00 00 */	li r4, 0x0
/* 800FBE78 000F8C78  80 7E 00 08 */	lwz r3, 0x8(r30)
/* 800FBE7C 000F8C7C  83 E3 00 00 */	lwz r31, 0x0(r3)
/* 800FBE80 000F8C80  80 7F 00 00 */	lwz r3, 0x0(r31)
/* 800FBE84 000F8C84  80 03 00 18 */	lwz r0, 0x18(r3)
/* 800FBE88 000F8C88  90 1E 01 40 */	stw r0, 0x140(r30)
/* 800FBE8C 000F8C8C  80 7E 01 30 */	lwz r3, 0x130(r30)
/* 800FBE90 000F8C90  4B FD BC 41 */	bl kar_grcoll__near_800d7ad0
/* 800FBE94 000F8C94  C0 22 91 E4 */	lfs f1, lbl_805DF8E4@sda21(r0)
/* 800FBE98 000F8C98  7F C3 F3 78 */	mr r3, r30
/* 800FBE9C 000F8C9C  80 BF 00 0C */	lwz r5, 0xc(r31)
/* 800FBEA0 000F8CA0  38 80 00 00 */	li r4, 0x0
/* 800FBEA4 000F8CA4  FC 40 08 90 */	fmr f2, f1
/* 800FBEA8 000F8CA8  80 DF 00 08 */	lwz r6, 0x8(r31)
/* 800FBEAC 000F8CAC  FC 60 08 90 */	fmr f3, f1
/* 800FBEB0 000F8CB0  38 E0 00 00 */	li r7, 0x0
/* 800FBEB4 000F8CB4  4B FF 96 95 */	bl kar_gryaku_set_path_node_motion
/* 800FBEB8 000F8CB8  48 00 00 80 */	b .L_800FBF38
.L_800FBEBC:
/* 800FBEBC 000F8CBC  28 1E 00 00 */	cmplwi r30, 0x0
/* 800FBEC0 000F8CC0  C3 FD 01 38 */	lfs f31, 0x138(r29)
/* 800FBEC4 000F8CC4  40 82 00 14 */	bne .L_800FBED8
/* 800FBEC8 000F8CC8  38 6D 91 58 */	li r3, kar_srcfile_jobj_h_805d6238@sda21
/* 800FBECC 000F8CCC  38 80 04 12 */	li r4, 0x412
/* 800FBED0 000F8CD0  38 AD 91 60 */	li r5, lbl_805D6240@sda21
/* 800FBED4 000F8CD4  48 32 C5 E5 */	bl __assert
.L_800FBED8:
/* 800FBED8 000F8CD8  C0 1E 00 1C */	lfs f0, 0x1c(r30)
/* 800FBEDC 000F8CDC  EC 00 F8 2A */	fadds f0, f0, f31
/* 800FBEE0 000F8CE0  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 800FBEE4 000F8CE4  80 1E 00 14 */	lwz r0, 0x14(r30)
/* 800FBEE8 000F8CE8  54 00 01 8D */	rlwinm. r0, r0, 0, 6, 6
/* 800FBEEC 000F8CEC  40 82 00 4C */	bne .L_800FBF38
/* 800FBEF0 000F8CF0  28 1E 00 00 */	cmplwi r30, 0x0
/* 800FBEF4 000F8CF4  41 82 00 44 */	beq .L_800FBF38
/* 800FBEF8 000F8CF8  40 82 00 14 */	bne .L_800FBF0C
/* 800FBEFC 000F8CFC  38 6D 91 58 */	li r3, kar_srcfile_jobj_h_805d6238@sda21
/* 800FBF00 000F8D00  38 80 02 5D */	li r4, 0x25d
/* 800FBF04 000F8D04  38 AD 91 60 */	li r5, lbl_805D6240@sda21
/* 800FBF08 000F8D08  48 32 C5 B1 */	bl __assert
.L_800FBF0C:
/* 800FBF0C 000F8D0C  80 9E 00 14 */	lwz r4, 0x14(r30)
/* 800FBF10 000F8D10  38 60 00 00 */	li r3, 0x0
/* 800FBF14 000F8D14  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 800FBF18 000F8D18  40 82 00 10 */	bne .L_800FBF28
/* 800FBF1C 000F8D1C  54 80 06 73 */	rlwinm. r0, r4, 0, 25, 25
/* 800FBF20 000F8D20  41 82 00 08 */	beq .L_800FBF28
/* 800FBF24 000F8D24  38 60 00 01 */	li r3, 0x1
.L_800FBF28:
/* 800FBF28 000F8D28  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FBF2C 000F8D2C  40 82 00 0C */	bne .L_800FBF38
/* 800FBF30 000F8D30  7F C3 F3 78 */	mr r3, r30
/* 800FBF34 000F8D34  48 31 19 F9 */	bl HSD_JObjSetMtxDirtySub
.L_800FBF38:
/* 800FBF38 000F8D38  E3 E1 00 28 */	psq_l f31, 0x28(r1), 0, qr0
/* 800FBF3C 000F8D3C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800FBF40 000F8D40  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 800FBF44 000F8D44  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800FBF48 000F8D48  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800FBF4C 000F8D4C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800FBF50 000F8D50  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800FBF54 000F8D54  7C 08 03 A6 */	mtlr r0
/* 800FBF58 000F8D58  38 21 00 30 */	addi r1, r1, 0x30
/* 800FBF5C 000F8D5C  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_update_kind41_return_angle

# .text:0x12C4 | 0x800FBF60 | size: 0x38
.fn kar_gryakurecoveryzone_create_stage_linked_kind42_ground_group_yaku, global
/* 800FBF60 000F8D60  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FBF64 000F8D64  7C 08 02 A6 */	mflr r0
/* 800FBF68 000F8D68  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FBF6C 000F8D6C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FBF70 000F8D70  7C 7F 1B 78 */	mr r31, r3
/* 800FBF74 000F8D74  38 60 00 2A */	li r3, 0x2a
/* 800FBF78 000F8D78  4B FF 84 F5 */	bl kar_gryaku_create_yaku_from_main_kind
/* 800FBF7C 000F8D7C  7F E4 FB 78 */	mr r4, r31
/* 800FBF80 000F8D80  48 00 00 19 */	bl kar_gryakurecoveryzone_init_stage_linked_kind42_ground_group_yaku
/* 800FBF84 000F8D84  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FBF88 000F8D88  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FBF8C 000F8D8C  7C 08 03 A6 */	mtlr r0
/* 800FBF90 000F8D90  38 21 00 10 */	addi r1, r1, 0x10
/* 800FBF94 000F8D94  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_create_stage_linked_kind42_ground_group_yaku

# .text:0x12FC | 0x800FBF98 | size: 0xE0
.fn kar_gryakurecoveryzone_init_stage_linked_kind42_ground_group_yaku, global
/* 800FBF98 000F8D98  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800FBF9C 000F8D9C  7C 08 02 A6 */	mflr r0
/* 800FBFA0 000F8DA0  90 01 00 24 */	stw r0, 0x24(r1)
/* 800FBFA4 000F8DA4  39 61 00 20 */	addi r11, r1, 0x20
/* 800FBFA8 000F8DA8  48 2B 1B AD */	bl _savegpr_27
/* 800FBFAC 000F8DAC  7C 7B 1B 78 */	mr r27, r3
/* 800FBFB0 000F8DB0  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 800FBFB4 000F8DB4  80 7E 00 08 */	lwz r3, 0x8(r30)
/* 800FBFB8 000F8DB8  83 A3 00 00 */	lwz r29, 0x0(r3)
/* 800FBFBC 000F8DBC  80 1D 00 10 */	lwz r0, 0x10(r29)
/* 800FBFC0 000F8DC0  54 03 10 3A */	slwi r3, r0, 2
/* 800FBFC4 000F8DC4  48 32 0F 21 */	bl HSD_Alloc
/* 800FBFC8 000F8DC8  90 7E 01 30 */	stw r3, 0x130(r30)
/* 800FBFCC 000F8DCC  3B 80 00 00 */	li r28, 0x0
/* 800FBFD0 000F8DD0  3B E0 00 00 */	li r31, 0x0
/* 800FBFD4 000F8DD4  48 00 00 60 */	b .L_800FC034
.L_800FBFD8:
/* 800FBFD8 000F8DD8  80 9D 00 0C */	lwz r4, 0xc(r29)
/* 800FBFDC 000F8DDC  38 A0 00 00 */	li r5, 0x0
/* 800FBFE0 000F8DE0  80 6D 12 54 */	lwz r3, lbl_805DE334@sda21(r0)
/* 800FBFE4 000F8DE4  7C 04 F8 2E */	lwzx r0, r4, r31
/* 800FBFE8 000F8DE8  80 83 00 20 */	lwz r4, 0x20(r3)
/* 800FBFEC 000F8DEC  48 00 00 18 */	b .L_800FC004
.L_800FBFF0:
/* 800FBFF0 000F8DF0  7C 00 28 00 */	cmpw r0, r5
/* 800FBFF4 000F8DF4  40 82 00 08 */	bne .L_800FBFFC
/* 800FBFF8 000F8DF8  48 00 00 2C */	b .L_800FC024
.L_800FBFFC:
/* 800FBFFC 000F8DFC  80 84 00 08 */	lwz r4, 0x8(r4)
/* 800FC000 000F8E00  38 A5 00 01 */	addi r5, r5, 0x1
.L_800FC004:
/* 800FC004 000F8E04  28 04 00 00 */	cmplwi r4, 0x0
/* 800FC008 000F8E08  40 82 FF E8 */	bne .L_800FBFF0
/* 800FC00C 000F8E0C  3C 60 80 4A */	lis r3, kar_src_ground_h_804a6170@ha
/* 800FC010 000F8E10  38 80 09 6C */	li r4, 0x96c
/* 800FC014 000F8E14  38 63 61 70 */	addi r3, r3, kar_src_ground_h_804a6170@l
/* 800FC018 000F8E18  38 AD 91 68 */	li r5, lbl_805D6248@sda21
/* 800FC01C 000F8E1C  48 32 C4 9D */	bl __assert
/* 800FC020 000F8E20  38 80 00 00 */	li r4, 0x0
.L_800FC024:
/* 800FC024 000F8E24  80 7E 01 30 */	lwz r3, 0x130(r30)
/* 800FC028 000F8E28  3B 9C 00 01 */	addi r28, r28, 0x1
/* 800FC02C 000F8E2C  7C 83 F9 2E */	stwx r4, r3, r31
/* 800FC030 000F8E30  3B FF 00 04 */	addi r31, r31, 0x4
.L_800FC034:
/* 800FC034 000F8E34  80 1D 00 10 */	lwz r0, 0x10(r29)
/* 800FC038 000F8E38  7C 1C 00 00 */	cmpw r28, r0
/* 800FC03C 000F8E3C  41 80 FF 9C */	blt .L_800FBFD8
/* 800FC040 000F8E40  38 80 00 00 */	li r4, 0x0
/* 800FC044 000F8E44  7F 63 DB 78 */	mr r3, r27
/* 800FC048 000F8E48  90 9E 01 34 */	stw r4, 0x134(r30)
/* 800FC04C 000F8E4C  90 9E 01 38 */	stw r4, 0x138(r30)
/* 800FC050 000F8E50  88 1E 01 3C */	lbz r0, 0x13c(r30)
/* 800FC054 000F8E54  50 80 3E 30 */	rlwimi r0, r4, 7, 24, 24
/* 800FC058 000F8E58  98 1E 01 3C */	stb r0, 0x13c(r30)
/* 800FC05C 000F8E5C  48 00 00 45 */	bl kar_gryakurecoveryzone_start_kind42_ground_group_idle_motion
/* 800FC060 000F8E60  39 61 00 20 */	addi r11, r1, 0x20
/* 800FC064 000F8E64  48 2B 1B 3D */	bl _restgpr_27
/* 800FC068 000F8E68  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FC06C 000F8E6C  7C 08 03 A6 */	mtlr r0
/* 800FC070 000F8E70  38 21 00 20 */	addi r1, r1, 0x20
/* 800FC074 000F8E74  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_init_stage_linked_kind42_ground_group_yaku

# .text:0x13DC | 0x800FC078 | size: 0x28
.fn kar_gryakurecoveryzone_destroy_kind42_ground_group_yaku, global
/* 800FC078 000F8E78  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FC07C 000F8E7C  7C 08 02 A6 */	mflr r0
/* 800FC080 000F8E80  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FC084 000F8E84  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FC088 000F8E88  80 63 01 30 */	lwz r3, 0x130(r3)
/* 800FC08C 000F8E8C  48 32 0E 29 */	bl HSD_Free
/* 800FC090 000F8E90  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FC094 000F8E94  7C 08 03 A6 */	mtlr r0
/* 800FC098 000F8E98  38 21 00 10 */	addi r1, r1, 0x10
/* 800FC09C 000F8E9C  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_destroy_kind42_ground_group_yaku

# .text:0x1404 | 0x800FC0A0 | size: 0x50
.fn kar_gryakurecoveryzone_start_kind42_ground_group_idle_motion, global
/* 800FC0A0 000F8EA0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FC0A4 000F8EA4  7C 08 02 A6 */	mflr r0
/* 800FC0A8 000F8EA8  C0 22 91 E4 */	lfs f1, lbl_805DF8E4@sda21(r0)
/* 800FC0AC 000F8EAC  38 80 00 00 */	li r4, 0x0
/* 800FC0B0 000F8EB0  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FC0B4 000F8EB4  38 A0 FF FF */	li r5, -0x1
/* 800FC0B8 000F8EB8  FC 40 08 90 */	fmr f2, f1
/* 800FC0BC 000F8EBC  38 C0 FF FF */	li r6, -0x1
/* 800FC0C0 000F8EC0  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FC0C4 000F8EC4  FC 60 08 90 */	fmr f3, f1
/* 800FC0C8 000F8EC8  80 E3 00 08 */	lwz r7, 0x8(r3)
/* 800FC0CC 000F8ECC  81 07 00 00 */	lwz r8, 0x0(r7)
/* 800FC0D0 000F8ED0  38 E0 00 00 */	li r7, 0x0
/* 800FC0D4 000F8ED4  80 08 00 00 */	lwz r0, 0x0(r8)
/* 800FC0D8 000F8ED8  90 03 01 34 */	stw r0, 0x134(r3)
/* 800FC0DC 000F8EDC  4B FF 94 6D */	bl kar_gryaku_set_path_node_motion
/* 800FC0E0 000F8EE0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FC0E4 000F8EE4  7C 08 03 A6 */	mtlr r0
/* 800FC0E8 000F8EE8  38 21 00 10 */	addi r1, r1, 0x10
/* 800FC0EC 000F8EEC  4E 80 00 20 */	blr
.endfn kar_gryakurecoveryzone_start_kind42_ground_group_idle_motion
