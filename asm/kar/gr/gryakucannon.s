.include "macros.inc"
.file "gryakucannon.c"

# 0x800FEE40..0x800FF5CC | size: 0x78C
.text
.balign 4

# .text:0x0 | 0x800FEE40 | size: 0x1D0
.fn kar_gryakucannon_update_pending_shot_queue, global
/* 800FEE40 000FBC40  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800FEE44 000FBC44  7C 08 02 A6 */	mflr r0
/* 800FEE48 000FBC48  90 01 00 34 */	stw r0, 0x34(r1)
/* 800FEE4C 000FBC4C  39 61 00 30 */	addi r11, r1, 0x30
/* 800FEE50 000FBC50  48 2A EC FD */	bl _savegpr_25
/* 800FEE54 000FBC54  7C 7B 1B 78 */	mr r27, r3
/* 800FEE58 000FBC58  3C 60 66 66 */	lis r3, 0x6666
/* 800FEE5C 000FBC5C  83 BB 00 2C */	lwz r29, 0x2c(r27)
/* 800FEE60 000FBC60  3B 43 66 67 */	addi r26, r3, 0x6667
/* 800FEE64 000FBC64  80 7D 00 08 */	lwz r3, 0x8(r29)
/* 800FEE68 000FBC68  83 FD 01 80 */	lwz r31, 0x180(r29)
/* 800FEE6C 000FBC6C  83 C3 00 00 */	lwz r30, 0x0(r3)
/* 800FEE70 000FBC70  48 00 01 7C */	b .L_800FEFEC
.L_800FEE74:
/* 800FEE74 000FBC74  57 E0 18 38 */	slwi r0, r31, 3
/* 800FEE78 000FBC78  7F 9D 02 14 */	add r28, r29, r0
/* 800FEE7C 000FBC7C  80 7C 01 34 */	lwz r3, 0x134(r28)
/* 800FEE80 000FBC80  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FEE84 000FBC84  40 81 00 0C */	ble .L_800FEE90
/* 800FEE88 000FBC88  38 03 FF FF */	subi r0, r3, 0x1
/* 800FEE8C 000FBC8C  90 1C 01 34 */	stw r0, 0x134(r28)
.L_800FEE90:
/* 800FEE90 000FBC90  80 1C 01 34 */	lwz r0, 0x134(r28)
/* 800FEE94 000FBC94  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FEE98 000FBC98  41 81 01 38 */	bgt .L_800FEFD0
/* 800FEE9C 000FBC9C  80 1D 00 74 */	lwz r0, 0x74(r29)
/* 800FEEA0 000FBCA0  83 2D 05 EC */	lwz r25, lbl_805DD6CC@sda21(r0)
/* 800FEEA4 000FBCA4  2C 00 00 01 */	cmpwi r0, 0x1
/* 800FEEA8 000FBCA8  41 82 01 28 */	beq .L_800FEFD0
/* 800FEEAC 000FBCAC  40 80 01 24 */	bge .L_800FEFD0
/* 800FEEB0 000FBCB0  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FEEB4 000FBCB4  40 80 00 08 */	bge .L_800FEEBC
/* 800FEEB8 000FBCB8  48 00 01 18 */	b .L_800FEFD0
.L_800FEEBC:
/* 800FEEBC 000FBCBC  80 1C 01 30 */	lwz r0, 0x130(r28)
/* 800FEEC0 000FBCC0  28 00 00 00 */	cmplwi r0, 0x0
/* 800FEEC4 000FBCC4  40 82 00 1C */	bne .L_800FEEE0
/* 800FEEC8 000FBCC8  3C 60 80 4A */	lis r3, kar_src_gryakucannon_c@ha
/* 800FEECC 000FBCCC  3C A0 80 4A */	lis r5, kar_gryakucannon_assert_pending_user_gobj@ha
/* 800FEED0 000FBCD0  38 63 64 64 */	addi r3, r3, kar_src_gryakucannon_c@l
/* 800FEED4 000FBCD4  38 80 00 93 */	li r4, 0x93
/* 800FEED8 000FBCD8  38 A5 64 74 */	addi r5, r5, kar_gryakucannon_assert_pending_user_gobj@l
/* 800FEEDC 000FBCDC  48 32 95 DD */	bl __assert
.L_800FEEE0:
/* 800FEEE0 000FBCE0  80 7C 01 30 */	lwz r3, 0x130(r28)
/* 800FEEE4 000FBCE4  48 0C 86 51 */	bl fn_801C7534
/* 800FEEE8 000FBCE8  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FEEEC 000FBCEC  41 82 00 30 */	beq .L_800FEF1C
/* 800FEEF0 000FBCF0  80 79 00 08 */	lwz r3, 0x8(r25)
/* 800FEEF4 000FBCF4  80 1E 00 10 */	lwz r0, 0x10(r30)
/* 800FEEF8 000FBCF8  80 83 00 24 */	lwz r4, 0x24(r3)
/* 800FEEFC 000FBCFC  54 00 10 3A */	slwi r0, r0, 2
/* 800FEF00 000FBD00  80 7C 01 30 */	lwz r3, 0x130(r28)
/* 800FEF04 000FBD04  80 84 00 0C */	lwz r4, 0xc(r4)
/* 800FEF08 000FBD08  80 BE 00 14 */	lwz r5, 0x14(r30)
/* 800FEF0C 000FBD0C  80 84 00 00 */	lwz r4, 0x0(r4)
/* 800FEF10 000FBD10  7C 84 00 2E */	lwzx r4, r4, r0
/* 800FEF14 000FBD14  48 0C 95 45 */	bl kar_gryakucannon_dispatch_user_launch_to_target_entry
/* 800FEF18 000FBD18  48 00 00 4C */	b .L_800FEF64
.L_800FEF1C:
/* 800FEF1C 000FBD1C  80 7C 01 30 */	lwz r3, 0x130(r28)
/* 800FEF20 000FBD20  A0 03 00 00 */	lhz r0, 0x0(r3)
/* 800FEF24 000FBD24  28 00 00 15 */	cmplwi r0, 0x15
/* 800FEF28 000FBD28  40 82 00 3C */	bne .L_800FEF64
/* 800FEF2C 000FBD2C  80 99 00 08 */	lwz r4, 0x8(r25)
/* 800FEF30 000FBD30  80 1E 00 10 */	lwz r0, 0x10(r30)
/* 800FEF34 000FBD34  80 84 00 24 */	lwz r4, 0x24(r4)
/* 800FEF38 000FBD38  54 00 10 3A */	slwi r0, r0, 2
/* 800FEF3C 000FBD3C  80 84 00 0C */	lwz r4, 0xc(r4)
/* 800FEF40 000FBD40  80 84 00 00 */	lwz r4, 0x0(r4)
/* 800FEF44 000FBD44  7C 84 00 2E */	lwzx r4, r4, r0
/* 800FEF48 000FBD48  48 10 56 E1 */	bl kar_emupdate__near_80204628
/* 800FEF4C 000FBD4C  80 1D 01 1C */	lwz r0, 0x11c(r29)
/* 800FEF50 000FBD50  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FEF54 000FBD54  40 81 00 10 */	ble .L_800FEF64
/* 800FEF58 000FBD58  38 7D 01 18 */	addi r3, r29, 0x118
/* 800FEF5C 000FBD5C  38 80 00 00 */	li r4, 0x0
/* 800FEF60 000FBD60  4B FE B1 25 */	bl kar_graudio_play_fgm_entry_id
.L_800FEF64:
/* 800FEF64 000FBD64  38 A0 00 00 */	li r5, 0x0
/* 800FEF68 000FBD68  3C 60 66 66 */	lis r3, 0x6666
/* 800FEF6C 000FBD6C  90 BC 01 30 */	stw r5, 0x130(r28)
/* 800FEF70 000FBD70  38 03 66 67 */	addi r0, r3, 0x6667
/* 800FEF74 000FBD74  C0 22 92 28 */	lfs f1, lbl_805DF928@sda21(r0)
/* 800FEF78 000FBD78  38 80 00 01 */	li r4, 0x1
/* 800FEF7C 000FBD7C  90 BC 01 34 */	stw r5, 0x134(r28)
/* 800FEF80 000FBD80  38 A0 FF FF */	li r5, -0x1
/* 800FEF84 000FBD84  FC 60 08 90 */	fmr f3, f1
/* 800FEF88 000FBD88  C0 42 92 2C */	lfs f2, lbl_805DF92C@sda21(r0)
/* 800FEF8C 000FBD8C  80 7D 01 80 */	lwz r3, 0x180(r29)
/* 800FEF90 000FBD90  38 C0 FF FF */	li r6, -0x1
/* 800FEF94 000FBD94  38 E0 00 00 */	li r7, 0x0
/* 800FEF98 000FBD98  38 63 00 01 */	addi r3, r3, 0x1
/* 800FEF9C 000FBD9C  90 7D 01 80 */	stw r3, 0x180(r29)
/* 800FEFA0 000FBDA0  81 1D 01 80 */	lwz r8, 0x180(r29)
/* 800FEFA4 000FBDA4  7C 00 40 96 */	mulhw r0, r0, r8
/* 800FEFA8 000FBDA8  7C 00 16 70 */	srawi r0, r0, 2
/* 800FEFAC 000FBDAC  54 03 0F FE */	srwi r3, r0, 31
/* 800FEFB0 000FBDB0  7C 00 1A 14 */	add r0, r0, r3
/* 800FEFB4 000FBDB4  1C 00 00 0A */	mulli r0, r0, 0xa
/* 800FEFB8 000FBDB8  7C 00 40 50 */	subf r0, r0, r8
/* 800FEFBC 000FBDBC  90 1D 01 80 */	stw r0, 0x180(r29)
/* 800FEFC0 000FBDC0  80 1E 00 0C */	lwz r0, 0xc(r30)
/* 800FEFC4 000FBDC4  90 1D 01 88 */	stw r0, 0x188(r29)
/* 800FEFC8 000FBDC8  80 7B 00 2C */	lwz r3, 0x2c(r27)
/* 800FEFCC 000FBDCC  4B FF 65 7D */	bl kar_gryaku_set_path_node_motion
.L_800FEFD0:
/* 800FEFD0 000FBDD0  38 9F 00 01 */	addi r4, r31, 0x1
/* 800FEFD4 000FBDD4  7C 1A 20 96 */	mulhw r0, r26, r4
/* 800FEFD8 000FBDD8  7C 00 16 70 */	srawi r0, r0, 2
/* 800FEFDC 000FBDDC  54 03 0F FE */	srwi r3, r0, 31
/* 800FEFE0 000FBDE0  7C 00 1A 14 */	add r0, r0, r3
/* 800FEFE4 000FBDE4  1C 00 00 0A */	mulli r0, r0, 0xa
/* 800FEFE8 000FBDE8  7F E0 20 50 */	subf r31, r0, r4
.L_800FEFEC:
/* 800FEFEC 000FBDEC  80 1D 01 84 */	lwz r0, 0x184(r29)
/* 800FEFF0 000FBDF0  7C 1F 00 00 */	cmpw r31, r0
/* 800FEFF4 000FBDF4  40 82 FE 80 */	bne .L_800FEE74
/* 800FEFF8 000FBDF8  39 61 00 30 */	addi r11, r1, 0x30
/* 800FEFFC 000FBDFC  48 2A EB 9D */	bl _restgpr_25
/* 800FF000 000FBE00  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800FF004 000FBE04  7C 08 03 A6 */	mtlr r0
/* 800FF008 000FBE08  38 21 00 30 */	addi r1, r1, 0x30
/* 800FF00C 000FBE0C  4E 80 00 20 */	blr
.endfn kar_gryakucannon_update_pending_shot_queue

# .text:0x1D0 | 0x800FF010 | size: 0x210
.fn kar_gryakucannon_update_reload_and_pending_shots, global
/* 800FF010 000FBE10  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800FF014 000FBE14  7C 08 02 A6 */	mflr r0
/* 800FF018 000FBE18  90 01 00 34 */	stw r0, 0x34(r1)
/* 800FF01C 000FBE1C  39 61 00 30 */	addi r11, r1, 0x30
/* 800FF020 000FBE20  48 2A EB 2D */	bl _savegpr_25
/* 800FF024 000FBE24  7C 7B 1B 78 */	mr r27, r3
/* 800FF028 000FBE28  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 800FF02C 000FBE2C  80 64 01 88 */	lwz r3, 0x188(r4)
/* 800FF030 000FBE30  38 03 FF FF */	subi r0, r3, 0x1
/* 800FF034 000FBE34  90 04 01 88 */	stw r0, 0x188(r4)
/* 800FF038 000FBE38  80 04 01 88 */	lwz r0, 0x188(r4)
/* 800FF03C 000FBE3C  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FF040 000FBE40  41 81 00 28 */	bgt .L_800FF068
/* 800FF044 000FBE44  C0 22 92 28 */	lfs f1, lbl_805DF928@sda21(r0)
/* 800FF048 000FBE48  38 80 00 00 */	li r4, 0x0
/* 800FF04C 000FBE4C  80 7B 00 2C */	lwz r3, 0x2c(r27)
/* 800FF050 000FBE50  38 A0 FF FF */	li r5, -0x1
/* 800FF054 000FBE54  FC 60 08 90 */	fmr f3, f1
/* 800FF058 000FBE58  C0 42 92 2C */	lfs f2, lbl_805DF92C@sda21(r0)
/* 800FF05C 000FBE5C  38 C0 FF FF */	li r6, -0x1
/* 800FF060 000FBE60  38 E0 00 00 */	li r7, 0x0
/* 800FF064 000FBE64  4B FF 64 E5 */	bl kar_gryaku_set_path_node_motion
.L_800FF068:
/* 800FF068 000FBE68  83 BB 00 2C */	lwz r29, 0x2c(r27)
/* 800FF06C 000FBE6C  3C 60 66 66 */	lis r3, 0x6666
/* 800FF070 000FBE70  3B 43 66 67 */	addi r26, r3, 0x6667
/* 800FF074 000FBE74  80 7D 00 08 */	lwz r3, 0x8(r29)
/* 800FF078 000FBE78  83 FD 01 80 */	lwz r31, 0x180(r29)
/* 800FF07C 000FBE7C  83 C3 00 00 */	lwz r30, 0x0(r3)
/* 800FF080 000FBE80  48 00 01 7C */	b .L_800FF1FC
.L_800FF084:
/* 800FF084 000FBE84  57 E0 18 38 */	slwi r0, r31, 3
/* 800FF088 000FBE88  7F 9D 02 14 */	add r28, r29, r0
/* 800FF08C 000FBE8C  80 7C 01 34 */	lwz r3, 0x134(r28)
/* 800FF090 000FBE90  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FF094 000FBE94  40 81 00 0C */	ble .L_800FF0A0
/* 800FF098 000FBE98  38 03 FF FF */	subi r0, r3, 0x1
/* 800FF09C 000FBE9C  90 1C 01 34 */	stw r0, 0x134(r28)
.L_800FF0A0:
/* 800FF0A0 000FBEA0  80 1C 01 34 */	lwz r0, 0x134(r28)
/* 800FF0A4 000FBEA4  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FF0A8 000FBEA8  41 81 01 38 */	bgt .L_800FF1E0
/* 800FF0AC 000FBEAC  80 1D 00 74 */	lwz r0, 0x74(r29)
/* 800FF0B0 000FBEB0  83 2D 05 EC */	lwz r25, lbl_805DD6CC@sda21(r0)
/* 800FF0B4 000FBEB4  2C 00 00 01 */	cmpwi r0, 0x1
/* 800FF0B8 000FBEB8  41 82 01 28 */	beq .L_800FF1E0
/* 800FF0BC 000FBEBC  40 80 01 24 */	bge .L_800FF1E0
/* 800FF0C0 000FBEC0  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FF0C4 000FBEC4  40 80 00 08 */	bge .L_800FF0CC
/* 800FF0C8 000FBEC8  48 00 01 18 */	b .L_800FF1E0
.L_800FF0CC:
/* 800FF0CC 000FBECC  80 1C 01 30 */	lwz r0, 0x130(r28)
/* 800FF0D0 000FBED0  28 00 00 00 */	cmplwi r0, 0x0
/* 800FF0D4 000FBED4  40 82 00 1C */	bne .L_800FF0F0
/* 800FF0D8 000FBED8  3C 60 80 4A */	lis r3, kar_src_gryakucannon_c@ha
/* 800FF0DC 000FBEDC  3C A0 80 4A */	lis r5, kar_gryakucannon_assert_pending_user_gobj@ha
/* 800FF0E0 000FBEE0  38 63 64 64 */	addi r3, r3, kar_src_gryakucannon_c@l
/* 800FF0E4 000FBEE4  38 80 00 93 */	li r4, 0x93
/* 800FF0E8 000FBEE8  38 A5 64 74 */	addi r5, r5, kar_gryakucannon_assert_pending_user_gobj@l
/* 800FF0EC 000FBEEC  48 32 93 CD */	bl __assert
.L_800FF0F0:
/* 800FF0F0 000FBEF0  80 7C 01 30 */	lwz r3, 0x130(r28)
/* 800FF0F4 000FBEF4  48 0C 84 41 */	bl fn_801C7534
/* 800FF0F8 000FBEF8  2C 03 00 00 */	cmpwi r3, 0x0
/* 800FF0FC 000FBEFC  41 82 00 30 */	beq .L_800FF12C
/* 800FF100 000FBF00  80 79 00 08 */	lwz r3, 0x8(r25)
/* 800FF104 000FBF04  80 1E 00 10 */	lwz r0, 0x10(r30)
/* 800FF108 000FBF08  80 83 00 24 */	lwz r4, 0x24(r3)
/* 800FF10C 000FBF0C  54 00 10 3A */	slwi r0, r0, 2
/* 800FF110 000FBF10  80 7C 01 30 */	lwz r3, 0x130(r28)
/* 800FF114 000FBF14  80 84 00 0C */	lwz r4, 0xc(r4)
/* 800FF118 000FBF18  80 BE 00 14 */	lwz r5, 0x14(r30)
/* 800FF11C 000FBF1C  80 84 00 00 */	lwz r4, 0x0(r4)
/* 800FF120 000FBF20  7C 84 00 2E */	lwzx r4, r4, r0
/* 800FF124 000FBF24  48 0C 93 35 */	bl kar_gryakucannon_dispatch_user_launch_to_target_entry
/* 800FF128 000FBF28  48 00 00 4C */	b .L_800FF174
.L_800FF12C:
/* 800FF12C 000FBF2C  80 7C 01 30 */	lwz r3, 0x130(r28)
/* 800FF130 000FBF30  A0 03 00 00 */	lhz r0, 0x0(r3)
/* 800FF134 000FBF34  28 00 00 15 */	cmplwi r0, 0x15
/* 800FF138 000FBF38  40 82 00 3C */	bne .L_800FF174
/* 800FF13C 000FBF3C  80 99 00 08 */	lwz r4, 0x8(r25)
/* 800FF140 000FBF40  80 1E 00 10 */	lwz r0, 0x10(r30)
/* 800FF144 000FBF44  80 84 00 24 */	lwz r4, 0x24(r4)
/* 800FF148 000FBF48  54 00 10 3A */	slwi r0, r0, 2
/* 800FF14C 000FBF4C  80 84 00 0C */	lwz r4, 0xc(r4)
/* 800FF150 000FBF50  80 84 00 00 */	lwz r4, 0x0(r4)
/* 800FF154 000FBF54  7C 84 00 2E */	lwzx r4, r4, r0
/* 800FF158 000FBF58  48 10 54 D1 */	bl kar_emupdate__near_80204628
/* 800FF15C 000FBF5C  80 1D 01 1C */	lwz r0, 0x11c(r29)
/* 800FF160 000FBF60  2C 00 00 00 */	cmpwi r0, 0x0
/* 800FF164 000FBF64  40 81 00 10 */	ble .L_800FF174
/* 800FF168 000FBF68  38 7D 01 18 */	addi r3, r29, 0x118
/* 800FF16C 000FBF6C  38 80 00 00 */	li r4, 0x0
/* 800FF170 000FBF70  4B FE AF 15 */	bl kar_graudio_play_fgm_entry_id
.L_800FF174:
/* 800FF174 000FBF74  38 A0 00 00 */	li r5, 0x0
/* 800FF178 000FBF78  3C 60 66 66 */	lis r3, 0x6666
/* 800FF17C 000FBF7C  90 BC 01 30 */	stw r5, 0x130(r28)
/* 800FF180 000FBF80  38 03 66 67 */	addi r0, r3, 0x6667
/* 800FF184 000FBF84  C0 22 92 28 */	lfs f1, lbl_805DF928@sda21(r0)
/* 800FF188 000FBF88  38 80 00 01 */	li r4, 0x1
/* 800FF18C 000FBF8C  90 BC 01 34 */	stw r5, 0x134(r28)
/* 800FF190 000FBF90  38 A0 FF FF */	li r5, -0x1
/* 800FF194 000FBF94  FC 60 08 90 */	fmr f3, f1
/* 800FF198 000FBF98  C0 42 92 2C */	lfs f2, lbl_805DF92C@sda21(r0)
/* 800FF19C 000FBF9C  80 7D 01 80 */	lwz r3, 0x180(r29)
/* 800FF1A0 000FBFA0  38 C0 FF FF */	li r6, -0x1
/* 800FF1A4 000FBFA4  38 E0 00 00 */	li r7, 0x0
/* 800FF1A8 000FBFA8  38 63 00 01 */	addi r3, r3, 0x1
/* 800FF1AC 000FBFAC  90 7D 01 80 */	stw r3, 0x180(r29)
/* 800FF1B0 000FBFB0  81 1D 01 80 */	lwz r8, 0x180(r29)
/* 800FF1B4 000FBFB4  7C 00 40 96 */	mulhw r0, r0, r8
/* 800FF1B8 000FBFB8  7C 00 16 70 */	srawi r0, r0, 2
/* 800FF1BC 000FBFBC  54 03 0F FE */	srwi r3, r0, 31
/* 800FF1C0 000FBFC0  7C 00 1A 14 */	add r0, r0, r3
/* 800FF1C4 000FBFC4  1C 00 00 0A */	mulli r0, r0, 0xa
/* 800FF1C8 000FBFC8  7C 00 40 50 */	subf r0, r0, r8
/* 800FF1CC 000FBFCC  90 1D 01 80 */	stw r0, 0x180(r29)
/* 800FF1D0 000FBFD0  80 1E 00 0C */	lwz r0, 0xc(r30)
/* 800FF1D4 000FBFD4  90 1D 01 88 */	stw r0, 0x188(r29)
/* 800FF1D8 000FBFD8  80 7B 00 2C */	lwz r3, 0x2c(r27)
/* 800FF1DC 000FBFDC  4B FF 63 6D */	bl kar_gryaku_set_path_node_motion
.L_800FF1E0:
/* 800FF1E0 000FBFE0  38 9F 00 01 */	addi r4, r31, 0x1
/* 800FF1E4 000FBFE4  7C 1A 20 96 */	mulhw r0, r26, r4
/* 800FF1E8 000FBFE8  7C 00 16 70 */	srawi r0, r0, 2
/* 800FF1EC 000FBFEC  54 03 0F FE */	srwi r3, r0, 31
/* 800FF1F0 000FBFF0  7C 00 1A 14 */	add r0, r0, r3
/* 800FF1F4 000FBFF4  1C 00 00 0A */	mulli r0, r0, 0xa
/* 800FF1F8 000FBFF8  7F E0 20 50 */	subf r31, r0, r4
.L_800FF1FC:
/* 800FF1FC 000FBFFC  80 1D 01 84 */	lwz r0, 0x184(r29)
/* 800FF200 000FC000  7C 1F 00 00 */	cmpw r31, r0
/* 800FF204 000FC004  40 82 FE 80 */	bne .L_800FF084
/* 800FF208 000FC008  39 61 00 30 */	addi r11, r1, 0x30
/* 800FF20C 000FC00C  48 2A E9 8D */	bl _restgpr_25
/* 800FF210 000FC010  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800FF214 000FC014  7C 08 03 A6 */	mtlr r0
/* 800FF218 000FC018  38 21 00 30 */	addi r1, r1, 0x30
/* 800FF21C 000FC01C  4E 80 00 20 */	blr
.endfn kar_gryakucannon_update_reload_and_pending_shots

# .text:0x3E0 | 0x800FF220 | size: 0x1C4
.fn kar_gryakucannon_enqueue_catch_target, global
/* 800FF220 000FC020  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800FF224 000FC024  7C 08 02 A6 */	mflr r0
/* 800FF228 000FC028  90 01 00 24 */	stw r0, 0x24(r1)
/* 800FF22C 000FC02C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800FF230 000FC030  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800FF234 000FC034  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800FF238 000FC038  7C 9D 23 78 */	mr r29, r4
/* 800FF23C 000FC03C  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 800FF240 000FC040  3C 60 66 66 */	lis r3, 0x6666
/* 800FF244 000FC044  38 63 66 67 */	addi r3, r3, 0x6667
/* 800FF248 000FC048  80 DE 01 84 */	lwz r6, 0x184(r30)
/* 800FF24C 000FC04C  80 1E 01 80 */	lwz r0, 0x180(r30)
/* 800FF250 000FC050  38 A6 00 01 */	addi r5, r6, 0x1
/* 800FF254 000FC054  7C 63 28 96 */	mulhw r3, r3, r5
/* 800FF258 000FC058  7C 63 16 70 */	srawi r3, r3, 2
/* 800FF25C 000FC05C  54 64 0F FE */	srwi r4, r3, 31
/* 800FF260 000FC060  7C 63 22 14 */	add r3, r3, r4
/* 800FF264 000FC064  1C 63 00 0A */	mulli r3, r3, 0xa
/* 800FF268 000FC068  7C 63 28 50 */	subf r3, r3, r5
/* 800FF26C 000FC06C  7C 03 00 00 */	cmpw r3, r0
/* 800FF270 000FC070  40 82 00 F4 */	bne .L_800FF364
/* 800FF274 000FC074  A0 1D 00 00 */	lhz r0, 0x0(r29)
/* 800FF278 000FC078  2C 00 00 15 */	cmpwi r0, 0x15
/* 800FF27C 000FC07C  41 82 00 E0 */	beq .L_800FF35C
/* 800FF280 000FC080  40 80 00 E4 */	bge .L_800FF364
/* 800FF284 000FC084  2C 00 00 10 */	cmpwi r0, 0x10
/* 800FF288 000FC088  41 82 00 08 */	beq .L_800FF290
/* 800FF28C 000FC08C  48 00 00 D8 */	b .L_800FF364
.L_800FF290:
/* 800FF290 000FC090  34 06 FF FF */	subic. r0, r6, 0x1
/* 800FF294 000FC094  90 1E 01 84 */	stw r0, 0x184(r30)
/* 800FF298 000FC098  41 80 00 0C */	blt .L_800FF2A4
/* 800FF29C 000FC09C  80 1E 01 84 */	lwz r0, 0x184(r30)
/* 800FF2A0 000FC0A0  48 00 00 08 */	b .L_800FF2A8
.L_800FF2A4:
/* 800FF2A4 000FC0A4  38 00 00 09 */	li r0, 0x9
.L_800FF2A8:
/* 800FF2A8 000FC0A8  90 1E 01 84 */	stw r0, 0x184(r30)
/* 800FF2AC 000FC0AC  83 FE 01 84 */	lwz r31, 0x184(r30)
/* 800FF2B0 000FC0B0  80 9E 01 80 */	lwz r4, 0x180(r30)
/* 800FF2B4 000FC0B4  48 00 00 40 */	b .L_800FF2F4
.L_800FF2B8:
/* 800FF2B8 000FC0B8  57 E5 18 38 */	slwi r5, r31, 3
/* 800FF2BC 000FC0BC  38 05 01 30 */	addi r0, r5, 0x130
/* 800FF2C0 000FC0C0  7C 7E 00 2E */	lwzx r3, r30, r0
/* 800FF2C4 000FC0C4  A0 03 00 00 */	lhz r0, 0x0(r3)
/* 800FF2C8 000FC0C8  28 00 00 15 */	cmplwi r0, 0x15
/* 800FF2CC 000FC0CC  40 82 00 14 */	bne .L_800FF2E0
/* 800FF2D0 000FC0D0  7C 7E 2A 14 */	add r3, r30, r5
/* 800FF2D4 000FC0D4  80 63 01 30 */	lwz r3, 0x130(r3)
/* 800FF2D8 000FC0D8  48 10 54 F5 */	bl kar_emupdate__near_802047cc
/* 800FF2DC 000FC0DC  48 00 00 20 */	b .L_800FF2FC
.L_800FF2E0:
/* 800FF2E0 000FC0E0  37 FF FF FF */	subic. r31, r31, 0x1
/* 800FF2E4 000FC0E4  38 00 00 09 */	li r0, 0x9
/* 800FF2E8 000FC0E8  41 80 00 08 */	blt .L_800FF2F0
/* 800FF2EC 000FC0EC  7F E0 FB 78 */	mr r0, r31
.L_800FF2F0:
/* 800FF2F0 000FC0F0  7C 1F 03 78 */	mr r31, r0
.L_800FF2F4:
/* 800FF2F4 000FC0F4  7C 1F 20 00 */	cmpw r31, r4
/* 800FF2F8 000FC0F8  40 82 FF C0 */	bne .L_800FF2B8
.L_800FF2FC:
/* 800FF2FC 000FC0FC  3C 60 66 66 */	lis r3, 0x6666
/* 800FF300 000FC100  38 C3 66 67 */	addi r6, r3, 0x6667
/* 800FF304 000FC104  48 00 00 48 */	b .L_800FF34C
.L_800FF308:
/* 800FF308 000FC108  38 FF 00 01 */	addi r7, r31, 0x1
/* 800FF30C 000FC10C  57 E3 18 38 */	slwi r3, r31, 3
/* 800FF310 000FC110  7C 86 38 96 */	mulhw r4, r6, r7
/* 800FF314 000FC114  38 03 01 30 */	addi r0, r3, 0x130
/* 800FF318 000FC118  7C BE 02 14 */	add r5, r30, r0
/* 800FF31C 000FC11C  7C 80 16 70 */	srawi r0, r4, 2
/* 800FF320 000FC120  54 03 0F FE */	srwi r3, r0, 31
/* 800FF324 000FC124  7C 00 1A 14 */	add r0, r0, r3
/* 800FF328 000FC128  1C 00 00 0A */	mulli r0, r0, 0xa
/* 800FF32C 000FC12C  7F E0 38 50 */	subf r31, r0, r7
/* 800FF330 000FC130  57 E3 18 38 */	slwi r3, r31, 3
/* 800FF334 000FC134  38 03 01 30 */	addi r0, r3, 0x130
/* 800FF338 000FC138  7C 9E 02 14 */	add r4, r30, r0
/* 800FF33C 000FC13C  80 64 00 00 */	lwz r3, 0x0(r4)
/* 800FF340 000FC140  80 04 00 04 */	lwz r0, 0x4(r4)
/* 800FF344 000FC144  90 65 00 00 */	stw r3, 0x0(r5)
/* 800FF348 000FC148  90 05 00 04 */	stw r0, 0x4(r5)
.L_800FF34C:
/* 800FF34C 000FC14C  80 1E 01 84 */	lwz r0, 0x184(r30)
/* 800FF350 000FC150  7C 1F 00 00 */	cmpw r31, r0
/* 800FF354 000FC154  40 82 FF B4 */	bne .L_800FF308
/* 800FF358 000FC158  48 00 00 0C */	b .L_800FF364
.L_800FF35C:
/* 800FF35C 000FC15C  38 60 00 00 */	li r3, 0x0
/* 800FF360 000FC160  48 00 00 68 */	b .L_800FF3C8
.L_800FF364:
/* 800FF364 000FC164  80 BE 00 08 */	lwz r5, 0x8(r30)
/* 800FF368 000FC168  3C 60 66 66 */	lis r3, 0x6666
/* 800FF36C 000FC16C  80 9E 01 84 */	lwz r4, 0x184(r30)
/* 800FF370 000FC170  38 03 66 67 */	addi r0, r3, 0x6667
/* 800FF374 000FC174  80 A5 00 00 */	lwz r5, 0x0(r5)
/* 800FF378 000FC178  38 60 00 01 */	li r3, 0x1
/* 800FF37C 000FC17C  54 84 18 38 */	slwi r4, r4, 3
/* 800FF380 000FC180  7C 9E 22 14 */	add r4, r30, r4
/* 800FF384 000FC184  93 A4 01 30 */	stw r29, 0x130(r4)
/* 800FF388 000FC188  80 9E 01 84 */	lwz r4, 0x184(r30)
/* 800FF38C 000FC18C  80 A5 00 08 */	lwz r5, 0x8(r5)
/* 800FF390 000FC190  54 84 18 38 */	slwi r4, r4, 3
/* 800FF394 000FC194  7C 9E 22 14 */	add r4, r30, r4
/* 800FF398 000FC198  90 A4 01 34 */	stw r5, 0x134(r4)
/* 800FF39C 000FC19C  80 9E 01 84 */	lwz r4, 0x184(r30)
/* 800FF3A0 000FC1A0  38 84 00 01 */	addi r4, r4, 0x1
/* 800FF3A4 000FC1A4  90 9E 01 84 */	stw r4, 0x184(r30)
/* 800FF3A8 000FC1A8  80 BE 01 84 */	lwz r5, 0x184(r30)
/* 800FF3AC 000FC1AC  7C 00 28 96 */	mulhw r0, r0, r5
/* 800FF3B0 000FC1B0  7C 00 16 70 */	srawi r0, r0, 2
/* 800FF3B4 000FC1B4  54 04 0F FE */	srwi r4, r0, 31
/* 800FF3B8 000FC1B8  7C 00 22 14 */	add r0, r0, r4
/* 800FF3BC 000FC1BC  1C 00 00 0A */	mulli r0, r0, 0xa
/* 800FF3C0 000FC1C0  7C 00 28 50 */	subf r0, r0, r5
/* 800FF3C4 000FC1C4  90 1E 01 84 */	stw r0, 0x184(r30)
.L_800FF3C8:
/* 800FF3C8 000FC1C8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FF3CC 000FC1CC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800FF3D0 000FC1D0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800FF3D4 000FC1D4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800FF3D8 000FC1D8  7C 08 03 A6 */	mtlr r0
/* 800FF3DC 000FC1DC  38 21 00 20 */	addi r1, r1, 0x20
/* 800FF3E0 000FC1E0  4E 80 00 20 */	blr
.endfn kar_gryakucannon_enqueue_catch_target

# .text:0x5A4 | 0x800FF3E4 | size: 0x68
.fn kar_gryakucannon_get_reference_position_and_vectors, global
/* 800FF3E4 000FC1E4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800FF3E8 000FC1E8  7C 08 02 A6 */	mflr r0
/* 800FF3EC 000FC1EC  90 01 00 24 */	stw r0, 0x24(r1)
/* 800FF3F0 000FC1F0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800FF3F4 000FC1F4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800FF3F8 000FC1F8  7C DE 33 78 */	mr r30, r6
/* 800FF3FC 000FC1FC  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800FF400 000FC200  7C BD 2B 78 */	mr r29, r5
/* 800FF404 000FC204  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FF408 000FC208  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800FF40C 000FC20C  83 E3 00 00 */	lwz r31, 0x0(r3)
/* 800FF410 000FC210  80 7F 00 04 */	lwz r3, 0x4(r31)
/* 800FF414 000FC214  4B FD 57 E1 */	bl kar_grcommon__near_800d4bf4
/* 800FF418 000FC218  80 7F 00 04 */	lwz r3, 0x4(r31)
/* 800FF41C 000FC21C  7F A4 EB 78 */	mr r4, r29
/* 800FF420 000FC220  4B FD 58 81 */	bl kar_grcommon__near_800d4ca0
/* 800FF424 000FC224  80 7F 00 04 */	lwz r3, 0x4(r31)
/* 800FF428 000FC228  7F C4 F3 78 */	mr r4, r30
/* 800FF42C 000FC22C  4B FD 59 2D */	bl kar_grcommon__near_800d4d58
/* 800FF430 000FC230  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800FF434 000FC234  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800FF438 000FC238  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800FF43C 000FC23C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800FF440 000FC240  7C 08 03 A6 */	mtlr r0
/* 800FF444 000FC244  38 21 00 20 */	addi r1, r1, 0x20
/* 800FF448 000FC248  4E 80 00 20 */	blr
.endfn kar_gryakucannon_get_reference_position_and_vectors

# .text:0x60C | 0x800FF44C | size: 0x34
.fn kar_gryakucannon_get_launch_target_entry, global
/* 800FF44C 000FC24C  80 AD 05 EC */	lwz r5, lbl_805DD6CC@sda21(r0)
/* 800FF450 000FC250  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FF454 000FC254  80 A5 00 08 */	lwz r5, 0x8(r5)
/* 800FF458 000FC258  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800FF45C 000FC25C  80 A5 00 24 */	lwz r5, 0x24(r5)
/* 800FF460 000FC260  80 63 00 00 */	lwz r3, 0x0(r3)
/* 800FF464 000FC264  80 A5 00 0C */	lwz r5, 0xc(r5)
/* 800FF468 000FC268  80 03 00 10 */	lwz r0, 0x10(r3)
/* 800FF46C 000FC26C  80 65 00 00 */	lwz r3, 0x0(r5)
/* 800FF470 000FC270  54 00 10 3A */	slwi r0, r0, 2
/* 800FF474 000FC274  7C 03 00 2E */	lwzx r0, r3, r0
/* 800FF478 000FC278  90 04 00 00 */	stw r0, 0x0(r4)
/* 800FF47C 000FC27C  4E 80 00 20 */	blr
.endfn kar_gryakucannon_get_launch_target_entry

# .text:0x640 | 0x800FF480 | size: 0x8C
.fn kar_gryakucannon_replace_queued_user_gobj, global
/* 800FF480 000FC280  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FF484 000FC284  7C 08 02 A6 */	mflr r0
/* 800FF488 000FC288  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FF48C 000FC28C  81 23 00 2C */	lwz r9, 0x2c(r3)
/* 800FF490 000FC290  3C 60 66 66 */	lis r3, 0x6666
/* 800FF494 000FC294  38 C3 66 67 */	addi r6, r3, 0x6667
/* 800FF498 000FC298  80 E9 01 80 */	lwz r7, 0x180(r9)
/* 800FF49C 000FC29C  81 09 01 84 */	lwz r8, 0x184(r9)
/* 800FF4A0 000FC2A0  48 00 00 40 */	b .L_800FF4E0
.L_800FF4A4:
/* 800FF4A4 000FC2A4  54 E3 18 38 */	slwi r3, r7, 3
/* 800FF4A8 000FC2A8  38 03 01 30 */	addi r0, r3, 0x130
/* 800FF4AC 000FC2AC  7C 09 00 2E */	lwzx r0, r9, r0
/* 800FF4B0 000FC2B0  7C 00 20 40 */	cmplw r0, r4
/* 800FF4B4 000FC2B4  40 82 00 10 */	bne .L_800FF4C4
/* 800FF4B8 000FC2B8  7C 69 1A 14 */	add r3, r9, r3
/* 800FF4BC 000FC2BC  90 A3 01 30 */	stw r5, 0x130(r3)
/* 800FF4C0 000FC2C0  48 00 00 3C */	b .L_800FF4FC
.L_800FF4C4:
/* 800FF4C4 000FC2C4  38 E7 00 01 */	addi r7, r7, 0x1
/* 800FF4C8 000FC2C8  7C 06 38 96 */	mulhw r0, r6, r7
/* 800FF4CC 000FC2CC  7C 00 16 70 */	srawi r0, r0, 2
/* 800FF4D0 000FC2D0  54 03 0F FE */	srwi r3, r0, 31
/* 800FF4D4 000FC2D4  7C 00 1A 14 */	add r0, r0, r3
/* 800FF4D8 000FC2D8  1C 00 00 0A */	mulli r0, r0, 0xa
/* 800FF4DC 000FC2DC  7C E0 38 50 */	subf r7, r0, r7
.L_800FF4E0:
/* 800FF4E0 000FC2E0  7C 07 40 00 */	cmpw r7, r8
/* 800FF4E4 000FC2E4  40 82 FF C0 */	bne .L_800FF4A4
/* 800FF4E8 000FC2E8  3C 60 80 4A */	lis r3, kar_src_gryakucannon_c@ha
/* 800FF4EC 000FC2EC  38 80 01 5C */	li r4, 0x15c
/* 800FF4F0 000FC2F0  38 63 64 64 */	addi r3, r3, kar_src_gryakucannon_c@l
/* 800FF4F4 000FC2F4  38 AD 91 98 */	li r5, lbl_805D6278@sda21
/* 800FF4F8 000FC2F8  48 32 8F C1 */	bl __assert
.L_800FF4FC:
/* 800FF4FC 000FC2FC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FF500 000FC300  7C 08 03 A6 */	mtlr r0
/* 800FF504 000FC304  38 21 00 10 */	addi r1, r1, 0x10
/* 800FF508 000FC308  4E 80 00 20 */	blr
.endfn kar_gryakucannon_replace_queued_user_gobj

# .text:0x6CC | 0x800FF50C | size: 0x38
.fn kar_gryakupushoutwall_create_stage_linked_kind49_wall, global
/* 800FF50C 000FC30C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FF510 000FC310  7C 08 02 A6 */	mflr r0
/* 800FF514 000FC314  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FF518 000FC318  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800FF51C 000FC31C  7C 7F 1B 78 */	mr r31, r3
/* 800FF520 000FC320  38 60 00 31 */	li r3, 0x31
/* 800FF524 000FC324  4B FF 4F 49 */	bl kar_gryaku_create_yaku_from_main_kind
/* 800FF528 000FC328  7F E4 FB 78 */	mr r4, r31
/* 800FF52C 000FC32C  48 00 00 19 */	bl kar_gryakupushoutwall_init_stage_linked_kind49_wall
/* 800FF530 000FC330  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FF534 000FC334  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800FF538 000FC338  7C 08 03 A6 */	mtlr r0
/* 800FF53C 000FC33C  38 21 00 10 */	addi r1, r1, 0x10
/* 800FF540 000FC340  4E 80 00 20 */	blr
.endfn kar_gryakupushoutwall_create_stage_linked_kind49_wall

# .text:0x704 | 0x800FF544 | size: 0x40
.fn kar_gryakupushoutwall_init_stage_linked_kind49_wall, global
/* 800FF544 000FC344  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FF548 000FC348  7C 08 02 A6 */	mflr r0
/* 800FF54C 000FC34C  38 80 00 00 */	li r4, 0x0
/* 800FF550 000FC350  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FF554 000FC354  80 A3 00 2C */	lwz r5, 0x2c(r3)
/* 800FF558 000FC358  90 85 01 30 */	stw r4, 0x130(r5)
/* 800FF55C 000FC35C  90 85 01 34 */	stw r4, 0x134(r5)
/* 800FF560 000FC360  90 85 01 38 */	stw r4, 0x138(r5)
/* 800FF564 000FC364  88 05 01 3C */	lbz r0, 0x13c(r5)
/* 800FF568 000FC368  50 80 3E 30 */	rlwimi r0, r4, 7, 24, 24
/* 800FF56C 000FC36C  98 05 01 3C */	stb r0, 0x13c(r5)
/* 800FF570 000FC370  48 00 00 15 */	bl kar_gryakupushoutwall_start_kind49_mode2_motion
/* 800FF574 000FC374  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FF578 000FC378  7C 08 03 A6 */	mtlr r0
/* 800FF57C 000FC37C  38 21 00 10 */	addi r1, r1, 0x10
/* 800FF580 000FC380  4E 80 00 20 */	blr
.endfn kar_gryakupushoutwall_init_stage_linked_kind49_wall

# .text:0x744 | 0x800FF584 | size: 0x48
.fn kar_gryakupushoutwall_start_kind49_mode2_motion, global
/* 800FF584 000FC384  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800FF588 000FC388  7C 08 02 A6 */	mflr r0
/* 800FF58C 000FC38C  C0 22 92 30 */	lfs f1, lbl_805DF930@sda21(r0)
/* 800FF590 000FC390  38 80 00 02 */	li r4, 0x2
/* 800FF594 000FC394  90 01 00 14 */	stw r0, 0x14(r1)
/* 800FF598 000FC398  38 A0 FF FF */	li r5, -0x1
/* 800FF59C 000FC39C  FC 40 08 90 */	fmr f2, f1
/* 800FF5A0 000FC3A0  38 E0 00 00 */	li r7, 0x0
/* 800FF5A4 000FC3A4  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800FF5A8 000FC3A8  FC 60 08 90 */	fmr f3, f1
/* 800FF5AC 000FC3AC  80 C3 00 08 */	lwz r6, 0x8(r3)
/* 800FF5B0 000FC3B0  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 800FF5B4 000FC3B4  80 C6 00 04 */	lwz r6, 0x4(r6)
/* 800FF5B8 000FC3B8  4B FF 5F 91 */	bl kar_gryaku_set_path_node_motion
/* 800FF5BC 000FC3BC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800FF5C0 000FC3C0  7C 08 03 A6 */	mtlr r0
/* 800FF5C4 000FC3C4  38 21 00 10 */	addi r1, r1, 0x10
/* 800FF5C8 000FC3C8  4E 80 00 20 */	blr
.endfn kar_gryakupushoutwall_start_kind49_mode2_motion

# 0x804A6430..0x804A6498 | size: 0x68
.data
.balign 8

# .data:0x0 | 0x804A6430 | size: 0x20
.obj kar_gryakucannon_kind48_callback_table, global
	.4byte kar_gryakucannon_update_pending_shot_queue
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte kar_gryakucannon_update_reload_and_pending_shots
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj kar_gryakucannon_kind48_callback_table

# .data:0x20 | 0x804A6450 | size: 0x14
.obj kar_gryakucannon_kind48_callback_table_ptr, global
	.4byte kar_gryakucannon_kind48_callback_table
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj kar_gryakucannon_kind48_callback_table_ptr

# .data:0x34 | 0x804A6464 | size: 0xF
.obj kar_src_gryakucannon_c, global
	.string "gryakucannon.c"
.endobj kar_src_gryakucannon_c

# .data:0x43 | 0x804A6473 | size: 0x1
.obj gap_07_804A6473_data, global
.hidden gap_07_804A6473_data
	.byte 0x00
.endobj gap_07_804A6473_data

# .data:0x44 | 0x804A6474 | size: 0x20
.obj kar_gryakucannon_assert_pending_user_gobj, global
	.string "gyp->lc.cannon.userInfo[i].gobj"
.endobj kar_gryakucannon_assert_pending_user_gobj

# .data:0x64 | 0x804A6494 | size: 0x4
.obj gap_07_804A6494_data, global
.hidden gap_07_804A6494_data
	.4byte 0x00000000
.endobj gap_07_804A6494_data

# 0x805D6278..0x805D6280 | size: 0x8
.section .sdata, "wa"
.balign 8

# .sdata:0x0 | 0x805D6278 | size: 0x2
.obj lbl_805D6278, global
	.string "0"
.endobj lbl_805D6278

# .sdata:0x2 | 0x805D627A | size: 0x6
.obj gap_09_805D627A_sdata, global
.hidden gap_09_805D627A_sdata
	.4byte 0x00000000
	.2byte 0x0000
.endobj gap_09_805D627A_sdata

# 0x805DF930..0x805DF938 | size: 0x8
.section .sdata2, "a"
.balign 8

# .sdata2:0x0 | 0x805DF930 | size: 0x8
.obj lbl_805DF930, global
	.float 0
	.float 0
.endobj lbl_805DF930
