.include "macros.inc"
.file "grmachine2.c"

# 0x8010E95C..0x8010EC10 | size: 0x2B4
.text
.balign 4

# .text:0x0 | 0x8010E95C | size: 0xE4
.fn kar_grmachine2_init_loop_anim_and_individual_fgm_ids, global
/* 8010E95C 0010B75C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8010E960 0010B760  7C 08 02 A6 */	mflr r0
/* 8010E964 0010B764  90 01 00 24 */	stw r0, 0x24(r1)
/* 8010E968 0010B768  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8010E96C 0010B76C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8010E970 0010B770  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8010E974 0010B774  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 8010E978 0010B778  3C 60 80 4A */	lis r3, kar_grmachine2_callback_table@ha
/* 8010E97C 0010B77C  3B E3 76 98 */	addi r31, r3, kar_grmachine2_callback_table@l
/* 8010E980 0010B780  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 8010E984 0010B784  38 60 00 00 */	li r3, 0x0
/* 8010E988 0010B788  83 A4 00 08 */	lwz r29, 0x8(r4)
/* 8010E98C 0010B78C  28 1D 00 00 */	cmplwi r29, 0x0
/* 8010E990 0010B790  41 82 00 14 */	beq .L_8010E9A4
/* 8010E994 0010B794  80 1D 00 00 */	lwz r0, 0x0(r29)
/* 8010E998 0010B798  28 00 00 00 */	cmplwi r0, 0x0
/* 8010E99C 0010B79C  41 82 00 08 */	beq .L_8010E9A4
/* 8010E9A0 0010B7A0  38 60 00 01 */	li r3, 0x1
.L_8010E9A4:
/* 8010E9A4 0010B7A4  2C 03 00 00 */	cmpwi r3, 0x0
/* 8010E9A8 0010B7A8  40 82 00 14 */	bne .L_8010E9BC
/* 8010E9AC 0010B7AC  38 7F 00 0C */	addi r3, r31, 0xc
/* 8010E9B0 0010B7B0  38 BF 00 1C */	addi r5, r31, 0x1c
/* 8010E9B4 0010B7B4  38 80 00 2B */	li r4, 0x2b
/* 8010E9B8 0010B7B8  48 31 9B 01 */	bl __assert
.L_8010E9BC:
/* 8010E9BC 0010B7BC  80 9D 00 00 */	lwz r4, 0x0(r29)
/* 8010E9C0 0010B7C0  7F C3 F3 78 */	mr r3, r30
/* 8010E9C4 0010B7C4  4B FC D4 85 */	bl kar_granim__800dbe48
/* 8010E9C8 0010B7C8  80 7D 00 04 */	lwz r3, 0x4(r29)
/* 8010E9CC 0010B7CC  80 03 00 04 */	lwz r0, 0x4(r3)
/* 8010E9D0 0010B7D0  2C 00 00 0A */	cmpwi r0, 0xa
/* 8010E9D4 0010B7D4  40 81 00 14 */	ble .L_8010E9E8
/* 8010E9D8 0010B7D8  38 7F 00 0C */	addi r3, r31, 0xc
/* 8010E9DC 0010B7DC  38 BF 00 44 */	addi r5, r31, 0x44
/* 8010E9E0 0010B7E0  38 80 00 31 */	li r4, 0x31
/* 8010E9E4 0010B7E4  48 31 9A D5 */	bl __assert
.L_8010E9E8:
/* 8010E9E8 0010B7E8  7F C5 F3 78 */	mr r5, r30
/* 8010E9EC 0010B7EC  38 C0 00 00 */	li r6, 0x0
/* 8010E9F0 0010B7F0  38 80 00 00 */	li r4, 0x0
/* 8010E9F4 0010B7F4  48 00 00 20 */	b .L_8010EA14
.L_8010E9F8:
/* 8010E9F8 0010B7F8  80 63 00 00 */	lwz r3, 0x0(r3)
/* 8010E9FC 0010B7FC  38 04 00 08 */	addi r0, r4, 0x8
/* 8010EA00 0010B800  38 84 00 10 */	addi r4, r4, 0x10
/* 8010EA04 0010B804  38 C6 00 01 */	addi r6, r6, 0x1
/* 8010EA08 0010B808  7C 03 00 2E */	lwzx r0, r3, r0
/* 8010EA0C 0010B80C  90 05 07 28 */	stw r0, 0x728(r5)
/* 8010EA10 0010B810  38 A5 00 04 */	addi r5, r5, 0x4
.L_8010EA14:
/* 8010EA14 0010B814  80 7D 00 04 */	lwz r3, 0x4(r29)
/* 8010EA18 0010B818  80 03 00 04 */	lwz r0, 0x4(r3)
/* 8010EA1C 0010B81C  7C 06 00 00 */	cmpw r6, r0
/* 8010EA20 0010B820  41 80 FF D8 */	blt .L_8010E9F8
/* 8010EA24 0010B824  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8010EA28 0010B828  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8010EA2C 0010B82C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8010EA30 0010B830  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8010EA34 0010B834  7C 08 03 A6 */	mtlr r0
/* 8010EA38 0010B838  38 21 00 20 */	addi r1, r1, 0x20
/* 8010EA3C 0010B83C  4E 80 00 20 */	blr
.endfn kar_grmachine2_init_loop_anim_and_individual_fgm_ids

# .text:0xE4 | 0x8010EA40 | size: 0x174
.fn kar_grmachine2_create_stage_mechanism_yaku_objects, global
/* 8010EA40 0010B840  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010EA44 0010B844  7C 08 02 A6 */	mflr r0
/* 8010EA48 0010B848  38 80 00 00 */	li r4, 0x0
/* 8010EA4C 0010B84C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010EA50 0010B850  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010EA54 0010B854  7C 7F 1B 78 */	mr r31, r3
/* 8010EA58 0010B858  4B FE B8 49 */	bl kar_gryakudownforcezone_create_stage_linked_kind17_yaku
/* 8010EA5C 0010B85C  7F E3 FB 78 */	mr r3, r31
/* 8010EA60 0010B860  38 80 00 01 */	li r4, 0x1
/* 8010EA64 0010B864  4B FF 02 BD */	bl kar_gryakugondola_create_stage_linked_kind48_route_yaku
/* 8010EA68 0010B868  7F E3 FB 78 */	mr r3, r31
/* 8010EA6C 0010B86C  38 80 00 02 */	li r4, 0x2
/* 8010EA70 0010B870  4B FF 4B E5 */	bl kar_gryakuanimfloor_create_stage_linked_kind55_reactive_floor
/* 8010EA74 0010B874  7F E3 FB 78 */	mr r3, r31
/* 8010EA78 0010B878  38 80 00 03 */	li r4, 0x3
/* 8010EA7C 0010B87C  4B FF 4B D9 */	bl kar_gryakuanimfloor_create_stage_linked_kind55_reactive_floor
/* 8010EA80 0010B880  7F E3 FB 78 */	mr r3, r31
/* 8010EA84 0010B884  38 80 00 04 */	li r4, 0x4
/* 8010EA88 0010B888  4B FF 4B CD */	bl kar_gryakuanimfloor_create_stage_linked_kind55_reactive_floor
/* 8010EA8C 0010B88C  7F E3 FB 78 */	mr r3, r31
/* 8010EA90 0010B890  38 80 00 05 */	li r4, 0x5
/* 8010EA94 0010B894  4B FF 73 25 */	bl kar_gryakubreakcommon_create_stage_linked_kind56_delayed_collision
/* 8010EA98 0010B898  7F E3 FB 78 */	mr r3, r31
/* 8010EA9C 0010B89C  38 80 00 06 */	li r4, 0x6
/* 8010EAA0 0010B8A0  4B FF 73 19 */	bl kar_gryakubreakcommon_create_stage_linked_kind56_delayed_collision
/* 8010EAA4 0010B8A4  7F E3 FB 78 */	mr r3, r31
/* 8010EAA8 0010B8A8  38 80 00 07 */	li r4, 0x7
/* 8010EAAC 0010B8AC  4B FF 73 0D */	bl kar_gryakubreakcommon_create_stage_linked_kind56_delayed_collision
/* 8010EAB0 0010B8B0  7F E3 FB 78 */	mr r3, r31
/* 8010EAB4 0010B8B4  38 80 00 08 */	li r4, 0x8
/* 8010EAB8 0010B8B8  4B FF 73 01 */	bl kar_gryakubreakcommon_create_stage_linked_kind56_delayed_collision
/* 8010EABC 0010B8BC  7F E3 FB 78 */	mr r3, r31
/* 8010EAC0 0010B8C0  38 80 00 09 */	li r4, 0x9
/* 8010EAC4 0010B8C4  4B FF 72 F5 */	bl kar_gryakubreakcommon_create_stage_linked_kind56_delayed_collision
/* 8010EAC8 0010B8C8  7F E3 FB 78 */	mr r3, r31
/* 8010EACC 0010B8CC  38 80 00 0A */	li r4, 0xa
/* 8010EAD0 0010B8D0  4B FF 86 51 */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 8010EAD4 0010B8D4  7F E3 FB 78 */	mr r3, r31
/* 8010EAD8 0010B8D8  38 80 00 0B */	li r4, 0xb
/* 8010EADC 0010B8DC  4B FF 86 45 */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 8010EAE0 0010B8E0  7F E3 FB 78 */	mr r3, r31
/* 8010EAE4 0010B8E4  38 80 00 0C */	li r4, 0xc
/* 8010EAE8 0010B8E8  4B FF 86 39 */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 8010EAEC 0010B8EC  7F E3 FB 78 */	mr r3, r31
/* 8010EAF0 0010B8F0  38 80 00 0D */	li r4, 0xd
/* 8010EAF4 0010B8F4  4B FF 86 2D */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 8010EAF8 0010B8F8  7F E3 FB 78 */	mr r3, r31
/* 8010EAFC 0010B8FC  38 80 00 0E */	li r4, 0xe
/* 8010EB00 0010B900  4B FF 86 21 */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 8010EB04 0010B904  7F E3 FB 78 */	mr r3, r31
/* 8010EB08 0010B908  38 80 00 0F */	li r4, 0xf
/* 8010EB0C 0010B90C  4B FF 86 15 */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 8010EB10 0010B910  7F E3 FB 78 */	mr r3, r31
/* 8010EB14 0010B914  38 80 00 10 */	li r4, 0x10
/* 8010EB18 0010B918  4B FF 86 09 */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 8010EB1C 0010B91C  7F E3 FB 78 */	mr r3, r31
/* 8010EB20 0010B920  38 80 00 11 */	li r4, 0x11
/* 8010EB24 0010B924  4B FF 85 FD */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 8010EB28 0010B928  7F E3 FB 78 */	mr r3, r31
/* 8010EB2C 0010B92C  38 80 00 12 */	li r4, 0x12
/* 8010EB30 0010B930  4B FF 85 F1 */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 8010EB34 0010B934  7F E3 FB 78 */	mr r3, r31
/* 8010EB38 0010B938  38 80 00 13 */	li r4, 0x13
/* 8010EB3C 0010B93C  4B FF 85 E5 */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 8010EB40 0010B940  7F E3 FB 78 */	mr r3, r31
/* 8010EB44 0010B944  38 80 00 14 */	li r4, 0x14
/* 8010EB48 0010B948  4B FF 85 D9 */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 8010EB4C 0010B94C  7F E3 FB 78 */	mr r3, r31
/* 8010EB50 0010B950  38 80 00 15 */	li r4, 0x15
/* 8010EB54 0010B954  4B FF 85 CD */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 8010EB58 0010B958  7F E3 FB 78 */	mr r3, r31
/* 8010EB5C 0010B95C  38 80 00 16 */	li r4, 0x16
/* 8010EB60 0010B960  4B FF 85 C1 */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 8010EB64 0010B964  7F E3 FB 78 */	mr r3, r31
/* 8010EB68 0010B968  38 80 00 17 */	li r4, 0x17
/* 8010EB6C 0010B96C  4B FF 85 B5 */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 8010EB70 0010B970  7F E3 FB 78 */	mr r3, r31
/* 8010EB74 0010B974  38 80 00 18 */	li r4, 0x18
/* 8010EB78 0010B978  4B FF 85 A9 */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 8010EB7C 0010B97C  7F E3 FB 78 */	mr r3, r31
/* 8010EB80 0010B980  38 80 00 19 */	li r4, 0x19
/* 8010EB84 0010B984  4B FF 85 9D */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 8010EB88 0010B988  7F E3 FB 78 */	mr r3, r31
/* 8010EB8C 0010B98C  38 80 00 1A */	li r4, 0x1a
/* 8010EB90 0010B990  4B FF 85 91 */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 8010EB94 0010B994  7F E3 FB 78 */	mr r3, r31
/* 8010EB98 0010B998  38 80 00 1B */	li r4, 0x1b
/* 8010EB9C 0010B99C  4B FF 85 85 */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 8010EBA0 0010B9A0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010EBA4 0010B9A4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010EBA8 0010B9A8  7C 08 03 A6 */	mtlr r0
/* 8010EBAC 0010B9AC  38 21 00 10 */	addi r1, r1, 0x10
/* 8010EBB0 0010B9B0  4E 80 00 20 */	blr
.endfn kar_grmachine2_create_stage_mechanism_yaku_objects

# .text:0x258 | 0x8010EBB4 | size: 0x58
.fn kar_grmachine2_update_individual_fgm_timers, global
/* 8010EBB4 0010B9B4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010EBB8 0010B9B8  7C 08 02 A6 */	mflr r0
/* 8010EBBC 0010B9BC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010EBC0 0010B9C0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010EBC4 0010B9C4  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8010EBC8 0010B9C8  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8010EBCC 0010B9CC  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 8010EBD0 0010B9D0  7F E3 FB 78 */	mr r3, r31
/* 8010EBD4 0010B9D4  83 C4 00 08 */	lwz r30, 0x8(r4)
/* 8010EBD8 0010B9D8  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 8010EBDC 0010B9DC  4B FD B8 0D */	bl kar_graudio_configure_individual_fgm_tracks
/* 8010EBE0 0010B9E0  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 8010EBE4 0010B9E4  7F E3 FB 78 */	mr r3, r31
/* 8010EBE8 0010B9E8  38 BF 07 28 */	addi r5, r31, 0x728
/* 8010EBEC 0010B9EC  38 C0 00 0A */	li r6, 0xa
/* 8010EBF0 0010B9F0  4B FD B9 79 */	bl kar_graudio_update_individual_fgm_timers
/* 8010EBF4 0010B9F4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010EBF8 0010B9F8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010EBFC 0010B9FC  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8010EC00 0010BA00  7C 08 03 A6 */	mtlr r0
/* 8010EC04 0010BA04  38 21 00 10 */	addi r1, r1, 0x10
/* 8010EC08 0010BA08  4E 80 00 20 */	blr
.endfn kar_grmachine2_update_individual_fgm_timers

# .text:0x2B0 | 0x8010EC0C | size: 0x4
.fn fn_8010EC0C, global
/* 8010EC0C 0010BA0C  4E 80 00 20 */	blr
.endfn fn_8010EC0C

# 0x804A7698..0x804A7730 | size: 0x98
.data
.balign 8

# .data:0x0 | 0x804A7698 | size: 0x88
.obj kar_grmachine2_callback_table, global
	.4byte kar_grmachine2_init_loop_anim_and_individual_fgm_ids
	.4byte kar_grmachine2_create_stage_mechanism_yaku_objects
	.4byte kar_grmachine2_update_individual_fgm_timers
	.4byte 0x67726D61
	.4byte 0x6368696E
	.4byte 0x65322E63
	.4byte 0x00000000
	.4byte 0x696E6469
	.4byte 0x76695061
	.4byte 0x72616D20
	.4byte 0x26262069
	.4byte 0x6E646976
	.4byte 0x69506172
	.4byte 0x616D2D3E
	.4byte 0x6C6F6F70
	.4byte 0x416E696D
	.4byte 0x416C6C00
	.4byte 0x696E6469
	.4byte 0x76695061
	.4byte 0x72616D2D
	.4byte 0x3E696E64
	.4byte 0x69766946
	.4byte 0x676D416C
	.4byte 0x6C2D3E69
	.4byte 0x6E646976
	.4byte 0x6946676D
	.4byte 0x4E756D20
	.4byte 0x3C3D2047
	.4byte 0x724D6163
	.4byte 0x68696E65
	.4byte 0x325F4667
	.4byte 0x6D436F75
	.4byte 0x6E746572
	.4byte 0x4E756D00
.endobj kar_grmachine2_callback_table

# .data:0x88 | 0x804A7720 | size: 0x10
.obj lbl_804A7720, global
	.4byte fn_8010EC0C
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A7720
