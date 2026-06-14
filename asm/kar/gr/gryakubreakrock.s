.include "macros.inc"
.file "gryakubreakrock.c"

# 0x8010203C..0x80102794 | size: 0x758
.text
.balign 4

# .text:0x0 | 0x8010203C | size: 0x308
.fn kar_gryakubreakrock_update_eventrock_shatter_sequence, global
/* 8010203C 000FEE3C  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 80102040 000FEE40  7C 08 02 A6 */	mflr r0
/* 80102044 000FEE44  90 01 00 54 */	stw r0, 0x54(r1)
/* 80102048 000FEE48  39 61 00 50 */	addi r11, r1, 0x50
/* 8010204C 000FEE4C  48 2A BB 01 */	bl _savegpr_25
/* 80102050 000FEE50  7C 7B 1B 78 */	mr r27, r3
/* 80102054 000FEE54  7C 9E 23 78 */	mr r30, r4
/* 80102058 000FEE58  83 83 00 2C */	lwz r28, 0x2c(r3)
/* 8010205C 000FEE5C  3C 60 80 4A */	lis r3, kar_gryakupillar_kind40_callback_table@ha
/* 80102060 000FEE60  80 04 00 38 */	lwz r0, 0x38(r4)
/* 80102064 000FEE64  3B E3 67 D8 */	addi r31, r3, kar_gryakupillar_kind40_callback_table@l
/* 80102068 000FEE68  80 7C 00 08 */	lwz r3, 0x8(r28)
/* 8010206C 000FEE6C  2C 00 00 05 */	cmpwi r0, 0x5
/* 80102070 000FEE70  83 A3 00 00 */	lwz r29, 0x0(r3)
/* 80102074 000FEE74  41 82 02 B8 */	beq .L_8010232C
/* 80102078 000FEE78  40 80 00 10 */	bge .L_80102088
/* 8010207C 000FEE7C  2C 00 00 00 */	cmpwi r0, 0x0
/* 80102080 000FEE80  40 80 00 10 */	bge .L_80102090
/* 80102084 000FEE84  48 00 02 A8 */	b .L_8010232C
.L_80102088:
/* 80102088 000FEE88  2C 00 00 08 */	cmpwi r0, 0x8
/* 8010208C 000FEE8C  40 80 02 A0 */	bge .L_8010232C
.L_80102090:
/* 80102090 000FEE90  80 7E 00 2C */	lwz r3, 0x2c(r30)
/* 80102094 000FEE94  80 1E 00 30 */	lwz r0, 0x30(r30)
/* 80102098 000FEE98  C0 22 92 70 */	lfs f1, lbl_805DF970@sda21(r0)
/* 8010209C 000FEE9C  90 61 00 20 */	stw r3, 0x20(r1)
/* 801020A0 000FEEA0  90 01 00 24 */	stw r0, 0x24(r1)
/* 801020A4 000FEEA4  80 1E 00 34 */	lwz r0, 0x34(r30)
/* 801020A8 000FEEA8  90 01 00 28 */	stw r0, 0x28(r1)
/* 801020AC 000FEEAC  80 1E 00 14 */	lwz r0, 0x14(r30)
/* 801020B0 000FEEB0  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 801020B4 000FEEB4  90 01 00 08 */	stw r0, 0x8(r1)
/* 801020B8 000FEEB8  C0 41 00 08 */	lfs f2, 0x8(r1)
/* 801020BC 000FEEBC  90 01 00 14 */	stw r0, 0x14(r1)
/* 801020C0 000FEEC0  FC 02 08 40 */	fcmpo cr0, f2, f1
/* 801020C4 000FEEC4  90 61 00 18 */	stw r3, 0x18(r1)
/* 801020C8 000FEEC8  80 1E 00 1C */	lwz r0, 0x1c(r30)
/* 801020CC 000FEECC  90 61 00 0C */	stw r3, 0xc(r1)
/* 801020D0 000FEED0  90 01 00 1C */	stw r0, 0x1c(r1)
/* 801020D4 000FEED4  90 01 00 10 */	stw r0, 0x10(r1)
/* 801020D8 000FEED8  4C 41 13 82 */	cror eq, gt, eq
/* 801020DC 000FEEDC  41 82 00 4C */	beq .L_80102128
/* 801020E0 000FEEE0  C0 02 92 74 */	lfs f0, lbl_805DF974@sda21(r0)
/* 801020E4 000FEEE4  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 801020E8 000FEEE8  4C 40 13 82 */	cror eq, lt, eq
/* 801020EC 000FEEEC  41 82 00 3C */	beq .L_80102128
/* 801020F0 000FEEF0  C0 41 00 0C */	lfs f2, 0xc(r1)
/* 801020F4 000FEEF4  FC 02 08 40 */	fcmpo cr0, f2, f1
/* 801020F8 000FEEF8  4C 41 13 82 */	cror eq, gt, eq
/* 801020FC 000FEEFC  41 82 00 2C */	beq .L_80102128
/* 80102100 000FEF00  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80102104 000FEF04  4C 40 13 82 */	cror eq, lt, eq
/* 80102108 000FEF08  41 82 00 20 */	beq .L_80102128
/* 8010210C 000FEF0C  C0 41 00 10 */	lfs f2, 0x10(r1)
/* 80102110 000FEF10  FC 02 08 40 */	fcmpo cr0, f2, f1
/* 80102114 000FEF14  4C 41 13 82 */	cror eq, gt, eq
/* 80102118 000FEF18  41 82 00 10 */	beq .L_80102128
/* 8010211C 000FEF1C  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80102120 000FEF20  4C 40 13 82 */	cror eq, lt, eq
/* 80102124 000FEF24  40 82 00 0C */	bne .L_80102130
.L_80102128:
/* 80102128 000FEF28  38 00 00 00 */	li r0, 0x0
/* 8010212C 000FEF2C  48 00 00 08 */	b .L_80102134
.L_80102130:
/* 80102130 000FEF30  38 00 00 01 */	li r0, 0x1
.L_80102134:
/* 80102134 000FEF34  2C 00 00 00 */	cmpwi r0, 0x0
/* 80102138 000FEF38  41 82 00 14 */	beq .L_8010214C
/* 8010213C 000FEF3C  38 7F 00 84 */	addi r3, r31, 0x84
/* 80102140 000FEF40  38 BF 00 D4 */	addi r5, r31, 0xd4
/* 80102144 000FEF44  38 80 02 AE */	li r4, 0x2ae
/* 80102148 000FEF48  48 32 63 71 */	bl __assert
.L_8010214C:
/* 8010214C 000FEF4C  80 7D 00 28 */	lwz r3, 0x28(r29)
/* 80102150 000FEF50  80 03 00 04 */	lwz r0, 0x4(r3)
/* 80102154 000FEF54  2C 00 00 00 */	cmpwi r0, 0x0
/* 80102158 000FEF58  40 81 00 18 */	ble .L_80102170
/* 8010215C 000FEF5C  80 7C 00 EC */	lwz r3, 0xec(r28)
/* 80102160 000FEF60  48 08 A9 A5 */	bl kar_collision_object_begin_disable
/* 80102164 000FEF64  80 7D 00 28 */	lwz r3, 0x28(r29)
/* 80102168 000FEF68  80 03 00 04 */	lwz r0, 0x4(r3)
/* 8010216C 000FEF6C  90 1C 01 40 */	stw r0, 0x140(r28)
.L_80102170:
/* 80102170 000FEF70  3B 20 00 00 */	li r25, 0x0
/* 80102174 000FEF74  3B 40 00 00 */	li r26, 0x0
/* 80102178 000FEF78  48 00 00 30 */	b .L_801021A8
.L_8010217C:
/* 8010217C 000FEF7C  80 1D 00 34 */	lwz r0, 0x34(r29)
/* 80102180 000FEF80  38 E1 00 14 */	addi r7, r1, 0x14
/* 80102184 000FEF84  80 BD 00 00 */	lwz r5, 0x0(r29)
/* 80102188 000FEF88  7F 63 DB 78 */	mr r3, r27
/* 8010218C 000FEF8C  7C E8 3B 78 */	mr r8, r7
/* 80102190 000FEF90  7C 80 D2 14 */	add r4, r0, r26
/* 80102194 000FEF94  38 C1 00 20 */	addi r6, r1, 0x20
/* 80102198 000FEF98  39 20 00 01 */	li r9, 0x1
/* 8010219C 000FEF9C  4B FF 4E A9 */	bl kar_gryakueffect_request_by_entry_mode
/* 801021A0 000FEFA0  3B 5A 00 1C */	addi r26, r26, 0x1c
/* 801021A4 000FEFA4  3B 39 00 01 */	addi r25, r25, 0x1
.L_801021A8:
/* 801021A8 000FEFA8  80 1D 00 38 */	lwz r0, 0x38(r29)
/* 801021AC 000FEFAC  7C 19 00 00 */	cmpw r25, r0
/* 801021B0 000FEFB0  41 80 FF CC */	blt .L_8010217C
/* 801021B4 000FEFB4  C0 5C 01 38 */	lfs f2, 0x138(r28)
/* 801021B8 000FEFB8  C0 3E 00 0C */	lfs f1, 0xc(r30)
/* 801021BC 000FEFBC  C0 02 92 5C */	lfs f0, lbl_805DF95C@sda21(r0)
/* 801021C0 000FEFC0  EC 22 08 28 */	fsubs f1, f2, f1
/* 801021C4 000FEFC4  D0 3C 01 38 */	stfs f1, 0x138(r28)
/* 801021C8 000FEFC8  C0 3C 01 38 */	lfs f1, 0x138(r28)
/* 801021CC 000FEFCC  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801021D0 000FEFD0  4C 40 13 82 */	cror eq, lt, eq
/* 801021D4 000FEFD4  40 82 01 38 */	bne .L_8010230C
/* 801021D8 000FEFD8  83 BB 00 2C */	lwz r29, 0x2c(r27)
/* 801021DC 000FEFDC  38 80 00 00 */	li r4, 0x0
/* 801021E0 000FEFE0  83 9C 00 B0 */	lwz r28, 0xb0(r28)
/* 801021E4 000FEFE4  80 BD 00 08 */	lwz r5, 0x8(r29)
/* 801021E8 000FEFE8  80 7D 01 34 */	lwz r3, 0x134(r29)
/* 801021EC 000FEFEC  83 C5 00 00 */	lwz r30, 0x0(r5)
/* 801021F0 000FEFF0  4B FD 58 E1 */	bl kar_grcoll__near_800d7ad0
/* 801021F4 000FEFF4  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 801021F8 000FEFF8  38 80 00 10 */	li r4, 0x10
/* 801021FC 000FEFFC  80 7D 00 64 */	lwz r3, 0x64(r29)
/* 80102200 000FF000  54 00 18 38 */	slwi r0, r0, 3
/* 80102204 000FF004  7C 63 00 2E */	lwzx r3, r3, r0
/* 80102208 000FF008  48 30 9B F9 */	bl HSD_JObjSetFlagsAll
/* 8010220C 000FF00C  80 7D 00 EC */	lwz r3, 0xec(r29)
/* 80102210 000FF010  48 08 A8 F5 */	bl kar_collision_object_begin_disable
/* 80102214 000FF014  80 9E 00 24 */	lwz r4, 0x24(r30)
/* 80102218 000FF018  28 04 00 00 */	cmplwi r4, 0x0
/* 8010221C 000FF01C  41 82 00 24 */	beq .L_80102240
/* 80102220 000FF020  80 DD 00 08 */	lwz r6, 0x8(r29)
/* 80102224 000FF024  7F A3 EB 78 */	mr r3, r29
/* 80102228 000FF028  38 A1 00 14 */	addi r5, r1, 0x14
/* 8010222C 000FF02C  80 C6 00 04 */	lwz r6, 0x4(r6)
/* 80102230 000FF030  7C 06 00 D0 */	neg r0, r6
/* 80102234 000FF034  7C 00 33 78 */	or r0, r0, r6
/* 80102238 000FF038  54 06 0F FE */	srwi r6, r0, 31
/* 8010223C 000FF03C  48 00 2B 75 */	bl kar_gryakubreakcommon_spawn_break_parts_by_mode
.L_80102240:
/* 80102240 000FF040  80 1E 00 40 */	lwz r0, 0x40(r30)
/* 80102244 000FF044  2C 00 00 03 */	cmpwi r0, 0x3
/* 80102248 000FF048  40 81 00 14 */	ble .L_8010225C
/* 8010224C 000FF04C  38 7F 00 84 */	addi r3, r31, 0x84
/* 80102250 000FF050  38 BF 00 98 */	addi r5, r31, 0x98
/* 80102254 000FF054  38 80 01 3F */	li r4, 0x13f
/* 80102258 000FF058  48 32 62 61 */	bl __assert
.L_8010225C:
/* 8010225C 000FF05C  3B E0 00 00 */	li r31, 0x0
/* 80102260 000FF060  7F B9 EB 78 */	mr r25, r29
/* 80102264 000FF064  7F FA FB 78 */	mr r26, r31
/* 80102268 000FF068  48 00 00 3C */	b .L_801022A4
.L_8010226C:
/* 8010226C 000FF06C  80 1E 00 3C */	lwz r0, 0x3c(r30)
/* 80102270 000FF070  38 E1 00 14 */	addi r7, r1, 0x14
/* 80102274 000FF074  80 BE 00 00 */	lwz r5, 0x0(r30)
/* 80102278 000FF078  7F 63 DB 78 */	mr r3, r27
/* 8010227C 000FF07C  7C E8 3B 78 */	mr r8, r7
/* 80102280 000FF080  7C 80 D2 14 */	add r4, r0, r26
/* 80102284 000FF084  38 C1 00 20 */	addi r6, r1, 0x20
/* 80102288 000FF088  39 20 00 01 */	li r9, 0x1
/* 8010228C 000FF08C  4B FF 4D B9 */	bl kar_gryakueffect_request_by_entry_mode
/* 80102290 000FF090  90 99 01 4C */	stw r4, 0x14c(r25)
/* 80102294 000FF094  3B 5A 00 1C */	addi r26, r26, 0x1c
/* 80102298 000FF098  3B FF 00 01 */	addi r31, r31, 0x1
/* 8010229C 000FF09C  90 79 01 48 */	stw r3, 0x148(r25)
/* 801022A0 000FF0A0  3B 39 00 08 */	addi r25, r25, 0x8
.L_801022A4:
/* 801022A4 000FF0A4  80 1E 00 40 */	lwz r0, 0x40(r30)
/* 801022A8 000FF0A8  7C 1F 00 00 */	cmpw r31, r0
/* 801022AC 000FF0AC  41 80 FF C0 */	blt .L_8010226C
/* 801022B0 000FF0B0  80 1D 01 1C */	lwz r0, 0x11c(r29)
/* 801022B4 000FF0B4  2C 00 00 02 */	cmpwi r0, 0x2
/* 801022B8 000FF0B8  40 81 00 10 */	ble .L_801022C8
/* 801022BC 000FF0BC  38 7D 01 18 */	addi r3, r29, 0x118
/* 801022C0 000FF0C0  38 80 00 02 */	li r4, 0x2
/* 801022C4 000FF0C4  4B FE 7D C1 */	bl kar_graudio_play_fgm_entry_id
.L_801022C8:
/* 801022C8 000FF0C8  C0 22 92 5C */	lfs f1, lbl_805DF95C@sda21(r0)
/* 801022CC 000FF0CC  7F A3 EB 78 */	mr r3, r29
/* 801022D0 000FF0D0  80 BE 00 18 */	lwz r5, 0x18(r30)
/* 801022D4 000FF0D4  38 80 00 04 */	li r4, 0x4
/* 801022D8 000FF0D8  FC 40 08 90 */	fmr f2, f1
/* 801022DC 000FF0DC  38 C0 FF FF */	li r6, -0x1
/* 801022E0 000FF0E0  FC 60 08 90 */	fmr f3, f1
/* 801022E4 000FF0E4  38 E0 00 00 */	li r7, 0x0
/* 801022E8 000FF0E8  4B FF 32 61 */	bl kar_gryaku_set_path_node_motion
/* 801022EC 000FF0EC  2C 1C 00 05 */	cmpwi r28, 0x5
/* 801022F0 000FF0F0  41 82 00 10 */	beq .L_80102300
/* 801022F4 000FF0F4  7F 63 DB 78 */	mr r3, r27
/* 801022F8 000FF0F8  7F 84 E3 78 */	mr r4, r28
/* 801022FC 000FF0FC  48 00 3A 85 */	bl kar_gryakubreakcommon_award_clearchecker_break_credit
.L_80102300:
/* 80102300 000FF100  80 7D 01 30 */	lwz r3, 0x130(r29)
/* 80102304 000FF104  48 00 F3 B1 */	bl kar_greventrock_notify_eventrock_shatter_finished
/* 80102308 000FF108  48 00 00 24 */	b .L_8010232C
.L_8010230C:
/* 8010230C 000FF10C  7F 63 DB 78 */	mr r3, r27
/* 80102310 000FF110  48 00 00 35 */	bl kar_gryakubreakrock_update_break_anim_threshold_index
/* 80102314 000FF114  80 1C 01 1C */	lwz r0, 0x11c(r28)
/* 80102318 000FF118  2C 00 00 00 */	cmpwi r0, 0x0
/* 8010231C 000FF11C  40 81 00 10 */	ble .L_8010232C
/* 80102320 000FF120  38 7C 01 18 */	addi r3, r28, 0x118
/* 80102324 000FF124  38 80 00 01 */	li r4, 0x1
/* 80102328 000FF128  4B FE 7D 5D */	bl kar_graudio_play_fgm_entry_id
.L_8010232C:
/* 8010232C 000FF12C  39 61 00 50 */	addi r11, r1, 0x50
/* 80102330 000FF130  48 2A B8 69 */	bl _restgpr_25
/* 80102334 000FF134  80 01 00 54 */	lwz r0, 0x54(r1)
/* 80102338 000FF138  7C 08 03 A6 */	mtlr r0
/* 8010233C 000FF13C  38 21 00 50 */	addi r1, r1, 0x50
/* 80102340 000FF140  4E 80 00 20 */	blr
.endfn kar_gryakubreakrock_update_eventrock_shatter_sequence

# .text:0x308 | 0x80102344 | size: 0xA4
.fn kar_gryakubreakrock_update_break_anim_threshold_index, global
/* 80102344 000FF144  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80102348 000FF148  7C 08 02 A6 */	mflr r0
/* 8010234C 000FF14C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80102350 000FF150  80 E3 00 2C */	lwz r7, 0x2c(r3)
/* 80102354 000FF154  80 87 00 08 */	lwz r4, 0x8(r7)
/* 80102358 000FF158  80 C7 01 3C */	lwz r6, 0x13c(r7)
/* 8010235C 000FF15C  81 04 00 00 */	lwz r8, 0x0(r4)
/* 80102360 000FF160  80 88 00 30 */	lwz r4, 0x30(r8)
/* 80102364 000FF164  38 04 FF FF */	subi r0, r4, 0x1
/* 80102368 000FF168  7C 06 00 00 */	cmpw r6, r0
/* 8010236C 000FF16C  40 80 00 6C */	bge .L_801023D8
/* 80102370 000FF170  80 A8 00 28 */	lwz r5, 0x28(r8)
/* 80102374 000FF174  54 C0 10 3A */	slwi r0, r6, 2
/* 80102378 000FF178  80 88 00 2C */	lwz r4, 0x2c(r8)
/* 8010237C 000FF17C  C0 47 01 38 */	lfs f2, 0x138(r7)
/* 80102380 000FF180  C0 25 00 00 */	lfs f1, 0x0(r5)
/* 80102384 000FF184  7C 84 02 14 */	add r4, r4, r0
/* 80102388 000FF188  C0 04 00 04 */	lfs f0, 0x4(r4)
/* 8010238C 000FF18C  EC 22 08 24 */	fdivs f1, f2, f1
/* 80102390 000FF190  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80102394 000FF194  4C 40 13 82 */	cror eq, lt, eq
/* 80102398 000FF198  40 82 00 40 */	bne .L_801023D8
/* 8010239C 000FF19C  38 06 00 01 */	addi r0, r6, 0x1
/* 801023A0 000FF1A0  90 07 01 3C */	stw r0, 0x13c(r7)
/* 801023A4 000FF1A4  48 00 00 10 */	b .L_801023B4
.L_801023A8:
/* 801023A8 000FF1A8  80 87 01 3C */	lwz r4, 0x13c(r7)
/* 801023AC 000FF1AC  38 04 00 01 */	addi r0, r4, 0x1
/* 801023B0 000FF1B0  90 07 01 3C */	stw r0, 0x13c(r7)
.L_801023B4:
/* 801023B4 000FF1B4  80 07 01 3C */	lwz r0, 0x13c(r7)
/* 801023B8 000FF1B8  80 A8 00 2C */	lwz r5, 0x2c(r8)
/* 801023BC 000FF1BC  54 04 10 3A */	slwi r4, r0, 2
/* 801023C0 000FF1C0  38 04 00 04 */	addi r0, r4, 0x4
/* 801023C4 000FF1C4  7C 05 04 2E */	lfsx f0, r5, r0
/* 801023C8 000FF1C8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801023CC 000FF1CC  4C 40 13 82 */	cror eq, lt, eq
/* 801023D0 000FF1D0  41 82 FF D8 */	beq .L_801023A8
/* 801023D4 000FF1D4  48 00 00 15 */	bl kar_gryakubreakrock_start_dobj_anim_for_threshold_index
.L_801023D8:
/* 801023D8 000FF1D8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801023DC 000FF1DC  7C 08 03 A6 */	mtlr r0
/* 801023E0 000FF1E0  38 21 00 10 */	addi r1, r1, 0x10
/* 801023E4 000FF1E4  4E 80 00 20 */	blr
.endfn kar_gryakubreakrock_update_break_anim_threshold_index

# .text:0x3AC | 0x801023E8 | size: 0x7C
.fn kar_gryakubreakrock_start_dobj_anim_for_threshold_index, global
/* 801023E8 000FF1E8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801023EC 000FF1EC  7C 08 02 A6 */	mflr r0
/* 801023F0 000FF1F0  C8 22 92 68 */	lfd f1, lbl_805DF968@sda21(r0)
/* 801023F4 000FF1F4  38 C0 00 00 */	li r6, 0x0
/* 801023F8 000FF1F8  90 01 00 24 */	stw r0, 0x24(r1)
/* 801023FC 000FF1FC  3C 00 43 30 */	lis r0, 0x4330
/* 80102400 000FF200  C0 42 92 5C */	lfs f2, lbl_805DF95C@sda21(r0)
/* 80102404 000FF204  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80102408 000FF208  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8010240C 000FF20C  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80102410 000FF210  90 01 00 08 */	stw r0, 0x8(r1)
/* 80102414 000FF214  80 1F 01 3C */	lwz r0, 0x13c(r31)
/* 80102418 000FF218  7F E3 FB 78 */	mr r3, r31
/* 8010241C 000FF21C  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 80102420 000FF220  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 80102424 000FF224  90 01 00 0C */	stw r0, 0xc(r1)
/* 80102428 000FF228  83 C4 00 00 */	lwz r30, 0x0(r4)
/* 8010242C 000FF22C  C8 01 00 08 */	lfd f0, 0x8(r1)
/* 80102430 000FF230  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 80102434 000FF234  EC 20 08 28 */	fsubs f1, f0, f1
/* 80102438 000FF238  80 BE 00 14 */	lwz r5, 0x14(r30)
/* 8010243C 000FF23C  4B FF 3B 4D */	bl kar_gryakuanim_start_dobj_anim_for_entry
/* 80102440 000FF240  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 80102444 000FF244  7F E3 FB 78 */	mr r3, r31
/* 80102448 000FF248  4B FF 3B E9 */	bl kar_gryakuanim_step_dobj_anim_for_slot
/* 8010244C 000FF24C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80102450 000FF250  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80102454 000FF254  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80102458 000FF258  7C 08 03 A6 */	mtlr r0
/* 8010245C 000FF25C  38 21 00 20 */	addi r1, r1, 0x20
/* 80102460 000FF260  4E 80 00 20 */	blr
.endfn kar_gryakubreakrock_start_dobj_anim_for_threshold_index

# .text:0x428 | 0x80102464 | size: 0xA8
.fn kar_gryakubreakrock_find_active_kind40_colosseum_pillar_position, global
/* 80102464 000FF264  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80102468 000FF268  7C 08 02 A6 */	mflr r0
/* 8010246C 000FF26C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80102470 000FF270  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80102474 000FF274  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80102478 000FF278  7C 7E 1B 78 */	mr r30, r3
/* 8010247C 000FF27C  80 8D 12 50 */	lwz r4, lbl_805DE330@sda21(r0)
/* 80102480 000FF280  83 E4 00 20 */	lwz r31, 0x20(r4)
/* 80102484 000FF284  48 00 00 18 */	b .L_8010249C
.L_80102488:
/* 80102488 000FF288  7F E3 FB 78 */	mr r3, r31
/* 8010248C 000FF28C  4B FF 55 D9 */	bl kar_gryakulib_get_yaku_data_checked
/* 80102490 000FF290  2C 03 00 28 */	cmpwi r3, 0x28
/* 80102494 000FF294  41 82 00 10 */	beq .L_801024A4
/* 80102498 000FF298  83 FF 00 0C */	lwz r31, 0xc(r31)
.L_8010249C:
/* 8010249C 000FF29C  28 1F 00 00 */	cmplwi r31, 0x0
/* 801024A0 000FF2A0  40 82 FF E8 */	bne .L_80102488
.L_801024A4:
/* 801024A4 000FF2A4  28 1F 00 00 */	cmplwi r31, 0x0
/* 801024A8 000FF2A8  41 82 00 48 */	beq .L_801024F0
/* 801024AC 000FF2AC  7F E3 FB 78 */	mr r3, r31
/* 801024B0 000FF2B0  4B FF 56 09 */	bl kar_gryakulib_get_yaku_state_or_none
/* 801024B4 000FF2B4  2C 03 00 04 */	cmpwi r3, 0x4
/* 801024B8 000FF2B8  41 82 00 30 */	beq .L_801024E8
/* 801024BC 000FF2BC  40 80 00 10 */	bge .L_801024CC
/* 801024C0 000FF2C0  2C 03 00 01 */	cmpwi r3, 0x1
/* 801024C4 000FF2C4  40 80 00 10 */	bge .L_801024D4
/* 801024C8 000FF2C8  48 00 00 20 */	b .L_801024E8
.L_801024CC:
/* 801024CC 000FF2CC  2C 03 00 06 */	cmpwi r3, 0x6
/* 801024D0 000FF2D0  40 80 00 18 */	bge .L_801024E8
.L_801024D4:
/* 801024D4 000FF2D4  7F E3 FB 78 */	mr r3, r31
/* 801024D8 000FF2D8  7F C4 F3 78 */	mr r4, r30
/* 801024DC 000FF2DC  4B FF 55 FD */	bl kar_gryakulib_get_model_root_position
/* 801024E0 000FF2E0  38 60 00 01 */	li r3, 0x1
/* 801024E4 000FF2E4  48 00 00 10 */	b .L_801024F4
.L_801024E8:
/* 801024E8 000FF2E8  38 60 00 00 */	li r3, 0x0
/* 801024EC 000FF2EC  48 00 00 08 */	b .L_801024F4
.L_801024F0:
/* 801024F0 000FF2F0  38 60 00 00 */	li r3, 0x0
.L_801024F4:
/* 801024F4 000FF2F4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801024F8 000FF2F8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801024FC 000FF2FC  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80102500 000FF300  7C 08 03 A6 */	mtlr r0
/* 80102504 000FF304  38 21 00 10 */	addi r1, r1, 0x10
/* 80102508 000FF308  4E 80 00 20 */	blr
.endfn kar_gryakubreakrock_find_active_kind40_colosseum_pillar_position

# .text:0x4D0 | 0x8010250C | size: 0x38
.fn kar_gryakubreakrock_create_colosseum_kind22_breakrock, global
/* 8010250C 000FF30C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80102510 000FF310  7C 08 02 A6 */	mflr r0
/* 80102514 000FF314  90 01 00 14 */	stw r0, 0x14(r1)
/* 80102518 000FF318  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010251C 000FF31C  7C 7F 1B 78 */	mr r31, r3
/* 80102520 000FF320  38 60 00 16 */	li r3, 0x16
/* 80102524 000FF324  4B FF 1F 49 */	bl kar_gryaku_create_yaku_from_main_kind
/* 80102528 000FF328  7F E4 FB 78 */	mr r4, r31
/* 8010252C 000FF32C  48 00 00 19 */	bl kar_gryakubreakrock_init_colosseum_kind22_breakrock
/* 80102530 000FF330  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80102534 000FF334  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80102538 000FF338  7C 08 03 A6 */	mtlr r0
/* 8010253C 000FF33C  38 21 00 10 */	addi r1, r1, 0x10
/* 80102540 000FF340  4E 80 00 20 */	blr
.endfn kar_gryakubreakrock_create_colosseum_kind22_breakrock

# .text:0x508 | 0x80102544 | size: 0xCC
.fn kar_gryakubreakrock_init_colosseum_kind22_breakrock, global
/* 80102544 000FF344  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80102548 000FF348  7C 08 02 A6 */	mflr r0
/* 8010254C 000FF34C  90 01 00 24 */	stw r0, 0x24(r1)
/* 80102550 000FF350  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80102554 000FF354  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80102558 000FF358  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8010255C 000FF35C  7C 7D 1B 78 */	mr r29, r3
/* 80102560 000FF360  83 FD 00 2C */	lwz r31, 0x2c(r29)
/* 80102564 000FF364  80 64 00 2C */	lwz r3, 0x2c(r4)
/* 80102568 000FF368  80 DF 00 08 */	lwz r6, 0x8(r31)
/* 8010256C 000FF36C  80 83 01 04 */	lwz r4, 0x104(r3)
/* 80102570 000FF370  83 C6 00 00 */	lwz r30, 0x0(r6)
/* 80102574 000FF374  80 AD 05 EC */	lwz r5, lbl_805DD6CC@sda21(r0)
/* 80102578 000FF378  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 8010257C 000FF37C  38 65 00 54 */	addi r3, r5, 0x54
/* 80102580 000FF380  54 00 18 38 */	slwi r0, r0, 3
/* 80102584 000FF384  7C 84 00 2E */	lwzx r4, r4, r0
/* 80102588 000FF388  4B FD 53 CD */	bl kar_grcoll__800d7954
/* 8010258C 000FF38C  90 7F 01 30 */	stw r3, 0x130(r31)
/* 80102590 000FF390  38 00 00 00 */	li r0, 0x0
/* 80102594 000FF394  80 9F 00 00 */	lwz r4, 0x0(r31)
/* 80102598 000FF398  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 8010259C 000FF39C  90 83 00 90 */	stw r4, 0x90(r3)
/* 801025A0 000FF3A0  80 7E 00 08 */	lwz r3, 0x8(r30)
/* 801025A4 000FF3A4  C0 03 00 00 */	lfs f0, 0x0(r3)
/* 801025A8 000FF3A8  D0 1F 01 34 */	stfs f0, 0x134(r31)
/* 801025AC 000FF3AC  90 1F 01 38 */	stw r0, 0x138(r31)
/* 801025B0 000FF3B0  90 1F 01 58 */	stw r0, 0x158(r31)
/* 801025B4 000FF3B4  90 1F 01 44 */	stw r0, 0x144(r31)
/* 801025B8 000FF3B8  90 1F 01 40 */	stw r0, 0x140(r31)
/* 801025BC 000FF3BC  90 1F 01 4C */	stw r0, 0x14c(r31)
/* 801025C0 000FF3C0  90 1F 01 48 */	stw r0, 0x148(r31)
/* 801025C4 000FF3C4  90 1F 01 54 */	stw r0, 0x154(r31)
/* 801025C8 000FF3C8  90 1F 01 50 */	stw r0, 0x150(r31)
/* 801025CC 000FF3CC  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 801025D0 000FF3D0  80 03 00 14 */	lwz r0, 0x14(r3)
/* 801025D4 000FF3D4  28 00 00 00 */	cmplwi r0, 0x0
/* 801025D8 000FF3D8  41 82 00 14 */	beq .L_801025EC
/* 801025DC 000FF3DC  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 801025E0 000FF3E0  7F A3 EB 78 */	mr r3, r29
/* 801025E4 000FF3E4  38 A0 00 00 */	li r5, 0x0
/* 801025E8 000FF3E8  4B FF 52 89 */	bl kar_gryakuaudio_configure_fgm_track_from_joint
.L_801025EC:
/* 801025EC 000FF3EC  7F A3 EB 78 */	mr r3, r29
/* 801025F0 000FF3F0  48 00 00 21 */	bl kar_gryakubreakrock_start_kind22_idle_path_motion
/* 801025F4 000FF3F4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801025F8 000FF3F8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801025FC 000FF3FC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80102600 000FF400  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80102604 000FF404  7C 08 03 A6 */	mtlr r0
/* 80102608 000FF408  38 21 00 20 */	addi r1, r1, 0x20
/* 8010260C 000FF40C  4E 80 00 20 */	blr
.endfn kar_gryakubreakrock_init_colosseum_kind22_breakrock

# .text:0x5D4 | 0x80102610 | size: 0x64
.fn kar_gryakubreakrock_start_kind22_idle_path_motion, global
/* 80102610 000FF410  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80102614 000FF414  7C 08 02 A6 */	mflr r0
/* 80102618 000FF418  C0 42 92 78 */	lfs f2, lbl_805DF978@sda21(r0)
/* 8010261C 000FF41C  38 80 00 00 */	li r4, 0x0
/* 80102620 000FF420  90 01 00 14 */	stw r0, 0x14(r1)
/* 80102624 000FF424  3C 00 43 30 */	lis r0, 0x4330
/* 80102628 000FF428  C8 22 92 80 */	lfd f1, lbl_805DF980@sda21(r0)
/* 8010262C 000FF42C  FC 60 10 90 */	fmr f3, f2
/* 80102630 000FF430  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80102634 000FF434  38 E0 00 00 */	li r7, 0x0
/* 80102638 000FF438  90 01 00 08 */	stw r0, 0x8(r1)
/* 8010263C 000FF43C  80 A3 01 38 */	lwz r5, 0x138(r3)
/* 80102640 000FF440  80 C3 00 08 */	lwz r6, 0x8(r3)
/* 80102644 000FF444  6C A5 80 00 */	xoris r5, r5, 0x8000
/* 80102648 000FF448  90 A1 00 0C */	stw r5, 0xc(r1)
/* 8010264C 000FF44C  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 80102650 000FF450  C8 01 00 08 */	lfd f0, 0x8(r1)
/* 80102654 000FF454  80 A6 00 04 */	lwz r5, 0x4(r6)
/* 80102658 000FF458  EC 20 08 28 */	fsubs f1, f0, f1
/* 8010265C 000FF45C  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 80102660 000FF460  4B FF 2E E9 */	bl kar_gryaku_set_path_node_motion
/* 80102664 000FF464  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80102668 000FF468  7C 08 03 A6 */	mtlr r0
/* 8010266C 000FF46C  38 21 00 10 */	addi r1, r1, 0x10
/* 80102670 000FF470  4E 80 00 20 */	blr
.endfn kar_gryakubreakrock_start_kind22_idle_path_motion

# .text:0x638 | 0x80102674 | size: 0x1C
.fn kar_gryakubreakrock_update_kind22_lifetime_countdown, global
/* 80102674 000FF474  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 80102678 000FF478  80 64 01 58 */	lwz r3, 0x158(r4)
/* 8010267C 000FF47C  2C 03 00 00 */	cmpwi r3, 0x0
/* 80102680 000FF480  4C 81 00 20 */	blelr
/* 80102684 000FF484  38 03 FF FF */	subi r0, r3, 0x1
/* 80102688 000FF488  90 04 01 58 */	stw r0, 0x158(r4)
/* 8010268C 000FF48C  4E 80 00 20 */	blr
.endfn kar_gryakubreakrock_update_kind22_lifetime_countdown

# .text:0x654 | 0x80102690 | size: 0x104
.fn kar_gryakubreakrock_update_kind22_effects_then_destroy, global
/* 80102690 000FF490  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80102694 000FF494  7C 08 02 A6 */	mflr r0
/* 80102698 000FF498  90 01 00 24 */	stw r0, 0x24(r1)
/* 8010269C 000FF49C  39 61 00 20 */	addi r11, r1, 0x20
/* 801026A0 000FF4A0  48 2A B4 B1 */	bl _savegpr_26
/* 801026A4 000FF4A4  7C 7E 1B 78 */	mr r30, r3
/* 801026A8 000FF4A8  3B 40 00 00 */	li r26, 0x0
/* 801026AC 000FF4AC  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 801026B0 000FF4B0  3B A0 00 00 */	li r29, 0x0
/* 801026B4 000FF4B4  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 801026B8 000FF4B8  7F FC FB 78 */	mr r28, r31
/* 801026BC 000FF4BC  83 63 00 00 */	lwz r27, 0x0(r3)
/* 801026C0 000FF4C0  48 00 00 38 */	b .L_801026F8
.L_801026C4:
/* 801026C4 000FF4C4  80 7C 01 40 */	lwz r3, 0x140(r28)
/* 801026C8 000FF4C8  80 9C 01 44 */	lwz r4, 0x144(r28)
/* 801026CC 000FF4CC  7C 60 EA 78 */	xor r0, r3, r29
/* 801026D0 000FF4D0  7C 85 EA 78 */	xor r5, r4, r29
/* 801026D4 000FF4D4  7C A0 03 79 */	or. r0, r5, r0
/* 801026D8 000FF4D8  41 82 00 18 */	beq .L_801026F0
/* 801026DC 000FF4DC  4B FF 4B B1 */	bl kar_gryakueffect_is_effect_key_active
/* 801026E0 000FF4E0  2C 03 00 00 */	cmpwi r3, 0x0
/* 801026E4 000FF4E4  40 82 00 0C */	bne .L_801026F0
/* 801026E8 000FF4E8  93 BC 01 44 */	stw r29, 0x144(r28)
/* 801026EC 000FF4EC  93 BC 01 40 */	stw r29, 0x140(r28)
.L_801026F0:
/* 801026F0 000FF4F0  3B 9C 00 08 */	addi r28, r28, 0x8
/* 801026F4 000FF4F4  3B 5A 00 01 */	addi r26, r26, 0x1
.L_801026F8:
/* 801026F8 000FF4F8  80 FB 00 20 */	lwz r7, 0x20(r27)
/* 801026FC 000FF4FC  7C 1A 38 00 */	cmpw r26, r7
/* 80102700 000FF500  41 80 FF C4 */	blt .L_801026C4
/* 80102704 000FF504  39 00 00 00 */	li r8, 0x0
/* 80102708 000FF508  7F E6 FB 78 */	mr r6, r31
/* 8010270C 000FF50C  7D 05 43 78 */	mr r5, r8
/* 80102710 000FF510  7D 04 43 78 */	mr r4, r8
/* 80102714 000FF514  7C E9 03 A6 */	mtctr r7
/* 80102718 000FF518  2C 07 00 00 */	cmpwi r7, 0x0
/* 8010271C 000FF51C  40 81 00 28 */	ble .L_80102744
.L_80102720:
/* 80102720 000FF520  80 06 01 40 */	lwz r0, 0x140(r6)
/* 80102724 000FF524  80 66 01 44 */	lwz r3, 0x144(r6)
/* 80102728 000FF528  7C 00 22 78 */	xor r0, r0, r4
/* 8010272C 000FF52C  7C 63 2A 78 */	xor r3, r3, r5
/* 80102730 000FF530  7C 60 03 79 */	or. r0, r3, r0
/* 80102734 000FF534  40 82 00 10 */	bne .L_80102744
/* 80102738 000FF538  38 C6 00 08 */	addi r6, r6, 0x8
/* 8010273C 000FF53C  39 08 00 01 */	addi r8, r8, 0x1
/* 80102740 000FF540  42 00 FF E0 */	bdnz .L_80102720
.L_80102744:
/* 80102744 000FF544  7C 08 38 00 */	cmpw r8, r7
/* 80102748 000FF548  40 82 00 34 */	bne .L_8010277C
/* 8010274C 000FF54C  80 7F 01 18 */	lwz r3, 0x118(r31)
/* 80102750 000FF550  28 03 00 00 */	cmplwi r3, 0x0
/* 80102754 000FF554  41 82 00 20 */	beq .L_80102774
/* 80102758 000FF558  88 03 00 0C */	lbz r0, 0xc(r3)
/* 8010275C 000FF55C  54 00 C0 02 */	extlwi r0, r0, 2, 24
/* 80102760 000FF560  7C 00 FE 70 */	srawi r0, r0, 31
/* 80102764 000FF564  7C 00 07 75 */	extsb. r0, r0
/* 80102768 000FF568  41 82 00 0C */	beq .L_80102774
/* 8010276C 000FF56C  38 7F 01 18 */	addi r3, r31, 0x118
/* 80102770 000FF570  4B FE 7A 11 */	bl kar_graudio_stop_active_fgm_slot
.L_80102774:
/* 80102774 000FF574  7F C3 F3 78 */	mr r3, r30
/* 80102778 000FF578  48 32 67 ED */	bl HSD_GObjDestroy
.L_8010277C:
/* 8010277C 000FF57C  39 61 00 20 */	addi r11, r1, 0x20
/* 80102780 000FF580  48 2A B4 1D */	bl _restgpr_26
/* 80102784 000FF584  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80102788 000FF588  7C 08 03 A6 */	mtlr r0
/* 8010278C 000FF58C  38 21 00 20 */	addi r1, r1, 0x20
/* 80102790 000FF590  4E 80 00 20 */	blr
.endfn kar_gryakubreakrock_update_kind22_effects_then_destroy

# 0x804A68C8..0x804A6978 | size: 0xB0
.data
.balign 8

# .data:0x0 | 0x804A68C8 | size: 0x20
.obj kar_gryakubreakrock_kind22_callback_table, global
	.4byte kar_gryakubreakrock_update_kind22_lifetime_countdown
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte kar_gryakubreakrock_update_kind22_effects_then_destroy
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj kar_gryakubreakrock_kind22_callback_table

# .data:0x20 | 0x804A68E8 | size: 0x90
.obj kar_gryakubreakrock_kind22_callback_table_ptr, global
	.4byte kar_gryakubreakrock_kind22_callback_table
	.4byte kar_gryakubreakhouse_handle_kind22_23_grcoll_hit
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x67727961
	.4byte 0x6B756272
	.4byte 0x65616B68
	.4byte 0x6F757365
	.4byte 0x2E630000
	.4byte 0x70617261
	.4byte 0x6D2D3E65
	.4byte 0x66427265
	.4byte 0x616B4E75
	.4byte 0x6D203C3D
	.4byte 0x20477259
	.4byte 0x616B7542
	.4byte 0x7265616B
	.4byte 0x486F7573
	.4byte 0x655F5265
	.4byte 0x6D6F7665
	.4byte 0x45666665
	.4byte 0x63744964
	.4byte 0x4E756D4D
	.4byte 0x61780000
	.4byte 0x6772636F
	.4byte 0x6C6C2E68
	.4byte 0x00000000
	.4byte 0x21677243
	.4byte 0x6F6C6C43
	.4byte 0x686B4661
	.4byte 0x6365496C
	.4byte 0x6C656761
	.4byte 0x6C286763
	.4byte 0x702C2069
	.4byte 0x64290000
.endobj kar_gryakubreakrock_kind22_callback_table_ptr

# 0x805DF970..0x805DF988 | size: 0x18
.section .sdata2, "a"
.balign 8

# .sdata2:0x0 | 0x805DF970 | size: 0x4
.obj lbl_805DF970, global
	.float 0.00001
.endobj lbl_805DF970

# .sdata2:0x4 | 0x805DF974 | size: 0x4
.obj lbl_805DF974, global
	.float -0.00001
.endobj lbl_805DF974

# .sdata2:0x8 | 0x805DF978 | size: 0x4
.obj lbl_805DF978, global
	.float 0
.endobj lbl_805DF978
	.4byte 0x00000000

# .sdata2:0x10 | 0x805DF980 | size: 0x8
.obj lbl_805DF980, global
	.double 4503601774854144
.endobj lbl_805DF980
