.include "macros.inc"
.file "grheat2.c"

# 0x8010E0E4..0x8010E2E8 | size: 0x204
.text
.balign 4

# .text:0x0 | 0x8010E0E4 | size: 0xE4
.fn kar_grheat2_init_loop_anim_and_individual_fgm_ids, global
/* 8010E0E4 0010AEE4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8010E0E8 0010AEE8  7C 08 02 A6 */	mflr r0
/* 8010E0EC 0010AEEC  90 01 00 24 */	stw r0, 0x24(r1)
/* 8010E0F0 0010AEF0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8010E0F4 0010AEF4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8010E0F8 0010AEF8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8010E0FC 0010AEFC  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 8010E100 0010AF00  3C 60 80 4A */	lis r3, kar_grheat2_callback_table@ha
/* 8010E104 0010AF04  3B E3 75 38 */	addi r31, r3, kar_grheat2_callback_table@l
/* 8010E108 0010AF08  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 8010E10C 0010AF0C  38 60 00 00 */	li r3, 0x0
/* 8010E110 0010AF10  83 A4 00 08 */	lwz r29, 0x8(r4)
/* 8010E114 0010AF14  28 1D 00 00 */	cmplwi r29, 0x0
/* 8010E118 0010AF18  41 82 00 14 */	beq .L_8010E12C
/* 8010E11C 0010AF1C  80 1D 00 00 */	lwz r0, 0x0(r29)
/* 8010E120 0010AF20  28 00 00 00 */	cmplwi r0, 0x0
/* 8010E124 0010AF24  41 82 00 08 */	beq .L_8010E12C
/* 8010E128 0010AF28  38 60 00 01 */	li r3, 0x1
.L_8010E12C:
/* 8010E12C 0010AF2C  2C 03 00 00 */	cmpwi r3, 0x0
/* 8010E130 0010AF30  40 82 00 14 */	bne .L_8010E144
/* 8010E134 0010AF34  38 7F 00 0C */	addi r3, r31, 0xc
/* 8010E138 0010AF38  38 BF 00 18 */	addi r5, r31, 0x18
/* 8010E13C 0010AF3C  38 80 00 2A */	li r4, 0x2a
/* 8010E140 0010AF40  48 31 A3 79 */	bl __assert
.L_8010E144:
/* 8010E144 0010AF44  80 9D 00 00 */	lwz r4, 0x0(r29)
/* 8010E148 0010AF48  7F C3 F3 78 */	mr r3, r30
/* 8010E14C 0010AF4C  4B FC DC FD */	bl kar_granim__800dbe48
/* 8010E150 0010AF50  80 7D 00 04 */	lwz r3, 0x4(r29)
/* 8010E154 0010AF54  80 03 00 04 */	lwz r0, 0x4(r3)
/* 8010E158 0010AF58  2C 00 00 0A */	cmpwi r0, 0xa
/* 8010E15C 0010AF5C  40 81 00 14 */	ble .L_8010E170
/* 8010E160 0010AF60  38 7F 00 0C */	addi r3, r31, 0xc
/* 8010E164 0010AF64  38 BF 00 40 */	addi r5, r31, 0x40
/* 8010E168 0010AF68  38 80 00 30 */	li r4, 0x30
/* 8010E16C 0010AF6C  48 31 A3 4D */	bl __assert
.L_8010E170:
/* 8010E170 0010AF70  7F C5 F3 78 */	mr r5, r30
/* 8010E174 0010AF74  38 C0 00 00 */	li r6, 0x0
/* 8010E178 0010AF78  38 80 00 00 */	li r4, 0x0
/* 8010E17C 0010AF7C  48 00 00 20 */	b .L_8010E19C
.L_8010E180:
/* 8010E180 0010AF80  80 63 00 00 */	lwz r3, 0x0(r3)
/* 8010E184 0010AF84  38 04 00 08 */	addi r0, r4, 0x8
/* 8010E188 0010AF88  38 84 00 10 */	addi r4, r4, 0x10
/* 8010E18C 0010AF8C  38 C6 00 01 */	addi r6, r6, 0x1
/* 8010E190 0010AF90  7C 03 00 2E */	lwzx r0, r3, r0
/* 8010E194 0010AF94  90 05 07 28 */	stw r0, 0x728(r5)
/* 8010E198 0010AF98  38 A5 00 04 */	addi r5, r5, 0x4
.L_8010E19C:
/* 8010E19C 0010AF9C  80 7D 00 04 */	lwz r3, 0x4(r29)
/* 8010E1A0 0010AFA0  80 03 00 04 */	lwz r0, 0x4(r3)
/* 8010E1A4 0010AFA4  7C 06 00 00 */	cmpw r6, r0
/* 8010E1A8 0010AFA8  41 80 FF D8 */	blt .L_8010E180
/* 8010E1AC 0010AFAC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8010E1B0 0010AFB0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8010E1B4 0010AFB4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8010E1B8 0010AFB8  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8010E1BC 0010AFBC  7C 08 03 A6 */	mtlr r0
/* 8010E1C0 0010AFC0  38 21 00 20 */	addi r1, r1, 0x20
/* 8010E1C4 0010AFC4  4E 80 00 20 */	blr
.endfn kar_grheat2_init_loop_anim_and_individual_fgm_ids

# .text:0xE4 | 0x8010E1C8 | size: 0x60
.fn kar_grheat2_create_stage_yaku_objects, global
/* 8010E1C8 0010AFC8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010E1CC 0010AFCC  7C 08 02 A6 */	mflr r0
/* 8010E1D0 0010AFD0  38 80 00 00 */	li r4, 0x0
/* 8010E1D4 0010AFD4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010E1D8 0010AFD8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010E1DC 0010AFDC  7C 7F 1B 78 */	mr r31, r3
/* 8010E1E0 0010AFE0  4B FE C5 29 */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010E1E4 0010AFE4  7F E3 FB 78 */	mr r3, r31
/* 8010E1E8 0010AFE8  38 80 00 01 */	li r4, 0x1
/* 8010E1EC 0010AFEC  4B FF 4A 55 */	bl kar_gryakubreakhouse_create_stage_linked_kind54_animfloor
/* 8010E1F0 0010AFF0  7F E3 FB 78 */	mr r3, r31
/* 8010E1F4 0010AFF4  38 80 00 02 */	li r4, 0x2
/* 8010E1F8 0010AFF8  4B FF BB BD */	bl kar_gryakubreakhpcoll_create_stage_linked_kind61_timed_anim_audio_cycle
/* 8010E1FC 0010AFFC  7F E3 FB 78 */	mr r3, r31
/* 8010E200 0010B000  38 80 00 03 */	li r4, 0x3
/* 8010E204 0010B004  4B FF BB B1 */	bl kar_gryakubreakhpcoll_create_stage_linked_kind61_timed_anim_audio_cycle
/* 8010E208 0010B008  7F E3 FB 78 */	mr r3, r31
/* 8010E20C 0010B00C  38 80 00 04 */	li r4, 0x4
/* 8010E210 0010B010  4B FF BB A5 */	bl kar_gryakubreakhpcoll_create_stage_linked_kind61_timed_anim_audio_cycle
/* 8010E214 0010B014  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010E218 0010B018  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010E21C 0010B01C  7C 08 03 A6 */	mtlr r0
/* 8010E220 0010B020  38 21 00 10 */	addi r1, r1, 0x10
/* 8010E224 0010B024  4E 80 00 20 */	blr
.endfn kar_grheat2_create_stage_yaku_objects

# .text:0x144 | 0x8010E228 | size: 0x58
.fn kar_grheat2_update_individual_fgm_timers, global
/* 8010E228 0010B028  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010E22C 0010B02C  7C 08 02 A6 */	mflr r0
/* 8010E230 0010B030  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010E234 0010B034  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010E238 0010B038  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8010E23C 0010B03C  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8010E240 0010B040  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 8010E244 0010B044  7F E3 FB 78 */	mr r3, r31
/* 8010E248 0010B048  83 C4 00 08 */	lwz r30, 0x8(r4)
/* 8010E24C 0010B04C  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 8010E250 0010B050  4B FD C1 99 */	bl kar_graudio_configure_individual_fgm_tracks
/* 8010E254 0010B054  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 8010E258 0010B058  7F E3 FB 78 */	mr r3, r31
/* 8010E25C 0010B05C  38 BF 07 28 */	addi r5, r31, 0x728
/* 8010E260 0010B060  38 C0 00 0A */	li r6, 0xa
/* 8010E264 0010B064  4B FD C3 05 */	bl kar_graudio_update_individual_fgm_timers
/* 8010E268 0010B068  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010E26C 0010B06C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010E270 0010B070  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8010E274 0010B074  7C 08 03 A6 */	mtlr r0
/* 8010E278 0010B078  38 21 00 10 */	addi r1, r1, 0x10
/* 8010E27C 0010B07C  4E 80 00 20 */	blr
.endfn kar_grheat2_update_individual_fgm_timers

# .text:0x19C | 0x8010E280 | size: 0x34
.fn kar_grheat2_start_bit_counter_id0_duration500, global
/* 8010E280 0010B080  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010E284 0010B084  7C 08 02 A6 */	mflr r0
/* 8010E288 0010B088  38 A0 00 00 */	li r5, 0x0
/* 8010E28C 0010B08C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010E290 0010B090  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 8010E294 0010B094  80 83 00 08 */	lwz r4, 0x8(r3)
/* 8010E298 0010B098  80 84 00 08 */	lwz r4, 0x8(r4)
/* 8010E29C 0010B09C  80 84 00 08 */	lwz r4, 0x8(r4)
/* 8010E2A0 0010B0A0  4B FC D3 35 */	bl kar_grcommon__800db5d4
/* 8010E2A4 0010B0A4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010E2A8 0010B0A8  7C 08 03 A6 */	mtlr r0
/* 8010E2AC 0010B0AC  38 21 00 10 */	addi r1, r1, 0x10
/* 8010E2B0 0010B0B0  4E 80 00 20 */	blr
.endfn kar_grheat2_start_bit_counter_id0_duration500

# .text:0x1D0 | 0x8010E2B4 | size: 0x34
.fn kar_grheat2_start_bit_counter_id1_duration100, global
/* 8010E2B4 0010B0B4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010E2B8 0010B0B8  7C 08 02 A6 */	mflr r0
/* 8010E2BC 0010B0BC  38 A0 00 01 */	li r5, 0x1
/* 8010E2C0 0010B0C0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010E2C4 0010B0C4  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 8010E2C8 0010B0C8  80 83 00 08 */	lwz r4, 0x8(r3)
/* 8010E2CC 0010B0CC  80 84 00 08 */	lwz r4, 0x8(r4)
/* 8010E2D0 0010B0D0  80 84 00 08 */	lwz r4, 0x8(r4)
/* 8010E2D4 0010B0D4  4B FC D3 81 */	bl kar_grcommon__800db654
/* 8010E2D8 0010B0D8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010E2DC 0010B0DC  7C 08 03 A6 */	mtlr r0
/* 8010E2E0 0010B0E0  38 21 00 10 */	addi r1, r1, 0x10
/* 8010E2E4 0010B0E4  4E 80 00 20 */	blr
.endfn kar_grheat2_start_bit_counter_id1_duration100
