.include "macros.inc"
.file "mpcoll.c"

# 0x80241428..0x8024178C | size: 0x364
.text
.balign 4

# .text:0x0 | 0x80241428 | size: 0xAC
.fn kar_mpcoll_free_handle, global
/* 80241428 0023E228  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8024142C 0023E22C  7C 08 02 A6 */	mflr r0
/* 80241430 0023E230  90 01 00 14 */	stw r0, 0x14(r1)
/* 80241434 0023E234  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80241438 0023E238  7C 7F 1B 78 */	mr r31, r3
/* 8024143C 0023E23C  80 0D 07 E4 */	lwz r0, lbl_805DD8C4@sda21(r0)
/* 80241440 0023E240  7C 00 F8 40 */	cmplw r0, r31
/* 80241444 0023E244  40 82 00 10 */	bne .L_80241454
/* 80241448 0023E248  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 8024144C 0023E24C  90 0D 07 E4 */	stw r0, lbl_805DD8C4@sda21(r0)
/* 80241450 0023E250  48 00 00 58 */	b .L_802414A8
.L_80241454:
/* 80241454 0023E254  7C 03 03 78 */	mr r3, r0
/* 80241458 0023E258  48 00 00 20 */	b .L_80241478
.L_8024145C:
/* 8024145C 0023E25C  80 03 00 00 */	lwz r0, 0x0(r3)
/* 80241460 0023E260  7C 00 F8 40 */	cmplw r0, r31
/* 80241464 0023E264  40 82 00 10 */	bne .L_80241474
/* 80241468 0023E268  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 8024146C 0023E26C  90 03 00 00 */	stw r0, 0x0(r3)
/* 80241470 0023E270  48 00 00 38 */	b .L_802414A8
.L_80241474:
/* 80241474 0023E274  7C 03 03 78 */	mr r3, r0
.L_80241478:
/* 80241478 0023E278  28 03 00 00 */	cmplwi r3, 0x0
/* 8024147C 0023E27C  40 82 FF E0 */	bne .L_8024145C
/* 80241480 0023E280  3C 60 80 4B */	lis r3, kar_mpcoll_report_free_not_found_fmt@ha
/* 80241484 0023E284  7F E4 FB 78 */	mr r4, r31
/* 80241488 0023E288  38 63 56 68 */	addi r3, r3, kar_mpcoll_report_free_not_found_fmt@l
/* 8024148C 0023E28C  4C C6 31 82 */	crclr cr1eq
/* 80241490 0023E290  48 19 38 59 */	bl OSReport
/* 80241494 0023E294  3C 60 80 4B */	lis r3, kar_src_mpcoll_c@ha
/* 80241498 0023E298  38 80 01 16 */	li r4, 0x116
/* 8024149C 0023E29C  38 63 56 88 */	addi r3, r3, kar_src_mpcoll_c@l
/* 802414A0 0023E2A0  38 AD A2 50 */	li r5, lbl_805D7330@sda21
/* 802414A4 0023E2A4  48 1E 70 15 */	bl __assert
.L_802414A8:
/* 802414A8 0023E2A8  80 7F 00 44 */	lwz r3, 0x44(r31)
/* 802414AC 0023E2AC  48 00 02 61 */	bl kar_mpcoll_free_report
/* 802414B0 0023E2B0  3C 60 80 56 */	lis r3, kar_mpcoll_handle_pool@ha
/* 802414B4 0023E2B4  7F E4 FB 78 */	mr r4, r31
/* 802414B8 0023E2B8  38 63 DB C8 */	addi r3, r3, kar_mpcoll_handle_pool@l
/* 802414BC 0023E2BC  48 1D 6D 79 */	bl HSD_ObjFree
/* 802414C0 0023E2C0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802414C4 0023E2C4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802414C8 0023E2C8  7C 08 03 A6 */	mtlr r0
/* 802414CC 0023E2CC  38 21 00 10 */	addi r1, r1, 0x10
/* 802414D0 0023E2D0  4E 80 00 20 */	blr
.endfn kar_mpcoll_free_handle

# .text:0xAC | 0x802414D4 | size: 0x8
.fn kar_mpcoll_get_active_list_head, global
/* 802414D4 0023E2D4  80 6D 07 E4 */	lwz r3, lbl_805DD8C4@sda21(r0)
/* 802414D8 0023E2D8  4E 80 00 20 */	blr
.endfn kar_mpcoll_get_active_list_head

# .text:0xB4 | 0x802414DC | size: 0x98
.fn kar_mpcoll_apply_sphere_motion_response, global
/* 802414DC 0023E2DC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 802414E0 0023E2E0  7C 08 02 A6 */	mflr r0
/* 802414E4 0023E2E4  90 01 00 24 */	stw r0, 0x24(r1)
/* 802414E8 0023E2E8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 802414EC 0023E2EC  7C 7F 1B 78 */	mr r31, r3
/* 802414F0 0023E2F0  80 03 03 3C */	lwz r0, 0x33c(r3)
/* 802414F4 0023E2F4  2C 00 00 00 */	cmpwi r0, 0x0
/* 802414F8 0023E2F8  41 82 00 1C */	beq .L_80241514
/* 802414FC 0023E2FC  3C 60 80 4B */	lis r3, kar_src_mpcoll_h@ha
/* 80241500 0023E300  3C A0 80 4B */	lis r5, kar_mpcoll_assert_shape_is_sphere@ha
/* 80241504 0023E304  38 63 56 94 */	addi r3, r3, kar_src_mpcoll_h@l
/* 80241508 0023E308  38 80 00 F9 */	li r4, 0xf9
/* 8024150C 0023E30C  38 A5 56 A0 */	addi r5, r5, kar_mpcoll_assert_shape_is_sphere@l
/* 80241510 0023E310  48 1E 6F A9 */	bl __assert
.L_80241514:
/* 80241514 0023E314  C0 3F 00 08 */	lfs f1, 0x8(r31)
/* 80241518 0023E318  38 7F 00 08 */	addi r3, r31, 0x8
/* 8024151C 0023E31C  C0 1F 00 14 */	lfs f0, 0x14(r31)
/* 80241520 0023E320  38 81 00 08 */	addi r4, r1, 0x8
/* 80241524 0023E324  80 DF 03 40 */	lwz r6, 0x340(r31)
/* 80241528 0023E328  38 BF 00 2C */	addi r5, r31, 0x2c
/* 8024152C 0023E32C  EC 01 00 2A */	fadds f0, f1, f0
/* 80241530 0023E330  D0 01 00 08 */	stfs f0, 0x8(r1)
/* 80241534 0023E334  C0 3F 00 0C */	lfs f1, 0xc(r31)
/* 80241538 0023E338  C0 1F 00 18 */	lfs f0, 0x18(r31)
/* 8024153C 0023E33C  EC 01 00 2A */	fadds f0, f1, f0
/* 80241540 0023E340  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 80241544 0023E344  C0 3F 00 10 */	lfs f1, 0x10(r31)
/* 80241548 0023E348  C0 1F 00 1C */	lfs f0, 0x1c(r31)
/* 8024154C 0023E34C  EC 01 00 2A */	fadds f0, f1, f0
/* 80241550 0023E350  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 80241554 0023E354  C0 26 00 30 */	lfs f1, 0x30(r6)
/* 80241558 0023E358  C0 46 00 34 */	lfs f2, 0x34(r6)
/* 8024155C 0023E35C  48 00 94 65 */	bl kar_mpresponse_build_swept_sphere_aabb_center_extents
/* 80241560 0023E360  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80241564 0023E364  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80241568 0023E368  7C 08 03 A6 */	mtlr r0
/* 8024156C 0023E36C  38 21 00 20 */	addi r1, r1, 0x20
/* 80241570 0023E370  4E 80 00 20 */	blr
.endfn kar_mpcoll_apply_sphere_motion_response

# .text:0x14C | 0x80241574 | size: 0x34
.fn kar_mpcoll_check_special_face_kind3_enabled, global
/* 80241574 0023E374  88 03 03 4C */	lbz r0, 0x34c(r3)
/* 80241578 0023E378  38 60 00 00 */	li r3, 0x0
/* 8024157C 0023E37C  54 00 F7 FF */	extrwi. r0, r0, 1, 29
/* 80241580 0023E380  4D 82 00 20 */	beqlr
/* 80241584 0023E384  80 84 00 08 */	lwz r4, 0x8(r4)
/* 80241588 0023E388  54 A0 30 32 */	slwi r0, r5, 6
/* 8024158C 0023E38C  7C 84 02 14 */	add r4, r4, r0
/* 80241590 0023E390  80 84 00 38 */	lwz r4, 0x38(r4)
/* 80241594 0023E394  80 04 00 8C */	lwz r0, 0x8c(r4)
/* 80241598 0023E398  2C 00 00 03 */	cmpwi r0, 0x3
/* 8024159C 0023E39C  4C 82 00 20 */	bnelr
/* 802415A0 0023E3A0  38 60 00 01 */	li r3, 0x1
/* 802415A4 0023E3A4  4E 80 00 20 */	blr
.endfn kar_mpcoll_check_special_face_kind3_enabled

# .text:0x180 | 0x802415A8 | size: 0xF0
.fn kar_mpcoll_lerp_sphere_radius, global
/* 802415A8 0023E3A8  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 802415AC 0023E3AC  7C 08 02 A6 */	mflr r0
/* 802415B0 0023E3B0  90 01 00 34 */	stw r0, 0x34(r1)
/* 802415B4 0023E3B4  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 802415B8 0023E3B8  F3 E1 00 28 */	psq_st f31, 0x28(r1), 0, qr0
/* 802415BC 0023E3BC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 802415C0 0023E3C0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 802415C4 0023E3C4  7C 7E 1B 78 */	mr r30, r3
/* 802415C8 0023E3C8  FF E0 08 90 */	fmr f31, f1
/* 802415CC 0023E3CC  80 03 03 3C */	lwz r0, 0x33c(r3)
/* 802415D0 0023E3D0  2C 00 00 00 */	cmpwi r0, 0x0
/* 802415D4 0023E3D4  41 82 00 1C */	beq .L_802415F0
/* 802415D8 0023E3D8  3C 60 80 4B */	lis r3, kar_src_mpcoll_h@ha
/* 802415DC 0023E3DC  3C A0 80 4B */	lis r5, kar_mpcoll_assert_shape_is_sphere@ha
/* 802415E0 0023E3E0  38 63 56 94 */	addi r3, r3, kar_src_mpcoll_h@l
/* 802415E4 0023E3E4  38 80 00 F9 */	li r4, 0xf9
/* 802415E8 0023E3E8  38 A5 56 A0 */	addi r5, r5, kar_mpcoll_assert_shape_is_sphere@l
/* 802415EC 0023E3EC  48 1E 6E CD */	bl __assert
.L_802415F0:
/* 802415F0 0023E3F0  80 1E 03 3C */	lwz r0, 0x33c(r30)
/* 802415F4 0023E3F4  83 FE 03 40 */	lwz r31, 0x340(r30)
/* 802415F8 0023E3F8  2C 00 00 00 */	cmpwi r0, 0x0
/* 802415FC 0023E3FC  41 82 00 1C */	beq .L_80241618
/* 80241600 0023E400  3C 60 80 4B */	lis r3, kar_src_mpcoll_h@ha
/* 80241604 0023E404  3C A0 80 4B */	lis r5, kar_mpcoll_assert_shape_is_sphere@ha
/* 80241608 0023E408  38 63 56 94 */	addi r3, r3, kar_src_mpcoll_h@l
/* 8024160C 0023E40C  38 80 00 F9 */	li r4, 0xf9
/* 80241610 0023E410  38 A5 56 A0 */	addi r5, r5, kar_mpcoll_assert_shape_is_sphere@l
/* 80241614 0023E414  48 1E 6E A5 */	bl __assert
.L_80241618:
/* 80241618 0023E418  80 7E 03 40 */	lwz r3, 0x340(r30)
/* 8024161C 0023E41C  C0 23 00 30 */	lfs f1, 0x30(r3)
/* 80241620 0023E420  C0 03 00 34 */	lfs f0, 0x34(r3)
/* 80241624 0023E424  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 80241628 0023E428  7C 60 00 26 */	mfcr r3
/* 8024162C 0023E42C  3C 00 43 30 */	lis r0, 0x4330
/* 80241630 0023E430  54 63 1F FE */	extrwi r3, r3, 1, 2
/* 80241634 0023E434  90 01 00 08 */	stw r0, 0x8(r1)
/* 80241638 0023E438  7C 60 00 34 */	cntlzw r0, r3
/* 8024163C 0023E43C  C8 42 C4 40 */	lfd f2, lbl_805E2B40@sda21(r0)
/* 80241640 0023E440  54 00 D9 7E */	srwi r0, r0, 5
/* 80241644 0023E444  C0 02 C4 38 */	lfs f0, lbl_805E2B38@sda21(r0)
/* 80241648 0023E448  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 8024164C 0023E44C  90 01 00 0C */	stw r0, 0xc(r1)
/* 80241650 0023E450  C8 21 00 08 */	lfd f1, 0x8(r1)
/* 80241654 0023E454  EC 21 10 28 */	fsubs f1, f1, f2
/* 80241658 0023E458  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 8024165C 0023E45C  41 82 00 18 */	beq .L_80241674
/* 80241660 0023E460  C0 3F 00 30 */	lfs f1, 0x30(r31)
/* 80241664 0023E464  C0 1F 00 34 */	lfs f0, 0x34(r31)
/* 80241668 0023E468  EC 00 08 28 */	fsubs f0, f0, f1
/* 8024166C 0023E46C  EC 3F 08 3A */	fmadds f1, f31, f0, f1
/* 80241670 0023E470  48 00 00 08 */	b .L_80241678
.L_80241674:
/* 80241674 0023E474  C0 3F 00 30 */	lfs f1, 0x30(r31)
.L_80241678:
/* 80241678 0023E478  E3 E1 00 28 */	psq_l f31, 0x28(r1), 0, qr0
/* 8024167C 0023E47C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80241680 0023E480  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 80241684 0023E484  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80241688 0023E488  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8024168C 0023E48C  7C 08 03 A6 */	mtlr r0
/* 80241690 0023E490  38 21 00 30 */	addi r1, r1, 0x30
/* 80241694 0023E494  4E 80 00 20 */	blr
.endfn kar_mpcoll_lerp_sphere_radius

# .text:0x270 | 0x80241698 | size: 0x34
.fn kar_mpcoll_init_report_pool, global
/* 80241698 0023E498  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8024169C 0023E49C  7C 08 02 A6 */	mflr r0
/* 802416A0 0023E4A0  3C 60 80 56 */	lis r3, kar_mpcoll_report_pool@ha
/* 802416A4 0023E4A4  38 80 01 E0 */	li r4, 0x1e0
/* 802416A8 0023E4A8  90 01 00 14 */	stw r0, 0x14(r1)
/* 802416AC 0023E4AC  38 63 DC 78 */	addi r3, r3, kar_mpcoll_report_pool@l
/* 802416B0 0023E4B0  38 A0 00 04 */	li r5, 0x4
/* 802416B4 0023E4B4  48 1D 6B A9 */	bl HSD_ObjAllocInit
/* 802416B8 0023E4B8  48 00 00 91 */	bl kar_mpcoll_init_report_subpools
/* 802416BC 0023E4BC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802416C0 0023E4C0  7C 08 03 A6 */	mtlr r0
/* 802416C4 0023E4C4  38 21 00 10 */	addi r1, r1, 0x10
/* 802416C8 0023E4C8  4E 80 00 20 */	blr
.endfn kar_mpcoll_init_report_pool

# .text:0x2A4 | 0x802416CC | size: 0x40
.fn kar_mpcoll_alloc_report, global
/* 802416CC 0023E4CC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802416D0 0023E4D0  7C 08 02 A6 */	mflr r0
/* 802416D4 0023E4D4  3C 60 80 56 */	lis r3, kar_mpcoll_report_pool@ha
/* 802416D8 0023E4D8  90 01 00 14 */	stw r0, 0x14(r1)
/* 802416DC 0023E4DC  38 63 DC 78 */	addi r3, r3, kar_mpcoll_report_pool@l
/* 802416E0 0023E4E0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802416E4 0023E4E4  48 1D 6A 01 */	bl HSD_ObjAlloc
/* 802416E8 0023E4E8  38 80 00 01 */	li r4, 0x1
/* 802416EC 0023E4EC  7C 7F 1B 78 */	mr r31, r3
/* 802416F0 0023E4F0  48 00 00 9D */	bl kar_mpcollreport_alloc_contact_lists
/* 802416F4 0023E4F4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802416F8 0023E4F8  7F E3 FB 78 */	mr r3, r31
/* 802416FC 0023E4FC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80241700 0023E500  7C 08 03 A6 */	mtlr r0
/* 80241704 0023E504  38 21 00 10 */	addi r1, r1, 0x10
/* 80241708 0023E508  4E 80 00 20 */	blr
.endfn kar_mpcoll_alloc_report

# .text:0x2E4 | 0x8024170C | size: 0x3C
.fn kar_mpcoll_free_report, global
/* 8024170C 0023E50C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80241710 0023E510  7C 08 02 A6 */	mflr r0
/* 80241714 0023E514  90 01 00 14 */	stw r0, 0x14(r1)
/* 80241718 0023E518  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8024171C 0023E51C  7C 7F 1B 78 */	mr r31, r3
/* 80241720 0023E520  48 00 12 B1 */	bl kar_mpcollreport_free_contact_lists
/* 80241724 0023E524  3C 60 80 56 */	lis r3, kar_mpcoll_report_pool@ha
/* 80241728 0023E528  7F E4 FB 78 */	mr r4, r31
/* 8024172C 0023E52C  38 63 DC 78 */	addi r3, r3, kar_mpcoll_report_pool@l
/* 80241730 0023E530  48 1D 6B 05 */	bl HSD_ObjFree
/* 80241734 0023E534  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80241738 0023E538  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8024173C 0023E53C  7C 08 03 A6 */	mtlr r0
/* 80241740 0023E540  38 21 00 10 */	addi r1, r1, 0x10
/* 80241744 0023E544  4E 80 00 20 */	blr
.endfn kar_mpcoll_free_report

# .text:0x320 | 0x80241748 | size: 0x44
.fn kar_mpcoll_init_report_subpools, global
/* 80241748 0023E548  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8024174C 0023E54C  7C 08 02 A6 */	mflr r0
/* 80241750 0023E550  3C 60 80 56 */	lis r3, kar_mpcoll_report_subentry_pool@ha
/* 80241754 0023E554  38 80 00 2C */	li r4, 0x2c
/* 80241758 0023E558  90 01 00 14 */	stw r0, 0x14(r1)
/* 8024175C 0023E55C  38 63 DC D0 */	addi r3, r3, kar_mpcoll_report_subentry_pool@l
/* 80241760 0023E560  38 A0 00 04 */	li r5, 0x4
/* 80241764 0023E564  48 1D 6A F9 */	bl HSD_ObjAllocInit
/* 80241768 0023E568  3C 60 80 56 */	lis r3, kar_mpcoll_report_detail_pool@ha
/* 8024176C 0023E56C  38 80 03 70 */	li r4, 0x370
/* 80241770 0023E570  38 63 DC A4 */	addi r3, r3, kar_mpcoll_report_detail_pool@l
/* 80241774 0023E574  38 A0 00 04 */	li r5, 0x4
/* 80241778 0023E578  48 1D 6A E5 */	bl HSD_ObjAllocInit
/* 8024177C 0023E57C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80241780 0023E580  7C 08 03 A6 */	mtlr r0
/* 80241784 0023E584  38 21 00 10 */	addi r1, r1, 0x10
/* 80241788 0023E588  4E 80 00 20 */	blr
.endfn kar_mpcoll_init_report_subpools
