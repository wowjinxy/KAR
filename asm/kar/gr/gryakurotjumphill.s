.include "macros.inc"
.file "gryakurotjumphill.c"

# 0x800FC0F0..0x800FC740 | size: 0x650
.text
.balign 4

# .text:0x0 | 0x800FC0F0 | size: 0x1E0
.fn kar_gryakurotjumphill_update_target_trigger_cycle, global
/* 800FC0F0 000F8EF0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800FC0F4 000F8EF4  7C 08 02 A6 */	mflr r0
/* 800FC0F8 000F8EF8  90 01 00 24 */	stw r0, 0x24(r1)
/* 800FC0FC 000F8EFC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800FC100 000F8F00  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800FC104 000F8F04  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800FC108 000F8F08  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800FC10C 000F8F0C  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 800FC110 000F8F10  80 7F 01 34 */	lwz r3, 0x134(r31)
/* 800FC114 000F8F14  83 C4 00 00 */	lwz r30, 0x0(r4)
/* 800FC118 000F8F18  38 03 FF FF */	subi r0, r3, 0x1
/* 800FC11C 000F8F1C  90 1F 01 34 */	stw r0, 0x134(r31)
/* 800FC120 000F8F20  88 7F 01 3C */	lbz r3, 0x13c(r31)
/* 800FC124 000F8F24  54 60 CF FF */	extrwi. r0, r3, 1, 24
/* 800FC128 000F8F28  41 82 00 C0 */	beq .L_800FC1E8
/* 800FC12C 000F8F2C  48 00 00 AC */	b .L_800FC1D8
.L_800FC130:
/* 800FC130 000F8F30  80 1F 01 38 */	lwz r0, 0x138(r31)
/* 800FC134 000F8F34  38 60 00 00 */	li r3, 0x0
/* 800FC138 000F8F38  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 800FC13C 000F8F3C  54 00 18 38 */	slwi r0, r0, 3
/* 800FC140 000F8F40  7F A4 00 2E */	lwzx r29, r4, r0
/* 800FC144 000F8F44  2C 1D 00 00 */	cmpwi r29, 0x0
/* 800FC148 000F8F48  41 80 00 14 */	blt .L_800FC15C
/* 800FC14C 000F8F4C  80 1E 00 10 */	lwz r0, 0x10(r30)
/* 800FC150 000F8F50  7C 1D 00 00 */	cmpw r29, r0
/* 800FC154 000F8F54  40 80 00 08 */	bge .L_800FC15C
/* 800FC158 000F8F58  38 60 00 01 */	li r3, 0x1
.L_800FC15C:
/* 800FC15C 000F8F5C  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FC160 000F8F60  40 82 00 1C */	bne .L_800FC17C
/* 800FC164 000F8F64  3C 60 80 4A */	lis r3, kar_src_gryakurotjumphill_c@ha
/* 800FC168 000F8F68  3C A0 80 4A */	lis r5, kar_gryakurotjumphill_assert_target_ref_in_range@ha
/* 800FC16C 000F8F6C  38 63 61 7C */	addi r3, r3, kar_src_gryakurotjumphill_c@l
/* 800FC170 000F8F70  38 80 01 B5 */	li r4, 0x1b5
/* 800FC174 000F8F74  38 A5 61 90 */	addi r5, r5, kar_gryakurotjumphill_assert_target_ref_in_range@l
/* 800FC178 000F8F78  48 32 C3 41 */	bl __assert
.L_800FC17C:
/* 800FC17C 000F8F7C  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 800FC180 000F8F80  57 A0 10 3A */	slwi r0, r29, 2
/* 800FC184 000F8F84  38 80 00 01 */	li r4, 0x1
/* 800FC188 000F8F88  7C 63 00 2E */	lwzx r3, r3, r0
/* 800FC18C 000F8F8C  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FC190 000F8F90  88 03 01 44 */	lbz r0, 0x144(r3)
/* 800FC194 000F8F94  50 80 36 72 */	rlwimi r0, r4, 6, 25, 25
/* 800FC198 000F8F98  98 03 01 44 */	stb r0, 0x144(r3)
/* 800FC19C 000F8F9C  80 1F 01 38 */	lwz r0, 0x138(r31)
/* 800FC1A0 000F8FA0  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 800FC1A4 000F8FA4  54 03 18 38 */	slwi r3, r0, 3
/* 800FC1A8 000F8FA8  38 03 00 04 */	addi r0, r3, 0x4
/* 800FC1AC 000F8FAC  7C 04 00 2E */	lwzx r0, r4, r0
/* 800FC1B0 000F8FB0  90 1F 01 34 */	stw r0, 0x134(r31)
/* 800FC1B4 000F8FB4  80 7F 01 38 */	lwz r3, 0x138(r31)
/* 800FC1B8 000F8FB8  38 03 00 01 */	addi r0, r3, 0x1
/* 800FC1BC 000F8FBC  90 1F 01 38 */	stw r0, 0x138(r31)
/* 800FC1C0 000F8FC0  80 7F 01 38 */	lwz r3, 0x138(r31)
/* 800FC1C4 000F8FC4  80 1E 00 08 */	lwz r0, 0x8(r30)
/* 800FC1C8 000F8FC8  7C 03 00 00 */	cmpw r3, r0
/* 800FC1CC 000F8FCC  41 80 00 0C */	blt .L_800FC1D8
/* 800FC1D0 000F8FD0  38 00 00 00 */	li r0, 0x0
/* 800FC1D4 000F8FD4  90 1F 01 38 */	stw r0, 0x138(r31)
.L_800FC1D8:
/* 800FC1D8 000F8FD8  80 1F 01 34 */	lwz r0, 0x134(r31)
/* 800FC1DC 000F8FDC  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FC1E0 000F8FE0  40 81 FF 50 */	ble .L_800FC130
/* 800FC1E4 000F8FE4  48 00 00 D0 */	b .L_800FC2B4
.L_800FC1E8:
/* 800FC1E8 000F8FE8  80 1F 01 34 */	lwz r0, 0x134(r31)
/* 800FC1EC 000F8FEC  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FC1F0 000F8FF0  41 81 00 C4 */	bgt .L_800FC2B4
/* 800FC1F4 000F8FF4  38 00 00 01 */	li r0, 0x1
/* 800FC1F8 000F8FF8  50 03 3E 30 */	rlwimi r3, r0, 7, 24, 24
/* 800FC1FC 000F8FFC  98 7F 01 3C */	stb r3, 0x13c(r31)
.L_800FC200:
/* 800FC200 000F9000  80 1F 01 38 */	lwz r0, 0x138(r31)
/* 800FC204 000F9004  38 60 00 00 */	li r3, 0x0
/* 800FC208 000F9008  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 800FC20C 000F900C  54 00 18 38 */	slwi r0, r0, 3
/* 800FC210 000F9010  7F A4 00 2E */	lwzx r29, r4, r0
/* 800FC214 000F9014  2C 1D 00 00 */	cmpwi r29, 0x0
/* 800FC218 000F9018  41 80 00 14 */	blt .L_800FC22C
/* 800FC21C 000F901C  80 1E 00 10 */	lwz r0, 0x10(r30)
/* 800FC220 000F9020  7C 1D 00 00 */	cmpw r29, r0
/* 800FC224 000F9024  40 80 00 08 */	bge .L_800FC22C
/* 800FC228 000F9028  38 60 00 01 */	li r3, 0x1
.L_800FC22C:
/* 800FC22C 000F902C  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FC230 000F9030  40 82 00 1C */	bne .L_800FC24C
/* 800FC234 000F9034  3C 60 80 4A */	lis r3, kar_src_gryakurotjumphill_c@ha
/* 800FC238 000F9038  3C A0 80 4A */	lis r5, kar_gryakurotjumphill_assert_target_ref_in_range@ha
/* 800FC23C 000F903C  38 63 61 7C */	addi r3, r3, kar_src_gryakurotjumphill_c@l
/* 800FC240 000F9040  38 80 01 B5 */	li r4, 0x1b5
/* 800FC244 000F9044  38 A5 61 90 */	addi r5, r5, kar_gryakurotjumphill_assert_target_ref_in_range@l
/* 800FC248 000F9048  48 32 C2 71 */	bl __assert
.L_800FC24C:
/* 800FC24C 000F904C  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 800FC250 000F9050  57 A0 10 3A */	slwi r0, r29, 2
/* 800FC254 000F9054  38 80 00 01 */	li r4, 0x1
/* 800FC258 000F9058  7C 63 00 2E */	lwzx r3, r3, r0
/* 800FC25C 000F905C  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FC260 000F9060  88 03 01 44 */	lbz r0, 0x144(r3)
/* 800FC264 000F9064  50 80 36 72 */	rlwimi r0, r4, 6, 25, 25
/* 800FC268 000F9068  98 03 01 44 */	stb r0, 0x144(r3)
/* 800FC26C 000F906C  80 1F 01 38 */	lwz r0, 0x138(r31)
/* 800FC270 000F9070  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 800FC274 000F9074  54 03 18 38 */	slwi r3, r0, 3
/* 800FC278 000F9078  38 03 00 04 */	addi r0, r3, 0x4
/* 800FC27C 000F907C  7C 04 00 2E */	lwzx r0, r4, r0
/* 800FC280 000F9080  90 1F 01 34 */	stw r0, 0x134(r31)
/* 800FC284 000F9084  80 7F 01 38 */	lwz r3, 0x138(r31)
/* 800FC288 000F9088  38 03 00 01 */	addi r0, r3, 0x1
/* 800FC28C 000F908C  90 1F 01 38 */	stw r0, 0x138(r31)
/* 800FC290 000F9090  80 7F 01 38 */	lwz r3, 0x138(r31)
/* 800FC294 000F9094  80 1E 00 08 */	lwz r0, 0x8(r30)
/* 800FC298 000F9098  7C 03 00 00 */	cmpw r3, r0
/* 800FC29C 000F909C  41 80 00 0C */	blt .L_800FC2A8
/* 800FC2A0 000F90A0  38 00 00 00 */	li r0, 0x0
/* 800FC2A4 000F90A4  90 1F 01 38 */	stw r0, 0x138(r31)
.L_800FC2A8:
/* 800FC2A8 000F90A8  80 1F 01 34 */	lwz r0, 0x134(r31)
/* 800FC2AC 000F90AC  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FC2B0 000F90B0  40 81 FF 50 */	ble .L_800FC200
.L_800FC2B4:
/* 800FC2B4 000F90B4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FC2B8 000F90B8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800FC2BC 000F90BC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800FC2C0 000F90C0  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800FC2C4 000F90C4  7C 08 03 A6 */	mtlr r0
/* 800FC2C8 000F90C8  38 21 00 20 */	addi r1, r1, 0x20
/* 800FC2CC 000F90CC  4E 80 00 20 */	blr
.endfn kar_gryakurotjumphill_update_target_trigger_cycle

# .text:0x1E0 | 0x800FC2D0 | size: 0x38
.fn kar_gryakurotjumphill_create_stage_linked_rotjumphill_yaku, global
/* 800FC2D0 000F90D0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FC2D4 000F90D4  7C 08 02 A6 */	mflr r0
/* 800FC2D8 000F90D8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FC2DC 000F90DC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FC2E0 000F90E0  7C 7F 1B 78 */	mr r31, r3
/* 800FC2E4 000F90E4  38 60 00 15 */	li r3, 0x15
/* 800FC2E8 000F90E8  4B FF 81 85 */	bl kar_gryaku_create_yaku_from_main_kind
/* 800FC2EC 000F90EC  7F E4 FB 78 */	mr r4, r31
/* 800FC2F0 000F90F0  48 00 00 19 */	bl kar_gryakurotjumphill_init_stage_linked_rotjumphill_yaku
/* 800FC2F4 000F90F4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FC2F8 000F90F8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FC2FC 000F90FC  7C 08 03 A6 */	mtlr r0
/* 800FC300 000F9100  38 21 00 10 */	addi r1, r1, 0x10
/* 800FC304 000F9104  4E 80 00 20 */	blr
.endfn kar_gryakurotjumphill_create_stage_linked_rotjumphill_yaku

# .text:0x218 | 0x800FC308 | size: 0xD0
.fn kar_gryakurotjumphill_init_stage_linked_rotjumphill_yaku, global
/* 800FC308 000F9108  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800FC30C 000F910C  7C 08 02 A6 */	mflr r0
/* 800FC310 000F9110  90 01 00 24 */	stw r0, 0x24(r1)
/* 800FC314 000F9114  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800FC318 000F9118  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800FC31C 000F911C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800FC320 000F9120  93 81 00 10 */	stw r28, 0x10(r1)
/* 800FC324 000F9124  7C 7C 1B 78 */	mr r28, r3
/* 800FC328 000F9128  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 800FC32C 000F912C  83 E4 00 2C */	lwz r31, 0x2c(r4)
/* 800FC330 000F9130  80 BE 00 08 */	lwz r5, 0x8(r30)
/* 800FC334 000F9134  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 800FC338 000F9138  83 A5 00 00 */	lwz r29, 0x0(r5)
/* 800FC33C 000F913C  80 9F 01 04 */	lwz r4, 0x104(r31)
/* 800FC340 000F9140  38 63 00 54 */	addi r3, r3, 0x54
/* 800FC344 000F9144  80 1D 00 00 */	lwz r0, 0x0(r29)
/* 800FC348 000F9148  54 00 18 38 */	slwi r0, r0, 3
/* 800FC34C 000F914C  7C 84 00 2E */	lwzx r4, r4, r0
/* 800FC350 000F9150  4B FD B6 05 */	bl kar_grcoll__800d7954
/* 800FC354 000F9154  90 7E 01 30 */	stw r3, 0x130(r30)
/* 800FC358 000F9158  38 00 00 00 */	li r0, 0x0
/* 800FC35C 000F915C  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 800FC360 000F9160  80 7E 01 30 */	lwz r3, 0x130(r30)
/* 800FC364 000F9164  90 83 00 90 */	stw r4, 0x90(r3)
/* 800FC368 000F9168  C0 1D 00 08 */	lfs f0, 0x8(r29)
/* 800FC36C 000F916C  D0 1E 01 34 */	stfs f0, 0x134(r30)
/* 800FC370 000F9170  90 1E 01 38 */	stw r0, 0x138(r30)
/* 800FC374 000F9174  90 1E 01 3C */	stw r0, 0x13c(r30)
/* 800FC378 000F9178  80 9D 00 24 */	lwz r4, 0x24(r29)
/* 800FC37C 000F917C  2C 04 FF FF */	cmpwi r4, -0x1
/* 800FC380 000F9180  41 82 00 10 */	beq .L_800FC390
/* 800FC384 000F9184  7F E3 FB 78 */	mr r3, r31
/* 800FC388 000F9188  38 A0 00 00 */	li r5, 0x0
/* 800FC38C 000F918C  4B FE 68 45 */	bl kar_grrangespline_set_spline_enabled
.L_800FC390:
/* 800FC390 000F9190  80 7E 00 08 */	lwz r3, 0x8(r30)
/* 800FC394 000F9194  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800FC398 000F9198  28 00 00 00 */	cmplwi r0, 0x0
/* 800FC39C 000F919C  41 82 00 14 */	beq .L_800FC3B0
/* 800FC3A0 000F91A0  80 9D 00 00 */	lwz r4, 0x0(r29)
/* 800FC3A4 000F91A4  7F 83 E3 78 */	mr r3, r28
/* 800FC3A8 000F91A8  38 A0 00 00 */	li r5, 0x0
/* 800FC3AC 000F91AC  4B FF B4 C5 */	bl kar_gryakuaudio_configure_fgm_track_from_joint
.L_800FC3B0:
/* 800FC3B0 000F91B0  7F 83 E3 78 */	mr r3, r28
/* 800FC3B4 000F91B4  48 00 00 25 */	bl kar_gryakurotjumphill_start_current_index_path_motion
/* 800FC3B8 000F91B8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FC3BC 000F91BC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800FC3C0 000F91C0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800FC3C4 000F91C4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800FC3C8 000F91C8  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800FC3CC 000F91CC  7C 08 03 A6 */	mtlr r0
/* 800FC3D0 000F91D0  38 21 00 20 */	addi r1, r1, 0x20
/* 800FC3D4 000F91D4  4E 80 00 20 */	blr
.endfn kar_gryakurotjumphill_init_stage_linked_rotjumphill_yaku

# .text:0x2E8 | 0x800FC3D8 | size: 0x64
.fn kar_gryakurotjumphill_start_current_index_path_motion, global
/* 800FC3D8 000F91D8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FC3DC 000F91DC  7C 08 02 A6 */	mflr r0
/* 800FC3E0 000F91E0  C0 42 91 F8 */	lfs f2, lbl_805DF8F8@sda21(r0)
/* 800FC3E4 000F91E4  38 80 00 00 */	li r4, 0x0
/* 800FC3E8 000F91E8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FC3EC 000F91EC  3C 00 43 30 */	lis r0, 0x4330
/* 800FC3F0 000F91F0  C8 22 92 00 */	lfd f1, lbl_805DF900@sda21(r0)
/* 800FC3F4 000F91F4  FC 60 10 90 */	fmr f3, f2
/* 800FC3F8 000F91F8  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FC3FC 000F91FC  38 E0 00 00 */	li r7, 0x0
/* 800FC400 000F9200  90 01 00 08 */	stw r0, 0x8(r1)
/* 800FC404 000F9204  80 A3 01 38 */	lwz r5, 0x138(r3)
/* 800FC408 000F9208  80 C3 00 08 */	lwz r6, 0x8(r3)
/* 800FC40C 000F920C  6C A5 80 00 */	xoris r5, r5, 0x8000
/* 800FC410 000F9210  90 A1 00 0C */	stw r5, 0xc(r1)
/* 800FC414 000F9214  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 800FC418 000F9218  C8 01 00 08 */	lfd f0, 0x8(r1)
/* 800FC41C 000F921C  80 A6 00 04 */	lwz r5, 0x4(r6)
/* 800FC420 000F9220  EC 20 08 28 */	fsubs f1, f0, f1
/* 800FC424 000F9224  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 800FC428 000F9228  4B FF 91 21 */	bl kar_gryaku_set_path_node_motion
/* 800FC42C 000F922C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FC430 000F9230  7C 08 03 A6 */	mtlr r0
/* 800FC434 000F9234  38 21 00 10 */	addi r1, r1, 0x10
/* 800FC438 000F9238  4E 80 00 20 */	blr
.endfn kar_gryakurotjumphill_start_current_index_path_motion

# .text:0x34C | 0x800FC43C | size: 0x1C
.fn kar_gryakurotjumphill_decrement_fgm_cooldown_state0, global
/* 800FC43C 000F923C  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 800FC440 000F9240  80 64 01 3C */	lwz r3, 0x13c(r4)
/* 800FC444 000F9244  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FC448 000F9248  4C 81 00 20 */	blelr
/* 800FC44C 000F924C  38 03 FF FF */	subi r0, r3, 0x1
/* 800FC450 000F9250  90 04 01 3C */	stw r0, 0x13c(r4)
/* 800FC454 000F9254  4E 80 00 20 */	blr
.endfn kar_gryakurotjumphill_decrement_fgm_cooldown_state0

# .text:0x368 | 0x800FC458 | size: 0x1C
.fn kar_gryakurotjumphill_decrement_fgm_cooldown_state1, global
/* 800FC458 000F9258  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 800FC45C 000F925C  80 64 01 3C */	lwz r3, 0x13c(r4)
/* 800FC460 000F9260  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FC464 000F9264  4C 81 00 20 */	blelr
/* 800FC468 000F9268  38 03 FF FF */	subi r0, r3, 0x1
/* 800FC46C 000F926C  90 04 01 3C */	stw r0, 0x13c(r4)
/* 800FC470 000F9270  4E 80 00 20 */	blr
.endfn kar_gryakurotjumphill_decrement_fgm_cooldown_state1

# .text:0x384 | 0x800FC474 | size: 0x2CC
.fn kar_gryakurotjumphill_handle_collision_launch, global
/* 800FC474 000F9274  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 800FC478 000F9278  7C 08 02 A6 */	mflr r0
/* 800FC47C 000F927C  90 01 00 44 */	stw r0, 0x44(r1)
/* 800FC480 000F9280  DB E1 00 30 */	stfd f31, 0x30(r1)
/* 800FC484 000F9284  F3 E1 00 38 */	psq_st f31, 0x38(r1), 0, qr0
/* 800FC488 000F9288  39 61 00 30 */	addi r11, r1, 0x30
/* 800FC48C 000F928C  48 2B 16 BD */	bl _savegpr_24
/* 800FC490 000F9290  7C 7B 1B 78 */	mr r27, r3
/* 800FC494 000F9294  7C 9C 23 78 */	mr r28, r4
/* 800FC498 000F9298  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800FC49C 000F929C  7C B8 2B 78 */	mr r24, r5
/* 800FC4A0 000F92A0  C3 E4 03 44 */	lfs f31, 0x344(r4)
/* 800FC4A4 000F92A4  7C D9 33 78 */	mr r25, r6
/* 800FC4A8 000F92A8  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 800FC4AC 000F92AC  7C FA 3B 78 */	mr r26, r7
/* 800FC4B0 000F92B0  80 BF 01 30 */	lwz r5, 0x130(r31)
/* 800FC4B4 000F92B4  7F 83 E3 78 */	mr r3, r28
/* 800FC4B8 000F92B8  83 C4 00 00 */	lwz r30, 0x0(r4)
/* 800FC4BC 000F92BC  7F 04 C3 78 */	mr r4, r24
/* 800FC4C0 000F92C0  3B BC 00 14 */	addi r29, r28, 0x14
/* 800FC4C4 000F92C4  4B FD B6 C9 */	bl kar_grcoll__near_800d7b8c
/* 800FC4C8 000F92C8  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FC4CC 000F92CC  41 82 00 0C */	beq .L_800FC4D8
/* 800FC4D0 000F92D0  38 60 00 00 */	li r3, 0x0
/* 800FC4D4 000F92D4  48 00 02 4C */	b .L_800FC720
.L_800FC4D8:
/* 800FC4D8 000F92D8  80 AD 05 E8 */	lwz r5, lbl_805DD6C8@sda21(r0)
/* 800FC4DC 000F92DC  7F A3 EB 78 */	mr r3, r29
/* 800FC4E0 000F92E0  C0 22 92 0C */	lfs f1, lbl_805DF90C@sda21(r0)
/* 800FC4E4 000F92E4  7F 04 C3 78 */	mr r4, r24
/* 800FC4E8 000F92E8  C0 05 05 8C */	lfs f0, 0x58c(r5)
/* 800FC4EC 000F92EC  7F 25 CB 78 */	mr r5, r25
/* 800FC4F0 000F92F0  7F 46 D3 78 */	mr r6, r26
/* 800FC4F4 000F92F4  EC 21 00 32 */	fmuls f1, f1, f0
/* 800FC4F8 000F92F8  4B FD C9 E5 */	bl kar_grparts__near_800d8edc
/* 800FC4FC 000F92FC  EC 21 00 72 */	fmuls f1, f1, f1
/* 800FC500 000F9300  C0 5F 01 34 */	lfs f2, 0x134(r31)
/* 800FC504 000F9304  C0 02 91 F8 */	lfs f0, lbl_805DF8F8@sda21(r0)
/* 800FC508 000F9308  EC 3F 00 72 */	fmuls f1, f31, f1
/* 800FC50C 000F930C  EC 22 08 28 */	fsubs f1, f2, f1
/* 800FC510 000F9310  D0 3F 01 34 */	stfs f1, 0x134(r31)
/* 800FC514 000F9314  C0 3F 01 34 */	lfs f1, 0x134(r31)
/* 800FC518 000F9318  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800FC51C 000F931C  4C 40 13 82 */	cror eq, lt, eq
/* 800FC520 000F9320  40 82 01 18 */	bne .L_800FC638
/* 800FC524 000F9324  83 FB 00 2C */	lwz r31, 0x2c(r27)
/* 800FC528 000F9328  38 80 00 00 */	li r4, 0x0
/* 800FC52C 000F932C  83 4D 05 EC */	lwz r26, lbl_805DD6CC@sda21(r0)
/* 800FC530 000F9330  80 BF 00 08 */	lwz r5, 0x8(r31)
/* 800FC534 000F9334  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 800FC538 000F9338  83 C5 00 00 */	lwz r30, 0x0(r5)
/* 800FC53C 000F933C  4B FD B5 95 */	bl kar_grcoll__near_800d7ad0
/* 800FC540 000F9340  80 9E 00 18 */	lwz r4, 0x18(r30)
/* 800FC544 000F9344  3C 00 43 30 */	lis r0, 0x4330
/* 800FC548 000F9348  C0 42 91 F8 */	lfs f2, lbl_805DF8F8@sda21(r0)
/* 800FC54C 000F934C  7F E3 FB 78 */	mr r3, r31
/* 800FC550 000F9350  6C 84 80 00 */	xoris r4, r4, 0x8000
/* 800FC554 000F9354  90 01 00 08 */	stw r0, 0x8(r1)
/* 800FC558 000F9358  C8 82 92 00 */	lfd f4, lbl_805DF900@sda21(r0)
/* 800FC55C 000F935C  FC 60 10 90 */	fmr f3, f2
/* 800FC560 000F9360  90 81 00 0C */	stw r4, 0xc(r1)
/* 800FC564 000F9364  38 80 00 01 */	li r4, 0x1
/* 800FC568 000F9368  C0 02 92 08 */	lfs f0, lbl_805DF908@sda21(r0)
/* 800FC56C 000F936C  38 E0 00 00 */	li r7, 0x0
/* 800FC570 000F9370  C8 21 00 08 */	lfd f1, 0x8(r1)
/* 800FC574 000F9374  80 BE 00 04 */	lwz r5, 0x4(r30)
/* 800FC578 000F9378  EC 21 20 28 */	fsubs f1, f1, f4
/* 800FC57C 000F937C  80 DE 00 00 */	lwz r6, 0x0(r30)
/* 800FC580 000F9380  EC 21 00 28 */	fsubs f1, f1, f0
/* 800FC584 000F9384  4B FF 8F C5 */	bl kar_gryaku_set_path_node_motion
/* 800FC588 000F9388  80 1E 00 1C */	lwz r0, 0x1c(r30)
/* 800FC58C 000F938C  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FC590 000F9390  41 82 00 1C */	beq .L_800FC5AC
/* 800FC594 000F9394  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 800FC598 000F9398  38 80 00 10 */	li r4, 0x10
/* 800FC59C 000F939C  80 7A 01 04 */	lwz r3, 0x104(r26)
/* 800FC5A0 000F93A0  54 00 18 38 */	slwi r0, r0, 3
/* 800FC5A4 000F93A4  7C 63 00 2E */	lwzx r3, r3, r0
/* 800FC5A8 000F93A8  48 30 F8 59 */	bl HSD_JObjSetFlagsAll
.L_800FC5AC:
/* 800FC5AC 000F93AC  80 9E 00 24 */	lwz r4, 0x24(r30)
/* 800FC5B0 000F93B0  2C 04 FF FF */	cmpwi r4, -0x1
/* 800FC5B4 000F93B4  41 82 00 10 */	beq .L_800FC5C4
/* 800FC5B8 000F93B8  7F 43 D3 78 */	mr r3, r26
/* 800FC5BC 000F93BC  38 A0 00 01 */	li r5, 0x1
/* 800FC5C0 000F93C0  4B FE 66 11 */	bl kar_grrangespline_set_spline_enabled
.L_800FC5C4:
/* 800FC5C4 000F93C4  7F 63 DB 78 */	mr r3, r27
/* 800FC5C8 000F93C8  7F A4 EB 78 */	mr r4, r29
/* 800FC5CC 000F93CC  48 00 01 75 */	bl kar_gryakuinvisibleball_spawn_rotjump_launch_effect
/* 800FC5D0 000F93D0  C0 1F 01 34 */	lfs f0, 0x134(r31)
/* 800FC5D4 000F93D4  C0 3E 00 10 */	lfs f1, 0x10(r30)
/* 800FC5D8 000F93D8  FC 40 00 50 */	fneg f2, f0
/* 800FC5DC 000F93DC  C0 62 92 08 */	lfs f3, lbl_805DF908@sda21(r0)
/* 800FC5E0 000F93E0  C0 9E 00 0C */	lfs f4, 0xc(r30)
/* 800FC5E4 000F93E4  C0 02 91 F8 */	lfs f0, lbl_805DF8F8@sda21(r0)
/* 800FC5E8 000F93E8  EC 22 08 24 */	fdivs f1, f2, f1
/* 800FC5EC 000F93EC  EC 23 08 28 */	fsubs f1, f3, f1
/* 800FC5F0 000F93F0  EC 24 00 72 */	fmuls f1, f4, f1
/* 800FC5F4 000F93F4  D0 3C 03 34 */	stfs f1, 0x334(r28)
/* 800FC5F8 000F93F8  C0 3C 03 34 */	lfs f1, 0x334(r28)
/* 800FC5FC 000F93FC  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800FC600 000F9400  40 80 00 08 */	bge .L_800FC608
/* 800FC604 000F9404  D0 1C 03 34 */	stfs f0, 0x334(r28)
.L_800FC608:
/* 800FC608 000F9408  80 1F 01 1C */	lwz r0, 0x11c(r31)
/* 800FC60C 000F940C  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FC610 000F9410  40 81 00 10 */	ble .L_800FC620
/* 800FC614 000F9414  38 7F 01 18 */	addi r3, r31, 0x118
/* 800FC618 000F9418  38 80 00 01 */	li r4, 0x1
/* 800FC61C 000F941C  4B FE DA 69 */	bl kar_graudio_play_fgm_entry_id
.L_800FC620:
/* 800FC620 000F9420  88 1C 03 38 */	lbz r0, 0x338(r28)
/* 800FC624 000F9424  38 60 00 01 */	li r3, 0x1
/* 800FC628 000F9428  50 60 3E 30 */	rlwimi r0, r3, 7, 24, 24
/* 800FC62C 000F942C  38 60 00 01 */	li r3, 0x1
/* 800FC630 000F9430  98 1C 03 38 */	stb r0, 0x338(r28)
/* 800FC634 000F9434  48 00 00 EC */	b .L_800FC720
.L_800FC638:
/* 800FC638 000F9438  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 800FC63C 000F943C  80 9F 01 38 */	lwz r4, 0x138(r31)
/* 800FC640 000F9440  38 03 FF FF */	subi r0, r3, 0x1
/* 800FC644 000F9444  7C 04 00 00 */	cmpw r4, r0
/* 800FC648 000F9448  40 80 00 D4 */	bge .L_800FC71C
/* 800FC64C 000F944C  C0 1E 00 08 */	lfs f0, 0x8(r30)
/* 800FC650 000F9450  54 80 10 3A */	slwi r0, r4, 2
/* 800FC654 000F9454  80 7E 00 14 */	lwz r3, 0x14(r30)
/* 800FC658 000F9458  EC 21 00 24 */	fdivs f1, f1, f0
/* 800FC65C 000F945C  7C 63 02 14 */	add r3, r3, r0
/* 800FC660 000F9460  C0 03 00 04 */	lfs f0, 0x4(r3)
/* 800FC664 000F9464  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800FC668 000F9468  4C 40 13 82 */	cror eq, lt, eq
/* 800FC66C 000F946C  40 82 00 84 */	bne .L_800FC6F0
/* 800FC670 000F9470  38 04 00 01 */	addi r0, r4, 0x1
/* 800FC674 000F9474  90 1F 01 38 */	stw r0, 0x138(r31)
/* 800FC678 000F9478  48 00 00 10 */	b .L_800FC688
.L_800FC67C:
/* 800FC67C 000F947C  80 7F 01 38 */	lwz r3, 0x138(r31)
/* 800FC680 000F9480  38 03 00 01 */	addi r0, r3, 0x1
/* 800FC684 000F9484  90 1F 01 38 */	stw r0, 0x138(r31)
.L_800FC688:
/* 800FC688 000F9488  80 1F 01 38 */	lwz r0, 0x138(r31)
/* 800FC68C 000F948C  80 9E 00 14 */	lwz r4, 0x14(r30)
/* 800FC690 000F9490  54 03 10 3A */	slwi r3, r0, 2
/* 800FC694 000F9494  38 03 00 04 */	addi r0, r3, 0x4
/* 800FC698 000F9498  7C 04 04 2E */	lfsx f0, r4, r0
/* 800FC69C 000F949C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800FC6A0 000F94A0  4C 40 13 82 */	cror eq, lt, eq
/* 800FC6A4 000F94A4  41 82 FF D8 */	beq .L_800FC67C
/* 800FC6A8 000F94A8  80 7B 00 2C */	lwz r3, 0x2c(r27)
/* 800FC6AC 000F94AC  3C 00 43 30 */	lis r0, 0x4330
/* 800FC6B0 000F94B0  C0 42 91 F8 */	lfs f2, lbl_805DF8F8@sda21(r0)
/* 800FC6B4 000F94B4  38 80 00 00 */	li r4, 0x0
/* 800FC6B8 000F94B8  80 A3 01 38 */	lwz r5, 0x138(r3)
/* 800FC6BC 000F94BC  38 E0 00 00 */	li r7, 0x0
/* 800FC6C0 000F94C0  80 C3 00 08 */	lwz r6, 0x8(r3)
/* 800FC6C4 000F94C4  FC 60 10 90 */	fmr f3, f2
/* 800FC6C8 000F94C8  6C A5 80 00 */	xoris r5, r5, 0x8000
/* 800FC6CC 000F94CC  90 01 00 08 */	stw r0, 0x8(r1)
/* 800FC6D0 000F94D0  C8 22 92 00 */	lfd f1, lbl_805DF900@sda21(r0)
/* 800FC6D4 000F94D4  90 A1 00 0C */	stw r5, 0xc(r1)
/* 800FC6D8 000F94D8  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 800FC6DC 000F94DC  C8 01 00 08 */	lfd f0, 0x8(r1)
/* 800FC6E0 000F94E0  80 A6 00 04 */	lwz r5, 0x4(r6)
/* 800FC6E4 000F94E4  EC 20 08 28 */	fsubs f1, f0, f1
/* 800FC6E8 000F94E8  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 800FC6EC 000F94EC  4B FF 8E 5D */	bl kar_gryaku_set_path_node_motion
.L_800FC6F0:
/* 800FC6F0 000F94F0  80 1F 01 3C */	lwz r0, 0x13c(r31)
/* 800FC6F4 000F94F4  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FC6F8 000F94F8  40 82 00 24 */	bne .L_800FC71C
/* 800FC6FC 000F94FC  80 1F 01 1C */	lwz r0, 0x11c(r31)
/* 800FC700 000F9500  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FC704 000F9504  40 81 00 10 */	ble .L_800FC714
/* 800FC708 000F9508  38 7F 01 18 */	addi r3, r31, 0x118
/* 800FC70C 000F950C  38 80 00 00 */	li r4, 0x0
/* 800FC710 000F9510  4B FE D9 75 */	bl kar_graudio_play_fgm_entry_id
.L_800FC714:
/* 800FC714 000F9514  80 1E 00 28 */	lwz r0, 0x28(r30)
/* 800FC718 000F9518  90 1F 01 3C */	stw r0, 0x13c(r31)
.L_800FC71C:
/* 800FC71C 000F951C  38 60 00 00 */	li r3, 0x0
.L_800FC720:
/* 800FC720 000F9520  E3 E1 00 38 */	psq_l f31, 0x38(r1), 0, qr0
/* 800FC724 000F9524  39 61 00 30 */	addi r11, r1, 0x30
/* 800FC728 000F9528  CB E1 00 30 */	lfd f31, 0x30(r1)
/* 800FC72C 000F952C  48 2B 14 69 */	bl _restgpr_24
/* 800FC730 000F9530  80 01 00 44 */	lwz r0, 0x44(r1)
/* 800FC734 000F9534  7C 08 03 A6 */	mtlr r0
/* 800FC738 000F9538  38 21 00 40 */	addi r1, r1, 0x40
/* 800FC73C 000F953C  4E 80 00 20 */	blr
.endfn kar_gryakurotjumphill_handle_collision_launch

# 0x804A617C..0x804A61F0 | size: 0x74
.data
.balign 4

# .data:0x0 | 0x804A617C | size: 0x14
.obj kar_src_gryakurotjumphill_c, global
	.string "gryakurotjumphill.c"
.endobj kar_src_gryakurotjumphill_c

# .data:0x14 | 0x804A6190 | size: 0x27
.obj kar_gryakurotjumphill_assert_target_ref_in_range, global
	.string "0 <= refId && refId < param->targetNum"
.endobj kar_gryakurotjumphill_assert_target_ref_in_range

# .data:0x3B | 0x804A61B7 | size: 0x1
.obj gap_07_804A61B7_data, global
.hidden gap_07_804A61B7_data
	.byte 0x00
.endobj gap_07_804A61B7_data

# .data:0x3C | 0x804A61B8 | size: 0x20
.obj kar_gryakurotjumphill_cooldown_callback_table, global
	.4byte kar_gryakurotjumphill_decrement_fgm_cooldown_state0
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte kar_gryakurotjumphill_decrement_fgm_cooldown_state1
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj kar_gryakurotjumphill_cooldown_callback_table

# .data:0x5C | 0x804A61D8 | size: 0x18
.obj kar_gryakurotjumphill_cooldown_callback_table_ptr, global
	.4byte kar_gryakurotjumphill_cooldown_callback_table
	.4byte kar_gryakurotjumphill_handle_collision_launch
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj kar_gryakurotjumphill_cooldown_callback_table_ptr
