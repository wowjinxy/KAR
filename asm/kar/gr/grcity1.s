.include "macros.inc"
.file "grcity1.c"

# 0x8010F114..0x8010F92C | size: 0x818
.text
.balign 4

# .text:0x0 | 0x8010F114 | size: 0x154
.fn kar_grcity1_init_mode_dependent_anim_and_bitcounter_params, global
/* 8010F114 0010BF14  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F118 0010BF18  7C 08 02 A6 */	mflr r0
/* 8010F11C 0010BF1C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F120 0010BF20  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010F124 0010BF24  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8010F128 0010BF28  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 8010F12C 0010BF2C  80 7E 00 08 */	lwz r3, 0x8(r30)
/* 8010F130 0010BF30  80 63 00 08 */	lwz r3, 0x8(r3)
/* 8010F134 0010BF34  28 03 00 00 */	cmplwi r3, 0x0
/* 8010F138 0010BF38  41 82 00 18 */	beq .L_8010F150
/* 8010F13C 0010BF3C  80 83 00 00 */	lwz r4, 0x0(r3)
/* 8010F140 0010BF40  28 04 00 00 */	cmplwi r4, 0x0
/* 8010F144 0010BF44  41 82 00 0C */	beq .L_8010F150
/* 8010F148 0010BF48  7F C3 F3 78 */	mr r3, r30
/* 8010F14C 0010BF4C  4B FC CC FD */	bl kar_granim__800dbe48
.L_8010F150:
/* 8010F150 0010BF50  48 15 2D 7D */	bl fn_80261ECC
/* 8010F154 0010BF54  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 8010F158 0010BF58  2C 03 00 17 */	cmpwi r3, 0x17
/* 8010F15C 0010BF5C  83 E4 00 08 */	lwz r31, 0x8(r4)
/* 8010F160 0010BF60  41 82 00 90 */	beq .L_8010F1F0
/* 8010F164 0010BF64  40 80 00 1C */	bge .L_8010F180
/* 8010F168 0010BF68  2C 03 00 09 */	cmpwi r3, 0x9
/* 8010F16C 0010BF6C  41 82 00 20 */	beq .L_8010F18C
/* 8010F170 0010BF70  41 80 00 C4 */	blt .L_8010F234
/* 8010F174 0010BF74  2C 03 00 16 */	cmpwi r3, 0x16
/* 8010F178 0010BF78  40 80 00 5C */	bge .L_8010F1D4
/* 8010F17C 0010BF7C  48 00 00 B8 */	b .L_8010F234
.L_8010F180:
/* 8010F180 0010BF80  2C 03 00 34 */	cmpwi r3, 0x34
/* 8010F184 0010BF84  41 82 00 88 */	beq .L_8010F20C
/* 8010F188 0010BF88  48 00 00 AC */	b .L_8010F234
.L_8010F18C:
/* 8010F18C 0010BF8C  80 9F 00 04 */	lwz r4, 0x4(r31)
/* 8010F190 0010BF90  7F C3 F3 78 */	mr r3, r30
/* 8010F194 0010BF94  4B FC C5 E1 */	bl kar_grcommon__near_800db774
/* 8010F198 0010BF98  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 8010F19C 0010BF9C  7F C3 F3 78 */	mr r3, r30
/* 8010F1A0 0010BFA0  4B FC C5 D5 */	bl kar_grcommon__near_800db774
/* 8010F1A4 0010BFA4  80 7E 00 08 */	lwz r3, 0x8(r30)
/* 8010F1A8 0010BFA8  38 80 00 04 */	li r4, 0x4
/* 8010F1AC 0010BFAC  80 63 00 08 */	lwz r3, 0x8(r3)
/* 8010F1B0 0010BFB0  80 63 00 0C */	lwz r3, 0xc(r3)
/* 8010F1B4 0010BFB4  4B FC C1 05 */	bl kar_grcommon__near_800db2b8
/* 8010F1B8 0010BFB8  3C 80 80 4A */	lis r4, kar_grcity1_mode9_anim_id_lookup_table@ha
/* 8010F1BC 0010BFBC  54 60 10 3A */	slwi r0, r3, 2
/* 8010F1C0 0010BFC0  38 84 77 E4 */	addi r4, r4, kar_grcity1_mode9_anim_id_lookup_table@l
/* 8010F1C4 0010BFC4  7F C3 F3 78 */	mr r3, r30
/* 8010F1C8 0010BFC8  7C 84 00 2E */	lwzx r4, r4, r0
/* 8010F1CC 0010BFCC  4B FC D4 65 */	bl kar_granim__near_800dc630
/* 8010F1D0 0010BFD0  48 00 00 78 */	b .L_8010F248
.L_8010F1D4:
/* 8010F1D4 0010BFD4  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 8010F1D8 0010BFD8  7F C3 F3 78 */	mr r3, r30
/* 8010F1DC 0010BFDC  4B FC C5 99 */	bl kar_grcommon__near_800db774
/* 8010F1E0 0010BFE0  7F C3 F3 78 */	mr r3, r30
/* 8010F1E4 0010BFE4  38 80 00 0F */	li r4, 0xf
/* 8010F1E8 0010BFE8  4B FC D4 49 */	bl kar_granim__near_800dc630
/* 8010F1EC 0010BFEC  48 00 00 5C */	b .L_8010F248
.L_8010F1F0:
/* 8010F1F0 0010BFF0  80 9F 00 04 */	lwz r4, 0x4(r31)
/* 8010F1F4 0010BFF4  7F C3 F3 78 */	mr r3, r30
/* 8010F1F8 0010BFF8  4B FC C5 7D */	bl kar_grcommon__near_800db774
/* 8010F1FC 0010BFFC  7F C3 F3 78 */	mr r3, r30
/* 8010F200 0010C000  38 80 00 10 */	li r4, 0x10
/* 8010F204 0010C004  4B FC D4 2D */	bl kar_granim__near_800dc630
/* 8010F208 0010C008  48 00 00 40 */	b .L_8010F248
.L_8010F20C:
/* 8010F20C 0010C00C  80 9F 00 04 */	lwz r4, 0x4(r31)
/* 8010F210 0010C010  7F C3 F3 78 */	mr r3, r30
/* 8010F214 0010C014  4B FC C5 61 */	bl kar_grcommon__near_800db774
/* 8010F218 0010C018  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 8010F21C 0010C01C  7F C3 F3 78 */	mr r3, r30
/* 8010F220 0010C020  4B FC C5 55 */	bl kar_grcommon__near_800db774
/* 8010F224 0010C024  7F C3 F3 78 */	mr r3, r30
/* 8010F228 0010C028  38 80 00 00 */	li r4, 0x0
/* 8010F22C 0010C02C  4B FC D4 05 */	bl kar_granim__near_800dc630
/* 8010F230 0010C030  48 00 00 18 */	b .L_8010F248
.L_8010F234:
/* 8010F234 0010C034  3C 60 80 4A */	lis r3, kar_src_grcity1_c@ha
/* 8010F238 0010C038  38 80 00 6A */	li r4, 0x6a
/* 8010F23C 0010C03C  38 63 77 F4 */	addi r3, r3, kar_src_grcity1_c@l
/* 8010F240 0010C040  38 AD 92 88 */	li r5, lbl_805D6368@sda21
/* 8010F244 0010C044  48 31 92 75 */	bl __assert
.L_8010F248:
/* 8010F248 0010C048  7F C3 F3 78 */	mr r3, r30
/* 8010F24C 0010C04C  4B FC CF 69 */	bl kar_granim__near_800dc1b4
/* 8010F250 0010C050  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F254 0010C054  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010F258 0010C058  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8010F25C 0010C05C  7C 08 03 A6 */	mtlr r0
/* 8010F260 0010C060  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F264 0010C064  4E 80 00 20 */	blr
.endfn kar_grcity1_init_mode_dependent_anim_and_bitcounter_params

# .text:0x154 | 0x8010F268 | size: 0x198
.fn kar_grcity1_create_stage_city_yaku_objects, global
/* 8010F268 0010C068  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F26C 0010C06C  7C 08 02 A6 */	mflr r0
/* 8010F270 0010C070  38 80 00 00 */	li r4, 0x0
/* 8010F274 0010C074  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F278 0010C078  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010F27C 0010C07C  7C 7F 1B 78 */	mr r31, r3
/* 8010F280 0010C080  4B FE B0 21 */	bl kar_gryakudownforcezone_create_stage_linked_kind17_yaku
/* 8010F284 0010C084  7F E3 FB 78 */	mr r3, r31
/* 8010F288 0010C088  38 80 00 01 */	li r4, 0x1
/* 8010F28C 0010C08C  4B FE B3 85 */	bl kar_gryakucatchzone_create_stage_linked_kind18_yaku
/* 8010F290 0010C090  7F E3 FB 78 */	mr r3, r31
/* 8010F294 0010C094  38 80 00 02 */	li r4, 0x2
/* 8010F298 0010C098  4B FE F3 3D */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010F29C 0010C09C  7F E3 FB 78 */	mr r3, r31
/* 8010F2A0 0010C0A0  38 80 00 03 */	li r4, 0x3
/* 8010F2A4 0010C0A4  4B FE F3 31 */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010F2A8 0010C0A8  7F E3 FB 78 */	mr r3, r31
/* 8010F2AC 0010C0AC  38 80 00 04 */	li r4, 0x4
/* 8010F2B0 0010C0B0  4B FE F3 25 */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010F2B4 0010C0B4  7F E3 FB 78 */	mr r3, r31
/* 8010F2B8 0010C0B8  38 80 00 05 */	li r4, 0x5
/* 8010F2BC 0010C0BC  4B FE F3 19 */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010F2C0 0010C0C0  7F E3 FB 78 */	mr r3, r31
/* 8010F2C4 0010C0C4  38 80 00 06 */	li r4, 0x6
/* 8010F2C8 0010C0C8  4B FE F3 0D */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010F2CC 0010C0CC  7F E3 FB 78 */	mr r3, r31
/* 8010F2D0 0010C0D0  38 80 00 07 */	li r4, 0x7
/* 8010F2D4 0010C0D4  4B FE F3 01 */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010F2D8 0010C0D8  7F E3 FB 78 */	mr r3, r31
/* 8010F2DC 0010C0DC  38 80 00 08 */	li r4, 0x8
/* 8010F2E0 0010C0E0  4B FE F2 F5 */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010F2E4 0010C0E4  7F E3 FB 78 */	mr r3, r31
/* 8010F2E8 0010C0E8  38 80 00 09 */	li r4, 0x9
/* 8010F2EC 0010C0EC  4B FE F2 E9 */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010F2F0 0010C0F0  7F E3 FB 78 */	mr r3, r31
/* 8010F2F4 0010C0F4  38 80 00 0A */	li r4, 0xa
/* 8010F2F8 0010C0F8  4B FE F2 DD */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010F2FC 0010C0FC  7F E3 FB 78 */	mr r3, r31
/* 8010F300 0010C100  38 80 00 0B */	li r4, 0xb
/* 8010F304 0010C104  4B FE F2 D1 */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010F308 0010C108  7F E3 FB 78 */	mr r3, r31
/* 8010F30C 0010C10C  38 80 00 0C */	li r4, 0xc
/* 8010F310 0010C110  4B FE F2 C5 */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010F314 0010C114  7F E3 FB 78 */	mr r3, r31
/* 8010F318 0010C118  38 80 00 0D */	li r4, 0xd
/* 8010F31C 0010C11C  4B FE F2 B9 */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010F320 0010C120  7F E3 FB 78 */	mr r3, r31
/* 8010F324 0010C124  38 80 00 0E */	li r4, 0xe
/* 8010F328 0010C128  4B FE F2 AD */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010F32C 0010C12C  7F E3 FB 78 */	mr r3, r31
/* 8010F330 0010C130  38 80 00 0F */	li r4, 0xf
/* 8010F334 0010C134  4B FE F2 A1 */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010F338 0010C138  7F E3 FB 78 */	mr r3, r31
/* 8010F33C 0010C13C  38 80 00 10 */	li r4, 0x10
/* 8010F340 0010C140  4B FE F2 95 */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010F344 0010C144  7F E3 FB 78 */	mr r3, r31
/* 8010F348 0010C148  38 80 00 11 */	li r4, 0x11
/* 8010F34C 0010C14C  4B FE F2 89 */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010F350 0010C150  7F E3 FB 78 */	mr r3, r31
/* 8010F354 0010C154  38 80 00 12 */	li r4, 0x12
/* 8010F358 0010C158  4B FF AA 5D */	bl kar_gryakubreakhpcoll_create_stage_linked_kind61_timed_anim_audio_cycle
/* 8010F35C 0010C15C  7F E3 FB 78 */	mr r3, r31
/* 8010F360 0010C160  38 80 00 13 */	li r4, 0x13
/* 8010F364 0010C164  4B FF AA 51 */	bl kar_gryakubreakhpcoll_create_stage_linked_kind61_timed_anim_audio_cycle
/* 8010F368 0010C168  7F E3 FB 78 */	mr r3, r31
/* 8010F36C 0010C16C  38 80 00 14 */	li r4, 0x14
/* 8010F370 0010C170  4B FF DE B9 */	bl kar_gryakubreakhpcoll_create_kind68_lighthouse_flag_controller
/* 8010F374 0010C174  7F E3 FB 78 */	mr r3, r31
/* 8010F378 0010C178  38 80 00 15 */	li r4, 0x15
/* 8010F37C 0010C17C  4B FF E7 E9 */	bl kar_gryakuwhispywoods_create_stage_linked_kind69
/* 8010F380 0010C180  7F E3 FB 78 */	mr r3, r31
/* 8010F384 0010C184  38 80 00 16 */	li r4, 0x16
/* 8010F388 0010C188  4B FF 74 9D */	bl kar_gryakulasergate_create_stage_linked_kind32_breakfloor
/* 8010F38C 0010C18C  7F E3 FB 78 */	mr r3, r31
/* 8010F390 0010C190  38 80 00 17 */	li r4, 0x17
/* 8010F394 0010C194  4B FF 74 91 */	bl kar_gryakulasergate_create_stage_linked_kind32_breakfloor
/* 8010F398 0010C198  7F E3 FB 78 */	mr r3, r31
/* 8010F39C 0010C19C  38 80 00 18 */	li r4, 0x18
/* 8010F3A0 0010C1A0  4B FF 9B 71 */	bl kar_gryakubreakhpcoll_create_stage_linked_kind37_breakhpcoll_mid
/* 8010F3A4 0010C1A4  7F E3 FB 78 */	mr r3, r31
/* 8010F3A8 0010C1A8  38 80 00 19 */	li r4, 0x19
/* 8010F3AC 0010C1AC  4B FF 99 3D */	bl kar_gryakubreakhpcoll_create_stage_linked_kind36_breakhpcoll_door
/* 8010F3B0 0010C1B0  7F E3 FB 78 */	mr r3, r31
/* 8010F3B4 0010C1B4  38 80 00 1A */	li r4, 0x1a
/* 8010F3B8 0010C1B8  4B FF 9D 81 */	bl kar_gryakubreakhpcoll_create_stage_linked_kind38_breakhpcoll_house
/* 8010F3BC 0010C1BC  7F E3 FB 78 */	mr r3, r31
/* 8010F3C0 0010C1C0  38 80 00 1B */	li r4, 0x1b
/* 8010F3C4 0010C1C4  4B FF 88 39 */	bl kar_gryakubreakcoll_create_stage_linked_kind33_breakcoll
/* 8010F3C8 0010C1C8  7F E3 FB 78 */	mr r3, r31
/* 8010F3CC 0010C1CC  38 80 00 1C */	li r4, 0x1c
/* 8010F3D0 0010C1D0  4B FF 89 95 */	bl kar_gryakubreakcoll_create_stage_linked_kind34_breakcoll
/* 8010F3D4 0010C1D4  7F E3 FB 78 */	mr r3, r31
/* 8010F3D8 0010C1D8  38 80 00 1D */	li r4, 0x1d
/* 8010F3DC 0010C1DC  4B FF 8A F1 */	bl kar_gryakubreakcoll_create_stage_linked_kind35_breakcoll
/* 8010F3E0 0010C1E0  7F E3 FB 78 */	mr r3, r31
/* 8010F3E4 0010C1E4  38 80 00 1E */	li r4, 0x1e
/* 8010F3E8 0010C1E8  4B FF 4F E1 */	bl kar_gryakubreakcoral_create_stage_linked_kind29_breakcoral
/* 8010F3EC 0010C1EC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F3F0 0010C1F0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010F3F4 0010C1F4  7C 08 03 A6 */	mtlr r0
/* 8010F3F8 0010C1F8  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F3FC 0010C1FC  4E 80 00 20 */	blr
.endfn kar_grcity1_create_stage_city_yaku_objects

# .text:0x2EC | 0x8010F400 | size: 0x1A4
.fn kar_grcity1_break_nearby_scripted_city_targets, global
/* 8010F400 0010C200  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 8010F404 0010C204  7C 08 02 A6 */	mflr r0
/* 8010F408 0010C208  90 01 00 64 */	stw r0, 0x64(r1)
/* 8010F40C 0010C20C  DB E1 00 50 */	stfd f31, 0x50(r1)
/* 8010F410 0010C210  F3 E1 00 58 */	psq_st f31, 0x58(r1), 0, qr0
/* 8010F414 0010C214  39 61 00 50 */	addi r11, r1, 0x50
/* 8010F418 0010C218  48 29 E7 29 */	bl _savegpr_22
/* 8010F41C 0010C21C  80 8D 05 EC */	lwz r4, lbl_805DD6CC@sda21(r0)
/* 8010F420 0010C220  FF E0 08 90 */	fmr f31, f1
/* 8010F424 0010C224  7C 7F 1B 78 */	mr r31, r3
/* 8010F428 0010C228  80 64 00 08 */	lwz r3, 0x8(r4)
/* 8010F42C 0010C22C  80 63 00 08 */	lwz r3, 0x8(r3)
/* 8010F430 0010C230  83 23 00 10 */	lwz r25, 0x10(r3)
/* 8010F434 0010C234  28 19 00 00 */	cmplwi r25, 0x0
/* 8010F438 0010C238  41 82 01 4C */	beq .L_8010F584
/* 8010F43C 0010C23C  3B 00 00 00 */	li r24, 0x0
/* 8010F440 0010C240  3B 40 00 00 */	li r26, 0x0
/* 8010F444 0010C244  48 00 01 34 */	b .L_8010F578
.L_8010F448:
/* 8010F448 0010C248  80 19 00 00 */	lwz r0, 0x0(r25)
/* 8010F44C 0010C24C  3A C0 00 00 */	li r22, 0x0
/* 8010F450 0010C250  3B 60 00 00 */	li r27, 0x0
/* 8010F454 0010C254  7E E0 D2 14 */	add r23, r0, r26
/* 8010F458 0010C258  48 00 01 0C */	b .L_8010F564
.L_8010F45C:
/* 8010F45C 0010C25C  80 77 00 00 */	lwz r3, 0x0(r23)
/* 8010F460 0010C260  38 81 00 14 */	addi r4, r1, 0x14
/* 8010F464 0010C264  7C 63 D8 2E */	lwzx r3, r3, r27
/* 8010F468 0010C268  4B FC 57 8D */	bl kar_grcommon__near_800d4bf4
/* 8010F46C 0010C26C  C0 21 00 14 */	lfs f1, 0x14(r1)
/* 8010F470 0010C270  38 61 00 08 */	addi r3, r1, 0x8
/* 8010F474 0010C274  C0 1F 00 00 */	lfs f0, 0x0(r31)
/* 8010F478 0010C278  C0 41 00 18 */	lfs f2, 0x18(r1)
/* 8010F47C 0010C27C  EC 01 00 28 */	fsubs f0, f1, f0
/* 8010F480 0010C280  C0 21 00 1C */	lfs f1, 0x1c(r1)
/* 8010F484 0010C284  D0 01 00 08 */	stfs f0, 0x8(r1)
/* 8010F488 0010C288  C0 1F 00 04 */	lfs f0, 0x4(r31)
/* 8010F48C 0010C28C  EC 02 00 28 */	fsubs f0, f2, f0
/* 8010F490 0010C290  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 8010F494 0010C294  C0 1F 00 08 */	lfs f0, 0x8(r31)
/* 8010F498 0010C298  EC 01 00 28 */	fsubs f0, f1, f0
/* 8010F49C 0010C29C  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 8010F4A0 0010C2A0  48 2C 2C B9 */	bl fn_803D2158
/* 8010F4A4 0010C2A4  FC 01 F8 40 */	fcmpo cr0, f1, f31
/* 8010F4A8 0010C2A8  4C 40 13 82 */	cror eq, lt, eq
/* 8010F4AC 0010C2AC  40 82 00 B0 */	bne .L_8010F55C
/* 8010F4B0 0010C2B0  38 61 00 08 */	addi r3, r1, 0x8
/* 8010F4B4 0010C2B4  7C 64 1B 78 */	mr r4, r3
/* 8010F4B8 0010C2B8  4B F5 37 ED */	bl kar_lbvector_normalize_with_axis_fallback
/* 8010F4BC 0010C2BC  83 97 00 08 */	lwz r28, 0x8(r23)
/* 8010F4C0 0010C2C0  3B C0 00 00 */	li r30, 0x0
.L_8010F4C4:
/* 8010F4C4 0010C2C4  7F C3 F3 78 */	mr r3, r30
/* 8010F4C8 0010C2C8  48 11 D3 91 */	bl kar_plclearcheckerlib__near_8022c858
/* 8010F4CC 0010C2CC  2C 03 00 04 */	cmpwi r3, 0x4
/* 8010F4D0 0010C2D0  40 82 00 10 */	bne .L_8010F4E0
/* 8010F4D4 0010C2D4  3B DE 00 01 */	addi r30, r30, 0x1
/* 8010F4D8 0010C2D8  2C 1E 00 05 */	cmpwi r30, 0x5
/* 8010F4DC 0010C2DC  41 80 FF E8 */	blt .L_8010F4C4
.L_8010F4E0:
/* 8010F4E0 0010C2E0  80 6D 12 50 */	lwz r3, lbl_805DE330@sda21(r0)
/* 8010F4E4 0010C2E4  83 A3 00 20 */	lwz r29, 0x20(r3)
/* 8010F4E8 0010C2E8  48 00 00 6C */	b .L_8010F554
.L_8010F4EC:
/* 8010F4EC 0010C2EC  7F A3 EB 78 */	mr r3, r29
/* 8010F4F0 0010C2F0  4B FE 85 75 */	bl kar_gryakulib_get_yaku_data_checked
/* 8010F4F4 0010C2F4  7C 1C 18 00 */	cmpw r28, r3
/* 8010F4F8 0010C2F8  40 82 00 58 */	bne .L_8010F550
/* 8010F4FC 0010C2FC  2C 1C 00 26 */	cmpwi r28, 0x26
/* 8010F500 0010C300  41 82 00 1C */	beq .L_8010F51C
/* 8010F504 0010C304  40 80 00 4C */	bge .L_8010F550
/* 8010F508 0010C308  2C 1C 00 24 */	cmpwi r28, 0x24
/* 8010F50C 0010C30C  40 80 00 44 */	bge .L_8010F550
/* 8010F510 0010C310  2C 1C 00 21 */	cmpwi r28, 0x21
/* 8010F514 0010C314  40 80 00 28 */	bge .L_8010F53C
/* 8010F518 0010C318  48 00 00 38 */	b .L_8010F550
.L_8010F51C:
/* 8010F51C 0010C31C  38 C1 00 08 */	addi r6, r1, 0x8
/* 8010F520 0010C320  7F A3 EB 78 */	mr r3, r29
/* 8010F524 0010C324  7E C4 B3 78 */	mr r4, r22
/* 8010F528 0010C328  7F C8 F3 78 */	mr r8, r30
/* 8010F52C 0010C32C  7C C7 33 78 */	mr r7, r6
/* 8010F530 0010C330  38 A1 00 14 */	addi r5, r1, 0x14
/* 8010F534 0010C334  4B FF 8B B9 */	bl kar_gryakubreakhpcoll_break_target_by_index_with_credit
/* 8010F538 0010C338  48 00 00 18 */	b .L_8010F550
.L_8010F53C:
/* 8010F53C 0010C33C  7F A3 EB 78 */	mr r3, r29
/* 8010F540 0010C340  7E C4 B3 78 */	mr r4, r22
/* 8010F544 0010C344  7F C6 F3 78 */	mr r6, r30
/* 8010F548 0010C348  38 A1 00 08 */	addi r5, r1, 0x8
/* 8010F54C 0010C34C  4B FF 80 31 */	bl kar_gryakubreakcoll_break_target_by_index
.L_8010F550:
/* 8010F550 0010C350  83 BD 00 0C */	lwz r29, 0xc(r29)
.L_8010F554:
/* 8010F554 0010C354  28 1D 00 00 */	cmplwi r29, 0x0
/* 8010F558 0010C358  40 82 FF 94 */	bne .L_8010F4EC
.L_8010F55C:
/* 8010F55C 0010C35C  3B 7B 00 04 */	addi r27, r27, 0x4
/* 8010F560 0010C360  3A D6 00 01 */	addi r22, r22, 0x1
.L_8010F564:
/* 8010F564 0010C364  80 17 00 04 */	lwz r0, 0x4(r23)
/* 8010F568 0010C368  7C 16 00 00 */	cmpw r22, r0
/* 8010F56C 0010C36C  41 80 FE F0 */	blt .L_8010F45C
/* 8010F570 0010C370  3B 5A 00 0C */	addi r26, r26, 0xc
/* 8010F574 0010C374  3B 18 00 01 */	addi r24, r24, 0x1
.L_8010F578:
/* 8010F578 0010C378  80 19 00 04 */	lwz r0, 0x4(r25)
/* 8010F57C 0010C37C  7C 18 00 00 */	cmpw r24, r0
/* 8010F580 0010C380  41 80 FE C8 */	blt .L_8010F448
.L_8010F584:
/* 8010F584 0010C384  E3 E1 00 58 */	psq_l f31, 0x58(r1), 0, qr0
/* 8010F588 0010C388  39 61 00 50 */	addi r11, r1, 0x50
/* 8010F58C 0010C38C  CB E1 00 50 */	lfd f31, 0x50(r1)
/* 8010F590 0010C390  48 29 E5 FD */	bl _restgpr_22
/* 8010F594 0010C394  80 01 00 64 */	lwz r0, 0x64(r1)
/* 8010F598 0010C398  7C 08 03 A6 */	mtlr r0
/* 8010F59C 0010C39C  38 21 00 60 */	addi r1, r1, 0x60
/* 8010F5A0 0010C3A0  4E 80 00 20 */	blr
.endfn kar_grcity1_break_nearby_scripted_city_targets

# .text:0x490 | 0x8010F5A4 | size: 0x44
.fn kar_grcity1_lookup_script_entry_value, global
/* 8010F5A4 0010C3A4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F5A8 0010C3A8  7C 08 02 A6 */	mflr r0
/* 8010F5AC 0010C3AC  7C 64 1B 78 */	mr r4, r3
/* 8010F5B0 0010C3B0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F5B4 0010C3B4  80 AD 05 EC */	lwz r5, lbl_805DD6CC@sda21(r0)
/* 8010F5B8 0010C3B8  80 65 00 08 */	lwz r3, 0x8(r5)
/* 8010F5BC 0010C3BC  80 63 00 08 */	lwz r3, 0x8(r3)
/* 8010F5C0 0010C3C0  80 63 00 10 */	lwz r3, 0x10(r3)
/* 8010F5C4 0010C3C4  28 03 00 00 */	cmplwi r3, 0x0
/* 8010F5C8 0010C3C8  41 82 00 0C */	beq .L_8010F5D4
/* 8010F5CC 0010C3CC  4B FE 95 A9 */	bl kar_gryakucommon_lookup_script_entry_value
/* 8010F5D0 0010C3D0  48 00 00 08 */	b .L_8010F5D8
.L_8010F5D4:
/* 8010F5D4 0010C3D4  38 60 00 00 */	li r3, 0x0
.L_8010F5D8:
/* 8010F5D8 0010C3D8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F5DC 0010C3DC  7C 08 03 A6 */	mtlr r0
/* 8010F5E0 0010C3E0  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F5E4 0010C3E4  4E 80 00 20 */	blr
.endfn kar_grcity1_lookup_script_entry_value

# .text:0x4D4 | 0x8010F5E8 | size: 0x34
.fn kar_grcity1_start_bit_counter_id0_duration500, global
/* 8010F5E8 0010C3E8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F5EC 0010C3EC  7C 08 02 A6 */	mflr r0
/* 8010F5F0 0010C3F0  38 A0 00 00 */	li r5, 0x0
/* 8010F5F4 0010C3F4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F5F8 0010C3F8  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 8010F5FC 0010C3FC  80 83 00 08 */	lwz r4, 0x8(r3)
/* 8010F600 0010C400  80 84 00 08 */	lwz r4, 0x8(r4)
/* 8010F604 0010C404  80 84 00 14 */	lwz r4, 0x14(r4)
/* 8010F608 0010C408  4B FC BF CD */	bl kar_grcommon__800db5d4
/* 8010F60C 0010C40C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F610 0010C410  7C 08 03 A6 */	mtlr r0
/* 8010F614 0010C414  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F618 0010C418  4E 80 00 20 */	blr
.endfn kar_grcity1_start_bit_counter_id0_duration500

# .text:0x508 | 0x8010F61C | size: 0x34
.fn kar_grcity1_start_bit_counter_id1_duration500, global
/* 8010F61C 0010C41C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F620 0010C420  7C 08 02 A6 */	mflr r0
/* 8010F624 0010C424  38 A0 00 01 */	li r5, 0x1
/* 8010F628 0010C428  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F62C 0010C42C  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 8010F630 0010C430  80 83 00 08 */	lwz r4, 0x8(r3)
/* 8010F634 0010C434  80 84 00 08 */	lwz r4, 0x8(r4)
/* 8010F638 0010C438  80 84 00 14 */	lwz r4, 0x14(r4)
/* 8010F63C 0010C43C  4B FC BF 99 */	bl kar_grcommon__800db5d4
/* 8010F640 0010C440  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F644 0010C444  7C 08 03 A6 */	mtlr r0
/* 8010F648 0010C448  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F64C 0010C44C  4E 80 00 20 */	blr
.endfn kar_grcity1_start_bit_counter_id1_duration500

# .text:0x53C | 0x8010F650 | size: 0x34
.fn kar_grcity1_start_bit_counter_id2_duration500, global
/* 8010F650 0010C450  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F654 0010C454  7C 08 02 A6 */	mflr r0
/* 8010F658 0010C458  38 A0 00 02 */	li r5, 0x2
/* 8010F65C 0010C45C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F660 0010C460  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 8010F664 0010C464  80 83 00 08 */	lwz r4, 0x8(r3)
/* 8010F668 0010C468  80 84 00 08 */	lwz r4, 0x8(r4)
/* 8010F66C 0010C46C  80 84 00 14 */	lwz r4, 0x14(r4)
/* 8010F670 0010C470  4B FC BF 65 */	bl kar_grcommon__800db5d4
/* 8010F674 0010C474  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F678 0010C478  7C 08 03 A6 */	mtlr r0
/* 8010F67C 0010C47C  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F680 0010C480  4E 80 00 20 */	blr
.endfn kar_grcity1_start_bit_counter_id2_duration500

# .text:0x570 | 0x8010F684 | size: 0x34
.fn kar_grcity1_start_bit_counter_id3_duration500, global
/* 8010F684 0010C484  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F688 0010C488  7C 08 02 A6 */	mflr r0
/* 8010F68C 0010C48C  38 A0 00 03 */	li r5, 0x3
/* 8010F690 0010C490  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F694 0010C494  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 8010F698 0010C498  80 83 00 08 */	lwz r4, 0x8(r3)
/* 8010F69C 0010C49C  80 84 00 08 */	lwz r4, 0x8(r4)
/* 8010F6A0 0010C4A0  80 84 00 14 */	lwz r4, 0x14(r4)
/* 8010F6A4 0010C4A4  4B FC BF 31 */	bl kar_grcommon__800db5d4
/* 8010F6A8 0010C4A8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F6AC 0010C4AC  7C 08 03 A6 */	mtlr r0
/* 8010F6B0 0010C4B0  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F6B4 0010C4B4  4E 80 00 20 */	blr
.endfn kar_grcity1_start_bit_counter_id3_duration500

# .text:0x5A4 | 0x8010F6B8 | size: 0x34
.fn kar_grcity1_start_bit_counter_id4_duration100, global
/* 8010F6B8 0010C4B8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F6BC 0010C4BC  7C 08 02 A6 */	mflr r0
/* 8010F6C0 0010C4C0  38 A0 00 04 */	li r5, 0x4
/* 8010F6C4 0010C4C4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F6C8 0010C4C8  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 8010F6CC 0010C4CC  80 83 00 08 */	lwz r4, 0x8(r3)
/* 8010F6D0 0010C4D0  80 84 00 08 */	lwz r4, 0x8(r4)
/* 8010F6D4 0010C4D4  80 84 00 14 */	lwz r4, 0x14(r4)
/* 8010F6D8 0010C4D8  4B FC BF 7D */	bl kar_grcommon__800db654
/* 8010F6DC 0010C4DC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F6E0 0010C4E0  7C 08 03 A6 */	mtlr r0
/* 8010F6E4 0010C4E4  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F6E8 0010C4E8  4E 80 00 20 */	blr
.endfn kar_grcity1_start_bit_counter_id4_duration100

# .text:0x5D8 | 0x8010F6EC | size: 0x34
.fn kar_grcity1_start_bit_counter_id5_duration100, global
/* 8010F6EC 0010C4EC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F6F0 0010C4F0  7C 08 02 A6 */	mflr r0
/* 8010F6F4 0010C4F4  38 A0 00 05 */	li r5, 0x5
/* 8010F6F8 0010C4F8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F6FC 0010C4FC  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 8010F700 0010C500  80 83 00 08 */	lwz r4, 0x8(r3)
/* 8010F704 0010C504  80 84 00 08 */	lwz r4, 0x8(r4)
/* 8010F708 0010C508  80 84 00 14 */	lwz r4, 0x14(r4)
/* 8010F70C 0010C50C  4B FC BF 49 */	bl kar_grcommon__800db654
/* 8010F710 0010C510  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F714 0010C514  7C 08 03 A6 */	mtlr r0
/* 8010F718 0010C518  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F71C 0010C51C  4E 80 00 20 */	blr
.endfn kar_grcity1_start_bit_counter_id5_duration100

# .text:0x60C | 0x8010F720 | size: 0xA4
.fn kar_grcity1_check_bit_counter_param_id_membership, global
/* 8010F720 0010C520  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F724 0010C524  7C 08 02 A6 */	mflr r0
/* 8010F728 0010C528  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F72C 0010C52C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010F730 0010C530  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8010F734 0010C534  7C 7E 1B 78 */	mr r30, r3
/* 8010F738 0010C538  80 8D 05 EC */	lwz r4, lbl_805DD6CC@sda21(r0)
/* 8010F73C 0010C53C  80 64 00 08 */	lwz r3, 0x8(r4)
/* 8010F740 0010C540  83 E3 00 08 */	lwz r31, 0x8(r3)
/* 8010F744 0010C544  80 7F 00 14 */	lwz r3, 0x14(r31)
/* 8010F748 0010C548  80 03 00 04 */	lwz r0, 0x4(r3)
/* 8010F74C 0010C54C  2C 00 00 06 */	cmpwi r0, 0x6
/* 8010F750 0010C550  41 81 00 1C */	bgt .L_8010F76C
/* 8010F754 0010C554  3C 60 80 4A */	lis r3, kar_src_grcity1_c@ha
/* 8010F758 0010C558  3C A0 80 4A */	lis r5, kar_grcity1_assert_bit_counter_id_count_at_least7@ha
/* 8010F75C 0010C55C  38 63 77 F4 */	addi r3, r3, kar_src_grcity1_c@l
/* 8010F760 0010C560  38 80 01 C3 */	li r4, 0x1c3
/* 8010F764 0010C564  38 A5 78 00 */	addi r5, r5, kar_grcity1_assert_bit_counter_id_count_at_least7@l
/* 8010F768 0010C568  48 31 8D 51 */	bl __assert
.L_8010F76C:
/* 8010F76C 0010C56C  80 7F 00 14 */	lwz r3, 0x14(r31)
/* 8010F770 0010C570  38 A0 00 00 */	li r5, 0x0
/* 8010F774 0010C574  80 83 00 00 */	lwz r4, 0x0(r3)
/* 8010F778 0010C578  80 04 00 34 */	lwz r0, 0x34(r4)
/* 8010F77C 0010C57C  7C 09 03 A6 */	mtctr r0
/* 8010F780 0010C580  2C 00 00 00 */	cmpwi r0, 0x0
/* 8010F784 0010C584  40 81 00 24 */	ble .L_8010F7A8
.L_8010F788:
/* 8010F788 0010C588  80 64 00 30 */	lwz r3, 0x30(r4)
/* 8010F78C 0010C58C  7C 03 28 2E */	lwzx r0, r3, r5
/* 8010F790 0010C590  7C 1E 00 00 */	cmpw r30, r0
/* 8010F794 0010C594  40 82 00 0C */	bne .L_8010F7A0
/* 8010F798 0010C598  38 60 00 01 */	li r3, 0x1
/* 8010F79C 0010C59C  48 00 00 10 */	b .L_8010F7AC
.L_8010F7A0:
/* 8010F7A0 0010C5A0  38 A5 00 04 */	addi r5, r5, 0x4
/* 8010F7A4 0010C5A4  42 00 FF E4 */	bdnz .L_8010F788
.L_8010F7A8:
/* 8010F7A8 0010C5A8  38 60 00 00 */	li r3, 0x0
.L_8010F7AC:
/* 8010F7AC 0010C5AC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F7B0 0010C5B0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010F7B4 0010C5B4  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8010F7B8 0010C5B8  7C 08 03 A6 */	mtlr r0
/* 8010F7BC 0010C5BC  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F7C0 0010C5C0  4E 80 00 20 */	blr
.endfn kar_grcity1_check_bit_counter_param_id_membership

# .text:0x6B0 | 0x8010F7C4 | size: 0x90
.fn kar_grcity1_patch_asset_material_anim_params, global
/* 8010F7C4 0010C5C4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8010F7C8 0010C5C8  7C 08 02 A6 */	mflr r0
/* 8010F7CC 0010C5CC  90 01 00 24 */	stw r0, 0x24(r1)
/* 8010F7D0 0010C5D0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8010F7D4 0010C5D4  7C 7F 1B 78 */	mr r31, r3
/* 8010F7D8 0010C5D8  38 61 00 08 */	addi r3, r1, 0x8
/* 8010F7DC 0010C5DC  4B FB F1 49 */	bl kar_gr_assets__asset_800ce924
/* 8010F7E0 0010C5E0  80 61 00 08 */	lwz r3, 0x8(r1)
/* 8010F7E4 0010C5E4  80 03 00 00 */	lwz r0, 0x0(r3)
/* 8010F7E8 0010C5E8  90 1F 00 30 */	stw r0, 0x30(r31)
/* 8010F7EC 0010C5EC  80 61 00 08 */	lwz r3, 0x8(r1)
/* 8010F7F0 0010C5F0  80 BF 00 40 */	lwz r5, 0x40(r31)
/* 8010F7F4 0010C5F4  80 83 00 04 */	lwz r4, 0x4(r3)
/* 8010F7F8 0010C5F8  80 65 00 00 */	lwz r3, 0x0(r5)
/* 8010F7FC 0010C5FC  80 84 00 00 */	lwz r4, 0x0(r4)
/* 8010F800 0010C600  80 04 00 00 */	lwz r0, 0x0(r4)
/* 8010F804 0010C604  90 03 00 7C */	stw r0, 0x7c(r3)
/* 8010F808 0010C608  80 81 00 08 */	lwz r4, 0x8(r1)
/* 8010F80C 0010C60C  80 65 00 00 */	lwz r3, 0x0(r5)
/* 8010F810 0010C610  80 84 00 04 */	lwz r4, 0x4(r4)
/* 8010F814 0010C614  80 84 00 00 */	lwz r4, 0x0(r4)
/* 8010F818 0010C618  80 04 00 04 */	lwz r0, 0x4(r4)
/* 8010F81C 0010C61C  90 03 00 80 */	stw r0, 0x80(r3)
/* 8010F820 0010C620  80 61 00 08 */	lwz r3, 0x8(r1)
/* 8010F824 0010C624  80 63 00 04 */	lwz r3, 0x4(r3)
/* 8010F828 0010C628  80 03 00 08 */	lwz r0, 0x8(r3)
/* 8010F82C 0010C62C  90 05 00 08 */	stw r0, 0x8(r5)
/* 8010F830 0010C630  80 61 00 08 */	lwz r3, 0x8(r1)
/* 8010F834 0010C634  80 63 00 04 */	lwz r3, 0x4(r3)
/* 8010F838 0010C638  80 03 00 0C */	lwz r0, 0xc(r3)
/* 8010F83C 0010C63C  90 05 00 0C */	stw r0, 0xc(r5)
/* 8010F840 0010C640  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8010F844 0010C644  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8010F848 0010C648  7C 08 03 A6 */	mtlr r0
/* 8010F84C 0010C64C  38 21 00 20 */	addi r1, r1, 0x20
/* 8010F850 0010C650  4E 80 00 20 */	blr
.endfn kar_grcity1_patch_asset_material_anim_params

# .text:0x740 | 0x8010F854 | size: 0x2C
.fn kar_grcity1_init_risingcube_switch_group, global
/* 8010F854 0010C654  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F858 0010C658  7C 08 02 A6 */	mflr r0
/* 8010F85C 0010C65C  38 8D 92 90 */	li r4, lbl_805D6370@sda21
/* 8010F860 0010C660  38 A0 00 02 */	li r5, 0x2
/* 8010F864 0010C664  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F868 0010C668  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8010F86C 0010C66C  4B FD 8D 3D */	bl kar_grswitch__800e85a8
/* 8010F870 0010C670  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F874 0010C674  7C 08 03 A6 */	mtlr r0
/* 8010F878 0010C678  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F87C 0010C67C  4E 80 00 20 */	blr
.endfn kar_grcity1_init_risingcube_switch_group

# .text:0x76C | 0x8010F880 | size: 0x3C
.fn kar_grcity1_create_stage_risingcube_pair, global
/* 8010F880 0010C680  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F884 0010C684  7C 08 02 A6 */	mflr r0
/* 8010F888 0010C688  38 80 00 00 */	li r4, 0x0
/* 8010F88C 0010C68C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F890 0010C690  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010F894 0010C694  7C 7F 1B 78 */	mr r31, r3
/* 8010F898 0010C698  4B FE D4 AD */	bl kar_gryakurisingcube_create_stage_linked_cube_yaku
/* 8010F89C 0010C69C  7F E3 FB 78 */	mr r3, r31
/* 8010F8A0 0010C6A0  38 80 00 01 */	li r4, 0x1
/* 8010F8A4 0010C6A4  4B FE D4 A1 */	bl kar_gryakurisingcube_create_stage_linked_cube_yaku
/* 8010F8A8 0010C6A8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F8AC 0010C6AC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010F8B0 0010C6B0  7C 08 03 A6 */	mtlr r0
/* 8010F8B4 0010C6B4  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F8B8 0010C6B8  4E 80 00 20 */	blr
.endfn kar_grcity1_create_stage_risingcube_pair

# .text:0x7A8 | 0x8010F8BC | size: 0x30
.fn kar_grcity1_switch0_trigger_risingcube_by_stage_index, global
/* 8010F8BC 0010C6BC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F8C0 0010C6C0  7C 08 02 A6 */	mflr r0
/* 8010F8C4 0010C6C4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F8C8 0010C6C8  1C 04 00 48 */	mulli r0, r4, 0x48
/* 8010F8CC 0010C6CC  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 8010F8D0 0010C6D0  7C 63 02 14 */	add r3, r3, r0
/* 8010F8D4 0010C6D4  80 63 02 18 */	lwz r3, 0x218(r3)
/* 8010F8D8 0010C6D8  4B FE DF B9 */	bl kar_gryakurisingcube_trigger_cube_state_toggle
/* 8010F8DC 0010C6DC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F8E0 0010C6E0  7C 08 03 A6 */	mtlr r0
/* 8010F8E4 0010C6E4  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F8E8 0010C6E8  4E 80 00 20 */	blr
.endfn kar_grcity1_switch0_trigger_risingcube_by_stage_index

# .text:0x7D8 | 0x8010F8EC | size: 0x30
.fn kar_grcity1_switch1_trigger_risingcube_by_stage_index, global
/* 8010F8EC 0010C6EC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F8F0 0010C6F0  7C 08 02 A6 */	mflr r0
/* 8010F8F4 0010C6F4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F8F8 0010C6F8  1C 04 00 48 */	mulli r0, r4, 0x48
/* 8010F8FC 0010C6FC  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 8010F900 0010C700  7C 63 02 14 */	add r3, r3, r0
/* 8010F904 0010C704  80 63 02 18 */	lwz r3, 0x218(r3)
/* 8010F908 0010C708  4B FE DF 89 */	bl kar_gryakurisingcube_trigger_cube_state_toggle
/* 8010F90C 0010C70C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F910 0010C710  7C 08 03 A6 */	mtlr r0
/* 8010F914 0010C714  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F918 0010C718  4E 80 00 20 */	blr
.endfn kar_grcity1_switch1_trigger_risingcube_by_stage_index

# .text:0x808 | 0x8010F91C | size: 0x4
.fn fn_8010F91C, global
/* 8010F91C 0010C71C  4E 80 00 20 */	blr
.endfn fn_8010F91C

# .text:0x80C | 0x8010F920 | size: 0x4
.fn fn_8010F920, global
/* 8010F920 0010C720  4E 80 00 20 */	blr
.endfn fn_8010F920

# .text:0x810 | 0x8010F924 | size: 0x4
.fn fn_8010F924, global
/* 8010F924 0010C724  4E 80 00 20 */	blr
.endfn fn_8010F924

# .text:0x814 | 0x8010F928 | size: 0x4
.fn fn_8010F928, global
/* 8010F928 0010C728  4E 80 00 20 */	blr
.endfn fn_8010F928
