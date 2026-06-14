.include "macros.inc"
.file "gryakuaudio.c"

# 0x800F7870..0x800F7A64 | size: 0x1F4
.text
.balign 4

# .text:0x0 | 0x800F7870 | size: 0xC0
.fn kar_gryakuaudio_configure_fgm_track_from_joint, global
/* 800F7870 000F4670  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800F7874 000F4674  7C 08 02 A6 */	mflr r0
/* 800F7878 000F4678  90 01 00 34 */	stw r0, 0x34(r1)
/* 800F787C 000F467C  39 61 00 30 */	addi r11, r1, 0x30
/* 800F7880 000F4680  48 2B 62 D5 */	bl _savegpr_27
/* 800F7884 000F4684  7C 7B 1B 78 */	mr r27, r3
/* 800F7888 000F4688  7C 9C 23 78 */	mr r28, r4
/* 800F788C 000F468C  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800F7890 000F4690  7C BD 2B 78 */	mr r29, r5
/* 800F7894 000F4694  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F7898 000F4698  83 C3 00 14 */	lwz r30, 0x14(r3)
/* 800F789C 000F469C  80 BE 00 14 */	lwz r5, 0x14(r30)
/* 800F78A0 000F46A0  28 05 00 00 */	cmplwi r5, 0x0
/* 800F78A4 000F46A4  41 82 00 18 */	beq .L_800F78BC
/* 800F78A8 000F46A8  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800F78AC 000F46AC  80 9F 01 24 */	lwz r4, 0x124(r31)
/* 800F78B0 000F46B0  C0 3E 00 10 */	lfs f1, 0x10(r30)
/* 800F78B4 000F46B4  4B FF 26 9D */	bl kar_graudio_configure_fgm_track_mode
/* 800F78B8 000F46B8  48 00 00 60 */	b .L_800F7918
.L_800F78BC:
/* 800F78BC 000F46BC  2C 1C FF FF */	cmpwi r28, -0x1
/* 800F78C0 000F46C0  40 82 00 1C */	bne .L_800F78DC
/* 800F78C4 000F46C4  3C 60 80 4A */	lis r3, kar_src_gryakuaudio_c@ha
/* 800F78C8 000F46C8  3C A0 80 4A */	lis r5, kar_gryakuaudio_assert_joint_not_parts_none@ha
/* 800F78CC 000F46CC  38 63 5B 30 */	addi r3, r3, kar_src_gryakuaudio_c@l
/* 800F78D0 000F46D0  38 80 00 B6 */	li r4, 0xb6
/* 800F78D4 000F46D4  38 A5 5B 40 */	addi r5, r5, kar_gryakuaudio_assert_joint_not_parts_none@l
/* 800F78D8 000F46D8  48 33 0B E1 */	bl __assert
.L_800F78DC:
/* 800F78DC 000F46DC  2C 1D 00 00 */	cmpwi r29, 0x0
/* 800F78E0 000F46E0  41 82 00 18 */	beq .L_800F78F8
/* 800F78E4 000F46E4  7F 63 DB 78 */	mr r3, r27
/* 800F78E8 000F46E8  7F 84 E3 78 */	mr r4, r28
/* 800F78EC 000F46EC  38 A1 00 08 */	addi r5, r1, 0x8
/* 800F78F0 000F46F0  48 00 02 59 */	bl kar_gryakulib_get_anchor_world_translate
/* 800F78F4 000F46F4  48 00 00 10 */	b .L_800F7904
.L_800F78F8:
/* 800F78F8 000F46F8  7F 83 E3 78 */	mr r3, r28
/* 800F78FC 000F46FC  38 81 00 08 */	addi r4, r1, 0x8
/* 800F7900 000F4700  4B FD D2 F5 */	bl kar_grcommon__near_800d4bf4
.L_800F7904:
/* 800F7904 000F4704  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800F7908 000F4708  38 A1 00 08 */	addi r5, r1, 0x8
/* 800F790C 000F470C  80 9F 01 24 */	lwz r4, 0x124(r31)
/* 800F7910 000F4710  C0 3E 00 10 */	lfs f1, 0x10(r30)
/* 800F7914 000F4714  4B FF 26 3D */	bl kar_graudio_configure_fgm_track_mode
.L_800F7918:
/* 800F7918 000F4718  39 61 00 30 */	addi r11, r1, 0x30
/* 800F791C 000F471C  48 2B 62 85 */	bl _restgpr_27
/* 800F7920 000F4720  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800F7924 000F4724  7C 08 03 A6 */	mtlr r0
/* 800F7928 000F4728  38 21 00 30 */	addi r1, r1, 0x30
/* 800F792C 000F472C  4E 80 00 20 */	blr
.endfn kar_gryakuaudio_configure_fgm_track_from_joint

# .text:0xC0 | 0x800F7930 | size: 0x120
.fn kar_gryakuaudio_update_scaled_joint_fgm_track, global
/* 800F7930 000F4730  94 21 FF 80 */	stwu r1, -0x80(r1)
/* 800F7934 000F4734  7C 08 02 A6 */	mflr r0
/* 800F7938 000F4738  90 01 00 84 */	stw r0, 0x84(r1)
/* 800F793C 000F473C  DB E1 00 70 */	stfd f31, 0x70(r1)
/* 800F7940 000F4740  F3 E1 00 78 */	psq_st f31, 0x78(r1), 0, qr0
/* 800F7944 000F4744  39 61 00 70 */	addi r11, r1, 0x70
/* 800F7948 000F4748  48 2B 62 0D */	bl _savegpr_27
/* 800F794C 000F474C  7C 7B 1B 78 */	mr r27, r3
/* 800F7950 000F4750  7C 9C 23 78 */	mr r28, r4
/* 800F7954 000F4754  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 800F7958 000F4758  83 FE 00 70 */	lwz r31, 0x70(r30)
/* 800F795C 000F475C  80 7E 00 08 */	lwz r3, 0x8(r30)
/* 800F7960 000F4760  28 1F 00 00 */	cmplwi r31, 0x0
/* 800F7964 000F4764  83 A3 00 14 */	lwz r29, 0x14(r3)
/* 800F7968 000F4768  40 82 00 14 */	bne .L_800F797C
/* 800F796C 000F476C  38 6D 91 08 */	li r3, kar_srcfile_jobj_h_805d61e8@sda21
/* 800F7970 000F4770  38 80 04 7C */	li r4, 0x47c
/* 800F7974 000F4774  38 AD 91 10 */	li r5, lbl_805D61F0@sda21
/* 800F7978 000F4778  48 33 0B 41 */	bl __assert
.L_800F797C:
/* 800F797C 000F477C  28 1F 00 00 */	cmplwi r31, 0x0
/* 800F7980 000F4780  41 82 00 44 */	beq .L_800F79C4
/* 800F7984 000F4784  40 82 00 14 */	bne .L_800F7998
/* 800F7988 000F4788  38 6D 91 08 */	li r3, kar_srcfile_jobj_h_805d61e8@sda21
/* 800F798C 000F478C  38 80 02 5D */	li r4, 0x25d
/* 800F7990 000F4790  38 AD 91 10 */	li r5, lbl_805D61F0@sda21
/* 800F7994 000F4794  48 33 0B 25 */	bl __assert
.L_800F7998:
/* 800F7998 000F4798  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 800F799C 000F479C  38 60 00 00 */	li r3, 0x0
/* 800F79A0 000F47A0  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 800F79A4 000F47A4  40 82 00 10 */	bne .L_800F79B4
/* 800F79A8 000F47A8  54 80 06 73 */	rlwinm. r0, r4, 0, 25, 25
/* 800F79AC 000F47AC  41 82 00 08 */	beq .L_800F79B4
/* 800F79B0 000F47B0  38 60 00 01 */	li r3, 0x1
.L_800F79B4:
/* 800F79B4 000F47B4  2C 03 00 00 */	cmpwi r3, 0x0
/* 800F79B8 000F47B8  41 82 00 0C */	beq .L_800F79C4
/* 800F79BC 000F47BC  7F E3 FB 78 */	mr r3, r31
/* 800F79C0 000F47C0  48 31 5C F5 */	bl HSD_JObjSetupMatrixSub
.L_800F79C4:
/* 800F79C4 000F47C4  38 7F 00 44 */	addi r3, r31, 0x44
/* 800F79C8 000F47C8  38 81 00 20 */	addi r4, r1, 0x20
/* 800F79CC 000F47CC  48 2D 9A 5D */	bl PSMTXCopy
/* 800F79D0 000F47D0  4B FD B6 89 */	bl kar_grcommon__near_800d3058
/* 800F79D4 000F47D4  C0 02 91 20 */	lfs f0, lbl_805DF820@sda21(r0)
/* 800F79D8 000F47D8  38 61 00 20 */	addi r3, r1, 0x20
/* 800F79DC 000F47DC  EC 20 08 24 */	fdivs f1, f0, f1
/* 800F79E0 000F47E0  4B FF F9 AD */	bl kar_gryakueffect_scale_orientation_matrix
/* 800F79E4 000F47E4  38 61 00 20 */	addi r3, r1, 0x20
/* 800F79E8 000F47E8  38 81 00 08 */	addi r4, r1, 0x8
/* 800F79EC 000F47EC  48 31 F1 39 */	bl HSD_MtxGetScale
/* 800F79F0 000F47F0  C3 E1 00 08 */	lfs f31, 0x8(r1)
/* 800F79F4 000F47F4  C0 01 00 10 */	lfs f0, 0x10(r1)
/* 800F79F8 000F47F8  FC 1F 00 40 */	fcmpo cr0, f31, f0
/* 800F79FC 000F47FC  40 81 00 08 */	ble .L_800F7A04
/* 800F7A00 000F4800  48 00 00 08 */	b .L_800F7A08
.L_800F7A04:
/* 800F7A04 000F4804  FF E0 00 90 */	fmr f31, f0
.L_800F7A08:
/* 800F7A08 000F4808  7F 63 DB 78 */	mr r3, r27
/* 800F7A0C 000F480C  7F 84 E3 78 */	mr r4, r28
/* 800F7A10 000F4810  38 A1 00 14 */	addi r5, r1, 0x14
/* 800F7A14 000F4814  48 00 01 35 */	bl kar_gryakulib_get_anchor_world_translate
/* 800F7A18 000F4818  C0 1D 00 10 */	lfs f0, 0x10(r29)
/* 800F7A1C 000F481C  38 A1 00 14 */	addi r5, r1, 0x14
/* 800F7A20 000F4820  80 7D 00 0C */	lwz r3, 0xc(r29)
/* 800F7A24 000F4824  EC 20 07 F2 */	fmuls f1, f0, f31
/* 800F7A28 000F4828  80 9E 01 24 */	lwz r4, 0x124(r30)
/* 800F7A2C 000F482C  4B FF 25 25 */	bl kar_graudio_configure_fgm_track_mode
/* 800F7A30 000F4830  E3 E1 00 78 */	psq_l f31, 0x78(r1), 0, qr0
/* 800F7A34 000F4834  39 61 00 70 */	addi r11, r1, 0x70
/* 800F7A38 000F4838  CB E1 00 70 */	lfd f31, 0x70(r1)
/* 800F7A3C 000F483C  48 2B 61 65 */	bl _restgpr_27
/* 800F7A40 000F4840  80 01 00 84 */	lwz r0, 0x84(r1)
/* 800F7A44 000F4844  7C 08 03 A6 */	mtlr r0
/* 800F7A48 000F4848  38 21 00 80 */	addi r1, r1, 0x80
/* 800F7A4C 000F484C  4E 80 00 20 */	blr
.endfn kar_gryakuaudio_update_scaled_joint_fgm_track

# .text:0x1E0 | 0x800F7A50 | size: 0x14
.fn kar_gryakuaudio_is_gr_parts_none_joint, global
/* 800F7A50 000F4850  A0 03 00 00 */	lhz r0, 0x0(r3)
/* 800F7A54 000F4854  20 00 00 0F */	subfic r0, r0, 0xf
/* 800F7A58 000F4858  7C 00 00 34 */	cntlzw r0, r0
/* 800F7A5C 000F485C  54 03 D9 7E */	srwi r3, r0, 5
/* 800F7A60 000F4860  4E 80 00 20 */	blr
.endfn kar_gryakuaudio_is_gr_parts_none_joint

# 0x804A5B30..0x804A5B60 | size: 0x30
.data
.balign 8

# .data:0x0 | 0x804A5B30 | size: 0xE
.obj kar_src_gryakuaudio_c, global
	.string "gryakuaudio.c"
.endobj kar_src_gryakuaudio_c

# .data:0xE | 0x804A5B3E | size: 0x2
.obj gap_07_804A5B3E_data, global
.hidden gap_07_804A5B3E_data
	.2byte 0x0000
.endobj gap_07_804A5B3E_data

# .data:0x10 | 0x804A5B40 | size: 0x1B
.obj kar_gryakuaudio_assert_joint_not_parts_none, global
	.string "jointName != Gr_Parts_None"
.endobj kar_gryakuaudio_assert_joint_not_parts_none

# .data:0x2B | 0x804A5B5B | size: 0x5
.obj gap_07_804A5B5B_data, global
.hidden gap_07_804A5B5B_data
	.4byte 0x00000000
	.byte 0x00
.endobj gap_07_804A5B5B_data

# 0x805D61E8..0x805D61F8 | size: 0x10
.section .sdata, "wa"
.balign 8

# .sdata:0x0 | 0x805D61E8 | size: 0x7
.obj kar_srcfile_jobj_h_805d61e8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d61e8

# .sdata:0x7 | 0x805D61EF | size: 0x1
.obj gap_09_805D61EF_sdata, global
.hidden gap_09_805D61EF_sdata
	.byte 0x00
.endobj gap_09_805D61EF_sdata

# .sdata:0x8 | 0x805D61F0 | size: 0x5
.obj lbl_805D61F0, global
	.string "jobj"
.endobj lbl_805D61F0

# .sdata:0xD | 0x805D61F5 | size: 0x3
.obj gap_09_805D61F5_sdata, global
.hidden gap_09_805D61F5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D61F5_sdata

# 0x805DF820..0x805DF828 | size: 0x8
.section .sdata2, "a"
.balign 8

# .sdata2:0x0 | 0x805DF820 | size: 0x8
.obj lbl_805DF820, global
	.float 1
	.float 0
.endobj lbl_805DF820
