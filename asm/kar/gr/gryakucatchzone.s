.include "macros.inc"
.file "gryakucatchzone.c"

# 0x800FA3C0..0x800FAC9C | size: 0x8DC
.text
.balign 4

# .text:0x0 | 0x800FA3C0 | size: 0x1D4
.fn kar_gryakucatchzone_find_catch_target_for_player, global
/* 800FA3C0 000F71C0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800FA3C4 000F71C4  7C 08 02 A6 */	mflr r0
/* 800FA3C8 000F71C8  90 01 00 24 */	stw r0, 0x24(r1)
/* 800FA3CC 000F71CC  39 61 00 20 */	addi r11, r1, 0x20
/* 800FA3D0 000F71D0  48 2B 37 81 */	bl _savegpr_26
/* 800FA3D4 000F71D4  7C 7A 1B 78 */	mr r26, r3
/* 800FA3D8 000F71D8  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 800FA3DC 000F71DC  1F FA 01 40 */	mulli r31, r26, 0x140
/* 800FA3E0 000F71E0  7C 9B 23 78 */	mr r27, r4
/* 800FA3E4 000F71E4  80 03 00 74 */	lwz r0, 0x74(r3)
/* 800FA3E8 000F71E8  7C 60 FA 14 */	add r3, r0, r31
/* 800FA3EC 000F71EC  80 63 01 38 */	lwz r3, 0x138(r3)
/* 800FA3F0 000F71F0  28 03 00 00 */	cmplwi r3, 0x0
/* 800FA3F4 000F71F4  41 82 01 84 */	beq .L_800FA578
/* 800FA3F8 000F71F8  83 A3 00 2C */	lwz r29, 0x2c(r3)
/* 800FA3FC 000F71FC  80 1D 00 04 */	lwz r0, 0x4(r29)
/* 800FA400 000F7200  2C 00 00 11 */	cmpwi r0, 0x11
/* 800FA404 000F7204  41 82 00 1C */	beq .L_800FA420
/* 800FA408 000F7208  3C 60 80 4A */	lis r3, kar_src_gryakucatchzone_c@ha
/* 800FA40C 000F720C  3C A0 80 4A */	lis r5, kar_gryakucatchzone_assert_kind_catchzone@ha
/* 800FA410 000F7210  38 63 5F 64 */	addi r3, r3, kar_src_gryakucatchzone_c@l
/* 800FA414 000F7214  38 80 00 C4 */	li r4, 0xc4
/* 800FA418 000F7218  38 A5 5F 78 */	addi r5, r5, kar_gryakucatchzone_assert_kind_catchzone@l
/* 800FA41C 000F721C  48 32 E0 9D */	bl __assert
.L_800FA420:
/* 800FA420 000F7220  80 9D 00 08 */	lwz r4, 0x8(r29)
/* 800FA424 000F7224  80 6D 12 54 */	lwz r3, lbl_805DE334@sda21(r0)
/* 800FA428 000F7228  83 C4 00 00 */	lwz r30, 0x0(r4)
/* 800FA42C 000F722C  83 A3 00 20 */	lwz r29, 0x20(r3)
/* 800FA430 000F7230  48 00 01 40 */	b .L_800FA570
.L_800FA434:
/* 800FA434 000F7234  7F A3 EB 78 */	mr r3, r29
/* 800FA438 000F7238  4B FF D6 2D */	bl kar_gryakulib_get_yaku_data_checked
/* 800FA43C 000F723C  80 1E 00 0C */	lwz r0, 0xc(r30)
/* 800FA440 000F7240  7C 00 18 00 */	cmpw r0, r3
/* 800FA444 000F7244  40 82 01 28 */	bne .L_800FA56C
/* 800FA448 000F7248  2C 00 00 2F */	cmpwi r0, 0x2f
/* 800FA44C 000F724C  41 82 01 10 */	beq .L_800FA55C
/* 800FA450 000F7250  40 80 00 10 */	bge .L_800FA460
/* 800FA454 000F7254  2C 00 00 2E */	cmpwi r0, 0x2e
/* 800FA458 000F7258  40 80 00 14 */	bge .L_800FA46C
/* 800FA45C 000F725C  48 00 01 00 */	b .L_800FA55C
.L_800FA460:
/* 800FA460 000F7260  2C 00 00 31 */	cmpwi r0, 0x31
/* 800FA464 000F7264  40 80 00 F8 */	bge .L_800FA55C
/* 800FA468 000F7268  48 00 00 64 */	b .L_800FA4CC
.L_800FA46C:
/* 800FA46C 000F726C  80 AD 05 EC */	lwz r5, lbl_805DD6CC@sda21(r0)
/* 800FA470 000F7270  7F A3 EB 78 */	mr r3, r29
/* 800FA474 000F7274  7F 44 D3 78 */	mr r4, r26
/* 800FA478 000F7278  80 A5 00 74 */	lwz r5, 0x74(r5)
/* 800FA47C 000F727C  38 05 01 38 */	addi r0, r5, 0x138
/* 800FA480 000F7280  7C BF 00 2E */	lwzx r5, r31, r0
/* 800FA484 000F7284  83 85 00 2C */	lwz r28, 0x2c(r5)
/* 800FA488 000F7288  48 00 44 81 */	bl kar_gryakugondola_is_catch_candidate_in_zone
/* 800FA48C 000F728C  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FA490 000F7290  41 82 00 30 */	beq .L_800FA4C0
/* 800FA494 000F7294  7F A3 EB 78 */	mr r3, r29
/* 800FA498 000F7298  7F 64 DB 78 */	mr r4, r27
/* 800FA49C 000F729C  48 00 44 CD */	bl kar_gryakugondola_record_nearest_catch_candidate
/* 800FA4A0 000F72A0  80 1C 01 1C */	lwz r0, 0x11c(r28)
/* 800FA4A4 000F72A4  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FA4A8 000F72A8  40 81 00 10 */	ble .L_800FA4B8
/* 800FA4AC 000F72AC  38 7C 01 18 */	addi r3, r28, 0x118
/* 800FA4B0 000F72B0  38 80 00 00 */	li r4, 0x0
/* 800FA4B4 000F72B4  4B FE FB D1 */	bl kar_graudio_play_fgm_entry_id
.L_800FA4B8:
/* 800FA4B8 000F72B8  7F A0 EB 78 */	mr r0, r29
/* 800FA4BC 000F72BC  48 00 00 08 */	b .L_800FA4C4
.L_800FA4C0:
/* 800FA4C0 000F72C0  38 00 00 00 */	li r0, 0x0
.L_800FA4C4:
/* 800FA4C4 000F72C4  7C 1C 03 78 */	mr r28, r0
/* 800FA4C8 000F72C8  48 00 00 94 */	b .L_800FA55C
.L_800FA4CC:
/* 800FA4CC 000F72CC  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 800FA4D0 000F72D0  38 C0 00 00 */	li r6, 0x0
/* 800FA4D4 000F72D4  80 9D 00 2C */	lwz r4, 0x2c(r29)
/* 800FA4D8 000F72D8  80 63 00 74 */	lwz r3, 0x74(r3)
/* 800FA4DC 000F72DC  80 84 00 08 */	lwz r4, 0x8(r4)
/* 800FA4E0 000F72E0  38 03 01 38 */	addi r0, r3, 0x138
/* 800FA4E4 000F72E4  7C 7F 00 2E */	lwzx r3, r31, r0
/* 800FA4E8 000F72E8  80 84 00 00 */	lwz r4, 0x0(r4)
/* 800FA4EC 000F72EC  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FA4F0 000F72F0  80 A4 00 00 */	lwz r5, 0x0(r4)
/* 800FA4F4 000F72F4  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800FA4F8 000F72F8  80 83 00 00 */	lwz r4, 0x0(r3)
/* 800FA4FC 000F72FC  80 04 00 08 */	lwz r0, 0x8(r4)
/* 800FA500 000F7300  7C 09 03 A6 */	mtctr r0
/* 800FA504 000F7304  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FA508 000F7308  40 81 00 24 */	ble .L_800FA52C
.L_800FA50C:
/* 800FA50C 000F730C  80 64 00 04 */	lwz r3, 0x4(r4)
/* 800FA510 000F7310  7C 03 30 2E */	lwzx r0, r3, r6
/* 800FA514 000F7314  7C 05 00 00 */	cmpw r5, r0
/* 800FA518 000F7318  40 82 00 0C */	bne .L_800FA524
/* 800FA51C 000F731C  38 00 00 01 */	li r0, 0x1
/* 800FA520 000F7320  48 00 00 10 */	b .L_800FA530
.L_800FA524:
/* 800FA524 000F7324  38 C6 00 04 */	addi r6, r6, 0x4
/* 800FA528 000F7328  42 00 FF E4 */	bdnz .L_800FA50C
.L_800FA52C:
/* 800FA52C 000F732C  38 00 00 00 */	li r0, 0x0
.L_800FA530:
/* 800FA530 000F7330  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FA534 000F7334  41 82 00 20 */	beq .L_800FA554
/* 800FA538 000F7338  7F A3 EB 78 */	mr r3, r29
/* 800FA53C 000F733C  7F 64 DB 78 */	mr r4, r27
/* 800FA540 000F7340  48 00 4C E1 */	bl kar_gryakucannon_enqueue_catch_target
/* 800FA544 000F7344  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FA548 000F7348  41 82 00 0C */	beq .L_800FA554
/* 800FA54C 000F734C  7F A0 EB 78 */	mr r0, r29
/* 800FA550 000F7350  48 00 00 08 */	b .L_800FA558
.L_800FA554:
/* 800FA554 000F7354  38 00 00 00 */	li r0, 0x0
.L_800FA558:
/* 800FA558 000F7358  7C 1C 03 78 */	mr r28, r0
.L_800FA55C:
/* 800FA55C 000F735C  28 1C 00 00 */	cmplwi r28, 0x0
/* 800FA560 000F7360  41 82 00 0C */	beq .L_800FA56C
/* 800FA564 000F7364  7F 83 E3 78 */	mr r3, r28
/* 800FA568 000F7368  48 00 00 14 */	b .L_800FA57C
.L_800FA56C:
/* 800FA56C 000F736C  83 BD 00 08 */	lwz r29, 0x8(r29)
.L_800FA570:
/* 800FA570 000F7370  28 1D 00 00 */	cmplwi r29, 0x0
/* 800FA574 000F7374  40 82 FE C0 */	bne .L_800FA434
.L_800FA578:
/* 800FA578 000F7378  38 60 00 00 */	li r3, 0x0
.L_800FA57C:
/* 800FA57C 000F737C  39 61 00 20 */	addi r11, r1, 0x20
/* 800FA580 000F7380  48 2B 36 1D */	bl _restgpr_26
/* 800FA584 000F7384  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FA588 000F7388  7C 08 03 A6 */	mtlr r0
/* 800FA58C 000F738C  38 21 00 20 */	addi r1, r1, 0x20
/* 800FA590 000F7390  4E 80 00 20 */	blr
.endfn kar_gryakucatchzone_find_catch_target_for_player

# .text:0x1D4 | 0x800FA594 | size: 0x7C
.fn kar_gryakucatchzone_get_target_yaku_kind, global
/* 800FA594 000F7394  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FA598 000F7398  7C 08 02 A6 */	mflr r0
/* 800FA59C 000F739C  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FA5A0 000F73A0  1C 03 01 40 */	mulli r0, r3, 0x140
/* 800FA5A4 000F73A4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FA5A8 000F73A8  80 8D 05 EC */	lwz r4, lbl_805DD6CC@sda21(r0)
/* 800FA5AC 000F73AC  80 64 00 74 */	lwz r3, 0x74(r4)
/* 800FA5B0 000F73B0  7C 63 02 14 */	add r3, r3, r0
/* 800FA5B4 000F73B4  80 63 01 38 */	lwz r3, 0x138(r3)
/* 800FA5B8 000F73B8  28 03 00 00 */	cmplwi r3, 0x0
/* 800FA5BC 000F73BC  41 82 00 3C */	beq .L_800FA5F8
/* 800FA5C0 000F73C0  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800FA5C4 000F73C4  80 1F 00 04 */	lwz r0, 0x4(r31)
/* 800FA5C8 000F73C8  2C 00 00 11 */	cmpwi r0, 0x11
/* 800FA5CC 000F73CC  41 82 00 1C */	beq .L_800FA5E8
/* 800FA5D0 000F73D0  3C 60 80 4A */	lis r3, kar_src_gryakucatchzone_c@ha
/* 800FA5D4 000F73D4  3C A0 80 4A */	lis r5, kar_gryakucatchzone_assert_kind_catchzone@ha
/* 800FA5D8 000F73D8  38 63 5F 64 */	addi r3, r3, kar_src_gryakucatchzone_c@l
/* 800FA5DC 000F73DC  38 80 01 07 */	li r4, 0x107
/* 800FA5E0 000F73E0  38 A5 5F 78 */	addi r5, r5, kar_gryakucatchzone_assert_kind_catchzone@l
/* 800FA5E4 000F73E4  48 32 DE D5 */	bl __assert
.L_800FA5E8:
/* 800FA5E8 000F73E8  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800FA5EC 000F73EC  80 63 00 00 */	lwz r3, 0x0(r3)
/* 800FA5F0 000F73F0  80 63 00 0C */	lwz r3, 0xc(r3)
/* 800FA5F4 000F73F4  48 00 00 08 */	b .L_800FA5FC
.L_800FA5F8:
/* 800FA5F8 000F73F8  38 60 FF FF */	li r3, -0x1
.L_800FA5FC:
/* 800FA5FC 000F73FC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FA600 000F7400  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FA604 000F7404  7C 08 03 A6 */	mtlr r0
/* 800FA608 000F7408  38 21 00 10 */	addi r1, r1, 0x10
/* 800FA60C 000F740C  4E 80 00 20 */	blr
.endfn kar_gryakucatchzone_get_target_yaku_kind

# .text:0x250 | 0x800FA610 | size: 0x38
.fn kar_gryakucatchzone_create_stage_linked_kind18_yaku, global
/* 800FA610 000F7410  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FA614 000F7414  7C 08 02 A6 */	mflr r0
/* 800FA618 000F7418  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FA61C 000F741C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FA620 000F7420  7C 7F 1B 78 */	mr r31, r3
/* 800FA624 000F7424  38 60 00 12 */	li r3, 0x12
/* 800FA628 000F7428  4B FF 9E 45 */	bl kar_gryaku_create_yaku_from_main_kind
/* 800FA62C 000F742C  7F E4 FB 78 */	mr r4, r31
/* 800FA630 000F7430  48 00 00 19 */	bl kar_gryakucatchzone_init_stage_linked_kind18_yaku
/* 800FA634 000F7434  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FA638 000F7438  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FA63C 000F743C  7C 08 03 A6 */	mtlr r0
/* 800FA640 000F7440  38 21 00 10 */	addi r1, r1, 0x10
/* 800FA644 000F7444  4E 80 00 20 */	blr
.endfn kar_gryakucatchzone_create_stage_linked_kind18_yaku

# .text:0x288 | 0x800FA648 | size: 0x78
.fn kar_gryakucatchzone_init_stage_linked_kind18_yaku, global
/* 800FA648 000F7448  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FA64C 000F744C  7C 08 02 A6 */	mflr r0
/* 800FA650 000F7450  38 A0 00 00 */	li r5, 0x0
/* 800FA654 000F7454  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FA658 000F7458  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FA65C 000F745C  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800FA660 000F7460  7C 7E 1B 78 */	mr r30, r3
/* 800FA664 000F7464  83 FE 00 2C */	lwz r31, 0x2c(r30)
/* 800FA668 000F7468  80 64 00 2C */	lwz r3, 0x2c(r4)
/* 800FA66C 000F746C  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 800FA670 000F7470  80 C3 01 04 */	lwz r6, 0x104(r3)
/* 800FA674 000F7474  80 84 00 00 */	lwz r4, 0x0(r4)
/* 800FA678 000F7478  80 ED 05 EC */	lwz r7, lbl_805DD6CC@sda21(r0)
/* 800FA67C 000F747C  80 04 00 00 */	lwz r0, 0x0(r4)
/* 800FA680 000F7480  38 67 00 54 */	addi r3, r7, 0x54
/* 800FA684 000F7484  54 00 18 38 */	slwi r0, r0, 3
/* 800FA688 000F7488  7C 86 00 2E */	lwzx r4, r6, r0
/* 800FA68C 000F748C  4B FD D3 35 */	bl kar_grcoll__800d79c0
/* 800FA690 000F7490  90 7F 01 30 */	stw r3, 0x130(r31)
/* 800FA694 000F7494  7F C3 F3 78 */	mr r3, r30
/* 800FA698 000F7498  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 800FA69C 000F749C  80 9F 01 30 */	lwz r4, 0x130(r31)
/* 800FA6A0 000F74A0  90 04 01 38 */	stw r0, 0x138(r4)
/* 800FA6A4 000F74A4  48 00 00 1D */	bl kar_gryakucatchzone_start_kind18_path_motion
/* 800FA6A8 000F74A8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FA6AC 000F74AC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FA6B0 000F74B0  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800FA6B4 000F74B4  7C 08 03 A6 */	mtlr r0
/* 800FA6B8 000F74B8  38 21 00 10 */	addi r1, r1, 0x10
/* 800FA6BC 000F74BC  4E 80 00 20 */	blr
.endfn kar_gryakucatchzone_init_stage_linked_kind18_yaku

# .text:0x300 | 0x800FA6C0 | size: 0x48
.fn kar_gryakucatchzone_start_kind18_path_motion, global
/* 800FA6C0 000F74C0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FA6C4 000F74C4  7C 08 02 A6 */	mflr r0
/* 800FA6C8 000F74C8  C0 22 91 C0 */	lfs f1, lbl_805DF8C0@sda21(r0)
/* 800FA6CC 000F74CC  38 80 00 00 */	li r4, 0x0
/* 800FA6D0 000F74D0  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FA6D4 000F74D4  38 A0 FF FF */	li r5, -0x1
/* 800FA6D8 000F74D8  FC 40 08 90 */	fmr f2, f1
/* 800FA6DC 000F74DC  38 E0 00 00 */	li r7, 0x0
/* 800FA6E0 000F74E0  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FA6E4 000F74E4  FC 60 08 90 */	fmr f3, f1
/* 800FA6E8 000F74E8  80 C3 00 08 */	lwz r6, 0x8(r3)
/* 800FA6EC 000F74EC  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 800FA6F0 000F74F0  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 800FA6F4 000F74F4  4B FF AE 55 */	bl kar_gryaku_set_path_node_motion
/* 800FA6F8 000F74F8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FA6FC 000F74FC  7C 08 03 A6 */	mtlr r0
/* 800FA700 000F7500  38 21 00 10 */	addi r1, r1, 0x10
/* 800FA704 000F7504  4E 80 00 20 */	blr
.endfn kar_gryakucatchzone_start_kind18_path_motion

# .text:0x348 | 0x800FA708 | size: 0x38
.fn kar_gryakucatchzone_create_stage_linked_kind19_yaku, global
/* 800FA708 000F7508  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FA70C 000F750C  7C 08 02 A6 */	mflr r0
/* 800FA710 000F7510  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FA714 000F7514  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FA718 000F7518  7C 7F 1B 78 */	mr r31, r3
/* 800FA71C 000F751C  38 60 00 13 */	li r3, 0x13
/* 800FA720 000F7520  4B FF 9D 4D */	bl kar_gryaku_create_yaku_from_main_kind
/* 800FA724 000F7524  7F E4 FB 78 */	mr r4, r31
/* 800FA728 000F7528  48 00 00 19 */	bl kar_gryakucatchzone_init_stage_linked_kind19_yaku
/* 800FA72C 000F752C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FA730 000F7530  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FA734 000F7534  7C 08 03 A6 */	mtlr r0
/* 800FA738 000F7538  38 21 00 10 */	addi r1, r1, 0x10
/* 800FA73C 000F753C  4E 80 00 20 */	blr
.endfn kar_gryakucatchzone_create_stage_linked_kind19_yaku

# .text:0x380 | 0x800FA740 | size: 0xA0
.fn kar_gryakucatchzone_init_stage_linked_kind19_yaku, global
/* 800FA740 000F7540  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FA744 000F7544  7C 08 02 A6 */	mflr r0
/* 800FA748 000F7548  38 A0 00 00 */	li r5, 0x0
/* 800FA74C 000F754C  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FA750 000F7550  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FA754 000F7554  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800FA758 000F7558  7C 7E 1B 78 */	mr r30, r3
/* 800FA75C 000F755C  83 FE 00 2C */	lwz r31, 0x2c(r30)
/* 800FA760 000F7560  80 64 00 2C */	lwz r3, 0x2c(r4)
/* 800FA764 000F7564  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 800FA768 000F7568  80 C3 01 04 */	lwz r6, 0x104(r3)
/* 800FA76C 000F756C  80 84 00 00 */	lwz r4, 0x0(r4)
/* 800FA770 000F7570  80 ED 05 EC */	lwz r7, lbl_805DD6CC@sda21(r0)
/* 800FA774 000F7574  80 04 00 00 */	lwz r0, 0x0(r4)
/* 800FA778 000F7578  38 67 00 54 */	addi r3, r7, 0x54
/* 800FA77C 000F757C  54 00 18 38 */	slwi r0, r0, 3
/* 800FA780 000F7580  7C 86 00 2E */	lwzx r4, r6, r0
/* 800FA784 000F7584  4B FD D2 3D */	bl kar_grcoll__800d79c0
/* 800FA788 000F7588  90 7F 01 30 */	stw r3, 0x130(r31)
/* 800FA78C 000F758C  38 60 00 00 */	li r3, 0x0
/* 800FA790 000F7590  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 800FA794 000F7594  80 9F 01 30 */	lwz r4, 0x130(r31)
/* 800FA798 000F7598  90 04 01 38 */	stw r0, 0x138(r4)
/* 800FA79C 000F759C  88 1F 01 84 */	lbz r0, 0x184(r31)
/* 800FA7A0 000F75A0  50 60 3E 30 */	rlwimi r0, r3, 7, 24, 24
/* 800FA7A4 000F75A4  98 1F 01 84 */	stb r0, 0x184(r31)
/* 800FA7A8 000F75A8  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800FA7AC 000F75AC  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800FA7B0 000F75B0  28 00 00 00 */	cmplwi r0, 0x0
/* 800FA7B4 000F75B4  41 82 00 0C */	beq .L_800FA7C0
/* 800FA7B8 000F75B8  7F E3 FB 78 */	mr r3, r31
/* 800FA7BC 000F75BC  48 00 00 25 */	bl kar_gryakucatchzone_init_four_audio_rail_states
.L_800FA7C0:
/* 800FA7C0 000F75C0  7F C3 F3 78 */	mr r3, r30
/* 800FA7C4 000F75C4  48 00 01 05 */	bl kar_gryakucatchzone_start_kind19_path_motion
/* 800FA7C8 000F75C8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FA7CC 000F75CC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FA7D0 000F75D0  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800FA7D4 000F75D4  7C 08 03 A6 */	mtlr r0
/* 800FA7D8 000F75D8  38 21 00 10 */	addi r1, r1, 0x10
/* 800FA7DC 000F75DC  4E 80 00 20 */	blr
.endfn kar_gryakucatchzone_init_stage_linked_kind19_yaku

# .text:0x420 | 0x800FA7E0 | size: 0x88
.fn kar_gryakucatchzone_init_four_audio_rail_states, global
/* 800FA7E0 000F75E0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800FA7E4 000F75E4  7C 08 02 A6 */	mflr r0
/* 800FA7E8 000F75E8  90 01 00 24 */	stw r0, 0x24(r1)
/* 800FA7EC 000F75EC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800FA7F0 000F75F0  7C 7F 1B 78 */	mr r31, r3
/* 800FA7F4 000F75F4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800FA7F8 000F75F8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800FA7FC 000F75FC  80 83 00 08 */	lwz r4, 0x8(r3)
/* 800FA800 000F7600  83 C4 00 14 */	lwz r30, 0x14(r4)
/* 800FA804 000F7604  4B FF D0 49 */	bl kar_gryakueffect_stop_audio_rail_state
/* 800FA808 000F7608  3B A0 00 00 */	li r29, 0x0
.L_800FA80C:
/* 800FA80C 000F760C  38 7F 01 34 */	addi r3, r31, 0x134
/* 800FA810 000F7610  4B FE F2 3D */	bl kar_grrail__near_800e9a4c
/* 800FA814 000F7614  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 800FA818 000F7618  90 1F 01 34 */	stw r0, 0x134(r31)
/* 800FA81C 000F761C  80 1E 00 04 */	lwz r0, 0x4(r30)
/* 800FA820 000F7620  90 1F 01 38 */	stw r0, 0x138(r31)
/* 800FA824 000F7624  80 7E 00 08 */	lwz r3, 0x8(r30)
/* 800FA828 000F7628  4B FE F6 81 */	bl kar_graudio_alloc_fgm_track_by_kind
/* 800FA82C 000F762C  90 7F 01 3C */	stw r3, 0x13c(r31)
/* 800FA830 000F7630  38 60 00 01 */	li r3, 0x1
/* 800FA834 000F7634  4B FE F6 FD */	bl kar_graudio_alloc_map_fgm_track_group
/* 800FA838 000F7638  3B BD 00 01 */	addi r29, r29, 0x1
/* 800FA83C 000F763C  90 7F 01 40 */	stw r3, 0x140(r31)
/* 800FA840 000F7640  2C 1D 00 04 */	cmpwi r29, 0x4
/* 800FA844 000F7644  3B FF 00 14 */	addi r31, r31, 0x14
/* 800FA848 000F7648  41 80 FF C4 */	blt .L_800FA80C
/* 800FA84C 000F764C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FA850 000F7650  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800FA854 000F7654  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800FA858 000F7658  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800FA85C 000F765C  7C 08 03 A6 */	mtlr r0
/* 800FA860 000F7660  38 21 00 20 */	addi r1, r1, 0x20
/* 800FA864 000F7664  4E 80 00 20 */	blr
.endfn kar_gryakucatchzone_init_four_audio_rail_states

# .text:0x4A8 | 0x800FA868 | size: 0x60
.fn kar_gryakucatchzone_stop_four_audio_rail_states, global
/* 800FA868 000F7668  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FA86C 000F766C  7C 08 02 A6 */	mflr r0
/* 800FA870 000F7670  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FA874 000F7674  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FA878 000F7678  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800FA87C 000F767C  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 800FA880 000F7680  80 64 00 08 */	lwz r3, 0x8(r4)
/* 800FA884 000F7684  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800FA888 000F7688  28 00 00 00 */	cmplwi r0, 0x0
/* 800FA88C 000F768C  41 82 00 24 */	beq .L_800FA8B0
/* 800FA890 000F7690  3B C0 00 00 */	li r30, 0x0
/* 800FA894 000F7694  7C 9F 23 78 */	mr r31, r4
.L_800FA898:
/* 800FA898 000F7698  38 7F 01 34 */	addi r3, r31, 0x134
/* 800FA89C 000F769C  4B FE F1 CD */	bl kar_graudio_stop_fgm_entry
/* 800FA8A0 000F76A0  3B DE 00 01 */	addi r30, r30, 0x1
/* 800FA8A4 000F76A4  3B FF 00 14 */	addi r31, r31, 0x14
/* 800FA8A8 000F76A8  2C 1E 00 04 */	cmpwi r30, 0x4
/* 800FA8AC 000F76AC  41 80 FF EC */	blt .L_800FA898
.L_800FA8B0:
/* 800FA8B0 000F76B0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FA8B4 000F76B4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FA8B8 000F76B8  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800FA8BC 000F76BC  7C 08 03 A6 */	mtlr r0
/* 800FA8C0 000F76C0  38 21 00 10 */	addi r1, r1, 0x10
/* 800FA8C4 000F76C4  4E 80 00 20 */	blr
.endfn kar_gryakucatchzone_stop_four_audio_rail_states

# .text:0x508 | 0x800FA8C8 | size: 0x48
.fn kar_gryakucatchzone_start_kind19_path_motion, global
/* 800FA8C8 000F76C8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FA8CC 000F76CC  7C 08 02 A6 */	mflr r0
/* 800FA8D0 000F76D0  C0 22 91 C8 */	lfs f1, lbl_805DF8C8@sda21(r0)
/* 800FA8D4 000F76D4  38 80 00 00 */	li r4, 0x0
/* 800FA8D8 000F76D8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FA8DC 000F76DC  38 A0 FF FF */	li r5, -0x1
/* 800FA8E0 000F76E0  FC 40 08 90 */	fmr f2, f1
/* 800FA8E4 000F76E4  38 E0 00 00 */	li r7, 0x0
/* 800FA8E8 000F76E8  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FA8EC 000F76EC  FC 60 08 90 */	fmr f3, f1
/* 800FA8F0 000F76F0  80 C3 00 08 */	lwz r6, 0x8(r3)
/* 800FA8F4 000F76F4  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 800FA8F8 000F76F8  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 800FA8FC 000F76FC  4B FF AC 4D */	bl kar_gryaku_set_path_node_motion
/* 800FA900 000F7700  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FA904 000F7704  7C 08 03 A6 */	mtlr r0
/* 800FA908 000F7708  38 21 00 10 */	addi r1, r1, 0x10
/* 800FA90C 000F770C  4E 80 00 20 */	blr
.endfn kar_gryakucatchzone_start_kind19_path_motion

# .text:0x550 | 0x800FA910 | size: 0x18
.fn fn_800FA910, global
/* 800FA910 000F7710  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FA914 000F7714  38 80 00 00 */	li r4, 0x0
/* 800FA918 000F7718  88 03 01 84 */	lbz r0, 0x184(r3)
/* 800FA91C 000F771C  50 80 3E 30 */	rlwimi r0, r4, 7, 24, 24
/* 800FA920 000F7720  98 03 01 84 */	stb r0, 0x184(r3)
/* 800FA924 000F7724  4E 80 00 20 */	blr
.endfn fn_800FA910

# .text:0x568 | 0x800FA928 | size: 0x64
.fn kar_gryakucatchzone_request_contact_fgm_for_report, global
/* 800FA928 000F7728  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FA92C 000F772C  7C 08 02 A6 */	mflr r0
/* 800FA930 000F7730  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FA934 000F7734  1C 04 01 40 */	mulli r0, r4, 0x140
/* 800FA938 000F7738  7C 64 1B 78 */	mr r4, r3
/* 800FA93C 000F773C  80 AD 05 EC */	lwz r5, lbl_805DD6CC@sda21(r0)
/* 800FA940 000F7740  80 65 00 74 */	lwz r3, 0x74(r5)
/* 800FA944 000F7744  7C 63 02 14 */	add r3, r3, r0
/* 800FA948 000F7748  80 63 01 38 */	lwz r3, 0x138(r3)
/* 800FA94C 000F774C  28 03 00 00 */	cmplwi r3, 0x0
/* 800FA950 000F7750  41 82 00 2C */	beq .L_800FA97C
/* 800FA954 000F7754  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FA958 000F7758  38 A0 00 01 */	li r5, 0x1
/* 800FA95C 000F775C  88 03 01 84 */	lbz r0, 0x184(r3)
/* 800FA960 000F7760  50 A0 3E 30 */	rlwimi r0, r5, 7, 24, 24
/* 800FA964 000F7764  98 03 01 84 */	stb r0, 0x184(r3)
/* 800FA968 000F7768  80 A3 00 08 */	lwz r5, 0x8(r3)
/* 800FA96C 000F776C  80 05 00 14 */	lwz r0, 0x14(r5)
/* 800FA970 000F7770  28 00 00 00 */	cmplwi r0, 0x0
/* 800FA974 000F7774  41 82 00 08 */	beq .L_800FA97C
/* 800FA978 000F7778  48 00 00 15 */	bl kar_gryakucatchzone_play_contact_fgm_at_report
.L_800FA97C:
/* 800FA97C 000F777C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FA980 000F7780  7C 08 03 A6 */	mtlr r0
/* 800FA984 000F7784  38 21 00 10 */	addi r1, r1, 0x10
/* 800FA988 000F7788  4E 80 00 20 */	blr
.endfn kar_gryakucatchzone_request_contact_fgm_for_report

# .text:0x5CC | 0x800FA98C | size: 0xFC
.fn kar_gryakucatchzone_play_contact_fgm_at_report, global
/* 800FA98C 000F778C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800FA990 000F7790  7C 08 02 A6 */	mflr r0
/* 800FA994 000F7794  38 C4 00 44 */	addi r6, r4, 0x44
/* 800FA998 000F7798  90 01 00 24 */	stw r0, 0x24(r1)
/* 800FA99C 000F779C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800FA9A0 000F77A0  7C 7F 1B 78 */	mr r31, r3
/* 800FA9A4 000F77A4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800FA9A8 000F77A8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800FA9AC 000F77AC  93 81 00 10 */	stw r28, 0x10(r1)
/* 800FA9B0 000F77B0  3B 80 00 00 */	li r28, 0x0
/* 800FA9B4 000F77B4  80 04 03 1C */	lwz r0, 0x31c(r4)
/* 800FA9B8 000F77B8  80 AD 05 EC */	lwz r5, lbl_805DD6CC@sda21(r0)
/* 800FA9BC 000F77BC  7C 09 03 A6 */	mtctr r0
/* 800FA9C0 000F77C0  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FA9C4 000F77C4  40 81 00 3C */	ble .L_800FAA00
.L_800FA9C8:
/* 800FA9C8 000F77C8  80 66 00 58 */	lwz r3, 0x58(r6)
/* 800FA9CC 000F77CC  80 06 00 5C */	lwz r0, 0x5c(r6)
/* 800FA9D0 000F77D0  1C 63 01 40 */	mulli r3, r3, 0x140
/* 800FA9D4 000F77D4  80 85 00 74 */	lwz r4, 0x74(r5)
/* 800FA9D8 000F77D8  1C 00 00 24 */	mulli r0, r0, 0x24
/* 800FA9DC 000F77DC  7C 63 02 14 */	add r3, r3, r0
/* 800FA9E0 000F77E0  38 03 00 24 */	addi r0, r3, 0x24
/* 800FA9E4 000F77E4  7C 04 00 2E */	lwzx r0, r4, r0
/* 800FA9E8 000F77E8  54 00 01 FE */	clrlwi r0, r0, 7
/* 800FA9EC 000F77EC  2C 00 00 18 */	cmpwi r0, 0x18
/* 800FA9F0 000F77F0  40 82 00 08 */	bne .L_800FA9F8
/* 800FA9F4 000F77F4  3B 86 00 60 */	addi r28, r6, 0x60
.L_800FA9F8:
/* 800FA9F8 000F77F8  38 C6 00 20 */	addi r6, r6, 0x20
/* 800FA9FC 000F77FC  42 00 FF CC */	bdnz .L_800FA9C8
.L_800FAA00:
/* 800FAA00 000F7800  28 1C 00 00 */	cmplwi r28, 0x0
/* 800FAA04 000F7804  41 82 00 64 */	beq .L_800FAA68
/* 800FAA08 000F7808  3B A0 00 00 */	li r29, 0x0
/* 800FAA0C 000F780C  7F FE FB 78 */	mr r30, r31
.L_800FAA10:
/* 800FAA10 000F7810  38 7E 01 34 */	addi r3, r30, 0x134
/* 800FAA14 000F7814  4B FE F7 BD */	bl kar_graudio_is_active_fgm_slot_playing
/* 800FAA18 000F7818  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FAA1C 000F781C  40 82 00 3C */	bne .L_800FAA58
/* 800FAA20 000F7820  1F DD 00 14 */	mulli r30, r29, 0x14
/* 800FAA24 000F7824  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800FAA28 000F7828  7F 85 E3 78 */	mr r5, r28
/* 800FAA2C 000F782C  80 C3 00 14 */	lwz r6, 0x14(r3)
/* 800FAA30 000F7830  7C 9F F2 14 */	add r4, r31, r30
/* 800FAA34 000F7834  80 66 00 0C */	lwz r3, 0xc(r6)
/* 800FAA38 000F7838  80 84 01 40 */	lwz r4, 0x140(r4)
/* 800FAA3C 000F783C  C0 26 00 10 */	lfs f1, 0x10(r6)
/* 800FAA40 000F7840  4B FE F5 11 */	bl kar_graudio_configure_fgm_track_mode
/* 800FAA44 000F7844  38 7E 01 34 */	addi r3, r30, 0x134
/* 800FAA48 000F7848  38 80 00 00 */	li r4, 0x0
/* 800FAA4C 000F784C  7C 7F 1A 14 */	add r3, r31, r3
/* 800FAA50 000F7850  4B FE F6 35 */	bl kar_graudio_play_fgm_entry_id
/* 800FAA54 000F7854  48 00 00 14 */	b .L_800FAA68
.L_800FAA58:
/* 800FAA58 000F7858  3B BD 00 01 */	addi r29, r29, 0x1
/* 800FAA5C 000F785C  3B DE 00 14 */	addi r30, r30, 0x14
/* 800FAA60 000F7860  2C 1D 00 04 */	cmpwi r29, 0x4
/* 800FAA64 000F7864  41 80 FF AC */	blt .L_800FAA10
.L_800FAA68:
/* 800FAA68 000F7868  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FAA6C 000F786C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800FAA70 000F7870  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800FAA74 000F7874  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800FAA78 000F7878  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800FAA7C 000F787C  7C 08 03 A6 */	mtlr r0
/* 800FAA80 000F7880  38 21 00 20 */	addi r1, r1, 0x20
/* 800FAA84 000F7884  4E 80 00 20 */	blr
.endfn kar_gryakucatchzone_play_contact_fgm_at_report

# .text:0x6C8 | 0x800FAA88 | size: 0x10
.fn kar_gryakucatchzone_is_contact_flag_set, global
/* 800FAA88 000F7888  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FAA8C 000F788C  88 03 01 84 */	lbz r0, 0x184(r3)
/* 800FAA90 000F7890  54 03 CF FE */	extrwi r3, r0, 1, 24
/* 800FAA94 000F7894  4E 80 00 20 */	blr
.endfn kar_gryakucatchzone_is_contact_flag_set

# .text:0x6D8 | 0x800FAA98 | size: 0x48
.fn kar_gryakucatchzone_create_secondary_kind20_event_yaku, global
/* 800FAA98 000F7898  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800FAA9C 000F789C  7C 08 02 A6 */	mflr r0
/* 800FAAA0 000F78A0  38 60 00 14 */	li r3, 0x14
/* 800FAAA4 000F78A4  90 01 00 24 */	stw r0, 0x24(r1)
/* 800FAAA8 000F78A8  DB E1 00 18 */	stfd f31, 0x18(r1)
/* 800FAAAC 000F78AC  FF E0 08 90 */	fmr f31, f1
/* 800FAAB0 000F78B0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800FAAB4 000F78B4  7C BF 2B 78 */	mr r31, r5
/* 800FAAB8 000F78B8  4B FF 9E 15 */	bl kar_gryaku_create_yaku_from_secondary_kind
/* 800FAABC 000F78BC  FC 20 F8 90 */	fmr f1, f31
/* 800FAAC0 000F78C0  7F E4 FB 78 */	mr r4, r31
/* 800FAAC4 000F78C4  48 00 00 1D */	bl kar_gryakucatchzone_init_secondary_kind20_event_yaku
/* 800FAAC8 000F78C8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FAACC 000F78CC  CB E1 00 18 */	lfd f31, 0x18(r1)
/* 800FAAD0 000F78D0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800FAAD4 000F78D4  7C 08 03 A6 */	mtlr r0
/* 800FAAD8 000F78D8  38 21 00 20 */	addi r1, r1, 0x20
/* 800FAADC 000F78DC  4E 80 00 20 */	blr
.endfn kar_gryakucatchzone_create_secondary_kind20_event_yaku

# .text:0x720 | 0x800FAAE0 | size: 0x108
.fn kar_gryakucatchzone_init_secondary_kind20_event_yaku, global
/* 800FAAE0 000F78E0  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800FAAE4 000F78E4  7C 08 02 A6 */	mflr r0
/* 800FAAE8 000F78E8  90 01 00 34 */	stw r0, 0x34(r1)
/* 800FAAEC 000F78EC  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 800FAAF0 000F78F0  F3 E1 00 28 */	psq_st f31, 0x28(r1), 0, qr0
/* 800FAAF4 000F78F4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800FAAF8 000F78F8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800FAAFC 000F78FC  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800FAB00 000F7900  93 81 00 10 */	stw r28, 0x10(r1)
/* 800FAB04 000F7904  7C 7C 1B 78 */	mr r28, r3
/* 800FAB08 000F7908  FF E0 08 90 */	fmr f31, f1
/* 800FAB0C 000F790C  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800FAB10 000F7910  7C 9D 23 78 */	mr r29, r4
/* 800FAB14 000F7914  38 A0 00 00 */	li r5, 0x0
/* 800FAB18 000F7918  80 DF 00 08 */	lwz r6, 0x8(r31)
/* 800FAB1C 000F791C  38 7F 00 1C */	addi r3, r31, 0x1c
/* 800FAB20 000F7920  80 9F 00 64 */	lwz r4, 0x64(r31)
/* 800FAB24 000F7924  83 C6 00 00 */	lwz r30, 0x0(r6)
/* 800FAB28 000F7928  80 1E 00 04 */	lwz r0, 0x4(r30)
/* 800FAB2C 000F792C  54 00 18 38 */	slwi r0, r0, 3
/* 800FAB30 000F7930  7C 84 00 2E */	lwzx r4, r4, r0
/* 800FAB34 000F7934  4B FD CE 8D */	bl kar_grcoll__800d79c0
/* 800FAB38 000F7938  90 7F 01 30 */	stw r3, 0x130(r31)
/* 800FAB3C 000F793C  FC 40 F8 90 */	fmr f2, f31
/* 800FAB40 000F7940  C0 22 91 D0 */	lfs f1, lbl_805DF8D0@sda21(r0)
/* 800FAB44 000F7944  7F 83 E3 78 */	mr r3, r28
/* 800FAB48 000F7948  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 800FAB4C 000F794C  7F A4 EB 78 */	mr r4, r29
/* 800FAB50 000F7950  80 BF 01 30 */	lwz r5, 0x130(r31)
/* 800FAB54 000F7954  90 05 01 38 */	stw r0, 0x138(r5)
/* 800FAB58 000F7958  80 BE 00 30 */	lwz r5, 0x30(r30)
/* 800FAB5C 000F795C  80 A5 00 10 */	lwz r5, 0x10(r5)
/* 800FAB60 000F7960  4B FF DC F5 */	bl kar_gryakucommon_sync_jobj_to_eventpos_matrix
/* 800FAB64 000F7964  80 9E 00 30 */	lwz r4, 0x30(r30)
/* 800FAB68 000F7968  38 60 00 00 */	li r3, 0x0
/* 800FAB6C 000F796C  C0 04 00 00 */	lfs f0, 0x0(r4)
/* 800FAB70 000F7970  D0 1F 01 34 */	stfs f0, 0x134(r31)
/* 800FAB74 000F7974  88 1F 01 58 */	lbz r0, 0x158(r31)
/* 800FAB78 000F7978  50 60 3E 30 */	rlwimi r0, r3, 7, 24, 24
/* 800FAB7C 000F797C  98 1F 01 58 */	stb r0, 0x158(r31)
/* 800FAB80 000F7980  90 7F 01 44 */	stw r3, 0x144(r31)
/* 800FAB84 000F7984  90 7F 01 40 */	stw r3, 0x140(r31)
/* 800FAB88 000F7988  90 7F 01 4C */	stw r3, 0x14c(r31)
/* 800FAB8C 000F798C  90 7F 01 48 */	stw r3, 0x148(r31)
/* 800FAB90 000F7990  90 7F 01 54 */	stw r3, 0x154(r31)
/* 800FAB94 000F7994  90 7F 01 50 */	stw r3, 0x150(r31)
/* 800FAB98 000F7998  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800FAB9C 000F799C  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800FABA0 000F79A0  28 00 00 00 */	cmplwi r0, 0x0
/* 800FABA4 000F79A4  41 82 00 14 */	beq .L_800FABB8
/* 800FABA8 000F79A8  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 800FABAC 000F79AC  7F 83 E3 78 */	mr r3, r28
/* 800FABB0 000F79B0  38 A0 00 01 */	li r5, 0x1
/* 800FABB4 000F79B4  4B FF CC BD */	bl kar_gryakuaudio_configure_fgm_track_from_joint
.L_800FABB8:
/* 800FABB8 000F79B8  7F 83 E3 78 */	mr r3, r28
/* 800FABBC 000F79BC  48 00 00 2D */	bl kar_gryakucatchzone_start_secondary_kind20_motion
/* 800FABC0 000F79C0  E3 E1 00 28 */	psq_l f31, 0x28(r1), 0, qr0
/* 800FABC4 000F79C4  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800FABC8 000F79C8  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 800FABCC 000F79CC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800FABD0 000F79D0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800FABD4 000F79D4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800FABD8 000F79D8  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800FABDC 000F79DC  7C 08 03 A6 */	mtlr r0
/* 800FABE0 000F79E0  38 21 00 30 */	addi r1, r1, 0x30
/* 800FABE4 000F79E4  4E 80 00 20 */	blr
.endfn kar_gryakucatchzone_init_secondary_kind20_event_yaku

# .text:0x828 | 0x800FABE8 | size: 0x74
.fn kar_gryakucatchzone_start_secondary_kind20_motion, global
/* 800FABE8 000F79E8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FABEC 000F79EC  7C 08 02 A6 */	mflr r0
/* 800FABF0 000F79F0  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FABF4 000F79F4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FABF8 000F79F8  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800FABFC 000F79FC  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800FAC00 000F7A00  80 1F 01 1C */	lwz r0, 0x11c(r31)
/* 800FAC04 000F7A04  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800FAC08 000F7A08  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FAC0C 000F7A0C  83 C3 00 00 */	lwz r30, 0x0(r3)
/* 800FAC10 000F7A10  40 81 00 10 */	ble .L_800FAC20
/* 800FAC14 000F7A14  38 7F 01 18 */	addi r3, r31, 0x118
/* 800FAC18 000F7A18  38 80 00 00 */	li r4, 0x0
/* 800FAC1C 000F7A1C  4B FE F4 69 */	bl kar_graudio_play_fgm_entry_id
.L_800FAC20:
/* 800FAC20 000F7A20  C0 22 91 D4 */	lfs f1, lbl_805DF8D4@sda21(r0)
/* 800FAC24 000F7A24  7F E3 FB 78 */	mr r3, r31
/* 800FAC28 000F7A28  80 BE 00 0C */	lwz r5, 0xc(r30)
/* 800FAC2C 000F7A2C  38 80 00 00 */	li r4, 0x0
/* 800FAC30 000F7A30  FC 60 08 90 */	fmr f3, f1
/* 800FAC34 000F7A34  C0 42 91 D8 */	lfs f2, lbl_805DF8D8@sda21(r0)
/* 800FAC38 000F7A38  38 C0 FF FF */	li r6, -0x1
/* 800FAC3C 000F7A3C  38 E0 00 00 */	li r7, 0x0
/* 800FAC40 000F7A40  4B FF A9 09 */	bl kar_gryaku_set_path_node_motion
/* 800FAC44 000F7A44  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FAC48 000F7A48  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FAC4C 000F7A4C  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800FAC50 000F7A50  7C 08 03 A6 */	mtlr r0
/* 800FAC54 000F7A54  38 21 00 10 */	addi r1, r1, 0x10
/* 800FAC58 000F7A58  4E 80 00 20 */	blr
.endfn kar_gryakucatchzone_start_secondary_kind20_motion

# .text:0x89C | 0x800FAC5C | size: 0x40
.fn kar_gryakucatchzone_get_entry_offset_c_float, global
/* 800FAC5C 000F7A5C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FAC60 000F7A60  7C 08 02 A6 */	mflr r0
/* 800FAC64 000F7A64  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FAC68 000F7A68  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FAC6C 000F7A6C  7C 7F 1B 79 */	mr. r31, r3
/* 800FAC70 000F7A70  40 82 00 14 */	bne .L_800FAC84
/* 800FAC74 000F7A74  38 6D 91 44 */	li r3, kar_srcfile_aobj_h_805d6224@sda21
/* 800FAC78 000F7A78  38 80 00 AB */	li r4, 0xab
/* 800FAC7C 000F7A7C  38 AD 91 4C */	li r5, lbl_805D622C@sda21
/* 800FAC80 000F7A80  48 32 D8 39 */	bl __assert
.L_800FAC84:
/* 800FAC84 000F7A84  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FAC88 000F7A88  C0 3F 00 0C */	lfs f1, 0xc(r31)
/* 800FAC8C 000F7A8C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FAC90 000F7A90  7C 08 03 A6 */	mtlr r0
/* 800FAC94 000F7A94  38 21 00 10 */	addi r1, r1, 0x10
/* 800FAC98 000F7A98  4E 80 00 20 */	blr
.endfn kar_gryakucatchzone_get_entry_offset_c_float
