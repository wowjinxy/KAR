.include "macros.inc"
.file "gryakudownforcezone.c"

# 0x800F9F78..0x800FA3C0 | size: 0x448
.text
.balign 4

# .text:0x0 | 0x800F9F78 | size: 0xCC
.fn kar_gryakudownforcezone_query_force_vector, global
/* 800F9F78 000F6D78  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F9F7C 000F6D7C  7C 08 02 A6 */	mflr r0
/* 800F9F80 000F6D80  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F9F84 000F6D84  39 61 00 20 */	addi r11, r1, 0x20
/* 800F9F88 000F6D88  48 2B 3B CD */	bl _savegpr_27
/* 800F9F8C 000F6D8C  80 CD 05 EC */	lwz r6, lbl_805DD6CC@sda21(r0)
/* 800F9F90 000F6D90  7C 7B 1B 78 */	mr r27, r3
/* 800F9F94 000F6D94  1C 1B 01 40 */	mulli r0, r27, 0x140
/* 800F9F98 000F6D98  7C 9C 23 78 */	mr r28, r4
/* 800F9F9C 000F6D9C  3B E6 00 54 */	addi r31, r6, 0x54
/* 800F9FA0 000F6DA0  80 66 00 74 */	lwz r3, 0x74(r6)
/* 800F9FA4 000F6DA4  7C BD 2B 78 */	mr r29, r5
/* 800F9FA8 000F6DA8  7C 63 02 14 */	add r3, r3, r0
/* 800F9FAC 000F6DAC  80 63 01 38 */	lwz r3, 0x138(r3)
/* 800F9FB0 000F6DB0  28 03 00 00 */	cmplwi r3, 0x0
/* 800F9FB4 000F6DB4  41 82 00 60 */	beq .L_800FA014
/* 800F9FB8 000F6DB8  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 800F9FBC 000F6DBC  80 1E 00 04 */	lwz r0, 0x4(r30)
/* 800F9FC0 000F6DC0  2C 00 00 10 */	cmpwi r0, 0x10
/* 800F9FC4 000F6DC4  41 82 00 1C */	beq .L_800F9FE0
/* 800F9FC8 000F6DC8  3C 60 80 4A */	lis r3, kar_src_gryakudownforcezone_c@ha
/* 800F9FCC 000F6DCC  3C A0 80 4A */	lis r5, kar_gryakudownforcezone_assert_kind_downforcezone@ha
/* 800F9FD0 000F6DD0  38 63 5E FC */	addi r3, r3, kar_src_gryakudownforcezone_c@l
/* 800F9FD4 000F6DD4  38 80 00 AB */	li r4, 0xab
/* 800F9FD8 000F6DD8  38 A5 5F 14 */	addi r5, r5, kar_gryakudownforcezone_assert_kind_downforcezone@l
/* 800F9FDC 000F6DDC  48 32 E4 DD */	bl __assert
.L_800F9FE0:
/* 800F9FE0 000F6DE0  80 DE 00 08 */	lwz r6, 0x8(r30)
/* 800F9FE4 000F6DE4  7F E3 FB 78 */	mr r3, r31
/* 800F9FE8 000F6DE8  7F 64 DB 78 */	mr r4, r27
/* 800F9FEC 000F6DEC  7F 85 E3 78 */	mr r5, r28
/* 800F9FF0 000F6DF0  83 C6 00 00 */	lwz r30, 0x0(r6)
/* 800F9FF4 000F6DF4  4B FD D8 C1 */	bl kar_grcoll__near_800d78b4
/* 800F9FF8 000F6DF8  7F 83 E3 78 */	mr r3, r28
/* 800F9FFC 000F6DFC  7F 84 E3 78 */	mr r4, r28
/* 800FA000 000F6E00  4B F6 8C A5 */	bl kar_lbvector_normalize_with_axis_fallback
/* 800FA004 000F6E04  80 1E 00 0C */	lwz r0, 0xc(r30)
/* 800FA008 000F6E08  90 1D 00 00 */	stw r0, 0x0(r29)
/* 800FA00C 000F6E0C  C0 3E 00 04 */	lfs f1, 0x4(r30)
/* 800FA010 000F6E10  48 00 00 1C */	b .L_800FA02C
.L_800FA014:
/* 800FA014 000F6E14  C0 22 91 A8 */	lfs f1, lbl_805DF8A8@sda21(r0)
/* 800FA018 000F6E18  38 00 FF FF */	li r0, -0x1
/* 800FA01C 000F6E1C  D0 3C 00 00 */	stfs f1, 0x0(r28)
/* 800FA020 000F6E20  D0 3C 00 04 */	stfs f1, 0x4(r28)
/* 800FA024 000F6E24  D0 3C 00 08 */	stfs f1, 0x8(r28)
/* 800FA028 000F6E28  90 1D 00 00 */	stw r0, 0x0(r29)
.L_800FA02C:
/* 800FA02C 000F6E2C  39 61 00 20 */	addi r11, r1, 0x20
/* 800FA030 000F6E30  48 2B 3B 71 */	bl _restgpr_27
/* 800FA034 000F6E34  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FA038 000F6E38  7C 08 03 A6 */	mtlr r0
/* 800FA03C 000F6E3C  38 21 00 20 */	addi r1, r1, 0x20
/* 800FA040 000F6E40  4E 80 00 20 */	blr
.endfn kar_gryakudownforcezone_query_force_vector

# .text:0xCC | 0x800FA044 | size: 0x160
.fn kar_gryakudownforcezone_handle_collision_report_audio, global
/* 800FA044 000F6E44  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800FA048 000F6E48  7C 08 02 A6 */	mflr r0
/* 800FA04C 000F6E4C  90 01 00 34 */	stw r0, 0x34(r1)
/* 800FA050 000F6E50  1C 04 01 40 */	mulli r0, r4, 0x140
/* 800FA054 000F6E54  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 800FA058 000F6E58  93 C1 00 28 */	stw r30, 0x28(r1)
/* 800FA05C 000F6E5C  93 A1 00 24 */	stw r29, 0x24(r1)
/* 800FA060 000F6E60  7C 7D 1B 78 */	mr r29, r3
/* 800FA064 000F6E64  80 AD 05 EC */	lwz r5, lbl_805DD6CC@sda21(r0)
/* 800FA068 000F6E68  80 65 00 74 */	lwz r3, 0x74(r5)
/* 800FA06C 000F6E6C  7C 63 02 14 */	add r3, r3, r0
/* 800FA070 000F6E70  80 63 01 38 */	lwz r3, 0x138(r3)
/* 800FA074 000F6E74  28 03 00 00 */	cmplwi r3, 0x0
/* 800FA078 000F6E78  41 82 01 10 */	beq .L_800FA188
/* 800FA07C 000F6E7C  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800FA080 000F6E80  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800FA084 000F6E84  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800FA088 000F6E88  83 C3 00 00 */	lwz r30, 0x0(r3)
/* 800FA08C 000F6E8C  28 00 00 00 */	cmplwi r0, 0x0
/* 800FA090 000F6E90  41 82 00 F8 */	beq .L_800FA188
/* 800FA094 000F6E94  80 7D 00 04 */	lwz r3, 0x4(r29)
/* 800FA098 000F6E98  C0 02 91 A8 */	lfs f0, lbl_805DF8A8@sda21(r0)
/* 800FA09C 000F6E9C  28 03 00 00 */	cmplwi r3, 0x0
/* 800FA0A0 000F6EA0  D0 01 00 14 */	stfs f0, 0x14(r1)
/* 800FA0A4 000F6EA4  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 800FA0A8 000F6EA8  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 800FA0AC 000F6EAC  41 82 00 34 */	beq .L_800FA0E0
/* 800FA0B0 000F6EB0  A0 03 00 00 */	lhz r0, 0x0(r3)
/* 800FA0B4 000F6EB4  2C 00 00 11 */	cmpwi r0, 0x11
/* 800FA0B8 000F6EB8  41 82 00 14 */	beq .L_800FA0CC
/* 800FA0BC 000F6EBC  40 80 00 24 */	bge .L_800FA0E0
/* 800FA0C0 000F6EC0  2C 00 00 10 */	cmpwi r0, 0x10
/* 800FA0C4 000F6EC4  40 80 00 14 */	bge .L_800FA0D8
/* 800FA0C8 000F6EC8  48 00 00 18 */	b .L_800FA0E0
.L_800FA0CC:
/* 800FA0CC 000F6ECC  38 81 00 14 */	addi r4, r1, 0x14
/* 800FA0D0 000F6ED0  48 09 7A 7D */	bl fn_80191B4C
/* 800FA0D4 000F6ED4  48 00 00 0C */	b .L_800FA0E0
.L_800FA0D8:
/* 800FA0D8 000F6ED8  38 81 00 14 */	addi r4, r1, 0x14
/* 800FA0DC 000F6EDC  48 0C D5 4D */	bl fn_801C7628
.L_800FA0E0:
/* 800FA0E0 000F6EE0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FA0E4 000F6EE4  80 61 00 18 */	lwz r3, 0x18(r1)
/* 800FA0E8 000F6EE8  90 01 00 08 */	stw r0, 0x8(r1)
/* 800FA0EC 000F6EEC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800FA0F0 000F6EF0  C0 41 00 08 */	lfs f2, 0x8(r1)
/* 800FA0F4 000F6EF4  C0 22 91 AC */	lfs f1, lbl_805DF8AC@sda21(r0)
/* 800FA0F8 000F6EF8  90 61 00 0C */	stw r3, 0xc(r1)
/* 800FA0FC 000F6EFC  FC 02 08 40 */	fcmpo cr0, f2, f1
/* 800FA100 000F6F00  90 01 00 10 */	stw r0, 0x10(r1)
/* 800FA104 000F6F04  4C 41 13 82 */	cror eq, gt, eq
/* 800FA108 000F6F08  41 82 00 4C */	beq .L_800FA154
/* 800FA10C 000F6F0C  C0 02 91 B0 */	lfs f0, lbl_805DF8B0@sda21(r0)
/* 800FA110 000F6F10  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 800FA114 000F6F14  4C 40 13 82 */	cror eq, lt, eq
/* 800FA118 000F6F18  41 82 00 3C */	beq .L_800FA154
/* 800FA11C 000F6F1C  C0 41 00 0C */	lfs f2, 0xc(r1)
/* 800FA120 000F6F20  FC 02 08 40 */	fcmpo cr0, f2, f1
/* 800FA124 000F6F24  4C 41 13 82 */	cror eq, gt, eq
/* 800FA128 000F6F28  41 82 00 2C */	beq .L_800FA154
/* 800FA12C 000F6F2C  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 800FA130 000F6F30  4C 40 13 82 */	cror eq, lt, eq
/* 800FA134 000F6F34  41 82 00 20 */	beq .L_800FA154
/* 800FA138 000F6F38  C0 41 00 10 */	lfs f2, 0x10(r1)
/* 800FA13C 000F6F3C  FC 02 08 40 */	fcmpo cr0, f2, f1
/* 800FA140 000F6F40  4C 41 13 82 */	cror eq, gt, eq
/* 800FA144 000F6F44  41 82 00 10 */	beq .L_800FA154
/* 800FA148 000F6F48  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 800FA14C 000F6F4C  4C 40 13 82 */	cror eq, lt, eq
/* 800FA150 000F6F50  40 82 00 0C */	bne .L_800FA15C
.L_800FA154:
/* 800FA154 000F6F54  38 00 00 00 */	li r0, 0x0
/* 800FA158 000F6F58  48 00 00 08 */	b .L_800FA160
.L_800FA15C:
/* 800FA15C 000F6F5C  38 00 00 01 */	li r0, 0x1
.L_800FA160:
/* 800FA160 000F6F60  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FA164 000F6F64  40 82 00 24 */	bne .L_800FA188
/* 800FA168 000F6F68  38 61 00 14 */	addi r3, r1, 0x14
/* 800FA16C 000F6F6C  48 2D 7F ED */	bl fn_803D2158
/* 800FA170 000F6F70  C0 1E 00 08 */	lfs f0, 0x8(r30)
/* 800FA174 000F6F74  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800FA178 000F6F78  40 81 00 10 */	ble .L_800FA188
/* 800FA17C 000F6F7C  7F E3 FB 78 */	mr r3, r31
/* 800FA180 000F6F80  7F A4 EB 78 */	mr r4, r29
/* 800FA184 000F6F84  48 00 00 21 */	bl kar_gryakudownforcezone_play_contact_fgm_at_report
.L_800FA188:
/* 800FA188 000F6F88  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800FA18C 000F6F8C  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800FA190 000F6F90  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 800FA194 000F6F94  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 800FA198 000F6F98  7C 08 03 A6 */	mtlr r0
/* 800FA19C 000F6F9C  38 21 00 30 */	addi r1, r1, 0x30
/* 800FA1A0 000F6FA0  4E 80 00 20 */	blr
.endfn kar_gryakudownforcezone_handle_collision_report_audio

# .text:0x22C | 0x800FA1A4 | size: 0xFC
.fn kar_gryakudownforcezone_play_contact_fgm_at_report, global
/* 800FA1A4 000F6FA4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800FA1A8 000F6FA8  7C 08 02 A6 */	mflr r0
/* 800FA1AC 000F6FAC  38 C4 00 44 */	addi r6, r4, 0x44
/* 800FA1B0 000F6FB0  90 01 00 24 */	stw r0, 0x24(r1)
/* 800FA1B4 000F6FB4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800FA1B8 000F6FB8  7C 7F 1B 78 */	mr r31, r3
/* 800FA1BC 000F6FBC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800FA1C0 000F6FC0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800FA1C4 000F6FC4  93 81 00 10 */	stw r28, 0x10(r1)
/* 800FA1C8 000F6FC8  3B 80 00 00 */	li r28, 0x0
/* 800FA1CC 000F6FCC  80 04 03 1C */	lwz r0, 0x31c(r4)
/* 800FA1D0 000F6FD0  80 AD 05 EC */	lwz r5, lbl_805DD6CC@sda21(r0)
/* 800FA1D4 000F6FD4  7C 09 03 A6 */	mtctr r0
/* 800FA1D8 000F6FD8  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FA1DC 000F6FDC  40 81 00 3C */	ble .L_800FA218
.L_800FA1E0:
/* 800FA1E0 000F6FE0  80 66 00 58 */	lwz r3, 0x58(r6)
/* 800FA1E4 000F6FE4  80 06 00 5C */	lwz r0, 0x5c(r6)
/* 800FA1E8 000F6FE8  1C 63 01 40 */	mulli r3, r3, 0x140
/* 800FA1EC 000F6FEC  80 85 00 74 */	lwz r4, 0x74(r5)
/* 800FA1F0 000F6FF0  1C 00 00 24 */	mulli r0, r0, 0x24
/* 800FA1F4 000F6FF4  7C 63 02 14 */	add r3, r3, r0
/* 800FA1F8 000F6FF8  38 03 00 24 */	addi r0, r3, 0x24
/* 800FA1FC 000F6FFC  7C 04 00 2E */	lwzx r0, r4, r0
/* 800FA200 000F7000  54 00 01 FE */	clrlwi r0, r0, 7
/* 800FA204 000F7004  2C 00 00 11 */	cmpwi r0, 0x11
/* 800FA208 000F7008  40 82 00 08 */	bne .L_800FA210
/* 800FA20C 000F700C  3B 86 00 60 */	addi r28, r6, 0x60
.L_800FA210:
/* 800FA210 000F7010  38 C6 00 20 */	addi r6, r6, 0x20
/* 800FA214 000F7014  42 00 FF CC */	bdnz .L_800FA1E0
.L_800FA218:
/* 800FA218 000F7018  28 1C 00 00 */	cmplwi r28, 0x0
/* 800FA21C 000F701C  41 82 00 64 */	beq .L_800FA280
/* 800FA220 000F7020  3B A0 00 00 */	li r29, 0x0
/* 800FA224 000F7024  7F FE FB 78 */	mr r30, r31
.L_800FA228:
/* 800FA228 000F7028  38 7E 01 34 */	addi r3, r30, 0x134
/* 800FA22C 000F702C  4B FE FF A5 */	bl kar_graudio_is_active_fgm_slot_playing
/* 800FA230 000F7030  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FA234 000F7034  40 82 00 3C */	bne .L_800FA270
/* 800FA238 000F7038  1F DD 00 14 */	mulli r30, r29, 0x14
/* 800FA23C 000F703C  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800FA240 000F7040  7F 85 E3 78 */	mr r5, r28
/* 800FA244 000F7044  80 C3 00 14 */	lwz r6, 0x14(r3)
/* 800FA248 000F7048  7C 9F F2 14 */	add r4, r31, r30
/* 800FA24C 000F704C  80 66 00 0C */	lwz r3, 0xc(r6)
/* 800FA250 000F7050  80 84 01 40 */	lwz r4, 0x140(r4)
/* 800FA254 000F7054  C0 26 00 10 */	lfs f1, 0x10(r6)
/* 800FA258 000F7058  4B FE FC F9 */	bl kar_graudio_configure_fgm_track_mode
/* 800FA25C 000F705C  38 7E 01 34 */	addi r3, r30, 0x134
/* 800FA260 000F7060  38 80 00 00 */	li r4, 0x0
/* 800FA264 000F7064  7C 7F 1A 14 */	add r3, r31, r3
/* 800FA268 000F7068  4B FE FE 1D */	bl kar_graudio_play_fgm_entry_id
/* 800FA26C 000F706C  48 00 00 14 */	b .L_800FA280
.L_800FA270:
/* 800FA270 000F7070  3B BD 00 01 */	addi r29, r29, 0x1
/* 800FA274 000F7074  3B DE 00 14 */	addi r30, r30, 0x14
/* 800FA278 000F7078  2C 1D 00 04 */	cmpwi r29, 0x4
/* 800FA27C 000F707C  41 80 FF AC */	blt .L_800FA228
.L_800FA280:
/* 800FA280 000F7080  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FA284 000F7084  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800FA288 000F7088  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800FA28C 000F708C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800FA290 000F7090  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800FA294 000F7094  7C 08 03 A6 */	mtlr r0
/* 800FA298 000F7098  38 21 00 20 */	addi r1, r1, 0x20
/* 800FA29C 000F709C  4E 80 00 20 */	blr
.endfn kar_gryakudownforcezone_play_contact_fgm_at_report

# .text:0x328 | 0x800FA2A0 | size: 0x38
.fn kar_gryakudownforcezone_create_stage_linked_kind17_yaku, global
/* 800FA2A0 000F70A0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FA2A4 000F70A4  7C 08 02 A6 */	mflr r0
/* 800FA2A8 000F70A8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FA2AC 000F70AC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FA2B0 000F70B0  7C 7F 1B 78 */	mr r31, r3
/* 800FA2B4 000F70B4  38 60 00 11 */	li r3, 0x11
/* 800FA2B8 000F70B8  4B FF A1 B5 */	bl kar_gryaku_create_yaku_from_main_kind
/* 800FA2BC 000F70BC  7F E4 FB 78 */	mr r4, r31
/* 800FA2C0 000F70C0  48 00 00 19 */	bl kar_gryakudownforcezone_init_stage_linked_kind17_yaku
/* 800FA2C4 000F70C4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FA2C8 000F70C8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FA2CC 000F70CC  7C 08 03 A6 */	mtlr r0
/* 800FA2D0 000F70D0  38 21 00 10 */	addi r1, r1, 0x10
/* 800FA2D4 000F70D4  4E 80 00 20 */	blr
.endfn kar_gryakudownforcezone_create_stage_linked_kind17_yaku

# .text:0x360 | 0x800FA2D8 | size: 0xA0
.fn kar_gryakudownforcezone_init_stage_linked_kind17_yaku, global
/* 800FA2D8 000F70D8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800FA2DC 000F70DC  7C 08 02 A6 */	mflr r0
/* 800FA2E0 000F70E0  38 A0 00 00 */	li r5, 0x0
/* 800FA2E4 000F70E4  90 01 00 24 */	stw r0, 0x24(r1)
/* 800FA2E8 000F70E8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800FA2EC 000F70EC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800FA2F0 000F70F0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800FA2F4 000F70F4  7C 7D 1B 78 */	mr r29, r3
/* 800FA2F8 000F70F8  83 FD 00 2C */	lwz r31, 0x2c(r29)
/* 800FA2FC 000F70FC  80 64 00 2C */	lwz r3, 0x2c(r4)
/* 800FA300 000F7100  80 FF 00 08 */	lwz r7, 0x8(r31)
/* 800FA304 000F7104  80 83 01 04 */	lwz r4, 0x104(r3)
/* 800FA308 000F7108  83 C7 00 00 */	lwz r30, 0x0(r7)
/* 800FA30C 000F710C  80 CD 05 EC */	lwz r6, lbl_805DD6CC@sda21(r0)
/* 800FA310 000F7110  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 800FA314 000F7114  38 66 00 54 */	addi r3, r6, 0x54
/* 800FA318 000F7118  54 00 18 38 */	slwi r0, r0, 3
/* 800FA31C 000F711C  7C 84 00 2E */	lwzx r4, r4, r0
/* 800FA320 000F7120  4B FD D6 A1 */	bl kar_grcoll__800d79c0
/* 800FA324 000F7124  90 7F 01 30 */	stw r3, 0x130(r31)
/* 800FA328 000F7128  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 800FA32C 000F712C  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 800FA330 000F7130  90 03 01 38 */	stw r0, 0x138(r3)
/* 800FA334 000F7134  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800FA338 000F7138  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800FA33C 000F713C  28 00 00 00 */	cmplwi r0, 0x0
/* 800FA340 000F7140  41 82 00 14 */	beq .L_800FA354
/* 800FA344 000F7144  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 800FA348 000F7148  7F A3 EB 78 */	mr r3, r29
/* 800FA34C 000F714C  38 A0 00 00 */	li r5, 0x0
/* 800FA350 000F7150  4B FF D5 21 */	bl kar_gryakuaudio_configure_fgm_track_from_joint
.L_800FA354:
/* 800FA354 000F7154  7F A3 EB 78 */	mr r3, r29
/* 800FA358 000F7158  48 00 00 21 */	bl kar_gryakudownforcezone_start_path_motion
/* 800FA35C 000F715C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FA360 000F7160  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800FA364 000F7164  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800FA368 000F7168  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800FA36C 000F716C  7C 08 03 A6 */	mtlr r0
/* 800FA370 000F7170  38 21 00 20 */	addi r1, r1, 0x20
/* 800FA374 000F7174  4E 80 00 20 */	blr
.endfn kar_gryakudownforcezone_init_stage_linked_kind17_yaku

# .text:0x400 | 0x800FA378 | size: 0x48
.fn kar_gryakudownforcezone_start_path_motion, global
/* 800FA378 000F7178  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FA37C 000F717C  7C 08 02 A6 */	mflr r0
/* 800FA380 000F7180  C0 22 91 B8 */	lfs f1, lbl_805DF8B8@sda21(r0)
/* 800FA384 000F7184  38 80 00 00 */	li r4, 0x0
/* 800FA388 000F7188  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FA38C 000F718C  38 A0 FF FF */	li r5, -0x1
/* 800FA390 000F7190  FC 40 08 90 */	fmr f2, f1
/* 800FA394 000F7194  38 E0 00 00 */	li r7, 0x0
/* 800FA398 000F7198  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FA39C 000F719C  FC 60 08 90 */	fmr f3, f1
/* 800FA3A0 000F71A0  80 C3 00 08 */	lwz r6, 0x8(r3)
/* 800FA3A4 000F71A4  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 800FA3A8 000F71A8  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 800FA3AC 000F71AC  4B FF B1 9D */	bl kar_gryaku_set_path_node_motion
/* 800FA3B0 000F71B0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FA3B4 000F71B4  7C 08 03 A6 */	mtlr r0
/* 800FA3B8 000F71B8  38 21 00 10 */	addi r1, r1, 0x10
/* 800FA3BC 000F71BC  4E 80 00 20 */	blr
.endfn kar_gryakudownforcezone_start_path_motion

# 0x804A5EFC..0x804A5F64 | size: 0x68
.data
.balign 4

# .data:0x0 | 0x804A5EFC | size: 0x16
.obj kar_src_gryakudownforcezone_c, global
	.string "gryakudownforcezone.c"
.endobj kar_src_gryakudownforcezone_c

# .data:0x16 | 0x804A5F12 | size: 0x2
.obj gap_07_804A5F12_data, global
.hidden gap_07_804A5F12_data
	.2byte 0x0000
.endobj gap_07_804A5F12_data

# .data:0x18 | 0x804A5F14 | size: 0x27
.obj kar_gryakudownforcezone_assert_kind_downforcezone, global
	.string "gyp->kind == Gr_YakuKind_DownForceZone"
.endobj kar_gryakudownforcezone_assert_kind_downforcezone

# .data:0x3F | 0x804A5F3B | size: 0x5
.obj gap_07_804A5F3B_data, global
.hidden gap_07_804A5F3B_data
	.4byte 0x00000000
	.byte 0x00
.endobj gap_07_804A5F3B_data

# .data:0x44 | 0x804A5F40 | size: 0x10
.obj lbl_804A5F40, global
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A5F40

# .data:0x54 | 0x804A5F50 | size: 0x14
.obj lbl_804A5F50, global
	.4byte lbl_804A5F40
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804A5F50

# 0x805DF8AC..0x805DF8C0 | size: 0x14
.section .sdata2, "a"
.balign 4

# .sdata2:0x0 | 0x805DF8AC | size: 0x4
.obj lbl_805DF8AC, global
	.float 0.00001
.endobj lbl_805DF8AC

# .sdata2:0x4 | 0x805DF8B0 | size: 0x8
.obj lbl_805DF8B0, global
	.float -0.00001
	.float 0
.endobj lbl_805DF8B0

# .sdata2:0xC | 0x805DF8B8 | size: 0x8
.obj lbl_805DF8B8, global
	.float 0
	.float 0
.endobj lbl_805DF8B8
