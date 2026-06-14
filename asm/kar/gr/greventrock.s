.include "macros.inc"
.file "greventrock.c"

# 0x8011120C..0x80111F00 | size: 0xCF4
.text
.balign 4

# .text:0x0 | 0x8011120C | size: 0x368
.fn kar_greventrock_choose_eventpos_vectors_far_from_players, global
/* 8011120C 0010E00C  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 80111210 0010E010  7C 08 02 A6 */	mflr r0
/* 80111214 0010E014  90 01 00 44 */	stw r0, 0x44(r1)
/* 80111218 0010E018  39 61 00 40 */	addi r11, r1, 0x40
/* 8011121C 0010E01C  48 29 C9 1D */	bl _savegpr_20
/* 80111220 0010E020  3C E0 80 4A */	lis r7, kar_src_greventrock_c@ha
/* 80111224 0010E024  7C 74 1B 78 */	mr r20, r3
/* 80111228 0010E028  7C 96 23 78 */	mr r22, r4
/* 8011122C 0010E02C  7C B7 2B 78 */	mr r23, r5
/* 80111230 0010E030  7C D8 33 78 */	mr r24, r6
/* 80111234 0010E034  3B 87 79 A0 */	addi r28, r7, kar_src_greventrock_c@l
/* 80111238 0010E038  4B FD D5 05 */	bl kar_greventgenerator_get_current_event_param
/* 8011123C 0010E03C  7C 7D 1B 78 */	mr r29, r3
/* 80111240 0010E040  7E 83 A3 78 */	mr r3, r20
/* 80111244 0010E044  4B FD D4 A9 */	bl kar_greventgenerator_get_current_eventpos_start
/* 80111248 0010E048  7C 7E 1B 78 */	mr r30, r3
/* 8011124C 0010E04C  7E 83 A3 78 */	mr r3, r20
/* 80111250 0010E050  4B FD D4 B9 */	bl kar_greventgenerator_get_current_eventpos_count
/* 80111254 0010E054  7C 7F 1B 78 */	mr r31, r3
/* 80111258 0010E058  3C 60 80 55 */	lis r3, kar_greventrock_eventpos_candidate_linked_list@ha
/* 8011125C 0010E05C  2C 1F 00 0A */	cmpwi r31, 0xa
/* 80111260 0010E060  3B 63 78 68 */	addi r27, r3, kar_greventrock_eventpos_candidate_linked_list@l
/* 80111264 0010E064  7F 79 DB 78 */	mr r25, r27
/* 80111268 0010E068  41 82 00 14 */	beq .L_8011127C
/* 8011126C 0010E06C  38 7C 00 00 */	addi r3, r28, 0x0
/* 80111270 0010E070  38 BC 00 10 */	addi r5, r28, 0x10
/* 80111274 0010E074  38 80 00 8A */	li r4, 0x8a
/* 80111278 0010E078  48 31 72 41 */	bl __assert
.L_8011127C:
/* 8011127C 0010E07C  3C 60 80 55 */	lis r3, kar_greventrock_eventpos_candidate_linked_list@ha
/* 80111280 0010E080  2C 1F 00 00 */	cmpwi r31, 0x0
/* 80111284 0010E084  39 23 78 68 */	addi r9, r3, kar_greventrock_eventpos_candidate_linked_list@l
/* 80111288 0010E088  38 FF FF FF */	subi r7, r31, 0x1
/* 8011128C 0010E08C  7D 2A 4B 78 */	mr r10, r9
/* 80111290 0010E090  7F E3 FB 78 */	mr r3, r31
/* 80111294 0010E094  54 E6 0F FE */	srwi r6, r7, 31
/* 80111298 0010E098  39 60 00 00 */	li r11, 0x0
/* 8011129C 0010E09C  40 81 01 08 */	ble .L_801113A4
/* 801112A0 0010E0A0  57 E0 F0 BF */	srwi. r0, r31, 2
/* 801112A4 0010E0A4  7C 09 03 A6 */	mtctr r0
/* 801112A8 0010E0A8  41 82 00 C4 */	beq .L_8011136C
.L_801112AC:
/* 801112AC 0010E0AC  38 8B 00 01 */	addi r4, r11, 0x1
/* 801112B0 0010E0B0  7D 1E 5A 14 */	add r8, r30, r11
/* 801112B4 0010E0B4  54 84 18 38 */	slwi r4, r4, 3
/* 801112B8 0010E0B8  7C 07 58 10 */	subfc r0, r7, r11
/* 801112BC 0010E0BC  55 65 0F FE */	srwi r5, r11, 31
/* 801112C0 0010E0C0  91 0A 00 00 */	stw r8, 0x0(r10)
/* 801112C4 0010E0C4  7C 09 22 14 */	add r0, r9, r4
/* 801112C8 0010E0C8  38 8B 00 02 */	addi r4, r11, 0x2
/* 801112CC 0010E0CC  7C A5 31 10 */	subfe r5, r5, r6
/* 801112D0 0010E0D0  39 6B 00 01 */	addi r11, r11, 0x1
/* 801112D4 0010E0D4  7C 00 28 38 */	and r0, r0, r5
/* 801112D8 0010E0D8  54 84 18 38 */	slwi r4, r4, 3
/* 801112DC 0010E0DC  90 0A 00 04 */	stw r0, 0x4(r10)
/* 801112E0 0010E0E0  7D 1E 5A 14 */	add r8, r30, r11
/* 801112E4 0010E0E4  7C 07 58 10 */	subfc r0, r7, r11
/* 801112E8 0010E0E8  55 65 0F FE */	srwi r5, r11, 31
/* 801112EC 0010E0EC  7C 09 22 14 */	add r0, r9, r4
/* 801112F0 0010E0F0  38 8B 00 02 */	addi r4, r11, 0x2
/* 801112F4 0010E0F4  7C A5 31 10 */	subfe r5, r5, r6
/* 801112F8 0010E0F8  91 0A 00 08 */	stw r8, 0x8(r10)
/* 801112FC 0010E0FC  7C 00 28 38 */	and r0, r0, r5
/* 80111300 0010E100  39 6B 00 01 */	addi r11, r11, 0x1
/* 80111304 0010E104  90 0A 00 0C */	stw r0, 0xc(r10)
/* 80111308 0010E108  7D 1E 5A 14 */	add r8, r30, r11
/* 8011130C 0010E10C  54 84 18 38 */	slwi r4, r4, 3
/* 80111310 0010E110  7C 07 58 10 */	subfc r0, r7, r11
/* 80111314 0010E114  55 65 0F FE */	srwi r5, r11, 31
/* 80111318 0010E118  91 0A 00 10 */	stw r8, 0x10(r10)
/* 8011131C 0010E11C  7C 09 22 14 */	add r0, r9, r4
/* 80111320 0010E120  38 8B 00 02 */	addi r4, r11, 0x2
/* 80111324 0010E124  7C A5 31 10 */	subfe r5, r5, r6
/* 80111328 0010E128  39 6B 00 01 */	addi r11, r11, 0x1
/* 8011132C 0010E12C  7C 00 28 38 */	and r0, r0, r5
/* 80111330 0010E130  54 84 18 38 */	slwi r4, r4, 3
/* 80111334 0010E134  90 0A 00 14 */	stw r0, 0x14(r10)
/* 80111338 0010E138  7D 1E 5A 14 */	add r8, r30, r11
/* 8011133C 0010E13C  7C 07 58 10 */	subfc r0, r7, r11
/* 80111340 0010E140  55 65 0F FE */	srwi r5, r11, 31
/* 80111344 0010E144  91 0A 00 18 */	stw r8, 0x18(r10)
/* 80111348 0010E148  7C A5 31 10 */	subfe r5, r5, r6
/* 8011134C 0010E14C  7C 09 22 14 */	add r0, r9, r4
/* 80111350 0010E150  39 6B 00 01 */	addi r11, r11, 0x1
/* 80111354 0010E154  7C 00 28 38 */	and r0, r0, r5
/* 80111358 0010E158  90 0A 00 1C */	stw r0, 0x1c(r10)
/* 8011135C 0010E15C  39 4A 00 20 */	addi r10, r10, 0x20
/* 80111360 0010E160  42 00 FF 4C */	bdnz .L_801112AC
/* 80111364 0010E164  70 63 00 03 */	andi. r3, r3, 0x3
/* 80111368 0010E168  41 82 00 3C */	beq .L_801113A4
.L_8011136C:
/* 8011136C 0010E16C  7C 69 03 A6 */	mtctr r3
.L_80111370:
/* 80111370 0010E170  38 8B 00 01 */	addi r4, r11, 0x1
/* 80111374 0010E174  7D 1E 5A 14 */	add r8, r30, r11
/* 80111378 0010E178  54 84 18 38 */	slwi r4, r4, 3
/* 8011137C 0010E17C  7C 07 58 10 */	subfc r0, r7, r11
/* 80111380 0010E180  55 65 0F FE */	srwi r5, r11, 31
/* 80111384 0010E184  91 0A 00 00 */	stw r8, 0x0(r10)
/* 80111388 0010E188  7C A5 31 10 */	subfe r5, r5, r6
/* 8011138C 0010E18C  7C 09 22 14 */	add r0, r9, r4
/* 80111390 0010E190  7C 00 28 38 */	and r0, r0, r5
/* 80111394 0010E194  39 6B 00 01 */	addi r11, r11, 0x1
/* 80111398 0010E198  90 0A 00 04 */	stw r0, 0x4(r10)
/* 8011139C 0010E19C  39 4A 00 08 */	addi r10, r10, 0x8
/* 801113A0 0010E1A0  42 00 FF D0 */	bdnz .L_80111370
.L_801113A4:
/* 801113A4 0010E1A4  3A BF FF FF */	subi r21, r31, 0x1
/* 801113A8 0010E1A8  3B 40 00 00 */	li r26, 0x0
/* 801113AC 0010E1AC  48 00 01 44 */	b .L_801114F0
.L_801113B0:
/* 801113B0 0010E1B0  7C 7A F8 50 */	subf r3, r26, r31
/* 801113B4 0010E1B4  48 30 D2 B5 */	bl HSD_Randi
/* 801113B8 0010E1B8  7C 74 1B 79 */	mr. r20, r3
/* 801113BC 0010E1BC  7F 3B CB 78 */	mr r27, r25
/* 801113C0 0010E1C0  38 80 00 00 */	li r4, 0x0
/* 801113C4 0010E1C4  40 81 00 68 */	ble .L_8011142C
/* 801113C8 0010E1C8  2C 14 00 08 */	cmpwi r20, 0x8
/* 801113CC 0010E1CC  38 74 FF F8 */	subi r3, r20, 0x8
/* 801113D0 0010E1D0  40 81 00 40 */	ble .L_80111410
/* 801113D4 0010E1D4  38 03 00 07 */	addi r0, r3, 0x7
/* 801113D8 0010E1D8  54 00 E8 FE */	srwi r0, r0, 3
/* 801113DC 0010E1DC  7C 09 03 A6 */	mtctr r0
/* 801113E0 0010E1E0  2C 03 00 00 */	cmpwi r3, 0x0
/* 801113E4 0010E1E4  40 81 00 2C */	ble .L_80111410
.L_801113E8:
/* 801113E8 0010E1E8  80 7B 00 04 */	lwz r3, 0x4(r27)
/* 801113EC 0010E1EC  38 84 00 08 */	addi r4, r4, 0x8
/* 801113F0 0010E1F0  80 63 00 04 */	lwz r3, 0x4(r3)
/* 801113F4 0010E1F4  80 63 00 04 */	lwz r3, 0x4(r3)
/* 801113F8 0010E1F8  80 63 00 04 */	lwz r3, 0x4(r3)
/* 801113FC 0010E1FC  80 63 00 04 */	lwz r3, 0x4(r3)
/* 80111400 0010E200  80 63 00 04 */	lwz r3, 0x4(r3)
/* 80111404 0010E204  80 63 00 04 */	lwz r3, 0x4(r3)
/* 80111408 0010E208  83 63 00 04 */	lwz r27, 0x4(r3)
/* 8011140C 0010E20C  42 00 FF DC */	bdnz .L_801113E8
.L_80111410:
/* 80111410 0010E210  7C 04 A0 50 */	subf r0, r4, r20
/* 80111414 0010E214  7C 09 03 A6 */	mtctr r0
/* 80111418 0010E218  7C 04 A0 00 */	cmpw r4, r20
/* 8011141C 0010E21C  40 80 00 10 */	bge .L_8011142C
.L_80111420:
/* 80111420 0010E220  83 7B 00 04 */	lwz r27, 0x4(r27)
/* 80111424 0010E224  38 84 00 01 */	addi r4, r4, 0x1
/* 80111428 0010E228  42 00 FF F8 */	bdnz .L_80111420
.L_8011142C:
/* 8011142C 0010E22C  80 7B 00 00 */	lwz r3, 0x0(r27)
/* 80111430 0010E230  7E C4 B3 78 */	mr r4, r22
/* 80111434 0010E234  7E E5 BB 78 */	mr r5, r23
/* 80111438 0010E238  7F 06 C3 78 */	mr r6, r24
/* 8011143C 0010E23C  4B FB FD C1 */	bl kar_grcommon_get_eventpos_vectors_by_index
/* 80111440 0010E240  C0 3D 00 08 */	lfs f1, 0x8(r29)
/* 80111444 0010E244  7E C3 B3 78 */	mr r3, r22
/* 80111448 0010E248  48 00 01 2D */	bl kar_greventrock_is_position_clear_of_active_players
/* 8011144C 0010E24C  2C 03 00 00 */	cmpwi r3, 0x0
/* 80111450 0010E250  40 82 00 A8 */	bne .L_801114F8
/* 80111454 0010E254  2C 14 00 00 */	cmpwi r20, 0x0
/* 80111458 0010E258  40 82 00 0C */	bne .L_80111464
/* 8011145C 0010E25C  83 39 00 04 */	lwz r25, 0x4(r25)
/* 80111460 0010E260  48 00 00 8C */	b .L_801114EC
.L_80111464:
/* 80111464 0010E264  34 14 FF FF */	subic. r0, r20, 0x1
/* 80111468 0010E268  7F 3B CB 78 */	mr r27, r25
/* 8011146C 0010E26C  38 80 00 00 */	li r4, 0x0
/* 80111470 0010E270  40 81 00 70 */	ble .L_801114E0
/* 80111474 0010E274  38 14 FF FF */	subi r0, r20, 0x1
/* 80111478 0010E278  38 74 FF F7 */	subi r3, r20, 0x9
/* 8011147C 0010E27C  2C 00 00 08 */	cmpwi r0, 0x8
/* 80111480 0010E280  40 81 00 40 */	ble .L_801114C0
/* 80111484 0010E284  38 03 00 07 */	addi r0, r3, 0x7
/* 80111488 0010E288  54 00 E8 FE */	srwi r0, r0, 3
/* 8011148C 0010E28C  7C 09 03 A6 */	mtctr r0
/* 80111490 0010E290  2C 03 00 00 */	cmpwi r3, 0x0
/* 80111494 0010E294  40 81 00 2C */	ble .L_801114C0
.L_80111498:
/* 80111498 0010E298  80 7B 00 04 */	lwz r3, 0x4(r27)
/* 8011149C 0010E29C  38 84 00 08 */	addi r4, r4, 0x8
/* 801114A0 0010E2A0  80 63 00 04 */	lwz r3, 0x4(r3)
/* 801114A4 0010E2A4  80 63 00 04 */	lwz r3, 0x4(r3)
/* 801114A8 0010E2A8  80 63 00 04 */	lwz r3, 0x4(r3)
/* 801114AC 0010E2AC  80 63 00 04 */	lwz r3, 0x4(r3)
/* 801114B0 0010E2B0  80 63 00 04 */	lwz r3, 0x4(r3)
/* 801114B4 0010E2B4  80 63 00 04 */	lwz r3, 0x4(r3)
/* 801114B8 0010E2B8  83 63 00 04 */	lwz r27, 0x4(r3)
/* 801114BC 0010E2BC  42 00 FF DC */	bdnz .L_80111498
.L_801114C0:
/* 801114C0 0010E2C0  38 74 FF FF */	subi r3, r20, 0x1
/* 801114C4 0010E2C4  7C 04 18 50 */	subf r0, r4, r3
/* 801114C8 0010E2C8  7C 09 03 A6 */	mtctr r0
/* 801114CC 0010E2CC  7C 04 18 00 */	cmpw r4, r3
/* 801114D0 0010E2D0  40 80 00 10 */	bge .L_801114E0
.L_801114D4:
/* 801114D4 0010E2D4  83 7B 00 04 */	lwz r27, 0x4(r27)
/* 801114D8 0010E2D8  38 84 00 01 */	addi r4, r4, 0x1
/* 801114DC 0010E2DC  42 00 FF F8 */	bdnz .L_801114D4
.L_801114E0:
/* 801114E0 0010E2E0  80 7B 00 04 */	lwz r3, 0x4(r27)
/* 801114E4 0010E2E4  80 03 00 04 */	lwz r0, 0x4(r3)
/* 801114E8 0010E2E8  90 1B 00 04 */	stw r0, 0x4(r27)
.L_801114EC:
/* 801114EC 0010E2EC  3B 5A 00 01 */	addi r26, r26, 0x1
.L_801114F0:
/* 801114F0 0010E2F0  7C 1A A8 00 */	cmpw r26, r21
/* 801114F4 0010E2F4  41 80 FE BC */	blt .L_801113B0
.L_801114F8:
/* 801114F8 0010E2F8  38 1F FF FF */	subi r0, r31, 0x1
/* 801114FC 0010E2FC  7C 1A 00 00 */	cmpw r26, r0
/* 80111500 0010E300  40 80 00 0C */	bge .L_8011150C
/* 80111504 0010E304  82 9B 00 00 */	lwz r20, 0x0(r27)
/* 80111508 0010E308  48 00 00 1C */	b .L_80111524
.L_8011150C:
/* 8011150C 0010E30C  82 99 00 00 */	lwz r20, 0x0(r25)
/* 80111510 0010E310  7E C4 B3 78 */	mr r4, r22
/* 80111514 0010E314  7E E5 BB 78 */	mr r5, r23
/* 80111518 0010E318  7F 06 C3 78 */	mr r6, r24
/* 8011151C 0010E31C  7E 83 A3 78 */	mr r3, r20
/* 80111520 0010E320  4B FB FC DD */	bl kar_grcommon_get_eventpos_vectors_by_index
.L_80111524:
/* 80111524 0010E324  7C 1E A0 00 */	cmpw r30, r20
/* 80111528 0010E328  38 60 00 00 */	li r3, 0x0
/* 8011152C 0010E32C  41 81 00 14 */	bgt .L_80111540
/* 80111530 0010E330  7C 1E FA 14 */	add r0, r30, r31
/* 80111534 0010E334  7C 14 00 00 */	cmpw r20, r0
/* 80111538 0010E338  40 80 00 08 */	bge .L_80111540
/* 8011153C 0010E33C  38 60 00 01 */	li r3, 0x1
.L_80111540:
/* 80111540 0010E340  2C 03 00 00 */	cmpwi r3, 0x0
/* 80111544 0010E344  40 82 00 14 */	bne .L_80111558
/* 80111548 0010E348  38 7C 00 00 */	addi r3, r28, 0x0
/* 8011154C 0010E34C  38 BC 00 34 */	addi r5, r28, 0x34
/* 80111550 0010E350  38 80 00 E2 */	li r4, 0xe2
/* 80111554 0010E354  48 31 6F 65 */	bl __assert
.L_80111558:
/* 80111558 0010E358  7E 83 A3 78 */	mr r3, r20
/* 8011155C 0010E35C  39 61 00 40 */	addi r11, r1, 0x40
/* 80111560 0010E360  48 29 C6 25 */	bl _restgpr_20
/* 80111564 0010E364  80 01 00 44 */	lwz r0, 0x44(r1)
/* 80111568 0010E368  7C 08 03 A6 */	mtlr r0
/* 8011156C 0010E36C  38 21 00 40 */	addi r1, r1, 0x40
/* 80111570 0010E370  4E 80 00 20 */	blr
.endfn kar_greventrock_choose_eventpos_vectors_far_from_players

# .text:0x368 | 0x80111574 | size: 0x90
.fn kar_greventrock_is_position_clear_of_active_players, global
/* 80111574 0010E374  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80111578 0010E378  7C 08 02 A6 */	mflr r0
/* 8011157C 0010E37C  90 01 00 34 */	stw r0, 0x34(r1)
/* 80111580 0010E380  DB E1 00 28 */	stfd f31, 0x28(r1)
/* 80111584 0010E384  FF E0 08 90 */	fmr f31, f1
/* 80111588 0010E388  93 E1 00 24 */	stw r31, 0x24(r1)
/* 8011158C 0010E38C  3B E0 00 00 */	li r31, 0x0
/* 80111590 0010E390  93 C1 00 20 */	stw r30, 0x20(r1)
/* 80111594 0010E394  7C 7E 1B 78 */	mr r30, r3
.L_80111598:
/* 80111598 0010E398  7F E3 FB 78 */	mr r3, r31
/* 8011159C 0010E39C  48 11 B2 BD */	bl kar_plclearcheckerlib__near_8022c858
/* 801115A0 0010E3A0  2C 03 00 00 */	cmpwi r3, 0x0
/* 801115A4 0010E3A4  41 82 00 0C */	beq .L_801115B0
/* 801115A8 0010E3A8  2C 03 00 01 */	cmpwi r3, 0x1
/* 801115AC 0010E3AC  40 82 00 2C */	bne .L_801115D8
.L_801115B0:
/* 801115B0 0010E3B0  7F E3 FB 78 */	mr r3, r31
/* 801115B4 0010E3B4  38 81 00 08 */	addi r4, r1, 0x8
/* 801115B8 0010E3B8  48 11 AF B1 */	bl kar_plclearchecker_get_template_vec_008
/* 801115BC 0010E3BC  7F C3 F3 78 */	mr r3, r30
/* 801115C0 0010E3C0  38 81 00 08 */	addi r4, r1, 0x8
/* 801115C4 0010E3C4  48 2C 0D 31 */	bl fn_803D22F4
/* 801115C8 0010E3C8  FC 01 F8 40 */	fcmpo cr0, f1, f31
/* 801115CC 0010E3CC  40 80 00 0C */	bge .L_801115D8
/* 801115D0 0010E3D0  38 60 00 00 */	li r3, 0x0
/* 801115D4 0010E3D4  48 00 00 14 */	b .L_801115E8
.L_801115D8:
/* 801115D8 0010E3D8  3B FF 00 01 */	addi r31, r31, 0x1
/* 801115DC 0010E3DC  2C 1F 00 05 */	cmpwi r31, 0x5
/* 801115E0 0010E3E0  41 80 FF B8 */	blt .L_80111598
/* 801115E4 0010E3E4  38 60 00 01 */	li r3, 0x1
.L_801115E8:
/* 801115E8 0010E3E8  80 01 00 34 */	lwz r0, 0x34(r1)
/* 801115EC 0010E3EC  CB E1 00 28 */	lfd f31, 0x28(r1)
/* 801115F0 0010E3F0  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 801115F4 0010E3F4  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 801115F8 0010E3F8  7C 08 03 A6 */	mtlr r0
/* 801115FC 0010E3FC  38 21 00 30 */	addi r1, r1, 0x30
/* 80111600 0010E400  4E 80 00 20 */	blr
.endfn kar_greventrock_is_position_clear_of_active_players

# .text:0x3F8 | 0x80111604 | size: 0xB0
.fn kar_greventrock_event_update_kind40_pillar_prefall_and_fall, global
/* 80111604 0010E404  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80111608 0010E408  7C 08 02 A6 */	mflr r0
/* 8011160C 0010E40C  90 01 00 24 */	stw r0, 0x24(r1)
/* 80111610 0010E410  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80111614 0010E414  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80111618 0010E418  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8011161C 0010E41C  7C 7D 1B 78 */	mr r29, r3
/* 80111620 0010E420  80 0D 06 60 */	lwz r0, lbl_805DD740@sda21(r0)
/* 80111624 0010E424  28 00 00 00 */	cmplwi r0, 0x0
/* 80111628 0010E428  41 82 00 70 */	beq .L_80111698
/* 8011162C 0010E42C  4B FD D1 11 */	bl kar_greventgenerator_get_current_event_param
/* 80111630 0010E430  7C 7E 1B 78 */	mr r30, r3
/* 80111634 0010E434  7F A3 EB 78 */	mr r3, r29
/* 80111638 0010E438  4B FD D0 95 */	bl kar_greventgenerator_get_current_event_key_frame
/* 8011163C 0010E43C  7C 7F 1B 78 */	mr r31, r3
/* 80111640 0010E440  7F A3 EB 78 */	mr r3, r29
/* 80111644 0010E444  4B FD D0 81 */	bl kar_greventgenerator_get_state_elapsed_frames
/* 80111648 0010E448  7C 63 F8 51 */	subf. r3, r3, r31
/* 8011164C 0010E44C  41 82 00 2C */	beq .L_80111678
/* 80111650 0010E450  80 1E 00 04 */	lwz r0, 0x4(r30)
/* 80111654 0010E454  7C 03 00 40 */	cmplw r3, r0
/* 80111658 0010E458  41 81 00 40 */	bgt .L_80111698
/* 8011165C 0010E45C  80 6D 06 60 */	lwz r3, lbl_805DD740@sda21(r0)
/* 80111660 0010E460  4B FE 64 59 */	bl kar_gryakulib_get_yaku_state_or_none
/* 80111664 0010E464  2C 03 00 03 */	cmpwi r3, 0x3
/* 80111668 0010E468  41 82 00 30 */	beq .L_80111698
/* 8011166C 0010E46C  80 6D 06 60 */	lwz r3, lbl_805DD740@sda21(r0)
/* 80111670 0010E470  4B FF 03 91 */	bl kar_gryakupillar_prepare_kind40_eventrock_prefall_anim
/* 80111674 0010E474  48 00 00 24 */	b .L_80111698
.L_80111678:
/* 80111678 0010E478  80 6D 06 60 */	lwz r3, lbl_805DD740@sda21(r0)
/* 8011167C 0010E47C  4B FE 64 3D */	bl kar_gryakulib_get_yaku_state_or_none
/* 80111680 0010E480  2C 03 00 03 */	cmpwi r3, 0x3
/* 80111684 0010E484  40 82 00 14 */	bne .L_80111698
/* 80111688 0010E488  80 6D 06 60 */	lwz r3, lbl_805DD740@sda21(r0)
/* 8011168C 0010E48C  4B FF 04 A9 */	bl kar_gryakupillar_start_kind40_eventrock_fall_motion
/* 80111690 0010E490  7F A3 EB 78 */	mr r3, r29
/* 80111694 0010E494  48 00 00 41 */	bl kar_greventrock_finish_active_kind40_event
.L_80111698:
/* 80111698 0010E498  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8011169C 0010E49C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801116A0 0010E4A0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801116A4 0010E4A4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 801116A8 0010E4A8  7C 08 03 A6 */	mtlr r0
/* 801116AC 0010E4AC  38 21 00 20 */	addi r1, r1, 0x20
/* 801116B0 0010E4B0  4E 80 00 20 */	blr
.endfn kar_greventrock_event_update_kind40_pillar_prefall_and_fall

# .text:0x4A8 | 0x801116B4 | size: 0x20
.fn kar_greventrock_notify_eventrock_shatter_finished, global
/* 801116B4 0010E4B4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801116B8 0010E4B8  7C 08 02 A6 */	mflr r0
/* 801116BC 0010E4BC  90 01 00 14 */	stw r0, 0x14(r1)
/* 801116C0 0010E4C0  48 00 00 15 */	bl kar_greventrock_finish_active_kind40_event
/* 801116C4 0010E4C4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801116C8 0010E4C8  7C 08 03 A6 */	mtlr r0
/* 801116CC 0010E4CC  38 21 00 10 */	addi r1, r1, 0x10
/* 801116D0 0010E4D0  4E 80 00 20 */	blr
.endfn kar_greventrock_notify_eventrock_shatter_finished

# .text:0x4C8 | 0x801116D4 | size: 0x3C
.fn kar_greventrock_finish_active_kind40_event, global
/* 801116D4 0010E4D4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801116D8 0010E4D8  7C 08 02 A6 */	mflr r0
/* 801116DC 0010E4DC  90 01 00 14 */	stw r0, 0x14(r1)
/* 801116E0 0010E4E0  38 00 00 00 */	li r0, 0x0
/* 801116E4 0010E4E4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801116E8 0010E4E8  7C 7F 1B 78 */	mr r31, r3
/* 801116EC 0010E4EC  90 0D 06 60 */	stw r0, lbl_805DD740@sda21(r0)
/* 801116F0 0010E4F0  48 00 2A 65 */	bl fn_80114154
/* 801116F4 0010E4F4  7F E3 FB 78 */	mr r3, r31
/* 801116F8 0010E4F8  4B FD CF 69 */	bl kar_greventgenerator_enter_finish_state
/* 801116FC 0010E4FC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80111700 0010E500  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80111704 0010E504  7C 08 03 A6 */	mtlr r0
/* 80111708 0010E508  38 21 00 10 */	addi r1, r1, 0x10
/* 8011170C 0010E50C  4E 80 00 20 */	blr
.endfn kar_greventrock_finish_active_kind40_event

# .text:0x504 | 0x80111710 | size: 0x28
.fn kar_greventrock_cleanup_kind40_boxgenerator_state, global
/* 80111710 0010E510  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80111714 0010E514  7C 08 02 A6 */	mflr r0
/* 80111718 0010E518  90 01 00 14 */	stw r0, 0x14(r1)
/* 8011171C 0010E51C  4B FD D0 21 */	bl kar_greventgenerator_get_current_event_param
/* 80111720 0010E520  38 60 00 03 */	li r3, 0x3
/* 80111724 0010E524  4B FD C0 DD */	bl kar_grboxgenerator__near_800ed800
/* 80111728 0010E528  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011172C 0010E52C  7C 08 03 A6 */	mtlr r0
/* 80111730 0010E530  38 21 00 10 */	addi r1, r1, 0x10
/* 80111734 0010E534  4E 80 00 20 */	blr
.endfn kar_greventrock_cleanup_kind40_boxgenerator_state

# .text:0x52C | 0x80111738 | size: 0x64
.fn kar_greventrock_event_spawn_kind65_effect_fgm_timers, global
/* 80111738 0010E538  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8011173C 0010E53C  7C 08 02 A6 */	mflr r0
/* 80111740 0010E540  90 01 00 24 */	stw r0, 0x24(r1)
/* 80111744 0010E544  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80111748 0010E548  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8011174C 0010E54C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80111750 0010E550  7C 7D 1B 78 */	mr r29, r3
/* 80111754 0010E554  4B FD CF E9 */	bl kar_greventgenerator_get_current_event_param
/* 80111758 0010E558  7C 7E 1B 78 */	mr r30, r3
/* 8011175C 0010E55C  7F A3 EB 78 */	mr r3, r29
/* 80111760 0010E560  4B FD CF A9 */	bl kar_greventgenerator_get_current_eventpos_count
/* 80111764 0010E564  7C 7F 1B 78 */	mr r31, r3
/* 80111768 0010E568  7F A3 EB 78 */	mr r3, r29
/* 8011176C 0010E56C  4B FD CF 81 */	bl kar_greventgenerator_get_current_eventpos_start
/* 80111770 0010E570  7C 64 1B 78 */	mr r4, r3
/* 80111774 0010E574  80 7E 00 00 */	lwz r3, 0x0(r30)
/* 80111778 0010E578  7F E5 FB 78 */	mr r5, r31
/* 8011177C 0010E57C  4B FF 8E 61 */	bl kar_gryakubreakhpcoll_spawn_kind65_eventpos_effect_fgm_timers
/* 80111780 0010E580  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80111784 0010E584  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80111788 0010E588  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8011178C 0010E58C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80111790 0010E590  7C 08 03 A6 */	mtlr r0
/* 80111794 0010E594  38 21 00 20 */	addi r1, r1, 0x20
/* 80111798 0010E598  4E 80 00 20 */	blr
.endfn kar_greventrock_event_spawn_kind65_effect_fgm_timers

# .text:0x590 | 0x8011179C | size: 0x54
.fn kar_greventrock_event_destroy_kind65_timers_after_keyframe, global
/* 8011179C 0010E59C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801117A0 0010E5A0  7C 08 02 A6 */	mflr r0
/* 801117A4 0010E5A4  90 01 00 14 */	stw r0, 0x14(r1)
/* 801117A8 0010E5A8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801117AC 0010E5AC  93 C1 00 08 */	stw r30, 0x8(r1)
/* 801117B0 0010E5B0  7C 7E 1B 78 */	mr r30, r3
/* 801117B4 0010E5B4  4B FD CF 19 */	bl kar_greventgenerator_get_current_event_key_frame
/* 801117B8 0010E5B8  7C 7F 1B 78 */	mr r31, r3
/* 801117BC 0010E5BC  7F C3 F3 78 */	mr r3, r30
/* 801117C0 0010E5C0  4B FD CF 05 */	bl kar_greventgenerator_get_state_elapsed_frames
/* 801117C4 0010E5C4  7C 03 F8 40 */	cmplw r3, r31
/* 801117C8 0010E5C8  41 80 00 10 */	blt .L_801117D8
/* 801117CC 0010E5CC  4B FF 8F A9 */	bl kar_gryakubreakhpcoll_destroy_all_kind65_eventpos_effect_fgm_timers
/* 801117D0 0010E5D0  7F C3 F3 78 */	mr r3, r30
/* 801117D4 0010E5D4  4B FD CE 8D */	bl kar_greventgenerator_enter_finish_state
.L_801117D8:
/* 801117D8 0010E5D8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801117DC 0010E5DC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801117E0 0010E5E0  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 801117E4 0010E5E4  7C 08 03 A6 */	mtlr r0
/* 801117E8 0010E5E8  38 21 00 10 */	addi r1, r1, 0x10
/* 801117EC 0010E5EC  4E 80 00 20 */	blr
.endfn kar_greventrock_event_destroy_kind65_timers_after_keyframe

# .text:0x5E4 | 0x801117F0 | size: 0x94
.fn kar_greventrock_event_create_kind66_break_part_emitter, global
/* 801117F0 0010E5F0  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 801117F4 0010E5F4  7C 08 02 A6 */	mflr r0
/* 801117F8 0010E5F8  90 01 00 44 */	stw r0, 0x44(r1)
/* 801117FC 0010E5FC  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 80111800 0010E600  93 C1 00 38 */	stw r30, 0x38(r1)
/* 80111804 0010E604  93 A1 00 34 */	stw r29, 0x34(r1)
/* 80111808 0010E608  93 81 00 30 */	stw r28, 0x30(r1)
/* 8011180C 0010E60C  7C 7C 1B 78 */	mr r28, r3
/* 80111810 0010E610  83 AD 05 EC */	lwz r29, lbl_805DD6CC@sda21(r0)
/* 80111814 0010E614  4B FD CF 29 */	bl kar_greventgenerator_get_current_event_param
/* 80111818 0010E618  7C 7E 1B 78 */	mr r30, r3
/* 8011181C 0010E61C  7F 83 E3 78 */	mr r3, r28
/* 80111820 0010E620  4B FD CE E9 */	bl kar_greventgenerator_get_current_eventpos_count
/* 80111824 0010E624  7C 7F 1B 78 */	mr r31, r3
/* 80111828 0010E628  7F 83 E3 78 */	mr r3, r28
/* 8011182C 0010E62C  4B FD CE C1 */	bl kar_greventgenerator_get_current_eventpos_start
/* 80111830 0010E630  7C 65 1B 78 */	mr r5, r3
/* 80111834 0010E634  80 7D 00 00 */	lwz r3, 0x0(r29)
/* 80111838 0010E638  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 8011183C 0010E63C  7F E6 FB 78 */	mr r6, r31
/* 80111840 0010E640  4B FF 90 95 */	bl kar_gryakubreakhpcoll_create_kind66_eventrock_break_part_emitter
/* 80111844 0010E644  7F 83 E3 78 */	mr r3, r28
/* 80111848 0010E648  4B FD CE A5 */	bl kar_greventgenerator_get_current_eventpos_start
/* 8011184C 0010E64C  38 81 00 20 */	addi r4, r1, 0x20
/* 80111850 0010E650  38 A1 00 14 */	addi r5, r1, 0x14
/* 80111854 0010E654  38 C1 00 08 */	addi r6, r1, 0x8
/* 80111858 0010E658  4B FB F9 A5 */	bl kar_grcommon_get_eventpos_vectors_by_index
/* 8011185C 0010E65C  38 61 00 20 */	addi r3, r1, 0x20
/* 80111860 0010E660  48 00 27 B1 */	bl fn_80114010
/* 80111864 0010E664  80 01 00 44 */	lwz r0, 0x44(r1)
/* 80111868 0010E668  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 8011186C 0010E66C  83 C1 00 38 */	lwz r30, 0x38(r1)
/* 80111870 0010E670  83 A1 00 34 */	lwz r29, 0x34(r1)
/* 80111874 0010E674  83 81 00 30 */	lwz r28, 0x30(r1)
/* 80111878 0010E678  7C 08 03 A6 */	mtlr r0
/* 8011187C 0010E67C  38 21 00 40 */	addi r1, r1, 0x40
/* 80111880 0010E680  4E 80 00 20 */	blr
.endfn kar_greventrock_event_create_kind66_break_part_emitter

# .text:0x678 | 0x80111884 | size: 0x54
.fn kar_greventrock_event_finish_kind66_emitter_after_keyframe, global
/* 80111884 0010E684  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80111888 0010E688  7C 08 02 A6 */	mflr r0
/* 8011188C 0010E68C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80111890 0010E690  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80111894 0010E694  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80111898 0010E698  7C 7E 1B 78 */	mr r30, r3
/* 8011189C 0010E69C  4B FD CE 31 */	bl kar_greventgenerator_get_current_event_key_frame
/* 801118A0 0010E6A0  7C 7F 1B 78 */	mr r31, r3
/* 801118A4 0010E6A4  7F C3 F3 78 */	mr r3, r30
/* 801118A8 0010E6A8  4B FD CE 1D */	bl kar_greventgenerator_get_state_elapsed_frames
/* 801118AC 0010E6AC  7C 03 F8 40 */	cmplw r3, r31
/* 801118B0 0010E6B0  41 80 00 10 */	blt .L_801118C0
/* 801118B4 0010E6B4  7F C3 F3 78 */	mr r3, r30
/* 801118B8 0010E6B8  4B FD CD A9 */	bl kar_greventgenerator_enter_finish_state
/* 801118BC 0010E6BC  48 00 28 99 */	bl fn_80114154
.L_801118C0:
/* 801118C0 0010E6C0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801118C4 0010E6C4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801118C8 0010E6C8  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 801118CC 0010E6CC  7C 08 03 A6 */	mtlr r0
/* 801118D0 0010E6D0  38 21 00 10 */	addi r1, r1, 0x10
/* 801118D4 0010E6D4  4E 80 00 20 */	blr
.endfn kar_greventrock_event_finish_kind66_emitter_after_keyframe

# .text:0x6CC | 0x801118D8 | size: 0x4
.fn fn_801118D8, global
/* 801118D8 0010E6D8  4E 80 00 20 */	blr
.endfn fn_801118D8

# .text:0x6D0 | 0x801118DC | size: 0x50
.fn kar_greventrock_event_finish_after_keyframe, global
/* 801118DC 0010E6DC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801118E0 0010E6E0  7C 08 02 A6 */	mflr r0
/* 801118E4 0010E6E4  90 01 00 14 */	stw r0, 0x14(r1)
/* 801118E8 0010E6E8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801118EC 0010E6EC  93 C1 00 08 */	stw r30, 0x8(r1)
/* 801118F0 0010E6F0  7C 7E 1B 78 */	mr r30, r3
/* 801118F4 0010E6F4  4B FD CD D9 */	bl kar_greventgenerator_get_current_event_key_frame
/* 801118F8 0010E6F8  7C 7F 1B 78 */	mr r31, r3
/* 801118FC 0010E6FC  7F C3 F3 78 */	mr r3, r30
/* 80111900 0010E700  4B FD CD C5 */	bl kar_greventgenerator_get_state_elapsed_frames
/* 80111904 0010E704  7C 03 F8 40 */	cmplw r3, r31
/* 80111908 0010E708  41 80 00 0C */	blt .L_80111914
/* 8011190C 0010E70C  7F C3 F3 78 */	mr r3, r30
/* 80111910 0010E710  4B FD CD 51 */	bl kar_greventgenerator_enter_finish_state
.L_80111914:
/* 80111914 0010E714  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80111918 0010E718  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8011191C 0010E71C  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80111920 0010E720  7C 08 03 A6 */	mtlr r0
/* 80111924 0010E724  38 21 00 10 */	addi r1, r1, 0x10
/* 80111928 0010E728  4E 80 00 20 */	blr
.endfn kar_greventrock_event_finish_after_keyframe

# .text:0x720 | 0x8011192C | size: 0x4
.fn fn_8011192C, global
/* 8011192C 0010E72C  4E 80 00 20 */	blr
.endfn fn_8011192C

# .text:0x724 | 0x80111930 | size: 0x4
.fn fn_80111930, global
/* 80111930 0010E730  4E 80 00 20 */	blr
.endfn fn_80111930

# .text:0x728 | 0x80111934 | size: 0x34
.fn kar_greventrock_event_init_kind67_collapse_controller, global
/* 80111934 0010E734  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80111938 0010E738  7C 08 02 A6 */	mflr r0
/* 8011193C 0010E73C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80111940 0010E740  4B FD CD FD */	bl kar_greventgenerator_get_current_event_param
/* 80111944 0010E744  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80111948 0010E748  4B FF 91 7D */	bl kar_gryakubreakhpcoll_get_or_create_kind67_eventrock_collapse_controller
/* 8011194C 0010E74C  90 6D 06 68 */	stw r3, lbl_805DD748@sda21(r0)
/* 80111950 0010E750  38 60 00 0C */	li r3, 0xc
/* 80111954 0010E754  4B FD BE 31 */	bl kar_grboxgenerator__near_800ed784
/* 80111958 0010E758  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011195C 0010E75C  7C 08 03 A6 */	mtlr r0
/* 80111960 0010E760  38 21 00 10 */	addi r1, r1, 0x10
/* 80111964 0010E764  4E 80 00 20 */	blr
.endfn kar_greventrock_event_init_kind67_collapse_controller

# .text:0x75C | 0x80111968 | size: 0x4
.fn fn_80111968, global
/* 80111968 0010E768  4E 80 00 20 */	blr
.endfn fn_80111968

# .text:0x760 | 0x8011196C | size: 0x38
.fn kar_greventrock_finish_kind67_collapse_controller_event, global
/* 8011196C 0010E76C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80111970 0010E770  7C 08 02 A6 */	mflr r0
/* 80111974 0010E774  90 01 00 14 */	stw r0, 0x14(r1)
/* 80111978 0010E778  4B FD CD F9 */	bl kar_greventgenerator_get_gobj
/* 8011197C 0010E77C  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80111980 0010E780  38 00 00 00 */	li r0, 0x0
/* 80111984 0010E784  90 0D 06 68 */	stw r0, lbl_805DD748@sda21(r0)
/* 80111988 0010E788  4B FD CC D9 */	bl kar_greventgenerator_enter_finish_state
/* 8011198C 0010E78C  38 60 00 0C */	li r3, 0xc
/* 80111990 0010E790  4B FD BE 71 */	bl kar_grboxgenerator__near_800ed800
/* 80111994 0010E794  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80111998 0010E798  7C 08 03 A6 */	mtlr r0
/* 8011199C 0010E79C  38 21 00 10 */	addi r1, r1, 0x10
/* 801119A0 0010E7A0  4E 80 00 20 */	blr
.endfn kar_greventrock_finish_kind67_collapse_controller_event

# .text:0x798 | 0x801119A4 | size: 0x34
.fn kar_greventrock_get_active_kind67_collapse_controller, global
/* 801119A4 0010E7A4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801119A8 0010E7A8  7C 08 02 A6 */	mflr r0
/* 801119AC 0010E7AC  90 01 00 14 */	stw r0, 0x14(r1)
/* 801119B0 0010E7B0  4B FD CF 15 */	bl kar_greventgenerator_get_active_event_kind
/* 801119B4 0010E7B4  2C 03 00 0C */	cmpwi r3, 0xc
/* 801119B8 0010E7B8  40 82 00 0C */	bne .L_801119C4
/* 801119BC 0010E7BC  80 6D 06 68 */	lwz r3, lbl_805DD748@sda21(r0)
/* 801119C0 0010E7C0  48 00 00 08 */	b .L_801119C8
.L_801119C4:
/* 801119C4 0010E7C4  38 60 00 00 */	li r3, 0x0
.L_801119C8:
/* 801119C8 0010E7C8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801119CC 0010E7CC  7C 08 03 A6 */	mtlr r0
/* 801119D0 0010E7D0  38 21 00 10 */	addi r1, r1, 0x10
/* 801119D4 0010E7D4  4E 80 00 20 */	blr
.endfn kar_greventrock_get_active_kind67_collapse_controller

# .text:0x7CC | 0x801119D8 | size: 0x2C
.fn kar_greventrock_event_init_state15_boxgenerator_helper, global
/* 801119D8 0010E7D8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801119DC 0010E7DC  7C 08 02 A6 */	mflr r0
/* 801119E0 0010E7E0  90 01 00 14 */	stw r0, 0x14(r1)
/* 801119E4 0010E7E4  4B FD CD 59 */	bl kar_greventgenerator_get_current_event_param
/* 801119E8 0010E7E8  48 14 28 51 */	bl fn_80254238
/* 801119EC 0010E7EC  38 60 00 0F */	li r3, 0xf
/* 801119F0 0010E7F0  4B FD BD 95 */	bl kar_grboxgenerator__near_800ed784
/* 801119F4 0010E7F4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801119F8 0010E7F8  7C 08 03 A6 */	mtlr r0
/* 801119FC 0010E7FC  38 21 00 10 */	addi r1, r1, 0x10
/* 80111A00 0010E800  4E 80 00 20 */	blr
.endfn kar_greventrock_event_init_state15_boxgenerator_helper

# .text:0x7F8 | 0x80111A04 | size: 0x5C
.fn kar_greventrock_event_cleanup_state15_after_keyframe, global
/* 80111A04 0010E804  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80111A08 0010E808  7C 08 02 A6 */	mflr r0
/* 80111A0C 0010E80C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80111A10 0010E810  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80111A14 0010E814  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80111A18 0010E818  7C 7E 1B 78 */	mr r30, r3
/* 80111A1C 0010E81C  4B FD CC B1 */	bl kar_greventgenerator_get_current_event_key_frame
/* 80111A20 0010E820  7C 7F 1B 78 */	mr r31, r3
/* 80111A24 0010E824  7F C3 F3 78 */	mr r3, r30
/* 80111A28 0010E828  4B FD CC 9D */	bl kar_greventgenerator_get_state_elapsed_frames
/* 80111A2C 0010E82C  7C 03 F8 40 */	cmplw r3, r31
/* 80111A30 0010E830  41 80 00 18 */	blt .L_80111A48
/* 80111A34 0010E834  48 14 28 5D */	bl fn_80254290
/* 80111A38 0010E838  38 60 00 0F */	li r3, 0xf
/* 80111A3C 0010E83C  4B FD BD C5 */	bl kar_grboxgenerator__near_800ed800
/* 80111A40 0010E840  7F C3 F3 78 */	mr r3, r30
/* 80111A44 0010E844  4B FD CC 1D */	bl kar_greventgenerator_enter_finish_state
.L_80111A48:
/* 80111A48 0010E848  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80111A4C 0010E84C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80111A50 0010E850  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80111A54 0010E854  7C 08 03 A6 */	mtlr r0
/* 80111A58 0010E858  38 21 00 10 */	addi r1, r1, 0x10
/* 80111A5C 0010E85C  4E 80 00 20 */	blr
.endfn kar_greventrock_event_cleanup_state15_after_keyframe

# .text:0x854 | 0x80111A60 | size: 0x13C
.fn kar_greventrock_fill_random_box_spawn_config_from_event_table, global
/* 80111A60 0010E860  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80111A64 0010E864  7C 08 02 A6 */	mflr r0
/* 80111A68 0010E868  90 01 00 14 */	stw r0, 0x14(r1)
/* 80111A6C 0010E86C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80111A70 0010E870  7C 9F 23 78 */	mr r31, r4
/* 80111A74 0010E874  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80111A78 0010E878  7C 7E 1B 78 */	mr r30, r3
/* 80111A7C 0010E87C  80 63 00 04 */	lwz r3, 0x4(r3)
/* 80111A80 0010E880  48 30 CB E9 */	bl HSD_Randi
/* 80111A84 0010E884  1C 03 00 14 */	mulli r0, r3, 0x14
/* 80111A88 0010E888  80 DE 00 00 */	lwz r6, 0x0(r30)
/* 80111A8C 0010E88C  C0 62 94 38 */	lfs f3, lbl_805DFB38@sda21(r0)
/* 80111A90 0010E890  38 80 00 00 */	li r4, 0x0
/* 80111A94 0010E894  C0 22 94 3C */	lfs f1, lbl_805DFB3C@sda21(r0)
/* 80111A98 0010E898  38 60 00 01 */	li r3, 0x1
/* 80111A9C 0010E89C  7C C6 02 14 */	add r6, r6, r0
/* 80111AA0 0010E8A0  C0 02 94 40 */	lfs f0, lbl_805DFB40@sda21(r0)
/* 80111AA4 0010E8A4  80 06 00 04 */	lwz r0, 0x4(r6)
/* 80111AA8 0010E8A8  90 1F 00 00 */	stw r0, 0x0(r31)
/* 80111AAC 0010E8AC  D0 7F 00 04 */	stfs f3, 0x4(r31)
/* 80111AB0 0010E8B0  C0 46 00 08 */	lfs f2, 0x8(r6)
/* 80111AB4 0010E8B4  D0 5F 00 14 */	stfs f2, 0x14(r31)
/* 80111AB8 0010E8B8  D0 7F 00 08 */	stfs f3, 0x8(r31)
/* 80111ABC 0010E8BC  D0 7F 00 0C */	stfs f3, 0xc(r31)
/* 80111AC0 0010E8C0  D0 7F 00 10 */	stfs f3, 0x10(r31)
/* 80111AC4 0010E8C4  D0 7F 00 18 */	stfs f3, 0x18(r31)
/* 80111AC8 0010E8C8  D0 3F 00 1C */	stfs f1, 0x1c(r31)
/* 80111ACC 0010E8CC  C0 26 00 0C */	lfs f1, 0xc(r6)
/* 80111AD0 0010E8D0  D0 3F 00 20 */	stfs f1, 0x20(r31)
/* 80111AD4 0010E8D4  D0 7F 00 24 */	stfs f3, 0x24(r31)
/* 80111AD8 0010E8D8  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 80111ADC 0010E8DC  80 A6 00 00 */	lwz r5, 0x0(r6)
/* 80111AE0 0010E8E0  88 1F 00 2C */	lbz r0, 0x2c(r31)
/* 80111AE4 0010E8E4  50 A0 1E 38 */	rlwimi r0, r5, 3, 24, 28
/* 80111AE8 0010E8E8  98 1F 00 2C */	stb r0, 0x2c(r31)
/* 80111AEC 0010E8EC  88 A6 00 10 */	lbz r5, 0x10(r6)
/* 80111AF0 0010E8F0  88 1F 00 2C */	lbz r0, 0x2c(r31)
/* 80111AF4 0010E8F4  50 A0 DF 7E */	rlwimi r0, r5, 27, 29, 31
/* 80111AF8 0010E8F8  98 1F 00 2C */	stb r0, 0x2c(r31)
/* 80111AFC 0010E8FC  88 A6 00 10 */	lbz r5, 0x10(r6)
/* 80111B00 0010E900  88 1F 00 2D */	lbz r0, 0x2d(r31)
/* 80111B04 0010E904  50 A0 1E 36 */	rlwimi r0, r5, 3, 24, 27
/* 80111B08 0010E908  98 1F 00 2D */	stb r0, 0x2d(r31)
/* 80111B0C 0010E90C  88 1F 00 2D */	lbz r0, 0x2d(r31)
/* 80111B10 0010E910  50 80 1F 38 */	rlwimi r0, r4, 3, 28, 28
/* 80111B14 0010E914  98 1F 00 2D */	stb r0, 0x2d(r31)
/* 80111B18 0010E918  88 1F 00 2D */	lbz r0, 0x2d(r31)
/* 80111B1C 0010E91C  50 60 17 7A */	rlwimi r0, r3, 2, 29, 29
/* 80111B20 0010E920  98 1F 00 2D */	stb r0, 0x2d(r31)
/* 80111B24 0010E924  88 1F 00 2D */	lbz r0, 0x2d(r31)
/* 80111B28 0010E928  50 60 0F BC */	rlwimi r0, r3, 1, 30, 30
/* 80111B2C 0010E92C  98 1F 00 2D */	stb r0, 0x2d(r31)
/* 80111B30 0010E930  80 1F 00 2C */	lwz r0, 0x2c(r31)
/* 80111B34 0010E934  50 60 53 EA */	rlwimi r0, r3, 10, 15, 21
/* 80111B38 0010E938  90 1F 00 2C */	stw r0, 0x2c(r31)
/* 80111B3C 0010E93C  A0 1F 00 2E */	lhz r0, 0x2e(r31)
/* 80111B40 0010E940  50 80 15 BA */	rlwimi r0, r4, 2, 22, 29
/* 80111B44 0010E944  B0 1F 00 2E */	sth r0, 0x2e(r31)
/* 80111B48 0010E948  88 1F 00 2F */	lbz r0, 0x2f(r31)
/* 80111B4C 0010E94C  50 80 0F BC */	rlwimi r0, r4, 1, 30, 30
/* 80111B50 0010E950  98 1F 00 2F */	stb r0, 0x2f(r31)
/* 80111B54 0010E954  88 1F 00 2F */	lbz r0, 0x2f(r31)
/* 80111B58 0010E958  50 80 07 FE */	rlwimi r0, r4, 0, 31, 31
/* 80111B5C 0010E95C  98 1F 00 2F */	stb r0, 0x2f(r31)
/* 80111B60 0010E960  88 1F 00 30 */	lbz r0, 0x30(r31)
/* 80111B64 0010E964  50 80 2E 34 */	rlwimi r0, r4, 5, 24, 26
/* 80111B68 0010E968  98 1F 00 30 */	stb r0, 0x30(r31)
/* 80111B6C 0010E96C  88 1F 00 30 */	lbz r0, 0x30(r31)
/* 80111B70 0010E970  50 80 26 F6 */	rlwimi r0, r4, 4, 27, 27
/* 80111B74 0010E974  98 1F 00 30 */	stb r0, 0x30(r31)
/* 80111B78 0010E978  88 1F 00 30 */	lbz r0, 0x30(r31)
/* 80111B7C 0010E97C  50 80 1F 38 */	rlwimi r0, r4, 3, 28, 28
/* 80111B80 0010E980  98 1F 00 30 */	stb r0, 0x30(r31)
/* 80111B84 0010E984  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80111B88 0010E988  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80111B8C 0010E98C  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80111B90 0010E990  7C 08 03 A6 */	mtlr r0
/* 80111B94 0010E994  38 21 00 10 */	addi r1, r1, 0x10
/* 80111B98 0010E998  4E 80 00 20 */	blr
.endfn kar_greventrock_fill_random_box_spawn_config_from_event_table

# .text:0x990 | 0x80111B9C | size: 0x28
.fn kar_greventrock_event_init_state7_boxgenerator_helper, global
/* 80111B9C 0010E99C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80111BA0 0010E9A0  7C 08 02 A6 */	mflr r0
/* 80111BA4 0010E9A4  90 01 00 14 */	stw r0, 0x14(r1)
/* 80111BA8 0010E9A8  48 14 27 05 */	bl fn_802542AC
/* 80111BAC 0010E9AC  38 60 00 07 */	li r3, 0x7
/* 80111BB0 0010E9B0  4B FD BB D5 */	bl kar_grboxgenerator__near_800ed784
/* 80111BB4 0010E9B4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80111BB8 0010E9B8  7C 08 03 A6 */	mtlr r0
/* 80111BBC 0010E9BC  38 21 00 10 */	addi r1, r1, 0x10
/* 80111BC0 0010E9C0  4E 80 00 20 */	blr
.endfn kar_greventrock_event_init_state7_boxgenerator_helper

# .text:0x9B8 | 0x80111BC4 | size: 0x5C
.fn kar_greventrock_event_cleanup_state7_after_keyframe, global
/* 80111BC4 0010E9C4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80111BC8 0010E9C8  7C 08 02 A6 */	mflr r0
/* 80111BCC 0010E9CC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80111BD0 0010E9D0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80111BD4 0010E9D4  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80111BD8 0010E9D8  7C 7E 1B 78 */	mr r30, r3
/* 80111BDC 0010E9DC  4B FD CA F1 */	bl kar_greventgenerator_get_current_event_key_frame
/* 80111BE0 0010E9E0  7C 7F 1B 78 */	mr r31, r3
/* 80111BE4 0010E9E4  7F C3 F3 78 */	mr r3, r30
/* 80111BE8 0010E9E8  4B FD CA DD */	bl kar_greventgenerator_get_state_elapsed_frames
/* 80111BEC 0010E9EC  7C 03 F8 40 */	cmplw r3, r31
/* 80111BF0 0010E9F0  41 80 00 18 */	blt .L_80111C08
/* 80111BF4 0010E9F4  48 14 26 CD */	bl fn_802542C0
/* 80111BF8 0010E9F8  38 60 00 07 */	li r3, 0x7
/* 80111BFC 0010E9FC  4B FD BC 05 */	bl kar_grboxgenerator__near_800ed800
/* 80111C00 0010EA00  7F C3 F3 78 */	mr r3, r30
/* 80111C04 0010EA04  4B FD CA 5D */	bl kar_greventgenerator_enter_finish_state
.L_80111C08:
/* 80111C08 0010EA08  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80111C0C 0010EA0C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80111C10 0010EA10  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80111C14 0010EA14  7C 08 03 A6 */	mtlr r0
/* 80111C18 0010EA18  38 21 00 10 */	addi r1, r1, 0x10
/* 80111C1C 0010EA1C  4E 80 00 20 */	blr
.endfn kar_greventrock_event_cleanup_state7_after_keyframe

# .text:0xA14 | 0x80111C20 | size: 0x44
.fn kar_greventrock_event_init_state13_five_float_boxgenerator, global
/* 80111C20 0010EA20  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80111C24 0010EA24  7C 08 02 A6 */	mflr r0
/* 80111C28 0010EA28  90 01 00 14 */	stw r0, 0x14(r1)
/* 80111C2C 0010EA2C  4B FD CB 11 */	bl kar_greventgenerator_get_current_event_param
/* 80111C30 0010EA30  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80111C34 0010EA34  C0 23 00 00 */	lfs f1, 0x0(r3)
/* 80111C38 0010EA38  C0 43 00 04 */	lfs f2, 0x4(r3)
/* 80111C3C 0010EA3C  C0 63 00 08 */	lfs f3, 0x8(r3)
/* 80111C40 0010EA40  C0 83 00 0C */	lfs f4, 0xc(r3)
/* 80111C44 0010EA44  C0 A3 00 10 */	lfs f5, 0x10(r3)
/* 80111C48 0010EA48  48 14 25 5D */	bl fn_802541A4
/* 80111C4C 0010EA4C  38 60 00 0D */	li r3, 0xd
/* 80111C50 0010EA50  4B FD BB 35 */	bl kar_grboxgenerator__near_800ed784
/* 80111C54 0010EA54  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80111C58 0010EA58  7C 08 03 A6 */	mtlr r0
/* 80111C5C 0010EA5C  38 21 00 10 */	addi r1, r1, 0x10
/* 80111C60 0010EA60  4E 80 00 20 */	blr
.endfn kar_greventrock_event_init_state13_five_float_boxgenerator

# .text:0xA58 | 0x80111C64 | size: 0x5C
.fn kar_greventrock_event_cleanup_state13_after_keyframe, global
/* 80111C64 0010EA64  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80111C68 0010EA68  7C 08 02 A6 */	mflr r0
/* 80111C6C 0010EA6C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80111C70 0010EA70  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80111C74 0010EA74  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80111C78 0010EA78  7C 7E 1B 78 */	mr r30, r3
/* 80111C7C 0010EA7C  4B FD CA 51 */	bl kar_greventgenerator_get_current_event_key_frame
/* 80111C80 0010EA80  7C 7F 1B 78 */	mr r31, r3
/* 80111C84 0010EA84  7F C3 F3 78 */	mr r3, r30
/* 80111C88 0010EA88  4B FD CA 3D */	bl kar_greventgenerator_get_state_elapsed_frames
/* 80111C8C 0010EA8C  7C 03 F8 40 */	cmplw r3, r31
/* 80111C90 0010EA90  41 80 00 18 */	blt .L_80111CA8
/* 80111C94 0010EA94  48 14 25 89 */	bl fn_8025421C
/* 80111C98 0010EA98  38 60 00 0D */	li r3, 0xd
/* 80111C9C 0010EA9C  4B FD BB 65 */	bl kar_grboxgenerator__near_800ed800
/* 80111CA0 0010EAA0  7F C3 F3 78 */	mr r3, r30
/* 80111CA4 0010EAA4  4B FD C9 BD */	bl kar_greventgenerator_enter_finish_state
.L_80111CA8:
/* 80111CA8 0010EAA8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80111CAC 0010EAAC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80111CB0 0010EAB0  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80111CB4 0010EAB4  7C 08 03 A6 */	mtlr r0
/* 80111CB8 0010EAB8  38 21 00 10 */	addi r1, r1, 0x10
/* 80111CBC 0010EABC  4E 80 00 20 */	blr
.endfn kar_greventrock_event_cleanup_state13_after_keyframe

# .text:0xAB4 | 0x80111CC0 | size: 0x4C
.fn kar_greventrock_event_init_vcgenerator_from_three_floats, global
/* 80111CC0 0010EAC0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80111CC4 0010EAC4  7C 08 02 A6 */	mflr r0
/* 80111CC8 0010EAC8  90 01 00 24 */	stw r0, 0x24(r1)
/* 80111CCC 0010EACC  4B FD CA 71 */	bl kar_greventgenerator_get_current_event_param
/* 80111CD0 0010EAD0  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80111CD4 0010EAD4  C0 23 00 00 */	lfs f1, 0x0(r3)
/* 80111CD8 0010EAD8  C0 43 00 04 */	lfs f2, 0x4(r3)
/* 80111CDC 0010EADC  C0 63 00 08 */	lfs f3, 0x8(r3)
/* 80111CE0 0010EAE0  48 0C DF 85 */	bl kar_vcgenerator__near_801dfc64
/* 80111CE4 0010EAE4  38 61 00 08 */	addi r3, r1, 0x8
/* 80111CE8 0010EAE8  48 0C E1 11 */	bl kar_vcgenerator__near_801dfdf8
/* 80111CEC 0010EAEC  2C 03 00 00 */	cmpwi r3, 0x0
/* 80111CF0 0010EAF0  41 82 00 0C */	beq .L_80111CFC
/* 80111CF4 0010EAF4  38 61 00 08 */	addi r3, r1, 0x8
/* 80111CF8 0010EAF8  48 00 23 19 */	bl fn_80114010
.L_80111CFC:
/* 80111CFC 0010EAFC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80111D00 0010EB00  7C 08 03 A6 */	mtlr r0
/* 80111D04 0010EB04  38 21 00 20 */	addi r1, r1, 0x20
/* 80111D08 0010EB08  4E 80 00 20 */	blr
.endfn kar_greventrock_event_init_vcgenerator_from_three_floats

# .text:0xB00 | 0x80111D0C | size: 0x5C
.fn kar_greventrock_event_update_vcgenerator_until_done, global
/* 80111D0C 0010EB0C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80111D10 0010EB10  7C 08 02 A6 */	mflr r0
/* 80111D14 0010EB14  90 01 00 24 */	stw r0, 0x24(r1)
/* 80111D18 0010EB18  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80111D1C 0010EB1C  7C 7F 1B 78 */	mr r31, r3
/* 80111D20 0010EB20  48 0C E1 65 */	bl kar_vcgenerator__near_801dfe84
/* 80111D24 0010EB24  2C 03 00 00 */	cmpwi r3, 0x0
/* 80111D28 0010EB28  41 82 00 14 */	beq .L_80111D3C
/* 80111D2C 0010EB2C  7F E3 FB 78 */	mr r3, r31
/* 80111D30 0010EB30  4B FD C9 31 */	bl kar_greventgenerator_enter_finish_state
/* 80111D34 0010EB34  48 00 24 21 */	bl fn_80114154
/* 80111D38 0010EB38  48 00 00 1C */	b .L_80111D54
.L_80111D3C:
/* 80111D3C 0010EB3C  38 61 00 08 */	addi r3, r1, 0x8
/* 80111D40 0010EB40  48 0C E0 B9 */	bl kar_vcgenerator__near_801dfdf8
/* 80111D44 0010EB44  2C 03 00 00 */	cmpwi r3, 0x0
/* 80111D48 0010EB48  41 82 00 0C */	beq .L_80111D54
/* 80111D4C 0010EB4C  38 61 00 08 */	addi r3, r1, 0x8
/* 80111D50 0010EB50  48 00 23 95 */	bl fn_801140E4
.L_80111D54:
/* 80111D54 0010EB54  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80111D58 0010EB58  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80111D5C 0010EB5C  7C 08 03 A6 */	mtlr r0
/* 80111D60 0010EB60  38 21 00 20 */	addi r1, r1, 0x20
/* 80111D64 0010EB64  4E 80 00 20 */	blr
.endfn kar_greventrock_event_update_vcgenerator_until_done

# .text:0xB5C | 0x80111D68 | size: 0x4
.fn fn_80111D68, global
/* 80111D68 0010EB68  4E 80 00 20 */	blr
.endfn fn_80111D68

# .text:0xB60 | 0x80111D6C | size: 0x4
.fn fn_80111D6C, global
/* 80111D6C 0010EB6C  4E 80 00 20 */	blr
.endfn fn_80111D6C

# .text:0xB64 | 0x80111D70 | size: 0x190
.fn kar_greventrock_configure_vcgenerator_weighted_kind11_segment, global
/* 80111D70 0010EB70  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 80111D74 0010EB74  7C 08 02 A6 */	mflr r0
/* 80111D78 0010EB78  38 80 00 0B */	li r4, 0xb
/* 80111D7C 0010EB7C  90 01 00 64 */	stw r0, 0x64(r1)
/* 80111D80 0010EB80  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 80111D84 0010EB84  7C 7F 1B 78 */	mr r31, r3
/* 80111D88 0010EB88  93 C1 00 58 */	stw r30, 0x58(r1)
/* 80111D8C 0010EB8C  4B FD C9 CD */	bl kar_greventgenerator_get_event_param_for_kind
/* 80111D90 0010EB90  7C 7E 1B 78 */	mr r30, r3
/* 80111D94 0010EB94  7F E3 FB 78 */	mr r3, r31
/* 80111D98 0010EB98  38 80 00 0B */	li r4, 0xb
/* 80111D9C 0010EB9C  4B FD C9 89 */	bl kar_greventgenerator_get_eventpos_start_for_kind
/* 80111DA0 0010EBA0  80 DE 00 00 */	lwz r6, 0x0(r30)
/* 80111DA4 0010EBA4  7C 7F 1B 78 */	mr r31, r3
/* 80111DA8 0010EBA8  80 A6 00 0C */	lwz r5, 0xc(r6)
/* 80111DAC 0010EBAC  80 86 00 10 */	lwz r4, 0x10(r6)
/* 80111DB0 0010EBB0  80 06 00 14 */	lwz r0, 0x14(r6)
/* 80111DB4 0010EBB4  7C 65 22 14 */	add r3, r5, r4
/* 80111DB8 0010EBB8  80 86 00 18 */	lwz r4, 0x18(r6)
/* 80111DBC 0010EBBC  7C 63 02 14 */	add r3, r3, r0
/* 80111DC0 0010EBC0  80 06 00 1C */	lwz r0, 0x1c(r6)
/* 80111DC4 0010EBC4  7C 63 22 14 */	add r3, r3, r4
/* 80111DC8 0010EBC8  80 A6 00 20 */	lwz r5, 0x20(r6)
/* 80111DCC 0010EBCC  7C 63 02 14 */	add r3, r3, r0
/* 80111DD0 0010EBD0  80 86 00 24 */	lwz r4, 0x24(r6)
/* 80111DD4 0010EBD4  7C 63 2A 14 */	add r3, r3, r5
/* 80111DD8 0010EBD8  80 06 00 28 */	lwz r0, 0x28(r6)
/* 80111DDC 0010EBDC  7C 63 22 14 */	add r3, r3, r4
/* 80111DE0 0010EBE0  80 86 00 2C */	lwz r4, 0x2c(r6)
/* 80111DE4 0010EBE4  7C 63 02 14 */	add r3, r3, r0
/* 80111DE8 0010EBE8  80 06 00 30 */	lwz r0, 0x30(r6)
/* 80111DEC 0010EBEC  7C 63 22 14 */	add r3, r3, r4
/* 80111DF0 0010EBF0  7C 63 02 14 */	add r3, r3, r0
/* 80111DF4 0010EBF4  48 30 C8 75 */	bl HSD_Randi
/* 80111DF8 0010EBF8  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 80111DFC 0010EBFC  38 A0 00 00 */	li r5, 0x0
/* 80111E00 0010EC00  80 04 00 0C */	lwz r0, 0xc(r4)
/* 80111E04 0010EC04  7C 60 18 51 */	subf. r3, r0, r3
/* 80111E08 0010EC08  41 80 00 98 */	blt .L_80111EA0
/* 80111E0C 0010EC0C  80 04 00 10 */	lwz r0, 0x10(r4)
/* 80111E10 0010EC10  38 A0 00 01 */	li r5, 0x1
/* 80111E14 0010EC14  7C 60 18 51 */	subf. r3, r0, r3
/* 80111E18 0010EC18  41 80 00 88 */	blt .L_80111EA0
/* 80111E1C 0010EC1C  80 04 00 14 */	lwz r0, 0x14(r4)
/* 80111E20 0010EC20  38 A0 00 02 */	li r5, 0x2
/* 80111E24 0010EC24  7C 60 18 51 */	subf. r3, r0, r3
/* 80111E28 0010EC28  41 80 00 78 */	blt .L_80111EA0
/* 80111E2C 0010EC2C  80 04 00 18 */	lwz r0, 0x18(r4)
/* 80111E30 0010EC30  38 A0 00 03 */	li r5, 0x3
/* 80111E34 0010EC34  7C 60 18 51 */	subf. r3, r0, r3
/* 80111E38 0010EC38  41 80 00 68 */	blt .L_80111EA0
/* 80111E3C 0010EC3C  80 04 00 1C */	lwz r0, 0x1c(r4)
/* 80111E40 0010EC40  38 A0 00 04 */	li r5, 0x4
/* 80111E44 0010EC44  7C 60 18 51 */	subf. r3, r0, r3
/* 80111E48 0010EC48  41 80 00 58 */	blt .L_80111EA0
/* 80111E4C 0010EC4C  80 04 00 20 */	lwz r0, 0x20(r4)
/* 80111E50 0010EC50  38 A0 00 05 */	li r5, 0x5
/* 80111E54 0010EC54  7C 60 18 51 */	subf. r3, r0, r3
/* 80111E58 0010EC58  41 80 00 48 */	blt .L_80111EA0
/* 80111E5C 0010EC5C  80 04 00 24 */	lwz r0, 0x24(r4)
/* 80111E60 0010EC60  38 A0 00 06 */	li r5, 0x6
/* 80111E64 0010EC64  7C 60 18 51 */	subf. r3, r0, r3
/* 80111E68 0010EC68  41 80 00 38 */	blt .L_80111EA0
/* 80111E6C 0010EC6C  80 04 00 28 */	lwz r0, 0x28(r4)
/* 80111E70 0010EC70  38 A0 00 07 */	li r5, 0x7
/* 80111E74 0010EC74  7C 60 18 51 */	subf. r3, r0, r3
/* 80111E78 0010EC78  41 80 00 28 */	blt .L_80111EA0
/* 80111E7C 0010EC7C  80 04 00 2C */	lwz r0, 0x2c(r4)
/* 80111E80 0010EC80  38 A0 00 08 */	li r5, 0x8
/* 80111E84 0010EC84  7C 60 18 51 */	subf. r3, r0, r3
/* 80111E88 0010EC88  41 80 00 18 */	blt .L_80111EA0
/* 80111E8C 0010EC8C  80 04 00 30 */	lwz r0, 0x30(r4)
/* 80111E90 0010EC90  38 A0 00 09 */	li r5, 0x9
/* 80111E94 0010EC94  7C 60 18 51 */	subf. r3, r0, r3
/* 80111E98 0010EC98  41 80 00 08 */	blt .L_80111EA0
/* 80111E9C 0010EC9C  38 A0 00 0A */	li r5, 0xa
.L_80111EA0:
/* 80111EA0 0010ECA0  54 A0 08 3C */	slwi r0, r5, 1
/* 80111EA4 0010ECA4  38 81 00 44 */	addi r4, r1, 0x44
/* 80111EA8 0010ECA8  7F DF 02 14 */	add r30, r31, r0
/* 80111EAC 0010ECAC  38 A1 00 2C */	addi r5, r1, 0x2c
/* 80111EB0 0010ECB0  7F C3 F3 78 */	mr r3, r30
/* 80111EB4 0010ECB4  38 C1 00 20 */	addi r6, r1, 0x20
/* 80111EB8 0010ECB8  4B FB F3 45 */	bl kar_grcommon_get_eventpos_vectors_by_index
/* 80111EBC 0010ECBC  38 7E 00 01 */	addi r3, r30, 0x1
/* 80111EC0 0010ECC0  38 81 00 38 */	addi r4, r1, 0x38
/* 80111EC4 0010ECC4  38 A1 00 14 */	addi r5, r1, 0x14
/* 80111EC8 0010ECC8  38 C1 00 08 */	addi r6, r1, 0x8
/* 80111ECC 0010ECCC  4B FB F3 31 */	bl kar_grcommon_get_eventpos_vectors_by_index
/* 80111ED0 0010ECD0  48 0C DB D1 */	bl kar_vcgenerator__near_801dfaa0
/* 80111ED4 0010ECD4  38 61 00 44 */	addi r3, r1, 0x44
/* 80111ED8 0010ECD8  38 81 00 38 */	addi r4, r1, 0x38
/* 80111EDC 0010ECDC  38 A1 00 2C */	addi r5, r1, 0x2c
/* 80111EE0 0010ECE0  38 C1 00 20 */	addi r6, r1, 0x20
/* 80111EE4 0010ECE4  48 0C DC D1 */	bl kar_vcgenerator__near_801dfbb4
/* 80111EE8 0010ECE8  80 01 00 64 */	lwz r0, 0x64(r1)
/* 80111EEC 0010ECEC  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 80111EF0 0010ECF0  83 C1 00 58 */	lwz r30, 0x58(r1)
/* 80111EF4 0010ECF4  7C 08 03 A6 */	mtlr r0
/* 80111EF8 0010ECF8  38 21 00 60 */	addi r1, r1, 0x60
/* 80111EFC 0010ECFC  4E 80 00 20 */	blr
.endfn kar_greventrock_configure_vcgenerator_weighted_kind11_segment

# 0x804A79A0..0x804A7A20 | size: 0x80
.data
.balign 8

# .data:0x0 | 0x804A79A0 | size: 0x80
.obj kar_src_greventrock_c, global
	.4byte 0x67726576
	.4byte 0x656E7472
	.4byte 0x6F636B2E
	.4byte 0x63000000
	.4byte 0x6576656E
	.4byte 0x74506F73
	.4byte 0x4E756D20
	.4byte 0x3D3D2047
	.4byte 0x72457665
	.4byte 0x6E74526F
	.4byte 0x636B5F50
	.4byte 0x6F734E75
	.4byte 0x6D000000
	.4byte 0x6576656E
	.4byte 0x74506F73
	.4byte 0x53746172
	.4byte 0x74203C3D
	.4byte 0x20657665
	.4byte 0x6E74506F
	.4byte 0x73496420
	.4byte 0x26262065
	.4byte 0x76656E74
	.4byte 0x506F7349
	.4byte 0x64203C20
	.4byte 0x6576656E
	.4byte 0x74506F73
	.4byte 0x53746172
	.4byte 0x74202B20
	.4byte 0x6576656E
	.4byte 0x74506F73
	.4byte 0x4E756D00
	.4byte 0x00000000
.endobj kar_src_greventrock_c

# 0x80557868..0x805578B8 | size: 0x50
.section .bss, "wa", @nobits
.balign 8

# .bss:0x0 | 0x80557868 | size: 0x50
.obj kar_greventrock_eventpos_candidate_linked_list, global
	.skip 0x50
.endobj kar_greventrock_eventpos_candidate_linked_list

# 0x805DD748..0x805DD750 | size: 0x8
.section .sbss, "wa", @nobits
.balign 8

# .sbss:0x0 | 0x805DD748 | size: 0x8
.obj lbl_805DD748, global
	.skip 0x8
.endobj lbl_805DD748

# 0x805DFB38..0x805DFD10 | size: 0x1D8
.section .sdata2, "a"
.balign 8

# .sdata2:0x0 | 0x805DFB38 | size: 0x4
.obj lbl_805DFB38, global
	.float 0
.endobj lbl_805DFB38

# .sdata2:0x4 | 0x805DFB3C | size: 0x4
.obj lbl_805DFB3C, global
	.float 1
.endobj lbl_805DFB3C

# .sdata2:0x8 | 0x805DFB40 | size: 0x8
.obj lbl_805DFB40, global
	.float -1
	.float 0
.endobj lbl_805DFB40

# .sdata2:0x10 | 0x805DFB48 | size: 0x4
.obj lbl_805DFB48, global
	.float 0
.endobj lbl_805DFB48
	.4byte 0x00000000

# .sdata2:0x18 | 0x805DFB50 | size: 0x8
.obj lbl_805DFB50, global
	.double 4503601774854144
.endobj lbl_805DFB50

# .sdata2:0x20 | 0x805DFB58 | size: 0x4
.obj lbl_805DFB58, global
	.float 1
.endobj lbl_805DFB58

# .sdata2:0x24 | 0x805DFB5C | size: 0x4
.obj lbl_805DFB5C, global
	.float 0.85
.endobj lbl_805DFB5C

# .sdata2:0x28 | 0x805DFB60 | size: 0x4
.obj lbl_805DFB60, global
	.float 0.7
.endobj lbl_805DFB60

# .sdata2:0x2C | 0x805DFB64 | size: 0x4
.obj lbl_805DFB64, global
	.float 0.001
.endobj lbl_805DFB64

# .sdata2:0x30 | 0x805DFB68 | size: 0x4
.obj lbl_805DFB68, global
	.float 0.4
.endobj lbl_805DFB68

# .sdata2:0x34 | 0x805DFB6C | size: 0x4
.obj lbl_805DFB6C, global
	.float 450
.endobj lbl_805DFB6C

# .sdata2:0x38 | 0x805DFB70 | size: 0x4
.obj lbl_805DFB70, global
	.float 640
.endobj lbl_805DFB70

# .sdata2:0x3C | 0x805DFB74 | size: 0x4
.obj lbl_805DFB74, global
	.float 240
.endobj lbl_805DFB74

# .sdata2:0x40 | 0x805DFB78 | size: 0x8
.obj lbl_805DFB78, global
	.float 320
	.float 0
.endobj lbl_805DFB78

# .sdata2:0x48 | 0x805DFB80 | size: 0x4
.obj lbl_805DFB80, global
	.float 0.31415927
.endobj lbl_805DFB80

# .sdata2:0x4C | 0x805DFB84 | size: 0x4
.obj lbl_805DFB84, global
	.float 0.61086524
.endobj lbl_805DFB84

# .sdata2:0x50 | 0x805DFB88 | size: 0x4
.obj lbl_805DFB88, global
	.float 0
.endobj lbl_805DFB88

# .sdata2:0x54 | 0x805DFB8C | size: 0x4
.obj lbl_805DFB8C, global
	.float 120
.endobj lbl_805DFB8C

# .sdata2:0x58 | 0x805DFB90 | size: 0x4
.obj lbl_805DFB90, global
	.float 80
.endobj lbl_805DFB90

# .sdata2:0x5C | 0x805DFB94 | size: 0x4
.obj lbl_805DFB94, global
	.float 0.001
.endobj lbl_805DFB94

# .sdata2:0x60 | 0x805DFB98 | size: 0x4
.obj lbl_805DFB98, global
	.float 119.999
.endobj lbl_805DFB98

# .sdata2:0x64 | 0x805DFB9C | size: 0x4
.obj lbl_805DFB9C, global
	.float 1
.endobj lbl_805DFB9C

# .sdata2:0x68 | 0x805DFBA0 | size: 0x4
.obj lbl_805DFBA0, global
	.float -1
.endobj lbl_805DFBA0
	.4byte 0x00000000

# .sdata2:0x70 | 0x805DFBA8 | size: 0x8
.obj lbl_805DFBA8, global
	.double 1.5707963267948966
.endobj lbl_805DFBA8

# .sdata2:0x78 | 0x805DFBB0 | size: 0x8
.obj lbl_805DFBB0, global
	.double 6.283185307179586
.endobj lbl_805DFBB0

# .sdata2:0x80 | 0x805DFBB8 | size: 0x8
.obj lbl_805DFBB8, global
	.double 3.141592653589793
.endobj lbl_805DFBB8

# .sdata2:0x88 | 0x805DFBC0 | size: 0x4
.obj lbl_805DFBC0, global
	.float 0.16666669
.endobj lbl_805DFBC0

# .sdata2:0x8C | 0x805DFBC4 | size: 0x4
.obj lbl_805DFBC4, global
	.float 0.008332824
.endobj lbl_805DFBC4

# .sdata2:0x90 | 0x805DFBC8 | size: 0x4
.obj lbl_805DFBC8, global
	.float 0.00019587841
.endobj lbl_805DFBC8

# .sdata2:0x94 | 0x805DFBCC | size: 0x4
.obj lbl_805DFBCC, global
	.float 0.9999998
.endobj lbl_805DFBCC

# .sdata2:0x98 | 0x805DFBD0 | size: 0x4
.obj lbl_805DFBD0, global
	.float 0.49999395
.endobj lbl_805DFBD0

# .sdata2:0x9C | 0x805DFBD4 | size: 0x4
.obj lbl_805DFBD4, global
	.float 0.04163633
.endobj lbl_805DFBD4

# .sdata2:0xA0 | 0x805DFBD8 | size: 0x4
.obj lbl_805DFBD8, global
	.float 0.0013400711
.endobj lbl_805DFBD8
	.4byte 0x00000000

# .sdata2:0xA8 | 0x805DFBE0 | size: 0x8
.obj lbl_805DFBE0, global
	.double 0.7853981633974483
.endobj lbl_805DFBE0

# .sdata2:0xB0 | 0x805DFBE8 | size: 0x8
.obj lbl_805DFBE8, global
	.double 80
.endobj lbl_805DFBE8

# .sdata2:0xB8 | 0x805DFBF0 | size: 0x8
.obj lbl_805DFBF0, global
	.float 32768
	.float 0
.endobj lbl_805DFBF0

# .sdata2:0xC0 | 0x805DFBF8 | size: 0x4
.obj lbl_805DFBF8, global
	.float 64
.endobj lbl_805DFBF8

# .sdata2:0xC4 | 0x805DFBFC | size: 0x4
.obj lbl_805DFBFC, global
	.float 228.5
.endobj lbl_805DFBFC

# .sdata2:0xC8 | 0x805DFC00 | size: 0x4
.obj lbl_805DFC00, global
	.float 74
.endobj lbl_805DFC00

# .sdata2:0xCC | 0x805DFC04 | size: 0x4
.obj lbl_805DFC04, global
	.float 415
.endobj lbl_805DFC04

# .sdata2:0xD0 | 0x805DFC08 | size: 0x4
.obj lbl_805DFC08, global
	.float 10
.endobj lbl_805DFC08

# .sdata2:0xD4 | 0x805DFC0C | size: 0x4
.obj lbl_805DFC0C, global
	.float 540
.endobj lbl_805DFC0C

# .sdata2:0xD8 | 0x805DFC10 | size: 0x4
.obj lbl_805DFC10, global
	.float 446
.endobj lbl_805DFC10

# .sdata2:0xDC | 0x805DFC14 | size: 0x4
.obj lbl_805DFC14, global
	.float 1
.endobj lbl_805DFC14

# .sdata2:0xE0 | 0x805DFC18 | size: 0x4
.obj lbl_805DFC18, global
	.float 0
.endobj lbl_805DFC18

# .sdata2:0xE4 | 0x805DFC1C | size: 0x4
.obj lbl_805DFC1C, global
	.float 1
.endobj lbl_805DFC1C

# .sdata2:0xE8 | 0x805DFC20 | size: 0x4
.obj lbl_805DFC20, global
	.float 100
.endobj lbl_805DFC20
	.4byte 0x00000000

# .sdata2:0xF0 | 0x805DFC28 | size: 0x8
.obj lbl_805DFC28, global
	.double 4503601774854144
.endobj lbl_805DFC28

# .sdata2:0xF8 | 0x805DFC30 | size: 0x4
.obj lbl_805DFC30, global
	.float 100
.endobj lbl_805DFC30

# .sdata2:0xFC | 0x805DFC34 | size: 0x4
.obj lbl_805DFC34, global
	.float 0
.endobj lbl_805DFC34

# .sdata2:0x100 | 0x805DFC38 | size: 0x8
.obj lbl_805DFC38, global
	.float 1
	.float 0
.endobj lbl_805DFC38

# .sdata2:0x108 | 0x805DFC40 | size: 0x4
.obj lbl_805DFC40, global
	.float 100000
.endobj lbl_805DFC40

# .sdata2:0x10C | 0x805DFC44 | size: 0x4
.obj lbl_805DFC44, global
	.float 160934.4
.endobj lbl_805DFC44

# .sdata2:0x110 | 0x805DFC48 | size: 0x4
.obj lbl_805DFC48, global
	.float 10
.endobj lbl_805DFC48

# .sdata2:0x114 | 0x805DFC4C | size: 0x4
.obj lbl_805DFC4C, global
	.float 100
.endobj lbl_805DFC4C

# .sdata2:0x118 | 0x805DFC50 | size: 0x4
.obj lbl_805DFC50, global
	.float 5
.endobj lbl_805DFC50

# .sdata2:0x11C | 0x805DFC54 | size: 0x4
.obj lbl_805DFC54, global
	.float 0.017453292
.endobj lbl_805DFC54

# .sdata2:0x120 | 0x805DFC58 | size: 0x4
.obj lbl_805DFC58, global
	.float 30
.endobj lbl_805DFC58

# .sdata2:0x124 | 0x805DFC5C | size: 0x4
.obj lbl_805DFC5C, global
	.float 1
.endobj lbl_805DFC5C

# .sdata2:0x128 | 0x805DFC60 | size: 0x8
.obj lbl_805DFC60, global
	.double 4503601774854144
.endobj lbl_805DFC60

# .sdata2:0x130 | 0x805DFC68 | size: 0x8
.obj lbl_805DFC68, global
	.float 0
	.float 0
.endobj lbl_805DFC68

# .sdata2:0x138 | 0x805DFC70 | size: 0x8
.obj lbl_805DFC70, global
	.float 0
	.float 0
.endobj lbl_805DFC70

# .sdata2:0x140 | 0x805DFC78 | size: 0x4
.obj lbl_805DFC78, global
	.float 0
.endobj lbl_805DFC78

# .sdata2:0x144 | 0x805DFC7C | size: 0x4
.obj lbl_805DFC7C, global
	.float 1
.endobj lbl_805DFC7C

# .sdata2:0x148 | 0x805DFC80 | size: 0x4
.obj lbl_805DFC80, global
	.float -0.6
.endobj lbl_805DFC80

# .sdata2:0x14C | 0x805DFC84 | size: 0x4
.obj lbl_805DFC84, global
	.float 0.8
.endobj lbl_805DFC84

# .sdata2:0x150 | 0x805DFC88 | size: 0x8
.obj lbl_805DFC88, global
	.float 0.5
	.float 0
.endobj lbl_805DFC88

# .sdata2:0x158 | 0x805DFC90 | size: 0x4
.obj lbl_805DFC90, global
	.float 0
.endobj lbl_805DFC90

# .sdata2:0x15C | 0x805DFC94 | size: 0x4
.obj lbl_805DFC94, global
	.float 1
.endobj lbl_805DFC94

# .sdata2:0x160 | 0x805DFC98 | size: 0x8
.obj lbl_805DFC98, global
	.float 0
	.float 0
.endobj lbl_805DFC98

# .sdata2:0x168 | 0x805DFCA0 | size: 0x4
.obj lbl_805DFCA0, global
	.float -2.2
.endobj lbl_805DFCA0

# .sdata2:0x16C | 0x805DFCA4 | size: 0x4
.obj lbl_805DFCA4, global
	.float 0
.endobj lbl_805DFCA4

# .sdata2:0x170 | 0x805DFCA8 | size: 0x4
.obj lbl_805DFCA8, global
	.float 1
.endobj lbl_805DFCA8

# .sdata2:0x174 | 0x805DFCAC | size: 0x4
.obj lbl_805DFCAC, global
	.float 0
.endobj lbl_805DFCAC

# .sdata2:0x178 | 0x805DFCB0 | size: 0x4
.obj lbl_805DFCB0, global
	.float 2.2
.endobj lbl_805DFCB0
	.4byte 0x00000000

# .sdata2:0x180 | 0x805DFCB8 | size: 0x8
.obj lbl_805DFCB8, global
	.double 4503601774854144
.endobj lbl_805DFCB8

# .sdata2:0x188 | 0x805DFCC0 | size: 0x4
.obj lbl_805DFCC0, global
	.float 1
.endobj lbl_805DFCC0

# .sdata2:0x18C | 0x805DFCC4 | size: 0x4
.obj lbl_805DFCC4, global
	.float 0
.endobj lbl_805DFCC4

# .sdata2:0x190 | 0x805DFCC8 | size: 0x4
.obj lbl_805DFCC8, global
	.float 0
.endobj lbl_805DFCC8

# .sdata2:0x194 | 0x805DFCCC | size: 0x4
.obj lbl_805DFCCC, global
	.float 1
.endobj lbl_805DFCCC

# .sdata2:0x198 | 0x805DFCD0 | size: 0x4
.obj lbl_805DFCD0, global
	.float 100
.endobj lbl_805DFCD0

# .sdata2:0x19C | 0x805DFCD4 | size: 0x4
.obj lbl_805DFCD4, global
	.float 70
.endobj lbl_805DFCD4

# .sdata2:0x1A0 | 0x805DFCD8 | size: 0x4
.obj lbl_805DFCD8, global
	.float 1
.endobj lbl_805DFCD8

# .sdata2:0x1A4 | 0x805DFCDC | size: 0x4
.obj lbl_805DFCDC, global
	.float 3
.endobj lbl_805DFCDC

# .sdata2:0x1A8 | 0x805DFCE0 | size: 0x4
.obj lbl_805DFCE0, global
	.float 2
.endobj lbl_805DFCE0

# .sdata2:0x1AC | 0x805DFCE4 | size: 0x4
.obj lbl_805DFCE4, global
	.float 0
.endobj lbl_805DFCE4

# .sdata2:0x1B0 | 0x805DFCE8 | size: 0x8
.obj lbl_805DFCE8, global
	.float 1.2
	.float 0
.endobj lbl_805DFCE8

# .sdata2:0x1B8 | 0x805DFCF0 | size: 0x4
.obj lbl_805DFCF0, global
	.float 1
.endobj lbl_805DFCF0

# .sdata2:0x1BC | 0x805DFCF4 | size: 0x4
.obj lbl_805DFCF4, global
	.float 0
.endobj lbl_805DFCF4

# .sdata2:0x1C0 | 0x805DFCF8 | size: 0x4
.obj lbl_805DFCF8, global
	.float 1.4
.endobj lbl_805DFCF8

# .sdata2:0x1C4 | 0x805DFCFC | size: 0x4
.obj lbl_805DFCFC, global
	.float 1.2
.endobj lbl_805DFCFC

# .sdata2:0x1C8 | 0x805DFD00 | size: 0x4
.obj lbl_805DFD00, global
	.float 0
.endobj lbl_805DFD00

# .sdata2:0x1CC | 0x805DFD04 | size: 0x4
.obj lbl_805DFD04, global
	.float 1
.endobj lbl_805DFD04

# .sdata2:0x1D0 | 0x805DFD08 | size: 0x4
.obj lbl_805DFD08, global
	.float 1.8
.endobj lbl_805DFD08

# .sdata2:0x1D4 | 0x805DFD0C | size: 0x4
.obj lbl_805DFD0C, global
	.float 1.6
.endobj lbl_805DFD0C
