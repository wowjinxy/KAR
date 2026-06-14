.include "macros.inc"
.file "grdata.c"

# 0x800CE7A0..0x800CEC28 | size: 0x488
.text
.balign 4

# .text:0x0 | 0x800CE7A0 | size: 0x184
.fn kar_grdata__800ce7a0, global
/* 800CE7A0 000CB5A0  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800CE7A4 000CB5A4  7C 08 02 A6 */	mflr r0
/* 800CE7A8 000CB5A8  90 01 00 34 */	stw r0, 0x34(r1)
/* 800CE7AC 000CB5AC  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 800CE7B0 000CB5B0  F3 E1 00 28 */	psq_st f31, 0x28(r1), 0, qr0
/* 800CE7B4 000CB5B4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800CE7B8 000CB5B8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800CE7BC 000CB5BC  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800CE7C0 000CB5C0  93 81 00 10 */	stw r28, 0x10(r1)
/* 800CE7C4 000CB5C4  7C 7C 1B 78 */	mr r28, r3
/* 800CE7C8 000CB5C8  3C 60 80 55 */	lis r3, lbl_80557638@ha
/* 800CE7CC 000CB5CC  57 84 10 3A */	slwi r4, r28, 2
/* 800CE7D0 000CB5D0  3C A0 80 4A */	lis r5, lbl_804A2408@ha
/* 800CE7D4 000CB5D4  38 03 76 38 */	addi r0, r3, lbl_80557638@l
/* 800CE7D8 000CB5D8  7F A0 22 14 */	add r29, r0, r4
/* 800CE7DC 000CB5DC  3B E5 24 08 */	addi r31, r5, lbl_804A2408@l
/* 800CE7E0 000CB5E0  80 1D 00 00 */	lwz r0, 0x0(r29)
/* 800CE7E4 000CB5E4  28 00 00 00 */	cmplwi r0, 0x0
/* 800CE7E8 000CB5E8  40 82 01 14 */	bne .L_800CE8FC
/* 800CE7EC 000CB5EC  2C 1C 00 16 */	cmpwi r28, 0x16
/* 800CE7F0 000CB5F0  40 82 00 10 */	bne .L_800CE800
/* 800CE7F4 000CB5F4  38 1F 02 58 */	addi r0, r31, 0x258
/* 800CE7F8 000CB5F8  90 1D 00 00 */	stw r0, 0x0(r29)
/* 800CE7FC 000CB5FC  48 00 00 60 */	b .L_800CE85C
.L_800CE800:
/* 800CE800 000CB600  1C 9C 00 14 */	mulli r4, r28, 0x14
/* 800CE804 000CB604  3B DF 0B F4 */	addi r30, r31, 0xbf4
/* 800CE808 000CB608  7F A5 EB 78 */	mr r5, r29
/* 800CE80C 000CB60C  7F C0 F3 78 */	mr r0, r30
/* 800CE810 000CB610  7C C0 22 14 */	add r6, r0, r4
/* 800CE814 000CB614  38 60 00 00 */	li r3, 0x0
/* 800CE818 000CB618  7F DE 22 14 */	add r30, r30, r4
/* 800CE81C 000CB61C  80 C6 00 04 */	lwz r6, 0x4(r6)
/* 800CE820 000CB620  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 800CE824 000CB624  38 E0 00 00 */	li r7, 0x0
/* 800CE828 000CB628  4C C6 31 82 */	crclr cr1eq
/* 800CE82C 000CB62C  4B F8 B1 F5 */	bl kar_lbarchive__80059a20
/* 800CE830 000CB630  39 1E 00 08 */	addi r8, r30, 0x8
/* 800CE834 000CB634  80 FD 00 00 */	lwz r7, 0x0(r29)
/* 800CE838 000CB638  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 800CE83C 000CB63C  38 60 00 00 */	li r3, 0x0
/* 800CE840 000CB640  80 DE 00 0C */	lwz r6, 0xc(r30)
/* 800CE844 000CB644  38 A7 00 0C */	addi r5, r7, 0xc
/* 800CE848 000CB648  81 08 00 08 */	lwz r8, 0x8(r8)
/* 800CE84C 000CB64C  38 E7 00 10 */	addi r7, r7, 0x10
/* 800CE850 000CB650  39 20 00 00 */	li r9, 0x0
/* 800CE854 000CB654  4C C6 31 82 */	crclr cr1eq
/* 800CE858 000CB658  4B F8 B1 C9 */	bl kar_lbarchive__80059a20
.L_800CE85C:
/* 800CE85C 000CB65C  83 DD 00 00 */	lwz r30, 0x0(r29)
/* 800CE860 000CB660  48 19 36 6D */	bl fn_80261ECC
/* 800CE864 000CB664  48 19 3D 11 */	bl fn_80262574
/* 800CE868 000CB668  2C 03 00 00 */	cmpwi r3, 0x0
/* 800CE86C 000CB66C  41 82 00 24 */	beq .L_800CE890
/* 800CE870 000CB670  2C 1C 00 09 */	cmpwi r28, 0x9
/* 800CE874 000CB674  41 82 00 14 */	beq .L_800CE888
/* 800CE878 000CB678  38 7F 0E C8 */	addi r3, r31, 0xec8
/* 800CE87C 000CB67C  38 BF 0E D4 */	addi r5, r31, 0xed4
/* 800CE880 000CB680  38 80 00 AC */	li r4, 0xac
/* 800CE884 000CB684  48 35 9C 35 */	bl __assert
.L_800CE888:
/* 800CE888 000CB688  7F C3 F3 78 */	mr r3, r30
/* 800CE88C 000CB68C  48 04 0F 39 */	bl kar_grcity1_patch_asset_material_anim_params
.L_800CE890:
/* 800CE890 000CB690  80 9D 00 00 */	lwz r4, 0x0(r29)
/* 800CE894 000CB694  88 04 00 00 */	lbz r0, 0x0(r4)
/* 800CE898 000CB698  28 00 00 00 */	cmplwi r0, 0x0
/* 800CE89C 000CB69C  40 82 00 60 */	bne .L_800CE8FC
/* 800CE8A0 000CB6A0  80 64 00 04 */	lwz r3, 0x4(r4)
/* 800CE8A4 000CB6A4  38 00 00 01 */	li r0, 0x1
/* 800CE8A8 000CB6A8  28 03 00 00 */	cmplwi r3, 0x0
/* 800CE8AC 000CB6AC  98 04 00 00 */	stb r0, 0x0(r4)
/* 800CE8B0 000CB6B0  41 82 00 0C */	beq .L_800CE8BC
/* 800CE8B4 000CB6B4  C3 E3 00 08 */	lfs f31, 0x8(r3)
/* 800CE8B8 000CB6B8  48 00 00 08 */	b .L_800CE8C0
.L_800CE8BC:
/* 800CE8BC 000CB6BC  C3 E2 8E C8 */	lfs f31, lbl_805DF5C8@sda21(r0)
.L_800CE8C0:
/* 800CE8C0 000CB6C0  80 64 00 0C */	lwz r3, 0xc(r4)
/* 800CE8C4 000CB6C4  83 E4 00 48 */	lwz r31, 0x48(r4)
/* 800CE8C8 000CB6C8  28 03 00 00 */	cmplwi r3, 0x0
/* 800CE8CC 000CB6CC  83 C4 00 1C */	lwz r30, 0x1c(r4)
/* 800CE8D0 000CB6D0  41 82 00 14 */	beq .L_800CE8E4
/* 800CE8D4 000CB6D4  80 63 00 00 */	lwz r3, 0x0(r3)
/* 800CE8D8 000CB6D8  FC 20 F8 90 */	fmr f1, f31
/* 800CE8DC 000CB6DC  80 63 00 10 */	lwz r3, 0x10(r3)
/* 800CE8E0 000CB6E0  48 01 71 49 */	bl kar_grnullpos_scale_setup_position_data
.L_800CE8E4:
/* 800CE8E4 000CB6E4  FC 20 F8 90 */	fmr f1, f31
/* 800CE8E8 000CB6E8  80 7F 00 00 */	lwz r3, 0x0(r31)
/* 800CE8EC 000CB6EC  4B F9 FD 79 */	bl kar_lbspline__near_8006e664
/* 800CE8F0 000CB6F0  FC 20 F8 90 */	fmr f1, f31
/* 800CE8F4 000CB6F4  7F C3 F3 78 */	mr r3, r30
/* 800CE8F8 000CB6F8  48 00 FC 1D */	bl kar_grdata_scale_all_spline_sets
.L_800CE8FC:
/* 800CE8FC 000CB6FC  E3 E1 00 28 */	psq_l f31, 0x28(r1), 0, qr0
/* 800CE900 000CB700  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800CE904 000CB704  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 800CE908 000CB708  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800CE90C 000CB70C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800CE910 000CB710  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800CE914 000CB714  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800CE918 000CB718  7C 08 03 A6 */	mtlr r0
/* 800CE91C 000CB71C  38 21 00 30 */	addi r1, r1, 0x30
/* 800CE920 000CB720  4E 80 00 20 */	blr
.endfn kar_grdata__800ce7a0

# .text:0x184 | 0x800CE924 | size: 0x40
.fn kar_gr_assets__asset_800ce924, global
/* 800CE924 000CB724  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800CE928 000CB728  7C 08 02 A6 */	mflr r0
/* 800CE92C 000CB72C  3C 80 80 4A */	lis r4, kar_asset_grcity1event_804a329c@ha
/* 800CE930 000CB730  3C C0 80 4A */	lis r6, lbl_804A32F4@ha
/* 800CE934 000CB734  90 01 00 14 */	stw r0, 0x14(r1)
/* 800CE938 000CB738  7C 65 1B 78 */	mr r5, r3
/* 800CE93C 000CB73C  38 60 00 00 */	li r3, 0x0
/* 800CE940 000CB740  38 84 32 9C */	addi r4, r4, kar_asset_grcity1event_804a329c@l
/* 800CE944 000CB744  38 C6 32 F4 */	addi r6, r6, lbl_804A32F4@l
/* 800CE948 000CB748  38 E0 00 00 */	li r7, 0x0
/* 800CE94C 000CB74C  4C C6 31 82 */	crclr cr1eq
/* 800CE950 000CB750  4B F8 B0 D1 */	bl kar_lbarchive__80059a20
/* 800CE954 000CB754  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800CE958 000CB758  7C 08 03 A6 */	mtlr r0
/* 800CE95C 000CB75C  38 21 00 10 */	addi r1, r1, 0x10
/* 800CE960 000CB760  4E 80 00 20 */	blr
.endfn kar_gr_assets__asset_800ce924

# .text:0x1C4 | 0x800CE964 | size: 0xF8
.fn kar_gr_assets__asset_800ce964, global
/* 800CE964 000CB764  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800CE968 000CB768  7C 08 02 A6 */	mflr r0
/* 800CE96C 000CB76C  90 01 00 24 */	stw r0, 0x24(r1)
/* 800CE970 000CB770  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800CE974 000CB774  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800CE978 000CB778  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800CE97C 000CB77C  7C 7D 1B 78 */	mr r29, r3
/* 800CE980 000CB780  48 19 33 69 */	bl fn_80261CE8
/* 800CE984 000CB784  7C 7E 1B 78 */	mr r30, r3
/* 800CE988 000CB788  38 00 00 00 */	li r0, 0x0
/* 800CE98C 000CB78C  1F FE 00 14 */	mulli r31, r30, 0x14
/* 800CE990 000CB790  3C 60 80 4A */	lis r3, kar_course_dat_model_resource_table@ha
/* 800CE994 000CB794  90 01 00 08 */	stw r0, 0x8(r1)
/* 800CE998 000CB798  38 A0 00 04 */	li r5, 0x4
/* 800CE99C 000CB79C  38 83 2F FC */	addi r4, r3, kar_course_dat_model_resource_table@l
/* 800CE9A0 000CB7A0  7C 84 F8 2E */	lwzx r4, r4, r31
/* 800CE9A4 000CB7A4  38 60 00 02 */	li r3, 0x2
/* 800CE9A8 000CB7A8  38 C0 00 04 */	li r6, 0x4
/* 800CE9AC 000CB7AC  38 E0 00 00 */	li r7, 0x0
/* 800CE9B0 000CB7B0  39 00 00 01 */	li r8, 0x1
/* 800CE9B4 000CB7B4  39 20 00 08 */	li r9, 0x8
/* 800CE9B8 000CB7B8  39 40 00 10 */	li r10, 0x10
/* 800CE9BC 000CB7BC  4B FA 42 D5 */	bl kar_lbkdcoll__near_80072c90
/* 800CE9C0 000CB7C0  38 80 00 00 */	li r4, 0x0
/* 800CE9C4 000CB7C4  3C 60 80 4A */	lis r3, kar_course_dat_model_resource_table@ha
/* 800CE9C8 000CB7C8  38 03 2F FC */	addi r0, r3, kar_course_dat_model_resource_table@l
/* 800CE9CC 000CB7CC  90 81 00 08 */	stw r4, 0x8(r1)
/* 800CE9D0 000CB7D0  7C 80 FA 14 */	add r4, r0, r31
/* 800CE9D4 000CB7D4  38 60 00 02 */	li r3, 0x2
/* 800CE9D8 000CB7D8  80 84 00 08 */	lwz r4, 0x8(r4)
/* 800CE9DC 000CB7DC  38 A0 00 04 */	li r5, 0x4
/* 800CE9E0 000CB7E0  38 C0 00 04 */	li r6, 0x4
/* 800CE9E4 000CB7E4  38 E0 00 00 */	li r7, 0x0
/* 800CE9E8 000CB7E8  39 00 00 01 */	li r8, 0x1
/* 800CE9EC 000CB7EC  39 20 00 08 */	li r9, 0x8
/* 800CE9F0 000CB7F0  39 40 00 10 */	li r10, 0x10
/* 800CE9F4 000CB7F4  4B FA 42 9D */	bl kar_lbkdcoll__near_80072c90
/* 800CE9F8 000CB7F8  7F C3 F3 78 */	mr r3, r30
/* 800CE9FC 000CB7FC  48 16 6E C9 */	bl kar_efdata__near_802358c4
/* 800CEA00 000CB800  7F A3 EB 78 */	mr r3, r29
/* 800CEA04 000CB804  48 19 3B 71 */	bl fn_80262574
/* 800CEA08 000CB808  2C 03 00 00 */	cmpwi r3, 0x0
/* 800CEA0C 000CB80C  41 82 00 34 */	beq .L_800CEA40
/* 800CEA10 000CB810  38 00 00 00 */	li r0, 0x0
/* 800CEA14 000CB814  3C 60 80 4A */	lis r3, kar_asset_grcity1event_804a329c@ha
/* 800CEA18 000CB818  90 01 00 08 */	stw r0, 0x8(r1)
/* 800CEA1C 000CB81C  38 83 32 9C */	addi r4, r3, kar_asset_grcity1event_804a329c@l
/* 800CEA20 000CB820  38 60 00 02 */	li r3, 0x2
/* 800CEA24 000CB824  38 A0 00 04 */	li r5, 0x4
/* 800CEA28 000CB828  38 C0 00 04 */	li r6, 0x4
/* 800CEA2C 000CB82C  38 E0 00 00 */	li r7, 0x0
/* 800CEA30 000CB830  39 00 00 01 */	li r8, 0x1
/* 800CEA34 000CB834  39 20 00 08 */	li r9, 0x8
/* 800CEA38 000CB838  39 40 00 10 */	li r10, 0x10
/* 800CEA3C 000CB83C  4B FA 42 55 */	bl kar_lbkdcoll__near_80072c90
.L_800CEA40:
/* 800CEA40 000CB840  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800CEA44 000CB844  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800CEA48 000CB848  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800CEA4C 000CB84C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800CEA50 000CB850  7C 08 03 A6 */	mtlr r0
/* 800CEA54 000CB854  38 21 00 20 */	addi r1, r1, 0x20
/* 800CEA58 000CB858  4E 80 00 20 */	blr
.endfn kar_gr_assets__asset_800ce964

# .text:0x2BC | 0x800CEA5C | size: 0x24
.fn kar_grdata__near_800cea5c, global
/* 800CEA5C 000CB85C  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 800CEA60 000CB860  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800CEA64 000CB864  80 63 00 14 */	lwz r3, 0x14(r3)
/* 800CEA68 000CB868  28 03 00 00 */	cmplwi r3, 0x0
/* 800CEA6C 000CB86C  41 82 00 0C */	beq .L_800CEA78
/* 800CEA70 000CB870  80 63 00 04 */	lwz r3, 0x4(r3)
/* 800CEA74 000CB874  4E 80 00 20 */	blr
.L_800CEA78:
/* 800CEA78 000CB878  38 60 00 00 */	li r3, 0x0
/* 800CEA7C 000CB87C  4E 80 00 20 */	blr
.endfn kar_grdata__near_800cea5c

# .text:0x2E0 | 0x800CEA80 | size: 0x24
.fn kar_grdata__near_800cea80, global
/* 800CEA80 000CB880  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 800CEA84 000CB884  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800CEA88 000CB888  80 63 00 04 */	lwz r3, 0x4(r3)
/* 800CEA8C 000CB88C  28 03 00 00 */	cmplwi r3, 0x0
/* 800CEA90 000CB890  41 82 00 0C */	beq .L_800CEA9C
/* 800CEA94 000CB894  C0 23 00 04 */	lfs f1, 0x4(r3)
/* 800CEA98 000CB898  4E 80 00 20 */	blr
.L_800CEA9C:
/* 800CEA9C 000CB89C  C0 22 8E D0 */	lfs f1, lbl_805DF5D0@sda21(r0)
/* 800CEAA0 000CB8A0  4E 80 00 20 */	blr
.endfn kar_grdata__near_800cea80

# .text:0x304 | 0x800CEAA4 | size: 0x14
.fn kar_grdata__near_800ceaa4, global
/* 800CEAA4 000CB8A4  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 800CEAA8 000CB8A8  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800CEAAC 000CB8AC  80 63 00 04 */	lwz r3, 0x4(r3)
/* 800CEAB0 000CB8B0  88 63 00 81 */	lbz r3, 0x81(r3)
/* 800CEAB4 000CB8B4  4E 80 00 20 */	blr
.endfn kar_grdata__near_800ceaa4

# .text:0x318 | 0x800CEAB8 | size: 0x14
.fn kar_grdata__near_800ceab8, global
/* 800CEAB8 000CB8B8  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 800CEABC 000CB8BC  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800CEAC0 000CB8C0  80 63 00 04 */	lwz r3, 0x4(r3)
/* 800CEAC4 000CB8C4  C0 23 00 60 */	lfs f1, 0x60(r3)
/* 800CEAC8 000CB8C8  4E 80 00 20 */	blr
.endfn kar_grdata__near_800ceab8

# .text:0x32C | 0x800CEACC | size: 0x28
.fn kar_grdata__near_800ceacc, global
/* 800CEACC 000CB8CC  80 8D 05 EC */	lwz r4, lbl_805DD6CC@sda21(r0)
/* 800CEAD0 000CB8D0  80 84 00 08 */	lwz r4, 0x8(r4)
/* 800CEAD4 000CB8D4  80 A4 00 04 */	lwz r5, 0x4(r4)
/* 800CEAD8 000CB8D8  80 85 00 64 */	lwz r4, 0x64(r5)
/* 800CEADC 000CB8DC  80 05 00 68 */	lwz r0, 0x68(r5)
/* 800CEAE0 000CB8E0  90 83 00 00 */	stw r4, 0x0(r3)
/* 800CEAE4 000CB8E4  90 03 00 04 */	stw r0, 0x4(r3)
/* 800CEAE8 000CB8E8  80 05 00 6C */	lwz r0, 0x6c(r5)
/* 800CEAEC 000CB8EC  90 03 00 08 */	stw r0, 0x8(r3)
/* 800CEAF0 000CB8F0  4E 80 00 20 */	blr
.endfn kar_grdata__near_800ceacc

# .text:0x354 | 0x800CEAF4 | size: 0x24
.fn kar_grdata__near_800ceaf4, global
/* 800CEAF4 000CB8F4  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 800CEAF8 000CB8F8  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800CEAFC 000CB8FC  80 63 00 04 */	lwz r3, 0x4(r3)
/* 800CEB00 000CB900  28 03 00 00 */	cmplwi r3, 0x0
/* 800CEB04 000CB904  41 82 00 0C */	beq .L_800CEB10
/* 800CEB08 000CB908  88 63 00 80 */	lbz r3, 0x80(r3)
/* 800CEB0C 000CB90C  4E 80 00 20 */	blr
.L_800CEB10:
/* 800CEB10 000CB910  38 60 00 00 */	li r3, 0x0
/* 800CEB14 000CB914  4E 80 00 20 */	blr
.endfn kar_grdata__near_800ceaf4

# .text:0x378 | 0x800CEB18 | size: 0x110
.fn kar_grdata__near_800ceb18, global
/* 800CEB18 000CB918  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800CEB1C 000CB91C  7C 08 02 A6 */	mflr r0
/* 800CEB20 000CB920  90 01 00 24 */	stw r0, 0x24(r1)
/* 800CEB24 000CB924  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800CEB28 000CB928  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800CEB2C 000CB92C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800CEB30 000CB930  7C 9D 23 78 */	mr r29, r4
/* 800CEB34 000CB934  93 81 00 10 */	stw r28, 0x10(r1)
/* 800CEB38 000CB938  7C 7C 1B 78 */	mr r28, r3
/* 800CEB3C 000CB93C  7F 84 E3 78 */	mr r4, r28
/* 800CEB40 000CB940  83 CD 05 EC */	lwz r30, lbl_805DD6CC@sda21(r0)
/* 800CEB44 000CB944  80 BE 00 08 */	lwz r5, 0x8(r30)
/* 800CEB48 000CB948  7F C3 F3 78 */	mr r3, r30
/* 800CEB4C 000CB94C  83 E5 00 04 */	lwz r31, 0x4(r5)
/* 800CEB50 000CB950  7F A5 EB 78 */	mr r5, r29
/* 800CEB54 000CB954  48 01 7C E1 */	bl kar_grgravity_calc_nearest_nullpos_gravity
/* 800CEB58 000CB958  C0 02 8E D4 */	lfs f0, lbl_805DF5D4@sda21(r0)
/* 800CEB5C 000CB95C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800CEB60 000CB960  40 80 00 18 */	bge .L_800CEB78
/* 800CEB64 000CB964  C0 02 8E D8 */	lfs f0, lbl_805DF5D8@sda21(r0)
/* 800CEB68 000CB968  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800CEB6C 000CB96C  40 81 00 0C */	ble .L_800CEB78
/* 800CEB70 000CB970  38 00 00 01 */	li r0, 0x1
/* 800CEB74 000CB974  48 00 00 08 */	b .L_800CEB7C
.L_800CEB78:
/* 800CEB78 000CB978  38 00 00 00 */	li r0, 0x0
.L_800CEB7C:
/* 800CEB7C 000CB97C  2C 00 00 00 */	cmpwi r0, 0x0
/* 800CEB80 000CB980  40 82 00 08 */	bne .L_800CEB88
/* 800CEB84 000CB984  48 00 00 84 */	b .L_800CEC08
.L_800CEB88:
/* 800CEB88 000CB988  7F C3 F3 78 */	mr r3, r30
/* 800CEB8C 000CB98C  7F 84 E3 78 */	mr r4, r28
/* 800CEB90 000CB990  7F A5 EB 78 */	mr r5, r29
/* 800CEB94 000CB994  48 01 7E 1D */	bl kar_grgravity_calc_nearest_spline_gravity
/* 800CEB98 000CB998  C0 02 8E D4 */	lfs f0, lbl_805DF5D4@sda21(r0)
/* 800CEB9C 000CB99C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800CEBA0 000CB9A0  40 80 00 18 */	bge .L_800CEBB8
/* 800CEBA4 000CB9A4  C0 02 8E D8 */	lfs f0, lbl_805DF5D8@sda21(r0)
/* 800CEBA8 000CB9A8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800CEBAC 000CB9AC  40 81 00 0C */	ble .L_800CEBB8
/* 800CEBB0 000CB9B0  38 00 00 01 */	li r0, 0x1
/* 800CEBB4 000CB9B4  48 00 00 08 */	b .L_800CEBBC
.L_800CEBB8:
/* 800CEBB8 000CB9B8  38 00 00 00 */	li r0, 0x0
.L_800CEBBC:
/* 800CEBBC 000CB9BC  2C 00 00 00 */	cmpwi r0, 0x0
/* 800CEBC0 000CB9C0  40 82 00 08 */	bne .L_800CEBC8
/* 800CEBC4 000CB9C4  48 00 00 44 */	b .L_800CEC08
.L_800CEBC8:
/* 800CEBC8 000CB9C8  28 1F 00 00 */	cmplwi r31, 0x0
/* 800CEBCC 000CB9CC  41 82 00 24 */	beq .L_800CEBF0
/* 800CEBD0 000CB9D0  80 7F 00 10 */	lwz r3, 0x10(r31)
/* 800CEBD4 000CB9D4  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 800CEBD8 000CB9D8  90 7D 00 00 */	stw r3, 0x0(r29)
/* 800CEBDC 000CB9DC  90 1D 00 04 */	stw r0, 0x4(r29)
/* 800CEBE0 000CB9E0  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 800CEBE4 000CB9E4  90 1D 00 08 */	stw r0, 0x8(r29)
/* 800CEBE8 000CB9E8  C0 3F 00 0C */	lfs f1, 0xc(r31)
/* 800CEBEC 000CB9EC  48 00 00 1C */	b .L_800CEC08
.L_800CEBF0:
/* 800CEBF0 000CB9F0  C0 42 8E DC */	lfs f2, lbl_805DF5DC@sda21(r0)
/* 800CEBF4 000CB9F4  C0 02 8E E0 */	lfs f0, lbl_805DF5E0@sda21(r0)
/* 800CEBF8 000CB9F8  D0 5D 00 00 */	stfs f2, 0x0(r29)
/* 800CEBFC 000CB9FC  C0 22 8E E4 */	lfs f1, lbl_805DF5E4@sda21(r0)
/* 800CEC00 000CBA00  D0 1D 00 04 */	stfs f0, 0x4(r29)
/* 800CEC04 000CBA04  D0 5D 00 08 */	stfs f2, 0x8(r29)
.L_800CEC08:
/* 800CEC08 000CBA08  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800CEC0C 000CBA0C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800CEC10 000CBA10  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800CEC14 000CBA14  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800CEC18 000CBA18  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800CEC1C 000CBA1C  7C 08 03 A6 */	mtlr r0
/* 800CEC20 000CBA20  38 21 00 20 */	addi r1, r1, 0x20
/* 800CEC24 000CBA24  4E 80 00 20 */	blr
.endfn kar_grdata__near_800ceb18

# 0x804A2648..0x804A3AF0 | size: 0x14A8
.data
.balign 8

# .data:0x0 | 0x804A2648 | size: 0x6C
.obj lbl_804A2648, global
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte lbl_804A2528
	.4byte lbl_804A2558
	.4byte lbl_804A2610
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte lbl_804A2648
	.4byte 0x00000000
	.4byte lbl_805D608C
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A2648

# .data:0x6C | 0x804A26B4 | size: 0xE
.obj kar_linkfile_grplants1_dat_804a26b4, global
	.string "GrPlants1.dat"
.endobj kar_linkfile_grplants1_dat_804a26b4

# .data:0x7A | 0x804A26C2 | size: 0x2
.obj gap_07_804A26C2_data, global
.hidden gap_07_804A26C2_data
	.2byte 0x0000
.endobj gap_07_804A26C2_data

# .data:0x7C | 0x804A26C4 | size: 0xE
.obj lbl_804A26C4, global
	.string "grDataPlants1"
.endobj lbl_804A26C4

# .data:0x8A | 0x804A26D2 | size: 0x2
.obj gap_07_804A26D2_data, global
.hidden gap_07_804A26D2_data
	.2byte 0x0000
.endobj gap_07_804A26D2_data

# .data:0x8C | 0x804A26D4 | size: 0x13
.obj kar_linkfile_grplants1model_dat_804a26d4, global
	.string "GrPlants1Model.dat"
.endobj kar_linkfile_grplants1model_dat_804a26d4

# .data:0x9F | 0x804A26E7 | size: 0x1
.obj gap_07_804A26E7_data, global
.hidden gap_07_804A26E7_data
	.byte 0x00
.endobj gap_07_804A26E7_data

# .data:0xA0 | 0x804A26E8 | size: 0xF
.obj lbl_804A26E8, global
	.string "grModelPlants1"
.endobj lbl_804A26E8

# .data:0xAF | 0x804A26F7 | size: 0x1
.obj gap_07_804A26F7_data, global
.hidden gap_07_804A26F7_data
	.byte 0x00
.endobj gap_07_804A26F7_data

# .data:0xB0 | 0x804A26F8 | size: 0x15
.obj lbl_804A26F8, global
	.string "grModelMotionPlants1"
.endobj lbl_804A26F8

# .data:0xC5 | 0x804A270D | size: 0x3
.obj gap_07_804A270D_data, global
.hidden gap_07_804A270D_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A270D_data

# .data:0xC8 | 0x804A2710 | size: 0xC
.obj kar_linkfile_grheat2_dat_804a2710, global
	.string "GrHeat2.dat"
.endobj kar_linkfile_grheat2_dat_804a2710

# .data:0xD4 | 0x804A271C | size: 0xC
.obj lbl_804A271C, global
	.string "grDataHeat2"
.endobj lbl_804A271C

# .data:0xE0 | 0x804A2728 | size: 0x11
.obj kar_linkfile_grheat2model_dat_804a2728, global
	.string "GrHeat2Model.dat"
.endobj kar_linkfile_grheat2model_dat_804a2728

# .data:0xF1 | 0x804A2739 | size: 0x3
.obj gap_07_804A2739_data, global
.hidden gap_07_804A2739_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2739_data

# .data:0xF4 | 0x804A273C | size: 0xD
.obj lbl_804A273C, global
	.string "grModelHeat2"
.endobj lbl_804A273C

# .data:0x101 | 0x804A2749 | size: 0x3
.obj gap_07_804A2749_data, global
.hidden gap_07_804A2749_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2749_data

# .data:0x104 | 0x804A274C | size: 0x13
.obj lbl_804A274C, global
	.string "grModelMotionHeat2"
.endobj lbl_804A274C

# .data:0x117 | 0x804A275F | size: 0x1
.obj gap_07_804A275F_data, global
.hidden gap_07_804A275F_data
	.byte 0x00
.endobj gap_07_804A275F_data

# .data:0x118 | 0x804A2760 | size: 0xE
.obj kar_linkfile_grdesert1_dat_804a2760, global
	.string "GrDesert1.dat"
.endobj kar_linkfile_grdesert1_dat_804a2760

# .data:0x126 | 0x804A276E | size: 0x2
.obj gap_07_804A276E_data, global
.hidden gap_07_804A276E_data
	.2byte 0x0000
.endobj gap_07_804A276E_data

# .data:0x128 | 0x804A2770 | size: 0xE
.obj lbl_804A2770, global
	.string "grDataDesert1"
.endobj lbl_804A2770

# .data:0x136 | 0x804A277E | size: 0x2
.obj gap_07_804A277E_data, global
.hidden gap_07_804A277E_data
	.2byte 0x0000
.endobj gap_07_804A277E_data

# .data:0x138 | 0x804A2780 | size: 0x13
.obj kar_linkfile_grdesert1model_dat_804a2780, global
	.string "GrDesert1Model.dat"
.endobj kar_linkfile_grdesert1model_dat_804a2780

# .data:0x14B | 0x804A2793 | size: 0x1
.obj gap_07_804A2793_data, global
.hidden gap_07_804A2793_data
	.byte 0x00
.endobj gap_07_804A2793_data

# .data:0x14C | 0x804A2794 | size: 0xF
.obj lbl_804A2794, global
	.string "grModelDesert1"
.endobj lbl_804A2794

# .data:0x15B | 0x804A27A3 | size: 0x1
.obj gap_07_804A27A3_data, global
.hidden gap_07_804A27A3_data
	.byte 0x00
.endobj gap_07_804A27A3_data

# .data:0x15C | 0x804A27A4 | size: 0x15
.obj lbl_804A27A4, global
	.string "grModelMotionDesert1"
.endobj lbl_804A27A4

# .data:0x171 | 0x804A27B9 | size: 0x3
.obj gap_07_804A27B9_data, global
.hidden gap_07_804A27B9_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A27B9_data

# .data:0x174 | 0x804A27BC | size: 0xD
.obj kar_linkfile_grcheck2_dat_804a27bc, global
	.string "GrCheck2.dat"
.endobj kar_linkfile_grcheck2_dat_804a27bc

# .data:0x181 | 0x804A27C9 | size: 0x3
.obj gap_07_804A27C9_data, global
.hidden gap_07_804A27C9_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A27C9_data

# .data:0x184 | 0x804A27CC | size: 0xD
.obj lbl_804A27CC, global
	.string "grDataCheck2"
.endobj lbl_804A27CC

# .data:0x191 | 0x804A27D9 | size: 0x3
.obj gap_07_804A27D9_data, global
.hidden gap_07_804A27D9_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A27D9_data

# .data:0x194 | 0x804A27DC | size: 0x12
.obj kar_linkfile_grcheck2model_dat_804a27dc, global
	.string "GrCheck2Model.dat"
.endobj kar_linkfile_grcheck2model_dat_804a27dc

# .data:0x1A6 | 0x804A27EE | size: 0x2
.obj gap_07_804A27EE_data, global
.hidden gap_07_804A27EE_data
	.2byte 0x0000
.endobj gap_07_804A27EE_data

# .data:0x1A8 | 0x804A27F0 | size: 0xE
.obj lbl_804A27F0, global
	.string "grModelCheck2"
.endobj lbl_804A27F0

# .data:0x1B6 | 0x804A27FE | size: 0x2
.obj gap_07_804A27FE_data, global
.hidden gap_07_804A27FE_data
	.2byte 0x0000
.endobj gap_07_804A27FE_data

# .data:0x1B8 | 0x804A2800 | size: 0x14
.obj lbl_804A2800, global
	.string "grModelMotionCheck2"
.endobj lbl_804A2800

# .data:0x1CC | 0x804A2814 | size: 0xE
.obj kar_linkfile_grvalley2_dat_804a2814, global
	.string "GrValley2.dat"
.endobj kar_linkfile_grvalley2_dat_804a2814

# .data:0x1DA | 0x804A2822 | size: 0x2
.obj gap_07_804A2822_data, global
.hidden gap_07_804A2822_data
	.2byte 0x0000
.endobj gap_07_804A2822_data

# .data:0x1DC | 0x804A2824 | size: 0xE
.obj lbl_804A2824, global
	.string "grDataValley2"
.endobj lbl_804A2824

# .data:0x1EA | 0x804A2832 | size: 0x2
.obj gap_07_804A2832_data, global
.hidden gap_07_804A2832_data
	.2byte 0x0000
.endobj gap_07_804A2832_data

# .data:0x1EC | 0x804A2834 | size: 0x13
.obj kar_linkfile_grvalley2model_dat_804a2834, global
	.string "GrValley2Model.dat"
.endobj kar_linkfile_grvalley2model_dat_804a2834

# .data:0x1FF | 0x804A2847 | size: 0x1
.obj gap_07_804A2847_data, global
.hidden gap_07_804A2847_data
	.byte 0x00
.endobj gap_07_804A2847_data

# .data:0x200 | 0x804A2848 | size: 0xF
.obj lbl_804A2848, global
	.string "grModelValley2"
.endobj lbl_804A2848

# .data:0x20F | 0x804A2857 | size: 0x1
.obj gap_07_804A2857_data, global
.hidden gap_07_804A2857_data
	.byte 0x00
.endobj gap_07_804A2857_data

# .data:0x210 | 0x804A2858 | size: 0x15
.obj lbl_804A2858, global
	.string "grModelMotionValley2"
.endobj lbl_804A2858

# .data:0x225 | 0x804A286D | size: 0x3
.obj gap_07_804A286D_data, global
.hidden gap_07_804A286D_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A286D_data

# .data:0x228 | 0x804A2870 | size: 0xF
.obj kar_linkfile_grmachine2_dat_804a2870, global
	.string "GrMachine2.dat"
.endobj kar_linkfile_grmachine2_dat_804a2870

# .data:0x237 | 0x804A287F | size: 0x1
.obj gap_07_804A287F_data, global
.hidden gap_07_804A287F_data
	.byte 0x00
.endobj gap_07_804A287F_data

# .data:0x238 | 0x804A2880 | size: 0xF
.obj lbl_804A2880, global
	.string "grDataMachine2"
.endobj lbl_804A2880

# .data:0x247 | 0x804A288F | size: 0x1
.obj gap_07_804A288F_data, global
.hidden gap_07_804A288F_data
	.byte 0x00
.endobj gap_07_804A288F_data

# .data:0x248 | 0x804A2890 | size: 0x14
.obj kar_linkfile_grmachine2model_dat_804a2890, global
	.string "GrMachine2Model.dat"
.endobj kar_linkfile_grmachine2model_dat_804a2890

# .data:0x25C | 0x804A28A4 | size: 0x10
.obj lbl_804A28A4, global
	.string "grModelMachine2"
.endobj lbl_804A28A4

# .data:0x26C | 0x804A28B4 | size: 0x16
.obj lbl_804A28B4, global
	.string "grModelMotionMachine2"
.endobj lbl_804A28B4

# .data:0x282 | 0x804A28CA | size: 0x2
.obj gap_07_804A28CA_data, global
.hidden gap_07_804A28CA_data
	.2byte 0x0000
.endobj gap_07_804A28CA_data

# .data:0x284 | 0x804A28CC | size: 0xD
.obj kar_linkfile_grspace2_dat_804a28cc, global
	.string "GrSpace2.dat"
.endobj kar_linkfile_grspace2_dat_804a28cc

# .data:0x291 | 0x804A28D9 | size: 0x3
.obj gap_07_804A28D9_data, global
.hidden gap_07_804A28D9_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A28D9_data

# .data:0x294 | 0x804A28DC | size: 0xD
.obj lbl_804A28DC, global
	.string "grDataSpace2"
.endobj lbl_804A28DC

# .data:0x2A1 | 0x804A28E9 | size: 0x3
.obj gap_07_804A28E9_data, global
.hidden gap_07_804A28E9_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A28E9_data

# .data:0x2A4 | 0x804A28EC | size: 0x12
.obj kar_linkfile_grspace2model_dat_804a28ec, global
	.string "GrSpace2Model.dat"
.endobj kar_linkfile_grspace2model_dat_804a28ec

# .data:0x2B6 | 0x804A28FE | size: 0x2
.obj gap_07_804A28FE_data, global
.hidden gap_07_804A28FE_data
	.2byte 0x0000
.endobj gap_07_804A28FE_data

# .data:0x2B8 | 0x804A2900 | size: 0xE
.obj lbl_804A2900, global
	.string "grModelSpace2"
.endobj lbl_804A2900

# .data:0x2C6 | 0x804A290E | size: 0x2
.obj gap_07_804A290E_data, global
.hidden gap_07_804A290E_data
	.2byte 0x0000
.endobj gap_07_804A290E_data

# .data:0x2C8 | 0x804A2910 | size: 0x14
.obj lbl_804A2910, global
	.string "grModelMotionSpace2"
.endobj lbl_804A2910

# .data:0x2DC | 0x804A2924 | size: 0xB
.obj kar_linkfile_grsky2_dat_804a2924, global
	.string "GrSky2.dat"
.endobj kar_linkfile_grsky2_dat_804a2924

# .data:0x2E7 | 0x804A292F | size: 0x1
.obj gap_07_804A292F_data, global
.hidden gap_07_804A292F_data
	.byte 0x00
.endobj gap_07_804A292F_data

# .data:0x2E8 | 0x804A2930 | size: 0xB
.obj lbl_804A2930, global
	.string "grDataSky2"
.endobj lbl_804A2930

# .data:0x2F3 | 0x804A293B | size: 0x1
.obj gap_07_804A293B_data, global
.hidden gap_07_804A293B_data
	.byte 0x00
.endobj gap_07_804A293B_data

# .data:0x2F4 | 0x804A293C | size: 0x10
.obj kar_linkfile_grsky2model_dat_804a293c, global
	.string "GrSky2Model.dat"
.endobj kar_linkfile_grsky2model_dat_804a293c

# .data:0x304 | 0x804A294C | size: 0xC
.obj lbl_804A294C, global
	.string "grModelSky2"
.endobj lbl_804A294C

# .data:0x310 | 0x804A2958 | size: 0x12
.obj lbl_804A2958, global
	.string "grModelMotionSky2"
.endobj lbl_804A2958

# .data:0x322 | 0x804A296A | size: 0x2
.obj gap_07_804A296A_data, global
.hidden gap_07_804A296A_data
	.2byte 0x0000
.endobj gap_07_804A296A_data

# .data:0x324 | 0x804A296C | size: 0xB
.obj kar_linkfile_grice1_dat_804a296c, global
	.string "GrIce1.dat"
.endobj kar_linkfile_grice1_dat_804a296c

# .data:0x32F | 0x804A2977 | size: 0x1
.obj gap_07_804A2977_data, global
.hidden gap_07_804A2977_data
	.byte 0x00
.endobj gap_07_804A2977_data

# .data:0x330 | 0x804A2978 | size: 0xB
.obj lbl_804A2978, global
	.string "grDataIce1"
.endobj lbl_804A2978

# .data:0x33B | 0x804A2983 | size: 0x1
.obj gap_07_804A2983_data, global
.hidden gap_07_804A2983_data
	.byte 0x00
.endobj gap_07_804A2983_data

# .data:0x33C | 0x804A2984 | size: 0x10
.obj kar_linkfile_grice1model_dat_804a2984, global
	.string "GrIce1Model.dat"
.endobj kar_linkfile_grice1model_dat_804a2984

# .data:0x34C | 0x804A2994 | size: 0xC
.obj lbl_804A2994, global
	.string "grModelIce1"
.endobj lbl_804A2994

# .data:0x358 | 0x804A29A0 | size: 0x12
.obj lbl_804A29A0, global
	.string "grModelMotionIce1"
.endobj lbl_804A29A0

# .data:0x36A | 0x804A29B2 | size: 0x2
.obj gap_07_804A29B2_data, global
.hidden gap_07_804A29B2_data
	.2byte 0x0000
.endobj gap_07_804A29B2_data

# .data:0x36C | 0x804A29B4 | size: 0xC
.obj kar_linkfile_grcity1_dat_804a29b4, global
	.string "GrCity1.dat"
.endobj kar_linkfile_grcity1_dat_804a29b4

# .data:0x378 | 0x804A29C0 | size: 0xC
.obj lbl_804A29C0, global
	.string "grDataCity1"
.endobj lbl_804A29C0

# .data:0x384 | 0x804A29CC | size: 0x11
.obj kar_linkfile_grcity1model_dat_804a29cc, global
	.string "GrCity1Model.dat"
.endobj kar_linkfile_grcity1model_dat_804a29cc

# .data:0x395 | 0x804A29DD | size: 0x3
.obj gap_07_804A29DD_data, global
.hidden gap_07_804A29DD_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A29DD_data

# .data:0x398 | 0x804A29E0 | size: 0xD
.obj lbl_804A29E0, global
	.string "grModelCity1"
.endobj lbl_804A29E0

# .data:0x3A5 | 0x804A29ED | size: 0x3
.obj gap_07_804A29ED_data, global
.hidden gap_07_804A29ED_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A29ED_data

# .data:0x3A8 | 0x804A29F0 | size: 0x13
.obj lbl_804A29F0, global
	.string "grModelMotionCity1"
.endobj lbl_804A29F0

# .data:0x3BB | 0x804A2A03 | size: 0x1
.obj gap_07_804A2A03_data, global
.hidden gap_07_804A2A03_data
	.byte 0x00
.endobj gap_07_804A2A03_data

# .data:0x3BC | 0x804A2A04 | size: 0xF
.obj kar_linkfile_grzeroyon1_dat_804a2a04, global
	.string "GrZeroyon1.dat"
.endobj kar_linkfile_grzeroyon1_dat_804a2a04

# .data:0x3CB | 0x804A2A13 | size: 0x1
.obj gap_07_804A2A13_data, global
.hidden gap_07_804A2A13_data
	.byte 0x00
.endobj gap_07_804A2A13_data

# .data:0x3CC | 0x804A2A14 | size: 0xF
.obj lbl_804A2A14, global
	.string "grDataZeroyon1"
.endobj lbl_804A2A14

# .data:0x3DB | 0x804A2A23 | size: 0x1
.obj gap_07_804A2A23_data, global
.hidden gap_07_804A2A23_data
	.byte 0x00
.endobj gap_07_804A2A23_data

# .data:0x3DC | 0x804A2A24 | size: 0x14
.obj kar_linkfile_grzeroyon1model_dat_804a2a24, global
	.string "GrZeroyon1Model.dat"
.endobj kar_linkfile_grzeroyon1model_dat_804a2a24

# .data:0x3F0 | 0x804A2A38 | size: 0x10
.obj lbl_804A2A38, global
	.string "grModelZeroyon1"
.endobj lbl_804A2A38

# .data:0x400 | 0x804A2A48 | size: 0x16
.obj lbl_804A2A48, global
	.string "grModelMotionZeroyon1"
.endobj lbl_804A2A48

# .data:0x416 | 0x804A2A5E | size: 0x2
.obj gap_07_804A2A5E_data, global
.hidden gap_07_804A2A5E_data
	.2byte 0x0000
.endobj gap_07_804A2A5E_data

# .data:0x418 | 0x804A2A60 | size: 0xF
.obj kar_linkfile_grzeroyon3_dat_804a2a60, global
	.string "GrZeroyon3.dat"
.endobj kar_linkfile_grzeroyon3_dat_804a2a60

# .data:0x427 | 0x804A2A6F | size: 0x1
.obj gap_07_804A2A6F_data, global
.hidden gap_07_804A2A6F_data
	.byte 0x00
.endobj gap_07_804A2A6F_data

# .data:0x428 | 0x804A2A70 | size: 0xF
.obj lbl_804A2A70, global
	.string "grDataZeroyon3"
.endobj lbl_804A2A70

# .data:0x437 | 0x804A2A7F | size: 0x1
.obj gap_07_804A2A7F_data, global
.hidden gap_07_804A2A7F_data
	.byte 0x00
.endobj gap_07_804A2A7F_data

# .data:0x438 | 0x804A2A80 | size: 0x14
.obj kar_linkfile_grzeroyon3model_dat_804a2a80, global
	.string "GrZeroyon3Model.dat"
.endobj kar_linkfile_grzeroyon3model_dat_804a2a80

# .data:0x44C | 0x804A2A94 | size: 0x10
.obj lbl_804A2A94, global
	.string "grModelZeroyon3"
.endobj lbl_804A2A94

# .data:0x45C | 0x804A2AA4 | size: 0x16
.obj lbl_804A2AA4, global
	.string "grModelMotionZeroyon3"
.endobj lbl_804A2AA4

# .data:0x472 | 0x804A2ABA | size: 0x2
.obj gap_07_804A2ABA_data, global
.hidden gap_07_804A2ABA_data
	.2byte 0x0000
.endobj gap_07_804A2ABA_data

# .data:0x474 | 0x804A2ABC | size: 0xF
.obj kar_linkfile_grzeroyon4_dat_804a2abc, global
	.string "GrZeroyon4.dat"
.endobj kar_linkfile_grzeroyon4_dat_804a2abc

# .data:0x483 | 0x804A2ACB | size: 0x1
.obj gap_07_804A2ACB_data, global
.hidden gap_07_804A2ACB_data
	.byte 0x00
.endobj gap_07_804A2ACB_data

# .data:0x484 | 0x804A2ACC | size: 0xF
.obj lbl_804A2ACC, global
	.string "grDataZeroyon4"
.endobj lbl_804A2ACC

# .data:0x493 | 0x804A2ADB | size: 0x1
.obj gap_07_804A2ADB_data, global
.hidden gap_07_804A2ADB_data
	.byte 0x00
.endobj gap_07_804A2ADB_data

# .data:0x494 | 0x804A2ADC | size: 0x14
.obj kar_linkfile_grzeroyon4model_dat_804a2adc, global
	.string "GrZeroyon4Model.dat"
.endobj kar_linkfile_grzeroyon4model_dat_804a2adc

# .data:0x4A8 | 0x804A2AF0 | size: 0x10
.obj lbl_804A2AF0, global
	.string "grModelZeroyon4"
.endobj lbl_804A2AF0

# .data:0x4B8 | 0x804A2B00 | size: 0x16
.obj lbl_804A2B00, global
	.string "grModelMotionZeroyon4"
.endobj lbl_804A2B00

# .data:0x4CE | 0x804A2B16 | size: 0x2
.obj gap_07_804A2B16_data, global
.hidden gap_07_804A2B16_data
	.2byte 0x0000
.endobj gap_07_804A2B16_data

# .data:0x4D0 | 0x804A2B18 | size: 0xF
.obj kar_linkfile_grzeroyon5_dat_804a2b18, global
	.string "GrZeroyon5.dat"
.endobj kar_linkfile_grzeroyon5_dat_804a2b18

# .data:0x4DF | 0x804A2B27 | size: 0x1
.obj gap_07_804A2B27_data, global
.hidden gap_07_804A2B27_data
	.byte 0x00
.endobj gap_07_804A2B27_data

# .data:0x4E0 | 0x804A2B28 | size: 0xF
.obj lbl_804A2B28, global
	.string "grDataZeroyon5"
.endobj lbl_804A2B28

# .data:0x4EF | 0x804A2B37 | size: 0x1
.obj gap_07_804A2B37_data, global
.hidden gap_07_804A2B37_data
	.byte 0x00
.endobj gap_07_804A2B37_data

# .data:0x4F0 | 0x804A2B38 | size: 0x14
.obj kar_linkfile_grzeroyon5model_dat_804a2b38, global
	.string "GrZeroyon5Model.dat"
.endobj kar_linkfile_grzeroyon5model_dat_804a2b38

# .data:0x504 | 0x804A2B4C | size: 0x10
.obj lbl_804A2B4C, global
	.string "grModelZeroyon5"
.endobj lbl_804A2B4C

# .data:0x514 | 0x804A2B5C | size: 0x16
.obj lbl_804A2B5C, global
	.string "grModelMotionZeroyon5"
.endobj lbl_804A2B5C

# .data:0x52A | 0x804A2B72 | size: 0x2
.obj gap_07_804A2B72_data, global
.hidden gap_07_804A2B72_data
	.2byte 0x0000
.endobj gap_07_804A2B72_data

# .data:0x52C | 0x804A2B74 | size: 0xF
.obj kar_linkfile_grpasture1_dat_804a2b74, global
	.string "GrPasture1.dat"
.endobj kar_linkfile_grpasture1_dat_804a2b74

# .data:0x53B | 0x804A2B83 | size: 0x1
.obj gap_07_804A2B83_data, global
.hidden gap_07_804A2B83_data
	.byte 0x00
.endobj gap_07_804A2B83_data

# .data:0x53C | 0x804A2B84 | size: 0xF
.obj lbl_804A2B84, global
	.string "grDataPasture1"
.endobj lbl_804A2B84

# .data:0x54B | 0x804A2B93 | size: 0x1
.obj gap_07_804A2B93_data, global
.hidden gap_07_804A2B93_data
	.byte 0x00
.endobj gap_07_804A2B93_data

# .data:0x54C | 0x804A2B94 | size: 0x14
.obj kar_linkfile_grpasture1model_dat_804a2b94, global
	.string "GrPasture1Model.dat"
.endobj kar_linkfile_grpasture1model_dat_804a2b94

# .data:0x560 | 0x804A2BA8 | size: 0x10
.obj lbl_804A2BA8, global
	.string "grModelPasture1"
.endobj lbl_804A2BA8

# .data:0x570 | 0x804A2BB8 | size: 0x16
.obj lbl_804A2BB8, global
	.string "grModelMotionPasture1"
.endobj lbl_804A2BB8

# .data:0x586 | 0x804A2BCE | size: 0x2
.obj gap_07_804A2BCE_data, global
.hidden gap_07_804A2BCE_data
	.2byte 0x0000
.endobj gap_07_804A2BCE_data

# .data:0x588 | 0x804A2BD0 | size: 0x11
.obj kar_linkfile_grcolosseum1_dat_804a2bd0, global
	.string "GrColosseum1.dat"
.endobj kar_linkfile_grcolosseum1_dat_804a2bd0

# .data:0x599 | 0x804A2BE1 | size: 0x3
.obj gap_07_804A2BE1_data, global
.hidden gap_07_804A2BE1_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2BE1_data

# .data:0x59C | 0x804A2BE4 | size: 0x11
.obj lbl_804A2BE4, global
	.string "grDataColosseum1"
.endobj lbl_804A2BE4

# .data:0x5AD | 0x804A2BF5 | size: 0x3
.obj gap_07_804A2BF5_data, global
.hidden gap_07_804A2BF5_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2BF5_data

# .data:0x5B0 | 0x804A2BF8 | size: 0x16
.obj kar_linkfile_grcolosseum1model_dat_804a2bf8, global
	.string "GrColosseum1Model.dat"
.endobj kar_linkfile_grcolosseum1model_dat_804a2bf8

# .data:0x5C6 | 0x804A2C0E | size: 0x2
.obj gap_07_804A2C0E_data, global
.hidden gap_07_804A2C0E_data
	.2byte 0x0000
.endobj gap_07_804A2C0E_data

# .data:0x5C8 | 0x804A2C10 | size: 0x12
.obj lbl_804A2C10, global
	.string "grModelColosseum1"
.endobj lbl_804A2C10

# .data:0x5DA | 0x804A2C22 | size: 0x2
.obj gap_07_804A2C22_data, global
.hidden gap_07_804A2C22_data
	.2byte 0x0000
.endobj gap_07_804A2C22_data

# .data:0x5DC | 0x804A2C24 | size: 0x18
.obj lbl_804A2C24, global
	.string "grModelMotionColosseum1"
.endobj lbl_804A2C24

# .data:0x5F4 | 0x804A2C3C | size: 0x11
.obj kar_linkfile_grcolosseum3_dat_804a2c3c, global
	.string "GrColosseum3.dat"
.endobj kar_linkfile_grcolosseum3_dat_804a2c3c

# .data:0x605 | 0x804A2C4D | size: 0x3
.obj gap_07_804A2C4D_data, global
.hidden gap_07_804A2C4D_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2C4D_data

# .data:0x608 | 0x804A2C50 | size: 0x11
.obj lbl_804A2C50, global
	.string "grDataColosseum3"
.endobj lbl_804A2C50

# .data:0x619 | 0x804A2C61 | size: 0x3
.obj gap_07_804A2C61_data, global
.hidden gap_07_804A2C61_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2C61_data

# .data:0x61C | 0x804A2C64 | size: 0x16
.obj kar_linkfile_grcolosseum3model_dat_804a2c64, global
	.string "GrColosseum3Model.dat"
.endobj kar_linkfile_grcolosseum3model_dat_804a2c64

# .data:0x632 | 0x804A2C7A | size: 0x2
.obj gap_07_804A2C7A_data, global
.hidden gap_07_804A2C7A_data
	.2byte 0x0000
.endobj gap_07_804A2C7A_data

# .data:0x634 | 0x804A2C7C | size: 0x12
.obj lbl_804A2C7C, global
	.string "grModelColosseum3"
.endobj lbl_804A2C7C

# .data:0x646 | 0x804A2C8E | size: 0x2
.obj gap_07_804A2C8E_data, global
.hidden gap_07_804A2C8E_data
	.2byte 0x0000
.endobj gap_07_804A2C8E_data

# .data:0x648 | 0x804A2C90 | size: 0x18
.obj lbl_804A2C90, global
	.string "grModelMotionColosseum3"
.endobj lbl_804A2C90

# .data:0x660 | 0x804A2CA8 | size: 0x11
.obj kar_linkfile_grcolosseum5_dat_804a2ca8, global
	.string "GrColosseum5.dat"
.endobj kar_linkfile_grcolosseum5_dat_804a2ca8

# .data:0x671 | 0x804A2CB9 | size: 0x3
.obj gap_07_804A2CB9_data, global
.hidden gap_07_804A2CB9_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2CB9_data

# .data:0x674 | 0x804A2CBC | size: 0x11
.obj lbl_804A2CBC, global
	.string "grDataColosseum5"
.endobj lbl_804A2CBC

# .data:0x685 | 0x804A2CCD | size: 0x3
.obj gap_07_804A2CCD_data, global
.hidden gap_07_804A2CCD_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2CCD_data

# .data:0x688 | 0x804A2CD0 | size: 0x16
.obj kar_linkfile_grcolosseum5model_dat_804a2cd0, global
	.string "GrColosseum5Model.dat"
.endobj kar_linkfile_grcolosseum5model_dat_804a2cd0

# .data:0x69E | 0x804A2CE6 | size: 0x2
.obj gap_07_804A2CE6_data, global
.hidden gap_07_804A2CE6_data
	.2byte 0x0000
.endobj gap_07_804A2CE6_data

# .data:0x6A0 | 0x804A2CE8 | size: 0x12
.obj lbl_804A2CE8, global
	.string "grModelColosseum5"
.endobj lbl_804A2CE8

# .data:0x6B2 | 0x804A2CFA | size: 0x2
.obj gap_07_804A2CFA_data, global
.hidden gap_07_804A2CFA_data
	.2byte 0x0000
.endobj gap_07_804A2CFA_data

# .data:0x6B4 | 0x804A2CFC | size: 0x18
.obj lbl_804A2CFC, global
	.string "grModelMotionColosseum5"
.endobj lbl_804A2CFC

# .data:0x6CC | 0x804A2D14 | size: 0xC
.obj kar_linkfile_grjump1_dat_804a2d14, global
	.string "GrJump1.dat"
.endobj kar_linkfile_grjump1_dat_804a2d14

# .data:0x6D8 | 0x804A2D20 | size: 0xC
.obj lbl_804A2D20, global
	.string "grDataJump1"
.endobj lbl_804A2D20

# .data:0x6E4 | 0x804A2D2C | size: 0x11
.obj kar_linkfile_grjump1model_dat_804a2d2c, global
	.string "GrJump1Model.dat"
.endobj kar_linkfile_grjump1model_dat_804a2d2c

# .data:0x6F5 | 0x804A2D3D | size: 0x3
.obj gap_07_804A2D3D_data, global
.hidden gap_07_804A2D3D_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2D3D_data

# .data:0x6F8 | 0x804A2D40 | size: 0xD
.obj lbl_804A2D40, global
	.string "grModelJump1"
.endobj lbl_804A2D40

# .data:0x705 | 0x804A2D4D | size: 0x3
.obj gap_07_804A2D4D_data, global
.hidden gap_07_804A2D4D_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2D4D_data

# .data:0x708 | 0x804A2D50 | size: 0x13
.obj lbl_804A2D50, global
	.string "grModelMotionJump1"
.endobj lbl_804A2D50

# .data:0x71B | 0x804A2D63 | size: 0x1
.obj gap_07_804A2D63_data, global
.hidden gap_07_804A2D63_data
	.byte 0x00
.endobj gap_07_804A2D63_data

# .data:0x71C | 0x804A2D64 | size: 0xC
.obj kar_linkfile_grjump2_dat_804a2d64, global
	.string "GrJump2.dat"
.endobj kar_linkfile_grjump2_dat_804a2d64

# .data:0x728 | 0x804A2D70 | size: 0xC
.obj lbl_804A2D70, global
	.string "grDataJump2"
.endobj lbl_804A2D70

# .data:0x734 | 0x804A2D7C | size: 0x11
.obj kar_linkfile_grjump2model_dat_804a2d7c, global
	.string "GrJump2Model.dat"
.endobj kar_linkfile_grjump2model_dat_804a2d7c

# .data:0x745 | 0x804A2D8D | size: 0x3
.obj gap_07_804A2D8D_data, global
.hidden gap_07_804A2D8D_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2D8D_data

# .data:0x748 | 0x804A2D90 | size: 0xD
.obj lbl_804A2D90, global
	.string "grModelJump2"
.endobj lbl_804A2D90

# .data:0x755 | 0x804A2D9D | size: 0x3
.obj gap_07_804A2D9D_data, global
.hidden gap_07_804A2D9D_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2D9D_data

# .data:0x758 | 0x804A2DA0 | size: 0x13
.obj lbl_804A2DA0, global
	.string "grModelMotionJump2"
.endobj lbl_804A2DA0

# .data:0x76B | 0x804A2DB3 | size: 0x1
.obj gap_07_804A2DB3_data, global
.hidden gap_07_804A2DB3_data
	.byte 0x00
.endobj gap_07_804A2DB3_data

# .data:0x76C | 0x804A2DB4 | size: 0xC
.obj kar_linkfile_grjump3_dat_804a2db4, global
	.string "GrJump3.dat"
.endobj kar_linkfile_grjump3_dat_804a2db4

# .data:0x778 | 0x804A2DC0 | size: 0xC
.obj lbl_804A2DC0, global
	.string "grDataJump3"
.endobj lbl_804A2DC0

# .data:0x784 | 0x804A2DCC | size: 0x11
.obj kar_linkfile_grjump3model_dat_804a2dcc, global
	.string "GrJump3Model.dat"
.endobj kar_linkfile_grjump3model_dat_804a2dcc

# .data:0x795 | 0x804A2DDD | size: 0x3
.obj gap_07_804A2DDD_data, global
.hidden gap_07_804A2DDD_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2DDD_data

# .data:0x798 | 0x804A2DE0 | size: 0xD
.obj lbl_804A2DE0, global
	.string "grModelJump3"
.endobj lbl_804A2DE0

# .data:0x7A5 | 0x804A2DED | size: 0x3
.obj gap_07_804A2DED_data, global
.hidden gap_07_804A2DED_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2DED_data

# .data:0x7A8 | 0x804A2DF0 | size: 0x13
.obj lbl_804A2DF0, global
	.string "grModelMotionJump3"
.endobj lbl_804A2DF0

# .data:0x7BB | 0x804A2E03 | size: 0x1
.obj gap_07_804A2E03_data, global
.hidden gap_07_804A2E03_data
	.byte 0x00
.endobj gap_07_804A2E03_data

# .data:0x7BC | 0x804A2E04 | size: 0xE
.obj kar_linkfile_grdedede1_dat_804a2e04, global
	.string "GrDedede1.dat"
.endobj kar_linkfile_grdedede1_dat_804a2e04

# .data:0x7CA | 0x804A2E12 | size: 0x2
.obj gap_07_804A2E12_data, global
.hidden gap_07_804A2E12_data
	.2byte 0x0000
.endobj gap_07_804A2E12_data

# .data:0x7CC | 0x804A2E14 | size: 0xE
.obj lbl_804A2E14, global
	.string "grDataDedede1"
.endobj lbl_804A2E14

# .data:0x7DA | 0x804A2E22 | size: 0x2
.obj gap_07_804A2E22_data, global
.hidden gap_07_804A2E22_data
	.2byte 0x0000
.endobj gap_07_804A2E22_data

# .data:0x7DC | 0x804A2E24 | size: 0x13
.obj kar_linkfile_grdedede1model_dat_804a2e24, global
	.string "GrDedede1Model.dat"
.endobj kar_linkfile_grdedede1model_dat_804a2e24

# .data:0x7EF | 0x804A2E37 | size: 0x1
.obj gap_07_804A2E37_data, global
.hidden gap_07_804A2E37_data
	.byte 0x00
.endobj gap_07_804A2E37_data

# .data:0x7F0 | 0x804A2E38 | size: 0xF
.obj lbl_804A2E38, global
	.string "grModelDedede1"
.endobj lbl_804A2E38

# .data:0x7FF | 0x804A2E47 | size: 0x1
.obj gap_07_804A2E47_data, global
.hidden gap_07_804A2E47_data
	.byte 0x00
.endobj gap_07_804A2E47_data

# .data:0x800 | 0x804A2E48 | size: 0x15
.obj lbl_804A2E48, global
	.string "grModelMotionDedede1"
.endobj lbl_804A2E48

# .data:0x815 | 0x804A2E5D | size: 0x3
.obj gap_07_804A2E5D_data, global
.hidden gap_07_804A2E5D_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2E5D_data

# .data:0x818 | 0x804A2E60 | size: 0xB
.obj kar_linkfile_grtest_dat_804a2e60, global
	.string "GrTest.dat"
.endobj kar_linkfile_grtest_dat_804a2e60

# .data:0x823 | 0x804A2E6B | size: 0x1
.obj gap_07_804A2E6B_data, global
.hidden gap_07_804A2E6B_data
	.byte 0x00
.endobj gap_07_804A2E6B_data

# .data:0x824 | 0x804A2E6C | size: 0xB
.obj lbl_804A2E6C, global
	.string "grDataTest"
.endobj lbl_804A2E6C

# .data:0x82F | 0x804A2E77 | size: 0x1
.obj gap_07_804A2E77_data, global
.hidden gap_07_804A2E77_data
	.byte 0x00
.endobj gap_07_804A2E77_data

# .data:0x830 | 0x804A2E78 | size: 0x10
.obj kar_linkfile_grtestmodel_dat_804a2e78, global
	.string "GrTestModel.dat"
.endobj kar_linkfile_grtestmodel_dat_804a2e78

# .data:0x840 | 0x804A2E88 | size: 0xC
.obj lbl_804A2E88, global
	.string "grModelTest"
.endobj lbl_804A2E88

# .data:0x84C | 0x804A2E94 | size: 0x12
.obj lbl_804A2E94, global
	.string "grModelMotionTest"
.endobj lbl_804A2E94

# .data:0x85E | 0x804A2EA6 | size: 0x2
.obj gap_07_804A2EA6_data, global
.hidden gap_07_804A2EA6_data
	.2byte 0x0000
.endobj gap_07_804A2EA6_data

# .data:0x860 | 0x804A2EA8 | size: 0xC
.obj kar_linkfile_grtest6_dat_804a2ea8, global
	.string "GrTest6.dat"
.endobj kar_linkfile_grtest6_dat_804a2ea8

# .data:0x86C | 0x804A2EB4 | size: 0xC
.obj lbl_804A2EB4, global
	.string "grDataTest6"
.endobj lbl_804A2EB4

# .data:0x878 | 0x804A2EC0 | size: 0x11
.obj kar_linkfile_grtest6model_dat_804a2ec0, global
	.string "GrTest6Model.dat"
.endobj kar_linkfile_grtest6model_dat_804a2ec0

# .data:0x889 | 0x804A2ED1 | size: 0x3
.obj gap_07_804A2ED1_data, global
.hidden gap_07_804A2ED1_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2ED1_data

# .data:0x88C | 0x804A2ED4 | size: 0xD
.obj lbl_804A2ED4, global
	.string "grModelTest6"
.endobj lbl_804A2ED4

# .data:0x899 | 0x804A2EE1 | size: 0x3
.obj gap_07_804A2EE1_data, global
.hidden gap_07_804A2EE1_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2EE1_data

# .data:0x89C | 0x804A2EE4 | size: 0x13
.obj lbl_804A2EE4, global
	.string "grModelMotionTest6"
.endobj lbl_804A2EE4

# .data:0x8AF | 0x804A2EF7 | size: 0x1
.obj gap_07_804A2EF7_data, global
.hidden gap_07_804A2EF7_data
	.byte 0x00
.endobj gap_07_804A2EF7_data

# .data:0x8B0 | 0x804A2EF8 | size: 0xC
.obj kar_linkfile_grtest7_dat_804a2ef8, global
	.string "GrTest7.dat"
.endobj kar_linkfile_grtest7_dat_804a2ef8

# .data:0x8BC | 0x804A2F04 | size: 0xC
.obj lbl_804A2F04, global
	.string "grDataTest7"
.endobj lbl_804A2F04

# .data:0x8C8 | 0x804A2F10 | size: 0x11
.obj kar_linkfile_grtest7model_dat_804a2f10, global
	.string "GrTest7Model.dat"
.endobj kar_linkfile_grtest7model_dat_804a2f10

# .data:0x8D9 | 0x804A2F21 | size: 0x3
.obj gap_07_804A2F21_data, global
.hidden gap_07_804A2F21_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2F21_data

# .data:0x8DC | 0x804A2F24 | size: 0xD
.obj lbl_804A2F24, global
	.string "grModelTest7"
.endobj lbl_804A2F24

# .data:0x8E9 | 0x804A2F31 | size: 0x3
.obj gap_07_804A2F31_data, global
.hidden gap_07_804A2F31_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2F31_data

# .data:0x8EC | 0x804A2F34 | size: 0x13
.obj lbl_804A2F34, global
	.string "grModelMotionTest7"
.endobj lbl_804A2F34

# .data:0x8FF | 0x804A2F47 | size: 0x1
.obj gap_07_804A2F47_data, global
.hidden gap_07_804A2F47_data
	.byte 0x00
.endobj gap_07_804A2F47_data

# .data:0x900 | 0x804A2F48 | size: 0xD
.obj kar_linkfile_grsimple_dat_804a2f48, global
	.string "GrSimple.dat"
.endobj kar_linkfile_grsimple_dat_804a2f48

# .data:0x90D | 0x804A2F55 | size: 0x3
.obj gap_07_804A2F55_data, global
.hidden gap_07_804A2F55_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2F55_data

# .data:0x910 | 0x804A2F58 | size: 0xD
.obj lbl_804A2F58, global
	.string "grDataSimple"
.endobj lbl_804A2F58

# .data:0x91D | 0x804A2F65 | size: 0x3
.obj gap_07_804A2F65_data, global
.hidden gap_07_804A2F65_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2F65_data

# .data:0x920 | 0x804A2F68 | size: 0x12
.obj kar_linkfile_grsimplemodel_dat_804a2f68, global
	.string "GrSimpleModel.dat"
.endobj kar_linkfile_grsimplemodel_dat_804a2f68

# .data:0x932 | 0x804A2F7A | size: 0x2
.obj gap_07_804A2F7A_data, global
.hidden gap_07_804A2F7A_data
	.2byte 0x0000
.endobj gap_07_804A2F7A_data

# .data:0x934 | 0x804A2F7C | size: 0xE
.obj lbl_804A2F7C, global
	.string "grModelSimple"
.endobj lbl_804A2F7C

# .data:0x942 | 0x804A2F8A | size: 0x2
.obj gap_07_804A2F8A_data, global
.hidden gap_07_804A2F8A_data
	.2byte 0x0000
.endobj gap_07_804A2F8A_data

# .data:0x944 | 0x804A2F8C | size: 0x14
.obj lbl_804A2F8C, global
	.string "grModelMotionSimple"
.endobj lbl_804A2F8C

# .data:0x958 | 0x804A2FA0 | size: 0xE
.obj kar_linkfile_grsimple2_dat_804a2fa0, global
	.string "GrSimple2.dat"
.endobj kar_linkfile_grsimple2_dat_804a2fa0

# .data:0x966 | 0x804A2FAE | size: 0x2
.obj gap_07_804A2FAE_data, global
.hidden gap_07_804A2FAE_data
	.2byte 0x0000
.endobj gap_07_804A2FAE_data

# .data:0x968 | 0x804A2FB0 | size: 0xE
.obj lbl_804A2FB0, global
	.string "grDataSimple2"
.endobj lbl_804A2FB0

# .data:0x976 | 0x804A2FBE | size: 0x2
.obj gap_07_804A2FBE_data, global
.hidden gap_07_804A2FBE_data
	.2byte 0x0000
.endobj gap_07_804A2FBE_data

# .data:0x978 | 0x804A2FC0 | size: 0x13
.obj kar_linkfile_grsimple2model_dat_804a2fc0, global
	.string "GrSimple2Model.dat"
.endobj kar_linkfile_grsimple2model_dat_804a2fc0

# .data:0x98B | 0x804A2FD3 | size: 0x1
.obj gap_07_804A2FD3_data, global
.hidden gap_07_804A2FD3_data
	.byte 0x00
.endobj gap_07_804A2FD3_data

# .data:0x98C | 0x804A2FD4 | size: 0xF
.obj lbl_804A2FD4, global
	.string "grModelSimple2"
.endobj lbl_804A2FD4

# .data:0x99B | 0x804A2FE3 | size: 0x1
.obj gap_07_804A2FE3_data, global
.hidden gap_07_804A2FE3_data
	.byte 0x00
.endobj gap_07_804A2FE3_data

# .data:0x99C | 0x804A2FE4 | size: 0x15
.obj lbl_804A2FE4, global
	.string "grModelMotionSimple2"
.endobj lbl_804A2FE4

# .data:0x9B1 | 0x804A2FF9 | size: 0x3
.obj gap_07_804A2FF9_data, global
.hidden gap_07_804A2FF9_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A2FF9_data

# .data:0x9B4 | 0x804A2FFC | size: 0x230
.obj kar_course_dat_model_resource_table, global
	.4byte kar_linkfile_grplants1_dat_804a26b4
	.4byte lbl_804A26C4
	.4byte kar_linkfile_grplants1model_dat_804a26d4
	.4byte lbl_804A26E8
	.4byte lbl_804A26F8
	.4byte kar_linkfile_grheat2_dat_804a2710
	.4byte lbl_804A271C
	.4byte kar_linkfile_grheat2model_dat_804a2728
	.4byte lbl_804A273C
	.4byte lbl_804A274C
	.4byte kar_linkfile_grdesert1_dat_804a2760
	.4byte lbl_804A2770
	.4byte kar_linkfile_grdesert1model_dat_804a2780
	.4byte lbl_804A2794
	.4byte lbl_804A27A4
	.4byte kar_linkfile_grcheck2_dat_804a27bc
	.4byte lbl_804A27CC
	.4byte kar_linkfile_grcheck2model_dat_804a27dc
	.4byte lbl_804A27F0
	.4byte lbl_804A2800
	.4byte kar_linkfile_grvalley2_dat_804a2814
	.4byte lbl_804A2824
	.4byte kar_linkfile_grvalley2model_dat_804a2834
	.4byte lbl_804A2848
	.4byte lbl_804A2858
	.4byte kar_linkfile_grmachine2_dat_804a2870
	.4byte lbl_804A2880
	.4byte kar_linkfile_grmachine2model_dat_804a2890
	.4byte lbl_804A28A4
	.4byte lbl_804A28B4
	.4byte kar_linkfile_grspace2_dat_804a28cc
	.4byte lbl_804A28DC
	.4byte kar_linkfile_grspace2model_dat_804a28ec
	.4byte lbl_804A2900
	.4byte lbl_804A2910
	.4byte kar_linkfile_grsky2_dat_804a2924
	.4byte lbl_804A2930
	.4byte kar_linkfile_grsky2model_dat_804a293c
	.4byte lbl_804A294C
	.4byte lbl_804A2958
	.4byte kar_linkfile_grice1_dat_804a296c
	.4byte lbl_804A2978
	.4byte kar_linkfile_grice1model_dat_804a2984
	.4byte lbl_804A2994
	.4byte lbl_804A29A0
	.4byte kar_linkfile_grcity1_dat_804a29b4
	.4byte lbl_804A29C0
	.4byte kar_linkfile_grcity1model_dat_804a29cc
	.4byte lbl_804A29E0
	.4byte lbl_804A29F0
	.4byte kar_linkfile_grzeroyon1_dat_804a2a04
	.4byte lbl_804A2A14
	.4byte kar_linkfile_grzeroyon1model_dat_804a2a24
	.4byte lbl_804A2A38
	.4byte lbl_804A2A48
	.4byte kar_linkfile_grzeroyon3_dat_804a2a60
	.4byte lbl_804A2A70
	.4byte kar_linkfile_grzeroyon3model_dat_804a2a80
	.4byte lbl_804A2A94
	.4byte lbl_804A2AA4
	.4byte kar_linkfile_grzeroyon4_dat_804a2abc
	.4byte lbl_804A2ACC
	.4byte kar_linkfile_grzeroyon4model_dat_804a2adc
	.4byte lbl_804A2AF0
	.4byte lbl_804A2B00
	.4byte kar_linkfile_grzeroyon5_dat_804a2b18
	.4byte lbl_804A2B28
	.4byte kar_linkfile_grzeroyon5model_dat_804a2b38
	.4byte lbl_804A2B4C
	.4byte lbl_804A2B5C
	.4byte kar_linkfile_grpasture1_dat_804a2b74
	.4byte lbl_804A2B84
	.4byte kar_linkfile_grpasture1model_dat_804a2b94
	.4byte lbl_804A2BA8
	.4byte lbl_804A2BB8
	.4byte kar_linkfile_grcolosseum1_dat_804a2bd0
	.4byte lbl_804A2BE4
	.4byte kar_linkfile_grcolosseum1model_dat_804a2bf8
	.4byte lbl_804A2C10
	.4byte lbl_804A2C24
	.4byte kar_linkfile_grcolosseum3_dat_804a2c3c
	.4byte lbl_804A2C50
	.4byte kar_linkfile_grcolosseum3model_dat_804a2c64
	.4byte lbl_804A2C7C
	.4byte lbl_804A2C90
	.4byte kar_linkfile_grcolosseum5_dat_804a2ca8
	.4byte lbl_804A2CBC
	.4byte kar_linkfile_grcolosseum5model_dat_804a2cd0
	.4byte lbl_804A2CE8
	.4byte lbl_804A2CFC
	.4byte kar_linkfile_grjump1_dat_804a2d14
	.4byte lbl_804A2D20
	.4byte kar_linkfile_grjump1model_dat_804a2d2c
	.4byte lbl_804A2D40
	.4byte lbl_804A2D50
	.4byte kar_linkfile_grjump2_dat_804a2d64
	.4byte lbl_804A2D70
	.4byte kar_linkfile_grjump2model_dat_804a2d7c
	.4byte lbl_804A2D90
	.4byte lbl_804A2DA0
	.4byte kar_linkfile_grjump3_dat_804a2db4
	.4byte lbl_804A2DC0
	.4byte kar_linkfile_grjump3model_dat_804a2dcc
	.4byte lbl_804A2DE0
	.4byte lbl_804A2DF0
	.4byte kar_linkfile_grdedede1_dat_804a2e04
	.4byte lbl_804A2E14
	.4byte kar_linkfile_grdedede1model_dat_804a2e24
	.4byte lbl_804A2E38
	.4byte lbl_804A2E48
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte kar_linkfile_grtest_dat_804a2e60
	.4byte lbl_804A2E6C
	.4byte kar_linkfile_grtestmodel_dat_804a2e78
	.4byte lbl_804A2E88
	.4byte lbl_804A2E94
	.4byte kar_linkfile_grtest6_dat_804a2ea8
	.4byte lbl_804A2EB4
	.4byte kar_linkfile_grtest6model_dat_804a2ec0
	.4byte lbl_804A2ED4
	.4byte lbl_804A2EE4
	.4byte kar_linkfile_grtest7_dat_804a2ef8
	.4byte lbl_804A2F04
	.4byte kar_linkfile_grtest7model_dat_804a2f10
	.4byte lbl_804A2F24
	.4byte lbl_804A2F34
	.4byte kar_linkfile_grsimple_dat_804a2f48
	.4byte lbl_804A2F58
	.4byte kar_linkfile_grsimplemodel_dat_804a2f68
	.4byte lbl_804A2F7C
	.4byte lbl_804A2F8C
	.4byte kar_linkfile_grsimple2_dat_804a2fa0
	.4byte lbl_804A2FB0
	.4byte kar_linkfile_grsimple2model_dat_804a2fc0
	.4byte lbl_804A2FD4
	.4byte lbl_804A2FE4
.endobj kar_course_dat_model_resource_table

# .data:0xBE4 | 0x804A322C | size: 0x70
.obj ground_stage_yaku_callback_table, global
	.4byte lbl_804A7528
	.4byte kar_grheat2_callback_table
	.4byte kar_grdesert1_main_callback_table
	.4byte kar_grdesert1_recovery_callback_table
	.4byte kar_grvalley2_callback_table
	.4byte kar_grmachine2_callback_table
	.4byte lbl_804A7720
	.4byte kar_grsky2_callback_table
	.4byte kar_grice1_callback_table
	.4byte kar_grcity1_main_callback_table
	.4byte kar_grcity1_risingcube_callback_table
	.4byte lbl_804A7868
	.4byte lbl_804A7878
	.4byte lbl_804A7888
	.4byte lbl_804A7898
	.4byte kar_grcolosseum1_main_callback_table
	.4byte kar_grcolosseum1_effect_9c47_callback_table
	.4byte lbl_804A78D8
	.4byte lbl_804A78E8
	.4byte kar_grcolosseum1_pointstrike_callback_table
	.4byte lbl_804A7908
	.4byte kar_grcolosseum1_risingcube_controller_callback_table
	.4byte lbl_804A7928
	.4byte lbl_804A7938
	.4byte lbl_804A7948
	.4byte lbl_804A7958
	.4byte kar_grcolosseum1_arealight_recovery_callback_table
	.4byte kar_grcolosseum1_airflow_and_yaku_callback_table
.endobj ground_stage_yaku_callback_table

# .data:0xC54 | 0x804A329C | size: 0x11
.obj kar_asset_grcity1event_804a329c, global
	.string "GrCity1Event.dat"
.endobj kar_asset_grcity1event_804a329c

# .data:0xC65 | 0x804A32AD | size: 0x3
.obj gap_07_804A32AD_data, global
.hidden gap_07_804A32AD_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A32AD_data

# .data:0xC68 | 0x804A32B0 | size: 0xD
.obj kar_linkfile_grcommon_dat_804a32b0, global
	.string "GrCommon.dat"
.endobj kar_linkfile_grcommon_dat_804a32b0

# .data:0xC75 | 0x804A32BD | size: 0x3
.obj gap_07_804A32BD_data, global
.hidden gap_07_804A32BD_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A32BD_data

# .data:0xC78 | 0x804A32C0 | size: 0x34
.obj lbl_804A32C0, global
	.4byte 0x67724461
	.4byte 0x7461436F
	.4byte 0x6D6D6F6E
	.4byte 0x00000000
	.4byte 0x67726461
	.4byte 0x74612E63
	.4byte 0x00000000
	.4byte 0x6B696E64
	.4byte 0x203D3D20
	.4byte 0x47725F4B
	.4byte 0x696E645F
	.4byte 0x43697479
	.4byte 0x31000000
.endobj lbl_804A32C0

# .data:0xCAC | 0x804A32F4 | size: 0x14
.obj lbl_804A32F4, global
	.string "grEventDataAllCity1"
.endobj lbl_804A32F4

# .data:0xCC0 | 0x804A3308 | size: 0x2A
.obj lbl_804A3308, global
	.string "0 <= index && index < GrCFF_ReflectNumMax"
.endobj lbl_804A3308

# .data:0xCEA | 0x804A3332 | size: 0x2
.obj gap_07_804A3332_data, global
.hidden gap_07_804A3332_data
	.2byte 0x0000
.endobj gap_07_804A3332_data

# .data:0xCEC | 0x804A3334 | size: 0x30
.obj lbl_804A3334, global
	.string "0 <= index && index < GrCFF_ForcedReflectNumMax"
.endobj lbl_804A3334

# .data:0xD1C | 0x804A3364 | size: 0x40
.obj lbl_804A3364, global
	.4byte 0x636F6E6E
	.4byte 0x6563745F
	.4byte 0x73706C00
	.4byte 0x6772636F
	.4byte 0x6D6D6F6E
	.4byte 0x2E680000
	.4byte 0x30203C3D
	.4byte 0x2073706C
	.4byte 0x5F696420
	.4byte 0x26262073
	.4byte 0x706C5F69
	.4byte 0x64203C20
	.4byte 0x73706C5F
	.4byte 0x64617461
	.4byte 0x2D3E6E75
	.4byte 0x6D000000
.endobj lbl_804A3364

# .data:0xD5C | 0x804A33A4 | size: 0x44
.obj lbl_804A33A4, global
	.4byte 0x72616E67
	.4byte 0x65446174
	.4byte 0x61000000
	.4byte 0x30203C3D
	.4byte 0x2072616E
	.4byte 0x67655F73
	.4byte 0x706C5F69
	.4byte 0x64202626
	.4byte 0x2072616E
	.4byte 0x67655F73
	.4byte 0x706C5F69
	.4byte 0x64203C20
	.4byte 0x72616E67
	.4byte 0x65446174
	.4byte 0x612D3E70
	.4byte 0x6169724E
	.4byte 0x756D0000
.endobj lbl_804A33A4

# .data:0xDA0 | 0x804A33E8 | size: 0x164
.obj lbl_804A33E8, global
	.4byte 0x72616E67
	.4byte 0x652D3E64
	.4byte 0x61746100
	.4byte 0x30203C3D
	.4byte 0x2063745F
	.4byte 0x706F696E
	.4byte 0x745F6964
	.4byte 0x20262620
	.4byte 0x63745F70
	.4byte 0x6F696E74
	.4byte 0x5F696420
	.4byte 0x3C207261
	.4byte 0x6E67652D
	.4byte 0x3E63744E
	.4byte 0x756D0000
	.4byte 0x67727370
	.4byte 0x6C696E65
	.4byte 0x2E680000
	.4byte 0x6C6F6361
	.4byte 0x6C5F7061
	.4byte 0x72616D20
	.4byte 0x3D3D2030
	.4byte 0x2E304620
	.4byte 0x7C7C206C
	.4byte 0x6F63616C
	.4byte 0x5F706172
	.4byte 0x616D203D
	.4byte 0x3D20312E
	.4byte 0x30460000
	.4byte 0x68656164
	.4byte 0x5F6E756D
	.4byte 0x203C2047
	.4byte 0x725F5261
	.4byte 0x6E676553
	.4byte 0x706C696E
	.4byte 0x655F4E75
	.4byte 0x6D4D6178
	.4byte 0x00000000
	.4byte 0x7461696C
	.4byte 0x5F6E756D
	.4byte 0x203C2047
	.4byte 0x725F5261
	.4byte 0x6E676553
	.4byte 0x706C696E
	.4byte 0x655F4E75
	.4byte 0x6D4D6178
	.4byte 0x00000000
	.4byte 0x6920213D
	.4byte 0x2070302D
	.4byte 0x3E636F6E
	.4byte 0x6E656374
	.4byte 0x5F6E756D
	.4byte 0x00000000
	.4byte 0x72616E67
	.4byte 0x652D3E63
	.4byte 0x744E756D
	.4byte 0x41646420
	.4byte 0x3C204772
	.4byte 0x5F52616E
	.4byte 0x67654164
	.4byte 0x64437450
	.4byte 0x6F696E74
	.4byte 0x5F4D6178
	.4byte 0x00000000
	.4byte 0x72616E67
	.4byte 0x652D3E63
	.4byte 0x744E756D
	.4byte 0x203E2030
	.4byte 0x00000000
	.4byte 0x72616E67
	.4byte 0x652D3E63
	.4byte 0x744E756D
	.4byte 0x41646420
	.4byte 0x3E203000
	.4byte 0x6374506F
	.4byte 0x696E742D
	.4byte 0x3E636F6E
	.4byte 0x6E656374
	.4byte 0x5F6E756D
	.4byte 0x203D3D20
	.4byte 0x32000000
	.4byte 0x635B305D
	.4byte 0x2D3E7370
	.4byte 0x6C5F6964
	.4byte 0x203D3D20
	.4byte 0x635B315D
	.4byte 0x2D3E7370
	.4byte 0x6C5F6964
	.4byte 0x00000000
.endobj lbl_804A33E8

# .data:0xF04 | 0x804A354C | size: 0x16
.obj lbl_804A354C, global
	.string "spl_id0_ix != ct->num"
.endobj lbl_804A354C

# .data:0xF1A | 0x804A3562 | size: 0x2
.obj gap_07_804A3562_data, global
.hidden gap_07_804A3562_data
	.2byte 0x0000
.endobj gap_07_804A3562_data

# .data:0xF1C | 0x804A3564 | size: 0xA
.obj lbl_804A3564, global
	.string "num = %d\n"
.endobj lbl_804A3564

# .data:0xF26 | 0x804A356E | size: 0x2
.obj gap_07_804A356E_data, global
.hidden gap_07_804A356E_data
	.2byte 0x0000
.endobj gap_07_804A356E_data

# .data:0xF28 | 0x804A3570 | size: 0x25
.obj lbl_804A3570, global
	.string "0 <= num && num < grGetStartposNum()"
.endobj lbl_804A3570

# .data:0xF4D | 0x804A3595 | size: 0x3
.obj gap_07_804A3595_data, global
.hidden gap_07_804A3595_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A3595_data

# .data:0xF50 | 0x804A3598 | size: 0x29
.obj lbl_804A3598, global
	.string "(0 <= num) && (num < grGetEnemyposNum())"
.endobj lbl_804A3598

# .data:0xF79 | 0x804A35C1 | size: 0x3
.obj gap_07_804A35C1_data, global
.hidden gap_07_804A35C1_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A35C1_data

# .data:0xF7C | 0x804A35C4 | size: 0x27
.obj lbl_804A35C4, global
	.string "0 <= num && num < grGetGravityposNum()"
.endobj lbl_804A35C4

# .data:0xFA3 | 0x804A35EB | size: 0x1
.obj gap_07_804A35EB_data, global
.hidden gap_07_804A35EB_data
	.byte 0x00
.endobj gap_07_804A35EB_data

# .data:0xFA4 | 0x804A35EC | size: 0x27
.obj lbl_804A35EC, global
	.string "0 <= num && num < grGetAirflowposNum()"
.endobj lbl_804A35EC

# .data:0xFCB | 0x804A3613 | size: 0x1
.obj gap_07_804A3613_data, global
.hidden gap_07_804A3613_data
	.byte 0x00
.endobj gap_07_804A3613_data

# .data:0xFCC | 0x804A3614 | size: 0x28
.obj lbl_804A3614, global
	.string "0 <= num && num < grGetConveyerposNum()"
.endobj lbl_804A3614

# .data:0xFF4 | 0x804A363C | size: 0x24
.obj lbl_804A363C, global
	.string "0 <= num && num < grGetItemposNum()"
.endobj lbl_804A363C

# .data:0x1018 | 0x804A3660 | size: 0x25
.obj lbl_804A3660, global
	.string "0 <= num && num < grGetEventposNum()"
.endobj lbl_804A3660

# .data:0x103D | 0x804A3685 | size: 0x3
.obj gap_07_804A3685_data, global
.hidden gap_07_804A3685_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A3685_data

# .data:0x1040 | 0x804A3688 | size: 0x27
.obj lbl_804A3688, global
	.string "0 <= num && num < grGetVehicleposNum()"
.endobj lbl_804A3688

# .data:0x1067 | 0x804A36AF | size: 0x1
.obj gap_07_804A36AF_data, global
.hidden gap_07_804A36AF_data
	.byte 0x00
.endobj gap_07_804A36AF_data

# .data:0x1068 | 0x804A36B0 | size: 0x28
.obj lbl_804A36B0, global
	.string "0 <= num && num < grGetYakumonoposNum()"
.endobj lbl_804A36B0

# .data:0x1090 | 0x804A36D8 | size: 0x28
.obj lbl_804A36D8, global
	.string "0 <= num && num < grGetItemAreaposNum()"
.endobj lbl_804A36D8

# .data:0x10B8 | 0x804A3700 | size: 0x2B
.obj lbl_804A3700, global
	.string "0 <= num && num < grGetVehicleAreaposNum()"
.endobj lbl_804A3700

# .data:0x10E3 | 0x804A372B | size: 0x1
.obj gap_07_804A372B_data, global
.hidden gap_07_804A372B_data
	.byte 0x00
.endobj gap_07_804A372B_data

# .data:0x10E4 | 0x804A372C | size: 0x9
.obj kar_src_grcoll_804a372c, global
	.string "grcoll.h"
.endobj kar_src_grcoll_804a372c

# .data:0x10ED | 0x804A3735 | size: 0x3
.obj gap_07_804A3735_data, global
.hidden gap_07_804A3735_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A3735_data

# .data:0x10F0 | 0x804A3738 | size: 0x110
.obj lbl_804A3738, global
	.4byte 0x21677243
	.4byte 0x6F6C6C43
	.4byte 0x686B4661
	.4byte 0x6365496C
	.4byte 0x6C656761
	.4byte 0x6C286763
	.4byte 0x702C2069
	.4byte 0x64290000
	.4byte 0x696E6465
	.4byte 0x78203E3D
	.4byte 0x20302026
	.4byte 0x2620696E
	.4byte 0x64657820
	.4byte 0x3C204772
	.4byte 0x44617368
	.4byte 0x5A6F6E65
	.4byte 0x5F4E756D
	.4byte 0x00000000
	.4byte 0x7A6F6E65
	.4byte 0x4964203D
	.4byte 0x2025642C
	.4byte 0x206B696E
	.4byte 0x64203D20
	.4byte 0x25640000
	.4byte 0x2A667261
	.4byte 0x6D65203E
	.4byte 0x20300000
	.4byte 0x696E6465
	.4byte 0x78203E3D
	.4byte 0x20302026
	.4byte 0x2620696E
	.4byte 0x64657820
	.4byte 0x3C204772
	.4byte 0x44617368
	.4byte 0x47617465
	.4byte 0x5F4E756D
	.4byte 0x00000000
	.4byte 0x67724765
	.4byte 0x74446173
	.4byte 0x68476174
	.4byte 0x655A6F6E
	.4byte 0x65506172
	.4byte 0x616D203A
	.4byte 0x20696C6C
	.4byte 0x6567616C
	.4byte 0x206B696E
	.4byte 0x64203D20
	.4byte 0x25640000
	.4byte 0x696E6465
	.4byte 0x78203E3D
	.4byte 0x20302026
	.4byte 0x2620696E
	.4byte 0x64657820
	.4byte 0x3C204772
	.4byte 0x44617368
	.4byte 0x52696E67
	.4byte 0x5F4E756D
	.4byte 0x00000000
	.4byte 0x67724765
	.4byte 0x744B696E
	.4byte 0x64435A4B
	.4byte 0x287A6F6E
	.4byte 0x654B696E
	.4byte 0x6429203D
	.4byte 0x3D204772
	.4byte 0x435A4B5F
	.4byte 0x57617270
	.4byte 0x496E0000
.endobj lbl_804A3738

# .data:0x1200 | 0x804A3848 | size: 0x2A
.obj lbl_804A3848, global
	.string "grGetKindCZK(zoneKind) == GrCZK_SuperJump"
.endobj lbl_804A3848

# .data:0x122A | 0x804A3872 | size: 0x2
.obj gap_07_804A3872_data, global
.hidden gap_07_804A3872_data
	.2byte 0x0000
.endobj gap_07_804A3872_data

# .data:0x122C | 0x804A3874 | size: 0x25
.obj lbl_804A3874, global
	.string "grGetKindCZK(zoneKind) == GrCZK_Jump"
.endobj lbl_804A3874

# .data:0x1251 | 0x804A3899 | size: 0x3
.obj gap_07_804A3899_data, global
.hidden gap_07_804A3899_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A3899_data

# .data:0x1254 | 0x804A389C | size: 0x25
.obj lbl_804A389C, global
	.string "grGetKindCZK(zoneKind) == GrCZK_Spin"
.endobj lbl_804A389C

# .data:0x1279 | 0x804A38C1 | size: 0x3
.obj gap_07_804A38C1_data, global
.hidden gap_07_804A38C1_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A38C1_data

# .data:0x127C | 0x804A38C4 | size: 0x17
.obj lbl_804A38C4, global
	.string "index < GrSpinZone_Num"
.endobj lbl_804A38C4

# .data:0x1293 | 0x804A38DB | size: 0x1
.obj gap_07_804A38DB_data, global
.hidden gap_07_804A38DB_data
	.byte 0x00
.endobj gap_07_804A38DB_data

# .data:0x1294 | 0x804A38DC | size: 0x2E
.obj lbl_804A38DC, global
	.string "grYakuGetKind(yakuGObj) == Gr_YakuKind_Cannon"
.endobj lbl_804A38DC

# .data:0x12C2 | 0x804A390A | size: 0x2
.obj gap_07_804A390A_data, global
.hidden gap_07_804A390A_data
	.2byte 0x0000
.endobj gap_07_804A390A_data

# .data:0x12C4 | 0x804A390C | size: 0x1C
.obj lbl_804A390C, global
	.string "!grChkIllegalZoneId(zoneId)"
.endobj lbl_804A390C

# .data:0x12E0 | 0x804A3928 | size: 0x40
.obj jumptable_804A3928, global
	.4byte kar_grcommon__near_800d2afc+0xF4
	.4byte kar_grcommon__near_800d2afc+0xD4
	.4byte kar_grcommon__near_800d2afc+0xE4
	.4byte kar_grcommon__near_800d2afc+0x124
	.4byte kar_grcommon__near_800d2afc+0x124
	.4byte kar_grcommon__near_800d2afc+0x124
	.4byte kar_grcommon__near_800d2afc+0x124
	.4byte kar_grcommon__near_800d2afc+0x104
	.4byte kar_grcommon__near_800d2afc+0x124
	.4byte kar_grcommon__near_800d2afc+0x124
	.4byte kar_grcommon__near_800d2afc+0x124
	.4byte kar_grcommon__near_800d2afc+0x124
	.4byte kar_grcommon__near_800d2afc+0x124
	.4byte kar_grcommon__near_800d2afc+0x124
	.4byte kar_grcommon__near_800d2afc+0x124
	.4byte kar_grcommon__near_800d2afc+0x114
.endobj jumptable_804A3928

# .data:0x1320 | 0x804A3968 | size: 0x15C
.obj lbl_804A3968, global
	.4byte 0x7472616E
	.4byte 0x736C6174
	.4byte 0x65000000
	.4byte 0x7261696C
	.4byte 0x5F616C6C
	.4byte 0x2D3E6461
	.4byte 0x74610000
	.4byte 0x7261696C
	.4byte 0x5F696420
	.4byte 0x3D202564
	.4byte 0x0A000000
	.4byte 0x47725F52
	.4byte 0x61696C49
	.4byte 0x645F4E6F
	.4byte 0x6E65203C
	.4byte 0x20726169
	.4byte 0x6C5F6964
	.4byte 0x20262620
	.4byte 0x7261696C
	.4byte 0x5F696420
	.4byte 0x3C206772
	.4byte 0x47657452
	.4byte 0x61696C44
	.4byte 0x6174614E
	.4byte 0x756D2872
	.4byte 0x61696C5F
	.4byte 0x616C6C29
	.4byte 0x00000000
	.4byte 0x70617261
	.4byte 0x6D203D20
	.4byte 0x25660A00
	.4byte 0x302E3046
	.4byte 0x203C3D20
	.4byte 0x70617261
	.4byte 0x6D202626
	.4byte 0x20706172
	.4byte 0x616D203C
	.4byte 0x3D20312E
	.4byte 0x30460000
	.4byte 0x7261696C
	.4byte 0x5F706172
	.4byte 0x616D2D3E
	.4byte 0x64617461
	.4byte 0x5B305D2E
	.4byte 0x70617261
	.4byte 0x6D203D20
	.4byte 0x25660A00
	.4byte 0x7261696C
	.4byte 0x5F706172
	.4byte 0x616D2D3E
	.4byte 0x64617461
	.4byte 0x5B305D2E
	.4byte 0x70617261
	.4byte 0x6D203D3D
	.4byte 0x20302E30
	.4byte 0x00000000
	.4byte 0x67724765
	.4byte 0x7453706C
	.4byte 0x696E6544
	.4byte 0x61746141
	.4byte 0x6C6C2867
	.4byte 0x72476574
	.4byte 0x476C6F62
	.4byte 0x616C5028
	.4byte 0x29292D3E
	.4byte 0x7261696C
	.4byte 0x00000000
	.4byte 0x7261696C
	.4byte 0x5F706172
	.4byte 0x616D2D3E
	.4byte 0x64617368
	.4byte 0x5F646174
	.4byte 0x615B305D
	.4byte 0x2E706172
	.4byte 0x616D203D
	.4byte 0x3D20302E
	.4byte 0x30460000
	.4byte 0x7261696C
	.4byte 0x5F706172
	.4byte 0x616D2D3E
	.4byte 0x6C656170
	.4byte 0x5F646174
	.4byte 0x615B305D
	.4byte 0x2E706172
	.4byte 0x616D203D
	.4byte 0x3D20302E
	.4byte 0x30460000
.endobj lbl_804A3968

# .data:0x147C | 0x804A3AC4 | size: 0x2A
.obj lbl_804A3AC4, global
	.string "grGetKindCZK(zoneKind) == GrCZK_LocalDead"
.endobj lbl_804A3AC4

# .data:0x14A6 | 0x804A3AEE | size: 0x2
.obj gap_07_804A3AEE_data, global
.hidden gap_07_804A3AEE_data
	.2byte 0x0000
.endobj gap_07_804A3AEE_data

# 0x805DF5C8..0x805DF608 | size: 0x40
.section .sdata2, "a"
.balign 8

# .sdata2:0x0 | 0x805DF5C8 | size: 0x8
.obj lbl_805DF5C8, global
	.float 1
	.float 0
.endobj lbl_805DF5C8

# .sdata2:0x8 | 0x805DF5D0 | size: 0x4
.obj lbl_805DF5D0, global
	.float 1.21
.endobj lbl_805DF5D0

# .sdata2:0xC | 0x805DF5D4 | size: 0x4
.obj lbl_805DF5D4, global
	.float 0.00001
.endobj lbl_805DF5D4

# .sdata2:0x10 | 0x805DF5D8 | size: 0x4
.obj lbl_805DF5D8, global
	.float -0.00001
.endobj lbl_805DF5D8

# .sdata2:0x14 | 0x805DF5DC | size: 0x4
.obj lbl_805DF5DC, global
	.float 0
.endobj lbl_805DF5DC

# .sdata2:0x18 | 0x805DF5E0 | size: 0x4
.obj lbl_805DF5E0, global
	.float 1
.endobj lbl_805DF5E0

# .sdata2:0x1C | 0x805DF5E4 | size: 0x4
.obj lbl_805DF5E4, global
	.float 0.025
.endobj lbl_805DF5E4

# .sdata2:0x20 | 0x805DF5E8 | size: 0x4
.obj lbl_805DF5E8, global
	.float -1
.endobj lbl_805DF5E8

# .sdata2:0x24 | 0x805DF5EC | size: 0x4
.obj lbl_805DF5EC, global
	.float 340282350000000000000000000000000000000
.endobj lbl_805DF5EC

# .sdata2:0x28 | 0x805DF5F0 | size: 0x8
.obj lbl_805DF5F0, global
	.double 4503601774854144
.endobj lbl_805DF5F0

# .sdata2:0x30 | 0x805DF5F8 | size: 0x8
.obj lbl_805DF5F8, global
	.double 0
.endobj lbl_805DF5F8

# .sdata2:0x38 | 0x805DF600 | size: 0x8
.obj lbl_805DF600, global
	.float 10000
	.float 0
.endobj lbl_805DF600
