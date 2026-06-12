.include "macros.inc"
.file "gryakupillar.c"

# 0x80100FEC..0x8010203C | size: 0x1050
.text
.balign 4

# .text:0x0 | 0x80100FEC | size: 0x11C
.fn kar_gryakupillar_init_kind53_pillar_controller, global
/* 80100FEC 000FDDEC  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80100FF0 000FDDF0  7C 08 02 A6 */	mflr r0
/* 80100FF4 000FDDF4  90 01 00 34 */	stw r0, 0x34(r1)
/* 80100FF8 000FDDF8  39 61 00 30 */	addi r11, r1, 0x30
/* 80100FFC 000FDDFC  48 2A CB 51 */	bl _savegpr_25
/* 80101000 000FDE00  7C 7E 1B 78 */	mr r30, r3
/* 80101004 000FDE04  3C 60 80 4A */	lis r3, kar_gryakulighttunnel_kind52_callback_table@ha
/* 80101008 000FDE08  83 7E 00 2C */	lwz r27, 0x2c(r30)
/* 8010100C 000FDE0C  3B A3 66 40 */	addi r29, r3, kar_gryakulighttunnel_kind52_callback_table@l
/* 80101010 000FDE10  83 44 00 2C */	lwz r26, 0x2c(r4)
/* 80101014 000FDE14  3B 20 00 00 */	li r25, 0x0
/* 80101018 000FDE18  80 7B 00 08 */	lwz r3, 0x8(r27)
/* 8010101C 000FDE1C  3B 80 00 00 */	li r28, 0x0
/* 80101020 000FDE20  83 E3 00 00 */	lwz r31, 0x0(r3)
/* 80101024 000FDE24  48 00 00 20 */	b .L_80101044
.L_80101028:
/* 80101028 000FDE28  80 BF 00 0C */	lwz r5, 0xc(r31)
/* 8010102C 000FDE2C  7F 43 D3 78 */	mr r3, r26
/* 80101030 000FDE30  7F C4 F3 78 */	mr r4, r30
/* 80101034 000FDE34  7C A5 E0 2E */	lwzx r5, r5, r28
/* 80101038 000FDE38  4B FE 76 95 */	bl kar_grswitch__near_800e86cc
/* 8010103C 000FDE3C  3B 9C 00 04 */	addi r28, r28, 0x4
/* 80101040 000FDE40  3B 39 00 01 */	addi r25, r25, 0x1
.L_80101044:
/* 80101044 000FDE44  80 1F 00 10 */	lwz r0, 0x10(r31)
/* 80101048 000FDE48  7C 19 00 00 */	cmpw r25, r0
/* 8010104C 000FDE4C  41 80 FF DC */	blt .L_80101028
/* 80101050 000FDE50  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 80101054 000FDE54  2C 00 00 07 */	cmpwi r0, 0x7
/* 80101058 000FDE58  40 81 00 14 */	ble .L_8010106C
/* 8010105C 000FDE5C  38 7D 00 78 */	addi r3, r29, 0x78
/* 80101060 000FDE60  38 BD 00 A8 */	addi r5, r29, 0xa8
/* 80101064 000FDE64  38 80 01 79 */	li r4, 0x179
/* 80101068 000FDE68  48 32 74 51 */	bl __assert
.L_8010106C:
/* 8010106C 000FDE6C  3B 40 00 00 */	li r26, 0x0
/* 80101070 000FDE70  7F 7C DB 78 */	mr r28, r27
/* 80101074 000FDE74  7F 5B D3 78 */	mr r27, r26
.L_80101078:
/* 80101078 000FDE78  38 A0 00 00 */	li r5, 0x0
/* 8010107C 000FDE7C  90 BC 01 30 */	stw r5, 0x130(r28)
/* 80101080 000FDE80  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 80101084 000FDE84  7C 1A 00 00 */	cmpw r26, r0
/* 80101088 000FDE88  40 80 00 4C */	bge .L_801010D4
/* 8010108C 000FDE8C  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 80101090 000FDE90  80 6D 12 54 */	lwz r3, lbl_805DE334@sda21(r0)
/* 80101094 000FDE94  7C 04 D8 2E */	lwzx r0, r4, r27
/* 80101098 000FDE98  80 63 00 20 */	lwz r3, 0x20(r3)
/* 8010109C 000FDE9C  48 00 00 18 */	b .L_801010B4
.L_801010A0:
/* 801010A0 000FDEA0  7C 00 28 00 */	cmpw r0, r5
/* 801010A4 000FDEA4  40 82 00 08 */	bne .L_801010AC
/* 801010A8 000FDEA8  48 00 00 28 */	b .L_801010D0
.L_801010AC:
/* 801010AC 000FDEAC  80 63 00 08 */	lwz r3, 0x8(r3)
/* 801010B0 000FDEB0  38 A5 00 01 */	addi r5, r5, 0x1
.L_801010B4:
/* 801010B4 000FDEB4  28 03 00 00 */	cmplwi r3, 0x0
/* 801010B8 000FDEB8  40 82 FF E8 */	bne .L_801010A0
/* 801010BC 000FDEBC  38 7D 00 D8 */	addi r3, r29, 0xd8
/* 801010C0 000FDEC0  38 80 09 6C */	li r4, 0x96c
/* 801010C4 000FDEC4  38 AD 91 D0 */	li r5, lbl_805D62B0@sda21
/* 801010C8 000FDEC8  48 32 73 F1 */	bl __assert
/* 801010CC 000FDECC  38 60 00 00 */	li r3, 0x0
.L_801010D0:
/* 801010D0 000FDED0  90 7C 01 30 */	stw r3, 0x130(r28)
.L_801010D4:
/* 801010D4 000FDED4  3B 5A 00 01 */	addi r26, r26, 0x1
/* 801010D8 000FDED8  3B 7B 00 04 */	addi r27, r27, 0x4
/* 801010DC 000FDEDC  2C 1A 00 07 */	cmpwi r26, 0x7
/* 801010E0 000FDEE0  3B 9C 00 04 */	addi r28, r28, 0x4
/* 801010E4 000FDEE4  41 80 FF 94 */	blt .L_80101078
/* 801010E8 000FDEE8  7F C3 F3 78 */	mr r3, r30
/* 801010EC 000FDEEC  48 00 00 1D */	bl kar_gryakupillar_start_kind53_controller_idle_motion
/* 801010F0 000FDEF0  39 61 00 30 */	addi r11, r1, 0x30
/* 801010F4 000FDEF4  48 2A CA A5 */	bl _restgpr_25
/* 801010F8 000FDEF8  80 01 00 34 */	lwz r0, 0x34(r1)
/* 801010FC 000FDEFC  7C 08 03 A6 */	mtlr r0
/* 80101100 000FDF00  38 21 00 30 */	addi r1, r1, 0x30
/* 80101104 000FDF04  4E 80 00 20 */	blr
.endfn kar_gryakupillar_init_kind53_pillar_controller

# .text:0x11C | 0x80101108 | size: 0x40
.fn kar_gryakupillar_start_kind53_controller_idle_motion, global
/* 80101108 000FDF08  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010110C 000FDF0C  7C 08 02 A6 */	mflr r0
/* 80101110 000FDF10  C0 22 92 48 */	lfs f1, lbl_805DF948@sda21(r0)
/* 80101114 000FDF14  38 80 00 00 */	li r4, 0x0
/* 80101118 000FDF18  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010111C 000FDF1C  38 A0 FF FF */	li r5, -0x1
/* 80101120 000FDF20  FC 40 08 90 */	fmr f2, f1
/* 80101124 000FDF24  38 C0 FF FF */	li r6, -0x1
/* 80101128 000FDF28  FC 60 08 90 */	fmr f3, f1
/* 8010112C 000FDF2C  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80101130 000FDF30  38 E0 00 00 */	li r7, 0x0
/* 80101134 000FDF34  4B FF 44 15 */	bl kar_gryaku_set_path_node_motion
/* 80101138 000FDF38  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010113C 000FDF3C  7C 08 03 A6 */	mtlr r0
/* 80101140 000FDF40  38 21 00 10 */	addi r1, r1, 0x10
/* 80101144 000FDF44  4E 80 00 20 */	blr
.endfn kar_gryakupillar_start_kind53_controller_idle_motion

# .text:0x15C | 0x80101148 | size: 0x180
.fn kar_gryakupillar_trigger_kind53_random_child_pillars, global
/* 80101148 000FDF48  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8010114C 000FDF4C  7C 08 02 A6 */	mflr r0
/* 80101150 000FDF50  90 01 00 34 */	stw r0, 0x34(r1)
/* 80101154 000FDF54  39 61 00 30 */	addi r11, r1, 0x30
/* 80101158 000FDF58  48 2A C9 F1 */	bl _savegpr_24
/* 8010115C 000FDF5C  83 03 00 2C */	lwz r24, 0x2c(r3)
/* 80101160 000FDF60  3C 60 80 4A */	lis r3, kar_gryakulighttunnel_kind52_callback_table@ha
/* 80101164 000FDF64  7C 99 23 78 */	mr r25, r4
/* 80101168 000FDF68  80 18 00 04 */	lwz r0, 0x4(r24)
/* 8010116C 000FDF6C  3B E3 66 40 */	addi r31, r3, kar_gryakulighttunnel_kind52_callback_table@l
/* 80101170 000FDF70  2C 00 00 35 */	cmpwi r0, 0x35
/* 80101174 000FDF74  41 82 00 14 */	beq .L_80101188
/* 80101178 000FDF78  38 7F 00 78 */	addi r3, r31, 0x78
/* 8010117C 000FDF7C  38 BF 00 E4 */	addi r5, r31, 0xe4
/* 80101180 000FDF80  38 80 01 AB */	li r4, 0x1ab
/* 80101184 000FDF84  48 32 73 35 */	bl __assert
.L_80101188:
/* 80101188 000FDF88  28 19 00 00 */	cmplwi r25, 0x0
/* 8010118C 000FDF8C  40 82 00 14 */	bne .L_801011A0
/* 80101190 000FDF90  38 7F 00 78 */	addi r3, r31, 0x78
/* 80101194 000FDF94  38 BF 01 08 */	addi r5, r31, 0x108
/* 80101198 000FDF98  38 80 01 AC */	li r4, 0x1ac
/* 8010119C 000FDF9C  48 32 73 1D */	bl __assert
.L_801011A0:
/* 801011A0 000FDFA0  80 98 00 08 */	lwz r4, 0x8(r24)
/* 801011A4 000FDFA4  7F 23 CB 78 */	mr r3, r25
/* 801011A8 000FDFA8  83 A4 00 00 */	lwz r29, 0x0(r4)
/* 801011AC 000FDFAC  48 0C 6B 49 */	bl fn_801C7CF4
/* 801011B0 000FDFB0  4B F0 83 85 */	bl fn_80009534
/* 801011B4 000FDFB4  7C 7A 1B 78 */	mr r26, r3
/* 801011B8 000FDFB8  80 1D 00 08 */	lwz r0, 0x8(r29)
/* 801011BC 000FDFBC  7F 43 07 74 */	extsb r3, r26
/* 801011C0 000FDFC0  7C 03 00 00 */	cmpw r3, r0
/* 801011C4 000FDFC4  41 80 00 14 */	blt .L_801011D8
/* 801011C8 000FDFC8  38 7F 00 78 */	addi r3, r31, 0x78
/* 801011CC 000FDFCC  38 BF 01 18 */	addi r5, r31, 0x118
/* 801011D0 000FDFD0  38 80 01 B8 */	li r4, 0x1b8
/* 801011D4 000FDFD4  48 32 72 E5 */	bl __assert
.L_801011D8:
/* 801011D8 000FDFD8  7F 40 07 74 */	extsb r0, r26
/* 801011DC 000FDFDC  80 9D 00 04 */	lwz r4, 0x4(r29)
/* 801011E0 000FDFE0  54 00 10 3A */	slwi r0, r0, 2
/* 801011E4 000FDFE4  80 7D 00 18 */	lwz r3, 0x18(r29)
/* 801011E8 000FDFE8  7C 84 00 2E */	lwzx r4, r4, r0
/* 801011EC 000FDFEC  4B FF 6C 85 */	bl kar_gryakulib_random_choose_k_of_n_mask
/* 801011F0 000FDFF0  7F 1E C3 78 */	mr r30, r24
/* 801011F4 000FDFF4  7C 7C 1B 78 */	mr r28, r3
/* 801011F8 000FDFF8  3B 60 00 00 */	li r27, 0x0
/* 801011FC 000FDFFC  48 00 00 A8 */	b .L_801012A4
.L_80101200:
/* 80101200 000FE000  57 80 07 FF */	clrlwi. r0, r28, 31
/* 80101204 000FE004  41 82 00 94 */	beq .L_80101298
/* 80101208 000FE008  80 7D 00 00 */	lwz r3, 0x0(r29)
/* 8010120C 000FE00C  48 31 D4 5D */	bl HSD_Randi
/* 80101210 000FE010  83 1E 01 30 */	lwz r24, 0x130(r30)
/* 80101214 000FE014  7C 7A 1B 78 */	mr r26, r3
/* 80101218 000FE018  83 38 00 2C */	lwz r25, 0x2c(r24)
/* 8010121C 000FE01C  80 19 00 04 */	lwz r0, 0x4(r25)
/* 80101220 000FE020  2C 00 00 34 */	cmpwi r0, 0x34
/* 80101224 000FE024  41 82 00 14 */	beq .L_80101238
/* 80101228 000FE028  38 7F 00 78 */	addi r3, r31, 0x78
/* 8010122C 000FE02C  38 BF 00 88 */	addi r5, r31, 0x88
/* 80101230 000FE030  38 80 01 45 */	li r4, 0x145
/* 80101234 000FE034  48 32 72 85 */	bl __assert
.L_80101238:
/* 80101238 000FE038  88 19 01 48 */	lbz r0, 0x148(r25)
/* 8010123C 000FE03C  54 00 CF FF */	extrwi. r0, r0, 1, 24
/* 80101240 000FE040  40 82 00 58 */	bne .L_80101298
/* 80101244 000FE044  93 59 01 3C */	stw r26, 0x13c(r25)
/* 80101248 000FE048  38 60 00 01 */	li r3, 0x1
/* 8010124C 000FE04C  88 19 01 48 */	lbz r0, 0x148(r25)
/* 80101250 000FE050  50 60 3E 30 */	rlwimi r0, r3, 7, 24, 24
/* 80101254 000FE054  98 19 01 48 */	stb r0, 0x148(r25)
/* 80101258 000FE058  80 19 01 3C */	lwz r0, 0x13c(r25)
/* 8010125C 000FE05C  2C 00 00 00 */	cmpwi r0, 0x0
/* 80101260 000FE060  41 81 00 38 */	bgt .L_80101298
/* 80101264 000FE064  80 78 00 2C */	lwz r3, 0x2c(r24)
/* 80101268 000FE068  38 80 00 01 */	li r4, 0x1
/* 8010126C 000FE06C  C0 22 92 48 */	lfs f1, lbl_805DF948@sda21(r0)
/* 80101270 000FE070  38 E0 00 00 */	li r7, 0x0
/* 80101274 000FE074  80 A3 00 08 */	lwz r5, 0x8(r3)
/* 80101278 000FE078  FC 60 08 90 */	fmr f3, f1
/* 8010127C 000FE07C  C0 42 92 4C */	lfs f2, lbl_805DF94C@sda21(r0)
/* 80101280 000FE080  80 C5 00 00 */	lwz r6, 0x0(r5)
/* 80101284 000FE084  80 06 00 1C */	lwz r0, 0x1c(r6)
/* 80101288 000FE088  90 03 01 38 */	stw r0, 0x138(r3)
/* 8010128C 000FE08C  80 A6 00 0C */	lwz r5, 0xc(r6)
/* 80101290 000FE090  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 80101294 000FE094  4B FF 42 B5 */	bl kar_gryaku_set_path_node_motion
.L_80101298:
/* 80101298 000FE098  57 9C F8 7E */	srwi r28, r28, 1
/* 8010129C 000FE09C  3B DE 00 04 */	addi r30, r30, 0x4
/* 801012A0 000FE0A0  3B 7B 00 01 */	addi r27, r27, 0x1
.L_801012A4:
/* 801012A4 000FE0A4  80 1D 00 18 */	lwz r0, 0x18(r29)
/* 801012A8 000FE0A8  7C 1B 00 00 */	cmpw r27, r0
/* 801012AC 000FE0AC  41 80 FF 54 */	blt .L_80101200
/* 801012B0 000FE0B0  39 61 00 30 */	addi r11, r1, 0x30
/* 801012B4 000FE0B4  48 2A C8 E1 */	bl _restgpr_24
/* 801012B8 000FE0B8  80 01 00 34 */	lwz r0, 0x34(r1)
/* 801012BC 000FE0BC  7C 08 03 A6 */	mtlr r0
/* 801012C0 000FE0C0  38 21 00 30 */	addi r1, r1, 0x30
/* 801012C4 000FE0C4  4E 80 00 20 */	blr
.endfn kar_gryakupillar_trigger_kind53_random_child_pillars

# .text:0x2DC | 0x801012C8 | size: 0x38
.fn kar_gryakupillar_create_stage_linked_kind39_ice_pillar, global
/* 801012C8 000FE0C8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801012CC 000FE0CC  7C 08 02 A6 */	mflr r0
/* 801012D0 000FE0D0  90 01 00 14 */	stw r0, 0x14(r1)
/* 801012D4 000FE0D4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801012D8 000FE0D8  7C 7F 1B 78 */	mr r31, r3
/* 801012DC 000FE0DC  38 60 00 27 */	li r3, 0x27
/* 801012E0 000FE0E0  4B FF 31 8D */	bl kar_gryaku_create_yaku_from_main_kind
/* 801012E4 000FE0E4  7F E4 FB 78 */	mr r4, r31
/* 801012E8 000FE0E8  48 00 00 19 */	bl kar_gryakupillar_init_kind39_ice_pillar
/* 801012EC 000FE0EC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801012F0 000FE0F0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801012F4 000FE0F4  7C 08 03 A6 */	mtlr r0
/* 801012F8 000FE0F8  38 21 00 10 */	addi r1, r1, 0x10
/* 801012FC 000FE0FC  4E 80 00 20 */	blr
.endfn kar_gryakupillar_create_stage_linked_kind39_ice_pillar

# .text:0x314 | 0x80101300 | size: 0xC8
.fn kar_gryakupillar_init_kind39_ice_pillar, global
/* 80101300 000FE100  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80101304 000FE104  7C 08 02 A6 */	mflr r0
/* 80101308 000FE108  90 01 00 24 */	stw r0, 0x24(r1)
/* 8010130C 000FE10C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80101310 000FE110  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80101314 000FE114  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80101318 000FE118  7C 7D 1B 78 */	mr r29, r3
/* 8010131C 000FE11C  83 FD 00 2C */	lwz r31, 0x2c(r29)
/* 80101320 000FE120  80 64 00 2C */	lwz r3, 0x2c(r4)
/* 80101324 000FE124  80 DF 00 08 */	lwz r6, 0x8(r31)
/* 80101328 000FE128  80 83 01 04 */	lwz r4, 0x104(r3)
/* 8010132C 000FE12C  83 C6 00 00 */	lwz r30, 0x0(r6)
/* 80101330 000FE130  80 AD 05 EC */	lwz r5, lbl_805DD6CC@sda21(r0)
/* 80101334 000FE134  80 1E 00 04 */	lwz r0, 0x4(r30)
/* 80101338 000FE138  38 65 00 54 */	addi r3, r5, 0x54
/* 8010133C 000FE13C  54 00 18 38 */	slwi r0, r0, 3
/* 80101340 000FE140  7C 84 00 2E */	lwzx r4, r4, r0
/* 80101344 000FE144  4B FD 66 11 */	bl kar_grcoll__800d7954
/* 80101348 000FE148  90 7F 01 30 */	stw r3, 0x130(r31)
/* 8010134C 000FE14C  38 00 00 00 */	li r0, 0x0
/* 80101350 000FE150  80 9F 00 00 */	lwz r4, 0x0(r31)
/* 80101354 000FE154  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 80101358 000FE158  90 83 00 90 */	stw r4, 0x90(r3)
/* 8010135C 000FE15C  90 1F 01 34 */	stw r0, 0x134(r31)
/* 80101360 000FE160  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80101364 000FE164  80 03 00 14 */	lwz r0, 0x14(r3)
/* 80101368 000FE168  28 00 00 00 */	cmplwi r0, 0x0
/* 8010136C 000FE16C  41 82 00 38 */	beq .L_801013A4
/* 80101370 000FE170  80 1E 00 0C */	lwz r0, 0xc(r30)
/* 80101374 000FE174  2C 00 00 00 */	cmpwi r0, 0x0
/* 80101378 000FE178  40 81 00 1C */	ble .L_80101394
/* 8010137C 000FE17C  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 80101380 000FE180  7F A3 EB 78 */	mr r3, r29
/* 80101384 000FE184  38 A0 00 00 */	li r5, 0x0
/* 80101388 000FE188  80 84 00 00 */	lwz r4, 0x0(r4)
/* 8010138C 000FE18C  4B FF 64 E5 */	bl kar_gryakuaudio_configure_fgm_track_from_joint
/* 80101390 000FE190  48 00 00 14 */	b .L_801013A4
.L_80101394:
/* 80101394 000FE194  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 80101398 000FE198  7F A3 EB 78 */	mr r3, r29
/* 8010139C 000FE19C  38 A0 00 00 */	li r5, 0x0
/* 801013A0 000FE1A0  4B FF 64 D1 */	bl kar_gryakuaudio_configure_fgm_track_from_joint
.L_801013A4:
/* 801013A4 000FE1A4  7F A3 EB 78 */	mr r3, r29
/* 801013A8 000FE1A8  48 00 00 21 */	bl kar_gryakupillar_start_kind39_raised_motion
/* 801013AC 000FE1AC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801013B0 000FE1B0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801013B4 000FE1B4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801013B8 000FE1B8  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 801013BC 000FE1BC  7C 08 03 A6 */	mtlr r0
/* 801013C0 000FE1C0  38 21 00 20 */	addi r1, r1, 0x20
/* 801013C4 000FE1C4  4E 80 00 20 */	blr
.endfn kar_gryakupillar_init_kind39_ice_pillar

# .text:0x3DC | 0x801013C8 | size: 0xBC
.fn kar_gryakupillar_start_kind39_raised_motion, global
/* 801013C8 000FE1C8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801013CC 000FE1CC  7C 08 02 A6 */	mflr r0
/* 801013D0 000FE1D0  90 01 00 14 */	stw r0, 0x14(r1)
/* 801013D4 000FE1D4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801013D8 000FE1D8  93 C1 00 08 */	stw r30, 0x8(r1)
/* 801013DC 000FE1DC  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 801013E0 000FE1E0  80 AD 05 EC */	lwz r5, lbl_805DD6CC@sda21(r0)
/* 801013E4 000FE1E4  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 801013E8 000FE1E8  83 C3 00 00 */	lwz r30, 0x0(r3)
/* 801013EC 000FE1EC  80 1E 00 28 */	lwz r0, 0x28(r30)
/* 801013F0 000FE1F0  2C 00 00 00 */	cmpwi r0, 0x0
/* 801013F4 000FE1F4  41 82 00 1C */	beq .L_80101410
/* 801013F8 000FE1F8  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 801013FC 000FE1FC  38 80 00 10 */	li r4, 0x10
/* 80101400 000FE200  80 65 01 04 */	lwz r3, 0x104(r5)
/* 80101404 000FE204  54 00 18 38 */	slwi r0, r0, 3
/* 80101408 000FE208  7C 63 00 2E */	lwzx r3, r3, r0
/* 8010140C 000FE20C  48 30 AD 69 */	bl HSD_JObjClearFlagsAll
.L_80101410:
/* 80101410 000FE210  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 80101414 000FE214  38 80 00 01 */	li r4, 0x1
/* 80101418 000FE218  4B FD 66 B9 */	bl kar_grcoll__near_800d7ad0
/* 8010141C 000FE21C  80 7F 00 EC */	lwz r3, 0xec(r31)
/* 80101420 000FE220  48 08 B7 09 */	bl kar_collision_object_end_disable
/* 80101424 000FE224  80 1F 01 1C */	lwz r0, 0x11c(r31)
/* 80101428 000FE228  2C 00 00 00 */	cmpwi r0, 0x0
/* 8010142C 000FE22C  40 81 00 10 */	ble .L_8010143C
/* 80101430 000FE230  38 7F 01 18 */	addi r3, r31, 0x118
/* 80101434 000FE234  38 80 00 01 */	li r4, 0x1
/* 80101438 000FE238  4B FE 8C 4D */	bl kar_graudio_play_fgm_entry_id
.L_8010143C:
/* 8010143C 000FE23C  C0 22 92 50 */	lfs f1, lbl_805DF950@sda21(r0)
/* 80101440 000FE240  7F E3 FB 78 */	mr r3, r31
/* 80101444 000FE244  80 BE 00 14 */	lwz r5, 0x14(r30)
/* 80101448 000FE248  38 80 00 03 */	li r4, 0x3
/* 8010144C 000FE24C  FC 60 08 90 */	fmr f3, f1
/* 80101450 000FE250  80 DE 00 00 */	lwz r6, 0x0(r30)
/* 80101454 000FE254  C0 42 92 54 */	lfs f2, lbl_805DF954@sda21(r0)
/* 80101458 000FE258  38 E0 00 00 */	li r7, 0x0
/* 8010145C 000FE25C  4B FF 40 ED */	bl kar_gryaku_set_path_node_motion
/* 80101460 000FE260  3C 60 80 10 */	lis r3, kar_gryakupillar_trigger_kind39_contact_drop@ha
/* 80101464 000FE264  38 03 16 B8 */	addi r0, r3, kar_gryakupillar_trigger_kind39_contact_drop@l
/* 80101468 000FE268  90 1F 01 00 */	stw r0, 0x100(r31)
/* 8010146C 000FE26C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80101470 000FE270  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80101474 000FE274  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80101478 000FE278  7C 08 03 A6 */	mtlr r0
/* 8010147C 000FE27C  38 21 00 10 */	addi r1, r1, 0x10
/* 80101480 000FE280  4E 80 00 20 */	blr
.endfn kar_gryakupillar_start_kind39_raised_motion

# .text:0x498 | 0x80101484 | size: 0x84
.fn kar_gryakupillar_update_kind39_drop_delay_to_mode2, global
/* 80101484 000FE284  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80101488 000FE288  7C 08 02 A6 */	mflr r0
/* 8010148C 000FE28C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80101490 000FE290  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80101494 000FE294  80 A3 00 2C */	lwz r5, 0x2c(r3)
/* 80101498 000FE298  80 85 01 34 */	lwz r4, 0x134(r5)
/* 8010149C 000FE29C  38 04 FF FF */	subi r0, r4, 0x1
/* 801014A0 000FE2A0  90 05 01 34 */	stw r0, 0x134(r5)
/* 801014A4 000FE2A4  80 05 01 34 */	lwz r0, 0x134(r5)
/* 801014A8 000FE2A8  2C 00 00 05 */	cmpwi r0, 0x5
/* 801014AC 000FE2AC  41 81 00 48 */	bgt .L_801014F4
/* 801014B0 000FE2B0  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 801014B4 000FE2B4  38 00 00 05 */	li r0, 0x5
/* 801014B8 000FE2B8  C0 22 92 50 */	lfs f1, lbl_805DF950@sda21(r0)
/* 801014BC 000FE2BC  38 80 00 02 */	li r4, 0x2
/* 801014C0 000FE2C0  80 BF 00 08 */	lwz r5, 0x8(r31)
/* 801014C4 000FE2C4  7F E3 FB 78 */	mr r3, r31
/* 801014C8 000FE2C8  FC 40 08 90 */	fmr f2, f1
/* 801014CC 000FE2CC  38 E0 00 00 */	li r7, 0x0
/* 801014D0 000FE2D0  80 C5 00 00 */	lwz r6, 0x0(r5)
/* 801014D4 000FE2D4  FC 60 08 90 */	fmr f3, f1
/* 801014D8 000FE2D8  90 1F 01 34 */	stw r0, 0x134(r31)
/* 801014DC 000FE2DC  80 A6 00 14 */	lwz r5, 0x14(r6)
/* 801014E0 000FE2E0  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 801014E4 000FE2E4  4B FF 40 65 */	bl kar_gryaku_set_path_node_motion
/* 801014E8 000FE2E8  3C 60 80 10 */	lis r3, kar_gryakupillar_trigger_kind39_contact_drop@ha
/* 801014EC 000FE2EC  38 03 16 B8 */	addi r0, r3, kar_gryakupillar_trigger_kind39_contact_drop@l
/* 801014F0 000FE2F0  90 1F 01 00 */	stw r0, 0x100(r31)
.L_801014F4:
/* 801014F4 000FE2F4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801014F8 000FE2F8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801014FC 000FE2FC  7C 08 03 A6 */	mtlr r0
/* 80101500 000FE300  38 21 00 10 */	addi r1, r1, 0x10
/* 80101504 000FE304  4E 80 00 20 */	blr
.endfn kar_gryakupillar_update_kind39_drop_delay_to_mode2

# .text:0x51C | 0x80101508 | size: 0xD8
.fn kar_gryakupillar_update_kind39_respawn_to_raised, global
/* 80101508 000FE308  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010150C 000FE30C  7C 08 02 A6 */	mflr r0
/* 80101510 000FE310  90 01 00 14 */	stw r0, 0x14(r1)
/* 80101514 000FE314  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80101518 000FE318  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8010151C 000FE31C  80 A3 00 2C */	lwz r5, 0x2c(r3)
/* 80101520 000FE320  80 85 01 34 */	lwz r4, 0x134(r5)
/* 80101524 000FE324  38 04 FF FF */	subi r0, r4, 0x1
/* 80101528 000FE328  90 05 01 34 */	stw r0, 0x134(r5)
/* 8010152C 000FE32C  80 05 01 34 */	lwz r0, 0x134(r5)
/* 80101530 000FE330  2C 00 00 00 */	cmpwi r0, 0x0
/* 80101534 000FE334  41 81 00 94 */	bgt .L_801015C8
/* 80101538 000FE338  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 8010153C 000FE33C  80 AD 05 EC */	lwz r5, lbl_805DD6CC@sda21(r0)
/* 80101540 000FE340  80 7E 00 08 */	lwz r3, 0x8(r30)
/* 80101544 000FE344  83 E3 00 00 */	lwz r31, 0x0(r3)
/* 80101548 000FE348  80 1F 00 28 */	lwz r0, 0x28(r31)
/* 8010154C 000FE34C  2C 00 00 00 */	cmpwi r0, 0x0
/* 80101550 000FE350  41 82 00 1C */	beq .L_8010156C
/* 80101554 000FE354  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 80101558 000FE358  38 80 00 10 */	li r4, 0x10
/* 8010155C 000FE35C  80 65 01 04 */	lwz r3, 0x104(r5)
/* 80101560 000FE360  54 00 18 38 */	slwi r0, r0, 3
/* 80101564 000FE364  7C 63 00 2E */	lwzx r3, r3, r0
/* 80101568 000FE368  48 30 AC 0D */	bl HSD_JObjClearFlagsAll
.L_8010156C:
/* 8010156C 000FE36C  80 7E 01 30 */	lwz r3, 0x130(r30)
/* 80101570 000FE370  38 80 00 01 */	li r4, 0x1
/* 80101574 000FE374  4B FD 65 5D */	bl kar_grcoll__near_800d7ad0
/* 80101578 000FE378  80 7E 00 EC */	lwz r3, 0xec(r30)
/* 8010157C 000FE37C  48 08 B5 AD */	bl kar_collision_object_end_disable
/* 80101580 000FE380  80 1E 01 1C */	lwz r0, 0x11c(r30)
/* 80101584 000FE384  2C 00 00 00 */	cmpwi r0, 0x0
/* 80101588 000FE388  40 81 00 10 */	ble .L_80101598
/* 8010158C 000FE38C  38 7E 01 18 */	addi r3, r30, 0x118
/* 80101590 000FE390  38 80 00 01 */	li r4, 0x1
/* 80101594 000FE394  4B FE 8A F1 */	bl kar_graudio_play_fgm_entry_id
.L_80101598:
/* 80101598 000FE398  C0 22 92 50 */	lfs f1, lbl_805DF950@sda21(r0)
/* 8010159C 000FE39C  7F C3 F3 78 */	mr r3, r30
/* 801015A0 000FE3A0  80 BF 00 14 */	lwz r5, 0x14(r31)
/* 801015A4 000FE3A4  38 80 00 03 */	li r4, 0x3
/* 801015A8 000FE3A8  FC 60 08 90 */	fmr f3, f1
/* 801015AC 000FE3AC  80 DF 00 00 */	lwz r6, 0x0(r31)
/* 801015B0 000FE3B0  C0 42 92 54 */	lfs f2, lbl_805DF954@sda21(r0)
/* 801015B4 000FE3B4  38 E0 00 00 */	li r7, 0x0
/* 801015B8 000FE3B8  4B FF 3F 91 */	bl kar_gryaku_set_path_node_motion
/* 801015BC 000FE3BC  3C 60 80 10 */	lis r3, kar_gryakupillar_trigger_kind39_contact_drop@ha
/* 801015C0 000FE3C0  38 03 16 B8 */	addi r0, r3, kar_gryakupillar_trigger_kind39_contact_drop@l
/* 801015C4 000FE3C4  90 1E 01 00 */	stw r0, 0x100(r30)
.L_801015C8:
/* 801015C8 000FE3C8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801015CC 000FE3CC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801015D0 000FE3D0  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 801015D4 000FE3D4  7C 08 03 A6 */	mtlr r0
/* 801015D8 000FE3D8  38 21 00 10 */	addi r1, r1, 0x10
/* 801015DC 000FE3DC  4E 80 00 20 */	blr
.endfn kar_gryakupillar_update_kind39_respawn_to_raised

# .text:0x5F4 | 0x801015E0 | size: 0xD8
.fn kar_gryakupillar_update_kind39_ground_clear_to_idle, global
/* 801015E0 000FE3E0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801015E4 000FE3E4  7C 08 02 A6 */	mflr r0
/* 801015E8 000FE3E8  90 01 00 24 */	stw r0, 0x24(r1)
/* 801015EC 000FE3EC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801015F0 000FE3F0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801015F4 000FE3F4  93 A1 00 14 */	stw r29, 0x14(r1)
/* 801015F8 000FE3F8  7C 7D 1B 78 */	mr r29, r3
/* 801015FC 000FE3FC  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 80101600 000FE400  83 ED 05 EC */	lwz r31, lbl_805DD6CC@sda21(r0)
/* 80101604 000FE404  80 84 00 08 */	lwz r4, 0x8(r4)
/* 80101608 000FE408  80 04 00 14 */	lwz r0, 0x14(r4)
/* 8010160C 000FE40C  83 C4 00 00 */	lwz r30, 0x0(r4)
/* 80101610 000FE410  28 00 00 00 */	cmplwi r0, 0x0
/* 80101614 000FE414  41 82 00 30 */	beq .L_80101644
/* 80101618 000FE418  80 1E 00 0C */	lwz r0, 0xc(r30)
/* 8010161C 000FE41C  2C 00 00 00 */	cmpwi r0, 0x0
/* 80101620 000FE420  40 81 00 18 */	ble .L_80101638
/* 80101624 000FE424  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 80101628 000FE428  38 A0 00 00 */	li r5, 0x0
/* 8010162C 000FE42C  80 84 00 00 */	lwz r4, 0x0(r4)
/* 80101630 000FE430  4B FF 62 41 */	bl kar_gryakuaudio_configure_fgm_track_from_joint
/* 80101634 000FE434  48 00 00 10 */	b .L_80101644
.L_80101638:
/* 80101638 000FE438  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 8010163C 000FE43C  38 A0 00 00 */	li r5, 0x0
/* 80101640 000FE440  4B FF 62 31 */	bl kar_gryakuaudio_configure_fgm_track_from_joint
.L_80101644:
/* 80101644 000FE444  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 80101648 000FE448  80 7F 01 04 */	lwz r3, 0x104(r31)
/* 8010164C 000FE44C  54 00 18 38 */	slwi r0, r0, 3
/* 80101650 000FE450  7C 63 00 2E */	lwzx r3, r3, r0
/* 80101654 000FE454  4B F5 31 8D */	bl kar_gmlanmenu__near_800547e0
/* 80101658 000FE458  2C 03 00 00 */	cmpwi r3, 0x0
/* 8010165C 000FE45C  40 82 00 40 */	bne .L_8010169C
/* 80101660 000FE460  83 FD 00 2C */	lwz r31, 0x2c(r29)
/* 80101664 000FE464  38 80 00 00 */	li r4, 0x0
/* 80101668 000FE468  C0 22 92 50 */	lfs f1, lbl_805DF950@sda21(r0)
/* 8010166C 000FE46C  38 A0 FF FF */	li r5, -0x1
/* 80101670 000FE470  80 DF 00 08 */	lwz r6, 0x8(r31)
/* 80101674 000FE474  7F E3 FB 78 */	mr r3, r31
/* 80101678 000FE478  FC 40 08 90 */	fmr f2, f1
/* 8010167C 000FE47C  38 E0 00 00 */	li r7, 0x0
/* 80101680 000FE480  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 80101684 000FE484  FC 60 08 90 */	fmr f3, f1
/* 80101688 000FE488  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 8010168C 000FE48C  4B FF 3E BD */	bl kar_gryaku_set_path_node_motion
/* 80101690 000FE490  3C 60 80 10 */	lis r3, kar_gryakupillar_trigger_kind39_contact_drop@ha
/* 80101694 000FE494  38 03 16 B8 */	addi r0, r3, kar_gryakupillar_trigger_kind39_contact_drop@l
/* 80101698 000FE498  90 1F 01 00 */	stw r0, 0x100(r31)
.L_8010169C:
/* 8010169C 000FE49C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801016A0 000FE4A0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801016A4 000FE4A4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801016A8 000FE4A8  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 801016AC 000FE4AC  7C 08 03 A6 */	mtlr r0
/* 801016B0 000FE4B0  38 21 00 20 */	addi r1, r1, 0x20
/* 801016B4 000FE4B4  4E 80 00 20 */	blr
.endfn kar_gryakupillar_update_kind39_ground_clear_to_idle

# .text:0x6CC | 0x801016B8 | size: 0x164
.fn kar_gryakupillar_trigger_kind39_contact_drop, global
/* 801016B8 000FE4B8  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 801016BC 000FE4BC  7C 08 02 A6 */	mflr r0
/* 801016C0 000FE4C0  90 01 00 34 */	stw r0, 0x34(r1)
/* 801016C4 000FE4C4  39 61 00 30 */	addi r11, r1, 0x30
/* 801016C8 000FE4C8  48 2A C4 85 */	bl _savegpr_25
/* 801016CC 000FE4CC  7C 7E 1B 78 */	mr r30, r3
/* 801016D0 000FE4D0  C0 24 00 0C */	lfs f1, 0xc(r4)
/* 801016D4 000FE4D4  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 801016D8 000FE4D8  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 801016DC 000FE4DC  80 63 00 00 */	lwz r3, 0x0(r3)
/* 801016E0 000FE4E0  C0 03 00 24 */	lfs f0, 0x24(r3)
/* 801016E4 000FE4E4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801016E8 000FE4E8  40 81 01 1C */	ble .L_80101804
/* 801016EC 000FE4EC  80 04 00 38 */	lwz r0, 0x38(r4)
/* 801016F0 000FE4F0  2C 00 00 06 */	cmpwi r0, 0x6
/* 801016F4 000FE4F4  40 80 00 18 */	bge .L_8010170C
/* 801016F8 000FE4F8  2C 00 00 04 */	cmpwi r0, 0x4
/* 801016FC 000FE4FC  40 80 01 08 */	bge .L_80101804
/* 80101700 000FE500  2C 00 00 00 */	cmpwi r0, 0x0
/* 80101704 000FE504  40 80 00 10 */	bge .L_80101714
/* 80101708 000FE508  48 00 00 FC */	b .L_80101804
.L_8010170C:
/* 8010170C 000FE50C  2C 00 00 08 */	cmpwi r0, 0x8
/* 80101710 000FE510  40 80 00 F4 */	bge .L_80101804
.L_80101714:
/* 80101714 000FE514  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80101718 000FE518  80 AD 05 EC */	lwz r5, lbl_805DD6CC@sda21(r0)
/* 8010171C 000FE51C  83 63 00 00 */	lwz r27, 0x0(r3)
/* 80101720 000FE520  80 1B 00 28 */	lwz r0, 0x28(r27)
/* 80101724 000FE524  2C 00 00 00 */	cmpwi r0, 0x0
/* 80101728 000FE528  41 82 00 1C */	beq .L_80101744
/* 8010172C 000FE52C  80 1B 00 00 */	lwz r0, 0x0(r27)
/* 80101730 000FE530  38 80 00 10 */	li r4, 0x10
/* 80101734 000FE534  80 65 01 04 */	lwz r3, 0x104(r5)
/* 80101738 000FE538  54 00 18 38 */	slwi r0, r0, 3
/* 8010173C 000FE53C  7C 63 00 2E */	lwzx r3, r3, r0
/* 80101740 000FE540  48 30 A6 C1 */	bl HSD_JObjSetFlagsAll
.L_80101744:
/* 80101744 000FE544  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 80101748 000FE548  38 80 00 00 */	li r4, 0x0
/* 8010174C 000FE54C  4B FD 63 85 */	bl kar_grcoll__near_800d7ad0
/* 80101750 000FE550  80 7F 00 EC */	lwz r3, 0xec(r31)
/* 80101754 000FE554  48 08 B3 B1 */	bl kar_collision_object_begin_disable
/* 80101758 000FE558  3B 80 00 00 */	li r28, 0x0
/* 8010175C 000FE55C  7F 99 E3 78 */	mr r25, r28
/* 80101760 000FE560  48 00 00 54 */	b .L_801017B4
.L_80101764:
/* 80101764 000FE564  3B A0 00 00 */	li r29, 0x0
/* 80101768 000FE568  7F BA EB 78 */	mr r26, r29
/* 8010176C 000FE56C  48 00 00 34 */	b .L_801017A0
.L_80101770:
/* 80101770 000FE570  80 1B 00 08 */	lwz r0, 0x8(r27)
/* 80101774 000FE574  7F C3 F3 78 */	mr r3, r30
/* 80101778 000FE578  80 9B 00 18 */	lwz r4, 0x18(r27)
/* 8010177C 000FE57C  38 C0 00 00 */	li r6, 0x0
/* 80101780 000FE580  7C B9 00 2E */	lwzx r5, r25, r0
/* 80101784 000FE584  38 E0 00 00 */	li r7, 0x0
/* 80101788 000FE588  7C 84 D2 14 */	add r4, r4, r26
/* 8010178C 000FE58C  39 00 00 00 */	li r8, 0x0
/* 80101790 000FE590  39 20 00 00 */	li r9, 0x0
/* 80101794 000FE594  4B FF 58 B1 */	bl kar_gryakueffect_request_by_entry_mode
/* 80101798 000FE598  3B 5A 00 1C */	addi r26, r26, 0x1c
/* 8010179C 000FE59C  3B BD 00 01 */	addi r29, r29, 0x1
.L_801017A0:
/* 801017A0 000FE5A0  80 1B 00 1C */	lwz r0, 0x1c(r27)
/* 801017A4 000FE5A4  7C 1D 00 00 */	cmpw r29, r0
/* 801017A8 000FE5A8  41 80 FF C8 */	blt .L_80101770
/* 801017AC 000FE5AC  3B 39 00 04 */	addi r25, r25, 0x4
/* 801017B0 000FE5B0  3B 9C 00 01 */	addi r28, r28, 0x1
.L_801017B4:
/* 801017B4 000FE5B4  80 1B 00 0C */	lwz r0, 0xc(r27)
/* 801017B8 000FE5B8  7C 1C 00 00 */	cmpw r28, r0
/* 801017BC 000FE5BC  41 80 FF A8 */	blt .L_80101764
/* 801017C0 000FE5C0  80 1F 01 1C */	lwz r0, 0x11c(r31)
/* 801017C4 000FE5C4  2C 00 00 00 */	cmpwi r0, 0x0
/* 801017C8 000FE5C8  40 81 00 10 */	ble .L_801017D8
/* 801017CC 000FE5CC  38 7F 01 18 */	addi r3, r31, 0x118
/* 801017D0 000FE5D0  38 80 00 00 */	li r4, 0x0
/* 801017D4 000FE5D4  4B FE 88 B1 */	bl kar_graudio_play_fgm_entry_id
.L_801017D8:
/* 801017D8 000FE5D8  80 1B 00 20 */	lwz r0, 0x20(r27)
/* 801017DC 000FE5DC  7F E3 FB 78 */	mr r3, r31
/* 801017E0 000FE5E0  C0 22 92 50 */	lfs f1, lbl_805DF950@sda21(r0)
/* 801017E4 000FE5E4  38 80 00 01 */	li r4, 0x1
/* 801017E8 000FE5E8  90 1F 01 34 */	stw r0, 0x134(r31)
/* 801017EC 000FE5EC  38 E0 00 00 */	li r7, 0x0
/* 801017F0 000FE5F0  FC 60 08 90 */	fmr f3, f1
/* 801017F4 000FE5F4  C0 42 92 54 */	lfs f2, lbl_805DF954@sda21(r0)
/* 801017F8 000FE5F8  80 BB 00 10 */	lwz r5, 0x10(r27)
/* 801017FC 000FE5FC  80 DB 00 00 */	lwz r6, 0x0(r27)
/* 80101800 000FE600  4B FF 3D 49 */	bl kar_gryaku_set_path_node_motion
.L_80101804:
/* 80101804 000FE604  39 61 00 30 */	addi r11, r1, 0x30
/* 80101808 000FE608  48 2A C3 91 */	bl _restgpr_25
/* 8010180C 000FE60C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80101810 000FE610  7C 08 03 A6 */	mtlr r0
/* 80101814 000FE614  38 21 00 30 */	addi r1, r1, 0x30
/* 80101818 000FE618  4E 80 00 20 */	blr
.endfn kar_gryakupillar_trigger_kind39_contact_drop

# .text:0x830 | 0x8010181C | size: 0x50
.fn kar_gryakupillar_create_secondary_kind40_colosseum_pillar, global
/* 8010181C 000FE61C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80101820 000FE620  7C 08 02 A6 */	mflr r0
/* 80101824 000FE624  90 01 00 14 */	stw r0, 0x14(r1)
/* 80101828 000FE628  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010182C 000FE62C  7C 7F 1B 78 */	mr r31, r3
/* 80101830 000FE630  38 60 00 28 */	li r3, 0x28
/* 80101834 000FE634  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80101838 000FE638  7C BE 2B 78 */	mr r30, r5
/* 8010183C 000FE63C  4B FF 30 91 */	bl kar_gryaku_create_yaku_from_secondary_kind
/* 80101840 000FE640  7F E4 FB 78 */	mr r4, r31
/* 80101844 000FE644  7C 7F 1B 78 */	mr r31, r3
/* 80101848 000FE648  7F C5 F3 78 */	mr r5, r30
/* 8010184C 000FE64C  48 00 00 21 */	bl kar_gryakupillar_init_secondary_kind40_colosseum_pillar
/* 80101850 000FE650  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80101854 000FE654  7F E3 FB 78 */	mr r3, r31
/* 80101858 000FE658  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010185C 000FE65C  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80101860 000FE660  7C 08 03 A6 */	mtlr r0
/* 80101864 000FE664  38 21 00 10 */	addi r1, r1, 0x10
/* 80101868 000FE668  4E 80 00 20 */	blr
.endfn kar_gryakupillar_create_secondary_kind40_colosseum_pillar

# .text:0x880 | 0x8010186C | size: 0x8C
.fn kar_gryakupillar_init_secondary_kind40_colosseum_pillar, global
/* 8010186C 000FE66C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80101870 000FE670  7C 08 02 A6 */	mflr r0
/* 80101874 000FE674  90 01 00 24 */	stw r0, 0x24(r1)
/* 80101878 000FE678  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8010187C 000FE67C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80101880 000FE680  7C BE 2B 78 */	mr r30, r5
/* 80101884 000FE684  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80101888 000FE688  7C 9D 23 78 */	mr r29, r4
/* 8010188C 000FE68C  93 81 00 10 */	stw r28, 0x10(r1)
/* 80101890 000FE690  7C 7C 1B 78 */	mr r28, r3
/* 80101894 000FE694  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80101898 000FE698  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 8010189C 000FE69C  38 7F 00 1C */	addi r3, r31, 0x1c
/* 801018A0 000FE6A0  80 BF 00 64 */	lwz r5, 0x64(r31)
/* 801018A4 000FE6A4  80 84 00 00 */	lwz r4, 0x0(r4)
/* 801018A8 000FE6A8  80 04 00 04 */	lwz r0, 0x4(r4)
/* 801018AC 000FE6AC  54 00 18 38 */	slwi r0, r0, 3
/* 801018B0 000FE6B0  7C 85 00 2E */	lwzx r4, r5, r0
/* 801018B4 000FE6B4  4B FD 60 A1 */	bl kar_grcoll__800d7954
/* 801018B8 000FE6B8  90 7F 01 34 */	stw r3, 0x134(r31)
/* 801018BC 000FE6BC  7F 83 E3 78 */	mr r3, r28
/* 801018C0 000FE6C0  7F A4 EB 78 */	mr r4, r29
/* 801018C4 000FE6C4  7F C5 F3 78 */	mr r5, r30
/* 801018C8 000FE6C8  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 801018CC 000FE6CC  80 DF 01 34 */	lwz r6, 0x134(r31)
/* 801018D0 000FE6D0  90 06 00 90 */	stw r0, 0x90(r6)
/* 801018D4 000FE6D4  48 00 00 25 */	bl kar_gryakupillar_reset_kind40_colosseum_pillar_eventpos
/* 801018D8 000FE6D8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801018DC 000FE6DC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801018E0 000FE6E0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801018E4 000FE6E4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 801018E8 000FE6E8  83 81 00 10 */	lwz r28, 0x10(r1)
/* 801018EC 000FE6EC  7C 08 03 A6 */	mtlr r0
/* 801018F0 000FE6F0  38 21 00 20 */	addi r1, r1, 0x20
/* 801018F4 000FE6F4  4E 80 00 20 */	blr
.endfn kar_gryakupillar_init_secondary_kind40_colosseum_pillar

# .text:0x90C | 0x801018F8 | size: 0x108
.fn kar_gryakupillar_reset_kind40_colosseum_pillar_eventpos, global
/* 801018F8 000FE6F8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801018FC 000FE6FC  7C 08 02 A6 */	mflr r0
/* 80101900 000FE700  90 01 00 24 */	stw r0, 0x24(r1)
/* 80101904 000FE704  39 61 00 20 */	addi r11, r1, 0x20
/* 80101908 000FE708  48 2A C2 4D */	bl _savegpr_27
/* 8010190C 000FE70C  7C 7B 1B 78 */	mr r27, r3
/* 80101910 000FE710  7C 9C 23 78 */	mr r28, r4
/* 80101914 000FE714  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80101918 000FE718  7C BD 2B 78 */	mr r29, r5
/* 8010191C 000FE71C  38 80 00 00 */	li r4, 0x0
/* 80101920 000FE720  80 BF 00 08 */	lwz r5, 0x8(r31)
/* 80101924 000FE724  80 7F 01 34 */	lwz r3, 0x134(r31)
/* 80101928 000FE728  83 C5 00 00 */	lwz r30, 0x0(r5)
/* 8010192C 000FE72C  4B FD 61 A5 */	bl kar_grcoll__near_800d7ad0
/* 80101930 000FE730  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 80101934 000FE734  38 80 00 10 */	li r4, 0x10
/* 80101938 000FE738  80 7F 00 64 */	lwz r3, 0x64(r31)
/* 8010193C 000FE73C  54 00 18 38 */	slwi r0, r0, 3
/* 80101940 000FE740  7C 63 00 2E */	lwzx r3, r3, r0
/* 80101944 000FE744  48 30 A4 BD */	bl HSD_JObjSetFlagsAll
/* 80101948 000FE748  80 7F 00 EC */	lwz r3, 0xec(r31)
/* 8010194C 000FE74C  48 08 B1 B9 */	bl kar_collision_object_begin_disable
/* 80101950 000FE750  80 DE 00 28 */	lwz r6, 0x28(r30)
/* 80101954 000FE754  7F 63 DB 78 */	mr r3, r27
/* 80101958 000FE758  C0 22 92 58 */	lfs f1, lbl_805DF958@sda21(r0)
/* 8010195C 000FE75C  7F A4 EB 78 */	mr r4, r29
/* 80101960 000FE760  80 A6 00 0C */	lwz r5, 0xc(r6)
/* 80101964 000FE764  C0 46 00 10 */	lfs f2, 0x10(r6)
/* 80101968 000FE768  4B FF 6E ED */	bl kar_gryakucommon_sync_jobj_to_eventpos_matrix
/* 8010196C 000FE76C  80 7E 00 48 */	lwz r3, 0x48(r30)
/* 80101970 000FE770  38 00 00 00 */	li r0, 0x0
/* 80101974 000FE774  90 7F 01 40 */	stw r3, 0x140(r31)
/* 80101978 000FE778  93 9F 01 30 */	stw r28, 0x130(r31)
/* 8010197C 000FE77C  80 7E 00 28 */	lwz r3, 0x28(r30)
/* 80101980 000FE780  C0 03 00 00 */	lfs f0, 0x0(r3)
/* 80101984 000FE784  D0 1F 01 38 */	stfs f0, 0x138(r31)
/* 80101988 000FE788  90 1F 01 3C */	stw r0, 0x13c(r31)
/* 8010198C 000FE78C  90 1F 01 4C */	stw r0, 0x14c(r31)
/* 80101990 000FE790  90 1F 01 48 */	stw r0, 0x148(r31)
/* 80101994 000FE794  90 1F 01 54 */	stw r0, 0x154(r31)
/* 80101998 000FE798  90 1F 01 50 */	stw r0, 0x150(r31)
/* 8010199C 000FE79C  90 1F 01 5C */	stw r0, 0x15c(r31)
/* 801019A0 000FE7A0  90 1F 01 58 */	stw r0, 0x158(r31)
/* 801019A4 000FE7A4  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 801019A8 000FE7A8  80 03 00 14 */	lwz r0, 0x14(r3)
/* 801019AC 000FE7AC  28 00 00 00 */	cmplwi r0, 0x0
/* 801019B0 000FE7B0  41 82 00 14 */	beq .L_801019C4
/* 801019B4 000FE7B4  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 801019B8 000FE7B8  7F 63 DB 78 */	mr r3, r27
/* 801019BC 000FE7BC  38 A0 00 01 */	li r5, 0x1
/* 801019C0 000FE7C0  4B FF 5E B1 */	bl kar_gryakuaudio_configure_fgm_track_from_joint
.L_801019C4:
/* 801019C4 000FE7C4  C0 22 92 5C */	lfs f1, lbl_805DF95C@sda21(r0)
/* 801019C8 000FE7C8  7F E3 FB 78 */	mr r3, r31
/* 801019CC 000FE7CC  80 BE 00 0C */	lwz r5, 0xc(r30)
/* 801019D0 000FE7D0  38 80 00 00 */	li r4, 0x0
/* 801019D4 000FE7D4  FC 40 08 90 */	fmr f2, f1
/* 801019D8 000FE7D8  38 C0 FF FF */	li r6, -0x1
/* 801019DC 000FE7DC  FC 60 08 90 */	fmr f3, f1
/* 801019E0 000FE7E0  38 E0 00 00 */	li r7, 0x0
/* 801019E4 000FE7E4  4B FF 3B 65 */	bl kar_gryaku_set_path_node_motion
/* 801019E8 000FE7E8  39 61 00 20 */	addi r11, r1, 0x20
/* 801019EC 000FE7EC  48 2A C1 B5 */	bl _restgpr_27
/* 801019F0 000FE7F0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801019F4 000FE7F4  7C 08 03 A6 */	mtlr r0
/* 801019F8 000FE7F8  38 21 00 20 */	addi r1, r1, 0x20
/* 801019FC 000FE7FC  4E 80 00 20 */	blr
.endfn kar_gryakupillar_reset_kind40_colosseum_pillar_eventpos

# .text:0xA14 | 0x80101A00 | size: 0xF4
.fn kar_gryakupillar_prepare_kind40_eventrock_prefall_anim, global
/* 80101A00 000FE800  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80101A04 000FE804  7C 08 02 A6 */	mflr r0
/* 80101A08 000FE808  90 01 00 34 */	stw r0, 0x34(r1)
/* 80101A0C 000FE80C  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 80101A10 000FE810  F3 E1 00 28 */	psq_st f31, 0x28(r1), 0, qr0
/* 80101A14 000FE814  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80101A18 000FE818  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80101A1C 000FE81C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80101A20 000FE820  7C 7D 1B 78 */	mr r29, r3
/* 80101A24 000FE824  3C 60 80 10 */	lis r3, kar_gryakupillar_get_kind40_anim_start_value@ha
/* 80101A28 000FE828  83 FD 00 2C */	lwz r31, 0x2c(r29)
/* 80101A2C 000FE82C  38 83 1A F4 */	addi r4, r3, kar_gryakupillar_get_kind40_anim_start_value@l
/* 80101A30 000FE830  80 BF 00 08 */	lwz r5, 0x8(r31)
/* 80101A34 000FE834  80 7F 01 34 */	lwz r3, 0x134(r31)
/* 80101A38 000FE838  83 C5 00 00 */	lwz r30, 0x0(r5)
/* 80101A3C 000FE83C  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80101A40 000FE840  4B FF 46 F5 */	bl kar_gryakuanim_get_jobj_aobj_value
/* 80101A44 000FE844  FC 00 08 90 */	fmr f0, f1
/* 80101A48 000FE848  C0 22 92 5C */	lfs f1, lbl_805DF95C@sda21(r0)
/* 80101A4C 000FE84C  80 BE 00 18 */	lwz r5, 0x18(r30)
/* 80101A50 000FE850  7F E3 FB 78 */	mr r3, r31
/* 80101A54 000FE854  FC 60 08 90 */	fmr f3, f1
/* 80101A58 000FE858  C0 42 92 60 */	lfs f2, lbl_805DF960@sda21(r0)
/* 80101A5C 000FE85C  FF E0 00 90 */	fmr f31, f0
/* 80101A60 000FE860  38 80 00 03 */	li r4, 0x3
/* 80101A64 000FE864  38 C0 FF FF */	li r6, -0x1
/* 80101A68 000FE868  38 E0 00 04 */	li r7, 0x4
/* 80101A6C 000FE86C  4B FF 3A DD */	bl kar_gryaku_set_path_node_motion
/* 80101A70 000FE870  80 7E 00 28 */	lwz r3, 0x28(r30)
/* 80101A74 000FE874  3C 00 43 30 */	lis r0, 0x4330
/* 80101A78 000FE878  90 01 00 08 */	stw r0, 0x8(r1)
/* 80101A7C 000FE87C  FC 40 F8 90 */	fmr f2, f31
/* 80101A80 000FE880  80 03 00 08 */	lwz r0, 0x8(r3)
/* 80101A84 000FE884  7F A3 EB 78 */	mr r3, r29
/* 80101A88 000FE888  C8 22 92 68 */	lfd f1, lbl_805DF968@sda21(r0)
/* 80101A8C 000FE88C  38 C0 00 01 */	li r6, 0x1
/* 80101A90 000FE890  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 80101A94 000FE894  90 01 00 0C */	stw r0, 0xc(r1)
/* 80101A98 000FE898  38 E0 00 00 */	li r7, 0x0
/* 80101A9C 000FE89C  80 9E 00 10 */	lwz r4, 0x10(r30)
/* 80101AA0 000FE8A0  C8 01 00 08 */	lfd f0, 0x8(r1)
/* 80101AA4 000FE8A4  80 BE 00 04 */	lwz r5, 0x4(r30)
/* 80101AA8 000FE8A8  EC 20 08 28 */	fsubs f1, f0, f1
/* 80101AAC 000FE8AC  4B FF 3C F1 */	bl kar_gryaku_play_anim_entry
/* 80101AB0 000FE8B0  80 9E 00 04 */	lwz r4, 0x4(r30)
/* 80101AB4 000FE8B4  7F A3 EB 78 */	mr r3, r29
/* 80101AB8 000FE8B8  4B FF 41 B1 */	bl kar_gryakuanim_step_jobj_slot_anim
/* 80101ABC 000FE8BC  7F A3 EB 78 */	mr r3, r29
/* 80101AC0 000FE8C0  48 00 09 29 */	bl kar_gryakubreakrock_start_dobj_anim_for_threshold_index
/* 80101AC4 000FE8C4  3C 60 80 10 */	lis r3, kar_gryakubreakrock_update_eventrock_shatter_sequence@ha
/* 80101AC8 000FE8C8  38 03 20 3C */	addi r0, r3, kar_gryakubreakrock_update_eventrock_shatter_sequence@l
/* 80101ACC 000FE8CC  90 1F 01 00 */	stw r0, 0x100(r31)
/* 80101AD0 000FE8D0  E3 E1 00 28 */	psq_l f31, 0x28(r1), 0, qr0
/* 80101AD4 000FE8D4  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80101AD8 000FE8D8  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 80101ADC 000FE8DC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80101AE0 000FE8E0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80101AE4 000FE8E4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80101AE8 000FE8E8  7C 08 03 A6 */	mtlr r0
/* 80101AEC 000FE8EC  38 21 00 30 */	addi r1, r1, 0x30
/* 80101AF0 000FE8F0  4E 80 00 20 */	blr
.endfn kar_gryakupillar_prepare_kind40_eventrock_prefall_anim

# .text:0xB08 | 0x80101AF4 | size: 0x40
.fn kar_gryakupillar_get_kind40_anim_start_value, global
/* 80101AF4 000FE8F4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80101AF8 000FE8F8  7C 08 02 A6 */	mflr r0
/* 80101AFC 000FE8FC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80101B00 000FE900  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80101B04 000FE904  7C 7F 1B 79 */	mr. r31, r3
/* 80101B08 000FE908  40 82 00 14 */	bne .L_80101B1C
/* 80101B0C 000FE90C  38 6D 91 D8 */	li r3, kar_srcfile_aobj_h_805d62b8@sda21
/* 80101B10 000FE910  38 80 00 95 */	li r4, 0x95
/* 80101B14 000FE914  38 AD 91 E0 */	li r5, lbl_805D62C0@sda21
/* 80101B18 000FE918  48 32 69 A1 */	bl __assert
.L_80101B1C:
/* 80101B1C 000FE91C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80101B20 000FE920  C0 3F 00 04 */	lfs f1, 0x4(r31)
/* 80101B24 000FE924  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80101B28 000FE928  7C 08 03 A6 */	mtlr r0
/* 80101B2C 000FE92C  38 21 00 10 */	addi r1, r1, 0x10
/* 80101B30 000FE930  4E 80 00 20 */	blr
.endfn kar_gryakupillar_get_kind40_anim_start_value

# .text:0xB48 | 0x80101B34 | size: 0x98
.fn kar_gryakupillar_start_kind40_eventrock_fall_motion, global
/* 80101B34 000FE934  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80101B38 000FE938  7C 08 02 A6 */	mflr r0
/* 80101B3C 000FE93C  90 01 00 24 */	stw r0, 0x24(r1)
/* 80101B40 000FE940  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80101B44 000FE944  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80101B48 000FE948  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80101B4C 000FE94C  7C 7D 1B 78 */	mr r29, r3
/* 80101B50 000FE950  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80101B54 000FE954  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 80101B58 000FE958  80 7F 00 EC */	lwz r3, 0xec(r31)
/* 80101B5C 000FE95C  83 C4 00 00 */	lwz r30, 0x0(r4)
/* 80101B60 000FE960  48 08 AF A5 */	bl kar_collision_object_begin_disable
/* 80101B64 000FE964  80 1F 01 1C */	lwz r0, 0x11c(r31)
/* 80101B68 000FE968  2C 00 00 03 */	cmpwi r0, 0x3
/* 80101B6C 000FE96C  40 81 00 10 */	ble .L_80101B7C
/* 80101B70 000FE970  38 7F 01 18 */	addi r3, r31, 0x118
/* 80101B74 000FE974  38 80 00 03 */	li r4, 0x3
/* 80101B78 000FE978  4B FE 85 0D */	bl kar_graudio_play_fgm_entry_id
.L_80101B7C:
/* 80101B7C 000FE97C  80 1E 00 44 */	lwz r0, 0x44(r30)
/* 80101B80 000FE980  7F E3 FB 78 */	mr r3, r31
/* 80101B84 000FE984  C0 22 92 5C */	lfs f1, lbl_805DF95C@sda21(r0)
/* 80101B88 000FE988  38 80 00 05 */	li r4, 0x5
/* 80101B8C 000FE98C  90 1F 01 40 */	stw r0, 0x140(r31)
/* 80101B90 000FE990  38 C0 FF FF */	li r6, -0x1
/* 80101B94 000FE994  FC 60 08 90 */	fmr f3, f1
/* 80101B98 000FE998  C0 42 92 60 */	lfs f2, lbl_805DF960@sda21(r0)
/* 80101B9C 000FE99C  80 BE 00 1C */	lwz r5, 0x1c(r30)
/* 80101BA0 000FE9A0  38 E0 00 00 */	li r7, 0x0
/* 80101BA4 000FE9A4  4B FF 39 A5 */	bl kar_gryaku_set_path_node_motion
/* 80101BA8 000FE9A8  7F A3 EB 78 */	mr r3, r29
/* 80101BAC 000FE9AC  48 00 08 3D */	bl kar_gryakubreakrock_start_dobj_anim_for_threshold_index
/* 80101BB0 000FE9B0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80101BB4 000FE9B4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80101BB8 000FE9B8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80101BBC 000FE9BC  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80101BC0 000FE9C0  7C 08 03 A6 */	mtlr r0
/* 80101BC4 000FE9C4  38 21 00 20 */	addi r1, r1, 0x20
/* 80101BC8 000FE9C8  4E 80 00 20 */	blr
.endfn kar_gryakupillar_start_kind40_eventrock_fall_motion

# .text:0xBE0 | 0x80101BCC | size: 0xD8
.fn kar_gryakupillar_update_kind40_delay_to_collision_enable, global
/* 80101BCC 000FE9CC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80101BD0 000FE9D0  7C 08 02 A6 */	mflr r0
/* 80101BD4 000FE9D4  90 01 00 24 */	stw r0, 0x24(r1)
/* 80101BD8 000FE9D8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80101BDC 000FE9DC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80101BE0 000FE9E0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80101BE4 000FE9E4  7C 7D 1B 78 */	mr r29, r3
/* 80101BE8 000FE9E8  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 80101BEC 000FE9EC  80 64 01 40 */	lwz r3, 0x140(r4)
/* 80101BF0 000FE9F0  2C 03 00 00 */	cmpwi r3, 0x0
/* 80101BF4 000FE9F4  40 81 00 94 */	ble .L_80101C88
/* 80101BF8 000FE9F8  38 03 FF FF */	subi r0, r3, 0x1
/* 80101BFC 000FE9FC  90 04 01 40 */	stw r0, 0x140(r4)
/* 80101C00 000FEA00  80 04 01 40 */	lwz r0, 0x140(r4)
/* 80101C04 000FEA04  2C 00 00 00 */	cmpwi r0, 0x0
/* 80101C08 000FEA08  41 81 00 80 */	bgt .L_80101C88
/* 80101C0C 000FEA0C  83 DD 00 2C */	lwz r30, 0x2c(r29)
/* 80101C10 000FEA10  38 80 00 01 */	li r4, 0x1
/* 80101C14 000FEA14  80 BE 00 08 */	lwz r5, 0x8(r30)
/* 80101C18 000FEA18  80 7E 01 34 */	lwz r3, 0x134(r30)
/* 80101C1C 000FEA1C  83 E5 00 00 */	lwz r31, 0x0(r5)
/* 80101C20 000FEA20  4B FD 5E B1 */	bl kar_grcoll__near_800d7ad0
/* 80101C24 000FEA24  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 80101C28 000FEA28  38 80 00 10 */	li r4, 0x10
/* 80101C2C 000FEA2C  80 7E 00 64 */	lwz r3, 0x64(r30)
/* 80101C30 000FEA30  54 00 18 38 */	slwi r0, r0, 3
/* 80101C34 000FEA34  7C 63 00 2E */	lwzx r3, r3, r0
/* 80101C38 000FEA38  48 30 A5 3D */	bl HSD_JObjClearFlagsAll
/* 80101C3C 000FEA3C  38 00 00 00 */	li r0, 0x0
/* 80101C40 000FEA40  90 1E 01 40 */	stw r0, 0x140(r30)
/* 80101C44 000FEA44  80 1E 01 1C */	lwz r0, 0x11c(r30)
/* 80101C48 000FEA48  2C 00 00 00 */	cmpwi r0, 0x0
/* 80101C4C 000FEA4C  40 81 00 10 */	ble .L_80101C5C
/* 80101C50 000FEA50  38 7E 01 18 */	addi r3, r30, 0x118
/* 80101C54 000FEA54  38 80 00 00 */	li r4, 0x0
/* 80101C58 000FEA58  4B FE 84 2D */	bl kar_graudio_play_fgm_entry_id
.L_80101C5C:
/* 80101C5C 000FEA5C  C0 22 92 5C */	lfs f1, lbl_805DF95C@sda21(r0)
/* 80101C60 000FEA60  7F C3 F3 78 */	mr r3, r30
/* 80101C64 000FEA64  80 BF 00 0C */	lwz r5, 0xc(r31)
/* 80101C68 000FEA68  38 80 00 01 */	li r4, 0x1
/* 80101C6C 000FEA6C  FC 60 08 90 */	fmr f3, f1
/* 80101C70 000FEA70  C0 42 92 60 */	lfs f2, lbl_805DF960@sda21(r0)
/* 80101C74 000FEA74  38 C0 FF FF */	li r6, -0x1
/* 80101C78 000FEA78  38 E0 00 00 */	li r7, 0x0
/* 80101C7C 000FEA7C  4B FF 38 CD */	bl kar_gryaku_set_path_node_motion
/* 80101C80 000FEA80  7F A3 EB 78 */	mr r3, r29
/* 80101C84 000FEA84  48 00 07 65 */	bl kar_gryakubreakrock_start_dobj_anim_for_threshold_index
.L_80101C88:
/* 80101C88 000FEA88  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80101C8C 000FEA8C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80101C90 000FEA90  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80101C94 000FEA94  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80101C98 000FEA98  7C 08 03 A6 */	mtlr r0
/* 80101C9C 000FEA9C  38 21 00 20 */	addi r1, r1, 0x20
/* 80101CA0 000FEAA0  4E 80 00 20 */	blr
.endfn kar_gryakupillar_update_kind40_delay_to_collision_enable

# .text:0xCB8 | 0x80101CA4 | size: 0xD8
.fn kar_gryakupillar_update_kind40_ground_clear_to_mode2_anim, global
/* 80101CA4 000FEAA4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80101CA8 000FEAA8  7C 08 02 A6 */	mflr r0
/* 80101CAC 000FEAAC  90 01 00 24 */	stw r0, 0x24(r1)
/* 80101CB0 000FEAB0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80101CB4 000FEAB4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80101CB8 000FEAB8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80101CBC 000FEABC  7C 7D 1B 78 */	mr r29, r3
/* 80101CC0 000FEAC0  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 80101CC4 000FEAC4  80 64 00 08 */	lwz r3, 0x8(r4)
/* 80101CC8 000FEAC8  80 84 00 64 */	lwz r4, 0x64(r4)
/* 80101CCC 000FEACC  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80101CD0 000FEAD0  80 03 00 00 */	lwz r0, 0x0(r3)
/* 80101CD4 000FEAD4  54 00 18 38 */	slwi r0, r0, 3
/* 80101CD8 000FEAD8  7C 64 00 2E */	lwzx r3, r4, r0
/* 80101CDC 000FEADC  4B F5 2B 05 */	bl kar_gmlanmenu__near_800547e0
/* 80101CE0 000FEAE0  2C 03 00 00 */	cmpwi r3, 0x0
/* 80101CE4 000FEAE4  40 82 00 7C */	bne .L_80101D60
/* 80101CE8 000FEAE8  83 DD 00 2C */	lwz r30, 0x2c(r29)
/* 80101CEC 000FEAEC  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 80101CF0 000FEAF0  80 7E 00 EC */	lwz r3, 0xec(r30)
/* 80101CF4 000FEAF4  83 E4 00 00 */	lwz r31, 0x0(r4)
/* 80101CF8 000FEAF8  48 08 AE 31 */	bl kar_collision_object_end_disable
/* 80101CFC 000FEAFC  C0 22 92 5C */	lfs f1, lbl_805DF95C@sda21(r0)
/* 80101D00 000FEB00  7F C3 F3 78 */	mr r3, r30
/* 80101D04 000FEB04  80 BF 00 18 */	lwz r5, 0x18(r31)
/* 80101D08 000FEB08  38 80 00 02 */	li r4, 0x2
/* 80101D0C 000FEB0C  FC 60 08 90 */	fmr f3, f1
/* 80101D10 000FEB10  C0 42 92 60 */	lfs f2, lbl_805DF960@sda21(r0)
/* 80101D14 000FEB14  38 C0 FF FF */	li r6, -0x1
/* 80101D18 000FEB18  38 E0 00 00 */	li r7, 0x0
/* 80101D1C 000FEB1C  4B FF 38 2D */	bl kar_gryaku_set_path_node_motion
/* 80101D20 000FEB20  80 9F 00 10 */	lwz r4, 0x10(r31)
/* 80101D24 000FEB24  7F A3 EB 78 */	mr r3, r29
/* 80101D28 000FEB28  80 BF 00 04 */	lwz r5, 0x4(r31)
/* 80101D2C 000FEB2C  38 C0 00 01 */	li r6, 0x1
/* 80101D30 000FEB30  C0 22 92 60 */	lfs f1, lbl_805DF960@sda21(r0)
/* 80101D34 000FEB34  38 E0 00 00 */	li r7, 0x0
/* 80101D38 000FEB38  C0 42 92 5C */	lfs f2, lbl_805DF95C@sda21(r0)
/* 80101D3C 000FEB3C  4B FF 3A 61 */	bl kar_gryaku_play_anim_entry
/* 80101D40 000FEB40  80 9F 00 04 */	lwz r4, 0x4(r31)
/* 80101D44 000FEB44  7F A3 EB 78 */	mr r3, r29
/* 80101D48 000FEB48  4B FF 3F 21 */	bl kar_gryakuanim_step_jobj_slot_anim
/* 80101D4C 000FEB4C  7F A3 EB 78 */	mr r3, r29
/* 80101D50 000FEB50  48 00 06 99 */	bl kar_gryakubreakrock_start_dobj_anim_for_threshold_index
/* 80101D54 000FEB54  3C 60 80 10 */	lis r3, kar_gryakubreakrock_update_eventrock_shatter_sequence@ha
/* 80101D58 000FEB58  38 03 20 3C */	addi r0, r3, kar_gryakubreakrock_update_eventrock_shatter_sequence@l
/* 80101D5C 000FEB5C  90 1E 01 00 */	stw r0, 0x100(r30)
.L_80101D60:
/* 80101D60 000FEB60  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80101D64 000FEB64  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80101D68 000FEB68  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80101D6C 000FEB6C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80101D70 000FEB70  7C 08 03 A6 */	mtlr r0
/* 80101D74 000FEB74  38 21 00 20 */	addi r1, r1, 0x20
/* 80101D78 000FEB78  4E 80 00 20 */	blr
.endfn kar_gryakupillar_update_kind40_ground_clear_to_mode2_anim

# .text:0xD90 | 0x80101D7C | size: 0x48
.fn kar_gryakupillar_update_kind40_icon_delay_a, global
/* 80101D7C 000FEB7C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80101D80 000FEB80  7C 08 02 A6 */	mflr r0
/* 80101D84 000FEB84  90 01 00 14 */	stw r0, 0x14(r1)
/* 80101D88 000FEB88  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 80101D8C 000FEB8C  80 64 01 40 */	lwz r3, 0x140(r4)
/* 80101D90 000FEB90  2C 03 00 00 */	cmpwi r3, 0x0
/* 80101D94 000FEB94  40 81 00 20 */	ble .L_80101DB4
/* 80101D98 000FEB98  38 03 FF FF */	subi r0, r3, 0x1
/* 80101D9C 000FEB9C  90 04 01 40 */	stw r0, 0x140(r4)
/* 80101DA0 000FEBA0  80 04 01 40 */	lwz r0, 0x140(r4)
/* 80101DA4 000FEBA4  2C 00 00 00 */	cmpwi r0, 0x0
/* 80101DA8 000FEBA8  41 81 00 0C */	bgt .L_80101DB4
/* 80101DAC 000FEBAC  80 64 00 EC */	lwz r3, 0xec(r4)
/* 80101DB0 000FEBB0  48 08 AD 79 */	bl kar_collision_object_end_disable
.L_80101DB4:
/* 80101DB4 000FEBB4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80101DB8 000FEBB8  7C 08 03 A6 */	mtlr r0
/* 80101DBC 000FEBBC  38 21 00 10 */	addi r1, r1, 0x10
/* 80101DC0 000FEBC0  4E 80 00 20 */	blr
.endfn kar_gryakupillar_update_kind40_icon_delay_a

# .text:0xDD8 | 0x80101DC4 | size: 0x48
.fn kar_gryakupillar_update_kind40_icon_delay_b, global
/* 80101DC4 000FEBC4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80101DC8 000FEBC8  7C 08 02 A6 */	mflr r0
/* 80101DCC 000FEBCC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80101DD0 000FEBD0  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 80101DD4 000FEBD4  80 64 01 40 */	lwz r3, 0x140(r4)
/* 80101DD8 000FEBD8  2C 03 00 00 */	cmpwi r3, 0x0
/* 80101DDC 000FEBDC  40 81 00 20 */	ble .L_80101DFC
/* 80101DE0 000FEBE0  38 03 FF FF */	subi r0, r3, 0x1
/* 80101DE4 000FEBE4  90 04 01 40 */	stw r0, 0x140(r4)
/* 80101DE8 000FEBE8  80 04 01 40 */	lwz r0, 0x140(r4)
/* 80101DEC 000FEBEC  2C 00 00 00 */	cmpwi r0, 0x0
/* 80101DF0 000FEBF0  41 81 00 0C */	bgt .L_80101DFC
/* 80101DF4 000FEBF4  80 64 00 EC */	lwz r3, 0xec(r4)
/* 80101DF8 000FEBF8  48 08 AD 31 */	bl kar_collision_object_end_disable
.L_80101DFC:
/* 80101DFC 000FEBFC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80101E00 000FEC00  7C 08 03 A6 */	mtlr r0
/* 80101E04 000FEC04  38 21 00 10 */	addi r1, r1, 0x10
/* 80101E08 000FEC08  4E 80 00 20 */	blr
.endfn kar_gryakupillar_update_kind40_icon_delay_b

# .text:0xE20 | 0x80101E0C | size: 0x14C
.fn kar_gryakupillar_update_kind40_wait_effects_then_reset, global
/* 80101E0C 000FEC0C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80101E10 000FEC10  7C 08 02 A6 */	mflr r0
/* 80101E14 000FEC14  90 01 00 24 */	stw r0, 0x24(r1)
/* 80101E18 000FEC18  39 61 00 20 */	addi r11, r1, 0x20
/* 80101E1C 000FEC1C  48 2A BD 35 */	bl _savegpr_26
/* 80101E20 000FEC20  7C 7E 1B 78 */	mr r30, r3
/* 80101E24 000FEC24  3B 40 00 00 */	li r26, 0x0
/* 80101E28 000FEC28  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80101E2C 000FEC2C  3B A0 00 00 */	li r29, 0x0
/* 80101E30 000FEC30  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80101E34 000FEC34  7F FC FB 78 */	mr r28, r31
/* 80101E38 000FEC38  83 63 00 00 */	lwz r27, 0x0(r3)
/* 80101E3C 000FEC3C  48 00 00 38 */	b .L_80101E74
.L_80101E40:
/* 80101E40 000FEC40  80 7C 01 48 */	lwz r3, 0x148(r28)
/* 80101E44 000FEC44  80 9C 01 4C */	lwz r4, 0x14c(r28)
/* 80101E48 000FEC48  7C 60 EA 78 */	xor r0, r3, r29
/* 80101E4C 000FEC4C  7C 85 EA 78 */	xor r5, r4, r29
/* 80101E50 000FEC50  7C A0 03 79 */	or. r0, r5, r0
/* 80101E54 000FEC54  41 82 00 18 */	beq .L_80101E6C
/* 80101E58 000FEC58  4B FF 54 35 */	bl kar_gryakueffect_is_effect_key_active
/* 80101E5C 000FEC5C  2C 03 00 00 */	cmpwi r3, 0x0
/* 80101E60 000FEC60  40 82 00 0C */	bne .L_80101E6C
/* 80101E64 000FEC64  93 BC 01 4C */	stw r29, 0x14c(r28)
/* 80101E68 000FEC68  93 BC 01 48 */	stw r29, 0x148(r28)
.L_80101E6C:
/* 80101E6C 000FEC6C  3B 9C 00 08 */	addi r28, r28, 0x8
/* 80101E70 000FEC70  3B 5A 00 01 */	addi r26, r26, 0x1
.L_80101E74:
/* 80101E74 000FEC74  80 FB 00 40 */	lwz r7, 0x40(r27)
/* 80101E78 000FEC78  7C 1A 38 00 */	cmpw r26, r7
/* 80101E7C 000FEC7C  41 80 FF C4 */	blt .L_80101E40
/* 80101E80 000FEC80  39 00 00 00 */	li r8, 0x0
/* 80101E84 000FEC84  7F E6 FB 78 */	mr r6, r31
/* 80101E88 000FEC88  7D 05 43 78 */	mr r5, r8
/* 80101E8C 000FEC8C  7D 04 43 78 */	mr r4, r8
/* 80101E90 000FEC90  7C E9 03 A6 */	mtctr r7
/* 80101E94 000FEC94  2C 07 00 00 */	cmpwi r7, 0x0
/* 80101E98 000FEC98  40 81 00 28 */	ble .L_80101EC0
.L_80101E9C:
/* 80101E9C 000FEC9C  80 06 01 48 */	lwz r0, 0x148(r6)
/* 80101EA0 000FECA0  80 66 01 4C */	lwz r3, 0x14c(r6)
/* 80101EA4 000FECA4  7C 00 22 78 */	xor r0, r0, r4
/* 80101EA8 000FECA8  7C 63 2A 78 */	xor r3, r3, r5
/* 80101EAC 000FECAC  7C 60 03 79 */	or. r0, r3, r0
/* 80101EB0 000FECB0  40 82 00 10 */	bne .L_80101EC0
/* 80101EB4 000FECB4  38 C6 00 08 */	addi r6, r6, 0x8
/* 80101EB8 000FECB8  39 08 00 01 */	addi r8, r8, 0x1
/* 80101EBC 000FECBC  42 00 FF E0 */	bdnz .L_80101E9C
.L_80101EC0:
/* 80101EC0 000FECC0  7C 08 38 00 */	cmpw r8, r7
/* 80101EC4 000FECC4  40 82 00 7C */	bne .L_80101F40
/* 80101EC8 000FECC8  80 7F 01 18 */	lwz r3, 0x118(r31)
/* 80101ECC 000FECCC  28 03 00 00 */	cmplwi r3, 0x0
/* 80101ED0 000FECD0  41 82 00 20 */	beq .L_80101EF0
/* 80101ED4 000FECD4  88 03 00 14 */	lbz r0, 0x14(r3)
/* 80101ED8 000FECD8  54 00 C0 02 */	extlwi r0, r0, 2, 24
/* 80101EDC 000FECDC  7C 00 FE 70 */	srawi r0, r0, 31
/* 80101EE0 000FECE0  7C 00 07 75 */	extsb. r0, r0
/* 80101EE4 000FECE4  41 82 00 0C */	beq .L_80101EF0
/* 80101EE8 000FECE8  38 7F 01 18 */	addi r3, r31, 0x118
/* 80101EEC 000FECEC  4B FE 82 95 */	bl kar_graudio_stop_active_fgm_slot
.L_80101EF0:
/* 80101EF0 000FECF0  83 FE 00 2C */	lwz r31, 0x2c(r30)
/* 80101EF4 000FECF4  38 80 00 00 */	li r4, 0x0
/* 80101EF8 000FECF8  80 BF 00 08 */	lwz r5, 0x8(r31)
/* 80101EFC 000FECFC  80 7F 01 34 */	lwz r3, 0x134(r31)
/* 80101F00 000FED00  83 A5 00 00 */	lwz r29, 0x0(r5)
/* 80101F04 000FED04  4B FD 5B CD */	bl kar_grcoll__near_800d7ad0
/* 80101F08 000FED08  C0 22 92 5C */	lfs f1, lbl_805DF95C@sda21(r0)
/* 80101F0C 000FED0C  7F E3 FB 78 */	mr r3, r31
/* 80101F10 000FED10  80 BD 00 0C */	lwz r5, 0xc(r29)
/* 80101F14 000FED14  38 80 00 06 */	li r4, 0x6
/* 80101F18 000FED18  FC 40 08 90 */	fmr f2, f1
/* 80101F1C 000FED1C  38 C0 FF FF */	li r6, -0x1
/* 80101F20 000FED20  FC 60 08 90 */	fmr f3, f1
/* 80101F24 000FED24  38 E0 00 00 */	li r7, 0x0
/* 80101F28 000FED28  4B FF 36 21 */	bl kar_gryaku_set_path_node_motion
/* 80101F2C 000FED2C  38 00 00 00 */	li r0, 0x0
/* 80101F30 000FED30  7F C3 F3 78 */	mr r3, r30
/* 80101F34 000FED34  90 1F 01 30 */	stw r0, 0x130(r31)
/* 80101F38 000FED38  90 1F 01 40 */	stw r0, 0x140(r31)
/* 80101F3C 000FED3C  48 00 04 AD */	bl kar_gryakubreakrock_start_dobj_anim_for_threshold_index
.L_80101F40:
/* 80101F40 000FED40  39 61 00 20 */	addi r11, r1, 0x20
/* 80101F44 000FED44  48 2A BC 59 */	bl _restgpr_26
/* 80101F48 000FED48  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80101F4C 000FED4C  7C 08 03 A6 */	mtlr r0
/* 80101F50 000FED50  38 21 00 20 */	addi r1, r1, 0x20
/* 80101F54 000FED54  4E 80 00 20 */	blr
.endfn kar_gryakupillar_update_kind40_wait_effects_then_reset

# .text:0xF6C | 0x80101F58 | size: 0xDC
.fn kar_gryakupillar_update_kind40_ground_clear_to_reset, global
/* 80101F58 000FED58  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80101F5C 000FED5C  7C 08 02 A6 */	mflr r0
/* 80101F60 000FED60  90 01 00 24 */	stw r0, 0x24(r1)
/* 80101F64 000FED64  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80101F68 000FED68  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80101F6C 000FED6C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80101F70 000FED70  7C 7D 1B 78 */	mr r29, r3
/* 80101F74 000FED74  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 80101F78 000FED78  80 7E 01 40 */	lwz r3, 0x140(r30)
/* 80101F7C 000FED7C  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 80101F80 000FED80  2C 03 00 00 */	cmpwi r3, 0x0
/* 80101F84 000FED84  83 E4 00 00 */	lwz r31, 0x0(r4)
/* 80101F88 000FED88  40 81 00 24 */	ble .L_80101FAC
/* 80101F8C 000FED8C  38 03 FF FF */	subi r0, r3, 0x1
/* 80101F90 000FED90  90 1E 01 40 */	stw r0, 0x140(r30)
/* 80101F94 000FED94  80 1E 01 40 */	lwz r0, 0x140(r30)
/* 80101F98 000FED98  2C 00 00 00 */	cmpwi r0, 0x0
/* 80101F9C 000FED9C  41 81 00 10 */	bgt .L_80101FAC
/* 80101FA0 000FEDA0  80 7E 01 34 */	lwz r3, 0x134(r30)
/* 80101FA4 000FEDA4  38 80 00 00 */	li r4, 0x0
/* 80101FA8 000FEDA8  4B FD 5B 29 */	bl kar_grcoll__near_800d7ad0
.L_80101FAC:
/* 80101FAC 000FEDAC  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 80101FB0 000FEDB0  80 7E 00 64 */	lwz r3, 0x64(r30)
/* 80101FB4 000FEDB4  54 00 18 38 */	slwi r0, r0, 3
/* 80101FB8 000FEDB8  7C 63 00 2E */	lwzx r3, r3, r0
/* 80101FBC 000FEDBC  4B F5 28 25 */	bl kar_gmlanmenu__near_800547e0
/* 80101FC0 000FEDC0  2C 03 00 00 */	cmpwi r3, 0x0
/* 80101FC4 000FEDC4  40 82 00 54 */	bne .L_80102018
/* 80101FC8 000FEDC8  83 DD 00 2C */	lwz r30, 0x2c(r29)
/* 80101FCC 000FEDCC  38 80 00 00 */	li r4, 0x0
/* 80101FD0 000FEDD0  80 BE 00 08 */	lwz r5, 0x8(r30)
/* 80101FD4 000FEDD4  80 7E 01 34 */	lwz r3, 0x134(r30)
/* 80101FD8 000FEDD8  83 E5 00 00 */	lwz r31, 0x0(r5)
/* 80101FDC 000FEDDC  4B FD 5A F5 */	bl kar_grcoll__near_800d7ad0
/* 80101FE0 000FEDE0  C0 22 92 5C */	lfs f1, lbl_805DF95C@sda21(r0)
/* 80101FE4 000FEDE4  7F C3 F3 78 */	mr r3, r30
/* 80101FE8 000FEDE8  80 BF 00 0C */	lwz r5, 0xc(r31)
/* 80101FEC 000FEDEC  38 80 00 06 */	li r4, 0x6
/* 80101FF0 000FEDF0  FC 40 08 90 */	fmr f2, f1
/* 80101FF4 000FEDF4  38 C0 FF FF */	li r6, -0x1
/* 80101FF8 000FEDF8  FC 60 08 90 */	fmr f3, f1
/* 80101FFC 000FEDFC  38 E0 00 00 */	li r7, 0x0
/* 80102000 000FEE00  4B FF 35 49 */	bl kar_gryaku_set_path_node_motion
/* 80102004 000FEE04  38 00 00 00 */	li r0, 0x0
/* 80102008 000FEE08  7F A3 EB 78 */	mr r3, r29
/* 8010200C 000FEE0C  90 1E 01 30 */	stw r0, 0x130(r30)
/* 80102010 000FEE10  90 1E 01 40 */	stw r0, 0x140(r30)
/* 80102014 000FEE14  48 00 03 D5 */	bl kar_gryakubreakrock_start_dobj_anim_for_threshold_index
.L_80102018:
/* 80102018 000FEE18  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8010201C 000FEE1C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80102020 000FEE20  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80102024 000FEE24  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80102028 000FEE28  7C 08 03 A6 */	mtlr r0
/* 8010202C 000FEE2C  38 21 00 20 */	addi r1, r1, 0x20
/* 80102030 000FEE30  4E 80 00 20 */	blr
.endfn kar_gryakupillar_update_kind40_ground_clear_to_reset

# .text:0x1048 | 0x80102034 | size: 0x8
.fn fn_80102034, global
/* 80102034 000FEE34  38 60 00 00 */	li r3, 0x0
/* 80102038 000FEE38  4E 80 00 20 */	blr
.endfn fn_80102034
