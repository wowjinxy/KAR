.include "macros.inc"
.file "lbfile.c"

# 0x80058E1C..0x80059484 | size: 0x668
.text
.balign 4

# .text:0x0 | 0x80058E1C | size: 0x44
.fn kar_lbfile_async_done_callback, global
/* 80058E1C 00055C1C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80058E20 00055C20  7C 08 02 A6 */	mflr r0
/* 80058E24 00055C24  2C 06 00 00 */	cmpwi r6, 0x0
/* 80058E28 00055C28  90 01 00 14 */	stw r0, 0x14(r1)
/* 80058E2C 00055C2C  41 82 00 1C */	beq .L_80058E48
/* 80058E30 00055C30  3C 60 80 4A */	lis r3, kar_src_lbfile_80498108@ha
/* 80058E34 00055C34  3C A0 80 4A */	lis r5, lbl_80498114@ha
/* 80058E38 00055C38  38 63 81 08 */	addi r3, r3, kar_src_lbfile_80498108@l
/* 80058E3C 00055C3C  38 80 00 4F */	li r4, 0x4f
/* 80058E40 00055C40  38 A5 81 14 */	addi r5, r5, lbl_80498114@l
/* 80058E44 00055C44  48 3C F6 75 */	bl __assert
.L_80058E48:
/* 80058E48 00055C48  38 00 00 01 */	li r0, 0x1
/* 80058E4C 00055C4C  90 0D 04 C8 */	stw r0, lbl_805DD5A8@sda21(r0)
/* 80058E50 00055C50  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80058E54 00055C54  7C 08 03 A6 */	mtlr r0
/* 80058E58 00055C58  38 21 00 10 */	addi r1, r1, 0x10
/* 80058E5C 00055C5C  4E 80 00 20 */	blr
.endfn kar_lbfile_async_done_callback

# .text:0x44 | 0x80058E60 | size: 0x24
.fn kar_lbfile_poll_async_done, global
/* 80058E60 00055C60  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80058E64 00055C64  7C 08 02 A6 */	mflr r0
/* 80058E68 00055C68  90 01 00 14 */	stw r0, 0x14(r1)
/* 80058E6C 00055C6C  48 00 0E 91 */	bl kar_lbarchive__near_80059cfc
/* 80058E70 00055C70  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80058E74 00055C74  80 6D 04 C8 */	lwz r3, lbl_805DD5A8@sda21(r0)
/* 80058E78 00055C78  7C 08 03 A6 */	mtlr r0
/* 80058E7C 00055C7C  38 21 00 10 */	addi r1, r1, 0x10
/* 80058E80 00055C80  4E 80 00 20 */	blr
.endfn kar_lbfile_poll_async_done

# .text:0x68 | 0x80058E84 | size: 0x214
.fn kar_lbfile_build_localized_filename, global
/* 80058E84 00055C84  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80058E88 00055C88  7C 08 02 A6 */	mflr r0
/* 80058E8C 00055C8C  3C 80 80 54 */	lis r4, kar_lbfile_path_buffer@ha
/* 80058E90 00055C90  90 01 00 24 */	stw r0, 0x24(r1)
/* 80058E94 00055C94  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80058E98 00055C98  3B E0 00 00 */	li r31, 0x0
/* 80058E9C 00055C9C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80058EA0 00055CA0  3B C4 80 68 */	addi r30, r4, kar_lbfile_path_buffer@l
/* 80058EA4 00055CA4  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80058EA8 00055CA8  93 81 00 10 */	stw r28, 0x10(r1)
/* 80058EAC 00055CAC  7C 7C 1B 78 */	mr r28, r3
/* 80058EB0 00055CB0  7F 9D E3 78 */	mr r29, r28
/* 80058EB4 00055CB4  48 00 00 48 */	b .L_80058EFC
.L_80058EB8:
/* 80058EB8 00055CB8  2C 1F 00 1C */	cmpwi r31, 0x1c
/* 80058EBC 00055CBC  40 81 00 2C */	ble .L_80058EE8
/* 80058EC0 00055CC0  3C 60 80 4A */	lis r3, lbl_80498120@ha
/* 80058EC4 00055CC4  7F 84 E3 78 */	mr r4, r28
/* 80058EC8 00055CC8  38 63 81 20 */	addi r3, r3, lbl_80498120@l
/* 80058ECC 00055CCC  4C C6 31 82 */	crclr cr1eq
/* 80058ED0 00055CD0  48 37 BE 19 */	bl OSReport
/* 80058ED4 00055CD4  3C 60 80 4A */	lis r3, kar_src_lbfile_80498108@ha
/* 80058ED8 00055CD8  38 80 00 AA */	li r4, 0xaa
/* 80058EDC 00055CDC  38 63 81 08 */	addi r3, r3, kar_src_lbfile_80498108@l
/* 80058EE0 00055CE0  38 AD 81 80 */	li r5, lbl_805D5260@sda21
/* 80058EE4 00055CE4  48 3C F5 D5 */	bl __assert
.L_80058EE8:
/* 80058EE8 00055CE8  88 1D 00 00 */	lbz r0, 0x0(r29)
/* 80058EEC 00055CEC  3B BD 00 01 */	addi r29, r29, 0x1
/* 80058EF0 00055CF0  3B FF 00 01 */	addi r31, r31, 0x1
/* 80058EF4 00055CF4  98 1E 00 00 */	stb r0, 0x0(r30)
/* 80058EF8 00055CF8  3B DE 00 01 */	addi r30, r30, 0x1
.L_80058EFC:
/* 80058EFC 00055CFC  88 7D 00 00 */	lbz r3, 0x0(r29)
/* 80058F00 00055D00  7C 60 07 75 */	extsb. r0, r3
/* 80058F04 00055D04  41 82 00 18 */	beq .L_80058F1C
/* 80058F08 00055D08  7C 60 07 74 */	extsb r0, r3
/* 80058F0C 00055D0C  2C 00 00 2E */	cmpwi r0, 0x2e
/* 80058F10 00055D10  41 82 00 0C */	beq .L_80058F1C
/* 80058F14 00055D14  2C 00 00 5F */	cmpwi r0, 0x5f
/* 80058F18 00055D18  40 82 FF A0 */	bne .L_80058EB8
.L_80058F1C:
/* 80058F1C 00055D1C  7C 60 07 75 */	extsb. r0, r3
/* 80058F20 00055D20  41 82 00 24 */	beq .L_80058F44
/* 80058F24 00055D24  88 1D 00 01 */	lbz r0, 0x1(r29)
/* 80058F28 00055D28  7C 00 07 75 */	extsb. r0, r0
/* 80058F2C 00055D2C  41 82 00 18 */	beq .L_80058F44
/* 80058F30 00055D30  3C 60 80 54 */	lis r3, kar_lbfile_path_buffer@ha
/* 80058F34 00055D34  7F 84 E3 78 */	mr r4, r28
/* 80058F38 00055D38  38 63 80 68 */	addi r3, r3, kar_lbfile_path_buffer@l
/* 80058F3C 00055D3C  48 35 F1 0D */	bl strcpy
/* 80058F40 00055D40  48 00 01 30 */	b .L_80059070
.L_80058F44:
/* 80058F44 00055D44  7C 60 07 74 */	extsb r0, r3
/* 80058F48 00055D48  2C 00 00 2E */	cmpwi r0, 0x2e
/* 80058F4C 00055D4C  40 82 00 80 */	bne .L_80058FCC
/* 80058F50 00055D50  3C 60 80 54 */	lis r3, kar_lbfile_path_buffer@ha
/* 80058F54 00055D54  38 00 00 2E */	li r0, 0x2e
/* 80058F58 00055D58  38 63 80 68 */	addi r3, r3, kar_lbfile_path_buffer@l
/* 80058F5C 00055D5C  7C 03 F9 AE */	stbx r0, r3, r31
/* 80058F60 00055D60  3B FF 00 01 */	addi r31, r31, 0x1
/* 80058F64 00055D64  4B FA E6 FD */	bl kar_gmglobal__near_80007660
/* 80058F68 00055D68  54 60 06 3E */	clrlwi r0, r3, 24
/* 80058F6C 00055D6C  2C 00 00 01 */	cmpwi r0, 0x1
/* 80058F70 00055D70  41 82 00 2C */	beq .L_80058F9C
/* 80058F74 00055D74  40 80 00 40 */	bge .L_80058FB4
/* 80058F78 00055D78  2C 00 00 00 */	cmpwi r0, 0x0
/* 80058F7C 00055D7C  40 80 00 08 */	bge .L_80058F84
/* 80058F80 00055D80  48 00 00 34 */	b .L_80058FB4
.L_80058F84:
/* 80058F84 00055D84  3C 60 80 54 */	lis r3, kar_lbfile_path_buffer@ha
/* 80058F88 00055D88  38 8D 81 88 */	li r4, lbl_805D5268@sda21
/* 80058F8C 00055D8C  38 03 80 68 */	addi r0, r3, kar_lbfile_path_buffer@l
/* 80058F90 00055D90  7C 60 FA 14 */	add r3, r0, r31
/* 80058F94 00055D94  48 35 F0 B5 */	bl strcpy
/* 80058F98 00055D98  48 00 00 D8 */	b .L_80059070
.L_80058F9C:
/* 80058F9C 00055D9C  3C 60 80 54 */	lis r3, kar_lbfile_path_buffer@ha
/* 80058FA0 00055DA0  38 8D 81 88 */	li r4, lbl_805D5268@sda21
/* 80058FA4 00055DA4  38 03 80 68 */	addi r0, r3, kar_lbfile_path_buffer@l
/* 80058FA8 00055DA8  7C 60 FA 14 */	add r3, r0, r31
/* 80058FAC 00055DAC  48 35 F0 9D */	bl strcpy
/* 80058FB0 00055DB0  48 00 00 C0 */	b .L_80059070
.L_80058FB4:
/* 80058FB4 00055DB4  3C 60 80 54 */	lis r3, kar_lbfile_path_buffer@ha
/* 80058FB8 00055DB8  38 8D 81 88 */	li r4, lbl_805D5268@sda21
/* 80058FBC 00055DBC  38 03 80 68 */	addi r0, r3, kar_lbfile_path_buffer@l
/* 80058FC0 00055DC0  7C 60 FA 14 */	add r3, r0, r31
/* 80058FC4 00055DC4  48 35 F0 85 */	bl strcpy
/* 80058FC8 00055DC8  48 00 00 A8 */	b .L_80059070
.L_80058FCC:
/* 80058FCC 00055DCC  2C 00 00 5F */	cmpwi r0, 0x5f
/* 80058FD0 00055DD0  40 82 00 80 */	bne .L_80059050
/* 80058FD4 00055DD4  3C 60 80 54 */	lis r3, kar_lbfile_path_buffer@ha
/* 80058FD8 00055DD8  38 00 00 2E */	li r0, 0x2e
/* 80058FDC 00055DDC  38 63 80 68 */	addi r3, r3, kar_lbfile_path_buffer@l
/* 80058FE0 00055DE0  7C 03 F9 AE */	stbx r0, r3, r31
/* 80058FE4 00055DE4  3B FF 00 01 */	addi r31, r31, 0x1
/* 80058FE8 00055DE8  4B FA E6 99 */	bl kar_gmglobal__near_80007680
/* 80058FEC 00055DEC  54 60 06 3E */	clrlwi r0, r3, 24
/* 80058FF0 00055DF0  2C 00 00 01 */	cmpwi r0, 0x1
/* 80058FF4 00055DF4  41 82 00 2C */	beq .L_80059020
/* 80058FF8 00055DF8  40 80 00 40 */	bge .L_80059038
/* 80058FFC 00055DFC  2C 00 00 00 */	cmpwi r0, 0x0
/* 80059000 00055E00  40 80 00 08 */	bge .L_80059008
/* 80059004 00055E04  48 00 00 34 */	b .L_80059038
.L_80059008:
/* 80059008 00055E08  3C 60 80 54 */	lis r3, kar_lbfile_path_buffer@ha
/* 8005900C 00055E0C  38 8D 81 88 */	li r4, lbl_805D5268@sda21
/* 80059010 00055E10  38 03 80 68 */	addi r0, r3, kar_lbfile_path_buffer@l
/* 80059014 00055E14  7C 60 FA 14 */	add r3, r0, r31
/* 80059018 00055E18  48 35 F0 31 */	bl strcpy
/* 8005901C 00055E1C  48 00 00 54 */	b .L_80059070
.L_80059020:
/* 80059020 00055E20  3C 60 80 54 */	lis r3, kar_lbfile_path_buffer@ha
/* 80059024 00055E24  38 8D 81 88 */	li r4, lbl_805D5268@sda21
/* 80059028 00055E28  38 03 80 68 */	addi r0, r3, kar_lbfile_path_buffer@l
/* 8005902C 00055E2C  7C 60 FA 14 */	add r3, r0, r31
/* 80059030 00055E30  48 35 F0 19 */	bl strcpy
/* 80059034 00055E34  48 00 00 3C */	b .L_80059070
.L_80059038:
/* 80059038 00055E38  3C 60 80 54 */	lis r3, kar_lbfile_path_buffer@ha
/* 8005903C 00055E3C  38 8D 81 88 */	li r4, lbl_805D5268@sda21
/* 80059040 00055E40  38 03 80 68 */	addi r0, r3, kar_lbfile_path_buffer@l
/* 80059044 00055E44  7C 60 FA 14 */	add r3, r0, r31
/* 80059048 00055E48  48 35 F0 01 */	bl strcpy
/* 8005904C 00055E4C  48 00 00 24 */	b .L_80059070
.L_80059050:
/* 80059050 00055E50  3C 60 80 54 */	lis r3, kar_lbfile_path_buffer@ha
/* 80059054 00055E54  38 00 00 2E */	li r0, 0x2e
/* 80059058 00055E58  38 63 80 68 */	addi r3, r3, kar_lbfile_path_buffer@l
/* 8005905C 00055E5C  38 8D 81 88 */	li r4, lbl_805D5268@sda21
/* 80059060 00055E60  7C 03 F9 AE */	stbx r0, r3, r31
/* 80059064 00055E64  3B FF 00 01 */	addi r31, r31, 0x1
/* 80059068 00055E68  7C 63 FA 14 */	add r3, r3, r31
/* 8005906C 00055E6C  48 35 EF DD */	bl strcpy
.L_80059070:
/* 80059070 00055E70  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80059074 00055E74  3C 60 80 54 */	lis r3, kar_lbfile_path_buffer@ha
/* 80059078 00055E78  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8005907C 00055E7C  38 63 80 68 */	addi r3, r3, kar_lbfile_path_buffer@l
/* 80059080 00055E80  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80059084 00055E84  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80059088 00055E88  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8005908C 00055E8C  7C 08 03 A6 */	mtlr r0
/* 80059090 00055E90  38 21 00 20 */	addi r1, r1, 0x20
/* 80059094 00055E94  4E 80 00 20 */	blr
.endfn kar_lbfile_build_localized_filename

# .text:0x27C | 0x80059098 | size: 0x34
.fn kar_lbfile_path_exists, global
/* 80059098 00055E98  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8005909C 00055E9C  7C 08 02 A6 */	mflr r0
/* 800590A0 00055EA0  90 01 00 14 */	stw r0, 0x14(r1)
/* 800590A4 00055EA4  4B FF FD E1 */	bl kar_lbfile_build_localized_filename
/* 800590A8 00055EA8  48 36 BE 2D */	bl DVDConvertPathToEntrynum
/* 800590AC 00055EAC  20 83 FF FF */	subfic r4, r3, -0x1
/* 800590B0 00055EB0  38 03 00 01 */	addi r0, r3, 0x1
/* 800590B4 00055EB4  7C 80 03 78 */	or r0, r4, r0
/* 800590B8 00055EB8  54 03 0F FE */	srwi r3, r0, 31
/* 800590BC 00055EBC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800590C0 00055EC0  7C 08 03 A6 */	mtlr r0
/* 800590C4 00055EC4  38 21 00 10 */	addi r1, r1, 0x10
/* 800590C8 00055EC8  4E 80 00 20 */	blr
.endfn kar_lbfile_path_exists

# .text:0x2B0 | 0x800590CC | size: 0x90
.fn kar_lbfile_get_size_by_entrynum, global
/* 800590CC 00055ECC  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 800590D0 00055ED0  7C 08 02 A6 */	mflr r0
/* 800590D4 00055ED4  90 01 00 54 */	stw r0, 0x54(r1)
/* 800590D8 00055ED8  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 800590DC 00055EDC  7C 7F 1B 78 */	mr r31, r3
/* 800590E0 00055EE0  93 C1 00 48 */	stw r30, 0x48(r1)
/* 800590E4 00055EE4  48 37 DF C5 */	bl OSDisableInterrupts
/* 800590E8 00055EE8  7C 60 1B 78 */	mr r0, r3
/* 800590EC 00055EEC  7F E3 FB 78 */	mr r3, r31
/* 800590F0 00055EF0  7C 1E 03 78 */	mr r30, r0
/* 800590F4 00055EF4  38 81 00 08 */	addi r4, r1, 0x8
/* 800590F8 00055EF8  48 36 C0 D1 */	bl kar_lbfile__803c51c8
/* 800590FC 00055EFC  2C 03 00 00 */	cmpwi r3, 0x0
/* 80059100 00055F00  40 82 00 2C */	bne .L_8005912C
/* 80059104 00055F04  3C 60 80 4A */	lis r3, lbl_80498140@ha
/* 80059108 00055F08  7F E4 FB 78 */	mr r4, r31
/* 8005910C 00055F0C  38 63 81 40 */	addi r3, r3, lbl_80498140@l
/* 80059110 00055F10  4C C6 31 82 */	crclr cr1eq
/* 80059114 00055F14  48 37 BB D5 */	bl OSReport
/* 80059118 00055F18  3C 60 80 4A */	lis r3, kar_src_lbfile_80498108@ha
/* 8005911C 00055F1C  38 80 01 26 */	li r4, 0x126
/* 80059120 00055F20  38 63 81 08 */	addi r3, r3, kar_src_lbfile_80498108@l
/* 80059124 00055F24  38 AD 81 8C */	li r5, lbl_805D526C@sda21
/* 80059128 00055F28  48 3C F3 91 */	bl __assert
.L_8005912C:
/* 8005912C 00055F2C  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 80059130 00055F30  38 61 00 08 */	addi r3, r1, 0x8
/* 80059134 00055F34  48 36 C1 D1 */	bl DVDClose
/* 80059138 00055F38  7F C3 F3 78 */	mr r3, r30
/* 8005913C 00055F3C  48 37 DF 95 */	bl OSRestoreInterrupts
/* 80059140 00055F40  80 01 00 54 */	lwz r0, 0x54(r1)
/* 80059144 00055F44  7F E3 FB 78 */	mr r3, r31
/* 80059148 00055F48  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 8005914C 00055F4C  83 C1 00 48 */	lwz r30, 0x48(r1)
/* 80059150 00055F50  7C 08 03 A6 */	mtlr r0
/* 80059154 00055F54  38 21 00 50 */	addi r1, r1, 0x50
/* 80059158 00055F58  4E 80 00 20 */	blr
.endfn kar_lbfile_get_size_by_entrynum

# .text:0x340 | 0x8005915C | size: 0xCC
.fn kar_lbfile_get_size_by_path, global
/* 8005915C 00055F5C  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 80059160 00055F60  7C 08 02 A6 */	mflr r0
/* 80059164 00055F64  3C 80 80 4A */	lis r4, kar_src_lbfile_80498108@ha
/* 80059168 00055F68  90 01 00 64 */	stw r0, 0x64(r1)
/* 8005916C 00055F6C  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 80059170 00055F70  3B E4 81 08 */	addi r31, r4, kar_src_lbfile_80498108@l
/* 80059174 00055F74  93 C1 00 58 */	stw r30, 0x58(r1)
/* 80059178 00055F78  93 A1 00 54 */	stw r29, 0x54(r1)
/* 8005917C 00055F7C  4B FF FD 09 */	bl kar_lbfile_build_localized_filename
/* 80059180 00055F80  7C 7E 1B 78 */	mr r30, r3
/* 80059184 00055F84  48 36 BD 51 */	bl DVDConvertPathToEntrynum
/* 80059188 00055F88  7C 7D 1B 78 */	mr r29, r3
/* 8005918C 00055F8C  2C 1D FF FF */	cmpwi r29, -0x1
/* 80059190 00055F90  40 82 00 28 */	bne .L_800591B8
/* 80059194 00055F94  7F C4 F3 78 */	mr r4, r30
/* 80059198 00055F98  7F A5 EB 78 */	mr r5, r29
/* 8005919C 00055F9C  38 7F 00 50 */	addi r3, r31, 0x50
/* 800591A0 00055FA0  4C C6 31 82 */	crclr cr1eq
/* 800591A4 00055FA4  48 37 BB 45 */	bl OSReport
/* 800591A8 00055FA8  38 7F 00 00 */	addi r3, r31, 0x0
/* 800591AC 00055FAC  38 BF 00 6C */	addi r5, r31, 0x6c
/* 800591B0 00055FB0  38 80 01 3C */	li r4, 0x13c
/* 800591B4 00055FB4  48 3C F3 05 */	bl __assert
.L_800591B8:
/* 800591B8 00055FB8  48 37 DE F1 */	bl OSDisableInterrupts
/* 800591BC 00055FBC  7C 7E 1B 78 */	mr r30, r3
/* 800591C0 00055FC0  7F A3 EB 78 */	mr r3, r29
/* 800591C4 00055FC4  38 81 00 08 */	addi r4, r1, 0x8
/* 800591C8 00055FC8  48 36 C0 01 */	bl kar_lbfile__803c51c8
/* 800591CC 00055FCC  2C 03 00 00 */	cmpwi r3, 0x0
/* 800591D0 00055FD0  40 82 00 24 */	bne .L_800591F4
/* 800591D4 00055FD4  7F A4 EB 78 */	mr r4, r29
/* 800591D8 00055FD8  38 7F 00 38 */	addi r3, r31, 0x38
/* 800591DC 00055FDC  4C C6 31 82 */	crclr cr1eq
/* 800591E0 00055FE0  48 37 BB 09 */	bl OSReport
/* 800591E4 00055FE4  38 7F 00 00 */	addi r3, r31, 0x0
/* 800591E8 00055FE8  38 80 01 26 */	li r4, 0x126
/* 800591EC 00055FEC  38 AD 81 8C */	li r5, lbl_805D526C@sda21
/* 800591F0 00055FF0  48 3C F2 C9 */	bl __assert
.L_800591F4:
/* 800591F4 00055FF4  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 800591F8 00055FF8  38 61 00 08 */	addi r3, r1, 0x8
/* 800591FC 00055FFC  48 36 C1 09 */	bl DVDClose
/* 80059200 00056000  7F C3 F3 78 */	mr r3, r30
/* 80059204 00056004  48 37 DE CD */	bl OSRestoreInterrupts
/* 80059208 00056008  80 01 00 64 */	lwz r0, 0x64(r1)
/* 8005920C 0005600C  7F E3 FB 78 */	mr r3, r31
/* 80059210 00056010  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 80059214 00056014  83 C1 00 58 */	lwz r30, 0x58(r1)
/* 80059218 00056018  83 A1 00 54 */	lwz r29, 0x54(r1)
/* 8005921C 0005601C  7C 08 03 A6 */	mtlr r0
/* 80059220 00056020  38 21 00 60 */	addi r1, r1, 0x60
/* 80059224 00056024  4E 80 00 20 */	blr
.endfn kar_lbfile_get_size_by_path

# .text:0x40C | 0x80059228 | size: 0x60
.fn kar_lbfile_devcom_copy_blocking, global
/* 80059228 00056028  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8005922C 0005602C  7C 08 02 A6 */	mflr r0
/* 80059230 00056030  3C E0 80 06 */	lis r7, kar_lbfile_async_done_callback@ha
/* 80059234 00056034  7C 8B 23 78 */	mr r11, r4
/* 80059238 00056038  90 01 00 14 */	stw r0, 0x14(r1)
/* 8005923C 0005603C  38 00 00 00 */	li r0, 0x0
/* 80059240 00056040  7C AA 2B 78 */	mr r10, r5
/* 80059244 00056044  7C C8 33 78 */	mr r8, r6
/* 80059248 00056048  90 0D 04 C8 */	stw r0, lbl_805DD5A8@sda21(r0)
/* 8005924C 0005604C  39 27 8E 1C */	addi r9, r7, kar_lbfile_async_done_callback@l
/* 80059250 00056050  7C 64 1B 78 */	mr r4, r3
/* 80059254 00056054  7D 46 53 78 */	mr r6, r10
/* 80059258 00056058  7D 65 5B 78 */	mr r5, r11
/* 8005925C 0005605C  38 60 00 00 */	li r3, 0x0
/* 80059260 00056060  38 E0 00 19 */	li r7, 0x19
/* 80059264 00056064  39 40 00 00 */	li r10, 0x0
/* 80059268 00056068  48 3E D8 65 */	bl HSD_DevComRequest
.L_8005926C:
/* 8005926C 0005606C  4B FF FB F5 */	bl kar_lbfile_poll_async_done
/* 80059270 00056070  2C 03 00 00 */	cmpwi r3, 0x0
/* 80059274 00056074  41 82 FF F8 */	beq .L_8005926C
/* 80059278 00056078  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8005927C 0005607C  7C 08 03 A6 */	mtlr r0
/* 80059280 00056080  38 21 00 10 */	addi r1, r1, 0x10
/* 80059284 00056084  4E 80 00 20 */	blr
.endfn kar_lbfile_devcom_copy_blocking

# .text:0x46C | 0x80059288 | size: 0xDC
.fn kar_lbfile_read_entrynum_async, global
/* 80059288 00056088  94 21 FF 90 */	stwu r1, -0x70(r1)
/* 8005928C 0005608C  7C 08 02 A6 */	mflr r0
/* 80059290 00056090  90 01 00 74 */	stw r0, 0x74(r1)
/* 80059294 00056094  39 61 00 70 */	addi r11, r1, 0x70
/* 80059298 00056098  48 35 48 B1 */	bl _savegpr_24
/* 8005929C 0005609C  7C 78 1B 78 */	mr r24, r3
/* 800592A0 000560A0  7C 99 23 78 */	mr r25, r4
/* 800592A4 000560A4  7C BA 2B 78 */	mr r26, r5
/* 800592A8 000560A8  7C DB 33 78 */	mr r27, r6
/* 800592AC 000560AC  7C FC 3B 78 */	mr r28, r7
/* 800592B0 000560B0  7D 1D 43 78 */	mr r29, r8
/* 800592B4 000560B4  48 37 DD F5 */	bl OSDisableInterrupts
/* 800592B8 000560B8  7C 7F 1B 78 */	mr r31, r3
/* 800592BC 000560BC  7F 03 C3 78 */	mr r3, r24
/* 800592C0 000560C0  38 81 00 08 */	addi r4, r1, 0x8
/* 800592C4 000560C4  48 36 BF 05 */	bl kar_lbfile__803c51c8
/* 800592C8 000560C8  2C 03 00 00 */	cmpwi r3, 0x0
/* 800592CC 000560CC  40 82 00 2C */	bne .L_800592F8
/* 800592D0 000560D0  3C 60 80 4A */	lis r3, lbl_80498140@ha
/* 800592D4 000560D4  7F 04 C3 78 */	mr r4, r24
/* 800592D8 000560D8  38 63 81 40 */	addi r3, r3, lbl_80498140@l
/* 800592DC 000560DC  4C C6 31 82 */	crclr cr1eq
/* 800592E0 000560E0  48 37 BA 09 */	bl OSReport
/* 800592E4 000560E4  3C 60 80 4A */	lis r3, kar_src_lbfile_80498108@ha
/* 800592E8 000560E8  38 80 01 26 */	li r4, 0x126
/* 800592EC 000560EC  38 63 81 08 */	addi r3, r3, kar_src_lbfile_80498108@l
/* 800592F0 000560F0  38 AD 81 8C */	li r5, lbl_805D526C@sda21
/* 800592F4 000560F4  48 3C F1 C5 */	bl __assert
.L_800592F8:
/* 800592F8 000560F8  83 C1 00 3C */	lwz r30, 0x3c(r1)
/* 800592FC 000560FC  38 61 00 08 */	addi r3, r1, 0x8
/* 80059300 00056100  48 36 C0 05 */	bl DVDClose
/* 80059304 00056104  7F E3 FB 78 */	mr r3, r31
/* 80059308 00056108  48 37 DD C9 */	bl OSRestoreInterrupts
/* 8005930C 0005610C  93 DA 00 00 */	stw r30, 0x0(r26)
/* 80059310 00056110  3C 00 80 00 */	lis r0, 0x8000
/* 80059314 00056114  7C 19 00 40 */	cmplw r25, r0
/* 80059318 00056118  7F 03 C3 78 */	mr r3, r24
/* 8005931C 0005611C  80 DA 00 00 */	lwz r6, 0x0(r26)
/* 80059320 00056120  7F 25 CB 78 */	mr r5, r25
/* 80059324 00056124  38 80 00 00 */	li r4, 0x0
/* 80059328 00056128  38 E0 00 23 */	li r7, 0x23
/* 8005932C 0005612C  38 06 00 1F */	addi r0, r6, 0x1f
/* 80059330 00056130  54 06 00 34 */	clrrwi r6, r0, 5
/* 80059334 00056134  41 80 00 08 */	blt .L_8005933C
/* 80059338 00056138  38 E0 00 21 */	li r7, 0x21
.L_8005933C:
/* 8005933C 0005613C  7F 68 DB 78 */	mr r8, r27
/* 80059340 00056140  7F 89 E3 78 */	mr r9, r28
/* 80059344 00056144  7F AA EB 78 */	mr r10, r29
/* 80059348 00056148  48 3E D7 85 */	bl HSD_DevComRequest
/* 8005934C 0005614C  39 61 00 70 */	addi r11, r1, 0x70
/* 80059350 00056150  48 35 48 45 */	bl _restgpr_24
/* 80059354 00056154  80 01 00 74 */	lwz r0, 0x74(r1)
/* 80059358 00056158  7C 08 03 A6 */	mtlr r0
/* 8005935C 0005615C  38 21 00 70 */	addi r1, r1, 0x70
/* 80059360 00056160  4E 80 00 20 */	blr
.endfn kar_lbfile_read_entrynum_async

# .text:0x548 | 0x80059364 | size: 0x120
.fn kar_lbfile_read_path_blocking, global
/* 80059364 00056164  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 80059368 00056168  7C 08 02 A6 */	mflr r0
/* 8005936C 0005616C  90 01 00 64 */	stw r0, 0x64(r1)
/* 80059370 00056170  39 61 00 60 */	addi r11, r1, 0x60
/* 80059374 00056174  48 35 47 E1 */	bl _savegpr_27
/* 80059378 00056178  38 00 00 00 */	li r0, 0x0
/* 8005937C 0005617C  3C C0 80 4A */	lis r6, kar_src_lbfile_80498108@ha
/* 80059380 00056180  90 0D 04 C8 */	stw r0, lbl_805DD5A8@sda21(r0)
/* 80059384 00056184  7C 9B 23 78 */	mr r27, r4
/* 80059388 00056188  7C BC 2B 78 */	mr r28, r5
/* 8005938C 0005618C  3B E6 81 08 */	addi r31, r6, kar_src_lbfile_80498108@l
/* 80059390 00056190  4B FF FA F5 */	bl kar_lbfile_build_localized_filename
/* 80059394 00056194  7C 7D 1B 78 */	mr r29, r3
/* 80059398 00056198  48 36 BB 3D */	bl DVDConvertPathToEntrynum
/* 8005939C 0005619C  7C 7E 1B 78 */	mr r30, r3
/* 800593A0 000561A0  2C 1E FF FF */	cmpwi r30, -0x1
/* 800593A4 000561A4  40 82 00 28 */	bne .L_800593CC
/* 800593A8 000561A8  7F A4 EB 78 */	mr r4, r29
/* 800593AC 000561AC  7F C5 F3 78 */	mr r5, r30
/* 800593B0 000561B0  38 7F 00 50 */	addi r3, r31, 0x50
/* 800593B4 000561B4  4C C6 31 82 */	crclr cr1eq
/* 800593B8 000561B8  48 37 B9 31 */	bl OSReport
/* 800593BC 000561BC  38 7F 00 00 */	addi r3, r31, 0x0
/* 800593C0 000561C0  38 BF 00 6C */	addi r5, r31, 0x6c
/* 800593C4 000561C4  38 80 01 8A */	li r4, 0x18a
/* 800593C8 000561C8  48 3C F0 F1 */	bl __assert
.L_800593CC:
/* 800593CC 000561CC  48 37 DC DD */	bl OSDisableInterrupts
/* 800593D0 000561D0  7C 7D 1B 78 */	mr r29, r3
/* 800593D4 000561D4  7F C3 F3 78 */	mr r3, r30
/* 800593D8 000561D8  38 81 00 08 */	addi r4, r1, 0x8
/* 800593DC 000561DC  48 36 BD ED */	bl kar_lbfile__803c51c8
/* 800593E0 000561E0  2C 03 00 00 */	cmpwi r3, 0x0
/* 800593E4 000561E4  40 82 00 24 */	bne .L_80059408
/* 800593E8 000561E8  7F C4 F3 78 */	mr r4, r30
/* 800593EC 000561EC  38 7F 00 38 */	addi r3, r31, 0x38
/* 800593F0 000561F0  4C C6 31 82 */	crclr cr1eq
/* 800593F4 000561F4  48 37 B8 F5 */	bl OSReport
/* 800593F8 000561F8  38 7F 00 00 */	addi r3, r31, 0x0
/* 800593FC 000561FC  38 80 01 26 */	li r4, 0x126
/* 80059400 00056200  38 AD 81 8C */	li r5, lbl_805D526C@sda21
/* 80059404 00056204  48 3C F0 B5 */	bl __assert
.L_80059408:
/* 80059408 00056208  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 8005940C 0005620C  38 61 00 08 */	addi r3, r1, 0x8
/* 80059410 00056210  48 36 BE F5 */	bl DVDClose
/* 80059414 00056214  7F A3 EB 78 */	mr r3, r29
/* 80059418 00056218  48 37 DC B9 */	bl OSRestoreInterrupts
/* 8005941C 0005621C  93 FC 00 00 */	stw r31, 0x0(r28)
/* 80059420 00056220  3C 00 80 00 */	lis r0, 0x8000
/* 80059424 00056224  7C 1B 00 40 */	cmplw r27, r0
/* 80059428 00056228  7F C3 F3 78 */	mr r3, r30
/* 8005942C 0005622C  80 DC 00 00 */	lwz r6, 0x0(r28)
/* 80059430 00056230  7F 65 DB 78 */	mr r5, r27
/* 80059434 00056234  38 80 00 00 */	li r4, 0x0
/* 80059438 00056238  38 E0 00 23 */	li r7, 0x23
/* 8005943C 0005623C  38 06 00 1F */	addi r0, r6, 0x1f
/* 80059440 00056240  54 06 00 34 */	clrrwi r6, r0, 5
/* 80059444 00056244  41 80 00 08 */	blt .L_8005944C
/* 80059448 00056248  38 E0 00 21 */	li r7, 0x21
.L_8005944C:
/* 8005944C 0005624C  3D 00 80 06 */	lis r8, kar_lbfile_async_done_callback@ha
/* 80059450 00056250  39 40 00 00 */	li r10, 0x0
/* 80059454 00056254  39 28 8E 1C */	addi r9, r8, kar_lbfile_async_done_callback@l
/* 80059458 00056258  39 00 00 01 */	li r8, 0x1
/* 8005945C 0005625C  48 3E D6 71 */	bl HSD_DevComRequest
.L_80059460:
/* 80059460 00056260  4B FF FA 01 */	bl kar_lbfile_poll_async_done
/* 80059464 00056264  2C 03 00 00 */	cmpwi r3, 0x0
/* 80059468 00056268  41 82 FF F8 */	beq .L_80059460
/* 8005946C 0005626C  39 61 00 60 */	addi r11, r1, 0x60
/* 80059470 00056270  48 35 47 31 */	bl _restgpr_27
/* 80059474 00056274  80 01 00 64 */	lwz r0, 0x64(r1)
/* 80059478 00056278  7C 08 03 A6 */	mtlr r0
/* 8005947C 0005627C  38 21 00 60 */	addi r1, r1, 0x60
/* 80059480 00056280  4E 80 00 20 */	blr
.endfn kar_lbfile_read_path_blocking

# 0x80498108..0x80498188 | size: 0x80
.data
.balign 8

# .data:0x0 | 0x80498108 | size: 0x9
.obj kar_src_lbfile_80498108, global
	.string "lbfile.c"
.endobj kar_src_lbfile_80498108

# .data:0x9 | 0x80498111 | size: 0x3
.obj gap_07_80498111_data, global
.hidden gap_07_80498111_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_80498111_data

# .data:0xC | 0x80498114 | size: 0xC
.obj lbl_80498114, global
	.string "!cancelflag"
.endobj lbl_80498114

# .data:0x18 | 0x80498120 | size: 0x1F
.obj lbl_80498120, global
	.string "Error : file name too long %s."
.endobj lbl_80498120

# .data:0x37 | 0x8049813F | size: 0x1
.obj gap_07_8049813F_data, global
.hidden gap_07_8049813F_data
	.byte 0x00
.endobj gap_07_8049813F_data

# .data:0x38 | 0x80498140 | size: 0x48
.obj lbl_80498140, global
	.4byte 0x43616E6E
	.4byte 0x6F74206F
	.4byte 0x70656E20
	.4byte 0x66696C65
	.4byte 0x206E6F3D
	.4byte 0x25642E00
	.4byte 0x66696C65
	.4byte 0x2069736E
	.4byte 0x27742065
	.4byte 0x78697374
	.4byte 0x20257320
	.4byte 0x3D202564
	.4byte 0x0A000000
	.4byte 0x656E7472
	.4byte 0x795F6E75
	.4byte 0x6D20213D
	.4byte 0x202D3100
	.4byte 0x00000000
.endobj lbl_80498140

# 0x80538068..0x80538088 | size: 0x20
.section .bss, "wa", @nobits
.balign 8

# .bss:0x0 | 0x80538068 | size: 0x20
.obj kar_lbfile_path_buffer, global
	.skip 0x20
.endobj kar_lbfile_path_buffer

# 0x805D5260..0x805D5270 | size: 0x10
.section .sdata, "wa"
.balign 8

# .sdata:0x0 | 0x805D5260 | size: 0x5
.obj lbl_805D5260, global
	.string "NULL"
.endobj lbl_805D5260

# .sdata:0x5 | 0x805D5265 | size: 0x3
.obj gap_09_805D5265_sdata, global
.hidden gap_09_805D5265_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D5265_sdata

# .sdata:0x8 | 0x805D5268 | size: 0x4
.obj lbl_805D5268, global
	.string "dat"
.endobj lbl_805D5268

# .sdata:0xC | 0x805D526C | size: 0x2
.obj lbl_805D526C, global
	.string "0"
.endobj lbl_805D526C

# .sdata:0xE | 0x805D526E | size: 0x2
.obj gap_09_805D526E_sdata, global
.hidden gap_09_805D526E_sdata
	.2byte 0x0000
.endobj gap_09_805D526E_sdata

# 0x805DD5A8..0x805DD5B0 | size: 0x8
.section .sbss, "wa", @nobits
.balign 8

# .sbss:0x0 | 0x805DD5A8 | size: 0x8
.obj lbl_805DD5A8, global
	.skip 0x8
.endobj lbl_805DD5A8
