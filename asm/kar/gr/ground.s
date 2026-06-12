.include "macros.inc"
.file "ground.c"

# 0x800CE270..0x800CE7A0 | size: 0x530
.text
.balign 4

# .text:0x0 | 0x800CE270 | size: 0x2C8
.fn kar_ground__800ce270, global
/* 800CE270 000CB070  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800CE274 000CB074  7C 08 02 A6 */	mflr r0
/* 800CE278 000CB078  90 01 00 24 */	stw r0, 0x24(r1)
/* 800CE27C 000CB07C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800CE280 000CB080  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800CE284 000CB084  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800CE288 000CB088  7C 7D 1B 78 */	mr r29, r3
/* 800CE28C 000CB08C  93 81 00 10 */	stw r28, 0x10(r1)
/* 800CE290 000CB090  80 0D 05 EC */	lwz r0, lbl_805DD6CC@sda21(r0)
/* 800CE294 000CB094  28 00 00 00 */	cmplwi r0, 0x0
/* 800CE298 000CB098  41 82 00 1C */	beq .L_800CE2B4
/* 800CE29C 000CB09C  3C 60 80 4A */	lis r3, kar_src_ground_804a23e8@ha
/* 800CE2A0 000CB0A0  3C A0 80 4A */	lis r5, lbl_804A23F4@ha
/* 800CE2A4 000CB0A4  38 63 23 E8 */	addi r3, r3, kar_src_ground_804a23e8@l
/* 800CE2A8 000CB0A8  38 80 00 B4 */	li r4, 0xb4
/* 800CE2AC 000CB0AC  38 A5 23 F4 */	addi r5, r5, lbl_804A23F4@l
/* 800CE2B0 000CB0B0  48 35 A2 09 */	bl __assert
.L_800CE2B4:
/* 800CE2B4 000CB0B4  48 19 3C 19 */	bl fn_80261ECC
/* 800CE2B8 000CB0B8  48 19 44 CD */	bl fn_80262784
/* 800CE2BC 000CB0BC  2C 03 00 00 */	cmpwi r3, 0x0
/* 800CE2C0 000CB0C0  41 82 00 08 */	beq .L_800CE2C8
/* 800CE2C4 000CB0C4  48 02 61 49 */	bl kar_gryaku_load_yaku_assets
.L_800CE2C8:
/* 800CE2C8 000CB0C8  38 60 00 0E */	li r3, 0xe
/* 800CE2CC 000CB0CC  38 80 00 07 */	li r4, 0x7
/* 800CE2D0 000CB0D0  38 A0 00 00 */	li r5, 0x0
/* 800CE2D4 000CB0D4  48 35 AC 55 */	bl HSD_GObjCreate
/* 800CE2D8 000CB0D8  3C 80 80 0E */	lis r4, kar_grcoll__near_800d81e4@ha
/* 800CE2DC 000CB0DC  38 A0 00 01 */	li r5, 0x1
/* 800CE2E0 000CB0E0  38 84 81 E4 */	addi r4, r4, kar_grcoll__near_800d81e4@l
/* 800CE2E4 000CB0E4  7C 7F 1B 78 */	mr r31, r3
/* 800CE2E8 000CB0E8  38 C0 00 01 */	li r6, 0x1
/* 800CE2EC 000CB0EC  48 35 B3 A5 */	bl HSD_GObjGXLink
/* 800CE2F0 000CB0F0  3C 60 80 55 */	lis r3, lbl_80557558@ha
/* 800CE2F4 000CB0F4  38 63 75 58 */	addi r3, r3, lbl_80557558@l
/* 800CE2F8 000CB0F8  48 34 9D ED */	bl HSD_ObjAlloc
/* 800CE2FC 000CB0FC  7C 7E 1B 78 */	mr r30, r3
/* 800CE300 000CB100  3C 80 80 0D */	lis r4, kar_ground__near_800ce538@ha
/* 800CE304 000CB104  38 A4 E5 38 */	addi r5, r4, kar_ground__near_800ce538@l
/* 800CE308 000CB108  7F E3 FB 78 */	mr r3, r31
/* 800CE30C 000CB10C  38 80 00 0E */	li r4, 0xe
/* 800CE310 000CB110  7F C6 F3 78 */	mr r6, r30
/* 800CE314 000CB114  48 35 B9 F9 */	bl HSD_GObjUserDataLink
/* 800CE318 000CB118  93 CD 05 EC */	stw r30, lbl_805DD6CC@sda21(r0)
/* 800CE31C 000CB11C  7F A3 EB 78 */	mr r3, r29
/* 800CE320 000CB120  48 00 04 81 */	bl kar_grdata__800ce7a0
/* 800CE324 000CB124  83 9F 00 2C */	lwz r28, 0x2c(r31)
/* 800CE328 000CB128  3C 60 80 55 */	lis r3, lbl_80557638@ha
/* 800CE32C 000CB12C  57 A0 10 3A */	slwi r0, r29, 2
/* 800CE330 000CB130  39 00 00 00 */	li r8, 0x0
/* 800CE334 000CB134  93 BC 00 04 */	stw r29, 0x4(r28)
/* 800CE338 000CB138  38 63 76 38 */	addi r3, r3, lbl_80557638@l
/* 800CE33C 000CB13C  38 E0 00 01 */	li r7, 0x1
/* 800CE340 000CB140  38 C0 00 01 */	li r6, 0x1
/* 800CE344 000CB144  7C 03 00 2E */	lwzx r0, r3, r0
/* 800CE348 000CB148  38 7C 08 24 */	addi r3, r28, 0x824
/* 800CE34C 000CB14C  38 80 00 00 */	li r4, 0x0
/* 800CE350 000CB150  38 A0 00 3F */	li r5, 0x3f
/* 800CE354 000CB154  90 1C 00 08 */	stw r0, 0x8(r28)
/* 800CE358 000CB158  93 FC 00 00 */	stw r31, 0x0(r28)
/* 800CE35C 000CB15C  99 1C 07 20 */	stb r8, 0x720(r28)
/* 800CE360 000CB160  99 1C 07 21 */	stb r8, 0x721(r28)
/* 800CE364 000CB164  91 1C 07 24 */	stw r8, 0x724(r28)
/* 800CE368 000CB168  88 1C 07 27 */	lbz r0, 0x727(r28)
/* 800CE36C 000CB16C  50 E0 0F BC */	rlwimi r0, r7, 1, 30, 30
/* 800CE370 000CB170  98 1C 07 27 */	stb r0, 0x727(r28)
/* 800CE374 000CB174  54 07 FF FE */	extrwi r7, r0, 1, 30
/* 800CE378 000CB178  88 1C 07 27 */	lbz r0, 0x727(r28)
/* 800CE37C 000CB17C  50 E0 07 FE */	rlwimi r0, r7, 0, 31, 31
/* 800CE380 000CB180  98 1C 07 27 */	stb r0, 0x727(r28)
/* 800CE384 000CB184  88 1C 07 1C */	lbz r0, 0x71c(r28)
/* 800CE388 000CB188  50 C0 3E 30 */	rlwimi r0, r6, 7, 24, 24
/* 800CE38C 000CB18C  98 1C 07 1C */	stb r0, 0x71c(r28)
/* 800CE390 000CB190  88 1C 07 1C */	lbz r0, 0x71c(r28)
/* 800CE394 000CB194  51 00 36 72 */	rlwimi r0, r8, 6, 25, 25
/* 800CE398 000CB198  98 1C 07 1C */	stb r0, 0x71c(r28)
/* 800CE39C 000CB19C  91 1C 06 FC */	stw r8, 0x6fc(r28)
/* 800CE3A0 000CB1A0  4B F3 4D 61 */	bl memset
/* 800CE3A4 000CB1A4  38 7C 08 63 */	addi r3, r28, 0x863
/* 800CE3A8 000CB1A8  38 80 00 00 */	li r4, 0x0
/* 800CE3AC 000CB1AC  38 A0 00 0D */	li r5, 0xd
/* 800CE3B0 000CB1B0  4B F3 4D 51 */	bl memset
/* 800CE3B4 000CB1B4  48 18 48 51 */	bl kar_itparts_load_item_assets
/* 800CE3B8 000CB1B8  7F C3 F3 78 */	mr r3, r30
/* 800CE3BC 000CB1BC  48 02 41 F9 */	bl kar_grairglider_cleanup_spawned_enemies
/* 800CE3C0 000CB1C0  7F E3 FB 78 */	mr r3, r31
/* 800CE3C4 000CB1C4  48 01 C2 F5 */	bl kar_graudio__near_800ea6b8
/* 800CE3C8 000CB1C8  7F E3 FB 78 */	mr r3, r31
/* 800CE3CC 000CB1CC  48 00 E8 25 */	bl kar_grrough__near_800dcbf0
/* 800CE3D0 000CB1D0  7F E3 FB 78 */	mr r3, r31
/* 800CE3D4 000CB1D4  38 80 00 00 */	li r4, 0x0
/* 800CE3D8 000CB1D8  48 00 D5 01 */	bl kar_grcommon__near_800db8d8
/* 800CE3DC 000CB1DC  7F E3 FB 78 */	mr r3, r31
/* 800CE3E0 000CB1E0  38 80 00 00 */	li r4, 0x0
/* 800CE3E4 000CB1E4  48 00 D8 49 */	bl kar_granim__near_800dbc2c
/* 800CE3E8 000CB1E8  7F C3 F3 78 */	mr r3, r30
/* 800CE3EC 000CB1EC  48 00 7A E9 */	bl kar_grlib2__near_800d5ed4
/* 800CE3F0 000CB1F0  7F C3 F3 78 */	mr r3, r30
/* 800CE3F4 000CB1F4  48 02 0B 11 */	bl kar_grairglider_init_fade_handle
/* 800CE3F8 000CB1F8  7F C3 F3 78 */	mr r3, r30
/* 800CE3FC 000CB1FC  48 00 DB AD */	bl kar_granim__near_800dbfa8
/* 800CE400 000CB200  7F C3 F3 78 */	mr r3, r30
/* 800CE404 000CB204  48 00 A7 95 */	bl kar_grparts__near_800d8b98
/* 800CE408 000CB208  7F C3 F3 78 */	mr r3, r30
/* 800CE40C 000CB20C  48 00 89 C1 */	bl kar_grcoll__800d6dcc
/* 800CE410 000CB210  7F C3 F3 78 */	mr r3, r30
/* 800CE414 000CB214  48 01 B6 B9 */	bl kar_graudio_init_map_zone_fgm
/* 800CE418 000CB218  7F C3 F3 78 */	mr r3, r30
/* 800CE41C 000CB21C  48 01 87 B1 */	bl kar_grairflow_init_stage_zones
/* 800CE420 000CB220  7F C3 F3 78 */	mr r3, r30
/* 800CE424 000CB224  48 01 A1 19 */	bl kar_grconveyer__near_800e853c
/* 800CE428 000CB228  7F C3 F3 78 */	mr r3, r30
/* 800CE42C 000CB22C  48 01 02 E9 */	bl kar_grkdtree_init_course_range_splines
/* 800CE430 000CB230  7F C3 F3 78 */	mr r3, r30
/* 800CE434 000CB234  48 01 A5 29 */	bl kar_grrail__800e895c
/* 800CE438 000CB238  7F C3 F3 78 */	mr r3, r30
/* 800CE43C 000CB23C  48 01 5B 45 */	bl kar_grnullpos_init_stage_null_positions
/* 800CE440 000CB240  7F C3 F3 78 */	mr r3, r30
/* 800CE444 000CB244  48 02 5E 19 */	bl kar_gryaku_init_common_yaku_objects
/* 800CE448 000CB248  7F C3 F3 78 */	mr r3, r30
/* 800CE44C 000CB24C  48 00 FC 9D */	bl kar_grkdtree_init_static_collision_tree
/* 800CE450 000CB250  7F C3 F3 78 */	mr r3, r30
/* 800CE454 000CB254  48 01 6C 19 */	bl kar_grnullpos_init_start_vehicle_positions
/* 800CE458 000CB258  7F C3 F3 78 */	mr r3, r30
/* 800CE45C 000CB25C  48 02 05 29 */	bl kar_grglobaldead_init
/* 800CE460 000CB260  7F C3 F3 78 */	mr r3, r30
/* 800CE464 000CB264  48 01 7E 5D */	bl kar_grdispbbox_init_ground_state
/* 800CE468 000CB268  7F C3 F3 78 */	mr r3, r30
/* 800CE46C 000CB26C  48 00 F5 6D */	bl kar_grzonecover_alloc_cover_records
/* 800CE470 000CB270  7F C3 F3 78 */	mr r3, r30
/* 800CE474 000CB274  48 00 FD B5 */	bl kar_grkdtree_build_ground_spatial_indexes
/* 800CE478 000CB278  3C 80 80 0D */	lis r4, kar_ground__near_800ce5e4@ha
/* 800CE47C 000CB27C  7F E3 FB 78 */	mr r3, r31
/* 800CE480 000CB280  38 84 E5 E4 */	addi r4, r4, kar_ground__near_800ce5e4@l
/* 800CE484 000CB284  38 A0 00 00 */	li r5, 0x0
/* 800CE488 000CB288  48 35 A4 1D */	bl HSD_GObjProcCreate
/* 800CE48C 000CB28C  3C 80 80 0D */	lis r4, kar_ground__near_800ce618@ha
/* 800CE490 000CB290  7F E3 FB 78 */	mr r3, r31
/* 800CE494 000CB294  38 84 E6 18 */	addi r4, r4, kar_ground__near_800ce618@l
/* 800CE498 000CB298  38 A0 00 01 */	li r5, 0x1
/* 800CE49C 000CB29C  48 35 A4 09 */	bl HSD_GObjProcCreate
/* 800CE4A0 000CB2A0  3C 80 80 0D */	lis r4, kar_ground__near_800ce68c@ha
/* 800CE4A4 000CB2A4  7F E3 FB 78 */	mr r3, r31
/* 800CE4A8 000CB2A8  38 84 E6 8C */	addi r4, r4, kar_ground__near_800ce68c@l
/* 800CE4AC 000CB2AC  38 A0 00 04 */	li r5, 0x4
/* 800CE4B0 000CB2B0  48 35 A3 F5 */	bl HSD_GObjProcCreate
/* 800CE4B4 000CB2B4  3C 80 80 0D */	lis r4, fn_800CE6D4@ha
/* 800CE4B8 000CB2B8  7F E3 FB 78 */	mr r3, r31
/* 800CE4BC 000CB2BC  38 84 E6 D4 */	addi r4, r4, fn_800CE6D4@l
/* 800CE4C0 000CB2C0  38 A0 00 15 */	li r5, 0x15
/* 800CE4C4 000CB2C4  48 35 A3 E1 */	bl HSD_GObjProcCreate
/* 800CE4C8 000CB2C8  80 1E 00 04 */	lwz r0, 0x4(r30)
/* 800CE4CC 000CB2CC  3C 60 80 4A */	lis r3, ground_stage_yaku_callback_table@ha
/* 800CE4D0 000CB2D0  38 63 32 2C */	addi r3, r3, ground_stage_yaku_callback_table@l
/* 800CE4D4 000CB2D4  54 00 10 3A */	slwi r0, r0, 2
/* 800CE4D8 000CB2D8  7C 63 00 2E */	lwzx r3, r3, r0
/* 800CE4DC 000CB2DC  81 83 00 00 */	lwz r12, 0x0(r3)
/* 800CE4E0 000CB2E0  28 0C 00 00 */	cmplwi r12, 0x0
/* 800CE4E4 000CB2E4  41 82 00 10 */	beq .L_800CE4F4
/* 800CE4E8 000CB2E8  7F E3 FB 78 */	mr r3, r31
/* 800CE4EC 000CB2EC  7D 89 03 A6 */	mtctr r12
/* 800CE4F0 000CB2F0  4E 80 04 21 */	bctrl
.L_800CE4F4:
/* 800CE4F4 000CB2F4  7F C3 F3 78 */	mr r3, r30
/* 800CE4F8 000CB2F8  48 02 41 3D */	bl kar_grairglider_init_runtime
/* 800CE4FC 000CB2FC  4B F3 BD 55 */	bl fn_8000A250
/* 800CE500 000CB300  2C 03 00 00 */	cmpwi r3, 0x0
/* 800CE504 000CB304  41 82 00 0C */	beq .L_800CE510
/* 800CE508 000CB308  7F C3 F3 78 */	mr r3, r30
/* 800CE50C 000CB30C  48 01 DE 59 */	bl kar_grboxgenerator__near_800ec364
.L_800CE510:
/* 800CE510 000CB310  7F C3 F3 78 */	mr r3, r30
/* 800CE514 000CB314  48 01 F6 75 */	bl kar_greventgenerator_init
/* 800CE518 000CB318  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800CE51C 000CB31C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800CE520 000CB320  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800CE524 000CB324  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800CE528 000CB328  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800CE52C 000CB32C  7C 08 03 A6 */	mtlr r0
/* 800CE530 000CB330  38 21 00 20 */	addi r1, r1, 0x20
/* 800CE534 000CB334  4E 80 00 20 */	blr
.endfn kar_ground__800ce270

# .text:0x2C8 | 0x800CE538 | size: 0xAC
.fn kar_ground__near_800ce538, global
/* 800CE538 000CB338  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800CE53C 000CB33C  7C 08 02 A6 */	mflr r0
/* 800CE540 000CB340  90 01 00 14 */	stw r0, 0x14(r1)
/* 800CE544 000CB344  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800CE548 000CB348  7C 7F 1B 78 */	mr r31, r3
/* 800CE54C 000CB34C  48 01 AA 85 */	bl kar_grrail__near_800e8fd0
/* 800CE550 000CB350  7F E3 FB 78 */	mr r3, r31
/* 800CE554 000CB354  48 01 B8 4D */	bl kar_graudio_update_map_zone_fgm
/* 800CE558 000CB358  7F E3 FB 78 */	mr r3, r31
/* 800CE55C 000CB35C  48 00 FA D9 */	bl kar_grzonecover_destroy_cover_records
/* 800CE560 000CB360  7F E3 FB 78 */	mr r3, r31
/* 800CE564 000CB364  48 01 7D F9 */	bl kar_grdispbbox_destroy_ground_state
/* 800CE568 000CB368  7F E3 FB 78 */	mr r3, r31
/* 800CE56C 000CB36C  48 02 04 F1 */	bl kar_grglobaldead_destroy
/* 800CE570 000CB370  7F E3 FB 78 */	mr r3, r31
/* 800CE574 000CB374  48 01 6C 69 */	bl kar_grnullpos_destroy
/* 800CE578 000CB378  7F E3 FB 78 */	mr r3, r31
/* 800CE57C 000CB37C  48 01 01 CD */	bl kar_grkdtree_destroy_course_range_splines
/* 800CE580 000CB380  7F E3 FB 78 */	mr r3, r31
/* 800CE584 000CB384  48 00 FC 25 */	bl kar_grkdtree_destroy_static_collision_tree
/* 800CE588 000CB388  7F E3 FB 78 */	mr r3, r31
/* 800CE58C 000CB38C  48 02 5E 11 */	bl kar_gryaku_destroy_all_common_yaku_objects
/* 800CE590 000CB390  7F E3 FB 78 */	mr r3, r31
/* 800CE594 000CB394  48 00 8A CD */	bl kar_grcoll__near_800d7060
/* 800CE598 000CB398  7F E3 FB 78 */	mr r3, r31
/* 800CE59C 000CB39C  48 00 A6 8D */	bl kar_grparts__near_800d8c28
/* 800CE5A0 000CB3A0  7F E3 FB 78 */	mr r3, r31
/* 800CE5A4 000CB3A4  48 00 79 79 */	bl kar_grlib2__near_800d5f1c
/* 800CE5A8 000CB3A8  7F E3 FB 78 */	mr r3, r31
/* 800CE5AC 000CB3AC  48 00 DB 99 */	bl kar_granim__near_800dc144
/* 800CE5B0 000CB3B0  7F E3 FB 78 */	mr r3, r31
/* 800CE5B4 000CB3B4  48 02 09 FD */	bl kar_grairglider_destroy_fade_handle
/* 800CE5B8 000CB3B8  3C 60 80 55 */	lis r3, lbl_80557558@ha
/* 800CE5BC 000CB3BC  7F E4 FB 78 */	mr r4, r31
/* 800CE5C0 000CB3C0  38 63 75 58 */	addi r3, r3, lbl_80557558@l
/* 800CE5C4 000CB3C4  48 34 9C 71 */	bl HSD_ObjFree
/* 800CE5C8 000CB3C8  38 00 00 00 */	li r0, 0x0
/* 800CE5CC 000CB3CC  90 0D 05 EC */	stw r0, lbl_805DD6CC@sda21(r0)
/* 800CE5D0 000CB3D0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800CE5D4 000CB3D4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800CE5D8 000CB3D8  7C 08 03 A6 */	mtlr r0
/* 800CE5DC 000CB3DC  38 21 00 10 */	addi r1, r1, 0x10
/* 800CE5E0 000CB3E0  4E 80 00 20 */	blr
.endfn kar_ground__near_800ce538

# .text:0x374 | 0x800CE5E4 | size: 0x34
.fn kar_ground__near_800ce5e4, global
/* 800CE5E4 000CB3E4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800CE5E8 000CB3E8  7C 08 02 A6 */	mflr r0
/* 800CE5EC 000CB3EC  38 80 00 01 */	li r4, 0x1
/* 800CE5F0 000CB3F0  90 01 00 14 */	stw r0, 0x14(r1)
/* 800CE5F4 000CB3F4  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800CE5F8 000CB3F8  88 03 07 1C */	lbz r0, 0x71c(r3)
/* 800CE5FC 000CB3FC  50 80 3E 30 */	rlwimi r0, r4, 7, 24, 24
/* 800CE600 000CB400  98 03 07 1C */	stb r0, 0x71c(r3)
/* 800CE604 000CB404  4B FD B2 DD */	bl kar_dbmapgravity__near_800a98e0
/* 800CE608 000CB408  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800CE60C 000CB40C  7C 08 03 A6 */	mtlr r0
/* 800CE610 000CB410  38 21 00 10 */	addi r1, r1, 0x10
/* 800CE614 000CB414  4E 80 00 20 */	blr
.endfn kar_ground__near_800ce5e4

# .text:0x3A8 | 0x800CE618 | size: 0x74
.fn kar_ground__near_800ce618, global
/* 800CE618 000CB418  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800CE61C 000CB41C  7C 08 02 A6 */	mflr r0
/* 800CE620 000CB420  90 01 00 14 */	stw r0, 0x14(r1)
/* 800CE624 000CB424  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800CE628 000CB428  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800CE62C 000CB42C  7C 7E 1B 78 */	mr r30, r3
/* 800CE630 000CB430  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800CE634 000CB434  48 00 D6 E5 */	bl kar_granim__near_800dbd18
/* 800CE638 000CB438  80 7F 00 F4 */	lwz r3, 0xf4(r31)
/* 800CE63C 000CB43C  48 33 C0 11 */	bl HSD_JObjAnimAll
/* 800CE640 000CB440  7F E3 FB 78 */	mr r3, r31
/* 800CE644 000CB444  48 00 DF FD */	bl kar_granim__near_800dc640
/* 800CE648 000CB448  80 1F 00 04 */	lwz r0, 0x4(r31)
/* 800CE64C 000CB44C  3C 60 80 4A */	lis r3, ground_stage_yaku_callback_table@ha
/* 800CE650 000CB450  38 63 32 2C */	addi r3, r3, ground_stage_yaku_callback_table@l
/* 800CE654 000CB454  54 00 10 3A */	slwi r0, r0, 2
/* 800CE658 000CB458  7C 63 00 2E */	lwzx r3, r3, r0
/* 800CE65C 000CB45C  81 83 00 08 */	lwz r12, 0x8(r3)
/* 800CE660 000CB460  28 0C 00 00 */	cmplwi r12, 0x0
/* 800CE664 000CB464  41 82 00 10 */	beq .L_800CE674
/* 800CE668 000CB468  7F C3 F3 78 */	mr r3, r30
/* 800CE66C 000CB46C  7D 89 03 A6 */	mtctr r12
/* 800CE670 000CB470  4E 80 04 21 */	bctrl
.L_800CE674:
/* 800CE674 000CB474  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800CE678 000CB478  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800CE67C 000CB47C  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800CE680 000CB480  7C 08 03 A6 */	mtlr r0
/* 800CE684 000CB484  38 21 00 10 */	addi r1, r1, 0x10
/* 800CE688 000CB488  4E 80 00 20 */	blr
.endfn kar_ground__near_800ce618

# .text:0x41C | 0x800CE68C | size: 0x48
.fn kar_ground__near_800ce68c, global
/* 800CE68C 000CB48C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800CE690 000CB490  7C 08 02 A6 */	mflr r0
/* 800CE694 000CB494  90 01 00 14 */	stw r0, 0x14(r1)
/* 800CE698 000CB498  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800CE69C 000CB49C  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800CE6A0 000CB4A0  7F E3 FB 78 */	mr r3, r31
/* 800CE6A4 000CB4A4  48 00 90 D9 */	bl kar_grcoll__near_800d777c
/* 800CE6A8 000CB4A8  7F E3 FB 78 */	mr r3, r31
/* 800CE6AC 000CB4AC  48 01 86 69 */	bl kar_grairflow_step_zone_animation
/* 800CE6B0 000CB4B0  7F E3 FB 78 */	mr r3, r31
/* 800CE6B4 000CB4B4  48 01 A1 D5 */	bl kar_grswitch__near_800e8888
/* 800CE6B8 000CB4B8  7F E3 FB 78 */	mr r3, r31
/* 800CE6BC 000CB4BC  48 01 A7 61 */	bl kar_grrail__near_800e8e1c
/* 800CE6C0 000CB4C0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800CE6C4 000CB4C4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800CE6C8 000CB4C8  7C 08 03 A6 */	mtlr r0
/* 800CE6CC 000CB4CC  38 21 00 10 */	addi r1, r1, 0x10
/* 800CE6D0 000CB4D0  4E 80 00 20 */	blr
.endfn kar_ground__near_800ce68c

# .text:0x464 | 0x800CE6D4 | size: 0x4
.fn fn_800CE6D4, global
/* 800CE6D4 000CB4D4  4E 80 00 20 */	blr
.endfn fn_800CE6D4

# .text:0x468 | 0x800CE6D8 | size: 0x7C
.fn kar_ground__near_800ce6d8, global
/* 800CE6D8 000CB4D8  38 00 00 00 */	li r0, 0x0
/* 800CE6DC 000CB4DC  3C 60 80 55 */	lis r3, lbl_80557638@ha
/* 800CE6E0 000CB4E0  94 03 76 38 */	stwu r0, lbl_80557638@l(r3)
/* 800CE6E4 000CB4E4  90 03 00 04 */	stw r0, 0x4(r3)
/* 800CE6E8 000CB4E8  90 03 00 08 */	stw r0, 0x8(r3)
/* 800CE6EC 000CB4EC  90 03 00 0C */	stw r0, 0xc(r3)
/* 800CE6F0 000CB4F0  90 03 00 10 */	stw r0, 0x10(r3)
/* 800CE6F4 000CB4F4  90 03 00 14 */	stw r0, 0x14(r3)
/* 800CE6F8 000CB4F8  90 03 00 18 */	stw r0, 0x18(r3)
/* 800CE6FC 000CB4FC  90 03 00 1C */	stw r0, 0x1c(r3)
/* 800CE700 000CB500  90 03 00 20 */	stw r0, 0x20(r3)
/* 800CE704 000CB504  90 03 00 24 */	stw r0, 0x24(r3)
/* 800CE708 000CB508  90 03 00 28 */	stw r0, 0x28(r3)
/* 800CE70C 000CB50C  90 03 00 2C */	stw r0, 0x2c(r3)
/* 800CE710 000CB510  90 03 00 30 */	stw r0, 0x30(r3)
/* 800CE714 000CB514  90 03 00 34 */	stw r0, 0x34(r3)
/* 800CE718 000CB518  90 03 00 38 */	stw r0, 0x38(r3)
/* 800CE71C 000CB51C  90 03 00 3C */	stw r0, 0x3c(r3)
/* 800CE720 000CB520  90 03 00 40 */	stw r0, 0x40(r3)
/* 800CE724 000CB524  90 03 00 44 */	stw r0, 0x44(r3)
/* 800CE728 000CB528  90 03 00 48 */	stw r0, 0x48(r3)
/* 800CE72C 000CB52C  90 03 00 4C */	stw r0, 0x4c(r3)
/* 800CE730 000CB530  90 03 00 50 */	stw r0, 0x50(r3)
/* 800CE734 000CB534  90 03 00 54 */	stw r0, 0x54(r3)
/* 800CE738 000CB538  90 03 00 58 */	stw r0, 0x58(r3)
/* 800CE73C 000CB53C  90 03 00 5C */	stw r0, 0x5c(r3)
/* 800CE740 000CB540  90 03 00 60 */	stw r0, 0x60(r3)
/* 800CE744 000CB544  90 03 00 64 */	stw r0, 0x64(r3)
/* 800CE748 000CB548  90 03 00 68 */	stw r0, 0x68(r3)
/* 800CE74C 000CB54C  90 03 00 6C */	stw r0, 0x6c(r3)
/* 800CE750 000CB550  4E 80 00 20 */	blr
.endfn kar_ground__near_800ce6d8

# .text:0x4E4 | 0x800CE754 | size: 0x4C
.fn kar_gr_assets__asset_800ce754, global
/* 800CE754 000CB554  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800CE758 000CB558  7C 08 02 A6 */	mflr r0
/* 800CE75C 000CB55C  3C 80 80 4A */	lis r4, kar_linkfile_grcommon_dat_804a32b0@ha
/* 800CE760 000CB560  3C 60 80 4A */	lis r3, lbl_804A32C0@ha
/* 800CE764 000CB564  90 01 00 14 */	stw r0, 0x14(r1)
/* 800CE768 000CB568  38 C3 32 C0 */	addi r6, r3, lbl_804A32C0@l
/* 800CE76C 000CB56C  38 84 32 B0 */	addi r4, r4, kar_linkfile_grcommon_dat_804a32b0@l
/* 800CE770 000CB570  38 A1 00 08 */	addi r5, r1, 0x8
/* 800CE774 000CB574  38 60 00 00 */	li r3, 0x0
/* 800CE778 000CB578  38 E0 00 00 */	li r7, 0x0
/* 800CE77C 000CB57C  4C C6 31 82 */	crclr cr1eq
/* 800CE780 000CB580  4B F8 B2 A1 */	bl kar_lbarchive__80059a20
/* 800CE784 000CB584  80 61 00 08 */	lwz r3, 0x8(r1)
/* 800CE788 000CB588  80 03 00 00 */	lwz r0, 0x0(r3)
/* 800CE78C 000CB58C  90 0D 05 E8 */	stw r0, lbl_805DD6C8@sda21(r0)
/* 800CE790 000CB590  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800CE794 000CB594  7C 08 03 A6 */	mtlr r0
/* 800CE798 000CB598  38 21 00 10 */	addi r1, r1, 0x10
/* 800CE79C 000CB59C  4E 80 00 20 */	blr
.endfn kar_gr_assets__asset_800ce754
