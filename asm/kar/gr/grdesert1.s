.include "macros.inc"
.file "grdesert1.c"

# 0x8010E2E8..0x8010E798 | size: 0x4B0
.text
.balign 4

# .text:0x0 | 0x8010E2E8 | size: 0x90
.fn kar_grdesert1_init_loop_anim_and_switch_group, global
/* 8010E2E8 0010B0E8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010E2EC 0010B0EC  7C 08 02 A6 */	mflr r0
/* 8010E2F0 0010B0F0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010E2F4 0010B0F4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010E2F8 0010B0F8  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8010E2FC 0010B0FC  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8010E300 0010B100  38 60 00 00 */	li r3, 0x0
/* 8010E304 0010B104  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 8010E308 0010B108  83 C4 00 08 */	lwz r30, 0x8(r4)
/* 8010E30C 0010B10C  28 1E 00 00 */	cmplwi r30, 0x0
/* 8010E310 0010B110  41 82 00 14 */	beq .L_8010E324
/* 8010E314 0010B114  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 8010E318 0010B118  28 00 00 00 */	cmplwi r0, 0x0
/* 8010E31C 0010B11C  41 82 00 08 */	beq .L_8010E324
/* 8010E320 0010B120  38 60 00 01 */	li r3, 0x1
.L_8010E324:
/* 8010E324 0010B124  2C 03 00 00 */	cmpwi r3, 0x0
/* 8010E328 0010B128  40 82 00 1C */	bne .L_8010E344
/* 8010E32C 0010B12C  3C 60 80 4A */	lis r3, kar_src_grdesert1_c@ha
/* 8010E330 0010B130  3C A0 80 4A */	lis r5, kar_grdesert1_assert_loop_anim_param_present@ha
/* 8010E334 0010B134  38 63 75 CC */	addi r3, r3, kar_src_grdesert1_c@l
/* 8010E338 0010B138  38 80 00 31 */	li r4, 0x31
/* 8010E33C 0010B13C  38 A5 75 D8 */	addi r5, r5, kar_grdesert1_assert_loop_anim_param_present@l
/* 8010E340 0010B140  48 31 A1 79 */	bl __assert
.L_8010E344:
/* 8010E344 0010B144  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 8010E348 0010B148  7F E3 FB 78 */	mr r3, r31
/* 8010E34C 0010B14C  4B FC DA FD */	bl kar_granim__800dbe48
/* 8010E350 0010B150  7F E3 FB 78 */	mr r3, r31
/* 8010E354 0010B154  38 8D 92 78 */	li r4, lbl_805D6358@sda21
/* 8010E358 0010B158  38 A0 00 02 */	li r5, 0x2
/* 8010E35C 0010B15C  4B FD A2 4D */	bl kar_grswitch__800e85a8
/* 8010E360 0010B160  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010E364 0010B164  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010E368 0010B168  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8010E36C 0010B16C  7C 08 03 A6 */	mtlr r0
/* 8010E370 0010B170  38 21 00 10 */	addi r1, r1, 0x10
/* 8010E374 0010B174  4E 80 00 20 */	blr
.endfn kar_grdesert1_init_loop_anim_and_switch_group

# .text:0x90 | 0x8010E378 | size: 0x18C
.fn kar_grdesert1_create_main_stage_yaku_objects, global
/* 8010E378 0010B178  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010E37C 0010B17C  7C 08 02 A6 */	mflr r0
/* 8010E380 0010B180  38 80 00 00 */	li r4, 0x0
/* 8010E384 0010B184  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010E388 0010B188  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010E38C 0010B18C  7C 7F 1B 78 */	mr r31, r3
/* 8010E390 0010B190  4B FE B9 F1 */	bl kar_gryakucommon_create_stage_linked_kind16_yaku
/* 8010E394 0010B194  7F E3 FB 78 */	mr r3, r31
/* 8010E398 0010B198  38 80 00 01 */	li r4, 0x1
/* 8010E39C 0010B19C  4B FE B9 E5 */	bl kar_gryakucommon_create_stage_linked_kind16_yaku
/* 8010E3A0 0010B1A0  7F E3 FB 78 */	mr r3, r31
/* 8010E3A4 0010B1A4  38 80 00 02 */	li r4, 0x2
/* 8010E3A8 0010B1A8  4B FE B9 D9 */	bl kar_gryakucommon_create_stage_linked_kind16_yaku
/* 8010E3AC 0010B1AC  7F E3 FB 78 */	mr r3, r31
/* 8010E3B0 0010B1B0  38 80 00 03 */	li r4, 0x3
/* 8010E3B4 0010B1B4  4B FE B9 CD */	bl kar_gryakucommon_create_stage_linked_kind16_yaku
/* 8010E3B8 0010B1B8  7F E3 FB 78 */	mr r3, r31
/* 8010E3BC 0010B1BC  38 80 00 04 */	li r4, 0x4
/* 8010E3C0 0010B1C0  4B FE B9 C1 */	bl kar_gryakucommon_create_stage_linked_kind16_yaku
/* 8010E3C4 0010B1C4  7F E3 FB 78 */	mr r3, r31
/* 8010E3C8 0010B1C8  38 80 00 05 */	li r4, 0x5
/* 8010E3CC 0010B1CC  4B FE B9 B5 */	bl kar_gryakucommon_create_stage_linked_kind16_yaku
/* 8010E3D0 0010B1D0  7F E3 FB 78 */	mr r3, r31
/* 8010E3D4 0010B1D4  38 80 00 06 */	li r4, 0x6
/* 8010E3D8 0010B1D8  4B FE B9 A9 */	bl kar_gryakucommon_create_stage_linked_kind16_yaku
/* 8010E3DC 0010B1DC  7F E3 FB 78 */	mr r3, r31
/* 8010E3E0 0010B1E0  38 80 00 07 */	li r4, 0x7
/* 8010E3E4 0010B1E4  4B FE C3 25 */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010E3E8 0010B1E8  7F E3 FB 78 */	mr r3, r31
/* 8010E3EC 0010B1EC  38 80 00 08 */	li r4, 0x8
/* 8010E3F0 0010B1F0  4B FE E4 59 */	bl kar_gryakuinvisibleball_create_stage_linked_invisibleball_yaku
/* 8010E3F4 0010B1F4  7F E3 FB 78 */	mr r3, r31
/* 8010E3F8 0010B1F8  38 80 00 09 */	li r4, 0x9
/* 8010E3FC 0010B1FC  4B FF 24 01 */	bl kar_gryakulighttunnel_create_stage_linked_kind52_pillar
/* 8010E400 0010B200  7F E3 FB 78 */	mr r3, r31
/* 8010E404 0010B204  38 80 00 0A */	li r4, 0xa
/* 8010E408 0010B208  4B FF 23 F5 */	bl kar_gryakulighttunnel_create_stage_linked_kind52_pillar
/* 8010E40C 0010B20C  7F E3 FB 78 */	mr r3, r31
/* 8010E410 0010B210  38 80 00 0B */	li r4, 0xb
/* 8010E414 0010B214  4B FF 23 E9 */	bl kar_gryakulighttunnel_create_stage_linked_kind52_pillar
/* 8010E418 0010B218  7F E3 FB 78 */	mr r3, r31
/* 8010E41C 0010B21C  38 80 00 0C */	li r4, 0xc
/* 8010E420 0010B220  4B FF 23 DD */	bl kar_gryakulighttunnel_create_stage_linked_kind52_pillar
/* 8010E424 0010B224  7F E3 FB 78 */	mr r3, r31
/* 8010E428 0010B228  38 80 00 0D */	li r4, 0xd
/* 8010E42C 0010B22C  4B FF 23 D1 */	bl kar_gryakulighttunnel_create_stage_linked_kind52_pillar
/* 8010E430 0010B230  7F E3 FB 78 */	mr r3, r31
/* 8010E434 0010B234  38 80 00 0E */	li r4, 0xe
/* 8010E438 0010B238  4B FF 23 C5 */	bl kar_gryakulighttunnel_create_stage_linked_kind52_pillar
/* 8010E43C 0010B23C  7F E3 FB 78 */	mr r3, r31
/* 8010E440 0010B240  38 80 00 0F */	li r4, 0xf
/* 8010E444 0010B244  4B FF 23 B9 */	bl kar_gryakulighttunnel_create_stage_linked_kind52_pillar
/* 8010E448 0010B248  7F E3 FB 78 */	mr r3, r31
/* 8010E44C 0010B24C  38 80 00 10 */	li r4, 0x10
/* 8010E450 0010B250  4B FF 2B 65 */	bl kar_gryakupillar_create_stage_linked_kind53_pillar_controller
/* 8010E454 0010B254  7F E3 FB 78 */	mr r3, r31
/* 8010E458 0010B258  38 80 00 11 */	li r4, 0x11
/* 8010E45C 0010B25C  4B FF 57 FD */	bl kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor
/* 8010E460 0010B260  7F E3 FB 78 */	mr r3, r31
/* 8010E464 0010B264  38 80 00 12 */	li r4, 0x12
/* 8010E468 0010B268  4B FF 57 F1 */	bl kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor
/* 8010E46C 0010B26C  7F E3 FB 78 */	mr r3, r31
/* 8010E470 0010B270  38 80 00 13 */	li r4, 0x13
/* 8010E474 0010B274  4B FF 57 E5 */	bl kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor
/* 8010E478 0010B278  7F E3 FB 78 */	mr r3, r31
/* 8010E47C 0010B27C  38 80 00 14 */	li r4, 0x14
/* 8010E480 0010B280  4B FF 57 D9 */	bl kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor
/* 8010E484 0010B284  7F E3 FB 78 */	mr r3, r31
/* 8010E488 0010B288  38 80 00 15 */	li r4, 0x15
/* 8010E48C 0010B28C  4B FF 57 CD */	bl kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor
/* 8010E490 0010B290  7F E3 FB 78 */	mr r3, r31
/* 8010E494 0010B294  38 80 00 16 */	li r4, 0x16
/* 8010E498 0010B298  4B FF 57 C1 */	bl kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor
/* 8010E49C 0010B29C  7F E3 FB 78 */	mr r3, r31
/* 8010E4A0 0010B2A0  38 80 00 17 */	li r4, 0x17
/* 8010E4A4 0010B2A4  4B FF 57 B5 */	bl kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor
/* 8010E4A8 0010B2A8  7F E3 FB 78 */	mr r3, r31
/* 8010E4AC 0010B2AC  38 80 00 18 */	li r4, 0x18
/* 8010E4B0 0010B2B0  4B FF 57 A9 */	bl kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor
/* 8010E4B4 0010B2B4  7F E3 FB 78 */	mr r3, r31
/* 8010E4B8 0010B2B8  38 80 00 19 */	li r4, 0x19
/* 8010E4BC 0010B2BC  4B FF 57 9D */	bl kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor
/* 8010E4C0 0010B2C0  7F E3 FB 78 */	mr r3, r31
/* 8010E4C4 0010B2C4  38 80 00 1A */	li r4, 0x1a
/* 8010E4C8 0010B2C8  4B FF 57 91 */	bl kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor
/* 8010E4CC 0010B2CC  7F E3 FB 78 */	mr r3, r31
/* 8010E4D0 0010B2D0  38 80 00 1B */	li r4, 0x1b
/* 8010E4D4 0010B2D4  4B FF 57 85 */	bl kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor
/* 8010E4D8 0010B2D8  7F E3 FB 78 */	mr r3, r31
/* 8010E4DC 0010B2DC  38 80 00 1C */	li r4, 0x1c
/* 8010E4E0 0010B2E0  4B FF 57 79 */	bl kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor
/* 8010E4E4 0010B2E4  7F E3 FB 78 */	mr r3, r31
/* 8010E4E8 0010B2E8  38 80 00 1D */	li r4, 0x1d
/* 8010E4EC 0010B2EC  4B FF 57 6D */	bl kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor
/* 8010E4F0 0010B2F0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010E4F4 0010B2F4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010E4F8 0010B2F8  7C 08 03 A6 */	mtlr r0
/* 8010E4FC 0010B2FC  38 21 00 10 */	addi r1, r1, 0x10
/* 8010E500 0010B300  4E 80 00 20 */	blr
.endfn kar_grdesert1_create_main_stage_yaku_objects

# .text:0x21C | 0x8010E504 | size: 0x34
.fn kar_grdesert1_trigger_invisibleball_by_stage_index, global
/* 8010E504 0010B304  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010E508 0010B308  7C 08 02 A6 */	mflr r0
/* 8010E50C 0010B30C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010E510 0010B310  1C 04 00 48 */	mulli r0, r4, 0x48
/* 8010E514 0010B314  80 8D 05 EC */	lwz r4, lbl_805DD6CC@sda21(r0)
/* 8010E518 0010B318  7C A4 02 14 */	add r5, r4, r0
/* 8010E51C 0010B31C  7C 64 1B 78 */	mr r4, r3
/* 8010E520 0010B320  80 65 02 18 */	lwz r3, 0x218(r5)
/* 8010E524 0010B324  4B FE E6 91 */	bl kar_gryakuinvisibleball_trigger_hidden_collision_state
/* 8010E528 0010B328  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010E52C 0010B32C  7C 08 03 A6 */	mtlr r0
/* 8010E530 0010B330  38 21 00 10 */	addi r1, r1, 0x10
/* 8010E534 0010B334  4E 80 00 20 */	blr
.endfn kar_grdesert1_trigger_invisibleball_by_stage_index

# .text:0x250 | 0x8010E538 | size: 0x34
.fn kar_grdesert1_trigger_pillar_controller_by_stage_index, global
/* 8010E538 0010B338  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010E53C 0010B33C  7C 08 02 A6 */	mflr r0
/* 8010E540 0010B340  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010E544 0010B344  1C 04 00 48 */	mulli r0, r4, 0x48
/* 8010E548 0010B348  80 8D 05 EC */	lwz r4, lbl_805DD6CC@sda21(r0)
/* 8010E54C 0010B34C  7C A4 02 14 */	add r5, r4, r0
/* 8010E550 0010B350  7C 64 1B 78 */	mr r4, r3
/* 8010E554 0010B354  80 65 02 18 */	lwz r3, 0x218(r5)
/* 8010E558 0010B358  4B FF 2B F1 */	bl kar_gryakupillar_trigger_kind53_random_child_pillars
/* 8010E55C 0010B35C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010E560 0010B360  7C 08 03 A6 */	mtlr r0
/* 8010E564 0010B364  38 21 00 10 */	addi r1, r1, 0x10
/* 8010E568 0010B368  4E 80 00 20 */	blr
.endfn kar_grdesert1_trigger_pillar_controller_by_stage_index

# .text:0x284 | 0x8010E56C | size: 0x44
.fn kar_grdesert1_lookup_script_entry_value, global
/* 8010E56C 0010B36C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010E570 0010B370  7C 08 02 A6 */	mflr r0
/* 8010E574 0010B374  7C 64 1B 78 */	mr r4, r3
/* 8010E578 0010B378  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010E57C 0010B37C  80 AD 05 EC */	lwz r5, lbl_805DD6CC@sda21(r0)
/* 8010E580 0010B380  80 65 00 08 */	lwz r3, 0x8(r5)
/* 8010E584 0010B384  80 63 00 08 */	lwz r3, 0x8(r3)
/* 8010E588 0010B388  80 63 00 04 */	lwz r3, 0x4(r3)
/* 8010E58C 0010B38C  28 03 00 00 */	cmplwi r3, 0x0
/* 8010E590 0010B390  41 82 00 0C */	beq .L_8010E59C
/* 8010E594 0010B394  4B FE A5 E1 */	bl kar_gryakucommon_lookup_script_entry_value
/* 8010E598 0010B398  48 00 00 08 */	b .L_8010E5A0
.L_8010E59C:
/* 8010E59C 0010B39C  38 60 00 00 */	li r3, 0x0
.L_8010E5A0:
/* 8010E5A0 0010B3A0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010E5A4 0010B3A4  7C 08 03 A6 */	mtlr r0
/* 8010E5A8 0010B3A8  38 21 00 10 */	addi r1, r1, 0x10
/* 8010E5AC 0010B3AC  4E 80 00 20 */	blr
.endfn kar_grdesert1_lookup_script_entry_value

# .text:0x2C8 | 0x8010E5B0 | size: 0x2C
.fn kar_grdesert1_init_recovery_area_switch_group, global
/* 8010E5B0 0010B3B0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010E5B4 0010B3B4  7C 08 02 A6 */	mflr r0
/* 8010E5B8 0010B3B8  38 8D 92 80 */	li r4, lbl_805D6360@sda21
/* 8010E5BC 0010B3BC  38 A0 00 01 */	li r5, 0x1
/* 8010E5C0 0010B3C0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010E5C4 0010B3C4  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8010E5C8 0010B3C8  4B FD 9F E1 */	bl kar_grswitch__800e85a8
/* 8010E5CC 0010B3CC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010E5D0 0010B3D0  7C 08 03 A6 */	mtlr r0
/* 8010E5D4 0010B3D4  38 21 00 10 */	addi r1, r1, 0x10
/* 8010E5D8 0010B3D8  4E 80 00 20 */	blr
.endfn kar_grdesert1_init_recovery_area_switch_group

# .text:0x2F4 | 0x8010E5DC | size: 0x18C
.fn kar_grdesert1_create_recovery_zone_stage_yaku_objects, global
/* 8010E5DC 0010B3DC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010E5E0 0010B3E0  7C 08 02 A6 */	mflr r0
/* 8010E5E4 0010B3E4  38 80 00 00 */	li r4, 0x0
/* 8010E5E8 0010B3E8  38 A0 00 00 */	li r5, 0x0
/* 8010E5EC 0010B3EC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010E5F0 0010B3F0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010E5F4 0010B3F4  7C 7F 1B 78 */	mr r31, r3
/* 8010E5F8 0010B3F8  4B FE CF D9 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010E5FC 0010B3FC  7F E3 FB 78 */	mr r3, r31
/* 8010E600 0010B400  38 80 00 01 */	li r4, 0x1
/* 8010E604 0010B404  38 A0 00 00 */	li r5, 0x0
/* 8010E608 0010B408  4B FE CF C9 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010E60C 0010B40C  7F E3 FB 78 */	mr r3, r31
/* 8010E610 0010B410  38 80 00 02 */	li r4, 0x2
/* 8010E614 0010B414  38 A0 00 00 */	li r5, 0x0
/* 8010E618 0010B418  4B FE CF B9 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010E61C 0010B41C  7F E3 FB 78 */	mr r3, r31
/* 8010E620 0010B420  38 80 00 03 */	li r4, 0x3
/* 8010E624 0010B424  38 A0 00 00 */	li r5, 0x0
/* 8010E628 0010B428  4B FE CF A9 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010E62C 0010B42C  7F E3 FB 78 */	mr r3, r31
/* 8010E630 0010B430  38 80 00 04 */	li r4, 0x4
/* 8010E634 0010B434  38 A0 00 00 */	li r5, 0x0
/* 8010E638 0010B438  4B FE CF 99 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010E63C 0010B43C  7F E3 FB 78 */	mr r3, r31
/* 8010E640 0010B440  38 80 00 05 */	li r4, 0x5
/* 8010E644 0010B444  38 A0 00 00 */	li r5, 0x0
/* 8010E648 0010B448  4B FE CF 89 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010E64C 0010B44C  7F E3 FB 78 */	mr r3, r31
/* 8010E650 0010B450  38 80 00 06 */	li r4, 0x6
/* 8010E654 0010B454  38 A0 00 00 */	li r5, 0x0
/* 8010E658 0010B458  4B FE CF 79 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010E65C 0010B45C  7F E3 FB 78 */	mr r3, r31
/* 8010E660 0010B460  38 80 00 07 */	li r4, 0x7
/* 8010E664 0010B464  38 A0 00 00 */	li r5, 0x0
/* 8010E668 0010B468  4B FE CF 69 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010E66C 0010B46C  7F E3 FB 78 */	mr r3, r31
/* 8010E670 0010B470  38 80 00 08 */	li r4, 0x8
/* 8010E674 0010B474  38 A0 00 00 */	li r5, 0x0
/* 8010E678 0010B478  4B FE CF 59 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010E67C 0010B47C  7F E3 FB 78 */	mr r3, r31
/* 8010E680 0010B480  38 80 00 09 */	li r4, 0x9
/* 8010E684 0010B484  38 A0 00 00 */	li r5, 0x0
/* 8010E688 0010B488  4B FE CF 49 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010E68C 0010B48C  7F E3 FB 78 */	mr r3, r31
/* 8010E690 0010B490  38 80 00 0A */	li r4, 0xa
/* 8010E694 0010B494  38 A0 00 00 */	li r5, 0x0
/* 8010E698 0010B498  4B FE CF 39 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010E69C 0010B49C  7F E3 FB 78 */	mr r3, r31
/* 8010E6A0 0010B4A0  38 80 00 0B */	li r4, 0xb
/* 8010E6A4 0010B4A4  38 A0 00 00 */	li r5, 0x0
/* 8010E6A8 0010B4A8  4B FE CF 29 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010E6AC 0010B4AC  7F E3 FB 78 */	mr r3, r31
/* 8010E6B0 0010B4B0  38 80 00 0C */	li r4, 0xc
/* 8010E6B4 0010B4B4  38 A0 00 00 */	li r5, 0x0
/* 8010E6B8 0010B4B8  4B FE CF 19 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010E6BC 0010B4BC  7F E3 FB 78 */	mr r3, r31
/* 8010E6C0 0010B4C0  38 80 00 0D */	li r4, 0xd
/* 8010E6C4 0010B4C4  38 A0 00 00 */	li r5, 0x0
/* 8010E6C8 0010B4C8  4B FE CF 09 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010E6CC 0010B4CC  7F E3 FB 78 */	mr r3, r31
/* 8010E6D0 0010B4D0  38 80 00 0E */	li r4, 0xe
/* 8010E6D4 0010B4D4  38 A0 00 00 */	li r5, 0x0
/* 8010E6D8 0010B4D8  4B FE CE F9 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010E6DC 0010B4DC  7F E3 FB 78 */	mr r3, r31
/* 8010E6E0 0010B4E0  38 80 00 0F */	li r4, 0xf
/* 8010E6E4 0010B4E4  38 A0 00 00 */	li r5, 0x0
/* 8010E6E8 0010B4E8  4B FE CE E9 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010E6EC 0010B4EC  7F E3 FB 78 */	mr r3, r31
/* 8010E6F0 0010B4F0  38 80 00 10 */	li r4, 0x10
/* 8010E6F4 0010B4F4  38 A0 00 00 */	li r5, 0x0
/* 8010E6F8 0010B4F8  4B FE CE D9 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010E6FC 0010B4FC  7F E3 FB 78 */	mr r3, r31
/* 8010E700 0010B500  38 80 00 11 */	li r4, 0x11
/* 8010E704 0010B504  38 A0 00 00 */	li r5, 0x0
/* 8010E708 0010B508  4B FE CE C9 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010E70C 0010B50C  7F E3 FB 78 */	mr r3, r31
/* 8010E710 0010B510  38 80 00 12 */	li r4, 0x12
/* 8010E714 0010B514  4B FE D8 4D */	bl kar_gryakurecoveryzone_create_stage_linked_kind42_ground_group_yaku
/* 8010E718 0010B518  7F E3 FB 78 */	mr r3, r31
/* 8010E71C 0010B51C  38 80 00 13 */	li r4, 0x13
/* 8010E720 0010B520  4B FE DB B1 */	bl kar_gryakurotjumphill_create_stage_linked_rotjumphill_yaku
/* 8010E724 0010B524  7F E3 FB 78 */	mr r3, r31
/* 8010E728 0010B528  38 80 00 14 */	li r4, 0x14
/* 8010E72C 0010B52C  4B FE DB A5 */	bl kar_gryakurotjumphill_create_stage_linked_rotjumphill_yaku
/* 8010E730 0010B530  7F E3 FB 78 */	mr r3, r31
/* 8010E734 0010B534  38 80 00 15 */	li r4, 0x15
/* 8010E738 0010B538  4B FE E6 0D */	bl kar_gryakurisingcube_create_stage_linked_cube_yaku
/* 8010E73C 0010B53C  7F E3 FB 78 */	mr r3, r31
/* 8010E740 0010B540  38 80 00 16 */	li r4, 0x16
/* 8010E744 0010B544  4B FE BF C5 */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010E748 0010B548  7F E3 FB 78 */	mr r3, r31
/* 8010E74C 0010B54C  38 80 00 17 */	li r4, 0x17
/* 8010E750 0010B550  4B FE BF B9 */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010E754 0010B554  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010E758 0010B558  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010E75C 0010B55C  7C 08 03 A6 */	mtlr r0
/* 8010E760 0010B560  38 21 00 10 */	addi r1, r1, 0x10
/* 8010E764 0010B564  4E 80 00 20 */	blr
.endfn kar_grdesert1_create_recovery_zone_stage_yaku_objects

# .text:0x480 | 0x8010E768 | size: 0x30
.fn kar_grdesert1_trigger_risingcube_by_stage_index, global
/* 8010E768 0010B568  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010E76C 0010B56C  7C 08 02 A6 */	mflr r0
/* 8010E770 0010B570  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010E774 0010B574  1C 04 00 48 */	mulli r0, r4, 0x48
/* 8010E778 0010B578  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 8010E77C 0010B57C  7C 63 02 14 */	add r3, r3, r0
/* 8010E780 0010B580  80 63 02 18 */	lwz r3, 0x218(r3)
/* 8010E784 0010B584  4B FE F1 0D */	bl kar_gryakurisingcube_trigger_cube_state_toggle
/* 8010E788 0010B588  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010E78C 0010B58C  7C 08 03 A6 */	mtlr r0
/* 8010E790 0010B590  38 21 00 10 */	addi r1, r1, 0x10
/* 8010E794 0010B594  4E 80 00 20 */	blr
.endfn kar_grdesert1_trigger_risingcube_by_stage_index
