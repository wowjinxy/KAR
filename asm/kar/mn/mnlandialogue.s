.include "macros.inc"
.file "mnlandialogue.c"

# 0x80183A58..0x80185940 | size: 0x1EE8
.text
.balign 4

# .text:0x0 | 0x80183A58 | size: 0xB4
.fn kar_mnlandialogue_project_box0_origin_to_screen, global
/* 80183A58 00180858  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80183A5C 0018085C  7C 08 02 A6 */	mflr r0
/* 80183A60 00180860  90 01 00 24 */	stw r0, 0x24(r1)
/* 80183A64 00180864  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80183A68 00180868  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80183A6C 0018086C  7C 7E 1B 78 */	mr r30, r3
/* 80183A70 00180870  4B FA D7 71 */	bl fn_801311E0
/* 80183A74 00180874  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 80183A78 00180878  28 03 00 00 */	cmplwi r3, 0x0
/* 80183A7C 0018087C  41 82 00 78 */	beq .L_80183AF4
/* 80183A80 00180880  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80183A84 00180884  83 E3 00 0C */	lwz r31, 0xc(r3)
/* 80183A88 00180888  28 1F 00 00 */	cmplwi r31, 0x0
/* 80183A8C 0018088C  40 82 00 14 */	bne .L_80183AA0
/* 80183A90 00180890  38 6D 9D 58 */	li r3, kar_srcfile_jobj_h_805d6e38@sda21
/* 80183A94 00180894  38 80 03 E4 */	li r4, 0x3e4
/* 80183A98 00180898  38 AD 9D 60 */	li r5, lbl_805D6E40@sda21
/* 80183A9C 0018089C  48 2A 4A 1D */	bl __assert
.L_80183AA0:
/* 80183AA0 001808A0  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 80183AA4 001808A4  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 80183AA8 001808A8  90 61 00 08 */	stw r3, 0x8(r1)
/* 80183AAC 001808AC  90 01 00 0C */	stw r0, 0xc(r1)
/* 80183AB0 001808B0  80 1F 00 40 */	lwz r0, 0x40(r31)
/* 80183AB4 001808B4  90 01 00 10 */	stw r0, 0x10(r1)
/* 80183AB8 001808B8  4B FA D7 29 */	bl fn_801311E0
/* 80183ABC 001808BC  80 63 00 08 */	lwz r3, 0x8(r3)
/* 80183AC0 001808C0  28 03 00 00 */	cmplwi r3, 0x0
/* 80183AC4 001808C4  41 82 00 1C */	beq .L_80183AE0
/* 80183AC8 001808C8  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80183ACC 001808CC  7F C5 F3 78 */	mr r5, r30
/* 80183AD0 001808D0  38 81 00 08 */	addi r4, r1, 0x8
/* 80183AD4 001808D4  38 C0 00 00 */	li r6, 0x0
/* 80183AD8 001808D8  4B EE 09 D5 */	bl kar_lbvector_project_world_to_screen
/* 80183ADC 001808DC  48 00 00 18 */	b .L_80183AF4
.L_80183AE0:
/* 80183AE0 001808E0  3C 60 80 4B */	lis r3, kar_src_mnlandialogue_c@ha
/* 80183AE4 001808E4  38 80 00 4F */	li r4, 0x4f
/* 80183AE8 001808E8  38 63 D6 B8 */	addi r3, r3, kar_src_mnlandialogue_c@l
/* 80183AEC 001808EC  38 AD 9D 68 */	li r5, lbl_805D6E48@sda21
/* 80183AF0 001808F0  48 2A 49 C9 */	bl __assert
.L_80183AF4:
/* 80183AF4 001808F4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80183AF8 001808F8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80183AFC 001808FC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80183B00 00180900  7C 08 03 A6 */	mtlr r0
/* 80183B04 00180904  38 21 00 20 */	addi r1, r1, 0x20
/* 80183B08 00180908  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_project_box0_origin_to_screen

# .text:0xB4 | 0x80183B0C | size: 0xB4
.fn kar_mnlandialogue_project_box0_right_edge_to_screen, global
/* 80183B0C 0018090C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80183B10 00180910  7C 08 02 A6 */	mflr r0
/* 80183B14 00180914  90 01 00 24 */	stw r0, 0x24(r1)
/* 80183B18 00180918  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80183B1C 0018091C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80183B20 00180920  7C 7E 1B 78 */	mr r30, r3
/* 80183B24 00180924  4B FA D6 BD */	bl fn_801311E0
/* 80183B28 00180928  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 80183B2C 0018092C  28 03 00 00 */	cmplwi r3, 0x0
/* 80183B30 00180930  41 82 00 78 */	beq .L_80183BA8
/* 80183B34 00180934  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80183B38 00180938  83 E3 00 10 */	lwz r31, 0x10(r3)
/* 80183B3C 0018093C  28 1F 00 00 */	cmplwi r31, 0x0
/* 80183B40 00180940  40 82 00 14 */	bne .L_80183B54
/* 80183B44 00180944  38 6D 9D 58 */	li r3, kar_srcfile_jobj_h_805d6e38@sda21
/* 80183B48 00180948  38 80 03 E4 */	li r4, 0x3e4
/* 80183B4C 0018094C  38 AD 9D 60 */	li r5, lbl_805D6E40@sda21
/* 80183B50 00180950  48 2A 49 69 */	bl __assert
.L_80183B54:
/* 80183B54 00180954  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 80183B58 00180958  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 80183B5C 0018095C  90 61 00 08 */	stw r3, 0x8(r1)
/* 80183B60 00180960  90 01 00 0C */	stw r0, 0xc(r1)
/* 80183B64 00180964  80 1F 00 40 */	lwz r0, 0x40(r31)
/* 80183B68 00180968  90 01 00 10 */	stw r0, 0x10(r1)
/* 80183B6C 0018096C  4B FA D6 75 */	bl fn_801311E0
/* 80183B70 00180970  80 63 00 08 */	lwz r3, 0x8(r3)
/* 80183B74 00180974  28 03 00 00 */	cmplwi r3, 0x0
/* 80183B78 00180978  41 82 00 1C */	beq .L_80183B94
/* 80183B7C 0018097C  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80183B80 00180980  7F C5 F3 78 */	mr r5, r30
/* 80183B84 00180984  38 81 00 08 */	addi r4, r1, 0x8
/* 80183B88 00180988  38 C0 00 00 */	li r6, 0x0
/* 80183B8C 0018098C  4B EE 09 21 */	bl kar_lbvector_project_world_to_screen
/* 80183B90 00180990  48 00 00 18 */	b .L_80183BA8
.L_80183B94:
/* 80183B94 00180994  3C 60 80 4B */	lis r3, kar_src_mnlandialogue_c@ha
/* 80183B98 00180998  38 80 00 4F */	li r4, 0x4f
/* 80183B9C 0018099C  38 63 D6 B8 */	addi r3, r3, kar_src_mnlandialogue_c@l
/* 80183BA0 001809A0  38 AD 9D 68 */	li r5, lbl_805D6E48@sda21
/* 80183BA4 001809A4  48 2A 49 15 */	bl __assert
.L_80183BA8:
/* 80183BA8 001809A8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80183BAC 001809AC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80183BB0 001809B0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80183BB4 001809B4  7C 08 03 A6 */	mtlr r0
/* 80183BB8 001809B8  38 21 00 20 */	addi r1, r1, 0x20
/* 80183BBC 001809BC  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_project_box0_right_edge_to_screen

# .text:0x168 | 0x80183BC0 | size: 0xB4
.fn kar_mnlandialogue_project_box0_bottom_edge_to_screen, global
/* 80183BC0 001809C0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80183BC4 001809C4  7C 08 02 A6 */	mflr r0
/* 80183BC8 001809C8  90 01 00 24 */	stw r0, 0x24(r1)
/* 80183BCC 001809CC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80183BD0 001809D0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80183BD4 001809D4  7C 7E 1B 78 */	mr r30, r3
/* 80183BD8 001809D8  4B FA D6 09 */	bl fn_801311E0
/* 80183BDC 001809DC  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 80183BE0 001809E0  28 03 00 00 */	cmplwi r3, 0x0
/* 80183BE4 001809E4  41 82 00 78 */	beq .L_80183C5C
/* 80183BE8 001809E8  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80183BEC 001809EC  83 E3 00 14 */	lwz r31, 0x14(r3)
/* 80183BF0 001809F0  28 1F 00 00 */	cmplwi r31, 0x0
/* 80183BF4 001809F4  40 82 00 14 */	bne .L_80183C08
/* 80183BF8 001809F8  38 6D 9D 58 */	li r3, kar_srcfile_jobj_h_805d6e38@sda21
/* 80183BFC 001809FC  38 80 03 E4 */	li r4, 0x3e4
/* 80183C00 00180A00  38 AD 9D 60 */	li r5, lbl_805D6E40@sda21
/* 80183C04 00180A04  48 2A 48 B5 */	bl __assert
.L_80183C08:
/* 80183C08 00180A08  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 80183C0C 00180A0C  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 80183C10 00180A10  90 61 00 08 */	stw r3, 0x8(r1)
/* 80183C14 00180A14  90 01 00 0C */	stw r0, 0xc(r1)
/* 80183C18 00180A18  80 1F 00 40 */	lwz r0, 0x40(r31)
/* 80183C1C 00180A1C  90 01 00 10 */	stw r0, 0x10(r1)
/* 80183C20 00180A20  4B FA D5 C1 */	bl fn_801311E0
/* 80183C24 00180A24  80 63 00 08 */	lwz r3, 0x8(r3)
/* 80183C28 00180A28  28 03 00 00 */	cmplwi r3, 0x0
/* 80183C2C 00180A2C  41 82 00 1C */	beq .L_80183C48
/* 80183C30 00180A30  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80183C34 00180A34  7F C5 F3 78 */	mr r5, r30
/* 80183C38 00180A38  38 81 00 08 */	addi r4, r1, 0x8
/* 80183C3C 00180A3C  38 C0 00 00 */	li r6, 0x0
/* 80183C40 00180A40  4B EE 08 6D */	bl kar_lbvector_project_world_to_screen
/* 80183C44 00180A44  48 00 00 18 */	b .L_80183C5C
.L_80183C48:
/* 80183C48 00180A48  3C 60 80 4B */	lis r3, kar_src_mnlandialogue_c@ha
/* 80183C4C 00180A4C  38 80 00 4F */	li r4, 0x4f
/* 80183C50 00180A50  38 63 D6 B8 */	addi r3, r3, kar_src_mnlandialogue_c@l
/* 80183C54 00180A54  38 AD 9D 68 */	li r5, lbl_805D6E48@sda21
/* 80183C58 00180A58  48 2A 48 61 */	bl __assert
.L_80183C5C:
/* 80183C5C 00180A5C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80183C60 00180A60  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80183C64 00180A64  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80183C68 00180A68  7C 08 03 A6 */	mtlr r0
/* 80183C6C 00180A6C  38 21 00 20 */	addi r1, r1, 0x20
/* 80183C70 00180A70  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_project_box0_bottom_edge_to_screen

# .text:0x21C | 0x80183C74 | size: 0x40
.fn kar_mnlandialogue_get_box1_screen_width, global
/* 80183C74 00180A74  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80183C78 00180A78  7C 08 02 A6 */	mflr r0
/* 80183C7C 00180A7C  90 01 00 24 */	stw r0, 0x24(r1)
/* 80183C80 00180A80  38 61 00 14 */	addi r3, r1, 0x14
/* 80183C84 00180A84  48 00 00 71 */	bl kar_mnlandialogue_project_box1_origin_to_screen
/* 80183C88 00180A88  38 61 00 08 */	addi r3, r1, 0x8
/* 80183C8C 00180A8C  48 00 01 1D */	bl kar_mnlandialogue_project_box1_right_edge_to_screen
/* 80183C90 00180A90  C0 21 00 08 */	lfs f1, 0x8(r1)
/* 80183C94 00180A94  C0 01 00 14 */	lfs f0, 0x14(r1)
/* 80183C98 00180A98  EC 01 00 28 */	fsubs f0, f1, f0
/* 80183C9C 00180A9C  FC 00 02 10 */	fabs f0, f0
/* 80183CA0 00180AA0  FC 20 00 18 */	frsp f1, f0
/* 80183CA4 00180AA4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80183CA8 00180AA8  7C 08 03 A6 */	mtlr r0
/* 80183CAC 00180AAC  38 21 00 20 */	addi r1, r1, 0x20
/* 80183CB0 00180AB0  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_get_box1_screen_width

# .text:0x25C | 0x80183CB4 | size: 0x40
.fn kar_mnlandialogue_get_box1_screen_height, global
/* 80183CB4 00180AB4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80183CB8 00180AB8  7C 08 02 A6 */	mflr r0
/* 80183CBC 00180ABC  90 01 00 24 */	stw r0, 0x24(r1)
/* 80183CC0 00180AC0  38 61 00 14 */	addi r3, r1, 0x14
/* 80183CC4 00180AC4  48 00 00 31 */	bl kar_mnlandialogue_project_box1_origin_to_screen
/* 80183CC8 00180AC8  38 61 00 08 */	addi r3, r1, 0x8
/* 80183CCC 00180ACC  48 00 01 91 */	bl kar_mnlandialogue_project_box1_bottom_edge_to_screen
/* 80183CD0 00180AD0  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 80183CD4 00180AD4  C0 01 00 18 */	lfs f0, 0x18(r1)
/* 80183CD8 00180AD8  EC 01 00 28 */	fsubs f0, f1, f0
/* 80183CDC 00180ADC  FC 00 02 10 */	fabs f0, f0
/* 80183CE0 00180AE0  FC 20 00 18 */	frsp f1, f0
/* 80183CE4 00180AE4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80183CE8 00180AE8  7C 08 03 A6 */	mtlr r0
/* 80183CEC 00180AEC  38 21 00 20 */	addi r1, r1, 0x20
/* 80183CF0 00180AF0  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_get_box1_screen_height

# .text:0x29C | 0x80183CF4 | size: 0xB4
.fn kar_mnlandialogue_project_box1_origin_to_screen, global
/* 80183CF4 00180AF4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80183CF8 00180AF8  7C 08 02 A6 */	mflr r0
/* 80183CFC 00180AFC  90 01 00 24 */	stw r0, 0x24(r1)
/* 80183D00 00180B00  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80183D04 00180B04  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80183D08 00180B08  7C 7E 1B 78 */	mr r30, r3
/* 80183D0C 00180B0C  4B FA D4 D5 */	bl fn_801311E0
/* 80183D10 00180B10  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 80183D14 00180B14  28 03 00 00 */	cmplwi r3, 0x0
/* 80183D18 00180B18  41 82 00 78 */	beq .L_80183D90
/* 80183D1C 00180B1C  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80183D20 00180B20  83 E3 00 18 */	lwz r31, 0x18(r3)
/* 80183D24 00180B24  28 1F 00 00 */	cmplwi r31, 0x0
/* 80183D28 00180B28  40 82 00 14 */	bne .L_80183D3C
/* 80183D2C 00180B2C  38 6D 9D 58 */	li r3, kar_srcfile_jobj_h_805d6e38@sda21
/* 80183D30 00180B30  38 80 03 E4 */	li r4, 0x3e4
/* 80183D34 00180B34  38 AD 9D 60 */	li r5, lbl_805D6E40@sda21
/* 80183D38 00180B38  48 2A 47 81 */	bl __assert
.L_80183D3C:
/* 80183D3C 00180B3C  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 80183D40 00180B40  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 80183D44 00180B44  90 61 00 08 */	stw r3, 0x8(r1)
/* 80183D48 00180B48  90 01 00 0C */	stw r0, 0xc(r1)
/* 80183D4C 00180B4C  80 1F 00 40 */	lwz r0, 0x40(r31)
/* 80183D50 00180B50  90 01 00 10 */	stw r0, 0x10(r1)
/* 80183D54 00180B54  4B FA D4 8D */	bl fn_801311E0
/* 80183D58 00180B58  80 63 00 08 */	lwz r3, 0x8(r3)
/* 80183D5C 00180B5C  28 03 00 00 */	cmplwi r3, 0x0
/* 80183D60 00180B60  41 82 00 1C */	beq .L_80183D7C
/* 80183D64 00180B64  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80183D68 00180B68  7F C5 F3 78 */	mr r5, r30
/* 80183D6C 00180B6C  38 81 00 08 */	addi r4, r1, 0x8
/* 80183D70 00180B70  38 C0 00 00 */	li r6, 0x0
/* 80183D74 00180B74  4B EE 07 39 */	bl kar_lbvector_project_world_to_screen
/* 80183D78 00180B78  48 00 00 18 */	b .L_80183D90
.L_80183D7C:
/* 80183D7C 00180B7C  3C 60 80 4B */	lis r3, kar_src_mnlandialogue_c@ha
/* 80183D80 00180B80  38 80 00 4F */	li r4, 0x4f
/* 80183D84 00180B84  38 63 D6 B8 */	addi r3, r3, kar_src_mnlandialogue_c@l
/* 80183D88 00180B88  38 AD 9D 68 */	li r5, lbl_805D6E48@sda21
/* 80183D8C 00180B8C  48 2A 47 2D */	bl __assert
.L_80183D90:
/* 80183D90 00180B90  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80183D94 00180B94  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80183D98 00180B98  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80183D9C 00180B9C  7C 08 03 A6 */	mtlr r0
/* 80183DA0 00180BA0  38 21 00 20 */	addi r1, r1, 0x20
/* 80183DA4 00180BA4  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_project_box1_origin_to_screen

# .text:0x350 | 0x80183DA8 | size: 0xB4
.fn kar_mnlandialogue_project_box1_right_edge_to_screen, global
/* 80183DA8 00180BA8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80183DAC 00180BAC  7C 08 02 A6 */	mflr r0
/* 80183DB0 00180BB0  90 01 00 24 */	stw r0, 0x24(r1)
/* 80183DB4 00180BB4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80183DB8 00180BB8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80183DBC 00180BBC  7C 7E 1B 78 */	mr r30, r3
/* 80183DC0 00180BC0  4B FA D4 21 */	bl fn_801311E0
/* 80183DC4 00180BC4  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 80183DC8 00180BC8  28 03 00 00 */	cmplwi r3, 0x0
/* 80183DCC 00180BCC  41 82 00 78 */	beq .L_80183E44
/* 80183DD0 00180BD0  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80183DD4 00180BD4  83 E3 00 1C */	lwz r31, 0x1c(r3)
/* 80183DD8 00180BD8  28 1F 00 00 */	cmplwi r31, 0x0
/* 80183DDC 00180BDC  40 82 00 14 */	bne .L_80183DF0
/* 80183DE0 00180BE0  38 6D 9D 58 */	li r3, kar_srcfile_jobj_h_805d6e38@sda21
/* 80183DE4 00180BE4  38 80 03 E4 */	li r4, 0x3e4
/* 80183DE8 00180BE8  38 AD 9D 60 */	li r5, lbl_805D6E40@sda21
/* 80183DEC 00180BEC  48 2A 46 CD */	bl __assert
.L_80183DF0:
/* 80183DF0 00180BF0  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 80183DF4 00180BF4  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 80183DF8 00180BF8  90 61 00 08 */	stw r3, 0x8(r1)
/* 80183DFC 00180BFC  90 01 00 0C */	stw r0, 0xc(r1)
/* 80183E00 00180C00  80 1F 00 40 */	lwz r0, 0x40(r31)
/* 80183E04 00180C04  90 01 00 10 */	stw r0, 0x10(r1)
/* 80183E08 00180C08  4B FA D3 D9 */	bl fn_801311E0
/* 80183E0C 00180C0C  80 63 00 08 */	lwz r3, 0x8(r3)
/* 80183E10 00180C10  28 03 00 00 */	cmplwi r3, 0x0
/* 80183E14 00180C14  41 82 00 1C */	beq .L_80183E30
/* 80183E18 00180C18  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80183E1C 00180C1C  7F C5 F3 78 */	mr r5, r30
/* 80183E20 00180C20  38 81 00 08 */	addi r4, r1, 0x8
/* 80183E24 00180C24  38 C0 00 00 */	li r6, 0x0
/* 80183E28 00180C28  4B EE 06 85 */	bl kar_lbvector_project_world_to_screen
/* 80183E2C 00180C2C  48 00 00 18 */	b .L_80183E44
.L_80183E30:
/* 80183E30 00180C30  3C 60 80 4B */	lis r3, kar_src_mnlandialogue_c@ha
/* 80183E34 00180C34  38 80 00 4F */	li r4, 0x4f
/* 80183E38 00180C38  38 63 D6 B8 */	addi r3, r3, kar_src_mnlandialogue_c@l
/* 80183E3C 00180C3C  38 AD 9D 68 */	li r5, lbl_805D6E48@sda21
/* 80183E40 00180C40  48 2A 46 79 */	bl __assert
.L_80183E44:
/* 80183E44 00180C44  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80183E48 00180C48  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80183E4C 00180C4C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80183E50 00180C50  7C 08 03 A6 */	mtlr r0
/* 80183E54 00180C54  38 21 00 20 */	addi r1, r1, 0x20
/* 80183E58 00180C58  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_project_box1_right_edge_to_screen

# .text:0x404 | 0x80183E5C | size: 0xB4
.fn kar_mnlandialogue_project_box1_bottom_edge_to_screen, global
/* 80183E5C 00180C5C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80183E60 00180C60  7C 08 02 A6 */	mflr r0
/* 80183E64 00180C64  90 01 00 24 */	stw r0, 0x24(r1)
/* 80183E68 00180C68  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80183E6C 00180C6C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80183E70 00180C70  7C 7E 1B 78 */	mr r30, r3
/* 80183E74 00180C74  4B FA D3 6D */	bl fn_801311E0
/* 80183E78 00180C78  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 80183E7C 00180C7C  28 03 00 00 */	cmplwi r3, 0x0
/* 80183E80 00180C80  41 82 00 78 */	beq .L_80183EF8
/* 80183E84 00180C84  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80183E88 00180C88  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 80183E8C 00180C8C  28 1F 00 00 */	cmplwi r31, 0x0
/* 80183E90 00180C90  40 82 00 14 */	bne .L_80183EA4
/* 80183E94 00180C94  38 6D 9D 58 */	li r3, kar_srcfile_jobj_h_805d6e38@sda21
/* 80183E98 00180C98  38 80 03 E4 */	li r4, 0x3e4
/* 80183E9C 00180C9C  38 AD 9D 60 */	li r5, lbl_805D6E40@sda21
/* 80183EA0 00180CA0  48 2A 46 19 */	bl __assert
.L_80183EA4:
/* 80183EA4 00180CA4  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 80183EA8 00180CA8  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 80183EAC 00180CAC  90 61 00 08 */	stw r3, 0x8(r1)
/* 80183EB0 00180CB0  90 01 00 0C */	stw r0, 0xc(r1)
/* 80183EB4 00180CB4  80 1F 00 40 */	lwz r0, 0x40(r31)
/* 80183EB8 00180CB8  90 01 00 10 */	stw r0, 0x10(r1)
/* 80183EBC 00180CBC  4B FA D3 25 */	bl fn_801311E0
/* 80183EC0 00180CC0  80 63 00 08 */	lwz r3, 0x8(r3)
/* 80183EC4 00180CC4  28 03 00 00 */	cmplwi r3, 0x0
/* 80183EC8 00180CC8  41 82 00 1C */	beq .L_80183EE4
/* 80183ECC 00180CCC  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80183ED0 00180CD0  7F C5 F3 78 */	mr r5, r30
/* 80183ED4 00180CD4  38 81 00 08 */	addi r4, r1, 0x8
/* 80183ED8 00180CD8  38 C0 00 00 */	li r6, 0x0
/* 80183EDC 00180CDC  4B EE 05 D1 */	bl kar_lbvector_project_world_to_screen
/* 80183EE0 00180CE0  48 00 00 18 */	b .L_80183EF8
.L_80183EE4:
/* 80183EE4 00180CE4  3C 60 80 4B */	lis r3, kar_src_mnlandialogue_c@ha
/* 80183EE8 00180CE8  38 80 00 4F */	li r4, 0x4f
/* 80183EEC 00180CEC  38 63 D6 B8 */	addi r3, r3, kar_src_mnlandialogue_c@l
/* 80183EF0 00180CF0  38 AD 9D 68 */	li r5, lbl_805D6E48@sda21
/* 80183EF4 00180CF4  48 2A 45 C5 */	bl __assert
.L_80183EF8:
/* 80183EF8 00180CF8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80183EFC 00180CFC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80183F00 00180D00  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80183F04 00180D04  7C 08 03 A6 */	mtlr r0
/* 80183F08 00180D08  38 21 00 20 */	addi r1, r1, 0x20
/* 80183F0C 00180D0C  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_project_box1_bottom_edge_to_screen

# .text:0x4B8 | 0x80183F10 | size: 0xB4
.fn kar_mnlandialogue_project_box2_origin_to_screen, global
/* 80183F10 00180D10  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80183F14 00180D14  7C 08 02 A6 */	mflr r0
/* 80183F18 00180D18  90 01 00 24 */	stw r0, 0x24(r1)
/* 80183F1C 00180D1C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80183F20 00180D20  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80183F24 00180D24  7C 7E 1B 78 */	mr r30, r3
/* 80183F28 00180D28  4B FA D2 B9 */	bl fn_801311E0
/* 80183F2C 00180D2C  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 80183F30 00180D30  28 03 00 00 */	cmplwi r3, 0x0
/* 80183F34 00180D34  41 82 00 78 */	beq .L_80183FAC
/* 80183F38 00180D38  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80183F3C 00180D3C  83 E3 00 20 */	lwz r31, 0x20(r3)
/* 80183F40 00180D40  28 1F 00 00 */	cmplwi r31, 0x0
/* 80183F44 00180D44  40 82 00 14 */	bne .L_80183F58
/* 80183F48 00180D48  38 6D 9D 58 */	li r3, kar_srcfile_jobj_h_805d6e38@sda21
/* 80183F4C 00180D4C  38 80 03 E4 */	li r4, 0x3e4
/* 80183F50 00180D50  38 AD 9D 60 */	li r5, lbl_805D6E40@sda21
/* 80183F54 00180D54  48 2A 45 65 */	bl __assert
.L_80183F58:
/* 80183F58 00180D58  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 80183F5C 00180D5C  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 80183F60 00180D60  90 61 00 08 */	stw r3, 0x8(r1)
/* 80183F64 00180D64  90 01 00 0C */	stw r0, 0xc(r1)
/* 80183F68 00180D68  80 1F 00 40 */	lwz r0, 0x40(r31)
/* 80183F6C 00180D6C  90 01 00 10 */	stw r0, 0x10(r1)
/* 80183F70 00180D70  4B FA D2 71 */	bl fn_801311E0
/* 80183F74 00180D74  80 63 00 08 */	lwz r3, 0x8(r3)
/* 80183F78 00180D78  28 03 00 00 */	cmplwi r3, 0x0
/* 80183F7C 00180D7C  41 82 00 1C */	beq .L_80183F98
/* 80183F80 00180D80  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80183F84 00180D84  7F C5 F3 78 */	mr r5, r30
/* 80183F88 00180D88  38 81 00 08 */	addi r4, r1, 0x8
/* 80183F8C 00180D8C  38 C0 00 00 */	li r6, 0x0
/* 80183F90 00180D90  4B EE 05 1D */	bl kar_lbvector_project_world_to_screen
/* 80183F94 00180D94  48 00 00 18 */	b .L_80183FAC
.L_80183F98:
/* 80183F98 00180D98  3C 60 80 4B */	lis r3, kar_src_mnlandialogue_c@ha
/* 80183F9C 00180D9C  38 80 00 4F */	li r4, 0x4f
/* 80183FA0 00180DA0  38 63 D6 B8 */	addi r3, r3, kar_src_mnlandialogue_c@l
/* 80183FA4 00180DA4  38 AD 9D 68 */	li r5, lbl_805D6E48@sda21
/* 80183FA8 00180DA8  48 2A 45 11 */	bl __assert
.L_80183FAC:
/* 80183FAC 00180DAC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80183FB0 00180DB0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80183FB4 00180DB4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80183FB8 00180DB8  7C 08 03 A6 */	mtlr r0
/* 80183FBC 00180DBC  38 21 00 20 */	addi r1, r1, 0x20
/* 80183FC0 00180DC0  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_project_box2_origin_to_screen

# .text:0x56C | 0x80183FC4 | size: 0x4C
.fn kar_mnlandialogue_request_dialogue_panel_anim0, global
/* 80183FC4 00180DC4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80183FC8 00180DC8  7C 08 02 A6 */	mflr r0
/* 80183FCC 00180DCC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80183FD0 00180DD0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80183FD4 00180DD4  4B FA D2 0D */	bl fn_801311E0
/* 80183FD8 00180DD8  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 80183FDC 00180DDC  28 03 00 00 */	cmplwi r3, 0x0
/* 80183FE0 00180DE0  41 82 00 1C */	beq .L_80183FFC
/* 80183FE4 00180DE4  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80183FE8 00180DE8  C0 22 A7 80 */	lfs f1, lbl_805E0E80@sda21(r0)
/* 80183FEC 00180DEC  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 80183FF0 00180DF0  48 28 52 61 */	bl HSD_JObjReqAnimAll
/* 80183FF4 00180DF4  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 80183FF8 00180DF8  48 28 66 55 */	bl HSD_JObjAnimAll
.L_80183FFC:
/* 80183FFC 00180DFC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184000 00180E00  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80184004 00180E04  7C 08 03 A6 */	mtlr r0
/* 80184008 00180E08  38 21 00 10 */	addi r1, r1, 0x10
/* 8018400C 00180E0C  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_dialogue_panel_anim0

# .text:0x5B8 | 0x80184010 | size: 0x4C
.fn kar_mnlandialogue_request_dialogue_panel_anim1, global
/* 80184010 00180E10  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184014 00180E14  7C 08 02 A6 */	mflr r0
/* 80184018 00180E18  90 01 00 14 */	stw r0, 0x14(r1)
/* 8018401C 00180E1C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80184020 00180E20  4B FA D1 C1 */	bl fn_801311E0
/* 80184024 00180E24  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 80184028 00180E28  28 03 00 00 */	cmplwi r3, 0x0
/* 8018402C 00180E2C  41 82 00 1C */	beq .L_80184048
/* 80184030 00180E30  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80184034 00180E34  C0 22 A7 84 */	lfs f1, lbl_805E0E84@sda21(r0)
/* 80184038 00180E38  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 8018403C 00180E3C  48 28 52 15 */	bl HSD_JObjReqAnimAll
/* 80184040 00180E40  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 80184044 00180E44  48 28 66 09 */	bl HSD_JObjAnimAll
.L_80184048:
/* 80184048 00180E48  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8018404C 00180E4C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80184050 00180E50  7C 08 03 A6 */	mtlr r0
/* 80184054 00180E54  38 21 00 10 */	addi r1, r1, 0x10
/* 80184058 00180E58  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_dialogue_panel_anim1

# .text:0x604 | 0x8018405C | size: 0x4C
.fn kar_mnlandialogue_request_dialogue_panel_anim2, global
/* 8018405C 00180E5C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184060 00180E60  7C 08 02 A6 */	mflr r0
/* 80184064 00180E64  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184068 00180E68  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8018406C 00180E6C  4B FA D1 75 */	bl fn_801311E0
/* 80184070 00180E70  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 80184074 00180E74  28 03 00 00 */	cmplwi r3, 0x0
/* 80184078 00180E78  41 82 00 1C */	beq .L_80184094
/* 8018407C 00180E7C  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80184080 00180E80  C0 22 A7 88 */	lfs f1, lbl_805E0E88@sda21(r0)
/* 80184084 00180E84  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 80184088 00180E88  48 28 51 C9 */	bl HSD_JObjReqAnimAll
/* 8018408C 00180E8C  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 80184090 00180E90  48 28 65 BD */	bl HSD_JObjAnimAll
.L_80184094:
/* 80184094 00180E94  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184098 00180E98  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8018409C 00180E9C  7C 08 03 A6 */	mtlr r0
/* 801840A0 00180EA0  38 21 00 10 */	addi r1, r1, 0x10
/* 801840A4 00180EA4  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_dialogue_panel_anim2

# .text:0x650 | 0x801840A8 | size: 0x4C
.fn kar_mnlandialogue_request_dialogue_panel_anim3, global
/* 801840A8 00180EA8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801840AC 00180EAC  7C 08 02 A6 */	mflr r0
/* 801840B0 00180EB0  90 01 00 14 */	stw r0, 0x14(r1)
/* 801840B4 00180EB4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801840B8 00180EB8  4B FA D1 29 */	bl fn_801311E0
/* 801840BC 00180EBC  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 801840C0 00180EC0  28 03 00 00 */	cmplwi r3, 0x0
/* 801840C4 00180EC4  41 82 00 1C */	beq .L_801840E0
/* 801840C8 00180EC8  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 801840CC 00180ECC  C0 22 A7 8C */	lfs f1, lbl_805E0E8C@sda21(r0)
/* 801840D0 00180ED0  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 801840D4 00180ED4  48 28 51 7D */	bl HSD_JObjReqAnimAll
/* 801840D8 00180ED8  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 801840DC 00180EDC  48 28 65 71 */	bl HSD_JObjAnimAll
.L_801840E0:
/* 801840E0 00180EE0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801840E4 00180EE4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801840E8 00180EE8  7C 08 03 A6 */	mtlr r0
/* 801840EC 00180EEC  38 21 00 10 */	addi r1, r1, 0x10
/* 801840F0 00180EF0  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_dialogue_panel_anim3

# .text:0x69C | 0x801840F4 | size: 0x4C
.fn kar_mnlandialogue_request_dialogue_panel_anim4, global
/* 801840F4 00180EF4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801840F8 00180EF8  7C 08 02 A6 */	mflr r0
/* 801840FC 00180EFC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184100 00180F00  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80184104 00180F04  4B FA D0 DD */	bl fn_801311E0
/* 80184108 00180F08  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 8018410C 00180F0C  28 03 00 00 */	cmplwi r3, 0x0
/* 80184110 00180F10  41 82 00 1C */	beq .L_8018412C
/* 80184114 00180F14  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80184118 00180F18  C0 22 A7 90 */	lfs f1, lbl_805E0E90@sda21(r0)
/* 8018411C 00180F1C  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 80184120 00180F20  48 28 51 31 */	bl HSD_JObjReqAnimAll
/* 80184124 00180F24  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 80184128 00180F28  48 28 65 25 */	bl HSD_JObjAnimAll
.L_8018412C:
/* 8018412C 00180F2C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184130 00180F30  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80184134 00180F34  7C 08 03 A6 */	mtlr r0
/* 80184138 00180F38  38 21 00 10 */	addi r1, r1, 0x10
/* 8018413C 00180F3C  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_dialogue_panel_anim4

# .text:0x6E8 | 0x80184140 | size: 0x5C
.fn kar_mnlandialogue_request_choice_panel_anim0_messages_3_4, global
/* 80184140 00180F40  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184144 00180F44  7C 08 02 A6 */	mflr r0
/* 80184148 00180F48  90 01 00 14 */	stw r0, 0x14(r1)
/* 8018414C 00180F4C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80184150 00180F50  4B FA D0 91 */	bl fn_801311E0
/* 80184154 00180F54  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 80184158 00180F58  28 03 00 00 */	cmplwi r3, 0x0
/* 8018415C 00180F5C  41 82 00 2C */	beq .L_80184188
/* 80184160 00180F60  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80184164 00180F64  C0 22 A7 80 */	lfs f1, lbl_805E0E80@sda21(r0)
/* 80184168 00180F68  80 7F 00 30 */	lwz r3, 0x30(r31)
/* 8018416C 00180F6C  48 28 50 E5 */	bl HSD_JObjReqAnimAll
/* 80184170 00180F70  80 7F 00 30 */	lwz r3, 0x30(r31)
/* 80184174 00180F74  48 28 64 D9 */	bl HSD_JObjAnimAll
/* 80184178 00180F78  38 60 00 03 */	li r3, 0x3
/* 8018417C 00180F7C  4B FF 88 4D */	bl kar_gmlanmenu_set_sis_lan_box2_message_id
/* 80184180 00180F80  38 60 00 04 */	li r3, 0x4
/* 80184184 00180F84  4B FF 88 7D */	bl kar_gmlanmenu_set_sis_lan_box3_message_id
.L_80184188:
/* 80184188 00180F88  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8018418C 00180F8C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80184190 00180F90  7C 08 03 A6 */	mtlr r0
/* 80184194 00180F94  38 21 00 10 */	addi r1, r1, 0x10
/* 80184198 00180F98  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_choice_panel_anim0_messages_3_4

# .text:0x744 | 0x8018419C | size: 0x5C
.fn kar_mnlandialogue_request_choice_panel_anim1_messages_3_4, global
/* 8018419C 00180F9C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801841A0 00180FA0  7C 08 02 A6 */	mflr r0
/* 801841A4 00180FA4  90 01 00 14 */	stw r0, 0x14(r1)
/* 801841A8 00180FA8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801841AC 00180FAC  4B FA D0 35 */	bl fn_801311E0
/* 801841B0 00180FB0  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 801841B4 00180FB4  28 03 00 00 */	cmplwi r3, 0x0
/* 801841B8 00180FB8  41 82 00 2C */	beq .L_801841E4
/* 801841BC 00180FBC  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 801841C0 00180FC0  C0 22 A7 84 */	lfs f1, lbl_805E0E84@sda21(r0)
/* 801841C4 00180FC4  80 7F 00 30 */	lwz r3, 0x30(r31)
/* 801841C8 00180FC8  48 28 50 89 */	bl HSD_JObjReqAnimAll
/* 801841CC 00180FCC  80 7F 00 30 */	lwz r3, 0x30(r31)
/* 801841D0 00180FD0  48 28 64 7D */	bl HSD_JObjAnimAll
/* 801841D4 00180FD4  38 60 00 03 */	li r3, 0x3
/* 801841D8 00180FD8  4B FF 87 F1 */	bl kar_gmlanmenu_set_sis_lan_box2_message_id
/* 801841DC 00180FDC  38 60 00 04 */	li r3, 0x4
/* 801841E0 00180FE0  4B FF 88 21 */	bl kar_gmlanmenu_set_sis_lan_box3_message_id
.L_801841E4:
/* 801841E4 00180FE4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801841E8 00180FE8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801841EC 00180FEC  7C 08 03 A6 */	mtlr r0
/* 801841F0 00180FF0  38 21 00 10 */	addi r1, r1, 0x10
/* 801841F4 00180FF4  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_choice_panel_anim1_messages_3_4

# .text:0x7A0 | 0x801841F8 | size: 0x5C
.fn kar_mnlandialogue_request_choice_panel_anim0_messages_5_6, global
/* 801841F8 00180FF8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801841FC 00180FFC  7C 08 02 A6 */	mflr r0
/* 80184200 00181000  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184204 00181004  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80184208 00181008  4B FA CF D9 */	bl fn_801311E0
/* 8018420C 0018100C  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 80184210 00181010  28 03 00 00 */	cmplwi r3, 0x0
/* 80184214 00181014  41 82 00 2C */	beq .L_80184240
/* 80184218 00181018  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8018421C 0018101C  C0 22 A7 80 */	lfs f1, lbl_805E0E80@sda21(r0)
/* 80184220 00181020  80 7F 00 30 */	lwz r3, 0x30(r31)
/* 80184224 00181024  48 28 50 2D */	bl HSD_JObjReqAnimAll
/* 80184228 00181028  80 7F 00 30 */	lwz r3, 0x30(r31)
/* 8018422C 0018102C  48 28 64 21 */	bl HSD_JObjAnimAll
/* 80184230 00181030  38 60 00 05 */	li r3, 0x5
/* 80184234 00181034  4B FF 87 95 */	bl kar_gmlanmenu_set_sis_lan_box2_message_id
/* 80184238 00181038  38 60 00 06 */	li r3, 0x6
/* 8018423C 0018103C  4B FF 87 C5 */	bl kar_gmlanmenu_set_sis_lan_box3_message_id
.L_80184240:
/* 80184240 00181040  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184244 00181044  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80184248 00181048  7C 08 03 A6 */	mtlr r0
/* 8018424C 0018104C  38 21 00 10 */	addi r1, r1, 0x10
/* 80184250 00181050  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_choice_panel_anim0_messages_5_6

# .text:0x7FC | 0x80184254 | size: 0x5C
.fn kar_mnlandialogue_request_choice_panel_anim1_messages_5_6, global
/* 80184254 00181054  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184258 00181058  7C 08 02 A6 */	mflr r0
/* 8018425C 0018105C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184260 00181060  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80184264 00181064  4B FA CF 7D */	bl fn_801311E0
/* 80184268 00181068  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 8018426C 0018106C  28 03 00 00 */	cmplwi r3, 0x0
/* 80184270 00181070  41 82 00 2C */	beq .L_8018429C
/* 80184274 00181074  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80184278 00181078  C0 22 A7 84 */	lfs f1, lbl_805E0E84@sda21(r0)
/* 8018427C 0018107C  80 7F 00 30 */	lwz r3, 0x30(r31)
/* 80184280 00181080  48 28 4F D1 */	bl HSD_JObjReqAnimAll
/* 80184284 00181084  80 7F 00 30 */	lwz r3, 0x30(r31)
/* 80184288 00181088  48 28 63 C5 */	bl HSD_JObjAnimAll
/* 8018428C 0018108C  38 60 00 05 */	li r3, 0x5
/* 80184290 00181090  4B FF 87 39 */	bl kar_gmlanmenu_set_sis_lan_box2_message_id
/* 80184294 00181094  38 60 00 06 */	li r3, 0x6
/* 80184298 00181098  4B FF 87 69 */	bl kar_gmlanmenu_set_sis_lan_box3_message_id
.L_8018429C:
/* 8018429C 0018109C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801842A0 001810A0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801842A4 001810A4  7C 08 03 A6 */	mtlr r0
/* 801842A8 001810A8  38 21 00 10 */	addi r1, r1, 0x10
/* 801842AC 001810AC  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_choice_panel_anim1_messages_5_6

# .text:0x858 | 0x801842B0 | size: 0x3C
.fn kar_mnlandialogue_hide_choice_child_jobj, global
/* 801842B0 001810B0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801842B4 001810B4  7C 08 02 A6 */	mflr r0
/* 801842B8 001810B8  90 01 00 14 */	stw r0, 0x14(r1)
/* 801842BC 001810BC  4B FA CF 25 */	bl fn_801311E0
/* 801842C0 001810C0  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 801842C4 001810C4  28 03 00 00 */	cmplwi r3, 0x0
/* 801842C8 001810C8  41 82 00 14 */	beq .L_801842DC
/* 801842CC 001810CC  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 801842D0 001810D0  38 80 00 10 */	li r4, 0x10
/* 801842D4 001810D4  80 63 00 30 */	lwz r3, 0x30(r3)
/* 801842D8 001810D8  48 28 7B 29 */	bl HSD_JObjSetFlagsAll
.L_801842DC:
/* 801842DC 001810DC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801842E0 001810E0  7C 08 03 A6 */	mtlr r0
/* 801842E4 001810E4  38 21 00 10 */	addi r1, r1, 0x10
/* 801842E8 001810E8  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_hide_choice_child_jobj

# .text:0x894 | 0x801842EC | size: 0x50
.fn kar_mnlandialogue_hide_panel_show_choice_child_jobj, global
/* 801842EC 001810EC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801842F0 001810F0  7C 08 02 A6 */	mflr r0
/* 801842F4 001810F4  90 01 00 14 */	stw r0, 0x14(r1)
/* 801842F8 001810F8  4B FA CE E9 */	bl fn_801311E0
/* 801842FC 001810FC  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 80184300 00181100  28 03 00 00 */	cmplwi r3, 0x0
/* 80184304 00181104  41 82 00 28 */	beq .L_8018432C
/* 80184308 00181108  4B FB 47 A9 */	bl kar_menu_gobj_userdata_hide
/* 8018430C 0018110C  4B FA CE D5 */	bl fn_801311E0
/* 80184310 00181110  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 80184314 00181114  28 03 00 00 */	cmplwi r3, 0x0
/* 80184318 00181118  41 82 00 14 */	beq .L_8018432C
/* 8018431C 0018111C  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80184320 00181120  38 80 00 10 */	li r4, 0x10
/* 80184324 00181124  80 63 00 30 */	lwz r3, 0x30(r3)
/* 80184328 00181128  48 28 7E 4D */	bl HSD_JObjClearFlagsAll
.L_8018432C:
/* 8018432C 0018112C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184330 00181130  7C 08 03 A6 */	mtlr r0
/* 80184334 00181134  38 21 00 10 */	addi r1, r1, 0x10
/* 80184338 00181138  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_hide_panel_show_choice_child_jobj

# .text:0x8E4 | 0x8018433C | size: 0x30
.fn kar_mnlandialogue_show_panel, global
/* 8018433C 0018113C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184340 00181140  7C 08 02 A6 */	mflr r0
/* 80184344 00181144  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184348 00181148  4B FA CE 99 */	bl fn_801311E0
/* 8018434C 0018114C  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 80184350 00181150  28 03 00 00 */	cmplwi r3, 0x0
/* 80184354 00181154  41 82 00 08 */	beq .L_8018435C
/* 80184358 00181158  4B FB 47 71 */	bl kar_menu_gobj_userdata_show
.L_8018435C:
/* 8018435C 0018115C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184360 00181160  7C 08 03 A6 */	mtlr r0
/* 80184364 00181164  38 21 00 10 */	addi r1, r1, 0x10
/* 80184368 00181168  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_show_panel

# .text:0x914 | 0x8018436C | size: 0x4
.fn fn_8018436C, global
/* 8018436C 0018116C  4E 80 00 20 */	blr
.endfn fn_8018436C

# .text:0x918 | 0x80184370 | size: 0x4C
.fn kar_mnlandialogue_load_dialogue_scene_models, global
/* 80184370 00181170  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184374 00181174  7C 08 02 A6 */	mflr r0
/* 80184378 00181178  90 01 00 14 */	stw r0, 0x14(r1)
/* 8018437C 0018117C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80184380 00181180  4B FA CE 61 */	bl fn_801311E0
/* 80184384 00181184  7C 7F 1B 78 */	mr r31, r3
/* 80184388 00181188  4B FB 4D 15 */	bl fn_8013909C
/* 8018438C 0018118C  3C 80 80 4B */	lis r4, kar_mnlandialogue_scene_models_name@ha
/* 80184390 00181190  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80184394 00181194  38 A4 D6 C8 */	addi r5, r4, kar_mnlandialogue_scene_models_name@l
/* 80184398 00181198  38 C0 00 00 */	li r6, 0x0
/* 8018439C 0018119C  38 9F 11 64 */	addi r4, r31, 0x1164
/* 801843A0 001811A0  4C C6 31 82 */	crclr cr1eq
/* 801843A4 001811A4  4B ED 51 7D */	bl kar_lbarchive__near_80059520
/* 801843A8 001811A8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801843AC 001811AC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801843B0 001811B0  7C 08 03 A6 */	mtlr r0
/* 801843B4 001811B4  38 21 00 10 */	addi r1, r1, 0x10
/* 801843B8 001811B8  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_load_dialogue_scene_models

# .text:0x964 | 0x801843BC | size: 0x130
.fn kar_mnlandialogue_create_dialogue_panel_and_cache_child_jobjs, global
/* 801843BC 001811BC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801843C0 001811C0  7C 08 02 A6 */	mflr r0
/* 801843C4 001811C4  90 01 00 24 */	stw r0, 0x24(r1)
/* 801843C8 001811C8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801843CC 001811CC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801843D0 001811D0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 801843D4 001811D4  4B FA CE 0D */	bl fn_801311E0
/* 801843D8 001811D8  7C 7E 1B 78 */	mr r30, r3
/* 801843DC 001811DC  80 63 11 64 */	lwz r3, 0x1164(r3)
/* 801843E0 001811E0  80 63 00 00 */	lwz r3, 0x0(r3)
/* 801843E4 001811E4  80 63 00 00 */	lwz r3, 0x0(r3)
/* 801843E8 001811E8  4B FB 44 C1 */	bl fn_801388A8
/* 801843EC 001811EC  3C 80 80 18 */	lis r4, fn_8018436C@ha
/* 801843F0 001811F0  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 801843F4 001811F4  7C 7D 1B 78 */	mr r29, r3
/* 801843F8 001811F8  38 A0 00 01 */	li r5, 0x1
/* 801843FC 001811FC  38 84 43 6C */	addi r4, r4, fn_8018436C@l
/* 80184400 00181200  48 2A 44 A5 */	bl HSD_GObjProcCreate
/* 80184404 00181204  80 9E 11 64 */	lwz r4, 0x1164(r30)
/* 80184408 00181208  7F E3 FB 78 */	mr r3, r31
/* 8018440C 0018120C  C0 22 A7 80 */	lfs f1, lbl_805E0E80@sda21(r0)
/* 80184410 00181210  80 84 00 00 */	lwz r4, 0x0(r4)
/* 80184414 00181214  C0 42 A7 84 */	lfs f2, lbl_805E0E84@sda21(r0)
/* 80184418 00181218  4B FB 45 C1 */	bl fn_801389D8
/* 8018441C 0018121C  7F A3 EB 78 */	mr r3, r29
/* 80184420 00181220  38 80 00 BA */	li r4, 0xba
/* 80184424 00181224  4B FB 45 DD */	bl kar_diag__80138a00
/* 80184428 00181228  7C 7F 1B 78 */	mr r31, r3
/* 8018442C 0018122C  7F A3 EB 78 */	mr r3, r29
/* 80184430 00181230  38 80 00 02 */	li r4, 0x2
/* 80184434 00181234  4B ED 16 BD */	bl kar_lbairride__near_80055af0
/* 80184438 00181238  90 7F 00 0C */	stw r3, 0xc(r31)
/* 8018443C 0018123C  7F A3 EB 78 */	mr r3, r29
/* 80184440 00181240  38 80 00 03 */	li r4, 0x3
/* 80184444 00181244  4B ED 16 AD */	bl kar_lbairride__near_80055af0
/* 80184448 00181248  90 7F 00 10 */	stw r3, 0x10(r31)
/* 8018444C 0018124C  7F A3 EB 78 */	mr r3, r29
/* 80184450 00181250  38 80 00 04 */	li r4, 0x4
/* 80184454 00181254  4B ED 16 9D */	bl kar_lbairride__near_80055af0
/* 80184458 00181258  90 7F 00 14 */	stw r3, 0x14(r31)
/* 8018445C 0018125C  7F A3 EB 78 */	mr r3, r29
/* 80184460 00181260  38 80 00 05 */	li r4, 0x5
/* 80184464 00181264  4B ED 16 8D */	bl kar_lbairride__near_80055af0
/* 80184468 00181268  90 7F 00 18 */	stw r3, 0x18(r31)
/* 8018446C 0018126C  7F A3 EB 78 */	mr r3, r29
/* 80184470 00181270  38 80 00 06 */	li r4, 0x6
/* 80184474 00181274  4B ED 16 7D */	bl kar_lbairride__near_80055af0
/* 80184478 00181278  90 7F 00 1C */	stw r3, 0x1c(r31)
/* 8018447C 0018127C  7F A3 EB 78 */	mr r3, r29
/* 80184480 00181280  38 80 00 07 */	li r4, 0x7
/* 80184484 00181284  4B ED 16 6D */	bl kar_lbairride__near_80055af0
/* 80184488 00181288  90 7F 00 20 */	stw r3, 0x20(r31)
/* 8018448C 0018128C  7F A3 EB 78 */	mr r3, r29
/* 80184490 00181290  38 80 00 08 */	li r4, 0x8
/* 80184494 00181294  4B ED 16 5D */	bl kar_lbairride__near_80055af0
/* 80184498 00181298  90 7F 00 24 */	stw r3, 0x24(r31)
/* 8018449C 0018129C  7F A3 EB 78 */	mr r3, r29
/* 801844A0 001812A0  38 80 00 09 */	li r4, 0x9
/* 801844A4 001812A4  4B ED 16 4D */	bl kar_lbairride__near_80055af0
/* 801844A8 001812A8  90 7F 00 28 */	stw r3, 0x28(r31)
/* 801844AC 001812AC  7F A3 EB 78 */	mr r3, r29
/* 801844B0 001812B0  38 80 00 0D */	li r4, 0xd
/* 801844B4 001812B4  4B ED 16 3D */	bl kar_lbairride__near_80055af0
/* 801844B8 001812B8  90 7F 00 2C */	stw r3, 0x2c(r31)
/* 801844BC 001812BC  7F A3 EB 78 */	mr r3, r29
/* 801844C0 001812C0  38 80 00 0A */	li r4, 0xa
/* 801844C4 001812C4  4B ED 16 2D */	bl kar_lbairride__near_80055af0
/* 801844C8 001812C8  90 7F 00 30 */	stw r3, 0x30(r31)
/* 801844CC 001812CC  93 BE 11 68 */	stw r29, 0x1168(r30)
/* 801844D0 001812D0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801844D4 001812D4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801844D8 001812D8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801844DC 001812DC  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 801844E0 001812E0  7C 08 03 A6 */	mtlr r0
/* 801844E4 001812E4  38 21 00 20 */	addi r1, r1, 0x20
/* 801844E8 001812E8  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_create_dialogue_panel_and_cache_child_jobjs

# .text:0xA94 | 0x801844EC | size: 0x44
.fn kar_mnlandialogue_destroy_dialogue_panel, global
/* 801844EC 001812EC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801844F0 001812F0  7C 08 02 A6 */	mflr r0
/* 801844F4 001812F4  90 01 00 14 */	stw r0, 0x14(r1)
/* 801844F8 001812F8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801844FC 001812FC  4B FA CC E5 */	bl fn_801311E0
/* 80184500 00181300  7C 7F 1B 78 */	mr r31, r3
/* 80184504 00181304  80 63 11 68 */	lwz r3, 0x1168(r3)
/* 80184508 00181308  28 03 00 00 */	cmplwi r3, 0x0
/* 8018450C 0018130C  41 82 00 10 */	beq .L_8018451C
/* 80184510 00181310  48 2A 4A 55 */	bl HSD_GObjDestroy
/* 80184514 00181314  38 00 00 00 */	li r0, 0x0
/* 80184518 00181318  90 1F 11 68 */	stw r0, 0x1168(r31)
.L_8018451C:
/* 8018451C 0018131C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184520 00181320  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80184524 00181324  7C 08 03 A6 */	mtlr r0
/* 80184528 00181328  38 21 00 10 */	addi r1, r1, 0x10
/* 8018452C 0018132C  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_destroy_dialogue_panel

# .text:0xAD8 | 0x80184530 | size: 0x7C
.fn kar_mnlandialogue_request_connect_panel_state0_anim, global
/* 80184530 00181330  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184534 00181334  7C 08 02 A6 */	mflr r0
/* 80184538 00181338  90 01 00 14 */	stw r0, 0x14(r1)
/* 8018453C 0018133C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80184540 00181340  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80184544 00181344  4B FA CC 9D */	bl fn_801311E0
/* 80184548 00181348  80 83 11 70 */	lwz r4, 0x1170(r3)
/* 8018454C 0018134C  28 04 00 00 */	cmplwi r4, 0x0
/* 80184550 00181350  41 82 00 44 */	beq .L_80184594
/* 80184554 00181354  83 E4 00 2C */	lwz r31, 0x2c(r4)
/* 80184558 00181358  38 00 00 00 */	li r0, 0x0
/* 8018455C 0018135C  C0 22 A7 98 */	lfs f1, lbl_805E0E98@sda21(r0)
/* 80184560 00181360  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 80184564 00181364  C0 42 A7 9C */	lfs f2, lbl_805E0E9C@sda21(r0)
/* 80184568 00181368  80 63 11 6C */	lwz r3, 0x116c(r3)
/* 8018456C 0018136C  83 C4 00 28 */	lwz r30, 0x28(r4)
/* 80184570 00181370  80 9F 00 1C */	lwz r4, 0x1c(r31)
/* 80184574 00181374  80 A3 00 00 */	lwz r5, 0x0(r3)
/* 80184578 00181378  7F C3 F3 78 */	mr r3, r30
/* 8018457C 0018137C  4B FB 45 95 */	bl fn_80138B10
/* 80184580 00181380  38 00 00 00 */	li r0, 0x0
/* 80184584 00181384  C0 22 A7 98 */	lfs f1, lbl_805E0E98@sda21(r0)
/* 80184588 00181388  90 1F 00 20 */	stw r0, 0x20(r31)
/* 8018458C 0018138C  7F C3 F3 78 */	mr r3, r30
/* 80184590 00181390  48 28 4C C1 */	bl HSD_JObjReqAnimAll
.L_80184594:
/* 80184594 00181394  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184598 00181398  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8018459C 0018139C  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 801845A0 001813A0  7C 08 03 A6 */	mtlr r0
/* 801845A4 001813A4  38 21 00 10 */	addi r1, r1, 0x10
/* 801845A8 001813A8  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_connect_panel_state0_anim

# .text:0xB54 | 0x801845AC | size: 0x7C
.fn kar_mnlandialogue_request_connect_panel_state1_anim, global
/* 801845AC 001813AC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801845B0 001813B0  7C 08 02 A6 */	mflr r0
/* 801845B4 001813B4  90 01 00 14 */	stw r0, 0x14(r1)
/* 801845B8 001813B8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801845BC 001813BC  93 C1 00 08 */	stw r30, 0x8(r1)
/* 801845C0 001813C0  4B FA CC 21 */	bl fn_801311E0
/* 801845C4 001813C4  80 83 11 70 */	lwz r4, 0x1170(r3)
/* 801845C8 001813C8  28 04 00 00 */	cmplwi r4, 0x0
/* 801845CC 001813CC  41 82 00 44 */	beq .L_80184610
/* 801845D0 001813D0  83 E4 00 2C */	lwz r31, 0x2c(r4)
/* 801845D4 001813D4  38 00 00 01 */	li r0, 0x1
/* 801845D8 001813D8  C0 22 A7 98 */	lfs f1, lbl_805E0E98@sda21(r0)
/* 801845DC 001813DC  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 801845E0 001813E0  C0 42 A7 9C */	lfs f2, lbl_805E0E9C@sda21(r0)
/* 801845E4 001813E4  80 63 11 6C */	lwz r3, 0x116c(r3)
/* 801845E8 001813E8  83 C4 00 28 */	lwz r30, 0x28(r4)
/* 801845EC 001813EC  80 9F 00 1C */	lwz r4, 0x1c(r31)
/* 801845F0 001813F0  80 A3 00 00 */	lwz r5, 0x0(r3)
/* 801845F4 001813F4  7F C3 F3 78 */	mr r3, r30
/* 801845F8 001813F8  4B FB 45 19 */	bl fn_80138B10
/* 801845FC 001813FC  38 00 00 00 */	li r0, 0x0
/* 80184600 00181400  C0 22 A7 98 */	lfs f1, lbl_805E0E98@sda21(r0)
/* 80184604 00181404  90 1F 00 20 */	stw r0, 0x20(r31)
/* 80184608 00181408  7F C3 F3 78 */	mr r3, r30
/* 8018460C 0018140C  48 28 4C 45 */	bl HSD_JObjReqAnimAll
.L_80184610:
/* 80184610 00181410  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184614 00181414  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80184618 00181418  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8018461C 0018141C  7C 08 03 A6 */	mtlr r0
/* 80184620 00181420  38 21 00 10 */	addi r1, r1, 0x10
/* 80184624 00181424  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_connect_panel_state1_anim

# .text:0xBD0 | 0x80184628 | size: 0x7C
.fn kar_mnlandialogue_request_connect_panel_state3_anim, global
/* 80184628 00181428  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8018462C 0018142C  7C 08 02 A6 */	mflr r0
/* 80184630 00181430  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184634 00181434  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80184638 00181438  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8018463C 0018143C  4B FA CB A5 */	bl fn_801311E0
/* 80184640 00181440  80 83 11 70 */	lwz r4, 0x1170(r3)
/* 80184644 00181444  28 04 00 00 */	cmplwi r4, 0x0
/* 80184648 00181448  41 82 00 44 */	beq .L_8018468C
/* 8018464C 0018144C  83 E4 00 2C */	lwz r31, 0x2c(r4)
/* 80184650 00181450  38 00 00 03 */	li r0, 0x3
/* 80184654 00181454  C0 22 A7 98 */	lfs f1, lbl_805E0E98@sda21(r0)
/* 80184658 00181458  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 8018465C 0018145C  C0 42 A7 9C */	lfs f2, lbl_805E0E9C@sda21(r0)
/* 80184660 00181460  80 63 11 6C */	lwz r3, 0x116c(r3)
/* 80184664 00181464  83 C4 00 28 */	lwz r30, 0x28(r4)
/* 80184668 00181468  80 9F 00 1C */	lwz r4, 0x1c(r31)
/* 8018466C 0018146C  80 A3 00 00 */	lwz r5, 0x0(r3)
/* 80184670 00181470  7F C3 F3 78 */	mr r3, r30
/* 80184674 00181474  4B FB 44 9D */	bl fn_80138B10
/* 80184678 00181478  38 00 00 00 */	li r0, 0x0
/* 8018467C 0018147C  C0 22 A7 98 */	lfs f1, lbl_805E0E98@sda21(r0)
/* 80184680 00181480  90 1F 00 20 */	stw r0, 0x20(r31)
/* 80184684 00181484  7F C3 F3 78 */	mr r3, r30
/* 80184688 00181488  48 28 4B C9 */	bl HSD_JObjReqAnimAll
.L_8018468C:
/* 8018468C 0018148C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184690 00181490  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80184694 00181494  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80184698 00181498  7C 08 03 A6 */	mtlr r0
/* 8018469C 0018149C  38 21 00 10 */	addi r1, r1, 0x10
/* 801846A0 001814A0  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_connect_panel_state3_anim

# .text:0xC4C | 0x801846A4 | size: 0x7C
.fn kar_mnlandialogue_request_connect_panel_state5_anim, global
/* 801846A4 001814A4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801846A8 001814A8  7C 08 02 A6 */	mflr r0
/* 801846AC 001814AC  90 01 00 14 */	stw r0, 0x14(r1)
/* 801846B0 001814B0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801846B4 001814B4  93 C1 00 08 */	stw r30, 0x8(r1)
/* 801846B8 001814B8  4B FA CB 29 */	bl fn_801311E0
/* 801846BC 001814BC  80 83 11 70 */	lwz r4, 0x1170(r3)
/* 801846C0 001814C0  28 04 00 00 */	cmplwi r4, 0x0
/* 801846C4 001814C4  41 82 00 44 */	beq .L_80184708
/* 801846C8 001814C8  83 E4 00 2C */	lwz r31, 0x2c(r4)
/* 801846CC 001814CC  38 00 00 05 */	li r0, 0x5
/* 801846D0 001814D0  C0 22 A7 98 */	lfs f1, lbl_805E0E98@sda21(r0)
/* 801846D4 001814D4  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 801846D8 001814D8  C0 42 A7 9C */	lfs f2, lbl_805E0E9C@sda21(r0)
/* 801846DC 001814DC  80 63 11 6C */	lwz r3, 0x116c(r3)
/* 801846E0 001814E0  83 C4 00 28 */	lwz r30, 0x28(r4)
/* 801846E4 001814E4  80 9F 00 1C */	lwz r4, 0x1c(r31)
/* 801846E8 001814E8  80 A3 00 00 */	lwz r5, 0x0(r3)
/* 801846EC 001814EC  7F C3 F3 78 */	mr r3, r30
/* 801846F0 001814F0  4B FB 44 21 */	bl fn_80138B10
/* 801846F4 001814F4  38 00 00 00 */	li r0, 0x0
/* 801846F8 001814F8  C0 22 A7 98 */	lfs f1, lbl_805E0E98@sda21(r0)
/* 801846FC 001814FC  90 1F 00 20 */	stw r0, 0x20(r31)
/* 80184700 00181500  7F C3 F3 78 */	mr r3, r30
/* 80184704 00181504  48 28 4B 4D */	bl HSD_JObjReqAnimAll
.L_80184708:
/* 80184708 00181508  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8018470C 0018150C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80184710 00181510  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80184714 00181514  7C 08 03 A6 */	mtlr r0
/* 80184718 00181518  38 21 00 10 */	addi r1, r1, 0x10
/* 8018471C 0018151C  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_connect_panel_state5_anim

# .text:0xCC8 | 0x80184720 | size: 0xD8
.fn kar_mnlandialogue_set_connect_indicator_count, global
/* 80184720 00181520  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184724 00181524  7C 08 02 A6 */	mflr r0
/* 80184728 00181528  90 01 00 14 */	stw r0, 0x14(r1)
/* 8018472C 0018152C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80184730 00181530  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80184734 00181534  7C 7E 1B 78 */	mr r30, r3
/* 80184738 00181538  4B FA CA A9 */	bl fn_801311E0
/* 8018473C 0018153C  80 63 11 70 */	lwz r3, 0x1170(r3)
/* 80184740 00181540  28 03 00 00 */	cmplwi r3, 0x0
/* 80184744 00181544  41 82 00 9C */	beq .L_801847E0
/* 80184748 00181548  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8018474C 0018154C  38 80 00 10 */	li r4, 0x10
/* 80184750 00181550  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 80184754 00181554  48 28 76 AD */	bl HSD_JObjSetFlagsAll
/* 80184758 00181558  80 7F 00 10 */	lwz r3, 0x10(r31)
/* 8018475C 0018155C  38 80 00 10 */	li r4, 0x10
/* 80184760 00181560  48 28 76 A1 */	bl HSD_JObjSetFlagsAll
/* 80184764 00181564  80 7F 00 14 */	lwz r3, 0x14(r31)
/* 80184768 00181568  38 80 00 10 */	li r4, 0x10
/* 8018476C 0018156C  48 28 76 95 */	bl HSD_JObjSetFlagsAll
/* 80184770 00181570  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 80184774 00181574  38 80 00 10 */	li r4, 0x10
/* 80184778 00181578  48 28 76 89 */	bl HSD_JObjSetFlagsAll
/* 8018477C 0018157C  2C 1E 00 03 */	cmpwi r30, 0x3
/* 80184780 00181580  41 82 00 2C */	beq .L_801847AC
/* 80184784 00181584  40 80 00 14 */	bge .L_80184798
/* 80184788 00181588  2C 1E 00 01 */	cmpwi r30, 0x1
/* 8018478C 0018158C  41 82 00 38 */	beq .L_801847C4
/* 80184790 00181590  40 80 00 28 */	bge .L_801847B8
/* 80184794 00181594  48 00 00 40 */	b .L_801847D4
.L_80184798:
/* 80184798 00181598  2C 1E 00 05 */	cmpwi r30, 0x5
/* 8018479C 0018159C  40 80 00 38 */	bge .L_801847D4
/* 801847A0 001815A0  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 801847A4 001815A4  38 80 00 10 */	li r4, 0x10
/* 801847A8 001815A8  48 28 79 CD */	bl HSD_JObjClearFlagsAll
.L_801847AC:
/* 801847AC 001815AC  80 7F 00 14 */	lwz r3, 0x14(r31)
/* 801847B0 001815B0  38 80 00 10 */	li r4, 0x10
/* 801847B4 001815B4  48 28 79 C1 */	bl HSD_JObjClearFlagsAll
.L_801847B8:
/* 801847B8 001815B8  80 7F 00 10 */	lwz r3, 0x10(r31)
/* 801847BC 001815BC  38 80 00 10 */	li r4, 0x10
/* 801847C0 001815C0  48 28 79 B5 */	bl HSD_JObjClearFlagsAll
.L_801847C4:
/* 801847C4 001815C4  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 801847C8 001815C8  38 80 00 10 */	li r4, 0x10
/* 801847CC 001815CC  48 28 79 A9 */	bl HSD_JObjClearFlagsAll
/* 801847D0 001815D0  48 00 00 10 */	b .L_801847E0
.L_801847D4:
/* 801847D4 001815D4  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 801847D8 001815D8  38 80 00 10 */	li r4, 0x10
/* 801847DC 001815DC  48 28 79 99 */	bl HSD_JObjClearFlagsAll
.L_801847E0:
/* 801847E0 001815E0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801847E4 001815E4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801847E8 001815E8  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 801847EC 001815EC  7C 08 03 A6 */	mtlr r0
/* 801847F0 001815F0  38 21 00 10 */	addi r1, r1, 0x10
/* 801847F4 001815F4  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_set_connect_indicator_count

# .text:0xDA0 | 0x801847F8 | size: 0x30
.fn kar_mnlandialogue_hide_connect_panel, global
/* 801847F8 001815F8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801847FC 001815FC  7C 08 02 A6 */	mflr r0
/* 80184800 00181600  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184804 00181604  4B FA C9 DD */	bl fn_801311E0
/* 80184808 00181608  80 63 11 70 */	lwz r3, 0x1170(r3)
/* 8018480C 0018160C  28 03 00 00 */	cmplwi r3, 0x0
/* 80184810 00181610  41 82 00 08 */	beq .L_80184818
/* 80184814 00181614  4B FB 42 9D */	bl kar_menu_gobj_userdata_hide
.L_80184818:
/* 80184818 00181618  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8018481C 0018161C  7C 08 03 A6 */	mtlr r0
/* 80184820 00181620  38 21 00 10 */	addi r1, r1, 0x10
/* 80184824 00181624  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_hide_connect_panel

# .text:0xDD0 | 0x80184828 | size: 0x30
.fn kar_mnlandialogue_show_connect_panel, global
/* 80184828 00181628  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8018482C 0018162C  7C 08 02 A6 */	mflr r0
/* 80184830 00181630  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184834 00181634  4B FA C9 AD */	bl fn_801311E0
/* 80184838 00181638  80 63 11 70 */	lwz r3, 0x1170(r3)
/* 8018483C 0018163C  28 03 00 00 */	cmplwi r3, 0x0
/* 80184840 00181640  41 82 00 08 */	beq .L_80184848
/* 80184844 00181644  4B FB 42 85 */	bl kar_menu_gobj_userdata_show
.L_80184848:
/* 80184848 00181648  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8018484C 0018164C  7C 08 03 A6 */	mtlr r0
/* 80184850 00181650  38 21 00 10 */	addi r1, r1, 0x10
/* 80184854 00181654  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_show_connect_panel

# .text:0xE00 | 0x80184858 | size: 0x218
.fn kar_mnlandialogue_proc_update_connect_panel, global
/* 80184858 00181658  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8018485C 0018165C  7C 08 02 A6 */	mflr r0
/* 80184860 00181660  90 01 00 24 */	stw r0, 0x24(r1)
/* 80184864 00181664  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80184868 00181668  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8018486C 0018166C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80184870 00181670  7C 7D 1B 78 */	mr r29, r3
/* 80184874 00181674  93 81 00 10 */	stw r28, 0x10(r1)
/* 80184878 00181678  4B FA C9 69 */	bl fn_801311E0
/* 8018487C 0018167C  83 9D 00 28 */	lwz r28, 0x28(r29)
/* 80184880 00181680  83 FD 00 2C */	lwz r31, 0x2c(r29)
/* 80184884 00181684  7F 83 E3 78 */	mr r3, r28
/* 80184888 00181688  48 28 5D C5 */	bl HSD_JObjAnimAll
/* 8018488C 0018168C  80 7F 00 20 */	lwz r3, 0x20(r31)
/* 80184890 00181690  38 03 00 01 */	addi r0, r3, 0x1
/* 80184894 00181694  90 1F 00 20 */	stw r0, 0x20(r31)
/* 80184898 00181698  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 8018489C 0018169C  2C 00 00 03 */	cmpwi r0, 0x3
/* 801848A0 001816A0  41 82 00 D0 */	beq .L_80184970
/* 801848A4 001816A4  40 80 00 10 */	bge .L_801848B4
/* 801848A8 001816A8  2C 00 00 01 */	cmpwi r0, 0x1
/* 801848AC 001816AC  41 82 00 14 */	beq .L_801848C0
/* 801848B0 001816B0  48 00 01 80 */	b .L_80184A30
.L_801848B4:
/* 801848B4 001816B4  2C 00 00 05 */	cmpwi r0, 0x5
/* 801848B8 001816B8  41 82 01 6C */	beq .L_80184A24
/* 801848BC 001816BC  48 00 01 74 */	b .L_80184A30
.L_801848C0:
/* 801848C0 001816C0  4B FA C9 21 */	bl fn_801311E0
/* 801848C4 001816C4  80 63 11 70 */	lwz r3, 0x1170(r3)
/* 801848C8 001816C8  3B A0 00 00 */	li r29, 0x0
/* 801848CC 001816CC  28 03 00 00 */	cmplwi r3, 0x0
/* 801848D0 001816D0  40 82 00 0C */	bne .L_801848DC
/* 801848D4 001816D4  3B A0 00 01 */	li r29, 0x1
/* 801848D8 001816D8  48 00 00 30 */	b .L_80184908
.L_801848DC:
/* 801848DC 001816DC  7F BE EB 78 */	mr r30, r29
/* 801848E0 001816E0  83 83 00 2C */	lwz r28, 0x2c(r3)
.L_801848E4:
/* 801848E4 001816E4  80 7C 00 0C */	lwz r3, 0xc(r28)
/* 801848E8 001816E8  48 28 74 65 */	bl HSD_JObjGetFlags
/* 801848EC 001816EC  54 60 06 F7 */	rlwinm. r0, r3, 0, 27, 27
/* 801848F0 001816F0  40 82 00 08 */	bne .L_801848F8
/* 801848F4 001816F4  3B BD 00 01 */	addi r29, r29, 0x1
.L_801848F8:
/* 801848F8 001816F8  3B DE 00 01 */	addi r30, r30, 0x1
/* 801848FC 001816FC  3B 9C 00 04 */	addi r28, r28, 0x4
/* 80184900 00181700  2C 1E 00 04 */	cmpwi r30, 0x4
/* 80184904 00181704  41 80 FF E0 */	blt .L_801848E4
.L_80184908:
/* 80184908 00181708  2C 1D 00 02 */	cmpwi r29, 0x2
/* 8018490C 0018170C  40 81 00 64 */	ble .L_80184970
/* 80184910 00181710  80 1F 00 20 */	lwz r0, 0x20(r31)
/* 80184914 00181714  2C 00 00 09 */	cmpwi r0, 0x9
/* 80184918 00181718  41 80 00 58 */	blt .L_80184970
/* 8018491C 0018171C  38 00 00 00 */	li r0, 0x0
/* 80184920 00181720  90 1F 00 20 */	stw r0, 0x20(r31)
/* 80184924 00181724  4B FA C8 BD */	bl fn_801311E0
/* 80184928 00181728  7C 64 1B 78 */	mr r4, r3
/* 8018492C 0018172C  80 63 11 70 */	lwz r3, 0x1170(r3)
/* 80184930 00181730  28 03 00 00 */	cmplwi r3, 0x0
/* 80184934 00181734  41 82 00 3C */	beq .L_80184970
/* 80184938 00181738  83 A3 00 28 */	lwz r29, 0x28(r3)
/* 8018493C 0018173C  38 00 00 02 */	li r0, 0x2
/* 80184940 00181740  80 C3 00 2C */	lwz r6, 0x2c(r3)
/* 80184944 00181744  C0 22 A7 98 */	lfs f1, lbl_805E0E98@sda21(r0)
/* 80184948 00181748  7F A3 EB 78 */	mr r3, r29
/* 8018494C 0018174C  90 06 00 1C */	stw r0, 0x1c(r6)
/* 80184950 00181750  C0 42 A7 9C */	lfs f2, lbl_805E0E9C@sda21(r0)
/* 80184954 00181754  80 A4 11 6C */	lwz r5, 0x116c(r4)
/* 80184958 00181758  80 86 00 1C */	lwz r4, 0x1c(r6)
/* 8018495C 0018175C  80 A5 00 00 */	lwz r5, 0x0(r5)
/* 80184960 00181760  4B FB 41 B1 */	bl fn_80138B10
/* 80184964 00181764  C0 22 A7 98 */	lfs f1, lbl_805E0E98@sda21(r0)
/* 80184968 00181768  7F A3 EB 78 */	mr r3, r29
/* 8018496C 0018176C  48 28 48 E5 */	bl HSD_JObjReqAnimAll
.L_80184970:
/* 80184970 00181770  4B FA C8 71 */	bl fn_801311E0
/* 80184974 00181774  80 63 11 70 */	lwz r3, 0x1170(r3)
/* 80184978 00181778  3B C0 00 00 */	li r30, 0x0
/* 8018497C 0018177C  28 03 00 00 */	cmplwi r3, 0x0
/* 80184980 00181780  40 82 00 0C */	bne .L_8018498C
/* 80184984 00181784  3B C0 00 01 */	li r30, 0x1
/* 80184988 00181788  48 00 00 30 */	b .L_801849B8
.L_8018498C:
/* 8018498C 0018178C  7F DD F3 78 */	mr r29, r30
/* 80184990 00181790  83 83 00 2C */	lwz r28, 0x2c(r3)
.L_80184994:
/* 80184994 00181794  80 7C 00 0C */	lwz r3, 0xc(r28)
/* 80184998 00181798  48 28 73 B5 */	bl HSD_JObjGetFlags
/* 8018499C 0018179C  54 60 06 F7 */	rlwinm. r0, r3, 0, 27, 27
/* 801849A0 001817A0  40 82 00 08 */	bne .L_801849A8
/* 801849A4 001817A4  3B DE 00 01 */	addi r30, r30, 0x1
.L_801849A8:
/* 801849A8 001817A8  3B BD 00 01 */	addi r29, r29, 0x1
/* 801849AC 001817AC  3B 9C 00 04 */	addi r28, r28, 0x4
/* 801849B0 001817B0  2C 1D 00 04 */	cmpwi r29, 0x4
/* 801849B4 001817B4  41 80 FF E0 */	blt .L_80184994
.L_801849B8:
/* 801849B8 001817B8  2C 1E 00 03 */	cmpwi r30, 0x3
/* 801849BC 001817BC  40 81 00 94 */	ble .L_80184A50
/* 801849C0 001817C0  80 1F 00 20 */	lwz r0, 0x20(r31)
/* 801849C4 001817C4  2C 00 00 09 */	cmpwi r0, 0x9
/* 801849C8 001817C8  41 80 00 88 */	blt .L_80184A50
/* 801849CC 001817CC  38 00 00 00 */	li r0, 0x0
/* 801849D0 001817D0  90 1F 00 20 */	stw r0, 0x20(r31)
/* 801849D4 001817D4  4B FA C8 0D */	bl fn_801311E0
/* 801849D8 001817D8  7C 64 1B 78 */	mr r4, r3
/* 801849DC 001817DC  80 63 11 70 */	lwz r3, 0x1170(r3)
/* 801849E0 001817E0  28 03 00 00 */	cmplwi r3, 0x0
/* 801849E4 001817E4  41 82 00 6C */	beq .L_80184A50
/* 801849E8 001817E8  83 A3 00 28 */	lwz r29, 0x28(r3)
/* 801849EC 001817EC  38 00 00 04 */	li r0, 0x4
/* 801849F0 001817F0  80 C3 00 2C */	lwz r6, 0x2c(r3)
/* 801849F4 001817F4  C0 22 A7 98 */	lfs f1, lbl_805E0E98@sda21(r0)
/* 801849F8 001817F8  7F A3 EB 78 */	mr r3, r29
/* 801849FC 001817FC  90 06 00 1C */	stw r0, 0x1c(r6)
/* 80184A00 00181800  C0 42 A7 9C */	lfs f2, lbl_805E0E9C@sda21(r0)
/* 80184A04 00181804  80 A4 11 6C */	lwz r5, 0x116c(r4)
/* 80184A08 00181808  80 86 00 1C */	lwz r4, 0x1c(r6)
/* 80184A0C 0018180C  80 A5 00 00 */	lwz r5, 0x0(r5)
/* 80184A10 00181810  4B FB 41 01 */	bl fn_80138B10
/* 80184A14 00181814  C0 22 A7 98 */	lfs f1, lbl_805E0E98@sda21(r0)
/* 80184A18 00181818  7F A3 EB 78 */	mr r3, r29
/* 80184A1C 0018181C  48 28 48 35 */	bl HSD_JObjReqAnimAll
/* 80184A20 00181820  48 00 00 30 */	b .L_80184A50
.L_80184A24:
/* 80184A24 00181824  38 00 00 00 */	li r0, 0x0
/* 80184A28 00181828  90 1F 00 20 */	stw r0, 0x20(r31)
/* 80184A2C 0018182C  48 00 00 24 */	b .L_80184A50
.L_80184A30:
/* 80184A30 00181830  80 1F 00 20 */	lwz r0, 0x20(r31)
/* 80184A34 00181834  2C 00 00 59 */	cmpwi r0, 0x59
/* 80184A38 00181838  40 82 00 18 */	bne .L_80184A50
/* 80184A3C 0018183C  38 00 00 00 */	li r0, 0x0
/* 80184A40 00181840  C0 22 A7 98 */	lfs f1, lbl_805E0E98@sda21(r0)
/* 80184A44 00181844  90 1F 00 20 */	stw r0, 0x20(r31)
/* 80184A48 00181848  7F 83 E3 78 */	mr r3, r28
/* 80184A4C 0018184C  48 28 48 05 */	bl HSD_JObjReqAnimAll
.L_80184A50:
/* 80184A50 00181850  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80184A54 00181854  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80184A58 00181858  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80184A5C 0018185C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80184A60 00181860  83 81 00 10 */	lwz r28, 0x10(r1)
/* 80184A64 00181864  7C 08 03 A6 */	mtlr r0
/* 80184A68 00181868  38 21 00 20 */	addi r1, r1, 0x20
/* 80184A6C 0018186C  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_proc_update_connect_panel

# .text:0x1018 | 0x80184A70 | size: 0x4C
.fn kar_mnlandialogue_load_connect_scene_models, global
/* 80184A70 00181870  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184A74 00181874  7C 08 02 A6 */	mflr r0
/* 80184A78 00181878  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184A7C 0018187C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80184A80 00181880  4B FA C7 61 */	bl fn_801311E0
/* 80184A84 00181884  7C 7F 1B 78 */	mr r31, r3
/* 80184A88 00181888  4B FB 46 15 */	bl fn_8013909C
/* 80184A8C 0018188C  3C 80 80 4B */	lis r4, kar_mnlandialogue_connect_scene_models_name@ha
/* 80184A90 00181890  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80184A94 00181894  38 A4 D6 E8 */	addi r5, r4, kar_mnlandialogue_connect_scene_models_name@l
/* 80184A98 00181898  38 C0 00 00 */	li r6, 0x0
/* 80184A9C 0018189C  38 9F 11 6C */	addi r4, r31, 0x116c
/* 80184AA0 001818A0  4C C6 31 82 */	crclr cr1eq
/* 80184AA4 001818A4  4B ED 4A 7D */	bl kar_lbarchive__near_80059520
/* 80184AA8 001818A8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184AAC 001818AC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80184AB0 001818B0  7C 08 03 A6 */	mtlr r0
/* 80184AB4 001818B4  38 21 00 10 */	addi r1, r1, 0x10
/* 80184AB8 001818B8  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_load_connect_scene_models

# .text:0x1064 | 0x80184ABC | size: 0xDC
.fn kar_mnlandialogue_create_connect_panel_and_cache_child_jobjs, global
/* 80184ABC 001818BC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80184AC0 001818C0  7C 08 02 A6 */	mflr r0
/* 80184AC4 001818C4  90 01 00 24 */	stw r0, 0x24(r1)
/* 80184AC8 001818C8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80184ACC 001818CC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80184AD0 001818D0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80184AD4 001818D4  4B FA C7 0D */	bl fn_801311E0
/* 80184AD8 001818D8  7C 7E 1B 78 */	mr r30, r3
/* 80184ADC 001818DC  80 63 11 6C */	lwz r3, 0x116c(r3)
/* 80184AE0 001818E0  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80184AE4 001818E4  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80184AE8 001818E8  4B FB 3D C1 */	bl fn_801388A8
/* 80184AEC 001818EC  3C 80 80 18 */	lis r4, kar_mnlandialogue_proc_update_connect_panel@ha
/* 80184AF0 001818F0  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 80184AF4 001818F4  7C 7D 1B 78 */	mr r29, r3
/* 80184AF8 001818F8  38 A0 00 01 */	li r5, 0x1
/* 80184AFC 001818FC  38 84 48 58 */	addi r4, r4, kar_mnlandialogue_proc_update_connect_panel@l
/* 80184B00 00181900  48 2A 3D A5 */	bl HSD_GObjProcCreate
/* 80184B04 00181904  80 9E 11 6C */	lwz r4, 0x116c(r30)
/* 80184B08 00181908  7F E3 FB 78 */	mr r3, r31
/* 80184B0C 0018190C  C0 22 A7 98 */	lfs f1, lbl_805E0E98@sda21(r0)
/* 80184B10 00181910  80 84 00 00 */	lwz r4, 0x0(r4)
/* 80184B14 00181914  C0 42 A7 9C */	lfs f2, lbl_805E0E9C@sda21(r0)
/* 80184B18 00181918  4B FB 3E C1 */	bl fn_801389D8
/* 80184B1C 0018191C  7F A3 EB 78 */	mr r3, r29
/* 80184B20 00181920  38 80 00 BA */	li r4, 0xba
/* 80184B24 00181924  4B FB 3E DD */	bl kar_diag__80138a00
/* 80184B28 00181928  7C 7F 1B 78 */	mr r31, r3
/* 80184B2C 0018192C  7F A3 EB 78 */	mr r3, r29
/* 80184B30 00181930  38 80 00 01 */	li r4, 0x1
/* 80184B34 00181934  4B ED 0F BD */	bl kar_lbairride__near_80055af0
/* 80184B38 00181938  90 7F 00 0C */	stw r3, 0xc(r31)
/* 80184B3C 0018193C  7F A3 EB 78 */	mr r3, r29
/* 80184B40 00181940  38 80 00 02 */	li r4, 0x2
/* 80184B44 00181944  4B ED 0F AD */	bl kar_lbairride__near_80055af0
/* 80184B48 00181948  90 7F 00 10 */	stw r3, 0x10(r31)
/* 80184B4C 0018194C  7F A3 EB 78 */	mr r3, r29
/* 80184B50 00181950  38 80 00 03 */	li r4, 0x3
/* 80184B54 00181954  4B ED 0F 9D */	bl kar_lbairride__near_80055af0
/* 80184B58 00181958  90 7F 00 14 */	stw r3, 0x14(r31)
/* 80184B5C 0018195C  7F A3 EB 78 */	mr r3, r29
/* 80184B60 00181960  38 80 00 04 */	li r4, 0x4
/* 80184B64 00181964  4B ED 0F 8D */	bl kar_lbairride__near_80055af0
/* 80184B68 00181968  90 7F 00 18 */	stw r3, 0x18(r31)
/* 80184B6C 0018196C  38 00 00 00 */	li r0, 0x0
/* 80184B70 00181970  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 80184B74 00181974  90 1F 00 20 */	stw r0, 0x20(r31)
/* 80184B78 00181978  93 BE 11 70 */	stw r29, 0x1170(r30)
/* 80184B7C 0018197C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80184B80 00181980  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80184B84 00181984  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80184B88 00181988  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80184B8C 0018198C  7C 08 03 A6 */	mtlr r0
/* 80184B90 00181990  38 21 00 20 */	addi r1, r1, 0x20
/* 80184B94 00181994  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_create_connect_panel_and_cache_child_jobjs

# .text:0x1140 | 0x80184B98 | size: 0x44
.fn kar_mnlandialogue_destroy_connect_panel, global
/* 80184B98 00181998  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184B9C 0018199C  7C 08 02 A6 */	mflr r0
/* 80184BA0 001819A0  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184BA4 001819A4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80184BA8 001819A8  4B FA C6 39 */	bl fn_801311E0
/* 80184BAC 001819AC  7C 7F 1B 78 */	mr r31, r3
/* 80184BB0 001819B0  80 63 11 70 */	lwz r3, 0x1170(r3)
/* 80184BB4 001819B4  28 03 00 00 */	cmplwi r3, 0x0
/* 80184BB8 001819B8  41 82 00 10 */	beq .L_80184BC8
/* 80184BBC 001819BC  48 2A 43 A9 */	bl HSD_GObjDestroy
/* 80184BC0 001819C0  38 00 00 00 */	li r0, 0x0
/* 80184BC4 001819C4  90 1F 11 70 */	stw r0, 0x1170(r31)
.L_80184BC8:
/* 80184BC8 001819C8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184BCC 001819CC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80184BD0 001819D0  7C 08 03 A6 */	mtlr r0
/* 80184BD4 001819D4  38 21 00 10 */	addi r1, r1, 0x10
/* 80184BD8 001819D8  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_destroy_connect_panel

# .text:0x1184 | 0x80184BDC | size: 0x30
.fn kar_mnlandialogue_hide_wait_panel, global
/* 80184BDC 001819DC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184BE0 001819E0  7C 08 02 A6 */	mflr r0
/* 80184BE4 001819E4  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184BE8 001819E8  4B FA C5 F9 */	bl fn_801311E0
/* 80184BEC 001819EC  80 63 11 78 */	lwz r3, 0x1178(r3)
/* 80184BF0 001819F0  28 03 00 00 */	cmplwi r3, 0x0
/* 80184BF4 001819F4  41 82 00 08 */	beq .L_80184BFC
/* 80184BF8 001819F8  4B FB 3E B9 */	bl kar_menu_gobj_userdata_hide
.L_80184BFC:
/* 80184BFC 001819FC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184C00 00181A00  7C 08 03 A6 */	mtlr r0
/* 80184C04 00181A04  38 21 00 10 */	addi r1, r1, 0x10
/* 80184C08 00181A08  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_hide_wait_panel

# .text:0x11B4 | 0x80184C0C | size: 0x30
.fn kar_mnlandialogue_show_wait_panel, global
/* 80184C0C 00181A0C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184C10 00181A10  7C 08 02 A6 */	mflr r0
/* 80184C14 00181A14  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184C18 00181A18  4B FA C5 C9 */	bl fn_801311E0
/* 80184C1C 00181A1C  80 63 11 78 */	lwz r3, 0x1178(r3)
/* 80184C20 00181A20  28 03 00 00 */	cmplwi r3, 0x0
/* 80184C24 00181A24  41 82 00 08 */	beq .L_80184C2C
/* 80184C28 00181A28  4B FB 3E A1 */	bl kar_menu_gobj_userdata_show
.L_80184C2C:
/* 80184C2C 00181A2C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184C30 00181A30  7C 08 03 A6 */	mtlr r0
/* 80184C34 00181A34  38 21 00 10 */	addi r1, r1, 0x10
/* 80184C38 00181A38  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_show_wait_panel

# .text:0x11E4 | 0x80184C3C | size: 0x24
.fn kar_mnlandialogue_proc_anim_wait_panel, global
/* 80184C3C 00181A3C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184C40 00181A40  7C 08 02 A6 */	mflr r0
/* 80184C44 00181A44  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184C48 00181A48  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80184C4C 00181A4C  48 28 5A 01 */	bl HSD_JObjAnimAll
/* 80184C50 00181A50  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184C54 00181A54  7C 08 03 A6 */	mtlr r0
/* 80184C58 00181A58  38 21 00 10 */	addi r1, r1, 0x10
/* 80184C5C 00181A5C  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_proc_anim_wait_panel

# .text:0x1208 | 0x80184C60 | size: 0x4C
.fn kar_mnlandialogue_load_wait_scene_models, global
/* 80184C60 00181A60  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184C64 00181A64  7C 08 02 A6 */	mflr r0
/* 80184C68 00181A68  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184C6C 00181A6C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80184C70 00181A70  4B FA C5 71 */	bl fn_801311E0
/* 80184C74 00181A74  7C 7F 1B 78 */	mr r31, r3
/* 80184C78 00181A78  4B FB 44 25 */	bl fn_8013909C
/* 80184C7C 00181A7C  3C 80 80 4B */	lis r4, kar_mnlandialogue_wait_scene_models_name@ha
/* 80184C80 00181A80  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80184C84 00181A84  38 A4 D7 08 */	addi r5, r4, kar_mnlandialogue_wait_scene_models_name@l
/* 80184C88 00181A88  38 C0 00 00 */	li r6, 0x0
/* 80184C8C 00181A8C  38 9F 11 74 */	addi r4, r31, 0x1174
/* 80184C90 00181A90  4C C6 31 82 */	crclr cr1eq
/* 80184C94 00181A94  4B ED 48 8D */	bl kar_lbarchive__near_80059520
/* 80184C98 00181A98  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184C9C 00181A9C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80184CA0 00181AA0  7C 08 03 A6 */	mtlr r0
/* 80184CA4 00181AA4  38 21 00 10 */	addi r1, r1, 0x10
/* 80184CA8 00181AA8  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_load_wait_scene_models

# .text:0x1254 | 0x80184CAC | size: 0x8C
.fn kar_mnlandialogue_create_wait_panel, global
/* 80184CAC 00181AAC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80184CB0 00181AB0  7C 08 02 A6 */	mflr r0
/* 80184CB4 00181AB4  90 01 00 24 */	stw r0, 0x24(r1)
/* 80184CB8 00181AB8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80184CBC 00181ABC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80184CC0 00181AC0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80184CC4 00181AC4  4B FA C5 1D */	bl fn_801311E0
/* 80184CC8 00181AC8  7C 7F 1B 78 */	mr r31, r3
/* 80184CCC 00181ACC  80 63 11 74 */	lwz r3, 0x1174(r3)
/* 80184CD0 00181AD0  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80184CD4 00181AD4  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80184CD8 00181AD8  4B FB 3B D1 */	bl fn_801388A8
/* 80184CDC 00181ADC  3C 80 80 18 */	lis r4, kar_mnlandialogue_proc_anim_wait_panel@ha
/* 80184CE0 00181AE0  83 A3 00 28 */	lwz r29, 0x28(r3)
/* 80184CE4 00181AE4  7C 7E 1B 78 */	mr r30, r3
/* 80184CE8 00181AE8  38 A0 00 01 */	li r5, 0x1
/* 80184CEC 00181AEC  38 84 4C 3C */	addi r4, r4, kar_mnlandialogue_proc_anim_wait_panel@l
/* 80184CF0 00181AF0  48 2A 3B B5 */	bl HSD_GObjProcCreate
/* 80184CF4 00181AF4  80 9F 11 74 */	lwz r4, 0x1174(r31)
/* 80184CF8 00181AF8  7F A3 EB 78 */	mr r3, r29
/* 80184CFC 00181AFC  C0 22 A7 A0 */	lfs f1, lbl_805E0EA0@sda21(r0)
/* 80184D00 00181B00  80 84 00 00 */	lwz r4, 0x0(r4)
/* 80184D04 00181B04  C0 42 A7 A4 */	lfs f2, lbl_805E0EA4@sda21(r0)
/* 80184D08 00181B08  4B FB 3C D1 */	bl fn_801389D8
/* 80184D0C 00181B0C  7F C3 F3 78 */	mr r3, r30
/* 80184D10 00181B10  38 80 00 BA */	li r4, 0xba
/* 80184D14 00181B14  4B FB 3C ED */	bl kar_diag__80138a00
/* 80184D18 00181B18  93 DF 11 78 */	stw r30, 0x1178(r31)
/* 80184D1C 00181B1C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80184D20 00181B20  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80184D24 00181B24  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80184D28 00181B28  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80184D2C 00181B2C  7C 08 03 A6 */	mtlr r0
/* 80184D30 00181B30  38 21 00 20 */	addi r1, r1, 0x20
/* 80184D34 00181B34  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_create_wait_panel

# .text:0x12E0 | 0x80184D38 | size: 0x44
.fn kar_mnlandialogue_destroy_wait_panel, global
/* 80184D38 00181B38  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184D3C 00181B3C  7C 08 02 A6 */	mflr r0
/* 80184D40 00181B40  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184D44 00181B44  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80184D48 00181B48  4B FA C4 99 */	bl fn_801311E0
/* 80184D4C 00181B4C  7C 7F 1B 78 */	mr r31, r3
/* 80184D50 00181B50  80 63 11 78 */	lwz r3, 0x1178(r3)
/* 80184D54 00181B54  28 03 00 00 */	cmplwi r3, 0x0
/* 80184D58 00181B58  41 82 00 10 */	beq .L_80184D68
/* 80184D5C 00181B5C  48 2A 42 09 */	bl HSD_GObjDestroy
/* 80184D60 00181B60  38 00 00 00 */	li r0, 0x0
/* 80184D64 00181B64  90 1F 11 78 */	stw r0, 0x1178(r31)
.L_80184D68:
/* 80184D68 00181B68  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184D6C 00181B6C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80184D70 00181B70  7C 08 03 A6 */	mtlr r0
/* 80184D74 00181B74  38 21 00 10 */	addi r1, r1, 0x10
/* 80184D78 00181B78  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_destroy_wait_panel

# .text:0x1324 | 0x80184D7C | size: 0x4C
.fn kar_mnlandialogue_request_select_panel_anim0, global
/* 80184D7C 00181B7C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184D80 00181B80  7C 08 02 A6 */	mflr r0
/* 80184D84 00181B84  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184D88 00181B88  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80184D8C 00181B8C  4B FA C4 55 */	bl fn_801311E0
/* 80184D90 00181B90  80 63 11 80 */	lwz r3, 0x1180(r3)
/* 80184D94 00181B94  28 03 00 00 */	cmplwi r3, 0x0
/* 80184D98 00181B98  41 82 00 1C */	beq .L_80184DB4
/* 80184D9C 00181B9C  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 80184DA0 00181BA0  C0 22 A7 A8 */	lfs f1, lbl_805E0EA8@sda21(r0)
/* 80184DA4 00181BA4  7F E3 FB 78 */	mr r3, r31
/* 80184DA8 00181BA8  48 28 44 A9 */	bl HSD_JObjReqAnimAll
/* 80184DAC 00181BAC  7F E3 FB 78 */	mr r3, r31
/* 80184DB0 00181BB0  48 28 58 9D */	bl HSD_JObjAnimAll
.L_80184DB4:
/* 80184DB4 00181BB4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184DB8 00181BB8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80184DBC 00181BBC  7C 08 03 A6 */	mtlr r0
/* 80184DC0 00181BC0  38 21 00 10 */	addi r1, r1, 0x10
/* 80184DC4 00181BC4  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_select_panel_anim0

# .text:0x1370 | 0x80184DC8 | size: 0x4C
.fn kar_mnlandialogue_request_select_panel_anim1, global
/* 80184DC8 00181BC8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184DCC 00181BCC  7C 08 02 A6 */	mflr r0
/* 80184DD0 00181BD0  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184DD4 00181BD4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80184DD8 00181BD8  4B FA C4 09 */	bl fn_801311E0
/* 80184DDC 00181BDC  80 63 11 80 */	lwz r3, 0x1180(r3)
/* 80184DE0 00181BE0  28 03 00 00 */	cmplwi r3, 0x0
/* 80184DE4 00181BE4  41 82 00 1C */	beq .L_80184E00
/* 80184DE8 00181BE8  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 80184DEC 00181BEC  C0 22 A7 AC */	lfs f1, lbl_805E0EAC@sda21(r0)
/* 80184DF0 00181BF0  7F E3 FB 78 */	mr r3, r31
/* 80184DF4 00181BF4  48 28 44 5D */	bl HSD_JObjReqAnimAll
/* 80184DF8 00181BF8  7F E3 FB 78 */	mr r3, r31
/* 80184DFC 00181BFC  48 28 58 51 */	bl HSD_JObjAnimAll
.L_80184E00:
/* 80184E00 00181C00  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184E04 00181C04  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80184E08 00181C08  7C 08 03 A6 */	mtlr r0
/* 80184E0C 00181C0C  38 21 00 10 */	addi r1, r1, 0x10
/* 80184E10 00181C10  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_select_panel_anim1

# .text:0x13BC | 0x80184E14 | size: 0x4C
.fn kar_mnlandialogue_request_select_panel_anim2, global
/* 80184E14 00181C14  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184E18 00181C18  7C 08 02 A6 */	mflr r0
/* 80184E1C 00181C1C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184E20 00181C20  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80184E24 00181C24  4B FA C3 BD */	bl fn_801311E0
/* 80184E28 00181C28  80 63 11 80 */	lwz r3, 0x1180(r3)
/* 80184E2C 00181C2C  28 03 00 00 */	cmplwi r3, 0x0
/* 80184E30 00181C30  41 82 00 1C */	beq .L_80184E4C
/* 80184E34 00181C34  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 80184E38 00181C38  C0 22 A7 B0 */	lfs f1, lbl_805E0EB0@sda21(r0)
/* 80184E3C 00181C3C  7F E3 FB 78 */	mr r3, r31
/* 80184E40 00181C40  48 28 44 11 */	bl HSD_JObjReqAnimAll
/* 80184E44 00181C44  7F E3 FB 78 */	mr r3, r31
/* 80184E48 00181C48  48 28 58 05 */	bl HSD_JObjAnimAll
.L_80184E4C:
/* 80184E4C 00181C4C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184E50 00181C50  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80184E54 00181C54  7C 08 03 A6 */	mtlr r0
/* 80184E58 00181C58  38 21 00 10 */	addi r1, r1, 0x10
/* 80184E5C 00181C5C  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_select_panel_anim2

# .text:0x1408 | 0x80184E60 | size: 0x30
.fn kar_mnlandialogue_hide_select_panel, global
/* 80184E60 00181C60  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184E64 00181C64  7C 08 02 A6 */	mflr r0
/* 80184E68 00181C68  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184E6C 00181C6C  4B FA C3 75 */	bl fn_801311E0
/* 80184E70 00181C70  80 63 11 80 */	lwz r3, 0x1180(r3)
/* 80184E74 00181C74  28 03 00 00 */	cmplwi r3, 0x0
/* 80184E78 00181C78  41 82 00 08 */	beq .L_80184E80
/* 80184E7C 00181C7C  4B FB 3C 35 */	bl kar_menu_gobj_userdata_hide
.L_80184E80:
/* 80184E80 00181C80  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184E84 00181C84  7C 08 03 A6 */	mtlr r0
/* 80184E88 00181C88  38 21 00 10 */	addi r1, r1, 0x10
/* 80184E8C 00181C8C  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_hide_select_panel

# .text:0x1438 | 0x80184E90 | size: 0x30
.fn kar_mnlandialogue_show_select_panel, global
/* 80184E90 00181C90  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184E94 00181C94  7C 08 02 A6 */	mflr r0
/* 80184E98 00181C98  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184E9C 00181C9C  4B FA C3 45 */	bl fn_801311E0
/* 80184EA0 00181CA0  80 63 11 80 */	lwz r3, 0x1180(r3)
/* 80184EA4 00181CA4  28 03 00 00 */	cmplwi r3, 0x0
/* 80184EA8 00181CA8  41 82 00 08 */	beq .L_80184EB0
/* 80184EAC 00181CAC  4B FB 3C 1D */	bl kar_menu_gobj_userdata_show
.L_80184EB0:
/* 80184EB0 00181CB0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184EB4 00181CB4  7C 08 03 A6 */	mtlr r0
/* 80184EB8 00181CB8  38 21 00 10 */	addi r1, r1, 0x10
/* 80184EBC 00181CBC  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_show_select_panel

# .text:0x1468 | 0x80184EC0 | size: 0x4
.fn fn_80184EC0, global
/* 80184EC0 00181CC0  4E 80 00 20 */	blr
.endfn fn_80184EC0

# .text:0x146C | 0x80184EC4 | size: 0x4C
.fn kar_mnlandialogue_load_select_scene_models, global
/* 80184EC4 00181CC4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184EC8 00181CC8  7C 08 02 A6 */	mflr r0
/* 80184ECC 00181CCC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184ED0 00181CD0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80184ED4 00181CD4  4B FA C3 0D */	bl fn_801311E0
/* 80184ED8 00181CD8  7C 7F 1B 78 */	mr r31, r3
/* 80184EDC 00181CDC  4B FB 41 C1 */	bl fn_8013909C
/* 80184EE0 00181CE0  3C 80 80 4B */	lis r4, kar_mnlandialogue_select_scene_models_name@ha
/* 80184EE4 00181CE4  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80184EE8 00181CE8  38 A4 D7 28 */	addi r5, r4, kar_mnlandialogue_select_scene_models_name@l
/* 80184EEC 00181CEC  38 C0 00 00 */	li r6, 0x0
/* 80184EF0 00181CF0  38 9F 11 7C */	addi r4, r31, 0x117c
/* 80184EF4 00181CF4  4C C6 31 82 */	crclr cr1eq
/* 80184EF8 00181CF8  4B ED 46 29 */	bl kar_lbarchive__near_80059520
/* 80184EFC 00181CFC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184F00 00181D00  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80184F04 00181D04  7C 08 03 A6 */	mtlr r0
/* 80184F08 00181D08  38 21 00 10 */	addi r1, r1, 0x10
/* 80184F0C 00181D0C  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_load_select_scene_models

# .text:0x14B8 | 0x80184F10 | size: 0x8C
.fn kar_mnlandialogue_create_select_panel, global
/* 80184F10 00181D10  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80184F14 00181D14  7C 08 02 A6 */	mflr r0
/* 80184F18 00181D18  90 01 00 24 */	stw r0, 0x24(r1)
/* 80184F1C 00181D1C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80184F20 00181D20  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80184F24 00181D24  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80184F28 00181D28  4B FA C2 B9 */	bl fn_801311E0
/* 80184F2C 00181D2C  7C 7F 1B 78 */	mr r31, r3
/* 80184F30 00181D30  80 63 11 7C */	lwz r3, 0x117c(r3)
/* 80184F34 00181D34  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80184F38 00181D38  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80184F3C 00181D3C  4B FB 39 6D */	bl fn_801388A8
/* 80184F40 00181D40  3C 80 80 18 */	lis r4, fn_80184EC0@ha
/* 80184F44 00181D44  83 A3 00 28 */	lwz r29, 0x28(r3)
/* 80184F48 00181D48  7C 7E 1B 78 */	mr r30, r3
/* 80184F4C 00181D4C  38 A0 00 01 */	li r5, 0x1
/* 80184F50 00181D50  38 84 4E C0 */	addi r4, r4, fn_80184EC0@l
/* 80184F54 00181D54  48 2A 39 51 */	bl HSD_GObjProcCreate
/* 80184F58 00181D58  80 9F 11 7C */	lwz r4, 0x117c(r31)
/* 80184F5C 00181D5C  7F A3 EB 78 */	mr r3, r29
/* 80184F60 00181D60  C0 22 A7 A8 */	lfs f1, lbl_805E0EA8@sda21(r0)
/* 80184F64 00181D64  80 84 00 00 */	lwz r4, 0x0(r4)
/* 80184F68 00181D68  C0 42 A7 AC */	lfs f2, lbl_805E0EAC@sda21(r0)
/* 80184F6C 00181D6C  4B FB 3A 6D */	bl fn_801389D8
/* 80184F70 00181D70  7F C3 F3 78 */	mr r3, r30
/* 80184F74 00181D74  38 80 00 BA */	li r4, 0xba
/* 80184F78 00181D78  4B FB 3A 89 */	bl kar_diag__80138a00
/* 80184F7C 00181D7C  93 DF 11 80 */	stw r30, 0x1180(r31)
/* 80184F80 00181D80  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80184F84 00181D84  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80184F88 00181D88  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80184F8C 00181D8C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80184F90 00181D90  7C 08 03 A6 */	mtlr r0
/* 80184F94 00181D94  38 21 00 20 */	addi r1, r1, 0x20
/* 80184F98 00181D98  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_create_select_panel

# .text:0x1544 | 0x80184F9C | size: 0x44
.fn kar_mnlandialogue_destroy_select_panel, global
/* 80184F9C 00181D9C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184FA0 00181DA0  7C 08 02 A6 */	mflr r0
/* 80184FA4 00181DA4  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184FA8 00181DA8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80184FAC 00181DAC  4B FA C2 35 */	bl fn_801311E0
/* 80184FB0 00181DB0  7C 7F 1B 78 */	mr r31, r3
/* 80184FB4 00181DB4  80 63 11 80 */	lwz r3, 0x1180(r3)
/* 80184FB8 00181DB8  28 03 00 00 */	cmplwi r3, 0x0
/* 80184FBC 00181DBC  41 82 00 10 */	beq .L_80184FCC
/* 80184FC0 00181DC0  48 2A 3F A5 */	bl HSD_GObjDestroy
/* 80184FC4 00181DC4  38 00 00 00 */	li r0, 0x0
/* 80184FC8 00181DC8  90 1F 11 80 */	stw r0, 0x1180(r31)
.L_80184FCC:
/* 80184FCC 00181DCC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80184FD0 00181DD0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80184FD4 00181DD4  7C 08 03 A6 */	mtlr r0
/* 80184FD8 00181DD8  38 21 00 10 */	addi r1, r1, 0x10
/* 80184FDC 00181DDC  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_destroy_select_panel

# .text:0x1588 | 0x80184FE0 | size: 0x4C
.fn kar_mnlandialogue_request_airride_panel_anim0, global
/* 80184FE0 00181DE0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80184FE4 00181DE4  7C 08 02 A6 */	mflr r0
/* 80184FE8 00181DE8  90 01 00 14 */	stw r0, 0x14(r1)
/* 80184FEC 00181DEC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80184FF0 00181DF0  4B FA C1 F1 */	bl fn_801311E0
/* 80184FF4 00181DF4  80 63 11 88 */	lwz r3, 0x1188(r3)
/* 80184FF8 00181DF8  28 03 00 00 */	cmplwi r3, 0x0
/* 80184FFC 00181DFC  41 82 00 1C */	beq .L_80185018
/* 80185000 00181E00  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 80185004 00181E04  C0 22 A7 B8 */	lfs f1, lbl_805E0EB8@sda21(r0)
/* 80185008 00181E08  7F E3 FB 78 */	mr r3, r31
/* 8018500C 00181E0C  48 28 42 45 */	bl HSD_JObjReqAnimAll
/* 80185010 00181E10  7F E3 FB 78 */	mr r3, r31
/* 80185014 00181E14  48 28 56 39 */	bl HSD_JObjAnimAll
.L_80185018:
/* 80185018 00181E18  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8018501C 00181E1C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80185020 00181E20  7C 08 03 A6 */	mtlr r0
/* 80185024 00181E24  38 21 00 10 */	addi r1, r1, 0x10
/* 80185028 00181E28  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_airride_panel_anim0

# .text:0x15D4 | 0x8018502C | size: 0x4C
.fn kar_mnlandialogue_request_airride_panel_anim1, global
/* 8018502C 00181E2C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80185030 00181E30  7C 08 02 A6 */	mflr r0
/* 80185034 00181E34  90 01 00 14 */	stw r0, 0x14(r1)
/* 80185038 00181E38  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8018503C 00181E3C  4B FA C1 A5 */	bl fn_801311E0
/* 80185040 00181E40  80 63 11 88 */	lwz r3, 0x1188(r3)
/* 80185044 00181E44  28 03 00 00 */	cmplwi r3, 0x0
/* 80185048 00181E48  41 82 00 1C */	beq .L_80185064
/* 8018504C 00181E4C  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 80185050 00181E50  C0 22 A7 BC */	lfs f1, lbl_805E0EBC@sda21(r0)
/* 80185054 00181E54  7F E3 FB 78 */	mr r3, r31
/* 80185058 00181E58  48 28 41 F9 */	bl HSD_JObjReqAnimAll
/* 8018505C 00181E5C  7F E3 FB 78 */	mr r3, r31
/* 80185060 00181E60  48 28 55 ED */	bl HSD_JObjAnimAll
.L_80185064:
/* 80185064 00181E64  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80185068 00181E68  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8018506C 00181E6C  7C 08 03 A6 */	mtlr r0
/* 80185070 00181E70  38 21 00 10 */	addi r1, r1, 0x10
/* 80185074 00181E74  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_airride_panel_anim1

# .text:0x1620 | 0x80185078 | size: 0x30
.fn kar_mnlandialogue_hide_airride_panel, global
/* 80185078 00181E78  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8018507C 00181E7C  7C 08 02 A6 */	mflr r0
/* 80185080 00181E80  90 01 00 14 */	stw r0, 0x14(r1)
/* 80185084 00181E84  4B FA C1 5D */	bl fn_801311E0
/* 80185088 00181E88  80 63 11 88 */	lwz r3, 0x1188(r3)
/* 8018508C 00181E8C  28 03 00 00 */	cmplwi r3, 0x0
/* 80185090 00181E90  41 82 00 08 */	beq .L_80185098
/* 80185094 00181E94  4B FB 3A 1D */	bl kar_menu_gobj_userdata_hide
.L_80185098:
/* 80185098 00181E98  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8018509C 00181E9C  7C 08 03 A6 */	mtlr r0
/* 801850A0 00181EA0  38 21 00 10 */	addi r1, r1, 0x10
/* 801850A4 00181EA4  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_hide_airride_panel

# .text:0x1650 | 0x801850A8 | size: 0x30
.fn kar_mnlandialogue_show_airride_panel, global
/* 801850A8 00181EA8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801850AC 00181EAC  7C 08 02 A6 */	mflr r0
/* 801850B0 00181EB0  90 01 00 14 */	stw r0, 0x14(r1)
/* 801850B4 00181EB4  4B FA C1 2D */	bl fn_801311E0
/* 801850B8 00181EB8  80 63 11 88 */	lwz r3, 0x1188(r3)
/* 801850BC 00181EBC  28 03 00 00 */	cmplwi r3, 0x0
/* 801850C0 00181EC0  41 82 00 08 */	beq .L_801850C8
/* 801850C4 00181EC4  4B FB 3A 05 */	bl kar_menu_gobj_userdata_show
.L_801850C8:
/* 801850C8 00181EC8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801850CC 00181ECC  7C 08 03 A6 */	mtlr r0
/* 801850D0 00181ED0  38 21 00 10 */	addi r1, r1, 0x10
/* 801850D4 00181ED4  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_show_airride_panel

# .text:0x1680 | 0x801850D8 | size: 0x4
.fn fn_801850D8, global
/* 801850D8 00181ED8  4E 80 00 20 */	blr
.endfn fn_801850D8

# .text:0x1684 | 0x801850DC | size: 0x4C
.fn kar_mnlandialogue_load_airride_scene_models, global
/* 801850DC 00181EDC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801850E0 00181EE0  7C 08 02 A6 */	mflr r0
/* 801850E4 00181EE4  90 01 00 14 */	stw r0, 0x14(r1)
/* 801850E8 00181EE8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801850EC 00181EEC  4B FA C0 F5 */	bl fn_801311E0
/* 801850F0 00181EF0  7C 7F 1B 78 */	mr r31, r3
/* 801850F4 00181EF4  4B FB 3F A9 */	bl fn_8013909C
/* 801850F8 00181EF8  3C 80 80 4B */	lis r4, kar_mnlandialogue_airride_scene_models_name@ha
/* 801850FC 00181EFC  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80185100 00181F00  38 A4 D7 48 */	addi r5, r4, kar_mnlandialogue_airride_scene_models_name@l
/* 80185104 00181F04  38 C0 00 00 */	li r6, 0x0
/* 80185108 00181F08  38 9F 11 84 */	addi r4, r31, 0x1184
/* 8018510C 00181F0C  4C C6 31 82 */	crclr cr1eq
/* 80185110 00181F10  4B ED 44 11 */	bl kar_lbarchive__near_80059520
/* 80185114 00181F14  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80185118 00181F18  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8018511C 00181F1C  7C 08 03 A6 */	mtlr r0
/* 80185120 00181F20  38 21 00 10 */	addi r1, r1, 0x10
/* 80185124 00181F24  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_load_airride_scene_models

# .text:0x16D0 | 0x80185128 | size: 0x8C
.fn kar_mnlandialogue_create_airride_panel, global
/* 80185128 00181F28  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8018512C 00181F2C  7C 08 02 A6 */	mflr r0
/* 80185130 00181F30  90 01 00 24 */	stw r0, 0x24(r1)
/* 80185134 00181F34  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80185138 00181F38  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8018513C 00181F3C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80185140 00181F40  4B FA C0 A1 */	bl fn_801311E0
/* 80185144 00181F44  7C 7F 1B 78 */	mr r31, r3
/* 80185148 00181F48  80 63 11 84 */	lwz r3, 0x1184(r3)
/* 8018514C 00181F4C  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80185150 00181F50  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80185154 00181F54  4B FB 37 55 */	bl fn_801388A8
/* 80185158 00181F58  3C 80 80 18 */	lis r4, fn_801850D8@ha
/* 8018515C 00181F5C  83 A3 00 28 */	lwz r29, 0x28(r3)
/* 80185160 00181F60  7C 7E 1B 78 */	mr r30, r3
/* 80185164 00181F64  38 A0 00 01 */	li r5, 0x1
/* 80185168 00181F68  38 84 50 D8 */	addi r4, r4, fn_801850D8@l
/* 8018516C 00181F6C  48 2A 37 39 */	bl HSD_GObjProcCreate
/* 80185170 00181F70  80 9F 11 84 */	lwz r4, 0x1184(r31)
/* 80185174 00181F74  7F A3 EB 78 */	mr r3, r29
/* 80185178 00181F78  C0 22 A7 B8 */	lfs f1, lbl_805E0EB8@sda21(r0)
/* 8018517C 00181F7C  80 84 00 00 */	lwz r4, 0x0(r4)
/* 80185180 00181F80  C0 42 A7 BC */	lfs f2, lbl_805E0EBC@sda21(r0)
/* 80185184 00181F84  4B FB 38 55 */	bl fn_801389D8
/* 80185188 00181F88  7F C3 F3 78 */	mr r3, r30
/* 8018518C 00181F8C  38 80 00 BA */	li r4, 0xba
/* 80185190 00181F90  4B FB 38 71 */	bl kar_diag__80138a00
/* 80185194 00181F94  93 DF 11 88 */	stw r30, 0x1188(r31)
/* 80185198 00181F98  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8018519C 00181F9C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801851A0 00181FA0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801851A4 00181FA4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 801851A8 00181FA8  7C 08 03 A6 */	mtlr r0
/* 801851AC 00181FAC  38 21 00 20 */	addi r1, r1, 0x20
/* 801851B0 00181FB0  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_create_airride_panel

# .text:0x175C | 0x801851B4 | size: 0x44
.fn kar_mnlandialogue_destroy_airride_panel, global
/* 801851B4 00181FB4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801851B8 00181FB8  7C 08 02 A6 */	mflr r0
/* 801851BC 00181FBC  90 01 00 14 */	stw r0, 0x14(r1)
/* 801851C0 00181FC0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801851C4 00181FC4  4B FA C0 1D */	bl fn_801311E0
/* 801851C8 00181FC8  7C 7F 1B 78 */	mr r31, r3
/* 801851CC 00181FCC  80 63 11 88 */	lwz r3, 0x1188(r3)
/* 801851D0 00181FD0  28 03 00 00 */	cmplwi r3, 0x0
/* 801851D4 00181FD4  41 82 00 10 */	beq .L_801851E4
/* 801851D8 00181FD8  48 2A 3D 8D */	bl HSD_GObjDestroy
/* 801851DC 00181FDC  38 00 00 00 */	li r0, 0x0
/* 801851E0 00181FE0  90 1F 11 88 */	stw r0, 0x1188(r31)
.L_801851E4:
/* 801851E4 00181FE4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801851E8 00181FE8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801851EC 00181FEC  7C 08 03 A6 */	mtlr r0
/* 801851F0 00181FF0  38 21 00 10 */	addi r1, r1, 0x10
/* 801851F4 00181FF4  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_destroy_airride_panel

# .text:0x17A0 | 0x801851F8 | size: 0x4C
.fn kar_mnlandialogue_request_city_panel_anim0, global
/* 801851F8 00181FF8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801851FC 00181FFC  7C 08 02 A6 */	mflr r0
/* 80185200 00182000  90 01 00 14 */	stw r0, 0x14(r1)
/* 80185204 00182004  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80185208 00182008  4B FA BF D9 */	bl fn_801311E0
/* 8018520C 0018200C  80 63 11 90 */	lwz r3, 0x1190(r3)
/* 80185210 00182010  28 03 00 00 */	cmplwi r3, 0x0
/* 80185214 00182014  41 82 00 1C */	beq .L_80185230
/* 80185218 00182018  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 8018521C 0018201C  C0 22 A7 C0 */	lfs f1, lbl_805E0EC0@sda21(r0)
/* 80185220 00182020  7F E3 FB 78 */	mr r3, r31
/* 80185224 00182024  48 28 40 2D */	bl HSD_JObjReqAnimAll
/* 80185228 00182028  7F E3 FB 78 */	mr r3, r31
/* 8018522C 0018202C  48 28 54 21 */	bl HSD_JObjAnimAll
.L_80185230:
/* 80185230 00182030  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80185234 00182034  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80185238 00182038  7C 08 03 A6 */	mtlr r0
/* 8018523C 0018203C  38 21 00 10 */	addi r1, r1, 0x10
/* 80185240 00182040  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_city_panel_anim0

# .text:0x17EC | 0x80185244 | size: 0x4C
.fn kar_mnlandialogue_request_city_panel_anim1, global
/* 80185244 00182044  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80185248 00182048  7C 08 02 A6 */	mflr r0
/* 8018524C 0018204C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80185250 00182050  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80185254 00182054  4B FA BF 8D */	bl fn_801311E0
/* 80185258 00182058  80 63 11 90 */	lwz r3, 0x1190(r3)
/* 8018525C 0018205C  28 03 00 00 */	cmplwi r3, 0x0
/* 80185260 00182060  41 82 00 1C */	beq .L_8018527C
/* 80185264 00182064  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 80185268 00182068  C0 22 A7 C4 */	lfs f1, lbl_805E0EC4@sda21(r0)
/* 8018526C 0018206C  7F E3 FB 78 */	mr r3, r31
/* 80185270 00182070  48 28 3F E1 */	bl HSD_JObjReqAnimAll
/* 80185274 00182074  7F E3 FB 78 */	mr r3, r31
/* 80185278 00182078  48 28 53 D5 */	bl HSD_JObjAnimAll
.L_8018527C:
/* 8018527C 0018207C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80185280 00182080  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80185284 00182084  7C 08 03 A6 */	mtlr r0
/* 80185288 00182088  38 21 00 10 */	addi r1, r1, 0x10
/* 8018528C 0018208C  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_city_panel_anim1

# .text:0x1838 | 0x80185290 | size: 0x4C
.fn kar_mnlandialogue_request_city_panel_anim2, global
/* 80185290 00182090  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80185294 00182094  7C 08 02 A6 */	mflr r0
/* 80185298 00182098  90 01 00 14 */	stw r0, 0x14(r1)
/* 8018529C 0018209C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801852A0 001820A0  4B FA BF 41 */	bl fn_801311E0
/* 801852A4 001820A4  80 63 11 90 */	lwz r3, 0x1190(r3)
/* 801852A8 001820A8  28 03 00 00 */	cmplwi r3, 0x0
/* 801852AC 001820AC  41 82 00 1C */	beq .L_801852C8
/* 801852B0 001820B0  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 801852B4 001820B4  C0 22 A7 C8 */	lfs f1, lbl_805E0EC8@sda21(r0)
/* 801852B8 001820B8  7F E3 FB 78 */	mr r3, r31
/* 801852BC 001820BC  48 28 3F 95 */	bl HSD_JObjReqAnimAll
/* 801852C0 001820C0  7F E3 FB 78 */	mr r3, r31
/* 801852C4 001820C4  48 28 53 89 */	bl HSD_JObjAnimAll
.L_801852C8:
/* 801852C8 001820C8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801852CC 001820CC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801852D0 001820D0  7C 08 03 A6 */	mtlr r0
/* 801852D4 001820D4  38 21 00 10 */	addi r1, r1, 0x10
/* 801852D8 001820D8  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_city_panel_anim2

# .text:0x1884 | 0x801852DC | size: 0x4C
.fn kar_mnlandialogue_request_city_panel_anim3, global
/* 801852DC 001820DC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801852E0 001820E0  7C 08 02 A6 */	mflr r0
/* 801852E4 001820E4  90 01 00 14 */	stw r0, 0x14(r1)
/* 801852E8 001820E8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801852EC 001820EC  4B FA BE F5 */	bl fn_801311E0
/* 801852F0 001820F0  80 63 11 90 */	lwz r3, 0x1190(r3)
/* 801852F4 001820F4  28 03 00 00 */	cmplwi r3, 0x0
/* 801852F8 001820F8  41 82 00 1C */	beq .L_80185314
/* 801852FC 001820FC  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 80185300 00182100  C0 22 A7 CC */	lfs f1, lbl_805E0ECC@sda21(r0)
/* 80185304 00182104  7F E3 FB 78 */	mr r3, r31
/* 80185308 00182108  48 28 3F 49 */	bl HSD_JObjReqAnimAll
/* 8018530C 0018210C  7F E3 FB 78 */	mr r3, r31
/* 80185310 00182110  48 28 53 3D */	bl HSD_JObjAnimAll
.L_80185314:
/* 80185314 00182114  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80185318 00182118  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8018531C 0018211C  7C 08 03 A6 */	mtlr r0
/* 80185320 00182120  38 21 00 10 */	addi r1, r1, 0x10
/* 80185324 00182124  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_request_city_panel_anim3

# .text:0x18D0 | 0x80185328 | size: 0x30
.fn kar_mnlandialogue_hide_city_panel, global
/* 80185328 00182128  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8018532C 0018212C  7C 08 02 A6 */	mflr r0
/* 80185330 00182130  90 01 00 14 */	stw r0, 0x14(r1)
/* 80185334 00182134  4B FA BE AD */	bl fn_801311E0
/* 80185338 00182138  80 63 11 90 */	lwz r3, 0x1190(r3)
/* 8018533C 0018213C  28 03 00 00 */	cmplwi r3, 0x0
/* 80185340 00182140  41 82 00 08 */	beq .L_80185348
/* 80185344 00182144  4B FB 37 6D */	bl kar_menu_gobj_userdata_hide
.L_80185348:
/* 80185348 00182148  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8018534C 0018214C  7C 08 03 A6 */	mtlr r0
/* 80185350 00182150  38 21 00 10 */	addi r1, r1, 0x10
/* 80185354 00182154  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_hide_city_panel

# .text:0x1900 | 0x80185358 | size: 0x30
.fn kar_mnlandialogue_show_city_panel, global
/* 80185358 00182158  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8018535C 0018215C  7C 08 02 A6 */	mflr r0
/* 80185360 00182160  90 01 00 14 */	stw r0, 0x14(r1)
/* 80185364 00182164  4B FA BE 7D */	bl fn_801311E0
/* 80185368 00182168  80 63 11 90 */	lwz r3, 0x1190(r3)
/* 8018536C 0018216C  28 03 00 00 */	cmplwi r3, 0x0
/* 80185370 00182170  41 82 00 08 */	beq .L_80185378
/* 80185374 00182174  4B FB 37 55 */	bl kar_menu_gobj_userdata_show
.L_80185378:
/* 80185378 00182178  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8018537C 0018217C  7C 08 03 A6 */	mtlr r0
/* 80185380 00182180  38 21 00 10 */	addi r1, r1, 0x10
/* 80185384 00182184  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_show_city_panel

# .text:0x1930 | 0x80185388 | size: 0x4
.fn fn_80185388, global
/* 80185388 00182188  4E 80 00 20 */	blr
.endfn fn_80185388

# .text:0x1934 | 0x8018538C | size: 0x4C
.fn kar_mnlandialogue_load_city_scene_models, global
/* 8018538C 0018218C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80185390 00182190  7C 08 02 A6 */	mflr r0
/* 80185394 00182194  90 01 00 14 */	stw r0, 0x14(r1)
/* 80185398 00182198  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8018539C 0018219C  4B FA BE 45 */	bl fn_801311E0
/* 801853A0 001821A0  7C 7F 1B 78 */	mr r31, r3
/* 801853A4 001821A4  4B FB 3C F9 */	bl fn_8013909C
/* 801853A8 001821A8  3C 80 80 4B */	lis r4, kar_mnlandialogue_city_scene_models_name@ha
/* 801853AC 001821AC  80 63 00 00 */	lwz r3, 0x0(r3)
/* 801853B0 001821B0  38 A4 D7 68 */	addi r5, r4, kar_mnlandialogue_city_scene_models_name@l
/* 801853B4 001821B4  38 C0 00 00 */	li r6, 0x0
/* 801853B8 001821B8  38 9F 11 8C */	addi r4, r31, 0x118c
/* 801853BC 001821BC  4C C6 31 82 */	crclr cr1eq
/* 801853C0 001821C0  4B ED 41 61 */	bl kar_lbarchive__near_80059520
/* 801853C4 001821C4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801853C8 001821C8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801853CC 001821CC  7C 08 03 A6 */	mtlr r0
/* 801853D0 001821D0  38 21 00 10 */	addi r1, r1, 0x10
/* 801853D4 001821D4  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_load_city_scene_models

# .text:0x1980 | 0x801853D8 | size: 0x8C
.fn kar_mnlandialogue_create_city_panel, global
/* 801853D8 001821D8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801853DC 001821DC  7C 08 02 A6 */	mflr r0
/* 801853E0 001821E0  90 01 00 24 */	stw r0, 0x24(r1)
/* 801853E4 001821E4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801853E8 001821E8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801853EC 001821EC  93 A1 00 14 */	stw r29, 0x14(r1)
/* 801853F0 001821F0  4B FA BD F1 */	bl fn_801311E0
/* 801853F4 001821F4  7C 7F 1B 78 */	mr r31, r3
/* 801853F8 001821F8  80 63 11 8C */	lwz r3, 0x118c(r3)
/* 801853FC 001821FC  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80185400 00182200  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80185404 00182204  4B FB 34 A5 */	bl fn_801388A8
/* 80185408 00182208  3C 80 80 18 */	lis r4, fn_80185388@ha
/* 8018540C 0018220C  83 A3 00 28 */	lwz r29, 0x28(r3)
/* 80185410 00182210  7C 7E 1B 78 */	mr r30, r3
/* 80185414 00182214  38 A0 00 01 */	li r5, 0x1
/* 80185418 00182218  38 84 53 88 */	addi r4, r4, fn_80185388@l
/* 8018541C 0018221C  48 2A 34 89 */	bl HSD_GObjProcCreate
/* 80185420 00182220  80 9F 11 8C */	lwz r4, 0x118c(r31)
/* 80185424 00182224  7F A3 EB 78 */	mr r3, r29
/* 80185428 00182228  C0 22 A7 C0 */	lfs f1, lbl_805E0EC0@sda21(r0)
/* 8018542C 0018222C  80 84 00 00 */	lwz r4, 0x0(r4)
/* 80185430 00182230  C0 42 A7 C4 */	lfs f2, lbl_805E0EC4@sda21(r0)
/* 80185434 00182234  4B FB 35 A5 */	bl fn_801389D8
/* 80185438 00182238  7F C3 F3 78 */	mr r3, r30
/* 8018543C 0018223C  38 80 00 BA */	li r4, 0xba
/* 80185440 00182240  4B FB 35 C1 */	bl kar_diag__80138a00
/* 80185444 00182244  93 DF 11 90 */	stw r30, 0x1190(r31)
/* 80185448 00182248  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8018544C 0018224C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80185450 00182250  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80185454 00182254  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80185458 00182258  7C 08 03 A6 */	mtlr r0
/* 8018545C 0018225C  38 21 00 20 */	addi r1, r1, 0x20
/* 80185460 00182260  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_create_city_panel

# .text:0x1A0C | 0x80185464 | size: 0x44
.fn kar_mnlandialogue_destroy_city_panel, global
/* 80185464 00182264  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80185468 00182268  7C 08 02 A6 */	mflr r0
/* 8018546C 0018226C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80185470 00182270  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80185474 00182274  4B FA BD 6D */	bl fn_801311E0
/* 80185478 00182278  7C 7F 1B 78 */	mr r31, r3
/* 8018547C 0018227C  80 63 11 90 */	lwz r3, 0x1190(r3)
/* 80185480 00182280  28 03 00 00 */	cmplwi r3, 0x0
/* 80185484 00182284  41 82 00 10 */	beq .L_80185494
/* 80185488 00182288  48 2A 3A DD */	bl HSD_GObjDestroy
/* 8018548C 0018228C  38 00 00 00 */	li r0, 0x0
/* 80185490 00182290  90 1F 11 90 */	stw r0, 0x1190(r31)
.L_80185494:
/* 80185494 00182294  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80185498 00182298  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8018549C 0018229C  7C 08 03 A6 */	mtlr r0
/* 801854A0 001822A0  38 21 00 10 */	addi r1, r1, 0x10
/* 801854A4 001822A4  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_destroy_city_panel

# .text:0x1A50 | 0x801854A8 | size: 0x17C
.fn kar_mnlandialogue_update_time_panel_digits, global
/* 801854A8 001822A8  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 801854AC 001822AC  7C 08 02 A6 */	mflr r0
/* 801854B0 001822B0  90 01 00 34 */	stw r0, 0x34(r1)
/* 801854B4 001822B4  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 801854B8 001822B8  93 C1 00 28 */	stw r30, 0x28(r1)
/* 801854BC 001822BC  7C 7E 1B 78 */	mr r30, r3
/* 801854C0 001822C0  4B FA BD 21 */	bl fn_801311E0
/* 801854C4 001822C4  80 63 11 98 */	lwz r3, 0x1198(r3)
/* 801854C8 001822C8  28 03 00 00 */	cmplwi r3, 0x0
/* 801854CC 001822CC  41 82 01 40 */	beq .L_8018560C
/* 801854D0 001822D0  2C 1E 00 00 */	cmpwi r30, 0x0
/* 801854D4 001822D4  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 801854D8 001822D8  40 80 00 08 */	bge .L_801854E0
/* 801854DC 001822DC  3B C0 00 00 */	li r30, 0x0
.L_801854E0:
/* 801854E0 001822E0  3C 80 10 62 */	lis r4, 0x1062
/* 801854E4 001822E4  3C 60 66 66 */	lis r3, 0x6666
/* 801854E8 001822E8  38 84 4D D3 */	addi r4, r4, 0x4dd3
/* 801854EC 001822EC  3C 00 43 30 */	lis r0, 0x4330
/* 801854F0 001822F0  7C A4 F0 96 */	mulhw r5, r4, r30
/* 801854F4 001822F4  38 83 66 67 */	addi r4, r3, 0x6667
/* 801854F8 001822F8  90 01 00 08 */	stw r0, 0x8(r1)
/* 801854FC 001822FC  C8 22 A7 D0 */	lfd f1, lbl_805E0ED0@sda21(r0)
/* 80185500 00182300  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 80185504 00182304  7C A0 36 70 */	srawi r0, r5, 6
/* 80185508 00182308  54 05 0F FE */	srwi r5, r0, 31
/* 8018550C 0018230C  7C 00 2A 14 */	add r0, r0, r5
/* 80185510 00182310  1C 00 03 E8 */	mulli r0, r0, 0x3e8
/* 80185514 00182314  7F C0 F0 50 */	subf r30, r0, r30
/* 80185518 00182318  7C 04 F0 96 */	mulhw r0, r4, r30
/* 8018551C 0018231C  7C 00 16 70 */	srawi r0, r0, 2
/* 80185520 00182320  54 04 0F FE */	srwi r4, r0, 31
/* 80185524 00182324  7C 00 22 14 */	add r0, r0, r4
/* 80185528 00182328  1C 00 00 0A */	mulli r0, r0, 0xa
/* 8018552C 0018232C  7C 00 F0 50 */	subf r0, r0, r30
/* 80185530 00182330  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 80185534 00182334  90 01 00 0C */	stw r0, 0xc(r1)
/* 80185538 00182338  C8 01 00 08 */	lfd f0, 0x8(r1)
/* 8018553C 0018233C  EC 20 08 28 */	fsubs f1, f0, f1
/* 80185540 00182340  48 28 3D 11 */	bl HSD_JObjReqAnimAll
/* 80185544 00182344  3C 60 66 66 */	lis r3, 0x6666
/* 80185548 00182348  3C 00 43 30 */	lis r0, 0x4330
/* 8018554C 0018234C  38 C3 66 67 */	addi r6, r3, 0x6667
/* 80185550 00182350  90 01 00 10 */	stw r0, 0x10(r1)
/* 80185554 00182354  7C 06 F0 96 */	mulhw r0, r6, r30
/* 80185558 00182358  C8 22 A7 D0 */	lfd f1, lbl_805E0ED0@sda21(r0)
/* 8018555C 0018235C  80 7F 00 10 */	lwz r3, 0x10(r31)
/* 80185560 00182360  7C 00 16 70 */	srawi r0, r0, 2
/* 80185564 00182364  54 04 0F FE */	srwi r4, r0, 31
/* 80185568 00182368  7C A0 22 14 */	add r5, r0, r4
/* 8018556C 0018236C  7C 06 28 96 */	mulhw r0, r6, r5
/* 80185570 00182370  7C 00 16 70 */	srawi r0, r0, 2
/* 80185574 00182374  54 04 0F FE */	srwi r4, r0, 31
/* 80185578 00182378  7C 00 22 14 */	add r0, r0, r4
/* 8018557C 0018237C  1C 00 00 0A */	mulli r0, r0, 0xa
/* 80185580 00182380  7C 00 28 50 */	subf r0, r0, r5
/* 80185584 00182384  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 80185588 00182388  90 01 00 14 */	stw r0, 0x14(r1)
/* 8018558C 0018238C  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 80185590 00182390  EC 20 08 28 */	fsubs f1, f0, f1
/* 80185594 00182394  48 28 3C BD */	bl HSD_JObjReqAnimAll
/* 80185598 00182398  3C 80 51 EC */	lis r4, 0x51ec
/* 8018559C 0018239C  3C 60 66 66 */	lis r3, 0x6666
/* 801855A0 001823A0  38 84 85 1F */	subi r4, r4, 0x7ae1
/* 801855A4 001823A4  3C 00 43 30 */	lis r0, 0x4330
/* 801855A8 001823A8  7C A4 F0 96 */	mulhw r5, r4, r30
/* 801855AC 001823AC  38 83 66 67 */	addi r4, r3, 0x6667
/* 801855B0 001823B0  90 01 00 18 */	stw r0, 0x18(r1)
/* 801855B4 001823B4  C8 22 A7 D0 */	lfd f1, lbl_805E0ED0@sda21(r0)
/* 801855B8 001823B8  80 7F 00 14 */	lwz r3, 0x14(r31)
/* 801855BC 001823BC  7C A0 2E 70 */	srawi r0, r5, 5
/* 801855C0 001823C0  54 05 0F FE */	srwi r5, r0, 31
/* 801855C4 001823C4  7C A0 2A 14 */	add r5, r0, r5
/* 801855C8 001823C8  7C 04 28 96 */	mulhw r0, r4, r5
/* 801855CC 001823CC  7C 00 16 70 */	srawi r0, r0, 2
/* 801855D0 001823D0  54 04 0F FE */	srwi r4, r0, 31
/* 801855D4 001823D4  7C 00 22 14 */	add r0, r0, r4
/* 801855D8 001823D8  1C 00 00 0A */	mulli r0, r0, 0xa
/* 801855DC 001823DC  7C 00 28 50 */	subf r0, r0, r5
/* 801855E0 001823E0  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 801855E4 001823E4  90 01 00 1C */	stw r0, 0x1c(r1)
/* 801855E8 001823E8  C8 01 00 18 */	lfd f0, 0x18(r1)
/* 801855EC 001823EC  EC 20 08 28 */	fsubs f1, f0, f1
/* 801855F0 001823F0  48 28 3C 61 */	bl HSD_JObjReqAnimAll
/* 801855F4 001823F4  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 801855F8 001823F8  48 28 50 55 */	bl HSD_JObjAnimAll
/* 801855FC 001823FC  80 7F 00 10 */	lwz r3, 0x10(r31)
/* 80185600 00182400  48 28 50 4D */	bl HSD_JObjAnimAll
/* 80185604 00182404  80 7F 00 14 */	lwz r3, 0x14(r31)
/* 80185608 00182408  48 28 50 45 */	bl HSD_JObjAnimAll
.L_8018560C:
/* 8018560C 0018240C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80185610 00182410  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 80185614 00182414  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 80185618 00182418  7C 08 03 A6 */	mtlr r0
/* 8018561C 0018241C  38 21 00 30 */	addi r1, r1, 0x30
/* 80185620 00182420  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_update_time_panel_digits

# .text:0x1BCC | 0x80185624 | size: 0x30
.fn kar_mnlandialogue_hide_time_panel, global
/* 80185624 00182424  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80185628 00182428  7C 08 02 A6 */	mflr r0
/* 8018562C 0018242C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80185630 00182430  4B FA BB B1 */	bl fn_801311E0
/* 80185634 00182434  80 63 11 98 */	lwz r3, 0x1198(r3)
/* 80185638 00182438  28 03 00 00 */	cmplwi r3, 0x0
/* 8018563C 0018243C  41 82 00 08 */	beq .L_80185644
/* 80185640 00182440  4B FB 34 71 */	bl kar_menu_gobj_userdata_hide
.L_80185644:
/* 80185644 00182444  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80185648 00182448  7C 08 03 A6 */	mtlr r0
/* 8018564C 0018244C  38 21 00 10 */	addi r1, r1, 0x10
/* 80185650 00182450  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_hide_time_panel

# .text:0x1BFC | 0x80185654 | size: 0x30
.fn kar_mnlandialogue_show_time_panel, global
/* 80185654 00182454  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80185658 00182458  7C 08 02 A6 */	mflr r0
/* 8018565C 0018245C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80185660 00182460  4B FA BB 81 */	bl fn_801311E0
/* 80185664 00182464  80 63 11 98 */	lwz r3, 0x1198(r3)
/* 80185668 00182468  28 03 00 00 */	cmplwi r3, 0x0
/* 8018566C 0018246C  41 82 00 08 */	beq .L_80185674
/* 80185670 00182470  4B FB 34 59 */	bl kar_menu_gobj_userdata_show
.L_80185674:
/* 80185674 00182474  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80185678 00182478  7C 08 03 A6 */	mtlr r0
/* 8018567C 0018247C  38 21 00 10 */	addi r1, r1, 0x10
/* 80185680 00182480  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_show_time_panel

# .text:0x1C2C | 0x80185684 | size: 0x4
.fn fn_80185684, global
/* 80185684 00182484  4E 80 00 20 */	blr
.endfn fn_80185684

# .text:0x1C30 | 0x80185688 | size: 0x4C
.fn kar_mnlandialogue_load_time_scene_models, global
/* 80185688 00182488  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8018568C 0018248C  7C 08 02 A6 */	mflr r0
/* 80185690 00182490  90 01 00 14 */	stw r0, 0x14(r1)
/* 80185694 00182494  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80185698 00182498  4B FA BB 49 */	bl fn_801311E0
/* 8018569C 0018249C  7C 7F 1B 78 */	mr r31, r3
/* 801856A0 001824A0  4B FB 39 FD */	bl fn_8013909C
/* 801856A4 001824A4  3C 80 80 4B */	lis r4, kar_mnlandialogue_time_scene_models_name@ha
/* 801856A8 001824A8  80 63 00 00 */	lwz r3, 0x0(r3)
/* 801856AC 001824AC  38 A4 D7 88 */	addi r5, r4, kar_mnlandialogue_time_scene_models_name@l
/* 801856B0 001824B0  38 C0 00 00 */	li r6, 0x0
/* 801856B4 001824B4  38 9F 11 94 */	addi r4, r31, 0x1194
/* 801856B8 001824B8  4C C6 31 82 */	crclr cr1eq
/* 801856BC 001824BC  4B ED 3E 65 */	bl kar_lbarchive__near_80059520
/* 801856C0 001824C0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801856C4 001824C4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801856C8 001824C8  7C 08 03 A6 */	mtlr r0
/* 801856CC 001824CC  38 21 00 10 */	addi r1, r1, 0x10
/* 801856D0 001824D0  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_load_time_scene_models

# .text:0x1C7C | 0x801856D4 | size: 0xC0
.fn kar_mnlandialogue_create_time_panel_and_cache_digit_jobjs, global
/* 801856D4 001824D4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801856D8 001824D8  7C 08 02 A6 */	mflr r0
/* 801856DC 001824DC  90 01 00 24 */	stw r0, 0x24(r1)
/* 801856E0 001824E0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801856E4 001824E4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801856E8 001824E8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 801856EC 001824EC  4B FA BA F5 */	bl fn_801311E0
/* 801856F0 001824F0  7C 7E 1B 78 */	mr r30, r3
/* 801856F4 001824F4  80 63 11 94 */	lwz r3, 0x1194(r3)
/* 801856F8 001824F8  80 63 00 00 */	lwz r3, 0x0(r3)
/* 801856FC 001824FC  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80185700 00182500  4B FB 31 A9 */	bl fn_801388A8
/* 80185704 00182504  3C 80 80 18 */	lis r4, fn_80185684@ha
/* 80185708 00182508  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 8018570C 0018250C  7C 7D 1B 78 */	mr r29, r3
/* 80185710 00182510  38 A0 00 01 */	li r5, 0x1
/* 80185714 00182514  38 84 56 84 */	addi r4, r4, fn_80185684@l
/* 80185718 00182518  48 2A 31 8D */	bl HSD_GObjProcCreate
/* 8018571C 0018251C  80 9E 11 94 */	lwz r4, 0x1194(r30)
/* 80185720 00182520  7F E3 FB 78 */	mr r3, r31
/* 80185724 00182524  C0 22 A7 D8 */	lfs f1, lbl_805E0ED8@sda21(r0)
/* 80185728 00182528  80 84 00 00 */	lwz r4, 0x0(r4)
/* 8018572C 0018252C  C0 42 A7 DC */	lfs f2, lbl_805E0EDC@sda21(r0)
/* 80185730 00182530  4B FB 32 A9 */	bl fn_801389D8
/* 80185734 00182534  7F A3 EB 78 */	mr r3, r29
/* 80185738 00182538  38 80 00 BA */	li r4, 0xba
/* 8018573C 0018253C  4B FB 32 C5 */	bl kar_diag__80138a00
/* 80185740 00182540  7C 7F 1B 78 */	mr r31, r3
/* 80185744 00182544  7F A3 EB 78 */	mr r3, r29
/* 80185748 00182548  38 80 00 01 */	li r4, 0x1
/* 8018574C 0018254C  4B ED 03 A5 */	bl kar_lbairride__near_80055af0
/* 80185750 00182550  90 7F 00 0C */	stw r3, 0xc(r31)
/* 80185754 00182554  7F A3 EB 78 */	mr r3, r29
/* 80185758 00182558  38 80 00 02 */	li r4, 0x2
/* 8018575C 0018255C  4B ED 03 95 */	bl kar_lbairride__near_80055af0
/* 80185760 00182560  90 7F 00 10 */	stw r3, 0x10(r31)
/* 80185764 00182564  7F A3 EB 78 */	mr r3, r29
/* 80185768 00182568  38 80 00 03 */	li r4, 0x3
/* 8018576C 0018256C  4B ED 03 85 */	bl kar_lbairride__near_80055af0
/* 80185770 00182570  90 7F 00 14 */	stw r3, 0x14(r31)
/* 80185774 00182574  93 BE 11 98 */	stw r29, 0x1198(r30)
/* 80185778 00182578  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8018577C 0018257C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80185780 00182580  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80185784 00182584  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80185788 00182588  7C 08 03 A6 */	mtlr r0
/* 8018578C 0018258C  38 21 00 20 */	addi r1, r1, 0x20
/* 80185790 00182590  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_create_time_panel_and_cache_digit_jobjs

# .text:0x1D3C | 0x80185794 | size: 0x44
.fn kar_mnlandialogue_destroy_time_panel, global
/* 80185794 00182594  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80185798 00182598  7C 08 02 A6 */	mflr r0
/* 8018579C 0018259C  90 01 00 14 */	stw r0, 0x14(r1)
/* 801857A0 001825A0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801857A4 001825A4  4B FA BA 3D */	bl fn_801311E0
/* 801857A8 001825A8  7C 7F 1B 78 */	mr r31, r3
/* 801857AC 001825AC  80 63 11 98 */	lwz r3, 0x1198(r3)
/* 801857B0 001825B0  28 03 00 00 */	cmplwi r3, 0x0
/* 801857B4 001825B4  41 82 00 10 */	beq .L_801857C4
/* 801857B8 001825B8  48 2A 37 AD */	bl HSD_GObjDestroy
/* 801857BC 001825BC  38 00 00 00 */	li r0, 0x0
/* 801857C0 001825C0  90 1F 11 98 */	stw r0, 0x1198(r31)
.L_801857C4:
/* 801857C4 001825C4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801857C8 001825C8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801857CC 001825CC  7C 08 03 A6 */	mtlr r0
/* 801857D0 001825D0  38 21 00 10 */	addi r1, r1, 0x10
/* 801857D4 001825D4  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_destroy_time_panel

# .text:0x1D80 | 0x801857D8 | size: 0x24
.fn kar_mnlandialogue_proc_anim_sboard_bg_panel, global
/* 801857D8 001825D8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801857DC 001825DC  7C 08 02 A6 */	mflr r0
/* 801857E0 001825E0  90 01 00 14 */	stw r0, 0x14(r1)
/* 801857E4 001825E4  80 63 00 28 */	lwz r3, 0x28(r3)
/* 801857E8 001825E8  48 28 4E 65 */	bl HSD_JObjAnimAll
/* 801857EC 001825EC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801857F0 001825F0  7C 08 03 A6 */	mtlr r0
/* 801857F4 001825F4  38 21 00 10 */	addi r1, r1, 0x10
/* 801857F8 001825F8  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_proc_anim_sboard_bg_panel

# .text:0x1DA4 | 0x801857FC | size: 0x4C
.fn kar_mnlandialogue_load_sboard_bg_scene_models, global
/* 801857FC 001825FC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80185800 00182600  7C 08 02 A6 */	mflr r0
/* 80185804 00182604  90 01 00 14 */	stw r0, 0x14(r1)
/* 80185808 00182608  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8018580C 0018260C  4B FA B9 D5 */	bl fn_801311E0
/* 80185810 00182610  7C 7F 1B 78 */	mr r31, r3
/* 80185814 00182614  4B FB 3A 25 */	bl fn_80139238
/* 80185818 00182618  3C 80 80 4B */	lis r4, kar_mnlandialogue_sboard_bg_scene_models_name@ha
/* 8018581C 0018261C  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80185820 00182620  38 A4 D7 A8 */	addi r5, r4, kar_mnlandialogue_sboard_bg_scene_models_name@l
/* 80185824 00182624  38 C0 00 00 */	li r6, 0x0
/* 80185828 00182628  38 9F 11 A0 */	addi r4, r31, 0x11a0
/* 8018582C 0018262C  4C C6 31 82 */	crclr cr1eq
/* 80185830 00182630  4B ED 3C F1 */	bl kar_lbarchive__near_80059520
/* 80185834 00182634  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80185838 00182638  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8018583C 0018263C  7C 08 03 A6 */	mtlr r0
/* 80185840 00182640  38 21 00 10 */	addi r1, r1, 0x10
/* 80185844 00182644  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_load_sboard_bg_scene_models

# .text:0x1DF0 | 0x80185848 | size: 0xB4
.fn kar_mnlandialogue_create_sboard_bg_panel_and_cache_child_jobjs, global
/* 80185848 00182648  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8018584C 0018264C  7C 08 02 A6 */	mflr r0
/* 80185850 00182650  90 01 00 24 */	stw r0, 0x24(r1)
/* 80185854 00182654  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80185858 00182658  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8018585C 0018265C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80185860 00182660  4B FA B9 81 */	bl fn_801311E0
/* 80185864 00182664  7C 7E 1B 78 */	mr r30, r3
/* 80185868 00182668  80 63 11 A0 */	lwz r3, 0x11a0(r3)
/* 8018586C 0018266C  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80185870 00182670  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80185874 00182674  4B FB 30 35 */	bl fn_801388A8
/* 80185878 00182678  38 80 00 C3 */	li r4, 0xc3
/* 8018587C 0018267C  7C 7D 1B 78 */	mr r29, r3
/* 80185880 00182680  4B FB 31 81 */	bl kar_diag__80138a00
/* 80185884 00182684  7C 7F 1B 78 */	mr r31, r3
/* 80185888 00182688  7F A3 EB 78 */	mr r3, r29
/* 8018588C 0018268C  38 80 00 14 */	li r4, 0x14
/* 80185890 00182690  4B ED 02 61 */	bl kar_lbairride__near_80055af0
/* 80185894 00182694  90 7F 00 0C */	stw r3, 0xc(r31)
/* 80185898 00182698  7F A3 EB 78 */	mr r3, r29
/* 8018589C 0018269C  38 80 00 13 */	li r4, 0x13
/* 801858A0 001826A0  4B ED 02 51 */	bl kar_lbairride__near_80055af0
/* 801858A4 001826A4  90 7F 00 10 */	stw r3, 0x10(r31)
/* 801858A8 001826A8  7F A3 EB 78 */	mr r3, r29
/* 801858AC 001826AC  38 80 00 0D */	li r4, 0xd
/* 801858B0 001826B0  4B ED 02 41 */	bl kar_lbairride__near_80055af0
/* 801858B4 001826B4  90 7F 00 14 */	stw r3, 0x14(r31)
/* 801858B8 001826B8  7F A3 EB 78 */	mr r3, r29
/* 801858BC 001826BC  38 80 00 12 */	li r4, 0x12
/* 801858C0 001826C0  4B ED 02 31 */	bl kar_lbairride__near_80055af0
/* 801858C4 001826C4  3C 80 80 18 */	lis r4, kar_mnlandialogue_proc_anim_sboard_bg_panel@ha
/* 801858C8 001826C8  90 7F 00 18 */	stw r3, 0x18(r31)
/* 801858CC 001826CC  38 84 57 D8 */	addi r4, r4, kar_mnlandialogue_proc_anim_sboard_bg_panel@l
/* 801858D0 001826D0  7F A3 EB 78 */	mr r3, r29
/* 801858D4 001826D4  38 A0 00 01 */	li r5, 0x1
/* 801858D8 001826D8  48 2A 2F CD */	bl HSD_GObjProcCreate
/* 801858DC 001826DC  93 BE 11 A4 */	stw r29, 0x11a4(r30)
/* 801858E0 001826E0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801858E4 001826E4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801858E8 001826E8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801858EC 001826EC  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 801858F0 001826F0  7C 08 03 A6 */	mtlr r0
/* 801858F4 001826F4  38 21 00 20 */	addi r1, r1, 0x20
/* 801858F8 001826F8  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_create_sboard_bg_panel_and_cache_child_jobjs

# .text:0x1EA4 | 0x801858FC | size: 0x44
.fn kar_mnlandialogue_destroy_sboard_bg_panel, global
/* 801858FC 001826FC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80185900 00182700  7C 08 02 A6 */	mflr r0
/* 80185904 00182704  90 01 00 14 */	stw r0, 0x14(r1)
/* 80185908 00182708  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8018590C 0018270C  4B FA B8 D5 */	bl fn_801311E0
/* 80185910 00182710  7C 7F 1B 78 */	mr r31, r3
/* 80185914 00182714  80 63 11 A4 */	lwz r3, 0x11a4(r3)
/* 80185918 00182718  28 03 00 00 */	cmplwi r3, 0x0
/* 8018591C 0018271C  41 82 00 10 */	beq .L_8018592C
/* 80185920 00182720  48 2A 36 45 */	bl HSD_GObjDestroy
/* 80185924 00182724  38 00 00 00 */	li r0, 0x0
/* 80185928 00182728  90 1F 11 A4 */	stw r0, 0x11a4(r31)
.L_8018592C:
/* 8018592C 0018272C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80185930 00182730  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80185934 00182734  7C 08 03 A6 */	mtlr r0
/* 80185938 00182738  38 21 00 10 */	addi r1, r1, 0x10
/* 8018593C 0018273C  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_destroy_sboard_bg_panel
