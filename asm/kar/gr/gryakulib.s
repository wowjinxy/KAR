.include "macros.inc"
.file "gryakulib.c"

# 0x800F7A64..0x800F87E4 | size: 0xD80
.text
.balign 4

# .text:0x0 | 0x800F7A64 | size: 0x54
.fn kar_gryakulib_get_yaku_data_checked, global
/* 800F7A64 000F4864  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F7A68 000F4868  7C 08 02 A6 */	mflr r0
/* 800F7A6C 000F486C  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F7A70 000F4870  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F7A74 000F4874  7C 7F 1B 78 */	mr r31, r3
/* 800F7A78 000F4878  A0 03 00 00 */	lhz r0, 0x0(r3)
/* 800F7A7C 000F487C  28 00 00 0F */	cmplwi r0, 0xf
/* 800F7A80 000F4880  41 82 00 1C */	beq .L_800F7A9C
/* 800F7A84 000F4884  3C 60 80 4A */	lis r3, kar_src_gryakulib_c@ha
/* 800F7A88 000F4888  3C A0 80 4A */	lis r5, kar_gryakulib_assert_yakumono_gobj@ha
/* 800F7A8C 000F488C  38 63 5B 60 */	addi r3, r3, kar_src_gryakulib_c@l
/* 800F7A90 000F4890  38 80 00 2D */	li r4, 0x2d
/* 800F7A94 000F4894  38 A5 5B 6C */	addi r5, r5, kar_gryakulib_assert_yakumono_gobj@l
/* 800F7A98 000F4898  48 33 0A 21 */	bl __assert
.L_800F7A9C:
/* 800F7A9C 000F489C  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 800F7AA0 000F48A0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F7AA4 000F48A4  80 63 00 04 */	lwz r3, 0x4(r3)
/* 800F7AA8 000F48A8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F7AAC 000F48AC  7C 08 03 A6 */	mtlr r0
/* 800F7AB0 000F48B0  38 21 00 10 */	addi r1, r1, 0x10
/* 800F7AB4 000F48B4  4E 80 00 20 */	blr
.endfn kar_gryakulib_get_yaku_data_checked

# .text:0x54 | 0x800F7AB8 | size: 0x20
.fn kar_gryakulib_get_yaku_state_or_none, global
/* 800F7AB8 000F48B8  A0 03 00 00 */	lhz r0, 0x0(r3)
/* 800F7ABC 000F48BC  28 00 00 0F */	cmplwi r0, 0xf
/* 800F7AC0 000F48C0  40 82 00 10 */	bne .L_800F7AD0
/* 800F7AC4 000F48C4  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F7AC8 000F48C8  80 63 00 74 */	lwz r3, 0x74(r3)
/* 800F7ACC 000F48CC  4E 80 00 20 */	blr
.L_800F7AD0:
/* 800F7AD0 000F48D0  38 60 FF FF */	li r3, -0x1
/* 800F7AD4 000F48D4  4E 80 00 20 */	blr
.endfn kar_gryakulib_get_yaku_state_or_none

# .text:0x74 | 0x800F7AD8 | size: 0x70
.fn kar_gryakulib_get_model_root_position, global
/* 800F7AD8 000F48D8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F7ADC 000F48DC  7C 08 02 A6 */	mflr r0
/* 800F7AE0 000F48E0  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F7AE4 000F48E4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F7AE8 000F48E8  7C 9F 23 78 */	mr r31, r4
/* 800F7AEC 000F48EC  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800F7AF0 000F48F0  7C 7E 1B 78 */	mr r30, r3
/* 800F7AF4 000F48F4  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F7AF8 000F48F8  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800F7AFC 000F48FC  80 03 00 04 */	lwz r0, 0x4(r3)
/* 800F7B00 000F4900  28 00 00 00 */	cmplwi r0, 0x0
/* 800F7B04 000F4904  40 82 00 1C */	bne .L_800F7B20
/* 800F7B08 000F4908  3C 60 80 4A */	lis r3, kar_src_gryakulib_c@ha
/* 800F7B0C 000F490C  3C A0 80 4A */	lis r5, kar_gryakulib_assert_model_data_present@ha
/* 800F7B10 000F4910  38 63 5B 60 */	addi r3, r3, kar_src_gryakulib_c@l
/* 800F7B14 000F4914  38 80 00 4C */	li r4, 0x4c
/* 800F7B18 000F4918  38 A5 5B 90 */	addi r5, r5, kar_gryakulib_assert_model_data_present@l
/* 800F7B1C 000F491C  48 33 09 9D */	bl __assert
.L_800F7B20:
/* 800F7B20 000F4920  80 7E 00 28 */	lwz r3, 0x28(r30)
/* 800F7B24 000F4924  7F E5 FB 78 */	mr r5, r31
/* 800F7B28 000F4928  38 80 00 00 */	li r4, 0x0
/* 800F7B2C 000F492C  4B F5 C4 09 */	bl kar_gmlanmenu__near_80053f34
/* 800F7B30 000F4930  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F7B34 000F4934  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F7B38 000F4938  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800F7B3C 000F493C  7C 08 03 A6 */	mtlr r0
/* 800F7B40 000F4940  38 21 00 10 */	addi r1, r1, 0x10
/* 800F7B44 000F4944  4E 80 00 20 */	blr
.endfn kar_gryakulib_get_model_root_position

# .text:0xE4 | 0x800F7B48 | size: 0xAC
.fn kar_gryakulib_get_anchor_world_translate, global
/* 800F7B48 000F4948  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F7B4C 000F494C  7C 08 02 A6 */	mflr r0
/* 800F7B50 000F4950  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F7B54 000F4954  54 80 18 38 */	slwi r0, r4, 3
/* 800F7B58 000F4958  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F7B5C 000F495C  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800F7B60 000F4960  7C BE 2B 78 */	mr r30, r5
/* 800F7B64 000F4964  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F7B68 000F4968  80 63 00 64 */	lwz r3, 0x64(r3)
/* 800F7B6C 000F496C  7F E3 00 2E */	lwzx r31, r3, r0
/* 800F7B70 000F4970  28 1F 00 00 */	cmplwi r31, 0x0
/* 800F7B74 000F4974  40 82 00 14 */	bne .L_800F7B88
/* 800F7B78 000F4978  38 6D 91 18 */	li r3, kar_srcfile_jobj_h_805d61f8@sda21
/* 800F7B7C 000F497C  38 80 04 7C */	li r4, 0x47c
/* 800F7B80 000F4980  38 AD 91 20 */	li r5, lbl_805D6200@sda21
/* 800F7B84 000F4984  48 33 09 35 */	bl __assert
.L_800F7B88:
/* 800F7B88 000F4988  28 1F 00 00 */	cmplwi r31, 0x0
/* 800F7B8C 000F498C  41 82 00 44 */	beq .L_800F7BD0
/* 800F7B90 000F4990  40 82 00 14 */	bne .L_800F7BA4
/* 800F7B94 000F4994  38 6D 91 18 */	li r3, kar_srcfile_jobj_h_805d61f8@sda21
/* 800F7B98 000F4998  38 80 02 5D */	li r4, 0x25d
/* 800F7B9C 000F499C  38 AD 91 20 */	li r5, lbl_805D6200@sda21
/* 800F7BA0 000F49A0  48 33 09 19 */	bl __assert
.L_800F7BA4:
/* 800F7BA4 000F49A4  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 800F7BA8 000F49A8  38 60 00 00 */	li r3, 0x0
/* 800F7BAC 000F49AC  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 800F7BB0 000F49B0  40 82 00 10 */	bne .L_800F7BC0
/* 800F7BB4 000F49B4  54 80 06 73 */	rlwinm. r0, r4, 0, 25, 25
/* 800F7BB8 000F49B8  41 82 00 08 */	beq .L_800F7BC0
/* 800F7BBC 000F49BC  38 60 00 01 */	li r3, 0x1
.L_800F7BC0:
/* 800F7BC0 000F49C0  2C 03 00 00 */	cmpwi r3, 0x0
/* 800F7BC4 000F49C4  41 82 00 0C */	beq .L_800F7BD0
/* 800F7BC8 000F49C8  7F E3 FB 78 */	mr r3, r31
/* 800F7BCC 000F49CC  48 31 5A E9 */	bl HSD_JObjSetupMatrixSub
.L_800F7BD0:
/* 800F7BD0 000F49D0  7F C4 F3 78 */	mr r4, r30
/* 800F7BD4 000F49D4  38 7F 00 44 */	addi r3, r31, 0x44
/* 800F7BD8 000F49D8  48 31 EF 31 */	bl HSD_MtxGetTranslate
/* 800F7BDC 000F49DC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F7BE0 000F49E0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F7BE4 000F49E4  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800F7BE8 000F49E8  7C 08 03 A6 */	mtlr r0
/* 800F7BEC 000F49EC  38 21 00 10 */	addi r1, r1, 0x10
/* 800F7BF0 000F49F0  4E 80 00 20 */	blr
.endfn kar_gryakulib_get_anchor_world_translate

# .text:0x190 | 0x800F7BF4 | size: 0xB8
.fn kar_gryakulib_get_anchor_world_axis_z, global
/* 800F7BF4 000F49F4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F7BF8 000F49F8  7C 08 02 A6 */	mflr r0
/* 800F7BFC 000F49FC  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F7C00 000F4A00  54 80 18 38 */	slwi r0, r4, 3
/* 800F7C04 000F4A04  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F7C08 000F4A08  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800F7C0C 000F4A0C  7C BE 2B 78 */	mr r30, r5
/* 800F7C10 000F4A10  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F7C14 000F4A14  80 63 00 64 */	lwz r3, 0x64(r3)
/* 800F7C18 000F4A18  7F E3 00 2E */	lwzx r31, r3, r0
/* 800F7C1C 000F4A1C  28 1F 00 00 */	cmplwi r31, 0x0
/* 800F7C20 000F4A20  40 82 00 14 */	bne .L_800F7C34
/* 800F7C24 000F4A24  38 6D 91 18 */	li r3, kar_srcfile_jobj_h_805d61f8@sda21
/* 800F7C28 000F4A28  38 80 04 7C */	li r4, 0x47c
/* 800F7C2C 000F4A2C  38 AD 91 20 */	li r5, lbl_805D6200@sda21
/* 800F7C30 000F4A30  48 33 08 89 */	bl __assert
.L_800F7C34:
/* 800F7C34 000F4A34  28 1F 00 00 */	cmplwi r31, 0x0
/* 800F7C38 000F4A38  41 82 00 44 */	beq .L_800F7C7C
/* 800F7C3C 000F4A3C  40 82 00 14 */	bne .L_800F7C50
/* 800F7C40 000F4A40  38 6D 91 18 */	li r3, kar_srcfile_jobj_h_805d61f8@sda21
/* 800F7C44 000F4A44  38 80 02 5D */	li r4, 0x25d
/* 800F7C48 000F4A48  38 AD 91 20 */	li r5, lbl_805D6200@sda21
/* 800F7C4C 000F4A4C  48 33 08 6D */	bl __assert
.L_800F7C50:
/* 800F7C50 000F4A50  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 800F7C54 000F4A54  38 60 00 00 */	li r3, 0x0
/* 800F7C58 000F4A58  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 800F7C5C 000F4A5C  40 82 00 10 */	bne .L_800F7C6C
/* 800F7C60 000F4A60  54 80 06 73 */	rlwinm. r0, r4, 0, 25, 25
/* 800F7C64 000F4A64  41 82 00 08 */	beq .L_800F7C6C
/* 800F7C68 000F4A68  38 60 00 01 */	li r3, 0x1
.L_800F7C6C:
/* 800F7C6C 000F4A6C  2C 03 00 00 */	cmpwi r3, 0x0
/* 800F7C70 000F4A70  41 82 00 0C */	beq .L_800F7C7C
/* 800F7C74 000F4A74  7F E3 FB 78 */	mr r3, r31
/* 800F7C78 000F4A78  48 31 5A 3D */	bl HSD_JObjSetupMatrixSub
.L_800F7C7C:
/* 800F7C7C 000F4A7C  C0 1F 00 4C */	lfs f0, 0x4c(r31)
/* 800F7C80 000F4A80  D0 1E 00 00 */	stfs f0, 0x0(r30)
/* 800F7C84 000F4A84  C0 1F 00 5C */	lfs f0, 0x5c(r31)
/* 800F7C88 000F4A88  D0 1E 00 04 */	stfs f0, 0x4(r30)
/* 800F7C8C 000F4A8C  C0 1F 00 6C */	lfs f0, 0x6c(r31)
/* 800F7C90 000F4A90  D0 1E 00 08 */	stfs f0, 0x8(r30)
/* 800F7C94 000F4A94  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F7C98 000F4A98  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800F7C9C 000F4A9C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F7CA0 000F4AA0  7C 08 03 A6 */	mtlr r0
/* 800F7CA4 000F4AA4  38 21 00 10 */	addi r1, r1, 0x10
/* 800F7CA8 000F4AA8  4E 80 00 20 */	blr
.endfn kar_gryakulib_get_anchor_world_axis_z

# .text:0x248 | 0x800F7CAC | size: 0xB8
.fn kar_gryakulib_get_anchor_world_axis_x, global
/* 800F7CAC 000F4AAC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F7CB0 000F4AB0  7C 08 02 A6 */	mflr r0
/* 800F7CB4 000F4AB4  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F7CB8 000F4AB8  54 80 18 38 */	slwi r0, r4, 3
/* 800F7CBC 000F4ABC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F7CC0 000F4AC0  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800F7CC4 000F4AC4  7C BE 2B 78 */	mr r30, r5
/* 800F7CC8 000F4AC8  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F7CCC 000F4ACC  80 63 00 64 */	lwz r3, 0x64(r3)
/* 800F7CD0 000F4AD0  7F E3 00 2E */	lwzx r31, r3, r0
/* 800F7CD4 000F4AD4  28 1F 00 00 */	cmplwi r31, 0x0
/* 800F7CD8 000F4AD8  40 82 00 14 */	bne .L_800F7CEC
/* 800F7CDC 000F4ADC  38 6D 91 18 */	li r3, kar_srcfile_jobj_h_805d61f8@sda21
/* 800F7CE0 000F4AE0  38 80 04 7C */	li r4, 0x47c
/* 800F7CE4 000F4AE4  38 AD 91 20 */	li r5, lbl_805D6200@sda21
/* 800F7CE8 000F4AE8  48 33 07 D1 */	bl __assert
.L_800F7CEC:
/* 800F7CEC 000F4AEC  28 1F 00 00 */	cmplwi r31, 0x0
/* 800F7CF0 000F4AF0  41 82 00 44 */	beq .L_800F7D34
/* 800F7CF4 000F4AF4  40 82 00 14 */	bne .L_800F7D08
/* 800F7CF8 000F4AF8  38 6D 91 18 */	li r3, kar_srcfile_jobj_h_805d61f8@sda21
/* 800F7CFC 000F4AFC  38 80 02 5D */	li r4, 0x25d
/* 800F7D00 000F4B00  38 AD 91 20 */	li r5, lbl_805D6200@sda21
/* 800F7D04 000F4B04  48 33 07 B5 */	bl __assert
.L_800F7D08:
/* 800F7D08 000F4B08  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 800F7D0C 000F4B0C  38 60 00 00 */	li r3, 0x0
/* 800F7D10 000F4B10  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 800F7D14 000F4B14  40 82 00 10 */	bne .L_800F7D24
/* 800F7D18 000F4B18  54 80 06 73 */	rlwinm. r0, r4, 0, 25, 25
/* 800F7D1C 000F4B1C  41 82 00 08 */	beq .L_800F7D24
/* 800F7D20 000F4B20  38 60 00 01 */	li r3, 0x1
.L_800F7D24:
/* 800F7D24 000F4B24  2C 03 00 00 */	cmpwi r3, 0x0
/* 800F7D28 000F4B28  41 82 00 0C */	beq .L_800F7D34
/* 800F7D2C 000F4B2C  7F E3 FB 78 */	mr r3, r31
/* 800F7D30 000F4B30  48 31 59 85 */	bl HSD_JObjSetupMatrixSub
.L_800F7D34:
/* 800F7D34 000F4B34  C0 1F 00 44 */	lfs f0, 0x44(r31)
/* 800F7D38 000F4B38  D0 1E 00 00 */	stfs f0, 0x0(r30)
/* 800F7D3C 000F4B3C  C0 1F 00 54 */	lfs f0, 0x54(r31)
/* 800F7D40 000F4B40  D0 1E 00 04 */	stfs f0, 0x4(r30)
/* 800F7D44 000F4B44  C0 1F 00 64 */	lfs f0, 0x64(r31)
/* 800F7D48 000F4B48  D0 1E 00 08 */	stfs f0, 0x8(r30)
/* 800F7D4C 000F4B4C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F7D50 000F4B50  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800F7D54 000F4B54  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F7D58 000F4B58  7C 08 03 A6 */	mtlr r0
/* 800F7D5C 000F4B5C  38 21 00 10 */	addi r1, r1, 0x10
/* 800F7D60 000F4B60  4E 80 00 20 */	blr
.endfn kar_gryakulib_get_anchor_world_axis_x

# .text:0x300 | 0x800F7D64 | size: 0x4C
.fn kar_gryakulib_dispatch_city1_stage_helper, global
/* 800F7D64 000F4B64  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F7D68 000F4B68  7C 08 02 A6 */	mflr r0
/* 800F7D6C 000F4B6C  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F7D70 000F4B70  DB E1 00 18 */	stfd f31, 0x18(r1)
/* 800F7D74 000F4B74  FF E0 08 90 */	fmr f31, f1
/* 800F7D78 000F4B78  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F7D7C 000F4B7C  7C 7F 1B 78 */	mr r31, r3
/* 800F7D80 000F4B80  4B FD 9F BD */	bl kar_grcoll_get_current_course_kind
/* 800F7D84 000F4B84  2C 03 00 09 */	cmpwi r3, 0x9
/* 800F7D88 000F4B88  40 82 00 10 */	bne .L_800F7D98
/* 800F7D8C 000F4B8C  FC 20 F8 90 */	fmr f1, f31
/* 800F7D90 000F4B90  7F E3 FB 78 */	mr r3, r31
/* 800F7D94 000F4B94  48 01 76 6D */	bl kar_grcity1_break_nearby_scripted_city_targets
.L_800F7D98:
/* 800F7D98 000F4B98  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F7D9C 000F4B9C  CB E1 00 18 */	lfd f31, 0x18(r1)
/* 800F7DA0 000F4BA0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F7DA4 000F4BA4  7C 08 03 A6 */	mtlr r0
/* 800F7DA8 000F4BA8  38 21 00 20 */	addi r1, r1, 0x20
/* 800F7DAC 000F4BAC  4E 80 00 20 */	blr
.endfn kar_gryakulib_dispatch_city1_stage_helper

# .text:0x34C | 0x800F7DB0 | size: 0x60
.fn kar_gryakulib_query_desert_or_city_stage_helper, global
/* 800F7DB0 000F4BB0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F7DB4 000F4BB4  7C 08 02 A6 */	mflr r0
/* 800F7DB8 000F4BB8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F7DBC 000F4BBC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F7DC0 000F4BC0  7C 7F 1B 78 */	mr r31, r3
/* 800F7DC4 000F4BC4  4B FD 9F 79 */	bl kar_grcoll_get_current_course_kind
/* 800F7DC8 000F4BC8  2C 03 00 09 */	cmpwi r3, 0x9
/* 800F7DCC 000F4BCC  41 82 00 14 */	beq .L_800F7DE0
/* 800F7DD0 000F4BD0  40 80 00 28 */	bge .L_800F7DF8
/* 800F7DD4 000F4BD4  2C 03 00 02 */	cmpwi r3, 0x2
/* 800F7DD8 000F4BD8  41 82 00 14 */	beq .L_800F7DEC
/* 800F7DDC 000F4BDC  48 00 00 1C */	b .L_800F7DF8
.L_800F7DE0:
/* 800F7DE0 000F4BE0  7F E3 FB 78 */	mr r3, r31
/* 800F7DE4 000F4BE4  48 01 77 C1 */	bl kar_grcity1_lookup_script_entry_value
/* 800F7DE8 000F4BE8  48 00 00 14 */	b .L_800F7DFC
.L_800F7DEC:
/* 800F7DEC 000F4BEC  7F E3 FB 78 */	mr r3, r31
/* 800F7DF0 000F4BF0  48 01 67 7D */	bl kar_grdesert1_lookup_script_entry_value
/* 800F7DF4 000F4BF4  48 00 00 08 */	b .L_800F7DFC
.L_800F7DF8:
/* 800F7DF8 000F4BF8  38 60 00 00 */	li r3, 0x0
.L_800F7DFC:
/* 800F7DFC 000F4BFC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F7E00 000F4C00  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F7E04 000F4C04  7C 08 03 A6 */	mtlr r0
/* 800F7E08 000F4C08  38 21 00 10 */	addi r1, r1, 0x10
/* 800F7E0C 000F4C0C  4E 80 00 20 */	blr
.endfn kar_gryakulib_query_desert_or_city_stage_helper

# .text:0x3AC | 0x800F7E10 | size: 0x20
.fn kar_gryakulib_dispatch_breakrock_helper, global
/* 800F7E10 000F4C10  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F7E14 000F4C14  7C 08 02 A6 */	mflr r0
/* 800F7E18 000F4C18  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F7E1C 000F4C1C  48 00 A6 49 */	bl kar_gryakubreakrock_find_active_kind40_colosseum_pillar_position
/* 800F7E20 000F4C20  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F7E24 000F4C24  7C 08 03 A6 */	mtlr r0
/* 800F7E28 000F4C28  38 21 00 10 */	addi r1, r1, 0x10
/* 800F7E2C 000F4C2C  4E 80 00 20 */	blr
.endfn kar_gryakulib_dispatch_breakrock_helper

# .text:0x3CC | 0x800F7E30 | size: 0x20
.fn kar_gryakulib_dispatch_recoveryzone_helper, global
/* 800F7E30 000F4C30  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F7E34 000F4C34  7C 08 02 A6 */	mflr r0
/* 800F7E38 000F4C38  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F7E3C 000F4C3C  48 00 36 A5 */	bl kar_gryakurecoveryzone_find_nearest_active_recoveryzone_pos
/* 800F7E40 000F4C40  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F7E44 000F4C44  7C 08 03 A6 */	mtlr r0
/* 800F7E48 000F4C48  38 21 00 10 */	addi r1, r1, 0x10
/* 800F7E4C 000F4C4C  4E 80 00 20 */	blr
.endfn kar_gryakulib_dispatch_recoveryzone_helper

# .text:0x3EC | 0x800F7E50 | size: 0x20
.fn kar_gryakulib_dispatch_breakhpcoll_helper, global
/* 800F7E50 000F4C50  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F7E54 000F4C54  7C 08 02 A6 */	mflr r0
/* 800F7E58 000F4C58  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F7E5C 000F4C5C  48 01 5B 65 */	bl kar_gryakubreakhpcoll_find_kind68_lighthouse_nearest_segment_hit
/* 800F7E60 000F4C60  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F7E64 000F4C64  7C 08 03 A6 */	mtlr r0
/* 800F7E68 000F4C68  38 21 00 10 */	addi r1, r1, 0x10
/* 800F7E6C 000F4C6C  4E 80 00 20 */	blr
.endfn kar_gryakulib_dispatch_breakhpcoll_helper

# .text:0x40C | 0x800F7E70 | size: 0x3D8
.fn kar_gryakulib_random_choose_k_of_n_mask, global
/* 800F7E70 000F4C70  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 800F7E74 000F4C74  7C 08 02 A6 */	mflr r0
/* 800F7E78 000F4C78  90 01 00 64 */	stw r0, 0x64(r1)
/* 800F7E7C 000F4C7C  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 800F7E80 000F4C80  7C 9F 23 78 */	mr r31, r4
/* 800F7E84 000F4C84  7C 1F 18 50 */	subf r0, r31, r3
/* 800F7E88 000F4C88  7C 1F 00 00 */	cmpw r31, r0
/* 800F7E8C 000F4C8C  40 81 00 08 */	ble .L_800F7E94
/* 800F7E90 000F4C90  7C 04 03 78 */	mr r4, r0
.L_800F7E94:
/* 800F7E94 000F4C94  2C 04 00 00 */	cmpwi r4, 0x0
/* 800F7E98 000F4C98  40 82 00 0C */	bne .L_800F7EA4
/* 800F7E9C 000F4C9C  38 60 00 01 */	li r3, 0x1
/* 800F7EA0 000F4CA0  48 00 01 F4 */	b .L_800F8094
.L_800F7EA4:
/* 800F7EA4 000F4CA4  2C 04 00 01 */	cmpwi r4, 0x1
/* 800F7EA8 000F4CA8  40 82 00 08 */	bne .L_800F7EB0
/* 800F7EAC 000F4CAC  48 00 01 E8 */	b .L_800F8094
.L_800F7EB0:
/* 800F7EB0 000F4CB0  2C 04 00 11 */	cmpwi r4, 0x11
/* 800F7EB4 000F4CB4  40 81 00 0C */	ble .L_800F7EC0
/* 800F7EB8 000F4CB8  38 60 00 00 */	li r3, 0x0
/* 800F7EBC 000F4CBC  48 00 01 D8 */	b .L_800F8094
.L_800F7EC0:
/* 800F7EC0 000F4CC0  2C 04 00 01 */	cmpwi r4, 0x1
/* 800F7EC4 000F4CC4  39 40 00 01 */	li r10, 0x1
/* 800F7EC8 000F4CC8  40 81 00 A8 */	ble .L_800F7F70
/* 800F7ECC 000F4CCC  38 04 FF FF */	subi r0, r4, 0x1
/* 800F7ED0 000F4CD0  38 A4 FF F8 */	subi r5, r4, 0x8
/* 800F7ED4 000F4CD4  2C 00 00 08 */	cmpwi r0, 0x8
/* 800F7ED8 000F4CD8  40 81 00 68 */	ble .L_800F7F40
/* 800F7EDC 000F4CDC  38 05 00 06 */	addi r0, r5, 0x6
/* 800F7EE0 000F4CE0  39 61 00 0C */	addi r11, r1, 0xc
/* 800F7EE4 000F4CE4  54 00 E8 FE */	srwi r0, r0, 3
/* 800F7EE8 000F4CE8  7C 09 03 A6 */	mtctr r0
/* 800F7EEC 000F4CEC  2C 05 00 01 */	cmpwi r5, 0x1
/* 800F7EF0 000F4CF0  40 81 00 50 */	ble .L_800F7F40
.L_800F7EF4:
/* 800F7EF4 000F4CF4  38 AA 00 02 */	addi r5, r10, 0x2
/* 800F7EF8 000F4CF8  38 0A 00 03 */	addi r0, r10, 0x3
/* 800F7EFC 000F4CFC  90 AB 00 00 */	stw r5, 0x0(r11)
/* 800F7F00 000F4D00  39 2A 00 04 */	addi r9, r10, 0x4
/* 800F7F04 000F4D04  39 0A 00 05 */	addi r8, r10, 0x5
/* 800F7F08 000F4D08  38 EA 00 06 */	addi r7, r10, 0x6
/* 800F7F0C 000F4D0C  90 0B 00 04 */	stw r0, 0x4(r11)
/* 800F7F10 000F4D10  38 CA 00 07 */	addi r6, r10, 0x7
/* 800F7F14 000F4D14  38 AA 00 08 */	addi r5, r10, 0x8
/* 800F7F18 000F4D18  38 0A 00 09 */	addi r0, r10, 0x9
/* 800F7F1C 000F4D1C  91 2B 00 08 */	stw r9, 0x8(r11)
/* 800F7F20 000F4D20  39 4A 00 08 */	addi r10, r10, 0x8
/* 800F7F24 000F4D24  91 0B 00 0C */	stw r8, 0xc(r11)
/* 800F7F28 000F4D28  90 EB 00 10 */	stw r7, 0x10(r11)
/* 800F7F2C 000F4D2C  90 CB 00 14 */	stw r6, 0x14(r11)
/* 800F7F30 000F4D30  90 AB 00 18 */	stw r5, 0x18(r11)
/* 800F7F34 000F4D34  90 0B 00 1C */	stw r0, 0x1c(r11)
/* 800F7F38 000F4D38  39 6B 00 20 */	addi r11, r11, 0x20
/* 800F7F3C 000F4D3C  42 00 FF B8 */	bdnz .L_800F7EF4
.L_800F7F40:
/* 800F7F40 000F4D40  55 45 10 3A */	slwi r5, r10, 2
/* 800F7F44 000F4D44  38 C1 00 08 */	addi r6, r1, 0x8
/* 800F7F48 000F4D48  7C 0A 20 50 */	subf r0, r10, r4
/* 800F7F4C 000F4D4C  7C C6 2A 14 */	add r6, r6, r5
/* 800F7F50 000F4D50  7C 09 03 A6 */	mtctr r0
/* 800F7F54 000F4D54  7C 0A 20 00 */	cmpw r10, r4
/* 800F7F58 000F4D58  40 80 00 18 */	bge .L_800F7F70
.L_800F7F5C:
/* 800F7F5C 000F4D5C  38 0A 00 02 */	addi r0, r10, 0x2
/* 800F7F60 000F4D60  39 4A 00 01 */	addi r10, r10, 0x1
/* 800F7F64 000F4D64  90 06 00 00 */	stw r0, 0x0(r6)
/* 800F7F68 000F4D68  38 C6 00 04 */	addi r6, r6, 0x4
/* 800F7F6C 000F4D6C  42 00 FF F0 */	bdnz .L_800F7F5C
.L_800F7F70:
/* 800F7F70 000F4D70  7C 64 18 50 */	subf r3, r4, r3
/* 800F7F74 000F4D74  38 04 FF FF */	subi r0, r4, 0x1
/* 800F7F78 000F4D78  38 C3 00 01 */	addi r6, r3, 0x1
/* 800F7F7C 000F4D7C  38 E0 00 03 */	li r7, 0x3
/* 800F7F80 000F4D80  48 00 01 00 */	b .L_800F8080
.L_800F7F84:
/* 800F7F84 000F4D84  2C 04 00 01 */	cmpwi r4, 0x1
/* 800F7F88 000F4D88  90 E1 00 08 */	stw r7, 0x8(r1)
/* 800F7F8C 000F4D8C  38 60 00 01 */	li r3, 0x1
/* 800F7F90 000F4D90  40 81 00 EC */	ble .L_800F807C
/* 800F7F94 000F4D94  2C 00 00 08 */	cmpwi r0, 0x8
/* 800F7F98 000F4D98  39 24 FF F8 */	subi r9, r4, 0x8
/* 800F7F9C 000F4D9C  40 81 00 A8 */	ble .L_800F8044
/* 800F7FA0 000F4DA0  39 09 00 06 */	addi r8, r9, 0x6
/* 800F7FA4 000F4DA4  38 A1 00 0C */	addi r5, r1, 0xc
/* 800F7FA8 000F4DA8  55 08 E8 FE */	srwi r8, r8, 3
/* 800F7FAC 000F4DAC  7D 09 03 A6 */	mtctr r8
/* 800F7FB0 000F4DB0  2C 09 00 01 */	cmpwi r9, 0x1
/* 800F7FB4 000F4DB4  40 81 00 90 */	ble .L_800F8044
.L_800F7FB8:
/* 800F7FB8 000F4DB8  81 25 00 00 */	lwz r9, 0x0(r5)
/* 800F7FBC 000F4DBC  38 63 00 08 */	addi r3, r3, 0x8
/* 800F7FC0 000F4DC0  81 05 FF FC */	lwz r8, -0x4(r5)
/* 800F7FC4 000F4DC4  7D 09 42 14 */	add r8, r9, r8
/* 800F7FC8 000F4DC8  91 05 00 00 */	stw r8, 0x0(r5)
/* 800F7FCC 000F4DCC  81 25 00 04 */	lwz r9, 0x4(r5)
/* 800F7FD0 000F4DD0  81 05 00 00 */	lwz r8, 0x0(r5)
/* 800F7FD4 000F4DD4  7D 09 42 14 */	add r8, r9, r8
/* 800F7FD8 000F4DD8  91 05 00 04 */	stw r8, 0x4(r5)
/* 800F7FDC 000F4DDC  81 25 00 08 */	lwz r9, 0x8(r5)
/* 800F7FE0 000F4DE0  81 05 00 04 */	lwz r8, 0x4(r5)
/* 800F7FE4 000F4DE4  7D 09 42 14 */	add r8, r9, r8
/* 800F7FE8 000F4DE8  91 05 00 08 */	stw r8, 0x8(r5)
/* 800F7FEC 000F4DEC  81 25 00 0C */	lwz r9, 0xc(r5)
/* 800F7FF0 000F4DF0  81 05 00 08 */	lwz r8, 0x8(r5)
/* 800F7FF4 000F4DF4  7D 09 42 14 */	add r8, r9, r8
/* 800F7FF8 000F4DF8  91 05 00 0C */	stw r8, 0xc(r5)
/* 800F7FFC 000F4DFC  81 25 00 10 */	lwz r9, 0x10(r5)
/* 800F8000 000F4E00  81 05 00 0C */	lwz r8, 0xc(r5)
/* 800F8004 000F4E04  7D 09 42 14 */	add r8, r9, r8
/* 800F8008 000F4E08  91 05 00 10 */	stw r8, 0x10(r5)
/* 800F800C 000F4E0C  81 25 00 14 */	lwz r9, 0x14(r5)
/* 800F8010 000F4E10  81 05 00 10 */	lwz r8, 0x10(r5)
/* 800F8014 000F4E14  7D 09 42 14 */	add r8, r9, r8
/* 800F8018 000F4E18  91 05 00 14 */	stw r8, 0x14(r5)
/* 800F801C 000F4E1C  81 25 00 18 */	lwz r9, 0x18(r5)
/* 800F8020 000F4E20  81 05 00 14 */	lwz r8, 0x14(r5)
/* 800F8024 000F4E24  7D 09 42 14 */	add r8, r9, r8
/* 800F8028 000F4E28  91 05 00 18 */	stw r8, 0x18(r5)
/* 800F802C 000F4E2C  81 25 00 1C */	lwz r9, 0x1c(r5)
/* 800F8030 000F4E30  81 05 00 18 */	lwz r8, 0x18(r5)
/* 800F8034 000F4E34  7D 09 42 14 */	add r8, r9, r8
/* 800F8038 000F4E38  91 05 00 1C */	stw r8, 0x1c(r5)
/* 800F803C 000F4E3C  38 A5 00 20 */	addi r5, r5, 0x20
/* 800F8040 000F4E40  42 00 FF 78 */	bdnz .L_800F7FB8
.L_800F8044:
/* 800F8044 000F4E44  54 68 10 3A */	slwi r8, r3, 2
/* 800F8048 000F4E48  39 21 00 08 */	addi r9, r1, 0x8
/* 800F804C 000F4E4C  7C A3 20 50 */	subf r5, r3, r4
/* 800F8050 000F4E50  7D 29 42 14 */	add r9, r9, r8
/* 800F8054 000F4E54  7C A9 03 A6 */	mtctr r5
/* 800F8058 000F4E58  7C 03 20 00 */	cmpw r3, r4
/* 800F805C 000F4E5C  40 80 00 20 */	bge .L_800F807C
.L_800F8060:
/* 800F8060 000F4E60  81 09 00 00 */	lwz r8, 0x0(r9)
/* 800F8064 000F4E64  38 63 00 01 */	addi r3, r3, 0x1
/* 800F8068 000F4E68  80 A9 FF FC */	lwz r5, -0x4(r9)
/* 800F806C 000F4E6C  7C A8 2A 14 */	add r5, r8, r5
/* 800F8070 000F4E70  90 A9 00 00 */	stw r5, 0x0(r9)
/* 800F8074 000F4E74  39 29 00 04 */	addi r9, r9, 0x4
/* 800F8078 000F4E78  42 00 FF E8 */	bdnz .L_800F8060
.L_800F807C:
/* 800F807C 000F4E7C  38 E7 00 01 */	addi r7, r7, 0x1
.L_800F8080:
/* 800F8080 000F4E80  7C 07 30 00 */	cmpw r7, r6
/* 800F8084 000F4E84  40 81 FF 00 */	ble .L_800F7F84
/* 800F8088 000F4E88  54 80 10 3A */	slwi r0, r4, 2
/* 800F808C 000F4E8C  38 61 00 04 */	addi r3, r1, 0x4
/* 800F8090 000F4E90  7C 63 00 2E */	lwzx r3, r3, r0
.L_800F8094:
/* 800F8094 000F4E94  48 32 65 D5 */	bl HSD_Randi
/* 800F8098 000F4E98  38 00 00 01 */	li r0, 0x1
/* 800F809C 000F4E9C  2C 03 00 00 */	cmpwi r3, 0x0
/* 800F80A0 000F4EA0  7C 05 F8 30 */	slw r5, r0, r31
/* 800F80A4 000F4EA4  38 80 00 00 */	li r4, 0x0
/* 800F80A8 000F4EA8  38 A5 FF FF */	subi r5, r5, 0x1
/* 800F80AC 000F4EAC  40 81 01 84 */	ble .L_800F8230
/* 800F80B0 000F4EB0  2C 03 00 08 */	cmpwi r3, 0x8
/* 800F80B4 000F4EB4  38 C3 FF F8 */	subi r6, r3, 0x8
/* 800F80B8 000F4EB8  40 81 01 40 */	ble .L_800F81F8
/* 800F80BC 000F4EBC  38 06 00 07 */	addi r0, r6, 0x7
/* 800F80C0 000F4EC0  54 00 E8 FE */	srwi r0, r0, 3
/* 800F80C4 000F4EC4  7C 09 03 A6 */	mtctr r0
/* 800F80C8 000F4EC8  2C 06 00 00 */	cmpwi r6, 0x0
/* 800F80CC 000F4ECC  40 81 01 2C */	ble .L_800F81F8
.L_800F80D0:
/* 800F80D0 000F4ED0  7C 05 00 D0 */	neg r0, r5
/* 800F80D4 000F4ED4  38 84 00 08 */	addi r4, r4, 0x8
/* 800F80D8 000F4ED8  7C A7 00 38 */	and r7, r5, r0
/* 800F80DC 000F4EDC  7C C5 3A 14 */	add r6, r5, r7
/* 800F80E0 000F4EE0  7C 06 00 D0 */	neg r0, r6
/* 800F80E4 000F4EE4  7C C0 00 38 */	and r0, r6, r0
/* 800F80E8 000F4EE8  7C 00 3B 96 */	divwu r0, r0, r7
/* 800F80EC 000F4EEC  54 05 F8 7E */	srwi r5, r0, 1
/* 800F80F0 000F4EF0  38 05 FF FF */	subi r0, r5, 0x1
/* 800F80F4 000F4EF4  7C C5 03 78 */	or r5, r6, r0
/* 800F80F8 000F4EF8  7C 05 00 D0 */	neg r0, r5
/* 800F80FC 000F4EFC  7C A6 00 38 */	and r6, r5, r0
/* 800F8100 000F4F00  7C E5 32 14 */	add r7, r5, r6
/* 800F8104 000F4F04  7C 07 00 D0 */	neg r0, r7
/* 800F8108 000F4F08  7C E0 00 38 */	and r0, r7, r0
/* 800F810C 000F4F0C  7C 00 33 96 */	divwu r0, r0, r6
/* 800F8110 000F4F10  54 05 F8 7E */	srwi r5, r0, 1
/* 800F8114 000F4F14  38 05 FF FF */	subi r0, r5, 0x1
/* 800F8118 000F4F18  7C E6 03 78 */	or r6, r7, r0
/* 800F811C 000F4F1C  7C 06 00 D0 */	neg r0, r6
/* 800F8120 000F4F20  7C C5 00 38 */	and r5, r6, r0
/* 800F8124 000F4F24  7C C6 2A 14 */	add r6, r6, r5
/* 800F8128 000F4F28  7C 06 00 D0 */	neg r0, r6
/* 800F812C 000F4F2C  7C C0 00 38 */	and r0, r6, r0
/* 800F8130 000F4F30  7C 00 2B 96 */	divwu r0, r0, r5
/* 800F8134 000F4F34  54 05 F8 7E */	srwi r5, r0, 1
/* 800F8138 000F4F38  38 05 FF FF */	subi r0, r5, 0x1
/* 800F813C 000F4F3C  7C C6 03 78 */	or r6, r6, r0
/* 800F8140 000F4F40  7C 06 00 D0 */	neg r0, r6
/* 800F8144 000F4F44  7C C5 00 38 */	and r5, r6, r0
/* 800F8148 000F4F48  7C C6 2A 14 */	add r6, r6, r5
/* 800F814C 000F4F4C  7C 06 00 D0 */	neg r0, r6
/* 800F8150 000F4F50  7C C0 00 38 */	and r0, r6, r0
/* 800F8154 000F4F54  7C 00 2B 96 */	divwu r0, r0, r5
/* 800F8158 000F4F58  54 05 F8 7E */	srwi r5, r0, 1
/* 800F815C 000F4F5C  38 05 FF FF */	subi r0, r5, 0x1
/* 800F8160 000F4F60  7C C6 03 78 */	or r6, r6, r0
/* 800F8164 000F4F64  7C 06 00 D0 */	neg r0, r6
/* 800F8168 000F4F68  7C C5 00 38 */	and r5, r6, r0
/* 800F816C 000F4F6C  7C C6 2A 14 */	add r6, r6, r5
/* 800F8170 000F4F70  7C 06 00 D0 */	neg r0, r6
/* 800F8174 000F4F74  7C C0 00 38 */	and r0, r6, r0
/* 800F8178 000F4F78  7C 00 2B 96 */	divwu r0, r0, r5
/* 800F817C 000F4F7C  54 05 F8 7E */	srwi r5, r0, 1
/* 800F8180 000F4F80  38 05 FF FF */	subi r0, r5, 0x1
/* 800F8184 000F4F84  7C C6 03 78 */	or r6, r6, r0
/* 800F8188 000F4F88  7C 06 00 D0 */	neg r0, r6
/* 800F818C 000F4F8C  7C C5 00 38 */	and r5, r6, r0
/* 800F8190 000F4F90  7C C6 2A 14 */	add r6, r6, r5
/* 800F8194 000F4F94  7C 06 00 D0 */	neg r0, r6
/* 800F8198 000F4F98  7C C0 00 38 */	and r0, r6, r0
/* 800F819C 000F4F9C  7C 00 2B 96 */	divwu r0, r0, r5
/* 800F81A0 000F4FA0  54 05 F8 7E */	srwi r5, r0, 1
/* 800F81A4 000F4FA4  38 05 FF FF */	subi r0, r5, 0x1
/* 800F81A8 000F4FA8  7C C6 03 78 */	or r6, r6, r0
/* 800F81AC 000F4FAC  7C 06 00 D0 */	neg r0, r6
/* 800F81B0 000F4FB0  7C C5 00 38 */	and r5, r6, r0
/* 800F81B4 000F4FB4  7C C6 2A 14 */	add r6, r6, r5
/* 800F81B8 000F4FB8  7C 06 00 D0 */	neg r0, r6
/* 800F81BC 000F4FBC  7C C0 00 38 */	and r0, r6, r0
/* 800F81C0 000F4FC0  7C 00 2B 96 */	divwu r0, r0, r5
/* 800F81C4 000F4FC4  54 05 F8 7E */	srwi r5, r0, 1
/* 800F81C8 000F4FC8  38 05 FF FF */	subi r0, r5, 0x1
/* 800F81CC 000F4FCC  7C C6 03 78 */	or r6, r6, r0
/* 800F81D0 000F4FD0  7C 06 00 D0 */	neg r0, r6
/* 800F81D4 000F4FD4  7C C5 00 38 */	and r5, r6, r0
/* 800F81D8 000F4FD8  7C C6 2A 14 */	add r6, r6, r5
/* 800F81DC 000F4FDC  7C 06 00 D0 */	neg r0, r6
/* 800F81E0 000F4FE0  7C C0 00 38 */	and r0, r6, r0
/* 800F81E4 000F4FE4  7C 00 2B 96 */	divwu r0, r0, r5
/* 800F81E8 000F4FE8  54 05 F8 7E */	srwi r5, r0, 1
/* 800F81EC 000F4FEC  38 05 FF FF */	subi r0, r5, 0x1
/* 800F81F0 000F4FF0  7C C5 03 78 */	or r5, r6, r0
/* 800F81F4 000F4FF4  42 00 FE DC */	bdnz .L_800F80D0
.L_800F81F8:
/* 800F81F8 000F4FF8  7C 04 18 50 */	subf r0, r4, r3
/* 800F81FC 000F4FFC  7C 09 03 A6 */	mtctr r0
/* 800F8200 000F5000  7C 04 18 00 */	cmpw r4, r3
/* 800F8204 000F5004  40 80 00 2C */	bge .L_800F8230
.L_800F8208:
/* 800F8208 000F5008  7C 05 00 D0 */	neg r0, r5
/* 800F820C 000F500C  7C A3 00 38 */	and r3, r5, r0
/* 800F8210 000F5010  7C 85 1A 14 */	add r4, r5, r3
/* 800F8214 000F5014  7C 04 00 D0 */	neg r0, r4
/* 800F8218 000F5018  7C 80 00 38 */	and r0, r4, r0
/* 800F821C 000F501C  7C 00 1B 96 */	divwu r0, r0, r3
/* 800F8220 000F5020  54 03 F8 7E */	srwi r3, r0, 1
/* 800F8224 000F5024  38 03 FF FF */	subi r0, r3, 0x1
/* 800F8228 000F5028  7C 85 03 78 */	or r5, r4, r0
/* 800F822C 000F502C  42 00 FF DC */	bdnz .L_800F8208
.L_800F8230:
/* 800F8230 000F5030  80 01 00 64 */	lwz r0, 0x64(r1)
/* 800F8234 000F5034  7C A3 2B 78 */	mr r3, r5
/* 800F8238 000F5038  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 800F823C 000F503C  7C 08 03 A6 */	mtlr r0
/* 800F8240 000F5040  38 21 00 60 */	addi r1, r1, 0x60
/* 800F8244 000F5044  4E 80 00 20 */	blr
.endfn kar_gryakulib_random_choose_k_of_n_mask

# .text:0x7E4 | 0x800F8248 | size: 0xC
.fn kar_gryakulib_get_clobject_handle, global
/* 800F8248 000F5048  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F824C 000F504C  80 63 00 EC */	lwz r3, 0xec(r3)
/* 800F8250 000F5050  4E 80 00 20 */	blr
.endfn kar_gryakulib_get_clobject_handle

# .text:0x7F0 | 0x800F8254 | size: 0x4C
.fn kar_yk_assets_load_ykcommon_archive, global
/* 800F8254 000F5054  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F8258 000F5058  7C 08 02 A6 */	mflr r0
/* 800F825C 000F505C  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F8260 000F5060  80 0D 05 E0 */	lwz r0, lbl_805DD6C0@sda21(r0)
/* 800F8264 000F5064  28 00 00 00 */	cmplwi r0, 0x0
/* 800F8268 000F5068  40 82 00 28 */	bne .L_800F8290
/* 800F826C 000F506C  3C 60 80 4A */	lis r3, kar_asset_ykcommon_dat@ha
/* 800F8270 000F5070  3C A0 80 4A */	lis r5, kar_asset_ykdata_common_name@ha
/* 800F8274 000F5074  38 83 5D 00 */	addi r4, r3, kar_asset_ykcommon_dat@l
/* 800F8278 000F5078  38 E0 00 00 */	li r7, 0x0
/* 800F827C 000F507C  38 C5 5D 20 */	addi r6, r5, kar_asset_ykdata_common_name@l
/* 800F8280 000F5080  38 60 00 00 */	li r3, 0x0
/* 800F8284 000F5084  38 AD 05 E0 */	li r5, lbl_805DD6C0@sda21
/* 800F8288 000F5088  4C C6 31 82 */	crclr cr1eq
/* 800F828C 000F508C  4B F6 17 95 */	bl kar_lbarchive__80059a20
.L_800F8290:
/* 800F8290 000F5090  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F8294 000F5094  7C 08 03 A6 */	mtlr r0
/* 800F8298 000F5098  38 21 00 10 */	addi r1, r1, 0x10
/* 800F829C 000F509C  4E 80 00 20 */	blr
.endfn kar_yk_assets_load_ykcommon_archive

# .text:0x83C | 0x800F82A0 | size: 0x4C
.fn kar_ya_assets_load_yakumono_archive, global
/* 800F82A0 000F50A0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F82A4 000F50A4  7C 08 02 A6 */	mflr r0
/* 800F82A8 000F50A8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F82AC 000F50AC  80 0D 05 E4 */	lwz r0, lbl_805DD6C4@sda21(r0)
/* 800F82B0 000F50B0  28 00 00 00 */	cmplwi r0, 0x0
/* 800F82B4 000F50B4  40 82 00 28 */	bne .L_800F82DC
/* 800F82B8 000F50B8  3C 60 80 4A */	lis r3, kar_asset_yakumono_dat@ha
/* 800F82BC 000F50BC  3C A0 80 4A */	lis r5, kar_asset_ykdata_all_name@ha
/* 800F82C0 000F50C0  38 83 5D 10 */	addi r4, r3, kar_asset_yakumono_dat@l
/* 800F82C4 000F50C4  38 E0 00 00 */	li r7, 0x0
/* 800F82C8 000F50C8  38 C5 5D 30 */	addi r6, r5, kar_asset_ykdata_all_name@l
/* 800F82CC 000F50CC  38 60 00 00 */	li r3, 0x0
/* 800F82D0 000F50D0  38 AD 05 E4 */	li r5, lbl_805DD6C4@sda21
/* 800F82D4 000F50D4  4C C6 31 82 */	crclr cr1eq
/* 800F82D8 000F50D8  4B F6 17 49 */	bl kar_lbarchive__80059a20
.L_800F82DC:
/* 800F82DC 000F50DC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F82E0 000F50E0  7C 08 03 A6 */	mtlr r0
/* 800F82E4 000F50E4  38 21 00 10 */	addi r1, r1, 0x10
/* 800F82E8 000F50E8  4E 80 00 20 */	blr
.endfn kar_ya_assets_load_yakumono_archive

# .text:0x888 | 0x800F82EC | size: 0x58
.fn kar_ya_assets_load_yakumono_kdcoll_archive, global
/* 800F82EC 000F50EC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F82F0 000F50F0  7C 08 02 A6 */	mflr r0
/* 800F82F4 000F50F4  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F82F8 000F50F8  48 16 A4 8D */	bl fn_80262784
/* 800F82FC 000F50FC  2C 03 00 00 */	cmpwi r3, 0x0
/* 800F8300 000F5100  41 82 00 34 */	beq .L_800F8334
/* 800F8304 000F5104  38 00 00 00 */	li r0, 0x0
/* 800F8308 000F5108  3C 60 80 4A */	lis r3, kar_asset_yakumono_dat@ha
/* 800F830C 000F510C  90 01 00 08 */	stw r0, 0x8(r1)
/* 800F8310 000F5110  38 83 5D 10 */	addi r4, r3, kar_asset_yakumono_dat@l
/* 800F8314 000F5114  38 60 00 02 */	li r3, 0x2
/* 800F8318 000F5118  38 A0 00 04 */	li r5, 0x4
/* 800F831C 000F511C  38 C0 00 04 */	li r6, 0x4
/* 800F8320 000F5120  38 E0 00 00 */	li r7, 0x0
/* 800F8324 000F5124  39 00 00 01 */	li r8, 0x1
/* 800F8328 000F5128  39 20 00 08 */	li r9, 0x8
/* 800F832C 000F512C  39 40 00 10 */	li r10, 0x10
/* 800F8330 000F5130  4B F7 A9 61 */	bl kar_lbkdcoll__near_80072c90
.L_800F8334:
/* 800F8334 000F5134  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F8338 000F5138  7C 08 03 A6 */	mtlr r0
/* 800F833C 000F513C  38 21 00 10 */	addi r1, r1, 0x10
/* 800F8340 000F5140  4E 80 00 20 */	blr
.endfn kar_ya_assets_load_yakumono_kdcoll_archive

# .text:0x8E0 | 0x800F8344 | size: 0x44
.fn kar_gryakulib_clobject_damage_effect_callback, global
/* 800F8344 000F5144  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F8348 000F5148  7C 08 02 A6 */	mflr r0
/* 800F834C 000F514C  FC 20 10 90 */	fmr f1, f2
/* 800F8350 000F5150  7C 89 23 78 */	mr r9, r4
/* 800F8354 000F5154  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F8358 000F5158  7C A0 2B 78 */	mr r0, r5
/* 800F835C 000F515C  7C C7 33 78 */	mr r7, r6
/* 800F8360 000F5160  7D 25 4B 78 */	mr r5, r9
/* 800F8364 000F5164  81 03 00 2C */	lwz r8, 0x2c(r3)
/* 800F8368 000F5168  7C 06 03 78 */	mr r6, r0
/* 800F836C 000F516C  80 68 00 00 */	lwz r3, 0x0(r8)
/* 800F8370 000F5170  80 88 01 0C */	lwz r4, 0x10c(r8)
/* 800F8374 000F5174  48 09 58 2D */	bl kar_clobject_request_damage_effect
/* 800F8378 000F5178  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F837C 000F517C  7C 08 03 A6 */	mtlr r0
/* 800F8380 000F5180  38 21 00 10 */	addi r1, r1, 0x10
/* 800F8384 000F5184  4E 80 00 20 */	blr
.endfn kar_gryakulib_clobject_damage_effect_callback

# .text:0x924 | 0x800F8388 | size: 0x60
.fn kar_gryakulib_update_clobject_slot, global
/* 800F8388 000F5188  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F838C 000F518C  7C 08 02 A6 */	mflr r0
/* 800F8390 000F5190  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F8394 000F5194  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F8398 000F5198  7C DF 33 78 */	mr r31, r6
/* 800F839C 000F519C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F83A0 000F51A0  7C 9E 23 78 */	mr r30, r4
/* 800F83A4 000F51A4  7C A4 2B 78 */	mr r4, r5
/* 800F83A8 000F51A8  7C E5 3B 78 */	mr r5, r7
/* 800F83AC 000F51AC  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F83B0 000F51B0  7C 7D 1B 78 */	mr r29, r3
/* 800F83B4 000F51B4  48 00 04 31 */	bl kar_gryakucommon_get_jobj_by_anchor_scope
/* 800F83B8 000F51B8  7C 65 1B 78 */	mr r5, r3
/* 800F83BC 000F51BC  80 7D 00 EC */	lwz r3, 0xec(r29)
/* 800F83C0 000F51C0  7F C4 F3 78 */	mr r4, r30
/* 800F83C4 000F51C4  7F E6 FB 78 */	mr r6, r31
/* 800F83C8 000F51C8  48 09 44 FD */	bl kar_collision_object_update_motion_slot
/* 800F83CC 000F51CC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F83D0 000F51D0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F83D4 000F51D4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F83D8 000F51D8  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F83DC 000F51DC  7C 08 03 A6 */	mtlr r0
/* 800F83E0 000F51E0  38 21 00 20 */	addi r1, r1, 0x20
/* 800F83E4 000F51E4  4E 80 00 20 */	blr
.endfn kar_gryakulib_update_clobject_slot

# .text:0x984 | 0x800F83E8 | size: 0x9C
.fn kar_gryakulib_refresh_clobject_slots, global
/* 800F83E8 000F51E8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F83EC 000F51EC  7C 08 02 A6 */	mflr r0
/* 800F83F0 000F51F0  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F83F4 000F51F4  39 61 00 20 */	addi r11, r1, 0x20
/* 800F83F8 000F51F8  48 2B 57 5D */	bl _savegpr_27
/* 800F83FC 000F51FC  7C 7B 1B 78 */	mr r27, r3
/* 800F8400 000F5200  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800F8404 000F5204  83 C3 00 10 */	lwz r30, 0x10(r3)
/* 800F8408 000F5208  28 1E 00 00 */	cmplwi r30, 0x0
/* 800F840C 000F520C  41 82 00 60 */	beq .L_800F846C
/* 800F8410 000F5210  3B A0 00 00 */	li r29, 0x0
/* 800F8414 000F5214  3B E0 00 00 */	li r31, 0x0
/* 800F8418 000F5218  48 00 00 38 */	b .L_800F8450
.L_800F841C:
/* 800F841C 000F521C  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 800F8420 000F5220  7F 63 DB 78 */	mr r3, r27
/* 800F8424 000F5224  80 BB 00 A8 */	lwz r5, 0xa8(r27)
/* 800F8428 000F5228  7F 80 FA 14 */	add r28, r0, r31
/* 800F842C 000F522C  80 9C 00 00 */	lwz r4, 0x0(r28)
/* 800F8430 000F5230  48 00 03 B5 */	bl kar_gryakucommon_get_jobj_by_anchor_scope
/* 800F8434 000F5234  7C 65 1B 78 */	mr r5, r3
/* 800F8438 000F5238  80 7B 00 EC */	lwz r3, 0xec(r27)
/* 800F843C 000F523C  7F A4 EB 78 */	mr r4, r29
/* 800F8440 000F5240  38 DC 00 04 */	addi r6, r28, 0x4
/* 800F8444 000F5244  48 09 41 55 */	bl kar_collision_object_set_segment_desc
/* 800F8448 000F5248  3B FF 00 18 */	addi r31, r31, 0x18
/* 800F844C 000F524C  3B BD 00 01 */	addi r29, r29, 0x1
.L_800F8450:
/* 800F8450 000F5250  80 1E 00 04 */	lwz r0, 0x4(r30)
/* 800F8454 000F5254  7C 1D 00 00 */	cmpw r29, r0
/* 800F8458 000F5258  41 80 FF C4 */	blt .L_800F841C
/* 800F845C 000F525C  88 1B 01 2C */	lbz r0, 0x12c(r27)
/* 800F8460 000F5260  38 60 00 00 */	li r3, 0x0
/* 800F8464 000F5264  50 60 2E B4 */	rlwimi r0, r3, 5, 26, 26
/* 800F8468 000F5268  98 1B 01 2C */	stb r0, 0x12c(r27)
.L_800F846C:
/* 800F846C 000F526C  39 61 00 20 */	addi r11, r1, 0x20
/* 800F8470 000F5270  48 2B 57 31 */	bl _restgpr_27
/* 800F8474 000F5274  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F8478 000F5278  7C 08 03 A6 */	mtlr r0
/* 800F847C 000F527C  38 21 00 20 */	addi r1, r1, 0x20
/* 800F8480 000F5280  4E 80 00 20 */	blr
.endfn kar_gryakulib_refresh_clobject_slots

# .text:0xA20 | 0x800F8484 | size: 0xF8
.fn kar_gryakulib_init_clobject_handle, global
/* 800F8484 000F5284  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F8488 000F5288  7C 08 02 A6 */	mflr r0
/* 800F848C 000F528C  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F8490 000F5290  39 61 00 20 */	addi r11, r1, 0x20
/* 800F8494 000F5294  48 2B 56 C1 */	bl _savegpr_27
/* 800F8498 000F5298  7C 7F 1B 78 */	mr r31, r3
/* 800F849C 000F529C  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800F84A0 000F52A0  83 63 00 10 */	lwz r27, 0x10(r3)
/* 800F84A4 000F52A4  28 1B 00 00 */	cmplwi r27, 0x0
/* 800F84A8 000F52A8  41 82 00 14 */	beq .L_800F84BC
/* 800F84AC 000F52AC  80 DB 00 04 */	lwz r6, 0x4(r27)
/* 800F84B0 000F52B0  80 1B 00 08 */	lwz r0, 0x8(r27)
/* 800F84B4 000F52B4  90 1F 00 A8 */	stw r0, 0xa8(r31)
/* 800F84B8 000F52B8  48 00 00 10 */	b .L_800F84C8
.L_800F84BC:
/* 800F84BC 000F52BC  38 00 FF FF */	li r0, -0x1
/* 800F84C0 000F52C0  38 C0 00 00 */	li r6, 0x0
/* 800F84C4 000F52C4  90 1F 00 A8 */	stw r0, 0xa8(r31)
.L_800F84C8:
/* 800F84C8 000F52C8  80 7F 00 00 */	lwz r3, 0x0(r31)
/* 800F84CC 000F52CC  38 80 00 06 */	li r4, 0x6
/* 800F84D0 000F52D0  38 A0 00 02 */	li r5, 0x2
/* 800F84D4 000F52D4  38 E0 00 00 */	li r7, 0x0
/* 800F84D8 000F52D8  48 09 3C F1 */	bl kar_collision_object_alloc_handle
/* 800F84DC 000F52DC  28 1B 00 00 */	cmplwi r27, 0x0
/* 800F84E0 000F52E0  90 7F 00 EC */	stw r3, 0xec(r31)
/* 800F84E4 000F52E4  41 82 00 14 */	beq .L_800F84F8
/* 800F84E8 000F52E8  3C 80 80 10 */	lis r4, kar_gryakulib_clobject_damage_effect_callback@ha
/* 800F84EC 000F52EC  80 7F 00 EC */	lwz r3, 0xec(r31)
/* 800F84F0 000F52F0  38 04 83 44 */	addi r0, r4, kar_gryakulib_clobject_damage_effect_callback@l
/* 800F84F4 000F52F4  90 03 00 8C */	stw r0, 0x8c(r3)
.L_800F84F8:
/* 800F84F8 000F52F8  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F84FC 000F52FC  83 83 00 10 */	lwz r28, 0x10(r3)
/* 800F8500 000F5300  28 1C 00 00 */	cmplwi r28, 0x0
/* 800F8504 000F5304  41 82 00 60 */	beq .L_800F8564
/* 800F8508 000F5308  3B A0 00 00 */	li r29, 0x0
/* 800F850C 000F530C  7F BB EB 78 */	mr r27, r29
/* 800F8510 000F5310  48 00 00 38 */	b .L_800F8548
.L_800F8514:
/* 800F8514 000F5314  80 1C 00 00 */	lwz r0, 0x0(r28)
/* 800F8518 000F5318  7F E3 FB 78 */	mr r3, r31
/* 800F851C 000F531C  80 BF 00 A8 */	lwz r5, 0xa8(r31)
/* 800F8520 000F5320  7F C0 DA 14 */	add r30, r0, r27
/* 800F8524 000F5324  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 800F8528 000F5328  48 00 02 BD */	bl kar_gryakucommon_get_jobj_by_anchor_scope
/* 800F852C 000F532C  7C 65 1B 78 */	mr r5, r3
/* 800F8530 000F5330  80 7F 00 EC */	lwz r3, 0xec(r31)
/* 800F8534 000F5334  7F A4 EB 78 */	mr r4, r29
/* 800F8538 000F5338  38 DE 00 04 */	addi r6, r30, 0x4
/* 800F853C 000F533C  48 09 40 5D */	bl kar_collision_object_set_segment_desc
/* 800F8540 000F5340  3B 7B 00 18 */	addi r27, r27, 0x18
/* 800F8544 000F5344  3B BD 00 01 */	addi r29, r29, 0x1
.L_800F8548:
/* 800F8548 000F5348  80 1C 00 04 */	lwz r0, 0x4(r28)
/* 800F854C 000F534C  7C 1D 00 00 */	cmpw r29, r0
/* 800F8550 000F5350  41 80 FF C4 */	blt .L_800F8514
/* 800F8554 000F5354  88 1F 01 2C */	lbz r0, 0x12c(r31)
/* 800F8558 000F5358  38 60 00 00 */	li r3, 0x0
/* 800F855C 000F535C  50 60 2E B4 */	rlwimi r0, r3, 5, 26, 26
/* 800F8560 000F5360  98 1F 01 2C */	stb r0, 0x12c(r31)
.L_800F8564:
/* 800F8564 000F5364  39 61 00 20 */	addi r11, r1, 0x20
/* 800F8568 000F5368  48 2B 56 39 */	bl _restgpr_27
/* 800F856C 000F536C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F8570 000F5370  7C 08 03 A6 */	mtlr r0
/* 800F8574 000F5374  38 21 00 20 */	addi r1, r1, 0x20
/* 800F8578 000F5378  4E 80 00 20 */	blr
.endfn kar_gryakulib_init_clobject_handle

# .text:0xB18 | 0x800F857C | size: 0x24
.fn kar_gryakulib_free_clobject_handle, global
/* 800F857C 000F537C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F8580 000F5380  7C 08 02 A6 */	mflr r0
/* 800F8584 000F5384  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F8588 000F5388  80 63 00 EC */	lwz r3, 0xec(r3)
/* 800F858C 000F538C  48 09 3D 59 */	bl kar_collision_object_free_handle
/* 800F8590 000F5390  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F8594 000F5394  7C 08 03 A6 */	mtlr r0
/* 800F8598 000F5398  38 21 00 10 */	addi r1, r1, 0x10
/* 800F859C 000F539C  4E 80 00 20 */	blr
.endfn kar_gryakulib_free_clobject_handle

# .text:0xB3C | 0x800F85A0 | size: 0x5C
.fn kar_gryakulib_register_global_list28_clobjects, global
/* 800F85A0 000F53A0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F85A4 000F53A4  7C 08 02 A6 */	mflr r0
/* 800F85A8 000F53A8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F85AC 000F53AC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F85B0 000F53B0  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800F85B4 000F53B4  7C 7E 1B 78 */	mr r30, r3
/* 800F85B8 000F53B8  80 8D 12 54 */	lwz r4, lbl_805DE334@sda21(r0)
/* 800F85BC 000F53BC  83 E4 00 28 */	lwz r31, 0x28(r4)
/* 800F85C0 000F53C0  48 00 00 1C */	b .L_800F85DC
.L_800F85C4:
/* 800F85C4 000F53C4  7F E3 FB 78 */	mr r3, r31
/* 800F85C8 000F53C8  48 09 A1 C1 */	bl fn_80192788
/* 800F85CC 000F53CC  7C 64 1B 78 */	mr r4, r3
/* 800F85D0 000F53D0  80 7E 00 EC */	lwz r3, 0xec(r30)
/* 800F85D4 000F53D4  48 09 4C B1 */	bl kar_clobject__near_8018d284
/* 800F85D8 000F53D8  83 FF 00 08 */	lwz r31, 0x8(r31)
.L_800F85DC:
/* 800F85DC 000F53DC  28 1F 00 00 */	cmplwi r31, 0x0
/* 800F85E0 000F53E0  40 82 FF E4 */	bne .L_800F85C4
/* 800F85E4 000F53E4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F85E8 000F53E8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F85EC 000F53EC  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800F85F0 000F53F0  7C 08 03 A6 */	mtlr r0
/* 800F85F4 000F53F4  38 21 00 10 */	addi r1, r1, 0x10
/* 800F85F8 000F53F8  4E 80 00 20 */	blr
.endfn kar_gryakulib_register_global_list28_clobjects

# .text:0xB98 | 0x800F85FC | size: 0x5C
.fn kar_gryakulib_register_global_list24_clobjects, global
/* 800F85FC 000F53FC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F8600 000F5400  7C 08 02 A6 */	mflr r0
/* 800F8604 000F5404  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F8608 000F5408  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F860C 000F540C  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800F8610 000F5410  7C 7E 1B 78 */	mr r30, r3
/* 800F8614 000F5414  80 8D 12 54 */	lwz r4, lbl_805DE334@sda21(r0)
/* 800F8618 000F5418  83 E4 00 24 */	lwz r31, 0x24(r4)
/* 800F861C 000F541C  48 00 00 1C */	b .L_800F8638
.L_800F8620:
/* 800F8620 000F5420  7F E3 FB 78 */	mr r3, r31
/* 800F8624 000F5424  48 0D 00 3D */	bl fn_801C8660
/* 800F8628 000F5428  7C 64 1B 78 */	mr r4, r3
/* 800F862C 000F542C  80 7E 00 EC */	lwz r3, 0xec(r30)
/* 800F8630 000F5430  48 09 4C 55 */	bl kar_clobject__near_8018d284
/* 800F8634 000F5434  83 FF 00 08 */	lwz r31, 0x8(r31)
.L_800F8638:
/* 800F8638 000F5438  28 1F 00 00 */	cmplwi r31, 0x0
/* 800F863C 000F543C  40 82 FF E4 */	bne .L_800F8620
/* 800F8640 000F5440  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F8644 000F5444  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F8648 000F5448  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800F864C 000F544C  7C 08 03 A6 */	mtlr r0
/* 800F8650 000F5450  38 21 00 10 */	addi r1, r1, 0x10
/* 800F8654 000F5454  4E 80 00 20 */	blr
.endfn kar_gryakulib_register_global_list24_clobjects

# .text:0xBF4 | 0x800F8658 | size: 0x5C
.fn kar_gryakulib_register_wneffect_clobjects, global
/* 800F8658 000F5458  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F865C 000F545C  7C 08 02 A6 */	mflr r0
/* 800F8660 000F5460  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F8664 000F5464  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F8668 000F5468  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800F866C 000F546C  7C 7E 1B 78 */	mr r30, r3
/* 800F8670 000F5470  80 8D 12 54 */	lwz r4, lbl_805DE334@sda21(r0)
/* 800F8674 000F5474  83 E4 00 38 */	lwz r31, 0x38(r4)
/* 800F8678 000F5478  48 00 00 1C */	b .L_800F8694
.L_800F867C:
/* 800F867C 000F547C  7F E3 FB 78 */	mr r3, r31
/* 800F8680 000F5480  48 12 AA A1 */	bl kar_wneffect__near_80223120
/* 800F8684 000F5484  7C 64 1B 78 */	mr r4, r3
/* 800F8688 000F5488  80 7E 00 EC */	lwz r3, 0xec(r30)
/* 800F868C 000F548C  48 09 4B F9 */	bl kar_clobject__near_8018d284
/* 800F8690 000F5490  83 FF 00 08 */	lwz r31, 0x8(r31)
.L_800F8694:
/* 800F8694 000F5494  28 1F 00 00 */	cmplwi r31, 0x0
/* 800F8698 000F5498  40 82 FF E4 */	bne .L_800F867C
/* 800F869C 000F549C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F86A0 000F54A0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F86A4 000F54A4  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800F86A8 000F54A8  7C 08 03 A6 */	mtlr r0
/* 800F86AC 000F54AC  38 21 00 10 */	addi r1, r1, 0x10
/* 800F86B0 000F54B0  4E 80 00 20 */	blr
.endfn kar_gryakulib_register_wneffect_clobjects

# .text:0xC50 | 0x800F86B4 | size: 0xA8
.fn kar_gryakulib_update_clobject_damage_source, global
/* 800F86B4 000F54B4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F86B8 000F54B8  7C 08 02 A6 */	mflr r0
/* 800F86BC 000F54BC  C0 02 91 28 */	lfs f0, lbl_805DF828@sda21(r0)
/* 800F86C0 000F54C0  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F86C4 000F54C4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F86C8 000F54C8  7C 7F 1B 78 */	mr r31, r3
/* 800F86CC 000F54CC  80 63 00 EC */	lwz r3, 0xec(r3)
/* 800F86D0 000F54D0  C0 23 00 24 */	lfs f1, 0x24(r3)
/* 800F86D4 000F54D4  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 800F86D8 000F54D8  41 82 00 70 */	beq .L_800F8748
/* 800F86DC 000F54DC  80 83 00 1C */	lwz r4, 0x1c(r3)
/* 800F86E0 000F54E0  48 09 54 31 */	bl kar_clobject_get_damage_log_entry
/* 800F86E4 000F54E4  80 63 00 00 */	lwz r3, 0x0(r3)
/* 800F86E8 000F54E8  80 03 00 00 */	lwz r0, 0x0(r3)
/* 800F86EC 000F54EC  80 63 00 04 */	lwz r3, 0x4(r3)
/* 800F86F0 000F54F0  2C 00 00 03 */	cmpwi r0, 0x3
/* 800F86F4 000F54F4  41 82 00 44 */	beq .L_800F8738
/* 800F86F8 000F54F8  40 80 00 1C */	bge .L_800F8714
/* 800F86FC 000F54FC  2C 00 00 01 */	cmpwi r0, 0x1
/* 800F8700 000F5500  41 82 00 28 */	beq .L_800F8728
/* 800F8704 000F5504  40 80 00 3C */	bge .L_800F8740
/* 800F8708 000F5508  2C 00 00 00 */	cmpwi r0, 0x0
/* 800F870C 000F550C  40 80 00 14 */	bge .L_800F8720
/* 800F8710 000F5510  48 00 00 30 */	b .L_800F8740
.L_800F8714:
/* 800F8714 000F5514  2C 00 00 05 */	cmpwi r0, 0x5
/* 800F8718 000F5518  41 82 00 18 */	beq .L_800F8730
/* 800F871C 000F551C  48 00 00 24 */	b .L_800F8740
.L_800F8720:
/* 800F8720 000F5520  48 09 99 1D */	bl fn_8019203C
/* 800F8724 000F5524  48 00 00 20 */	b .L_800F8744
.L_800F8728:
/* 800F8728 000F5528  48 0C F5 CD */	bl fn_801C7CF4
/* 800F872C 000F552C  48 00 00 18 */	b .L_800F8744
.L_800F8730:
/* 800F8730 000F5530  48 12 A9 95 */	bl kar_wneffect__near_802230c4
/* 800F8734 000F5534  48 00 00 10 */	b .L_800F8744
.L_800F8738:
/* 800F8738 000F5538  38 60 00 05 */	li r3, 0x5
/* 800F873C 000F553C  48 00 00 08 */	b .L_800F8744
.L_800F8740:
/* 800F8740 000F5540  38 60 00 05 */	li r3, 0x5
.L_800F8744:
/* 800F8744 000F5544  90 7F 00 B0 */	stw r3, 0xb0(r31)
.L_800F8748:
/* 800F8748 000F5548  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F874C 000F554C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F8750 000F5550  7C 08 03 A6 */	mtlr r0
/* 800F8754 000F5554  38 21 00 10 */	addi r1, r1, 0x10
/* 800F8758 000F5558  4E 80 00 20 */	blr
.endfn kar_gryakulib_update_clobject_damage_source

# .text:0xCF8 | 0x800F875C | size: 0x24
.fn kar_gryakulib_accumulate_clobject_timer, global
/* 800F875C 000F555C  C0 43 00 AC */	lfs f2, 0xac(r3)
/* 800F8760 000F5560  C0 02 91 30 */	lfs f0, lbl_805DF830@sda21(r0)
/* 800F8764 000F5564  EC 22 08 2A */	fadds f1, f2, f1
/* 800F8768 000F5568  D0 23 00 AC */	stfs f1, 0xac(r3)
/* 800F876C 000F556C  C0 23 00 AC */	lfs f1, 0xac(r3)
/* 800F8770 000F5570  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800F8774 000F5574  4C 81 00 20 */	blelr
/* 800F8778 000F5578  D0 03 00 AC */	stfs f0, 0xac(r3)
/* 800F877C 000F557C  4E 80 00 20 */	blr
.endfn kar_gryakulib_accumulate_clobject_timer

# .text:0xD1C | 0x800F8780 | size: 0x4
.fn kar_gryakulib_noop_callback, global
/* 800F8780 000F5580  4E 80 00 20 */	blr
.endfn kar_gryakulib_noop_callback

# .text:0xD20 | 0x800F8784 | size: 0x60
.fn kar_gryakulib_set_orientation_basis, global
/* 800F8784 000F5584  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F8788 000F5588  7C 08 02 A6 */	mflr r0
/* 800F878C 000F558C  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F8790 000F5590  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F8794 000F5594  7C 9F 23 78 */	mr r31, r4
/* 800F8798 000F5598  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F879C 000F559C  7C 7E 1B 78 */	mr r30, r3
/* 800F87A0 000F55A0  7C A3 2B 78 */	mr r3, r5
/* 800F87A4 000F55A4  38 9E 00 94 */	addi r4, r30, 0x94
/* 800F87A8 000F55A8  4B F6 A4 FD */	bl kar_lbvector_normalize_with_axis_fallback
/* 800F87AC 000F55AC  7F E4 FB 78 */	mr r4, r31
/* 800F87B0 000F55B0  38 7E 00 94 */	addi r3, r30, 0x94
/* 800F87B4 000F55B4  38 A1 00 08 */	addi r5, r1, 0x8
/* 800F87B8 000F55B8  4B F6 A6 19 */	bl kar_lbvector_cross_normalize
/* 800F87BC 000F55BC  38 61 00 08 */	addi r3, r1, 0x8
/* 800F87C0 000F55C0  38 9E 00 94 */	addi r4, r30, 0x94
/* 800F87C4 000F55C4  38 BE 00 88 */	addi r5, r30, 0x88
/* 800F87C8 000F55C8  4B F6 A6 09 */	bl kar_lbvector_cross_normalize
/* 800F87CC 000F55CC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F87D0 000F55D0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F87D4 000F55D4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F87D8 000F55D8  7C 08 03 A6 */	mtlr r0
/* 800F87DC 000F55DC  38 21 00 20 */	addi r1, r1, 0x20
/* 800F87E0 000F55E0  4E 80 00 20 */	blr
.endfn kar_gryakulib_set_orientation_basis

# 0x804A5B60..0x804A5D40 | size: 0x1E0
.data
.balign 8

# .data:0x0 | 0x804A5B60 | size: 0xC
.obj kar_src_gryakulib_c, global
	.string "gryakulib.c"
.endobj kar_src_gryakulib_c

# .data:0xC | 0x804A5B6C | size: 0x22
.obj kar_gryakulib_assert_yakumono_gobj, global
	.string "grYakuCheckGObjYakumono(yakuGObj)"
.endobj kar_gryakulib_assert_yakumono_gobj

# .data:0x2E | 0x804A5B8E | size: 0x2
.obj gap_07_804A5B8E_data, global
.hidden gap_07_804A5B8E_data
	.2byte 0x0000
.endobj gap_07_804A5B8E_data

# .data:0x30 | 0x804A5B90 | size: 0x16
.obj kar_gryakulib_assert_model_data_present, global
	.string "yaku_data->model_data"
.endobj kar_gryakulib_assert_model_data_present

# .data:0x46 | 0x804A5BA6 | size: 0x2
.obj gap_07_804A5BA6_data, global
.hidden gap_07_804A5BA6_data
	.2byte 0x0000
.endobj gap_07_804A5BA6_data

# .data:0x48 | 0x804A5BA8 | size: 0x40
.obj gryaku_common_kind_factory_table, global
	.4byte kar_gryakucommon_create_factory_variant0_bbox
	.4byte kar_gryakucommon_create_factory_variant0_scaled_bbox
	.4byte kar_gryakucommon_create_factory_variant1_bbox
	.4byte kar_gryakucommon_create_factory_variant1_scaled_bbox
	.4byte kar_gryakucommon_create_factory_variant2_bbox
	.4byte kar_gryakucommon_create_factory_variant2_scaled_bbox
	.4byte kar_gryakucommon_create_factory_variant3_bbox
	.4byte kar_gryakucommon_create_factory_variant3_scaled_bbox
	.4byte kar_gryakucommon_create_factory_variant4_bbox
	.4byte kar_gryakucommon_create_factory_variant4_scaled_bbox
	.4byte kar_gryakucommon_create_factory_variant5_bbox
	.4byte kar_gryakucommon_create_factory_variant5_scaled_bbox
	.4byte kar_gryakucommon_create_factory_variant6_bbox
	.4byte kar_gryakucommon_create_factory_variant6_scaled_bbox
	.4byte kar_gryakucommon_create_factory_variant7_bbox
	.4byte kar_gryakucommon_create_factory_variant7_scaled_bbox
.endobj gryaku_common_kind_factory_table

# .data:0x88 | 0x804A5BE8 | size: 0x118
.obj gryaku_kind_function_table, global
	.4byte gryakucommon_factory_variant0_config
	.4byte gryakucommon_factory_variant0_config
	.4byte gryakucommon_factory_variant1_config
	.4byte gryakucommon_factory_variant1_config
	.4byte gryakucommon_factory_variant2_config
	.4byte gryakucommon_factory_variant2_config
	.4byte gryakucommon_factory_variant3_config
	.4byte gryakucommon_factory_variant3_config
	.4byte gryakucommon_factory_variant4_config
	.4byte gryakucommon_factory_variant4_config
	.4byte gryakucommon_factory_variant5_config
	.4byte gryakucommon_factory_variant5_config
	.4byte gryakucommon_factory_variant6_config
	.4byte gryakucommon_factory_variant6_config
	.4byte gryakucommon_factory_variant7_config
	.4byte gryakucommon_factory_variant7_config
	.4byte lbl_804A5EE8
	.4byte lbl_804A5F50
	.4byte lbl_804A5FB0
	.4byte lbl_804A5FD8
	.4byte kar_gryakurecoveryzone_recoveryzone_callback_table_ptr
	.4byte kar_gryakurotjumphill_cooldown_callback_table_ptr
	.4byte kar_gryakubreakrock_kind22_callback_table_ptr
	.4byte kar_gryakubreakhouse_kind23_callback_table_ptr
	.4byte kar_gryakuanimfloor_kind24_callback_table_ptr
	.4byte kar_gryakubreakcoral_kind25_callback_table_ptr
	.4byte kar_gryakubreakcoral_kind26_callback_table_ptr
	.4byte kar_gryakubreakcoral_kind27_callback_table_ptr
	.4byte kar_gryakubreakcoral_kind28_callback_table_ptr
	.4byte kar_gryakubreakcoral_kind29_callback_table_ptr
	.4byte kar_gryakubreakfloor_kind30_breakfan_callback_table_ptr
	.4byte kar_gryakubreakicicle_kind31_callback_table_ptr
	.4byte kar_gryakubreakfloor_kind32_callback_table_ptr
	.4byte kar_gryakubreakcoll_kind33_callback_table_ptr
	.4byte kar_gryakubreakcoll_kind34_callback_table_ptr
	.4byte kar_gryakubreakcoll_kind35_callback_table_ptr
	.4byte kar_gryakubreakhpcoll_kind36_callback_table_ptr
	.4byte kar_gryakubreakhpcoll_kind37_callback_table_ptr
	.4byte kar_gryakubreakhpcoll_kind38_callback_table_ptr
	.4byte kar_gryakupillar_kind39_callback_table_ptr
	.4byte kar_gryakupillar_kind40_callback_table_ptr
	.4byte kar_gryakurecoveryzone_kind41_joint_callback_table_ptr
	.4byte kar_gryakurotjumphill_target_cycle_callback_table_ptr
	.4byte kar_gryakuinvisibleball_restore_callback_table_ptr
	.4byte kar_gryakurisingcube_cube_state_callback_table_ptr
	.4byte kar_gryakurisingcube_controller_callback_table_ptr
	.4byte kar_gryakugondola_kind46_callback_table_ptr
	.4byte kar_gryakugondola_kind47_ground_audio_callback_table_ptr
	.4byte kar_gryakucannon_kind48_callback_table_ptr
	.4byte kar_gryakupushoutwall_kind49_callback_table_ptr
	.4byte kar_gryakupushoutwall_kind50_callback_table_ptr
	.4byte kar_gryakupushoutwall_kind51_callback_table_ptr
	.4byte kar_gryakulighttunnel_kind52_callback_table_ptr
	.4byte kar_gryakupillar_kind53_empty_callback_table_ptr
	.4byte kar_gryakuanimfloor_kind54_callback_table_ptr
	.4byte kar_gryakuanimfloor_kind55_callback_table_ptr
	.4byte kar_gryakubreakcommon_kind56_callback_table_ptr
	.4byte kar_gryakubreakcommon_kind57_lasergate_callback_table_ptr
	.4byte kar_gryakulasergate_kind58_ctrl_callback_table_ptr
	.4byte kar_gryakubreakfloor_kind59_bounce_callback_table_ptr
	.4byte kar_gryakubreakfloor_kind60_callback_table_ptr
	.4byte kar_gryakubreakhpcoll_kind61_callback_table_ptr
	.4byte kar_gryakubreakhpcoll_kind62_callback_table_ptr
	.4byte kar_gryakubreakhpcoll_kind63_callback_table_ptr
	.4byte kar_gryakubreakhpcoll_kind64_callback_table_ptr
	.4byte kar_gryakubreakhpcoll_kind65_callback_table_ptr
	.4byte kar_gryakubreakhpcoll_kind66_callback_table_ptr
	.4byte kar_gryakubreakhpcoll_kind67_callback_table_ptr
	.4byte kar_gryakubreakhpcoll_kind68_callback_table_ptr
	.4byte kar_gryakuwhispywoods_kind69_callback_table_ptr
.endobj gryaku_kind_function_table

# .data:0x1A0 | 0x804A5D00 | size: 0xD
.obj kar_asset_ykcommon_dat, global
	.string "YkCommon.dat"
.endobj kar_asset_ykcommon_dat

# .data:0x1AD | 0x804A5D0D | size: 0x3
.obj gap_07_804A5D0D_data, global
.hidden gap_07_804A5D0D_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A5D0D_data

# .data:0x1B0 | 0x804A5D10 | size: 0xD
.obj kar_asset_yakumono_dat, global
	.string "Yakumono.dat"
.endobj kar_asset_yakumono_dat

# .data:0x1BD | 0x804A5D1D | size: 0x3
.obj gap_07_804A5D1D_data, global
.hidden gap_07_804A5D1D_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A5D1D_data

# .data:0x1C0 | 0x804A5D20 | size: 0xD
.obj kar_asset_ykdata_common_name, global
	.string "ykDataCommon"
.endobj kar_asset_ykdata_common_name

# .data:0x1CD | 0x804A5D2D | size: 0x3
.obj gap_07_804A5D2D_data, global
.hidden gap_07_804A5D2D_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A5D2D_data

# .data:0x1D0 | 0x804A5D30 | size: 0xA
.obj kar_asset_ykdata_all_name, global
	.string "ykDataAll"
.endobj kar_asset_ykdata_all_name

# .data:0x1DA | 0x804A5D3A | size: 0x6
.obj gap_07_804A5D3A_data, global
.hidden gap_07_804A5D3A_data
	.4byte 0x00000000
	.2byte 0x0000
.endobj gap_07_804A5D3A_data

# 0x805D61F8..0x805D6208 | size: 0x10
.section .sdata, "wa"
.balign 8

# .sdata:0x0 | 0x805D61F8 | size: 0x7
.obj kar_srcfile_jobj_h_805d61f8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d61f8

# .sdata:0x7 | 0x805D61FF | size: 0x1
.obj gap_09_805D61FF_sdata, global
.hidden gap_09_805D61FF_sdata
	.byte 0x00
.endobj gap_09_805D61FF_sdata

# .sdata:0x8 | 0x805D6200 | size: 0x5
.obj lbl_805D6200, global
	.string "jobj"
.endobj lbl_805D6200

# .sdata:0xD | 0x805D6205 | size: 0x3
.obj gap_09_805D6205_sdata, global
.hidden gap_09_805D6205_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6205_sdata

# 0x805DF828..0x805DF838 | size: 0x10
.section .sdata2, "a"
.balign 8

# .sdata2:0x0 | 0x805DF828 | size: 0x8
.obj lbl_805DF828, global
	.float 0
	.float 0
.endobj lbl_805DF828

# .sdata2:0x8 | 0x805DF830 | size: 0x8
.obj lbl_805DF830, global
	.float 9999
	.float 0
.endobj lbl_805DF830
