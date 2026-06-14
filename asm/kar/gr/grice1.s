.include "macros.inc"
.file "grice1.c"

# 0x8010ED44..0x8010F114 | size: 0x3D0
.text
.balign 4

# .text:0x0 | 0x8010ED44 | size: 0xB4
.fn kar_grice1_init_switch_group_and_individual_fgm_ids, global
/* 8010ED44 0010BB44  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8010ED48 0010BB48  7C 08 02 A6 */	mflr r0
/* 8010ED4C 0010BB4C  38 A0 00 03 */	li r5, 0x3
/* 8010ED50 0010BB50  90 01 00 24 */	stw r0, 0x24(r1)
/* 8010ED54 0010BB54  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8010ED58 0010BB58  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8010ED5C 0010BB5C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8010ED60 0010BB60  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 8010ED64 0010BB64  3C 60 80 4A */	lis r3, kar_grice1_callback_table@ha
/* 8010ED68 0010BB68  3B E3 77 70 */	addi r31, r3, kar_grice1_callback_table@l
/* 8010ED6C 0010BB6C  80 DE 00 08 */	lwz r6, 0x8(r30)
/* 8010ED70 0010BB70  7F C3 F3 78 */	mr r3, r30
/* 8010ED74 0010BB74  38 9F 00 0C */	addi r4, r31, 0xc
/* 8010ED78 0010BB78  83 A6 00 08 */	lwz r29, 0x8(r6)
/* 8010ED7C 0010BB7C  4B FD 98 2D */	bl kar_grswitch__800e85a8
/* 8010ED80 0010BB80  80 7D 00 00 */	lwz r3, 0x0(r29)
/* 8010ED84 0010BB84  80 03 00 04 */	lwz r0, 0x4(r3)
/* 8010ED88 0010BB88  2C 00 00 0A */	cmpwi r0, 0xa
/* 8010ED8C 0010BB8C  40 81 00 14 */	ble .L_8010EDA0
/* 8010ED90 0010BB90  38 7F 00 18 */	addi r3, r31, 0x18
/* 8010ED94 0010BB94  38 BF 00 24 */	addi r5, r31, 0x24
/* 8010ED98 0010BB98  38 80 00 3C */	li r4, 0x3c
/* 8010ED9C 0010BB9C  48 31 97 1D */	bl __assert
.L_8010EDA0:
/* 8010EDA0 0010BBA0  7F C5 F3 78 */	mr r5, r30
/* 8010EDA4 0010BBA4  38 C0 00 00 */	li r6, 0x0
/* 8010EDA8 0010BBA8  38 80 00 00 */	li r4, 0x0
/* 8010EDAC 0010BBAC  48 00 00 20 */	b .L_8010EDCC
.L_8010EDB0:
/* 8010EDB0 0010BBB0  80 63 00 00 */	lwz r3, 0x0(r3)
/* 8010EDB4 0010BBB4  38 04 00 08 */	addi r0, r4, 0x8
/* 8010EDB8 0010BBB8  38 84 00 10 */	addi r4, r4, 0x10
/* 8010EDBC 0010BBBC  38 C6 00 01 */	addi r6, r6, 0x1
/* 8010EDC0 0010BBC0  7C 03 00 2E */	lwzx r0, r3, r0
/* 8010EDC4 0010BBC4  90 05 07 28 */	stw r0, 0x728(r5)
/* 8010EDC8 0010BBC8  38 A5 00 04 */	addi r5, r5, 0x4
.L_8010EDCC:
/* 8010EDCC 0010BBCC  80 7D 00 00 */	lwz r3, 0x0(r29)
/* 8010EDD0 0010BBD0  80 03 00 04 */	lwz r0, 0x4(r3)
/* 8010EDD4 0010BBD4  7C 06 00 00 */	cmpw r6, r0
/* 8010EDD8 0010BBD8  41 80 FF D8 */	blt .L_8010EDB0
/* 8010EDDC 0010BBDC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8010EDE0 0010BBE0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8010EDE4 0010BBE4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8010EDE8 0010BBE8  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8010EDEC 0010BBEC  7C 08 03 A6 */	mtlr r0
/* 8010EDF0 0010BBF0  38 21 00 20 */	addi r1, r1, 0x20
/* 8010EDF4 0010BBF4  4E 80 00 20 */	blr
.endfn kar_grice1_init_switch_group_and_individual_fgm_ids

# .text:0xB4 | 0x8010EDF8 | size: 0x21C
.fn kar_grice1_create_stage_ice_yaku_objects, global
/* 8010EDF8 0010BBF8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010EDFC 0010BBFC  7C 08 02 A6 */	mflr r0
/* 8010EE00 0010BC00  38 80 00 00 */	li r4, 0x0
/* 8010EE04 0010BC04  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010EE08 0010BC08  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010EE0C 0010BC0C  7C 7F 1B 78 */	mr r31, r3
/* 8010EE10 0010BC10  4B FF 06 FD */	bl kar_gryakupushoutwall_create_stage_linked_kind49_wall
/* 8010EE14 0010BC14  7F E3 FB 78 */	mr r3, r31
/* 8010EE18 0010BC18  38 80 00 01 */	li r4, 0x1
/* 8010EE1C 0010BC1C  4B FF 06 F1 */	bl kar_gryakupushoutwall_create_stage_linked_kind49_wall
/* 8010EE20 0010BC20  7F E3 FB 78 */	mr r3, r31
/* 8010EE24 0010BC24  38 80 00 02 */	li r4, 0x2
/* 8010EE28 0010BC28  4B FF 06 E5 */	bl kar_gryakupushoutwall_create_stage_linked_kind49_wall
/* 8010EE2C 0010BC2C  7F E3 FB 78 */	mr r3, r31
/* 8010EE30 0010BC30  38 80 00 03 */	li r4, 0x3
/* 8010EE34 0010BC34  4B FF 06 D9 */	bl kar_gryakupushoutwall_create_stage_linked_kind49_wall
/* 8010EE38 0010BC38  7F E3 FB 78 */	mr r3, r31
/* 8010EE3C 0010BC3C  38 80 00 04 */	li r4, 0x4
/* 8010EE40 0010BC40  4B FF 06 CD */	bl kar_gryakupushoutwall_create_stage_linked_kind49_wall
/* 8010EE44 0010BC44  7F E3 FB 78 */	mr r3, r31
/* 8010EE48 0010BC48  38 80 00 05 */	li r4, 0x5
/* 8010EE4C 0010BC4C  4B FF 06 C1 */	bl kar_gryakupushoutwall_create_stage_linked_kind49_wall
/* 8010EE50 0010BC50  7F E3 FB 78 */	mr r3, r31
/* 8010EE54 0010BC54  38 80 00 06 */	li r4, 0x6
/* 8010EE58 0010BC58  4B FF 0E AD */	bl kar_gryakupushoutwall_create_stage_linked_kind50_switch_controller
/* 8010EE5C 0010BC5C  7F E3 FB 78 */	mr r3, r31
/* 8010EE60 0010BC60  38 80 00 07 */	li r4, 0x7
/* 8010EE64 0010BC64  4B FE B8 A5 */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010EE68 0010BC68  7F E3 FB 78 */	mr r3, r31
/* 8010EE6C 0010BC6C  38 80 00 08 */	li r4, 0x8
/* 8010EE70 0010BC70  4B FE B8 99 */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010EE74 0010BC74  7F E3 FB 78 */	mr r3, r31
/* 8010EE78 0010BC78  38 80 00 09 */	li r4, 0x9
/* 8010EE7C 0010BC7C  4B FE B8 8D */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010EE80 0010BC80  7F E3 FB 78 */	mr r3, r31
/* 8010EE84 0010BC84  38 80 00 0A */	li r4, 0xa
/* 8010EE88 0010BC88  4B FE B8 81 */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010EE8C 0010BC8C  7F E3 FB 78 */	mr r3, r31
/* 8010EE90 0010BC90  38 80 00 0B */	li r4, 0xb
/* 8010EE94 0010BC94  4B FE B8 75 */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010EE98 0010BC98  7F E3 FB 78 */	mr r3, r31
/* 8010EE9C 0010BC9C  38 80 00 0C */	li r4, 0xc
/* 8010EEA0 0010BCA0  4B FE B8 69 */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010EEA4 0010BCA4  7F E3 FB 78 */	mr r3, r31
/* 8010EEA8 0010BCA8  38 80 00 0D */	li r4, 0xd
/* 8010EEAC 0010BCAC  4B FE B8 5D */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010EEB0 0010BCB0  7F E3 FB 78 */	mr r3, r31
/* 8010EEB4 0010BCB4  38 80 00 0E */	li r4, 0xe
/* 8010EEB8 0010BCB8  4B FE B8 51 */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010EEBC 0010BCBC  7F E3 FB 78 */	mr r3, r31
/* 8010EEC0 0010BCC0  38 80 00 0F */	li r4, 0xf
/* 8010EEC4 0010BCC4  4B FE B8 45 */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010EEC8 0010BCC8  7F E3 FB 78 */	mr r3, r31
/* 8010EECC 0010BCCC  38 80 00 10 */	li r4, 0x10
/* 8010EED0 0010BCD0  4B FE B8 39 */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010EED4 0010BCD4  7F E3 FB 78 */	mr r3, r31
/* 8010EED8 0010BCD8  38 80 00 11 */	li r4, 0x11
/* 8010EEDC 0010BCDC  4B FF 3D 65 */	bl kar_gryakubreakhouse_create_stage_linked_kind54_animfloor
/* 8010EEE0 0010BCE0  7F E3 FB 78 */	mr r3, r31
/* 8010EEE4 0010BCE4  38 80 00 12 */	li r4, 0x12
/* 8010EEE8 0010BCE8  4B FF 3D 59 */	bl kar_gryakubreakhouse_create_stage_linked_kind54_animfloor
/* 8010EEEC 0010BCEC  7F E3 FB 78 */	mr r3, r31
/* 8010EEF0 0010BCF0  38 80 00 13 */	li r4, 0x13
/* 8010EEF4 0010BCF4  4B FF 3D 4D */	bl kar_gryakubreakhouse_create_stage_linked_kind54_animfloor
/* 8010EEF8 0010BCF8  7F E3 FB 78 */	mr r3, r31
/* 8010EEFC 0010BCFC  38 80 00 14 */	li r4, 0x14
/* 8010EF00 0010BD00  4B FF 72 45 */	bl kar_gryakubreakcommon_create_stage_linked_kind57_lasergate
/* 8010EF04 0010BD04  7F E3 FB 78 */	mr r3, r31
/* 8010EF08 0010BD08  38 80 00 15 */	li r4, 0x15
/* 8010EF0C 0010BD0C  4B FF 72 39 */	bl kar_gryakubreakcommon_create_stage_linked_kind57_lasergate
/* 8010EF10 0010BD10  7F E3 FB 78 */	mr r3, r31
/* 8010EF14 0010BD14  38 80 00 16 */	li r4, 0x16
/* 8010EF18 0010BD18  4B FF 72 2D */	bl kar_gryakubreakcommon_create_stage_linked_kind57_lasergate
/* 8010EF1C 0010BD1C  7F E3 FB 78 */	mr r3, r31
/* 8010EF20 0010BD20  38 80 00 17 */	li r4, 0x17
/* 8010EF24 0010BD24  4B FF 72 21 */	bl kar_gryakubreakcommon_create_stage_linked_kind57_lasergate
/* 8010EF28 0010BD28  7F E3 FB 78 */	mr r3, r31
/* 8010EF2C 0010BD2C  38 80 00 18 */	li r4, 0x18
/* 8010EF30 0010BD30  4B FF 74 8D */	bl kar_gryakubreakcommon_create_stage_linked_kind58_lasergate_ctrl
/* 8010EF34 0010BD34  7F E3 FB 78 */	mr r3, r31
/* 8010EF38 0010BD38  38 80 00 19 */	li r4, 0x19
/* 8010EF3C 0010BD3C  4B FF 78 E9 */	bl kar_gryakulasergate_create_stage_linked_kind32_breakfloor
/* 8010EF40 0010BD40  7F E3 FB 78 */	mr r3, r31
/* 8010EF44 0010BD44  38 80 00 1A */	li r4, 0x1a
/* 8010EF48 0010BD48  4B FF 78 DD */	bl kar_gryakulasergate_create_stage_linked_kind32_breakfloor
/* 8010EF4C 0010BD4C  7F E3 FB 78 */	mr r3, r31
/* 8010EF50 0010BD50  38 80 00 1B */	li r4, 0x1b
/* 8010EF54 0010BD54  4B FF 78 D1 */	bl kar_gryakulasergate_create_stage_linked_kind32_breakfloor
/* 8010EF58 0010BD58  7F E3 FB 78 */	mr r3, r31
/* 8010EF5C 0010BD5C  38 80 00 1C */	li r4, 0x1c
/* 8010EF60 0010BD60  4B FF 78 C5 */	bl kar_gryakulasergate_create_stage_linked_kind32_breakfloor
/* 8010EF64 0010BD64  7F E3 FB 78 */	mr r3, r31
/* 8010EF68 0010BD68  38 80 00 1D */	li r4, 0x1d
/* 8010EF6C 0010BD6C  4B FF 78 B9 */	bl kar_gryakulasergate_create_stage_linked_kind32_breakfloor
/* 8010EF70 0010BD70  7F E3 FB 78 */	mr r3, r31
/* 8010EF74 0010BD74  38 80 00 1E */	li r4, 0x1e
/* 8010EF78 0010BD78  4B FF 78 AD */	bl kar_gryakulasergate_create_stage_linked_kind32_breakfloor
/* 8010EF7C 0010BD7C  7F E3 FB 78 */	mr r3, r31
/* 8010EF80 0010BD80  38 80 00 1F */	li r4, 0x1f
/* 8010EF84 0010BD84  4B FF 55 49 */	bl kar_gryakubreakcoral_create_stage_linked_kind31_breakicicle
/* 8010EF88 0010BD88  7F E3 FB 78 */	mr r3, r31
/* 8010EF8C 0010BD8C  38 80 00 20 */	li r4, 0x20
/* 8010EF90 0010BD90  4B FF 55 3D */	bl kar_gryakubreakcoral_create_stage_linked_kind31_breakicicle
/* 8010EF94 0010BD94  7F E3 FB 78 */	mr r3, r31
/* 8010EF98 0010BD98  38 80 00 21 */	li r4, 0x21
/* 8010EF9C 0010BD9C  4B FF 55 31 */	bl kar_gryakubreakcoral_create_stage_linked_kind31_breakicicle
/* 8010EFA0 0010BDA0  7F E3 FB 78 */	mr r3, r31
/* 8010EFA4 0010BDA4  38 80 00 22 */	li r4, 0x22
/* 8010EFA8 0010BDA8  4B FF 55 25 */	bl kar_gryakubreakcoral_create_stage_linked_kind31_breakicicle
/* 8010EFAC 0010BDAC  7F E3 FB 78 */	mr r3, r31
/* 8010EFB0 0010BDB0  38 80 00 23 */	li r4, 0x23
/* 8010EFB4 0010BDB4  4B FF 55 19 */	bl kar_gryakubreakcoral_create_stage_linked_kind31_breakicicle
/* 8010EFB8 0010BDB8  7F E3 FB 78 */	mr r3, r31
/* 8010EFBC 0010BDBC  38 80 00 24 */	li r4, 0x24
/* 8010EFC0 0010BDC0  4B FF 55 0D */	bl kar_gryakubreakcoral_create_stage_linked_kind31_breakicicle
/* 8010EFC4 0010BDC4  7F E3 FB 78 */	mr r3, r31
/* 8010EFC8 0010BDC8  38 80 00 25 */	li r4, 0x25
/* 8010EFCC 0010BDCC  4B FF 22 FD */	bl kar_gryakupillar_create_stage_linked_kind39_ice_pillar
/* 8010EFD0 0010BDD0  7F E3 FB 78 */	mr r3, r31
/* 8010EFD4 0010BDD4  38 80 00 26 */	li r4, 0x26
/* 8010EFD8 0010BDD8  4B FF 22 F1 */	bl kar_gryakupillar_create_stage_linked_kind39_ice_pillar
/* 8010EFDC 0010BDDC  7F E3 FB 78 */	mr r3, r31
/* 8010EFE0 0010BDE0  38 80 00 27 */	li r4, 0x27
/* 8010EFE4 0010BDE4  4B FF 22 E5 */	bl kar_gryakupillar_create_stage_linked_kind39_ice_pillar
/* 8010EFE8 0010BDE8  7F E3 FB 78 */	mr r3, r31
/* 8010EFEC 0010BDEC  38 80 00 28 */	li r4, 0x28
/* 8010EFF0 0010BDF0  4B FF 22 D9 */	bl kar_gryakupillar_create_stage_linked_kind39_ice_pillar
/* 8010EFF4 0010BDF4  7F E3 FB 78 */	mr r3, r31
/* 8010EFF8 0010BDF8  38 80 00 29 */	li r4, 0x29
/* 8010EFFC 0010BDFC  4B FF 12 29 */	bl kar_gryakupushoutwall_create_stage_linked_kind51_lightzone_controller
/* 8010F000 0010BE00  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F004 0010BE04  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010F008 0010BE08  7C 08 03 A6 */	mtlr r0
/* 8010F00C 0010BE0C  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F010 0010BE10  4E 80 00 20 */	blr
.endfn kar_grice1_create_stage_ice_yaku_objects

# .text:0x2D0 | 0x8010F014 | size: 0x58
.fn kar_grice1_update_individual_fgm_timers, global
/* 8010F014 0010BE14  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F018 0010BE18  7C 08 02 A6 */	mflr r0
/* 8010F01C 0010BE1C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F020 0010BE20  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010F024 0010BE24  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8010F028 0010BE28  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8010F02C 0010BE2C  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 8010F030 0010BE30  7F E3 FB 78 */	mr r3, r31
/* 8010F034 0010BE34  83 C4 00 08 */	lwz r30, 0x8(r4)
/* 8010F038 0010BE38  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 8010F03C 0010BE3C  4B FD B3 AD */	bl kar_graudio_configure_individual_fgm_tracks
/* 8010F040 0010BE40  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 8010F044 0010BE44  7F E3 FB 78 */	mr r3, r31
/* 8010F048 0010BE48  38 BF 07 28 */	addi r5, r31, 0x728
/* 8010F04C 0010BE4C  38 C0 00 0A */	li r6, 0xa
/* 8010F050 0010BE50  4B FD B5 19 */	bl kar_graudio_update_individual_fgm_timers
/* 8010F054 0010BE54  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F058 0010BE58  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010F05C 0010BE5C  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8010F060 0010BE60  7C 08 03 A6 */	mtlr r0
/* 8010F064 0010BE64  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F068 0010BE68  4E 80 00 20 */	blr
.endfn kar_grice1_update_individual_fgm_timers

# .text:0x328 | 0x8010F06C | size: 0x38
.fn kar_grice1_switch_trigger_pushoutwall_targets_by_stage_index, global
/* 8010F06C 0010BE6C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F070 0010BE70  7C 08 02 A6 */	mflr r0
/* 8010F074 0010BE74  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F078 0010BE78  1C 04 00 48 */	mulli r0, r4, 0x48
/* 8010F07C 0010BE7C  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 8010F080 0010BE80  7C 63 02 14 */	add r3, r3, r0
/* 8010F084 0010BE84  80 63 02 18 */	lwz r3, 0x218(r3)
/* 8010F088 0010BE88  28 03 00 00 */	cmplwi r3, 0x0
/* 8010F08C 0010BE8C  41 82 00 08 */	beq .L_8010F094
/* 8010F090 0010BE90  4B FF 0F F5 */	bl kar_gryakupushoutwall_trigger_kind50_target_wall_pushes
.L_8010F094:
/* 8010F094 0010BE94  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F098 0010BE98  7C 08 03 A6 */	mtlr r0
/* 8010F09C 0010BE9C  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F0A0 0010BEA0  4E 80 00 20 */	blr
.endfn kar_grice1_switch_trigger_pushoutwall_targets_by_stage_index

# .text:0x360 | 0x8010F0A4 | size: 0x38
.fn kar_grice1_switch_trigger_lighttunnel_pillar_entry_by_stage_index, global
/* 8010F0A4 0010BEA4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F0A8 0010BEA8  7C 08 02 A6 */	mflr r0
/* 8010F0AC 0010BEAC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F0B0 0010BEB0  1C 04 00 48 */	mulli r0, r4, 0x48
/* 8010F0B4 0010BEB4  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 8010F0B8 0010BEB8  7C 63 02 14 */	add r3, r3, r0
/* 8010F0BC 0010BEBC  80 63 02 18 */	lwz r3, 0x218(r3)
/* 8010F0C0 0010BEC0  28 03 00 00 */	cmplwi r3, 0x0
/* 8010F0C4 0010BEC4  41 82 00 08 */	beq .L_8010F0CC
/* 8010F0C8 0010BEC8  4B FF 16 2D */	bl kar_gryakulighttunnel_trigger_kind52_pillar_entry_motion
.L_8010F0CC:
/* 8010F0CC 0010BECC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F0D0 0010BED0  7C 08 03 A6 */	mtlr r0
/* 8010F0D4 0010BED4  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F0D8 0010BED8  4E 80 00 20 */	blr
.endfn kar_grice1_switch_trigger_lighttunnel_pillar_entry_by_stage_index

# .text:0x398 | 0x8010F0DC | size: 0x38
.fn kar_grice1_switch_trigger_lasergate_ctrl_open_by_stage_index, global
/* 8010F0DC 0010BEDC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010F0E0 0010BEE0  7C 08 02 A6 */	mflr r0
/* 8010F0E4 0010BEE4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010F0E8 0010BEE8  1C 04 00 48 */	mulli r0, r4, 0x48
/* 8010F0EC 0010BEEC  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 8010F0F0 0010BEF0  7C 63 02 14 */	add r3, r3, r0
/* 8010F0F4 0010BEF4  80 63 02 18 */	lwz r3, 0x218(r3)
/* 8010F0F8 0010BEF8  28 03 00 00 */	cmplwi r3, 0x0
/* 8010F0FC 0010BEFC  41 82 00 08 */	beq .L_8010F104
/* 8010F100 0010BF00  4B FF 75 59 */	bl kar_gryakulasergate_trigger_kind58_ctrl_open_linked_gates
.L_8010F104:
/* 8010F104 0010BF04  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010F108 0010BF08  7C 08 03 A6 */	mtlr r0
/* 8010F10C 0010BF0C  38 21 00 10 */	addi r1, r1, 0x10
/* 8010F110 0010BF10  4E 80 00 20 */	blr
.endfn kar_grice1_switch_trigger_lasergate_ctrl_open_by_stage_index

# 0x804A7770..0x804A77D8 | size: 0x68
.data
.balign 8

# .data:0x0 | 0x804A7770 | size: 0x68
.obj kar_grice1_callback_table, global
	.4byte kar_grice1_init_switch_group_and_individual_fgm_ids
	.4byte kar_grice1_create_stage_ice_yaku_objects
	.4byte kar_grice1_update_individual_fgm_timers
	.4byte kar_grice1_switch_trigger_pushoutwall_targets_by_stage_index
	.4byte kar_grice1_switch_trigger_lighttunnel_pillar_entry_by_stage_index
	.4byte kar_grice1_switch_trigger_lasergate_ctrl_open_by_stage_index
	.4byte 0x67726963
	.4byte 0x65312E63
	.4byte 0x00000000
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
	.4byte 0x72496365
	.4byte 0x315F4667
	.4byte 0x6D436F75
	.4byte 0x6E746572
	.4byte 0x4E756D00
	.4byte 0x00000000
.endobj kar_grice1_callback_table
