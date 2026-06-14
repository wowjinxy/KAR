.include "macros.inc"
.file "gryakucommon.c"

# 0x800F87E4..0x800F9F78 | size: 0x1794
.text
.balign 4

# .text:0x0 | 0x800F87E4 | size: 0x70
.fn kar_gryakucommon_get_jobj_by_anchor_scope, global
/* 800F87E4 000F55E4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F87E8 000F55E8  7C 08 02 A6 */	mflr r0
/* 800F87EC 000F55EC  2C 05 00 01 */	cmpwi r5, 0x1
/* 800F87F0 000F55F0  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F87F4 000F55F4  41 82 00 28 */	beq .L_800F881C
/* 800F87F8 000F55F8  40 80 00 34 */	bge .L_800F882C
/* 800F87FC 000F55FC  2C 05 00 00 */	cmpwi r5, 0x0
/* 800F8800 000F5600  40 80 00 08 */	bge .L_800F8808
/* 800F8804 000F5604  48 00 00 28 */	b .L_800F882C
.L_800F8808:
/* 800F8808 000F5608  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 800F880C 000F560C  54 80 18 38 */	slwi r0, r4, 3
/* 800F8810 000F5610  80 63 01 04 */	lwz r3, 0x104(r3)
/* 800F8814 000F5614  7C 63 00 2E */	lwzx r3, r3, r0
/* 800F8818 000F5618  48 00 00 2C */	b .L_800F8844
.L_800F881C:
/* 800F881C 000F561C  80 63 00 64 */	lwz r3, 0x64(r3)
/* 800F8820 000F5620  54 80 18 38 */	slwi r0, r4, 3
/* 800F8824 000F5624  7C 63 00 2E */	lwzx r3, r3, r0
/* 800F8828 000F5628  48 00 00 1C */	b .L_800F8844
.L_800F882C:
/* 800F882C 000F562C  3C 60 80 4A */	lis r3, kar_src_gryakucommon_c@ha
/* 800F8830 000F5630  38 80 00 3A */	li r4, 0x3a
/* 800F8834 000F5634  38 63 5D 40 */	addi r3, r3, kar_src_gryakucommon_c@l
/* 800F8838 000F5638  38 AD 91 28 */	li r5, lbl_805D6208@sda21
/* 800F883C 000F563C  48 32 FC 7D */	bl __assert
/* 800F8840 000F5640  38 60 00 00 */	li r3, 0x0
.L_800F8844:
/* 800F8844 000F5644  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F8848 000F5648  7C 08 03 A6 */	mtlr r0
/* 800F884C 000F564C  38 21 00 10 */	addi r1, r1, 0x10
/* 800F8850 000F5650  4E 80 00 20 */	blr
.endfn kar_gryakucommon_get_jobj_by_anchor_scope

# .text:0x70 | 0x800F8854 | size: 0x320
.fn kar_gryakucommon_sync_jobj_to_eventpos_matrix, global
/* 800F8854 000F5654  94 21 FF 20 */	stwu r1, -0xe0(r1)
/* 800F8858 000F5658  7C 08 02 A6 */	mflr r0
/* 800F885C 000F565C  90 01 00 E4 */	stw r0, 0xe4(r1)
/* 800F8860 000F5660  DB E1 00 D0 */	stfd f31, 0xd0(r1)
/* 800F8864 000F5664  F3 E1 00 D8 */	psq_st f31, 0xd8(r1), 0, qr0
/* 800F8868 000F5668  DB C1 00 C0 */	stfd f30, 0xc0(r1)
/* 800F886C 000F566C  F3 C1 00 C8 */	psq_st f30, 0xc8(r1), 0, qr0
/* 800F8870 000F5670  93 E1 00 BC */	stw r31, 0xbc(r1)
/* 800F8874 000F5674  93 C1 00 B8 */	stw r30, 0xb8(r1)
/* 800F8878 000F5678  93 A1 00 B4 */	stw r29, 0xb4(r1)
/* 800F887C 000F567C  93 81 00 B0 */	stw r28, 0xb0(r1)
/* 800F8880 000F5680  FF C0 08 90 */	fmr f30, f1
/* 800F8884 000F5684  7C BC 2B 78 */	mr r28, r5
/* 800F8888 000F5688  FF E0 10 90 */	fmr f31, f2
/* 800F888C 000F568C  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 800F8890 000F5690  7C 7F 1B 78 */	mr r31, r3
/* 800F8894 000F5694  7C 83 23 78 */	mr r3, r4
/* 800F8898 000F5698  38 81 00 68 */	addi r4, r1, 0x68
/* 800F889C 000F569C  38 A1 00 5C */	addi r5, r1, 0x5c
/* 800F88A0 000F56A0  38 C1 00 50 */	addi r6, r1, 0x50
/* 800F88A4 000F56A4  3B A0 FF FF */	li r29, -0x1
/* 800F88A8 000F56A8  4B FD 89 55 */	bl kar_grcommon_get_eventpos_vectors_by_index
/* 800F88AC 000F56AC  2C 1C 00 00 */	cmpwi r28, 0x0
/* 800F88B0 000F56B0  41 82 00 64 */	beq .L_800F8914
/* 800F88B4 000F56B4  FC 80 F0 50 */	fneg f4, f30
/* 800F88B8 000F56B8  C0 A2 91 38 */	lfs f5, lbl_805DF838@sda21(r0)
/* 800F88BC 000F56BC  C0 61 00 68 */	lfs f3, 0x68(r1)
/* 800F88C0 000F56C0  38 61 00 68 */	addi r3, r1, 0x68
/* 800F88C4 000F56C4  C0 01 00 70 */	lfs f0, 0x70(r1)
/* 800F88C8 000F56C8  38 81 00 2C */	addi r4, r1, 0x2c
/* 800F88CC 000F56CC  FC 40 20 18 */	frsp f2, f4
/* 800F88D0 000F56D0  C0 21 00 6C */	lfs f1, 0x6c(r1)
/* 800F88D4 000F56D4  EC 65 18 2A */	fadds f3, f5, f3
/* 800F88D8 000F56D8  D0 A1 00 2C */	stfs f5, 0x2c(r1)
/* 800F88DC 000F56DC  EC 05 00 2A */	fadds f0, f5, f0
/* 800F88E0 000F56E0  38 A1 00 38 */	addi r5, r1, 0x38
/* 800F88E4 000F56E4  D0 A1 00 34 */	stfs f5, 0x34(r1)
/* 800F88E8 000F56E8  EC 22 08 2A */	fadds f1, f2, f1
/* 800F88EC 000F56EC  D0 81 00 30 */	stfs f4, 0x30(r1)
/* 800F88F0 000F56F0  D0 61 00 2C */	stfs f3, 0x2c(r1)
/* 800F88F4 000F56F4  D0 21 00 30 */	stfs f1, 0x30(r1)
/* 800F88F8 000F56F8  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 800F88FC 000F56FC  4B FD 91 59 */	bl kar_grcoll__near_800d1a54
/* 800F8900 000F5700  7C 7D 1B 78 */	mr r29, r3
/* 800F8904 000F5704  4B FD 63 25 */	bl kar_grcommon_get_collision_face_material_id
/* 800F8908 000F5708  2C 03 00 1D */	cmpwi r3, 0x1d
/* 800F890C 000F570C  40 82 00 08 */	bne .L_800F8914
/* 800F8910 000F5710  3B A0 FF FF */	li r29, -0x1
.L_800F8914:
/* 800F8914 000F5714  7F A3 EB 78 */	mr r3, r29
/* 800F8918 000F5718  4B FD 8F 21 */	bl kar_grcoll_is_face_id_invalid
/* 800F891C 000F571C  2C 03 00 00 */	cmpwi r3, 0x0
/* 800F8920 000F5720  40 82 00 C8 */	bne .L_800F89E8
/* 800F8924 000F5724  80 C1 00 38 */	lwz r6, 0x38(r1)
/* 800F8928 000F5728  7F A3 EB 78 */	mr r3, r29
/* 800F892C 000F572C  80 A1 00 3C */	lwz r5, 0x3c(r1)
/* 800F8930 000F5730  38 81 00 50 */	addi r4, r1, 0x50
/* 800F8934 000F5734  80 01 00 40 */	lwz r0, 0x40(r1)
/* 800F8938 000F5738  90 C1 00 68 */	stw r6, 0x68(r1)
/* 800F893C 000F573C  90 A1 00 6C */	stw r5, 0x6c(r1)
/* 800F8940 000F5740  90 01 00 70 */	stw r0, 0x70(r1)
/* 800F8944 000F5744  4B FD 8F 1D */	bl kar_grcoll_get_face_normal
/* 800F8948 000F5748  C0 C1 00 54 */	lfs f6, 0x54(r1)
/* 800F894C 000F574C  C0 A1 00 5C */	lfs f5, 0x5c(r1)
/* 800F8950 000F5750  C0 61 00 64 */	lfs f3, 0x64(r1)
/* 800F8954 000F5754  C0 E1 00 50 */	lfs f7, 0x50(r1)
/* 800F8958 000F5758  EC 06 01 72 */	fmuls f0, f6, f5
/* 800F895C 000F575C  C0 41 00 60 */	lfs f2, 0x60(r1)
/* 800F8960 000F5760  C0 81 00 58 */	lfs f4, 0x58(r1)
/* 800F8964 000F5764  EC 27 00 F2 */	fmuls f1, f7, f3
/* 800F8968 000F5768  EC 07 00 B8 */	fmsubs f0, f7, f2, f0
/* 800F896C 000F576C  EC 44 00 B2 */	fmuls f2, f4, f2
/* 800F8970 000F5770  EC 24 09 78 */	fmsubs f1, f4, f5, f1
/* 800F8974 000F5774  D0 01 00 28 */	stfs f0, 0x28(r1)
/* 800F8978 000F5778  EC 06 10 F8 */	fmsubs f0, f6, f3, f2
/* 800F897C 000F577C  D0 21 00 24 */	stfs f1, 0x24(r1)
/* 800F8980 000F5780  80 01 00 28 */	lwz r0, 0x28(r1)
/* 800F8984 000F5784  D0 01 00 20 */	stfs f0, 0x20(r1)
/* 800F8988 000F5788  80 61 00 24 */	lwz r3, 0x24(r1)
/* 800F898C 000F578C  80 81 00 20 */	lwz r4, 0x20(r1)
/* 800F8990 000F5790  90 61 00 48 */	stw r3, 0x48(r1)
/* 800F8994 000F5794  90 81 00 44 */	stw r4, 0x44(r1)
/* 800F8998 000F5798  C1 01 00 48 */	lfs f8, 0x48(r1)
/* 800F899C 000F579C  90 01 00 4C */	stw r0, 0x4c(r1)
/* 800F89A0 000F57A0  C0 41 00 44 */	lfs f2, 0x44(r1)
/* 800F89A4 000F57A4  EC 08 01 F2 */	fmuls f0, f8, f7
/* 800F89A8 000F57A8  C0 A1 00 4C */	lfs f5, 0x4c(r1)
/* 800F89AC 000F57AC  EC 22 01 32 */	fmuls f1, f2, f4
/* 800F89B0 000F57B0  EC 65 01 B2 */	fmuls f3, f5, f6
/* 800F89B4 000F57B4  EC 02 01 B8 */	fmsubs f0, f2, f6, f0
/* 800F89B8 000F57B8  EC 25 09 F8 */	fmsubs f1, f5, f7, f1
/* 800F89BC 000F57BC  EC 48 19 38 */	fmsubs f2, f8, f4, f3
/* 800F89C0 000F57C0  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 800F89C4 000F57C4  D0 41 00 14 */	stfs f2, 0x14(r1)
/* 800F89C8 000F57C8  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F89CC 000F57CC  D0 21 00 18 */	stfs f1, 0x18(r1)
/* 800F89D0 000F57D0  80 81 00 14 */	lwz r4, 0x14(r1)
/* 800F89D4 000F57D4  80 61 00 18 */	lwz r3, 0x18(r1)
/* 800F89D8 000F57D8  90 81 00 5C */	stw r4, 0x5c(r1)
/* 800F89DC 000F57DC  90 61 00 60 */	stw r3, 0x60(r1)
/* 800F89E0 000F57E0  90 01 00 64 */	stw r0, 0x64(r1)
/* 800F89E4 000F57E4  48 00 00 58 */	b .L_800F8A3C
.L_800F89E8:
/* 800F89E8 000F57E8  C0 C1 00 54 */	lfs f6, 0x54(r1)
/* 800F89EC 000F57EC  C0 A1 00 5C */	lfs f5, 0x5c(r1)
/* 800F89F0 000F57F0  C0 61 00 64 */	lfs f3, 0x64(r1)
/* 800F89F4 000F57F4  C0 E1 00 50 */	lfs f7, 0x50(r1)
/* 800F89F8 000F57F8  EC 06 01 72 */	fmuls f0, f6, f5
/* 800F89FC 000F57FC  C0 41 00 60 */	lfs f2, 0x60(r1)
/* 800F8A00 000F5800  C0 81 00 58 */	lfs f4, 0x58(r1)
/* 800F8A04 000F5804  EC 27 00 F2 */	fmuls f1, f7, f3
/* 800F8A08 000F5808  EC 07 00 B8 */	fmsubs f0, f7, f2, f0
/* 800F8A0C 000F580C  EC 44 00 B2 */	fmuls f2, f4, f2
/* 800F8A10 000F5810  EC 24 09 78 */	fmsubs f1, f4, f5, f1
/* 800F8A14 000F5814  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 800F8A18 000F5818  EC 06 10 F8 */	fmsubs f0, f6, f3, f2
/* 800F8A1C 000F581C  D0 21 00 0C */	stfs f1, 0xc(r1)
/* 800F8A20 000F5820  80 01 00 10 */	lwz r0, 0x10(r1)
/* 800F8A24 000F5824  D0 01 00 08 */	stfs f0, 0x8(r1)
/* 800F8A28 000F5828  80 61 00 0C */	lwz r3, 0xc(r1)
/* 800F8A2C 000F582C  80 81 00 08 */	lwz r4, 0x8(r1)
/* 800F8A30 000F5830  90 61 00 48 */	stw r3, 0x48(r1)
/* 800F8A34 000F5834  90 81 00 44 */	stw r4, 0x44(r1)
/* 800F8A38 000F5838  90 01 00 4C */	stw r0, 0x4c(r1)
.L_800F8A3C:
/* 800F8A3C 000F583C  C1 61 00 44 */	lfs f11, 0x44(r1)
/* 800F8A40 000F5840  C1 41 00 48 */	lfs f10, 0x48(r1)
/* 800F8A44 000F5844  C1 21 00 4C */	lfs f9, 0x4c(r1)
/* 800F8A48 000F5848  C1 01 00 50 */	lfs f8, 0x50(r1)
/* 800F8A4C 000F584C  C0 E1 00 54 */	lfs f7, 0x54(r1)
/* 800F8A50 000F5850  C0 C1 00 58 */	lfs f6, 0x58(r1)
/* 800F8A54 000F5854  C0 A1 00 5C */	lfs f5, 0x5c(r1)
/* 800F8A58 000F5858  C0 81 00 60 */	lfs f4, 0x60(r1)
/* 800F8A5C 000F585C  C0 61 00 64 */	lfs f3, 0x64(r1)
/* 800F8A60 000F5860  C0 41 00 68 */	lfs f2, 0x68(r1)
/* 800F8A64 000F5864  C0 21 00 6C */	lfs f1, 0x6c(r1)
/* 800F8A68 000F5868  C0 01 00 70 */	lfs f0, 0x70(r1)
/* 800F8A6C 000F586C  D1 61 00 74 */	stfs f11, 0x74(r1)
/* 800F8A70 000F5870  D1 41 00 84 */	stfs f10, 0x84(r1)
/* 800F8A74 000F5874  D1 21 00 94 */	stfs f9, 0x94(r1)
/* 800F8A78 000F5878  D1 01 00 78 */	stfs f8, 0x78(r1)
/* 800F8A7C 000F587C  D0 E1 00 88 */	stfs f7, 0x88(r1)
/* 800F8A80 000F5880  D0 C1 00 98 */	stfs f6, 0x98(r1)
/* 800F8A84 000F5884  D0 A1 00 7C */	stfs f5, 0x7c(r1)
/* 800F8A88 000F5888  D0 81 00 8C */	stfs f4, 0x8c(r1)
/* 800F8A8C 000F588C  D0 61 00 9C */	stfs f3, 0x9c(r1)
/* 800F8A90 000F5890  D0 41 00 80 */	stfs f2, 0x80(r1)
/* 800F8A94 000F5894  D0 21 00 90 */	stfs f1, 0x90(r1)
/* 800F8A98 000F5898  D0 01 00 A0 */	stfs f0, 0xa0(r1)
/* 800F8A9C 000F589C  88 1E 01 2C */	lbz r0, 0x12c(r30)
/* 800F8AA0 000F58A0  54 00 D7 FF */	extrwi. r0, r0, 1, 25
/* 800F8AA4 000F58A4  41 82 00 18 */	beq .L_800F8ABC
/* 800F8AA8 000F58A8  4B FD A5 B1 */	bl kar_grcommon__near_800d3058
/* 800F8AAC 000F58AC  C0 02 91 3C */	lfs f0, lbl_805DF83C@sda21(r0)
/* 800F8AB0 000F58B0  38 61 00 74 */	addi r3, r1, 0x74
/* 800F8AB4 000F58B4  EC 20 08 24 */	fdivs f1, f0, f1
/* 800F8AB8 000F58B8  4B FF E8 D5 */	bl kar_gryakueffect_scale_orientation_matrix
.L_800F8ABC:
/* 800F8ABC 000F58BC  FC 20 F8 90 */	fmr f1, f31
/* 800F8AC0 000F58C0  38 61 00 74 */	addi r3, r1, 0x74
/* 800F8AC4 000F58C4  4B FF E8 C9 */	bl kar_gryakueffect_scale_orientation_matrix
/* 800F8AC8 000F58C8  83 FF 00 28 */	lwz r31, 0x28(r31)
/* 800F8ACC 000F58CC  28 1F 00 00 */	cmplwi r31, 0x0
/* 800F8AD0 000F58D0  40 82 00 14 */	bne .L_800F8AE4
/* 800F8AD4 000F58D4  38 6D 91 2C */	li r3, kar_srcfile_jobj_h_805d620c@sda21
/* 800F8AD8 000F58D8  38 80 04 95 */	li r4, 0x495
/* 800F8ADC 000F58DC  38 AD 91 34 */	li r5, lbl_805D6214@sda21
/* 800F8AE0 000F58E0  48 32 F9 D9 */	bl __assert
.L_800F8AE4:
/* 800F8AE4 000F58E4  38 61 00 74 */	addi r3, r1, 0x74
/* 800F8AE8 000F58E8  38 9F 00 44 */	addi r4, r31, 0x44
/* 800F8AEC 000F58EC  48 2D 89 3D */	bl PSMTXCopy
/* 800F8AF0 000F58F0  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 800F8AF4 000F58F4  28 1F 00 00 */	cmplwi r31, 0x0
/* 800F8AF8 000F58F8  64 00 03 80 */	oris r0, r0, 0x380
/* 800F8AFC 000F58FC  90 1F 00 14 */	stw r0, 0x14(r31)
/* 800F8B00 000F5900  41 82 00 44 */	beq .L_800F8B44
/* 800F8B04 000F5904  40 82 00 14 */	bne .L_800F8B18
/* 800F8B08 000F5908  38 6D 91 2C */	li r3, kar_srcfile_jobj_h_805d620c@sda21
/* 800F8B0C 000F590C  38 80 02 5D */	li r4, 0x25d
/* 800F8B10 000F5910  38 AD 91 34 */	li r5, lbl_805D6214@sda21
/* 800F8B14 000F5914  48 32 F9 A5 */	bl __assert
.L_800F8B18:
/* 800F8B18 000F5918  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 800F8B1C 000F591C  38 60 00 00 */	li r3, 0x0
/* 800F8B20 000F5920  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 800F8B24 000F5924  40 82 00 10 */	bne .L_800F8B34
/* 800F8B28 000F5928  54 80 06 73 */	rlwinm. r0, r4, 0, 25, 25
/* 800F8B2C 000F592C  41 82 00 08 */	beq .L_800F8B34
/* 800F8B30 000F5930  38 60 00 01 */	li r3, 0x1
.L_800F8B34:
/* 800F8B34 000F5934  2C 03 00 00 */	cmpwi r3, 0x0
/* 800F8B38 000F5938  40 82 00 0C */	bne .L_800F8B44
/* 800F8B3C 000F593C  7F E3 FB 78 */	mr r3, r31
/* 800F8B40 000F5940  48 31 4D ED */	bl HSD_JObjSetMtxDirtySub
.L_800F8B44:
/* 800F8B44 000F5944  E3 E1 00 D8 */	psq_l f31, 0xd8(r1), 0, qr0
/* 800F8B48 000F5948  CB E1 00 D0 */	lfd f31, 0xd0(r1)
/* 800F8B4C 000F594C  E3 C1 00 C8 */	psq_l f30, 0xc8(r1), 0, qr0
/* 800F8B50 000F5950  CB C1 00 C0 */	lfd f30, 0xc0(r1)
/* 800F8B54 000F5954  83 E1 00 BC */	lwz r31, 0xbc(r1)
/* 800F8B58 000F5958  83 C1 00 B8 */	lwz r30, 0xb8(r1)
/* 800F8B5C 000F595C  83 A1 00 B4 */	lwz r29, 0xb4(r1)
/* 800F8B60 000F5960  80 01 00 E4 */	lwz r0, 0xe4(r1)
/* 800F8B64 000F5964  83 81 00 B0 */	lwz r28, 0xb0(r1)
/* 800F8B68 000F5968  7C 08 03 A6 */	mtlr r0
/* 800F8B6C 000F596C  38 21 00 E0 */	addi r1, r1, 0xe0
/* 800F8B70 000F5970  4E 80 00 20 */	blr
.endfn kar_gryakucommon_sync_jobj_to_eventpos_matrix

# .text:0x390 | 0x800F8B74 | size: 0x50
.fn kar_gryakucommon_lookup_script_entry_value, global
/* 800F8B74 000F5974  80 03 00 04 */	lwz r0, 0x4(r3)
/* 800F8B78 000F5978  38 E0 00 00 */	li r7, 0x0
/* 800F8B7C 000F597C  38 A0 00 00 */	li r5, 0x0
/* 800F8B80 000F5980  7C 09 03 A6 */	mtctr r0
/* 800F8B84 000F5984  2C 00 00 00 */	cmpwi r0, 0x0
/* 800F8B88 000F5988  40 81 00 34 */	ble .L_800F8BBC
.L_800F8B8C:
/* 800F8B8C 000F598C  80 C3 00 00 */	lwz r6, 0x0(r3)
/* 800F8B90 000F5990  38 05 00 08 */	addi r0, r5, 0x8
/* 800F8B94 000F5994  7C 06 00 2E */	lwzx r0, r6, r0
/* 800F8B98 000F5998  7C 04 00 00 */	cmpw r4, r0
/* 800F8B9C 000F599C  40 82 00 14 */	bne .L_800F8BB0
/* 800F8BA0 000F59A0  1C 07 00 0C */	mulli r0, r7, 0xc
/* 800F8BA4 000F59A4  7C 66 02 14 */	add r3, r6, r0
/* 800F8BA8 000F59A8  80 63 00 04 */	lwz r3, 0x4(r3)
/* 800F8BAC 000F59AC  4E 80 00 20 */	blr
.L_800F8BB0:
/* 800F8BB0 000F59B0  38 A5 00 0C */	addi r5, r5, 0xc
/* 800F8BB4 000F59B4  38 E7 00 01 */	addi r7, r7, 0x1
/* 800F8BB8 000F59B8  42 00 FF D4 */	bdnz .L_800F8B8C
.L_800F8BBC:
/* 800F8BBC 000F59BC  38 60 00 00 */	li r3, 0x0
/* 800F8BC0 000F59C0  4E 80 00 20 */	blr
.endfn kar_gryakucommon_lookup_script_entry_value

# .text:0x3E0 | 0x800F8BC4 | size: 0x4
.fn kar_gryakucommon_opcode_noop_primary, global
/* 800F8BC4 000F59C4  4E 80 00 20 */	blr
.endfn kar_gryakucommon_opcode_noop_primary

# .text:0x3E4 | 0x800F8BC8 | size: 0x4
.fn kar_gryakucommon_opcode_noop_secondary, global
/* 800F8BC8 000F59C8  4E 80 00 20 */	blr
.endfn kar_gryakucommon_opcode_noop_secondary

# .text:0x3E8 | 0x800F8BCC | size: 0x29C
.fn kar_gryakucommon_decode_clobject_slot_opcode, global
/* 800F8BCC 000F59CC  94 21 FF 70 */	stwu r1, -0x90(r1)
/* 800F8BD0 000F59D0  7C 08 02 A6 */	mflr r0
/* 800F8BD4 000F59D4  3D 40 43 30 */	lis r10, 0x4330
/* 800F8BD8 000F59D8  C8 62 91 50 */	lfd f3, lbl_805DF850@sda21(r0)
/* 800F8BDC 000F59DC  90 01 00 94 */	stw r0, 0x94(r1)
/* 800F8BE0 000F59E0  C0 82 91 40 */	lfs f4, lbl_805DF840@sda21(r0)
/* 800F8BE4 000F59E4  93 E1 00 8C */	stw r31, 0x8c(r1)
/* 800F8BE8 000F59E8  C8 22 91 58 */	lfd f1, lbl_805DF858@sda21(r0)
/* 800F8BEC 000F59EC  93 C1 00 88 */	stw r30, 0x88(r1)
/* 800F8BF0 000F59F0  81 64 00 08 */	lwz r11, 0x8(r4)
/* 800F8BF4 000F59F4  88 A1 00 38 */	lbz r5, 0x38(r1)
/* 800F8BF8 000F59F8  88 0B 00 01 */	lbz r0, 0x1(r11)
/* 800F8BFC 000F59FC  38 CB 00 04 */	addi r6, r11, 0x4
/* 800F8C00 000F5A00  A0 EB 00 00 */	lhz r7, 0x0(r11)
/* 800F8C04 000F5A04  50 05 0E 34 */	rlwimi r5, r0, 1, 24, 26
/* 800F8C08 000F5A08  89 21 00 35 */	lbz r9, 0x35(r1)
/* 800F8C0C 000F5A0C  98 A1 00 38 */	stb r5, 0x38(r1)
/* 800F8C10 000F5A10  54 E0 CF 7E */	extrwi r0, r7, 3, 22
/* 800F8C14 000F5A14  A0 AB 00 02 */	lhz r5, 0x2(r11)
/* 800F8C18 000F5A18  81 0B 00 00 */	lwz r8, 0x0(r11)
/* 800F8C1C 000F5A1C  54 A7 F5 BE */	extrwi r7, r5, 10, 20
/* 800F8C20 000F5A20  91 41 00 40 */	stw r10, 0x40(r1)
/* 800F8C24 000F5A24  55 05 A6 3E */	extrwi r5, r8, 8, 12
/* 800F8C28 000F5A28  90 E1 00 08 */	stw r7, 0x8(r1)
/* 800F8C2C 000F5A2C  89 0B 00 03 */	lbz r8, 0x3(r11)
/* 800F8C30 000F5A30  91 41 00 48 */	stw r10, 0x48(r1)
/* 800F8C34 000F5A34  51 09 17 7A */	rlwimi r9, r8, 2, 29, 29
/* 800F8C38 000F5A38  55 27 06 3E */	clrlwi r7, r9, 24
/* 800F8C3C 000F5A3C  99 21 00 35 */	stb r9, 0x35(r1)
/* 800F8C40 000F5A40  51 07 07 BC */	rlwimi r7, r8, 0, 30, 30
/* 800F8C44 000F5A44  98 E1 00 35 */	stb r7, 0x35(r1)
/* 800F8C48 000F5A48  90 C4 00 08 */	stw r6, 0x8(r4)
/* 800F8C4C 000F5A4C  81 04 00 08 */	lwz r8, 0x8(r4)
/* 800F8C50 000F5A50  91 41 00 50 */	stw r10, 0x50(r1)
/* 800F8C54 000F5A54  A0 E8 00 00 */	lhz r7, 0x0(r8)
/* 800F8C58 000F5A58  38 C8 00 04 */	addi r6, r8, 0x4
/* 800F8C5C 000F5A5C  91 41 00 58 */	stw r10, 0x58(r1)
/* 800F8C60 000F5A60  90 E1 00 44 */	stw r7, 0x44(r1)
/* 800F8C64 000F5A64  C8 01 00 40 */	lfd f0, 0x40(r1)
/* 800F8C68 000F5A68  91 41 00 60 */	stw r10, 0x60(r1)
/* 800F8C6C 000F5A6C  EC 00 18 28 */	fsubs f0, f0, f3
/* 800F8C70 000F5A70  EC 04 00 32 */	fmuls f0, f4, f0
/* 800F8C74 000F5A74  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 800F8C78 000F5A78  A8 E8 00 02 */	lha r7, 0x2(r8)
/* 800F8C7C 000F5A7C  6C E7 80 00 */	xoris r7, r7, 0x8000
/* 800F8C80 000F5A80  90 E1 00 4C */	stw r7, 0x4c(r1)
/* 800F8C84 000F5A84  C8 01 00 48 */	lfd f0, 0x48(r1)
/* 800F8C88 000F5A88  EC 00 08 28 */	fsubs f0, f0, f1
/* 800F8C8C 000F5A8C  EC 04 00 32 */	fmuls f0, f4, f0
/* 800F8C90 000F5A90  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 800F8C94 000F5A94  90 C4 00 08 */	stw r6, 0x8(r4)
/* 800F8C98 000F5A98  81 04 00 08 */	lwz r8, 0x8(r4)
/* 800F8C9C 000F5A9C  A8 E8 00 00 */	lha r7, 0x0(r8)
/* 800F8CA0 000F5AA0  38 C8 00 04 */	addi r6, r8, 0x4
/* 800F8CA4 000F5AA4  6C E7 80 00 */	xoris r7, r7, 0x8000
/* 800F8CA8 000F5AA8  90 E1 00 54 */	stw r7, 0x54(r1)
/* 800F8CAC 000F5AAC  C8 01 00 50 */	lfd f0, 0x50(r1)
/* 800F8CB0 000F5AB0  EC 00 08 28 */	fsubs f0, f0, f1
/* 800F8CB4 000F5AB4  EC 04 00 32 */	fmuls f0, f4, f0
/* 800F8CB8 000F5AB8  D0 01 00 14 */	stfs f0, 0x14(r1)
/* 800F8CBC 000F5ABC  A8 E8 00 02 */	lha r7, 0x2(r8)
/* 800F8CC0 000F5AC0  6C E7 80 00 */	xoris r7, r7, 0x8000
/* 800F8CC4 000F5AC4  90 E1 00 5C */	stw r7, 0x5c(r1)
/* 800F8CC8 000F5AC8  C8 01 00 58 */	lfd f0, 0x58(r1)
/* 800F8CCC 000F5ACC  EC 00 08 28 */	fsubs f0, f0, f1
/* 800F8CD0 000F5AD0  EC 04 00 32 */	fmuls f0, f4, f0
/* 800F8CD4 000F5AD4  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 800F8CD8 000F5AD8  90 C4 00 08 */	stw r6, 0x8(r4)
/* 800F8CDC 000F5ADC  81 24 00 08 */	lwz r9, 0x8(r4)
/* 800F8CE0 000F5AE0  88 C9 00 00 */	lbz r6, 0x0(r9)
/* 800F8CE4 000F5AE4  90 C1 00 64 */	stw r6, 0x64(r1)
/* 800F8CE8 000F5AE8  C8 01 00 60 */	lfd f0, 0x60(r1)
/* 800F8CEC 000F5AEC  EC 00 18 28 */	fsubs f0, f0, f3
/* 800F8CF0 000F5AF0  EC 04 00 32 */	fmuls f0, f4, f0
/* 800F8CF4 000F5AF4  D0 01 00 20 */	stfs f0, 0x20(r1)
/* 800F8CF8 000F5AF8  89 09 00 01 */	lbz r8, 0x1(r9)
/* 800F8CFC 000F5AFC  38 E9 00 04 */	addi r7, r9, 0x4
/* 800F8D00 000F5B00  91 41 00 68 */	stw r10, 0x68(r1)
/* 800F8D04 000F5B04  38 C1 00 08 */	addi r6, r1, 0x8
/* 800F8D08 000F5B08  C0 42 91 44 */	lfs f2, lbl_805DF844@sda21(r0)
/* 800F8D0C 000F5B0C  91 01 00 6C */	stw r8, 0x6c(r1)
/* 800F8D10 000F5B10  C0 02 91 48 */	lfs f0, lbl_805DF848@sda21(r0)
/* 800F8D14 000F5B14  C8 21 00 68 */	lfd f1, 0x68(r1)
/* 800F8D18 000F5B18  91 41 00 70 */	stw r10, 0x70(r1)
/* 800F8D1C 000F5B1C  EC 21 18 28 */	fsubs f1, f1, f3
/* 800F8D20 000F5B20  91 41 00 78 */	stw r10, 0x78(r1)
/* 800F8D24 000F5B24  EC 24 00 72 */	fmuls f1, f4, f1
/* 800F8D28 000F5B28  91 41 00 80 */	stw r10, 0x80(r1)
/* 800F8D2C 000F5B2C  D0 21 00 24 */	stfs f1, 0x24(r1)
/* 800F8D30 000F5B30  A1 09 00 02 */	lhz r8, 0x2(r9)
/* 800F8D34 000F5B34  91 01 00 74 */	stw r8, 0x74(r1)
/* 800F8D38 000F5B38  C8 21 00 70 */	lfd f1, 0x70(r1)
/* 800F8D3C 000F5B3C  EC 21 18 28 */	fsubs f1, f1, f3
/* 800F8D40 000F5B40  EC 24 00 72 */	fmuls f1, f4, f1
/* 800F8D44 000F5B44  D0 21 00 28 */	stfs f1, 0x28(r1)
/* 800F8D48 000F5B48  90 E4 00 08 */	stw r7, 0x8(r4)
/* 800F8D4C 000F5B4C  81 24 00 08 */	lwz r9, 0x8(r4)
/* 800F8D50 000F5B50  A1 09 00 00 */	lhz r8, 0x0(r9)
/* 800F8D54 000F5B54  38 E9 00 04 */	addi r7, r9, 0x4
/* 800F8D58 000F5B58  91 01 00 7C */	stw r8, 0x7c(r1)
/* 800F8D5C 000F5B5C  C8 21 00 78 */	lfd f1, 0x78(r1)
/* 800F8D60 000F5B60  EC 21 18 28 */	fsubs f1, f1, f3
/* 800F8D64 000F5B64  EC 24 00 72 */	fmuls f1, f4, f1
/* 800F8D68 000F5B68  EC 22 00 72 */	fmuls f1, f2, f1
/* 800F8D6C 000F5B6C  D0 21 00 0C */	stfs f1, 0xc(r1)
/* 800F8D70 000F5B70  A1 09 00 02 */	lhz r8, 0x2(r9)
/* 800F8D74 000F5B74  91 01 00 84 */	stw r8, 0x84(r1)
/* 800F8D78 000F5B78  C8 21 00 80 */	lfd f1, 0x80(r1)
/* 800F8D7C 000F5B7C  EC 21 18 28 */	fsubs f1, f1, f3
/* 800F8D80 000F5B80  EC 24 00 72 */	fmuls f1, f4, f1
/* 800F8D84 000F5B84  EC 22 00 72 */	fmuls f1, f2, f1
/* 800F8D88 000F5B88  D0 21 00 2C */	stfs f1, 0x2c(r1)
/* 800F8D8C 000F5B8C  90 E4 00 08 */	stw r7, 0x8(r4)
/* 800F8D90 000F5B90  83 C4 00 08 */	lwz r30, 0x8(r4)
/* 800F8D94 000F5B94  89 21 00 37 */	lbz r9, 0x37(r1)
/* 800F8D98 000F5B98  8B FE 00 00 */	lbz r31, 0x0(r30)
/* 800F8D9C 000F5B9C  38 FE 00 04 */	addi r7, r30, 0x4
/* 800F8DA0 000F5BA0  89 41 00 34 */	lbz r10, 0x34(r1)
/* 800F8DA4 000F5BA4  53 E9 FF BC */	rlwimi r9, r31, 31, 30, 30
/* 800F8DA8 000F5BA8  89 81 00 35 */	lbz r12, 0x35(r1)
/* 800F8DAC 000F5BAC  53 EA 06 38 */	rlwimi r10, r31, 0, 24, 28
/* 800F8DB0 000F5BB0  53 EC 17 38 */	rlwimi r12, r31, 2, 28, 28
/* 800F8DB4 000F5BB4  99 21 00 37 */	stb r9, 0x37(r1)
/* 800F8DB8 000F5BB8  55 29 06 3E */	clrlwi r9, r9, 24
/* 800F8DBC 000F5BBC  53 E9 07 FE */	rlwimi r9, r31, 0, 31, 31
/* 800F8DC0 000F5BC0  55 88 06 3E */	clrlwi r8, r12, 24
/* 800F8DC4 000F5BC4  99 21 00 37 */	stb r9, 0x37(r1)
/* 800F8DC8 000F5BC8  55 4B 06 3E */	clrlwi r11, r10, 24
/* 800F8DCC 000F5BCC  99 41 00 34 */	stb r10, 0x34(r1)
/* 800F8DD0 000F5BD0  A1 21 00 36 */	lhz r9, 0x36(r1)
/* 800F8DD4 000F5BD4  99 81 00 35 */	stb r12, 0x35(r1)
/* 800F8DD8 000F5BD8  89 41 00 38 */	lbz r10, 0x38(r1)
/* 800F8DDC 000F5BDC  89 9E 00 01 */	lbz r12, 0x1(r30)
/* 800F8DE0 000F5BE0  51 89 15 BA */	rlwimi r9, r12, 2, 22, 29
/* 800F8DE4 000F5BE4  B1 21 00 36 */	sth r9, 0x36(r1)
/* 800F8DE8 000F5BE8  89 3E 00 02 */	lbz r9, 0x2(r30)
/* 800F8DEC 000F5BEC  51 2B DF 7E */	rlwimi r11, r9, 27, 29, 31
/* 800F8DF0 000F5BF0  51 28 1E 36 */	rlwimi r8, r9, 3, 24, 27
/* 800F8DF4 000F5BF4  99 61 00 34 */	stb r11, 0x34(r1)
/* 800F8DF8 000F5BF8  99 01 00 35 */	stb r8, 0x35(r1)
/* 800F8DFC 000F5BFC  A1 3E 00 02 */	lhz r9, 0x2(r30)
/* 800F8E00 000F5C00  81 01 00 34 */	lwz r8, 0x34(r1)
/* 800F8E04 000F5C04  51 28 43 EA */	rlwimi r8, r9, 8, 15, 21
/* 800F8E08 000F5C08  91 01 00 34 */	stw r8, 0x34(r1)
/* 800F8E0C 000F5C0C  89 3E 00 03 */	lbz r9, 0x3(r30)
/* 800F8E10 000F5C10  51 2A 1E F6 */	rlwimi r10, r9, 3, 27, 27
/* 800F8E14 000F5C14  55 48 06 3E */	clrlwi r8, r10, 24
/* 800F8E18 000F5C18  99 41 00 38 */	stb r10, 0x38(r1)
/* 800F8E1C 000F5C1C  51 28 1F 38 */	rlwimi r8, r9, 3, 28, 28
/* 800F8E20 000F5C20  99 01 00 38 */	stb r8, 0x38(r1)
/* 800F8E24 000F5C24  90 E4 00 08 */	stw r7, 0x8(r4)
/* 800F8E28 000F5C28  80 E4 00 08 */	lwz r7, 0x8(r4)
/* 800F8E2C 000F5C2C  89 07 00 00 */	lbz r8, 0x0(r7)
/* 800F8E30 000F5C30  38 E7 00 04 */	addi r7, r7, 0x4
/* 800F8E34 000F5C34  90 E4 00 08 */	stw r7, 0x8(r4)
/* 800F8E38 000F5C38  55 04 CF FE */	extrwi r4, r8, 1, 24
/* 800F8E3C 000F5C3C  7C 87 00 34 */	cntlzw r7, r4
/* 800F8E40 000F5C40  D0 01 00 30 */	stfs f0, 0x30(r1)
/* 800F8E44 000F5C44  7C 04 03 78 */	mr r4, r0
/* 800F8E48 000F5C48  54 E7 D9 7E */	srwi r7, r7, 5
/* 800F8E4C 000F5C4C  4B FF F5 3D */	bl kar_gryakulib_update_clobject_slot
/* 800F8E50 000F5C50  80 01 00 94 */	lwz r0, 0x94(r1)
/* 800F8E54 000F5C54  83 E1 00 8C */	lwz r31, 0x8c(r1)
/* 800F8E58 000F5C58  83 C1 00 88 */	lwz r30, 0x88(r1)
/* 800F8E5C 000F5C5C  7C 08 03 A6 */	mtlr r0
/* 800F8E60 000F5C60  38 21 00 90 */	addi r1, r1, 0x90
/* 800F8E64 000F5C64  4E 80 00 20 */	blr
.endfn kar_gryakucommon_decode_clobject_slot_opcode

# .text:0x684 | 0x800F8E68 | size: 0x3C
.fn kar_gryakucommon_flush_clobject_slots_opcode, global
/* 800F8E68 000F5C68  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F8E6C 000F5C6C  7C 08 02 A6 */	mflr r0
/* 800F8E70 000F5C70  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F8E74 000F5C74  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F8E78 000F5C78  7C 9F 23 78 */	mr r31, r4
/* 800F8E7C 000F5C7C  80 63 00 EC */	lwz r3, 0xec(r3)
/* 800F8E80 000F5C80  48 09 39 A5 */	bl kar_collision_object_flush_dirty_motion_slots
/* 800F8E84 000F5C84  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F8E88 000F5C88  38 03 00 04 */	addi r0, r3, 0x4
/* 800F8E8C 000F5C8C  90 1F 00 08 */	stw r0, 0x8(r31)
/* 800F8E90 000F5C90  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F8E94 000F5C94  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F8E98 000F5C98  7C 08 03 A6 */	mtlr r0
/* 800F8E9C 000F5C9C  38 21 00 10 */	addi r1, r1, 0x10
/* 800F8EA0 000F5CA0  4E 80 00 20 */	blr
.endfn kar_gryakucommon_flush_clobject_slots_opcode

# .text:0x6C0 | 0x800F8EA4 | size: 0x188
.fn kar_gryakucommon_decode_animlist_effect_opcode, global
/* 800F8EA4 000F5CA4  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 800F8EA8 000F5CA8  7C 08 02 A6 */	mflr r0
/* 800F8EAC 000F5CAC  3D 20 43 30 */	lis r9, 0x4330
/* 800F8EB0 000F5CB0  C8 42 91 58 */	lfd f2, lbl_805DF858@sda21(r0)
/* 800F8EB4 000F5CB4  90 01 00 64 */	stw r0, 0x64(r1)
/* 800F8EB8 000F5CB8  C0 62 91 40 */	lfs f3, lbl_805DF840@sda21(r0)
/* 800F8EBC 000F5CBC  80 E4 00 08 */	lwz r7, 0x8(r4)
/* 800F8EC0 000F5CC0  91 21 00 28 */	stw r9, 0x28(r1)
/* 800F8EC4 000F5CC4  A0 A7 00 00 */	lhz r5, 0x0(r7)
/* 800F8EC8 000F5CC8  38 07 00 04 */	addi r0, r7, 0x4
/* 800F8ECC 000F5CCC  88 C7 00 01 */	lbz r6, 0x1(r7)
/* 800F8ED0 000F5CD0  81 07 00 00 */	lwz r8, 0x0(r7)
/* 800F8ED4 000F5CD4  54 A5 F6 3E */	extrwi r5, r5, 8, 22
/* 800F8ED8 000F5CD8  88 E7 00 03 */	lbz r7, 0x3(r7)
/* 800F8EDC 000F5CDC  54 C6 FF FE */	extrwi r6, r6, 1, 30
/* 800F8EE0 000F5CE0  55 0A FC 3E */	extrwi r10, r8, 16, 15
/* 800F8EE4 000F5CE4  91 21 00 30 */	stw r9, 0x30(r1)
/* 800F8EE8 000F5CE8  C8 82 91 50 */	lfd f4, lbl_805DF850@sda21(r0)
/* 800F8EEC 000F5CEC  90 04 00 08 */	stw r0, 0x8(r4)
/* 800F8EF0 000F5CF0  54 E0 07 FF */	clrlwi. r0, r7, 31
/* 800F8EF4 000F5CF4  80 E4 00 08 */	lwz r7, 0x8(r4)
/* 800F8EF8 000F5CF8  91 21 00 38 */	stw r9, 0x38(r1)
/* 800F8EFC 000F5CFC  81 67 00 00 */	lwz r11, 0x0(r7)
/* 800F8F00 000F5D00  38 07 00 04 */	addi r0, r7, 0x4
/* 800F8F04 000F5D04  91 21 00 40 */	stw r9, 0x40(r1)
/* 800F8F08 000F5D08  90 04 00 08 */	stw r0, 0x8(r4)
/* 800F8F0C 000F5D0C  81 04 00 08 */	lwz r8, 0x8(r4)
/* 800F8F10 000F5D10  91 21 00 48 */	stw r9, 0x48(r1)
/* 800F8F14 000F5D14  A8 E8 00 00 */	lha r7, 0x0(r8)
/* 800F8F18 000F5D18  38 08 00 04 */	addi r0, r8, 0x4
/* 800F8F1C 000F5D1C  91 21 00 50 */	stw r9, 0x50(r1)
/* 800F8F20 000F5D20  6C E7 80 00 */	xoris r7, r7, 0x8000
/* 800F8F24 000F5D24  90 E1 00 2C */	stw r7, 0x2c(r1)
/* 800F8F28 000F5D28  C8 01 00 28 */	lfd f0, 0x28(r1)
/* 800F8F2C 000F5D2C  91 41 00 24 */	stw r10, 0x24(r1)
/* 800F8F30 000F5D30  EC 00 10 28 */	fsubs f0, f0, f2
/* 800F8F34 000F5D34  91 21 00 20 */	stw r9, 0x20(r1)
/* 800F8F38 000F5D38  EC 03 00 32 */	fmuls f0, f3, f0
/* 800F8F3C 000F5D3C  C8 21 00 20 */	lfd f1, 0x20(r1)
/* 800F8F40 000F5D40  EC 21 20 28 */	fsubs f1, f1, f4
/* 800F8F44 000F5D44  D0 01 00 14 */	stfs f0, 0x14(r1)
/* 800F8F48 000F5D48  A8 E8 00 02 */	lha r7, 0x2(r8)
/* 800F8F4C 000F5D4C  6C E7 80 00 */	xoris r7, r7, 0x8000
/* 800F8F50 000F5D50  90 E1 00 34 */	stw r7, 0x34(r1)
/* 800F8F54 000F5D54  C8 01 00 30 */	lfd f0, 0x30(r1)
/* 800F8F58 000F5D58  EC 00 10 28 */	fsubs f0, f0, f2
/* 800F8F5C 000F5D5C  EC 03 00 32 */	fmuls f0, f3, f0
/* 800F8F60 000F5D60  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 800F8F64 000F5D64  90 04 00 08 */	stw r0, 0x8(r4)
/* 800F8F68 000F5D68  81 04 00 08 */	lwz r8, 0x8(r4)
/* 800F8F6C 000F5D6C  A8 E8 00 00 */	lha r7, 0x0(r8)
/* 800F8F70 000F5D70  38 08 00 04 */	addi r0, r8, 0x4
/* 800F8F74 000F5D74  6C E7 80 00 */	xoris r7, r7, 0x8000
/* 800F8F78 000F5D78  90 E1 00 3C */	stw r7, 0x3c(r1)
/* 800F8F7C 000F5D7C  C8 01 00 38 */	lfd f0, 0x38(r1)
/* 800F8F80 000F5D80  EC 00 10 28 */	fsubs f0, f0, f2
/* 800F8F84 000F5D84  EC 03 00 32 */	fmuls f0, f3, f0
/* 800F8F88 000F5D88  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 800F8F8C 000F5D8C  A0 E8 00 02 */	lhz r7, 0x2(r8)
/* 800F8F90 000F5D90  90 E1 00 44 */	stw r7, 0x44(r1)
/* 800F8F94 000F5D94  C8 01 00 40 */	lfd f0, 0x40(r1)
/* 800F8F98 000F5D98  EC 00 20 28 */	fsubs f0, f0, f4
/* 800F8F9C 000F5D9C  EC 03 00 32 */	fmuls f0, f3, f0
/* 800F8FA0 000F5DA0  D0 01 00 08 */	stfs f0, 0x8(r1)
/* 800F8FA4 000F5DA4  90 04 00 08 */	stw r0, 0x8(r4)
/* 800F8FA8 000F5DA8  81 04 00 08 */	lwz r8, 0x8(r4)
/* 800F8FAC 000F5DAC  A0 E8 00 00 */	lhz r7, 0x0(r8)
/* 800F8FB0 000F5DB0  38 08 00 04 */	addi r0, r8, 0x4
/* 800F8FB4 000F5DB4  90 E1 00 4C */	stw r7, 0x4c(r1)
/* 800F8FB8 000F5DB8  C8 01 00 48 */	lfd f0, 0x48(r1)
/* 800F8FBC 000F5DBC  EC 00 20 28 */	fsubs f0, f0, f4
/* 800F8FC0 000F5DC0  EC 03 00 32 */	fmuls f0, f3, f0
/* 800F8FC4 000F5DC4  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 800F8FC8 000F5DC8  A0 E8 00 02 */	lhz r7, 0x2(r8)
/* 800F8FCC 000F5DCC  90 E1 00 54 */	stw r7, 0x54(r1)
/* 800F8FD0 000F5DD0  C8 01 00 50 */	lfd f0, 0x50(r1)
/* 800F8FD4 000F5DD4  EC 00 20 28 */	fsubs f0, f0, f4
/* 800F8FD8 000F5DD8  EC 03 00 32 */	fmuls f0, f3, f0
/* 800F8FDC 000F5DDC  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 800F8FE0 000F5DE0  90 04 00 08 */	stw r0, 0x8(r4)
/* 800F8FE4 000F5DE4  41 82 00 20 */	beq .L_800F9004
/* 800F8FE8 000F5DE8  80 63 00 00 */	lwz r3, 0x0(r3)
/* 800F8FEC 000F5DEC  7D 64 5B 78 */	mr r4, r11
/* 800F8FF0 000F5DF0  38 E1 00 14 */	addi r7, r1, 0x14
/* 800F8FF4 000F5DF4  39 01 00 08 */	addi r8, r1, 0x8
/* 800F8FF8 000F5DF8  39 20 00 00 */	li r9, 0x0
/* 800F8FFC 000F5DFC  4B FF D6 E5 */	bl kar_gryakueffect_request_animlist_effect
/* 800F9000 000F5E00  48 00 00 1C */	b .L_800F901C
.L_800F9004:
/* 800F9004 000F5E04  80 63 00 00 */	lwz r3, 0x0(r3)
/* 800F9008 000F5E08  7D 64 5B 78 */	mr r4, r11
/* 800F900C 000F5E0C  38 E1 00 14 */	addi r7, r1, 0x14
/* 800F9010 000F5E10  39 01 00 08 */	addi r8, r1, 0x8
/* 800F9014 000F5E14  39 20 00 01 */	li r9, 0x1
/* 800F9018 000F5E18  4B FF D6 C9 */	bl kar_gryakueffect_request_animlist_effect
.L_800F901C:
/* 800F901C 000F5E1C  80 01 00 64 */	lwz r0, 0x64(r1)
/* 800F9020 000F5E20  7C 08 03 A6 */	mtlr r0
/* 800F9024 000F5E24  38 21 00 60 */	addi r1, r1, 0x60
/* 800F9028 000F5E28  4E 80 00 20 */	blr
.endfn kar_gryakucommon_decode_animlist_effect_opcode

# .text:0x848 | 0x800F902C | size: 0x4
.fn kar_gryakucommon_opcode_noop_terminator, global
/* 800F902C 000F5E2C  4E 80 00 20 */	blr
.endfn kar_gryakucommon_opcode_noop_terminator

# .text:0x84C | 0x800F9030 | size: 0x11C
.fn kar_gryakucommon_run_opcode_stream, global
/* 800F9030 000F5E30  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800F9034 000F5E34  7C 08 02 A6 */	mflr r0
/* 800F9038 000F5E38  90 01 00 34 */	stw r0, 0x34(r1)
/* 800F903C 000F5E3C  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 800F9040 000F5E40  F3 E1 00 28 */	psq_st f31, 0x28(r1), 0, qr0
/* 800F9044 000F5E44  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F9048 000F5E48  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F904C 000F5E4C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F9050 000F5E50  7C 7D 1B 78 */	mr r29, r3
/* 800F9054 000F5E54  C0 23 00 E0 */	lfs f1, 0xe0(r3)
/* 800F9058 000F5E58  3B FD 00 BC */	addi r31, r29, 0xbc
/* 800F905C 000F5E5C  C0 03 00 E4 */	lfs f0, 0xe4(r3)
/* 800F9060 000F5E60  EC 01 00 2A */	fadds f0, f1, f0
/* 800F9064 000F5E64  D0 03 00 C0 */	stfs f0, 0xc0(r3)
/* 800F9068 000F5E68  80 03 00 C4 */	lwz r0, 0xc4(r3)
/* 800F906C 000F5E6C  28 00 00 00 */	cmplwi r0, 0x0
/* 800F9070 000F5E70  41 82 00 B8 */	beq .L_800F9128
/* 800F9074 000F5E74  C0 02 91 60 */	lfs f0, lbl_805DF860@sda21(r0)
/* 800F9078 000F5E78  C0 3F 00 00 */	lfs f1, 0x0(r31)
/* 800F907C 000F5E7C  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 800F9080 000F5E80  41 82 00 10 */	beq .L_800F9090
/* 800F9084 000F5E84  C0 1D 00 E8 */	lfs f0, 0xe8(r29)
/* 800F9088 000F5E88  EC 01 00 28 */	fsubs f0, f1, f0
/* 800F908C 000F5E8C  D0 1F 00 00 */	stfs f0, 0x0(r31)
.L_800F9090:
/* 800F9090 000F5E90  C3 E2 91 60 */	lfs f31, lbl_805DF860@sda21(r0)
.L_800F9094:
/* 800F9094 000F5E94  80 1F 00 08 */	lwz r0, 0x8(r31)
/* 800F9098 000F5E98  28 00 00 00 */	cmplwi r0, 0x0
/* 800F909C 000F5E9C  41 82 00 8C */	beq .L_800F9128
/* 800F90A0 000F5EA0  C0 3F 00 00 */	lfs f1, 0x0(r31)
/* 800F90A4 000F5EA4  FC 1F 08 00 */	fcmpu cr0, f31, f1
/* 800F90A8 000F5EA8  40 82 00 24 */	bne .L_800F90CC
/* 800F90AC 000F5EAC  C0 3F 00 04 */	lfs f1, 0x4(r31)
/* 800F90B0 000F5EB0  C0 1D 00 E8 */	lfs f0, 0xe8(r29)
/* 800F90B4 000F5EB4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800F90B8 000F5EB8  4C 41 13 82 */	cror eq, gt, eq
/* 800F90BC 000F5EBC  41 82 00 6C */	beq .L_800F9128
/* 800F90C0 000F5EC0  FC 00 08 50 */	fneg f0, f1
/* 800F90C4 000F5EC4  D0 1F 00 00 */	stfs f0, 0x0(r31)
/* 800F90C8 000F5EC8  48 00 00 10 */	b .L_800F90D8
.L_800F90CC:
/* 800F90CC 000F5ECC  C0 02 91 64 */	lfs f0, lbl_805DF864@sda21(r0)
/* 800F90D0 000F5ED0  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800F90D4 000F5ED4  41 81 00 54 */	bgt .L_800F9128
.L_800F90D8:
/* 800F90D8 000F5ED8  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 800F90DC 000F5EDC  7F E3 FB 78 */	mr r3, r31
/* 800F90E0 000F5EE0  88 04 00 00 */	lbz r0, 0x0(r4)
/* 800F90E4 000F5EE4  54 1E F6 BE */	extrwi r30, r0, 6, 24
/* 800F90E8 000F5EE8  7F C4 F3 78 */	mr r4, r30
/* 800F90EC 000F5EEC  4B F6 FC 89 */	bl kar_lbcamera__near_80068d74
/* 800F90F0 000F5EF0  2C 03 00 00 */	cmpwi r3, 0x0
/* 800F90F4 000F5EF4  40 82 00 28 */	bne .L_800F911C
/* 800F90F8 000F5EF8  38 1E FF F5 */	subi r0, r30, 0xb
/* 800F90FC 000F5EFC  3C 80 80 4A */	lis r4, gryakucommon_opcode_callback_table@ha
/* 800F9100 000F5F00  1C 00 00 0C */	mulli r0, r0, 0xc
/* 800F9104 000F5F04  7F A3 EB 78 */	mr r3, r29
/* 800F9108 000F5F08  38 A4 5D 50 */	addi r5, r4, gryakucommon_opcode_callback_table@l
/* 800F910C 000F5F0C  7F E4 FB 78 */	mr r4, r31
/* 800F9110 000F5F10  7D 85 00 2E */	lwzx r12, r5, r0
/* 800F9114 000F5F14  7D 89 03 A6 */	mtctr r12
/* 800F9118 000F5F18  4E 80 04 21 */	bctrl
.L_800F911C:
/* 800F911C 000F5F1C  C0 1F 00 00 */	lfs f0, 0x0(r31)
/* 800F9120 000F5F20  FC 1F 00 00 */	fcmpu cr0, f31, f0
/* 800F9124 000F5F24  40 82 FF 70 */	bne .L_800F9094
.L_800F9128:
/* 800F9128 000F5F28  E3 E1 00 28 */	psq_l f31, 0x28(r1), 0, qr0
/* 800F912C 000F5F2C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800F9130 000F5F30  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 800F9134 000F5F34  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F9138 000F5F38  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F913C 000F5F3C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F9140 000F5F40  7C 08 03 A6 */	mtlr r0
/* 800F9144 000F5F44  38 21 00 30 */	addi r1, r1, 0x30
/* 800F9148 000F5F48  4E 80 00 20 */	blr
.endfn kar_gryakucommon_run_opcode_stream

# .text:0x968 | 0x800F914C | size: 0x18
.fn kar_gryakucommon_set_opcode_stream, global
/* 800F914C 000F5F4C  90 83 00 C4 */	stw r4, 0xc4(r3)
/* 800F9150 000F5F50  38 00 00 00 */	li r0, 0x0
/* 800F9154 000F5F54  C0 02 91 64 */	lfs f0, lbl_805DF864@sda21(r0)
/* 800F9158 000F5F58  90 03 00 C8 */	stw r0, 0xc8(r3)
/* 800F915C 000F5F5C  D0 03 00 BC */	stfs f0, 0xbc(r3)
/* 800F9160 000F5F60  4E 80 00 20 */	blr
.endfn kar_gryakucommon_set_opcode_stream

# .text:0x980 | 0x800F9164 | size: 0x24
.fn kar_gryakucommon_reset_opcode_cursor, global
/* 800F9164 000F5F64  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9168 000F5F68  7C 08 02 A6 */	mflr r0
/* 800F916C 000F5F6C  38 63 00 BC */	addi r3, r3, 0xbc
/* 800F9170 000F5F70  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9174 000F5F74  4B F6 FB F5 */	bl kar_lbcamera__near_80068d68
/* 800F9178 000F5F78  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F917C 000F5F7C  7C 08 03 A6 */	mtlr r0
/* 800F9180 000F5F80  38 21 00 10 */	addi r1, r1, 0x10
/* 800F9184 000F5F84  4E 80 00 20 */	blr
.endfn kar_gryakucommon_reset_opcode_cursor

# .text:0x9A4 | 0x800F9188 | size: 0x40
.fn kar_gryakucommon_enable_display_bbox_flag, global
/* 800F9188 000F5F88  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F918C 000F5F8C  7C 08 02 A6 */	mflr r0
/* 800F9190 000F5F90  38 80 00 00 */	li r4, 0x0
/* 800F9194 000F5F94  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9198 000F5F98  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F919C 000F5F9C  7C 7F 1B 78 */	mr r31, r3
/* 800F91A0 000F5FA0  4B FF D2 51 */	bl kar_gryakuanim_mark_display_bbox_dirty
/* 800F91A4 000F5FA4  88 1F 01 2C */	lbz r0, 0x12c(r31)
/* 800F91A8 000F5FA8  38 60 00 01 */	li r3, 0x1
/* 800F91AC 000F5FAC  50 60 36 72 */	rlwimi r0, r3, 6, 25, 25
/* 800F91B0 000F5FB0  98 1F 01 2C */	stb r0, 0x12c(r31)
/* 800F91B4 000F5FB4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F91B8 000F5FB8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F91BC 000F5FBC  7C 08 03 A6 */	mtlr r0
/* 800F91C0 000F5FC0  38 21 00 10 */	addi r1, r1, 0x10
/* 800F91C4 000F5FC4  4E 80 00 20 */	blr
.endfn kar_gryakucommon_enable_display_bbox_flag

# .text:0x9E4 | 0x800F91C8 | size: 0x20
.fn kar_gryakucommon_enable_scaled_display_bbox_flags, global
/* 800F91C8 000F5FC8  88 03 01 2C */	lbz r0, 0x12c(r3)
/* 800F91CC 000F5FCC  38 80 00 01 */	li r4, 0x1
/* 800F91D0 000F5FD0  50 80 3E 30 */	rlwimi r0, r4, 7, 24, 24
/* 800F91D4 000F5FD4  98 03 01 2C */	stb r0, 0x12c(r3)
/* 800F91D8 000F5FD8  88 03 01 2C */	lbz r0, 0x12c(r3)
/* 800F91DC 000F5FDC  50 80 36 72 */	rlwimi r0, r4, 6, 25, 25
/* 800F91E0 000F5FE0  98 03 01 2C */	stb r0, 0x12c(r3)
/* 800F91E4 000F5FE4  4E 80 00 20 */	blr
.endfn kar_gryakucommon_enable_scaled_display_bbox_flags

# .text:0xA04 | 0x800F91E8 | size: 0x14
.fn kar_gryakucommon_enable_flag10_variant_a, global
/* 800F91E8 000F5FE8  88 03 01 2C */	lbz r0, 0x12c(r3)
/* 800F91EC 000F5FEC  38 80 00 01 */	li r4, 0x1
/* 800F91F0 000F5FF0  50 80 26 F6 */	rlwimi r0, r4, 4, 27, 27
/* 800F91F4 000F5FF4  98 03 01 2C */	stb r0, 0x12c(r3)
/* 800F91F8 000F5FF8  4E 80 00 20 */	blr
.endfn kar_gryakucommon_enable_flag10_variant_a

# .text:0xA18 | 0x800F91FC | size: 0x14
.fn kar_gryakucommon_enable_flag10_variant_b, global
/* 800F91FC 000F5FFC  88 03 01 2C */	lbz r0, 0x12c(r3)
/* 800F9200 000F6000  38 80 00 01 */	li r4, 0x1
/* 800F9204 000F6004  50 80 26 F6 */	rlwimi r0, r4, 4, 27, 27
/* 800F9208 000F6008  98 03 01 2C */	stb r0, 0x12c(r3)
/* 800F920C 000F600C  4E 80 00 20 */	blr
.endfn kar_gryakucommon_enable_flag10_variant_b

# .text:0xA2C | 0x800F9210 | size: 0x48
.fn kar_gryakucommon_create_factory_variant0_bbox, global
/* 800F9210 000F6010  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9214 000F6014  7C 08 02 A6 */	mflr r0
/* 800F9218 000F6018  7C 83 23 78 */	mr r3, r4
/* 800F921C 000F601C  7C A4 2B 78 */	mr r4, r5
/* 800F9220 000F6020  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9224 000F6024  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F9228 000F6028  4B FF B8 F9 */	bl kar_gryaku_create_common_yaku_by_kind
/* 800F922C 000F602C  7C 7F 1B 78 */	mr r31, r3
/* 800F9230 000F6030  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F9234 000F6034  4B FF FF 55 */	bl kar_gryakucommon_enable_display_bbox_flag
/* 800F9238 000F6038  7F E3 FB 78 */	mr r3, r31
/* 800F923C 000F603C  48 00 00 65 */	bl kar_gryakucommon_init_factory_variant0_collision
/* 800F9240 000F6040  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F9244 000F6044  7F E3 FB 78 */	mr r3, r31
/* 800F9248 000F6048  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F924C 000F604C  7C 08 03 A6 */	mtlr r0
/* 800F9250 000F6050  38 21 00 10 */	addi r1, r1, 0x10
/* 800F9254 000F6054  4E 80 00 20 */	blr
.endfn kar_gryakucommon_create_factory_variant0_bbox

# .text:0xA74 | 0x800F9258 | size: 0x48
.fn kar_gryakucommon_create_factory_variant0_scaled_bbox, global
/* 800F9258 000F6058  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F925C 000F605C  7C 08 02 A6 */	mflr r0
/* 800F9260 000F6060  7C 83 23 78 */	mr r3, r4
/* 800F9264 000F6064  7C A4 2B 78 */	mr r4, r5
/* 800F9268 000F6068  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F926C 000F606C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F9270 000F6070  4B FF B8 B1 */	bl kar_gryaku_create_common_yaku_by_kind
/* 800F9274 000F6074  7C 7F 1B 78 */	mr r31, r3
/* 800F9278 000F6078  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F927C 000F607C  4B FF FF 4D */	bl kar_gryakucommon_enable_scaled_display_bbox_flags
/* 800F9280 000F6080  7F E3 FB 78 */	mr r3, r31
/* 800F9284 000F6084  48 00 00 1D */	bl kar_gryakucommon_init_factory_variant0_collision
/* 800F9288 000F6088  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F928C 000F608C  7F E3 FB 78 */	mr r3, r31
/* 800F9290 000F6090  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F9294 000F6094  7C 08 03 A6 */	mtlr r0
/* 800F9298 000F6098  38 21 00 10 */	addi r1, r1, 0x10
/* 800F929C 000F609C  4E 80 00 20 */	blr
.endfn kar_gryakucommon_create_factory_variant0_scaled_bbox

# .text:0xABC | 0x800F92A0 | size: 0xC4
.fn kar_gryakucommon_init_factory_variant0_collision, global
/* 800F92A0 000F60A0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F92A4 000F60A4  7C 08 02 A6 */	mflr r0
/* 800F92A8 000F60A8  38 A0 00 00 */	li r5, 0x0
/* 800F92AC 000F60AC  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F92B0 000F60B0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F92B4 000F60B4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F92B8 000F60B8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F92BC 000F60BC  7C 7D 1B 78 */	mr r29, r3
/* 800F92C0 000F60C0  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800F92C4 000F60C4  80 DF 00 08 */	lwz r6, 0x8(r31)
/* 800F92C8 000F60C8  38 7F 00 1C */	addi r3, r31, 0x1c
/* 800F92CC 000F60CC  80 9F 00 64 */	lwz r4, 0x64(r31)
/* 800F92D0 000F60D0  83 C6 00 00 */	lwz r30, 0x0(r6)
/* 800F92D4 000F60D4  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 800F92D8 000F60D8  54 00 18 38 */	slwi r0, r0, 3
/* 800F92DC 000F60DC  7C 84 00 2E */	lwzx r4, r4, r0
/* 800F92E0 000F60E0  4B FD E6 E1 */	bl kar_grcoll__800d79c0
/* 800F92E4 000F60E4  90 7F 01 30 */	stw r3, 0x130(r31)
/* 800F92E8 000F60E8  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 800F92EC 000F60EC  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 800F92F0 000F60F0  90 03 01 38 */	stw r0, 0x138(r3)
/* 800F92F4 000F60F4  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 800F92F8 000F60F8  2C 04 FF FF */	cmpwi r4, -0x1
/* 800F92FC 000F60FC  41 82 00 0C */	beq .L_800F9308
/* 800F9300 000F6100  7F E3 FB 78 */	mr r3, r31
/* 800F9304 000F6104  4B FF E2 B1 */	bl kar_gryakueffect_sync_indexed_anchor_jobj_matrix
.L_800F9308:
/* 800F9308 000F6108  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F930C 000F610C  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800F9310 000F6110  28 00 00 00 */	cmplwi r0, 0x0
/* 800F9314 000F6114  41 82 00 10 */	beq .L_800F9324
/* 800F9318 000F6118  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 800F931C 000F611C  7F A3 EB 78 */	mr r3, r29
/* 800F9320 000F6120  4B FF E6 11 */	bl kar_gryakuaudio_update_scaled_joint_fgm_track
.L_800F9324:
/* 800F9324 000F6124  C0 22 91 68 */	lfs f1, lbl_805DF868@sda21(r0)
/* 800F9328 000F6128  7F E3 FB 78 */	mr r3, r31
/* 800F932C 000F612C  C0 42 91 6C */	lfs f2, lbl_805DF86C@sda21(r0)
/* 800F9330 000F6130  38 80 00 00 */	li r4, 0x0
/* 800F9334 000F6134  FC 60 08 90 */	fmr f3, f1
/* 800F9338 000F6138  38 A0 00 00 */	li r5, 0x0
/* 800F933C 000F613C  38 C0 FF FF */	li r6, -0x1
/* 800F9340 000F6140  38 E0 00 00 */	li r7, 0x0
/* 800F9344 000F6144  4B FF C2 05 */	bl kar_gryaku_set_path_node_motion
/* 800F9348 000F6148  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F934C 000F614C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F9350 000F6150  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F9354 000F6154  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F9358 000F6158  7C 08 03 A6 */	mtlr r0
/* 800F935C 000F615C  38 21 00 20 */	addi r1, r1, 0x20
/* 800F9360 000F6160  4E 80 00 20 */	blr
.endfn kar_gryakucommon_init_factory_variant0_collision

# .text:0xB80 | 0x800F9364 | size: 0x48
.fn kar_gryakucommon_create_factory_variant1_bbox, global
/* 800F9364 000F6164  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9368 000F6168  7C 08 02 A6 */	mflr r0
/* 800F936C 000F616C  7C 83 23 78 */	mr r3, r4
/* 800F9370 000F6170  7C A4 2B 78 */	mr r4, r5
/* 800F9374 000F6174  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9378 000F6178  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F937C 000F617C  4B FF B7 A5 */	bl kar_gryaku_create_common_yaku_by_kind
/* 800F9380 000F6180  7C 7F 1B 78 */	mr r31, r3
/* 800F9384 000F6184  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F9388 000F6188  4B FF FE 01 */	bl kar_gryakucommon_enable_display_bbox_flag
/* 800F938C 000F618C  7F E3 FB 78 */	mr r3, r31
/* 800F9390 000F6190  48 00 00 65 */	bl kar_gryakucommon_init_factory_variant1_collision
/* 800F9394 000F6194  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F9398 000F6198  7F E3 FB 78 */	mr r3, r31
/* 800F939C 000F619C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F93A0 000F61A0  7C 08 03 A6 */	mtlr r0
/* 800F93A4 000F61A4  38 21 00 10 */	addi r1, r1, 0x10
/* 800F93A8 000F61A8  4E 80 00 20 */	blr
.endfn kar_gryakucommon_create_factory_variant1_bbox

# .text:0xBC8 | 0x800F93AC | size: 0x48
.fn kar_gryakucommon_create_factory_variant1_scaled_bbox, global
/* 800F93AC 000F61AC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F93B0 000F61B0  7C 08 02 A6 */	mflr r0
/* 800F93B4 000F61B4  7C 83 23 78 */	mr r3, r4
/* 800F93B8 000F61B8  7C A4 2B 78 */	mr r4, r5
/* 800F93BC 000F61BC  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F93C0 000F61C0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F93C4 000F61C4  4B FF B7 5D */	bl kar_gryaku_create_common_yaku_by_kind
/* 800F93C8 000F61C8  7C 7F 1B 78 */	mr r31, r3
/* 800F93CC 000F61CC  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F93D0 000F61D0  4B FF FD F9 */	bl kar_gryakucommon_enable_scaled_display_bbox_flags
/* 800F93D4 000F61D4  7F E3 FB 78 */	mr r3, r31
/* 800F93D8 000F61D8  48 00 00 1D */	bl kar_gryakucommon_init_factory_variant1_collision
/* 800F93DC 000F61DC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F93E0 000F61E0  7F E3 FB 78 */	mr r3, r31
/* 800F93E4 000F61E4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F93E8 000F61E8  7C 08 03 A6 */	mtlr r0
/* 800F93EC 000F61EC  38 21 00 10 */	addi r1, r1, 0x10
/* 800F93F0 000F61F0  4E 80 00 20 */	blr
.endfn kar_gryakucommon_create_factory_variant1_scaled_bbox

# .text:0xC10 | 0x800F93F4 | size: 0xC4
.fn kar_gryakucommon_init_factory_variant1_collision, global
/* 800F93F4 000F61F4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F93F8 000F61F8  7C 08 02 A6 */	mflr r0
/* 800F93FC 000F61FC  38 A0 00 00 */	li r5, 0x0
/* 800F9400 000F6200  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F9404 000F6204  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F9408 000F6208  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F940C 000F620C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F9410 000F6210  7C 7D 1B 78 */	mr r29, r3
/* 800F9414 000F6214  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800F9418 000F6218  80 DF 00 08 */	lwz r6, 0x8(r31)
/* 800F941C 000F621C  38 7F 00 1C */	addi r3, r31, 0x1c
/* 800F9420 000F6220  80 9F 00 64 */	lwz r4, 0x64(r31)
/* 800F9424 000F6224  83 C6 00 00 */	lwz r30, 0x0(r6)
/* 800F9428 000F6228  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 800F942C 000F622C  54 00 18 38 */	slwi r0, r0, 3
/* 800F9430 000F6230  7C 84 00 2E */	lwzx r4, r4, r0
/* 800F9434 000F6234  4B FD E5 8D */	bl kar_grcoll__800d79c0
/* 800F9438 000F6238  90 7F 01 30 */	stw r3, 0x130(r31)
/* 800F943C 000F623C  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 800F9440 000F6240  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 800F9444 000F6244  90 03 01 38 */	stw r0, 0x138(r3)
/* 800F9448 000F6248  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 800F944C 000F624C  2C 04 FF FF */	cmpwi r4, -0x1
/* 800F9450 000F6250  41 82 00 0C */	beq .L_800F945C
/* 800F9454 000F6254  7F E3 FB 78 */	mr r3, r31
/* 800F9458 000F6258  4B FF E1 5D */	bl kar_gryakueffect_sync_indexed_anchor_jobj_matrix
.L_800F945C:
/* 800F945C 000F625C  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F9460 000F6260  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800F9464 000F6264  28 00 00 00 */	cmplwi r0, 0x0
/* 800F9468 000F6268  41 82 00 10 */	beq .L_800F9478
/* 800F946C 000F626C  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 800F9470 000F6270  7F A3 EB 78 */	mr r3, r29
/* 800F9474 000F6274  4B FF E4 BD */	bl kar_gryakuaudio_update_scaled_joint_fgm_track
.L_800F9478:
/* 800F9478 000F6278  C0 22 91 70 */	lfs f1, lbl_805DF870@sda21(r0)
/* 800F947C 000F627C  7F E3 FB 78 */	mr r3, r31
/* 800F9480 000F6280  C0 42 91 74 */	lfs f2, lbl_805DF874@sda21(r0)
/* 800F9484 000F6284  38 80 00 00 */	li r4, 0x0
/* 800F9488 000F6288  FC 60 08 90 */	fmr f3, f1
/* 800F948C 000F628C  38 A0 00 00 */	li r5, 0x0
/* 800F9490 000F6290  38 C0 FF FF */	li r6, -0x1
/* 800F9494 000F6294  38 E0 00 00 */	li r7, 0x0
/* 800F9498 000F6298  4B FF C0 B1 */	bl kar_gryaku_set_path_node_motion
/* 800F949C 000F629C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F94A0 000F62A0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F94A4 000F62A4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F94A8 000F62A8  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F94AC 000F62AC  7C 08 03 A6 */	mtlr r0
/* 800F94B0 000F62B0  38 21 00 20 */	addi r1, r1, 0x20
/* 800F94B4 000F62B4  4E 80 00 20 */	blr
.endfn kar_gryakucommon_init_factory_variant1_collision

# .text:0xCD4 | 0x800F94B8 | size: 0x80
.fn kar_gryakucommon_update_variant1_anchor_audio, global
/* 800F94B8 000F62B8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F94BC 000F62BC  7C 08 02 A6 */	mflr r0
/* 800F94C0 000F62C0  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F94C4 000F62C4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F94C8 000F62C8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F94CC 000F62CC  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F94D0 000F62D0  7C 7D 1B 78 */	mr r29, r3
/* 800F94D4 000F62D4  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800F94D8 000F62D8  88 1F 01 2C */	lbz r0, 0x12c(r31)
/* 800F94DC 000F62DC  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F94E0 000F62E0  54 00 CF FF */	extrwi. r0, r0, 1, 24
/* 800F94E4 000F62E4  83 C3 00 00 */	lwz r30, 0x0(r3)
/* 800F94E8 000F62E8  41 82 00 18 */	beq .L_800F9500
/* 800F94EC 000F62EC  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 800F94F0 000F62F0  2C 04 FF FF */	cmpwi r4, -0x1
/* 800F94F4 000F62F4  41 82 00 0C */	beq .L_800F9500
/* 800F94F8 000F62F8  7F E3 FB 78 */	mr r3, r31
/* 800F94FC 000F62FC  4B FF E0 B9 */	bl kar_gryakueffect_sync_indexed_anchor_jobj_matrix
.L_800F9500:
/* 800F9500 000F6300  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F9504 000F6304  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800F9508 000F6308  28 00 00 00 */	cmplwi r0, 0x0
/* 800F950C 000F630C  41 82 00 10 */	beq .L_800F951C
/* 800F9510 000F6310  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 800F9514 000F6314  7F A3 EB 78 */	mr r3, r29
/* 800F9518 000F6318  4B FF E4 19 */	bl kar_gryakuaudio_update_scaled_joint_fgm_track
.L_800F951C:
/* 800F951C 000F631C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F9520 000F6320  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F9524 000F6324  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F9528 000F6328  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F952C 000F632C  7C 08 03 A6 */	mtlr r0
/* 800F9530 000F6330  38 21 00 20 */	addi r1, r1, 0x20
/* 800F9534 000F6334  4E 80 00 20 */	blr
.endfn kar_gryakucommon_update_variant1_anchor_audio

# .text:0xD54 | 0x800F9538 | size: 0x48
.fn kar_gryakucommon_create_factory_variant2_bbox, global
/* 800F9538 000F6338  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F953C 000F633C  7C 08 02 A6 */	mflr r0
/* 800F9540 000F6340  7C 83 23 78 */	mr r3, r4
/* 800F9544 000F6344  7C A4 2B 78 */	mr r4, r5
/* 800F9548 000F6348  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F954C 000F634C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F9550 000F6350  4B FF B5 D1 */	bl kar_gryaku_create_common_yaku_by_kind
/* 800F9554 000F6354  7C 7F 1B 78 */	mr r31, r3
/* 800F9558 000F6358  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F955C 000F635C  4B FF FC 2D */	bl kar_gryakucommon_enable_display_bbox_flag
/* 800F9560 000F6360  7F E3 FB 78 */	mr r3, r31
/* 800F9564 000F6364  48 00 00 65 */	bl kar_gryakucommon_init_factory_variant2_collision
/* 800F9568 000F6368  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F956C 000F636C  7F E3 FB 78 */	mr r3, r31
/* 800F9570 000F6370  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F9574 000F6374  7C 08 03 A6 */	mtlr r0
/* 800F9578 000F6378  38 21 00 10 */	addi r1, r1, 0x10
/* 800F957C 000F637C  4E 80 00 20 */	blr
.endfn kar_gryakucommon_create_factory_variant2_bbox

# .text:0xD9C | 0x800F9580 | size: 0x48
.fn kar_gryakucommon_create_factory_variant2_scaled_bbox, global
/* 800F9580 000F6380  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9584 000F6384  7C 08 02 A6 */	mflr r0
/* 800F9588 000F6388  7C 83 23 78 */	mr r3, r4
/* 800F958C 000F638C  7C A4 2B 78 */	mr r4, r5
/* 800F9590 000F6390  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9594 000F6394  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F9598 000F6398  4B FF B5 89 */	bl kar_gryaku_create_common_yaku_by_kind
/* 800F959C 000F639C  7C 7F 1B 78 */	mr r31, r3
/* 800F95A0 000F63A0  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F95A4 000F63A4  4B FF FC 25 */	bl kar_gryakucommon_enable_scaled_display_bbox_flags
/* 800F95A8 000F63A8  7F E3 FB 78 */	mr r3, r31
/* 800F95AC 000F63AC  48 00 00 1D */	bl kar_gryakucommon_init_factory_variant2_collision
/* 800F95B0 000F63B0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F95B4 000F63B4  7F E3 FB 78 */	mr r3, r31
/* 800F95B8 000F63B8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F95BC 000F63BC  7C 08 03 A6 */	mtlr r0
/* 800F95C0 000F63C0  38 21 00 10 */	addi r1, r1, 0x10
/* 800F95C4 000F63C4  4E 80 00 20 */	blr
.endfn kar_gryakucommon_create_factory_variant2_scaled_bbox

# .text:0xDE4 | 0x800F95C8 | size: 0xC4
.fn kar_gryakucommon_init_factory_variant2_collision, global
/* 800F95C8 000F63C8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F95CC 000F63CC  7C 08 02 A6 */	mflr r0
/* 800F95D0 000F63D0  38 A0 00 00 */	li r5, 0x0
/* 800F95D4 000F63D4  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F95D8 000F63D8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F95DC 000F63DC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F95E0 000F63E0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F95E4 000F63E4  7C 7D 1B 78 */	mr r29, r3
/* 800F95E8 000F63E8  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800F95EC 000F63EC  80 DF 00 08 */	lwz r6, 0x8(r31)
/* 800F95F0 000F63F0  38 7F 00 1C */	addi r3, r31, 0x1c
/* 800F95F4 000F63F4  80 9F 00 64 */	lwz r4, 0x64(r31)
/* 800F95F8 000F63F8  83 C6 00 00 */	lwz r30, 0x0(r6)
/* 800F95FC 000F63FC  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 800F9600 000F6400  54 00 18 38 */	slwi r0, r0, 3
/* 800F9604 000F6404  7C 84 00 2E */	lwzx r4, r4, r0
/* 800F9608 000F6408  4B FD E3 B9 */	bl kar_grcoll__800d79c0
/* 800F960C 000F640C  90 7F 01 30 */	stw r3, 0x130(r31)
/* 800F9610 000F6410  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 800F9614 000F6414  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 800F9618 000F6418  90 03 01 38 */	stw r0, 0x138(r3)
/* 800F961C 000F641C  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 800F9620 000F6420  2C 04 FF FF */	cmpwi r4, -0x1
/* 800F9624 000F6424  41 82 00 0C */	beq .L_800F9630
/* 800F9628 000F6428  7F E3 FB 78 */	mr r3, r31
/* 800F962C 000F642C  4B FF DF 89 */	bl kar_gryakueffect_sync_indexed_anchor_jobj_matrix
.L_800F9630:
/* 800F9630 000F6430  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F9634 000F6434  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800F9638 000F6438  28 00 00 00 */	cmplwi r0, 0x0
/* 800F963C 000F643C  41 82 00 10 */	beq .L_800F964C
/* 800F9640 000F6440  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 800F9644 000F6444  7F A3 EB 78 */	mr r3, r29
/* 800F9648 000F6448  4B FF E2 E9 */	bl kar_gryakuaudio_update_scaled_joint_fgm_track
.L_800F964C:
/* 800F964C 000F644C  C0 22 91 78 */	lfs f1, lbl_805DF878@sda21(r0)
/* 800F9650 000F6450  7F E3 FB 78 */	mr r3, r31
/* 800F9654 000F6454  C0 42 91 7C */	lfs f2, lbl_805DF87C@sda21(r0)
/* 800F9658 000F6458  38 80 00 00 */	li r4, 0x0
/* 800F965C 000F645C  FC 60 08 90 */	fmr f3, f1
/* 800F9660 000F6460  38 A0 00 00 */	li r5, 0x0
/* 800F9664 000F6464  38 C0 FF FF */	li r6, -0x1
/* 800F9668 000F6468  38 E0 00 00 */	li r7, 0x0
/* 800F966C 000F646C  4B FF BE DD */	bl kar_gryaku_set_path_node_motion
/* 800F9670 000F6470  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F9674 000F6474  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F9678 000F6478  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F967C 000F647C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F9680 000F6480  7C 08 03 A6 */	mtlr r0
/* 800F9684 000F6484  38 21 00 20 */	addi r1, r1, 0x20
/* 800F9688 000F6488  4E 80 00 20 */	blr
.endfn kar_gryakucommon_init_factory_variant2_collision

# .text:0xEA8 | 0x800F968C | size: 0x80
.fn kar_gryakucommon_update_variant2_anchor_audio, global
/* 800F968C 000F648C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F9690 000F6490  7C 08 02 A6 */	mflr r0
/* 800F9694 000F6494  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F9698 000F6498  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F969C 000F649C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F96A0 000F64A0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F96A4 000F64A4  7C 7D 1B 78 */	mr r29, r3
/* 800F96A8 000F64A8  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800F96AC 000F64AC  88 1F 01 2C */	lbz r0, 0x12c(r31)
/* 800F96B0 000F64B0  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F96B4 000F64B4  54 00 CF FF */	extrwi. r0, r0, 1, 24
/* 800F96B8 000F64B8  83 C3 00 00 */	lwz r30, 0x0(r3)
/* 800F96BC 000F64BC  41 82 00 18 */	beq .L_800F96D4
/* 800F96C0 000F64C0  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 800F96C4 000F64C4  2C 04 FF FF */	cmpwi r4, -0x1
/* 800F96C8 000F64C8  41 82 00 0C */	beq .L_800F96D4
/* 800F96CC 000F64CC  7F E3 FB 78 */	mr r3, r31
/* 800F96D0 000F64D0  4B FF DE E5 */	bl kar_gryakueffect_sync_indexed_anchor_jobj_matrix
.L_800F96D4:
/* 800F96D4 000F64D4  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F96D8 000F64D8  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800F96DC 000F64DC  28 00 00 00 */	cmplwi r0, 0x0
/* 800F96E0 000F64E0  41 82 00 10 */	beq .L_800F96F0
/* 800F96E4 000F64E4  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 800F96E8 000F64E8  7F A3 EB 78 */	mr r3, r29
/* 800F96EC 000F64EC  4B FF E2 45 */	bl kar_gryakuaudio_update_scaled_joint_fgm_track
.L_800F96F0:
/* 800F96F0 000F64F0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F96F4 000F64F4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F96F8 000F64F8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F96FC 000F64FC  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F9700 000F6500  7C 08 03 A6 */	mtlr r0
/* 800F9704 000F6504  38 21 00 20 */	addi r1, r1, 0x20
/* 800F9708 000F6508  4E 80 00 20 */	blr
.endfn kar_gryakucommon_update_variant2_anchor_audio

# .text:0xF28 | 0x800F970C | size: 0x48
.fn kar_gryakucommon_create_factory_variant3_bbox, global
/* 800F970C 000F650C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9710 000F6510  7C 08 02 A6 */	mflr r0
/* 800F9714 000F6514  7C 83 23 78 */	mr r3, r4
/* 800F9718 000F6518  7C A4 2B 78 */	mr r4, r5
/* 800F971C 000F651C  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9720 000F6520  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F9724 000F6524  4B FF B3 FD */	bl kar_gryaku_create_common_yaku_by_kind
/* 800F9728 000F6528  7C 7F 1B 78 */	mr r31, r3
/* 800F972C 000F652C  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F9730 000F6530  4B FF FA 59 */	bl kar_gryakucommon_enable_display_bbox_flag
/* 800F9734 000F6534  7F E3 FB 78 */	mr r3, r31
/* 800F9738 000F6538  48 00 00 65 */	bl kar_gryakucommon_init_factory_variant3_collision
/* 800F973C 000F653C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F9740 000F6540  7F E3 FB 78 */	mr r3, r31
/* 800F9744 000F6544  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F9748 000F6548  7C 08 03 A6 */	mtlr r0
/* 800F974C 000F654C  38 21 00 10 */	addi r1, r1, 0x10
/* 800F9750 000F6550  4E 80 00 20 */	blr
.endfn kar_gryakucommon_create_factory_variant3_bbox

# .text:0xF70 | 0x800F9754 | size: 0x48
.fn kar_gryakucommon_create_factory_variant3_scaled_bbox, global
/* 800F9754 000F6554  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9758 000F6558  7C 08 02 A6 */	mflr r0
/* 800F975C 000F655C  7C 83 23 78 */	mr r3, r4
/* 800F9760 000F6560  7C A4 2B 78 */	mr r4, r5
/* 800F9764 000F6564  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9768 000F6568  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F976C 000F656C  4B FF B3 B5 */	bl kar_gryaku_create_common_yaku_by_kind
/* 800F9770 000F6570  7C 7F 1B 78 */	mr r31, r3
/* 800F9774 000F6574  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F9778 000F6578  4B FF FA 51 */	bl kar_gryakucommon_enable_scaled_display_bbox_flags
/* 800F977C 000F657C  7F E3 FB 78 */	mr r3, r31
/* 800F9780 000F6580  48 00 00 1D */	bl kar_gryakucommon_init_factory_variant3_collision
/* 800F9784 000F6584  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F9788 000F6588  7F E3 FB 78 */	mr r3, r31
/* 800F978C 000F658C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F9790 000F6590  7C 08 03 A6 */	mtlr r0
/* 800F9794 000F6594  38 21 00 10 */	addi r1, r1, 0x10
/* 800F9798 000F6598  4E 80 00 20 */	blr
.endfn kar_gryakucommon_create_factory_variant3_scaled_bbox

# .text:0xFB8 | 0x800F979C | size: 0xC4
.fn kar_gryakucommon_init_factory_variant3_collision, global
/* 800F979C 000F659C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F97A0 000F65A0  7C 08 02 A6 */	mflr r0
/* 800F97A4 000F65A4  38 A0 00 00 */	li r5, 0x0
/* 800F97A8 000F65A8  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F97AC 000F65AC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F97B0 000F65B0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F97B4 000F65B4  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F97B8 000F65B8  7C 7D 1B 78 */	mr r29, r3
/* 800F97BC 000F65BC  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800F97C0 000F65C0  80 DF 00 08 */	lwz r6, 0x8(r31)
/* 800F97C4 000F65C4  38 7F 00 1C */	addi r3, r31, 0x1c
/* 800F97C8 000F65C8  80 9F 00 64 */	lwz r4, 0x64(r31)
/* 800F97CC 000F65CC  83 C6 00 00 */	lwz r30, 0x0(r6)
/* 800F97D0 000F65D0  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 800F97D4 000F65D4  54 00 18 38 */	slwi r0, r0, 3
/* 800F97D8 000F65D8  7C 84 00 2E */	lwzx r4, r4, r0
/* 800F97DC 000F65DC  4B FD E1 E5 */	bl kar_grcoll__800d79c0
/* 800F97E0 000F65E0  90 7F 01 30 */	stw r3, 0x130(r31)
/* 800F97E4 000F65E4  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 800F97E8 000F65E8  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 800F97EC 000F65EC  90 03 01 38 */	stw r0, 0x138(r3)
/* 800F97F0 000F65F0  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 800F97F4 000F65F4  2C 04 FF FF */	cmpwi r4, -0x1
/* 800F97F8 000F65F8  41 82 00 0C */	beq .L_800F9804
/* 800F97FC 000F65FC  7F E3 FB 78 */	mr r3, r31
/* 800F9800 000F6600  4B FF DD B5 */	bl kar_gryakueffect_sync_indexed_anchor_jobj_matrix
.L_800F9804:
/* 800F9804 000F6604  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F9808 000F6608  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800F980C 000F660C  28 00 00 00 */	cmplwi r0, 0x0
/* 800F9810 000F6610  41 82 00 10 */	beq .L_800F9820
/* 800F9814 000F6614  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 800F9818 000F6618  7F A3 EB 78 */	mr r3, r29
/* 800F981C 000F661C  4B FF E1 15 */	bl kar_gryakuaudio_update_scaled_joint_fgm_track
.L_800F9820:
/* 800F9820 000F6620  C0 22 91 80 */	lfs f1, lbl_805DF880@sda21(r0)
/* 800F9824 000F6624  7F E3 FB 78 */	mr r3, r31
/* 800F9828 000F6628  C0 42 91 84 */	lfs f2, lbl_805DF884@sda21(r0)
/* 800F982C 000F662C  38 80 00 00 */	li r4, 0x0
/* 800F9830 000F6630  FC 60 08 90 */	fmr f3, f1
/* 800F9834 000F6634  38 A0 00 00 */	li r5, 0x0
/* 800F9838 000F6638  38 C0 FF FF */	li r6, -0x1
/* 800F983C 000F663C  38 E0 00 00 */	li r7, 0x0
/* 800F9840 000F6640  4B FF BD 09 */	bl kar_gryaku_set_path_node_motion
/* 800F9844 000F6644  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F9848 000F6648  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F984C 000F664C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F9850 000F6650  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F9854 000F6654  7C 08 03 A6 */	mtlr r0
/* 800F9858 000F6658  38 21 00 20 */	addi r1, r1, 0x20
/* 800F985C 000F665C  4E 80 00 20 */	blr
.endfn kar_gryakucommon_init_factory_variant3_collision

# .text:0x107C | 0x800F9860 | size: 0x80
.fn kar_gryakucommon_update_variant3_anchor_audio, global
/* 800F9860 000F6660  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F9864 000F6664  7C 08 02 A6 */	mflr r0
/* 800F9868 000F6668  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F986C 000F666C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F9870 000F6670  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F9874 000F6674  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F9878 000F6678  7C 7D 1B 78 */	mr r29, r3
/* 800F987C 000F667C  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800F9880 000F6680  88 1F 01 2C */	lbz r0, 0x12c(r31)
/* 800F9884 000F6684  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F9888 000F6688  54 00 CF FF */	extrwi. r0, r0, 1, 24
/* 800F988C 000F668C  83 C3 00 00 */	lwz r30, 0x0(r3)
/* 800F9890 000F6690  41 82 00 18 */	beq .L_800F98A8
/* 800F9894 000F6694  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 800F9898 000F6698  2C 04 FF FF */	cmpwi r4, -0x1
/* 800F989C 000F669C  41 82 00 0C */	beq .L_800F98A8
/* 800F98A0 000F66A0  7F E3 FB 78 */	mr r3, r31
/* 800F98A4 000F66A4  4B FF DD 11 */	bl kar_gryakueffect_sync_indexed_anchor_jobj_matrix
.L_800F98A8:
/* 800F98A8 000F66A8  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F98AC 000F66AC  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800F98B0 000F66B0  28 00 00 00 */	cmplwi r0, 0x0
/* 800F98B4 000F66B4  41 82 00 10 */	beq .L_800F98C4
/* 800F98B8 000F66B8  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 800F98BC 000F66BC  7F A3 EB 78 */	mr r3, r29
/* 800F98C0 000F66C0  4B FF E0 71 */	bl kar_gryakuaudio_update_scaled_joint_fgm_track
.L_800F98C4:
/* 800F98C4 000F66C4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F98C8 000F66C8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F98CC 000F66CC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F98D0 000F66D0  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F98D4 000F66D4  7C 08 03 A6 */	mtlr r0
/* 800F98D8 000F66D8  38 21 00 20 */	addi r1, r1, 0x20
/* 800F98DC 000F66DC  4E 80 00 20 */	blr
.endfn kar_gryakucommon_update_variant3_anchor_audio

# .text:0x10FC | 0x800F98E0 | size: 0x48
.fn kar_gryakucommon_create_factory_variant4_bbox, global
/* 800F98E0 000F66E0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F98E4 000F66E4  7C 08 02 A6 */	mflr r0
/* 800F98E8 000F66E8  7C 83 23 78 */	mr r3, r4
/* 800F98EC 000F66EC  7C A4 2B 78 */	mr r4, r5
/* 800F98F0 000F66F0  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F98F4 000F66F4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F98F8 000F66F8  4B FF B2 29 */	bl kar_gryaku_create_common_yaku_by_kind
/* 800F98FC 000F66FC  7C 7F 1B 78 */	mr r31, r3
/* 800F9900 000F6700  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F9904 000F6704  4B FF F8 85 */	bl kar_gryakucommon_enable_display_bbox_flag
/* 800F9908 000F6708  7F E3 FB 78 */	mr r3, r31
/* 800F990C 000F670C  48 00 00 65 */	bl kar_gryakucommon_init_factory_variant4_colltype10
/* 800F9910 000F6710  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F9914 000F6714  7F E3 FB 78 */	mr r3, r31
/* 800F9918 000F6718  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F991C 000F671C  7C 08 03 A6 */	mtlr r0
/* 800F9920 000F6720  38 21 00 10 */	addi r1, r1, 0x10
/* 800F9924 000F6724  4E 80 00 20 */	blr
.endfn kar_gryakucommon_create_factory_variant4_bbox

# .text:0x1144 | 0x800F9928 | size: 0x48
.fn kar_gryakucommon_create_factory_variant4_scaled_bbox, global
/* 800F9928 000F6728  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F992C 000F672C  7C 08 02 A6 */	mflr r0
/* 800F9930 000F6730  7C 83 23 78 */	mr r3, r4
/* 800F9934 000F6734  7C A4 2B 78 */	mr r4, r5
/* 800F9938 000F6738  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F993C 000F673C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F9940 000F6740  4B FF B1 E1 */	bl kar_gryaku_create_common_yaku_by_kind
/* 800F9944 000F6744  7C 7F 1B 78 */	mr r31, r3
/* 800F9948 000F6748  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F994C 000F674C  4B FF F8 7D */	bl kar_gryakucommon_enable_scaled_display_bbox_flags
/* 800F9950 000F6750  7F E3 FB 78 */	mr r3, r31
/* 800F9954 000F6754  48 00 00 1D */	bl kar_gryakucommon_init_factory_variant4_colltype10
/* 800F9958 000F6758  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F995C 000F675C  7F E3 FB 78 */	mr r3, r31
/* 800F9960 000F6760  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F9964 000F6764  7C 08 03 A6 */	mtlr r0
/* 800F9968 000F6768  38 21 00 10 */	addi r1, r1, 0x10
/* 800F996C 000F676C  4E 80 00 20 */	blr
.endfn kar_gryakucommon_create_factory_variant4_scaled_bbox

# .text:0x118C | 0x800F9970 | size: 0xB4
.fn kar_gryakucommon_init_factory_variant4_colltype10, global
/* 800F9970 000F6770  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F9974 000F6774  7C 08 02 A6 */	mflr r0
/* 800F9978 000F6778  38 A0 00 0A */	li r5, 0xa
/* 800F997C 000F677C  38 C0 00 00 */	li r6, 0x0
/* 800F9980 000F6780  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F9984 000F6784  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F9988 000F6788  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F998C 000F678C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F9990 000F6790  7C 7D 1B 78 */	mr r29, r3
/* 800F9994 000F6794  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800F9998 000F6798  80 FF 00 08 */	lwz r7, 0x8(r31)
/* 800F999C 000F679C  38 7F 00 1C */	addi r3, r31, 0x1c
/* 800F99A0 000F67A0  80 9F 00 64 */	lwz r4, 0x64(r31)
/* 800F99A4 000F67A4  83 C7 00 00 */	lwz r30, 0x0(r7)
/* 800F99A8 000F67A8  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 800F99AC 000F67AC  54 00 18 38 */	slwi r0, r0, 3
/* 800F99B0 000F67B0  7C 84 00 2E */	lwzx r4, r4, r0
/* 800F99B4 000F67B4  4B FD E0 8D */	bl kar_grcoll__800d7a40
/* 800F99B8 000F67B8  90 7F 01 30 */	stw r3, 0x130(r31)
/* 800F99BC 000F67BC  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 800F99C0 000F67C0  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 800F99C4 000F67C4  90 03 01 38 */	stw r0, 0x138(r3)
/* 800F99C8 000F67C8  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F99CC 000F67CC  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800F99D0 000F67D0  28 00 00 00 */	cmplwi r0, 0x0
/* 800F99D4 000F67D4  41 82 00 10 */	beq .L_800F99E4
/* 800F99D8 000F67D8  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 800F99DC 000F67DC  7F A3 EB 78 */	mr r3, r29
/* 800F99E0 000F67E0  4B FF DF 51 */	bl kar_gryakuaudio_update_scaled_joint_fgm_track
.L_800F99E4:
/* 800F99E4 000F67E4  C0 22 91 88 */	lfs f1, lbl_805DF888@sda21(r0)
/* 800F99E8 000F67E8  7F E3 FB 78 */	mr r3, r31
/* 800F99EC 000F67EC  C0 42 91 8C */	lfs f2, lbl_805DF88C@sda21(r0)
/* 800F99F0 000F67F0  38 80 00 00 */	li r4, 0x0
/* 800F99F4 000F67F4  FC 60 08 90 */	fmr f3, f1
/* 800F99F8 000F67F8  38 A0 00 00 */	li r5, 0x0
/* 800F99FC 000F67FC  38 C0 FF FF */	li r6, -0x1
/* 800F9A00 000F6800  38 E0 00 00 */	li r7, 0x0
/* 800F9A04 000F6804  4B FF BB 45 */	bl kar_gryaku_set_path_node_motion
/* 800F9A08 000F6808  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F9A0C 000F680C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F9A10 000F6810  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F9A14 000F6814  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F9A18 000F6818  7C 08 03 A6 */	mtlr r0
/* 800F9A1C 000F681C  38 21 00 20 */	addi r1, r1, 0x20
/* 800F9A20 000F6820  4E 80 00 20 */	blr
.endfn kar_gryakucommon_init_factory_variant4_colltype10

# .text:0x1240 | 0x800F9A24 | size: 0x3C
.fn kar_gryakucommon_update_variant4_audio_only, global
/* 800F9A24 000F6824  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9A28 000F6828  7C 08 02 A6 */	mflr r0
/* 800F9A2C 000F682C  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9A30 000F6830  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 800F9A34 000F6834  80 84 00 08 */	lwz r4, 0x8(r4)
/* 800F9A38 000F6838  80 04 00 14 */	lwz r0, 0x14(r4)
/* 800F9A3C 000F683C  80 84 00 00 */	lwz r4, 0x0(r4)
/* 800F9A40 000F6840  28 00 00 00 */	cmplwi r0, 0x0
/* 800F9A44 000F6844  41 82 00 0C */	beq .L_800F9A50
/* 800F9A48 000F6848  80 84 00 00 */	lwz r4, 0x0(r4)
/* 800F9A4C 000F684C  4B FF DE E5 */	bl kar_gryakuaudio_update_scaled_joint_fgm_track
.L_800F9A50:
/* 800F9A50 000F6850  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F9A54 000F6854  7C 08 03 A6 */	mtlr r0
/* 800F9A58 000F6858  38 21 00 10 */	addi r1, r1, 0x10
/* 800F9A5C 000F685C  4E 80 00 20 */	blr
.endfn kar_gryakucommon_update_variant4_audio_only

# .text:0x127C | 0x800F9A60 | size: 0x48
.fn kar_gryakucommon_create_factory_variant5_bbox, global
/* 800F9A60 000F6860  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9A64 000F6864  7C 08 02 A6 */	mflr r0
/* 800F9A68 000F6868  7C 83 23 78 */	mr r3, r4
/* 800F9A6C 000F686C  7C A4 2B 78 */	mr r4, r5
/* 800F9A70 000F6870  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9A74 000F6874  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F9A78 000F6878  4B FF B0 A9 */	bl kar_gryaku_create_common_yaku_by_kind
/* 800F9A7C 000F687C  7C 7F 1B 78 */	mr r31, r3
/* 800F9A80 000F6880  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F9A84 000F6884  4B FF F7 05 */	bl kar_gryakucommon_enable_display_bbox_flag
/* 800F9A88 000F6888  7F E3 FB 78 */	mr r3, r31
/* 800F9A8C 000F688C  48 00 00 65 */	bl kar_gryakucommon_init_factory_variant5_colltype10
/* 800F9A90 000F6890  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F9A94 000F6894  7F E3 FB 78 */	mr r3, r31
/* 800F9A98 000F6898  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F9A9C 000F689C  7C 08 03 A6 */	mtlr r0
/* 800F9AA0 000F68A0  38 21 00 10 */	addi r1, r1, 0x10
/* 800F9AA4 000F68A4  4E 80 00 20 */	blr
.endfn kar_gryakucommon_create_factory_variant5_bbox

# .text:0x12C4 | 0x800F9AA8 | size: 0x48
.fn kar_gryakucommon_create_factory_variant5_scaled_bbox, global
/* 800F9AA8 000F68A8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9AAC 000F68AC  7C 08 02 A6 */	mflr r0
/* 800F9AB0 000F68B0  7C 83 23 78 */	mr r3, r4
/* 800F9AB4 000F68B4  7C A4 2B 78 */	mr r4, r5
/* 800F9AB8 000F68B8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9ABC 000F68BC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F9AC0 000F68C0  4B FF B0 61 */	bl kar_gryaku_create_common_yaku_by_kind
/* 800F9AC4 000F68C4  7C 7F 1B 78 */	mr r31, r3
/* 800F9AC8 000F68C8  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F9ACC 000F68CC  4B FF F6 FD */	bl kar_gryakucommon_enable_scaled_display_bbox_flags
/* 800F9AD0 000F68D0  7F E3 FB 78 */	mr r3, r31
/* 800F9AD4 000F68D4  48 00 00 1D */	bl kar_gryakucommon_init_factory_variant5_colltype10
/* 800F9AD8 000F68D8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F9ADC 000F68DC  7F E3 FB 78 */	mr r3, r31
/* 800F9AE0 000F68E0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F9AE4 000F68E4  7C 08 03 A6 */	mtlr r0
/* 800F9AE8 000F68E8  38 21 00 10 */	addi r1, r1, 0x10
/* 800F9AEC 000F68EC  4E 80 00 20 */	blr
.endfn kar_gryakucommon_create_factory_variant5_scaled_bbox

# .text:0x130C | 0x800F9AF0 | size: 0xB4
.fn kar_gryakucommon_init_factory_variant5_colltype10, global
/* 800F9AF0 000F68F0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F9AF4 000F68F4  7C 08 02 A6 */	mflr r0
/* 800F9AF8 000F68F8  38 A0 00 0A */	li r5, 0xa
/* 800F9AFC 000F68FC  38 C0 00 00 */	li r6, 0x0
/* 800F9B00 000F6900  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F9B04 000F6904  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F9B08 000F6908  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F9B0C 000F690C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F9B10 000F6910  7C 7D 1B 78 */	mr r29, r3
/* 800F9B14 000F6914  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800F9B18 000F6918  80 FF 00 08 */	lwz r7, 0x8(r31)
/* 800F9B1C 000F691C  38 7F 00 1C */	addi r3, r31, 0x1c
/* 800F9B20 000F6920  80 9F 00 64 */	lwz r4, 0x64(r31)
/* 800F9B24 000F6924  83 C7 00 00 */	lwz r30, 0x0(r7)
/* 800F9B28 000F6928  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 800F9B2C 000F692C  54 00 18 38 */	slwi r0, r0, 3
/* 800F9B30 000F6930  7C 84 00 2E */	lwzx r4, r4, r0
/* 800F9B34 000F6934  4B FD DF 0D */	bl kar_grcoll__800d7a40
/* 800F9B38 000F6938  90 7F 01 30 */	stw r3, 0x130(r31)
/* 800F9B3C 000F693C  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 800F9B40 000F6940  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 800F9B44 000F6944  90 03 01 38 */	stw r0, 0x138(r3)
/* 800F9B48 000F6948  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F9B4C 000F694C  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800F9B50 000F6950  28 00 00 00 */	cmplwi r0, 0x0
/* 800F9B54 000F6954  41 82 00 10 */	beq .L_800F9B64
/* 800F9B58 000F6958  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 800F9B5C 000F695C  7F A3 EB 78 */	mr r3, r29
/* 800F9B60 000F6960  4B FF DD D1 */	bl kar_gryakuaudio_update_scaled_joint_fgm_track
.L_800F9B64:
/* 800F9B64 000F6964  C0 22 91 90 */	lfs f1, lbl_805DF890@sda21(r0)
/* 800F9B68 000F6968  7F E3 FB 78 */	mr r3, r31
/* 800F9B6C 000F696C  C0 42 91 94 */	lfs f2, lbl_805DF894@sda21(r0)
/* 800F9B70 000F6970  38 80 00 00 */	li r4, 0x0
/* 800F9B74 000F6974  FC 60 08 90 */	fmr f3, f1
/* 800F9B78 000F6978  38 A0 00 00 */	li r5, 0x0
/* 800F9B7C 000F697C  38 C0 FF FF */	li r6, -0x1
/* 800F9B80 000F6980  38 E0 00 00 */	li r7, 0x0
/* 800F9B84 000F6984  4B FF B9 C5 */	bl kar_gryaku_set_path_node_motion
/* 800F9B88 000F6988  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F9B8C 000F698C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F9B90 000F6990  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F9B94 000F6994  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F9B98 000F6998  7C 08 03 A6 */	mtlr r0
/* 800F9B9C 000F699C  38 21 00 20 */	addi r1, r1, 0x20
/* 800F9BA0 000F69A0  4E 80 00 20 */	blr
.endfn kar_gryakucommon_init_factory_variant5_colltype10

# .text:0x13C0 | 0x800F9BA4 | size: 0x3C
.fn kar_gryakucommon_update_variant5_audio_only, global
/* 800F9BA4 000F69A4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9BA8 000F69A8  7C 08 02 A6 */	mflr r0
/* 800F9BAC 000F69AC  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9BB0 000F69B0  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 800F9BB4 000F69B4  80 84 00 08 */	lwz r4, 0x8(r4)
/* 800F9BB8 000F69B8  80 04 00 14 */	lwz r0, 0x14(r4)
/* 800F9BBC 000F69BC  80 84 00 00 */	lwz r4, 0x0(r4)
/* 800F9BC0 000F69C0  28 00 00 00 */	cmplwi r0, 0x0
/* 800F9BC4 000F69C4  41 82 00 0C */	beq .L_800F9BD0
/* 800F9BC8 000F69C8  80 84 00 00 */	lwz r4, 0x0(r4)
/* 800F9BCC 000F69CC  4B FF DD 65 */	bl kar_gryakuaudio_update_scaled_joint_fgm_track
.L_800F9BD0:
/* 800F9BD0 000F69D0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F9BD4 000F69D4  7C 08 03 A6 */	mtlr r0
/* 800F9BD8 000F69D8  38 21 00 10 */	addi r1, r1, 0x10
/* 800F9BDC 000F69DC  4E 80 00 20 */	blr
.endfn kar_gryakucommon_update_variant5_audio_only

# .text:0x13FC | 0x800F9BE0 | size: 0x48
.fn kar_gryakucommon_create_factory_variant6_bbox, global
/* 800F9BE0 000F69E0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9BE4 000F69E4  7C 08 02 A6 */	mflr r0
/* 800F9BE8 000F69E8  7C 83 23 78 */	mr r3, r4
/* 800F9BEC 000F69EC  7C A4 2B 78 */	mr r4, r5
/* 800F9BF0 000F69F0  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9BF4 000F69F4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F9BF8 000F69F8  4B FF AF 29 */	bl kar_gryaku_create_common_yaku_by_kind
/* 800F9BFC 000F69FC  7C 7F 1B 78 */	mr r31, r3
/* 800F9C00 000F6A00  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F9C04 000F6A04  4B FF F5 85 */	bl kar_gryakucommon_enable_display_bbox_flag
/* 800F9C08 000F6A08  7F E3 FB 78 */	mr r3, r31
/* 800F9C0C 000F6A0C  48 00 00 65 */	bl kar_gryakucommon_init_factory_variant6_path_only
/* 800F9C10 000F6A10  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F9C14 000F6A14  7F E3 FB 78 */	mr r3, r31
/* 800F9C18 000F6A18  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F9C1C 000F6A1C  7C 08 03 A6 */	mtlr r0
/* 800F9C20 000F6A20  38 21 00 10 */	addi r1, r1, 0x10
/* 800F9C24 000F6A24  4E 80 00 20 */	blr
.endfn kar_gryakucommon_create_factory_variant6_bbox

# .text:0x1444 | 0x800F9C28 | size: 0x48
.fn kar_gryakucommon_create_factory_variant6_scaled_bbox, global
/* 800F9C28 000F6A28  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9C2C 000F6A2C  7C 08 02 A6 */	mflr r0
/* 800F9C30 000F6A30  7C 83 23 78 */	mr r3, r4
/* 800F9C34 000F6A34  7C A4 2B 78 */	mr r4, r5
/* 800F9C38 000F6A38  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9C3C 000F6A3C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F9C40 000F6A40  4B FF AE E1 */	bl kar_gryaku_create_common_yaku_by_kind
/* 800F9C44 000F6A44  7C 7F 1B 78 */	mr r31, r3
/* 800F9C48 000F6A48  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F9C4C 000F6A4C  4B FF F5 7D */	bl kar_gryakucommon_enable_scaled_display_bbox_flags
/* 800F9C50 000F6A50  7F E3 FB 78 */	mr r3, r31
/* 800F9C54 000F6A54  48 00 00 1D */	bl kar_gryakucommon_init_factory_variant6_path_only
/* 800F9C58 000F6A58  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F9C5C 000F6A5C  7F E3 FB 78 */	mr r3, r31
/* 800F9C60 000F6A60  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F9C64 000F6A64  7C 08 03 A6 */	mtlr r0
/* 800F9C68 000F6A68  38 21 00 10 */	addi r1, r1, 0x10
/* 800F9C6C 000F6A6C  4E 80 00 20 */	blr
.endfn kar_gryakucommon_create_factory_variant6_scaled_bbox

# .text:0x148C | 0x800F9C70 | size: 0x40
.fn kar_gryakucommon_init_factory_variant6_path_only, global
/* 800F9C70 000F6A70  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9C74 000F6A74  7C 08 02 A6 */	mflr r0
/* 800F9C78 000F6A78  C0 22 91 98 */	lfs f1, lbl_805DF898@sda21(r0)
/* 800F9C7C 000F6A7C  38 80 00 00 */	li r4, 0x0
/* 800F9C80 000F6A80  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9C84 000F6A84  38 A0 00 00 */	li r5, 0x0
/* 800F9C88 000F6A88  FC 60 08 90 */	fmr f3, f1
/* 800F9C8C 000F6A8C  C0 42 91 9C */	lfs f2, lbl_805DF89C@sda21(r0)
/* 800F9C90 000F6A90  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F9C94 000F6A94  38 C0 FF FF */	li r6, -0x1
/* 800F9C98 000F6A98  38 E0 00 00 */	li r7, 0x0
/* 800F9C9C 000F6A9C  4B FF B8 AD */	bl kar_gryaku_set_path_node_motion
/* 800F9CA0 000F6AA0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F9CA4 000F6AA4  7C 08 03 A6 */	mtlr r0
/* 800F9CA8 000F6AA8  38 21 00 10 */	addi r1, r1, 0x10
/* 800F9CAC 000F6AAC  4E 80 00 20 */	blr
.endfn kar_gryakucommon_init_factory_variant6_path_only

# .text:0x14CC | 0x800F9CB0 | size: 0x48
.fn kar_gryakucommon_create_factory_variant7_bbox, global
/* 800F9CB0 000F6AB0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9CB4 000F6AB4  7C 08 02 A6 */	mflr r0
/* 800F9CB8 000F6AB8  7C 83 23 78 */	mr r3, r4
/* 800F9CBC 000F6ABC  7C A4 2B 78 */	mr r4, r5
/* 800F9CC0 000F6AC0  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9CC4 000F6AC4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F9CC8 000F6AC8  4B FF AE 59 */	bl kar_gryaku_create_common_yaku_by_kind
/* 800F9CCC 000F6ACC  7C 7F 1B 78 */	mr r31, r3
/* 800F9CD0 000F6AD0  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F9CD4 000F6AD4  4B FF F4 B5 */	bl kar_gryakucommon_enable_display_bbox_flag
/* 800F9CD8 000F6AD8  7F E3 FB 78 */	mr r3, r31
/* 800F9CDC 000F6ADC  48 00 00 65 */	bl kar_gryakucommon_init_factory_variant7_path_only
/* 800F9CE0 000F6AE0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F9CE4 000F6AE4  7F E3 FB 78 */	mr r3, r31
/* 800F9CE8 000F6AE8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F9CEC 000F6AEC  7C 08 03 A6 */	mtlr r0
/* 800F9CF0 000F6AF0  38 21 00 10 */	addi r1, r1, 0x10
/* 800F9CF4 000F6AF4  4E 80 00 20 */	blr
.endfn kar_gryakucommon_create_factory_variant7_bbox

# .text:0x1514 | 0x800F9CF8 | size: 0x48
.fn kar_gryakucommon_create_factory_variant7_scaled_bbox, global
/* 800F9CF8 000F6AF8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9CFC 000F6AFC  7C 08 02 A6 */	mflr r0
/* 800F9D00 000F6B00  7C 83 23 78 */	mr r3, r4
/* 800F9D04 000F6B04  7C A4 2B 78 */	mr r4, r5
/* 800F9D08 000F6B08  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9D0C 000F6B0C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F9D10 000F6B10  4B FF AE 11 */	bl kar_gryaku_create_common_yaku_by_kind
/* 800F9D14 000F6B14  7C 7F 1B 78 */	mr r31, r3
/* 800F9D18 000F6B18  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F9D1C 000F6B1C  4B FF F4 AD */	bl kar_gryakucommon_enable_scaled_display_bbox_flags
/* 800F9D20 000F6B20  7F E3 FB 78 */	mr r3, r31
/* 800F9D24 000F6B24  48 00 00 1D */	bl kar_gryakucommon_init_factory_variant7_path_only
/* 800F9D28 000F6B28  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F9D2C 000F6B2C  7F E3 FB 78 */	mr r3, r31
/* 800F9D30 000F6B30  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F9D34 000F6B34  7C 08 03 A6 */	mtlr r0
/* 800F9D38 000F6B38  38 21 00 10 */	addi r1, r1, 0x10
/* 800F9D3C 000F6B3C  4E 80 00 20 */	blr
.endfn kar_gryakucommon_create_factory_variant7_scaled_bbox

# .text:0x155C | 0x800F9D40 | size: 0x40
.fn kar_gryakucommon_init_factory_variant7_path_only, global
/* 800F9D40 000F6B40  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9D44 000F6B44  7C 08 02 A6 */	mflr r0
/* 800F9D48 000F6B48  C0 22 91 A0 */	lfs f1, lbl_805DF8A0@sda21(r0)
/* 800F9D4C 000F6B4C  38 80 00 00 */	li r4, 0x0
/* 800F9D50 000F6B50  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9D54 000F6B54  38 A0 00 00 */	li r5, 0x0
/* 800F9D58 000F6B58  FC 60 08 90 */	fmr f3, f1
/* 800F9D5C 000F6B5C  C0 42 91 A4 */	lfs f2, lbl_805DF8A4@sda21(r0)
/* 800F9D60 000F6B60  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F9D64 000F6B64  38 C0 FF FF */	li r6, -0x1
/* 800F9D68 000F6B68  38 E0 00 00 */	li r7, 0x0
/* 800F9D6C 000F6B6C  4B FF B7 DD */	bl kar_gryaku_set_path_node_motion
/* 800F9D70 000F6B70  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F9D74 000F6B74  7C 08 03 A6 */	mtlr r0
/* 800F9D78 000F6B78  38 21 00 10 */	addi r1, r1, 0x10
/* 800F9D7C 000F6B7C  4E 80 00 20 */	blr
.endfn kar_gryakucommon_init_factory_variant7_path_only

# .text:0x159C | 0x800F9D80 | size: 0x38
.fn kar_gryakucommon_create_stage_linked_kind16_yaku, global
/* 800F9D80 000F6B80  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9D84 000F6B84  7C 08 02 A6 */	mflr r0
/* 800F9D88 000F6B88  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9D8C 000F6B8C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F9D90 000F6B90  7C 7F 1B 78 */	mr r31, r3
/* 800F9D94 000F6B94  38 60 00 10 */	li r3, 0x10
/* 800F9D98 000F6B98  4B FF A6 D5 */	bl kar_gryaku_create_yaku_from_main_kind
/* 800F9D9C 000F6B9C  7F E4 FB 78 */	mr r4, r31
/* 800F9DA0 000F6BA0  48 00 00 19 */	bl kar_gryakucommon_init_stage_linked_kind16_yaku
/* 800F9DA4 000F6BA4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F9DA8 000F6BA8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F9DAC 000F6BAC  7C 08 03 A6 */	mtlr r0
/* 800F9DB0 000F6BB0  38 21 00 10 */	addi r1, r1, 0x10
/* 800F9DB4 000F6BB4  4E 80 00 20 */	blr
.endfn kar_gryakucommon_create_stage_linked_kind16_yaku

# .text:0x15D4 | 0x800F9DB8 | size: 0x90
.fn kar_gryakucommon_init_stage_linked_kind16_yaku, global
/* 800F9DB8 000F6BB8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9DBC 000F6BBC  7C 08 02 A6 */	mflr r0
/* 800F9DC0 000F6BC0  38 A0 00 00 */	li r5, 0x0
/* 800F9DC4 000F6BC4  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9DC8 000F6BC8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F9DCC 000F6BCC  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800F9DD0 000F6BD0  7C 7E 1B 78 */	mr r30, r3
/* 800F9DD4 000F6BD4  83 FE 00 2C */	lwz r31, 0x2c(r30)
/* 800F9DD8 000F6BD8  80 64 00 2C */	lwz r3, 0x2c(r4)
/* 800F9DDC 000F6BDC  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 800F9DE0 000F6BE0  80 C3 01 04 */	lwz r6, 0x104(r3)
/* 800F9DE4 000F6BE4  80 84 00 00 */	lwz r4, 0x0(r4)
/* 800F9DE8 000F6BE8  80 ED 05 EC */	lwz r7, lbl_805DD6CC@sda21(r0)
/* 800F9DEC 000F6BEC  80 04 00 00 */	lwz r0, 0x0(r4)
/* 800F9DF0 000F6BF0  38 67 00 54 */	addi r3, r7, 0x54
/* 800F9DF4 000F6BF4  54 00 18 38 */	slwi r0, r0, 3
/* 800F9DF8 000F6BF8  7C 86 00 2E */	lwzx r4, r6, r0
/* 800F9DFC 000F6BFC  4B FD DB C5 */	bl kar_grcoll__800d79c0
/* 800F9E00 000F6C00  90 7F 01 30 */	stw r3, 0x130(r31)
/* 800F9E04 000F6C04  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 800F9E08 000F6C08  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 800F9E0C 000F6C0C  90 03 01 38 */	stw r0, 0x138(r3)
/* 800F9E10 000F6C10  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F9E14 000F6C14  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800F9E18 000F6C18  28 00 00 00 */	cmplwi r0, 0x0
/* 800F9E1C 000F6C1C  41 82 00 0C */	beq .L_800F9E28
/* 800F9E20 000F6C20  7F E3 FB 78 */	mr r3, r31
/* 800F9E24 000F6C24  48 00 00 25 */	bl kar_gryakucommon_init_four_audio_rail_states
.L_800F9E28:
/* 800F9E28 000F6C28  7F C3 F3 78 */	mr r3, r30
/* 800F9E2C 000F6C2C  48 00 01 05 */	bl kar_gryakucommon_start_stage_linked_path_motion
/* 800F9E30 000F6C30  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F9E34 000F6C34  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F9E38 000F6C38  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800F9E3C 000F6C3C  7C 08 03 A6 */	mtlr r0
/* 800F9E40 000F6C40  38 21 00 10 */	addi r1, r1, 0x10
/* 800F9E44 000F6C44  4E 80 00 20 */	blr
.endfn kar_gryakucommon_init_stage_linked_kind16_yaku

# .text:0x1664 | 0x800F9E48 | size: 0x88
.fn kar_gryakucommon_init_four_audio_rail_states, global
/* 800F9E48 000F6C48  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F9E4C 000F6C4C  7C 08 02 A6 */	mflr r0
/* 800F9E50 000F6C50  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F9E54 000F6C54  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F9E58 000F6C58  7C 7F 1B 78 */	mr r31, r3
/* 800F9E5C 000F6C5C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F9E60 000F6C60  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F9E64 000F6C64  80 83 00 08 */	lwz r4, 0x8(r3)
/* 800F9E68 000F6C68  83 C4 00 14 */	lwz r30, 0x14(r4)
/* 800F9E6C 000F6C6C  4B FF D9 E1 */	bl kar_gryakueffect_stop_audio_rail_state
/* 800F9E70 000F6C70  3B A0 00 00 */	li r29, 0x0
.L_800F9E74:
/* 800F9E74 000F6C74  38 7F 01 34 */	addi r3, r31, 0x134
/* 800F9E78 000F6C78  4B FE FB D5 */	bl kar_grrail__near_800e9a4c
/* 800F9E7C 000F6C7C  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 800F9E80 000F6C80  90 1F 01 34 */	stw r0, 0x134(r31)
/* 800F9E84 000F6C84  80 1E 00 04 */	lwz r0, 0x4(r30)
/* 800F9E88 000F6C88  90 1F 01 38 */	stw r0, 0x138(r31)
/* 800F9E8C 000F6C8C  80 7E 00 08 */	lwz r3, 0x8(r30)
/* 800F9E90 000F6C90  4B FF 00 19 */	bl kar_graudio_alloc_fgm_track_by_kind
/* 800F9E94 000F6C94  90 7F 01 3C */	stw r3, 0x13c(r31)
/* 800F9E98 000F6C98  38 60 00 01 */	li r3, 0x1
/* 800F9E9C 000F6C9C  4B FF 00 95 */	bl kar_graudio_alloc_map_fgm_track_group
/* 800F9EA0 000F6CA0  3B BD 00 01 */	addi r29, r29, 0x1
/* 800F9EA4 000F6CA4  90 7F 01 40 */	stw r3, 0x140(r31)
/* 800F9EA8 000F6CA8  2C 1D 00 04 */	cmpwi r29, 0x4
/* 800F9EAC 000F6CAC  3B FF 00 14 */	addi r31, r31, 0x14
/* 800F9EB0 000F6CB0  41 80 FF C4 */	blt .L_800F9E74
/* 800F9EB4 000F6CB4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F9EB8 000F6CB8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F9EBC 000F6CBC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F9EC0 000F6CC0  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F9EC4 000F6CC4  7C 08 03 A6 */	mtlr r0
/* 800F9EC8 000F6CC8  38 21 00 20 */	addi r1, r1, 0x20
/* 800F9ECC 000F6CCC  4E 80 00 20 */	blr
.endfn kar_gryakucommon_init_four_audio_rail_states

# .text:0x16EC | 0x800F9ED0 | size: 0x60
.fn kar_gryakucommon_stop_four_audio_rail_states, global
/* 800F9ED0 000F6CD0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9ED4 000F6CD4  7C 08 02 A6 */	mflr r0
/* 800F9ED8 000F6CD8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9EDC 000F6CDC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F9EE0 000F6CE0  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800F9EE4 000F6CE4  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 800F9EE8 000F6CE8  80 64 00 08 */	lwz r3, 0x8(r4)
/* 800F9EEC 000F6CEC  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800F9EF0 000F6CF0  28 00 00 00 */	cmplwi r0, 0x0
/* 800F9EF4 000F6CF4  41 82 00 24 */	beq .L_800F9F18
/* 800F9EF8 000F6CF8  3B C0 00 00 */	li r30, 0x0
/* 800F9EFC 000F6CFC  7C 9F 23 78 */	mr r31, r4
.L_800F9F00:
/* 800F9F00 000F6D00  38 7F 01 34 */	addi r3, r31, 0x134
/* 800F9F04 000F6D04  4B FE FB 65 */	bl kar_graudio_stop_fgm_entry
/* 800F9F08 000F6D08  3B DE 00 01 */	addi r30, r30, 0x1
/* 800F9F0C 000F6D0C  3B FF 00 14 */	addi r31, r31, 0x14
/* 800F9F10 000F6D10  2C 1E 00 04 */	cmpwi r30, 0x4
/* 800F9F14 000F6D14  41 80 FF EC */	blt .L_800F9F00
.L_800F9F18:
/* 800F9F18 000F6D18  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F9F1C 000F6D1C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F9F20 000F6D20  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800F9F24 000F6D24  7C 08 03 A6 */	mtlr r0
/* 800F9F28 000F6D28  38 21 00 10 */	addi r1, r1, 0x10
/* 800F9F2C 000F6D2C  4E 80 00 20 */	blr
.endfn kar_gryakucommon_stop_four_audio_rail_states

# .text:0x174C | 0x800F9F30 | size: 0x48
.fn kar_gryakucommon_start_stage_linked_path_motion, global
/* 800F9F30 000F6D30  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F9F34 000F6D34  7C 08 02 A6 */	mflr r0
/* 800F9F38 000F6D38  C0 22 91 A8 */	lfs f1, lbl_805DF8A8@sda21(r0)
/* 800F9F3C 000F6D3C  38 80 00 00 */	li r4, 0x0
/* 800F9F40 000F6D40  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F9F44 000F6D44  38 A0 FF FF */	li r5, -0x1
/* 800F9F48 000F6D48  FC 40 08 90 */	fmr f2, f1
/* 800F9F4C 000F6D4C  38 E0 00 00 */	li r7, 0x0
/* 800F9F50 000F6D50  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F9F54 000F6D54  FC 60 08 90 */	fmr f3, f1
/* 800F9F58 000F6D58  80 C3 00 08 */	lwz r6, 0x8(r3)
/* 800F9F5C 000F6D5C  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 800F9F60 000F6D60  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 800F9F64 000F6D64  4B FF B5 E5 */	bl kar_gryaku_set_path_node_motion
/* 800F9F68 000F6D68  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F9F6C 000F6D6C  7C 08 03 A6 */	mtlr r0
/* 800F9F70 000F6D70  38 21 00 10 */	addi r1, r1, 0x10
/* 800F9F74 000F6D74  4E 80 00 20 */	blr
.endfn kar_gryakucommon_start_stage_linked_path_motion

# 0x804A5D40..0x804A5EFC | size: 0x1BC
.data
.balign 8

# .data:0x0 | 0x804A5D40 | size: 0xF
.obj kar_src_gryakucommon_c, global
	.string "gryakucommon.c"
.endobj kar_src_gryakucommon_c

# .data:0xF | 0x804A5D4F | size: 0x1
.obj gap_07_804A5D4F_data, global
.hidden gap_07_804A5D4F_data
	.byte 0x00
.endobj gap_07_804A5D4F_data

# .data:0x10 | 0x804A5D50 | size: 0x48
.obj gryakucommon_opcode_callback_table, global
	.4byte kar_gryakucommon_opcode_noop_primary
	.4byte kar_gryakucommon_opcode_noop_primary
	.4byte 0x01000000
	.4byte kar_gryakucommon_opcode_noop_secondary
	.4byte kar_gryakucommon_opcode_noop_secondary
	.4byte 0x01000000
	.4byte kar_gryakucommon_decode_clobject_slot_opcode
	.4byte 0x00000000
	.4byte 0x07000000
	.4byte kar_gryakucommon_flush_clobject_slots_opcode
	.4byte 0x00000000
	.4byte 0x01000000
	.4byte kar_gryakucommon_decode_animlist_effect_opcode
	.4byte 0x00000000
	.4byte 0x05000000
	.4byte kar_gryakucommon_opcode_noop_terminator
	.4byte 0x00000000
	.4byte 0x02000000
.endobj gryakucommon_opcode_callback_table

# .data:0x58 | 0x804A5D98 | size: 0x10
.obj lbl_804A5D98, global
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A5D98

# .data:0x68 | 0x804A5DA8 | size: 0x18
.obj gryakucommon_factory_variant0_config, global
	.4byte lbl_804A5D98
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj gryakucommon_factory_variant0_config

# .data:0x80 | 0x804A5DC0 | size: 0x10
.obj lbl_804A5DC0, global
	.4byte 0x00000000
	.4byte kar_gryakucommon_update_variant1_anchor_audio
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A5DC0

# .data:0x90 | 0x804A5DD0 | size: 0x18
.obj gryakucommon_factory_variant1_config, global
	.4byte lbl_804A5DC0
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj gryakucommon_factory_variant1_config

# .data:0xA8 | 0x804A5DE8 | size: 0x10
.obj lbl_804A5DE8, global
	.4byte 0x00000000
	.4byte kar_gryakucommon_update_variant2_anchor_audio
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A5DE8

# .data:0xB8 | 0x804A5DF8 | size: 0x18
.obj gryakucommon_factory_variant2_config, global
	.4byte lbl_804A5DE8
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj gryakucommon_factory_variant2_config

# .data:0xD0 | 0x804A5E10 | size: 0x10
.obj lbl_804A5E10, global
	.4byte 0x00000000
	.4byte kar_gryakucommon_update_variant3_anchor_audio
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A5E10

# .data:0xE0 | 0x804A5E20 | size: 0x18
.obj gryakucommon_factory_variant3_config, global
	.4byte lbl_804A5E10
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj gryakucommon_factory_variant3_config

# .data:0xF8 | 0x804A5E38 | size: 0x10
.obj lbl_804A5E38, global
	.4byte 0x00000000
	.4byte kar_gryakucommon_update_variant4_audio_only
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A5E38

# .data:0x108 | 0x804A5E48 | size: 0x18
.obj gryakucommon_factory_variant4_config, global
	.4byte lbl_804A5E38
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj gryakucommon_factory_variant4_config

# .data:0x120 | 0x804A5E60 | size: 0x10
.obj lbl_804A5E60, global
	.4byte 0x00000000
	.4byte kar_gryakucommon_update_variant5_audio_only
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A5E60

# .data:0x130 | 0x804A5E70 | size: 0x18
.obj gryakucommon_factory_variant5_config, global
	.4byte lbl_804A5E60
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj gryakucommon_factory_variant5_config

# .data:0x148 | 0x804A5E88 | size: 0x10
.obj lbl_804A5E88, global
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A5E88

# .data:0x158 | 0x804A5E98 | size: 0x18
.obj gryakucommon_factory_variant6_config, global
	.4byte lbl_804A5E88
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj gryakucommon_factory_variant6_config

# .data:0x170 | 0x804A5EB0 | size: 0x10
.obj lbl_804A5EB0, global
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A5EB0

# .data:0x180 | 0x804A5EC0 | size: 0x18
.obj gryakucommon_factory_variant7_config, global
	.4byte lbl_804A5EB0
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj gryakucommon_factory_variant7_config

# .data:0x198 | 0x804A5ED8 | size: 0x10
.obj lbl_804A5ED8, global
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A5ED8

# .data:0x1A8 | 0x804A5EE8 | size: 0x14
.obj lbl_804A5EE8, global
	.4byte lbl_804A5ED8
	.4byte 0x00000000
	.4byte kar_gryakucommon_stop_four_audio_rail_states
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A5EE8

# 0x805D6208..0x805D6220 | size: 0x18
.section .sdata, "wa"
.balign 8

# .sdata:0x0 | 0x805D6208 | size: 0x2
.obj lbl_805D6208, global
	.string "0"
.endobj lbl_805D6208

# .sdata:0x2 | 0x805D620A | size: 0x2
.obj gap_09_805D620A_sdata, global
.hidden gap_09_805D620A_sdata
	.2byte 0x0000
.endobj gap_09_805D620A_sdata

# .sdata:0x4 | 0x805D620C | size: 0x7
.obj kar_srcfile_jobj_h_805d620c, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d620c

# .sdata:0xB | 0x805D6213 | size: 0x1
.obj gap_09_805D6213_sdata, global
.hidden gap_09_805D6213_sdata
	.byte 0x00
.endobj gap_09_805D6213_sdata

# .sdata:0xC | 0x805D6214 | size: 0x5
.obj lbl_805D6214, global
	.string "jobj"
.endobj lbl_805D6214

# .sdata:0x11 | 0x805D6219 | size: 0x7
.obj gap_09_805D6219_sdata, global
.hidden gap_09_805D6219_sdata
	.4byte 0x00000000
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6219_sdata

# 0x805DF838..0x805DF8AC | size: 0x74
.section .sdata2, "a"
.balign 8

# .sdata2:0x0 | 0x805DF838 | size: 0x4
.obj lbl_805DF838, global
	.float 0
.endobj lbl_805DF838

# .sdata2:0x4 | 0x805DF83C | size: 0x4
.obj lbl_805DF83C, global
	.float 1
.endobj lbl_805DF83C

# .sdata2:0x8 | 0x805DF840 | size: 0x4
.obj lbl_805DF840, global
	.float 0.004
.endobj lbl_805DF840

# .sdata2:0xC | 0x805DF844 | size: 0x4
.obj lbl_805DF844, global
	.float 24.685715
.endobj lbl_805DF844

# .sdata2:0x10 | 0x805DF848 | size: 0x4
.obj lbl_805DF848, global
	.float -1
.endobj lbl_805DF848
	.4byte 0x00000000

# .sdata2:0x18 | 0x805DF850 | size: 0x8
.obj lbl_805DF850, global
	.double 4503599627370496
.endobj lbl_805DF850

# .sdata2:0x20 | 0x805DF858 | size: 0x8
.obj lbl_805DF858, global
	.double 4503601774854144
.endobj lbl_805DF858

# .sdata2:0x28 | 0x805DF860 | size: 0x4
.obj lbl_805DF860, global
	.float 340282350000000000000000000000000000000
.endobj lbl_805DF860

# .sdata2:0x2C | 0x805DF864 | size: 0x4
.obj lbl_805DF864, global
	.float 0
.endobj lbl_805DF864

# .sdata2:0x30 | 0x805DF868 | size: 0x4
.obj lbl_805DF868, global
	.float 0
.endobj lbl_805DF868

# .sdata2:0x34 | 0x805DF86C | size: 0x4
.obj lbl_805DF86C, global
	.float 1
.endobj lbl_805DF86C

# .sdata2:0x38 | 0x805DF870 | size: 0x4
.obj lbl_805DF870, global
	.float 0
.endobj lbl_805DF870

# .sdata2:0x3C | 0x805DF874 | size: 0x4
.obj lbl_805DF874, global
	.float 1
.endobj lbl_805DF874

# .sdata2:0x40 | 0x805DF878 | size: 0x4
.obj lbl_805DF878, global
	.float 0
.endobj lbl_805DF878

# .sdata2:0x44 | 0x805DF87C | size: 0x4
.obj lbl_805DF87C, global
	.float 1
.endobj lbl_805DF87C

# .sdata2:0x48 | 0x805DF880 | size: 0x4
.obj lbl_805DF880, global
	.float 0
.endobj lbl_805DF880

# .sdata2:0x4C | 0x805DF884 | size: 0x4
.obj lbl_805DF884, global
	.float 1
.endobj lbl_805DF884

# .sdata2:0x50 | 0x805DF888 | size: 0x4
.obj lbl_805DF888, global
	.float 0
.endobj lbl_805DF888

# .sdata2:0x54 | 0x805DF88C | size: 0x4
.obj lbl_805DF88C, global
	.float 1
.endobj lbl_805DF88C

# .sdata2:0x58 | 0x805DF890 | size: 0x4
.obj lbl_805DF890, global
	.float 0
.endobj lbl_805DF890

# .sdata2:0x5C | 0x805DF894 | size: 0x4
.obj lbl_805DF894, global
	.float 1
.endobj lbl_805DF894

# .sdata2:0x60 | 0x805DF898 | size: 0x4
.obj lbl_805DF898, global
	.float 0
.endobj lbl_805DF898

# .sdata2:0x64 | 0x805DF89C | size: 0x4
.obj lbl_805DF89C, global
	.float 1
.endobj lbl_805DF89C

# .sdata2:0x68 | 0x805DF8A0 | size: 0x4
.obj lbl_805DF8A0, global
	.float 0
.endobj lbl_805DF8A0

# .sdata2:0x6C | 0x805DF8A4 | size: 0x4
.obj lbl_805DF8A4, global
	.float 1
.endobj lbl_805DF8A4

# .sdata2:0x70 | 0x805DF8A8 | size: 0x4
.obj lbl_805DF8A8, global
	.float 0
.endobj lbl_805DF8A8
