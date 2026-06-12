.include "macros.inc"
.file "gryakubreakcoral.c"

# 0x80103EB8..0x80104504 | size: 0x64C
.text
.balign 4

# .text:0x0 | 0x80103EB8 | size: 0x244
.fn kar_gryakubreakcoral_handle_kind24_to29_grcoll_hit, global
/* 80103EB8 00100CB8  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80103EBC 00100CBC  7C 08 02 A6 */	mflr r0
/* 80103EC0 00100CC0  90 01 00 34 */	stw r0, 0x34(r1)
/* 80103EC4 00100CC4  39 61 00 30 */	addi r11, r1, 0x30
/* 80103EC8 00100CC8  48 2A 9C 79 */	bl _savegpr_22
/* 80103ECC 00100CCC  7C 79 1B 78 */	mr r25, r3
/* 80103ED0 00100CD0  7C 9A 23 78 */	mr r26, r4
/* 80103ED4 00100CD4  82 C3 00 2C */	lwz r22, 0x2c(r3)
/* 80103ED8 00100CD8  7C B8 2B 78 */	mr r24, r5
/* 80103EDC 00100CDC  7C D7 33 78 */	mr r23, r6
/* 80103EE0 00100CE0  7C FB 3B 78 */	mr r27, r7
/* 80103EE4 00100CE4  80 D6 00 08 */	lwz r6, 0x8(r22)
/* 80103EE8 00100CE8  7F 43 D3 78 */	mr r3, r26
/* 80103EEC 00100CEC  80 B6 01 30 */	lwz r5, 0x130(r22)
/* 80103EF0 00100CF0  7F 04 C3 78 */	mr r4, r24
/* 80103EF4 00100CF4  83 A6 00 00 */	lwz r29, 0x0(r6)
/* 80103EF8 00100CF8  4B FD 3C 95 */	bl kar_grcoll__near_800d7b8c
/* 80103EFC 00100CFC  2C 03 00 00 */	cmpwi r3, 0x0
/* 80103F00 00100D00  41 82 00 0C */	beq .L_80103F0C
/* 80103F04 00100D04  38 60 00 00 */	li r3, 0x0
/* 80103F08 00100D08  48 00 01 DC */	b .L_801040E4
.L_80103F0C:
/* 80103F0C 00100D0C  88 16 01 50 */	lbz r0, 0x150(r22)
/* 80103F10 00100D10  54 00 CF FF */	extrwi. r0, r0, 1, 24
/* 80103F14 00100D14  40 82 00 24 */	bne .L_80103F38
/* 80103F18 00100D18  80 7D 00 14 */	lwz r3, 0x14(r29)
/* 80103F1C 00100D1C  7F 44 D3 78 */	mr r4, r26
/* 80103F20 00100D20  7F 05 C3 78 */	mr r5, r24
/* 80103F24 00100D24  7E E6 BB 78 */	mr r6, r23
/* 80103F28 00100D28  7F 67 DB 78 */	mr r7, r27
/* 80103F2C 00100D2C  48 00 0D A9 */	bl kar_gryakubreakicicle_test_damage_falloff_threshold
/* 80103F30 00100D30  2C 03 00 00 */	cmpwi r3, 0x0
/* 80103F34 00100D34  41 82 01 54 */	beq .L_80104088
.L_80103F38:
/* 80103F38 00100D38  7F 43 D3 78 */	mr r3, r26
/* 80103F3C 00100D3C  48 00 1D 75 */	bl kar_gryakubreakcommon_resolve_break_credit_player
/* 80103F40 00100D40  83 D9 00 2C */	lwz r30, 0x2c(r25)
/* 80103F44 00100D44  7C 7C 1B 78 */	mr r28, r3
/* 80103F48 00100D48  82 CD 05 EC */	lwz r22, lbl_805DD6CC@sda21(r0)
/* 80103F4C 00100D4C  38 80 00 00 */	li r4, 0x0
/* 80103F50 00100D50  80 BE 00 08 */	lwz r5, 0x8(r30)
/* 80103F54 00100D54  80 7E 01 30 */	lwz r3, 0x130(r30)
/* 80103F58 00100D58  83 E5 00 00 */	lwz r31, 0x0(r5)
/* 80103F5C 00100D5C  4B FD 3B 75 */	bl kar_grcoll__near_800d7ad0
/* 80103F60 00100D60  80 1F 00 20 */	lwz r0, 0x20(r31)
/* 80103F64 00100D64  2C 00 00 00 */	cmpwi r0, 0x0
/* 80103F68 00100D68  41 82 00 1C */	beq .L_80103F84
/* 80103F6C 00100D6C  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 80103F70 00100D70  38 80 00 10 */	li r4, 0x10
/* 80103F74 00100D74  80 76 01 04 */	lwz r3, 0x104(r22)
/* 80103F78 00100D78  54 00 18 38 */	slwi r0, r0, 3
/* 80103F7C 00100D7C  7C 63 00 2E */	lwzx r3, r3, r0
/* 80103F80 00100D80  48 30 7E 81 */	bl HSD_JObjSetFlagsAll
.L_80103F84:
/* 80103F84 00100D84  80 7E 00 EC */	lwz r3, 0xec(r30)
/* 80103F88 00100D88  48 08 8B 7D */	bl kar_collision_object_begin_disable
/* 80103F8C 00100D8C  80 9F 00 28 */	lwz r4, 0x28(r31)
/* 80103F90 00100D90  28 04 00 00 */	cmplwi r4, 0x0
/* 80103F94 00100D94  41 82 00 24 */	beq .L_80103FB8
/* 80103F98 00100D98  80 DE 00 08 */	lwz r6, 0x8(r30)
/* 80103F9C 00100D9C  7F C3 F3 78 */	mr r3, r30
/* 80103FA0 00100DA0  38 BA 00 14 */	addi r5, r26, 0x14
/* 80103FA4 00100DA4  80 C6 00 04 */	lwz r6, 0x4(r6)
/* 80103FA8 00100DA8  7C 06 00 D0 */	neg r0, r6
/* 80103FAC 00100DAC  7C 00 33 78 */	or r0, r0, r6
/* 80103FB0 00100DB0  54 06 0F FE */	srwi r6, r0, 31
/* 80103FB4 00100DB4  48 00 0D FD */	bl kar_gryakubreakcommon_spawn_break_parts_by_mode
.L_80103FB8:
/* 80103FB8 00100DB8  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 80103FBC 00100DBC  2C 00 00 03 */	cmpwi r0, 0x3
/* 80103FC0 00100DC0  40 81 00 1C */	ble .L_80103FDC
/* 80103FC4 00100DC4  3C 60 80 4A */	lis r3, kar_src_gryakubreakcoral_c@ha
/* 80103FC8 00100DC8  3C A0 80 4A */	lis r5, kar_gryakubreakcoral_assert_remove_effect_count@ha
/* 80103FCC 00100DCC  38 63 6A 9C */	addi r3, r3, kar_src_gryakubreakcoral_c@l
/* 80103FD0 00100DD0  38 80 00 D7 */	li r4, 0xd7
/* 80103FD4 00100DD4  38 A5 6A B0 */	addi r5, r5, kar_gryakubreakcoral_assert_remove_effect_count@l
/* 80103FD8 00100DD8  48 32 44 E1 */	bl __assert
.L_80103FDC:
/* 80103FDC 00100DDC  3B 00 00 00 */	li r24, 0x0
/* 80103FE0 00100DE0  7F D6 F3 78 */	mr r22, r30
/* 80103FE4 00100DE4  7F 17 C3 78 */	mr r23, r24
/* 80103FE8 00100DE8  48 00 00 3C */	b .L_80104024
.L_80103FEC:
/* 80103FEC 00100DEC  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 80103FF0 00100DF0  38 FA 00 14 */	addi r7, r26, 0x14
/* 80103FF4 00100DF4  80 BF 00 08 */	lwz r5, 0x8(r31)
/* 80103FF8 00100DF8  7F 23 CB 78 */	mr r3, r25
/* 80103FFC 00100DFC  7F 66 DB 78 */	mr r6, r27
/* 80104000 00100E00  7C E8 3B 78 */	mr r8, r7
/* 80104004 00100E04  7C 80 BA 14 */	add r4, r0, r23
/* 80104008 00100E08  39 20 00 00 */	li r9, 0x0
/* 8010400C 00100E0C  4B FF 30 39 */	bl kar_gryakueffect_request_by_entry_mode
/* 80104010 00100E10  90 96 01 3C */	stw r4, 0x13c(r22)
/* 80104014 00100E14  3A F7 00 1C */	addi r23, r23, 0x1c
/* 80104018 00100E18  3B 18 00 01 */	addi r24, r24, 0x1
/* 8010401C 00100E1C  90 76 01 38 */	stw r3, 0x138(r22)
/* 80104020 00100E20  3A D6 00 08 */	addi r22, r22, 0x8
.L_80104024:
/* 80104024 00100E24  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 80104028 00100E28  7C 18 00 00 */	cmpw r24, r0
/* 8010402C 00100E2C  41 80 FF C0 */	blt .L_80103FEC
/* 80104030 00100E30  80 1E 01 1C */	lwz r0, 0x11c(r30)
/* 80104034 00100E34  2C 00 00 00 */	cmpwi r0, 0x0
/* 80104038 00100E38  40 81 00 10 */	ble .L_80104048
/* 8010403C 00100E3C  38 7E 01 18 */	addi r3, r30, 0x118
/* 80104040 00100E40  38 80 00 00 */	li r4, 0x0
/* 80104044 00100E44  4B FE 60 41 */	bl kar_graudio_play_fgm_entry_id
.L_80104048:
/* 80104048 00100E48  2C 1C 00 05 */	cmpwi r28, 0x5
/* 8010404C 00100E4C  41 82 00 10 */	beq .L_8010405C
/* 80104050 00100E50  7F 23 CB 78 */	mr r3, r25
/* 80104054 00100E54  7F 84 E3 78 */	mr r4, r28
/* 80104058 00100E58  48 00 1D 29 */	bl kar_gryakubreakcommon_award_clearchecker_break_credit
.L_8010405C:
/* 8010405C 00100E5C  C0 22 92 B0 */	lfs f1, lbl_805DF9B0@sda21(r0)
/* 80104060 00100E60  7F C3 F3 78 */	mr r3, r30
/* 80104064 00100E64  80 BF 00 10 */	lwz r5, 0x10(r31)
/* 80104068 00100E68  38 80 00 02 */	li r4, 0x2
/* 8010406C 00100E6C  FC 60 08 90 */	fmr f3, f1
/* 80104070 00100E70  80 DF 00 00 */	lwz r6, 0x0(r31)
/* 80104074 00100E74  C0 42 92 B4 */	lfs f2, lbl_805DF9B4@sda21(r0)
/* 80104078 00100E78  38 E0 00 00 */	li r7, 0x0
/* 8010407C 00100E7C  4B FF 14 CD */	bl kar_gryaku_set_path_node_motion
/* 80104080 00100E80  80 7D 00 24 */	lwz r3, 0x24(r29)
/* 80104084 00100E84  48 00 00 60 */	b .L_801040E4
.L_80104088:
/* 80104088 00100E88  80 1D 00 0C */	lwz r0, 0xc(r29)
/* 8010408C 00100E8C  2C 00 FF FF */	cmpwi r0, -0x1
/* 80104090 00100E90  41 82 00 50 */	beq .L_801040E0
/* 80104094 00100E94  83 19 00 2C */	lwz r24, 0x2c(r25)
/* 80104098 00100E98  38 80 00 01 */	li r4, 0x1
/* 8010409C 00100E9C  C0 22 92 B0 */	lfs f1, lbl_805DF9B0@sda21(r0)
/* 801040A0 00100EA0  38 E0 00 00 */	li r7, 0x0
/* 801040A4 00100EA4  80 B8 00 08 */	lwz r5, 0x8(r24)
/* 801040A8 00100EA8  7F 03 C3 78 */	mr r3, r24
/* 801040AC 00100EAC  FC 60 08 90 */	fmr f3, f1
/* 801040B0 00100EB0  C0 42 92 B4 */	lfs f2, lbl_805DF9B4@sda21(r0)
/* 801040B4 00100EB4  80 C5 00 00 */	lwz r6, 0x0(r5)
/* 801040B8 00100EB8  80 A6 00 0C */	lwz r5, 0xc(r6)
/* 801040BC 00100EBC  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 801040C0 00100EC0  4B FF 14 89 */	bl kar_gryaku_set_path_node_motion
/* 801040C4 00100EC4  3C 80 80 10 */	lis r4, kar_gryakubreakcoral_trigger_break_effects_mode2@ha
/* 801040C8 00100EC8  38 60 00 01 */	li r3, 0x1
/* 801040CC 00100ECC  38 04 40 FC */	addi r0, r4, kar_gryakubreakcoral_trigger_break_effects_mode2@l
/* 801040D0 00100ED0  90 18 01 00 */	stw r0, 0x100(r24)
/* 801040D4 00100ED4  88 18 01 50 */	lbz r0, 0x150(r24)
/* 801040D8 00100ED8  50 60 3E 30 */	rlwimi r0, r3, 7, 24, 24
/* 801040DC 00100EDC  98 18 01 50 */	stb r0, 0x150(r24)
.L_801040E0:
/* 801040E0 00100EE0  38 60 00 00 */	li r3, 0x0
.L_801040E4:
/* 801040E4 00100EE4  39 61 00 30 */	addi r11, r1, 0x30
/* 801040E8 00100EE8  48 2A 9A A5 */	bl _restgpr_22
/* 801040EC 00100EEC  80 01 00 34 */	lwz r0, 0x34(r1)
/* 801040F0 00100EF0  7C 08 03 A6 */	mtlr r0
/* 801040F4 00100EF4  38 21 00 30 */	addi r1, r1, 0x30
/* 801040F8 00100EF8  4E 80 00 20 */	blr
.endfn kar_gryakubreakcoral_handle_kind24_to29_grcoll_hit

# .text:0x244 | 0x801040FC | size: 0x1C8
.fn kar_gryakubreakcoral_trigger_break_effects_mode2, global
/* 801040FC 00100EFC  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 80104100 00100F00  7C 08 02 A6 */	mflr r0
/* 80104104 00100F04  90 01 00 44 */	stw r0, 0x44(r1)
/* 80104108 00100F08  39 61 00 40 */	addi r11, r1, 0x40
/* 8010410C 00100F0C  48 2A 9A 41 */	bl _savegpr_25
/* 80104110 00100F10  80 04 00 38 */	lwz r0, 0x38(r4)
/* 80104114 00100F14  7C 7C 1B 78 */	mr r28, r3
/* 80104118 00100F18  80 A3 00 2C */	lwz r5, 0x2c(r3)
/* 8010411C 00100F1C  2C 00 00 05 */	cmpwi r0, 0x5
/* 80104120 00100F20  41 82 01 8C */	beq .L_801042AC
/* 80104124 00100F24  40 80 00 10 */	bge .L_80104134
/* 80104128 00100F28  2C 00 00 00 */	cmpwi r0, 0x0
/* 8010412C 00100F2C  40 80 00 10 */	bge .L_8010413C
/* 80104130 00100F30  48 00 01 7C */	b .L_801042AC
.L_80104134:
/* 80104134 00100F34  2C 00 00 08 */	cmpwi r0, 0x8
/* 80104138 00100F38  40 80 01 74 */	bge .L_801042AC
.L_8010413C:
/* 8010413C 00100F3C  80 64 00 2C */	lwz r3, 0x2c(r4)
/* 80104140 00100F40  80 04 00 30 */	lwz r0, 0x30(r4)
/* 80104144 00100F44  83 2D 05 EC */	lwz r25, lbl_805DD6CC@sda21(r0)
/* 80104148 00100F48  90 61 00 14 */	stw r3, 0x14(r1)
/* 8010414C 00100F4C  90 01 00 18 */	stw r0, 0x18(r1)
/* 80104150 00100F50  80 04 00 34 */	lwz r0, 0x34(r4)
/* 80104154 00100F54  90 01 00 1C */	stw r0, 0x1c(r1)
/* 80104158 00100F58  80 64 00 14 */	lwz r3, 0x14(r4)
/* 8010415C 00100F5C  80 04 00 18 */	lwz r0, 0x18(r4)
/* 80104160 00100F60  90 61 00 08 */	stw r3, 0x8(r1)
/* 80104164 00100F64  90 01 00 0C */	stw r0, 0xc(r1)
/* 80104168 00100F68  80 04 00 1C */	lwz r0, 0x1c(r4)
/* 8010416C 00100F6C  38 80 00 00 */	li r4, 0x0
/* 80104170 00100F70  90 01 00 10 */	stw r0, 0x10(r1)
/* 80104174 00100F74  83 DC 00 2C */	lwz r30, 0x2c(r28)
/* 80104178 00100F78  83 A5 00 B0 */	lwz r29, 0xb0(r5)
/* 8010417C 00100F7C  80 BE 00 08 */	lwz r5, 0x8(r30)
/* 80104180 00100F80  80 7E 01 30 */	lwz r3, 0x130(r30)
/* 80104184 00100F84  83 E5 00 00 */	lwz r31, 0x0(r5)
/* 80104188 00100F88  4B FD 39 49 */	bl kar_grcoll__near_800d7ad0
/* 8010418C 00100F8C  80 1F 00 20 */	lwz r0, 0x20(r31)
/* 80104190 00100F90  2C 00 00 00 */	cmpwi r0, 0x0
/* 80104194 00100F94  41 82 00 1C */	beq .L_801041B0
/* 80104198 00100F98  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 8010419C 00100F9C  38 80 00 10 */	li r4, 0x10
/* 801041A0 00100FA0  80 79 01 04 */	lwz r3, 0x104(r25)
/* 801041A4 00100FA4  54 00 18 38 */	slwi r0, r0, 3
/* 801041A8 00100FA8  7C 63 00 2E */	lwzx r3, r3, r0
/* 801041AC 00100FAC  48 30 7C 55 */	bl HSD_JObjSetFlagsAll
.L_801041B0:
/* 801041B0 00100FB0  80 7E 00 EC */	lwz r3, 0xec(r30)
/* 801041B4 00100FB4  48 08 89 51 */	bl kar_collision_object_begin_disable
/* 801041B8 00100FB8  80 9F 00 28 */	lwz r4, 0x28(r31)
/* 801041BC 00100FBC  28 04 00 00 */	cmplwi r4, 0x0
/* 801041C0 00100FC0  41 82 00 24 */	beq .L_801041E4
/* 801041C4 00100FC4  80 DE 00 08 */	lwz r6, 0x8(r30)
/* 801041C8 00100FC8  7F C3 F3 78 */	mr r3, r30
/* 801041CC 00100FCC  38 A1 00 08 */	addi r5, r1, 0x8
/* 801041D0 00100FD0  80 C6 00 04 */	lwz r6, 0x4(r6)
/* 801041D4 00100FD4  7C 06 00 D0 */	neg r0, r6
/* 801041D8 00100FD8  7C 00 33 78 */	or r0, r0, r6
/* 801041DC 00100FDC  54 06 0F FE */	srwi r6, r0, 31
/* 801041E0 00100FE0  48 00 0B D1 */	bl kar_gryakubreakcommon_spawn_break_parts_by_mode
.L_801041E4:
/* 801041E4 00100FE4  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 801041E8 00100FE8  2C 00 00 03 */	cmpwi r0, 0x3
/* 801041EC 00100FEC  40 81 00 1C */	ble .L_80104208
/* 801041F0 00100FF0  3C 60 80 4A */	lis r3, kar_src_gryakubreakcoral_c@ha
/* 801041F4 00100FF4  3C A0 80 4A */	lis r5, kar_gryakubreakcoral_assert_remove_effect_count@ha
/* 801041F8 00100FF8  38 63 6A 9C */	addi r3, r3, kar_src_gryakubreakcoral_c@l
/* 801041FC 00100FFC  38 80 00 D7 */	li r4, 0xd7
/* 80104200 00101000  38 A5 6A B0 */	addi r5, r5, kar_gryakubreakcoral_assert_remove_effect_count@l
/* 80104204 00101004  48 32 42 B5 */	bl __assert
.L_80104208:
/* 80104208 00101008  3B 60 00 00 */	li r27, 0x0
/* 8010420C 0010100C  7F D9 F3 78 */	mr r25, r30
/* 80104210 00101010  7F 7A DB 78 */	mr r26, r27
/* 80104214 00101014  48 00 00 3C */	b .L_80104250
.L_80104218:
/* 80104218 00101018  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 8010421C 0010101C  38 E1 00 08 */	addi r7, r1, 0x8
/* 80104220 00101020  80 BF 00 08 */	lwz r5, 0x8(r31)
/* 80104224 00101024  7F 83 E3 78 */	mr r3, r28
/* 80104228 00101028  7C E8 3B 78 */	mr r8, r7
/* 8010422C 0010102C  7C 80 D2 14 */	add r4, r0, r26
/* 80104230 00101030  38 C1 00 14 */	addi r6, r1, 0x14
/* 80104234 00101034  39 20 00 00 */	li r9, 0x0
/* 80104238 00101038  4B FF 2E 0D */	bl kar_gryakueffect_request_by_entry_mode
/* 8010423C 0010103C  90 99 01 3C */	stw r4, 0x13c(r25)
/* 80104240 00101040  3B 5A 00 1C */	addi r26, r26, 0x1c
/* 80104244 00101044  3B 7B 00 01 */	addi r27, r27, 0x1
/* 80104248 00101048  90 79 01 38 */	stw r3, 0x138(r25)
/* 8010424C 0010104C  3B 39 00 08 */	addi r25, r25, 0x8
.L_80104250:
/* 80104250 00101050  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 80104254 00101054  7C 1B 00 00 */	cmpw r27, r0
/* 80104258 00101058  41 80 FF C0 */	blt .L_80104218
/* 8010425C 0010105C  80 1E 01 1C */	lwz r0, 0x11c(r30)
/* 80104260 00101060  2C 00 00 00 */	cmpwi r0, 0x0
/* 80104264 00101064  40 81 00 10 */	ble .L_80104274
/* 80104268 00101068  38 7E 01 18 */	addi r3, r30, 0x118
/* 8010426C 0010106C  38 80 00 00 */	li r4, 0x0
/* 80104270 00101070  4B FE 5E 15 */	bl kar_graudio_play_fgm_entry_id
.L_80104274:
/* 80104274 00101074  2C 1D 00 05 */	cmpwi r29, 0x5
/* 80104278 00101078  41 82 00 10 */	beq .L_80104288
/* 8010427C 0010107C  7F 83 E3 78 */	mr r3, r28
/* 80104280 00101080  7F A4 EB 78 */	mr r4, r29
/* 80104284 00101084  48 00 1A FD */	bl kar_gryakubreakcommon_award_clearchecker_break_credit
.L_80104288:
/* 80104288 00101088  C0 22 92 B0 */	lfs f1, lbl_805DF9B0@sda21(r0)
/* 8010428C 0010108C  7F C3 F3 78 */	mr r3, r30
/* 80104290 00101090  80 BF 00 10 */	lwz r5, 0x10(r31)
/* 80104294 00101094  38 80 00 02 */	li r4, 0x2
/* 80104298 00101098  FC 60 08 90 */	fmr f3, f1
/* 8010429C 0010109C  80 DF 00 00 */	lwz r6, 0x0(r31)
/* 801042A0 001010A0  C0 42 92 B4 */	lfs f2, lbl_805DF9B4@sda21(r0)
/* 801042A4 001010A4  38 E0 00 00 */	li r7, 0x0
/* 801042A8 001010A8  4B FF 12 A1 */	bl kar_gryaku_set_path_node_motion
.L_801042AC:
/* 801042AC 001010AC  39 61 00 40 */	addi r11, r1, 0x40
/* 801042B0 001010B0  48 2A 98 E9 */	bl _restgpr_25
/* 801042B4 001010B4  80 01 00 44 */	lwz r0, 0x44(r1)
/* 801042B8 001010B8  7C 08 03 A6 */	mtlr r0
/* 801042BC 001010BC  38 21 00 40 */	addi r1, r1, 0x40
/* 801042C0 001010C0  4E 80 00 20 */	blr
.endfn kar_gryakubreakcoral_trigger_break_effects_mode2

# .text:0x40C | 0x801042C4 | size: 0x104
.fn kar_gryakubreakcoral_create_stage_linked_kind28_breakcoral, global
/* 801042C4 001010C4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801042C8 001010C8  7C 08 02 A6 */	mflr r0
/* 801042CC 001010CC  90 01 00 24 */	stw r0, 0x24(r1)
/* 801042D0 001010D0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801042D4 001010D4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801042D8 001010D8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 801042DC 001010DC  7C 7D 1B 78 */	mr r29, r3
/* 801042E0 001010E0  38 60 00 1C */	li r3, 0x1c
/* 801042E4 001010E4  4B FF 01 89 */	bl kar_gryaku_create_yaku_from_main_kind
/* 801042E8 001010E8  80 9D 00 2C */	lwz r4, 0x2c(r29)
/* 801042EC 001010EC  7C 7D 1B 78 */	mr r29, r3
/* 801042F0 001010F0  83 DD 00 2C */	lwz r30, 0x2c(r29)
/* 801042F4 001010F4  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 801042F8 001010F8  80 BE 00 08 */	lwz r5, 0x8(r30)
/* 801042FC 001010FC  80 84 01 04 */	lwz r4, 0x104(r4)
/* 80104300 00101100  38 63 00 54 */	addi r3, r3, 0x54
/* 80104304 00101104  83 E5 00 00 */	lwz r31, 0x0(r5)
/* 80104308 00101108  80 1F 00 04 */	lwz r0, 0x4(r31)
/* 8010430C 0010110C  54 00 18 38 */	slwi r0, r0, 3
/* 80104310 00101110  7C 84 00 2E */	lwzx r4, r4, r0
/* 80104314 00101114  4B FD 36 41 */	bl kar_grcoll__800d7954
/* 80104318 00101118  90 7E 01 30 */	stw r3, 0x130(r30)
/* 8010431C 0010111C  38 60 00 00 */	li r3, 0x0
/* 80104320 00101120  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 80104324 00101124  80 9E 01 30 */	lwz r4, 0x130(r30)
/* 80104328 00101128  90 04 00 90 */	stw r0, 0x90(r4)
/* 8010432C 0010112C  88 1E 01 50 */	lbz r0, 0x150(r30)
/* 80104330 00101130  50 60 3E 30 */	rlwimi r0, r3, 7, 24, 24
/* 80104334 00101134  98 1E 01 50 */	stb r0, 0x150(r30)
/* 80104338 00101138  90 7E 01 3C */	stw r3, 0x13c(r30)
/* 8010433C 0010113C  90 7E 01 38 */	stw r3, 0x138(r30)
/* 80104340 00101140  90 7E 01 44 */	stw r3, 0x144(r30)
/* 80104344 00101144  90 7E 01 40 */	stw r3, 0x140(r30)
/* 80104348 00101148  90 7E 01 4C */	stw r3, 0x14c(r30)
/* 8010434C 0010114C  90 7E 01 48 */	stw r3, 0x148(r30)
/* 80104350 00101150  80 7E 00 08 */	lwz r3, 0x8(r30)
/* 80104354 00101154  80 03 00 14 */	lwz r0, 0x14(r3)
/* 80104358 00101158  28 00 00 00 */	cmplwi r0, 0x0
/* 8010435C 0010115C  41 82 00 14 */	beq .L_80104370
/* 80104360 00101160  80 9F 00 00 */	lwz r4, 0x0(r31)
/* 80104364 00101164  7F A3 EB 78 */	mr r3, r29
/* 80104368 00101168  38 A0 00 00 */	li r5, 0x0
/* 8010436C 0010116C  4B FF 35 05 */	bl kar_gryakuaudio_configure_fgm_track_from_joint
.L_80104370:
/* 80104370 00101170  83 DD 00 2C */	lwz r30, 0x2c(r29)
/* 80104374 00101174  38 80 00 00 */	li r4, 0x0
/* 80104378 00101178  C0 22 92 B0 */	lfs f1, lbl_805DF9B0@sda21(r0)
/* 8010437C 0010117C  38 A0 FF FF */	li r5, -0x1
/* 80104380 00101180  80 DE 00 08 */	lwz r6, 0x8(r30)
/* 80104384 00101184  7F C3 F3 78 */	mr r3, r30
/* 80104388 00101188  FC 40 08 90 */	fmr f2, f1
/* 8010438C 0010118C  38 E0 00 00 */	li r7, 0x0
/* 80104390 00101190  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 80104394 00101194  FC 60 08 90 */	fmr f3, f1
/* 80104398 00101198  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 8010439C 0010119C  4B FF 11 AD */	bl kar_gryaku_set_path_node_motion
/* 801043A0 001011A0  3C 60 80 10 */	lis r3, kar_gryakubreakcoral_trigger_break_effects_mode2@ha
/* 801043A4 001011A4  38 03 40 FC */	addi r0, r3, kar_gryakubreakcoral_trigger_break_effects_mode2@l
/* 801043A8 001011A8  90 1E 01 00 */	stw r0, 0x100(r30)
/* 801043AC 001011AC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801043B0 001011B0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801043B4 001011B4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 801043B8 001011B8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801043BC 001011BC  7C 08 03 A6 */	mtlr r0
/* 801043C0 001011C0  38 21 00 20 */	addi r1, r1, 0x20
/* 801043C4 001011C4  4E 80 00 20 */	blr
.endfn kar_gryakubreakcoral_create_stage_linked_kind28_breakcoral

# .text:0x510 | 0x801043C8 | size: 0x104
.fn kar_gryakubreakcoral_create_stage_linked_kind29_breakcoral, global
/* 801043C8 001011C8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801043CC 001011CC  7C 08 02 A6 */	mflr r0
/* 801043D0 001011D0  90 01 00 24 */	stw r0, 0x24(r1)
/* 801043D4 001011D4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801043D8 001011D8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801043DC 001011DC  93 A1 00 14 */	stw r29, 0x14(r1)
/* 801043E0 001011E0  7C 7D 1B 78 */	mr r29, r3
/* 801043E4 001011E4  38 60 00 1D */	li r3, 0x1d
/* 801043E8 001011E8  4B FF 00 85 */	bl kar_gryaku_create_yaku_from_main_kind
/* 801043EC 001011EC  80 9D 00 2C */	lwz r4, 0x2c(r29)
/* 801043F0 001011F0  7C 7D 1B 78 */	mr r29, r3
/* 801043F4 001011F4  83 DD 00 2C */	lwz r30, 0x2c(r29)
/* 801043F8 001011F8  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 801043FC 001011FC  80 BE 00 08 */	lwz r5, 0x8(r30)
/* 80104400 00101200  80 84 01 04 */	lwz r4, 0x104(r4)
/* 80104404 00101204  38 63 00 54 */	addi r3, r3, 0x54
/* 80104408 00101208  83 E5 00 00 */	lwz r31, 0x0(r5)
/* 8010440C 0010120C  80 1F 00 04 */	lwz r0, 0x4(r31)
/* 80104410 00101210  54 00 18 38 */	slwi r0, r0, 3
/* 80104414 00101214  7C 84 00 2E */	lwzx r4, r4, r0
/* 80104418 00101218  4B FD 35 3D */	bl kar_grcoll__800d7954
/* 8010441C 0010121C  90 7E 01 30 */	stw r3, 0x130(r30)
/* 80104420 00101220  38 60 00 00 */	li r3, 0x0
/* 80104424 00101224  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 80104428 00101228  80 9E 01 30 */	lwz r4, 0x130(r30)
/* 8010442C 0010122C  90 04 00 90 */	stw r0, 0x90(r4)
/* 80104430 00101230  88 1E 01 50 */	lbz r0, 0x150(r30)
/* 80104434 00101234  50 60 3E 30 */	rlwimi r0, r3, 7, 24, 24
/* 80104438 00101238  98 1E 01 50 */	stb r0, 0x150(r30)
/* 8010443C 0010123C  90 7E 01 3C */	stw r3, 0x13c(r30)
/* 80104440 00101240  90 7E 01 38 */	stw r3, 0x138(r30)
/* 80104444 00101244  90 7E 01 44 */	stw r3, 0x144(r30)
/* 80104448 00101248  90 7E 01 40 */	stw r3, 0x140(r30)
/* 8010444C 0010124C  90 7E 01 4C */	stw r3, 0x14c(r30)
/* 80104450 00101250  90 7E 01 48 */	stw r3, 0x148(r30)
/* 80104454 00101254  80 7E 00 08 */	lwz r3, 0x8(r30)
/* 80104458 00101258  80 03 00 14 */	lwz r0, 0x14(r3)
/* 8010445C 0010125C  28 00 00 00 */	cmplwi r0, 0x0
/* 80104460 00101260  41 82 00 14 */	beq .L_80104474
/* 80104464 00101264  80 9F 00 00 */	lwz r4, 0x0(r31)
/* 80104468 00101268  7F A3 EB 78 */	mr r3, r29
/* 8010446C 0010126C  38 A0 00 00 */	li r5, 0x0
/* 80104470 00101270  4B FF 34 01 */	bl kar_gryakuaudio_configure_fgm_track_from_joint
.L_80104474:
/* 80104474 00101274  83 DD 00 2C */	lwz r30, 0x2c(r29)
/* 80104478 00101278  38 80 00 00 */	li r4, 0x0
/* 8010447C 0010127C  C0 22 92 B0 */	lfs f1, lbl_805DF9B0@sda21(r0)
/* 80104480 00101280  38 A0 FF FF */	li r5, -0x1
/* 80104484 00101284  80 DE 00 08 */	lwz r6, 0x8(r30)
/* 80104488 00101288  7F C3 F3 78 */	mr r3, r30
/* 8010448C 0010128C  FC 40 08 90 */	fmr f2, f1
/* 80104490 00101290  38 E0 00 00 */	li r7, 0x0
/* 80104494 00101294  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 80104498 00101298  FC 60 08 90 */	fmr f3, f1
/* 8010449C 0010129C  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 801044A0 001012A0  4B FF 10 A9 */	bl kar_gryaku_set_path_node_motion
/* 801044A4 001012A4  3C 60 80 10 */	lis r3, kar_gryakubreakcoral_trigger_break_effects_mode2@ha
/* 801044A8 001012A8  38 03 40 FC */	addi r0, r3, kar_gryakubreakcoral_trigger_break_effects_mode2@l
/* 801044AC 001012AC  90 1E 01 00 */	stw r0, 0x100(r30)
/* 801044B0 001012B0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801044B4 001012B4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801044B8 001012B8  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 801044BC 001012BC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801044C0 001012C0  7C 08 03 A6 */	mtlr r0
/* 801044C4 001012C4  38 21 00 20 */	addi r1, r1, 0x20
/* 801044C8 001012C8  4E 80 00 20 */	blr
.endfn kar_gryakubreakcoral_create_stage_linked_kind29_breakcoral

# .text:0x614 | 0x801044CC | size: 0x38
.fn kar_gryakubreakcoral_create_stage_linked_kind31_breakicicle, global
/* 801044CC 001012CC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801044D0 001012D0  7C 08 02 A6 */	mflr r0
/* 801044D4 001012D4  90 01 00 14 */	stw r0, 0x14(r1)
/* 801044D8 001012D8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801044DC 001012DC  7C 7F 1B 78 */	mr r31, r3
/* 801044E0 001012E0  38 60 00 1F */	li r3, 0x1f
/* 801044E4 001012E4  4B FE FF 89 */	bl kar_gryaku_create_yaku_from_main_kind
/* 801044E8 001012E8  7F E4 FB 78 */	mr r4, r31
/* 801044EC 001012EC  48 00 00 19 */	bl kar_gryakubreakicicle_init_kind31_breakicicle
/* 801044F0 001012F0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801044F4 001012F4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801044F8 001012F8  7C 08 03 A6 */	mtlr r0
/* 801044FC 001012FC  38 21 00 10 */	addi r1, r1, 0x10
/* 80104500 00101300  4E 80 00 20 */	blr
.endfn kar_gryakubreakcoral_create_stage_linked_kind31_breakicicle
