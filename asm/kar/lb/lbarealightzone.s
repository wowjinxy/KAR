.include "macros.inc"
.file "lbarealightzone.c"

# 0x8007AC30..0x8007ADE8 | size: 0x1B8
.text
.balign 4

# .text:0x0 | 0x8007AC30 | size: 0x98
.fn kar_lbarealightzone__8007ac30, global
/* 8007AC30 00077A30  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8007AC34 00077A34  7C 08 02 A6 */	mflr r0
/* 8007AC38 00077A38  3C 80 80 55 */	lis r4, lbl_805529A4@ha
/* 8007AC3C 00077A3C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8007AC40 00077A40  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8007AC44 00077A44  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8007AC48 00077A48  7C 7E 1B 78 */	mr r30, r3
/* 8007AC4C 00077A4C  38 64 29 A4 */	addi r3, r4, lbl_805529A4@l
/* 8007AC50 00077A50  48 39 D4 95 */	bl HSD_ObjAlloc
/* 8007AC54 00077A54  28 1E 00 00 */	cmplwi r30, 0x0
/* 8007AC58 00077A58  7C 7F 1B 78 */	mr r31, r3
/* 8007AC5C 00077A5C  40 82 00 1C */	bne .L_8007AC78
/* 8007AC60 00077A60  3C 60 80 4A */	lis r3, kar_src_lbarealightzone_8049ad98@ha
/* 8007AC64 00077A64  3C A0 80 4A */	lis r5, lbl_8049ADAC@ha
/* 8007AC68 00077A68  38 63 AD 98 */	addi r3, r3, kar_src_lbarealightzone_8049ad98@l
/* 8007AC6C 00077A6C  38 80 00 19 */	li r4, 0x19
/* 8007AC70 00077A70  38 A5 AD AC */	addi r5, r5, lbl_8049ADAC@l
/* 8007AC74 00077A74  48 3A D8 45 */	bl __assert
.L_8007AC78:
/* 8007AC78 00077A78  C0 1E 00 2C */	lfs f0, 0x2c(r30)
/* 8007AC7C 00077A7C  7F C4 F3 78 */	mr r4, r30
/* 8007AC80 00077A80  7F E5 FB 78 */	mr r5, r31
/* 8007AC84 00077A84  38 60 00 03 */	li r3, 0x3
/* 8007AC88 00077A88  D0 1F 00 24 */	stfs f0, 0x24(r31)
/* 8007AC8C 00077A8C  80 DE 00 30 */	lwz r6, 0x30(r30)
/* 8007AC90 00077A90  80 1E 00 34 */	lwz r0, 0x34(r30)
/* 8007AC94 00077A94  90 DF 00 28 */	stw r6, 0x28(r31)
/* 8007AC98 00077A98  90 1F 00 2C */	stw r0, 0x2c(r31)
/* 8007AC9C 00077A9C  80 1E 00 38 */	lwz r0, 0x38(r30)
/* 8007ACA0 00077AA0  90 1F 00 30 */	stw r0, 0x30(r31)
/* 8007ACA4 00077AA4  88 1E 00 3C */	lbz r0, 0x3c(r30)
/* 8007ACA8 00077AA8  98 1F 00 34 */	stb r0, 0x34(r31)
/* 8007ACAC 00077AAC  4B FF E7 7D */	bl kar_lbhvqm__near_80079428
/* 8007ACB0 00077AB0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8007ACB4 00077AB4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8007ACB8 00077AB8  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8007ACBC 00077ABC  7C 08 03 A6 */	mtlr r0
/* 8007ACC0 00077AC0  38 21 00 10 */	addi r1, r1, 0x10
/* 8007ACC4 00077AC4  4E 80 00 20 */	blr
.endfn kar_lbarealightzone__8007ac30

# .text:0x98 | 0x8007ACC8 | size: 0x40
.fn kar_lbarealightzone__near_8007acc8, global
/* 8007ACC8 00077AC8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8007ACCC 00077ACC  7C 08 02 A6 */	mflr r0
/* 8007ACD0 00077AD0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8007ACD4 00077AD4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8007ACD8 00077AD8  7C 7F 1B 78 */	mr r31, r3
/* 8007ACDC 00077ADC  3C 60 80 55 */	lis r3, lbl_805529A4@ha
/* 8007ACE0 00077AE0  80 9F 00 34 */	lwz r4, 0x34(r31)
/* 8007ACE4 00077AE4  38 63 29 A4 */	addi r3, r3, lbl_805529A4@l
/* 8007ACE8 00077AE8  48 39 D5 4D */	bl HSD_ObjFree
/* 8007ACEC 00077AEC  7F E3 FB 78 */	mr r3, r31
/* 8007ACF0 00077AF0  4B FF E8 29 */	bl kar_lbarealight__80079518
/* 8007ACF4 00077AF4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8007ACF8 00077AF8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8007ACFC 00077AFC  7C 08 03 A6 */	mtlr r0
/* 8007AD00 00077B00  38 21 00 10 */	addi r1, r1, 0x10
/* 8007AD04 00077B04  4E 80 00 20 */	blr
.endfn kar_lbarealightzone__near_8007acc8

# .text:0xD8 | 0x8007AD08 | size: 0x30
.fn kar_lbarealightzone__near_8007ad08, global
/* 8007AD08 00077B08  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8007AD0C 00077B0C  7C 08 02 A6 */	mflr r0
/* 8007AD10 00077B10  7C A6 2B 78 */	mr r6, r5
/* 8007AD14 00077B14  90 01 00 14 */	stw r0, 0x14(r1)
/* 8007AD18 00077B18  80 E4 00 00 */	lwz r7, 0x0(r4)
/* 8007AD1C 00077B1C  80 A7 00 34 */	lwz r5, 0x34(r7)
/* 8007AD20 00077B20  88 A5 00 34 */	lbz r5, 0x34(r5)
/* 8007AD24 00077B24  4B FF FA BD */	bl kar_lbarealightuser__near_8007a7e0
/* 8007AD28 00077B28  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8007AD2C 00077B2C  7C 08 03 A6 */	mtlr r0
/* 8007AD30 00077B30  38 21 00 10 */	addi r1, r1, 0x10
/* 8007AD34 00077B34  4E 80 00 20 */	blr
.endfn kar_lbarealightzone__near_8007ad08

# .text:0x108 | 0x8007AD38 | size: 0x20
.fn kar_lbarealightzone__near_8007ad38, global
/* 8007AD38 00077B38  80 A3 00 34 */	lwz r5, 0x34(r3)
/* 8007AD3C 00077B3C  80 64 00 00 */	lwz r3, 0x0(r4)
/* 8007AD40 00077B40  80 04 00 04 */	lwz r0, 0x4(r4)
/* 8007AD44 00077B44  90 65 00 28 */	stw r3, 0x28(r5)
/* 8007AD48 00077B48  90 05 00 2C */	stw r0, 0x2c(r5)
/* 8007AD4C 00077B4C  80 04 00 08 */	lwz r0, 0x8(r4)
/* 8007AD50 00077B50  90 05 00 30 */	stw r0, 0x30(r5)
/* 8007AD54 00077B54  4E 80 00 20 */	blr
.endfn kar_lbarealightzone__near_8007ad38

# .text:0x128 | 0x8007AD58 | size: 0x60
.fn kar_lbarealightzone__near_8007ad58, global
/* 8007AD58 00077B58  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8007AD5C 00077B5C  7C 08 02 A6 */	mflr r0
/* 8007AD60 00077B60  90 01 00 14 */	stw r0, 0x14(r1)
/* 8007AD64 00077B64  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8007AD68 00077B68  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8007AD6C 00077B6C  7C 9E 23 78 */	mr r30, r4
/* 8007AD70 00077B70  83 E5 00 34 */	lwz r31, 0x34(r5)
/* 8007AD74 00077B74  4B FF EA 35 */	bl kar_lbarealight__800797a8
/* 8007AD78 00077B78  C0 1E 00 2C */	lfs f0, 0x2c(r30)
/* 8007AD7C 00077B7C  D0 1F 00 24 */	stfs f0, 0x24(r31)
/* 8007AD80 00077B80  80 7E 00 30 */	lwz r3, 0x30(r30)
/* 8007AD84 00077B84  80 1E 00 34 */	lwz r0, 0x34(r30)
/* 8007AD88 00077B88  90 7F 00 28 */	stw r3, 0x28(r31)
/* 8007AD8C 00077B8C  90 1F 00 2C */	stw r0, 0x2c(r31)
/* 8007AD90 00077B90  80 1E 00 38 */	lwz r0, 0x38(r30)
/* 8007AD94 00077B94  90 1F 00 30 */	stw r0, 0x30(r31)
/* 8007AD98 00077B98  88 1E 00 3C */	lbz r0, 0x3c(r30)
/* 8007AD9C 00077B9C  98 1F 00 34 */	stb r0, 0x34(r31)
/* 8007ADA0 00077BA0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8007ADA4 00077BA4  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8007ADA8 00077BA8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8007ADAC 00077BAC  7C 08 03 A6 */	mtlr r0
/* 8007ADB0 00077BB0  38 21 00 10 */	addi r1, r1, 0x10
/* 8007ADB4 00077BB4  4E 80 00 20 */	blr
.endfn kar_lbarealightzone__near_8007ad58

# .text:0x188 | 0x8007ADB8 | size: 0x30
.fn kar_lbarealightzone__near_8007adb8, global
/* 8007ADB8 00077BB8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8007ADBC 00077BBC  7C 08 02 A6 */	mflr r0
/* 8007ADC0 00077BC0  3C 60 80 55 */	lis r3, lbl_80552A00@ha
/* 8007ADC4 00077BC4  38 80 00 24 */	li r4, 0x24
/* 8007ADC8 00077BC8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8007ADCC 00077BCC  38 63 2A 00 */	addi r3, r3, lbl_80552A00@l
/* 8007ADD0 00077BD0  38 A0 00 04 */	li r5, 0x4
/* 8007ADD4 00077BD4  48 39 D4 89 */	bl HSD_ObjAllocInit
/* 8007ADD8 00077BD8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8007ADDC 00077BDC  7C 08 03 A6 */	mtlr r0
/* 8007ADE0 00077BE0  38 21 00 10 */	addi r1, r1, 0x10
/* 8007ADE4 00077BE4  4E 80 00 20 */	blr
.endfn kar_lbarealightzone__near_8007adb8
