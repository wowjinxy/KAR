.include "macros.inc"
.file "gmdialoguestatus.c"

# 0x80048F68..0x80049198 | size: 0x230
.text
.balign 4

# .text:0x0 | 0x80048F68 | size: 0x30
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

# .text:0x30 | 0x80048F98 | size: 0x38
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

# .text:0x68 | 0x80048FD0 | size: 0x38
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

# .text:0xA0 | 0x80049008 | size: 0x38
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

# .text:0xD8 | 0x80049040 | size: 0x30
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

# .text:0x108 | 0x80049070 | size: 0x38
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

# .text:0x140 | 0x800490A8 | size: 0x28
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

# .text:0x168 | 0x800490D0 | size: 0x28
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

# .text:0x190 | 0x800490F8 | size: 0x28
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

# .text:0x1B8 | 0x80049120 | size: 0x20
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

# .text:0x1D8 | 0x80049140 | size: 0x28
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

# .text:0x200 | 0x80049168 | size: 0x30
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
