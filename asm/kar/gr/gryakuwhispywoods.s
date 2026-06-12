.include "macros.inc"
.file "gryakuwhispywoods.c"

# 0x8010DB9C..0x8010E0E4 | size: 0x548
.text
.balign 4

# .text:0x0 | 0x8010DB9C | size: 0xFC
.fn kar_gryakuwhispywoods_init_kind69_collision_wait_state, global
/* 8010DB9C 0010A99C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8010DBA0 0010A9A0  7C 08 02 A6 */	mflr r0
/* 8010DBA4 0010A9A4  90 01 00 24 */	stw r0, 0x24(r1)
/* 8010DBA8 0010A9A8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8010DBAC 0010A9AC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8010DBB0 0010A9B0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8010DBB4 0010A9B4  7C 7D 1B 78 */	mr r29, r3
/* 8010DBB8 0010A9B8  83 FD 00 2C */	lwz r31, 0x2c(r29)
/* 8010DBBC 0010A9BC  80 64 00 2C */	lwz r3, 0x2c(r4)
/* 8010DBC0 0010A9C0  80 DF 00 08 */	lwz r6, 0x8(r31)
/* 8010DBC4 0010A9C4  80 83 01 04 */	lwz r4, 0x104(r3)
/* 8010DBC8 0010A9C8  83 C6 00 00 */	lwz r30, 0x0(r6)
/* 8010DBCC 0010A9CC  80 AD 05 EC */	lwz r5, lbl_805DD6CC@sda21(r0)
/* 8010DBD0 0010A9D0  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 8010DBD4 0010A9D4  38 65 00 54 */	addi r3, r5, 0x54
/* 8010DBD8 0010A9D8  54 00 18 38 */	slwi r0, r0, 3
/* 8010DBDC 0010A9DC  7C 84 00 2E */	lwzx r4, r4, r0
/* 8010DBE0 0010A9E0  4B FC 9D 75 */	bl kar_grcoll__800d7954
/* 8010DBE4 0010A9E4  90 7F 01 30 */	stw r3, 0x130(r31)
/* 8010DBE8 0010A9E8  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 8010DBEC 0010A9EC  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 8010DBF0 0010A9F0  90 03 00 90 */	stw r0, 0x90(r3)
/* 8010DBF4 0010A9F4  80 9E 00 14 */	lwz r4, 0x14(r30)
/* 8010DBF8 0010A9F8  80 64 00 08 */	lwz r3, 0x8(r4)
/* 8010DBFC 0010A9FC  80 04 00 04 */	lwz r0, 0x4(r4)
/* 8010DC00 0010AA00  7C 03 00 00 */	cmpw r3, r0
/* 8010DC04 0010AA04  41 81 00 1C */	bgt .L_8010DC20
/* 8010DC08 0010AA08  3C 60 80 4A */	lis r3, kar_src_gryakuwhispywoods_c@ha
/* 8010DC0C 0010AA0C  3C A0 80 4A */	lis r5, kar_gryakuwhispywoods_assert_wait_ex_motion_req_count_range@ha
/* 8010DC10 0010AA10  38 63 74 C4 */	addi r3, r3, kar_src_gryakuwhispywoods_c@l
/* 8010DC14 0010AA14  38 80 00 61 */	li r4, 0x61
/* 8010DC18 0010AA18  38 A5 74 D8 */	addi r5, r5, kar_gryakuwhispywoods_assert_wait_ex_motion_req_count_range@l
/* 8010DC1C 0010AA1C  48 31 A8 9D */	bl __assert
.L_8010DC20:
/* 8010DC20 0010AA20  80 7E 00 14 */	lwz r3, 0x14(r30)
/* 8010DC24 0010AA24  80 03 00 00 */	lwz r0, 0x0(r3)
/* 8010DC28 0010AA28  90 1F 01 34 */	stw r0, 0x134(r31)
/* 8010DC2C 0010AA2C  80 9E 00 14 */	lwz r4, 0x14(r30)
/* 8010DC30 0010AA30  80 64 00 04 */	lwz r3, 0x4(r4)
/* 8010DC34 0010AA34  80 04 00 08 */	lwz r0, 0x8(r4)
/* 8010DC38 0010AA38  7C 63 00 50 */	subf r3, r3, r0
/* 8010DC3C 0010AA3C  38 63 00 01 */	addi r3, r3, 0x1
/* 8010DC40 0010AA40  48 31 0A 29 */	bl HSD_Randi
/* 8010DC44 0010AA44  80 9E 00 14 */	lwz r4, 0x14(r30)
/* 8010DC48 0010AA48  80 04 00 04 */	lwz r0, 0x4(r4)
/* 8010DC4C 0010AA4C  7C 00 1A 14 */	add r0, r0, r3
/* 8010DC50 0010AA50  90 1F 01 38 */	stw r0, 0x138(r31)
/* 8010DC54 0010AA54  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 8010DC58 0010AA58  80 03 00 14 */	lwz r0, 0x14(r3)
/* 8010DC5C 0010AA5C  28 00 00 00 */	cmplwi r0, 0x0
/* 8010DC60 0010AA60  41 82 00 14 */	beq .L_8010DC74
/* 8010DC64 0010AA64  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 8010DC68 0010AA68  7F A3 EB 78 */	mr r3, r29
/* 8010DC6C 0010AA6C  38 A0 00 00 */	li r5, 0x0
/* 8010DC70 0010AA70  4B FE 9C 01 */	bl kar_gryakuaudio_configure_fgm_track_from_joint
.L_8010DC74:
/* 8010DC74 0010AA74  7F A3 EB 78 */	mr r3, r29
/* 8010DC78 0010AA78  48 00 00 21 */	bl kar_gryakuwhispywoods_start_kind69_idle_motion
/* 8010DC7C 0010AA7C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8010DC80 0010AA80  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8010DC84 0010AA84  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8010DC88 0010AA88  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8010DC8C 0010AA8C  7C 08 03 A6 */	mtlr r0
/* 8010DC90 0010AA90  38 21 00 20 */	addi r1, r1, 0x20
/* 8010DC94 0010AA94  4E 80 00 20 */	blr
.endfn kar_gryakuwhispywoods_init_kind69_collision_wait_state

# .text:0xFC | 0x8010DC98 | size: 0x48
.fn kar_gryakuwhispywoods_start_kind69_idle_motion, global
/* 8010DC98 0010AA98  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010DC9C 0010AA9C  7C 08 02 A6 */	mflr r0
/* 8010DCA0 0010AAA0  C0 22 93 E0 */	lfs f1, lbl_805DFAE0@sda21(r0)
/* 8010DCA4 0010AAA4  38 80 00 00 */	li r4, 0x0
/* 8010DCA8 0010AAA8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010DCAC 0010AAAC  38 E0 00 00 */	li r7, 0x0
/* 8010DCB0 0010AAB0  FC 60 08 90 */	fmr f3, f1
/* 8010DCB4 0010AAB4  C0 42 93 E4 */	lfs f2, lbl_805DFAE4@sda21(r0)
/* 8010DCB8 0010AAB8  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8010DCBC 0010AABC  80 A3 00 08 */	lwz r5, 0x8(r3)
/* 8010DCC0 0010AAC0  80 C5 00 00 */	lwz r6, 0x0(r5)
/* 8010DCC4 0010AAC4  80 A6 00 04 */	lwz r5, 0x4(r6)
/* 8010DCC8 0010AAC8  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 8010DCCC 0010AACC  4B FE 78 7D */	bl kar_gryaku_set_path_node_motion
/* 8010DCD0 0010AAD0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010DCD4 0010AAD4  7C 08 03 A6 */	mtlr r0
/* 8010DCD8 0010AAD8  38 21 00 10 */	addi r1, r1, 0x10
/* 8010DCDC 0010AADC  4E 80 00 20 */	blr
.endfn kar_gryakuwhispywoods_start_kind69_idle_motion

# .text:0x144 | 0x8010DCE0 | size: 0x118
.fn kar_gryakuwhispywoods_update_kind69_wait_random_extra_motion, global
/* 8010DCE0 0010AAE0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8010DCE4 0010AAE4  7C 08 02 A6 */	mflr r0
/* 8010DCE8 0010AAE8  90 01 00 24 */	stw r0, 0x24(r1)
/* 8010DCEC 0010AAEC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8010DCF0 0010AAF0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8010DCF4 0010AAF4  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8010DCF8 0010AAF8  7C 7D 1B 78 */	mr r29, r3
/* 8010DCFC 0010AAFC  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 8010DD00 0010AB00  83 FD 00 2C */	lwz r31, 0x2c(r29)
/* 8010DD04 0010AB04  80 83 01 04 */	lwz r4, 0x104(r3)
/* 8010DD08 0010AB08  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 8010DD0C 0010AB0C  80 63 00 00 */	lwz r3, 0x0(r3)
/* 8010DD10 0010AB10  80 03 00 00 */	lwz r0, 0x0(r3)
/* 8010DD14 0010AB14  54 00 18 38 */	slwi r0, r0, 3
/* 8010DD18 0010AB18  7F C4 00 2E */	lwzx r30, r4, r0
/* 8010DD1C 0010AB1C  7F C3 F3 78 */	mr r3, r30
/* 8010DD20 0010AB20  4B F4 6A C1 */	bl kar_gmlanmenu__near_800547e0
/* 8010DD24 0010AB24  2C 03 00 00 */	cmpwi r3, 0x0
/* 8010DD28 0010AB28  40 82 00 B4 */	bne .L_8010DDDC
/* 8010DD2C 0010AB2C  7F C3 F3 78 */	mr r3, r30
/* 8010DD30 0010AB30  4B F4 6C 71 */	bl kar_lbairride__800549a0
/* 8010DD34 0010AB34  2C 03 00 00 */	cmpwi r3, 0x0
/* 8010DD38 0010AB38  40 82 00 A4 */	bne .L_8010DDDC
/* 8010DD3C 0010AB3C  80 7F 01 38 */	lwz r3, 0x138(r31)
/* 8010DD40 0010AB40  38 03 FF FF */	subi r0, r3, 0x1
/* 8010DD44 0010AB44  90 1F 01 38 */	stw r0, 0x138(r31)
/* 8010DD48 0010AB48  80 1F 01 38 */	lwz r0, 0x138(r31)
/* 8010DD4C 0010AB4C  2C 00 00 00 */	cmpwi r0, 0x0
/* 8010DD50 0010AB50  41 81 00 60 */	bgt .L_8010DDB0
/* 8010DD54 0010AB54  83 DD 00 2C */	lwz r30, 0x2c(r29)
/* 8010DD58 0010AB58  80 7E 00 08 */	lwz r3, 0x8(r30)
/* 8010DD5C 0010AB5C  83 E3 00 00 */	lwz r31, 0x0(r3)
/* 8010DD60 0010AB60  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 8010DD64 0010AB64  80 64 00 04 */	lwz r3, 0x4(r4)
/* 8010DD68 0010AB68  80 04 00 08 */	lwz r0, 0x8(r4)
/* 8010DD6C 0010AB6C  7C 63 00 50 */	subf r3, r3, r0
/* 8010DD70 0010AB70  38 63 00 01 */	addi r3, r3, 0x1
/* 8010DD74 0010AB74  48 31 08 F5 */	bl HSD_Randi
/* 8010DD78 0010AB78  80 BF 00 14 */	lwz r5, 0x14(r31)
/* 8010DD7C 0010AB7C  38 80 00 01 */	li r4, 0x1
/* 8010DD80 0010AB80  C0 22 93 E0 */	lfs f1, lbl_805DFAE0@sda21(r0)
/* 8010DD84 0010AB84  38 E0 00 00 */	li r7, 0x0
/* 8010DD88 0010AB88  80 05 00 04 */	lwz r0, 0x4(r5)
/* 8010DD8C 0010AB8C  FC 60 08 90 */	fmr f3, f1
/* 8010DD90 0010AB90  C0 42 93 E4 */	lfs f2, lbl_805DFAE4@sda21(r0)
/* 8010DD94 0010AB94  7C 00 1A 14 */	add r0, r0, r3
/* 8010DD98 0010AB98  7F C3 F3 78 */	mr r3, r30
/* 8010DD9C 0010AB9C  90 1E 01 38 */	stw r0, 0x138(r30)
/* 8010DDA0 0010ABA0  80 BF 00 08 */	lwz r5, 0x8(r31)
/* 8010DDA4 0010ABA4  80 DF 00 00 */	lwz r6, 0x0(r31)
/* 8010DDA8 0010ABA8  4B FE 77 A1 */	bl kar_gryaku_set_path_node_motion
/* 8010DDAC 0010ABAC  48 00 00 30 */	b .L_8010DDDC
.L_8010DDB0:
/* 8010DDB0 0010ABB0  80 7D 00 2C */	lwz r3, 0x2c(r29)
/* 8010DDB4 0010ABB4  38 80 00 00 */	li r4, 0x0
/* 8010DDB8 0010ABB8  C0 22 93 E0 */	lfs f1, lbl_805DFAE0@sda21(r0)
/* 8010DDBC 0010ABBC  38 E0 00 00 */	li r7, 0x0
/* 8010DDC0 0010ABC0  80 A3 00 08 */	lwz r5, 0x8(r3)
/* 8010DDC4 0010ABC4  FC 60 08 90 */	fmr f3, f1
/* 8010DDC8 0010ABC8  C0 42 93 E4 */	lfs f2, lbl_805DFAE4@sda21(r0)
/* 8010DDCC 0010ABCC  80 C5 00 00 */	lwz r6, 0x0(r5)
/* 8010DDD0 0010ABD0  80 A6 00 04 */	lwz r5, 0x4(r6)
/* 8010DDD4 0010ABD4  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 8010DDD8 0010ABD8  4B FE 77 71 */	bl kar_gryaku_set_path_node_motion
.L_8010DDDC:
/* 8010DDDC 0010ABDC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8010DDE0 0010ABE0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8010DDE4 0010ABE4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8010DDE8 0010ABE8  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8010DDEC 0010ABEC  7C 08 03 A6 */	mtlr r0
/* 8010DDF0 0010ABF0  38 21 00 20 */	addi r1, r1, 0x20
/* 8010DDF4 0010ABF4  4E 80 00 20 */	blr
.endfn kar_gryakuwhispywoods_update_kind69_wait_random_extra_motion

# .text:0x25C | 0x8010DDF8 | size: 0x9C
.fn kar_gryakuwhispywoods_update_kind69_return_idle_when_clear, global
/* 8010DDF8 0010ABF8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010DDFC 0010ABFC  7C 08 02 A6 */	mflr r0
/* 8010DE00 0010AC00  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010DE04 0010AC04  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010DE08 0010AC08  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8010DE0C 0010AC0C  7C 7E 1B 78 */	mr r30, r3
/* 8010DE10 0010AC10  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8010DE14 0010AC14  80 8D 05 EC */	lwz r4, lbl_805DD6CC@sda21(r0)
/* 8010DE18 0010AC18  80 63 00 08 */	lwz r3, 0x8(r3)
/* 8010DE1C 0010AC1C  80 84 01 04 */	lwz r4, 0x104(r4)
/* 8010DE20 0010AC20  80 63 00 00 */	lwz r3, 0x0(r3)
/* 8010DE24 0010AC24  80 03 00 00 */	lwz r0, 0x0(r3)
/* 8010DE28 0010AC28  54 00 18 38 */	slwi r0, r0, 3
/* 8010DE2C 0010AC2C  7F E4 00 2E */	lwzx r31, r4, r0
/* 8010DE30 0010AC30  7F E3 FB 78 */	mr r3, r31
/* 8010DE34 0010AC34  4B F4 69 AD */	bl kar_gmlanmenu__near_800547e0
/* 8010DE38 0010AC38  2C 03 00 00 */	cmpwi r3, 0x0
/* 8010DE3C 0010AC3C  40 82 00 40 */	bne .L_8010DE7C
/* 8010DE40 0010AC40  7F E3 FB 78 */	mr r3, r31
/* 8010DE44 0010AC44  4B F4 6B 5D */	bl kar_lbairride__800549a0
/* 8010DE48 0010AC48  2C 03 00 00 */	cmpwi r3, 0x0
/* 8010DE4C 0010AC4C  40 82 00 30 */	bne .L_8010DE7C
/* 8010DE50 0010AC50  80 7E 00 2C */	lwz r3, 0x2c(r30)
/* 8010DE54 0010AC54  38 80 00 00 */	li r4, 0x0
/* 8010DE58 0010AC58  C0 22 93 E0 */	lfs f1, lbl_805DFAE0@sda21(r0)
/* 8010DE5C 0010AC5C  38 E0 00 00 */	li r7, 0x0
/* 8010DE60 0010AC60  80 A3 00 08 */	lwz r5, 0x8(r3)
/* 8010DE64 0010AC64  FC 60 08 90 */	fmr f3, f1
/* 8010DE68 0010AC68  C0 42 93 E4 */	lfs f2, lbl_805DFAE4@sda21(r0)
/* 8010DE6C 0010AC6C  80 C5 00 00 */	lwz r6, 0x0(r5)
/* 8010DE70 0010AC70  80 A6 00 04 */	lwz r5, 0x4(r6)
/* 8010DE74 0010AC74  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 8010DE78 0010AC78  4B FE 76 D1 */	bl kar_gryaku_set_path_node_motion
.L_8010DE7C:
/* 8010DE7C 0010AC7C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010DE80 0010AC80  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010DE84 0010AC84  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8010DE88 0010AC88  7C 08 03 A6 */	mtlr r0
/* 8010DE8C 0010AC8C  38 21 00 10 */	addi r1, r1, 0x10
/* 8010DE90 0010AC90  4E 80 00 20 */	blr
.endfn kar_gryakuwhispywoods_update_kind69_return_idle_when_clear

# .text:0x2F8 | 0x8010DE94 | size: 0xC8
.fn kar_gryakuwhispywoods_update_kind69_reseed_extra_motion_when_clear, global
/* 8010DE94 0010AC94  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010DE98 0010AC98  7C 08 02 A6 */	mflr r0
/* 8010DE9C 0010AC9C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010DEA0 0010ACA0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010DEA4 0010ACA4  7C 7F 1B 78 */	mr r31, r3
/* 8010DEA8 0010ACA8  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8010DEAC 0010ACAC  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8010DEB0 0010ACB0  80 8D 05 EC */	lwz r4, lbl_805DD6CC@sda21(r0)
/* 8010DEB4 0010ACB4  80 63 00 08 */	lwz r3, 0x8(r3)
/* 8010DEB8 0010ACB8  80 84 01 04 */	lwz r4, 0x104(r4)
/* 8010DEBC 0010ACBC  80 63 00 00 */	lwz r3, 0x0(r3)
/* 8010DEC0 0010ACC0  80 03 00 00 */	lwz r0, 0x0(r3)
/* 8010DEC4 0010ACC4  54 00 18 38 */	slwi r0, r0, 3
/* 8010DEC8 0010ACC8  7F C4 00 2E */	lwzx r30, r4, r0
/* 8010DECC 0010ACCC  7F C3 F3 78 */	mr r3, r30
/* 8010DED0 0010ACD0  4B F4 69 11 */	bl kar_gmlanmenu__near_800547e0
/* 8010DED4 0010ACD4  2C 03 00 00 */	cmpwi r3, 0x0
/* 8010DED8 0010ACD8  40 82 00 6C */	bne .L_8010DF44
/* 8010DEDC 0010ACDC  7F C3 F3 78 */	mr r3, r30
/* 8010DEE0 0010ACE0  4B F4 6A C1 */	bl kar_lbairride__800549a0
/* 8010DEE4 0010ACE4  2C 03 00 00 */	cmpwi r3, 0x0
/* 8010DEE8 0010ACE8  40 82 00 5C */	bne .L_8010DF44
/* 8010DEEC 0010ACEC  83 DF 00 2C */	lwz r30, 0x2c(r31)
/* 8010DEF0 0010ACF0  80 7E 00 08 */	lwz r3, 0x8(r30)
/* 8010DEF4 0010ACF4  83 E3 00 00 */	lwz r31, 0x0(r3)
/* 8010DEF8 0010ACF8  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 8010DEFC 0010ACFC  80 64 00 04 */	lwz r3, 0x4(r4)
/* 8010DF00 0010AD00  80 04 00 08 */	lwz r0, 0x8(r4)
/* 8010DF04 0010AD04  7C 63 00 50 */	subf r3, r3, r0
/* 8010DF08 0010AD08  38 63 00 01 */	addi r3, r3, 0x1
/* 8010DF0C 0010AD0C  48 31 07 5D */	bl HSD_Randi
/* 8010DF10 0010AD10  80 BF 00 14 */	lwz r5, 0x14(r31)
/* 8010DF14 0010AD14  38 80 00 01 */	li r4, 0x1
/* 8010DF18 0010AD18  C0 22 93 E0 */	lfs f1, lbl_805DFAE0@sda21(r0)
/* 8010DF1C 0010AD1C  38 E0 00 00 */	li r7, 0x0
/* 8010DF20 0010AD20  80 05 00 04 */	lwz r0, 0x4(r5)
/* 8010DF24 0010AD24  FC 60 08 90 */	fmr f3, f1
/* 8010DF28 0010AD28  C0 42 93 E4 */	lfs f2, lbl_805DFAE4@sda21(r0)
/* 8010DF2C 0010AD2C  7C 00 1A 14 */	add r0, r0, r3
/* 8010DF30 0010AD30  7F C3 F3 78 */	mr r3, r30
/* 8010DF34 0010AD34  90 1E 01 38 */	stw r0, 0x138(r30)
/* 8010DF38 0010AD38  80 BF 00 08 */	lwz r5, 0x8(r31)
/* 8010DF3C 0010AD3C  80 DF 00 00 */	lwz r6, 0x0(r31)
/* 8010DF40 0010AD40  4B FE 76 09 */	bl kar_gryaku_set_path_node_motion
.L_8010DF44:
/* 8010DF44 0010AD44  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010DF48 0010AD48  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010DF4C 0010AD4C  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8010DF50 0010AD50  7C 08 03 A6 */	mtlr r0
/* 8010DF54 0010AD54  38 21 00 10 */	addi r1, r1, 0x10
/* 8010DF58 0010AD58  4E 80 00 20 */	blr
.endfn kar_gryakuwhispywoods_update_kind69_reseed_extra_motion_when_clear

# .text:0x3C0 | 0x8010DF5C | size: 0x13C
.fn kar_gryakuwhispywoods_handle_kind69_grcoll_hit_damage, global
/* 8010DF5C 0010AD5C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8010DF60 0010AD60  7C 08 02 A6 */	mflr r0
/* 8010DF64 0010AD64  90 01 00 24 */	stw r0, 0x24(r1)
/* 8010DF68 0010AD68  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8010DF6C 0010AD6C  7C BF 2B 78 */	mr r31, r5
/* 8010DF70 0010AD70  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8010DF74 0010AD74  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8010DF78 0010AD78  7C 9D 23 78 */	mr r29, r4
/* 8010DF7C 0010AD7C  93 81 00 10 */	stw r28, 0x10(r1)
/* 8010DF80 0010AD80  7C 7C 1B 78 */	mr r28, r3
/* 8010DF84 0010AD84  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 8010DF88 0010AD88  4B FE 9B 31 */	bl kar_gryakulib_get_yaku_state_or_none
/* 8010DF8C 0010AD8C  2C 03 00 00 */	cmpwi r3, 0x0
/* 8010DF90 0010AD90  41 82 00 0C */	beq .L_8010DF9C
/* 8010DF94 0010AD94  2C 03 00 01 */	cmpwi r3, 0x1
/* 8010DF98 0010AD98  40 82 00 DC */	bne .L_8010E074
.L_8010DF9C:
/* 8010DF9C 0010AD9C  80 BE 01 30 */	lwz r5, 0x130(r30)
/* 8010DFA0 0010ADA0  7F A3 EB 78 */	mr r3, r29
/* 8010DFA4 0010ADA4  7F E4 FB 78 */	mr r4, r31
/* 8010DFA8 0010ADA8  4B FC 9B E5 */	bl kar_grcoll__near_800d7b8c
/* 8010DFAC 0010ADAC  2C 03 00 00 */	cmpwi r3, 0x0
/* 8010DFB0 0010ADB0  41 82 00 0C */	beq .L_8010DFBC
/* 8010DFB4 0010ADB4  38 60 00 00 */	li r3, 0x0
/* 8010DFB8 0010ADB8  48 00 00 C0 */	b .L_8010E078
.L_8010DFBC:
/* 8010DFBC 0010ADBC  80 7E 01 34 */	lwz r3, 0x134(r30)
/* 8010DFC0 0010ADC0  38 03 FF FF */	subi r0, r3, 0x1
/* 8010DFC4 0010ADC4  90 1E 01 34 */	stw r0, 0x134(r30)
/* 8010DFC8 0010ADC8  80 1E 01 34 */	lwz r0, 0x134(r30)
/* 8010DFCC 0010ADCC  2C 00 00 00 */	cmpwi r0, 0x0
/* 8010DFD0 0010ADD0  41 81 00 5C */	bgt .L_8010E02C
/* 8010DFD4 0010ADD4  7F A3 EB 78 */	mr r3, r29
/* 8010DFD8 0010ADD8  4B FF 7C D9 */	bl kar_gryakubreakcommon_resolve_break_credit_player
/* 8010DFDC 0010ADDC  48 16 CA 99 */	bl fn_8027AA74
/* 8010DFE0 0010ADE0  83 DC 00 2C */	lwz r30, 0x2c(r28)
/* 8010DFE4 0010ADE4  80 1E 01 1C */	lwz r0, 0x11c(r30)
/* 8010DFE8 0010ADE8  80 7E 00 08 */	lwz r3, 0x8(r30)
/* 8010DFEC 0010ADEC  2C 00 00 01 */	cmpwi r0, 0x1
/* 8010DFF0 0010ADF0  83 E3 00 00 */	lwz r31, 0x0(r3)
/* 8010DFF4 0010ADF4  40 81 00 10 */	ble .L_8010E004
/* 8010DFF8 0010ADF8  38 7E 01 18 */	addi r3, r30, 0x118
/* 8010DFFC 0010ADFC  38 80 00 01 */	li r4, 0x1
/* 8010E000 0010AE00  4B FD C0 85 */	bl kar_graudio_play_fgm_entry_id
.L_8010E004:
/* 8010E004 0010AE04  C0 22 93 E0 */	lfs f1, lbl_805DFAE0@sda21(r0)
/* 8010E008 0010AE08  7F C3 F3 78 */	mr r3, r30
/* 8010E00C 0010AE0C  80 BF 00 10 */	lwz r5, 0x10(r31)
/* 8010E010 0010AE10  38 80 00 03 */	li r4, 0x3
/* 8010E014 0010AE14  FC 60 08 90 */	fmr f3, f1
/* 8010E018 0010AE18  80 DF 00 00 */	lwz r6, 0x0(r31)
/* 8010E01C 0010AE1C  C0 42 93 E4 */	lfs f2, lbl_805DFAE4@sda21(r0)
/* 8010E020 0010AE20  38 E0 00 00 */	li r7, 0x0
/* 8010E024 0010AE24  4B FE 75 25 */	bl kar_gryaku_set_path_node_motion
/* 8010E028 0010AE28  48 00 00 4C */	b .L_8010E074
.L_8010E02C:
/* 8010E02C 0010AE2C  83 FC 00 2C */	lwz r31, 0x2c(r28)
/* 8010E030 0010AE30  80 1F 01 1C */	lwz r0, 0x11c(r31)
/* 8010E034 0010AE34  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 8010E038 0010AE38  2C 00 00 00 */	cmpwi r0, 0x0
/* 8010E03C 0010AE3C  83 C3 00 00 */	lwz r30, 0x0(r3)
/* 8010E040 0010AE40  40 81 00 10 */	ble .L_8010E050
/* 8010E044 0010AE44  38 7F 01 18 */	addi r3, r31, 0x118
/* 8010E048 0010AE48  38 80 00 00 */	li r4, 0x0
/* 8010E04C 0010AE4C  4B FD C0 39 */	bl kar_graudio_play_fgm_entry_id
.L_8010E050:
/* 8010E050 0010AE50  C0 22 93 E0 */	lfs f1, lbl_805DFAE0@sda21(r0)
/* 8010E054 0010AE54  7F E3 FB 78 */	mr r3, r31
/* 8010E058 0010AE58  80 BE 00 0C */	lwz r5, 0xc(r30)
/* 8010E05C 0010AE5C  38 80 00 02 */	li r4, 0x2
/* 8010E060 0010AE60  FC 60 08 90 */	fmr f3, f1
/* 8010E064 0010AE64  80 DE 00 00 */	lwz r6, 0x0(r30)
/* 8010E068 0010AE68  C0 42 93 E4 */	lfs f2, lbl_805DFAE4@sda21(r0)
/* 8010E06C 0010AE6C  38 E0 00 00 */	li r7, 0x0
/* 8010E070 0010AE70  4B FE 74 D9 */	bl kar_gryaku_set_path_node_motion
.L_8010E074:
/* 8010E074 0010AE74  38 60 00 00 */	li r3, 0x0
.L_8010E078:
/* 8010E078 0010AE78  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8010E07C 0010AE7C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8010E080 0010AE80  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8010E084 0010AE84  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8010E088 0010AE88  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8010E08C 0010AE8C  7C 08 03 A6 */	mtlr r0
/* 8010E090 0010AE90  38 21 00 20 */	addi r1, r1, 0x20
/* 8010E094 0010AE94  4E 80 00 20 */	blr
.endfn kar_gryakuwhispywoods_handle_kind69_grcoll_hit_damage

# .text:0x4FC | 0x8010E098 | size: 0x4
.fn fn_8010E098, global
/* 8010E098 0010AE98  4E 80 00 20 */	blr
.endfn fn_8010E098

# .text:0x500 | 0x8010E09C | size: 0x48
.fn kar_gryakuwhispywoods_create_stage_linked_catchzones, global
/* 8010E09C 0010AE9C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010E0A0 0010AEA0  7C 08 02 A6 */	mflr r0
/* 8010E0A4 0010AEA4  38 80 00 00 */	li r4, 0x0
/* 8010E0A8 0010AEA8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010E0AC 0010AEAC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010E0B0 0010AEB0  7C 7F 1B 78 */	mr r31, r3
/* 8010E0B4 0010AEB4  4B FE C6 55 */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010E0B8 0010AEB8  7F E3 FB 78 */	mr r3, r31
/* 8010E0BC 0010AEBC  38 80 00 01 */	li r4, 0x1
/* 8010E0C0 0010AEC0  4B FE C6 49 */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010E0C4 0010AEC4  7F E3 FB 78 */	mr r3, r31
/* 8010E0C8 0010AEC8  38 80 00 02 */	li r4, 0x2
/* 8010E0CC 0010AECC  4B FE C6 3D */	bl kar_gryakucatchzone_create_stage_linked_kind19_yaku
/* 8010E0D0 0010AED0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010E0D4 0010AED4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010E0D8 0010AED8  7C 08 03 A6 */	mtlr r0
/* 8010E0DC 0010AEDC  38 21 00 10 */	addi r1, r1, 0x10
/* 8010E0E0 0010AEE0  4E 80 00 20 */	blr
.endfn kar_gryakuwhispywoods_create_stage_linked_catchzones
