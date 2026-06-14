.include "macros.inc"
.file "grglobaldead.c"

# 0x800EE984..0x800EEB9C | size: 0x218
.text
.balign 4

# .text:0x0 | 0x800EE984 | size: 0xD8
.fn kar_grglobaldead_init, global
/* 800EE984 000EB784  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 800EE988 000EB788  7C 08 02 A6 */	mflr r0
/* 800EE98C 000EB78C  90 01 00 54 */	stw r0, 0x54(r1)
/* 800EE990 000EB790  39 61 00 50 */	addi r11, r1, 0x50
/* 800EE994 000EB794  48 2B F1 BD */	bl _savegpr_26
/* 800EE998 000EB798  7C 7A 1B 78 */	mr r26, r3
/* 800EE99C 000EB79C  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800EE9A0 000EB7A0  83 83 00 4C */	lwz r28, 0x4c(r3)
/* 800EE9A4 000EB7A4  28 1C 00 00 */	cmplwi r28, 0x0
/* 800EE9A8 000EB7A8  41 82 00 0C */	beq .L_800EE9B4
/* 800EE9AC 000EB7AC  83 FC 00 04 */	lwz r31, 0x4(r28)
/* 800EE9B0 000EB7B0  48 00 00 08 */	b .L_800EE9B8
.L_800EE9B4:
/* 800EE9B4 000EB7B4  3B E0 00 00 */	li r31, 0x0
.L_800EE9B8:
/* 800EE9B8 000EB7B8  2C 1F 00 00 */	cmpwi r31, 0x0
/* 800EE9BC 000EB7BC  41 82 00 88 */	beq .L_800EEA44
/* 800EE9C0 000EB7C0  4B FF 69 59 */	bl kar_grnullpos_get_global_dead_pos_count
/* 800EE9C4 000EB7C4  7C 1F 18 00 */	cmpw r31, r3
/* 800EE9C8 000EB7C8  40 81 00 1C */	ble .L_800EE9E4
/* 800EE9CC 000EB7CC  3C 60 80 4A */	lis r3, kar_src_grglobaldead_804a5618@ha
/* 800EE9D0 000EB7D0  3C A0 80 4A */	lis r5, lbl_804A5628@ha
/* 800EE9D4 000EB7D4  38 63 56 18 */	addi r3, r3, kar_src_grglobaldead_804a5618@l
/* 800EE9D8 000EB7D8  38 80 00 2C */	li r4, 0x2c
/* 800EE9DC 000EB7DC  38 A5 56 28 */	addi r5, r5, lbl_804A5628@l
/* 800EE9E0 000EB7E0  48 33 9A D9 */	bl __assert
.L_800EE9E4:
/* 800EE9E4 000EB7E4  1C 7F 00 0C */	mulli r3, r31, 0xc
/* 800EE9E8 000EB7E8  93 9A 07 08 */	stw r28, 0x708(r26)
/* 800EE9EC 000EB7EC  48 32 E4 F9 */	bl HSD_Alloc
/* 800EE9F0 000EB7F0  3B C0 00 00 */	li r30, 0x0
/* 800EE9F4 000EB7F4  90 7A 07 0C */	stw r3, 0x70c(r26)
/* 800EE9F8 000EB7F8  7F DD F3 78 */	mr r29, r30
/* 800EE9FC 000EB7FC  3B 60 00 00 */	li r27, 0x0
/* 800EEA00 000EB800  48 00 00 3C */	b .L_800EEA3C
.L_800EEA04:
/* 800EEA04 000EB804  7F 63 DB 78 */	mr r3, r27
/* 800EEA08 000EB808  38 81 00 20 */	addi r4, r1, 0x20
/* 800EEA0C 000EB80C  38 A1 00 14 */	addi r5, r1, 0x14
/* 800EEA10 000EB810  38 C1 00 08 */	addi r6, r1, 0x8
/* 800EEA14 000EB814  4B FF 69 2D */	bl kar_grnullpos_get_global_dead_pos
/* 800EEA18 000EB818  80 9C 00 00 */	lwz r4, 0x0(r28)
/* 800EEA1C 000EB81C  38 61 00 20 */	addi r3, r1, 0x20
/* 800EEA20 000EB820  80 1A 07 0C */	lwz r0, 0x70c(r26)
/* 800EEA24 000EB824  7C 84 E8 2E */	lwzx r4, r4, r29
/* 800EEA28 000EB828  7C A0 F2 14 */	add r5, r0, r30
/* 800EEA2C 000EB82C  4B FE 04 8D */	bl kar_grcommon__800ceeb8
/* 800EEA30 000EB830  3B DE 00 0C */	addi r30, r30, 0xc
/* 800EEA34 000EB834  3B BD 00 04 */	addi r29, r29, 0x4
/* 800EEA38 000EB838  3B 7B 00 01 */	addi r27, r27, 0x1
.L_800EEA3C:
/* 800EEA3C 000EB83C  7C 1B F8 00 */	cmpw r27, r31
/* 800EEA40 000EB840  41 80 FF C4 */	blt .L_800EEA04
.L_800EEA44:
/* 800EEA44 000EB844  39 61 00 50 */	addi r11, r1, 0x50
/* 800EEA48 000EB848  48 2B F1 55 */	bl _restgpr_26
/* 800EEA4C 000EB84C  80 01 00 54 */	lwz r0, 0x54(r1)
/* 800EEA50 000EB850  7C 08 03 A6 */	mtlr r0
/* 800EEA54 000EB854  38 21 00 50 */	addi r1, r1, 0x50
/* 800EEA58 000EB858  4E 80 00 20 */	blr
.endfn kar_grglobaldead_init

# .text:0xD8 | 0x800EEA5C | size: 0x48
.fn kar_grglobaldead_destroy, global
/* 800EEA5C 000EB85C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800EEA60 000EB860  7C 08 02 A6 */	mflr r0
/* 800EEA64 000EB864  90 01 00 14 */	stw r0, 0x14(r1)
/* 800EEA68 000EB868  80 83 00 08 */	lwz r4, 0x8(r3)
/* 800EEA6C 000EB86C  80 84 00 4C */	lwz r4, 0x4c(r4)
/* 800EEA70 000EB870  28 04 00 00 */	cmplwi r4, 0x0
/* 800EEA74 000EB874  41 82 00 0C */	beq .L_800EEA80
/* 800EEA78 000EB878  80 04 00 04 */	lwz r0, 0x4(r4)
/* 800EEA7C 000EB87C  48 00 00 08 */	b .L_800EEA84
.L_800EEA80:
/* 800EEA80 000EB880  38 00 00 00 */	li r0, 0x0
.L_800EEA84:
/* 800EEA84 000EB884  2C 00 00 00 */	cmpwi r0, 0x0
/* 800EEA88 000EB888  41 82 00 0C */	beq .L_800EEA94
/* 800EEA8C 000EB88C  80 63 07 0C */	lwz r3, 0x70c(r3)
/* 800EEA90 000EB890  48 32 E4 25 */	bl HSD_Free
.L_800EEA94:
/* 800EEA94 000EB894  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800EEA98 000EB898  7C 08 03 A6 */	mtlr r0
/* 800EEA9C 000EB89C  38 21 00 10 */	addi r1, r1, 0x10
/* 800EEAA0 000EB8A0  4E 80 00 20 */	blr
.endfn kar_grglobaldead_destroy

# .text:0x120 | 0x800EEAA4 | size: 0xF8
.fn kar_grglobaldead_find_nearest_index, global
/* 800EEAA4 000EB8A4  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 800EEAA8 000EB8A8  7C 08 02 A6 */	mflr r0
/* 800EEAAC 000EB8AC  90 01 00 44 */	stw r0, 0x44(r1)
/* 800EEAB0 000EB8B0  DB E1 00 30 */	stfd f31, 0x30(r1)
/* 800EEAB4 000EB8B4  F3 E1 00 38 */	psq_st f31, 0x38(r1), 0, qr0
/* 800EEAB8 000EB8B8  DB C1 00 20 */	stfd f30, 0x20(r1)
/* 800EEABC 000EB8BC  F3 C1 00 28 */	psq_st f30, 0x28(r1), 0, qr0
/* 800EEAC0 000EB8C0  39 61 00 20 */	addi r11, r1, 0x20
/* 800EEAC4 000EB8C4  48 2B F0 8D */	bl _savegpr_26
/* 800EEAC8 000EB8C8  7C 7A 1B 78 */	mr r26, r3
/* 800EEACC 000EB8CC  7C 9B 23 78 */	mr r27, r4
/* 800EEAD0 000EB8D0  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800EEAD4 000EB8D4  80 63 00 4C */	lwz r3, 0x4c(r3)
/* 800EEAD8 000EB8D8  28 03 00 00 */	cmplwi r3, 0x0
/* 800EEADC 000EB8DC  41 82 00 0C */	beq .L_800EEAE8
/* 800EEAE0 000EB8E0  83 E3 00 04 */	lwz r31, 0x4(r3)
/* 800EEAE4 000EB8E4  48 00 00 08 */	b .L_800EEAEC
.L_800EEAE8:
/* 800EEAE8 000EB8E8  3B E0 00 00 */	li r31, 0x0
.L_800EEAEC:
/* 800EEAEC 000EB8EC  2C 1F 00 00 */	cmpwi r31, 0x0
/* 800EEAF0 000EB8F0  C3 C2 90 90 */	lfs f30, lbl_805DF790@sda21(r0)
/* 800EEAF4 000EB8F4  3B A0 FF FF */	li r29, -0x1
/* 800EEAF8 000EB8F8  40 82 00 18 */	bne .L_800EEB10
/* 800EEAFC 000EB8FC  3C 60 80 4A */	lis r3, kar_src_grglobaldead_804a5618@ha
/* 800EEB00 000EB900  38 80 00 59 */	li r4, 0x59
/* 800EEB04 000EB904  38 63 56 18 */	addi r3, r3, kar_src_grglobaldead_804a5618@l
/* 800EEB08 000EB908  38 AD 90 A8 */	li r5, lbl_805D6188@sda21
/* 800EEB0C 000EB90C  48 33 99 AD */	bl __assert
.L_800EEB10:
/* 800EEB10 000EB910  C3 E2 90 94 */	lfs f31, lbl_805DF794@sda21(r0)
/* 800EEB14 000EB914  3B 80 00 00 */	li r28, 0x0
/* 800EEB18 000EB918  3B C0 00 00 */	li r30, 0x0
/* 800EEB1C 000EB91C  48 00 00 40 */	b .L_800EEB5C
.L_800EEB20:
/* 800EEB20 000EB920  80 1A 07 0C */	lwz r0, 0x70c(r26)
/* 800EEB24 000EB924  80 9B 00 00 */	lwz r4, 0x0(r27)
/* 800EEB28 000EB928  7C A0 F2 14 */	add r5, r0, r30
/* 800EEB2C 000EB92C  C0 5B 00 08 */	lfs f2, 0x8(r27)
/* 800EEB30 000EB930  80 65 00 00 */	lwz r3, 0x0(r5)
/* 800EEB34 000EB934  C0 25 00 08 */	lfs f1, 0x8(r5)
/* 800EEB38 000EB938  4B FE 1B 35 */	bl kar_grcommon__near_800d066c
/* 800EEB3C 000EB93C  FC 1F 08 00 */	fcmpu cr0, f31, f1
/* 800EEB40 000EB940  41 82 00 14 */	beq .L_800EEB54
/* 800EEB44 000EB944  FC 01 F0 40 */	fcmpo cr0, f1, f30
/* 800EEB48 000EB948  40 80 00 0C */	bge .L_800EEB54
/* 800EEB4C 000EB94C  FF C0 08 90 */	fmr f30, f1
/* 800EEB50 000EB950  7F 9D E3 78 */	mr r29, r28
.L_800EEB54:
/* 800EEB54 000EB954  3B DE 00 0C */	addi r30, r30, 0xc
/* 800EEB58 000EB958  3B 9C 00 01 */	addi r28, r28, 0x1
.L_800EEB5C:
/* 800EEB5C 000EB95C  7C 1C F8 00 */	cmpw r28, r31
/* 800EEB60 000EB960  41 80 FF C0 */	blt .L_800EEB20
/* 800EEB64 000EB964  2C 1D FF FF */	cmpwi r29, -0x1
/* 800EEB68 000EB968  40 82 00 08 */	bne .L_800EEB70
/* 800EEB6C 000EB96C  3B A0 00 00 */	li r29, 0x0
.L_800EEB70:
/* 800EEB70 000EB970  7F A3 EB 78 */	mr r3, r29
/* 800EEB74 000EB974  E3 E1 00 38 */	psq_l f31, 0x38(r1), 0, qr0
/* 800EEB78 000EB978  CB E1 00 30 */	lfd f31, 0x30(r1)
/* 800EEB7C 000EB97C  E3 C1 00 28 */	psq_l f30, 0x28(r1), 0, qr0
/* 800EEB80 000EB980  39 61 00 20 */	addi r11, r1, 0x20
/* 800EEB84 000EB984  CB C1 00 20 */	lfd f30, 0x20(r1)
/* 800EEB88 000EB988  48 2B F0 15 */	bl _restgpr_26
/* 800EEB8C 000EB98C  80 01 00 44 */	lwz r0, 0x44(r1)
/* 800EEB90 000EB990  7C 08 03 A6 */	mtlr r0
/* 800EEB94 000EB994  38 21 00 40 */	addi r1, r1, 0x40
/* 800EEB98 000EB998  4E 80 00 20 */	blr
.endfn kar_grglobaldead_find_nearest_index

# 0x804A5618..0x804A5648 | size: 0x30
.data
.balign 8

# .data:0x0 | 0x804A5618 | size: 0xF
.obj kar_src_grglobaldead_804a5618, global
	.string "grglobaldead.c"
.endobj kar_src_grglobaldead_804a5618

# .data:0xF | 0x804A5627 | size: 0x1
.obj gap_07_804A5627_data, global
.hidden gap_07_804A5627_data
	.byte 0x00
.endobj gap_07_804A5627_data

# .data:0x10 | 0x804A5628 | size: 0x1F
.obj lbl_804A5628, global
	.string "num <= grGetGlobalDeadPosNum()"
.endobj lbl_804A5628

# .data:0x2F | 0x804A5647 | size: 0x1
.obj gap_07_804A5647_data, global
.hidden gap_07_804A5647_data
	.byte 0x00
.endobj gap_07_804A5647_data

# 0x805D6188..0x805D6190 | size: 0x8
.section .sdata, "wa"
.balign 8

# .sdata:0x0 | 0x805D6188 | size: 0x4
.obj lbl_805D6188, global
	.string "num"
.endobj lbl_805D6188

# .sdata:0x4 | 0x805D618C | size: 0x4
.obj gap_09_805D618C_sdata, global
.hidden gap_09_805D618C_sdata
	.4byte 0x00000000
.endobj gap_09_805D618C_sdata

# 0x805DF790..0x805DF798 | size: 0x8
.section .sdata2, "a"
.balign 8

# .sdata2:0x0 | 0x805DF790 | size: 0x4
.obj lbl_805DF790, global
	.float 340282350000000000000000000000000000000
.endobj lbl_805DF790

# .sdata2:0x4 | 0x805DF794 | size: 0x4
.obj lbl_805DF794, global
	.float -1
.endobj lbl_805DF794
