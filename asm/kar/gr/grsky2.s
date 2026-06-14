.include "macros.inc"
.file "grsky2.c"

# 0x8010EC10..0x8010ED44 | size: 0x134
.text
.balign 4

# .text:0x0 | 0x8010EC10 | size: 0x80
.fn kar_grsky2_init_loop_anim, global
/* 8010EC10 0010BA10  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010EC14 0010BA14  7C 08 02 A6 */	mflr r0
/* 8010EC18 0010BA18  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010EC1C 0010BA1C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010EC20 0010BA20  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8010EC24 0010BA24  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8010EC28 0010BA28  38 60 00 00 */	li r3, 0x0
/* 8010EC2C 0010BA2C  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 8010EC30 0010BA30  83 C4 00 08 */	lwz r30, 0x8(r4)
/* 8010EC34 0010BA34  28 1E 00 00 */	cmplwi r30, 0x0
/* 8010EC38 0010BA38  41 82 00 14 */	beq .L_8010EC4C
/* 8010EC3C 0010BA3C  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 8010EC40 0010BA40  28 00 00 00 */	cmplwi r0, 0x0
/* 8010EC44 0010BA44  41 82 00 08 */	beq .L_8010EC4C
/* 8010EC48 0010BA48  38 60 00 01 */	li r3, 0x1
.L_8010EC4C:
/* 8010EC4C 0010BA4C  2C 03 00 00 */	cmpwi r3, 0x0
/* 8010EC50 0010BA50  40 82 00 1C */	bne .L_8010EC6C
/* 8010EC54 0010BA54  3C 60 80 4A */	lis r3, kar_src_grsky2_c@ha
/* 8010EC58 0010BA58  3C A0 80 4A */	lis r5, kar_grsky2_assert_loop_anim_param_present@ha
/* 8010EC5C 0010BA5C  38 63 77 3C */	addi r3, r3, kar_src_grsky2_c@l
/* 8010EC60 0010BA60  38 80 00 28 */	li r4, 0x28
/* 8010EC64 0010BA64  38 A5 77 48 */	addi r5, r5, kar_grsky2_assert_loop_anim_param_present@l
/* 8010EC68 0010BA68  48 31 98 51 */	bl __assert
.L_8010EC6C:
/* 8010EC6C 0010BA6C  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 8010EC70 0010BA70  7F E3 FB 78 */	mr r3, r31
/* 8010EC74 0010BA74  4B FC D1 D5 */	bl kar_granim__800dbe48
/* 8010EC78 0010BA78  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010EC7C 0010BA7C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010EC80 0010BA80  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8010EC84 0010BA84  7C 08 03 A6 */	mtlr r0
/* 8010EC88 0010BA88  38 21 00 10 */	addi r1, r1, 0x10
/* 8010EC8C 0010BA8C  4E 80 00 20 */	blr
.endfn kar_grsky2_init_loop_anim

# .text:0x80 | 0x8010EC90 | size: 0xB4
.fn kar_grsky2_create_stage_downforce_gondola_yaku, global
/* 8010EC90 0010BA90  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010EC94 0010BA94  7C 08 02 A6 */	mflr r0
/* 8010EC98 0010BA98  38 80 00 00 */	li r4, 0x0
/* 8010EC9C 0010BA9C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010ECA0 0010BAA0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010ECA4 0010BAA4  7C 7F 1B 78 */	mr r31, r3
/* 8010ECA8 0010BAA8  4B FE B5 F9 */	bl kar_gryakudownforcezone_create_stage_linked_kind17_yaku
/* 8010ECAC 0010BAAC  7F E3 FB 78 */	mr r3, r31
/* 8010ECB0 0010BAB0  38 80 00 01 */	li r4, 0x1
/* 8010ECB4 0010BAB4  4B FE B9 5D */	bl kar_gryakucatchzone_create_stage_linked_kind18_yaku
/* 8010ECB8 0010BAB8  7F E3 FB 78 */	mr r3, r31
/* 8010ECBC 0010BABC  38 80 00 02 */	li r4, 0x2
/* 8010ECC0 0010BAC0  4B FE F9 15 */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010ECC4 0010BAC4  7F E3 FB 78 */	mr r3, r31
/* 8010ECC8 0010BAC8  38 80 00 03 */	li r4, 0x3
/* 8010ECCC 0010BACC  4B FE F9 09 */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010ECD0 0010BAD0  7F E3 FB 78 */	mr r3, r31
/* 8010ECD4 0010BAD4  38 80 00 04 */	li r4, 0x4
/* 8010ECD8 0010BAD8  4B FE F8 FD */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010ECDC 0010BADC  7F E3 FB 78 */	mr r3, r31
/* 8010ECE0 0010BAE0  38 80 00 05 */	li r4, 0x5
/* 8010ECE4 0010BAE4  4B FE F8 F1 */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010ECE8 0010BAE8  7F E3 FB 78 */	mr r3, r31
/* 8010ECEC 0010BAEC  38 80 00 06 */	li r4, 0x6
/* 8010ECF0 0010BAF0  4B FE F8 E5 */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010ECF4 0010BAF4  7F E3 FB 78 */	mr r3, r31
/* 8010ECF8 0010BAF8  38 80 00 07 */	li r4, 0x7
/* 8010ECFC 0010BAFC  4B FE F8 D9 */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010ED00 0010BB00  7F E3 FB 78 */	mr r3, r31
/* 8010ED04 0010BB04  38 80 00 08 */	li r4, 0x8
/* 8010ED08 0010BB08  4B FE F8 CD */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010ED0C 0010BB0C  7F E3 FB 78 */	mr r3, r31
/* 8010ED10 0010BB10  38 80 00 09 */	li r4, 0x9
/* 8010ED14 0010BB14  4B FE F8 C1 */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 8010ED18 0010BB18  7F E3 FB 78 */	mr r3, r31
/* 8010ED1C 0010BB1C  38 80 00 0A */	li r4, 0xa
/* 8010ED20 0010BB20  4B FE FE 01 */	bl kar_gryakugondola_create_stage_linked_kind47_ground_audio_yaku
/* 8010ED24 0010BB24  7F E3 FB 78 */	mr r3, r31
/* 8010ED28 0010BB28  38 80 00 0B */	li r4, 0xb
/* 8010ED2C 0010BB2C  4B FF 49 29 */	bl kar_gryakuanimfloor_create_stage_linked_kind55_reactive_floor
/* 8010ED30 0010BB30  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010ED34 0010BB34  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010ED38 0010BB38  7C 08 03 A6 */	mtlr r0
/* 8010ED3C 0010BB3C  38 21 00 10 */	addi r1, r1, 0x10
/* 8010ED40 0010BB40  4E 80 00 20 */	blr
.endfn kar_grsky2_create_stage_downforce_gondola_yaku

# 0x804A7730..0x804A7770 | size: 0x40
.data
.balign 8

# .data:0x0 | 0x804A7730 | size: 0xC
.obj kar_grsky2_callback_table, global
	.4byte kar_grsky2_init_loop_anim
	.4byte kar_grsky2_create_stage_downforce_gondola_yaku
	.4byte 0x00000000
.endobj kar_grsky2_callback_table

# .data:0xC | 0x804A773C | size: 0x9
.obj kar_src_grsky2_c, global
	.string "grsky2.c"
.endobj kar_src_grsky2_c

# .data:0x15 | 0x804A7745 | size: 0x3
.obj gap_07_804A7745_data, global
.hidden gap_07_804A7745_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A7745_data

# .data:0x18 | 0x804A7748 | size: 0x28
.obj kar_grsky2_assert_loop_anim_param_present, global
	.string "indiviParam && indiviParam->loopAnimAll"
.endobj kar_grsky2_assert_loop_anim_param_present
