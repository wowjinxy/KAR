.include "macros.inc"
.file "grcolosseum1.c"

# 0x8010F92C..0x8011120C | size: 0x18E0
.text
.balign 4

# .text:0x0 | 0x8010F92C | size: 0xE0
.fn kar_grcolosseum1_init_course_dependent_common_setup_list, global
/* 8010F92C 0010C72C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8010F930 0010C730  7C 08 02 A6 */	mflr r0
/* 8010F934 0010C734  90 01 00 24 */	stw r0, 0x24(r1)
/* 8010F938 0010C738  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8010F93C 0010C73C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8010F940 0010C740  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8010F944 0010C744  93 81 00 10 */	stw r28, 0x10(r1)
/* 8010F948 0010C748  83 83 00 2C */	lwz r28, 0x2c(r3)
/* 8010F94C 0010C74C  80 7C 00 08 */	lwz r3, 0x8(r28)
/* 8010F950 0010C750  83 C3 00 08 */	lwz r30, 0x8(r3)
/* 8010F954 0010C754  48 15 25 79 */	bl fn_80261ECC
/* 8010F958 0010C758  2C 03 00 21 */	cmpwi r3, 0x21
/* 8010F95C 0010C75C  41 82 00 48 */	beq .L_8010F9A4
/* 8010F960 0010C760  40 80 00 78 */	bge .L_8010F9D8
/* 8010F964 0010C764  2C 03 00 13 */	cmpwi r3, 0x13
/* 8010F968 0010C768  41 82 00 08 */	beq .L_8010F970
/* 8010F96C 0010C76C  48 00 00 6C */	b .L_8010F9D8
.L_8010F970:
/* 8010F970 0010C770  3B E0 00 00 */	li r31, 0x0
/* 8010F974 0010C774  7F FD FB 78 */	mr r29, r31
/* 8010F978 0010C778  48 00 00 1C */	b .L_8010F994
.L_8010F97C:
/* 8010F97C 0010C77C  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 8010F980 0010C780  7F 83 E3 78 */	mr r3, r28
/* 8010F984 0010C784  7C 84 E8 2E */	lwzx r4, r4, r29
/* 8010F988 0010C788  4B FC BD ED */	bl kar_grcommon__near_800db774
/* 8010F98C 0010C78C  3B BD 00 04 */	addi r29, r29, 0x4
/* 8010F990 0010C790  3B FF 00 01 */	addi r31, r31, 0x1
.L_8010F994:
/* 8010F994 0010C794  80 1E 00 0C */	lwz r0, 0xc(r30)
/* 8010F998 0010C798  7C 1F 00 00 */	cmpw r31, r0
/* 8010F99C 0010C79C  41 80 FF E0 */	blt .L_8010F97C
/* 8010F9A0 0010C7A0  48 00 00 4C */	b .L_8010F9EC
.L_8010F9A4:
/* 8010F9A4 0010C7A4  3B E0 00 00 */	li r31, 0x0
/* 8010F9A8 0010C7A8  7F FD FB 78 */	mr r29, r31
/* 8010F9AC 0010C7AC  48 00 00 1C */	b .L_8010F9C8
.L_8010F9B0:
/* 8010F9B0 0010C7B0  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 8010F9B4 0010C7B4  7F 83 E3 78 */	mr r3, r28
/* 8010F9B8 0010C7B8  7C 84 E8 2E */	lwzx r4, r4, r29
/* 8010F9BC 0010C7BC  4B FC BD B9 */	bl kar_grcommon__near_800db774
/* 8010F9C0 0010C7C0  3B BD 00 04 */	addi r29, r29, 0x4
/* 8010F9C4 0010C7C4  3B FF 00 01 */	addi r31, r31, 0x1
.L_8010F9C8:
/* 8010F9C8 0010C7C8  80 1E 00 04 */	lwz r0, 0x4(r30)
/* 8010F9CC 0010C7CC  7C 1F 00 00 */	cmpw r31, r0
/* 8010F9D0 0010C7D0  41 80 FF E0 */	blt .L_8010F9B0
/* 8010F9D4 0010C7D4  48 00 00 18 */	b .L_8010F9EC
.L_8010F9D8:
/* 8010F9D8 0010C7D8  3C 60 80 4A */	lis r3, kar_src_grcolosseum1_c@ha
/* 8010F9DC 0010C7DC  38 80 00 43 */	li r4, 0x43
/* 8010F9E0 0010C7E0  38 63 78 B4 */	addi r3, r3, kar_src_grcolosseum1_c@l
/* 8010F9E4 0010C7E4  38 AD 92 98 */	li r5, lbl_805D6378@sda21
/* 8010F9E8 0010C7E8  48 31 8A D1 */	bl __assert
.L_8010F9EC:
/* 8010F9EC 0010C7EC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8010F9F0 0010C7F0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8010F9F4 0010C7F4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8010F9F8 0010C7F8  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8010F9FC 0010C7FC  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8010FA00 0010C800  7C 08 03 A6 */	mtlr r0
/* 8010FA04 0010C804  38 21 00 20 */	addi r1, r1, 0x20
/* 8010FA08 0010C808  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_init_course_dependent_common_setup_list

# .text:0xE0 | 0x8010FA0C | size: 0x4C
.fn kar_grcolosseum1_create_course19_kind23_breakhouse_pair, global
/* 8010FA0C 0010C80C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010FA10 0010C810  7C 08 02 A6 */	mflr r0
/* 8010FA14 0010C814  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010FA18 0010C818  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010FA1C 0010C81C  7C 7F 1B 78 */	mr r31, r3
/* 8010FA20 0010C820  48 15 24 AD */	bl fn_80261ECC
/* 8010FA24 0010C824  2C 03 00 13 */	cmpwi r3, 0x13
/* 8010FA28 0010C828  40 82 00 1C */	bne .L_8010FA44
/* 8010FA2C 0010C82C  7F E3 FB 78 */	mr r3, r31
/* 8010FA30 0010C830  38 80 00 00 */	li r4, 0x0
/* 8010FA34 0010C834  4B FF 30 F5 */	bl kar_gryakubreakhouse_create_colosseum_kind23_breakhouse
/* 8010FA38 0010C838  7F E3 FB 78 */	mr r3, r31
/* 8010FA3C 0010C83C  38 80 00 01 */	li r4, 0x1
/* 8010FA40 0010C840  4B FF 30 E9 */	bl kar_gryakubreakhouse_create_colosseum_kind23_breakhouse
.L_8010FA44:
/* 8010FA44 0010C844  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010FA48 0010C848  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010FA4C 0010C84C  7C 08 03 A6 */	mtlr r0
/* 8010FA50 0010C850  38 21 00 10 */	addi r1, r1, 0x10
/* 8010FA54 0010C854  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_create_course19_kind23_breakhouse_pair

# .text:0x12C | 0x8010FA58 | size: 0x50
.fn kar_grcolosseum1_request_effect_9c47_at_configured_joint, global
/* 8010FA58 0010C858  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010FA5C 0010C85C  7C 08 02 A6 */	mflr r0
/* 8010FA60 0010C860  3C 80 00 01 */	lis r4, 0x1
/* 8010FA64 0010C864  38 A0 00 04 */	li r5, 0x4
/* 8010FA68 0010C868  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010FA6C 0010C86C  38 84 9C 47 */	subi r4, r4, 0x63b9
/* 8010FA70 0010C870  38 C0 00 CF */	li r6, 0xcf
/* 8010FA74 0010C874  81 03 00 2C */	lwz r8, 0x2c(r3)
/* 8010FA78 0010C878  80 E8 00 08 */	lwz r7, 0x8(r8)
/* 8010FA7C 0010C87C  81 08 01 04 */	lwz r8, 0x104(r8)
/* 8010FA80 0010C880  80 E7 00 08 */	lwz r7, 0x8(r7)
/* 8010FA84 0010C884  80 07 00 00 */	lwz r0, 0x0(r7)
/* 8010FA88 0010C888  54 00 18 38 */	slwi r0, r0, 3
/* 8010FA8C 0010C88C  7C E8 00 2E */	lwzx r7, r8, r0
/* 8010FA90 0010C890  4C C6 31 82 */	crclr cr1eq
/* 8010FA94 0010C894  48 12 71 AD */	bl kar_efrequest__80236c40
/* 8010FA98 0010C898  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010FA9C 0010C89C  7C 08 03 A6 */	mtlr r0
/* 8010FAA0 0010C8A0  38 21 00 10 */	addi r1, r1, 0x10
/* 8010FAA4 0010C8A4  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_request_effect_9c47_at_configured_joint

# .text:0x17C | 0x8010FAA8 | size: 0x4
.fn fn_8010FAA8, global
/* 8010FAA8 0010C8A8  4E 80 00 20 */	blr
.endfn fn_8010FAA8

# .text:0x180 | 0x8010FAAC | size: 0x4
.fn fn_8010FAAC, global
/* 8010FAAC 0010C8AC  4E 80 00 20 */	blr
.endfn fn_8010FAAC

# .text:0x184 | 0x8010FAB0 | size: 0x4
.fn fn_8010FAB0, global
/* 8010FAB0 0010C8B0  4E 80 00 20 */	blr
.endfn fn_8010FAB0

# .text:0x188 | 0x8010FAB4 | size: 0x4
.fn fn_8010FAB4, global
/* 8010FAB4 0010C8B4  4E 80 00 20 */	blr
.endfn fn_8010FAB4

# .text:0x18C | 0x8010FAB8 | size: 0x24
.fn kar_grcolosseum1_init_pointstrike_panel_handles, global
/* 8010FAB8 0010C8B8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010FABC 0010C8BC  7C 08 02 A6 */	mflr r0
/* 8010FAC0 0010C8C0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010FAC4 0010C8C4  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8010FAC8 0010C8C8  4B FD F0 D5 */	bl kar_grpointstrike_init_panel_handles
/* 8010FACC 0010C8CC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010FAD0 0010C8D0  7C 08 03 A6 */	mtlr r0
/* 8010FAD4 0010C8D4  38 21 00 10 */	addi r1, r1, 0x10
/* 8010FAD8 0010C8D8  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_init_pointstrike_panel_handles

# .text:0x1B0 | 0x8010FADC | size: 0x4
.fn fn_8010FADC, global
/* 8010FADC 0010C8DC  4E 80 00 20 */	blr
.endfn fn_8010FADC

# .text:0x1B4 | 0x8010FAE0 | size: 0x2C
.fn kar_grcolosseum1_init_risingcube_controller_switch_group, global
/* 8010FAE0 0010C8E0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010FAE4 0010C8E4  7C 08 02 A6 */	mflr r0
/* 8010FAE8 0010C8E8  38 8D 92 A0 */	li r4, lbl_805D6380@sda21
/* 8010FAEC 0010C8EC  38 A0 00 01 */	li r5, 0x1
/* 8010FAF0 0010C8F0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010FAF4 0010C8F4  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8010FAF8 0010C8F8  4B FD 8A B1 */	bl kar_grswitch__800e85a8
/* 8010FAFC 0010C8FC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010FB00 0010C900  7C 08 03 A6 */	mtlr r0
/* 8010FB04 0010C904  38 21 00 10 */	addi r1, r1, 0x10
/* 8010FB08 0010C908  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_init_risingcube_controller_switch_group

# .text:0x1E0 | 0x8010FB0C | size: 0x48
.fn kar_grcolosseum1_create_risingcube_pair_and_controller, global
/* 8010FB0C 0010C90C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010FB10 0010C910  7C 08 02 A6 */	mflr r0
/* 8010FB14 0010C914  38 80 00 00 */	li r4, 0x0
/* 8010FB18 0010C918  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010FB1C 0010C91C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010FB20 0010C920  7C 7F 1B 78 */	mr r31, r3
/* 8010FB24 0010C924  4B FE D2 21 */	bl kar_gryakurisingcube_create_stage_linked_cube_yaku
/* 8010FB28 0010C928  7F E3 FB 78 */	mr r3, r31
/* 8010FB2C 0010C92C  38 80 00 01 */	li r4, 0x1
/* 8010FB30 0010C930  4B FE D2 15 */	bl kar_gryakurisingcube_create_stage_linked_cube_yaku
/* 8010FB34 0010C934  7F E3 FB 78 */	mr r3, r31
/* 8010FB38 0010C938  38 80 00 02 */	li r4, 0x2
/* 8010FB3C 0010C93C  4B FE E4 31 */	bl kar_gryakurisingcube_create_stage_linked_controller_yaku
/* 8010FB40 0010C940  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010FB44 0010C944  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010FB48 0010C948  7C 08 03 A6 */	mtlr r0
/* 8010FB4C 0010C94C  38 21 00 10 */	addi r1, r1, 0x10
/* 8010FB50 0010C950  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_create_risingcube_pair_and_controller

# .text:0x228 | 0x8010FB54 | size: 0x30
.fn kar_grcolosseum1_update_risingcube_controller_targets_by_stage_index, global
/* 8010FB54 0010C954  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010FB58 0010C958  7C 08 02 A6 */	mflr r0
/* 8010FB5C 0010C95C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010FB60 0010C960  1C 04 00 48 */	mulli r0, r4, 0x48
/* 8010FB64 0010C964  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 8010FB68 0010C968  7C 63 02 14 */	add r3, r3, r0
/* 8010FB6C 0010C96C  80 63 02 18 */	lwz r3, 0x218(r3)
/* 8010FB70 0010C970  4B FE E7 6D */	bl kar_gryakurisingcube_update_controller_target_groups
/* 8010FB74 0010C974  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010FB78 0010C978  7C 08 03 A6 */	mtlr r0
/* 8010FB7C 0010C97C  38 21 00 10 */	addi r1, r1, 0x10
/* 8010FB80 0010C980  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_update_risingcube_controller_targets_by_stage_index

# .text:0x258 | 0x8010FB84 | size: 0x4
.fn fn_8010FB84, global
/* 8010FB84 0010C984  4E 80 00 20 */	blr
.endfn fn_8010FB84

# .text:0x25C | 0x8010FB88 | size: 0x4
.fn fn_8010FB88, global
/* 8010FB88 0010C988  4E 80 00 20 */	blr
.endfn fn_8010FB88

# .text:0x260 | 0x8010FB8C | size: 0x4
.fn fn_8010FB8C, global
/* 8010FB8C 0010C98C  4E 80 00 20 */	blr
.endfn fn_8010FB8C

# .text:0x264 | 0x8010FB90 | size: 0x4
.fn fn_8010FB90, global
/* 8010FB90 0010C990  4E 80 00 20 */	blr
.endfn fn_8010FB90

# .text:0x268 | 0x8010FB94 | size: 0x40
.fn kar_grcolosseum1_init_two_area_light_users, global
/* 8010FB94 0010C994  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010FB98 0010C998  7C 08 02 A6 */	mflr r0
/* 8010FB9C 0010C99C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010FBA0 0010C9A0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010FBA4 0010C9A4  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8010FBA8 0010C9A8  80 63 00 08 */	lwz r3, 0x8(r3)
/* 8010FBAC 0010C9AC  83 E3 00 08 */	lwz r31, 0x8(r3)
/* 8010FBB0 0010C9B0  7F E3 FB 78 */	mr r3, r31
/* 8010FBB4 0010C9B4  4B F6 AD A5 */	bl kar_lbarealightuser__near_8007a958
/* 8010FBB8 0010C9B8  38 7F 00 50 */	addi r3, r31, 0x50
/* 8010FBBC 0010C9BC  4B F6 AD 9D */	bl kar_lbarealightuser__near_8007a958
/* 8010FBC0 0010C9C0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010FBC4 0010C9C4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010FBC8 0010C9C8  7C 08 03 A6 */	mtlr r0
/* 8010FBCC 0010C9CC  38 21 00 10 */	addi r1, r1, 0x10
/* 8010FBD0 0010C9D0  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_init_two_area_light_users

# .text:0x2A8 | 0x8010FBD4 | size: 0x28
.fn kar_grcolosseum1_create_kind41_recovery_joint_index0, global
/* 8010FBD4 0010C9D4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010FBD8 0010C9D8  7C 08 02 A6 */	mflr r0
/* 8010FBDC 0010C9DC  38 80 00 00 */	li r4, 0x0
/* 8010FBE0 0010C9E0  38 A0 00 01 */	li r5, 0x1
/* 8010FBE4 0010C9E4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010FBE8 0010C9E8  4B FE B9 E9 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010FBEC 0010C9EC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010FBF0 0010C9F0  7C 08 03 A6 */	mtlr r0
/* 8010FBF4 0010C9F4  38 21 00 10 */	addi r1, r1, 0x10
/* 8010FBF8 0010C9F8  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_create_kind41_recovery_joint_index0

# .text:0x2D0 | 0x8010FBFC | size: 0x2A0
.fn kar_grcolosseum1_create_external_airflow_shapes, global
/* 8010FBFC 0010C9FC  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8010FC00 0010CA00  7C 08 02 A6 */	mflr r0
/* 8010FC04 0010CA04  3C 80 80 49 */	lis r4, lbl_80489E6C@ha
/* 8010FC08 0010CA08  3C A0 80 49 */	lis r5, lbl_80489E60@ha
/* 8010FC0C 0010CA0C  90 01 00 34 */	stw r0, 0x34(r1)
/* 8010FC10 0010CA10  38 C4 9E 6C */	addi r6, r4, lbl_80489E6C@l
/* 8010FC14 0010CA14  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 8010FC18 0010CA18  93 C1 00 28 */	stw r30, 0x28(r1)
/* 8010FC1C 0010CA1C  7C 7E 1B 78 */	mr r30, r3
/* 8010FC20 0010CA20  85 25 9E 60 */	lwzu r9, lbl_80489E60@l(r5)
/* 8010FC24 0010CA24  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8010FC28 0010CA28  81 05 00 04 */	lwz r8, 0x4(r5)
/* 8010FC2C 0010CA2C  80 E5 00 08 */	lwz r7, 0x8(r5)
/* 8010FC30 0010CA30  80 A6 00 00 */	lwz r5, 0x0(r6)
/* 8010FC34 0010CA34  80 86 00 04 */	lwz r4, 0x4(r6)
/* 8010FC38 0010CA38  80 06 00 08 */	lwz r0, 0x8(r6)
/* 8010FC3C 0010CA3C  91 21 00 14 */	stw r9, 0x14(r1)
/* 8010FC40 0010CA40  91 01 00 18 */	stw r8, 0x18(r1)
/* 8010FC44 0010CA44  90 E1 00 1C */	stw r7, 0x1c(r1)
/* 8010FC48 0010CA48  90 A1 00 08 */	stw r5, 0x8(r1)
/* 8010FC4C 0010CA4C  90 81 00 0C */	stw r4, 0xc(r1)
/* 8010FC50 0010CA50  90 01 00 10 */	stw r0, 0x10(r1)
/* 8010FC54 0010CA54  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FC58 0010CA58  2C 00 00 08 */	cmpwi r0, 0x8
/* 8010FC5C 0010CA5C  40 80 00 78 */	bge .L_8010FCD4
/* 8010FC60 0010CA60  4B FD 74 A9 */	bl kar_grairflow_create_external_gobj
/* 8010FC64 0010CA64  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FC68 0010CA68  38 81 00 14 */	addi r4, r1, 0x14
/* 8010FC6C 0010CA6C  C0 02 93 E8 */	lfs f0, lbl_805DFAE8@sda21(r0)
/* 8010FC70 0010CA70  54 00 10 3A */	slwi r0, r0, 2
/* 8010FC74 0010CA74  7C BF 02 14 */	add r5, r31, r0
/* 8010FC78 0010CA78  90 65 07 28 */	stw r3, 0x728(r5)
/* 8010FC7C 0010CA7C  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 8010FC80 0010CA80  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FC84 0010CA84  54 00 10 3A */	slwi r0, r0, 2
/* 8010FC88 0010CA88  7C 7F 02 14 */	add r3, r31, r0
/* 8010FC8C 0010CA8C  80 63 07 28 */	lwz r3, 0x728(r3)
/* 8010FC90 0010CA90  4B FD 75 09 */	bl kar_grairflow_set_external_point
/* 8010FC94 0010CA94  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FC98 0010CA98  C0 22 93 EC */	lfs f1, lbl_805DFAEC@sda21(r0)
/* 8010FC9C 0010CA9C  54 00 10 3A */	slwi r0, r0, 2
/* 8010FCA0 0010CAA0  C0 42 93 F0 */	lfs f2, lbl_805DFAF0@sda21(r0)
/* 8010FCA4 0010CAA4  7C 7F 02 14 */	add r3, r31, r0
/* 8010FCA8 0010CAA8  80 63 07 28 */	lwz r3, 0x728(r3)
/* 8010FCAC 0010CAAC  4B FD 77 49 */	bl kar_grairflow_set_point_strength_range
/* 8010FCB0 0010CAB0  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FCB4 0010CAB4  C0 22 93 F4 */	lfs f1, lbl_805DFAF4@sda21(r0)
/* 8010FCB8 0010CAB8  54 00 10 3A */	slwi r0, r0, 2
/* 8010FCBC 0010CABC  7C 7F 02 14 */	add r3, r31, r0
/* 8010FCC0 0010CAC0  80 63 07 28 */	lwz r3, 0x728(r3)
/* 8010FCC4 0010CAC4  4B FD 79 81 */	bl kar_grairflow_set_point_radius
/* 8010FCC8 0010CAC8  80 7F 07 48 */	lwz r3, 0x748(r31)
/* 8010FCCC 0010CACC  38 03 00 01 */	addi r0, r3, 0x1
/* 8010FCD0 0010CAD0  90 1F 07 48 */	stw r0, 0x748(r31)
.L_8010FCD4:
/* 8010FCD4 0010CAD4  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FCD8 0010CAD8  2C 00 00 08 */	cmpwi r0, 0x8
/* 8010FCDC 0010CADC  40 80 00 88 */	bge .L_8010FD64
/* 8010FCE0 0010CAE0  7F C3 F3 78 */	mr r3, r30
/* 8010FCE4 0010CAE4  4B FD 74 25 */	bl kar_grairflow_create_external_gobj
/* 8010FCE8 0010CAE8  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FCEC 0010CAEC  38 81 00 14 */	addi r4, r1, 0x14
/* 8010FCF0 0010CAF0  C0 22 93 F8 */	lfs f1, lbl_805DFAF8@sda21(r0)
/* 8010FCF4 0010CAF4  38 A1 00 08 */	addi r5, r1, 0x8
/* 8010FCF8 0010CAF8  54 00 10 3A */	slwi r0, r0, 2
/* 8010FCFC 0010CAFC  C0 02 93 FC */	lfs f0, lbl_805DFAFC@sda21(r0)
/* 8010FD00 0010CB00  7C DF 02 14 */	add r6, r31, r0
/* 8010FD04 0010CB04  90 66 07 28 */	stw r3, 0x728(r6)
/* 8010FD08 0010CB08  D0 21 00 1C */	stfs f1, 0x1c(r1)
/* 8010FD0C 0010CB0C  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 8010FD10 0010CB10  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FD14 0010CB14  54 00 10 3A */	slwi r0, r0, 2
/* 8010FD18 0010CB18  7C 7F 02 14 */	add r3, r31, r0
/* 8010FD1C 0010CB1C  80 63 07 28 */	lwz r3, 0x728(r3)
/* 8010FD20 0010CB20  4B FD 74 F5 */	bl kar_grairflow_set_external_segment_radial
/* 8010FD24 0010CB24  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FD28 0010CB28  C0 22 93 EC */	lfs f1, lbl_805DFAEC@sda21(r0)
/* 8010FD2C 0010CB2C  54 00 10 3A */	slwi r0, r0, 2
/* 8010FD30 0010CB30  C0 42 93 F0 */	lfs f2, lbl_805DFAF0@sda21(r0)
/* 8010FD34 0010CB34  7C 7F 02 14 */	add r3, r31, r0
/* 8010FD38 0010CB38  80 63 07 28 */	lwz r3, 0x728(r3)
/* 8010FD3C 0010CB3C  4B FD 77 4D */	bl kar_grairflow_set_segment_radial_strength_range
/* 8010FD40 0010CB40  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FD44 0010CB44  C0 22 93 F4 */	lfs f1, lbl_805DFAF4@sda21(r0)
/* 8010FD48 0010CB48  54 00 10 3A */	slwi r0, r0, 2
/* 8010FD4C 0010CB4C  7C 7F 02 14 */	add r3, r31, r0
/* 8010FD50 0010CB50  80 63 07 28 */	lwz r3, 0x728(r3)
/* 8010FD54 0010CB54  4B FD 79 75 */	bl kar_grairflow_set_segment_radial_radius
/* 8010FD58 0010CB58  80 7F 07 48 */	lwz r3, 0x748(r31)
/* 8010FD5C 0010CB5C  38 03 00 01 */	addi r0, r3, 0x1
/* 8010FD60 0010CB60  90 1F 07 48 */	stw r0, 0x748(r31)
.L_8010FD64:
/* 8010FD64 0010CB64  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FD68 0010CB68  2C 00 00 08 */	cmpwi r0, 0x8
/* 8010FD6C 0010CB6C  40 80 00 88 */	bge .L_8010FDF4
/* 8010FD70 0010CB70  7F C3 F3 78 */	mr r3, r30
/* 8010FD74 0010CB74  4B FD 73 95 */	bl kar_grairflow_create_external_gobj
/* 8010FD78 0010CB78  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FD7C 0010CB7C  38 81 00 14 */	addi r4, r1, 0x14
/* 8010FD80 0010CB80  C0 22 94 00 */	lfs f1, lbl_805DFB00@sda21(r0)
/* 8010FD84 0010CB84  38 A1 00 08 */	addi r5, r1, 0x8
/* 8010FD88 0010CB88  54 00 10 3A */	slwi r0, r0, 2
/* 8010FD8C 0010CB8C  C0 02 94 04 */	lfs f0, lbl_805DFB04@sda21(r0)
/* 8010FD90 0010CB90  7C DF 02 14 */	add r6, r31, r0
/* 8010FD94 0010CB94  90 66 07 28 */	stw r3, 0x728(r6)
/* 8010FD98 0010CB98  D0 21 00 1C */	stfs f1, 0x1c(r1)
/* 8010FD9C 0010CB9C  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 8010FDA0 0010CBA0  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FDA4 0010CBA4  54 00 10 3A */	slwi r0, r0, 2
/* 8010FDA8 0010CBA8  7C 7F 02 14 */	add r3, r31, r0
/* 8010FDAC 0010CBAC  80 63 07 28 */	lwz r3, 0x728(r3)
/* 8010FDB0 0010CBB0  4B FD 75 05 */	bl kar_grairflow_set_external_segment_directional
/* 8010FDB4 0010CBB4  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FDB8 0010CBB8  C0 22 93 EC */	lfs f1, lbl_805DFAEC@sda21(r0)
/* 8010FDBC 0010CBBC  54 00 10 3A */	slwi r0, r0, 2
/* 8010FDC0 0010CBC0  C0 42 93 F0 */	lfs f2, lbl_805DFAF0@sda21(r0)
/* 8010FDC4 0010CBC4  7C 7F 02 14 */	add r3, r31, r0
/* 8010FDC8 0010CBC8  80 63 07 28 */	lwz r3, 0x728(r3)
/* 8010FDCC 0010CBCC  4B FD 77 51 */	bl kar_grairflow_set_segment_directional_strength_range
/* 8010FDD0 0010CBD0  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FDD4 0010CBD4  C0 22 93 F4 */	lfs f1, lbl_805DFAF4@sda21(r0)
/* 8010FDD8 0010CBD8  54 00 10 3A */	slwi r0, r0, 2
/* 8010FDDC 0010CBDC  7C 7F 02 14 */	add r3, r31, r0
/* 8010FDE0 0010CBE0  80 63 07 28 */	lwz r3, 0x728(r3)
/* 8010FDE4 0010CBE4  4B FD 79 69 */	bl kar_grairflow_set_segment_directional_radius
/* 8010FDE8 0010CBE8  80 7F 07 48 */	lwz r3, 0x748(r31)
/* 8010FDEC 0010CBEC  38 03 00 01 */	addi r0, r3, 0x1
/* 8010FDF0 0010CBF0  90 1F 07 48 */	stw r0, 0x748(r31)
.L_8010FDF4:
/* 8010FDF4 0010CBF4  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FDF8 0010CBF8  2C 00 00 08 */	cmpwi r0, 0x8
/* 8010FDFC 0010CBFC  40 80 00 88 */	bge .L_8010FE84
/* 8010FE00 0010CC00  7F C3 F3 78 */	mr r3, r30
/* 8010FE04 0010CC04  4B FD 73 05 */	bl kar_grairflow_create_external_gobj
/* 8010FE08 0010CC08  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FE0C 0010CC0C  38 81 00 14 */	addi r4, r1, 0x14
/* 8010FE10 0010CC10  C0 22 94 08 */	lfs f1, lbl_805DFB08@sda21(r0)
/* 8010FE14 0010CC14  38 A1 00 08 */	addi r5, r1, 0x8
/* 8010FE18 0010CC18  54 00 10 3A */	slwi r0, r0, 2
/* 8010FE1C 0010CC1C  C0 02 94 0C */	lfs f0, lbl_805DFB0C@sda21(r0)
/* 8010FE20 0010CC20  7C DF 02 14 */	add r6, r31, r0
/* 8010FE24 0010CC24  90 66 07 28 */	stw r3, 0x728(r6)
/* 8010FE28 0010CC28  D0 21 00 1C */	stfs f1, 0x1c(r1)
/* 8010FE2C 0010CC2C  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 8010FE30 0010CC30  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FE34 0010CC34  54 00 10 3A */	slwi r0, r0, 2
/* 8010FE38 0010CC38  7C 7F 02 14 */	add r3, r31, r0
/* 8010FE3C 0010CC3C  80 63 07 28 */	lwz r3, 0x728(r3)
/* 8010FE40 0010CC40  4B FD 75 15 */	bl kar_grairflow_set_external_linked_segment
/* 8010FE44 0010CC44  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FE48 0010CC48  C0 22 93 F0 */	lfs f1, lbl_805DFAF0@sda21(r0)
/* 8010FE4C 0010CC4C  54 00 10 3A */	slwi r0, r0, 2
/* 8010FE50 0010CC50  C0 42 93 EC */	lfs f2, lbl_805DFAEC@sda21(r0)
/* 8010FE54 0010CC54  7C 7F 02 14 */	add r3, r31, r0
/* 8010FE58 0010CC58  80 63 07 28 */	lwz r3, 0x728(r3)
/* 8010FE5C 0010CC5C  4B FD 77 55 */	bl kar_grairflow_set_linked_segment_strength_range
/* 8010FE60 0010CC60  80 1F 07 48 */	lwz r0, 0x748(r31)
/* 8010FE64 0010CC64  C0 22 93 F4 */	lfs f1, lbl_805DFAF4@sda21(r0)
/* 8010FE68 0010CC68  54 00 10 3A */	slwi r0, r0, 2
/* 8010FE6C 0010CC6C  7C 7F 02 14 */	add r3, r31, r0
/* 8010FE70 0010CC70  80 63 07 28 */	lwz r3, 0x728(r3)
/* 8010FE74 0010CC74  4B FD 79 5D */	bl kar_grairflow_set_linked_segment_radius
/* 8010FE78 0010CC78  80 7F 07 48 */	lwz r3, 0x748(r31)
/* 8010FE7C 0010CC7C  38 03 00 01 */	addi r0, r3, 0x1
/* 8010FE80 0010CC80  90 1F 07 48 */	stw r0, 0x748(r31)
.L_8010FE84:
/* 8010FE84 0010CC84  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8010FE88 0010CC88  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 8010FE8C 0010CC8C  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 8010FE90 0010CC90  7C 08 03 A6 */	mtlr r0
/* 8010FE94 0010CC94  38 21 00 30 */	addi r1, r1, 0x30
/* 8010FE98 0010CC98  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_create_external_airflow_shapes

# .text:0x570 | 0x8010FE9C | size: 0x6C
.fn kar_grcolosseum1_init_airflow_slots_and_switch_group, global
/* 8010FE9C 0010CC9C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010FEA0 0010CCA0  7C 08 02 A6 */	mflr r0
/* 8010FEA4 0010CCA4  3C 80 80 4A */	lis r4, kar_grcolosseum1_airflow_switch_callback_table@ha
/* 8010FEA8 0010CCA8  38 A0 00 06 */	li r5, 0x6
/* 8010FEAC 0010CCAC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010FEB0 0010CCB0  38 00 00 00 */	li r0, 0x0
/* 8010FEB4 0010CCB4  38 84 79 84 */	addi r4, r4, kar_grcolosseum1_airflow_switch_callback_table@l
/* 8010FEB8 0010CCB8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010FEBC 0010CCBC  7C 7F 1B 78 */	mr r31, r3
/* 8010FEC0 0010CCC0  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8010FEC4 0010CCC4  90 03 07 28 */	stw r0, 0x728(r3)
/* 8010FEC8 0010CCC8  90 03 07 2C */	stw r0, 0x72c(r3)
/* 8010FECC 0010CCCC  90 03 07 30 */	stw r0, 0x730(r3)
/* 8010FED0 0010CCD0  90 03 07 34 */	stw r0, 0x734(r3)
/* 8010FED4 0010CCD4  90 03 07 38 */	stw r0, 0x738(r3)
/* 8010FED8 0010CCD8  90 03 07 3C */	stw r0, 0x73c(r3)
/* 8010FEDC 0010CCDC  90 03 07 40 */	stw r0, 0x740(r3)
/* 8010FEE0 0010CCE0  90 03 07 44 */	stw r0, 0x744(r3)
/* 8010FEE4 0010CCE4  90 03 07 48 */	stw r0, 0x748(r3)
/* 8010FEE8 0010CCE8  4B FD 86 C1 */	bl kar_grswitch__800e85a8
/* 8010FEEC 0010CCEC  7F E3 FB 78 */	mr r3, r31
/* 8010FEF0 0010CCF0  4B FF FD 0D */	bl kar_grcolosseum1_create_external_airflow_shapes
/* 8010FEF4 0010CCF4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010FEF8 0010CCF8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010FEFC 0010CCFC  7C 08 03 A6 */	mtlr r0
/* 8010FF00 0010CD00  38 21 00 10 */	addi r1, r1, 0x10
/* 8010FF04 0010CD04  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_init_airflow_slots_and_switch_group

# .text:0x5DC | 0x8010FF08 | size: 0x1DC
.fn kar_grcolosseum1_create_stage_colosseum_yaku_objects, global
/* 8010FF08 0010CD08  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010FF0C 0010CD0C  7C 08 02 A6 */	mflr r0
/* 8010FF10 0010CD10  38 80 00 00 */	li r4, 0x0
/* 8010FF14 0010CD14  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010FF18 0010CD18  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010FF1C 0010CD1C  7C 7F 1B 78 */	mr r31, r3
/* 8010FF20 0010CD20  4B FE 9E 61 */	bl kar_gryakucommon_create_stage_linked_kind16_yaku
/* 8010FF24 0010CD24  7F E3 FB 78 */	mr r3, r31
/* 8010FF28 0010CD28  38 80 00 01 */	li r4, 0x1
/* 8010FF2C 0010CD2C  4B FE A3 75 */	bl kar_gryakudownforcezone_create_stage_linked_kind17_yaku
/* 8010FF30 0010CD30  7F E3 FB 78 */	mr r3, r31
/* 8010FF34 0010CD34  38 80 00 02 */	li r4, 0x2
/* 8010FF38 0010CD38  4B FE A3 69 */	bl kar_gryakudownforcezone_create_stage_linked_kind17_yaku
/* 8010FF3C 0010CD3C  7F E3 FB 78 */	mr r3, r31
/* 8010FF40 0010CD40  38 80 00 03 */	li r4, 0x3
/* 8010FF44 0010CD44  4B FE A6 CD */	bl kar_gryakucatchzone_create_stage_linked_kind18_yaku
/* 8010FF48 0010CD48  7F E3 FB 78 */	mr r3, r31
/* 8010FF4C 0010CD4C  38 80 00 04 */	li r4, 0x4
/* 8010FF50 0010CD50  4B FE A7 B9 */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010FF54 0010CD54  7F E3 FB 78 */	mr r3, r31
/* 8010FF58 0010CD58  38 80 00 05 */	li r4, 0x5
/* 8010FF5C 0010CD5C  4B FE A7 AD */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010FF60 0010CD60  7F E3 FB 78 */	mr r3, r31
/* 8010FF64 0010CD64  38 80 00 06 */	li r4, 0x6
/* 8010FF68 0010CD68  4B FE A7 A1 */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010FF6C 0010CD6C  7F E3 FB 78 */	mr r3, r31
/* 8010FF70 0010CD70  38 80 00 07 */	li r4, 0x7
/* 8010FF74 0010CD74  4B FE A7 95 */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010FF78 0010CD78  7F E3 FB 78 */	mr r3, r31
/* 8010FF7C 0010CD7C  38 80 00 08 */	li r4, 0x8
/* 8010FF80 0010CD80  4B FE B3 F9 */	bl kar_gryakurecoveryzone_create_stage_linked_recoveryzone_yaku
/* 8010FF84 0010CD84  7F E3 FB 78 */	mr r3, r31
/* 8010FF88 0010CD88  38 80 00 09 */	li r4, 0x9
/* 8010FF8C 0010CD8C  38 A0 00 00 */	li r5, 0x0
/* 8010FF90 0010CD90  4B FE B6 41 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010FF94 0010CD94  7F E3 FB 78 */	mr r3, r31
/* 8010FF98 0010CD98  38 80 00 0A */	li r4, 0xa
/* 8010FF9C 0010CD9C  38 A0 00 00 */	li r5, 0x0
/* 8010FFA0 0010CDA0  4B FE B6 31 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010FFA4 0010CDA4  7F E3 FB 78 */	mr r3, r31
/* 8010FFA8 0010CDA8  38 80 00 0B */	li r4, 0xb
/* 8010FFAC 0010CDAC  38 A0 00 00 */	li r5, 0x0
/* 8010FFB0 0010CDB0  4B FE B6 21 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010FFB4 0010CDB4  7F E3 FB 78 */	mr r3, r31
/* 8010FFB8 0010CDB8  38 80 00 0C */	li r4, 0xc
/* 8010FFBC 0010CDBC  38 A0 00 00 */	li r5, 0x0
/* 8010FFC0 0010CDC0  4B FE B6 11 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010FFC4 0010CDC4  7F E3 FB 78 */	mr r3, r31
/* 8010FFC8 0010CDC8  38 80 00 0D */	li r4, 0xd
/* 8010FFCC 0010CDCC  38 A0 00 00 */	li r5, 0x0
/* 8010FFD0 0010CDD0  4B FE B6 01 */	bl kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku
/* 8010FFD4 0010CDD4  7F E3 FB 78 */	mr r3, r31
/* 8010FFD8 0010CDD8  38 80 00 0E */	li r4, 0xe
/* 8010FFDC 0010CDDC  4B FE BF 85 */	bl kar_gryakurecoveryzone_create_stage_linked_kind42_ground_group_yaku
/* 8010FFE0 0010CDE0  7F E3 FB 78 */	mr r3, r31
/* 8010FFE4 0010CDE4  38 80 00 0F */	li r4, 0xf
/* 8010FFE8 0010CDE8  4B FE CD 5D */	bl kar_gryakurisingcube_create_stage_linked_cube_yaku
/* 8010FFEC 0010CDEC  7F E3 FB 78 */	mr r3, r31
/* 8010FFF0 0010CDF0  38 80 00 10 */	li r4, 0x10
/* 8010FFF4 0010CDF4  4B FE CD 51 */	bl kar_gryakurisingcube_create_stage_linked_cube_yaku
/* 8010FFF8 0010CDF8  7F E3 FB 78 */	mr r3, r31
/* 8010FFFC 0010CDFC  38 80 00 11 */	li r4, 0x11
/* 80110000 0010CE00  4B FE E5 D5 */	bl kar_gryakugondola_create_stage_linked_kind46_carrier_yaku
/* 80110004 0010CE04  7F E3 FB 78 */	mr r3, r31
/* 80110008 0010CE08  38 80 00 12 */	li r4, 0x12
/* 8011000C 0010CE0C  4B FE ED 15 */	bl kar_gryakugondola_create_stage_linked_kind48_route_yaku
/* 80110010 0010CE10  7F E3 FB 78 */	mr r3, r31
/* 80110014 0010CE14  38 80 00 13 */	li r4, 0x13
/* 80110018 0010CE18  4B FF 2C 29 */	bl kar_gryakubreakhouse_create_stage_linked_kind54_animfloor
/* 8011001C 0010CE1C  7F E3 FB 78 */	mr r3, r31
/* 80110020 0010CE20  38 80 00 14 */	li r4, 0x14
/* 80110024 0010CE24  4B FF 2C 1D */	bl kar_gryakubreakhouse_create_stage_linked_kind54_animfloor
/* 80110028 0010CE28  7F E3 FB 78 */	mr r3, r31
/* 8011002C 0010CE2C  38 80 00 15 */	li r4, 0x15
/* 80110030 0010CE30  4B FF 36 25 */	bl kar_gryakuanimfloor_create_stage_linked_kind55_reactive_floor
/* 80110034 0010CE34  7F E3 FB 78 */	mr r3, r31
/* 80110038 0010CE38  38 80 00 16 */	li r4, 0x16
/* 8011003C 0010CE3C  4B FF 5D 7D */	bl kar_gryakubreakcommon_create_stage_linked_kind56_delayed_collision
/* 80110040 0010CE40  7F E3 FB 78 */	mr r3, r31
/* 80110044 0010CE44  38 80 00 17 */	li r4, 0x17
/* 80110048 0010CE48  4B FF 60 FD */	bl kar_gryakubreakcommon_create_stage_linked_kind57_lasergate
/* 8011004C 0010CE4C  7F E3 FB 78 */	mr r3, r31
/* 80110050 0010CE50  38 80 00 18 */	li r4, 0x18
/* 80110054 0010CE54  4B FF 63 69 */	bl kar_gryakubreakcommon_create_stage_linked_kind58_lasergate_ctrl
/* 80110058 0010CE58  7F E3 FB 78 */	mr r3, r31
/* 8011005C 0010CE5C  38 80 00 19 */	li r4, 0x19
/* 80110060 0010CE60  4B FF 67 C5 */	bl kar_gryakulasergate_create_stage_linked_kind32_breakfloor
/* 80110064 0010CE64  7F E3 FB 78 */	mr r3, r31
/* 80110068 0010CE68  38 80 00 1A */	li r4, 0x1a
/* 8011006C 0010CE6C  4B FF 44 61 */	bl kar_gryakubreakcoral_create_stage_linked_kind31_breakicicle
/* 80110070 0010CE70  7F E3 FB 78 */	mr r3, r31
/* 80110074 0010CE74  38 80 00 1B */	li r4, 0x1b
/* 80110078 0010CE78  4B FF 24 95 */	bl kar_gryakubreakrock_create_colosseum_kind22_breakrock
/* 8011007C 0010CE7C  7F E3 FB 78 */	mr r3, r31
/* 80110080 0010CE80  38 80 00 1C */	li r4, 0x1c
/* 80110084 0010CE84  4B FF 3B D5 */	bl kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor
/* 80110088 0010CE88  7F E3 FB 78 */	mr r3, r31
/* 8011008C 0010CE8C  38 80 00 1D */	li r4, 0x1d
/* 80110090 0010CE90  4B FF 70 91 */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 80110094 0010CE94  7F E3 FB 78 */	mr r3, r31
/* 80110098 0010CE98  38 80 00 1E */	li r4, 0x1e
/* 8011009C 0010CE9C  4B FF 70 85 */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 801100A0 0010CEA0  7F E3 FB 78 */	mr r3, r31
/* 801100A4 0010CEA4  38 80 00 1F */	li r4, 0x1f
/* 801100A8 0010CEA8  4B FF 70 79 */	bl kar_gryakubreakfloor_create_stage_linked_kind30_breakfan
/* 801100AC 0010CEAC  7F E3 FB 78 */	mr r3, r31
/* 801100B0 0010CEB0  38 80 00 20 */	li r4, 0x20
/* 801100B4 0010CEB4  4B FF 7B 49 */	bl kar_gryakubreakcoll_create_stage_linked_kind33_breakcoll
/* 801100B8 0010CEB8  7F E3 FB 78 */	mr r3, r31
/* 801100BC 0010CEBC  38 80 00 21 */	li r4, 0x21
/* 801100C0 0010CEC0  4B FF 7C A5 */	bl kar_gryakubreakcoll_create_stage_linked_kind34_breakcoll
/* 801100C4 0010CEC4  7F E3 FB 78 */	mr r3, r31
/* 801100C8 0010CEC8  38 80 00 22 */	li r4, 0x22
/* 801100CC 0010CECC  4B FF 90 6D */	bl kar_gryakubreakhpcoll_create_stage_linked_kind38_breakhpcoll_house
/* 801100D0 0010CED0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801100D4 0010CED4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801100D8 0010CED8  7C 08 03 A6 */	mtlr r0
/* 801100DC 0010CEDC  38 21 00 10 */	addi r1, r1, 0x10
/* 801100E0 0010CEE0  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_create_stage_colosseum_yaku_objects

# .text:0x7B8 | 0x801100E4 | size: 0x4
.fn fn_801100E4, global
/* 801100E4 0010CEE4  4E 80 00 20 */	blr
.endfn fn_801100E4

# .text:0x7BC | 0x801100E8 | size: 0x30
.fn kar_grcolosseum1_switch0_trigger_risingcube_by_stage_index, global
/* 801100E8 0010CEE8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801100EC 0010CEEC  7C 08 02 A6 */	mflr r0
/* 801100F0 0010CEF0  90 01 00 14 */	stw r0, 0x14(r1)
/* 801100F4 0010CEF4  1C 04 00 48 */	mulli r0, r4, 0x48
/* 801100F8 0010CEF8  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 801100FC 0010CEFC  7C 63 02 14 */	add r3, r3, r0
/* 80110100 0010CF00  80 63 02 18 */	lwz r3, 0x218(r3)
/* 80110104 0010CF04  4B FE D7 8D */	bl kar_gryakurisingcube_trigger_cube_state_toggle
/* 80110108 0010CF08  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011010C 0010CF0C  7C 08 03 A6 */	mtlr r0
/* 80110110 0010CF10  38 21 00 10 */	addi r1, r1, 0x10
/* 80110114 0010CF14  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_switch0_trigger_risingcube_by_stage_index

# .text:0x7EC | 0x80110118 | size: 0x30
.fn kar_grcolosseum1_switch1_trigger_risingcube_by_stage_index, global
/* 80110118 0010CF18  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8011011C 0010CF1C  7C 08 02 A6 */	mflr r0
/* 80110120 0010CF20  90 01 00 14 */	stw r0, 0x14(r1)
/* 80110124 0010CF24  1C 04 00 48 */	mulli r0, r4, 0x48
/* 80110128 0010CF28  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 8011012C 0010CF2C  7C 63 02 14 */	add r3, r3, r0
/* 80110130 0010CF30  80 63 02 18 */	lwz r3, 0x218(r3)
/* 80110134 0010CF34  4B FE D7 5D */	bl kar_gryakurisingcube_trigger_cube_state_toggle
/* 80110138 0010CF38  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011013C 0010CF3C  7C 08 03 A6 */	mtlr r0
/* 80110140 0010CF40  38 21 00 10 */	addi r1, r1, 0x10
/* 80110144 0010CF44  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_switch1_trigger_risingcube_by_stage_index

# .text:0x81C | 0x80110148 | size: 0x4
.fn fn_80110148, global
/* 80110148 0010CF48  4E 80 00 20 */	blr
.endfn fn_80110148

# .text:0x820 | 0x8011014C | size: 0x4
.fn fn_8011014C, global
/* 8011014C 0010CF4C  4E 80 00 20 */	blr
.endfn fn_8011014C

# .text:0x824 | 0x80110150 | size: 0x4
.fn fn_80110150, global
/* 80110150 0010CF50  4E 80 00 20 */	blr
.endfn fn_80110150

# .text:0x828 | 0x80110154 | size: 0x30
.fn kar_grcolosseum1_switch5_trigger_lasergate_ctrl_open_by_stage_index, global
/* 80110154 0010CF54  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80110158 0010CF58  7C 08 02 A6 */	mflr r0
/* 8011015C 0010CF5C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80110160 0010CF60  1C 04 00 48 */	mulli r0, r4, 0x48
/* 80110164 0010CF64  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 80110168 0010CF68  7C 63 02 14 */	add r3, r3, r0
/* 8011016C 0010CF6C  80 63 02 18 */	lwz r3, 0x218(r3)
/* 80110170 0010CF70  4B FF 64 E9 */	bl kar_gryakulasergate_trigger_kind58_ctrl_open_linked_gates
/* 80110174 0010CF74  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80110178 0010CF78  7C 08 03 A6 */	mtlr r0
/* 8011017C 0010CF7C  38 21 00 10 */	addi r1, r1, 0x10
/* 80110180 0010CF80  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_switch5_trigger_lasergate_ctrl_open_by_stage_index

# .text:0x858 | 0x80110184 | size: 0xC8
.fn kar_grcolosseum1_event_kind4d_init_shuffle_positions, global
/* 80110184 0010CF84  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80110188 0010CF88  7C 08 02 A6 */	mflr r0
/* 8011018C 0010CF8C  90 01 00 24 */	stw r0, 0x24(r1)
/* 80110190 0010CF90  38 00 00 00 */	li r0, 0x0
/* 80110194 0010CF94  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80110198 0010CF98  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8011019C 0010CF9C  7C 7E 1B 78 */	mr r30, r3
/* 801101A0 0010CFA0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 801101A4 0010CFA4  90 0D 06 40 */	stw r0, lbl_805DD720@sda21(r0)
/* 801101A8 0010CFA8  90 0D 06 38 */	stw r0, lbl_805DD718@sda21(r0)
/* 801101AC 0010CFAC  90 0D 06 3C */	stw r0, lbl_805DD71C@sda21(r0)
/* 801101B0 0010CFB0  90 0D 06 44 */	stw r0, lbl_805DD724@sda21(r0)
/* 801101B4 0010CFB4  48 14 3F 91 */	bl fn_80254144
/* 801101B8 0010CFB8  38 60 00 00 */	li r3, 0x0
/* 801101BC 0010CFBC  4B FD D5 C9 */	bl kar_grboxgenerator__near_800ed784
/* 801101C0 0010CFC0  3C 60 80 55 */	lis r3, kar_grcolosseum1_event_position_order_buffer@ha
/* 801101C4 0010CFC4  3B A0 00 00 */	li r29, 0x0
/* 801101C8 0010CFC8  3B E3 78 20 */	addi r31, r3, kar_grcolosseum1_event_position_order_buffer@l
.L_801101CC:
/* 801101CC 0010CFCC  7F C3 F3 78 */	mr r3, r30
/* 801101D0 0010CFD0  4B FD E5 1D */	bl kar_greventgenerator_get_current_eventpos_start
/* 801101D4 0010CFD4  7C 1D 1A 14 */	add r0, r29, r3
/* 801101D8 0010CFD8  3B BD 00 01 */	addi r29, r29, 0x1
/* 801101DC 0010CFDC  2C 1D 00 14 */	cmpwi r29, 0x14
/* 801101E0 0010CFE0  98 1F 00 00 */	stb r0, 0x0(r31)
/* 801101E4 0010CFE4  3B FF 00 01 */	addi r31, r31, 0x1
/* 801101E8 0010CFE8  41 80 FF E4 */	blt .L_801101CC
/* 801101EC 0010CFEC  7F C3 F3 78 */	mr r3, r30
/* 801101F0 0010CFF0  4B FD E5 19 */	bl kar_greventgenerator_get_current_eventpos_count
/* 801101F4 0010CFF4  3C 80 80 55 */	lis r4, kar_grcolosseum1_event_position_order_buffer@ha
/* 801101F8 0010CFF8  3B A3 FF FF */	subi r29, r3, 0x1
/* 801101FC 0010CFFC  3B E4 78 20 */	addi r31, r4, kar_grcolosseum1_event_position_order_buffer@l
/* 80110200 0010D000  7F DF EA 14 */	add r30, r31, r29
/* 80110204 0010D004  48 00 00 24 */	b .L_80110228
.L_80110208:
/* 80110208 0010D008  38 7D 00 01 */	addi r3, r29, 0x1
/* 8011020C 0010D00C  48 30 E4 5D */	bl HSD_Randi
/* 80110210 0010D010  88 9E 00 00 */	lbz r4, 0x0(r30)
/* 80110214 0010D014  3B BD FF FF */	subi r29, r29, 0x1
/* 80110218 0010D018  7C 1F 18 AE */	lbzx r0, r31, r3
/* 8011021C 0010D01C  98 1E 00 00 */	stb r0, 0x0(r30)
/* 80110220 0010D020  3B DE FF FF */	subi r30, r30, 0x1
/* 80110224 0010D024  7C 9F 19 AE */	stbx r4, r31, r3
.L_80110228:
/* 80110228 0010D028  2C 1D 00 01 */	cmpwi r29, 0x1
/* 8011022C 0010D02C  41 81 FF DC */	bgt .L_80110208
/* 80110230 0010D030  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80110234 0010D034  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80110238 0010D038  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8011023C 0010D03C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80110240 0010D040  7C 08 03 A6 */	mtlr r0
/* 80110244 0010D044  38 21 00 20 */	addi r1, r1, 0x20
/* 80110248 0010D048  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_event_kind4d_init_shuffle_positions

# .text:0x920 | 0x8011024C | size: 0x1F8
.fn kar_grcolosseum1_event_kind4d_update_spawn_until_timeout, global
/* 8011024C 0010D04C  94 21 FF 70 */	stwu r1, -0x90(r1)
/* 80110250 0010D050  7C 08 02 A6 */	mflr r0
/* 80110254 0010D054  90 01 00 94 */	stw r0, 0x94(r1)
/* 80110258 0010D058  93 E1 00 8C */	stw r31, 0x8c(r1)
/* 8011025C 0010D05C  7C 7F 1B 78 */	mr r31, r3
/* 80110260 0010D060  93 C1 00 88 */	stw r30, 0x88(r1)
/* 80110264 0010D064  93 A1 00 84 */	stw r29, 0x84(r1)
/* 80110268 0010D068  93 81 00 80 */	stw r28, 0x80(r1)
/* 8011026C 0010D06C  80 0D 06 38 */	lwz r0, lbl_805DD718@sda21(r0)
/* 80110270 0010D070  2C 00 00 00 */	cmpwi r0, 0x0
/* 80110274 0010D074  40 82 01 B0 */	bne .L_80110424
/* 80110278 0010D078  80 6D 06 40 */	lwz r3, lbl_805DD720@sda21(r0)
/* 8011027C 0010D07C  28 03 00 00 */	cmplwi r3, 0x0
/* 80110280 0010D080  40 82 01 18 */	bne .L_80110398
/* 80110284 0010D084  3C 60 80 55 */	lis r3, kar_grcolosseum1_event_position_order_buffer@ha
/* 80110288 0010D088  80 0D 06 44 */	lwz r0, lbl_805DD724@sda21(r0)
/* 8011028C 0010D08C  38 63 78 20 */	addi r3, r3, kar_grcolosseum1_event_position_order_buffer@l
/* 80110290 0010D090  38 80 00 4D */	li r4, 0x4d
/* 80110294 0010D094  3B 81 00 18 */	addi r28, r1, 0x18
/* 80110298 0010D098  3B A1 00 24 */	addi r29, r1, 0x24
/* 8011029C 0010D09C  3B C1 00 30 */	addi r30, r1, 0x30
/* 801102A0 0010D0A0  90 81 00 14 */	stw r4, 0x14(r1)
/* 801102A4 0010D0A4  7C 63 00 AE */	lbzx r3, r3, r0
/* 801102A8 0010D0A8  7F 84 E3 78 */	mr r4, r28
/* 801102AC 0010D0AC  7F A5 EB 78 */	mr r5, r29
/* 801102B0 0010D0B0  7F C6 F3 78 */	mr r6, r30
/* 801102B4 0010D0B4  4B FC 0F 49 */	bl kar_grcommon_get_eventpos_vectors_by_index
/* 801102B8 0010D0B8  C0 22 94 10 */	lfs f1, lbl_805DFB10@sda21(r0)
/* 801102BC 0010D0BC  7F C3 F3 78 */	mr r3, r30
/* 801102C0 0010D0C0  C0 02 94 14 */	lfs f0, lbl_805DFB14@sda21(r0)
/* 801102C4 0010D0C4  7F A4 EB 78 */	mr r4, r29
/* 801102C8 0010D0C8  D0 21 00 30 */	stfs f1, 0x30(r1)
/* 801102CC 0010D0CC  38 A1 00 08 */	addi r5, r1, 0x8
/* 801102D0 0010D0D0  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 801102D4 0010D0D4  D0 21 00 38 */	stfs f1, 0x38(r1)
/* 801102D8 0010D0D8  4B F5 2A F9 */	bl kar_lbvector_cross_normalize
/* 801102DC 0010D0DC  7F C4 F3 78 */	mr r4, r30
/* 801102E0 0010D0E0  7F A5 EB 78 */	mr r5, r29
/* 801102E4 0010D0E4  38 61 00 08 */	addi r3, r1, 0x8
/* 801102E8 0010D0E8  4B F5 2A E9 */	bl kar_lbvector_cross_normalize
/* 801102EC 0010D0EC  48 30 E3 25 */	bl HSD_Randf
/* 801102F0 0010D0F0  C8 02 94 18 */	lfd f0, lbl_805DFB18@sda21(r0)
/* 801102F4 0010D0F4  7F A3 EB 78 */	mr r3, r29
/* 801102F8 0010D0F8  7F C4 F3 78 */	mr r4, r30
/* 801102FC 0010D0FC  FC 20 00 72 */	fmul f1, f0, f1
/* 80110300 0010D100  FC 20 08 18 */	frsp f1, f1
/* 80110304 0010D104  4B F5 35 F5 */	bl kar_lbvector_rotate_about_axis
/* 80110308 0010D108  C0 02 94 14 */	lfs f0, lbl_805DFB14@sda21(r0)
/* 8011030C 0010D10C  3C 60 77 36 */	lis r3, 0x7736
/* 80110310 0010D110  38 A0 FF FF */	li r5, -0x1
/* 80110314 0010D114  38 80 00 00 */	li r4, 0x0
/* 80110318 0010D118  38 03 94 00 */	subi r0, r3, 0x6c00
/* 8011031C 0010D11C  D0 01 00 3C */	stfs f0, 0x3c(r1)
/* 80110320 0010D120  7F E3 FB 78 */	mr r3, r31
/* 80110324 0010D124  90 A1 00 40 */	stw r5, 0x40(r1)
/* 80110328 0010D128  90 A1 00 44 */	stw r5, 0x44(r1)
/* 8011032C 0010D12C  90 81 00 48 */	stw r4, 0x48(r1)
/* 80110330 0010D130  90 01 00 4C */	stw r0, 0x4c(r1)
/* 80110334 0010D134  4B FD E3 91 */	bl kar_greventgenerator_get_state_elapsed_frames
/* 80110338 0010D138  7F E3 FB 78 */	mr r3, r31
/* 8011033C 0010D13C  4B FD E3 91 */	bl kar_greventgenerator_get_current_event_key_frame
/* 80110340 0010D140  7F E3 FB 78 */	mr r3, r31
/* 80110344 0010D144  4B FD E3 89 */	bl kar_greventgenerator_get_current_event_key_frame
/* 80110348 0010D148  7C 7E 1B 78 */	mr r30, r3
/* 8011034C 0010D14C  7F E3 FB 78 */	mr r3, r31
/* 80110350 0010D150  4B FD E3 75 */	bl kar_greventgenerator_get_state_elapsed_frames
/* 80110354 0010D154  C0 02 94 20 */	lfs f0, lbl_805DFB20@sda21(r0)
/* 80110358 0010D158  7C 63 F0 50 */	subf r3, r3, r30
/* 8011035C 0010D15C  38 00 00 00 */	li r0, 0x0
/* 80110360 0010D160  90 61 00 50 */	stw r3, 0x50(r1)
/* 80110364 0010D164  38 61 00 14 */	addi r3, r1, 0x14
/* 80110368 0010D168  90 01 00 54 */	stw r0, 0x54(r1)
/* 8011036C 0010D16C  D0 01 00 64 */	stfs f0, 0x64(r1)
/* 80110370 0010D170  48 0E B7 E1 */	bl fn_801FBB50
/* 80110374 0010D174  90 6D 06 40 */	stw r3, lbl_805DD720@sda21(r0)
/* 80110378 0010D178  80 8D 06 3C */	lwz r4, lbl_805DD71C@sda21(r0)
/* 8011037C 0010D17C  48 0F 46 69 */	bl kar_emupdate__near_802049e4
/* 80110380 0010D180  7F 83 E3 78 */	mr r3, r28
/* 80110384 0010D184  48 00 3C 8D */	bl fn_80114010
/* 80110388 0010D188  80 6D 06 44 */	lwz r3, lbl_805DD724@sda21(r0)
/* 8011038C 0010D18C  38 03 00 01 */	addi r0, r3, 0x1
/* 80110390 0010D190  90 0D 06 44 */	stw r0, lbl_805DD724@sda21(r0)
/* 80110394 0010D194  48 00 00 90 */	b .L_80110424
.L_80110398:
/* 80110398 0010D198  80 8D 12 54 */	lwz r4, lbl_805DE334@sda21(r0)
/* 8011039C 0010D19C  38 00 00 00 */	li r0, 0x0
/* 801103A0 0010D1A0  80 84 00 30 */	lwz r4, 0x30(r4)
/* 801103A4 0010D1A4  48 00 00 18 */	b .L_801103BC
.L_801103A8:
/* 801103A8 0010D1A8  7C 04 18 40 */	cmplw r4, r3
/* 801103AC 0010D1AC  40 82 00 0C */	bne .L_801103B8
/* 801103B0 0010D1B0  38 00 00 01 */	li r0, 0x1
/* 801103B4 0010D1B4  48 00 00 10 */	b .L_801103C4
.L_801103B8:
/* 801103B8 0010D1B8  80 84 00 08 */	lwz r4, 0x8(r4)
.L_801103BC:
/* 801103BC 0010D1BC  28 04 00 00 */	cmplwi r4, 0x0
/* 801103C0 0010D1C0  40 82 FF E8 */	bne .L_801103A8
.L_801103C4:
/* 801103C4 0010D1C4  2C 00 00 00 */	cmpwi r0, 0x0
/* 801103C8 0010D1C8  40 82 00 54 */	bne .L_8011041C
/* 801103CC 0010D1CC  48 00 3D 89 */	bl fn_80114154
/* 801103D0 0010D1D0  7F E3 FB 78 */	mr r3, r31
/* 801103D4 0010D1D4  4B FD E2 F9 */	bl kar_greventgenerator_get_current_event_key_frame
/* 801103D8 0010D1D8  7C 7E 1B 78 */	mr r30, r3
/* 801103DC 0010D1DC  7F E3 FB 78 */	mr r3, r31
/* 801103E0 0010D1E0  4B FD E2 E5 */	bl kar_greventgenerator_get_state_elapsed_frames
/* 801103E4 0010D1E4  7C 03 F0 40 */	cmplw r3, r30
/* 801103E8 0010D1E8  40 80 00 18 */	bge .L_80110400
/* 801103EC 0010D1EC  3C 60 00 02 */	lis r3, 0x2
/* 801103F0 0010D1F0  80 8D 06 3C */	lwz r4, lbl_805DD71C@sda21(r0)
/* 801103F4 0010D1F4  38 03 86 A0 */	subi r0, r3, 0x7960
/* 801103F8 0010D1F8  7C 04 00 00 */	cmpw r4, r0
/* 801103FC 0010D1FC  41 80 00 14 */	blt .L_80110410
.L_80110400:
/* 80110400 0010D200  7F E3 FB 78 */	mr r3, r31
/* 80110404 0010D204  4B FD E2 5D */	bl kar_greventgenerator_enter_finish_state
/* 80110408 0010D208  38 00 00 01 */	li r0, 0x1
/* 8011040C 0010D20C  90 0D 06 38 */	stw r0, lbl_805DD718@sda21(r0)
.L_80110410:
/* 80110410 0010D210  38 00 00 00 */	li r0, 0x0
/* 80110414 0010D214  90 0D 06 40 */	stw r0, lbl_805DD720@sda21(r0)
/* 80110418 0010D218  48 00 00 0C */	b .L_80110424
.L_8011041C:
/* 8011041C 0010D21C  48 0F 45 D5 */	bl kar_emupdate__near_802049f0
/* 80110420 0010D220  90 6D 06 3C */	stw r3, lbl_805DD71C@sda21(r0)
.L_80110424:
/* 80110424 0010D224  80 01 00 94 */	lwz r0, 0x94(r1)
/* 80110428 0010D228  83 E1 00 8C */	lwz r31, 0x8c(r1)
/* 8011042C 0010D22C  83 C1 00 88 */	lwz r30, 0x88(r1)
/* 80110430 0010D230  83 A1 00 84 */	lwz r29, 0x84(r1)
/* 80110434 0010D234  83 81 00 80 */	lwz r28, 0x80(r1)
/* 80110438 0010D238  7C 08 03 A6 */	mtlr r0
/* 8011043C 0010D23C  38 21 00 90 */	addi r1, r1, 0x90
/* 80110440 0010D240  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_event_kind4d_update_spawn_until_timeout

# .text:0xB18 | 0x80110444 | size: 0x4
.fn fn_80110444, global
/* 80110444 0010D244  4E 80 00 20 */	blr
.endfn fn_80110444

# .text:0xB1C | 0x80110448 | size: 0x84
.fn kar_grcolosseum1_event_kind4d_cleanup_reset_positions, global
/* 80110448 0010D248  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8011044C 0010D24C  7C 08 02 A6 */	mflr r0
/* 80110450 0010D250  90 01 00 24 */	stw r0, 0x24(r1)
/* 80110454 0010D254  38 00 00 00 */	li r0, 0x0
/* 80110458 0010D258  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8011045C 0010D25C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80110460 0010D260  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80110464 0010D264  7C 7D 1B 78 */	mr r29, r3
/* 80110468 0010D268  90 0D 06 40 */	stw r0, lbl_805DD720@sda21(r0)
/* 8011046C 0010D26C  90 0D 06 38 */	stw r0, lbl_805DD718@sda21(r0)
/* 80110470 0010D270  90 0D 06 3C */	stw r0, lbl_805DD71C@sda21(r0)
/* 80110474 0010D274  90 0D 06 44 */	stw r0, lbl_805DD724@sda21(r0)
/* 80110478 0010D278  48 14 3C E1 */	bl fn_80254158
/* 8011047C 0010D27C  38 60 00 00 */	li r3, 0x0
/* 80110480 0010D280  4B FD D3 81 */	bl kar_grboxgenerator__near_800ed800
/* 80110484 0010D284  3C 60 80 55 */	lis r3, kar_grcolosseum1_event_position_order_buffer@ha
/* 80110488 0010D288  3B C0 00 00 */	li r30, 0x0
/* 8011048C 0010D28C  3B E3 78 20 */	addi r31, r3, kar_grcolosseum1_event_position_order_buffer@l
.L_80110490:
/* 80110490 0010D290  7F A3 EB 78 */	mr r3, r29
/* 80110494 0010D294  4B FD E2 59 */	bl kar_greventgenerator_get_current_eventpos_start
/* 80110498 0010D298  7C 1E 1A 14 */	add r0, r30, r3
/* 8011049C 0010D29C  3B DE 00 01 */	addi r30, r30, 0x1
/* 801104A0 0010D2A0  2C 1E 00 14 */	cmpwi r30, 0x14
/* 801104A4 0010D2A4  98 1F 00 00 */	stb r0, 0x0(r31)
/* 801104A8 0010D2A8  3B FF 00 01 */	addi r31, r31, 0x1
/* 801104AC 0010D2AC  41 80 FF E4 */	blt .L_80110490
/* 801104B0 0010D2B0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801104B4 0010D2B4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801104B8 0010D2B8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801104BC 0010D2BC  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 801104C0 0010D2C0  7C 08 03 A6 */	mtlr r0
/* 801104C4 0010D2C4  38 21 00 20 */	addi r1, r1, 0x20
/* 801104C8 0010D2C8  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_event_kind4d_cleanup_reset_positions

# .text:0xBA0 | 0x801104CC | size: 0x30
.fn kar_grcolosseum1_event_kind4c_init_boxgenerator_state, global
/* 801104CC 0010D2CC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801104D0 0010D2D0  7C 08 02 A6 */	mflr r0
/* 801104D4 0010D2D4  38 60 00 01 */	li r3, 0x1
/* 801104D8 0010D2D8  90 01 00 14 */	stw r0, 0x14(r1)
/* 801104DC 0010D2DC  38 00 00 00 */	li r0, 0x0
/* 801104E0 0010D2E0  90 0D 06 4C */	stw r0, lbl_805DD72C@sda21(r0)
/* 801104E4 0010D2E4  90 0D 06 48 */	stw r0, lbl_805DD728@sda21(r0)
/* 801104E8 0010D2E8  4B FD D2 9D */	bl kar_grboxgenerator__near_800ed784
/* 801104EC 0010D2EC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801104F0 0010D2F0  7C 08 03 A6 */	mtlr r0
/* 801104F4 0010D2F4  38 21 00 10 */	addi r1, r1, 0x10
/* 801104F8 0010D2F8  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_event_kind4c_init_boxgenerator_state

# .text:0xBD0 | 0x801104FC | size: 0x138
.fn kar_grcolosseum1_event_kind4c_update_spawn_until_gone, global
/* 801104FC 0010D2FC  94 21 FF 70 */	stwu r1, -0x90(r1)
/* 80110500 0010D300  7C 08 02 A6 */	mflr r0
/* 80110504 0010D304  90 01 00 94 */	stw r0, 0x94(r1)
/* 80110508 0010D308  93 E1 00 8C */	stw r31, 0x8c(r1)
/* 8011050C 0010D30C  93 C1 00 88 */	stw r30, 0x88(r1)
/* 80110510 0010D310  93 A1 00 84 */	stw r29, 0x84(r1)
/* 80110514 0010D314  7C 7D 1B 78 */	mr r29, r3
/* 80110518 0010D318  80 0D 06 48 */	lwz r0, lbl_805DD728@sda21(r0)
/* 8011051C 0010D31C  2C 00 00 00 */	cmpwi r0, 0x0
/* 80110520 0010D320  40 82 00 F8 */	bne .L_80110618
/* 80110524 0010D324  80 0D 06 4C */	lwz r0, lbl_805DD72C@sda21(r0)
/* 80110528 0010D328  28 00 00 00 */	cmplwi r0, 0x0
/* 8011052C 0010D32C  40 82 00 94 */	bne .L_801105C0
/* 80110530 0010D330  38 00 00 4C */	li r0, 0x4c
/* 80110534 0010D334  90 01 00 14 */	stw r0, 0x14(r1)
/* 80110538 0010D338  4B FD E1 D1 */	bl kar_greventgenerator_get_current_eventpos_count
/* 8011053C 0010D33C  48 30 E1 2D */	bl HSD_Randi
/* 80110540 0010D340  7C 7F 1B 78 */	mr r31, r3
/* 80110544 0010D344  7F A3 EB 78 */	mr r3, r29
/* 80110548 0010D348  4B FD E1 A5 */	bl kar_greventgenerator_get_current_eventpos_start
/* 8011054C 0010D34C  3B C1 00 18 */	addi r30, r1, 0x18
/* 80110550 0010D350  7C 63 FA 14 */	add r3, r3, r31
/* 80110554 0010D354  7F C4 F3 78 */	mr r4, r30
/* 80110558 0010D358  38 A1 00 24 */	addi r5, r1, 0x24
/* 8011055C 0010D35C  38 C1 00 30 */	addi r6, r1, 0x30
/* 80110560 0010D360  4B FC 0C 9D */	bl kar_grcommon_get_eventpos_vectors_by_index
/* 80110564 0010D364  C0 02 94 28 */	lfs f0, lbl_805DFB28@sda21(r0)
/* 80110568 0010D368  3C 60 77 36 */	lis r3, 0x7736
/* 8011056C 0010D36C  38 A0 FF FF */	li r5, -0x1
/* 80110570 0010D370  38 80 00 00 */	li r4, 0x0
/* 80110574 0010D374  38 03 94 00 */	subi r0, r3, 0x6c00
/* 80110578 0010D378  D0 01 00 3C */	stfs f0, 0x3c(r1)
/* 8011057C 0010D37C  7F A3 EB 78 */	mr r3, r29
/* 80110580 0010D380  90 A1 00 40 */	stw r5, 0x40(r1)
/* 80110584 0010D384  90 A1 00 44 */	stw r5, 0x44(r1)
/* 80110588 0010D388  90 81 00 48 */	stw r4, 0x48(r1)
/* 8011058C 0010D38C  90 01 00 4C */	stw r0, 0x4c(r1)
/* 80110590 0010D390  4B FD E1 3D */	bl kar_greventgenerator_get_current_event_key_frame
/* 80110594 0010D394  C0 02 94 2C */	lfs f0, lbl_805DFB2C@sda21(r0)
/* 80110598 0010D398  38 00 00 00 */	li r0, 0x0
/* 8011059C 0010D39C  90 61 00 50 */	stw r3, 0x50(r1)
/* 801105A0 0010D3A0  38 61 00 14 */	addi r3, r1, 0x14
/* 801105A4 0010D3A4  90 01 00 54 */	stw r0, 0x54(r1)
/* 801105A8 0010D3A8  D0 01 00 64 */	stfs f0, 0x64(r1)
/* 801105AC 0010D3AC  48 0E B5 A5 */	bl fn_801FBB50
/* 801105B0 0010D3B0  90 6D 06 4C */	stw r3, lbl_805DD72C@sda21(r0)
/* 801105B4 0010D3B4  7F C3 F3 78 */	mr r3, r30
/* 801105B8 0010D3B8  48 00 3A 59 */	bl fn_80114010
/* 801105BC 0010D3BC  48 00 00 5C */	b .L_80110618
.L_801105C0:
/* 801105C0 0010D3C0  80 6D 12 54 */	lwz r3, lbl_805DE334@sda21(r0)
/* 801105C4 0010D3C4  38 80 00 00 */	li r4, 0x0
/* 801105C8 0010D3C8  80 63 00 30 */	lwz r3, 0x30(r3)
/* 801105CC 0010D3CC  48 00 00 28 */	b .L_801105F4
.L_801105D0:
/* 801105D0 0010D3D0  7C 03 00 40 */	cmplw r3, r0
/* 801105D4 0010D3D4  40 82 00 1C */	bne .L_801105F0
/* 801105D8 0010D3D8  38 81 00 08 */	addi r4, r1, 0x8
/* 801105DC 0010D3DC  48 0F 39 D1 */	bl kar_emupdate__near_80203fac
/* 801105E0 0010D3E0  38 61 00 08 */	addi r3, r1, 0x8
/* 801105E4 0010D3E4  48 00 3B 01 */	bl fn_801140E4
/* 801105E8 0010D3E8  38 80 00 01 */	li r4, 0x1
/* 801105EC 0010D3EC  48 00 00 10 */	b .L_801105FC
.L_801105F0:
/* 801105F0 0010D3F0  80 63 00 08 */	lwz r3, 0x8(r3)
.L_801105F4:
/* 801105F4 0010D3F4  28 03 00 00 */	cmplwi r3, 0x0
/* 801105F8 0010D3F8  40 82 FF D8 */	bne .L_801105D0
.L_801105FC:
/* 801105FC 0010D3FC  2C 04 00 00 */	cmpwi r4, 0x0
/* 80110600 0010D400  40 82 00 18 */	bne .L_80110618
/* 80110604 0010D404  7F A3 EB 78 */	mr r3, r29
/* 80110608 0010D408  4B FD E0 59 */	bl kar_greventgenerator_enter_finish_state
/* 8011060C 0010D40C  38 00 00 01 */	li r0, 0x1
/* 80110610 0010D410  90 0D 06 48 */	stw r0, lbl_805DD728@sda21(r0)
/* 80110614 0010D414  48 00 3B 41 */	bl fn_80114154
.L_80110618:
/* 80110618 0010D418  80 01 00 94 */	lwz r0, 0x94(r1)
/* 8011061C 0010D41C  83 E1 00 8C */	lwz r31, 0x8c(r1)
/* 80110620 0010D420  83 C1 00 88 */	lwz r30, 0x88(r1)
/* 80110624 0010D424  83 A1 00 84 */	lwz r29, 0x84(r1)
/* 80110628 0010D428  7C 08 03 A6 */	mtlr r0
/* 8011062C 0010D42C  38 21 00 90 */	addi r1, r1, 0x90
/* 80110630 0010D430  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_event_kind4c_update_spawn_until_gone

# .text:0xD08 | 0x80110634 | size: 0x4
.fn fn_80110634, global
/* 80110634 0010D434  4E 80 00 20 */	blr
.endfn fn_80110634

# .text:0xD0C | 0x80110638 | size: 0x30
.fn kar_grcolosseum1_event_kind4c_cleanup_boxgenerator_state, global
/* 80110638 0010D438  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8011063C 0010D43C  7C 08 02 A6 */	mflr r0
/* 80110640 0010D440  38 60 00 01 */	li r3, 0x1
/* 80110644 0010D444  90 01 00 14 */	stw r0, 0x14(r1)
/* 80110648 0010D448  38 00 00 00 */	li r0, 0x0
/* 8011064C 0010D44C  90 0D 06 4C */	stw r0, lbl_805DD72C@sda21(r0)
/* 80110650 0010D450  90 0D 06 48 */	stw r0, lbl_805DD728@sda21(r0)
/* 80110654 0010D454  4B FD D1 AD */	bl kar_grboxgenerator__near_800ed800
/* 80110658 0010D458  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011065C 0010D45C  7C 08 03 A6 */	mtlr r0
/* 80110660 0010D460  38 21 00 10 */	addi r1, r1, 0x10
/* 80110664 0010D464  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_event_kind4c_cleanup_boxgenerator_state

# .text:0xD3C | 0x80110668 | size: 0x38
.fn kar_grcolosseum1_get_event_kind4e_spawn_scaled_angle, global
/* 80110668 0010D468  80 0D 06 50 */	lwz r0, lbl_805DD730@sda21(r0)
/* 8011066C 0010D46C  28 00 00 00 */	cmplwi r0, 0x0
/* 80110670 0010D470  4D 82 00 20 */	beqlr
/* 80110674 0010D474  80 AD 06 54 */	lwz r5, lbl_805DD734@sda21(r0)
/* 80110678 0010D478  28 05 00 00 */	cmplwi r5, 0x0
/* 8011067C 0010D47C  4D 82 00 20 */	beqlr
/* 80110680 0010D480  80 A5 00 04 */	lwz r5, 0x4(r5)
/* 80110684 0010D484  54 60 18 38 */	slwi r0, r3, 3
/* 80110688 0010D488  C0 22 94 30 */	lfs f1, lbl_805DFB30@sda21(r0)
/* 8011068C 0010D48C  7C 65 02 14 */	add r3, r5, r0
/* 80110690 0010D490  C0 03 00 04 */	lfs f0, 0x4(r3)
/* 80110694 0010D494  EC 01 00 32 */	fmuls f0, f1, f0
/* 80110698 0010D498  D0 04 00 00 */	stfs f0, 0x0(r4)
/* 8011069C 0010D49C  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_get_event_kind4e_spawn_scaled_angle

# .text:0xD74 | 0x801106A0 | size: 0x54
.fn kar_grcolosseum1_get_event_kind4e_spawn_vector, global
/* 801106A0 0010D4A0  80 0D 06 50 */	lwz r0, lbl_805DD730@sda21(r0)
/* 801106A4 0010D4A4  28 00 00 00 */	cmplwi r0, 0x0
/* 801106A8 0010D4A8  4D 82 00 20 */	beqlr
/* 801106AC 0010D4AC  80 ED 06 54 */	lwz r7, lbl_805DD734@sda21(r0)
/* 801106B0 0010D4B0  28 07 00 00 */	cmplwi r7, 0x0
/* 801106B4 0010D4B4  4D 82 00 20 */	beqlr
/* 801106B8 0010D4B8  1D 03 00 0C */	mulli r8, r3, 0xc
/* 801106BC 0010D4BC  80 67 00 0C */	lwz r3, 0xc(r7)
/* 801106C0 0010D4C0  7C 03 44 2E */	lfsx f0, r3, r8
/* 801106C4 0010D4C4  D0 04 00 00 */	stfs f0, 0x0(r4)
/* 801106C8 0010D4C8  80 6D 06 54 */	lwz r3, lbl_805DD734@sda21(r0)
/* 801106CC 0010D4CC  80 03 00 0C */	lwz r0, 0xc(r3)
/* 801106D0 0010D4D0  7C 60 42 14 */	add r3, r0, r8
/* 801106D4 0010D4D4  C0 03 00 04 */	lfs f0, 0x4(r3)
/* 801106D8 0010D4D8  D0 05 00 00 */	stfs f0, 0x0(r5)
/* 801106DC 0010D4DC  80 6D 06 54 */	lwz r3, lbl_805DD734@sda21(r0)
/* 801106E0 0010D4E0  80 03 00 0C */	lwz r0, 0xc(r3)
/* 801106E4 0010D4E4  7C 60 42 14 */	add r3, r0, r8
/* 801106E8 0010D4E8  C0 03 00 08 */	lfs f0, 0x8(r3)
/* 801106EC 0010D4EC  D0 06 00 00 */	stfs f0, 0x0(r6)
/* 801106F0 0010D4F0  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_get_event_kind4e_spawn_vector

# .text:0xDC8 | 0x801106F4 | size: 0x480
.fn kar_grcolosseum1_event_kind4e_build_weighted_spawn_pattern, global
/* 801106F4 0010D4F4  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 801106F8 0010D4F8  7C 08 02 A6 */	mflr r0
/* 801106FC 0010D4FC  90 01 00 54 */	stw r0, 0x54(r1)
/* 80110700 0010D500  39 61 00 50 */	addi r11, r1, 0x50
/* 80110704 0010D504  48 29 D4 1D */	bl _savegpr_14
/* 80110708 0010D508  4B FD E0 35 */	bl kar_greventgenerator_get_current_event_param
/* 8011070C 0010D50C  80 AD 06 50 */	lwz r5, lbl_805DD730@sda21(r0)
/* 80110710 0010D510  38 E0 00 00 */	li r7, 0x0
/* 80110714 0010D514  7C 7F 1B 78 */	mr r31, r3
/* 80110718 0010D518  38 80 FF FF */	li r4, -0x1
/* 8011071C 0010D51C  B0 E5 00 00 */	sth r7, 0x0(r5)
/* 80110720 0010D520  38 00 00 06 */	li r0, 0x6
/* 80110724 0010D524  7C E8 3B 78 */	mr r8, r7
/* 80110728 0010D528  39 40 00 00 */	li r10, 0x0
/* 8011072C 0010D52C  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110730 0010D530  B0 E3 00 02 */	sth r7, 0x2(r3)
/* 80110734 0010D534  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110738 0010D538  98 83 00 04 */	stb r4, 0x4(r3)
/* 8011073C 0010D53C  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110740 0010D540  98 E3 00 05 */	stb r7, 0x5(r3)
/* 80110744 0010D544  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110748 0010D548  98 E3 00 06 */	stb r7, 0x6(r3)
/* 8011074C 0010D54C  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110750 0010D550  98 E3 00 07 */	stb r7, 0x7(r3)
/* 80110754 0010D554  7C 09 03 A6 */	mtctr r0
.L_80110758:
/* 80110758 0010D558  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 8011075C 0010D55C  38 CA 00 08 */	addi r6, r10, 0x8
/* 80110760 0010D560  38 00 FF FF */	li r0, -0x1
/* 80110764 0010D564  38 AA 00 38 */	addi r5, r10, 0x38
/* 80110768 0010D568  7C 03 31 AE */	stbx r0, r3, r6
/* 8011076C 0010D56C  38 8A 00 68 */	addi r4, r10, 0x68
/* 80110770 0010D570  38 67 00 98 */	addi r3, r7, 0x98
/* 80110774 0010D574  39 E7 00 F8 */	addi r15, r7, 0xf8
/* 80110778 0010D578  81 6D 06 50 */	lwz r11, lbl_805DD730@sda21(r0)
/* 8011077C 0010D57C  39 20 00 00 */	li r9, 0x0
/* 80110780 0010D580  3A 08 01 58 */	addi r16, r8, 0x158
/* 80110784 0010D584  3A 26 00 01 */	addi r17, r6, 0x1
/* 80110788 0010D588  7C 0B 29 AE */	stbx r0, r11, r5
/* 8011078C 0010D58C  3A 45 00 01 */	addi r18, r5, 0x1
/* 80110790 0010D590  3A 67 00 9A */	addi r19, r7, 0x9a
/* 80110794 0010D594  3A 84 00 01 */	addi r20, r4, 0x1
/* 80110798 0010D598  81 6D 06 50 */	lwz r11, lbl_805DD730@sda21(r0)
/* 8011079C 0010D59C  3A A7 00 FA */	addi r21, r7, 0xfa
/* 801107A0 0010D5A0  3A C8 01 5C */	addi r22, r8, 0x15c
/* 801107A4 0010D5A4  3A E6 00 02 */	addi r23, r6, 0x2
/* 801107A8 0010D5A8  7C 0B 1B 2E */	sthx r0, r11, r3
/* 801107AC 0010D5AC  3B 05 00 02 */	addi r24, r5, 0x2
/* 801107B0 0010D5B0  3B 27 00 9C */	addi r25, r7, 0x9c
/* 801107B4 0010D5B4  3B 44 00 02 */	addi r26, r4, 0x2
/* 801107B8 0010D5B8  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 801107BC 0010D5BC  3B 67 00 FC */	addi r27, r7, 0xfc
/* 801107C0 0010D5C0  3B 88 01 60 */	addi r28, r8, 0x160
/* 801107C4 0010D5C4  3B A6 00 03 */	addi r29, r6, 0x3
/* 801107C8 0010D5C8  7C 03 21 AE */	stbx r0, r3, r4
/* 801107CC 0010D5CC  3B C5 00 03 */	addi r30, r5, 0x3
/* 801107D0 0010D5D0  39 87 00 9E */	addi r12, r7, 0x9e
/* 801107D4 0010D5D4  39 64 00 03 */	addi r11, r4, 0x3
/* 801107D8 0010D5D8  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 801107DC 0010D5DC  39 C7 00 FE */	addi r14, r7, 0xfe
/* 801107E0 0010D5E0  7D 23 7B 2E */	sthx r9, r3, r15
/* 801107E4 0010D5E4  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 801107E8 0010D5E8  7D 23 81 2E */	stwx r9, r3, r16
/* 801107EC 0010D5EC  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 801107F0 0010D5F0  7C 03 89 AE */	stbx r0, r3, r17
/* 801107F4 0010D5F4  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 801107F8 0010D5F8  7C 03 91 AE */	stbx r0, r3, r18
/* 801107FC 0010D5FC  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110800 0010D600  7C 03 9B 2E */	sthx r0, r3, r19
/* 80110804 0010D604  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110808 0010D608  7C 03 A1 AE */	stbx r0, r3, r20
/* 8011080C 0010D60C  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110810 0010D610  7D 23 AB 2E */	sthx r9, r3, r21
/* 80110814 0010D614  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110818 0010D618  7D 23 B1 2E */	stwx r9, r3, r22
/* 8011081C 0010D61C  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110820 0010D620  7C 03 B9 AE */	stbx r0, r3, r23
/* 80110824 0010D624  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110828 0010D628  7C 03 C1 AE */	stbx r0, r3, r24
/* 8011082C 0010D62C  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110830 0010D630  7C 03 CB 2E */	sthx r0, r3, r25
/* 80110834 0010D634  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110838 0010D638  7C 03 D1 AE */	stbx r0, r3, r26
/* 8011083C 0010D63C  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110840 0010D640  7D 23 DB 2E */	sthx r9, r3, r27
/* 80110844 0010D644  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110848 0010D648  7D 23 E1 2E */	stwx r9, r3, r28
/* 8011084C 0010D64C  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110850 0010D650  7C 03 E9 AE */	stbx r0, r3, r29
/* 80110854 0010D654  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110858 0010D658  7C 03 F1 AE */	stbx r0, r3, r30
/* 8011085C 0010D65C  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110860 0010D660  7C 03 63 2E */	sthx r0, r3, r12
/* 80110864 0010D664  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110868 0010D668  7C 03 59 AE */	stbx r0, r3, r11
/* 8011086C 0010D66C  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110870 0010D670  7D 23 73 2E */	sthx r9, r3, r14
/* 80110874 0010D674  81 CD 06 50 */	lwz r14, lbl_805DD730@sda21(r0)
/* 80110878 0010D678  39 88 01 64 */	addi r12, r8, 0x164
/* 8011087C 0010D67C  39 66 00 04 */	addi r11, r6, 0x4
/* 80110880 0010D680  38 65 00 04 */	addi r3, r5, 0x4
/* 80110884 0010D684  7D 2E 61 2E */	stwx r9, r14, r12
/* 80110888 0010D688  3B A7 00 A0 */	addi r29, r7, 0xa0
/* 8011088C 0010D68C  3B 64 00 04 */	addi r27, r4, 0x4
/* 80110890 0010D690  3B 47 01 00 */	addi r26, r7, 0x100
/* 80110894 0010D694  81 8D 06 50 */	lwz r12, lbl_805DD730@sda21(r0)
/* 80110898 0010D698  3B 28 01 68 */	addi r25, r8, 0x168
/* 8011089C 0010D69C  3B 06 00 05 */	addi r24, r6, 0x5
/* 801108A0 0010D6A0  3A E5 00 05 */	addi r23, r5, 0x5
/* 801108A4 0010D6A4  7C 0C 59 AE */	stbx r0, r12, r11
/* 801108A8 0010D6A8  3A C7 00 A2 */	addi r22, r7, 0xa2
/* 801108AC 0010D6AC  3A A4 00 05 */	addi r21, r4, 0x5
/* 801108B0 0010D6B0  39 E4 00 06 */	addi r15, r4, 0x6
/* 801108B4 0010D6B4  81 6D 06 50 */	lwz r11, lbl_805DD730@sda21(r0)
/* 801108B8 0010D6B8  3A 87 01 02 */	addi r20, r7, 0x102
/* 801108BC 0010D6BC  3A 68 01 6C */	addi r19, r8, 0x16c
/* 801108C0 0010D6C0  3A 46 00 06 */	addi r18, r6, 0x6
/* 801108C4 0010D6C4  7C 0B 19 AE */	stbx r0, r11, r3
/* 801108C8 0010D6C8  39 66 00 07 */	addi r11, r6, 0x7
/* 801108CC 0010D6CC  3A 25 00 06 */	addi r17, r5, 0x6
/* 801108D0 0010D6D0  38 C5 00 07 */	addi r6, r5, 0x7
/* 801108D4 0010D6D4  83 8D 06 50 */	lwz r28, lbl_805DD730@sda21(r0)
/* 801108D8 0010D6D8  3A 07 00 A4 */	addi r16, r7, 0xa4
/* 801108DC 0010D6DC  39 C7 01 04 */	addi r14, r7, 0x104
/* 801108E0 0010D6E0  39 88 01 70 */	addi r12, r8, 0x170
/* 801108E4 0010D6E4  7C 1C EB 2E */	sthx r0, r28, r29
/* 801108E8 0010D6E8  38 68 01 74 */	addi r3, r8, 0x174
/* 801108EC 0010D6EC  38 A7 00 A6 */	addi r5, r7, 0xa6
/* 801108F0 0010D6F0  3B A7 01 06 */	addi r29, r7, 0x106
/* 801108F4 0010D6F4  83 8D 06 50 */	lwz r28, lbl_805DD730@sda21(r0)
/* 801108F8 0010D6F8  38 84 00 07 */	addi r4, r4, 0x7
/* 801108FC 0010D6FC  38 E7 00 10 */	addi r7, r7, 0x10
/* 80110900 0010D700  39 08 00 20 */	addi r8, r8, 0x20
/* 80110904 0010D704  7C 1C D9 AE */	stbx r0, r28, r27
/* 80110908 0010D708  39 4A 00 08 */	addi r10, r10, 0x8
/* 8011090C 0010D70C  83 6D 06 50 */	lwz r27, lbl_805DD730@sda21(r0)
/* 80110910 0010D710  7D 3B D3 2E */	sthx r9, r27, r26
/* 80110914 0010D714  83 4D 06 50 */	lwz r26, lbl_805DD730@sda21(r0)
/* 80110918 0010D718  7D 3A C9 2E */	stwx r9, r26, r25
/* 8011091C 0010D71C  83 2D 06 50 */	lwz r25, lbl_805DD730@sda21(r0)
/* 80110920 0010D720  7C 19 C1 AE */	stbx r0, r25, r24
/* 80110924 0010D724  83 0D 06 50 */	lwz r24, lbl_805DD730@sda21(r0)
/* 80110928 0010D728  7C 18 B9 AE */	stbx r0, r24, r23
/* 8011092C 0010D72C  82 ED 06 50 */	lwz r23, lbl_805DD730@sda21(r0)
/* 80110930 0010D730  7C 17 B3 2E */	sthx r0, r23, r22
/* 80110934 0010D734  82 CD 06 50 */	lwz r22, lbl_805DD730@sda21(r0)
/* 80110938 0010D738  7C 16 A9 AE */	stbx r0, r22, r21
/* 8011093C 0010D73C  82 AD 06 50 */	lwz r21, lbl_805DD730@sda21(r0)
/* 80110940 0010D740  7D 35 A3 2E */	sthx r9, r21, r20
/* 80110944 0010D744  82 8D 06 50 */	lwz r20, lbl_805DD730@sda21(r0)
/* 80110948 0010D748  7D 34 99 2E */	stwx r9, r20, r19
/* 8011094C 0010D74C  82 6D 06 50 */	lwz r19, lbl_805DD730@sda21(r0)
/* 80110950 0010D750  7C 13 91 AE */	stbx r0, r19, r18
/* 80110954 0010D754  82 4D 06 50 */	lwz r18, lbl_805DD730@sda21(r0)
/* 80110958 0010D758  7C 12 89 AE */	stbx r0, r18, r17
/* 8011095C 0010D75C  82 2D 06 50 */	lwz r17, lbl_805DD730@sda21(r0)
/* 80110960 0010D760  7C 11 83 2E */	sthx r0, r17, r16
/* 80110964 0010D764  82 0D 06 50 */	lwz r16, lbl_805DD730@sda21(r0)
/* 80110968 0010D768  7C 10 79 AE */	stbx r0, r16, r15
/* 8011096C 0010D76C  81 ED 06 50 */	lwz r15, lbl_805DD730@sda21(r0)
/* 80110970 0010D770  7D 2F 73 2E */	sthx r9, r15, r14
/* 80110974 0010D774  81 CD 06 50 */	lwz r14, lbl_805DD730@sda21(r0)
/* 80110978 0010D778  7D 2E 61 2E */	stwx r9, r14, r12
/* 8011097C 0010D77C  81 8D 06 50 */	lwz r12, lbl_805DD730@sda21(r0)
/* 80110980 0010D780  7C 0C 59 AE */	stbx r0, r12, r11
/* 80110984 0010D784  81 6D 06 50 */	lwz r11, lbl_805DD730@sda21(r0)
/* 80110988 0010D788  7C 0B 31 AE */	stbx r0, r11, r6
/* 8011098C 0010D78C  80 CD 06 50 */	lwz r6, lbl_805DD730@sda21(r0)
/* 80110990 0010D790  7C 06 2B 2E */	sthx r0, r6, r5
/* 80110994 0010D794  80 AD 06 50 */	lwz r5, lbl_805DD730@sda21(r0)
/* 80110998 0010D798  7C 05 21 AE */	stbx r0, r5, r4
/* 8011099C 0010D79C  80 8D 06 50 */	lwz r4, lbl_805DD730@sda21(r0)
/* 801109A0 0010D7A0  7D 24 EB 2E */	sthx r9, r4, r29
/* 801109A4 0010D7A4  80 8D 06 50 */	lwz r4, lbl_805DD730@sda21(r0)
/* 801109A8 0010D7A8  7D 24 19 2E */	stwx r9, r4, r3
/* 801109AC 0010D7AC  42 00 FD AC */	bdnz .L_80110758
/* 801109B0 0010D7B0  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 801109B4 0010D7B4  38 60 00 00 */	li r3, 0x0
/* 801109B8 0010D7B8  7C 09 03 A6 */	mtctr r0
/* 801109BC 0010D7BC  2C 00 00 00 */	cmpwi r0, 0x0
/* 801109C0 0010D7C0  40 81 00 24 */	ble .L_801109E4
.L_801109C4:
/* 801109C4 0010D7C4  80 9F 00 1C */	lwz r4, 0x1c(r31)
/* 801109C8 0010D7C8  38 09 00 02 */	addi r0, r9, 0x2
/* 801109CC 0010D7CC  7C 84 02 AE */	lhax r4, r4, r0
/* 801109D0 0010D7D0  7C 80 07 35 */	extsh. r0, r4
/* 801109D4 0010D7D4  40 81 00 08 */	ble .L_801109DC
/* 801109D8 0010D7D8  7C 63 22 14 */	add r3, r3, r4
.L_801109DC:
/* 801109DC 0010D7DC  39 29 00 04 */	addi r9, r9, 0x4
/* 801109E0 0010D7E0  42 00 FF E4 */	bdnz .L_801109C4
.L_801109E4:
/* 801109E4 0010D7E4  48 30 DC 85 */	bl HSD_Randi
/* 801109E8 0010D7E8  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 801109EC 0010D7EC  38 E0 00 00 */	li r7, 0x0
/* 801109F0 0010D7F0  7C E8 3B 78 */	mr r8, r7
/* 801109F4 0010D7F4  7C E4 3B 78 */	mr r4, r7
/* 801109F8 0010D7F8  7C 09 03 A6 */	mtctr r0
/* 801109FC 0010D7FC  2C 00 00 00 */	cmpwi r0, 0x0
/* 80110A00 0010D800  40 81 00 44 */	ble .L_80110A44
.L_80110A04:
/* 80110A04 0010D804  80 DF 00 1C */	lwz r6, 0x1c(r31)
/* 80110A08 0010D808  38 04 00 02 */	addi r0, r4, 0x2
/* 80110A0C 0010D80C  7C A6 02 AE */	lhax r5, r6, r0
/* 80110A10 0010D810  7C A0 07 35 */	extsh. r0, r5
/* 80110A14 0010D814  40 81 00 24 */	ble .L_80110A38
/* 80110A18 0010D818  7D 08 2A 14 */	add r8, r8, r5
/* 80110A1C 0010D81C  7C 03 40 00 */	cmpw r3, r8
/* 80110A20 0010D820  40 80 00 18 */	bge .L_80110A38
/* 80110A24 0010D824  54 E0 10 3A */	slwi r0, r7, 2
/* 80110A28 0010D828  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110A2C 0010D82C  7C 06 02 AE */	lhax r0, r6, r0
/* 80110A30 0010D830  98 03 00 04 */	stb r0, 0x4(r3)
/* 80110A34 0010D834  48 00 00 10 */	b .L_80110A44
.L_80110A38:
/* 80110A38 0010D838  38 84 00 04 */	addi r4, r4, 0x4
/* 80110A3C 0010D83C  38 E7 00 01 */	addi r7, r7, 0x1
/* 80110A40 0010D840  42 00 FF C4 */	bdnz .L_80110A04
.L_80110A44:
/* 80110A44 0010D844  80 CD 06 50 */	lwz r6, lbl_805DD730@sda21(r0)
/* 80110A48 0010D848  38 A0 00 00 */	li r5, 0x0
/* 80110A4C 0010D84C  38 00 00 30 */	li r0, 0x30
/* 80110A50 0010D850  7C A3 2B 78 */	mr r3, r5
/* 80110A54 0010D854  7C A4 2B 78 */	mr r4, r5
/* 80110A58 0010D858  98 A6 00 05 */	stb r5, 0x5(r6)
/* 80110A5C 0010D85C  7C 09 03 A6 */	mtctr r0
.L_80110A60:
/* 80110A60 0010D860  81 0D 06 50 */	lwz r8, lbl_805DD730@sda21(r0)
/* 80110A64 0010D864  80 DF 00 14 */	lwz r6, 0x14(r31)
/* 80110A68 0010D868  88 08 00 04 */	lbz r0, 0x4(r8)
/* 80110A6C 0010D86C  7C 00 07 74 */	extsb r0, r0
/* 80110A70 0010D870  54 00 10 3A */	slwi r0, r0, 2
/* 80110A74 0010D874  7C 06 00 2E */	lwzx r0, r6, r0
/* 80110A78 0010D878  7C C0 1A 14 */	add r6, r0, r3
/* 80110A7C 0010D87C  A8 E6 00 00 */	lha r7, 0x0(r6)
/* 80110A80 0010D880  2C 07 FF FF */	cmpwi r7, -0x1
/* 80110A84 0010D884  40 82 00 10 */	bne .L_80110A94
/* 80110A88 0010D888  A8 06 00 02 */	lha r0, 0x2(r6)
/* 80110A8C 0010D88C  2C 00 FF FF */	cmpwi r0, -0x1
/* 80110A90 0010D890  41 82 00 CC */	beq .L_80110B5C
.L_80110A94:
/* 80110A94 0010D894  38 05 00 08 */	addi r0, r5, 0x8
/* 80110A98 0010D898  39 83 00 02 */	addi r12, r3, 0x2
/* 80110A9C 0010D89C  7C E8 01 AE */	stbx r7, r8, r0
/* 80110AA0 0010D8A0  39 65 00 38 */	addi r11, r5, 0x38
/* 80110AA4 0010D8A4  38 E5 00 68 */	addi r7, r5, 0x68
/* 80110AA8 0010D8A8  39 43 00 06 */	addi r10, r3, 0x6
/* 80110AAC 0010D8AC  82 0D 06 50 */	lwz r16, lbl_805DD730@sda21(r0)
/* 80110AB0 0010D8B0  39 24 00 98 */	addi r9, r4, 0x98
/* 80110AB4 0010D8B4  38 04 00 F8 */	addi r0, r4, 0xf8
/* 80110AB8 0010D8B8  81 FF 00 14 */	lwz r15, 0x14(r31)
/* 80110ABC 0010D8BC  89 D0 00 04 */	lbz r14, 0x4(r16)
/* 80110AC0 0010D8C0  39 03 00 04 */	addi r8, r3, 0x4
/* 80110AC4 0010D8C4  38 C3 00 08 */	addi r6, r3, 0x8
/* 80110AC8 0010D8C8  38 63 00 0C */	addi r3, r3, 0xc
/* 80110ACC 0010D8CC  7D CE 07 74 */	extsb r14, r14
/* 80110AD0 0010D8D0  38 84 00 02 */	addi r4, r4, 0x2
/* 80110AD4 0010D8D4  55 CE 10 3A */	slwi r14, r14, 2
/* 80110AD8 0010D8D8  38 A5 00 01 */	addi r5, r5, 0x1
/* 80110ADC 0010D8DC  7D CF 70 2E */	lwzx r14, r15, r14
/* 80110AE0 0010D8E0  7D 8E 62 AE */	lhax r12, r14, r12
/* 80110AE4 0010D8E4  7D 90 59 AE */	stbx r12, r16, r11
/* 80110AE8 0010D8E8  81 CD 06 50 */	lwz r14, lbl_805DD730@sda21(r0)
/* 80110AEC 0010D8EC  81 9F 00 14 */	lwz r12, 0x14(r31)
/* 80110AF0 0010D8F0  89 6E 00 04 */	lbz r11, 0x4(r14)
/* 80110AF4 0010D8F4  7D 6B 07 74 */	extsb r11, r11
/* 80110AF8 0010D8F8  55 6B 10 3A */	slwi r11, r11, 2
/* 80110AFC 0010D8FC  7D 6C 58 2E */	lwzx r11, r12, r11
/* 80110B00 0010D900  7D 4B 52 AE */	lhax r10, r11, r10
/* 80110B04 0010D904  7D 4E 4B 2E */	sthx r10, r14, r9
/* 80110B08 0010D908  81 6D 06 50 */	lwz r11, lbl_805DD730@sda21(r0)
/* 80110B0C 0010D90C  81 5F 00 14 */	lwz r10, 0x14(r31)
/* 80110B10 0010D910  89 2B 00 04 */	lbz r9, 0x4(r11)
/* 80110B14 0010D914  7D 29 07 74 */	extsb r9, r9
/* 80110B18 0010D918  55 29 10 3A */	slwi r9, r9, 2
/* 80110B1C 0010D91C  7D 2A 48 2E */	lwzx r9, r10, r9
/* 80110B20 0010D920  7D 09 42 AE */	lhax r8, r9, r8
/* 80110B24 0010D924  7D 0B 39 AE */	stbx r8, r11, r7
/* 80110B28 0010D928  81 2D 06 50 */	lwz r9, lbl_805DD730@sda21(r0)
/* 80110B2C 0010D92C  81 1F 00 14 */	lwz r8, 0x14(r31)
/* 80110B30 0010D930  88 E9 00 04 */	lbz r7, 0x4(r9)
/* 80110B34 0010D934  7C E7 07 74 */	extsb r7, r7
/* 80110B38 0010D938  54 E7 10 3A */	slwi r7, r7, 2
/* 80110B3C 0010D93C  7C E8 38 2E */	lwzx r7, r8, r7
/* 80110B40 0010D940  7C C7 30 2E */	lwzx r6, r7, r6
/* 80110B44 0010D944  7C C9 03 2E */	sthx r6, r9, r0
/* 80110B48 0010D948  80 ED 06 50 */	lwz r7, lbl_805DD730@sda21(r0)
/* 80110B4C 0010D94C  88 C7 00 05 */	lbz r6, 0x5(r7)
/* 80110B50 0010D950  38 06 00 01 */	addi r0, r6, 0x1
/* 80110B54 0010D954  98 07 00 05 */	stb r0, 0x5(r7)
/* 80110B58 0010D958  42 00 FF 08 */	bdnz .L_80110A60
.L_80110B5C:
/* 80110B5C 0010D95C  39 61 00 50 */	addi r11, r1, 0x50
/* 80110B60 0010D960  48 29 D0 0D */	bl _restgpr_14
/* 80110B64 0010D964  80 01 00 54 */	lwz r0, 0x54(r1)
/* 80110B68 0010D968  7C 08 03 A6 */	mtlr r0
/* 80110B6C 0010D96C  38 21 00 50 */	addi r1, r1, 0x50
/* 80110B70 0010D970  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_event_kind4e_build_weighted_spawn_pattern

# .text:0x1248 | 0x80110B74 | size: 0x98
.fn kar_grcolosseum1_event_kind4e_init_pattern_state, global
/* 80110B74 0010D974  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80110B78 0010D978  7C 08 02 A6 */	mflr r0
/* 80110B7C 0010D97C  3C 80 80 55 */	lis r4, kar_grcolosseum1_kind4e_pattern_state_allocator@ha
/* 80110B80 0010D980  38 A0 00 04 */	li r5, 0x4
/* 80110B84 0010D984  90 01 00 14 */	stw r0, 0x14(r1)
/* 80110B88 0010D988  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80110B8C 0010D98C  7C 7F 1B 78 */	mr r31, r3
/* 80110B90 0010D990  38 64 78 38 */	addi r3, r4, kar_grcolosseum1_kind4e_pattern_state_allocator@l
/* 80110B94 0010D994  38 80 02 18 */	li r4, 0x218
/* 80110B98 0010D998  48 30 76 C5 */	bl HSD_ObjAllocInit
/* 80110B9C 0010D99C  3C 60 80 55 */	lis r3, kar_grcolosseum1_kind4e_pattern_state_allocator@ha
/* 80110BA0 0010D9A0  38 63 78 38 */	addi r3, r3, kar_grcolosseum1_kind4e_pattern_state_allocator@l
/* 80110BA4 0010D9A4  48 30 75 41 */	bl HSD_ObjAlloc
/* 80110BA8 0010D9A8  28 03 00 00 */	cmplwi r3, 0x0
/* 80110BAC 0010D9AC  90 6D 06 50 */	stw r3, lbl_805DD730@sda21(r0)
/* 80110BB0 0010D9B0  41 82 00 38 */	beq .L_80110BE8
/* 80110BB4 0010D9B4  7F E3 FB 78 */	mr r3, r31
/* 80110BB8 0010D9B8  4B FD DB 85 */	bl kar_greventgenerator_get_current_event_param
/* 80110BBC 0010D9BC  28 03 00 00 */	cmplwi r3, 0x0
/* 80110BC0 0010D9C0  90 6D 06 54 */	stw r3, lbl_805DD734@sda21(r0)
/* 80110BC4 0010D9C4  41 82 00 24 */	beq .L_80110BE8
/* 80110BC8 0010D9C8  7F E3 FB 78 */	mr r3, r31
/* 80110BCC 0010D9CC  4B FF FB 29 */	bl kar_grcolosseum1_event_kind4e_build_weighted_spawn_pattern
/* 80110BD0 0010D9D0  48 14 35 A5 */	bl fn_80254174
/* 80110BD4 0010D9D4  38 60 00 02 */	li r3, 0x2
/* 80110BD8 0010D9D8  4B FD CB AD */	bl kar_grboxgenerator__near_800ed784
/* 80110BDC 0010D9DC  38 00 00 00 */	li r0, 0x0
/* 80110BE0 0010D9E0  90 0D 06 58 */	stw r0, lbl_805DD738@sda21(r0)
/* 80110BE4 0010D9E4  48 00 00 14 */	b .L_80110BF8
.L_80110BE8:
/* 80110BE8 0010D9E8  38 00 00 00 */	li r0, 0x0
/* 80110BEC 0010D9EC  90 0D 06 50 */	stw r0, lbl_805DD730@sda21(r0)
/* 80110BF0 0010D9F0  90 0D 06 54 */	stw r0, lbl_805DD734@sda21(r0)
/* 80110BF4 0010D9F4  90 0D 06 58 */	stw r0, lbl_805DD738@sda21(r0)
.L_80110BF8:
/* 80110BF8 0010D9F8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80110BFC 0010D9FC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80110C00 0010DA00  7C 08 03 A6 */	mtlr r0
/* 80110C04 0010DA04  38 21 00 10 */	addi r1, r1, 0x10
/* 80110C08 0010DA08  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_event_kind4e_init_pattern_state

# .text:0x12E0 | 0x80110C0C | size: 0x328
.fn kar_grcolosseum1_event_kind4e_update_spawn_pattern_rows, global
/* 80110C0C 0010DA0C  94 21 FF 60 */	stwu r1, -0xa0(r1)
/* 80110C10 0010DA10  7C 08 02 A6 */	mflr r0
/* 80110C14 0010DA14  90 01 00 A4 */	stw r0, 0xa4(r1)
/* 80110C18 0010DA18  39 61 00 A0 */	addi r11, r1, 0xa0
/* 80110C1C 0010DA1C  48 29 CF 35 */	bl _savegpr_26
/* 80110C20 0010DA20  80 8D 06 50 */	lwz r4, lbl_805DD730@sda21(r0)
/* 80110C24 0010DA24  7C 7B 1B 78 */	mr r27, r3
/* 80110C28 0010DA28  28 04 00 00 */	cmplwi r4, 0x0
/* 80110C2C 0010DA2C  41 82 02 D8 */	beq .L_80110F04
/* 80110C30 0010DA30  88 04 00 07 */	lbz r0, 0x7(r4)
/* 80110C34 0010DA34  7C 00 07 75 */	extsb. r0, r0
/* 80110C38 0010DA38  40 82 02 E4 */	bne .L_80110F1C
/* 80110C3C 0010DA3C  4B FD DB 01 */	bl kar_greventgenerator_get_current_event_param
/* 80110C40 0010DA40  3B C1 00 3C */	addi r30, r1, 0x3c
/* 80110C44 0010DA44  3B A1 00 30 */	addi r29, r1, 0x30
/* 80110C48 0010DA48  3B 80 00 00 */	li r28, 0x0
/* 80110C4C 0010DA4C  48 00 01 D4 */	b .L_80110E20
.L_80110C50:
/* 80110C50 0010DA50  28 1B 00 00 */	cmplwi r27, 0x0
/* 80110C54 0010DA54  38 60 00 00 */	li r3, 0x0
/* 80110C58 0010DA58  41 82 01 84 */	beq .L_80110DDC
/* 80110C5C 0010DA5C  7F 63 DB 78 */	mr r3, r27
/* 80110C60 0010DA60  4B FD DA DD */	bl kar_greventgenerator_get_current_event_param
/* 80110C64 0010DA64  38 00 00 4E */	li r0, 0x4e
/* 80110C68 0010DA68  7C 7F 1B 78 */	mr r31, r3
/* 80110C6C 0010DA6C  90 01 00 20 */	stw r0, 0x20(r1)
/* 80110C70 0010DA70  7F 63 DB 78 */	mr r3, r27
/* 80110C74 0010DA74  4B FD DA 79 */	bl kar_greventgenerator_get_current_eventpos_start
/* 80110C78 0010DA78  81 2D 06 50 */	lwz r9, lbl_805DD730@sda21(r0)
/* 80110C7C 0010DA7C  7F A5 EB 78 */	mr r5, r29
/* 80110C80 0010DA80  81 1F 00 04 */	lwz r8, 0x4(r31)
/* 80110C84 0010DA84  7F C6 F3 78 */	mr r6, r30
/* 80110C88 0010DA88  88 09 00 06 */	lbz r0, 0x6(r9)
/* 80110C8C 0010DA8C  38 81 00 08 */	addi r4, r1, 0x8
/* 80110C90 0010DA90  7C 07 07 74 */	extsb r7, r0
/* 80110C94 0010DA94  38 07 00 08 */	addi r0, r7, 0x8
/* 80110C98 0010DA98  7C 09 00 AE */	lbzx r0, r9, r0
/* 80110C9C 0010DA9C  7C 00 07 74 */	extsb r0, r0
/* 80110CA0 0010DAA0  54 00 18 38 */	slwi r0, r0, 3
/* 80110CA4 0010DAA4  7C 08 02 AE */	lhax r0, r8, r0
/* 80110CA8 0010DAA8  7F 40 1A 14 */	add r26, r0, r3
/* 80110CAC 0010DAAC  7F 43 D3 78 */	mr r3, r26
/* 80110CB0 0010DAB0  4B FC 05 4D */	bl kar_grcommon_get_eventpos_vectors_by_index
/* 80110CB4 0010DAB4  7F A5 EB 78 */	mr r5, r29
/* 80110CB8 0010DAB8  7F C6 F3 78 */	mr r6, r30
/* 80110CBC 0010DABC  38 7A 00 01 */	addi r3, r26, 0x1
/* 80110CC0 0010DAC0  38 81 00 14 */	addi r4, r1, 0x14
/* 80110CC4 0010DAC4  4B FC 05 39 */	bl kar_grcommon_get_eventpos_vectors_by_index
/* 80110CC8 0010DAC8  48 30 D9 49 */	bl HSD_Randf
/* 80110CCC 0010DACC  C0 41 00 08 */	lfs f2, 0x8(r1)
/* 80110CD0 0010DAD0  C0 01 00 14 */	lfs f0, 0x14(r1)
/* 80110CD4 0010DAD4  EC 00 10 28 */	fsubs f0, f0, f2
/* 80110CD8 0010DAD8  EC 00 10 7A */	fmadds f0, f0, f1, f2
/* 80110CDC 0010DADC  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 80110CE0 0010DAE0  48 30 D9 31 */	bl HSD_Randf
/* 80110CE4 0010DAE4  C0 61 00 10 */	lfs f3, 0x10(r1)
/* 80110CE8 0010DAE8  3C 60 80 4B */	lis r3, lbl_804B1D64@ha
/* 80110CEC 0010DAEC  C0 41 00 1C */	lfs f2, 0x1c(r1)
/* 80110CF0 0010DAF0  38 A3 1D 64 */	addi r5, r3, lbl_804B1D64@l
/* 80110CF4 0010DAF4  3C 60 80 4B */	lis r3, lbl_804B1D4C@ha
/* 80110CF8 0010DAF8  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 80110CFC 0010DAFC  EC 42 18 28 */	fsubs f2, f2, f3
/* 80110D00 0010DB00  38 83 1D 4C */	addi r4, r3, lbl_804B1D4C@l
/* 80110D04 0010DB04  83 45 00 00 */	lwz r26, 0x0(r5)
/* 80110D08 0010DB08  3C 60 77 36 */	lis r3, 0x7736
/* 80110D0C 0010DB0C  81 85 00 04 */	lwz r12, 0x4(r5)
/* 80110D10 0010DB10  38 C3 94 00 */	subi r6, r3, 0x6c00
/* 80110D14 0010DB14  81 65 00 08 */	lwz r11, 0x8(r5)
/* 80110D18 0010DB18  EC 22 18 7A */	fmadds f1, f2, f1, f3
/* 80110D1C 0010DB1C  81 44 00 00 */	lwz r10, 0x0(r4)
/* 80110D20 0010DB20  39 20 FF FF */	li r9, -0x1
/* 80110D24 0010DB24  81 04 00 04 */	lwz r8, 0x4(r4)
/* 80110D28 0010DB28  38 E0 00 00 */	li r7, 0x0
/* 80110D2C 0010DB2C  80 A4 00 08 */	lwz r5, 0x8(r4)
/* 80110D30 0010DB30  D0 01 00 28 */	stfs f0, 0x28(r1)
/* 80110D34 0010DB34  38 00 00 01 */	li r0, 0x1
/* 80110D38 0010DB38  80 8D 06 50 */	lwz r4, lbl_805DD730@sda21(r0)
/* 80110D3C 0010DB3C  38 61 00 20 */	addi r3, r1, 0x20
/* 80110D40 0010DB40  D0 21 00 2C */	stfs f1, 0x2c(r1)
/* 80110D44 0010DB44  C0 02 94 34 */	lfs f0, lbl_805DFB34@sda21(r0)
/* 80110D48 0010DB48  93 41 00 30 */	stw r26, 0x30(r1)
/* 80110D4C 0010DB4C  91 81 00 34 */	stw r12, 0x34(r1)
/* 80110D50 0010DB50  91 61 00 38 */	stw r11, 0x38(r1)
/* 80110D54 0010DB54  91 41 00 3C */	stw r10, 0x3c(r1)
/* 80110D58 0010DB58  91 01 00 40 */	stw r8, 0x40(r1)
/* 80110D5C 0010DB5C  90 A1 00 44 */	stw r5, 0x44(r1)
/* 80110D60 0010DB60  88 A4 00 06 */	lbz r5, 0x6(r4)
/* 80110D64 0010DB64  81 7F 00 0C */	lwz r11, 0xc(r31)
/* 80110D68 0010DB68  7C AA 07 74 */	extsb r10, r5
/* 80110D6C 0010DB6C  38 AA 00 38 */	addi r5, r10, 0x38
/* 80110D70 0010DB70  7D 04 28 AE */	lbzx r8, r4, r5
/* 80110D74 0010DB74  55 45 08 3C */	slwi r5, r10, 1
/* 80110D78 0010DB78  7D 84 52 14 */	add r12, r4, r10
/* 80110D7C 0010DB7C  7D 0A 07 74 */	extsb r10, r8
/* 80110D80 0010DB80  39 05 00 F8 */	addi r8, r5, 0xf8
/* 80110D84 0010DB84  1C AA 00 0C */	mulli r5, r10, 0xc
/* 80110D88 0010DB88  38 A5 00 08 */	addi r5, r5, 0x8
/* 80110D8C 0010DB8C  7C 2B 2C 2E */	lfsx f1, r11, r5
/* 80110D90 0010DB90  D0 21 00 48 */	stfs f1, 0x48(r1)
/* 80110D94 0010DB94  91 21 00 4C */	stw r9, 0x4c(r1)
/* 80110D98 0010DB98  91 21 00 50 */	stw r9, 0x50(r1)
/* 80110D9C 0010DB9C  90 E1 00 54 */	stw r7, 0x54(r1)
/* 80110DA0 0010DBA0  90 C1 00 58 */	stw r6, 0x58(r1)
/* 80110DA4 0010DBA4  88 CC 00 38 */	lbz r6, 0x38(r12)
/* 80110DA8 0010DBA8  88 AC 00 08 */	lbz r5, 0x8(r12)
/* 80110DAC 0010DBAC  7D 04 42 2E */	lhzx r8, r4, r8
/* 80110DB0 0010DBB0  7C C6 07 74 */	extsb r6, r6
/* 80110DB4 0010DBB4  88 EC 00 68 */	lbz r7, 0x68(r12)
/* 80110DB8 0010DBB8  54 A4 44 2E */	clrlslwi r4, r5, 24, 8
/* 80110DBC 0010DBBC  50 C4 06 3E */	rlwimi r4, r6, 0, 24, 31
/* 80110DC0 0010DBC0  7C E5 07 74 */	extsb r5, r7
/* 80110DC4 0010DBC4  90 01 00 60 */	stw r0, 0x60(r1)
/* 80110DC8 0010DBC8  50 A4 82 9E */	rlwimi r4, r5, 16, 10, 15
/* 80110DCC 0010DBCC  51 04 B0 12 */	rlwimi r4, r8, 22, 0, 9
/* 80110DD0 0010DBD0  D0 01 00 70 */	stfs f0, 0x70(r1)
/* 80110DD4 0010DBD4  90 81 00 5C */	stw r4, 0x5c(r1)
/* 80110DD8 0010DBD8  48 0E AD 79 */	bl fn_801FBB50
.L_80110DDC:
/* 80110DDC 0010DBDC  80 AD 06 50 */	lwz r5, lbl_805DD730@sda21(r0)
/* 80110DE0 0010DBE0  88 05 00 06 */	lbz r0, 0x6(r5)
/* 80110DE4 0010DBE4  7C 00 07 74 */	extsb r0, r0
/* 80110DE8 0010DBE8  54 04 10 3A */	slwi r4, r0, 2
/* 80110DEC 0010DBEC  38 04 01 58 */	addi r0, r4, 0x158
/* 80110DF0 0010DBF0  7C 65 01 2E */	stwx r3, r5, r0
/* 80110DF4 0010DBF4  80 8D 06 50 */	lwz r4, lbl_805DD730@sda21(r0)
/* 80110DF8 0010DBF8  88 04 00 06 */	lbz r0, 0x6(r4)
/* 80110DFC 0010DBFC  7C 00 07 74 */	extsb r0, r0
/* 80110E00 0010DC00  54 03 08 3C */	slwi r3, r0, 1
/* 80110E04 0010DC04  38 03 00 98 */	addi r0, r3, 0x98
/* 80110E08 0010DC08  7C 04 02 AE */	lhax r0, r4, r0
/* 80110E0C 0010DC0C  B0 04 00 02 */	sth r0, 0x2(r4)
/* 80110E10 0010DC10  80 8D 06 50 */	lwz r4, lbl_805DD730@sda21(r0)
/* 80110E14 0010DC14  88 64 00 06 */	lbz r3, 0x6(r4)
/* 80110E18 0010DC18  38 03 00 01 */	addi r0, r3, 0x1
/* 80110E1C 0010DC1C  98 04 00 06 */	stb r0, 0x6(r4)
.L_80110E20:
/* 80110E20 0010DC20  80 8D 06 50 */	lwz r4, lbl_805DD730@sda21(r0)
/* 80110E24 0010DC24  88 64 00 06 */	lbz r3, 0x6(r4)
/* 80110E28 0010DC28  88 04 00 05 */	lbz r0, 0x5(r4)
/* 80110E2C 0010DC2C  7C 63 07 74 */	extsb r3, r3
/* 80110E30 0010DC30  7C 00 07 74 */	extsb r0, r0
/* 80110E34 0010DC34  7C 03 00 00 */	cmpw r3, r0
/* 80110E38 0010DC38  40 80 00 10 */	bge .L_80110E48
/* 80110E3C 0010DC3C  A8 04 00 02 */	lha r0, 0x2(r4)
/* 80110E40 0010DC40  2C 00 00 00 */	cmpwi r0, 0x0
/* 80110E44 0010DC44  41 82 FE 0C */	beq .L_80110C50
.L_80110E48:
/* 80110E48 0010DC48  80 6D 12 54 */	lwz r3, lbl_805DE334@sda21(r0)
/* 80110E4C 0010DC4C  80 A3 00 30 */	lwz r5, 0x30(r3)
/* 80110E50 0010DC50  48 00 00 38 */	b .L_80110E88
.L_80110E54:
/* 80110E54 0010DC54  88 04 00 05 */	lbz r0, 0x5(r4)
/* 80110E58 0010DC58  7C 83 23 78 */	mr r3, r4
/* 80110E5C 0010DC5C  7C 00 07 75 */	extsb. r0, r0
/* 80110E60 0010DC60  7C 09 03 A6 */	mtctr r0
/* 80110E64 0010DC64  40 81 00 20 */	ble .L_80110E84
.L_80110E68:
/* 80110E68 0010DC68  80 03 01 58 */	lwz r0, 0x158(r3)
/* 80110E6C 0010DC6C  7C 05 00 40 */	cmplw r5, r0
/* 80110E70 0010DC70  40 82 00 0C */	bne .L_80110E7C
/* 80110E74 0010DC74  3B 80 00 01 */	li r28, 0x1
/* 80110E78 0010DC78  48 00 00 0C */	b .L_80110E84
.L_80110E7C:
/* 80110E7C 0010DC7C  38 63 00 04 */	addi r3, r3, 0x4
/* 80110E80 0010DC80  42 00 FF E8 */	bdnz .L_80110E68
.L_80110E84:
/* 80110E84 0010DC84  80 A5 00 08 */	lwz r5, 0x8(r5)
.L_80110E88:
/* 80110E88 0010DC88  28 05 00 00 */	cmplwi r5, 0x0
/* 80110E8C 0010DC8C  40 82 FF C8 */	bne .L_80110E54
/* 80110E90 0010DC90  A8 64 00 02 */	lha r3, 0x2(r4)
/* 80110E94 0010DC94  2C 03 00 00 */	cmpwi r3, 0x0
/* 80110E98 0010DC98  40 81 00 0C */	ble .L_80110EA4
/* 80110E9C 0010DC9C  38 03 FF FF */	subi r0, r3, 0x1
/* 80110EA0 0010DCA0  B0 04 00 02 */	sth r0, 0x2(r4)
.L_80110EA4:
/* 80110EA4 0010DCA4  2C 1C 00 00 */	cmpwi r28, 0x0
/* 80110EA8 0010DCA8  40 82 00 40 */	bne .L_80110EE8
/* 80110EAC 0010DCAC  80 8D 06 50 */	lwz r4, lbl_805DD730@sda21(r0)
/* 80110EB0 0010DCB0  88 64 00 06 */	lbz r3, 0x6(r4)
/* 80110EB4 0010DCB4  88 04 00 05 */	lbz r0, 0x5(r4)
/* 80110EB8 0010DCB8  7C 63 07 74 */	extsb r3, r3
/* 80110EBC 0010DCBC  7C 00 07 74 */	extsb r0, r0
/* 80110EC0 0010DCC0  7C 03 00 00 */	cmpw r3, r0
/* 80110EC4 0010DCC4  40 82 00 10 */	bne .L_80110ED4
/* 80110EC8 0010DCC8  38 00 00 01 */	li r0, 0x1
/* 80110ECC 0010DCCC  98 04 00 07 */	stb r0, 0x7(r4)
/* 80110ED0 0010DCD0  48 00 00 18 */	b .L_80110EE8
.L_80110ED4:
/* 80110ED4 0010DCD4  A8 04 00 02 */	lha r0, 0x2(r4)
/* 80110ED8 0010DCD8  2C 00 FF FF */	cmpwi r0, -0x1
/* 80110EDC 0010DCDC  40 82 00 0C */	bne .L_80110EE8
/* 80110EE0 0010DCE0  38 00 00 00 */	li r0, 0x0
/* 80110EE4 0010DCE4  B0 04 00 02 */	sth r0, 0x2(r4)
.L_80110EE8:
/* 80110EE8 0010DCE8  80 6D 06 50 */	lwz r3, lbl_805DD730@sda21(r0)
/* 80110EEC 0010DCEC  88 03 00 07 */	lbz r0, 0x7(r3)
/* 80110EF0 0010DCF0  7C 00 07 75 */	extsb. r0, r0
/* 80110EF4 0010DCF4  41 82 00 28 */	beq .L_80110F1C
/* 80110EF8 0010DCF8  7F 63 DB 78 */	mr r3, r27
/* 80110EFC 0010DCFC  4B FD D7 65 */	bl kar_greventgenerator_enter_finish_state
/* 80110F00 0010DD00  48 00 00 1C */	b .L_80110F1C
.L_80110F04:
/* 80110F04 0010DD04  80 0D 06 58 */	lwz r0, lbl_805DD738@sda21(r0)
/* 80110F08 0010DD08  2C 00 00 00 */	cmpwi r0, 0x0
/* 80110F0C 0010DD0C  40 82 00 10 */	bne .L_80110F1C
/* 80110F10 0010DD10  4B FD D7 51 */	bl kar_greventgenerator_enter_finish_state
/* 80110F14 0010DD14  38 00 00 01 */	li r0, 0x1
/* 80110F18 0010DD18  90 0D 06 58 */	stw r0, lbl_805DD738@sda21(r0)
.L_80110F1C:
/* 80110F1C 0010DD1C  39 61 00 A0 */	addi r11, r1, 0xa0
/* 80110F20 0010DD20  48 29 CC 7D */	bl _restgpr_26
/* 80110F24 0010DD24  80 01 00 A4 */	lwz r0, 0xa4(r1)
/* 80110F28 0010DD28  7C 08 03 A6 */	mtlr r0
/* 80110F2C 0010DD2C  38 21 00 A0 */	addi r1, r1, 0xa0
/* 80110F30 0010DD30  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_event_kind4e_update_spawn_pattern_rows

# .text:0x1608 | 0x80110F34 | size: 0x4
.fn fn_80110F34, global
/* 80110F34 0010DD34  4E 80 00 20 */	blr
.endfn fn_80110F34

# .text:0x160C | 0x80110F38 | size: 0x50
.fn kar_grcolosseum1_event_kind4e_cleanup_pattern_state, global
/* 80110F38 0010DD38  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80110F3C 0010DD3C  7C 08 02 A6 */	mflr r0
/* 80110F40 0010DD40  90 01 00 14 */	stw r0, 0x14(r1)
/* 80110F44 0010DD44  80 8D 06 50 */	lwz r4, lbl_805DD730@sda21(r0)
/* 80110F48 0010DD48  28 04 00 00 */	cmplwi r4, 0x0
/* 80110F4C 0010DD4C  41 82 00 10 */	beq .L_80110F5C
/* 80110F50 0010DD50  3C 60 80 55 */	lis r3, kar_grcolosseum1_kind4e_pattern_state_allocator@ha
/* 80110F54 0010DD54  38 63 78 38 */	addi r3, r3, kar_grcolosseum1_kind4e_pattern_state_allocator@l
/* 80110F58 0010DD58  48 30 72 DD */	bl HSD_ObjFree
.L_80110F5C:
/* 80110F5C 0010DD5C  38 00 00 00 */	li r0, 0x0
/* 80110F60 0010DD60  90 0D 06 50 */	stw r0, lbl_805DD730@sda21(r0)
/* 80110F64 0010DD64  90 0D 06 54 */	stw r0, lbl_805DD734@sda21(r0)
/* 80110F68 0010DD68  90 0D 06 58 */	stw r0, lbl_805DD738@sda21(r0)
/* 80110F6C 0010DD6C  48 14 32 1D */	bl fn_80254188
/* 80110F70 0010DD70  38 60 00 02 */	li r3, 0x2
/* 80110F74 0010DD74  4B FD C8 8D */	bl kar_grboxgenerator__near_800ed800
/* 80110F78 0010DD78  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80110F7C 0010DD7C  7C 08 03 A6 */	mtlr r0
/* 80110F80 0010DD80  38 21 00 10 */	addi r1, r1, 0x10
/* 80110F84 0010DD84  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_event_kind4e_cleanup_pattern_state

# .text:0x165C | 0x80110F88 | size: 0x68
.fn kar_grcolosseum1_event_mark_active_players_at_keyframe, global
/* 80110F88 0010DD88  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80110F8C 0010DD8C  7C 08 02 A6 */	mflr r0
/* 80110F90 0010DD90  90 01 00 14 */	stw r0, 0x14(r1)
/* 80110F94 0010DD94  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80110F98 0010DD98  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80110F9C 0010DD9C  4B FD D7 31 */	bl kar_greventgenerator_get_current_event_key_frame
/* 80110FA0 0010DDA0  3B C0 00 00 */	li r30, 0x0
/* 80110FA4 0010DDA4  7C 7F 1B 78 */	mr r31, r3
.L_80110FA8:
/* 80110FA8 0010DDA8  7F C3 F3 78 */	mr r3, r30
/* 80110FAC 0010DDAC  48 11 B8 AD */	bl kar_plclearcheckerlib__near_8022c858
/* 80110FB0 0010DDB0  2C 03 00 00 */	cmpwi r3, 0x0
/* 80110FB4 0010DDB4  41 82 00 0C */	beq .L_80110FC0
/* 80110FB8 0010DDB8  2C 03 00 01 */	cmpwi r3, 0x1
/* 80110FBC 0010DDBC  40 82 00 10 */	bne .L_80110FCC
.L_80110FC0:
/* 80110FC0 0010DDC0  7F C3 F3 78 */	mr r3, r30
/* 80110FC4 0010DDC4  7F E4 FB 78 */	mr r4, r31
/* 80110FC8 0010DDC8  48 11 C6 01 */	bl kar_plclearcheckerlib__near_8022d5c8
.L_80110FCC:
/* 80110FCC 0010DDCC  3B DE 00 01 */	addi r30, r30, 0x1
/* 80110FD0 0010DDD0  2C 1E 00 05 */	cmpwi r30, 0x5
/* 80110FD4 0010DDD4  41 80 FF D4 */	blt .L_80110FA8
/* 80110FD8 0010DDD8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80110FDC 0010DDDC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80110FE0 0010DDE0  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80110FE4 0010DDE4  7C 08 03 A6 */	mtlr r0
/* 80110FE8 0010DDE8  38 21 00 10 */	addi r1, r1, 0x10
/* 80110FEC 0010DDEC  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_event_mark_active_players_at_keyframe

# .text:0x16C4 | 0x80110FF0 | size: 0x80
.fn kar_grcolosseum1_event_clear_marked_players_after_keyframe, global
/* 80110FF0 0010DDF0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80110FF4 0010DDF4  7C 08 02 A6 */	mflr r0
/* 80110FF8 0010DDF8  90 01 00 14 */	stw r0, 0x14(r1)
/* 80110FFC 0010DDFC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80111000 0010DE00  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80111004 0010DE04  7C 7E 1B 78 */	mr r30, r3
/* 80111008 0010DE08  4B FD D6 C5 */	bl kar_greventgenerator_get_current_event_key_frame
/* 8011100C 0010DE0C  7C 7F 1B 78 */	mr r31, r3
/* 80111010 0010DE10  7F C3 F3 78 */	mr r3, r30
/* 80111014 0010DE14  4B FD D6 B1 */	bl kar_greventgenerator_get_state_elapsed_frames
/* 80111018 0010DE18  7C 03 F8 40 */	cmplw r3, r31
/* 8011101C 0010DE1C  41 80 00 3C */	blt .L_80111058
/* 80111020 0010DE20  3B E0 00 00 */	li r31, 0x0
.L_80111024:
/* 80111024 0010DE24  7F E3 FB 78 */	mr r3, r31
/* 80111028 0010DE28  48 11 B8 31 */	bl kar_plclearcheckerlib__near_8022c858
/* 8011102C 0010DE2C  2C 03 00 00 */	cmpwi r3, 0x0
/* 80111030 0010DE30  41 82 00 0C */	beq .L_8011103C
/* 80111034 0010DE34  2C 03 00 01 */	cmpwi r3, 0x1
/* 80111038 0010DE38  40 82 00 0C */	bne .L_80111044
.L_8011103C:
/* 8011103C 0010DE3C  7F E3 FB 78 */	mr r3, r31
/* 80111040 0010DE40  48 11 C5 E1 */	bl kar_plclearcheckerlib__near_8022d620
.L_80111044:
/* 80111044 0010DE44  3B FF 00 01 */	addi r31, r31, 0x1
/* 80111048 0010DE48  2C 1F 00 05 */	cmpwi r31, 0x5
/* 8011104C 0010DE4C  41 80 FF D8 */	blt .L_80111024
/* 80111050 0010DE50  7F C3 F3 78 */	mr r3, r30
/* 80111054 0010DE54  4B FD D6 0D */	bl kar_greventgenerator_enter_finish_state
.L_80111058:
/* 80111058 0010DE58  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011105C 0010DE5C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80111060 0010DE60  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80111064 0010DE64  7C 08 03 A6 */	mtlr r0
/* 80111068 0010DE68  38 21 00 10 */	addi r1, r1, 0x10
/* 8011106C 0010DE6C  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_event_clear_marked_players_after_keyframe

# .text:0x1744 | 0x80111070 | size: 0x4
.fn fn_80111070, global
/* 80111070 0010DE70  4E 80 00 20 */	blr
.endfn fn_80111070

# .text:0x1748 | 0x80111074 | size: 0x4
.fn fn_80111074, global
/* 80111074 0010DE74  4E 80 00 20 */	blr
.endfn fn_80111074

# .text:0x174C | 0x80111078 | size: 0xA4
.fn kar_grcolosseum1_event_create_random_secondary_kind20_catchzones, global
/* 80111078 0010DE78  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8011107C 0010DE7C  7C 08 02 A6 */	mflr r0
/* 80111080 0010DE80  90 01 00 34 */	stw r0, 0x34(r1)
/* 80111084 0010DE84  39 61 00 30 */	addi r11, r1, 0x30
/* 80111088 0010DE88  48 29 CA C5 */	bl _savegpr_25
/* 8011108C 0010DE8C  7C 79 1B 78 */	mr r25, r3
/* 80111090 0010DE90  4B FD D6 AD */	bl kar_greventgenerator_get_current_event_param
/* 80111094 0010DE94  7C 7D 1B 78 */	mr r29, r3
/* 80111098 0010DE98  7F 23 CB 78 */	mr r3, r25
/* 8011109C 0010DE9C  4B FD D6 51 */	bl kar_greventgenerator_get_current_eventpos_start
/* 801110A0 0010DEA0  7C 7E 1B 78 */	mr r30, r3
/* 801110A4 0010DEA4  7F 23 CB 78 */	mr r3, r25
/* 801110A8 0010DEA8  4B FD D6 61 */	bl kar_greventgenerator_get_current_eventpos_count
/* 801110AC 0010DEAC  80 9D 00 04 */	lwz r4, 0x4(r29)
/* 801110B0 0010DEB0  7C 7F 1B 78 */	mr r31, r3
/* 801110B4 0010DEB4  4B FE 6D BD */	bl kar_gryakulib_random_choose_k_of_n_mask
/* 801110B8 0010DEB8  3B 60 00 00 */	li r27, 0x0
/* 801110BC 0010DEBC  7C 7A 1B 78 */	mr r26, r3
/* 801110C0 0010DEC0  3B 80 00 00 */	li r28, 0x0
/* 801110C4 0010DEC4  48 00 00 30 */	b .L_801110F4
.L_801110C8:
/* 801110C8 0010DEC8  57 40 07 FF */	clrlwi. r0, r26, 31
/* 801110CC 0010DECC  41 82 00 1C */	beq .L_801110E8
/* 801110D0 0010DED0  80 DD 00 08 */	lwz r6, 0x8(r29)
/* 801110D4 0010DED4  7F 23 CB 78 */	mr r3, r25
/* 801110D8 0010DED8  80 9D 00 00 */	lwz r4, 0x0(r29)
/* 801110DC 0010DEDC  7C BE DA 14 */	add r5, r30, r27
/* 801110E0 0010DEE0  7C 26 E4 2E */	lfsx f1, r6, r28
/* 801110E4 0010DEE4  4B FE 99 B5 */	bl kar_gryakucatchzone_create_secondary_kind20_event_yaku
.L_801110E8:
/* 801110E8 0010DEE8  57 5A F8 7E */	srwi r26, r26, 1
/* 801110EC 0010DEEC  3B 9C 00 04 */	addi r28, r28, 0x4
/* 801110F0 0010DEF0  3B 7B 00 01 */	addi r27, r27, 0x1
.L_801110F4:
/* 801110F4 0010DEF4  7C 1B F8 00 */	cmpw r27, r31
/* 801110F8 0010DEF8  41 80 FF D0 */	blt .L_801110C8
/* 801110FC 0010DEFC  7F 23 CB 78 */	mr r3, r25
/* 80111100 0010DF00  4B FD D5 61 */	bl kar_greventgenerator_enter_finish_state
/* 80111104 0010DF04  39 61 00 30 */	addi r11, r1, 0x30
/* 80111108 0010DF08  48 29 CA 91 */	bl _restgpr_25
/* 8011110C 0010DF0C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80111110 0010DF10  7C 08 03 A6 */	mtlr r0
/* 80111114 0010DF14  38 21 00 30 */	addi r1, r1, 0x30
/* 80111118 0010DF18  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_event_create_random_secondary_kind20_catchzones

# .text:0x17F0 | 0x8011111C | size: 0xF0
.fn kar_grcolosseum1_event_start_kind40_pillar_and_break_targets, global
/* 8011111C 0010DF1C  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 80111120 0010DF20  7C 08 02 A6 */	mflr r0
/* 80111124 0010DF24  90 01 00 44 */	stw r0, 0x44(r1)
/* 80111128 0010DF28  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 8011112C 0010DF2C  93 C1 00 38 */	stw r30, 0x38(r1)
/* 80111130 0010DF30  93 A1 00 34 */	stw r29, 0x34(r1)
/* 80111134 0010DF34  93 81 00 30 */	stw r28, 0x30(r1)
/* 80111138 0010DF38  7C 7C 1B 78 */	mr r28, r3
/* 8011113C 0010DF3C  4B FD D6 01 */	bl kar_greventgenerator_get_current_event_param
/* 80111140 0010DF40  7C 7F 1B 78 */	mr r31, r3
/* 80111144 0010DF44  7F 83 E3 78 */	mr r3, r28
/* 80111148 0010DF48  4B FD D5 C1 */	bl kar_greventgenerator_get_current_eventpos_count
/* 8011114C 0010DF4C  7F 83 E3 78 */	mr r3, r28
/* 80111150 0010DF50  38 81 00 20 */	addi r4, r1, 0x20
/* 80111154 0010DF54  38 A1 00 14 */	addi r5, r1, 0x14
/* 80111158 0010DF58  38 C1 00 08 */	addi r6, r1, 0x8
/* 8011115C 0010DF5C  48 00 00 B1 */	bl kar_greventrock_choose_eventpos_vectors_far_from_players
/* 80111160 0010DF60  38 00 00 00 */	li r0, 0x0
/* 80111164 0010DF64  7C 7D 1B 78 */	mr r29, r3
/* 80111168 0010DF68  90 0D 06 60 */	stw r0, lbl_805DD740@sda21(r0)
/* 8011116C 0010DF6C  80 6D 12 50 */	lwz r3, lbl_805DE330@sda21(r0)
/* 80111170 0010DF70  83 C3 00 20 */	lwz r30, 0x20(r3)
/* 80111174 0010DF74  48 00 00 20 */	b .L_80111194
.L_80111178:
/* 80111178 0010DF78  7F C3 F3 78 */	mr r3, r30
/* 8011117C 0010DF7C  4B FE 68 E9 */	bl kar_gryakulib_get_yaku_data_checked
/* 80111180 0010DF80  2C 03 00 28 */	cmpwi r3, 0x28
/* 80111184 0010DF84  40 82 00 0C */	bne .L_80111190
/* 80111188 0010DF88  93 CD 06 60 */	stw r30, lbl_805DD740@sda21(r0)
/* 8011118C 0010DF8C  48 00 00 10 */	b .L_8011119C
.L_80111190:
/* 80111190 0010DF90  83 DE 00 0C */	lwz r30, 0xc(r30)
.L_80111194:
/* 80111194 0010DF94  28 1E 00 00 */	cmplwi r30, 0x0
/* 80111198 0010DF98  40 82 FF E0 */	bne .L_80111178
.L_8011119C:
/* 8011119C 0010DF9C  80 0D 06 60 */	lwz r0, lbl_805DD740@sda21(r0)
/* 801111A0 0010DFA0  28 00 00 00 */	cmplwi r0, 0x0
/* 801111A4 0010DFA4  41 82 00 18 */	beq .L_801111BC
/* 801111A8 0010DFA8  7F C3 F3 78 */	mr r3, r30
/* 801111AC 0010DFAC  7F 84 E3 78 */	mr r4, r28
/* 801111B0 0010DFB0  7F A5 EB 78 */	mr r5, r29
/* 801111B4 0010DFB4  4B FF 07 45 */	bl kar_gryakupillar_reset_kind40_colosseum_pillar_eventpos
/* 801111B8 0010DFB8  48 00 00 18 */	b .L_801111D0
.L_801111BC:
/* 801111BC 0010DFBC  80 9F 00 00 */	lwz r4, 0x0(r31)
/* 801111C0 0010DFC0  7F 83 E3 78 */	mr r3, r28
/* 801111C4 0010DFC4  7F A5 EB 78 */	mr r5, r29
/* 801111C8 0010DFC8  4B FF 06 55 */	bl kar_gryakupillar_create_secondary_kind40_colosseum_pillar
/* 801111CC 0010DFCC  90 6D 06 60 */	stw r3, lbl_805DD740@sda21(r0)
.L_801111D0:
/* 801111D0 0010DFD0  C0 3F 00 0C */	lfs f1, 0xc(r31)
/* 801111D4 0010DFD4  38 61 00 20 */	addi r3, r1, 0x20
/* 801111D8 0010DFD8  4B FE 6B 8D */	bl kar_gryakulib_dispatch_city1_stage_helper
/* 801111DC 0010DFDC  38 61 00 20 */	addi r3, r1, 0x20
/* 801111E0 0010DFE0  48 00 2E 31 */	bl fn_80114010
/* 801111E4 0010DFE4  38 60 00 03 */	li r3, 0x3
/* 801111E8 0010DFE8  4B FD C5 9D */	bl kar_grboxgenerator__near_800ed784
/* 801111EC 0010DFEC  80 01 00 44 */	lwz r0, 0x44(r1)
/* 801111F0 0010DFF0  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 801111F4 0010DFF4  83 C1 00 38 */	lwz r30, 0x38(r1)
/* 801111F8 0010DFF8  83 A1 00 34 */	lwz r29, 0x34(r1)
/* 801111FC 0010DFFC  83 81 00 30 */	lwz r28, 0x30(r1)
/* 80111200 0010E000  7C 08 03 A6 */	mtlr r0
/* 80111204 0010E004  38 21 00 40 */	addi r1, r1, 0x40
/* 80111208 0010E008  4E 80 00 20 */	blr
.endfn kar_grcolosseum1_event_start_kind40_pillar_and_break_targets

# 0x80489E60..0x80489EE0 | size: 0x80
.rodata
.balign 8

# .rodata:0x0 | 0x80489E60 | size: 0xC
.obj lbl_80489E60, global
	.4byte 0x00000000
	.4byte 0x41700000
	.4byte 0x00000000
.endobj lbl_80489E60

# .rodata:0xC | 0x80489E6C | size: 0xC
.obj lbl_80489E6C, global
	.4byte 0x00000000
	.4byte 0x41700000
	.4byte 0x00000000
.endobj lbl_80489E6C

# .rodata:0x18 | 0x80489E78 | size: 0x10
.obj lbl_80489E78, global
	.4byte 0x2E87FF00
	.4byte 0x00CF0000
	.4byte 0xFFC30000
	.4byte 0xFF000000
.endobj lbl_80489E78

# .rodata:0x28 | 0x80489E88 | size: 0x10
.obj lbl_80489E88, global
	.4byte 0x00000000
	.4byte 0x41700000
	.4byte 0x42340000
	.4byte 0x00000000
.endobj lbl_80489E88

# .rodata:0x38 | 0x80489E98 | size: 0xC
.obj lbl_80489E98, global
	.4byte 0x3F933333
	.4byte 0x3F933333
	.4byte 0x3F933333
.endobj lbl_80489E98

# .rodata:0x44 | 0x80489EA4 | size: 0xC
.obj lbl_80489EA4, global
	.4byte 0x3F800000
	.4byte 0x3F800000
	.4byte 0x3F800000
.endobj lbl_80489EA4

# .rodata:0x50 | 0x80489EB0 | size: 0xC
.obj lbl_80489EB0, global
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0xBF800000
.endobj lbl_80489EB0

# .rodata:0x5C | 0x80489EBC | size: 0xC
.obj lbl_80489EBC, global
	.4byte 0xBF800000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_80489EBC

# .rodata:0x68 | 0x80489EC8 | size: 0xC
.obj lbl_80489EC8, global
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0xBF800000
.endobj lbl_80489EC8

# .rodata:0x74 | 0x80489ED4 | size: 0xC
.obj lbl_80489ED4, global
	.4byte 0xBF800000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_80489ED4

# 0x804A78A8..0x804A79A0 | size: 0xF8
.data
.balign 8

# .data:0x0 | 0x804A78A8 | size: 0xC
.obj kar_grcolosseum1_main_callback_table, global
	.4byte kar_grcolosseum1_init_course_dependent_common_setup_list
	.4byte kar_grcolosseum1_create_course19_kind23_breakhouse_pair
	.4byte 0x00000000
.endobj kar_grcolosseum1_main_callback_table

# .data:0xC | 0x804A78B4 | size: 0xF
.obj kar_src_grcolosseum1_c, global
	.string "grcolosseum1.c"
.endobj kar_src_grcolosseum1_c

# .data:0x1B | 0x804A78C3 | size: 0x5
.obj gap_07_804A78C3_data, global
.hidden gap_07_804A78C3_data
	.4byte 0x00000000
	.byte 0x00
.endobj gap_07_804A78C3_data

# .data:0x20 | 0x804A78C8 | size: 0x10
.obj kar_grcolosseum1_effect_9c47_callback_table, global
	.4byte kar_grcolosseum1_request_effect_9c47_at_configured_joint
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj kar_grcolosseum1_effect_9c47_callback_table

# .data:0x30 | 0x804A78D8 | size: 0x10
.obj lbl_804A78D8, global
	.4byte fn_8010FAA8
	.4byte fn_8010FAAC
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A78D8

# .data:0x40 | 0x804A78E8 | size: 0x10
.obj lbl_804A78E8, global
	.4byte fn_8010FAB0
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A78E8

# .data:0x50 | 0x804A78F8 | size: 0x10
.obj kar_grcolosseum1_pointstrike_callback_table, global
	.4byte fn_8010FAB4
	.4byte kar_grcolosseum1_init_pointstrike_panel_handles
	.4byte 0x00000000
	.4byte 0x00000000
.endobj kar_grcolosseum1_pointstrike_callback_table

# .data:0x60 | 0x804A7908 | size: 0x10
.obj lbl_804A7908, global
	.4byte fn_8010FADC
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A7908

# .data:0x70 | 0x804A7918 | size: 0x10
.obj kar_grcolosseum1_risingcube_controller_callback_table, global
	.4byte kar_grcolosseum1_init_risingcube_controller_switch_group
	.4byte kar_grcolosseum1_create_risingcube_pair_and_controller
	.4byte 0x00000000
	.4byte 0x00000000
.endobj kar_grcolosseum1_risingcube_controller_callback_table

# .data:0x80 | 0x804A7928 | size: 0x10
.obj lbl_804A7928, global
	.4byte fn_8010FB84
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A7928

# .data:0x90 | 0x804A7938 | size: 0x10
.obj lbl_804A7938, global
	.4byte fn_8010FB88
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A7938

# .data:0xA0 | 0x804A7948 | size: 0x10
.obj lbl_804A7948, global
	.4byte fn_8010FB8C
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A7948

# .data:0xB0 | 0x804A7958 | size: 0x10
.obj lbl_804A7958, global
	.4byte fn_8010FB90
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A7958

# .data:0xC0 | 0x804A7968 | size: 0x10
.obj kar_grcolosseum1_arealight_recovery_callback_table, global
	.4byte kar_grcolosseum1_init_two_area_light_users
	.4byte kar_grcolosseum1_create_kind41_recovery_joint_index0
	.4byte 0x00000000
	.4byte 0x00000000
.endobj kar_grcolosseum1_arealight_recovery_callback_table

# .data:0xD0 | 0x804A7978 | size: 0xC
.obj kar_grcolosseum1_airflow_and_yaku_callback_table, global
	.4byte kar_grcolosseum1_init_airflow_slots_and_switch_group
	.4byte kar_grcolosseum1_create_stage_colosseum_yaku_objects
	.4byte fn_801100E4
.endobj kar_grcolosseum1_airflow_and_yaku_callback_table

# .data:0xDC | 0x804A7984 | size: 0x1C
.obj kar_grcolosseum1_airflow_switch_callback_table, global
	.4byte kar_grcolosseum1_switch0_trigger_risingcube_by_stage_index
	.4byte kar_grcolosseum1_switch1_trigger_risingcube_by_stage_index
	.4byte fn_80110148
	.4byte fn_8011014C
	.4byte fn_80110150
	.4byte kar_grcolosseum1_switch5_trigger_lasergate_ctrl_open_by_stage_index
	.4byte 0x00000000
.endobj kar_grcolosseum1_airflow_switch_callback_table

# 0x80557820..0x80557868 | size: 0x48
.section .bss, "wa", @nobits
.balign 8

# .bss:0x0 | 0x80557820 | size: 0x18
.obj kar_grcolosseum1_event_position_order_buffer, global
	.skip 0x18
.endobj kar_grcolosseum1_event_position_order_buffer

# .bss:0x18 | 0x80557838 | size: 0x30
.obj kar_grcolosseum1_kind4e_pattern_state_allocator, global
	.skip 0x30
.endobj kar_grcolosseum1_kind4e_pattern_state_allocator

# 0x805D6378..0x805D6DD0 | size: 0xA58
.section .sdata, "wa"
.balign 8

# .sdata:0x0 | 0x805D6378 | size: 0x2
.obj lbl_805D6378, global
	.string "0"
.endobj lbl_805D6378

# .sdata:0x2 | 0x805D637A | size: 0x6
.obj gap_09_805D637A_sdata, global
.hidden gap_09_805D637A_sdata
	.4byte 0x00000000
	.2byte 0x0000
.endobj gap_09_805D637A_sdata

# .sdata:0x8 | 0x805D6380 | size: 0x8
.obj lbl_805D6380, global
	.4byte kar_grcolosseum1_update_risingcube_controller_targets_by_stage_index
	.4byte 0x00000000
.endobj lbl_805D6380

# .sdata:0x10 | 0x805D6388 | size: 0x7
.obj kar_srcfile_jobj_h_805d6388, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6388

# .sdata:0x17 | 0x805D638F | size: 0x1
.obj gap_09_805D638F_sdata, global
.hidden gap_09_805D638F_sdata
	.byte 0x00
.endobj gap_09_805D638F_sdata

# .sdata:0x18 | 0x805D6390 | size: 0x5
.obj lbl_805D6390, global
	.string "jobj"
.endobj lbl_805D6390

# .sdata:0x1D | 0x805D6395 | size: 0x3
.obj gap_09_805D6395_sdata, global
.hidden gap_09_805D6395_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6395_sdata

# .sdata:0x20 | 0x805D6398 | size: 0x8
.obj kar_srcfile_iflib_c_805d6398, global
	.string "iflib.c"
.endobj kar_srcfile_iflib_c_805d6398

# .sdata:0x28 | 0x805D63A0 | size: 0x2
.obj lbl_805D63A0, global
	.string "0"
.endobj lbl_805D63A0

# .sdata:0x2A | 0x805D63A2 | size: 0x6
.obj gap_09_805D63A2_sdata, global
.hidden gap_09_805D63A2_sdata
	.4byte 0x00000000
	.2byte 0x0000
.endobj gap_09_805D63A2_sdata

# .sdata:0x30 | 0x805D63A8 | size: 0x7
.obj kar_srcfile_jobj_h_805d63a8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d63a8

# .sdata:0x37 | 0x805D63AF | size: 0x1
.obj gap_09_805D63AF_sdata, global
.hidden gap_09_805D63AF_sdata
	.byte 0x00
.endobj gap_09_805D63AF_sdata

# .sdata:0x38 | 0x805D63B0 | size: 0x5
.obj lbl_805D63B0, global
	.string "jobj"
.endobj lbl_805D63B0

# .sdata:0x3D | 0x805D63B5 | size: 0x3
.obj gap_09_805D63B5_sdata, global
.hidden gap_09_805D63B5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D63B5_sdata

# .sdata:0x40 | 0x805D63B8 | size: 0x7
.obj kar_srcfile_jobj_h_805d63b8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d63b8

# .sdata:0x47 | 0x805D63BF | size: 0x1
.obj gap_09_805D63BF_sdata, global
.hidden gap_09_805D63BF_sdata
	.byte 0x00
.endobj gap_09_805D63BF_sdata

# .sdata:0x48 | 0x805D63C0 | size: 0x5
.obj lbl_805D63C0, global
	.string "jobj"
.endobj lbl_805D63C0

# .sdata:0x4D | 0x805D63C5 | size: 0x3
.obj gap_09_805D63C5_sdata, global
.hidden gap_09_805D63C5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D63C5_sdata

# .sdata:0x50 | 0x805D63C8 | size: 0x7
.obj kar_srcfile_jobj_h_805d63c8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d63c8

# .sdata:0x57 | 0x805D63CF | size: 0x1
.obj gap_09_805D63CF_sdata, global
.hidden gap_09_805D63CF_sdata
	.byte 0x00
.endobj gap_09_805D63CF_sdata

# .sdata:0x58 | 0x805D63D0 | size: 0x5
.obj lbl_805D63D0, global
	.string "jobj"
.endobj lbl_805D63D0

# .sdata:0x5D | 0x805D63D5 | size: 0x3
.obj gap_09_805D63D5_sdata, global
.hidden gap_09_805D63D5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D63D5_sdata

# .sdata:0x60 | 0x805D63D8 | size: 0x7
.obj kar_srcfile_jobj_h_805d63d8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d63d8

# .sdata:0x67 | 0x805D63DF | size: 0x1
.obj gap_09_805D63DF_sdata, global
.hidden gap_09_805D63DF_sdata
	.byte 0x00
.endobj gap_09_805D63DF_sdata

# .sdata:0x68 | 0x805D63E0 | size: 0x5
.obj lbl_805D63E0, global
	.string "jobj"
.endobj lbl_805D63E0

# .sdata:0x6D | 0x805D63E5 | size: 0x3
.obj gap_09_805D63E5_sdata, global
.hidden gap_09_805D63E5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D63E5_sdata

# .sdata:0x70 | 0x805D63E8 | size: 0x7
.obj kar_srcfile_jobj_h_805d63e8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d63e8

# .sdata:0x77 | 0x805D63EF | size: 0x1
.obj gap_09_805D63EF_sdata, global
.hidden gap_09_805D63EF_sdata
	.byte 0x00
.endobj gap_09_805D63EF_sdata

# .sdata:0x78 | 0x805D63F0 | size: 0x5
.obj lbl_805D63F0, global
	.string "jobj"
.endobj lbl_805D63F0

# .sdata:0x7D | 0x805D63F5 | size: 0x3
.obj gap_09_805D63F5_sdata, global
.hidden gap_09_805D63F5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D63F5_sdata

# .sdata:0x80 | 0x805D63F8 | size: 0x7
.obj kar_srcfile_jobj_h_805d63f8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d63f8

# .sdata:0x87 | 0x805D63FF | size: 0x1
.obj gap_09_805D63FF_sdata, global
.hidden gap_09_805D63FF_sdata
	.byte 0x00
.endobj gap_09_805D63FF_sdata

# .sdata:0x88 | 0x805D6400 | size: 0x5
.obj lbl_805D6400, global
	.string "jobj"
.endobj lbl_805D6400

# .sdata:0x8D | 0x805D6405 | size: 0x3
.obj gap_09_805D6405_sdata, global
.hidden gap_09_805D6405_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6405_sdata

# .sdata:0x90 | 0x805D6408 | size: 0x7
.obj kar_srcfile_jobj_h_805d6408, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6408

# .sdata:0x97 | 0x805D640F | size: 0x1
.obj gap_09_805D640F_sdata, global
.hidden gap_09_805D640F_sdata
	.byte 0x00
.endobj gap_09_805D640F_sdata

# .sdata:0x98 | 0x805D6410 | size: 0x5
.obj lbl_805D6410, global
	.string "jobj"
.endobj lbl_805D6410

# .sdata:0x9D | 0x805D6415 | size: 0x3
.obj gap_09_805D6415_sdata, global
.hidden gap_09_805D6415_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6415_sdata

# .sdata:0xA0 | 0x805D6418 | size: 0x7
.obj kar_srcfile_jobj_h_805d6418, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6418

# .sdata:0xA7 | 0x805D641F | size: 0x1
.obj gap_09_805D641F_sdata, global
.hidden gap_09_805D641F_sdata
	.byte 0x00
.endobj gap_09_805D641F_sdata

# .sdata:0xA8 | 0x805D6420 | size: 0x5
.obj lbl_805D6420, global
	.string "jobj"
.endobj lbl_805D6420

# .sdata:0xAD | 0x805D6425 | size: 0x3
.obj gap_09_805D6425_sdata, global
.hidden gap_09_805D6425_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6425_sdata

# .sdata:0xB0 | 0x805D6428 | size: 0x7
.obj kar_srcfile_jobj_h_805d6428, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6428

# .sdata:0xB7 | 0x805D642F | size: 0x1
.obj gap_09_805D642F_sdata, global
.hidden gap_09_805D642F_sdata
	.byte 0x00
.endobj gap_09_805D642F_sdata

# .sdata:0xB8 | 0x805D6430 | size: 0x5
.obj lbl_805D6430, global
	.string "jobj"
.endobj lbl_805D6430

# .sdata:0xBD | 0x805D6435 | size: 0x3
.obj gap_09_805D6435_sdata, global
.hidden gap_09_805D6435_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6435_sdata

# .sdata:0xC0 | 0x805D6438 | size: 0x7
.obj kar_srcfile_jobj_h_805d6438, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6438

# .sdata:0xC7 | 0x805D643F | size: 0x1
.obj gap_09_805D643F_sdata, global
.hidden gap_09_805D643F_sdata
	.byte 0x00
.endobj gap_09_805D643F_sdata

# .sdata:0xC8 | 0x805D6440 | size: 0x5
.obj lbl_805D6440, global
	.string "jobj"
.endobj lbl_805D6440

# .sdata:0xCD | 0x805D6445 | size: 0x3
.obj gap_09_805D6445_sdata, global
.hidden gap_09_805D6445_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6445_sdata

# .sdata:0xD0 | 0x805D6448 | size: 0x7
.obj kar_srcfile_jobj_h_805d6448, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6448

# .sdata:0xD7 | 0x805D644F | size: 0x1
.obj gap_09_805D644F_sdata, global
.hidden gap_09_805D644F_sdata
	.byte 0x00
.endobj gap_09_805D644F_sdata

# .sdata:0xD8 | 0x805D6450 | size: 0x5
.obj lbl_805D6450, global
	.string "jobj"
.endobj lbl_805D6450

# .sdata:0xDD | 0x805D6455 | size: 0x3
.obj gap_09_805D6455_sdata, global
.hidden gap_09_805D6455_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6455_sdata

# .sdata:0xE0 | 0x805D6458 | size: 0x7
.obj kar_srcfile_jobj_h_805d6458, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6458

# .sdata:0xE7 | 0x805D645F | size: 0x1
.obj gap_09_805D645F_sdata, global
.hidden gap_09_805D645F_sdata
	.byte 0x00
.endobj gap_09_805D645F_sdata

# .sdata:0xE8 | 0x805D6460 | size: 0x5
.obj lbl_805D6460, global
	.string "jobj"
.endobj lbl_805D6460

# .sdata:0xED | 0x805D6465 | size: 0x3
.obj gap_09_805D6465_sdata, global
.hidden gap_09_805D6465_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6465_sdata

# .sdata:0xF0 | 0x805D6468 | size: 0x7
.obj kar_srcfile_jobj_h_805d6468, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6468

# .sdata:0xF7 | 0x805D646F | size: 0x1
.obj gap_09_805D646F_sdata, global
.hidden gap_09_805D646F_sdata
	.byte 0x00
.endobj gap_09_805D646F_sdata

# .sdata:0xF8 | 0x805D6470 | size: 0x5
.obj lbl_805D6470, global
	.string "jobj"
.endobj lbl_805D6470

# .sdata:0xFD | 0x805D6475 | size: 0x3
.obj gap_09_805D6475_sdata, global
.hidden gap_09_805D6475_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6475_sdata

# .sdata:0x100 | 0x805D6478 | size: 0x7
.obj kar_srcfile_jobj_h_805d6478, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6478

# .sdata:0x107 | 0x805D647F | size: 0x1
.obj gap_09_805D647F_sdata, global
.hidden gap_09_805D647F_sdata
	.byte 0x00
.endobj gap_09_805D647F_sdata

# .sdata:0x108 | 0x805D6480 | size: 0x5
.obj lbl_805D6480, global
	.string "jobj"
.endobj lbl_805D6480

# .sdata:0x10D | 0x805D6485 | size: 0x3
.obj gap_09_805D6485_sdata, global
.hidden gap_09_805D6485_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6485_sdata

# .sdata:0x110 | 0x805D6488 | size: 0x7
.obj kar_srcfile_jobj_h_805d6488, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6488

# .sdata:0x117 | 0x805D648F | size: 0x1
.obj gap_09_805D648F_sdata, global
.hidden gap_09_805D648F_sdata
	.byte 0x00
.endobj gap_09_805D648F_sdata

# .sdata:0x118 | 0x805D6490 | size: 0x5
.obj lbl_805D6490, global
	.string "jobj"
.endobj lbl_805D6490

# .sdata:0x11D | 0x805D6495 | size: 0x3
.obj gap_09_805D6495_sdata, global
.hidden gap_09_805D6495_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6495_sdata

# .sdata:0x120 | 0x805D6498 | size: 0x7
.obj kar_srcfile_jobj_h_805d6498, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6498

# .sdata:0x127 | 0x805D649F | size: 0x1
.obj gap_09_805D649F_sdata, global
.hidden gap_09_805D649F_sdata
	.byte 0x00
.endobj gap_09_805D649F_sdata

# .sdata:0x128 | 0x805D64A0 | size: 0x5
.obj lbl_805D64A0, global
	.string "jobj"
.endobj lbl_805D64A0

# .sdata:0x12D | 0x805D64A5 | size: 0x3
.obj gap_09_805D64A5_sdata, global
.hidden gap_09_805D64A5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D64A5_sdata

# .sdata:0x130 | 0x805D64A8 | size: 0x7
.obj kar_srcfile_jobj_h_805d64a8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d64a8

# .sdata:0x137 | 0x805D64AF | size: 0x1
.obj gap_09_805D64AF_sdata, global
.hidden gap_09_805D64AF_sdata
	.byte 0x00
.endobj gap_09_805D64AF_sdata

# .sdata:0x138 | 0x805D64B0 | size: 0x5
.obj lbl_805D64B0, global
	.string "jobj"
.endobj lbl_805D64B0

# .sdata:0x13D | 0x805D64B5 | size: 0x3
.obj gap_09_805D64B5_sdata, global
.hidden gap_09_805D64B5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D64B5_sdata

# .sdata:0x140 | 0x805D64B8 | size: 0x7
.obj kar_srcfile_jobj_h_805d64b8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d64b8

# .sdata:0x147 | 0x805D64BF | size: 0x1
.obj gap_09_805D64BF_sdata, global
.hidden gap_09_805D64BF_sdata
	.byte 0x00
.endobj gap_09_805D64BF_sdata

# .sdata:0x148 | 0x805D64C0 | size: 0x5
.obj lbl_805D64C0, global
	.string "jobj"
.endobj lbl_805D64C0

# .sdata:0x14D | 0x805D64C5 | size: 0x3
.obj gap_09_805D64C5_sdata, global
.hidden gap_09_805D64C5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D64C5_sdata

# .sdata:0x150 | 0x805D64C8 | size: 0x7
.obj kar_srcfile_jobj_h_805d64c8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d64c8

# .sdata:0x157 | 0x805D64CF | size: 0x1
.obj gap_09_805D64CF_sdata, global
.hidden gap_09_805D64CF_sdata
	.byte 0x00
.endobj gap_09_805D64CF_sdata

# .sdata:0x158 | 0x805D64D0 | size: 0x5
.obj lbl_805D64D0, global
	.string "jobj"
.endobj lbl_805D64D0

# .sdata:0x15D | 0x805D64D5 | size: 0x3
.obj gap_09_805D64D5_sdata, global
.hidden gap_09_805D64D5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D64D5_sdata

# .sdata:0x160 | 0x805D64D8 | size: 0x7
.obj kar_srcfile_jobj_h_805d64d8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d64d8

# .sdata:0x167 | 0x805D64DF | size: 0x1
.obj gap_09_805D64DF_sdata, global
.hidden gap_09_805D64DF_sdata
	.byte 0x00
.endobj gap_09_805D64DF_sdata

# .sdata:0x168 | 0x805D64E0 | size: 0x5
.obj lbl_805D64E0, global
	.string "jobj"
.endobj lbl_805D64E0

# .sdata:0x16D | 0x805D64E5 | size: 0x3
.obj gap_09_805D64E5_sdata, global
.hidden gap_09_805D64E5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D64E5_sdata

# .sdata:0x170 | 0x805D64E8 | size: 0x7
.obj kar_srcfile_jobj_h_805d64e8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d64e8

# .sdata:0x177 | 0x805D64EF | size: 0x1
.obj gap_09_805D64EF_sdata, global
.hidden gap_09_805D64EF_sdata
	.byte 0x00
.endobj gap_09_805D64EF_sdata

# .sdata:0x178 | 0x805D64F0 | size: 0x5
.obj lbl_805D64F0, global
	.string "jobj"
.endobj lbl_805D64F0

# .sdata:0x17D | 0x805D64F5 | size: 0x3
.obj gap_09_805D64F5_sdata, global
.hidden gap_09_805D64F5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D64F5_sdata

# .sdata:0x180 | 0x805D64F8 | size: 0x7
.obj kar_srcfile_jobj_h_805d64f8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d64f8

# .sdata:0x187 | 0x805D64FF | size: 0x1
.obj gap_09_805D64FF_sdata, global
.hidden gap_09_805D64FF_sdata
	.byte 0x00
.endobj gap_09_805D64FF_sdata

# .sdata:0x188 | 0x805D6500 | size: 0x5
.obj lbl_805D6500, global
	.string "jobj"
.endobj lbl_805D6500

# .sdata:0x18D | 0x805D6505 | size: 0x3
.obj gap_09_805D6505_sdata, global
.hidden gap_09_805D6505_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6505_sdata

# .sdata:0x190 | 0x805D6508 | size: 0x7
.obj kar_srcfile_jobj_h_805d6508, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6508

# .sdata:0x197 | 0x805D650F | size: 0x1
.obj gap_09_805D650F_sdata, global
.hidden gap_09_805D650F_sdata
	.byte 0x00
.endobj gap_09_805D650F_sdata

# .sdata:0x198 | 0x805D6510 | size: 0x5
.obj lbl_805D6510, global
	.string "jobj"
.endobj lbl_805D6510

# .sdata:0x19D | 0x805D6515 | size: 0x3
.obj gap_09_805D6515_sdata, global
.hidden gap_09_805D6515_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6515_sdata

# .sdata:0x1A0 | 0x805D6518 | size: 0x7
.obj kar_srcfile_jobj_h_805d6518, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6518

# .sdata:0x1A7 | 0x805D651F | size: 0x1
.obj gap_09_805D651F_sdata, global
.hidden gap_09_805D651F_sdata
	.byte 0x00
.endobj gap_09_805D651F_sdata

# .sdata:0x1A8 | 0x805D6520 | size: 0x5
.obj lbl_805D6520, global
	.string "jobj"
.endobj lbl_805D6520

# .sdata:0x1AD | 0x805D6525 | size: 0x3
.obj gap_09_805D6525_sdata, global
.hidden gap_09_805D6525_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6525_sdata

# .sdata:0x1B0 | 0x805D6528 | size: 0x7
.obj kar_srcfile_jobj_h_805d6528, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6528

# .sdata:0x1B7 | 0x805D652F | size: 0x1
.obj gap_09_805D652F_sdata, global
.hidden gap_09_805D652F_sdata
	.byte 0x00
.endobj gap_09_805D652F_sdata

# .sdata:0x1B8 | 0x805D6530 | size: 0x5
.obj lbl_805D6530, global
	.string "jobj"
.endobj lbl_805D6530

# .sdata:0x1BD | 0x805D6535 | size: 0x3
.obj gap_09_805D6535_sdata, global
.hidden gap_09_805D6535_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6535_sdata

# .sdata:0x1C0 | 0x805D6538 | size: 0x7
.obj kar_srcfile_jobj_h_805d6538, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6538

# .sdata:0x1C7 | 0x805D653F | size: 0x1
.obj gap_09_805D653F_sdata, global
.hidden gap_09_805D653F_sdata
	.byte 0x00
.endobj gap_09_805D653F_sdata

# .sdata:0x1C8 | 0x805D6540 | size: 0x5
.obj lbl_805D6540, global
	.string "jobj"
.endobj lbl_805D6540

# .sdata:0x1CD | 0x805D6545 | size: 0x3
.obj gap_09_805D6545_sdata, global
.hidden gap_09_805D6545_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6545_sdata

# .sdata:0x1D0 | 0x805D6548 | size: 0x7
.obj kar_srcfile_jobj_h_805d6548, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6548

# .sdata:0x1D7 | 0x805D654F | size: 0x1
.obj gap_09_805D654F_sdata, global
.hidden gap_09_805D654F_sdata
	.byte 0x00
.endobj gap_09_805D654F_sdata

# .sdata:0x1D8 | 0x805D6550 | size: 0x5
.obj lbl_805D6550, global
	.string "jobj"
.endobj lbl_805D6550

# .sdata:0x1DD | 0x805D6555 | size: 0x3
.obj gap_09_805D6555_sdata, global
.hidden gap_09_805D6555_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6555_sdata

# .sdata:0x1E0 | 0x805D6558 | size: 0x7
.obj kar_srcfile_jobj_h_805d6558, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6558

# .sdata:0x1E7 | 0x805D655F | size: 0x1
.obj gap_09_805D655F_sdata, global
.hidden gap_09_805D655F_sdata
	.byte 0x00
.endobj gap_09_805D655F_sdata

# .sdata:0x1E8 | 0x805D6560 | size: 0x5
.obj lbl_805D6560, global
	.string "jobj"
.endobj lbl_805D6560

# .sdata:0x1ED | 0x805D6565 | size: 0x3
.obj gap_09_805D6565_sdata, global
.hidden gap_09_805D6565_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6565_sdata

# .sdata:0x1F0 | 0x805D6568 | size: 0x7
.obj kar_srcfile_jobj_h_805d6568, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6568

# .sdata:0x1F7 | 0x805D656F | size: 0x1
.obj gap_09_805D656F_sdata, global
.hidden gap_09_805D656F_sdata
	.byte 0x00
.endobj gap_09_805D656F_sdata

# .sdata:0x1F8 | 0x805D6570 | size: 0x5
.obj lbl_805D6570, global
	.string "jobj"
.endobj lbl_805D6570

# .sdata:0x1FD | 0x805D6575 | size: 0x3
.obj gap_09_805D6575_sdata, global
.hidden gap_09_805D6575_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6575_sdata

# .sdata:0x200 | 0x805D6578 | size: 0x7
.obj kar_srcfile_jobj_h_805d6578, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6578

# .sdata:0x207 | 0x805D657F | size: 0x1
.obj gap_09_805D657F_sdata, global
.hidden gap_09_805D657F_sdata
	.byte 0x00
.endobj gap_09_805D657F_sdata

# .sdata:0x208 | 0x805D6580 | size: 0x5
.obj lbl_805D6580, global
	.string "jobj"
.endobj lbl_805D6580

# .sdata:0x20D | 0x805D6585 | size: 0x3
.obj gap_09_805D6585_sdata, global
.hidden gap_09_805D6585_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6585_sdata

# .sdata:0x210 | 0x805D6588 | size: 0x7
.obj kar_srcfile_jobj_h_805d6588, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6588

# .sdata:0x217 | 0x805D658F | size: 0x1
.obj gap_09_805D658F_sdata, global
.hidden gap_09_805D658F_sdata
	.byte 0x00
.endobj gap_09_805D658F_sdata

# .sdata:0x218 | 0x805D6590 | size: 0x5
.obj lbl_805D6590, global
	.string "jobj"
.endobj lbl_805D6590

# .sdata:0x21D | 0x805D6595 | size: 0x3
.obj gap_09_805D6595_sdata, global
.hidden gap_09_805D6595_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6595_sdata

# .sdata:0x220 | 0x805D6598 | size: 0x7
.obj kar_srcfile_jobj_h_805d6598, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6598

# .sdata:0x227 | 0x805D659F | size: 0x1
.obj gap_09_805D659F_sdata, global
.hidden gap_09_805D659F_sdata
	.byte 0x00
.endobj gap_09_805D659F_sdata

# .sdata:0x228 | 0x805D65A0 | size: 0x5
.obj lbl_805D65A0, global
	.string "jobj"
.endobj lbl_805D65A0

# .sdata:0x22D | 0x805D65A5 | size: 0x3
.obj gap_09_805D65A5_sdata, global
.hidden gap_09_805D65A5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D65A5_sdata

# .sdata:0x230 | 0x805D65A8 | size: 0x7
.obj kar_srcfile_jobj_h_805d65a8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d65a8

# .sdata:0x237 | 0x805D65AF | size: 0x1
.obj gap_09_805D65AF_sdata, global
.hidden gap_09_805D65AF_sdata
	.byte 0x00
.endobj gap_09_805D65AF_sdata

# .sdata:0x238 | 0x805D65B0 | size: 0x5
.obj lbl_805D65B0, global
	.string "jobj"
.endobj lbl_805D65B0

# .sdata:0x23D | 0x805D65B5 | size: 0x3
.obj gap_09_805D65B5_sdata, global
.hidden gap_09_805D65B5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D65B5_sdata

# .sdata:0x240 | 0x805D65B8 | size: 0x7
.obj kar_srcfile_jobj_h_805d65b8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d65b8

# .sdata:0x247 | 0x805D65BF | size: 0x1
.obj gap_09_805D65BF_sdata, global
.hidden gap_09_805D65BF_sdata
	.byte 0x00
.endobj gap_09_805D65BF_sdata

# .sdata:0x248 | 0x805D65C0 | size: 0x5
.obj lbl_805D65C0, global
	.string "jobj"
.endobj lbl_805D65C0

# .sdata:0x24D | 0x805D65C5 | size: 0x3
.obj gap_09_805D65C5_sdata, global
.hidden gap_09_805D65C5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D65C5_sdata

# .sdata:0x250 | 0x805D65C8 | size: 0x7
.obj kar_srcfile_jobj_h_805d65c8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d65c8

# .sdata:0x257 | 0x805D65CF | size: 0x1
.obj gap_09_805D65CF_sdata, global
.hidden gap_09_805D65CF_sdata
	.byte 0x00
.endobj gap_09_805D65CF_sdata

# .sdata:0x258 | 0x805D65D0 | size: 0x5
.obj lbl_805D65D0, global
	.string "jobj"
.endobj lbl_805D65D0

# .sdata:0x25D | 0x805D65D5 | size: 0x3
.obj gap_09_805D65D5_sdata, global
.hidden gap_09_805D65D5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D65D5_sdata

# .sdata:0x260 | 0x805D65D8 | size: 0x7
.obj kar_srcfile_jobj_h_805d65d8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d65d8

# .sdata:0x267 | 0x805D65DF | size: 0x1
.obj gap_09_805D65DF_sdata, global
.hidden gap_09_805D65DF_sdata
	.byte 0x00
.endobj gap_09_805D65DF_sdata

# .sdata:0x268 | 0x805D65E0 | size: 0x5
.obj lbl_805D65E0, global
	.string "jobj"
.endobj lbl_805D65E0

# .sdata:0x26D | 0x805D65E5 | size: 0x3
.obj gap_09_805D65E5_sdata, global
.hidden gap_09_805D65E5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D65E5_sdata

# .sdata:0x270 | 0x805D65E8 | size: 0x7
.obj lbl_805D65E8, global
	.string "MnAll."
.endobj lbl_805D65E8

# .sdata:0x277 | 0x805D65EF | size: 0x1
.obj gap_09_805D65EF_sdata, global
.hidden gap_09_805D65EF_sdata
	.byte 0x00
.endobj gap_09_805D65EF_sdata

# .sdata:0x278 | 0x805D65F0 | size: 0x8
.obj kar_srcfile_mnlib_c_805d65f0, global
	.string "mnlib.c"
.endobj kar_srcfile_mnlib_c_805d65f0

# .sdata:0x280 | 0x805D65F8 | size: 0x2
.obj lbl_805D65F8, global
	.string "0"
.endobj lbl_805D65F8

# .sdata:0x282 | 0x805D65FA | size: 0x6
.obj gap_09_805D65FA_sdata, global
.hidden gap_09_805D65FA_sdata
	.4byte 0x00000000
	.2byte 0x0000
.endobj gap_09_805D65FA_sdata

# .sdata:0x288 | 0x805D6600 | size: 0x8
.obj lbl_805D6600, global
	.4byte 0x4C617073
	.4byte 0x81460000
.endobj lbl_805D6600

# .sdata:0x290 | 0x805D6608 | size: 0x4
.obj lbl_805D6608, global
	.4byte 0x81480000
.endobj lbl_805D6608

# .sdata:0x294 | 0x805D660C | size: 0x3
.obj lbl_805D660C, global
	.string "%d"
.endobj lbl_805D660C

# .sdata:0x297 | 0x805D660F | size: 0x1
.obj gap_09_805D660F_sdata, global
.hidden gap_09_805D660F_sdata
	.byte 0x00
.endobj gap_09_805D660F_sdata

# .sdata:0x298 | 0x805D6610 | size: 0x8
.obj lbl_805D6610, global
	.4byte 0x54696D65
	.4byte 0x81460000
.endobj lbl_805D6610

# .sdata:0x2A0 | 0x805D6618 | size: 0x4
.obj lbl_805D6618, global
	.string "min"
.endobj lbl_805D6618

# .sdata:0x2A4 | 0x805D661C | size: 0x8
.obj lbl_805D661C, global
	.string "Shuffle"
.endobj lbl_805D661C

# .sdata:0x2AC | 0x805D6624 | size: 0x8
.obj lbl_805D6624, global
	.4byte 0x816D2573
	.4byte 0x816E0000
.endobj lbl_805D6624

# .sdata:0x2B4 | 0x805D662C | size: 0x8
.obj lbl_805D662C, global
	.4byte 0x816D2564
	.4byte 0x00000000
.endobj lbl_805D662C

# .sdata:0x2BC | 0x805D6634 | size: 0x5
.obj lbl_805D6634, global
	.string "Laps"
.endobj lbl_805D6634

# .sdata:0x2C1 | 0x805D6639 | size: 0x3
.obj gap_09_805D6639_sdata, global
.hidden gap_09_805D6639_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6639_sdata

# .sdata:0x2C4 | 0x805D663C | size: 0x4
.obj lbl_805D663C, global
	.4byte 0x816E0000
.endobj lbl_805D663C

# .sdata:0x2C8 | 0x805D6640 | size: 0x4
.obj lbl_805D6640, global
	.4byte 0x81460000
.endobj lbl_805D6640

# .sdata:0x2CC | 0x805D6644 | size: 0x4
.obj lbl_805D6644, global
	.4byte 0x00000000
.endobj lbl_805D6644

# .sdata:0x2D0 | 0x805D6648 | size: 0x2
.obj lbl_805D6648, global
	.string "."
.endobj lbl_805D6648

# .sdata:0x2D2 | 0x805D664A | size: 0x2
.obj gap_09_805D664A_sdata, global
.hidden gap_09_805D664A_sdata
	.2byte 0x0000
.endobj gap_09_805D664A_sdata

# .sdata:0x2D4 | 0x805D664C | size: 0x2
.obj lbl_805D664C, global
	.string "f"
.endobj lbl_805D664C

# .sdata:0x2D6 | 0x805D664E | size: 0x2
.obj gap_09_805D664E_sdata, global
.hidden gap_09_805D664E_sdata
	.2byte 0x0000
.endobj gap_09_805D664E_sdata

# .sdata:0x2D8 | 0x805D6650 | size: 0x2
.obj lbl_805D6650, global
	.string "t"
.endobj lbl_805D6650

# .sdata:0x2DA | 0x805D6652 | size: 0x2
.obj gap_09_805D6652_sdata, global
.hidden gap_09_805D6652_sdata
	.2byte 0x0000
.endobj gap_09_805D6652_sdata

# .sdata:0x2DC | 0x805D6654 | size: 0x2
.obj lbl_805D6654, global
	.string "P"
.endobj lbl_805D6654

# .sdata:0x2DE | 0x805D6656 | size: 0x2
.obj gap_09_805D6656_sdata, global
.hidden gap_09_805D6656_sdata
	.2byte 0x0000
.endobj gap_09_805D6656_sdata

# .sdata:0x2E0 | 0x805D6658 | size: 0x2
.obj lbl_805D6658, global
	.string "s"
.endobj lbl_805D6658

# .sdata:0x2E2 | 0x805D665A | size: 0x2
.obj gap_09_805D665A_sdata, global
.hidden gap_09_805D665A_sdata
	.2byte 0x0000
.endobj gap_09_805D665A_sdata

# .sdata:0x2E4 | 0x805D665C | size: 0x2
.obj lbl_805D665C, global
	.string "-"
.endobj lbl_805D665C

# .sdata:0x2E6 | 0x805D665E | size: 0x2
.obj gap_09_805D665E_sdata, global
.hidden gap_09_805D665E_sdata
	.2byte 0x0000
.endobj gap_09_805D665E_sdata

# .sdata:0x2E8 | 0x805D6660 | size: 0x4
.obj lbl_805D6660, global
	.4byte 0x817E0000
.endobj lbl_805D6660

# .sdata:0x2EC | 0x805D6664 | size: 0x2
.obj lbl_805D6664, global
	.string "'"
.endobj lbl_805D6664

# .sdata:0x2EE | 0x805D6666 | size: 0x2
.obj gap_09_805D6666_sdata, global
.hidden gap_09_805D6666_sdata
	.2byte 0x0000
.endobj gap_09_805D6666_sdata

# .sdata:0x2F0 | 0x805D6668 | size: 0x8
.obj lbl_805D6668, global
	.4byte 0x0000141E
	.4byte 0x00000000
.endobj lbl_805D6668

# .sdata:0x2F8 | 0x805D6670 | size: 0x8
.obj lbl_805D6670, global
	.4byte 0x050A0F14
	.4byte 0x19000000
.endobj lbl_805D6670

# .sdata:0x300 | 0x805D6678 | size: 0x8
.obj lbl_805D6678, global
	.4byte 0x000A141E
	.4byte 0x28320000
.endobj lbl_805D6678

# .sdata:0x308 | 0x805D6680 | size: 0x8
.obj lbl_805D6680, global
	.byte 0x05, 0x0F, 0x19, 0x23, 0x2D, 0x37, 0x00, 0x00
.endobj lbl_805D6680

# .sdata:0x310 | 0x805D6688 | size: 0x7
.obj lbl_805D6688, global
	.string "<FPZdn"
.endobj lbl_805D6688

# .sdata:0x317 | 0x805D668F | size: 0x1
.obj gap_09_805D668F_sdata, global
.hidden gap_09_805D668F_sdata
	.byte 0x00
.endobj gap_09_805D668F_sdata

# .sdata:0x318 | 0x805D6690 | size: 0x7
.obj lbl_805D6690, global
	.string "AKU_is"
.endobj lbl_805D6690

# .sdata:0x31F | 0x805D6697 | size: 0x1
.obj gap_09_805D6697_sdata, global
.hidden gap_09_805D6697_sdata
	.byte 0x00
.endobj gap_09_805D6697_sdata

# .sdata:0x320 | 0x805D6698 | size: 0x7
.obj kar_srcfile_jobj_h_805d6698, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6698

# .sdata:0x327 | 0x805D669F | size: 0x1
.obj gap_09_805D669F_sdata, global
.hidden gap_09_805D669F_sdata
	.byte 0x00
.endobj gap_09_805D669F_sdata

# .sdata:0x328 | 0x805D66A0 | size: 0x5
.obj lbl_805D66A0, global
	.string "jobj"
.endobj lbl_805D66A0

# .sdata:0x32D | 0x805D66A5 | size: 0x3
.obj gap_09_805D66A5_sdata, global
.hidden gap_09_805D66A5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D66A5_sdata

# .sdata:0x330 | 0x805D66A8 | size: 0x6
.obj lbl_805D66A8, global
	.string "scale"
.endobj lbl_805D66A8

# .sdata:0x336 | 0x805D66AE | size: 0x2
.obj gap_09_805D66AE_sdata, global
.hidden gap_09_805D66AE_sdata
	.2byte 0x0000
.endobj gap_09_805D66AE_sdata

# .sdata:0x338 | 0x805D66B0 | size: 0x7
.obj kar_srcfile_jobj_h_805d66b0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d66b0

# .sdata:0x33F | 0x805D66B7 | size: 0x1
.obj gap_09_805D66B7_sdata, global
.hidden gap_09_805D66B7_sdata
	.byte 0x00
.endobj gap_09_805D66B7_sdata

# .sdata:0x340 | 0x805D66B8 | size: 0x5
.obj lbl_805D66B8, global
	.string "jobj"
.endobj lbl_805D66B8

# .sdata:0x345 | 0x805D66BD | size: 0x3
.obj gap_09_805D66BD_sdata, global
.hidden gap_09_805D66BD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D66BD_sdata

# .sdata:0x348 | 0x805D66C0 | size: 0x8
.obj lbl_805D66C0, global
	.4byte 0x03040506
	.4byte 0x07080900
.endobj lbl_805D66C0

# .sdata:0x350 | 0x805D66C8 | size: 0x7
.obj kar_srcfile_jobj_h_805d66c8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d66c8

# .sdata:0x357 | 0x805D66CF | size: 0x1
.obj gap_09_805D66CF_sdata, global
.hidden gap_09_805D66CF_sdata
	.byte 0x00
.endobj gap_09_805D66CF_sdata

# .sdata:0x358 | 0x805D66D0 | size: 0x5
.obj lbl_805D66D0, global
	.string "jobj"
.endobj lbl_805D66D0

# .sdata:0x35D | 0x805D66D5 | size: 0x3
.obj gap_09_805D66D5_sdata, global
.hidden gap_09_805D66D5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D66D5_sdata

# .sdata:0x360 | 0x805D66D8 | size: 0x7
.obj kar_srcfile_jobj_h_805d66d8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d66d8

# .sdata:0x367 | 0x805D66DF | size: 0x1
.obj gap_09_805D66DF_sdata, global
.hidden gap_09_805D66DF_sdata
	.byte 0x00
.endobj gap_09_805D66DF_sdata

# .sdata:0x368 | 0x805D66E0 | size: 0x5
.obj lbl_805D66E0, global
	.string "jobj"
.endobj lbl_805D66E0

# .sdata:0x36D | 0x805D66E5 | size: 0x3
.obj gap_09_805D66E5_sdata, global
.hidden gap_09_805D66E5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D66E5_sdata

# .sdata:0x370 | 0x805D66E8 | size: 0x7
.obj kar_srcfile_jobj_h_805d66e8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d66e8

# .sdata:0x377 | 0x805D66EF | size: 0x1
.obj gap_09_805D66EF_sdata, global
.hidden gap_09_805D66EF_sdata
	.byte 0x00
.endobj gap_09_805D66EF_sdata

# .sdata:0x378 | 0x805D66F0 | size: 0x5
.obj lbl_805D66F0, global
	.string "jobj"
.endobj lbl_805D66F0

# .sdata:0x37D | 0x805D66F5 | size: 0x3
.obj gap_09_805D66F5_sdata, global
.hidden gap_09_805D66F5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D66F5_sdata

# .sdata:0x380 | 0x805D66F8 | size: 0x7
.obj kar_srcfile_jobj_h_805d66f8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d66f8

# .sdata:0x387 | 0x805D66FF | size: 0x1
.obj gap_09_805D66FF_sdata, global
.hidden gap_09_805D66FF_sdata
	.byte 0x00
.endobj gap_09_805D66FF_sdata

# .sdata:0x388 | 0x805D6700 | size: 0x5
.obj lbl_805D6700, global
	.string "jobj"
.endobj lbl_805D6700

# .sdata:0x38D | 0x805D6705 | size: 0x3
.obj gap_09_805D6705_sdata, global
.hidden gap_09_805D6705_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6705_sdata

# .sdata:0x390 | 0x805D6708 | size: 0x7
.obj kar_srcfile_jobj_h_805d6708, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6708

# .sdata:0x397 | 0x805D670F | size: 0x1
.obj gap_09_805D670F_sdata, global
.hidden gap_09_805D670F_sdata
	.byte 0x00
.endobj gap_09_805D670F_sdata

# .sdata:0x398 | 0x805D6710 | size: 0x5
.obj lbl_805D6710, global
	.string "jobj"
.endobj lbl_805D6710

# .sdata:0x39D | 0x805D6715 | size: 0x3
.obj gap_09_805D6715_sdata, global
.hidden gap_09_805D6715_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6715_sdata

# .sdata:0x3A0 | 0x805D6718 | size: 0x7
.obj kar_srcfile_jobj_h_805d6718, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6718

# .sdata:0x3A7 | 0x805D671F | size: 0x1
.obj gap_09_805D671F_sdata, global
.hidden gap_09_805D671F_sdata
	.byte 0x00
.endobj gap_09_805D671F_sdata

# .sdata:0x3A8 | 0x805D6720 | size: 0x5
.obj lbl_805D6720, global
	.string "jobj"
.endobj lbl_805D6720

# .sdata:0x3AD | 0x805D6725 | size: 0x3
.obj gap_09_805D6725_sdata, global
.hidden gap_09_805D6725_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6725_sdata

# .sdata:0x3B0 | 0x805D6728 | size: 0x7
.obj kar_srcfile_jobj_h_805d6728, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6728

# .sdata:0x3B7 | 0x805D672F | size: 0x1
.obj gap_09_805D672F_sdata, global
.hidden gap_09_805D672F_sdata
	.byte 0x00
.endobj gap_09_805D672F_sdata

# .sdata:0x3B8 | 0x805D6730 | size: 0x5
.obj lbl_805D6730, global
	.string "jobj"
.endobj lbl_805D6730

# .sdata:0x3BD | 0x805D6735 | size: 0x3
.obj gap_09_805D6735_sdata, global
.hidden gap_09_805D6735_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6735_sdata

# .sdata:0x3C0 | 0x805D6738 | size: 0x7
.obj kar_srcfile_jobj_h_805d6738, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6738

# .sdata:0x3C7 | 0x805D673F | size: 0x1
.obj gap_09_805D673F_sdata, global
.hidden gap_09_805D673F_sdata
	.byte 0x00
.endobj gap_09_805D673F_sdata

# .sdata:0x3C8 | 0x805D6740 | size: 0x5
.obj lbl_805D6740, global
	.string "jobj"
.endobj lbl_805D6740

# .sdata:0x3CD | 0x805D6745 | size: 0x3
.obj gap_09_805D6745_sdata, global
.hidden gap_09_805D6745_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6745_sdata

# .sdata:0x3D0 | 0x805D6748 | size: 0x7
.obj kar_srcfile_jobj_h_805d6748, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6748

# .sdata:0x3D7 | 0x805D674F | size: 0x1
.obj gap_09_805D674F_sdata, global
.hidden gap_09_805D674F_sdata
	.byte 0x00
.endobj gap_09_805D674F_sdata

# .sdata:0x3D8 | 0x805D6750 | size: 0x5
.obj lbl_805D6750, global
	.string "jobj"
.endobj lbl_805D6750

# .sdata:0x3DD | 0x805D6755 | size: 0x3
.obj gap_09_805D6755_sdata, global
.hidden gap_09_805D6755_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6755_sdata

# .sdata:0x3E0 | 0x805D6758 | size: 0x7
.obj kar_srcfile_jobj_h_805d6758, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6758

# .sdata:0x3E7 | 0x805D675F | size: 0x1
.obj gap_09_805D675F_sdata, global
.hidden gap_09_805D675F_sdata
	.byte 0x00
.endobj gap_09_805D675F_sdata

# .sdata:0x3E8 | 0x805D6760 | size: 0x5
.obj lbl_805D6760, global
	.string "jobj"
.endobj lbl_805D6760

# .sdata:0x3ED | 0x805D6765 | size: 0x3
.obj gap_09_805D6765_sdata, global
.hidden gap_09_805D6765_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6765_sdata

# .sdata:0x3F0 | 0x805D6768 | size: 0x7
.obj kar_srcfile_jobj_h_805d6768, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6768

# .sdata:0x3F7 | 0x805D676F | size: 0x1
.obj gap_09_805D676F_sdata, global
.hidden gap_09_805D676F_sdata
	.byte 0x00
.endobj gap_09_805D676F_sdata

# .sdata:0x3F8 | 0x805D6770 | size: 0x5
.obj lbl_805D6770, global
	.string "jobj"
.endobj lbl_805D6770

# .sdata:0x3FD | 0x805D6775 | size: 0x3
.obj gap_09_805D6775_sdata, global
.hidden gap_09_805D6775_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6775_sdata

# .sdata:0x400 | 0x805D6778 | size: 0x7
.obj kar_srcfile_jobj_h_805d6778, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6778

# .sdata:0x407 | 0x805D677F | size: 0x1
.obj gap_09_805D677F_sdata, global
.hidden gap_09_805D677F_sdata
	.byte 0x00
.endobj gap_09_805D677F_sdata

# .sdata:0x408 | 0x805D6780 | size: 0x5
.obj lbl_805D6780, global
	.string "jobj"
.endobj lbl_805D6780

# .sdata:0x40D | 0x805D6785 | size: 0x3
.obj gap_09_805D6785_sdata, global
.hidden gap_09_805D6785_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6785_sdata

# .sdata:0x410 | 0x805D6788 | size: 0x6
.obj lbl_805D6788, global
	.string "scale"
.endobj lbl_805D6788

# .sdata:0x416 | 0x805D678E | size: 0x2
.obj gap_09_805D678E_sdata, global
.hidden gap_09_805D678E_sdata
	.2byte 0x0000
.endobj gap_09_805D678E_sdata

# .sdata:0x418 | 0x805D6790 | size: 0x7
.obj kar_srcfile_jobj_h_805d6790, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6790

# .sdata:0x41F | 0x805D6797 | size: 0x1
.obj gap_09_805D6797_sdata, global
.hidden gap_09_805D6797_sdata
	.byte 0x00
.endobj gap_09_805D6797_sdata

# .sdata:0x420 | 0x805D6798 | size: 0x5
.obj lbl_805D6798, global
	.string "jobj"
.endobj lbl_805D6798

# .sdata:0x425 | 0x805D679D | size: 0x3
.obj gap_09_805D679D_sdata, global
.hidden gap_09_805D679D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D679D_sdata

# .sdata:0x428 | 0x805D67A0 | size: 0x7
.obj kar_srcfile_jobj_h_805d67a0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d67a0

# .sdata:0x42F | 0x805D67A7 | size: 0x1
.obj gap_09_805D67A7_sdata, global
.hidden gap_09_805D67A7_sdata
	.byte 0x00
.endobj gap_09_805D67A7_sdata

# .sdata:0x430 | 0x805D67A8 | size: 0x5
.obj lbl_805D67A8, global
	.string "jobj"
.endobj lbl_805D67A8

# .sdata:0x435 | 0x805D67AD | size: 0x3
.obj gap_09_805D67AD_sdata, global
.hidden gap_09_805D67AD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D67AD_sdata

# .sdata:0x438 | 0x805D67B0 | size: 0x8
.obj lbl_805D67B0, global
	.4byte 0x00010200
	.4byte 0x01030000
.endobj lbl_805D67B0

# .sdata:0x440 | 0x805D67B8 | size: 0x7
.obj kar_srcfile_jobj_h_805d67b8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d67b8

# .sdata:0x447 | 0x805D67BF | size: 0x1
.obj gap_09_805D67BF_sdata, global
.hidden gap_09_805D67BF_sdata
	.byte 0x00
.endobj gap_09_805D67BF_sdata

# .sdata:0x448 | 0x805D67C0 | size: 0x5
.obj lbl_805D67C0, global
	.string "jobj"
.endobj lbl_805D67C0

# .sdata:0x44D | 0x805D67C5 | size: 0x3
.obj gap_09_805D67C5_sdata, global
.hidden gap_09_805D67C5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D67C5_sdata

# .sdata:0x450 | 0x805D67C8 | size: 0x7
.obj kar_srcfile_jobj_h_805d67c8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d67c8

# .sdata:0x457 | 0x805D67CF | size: 0x1
.obj gap_09_805D67CF_sdata, global
.hidden gap_09_805D67CF_sdata
	.byte 0x00
.endobj gap_09_805D67CF_sdata

# .sdata:0x458 | 0x805D67D0 | size: 0x5
.obj lbl_805D67D0, global
	.string "jobj"
.endobj lbl_805D67D0

# .sdata:0x45D | 0x805D67D5 | size: 0x3
.obj gap_09_805D67D5_sdata, global
.hidden gap_09_805D67D5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D67D5_sdata

# .sdata:0x460 | 0x805D67D8 | size: 0x7
.obj kar_srcfile_jobj_h_805d67d8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d67d8

# .sdata:0x467 | 0x805D67DF | size: 0x1
.obj gap_09_805D67DF_sdata, global
.hidden gap_09_805D67DF_sdata
	.byte 0x00
.endobj gap_09_805D67DF_sdata

# .sdata:0x468 | 0x805D67E0 | size: 0x5
.obj lbl_805D67E0, global
	.string "jobj"
.endobj lbl_805D67E0

# .sdata:0x46D | 0x805D67E5 | size: 0x3
.obj gap_09_805D67E5_sdata, global
.hidden gap_09_805D67E5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D67E5_sdata

# .sdata:0x470 | 0x805D67E8 | size: 0x7
.obj kar_srcfile_jobj_h_805d67e8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d67e8

# .sdata:0x477 | 0x805D67EF | size: 0x1
.obj gap_09_805D67EF_sdata, global
.hidden gap_09_805D67EF_sdata
	.byte 0x00
.endobj gap_09_805D67EF_sdata

# .sdata:0x478 | 0x805D67F0 | size: 0x5
.obj lbl_805D67F0, global
	.string "jobj"
.endobj lbl_805D67F0

# .sdata:0x47D | 0x805D67F5 | size: 0x3
.obj gap_09_805D67F5_sdata, global
.hidden gap_09_805D67F5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D67F5_sdata

# .sdata:0x480 | 0x805D67F8 | size: 0x7
.obj kar_srcfile_jobj_h_805d67f8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d67f8

# .sdata:0x487 | 0x805D67FF | size: 0x1
.obj gap_09_805D67FF_sdata, global
.hidden gap_09_805D67FF_sdata
	.byte 0x00
.endobj gap_09_805D67FF_sdata

# .sdata:0x488 | 0x805D6800 | size: 0x5
.obj lbl_805D6800, global
	.string "jobj"
.endobj lbl_805D6800

# .sdata:0x48D | 0x805D6805 | size: 0x3
.obj gap_09_805D6805_sdata, global
.hidden gap_09_805D6805_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6805_sdata

# .sdata:0x490 | 0x805D6808 | size: 0x7
.obj kar_srcfile_jobj_h_805d6808, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6808

# .sdata:0x497 | 0x805D680F | size: 0x1
.obj gap_09_805D680F_sdata, global
.hidden gap_09_805D680F_sdata
	.byte 0x00
.endobj gap_09_805D680F_sdata

# .sdata:0x498 | 0x805D6810 | size: 0x5
.obj lbl_805D6810, global
	.string "jobj"
.endobj lbl_805D6810

# .sdata:0x49D | 0x805D6815 | size: 0x3
.obj gap_09_805D6815_sdata, global
.hidden gap_09_805D6815_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6815_sdata

# .sdata:0x4A0 | 0x805D6818 | size: 0x7
.obj kar_srcfile_jobj_h_805d6818, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6818

# .sdata:0x4A7 | 0x805D681F | size: 0x1
.obj gap_09_805D681F_sdata, global
.hidden gap_09_805D681F_sdata
	.byte 0x00
.endobj gap_09_805D681F_sdata

# .sdata:0x4A8 | 0x805D6820 | size: 0x5
.obj lbl_805D6820, global
	.string "jobj"
.endobj lbl_805D6820

# .sdata:0x4AD | 0x805D6825 | size: 0x3
.obj gap_09_805D6825_sdata, global
.hidden gap_09_805D6825_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6825_sdata

# .sdata:0x4B0 | 0x805D6828 | size: 0x7
.obj kar_srcfile_jobj_h_805d6828, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6828

# .sdata:0x4B7 | 0x805D682F | size: 0x1
.obj gap_09_805D682F_sdata, global
.hidden gap_09_805D682F_sdata
	.byte 0x00
.endobj gap_09_805D682F_sdata

# .sdata:0x4B8 | 0x805D6830 | size: 0x5
.obj lbl_805D6830, global
	.string "jobj"
.endobj lbl_805D6830

# .sdata:0x4BD | 0x805D6835 | size: 0x3
.obj gap_09_805D6835_sdata, global
.hidden gap_09_805D6835_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6835_sdata

# .sdata:0x4C0 | 0x805D6838 | size: 0x7
.obj kar_srcfile_jobj_h_805d6838, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6838

# .sdata:0x4C7 | 0x805D683F | size: 0x1
.obj gap_09_805D683F_sdata, global
.hidden gap_09_805D683F_sdata
	.byte 0x00
.endobj gap_09_805D683F_sdata

# .sdata:0x4C8 | 0x805D6840 | size: 0x5
.obj lbl_805D6840, global
	.string "jobj"
.endobj lbl_805D6840

# .sdata:0x4CD | 0x805D6845 | size: 0x3
.obj gap_09_805D6845_sdata, global
.hidden gap_09_805D6845_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6845_sdata

# .sdata:0x4D0 | 0x805D6848 | size: 0x7
.obj kar_srcfile_jobj_h_805d6848, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6848

# .sdata:0x4D7 | 0x805D684F | size: 0x1
.obj gap_09_805D684F_sdata, global
.hidden gap_09_805D684F_sdata
	.byte 0x00
.endobj gap_09_805D684F_sdata

# .sdata:0x4D8 | 0x805D6850 | size: 0x5
.obj lbl_805D6850, global
	.string "jobj"
.endobj lbl_805D6850

# .sdata:0x4DD | 0x805D6855 | size: 0x3
.obj gap_09_805D6855_sdata, global
.hidden gap_09_805D6855_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6855_sdata

# .sdata:0x4E0 | 0x805D6858 | size: 0x7
.obj kar_srcfile_jobj_h_805d6858, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6858

# .sdata:0x4E7 | 0x805D685F | size: 0x1
.obj gap_09_805D685F_sdata, global
.hidden gap_09_805D685F_sdata
	.byte 0x00
.endobj gap_09_805D685F_sdata

# .sdata:0x4E8 | 0x805D6860 | size: 0x5
.obj lbl_805D6860, global
	.string "jobj"
.endobj lbl_805D6860

# .sdata:0x4ED | 0x805D6865 | size: 0x3
.obj gap_09_805D6865_sdata, global
.hidden gap_09_805D6865_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6865_sdata

# .sdata:0x4F0 | 0x805D6868 | size: 0x7
.obj kar_srcfile_jobj_h_805d6868, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6868

# .sdata:0x4F7 | 0x805D686F | size: 0x1
.obj gap_09_805D686F_sdata, global
.hidden gap_09_805D686F_sdata
	.byte 0x00
.endobj gap_09_805D686F_sdata

# .sdata:0x4F8 | 0x805D6870 | size: 0x5
.obj lbl_805D6870, global
	.string "jobj"
.endobj lbl_805D6870

# .sdata:0x4FD | 0x805D6875 | size: 0x3
.obj gap_09_805D6875_sdata, global
.hidden gap_09_805D6875_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6875_sdata

# .sdata:0x500 | 0x805D6878 | size: 0x7
.obj kar_srcfile_jobj_h_805d6878, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6878

# .sdata:0x507 | 0x805D687F | size: 0x1
.obj gap_09_805D687F_sdata, global
.hidden gap_09_805D687F_sdata
	.byte 0x00
.endobj gap_09_805D687F_sdata

# .sdata:0x508 | 0x805D6880 | size: 0x5
.obj lbl_805D6880, global
	.string "jobj"
.endobj lbl_805D6880

# .sdata:0x50D | 0x805D6885 | size: 0x3
.obj gap_09_805D6885_sdata, global
.hidden gap_09_805D6885_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6885_sdata

# .sdata:0x510 | 0x805D6888 | size: 0x7
.obj kar_srcfile_jobj_h_805d6888, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6888

# .sdata:0x517 | 0x805D688F | size: 0x1
.obj gap_09_805D688F_sdata, global
.hidden gap_09_805D688F_sdata
	.byte 0x00
.endobj gap_09_805D688F_sdata

# .sdata:0x518 | 0x805D6890 | size: 0x5
.obj lbl_805D6890, global
	.string "jobj"
.endobj lbl_805D6890

# .sdata:0x51D | 0x805D6895 | size: 0x3
.obj gap_09_805D6895_sdata, global
.hidden gap_09_805D6895_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6895_sdata

# .sdata:0x520 | 0x805D6898 | size: 0x7
.obj kar_srcfile_jobj_h_805d6898, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6898

# .sdata:0x527 | 0x805D689F | size: 0x1
.obj gap_09_805D689F_sdata, global
.hidden gap_09_805D689F_sdata
	.byte 0x00
.endobj gap_09_805D689F_sdata

# .sdata:0x528 | 0x805D68A0 | size: 0x5
.obj lbl_805D68A0, global
	.string "jobj"
.endobj lbl_805D68A0

# .sdata:0x52D | 0x805D68A5 | size: 0x3
.obj gap_09_805D68A5_sdata, global
.hidden gap_09_805D68A5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D68A5_sdata

# .sdata:0x530 | 0x805D68A8 | size: 0x8
.obj lbl_805D68A8, global
	.4byte 0x00010200
	.4byte 0x01030000
.endobj lbl_805D68A8

# .sdata:0x538 | 0x805D68B0 | size: 0x7
.obj kar_srcfile_jobj_h_805d68b0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d68b0

# .sdata:0x53F | 0x805D68B7 | size: 0x1
.obj gap_09_805D68B7_sdata, global
.hidden gap_09_805D68B7_sdata
	.byte 0x00
.endobj gap_09_805D68B7_sdata

# .sdata:0x540 | 0x805D68B8 | size: 0x5
.obj lbl_805D68B8, global
	.string "jobj"
.endobj lbl_805D68B8

# .sdata:0x545 | 0x805D68BD | size: 0x3
.obj gap_09_805D68BD_sdata, global
.hidden gap_09_805D68BD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D68BD_sdata

# .sdata:0x548 | 0x805D68C0 | size: 0x7
.obj kar_srcfile_jobj_h_805d68c0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d68c0

# .sdata:0x54F | 0x805D68C7 | size: 0x1
.obj gap_09_805D68C7_sdata, global
.hidden gap_09_805D68C7_sdata
	.byte 0x00
.endobj gap_09_805D68C7_sdata

# .sdata:0x550 | 0x805D68C8 | size: 0x5
.obj lbl_805D68C8, global
	.string "jobj"
.endobj lbl_805D68C8

# .sdata:0x555 | 0x805D68CD | size: 0x3
.obj gap_09_805D68CD_sdata, global
.hidden gap_09_805D68CD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D68CD_sdata

# .sdata:0x558 | 0x805D68D0 | size: 0x7
.obj kar_srcfile_jobj_h_805d68d0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d68d0

# .sdata:0x55F | 0x805D68D7 | size: 0x1
.obj gap_09_805D68D7_sdata, global
.hidden gap_09_805D68D7_sdata
	.byte 0x00
.endobj gap_09_805D68D7_sdata

# .sdata:0x560 | 0x805D68D8 | size: 0x5
.obj lbl_805D68D8, global
	.string "jobj"
.endobj lbl_805D68D8

# .sdata:0x565 | 0x805D68DD | size: 0x3
.obj gap_09_805D68DD_sdata, global
.hidden gap_09_805D68DD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D68DD_sdata

# .sdata:0x568 | 0x805D68E0 | size: 0x7
.obj kar_srcfile_jobj_h_805d68e0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d68e0

# .sdata:0x56F | 0x805D68E7 | size: 0x1
.obj gap_09_805D68E7_sdata, global
.hidden gap_09_805D68E7_sdata
	.byte 0x00
.endobj gap_09_805D68E7_sdata

# .sdata:0x570 | 0x805D68E8 | size: 0x5
.obj lbl_805D68E8, global
	.string "jobj"
.endobj lbl_805D68E8

# .sdata:0x575 | 0x805D68ED | size: 0x3
.obj gap_09_805D68ED_sdata, global
.hidden gap_09_805D68ED_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D68ED_sdata

# .sdata:0x578 | 0x805D68F0 | size: 0x7
.obj kar_srcfile_jobj_h_805d68f0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d68f0

# .sdata:0x57F | 0x805D68F7 | size: 0x1
.obj gap_09_805D68F7_sdata, global
.hidden gap_09_805D68F7_sdata
	.byte 0x00
.endobj gap_09_805D68F7_sdata

# .sdata:0x580 | 0x805D68F8 | size: 0x5
.obj lbl_805D68F8, global
	.string "jobj"
.endobj lbl_805D68F8

# .sdata:0x585 | 0x805D68FD | size: 0x3
.obj gap_09_805D68FD_sdata, global
.hidden gap_09_805D68FD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D68FD_sdata

# .sdata:0x588 | 0x805D6900 | size: 0x7
.obj kar_srcfile_jobj_h_805d6900, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6900

# .sdata:0x58F | 0x805D6907 | size: 0x1
.obj gap_09_805D6907_sdata, global
.hidden gap_09_805D6907_sdata
	.byte 0x00
.endobj gap_09_805D6907_sdata

# .sdata:0x590 | 0x805D6908 | size: 0x5
.obj lbl_805D6908, global
	.string "jobj"
.endobj lbl_805D6908

# .sdata:0x595 | 0x805D690D | size: 0x3
.obj gap_09_805D690D_sdata, global
.hidden gap_09_805D690D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D690D_sdata

# .sdata:0x598 | 0x805D6910 | size: 0x7
.obj kar_srcfile_jobj_h_805d6910, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6910

# .sdata:0x59F | 0x805D6917 | size: 0x1
.obj gap_09_805D6917_sdata, global
.hidden gap_09_805D6917_sdata
	.byte 0x00
.endobj gap_09_805D6917_sdata

# .sdata:0x5A0 | 0x805D6918 | size: 0x5
.obj lbl_805D6918, global
	.string "jobj"
.endobj lbl_805D6918

# .sdata:0x5A5 | 0x805D691D | size: 0x3
.obj gap_09_805D691D_sdata, global
.hidden gap_09_805D691D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D691D_sdata

# .sdata:0x5A8 | 0x805D6920 | size: 0x7
.obj kar_srcfile_jobj_h_805d6920, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6920

# .sdata:0x5AF | 0x805D6927 | size: 0x1
.obj gap_09_805D6927_sdata, global
.hidden gap_09_805D6927_sdata
	.byte 0x00
.endobj gap_09_805D6927_sdata

# .sdata:0x5B0 | 0x805D6928 | size: 0x5
.obj lbl_805D6928, global
	.string "jobj"
.endobj lbl_805D6928

# .sdata:0x5B5 | 0x805D692D | size: 0x3
.obj gap_09_805D692D_sdata, global
.hidden gap_09_805D692D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D692D_sdata

# .sdata:0x5B8 | 0x805D6930 | size: 0x7
.obj kar_srcfile_jobj_h_805d6930, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6930

# .sdata:0x5BF | 0x805D6937 | size: 0x1
.obj gap_09_805D6937_sdata, global
.hidden gap_09_805D6937_sdata
	.byte 0x00
.endobj gap_09_805D6937_sdata

# .sdata:0x5C0 | 0x805D6938 | size: 0x5
.obj lbl_805D6938, global
	.string "jobj"
.endobj lbl_805D6938

# .sdata:0x5C5 | 0x805D693D | size: 0x3
.obj gap_09_805D693D_sdata, global
.hidden gap_09_805D693D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D693D_sdata

# .sdata:0x5C8 | 0x805D6940 | size: 0x7
.obj kar_srcfile_jobj_h_805d6940, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6940

# .sdata:0x5CF | 0x805D6947 | size: 0x1
.obj gap_09_805D6947_sdata, global
.hidden gap_09_805D6947_sdata
	.byte 0x00
.endobj gap_09_805D6947_sdata

# .sdata:0x5D0 | 0x805D6948 | size: 0x5
.obj lbl_805D6948, global
	.string "jobj"
.endobj lbl_805D6948

# .sdata:0x5D5 | 0x805D694D | size: 0x3
.obj gap_09_805D694D_sdata, global
.hidden gap_09_805D694D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D694D_sdata

# .sdata:0x5D8 | 0x805D6950 | size: 0x6
.obj lbl_805D6950, global
	.string "scale"
.endobj lbl_805D6950

# .sdata:0x5DE | 0x805D6956 | size: 0x2
.obj gap_09_805D6956_sdata, global
.hidden gap_09_805D6956_sdata
	.2byte 0x0000
.endobj gap_09_805D6956_sdata

# .sdata:0x5E0 | 0x805D6958 | size: 0x7
.obj kar_srcfile_jobj_h_805d6958, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6958

# .sdata:0x5E7 | 0x805D695F | size: 0x1
.obj gap_09_805D695F_sdata, global
.hidden gap_09_805D695F_sdata
	.byte 0x00
.endobj gap_09_805D695F_sdata

# .sdata:0x5E8 | 0x805D6960 | size: 0x5
.obj lbl_805D6960, global
	.string "jobj"
.endobj lbl_805D6960

# .sdata:0x5ED | 0x805D6965 | size: 0x3
.obj gap_09_805D6965_sdata, global
.hidden gap_09_805D6965_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6965_sdata

# .sdata:0x5F0 | 0x805D6968 | size: 0x7
.obj kar_srcfile_jobj_h_805d6968, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6968

# .sdata:0x5F7 | 0x805D696F | size: 0x1
.obj gap_09_805D696F_sdata, global
.hidden gap_09_805D696F_sdata
	.byte 0x00
.endobj gap_09_805D696F_sdata

# .sdata:0x5F8 | 0x805D6970 | size: 0x5
.obj lbl_805D6970, global
	.string "jobj"
.endobj lbl_805D6970

# .sdata:0x5FD | 0x805D6975 | size: 0x3
.obj gap_09_805D6975_sdata, global
.hidden gap_09_805D6975_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6975_sdata

# .sdata:0x600 | 0x805D6978 | size: 0x8
.obj lbl_805D6978, global
	.4byte 0x00010200
	.4byte 0x01030000
.endobj lbl_805D6978

# .sdata:0x608 | 0x805D6980 | size: 0x7
.obj kar_srcfile_jobj_h_805d6980, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6980

# .sdata:0x60F | 0x805D6987 | size: 0x1
.obj gap_09_805D6987_sdata, global
.hidden gap_09_805D6987_sdata
	.byte 0x00
.endobj gap_09_805D6987_sdata

# .sdata:0x610 | 0x805D6988 | size: 0x5
.obj lbl_805D6988, global
	.string "jobj"
.endobj lbl_805D6988

# .sdata:0x615 | 0x805D698D | size: 0x3
.obj gap_09_805D698D_sdata, global
.hidden gap_09_805D698D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D698D_sdata

# .sdata:0x618 | 0x805D6990 | size: 0x7
.obj kar_srcfile_jobj_h_805d6990, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6990

# .sdata:0x61F | 0x805D6997 | size: 0x1
.obj gap_09_805D6997_sdata, global
.hidden gap_09_805D6997_sdata
	.byte 0x00
.endobj gap_09_805D6997_sdata

# .sdata:0x620 | 0x805D6998 | size: 0x5
.obj lbl_805D6998, global
	.string "jobj"
.endobj lbl_805D6998

# .sdata:0x625 | 0x805D699D | size: 0x3
.obj gap_09_805D699D_sdata, global
.hidden gap_09_805D699D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D699D_sdata

# .sdata:0x628 | 0x805D69A0 | size: 0x7
.obj kar_srcfile_jobj_h_805d69a0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d69a0

# .sdata:0x62F | 0x805D69A7 | size: 0x1
.obj gap_09_805D69A7_sdata, global
.hidden gap_09_805D69A7_sdata
	.byte 0x00
.endobj gap_09_805D69A7_sdata

# .sdata:0x630 | 0x805D69A8 | size: 0x5
.obj lbl_805D69A8, global
	.string "jobj"
.endobj lbl_805D69A8

# .sdata:0x635 | 0x805D69AD | size: 0x3
.obj gap_09_805D69AD_sdata, global
.hidden gap_09_805D69AD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D69AD_sdata

# .sdata:0x638 | 0x805D69B0 | size: 0x7
.obj kar_srcfile_jobj_h_805d69b0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d69b0

# .sdata:0x63F | 0x805D69B7 | size: 0x1
.obj gap_09_805D69B7_sdata, global
.hidden gap_09_805D69B7_sdata
	.byte 0x00
.endobj gap_09_805D69B7_sdata

# .sdata:0x640 | 0x805D69B8 | size: 0x5
.obj lbl_805D69B8, global
	.string "jobj"
.endobj lbl_805D69B8

# .sdata:0x645 | 0x805D69BD | size: 0x3
.obj gap_09_805D69BD_sdata, global
.hidden gap_09_805D69BD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D69BD_sdata

# .sdata:0x648 | 0x805D69C0 | size: 0x7
.obj kar_srcfile_jobj_h_805d69c0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d69c0

# .sdata:0x64F | 0x805D69C7 | size: 0x1
.obj gap_09_805D69C7_sdata, global
.hidden gap_09_805D69C7_sdata
	.byte 0x00
.endobj gap_09_805D69C7_sdata

# .sdata:0x650 | 0x805D69C8 | size: 0x5
.obj lbl_805D69C8, global
	.string "jobj"
.endobj lbl_805D69C8

# .sdata:0x655 | 0x805D69CD | size: 0x3
.obj gap_09_805D69CD_sdata, global
.hidden gap_09_805D69CD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D69CD_sdata

# .sdata:0x658 | 0x805D69D0 | size: 0x7
.obj kar_srcfile_jobj_h_805d69d0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d69d0

# .sdata:0x65F | 0x805D69D7 | size: 0x1
.obj gap_09_805D69D7_sdata, global
.hidden gap_09_805D69D7_sdata
	.byte 0x00
.endobj gap_09_805D69D7_sdata

# .sdata:0x660 | 0x805D69D8 | size: 0x5
.obj lbl_805D69D8, global
	.string "jobj"
.endobj lbl_805D69D8

# .sdata:0x665 | 0x805D69DD | size: 0x3
.obj gap_09_805D69DD_sdata, global
.hidden gap_09_805D69DD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D69DD_sdata

# .sdata:0x668 | 0x805D69E0 | size: 0x7
.obj kar_srcfile_jobj_h_805d69e0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d69e0

# .sdata:0x66F | 0x805D69E7 | size: 0x1
.obj gap_09_805D69E7_sdata, global
.hidden gap_09_805D69E7_sdata
	.byte 0x00
.endobj gap_09_805D69E7_sdata

# .sdata:0x670 | 0x805D69E8 | size: 0x5
.obj lbl_805D69E8, global
	.string "jobj"
.endobj lbl_805D69E8

# .sdata:0x675 | 0x805D69ED | size: 0x3
.obj gap_09_805D69ED_sdata, global
.hidden gap_09_805D69ED_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D69ED_sdata

# .sdata:0x678 | 0x805D69F0 | size: 0x7
.obj kar_srcfile_jobj_h_805d69f0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d69f0

# .sdata:0x67F | 0x805D69F7 | size: 0x1
.obj gap_09_805D69F7_sdata, global
.hidden gap_09_805D69F7_sdata
	.byte 0x00
.endobj gap_09_805D69F7_sdata

# .sdata:0x680 | 0x805D69F8 | size: 0x5
.obj lbl_805D69F8, global
	.string "jobj"
.endobj lbl_805D69F8

# .sdata:0x685 | 0x805D69FD | size: 0x3
.obj gap_09_805D69FD_sdata, global
.hidden gap_09_805D69FD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D69FD_sdata

# .sdata:0x688 | 0x805D6A00 | size: 0x7
.obj kar_srcfile_jobj_h_805d6a00, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6a00

# .sdata:0x68F | 0x805D6A07 | size: 0x1
.obj gap_09_805D6A07_sdata, global
.hidden gap_09_805D6A07_sdata
	.byte 0x00
.endobj gap_09_805D6A07_sdata

# .sdata:0x690 | 0x805D6A08 | size: 0x5
.obj lbl_805D6A08, global
	.string "jobj"
.endobj lbl_805D6A08

# .sdata:0x695 | 0x805D6A0D | size: 0x3
.obj gap_09_805D6A0D_sdata, global
.hidden gap_09_805D6A0D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6A0D_sdata

# .sdata:0x698 | 0x805D6A10 | size: 0x7
.obj kar_srcfile_jobj_h_805d6a10, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6a10

# .sdata:0x69F | 0x805D6A17 | size: 0x1
.obj gap_09_805D6A17_sdata, global
.hidden gap_09_805D6A17_sdata
	.byte 0x00
.endobj gap_09_805D6A17_sdata

# .sdata:0x6A0 | 0x805D6A18 | size: 0x5
.obj lbl_805D6A18, global
	.string "jobj"
.endobj lbl_805D6A18

# .sdata:0x6A5 | 0x805D6A1D | size: 0x3
.obj gap_09_805D6A1D_sdata, global
.hidden gap_09_805D6A1D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6A1D_sdata

# .sdata:0x6A8 | 0x805D6A20 | size: 0x7
.obj kar_srcfile_jobj_h_805d6a20, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6a20

# .sdata:0x6AF | 0x805D6A27 | size: 0x1
.obj gap_09_805D6A27_sdata, global
.hidden gap_09_805D6A27_sdata
	.byte 0x00
.endobj gap_09_805D6A27_sdata

# .sdata:0x6B0 | 0x805D6A28 | size: 0x5
.obj lbl_805D6A28, global
	.string "jobj"
.endobj lbl_805D6A28

# .sdata:0x6B5 | 0x805D6A2D | size: 0x3
.obj gap_09_805D6A2D_sdata, global
.hidden gap_09_805D6A2D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6A2D_sdata

# .sdata:0x6B8 | 0x805D6A30 | size: 0x7
.obj kar_srcfile_jobj_h_805d6a30, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6a30

# .sdata:0x6BF | 0x805D6A37 | size: 0x1
.obj gap_09_805D6A37_sdata, global
.hidden gap_09_805D6A37_sdata
	.byte 0x00
.endobj gap_09_805D6A37_sdata

# .sdata:0x6C0 | 0x805D6A38 | size: 0x5
.obj lbl_805D6A38, global
	.string "jobj"
.endobj lbl_805D6A38

# .sdata:0x6C5 | 0x805D6A3D | size: 0x3
.obj gap_09_805D6A3D_sdata, global
.hidden gap_09_805D6A3D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6A3D_sdata

# .sdata:0x6C8 | 0x805D6A40 | size: 0x7
.obj kar_srcfile_jobj_h_805d6a40, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6a40

# .sdata:0x6CF | 0x805D6A47 | size: 0x1
.obj gap_09_805D6A47_sdata, global
.hidden gap_09_805D6A47_sdata
	.byte 0x00
.endobj gap_09_805D6A47_sdata

# .sdata:0x6D0 | 0x805D6A48 | size: 0x5
.obj lbl_805D6A48, global
	.string "jobj"
.endobj lbl_805D6A48

# .sdata:0x6D5 | 0x805D6A4D | size: 0x3
.obj gap_09_805D6A4D_sdata, global
.hidden gap_09_805D6A4D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6A4D_sdata

# .sdata:0x6D8 | 0x805D6A50 | size: 0x7
.obj kar_srcfile_jobj_h_805d6a50, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6a50

# .sdata:0x6DF | 0x805D6A57 | size: 0x1
.obj gap_09_805D6A57_sdata, global
.hidden gap_09_805D6A57_sdata
	.byte 0x00
.endobj gap_09_805D6A57_sdata

# .sdata:0x6E0 | 0x805D6A58 | size: 0x5
.obj lbl_805D6A58, global
	.string "jobj"
.endobj lbl_805D6A58

# .sdata:0x6E5 | 0x805D6A5D | size: 0x3
.obj gap_09_805D6A5D_sdata, global
.hidden gap_09_805D6A5D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6A5D_sdata

# .sdata:0x6E8 | 0x805D6A60 | size: 0x7
.obj kar_srcfile_jobj_h_805d6a60, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6a60

# .sdata:0x6EF | 0x805D6A67 | size: 0x1
.obj gap_09_805D6A67_sdata, global
.hidden gap_09_805D6A67_sdata
	.byte 0x00
.endobj gap_09_805D6A67_sdata

# .sdata:0x6F0 | 0x805D6A68 | size: 0x5
.obj lbl_805D6A68, global
	.string "jobj"
.endobj lbl_805D6A68

# .sdata:0x6F5 | 0x805D6A6D | size: 0x3
.obj gap_09_805D6A6D_sdata, global
.hidden gap_09_805D6A6D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6A6D_sdata

# .sdata:0x6F8 | 0x805D6A70 | size: 0x7
.obj kar_srcfile_aobj_h_805d6a70, global
	.string "aobj.h"
.endobj kar_srcfile_aobj_h_805d6a70

# .sdata:0x6FF | 0x805D6A77 | size: 0x1
.obj gap_09_805D6A77_sdata, global
.hidden gap_09_805D6A77_sdata
	.byte 0x00
.endobj gap_09_805D6A77_sdata

# .sdata:0x700 | 0x805D6A78 | size: 0x5
.obj lbl_805D6A78, global
	.string "aobj"
.endobj lbl_805D6A78

# .sdata:0x705 | 0x805D6A7D | size: 0x3
.obj gap_09_805D6A7D_sdata, global
.hidden gap_09_805D6A7D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6A7D_sdata

# .sdata:0x708 | 0x805D6A80 | size: 0x7
.obj kar_srcfile_aobj_h_805d6a80, global
	.string "aobj.h"
.endobj kar_srcfile_aobj_h_805d6a80

# .sdata:0x70F | 0x805D6A87 | size: 0x1
.obj gap_09_805D6A87_sdata, global
.hidden gap_09_805D6A87_sdata
	.byte 0x00
.endobj gap_09_805D6A87_sdata

# .sdata:0x710 | 0x805D6A88 | size: 0x5
.obj lbl_805D6A88, global
	.string "aobj"
.endobj lbl_805D6A88

# .sdata:0x715 | 0x805D6A8D | size: 0x3
.obj gap_09_805D6A8D_sdata, global
.hidden gap_09_805D6A8D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6A8D_sdata

# .sdata:0x718 | 0x805D6A90 | size: 0x7
.obj kar_srcfile_jobj_h_805d6a90, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6a90

# .sdata:0x71F | 0x805D6A97 | size: 0x1
.obj gap_09_805D6A97_sdata, global
.hidden gap_09_805D6A97_sdata
	.byte 0x00
.endobj gap_09_805D6A97_sdata

# .sdata:0x720 | 0x805D6A98 | size: 0x5
.obj lbl_805D6A98, global
	.string "jobj"
.endobj lbl_805D6A98

# .sdata:0x725 | 0x805D6A9D | size: 0x3
.obj gap_09_805D6A9D_sdata, global
.hidden gap_09_805D6A9D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6A9D_sdata

# .sdata:0x728 | 0x805D6AA0 | size: 0x7
.obj kar_srcfile_aobj_h_805d6aa0, global
	.string "aobj.h"
.endobj kar_srcfile_aobj_h_805d6aa0

# .sdata:0x72F | 0x805D6AA7 | size: 0x1
.obj gap_09_805D6AA7_sdata, global
.hidden gap_09_805D6AA7_sdata
	.byte 0x00
.endobj gap_09_805D6AA7_sdata

# .sdata:0x730 | 0x805D6AA8 | size: 0x5
.obj lbl_805D6AA8, global
	.string "aobj"
.endobj lbl_805D6AA8

# .sdata:0x735 | 0x805D6AAD | size: 0x3
.obj gap_09_805D6AAD_sdata, global
.hidden gap_09_805D6AAD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6AAD_sdata

# .sdata:0x738 | 0x805D6AB0 | size: 0x7
.obj kar_srcfile_jobj_h_805d6ab0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6ab0

# .sdata:0x73F | 0x805D6AB7 | size: 0x1
.obj gap_09_805D6AB7_sdata, global
.hidden gap_09_805D6AB7_sdata
	.byte 0x00
.endobj gap_09_805D6AB7_sdata

# .sdata:0x740 | 0x805D6AB8 | size: 0x5
.obj lbl_805D6AB8, global
	.string "jobj"
.endobj lbl_805D6AB8

# .sdata:0x745 | 0x805D6ABD | size: 0x3
.obj gap_09_805D6ABD_sdata, global
.hidden gap_09_805D6ABD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6ABD_sdata

# .sdata:0x748 | 0x805D6AC0 | size: 0x7
.obj kar_srcfile_jobj_h_805d6ac0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6ac0

# .sdata:0x74F | 0x805D6AC7 | size: 0x1
.obj gap_09_805D6AC7_sdata, global
.hidden gap_09_805D6AC7_sdata
	.byte 0x00
.endobj gap_09_805D6AC7_sdata

# .sdata:0x750 | 0x805D6AC8 | size: 0x5
.obj lbl_805D6AC8, global
	.string "jobj"
.endobj lbl_805D6AC8

# .sdata:0x755 | 0x805D6ACD | size: 0x3
.obj gap_09_805D6ACD_sdata, global
.hidden gap_09_805D6ACD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6ACD_sdata

# .sdata:0x758 | 0x805D6AD0 | size: 0x7
.obj kar_srcfile_jobj_h_805d6ad0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6ad0

# .sdata:0x75F | 0x805D6AD7 | size: 0x1
.obj gap_09_805D6AD7_sdata, global
.hidden gap_09_805D6AD7_sdata
	.byte 0x00
.endobj gap_09_805D6AD7_sdata

# .sdata:0x760 | 0x805D6AD8 | size: 0x5
.obj lbl_805D6AD8, global
	.string "jobj"
.endobj lbl_805D6AD8

# .sdata:0x765 | 0x805D6ADD | size: 0x3
.obj gap_09_805D6ADD_sdata, global
.hidden gap_09_805D6ADD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6ADD_sdata

# .sdata:0x768 | 0x805D6AE0 | size: 0x6
.obj lbl_805D6AE0, global
	.string "scale"
.endobj lbl_805D6AE0

# .sdata:0x76E | 0x805D6AE6 | size: 0x2
.obj gap_09_805D6AE6_sdata, global
.hidden gap_09_805D6AE6_sdata
	.2byte 0x0000
.endobj gap_09_805D6AE6_sdata

# .sdata:0x770 | 0x805D6AE8 | size: 0x7
.obj kar_srcfile_jobj_h_805d6ae8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6ae8

# .sdata:0x777 | 0x805D6AEF | size: 0x1
.obj gap_09_805D6AEF_sdata, global
.hidden gap_09_805D6AEF_sdata
	.byte 0x00
.endobj gap_09_805D6AEF_sdata

# .sdata:0x778 | 0x805D6AF0 | size: 0x5
.obj lbl_805D6AF0, global
	.string "jobj"
.endobj lbl_805D6AF0

# .sdata:0x77D | 0x805D6AF5 | size: 0x3
.obj gap_09_805D6AF5_sdata, global
.hidden gap_09_805D6AF5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6AF5_sdata

# .sdata:0x780 | 0x805D6AF8 | size: 0x7
.obj kar_srcfile_aobj_h_805d6af8, global
	.string "aobj.h"
.endobj kar_srcfile_aobj_h_805d6af8

# .sdata:0x787 | 0x805D6AFF | size: 0x1
.obj gap_09_805D6AFF_sdata, global
.hidden gap_09_805D6AFF_sdata
	.byte 0x00
.endobj gap_09_805D6AFF_sdata

# .sdata:0x788 | 0x805D6B00 | size: 0x5
.obj lbl_805D6B00, global
	.string "aobj"
.endobj lbl_805D6B00

# .sdata:0x78D | 0x805D6B05 | size: 0x3
.obj gap_09_805D6B05_sdata, global
.hidden gap_09_805D6B05_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6B05_sdata

# .sdata:0x790 | 0x805D6B08 | size: 0x7
.obj kar_srcfile_jobj_h_805d6b08, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6b08

# .sdata:0x797 | 0x805D6B0F | size: 0x1
.obj gap_09_805D6B0F_sdata, global
.hidden gap_09_805D6B0F_sdata
	.byte 0x00
.endobj gap_09_805D6B0F_sdata

# .sdata:0x798 | 0x805D6B10 | size: 0x5
.obj lbl_805D6B10, global
	.string "jobj"
.endobj lbl_805D6B10

# .sdata:0x79D | 0x805D6B15 | size: 0x3
.obj gap_09_805D6B15_sdata, global
.hidden gap_09_805D6B15_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6B15_sdata

# .sdata:0x7A0 | 0x805D6B18 | size: 0x7
.obj kar_srcfile_jobj_h_805d6b18, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6b18

# .sdata:0x7A7 | 0x805D6B1F | size: 0x1
.obj gap_09_805D6B1F_sdata, global
.hidden gap_09_805D6B1F_sdata
	.byte 0x00
.endobj gap_09_805D6B1F_sdata

# .sdata:0x7A8 | 0x805D6B20 | size: 0x5
.obj lbl_805D6B20, global
	.string "jobj"
.endobj lbl_805D6B20

# .sdata:0x7AD | 0x805D6B25 | size: 0x3
.obj gap_09_805D6B25_sdata, global
.hidden gap_09_805D6B25_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6B25_sdata

# .sdata:0x7B0 | 0x805D6B28 | size: 0x7
.obj kar_srcfile_jobj_h_805d6b28, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6b28

# .sdata:0x7B7 | 0x805D6B2F | size: 0x1
.obj gap_09_805D6B2F_sdata, global
.hidden gap_09_805D6B2F_sdata
	.byte 0x00
.endobj gap_09_805D6B2F_sdata

# .sdata:0x7B8 | 0x805D6B30 | size: 0x5
.obj lbl_805D6B30, global
	.string "jobj"
.endobj lbl_805D6B30

# .sdata:0x7BD | 0x805D6B35 | size: 0x3
.obj gap_09_805D6B35_sdata, global
.hidden gap_09_805D6B35_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6B35_sdata

# .sdata:0x7C0 | 0x805D6B38 | size: 0x7
.obj kar_srcfile_aobj_h_805d6b38, global
	.string "aobj.h"
.endobj kar_srcfile_aobj_h_805d6b38

# .sdata:0x7C7 | 0x805D6B3F | size: 0x1
.obj gap_09_805D6B3F_sdata, global
.hidden gap_09_805D6B3F_sdata
	.byte 0x00
.endobj gap_09_805D6B3F_sdata

# .sdata:0x7C8 | 0x805D6B40 | size: 0x5
.obj lbl_805D6B40, global
	.string "aobj"
.endobj lbl_805D6B40

# .sdata:0x7CD | 0x805D6B45 | size: 0x3
.obj gap_09_805D6B45_sdata, global
.hidden gap_09_805D6B45_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6B45_sdata

# .sdata:0x7D0 | 0x805D6B48 | size: 0x7
.obj kar_srcfile_jobj_h_805d6b48, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6b48

# .sdata:0x7D7 | 0x805D6B4F | size: 0x1
.obj gap_09_805D6B4F_sdata, global
.hidden gap_09_805D6B4F_sdata
	.byte 0x00
.endobj gap_09_805D6B4F_sdata

# .sdata:0x7D8 | 0x805D6B50 | size: 0x5
.obj lbl_805D6B50, global
	.string "jobj"
.endobj lbl_805D6B50

# .sdata:0x7DD | 0x805D6B55 | size: 0x3
.obj gap_09_805D6B55_sdata, global
.hidden gap_09_805D6B55_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6B55_sdata

# .sdata:0x7E0 | 0x805D6B58 | size: 0x7
.obj kar_srcfile_jobj_h_805d6b58, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6b58

# .sdata:0x7E7 | 0x805D6B5F | size: 0x1
.obj gap_09_805D6B5F_sdata, global
.hidden gap_09_805D6B5F_sdata
	.byte 0x00
.endobj gap_09_805D6B5F_sdata

# .sdata:0x7E8 | 0x805D6B60 | size: 0x5
.obj lbl_805D6B60, global
	.string "jobj"
.endobj lbl_805D6B60

# .sdata:0x7ED | 0x805D6B65 | size: 0x3
.obj gap_09_805D6B65_sdata, global
.hidden gap_09_805D6B65_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6B65_sdata

# .sdata:0x7F0 | 0x805D6B68 | size: 0x7
.obj kar_srcfile_jobj_h_805d6b68, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6b68

# .sdata:0x7F7 | 0x805D6B6F | size: 0x1
.obj gap_09_805D6B6F_sdata, global
.hidden gap_09_805D6B6F_sdata
	.byte 0x00
.endobj gap_09_805D6B6F_sdata

# .sdata:0x7F8 | 0x805D6B70 | size: 0x5
.obj lbl_805D6B70, global
	.string "jobj"
.endobj lbl_805D6B70

# .sdata:0x7FD | 0x805D6B75 | size: 0x3
.obj gap_09_805D6B75_sdata, global
.hidden gap_09_805D6B75_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6B75_sdata

# .sdata:0x800 | 0x805D6B78 | size: 0x7
.obj kar_srcfile_jobj_h_805d6b78, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6b78

# .sdata:0x807 | 0x805D6B7F | size: 0x1
.obj gap_09_805D6B7F_sdata, global
.hidden gap_09_805D6B7F_sdata
	.byte 0x00
.endobj gap_09_805D6B7F_sdata

# .sdata:0x808 | 0x805D6B80 | size: 0x5
.obj lbl_805D6B80, global
	.string "jobj"
.endobj lbl_805D6B80

# .sdata:0x80D | 0x805D6B85 | size: 0x3
.obj gap_09_805D6B85_sdata, global
.hidden gap_09_805D6B85_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6B85_sdata

# .sdata:0x810 | 0x805D6B88 | size: 0x6
.obj lbl_805D6B88, global
	.string "scale"
.endobj lbl_805D6B88

# .sdata:0x816 | 0x805D6B8E | size: 0x2
.obj gap_09_805D6B8E_sdata, global
.hidden gap_09_805D6B8E_sdata
	.2byte 0x0000
.endobj gap_09_805D6B8E_sdata

# .sdata:0x818 | 0x805D6B90 | size: 0x7
.obj kar_srcfile_jobj_h_805d6b90, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6b90

# .sdata:0x81F | 0x805D6B97 | size: 0x1
.obj gap_09_805D6B97_sdata, global
.hidden gap_09_805D6B97_sdata
	.byte 0x00
.endobj gap_09_805D6B97_sdata

# .sdata:0x820 | 0x805D6B98 | size: 0x5
.obj lbl_805D6B98, global
	.string "jobj"
.endobj lbl_805D6B98

# .sdata:0x825 | 0x805D6B9D | size: 0x3
.obj gap_09_805D6B9D_sdata, global
.hidden gap_09_805D6B9D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6B9D_sdata

# .sdata:0x828 | 0x805D6BA0 | size: 0x7
.obj kar_srcfile_aobj_h_805d6ba0, global
	.string "aobj.h"
.endobj kar_srcfile_aobj_h_805d6ba0

# .sdata:0x82F | 0x805D6BA7 | size: 0x1
.obj gap_09_805D6BA7_sdata, global
.hidden gap_09_805D6BA7_sdata
	.byte 0x00
.endobj gap_09_805D6BA7_sdata

# .sdata:0x830 | 0x805D6BA8 | size: 0x5
.obj lbl_805D6BA8, global
	.string "aobj"
.endobj lbl_805D6BA8

# .sdata:0x835 | 0x805D6BAD | size: 0x3
.obj gap_09_805D6BAD_sdata, global
.hidden gap_09_805D6BAD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6BAD_sdata

# .sdata:0x838 | 0x805D6BB0 | size: 0x7
.obj kar_srcfile_jobj_h_805d6bb0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6bb0

# .sdata:0x83F | 0x805D6BB7 | size: 0x1
.obj gap_09_805D6BB7_sdata, global
.hidden gap_09_805D6BB7_sdata
	.byte 0x00
.endobj gap_09_805D6BB7_sdata

# .sdata:0x840 | 0x805D6BB8 | size: 0x5
.obj lbl_805D6BB8, global
	.string "jobj"
.endobj lbl_805D6BB8

# .sdata:0x845 | 0x805D6BBD | size: 0x3
.obj gap_09_805D6BBD_sdata, global
.hidden gap_09_805D6BBD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6BBD_sdata

# .sdata:0x848 | 0x805D6BC0 | size: 0x7
.obj kar_srcfile_jobj_h_805d6bc0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6bc0

# .sdata:0x84F | 0x805D6BC7 | size: 0x1
.obj gap_09_805D6BC7_sdata, global
.hidden gap_09_805D6BC7_sdata
	.byte 0x00
.endobj gap_09_805D6BC7_sdata

# .sdata:0x850 | 0x805D6BC8 | size: 0x5
.obj lbl_805D6BC8, global
	.string "jobj"
.endobj lbl_805D6BC8

# .sdata:0x855 | 0x805D6BCD | size: 0x3
.obj gap_09_805D6BCD_sdata, global
.hidden gap_09_805D6BCD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6BCD_sdata

# .sdata:0x858 | 0x805D6BD0 | size: 0x7
.obj kar_srcfile_jobj_h_805d6bd0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6bd0

# .sdata:0x85F | 0x805D6BD7 | size: 0x1
.obj gap_09_805D6BD7_sdata, global
.hidden gap_09_805D6BD7_sdata
	.byte 0x00
.endobj gap_09_805D6BD7_sdata

# .sdata:0x860 | 0x805D6BD8 | size: 0x5
.obj lbl_805D6BD8, global
	.string "jobj"
.endobj lbl_805D6BD8

# .sdata:0x865 | 0x805D6BDD | size: 0x3
.obj gap_09_805D6BDD_sdata, global
.hidden gap_09_805D6BDD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6BDD_sdata

# .sdata:0x868 | 0x805D6BE0 | size: 0x7
.obj kar_srcfile_jobj_h_805d6be0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6be0

# .sdata:0x86F | 0x805D6BE7 | size: 0x1
.obj gap_09_805D6BE7_sdata, global
.hidden gap_09_805D6BE7_sdata
	.byte 0x00
.endobj gap_09_805D6BE7_sdata

# .sdata:0x870 | 0x805D6BE8 | size: 0x5
.obj lbl_805D6BE8, global
	.string "jobj"
.endobj lbl_805D6BE8

# .sdata:0x875 | 0x805D6BED | size: 0x3
.obj gap_09_805D6BED_sdata, global
.hidden gap_09_805D6BED_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6BED_sdata

# .sdata:0x878 | 0x805D6BF0 | size: 0x7
.obj kar_srcfile_jobj_h_805d6bf0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6bf0

# .sdata:0x87F | 0x805D6BF7 | size: 0x1
.obj gap_09_805D6BF7_sdata, global
.hidden gap_09_805D6BF7_sdata
	.byte 0x00
.endobj gap_09_805D6BF7_sdata

# .sdata:0x880 | 0x805D6BF8 | size: 0x5
.obj lbl_805D6BF8, global
	.string "jobj"
.endobj lbl_805D6BF8

# .sdata:0x885 | 0x805D6BFD | size: 0x3
.obj gap_09_805D6BFD_sdata, global
.hidden gap_09_805D6BFD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6BFD_sdata

# .sdata:0x888 | 0x805D6C00 | size: 0x7
.obj kar_srcfile_jobj_h_805d6c00, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6c00

# .sdata:0x88F | 0x805D6C07 | size: 0x1
.obj gap_09_805D6C07_sdata, global
.hidden gap_09_805D6C07_sdata
	.byte 0x00
.endobj gap_09_805D6C07_sdata

# .sdata:0x890 | 0x805D6C08 | size: 0x5
.obj lbl_805D6C08, global
	.string "jobj"
.endobj lbl_805D6C08

# .sdata:0x895 | 0x805D6C0D | size: 0x3
.obj gap_09_805D6C0D_sdata, global
.hidden gap_09_805D6C0D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6C0D_sdata

# .sdata:0x898 | 0x805D6C10 | size: 0x7
.obj kar_srcfile_aobj_h_805d6c10, global
	.string "aobj.h"
.endobj kar_srcfile_aobj_h_805d6c10

# .sdata:0x89F | 0x805D6C17 | size: 0x1
.obj gap_09_805D6C17_sdata, global
.hidden gap_09_805D6C17_sdata
	.byte 0x00
.endobj gap_09_805D6C17_sdata

# .sdata:0x8A0 | 0x805D6C18 | size: 0x5
.obj lbl_805D6C18, global
	.string "aobj"
.endobj lbl_805D6C18

# .sdata:0x8A5 | 0x805D6C1D | size: 0x3
.obj gap_09_805D6C1D_sdata, global
.hidden gap_09_805D6C1D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6C1D_sdata

# .sdata:0x8A8 | 0x805D6C20 | size: 0x8
.obj lbl_805D6C20, global
	.byte 0x09, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00
.endobj lbl_805D6C20

# .sdata:0x8B0 | 0x805D6C28 | size: 0x7
.obj kar_srcfile_jobj_h_805d6c28, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6c28

# .sdata:0x8B7 | 0x805D6C2F | size: 0x1
.obj gap_09_805D6C2F_sdata, global
.hidden gap_09_805D6C2F_sdata
	.byte 0x00
.endobj gap_09_805D6C2F_sdata

# .sdata:0x8B8 | 0x805D6C30 | size: 0x5
.obj lbl_805D6C30, global
	.string "jobj"
.endobj lbl_805D6C30

# .sdata:0x8BD | 0x805D6C35 | size: 0x3
.obj gap_09_805D6C35_sdata, global
.hidden gap_09_805D6C35_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6C35_sdata

# .sdata:0x8C0 | 0x805D6C38 | size: 0x7
.obj kar_srcfile_jobj_h_805d6c38, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6c38

# .sdata:0x8C7 | 0x805D6C3F | size: 0x1
.obj gap_09_805D6C3F_sdata, global
.hidden gap_09_805D6C3F_sdata
	.byte 0x00
.endobj gap_09_805D6C3F_sdata

# .sdata:0x8C8 | 0x805D6C40 | size: 0x5
.obj lbl_805D6C40, global
	.string "jobj"
.endobj lbl_805D6C40

# .sdata:0x8CD | 0x805D6C45 | size: 0x3
.obj gap_09_805D6C45_sdata, global
.hidden gap_09_805D6C45_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6C45_sdata

# .sdata:0x8D0 | 0x805D6C48 | size: 0x7
.obj kar_srcfile_jobj_h_805d6c48, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6c48

# .sdata:0x8D7 | 0x805D6C4F | size: 0x1
.obj gap_09_805D6C4F_sdata, global
.hidden gap_09_805D6C4F_sdata
	.byte 0x00
.endobj gap_09_805D6C4F_sdata

# .sdata:0x8D8 | 0x805D6C50 | size: 0x5
.obj lbl_805D6C50, global
	.string "jobj"
.endobj lbl_805D6C50

# .sdata:0x8DD | 0x805D6C55 | size: 0x3
.obj gap_09_805D6C55_sdata, global
.hidden gap_09_805D6C55_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6C55_sdata

# .sdata:0x8E0 | 0x805D6C58 | size: 0x7
.obj kar_srcfile_jobj_h_805d6c58, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6c58

# .sdata:0x8E7 | 0x805D6C5F | size: 0x1
.obj gap_09_805D6C5F_sdata, global
.hidden gap_09_805D6C5F_sdata
	.byte 0x00
.endobj gap_09_805D6C5F_sdata

# .sdata:0x8E8 | 0x805D6C60 | size: 0x5
.obj lbl_805D6C60, global
	.string "jobj"
.endobj lbl_805D6C60

# .sdata:0x8ED | 0x805D6C65 | size: 0x3
.obj gap_09_805D6C65_sdata, global
.hidden gap_09_805D6C65_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6C65_sdata

# .sdata:0x8F0 | 0x805D6C68 | size: 0x6
.obj lbl_805D6C68, global
	.string "scale"
.endobj lbl_805D6C68

# .sdata:0x8F6 | 0x805D6C6E | size: 0x2
.obj gap_09_805D6C6E_sdata, global
.hidden gap_09_805D6C6E_sdata
	.2byte 0x0000
.endobj gap_09_805D6C6E_sdata

# .sdata:0x8F8 | 0x805D6C70 | size: 0x7
.obj kar_srcfile_aobj_h_805d6c70, global
	.string "aobj.h"
.endobj kar_srcfile_aobj_h_805d6c70

# .sdata:0x8FF | 0x805D6C77 | size: 0x1
.obj gap_09_805D6C77_sdata, global
.hidden gap_09_805D6C77_sdata
	.byte 0x00
.endobj gap_09_805D6C77_sdata

# .sdata:0x900 | 0x805D6C78 | size: 0x5
.obj lbl_805D6C78, global
	.string "aobj"
.endobj lbl_805D6C78

# .sdata:0x905 | 0x805D6C7D | size: 0x3
.obj gap_09_805D6C7D_sdata, global
.hidden gap_09_805D6C7D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6C7D_sdata

# .sdata:0x908 | 0x805D6C80 | size: 0x7
.obj kar_srcfile_jobj_h_805d6c80, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6c80

# .sdata:0x90F | 0x805D6C87 | size: 0x1
.obj gap_09_805D6C87_sdata, global
.hidden gap_09_805D6C87_sdata
	.byte 0x00
.endobj gap_09_805D6C87_sdata

# .sdata:0x910 | 0x805D6C88 | size: 0x5
.obj lbl_805D6C88, global
	.string "jobj"
.endobj lbl_805D6C88

# .sdata:0x915 | 0x805D6C8D | size: 0x3
.obj gap_09_805D6C8D_sdata, global
.hidden gap_09_805D6C8D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6C8D_sdata

# .sdata:0x918 | 0x805D6C90 | size: 0x7
.obj kar_srcfile_jobj_h_805d6c90, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6c90

# .sdata:0x91F | 0x805D6C97 | size: 0x1
.obj gap_09_805D6C97_sdata, global
.hidden gap_09_805D6C97_sdata
	.byte 0x00
.endobj gap_09_805D6C97_sdata

# .sdata:0x920 | 0x805D6C98 | size: 0x5
.obj lbl_805D6C98, global
	.string "jobj"
.endobj lbl_805D6C98

# .sdata:0x925 | 0x805D6C9D | size: 0x3
.obj gap_09_805D6C9D_sdata, global
.hidden gap_09_805D6C9D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6C9D_sdata

# .sdata:0x928 | 0x805D6CA0 | size: 0x7
.obj kar_srcfile_jobj_h_805d6ca0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6ca0

# .sdata:0x92F | 0x805D6CA7 | size: 0x1
.obj gap_09_805D6CA7_sdata, global
.hidden gap_09_805D6CA7_sdata
	.byte 0x00
.endobj gap_09_805D6CA7_sdata

# .sdata:0x930 | 0x805D6CA8 | size: 0x5
.obj lbl_805D6CA8, global
	.string "jobj"
.endobj lbl_805D6CA8

# .sdata:0x935 | 0x805D6CAD | size: 0x3
.obj gap_09_805D6CAD_sdata, global
.hidden gap_09_805D6CAD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6CAD_sdata

# .sdata:0x938 | 0x805D6CB0 | size: 0x7
.obj kar_srcfile_jobj_h_805d6cb0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6cb0

# .sdata:0x93F | 0x805D6CB7 | size: 0x1
.obj gap_09_805D6CB7_sdata, global
.hidden gap_09_805D6CB7_sdata
	.byte 0x00
.endobj gap_09_805D6CB7_sdata

# .sdata:0x940 | 0x805D6CB8 | size: 0x5
.obj lbl_805D6CB8, global
	.string "jobj"
.endobj lbl_805D6CB8

# .sdata:0x945 | 0x805D6CBD | size: 0x3
.obj gap_09_805D6CBD_sdata, global
.hidden gap_09_805D6CBD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6CBD_sdata

# .sdata:0x948 | 0x805D6CC0 | size: 0x6
.obj lbl_805D6CC0, global
	.string "scale"
.endobj lbl_805D6CC0

# .sdata:0x94E | 0x805D6CC6 | size: 0x2
.obj gap_09_805D6CC6_sdata, global
.hidden gap_09_805D6CC6_sdata
	.2byte 0x0000
.endobj gap_09_805D6CC6_sdata

# .sdata:0x950 | 0x805D6CC8 | size: 0x7
.obj kar_srcfile_jobj_h_805d6cc8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6cc8

# .sdata:0x957 | 0x805D6CCF | size: 0x1
.obj gap_09_805D6CCF_sdata, global
.hidden gap_09_805D6CCF_sdata
	.byte 0x00
.endobj gap_09_805D6CCF_sdata

# .sdata:0x958 | 0x805D6CD0 | size: 0x5
.obj lbl_805D6CD0, global
	.string "jobj"
.endobj lbl_805D6CD0

# .sdata:0x95D | 0x805D6CD5 | size: 0x3
.obj gap_09_805D6CD5_sdata, global
.hidden gap_09_805D6CD5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6CD5_sdata

# .sdata:0x960 | 0x805D6CD8 | size: 0x6
.obj lbl_805D6CD8, global
	.string "scale"
.endobj lbl_805D6CD8

# .sdata:0x966 | 0x805D6CDE | size: 0x2
.obj gap_09_805D6CDE_sdata, global
.hidden gap_09_805D6CDE_sdata
	.2byte 0x0000
.endobj gap_09_805D6CDE_sdata

# .sdata:0x968 | 0x805D6CE0 | size: 0x7
.obj kar_srcfile_jobj_h_805d6ce0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6ce0

# .sdata:0x96F | 0x805D6CE7 | size: 0x1
.obj gap_09_805D6CE7_sdata, global
.hidden gap_09_805D6CE7_sdata
	.byte 0x00
.endobj gap_09_805D6CE7_sdata

# .sdata:0x970 | 0x805D6CE8 | size: 0x5
.obj lbl_805D6CE8, global
	.string "jobj"
.endobj lbl_805D6CE8

# .sdata:0x975 | 0x805D6CED | size: 0x3
.obj gap_09_805D6CED_sdata, global
.hidden gap_09_805D6CED_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6CED_sdata

# .sdata:0x978 | 0x805D6CF0 | size: 0x6
.obj lbl_805D6CF0, global
	.string "scale"
.endobj lbl_805D6CF0

# .sdata:0x97E | 0x805D6CF6 | size: 0x2
.obj gap_09_805D6CF6_sdata, global
.hidden gap_09_805D6CF6_sdata
	.2byte 0x0000
.endobj gap_09_805D6CF6_sdata

# .sdata:0x980 | 0x805D6CF8 | size: 0x7
.obj kar_srcfile_jobj_h_805d6cf8, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6cf8

# .sdata:0x987 | 0x805D6CFF | size: 0x1
.obj gap_09_805D6CFF_sdata, global
.hidden gap_09_805D6CFF_sdata
	.byte 0x00
.endobj gap_09_805D6CFF_sdata

# .sdata:0x988 | 0x805D6D00 | size: 0x5
.obj lbl_805D6D00, global
	.string "jobj"
.endobj lbl_805D6D00

# .sdata:0x98D | 0x805D6D05 | size: 0x3
.obj gap_09_805D6D05_sdata, global
.hidden gap_09_805D6D05_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6D05_sdata

# .sdata:0x990 | 0x805D6D08 | size: 0x7
.obj kar_srcfile_jobj_h_805d6d08, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6d08

# .sdata:0x997 | 0x805D6D0F | size: 0x1
.obj gap_09_805D6D0F_sdata, global
.hidden gap_09_805D6D0F_sdata
	.byte 0x00
.endobj gap_09_805D6D0F_sdata

# .sdata:0x998 | 0x805D6D10 | size: 0x5
.obj lbl_805D6D10, global
	.string "jobj"
.endobj lbl_805D6D10

# .sdata:0x99D | 0x805D6D15 | size: 0x3
.obj gap_09_805D6D15_sdata, global
.hidden gap_09_805D6D15_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6D15_sdata

# .sdata:0x9A0 | 0x805D6D18 | size: 0x7
.obj kar_srcfile_jobj_h_805d6d18, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6d18

# .sdata:0x9A7 | 0x805D6D1F | size: 0x1
.obj gap_09_805D6D1F_sdata, global
.hidden gap_09_805D6D1F_sdata
	.byte 0x00
.endobj gap_09_805D6D1F_sdata

# .sdata:0x9A8 | 0x805D6D20 | size: 0x5
.obj lbl_805D6D20, global
	.string "jobj"
.endobj lbl_805D6D20

# .sdata:0x9AD | 0x805D6D25 | size: 0x3
.obj gap_09_805D6D25_sdata, global
.hidden gap_09_805D6D25_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6D25_sdata

# .sdata:0x9B0 | 0x805D6D28 | size: 0x7
.obj kar_srcfile_jobj_h_805d6d28, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6d28

# .sdata:0x9B7 | 0x805D6D2F | size: 0x1
.obj gap_09_805D6D2F_sdata, global
.hidden gap_09_805D6D2F_sdata
	.byte 0x00
.endobj gap_09_805D6D2F_sdata

# .sdata:0x9B8 | 0x805D6D30 | size: 0x5
.obj lbl_805D6D30, global
	.string "jobj"
.endobj lbl_805D6D30

# .sdata:0x9BD | 0x805D6D35 | size: 0x3
.obj gap_09_805D6D35_sdata, global
.hidden gap_09_805D6D35_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6D35_sdata

# .sdata:0x9C0 | 0x805D6D38 | size: 0x7
.obj kar_srcfile_jobj_h_805d6d38, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6d38

# .sdata:0x9C7 | 0x805D6D3F | size: 0x1
.obj gap_09_805D6D3F_sdata, global
.hidden gap_09_805D6D3F_sdata
	.byte 0x00
.endobj gap_09_805D6D3F_sdata

# .sdata:0x9C8 | 0x805D6D40 | size: 0x5
.obj lbl_805D6D40, global
	.string "jobj"
.endobj lbl_805D6D40

# .sdata:0x9CD | 0x805D6D45 | size: 0x3
.obj gap_09_805D6D45_sdata, global
.hidden gap_09_805D6D45_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6D45_sdata

# .sdata:0x9D0 | 0x805D6D48 | size: 0x7
.obj kar_srcfile_jobj_h_805d6d48, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6d48

# .sdata:0x9D7 | 0x805D6D4F | size: 0x1
.obj gap_09_805D6D4F_sdata, global
.hidden gap_09_805D6D4F_sdata
	.byte 0x00
.endobj gap_09_805D6D4F_sdata

# .sdata:0x9D8 | 0x805D6D50 | size: 0x5
.obj lbl_805D6D50, global
	.string "jobj"
.endobj lbl_805D6D50

# .sdata:0x9DD | 0x805D6D55 | size: 0x3
.obj gap_09_805D6D55_sdata, global
.hidden gap_09_805D6D55_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6D55_sdata

# .sdata:0x9E0 | 0x805D6D58 | size: 0x7
.obj kar_srcfile_jobj_h_805d6d58, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6d58

# .sdata:0x9E7 | 0x805D6D5F | size: 0x1
.obj gap_09_805D6D5F_sdata, global
.hidden gap_09_805D6D5F_sdata
	.byte 0x00
.endobj gap_09_805D6D5F_sdata

# .sdata:0x9E8 | 0x805D6D60 | size: 0x5
.obj lbl_805D6D60, global
	.string "jobj"
.endobj lbl_805D6D60

# .sdata:0x9ED | 0x805D6D65 | size: 0x3
.obj gap_09_805D6D65_sdata, global
.hidden gap_09_805D6D65_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6D65_sdata

# .sdata:0x9F0 | 0x805D6D68 | size: 0x7
.obj kar_srcfile_jobj_h_805d6d68, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6d68

# .sdata:0x9F7 | 0x805D6D6F | size: 0x1
.obj gap_09_805D6D6F_sdata, global
.hidden gap_09_805D6D6F_sdata
	.byte 0x00
.endobj gap_09_805D6D6F_sdata

# .sdata:0x9F8 | 0x805D6D70 | size: 0x5
.obj lbl_805D6D70, global
	.string "jobj"
.endobj lbl_805D6D70

# .sdata:0x9FD | 0x805D6D75 | size: 0x3
.obj gap_09_805D6D75_sdata, global
.hidden gap_09_805D6D75_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6D75_sdata

# .sdata:0xA00 | 0x805D6D78 | size: 0x7
.obj kar_srcfile_jobj_h_805d6d78, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6d78

# .sdata:0xA07 | 0x805D6D7F | size: 0x1
.obj gap_09_805D6D7F_sdata, global
.hidden gap_09_805D6D7F_sdata
	.byte 0x00
.endobj gap_09_805D6D7F_sdata

# .sdata:0xA08 | 0x805D6D80 | size: 0x5
.obj lbl_805D6D80, global
	.string "jobj"
.endobj lbl_805D6D80

# .sdata:0xA0D | 0x805D6D85 | size: 0x3
.obj gap_09_805D6D85_sdata, global
.hidden gap_09_805D6D85_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6D85_sdata

# .sdata:0xA10 | 0x805D6D88 | size: 0x6
.obj lbl_805D6D88, global
	.string "scale"
.endobj lbl_805D6D88

# .sdata:0xA16 | 0x805D6D8E | size: 0x2
.obj gap_09_805D6D8E_sdata, global
.hidden gap_09_805D6D8E_sdata
	.2byte 0x0000
.endobj gap_09_805D6D8E_sdata

# .sdata:0xA18 | 0x805D6D90 | size: 0x7
.obj kar_srcfile_jobj_h_805d6d90, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6d90

# .sdata:0xA1F | 0x805D6D97 | size: 0x1
.obj gap_09_805D6D97_sdata, global
.hidden gap_09_805D6D97_sdata
	.byte 0x00
.endobj gap_09_805D6D97_sdata

# .sdata:0xA20 | 0x805D6D98 | size: 0x5
.obj lbl_805D6D98, global
	.string "jobj"
.endobj lbl_805D6D98

# .sdata:0xA25 | 0x805D6D9D | size: 0x3
.obj gap_09_805D6D9D_sdata, global
.hidden gap_09_805D6D9D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6D9D_sdata

# .sdata:0xA28 | 0x805D6DA0 | size: 0x7
.obj kar_srcfile_jobj_h_805d6da0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6da0

# .sdata:0xA2F | 0x805D6DA7 | size: 0x1
.obj gap_09_805D6DA7_sdata, global
.hidden gap_09_805D6DA7_sdata
	.byte 0x00
.endobj gap_09_805D6DA7_sdata

# .sdata:0xA30 | 0x805D6DA8 | size: 0x5
.obj lbl_805D6DA8, global
	.string "jobj"
.endobj lbl_805D6DA8

# .sdata:0xA35 | 0x805D6DAD | size: 0x3
.obj gap_09_805D6DAD_sdata, global
.hidden gap_09_805D6DAD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6DAD_sdata

# .sdata:0xA38 | 0x805D6DB0 | size: 0x7
.obj kar_srcfile_jobj_h_805d6db0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6db0

# .sdata:0xA3F | 0x805D6DB7 | size: 0x1
.obj gap_09_805D6DB7_sdata, global
.hidden gap_09_805D6DB7_sdata
	.byte 0x00
.endobj gap_09_805D6DB7_sdata

# .sdata:0xA40 | 0x805D6DB8 | size: 0x5
.obj lbl_805D6DB8, global
	.string "jobj"
.endobj lbl_805D6DB8

# .sdata:0xA45 | 0x805D6DBD | size: 0x3
.obj gap_09_805D6DBD_sdata, global
.hidden gap_09_805D6DBD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6DBD_sdata

# .sdata:0xA48 | 0x805D6DC0 | size: 0x7
.obj kar_srcfile_jobj_h_805d6dc0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6dc0

# .sdata:0xA4F | 0x805D6DC7 | size: 0x1
.obj gap_09_805D6DC7_sdata, global
.hidden gap_09_805D6DC7_sdata
	.byte 0x00
.endobj gap_09_805D6DC7_sdata

# .sdata:0xA50 | 0x805D6DC8 | size: 0x5
.obj lbl_805D6DC8, global
	.string "jobj"
.endobj lbl_805D6DC8

# .sdata:0xA55 | 0x805D6DCD | size: 0x3
.obj gap_09_805D6DCD_sdata, global
.hidden gap_09_805D6DCD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6DCD_sdata

# 0x805DD718..0x805DD748 | size: 0x30
.section .sbss, "wa", @nobits
.balign 8

# .sbss:0x0 | 0x805DD718 | size: 0x4
.obj lbl_805DD718, global
	.skip 0x4
.endobj lbl_805DD718

# .sbss:0x4 | 0x805DD71C | size: 0x4
.obj lbl_805DD71C, global
	.skip 0x4
.endobj lbl_805DD71C

# .sbss:0x8 | 0x805DD720 | size: 0x4
.obj lbl_805DD720, global
	.skip 0x4
.endobj lbl_805DD720

# .sbss:0xC | 0x805DD724 | size: 0x4
.obj lbl_805DD724, global
	.skip 0x4
.endobj lbl_805DD724

# .sbss:0x10 | 0x805DD728 | size: 0x4
.obj lbl_805DD728, global
	.skip 0x4
.endobj lbl_805DD728

# .sbss:0x14 | 0x805DD72C | size: 0x4
.obj lbl_805DD72C, global
	.skip 0x4
.endobj lbl_805DD72C

# .sbss:0x18 | 0x805DD730 | size: 0x4
.obj lbl_805DD730, global
	.skip 0x4
.endobj lbl_805DD730

# .sbss:0x1C | 0x805DD734 | size: 0x4
.obj lbl_805DD734, global
	.skip 0x4
.endobj lbl_805DD734

# .sbss:0x20 | 0x805DD738 | size: 0x8
.obj lbl_805DD738, global
	.skip 0x8
.endobj lbl_805DD738

# .sbss:0x28 | 0x805DD740 | size: 0x8
.obj lbl_805DD740, global
	.skip 0x8
.endobj lbl_805DD740

# 0x805DFAE8..0x805DFB38 | size: 0x50
.section .sdata2, "a"
.balign 8

# .sdata2:0x0 | 0x805DFAE8 | size: 0x4
.obj lbl_805DFAE8, global
	.float 420
.endobj lbl_805DFAE8

# .sdata2:0x4 | 0x805DFAEC | size: 0x4
.obj lbl_805DFAEC, global
	.float 2
.endobj lbl_805DFAEC

# .sdata2:0x8 | 0x805DFAF0 | size: 0x4
.obj lbl_805DFAF0, global
	.float 1
.endobj lbl_805DFAF0

# .sdata2:0xC | 0x805DFAF4 | size: 0x4
.obj lbl_805DFAF4, global
	.float 15
.endobj lbl_805DFAF4

# .sdata2:0x10 | 0x805DFAF8 | size: 0x4
.obj lbl_805DFAF8, global
	.float 390
.endobj lbl_805DFAF8

# .sdata2:0x14 | 0x805DFAFC | size: 0x4
.obj lbl_805DFAFC, global
	.float 330
.endobj lbl_805DFAFC

# .sdata2:0x18 | 0x805DFB00 | size: 0x4
.obj lbl_805DFB00, global
	.float 360
.endobj lbl_805DFB00

# .sdata2:0x1C | 0x805DFB04 | size: 0x4
.obj lbl_805DFB04, global
	.float 240
.endobj lbl_805DFB04

# .sdata2:0x20 | 0x805DFB08 | size: 0x4
.obj lbl_805DFB08, global
	.float 280
.endobj lbl_805DFB08

# .sdata2:0x24 | 0x805DFB0C | size: 0x4
.obj lbl_805DFB0C, global
	.float 200
.endobj lbl_805DFB0C

# .sdata2:0x28 | 0x805DFB10 | size: 0x4
.obj lbl_805DFB10, global
	.float 0
.endobj lbl_805DFB10

# .sdata2:0x2C | 0x805DFB14 | size: 0x4
.obj lbl_805DFB14, global
	.float 1
.endobj lbl_805DFB14

# .sdata2:0x30 | 0x805DFB18 | size: 0x8
.obj lbl_805DFB18, global
	.double 6.283185307179586
.endobj lbl_805DFB18

# .sdata2:0x38 | 0x805DFB20 | size: 0x8
.obj lbl_805DFB20, global
	.float -1
	.float 0
.endobj lbl_805DFB20

# .sdata2:0x40 | 0x805DFB28 | size: 0x4
.obj lbl_805DFB28, global
	.float 1
.endobj lbl_805DFB28

# .sdata2:0x44 | 0x805DFB2C | size: 0x4
.obj lbl_805DFB2C, global
	.float -1
.endobj lbl_805DFB2C

# .sdata2:0x48 | 0x805DFB30 | size: 0x4
.obj lbl_805DFB30, global
	.float 0.017453292
.endobj lbl_805DFB30

# .sdata2:0x4C | 0x805DFB34 | size: 0x4
.obj lbl_805DFB34, global
	.float -1
.endobj lbl_805DFB34
