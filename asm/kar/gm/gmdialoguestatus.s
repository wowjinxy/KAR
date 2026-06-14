.include "macros.inc"
.file "gmdialoguestatus.c"

# 0x80048C2C..0x80049198 | size: 0x56C
.text
.balign 4

# .text:0x0 | 0x80048C2C | size: 0x38
.fn kar_gmdialoguestatus__near_80048c2c, global
/* 80048C2C 00045A2C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80048C30 00045A30  7C 08 02 A6 */	mflr r0
/* 80048C34 00045A34  90 01 00 14 */	stw r0, 0x14(r1)
/* 80048C38 00045A38  4B FF EC 0D */	bl kar_diagnostic__80047844
/* 80048C3C 00045A3C  38 00 00 00 */	li r0, 0x0
/* 80048C40 00045A40  38 80 00 0D */	li r4, 0xd
/* 80048C44 00045A44  98 03 00 01 */	stb r0, 0x1(r3)
/* 80048C48 00045A48  38 00 00 01 */	li r0, 0x1
/* 80048C4C 00045A4C  98 83 00 02 */	stb r4, 0x2(r3)
/* 80048C50 00045A50  98 03 00 06 */	stb r0, 0x6(r3)
/* 80048C54 00045A54  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80048C58 00045A58  7C 08 03 A6 */	mtlr r0
/* 80048C5C 00045A5C  38 21 00 10 */	addi r1, r1, 0x10
/* 80048C60 00045A60  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80048c2c

# .text:0x38 | 0x80048C64 | size: 0x38
.fn kar_gmdialoguestatus__near_80048c64, global
/* 80048C64 00045A64  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80048C68 00045A68  7C 08 02 A6 */	mflr r0
/* 80048C6C 00045A6C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80048C70 00045A70  4B FF EB D5 */	bl kar_diagnostic__80047844
/* 80048C74 00045A74  38 00 00 01 */	li r0, 0x1
/* 80048C78 00045A78  38 80 00 0E */	li r4, 0xe
/* 80048C7C 00045A7C  98 03 00 01 */	stb r0, 0x1(r3)
/* 80048C80 00045A80  38 00 00 00 */	li r0, 0x0
/* 80048C84 00045A84  98 83 00 02 */	stb r4, 0x2(r3)
/* 80048C88 00045A88  98 03 00 06 */	stb r0, 0x6(r3)
/* 80048C8C 00045A8C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80048C90 00045A90  7C 08 03 A6 */	mtlr r0
/* 80048C94 00045A94  38 21 00 10 */	addi r1, r1, 0x10
/* 80048C98 00045A98  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80048c64

# .text:0x70 | 0x80048C9C | size: 0x38
.fn kar_gmdialoguestatus__near_80048c9c, global
/* 80048C9C 00045A9C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80048CA0 00045AA0  7C 08 02 A6 */	mflr r0
/* 80048CA4 00045AA4  90 01 00 14 */	stw r0, 0x14(r1)
/* 80048CA8 00045AA8  4B FF EB 9D */	bl kar_diagnostic__80047844
/* 80048CAC 00045AAC  38 00 00 01 */	li r0, 0x1
/* 80048CB0 00045AB0  38 80 00 0F */	li r4, 0xf
/* 80048CB4 00045AB4  98 03 00 01 */	stb r0, 0x1(r3)
/* 80048CB8 00045AB8  38 00 00 00 */	li r0, 0x0
/* 80048CBC 00045ABC  98 83 00 02 */	stb r4, 0x2(r3)
/* 80048CC0 00045AC0  98 03 00 06 */	stb r0, 0x6(r3)
/* 80048CC4 00045AC4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80048CC8 00045AC8  7C 08 03 A6 */	mtlr r0
/* 80048CCC 00045ACC  38 21 00 10 */	addi r1, r1, 0x10
/* 80048CD0 00045AD0  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80048c9c

# .text:0xA8 | 0x80048CD4 | size: 0x48
.fn kar_gmdialoguestatus__near_80048cd4, global
/* 80048CD4 00045AD4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80048CD8 00045AD8  7C 08 02 A6 */	mflr r0
/* 80048CDC 00045ADC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80048CE0 00045AE0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80048CE4 00045AE4  4B FF EB 61 */	bl kar_diagnostic__80047844
/* 80048CE8 00045AE8  7C 7F 1B 78 */	mr r31, r3
/* 80048CEC 00045AEC  4B FF EB 79 */	bl kar_gmdialogue__near_80047864
/* 80048CF0 00045AF0  38 00 00 01 */	li r0, 0x1
/* 80048CF4 00045AF4  38 60 00 10 */	li r3, 0x10
/* 80048CF8 00045AF8  98 1F 00 01 */	stb r0, 0x1(r31)
/* 80048CFC 00045AFC  38 00 00 00 */	li r0, 0x0
/* 80048D00 00045B00  98 7F 00 02 */	stb r3, 0x2(r31)
/* 80048D04 00045B04  98 1F 00 06 */	stb r0, 0x6(r31)
/* 80048D08 00045B08  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80048D0C 00045B0C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80048D10 00045B10  7C 08 03 A6 */	mtlr r0
/* 80048D14 00045B14  38 21 00 10 */	addi r1, r1, 0x10
/* 80048D18 00045B18  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80048cd4

# .text:0xF0 | 0x80048D1C | size: 0x38
.fn kar_gmdialoguestatus__near_80048d1c, global
/* 80048D1C 00045B1C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80048D20 00045B20  7C 08 02 A6 */	mflr r0
/* 80048D24 00045B24  90 01 00 14 */	stw r0, 0x14(r1)
/* 80048D28 00045B28  4B FF EB 1D */	bl kar_diagnostic__80047844
/* 80048D2C 00045B2C  38 00 00 01 */	li r0, 0x1
/* 80048D30 00045B30  38 80 00 11 */	li r4, 0x11
/* 80048D34 00045B34  98 03 00 01 */	stb r0, 0x1(r3)
/* 80048D38 00045B38  38 00 00 00 */	li r0, 0x0
/* 80048D3C 00045B3C  98 83 00 02 */	stb r4, 0x2(r3)
/* 80048D40 00045B40  98 03 00 06 */	stb r0, 0x6(r3)
/* 80048D44 00045B44  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80048D48 00045B48  7C 08 03 A6 */	mtlr r0
/* 80048D4C 00045B4C  38 21 00 10 */	addi r1, r1, 0x10
/* 80048D50 00045B50  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80048d1c

# .text:0x128 | 0x80048D54 | size: 0x38
.fn kar_gmdialoguestatus__near_80048d54, global
/* 80048D54 00045B54  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80048D58 00045B58  7C 08 02 A6 */	mflr r0
/* 80048D5C 00045B5C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80048D60 00045B60  4B FF EA E5 */	bl kar_diagnostic__80047844
/* 80048D64 00045B64  38 00 00 01 */	li r0, 0x1
/* 80048D68 00045B68  38 80 00 12 */	li r4, 0x12
/* 80048D6C 00045B6C  98 03 00 01 */	stb r0, 0x1(r3)
/* 80048D70 00045B70  38 00 00 00 */	li r0, 0x0
/* 80048D74 00045B74  98 83 00 02 */	stb r4, 0x2(r3)
/* 80048D78 00045B78  98 03 00 06 */	stb r0, 0x6(r3)
/* 80048D7C 00045B7C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80048D80 00045B80  7C 08 03 A6 */	mtlr r0
/* 80048D84 00045B84  38 21 00 10 */	addi r1, r1, 0x10
/* 80048D88 00045B88  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80048d54

# .text:0x160 | 0x80048D8C | size: 0x34
.fn kar_gmdialoguestatus__near_80048d8c, global
/* 80048D8C 00045B8C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80048D90 00045B90  7C 08 02 A6 */	mflr r0
/* 80048D94 00045B94  90 01 00 14 */	stw r0, 0x14(r1)
/* 80048D98 00045B98  4B FF EA AD */	bl kar_diagnostic__80047844
/* 80048D9C 00045B9C  38 80 00 01 */	li r4, 0x1
/* 80048DA0 00045BA0  38 00 00 13 */	li r0, 0x13
/* 80048DA4 00045BA4  98 83 00 01 */	stb r4, 0x1(r3)
/* 80048DA8 00045BA8  98 03 00 02 */	stb r0, 0x2(r3)
/* 80048DAC 00045BAC  98 83 00 06 */	stb r4, 0x6(r3)
/* 80048DB0 00045BB0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80048DB4 00045BB4  7C 08 03 A6 */	mtlr r0
/* 80048DB8 00045BB8  38 21 00 10 */	addi r1, r1, 0x10
/* 80048DBC 00045BBC  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80048d8c

# .text:0x194 | 0x80048DC0 | size: 0x38
.fn kar_gmdialoguestatus__near_80048dc0, global
/* 80048DC0 00045BC0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80048DC4 00045BC4  7C 08 02 A6 */	mflr r0
/* 80048DC8 00045BC8  90 01 00 14 */	stw r0, 0x14(r1)
/* 80048DCC 00045BCC  4B FF EA 79 */	bl kar_diagnostic__80047844
/* 80048DD0 00045BD0  38 00 00 01 */	li r0, 0x1
/* 80048DD4 00045BD4  38 80 00 14 */	li r4, 0x14
/* 80048DD8 00045BD8  98 03 00 01 */	stb r0, 0x1(r3)
/* 80048DDC 00045BDC  38 00 00 00 */	li r0, 0x0
/* 80048DE0 00045BE0  98 83 00 02 */	stb r4, 0x2(r3)
/* 80048DE4 00045BE4  98 03 00 06 */	stb r0, 0x6(r3)
/* 80048DE8 00045BE8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80048DEC 00045BEC  7C 08 03 A6 */	mtlr r0
/* 80048DF0 00045BF0  38 21 00 10 */	addi r1, r1, 0x10
/* 80048DF4 00045BF4  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80048dc0

# .text:0x1CC | 0x80048DF8 | size: 0x38
.fn kar_gmdialoguestatus__near_80048df8, global
/* 80048DF8 00045BF8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80048DFC 00045BFC  7C 08 02 A6 */	mflr r0
/* 80048E00 00045C00  90 01 00 14 */	stw r0, 0x14(r1)
/* 80048E04 00045C04  4B FF EA 41 */	bl kar_diagnostic__80047844
/* 80048E08 00045C08  38 00 00 01 */	li r0, 0x1
/* 80048E0C 00045C0C  38 80 00 15 */	li r4, 0x15
/* 80048E10 00045C10  98 03 00 01 */	stb r0, 0x1(r3)
/* 80048E14 00045C14  38 00 00 00 */	li r0, 0x0
/* 80048E18 00045C18  98 83 00 02 */	stb r4, 0x2(r3)
/* 80048E1C 00045C1C  98 03 00 06 */	stb r0, 0x6(r3)
/* 80048E20 00045C20  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80048E24 00045C24  7C 08 03 A6 */	mtlr r0
/* 80048E28 00045C28  38 21 00 10 */	addi r1, r1, 0x10
/* 80048E2C 00045C2C  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80048df8

# .text:0x204 | 0x80048E30 | size: 0x48
.fn kar_gmdialoguestatus__near_80048e30, global
/* 80048E30 00045C30  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80048E34 00045C34  7C 08 02 A6 */	mflr r0
/* 80048E38 00045C38  90 01 00 14 */	stw r0, 0x14(r1)
/* 80048E3C 00045C3C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80048E40 00045C40  4B FF EA 05 */	bl kar_diagnostic__80047844
/* 80048E44 00045C44  7C 7F 1B 78 */	mr r31, r3
/* 80048E48 00045C48  4B FF EA 1D */	bl kar_gmdialogue__near_80047864
/* 80048E4C 00045C4C  38 00 00 01 */	li r0, 0x1
/* 80048E50 00045C50  38 60 00 16 */	li r3, 0x16
/* 80048E54 00045C54  98 1F 00 01 */	stb r0, 0x1(r31)
/* 80048E58 00045C58  38 00 00 00 */	li r0, 0x0
/* 80048E5C 00045C5C  98 7F 00 02 */	stb r3, 0x2(r31)
/* 80048E60 00045C60  98 1F 00 06 */	stb r0, 0x6(r31)
/* 80048E64 00045C64  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80048E68 00045C68  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80048E6C 00045C6C  7C 08 03 A6 */	mtlr r0
/* 80048E70 00045C70  38 21 00 10 */	addi r1, r1, 0x10
/* 80048E74 00045C74  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80048e30

# .text:0x24C | 0x80048E78 | size: 0x38
.fn kar_gmdialoguestatus__near_80048e78, global
/* 80048E78 00045C78  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80048E7C 00045C7C  7C 08 02 A6 */	mflr r0
/* 80048E80 00045C80  90 01 00 14 */	stw r0, 0x14(r1)
/* 80048E84 00045C84  4B FF E9 C1 */	bl kar_diagnostic__80047844
/* 80048E88 00045C88  38 00 00 01 */	li r0, 0x1
/* 80048E8C 00045C8C  38 80 00 17 */	li r4, 0x17
/* 80048E90 00045C90  98 03 00 01 */	stb r0, 0x1(r3)
/* 80048E94 00045C94  38 00 00 00 */	li r0, 0x0
/* 80048E98 00045C98  98 83 00 02 */	stb r4, 0x2(r3)
/* 80048E9C 00045C9C  98 03 00 06 */	stb r0, 0x6(r3)
/* 80048EA0 00045CA0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80048EA4 00045CA4  7C 08 03 A6 */	mtlr r0
/* 80048EA8 00045CA8  38 21 00 10 */	addi r1, r1, 0x10
/* 80048EAC 00045CAC  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80048e78

# .text:0x284 | 0x80048EB0 | size: 0x38
.fn kar_gmdialoguestatus__near_80048eb0, global
/* 80048EB0 00045CB0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80048EB4 00045CB4  7C 08 02 A6 */	mflr r0
/* 80048EB8 00045CB8  90 01 00 14 */	stw r0, 0x14(r1)
/* 80048EBC 00045CBC  4B FF E9 89 */	bl kar_diagnostic__80047844
/* 80048EC0 00045CC0  38 00 00 01 */	li r0, 0x1
/* 80048EC4 00045CC4  38 80 00 18 */	li r4, 0x18
/* 80048EC8 00045CC8  98 03 00 01 */	stb r0, 0x1(r3)
/* 80048ECC 00045CCC  38 00 00 00 */	li r0, 0x0
/* 80048ED0 00045CD0  98 83 00 02 */	stb r4, 0x2(r3)
/* 80048ED4 00045CD4  98 03 00 06 */	stb r0, 0x6(r3)
/* 80048ED8 00045CD8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80048EDC 00045CDC  7C 08 03 A6 */	mtlr r0
/* 80048EE0 00045CE0  38 21 00 10 */	addi r1, r1, 0x10
/* 80048EE4 00045CE4  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80048eb0

# .text:0x2BC | 0x80048EE8 | size: 0x48
.fn kar_gmdialoguestatus__near_80048ee8, global
/* 80048EE8 00045CE8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80048EEC 00045CEC  7C 08 02 A6 */	mflr r0
/* 80048EF0 00045CF0  90 01 00 14 */	stw r0, 0x14(r1)
/* 80048EF4 00045CF4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80048EF8 00045CF8  4B FF E9 4D */	bl kar_diagnostic__80047844
/* 80048EFC 00045CFC  7C 7F 1B 78 */	mr r31, r3
/* 80048F00 00045D00  4B FF E9 65 */	bl kar_gmdialogue__near_80047864
/* 80048F04 00045D04  38 00 00 01 */	li r0, 0x1
/* 80048F08 00045D08  38 60 00 19 */	li r3, 0x19
/* 80048F0C 00045D0C  98 1F 00 01 */	stb r0, 0x1(r31)
/* 80048F10 00045D10  38 00 00 00 */	li r0, 0x0
/* 80048F14 00045D14  98 7F 00 02 */	stb r3, 0x2(r31)
/* 80048F18 00045D18  98 1F 00 06 */	stb r0, 0x6(r31)
/* 80048F1C 00045D1C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80048F20 00045D20  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80048F24 00045D24  7C 08 03 A6 */	mtlr r0
/* 80048F28 00045D28  38 21 00 10 */	addi r1, r1, 0x10
/* 80048F2C 00045D2C  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80048ee8

# .text:0x304 | 0x80048F30 | size: 0x38
.fn kar_gmdialoguestatus__near_80048f30, global
/* 80048F30 00045D30  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80048F34 00045D34  7C 08 02 A6 */	mflr r0
/* 80048F38 00045D38  90 01 00 14 */	stw r0, 0x14(r1)
/* 80048F3C 00045D3C  4B FF E9 09 */	bl kar_diagnostic__80047844
/* 80048F40 00045D40  38 00 00 01 */	li r0, 0x1
/* 80048F44 00045D44  38 80 00 1A */	li r4, 0x1a
/* 80048F48 00045D48  98 03 00 01 */	stb r0, 0x1(r3)
/* 80048F4C 00045D4C  38 00 00 00 */	li r0, 0x0
/* 80048F50 00045D50  98 83 00 02 */	stb r4, 0x2(r3)
/* 80048F54 00045D54  98 03 00 06 */	stb r0, 0x6(r3)
/* 80048F58 00045D58  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80048F5C 00045D5C  7C 08 03 A6 */	mtlr r0
/* 80048F60 00045D60  38 21 00 10 */	addi r1, r1, 0x10
/* 80048F64 00045D64  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80048f30

# .text:0x33C | 0x80048F68 | size: 0x30
.fn kar_gmdialoguestatus__80048f68, global
/* 80048F68 00045D68  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80048F6C 00045D6C  7C 08 02 A6 */	mflr r0
/* 80048F70 00045D70  3C 60 80 49 */	lis r3, kar_src_gmdialoguestatus_804972d8@ha
/* 80048F74 00045D74  38 80 01 4F */	li r4, 0x14f
/* 80048F78 00045D78  90 01 00 14 */	stw r0, 0x14(r1)
/* 80048F7C 00045D7C  38 63 72 D8 */	addi r3, r3, kar_src_gmdialoguestatus_804972d8@l
/* 80048F80 00045D80  38 AD 80 E0 */	li r5, lbl_805D51C0@sda21
/* 80048F84 00045D84  48 3D F5 35 */	bl __assert
/* 80048F88 00045D88  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80048F8C 00045D8C  7C 08 03 A6 */	mtlr r0
/* 80048F90 00045D90  38 21 00 10 */	addi r1, r1, 0x10
/* 80048F94 00045D94  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__80048f68

# .text:0x36C | 0x80048F98 | size: 0x38
.fn kar_gmdialoguestatus__near_80048f98, global
/* 80048F98 00045D98  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80048F9C 00045D9C  7C 08 02 A6 */	mflr r0
/* 80048FA0 00045DA0  90 01 00 14 */	stw r0, 0x14(r1)
/* 80048FA4 00045DA4  4B FF E8 A1 */	bl kar_diagnostic__80047844
/* 80048FA8 00045DA8  38 00 00 01 */	li r0, 0x1
/* 80048FAC 00045DAC  38 80 00 1C */	li r4, 0x1c
/* 80048FB0 00045DB0  98 03 00 01 */	stb r0, 0x1(r3)
/* 80048FB4 00045DB4  38 00 00 02 */	li r0, 0x2
/* 80048FB8 00045DB8  98 83 00 02 */	stb r4, 0x2(r3)
/* 80048FBC 00045DBC  98 03 00 06 */	stb r0, 0x6(r3)
/* 80048FC0 00045DC0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80048FC4 00045DC4  7C 08 03 A6 */	mtlr r0
/* 80048FC8 00045DC8  38 21 00 10 */	addi r1, r1, 0x10
/* 80048FCC 00045DCC  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80048f98

# .text:0x3A4 | 0x80048FD0 | size: 0x38
.fn kar_gmdialoguestatus__near_80048fd0, global
/* 80048FD0 00045DD0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80048FD4 00045DD4  7C 08 02 A6 */	mflr r0
/* 80048FD8 00045DD8  90 01 00 14 */	stw r0, 0x14(r1)
/* 80048FDC 00045DDC  4B FF E8 69 */	bl kar_diagnostic__80047844
/* 80048FE0 00045DE0  38 00 00 01 */	li r0, 0x1
/* 80048FE4 00045DE4  38 80 00 1D */	li r4, 0x1d
/* 80048FE8 00045DE8  98 03 00 01 */	stb r0, 0x1(r3)
/* 80048FEC 00045DEC  38 00 00 02 */	li r0, 0x2
/* 80048FF0 00045DF0  98 83 00 02 */	stb r4, 0x2(r3)
/* 80048FF4 00045DF4  98 03 00 06 */	stb r0, 0x6(r3)
/* 80048FF8 00045DF8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80048FFC 00045DFC  7C 08 03 A6 */	mtlr r0
/* 80049000 00045E00  38 21 00 10 */	addi r1, r1, 0x10
/* 80049004 00045E04  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80048fd0

# .text:0x3DC | 0x80049008 | size: 0x38
.fn kar_gmdialoguestatus__near_80049008, global
/* 80049008 00045E08  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8004900C 00045E0C  7C 08 02 A6 */	mflr r0
/* 80049010 00045E10  90 01 00 14 */	stw r0, 0x14(r1)
/* 80049014 00045E14  4B FF E8 31 */	bl kar_diagnostic__80047844
/* 80049018 00045E18  38 00 00 01 */	li r0, 0x1
/* 8004901C 00045E1C  38 80 00 1E */	li r4, 0x1e
/* 80049020 00045E20  98 03 00 01 */	stb r0, 0x1(r3)
/* 80049024 00045E24  38 00 00 00 */	li r0, 0x0
/* 80049028 00045E28  98 83 00 02 */	stb r4, 0x2(r3)
/* 8004902C 00045E2C  98 03 00 06 */	stb r0, 0x6(r3)
/* 80049030 00045E30  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80049034 00045E34  7C 08 03 A6 */	mtlr r0
/* 80049038 00045E38  38 21 00 10 */	addi r1, r1, 0x10
/* 8004903C 00045E3C  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80049008

# .text:0x414 | 0x80049040 | size: 0x30
.fn kar_gmdialoguestatus__80049040, global
/* 80049040 00045E40  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80049044 00045E44  7C 08 02 A6 */	mflr r0
/* 80049048 00045E48  3C 60 80 49 */	lis r3, kar_src_gmdialoguestatus_804972d8@ha
/* 8004904C 00045E4C  38 80 01 84 */	li r4, 0x184
/* 80049050 00045E50  90 01 00 14 */	stw r0, 0x14(r1)
/* 80049054 00045E54  38 63 72 D8 */	addi r3, r3, kar_src_gmdialoguestatus_804972d8@l
/* 80049058 00045E58  38 AD 80 E0 */	li r5, lbl_805D51C0@sda21
/* 8004905C 00045E5C  48 3D F4 5D */	bl __assert
/* 80049060 00045E60  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80049064 00045E64  7C 08 03 A6 */	mtlr r0
/* 80049068 00045E68  38 21 00 10 */	addi r1, r1, 0x10
/* 8004906C 00045E6C  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__80049040

# .text:0x444 | 0x80049070 | size: 0x38
.fn kar_gmdialoguestatus__near_80049070, global
/* 80049070 00045E70  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80049074 00045E74  7C 08 02 A6 */	mflr r0
/* 80049078 00045E78  90 01 00 14 */	stw r0, 0x14(r1)
/* 8004907C 00045E7C  4B FF E7 C9 */	bl kar_diagnostic__80047844
/* 80049080 00045E80  38 00 00 01 */	li r0, 0x1
/* 80049084 00045E84  38 80 00 20 */	li r4, 0x20
/* 80049088 00045E88  98 03 00 01 */	stb r0, 0x1(r3)
/* 8004908C 00045E8C  38 00 00 00 */	li r0, 0x0
/* 80049090 00045E90  98 83 00 02 */	stb r4, 0x2(r3)
/* 80049094 00045E94  98 03 00 06 */	stb r0, 0x6(r3)
/* 80049098 00045E98  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8004909C 00045E9C  7C 08 03 A6 */	mtlr r0
/* 800490A0 00045EA0  38 21 00 10 */	addi r1, r1, 0x10
/* 800490A4 00045EA4  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80049070

# .text:0x47C | 0x800490A8 | size: 0x28
.fn kar_gmdialoguestatus__near_800490a8, global
/* 800490A8 00045EA8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800490AC 00045EAC  7C 08 02 A6 */	mflr r0
/* 800490B0 00045EB0  90 01 00 14 */	stw r0, 0x14(r1)
/* 800490B4 00045EB4  4B FF E7 91 */	bl kar_diagnostic__80047844
/* 800490B8 00045EB8  38 00 00 02 */	li r0, 0x2
/* 800490BC 00045EBC  98 03 00 01 */	stb r0, 0x1(r3)
/* 800490C0 00045EC0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800490C4 00045EC4  7C 08 03 A6 */	mtlr r0
/* 800490C8 00045EC8  38 21 00 10 */	addi r1, r1, 0x10
/* 800490CC 00045ECC  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_800490a8

# .text:0x4A4 | 0x800490D0 | size: 0x28
.fn kar_gmdialoguestatus__near_800490d0, global
/* 800490D0 00045ED0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800490D4 00045ED4  7C 08 02 A6 */	mflr r0
/* 800490D8 00045ED8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800490DC 00045EDC  4B FF E7 69 */	bl kar_diagnostic__80047844
/* 800490E0 00045EE0  38 00 00 02 */	li r0, 0x2
/* 800490E4 00045EE4  98 03 00 01 */	stb r0, 0x1(r3)
/* 800490E8 00045EE8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800490EC 00045EEC  7C 08 03 A6 */	mtlr r0
/* 800490F0 00045EF0  38 21 00 10 */	addi r1, r1, 0x10
/* 800490F4 00045EF4  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_800490d0

# .text:0x4CC | 0x800490F8 | size: 0x28
.fn kar_gmdialoguestatus__near_800490f8, global
/* 800490F8 00045EF8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800490FC 00045EFC  7C 08 02 A6 */	mflr r0
/* 80049100 00045F00  90 01 00 14 */	stw r0, 0x14(r1)
/* 80049104 00045F04  4B FF E7 41 */	bl kar_diagnostic__80047844
/* 80049108 00045F08  38 00 00 02 */	li r0, 0x2
/* 8004910C 00045F0C  98 03 00 01 */	stb r0, 0x1(r3)
/* 80049110 00045F10  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80049114 00045F14  7C 08 03 A6 */	mtlr r0
/* 80049118 00045F18  38 21 00 10 */	addi r1, r1, 0x10
/* 8004911C 00045F1C  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_800490f8

# .text:0x4F4 | 0x80049120 | size: 0x20
.fn kar_gmdialoguestatus__near_80049120, global
/* 80049120 00045F20  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80049124 00045F24  7C 08 02 A6 */	mflr r0
/* 80049128 00045F28  90 01 00 14 */	stw r0, 0x14(r1)
/* 8004912C 00045F2C  4B FF E7 19 */	bl kar_diagnostic__80047844
/* 80049130 00045F30  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80049134 00045F34  7C 08 03 A6 */	mtlr r0
/* 80049138 00045F38  38 21 00 10 */	addi r1, r1, 0x10
/* 8004913C 00045F3C  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80049120

# .text:0x514 | 0x80049140 | size: 0x28
.fn kar_gmdialoguestatus__near_80049140, global
/* 80049140 00045F40  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80049144 00045F44  7C 08 02 A6 */	mflr r0
/* 80049148 00045F48  90 01 00 14 */	stw r0, 0x14(r1)
/* 8004914C 00045F4C  4B FF E6 F9 */	bl kar_diagnostic__80047844
/* 80049150 00045F50  38 00 00 02 */	li r0, 0x2
/* 80049154 00045F54  98 03 00 01 */	stb r0, 0x1(r3)
/* 80049158 00045F58  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8004915C 00045F5C  7C 08 03 A6 */	mtlr r0
/* 80049160 00045F60  38 21 00 10 */	addi r1, r1, 0x10
/* 80049164 00045F64  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80049140

# .text:0x53C | 0x80049168 | size: 0x30
.fn kar_gmdialoguestatus__near_80049168, global
/* 80049168 00045F68  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8004916C 00045F6C  7C 08 02 A6 */	mflr r0
/* 80049170 00045F70  90 01 00 14 */	stw r0, 0x14(r1)
/* 80049174 00045F74  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80049178 00045F78  7C 7F 1B 78 */	mr r31, r3
/* 8004917C 00045F7C  4B FB DA 99 */	bl kar_gmmain__near_80006c14
/* 80049180 00045F80  9B E3 07 C4 */	stb r31, 0x7c4(r3)
/* 80049184 00045F84  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80049188 00045F88  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8004918C 00045F8C  7C 08 03 A6 */	mtlr r0
/* 80049190 00045F90  38 21 00 10 */	addi r1, r1, 0x10
/* 80049194 00045F94  4E 80 00 20 */	blr
.endfn kar_gmdialoguestatus__near_80049168

# 0x804972D8..0x804972F0 | size: 0x18
.data
.balign 8

# .data:0x0 | 0x804972D8 | size: 0x13
.obj kar_src_gmdialoguestatus_804972d8, global
	.string "gmdialoguestatus.c"
.endobj kar_src_gmdialoguestatus_804972d8

# .data:0x13 | 0x804972EB | size: 0x5
.obj gap_07_804972EB_data, global
.hidden gap_07_804972EB_data
	.4byte 0x00000000
	.byte 0x00
.endobj gap_07_804972EB_data

# 0x805D51C0..0x805D51C8 | size: 0x8
.section .sdata, "wa"
.balign 8

# .sdata:0x0 | 0x805D51C0 | size: 0x2
.obj lbl_805D51C0, global
	.string "0"
.endobj lbl_805D51C0

# .sdata:0x2 | 0x805D51C2 | size: 0x6
.obj gap_09_805D51C2_sdata, global
.hidden gap_09_805D51C2_sdata
	.4byte 0x00000000
	.2byte 0x0000
.endobj gap_09_805D51C2_sdata
