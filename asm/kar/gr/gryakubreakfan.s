.include "macros.inc"
.file "gryakubreakfan.c"

# 0x80107370..0x8010757C | size: 0x20C
.text
.balign 4

# .text:0x0 | 0x80107370 | size: 0x16C
.fn kar_gryakubreakfan_trigger_kind30_break_effects_from_event, global
/* 80107370 00104170  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80107374 00104174  7C 08 02 A6 */	mflr r0
/* 80107378 00104178  90 01 00 34 */	stw r0, 0x34(r1)
/* 8010737C 0010417C  39 61 00 30 */	addi r11, r1, 0x30
/* 80107380 00104180  48 2A 67 D1 */	bl _savegpr_26
/* 80107384 00104184  80 84 00 00 */	lwz r4, 0x0(r4)
/* 80107388 00104188  7C 7F 1B 78 */	mr r31, r3
/* 8010738C 0010418C  A0 04 00 00 */	lhz r0, 0x0(r4)
/* 80107390 00104190  2C 00 00 10 */	cmpwi r0, 0x10
/* 80107394 00104194  41 82 00 0C */	beq .L_801073A0
/* 80107398 00104198  2C 00 00 11 */	cmpwi r0, 0x11
/* 8010739C 0010419C  40 82 01 28 */	bne .L_801074C4
.L_801073A0:
/* 801073A0 001041A0  2C 00 00 11 */	cmpwi r0, 0x11
/* 801073A4 001041A4  41 82 00 24 */	beq .L_801073C8
/* 801073A8 001041A8  40 80 00 2C */	bge .L_801073D4
/* 801073AC 001041AC  2C 00 00 10 */	cmpwi r0, 0x10
/* 801073B0 001041B0  40 80 00 08 */	bge .L_801073B8
/* 801073B4 001041B4  48 00 00 20 */	b .L_801073D4
.L_801073B8:
/* 801073B8 001041B8  7C 83 23 78 */	mr r3, r4
/* 801073BC 001041BC  38 81 00 08 */	addi r4, r1, 0x8
/* 801073C0 001041C0  48 0C 02 69 */	bl fn_801C7628
/* 801073C4 001041C4  48 00 00 10 */	b .L_801073D4
.L_801073C8:
/* 801073C8 001041C8  7C 83 23 78 */	mr r3, r4
/* 801073CC 001041CC  38 81 00 08 */	addi r4, r1, 0x8
/* 801073D0 001041D0  48 08 A7 7D */	bl fn_80191B4C
.L_801073D4:
/* 801073D4 001041D4  83 9F 00 2C */	lwz r28, 0x2c(r31)
/* 801073D8 001041D8  80 AD 05 EC */	lwz r5, lbl_805DD6CC@sda21(r0)
/* 801073DC 001041DC  80 7C 00 08 */	lwz r3, 0x8(r28)
/* 801073E0 001041E0  83 A3 00 00 */	lwz r29, 0x0(r3)
/* 801073E4 001041E4  80 1D 00 1C */	lwz r0, 0x1c(r29)
/* 801073E8 001041E8  2C 00 00 00 */	cmpwi r0, 0x0
/* 801073EC 001041EC  41 82 00 1C */	beq .L_80107408
/* 801073F0 001041F0  80 1D 00 00 */	lwz r0, 0x0(r29)
/* 801073F4 001041F4  38 80 00 10 */	li r4, 0x10
/* 801073F8 001041F8  80 65 01 04 */	lwz r3, 0x104(r5)
/* 801073FC 001041FC  54 00 18 38 */	slwi r0, r0, 3
/* 80107400 00104200  7C 63 00 2E */	lwzx r3, r3, r0
/* 80107404 00104204  48 30 49 FD */	bl HSD_JObjSetFlagsAll
.L_80107408:
/* 80107408 00104208  80 7C 00 EC */	lwz r3, 0xec(r28)
/* 8010740C 0010420C  48 08 56 F9 */	bl kar_collision_object_begin_disable
/* 80107410 00104210  80 1D 00 18 */	lwz r0, 0x18(r29)
/* 80107414 00104214  2C 00 00 03 */	cmpwi r0, 0x3
/* 80107418 00104218  40 81 00 1C */	ble .L_80107434
/* 8010741C 0010421C  3C 60 80 4A */	lis r3, kar_src_gryakubreakfan_c@ha
/* 80107420 00104220  3C A0 80 4A */	lis r5, kar_gryakubreakfan_assert_remove_effect_count@ha
/* 80107424 00104224  38 63 6F 3C */	addi r3, r3, kar_src_gryakubreakfan_c@l
/* 80107428 00104228  38 80 00 A1 */	li r4, 0xa1
/* 8010742C 0010422C  38 A5 6F 50 */	addi r5, r5, kar_gryakubreakfan_assert_remove_effect_count@l
/* 80107430 00104230  48 32 10 89 */	bl __assert
.L_80107434:
/* 80107434 00104234  3B C0 00 00 */	li r30, 0x0
/* 80107438 00104238  7F 9A E3 78 */	mr r26, r28
/* 8010743C 0010423C  7F DB F3 78 */	mr r27, r30
/* 80107440 00104240  48 00 00 3C */	b .L_8010747C
.L_80107444:
/* 80107444 00104244  80 1D 00 14 */	lwz r0, 0x14(r29)
/* 80107448 00104248  7F E3 FB 78 */	mr r3, r31
/* 8010744C 0010424C  80 BD 00 04 */	lwz r5, 0x4(r29)
/* 80107450 00104250  39 01 00 08 */	addi r8, r1, 0x8
/* 80107454 00104254  7C 80 DA 14 */	add r4, r0, r27
/* 80107458 00104258  38 C0 00 00 */	li r6, 0x0
/* 8010745C 0010425C  38 E0 00 00 */	li r7, 0x0
/* 80107460 00104260  39 20 00 00 */	li r9, 0x0
/* 80107464 00104264  4B FE FB E1 */	bl kar_gryakueffect_request_by_entry_mode
/* 80107468 00104268  90 9A 01 34 */	stw r4, 0x134(r26)
/* 8010746C 0010426C  3B 7B 00 1C */	addi r27, r27, 0x1c
/* 80107470 00104270  3B DE 00 01 */	addi r30, r30, 0x1
/* 80107474 00104274  90 7A 01 30 */	stw r3, 0x130(r26)
/* 80107478 00104278  3B 5A 00 08 */	addi r26, r26, 0x8
.L_8010747C:
/* 8010747C 0010427C  80 1D 00 18 */	lwz r0, 0x18(r29)
/* 80107480 00104280  7C 1E 00 00 */	cmpw r30, r0
/* 80107484 00104284  41 80 FF C0 */	blt .L_80107444
/* 80107488 00104288  80 1C 01 1C */	lwz r0, 0x11c(r28)
/* 8010748C 0010428C  2C 00 00 00 */	cmpwi r0, 0x0
/* 80107490 00104290  40 81 00 10 */	ble .L_801074A0
/* 80107494 00104294  38 7C 01 18 */	addi r3, r28, 0x118
/* 80107498 00104298  38 80 00 00 */	li r4, 0x0
/* 8010749C 0010429C  4B FE 2B E9 */	bl kar_graudio_play_fgm_entry_id
.L_801074A0:
/* 801074A0 001042A0  C0 22 93 68 */	lfs f1, lbl_805DFA68@sda21(r0)
/* 801074A4 001042A4  7F 83 E3 78 */	mr r3, r28
/* 801074A8 001042A8  80 BD 00 0C */	lwz r5, 0xc(r29)
/* 801074AC 001042AC  38 80 00 01 */	li r4, 0x1
/* 801074B0 001042B0  FC 60 08 90 */	fmr f3, f1
/* 801074B4 001042B4  80 DD 00 00 */	lwz r6, 0x0(r29)
/* 801074B8 001042B8  C0 42 93 6C */	lfs f2, lbl_805DFA6C@sda21(r0)
/* 801074BC 001042BC  38 E0 00 00 */	li r7, 0x0
/* 801074C0 001042C0  4B FE E0 89 */	bl kar_gryaku_set_path_node_motion
.L_801074C4:
/* 801074C4 001042C4  39 61 00 30 */	addi r11, r1, 0x30
/* 801074C8 001042C8  48 2A 66 D5 */	bl _restgpr_26
/* 801074CC 001042CC  80 01 00 34 */	lwz r0, 0x34(r1)
/* 801074D0 001042D0  7C 08 03 A6 */	mtlr r0
/* 801074D4 001042D4  38 21 00 30 */	addi r1, r1, 0x30
/* 801074D8 001042D8  4E 80 00 20 */	blr
.endfn kar_gryakubreakfan_trigger_kind30_break_effects_from_event

# .text:0x16C | 0x801074DC | size: 0xA0
.fn kar_gryakubreakfan_cleanup_shared_allocs_and_fgm_handles, global
/* 801074DC 001042DC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801074E0 001042E0  7C 08 02 A6 */	mflr r0
/* 801074E4 001042E4  90 01 00 24 */	stw r0, 0x24(r1)
/* 801074E8 001042E8  39 61 00 20 */	addi r11, r1, 0x20
/* 801074EC 001042EC  48 2A 66 69 */	bl _savegpr_27
/* 801074F0 001042F0  83 A3 00 2C */	lwz r29, 0x2c(r3)
/* 801074F4 001042F4  80 9D 00 08 */	lwz r4, 0x8(r29)
/* 801074F8 001042F8  80 7D 01 30 */	lwz r3, 0x130(r29)
/* 801074FC 001042FC  83 84 00 00 */	lwz r28, 0x0(r4)
/* 80107500 00104300  48 31 59 B5 */	bl HSD_Free
/* 80107504 00104304  80 1D 01 50 */	lwz r0, 0x150(r29)
/* 80107508 00104308  28 00 00 00 */	cmplwi r0, 0x0
/* 8010750C 0010430C  41 82 00 58 */	beq .L_80107564
/* 80107510 00104310  3B 60 00 00 */	li r27, 0x0
/* 80107514 00104314  3B C0 00 00 */	li r30, 0x0
/* 80107518 00104318  3B E0 FF FF */	li r31, -0x1
/* 8010751C 0010431C  48 00 00 34 */	b .L_80107550
.L_80107520:
/* 80107520 00104320  80 7D 01 50 */	lwz r3, 0x150(r29)
/* 80107524 00104324  7C 63 F0 2E */	lwzx r3, r3, r30
/* 80107528 00104328  20 83 FF FF */	subfic r4, r3, -0x1
/* 8010752C 0010432C  38 03 00 01 */	addi r0, r3, 0x1
/* 80107530 00104330  7C 80 03 78 */	or r0, r4, r0
/* 80107534 00104334  54 00 0F FF */	srwi. r0, r0, 31
/* 80107538 00104338  41 82 00 10 */	beq .L_80107548
/* 8010753C 0010433C  4B FE 2B 29 */	bl kar_graudio_release_fgm_track_group_handle
/* 80107540 00104340  80 7D 01 50 */	lwz r3, 0x150(r29)
/* 80107544 00104344  7F E3 F1 2E */	stwx r31, r3, r30
.L_80107548:
/* 80107548 00104348  3B DE 00 04 */	addi r30, r30, 0x4
/* 8010754C 0010434C  3B 7B 00 01 */	addi r27, r27, 0x1
.L_80107550:
/* 80107550 00104350  80 1C 00 04 */	lwz r0, 0x4(r28)
/* 80107554 00104354  7C 1B 00 00 */	cmpw r27, r0
/* 80107558 00104358  41 80 FF C8 */	blt .L_80107520
/* 8010755C 0010435C  80 7D 01 50 */	lwz r3, 0x150(r29)
/* 80107560 00104360  48 31 59 55 */	bl HSD_Free
.L_80107564:
/* 80107564 00104364  39 61 00 20 */	addi r11, r1, 0x20
/* 80107568 00104368  48 2A 66 39 */	bl _restgpr_27
/* 8010756C 0010436C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80107570 00104370  7C 08 03 A6 */	mtlr r0
/* 80107574 00104374  38 21 00 20 */	addi r1, r1, 0x20
/* 80107578 00104378  4E 80 00 20 */	blr
.endfn kar_gryakubreakfan_cleanup_shared_allocs_and_fgm_handles

# 0x804A6F08..0x804A6F90 | size: 0x88
.data
.balign 8

# .data:0x0 | 0x804A6F08 | size: 0x20
.obj kar_gryakubreakfloor_kind30_breakfan_callback_table, global
	.4byte kar_gryakubreakfloor_configure_kind30_breakfan_fgm
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte kar_gryakubreakfloor_update_kind30_breakfan_effects_then_destroy
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj kar_gryakubreakfloor_kind30_breakfan_callback_table

# .data:0x20 | 0x804A6F28 | size: 0x14
.obj kar_gryakubreakfloor_kind30_breakfan_callback_table_ptr, global
	.4byte kar_gryakubreakfloor_kind30_breakfan_callback_table
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj kar_gryakubreakfloor_kind30_breakfan_callback_table_ptr

# .data:0x34 | 0x804A6F3C | size: 0x11
.obj kar_src_gryakubreakfan_c, global
	.string "gryakubreakfan.c"
.endobj kar_src_gryakubreakfan_c

# .data:0x45 | 0x804A6F4D | size: 0x3
.obj gap_07_804A6F4D_data, global
.hidden gap_07_804A6F4D_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A6F4D_data

# .data:0x48 | 0x804A6F50 | size: 0x39
.obj kar_gryakubreakfan_assert_remove_effect_count, global
	.string "param->efBreakNum <= GrYakuBreakFan_RemoveEffectIdNumMax"
.endobj kar_gryakubreakfan_assert_remove_effect_count

# .data:0x81 | 0x804A6F89 | size: 0x7
.obj gap_07_804A6F89_data, global
.hidden gap_07_804A6F89_data
	.4byte 0x00000000
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A6F89_data
