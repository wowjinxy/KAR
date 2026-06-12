.include "macros.inc"
.file "plclearcheckerlib.c"

# 0x8022DE74..0x80231B88 | size: 0x3D14
.text
.balign 4

# .text:0x0 | 0x8022DE74 | size: 0x54
.fn kar_plclearchecker_get_state_u32_840, global
/* 8022DE74 0022AC74  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022DE78 0022AC78  7C 08 02 A6 */	mflr r0
/* 8022DE7C 0022AC7C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022DE80 0022AC80  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022DE84 0022AC84  7C 7F 1B 78 */	mr r31, r3
/* 8022DE88 0022AC88  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022DE8C 0022AC8C  41 80 00 1C */	blt .L_8022DEA8
/* 8022DE90 0022AC90  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022DE94 0022AC94  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022DE98 0022AC98  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022DE9C 0022AC9C  38 80 00 53 */	li r4, 0x53
/* 8022DEA0 0022ACA0  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022DEA4 0022ACA4  48 1F A6 15 */	bl __assert
.L_8022DEA8:
/* 8022DEA8 0022ACA8  7F E3 FB 78 */	mr r3, r31
/* 8022DEAC 0022ACAC  4B FF F3 9D */	bl kar_plclearchecker_get_player_state
/* 8022DEB0 0022ACB0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022DEB4 0022ACB4  80 63 08 40 */	lwz r3, 0x840(r3)
/* 8022DEB8 0022ACB8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022DEBC 0022ACBC  7C 08 03 A6 */	mtlr r0
/* 8022DEC0 0022ACC0  38 21 00 10 */	addi r1, r1, 0x10
/* 8022DEC4 0022ACC4  4E 80 00 20 */	blr
.endfn kar_plclearchecker_get_state_u32_840

# .text:0x54 | 0x8022DEC8 | size: 0x54
.fn kar_plclearchecker_get_state_u32_844, global
/* 8022DEC8 0022ACC8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022DECC 0022ACCC  7C 08 02 A6 */	mflr r0
/* 8022DED0 0022ACD0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022DED4 0022ACD4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022DED8 0022ACD8  7C 7F 1B 78 */	mr r31, r3
/* 8022DEDC 0022ACDC  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022DEE0 0022ACE0  41 80 00 1C */	blt .L_8022DEFC
/* 8022DEE4 0022ACE4  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022DEE8 0022ACE8  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022DEEC 0022ACEC  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022DEF0 0022ACF0  38 80 00 5D */	li r4, 0x5d
/* 8022DEF4 0022ACF4  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022DEF8 0022ACF8  48 1F A5 C1 */	bl __assert
.L_8022DEFC:
/* 8022DEFC 0022ACFC  7F E3 FB 78 */	mr r3, r31
/* 8022DF00 0022AD00  4B FF F3 49 */	bl kar_plclearchecker_get_player_state
/* 8022DF04 0022AD04  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022DF08 0022AD08  80 63 08 44 */	lwz r3, 0x844(r3)
/* 8022DF0C 0022AD0C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022DF10 0022AD10  7C 08 03 A6 */	mtlr r0
/* 8022DF14 0022AD14  38 21 00 10 */	addi r1, r1, 0x10
/* 8022DF18 0022AD18  4E 80 00 20 */	blr
.endfn kar_plclearchecker_get_state_u32_844

# .text:0xA8 | 0x8022DF1C | size: 0x15C
.fn kar_plclearcheckerlib__near_8022df1c, global
/* 8022DF1C 0022AD1C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8022DF20 0022AD20  7C 08 02 A6 */	mflr r0
/* 8022DF24 0022AD24  90 01 00 24 */	stw r0, 0x24(r1)
/* 8022DF28 0022AD28  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8022DF2C 0022AD2C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8022DF30 0022AD30  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8022DF34 0022AD34  4B DD B2 D5 */	bl fn_80009208
/* 8022DF38 0022AD38  7C 7D 07 74 */	extsb r29, r3
/* 8022DF3C 0022AD3C  2C 1D 00 01 */	cmpwi r29, 0x1
/* 8022DF40 0022AD40  40 81 01 1C */	ble .L_8022E05C
/* 8022DF44 0022AD44  3B E0 00 00 */	li r31, 0x0
/* 8022DF48 0022AD48  7F FE FB 78 */	mr r30, r31
.L_8022DF4C:
/* 8022DF4C 0022AD4C  7F C3 F3 78 */	mr r3, r30
/* 8022DF50 0022AD50  4B FF E9 09 */	bl kar_plclearcheckerlib__near_8022c858
/* 8022DF54 0022AD54  2C 03 00 04 */	cmpwi r3, 0x4
/* 8022DF58 0022AD58  41 82 00 18 */	beq .L_8022DF70
/* 8022DF5C 0022AD5C  7F C3 F3 78 */	mr r3, r30
/* 8022DF60 0022AD60  4B FF F5 09 */	bl kar_plclearchecker_call_clobject_func_1926f4
/* 8022DF64 0022AD64  2C 03 00 00 */	cmpwi r3, 0x0
/* 8022DF68 0022AD68  41 82 00 08 */	beq .L_8022DF70
/* 8022DF6C 0022AD6C  3B FF 00 01 */	addi r31, r31, 0x1
.L_8022DF70:
/* 8022DF70 0022AD70  3B DE 00 01 */	addi r30, r30, 0x1
/* 8022DF74 0022AD74  2C 1E 00 04 */	cmpwi r30, 0x4
/* 8022DF78 0022AD78  41 80 FF D4 */	blt .L_8022DF4C
/* 8022DF7C 0022AD7C  3B C0 00 00 */	li r30, 0x0
.L_8022DF80:
/* 8022DF80 0022AD80  7F C3 F3 78 */	mr r3, r30
/* 8022DF84 0022AD84  4B FF E8 D5 */	bl kar_plclearcheckerlib__near_8022c858
/* 8022DF88 0022AD88  2C 03 00 04 */	cmpwi r3, 0x4
/* 8022DF8C 0022AD8C  41 82 00 54 */	beq .L_8022DFE0
/* 8022DF90 0022AD90  7F C3 F3 78 */	mr r3, r30
/* 8022DF94 0022AD94  4B FF F2 B5 */	bl kar_plclearchecker_get_player_state
/* 8022DF98 0022AD98  2C 1F 00 00 */	cmpwi r31, 0x0
/* 8022DF9C 0022AD9C  41 82 00 14 */	beq .L_8022DFB0
/* 8022DFA0 0022ADA0  80 83 08 3C */	lwz r4, 0x83c(r3)
/* 8022DFA4 0022ADA4  38 04 00 01 */	addi r0, r4, 0x1
/* 8022DFA8 0022ADA8  90 03 08 3C */	stw r0, 0x83c(r3)
/* 8022DFAC 0022ADAC  48 00 00 0C */	b .L_8022DFB8
.L_8022DFB0:
/* 8022DFB0 0022ADB0  38 00 00 00 */	li r0, 0x0
/* 8022DFB4 0022ADB4  90 03 08 3C */	stw r0, 0x83c(r3)
.L_8022DFB8:
/* 8022DFB8 0022ADB8  7C 1F E8 00 */	cmpw r31, r29
/* 8022DFBC 0022ADBC  40 82 00 24 */	bne .L_8022DFE0
/* 8022DFC0 0022ADC0  80 83 08 40 */	lwz r4, 0x840(r3)
/* 8022DFC4 0022ADC4  2C 04 FF FF */	cmpwi r4, -0x1
/* 8022DFC8 0022ADC8  41 82 00 10 */	beq .L_8022DFD8
/* 8022DFCC 0022ADCC  80 03 08 3C */	lwz r0, 0x83c(r3)
/* 8022DFD0 0022ADD0  7C 04 00 00 */	cmpw r4, r0
/* 8022DFD4 0022ADD4  40 81 00 0C */	ble .L_8022DFE0
.L_8022DFD8:
/* 8022DFD8 0022ADD8  80 03 08 3C */	lwz r0, 0x83c(r3)
/* 8022DFDC 0022ADDC  90 03 08 40 */	stw r0, 0x840(r3)
.L_8022DFE0:
/* 8022DFE0 0022ADE0  3B DE 00 01 */	addi r30, r30, 0x1
/* 8022DFE4 0022ADE4  2C 1E 00 04 */	cmpwi r30, 0x4
/* 8022DFE8 0022ADE8  41 80 FF 98 */	blt .L_8022DF80
/* 8022DFEC 0022ADEC  3B C0 00 00 */	li r30, 0x0
/* 8022DFF0 0022ADF0  7F DF F3 78 */	mr r31, r30
.L_8022DFF4:
/* 8022DFF4 0022ADF4  7F E3 FB 78 */	mr r3, r31
/* 8022DFF8 0022ADF8  4B FF E8 61 */	bl kar_plclearcheckerlib__near_8022c858
/* 8022DFFC 0022ADFC  2C 03 00 04 */	cmpwi r3, 0x4
/* 8022E000 0022AE00  41 82 00 18 */	beq .L_8022E018
/* 8022E004 0022AE04  7F E3 FB 78 */	mr r3, r31
/* 8022E008 0022AE08  4B FF E7 05 */	bl kar_plclearchecker_get_runtime_status
/* 8022E00C 0022AE0C  2C 03 00 01 */	cmpwi r3, 0x1
/* 8022E010 0022AE10  40 82 00 08 */	bne .L_8022E018
/* 8022E014 0022AE14  3B DE 00 01 */	addi r30, r30, 0x1
.L_8022E018:
/* 8022E018 0022AE18  3B FF 00 01 */	addi r31, r31, 0x1
/* 8022E01C 0022AE1C  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022E020 0022AE20  41 80 FF D4 */	blt .L_8022DFF4
/* 8022E024 0022AE24  3B E0 00 00 */	li r31, 0x0
.L_8022E028:
/* 8022E028 0022AE28  7F E3 FB 78 */	mr r3, r31
/* 8022E02C 0022AE2C  4B FF E8 2D */	bl kar_plclearcheckerlib__near_8022c858
/* 8022E030 0022AE30  2C 03 00 04 */	cmpwi r3, 0x4
/* 8022E034 0022AE34  41 82 00 1C */	beq .L_8022E050
/* 8022E038 0022AE38  7F E3 FB 78 */	mr r3, r31
/* 8022E03C 0022AE3C  4B FF F2 0D */	bl kar_plclearchecker_get_player_state
/* 8022E040 0022AE40  80 03 08 44 */	lwz r0, 0x844(r3)
/* 8022E044 0022AE44  7C 00 F0 40 */	cmplw r0, r30
/* 8022E048 0022AE48  40 80 00 08 */	bge .L_8022E050
/* 8022E04C 0022AE4C  93 C3 08 44 */	stw r30, 0x844(r3)
.L_8022E050:
/* 8022E050 0022AE50  3B FF 00 01 */	addi r31, r31, 0x1
/* 8022E054 0022AE54  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022E058 0022AE58  41 80 FF D0 */	blt .L_8022E028
.L_8022E05C:
/* 8022E05C 0022AE5C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8022E060 0022AE60  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8022E064 0022AE64  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8022E068 0022AE68  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8022E06C 0022AE6C  7C 08 03 A6 */	mtlr r0
/* 8022E070 0022AE70  38 21 00 20 */	addi r1, r1, 0x20
/* 8022E074 0022AE74  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_8022df1c

# .text:0x204 | 0x8022E078 | size: 0x58
.fn kar_plclearchecker_get_flag_854_bit7, global
/* 8022E078 0022AE78  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022E07C 0022AE7C  7C 08 02 A6 */	mflr r0
/* 8022E080 0022AE80  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022E084 0022AE84  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022E088 0022AE88  7C 7F 1B 78 */	mr r31, r3
/* 8022E08C 0022AE8C  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022E090 0022AE90  41 80 00 1C */	blt .L_8022E0AC
/* 8022E094 0022AE94  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E098 0022AE98  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E09C 0022AE9C  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E0A0 0022AEA0  38 80 00 B5 */	li r4, 0xb5
/* 8022E0A4 0022AEA4  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E0A8 0022AEA8  48 1F A4 11 */	bl __assert
.L_8022E0AC:
/* 8022E0AC 0022AEAC  7F E3 FB 78 */	mr r3, r31
/* 8022E0B0 0022AEB0  4B FF F1 99 */	bl kar_plclearchecker_get_player_state
/* 8022E0B4 0022AEB4  88 03 08 54 */	lbz r0, 0x854(r3)
/* 8022E0B8 0022AEB8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022E0BC 0022AEBC  54 03 CF FE */	extrwi r3, r0, 1, 24
/* 8022E0C0 0022AEC0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022E0C4 0022AEC4  7C 08 03 A6 */	mtlr r0
/* 8022E0C8 0022AEC8  38 21 00 10 */	addi r1, r1, 0x10
/* 8022E0CC 0022AECC  4E 80 00 20 */	blr
.endfn kar_plclearchecker_get_flag_854_bit7

# .text:0x25C | 0x8022E0D0 | size: 0x58
.fn kar_plclearchecker_get_flag_854_bit5, global
/* 8022E0D0 0022AED0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022E0D4 0022AED4  7C 08 02 A6 */	mflr r0
/* 8022E0D8 0022AED8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022E0DC 0022AEDC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022E0E0 0022AEE0  7C 7F 1B 78 */	mr r31, r3
/* 8022E0E4 0022AEE4  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022E0E8 0022AEE8  41 80 00 1C */	blt .L_8022E104
/* 8022E0EC 0022AEEC  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E0F0 0022AEF0  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E0F4 0022AEF4  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E0F8 0022AEF8  38 80 00 BE */	li r4, 0xbe
/* 8022E0FC 0022AEFC  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E100 0022AF00  48 1F A3 B9 */	bl __assert
.L_8022E104:
/* 8022E104 0022AF04  7F E3 FB 78 */	mr r3, r31
/* 8022E108 0022AF08  4B FF F1 41 */	bl kar_plclearchecker_get_player_state
/* 8022E10C 0022AF0C  88 03 08 54 */	lbz r0, 0x854(r3)
/* 8022E110 0022AF10  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022E114 0022AF14  54 03 DF FE */	extrwi r3, r0, 1, 26
/* 8022E118 0022AF18  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022E11C 0022AF1C  7C 08 03 A6 */	mtlr r0
/* 8022E120 0022AF20  38 21 00 10 */	addi r1, r1, 0x10
/* 8022E124 0022AF24  4E 80 00 20 */	blr
.endfn kar_plclearchecker_get_flag_854_bit5

# .text:0x2B4 | 0x8022E128 | size: 0x58
.fn kar_plclearchecker_get_flag_854_bit6, global
/* 8022E128 0022AF28  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022E12C 0022AF2C  7C 08 02 A6 */	mflr r0
/* 8022E130 0022AF30  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022E134 0022AF34  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022E138 0022AF38  7C 7F 1B 78 */	mr r31, r3
/* 8022E13C 0022AF3C  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022E140 0022AF40  41 80 00 1C */	blt .L_8022E15C
/* 8022E144 0022AF44  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E148 0022AF48  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E14C 0022AF4C  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E150 0022AF50  38 80 00 C7 */	li r4, 0xc7
/* 8022E154 0022AF54  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E158 0022AF58  48 1F A3 61 */	bl __assert
.L_8022E15C:
/* 8022E15C 0022AF5C  7F E3 FB 78 */	mr r3, r31
/* 8022E160 0022AF60  4B FF F0 E9 */	bl kar_plclearchecker_get_player_state
/* 8022E164 0022AF64  88 03 08 54 */	lbz r0, 0x854(r3)
/* 8022E168 0022AF68  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022E16C 0022AF6C  54 03 D7 FE */	extrwi r3, r0, 1, 25
/* 8022E170 0022AF70  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022E174 0022AF74  7C 08 03 A6 */	mtlr r0
/* 8022E178 0022AF78  38 21 00 10 */	addi r1, r1, 0x10
/* 8022E17C 0022AF7C  4E 80 00 20 */	blr
.endfn kar_plclearchecker_get_flag_854_bit6

# .text:0x30C | 0x8022E180 | size: 0x58
.fn kar_plclearchecker_get_flag_854_bit4, global
/* 8022E180 0022AF80  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022E184 0022AF84  7C 08 02 A6 */	mflr r0
/* 8022E188 0022AF88  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022E18C 0022AF8C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022E190 0022AF90  7C 7F 1B 78 */	mr r31, r3
/* 8022E194 0022AF94  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022E198 0022AF98  41 80 00 1C */	blt .L_8022E1B4
/* 8022E19C 0022AF9C  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E1A0 0022AFA0  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E1A4 0022AFA4  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E1A8 0022AFA8  38 80 00 D0 */	li r4, 0xd0
/* 8022E1AC 0022AFAC  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E1B0 0022AFB0  48 1F A3 09 */	bl __assert
.L_8022E1B4:
/* 8022E1B4 0022AFB4  7F E3 FB 78 */	mr r3, r31
/* 8022E1B8 0022AFB8  4B FF F0 91 */	bl kar_plclearchecker_get_player_state
/* 8022E1BC 0022AFBC  88 03 08 54 */	lbz r0, 0x854(r3)
/* 8022E1C0 0022AFC0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022E1C4 0022AFC4  54 03 E7 FE */	extrwi r3, r0, 1, 27
/* 8022E1C8 0022AFC8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022E1CC 0022AFCC  7C 08 03 A6 */	mtlr r0
/* 8022E1D0 0022AFD0  38 21 00 10 */	addi r1, r1, 0x10
/* 8022E1D4 0022AFD4  4E 80 00 20 */	blr
.endfn kar_plclearchecker_get_flag_854_bit4

# .text:0x364 | 0x8022E1D8 | size: 0x58
.fn kar_plclearchecker_get_flag_854_bit3, global
/* 8022E1D8 0022AFD8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022E1DC 0022AFDC  7C 08 02 A6 */	mflr r0
/* 8022E1E0 0022AFE0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022E1E4 0022AFE4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022E1E8 0022AFE8  7C 7F 1B 78 */	mr r31, r3
/* 8022E1EC 0022AFEC  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022E1F0 0022AFF0  41 80 00 1C */	blt .L_8022E20C
/* 8022E1F4 0022AFF4  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E1F8 0022AFF8  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E1FC 0022AFFC  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E200 0022B000  38 80 00 D9 */	li r4, 0xd9
/* 8022E204 0022B004  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E208 0022B008  48 1F A2 B1 */	bl __assert
.L_8022E20C:
/* 8022E20C 0022B00C  7F E3 FB 78 */	mr r3, r31
/* 8022E210 0022B010  4B FF F0 39 */	bl kar_plclearchecker_get_player_state
/* 8022E214 0022B014  88 03 08 54 */	lbz r0, 0x854(r3)
/* 8022E218 0022B018  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022E21C 0022B01C  54 03 EF FE */	extrwi r3, r0, 1, 28
/* 8022E220 0022B020  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022E224 0022B024  7C 08 03 A6 */	mtlr r0
/* 8022E228 0022B028  38 21 00 10 */	addi r1, r1, 0x10
/* 8022E22C 0022B02C  4E 80 00 20 */	blr
.endfn kar_plclearchecker_get_flag_854_bit3

# .text:0x3BC | 0x8022E230 | size: 0x58
.fn kar_plclearchecker_get_flag_854_bit2, global
/* 8022E230 0022B030  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022E234 0022B034  7C 08 02 A6 */	mflr r0
/* 8022E238 0022B038  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022E23C 0022B03C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022E240 0022B040  7C 7F 1B 78 */	mr r31, r3
/* 8022E244 0022B044  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022E248 0022B048  41 80 00 1C */	blt .L_8022E264
/* 8022E24C 0022B04C  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E250 0022B050  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E254 0022B054  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E258 0022B058  38 80 00 E2 */	li r4, 0xe2
/* 8022E25C 0022B05C  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E260 0022B060  48 1F A2 59 */	bl __assert
.L_8022E264:
/* 8022E264 0022B064  7F E3 FB 78 */	mr r3, r31
/* 8022E268 0022B068  4B FF EF E1 */	bl kar_plclearchecker_get_player_state
/* 8022E26C 0022B06C  88 03 08 54 */	lbz r0, 0x854(r3)
/* 8022E270 0022B070  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022E274 0022B074  54 03 F7 FE */	extrwi r3, r0, 1, 29
/* 8022E278 0022B078  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022E27C 0022B07C  7C 08 03 A6 */	mtlr r0
/* 8022E280 0022B080  38 21 00 10 */	addi r1, r1, 0x10
/* 8022E284 0022B084  4E 80 00 20 */	blr
.endfn kar_plclearchecker_get_flag_854_bit2

# .text:0x414 | 0x8022E288 | size: 0x58
.fn kar_plclearchecker_get_flag_854_bit1, global
/* 8022E288 0022B088  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022E28C 0022B08C  7C 08 02 A6 */	mflr r0
/* 8022E290 0022B090  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022E294 0022B094  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022E298 0022B098  7C 7F 1B 78 */	mr r31, r3
/* 8022E29C 0022B09C  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022E2A0 0022B0A0  41 80 00 1C */	blt .L_8022E2BC
/* 8022E2A4 0022B0A4  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E2A8 0022B0A8  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E2AC 0022B0AC  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E2B0 0022B0B0  38 80 00 EB */	li r4, 0xeb
/* 8022E2B4 0022B0B4  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E2B8 0022B0B8  48 1F A2 01 */	bl __assert
.L_8022E2BC:
/* 8022E2BC 0022B0BC  7F E3 FB 78 */	mr r3, r31
/* 8022E2C0 0022B0C0  4B FF EF 89 */	bl kar_plclearchecker_get_player_state
/* 8022E2C4 0022B0C4  88 03 08 54 */	lbz r0, 0x854(r3)
/* 8022E2C8 0022B0C8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022E2CC 0022B0CC  54 03 FF FE */	extrwi r3, r0, 1, 30
/* 8022E2D0 0022B0D0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022E2D4 0022B0D4  7C 08 03 A6 */	mtlr r0
/* 8022E2D8 0022B0D8  38 21 00 10 */	addi r1, r1, 0x10
/* 8022E2DC 0022B0DC  4E 80 00 20 */	blr
.endfn kar_plclearchecker_get_flag_854_bit1

# .text:0x46C | 0x8022E2E0 | size: 0x58
.fn kar_plclearchecker_get_flag_854_bit0, global
/* 8022E2E0 0022B0E0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022E2E4 0022B0E4  7C 08 02 A6 */	mflr r0
/* 8022E2E8 0022B0E8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022E2EC 0022B0EC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022E2F0 0022B0F0  7C 7F 1B 78 */	mr r31, r3
/* 8022E2F4 0022B0F4  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022E2F8 0022B0F8  41 80 00 1C */	blt .L_8022E314
/* 8022E2FC 0022B0FC  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E300 0022B100  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E304 0022B104  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E308 0022B108  38 80 00 F4 */	li r4, 0xf4
/* 8022E30C 0022B10C  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E310 0022B110  48 1F A1 A9 */	bl __assert
.L_8022E314:
/* 8022E314 0022B114  7F E3 FB 78 */	mr r3, r31
/* 8022E318 0022B118  4B FF EF 31 */	bl kar_plclearchecker_get_player_state
/* 8022E31C 0022B11C  88 03 08 54 */	lbz r0, 0x854(r3)
/* 8022E320 0022B120  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022E324 0022B124  54 03 07 FE */	clrlwi r3, r0, 31
/* 8022E328 0022B128  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022E32C 0022B12C  7C 08 03 A6 */	mtlr r0
/* 8022E330 0022B130  38 21 00 10 */	addi r1, r1, 0x10
/* 8022E334 0022B134  4E 80 00 20 */	blr
.endfn kar_plclearchecker_get_flag_854_bit0

# .text:0x4C4 | 0x8022E338 | size: 0x58
.fn kar_plclearchecker_get_flag_855_bit7, global
/* 8022E338 0022B138  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022E33C 0022B13C  7C 08 02 A6 */	mflr r0
/* 8022E340 0022B140  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022E344 0022B144  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022E348 0022B148  7C 7F 1B 78 */	mr r31, r3
/* 8022E34C 0022B14C  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022E350 0022B150  41 80 00 1C */	blt .L_8022E36C
/* 8022E354 0022B154  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E358 0022B158  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E35C 0022B15C  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E360 0022B160  38 80 00 FD */	li r4, 0xfd
/* 8022E364 0022B164  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E368 0022B168  48 1F A1 51 */	bl __assert
.L_8022E36C:
/* 8022E36C 0022B16C  7F E3 FB 78 */	mr r3, r31
/* 8022E370 0022B170  4B FF EE D9 */	bl kar_plclearchecker_get_player_state
/* 8022E374 0022B174  88 03 08 55 */	lbz r0, 0x855(r3)
/* 8022E378 0022B178  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022E37C 0022B17C  54 03 CF FE */	extrwi r3, r0, 1, 24
/* 8022E380 0022B180  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022E384 0022B184  7C 08 03 A6 */	mtlr r0
/* 8022E388 0022B188  38 21 00 10 */	addi r1, r1, 0x10
/* 8022E38C 0022B18C  4E 80 00 20 */	blr
.endfn kar_plclearchecker_get_flag_855_bit7

# .text:0x51C | 0x8022E390 | size: 0x54
.fn kar_plclearchecker_get_state_u32_7d4, global
/* 8022E390 0022B190  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022E394 0022B194  7C 08 02 A6 */	mflr r0
/* 8022E398 0022B198  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022E39C 0022B19C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022E3A0 0022B1A0  7C 7F 1B 78 */	mr r31, r3
/* 8022E3A4 0022B1A4  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022E3A8 0022B1A8  41 80 00 1C */	blt .L_8022E3C4
/* 8022E3AC 0022B1AC  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E3B0 0022B1B0  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E3B4 0022B1B4  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E3B8 0022B1B8  38 80 01 06 */	li r4, 0x106
/* 8022E3BC 0022B1BC  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E3C0 0022B1C0  48 1F A0 F9 */	bl __assert
.L_8022E3C4:
/* 8022E3C4 0022B1C4  7F E3 FB 78 */	mr r3, r31
/* 8022E3C8 0022B1C8  4B FF EE 81 */	bl kar_plclearchecker_get_player_state
/* 8022E3CC 0022B1CC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022E3D0 0022B1D0  80 63 07 D4 */	lwz r3, 0x7d4(r3)
/* 8022E3D4 0022B1D4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022E3D8 0022B1D8  7C 08 03 A6 */	mtlr r0
/* 8022E3DC 0022B1DC  38 21 00 10 */	addi r1, r1, 0x10
/* 8022E3E0 0022B1E0  4E 80 00 20 */	blr
.endfn kar_plclearchecker_get_state_u32_7d4

# .text:0x570 | 0x8022E3E4 | size: 0x54
.fn kar_plclearchecker_get_state_u32_7d8, global
/* 8022E3E4 0022B1E4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022E3E8 0022B1E8  7C 08 02 A6 */	mflr r0
/* 8022E3EC 0022B1EC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022E3F0 0022B1F0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022E3F4 0022B1F4  7C 7F 1B 78 */	mr r31, r3
/* 8022E3F8 0022B1F8  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022E3FC 0022B1FC  41 80 00 1C */	blt .L_8022E418
/* 8022E400 0022B200  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E404 0022B204  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E408 0022B208  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E40C 0022B20C  38 80 01 18 */	li r4, 0x118
/* 8022E410 0022B210  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E414 0022B214  48 1F A0 A5 */	bl __assert
.L_8022E418:
/* 8022E418 0022B218  7F E3 FB 78 */	mr r3, r31
/* 8022E41C 0022B21C  4B FF EE 2D */	bl kar_plclearchecker_get_player_state
/* 8022E420 0022B220  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022E424 0022B224  80 63 07 D8 */	lwz r3, 0x7d8(r3)
/* 8022E428 0022B228  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022E42C 0022B22C  7C 08 03 A6 */	mtlr r0
/* 8022E430 0022B230  38 21 00 10 */	addi r1, r1, 0x10
/* 8022E434 0022B234  4E 80 00 20 */	blr
.endfn kar_plclearchecker_get_state_u32_7d8

# .text:0x5C4 | 0x8022E438 | size: 0x54
.fn kar_plclearchecker_get_state_u32_7fc, global
/* 8022E438 0022B238  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022E43C 0022B23C  7C 08 02 A6 */	mflr r0
/* 8022E440 0022B240  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022E444 0022B244  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022E448 0022B248  7C 7F 1B 78 */	mr r31, r3
/* 8022E44C 0022B24C  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022E450 0022B250  41 80 00 1C */	blt .L_8022E46C
/* 8022E454 0022B254  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E458 0022B258  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E45C 0022B25C  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E460 0022B260  38 80 01 21 */	li r4, 0x121
/* 8022E464 0022B264  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E468 0022B268  48 1F A0 51 */	bl __assert
.L_8022E46C:
/* 8022E46C 0022B26C  7F E3 FB 78 */	mr r3, r31
/* 8022E470 0022B270  4B FF ED D9 */	bl kar_plclearchecker_get_player_state
/* 8022E474 0022B274  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022E478 0022B278  80 63 07 FC */	lwz r3, 0x7fc(r3)
/* 8022E47C 0022B27C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022E480 0022B280  7C 08 03 A6 */	mtlr r0
/* 8022E484 0022B284  38 21 00 10 */	addi r1, r1, 0x10
/* 8022E488 0022B288  4E 80 00 20 */	blr
.endfn kar_plclearchecker_get_state_u32_7fc

# .text:0x618 | 0x8022E48C | size: 0x54
.fn kar_plclearchecker_get_state_u32_82c, global
/* 8022E48C 0022B28C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022E490 0022B290  7C 08 02 A6 */	mflr r0
/* 8022E494 0022B294  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022E498 0022B298  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022E49C 0022B29C  7C 7F 1B 78 */	mr r31, r3
/* 8022E4A0 0022B2A0  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022E4A4 0022B2A4  41 80 00 1C */	blt .L_8022E4C0
/* 8022E4A8 0022B2A8  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E4AC 0022B2AC  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E4B0 0022B2B0  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E4B4 0022B2B4  38 80 01 2A */	li r4, 0x12a
/* 8022E4B8 0022B2B8  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E4BC 0022B2BC  48 1F 9F FD */	bl __assert
.L_8022E4C0:
/* 8022E4C0 0022B2C0  7F E3 FB 78 */	mr r3, r31
/* 8022E4C4 0022B2C4  4B FF ED 85 */	bl kar_plclearchecker_get_player_state
/* 8022E4C8 0022B2C8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022E4CC 0022B2CC  80 63 08 2C */	lwz r3, 0x82c(r3)
/* 8022E4D0 0022B2D0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022E4D4 0022B2D4  7C 08 03 A6 */	mtlr r0
/* 8022E4D8 0022B2D8  38 21 00 10 */	addi r1, r1, 0x10
/* 8022E4DC 0022B2DC  4E 80 00 20 */	blr
.endfn kar_plclearchecker_get_state_u32_82c

# .text:0x66C | 0x8022E4E0 | size: 0x1D4
.fn kar_plclearchecker_update_primary_flags, global
/* 8022E4E0 0022B2E0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8022E4E4 0022B2E4  7C 08 02 A6 */	mflr r0
/* 8022E4E8 0022B2E8  90 01 00 24 */	stw r0, 0x24(r1)
/* 8022E4EC 0022B2EC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8022E4F0 0022B2F0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8022E4F4 0022B2F4  7C 7E 1B 78 */	mr r30, r3
/* 8022E4F8 0022B2F8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8022E4FC 0022B2FC  4B FF ED 4D */	bl kar_plclearchecker_get_player_state
/* 8022E500 0022B300  2C 1E 00 05 */	cmpwi r30, 0x5
/* 8022E504 0022B304  7C 7F 1B 78 */	mr r31, r3
/* 8022E508 0022B308  41 80 00 1C */	blt .L_8022E524
/* 8022E50C 0022B30C  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E510 0022B310  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E514 0022B314  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E518 0022B318  38 80 01 34 */	li r4, 0x134
/* 8022E51C 0022B31C  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E520 0022B320  48 1F 9F 99 */	bl __assert
.L_8022E524:
/* 8022E524 0022B324  7F C3 F3 78 */	mr r3, r30
/* 8022E528 0022B328  4B FF ED 09 */	bl kar_plclearchecker_get_player_object
/* 8022E52C 0022B32C  7C 7D 1B 78 */	mr r29, r3
/* 8022E530 0022B330  4B F9 90 05 */	bl fn_801C7534
/* 8022E534 0022B334  2C 03 00 00 */	cmpwi r3, 0x0
/* 8022E538 0022B338  41 82 00 10 */	beq .L_8022E548
/* 8022E53C 0022B33C  7F A3 EB 78 */	mr r3, r29
/* 8022E540 0022B340  4B F9 95 C1 */	bl fn_801C7B00
/* 8022E544 0022B344  48 00 00 08 */	b .L_8022E54C
.L_8022E548:
/* 8022E548 0022B348  38 60 00 00 */	li r3, 0x0
.L_8022E54C:
/* 8022E54C 0022B34C  2C 03 00 00 */	cmpwi r3, 0x0
/* 8022E550 0022B350  41 82 00 14 */	beq .L_8022E564
/* 8022E554 0022B354  88 1F 08 54 */	lbz r0, 0x854(r31)
/* 8022E558 0022B358  38 60 00 01 */	li r3, 0x1
/* 8022E55C 0022B35C  50 60 3E 30 */	rlwimi r0, r3, 7, 24, 24
/* 8022E560 0022B360  98 1F 08 54 */	stb r0, 0x854(r31)
.L_8022E564:
/* 8022E564 0022B364  2C 1E 00 05 */	cmpwi r30, 0x5
/* 8022E568 0022B368  41 80 00 1C */	blt .L_8022E584
/* 8022E56C 0022B36C  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E570 0022B370  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E574 0022B374  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E578 0022B378  38 80 01 43 */	li r4, 0x143
/* 8022E57C 0022B37C  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E580 0022B380  48 1F 9F 39 */	bl __assert
.L_8022E584:
/* 8022E584 0022B384  7F C3 F3 78 */	mr r3, r30
/* 8022E588 0022B388  4B FF EC A9 */	bl kar_plclearchecker_get_player_object
/* 8022E58C 0022B38C  7C 7D 1B 78 */	mr r29, r3
/* 8022E590 0022B390  4B F9 8F A5 */	bl fn_801C7534
/* 8022E594 0022B394  2C 03 00 00 */	cmpwi r3, 0x0
/* 8022E598 0022B398  41 82 00 10 */	beq .L_8022E5A8
/* 8022E59C 0022B39C  7F A3 EB 78 */	mr r3, r29
/* 8022E5A0 0022B3A0  4B F9 96 D1 */	bl fn_801C7C70
/* 8022E5A4 0022B3A4  48 00 00 08 */	b .L_8022E5AC
.L_8022E5A8:
/* 8022E5A8 0022B3A8  38 60 00 00 */	li r3, 0x0
.L_8022E5AC:
/* 8022E5AC 0022B3AC  2C 03 00 01 */	cmpwi r3, 0x1
/* 8022E5B0 0022B3B0  40 82 00 14 */	bne .L_8022E5C4
/* 8022E5B4 0022B3B4  88 1F 08 54 */	lbz r0, 0x854(r31)
/* 8022E5B8 0022B3B8  38 60 00 01 */	li r3, 0x1
/* 8022E5BC 0022B3BC  50 60 36 72 */	rlwimi r0, r3, 6, 25, 25
/* 8022E5C0 0022B3C0  98 1F 08 54 */	stb r0, 0x854(r31)
.L_8022E5C4:
/* 8022E5C4 0022B3C4  7F C3 F3 78 */	mr r3, r30
/* 8022E5C8 0022B3C8  48 00 35 C1 */	bl kar_pltrick__80231b88
/* 8022E5CC 0022B3CC  2C 1E 00 05 */	cmpwi r30, 0x5
/* 8022E5D0 0022B3D0  7C 7D 1B 78 */	mr r29, r3
/* 8022E5D4 0022B3D4  41 80 00 1C */	blt .L_8022E5F0
/* 8022E5D8 0022B3D8  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E5DC 0022B3DC  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E5E0 0022B3E0  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E5E4 0022B3E4  38 80 01 53 */	li r4, 0x153
/* 8022E5E8 0022B3E8  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E5EC 0022B3EC  48 1F 9E CD */	bl __assert
.L_8022E5F0:
/* 8022E5F0 0022B3F0  88 1D 00 02 */	lbz r0, 0x2(r29)
/* 8022E5F4 0022B3F4  54 00 07 3E */	clrlwi r0, r0, 28
/* 8022E5F8 0022B3F8  28 00 00 03 */	cmplwi r0, 0x3
/* 8022E5FC 0022B3FC  40 82 00 14 */	bne .L_8022E610
/* 8022E600 0022B400  88 1F 08 54 */	lbz r0, 0x854(r31)
/* 8022E604 0022B404  38 60 00 01 */	li r3, 0x1
/* 8022E608 0022B408  50 60 2E B4 */	rlwimi r0, r3, 5, 26, 26
/* 8022E60C 0022B40C  98 1F 08 54 */	stb r0, 0x854(r31)
.L_8022E610:
/* 8022E610 0022B410  7F C3 F3 78 */	mr r3, r30
/* 8022E614 0022B414  4B FF E5 79 */	bl kar_plclearchecker_call_clobject_func_191f74
/* 8022E618 0022B418  2C 03 00 02 */	cmpwi r3, 0x2
/* 8022E61C 0022B41C  40 82 00 14 */	bne .L_8022E630
/* 8022E620 0022B420  88 1F 08 54 */	lbz r0, 0x854(r31)
/* 8022E624 0022B424  38 80 00 01 */	li r4, 0x1
/* 8022E628 0022B428  50 80 17 7A */	rlwimi r0, r4, 2, 29, 29
/* 8022E62C 0022B42C  98 1F 08 54 */	stb r0, 0x854(r31)
.L_8022E630:
/* 8022E630 0022B430  2C 03 00 00 */	cmpwi r3, 0x0
/* 8022E634 0022B434  40 82 00 14 */	bne .L_8022E648
/* 8022E638 0022B438  88 1F 08 54 */	lbz r0, 0x854(r31)
/* 8022E63C 0022B43C  38 80 00 01 */	li r4, 0x1
/* 8022E640 0022B440  50 80 0F BC */	rlwimi r0, r4, 1, 30, 30
/* 8022E644 0022B444  98 1F 08 54 */	stb r0, 0x854(r31)
.L_8022E648:
/* 8022E648 0022B448  2C 03 00 06 */	cmpwi r3, 0x6
/* 8022E64C 0022B44C  40 82 00 14 */	bne .L_8022E660
/* 8022E650 0022B450  88 1F 08 54 */	lbz r0, 0x854(r31)
/* 8022E654 0022B454  38 80 00 01 */	li r4, 0x1
/* 8022E658 0022B458  50 80 07 FE */	rlwimi r0, r4, 0, 31, 31
/* 8022E65C 0022B45C  98 1F 08 54 */	stb r0, 0x854(r31)
.L_8022E660:
/* 8022E660 0022B460  2C 03 00 0A */	cmpwi r3, 0xa
/* 8022E664 0022B464  40 82 00 14 */	bne .L_8022E678
/* 8022E668 0022B468  88 1F 08 55 */	lbz r0, 0x855(r31)
/* 8022E66C 0022B46C  38 60 00 01 */	li r3, 0x1
/* 8022E670 0022B470  50 60 3E 30 */	rlwimi r0, r3, 7, 24, 24
/* 8022E674 0022B474  98 1F 08 55 */	stb r0, 0x855(r31)
.L_8022E678:
/* 8022E678 0022B478  80 9F 08 24 */	lwz r4, 0x824(r31)
/* 8022E67C 0022B47C  38 60 00 01 */	li r3, 0x1
/* 8022E680 0022B480  80 1F 08 28 */	lwz r0, 0x828(r31)
/* 8022E684 0022B484  7C 04 00 50 */	subf r0, r4, r0
/* 8022E688 0022B488  90 1F 08 2C */	stw r0, 0x82c(r31)
/* 8022E68C 0022B48C  88 1F 08 55 */	lbz r0, 0x855(r31)
/* 8022E690 0022B490  50 60 36 72 */	rlwimi r0, r3, 6, 25, 25
/* 8022E694 0022B494  98 1F 08 55 */	stb r0, 0x855(r31)
/* 8022E698 0022B498  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8022E69C 0022B49C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8022E6A0 0022B4A0  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8022E6A4 0022B4A4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8022E6A8 0022B4A8  7C 08 03 A6 */	mtlr r0
/* 8022E6AC 0022B4AC  38 21 00 20 */	addi r1, r1, 0x20
/* 8022E6B0 0022B4B0  4E 80 00 20 */	blr
.endfn kar_plclearchecker_update_primary_flags

# .text:0x840 | 0x8022E6B4 | size: 0xD4
.fn kar_plclearchecker_update_secondary_flags, global
/* 8022E6B4 0022B4B4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8022E6B8 0022B4B8  7C 08 02 A6 */	mflr r0
/* 8022E6BC 0022B4BC  90 01 00 24 */	stw r0, 0x24(r1)
/* 8022E6C0 0022B4C0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8022E6C4 0022B4C4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8022E6C8 0022B4C8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8022E6CC 0022B4CC  7C 7D 1B 78 */	mr r29, r3
/* 8022E6D0 0022B4D0  4B FF EB 79 */	bl kar_plclearchecker_get_player_state
/* 8022E6D4 0022B4D4  7C 7F 1B 78 */	mr r31, r3
/* 8022E6D8 0022B4D8  7F A3 EB 78 */	mr r3, r29
/* 8022E6DC 0022B4DC  4B FF EB 55 */	bl kar_plclearchecker_get_player_object
/* 8022E6E0 0022B4E0  2C 1D 00 05 */	cmpwi r29, 0x5
/* 8022E6E4 0022B4E4  7C 7E 1B 78 */	mr r30, r3
/* 8022E6E8 0022B4E8  41 80 00 1C */	blt .L_8022E704
/* 8022E6EC 0022B4EC  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E6F0 0022B4F0  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E6F4 0022B4F4  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E6F8 0022B4F8  38 80 01 61 */	li r4, 0x161
/* 8022E6FC 0022B4FC  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E700 0022B500  48 1F 9D B9 */	bl __assert
.L_8022E704:
/* 8022E704 0022B504  7F C3 F3 78 */	mr r3, r30
/* 8022E708 0022B508  4B F9 9E 01 */	bl fn_801C8508
/* 8022E70C 0022B50C  2C 03 00 00 */	cmpwi r3, 0x0
/* 8022E710 0022B510  41 82 00 20 */	beq .L_8022E730
/* 8022E714 0022B514  7F C3 F3 78 */	mr r3, r30
/* 8022E718 0022B518  4B FB 73 99 */	bl fn_801E5AB0
/* 8022E71C 0022B51C  88 03 00 02 */	lbz r0, 0x2(r3)
/* 8022E720 0022B520  54 00 DF FF */	extrwi. r0, r0, 1, 26
/* 8022E724 0022B524  41 82 00 0C */	beq .L_8022E730
/* 8022E728 0022B528  38 00 00 01 */	li r0, 0x1
/* 8022E72C 0022B52C  48 00 00 08 */	b .L_8022E734
.L_8022E730:
/* 8022E730 0022B530  38 00 00 00 */	li r0, 0x0
.L_8022E734:
/* 8022E734 0022B534  2C 00 00 00 */	cmpwi r0, 0x0
/* 8022E738 0022B538  41 82 00 14 */	beq .L_8022E74C
/* 8022E73C 0022B53C  88 1F 08 54 */	lbz r0, 0x854(r31)
/* 8022E740 0022B540  38 60 00 01 */	li r3, 0x1
/* 8022E744 0022B544  50 60 26 F6 */	rlwimi r0, r3, 4, 27, 27
/* 8022E748 0022B548  98 1F 08 54 */	stb r0, 0x854(r31)
.L_8022E74C:
/* 8022E74C 0022B54C  7F A3 EB 78 */	mr r3, r29
/* 8022E750 0022B550  4B FF ED 19 */	bl kar_plclearchecker_call_clobject_func_1926f4
/* 8022E754 0022B554  2C 03 00 00 */	cmpwi r3, 0x0
/* 8022E758 0022B558  41 82 00 14 */	beq .L_8022E76C
/* 8022E75C 0022B55C  88 1F 08 54 */	lbz r0, 0x854(r31)
/* 8022E760 0022B560  38 60 00 01 */	li r3, 0x1
/* 8022E764 0022B564  50 60 1F 38 */	rlwimi r0, r3, 3, 28, 28
/* 8022E768 0022B568  98 1F 08 54 */	stb r0, 0x854(r31)
.L_8022E76C:
/* 8022E76C 0022B56C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8022E770 0022B570  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8022E774 0022B574  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8022E778 0022B578  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8022E77C 0022B57C  7C 08 03 A6 */	mtlr r0
/* 8022E780 0022B580  38 21 00 20 */	addi r1, r1, 0x20
/* 8022E784 0022B584  4E 80 00 20 */	blr
.endfn kar_plclearchecker_update_secondary_flags

# .text:0x914 | 0x8022E788 | size: 0x58
.fn kar_plclearchecker_get_flag_84c_bit5, global
/* 8022E788 0022B588  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022E78C 0022B58C  7C 08 02 A6 */	mflr r0
/* 8022E790 0022B590  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022E794 0022B594  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022E798 0022B598  7C 7F 1B 78 */	mr r31, r3
/* 8022E79C 0022B59C  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022E7A0 0022B5A0  41 80 00 1C */	blt .L_8022E7BC
/* 8022E7A4 0022B5A4  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E7A8 0022B5A8  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E7AC 0022B5AC  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E7B0 0022B5B0  38 80 01 B4 */	li r4, 0x1b4
/* 8022E7B4 0022B5B4  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E7B8 0022B5B8  48 1F 9D 01 */	bl __assert
.L_8022E7BC:
/* 8022E7BC 0022B5BC  7F E3 FB 78 */	mr r3, r31
/* 8022E7C0 0022B5C0  4B FF EA 89 */	bl kar_plclearchecker_get_player_state
/* 8022E7C4 0022B5C4  88 03 08 4C */	lbz r0, 0x84c(r3)
/* 8022E7C8 0022B5C8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022E7CC 0022B5CC  54 03 DF FE */	extrwi r3, r0, 1, 26
/* 8022E7D0 0022B5D0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022E7D4 0022B5D4  7C 08 03 A6 */	mtlr r0
/* 8022E7D8 0022B5D8  38 21 00 10 */	addi r1, r1, 0x10
/* 8022E7DC 0022B5DC  4E 80 00 20 */	blr
.endfn kar_plclearchecker_get_flag_84c_bit5

# .text:0x96C | 0x8022E7E0 | size: 0x58
.fn kar_plclearchecker_get_flag_84d_bit6, global
/* 8022E7E0 0022B5E0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022E7E4 0022B5E4  7C 08 02 A6 */	mflr r0
/* 8022E7E8 0022B5E8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022E7EC 0022B5EC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022E7F0 0022B5F0  7C 7F 1B 78 */	mr r31, r3
/* 8022E7F4 0022B5F4  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022E7F8 0022B5F8  41 80 00 1C */	blt .L_8022E814
/* 8022E7FC 0022B5FC  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E800 0022B600  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E804 0022B604  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E808 0022B608  38 80 01 BD */	li r4, 0x1bd
/* 8022E80C 0022B60C  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E810 0022B610  48 1F 9C A9 */	bl __assert
.L_8022E814:
/* 8022E814 0022B614  7F E3 FB 78 */	mr r3, r31
/* 8022E818 0022B618  4B FF EA 31 */	bl kar_plclearchecker_get_player_state
/* 8022E81C 0022B61C  88 03 08 4D */	lbz r0, 0x84d(r3)
/* 8022E820 0022B620  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022E824 0022B624  54 03 D7 FE */	extrwi r3, r0, 1, 25
/* 8022E828 0022B628  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022E82C 0022B62C  7C 08 03 A6 */	mtlr r0
/* 8022E830 0022B630  38 21 00 10 */	addi r1, r1, 0x10
/* 8022E834 0022B634  4E 80 00 20 */	blr
.endfn kar_plclearchecker_get_flag_84d_bit6

# .text:0x9C4 | 0x8022E838 | size: 0x54
.fn kar_plclearchecker_get_state_u32_81c, global
/* 8022E838 0022B638  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022E83C 0022B63C  7C 08 02 A6 */	mflr r0
/* 8022E840 0022B640  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022E844 0022B644  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022E848 0022B648  7C 7F 1B 78 */	mr r31, r3
/* 8022E84C 0022B64C  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022E850 0022B650  41 80 00 1C */	blt .L_8022E86C
/* 8022E854 0022B654  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022E858 0022B658  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022E85C 0022B65C  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022E860 0022B660  38 80 01 C7 */	li r4, 0x1c7
/* 8022E864 0022B664  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022E868 0022B668  48 1F 9C 51 */	bl __assert
.L_8022E86C:
/* 8022E86C 0022B66C  7F E3 FB 78 */	mr r3, r31
/* 8022E870 0022B670  4B FF E9 D9 */	bl kar_plclearchecker_get_player_state
/* 8022E874 0022B674  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022E878 0022B678  80 63 08 1C */	lwz r3, 0x81c(r3)
/* 8022E87C 0022B67C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022E880 0022B680  7C 08 03 A6 */	mtlr r0
/* 8022E884 0022B684  38 21 00 10 */	addi r1, r1, 0x10
/* 8022E888 0022B688  4E 80 00 20 */	blr
.endfn kar_plclearchecker_get_state_u32_81c

# .text:0xA18 | 0x8022E88C | size: 0x184
.fn kar_plclearcheckerlib__near_8022e88c, global
/* 8022E88C 0022B68C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8022E890 0022B690  7C 08 02 A6 */	mflr r0
/* 8022E894 0022B694  90 01 00 24 */	stw r0, 0x24(r1)
/* 8022E898 0022B698  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8022E89C 0022B69C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8022E8A0 0022B6A0  7C 7E 1B 78 */	mr r30, r3
/* 8022E8A4 0022B6A4  2C 1E 00 05 */	cmpwi r30, 0x5
/* 8022E8A8 0022B6A8  41 82 01 50 */	beq .L_8022E9F8
/* 8022E8AC 0022B6AC  4B FF E9 9D */	bl kar_plclearchecker_get_player_state
/* 8022E8B0 0022B6B0  88 03 08 55 */	lbz r0, 0x855(r3)
/* 8022E8B4 0022B6B4  7C 7F 1B 78 */	mr r31, r3
/* 8022E8B8 0022B6B8  54 00 D7 FF */	extrwi. r0, r0, 1, 25
/* 8022E8BC 0022B6BC  40 82 01 3C */	bne .L_8022E9F8
/* 8022E8C0 0022B6C0  4B DD AA 19 */	bl fn_800092D8
/* 8022E8C4 0022B6C4  7C 63 07 74 */	extsb r3, r3
/* 8022E8C8 0022B6C8  48 03 34 21 */	bl fn_80261CE8
/* 8022E8CC 0022B6CC  2C 03 00 07 */	cmpwi r3, 0x7
/* 8022E8D0 0022B6D0  41 82 00 30 */	beq .L_8022E900
/* 8022E8D4 0022B6D4  40 80 00 64 */	bge .L_8022E938
/* 8022E8D8 0022B6D8  2C 03 00 00 */	cmpwi r3, 0x0
/* 8022E8DC 0022B6DC  41 82 00 08 */	beq .L_8022E8E4
/* 8022E8E0 0022B6E0  48 00 00 58 */	b .L_8022E938
.L_8022E8E4:
/* 8022E8E4 0022B6E4  88 7F 08 4C */	lbz r3, 0x84c(r31)
/* 8022E8E8 0022B6E8  54 60 E7 FF */	extrwi. r0, r3, 1, 27
/* 8022E8EC 0022B6EC  41 82 00 4C */	beq .L_8022E938
/* 8022E8F0 0022B6F0  38 00 00 01 */	li r0, 0x1
/* 8022E8F4 0022B6F4  50 03 2E B4 */	rlwimi r3, r0, 5, 26, 26
/* 8022E8F8 0022B6F8  98 7F 08 4C */	stb r3, 0x84c(r31)
/* 8022E8FC 0022B6FC  48 00 00 3C */	b .L_8022E938
.L_8022E900:
/* 8022E900 0022B700  88 1F 08 4C */	lbz r0, 0x84c(r31)
/* 8022E904 0022B704  54 00 EF FF */	extrwi. r0, r0, 1, 28
/* 8022E908 0022B708  40 82 00 14 */	bne .L_8022E91C
/* 8022E90C 0022B70C  80 7F 08 18 */	lwz r3, 0x818(r31)
/* 8022E910 0022B710  38 03 00 01 */	addi r0, r3, 0x1
/* 8022E914 0022B714  90 1F 08 18 */	stw r0, 0x818(r31)
/* 8022E918 0022B718  48 00 00 0C */	b .L_8022E924
.L_8022E91C:
/* 8022E91C 0022B71C  38 00 00 00 */	li r0, 0x0
/* 8022E920 0022B720  90 1F 08 18 */	stw r0, 0x818(r31)
.L_8022E924:
/* 8022E924 0022B724  80 1F 08 1C */	lwz r0, 0x81c(r31)
/* 8022E928 0022B728  80 7F 08 18 */	lwz r3, 0x818(r31)
/* 8022E92C 0022B72C  7C 00 18 40 */	cmplw r0, r3
/* 8022E930 0022B730  40 80 00 08 */	bge .L_8022E938
/* 8022E934 0022B734  90 7F 08 1C */	stw r3, 0x81c(r31)
.L_8022E938:
/* 8022E938 0022B738  80 1F 08 24 */	lwz r0, 0x824(r31)
/* 8022E93C 0022B73C  7F C3 F3 78 */	mr r3, r30
/* 8022E940 0022B740  90 1F 08 28 */	stw r0, 0x828(r31)
/* 8022E944 0022B744  4B DD AB F1 */	bl fn_80009534
/* 8022E948 0022B748  7C 60 07 74 */	extsb r0, r3
/* 8022E94C 0022B74C  7F C3 F3 78 */	mr r3, r30
/* 8022E950 0022B750  90 1F 08 24 */	stw r0, 0x824(r31)
/* 8022E954 0022B754  4B DD B5 F1 */	bl fn_80009F44
/* 8022E958 0022B758  3C 80 88 89 */	lis r4, 0x8889
/* 8022E95C 0022B75C  3C 00 43 30 */	lis r0, 0x4330
/* 8022E960 0022B760  38 A4 88 89 */	subi r5, r4, 0x7777
/* 8022E964 0022B764  3C 80 66 66 */	lis r4, 0x6666
/* 8022E968 0022B768  7C A5 18 96 */	mulhw r5, r5, r3
/* 8022E96C 0022B76C  90 01 00 08 */	stw r0, 0x8(r1)
/* 8022E970 0022B770  C8 42 C3 40 */	lfd f2, lbl_805E2A40@sda21(r0)
/* 8022E974 0022B774  38 04 66 67 */	addi r0, r4, 0x6667
/* 8022E978 0022B778  C0 62 C3 38 */	lfs f3, lbl_805E2A38@sda21(r0)
/* 8022E97C 0022B77C  C0 02 C3 3C */	lfs f0, lbl_805E2A3C@sda21(r0)
/* 8022E980 0022B780  7C 85 1A 14 */	add r4, r5, r3
/* 8022E984 0022B784  7C 84 2E 70 */	srawi r4, r4, 5
/* 8022E988 0022B788  54 85 0F FE */	srwi r5, r4, 31
/* 8022E98C 0022B78C  7C 84 2A 14 */	add r4, r4, r5
/* 8022E990 0022B790  1C 84 00 3C */	mulli r4, r4, 0x3c
/* 8022E994 0022B794  7C 64 18 50 */	subf r3, r4, r3
/* 8022E998 0022B798  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 8022E99C 0022B79C  90 61 00 0C */	stw r3, 0xc(r1)
/* 8022E9A0 0022B7A0  C8 21 00 08 */	lfd f1, 0x8(r1)
/* 8022E9A4 0022B7A4  EC 21 10 28 */	fsubs f1, f1, f2
/* 8022E9A8 0022B7A8  EC 23 00 72 */	fmuls f1, f3, f1
/* 8022E9AC 0022B7AC  EC 01 00 24 */	fdivs f0, f1, f0
/* 8022E9B0 0022B7B0  FC 00 00 1E */	fctiwz f0, f0
/* 8022E9B4 0022B7B4  D8 01 00 10 */	stfd f0, 0x10(r1)
/* 8022E9B8 0022B7B8  80 C1 00 14 */	lwz r6, 0x14(r1)
/* 8022E9BC 0022B7BC  7C 00 30 96 */	mulhw r0, r0, r6
/* 8022E9C0 0022B7C0  7C 04 16 70 */	srawi r4, r0, 2
/* 8022E9C4 0022B7C4  7C 00 16 70 */	srawi r0, r0, 2
/* 8022E9C8 0022B7C8  54 03 0F FE */	srwi r3, r0, 31
/* 8022E9CC 0022B7CC  54 85 0F FE */	srwi r5, r4, 31
/* 8022E9D0 0022B7D0  7C 00 1A 14 */	add r0, r0, r3
/* 8022E9D4 0022B7D4  1C 00 00 0A */	mulli r0, r0, 0xa
/* 8022E9D8 0022B7D8  7C 64 2A 14 */	add r3, r4, r5
/* 8022E9DC 0022B7DC  7C 00 30 50 */	subf r0, r0, r6
/* 8022E9E0 0022B7E0  7C 03 00 00 */	cmpw r3, r0
/* 8022E9E4 0022B7E4  40 82 00 14 */	bne .L_8022E9F8
/* 8022E9E8 0022B7E8  88 1F 08 4D */	lbz r0, 0x84d(r31)
/* 8022E9EC 0022B7EC  38 60 00 01 */	li r3, 0x1
/* 8022E9F0 0022B7F0  50 60 36 72 */	rlwimi r0, r3, 6, 25, 25
/* 8022E9F4 0022B7F4  98 1F 08 4D */	stb r0, 0x84d(r31)
.L_8022E9F8:
/* 8022E9F8 0022B7F8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8022E9FC 0022B7FC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8022EA00 0022B800  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8022EA04 0022B804  7C 08 03 A6 */	mtlr r0
/* 8022EA08 0022B808  38 21 00 20 */	addi r1, r1, 0x20
/* 8022EA0C 0022B80C  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_8022e88c

# .text:0xB9C | 0x8022EA10 | size: 0x88
.fn kar_plclearcheckerlib__near_8022ea10, global
/* 8022EA10 0022B810  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022EA14 0022B814  7C 08 02 A6 */	mflr r0
/* 8022EA18 0022B818  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022EA1C 0022B81C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022EA20 0022B820  7C 7F 1B 78 */	mr r31, r3
/* 8022EA24 0022B824  4B DD AD 79 */	bl fn_8000979C
/* 8022EA28 0022B828  7C 60 07 75 */	extsb. r0, r3
/* 8022EA2C 0022B82C  40 82 00 58 */	bne .L_8022EA84
/* 8022EA30 0022B830  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022EA34 0022B834  41 82 00 50 */	beq .L_8022EA84
/* 8022EA38 0022B838  7F E3 FB 78 */	mr r3, r31
/* 8022EA3C 0022B83C  4B FF E8 0D */	bl kar_plclearchecker_get_player_state
/* 8022EA40 0022B840  7C 7F 1B 78 */	mr r31, r3
/* 8022EA44 0022B844  4B DD A8 95 */	bl fn_800092D8
/* 8022EA48 0022B848  7C 63 07 74 */	extsb r3, r3
/* 8022EA4C 0022B84C  48 03 32 9D */	bl fn_80261CE8
/* 8022EA50 0022B850  2C 03 00 00 */	cmpwi r3, 0x0
/* 8022EA54 0022B854  40 82 00 18 */	bne .L_8022EA6C
/* 8022EA58 0022B858  88 1F 08 4C */	lbz r0, 0x84c(r31)
/* 8022EA5C 0022B85C  38 60 00 01 */	li r3, 0x1
/* 8022EA60 0022B860  50 60 26 F6 */	rlwimi r0, r3, 4, 27, 27
/* 8022EA64 0022B864  98 1F 08 4C */	stb r0, 0x84c(r31)
/* 8022EA68 0022B868  48 00 00 1C */	b .L_8022EA84
.L_8022EA6C:
/* 8022EA6C 0022B86C  2C 03 00 07 */	cmpwi r3, 0x7
/* 8022EA70 0022B870  40 82 00 14 */	bne .L_8022EA84
/* 8022EA74 0022B874  88 1F 08 4C */	lbz r0, 0x84c(r31)
/* 8022EA78 0022B878  38 60 00 00 */	li r3, 0x0
/* 8022EA7C 0022B87C  50 60 1F 38 */	rlwimi r0, r3, 3, 28, 28
/* 8022EA80 0022B880  98 1F 08 4C */	stb r0, 0x84c(r31)
.L_8022EA84:
/* 8022EA84 0022B884  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022EA88 0022B888  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022EA8C 0022B88C  7C 08 03 A6 */	mtlr r0
/* 8022EA90 0022B890  38 21 00 10 */	addi r1, r1, 0x10
/* 8022EA94 0022B894  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_8022ea10

# .text:0xC24 | 0x8022EA98 | size: 0x78
.fn kar_plclearcheckerlib__8022ea98, global
/* 8022EA98 0022B898  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022EA9C 0022B89C  7C 08 02 A6 */	mflr r0
/* 8022EAA0 0022B8A0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022EAA4 0022B8A4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022EAA8 0022B8A8  7C 9F 23 78 */	mr r31, r4
/* 8022EAAC 0022B8AC  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8022EAB0 0022B8B0  7C 7E 1B 78 */	mr r30, r3
/* 8022EAB4 0022B8B4  2C 1E 00 05 */	cmpwi r30, 0x5
/* 8022EAB8 0022B8B8  41 80 00 1C */	blt .L_8022EAD4
/* 8022EABC 0022B8BC  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022EAC0 0022B8C0  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022EAC4 0022B8C4  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022EAC8 0022B8C8  38 80 02 3F */	li r4, 0x23f
/* 8022EACC 0022B8CC  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022EAD0 0022B8D0  48 1F 99 E9 */	bl __assert
.L_8022EAD4:
/* 8022EAD4 0022B8D4  2C 1F 00 1B */	cmpwi r31, 0x1b
/* 8022EAD8 0022B8D8  40 80 00 1C */	bge .L_8022EAF4
/* 8022EADC 0022B8DC  7F C3 F3 78 */	mr r3, r30
/* 8022EAE0 0022B8E0  4B FF E7 81 */	bl kar_plclearcheckerlib__8022d260
/* 8022EAE4 0022B8E4  57 E4 10 3A */	slwi r4, r31, 2
/* 8022EAE8 0022B8E8  38 04 00 74 */	addi r0, r4, 0x74
/* 8022EAEC 0022B8EC  7C 63 00 2E */	lwzx r3, r3, r0
/* 8022EAF0 0022B8F0  48 00 00 08 */	b .L_8022EAF8
.L_8022EAF4:
/* 8022EAF4 0022B8F4  38 60 00 00 */	li r3, 0x0
.L_8022EAF8:
/* 8022EAF8 0022B8F8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022EAFC 0022B8FC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022EB00 0022B900  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8022EB04 0022B904  7C 08 03 A6 */	mtlr r0
/* 8022EB08 0022B908  38 21 00 10 */	addi r1, r1, 0x10
/* 8022EB0C 0022B90C  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022ea98

# .text:0xC9C | 0x8022EB10 | size: 0x78
.fn kar_plclearcheckerlib__8022eb10, global
/* 8022EB10 0022B910  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022EB14 0022B914  7C 08 02 A6 */	mflr r0
/* 8022EB18 0022B918  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022EB1C 0022B91C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022EB20 0022B920  7C 9F 23 78 */	mr r31, r4
/* 8022EB24 0022B924  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8022EB28 0022B928  7C 7E 1B 78 */	mr r30, r3
/* 8022EB2C 0022B92C  2C 1E 00 05 */	cmpwi r30, 0x5
/* 8022EB30 0022B930  41 80 00 1C */	blt .L_8022EB4C
/* 8022EB34 0022B934  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022EB38 0022B938  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022EB3C 0022B93C  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022EB40 0022B940  38 80 02 56 */	li r4, 0x256
/* 8022EB44 0022B944  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022EB48 0022B948  48 1F 99 71 */	bl __assert
.L_8022EB4C:
/* 8022EB4C 0022B94C  2C 1F 00 1B */	cmpwi r31, 0x1b
/* 8022EB50 0022B950  40 80 00 1C */	bge .L_8022EB6C
/* 8022EB54 0022B954  7F C3 F3 78 */	mr r3, r30
/* 8022EB58 0022B958  4B FF E7 09 */	bl kar_plclearcheckerlib__8022d260
/* 8022EB5C 0022B95C  57 E4 10 3A */	slwi r4, r31, 2
/* 8022EB60 0022B960  38 04 00 E4 */	addi r0, r4, 0xe4
/* 8022EB64 0022B964  7C 63 00 2E */	lwzx r3, r3, r0
/* 8022EB68 0022B968  48 00 00 08 */	b .L_8022EB70
.L_8022EB6C:
/* 8022EB6C 0022B96C  38 60 00 00 */	li r3, 0x0
.L_8022EB70:
/* 8022EB70 0022B970  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022EB74 0022B974  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022EB78 0022B978  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8022EB7C 0022B97C  7C 08 03 A6 */	mtlr r0
/* 8022EB80 0022B980  38 21 00 10 */	addi r1, r1, 0x10
/* 8022EB84 0022B984  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022eb10

# .text:0xD14 | 0x8022EB88 | size: 0x54
.fn kar_plclearcheckerlib__8022eb88, global
/* 8022EB88 0022B988  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022EB8C 0022B98C  7C 08 02 A6 */	mflr r0
/* 8022EB90 0022B990  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022EB94 0022B994  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022EB98 0022B998  7C 7F 1B 78 */	mr r31, r3
/* 8022EB9C 0022B99C  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022EBA0 0022B9A0  41 80 00 1C */	blt .L_8022EBBC
/* 8022EBA4 0022B9A4  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022EBA8 0022B9A8  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022EBAC 0022B9AC  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022EBB0 0022B9B0  38 80 02 6D */	li r4, 0x26d
/* 8022EBB4 0022B9B4  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022EBB8 0022B9B8  48 1F 99 01 */	bl __assert
.L_8022EBBC:
/* 8022EBBC 0022B9BC  7F E3 FB 78 */	mr r3, r31
/* 8022EBC0 0022B9C0  4B FF E6 A1 */	bl kar_plclearcheckerlib__8022d260
/* 8022EBC4 0022B9C4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022EBC8 0022B9C8  80 63 00 E0 */	lwz r3, 0xe0(r3)
/* 8022EBCC 0022B9CC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022EBD0 0022B9D0  7C 08 03 A6 */	mtlr r0
/* 8022EBD4 0022B9D4  38 21 00 10 */	addi r1, r1, 0x10
/* 8022EBD8 0022B9D8  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022eb88

# .text:0xD68 | 0x8022EBDC | size: 0x58
.fn kar_plclearcheckerlib__8022ebdc, global
/* 8022EBDC 0022B9DC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022EBE0 0022B9E0  7C 08 02 A6 */	mflr r0
/* 8022EBE4 0022B9E4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022EBE8 0022B9E8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022EBEC 0022B9EC  7C 7F 1B 78 */	mr r31, r3
/* 8022EBF0 0022B9F0  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022EBF4 0022B9F4  41 80 00 1C */	blt .L_8022EC10
/* 8022EBF8 0022B9F8  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022EBFC 0022B9FC  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022EC00 0022BA00  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022EC04 0022BA04  38 80 02 AC */	li r4, 0x2ac
/* 8022EC08 0022BA08  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022EC0C 0022BA0C  48 1F 98 AD */	bl __assert
.L_8022EC10:
/* 8022EC10 0022BA10  7F E3 FB 78 */	mr r3, r31
/* 8022EC14 0022BA14  4B FF E6 35 */	bl kar_plclearchecker_get_player_state
/* 8022EC18 0022BA18  88 03 08 4C */	lbz r0, 0x84c(r3)
/* 8022EC1C 0022BA1C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022EC20 0022BA20  54 03 CF FE */	extrwi r3, r0, 1, 24
/* 8022EC24 0022BA24  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022EC28 0022BA28  7C 08 03 A6 */	mtlr r0
/* 8022EC2C 0022BA2C  38 21 00 10 */	addi r1, r1, 0x10
/* 8022EC30 0022BA30  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022ebdc

# .text:0xDC0 | 0x8022EC34 | size: 0x50
.fn kar_plclearcheckerlib__8022ec34, global
/* 8022EC34 0022BA34  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022EC38 0022BA38  7C 08 02 A6 */	mflr r0
/* 8022EC3C 0022BA3C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022EC40 0022BA40  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022EC44 0022BA44  7C 7F 1B 78 */	mr r31, r3
/* 8022EC48 0022BA48  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022EC4C 0022BA4C  41 80 00 1C */	blt .L_8022EC68
/* 8022EC50 0022BA50  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022EC54 0022BA54  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022EC58 0022BA58  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022EC5C 0022BA5C  38 80 02 B6 */	li r4, 0x2b6
/* 8022EC60 0022BA60  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022EC64 0022BA64  48 1F 98 55 */	bl __assert
.L_8022EC68:
/* 8022EC68 0022BA68  7F E3 FB 78 */	mr r3, r31
/* 8022EC6C 0022BA6C  48 00 30 81 */	bl kar_pltrick__near_80231cec
/* 8022EC70 0022BA70  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022EC74 0022BA74  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022EC78 0022BA78  7C 08 03 A6 */	mtlr r0
/* 8022EC7C 0022BA7C  38 21 00 10 */	addi r1, r1, 0x10
/* 8022EC80 0022BA80  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022ec34

# .text:0xE10 | 0x8022EC84 | size: 0x54
.fn kar_plclearcheckerlib__near_8022ec84, global
/* 8022EC84 0022BA84  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022EC88 0022BA88  7C 08 02 A6 */	mflr r0
/* 8022EC8C 0022BA8C  2C 03 00 05 */	cmpwi r3, 0x5
/* 8022EC90 0022BA90  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022EC94 0022BA94  40 80 00 34 */	bge .L_8022ECC8
/* 8022EC98 0022BA98  2C 04 00 05 */	cmpwi r4, 0x5
/* 8022EC9C 0022BA9C  40 80 00 2C */	bge .L_8022ECC8
/* 8022ECA0 0022BAA0  7C 03 20 00 */	cmpw r3, r4
/* 8022ECA4 0022BAA4  41 82 00 24 */	beq .L_8022ECC8
/* 8022ECA8 0022BAA8  4B FF E5 A1 */	bl kar_plclearchecker_get_player_state
/* 8022ECAC 0022BAAC  80 03 06 08 */	lwz r0, 0x608(r3)
/* 8022ECB0 0022BAB0  28 00 00 00 */	cmplwi r0, 0x0
/* 8022ECB4 0022BAB4  41 82 00 14 */	beq .L_8022ECC8
/* 8022ECB8 0022BAB8  88 03 08 4C */	lbz r0, 0x84c(r3)
/* 8022ECBC 0022BABC  38 80 00 01 */	li r4, 0x1
/* 8022ECC0 0022BAC0  50 80 3E 30 */	rlwimi r0, r4, 7, 24, 24
/* 8022ECC4 0022BAC4  98 03 08 4C */	stb r0, 0x84c(r3)
.L_8022ECC8:
/* 8022ECC8 0022BAC8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022ECCC 0022BACC  7C 08 03 A6 */	mtlr r0
/* 8022ECD0 0022BAD0  38 21 00 10 */	addi r1, r1, 0x10
/* 8022ECD4 0022BAD4  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_8022ec84

# .text:0xE64 | 0x8022ECD8 | size: 0x40
.fn kar_plclearcheckerlib__near_8022ecd8, global
/* 8022ECD8 0022BAD8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022ECDC 0022BADC  7C 08 02 A6 */	mflr r0
/* 8022ECE0 0022BAE0  2C 03 00 05 */	cmpwi r3, 0x5
/* 8022ECE4 0022BAE4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022ECE8 0022BAE8  40 80 00 20 */	bge .L_8022ED08
/* 8022ECEC 0022BAEC  4B FF E5 5D */	bl kar_plclearchecker_get_player_state
/* 8022ECF0 0022BAF0  88 03 08 55 */	lbz r0, 0x855(r3)
/* 8022ECF4 0022BAF4  54 00 D7 FF */	extrwi. r0, r0, 1, 25
/* 8022ECF8 0022BAF8  40 82 00 10 */	bne .L_8022ED08
/* 8022ECFC 0022BAFC  80 83 07 D4 */	lwz r4, 0x7d4(r3)
/* 8022ED00 0022BB00  38 04 00 01 */	addi r0, r4, 0x1
/* 8022ED04 0022BB04  90 03 07 D4 */	stw r0, 0x7d4(r3)
.L_8022ED08:
/* 8022ED08 0022BB08  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022ED0C 0022BB0C  7C 08 03 A6 */	mtlr r0
/* 8022ED10 0022BB10  38 21 00 10 */	addi r1, r1, 0x10
/* 8022ED14 0022BB14  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_8022ecd8

# .text:0xEA4 | 0x8022ED18 | size: 0x38
.fn kar_plclearcheckerlib__near_8022ed18, global
/* 8022ED18 0022BB18  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022ED1C 0022BB1C  7C 08 02 A6 */	mflr r0
/* 8022ED20 0022BB20  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022ED24 0022BB24  4B FF E5 25 */	bl kar_plclearchecker_get_player_state
/* 8022ED28 0022BB28  88 03 08 55 */	lbz r0, 0x855(r3)
/* 8022ED2C 0022BB2C  54 00 D7 FF */	extrwi. r0, r0, 1, 25
/* 8022ED30 0022BB30  40 82 00 10 */	bne .L_8022ED40
/* 8022ED34 0022BB34  80 83 07 D8 */	lwz r4, 0x7d8(r3)
/* 8022ED38 0022BB38  38 04 00 01 */	addi r0, r4, 0x1
/* 8022ED3C 0022BB3C  90 03 07 D8 */	stw r0, 0x7d8(r3)
.L_8022ED40:
/* 8022ED40 0022BB40  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022ED44 0022BB44  7C 08 03 A6 */	mtlr r0
/* 8022ED48 0022BB48  38 21 00 10 */	addi r1, r1, 0x10
/* 8022ED4C 0022BB4C  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_8022ed18

# .text:0xEDC | 0x8022ED50 | size: 0x58
.fn kar_plclearcheckerlib__8022ed50, global
/* 8022ED50 0022BB50  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022ED54 0022BB54  7C 08 02 A6 */	mflr r0
/* 8022ED58 0022BB58  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022ED5C 0022BB5C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022ED60 0022BB60  7C 7F 1B 78 */	mr r31, r3
/* 8022ED64 0022BB64  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022ED68 0022BB68  41 80 00 1C */	blt .L_8022ED84
/* 8022ED6C 0022BB6C  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022ED70 0022BB70  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022ED74 0022BB74  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022ED78 0022BB78  38 80 03 0D */	li r4, 0x30d
/* 8022ED7C 0022BB7C  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022ED80 0022BB80  48 1F 97 39 */	bl __assert
.L_8022ED84:
/* 8022ED84 0022BB84  7F E3 FB 78 */	mr r3, r31
/* 8022ED88 0022BB88  4B FF E4 C1 */	bl kar_plclearchecker_get_player_state
/* 8022ED8C 0022BB8C  88 03 03 7A */	lbz r0, 0x37a(r3)
/* 8022ED90 0022BB90  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022ED94 0022BB94  54 03 EF FE */	extrwi r3, r0, 1, 28
/* 8022ED98 0022BB98  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022ED9C 0022BB9C  7C 08 03 A6 */	mtlr r0
/* 8022EDA0 0022BBA0  38 21 00 10 */	addi r1, r1, 0x10
/* 8022EDA4 0022BBA4  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022ed50

# .text:0xF34 | 0x8022EDA8 | size: 0x58
.fn kar_plclearcheckerlib__8022eda8, global
/* 8022EDA8 0022BBA8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022EDAC 0022BBAC  7C 08 02 A6 */	mflr r0
/* 8022EDB0 0022BBB0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022EDB4 0022BBB4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022EDB8 0022BBB8  7C 7F 1B 78 */	mr r31, r3
/* 8022EDBC 0022BBBC  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022EDC0 0022BBC0  41 80 00 1C */	blt .L_8022EDDC
/* 8022EDC4 0022BBC4  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022EDC8 0022BBC8  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022EDCC 0022BBCC  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022EDD0 0022BBD0  38 80 03 16 */	li r4, 0x316
/* 8022EDD4 0022BBD4  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022EDD8 0022BBD8  48 1F 96 E1 */	bl __assert
.L_8022EDDC:
/* 8022EDDC 0022BBDC  7F E3 FB 78 */	mr r3, r31
/* 8022EDE0 0022BBE0  4B FF E4 69 */	bl kar_plclearchecker_get_player_state
/* 8022EDE4 0022BBE4  88 03 03 7A */	lbz r0, 0x37a(r3)
/* 8022EDE8 0022BBE8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022EDEC 0022BBEC  54 03 DF FE */	extrwi r3, r0, 1, 26
/* 8022EDF0 0022BBF0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022EDF4 0022BBF4  7C 08 03 A6 */	mtlr r0
/* 8022EDF8 0022BBF8  38 21 00 10 */	addi r1, r1, 0x10
/* 8022EDFC 0022BBFC  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022eda8

# .text:0xF8C | 0x8022EE00 | size: 0x350
.fn kar_plclearcheckerlib__near_8022ee00, global
/* 8022EE00 0022BC00  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022EE04 0022BC04  7C 08 02 A6 */	mflr r0
/* 8022EE08 0022BC08  2C 03 00 05 */	cmpwi r3, 0x5
/* 8022EE0C 0022BC0C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022EE10 0022BC10  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022EE14 0022BC14  7C 9F 23 78 */	mr r31, r4
/* 8022EE18 0022BC18  41 82 03 24 */	beq .L_8022F13C
/* 8022EE1C 0022BC1C  4B FF E4 2D */	bl kar_plclearchecker_get_player_state
/* 8022EE20 0022BC20  88 03 03 78 */	lbz r0, 0x378(r3)
/* 8022EE24 0022BC24  54 00 EE FE */	extrwi r0, r0, 5, 24
/* 8022EE28 0022BC28  28 00 00 06 */	cmplwi r0, 0x6
/* 8022EE2C 0022BC2C  40 82 00 44 */	bne .L_8022EE70
/* 8022EE30 0022BC30  7C 64 1B 78 */	mr r4, r3
/* 8022EE34 0022BC34  38 C0 00 00 */	li r6, 0x0
/* 8022EE38 0022BC38  48 00 00 14 */	b .L_8022EE4C
.L_8022EE3C:
/* 8022EE3C 0022BC3C  80 04 03 64 */	lwz r0, 0x364(r4)
/* 8022EE40 0022BC40  38 C6 00 01 */	addi r6, r6, 0x1
/* 8022EE44 0022BC44  90 04 03 60 */	stw r0, 0x360(r4)
/* 8022EE48 0022BC48  38 84 00 04 */	addi r4, r4, 0x4
.L_8022EE4C:
/* 8022EE4C 0022BC4C  88 03 03 78 */	lbz r0, 0x378(r3)
/* 8022EE50 0022BC50  54 05 EE FE */	extrwi r5, r0, 5, 24
/* 8022EE54 0022BC54  38 05 FF FF */	subi r0, r5, 0x1
/* 8022EE58 0022BC58  7C 06 00 00 */	cmpw r6, r0
/* 8022EE5C 0022BC5C  41 80 FF E0 */	blt .L_8022EE3C
/* 8022EE60 0022BC60  54 A0 10 3A */	slwi r0, r5, 2
/* 8022EE64 0022BC64  7C 83 02 14 */	add r4, r3, r0
/* 8022EE68 0022BC68  93 E4 03 5C */	stw r31, 0x35c(r4)
/* 8022EE6C 0022BC6C  48 00 00 24 */	b .L_8022EE90
.L_8022EE70:
/* 8022EE70 0022BC70  54 00 15 BA */	clrlslwi r0, r0, 24, 2
/* 8022EE74 0022BC74  7C 83 02 14 */	add r4, r3, r0
/* 8022EE78 0022BC78  93 E4 03 60 */	stw r31, 0x360(r4)
/* 8022EE7C 0022BC7C  88 A3 03 78 */	lbz r5, 0x378(r3)
/* 8022EE80 0022BC80  54 A4 EE FE */	extrwi r4, r5, 5, 24
/* 8022EE84 0022BC84  38 04 00 01 */	addi r0, r4, 0x1
/* 8022EE88 0022BC88  50 05 1E 38 */	rlwimi r5, r0, 3, 24, 28
/* 8022EE8C 0022BC8C  98 A3 03 78 */	stb r5, 0x378(r3)
.L_8022EE90:
/* 8022EE90 0022BC90  38 C0 00 00 */	li r6, 0x0
/* 8022EE94 0022BC94  3C 80 80 4B */	lis r4, lbl_804B4C20@ha
/* 8022EE98 0022BC98  38 00 00 02 */	li r0, 0x2
/* 8022EE9C 0022BC9C  7C 68 1B 78 */	mr r8, r3
/* 8022EEA0 0022BCA0  7C C7 33 78 */	mr r7, r6
/* 8022EEA4 0022BCA4  38 84 4C 20 */	addi r4, r4, lbl_804B4C20@l
/* 8022EEA8 0022BCA8  7C 09 03 A6 */	mtctr r0
.L_8022EEAC:
/* 8022EEAC 0022BCAC  54 C0 10 3A */	slwi r0, r6, 2
/* 8022EEB0 0022BCB0  80 A8 03 60 */	lwz r5, 0x360(r8)
/* 8022EEB4 0022BCB4  7C 04 00 2E */	lwzx r0, r4, r0
/* 8022EEB8 0022BCB8  7C 05 00 00 */	cmpw r5, r0
/* 8022EEBC 0022BCBC  40 82 00 0C */	bne .L_8022EEC8
/* 8022EEC0 0022BCC0  38 C6 00 01 */	addi r6, r6, 0x1
/* 8022EEC4 0022BCC4  48 00 00 10 */	b .L_8022EED4
.L_8022EEC8:
/* 8022EEC8 0022BCC8  2C 00 00 0B */	cmpwi r0, 0xb
/* 8022EECC 0022BCCC  41 82 00 08 */	beq .L_8022EED4
/* 8022EED0 0022BCD0  38 C0 00 00 */	li r6, 0x0
.L_8022EED4:
/* 8022EED4 0022BCD4  54 C0 10 3A */	slwi r0, r6, 2
/* 8022EED8 0022BCD8  80 A8 03 64 */	lwz r5, 0x364(r8)
/* 8022EEDC 0022BCDC  7C 04 00 2E */	lwzx r0, r4, r0
/* 8022EEE0 0022BCE0  7C 05 00 00 */	cmpw r5, r0
/* 8022EEE4 0022BCE4  40 82 00 0C */	bne .L_8022EEF0
/* 8022EEE8 0022BCE8  38 C6 00 01 */	addi r6, r6, 0x1
/* 8022EEEC 0022BCEC  48 00 00 10 */	b .L_8022EEFC
.L_8022EEF0:
/* 8022EEF0 0022BCF0  2C 00 00 0B */	cmpwi r0, 0xb
/* 8022EEF4 0022BCF4  41 82 00 08 */	beq .L_8022EEFC
/* 8022EEF8 0022BCF8  38 C0 00 00 */	li r6, 0x0
.L_8022EEFC:
/* 8022EEFC 0022BCFC  54 C0 10 3A */	slwi r0, r6, 2
/* 8022EF00 0022BD00  80 A8 03 68 */	lwz r5, 0x368(r8)
/* 8022EF04 0022BD04  7C 04 00 2E */	lwzx r0, r4, r0
/* 8022EF08 0022BD08  7C 05 00 00 */	cmpw r5, r0
/* 8022EF0C 0022BD0C  40 82 00 0C */	bne .L_8022EF18
/* 8022EF10 0022BD10  38 C6 00 01 */	addi r6, r6, 0x1
/* 8022EF14 0022BD14  48 00 00 10 */	b .L_8022EF24
.L_8022EF18:
/* 8022EF18 0022BD18  2C 00 00 0B */	cmpwi r0, 0xb
/* 8022EF1C 0022BD1C  41 82 00 08 */	beq .L_8022EF24
/* 8022EF20 0022BD20  38 C0 00 00 */	li r6, 0x0
.L_8022EF24:
/* 8022EF24 0022BD24  39 08 00 0C */	addi r8, r8, 0xc
/* 8022EF28 0022BD28  38 E7 00 02 */	addi r7, r7, 0x2
/* 8022EF2C 0022BD2C  42 00 FF 80 */	bdnz .L_8022EEAC
/* 8022EF30 0022BD30  3C 80 80 4B */	lis r4, lbl_804B4C20@ha
/* 8022EF34 0022BD34  54 C0 10 3A */	slwi r0, r6, 2
/* 8022EF38 0022BD38  38 84 4C 20 */	addi r4, r4, lbl_804B4C20@l
/* 8022EF3C 0022BD3C  7C 04 00 2E */	lwzx r0, r4, r0
/* 8022EF40 0022BD40  2C 00 00 0B */	cmpwi r0, 0xb
/* 8022EF44 0022BD44  40 82 00 14 */	bne .L_8022EF58
/* 8022EF48 0022BD48  88 03 03 78 */	lbz r0, 0x378(r3)
/* 8022EF4C 0022BD4C  38 80 00 01 */	li r4, 0x1
/* 8022EF50 0022BD50  50 80 17 7A */	rlwimi r0, r4, 2, 29, 29
/* 8022EF54 0022BD54  98 03 03 78 */	stb r0, 0x378(r3)
.L_8022EF58:
/* 8022EF58 0022BD58  38 E0 00 00 */	li r7, 0x0
/* 8022EF5C 0022BD5C  3C 80 80 4B */	lis r4, lbl_804B4C20@ha
/* 8022EF60 0022BD60  38 00 00 02 */	li r0, 0x2
/* 8022EF64 0022BD64  7C 69 1B 78 */	mr r9, r3
/* 8022EF68 0022BD68  7C E8 3B 78 */	mr r8, r7
/* 8022EF6C 0022BD6C  38 A4 4C 20 */	addi r5, r4, lbl_804B4C20@l
/* 8022EF70 0022BD70  7C 09 03 A6 */	mtctr r0
.L_8022EF74:
/* 8022EF74 0022BD74  54 E0 10 3A */	slwi r0, r7, 2
/* 8022EF78 0022BD78  80 C9 03 60 */	lwz r6, 0x360(r9)
/* 8022EF7C 0022BD7C  7C 85 02 14 */	add r4, r5, r0
/* 8022EF80 0022BD80  80 04 00 18 */	lwz r0, 0x18(r4)
/* 8022EF84 0022BD84  7C 06 00 00 */	cmpw r6, r0
/* 8022EF88 0022BD88  40 82 00 0C */	bne .L_8022EF94
/* 8022EF8C 0022BD8C  38 E7 00 01 */	addi r7, r7, 0x1
/* 8022EF90 0022BD90  48 00 00 10 */	b .L_8022EFA0
.L_8022EF94:
/* 8022EF94 0022BD94  2C 00 00 0B */	cmpwi r0, 0xb
/* 8022EF98 0022BD98  41 82 00 08 */	beq .L_8022EFA0
/* 8022EF9C 0022BD9C  38 E0 00 00 */	li r7, 0x0
.L_8022EFA0:
/* 8022EFA0 0022BDA0  54 E0 10 3A */	slwi r0, r7, 2
/* 8022EFA4 0022BDA4  80 C9 03 64 */	lwz r6, 0x364(r9)
/* 8022EFA8 0022BDA8  7C 85 02 14 */	add r4, r5, r0
/* 8022EFAC 0022BDAC  80 04 00 18 */	lwz r0, 0x18(r4)
/* 8022EFB0 0022BDB0  7C 06 00 00 */	cmpw r6, r0
/* 8022EFB4 0022BDB4  40 82 00 0C */	bne .L_8022EFC0
/* 8022EFB8 0022BDB8  38 E7 00 01 */	addi r7, r7, 0x1
/* 8022EFBC 0022BDBC  48 00 00 10 */	b .L_8022EFCC
.L_8022EFC0:
/* 8022EFC0 0022BDC0  2C 00 00 0B */	cmpwi r0, 0xb
/* 8022EFC4 0022BDC4  41 82 00 08 */	beq .L_8022EFCC
/* 8022EFC8 0022BDC8  38 E0 00 00 */	li r7, 0x0
.L_8022EFCC:
/* 8022EFCC 0022BDCC  54 E0 10 3A */	slwi r0, r7, 2
/* 8022EFD0 0022BDD0  80 C9 03 68 */	lwz r6, 0x368(r9)
/* 8022EFD4 0022BDD4  7C 85 02 14 */	add r4, r5, r0
/* 8022EFD8 0022BDD8  80 04 00 18 */	lwz r0, 0x18(r4)
/* 8022EFDC 0022BDDC  7C 06 00 00 */	cmpw r6, r0
/* 8022EFE0 0022BDE0  40 82 00 0C */	bne .L_8022EFEC
/* 8022EFE4 0022BDE4  38 E7 00 01 */	addi r7, r7, 0x1
/* 8022EFE8 0022BDE8  48 00 00 10 */	b .L_8022EFF8
.L_8022EFEC:
/* 8022EFEC 0022BDEC  2C 00 00 0B */	cmpwi r0, 0xb
/* 8022EFF0 0022BDF0  41 82 00 08 */	beq .L_8022EFF8
/* 8022EFF4 0022BDF4  38 E0 00 00 */	li r7, 0x0
.L_8022EFF8:
/* 8022EFF8 0022BDF8  39 29 00 0C */	addi r9, r9, 0xc
/* 8022EFFC 0022BDFC  39 08 00 02 */	addi r8, r8, 0x2
/* 8022F000 0022BE00  42 00 FF 74 */	bdnz .L_8022EF74
/* 8022F004 0022BE04  3C 80 80 4B */	lis r4, lbl_804B4C20@ha
/* 8022F008 0022BE08  54 E0 10 3A */	slwi r0, r7, 2
/* 8022F00C 0022BE0C  38 84 4C 20 */	addi r4, r4, lbl_804B4C20@l
/* 8022F010 0022BE10  7C 84 02 14 */	add r4, r4, r0
/* 8022F014 0022BE14  80 04 00 18 */	lwz r0, 0x18(r4)
/* 8022F018 0022BE18  2C 00 00 0B */	cmpwi r0, 0xb
/* 8022F01C 0022BE1C  40 82 00 14 */	bne .L_8022F030
/* 8022F020 0022BE20  88 03 03 78 */	lbz r0, 0x378(r3)
/* 8022F024 0022BE24  38 80 00 01 */	li r4, 0x1
/* 8022F028 0022BE28  50 80 0F BC */	rlwimi r0, r4, 1, 30, 30
/* 8022F02C 0022BE2C  98 03 03 78 */	stb r0, 0x378(r3)
.L_8022F030:
/* 8022F030 0022BE30  38 E0 00 00 */	li r7, 0x0
/* 8022F034 0022BE34  3C 80 80 4B */	lis r4, lbl_804B4C20@ha
/* 8022F038 0022BE38  38 00 00 02 */	li r0, 0x2
/* 8022F03C 0022BE3C  7C 69 1B 78 */	mr r9, r3
/* 8022F040 0022BE40  7C E8 3B 78 */	mr r8, r7
/* 8022F044 0022BE44  38 A4 4C 20 */	addi r5, r4, lbl_804B4C20@l
/* 8022F048 0022BE48  7C 09 03 A6 */	mtctr r0
.L_8022F04C:
/* 8022F04C 0022BE4C  54 E0 10 3A */	slwi r0, r7, 2
/* 8022F050 0022BE50  80 C9 03 60 */	lwz r6, 0x360(r9)
/* 8022F054 0022BE54  7C 85 02 14 */	add r4, r5, r0
/* 8022F058 0022BE58  80 04 00 30 */	lwz r0, 0x30(r4)
/* 8022F05C 0022BE5C  7C 06 00 00 */	cmpw r6, r0
/* 8022F060 0022BE60  40 82 00 0C */	bne .L_8022F06C
/* 8022F064 0022BE64  38 E7 00 01 */	addi r7, r7, 0x1
/* 8022F068 0022BE68  48 00 00 10 */	b .L_8022F078
.L_8022F06C:
/* 8022F06C 0022BE6C  2C 00 00 0B */	cmpwi r0, 0xb
/* 8022F070 0022BE70  41 82 00 08 */	beq .L_8022F078
/* 8022F074 0022BE74  38 E0 00 00 */	li r7, 0x0
.L_8022F078:
/* 8022F078 0022BE78  54 E0 10 3A */	slwi r0, r7, 2
/* 8022F07C 0022BE7C  80 C9 03 64 */	lwz r6, 0x364(r9)
/* 8022F080 0022BE80  7C 85 02 14 */	add r4, r5, r0
/* 8022F084 0022BE84  80 04 00 30 */	lwz r0, 0x30(r4)
/* 8022F088 0022BE88  7C 06 00 00 */	cmpw r6, r0
/* 8022F08C 0022BE8C  40 82 00 0C */	bne .L_8022F098
/* 8022F090 0022BE90  38 E7 00 01 */	addi r7, r7, 0x1
/* 8022F094 0022BE94  48 00 00 10 */	b .L_8022F0A4
.L_8022F098:
/* 8022F098 0022BE98  2C 00 00 0B */	cmpwi r0, 0xb
/* 8022F09C 0022BE9C  41 82 00 08 */	beq .L_8022F0A4
/* 8022F0A0 0022BEA0  38 E0 00 00 */	li r7, 0x0
.L_8022F0A4:
/* 8022F0A4 0022BEA4  54 E0 10 3A */	slwi r0, r7, 2
/* 8022F0A8 0022BEA8  80 C9 03 68 */	lwz r6, 0x368(r9)
/* 8022F0AC 0022BEAC  7C 85 02 14 */	add r4, r5, r0
/* 8022F0B0 0022BEB0  80 04 00 30 */	lwz r0, 0x30(r4)
/* 8022F0B4 0022BEB4  7C 06 00 00 */	cmpw r6, r0
/* 8022F0B8 0022BEB8  40 82 00 0C */	bne .L_8022F0C4
/* 8022F0BC 0022BEBC  38 E7 00 01 */	addi r7, r7, 0x1
/* 8022F0C0 0022BEC0  48 00 00 10 */	b .L_8022F0D0
.L_8022F0C4:
/* 8022F0C4 0022BEC4  2C 00 00 0B */	cmpwi r0, 0xb
/* 8022F0C8 0022BEC8  41 82 00 08 */	beq .L_8022F0D0
/* 8022F0CC 0022BECC  38 E0 00 00 */	li r7, 0x0
.L_8022F0D0:
/* 8022F0D0 0022BED0  39 29 00 0C */	addi r9, r9, 0xc
/* 8022F0D4 0022BED4  39 08 00 02 */	addi r8, r8, 0x2
/* 8022F0D8 0022BED8  42 00 FF 74 */	bdnz .L_8022F04C
/* 8022F0DC 0022BEDC  3C 80 80 4B */	lis r4, lbl_804B4C20@ha
/* 8022F0E0 0022BEE0  54 E0 10 3A */	slwi r0, r7, 2
/* 8022F0E4 0022BEE4  38 84 4C 20 */	addi r4, r4, lbl_804B4C20@l
/* 8022F0E8 0022BEE8  7C 84 02 14 */	add r4, r4, r0
/* 8022F0EC 0022BEEC  80 04 00 30 */	lwz r0, 0x30(r4)
/* 8022F0F0 0022BEF0  2C 00 00 0B */	cmpwi r0, 0xb
/* 8022F0F4 0022BEF4  40 82 00 14 */	bne .L_8022F108
/* 8022F0F8 0022BEF8  88 03 03 78 */	lbz r0, 0x378(r3)
/* 8022F0FC 0022BEFC  38 80 00 01 */	li r4, 0x1
/* 8022F100 0022BF00  50 80 07 FE */	rlwimi r0, r4, 0, 31, 31
/* 8022F104 0022BF04  98 03 03 78 */	stb r0, 0x378(r3)
.L_8022F108:
/* 8022F108 0022BF08  57 E0 10 3A */	slwi r0, r31, 2
/* 8022F10C 0022BF0C  7C A3 02 14 */	add r5, r3, r0
/* 8022F110 0022BF10  80 85 03 34 */	lwz r4, 0x334(r5)
/* 8022F114 0022BF14  38 04 00 01 */	addi r0, r4, 0x1
/* 8022F118 0022BF18  90 05 03 34 */	stw r0, 0x334(r5)
/* 8022F11C 0022BF1C  88 03 08 55 */	lbz r0, 0x855(r3)
/* 8022F120 0022BF20  54 00 D7 FF */	extrwi. r0, r0, 1, 25
/* 8022F124 0022BF24  40 82 00 18 */	bne .L_8022F13C
/* 8022F128 0022BF28  2C 1F 00 02 */	cmpwi r31, 0x2
/* 8022F12C 0022BF2C  40 82 00 10 */	bne .L_8022F13C
/* 8022F130 0022BF30  80 83 07 DC */	lwz r4, 0x7dc(r3)
/* 8022F134 0022BF34  38 04 00 01 */	addi r0, r4, 0x1
/* 8022F138 0022BF38  90 03 07 DC */	stw r0, 0x7dc(r3)
.L_8022F13C:
/* 8022F13C 0022BF3C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022F140 0022BF40  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022F144 0022BF44  7C 08 03 A6 */	mtlr r0
/* 8022F148 0022BF48  38 21 00 10 */	addi r1, r1, 0x10
/* 8022F14C 0022BF4C  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_8022ee00

# .text:0x12DC | 0x8022F150 | size: 0x4C
.fn kar_plclearcheckerlib__near_8022f150, global
/* 8022F150 0022BF50  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022F154 0022BF54  7C 08 02 A6 */	mflr r0
/* 8022F158 0022BF58  2C 03 00 05 */	cmpwi r3, 0x5
/* 8022F15C 0022BF5C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022F160 0022BF60  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022F164 0022BF64  7C 9F 23 78 */	mr r31, r4
/* 8022F168 0022BF68  41 82 00 20 */	beq .L_8022F188
/* 8022F16C 0022BF6C  4B FF E0 DD */	bl kar_plclearchecker_get_player_state
/* 8022F170 0022BF70  20 1F 00 0F */	subfic r0, r31, 0xf
/* 8022F174 0022BF74  38 80 00 01 */	li r4, 0x1
/* 8022F178 0022BF78  A0 A3 03 7A */	lhz r5, 0x37a(r3)
/* 8022F17C 0022BF7C  7C 80 00 30 */	slw r0, r4, r0
/* 8022F180 0022BF80  7C A0 03 78 */	or r0, r5, r0
/* 8022F184 0022BF84  B0 03 03 7A */	sth r0, 0x37a(r3)
.L_8022F188:
/* 8022F188 0022BF88  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022F18C 0022BF8C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022F190 0022BF90  7C 08 03 A6 */	mtlr r0
/* 8022F194 0022BF94  38 21 00 10 */	addi r1, r1, 0x10
/* 8022F198 0022BF98  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_8022f150

# .text:0x1328 | 0x8022F19C | size: 0x104
.fn kar_plclearcheckerlib__8022f19c, global
/* 8022F19C 0022BF9C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8022F1A0 0022BFA0  7C 08 02 A6 */	mflr r0
/* 8022F1A4 0022BFA4  90 01 00 24 */	stw r0, 0x24(r1)
/* 8022F1A8 0022BFA8  39 61 00 20 */	addi r11, r1, 0x20
/* 8022F1AC 0022BFAC  48 17 E9 A9 */	bl _savegpr_27
/* 8022F1B0 0022BFB0  7C 7B 1B 78 */	mr r27, r3
/* 8022F1B4 0022BFB4  3C 60 80 4B */	lis r3, lbl_804B4C20@ha
/* 8022F1B8 0022BFB8  2C 1B 00 05 */	cmpwi r27, 0x5
/* 8022F1BC 0022BFBC  3B A0 00 00 */	li r29, 0x0
/* 8022F1C0 0022BFC0  3B E3 4C 20 */	addi r31, r3, lbl_804B4C20@l
/* 8022F1C4 0022BFC4  41 80 00 14 */	blt .L_8022F1D8
/* 8022F1C8 0022BFC8  38 7F 00 BC */	addi r3, r31, 0xbc
/* 8022F1CC 0022BFCC  38 BF 00 D0 */	addi r5, r31, 0xd0
/* 8022F1D0 0022BFD0  38 80 03 8E */	li r4, 0x38e
/* 8022F1D4 0022BFD4  48 1F 92 E5 */	bl __assert
.L_8022F1D8:
/* 8022F1D8 0022BFD8  3B 80 00 00 */	li r28, 0x0
/* 8022F1DC 0022BFDC  3B C0 00 00 */	li r30, 0x0
.L_8022F1E0:
/* 8022F1E0 0022BFE0  2C 1C 00 13 */	cmpwi r28, 0x13
/* 8022F1E4 0022BFE4  40 80 00 4C */	bge .L_8022F230
/* 8022F1E8 0022BFE8  2C 1C 00 1A */	cmpwi r28, 0x1a
/* 8022F1EC 0022BFEC  41 80 00 14 */	blt .L_8022F200
/* 8022F1F0 0022BFF0  38 7F 00 BC */	addi r3, r31, 0xbc
/* 8022F1F4 0022BFF4  38 BF 00 EC */	addi r5, r31, 0xec
/* 8022F1F8 0022BFF8  38 80 03 68 */	li r4, 0x368
/* 8022F1FC 0022BFFC  48 1F 92 BD */	bl __assert
.L_8022F200:
/* 8022F200 0022C000  2C 1B 00 05 */	cmpwi r27, 0x5
/* 8022F204 0022C004  41 80 00 14 */	blt .L_8022F218
/* 8022F208 0022C008  38 7F 00 BC */	addi r3, r31, 0xbc
/* 8022F20C 0022C00C  38 BF 00 D0 */	addi r5, r31, 0xd0
/* 8022F210 0022C010  38 80 03 69 */	li r4, 0x369
/* 8022F214 0022C014  48 1F 92 A5 */	bl __assert
.L_8022F218:
/* 8022F218 0022C018  7F 63 DB 78 */	mr r3, r27
/* 8022F21C 0022C01C  4B FF E0 2D */	bl kar_plclearchecker_get_player_state
/* 8022F220 0022C020  38 1E 03 7C */	addi r0, r30, 0x37c
/* 8022F224 0022C024  7C 03 00 2E */	lwzx r0, r3, r0
/* 8022F228 0022C028  7F BD 02 14 */	add r29, r29, r0
/* 8022F22C 0022C02C  48 00 00 48 */	b .L_8022F274
.L_8022F230:
/* 8022F230 0022C030  2C 1C 00 1A */	cmpwi r28, 0x1a
/* 8022F234 0022C034  41 80 00 14 */	blt .L_8022F248
/* 8022F238 0022C038  38 7F 00 BC */	addi r3, r31, 0xbc
/* 8022F23C 0022C03C  38 BF 00 EC */	addi r5, r31, 0xec
/* 8022F240 0022C040  38 80 03 68 */	li r4, 0x368
/* 8022F244 0022C044  48 1F 92 75 */	bl __assert
.L_8022F248:
/* 8022F248 0022C048  2C 1B 00 05 */	cmpwi r27, 0x5
/* 8022F24C 0022C04C  41 80 00 14 */	blt .L_8022F260
/* 8022F250 0022C050  38 7F 00 BC */	addi r3, r31, 0xbc
/* 8022F254 0022C054  38 BF 00 D0 */	addi r5, r31, 0xd0
/* 8022F258 0022C058  38 80 03 69 */	li r4, 0x369
/* 8022F25C 0022C05C  48 1F 92 5D */	bl __assert
.L_8022F260:
/* 8022F260 0022C060  7F 63 DB 78 */	mr r3, r27
/* 8022F264 0022C064  4B FF DF E5 */	bl kar_plclearchecker_get_player_state
/* 8022F268 0022C068  38 1E 03 7C */	addi r0, r30, 0x37c
/* 8022F26C 0022C06C  7C 03 00 2E */	lwzx r0, r3, r0
/* 8022F270 0022C070  7F BD 02 14 */	add r29, r29, r0
.L_8022F274:
/* 8022F274 0022C074  3B 9C 00 01 */	addi r28, r28, 0x1
/* 8022F278 0022C078  3B DE 00 04 */	addi r30, r30, 0x4
/* 8022F27C 0022C07C  2C 1C 00 1A */	cmpwi r28, 0x1a
/* 8022F280 0022C080  41 80 FF 60 */	blt .L_8022F1E0
/* 8022F284 0022C084  7F A3 EB 78 */	mr r3, r29
/* 8022F288 0022C088  39 61 00 20 */	addi r11, r1, 0x20
/* 8022F28C 0022C08C  48 17 E9 15 */	bl _restgpr_27
/* 8022F290 0022C090  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8022F294 0022C094  7C 08 03 A6 */	mtlr r0
/* 8022F298 0022C098  38 21 00 20 */	addi r1, r1, 0x20
/* 8022F29C 0022C09C  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022f19c

# .text:0x142C | 0x8022F2A0 | size: 0x104
.fn kar_plclearcheckerlib__8022f2a0, global
/* 8022F2A0 0022C0A0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8022F2A4 0022C0A4  7C 08 02 A6 */	mflr r0
/* 8022F2A8 0022C0A8  90 01 00 24 */	stw r0, 0x24(r1)
/* 8022F2AC 0022C0AC  39 61 00 20 */	addi r11, r1, 0x20
/* 8022F2B0 0022C0B0  48 17 E8 A5 */	bl _savegpr_27
/* 8022F2B4 0022C0B4  7C 7B 1B 78 */	mr r27, r3
/* 8022F2B8 0022C0B8  3C 60 80 4B */	lis r3, lbl_804B4C20@ha
/* 8022F2BC 0022C0BC  2C 1B 00 05 */	cmpwi r27, 0x5
/* 8022F2C0 0022C0C0  3B A0 00 00 */	li r29, 0x0
/* 8022F2C4 0022C0C4  3B E3 4C 20 */	addi r31, r3, lbl_804B4C20@l
/* 8022F2C8 0022C0C8  41 80 00 14 */	blt .L_8022F2DC
/* 8022F2CC 0022C0CC  38 7F 00 BC */	addi r3, r31, 0xbc
/* 8022F2D0 0022C0D0  38 BF 00 D0 */	addi r5, r31, 0xd0
/* 8022F2D4 0022C0D4  38 80 03 A1 */	li r4, 0x3a1
/* 8022F2D8 0022C0D8  48 1F 91 E1 */	bl __assert
.L_8022F2DC:
/* 8022F2DC 0022C0DC  3B 80 00 00 */	li r28, 0x0
/* 8022F2E0 0022C0E0  3B C0 00 00 */	li r30, 0x0
.L_8022F2E4:
/* 8022F2E4 0022C0E4  2C 1C 00 13 */	cmpwi r28, 0x13
/* 8022F2E8 0022C0E8  40 80 00 4C */	bge .L_8022F334
/* 8022F2EC 0022C0EC  2C 1C 00 1A */	cmpwi r28, 0x1a
/* 8022F2F0 0022C0F0  41 80 00 14 */	blt .L_8022F304
/* 8022F2F4 0022C0F4  38 7F 00 BC */	addi r3, r31, 0xbc
/* 8022F2F8 0022C0F8  38 BF 00 EC */	addi r5, r31, 0xec
/* 8022F2FC 0022C0FC  38 80 03 74 */	li r4, 0x374
/* 8022F300 0022C100  48 1F 91 B9 */	bl __assert
.L_8022F304:
/* 8022F304 0022C104  2C 1B 00 05 */	cmpwi r27, 0x5
/* 8022F308 0022C108  41 80 00 14 */	blt .L_8022F31C
/* 8022F30C 0022C10C  38 7F 00 BC */	addi r3, r31, 0xbc
/* 8022F310 0022C110  38 BF 00 D0 */	addi r5, r31, 0xd0
/* 8022F314 0022C114  38 80 03 75 */	li r4, 0x375
/* 8022F318 0022C118  48 1F 91 A1 */	bl __assert
.L_8022F31C:
/* 8022F31C 0022C11C  7F 63 DB 78 */	mr r3, r27
/* 8022F320 0022C120  4B FF DF 29 */	bl kar_plclearchecker_get_player_state
/* 8022F324 0022C124  38 1E 03 E4 */	addi r0, r30, 0x3e4
/* 8022F328 0022C128  7C 03 00 2E */	lwzx r0, r3, r0
/* 8022F32C 0022C12C  7F BD 02 14 */	add r29, r29, r0
/* 8022F330 0022C130  48 00 00 48 */	b .L_8022F378
.L_8022F334:
/* 8022F334 0022C134  2C 1C 00 1A */	cmpwi r28, 0x1a
/* 8022F338 0022C138  41 80 00 14 */	blt .L_8022F34C
/* 8022F33C 0022C13C  38 7F 00 BC */	addi r3, r31, 0xbc
/* 8022F340 0022C140  38 BF 00 EC */	addi r5, r31, 0xec
/* 8022F344 0022C144  38 80 03 74 */	li r4, 0x374
/* 8022F348 0022C148  48 1F 91 71 */	bl __assert
.L_8022F34C:
/* 8022F34C 0022C14C  2C 1B 00 05 */	cmpwi r27, 0x5
/* 8022F350 0022C150  41 80 00 14 */	blt .L_8022F364
/* 8022F354 0022C154  38 7F 00 BC */	addi r3, r31, 0xbc
/* 8022F358 0022C158  38 BF 00 D0 */	addi r5, r31, 0xd0
/* 8022F35C 0022C15C  38 80 03 75 */	li r4, 0x375
/* 8022F360 0022C160  48 1F 91 59 */	bl __assert
.L_8022F364:
/* 8022F364 0022C164  7F 63 DB 78 */	mr r3, r27
/* 8022F368 0022C168  4B FF DE E1 */	bl kar_plclearchecker_get_player_state
/* 8022F36C 0022C16C  38 1E 03 E4 */	addi r0, r30, 0x3e4
/* 8022F370 0022C170  7C 03 00 2E */	lwzx r0, r3, r0
/* 8022F374 0022C174  7F BD 02 14 */	add r29, r29, r0
.L_8022F378:
/* 8022F378 0022C178  3B 9C 00 01 */	addi r28, r28, 0x1
/* 8022F37C 0022C17C  3B DE 00 04 */	addi r30, r30, 0x4
/* 8022F380 0022C180  2C 1C 00 1A */	cmpwi r28, 0x1a
/* 8022F384 0022C184  41 80 FF 60 */	blt .L_8022F2E4
/* 8022F388 0022C188  7F A3 EB 78 */	mr r3, r29
/* 8022F38C 0022C18C  39 61 00 20 */	addi r11, r1, 0x20
/* 8022F390 0022C190  48 17 E8 11 */	bl _restgpr_27
/* 8022F394 0022C194  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8022F398 0022C198  7C 08 03 A6 */	mtlr r0
/* 8022F39C 0022C19C  38 21 00 20 */	addi r1, r1, 0x20
/* 8022F3A0 0022C1A0  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022f2a0

# .text:0x1530 | 0x8022F3A4 | size: 0x74
.fn kar_plclearcheckerlib__8022f3a4, global
/* 8022F3A4 0022C1A4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022F3A8 0022C1A8  7C 08 02 A6 */	mflr r0
/* 8022F3AC 0022C1AC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022F3B0 0022C1B0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022F3B4 0022C1B4  7C 7F 1B 78 */	mr r31, r3
/* 8022F3B8 0022C1B8  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8022F3BC 0022C1BC  7C 9E 23 78 */	mr r30, r4
/* 8022F3C0 0022C1C0  4B FF DE 89 */	bl kar_plclearchecker_get_player_state
/* 8022F3C4 0022C1C4  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022F3C8 0022C1C8  7C 7F 1B 78 */	mr r31, r3
/* 8022F3CC 0022C1CC  41 80 00 1C */	blt .L_8022F3E8
/* 8022F3D0 0022C1D0  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022F3D4 0022C1D4  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022F3D8 0022C1D8  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022F3DC 0022C1DC  38 80 03 D0 */	li r4, 0x3d0
/* 8022F3E0 0022C1E0  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022F3E4 0022C1E4  48 1F 90 D5 */	bl __assert
.L_8022F3E8:
/* 8022F3E8 0022C1E8  20 1E 00 0F */	subfic r0, r30, 0xf
/* 8022F3EC 0022C1EC  38 60 00 01 */	li r3, 0x1
/* 8022F3F0 0022C1F0  A0 9F 04 C4 */	lhz r4, 0x4c4(r31)
/* 8022F3F4 0022C1F4  7C 60 00 30 */	slw r0, r3, r0
/* 8022F3F8 0022C1F8  7C 80 00 38 */	and r0, r4, r0
/* 8022F3FC 0022C1FC  54 03 04 3E */	clrlwi r3, r0, 16
/* 8022F400 0022C200  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022F404 0022C204  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8022F408 0022C208  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022F40C 0022C20C  7C 08 03 A6 */	mtlr r0
/* 8022F410 0022C210  38 21 00 10 */	addi r1, r1, 0x10
/* 8022F414 0022C214  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022f3a4

# .text:0x15A4 | 0x8022F418 | size: 0x54
.fn kar_plclearcheckerlib__8022f418, global
/* 8022F418 0022C218  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022F41C 0022C21C  7C 08 02 A6 */	mflr r0
/* 8022F420 0022C220  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022F424 0022C224  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022F428 0022C228  7C 7F 1B 78 */	mr r31, r3
/* 8022F42C 0022C22C  4B FF DE 1D */	bl kar_plclearchecker_get_player_state
/* 8022F430 0022C230  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022F434 0022C234  7C 7F 1B 78 */	mr r31, r3
/* 8022F438 0022C238  41 80 00 1C */	blt .L_8022F454
/* 8022F43C 0022C23C  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022F440 0022C240  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022F444 0022C244  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022F448 0022C248  38 80 03 DD */	li r4, 0x3dd
/* 8022F44C 0022C24C  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022F450 0022C250  48 1F 90 69 */	bl __assert
.L_8022F454:
/* 8022F454 0022C254  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022F458 0022C258  80 7F 04 B4 */	lwz r3, 0x4b4(r31)
/* 8022F45C 0022C25C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022F460 0022C260  7C 08 03 A6 */	mtlr r0
/* 8022F464 0022C264  38 21 00 10 */	addi r1, r1, 0x10
/* 8022F468 0022C268  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022f418

# .text:0x15F8 | 0x8022F46C | size: 0x54
.fn kar_plclearcheckerlib__8022f46c, global
/* 8022F46C 0022C26C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022F470 0022C270  7C 08 02 A6 */	mflr r0
/* 8022F474 0022C274  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022F478 0022C278  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022F47C 0022C27C  7C 7F 1B 78 */	mr r31, r3
/* 8022F480 0022C280  4B FF DD C9 */	bl kar_plclearchecker_get_player_state
/* 8022F484 0022C284  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022F488 0022C288  7C 7F 1B 78 */	mr r31, r3
/* 8022F48C 0022C28C  41 80 00 1C */	blt .L_8022F4A8
/* 8022F490 0022C290  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022F494 0022C294  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022F498 0022C298  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022F49C 0022C29C  38 80 03 E8 */	li r4, 0x3e8
/* 8022F4A0 0022C2A0  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022F4A4 0022C2A4  48 1F 90 15 */	bl __assert
.L_8022F4A8:
/* 8022F4A8 0022C2A8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022F4AC 0022C2AC  80 7F 04 B8 */	lwz r3, 0x4b8(r31)
/* 8022F4B0 0022C2B0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022F4B4 0022C2B4  7C 08 03 A6 */	mtlr r0
/* 8022F4B8 0022C2B8  38 21 00 10 */	addi r1, r1, 0x10
/* 8022F4BC 0022C2BC  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022f46c

# .text:0x164C | 0x8022F4C0 | size: 0x54
.fn kar_plclearcheckerlib__8022f4c0, global
/* 8022F4C0 0022C2C0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022F4C4 0022C2C4  7C 08 02 A6 */	mflr r0
/* 8022F4C8 0022C2C8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022F4CC 0022C2CC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022F4D0 0022C2D0  7C 7F 1B 78 */	mr r31, r3
/* 8022F4D4 0022C2D4  4B FF DD 75 */	bl kar_plclearchecker_get_player_state
/* 8022F4D8 0022C2D8  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022F4DC 0022C2DC  7C 7F 1B 78 */	mr r31, r3
/* 8022F4E0 0022C2E0  41 80 00 1C */	blt .L_8022F4FC
/* 8022F4E4 0022C2E4  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022F4E8 0022C2E8  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022F4EC 0022C2EC  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022F4F0 0022C2F0  38 80 03 F3 */	li r4, 0x3f3
/* 8022F4F4 0022C2F4  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022F4F8 0022C2F8  48 1F 8F C1 */	bl __assert
.L_8022F4FC:
/* 8022F4FC 0022C2FC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022F500 0022C300  80 7F 04 BC */	lwz r3, 0x4bc(r31)
/* 8022F504 0022C304  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022F508 0022C308  7C 08 03 A6 */	mtlr r0
/* 8022F50C 0022C30C  38 21 00 10 */	addi r1, r1, 0x10
/* 8022F510 0022C310  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022f4c0

# .text:0x16A0 | 0x8022F514 | size: 0x54
.fn kar_plclearcheckerlib__8022f514, global
/* 8022F514 0022C314  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022F518 0022C318  7C 08 02 A6 */	mflr r0
/* 8022F51C 0022C31C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022F520 0022C320  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022F524 0022C324  7C 7F 1B 78 */	mr r31, r3
/* 8022F528 0022C328  4B FF DD 21 */	bl kar_plclearchecker_get_player_state
/* 8022F52C 0022C32C  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022F530 0022C330  7C 7F 1B 78 */	mr r31, r3
/* 8022F534 0022C334  41 80 00 1C */	blt .L_8022F550
/* 8022F538 0022C338  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022F53C 0022C33C  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022F540 0022C340  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022F544 0022C344  38 80 03 FE */	li r4, 0x3fe
/* 8022F548 0022C348  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022F54C 0022C34C  48 1F 8F 6D */	bl __assert
.L_8022F550:
/* 8022F550 0022C350  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022F554 0022C354  80 7F 04 C0 */	lwz r3, 0x4c0(r31)
/* 8022F558 0022C358  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022F55C 0022C35C  7C 08 03 A6 */	mtlr r0
/* 8022F560 0022C360  38 21 00 10 */	addi r1, r1, 0x10
/* 8022F564 0022C364  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022f514

# .text:0x16F4 | 0x8022F568 | size: 0x54
.fn kar_plclearcheckerlib__8022f568, global
/* 8022F568 0022C368  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022F56C 0022C36C  7C 08 02 A6 */	mflr r0
/* 8022F570 0022C370  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022F574 0022C374  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022F578 0022C378  7C 7F 1B 78 */	mr r31, r3
/* 8022F57C 0022C37C  4B FF DC CD */	bl kar_plclearchecker_get_player_state
/* 8022F580 0022C380  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022F584 0022C384  7C 7F 1B 78 */	mr r31, r3
/* 8022F588 0022C388  41 80 00 1C */	blt .L_8022F5A4
/* 8022F58C 0022C38C  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022F590 0022C390  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022F594 0022C394  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022F598 0022C398  38 80 04 09 */	li r4, 0x409
/* 8022F59C 0022C39C  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022F5A0 0022C3A0  48 1F 8F 19 */	bl __assert
.L_8022F5A4:
/* 8022F5A4 0022C3A4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022F5A8 0022C3A8  80 7F 08 48 */	lwz r3, 0x848(r31)
/* 8022F5AC 0022C3AC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022F5B0 0022C3B0  7C 08 03 A6 */	mtlr r0
/* 8022F5B4 0022C3B4  38 21 00 10 */	addi r1, r1, 0x10
/* 8022F5B8 0022C3B8  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022f568

# .text:0x1748 | 0x8022F5BC | size: 0x8C
.fn kar_plclearcheckerlib__near_8022f5bc, global
/* 8022F5BC 0022C3BC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8022F5C0 0022C3C0  7C 08 02 A6 */	mflr r0
/* 8022F5C4 0022C3C4  90 01 00 24 */	stw r0, 0x24(r1)
/* 8022F5C8 0022C3C8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8022F5CC 0022C3CC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8022F5D0 0022C3D0  7C 9E 23 78 */	mr r30, r4
/* 8022F5D4 0022C3D4  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8022F5D8 0022C3D8  7C 7D 1B 78 */	mr r29, r3
/* 8022F5DC 0022C3DC  7F C3 F3 78 */	mr r3, r30
/* 8022F5E0 0022C3E0  4B F9 86 9D */	bl fn_801C7C7C
/* 8022F5E4 0022C3E4  7C 7F 1B 78 */	mr r31, r3
/* 8022F5E8 0022C3E8  7F C3 F3 78 */	mr r3, r30
/* 8022F5EC 0022C3EC  4B F9 86 9D */	bl fn_801C7C88
/* 8022F5F0 0022C3F0  2C 1F 00 00 */	cmpwi r31, 0x0
/* 8022F5F4 0022C3F4  3B E3 00 13 */	addi r31, r3, 0x13
/* 8022F5F8 0022C3F8  40 82 00 08 */	bne .L_8022F600
/* 8022F5FC 0022C3FC  7C 7F 1B 78 */	mr r31, r3
.L_8022F600:
/* 8022F600 0022C400  2C 1D 00 05 */	cmpwi r29, 0x5
/* 8022F604 0022C404  41 82 00 28 */	beq .L_8022F62C
/* 8022F608 0022C408  7F A3 EB 78 */	mr r3, r29
/* 8022F60C 0022C40C  4B FF DC 3D */	bl kar_plclearchecker_get_player_state
/* 8022F610 0022C410  7F A3 EB 78 */	mr r3, r29
/* 8022F614 0022C414  4B FF DC 35 */	bl kar_plclearchecker_get_player_state
/* 8022F618 0022C418  57 E4 10 3A */	slwi r4, r31, 2
/* 8022F61C 0022C41C  38 A4 03 7C */	addi r5, r4, 0x37c
/* 8022F620 0022C420  7C 83 28 2E */	lwzx r4, r3, r5
/* 8022F624 0022C424  38 04 00 01 */	addi r0, r4, 0x1
/* 8022F628 0022C428  7C 03 29 2E */	stwx r0, r3, r5
.L_8022F62C:
/* 8022F62C 0022C42C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8022F630 0022C430  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8022F634 0022C434  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8022F638 0022C438  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8022F63C 0022C43C  7C 08 03 A6 */	mtlr r0
/* 8022F640 0022C440  38 21 00 20 */	addi r1, r1, 0x20
/* 8022F644 0022C444  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_8022f5bc

# .text:0x17D4 | 0x8022F648 | size: 0x250
.fn kar_plclearcheckerlib__near_8022f648, global
/* 8022F648 0022C448  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8022F64C 0022C44C  7C 08 02 A6 */	mflr r0
/* 8022F650 0022C450  90 01 00 24 */	stw r0, 0x24(r1)
/* 8022F654 0022C454  39 61 00 20 */	addi r11, r1, 0x20
/* 8022F658 0022C458  48 17 E4 F9 */	bl _savegpr_26
/* 8022F65C 0022C45C  2C 05 00 00 */	cmpwi r5, 0x0
/* 8022F660 0022C460  83 44 00 1C */	lwz r26, 0x1c(r4)
/* 8022F664 0022C464  7C 9B 23 78 */	mr r27, r4
/* 8022F668 0022C468  7C 7C 1B 78 */	mr r28, r3
/* 8022F66C 0022C46C  3B C6 00 13 */	addi r30, r6, 0x13
/* 8022F670 0022C470  40 82 00 08 */	bne .L_8022F678
/* 8022F674 0022C474  7C DE 33 78 */	mr r30, r6
.L_8022F678:
/* 8022F678 0022C478  7C 1C D0 00 */	cmpw r28, r26
/* 8022F67C 0022C47C  41 82 02 04 */	beq .L_8022F880
/* 8022F680 0022C480  2C 1C 00 05 */	cmpwi r28, 0x5
/* 8022F684 0022C484  40 80 00 20 */	bge .L_8022F6A4
/* 8022F688 0022C488  7F 83 E3 78 */	mr r3, r28
/* 8022F68C 0022C48C  4B FF DB BD */	bl kar_plclearchecker_get_player_state
/* 8022F690 0022C490  57 C0 10 3A */	slwi r0, r30, 2
/* 8022F694 0022C494  7C 83 02 14 */	add r4, r3, r0
/* 8022F698 0022C498  80 64 04 4C */	lwz r3, 0x44c(r4)
/* 8022F69C 0022C49C  38 03 00 01 */	addi r0, r3, 0x1
/* 8022F6A0 0022C4A0  90 04 04 4C */	stw r0, 0x44c(r4)
.L_8022F6A4:
/* 8022F6A4 0022C4A4  2C 1A 00 05 */	cmpwi r26, 0x5
/* 8022F6A8 0022C4A8  40 80 01 D8 */	bge .L_8022F880
/* 8022F6AC 0022C4AC  7F 43 D3 78 */	mr r3, r26
/* 8022F6B0 0022C4B0  4B FF DB 99 */	bl kar_plclearchecker_get_player_state
/* 8022F6B4 0022C4B4  8B BB 00 07 */	lbz r29, 0x7(r27)
/* 8022F6B8 0022C4B8  7C 7F 1B 78 */	mr r31, r3
/* 8022F6BC 0022C4BC  7F 43 D3 78 */	mr r3, r26
/* 8022F6C0 0022C4C0  4B FF D1 F1 */	bl kar_plclearcheckerlib__near_8022c8b0
/* 8022F6C4 0022C4C4  7C 7B 1B 78 */	mr r27, r3
/* 8022F6C8 0022C4C8  7F 43 D3 78 */	mr r3, r26
/* 8022F6CC 0022C4CC  4B FF D2 15 */	bl kar_plclearcheckerlib__near_8022c8e0
/* 8022F6D0 0022C4D0  2C 1B 00 00 */	cmpwi r27, 0x0
/* 8022F6D4 0022C4D4  38 C3 00 13 */	addi r6, r3, 0x13
/* 8022F6D8 0022C4D8  40 82 00 08 */	bne .L_8022F6E0
/* 8022F6DC 0022C4DC  7C 66 1B 78 */	mr r6, r3
.L_8022F6E0:
/* 8022F6E0 0022C4E0  57 C0 10 3A */	slwi r0, r30, 2
/* 8022F6E4 0022C4E4  3C 60 80 4B */	lis r3, lbl_804B4C68@ha
/* 8022F6E8 0022C4E8  7C BF 02 14 */	add r5, r31, r0
/* 8022F6EC 0022C4EC  39 00 00 00 */	li r8, 0x0
/* 8022F6F0 0022C4F0  80 85 03 E4 */	lwz r4, 0x3e4(r5)
/* 8022F6F4 0022C4F4  38 E3 4C 68 */	addi r7, r3, lbl_804B4C68@l
/* 8022F6F8 0022C4F8  38 00 00 02 */	li r0, 0x2
/* 8022F6FC 0022C4FC  38 60 00 01 */	li r3, 0x1
/* 8022F700 0022C500  38 84 00 01 */	addi r4, r4, 0x1
/* 8022F704 0022C504  90 85 03 E4 */	stw r4, 0x3e4(r5)
/* 8022F708 0022C508  7C 09 03 A6 */	mtctr r0
.L_8022F70C:
/* 8022F70C 0022C50C  80 07 00 00 */	lwz r0, 0x0(r7)
/* 8022F710 0022C510  7C 1E 00 00 */	cmpw r30, r0
/* 8022F714 0022C514  40 82 00 24 */	bne .L_8022F738
/* 8022F718 0022C518  80 07 00 04 */	lwz r0, 0x4(r7)
/* 8022F71C 0022C51C  7C 06 00 00 */	cmpw r6, r0
/* 8022F720 0022C520  40 82 00 18 */	bne .L_8022F738
/* 8022F724 0022C524  20 08 00 0F */	subfic r0, r8, 0xf
/* 8022F728 0022C528  A0 9F 04 C4 */	lhz r4, 0x4c4(r31)
/* 8022F72C 0022C52C  7C 60 00 30 */	slw r0, r3, r0
/* 8022F730 0022C530  7C 80 03 78 */	or r0, r4, r0
/* 8022F734 0022C534  B0 1F 04 C4 */	sth r0, 0x4c4(r31)
.L_8022F738:
/* 8022F738 0022C538  84 07 00 08 */	lwzu r0, 0x8(r7)
/* 8022F73C 0022C53C  39 08 00 01 */	addi r8, r8, 0x1
/* 8022F740 0022C540  7C 1E 00 00 */	cmpw r30, r0
/* 8022F744 0022C544  40 82 00 24 */	bne .L_8022F768
/* 8022F748 0022C548  80 07 00 04 */	lwz r0, 0x4(r7)
/* 8022F74C 0022C54C  7C 06 00 00 */	cmpw r6, r0
/* 8022F750 0022C550  40 82 00 18 */	bne .L_8022F768
/* 8022F754 0022C554  20 08 00 0F */	subfic r0, r8, 0xf
/* 8022F758 0022C558  A0 9F 04 C4 */	lhz r4, 0x4c4(r31)
/* 8022F75C 0022C55C  7C 60 00 30 */	slw r0, r3, r0
/* 8022F760 0022C560  7C 80 03 78 */	or r0, r4, r0
/* 8022F764 0022C564  B0 1F 04 C4 */	sth r0, 0x4c4(r31)
.L_8022F768:
/* 8022F768 0022C568  84 07 00 08 */	lwzu r0, 0x8(r7)
/* 8022F76C 0022C56C  39 08 00 01 */	addi r8, r8, 0x1
/* 8022F770 0022C570  7C 1E 00 00 */	cmpw r30, r0
/* 8022F774 0022C574  40 82 00 24 */	bne .L_8022F798
/* 8022F778 0022C578  80 07 00 04 */	lwz r0, 0x4(r7)
/* 8022F77C 0022C57C  7C 06 00 00 */	cmpw r6, r0
/* 8022F780 0022C580  40 82 00 18 */	bne .L_8022F798
/* 8022F784 0022C584  20 08 00 0F */	subfic r0, r8, 0xf
/* 8022F788 0022C588  A0 9F 04 C4 */	lhz r4, 0x4c4(r31)
/* 8022F78C 0022C58C  7C 60 00 30 */	slw r0, r3, r0
/* 8022F790 0022C590  7C 80 03 78 */	or r0, r4, r0
/* 8022F794 0022C594  B0 1F 04 C4 */	sth r0, 0x4c4(r31)
.L_8022F798:
/* 8022F798 0022C598  84 07 00 08 */	lwzu r0, 0x8(r7)
/* 8022F79C 0022C59C  39 08 00 01 */	addi r8, r8, 0x1
/* 8022F7A0 0022C5A0  7C 1E 00 00 */	cmpw r30, r0
/* 8022F7A4 0022C5A4  40 82 00 24 */	bne .L_8022F7C8
/* 8022F7A8 0022C5A8  80 07 00 04 */	lwz r0, 0x4(r7)
/* 8022F7AC 0022C5AC  7C 06 00 00 */	cmpw r6, r0
/* 8022F7B0 0022C5B0  40 82 00 18 */	bne .L_8022F7C8
/* 8022F7B4 0022C5B4  20 08 00 0F */	subfic r0, r8, 0xf
/* 8022F7B8 0022C5B8  A0 9F 04 C4 */	lhz r4, 0x4c4(r31)
/* 8022F7BC 0022C5BC  7C 60 00 30 */	slw r0, r3, r0
/* 8022F7C0 0022C5C0  7C 80 03 78 */	or r0, r4, r0
/* 8022F7C4 0022C5C4  B0 1F 04 C4 */	sth r0, 0x4c4(r31)
.L_8022F7C8:
/* 8022F7C8 0022C5C8  84 07 00 08 */	lwzu r0, 0x8(r7)
/* 8022F7CC 0022C5CC  39 08 00 01 */	addi r8, r8, 0x1
/* 8022F7D0 0022C5D0  7C 1E 00 00 */	cmpw r30, r0
/* 8022F7D4 0022C5D4  40 82 00 24 */	bne .L_8022F7F8
/* 8022F7D8 0022C5D8  80 07 00 04 */	lwz r0, 0x4(r7)
/* 8022F7DC 0022C5DC  7C 06 00 00 */	cmpw r6, r0
/* 8022F7E0 0022C5E0  40 82 00 18 */	bne .L_8022F7F8
/* 8022F7E4 0022C5E4  20 08 00 0F */	subfic r0, r8, 0xf
/* 8022F7E8 0022C5E8  A0 9F 04 C4 */	lhz r4, 0x4c4(r31)
/* 8022F7EC 0022C5EC  7C 60 00 30 */	slw r0, r3, r0
/* 8022F7F0 0022C5F0  7C 80 03 78 */	or r0, r4, r0
/* 8022F7F4 0022C5F4  B0 1F 04 C4 */	sth r0, 0x4c4(r31)
.L_8022F7F8:
/* 8022F7F8 0022C5F8  38 E7 00 08 */	addi r7, r7, 0x8
/* 8022F7FC 0022C5FC  39 08 00 01 */	addi r8, r8, 0x1
/* 8022F800 0022C600  42 00 FF 0C */	bdnz .L_8022F70C
/* 8022F804 0022C604  2C 1C 00 05 */	cmpwi r28, 0x5
/* 8022F808 0022C608  40 80 00 78 */	bge .L_8022F880
/* 8022F80C 0022C60C  7F 83 E3 78 */	mr r3, r28
/* 8022F810 0022C610  4B FF D0 49 */	bl kar_plclearcheckerlib__near_8022c858
/* 8022F814 0022C614  2C 03 00 01 */	cmpwi r3, 0x1
/* 8022F818 0022C618  40 82 00 10 */	bne .L_8022F828
/* 8022F81C 0022C61C  80 7F 04 B4 */	lwz r3, 0x4b4(r31)
/* 8022F820 0022C620  38 03 00 01 */	addi r0, r3, 0x1
/* 8022F824 0022C624  90 1F 04 B4 */	stw r0, 0x4b4(r31)
.L_8022F828:
/* 8022F828 0022C628  2C 1C 00 04 */	cmpwi r28, 0x4
/* 8022F82C 0022C62C  40 82 00 18 */	bne .L_8022F844
/* 8022F830 0022C630  80 1F 08 48 */	lwz r0, 0x848(r31)
/* 8022F834 0022C634  28 00 00 00 */	cmplwi r0, 0x0
/* 8022F838 0022C638  40 82 00 0C */	bne .L_8022F844
/* 8022F83C 0022C63C  4B DD A3 81 */	bl fn_80009BBC
/* 8022F840 0022C640  90 7F 08 48 */	stw r3, 0x848(r31)
.L_8022F844:
/* 8022F844 0022C644  2C 1D 00 11 */	cmpwi r29, 0x11
/* 8022F848 0022C648  40 82 00 10 */	bne .L_8022F858
/* 8022F84C 0022C64C  80 7F 04 B8 */	lwz r3, 0x4b8(r31)
/* 8022F850 0022C650  38 03 00 01 */	addi r0, r3, 0x1
/* 8022F854 0022C654  90 1F 04 B8 */	stw r0, 0x4b8(r31)
.L_8022F858:
/* 8022F858 0022C658  2C 1D 00 13 */	cmpwi r29, 0x13
/* 8022F85C 0022C65C  40 82 00 10 */	bne .L_8022F86C
/* 8022F860 0022C660  80 7F 04 BC */	lwz r3, 0x4bc(r31)
/* 8022F864 0022C664  38 03 00 01 */	addi r0, r3, 0x1
/* 8022F868 0022C668  90 1F 04 BC */	stw r0, 0x4bc(r31)
.L_8022F86C:
/* 8022F86C 0022C66C  2C 1D 00 12 */	cmpwi r29, 0x12
/* 8022F870 0022C670  40 82 00 10 */	bne .L_8022F880
/* 8022F874 0022C674  80 7F 04 C0 */	lwz r3, 0x4c0(r31)
/* 8022F878 0022C678  38 03 00 01 */	addi r0, r3, 0x1
/* 8022F87C 0022C67C  90 1F 04 C0 */	stw r0, 0x4c0(r31)
.L_8022F880:
/* 8022F880 0022C680  39 61 00 20 */	addi r11, r1, 0x20
/* 8022F884 0022C684  48 17 E3 19 */	bl _restgpr_26
/* 8022F888 0022C688  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8022F88C 0022C68C  7C 08 03 A6 */	mtlr r0
/* 8022F890 0022C690  38 21 00 20 */	addi r1, r1, 0x20
/* 8022F894 0022C694  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_8022f648

# .text:0x1A24 | 0x8022F898 | size: 0x88
.fn kar_plclearcheckerlib__8022f898, global
/* 8022F898 0022C698  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8022F89C 0022C69C  7C 08 02 A6 */	mflr r0
/* 8022F8A0 0022C6A0  90 01 00 24 */	stw r0, 0x24(r1)
/* 8022F8A4 0022C6A4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8022F8A8 0022C6A8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8022F8AC 0022C6AC  7C 9E 23 78 */	mr r30, r4
/* 8022F8B0 0022C6B0  2C 1E 00 45 */	cmpwi r30, 0x45
/* 8022F8B4 0022C6B4  3C 80 80 4B */	lis r4, lbl_804B4C20@ha
/* 8022F8B8 0022C6B8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8022F8BC 0022C6BC  7C 7D 1B 78 */	mr r29, r3
/* 8022F8C0 0022C6C0  3B E4 4C 20 */	addi r31, r4, lbl_804B4C20@l
/* 8022F8C4 0022C6C4  41 80 00 14 */	blt .L_8022F8D8
/* 8022F8C8 0022C6C8  38 7F 00 BC */	addi r3, r31, 0xbc
/* 8022F8CC 0022C6CC  38 BF 01 04 */	addi r5, r31, 0x104
/* 8022F8D0 0022C6D0  38 80 04 6A */	li r4, 0x46a
/* 8022F8D4 0022C6D4  48 1F 8B E5 */	bl __assert
.L_8022F8D8:
/* 8022F8D8 0022C6D8  2C 1D 00 05 */	cmpwi r29, 0x5
/* 8022F8DC 0022C6DC  41 80 00 14 */	blt .L_8022F8F0
/* 8022F8E0 0022C6E0  38 7F 00 BC */	addi r3, r31, 0xbc
/* 8022F8E4 0022C6E4  38 BF 00 D0 */	addi r5, r31, 0xd0
/* 8022F8E8 0022C6E8  38 80 04 6B */	li r4, 0x46b
/* 8022F8EC 0022C6EC  48 1F 8B CD */	bl __assert
.L_8022F8F0:
/* 8022F8F0 0022C6F0  7F A3 EB 78 */	mr r3, r29
/* 8022F8F4 0022C6F4  4B FF D9 55 */	bl kar_plclearchecker_get_player_state
/* 8022F8F8 0022C6F8  57 C4 10 3A */	slwi r4, r30, 2
/* 8022F8FC 0022C6FC  38 04 04 C8 */	addi r0, r4, 0x4c8
/* 8022F900 0022C700  7C 63 00 2E */	lwzx r3, r3, r0
/* 8022F904 0022C704  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8022F908 0022C708  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8022F90C 0022C70C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8022F910 0022C710  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8022F914 0022C714  7C 08 03 A6 */	mtlr r0
/* 8022F918 0022C718  38 21 00 20 */	addi r1, r1, 0x20
/* 8022F91C 0022C71C  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022f898

# .text:0x1AAC | 0x8022F920 | size: 0x9C
.fn kar_plclearcheckerlib__8022f920, global
/* 8022F920 0022C720  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8022F924 0022C724  7C 08 02 A6 */	mflr r0
/* 8022F928 0022C728  90 01 00 24 */	stw r0, 0x24(r1)
/* 8022F92C 0022C72C  39 61 00 20 */	addi r11, r1, 0x20
/* 8022F930 0022C730  48 17 E2 25 */	bl _savegpr_27
/* 8022F934 0022C734  3C 80 80 4B */	lis r4, lbl_804B4C20@ha
/* 8022F938 0022C738  7C 7B 1B 78 */	mr r27, r3
/* 8022F93C 0022C73C  3B E4 4C 20 */	addi r31, r4, lbl_804B4C20@l
/* 8022F940 0022C740  3B A0 00 00 */	li r29, 0x0
/* 8022F944 0022C744  3B 80 00 03 */	li r28, 0x3
/* 8022F948 0022C748  3B C0 00 0C */	li r30, 0xc
.L_8022F94C:
/* 8022F94C 0022C74C  2C 1C 00 45 */	cmpwi r28, 0x45
/* 8022F950 0022C750  41 80 00 14 */	blt .L_8022F964
/* 8022F954 0022C754  38 7F 00 BC */	addi r3, r31, 0xbc
/* 8022F958 0022C758  38 BF 01 04 */	addi r5, r31, 0x104
/* 8022F95C 0022C75C  38 80 04 6A */	li r4, 0x46a
/* 8022F960 0022C760  48 1F 8B 59 */	bl __assert
.L_8022F964:
/* 8022F964 0022C764  2C 1B 00 05 */	cmpwi r27, 0x5
/* 8022F968 0022C768  41 80 00 14 */	blt .L_8022F97C
/* 8022F96C 0022C76C  38 7F 00 BC */	addi r3, r31, 0xbc
/* 8022F970 0022C770  38 BF 00 D0 */	addi r5, r31, 0xd0
/* 8022F974 0022C774  38 80 04 6B */	li r4, 0x46b
/* 8022F978 0022C778  48 1F 8B 41 */	bl __assert
.L_8022F97C:
/* 8022F97C 0022C77C  7F 63 DB 78 */	mr r3, r27
/* 8022F980 0022C780  4B FF D8 C9 */	bl kar_plclearchecker_get_player_state
/* 8022F984 0022C784  38 1E 04 C8 */	addi r0, r30, 0x4c8
/* 8022F988 0022C788  3B 9C 00 01 */	addi r28, r28, 0x1
/* 8022F98C 0022C78C  7C 03 00 2E */	lwzx r0, r3, r0
/* 8022F990 0022C790  2C 1C 00 44 */	cmpwi r28, 0x44
/* 8022F994 0022C794  3B DE 00 04 */	addi r30, r30, 0x4
/* 8022F998 0022C798  7F BD 02 14 */	add r29, r29, r0
/* 8022F99C 0022C79C  41 80 FF B0 */	blt .L_8022F94C
/* 8022F9A0 0022C7A0  7F A3 EB 78 */	mr r3, r29
/* 8022F9A4 0022C7A4  39 61 00 20 */	addi r11, r1, 0x20
/* 8022F9A8 0022C7A8  48 17 E1 F9 */	bl _restgpr_27
/* 8022F9AC 0022C7AC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8022F9B0 0022C7B0  7C 08 03 A6 */	mtlr r0
/* 8022F9B4 0022C7B4  38 21 00 20 */	addi r1, r1, 0x20
/* 8022F9B8 0022C7B8  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022f920

# .text:0x1B48 | 0x8022F9BC | size: 0x9C
.fn kar_plclearcheckerlib__8022f9bc, global
/* 8022F9BC 0022C7BC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8022F9C0 0022C7C0  7C 08 02 A6 */	mflr r0
/* 8022F9C4 0022C7C4  90 01 00 24 */	stw r0, 0x24(r1)
/* 8022F9C8 0022C7C8  39 61 00 20 */	addi r11, r1, 0x20
/* 8022F9CC 0022C7CC  48 17 E1 89 */	bl _savegpr_27
/* 8022F9D0 0022C7D0  3C 80 80 4B */	lis r4, lbl_804B4C20@ha
/* 8022F9D4 0022C7D4  7C 7B 1B 78 */	mr r27, r3
/* 8022F9D8 0022C7D8  3B E4 4C 20 */	addi r31, r4, lbl_804B4C20@l
/* 8022F9DC 0022C7DC  3B A0 00 00 */	li r29, 0x0
/* 8022F9E0 0022C7E0  3B 80 00 00 */	li r28, 0x0
/* 8022F9E4 0022C7E4  3B C0 00 00 */	li r30, 0x0
.L_8022F9E8:
/* 8022F9E8 0022C7E8  2C 1C 00 45 */	cmpwi r28, 0x45
/* 8022F9EC 0022C7EC  41 80 00 14 */	blt .L_8022FA00
/* 8022F9F0 0022C7F0  38 7F 00 BC */	addi r3, r31, 0xbc
/* 8022F9F4 0022C7F4  38 BF 01 04 */	addi r5, r31, 0x104
/* 8022F9F8 0022C7F8  38 80 04 6A */	li r4, 0x46a
/* 8022F9FC 0022C7FC  48 1F 8A BD */	bl __assert
.L_8022FA00:
/* 8022FA00 0022C800  2C 1B 00 05 */	cmpwi r27, 0x5
/* 8022FA04 0022C804  41 80 00 14 */	blt .L_8022FA18
/* 8022FA08 0022C808  38 7F 00 BC */	addi r3, r31, 0xbc
/* 8022FA0C 0022C80C  38 BF 00 D0 */	addi r5, r31, 0xd0
/* 8022FA10 0022C810  38 80 04 6B */	li r4, 0x46b
/* 8022FA14 0022C814  48 1F 8A A5 */	bl __assert
.L_8022FA18:
/* 8022FA18 0022C818  7F 63 DB 78 */	mr r3, r27
/* 8022FA1C 0022C81C  4B FF D8 2D */	bl kar_plclearchecker_get_player_state
/* 8022FA20 0022C820  38 1E 04 C8 */	addi r0, r30, 0x4c8
/* 8022FA24 0022C824  3B 9C 00 01 */	addi r28, r28, 0x1
/* 8022FA28 0022C828  7C 03 00 2E */	lwzx r0, r3, r0
/* 8022FA2C 0022C82C  2C 1C 00 03 */	cmpwi r28, 0x3
/* 8022FA30 0022C830  3B DE 00 04 */	addi r30, r30, 0x4
/* 8022FA34 0022C834  7F BD 02 14 */	add r29, r29, r0
/* 8022FA38 0022C838  41 80 FF B0 */	blt .L_8022F9E8
/* 8022FA3C 0022C83C  7F A3 EB 78 */	mr r3, r29
/* 8022FA40 0022C840  39 61 00 20 */	addi r11, r1, 0x20
/* 8022FA44 0022C844  48 17 E1 5D */	bl _restgpr_27
/* 8022FA48 0022C848  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8022FA4C 0022C84C  7C 08 03 A6 */	mtlr r0
/* 8022FA50 0022C850  38 21 00 20 */	addi r1, r1, 0x20
/* 8022FA54 0022C854  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022f9bc

# .text:0x1BE4 | 0x8022FA58 | size: 0x54
.fn kar_plclearcheckerlib__8022fa58, global
/* 8022FA58 0022C858  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022FA5C 0022C85C  7C 08 02 A6 */	mflr r0
/* 8022FA60 0022C860  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022FA64 0022C864  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022FA68 0022C868  7C 7F 1B 78 */	mr r31, r3
/* 8022FA6C 0022C86C  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022FA70 0022C870  41 80 00 1C */	blt .L_8022FA8C
/* 8022FA74 0022C874  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022FA78 0022C878  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022FA7C 0022C87C  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022FA80 0022C880  38 80 04 A8 */	li r4, 0x4a8
/* 8022FA84 0022C884  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022FA88 0022C888  48 1F 8A 31 */	bl __assert
.L_8022FA8C:
/* 8022FA8C 0022C88C  7F E3 FB 78 */	mr r3, r31
/* 8022FA90 0022C890  4B FF D7 B9 */	bl kar_plclearchecker_get_player_state
/* 8022FA94 0022C894  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022FA98 0022C898  80 63 08 08 */	lwz r3, 0x808(r3)
/* 8022FA9C 0022C89C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022FAA0 0022C8A0  7C 08 03 A6 */	mtlr r0
/* 8022FAA4 0022C8A4  38 21 00 10 */	addi r1, r1, 0x10
/* 8022FAA8 0022C8A8  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022fa58

# .text:0x1C38 | 0x8022FAAC | size: 0x54
.fn kar_plclearcheckerlib__8022faac, global
/* 8022FAAC 0022C8AC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022FAB0 0022C8B0  7C 08 02 A6 */	mflr r0
/* 8022FAB4 0022C8B4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022FAB8 0022C8B8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022FABC 0022C8BC  7C 7F 1B 78 */	mr r31, r3
/* 8022FAC0 0022C8C0  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022FAC4 0022C8C4  41 80 00 1C */	blt .L_8022FAE0
/* 8022FAC8 0022C8C8  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022FACC 0022C8CC  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022FAD0 0022C8D0  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022FAD4 0022C8D4  38 80 04 B1 */	li r4, 0x4b1
/* 8022FAD8 0022C8D8  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022FADC 0022C8DC  48 1F 89 DD */	bl __assert
.L_8022FAE0:
/* 8022FAE0 0022C8E0  7F E3 FB 78 */	mr r3, r31
/* 8022FAE4 0022C8E4  4B FF D7 65 */	bl kar_plclearchecker_get_player_state
/* 8022FAE8 0022C8E8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022FAEC 0022C8EC  80 63 08 04 */	lwz r3, 0x804(r3)
/* 8022FAF0 0022C8F0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022FAF4 0022C8F4  7C 08 03 A6 */	mtlr r0
/* 8022FAF8 0022C8F8  38 21 00 10 */	addi r1, r1, 0x10
/* 8022FAFC 0022C8FC  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022faac

# .text:0x1C8C | 0x8022FB00 | size: 0x58
.fn kar_plclearcheckerlib__near_8022fb00, global
/* 8022FB00 0022C900  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022FB04 0022C904  7C 08 02 A6 */	mflr r0
/* 8022FB08 0022C908  2C 03 00 05 */	cmpwi r3, 0x5
/* 8022FB0C 0022C90C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022FB10 0022C910  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022FB14 0022C914  7C 9F 23 78 */	mr r31, r4
/* 8022FB18 0022C918  40 80 00 2C */	bge .L_8022FB44
/* 8022FB1C 0022C91C  2C 1F FF FF */	cmpwi r31, -0x1
/* 8022FB20 0022C920  41 82 00 24 */	beq .L_8022FB44
/* 8022FB24 0022C924  2C 1F 00 02 */	cmpwi r31, 0x2
/* 8022FB28 0022C928  41 81 00 1C */	bgt .L_8022FB44
/* 8022FB2C 0022C92C  4B FF D7 1D */	bl kar_plclearchecker_get_player_state
/* 8022FB30 0022C930  57 E0 10 3A */	slwi r0, r31, 2
/* 8022FB34 0022C934  7C 83 02 14 */	add r4, r3, r0
/* 8022FB38 0022C938  80 64 04 C8 */	lwz r3, 0x4c8(r4)
/* 8022FB3C 0022C93C  38 03 00 01 */	addi r0, r3, 0x1
/* 8022FB40 0022C940  90 04 04 C8 */	stw r0, 0x4c8(r4)
.L_8022FB44:
/* 8022FB44 0022C944  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022FB48 0022C948  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022FB4C 0022C94C  7C 08 03 A6 */	mtlr r0
/* 8022FB50 0022C950  38 21 00 10 */	addi r1, r1, 0x10
/* 8022FB54 0022C954  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_8022fb00

# .text:0x1CE4 | 0x8022FB58 | size: 0x74
.fn kar_plclearcheckerlib__near_8022fb58, global
/* 8022FB58 0022C958  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022FB5C 0022C95C  7C 08 02 A6 */	mflr r0
/* 8022FB60 0022C960  2C 03 00 05 */	cmpwi r3, 0x5
/* 8022FB64 0022C964  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022FB68 0022C968  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022FB6C 0022C96C  7C 9F 23 78 */	mr r31, r4
/* 8022FB70 0022C970  40 80 00 48 */	bge .L_8022FBB8
/* 8022FB74 0022C974  40 80 00 44 */	bge .L_8022FBB8
/* 8022FB78 0022C978  2C 1F FF FF */	cmpwi r31, -0x1
/* 8022FB7C 0022C97C  41 82 00 3C */	beq .L_8022FBB8
/* 8022FB80 0022C980  4B FF D6 C9 */	bl kar_plclearchecker_get_player_state
/* 8022FB84 0022C984  57 E0 10 3A */	slwi r0, r31, 2
/* 8022FB88 0022C988  2C 1F 00 02 */	cmpwi r31, 0x2
/* 8022FB8C 0022C98C  7C A3 02 14 */	add r5, r3, r0
/* 8022FB90 0022C990  80 85 04 C8 */	lwz r4, 0x4c8(r5)
/* 8022FB94 0022C994  38 04 FF FF */	subi r0, r4, 0x1
/* 8022FB98 0022C998  90 05 04 C8 */	stw r0, 0x4c8(r5)
/* 8022FB9C 0022C99C  40 81 00 1C */	ble .L_8022FBB8
/* 8022FBA0 0022C9A0  80 03 06 04 */	lwz r0, 0x604(r3)
/* 8022FBA4 0022C9A4  28 00 00 00 */	cmplwi r0, 0x0
/* 8022FBA8 0022C9A8  41 82 00 10 */	beq .L_8022FBB8
/* 8022FBAC 0022C9AC  80 83 08 04 */	lwz r4, 0x804(r3)
/* 8022FBB0 0022C9B0  38 04 FF FF */	subi r0, r4, 0x1
/* 8022FBB4 0022C9B4  90 03 08 04 */	stw r0, 0x804(r3)
.L_8022FBB8:
/* 8022FBB8 0022C9B8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022FBBC 0022C9BC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022FBC0 0022C9C0  7C 08 03 A6 */	mtlr r0
/* 8022FBC4 0022C9C4  38 21 00 10 */	addi r1, r1, 0x10
/* 8022FBC8 0022C9C8  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_8022fb58

# .text:0x1D58 | 0x8022FBCC | size: 0x94
.fn kar_plclearcheckerlib__near_8022fbcc, global
/* 8022FBCC 0022C9CC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022FBD0 0022C9D0  7C 08 02 A6 */	mflr r0
/* 8022FBD4 0022C9D4  2C 03 00 05 */	cmpwi r3, 0x5
/* 8022FBD8 0022C9D8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022FBDC 0022C9DC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022FBE0 0022C9E0  7C BF 2B 78 */	mr r31, r5
/* 8022FBE4 0022C9E4  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8022FBE8 0022C9E8  7C 9E 23 78 */	mr r30, r4
/* 8022FBEC 0022C9EC  40 80 00 5C */	bge .L_8022FC48
/* 8022FBF0 0022C9F0  40 80 00 58 */	bge .L_8022FC48
/* 8022FBF4 0022C9F4  2C 1E FF FF */	cmpwi r30, -0x1
/* 8022FBF8 0022C9F8  41 82 00 50 */	beq .L_8022FC48
/* 8022FBFC 0022C9FC  4B FF D6 4D */	bl kar_plclearchecker_get_player_state
/* 8022FC00 0022CA00  57 C0 10 3A */	slwi r0, r30, 2
/* 8022FC04 0022CA04  2C 1F 00 04 */	cmpwi r31, 0x4
/* 8022FC08 0022CA08  7C A3 02 14 */	add r5, r3, r0
/* 8022FC0C 0022CA0C  80 85 04 C8 */	lwz r4, 0x4c8(r5)
/* 8022FC10 0022CA10  38 04 00 01 */	addi r0, r4, 0x1
/* 8022FC14 0022CA14  90 05 04 C8 */	stw r0, 0x4c8(r5)
/* 8022FC18 0022CA18  40 82 00 10 */	bne .L_8022FC28
/* 8022FC1C 0022CA1C  80 83 08 08 */	lwz r4, 0x808(r3)
/* 8022FC20 0022CA20  38 04 00 01 */	addi r0, r4, 0x1
/* 8022FC24 0022CA24  90 03 08 08 */	stw r0, 0x808(r3)
.L_8022FC28:
/* 8022FC28 0022CA28  2C 1E 00 02 */	cmpwi r30, 0x2
/* 8022FC2C 0022CA2C  40 81 00 1C */	ble .L_8022FC48
/* 8022FC30 0022CA30  80 03 06 04 */	lwz r0, 0x604(r3)
/* 8022FC34 0022CA34  28 00 00 00 */	cmplwi r0, 0x0
/* 8022FC38 0022CA38  41 82 00 10 */	beq .L_8022FC48
/* 8022FC3C 0022CA3C  80 83 08 04 */	lwz r4, 0x804(r3)
/* 8022FC40 0022CA40  38 04 00 01 */	addi r0, r4, 0x1
/* 8022FC44 0022CA44  90 03 08 04 */	stw r0, 0x804(r3)
.L_8022FC48:
/* 8022FC48 0022CA48  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022FC4C 0022CA4C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022FC50 0022CA50  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8022FC54 0022CA54  7C 08 03 A6 */	mtlr r0
/* 8022FC58 0022CA58  38 21 00 10 */	addi r1, r1, 0x10
/* 8022FC5C 0022CA5C  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_8022fbcc

# .text:0x1DEC | 0x8022FC60 | size: 0x6C
.fn kar_plclearcheckerlib__near_8022fc60, global
/* 8022FC60 0022CA60  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8022FC64 0022CA64  7C 08 02 A6 */	mflr r0
/* 8022FC68 0022CA68  90 01 00 34 */	stw r0, 0x34(r1)
/* 8022FC6C 0022CA6C  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 8022FC70 0022CA70  F3 E1 00 28 */	psq_st f31, 0x28(r1), 0, qr0
/* 8022FC74 0022CA74  DB C1 00 10 */	stfd f30, 0x10(r1)
/* 8022FC78 0022CA78  F3 C1 00 18 */	psq_st f30, 0x18(r1), 0, qr0
/* 8022FC7C 0022CA7C  FF C0 08 90 */	fmr f30, f1
/* 8022FC80 0022CA80  2C 03 00 05 */	cmpwi r3, 0x5
/* 8022FC84 0022CA84  FF E0 10 90 */	fmr f31, f2
/* 8022FC88 0022CA88  41 82 00 24 */	beq .L_8022FCAC
/* 8022FC8C 0022CA8C  4B FF D5 BD */	bl kar_plclearchecker_get_player_state
/* 8022FC90 0022CA90  C0 03 06 1C */	lfs f0, 0x61c(r3)
/* 8022FC94 0022CA94  EC 00 F8 2A */	fadds f0, f0, f31
/* 8022FC98 0022CA98  D0 03 06 1C */	stfs f0, 0x61c(r3)
/* 8022FC9C 0022CA9C  C0 03 06 20 */	lfs f0, 0x620(r3)
/* 8022FCA0 0022CAA0  FC 00 F0 40 */	fcmpo cr0, f0, f30
/* 8022FCA4 0022CAA4  40 80 00 08 */	bge .L_8022FCAC
/* 8022FCA8 0022CAA8  D3 C3 06 20 */	stfs f30, 0x620(r3)
.L_8022FCAC:
/* 8022FCAC 0022CAAC  E3 E1 00 28 */	psq_l f31, 0x28(r1), 0, qr0
/* 8022FCB0 0022CAB0  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 8022FCB4 0022CAB4  E3 C1 00 18 */	psq_l f30, 0x18(r1), 0, qr0
/* 8022FCB8 0022CAB8  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8022FCBC 0022CABC  CB C1 00 10 */	lfd f30, 0x10(r1)
/* 8022FCC0 0022CAC0  7C 08 03 A6 */	mtlr r0
/* 8022FCC4 0022CAC4  38 21 00 30 */	addi r1, r1, 0x30
/* 8022FCC8 0022CAC8  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_8022fc60

# .text:0x1E58 | 0x8022FCCC | size: 0x7C
.fn kar_plclearcheckerlib__8022fccc, global
/* 8022FCCC 0022CACC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022FCD0 0022CAD0  7C 08 02 A6 */	mflr r0
/* 8022FCD4 0022CAD4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022FCD8 0022CAD8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022FCDC 0022CADC  7C 9F 23 78 */	mr r31, r4
/* 8022FCE0 0022CAE0  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8022FCE4 0022CAE4  7C 7E 1B 78 */	mr r30, r3
/* 8022FCE8 0022CAE8  2C 1E 00 05 */	cmpwi r30, 0x5
/* 8022FCEC 0022CAEC  41 80 00 1C */	blt .L_8022FD08
/* 8022FCF0 0022CAF0  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022FCF4 0022CAF4  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022FCF8 0022CAF8  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022FCFC 0022CAFC  38 80 05 4A */	li r4, 0x54a
/* 8022FD00 0022CB00  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022FD04 0022CB04  48 1F 87 B5 */	bl __assert
.L_8022FD08:
/* 8022FD08 0022CB08  2C 1F 00 15 */	cmpwi r31, 0x15
/* 8022FD0C 0022CB0C  41 80 00 0C */	blt .L_8022FD18
/* 8022FD10 0022CB10  2C 1F 00 29 */	cmpwi r31, 0x29
/* 8022FD14 0022CB14  41 80 00 0C */	blt .L_8022FD20
.L_8022FD18:
/* 8022FD18 0022CB18  38 60 00 00 */	li r3, 0x0
/* 8022FD1C 0022CB1C  48 00 00 14 */	b .L_8022FD30
.L_8022FD20:
/* 8022FD20 0022CB20  7F C3 F3 78 */	mr r3, r30
/* 8022FD24 0022CB24  4B FF D5 25 */	bl kar_plclearchecker_get_player_state
/* 8022FD28 0022CB28  7C 7F 1A 14 */	add r3, r31, r3
/* 8022FD2C 0022CB2C  88 63 06 2B */	lbz r3, 0x62b(r3)
.L_8022FD30:
/* 8022FD30 0022CB30  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022FD34 0022CB34  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022FD38 0022CB38  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8022FD3C 0022CB3C  7C 08 03 A6 */	mtlr r0
/* 8022FD40 0022CB40  38 21 00 10 */	addi r1, r1, 0x10
/* 8022FD44 0022CB44  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022fccc

# .text:0x1ED4 | 0x8022FD48 | size: 0x78
.fn kar_plclearcheckerlib__8022fd48, global
/* 8022FD48 0022CB48  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022FD4C 0022CB4C  7C 08 02 A6 */	mflr r0
/* 8022FD50 0022CB50  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022FD54 0022CB54  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022FD58 0022CB58  7C 7F 1B 78 */	mr r31, r3
/* 8022FD5C 0022CB5C  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022FD60 0022CB60  41 80 00 1C */	blt .L_8022FD7C
/* 8022FD64 0022CB64  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022FD68 0022CB68  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022FD6C 0022CB6C  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022FD70 0022CB70  38 80 05 59 */	li r4, 0x559
/* 8022FD74 0022CB74  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022FD78 0022CB78  48 1F 87 41 */	bl __assert
.L_8022FD7C:
/* 8022FD7C 0022CB7C  7F E3 FB 78 */	mr r3, r31
/* 8022FD80 0022CB80  4B FF D4 C9 */	bl kar_plclearchecker_get_player_state
/* 8022FD84 0022CB84  8B E3 06 43 */	lbz r31, 0x643(r3)
/* 8022FD88 0022CB88  38 60 00 18 */	li r3, 0x18
/* 8022FD8C 0022CB8C  4B EC 80 25 */	bl kar_gryakulib_query_desert_or_city_stage_helper
/* 8022FD90 0022CB90  7C 1F 18 40 */	cmplw r31, r3
/* 8022FD94 0022CB94  40 82 00 14 */	bne .L_8022FDA8
/* 8022FD98 0022CB98  28 1F 00 00 */	cmplwi r31, 0x0
/* 8022FD9C 0022CB9C  41 82 00 0C */	beq .L_8022FDA8
/* 8022FDA0 0022CBA0  38 60 00 01 */	li r3, 0x1
/* 8022FDA4 0022CBA4  48 00 00 08 */	b .L_8022FDAC
.L_8022FDA8:
/* 8022FDA8 0022CBA8  38 60 00 00 */	li r3, 0x0
.L_8022FDAC:
/* 8022FDAC 0022CBAC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022FDB0 0022CBB0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022FDB4 0022CBB4  7C 08 03 A6 */	mtlr r0
/* 8022FDB8 0022CBB8  38 21 00 10 */	addi r1, r1, 0x10
/* 8022FDBC 0022CBBC  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022fd48

# .text:0x1F4C | 0x8022FDC0 | size: 0x68
.fn kar_plclearcheckerlib__8022fdc0, global
/* 8022FDC0 0022CBC0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022FDC4 0022CBC4  7C 08 02 A6 */	mflr r0
/* 8022FDC8 0022CBC8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022FDCC 0022CBCC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022FDD0 0022CBD0  7C 7F 1B 78 */	mr r31, r3
/* 8022FDD4 0022CBD4  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022FDD8 0022CBD8  41 80 00 1C */	blt .L_8022FDF4
/* 8022FDDC 0022CBDC  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022FDE0 0022CBE0  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022FDE4 0022CBE4  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022FDE8 0022CBE8  38 80 05 6D */	li r4, 0x56d
/* 8022FDEC 0022CBEC  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022FDF0 0022CBF0  48 1F 86 C9 */	bl __assert
.L_8022FDF4:
/* 8022FDF4 0022CBF4  7F E3 FB 78 */	mr r3, r31
/* 8022FDF8 0022CBF8  4B FF D4 51 */	bl kar_plclearchecker_get_player_state
/* 8022FDFC 0022CBFC  88 03 06 53 */	lbz r0, 0x653(r3)
/* 8022FE00 0022CC00  28 00 00 00 */	cmplwi r0, 0x0
/* 8022FE04 0022CC04  41 82 00 0C */	beq .L_8022FE10
/* 8022FE08 0022CC08  80 63 08 30 */	lwz r3, 0x830(r3)
/* 8022FE0C 0022CC0C  48 00 00 08 */	b .L_8022FE14
.L_8022FE10:
/* 8022FE10 0022CC10  38 60 FF FF */	li r3, -0x1
.L_8022FE14:
/* 8022FE14 0022CC14  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022FE18 0022CC18  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022FE1C 0022CC1C  7C 08 03 A6 */	mtlr r0
/* 8022FE20 0022CC20  38 21 00 10 */	addi r1, r1, 0x10
/* 8022FE24 0022CC24  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022fdc0

# .text:0x1FB4 | 0x8022FE28 | size: 0x58
.fn kar_plclearcheckerlib__8022fe28, global
/* 8022FE28 0022CC28  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022FE2C 0022CC2C  7C 08 02 A6 */	mflr r0
/* 8022FE30 0022CC30  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022FE34 0022CC34  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022FE38 0022CC38  7C 7F 1B 78 */	mr r31, r3
/* 8022FE3C 0022CC3C  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022FE40 0022CC40  41 80 00 1C */	blt .L_8022FE5C
/* 8022FE44 0022CC44  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022FE48 0022CC48  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022FE4C 0022CC4C  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022FE50 0022CC50  38 80 05 7D */	li r4, 0x57d
/* 8022FE54 0022CC54  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022FE58 0022CC58  48 1F 86 61 */	bl __assert
.L_8022FE5C:
/* 8022FE5C 0022CC5C  7F E3 FB 78 */	mr r3, r31
/* 8022FE60 0022CC60  4B FF D3 E9 */	bl kar_plclearchecker_get_player_state
/* 8022FE64 0022CC64  88 03 08 4D */	lbz r0, 0x84d(r3)
/* 8022FE68 0022CC68  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022FE6C 0022CC6C  54 03 DF FE */	extrwi r3, r0, 1, 26
/* 8022FE70 0022CC70  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022FE74 0022CC74  7C 08 03 A6 */	mtlr r0
/* 8022FE78 0022CC78  38 21 00 10 */	addi r1, r1, 0x10
/* 8022FE7C 0022CC7C  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022fe28

# .text:0x200C | 0x8022FE80 | size: 0x58
.fn kar_plclearcheckerlib__8022fe80, global
/* 8022FE80 0022CC80  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022FE84 0022CC84  7C 08 02 A6 */	mflr r0
/* 8022FE88 0022CC88  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022FE8C 0022CC8C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022FE90 0022CC90  7C 7F 1B 78 */	mr r31, r3
/* 8022FE94 0022CC94  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022FE98 0022CC98  41 80 00 1C */	blt .L_8022FEB4
/* 8022FE9C 0022CC9C  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8022FEA0 0022CCA0  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8022FEA4 0022CCA4  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8022FEA8 0022CCA8  38 80 05 87 */	li r4, 0x587
/* 8022FEAC 0022CCAC  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8022FEB0 0022CCB0  48 1F 86 09 */	bl __assert
.L_8022FEB4:
/* 8022FEB4 0022CCB4  7F E3 FB 78 */	mr r3, r31
/* 8022FEB8 0022CCB8  4B FF D3 91 */	bl kar_plclearchecker_get_player_state
/* 8022FEBC 0022CCBC  88 03 08 4D */	lbz r0, 0x84d(r3)
/* 8022FEC0 0022CCC0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022FEC4 0022CCC4  54 03 E7 FE */	extrwi r3, r0, 1, 27
/* 8022FEC8 0022CCC8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022FECC 0022CCCC  7C 08 03 A6 */	mtlr r0
/* 8022FED0 0022CCD0  38 21 00 10 */	addi r1, r1, 0x10
/* 8022FED4 0022CCD4  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8022fe80

# .text:0x2064 | 0x8022FED8 | size: 0xD0
.fn kar_plclearcheckerlib__near_8022fed8, global
/* 8022FED8 0022CCD8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8022FEDC 0022CCDC  7C 08 02 A6 */	mflr r0
/* 8022FEE0 0022CCE0  90 01 00 24 */	stw r0, 0x24(r1)
/* 8022FEE4 0022CCE4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8022FEE8 0022CCE8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8022FEEC 0022CCEC  7C 9E 23 78 */	mr r30, r4
/* 8022FEF0 0022CCF0  2C 1E 00 15 */	cmpwi r30, 0x15
/* 8022FEF4 0022CCF4  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8022FEF8 0022CCF8  7C 7D 1B 78 */	mr r29, r3
/* 8022FEFC 0022CCFC  41 80 00 90 */	blt .L_8022FF8C
/* 8022FF00 0022CD00  2C 1E 00 29 */	cmpwi r30, 0x29
/* 8022FF04 0022CD04  41 80 00 08 */	blt .L_8022FF0C
/* 8022FF08 0022CD08  48 00 00 84 */	b .L_8022FF8C
.L_8022FF0C:
/* 8022FF0C 0022CD0C  2C 1D 00 05 */	cmpwi r29, 0x5
/* 8022FF10 0022CD10  41 82 00 7C */	beq .L_8022FF8C
/* 8022FF14 0022CD14  4B FF D3 35 */	bl kar_plclearchecker_get_player_state
/* 8022FF18 0022CD18  88 03 08 55 */	lbz r0, 0x855(r3)
/* 8022FF1C 0022CD1C  7C 7F 1B 78 */	mr r31, r3
/* 8022FF20 0022CD20  54 00 D7 FF */	extrwi. r0, r0, 1, 25
/* 8022FF24 0022CD24  40 82 00 68 */	bne .L_8022FF8C
/* 8022FF28 0022CD28  7C 9F F2 14 */	add r4, r31, r30
/* 8022FF2C 0022CD2C  88 64 06 2B */	lbz r3, 0x62b(r4)
/* 8022FF30 0022CD30  38 03 00 01 */	addi r0, r3, 0x1
/* 8022FF34 0022CD34  98 04 06 2B */	stb r0, 0x62b(r4)
/* 8022FF38 0022CD38  4B DD AF 71 */	bl kar_gmracenormal__8000aea8
/* 8022FF3C 0022CD3C  7C 60 07 74 */	extsb r0, r3
/* 8022FF40 0022CD40  2C 00 00 06 */	cmpwi r0, 0x6
/* 8022FF44 0022CD44  40 82 00 48 */	bne .L_8022FF8C
/* 8022FF48 0022CD48  7F A3 EB 78 */	mr r3, r29
/* 8022FF4C 0022CD4C  7F C4 F3 78 */	mr r4, r30
/* 8022FF50 0022CD50  48 04 A7 51 */	bl fn_8027A6A0
/* 8022FF54 0022CD54  2C 1E 00 28 */	cmpwi r30, 0x28
/* 8022FF58 0022CD58  40 82 00 34 */	bne .L_8022FF8C
/* 8022FF5C 0022CD5C  4B EB E9 69 */	bl kar_greventgenerator_get_active_event_kind
/* 8022FF60 0022CD60  2C 03 00 03 */	cmpwi r3, 0x3
/* 8022FF64 0022CD64  40 82 00 28 */	bne .L_8022FF8C
/* 8022FF68 0022CD68  4B EB E9 A9 */	bl kar_greventgenerator_get_active_elapsed_frames
/* 8022FF6C 0022CD6C  80 1F 08 30 */	lwz r0, 0x830(r31)
/* 8022FF70 0022CD70  28 00 00 00 */	cmplwi r0, 0x0
/* 8022FF74 0022CD74  41 82 00 0C */	beq .L_8022FF80
/* 8022FF78 0022CD78  7C 00 18 40 */	cmplw r0, r3
/* 8022FF7C 0022CD7C  40 81 00 08 */	ble .L_8022FF84
.L_8022FF80:
/* 8022FF80 0022CD80  90 7F 08 30 */	stw r3, 0x830(r31)
.L_8022FF84:
/* 8022FF84 0022CD84  7F A3 EB 78 */	mr r3, r29
/* 8022FF88 0022CD88  4B FF D9 05 */	bl kar_plclearcheckerlib__near_8022d88c
.L_8022FF8C:
/* 8022FF8C 0022CD8C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8022FF90 0022CD90  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8022FF94 0022CD94  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8022FF98 0022CD98  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8022FF9C 0022CD9C  7C 08 03 A6 */	mtlr r0
/* 8022FFA0 0022CDA0  38 21 00 20 */	addi r1, r1, 0x20
/* 8022FFA4 0022CDA4  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_8022fed8

# .text:0x2134 | 0x8022FFA8 | size: 0x4C
.fn kar_plclearcheckerlib__near_8022ffa8, global
/* 8022FFA8 0022CDA8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022FFAC 0022CDAC  7C 08 02 A6 */	mflr r0
/* 8022FFB0 0022CDB0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8022FFB4 0022CDB4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8022FFB8 0022CDB8  7C 7F 1B 78 */	mr r31, r3
/* 8022FFBC 0022CDBC  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8022FFC0 0022CDC0  41 82 00 20 */	beq .L_8022FFE0
/* 8022FFC4 0022CDC4  4B FF D2 85 */	bl kar_plclearchecker_get_player_state
/* 8022FFC8 0022CDC8  88 03 08 4D */	lbz r0, 0x84d(r3)
/* 8022FFCC 0022CDCC  38 80 00 01 */	li r4, 0x1
/* 8022FFD0 0022CDD0  50 80 2E B4 */	rlwimi r0, r4, 5, 26, 26
/* 8022FFD4 0022CDD4  98 03 08 4D */	stb r0, 0x84d(r3)
/* 8022FFD8 0022CDD8  7F E3 FB 78 */	mr r3, r31
/* 8022FFDC 0022CDDC  48 04 A9 65 */	bl fn_8027A940
.L_8022FFE0:
/* 8022FFE0 0022CDE0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8022FFE4 0022CDE4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8022FFE8 0022CDE8  7C 08 03 A6 */	mtlr r0
/* 8022FFEC 0022CDEC  38 21 00 10 */	addi r1, r1, 0x10
/* 8022FFF0 0022CDF0  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_8022ffa8

# .text:0x2180 | 0x8022FFF4 | size: 0x38
.fn kar_plclearcheckerlib__near_8022fff4, global
/* 8022FFF4 0022CDF4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8022FFF8 0022CDF8  7C 08 02 A6 */	mflr r0
/* 8022FFFC 0022CDFC  2C 03 00 05 */	cmpwi r3, 0x5
/* 80230000 0022CE00  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230004 0022CE04  41 82 00 18 */	beq .L_8023001C
/* 80230008 0022CE08  4B FF D2 41 */	bl kar_plclearchecker_get_player_state
/* 8023000C 0022CE0C  88 03 08 4D */	lbz r0, 0x84d(r3)
/* 80230010 0022CE10  38 80 00 01 */	li r4, 0x1
/* 80230014 0022CE14  50 80 26 F6 */	rlwimi r0, r4, 4, 27, 27
/* 80230018 0022CE18  98 03 08 4D */	stb r0, 0x84d(r3)
.L_8023001C:
/* 8023001C 0022CE1C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230020 0022CE20  7C 08 03 A6 */	mtlr r0
/* 80230024 0022CE24  38 21 00 10 */	addi r1, r1, 0x10
/* 80230028 0022CE28  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_8022fff4

# .text:0x21B8 | 0x8023002C | size: 0x88
.fn kar_plclearcheckerlib__8023002c, global
/* 8023002C 0022CE2C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230030 0022CE30  7C 08 02 A6 */	mflr r0
/* 80230034 0022CE34  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230038 0022CE38  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023003C 0022CE3C  7C 9F 23 78 */	mr r31, r4
/* 80230040 0022CE40  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80230044 0022CE44  7C 7E 1B 78 */	mr r30, r3
/* 80230048 0022CE48  2C 1E 00 05 */	cmpwi r30, 0x5
/* 8023004C 0022CE4C  41 80 00 1C */	blt .L_80230068
/* 80230050 0022CE50  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80230054 0022CE54  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 80230058 0022CE58  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8023005C 0022CE5C  38 80 05 D4 */	li r4, 0x5d4
/* 80230060 0022CE60  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80230064 0022CE64  48 1F 84 55 */	bl __assert
.L_80230068:
/* 80230068 0022CE68  7F C3 F3 78 */	mr r3, r30
/* 8023006C 0022CE6C  4B FF D1 DD */	bl kar_plclearchecker_get_player_state
/* 80230070 0022CE70  7F E4 1E 70 */	srawi r4, r31, 3
/* 80230074 0022CE74  57 E0 E8 04 */	slwi r0, r31, 29
/* 80230078 0022CE78  7C A4 01 94 */	addze r5, r4
/* 8023007C 0022CE7C  57 E4 0F FE */	srwi r4, r31, 31
/* 80230080 0022CE80  7C 63 2A 14 */	add r3, r3, r5
/* 80230084 0022CE84  7C 04 00 50 */	subf r0, r4, r0
/* 80230088 0022CE88  88 63 06 54 */	lbz r3, 0x654(r3)
/* 8023008C 0022CE8C  54 00 18 3E */	rotlwi r0, r0, 3
/* 80230090 0022CE90  7C 00 22 14 */	add r0, r0, r4
/* 80230094 0022CE94  7C 60 06 30 */	sraw r0, r3, r0
/* 80230098 0022CE98  54 03 07 FE */	clrlwi r3, r0, 31
/* 8023009C 0022CE9C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802300A0 0022CEA0  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 802300A4 0022CEA4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802300A8 0022CEA8  7C 08 03 A6 */	mtlr r0
/* 802300AC 0022CEAC  38 21 00 10 */	addi r1, r1, 0x10
/* 802300B0 0022CEB0  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8023002c

# .text:0x2240 | 0x802300B4 | size: 0x18C
.fn kar_plclearcheckerlib__802300b4, global
/* 802300B4 0022CEB4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802300B8 0022CEB8  7C 08 02 A6 */	mflr r0
/* 802300BC 0022CEBC  90 01 00 14 */	stw r0, 0x14(r1)
/* 802300C0 0022CEC0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802300C4 0022CEC4  7C 7F 1B 78 */	mr r31, r3
/* 802300C8 0022CEC8  2C 1F 00 05 */	cmpwi r31, 0x5
/* 802300CC 0022CECC  93 C1 00 08 */	stw r30, 0x8(r1)
/* 802300D0 0022CED0  3B C0 00 01 */	li r30, 0x1
/* 802300D4 0022CED4  41 80 00 1C */	blt .L_802300F0
/* 802300D8 0022CED8  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 802300DC 0022CEDC  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 802300E0 0022CEE0  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 802300E4 0022CEE4  38 80 05 D4 */	li r4, 0x5d4
/* 802300E8 0022CEE8  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 802300EC 0022CEEC  48 1F 83 CD */	bl __assert
.L_802300F0:
/* 802300F0 0022CEF0  7F E3 FB 78 */	mr r3, r31
/* 802300F4 0022CEF4  4B FF D1 55 */	bl kar_plclearchecker_get_player_state
/* 802300F8 0022CEF8  3B E3 06 54 */	addi r31, r3, 0x654
/* 802300FC 0022CEFC  4B EA 56 7D */	bl kar_grlib2__near_800d5778
/* 80230100 0022CF00  38 00 00 0D */	li r0, 0xd
/* 80230104 0022CF04  38 80 00 01 */	li r4, 0x1
/* 80230108 0022CF08  7C 09 03 A6 */	mtctr r0
.L_8023010C:
/* 8023010C 0022CF0C  88 A3 00 00 */	lbz r5, 0x0(r3)
/* 80230110 0022CF10  28 05 00 00 */	cmplwi r5, 0x0
/* 80230114 0022CF14  41 82 01 04 */	beq .L_80230218
/* 80230118 0022CF18  38 00 00 00 */	li r0, 0x0
/* 8023011C 0022CF1C  7C 86 00 30 */	slw r6, r4, r0
/* 80230120 0022CF20  7C A0 30 39 */	and. r0, r5, r6
/* 80230124 0022CF24  41 82 00 14 */	beq .L_80230138
/* 80230128 0022CF28  88 1F 00 00 */	lbz r0, 0x0(r31)
/* 8023012C 0022CF2C  7C 00 30 39 */	and. r0, r0, r6
/* 80230130 0022CF30  40 82 00 08 */	bne .L_80230138
/* 80230134 0022CF34  3B C0 00 00 */	li r30, 0x0
.L_80230138:
/* 80230138 0022CF38  38 00 00 01 */	li r0, 0x1
/* 8023013C 0022CF3C  7C 86 00 30 */	slw r6, r4, r0
/* 80230140 0022CF40  7C A0 30 39 */	and. r0, r5, r6
/* 80230144 0022CF44  41 82 00 14 */	beq .L_80230158
/* 80230148 0022CF48  88 1F 00 00 */	lbz r0, 0x0(r31)
/* 8023014C 0022CF4C  7C 00 30 39 */	and. r0, r0, r6
/* 80230150 0022CF50  40 82 00 08 */	bne .L_80230158
/* 80230154 0022CF54  3B C0 00 00 */	li r30, 0x0
.L_80230158:
/* 80230158 0022CF58  38 00 00 02 */	li r0, 0x2
/* 8023015C 0022CF5C  7C 86 00 30 */	slw r6, r4, r0
/* 80230160 0022CF60  7C A0 30 39 */	and. r0, r5, r6
/* 80230164 0022CF64  41 82 00 14 */	beq .L_80230178
/* 80230168 0022CF68  88 1F 00 00 */	lbz r0, 0x0(r31)
/* 8023016C 0022CF6C  7C 00 30 39 */	and. r0, r0, r6
/* 80230170 0022CF70  40 82 00 08 */	bne .L_80230178
/* 80230174 0022CF74  3B C0 00 00 */	li r30, 0x0
.L_80230178:
/* 80230178 0022CF78  38 00 00 03 */	li r0, 0x3
/* 8023017C 0022CF7C  7C 86 00 30 */	slw r6, r4, r0
/* 80230180 0022CF80  7C A0 30 39 */	and. r0, r5, r6
/* 80230184 0022CF84  41 82 00 14 */	beq .L_80230198
/* 80230188 0022CF88  88 1F 00 00 */	lbz r0, 0x0(r31)
/* 8023018C 0022CF8C  7C 00 30 39 */	and. r0, r0, r6
/* 80230190 0022CF90  40 82 00 08 */	bne .L_80230198
/* 80230194 0022CF94  3B C0 00 00 */	li r30, 0x0
.L_80230198:
/* 80230198 0022CF98  38 00 00 04 */	li r0, 0x4
/* 8023019C 0022CF9C  7C 86 00 30 */	slw r6, r4, r0
/* 802301A0 0022CFA0  7C A0 30 39 */	and. r0, r5, r6
/* 802301A4 0022CFA4  41 82 00 14 */	beq .L_802301B8
/* 802301A8 0022CFA8  88 1F 00 00 */	lbz r0, 0x0(r31)
/* 802301AC 0022CFAC  7C 00 30 39 */	and. r0, r0, r6
/* 802301B0 0022CFB0  40 82 00 08 */	bne .L_802301B8
/* 802301B4 0022CFB4  3B C0 00 00 */	li r30, 0x0
.L_802301B8:
/* 802301B8 0022CFB8  38 00 00 05 */	li r0, 0x5
/* 802301BC 0022CFBC  7C 86 00 30 */	slw r6, r4, r0
/* 802301C0 0022CFC0  7C A0 30 39 */	and. r0, r5, r6
/* 802301C4 0022CFC4  41 82 00 14 */	beq .L_802301D8
/* 802301C8 0022CFC8  88 1F 00 00 */	lbz r0, 0x0(r31)
/* 802301CC 0022CFCC  7C 00 30 39 */	and. r0, r0, r6
/* 802301D0 0022CFD0  40 82 00 08 */	bne .L_802301D8
/* 802301D4 0022CFD4  3B C0 00 00 */	li r30, 0x0
.L_802301D8:
/* 802301D8 0022CFD8  38 00 00 06 */	li r0, 0x6
/* 802301DC 0022CFDC  7C 86 00 30 */	slw r6, r4, r0
/* 802301E0 0022CFE0  7C A0 30 39 */	and. r0, r5, r6
/* 802301E4 0022CFE4  41 82 00 14 */	beq .L_802301F8
/* 802301E8 0022CFE8  88 1F 00 00 */	lbz r0, 0x0(r31)
/* 802301EC 0022CFEC  7C 00 30 39 */	and. r0, r0, r6
/* 802301F0 0022CFF0  40 82 00 08 */	bne .L_802301F8
/* 802301F4 0022CFF4  3B C0 00 00 */	li r30, 0x0
.L_802301F8:
/* 802301F8 0022CFF8  38 00 00 07 */	li r0, 0x7
/* 802301FC 0022CFFC  7C 86 00 30 */	slw r6, r4, r0
/* 80230200 0022D000  7C A0 30 39 */	and. r0, r5, r6
/* 80230204 0022D004  41 82 00 14 */	beq .L_80230218
/* 80230208 0022D008  88 1F 00 00 */	lbz r0, 0x0(r31)
/* 8023020C 0022D00C  7C 00 30 39 */	and. r0, r0, r6
/* 80230210 0022D010  40 82 00 08 */	bne .L_80230218
/* 80230214 0022D014  3B C0 00 00 */	li r30, 0x0
.L_80230218:
/* 80230218 0022D018  38 63 00 01 */	addi r3, r3, 0x1
/* 8023021C 0022D01C  3B FF 00 01 */	addi r31, r31, 0x1
/* 80230220 0022D020  42 00 FE EC */	bdnz .L_8023010C
/* 80230224 0022D024  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230228 0022D028  7F C3 F3 78 */	mr r3, r30
/* 8023022C 0022D02C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80230230 0022D030  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80230234 0022D034  7C 08 03 A6 */	mtlr r0
/* 80230238 0022D038  38 21 00 10 */	addi r1, r1, 0x10
/* 8023023C 0022D03C  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__802300b4

# .text:0x23CC | 0x80230240 | size: 0x54
.fn kar_plclearcheckerlib__80230240, global
/* 80230240 0022D040  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230244 0022D044  7C 08 02 A6 */	mflr r0
/* 80230248 0022D048  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023024C 0022D04C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80230250 0022D050  7C 7F 1B 78 */	mr r31, r3
/* 80230254 0022D054  2C 1F 00 05 */	cmpwi r31, 0x5
/* 80230258 0022D058  41 80 00 1C */	blt .L_80230274
/* 8023025C 0022D05C  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80230260 0022D060  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 80230264 0022D064  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 80230268 0022D068  38 80 06 15 */	li r4, 0x615
/* 8023026C 0022D06C  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80230270 0022D070  48 1F 82 49 */	bl __assert
.L_80230274:
/* 80230274 0022D074  7F E3 FB 78 */	mr r3, r31
/* 80230278 0022D078  4B FF CF D1 */	bl kar_plclearchecker_get_player_state
/* 8023027C 0022D07C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230280 0022D080  80 63 08 50 */	lwz r3, 0x850(r3)
/* 80230284 0022D084  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80230288 0022D088  7C 08 03 A6 */	mtlr r0
/* 8023028C 0022D08C  38 21 00 10 */	addi r1, r1, 0x10
/* 80230290 0022D090  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__80230240

# .text:0x2420 | 0x80230294 | size: 0x18C
.fn kar_plclearcheckerlib__80230294, global
/* 80230294 0022D094  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230298 0022D098  7C 08 02 A6 */	mflr r0
/* 8023029C 0022D09C  90 01 00 14 */	stw r0, 0x14(r1)
/* 802302A0 0022D0A0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802302A4 0022D0A4  7C 7F 1B 78 */	mr r31, r3
/* 802302A8 0022D0A8  2C 1F 00 05 */	cmpwi r31, 0x5
/* 802302AC 0022D0AC  93 C1 00 08 */	stw r30, 0x8(r1)
/* 802302B0 0022D0B0  3B C0 00 01 */	li r30, 0x1
/* 802302B4 0022D0B4  41 80 00 1C */	blt .L_802302D0
/* 802302B8 0022D0B8  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 802302BC 0022D0BC  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 802302C0 0022D0C0  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 802302C4 0022D0C4  38 80 05 E0 */	li r4, 0x5e0
/* 802302C8 0022D0C8  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 802302CC 0022D0CC  48 1F 81 ED */	bl __assert
.L_802302D0:
/* 802302D0 0022D0D0  7F E3 FB 78 */	mr r3, r31
/* 802302D4 0022D0D4  4B FF CF 75 */	bl kar_plclearchecker_get_player_state
/* 802302D8 0022D0D8  3B E3 06 61 */	addi r31, r3, 0x661
/* 802302DC 0022D0DC  4B EA 54 65 */	bl kar_grlib2__near_800d5740
/* 802302E0 0022D0E0  38 00 00 3F */	li r0, 0x3f
/* 802302E4 0022D0E4  38 80 00 01 */	li r4, 0x1
/* 802302E8 0022D0E8  7C 09 03 A6 */	mtctr r0
.L_802302EC:
/* 802302EC 0022D0EC  88 A3 00 00 */	lbz r5, 0x0(r3)
/* 802302F0 0022D0F0  28 05 00 00 */	cmplwi r5, 0x0
/* 802302F4 0022D0F4  41 82 01 04 */	beq .L_802303F8
/* 802302F8 0022D0F8  38 00 00 00 */	li r0, 0x0
/* 802302FC 0022D0FC  7C 86 00 30 */	slw r6, r4, r0
/* 80230300 0022D100  7C A0 30 39 */	and. r0, r5, r6
/* 80230304 0022D104  41 82 00 14 */	beq .L_80230318
/* 80230308 0022D108  88 1F 00 00 */	lbz r0, 0x0(r31)
/* 8023030C 0022D10C  7C 00 30 39 */	and. r0, r0, r6
/* 80230310 0022D110  40 82 00 08 */	bne .L_80230318
/* 80230314 0022D114  3B C0 00 00 */	li r30, 0x0
.L_80230318:
/* 80230318 0022D118  38 00 00 01 */	li r0, 0x1
/* 8023031C 0022D11C  7C 86 00 30 */	slw r6, r4, r0
/* 80230320 0022D120  7C A0 30 39 */	and. r0, r5, r6
/* 80230324 0022D124  41 82 00 14 */	beq .L_80230338
/* 80230328 0022D128  88 1F 00 00 */	lbz r0, 0x0(r31)
/* 8023032C 0022D12C  7C 00 30 39 */	and. r0, r0, r6
/* 80230330 0022D130  40 82 00 08 */	bne .L_80230338
/* 80230334 0022D134  3B C0 00 00 */	li r30, 0x0
.L_80230338:
/* 80230338 0022D138  38 00 00 02 */	li r0, 0x2
/* 8023033C 0022D13C  7C 86 00 30 */	slw r6, r4, r0
/* 80230340 0022D140  7C A0 30 39 */	and. r0, r5, r6
/* 80230344 0022D144  41 82 00 14 */	beq .L_80230358
/* 80230348 0022D148  88 1F 00 00 */	lbz r0, 0x0(r31)
/* 8023034C 0022D14C  7C 00 30 39 */	and. r0, r0, r6
/* 80230350 0022D150  40 82 00 08 */	bne .L_80230358
/* 80230354 0022D154  3B C0 00 00 */	li r30, 0x0
.L_80230358:
/* 80230358 0022D158  38 00 00 03 */	li r0, 0x3
/* 8023035C 0022D15C  7C 86 00 30 */	slw r6, r4, r0
/* 80230360 0022D160  7C A0 30 39 */	and. r0, r5, r6
/* 80230364 0022D164  41 82 00 14 */	beq .L_80230378
/* 80230368 0022D168  88 1F 00 00 */	lbz r0, 0x0(r31)
/* 8023036C 0022D16C  7C 00 30 39 */	and. r0, r0, r6
/* 80230370 0022D170  40 82 00 08 */	bne .L_80230378
/* 80230374 0022D174  3B C0 00 00 */	li r30, 0x0
.L_80230378:
/* 80230378 0022D178  38 00 00 04 */	li r0, 0x4
/* 8023037C 0022D17C  7C 86 00 30 */	slw r6, r4, r0
/* 80230380 0022D180  7C A0 30 39 */	and. r0, r5, r6
/* 80230384 0022D184  41 82 00 14 */	beq .L_80230398
/* 80230388 0022D188  88 1F 00 00 */	lbz r0, 0x0(r31)
/* 8023038C 0022D18C  7C 00 30 39 */	and. r0, r0, r6
/* 80230390 0022D190  40 82 00 08 */	bne .L_80230398
/* 80230394 0022D194  3B C0 00 00 */	li r30, 0x0
.L_80230398:
/* 80230398 0022D198  38 00 00 05 */	li r0, 0x5
/* 8023039C 0022D19C  7C 86 00 30 */	slw r6, r4, r0
/* 802303A0 0022D1A0  7C A0 30 39 */	and. r0, r5, r6
/* 802303A4 0022D1A4  41 82 00 14 */	beq .L_802303B8
/* 802303A8 0022D1A8  88 1F 00 00 */	lbz r0, 0x0(r31)
/* 802303AC 0022D1AC  7C 00 30 39 */	and. r0, r0, r6
/* 802303B0 0022D1B0  40 82 00 08 */	bne .L_802303B8
/* 802303B4 0022D1B4  3B C0 00 00 */	li r30, 0x0
.L_802303B8:
/* 802303B8 0022D1B8  38 00 00 06 */	li r0, 0x6
/* 802303BC 0022D1BC  7C 86 00 30 */	slw r6, r4, r0
/* 802303C0 0022D1C0  7C A0 30 39 */	and. r0, r5, r6
/* 802303C4 0022D1C4  41 82 00 14 */	beq .L_802303D8
/* 802303C8 0022D1C8  88 1F 00 00 */	lbz r0, 0x0(r31)
/* 802303CC 0022D1CC  7C 00 30 39 */	and. r0, r0, r6
/* 802303D0 0022D1D0  40 82 00 08 */	bne .L_802303D8
/* 802303D4 0022D1D4  3B C0 00 00 */	li r30, 0x0
.L_802303D8:
/* 802303D8 0022D1D8  38 00 00 07 */	li r0, 0x7
/* 802303DC 0022D1DC  7C 86 00 30 */	slw r6, r4, r0
/* 802303E0 0022D1E0  7C A0 30 39 */	and. r0, r5, r6
/* 802303E4 0022D1E4  41 82 00 14 */	beq .L_802303F8
/* 802303E8 0022D1E8  88 1F 00 00 */	lbz r0, 0x0(r31)
/* 802303EC 0022D1EC  7C 00 30 39 */	and. r0, r0, r6
/* 802303F0 0022D1F0  40 82 00 08 */	bne .L_802303F8
/* 802303F4 0022D1F4  3B C0 00 00 */	li r30, 0x0
.L_802303F8:
/* 802303F8 0022D1F8  38 63 00 01 */	addi r3, r3, 0x1
/* 802303FC 0022D1FC  3B FF 00 01 */	addi r31, r31, 0x1
/* 80230400 0022D200  42 00 FE EC */	bdnz .L_802302EC
/* 80230404 0022D204  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230408 0022D208  7F C3 F3 78 */	mr r3, r30
/* 8023040C 0022D20C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80230410 0022D210  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80230414 0022D214  7C 08 03 A6 */	mtlr r0
/* 80230418 0022D218  38 21 00 10 */	addi r1, r1, 0x10
/* 8023041C 0022D21C  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__80230294

# .text:0x25AC | 0x80230420 | size: 0x54
.fn kar_plclearcheckerlib__80230420, global
/* 80230420 0022D220  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230424 0022D224  7C 08 02 A6 */	mflr r0
/* 80230428 0022D228  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023042C 0022D22C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80230430 0022D230  7C 7F 1B 78 */	mr r31, r3
/* 80230434 0022D234  2C 1F 00 05 */	cmpwi r31, 0x5
/* 80230438 0022D238  41 80 00 1C */	blt .L_80230454
/* 8023043C 0022D23C  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80230440 0022D240  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 80230444 0022D244  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 80230448 0022D248  38 80 06 3B */	li r4, 0x63b
/* 8023044C 0022D24C  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80230450 0022D250  48 1F 80 69 */	bl __assert
.L_80230454:
/* 80230454 0022D254  7F E3 FB 78 */	mr r3, r31
/* 80230458 0022D258  4B FF CD F1 */	bl kar_plclearchecker_get_player_state
/* 8023045C 0022D25C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230460 0022D260  80 63 08 34 */	lwz r3, 0x834(r3)
/* 80230464 0022D264  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80230468 0022D268  7C 08 03 A6 */	mtlr r0
/* 8023046C 0022D26C  38 21 00 10 */	addi r1, r1, 0x10
/* 80230470 0022D270  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__80230420

# .text:0x2600 | 0x80230474 | size: 0x54
.fn kar_plclearcheckerlib__80230474, global
/* 80230474 0022D274  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230478 0022D278  7C 08 02 A6 */	mflr r0
/* 8023047C 0022D27C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230480 0022D280  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80230484 0022D284  7C 7F 1B 78 */	mr r31, r3
/* 80230488 0022D288  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8023048C 0022D28C  41 80 00 1C */	blt .L_802304A8
/* 80230490 0022D290  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80230494 0022D294  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 80230498 0022D298  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8023049C 0022D29C  38 80 06 45 */	li r4, 0x645
/* 802304A0 0022D2A0  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 802304A4 0022D2A4  48 1F 80 15 */	bl __assert
.L_802304A8:
/* 802304A8 0022D2A8  7F E3 FB 78 */	mr r3, r31
/* 802304AC 0022D2AC  4B FF CD 9D */	bl kar_plclearchecker_get_player_state
/* 802304B0 0022D2B0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802304B4 0022D2B4  80 63 08 38 */	lwz r3, 0x838(r3)
/* 802304B8 0022D2B8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802304BC 0022D2BC  7C 08 03 A6 */	mtlr r0
/* 802304C0 0022D2C0  38 21 00 10 */	addi r1, r1, 0x10
/* 802304C4 0022D2C4  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__80230474

# .text:0x2654 | 0x802304C8 | size: 0xE8
.fn kar_plclearcheckerlib__near_802304c8, global
/* 802304C8 0022D2C8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 802304CC 0022D2CC  7C 08 02 A6 */	mflr r0
/* 802304D0 0022D2D0  90 01 00 24 */	stw r0, 0x24(r1)
/* 802304D4 0022D2D4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 802304D8 0022D2D8  7C 7F 1B 78 */	mr r31, r3
/* 802304DC 0022D2DC  2C 1F 00 05 */	cmpwi r31, 0x5
/* 802304E0 0022D2E0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 802304E4 0022D2E4  93 A1 00 14 */	stw r29, 0x14(r1)
/* 802304E8 0022D2E8  93 81 00 10 */	stw r28, 0x10(r1)
/* 802304EC 0022D2EC  7C 9C 23 78 */	mr r28, r4
/* 802304F0 0022D2F0  41 82 00 A0 */	beq .L_80230590
/* 802304F4 0022D2F4  4B DD 8D E5 */	bl fn_800092D8
/* 802304F8 0022D2F8  7C 63 07 74 */	extsb r3, r3
/* 802304FC 0022D2FC  48 03 17 ED */	bl fn_80261CE8
/* 80230500 0022D300  7C 7D 1B 78 */	mr r29, r3
/* 80230504 0022D304  7F E3 FB 78 */	mr r3, r31
/* 80230508 0022D308  4B FF CD 41 */	bl kar_plclearchecker_get_player_state
/* 8023050C 0022D30C  7F 85 1E 70 */	srawi r5, r28, 3
/* 80230510 0022D310  57 80 E8 04 */	slwi r0, r28, 29
/* 80230514 0022D314  57 84 0F FE */	srwi r4, r28, 31
/* 80230518 0022D318  7C 7E 1B 78 */	mr r30, r3
/* 8023051C 0022D31C  7F 85 01 94 */	addze r28, r5
/* 80230520 0022D320  38 60 00 01 */	li r3, 0x1
/* 80230524 0022D324  7C 04 00 50 */	subf r0, r4, r0
/* 80230528 0022D328  2C 1D 00 09 */	cmpwi r29, 0x9
/* 8023052C 0022D32C  7C DE E2 14 */	add r6, r30, r28
/* 80230530 0022D330  54 00 18 3E */	rotlwi r0, r0, 3
/* 80230534 0022D334  88 A6 06 54 */	lbz r5, 0x654(r6)
/* 80230538 0022D338  7F A0 22 14 */	add r29, r0, r4
/* 8023053C 0022D33C  7C 60 E8 30 */	slw r0, r3, r29
/* 80230540 0022D340  7C A0 03 78 */	or r0, r5, r0
/* 80230544 0022D344  98 06 06 54 */	stb r0, 0x654(r6)
/* 80230548 0022D348  40 82 00 48 */	bne .L_80230590
/* 8023054C 0022D34C  4B EA 51 85 */	bl kar_grlib2__near_800d56d0
/* 80230550 0022D350  7C 03 E0 AE */	lbzx r0, r3, r28
/* 80230554 0022D354  7C 00 EE 30 */	sraw r0, r0, r29
/* 80230558 0022D358  54 00 07 FF */	clrlwi. r0, r0, 31
/* 8023055C 0022D35C  41 82 00 0C */	beq .L_80230568
/* 80230560 0022D360  38 00 00 01 */	li r0, 0x1
/* 80230564 0022D364  90 1E 08 50 */	stw r0, 0x850(r30)
.L_80230568:
/* 80230568 0022D368  4B EB E3 5D */	bl kar_greventgenerator_get_active_event_kind
/* 8023056C 0022D36C  2C 03 00 06 */	cmpwi r3, 0x6
/* 80230570 0022D370  40 82 00 20 */	bne .L_80230590
/* 80230574 0022D374  4B EA 51 95 */	bl kar_grlib2__near_800d5708
/* 80230578 0022D378  7C 03 E0 AE */	lbzx r0, r3, r28
/* 8023057C 0022D37C  7C 00 EE 30 */	sraw r0, r0, r29
/* 80230580 0022D380  54 00 07 FF */	clrlwi. r0, r0, 31
/* 80230584 0022D384  41 82 00 0C */	beq .L_80230590
/* 80230588 0022D388  7F E3 FB 78 */	mr r3, r31
/* 8023058C 0022D38C  48 04 A4 BD */	bl fn_8027AA48
.L_80230590:
/* 80230590 0022D390  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80230594 0022D394  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80230598 0022D398  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8023059C 0022D39C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 802305A0 0022D3A0  83 81 00 10 */	lwz r28, 0x10(r1)
/* 802305A4 0022D3A4  7C 08 03 A6 */	mtlr r0
/* 802305A8 0022D3A8  38 21 00 20 */	addi r1, r1, 0x20
/* 802305AC 0022D3AC  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_802304c8

# .text:0x273C | 0x802305B0 | size: 0x124
.fn kar_plclearcheckerlib__near_802305b0, global
/* 802305B0 0022D3B0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 802305B4 0022D3B4  7C 08 02 A6 */	mflr r0
/* 802305B8 0022D3B8  90 01 00 24 */	stw r0, 0x24(r1)
/* 802305BC 0022D3BC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 802305C0 0022D3C0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 802305C4 0022D3C4  7C 9E 23 78 */	mr r30, r4
/* 802305C8 0022D3C8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 802305CC 0022D3CC  93 81 00 10 */	stw r28, 0x10(r1)
/* 802305D0 0022D3D0  7C 7C 1B 78 */	mr r28, r3
/* 802305D4 0022D3D4  2C 1C 00 05 */	cmpwi r28, 0x5
/* 802305D8 0022D3D8  41 82 00 DC */	beq .L_802306B4
/* 802305DC 0022D3DC  4B DD 8C FD */	bl fn_800092D8
/* 802305E0 0022D3E0  7C 63 07 74 */	extsb r3, r3
/* 802305E4 0022D3E4  48 03 17 05 */	bl fn_80261CE8
/* 802305E8 0022D3E8  7C 7D 1B 78 */	mr r29, r3
/* 802305EC 0022D3EC  7F 83 E3 78 */	mr r3, r28
/* 802305F0 0022D3F0  4B FF CC 59 */	bl kar_plclearchecker_get_player_state
/* 802305F4 0022D3F4  7F C5 1E 70 */	srawi r5, r30, 3
/* 802305F8 0022D3F8  57 C0 E8 04 */	slwi r0, r30, 29
/* 802305FC 0022D3FC  57 C4 0F FE */	srwi r4, r30, 31
/* 80230600 0022D400  7C 7F 1B 78 */	mr r31, r3
/* 80230604 0022D404  7F C5 01 94 */	addze r30, r5
/* 80230608 0022D408  38 60 00 01 */	li r3, 0x1
/* 8023060C 0022D40C  7C 04 00 50 */	subf r0, r4, r0
/* 80230610 0022D410  2C 1D 00 09 */	cmpwi r29, 0x9
/* 80230614 0022D414  7C DF F2 14 */	add r6, r31, r30
/* 80230618 0022D418  54 00 18 3E */	rotlwi r0, r0, 3
/* 8023061C 0022D41C  88 A6 06 61 */	lbz r5, 0x661(r6)
/* 80230620 0022D420  7F A0 22 14 */	add r29, r0, r4
/* 80230624 0022D424  7C 60 E8 30 */	slw r0, r3, r29
/* 80230628 0022D428  7C A0 03 78 */	or r0, r5, r0
/* 8023062C 0022D42C  98 06 06 61 */	stb r0, 0x661(r6)
/* 80230630 0022D430  40 82 00 84 */	bne .L_802306B4
/* 80230634 0022D434  4B EA 4F BD */	bl kar_grlib2__near_800d55f0
/* 80230638 0022D438  7C 03 F0 AE */	lbzx r0, r3, r30
/* 8023063C 0022D43C  7C 00 EE 30 */	sraw r0, r0, r29
/* 80230640 0022D440  54 00 07 FF */	clrlwi. r0, r0, 31
/* 80230644 0022D444  41 82 00 10 */	beq .L_80230654
/* 80230648 0022D448  80 7F 08 38 */	lwz r3, 0x838(r31)
/* 8023064C 0022D44C  38 03 00 01 */	addi r0, r3, 0x1
/* 80230650 0022D450  90 1F 08 38 */	stw r0, 0x838(r31)
.L_80230654:
/* 80230654 0022D454  4B EA 4F D5 */	bl kar_grlib2__near_800d5628
/* 80230658 0022D458  7C 03 F0 AE */	lbzx r0, r3, r30
/* 8023065C 0022D45C  7C 00 EE 30 */	sraw r0, r0, r29
/* 80230660 0022D460  54 00 07 FF */	clrlwi. r0, r0, 31
/* 80230664 0022D464  41 82 00 18 */	beq .L_8023067C
/* 80230668 0022D468  80 9F 08 34 */	lwz r4, 0x834(r31)
/* 8023066C 0022D46C  7F 83 E3 78 */	mr r3, r28
/* 80230670 0022D470  38 04 00 01 */	addi r0, r4, 0x1
/* 80230674 0022D474  90 1F 08 34 */	stw r0, 0x834(r31)
/* 80230678 0022D478  48 04 A3 21 */	bl fn_8027A998
.L_8023067C:
/* 8023067C 0022D47C  4B EA 4F E5 */	bl kar_grlib2__near_800d5660
/* 80230680 0022D480  7C 03 F0 AE */	lbzx r0, r3, r30
/* 80230684 0022D484  7C 00 EE 30 */	sraw r0, r0, r29
/* 80230688 0022D488  54 00 07 FF */	clrlwi. r0, r0, 31
/* 8023068C 0022D48C  41 82 00 0C */	beq .L_80230698
/* 80230690 0022D490  7F 83 E3 78 */	mr r3, r28
/* 80230694 0022D494  48 04 A3 31 */	bl fn_8027A9C4
.L_80230698:
/* 80230698 0022D498  4B EA 50 01 */	bl kar_grlib2__near_800d5698
/* 8023069C 0022D49C  7C 03 F0 AE */	lbzx r0, r3, r30
/* 802306A0 0022D4A0  7C 00 EE 30 */	sraw r0, r0, r29
/* 802306A4 0022D4A4  54 00 07 FF */	clrlwi. r0, r0, 31
/* 802306A8 0022D4A8  41 82 00 0C */	beq .L_802306B4
/* 802306AC 0022D4AC  7F 83 E3 78 */	mr r3, r28
/* 802306B0 0022D4B0  48 04 A3 41 */	bl fn_8027A9F0
.L_802306B4:
/* 802306B4 0022D4B4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 802306B8 0022D4B8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 802306BC 0022D4BC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 802306C0 0022D4C0  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 802306C4 0022D4C4  83 81 00 10 */	lwz r28, 0x10(r1)
/* 802306C8 0022D4C8  7C 08 03 A6 */	mtlr r0
/* 802306CC 0022D4CC  38 21 00 20 */	addi r1, r1, 0x20
/* 802306D0 0022D4D0  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_802305b0

# .text:0x2860 | 0x802306D4 | size: 0x54
.fn kar_plclearcheckerlib__802306d4, global
/* 802306D4 0022D4D4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802306D8 0022D4D8  7C 08 02 A6 */	mflr r0
/* 802306DC 0022D4DC  90 01 00 14 */	stw r0, 0x14(r1)
/* 802306E0 0022D4E0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802306E4 0022D4E4  7C 7F 1B 78 */	mr r31, r3
/* 802306E8 0022D4E8  2C 1F 00 05 */	cmpwi r31, 0x5
/* 802306EC 0022D4EC  41 80 00 1C */	blt .L_80230708
/* 802306F0 0022D4F0  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 802306F4 0022D4F4  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 802306F8 0022D4F8  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 802306FC 0022D4FC  38 80 06 9B */	li r4, 0x69b
/* 80230700 0022D500  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80230704 0022D504  48 1F 7D B5 */	bl __assert
.L_80230708:
/* 80230708 0022D508  7F E3 FB 78 */	mr r3, r31
/* 8023070C 0022D50C  4B FF CB 3D */	bl kar_plclearchecker_get_player_state
/* 80230710 0022D510  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230714 0022D514  80 63 06 A0 */	lwz r3, 0x6a0(r3)
/* 80230718 0022D518  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023071C 0022D51C  7C 08 03 A6 */	mtlr r0
/* 80230720 0022D520  38 21 00 10 */	addi r1, r1, 0x10
/* 80230724 0022D524  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__802306d4

# .text:0x28B4 | 0x80230728 | size: 0x54
.fn kar_plclearcheckerlib__80230728, global
/* 80230728 0022D528  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023072C 0022D52C  7C 08 02 A6 */	mflr r0
/* 80230730 0022D530  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230734 0022D534  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80230738 0022D538  7C 7F 1B 78 */	mr r31, r3
/* 8023073C 0022D53C  2C 1F 00 05 */	cmpwi r31, 0x5
/* 80230740 0022D540  41 80 00 1C */	blt .L_8023075C
/* 80230744 0022D544  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80230748 0022D548  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8023074C 0022D54C  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 80230750 0022D550  38 80 06 A4 */	li r4, 0x6a4
/* 80230754 0022D554  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80230758 0022D558  48 1F 7D 61 */	bl __assert
.L_8023075C:
/* 8023075C 0022D55C  7F E3 FB 78 */	mr r3, r31
/* 80230760 0022D560  4B FF CA E9 */	bl kar_plclearchecker_get_player_state
/* 80230764 0022D564  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230768 0022D568  80 63 07 D0 */	lwz r3, 0x7d0(r3)
/* 8023076C 0022D56C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80230770 0022D570  7C 08 03 A6 */	mtlr r0
/* 80230774 0022D574  38 21 00 10 */	addi r1, r1, 0x10
/* 80230778 0022D578  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__80230728

# .text:0x2908 | 0x8023077C | size: 0x68
.fn kar_plclearcheckerlib__8023077c, global
/* 8023077C 0022D57C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230780 0022D580  7C 08 02 A6 */	mflr r0
/* 80230784 0022D584  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230788 0022D588  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023078C 0022D58C  7C 9F 23 78 */	mr r31, r4
/* 80230790 0022D590  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80230794 0022D594  7C 7E 1B 78 */	mr r30, r3
/* 80230798 0022D598  2C 1E 00 05 */	cmpwi r30, 0x5
/* 8023079C 0022D59C  41 80 00 1C */	blt .L_802307B8
/* 802307A0 0022D5A0  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 802307A4 0022D5A4  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 802307A8 0022D5A8  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 802307AC 0022D5AC  38 80 06 B6 */	li r4, 0x6b6
/* 802307B0 0022D5B0  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 802307B4 0022D5B4  48 1F 7D 05 */	bl __assert
.L_802307B8:
/* 802307B8 0022D5B8  7F C3 F3 78 */	mr r3, r30
/* 802307BC 0022D5BC  4B FF CA 8D */	bl kar_plclearchecker_get_player_state
/* 802307C0 0022D5C0  57 E4 10 3A */	slwi r4, r31, 2
/* 802307C4 0022D5C4  38 04 06 A8 */	addi r0, r4, 0x6a8
/* 802307C8 0022D5C8  7C 63 00 2E */	lwzx r3, r3, r0
/* 802307CC 0022D5CC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802307D0 0022D5D0  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 802307D4 0022D5D4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802307D8 0022D5D8  7C 08 03 A6 */	mtlr r0
/* 802307DC 0022D5DC  38 21 00 10 */	addi r1, r1, 0x10
/* 802307E0 0022D5E0  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8023077c

# .text:0x2970 | 0x802307E4 | size: 0x54
.fn kar_plclearcheckerlib__802307e4, global
/* 802307E4 0022D5E4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802307E8 0022D5E8  7C 08 02 A6 */	mflr r0
/* 802307EC 0022D5EC  90 01 00 14 */	stw r0, 0x14(r1)
/* 802307F0 0022D5F0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802307F4 0022D5F4  7C 7F 1B 78 */	mr r31, r3
/* 802307F8 0022D5F8  2C 1F 00 05 */	cmpwi r31, 0x5
/* 802307FC 0022D5FC  41 80 00 1C */	blt .L_80230818
/* 80230800 0022D600  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80230804 0022D604  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 80230808 0022D608  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8023080C 0022D60C  38 80 06 BF */	li r4, 0x6bf
/* 80230810 0022D610  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80230814 0022D614  48 1F 7C A5 */	bl __assert
.L_80230818:
/* 80230818 0022D618  7F E3 FB 78 */	mr r3, r31
/* 8023081C 0022D61C  4B FF CA 2D */	bl kar_plclearchecker_get_player_state
/* 80230820 0022D620  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230824 0022D624  80 63 07 C8 */	lwz r3, 0x7c8(r3)
/* 80230828 0022D628  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023082C 0022D62C  7C 08 03 A6 */	mtlr r0
/* 80230830 0022D630  38 21 00 10 */	addi r1, r1, 0x10
/* 80230834 0022D634  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__802307e4

# .text:0x29C4 | 0x80230838 | size: 0x54
.fn kar_plclearcheckerlib__80230838, global
/* 80230838 0022D638  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023083C 0022D63C  7C 08 02 A6 */	mflr r0
/* 80230840 0022D640  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230844 0022D644  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80230848 0022D648  7C 7F 1B 78 */	mr r31, r3
/* 8023084C 0022D64C  2C 1F 00 05 */	cmpwi r31, 0x5
/* 80230850 0022D650  41 80 00 1C */	blt .L_8023086C
/* 80230854 0022D654  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80230858 0022D658  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 8023085C 0022D65C  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 80230860 0022D660  38 80 06 E3 */	li r4, 0x6e3
/* 80230864 0022D664  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80230868 0022D668  48 1F 7C 51 */	bl __assert
.L_8023086C:
/* 8023086C 0022D66C  7F E3 FB 78 */	mr r3, r31
/* 80230870 0022D670  4B FF C9 D9 */	bl kar_plclearchecker_get_player_state
/* 80230874 0022D674  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230878 0022D678  80 63 07 EC */	lwz r3, 0x7ec(r3)
/* 8023087C 0022D67C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80230880 0022D680  7C 08 03 A6 */	mtlr r0
/* 80230884 0022D684  38 21 00 10 */	addi r1, r1, 0x10
/* 80230888 0022D688  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__80230838

# .text:0x2A18 | 0x8023088C | size: 0x54
.fn kar_plclearcheckerlib__8023088c, global
/* 8023088C 0022D68C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230890 0022D690  7C 08 02 A6 */	mflr r0
/* 80230894 0022D694  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230898 0022D698  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023089C 0022D69C  7C 7F 1B 78 */	mr r31, r3
/* 802308A0 0022D6A0  2C 1F 00 05 */	cmpwi r31, 0x5
/* 802308A4 0022D6A4  41 80 00 1C */	blt .L_802308C0
/* 802308A8 0022D6A8  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 802308AC 0022D6AC  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 802308B0 0022D6B0  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 802308B4 0022D6B4  38 80 06 EC */	li r4, 0x6ec
/* 802308B8 0022D6B8  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 802308BC 0022D6BC  48 1F 7B FD */	bl __assert
.L_802308C0:
/* 802308C0 0022D6C0  7F E3 FB 78 */	mr r3, r31
/* 802308C4 0022D6C4  4B FF C9 85 */	bl kar_plclearchecker_get_player_state
/* 802308C8 0022D6C8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802308CC 0022D6CC  80 63 07 F0 */	lwz r3, 0x7f0(r3)
/* 802308D0 0022D6D0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802308D4 0022D6D4  7C 08 03 A6 */	mtlr r0
/* 802308D8 0022D6D8  38 21 00 10 */	addi r1, r1, 0x10
/* 802308DC 0022D6DC  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8023088c

# .text:0x2A6C | 0x802308E0 | size: 0x54
.fn kar_plclearcheckerlib__802308e0, global
/* 802308E0 0022D6E0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802308E4 0022D6E4  7C 08 02 A6 */	mflr r0
/* 802308E8 0022D6E8  90 01 00 14 */	stw r0, 0x14(r1)
/* 802308EC 0022D6EC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802308F0 0022D6F0  7C 7F 1B 78 */	mr r31, r3
/* 802308F4 0022D6F4  2C 1F 00 05 */	cmpwi r31, 0x5
/* 802308F8 0022D6F8  41 80 00 1C */	blt .L_80230914
/* 802308FC 0022D6FC  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80230900 0022D700  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 80230904 0022D704  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 80230908 0022D708  38 80 06 F5 */	li r4, 0x6f5
/* 8023090C 0022D70C  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80230910 0022D710  48 1F 7B A9 */	bl __assert
.L_80230914:
/* 80230914 0022D714  7F E3 FB 78 */	mr r3, r31
/* 80230918 0022D718  4B FF C9 31 */	bl kar_plclearchecker_get_player_state
/* 8023091C 0022D71C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230920 0022D720  80 63 07 F4 */	lwz r3, 0x7f4(r3)
/* 80230924 0022D724  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80230928 0022D728  7C 08 03 A6 */	mtlr r0
/* 8023092C 0022D72C  38 21 00 10 */	addi r1, r1, 0x10
/* 80230930 0022D730  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__802308e0

# .text:0x2AC0 | 0x80230934 | size: 0x58
.fn kar_plclearcheckerlib__80230934, global
/* 80230934 0022D734  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230938 0022D738  7C 08 02 A6 */	mflr r0
/* 8023093C 0022D73C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230940 0022D740  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80230944 0022D744  7C 7F 1B 78 */	mr r31, r3
/* 80230948 0022D748  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8023094C 0022D74C  41 80 00 1C */	blt .L_80230968
/* 80230950 0022D750  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80230954 0022D754  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 80230958 0022D758  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8023095C 0022D75C  38 80 07 07 */	li r4, 0x707
/* 80230960 0022D760  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80230964 0022D764  48 1F 7B 55 */	bl __assert
.L_80230968:
/* 80230968 0022D768  7F E3 FB 78 */	mr r3, r31
/* 8023096C 0022D76C  4B FF C8 DD */	bl kar_plclearchecker_get_player_state
/* 80230970 0022D770  88 03 08 4D */	lbz r0, 0x84d(r3)
/* 80230974 0022D774  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80230978 0022D778  54 03 FF FE */	extrwi r3, r0, 1, 30
/* 8023097C 0022D77C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230980 0022D780  7C 08 03 A6 */	mtlr r0
/* 80230984 0022D784  38 21 00 10 */	addi r1, r1, 0x10
/* 80230988 0022D788  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__80230934

# .text:0x2B18 | 0x8023098C | size: 0x54
.fn kar_plclearcheckerlib__8023098c, global
/* 8023098C 0022D78C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230990 0022D790  7C 08 02 A6 */	mflr r0
/* 80230994 0022D794  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230998 0022D798  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023099C 0022D79C  7C 7F 1B 78 */	mr r31, r3
/* 802309A0 0022D7A0  2C 1F 00 05 */	cmpwi r31, 0x5
/* 802309A4 0022D7A4  41 80 00 1C */	blt .L_802309C0
/* 802309A8 0022D7A8  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 802309AC 0022D7AC  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 802309B0 0022D7B0  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 802309B4 0022D7B4  38 80 07 10 */	li r4, 0x710
/* 802309B8 0022D7B8  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 802309BC 0022D7BC  48 1F 7A FD */	bl __assert
.L_802309C0:
/* 802309C0 0022D7C0  7F E3 FB 78 */	mr r3, r31
/* 802309C4 0022D7C4  4B FF C8 85 */	bl kar_plclearchecker_get_player_state
/* 802309C8 0022D7C8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802309CC 0022D7CC  80 63 08 00 */	lwz r3, 0x800(r3)
/* 802309D0 0022D7D0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802309D4 0022D7D4  7C 08 03 A6 */	mtlr r0
/* 802309D8 0022D7D8  38 21 00 10 */	addi r1, r1, 0x10
/* 802309DC 0022D7DC  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8023098c

# .text:0x2B6C | 0x802309E0 | size: 0x54
.fn kar_plclearcheckerlib__802309e0, global
/* 802309E0 0022D7E0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802309E4 0022D7E4  7C 08 02 A6 */	mflr r0
/* 802309E8 0022D7E8  90 01 00 14 */	stw r0, 0x14(r1)
/* 802309EC 0022D7EC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802309F0 0022D7F0  7C 7F 1B 78 */	mr r31, r3
/* 802309F4 0022D7F4  2C 1F 00 05 */	cmpwi r31, 0x5
/* 802309F8 0022D7F8  41 80 00 1C */	blt .L_80230A14
/* 802309FC 0022D7FC  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80230A00 0022D800  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 80230A04 0022D804  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 80230A08 0022D808  38 80 07 19 */	li r4, 0x719
/* 80230A0C 0022D80C  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80230A10 0022D810  48 1F 7A A9 */	bl __assert
.L_80230A14:
/* 80230A14 0022D814  7F E3 FB 78 */	mr r3, r31
/* 80230A18 0022D818  4B FF C8 31 */	bl kar_plclearchecker_get_player_state
/* 80230A1C 0022D81C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230A20 0022D820  80 63 08 10 */	lwz r3, 0x810(r3)
/* 80230A24 0022D824  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80230A28 0022D828  7C 08 03 A6 */	mtlr r0
/* 80230A2C 0022D82C  38 21 00 10 */	addi r1, r1, 0x10
/* 80230A30 0022D830  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__802309e0

# .text:0x2BC0 | 0x80230A34 | size: 0x54
.fn kar_plclearcheckerlib__80230a34, global
/* 80230A34 0022D834  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230A38 0022D838  7C 08 02 A6 */	mflr r0
/* 80230A3C 0022D83C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230A40 0022D840  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80230A44 0022D844  7C 7F 1B 78 */	mr r31, r3
/* 80230A48 0022D848  2C 1F 00 05 */	cmpwi r31, 0x5
/* 80230A4C 0022D84C  41 80 00 1C */	blt .L_80230A68
/* 80230A50 0022D850  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80230A54 0022D854  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 80230A58 0022D858  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 80230A5C 0022D85C  38 80 07 22 */	li r4, 0x722
/* 80230A60 0022D860  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80230A64 0022D864  48 1F 7A 55 */	bl __assert
.L_80230A68:
/* 80230A68 0022D868  7F E3 FB 78 */	mr r3, r31
/* 80230A6C 0022D86C  4B FF C7 DD */	bl kar_plclearchecker_get_player_state
/* 80230A70 0022D870  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230A74 0022D874  80 63 08 14 */	lwz r3, 0x814(r3)
/* 80230A78 0022D878  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80230A7C 0022D87C  7C 08 03 A6 */	mtlr r0
/* 80230A80 0022D880  38 21 00 10 */	addi r1, r1, 0x10
/* 80230A84 0022D884  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__80230a34

# .text:0x2C14 | 0x80230A88 | size: 0x58
.fn kar_plclearcheckerlib__80230a88, global
/* 80230A88 0022D888  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230A8C 0022D88C  7C 08 02 A6 */	mflr r0
/* 80230A90 0022D890  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230A94 0022D894  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80230A98 0022D898  7C 7F 1B 78 */	mr r31, r3
/* 80230A9C 0022D89C  2C 1F 00 05 */	cmpwi r31, 0x5
/* 80230AA0 0022D8A0  41 80 00 1C */	blt .L_80230ABC
/* 80230AA4 0022D8A4  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80230AA8 0022D8A8  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 80230AAC 0022D8AC  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 80230AB0 0022D8B0  38 80 07 2B */	li r4, 0x72b
/* 80230AB4 0022D8B4  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80230AB8 0022D8B8  48 1F 7A 01 */	bl __assert
.L_80230ABC:
/* 80230ABC 0022D8BC  7F E3 FB 78 */	mr r3, r31
/* 80230AC0 0022D8C0  4B FF C7 89 */	bl kar_plclearchecker_get_player_state
/* 80230AC4 0022D8C4  88 03 08 4C */	lbz r0, 0x84c(r3)
/* 80230AC8 0022D8C8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80230ACC 0022D8CC  54 03 D7 FE */	extrwi r3, r0, 1, 25
/* 80230AD0 0022D8D0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230AD4 0022D8D4  7C 08 03 A6 */	mtlr r0
/* 80230AD8 0022D8D8  38 21 00 10 */	addi r1, r1, 0x10
/* 80230ADC 0022D8DC  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__80230a88

# .text:0x2C6C | 0x80230AE0 | size: 0x58
.fn kar_plclearcheckerlib__80230ae0, global
/* 80230AE0 0022D8E0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230AE4 0022D8E4  7C 08 02 A6 */	mflr r0
/* 80230AE8 0022D8E8  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230AEC 0022D8EC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80230AF0 0022D8F0  7C 7F 1B 78 */	mr r31, r3
/* 80230AF4 0022D8F4  2C 1F 00 05 */	cmpwi r31, 0x5
/* 80230AF8 0022D8F8  41 80 00 1C */	blt .L_80230B14
/* 80230AFC 0022D8FC  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80230B00 0022D900  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 80230B04 0022D904  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 80230B08 0022D908  38 80 07 34 */	li r4, 0x734
/* 80230B0C 0022D90C  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80230B10 0022D910  48 1F 79 A9 */	bl __assert
.L_80230B14:
/* 80230B14 0022D914  7F E3 FB 78 */	mr r3, r31
/* 80230B18 0022D918  4B FF C7 31 */	bl kar_plclearchecker_get_player_state
/* 80230B1C 0022D91C  88 03 08 4C */	lbz r0, 0x84c(r3)
/* 80230B20 0022D920  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80230B24 0022D924  54 03 F7 FE */	extrwi r3, r0, 1, 29
/* 80230B28 0022D928  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230B2C 0022D92C  7C 08 03 A6 */	mtlr r0
/* 80230B30 0022D930  38 21 00 10 */	addi r1, r1, 0x10
/* 80230B34 0022D934  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__80230ae0

# .text:0x2CC4 | 0x80230B38 | size: 0x58
.fn kar_plclearcheckerlib__80230b38, global
/* 80230B38 0022D938  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230B3C 0022D93C  7C 08 02 A6 */	mflr r0
/* 80230B40 0022D940  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230B44 0022D944  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80230B48 0022D948  7C 7F 1B 78 */	mr r31, r3
/* 80230B4C 0022D94C  2C 1F 00 05 */	cmpwi r31, 0x5
/* 80230B50 0022D950  41 80 00 1C */	blt .L_80230B6C
/* 80230B54 0022D954  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80230B58 0022D958  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 80230B5C 0022D95C  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 80230B60 0022D960  38 80 07 3F */	li r4, 0x73f
/* 80230B64 0022D964  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80230B68 0022D968  48 1F 79 51 */	bl __assert
.L_80230B6C:
/* 80230B6C 0022D96C  7F E3 FB 78 */	mr r3, r31
/* 80230B70 0022D970  4B FF C6 D9 */	bl kar_plclearchecker_get_player_state
/* 80230B74 0022D974  88 03 08 4C */	lbz r0, 0x84c(r3)
/* 80230B78 0022D978  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80230B7C 0022D97C  54 03 FF FE */	extrwi r3, r0, 1, 30
/* 80230B80 0022D980  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230B84 0022D984  7C 08 03 A6 */	mtlr r0
/* 80230B88 0022D988  38 21 00 10 */	addi r1, r1, 0x10
/* 80230B8C 0022D98C  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__80230b38

# .text:0x2D1C | 0x80230B90 | size: 0x58
.fn kar_plclearcheckerlib__80230b90, global
/* 80230B90 0022D990  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230B94 0022D994  7C 08 02 A6 */	mflr r0
/* 80230B98 0022D998  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230B9C 0022D99C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80230BA0 0022D9A0  7C 7F 1B 78 */	mr r31, r3
/* 80230BA4 0022D9A4  2C 1F 00 05 */	cmpwi r31, 0x5
/* 80230BA8 0022D9A8  41 80 00 1C */	blt .L_80230BC4
/* 80230BAC 0022D9AC  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80230BB0 0022D9B0  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 80230BB4 0022D9B4  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 80230BB8 0022D9B8  38 80 07 4C */	li r4, 0x74c
/* 80230BBC 0022D9BC  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80230BC0 0022D9C0  48 1F 78 F9 */	bl __assert
.L_80230BC4:
/* 80230BC4 0022D9C4  7F E3 FB 78 */	mr r3, r31
/* 80230BC8 0022D9C8  4B FF C6 81 */	bl kar_plclearchecker_get_player_state
/* 80230BCC 0022D9CC  88 03 08 4C */	lbz r0, 0x84c(r3)
/* 80230BD0 0022D9D0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80230BD4 0022D9D4  54 03 07 FE */	clrlwi r3, r0, 31
/* 80230BD8 0022D9D8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230BDC 0022D9DC  7C 08 03 A6 */	mtlr r0
/* 80230BE0 0022D9E0  38 21 00 10 */	addi r1, r1, 0x10
/* 80230BE4 0022D9E4  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__80230b90

# .text:0x2D74 | 0x80230BE8 | size: 0x54
.fn kar_plclearcheckerlib__80230be8, global
/* 80230BE8 0022D9E8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230BEC 0022D9EC  7C 08 02 A6 */	mflr r0
/* 80230BF0 0022D9F0  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230BF4 0022D9F4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80230BF8 0022D9F8  7C 7F 1B 78 */	mr r31, r3
/* 80230BFC 0022D9FC  2C 1F 00 05 */	cmpwi r31, 0x5
/* 80230C00 0022DA00  41 80 00 1C */	blt .L_80230C1C
/* 80230C04 0022DA04  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80230C08 0022DA08  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 80230C0C 0022DA0C  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 80230C10 0022DA10  38 80 07 57 */	li r4, 0x757
/* 80230C14 0022DA14  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80230C18 0022DA18  48 1F 78 A1 */	bl __assert
.L_80230C1C:
/* 80230C1C 0022DA1C  7F E3 FB 78 */	mr r3, r31
/* 80230C20 0022DA20  4B FF C6 29 */	bl kar_plclearchecker_get_player_state
/* 80230C24 0022DA24  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230C28 0022DA28  80 63 08 20 */	lwz r3, 0x820(r3)
/* 80230C2C 0022DA2C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80230C30 0022DA30  7C 08 03 A6 */	mtlr r0
/* 80230C34 0022DA34  38 21 00 10 */	addi r1, r1, 0x10
/* 80230C38 0022DA38  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__80230be8

# .text:0x2DC8 | 0x80230C3C | size: 0x58
.fn kar_plclearcheckerlib__80230c3c, global
/* 80230C3C 0022DA3C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230C40 0022DA40  7C 08 02 A6 */	mflr r0
/* 80230C44 0022DA44  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230C48 0022DA48  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80230C4C 0022DA4C  7C 7F 1B 78 */	mr r31, r3
/* 80230C50 0022DA50  2C 1F 00 05 */	cmpwi r31, 0x5
/* 80230C54 0022DA54  41 80 00 1C */	blt .L_80230C70
/* 80230C58 0022DA58  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80230C5C 0022DA5C  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 80230C60 0022DA60  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 80230C64 0022DA64  38 80 07 60 */	li r4, 0x760
/* 80230C68 0022DA68  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80230C6C 0022DA6C  48 1F 78 4D */	bl __assert
.L_80230C70:
/* 80230C70 0022DA70  7F E3 FB 78 */	mr r3, r31
/* 80230C74 0022DA74  4B FF C5 D5 */	bl kar_plclearchecker_get_player_state
/* 80230C78 0022DA78  88 03 08 4D */	lbz r0, 0x84d(r3)
/* 80230C7C 0022DA7C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80230C80 0022DA80  54 03 EF FE */	extrwi r3, r0, 1, 28
/* 80230C84 0022DA84  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230C88 0022DA88  7C 08 03 A6 */	mtlr r0
/* 80230C8C 0022DA8C  38 21 00 10 */	addi r1, r1, 0x10
/* 80230C90 0022DA90  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__80230c3c

# .text:0x2E20 | 0x80230C94 | size: 0x58
.fn kar_plclearcheckerlib__80230c94, global
/* 80230C94 0022DA94  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230C98 0022DA98  7C 08 02 A6 */	mflr r0
/* 80230C9C 0022DA9C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230CA0 0022DAA0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80230CA4 0022DAA4  7C 7F 1B 78 */	mr r31, r3
/* 80230CA8 0022DAA8  2C 1F 00 05 */	cmpwi r31, 0x5
/* 80230CAC 0022DAAC  41 80 00 1C */	blt .L_80230CC8
/* 80230CB0 0022DAB0  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80230CB4 0022DAB4  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 80230CB8 0022DAB8  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 80230CBC 0022DABC  38 80 07 69 */	li r4, 0x769
/* 80230CC0 0022DAC0  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80230CC4 0022DAC4  48 1F 77 F5 */	bl __assert
.L_80230CC8:
/* 80230CC8 0022DAC8  7F E3 FB 78 */	mr r3, r31
/* 80230CCC 0022DACC  4B FF C5 7D */	bl kar_plclearchecker_get_player_state
/* 80230CD0 0022DAD0  88 03 08 4D */	lbz r0, 0x84d(r3)
/* 80230CD4 0022DAD4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80230CD8 0022DAD8  54 03 F7 FE */	extrwi r3, r0, 1, 29
/* 80230CDC 0022DADC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230CE0 0022DAE0  7C 08 03 A6 */	mtlr r0
/* 80230CE4 0022DAE4  38 21 00 10 */	addi r1, r1, 0x10
/* 80230CE8 0022DAE8  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__80230c94

# .text:0x2E78 | 0x80230CEC | size: 0x124
.fn kar_plclearcheckerlib__near_80230cec, global
/* 80230CEC 0022DAEC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80230CF0 0022DAF0  7C 08 02 A6 */	mflr r0
/* 80230CF4 0022DAF4  90 01 00 24 */	stw r0, 0x24(r1)
/* 80230CF8 0022DAF8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80230CFC 0022DAFC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80230D00 0022DB00  7C 7E 1B 78 */	mr r30, r3
/* 80230D04 0022DB04  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80230D08 0022DB08  7C 9D 23 78 */	mr r29, r4
/* 80230D0C 0022DB0C  7F A3 EB 78 */	mr r3, r29
/* 80230D10 0022DB10  4B FD 3D 71 */	bl kar_emupdate__near_80204a80
/* 80230D14 0022DB14  2C 03 00 00 */	cmpwi r3, 0x0
/* 80230D18 0022DB18  41 82 00 DC */	beq .L_80230DF4
/* 80230D1C 0022DB1C  2C 1E 00 05 */	cmpwi r30, 0x5
/* 80230D20 0022DB20  41 82 00 D4 */	beq .L_80230DF4
/* 80230D24 0022DB24  7F C3 F3 78 */	mr r3, r30
/* 80230D28 0022DB28  4B FF C5 09 */	bl kar_plclearchecker_get_player_object
/* 80230D2C 0022DB2C  7C 60 1B 78 */	mr r0, r3
/* 80230D30 0022DB30  7F C3 F3 78 */	mr r3, r30
/* 80230D34 0022DB34  7C 1E 03 78 */	mr r30, r0
/* 80230D38 0022DB38  4B FF C5 11 */	bl kar_plclearchecker_get_player_state
/* 80230D3C 0022DB3C  7C 7F 1B 78 */	mr r31, r3
/* 80230D40 0022DB40  7F A3 EB 78 */	mr r3, r29
/* 80230D44 0022DB44  4B FD 33 59 */	bl kar_emupdate__near_8020409c
/* 80230D48 0022DB48  80 9F 06 A0 */	lwz r4, 0x6a0(r31)
/* 80230D4C 0022DB4C  38 04 00 01 */	addi r0, r4, 0x1
/* 80230D50 0022DB50  90 1F 06 A0 */	stw r0, 0x6a0(r31)
/* 80230D54 0022DB54  88 1F 08 55 */	lbz r0, 0x855(r31)
/* 80230D58 0022DB58  54 00 D7 FF */	extrwi. r0, r0, 1, 25
/* 80230D5C 0022DB5C  40 82 00 68 */	bne .L_80230DC4
/* 80230D60 0022DB60  80 9F 07 D0 */	lwz r4, 0x7d0(r31)
/* 80230D64 0022DB64  2C 03 00 48 */	cmpwi r3, 0x48
/* 80230D68 0022DB68  38 04 00 01 */	addi r0, r4, 0x1
/* 80230D6C 0022DB6C  90 1F 07 D0 */	stw r0, 0x7d0(r31)
/* 80230D70 0022DB70  40 80 00 18 */	bge .L_80230D88
/* 80230D74 0022DB74  54 60 10 3A */	slwi r0, r3, 2
/* 80230D78 0022DB78  7C 9F 02 14 */	add r4, r31, r0
/* 80230D7C 0022DB7C  80 64 06 A8 */	lwz r3, 0x6a8(r4)
/* 80230D80 0022DB80  38 03 00 01 */	addi r0, r3, 0x1
/* 80230D84 0022DB84  90 04 06 A8 */	stw r0, 0x6a8(r4)
.L_80230D88:
/* 80230D88 0022DB88  7F A3 EB 78 */	mr r3, r29
/* 80230D8C 0022DB8C  4B FD 35 05 */	bl kar_emupdate__near_80204290
/* 80230D90 0022DB90  2C 03 FF FF */	cmpwi r3, -0x1
/* 80230D94 0022DB94  40 82 00 28 */	bne .L_80230DBC
/* 80230D98 0022DB98  80 7F 07 CC */	lwz r3, 0x7cc(r31)
/* 80230D9C 0022DB9C  38 03 00 01 */	addi r0, r3, 0x1
/* 80230DA0 0022DBA0  90 1F 07 CC */	stw r0, 0x7cc(r31)
/* 80230DA4 0022DBA4  80 1F 07 C8 */	lwz r0, 0x7c8(r31)
/* 80230DA8 0022DBA8  80 7F 07 CC */	lwz r3, 0x7cc(r31)
/* 80230DAC 0022DBAC  7C 00 18 40 */	cmplw r0, r3
/* 80230DB0 0022DBB0  40 80 00 14 */	bge .L_80230DC4
/* 80230DB4 0022DBB4  90 7F 07 C8 */	stw r3, 0x7c8(r31)
/* 80230DB8 0022DBB8  48 00 00 0C */	b .L_80230DC4
.L_80230DBC:
/* 80230DBC 0022DBBC  38 00 00 00 */	li r0, 0x0
/* 80230DC0 0022DBC0  90 1F 07 CC */	stw r0, 0x7cc(r31)
.L_80230DC4:
/* 80230DC4 0022DBC4  7F C3 F3 78 */	mr r3, r30
/* 80230DC8 0022DBC8  4B F9 77 41 */	bl fn_801C8508
/* 80230DCC 0022DBCC  2C 03 00 00 */	cmpwi r3, 0x0
/* 80230DD0 0022DBD0  41 82 00 24 */	beq .L_80230DF4
/* 80230DD4 0022DBD4  7F C3 F3 78 */	mr r3, r30
/* 80230DD8 0022DBD8  4B FB 4C D9 */	bl fn_801E5AB0
/* 80230DDC 0022DBDC  88 03 00 02 */	lbz r0, 0x2(r3)
/* 80230DE0 0022DBE0  54 00 DF FF */	extrwi. r0, r0, 1, 26
/* 80230DE4 0022DBE4  41 82 00 10 */	beq .L_80230DF4
/* 80230DE8 0022DBE8  80 7F 06 A4 */	lwz r3, 0x6a4(r31)
/* 80230DEC 0022DBEC  38 03 00 01 */	addi r0, r3, 0x1
/* 80230DF0 0022DBF0  90 1F 06 A4 */	stw r0, 0x6a4(r31)
.L_80230DF4:
/* 80230DF4 0022DBF4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80230DF8 0022DBF8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80230DFC 0022DBFC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80230E00 0022DC00  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80230E04 0022DC04  7C 08 03 A6 */	mtlr r0
/* 80230E08 0022DC08  38 21 00 20 */	addi r1, r1, 0x20
/* 80230E0C 0022DC0C  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80230cec

# .text:0x2F9C | 0x80230E10 | size: 0x34
.fn kar_plclearcheckerlib__near_80230e10, global
/* 80230E10 0022DC10  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230E14 0022DC14  7C 08 02 A6 */	mflr r0
/* 80230E18 0022DC18  2C 03 00 05 */	cmpwi r3, 0x5
/* 80230E1C 0022DC1C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230E20 0022DC20  41 82 00 14 */	beq .L_80230E34
/* 80230E24 0022DC24  4B FF C4 25 */	bl kar_plclearchecker_get_player_state
/* 80230E28 0022DC28  80 83 07 E0 */	lwz r4, 0x7e0(r3)
/* 80230E2C 0022DC2C  38 04 00 01 */	addi r0, r4, 0x1
/* 80230E30 0022DC30  90 03 07 E0 */	stw r0, 0x7e0(r3)
.L_80230E34:
/* 80230E34 0022DC34  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230E38 0022DC38  7C 08 03 A6 */	mtlr r0
/* 80230E3C 0022DC3C  38 21 00 10 */	addi r1, r1, 0x10
/* 80230E40 0022DC40  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80230e10

# .text:0x2FD0 | 0x80230E44 | size: 0x34
.fn kar_plclearcheckerlib__near_80230e44, global
/* 80230E44 0022DC44  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230E48 0022DC48  7C 08 02 A6 */	mflr r0
/* 80230E4C 0022DC4C  2C 03 00 05 */	cmpwi r3, 0x5
/* 80230E50 0022DC50  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230E54 0022DC54  41 82 00 14 */	beq .L_80230E68
/* 80230E58 0022DC58  4B FF C3 F1 */	bl kar_plclearchecker_get_player_state
/* 80230E5C 0022DC5C  80 83 07 E4 */	lwz r4, 0x7e4(r3)
/* 80230E60 0022DC60  38 04 00 01 */	addi r0, r4, 0x1
/* 80230E64 0022DC64  90 03 07 E4 */	stw r0, 0x7e4(r3)
.L_80230E68:
/* 80230E68 0022DC68  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230E6C 0022DC6C  7C 08 03 A6 */	mtlr r0
/* 80230E70 0022DC70  38 21 00 10 */	addi r1, r1, 0x10
/* 80230E74 0022DC74  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80230e44

# .text:0x3004 | 0x80230E78 | size: 0x68
.fn kar_plclearcheckerlib__near_80230e78, global
/* 80230E78 0022DC78  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230E7C 0022DC7C  7C 08 02 A6 */	mflr r0
/* 80230E80 0022DC80  2C 03 00 05 */	cmpwi r3, 0x5
/* 80230E84 0022DC84  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230E88 0022DC88  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80230E8C 0022DC8C  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80230E90 0022DC90  7C 9E 23 78 */	mr r30, r4
/* 80230E94 0022DC94  41 82 00 34 */	beq .L_80230EC8
/* 80230E98 0022DC98  4B FF C3 B1 */	bl kar_plclearchecker_get_player_state
/* 80230E9C 0022DC9C  7C 7F 1B 78 */	mr r31, r3
/* 80230EA0 0022DCA0  7F C3 F3 78 */	mr r3, r30
/* 80230EA4 0022DCA4  80 9F 07 E8 */	lwz r4, 0x7e8(r31)
/* 80230EA8 0022DCA8  38 04 00 01 */	addi r0, r4, 0x1
/* 80230EAC 0022DCAC  90 1F 07 E8 */	stw r0, 0x7e8(r31)
/* 80230EB0 0022DCB0  4B EA 13 21 */	bl kar_grcoll__near_800d21d0
/* 80230EB4 0022DCB4  2C 03 00 01 */	cmpwi r3, 0x1
/* 80230EB8 0022DCB8  40 82 00 10 */	bne .L_80230EC8
/* 80230EBC 0022DCBC  80 7F 07 EC */	lwz r3, 0x7ec(r31)
/* 80230EC0 0022DCC0  38 03 00 01 */	addi r0, r3, 0x1
/* 80230EC4 0022DCC4  90 1F 07 EC */	stw r0, 0x7ec(r31)
.L_80230EC8:
/* 80230EC8 0022DCC8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230ECC 0022DCCC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80230ED0 0022DCD0  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80230ED4 0022DCD4  7C 08 03 A6 */	mtlr r0
/* 80230ED8 0022DCD8  38 21 00 10 */	addi r1, r1, 0x10
/* 80230EDC 0022DCDC  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80230e78

# .text:0x306C | 0x80230EE0 | size: 0x38
.fn kar_plclearcheckerlib__near_80230ee0, global
/* 80230EE0 0022DCE0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230EE4 0022DCE4  7C 08 02 A6 */	mflr r0
/* 80230EE8 0022DCE8  2C 03 00 05 */	cmpwi r3, 0x5
/* 80230EEC 0022DCEC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230EF0 0022DCF0  41 82 00 18 */	beq .L_80230F08
/* 80230EF4 0022DCF4  4B FF C3 55 */	bl kar_plclearchecker_get_player_state
/* 80230EF8 0022DCF8  88 03 08 4D */	lbz r0, 0x84d(r3)
/* 80230EFC 0022DCFC  38 80 00 01 */	li r4, 0x1
/* 80230F00 0022DD00  50 80 0F BC */	rlwimi r0, r4, 1, 30, 30
/* 80230F04 0022DD04  98 03 08 4D */	stb r0, 0x84d(r3)
.L_80230F08:
/* 80230F08 0022DD08  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230F0C 0022DD0C  7C 08 03 A6 */	mtlr r0
/* 80230F10 0022DD10  38 21 00 10 */	addi r1, r1, 0x10
/* 80230F14 0022DD14  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80230ee0

# .text:0x30A4 | 0x80230F18 | size: 0x34
.fn kar_plclearcheckerlib__near_80230f18, global
/* 80230F18 0022DD18  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230F1C 0022DD1C  7C 08 02 A6 */	mflr r0
/* 80230F20 0022DD20  2C 03 00 05 */	cmpwi r3, 0x5
/* 80230F24 0022DD24  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230F28 0022DD28  41 82 00 14 */	beq .L_80230F3C
/* 80230F2C 0022DD2C  4B FF C3 1D */	bl kar_plclearchecker_get_player_state
/* 80230F30 0022DD30  80 83 07 F0 */	lwz r4, 0x7f0(r3)
/* 80230F34 0022DD34  38 04 00 01 */	addi r0, r4, 0x1
/* 80230F38 0022DD38  90 03 07 F0 */	stw r0, 0x7f0(r3)
.L_80230F3C:
/* 80230F3C 0022DD3C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230F40 0022DD40  7C 08 03 A6 */	mtlr r0
/* 80230F44 0022DD44  38 21 00 10 */	addi r1, r1, 0x10
/* 80230F48 0022DD48  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80230f18

# .text:0x30D8 | 0x80230F4C | size: 0x54
.fn kar_plclearcheckerlib__near_80230f4c, global
/* 80230F4C 0022DD4C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230F50 0022DD50  7C 08 02 A6 */	mflr r0
/* 80230F54 0022DD54  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230F58 0022DD58  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80230F5C 0022DD5C  7C 7F 1B 78 */	mr r31, r3
/* 80230F60 0022DD60  2C 1F 00 05 */	cmpwi r31, 0x5
/* 80230F64 0022DD64  41 82 00 28 */	beq .L_80230F8C
/* 80230F68 0022DD68  4B FF C2 E1 */	bl kar_plclearchecker_get_player_state
/* 80230F6C 0022DD6C  88 03 08 55 */	lbz r0, 0x855(r3)
/* 80230F70 0022DD70  54 00 D7 FF */	extrwi. r0, r0, 1, 25
/* 80230F74 0022DD74  40 82 00 18 */	bne .L_80230F8C
/* 80230F78 0022DD78  7F E3 FB 78 */	mr r3, r31
/* 80230F7C 0022DD7C  4B FF C2 CD */	bl kar_plclearchecker_get_player_state
/* 80230F80 0022DD80  80 83 07 F4 */	lwz r4, 0x7f4(r3)
/* 80230F84 0022DD84  38 04 00 01 */	addi r0, r4, 0x1
/* 80230F88 0022DD88  90 03 07 F4 */	stw r0, 0x7f4(r3)
.L_80230F8C:
/* 80230F8C 0022DD8C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230F90 0022DD90  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80230F94 0022DD94  7C 08 03 A6 */	mtlr r0
/* 80230F98 0022DD98  38 21 00 10 */	addi r1, r1, 0x10
/* 80230F9C 0022DD9C  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80230f4c

# .text:0x312C | 0x80230FA0 | size: 0x4C
.fn kar_plclearcheckerlib__near_80230fa0, global
/* 80230FA0 0022DDA0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230FA4 0022DDA4  7C 08 02 A6 */	mflr r0
/* 80230FA8 0022DDA8  2C 03 00 05 */	cmpwi r3, 0x5
/* 80230FAC 0022DDAC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230FB0 0022DDB0  41 82 00 2C */	beq .L_80230FDC
/* 80230FB4 0022DDB4  4B FF C2 95 */	bl kar_plclearchecker_get_player_state
/* 80230FB8 0022DDB8  80 83 07 F8 */	lwz r4, 0x7f8(r3)
/* 80230FBC 0022DDBC  38 04 00 01 */	addi r0, r4, 0x1
/* 80230FC0 0022DDC0  90 03 07 F8 */	stw r0, 0x7f8(r3)
/* 80230FC4 0022DDC4  88 03 08 55 */	lbz r0, 0x855(r3)
/* 80230FC8 0022DDC8  54 00 D7 FF */	extrwi. r0, r0, 1, 25
/* 80230FCC 0022DDCC  40 82 00 10 */	bne .L_80230FDC
/* 80230FD0 0022DDD0  80 83 07 FC */	lwz r4, 0x7fc(r3)
/* 80230FD4 0022DDD4  38 04 00 01 */	addi r0, r4, 0x1
/* 80230FD8 0022DDD8  90 03 07 FC */	stw r0, 0x7fc(r3)
.L_80230FDC:
/* 80230FDC 0022DDDC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80230FE0 0022DDE0  7C 08 03 A6 */	mtlr r0
/* 80230FE4 0022DDE4  38 21 00 10 */	addi r1, r1, 0x10
/* 80230FE8 0022DDE8  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80230fa0

# .text:0x3178 | 0x80230FEC | size: 0x34
.fn kar_plclearcheckerlib__near_80230fec, global
/* 80230FEC 0022DDEC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80230FF0 0022DDF0  7C 08 02 A6 */	mflr r0
/* 80230FF4 0022DDF4  2C 03 00 05 */	cmpwi r3, 0x5
/* 80230FF8 0022DDF8  90 01 00 14 */	stw r0, 0x14(r1)
/* 80230FFC 0022DDFC  41 82 00 14 */	beq .L_80231010
/* 80231000 0022DE00  4B FF C2 49 */	bl kar_plclearchecker_get_player_state
/* 80231004 0022DE04  80 83 08 00 */	lwz r4, 0x800(r3)
/* 80231008 0022DE08  38 04 00 01 */	addi r0, r4, 0x1
/* 8023100C 0022DE0C  90 03 08 00 */	stw r0, 0x800(r3)
.L_80231010:
/* 80231010 0022DE10  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80231014 0022DE14  7C 08 03 A6 */	mtlr r0
/* 80231018 0022DE18  38 21 00 10 */	addi r1, r1, 0x10
/* 8023101C 0022DE1C  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80230fec

# .text:0x31AC | 0x80231020 | size: 0x34
.fn kar_plclearcheckerlib__near_80231020, global
/* 80231020 0022DE20  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80231024 0022DE24  7C 08 02 A6 */	mflr r0
/* 80231028 0022DE28  2C 03 00 05 */	cmpwi r3, 0x5
/* 8023102C 0022DE2C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80231030 0022DE30  41 82 00 14 */	beq .L_80231044
/* 80231034 0022DE34  4B FF C2 15 */	bl kar_plclearchecker_get_player_state
/* 80231038 0022DE38  80 83 08 10 */	lwz r4, 0x810(r3)
/* 8023103C 0022DE3C  38 04 00 01 */	addi r0, r4, 0x1
/* 80231040 0022DE40  90 03 08 10 */	stw r0, 0x810(r3)
.L_80231044:
/* 80231044 0022DE44  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80231048 0022DE48  7C 08 03 A6 */	mtlr r0
/* 8023104C 0022DE4C  38 21 00 10 */	addi r1, r1, 0x10
/* 80231050 0022DE50  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80231020

# .text:0x31E0 | 0x80231054 | size: 0x34
.fn kar_plclearcheckerlib__near_80231054, global
/* 80231054 0022DE54  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80231058 0022DE58  7C 08 02 A6 */	mflr r0
/* 8023105C 0022DE5C  2C 03 00 05 */	cmpwi r3, 0x5
/* 80231060 0022DE60  90 01 00 14 */	stw r0, 0x14(r1)
/* 80231064 0022DE64  41 82 00 14 */	beq .L_80231078
/* 80231068 0022DE68  4B FF C1 E1 */	bl kar_plclearchecker_get_player_state
/* 8023106C 0022DE6C  80 83 08 14 */	lwz r4, 0x814(r3)
/* 80231070 0022DE70  38 04 00 01 */	addi r0, r4, 0x1
/* 80231074 0022DE74  90 03 08 14 */	stw r0, 0x814(r3)
.L_80231078:
/* 80231078 0022DE78  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023107C 0022DE7C  7C 08 03 A6 */	mtlr r0
/* 80231080 0022DE80  38 21 00 10 */	addi r1, r1, 0x10
/* 80231084 0022DE84  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80231054

# .text:0x3214 | 0x80231088 | size: 0x58
.fn kar_plclearcheckerlib__near_80231088, global
/* 80231088 0022DE88  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023108C 0022DE8C  7C 08 02 A6 */	mflr r0
/* 80231090 0022DE90  90 01 00 14 */	stw r0, 0x14(r1)
/* 80231094 0022DE94  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80231098 0022DE98  7C 7F 1B 78 */	mr r31, r3
/* 8023109C 0022DE9C  2C 1F 00 05 */	cmpwi r31, 0x5
/* 802310A0 0022DEA0  41 82 00 2C */	beq .L_802310CC
/* 802310A4 0022DEA4  4B FF C1 A5 */	bl kar_plclearchecker_get_player_state
/* 802310A8 0022DEA8  88 03 08 55 */	lbz r0, 0x855(r3)
/* 802310AC 0022DEAC  54 00 D7 FF */	extrwi. r0, r0, 1, 25
/* 802310B0 0022DEB0  40 82 00 1C */	bne .L_802310CC
/* 802310B4 0022DEB4  7F E3 FB 78 */	mr r3, r31
/* 802310B8 0022DEB8  3B E0 00 01 */	li r31, 0x1
/* 802310BC 0022DEBC  4B FF C1 8D */	bl kar_plclearchecker_get_player_state
/* 802310C0 0022DEC0  88 03 08 4C */	lbz r0, 0x84c(r3)
/* 802310C4 0022DEC4  53 E0 36 72 */	rlwimi r0, r31, 6, 25, 25
/* 802310C8 0022DEC8  98 03 08 4C */	stb r0, 0x84c(r3)
.L_802310CC:
/* 802310CC 0022DECC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802310D0 0022DED0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802310D4 0022DED4  7C 08 03 A6 */	mtlr r0
/* 802310D8 0022DED8  38 21 00 10 */	addi r1, r1, 0x10
/* 802310DC 0022DEDC  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80231088

# .text:0x326C | 0x802310E0 | size: 0x40
.fn kar_plclearcheckerlib__near_802310e0, global
/* 802310E0 0022DEE0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802310E4 0022DEE4  7C 08 02 A6 */	mflr r0
/* 802310E8 0022DEE8  2C 03 00 05 */	cmpwi r3, 0x5
/* 802310EC 0022DEEC  90 01 00 14 */	stw r0, 0x14(r1)
/* 802310F0 0022DEF0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802310F4 0022DEF4  41 82 00 18 */	beq .L_8023110C
/* 802310F8 0022DEF8  3B E0 00 01 */	li r31, 0x1
/* 802310FC 0022DEFC  4B FF C1 4D */	bl kar_plclearchecker_get_player_state
/* 80231100 0022DF00  88 03 08 4C */	lbz r0, 0x84c(r3)
/* 80231104 0022DF04  53 E0 17 7A */	rlwimi r0, r31, 2, 29, 29
/* 80231108 0022DF08  98 03 08 4C */	stb r0, 0x84c(r3)
.L_8023110C:
/* 8023110C 0022DF0C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80231110 0022DF10  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80231114 0022DF14  7C 08 03 A6 */	mtlr r0
/* 80231118 0022DF18  38 21 00 10 */	addi r1, r1, 0x10
/* 8023111C 0022DF1C  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_802310e0

# .text:0x32AC | 0x80231120 | size: 0x40
.fn kar_plclearcheckerlib__near_80231120, global
/* 80231120 0022DF20  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80231124 0022DF24  7C 08 02 A6 */	mflr r0
/* 80231128 0022DF28  2C 03 00 05 */	cmpwi r3, 0x5
/* 8023112C 0022DF2C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80231130 0022DF30  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80231134 0022DF34  41 82 00 18 */	beq .L_8023114C
/* 80231138 0022DF38  3B E0 00 01 */	li r31, 0x1
/* 8023113C 0022DF3C  4B FF C1 0D */	bl kar_plclearchecker_get_player_state
/* 80231140 0022DF40  88 03 08 4C */	lbz r0, 0x84c(r3)
/* 80231144 0022DF44  53 E0 0F BC */	rlwimi r0, r31, 1, 30, 30
/* 80231148 0022DF48  98 03 08 4C */	stb r0, 0x84c(r3)
.L_8023114C:
/* 8023114C 0022DF4C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80231150 0022DF50  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80231154 0022DF54  7C 08 03 A6 */	mtlr r0
/* 80231158 0022DF58  38 21 00 10 */	addi r1, r1, 0x10
/* 8023115C 0022DF5C  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80231120

# .text:0x32EC | 0x80231160 | size: 0x38
.fn kar_plclearcheckerlib__near_80231160, global
/* 80231160 0022DF60  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80231164 0022DF64  7C 08 02 A6 */	mflr r0
/* 80231168 0022DF68  2C 03 00 05 */	cmpwi r3, 0x5
/* 8023116C 0022DF6C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80231170 0022DF70  41 82 00 18 */	beq .L_80231188
/* 80231174 0022DF74  4B FF C0 D5 */	bl kar_plclearchecker_get_player_state
/* 80231178 0022DF78  88 03 08 4C */	lbz r0, 0x84c(r3)
/* 8023117C 0022DF7C  38 80 00 01 */	li r4, 0x1
/* 80231180 0022DF80  50 80 07 FE */	rlwimi r0, r4, 0, 31, 31
/* 80231184 0022DF84  98 03 08 4C */	stb r0, 0x84c(r3)
.L_80231188:
/* 80231188 0022DF88  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023118C 0022DF8C  7C 08 03 A6 */	mtlr r0
/* 80231190 0022DF90  38 21 00 10 */	addi r1, r1, 0x10
/* 80231194 0022DF94  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80231160

# .text:0x3324 | 0x80231198 | size: 0x68
.fn kar_plclearcheckerlib__near_80231198, global
/* 80231198 0022DF98  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023119C 0022DF9C  7C 08 02 A6 */	mflr r0
/* 802311A0 0022DFA0  2C 03 00 05 */	cmpwi r3, 0x5
/* 802311A4 0022DFA4  90 01 00 14 */	stw r0, 0x14(r1)
/* 802311A8 0022DFA8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802311AC 0022DFAC  7C 9F 23 78 */	mr r31, r4
/* 802311B0 0022DFB0  41 82 00 3C */	beq .L_802311EC
/* 802311B4 0022DFB4  4B FF C0 95 */	bl kar_plclearchecker_get_player_state
/* 802311B8 0022DFB8  2C 1F 00 00 */	cmpwi r31, 0x0
/* 802311BC 0022DFBC  40 82 00 18 */	bne .L_802311D4
/* 802311C0 0022DFC0  88 03 08 4D */	lbz r0, 0x84d(r3)
/* 802311C4 0022DFC4  38 80 00 01 */	li r4, 0x1
/* 802311C8 0022DFC8  50 80 17 7A */	rlwimi r0, r4, 2, 29, 29
/* 802311CC 0022DFCC  98 03 08 4D */	stb r0, 0x84d(r3)
/* 802311D0 0022DFD0  48 00 00 1C */	b .L_802311EC
.L_802311D4:
/* 802311D4 0022DFD4  2C 1F 00 01 */	cmpwi r31, 0x1
/* 802311D8 0022DFD8  40 82 00 14 */	bne .L_802311EC
/* 802311DC 0022DFDC  88 03 08 4D */	lbz r0, 0x84d(r3)
/* 802311E0 0022DFE0  38 80 00 01 */	li r4, 0x1
/* 802311E4 0022DFE4  50 80 1F 38 */	rlwimi r0, r4, 3, 28, 28
/* 802311E8 0022DFE8  98 03 08 4D */	stb r0, 0x84d(r3)
.L_802311EC:
/* 802311EC 0022DFEC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802311F0 0022DFF0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802311F4 0022DFF4  7C 08 03 A6 */	mtlr r0
/* 802311F8 0022DFF8  38 21 00 10 */	addi r1, r1, 0x10
/* 802311FC 0022DFFC  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80231198

# .text:0x338C | 0x80231200 | size: 0x140
.fn kar_plclearcheckerlib__near_80231200, global
/* 80231200 0022E000  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80231204 0022E004  7C 08 02 A6 */	mflr r0
/* 80231208 0022E008  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023120C 0022E00C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80231210 0022E010  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80231214 0022E014  7C 7E 1B 78 */	mr r30, r3
/* 80231218 0022E018  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8023121C 0022E01C  93 81 00 10 */	stw r28, 0x10(r1)
/* 80231220 0022E020  4B FF C0 29 */	bl kar_plclearchecker_get_player_state
/* 80231224 0022E024  7C 7F 1B 78 */	mr r31, r3
/* 80231228 0022E028  80 63 06 04 */	lwz r3, 0x604(r3)
/* 8023122C 0022E02C  28 03 00 00 */	cmplwi r3, 0x0
/* 80231230 0022E030  41 82 00 0C */	beq .L_8023123C
/* 80231234 0022E034  38 03 FF FF */	subi r0, r3, 0x1
/* 80231238 0022E038  90 1F 06 04 */	stw r0, 0x604(r31)
.L_8023123C:
/* 8023123C 0022E03C  80 7F 06 08 */	lwz r3, 0x608(r31)
/* 80231240 0022E040  28 03 00 00 */	cmplwi r3, 0x0
/* 80231244 0022E044  41 82 00 0C */	beq .L_80231250
/* 80231248 0022E048  38 03 FF FF */	subi r0, r3, 0x1
/* 8023124C 0022E04C  90 1F 06 08 */	stw r0, 0x608(r31)
.L_80231250:
/* 80231250 0022E050  7F C3 F3 78 */	mr r3, r30
/* 80231254 0022E054  4B FF BF DD */	bl kar_plclearchecker_get_player_object
/* 80231258 0022E058  7C 7C 1B 79 */	mr. r28, r3
/* 8023125C 0022E05C  41 82 00 B0 */	beq .L_8023130C
/* 80231260 0022E060  4B FB 48 51 */	bl fn_801E5AB0
/* 80231264 0022E064  80 9C 00 2C */	lwz r4, 0x2c(r28)
/* 80231268 0022E068  7C 7D 1B 78 */	mr r29, r3
/* 8023126C 0022E06C  38 64 03 6C */	addi r3, r4, 0x36c
/* 80231270 0022E070  48 1A 0E E9 */	bl fn_803D2158
/* 80231274 0022E074  C8 02 C3 50 */	lfd f0, lbl_805E2A50@sda21(r0)
/* 80231278 0022E078  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8023127C 0022E07C  4C 41 13 82 */	cror eq, gt, eq
/* 80231280 0022E080  40 82 00 8C */	bne .L_8023130C
/* 80231284 0022E084  7F 83 E3 78 */	mr r3, r28
/* 80231288 0022E088  4B F9 69 E9 */	bl fn_801C7C70
/* 8023128C 0022E08C  2C 03 00 00 */	cmpwi r3, 0x0
/* 80231290 0022E090  40 82 00 1C */	bne .L_802312AC
/* 80231294 0022E094  80 7F 05 E4 */	lwz r3, 0x5e4(r31)
/* 80231298 0022E098  38 00 00 00 */	li r0, 0x0
/* 8023129C 0022E09C  38 63 00 01 */	addi r3, r3, 0x1
/* 802312A0 0022E0A0  90 7F 05 E4 */	stw r3, 0x5e4(r31)
/* 802312A4 0022E0A4  90 1F 05 F8 */	stw r0, 0x5f8(r31)
/* 802312A8 0022E0A8  48 00 00 30 */	b .L_802312D8
.L_802312AC:
/* 802312AC 0022E0AC  80 7F 05 E8 */	lwz r3, 0x5e8(r31)
/* 802312B0 0022E0B0  38 03 00 01 */	addi r0, r3, 0x1
/* 802312B4 0022E0B4  90 1F 05 E8 */	stw r0, 0x5e8(r31)
/* 802312B8 0022E0B8  80 7F 05 F8 */	lwz r3, 0x5f8(r31)
/* 802312BC 0022E0BC  38 03 00 01 */	addi r0, r3, 0x1
/* 802312C0 0022E0C0  90 1F 05 F8 */	stw r0, 0x5f8(r31)
/* 802312C4 0022E0C4  80 7F 05 F8 */	lwz r3, 0x5f8(r31)
/* 802312C8 0022E0C8  80 1F 05 F4 */	lwz r0, 0x5f4(r31)
/* 802312CC 0022E0CC  7C 03 00 40 */	cmplw r3, r0
/* 802312D0 0022E0D0  40 81 00 08 */	ble .L_802312D8
/* 802312D4 0022E0D4  90 7F 05 F4 */	stw r3, 0x5f4(r31)
.L_802312D8:
/* 802312D8 0022E0D8  88 1D 00 02 */	lbz r0, 0x2(r29)
/* 802312DC 0022E0DC  54 00 DF FF */	extrwi. r0, r0, 1, 26
/* 802312E0 0022E0E0  41 82 00 10 */	beq .L_802312F0
/* 802312E4 0022E0E4  80 7F 05 EC */	lwz r3, 0x5ec(r31)
/* 802312E8 0022E0E8  38 03 00 01 */	addi r0, r3, 0x1
/* 802312EC 0022E0EC  90 1F 05 EC */	stw r0, 0x5ec(r31)
.L_802312F0:
/* 802312F0 0022E0F0  7F 83 E3 78 */	mr r3, r28
/* 802312F4 0022E0F4  4B F9 6D 0D */	bl fn_801C8000
/* 802312F8 0022E0F8  2C 03 00 00 */	cmpwi r3, 0x0
/* 802312FC 0022E0FC  41 82 00 10 */	beq .L_8023130C
/* 80231300 0022E100  80 7F 05 F0 */	lwz r3, 0x5f0(r31)
/* 80231304 0022E104  38 03 00 01 */	addi r0, r3, 0x1
/* 80231308 0022E108  90 1F 05 F0 */	stw r0, 0x5f0(r31)
.L_8023130C:
/* 8023130C 0022E10C  7F C3 F3 78 */	mr r3, r30
/* 80231310 0022E110  4B FF B8 65 */	bl kar_cmreplay__8022cb74
/* 80231314 0022E114  28 03 00 00 */	cmplwi r3, 0x0
/* 80231318 0022E118  41 82 00 08 */	beq .L_80231320
/* 8023131C 0022E11C  4B F7 0D D9 */	bl fn_801A20F4
.L_80231320:
/* 80231320 0022E120  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80231324 0022E124  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80231328 0022E128  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8023132C 0022E12C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80231330 0022E130  83 81 00 10 */	lwz r28, 0x10(r1)
/* 80231334 0022E134  7C 08 03 A6 */	mtlr r0
/* 80231338 0022E138  38 21 00 20 */	addi r1, r1, 0x20
/* 8023133C 0022E13C  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80231200

# .text:0x34CC | 0x80231340 | size: 0x1D0
.fn kar_plclearcheckerlib__near_80231340, global
/* 80231340 0022E140  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80231344 0022E144  7C 08 02 A6 */	mflr r0
/* 80231348 0022E148  90 01 00 34 */	stw r0, 0x34(r1)
/* 8023134C 0022E14C  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 80231350 0022E150  F3 E1 00 28 */	psq_st f31, 0x28(r1), 0, qr0
/* 80231354 0022E154  39 61 00 20 */	addi r11, r1, 0x20
/* 80231358 0022E158  48 17 C7 FD */	bl _savegpr_27
/* 8023135C 0022E15C  7C 7F 1B 78 */	mr r31, r3
/* 80231360 0022E160  4B DD 7F 79 */	bl fn_800092D8
/* 80231364 0022E164  7C 63 07 74 */	extsb r3, r3
/* 80231368 0022E168  48 03 09 81 */	bl fn_80261CE8
/* 8023136C 0022E16C  7C 7C 1B 78 */	mr r28, r3
/* 80231370 0022E170  3B A0 00 00 */	li r29, 0x0
/* 80231374 0022E174  4B DD 95 E5 */	bl fn_8000A958
/* 80231378 0022E178  7C 60 07 75 */	extsb. r0, r3
/* 8023137C 0022E17C  41 82 00 14 */	beq .L_80231390
/* 80231380 0022E180  4B DD 95 D9 */	bl fn_8000A958
/* 80231384 0022E184  7C 60 07 74 */	extsb r0, r3
/* 80231388 0022E188  2C 00 00 04 */	cmpwi r0, 0x4
/* 8023138C 0022E18C  40 82 00 08 */	bne .L_80231394
.L_80231390:
/* 80231390 0022E190  3B A0 00 01 */	li r29, 0x1
.L_80231394:
/* 80231394 0022E194  7C 1D 00 D0 */	neg r0, r29
/* 80231398 0022E198  7C 00 EB 78 */	or r0, r0, r29
/* 8023139C 0022E19C  54 00 0F FF */	srwi. r0, r0, 31
/* 802313A0 0022E1A0  41 82 01 50 */	beq .L_802314F0
/* 802313A4 0022E1A4  7F E3 FB 78 */	mr r3, r31
/* 802313A8 0022E1A8  4B FF C0 8D */	bl kar_plclearcheckerlib__near_8022d434
/* 802313AC 0022E1AC  2C 03 00 00 */	cmpwi r3, 0x0
/* 802313B0 0022E1B0  40 82 01 40 */	bne .L_802314F0
/* 802313B4 0022E1B4  7F E3 FB 78 */	mr r3, r31
/* 802313B8 0022E1B8  4B FF B8 79 */	bl kar_cmreplay__8022cc30
/* 802313BC 0022E1BC  2C 03 00 00 */	cmpwi r3, 0x0
/* 802313C0 0022E1C0  40 82 01 30 */	bne .L_802314F0
/* 802313C4 0022E1C4  4B DD 95 B9 */	bl fn_8000A97C
/* 802313C8 0022E1C8  7C 60 07 75 */	extsb. r0, r3
/* 802313CC 0022E1CC  40 82 01 24 */	bne .L_802314F0
/* 802313D0 0022E1D0  7F E3 FB 78 */	mr r3, r31
/* 802313D4 0022E1D4  4B FF FE 2D */	bl kar_plclearcheckerlib__near_80231200
/* 802313D8 0022E1D8  7F E3 FB 78 */	mr r3, r31
/* 802313DC 0022E1DC  4B FF BE 6D */	bl kar_plclearchecker_get_player_state
/* 802313E0 0022E1E0  7C 7D 1B 78 */	mr r29, r3
/* 802313E4 0022E1E4  7F E3 FB 78 */	mr r3, r31
/* 802313E8 0022E1E8  4B FF BE 49 */	bl kar_plclearchecker_get_player_object
/* 802313EC 0022E1EC  28 03 00 00 */	cmplwi r3, 0x0
/* 802313F0 0022E1F0  41 82 00 AC */	beq .L_8023149C
/* 802313F4 0022E1F4  83 63 00 2C */	lwz r27, 0x2c(r3)
/* 802313F8 0022E1F8  4B FB 46 B9 */	bl fn_801E5AB0
/* 802313FC 0022E1FC  7C 7E 1B 78 */	mr r30, r3
/* 80231400 0022E200  38 7B 03 54 */	addi r3, r27, 0x354
/* 80231404 0022E204  48 1A 0D 55 */	bl fn_803D2158
/* 80231408 0022E208  FF E0 08 90 */	fmr f31, f1
/* 8023140C 0022E20C  38 7B 03 6C */	addi r3, r27, 0x36c
/* 80231410 0022E210  48 1A 0D 49 */	bl fn_803D2158
/* 80231414 0022E214  C0 1D 06 18 */	lfs f0, 0x618(r29)
/* 80231418 0022E218  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 8023141C 0022E21C  40 80 00 08 */	bge .L_80231424
/* 80231420 0022E220  D0 3D 06 18 */	stfs f1, 0x618(r29)
.L_80231424:
/* 80231424 0022E224  C0 02 C3 48 */	lfs f0, lbl_805E2A48@sda21(r0)
/* 80231428 0022E228  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 8023142C 0022E22C  41 82 00 28 */	beq .L_80231454
/* 80231430 0022E230  80 7D 06 00 */	lwz r3, 0x600(r29)
/* 80231434 0022E234  38 03 00 01 */	addi r0, r3, 0x1
/* 80231438 0022E238  90 1D 06 00 */	stw r0, 0x600(r29)
/* 8023143C 0022E23C  80 1D 05 FC */	lwz r0, 0x5fc(r29)
/* 80231440 0022E240  80 7D 06 00 */	lwz r3, 0x600(r29)
/* 80231444 0022E244  7C 00 18 40 */	cmplw r0, r3
/* 80231448 0022E248  40 80 00 14 */	bge .L_8023145C
/* 8023144C 0022E24C  90 7D 05 FC */	stw r3, 0x5fc(r29)
/* 80231450 0022E250  48 00 00 0C */	b .L_8023145C
.L_80231454:
/* 80231454 0022E254  38 00 00 00 */	li r0, 0x0
/* 80231458 0022E258  90 1D 06 00 */	stw r0, 0x600(r29)
.L_8023145C:
/* 8023145C 0022E25C  80 1B 07 54 */	lwz r0, 0x754(r27)
/* 80231460 0022E260  2C 00 00 00 */	cmpwi r0, 0x0
/* 80231464 0022E264  40 82 00 14 */	bne .L_80231478
/* 80231468 0022E268  C0 1D 06 0C */	lfs f0, 0x60c(r29)
/* 8023146C 0022E26C  EC 00 F8 2A */	fadds f0, f0, f31
/* 80231470 0022E270  D0 1D 06 0C */	stfs f0, 0x60c(r29)
/* 80231474 0022E274  48 00 00 10 */	b .L_80231484
.L_80231478:
/* 80231478 0022E278  C0 1D 06 10 */	lfs f0, 0x610(r29)
/* 8023147C 0022E27C  EC 00 F8 2A */	fadds f0, f0, f31
/* 80231480 0022E280  D0 1D 06 10 */	stfs f0, 0x610(r29)
.L_80231484:
/* 80231484 0022E284  88 1E 00 02 */	lbz r0, 0x2(r30)
/* 80231488 0022E288  54 00 DF FF */	extrwi. r0, r0, 1, 26
/* 8023148C 0022E28C  41 82 00 10 */	beq .L_8023149C
/* 80231490 0022E290  C0 1D 06 14 */	lfs f0, 0x614(r29)
/* 80231494 0022E294  EC 00 F8 2A */	fadds f0, f0, f31
/* 80231498 0022E298  D0 1D 06 14 */	stfs f0, 0x614(r29)
.L_8023149C:
/* 8023149C 0022E29C  7F E3 FB 78 */	mr r3, r31
/* 802314A0 0022E2A0  4B FF B6 D5 */	bl kar_cmreplay__8022cb74
/* 802314A4 0022E2A4  28 03 00 00 */	cmplwi r3, 0x0
/* 802314A8 0022E2A8  41 82 00 08 */	beq .L_802314B0
/* 802314AC 0022E2AC  4B F7 0C 49 */	bl fn_801A20F4
.L_802314B0:
/* 802314B0 0022E2B0  2C 1C 00 08 */	cmpwi r28, 0x8
/* 802314B4 0022E2B4  41 81 00 2C */	bgt .L_802314E0
/* 802314B8 0022E2B8  3C 60 80 4B */	lis r3, lbl_804B4CB8@ha
/* 802314BC 0022E2BC  57 80 10 3A */	slwi r0, r28, 2
/* 802314C0 0022E2C0  38 63 4C B8 */	addi r3, r3, lbl_804B4CB8@l
/* 802314C4 0022E2C4  7D 83 00 2E */	lwzx r12, r3, r0
/* 802314C8 0022E2C8  28 0C 00 00 */	cmplwi r12, 0x0
/* 802314CC 0022E2CC  41 82 00 24 */	beq .L_802314F0
/* 802314D0 0022E2D0  7F E3 FB 78 */	mr r3, r31
/* 802314D4 0022E2D4  7D 89 03 A6 */	mtctr r12
/* 802314D8 0022E2D8  4E 80 04 21 */	bctrl
/* 802314DC 0022E2DC  48 00 00 14 */	b .L_802314F0
.L_802314E0:
/* 802314E0 0022E2E0  2C 1C 00 09 */	cmpwi r28, 0x9
/* 802314E4 0022E2E4  40 82 00 0C */	bne .L_802314F0
/* 802314E8 0022E2E8  7F E3 FB 78 */	mr r3, r31
/* 802314EC 0022E2EC  48 00 02 91 */	bl kar_plclearcheckerlib__near_8023177c
.L_802314F0:
/* 802314F0 0022E2F0  E3 E1 00 28 */	psq_l f31, 0x28(r1), 0, qr0
/* 802314F4 0022E2F4  39 61 00 20 */	addi r11, r1, 0x20
/* 802314F8 0022E2F8  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 802314FC 0022E2FC  48 17 C6 A5 */	bl _restgpr_27
/* 80231500 0022E300  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80231504 0022E304  7C 08 03 A6 */	mtlr r0
/* 80231508 0022E308  38 21 00 30 */	addi r1, r1, 0x30
/* 8023150C 0022E30C  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80231340

# .text:0x369C | 0x80231510 | size: 0x5C
.fn kar_plclearcheckerlib__80231510, global
/* 80231510 0022E310  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80231514 0022E314  7C 08 02 A6 */	mflr r0
/* 80231518 0022E318  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023151C 0022E31C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80231520 0022E320  7C 7F 1B 78 */	mr r31, r3
/* 80231524 0022E324  2C 1F 00 05 */	cmpwi r31, 0x5
/* 80231528 0022E328  41 80 00 1C */	blt .L_80231544
/* 8023152C 0022E32C  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80231530 0022E330  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 80231534 0022E334  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 80231538 0022E338  38 80 08 EB */	li r4, 0x8eb
/* 8023153C 0022E33C  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80231540 0022E340  48 1F 6F 79 */	bl __assert
.L_80231544:
/* 80231544 0022E344  7F E3 FB 78 */	mr r3, r31
/* 80231548 0022E348  4B FF BD 01 */	bl kar_plclearchecker_get_player_state
/* 8023154C 0022E34C  80 83 05 E4 */	lwz r4, 0x5e4(r3)
/* 80231550 0022E350  80 03 05 E8 */	lwz r0, 0x5e8(r3)
/* 80231554 0022E354  7C 64 02 14 */	add r3, r4, r0
/* 80231558 0022E358  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023155C 0022E35C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80231560 0022E360  7C 08 03 A6 */	mtlr r0
/* 80231564 0022E364  38 21 00 10 */	addi r1, r1, 0x10
/* 80231568 0022E368  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__80231510

# .text:0x36F8 | 0x8023156C | size: 0x54
.fn kar_plclearcheckerlib__8023156c, global
/* 8023156C 0022E36C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80231570 0022E370  7C 08 02 A6 */	mflr r0
/* 80231574 0022E374  90 01 00 14 */	stw r0, 0x14(r1)
/* 80231578 0022E378  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023157C 0022E37C  7C 7F 1B 78 */	mr r31, r3
/* 80231580 0022E380  2C 1F 00 05 */	cmpwi r31, 0x5
/* 80231584 0022E384  41 80 00 1C */	blt .L_802315A0
/* 80231588 0022E388  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 8023158C 0022E38C  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 80231590 0022E390  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 80231594 0022E394  38 80 08 F6 */	li r4, 0x8f6
/* 80231598 0022E398  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 8023159C 0022E39C  48 1F 6F 1D */	bl __assert
.L_802315A0:
/* 802315A0 0022E3A0  7F E3 FB 78 */	mr r3, r31
/* 802315A4 0022E3A4  4B FF BC A5 */	bl kar_plclearchecker_get_player_state
/* 802315A8 0022E3A8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802315AC 0022E3AC  80 63 05 E8 */	lwz r3, 0x5e8(r3)
/* 802315B0 0022E3B0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802315B4 0022E3B4  7C 08 03 A6 */	mtlr r0
/* 802315B8 0022E3B8  38 21 00 10 */	addi r1, r1, 0x10
/* 802315BC 0022E3BC  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__8023156c

# .text:0x374C | 0x802315C0 | size: 0x54
.fn kar_plclearcheckerlib__802315c0, global
/* 802315C0 0022E3C0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802315C4 0022E3C4  7C 08 02 A6 */	mflr r0
/* 802315C8 0022E3C8  90 01 00 14 */	stw r0, 0x14(r1)
/* 802315CC 0022E3CC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802315D0 0022E3D0  7C 7F 1B 78 */	mr r31, r3
/* 802315D4 0022E3D4  2C 1F 00 05 */	cmpwi r31, 0x5
/* 802315D8 0022E3D8  41 80 00 1C */	blt .L_802315F4
/* 802315DC 0022E3DC  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 802315E0 0022E3E0  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 802315E4 0022E3E4  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 802315E8 0022E3E8  38 80 09 11 */	li r4, 0x911
/* 802315EC 0022E3EC  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 802315F0 0022E3F0  48 1F 6E C9 */	bl __assert
.L_802315F4:
/* 802315F4 0022E3F4  7F E3 FB 78 */	mr r3, r31
/* 802315F8 0022E3F8  4B FF BC 51 */	bl kar_plclearchecker_get_player_state
/* 802315FC 0022E3FC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80231600 0022E400  80 63 05 F4 */	lwz r3, 0x5f4(r3)
/* 80231604 0022E404  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80231608 0022E408  7C 08 03 A6 */	mtlr r0
/* 8023160C 0022E40C  38 21 00 10 */	addi r1, r1, 0x10
/* 80231610 0022E410  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__802315c0

# .text:0x37A0 | 0x80231614 | size: 0x5C
.fn kar_plclearcheckerlib__80231614, global
/* 80231614 0022E414  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80231618 0022E418  7C 08 02 A6 */	mflr r0
/* 8023161C 0022E41C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80231620 0022E420  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80231624 0022E424  7C 7F 1B 78 */	mr r31, r3
/* 80231628 0022E428  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8023162C 0022E42C  41 80 00 1C */	blt .L_80231648
/* 80231630 0022E430  3C 60 80 4B */	lis r3, kar_src_plclearcheckerlib_804b4cdc@ha
/* 80231634 0022E434  3C A0 80 4B */	lis r5, lbl_804B4CF0@ha
/* 80231638 0022E438  38 63 4C DC */	addi r3, r3, kar_src_plclearcheckerlib_804b4cdc@l
/* 8023163C 0022E43C  38 80 09 26 */	li r4, 0x926
/* 80231640 0022E440  38 A5 4C F0 */	addi r5, r5, lbl_804B4CF0@l
/* 80231644 0022E444  48 1F 6E 75 */	bl __assert
.L_80231648:
/* 80231648 0022E448  7F E3 FB 78 */	mr r3, r31
/* 8023164C 0022E44C  4B FF BB FD */	bl kar_plclearchecker_get_player_state
/* 80231650 0022E450  C0 23 06 0C */	lfs f1, 0x60c(r3)
/* 80231654 0022E454  C0 03 06 10 */	lfs f0, 0x610(r3)
/* 80231658 0022E458  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023165C 0022E45C  EC 21 00 2A */	fadds f1, f1, f0
/* 80231660 0022E460  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80231664 0022E464  7C 08 03 A6 */	mtlr r0
/* 80231668 0022E468  38 21 00 10 */	addi r1, r1, 0x10
/* 8023166C 0022E46C  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__80231614

# .text:0x37FC | 0x80231670 | size: 0x90
.fn kar_plclearcheckerlib__near_80231670, global
/* 80231670 0022E470  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80231674 0022E474  7C 08 02 A6 */	mflr r0
/* 80231678 0022E478  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023167C 0022E47C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80231680 0022E480  7C 7F 1B 78 */	mr r31, r3
/* 80231684 0022E484  4B FF BB AD */	bl kar_plclearchecker_get_player_object
/* 80231688 0022E488  28 03 00 00 */	cmplwi r3, 0x0
/* 8023168C 0022E48C  41 82 00 48 */	beq .L_802316D4
/* 80231690 0022E490  38 81 00 08 */	addi r4, r1, 0x8
/* 80231694 0022E494  4B F9 5F 95 */	bl fn_801C7628
/* 80231698 0022E498  38 61 00 08 */	addi r3, r1, 0x8
/* 8023169C 0022E49C  48 1A 0A BD */	bl fn_803D2158
/* 802316A0 0022E4A0  C8 42 C3 58 */	lfd f2, lbl_805E2A58@sda21(r0)
/* 802316A4 0022E4A4  C0 02 C3 60 */	lfs f0, lbl_805E2A60@sda21(r0)
/* 802316A8 0022E4A8  FC 21 10 24 */	fdiv f1, f1, f2
/* 802316AC 0022E4AC  FC 20 08 18 */	frsp f1, f1
/* 802316B0 0022E4B0  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 802316B4 0022E4B4  40 80 00 38 */	bge .L_802316EC
/* 802316B8 0022E4B8  7F E3 FB 78 */	mr r3, r31
/* 802316BC 0022E4BC  3B E0 00 00 */	li r31, 0x0
/* 802316C0 0022E4C0  4B FF BB 89 */	bl kar_plclearchecker_get_player_state
/* 802316C4 0022E4C4  88 03 08 4C */	lbz r0, 0x84c(r3)
/* 802316C8 0022E4C8  53 E0 26 F6 */	rlwimi r0, r31, 4, 27, 27
/* 802316CC 0022E4CC  98 03 08 4C */	stb r0, 0x84c(r3)
/* 802316D0 0022E4D0  48 00 00 1C */	b .L_802316EC
.L_802316D4:
/* 802316D4 0022E4D4  7F E3 FB 78 */	mr r3, r31
/* 802316D8 0022E4D8  3B E0 00 00 */	li r31, 0x0
/* 802316DC 0022E4DC  4B FF BB 6D */	bl kar_plclearchecker_get_player_state
/* 802316E0 0022E4E0  88 03 08 4C */	lbz r0, 0x84c(r3)
/* 802316E4 0022E4E4  53 E0 26 F6 */	rlwimi r0, r31, 4, 27, 27
/* 802316E8 0022E4E8  98 03 08 4C */	stb r0, 0x84c(r3)
.L_802316EC:
/* 802316EC 0022E4EC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 802316F0 0022E4F0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 802316F4 0022E4F4  7C 08 03 A6 */	mtlr r0
/* 802316F8 0022E4F8  38 21 00 20 */	addi r1, r1, 0x20
/* 802316FC 0022E4FC  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80231670

# .text:0x388C | 0x80231700 | size: 0x7C
.fn kar_plclearcheckerlib__near_80231700, global
/* 80231700 0022E500  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80231704 0022E504  7C 08 02 A6 */	mflr r0
/* 80231708 0022E508  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023170C 0022E50C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80231710 0022E510  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80231714 0022E514  7C 7E 1B 78 */	mr r30, r3
/* 80231718 0022E518  4B FF BB 19 */	bl kar_plclearchecker_get_player_object
/* 8023171C 0022E51C  7C 60 1B 78 */	mr r0, r3
/* 80231720 0022E520  7F C3 F3 78 */	mr r3, r30
/* 80231724 0022E524  7C 1E 03 78 */	mr r30, r0
/* 80231728 0022E528  4B FF BB 21 */	bl kar_plclearchecker_get_player_state
/* 8023172C 0022E52C  28 1E 00 00 */	cmplwi r30, 0x0
/* 80231730 0022E530  7C 7F 1B 78 */	mr r31, r3
/* 80231734 0022E534  41 82 00 30 */	beq .L_80231764
/* 80231738 0022E538  7F C3 F3 78 */	mr r3, r30
/* 8023173C 0022E53C  4B FB 43 75 */	bl fn_801E5AB0
/* 80231740 0022E540  88 03 00 03 */	lbz r0, 0x3(r3)
/* 80231744 0022E544  28 00 00 26 */	cmplwi r0, 0x26
/* 80231748 0022E548  40 82 00 1C */	bne .L_80231764
/* 8023174C 0022E54C  88 7F 08 4C */	lbz r3, 0x84c(r31)
/* 80231750 0022E550  54 60 EF FF */	extrwi. r0, r3, 1, 28
/* 80231754 0022E554  40 82 00 10 */	bne .L_80231764
/* 80231758 0022E558  38 00 00 01 */	li r0, 0x1
/* 8023175C 0022E55C  50 03 1F 38 */	rlwimi r3, r0, 3, 28, 28
/* 80231760 0022E560  98 7F 08 4C */	stb r3, 0x84c(r31)
.L_80231764:
/* 80231764 0022E564  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80231768 0022E568  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023176C 0022E56C  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80231770 0022E570  7C 08 03 A6 */	mtlr r0
/* 80231774 0022E574  38 21 00 10 */	addi r1, r1, 0x10
/* 80231778 0022E578  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80231700

# .text:0x3908 | 0x8023177C | size: 0x9C
.fn kar_plclearcheckerlib__near_8023177c, global
/* 8023177C 0022E57C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80231780 0022E580  7C 08 02 A6 */	mflr r0
/* 80231784 0022E584  90 01 00 14 */	stw r0, 0x14(r1)
/* 80231788 0022E588  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023178C 0022E58C  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80231790 0022E590  7C 7E 1B 78 */	mr r30, r3
/* 80231794 0022E594  4B FF BA 9D */	bl kar_plclearchecker_get_player_object
/* 80231798 0022E598  7C 60 1B 78 */	mr r0, r3
/* 8023179C 0022E59C  7F C3 F3 78 */	mr r3, r30
/* 802317A0 0022E5A0  7C 1E 03 78 */	mr r30, r0
/* 802317A4 0022E5A4  4B FF BA A5 */	bl kar_plclearchecker_get_player_state
/* 802317A8 0022E5A8  28 1E 00 00 */	cmplwi r30, 0x0
/* 802317AC 0022E5AC  7C 7F 1B 78 */	mr r31, r3
/* 802317B0 0022E5B0  41 82 00 50 */	beq .L_80231800
/* 802317B4 0022E5B4  7F C3 F3 78 */	mr r3, r30
/* 802317B8 0022E5B8  4B FB 42 F9 */	bl fn_801E5AB0
/* 802317BC 0022E5BC  88 03 00 03 */	lbz r0, 0x3(r3)
/* 802317C0 0022E5C0  28 00 00 26 */	cmplwi r0, 0x26
/* 802317C4 0022E5C4  40 82 00 2C */	bne .L_802317F0
/* 802317C8 0022E5C8  88 7F 08 4C */	lbz r3, 0x84c(r31)
/* 802317CC 0022E5CC  54 60 EF FF */	extrwi. r0, r3, 1, 28
/* 802317D0 0022E5D0  40 82 00 30 */	bne .L_80231800
/* 802317D4 0022E5D4  38 00 00 01 */	li r0, 0x1
/* 802317D8 0022E5D8  50 03 1F 38 */	rlwimi r3, r0, 3, 28, 28
/* 802317DC 0022E5DC  98 7F 08 4C */	stb r3, 0x84c(r31)
/* 802317E0 0022E5E0  80 7F 08 20 */	lwz r3, 0x820(r31)
/* 802317E4 0022E5E4  38 03 00 01 */	addi r0, r3, 0x1
/* 802317E8 0022E5E8  90 1F 08 20 */	stw r0, 0x820(r31)
/* 802317EC 0022E5EC  48 00 00 14 */	b .L_80231800
.L_802317F0:
/* 802317F0 0022E5F0  88 1F 08 4C */	lbz r0, 0x84c(r31)
/* 802317F4 0022E5F4  38 60 00 00 */	li r3, 0x0
/* 802317F8 0022E5F8  50 60 1F 38 */	rlwimi r0, r3, 3, 28, 28
/* 802317FC 0022E5FC  98 1F 08 4C */	stb r0, 0x84c(r31)
.L_80231800:
/* 80231800 0022E600  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80231804 0022E604  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80231808 0022E608  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8023180C 0022E60C  7C 08 03 A6 */	mtlr r0
/* 80231810 0022E610  38 21 00 10 */	addi r1, r1, 0x10
/* 80231814 0022E614  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_8023177c

# .text:0x39A4 | 0x80231818 | size: 0xC
.fn kar_plclearcheckerlib__near_80231818, global
/* 80231818 0022E618  38 00 00 01 */	li r0, 0x1
/* 8023181C 0022E61C  B0 0D 07 C0 */	sth r0, lbl_805DD8A0@sda21(r0)
/* 80231820 0022E620  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80231818

# .text:0x39B0 | 0x80231824 | size: 0x344
.fn kar_plclearcheckerlib__near_80231824, global
/* 80231824 0022E624  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80231828 0022E628  7C 08 02 A6 */	mflr r0
/* 8023182C 0022E62C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80231830 0022E630  4B FF BA 31 */	bl kar_plclearcheckerlib__8022d260
/* 80231834 0022E634  38 A0 00 00 */	li r5, 0x0
/* 80231838 0022E638  38 C0 00 18 */	li r6, 0x18
/* 8023183C 0022E63C  90 A3 00 00 */	stw r5, 0x0(r3)
/* 80231840 0022E640  54 C4 10 3A */	slwi r4, r6, 2
/* 80231844 0022E644  20 06 00 1B */	subfic r0, r6, 0x1b
/* 80231848 0022E648  90 A3 00 04 */	stw r5, 0x4(r3)
/* 8023184C 0022E64C  7C 83 22 14 */	add r4, r3, r4
/* 80231850 0022E650  90 A3 00 08 */	stw r5, 0x8(r3)
/* 80231854 0022E654  90 A3 00 0C */	stw r5, 0xc(r3)
/* 80231858 0022E658  90 A3 00 10 */	stw r5, 0x10(r3)
/* 8023185C 0022E65C  90 A3 00 14 */	stw r5, 0x14(r3)
/* 80231860 0022E660  90 A3 00 18 */	stw r5, 0x18(r3)
/* 80231864 0022E664  90 A3 00 1C */	stw r5, 0x1c(r3)
/* 80231868 0022E668  90 A3 00 20 */	stw r5, 0x20(r3)
/* 8023186C 0022E66C  90 A3 00 24 */	stw r5, 0x24(r3)
/* 80231870 0022E670  90 A3 00 28 */	stw r5, 0x28(r3)
/* 80231874 0022E674  90 A3 00 2C */	stw r5, 0x2c(r3)
/* 80231878 0022E678  90 A3 00 30 */	stw r5, 0x30(r3)
/* 8023187C 0022E67C  90 A3 00 34 */	stw r5, 0x34(r3)
/* 80231880 0022E680  90 A3 00 38 */	stw r5, 0x38(r3)
/* 80231884 0022E684  90 A3 00 3C */	stw r5, 0x3c(r3)
/* 80231888 0022E688  90 A3 00 40 */	stw r5, 0x40(r3)
/* 8023188C 0022E68C  90 A3 00 44 */	stw r5, 0x44(r3)
/* 80231890 0022E690  90 A3 00 48 */	stw r5, 0x48(r3)
/* 80231894 0022E694  90 A3 00 4C */	stw r5, 0x4c(r3)
/* 80231898 0022E698  90 A3 00 50 */	stw r5, 0x50(r3)
/* 8023189C 0022E69C  90 A3 00 54 */	stw r5, 0x54(r3)
/* 802318A0 0022E6A0  90 A3 00 58 */	stw r5, 0x58(r3)
/* 802318A4 0022E6A4  90 A3 00 5C */	stw r5, 0x5c(r3)
/* 802318A8 0022E6A8  90 A3 00 60 */	stw r5, 0x60(r3)
/* 802318AC 0022E6AC  7C 09 03 A6 */	mtctr r0
/* 802318B0 0022E6B0  2C 06 00 1B */	cmpwi r6, 0x1b
/* 802318B4 0022E6B4  40 80 00 0C */	bge .L_802318C0
.L_802318B8:
/* 802318B8 0022E6B8  94 A4 00 04 */	stwu r5, 0x4(r4)
/* 802318BC 0022E6BC  42 00 FF FC */	bdnz .L_802318B8
.L_802318C0:
/* 802318C0 0022E6C0  38 A0 00 00 */	li r5, 0x0
/* 802318C4 0022E6C4  38 C0 00 18 */	li r6, 0x18
/* 802318C8 0022E6C8  90 A3 00 70 */	stw r5, 0x70(r3)
/* 802318CC 0022E6CC  54 C4 10 3A */	slwi r4, r6, 2
/* 802318D0 0022E6D0  20 06 00 1B */	subfic r0, r6, 0x1b
/* 802318D4 0022E6D4  90 A3 00 74 */	stw r5, 0x74(r3)
/* 802318D8 0022E6D8  7C 83 22 14 */	add r4, r3, r4
/* 802318DC 0022E6DC  90 A3 00 78 */	stw r5, 0x78(r3)
/* 802318E0 0022E6E0  90 A3 00 7C */	stw r5, 0x7c(r3)
/* 802318E4 0022E6E4  90 A3 00 80 */	stw r5, 0x80(r3)
/* 802318E8 0022E6E8  90 A3 00 84 */	stw r5, 0x84(r3)
/* 802318EC 0022E6EC  90 A3 00 88 */	stw r5, 0x88(r3)
/* 802318F0 0022E6F0  90 A3 00 8C */	stw r5, 0x8c(r3)
/* 802318F4 0022E6F4  90 A3 00 90 */	stw r5, 0x90(r3)
/* 802318F8 0022E6F8  90 A3 00 94 */	stw r5, 0x94(r3)
/* 802318FC 0022E6FC  90 A3 00 98 */	stw r5, 0x98(r3)
/* 80231900 0022E700  90 A3 00 9C */	stw r5, 0x9c(r3)
/* 80231904 0022E704  90 A3 00 A0 */	stw r5, 0xa0(r3)
/* 80231908 0022E708  90 A3 00 A4 */	stw r5, 0xa4(r3)
/* 8023190C 0022E70C  90 A3 00 A8 */	stw r5, 0xa8(r3)
/* 80231910 0022E710  90 A3 00 AC */	stw r5, 0xac(r3)
/* 80231914 0022E714  90 A3 00 B0 */	stw r5, 0xb0(r3)
/* 80231918 0022E718  90 A3 00 B4 */	stw r5, 0xb4(r3)
/* 8023191C 0022E71C  90 A3 00 B8 */	stw r5, 0xb8(r3)
/* 80231920 0022E720  90 A3 00 BC */	stw r5, 0xbc(r3)
/* 80231924 0022E724  90 A3 00 C0 */	stw r5, 0xc0(r3)
/* 80231928 0022E728  90 A3 00 C4 */	stw r5, 0xc4(r3)
/* 8023192C 0022E72C  90 A3 00 C8 */	stw r5, 0xc8(r3)
/* 80231930 0022E730  90 A3 00 CC */	stw r5, 0xcc(r3)
/* 80231934 0022E734  90 A3 00 D0 */	stw r5, 0xd0(r3)
/* 80231938 0022E738  7C 09 03 A6 */	mtctr r0
/* 8023193C 0022E73C  2C 06 00 1B */	cmpwi r6, 0x1b
/* 80231940 0022E740  40 80 00 10 */	bge .L_80231950
.L_80231944:
/* 80231944 0022E744  90 A4 00 74 */	stw r5, 0x74(r4)
/* 80231948 0022E748  38 84 00 04 */	addi r4, r4, 0x4
/* 8023194C 0022E74C  42 00 FF F8 */	bdnz .L_80231944
.L_80231950:
/* 80231950 0022E750  38 A0 00 00 */	li r5, 0x0
/* 80231954 0022E754  38 C0 00 18 */	li r6, 0x18
/* 80231958 0022E758  90 A3 00 E0 */	stw r5, 0xe0(r3)
/* 8023195C 0022E75C  54 C4 10 3A */	slwi r4, r6, 2
/* 80231960 0022E760  20 06 00 1B */	subfic r0, r6, 0x1b
/* 80231964 0022E764  90 A3 00 E4 */	stw r5, 0xe4(r3)
/* 80231968 0022E768  7C 83 22 14 */	add r4, r3, r4
/* 8023196C 0022E76C  90 A3 00 E8 */	stw r5, 0xe8(r3)
/* 80231970 0022E770  90 A3 00 EC */	stw r5, 0xec(r3)
/* 80231974 0022E774  90 A3 00 F0 */	stw r5, 0xf0(r3)
/* 80231978 0022E778  90 A3 00 F4 */	stw r5, 0xf4(r3)
/* 8023197C 0022E77C  90 A3 00 F8 */	stw r5, 0xf8(r3)
/* 80231980 0022E780  90 A3 00 FC */	stw r5, 0xfc(r3)
/* 80231984 0022E784  90 A3 01 00 */	stw r5, 0x100(r3)
/* 80231988 0022E788  90 A3 01 04 */	stw r5, 0x104(r3)
/* 8023198C 0022E78C  90 A3 01 08 */	stw r5, 0x108(r3)
/* 80231990 0022E790  90 A3 01 0C */	stw r5, 0x10c(r3)
/* 80231994 0022E794  90 A3 01 10 */	stw r5, 0x110(r3)
/* 80231998 0022E798  90 A3 01 14 */	stw r5, 0x114(r3)
/* 8023199C 0022E79C  90 A3 01 18 */	stw r5, 0x118(r3)
/* 802319A0 0022E7A0  90 A3 01 1C */	stw r5, 0x11c(r3)
/* 802319A4 0022E7A4  90 A3 01 20 */	stw r5, 0x120(r3)
/* 802319A8 0022E7A8  90 A3 01 24 */	stw r5, 0x124(r3)
/* 802319AC 0022E7AC  90 A3 01 28 */	stw r5, 0x128(r3)
/* 802319B0 0022E7B0  90 A3 01 2C */	stw r5, 0x12c(r3)
/* 802319B4 0022E7B4  90 A3 01 30 */	stw r5, 0x130(r3)
/* 802319B8 0022E7B8  90 A3 01 34 */	stw r5, 0x134(r3)
/* 802319BC 0022E7BC  90 A3 01 38 */	stw r5, 0x138(r3)
/* 802319C0 0022E7C0  90 A3 01 3C */	stw r5, 0x13c(r3)
/* 802319C4 0022E7C4  90 A3 01 40 */	stw r5, 0x140(r3)
/* 802319C8 0022E7C8  7C 09 03 A6 */	mtctr r0
/* 802319CC 0022E7CC  2C 06 00 1B */	cmpwi r6, 0x1b
/* 802319D0 0022E7D0  40 80 00 10 */	bge .L_802319E0
.L_802319D4:
/* 802319D4 0022E7D4  90 A4 00 E4 */	stw r5, 0xe4(r4)
/* 802319D8 0022E7D8  38 84 00 04 */	addi r4, r4, 0x4
/* 802319DC 0022E7DC  42 00 FF F8 */	bdnz .L_802319D4
.L_802319E0:
/* 802319E0 0022E7E0  38 00 00 03 */	li r0, 0x3
/* 802319E4 0022E7E4  7C 64 1B 78 */	mr r4, r3
/* 802319E8 0022E7E8  38 E0 00 00 */	li r7, 0x0
/* 802319EC 0022E7EC  7C 09 03 A6 */	mtctr r0
/* 802319F0 0022E7F0  38 A0 00 00 */	li r5, 0x0
.L_802319F4:
/* 802319F4 0022E7F4  38 C7 01 BC */	addi r6, r7, 0x1bc
/* 802319F8 0022E7F8  90 A4 01 50 */	stw r5, 0x150(r4)
/* 802319FC 0022E7FC  7C C3 32 14 */	add r6, r3, r6
/* 80231A00 0022E800  38 E7 00 08 */	addi r7, r7, 0x8
/* 80231A04 0022E804  98 A6 00 00 */	stb r5, 0x0(r6)
/* 80231A08 0022E808  90 A4 01 54 */	stw r5, 0x154(r4)
/* 80231A0C 0022E80C  98 A6 00 01 */	stb r5, 0x1(r6)
/* 80231A10 0022E810  90 A4 01 58 */	stw r5, 0x158(r4)
/* 80231A14 0022E814  98 A6 00 02 */	stb r5, 0x2(r6)
/* 80231A18 0022E818  90 A4 01 5C */	stw r5, 0x15c(r4)
/* 80231A1C 0022E81C  98 A6 00 03 */	stb r5, 0x3(r6)
/* 80231A20 0022E820  90 A4 01 60 */	stw r5, 0x160(r4)
/* 80231A24 0022E824  98 A6 00 04 */	stb r5, 0x4(r6)
/* 80231A28 0022E828  90 A4 01 64 */	stw r5, 0x164(r4)
/* 80231A2C 0022E82C  98 A6 00 05 */	stb r5, 0x5(r6)
/* 80231A30 0022E830  90 A4 01 68 */	stw r5, 0x168(r4)
/* 80231A34 0022E834  98 A6 00 06 */	stb r5, 0x6(r6)
/* 80231A38 0022E838  90 A4 01 6C */	stw r5, 0x16c(r4)
/* 80231A3C 0022E83C  38 84 00 20 */	addi r4, r4, 0x20
/* 80231A40 0022E840  98 A6 00 07 */	stb r5, 0x7(r6)
/* 80231A44 0022E844  42 00 FF B0 */	bdnz .L_802319F4
/* 80231A48 0022E848  54 E4 10 3A */	slwi r4, r7, 2
/* 80231A4C 0022E84C  20 07 00 1B */	subfic r0, r7, 0x1b
/* 80231A50 0022E850  7C 83 22 14 */	add r4, r3, r4
/* 80231A54 0022E854  7C 09 03 A6 */	mtctr r0
/* 80231A58 0022E858  2C 07 00 1B */	cmpwi r7, 0x1b
/* 80231A5C 0022E85C  40 80 00 1C */	bge .L_80231A78
.L_80231A60:
/* 80231A60 0022E860  90 A4 01 50 */	stw r5, 0x150(r4)
/* 80231A64 0022E864  38 07 01 BC */	addi r0, r7, 0x1bc
/* 80231A68 0022E868  38 84 00 04 */	addi r4, r4, 0x4
/* 80231A6C 0022E86C  38 E7 00 01 */	addi r7, r7, 0x1
/* 80231A70 0022E870  7C A3 01 AE */	stbx r5, r3, r0
/* 80231A74 0022E874  42 00 FF EC */	bdnz .L_80231A60
.L_80231A78:
/* 80231A78 0022E878  38 A0 00 00 */	li r5, 0x0
/* 80231A7C 0022E87C  38 C0 00 0C */	li r6, 0xc
/* 80231A80 0022E880  90 A3 01 D8 */	stw r5, 0x1d8(r3)
/* 80231A84 0022E884  54 C4 10 3A */	slwi r4, r6, 2
/* 80231A88 0022E888  20 06 00 0D */	subfic r0, r6, 0xd
/* 80231A8C 0022E88C  90 A3 01 DC */	stw r5, 0x1dc(r3)
/* 80231A90 0022E890  7C 83 22 14 */	add r4, r3, r4
/* 80231A94 0022E894  90 A3 01 E0 */	stw r5, 0x1e0(r3)
/* 80231A98 0022E898  90 A3 01 E4 */	stw r5, 0x1e4(r3)
/* 80231A9C 0022E89C  90 A3 01 E8 */	stw r5, 0x1e8(r3)
/* 80231AA0 0022E8A0  90 A3 01 EC */	stw r5, 0x1ec(r3)
/* 80231AA4 0022E8A4  90 A3 01 F0 */	stw r5, 0x1f0(r3)
/* 80231AA8 0022E8A8  90 A3 01 F4 */	stw r5, 0x1f4(r3)
/* 80231AAC 0022E8AC  90 A3 01 F8 */	stw r5, 0x1f8(r3)
/* 80231AB0 0022E8B0  90 A3 01 FC */	stw r5, 0x1fc(r3)
/* 80231AB4 0022E8B4  90 A3 02 00 */	stw r5, 0x200(r3)
/* 80231AB8 0022E8B8  90 A3 02 04 */	stw r5, 0x204(r3)
/* 80231ABC 0022E8BC  7C 09 03 A6 */	mtctr r0
/* 80231AC0 0022E8C0  2C 06 00 0D */	cmpwi r6, 0xd
/* 80231AC4 0022E8C4  40 80 00 10 */	bge .L_80231AD4
.L_80231AC8:
/* 80231AC8 0022E8C8  90 A4 01 D8 */	stw r5, 0x1d8(r4)
/* 80231ACC 0022E8CC  38 84 00 04 */	addi r4, r4, 0x4
/* 80231AD0 0022E8D0  42 00 FF F8 */	bdnz .L_80231AC8
.L_80231AD4:
/* 80231AD4 0022E8D4  38 00 00 03 */	li r0, 0x3
/* 80231AD8 0022E8D8  7C 65 1B 78 */	mr r5, r3
/* 80231ADC 0022E8DC  38 80 00 00 */	li r4, 0x0
/* 80231AE0 0022E8E0  7C 09 03 A6 */	mtctr r0
.L_80231AE4:
/* 80231AE4 0022E8E4  90 85 02 10 */	stw r4, 0x210(r5)
/* 80231AE8 0022E8E8  90 85 02 14 */	stw r4, 0x214(r5)
/* 80231AEC 0022E8EC  90 85 02 18 */	stw r4, 0x218(r5)
/* 80231AF0 0022E8F0  90 85 02 1C */	stw r4, 0x21c(r5)
/* 80231AF4 0022E8F4  90 85 02 20 */	stw r4, 0x220(r5)
/* 80231AF8 0022E8F8  90 85 02 24 */	stw r4, 0x224(r5)
/* 80231AFC 0022E8FC  90 85 02 28 */	stw r4, 0x228(r5)
/* 80231B00 0022E900  90 85 02 2C */	stw r4, 0x22c(r5)
/* 80231B04 0022E904  90 85 02 30 */	stw r4, 0x230(r5)
/* 80231B08 0022E908  90 85 02 34 */	stw r4, 0x234(r5)
/* 80231B0C 0022E90C  90 85 02 38 */	stw r4, 0x238(r5)
/* 80231B10 0022E910  90 85 02 3C */	stw r4, 0x23c(r5)
/* 80231B14 0022E914  90 85 02 40 */	stw r4, 0x240(r5)
/* 80231B18 0022E918  90 85 02 44 */	stw r4, 0x244(r5)
/* 80231B1C 0022E91C  90 85 02 48 */	stw r4, 0x248(r5)
/* 80231B20 0022E920  90 85 02 4C */	stw r4, 0x24c(r5)
/* 80231B24 0022E924  90 85 02 50 */	stw r4, 0x250(r5)
/* 80231B28 0022E928  90 85 02 54 */	stw r4, 0x254(r5)
/* 80231B2C 0022E92C  90 85 02 58 */	stw r4, 0x258(r5)
/* 80231B30 0022E930  90 85 02 5C */	stw r4, 0x25c(r5)
/* 80231B34 0022E934  90 85 02 60 */	stw r4, 0x260(r5)
/* 80231B38 0022E938  90 85 02 64 */	stw r4, 0x264(r5)
/* 80231B3C 0022E93C  90 85 02 68 */	stw r4, 0x268(r5)
/* 80231B40 0022E940  90 85 02 6C */	stw r4, 0x26c(r5)
/* 80231B44 0022E944  38 A5 00 60 */	addi r5, r5, 0x60
/* 80231B48 0022E948  42 00 FF 9C */	bdnz .L_80231AE4
/* 80231B4C 0022E94C  38 00 00 00 */	li r0, 0x0
/* 80231B50 0022E950  98 03 03 30 */	stb r0, 0x330(r3)
/* 80231B54 0022E954  98 03 03 31 */	stb r0, 0x331(r3)
/* 80231B58 0022E958  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80231B5C 0022E95C  7C 08 03 A6 */	mtlr r0
/* 80231B60 0022E960  38 21 00 10 */	addi r1, r1, 0x10
/* 80231B64 0022E964  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80231824

# .text:0x3CF4 | 0x80231B68 | size: 0x20
.fn kar_plclearcheckerlib__near_80231b68, global
/* 80231B68 0022E968  A0 6D 07 C0 */	lhz r3, lbl_805DD8A0@sda21(r0)
/* 80231B6C 0022E96C  38 83 00 01 */	addi r4, r3, 0x1
/* 80231B70 0022E970  54 80 04 3F */	clrlwi. r0, r4, 16
/* 80231B74 0022E974  B0 8D 07 C0 */	sth r4, lbl_805DD8A0@sda21(r0)
/* 80231B78 0022E978  4C 82 00 20 */	bnelr
/* 80231B7C 0022E97C  38 00 00 01 */	li r0, 0x1
/* 80231B80 0022E980  B0 0D 07 C0 */	sth r0, lbl_805DD8A0@sda21(r0)
/* 80231B84 0022E984  4E 80 00 20 */	blr
.endfn kar_plclearcheckerlib__near_80231b68
