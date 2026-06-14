.include "macros.inc"
.file "gryakugondola.c"

# 0x800FE5D4..0x800FEE40 | size: 0x86C
.text
.balign 4

# .text:0x0 | 0x800FE5D4 | size: 0x38
.fn kar_gryakugondola_create_stage_linked_kind46_carrier_yaku, global
/* 800FE5D4 000FB3D4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FE5D8 000FB3D8  7C 08 02 A6 */	mflr r0
/* 800FE5DC 000FB3DC  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FE5E0 000FB3E0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FE5E4 000FB3E4  7C 7F 1B 78 */	mr r31, r3
/* 800FE5E8 000FB3E8  38 60 00 2E */	li r3, 0x2e
/* 800FE5EC 000FB3EC  4B FF 5E 81 */	bl kar_gryaku_create_yaku_from_main_kind
/* 800FE5F0 000FB3F0  7F E4 FB 78 */	mr r4, r31
/* 800FE5F4 000FB3F4  48 00 00 19 */	bl kar_gryakugondola_init_stage_linked_kind46_carrier_yaku
/* 800FE5F8 000FB3F8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FE5FC 000FB3FC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FE600 000FB400  7C 08 03 A6 */	mtlr r0
/* 800FE604 000FB404  38 21 00 10 */	addi r1, r1, 0x10
/* 800FE608 000FB408  4E 80 00 20 */	blr
.endfn kar_gryakugondola_create_stage_linked_kind46_carrier_yaku

# .text:0x38 | 0x800FE60C | size: 0x8C
.fn kar_gryakugondola_init_stage_linked_kind46_carrier_yaku, global
/* 800FE60C 000FB40C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FE610 000FB410  7C 08 02 A6 */	mflr r0
/* 800FE614 000FB414  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FE618 000FB418  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FE61C 000FB41C  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800FE620 000FB420  7C 7E 1B 78 */	mr r30, r3
/* 800FE624 000FB424  83 FE 00 2C */	lwz r31, 0x2c(r30)
/* 800FE628 000FB428  80 64 00 2C */	lwz r3, 0x2c(r4)
/* 800FE62C 000FB42C  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 800FE630 000FB430  38 BF 01 38 */	addi r5, r31, 0x138
/* 800FE634 000FB434  80 C3 01 04 */	lwz r6, 0x104(r3)
/* 800FE638 000FB438  80 84 00 00 */	lwz r4, 0x0(r4)
/* 800FE63C 000FB43C  80 ED 05 EC */	lwz r7, lbl_805DD6CC@sda21(r0)
/* 800FE640 000FB440  80 04 00 0C */	lwz r0, 0xc(r4)
/* 800FE644 000FB444  38 67 00 54 */	addi r3, r7, 0x54
/* 800FE648 000FB448  54 00 18 38 */	slwi r0, r0, 3
/* 800FE64C 000FB44C  7C 86 00 2E */	lwzx r4, r6, r0
/* 800FE650 000FB450  4B FD 93 71 */	bl kar_grcoll__800d79c0
/* 800FE654 000FB454  38 A0 00 00 */	li r5, 0x0
/* 800FE658 000FB458  3C 60 80 5E */	lis r3, lbl_805DC8BC@ha
/* 800FE65C 000FB45C  90 BF 01 30 */	stw r5, 0x130(r31)
/* 800FE660 000FB460  38 83 C8 BC */	addi r4, r3, lbl_805DC8BC@l
/* 800FE664 000FB464  7F C3 F3 78 */	mr r3, r30
/* 800FE668 000FB468  C0 04 00 00 */	lfs f0, 0x0(r4)
/* 800FE66C 000FB46C  D0 1F 01 34 */	stfs f0, 0x134(r31)
/* 800FE670 000FB470  88 1F 01 3C */	lbz r0, 0x13c(r31)
/* 800FE674 000FB474  50 A0 3E 30 */	rlwimi r0, r5, 7, 24, 24
/* 800FE678 000FB478  98 1F 01 3C */	stb r0, 0x13c(r31)
/* 800FE67C 000FB47C  48 00 00 1D */	bl kar_gryakugondola_start_kind46_idle_motion
/* 800FE680 000FB480  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FE684 000FB484  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FE688 000FB488  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800FE68C 000FB48C  7C 08 03 A6 */	mtlr r0
/* 800FE690 000FB490  38 21 00 10 */	addi r1, r1, 0x10
/* 800FE694 000FB494  4E 80 00 20 */	blr
.endfn kar_gryakugondola_init_stage_linked_kind46_carrier_yaku

# .text:0xC4 | 0x800FE698 | size: 0x68
.fn kar_gryakugondola_start_kind46_idle_motion, global
/* 800FE698 000FB498  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FE69C 000FB49C  7C 08 02 A6 */	mflr r0
/* 800FE6A0 000FB4A0  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FE6A4 000FB4A4  38 00 00 00 */	li r0, 0x0
/* 800FE6A8 000FB4A8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FE6AC 000FB4AC  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800FE6B0 000FB4B0  90 1F 01 30 */	stw r0, 0x130(r31)
/* 800FE6B4 000FB4B4  80 1F 01 1C */	lwz r0, 0x11c(r31)
/* 800FE6B8 000FB4B8  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FE6BC 000FB4BC  40 81 00 0C */	ble .L_800FE6C8
/* 800FE6C0 000FB4C0  38 7F 01 18 */	addi r3, r31, 0x118
/* 800FE6C4 000FB4C4  4B FE BA BD */	bl kar_graudio_stop_active_fgm_slot
.L_800FE6C8:
/* 800FE6C8 000FB4C8  C0 22 92 20 */	lfs f1, lbl_805DF920@sda21(r0)
/* 800FE6CC 000FB4CC  7F E3 FB 78 */	mr r3, r31
/* 800FE6D0 000FB4D0  C0 42 92 24 */	lfs f2, lbl_805DF924@sda21(r0)
/* 800FE6D4 000FB4D4  38 80 00 00 */	li r4, 0x0
/* 800FE6D8 000FB4D8  FC 60 08 90 */	fmr f3, f1
/* 800FE6DC 000FB4DC  38 A0 FF FF */	li r5, -0x1
/* 800FE6E0 000FB4E0  38 C0 FF FF */	li r6, -0x1
/* 800FE6E4 000FB4E4  38 E0 00 00 */	li r7, 0x0
/* 800FE6E8 000FB4E8  4B FF 6E 61 */	bl kar_gryaku_set_path_node_motion
/* 800FE6EC 000FB4EC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FE6F0 000FB4F0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FE6F4 000FB4F4  7C 08 03 A6 */	mtlr r0
/* 800FE6F8 000FB4F8  38 21 00 10 */	addi r1, r1, 0x10
/* 800FE6FC 000FB4FC  4E 80 00 20 */	blr
.endfn kar_gryakugondola_start_kind46_idle_motion

# .text:0x12C | 0x800FE700 | size: 0x1C
.fn kar_gryakugondola_reset_kind46_candidate_state, global
/* 800FE700 000FB500  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 800FE704 000FB504  38 00 00 00 */	li r0, 0x0
/* 800FE708 000FB508  3C 60 80 5E */	lis r3, lbl_805DC8BC@ha
/* 800FE70C 000FB50C  90 04 01 30 */	stw r0, 0x130(r4)
/* 800FE710 000FB510  C0 03 C8 BC */	lfs f0, lbl_805DC8BC@l(r3)
/* 800FE714 000FB514  D0 04 01 34 */	stfs f0, 0x134(r4)
/* 800FE718 000FB518  4E 80 00 20 */	blr
.endfn kar_gryakugondola_reset_kind46_candidate_state

# .text:0x148 | 0x800FE71C | size: 0x18C
.fn kar_gryakugondola_apply_armed_user_launch, global
/* 800FE71C 000FB51C  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800FE720 000FB520  7C 08 02 A6 */	mflr r0
/* 800FE724 000FB524  90 01 00 34 */	stw r0, 0x34(r1)
/* 800FE728 000FB528  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 800FE72C 000FB52C  93 C1 00 28 */	stw r30, 0x28(r1)
/* 800FE730 000FB530  93 A1 00 24 */	stw r29, 0x24(r1)
/* 800FE734 000FB534  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800FE738 000FB538  83 CD 05 EC */	lwz r30, lbl_805DD6CC@sda21(r0)
/* 800FE73C 000FB53C  88 1F 01 3C */	lbz r0, 0x13c(r31)
/* 800FE740 000FB540  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800FE744 000FB544  54 00 CF FF */	extrwi. r0, r0, 1, 24
/* 800FE748 000FB548  83 A3 00 00 */	lwz r29, 0x0(r3)
/* 800FE74C 000FB54C  41 82 01 40 */	beq .L_800FE88C
/* 800FE750 000FB550  80 7D 00 14 */	lwz r3, 0x14(r29)
/* 800FE754 000FB554  28 03 00 00 */	cmplwi r3, 0x0
/* 800FE758 000FB558  41 82 00 10 */	beq .L_800FE768
/* 800FE75C 000FB55C  38 81 00 08 */	addi r4, r1, 0x8
/* 800FE760 000FB560  4B F6 45 45 */	bl kar_lbvector_normalize_with_axis_fallback
/* 800FE764 000FB564  48 00 00 1C */	b .L_800FE780
.L_800FE768:
/* 800FE768 000FB568  80 7D 00 04 */	lwz r3, 0x4(r29)
/* 800FE76C 000FB56C  38 81 00 08 */	addi r4, r1, 0x8
/* 800FE770 000FB570  4B FD 65 31 */	bl kar_grcommon__near_800d4ca0
/* 800FE774 000FB574  38 61 00 08 */	addi r3, r1, 0x8
/* 800FE778 000FB578  7C 64 1B 78 */	mr r4, r3
/* 800FE77C 000FB57C  4B F6 45 29 */	bl kar_lbvector_normalize_with_axis_fallback
.L_800FE780:
/* 800FE780 000FB580  C0 7D 00 10 */	lfs f3, 0x10(r29)
/* 800FE784 000FB584  C0 41 00 08 */	lfs f2, 0x8(r1)
/* 800FE788 000FB588  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 800FE78C 000FB58C  C0 01 00 10 */	lfs f0, 0x10(r1)
/* 800FE790 000FB590  EC 42 00 F2 */	fmuls f2, f2, f3
/* 800FE794 000FB594  EC 21 00 F2 */	fmuls f1, f1, f3
/* 800FE798 000FB598  EC 00 00 F2 */	fmuls f0, f0, f3
/* 800FE79C 000FB59C  D0 41 00 08 */	stfs f2, 0x8(r1)
/* 800FE7A0 000FB5A0  D0 21 00 0C */	stfs f1, 0xc(r1)
/* 800FE7A4 000FB5A4  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 800FE7A8 000FB5A8  80 1F 01 30 */	lwz r0, 0x130(r31)
/* 800FE7AC 000FB5AC  28 00 00 00 */	cmplwi r0, 0x0
/* 800FE7B0 000FB5B0  40 82 00 1C */	bne .L_800FE7CC
/* 800FE7B4 000FB5B4  3C 60 80 4A */	lis r3, kar_src_gryakugondola_c@ha
/* 800FE7B8 000FB5B8  3C A0 80 4A */	lis r5, kar_gryakugondola_assert_user_gobj@ha
/* 800FE7BC 000FB5BC  38 63 63 D0 */	addi r3, r3, kar_src_gryakugondola_c@l
/* 800FE7C0 000FB5C0  38 80 00 B8 */	li r4, 0xb8
/* 800FE7C4 000FB5C4  38 A5 63 E0 */	addi r5, r5, kar_gryakugondola_assert_user_gobj@l
/* 800FE7C8 000FB5C8  48 32 9C F1 */	bl __assert
.L_800FE7CC:
/* 800FE7CC 000FB5CC  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 800FE7D0 000FB5D0  48 0C 8D 65 */	bl fn_801C7534
/* 800FE7D4 000FB5D4  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FE7D8 000FB5D8  41 82 00 44 */	beq .L_800FE81C
/* 800FE7DC 000FB5DC  80 1D 00 18 */	lwz r0, 0x18(r29)
/* 800FE7E0 000FB5E0  2C 00 FF FF */	cmpwi r0, -0x1
/* 800FE7E4 000FB5E4  41 82 00 28 */	beq .L_800FE80C
/* 800FE7E8 000FB5E8  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 800FE7EC 000FB5EC  54 00 10 3A */	slwi r0, r0, 2
/* 800FE7F0 000FB5F0  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 800FE7F4 000FB5F4  80 84 00 24 */	lwz r4, 0x24(r4)
/* 800FE7F8 000FB5F8  80 84 00 10 */	lwz r4, 0x10(r4)
/* 800FE7FC 000FB5FC  80 84 00 00 */	lwz r4, 0x0(r4)
/* 800FE800 000FB600  7C 84 00 2E */	lwzx r4, r4, r0
/* 800FE804 000FB604  48 0C 9C 25 */	bl fn_801C8428
/* 800FE808 000FB608  48 00 00 2C */	b .L_800FE834
.L_800FE80C:
/* 800FE80C 000FB60C  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 800FE810 000FB610  38 81 00 08 */	addi r4, r1, 0x8
/* 800FE814 000FB614  48 0C 9C 75 */	bl fn_801C8488
/* 800FE818 000FB618  48 00 00 1C */	b .L_800FE834
.L_800FE81C:
/* 800FE81C 000FB61C  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 800FE820 000FB620  A0 03 00 00 */	lhz r0, 0x0(r3)
/* 800FE824 000FB624  28 00 00 15 */	cmplwi r0, 0x15
/* 800FE828 000FB628  40 82 00 0C */	bne .L_800FE834
/* 800FE82C 000FB62C  38 81 00 08 */	addi r4, r1, 0x8
/* 800FE830 000FB630  48 10 5E B9 */	bl kar_emupdate__near_802046e8
.L_800FE834:
/* 800FE834 000FB634  80 7F 00 00 */	lwz r3, 0x0(r31)
/* 800FE838 000FB638  38 00 00 00 */	li r0, 0x0
/* 800FE83C 000FB63C  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 800FE840 000FB640  90 1E 01 30 */	stw r0, 0x130(r30)
/* 800FE844 000FB644  80 1E 01 1C */	lwz r0, 0x11c(r30)
/* 800FE848 000FB648  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FE84C 000FB64C  40 81 00 0C */	ble .L_800FE858
/* 800FE850 000FB650  38 7E 01 18 */	addi r3, r30, 0x118
/* 800FE854 000FB654  4B FE B9 2D */	bl kar_graudio_stop_active_fgm_slot
.L_800FE858:
/* 800FE858 000FB658  C0 22 92 20 */	lfs f1, lbl_805DF920@sda21(r0)
/* 800FE85C 000FB65C  7F C3 F3 78 */	mr r3, r30
/* 800FE860 000FB660  C0 42 92 24 */	lfs f2, lbl_805DF924@sda21(r0)
/* 800FE864 000FB664  38 80 00 00 */	li r4, 0x0
/* 800FE868 000FB668  FC 60 08 90 */	fmr f3, f1
/* 800FE86C 000FB66C  38 A0 FF FF */	li r5, -0x1
/* 800FE870 000FB670  38 C0 FF FF */	li r6, -0x1
/* 800FE874 000FB674  38 E0 00 00 */	li r7, 0x0
/* 800FE878 000FB678  4B FF 6C D1 */	bl kar_gryaku_set_path_node_motion
/* 800FE87C 000FB67C  88 1F 01 3C */	lbz r0, 0x13c(r31)
/* 800FE880 000FB680  38 60 00 00 */	li r3, 0x0
/* 800FE884 000FB684  50 60 3E 30 */	rlwimi r0, r3, 7, 24, 24
/* 800FE888 000FB688  98 1F 01 3C */	stb r0, 0x13c(r31)
.L_800FE88C:
/* 800FE88C 000FB68C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800FE890 000FB690  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800FE894 000FB694  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 800FE898 000FB698  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 800FE89C 000FB69C  7C 08 03 A6 */	mtlr r0
/* 800FE8A0 000FB6A0  38 21 00 30 */	addi r1, r1, 0x30
/* 800FE8A4 000FB6A4  4E 80 00 20 */	blr
.endfn kar_gryakugondola_apply_armed_user_launch

# .text:0x2D4 | 0x800FE8A8 | size: 0x60
.fn kar_gryakugondola_update_zone_contains_current_user, global
/* 800FE8A8 000FB6A8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800FE8AC 000FB6AC  7C 08 02 A6 */	mflr r0
/* 800FE8B0 000FB6B0  90 01 00 24 */	stw r0, 0x24(r1)
/* 800FE8B4 000FB6B4  38 81 00 08 */	addi r4, r1, 0x8
/* 800FE8B8 000FB6B8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800FE8BC 000FB6BC  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800FE8C0 000FB6C0  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800FE8C4 000FB6C4  80 63 00 00 */	lwz r3, 0x0(r3)
/* 800FE8C8 000FB6C8  80 63 00 04 */	lwz r3, 0x4(r3)
/* 800FE8CC 000FB6CC  4B FD 63 29 */	bl kar_grcommon__near_800d4bf4
/* 800FE8D0 000FB6D0  80 7F 01 38 */	lwz r3, 0x138(r31)
/* 800FE8D4 000FB6D4  38 81 00 08 */	addi r4, r1, 0x8
/* 800FE8D8 000FB6D8  4B FD 62 05 */	bl kar_grcommon__near_800d4adc
/* 800FE8DC 000FB6DC  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FE8E0 000FB6E0  41 82 00 14 */	beq .L_800FE8F4
/* 800FE8E4 000FB6E4  88 1F 01 3C */	lbz r0, 0x13c(r31)
/* 800FE8E8 000FB6E8  38 60 00 01 */	li r3, 0x1
/* 800FE8EC 000FB6EC  50 60 3E 30 */	rlwimi r0, r3, 7, 24, 24
/* 800FE8F0 000FB6F0  98 1F 01 3C */	stb r0, 0x13c(r31)
.L_800FE8F4:
/* 800FE8F4 000FB6F4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FE8F8 000FB6F8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800FE8FC 000FB6FC  7C 08 03 A6 */	mtlr r0
/* 800FE900 000FB700  38 21 00 20 */	addi r1, r1, 0x20
/* 800FE904 000FB704  4E 80 00 20 */	blr
.endfn kar_gryakugondola_update_zone_contains_current_user

# .text:0x334 | 0x800FE908 | size: 0x60
.fn kar_gryakugondola_is_catch_candidate_in_zone, global
/* 800FE908 000FB708  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800FE90C 000FB70C  7C 08 02 A6 */	mflr r0
/* 800FE910 000FB710  90 01 00 24 */	stw r0, 0x24(r1)
/* 800FE914 000FB714  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800FE918 000FB718  7C 9F 23 78 */	mr r31, r4
/* 800FE91C 000FB71C  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FE920 000FB720  80 03 00 74 */	lwz r0, 0x74(r3)
/* 800FE924 000FB724  2C 00 00 01 */	cmpwi r0, 0x1
/* 800FE928 000FB728  40 82 00 0C */	bne .L_800FE934
/* 800FE92C 000FB72C  38 60 00 00 */	li r3, 0x0
/* 800FE930 000FB730  48 00 00 24 */	b .L_800FE954
.L_800FE934:
/* 800FE934 000FB734  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800FE938 000FB738  38 81 00 08 */	addi r4, r1, 0x8
/* 800FE93C 000FB73C  80 63 00 00 */	lwz r3, 0x0(r3)
/* 800FE940 000FB740  80 63 00 04 */	lwz r3, 0x4(r3)
/* 800FE944 000FB744  4B FD 62 B1 */	bl kar_grcommon__near_800d4bf4
/* 800FE948 000FB748  7F E3 FB 78 */	mr r3, r31
/* 800FE94C 000FB74C  38 81 00 08 */	addi r4, r1, 0x8
/* 800FE950 000FB750  4B FD 61 8D */	bl kar_grcommon__near_800d4adc
.L_800FE954:
/* 800FE954 000FB754  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FE958 000FB758  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800FE95C 000FB75C  7C 08 03 A6 */	mtlr r0
/* 800FE960 000FB760  38 21 00 20 */	addi r1, r1, 0x20
/* 800FE964 000FB764  4E 80 00 20 */	blr
.endfn kar_gryakugondola_is_catch_candidate_in_zone

# .text:0x394 | 0x800FE968 | size: 0x94
.fn kar_gryakugondola_record_nearest_catch_candidate, global
/* 800FE968 000FB768  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800FE96C 000FB76C  7C 08 02 A6 */	mflr r0
/* 800FE970 000FB770  90 01 00 34 */	stw r0, 0x34(r1)
/* 800FE974 000FB774  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 800FE978 000FB778  93 C1 00 28 */	stw r30, 0x28(r1)
/* 800FE97C 000FB77C  93 A1 00 24 */	stw r29, 0x24(r1)
/* 800FE980 000FB780  7C 9D 23 78 */	mr r29, r4
/* 800FE984 000FB784  38 81 00 14 */	addi r4, r1, 0x14
/* 800FE988 000FB788  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800FE98C 000FB78C  7F A3 EB 78 */	mr r3, r29
/* 800FE990 000FB790  80 BF 00 08 */	lwz r5, 0x8(r31)
/* 800FE994 000FB794  83 C5 00 00 */	lwz r30, 0x0(r5)
/* 800FE998 000FB798  48 0C 8B B1 */	bl fn_801C7548
/* 800FE99C 000FB79C  80 7E 00 04 */	lwz r3, 0x4(r30)
/* 800FE9A0 000FB7A0  38 81 00 08 */	addi r4, r1, 0x8
/* 800FE9A4 000FB7A4  4B FD 62 51 */	bl kar_grcommon__near_800d4bf4
/* 800FE9A8 000FB7A8  38 61 00 14 */	addi r3, r1, 0x14
/* 800FE9AC 000FB7AC  38 81 00 08 */	addi r4, r1, 0x8
/* 800FE9B0 000FB7B0  48 2D 39 45 */	bl fn_803D22F4
/* 800FE9B4 000FB7B4  80 1F 01 30 */	lwz r0, 0x130(r31)
/* 800FE9B8 000FB7B8  28 00 00 00 */	cmplwi r0, 0x0
/* 800FE9BC 000FB7BC  41 82 00 1C */	beq .L_800FE9D8
/* 800FE9C0 000FB7C0  C0 1F 01 34 */	lfs f0, 0x134(r31)
/* 800FE9C4 000FB7C4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800FE9C8 000FB7C8  40 80 00 18 */	bge .L_800FE9E0
/* 800FE9CC 000FB7CC  93 BF 01 30 */	stw r29, 0x130(r31)
/* 800FE9D0 000FB7D0  D0 3F 01 34 */	stfs f1, 0x134(r31)
/* 800FE9D4 000FB7D4  48 00 00 0C */	b .L_800FE9E0
.L_800FE9D8:
/* 800FE9D8 000FB7D8  93 BF 01 30 */	stw r29, 0x130(r31)
/* 800FE9DC 000FB7DC  D0 3F 01 34 */	stfs f1, 0x134(r31)
.L_800FE9E0:
/* 800FE9E0 000FB7E0  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800FE9E4 000FB7E4  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800FE9E8 000FB7E8  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 800FE9EC 000FB7EC  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 800FE9F0 000FB7F0  7C 08 03 A6 */	mtlr r0
/* 800FE9F4 000FB7F4  38 21 00 30 */	addi r1, r1, 0x30
/* 800FE9F8 000FB7F8  4E 80 00 20 */	blr
.endfn kar_gryakugondola_record_nearest_catch_candidate

# .text:0x428 | 0x800FE9FC | size: 0x60
.fn kar_gryakugondola_is_current_user_and_start_motion, global
/* 800FE9FC 000FB7FC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FEA00 000FB800  7C 08 02 A6 */	mflr r0
/* 800FEA04 000FB804  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FEA08 000FB808  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FEA0C 000FB80C  80 03 01 30 */	lwz r0, 0x130(r3)
/* 800FEA10 000FB810  7C 00 20 40 */	cmplw r0, r4
/* 800FEA14 000FB814  40 82 00 34 */	bne .L_800FEA48
/* 800FEA18 000FB818  C0 22 92 20 */	lfs f1, lbl_805DF920@sda21(r0)
/* 800FEA1C 000FB81C  38 80 00 01 */	li r4, 0x1
/* 800FEA20 000FB820  80 63 00 00 */	lwz r3, 0x0(r3)
/* 800FEA24 000FB824  38 A0 FF FF */	li r5, -0x1
/* 800FEA28 000FB828  FC 60 08 90 */	fmr f3, f1
/* 800FEA2C 000FB82C  C0 42 92 24 */	lfs f2, lbl_805DF924@sda21(r0)
/* 800FEA30 000FB830  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FEA34 000FB834  38 C0 FF FF */	li r6, -0x1
/* 800FEA38 000FB838  38 E0 00 00 */	li r7, 0x0
/* 800FEA3C 000FB83C  4B FF 6B 0D */	bl kar_gryaku_set_path_node_motion
/* 800FEA40 000FB840  38 60 00 01 */	li r3, 0x1
/* 800FEA44 000FB844  48 00 00 08 */	b .L_800FEA4C
.L_800FEA48:
/* 800FEA48 000FB848  38 60 00 00 */	li r3, 0x0
.L_800FEA4C:
/* 800FEA4C 000FB84C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FEA50 000FB850  7C 08 03 A6 */	mtlr r0
/* 800FEA54 000FB854  38 21 00 10 */	addi r1, r1, 0x10
/* 800FEA58 000FB858  4E 80 00 20 */	blr
.endfn kar_gryakugondola_is_current_user_and_start_motion

# .text:0x488 | 0x800FEA5C | size: 0x68
.fn kar_gryakugondola_get_reference_position_and_vectors, global
/* 800FEA5C 000FB85C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800FEA60 000FB860  7C 08 02 A6 */	mflr r0
/* 800FEA64 000FB864  90 01 00 24 */	stw r0, 0x24(r1)
/* 800FEA68 000FB868  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800FEA6C 000FB86C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800FEA70 000FB870  7C DE 33 78 */	mr r30, r6
/* 800FEA74 000FB874  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800FEA78 000FB878  7C BD 2B 78 */	mr r29, r5
/* 800FEA7C 000FB87C  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FEA80 000FB880  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800FEA84 000FB884  83 E3 00 00 */	lwz r31, 0x0(r3)
/* 800FEA88 000FB888  80 7F 00 04 */	lwz r3, 0x4(r31)
/* 800FEA8C 000FB88C  4B FD 61 69 */	bl kar_grcommon__near_800d4bf4
/* 800FEA90 000FB890  80 7F 00 04 */	lwz r3, 0x4(r31)
/* 800FEA94 000FB894  7F A4 EB 78 */	mr r4, r29
/* 800FEA98 000FB898  4B FD 62 09 */	bl kar_grcommon__near_800d4ca0
/* 800FEA9C 000FB89C  80 7F 00 04 */	lwz r3, 0x4(r31)
/* 800FEAA0 000FB8A0  7F C4 F3 78 */	mr r4, r30
/* 800FEAA4 000FB8A4  4B FD 62 B5 */	bl kar_grcommon__near_800d4d58
/* 800FEAA8 000FB8A8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FEAAC 000FB8AC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800FEAB0 000FB8B0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800FEAB4 000FB8B4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800FEAB8 000FB8B8  7C 08 03 A6 */	mtlr r0
/* 800FEABC 000FB8BC  38 21 00 20 */	addi r1, r1, 0x20
/* 800FEAC0 000FB8C0  4E 80 00 20 */	blr
.endfn kar_gryakugondola_get_reference_position_and_vectors

# .text:0x4F0 | 0x800FEAC4 | size: 0x5C
.fn kar_gryakugondola_replace_current_user_gobj, global
/* 800FEAC4 000FB8C4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FEAC8 000FB8C8  7C 08 02 A6 */	mflr r0
/* 800FEACC 000FB8CC  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FEAD0 000FB8D0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FEAD4 000FB8D4  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800FEAD8 000FB8D8  7C BE 2B 78 */	mr r30, r5
/* 800FEADC 000FB8DC  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800FEAE0 000FB8E0  80 1F 01 30 */	lwz r0, 0x130(r31)
/* 800FEAE4 000FB8E4  7C 00 20 40 */	cmplw r0, r4
/* 800FEAE8 000FB8E8  41 82 00 1C */	beq .L_800FEB04
/* 800FEAEC 000FB8EC  3C 60 80 4A */	lis r3, kar_src_gryakugondola_c@ha
/* 800FEAF0 000FB8F0  3C A0 80 4A */	lis r5, kar_gryakugondola_assert_user_gobj_matches_old_app@ha
/* 800FEAF4 000FB8F4  38 63 63 D0 */	addi r3, r3, kar_src_gryakugondola_c@l
/* 800FEAF8 000FB8F8  38 80 01 64 */	li r4, 0x164
/* 800FEAFC 000FB8FC  38 A5 63 FC */	addi r5, r5, kar_gryakugondola_assert_user_gobj_matches_old_app@l
/* 800FEB00 000FB900  48 32 99 B9 */	bl __assert
.L_800FEB04:
/* 800FEB04 000FB904  93 DF 01 30 */	stw r30, 0x130(r31)
/* 800FEB08 000FB908  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FEB0C 000FB90C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FEB10 000FB910  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800FEB14 000FB914  7C 08 03 A6 */	mtlr r0
/* 800FEB18 000FB918  38 21 00 10 */	addi r1, r1, 0x10
/* 800FEB1C 000FB91C  4E 80 00 20 */	blr
.endfn kar_gryakugondola_replace_current_user_gobj

# .text:0x54C | 0x800FEB20 | size: 0x38
.fn kar_gryakugondola_create_stage_linked_kind47_ground_audio_yaku, global
/* 800FEB20 000FB920  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FEB24 000FB924  7C 08 02 A6 */	mflr r0
/* 800FEB28 000FB928  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FEB2C 000FB92C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FEB30 000FB930  7C 7F 1B 78 */	mr r31, r3
/* 800FEB34 000FB934  38 60 00 2F */	li r3, 0x2f
/* 800FEB38 000FB938  4B FF 59 35 */	bl kar_gryaku_create_yaku_from_main_kind
/* 800FEB3C 000FB93C  7F E4 FB 78 */	mr r4, r31
/* 800FEB40 000FB940  48 00 00 19 */	bl kar_gryakugondola_init_stage_linked_kind47_ground_audio_yaku
/* 800FEB44 000FB944  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FEB48 000FB948  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FEB4C 000FB94C  7C 08 03 A6 */	mtlr r0
/* 800FEB50 000FB950  38 21 00 10 */	addi r1, r1, 0x10
/* 800FEB54 000FB954  4E 80 00 20 */	blr
.endfn kar_gryakugondola_create_stage_linked_kind47_ground_audio_yaku

# .text:0x584 | 0x800FEB58 | size: 0xDC
.fn kar_gryakugondola_init_stage_linked_kind47_ground_audio_yaku, global
/* 800FEB58 000FB958  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800FEB5C 000FB95C  7C 08 02 A6 */	mflr r0
/* 800FEB60 000FB960  90 01 00 24 */	stw r0, 0x24(r1)
/* 800FEB64 000FB964  39 61 00 20 */	addi r11, r1, 0x20
/* 800FEB68 000FB968  48 2A EF E9 */	bl _savegpr_26
/* 800FEB6C 000FB96C  7C 7A 1B 78 */	mr r26, r3
/* 800FEB70 000FB970  3B 60 00 00 */	li r27, 0x0
/* 800FEB74 000FB974  83 A3 00 2C */	lwz r29, 0x2c(r3)
/* 800FEB78 000FB978  3B E0 00 00 */	li r31, 0x0
/* 800FEB7C 000FB97C  80 7D 00 08 */	lwz r3, 0x8(r29)
/* 800FEB80 000FB980  7F BE EB 78 */	mr r30, r29
/* 800FEB84 000FB984  83 83 00 00 */	lwz r28, 0x0(r3)
/* 800FEB88 000FB988  48 00 00 60 */	b .L_800FEBE8
.L_800FEB8C:
/* 800FEB8C 000FB98C  80 9C 00 00 */	lwz r4, 0x0(r28)
/* 800FEB90 000FB990  38 A0 00 00 */	li r5, 0x0
/* 800FEB94 000FB994  80 6D 12 54 */	lwz r3, lbl_805DE334@sda21(r0)
/* 800FEB98 000FB998  7C 04 F8 2E */	lwzx r0, r4, r31
/* 800FEB9C 000FB99C  80 63 00 20 */	lwz r3, 0x20(r3)
/* 800FEBA0 000FB9A0  48 00 00 18 */	b .L_800FEBB8
.L_800FEBA4:
/* 800FEBA4 000FB9A4  7C 00 28 00 */	cmpw r0, r5
/* 800FEBA8 000FB9A8  40 82 00 08 */	bne .L_800FEBB0
/* 800FEBAC 000FB9AC  48 00 00 2C */	b .L_800FEBD8
.L_800FEBB0:
/* 800FEBB0 000FB9B0  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800FEBB4 000FB9B4  38 A5 00 01 */	addi r5, r5, 0x1
.L_800FEBB8:
/* 800FEBB8 000FB9B8  28 03 00 00 */	cmplwi r3, 0x0
/* 800FEBBC 000FB9BC  40 82 FF E8 */	bne .L_800FEBA4
/* 800FEBC0 000FB9C0  3C 60 80 4A */	lis r3, kar_src_ground_h_804a6424@ha
/* 800FEBC4 000FB9C4  38 80 09 6C */	li r4, 0x96c
/* 800FEBC8 000FB9C8  38 63 64 24 */	addi r3, r3, kar_src_ground_h_804a6424@l
/* 800FEBCC 000FB9CC  38 AD 91 90 */	li r5, lbl_805D6270@sda21
/* 800FEBD0 000FB9D0  48 32 98 E9 */	bl __assert
/* 800FEBD4 000FB9D4  38 60 00 00 */	li r3, 0x0
.L_800FEBD8:
/* 800FEBD8 000FB9D8  90 7E 01 30 */	stw r3, 0x130(r30)
/* 800FEBDC 000FB9DC  3B FF 00 04 */	addi r31, r31, 0x4
/* 800FEBE0 000FB9E0  3B DE 00 04 */	addi r30, r30, 0x4
/* 800FEBE4 000FB9E4  3B 7B 00 01 */	addi r27, r27, 0x1
.L_800FEBE8:
/* 800FEBE8 000FB9E8  80 1C 00 04 */	lwz r0, 0x4(r28)
/* 800FEBEC 000FB9EC  7C 1B 00 00 */	cmpw r27, r0
/* 800FEBF0 000FB9F0  41 80 FF 9C */	blt .L_800FEB8C
/* 800FEBF4 000FB9F4  80 7D 00 08 */	lwz r3, 0x8(r29)
/* 800FEBF8 000FB9F8  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800FEBFC 000FB9FC  28 00 00 00 */	cmplwi r0, 0x0
/* 800FEC00 000FBA00  41 82 00 14 */	beq .L_800FEC14
/* 800FEC04 000FBA04  7F 43 D3 78 */	mr r3, r26
/* 800FEC08 000FBA08  38 80 FF FF */	li r4, -0x1
/* 800FEC0C 000FBA0C  38 A0 00 00 */	li r5, 0x0
/* 800FEC10 000FBA10  4B FF 8C 61 */	bl kar_gryakuaudio_configure_fgm_track_from_joint
.L_800FEC14:
/* 800FEC14 000FBA14  7F 43 D3 78 */	mr r3, r26
/* 800FEC18 000FBA18  48 00 00 1D */	bl kar_gryakugondola_start_kind47_idle_motion
/* 800FEC1C 000FBA1C  39 61 00 20 */	addi r11, r1, 0x20
/* 800FEC20 000FBA20  48 2A EF 7D */	bl _restgpr_26
/* 800FEC24 000FBA24  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FEC28 000FBA28  7C 08 03 A6 */	mtlr r0
/* 800FEC2C 000FBA2C  38 21 00 20 */	addi r1, r1, 0x20
/* 800FEC30 000FBA30  4E 80 00 20 */	blr
.endfn kar_gryakugondola_init_stage_linked_kind47_ground_audio_yaku

# .text:0x660 | 0x800FEC34 | size: 0x40
.fn kar_gryakugondola_start_kind47_idle_motion, global
/* 800FEC34 000FBA34  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FEC38 000FBA38  7C 08 02 A6 */	mflr r0
/* 800FEC3C 000FBA3C  C0 22 92 20 */	lfs f1, lbl_805DF920@sda21(r0)
/* 800FEC40 000FBA40  38 80 00 00 */	li r4, 0x0
/* 800FEC44 000FBA44  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FEC48 000FBA48  38 A0 FF FF */	li r5, -0x1
/* 800FEC4C 000FBA4C  FC 40 08 90 */	fmr f2, f1
/* 800FEC50 000FBA50  38 C0 FF FF */	li r6, -0x1
/* 800FEC54 000FBA54  FC 60 08 90 */	fmr f3, f1
/* 800FEC58 000FBA58  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FEC5C 000FBA5C  38 E0 00 00 */	li r7, 0x0
/* 800FEC60 000FBA60  4B FF 68 E9 */	bl kar_gryaku_set_path_node_motion
/* 800FEC64 000FBA64  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FEC68 000FBA68  7C 08 03 A6 */	mtlr r0
/* 800FEC6C 000FBA6C  38 21 00 10 */	addi r1, r1, 0x10
/* 800FEC70 000FBA70  4E 80 00 20 */	blr
.endfn kar_gryakugondola_start_kind47_idle_motion

# .text:0x6A0 | 0x800FEC74 | size: 0xAC
.fn kar_gryakugondola_update_kind47_ground_state_fgm, global
/* 800FEC74 000FBA74  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800FEC78 000FBA78  7C 08 02 A6 */	mflr r0
/* 800FEC7C 000FBA7C  90 01 00 24 */	stw r0, 0x24(r1)
/* 800FEC80 000FBA80  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800FEC84 000FBA84  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800FEC88 000FBA88  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800FEC8C 000FBA8C  3B A0 00 00 */	li r29, 0x0
/* 800FEC90 000FBA90  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800FEC94 000FBA94  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800FEC98 000FBA98  7F E4 FB 78 */	mr r4, r31
/* 800FEC9C 000FBA9C  83 C3 00 00 */	lwz r30, 0x0(r3)
/* 800FECA0 000FBAA0  80 1E 00 04 */	lwz r0, 0x4(r30)
/* 800FECA4 000FBAA4  7C 09 03 A6 */	mtctr r0
/* 800FECA8 000FBAA8  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FECAC 000FBAAC  40 81 00 44 */	ble .L_800FECF0
.L_800FECB0:
/* 800FECB0 000FBAB0  80 64 01 30 */	lwz r3, 0x130(r4)
/* 800FECB4 000FBAB4  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FECB8 000FBAB8  80 03 00 74 */	lwz r0, 0x74(r3)
/* 800FECBC 000FBABC  2C 00 00 01 */	cmpwi r0, 0x1
/* 800FECC0 000FBAC0  40 82 00 24 */	bne .L_800FECE4
/* 800FECC4 000FBAC4  38 7F 01 18 */	addi r3, r31, 0x118
/* 800FECC8 000FBAC8  4B FE B5 09 */	bl kar_graudio_is_active_fgm_slot_playing
/* 800FECCC 000FBACC  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FECD0 000FBAD0  40 82 00 20 */	bne .L_800FECF0
/* 800FECD4 000FBAD4  38 7F 01 18 */	addi r3, r31, 0x118
/* 800FECD8 000FBAD8  38 80 00 00 */	li r4, 0x0
/* 800FECDC 000FBADC  4B FE B3 A9 */	bl kar_graudio_play_fgm_entry_id
/* 800FECE0 000FBAE0  48 00 00 10 */	b .L_800FECF0
.L_800FECE4:
/* 800FECE4 000FBAE4  38 84 00 04 */	addi r4, r4, 0x4
/* 800FECE8 000FBAE8  3B BD 00 01 */	addi r29, r29, 0x1
/* 800FECEC 000FBAEC  42 00 FF C4 */	bdnz .L_800FECB0
.L_800FECF0:
/* 800FECF0 000FBAF0  80 1E 00 04 */	lwz r0, 0x4(r30)
/* 800FECF4 000FBAF4  7C 1D 00 00 */	cmpw r29, r0
/* 800FECF8 000FBAF8  40 82 00 0C */	bne .L_800FED04
/* 800FECFC 000FBAFC  38 7F 01 18 */	addi r3, r31, 0x118
/* 800FED00 000FBB00  4B FE B4 81 */	bl kar_graudio_stop_active_fgm_slot
.L_800FED04:
/* 800FED04 000FBB04  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FED08 000FBB08  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800FED0C 000FBB0C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800FED10 000FBB10  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800FED14 000FBB14  7C 08 03 A6 */	mtlr r0
/* 800FED18 000FBB18  38 21 00 20 */	addi r1, r1, 0x20
/* 800FED1C 000FBB1C  4E 80 00 20 */	blr
.endfn kar_gryakugondola_update_kind47_ground_state_fgm

# .text:0x74C | 0x800FED20 | size: 0x28
.fn kar_gryakugondola_create_stage_linked_kind48_route_yaku, global
/* 800FED20 000FBB20  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FED24 000FBB24  7C 08 02 A6 */	mflr r0
/* 800FED28 000FBB28  38 60 00 30 */	li r3, 0x30
/* 800FED2C 000FBB2C  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FED30 000FBB30  4B FF 57 3D */	bl kar_gryaku_create_yaku_from_main_kind
/* 800FED34 000FBB34  48 00 00 15 */	bl kar_gryakugondola_init_stage_linked_kind48_route_yaku
/* 800FED38 000FBB38  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FED3C 000FBB3C  7C 08 03 A6 */	mtlr r0
/* 800FED40 000FBB40  38 21 00 10 */	addi r1, r1, 0x10
/* 800FED44 000FBB44  4E 80 00 20 */	blr
.endfn kar_gryakugondola_create_stage_linked_kind48_route_yaku

# .text:0x774 | 0x800FED48 | size: 0xB8
.fn kar_gryakugondola_init_stage_linked_kind48_route_yaku, global
/* 800FED48 000FBB48  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FED4C 000FBB4C  7C 08 02 A6 */	mflr r0
/* 800FED50 000FBB50  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FED54 000FBB54  38 00 00 00 */	li r0, 0x0
/* 800FED58 000FBB58  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FED5C 000FBB5C  7C 7F 1B 78 */	mr r31, r3
/* 800FED60 000FBB60  80 A3 00 2C */	lwz r5, 0x2c(r3)
/* 800FED64 000FBB64  80 85 00 08 */	lwz r4, 0x8(r5)
/* 800FED68 000FBB68  80 C4 00 00 */	lwz r6, 0x0(r4)
/* 800FED6C 000FBB6C  90 05 01 30 */	stw r0, 0x130(r5)
/* 800FED70 000FBB70  90 05 01 34 */	stw r0, 0x134(r5)
/* 800FED74 000FBB74  90 05 01 38 */	stw r0, 0x138(r5)
/* 800FED78 000FBB78  90 05 01 3C */	stw r0, 0x13c(r5)
/* 800FED7C 000FBB7C  90 05 01 40 */	stw r0, 0x140(r5)
/* 800FED80 000FBB80  90 05 01 44 */	stw r0, 0x144(r5)
/* 800FED84 000FBB84  90 05 01 48 */	stw r0, 0x148(r5)
/* 800FED88 000FBB88  90 05 01 4C */	stw r0, 0x14c(r5)
/* 800FED8C 000FBB8C  90 05 01 50 */	stw r0, 0x150(r5)
/* 800FED90 000FBB90  90 05 01 54 */	stw r0, 0x154(r5)
/* 800FED94 000FBB94  90 05 01 58 */	stw r0, 0x158(r5)
/* 800FED98 000FBB98  90 05 01 5C */	stw r0, 0x15c(r5)
/* 800FED9C 000FBB9C  90 05 01 60 */	stw r0, 0x160(r5)
/* 800FEDA0 000FBBA0  90 05 01 64 */	stw r0, 0x164(r5)
/* 800FEDA4 000FBBA4  90 05 01 68 */	stw r0, 0x168(r5)
/* 800FEDA8 000FBBA8  90 05 01 6C */	stw r0, 0x16c(r5)
/* 800FEDAC 000FBBAC  90 05 01 70 */	stw r0, 0x170(r5)
/* 800FEDB0 000FBBB0  90 05 01 74 */	stw r0, 0x174(r5)
/* 800FEDB4 000FBBB4  90 05 01 78 */	stw r0, 0x178(r5)
/* 800FEDB8 000FBBB8  90 05 01 7C */	stw r0, 0x17c(r5)
/* 800FEDBC 000FBBBC  90 05 01 80 */	stw r0, 0x180(r5)
/* 800FEDC0 000FBBC0  90 05 01 84 */	stw r0, 0x184(r5)
/* 800FEDC4 000FBBC4  90 05 01 88 */	stw r0, 0x188(r5)
/* 800FEDC8 000FBBC8  80 85 00 08 */	lwz r4, 0x8(r5)
/* 800FEDCC 000FBBCC  80 04 00 14 */	lwz r0, 0x14(r4)
/* 800FEDD0 000FBBD0  28 00 00 00 */	cmplwi r0, 0x0
/* 800FEDD4 000FBBD4  41 82 00 10 */	beq .L_800FEDE4
/* 800FEDD8 000FBBD8  80 86 00 04 */	lwz r4, 0x4(r6)
/* 800FEDDC 000FBBDC  38 A0 00 00 */	li r5, 0x0
/* 800FEDE0 000FBBE0  4B FF 8A 91 */	bl kar_gryakuaudio_configure_fgm_track_from_joint
.L_800FEDE4:
/* 800FEDE4 000FBBE4  7F E3 FB 78 */	mr r3, r31
/* 800FEDE8 000FBBE8  48 00 00 19 */	bl kar_gryakugondola_start_kind48_route_idle_motion
/* 800FEDEC 000FBBEC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FEDF0 000FBBF0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FEDF4 000FBBF4  7C 08 03 A6 */	mtlr r0
/* 800FEDF8 000FBBF8  38 21 00 10 */	addi r1, r1, 0x10
/* 800FEDFC 000FBBFC  4E 80 00 20 */	blr
.endfn kar_gryakugondola_init_stage_linked_kind48_route_yaku

# .text:0x82C | 0x800FEE00 | size: 0x40
.fn kar_gryakugondola_start_kind48_route_idle_motion, global
/* 800FEE00 000FBC00  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FEE04 000FBC04  7C 08 02 A6 */	mflr r0
/* 800FEE08 000FBC08  C0 22 92 28 */	lfs f1, lbl_805DF928@sda21(r0)
/* 800FEE0C 000FBC0C  38 80 00 00 */	li r4, 0x0
/* 800FEE10 000FBC10  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FEE14 000FBC14  38 A0 FF FF */	li r5, -0x1
/* 800FEE18 000FBC18  FC 60 08 90 */	fmr f3, f1
/* 800FEE1C 000FBC1C  C0 42 92 2C */	lfs f2, lbl_805DF92C@sda21(r0)
/* 800FEE20 000FBC20  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FEE24 000FBC24  38 C0 FF FF */	li r6, -0x1
/* 800FEE28 000FBC28  38 E0 00 00 */	li r7, 0x0
/* 800FEE2C 000FBC2C  4B FF 67 1D */	bl kar_gryaku_set_path_node_motion
/* 800FEE30 000FBC30  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FEE34 000FBC34  7C 08 03 A6 */	mtlr r0
/* 800FEE38 000FBC38  38 21 00 10 */	addi r1, r1, 0x10
/* 800FEE3C 000FBC3C  4E 80 00 20 */	blr
.endfn kar_gryakugondola_start_kind48_route_idle_motion

# 0x804A6378..0x804A6430 | size: 0xB8
.data
.balign 8

# .data:0x0 | 0x804A6378 | size: 0x20
.obj kar_gryakugondola_kind46_callback_table, global
	.4byte kar_gryakugondola_reset_kind46_candidate_state
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte kar_gryakugondola_apply_armed_user_launch
	.4byte 0x00000000
	.4byte kar_gryakugondola_update_zone_contains_current_user
	.4byte 0x00000000
.endobj kar_gryakugondola_kind46_callback_table

# .data:0x20 | 0x804A6398 | size: 0x14
.obj kar_gryakugondola_kind46_callback_table_ptr, global
	.4byte kar_gryakugondola_kind46_callback_table
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj kar_gryakugondola_kind46_callback_table_ptr

# .data:0x34 | 0x804A63AC | size: 0x10
.obj kar_gryakugondola_kind47_ground_audio_callback_table, global
	.4byte kar_gryakugondola_update_kind47_ground_state_fgm
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj kar_gryakugondola_kind47_ground_audio_callback_table

# .data:0x44 | 0x804A63BC | size: 0x14
.obj kar_gryakugondola_kind47_ground_audio_callback_table_ptr, global
	.4byte kar_gryakugondola_kind47_ground_audio_callback_table
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj kar_gryakugondola_kind47_ground_audio_callback_table_ptr

# .data:0x58 | 0x804A63D0 | size: 0x10
.obj kar_src_gryakugondola_c, global
	.string "gryakugondola.c"
.endobj kar_src_gryakugondola_c

# .data:0x68 | 0x804A63E0 | size: 0x19
.obj kar_gryakugondola_assert_user_gobj, global
	.string "gyp->lc.gondola.userGObj"
.endobj kar_gryakugondola_assert_user_gobj

# .data:0x81 | 0x804A63F9 | size: 0x3
.obj gap_07_804A63F9_data, global
.hidden gap_07_804A63F9_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A63F9_data

# .data:0x84 | 0x804A63FC | size: 0x27
.obj kar_gryakugondola_assert_user_gobj_matches_old_app, global
	.string "gyp->lc.gondola.userGObj == oldAppGObj"
.endobj kar_gryakugondola_assert_user_gobj_matches_old_app

# .data:0xAB | 0x804A6423 | size: 0x1
.obj gap_07_804A6423_data, global
.hidden gap_07_804A6423_data
	.byte 0x00
.endobj gap_07_804A6423_data

# .data:0xAC | 0x804A6424 | size: 0x9
.obj kar_src_ground_h_804a6424, global
	.string "ground.h"
.endobj kar_src_ground_h_804a6424

# .data:0xB5 | 0x804A642D | size: 0x3
.obj gap_07_804A642D_data, global
.hidden gap_07_804A642D_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A642D_data

# 0x805D6270..0x805D6278 | size: 0x8
.section .sdata, "wa"
.balign 8

# .sdata:0x0 | 0x805D6270 | size: 0x2
.obj lbl_805D6270, global
	.string "0"
.endobj lbl_805D6270

# .sdata:0x2 | 0x805D6272 | size: 0x6
.obj gap_09_805D6272_sdata, global
.hidden gap_09_805D6272_sdata
	.4byte 0x00000000
	.2byte 0x0000
.endobj gap_09_805D6272_sdata

# 0x805DF920..0x805DF930 | size: 0x10
.section .sdata2, "a"
.balign 8

# .sdata2:0x0 | 0x805DF920 | size: 0x4
.obj lbl_805DF920, global
	.float 0
.endobj lbl_805DF920

# .sdata2:0x4 | 0x805DF924 | size: 0x4
.obj lbl_805DF924, global
	.float 1
.endobj lbl_805DF924

# .sdata2:0x8 | 0x805DF928 | size: 0x4
.obj lbl_805DF928, global
	.float 0
.endobj lbl_805DF928

# .sdata2:0xC | 0x805DF92C | size: 0x4
.obj lbl_805DF92C, global
	.float 1
.endobj lbl_805DF92C
