.include "macros.inc"
.file "grvalley2.c"

# 0x8010E798..0x8010E95C | size: 0x1C4
.text
.balign 4

# .text:0x0 | 0x8010E798 | size: 0xE4
.fn kar_grvalley2_init_loop_anim_and_individual_fgm_ids, global
/* 8010E798 0010B598  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8010E79C 0010B59C  7C 08 02 A6 */	mflr r0
/* 8010E7A0 0010B5A0  90 01 00 24 */	stw r0, 0x24(r1)
/* 8010E7A4 0010B5A4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8010E7A8 0010B5A8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8010E7AC 0010B5AC  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8010E7B0 0010B5B0  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 8010E7B4 0010B5B4  3C 60 80 4A */	lis r3, kar_grvalley2_callback_table@ha
/* 8010E7B8 0010B5B8  3B E3 76 10 */	addi r31, r3, kar_grvalley2_callback_table@l
/* 8010E7BC 0010B5BC  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 8010E7C0 0010B5C0  38 60 00 00 */	li r3, 0x0
/* 8010E7C4 0010B5C4  83 A4 00 08 */	lwz r29, 0x8(r4)
/* 8010E7C8 0010B5C8  28 1D 00 00 */	cmplwi r29, 0x0
/* 8010E7CC 0010B5CC  41 82 00 14 */	beq .L_8010E7E0
/* 8010E7D0 0010B5D0  80 1D 00 00 */	lwz r0, 0x0(r29)
/* 8010E7D4 0010B5D4  28 00 00 00 */	cmplwi r0, 0x0
/* 8010E7D8 0010B5D8  41 82 00 08 */	beq .L_8010E7E0
/* 8010E7DC 0010B5DC  38 60 00 01 */	li r3, 0x1
.L_8010E7E0:
/* 8010E7E0 0010B5E0  2C 03 00 00 */	cmpwi r3, 0x0
/* 8010E7E4 0010B5E4  40 82 00 14 */	bne .L_8010E7F8
/* 8010E7E8 0010B5E8  38 7F 00 0C */	addi r3, r31, 0xc
/* 8010E7EC 0010B5EC  38 BF 00 18 */	addi r5, r31, 0x18
/* 8010E7F0 0010B5F0  38 80 00 29 */	li r4, 0x29
/* 8010E7F4 0010B5F4  48 31 9C C5 */	bl __assert
.L_8010E7F8:
/* 8010E7F8 0010B5F8  80 9D 00 00 */	lwz r4, 0x0(r29)
/* 8010E7FC 0010B5FC  7F C3 F3 78 */	mr r3, r30
/* 8010E800 0010B600  4B FC D6 49 */	bl kar_granim__800dbe48
/* 8010E804 0010B604  80 7D 00 04 */	lwz r3, 0x4(r29)
/* 8010E808 0010B608  80 03 00 04 */	lwz r0, 0x4(r3)
/* 8010E80C 0010B60C  2C 00 00 0A */	cmpwi r0, 0xa
/* 8010E810 0010B610  40 81 00 14 */	ble .L_8010E824
/* 8010E814 0010B614  38 7F 00 0C */	addi r3, r31, 0xc
/* 8010E818 0010B618  38 BF 00 40 */	addi r5, r31, 0x40
/* 8010E81C 0010B61C  38 80 00 2F */	li r4, 0x2f
/* 8010E820 0010B620  48 31 9C 99 */	bl __assert
.L_8010E824:
/* 8010E824 0010B624  7F C5 F3 78 */	mr r5, r30
/* 8010E828 0010B628  38 C0 00 00 */	li r6, 0x0
/* 8010E82C 0010B62C  38 80 00 00 */	li r4, 0x0
/* 8010E830 0010B630  48 00 00 20 */	b .L_8010E850
.L_8010E834:
/* 8010E834 0010B634  80 63 00 00 */	lwz r3, 0x0(r3)
/* 8010E838 0010B638  38 04 00 08 */	addi r0, r4, 0x8
/* 8010E83C 0010B63C  38 84 00 10 */	addi r4, r4, 0x10
/* 8010E840 0010B640  38 C6 00 01 */	addi r6, r6, 0x1
/* 8010E844 0010B644  7C 03 00 2E */	lwzx r0, r3, r0
/* 8010E848 0010B648  90 05 07 28 */	stw r0, 0x728(r5)
/* 8010E84C 0010B64C  38 A5 00 04 */	addi r5, r5, 0x4
.L_8010E850:
/* 8010E850 0010B650  80 7D 00 04 */	lwz r3, 0x4(r29)
/* 8010E854 0010B654  80 03 00 04 */	lwz r0, 0x4(r3)
/* 8010E858 0010B658  7C 06 00 00 */	cmpw r6, r0
/* 8010E85C 0010B65C  41 80 FF D8 */	blt .L_8010E834
/* 8010E860 0010B660  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8010E864 0010B664  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8010E868 0010B668  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8010E86C 0010B66C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8010E870 0010B670  7C 08 03 A6 */	mtlr r0
/* 8010E874 0010B674  38 21 00 20 */	addi r1, r1, 0x20
/* 8010E878 0010B678  4E 80 00 20 */	blr
.endfn kar_grvalley2_init_loop_anim_and_individual_fgm_ids

# .text:0xE4 | 0x8010E87C | size: 0x54
.fn kar_grvalley2_create_stage_common_and_breakcoral_yaku, global
/* 8010E87C 0010B67C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010E880 0010B680  7C 08 02 A6 */	mflr r0
/* 8010E884 0010B684  38 80 00 00 */	li r4, 0x0
/* 8010E888 0010B688  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010E88C 0010B68C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010E890 0010B690  7C 7F 1B 78 */	mr r31, r3
/* 8010E894 0010B694  4B FE B4 ED */	bl kar_gryakucommon_create_stage_linked_kind16_yaku
/* 8010E898 0010B698  7F E3 FB 78 */	mr r3, r31
/* 8010E89C 0010B69C  38 80 00 01 */	li r4, 0x1
/* 8010E8A0 0010B6A0  4B FE B4 E1 */	bl kar_gryakucommon_create_stage_linked_kind16_yaku
/* 8010E8A4 0010B6A4  7F E3 FB 78 */	mr r3, r31
/* 8010E8A8 0010B6A8  38 80 00 02 */	li r4, 0x2
/* 8010E8AC 0010B6AC  4B FF 5A 19 */	bl kar_gryakubreakcoral_create_stage_linked_kind28_breakcoral
/* 8010E8B0 0010B6B0  7F E3 FB 78 */	mr r3, r31
/* 8010E8B4 0010B6B4  38 80 00 03 */	li r4, 0x3
/* 8010E8B8 0010B6B8  4B FF 5A 0D */	bl kar_gryakubreakcoral_create_stage_linked_kind28_breakcoral
/* 8010E8BC 0010B6BC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010E8C0 0010B6C0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010E8C4 0010B6C4  7C 08 03 A6 */	mtlr r0
/* 8010E8C8 0010B6C8  38 21 00 10 */	addi r1, r1, 0x10
/* 8010E8CC 0010B6CC  4E 80 00 20 */	blr
.endfn kar_grvalley2_create_stage_common_and_breakcoral_yaku

# .text:0x138 | 0x8010E8D0 | size: 0x58
.fn kar_grvalley2_update_individual_fgm_timers, global
/* 8010E8D0 0010B6D0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010E8D4 0010B6D4  7C 08 02 A6 */	mflr r0
/* 8010E8D8 0010B6D8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010E8DC 0010B6DC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010E8E0 0010B6E0  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8010E8E4 0010B6E4  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8010E8E8 0010B6E8  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 8010E8EC 0010B6EC  7F E3 FB 78 */	mr r3, r31
/* 8010E8F0 0010B6F0  83 C4 00 08 */	lwz r30, 0x8(r4)
/* 8010E8F4 0010B6F4  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 8010E8F8 0010B6F8  4B FD BA F1 */	bl kar_graudio_configure_individual_fgm_tracks
/* 8010E8FC 0010B6FC  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 8010E900 0010B700  7F E3 FB 78 */	mr r3, r31
/* 8010E904 0010B704  38 BF 07 28 */	addi r5, r31, 0x728
/* 8010E908 0010B708  38 C0 00 0A */	li r6, 0xa
/* 8010E90C 0010B70C  4B FD BC 5D */	bl kar_graudio_update_individual_fgm_timers
/* 8010E910 0010B710  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010E914 0010B714  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010E918 0010B718  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8010E91C 0010B71C  7C 08 03 A6 */	mtlr r0
/* 8010E920 0010B720  38 21 00 10 */	addi r1, r1, 0x10
/* 8010E924 0010B724  4E 80 00 20 */	blr
.endfn kar_grvalley2_update_individual_fgm_timers

# .text:0x190 | 0x8010E928 | size: 0x34
.fn kar_grvalley2_start_bit_counter_id0_duration100, global
/* 8010E928 0010B728  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010E92C 0010B72C  7C 08 02 A6 */	mflr r0
/* 8010E930 0010B730  38 A0 00 00 */	li r5, 0x0
/* 8010E934 0010B734  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010E938 0010B738  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 8010E93C 0010B73C  80 83 00 08 */	lwz r4, 0x8(r3)
/* 8010E940 0010B740  80 84 00 08 */	lwz r4, 0x8(r4)
/* 8010E944 0010B744  80 84 00 08 */	lwz r4, 0x8(r4)
/* 8010E948 0010B748  4B FC CD 0D */	bl kar_grcommon__800db654
/* 8010E94C 0010B74C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010E950 0010B750  7C 08 03 A6 */	mtlr r0
/* 8010E954 0010B754  38 21 00 10 */	addi r1, r1, 0x10
/* 8010E958 0010B758  4E 80 00 20 */	blr
.endfn kar_grvalley2_start_bit_counter_id0_duration100

# 0x804A7610..0x804A7698 | size: 0x88
.data
.balign 8

# .data:0x0 | 0x804A7610 | size: 0x88
.obj kar_grvalley2_callback_table, global
	.4byte kar_grvalley2_init_loop_anim_and_individual_fgm_ids
	.4byte kar_grvalley2_create_stage_common_and_breakcoral_yaku
	.4byte kar_grvalley2_update_individual_fgm_timers
	.4byte 0x67727661
	.4byte 0x6C6C6579
	.4byte 0x322E6300
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
	.4byte 0x7256616C
	.4byte 0x6C657932
	.4byte 0x5F46676D
	.4byte 0x436F756E
	.4byte 0x7465724E
	.4byte 0x756D0000
	.4byte 0x00000000
.endobj kar_grvalley2_callback_table
