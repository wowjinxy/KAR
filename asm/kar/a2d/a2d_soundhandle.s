.include "macros.inc"
.file "a2d_soundhandle.cpp"

# 0x80379B1C..0x80379F94 | size: 0x478
.text
.balign 4

# .text:0x0 | 0x80379B1C | size: 0xDC
.fn kar_a2d_soundhandle__80379b1c, global
/* 80379B1C 0037691C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80379B20 00376920  7C 08 02 A6 */	mflr r0
/* 80379B24 00376924  90 01 00 24 */	stw r0, 0x24(r1)
/* 80379B28 00376928  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80379B2C 0037692C  7C 7F 1B 78 */	mr r31, r3
/* 80379B30 00376930  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80379B34 00376934  7C BE 2B 78 */	mr r30, r5
/* 80379B38 00376938  28 1E 00 03 */	cmplwi r30, 0x3
/* 80379B3C 0037693C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80379B40 00376940  7C 9D 23 78 */	mr r29, r4
/* 80379B44 00376944  41 80 00 1C */	blt .L_80379B60
/* 80379B48 00376948  3C 60 80 4F */	lis r3, kar_src_a2d_soundhandle_804f2b00@ha
/* 80379B4C 0037694C  3C A0 80 4F */	lis r5, lbl_804F2B14@ha
/* 80379B50 00376950  38 63 2B 00 */	addi r3, r3, kar_src_a2d_soundhandle_804f2b00@l
/* 80379B54 00376954  38 80 00 BE */	li r4, 0xbe
/* 80379B58 00376958  38 A5 2B 14 */	addi r5, r5, lbl_804F2B14@l
/* 80379B5C 0037695C  48 0A E9 5D */	bl __assert
.L_80379B60:
/* 80379B60 00376960  1C BD 00 0C */	mulli r5, r29, 0xc
/* 80379B64 00376964  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 80379B68 00376968  3C 80 80 49 */	lis r4, lbl_8048B3D0@ha
/* 80379B6C 0037696C  2C 03 FF FF */	cmpwi r3, -0x1
/* 80379B70 00376970  38 84 B3 D0 */	addi r4, r4, lbl_8048B3D0@l
/* 80379B74 00376974  57 C0 10 3A */	slwi r0, r30, 2
/* 80379B78 00376978  7C 84 2A 14 */	add r4, r4, r5
/* 80379B7C 0037697C  7F C4 00 2E */	lwzx r30, r4, r0
/* 80379B80 00376980  41 82 00 2C */	beq .L_80379BAC
/* 80379B84 00376984  80 1F 00 10 */	lwz r0, 0x10(r31)
/* 80379B88 00376988  7C 1E 00 00 */	cmpw r30, r0
/* 80379B8C 0037698C  40 82 00 20 */	bne .L_80379BAC
/* 80379B90 00376990  4B CE 45 79 */	bl kar_lbaudio_is_track_handle_playing
/* 80379B94 00376994  7C 03 00 D0 */	neg r0, r3
/* 80379B98 00376998  7C 00 1B 78 */	or r0, r0, r3
/* 80379B9C 0037699C  54 00 0F FF */	srwi. r0, r0, 31
/* 80379BA0 003769A0  41 82 00 0C */	beq .L_80379BAC
/* 80379BA4 003769A4  38 60 00 00 */	li r3, 0x0
/* 80379BA8 003769A8  48 00 00 34 */	b .L_80379BDC
.L_80379BAC:
/* 80379BAC 003769AC  7F C3 F3 78 */	mr r3, r30
/* 80379BB0 003769B0  38 80 00 7F */	li r4, 0x7f
/* 80379BB4 003769B4  38 A0 00 00 */	li r5, 0x0
/* 80379BB8 003769B8  4B CE 7C 7D */	bl kar_lbaudio__near_80061834
/* 80379BBC 003769BC  90 7F 00 0C */	stw r3, 0xc(r31)
/* 80379BC0 003769C0  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 80379BC4 003769C4  2C 00 FF FF */	cmpwi r0, -0x1
/* 80379BC8 003769C8  41 82 00 10 */	beq .L_80379BD8
/* 80379BCC 003769CC  93 DF 00 10 */	stw r30, 0x10(r31)
/* 80379BD0 003769D0  38 60 00 01 */	li r3, 0x1
/* 80379BD4 003769D4  48 00 00 08 */	b .L_80379BDC
.L_80379BD8:
/* 80379BD8 003769D8  38 60 00 00 */	li r3, 0x0
.L_80379BDC:
/* 80379BDC 003769DC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80379BE0 003769E0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80379BE4 003769E4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80379BE8 003769E8  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80379BEC 003769EC  7C 08 03 A6 */	mtlr r0
/* 80379BF0 003769F0  38 21 00 20 */	addi r1, r1, 0x20
/* 80379BF4 003769F4  4E 80 00 20 */	blr
.endfn kar_a2d_soundhandle__80379b1c

# .text:0xDC | 0x80379BF8 | size: 0xE4
.fn kar_a2d_soundhandle__near_80379bf8, global
/* 80379BF8 003769F8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80379BFC 003769FC  7C 08 02 A6 */	mflr r0
/* 80379C00 00376A00  38 80 00 00 */	li r4, 0x0
/* 80379C04 00376A04  38 AD EB 08 */	li r5, lbl_805DBBE8@sda21
/* 80379C08 00376A08  90 01 00 14 */	stw r0, 0x14(r1)
/* 80379C0C 00376A0C  38 CD EB 00 */	li r6, lbl_805DBBE0@sda21
/* 80379C10 00376A10  38 E0 00 00 */	li r7, 0x0
/* 80379C14 00376A14  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80379C18 00376A18  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80379C1C 00376A1C  7C 7E 1B 78 */	mr r30, r3
/* 80379C20 00376A20  80 6D 0A 14 */	lwz r3, lbl_805DDAF4@sda21(r0)
/* 80379C24 00376A24  83 FE 00 8C */	lwz r31, 0x8c(r30)
/* 80379C28 00376A28  48 03 3B 39 */	bl kar_diag__803ad760
/* 80379C2C 00376A2C  48 00 00 40 */	b .L_80379C6C
.L_80379C30:
/* 80379C30 00376A30  80 83 00 3C */	lwz r4, 0x3c(r3)
/* 80379C34 00376A34  28 04 00 00 */	cmplwi r4, 0x0
/* 80379C38 00376A38  41 82 00 24 */	beq .L_80379C5C
/* 80379C3C 00376A3C  A0 84 00 1C */	lhz r4, 0x1c(r4)
/* 80379C40 00376A40  A0 1F 00 1C */	lhz r0, 0x1c(r31)
/* 80379C44 00376A44  7C 04 00 40 */	cmplw r4, r0
/* 80379C48 00376A48  40 82 00 14 */	bne .L_80379C5C
/* 80379C4C 00376A4C  80 03 00 2C */	lwz r0, 0x2c(r3)
/* 80379C50 00376A50  28 00 00 00 */	cmplwi r0, 0x0
/* 80379C54 00376A54  41 82 00 08 */	beq .L_80379C5C
/* 80379C58 00376A58  48 00 00 20 */	b .L_80379C78
.L_80379C5C:
/* 80379C5C 00376A5C  81 83 00 00 */	lwz r12, 0x0(r3)
/* 80379C60 00376A60  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80379C64 00376A64  7D 89 03 A6 */	mtctr r12
/* 80379C68 00376A68  4E 80 04 21 */	bctrl
.L_80379C6C:
/* 80379C6C 00376A6C  28 03 00 00 */	cmplwi r3, 0x0
/* 80379C70 00376A70  40 82 FF C0 */	bne .L_80379C30
/* 80379C74 00376A74  38 60 00 00 */	li r3, 0x0
.L_80379C78:
/* 80379C78 00376A78  28 03 00 00 */	cmplwi r3, 0x0
/* 80379C7C 00376A7C  41 82 00 44 */	beq .L_80379CC0
/* 80379C80 00376A80  80 03 00 2C */	lwz r0, 0x2c(r3)
/* 80379C84 00376A84  28 00 00 00 */	cmplwi r0, 0x0
/* 80379C88 00376A88  41 82 00 38 */	beq .L_80379CC0
/* 80379C8C 00376A8C  A0 1E 00 9C */	lhz r0, 0x9c(r30)
/* 80379C90 00376A90  C0 22 E4 58 */	lfs f1, lbl_805E4B58@sda21(r0)
/* 80379C94 00376A94  60 00 00 02 */	ori r0, r0, 0x2
/* 80379C98 00376A98  C0 02 E4 5C */	lfs f0, lbl_805E4B5C@sda21(r0)
/* 80379C9C 00376A9C  B0 1E 00 9C */	sth r0, 0x9c(r30)
/* 80379CA0 00376AA0  D0 3E 00 AC */	stfs f1, 0xac(r30)
/* 80379CA4 00376AA4  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 80379CA8 00376AA8  C0 24 00 00 */	lfs f1, 0x0(r4)
/* 80379CAC 00376AAC  D0 3E 00 A0 */	stfs f1, 0xa0(r30)
/* 80379CB0 00376AB0  D0 1E 00 A4 */	stfs f0, 0xa4(r30)
/* 80379CB4 00376AB4  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80379CB8 00376AB8  C0 03 00 08 */	lfs f0, 0x8(r3)
/* 80379CBC 00376ABC  D0 1E 00 A8 */	stfs f0, 0xa8(r30)
.L_80379CC0:
/* 80379CC0 00376AC0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80379CC4 00376AC4  38 60 00 00 */	li r3, 0x0
/* 80379CC8 00376AC8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80379CCC 00376ACC  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80379CD0 00376AD0  7C 08 03 A6 */	mtlr r0
/* 80379CD4 00376AD4  38 21 00 10 */	addi r1, r1, 0x10
/* 80379CD8 00376AD8  4E 80 00 20 */	blr
.endfn kar_a2d_soundhandle__near_80379bf8

# .text:0x1C0 | 0x80379CDC | size: 0x4C
.fn kar_a2d_soundhandle__near_80379cdc, global
/* 80379CDC 00376ADC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80379CE0 00376AE0  7C 08 02 A6 */	mflr r0
/* 80379CE4 00376AE4  38 80 00 00 */	li r4, 0x0
/* 80379CE8 00376AE8  38 AD EB 18 */	li r5, lbl_805DBBF8@sda21
/* 80379CEC 00376AEC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80379CF0 00376AF0  38 CD EB 10 */	li r6, lbl_805DBBF0@sda21
/* 80379CF4 00376AF4  38 E0 00 00 */	li r7, 0x0
/* 80379CF8 00376AF8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80379CFC 00376AFC  7C 7F 1B 78 */	mr r31, r3
/* 80379D00 00376B00  80 6D 0A B0 */	lwz r3, lbl_805DDB90@sda21(r0)
/* 80379D04 00376B04  48 03 3A 5D */	bl kar_diag__803ad760
/* 80379D08 00376B08  7F E4 FB 78 */	mr r4, r31
/* 80379D0C 00376B0C  48 00 00 D9 */	bl kar_a2d_soundhandle__near_80379de4
/* 80379D10 00376B10  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80379D14 00376B14  38 60 00 00 */	li r3, 0x0
/* 80379D18 00376B18  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80379D1C 00376B1C  7C 08 03 A6 */	mtlr r0
/* 80379D20 00376B20  38 21 00 10 */	addi r1, r1, 0x10
/* 80379D24 00376B24  4E 80 00 20 */	blr
.endfn kar_a2d_soundhandle__near_80379cdc

# .text:0x20C | 0x80379D28 | size: 0xBC
.fn kar_a2d_soundhandle__near_80379d28, global
/* 80379D28 00376B28  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80379D2C 00376B2C  7C 08 02 A6 */	mflr r0
/* 80379D30 00376B30  90 01 00 14 */	stw r0, 0x14(r1)
/* 80379D34 00376B34  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80379D38 00376B38  7C 9F 23 78 */	mr r31, r4
/* 80379D3C 00376B3C  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80379D40 00376B40  7C 7E 1B 79 */	mr. r30, r3
/* 80379D44 00376B44  41 82 00 7C */	beq .L_80379DC0
/* 80379D48 00376B48  80 6D 0A 14 */	lwz r3, lbl_805DDAF4@sda21(r0)
/* 80379D4C 00376B4C  38 80 00 00 */	li r4, 0x0
/* 80379D50 00376B50  38 AD EB 08 */	li r5, lbl_805DBBE8@sda21
/* 80379D54 00376B54  38 CD EB 00 */	li r6, lbl_805DBBE0@sda21
/* 80379D58 00376B58  38 E0 00 00 */	li r7, 0x0
/* 80379D5C 00376B5C  48 03 3A 05 */	bl kar_diag__803ad760
/* 80379D60 00376B60  48 00 00 30 */	b .L_80379D90
.L_80379D64:
/* 80379D64 00376B64  80 03 00 3C */	lwz r0, 0x3c(r3)
/* 80379D68 00376B68  7C 00 F0 40 */	cmplw r0, r30
/* 80379D6C 00376B6C  40 82 00 14 */	bne .L_80379D80
/* 80379D70 00376B70  80 03 00 2C */	lwz r0, 0x2c(r3)
/* 80379D74 00376B74  28 00 00 00 */	cmplwi r0, 0x0
/* 80379D78 00376B78  41 82 00 08 */	beq .L_80379D80
/* 80379D7C 00376B7C  48 00 00 20 */	b .L_80379D9C
.L_80379D80:
/* 80379D80 00376B80  81 83 00 00 */	lwz r12, 0x0(r3)
/* 80379D84 00376B84  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80379D88 00376B88  7D 89 03 A6 */	mtctr r12
/* 80379D8C 00376B8C  4E 80 04 21 */	bctrl
.L_80379D90:
/* 80379D90 00376B90  28 03 00 00 */	cmplwi r3, 0x0
/* 80379D94 00376B94  40 82 FF D0 */	bne .L_80379D64
/* 80379D98 00376B98  38 60 00 00 */	li r3, 0x0
.L_80379D9C:
/* 80379D9C 00376B9C  28 03 00 00 */	cmplwi r3, 0x0
/* 80379DA0 00376BA0  41 82 00 20 */	beq .L_80379DC0
/* 80379DA4 00376BA4  80 03 00 2C */	lwz r0, 0x2c(r3)
/* 80379DA8 00376BA8  28 00 00 00 */	cmplwi r0, 0x0
/* 80379DAC 00376BAC  41 82 00 14 */	beq .L_80379DC0
/* 80379DB0 00376BB0  3C 80 80 4F */	lis r4, lbl_804F2CB0@ha
/* 80379DB4 00376BB4  7F E3 FB 78 */	mr r3, r31
/* 80379DB8 00376BB8  38 84 2C B0 */	addi r4, r4, lbl_804F2CB0@l
/* 80379DBC 00376BBC  48 0B 1C A5 */	bl kar_particle__near_8042ba60
.L_80379DC0:
/* 80379DC0 00376BC0  3C 60 80 38 */	lis r3, kar_a2d_soundhandle__near_80379cdc@ha
/* 80379DC4 00376BC4  38 03 9C DC */	addi r0, r3, kar_a2d_soundhandle__near_80379cdc@l
/* 80379DC8 00376BC8  90 1F 00 5C */	stw r0, 0x5c(r31)
/* 80379DCC 00376BCC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80379DD0 00376BD0  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80379DD4 00376BD4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80379DD8 00376BD8  7C 08 03 A6 */	mtlr r0
/* 80379DDC 00376BDC  38 21 00 10 */	addi r1, r1, 0x10
/* 80379DE0 00376BE0  4E 80 00 20 */	blr
.endfn kar_a2d_soundhandle__near_80379d28

# .text:0x2C8 | 0x80379DE4 | size: 0x74
.fn kar_a2d_soundhandle__near_80379de4, global
/* 80379DE4 00376BE4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80379DE8 00376BE8  7C 08 02 A6 */	mflr r0
/* 80379DEC 00376BEC  38 AD EB 08 */	li r5, lbl_805DBBE8@sda21
/* 80379DF0 00376BF0  38 CD EB 00 */	li r6, lbl_805DBBE0@sda21
/* 80379DF4 00376BF4  90 01 00 14 */	stw r0, 0x14(r1)
/* 80379DF8 00376BF8  38 E0 00 00 */	li r7, 0x0
/* 80379DFC 00376BFC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80379E00 00376C00  7C 9F 23 78 */	mr r31, r4
/* 80379E04 00376C04  38 80 00 00 */	li r4, 0x0
/* 80379E08 00376C08  80 6D 0A 14 */	lwz r3, lbl_805DDAF4@sda21(r0)
/* 80379E0C 00376C0C  48 03 39 55 */	bl kar_diag__803ad760
/* 80379E10 00376C10  48 00 00 2C */	b .L_80379E3C
.L_80379E14:
/* 80379E14 00376C14  80 03 00 3C */	lwz r0, 0x3c(r3)
/* 80379E18 00376C18  7C 00 F8 40 */	cmplw r0, r31
/* 80379E1C 00376C1C  40 82 00 10 */	bne .L_80379E2C
/* 80379E20 00376C20  38 00 00 00 */	li r0, 0x0
/* 80379E24 00376C24  90 03 00 3C */	stw r0, 0x3c(r3)
/* 80379E28 00376C28  48 00 00 1C */	b .L_80379E44
.L_80379E2C:
/* 80379E2C 00376C2C  81 83 00 00 */	lwz r12, 0x0(r3)
/* 80379E30 00376C30  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80379E34 00376C34  7D 89 03 A6 */	mtctr r12
/* 80379E38 00376C38  4E 80 04 21 */	bctrl
.L_80379E3C:
/* 80379E3C 00376C3C  28 03 00 00 */	cmplwi r3, 0x0
/* 80379E40 00376C40  40 82 FF D4 */	bne .L_80379E14
.L_80379E44:
/* 80379E44 00376C44  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80379E48 00376C48  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80379E4C 00376C4C  7C 08 03 A6 */	mtlr r0
/* 80379E50 00376C50  38 21 00 10 */	addi r1, r1, 0x10
/* 80379E54 00376C54  4E 80 00 20 */	blr
.endfn kar_a2d_soundhandle__near_80379de4

# .text:0x33C | 0x80379E58 | size: 0x13C
.fn kar_a2d_soundhandle__near_80379e58, global
/* 80379E58 00376C58  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80379E5C 00376C5C  7C 08 02 A6 */	mflr r0
/* 80379E60 00376C60  3C 80 80 4F */	lis r4, lbl_804F2B30@ha
/* 80379E64 00376C64  90 01 00 34 */	stw r0, 0x34(r1)
/* 80379E68 00376C68  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 80379E6C 00376C6C  7C 7F 1B 78 */	mr r31, r3
/* 80379E70 00376C70  38 60 00 00 */	li r3, 0x0
/* 80379E74 00376C74  93 C1 00 28 */	stw r30, 0x28(r1)
/* 80379E78 00376C78  3B C4 2B 30 */	addi r30, r4, lbl_804F2B30@l
/* 80379E7C 00376C7C  48 0B 0E C9 */	bl kar_particle__near_8042ad44
/* 80379E80 00376C80  38 60 00 00 */	li r3, 0x0
/* 80379E84 00376C84  48 0B 64 15 */	bl kar_psinterpret__near_80430298
/* 80379E88 00376C88  38 60 00 40 */	li r3, 0x40
/* 80379E8C 00376C8C  38 80 00 80 */	li r4, 0x80
/* 80379E90 00376C90  48 0B DD 61 */	bl kar_psdisp__near_80437bf0
/* 80379E94 00376C94  3C 60 80 43 */	lis r3, kar_generator__near_80433098@ha
/* 80379E98 00376C98  38 63 30 98 */	addi r3, r3, kar_generator__near_80433098@l
/* 80379E9C 00376C9C  48 09 0F 31 */	bl HSD_JObjSetJSoundCallback
/* 80379EA0 00376CA0  3C 60 80 43 */	lis r3, kar_generator__near_804328a0@ha
/* 80379EA4 00376CA4  38 63 28 A0 */	addi r3, r3, kar_generator__near_804328a0@l
/* 80379EA8 00376CA8  48 09 3D B9 */	bl HSD_JObjSetDPtclCallback
/* 80379EAC 00376CAC  3C 60 80 43 */	lis r3, kar_particle__near_8042b6a0@ha
/* 80379EB0 00376CB0  38 63 B6 A0 */	addi r3, r3, kar_particle__near_8042b6a0@l
/* 80379EB4 00376CB4  48 09 3D B5 */	bl HSD_JObjSetPtclTargetCallback
/* 80379EB8 00376CB8  3C 80 80 38 */	lis r4, kar_a2d_soundhandle__near_80379d28@ha
/* 80379EBC 00376CBC  38 7E 01 EC */	addi r3, r30, 0x1ec
/* 80379EC0 00376CC0  38 84 9D 28 */	addi r4, r4, kar_a2d_soundhandle__near_80379d28@l
/* 80379EC4 00376CC4  38 00 00 00 */	li r0, 0x0
/* 80379EC8 00376CC8  90 8D 12 8C */	stw r4, lbl_805DE36C@sda21(r0)
/* 80379ECC 00376CCC  38 81 00 10 */	addi r4, r1, 0x10
/* 80379ED0 00376CD0  38 BE 01 BC */	addi r5, r30, 0x1bc
/* 80379ED4 00376CD4  38 C1 00 18 */	addi r6, r1, 0x18
/* 80379ED8 00376CD8  90 61 00 08 */	stw r3, 0x8(r1)
/* 80379EDC 00376CDC  38 FE 01 CC */	addi r7, r30, 0x1cc
/* 80379EE0 00376CE0  39 01 00 1C */	addi r8, r1, 0x1c
/* 80379EE4 00376CE4  39 3E 01 DC */	addi r9, r30, 0x1dc
/* 80379EE8 00376CE8  90 01 00 0C */	stw r0, 0xc(r1)
/* 80379EEC 00376CEC  39 41 00 14 */	addi r10, r1, 0x14
/* 80379EF0 00376CF0  80 7F 00 04 */	lwz r3, 0x4(r31)
/* 80379EF4 00376CF4  4C C6 31 82 */	crclr cr1eq
/* 80379EF8 00376CF8  4B CD F6 29 */	bl kar_lbarchive__near_80059520
/* 80379EFC 00376CFC  80 61 00 18 */	lwz r3, 0x18(r1)
/* 80379F00 00376D00  A0 03 00 02 */	lhz r0, 0x2(r3)
/* 80379F04 00376D04  B0 1F 00 0C */	sth r0, 0xc(r31)
/* 80379F08 00376D08  A0 7F 00 0C */	lhz r3, 0xc(r31)
/* 80379F0C 00376D0C  80 81 00 18 */	lwz r4, 0x18(r1)
/* 80379F10 00376D10  80 A1 00 14 */	lwz r5, 0x14(r1)
/* 80379F14 00376D14  80 C1 00 1C */	lwz r6, 0x1c(r1)
/* 80379F18 00376D18  80 E1 00 10 */	lwz r7, 0x10(r1)
/* 80379F1C 00376D1C  48 0B 0C CD */	bl kar_particle__8042abe8
/* 80379F20 00376D20  38 7E 02 20 */	addi r3, r30, 0x220
/* 80379F24 00376D24  38 00 00 00 */	li r0, 0x0
/* 80379F28 00376D28  90 61 00 08 */	stw r3, 0x8(r1)
/* 80379F2C 00376D2C  38 81 00 10 */	addi r4, r1, 0x10
/* 80379F30 00376D30  38 BE 01 FC */	addi r5, r30, 0x1fc
/* 80379F34 00376D34  38 C1 00 18 */	addi r6, r1, 0x18
/* 80379F38 00376D38  90 01 00 0C */	stw r0, 0xc(r1)
/* 80379F3C 00376D3C  38 FE 02 08 */	addi r7, r30, 0x208
/* 80379F40 00376D40  39 01 00 1C */	addi r8, r1, 0x1c
/* 80379F44 00376D44  39 3E 02 14 */	addi r9, r30, 0x214
/* 80379F48 00376D48  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80379F4C 00376D4C  39 41 00 14 */	addi r10, r1, 0x14
/* 80379F50 00376D50  4C C6 31 82 */	crclr cr1eq
/* 80379F54 00376D54  4B CD F5 CD */	bl kar_lbarchive__near_80059520
/* 80379F58 00376D58  80 61 00 18 */	lwz r3, 0x18(r1)
/* 80379F5C 00376D5C  A0 03 00 02 */	lhz r0, 0x2(r3)
/* 80379F60 00376D60  B0 1F 00 0E */	sth r0, 0xe(r31)
/* 80379F64 00376D64  A0 7F 00 0E */	lhz r3, 0xe(r31)
/* 80379F68 00376D68  80 81 00 18 */	lwz r4, 0x18(r1)
/* 80379F6C 00376D6C  80 A1 00 14 */	lwz r5, 0x14(r1)
/* 80379F70 00376D70  80 C1 00 1C */	lwz r6, 0x1c(r1)
/* 80379F74 00376D74  80 E1 00 10 */	lwz r7, 0x10(r1)
/* 80379F78 00376D78  48 0B 0C 71 */	bl kar_particle__8042abe8
/* 80379F7C 00376D7C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80379F80 00376D80  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 80379F84 00376D84  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 80379F88 00376D88  7C 08 03 A6 */	mtlr r0
/* 80379F8C 00376D8C  38 21 00 30 */	addi r1, r1, 0x30
/* 80379F90 00376D90  4E 80 00 20 */	blr
.endfn kar_a2d_soundhandle__near_80379e58

# 0x8048B3D0..0x8048B3F8 | size: 0x28
.rodata
.balign 8

# .rodata:0x0 | 0x8048B3D0 | size: 0x28
.obj lbl_8048B3D0, global
	.4byte 0x00060037
	.4byte 0x00060038
	.4byte 0x00060039
	.4byte 0x00060033
	.4byte 0x00060034
	.4byte 0x00060034
	.4byte 0x00060035
	.4byte 0x00060036
	.4byte 0x00060036
	.4byte 0x00000000
.endobj lbl_8048B3D0

# 0x804F2B00..0x804F3158 | size: 0x658
.data
.balign 8

# .data:0x0 | 0x804F2B00 | size: 0x14
.obj kar_src_a2d_soundhandle_804f2b00, global
	.string "a2d_soundhandle.cpp"
.endobj kar_src_a2d_soundhandle_804f2b00

# .data:0x14 | 0x804F2B14 | size: 0x19
.obj lbl_804F2B14, global
	.string "level < AudienceLevelMax"
.endobj lbl_804F2B14

# .data:0x2D | 0x804F2B2D | size: 0x3
.obj gap_07_804F2B2D_data, global
.hidden gap_07_804F2B2D_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804F2B2D_data

# .data:0x30 | 0x804F2B30 | size: 0x12
.obj lbl_804F2B30, global
	.string "ModelEffectRipple"
.endobj lbl_804F2B30

# .data:0x42 | 0x804F2B42 | size: 0x2
.obj gap_07_804F2B42_data, global
.hidden gap_07_804F2B42_data
	.2byte 0x0000
.endobj gap_07_804F2B42_data

# .data:0x44 | 0x804F2B44 | size: 0x1E
.obj lbl_804F2B44, global
	.string "ObjCollect<ModelEffectRipple>"
.endobj lbl_804F2B44

# .data:0x62 | 0x804F2B62 | size: 0x2
.obj gap_07_804F2B62_data, global
.hidden gap_07_804F2B62_data
	.2byte 0x0000
.endobj gap_07_804F2B62_data

# .data:0x64 | 0x804F2B64 | size: 0xC
.obj lbl_804F2B64, global
	.4byte lbl_805DBB88
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804F2B64

# .data:0x70 | 0x804F2B70 | size: 0xF
.obj lbl_804F2B70, global
	.string "PostDrawEffect"
.endobj lbl_804F2B70

# .data:0x7F | 0x804F2B7F | size: 0x1
.obj gap_07_804F2B7F_data, global
.hidden gap_07_804F2B7F_data
	.byte 0x00
.endobj gap_07_804F2B7F_data

# .data:0x80 | 0x804F2B80 | size: 0x1B
.obj lbl_804F2B80, global
	.string "ObjCollect<PostDrawEffect>"
.endobj lbl_804F2B80

# .data:0x9B | 0x804F2B9B | size: 0x1
.obj gap_07_804F2B9B_data, global
.hidden gap_07_804F2B9B_data
	.byte 0x00
.endobj gap_07_804F2B9B_data

# .data:0x9C | 0x804F2B9C | size: 0xC
.obj lbl_804F2B9C, global
	.4byte lbl_805DBB98
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804F2B9C

# .data:0xA8 | 0x804F2BA8 | size: 0xE
.obj lbl_804F2BA8, global
	.string "EffectLantern"
.endobj lbl_804F2BA8

# .data:0xB6 | 0x804F2BB6 | size: 0x2
.obj gap_07_804F2BB6_data, global
.hidden gap_07_804F2BB6_data
	.2byte 0x0000
.endobj gap_07_804F2BB6_data

# .data:0xB8 | 0x804F2BB8 | size: 0x1A
.obj lbl_804F2BB8, global
	.string "ObjCollect<EffectLantern>"
.endobj lbl_804F2BB8

# .data:0xD2 | 0x804F2BD2 | size: 0x2
.obj gap_07_804F2BD2_data, global
.hidden gap_07_804F2BD2_data
	.2byte 0x0000
.endobj gap_07_804F2BD2_data

# .data:0xD4 | 0x804F2BD4 | size: 0xC
.obj lbl_804F2BD4, global
	.4byte lbl_805DBBA8
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804F2BD4

# .data:0xE0 | 0x804F2BE0 | size: 0xB
.obj lbl_804F2BE0, global
	.string "CommicSign"
.endobj lbl_804F2BE0

# .data:0xEB | 0x804F2BEB | size: 0x1
.obj gap_07_804F2BEB_data, global
.hidden gap_07_804F2BEB_data
	.byte 0x00
.endobj gap_07_804F2BEB_data

# .data:0xEC | 0x804F2BEC | size: 0x17
.obj lbl_804F2BEC, global
	.string "ObjCollect<CommicSign>"
.endobj lbl_804F2BEC

# .data:0x103 | 0x804F2C03 | size: 0x1
.obj gap_07_804F2C03_data, global
.hidden gap_07_804F2C03_data
	.byte 0x00
.endobj gap_07_804F2C03_data

# .data:0x104 | 0x804F2C04 | size: 0x18
.obj lbl_804F2C04, global
	.4byte lbl_805DBBB8
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x47616D65
	.4byte 0x53637269
	.4byte 0x70740000
.endobj lbl_804F2C04

# .data:0x11C | 0x804F2C1C | size: 0x24
.obj lbl_804F2C1C, global
	.4byte 0x4F626A43
	.4byte 0x6F6C6C65
	.4byte 0x63743C47
	.4byte 0x616D6553
	.4byte 0x63726970
	.4byte 0x743E0000
	.4byte lbl_805DBBC8
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804F2C1C

# .data:0x140 | 0x804F2C40 | size: 0xE
.obj lbl_804F2C40, global
	.string "EffectMapFade"
.endobj lbl_804F2C40

# .data:0x14E | 0x804F2C4E | size: 0x2
.obj gap_07_804F2C4E_data, global
.hidden gap_07_804F2C4E_data
	.2byte 0x0000
.endobj gap_07_804F2C4E_data

# .data:0x150 | 0x804F2C50 | size: 0x1A
.obj lbl_804F2C50, global
	.string "ObjCollect<EffectMapFade>"
.endobj lbl_804F2C50

# .data:0x16A | 0x804F2C6A | size: 0x2
.obj gap_07_804F2C6A_data, global
.hidden gap_07_804F2C6A_data
	.2byte 0x0000
.endobj gap_07_804F2C6A_data

# .data:0x16C | 0x804F2C6C | size: 0xC
.obj lbl_804F2C6C, global
	.4byte lbl_805DBBD0
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804F2C6C

# .data:0x178 | 0x804F2C78 | size: 0xD
.obj lbl_804F2C78, global
	.string "EffectHandle"
.endobj lbl_804F2C78

# .data:0x185 | 0x804F2C85 | size: 0x3
.obj gap_07_804F2C85_data, global
.hidden gap_07_804F2C85_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804F2C85_data

# .data:0x188 | 0x804F2C88 | size: 0x19
.obj lbl_804F2C88, global
	.string "ObjCollect<EffectHandle>"
.endobj lbl_804F2C88

# .data:0x1A1 | 0x804F2CA1 | size: 0x3
.obj gap_07_804F2CA1_data, global
.hidden gap_07_804F2CA1_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804F2CA1_data

# .data:0x1A4 | 0x804F2CA4 | size: 0xC
.obj lbl_804F2CA4, global
	.4byte lbl_805DBBE0
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804F2CA4

# .data:0x1B0 | 0x804F2CB0 | size: 0xC
.obj lbl_804F2CB0, global
	.4byte kar_a2d_soundhandle__near_80379bf8
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804F2CB0

# .data:0x1BC | 0x804F2CBC | size: 0xB
.obj lbl_804F2CBC, global
	.string "GameEffect"
.endobj lbl_804F2CBC

# .data:0x1C7 | 0x804F2CC7 | size: 0x1
.obj gap_07_804F2CC7_data, global
.hidden gap_07_804F2CC7_data
	.byte 0x00
.endobj gap_07_804F2CC7_data

# .data:0x1C8 | 0x804F2CC8 | size: 0x16
.obj lbl_804F2CC8, global
	.string "Singleton<GameEffect>"
.endobj lbl_804F2CC8

# .data:0x1DE | 0x804F2CDE | size: 0x2
.obj gap_07_804F2CDE_data, global
.hidden gap_07_804F2CDE_data
	.2byte 0x0000
.endobj gap_07_804F2CDE_data

# .data:0x1E0 | 0x804F2CE0 | size: 0x178
.obj lbl_804F2CE0, global
	.4byte lbl_805DBBF0
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x61326463
	.4byte 0x6F6D6D6F
	.4byte 0x6E5F666F
	.4byte 0x726D0000
	.4byte 0x61326463
	.4byte 0x6F6D6D6F
	.4byte 0x6E5F7074
	.4byte 0x636C0000
	.4byte 0x61326463
	.4byte 0x6F6D6D6F
	.4byte 0x6E5F7265
	.4byte 0x66000000
	.4byte 0x61326463
	.4byte 0x6F6D6D6F
	.4byte 0x6E5F7465
	.4byte 0x78670000
	.4byte 0x636F7572
	.4byte 0x73655F66
	.4byte 0x6F726D00
	.4byte 0x636F7572
	.4byte 0x73655F70
	.4byte 0x74636C00
	.4byte 0x636F7572
	.4byte 0x73655F72
	.4byte 0x65660000
	.4byte 0x636F7572
	.4byte 0x73655F74
	.4byte 0x65786700
	.4byte 0x61326445
	.4byte 0x465F434D
	.4byte 0x30305F54
	.4byte 0x6F704E5F
	.4byte 0x6D6F6465
	.4byte 0x6C5F7365
	.4byte 0x74000000
	.4byte 0x6132645F
	.4byte 0x67616D65
	.4byte 0x5F656666
	.4byte 0x6563742E
	.4byte 0x63707000
	.4byte 0x6D6F6465
	.4byte 0x6C736574
	.4byte 0x00000000
	.4byte 0x61326445
	.4byte 0x465F434D
	.4byte 0x30315F73
	.4byte 0x63656E65
	.4byte 0x5F646174
	.4byte 0x61000000
	.4byte 0x7363656E
	.4byte 0x65646573
	.4byte 0x63000000
	.4byte 0x6132645F
	.4byte 0x77697065
	.4byte 0x65666665
	.4byte 0x63742E68
	.4byte 0x00000000
	.4byte 0x61326445
	.4byte 0x465F434D
	.4byte 0x30335F73
	.4byte 0x63656E65
	.4byte 0x5F646174
	.4byte 0x61000000
	.4byte 0x6132645F
	.4byte 0x636F6D6D
	.4byte 0x69637369
	.4byte 0x676E2E68
	.4byte 0x00000000
	.4byte 0x61326445
	.4byte 0x465F434D
	.4byte 0x30345F73
	.4byte 0x63656E65
	.4byte 0x5F646174
	.4byte 0x61000000
	.4byte 0x696D6167
	.4byte 0x655F6465
	.4byte 0x73630000
	.4byte 0x61326445
	.4byte 0x465F4235
	.4byte 0x30305F54
	.4byte 0x6F704E5F
	.4byte 0x6D6F6465
	.4byte 0x6C5F7365
	.4byte 0x74000000
	.4byte 0x61326445
	.4byte 0x465F4235
	.4byte 0x30315F54
	.4byte 0x6F704E5F
	.4byte 0x6D6F6465
	.4byte 0x6C5F7365
	.4byte 0x74000000
.endobj lbl_804F2CE0

# .data:0x358 | 0x804F2E58 | size: 0xC
.obj lbl_804F2E58, global
	.string "ModelEffect"
.endobj lbl_804F2E58

# .data:0x364 | 0x804F2E64 | size: 0x18
.obj lbl_804F2E64, global
	.string "ObjCollect<ModelEffect>"
.endobj lbl_804F2E64

# .data:0x37C | 0x804F2E7C | size: 0x20
.obj lbl_804F2E7C, global
	.4byte lbl_805DBC10
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x436F6D6D
	.4byte 0x69635369
	.4byte 0x676E436F
	.4byte 0x6E746169
	.4byte 0x6E657200
.endobj lbl_804F2E7C

# .data:0x39C | 0x804F2E9C | size: 0x5C
.obj lbl_804F2E9C, global
	.4byte 0x53696E67
	.4byte 0x6C65746F
	.4byte 0x6E3C436F
	.4byte 0x6D6D6963
	.4byte 0x5369676E
	.4byte 0x436F6E74
	.4byte 0x61696E65
	.4byte 0x723E0000
	.4byte lbl_805DBC20
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x45666665
	.4byte 0x63744D61
	.4byte 0x70466164
	.4byte 0x65436F6E
	.4byte 0x7461696E
	.4byte 0x65720000
.endobj lbl_804F2E9C

# .data:0x3F8 | 0x804F2EF8 | size: 0x5C
.obj lbl_804F2EF8, global
	.4byte 0x53696E67
	.4byte 0x6C65746F
	.4byte 0x6E3C4566
	.4byte 0x66656374
	.4byte 0x4D617046
	.4byte 0x61646543
	.4byte 0x6F6E7461
	.4byte 0x696E6572
	.4byte 0x3E000000
	.4byte lbl_805DBC28
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x45666665
	.4byte 0x6374536C
	.4byte 0x69646542
	.4byte 0x6C75724D
	.4byte 0x67720000
.endobj lbl_804F2EF8

# .data:0x454 | 0x804F2F54 | size: 0x5C
.obj lbl_804F2F54, global
	.4byte 0x53696E67
	.4byte 0x6C65746F
	.4byte 0x6E3C4566
	.4byte 0x66656374
	.4byte 0x536C6964
	.4byte 0x65426C75
	.4byte 0x724D6772
	.4byte 0x3E000000
	.4byte lbl_805DBC30
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x45666665
	.4byte 0x63744C61
	.4byte 0x6E746572
	.4byte 0x6E436F6E
	.4byte 0x7461696E
	.4byte 0x65720000
.endobj lbl_804F2F54

# .data:0x4B0 | 0x804F2FB0 | size: 0x5C
.obj lbl_804F2FB0, global
	.4byte 0x53696E67
	.4byte 0x6C65746F
	.4byte 0x6E3C4566
	.4byte 0x66656374
	.4byte 0x4C616E74
	.4byte 0x65726E43
	.4byte 0x6F6E7461
	.4byte 0x696E6572
	.4byte 0x3E000000
	.4byte lbl_805DBC38
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x57697065
	.4byte 0x45666665
	.4byte 0x6374436F
	.4byte 0x6E746169
	.4byte 0x6E657200
.endobj lbl_804F2FB0

# .data:0x50C | 0x804F300C | size: 0x5C
.obj lbl_804F300C, global
	.4byte 0x53696E67
	.4byte 0x6C65746F
	.4byte 0x6E3C5769
	.4byte 0x70654566
	.4byte 0x66656374
	.4byte 0x436F6E74
	.4byte 0x61696E65
	.4byte 0x723E0000
	.4byte lbl_805DBC40
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x506F7374
	.4byte 0x44726177
	.4byte 0x45666665
	.4byte 0x6374436F
	.4byte 0x6E746169
	.4byte 0x6E657200
.endobj lbl_804F300C

# .data:0x568 | 0x804F3068 | size: 0x60
.obj lbl_804F3068, global
	.4byte 0x53696E67
	.4byte 0x6C65746F
	.4byte 0x6E3C506F
	.4byte 0x73744472
	.4byte 0x61774566
	.4byte 0x66656374
	.4byte 0x436F6E74
	.4byte 0x61696E65
	.4byte 0x723E0000
	.4byte lbl_805DBC48
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x4D6F6465
	.4byte 0x6C456666
	.4byte 0x65637443
	.4byte 0x6F6E7461
	.4byte 0x696E6572
	.4byte 0x00000000
.endobj lbl_804F3068

# .data:0x5C8 | 0x804F30C8 | size: 0x60
.obj lbl_804F30C8, global
	.4byte 0x53696E67
	.4byte 0x6C65746F
	.4byte 0x6E3C4D6F
	.4byte 0x64656C45
	.4byte 0x66666563
	.4byte 0x74436F6E
	.4byte 0x7461696E
	.4byte 0x65723E00
	.4byte lbl_805DBC50
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
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804F30C8

# .data:0x628 | 0x804F3128 | size: 0xB
.obj lbl_804F3128, global
	.string "GameEffect"
.endobj lbl_804F3128

# .data:0x633 | 0x804F3133 | size: 0x1
.obj gap_07_804F3133_data, global
.hidden gap_07_804F3133_data
	.byte 0x00
.endobj gap_07_804F3133_data

# .data:0x634 | 0x804F3134 | size: 0x16
.obj lbl_804F3134, global
	.string "Singleton<GameEffect>"
.endobj lbl_804F3134

# .data:0x64A | 0x804F314A | size: 0x2
.obj gap_07_804F314A_data, global
.hidden gap_07_804F314A_data
	.2byte 0x0000
.endobj gap_07_804F314A_data

# .data:0x64C | 0x804F314C | size: 0xC
.obj lbl_804F314C, global
	.4byte lbl_805DBC58
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804F314C

# 0x805E4B58..0x805E4B60 | size: 0x8
.section .sdata2, "a"
.balign 8

# .sdata2:0x0 | 0x805E4B58 | size: 0x4
.obj lbl_805E4B58, global
	.float 1
.endobj lbl_805E4B58

# .sdata2:0x4 | 0x805E4B5C | size: 0x4
.obj lbl_805E4B5C, global
	.float 0
.endobj lbl_805E4B5C
