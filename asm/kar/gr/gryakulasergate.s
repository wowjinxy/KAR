.include "macros.inc"
.file "gryakulasergate.c"

# 0x801063F4..0x8010685C | size: 0x468
.text
.balign 4

# .text:0x0 | 0x801063F4 | size: 0x154
.fn kar_gryakulasergate_init_kind58_lasergate_ctrl, global
/* 801063F4 001031F4  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 801063F8 001031F8  7C 08 02 A6 */	mflr r0
/* 801063FC 001031FC  90 01 00 34 */	stw r0, 0x34(r1)
/* 80106400 00103200  39 61 00 30 */	addi r11, r1, 0x30
/* 80106404 00103204  48 2A 77 49 */	bl _savegpr_25
/* 80106408 00103208  7C 7D 1B 78 */	mr r29, r3
/* 8010640C 0010320C  3C 60 80 4A */	lis r3, kar_gryakubreakcommon_kind57_lasergate_callback_table@ha
/* 80106410 00103210  83 FD 00 2C */	lwz r31, 0x2c(r29)
/* 80106414 00103214  3B 83 6C 88 */	addi r28, r3, kar_gryakubreakcommon_kind57_lasergate_callback_table@l
/* 80106418 00103218  83 24 00 2C */	lwz r25, 0x2c(r4)
/* 8010641C 0010321C  3B 40 00 00 */	li r26, 0x0
/* 80106420 00103220  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80106424 00103224  3B 60 00 00 */	li r27, 0x0
/* 80106428 00103228  83 C3 00 00 */	lwz r30, 0x0(r3)
/* 8010642C 0010322C  48 00 00 20 */	b .L_8010644C
.L_80106430:
/* 80106430 00103230  80 BE 00 00 */	lwz r5, 0x0(r30)
/* 80106434 00103234  7F 23 CB 78 */	mr r3, r25
/* 80106438 00103238  7F A4 EB 78 */	mr r4, r29
/* 8010643C 0010323C  7C A5 D8 2E */	lwzx r5, r5, r27
/* 80106440 00103240  4B FE 22 8D */	bl kar_grswitch__near_800e86cc
/* 80106444 00103244  3B 7B 00 04 */	addi r27, r27, 0x4
/* 80106448 00103248  3B 5A 00 01 */	addi r26, r26, 0x1
.L_8010644C:
/* 8010644C 0010324C  80 1E 00 04 */	lwz r0, 0x4(r30)
/* 80106450 00103250  7C 1A 00 00 */	cmpw r26, r0
/* 80106454 00103254  41 80 FF DC */	blt .L_80106430
/* 80106458 00103258  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 8010645C 0010325C  38 00 00 00 */	li r0, 0x0
/* 80106460 00103260  2C 03 00 00 */	cmpwi r3, 0x0
/* 80106464 00103264  40 81 00 10 */	ble .L_80106474
/* 80106468 00103268  2C 03 00 04 */	cmpwi r3, 0x4
/* 8010646C 0010326C  41 81 00 08 */	bgt .L_80106474
/* 80106470 00103270  38 00 00 01 */	li r0, 0x1
.L_80106474:
/* 80106474 00103274  2C 00 00 00 */	cmpwi r0, 0x0
/* 80106478 00103278  40 82 00 14 */	bne .L_8010648C
/* 8010647C 0010327C  38 7C 00 88 */	addi r3, r28, 0x88
/* 80106480 00103280  38 BC 00 C0 */	addi r5, r28, 0xc0
/* 80106484 00103284  38 80 01 38 */	li r4, 0x138
/* 80106488 00103288  48 32 20 31 */	bl __assert
.L_8010648C:
/* 8010648C 0010328C  3B 20 00 00 */	li r25, 0x0
/* 80106490 00103290  7F FB FB 78 */	mr r27, r31
/* 80106494 00103294  7F 3A CB 78 */	mr r26, r25
.L_80106498:
/* 80106498 00103298  38 A0 00 00 */	li r5, 0x0
/* 8010649C 0010329C  90 BB 01 30 */	stw r5, 0x130(r27)
/* 801064A0 001032A0  80 1E 00 0C */	lwz r0, 0xc(r30)
/* 801064A4 001032A4  7C 19 00 00 */	cmpw r25, r0
/* 801064A8 001032A8  40 80 00 4C */	bge .L_801064F4
/* 801064AC 001032AC  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 801064B0 001032B0  80 6D 12 54 */	lwz r3, lbl_805DE334@sda21(r0)
/* 801064B4 001032B4  7C 04 D0 2E */	lwzx r0, r4, r26
/* 801064B8 001032B8  80 63 00 20 */	lwz r3, 0x20(r3)
/* 801064BC 001032BC  48 00 00 18 */	b .L_801064D4
.L_801064C0:
/* 801064C0 001032C0  7C 00 28 00 */	cmpw r0, r5
/* 801064C4 001032C4  40 82 00 08 */	bne .L_801064CC
/* 801064C8 001032C8  48 00 00 28 */	b .L_801064F0
.L_801064CC:
/* 801064CC 001032CC  80 63 00 08 */	lwz r3, 0x8(r3)
/* 801064D0 001032D0  38 A5 00 01 */	addi r5, r5, 0x1
.L_801064D4:
/* 801064D4 001032D4  28 03 00 00 */	cmplwi r3, 0x0
/* 801064D8 001032D8  40 82 FF E8 */	bne .L_801064C0
/* 801064DC 001032DC  38 7C 01 0C */	addi r3, r28, 0x10c
/* 801064E0 001032E0  38 80 09 6C */	li r4, 0x96c
/* 801064E4 001032E4  38 AD 92 10 */	li r5, lbl_805D62F0@sda21
/* 801064E8 001032E8  48 32 1F D1 */	bl __assert
/* 801064EC 001032EC  38 60 00 00 */	li r3, 0x0
.L_801064F0:
/* 801064F0 001032F0  90 7B 01 30 */	stw r3, 0x130(r27)
.L_801064F4:
/* 801064F4 001032F4  3B 39 00 01 */	addi r25, r25, 0x1
/* 801064F8 001032F8  3B 5A 00 04 */	addi r26, r26, 0x4
/* 801064FC 001032FC  2C 19 00 04 */	cmpwi r25, 0x4
/* 80106500 00103300  3B 7B 00 04 */	addi r27, r27, 0x4
/* 80106504 00103304  41 80 FF 94 */	blt .L_80106498
/* 80106508 00103308  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 8010650C 0010330C  80 03 00 14 */	lwz r0, 0x14(r3)
/* 80106510 00103310  28 00 00 00 */	cmplwi r0, 0x0
/* 80106514 00103314  41 82 00 14 */	beq .L_80106528
/* 80106518 00103318  7F A3 EB 78 */	mr r3, r29
/* 8010651C 0010331C  38 80 FF FF */	li r4, -0x1
/* 80106520 00103320  38 A0 00 00 */	li r5, 0x0
/* 80106524 00103324  4B FF 13 4D */	bl kar_gryakuaudio_configure_fgm_track_from_joint
.L_80106528:
/* 80106528 00103328  7F A3 EB 78 */	mr r3, r29
/* 8010652C 0010332C  48 00 00 1D */	bl kar_gryakulasergate_start_kind58_ctrl_idle_wait_motion
/* 80106530 00103330  39 61 00 30 */	addi r11, r1, 0x30
/* 80106534 00103334  48 2A 76 65 */	bl _restgpr_25
/* 80106538 00103338  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8010653C 0010333C  7C 08 03 A6 */	mtlr r0
/* 80106540 00103340  38 21 00 30 */	addi r1, r1, 0x30
/* 80106544 00103344  4E 80 00 20 */	blr
.endfn kar_gryakulasergate_init_kind58_lasergate_ctrl

# .text:0x154 | 0x80106548 | size: 0x64
.fn kar_gryakulasergate_start_kind58_ctrl_idle_wait_motion, global
/* 80106548 00103348  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010654C 0010334C  7C 08 02 A6 */	mflr r0
/* 80106550 00103350  90 01 00 14 */	stw r0, 0x14(r1)
/* 80106554 00103354  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80106558 00103358  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8010655C 0010335C  80 1F 01 1C */	lwz r0, 0x11c(r31)
/* 80106560 00103360  2C 00 00 00 */	cmpwi r0, 0x0
/* 80106564 00103364  40 81 00 10 */	ble .L_80106574
/* 80106568 00103368  38 7F 01 18 */	addi r3, r31, 0x118
/* 8010656C 0010336C  38 80 00 00 */	li r4, 0x0
/* 80106570 00103370  4B FE 3B 15 */	bl kar_graudio_play_fgm_entry_id
.L_80106574:
/* 80106574 00103374  C0 22 93 38 */	lfs f1, lbl_805DFA38@sda21(r0)
/* 80106578 00103378  7F E3 FB 78 */	mr r3, r31
/* 8010657C 0010337C  38 80 00 00 */	li r4, 0x0
/* 80106580 00103380  38 A0 FF FF */	li r5, -0x1
/* 80106584 00103384  FC 40 08 90 */	fmr f2, f1
/* 80106588 00103388  38 C0 FF FF */	li r6, -0x1
/* 8010658C 0010338C  FC 60 08 90 */	fmr f3, f1
/* 80106590 00103390  38 E0 00 00 */	li r7, 0x0
/* 80106594 00103394  4B FE EF B5 */	bl kar_gryaku_set_path_node_motion
/* 80106598 00103398  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010659C 0010339C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801065A0 001033A0  7C 08 03 A6 */	mtlr r0
/* 801065A4 001033A4  38 21 00 10 */	addi r1, r1, 0x10
/* 801065A8 001033A8  4E 80 00 20 */	blr
.endfn kar_gryakulasergate_start_kind58_ctrl_idle_wait_motion

# .text:0x1B8 | 0x801065AC | size: 0xAC
.fn kar_gryakulasergate_update_kind58_ctrl_target_reset_to_idle, global
/* 801065AC 001033AC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801065B0 001033B0  7C 08 02 A6 */	mflr r0
/* 801065B4 001033B4  90 01 00 24 */	stw r0, 0x24(r1)
/* 801065B8 001033B8  39 61 00 20 */	addi r11, r1, 0x20
/* 801065BC 001033BC  48 2A 75 99 */	bl _savegpr_27
/* 801065C0 001033C0  7C 7B 1B 78 */	mr r27, r3
/* 801065C4 001033C4  3B 80 00 00 */	li r28, 0x0
/* 801065C8 001033C8  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 801065CC 001033CC  80 64 00 08 */	lwz r3, 0x8(r4)
/* 801065D0 001033D0  7C 9E 23 78 */	mr r30, r4
/* 801065D4 001033D4  83 A3 00 00 */	lwz r29, 0x0(r3)
/* 801065D8 001033D8  48 00 00 5C */	b .L_80106634
.L_801065DC:
/* 801065DC 001033DC  80 7E 01 30 */	lwz r3, 0x130(r30)
/* 801065E0 001033E0  4B FF 14 D9 */	bl kar_gryakulib_get_yaku_state_or_none
/* 801065E4 001033E4  2C 03 00 00 */	cmpwi r3, 0x0
/* 801065E8 001033E8  40 82 00 44 */	bne .L_8010662C
/* 801065EC 001033EC  83 FB 00 2C */	lwz r31, 0x2c(r27)
/* 801065F0 001033F0  80 1F 01 1C */	lwz r0, 0x11c(r31)
/* 801065F4 001033F4  2C 00 00 00 */	cmpwi r0, 0x0
/* 801065F8 001033F8  40 81 00 10 */	ble .L_80106608
/* 801065FC 001033FC  38 7F 01 18 */	addi r3, r31, 0x118
/* 80106600 00103400  38 80 00 00 */	li r4, 0x0
/* 80106604 00103404  4B FE 3A 81 */	bl kar_graudio_play_fgm_entry_id
.L_80106608:
/* 80106608 00103408  C0 22 93 38 */	lfs f1, lbl_805DFA38@sda21(r0)
/* 8010660C 0010340C  7F E3 FB 78 */	mr r3, r31
/* 80106610 00103410  38 80 00 00 */	li r4, 0x0
/* 80106614 00103414  38 A0 FF FF */	li r5, -0x1
/* 80106618 00103418  FC 40 08 90 */	fmr f2, f1
/* 8010661C 0010341C  38 C0 FF FF */	li r6, -0x1
/* 80106620 00103420  FC 60 08 90 */	fmr f3, f1
/* 80106624 00103424  38 E0 00 00 */	li r7, 0x0
/* 80106628 00103428  4B FE EF 21 */	bl kar_gryaku_set_path_node_motion
.L_8010662C:
/* 8010662C 0010342C  3B DE 00 04 */	addi r30, r30, 0x4
/* 80106630 00103430  3B 9C 00 01 */	addi r28, r28, 0x1
.L_80106634:
/* 80106634 00103434  80 1D 00 0C */	lwz r0, 0xc(r29)
/* 80106638 00103438  7C 1C 00 00 */	cmpw r28, r0
/* 8010663C 0010343C  41 80 FF A0 */	blt .L_801065DC
/* 80106640 00103440  39 61 00 20 */	addi r11, r1, 0x20
/* 80106644 00103444  48 2A 75 5D */	bl _restgpr_27
/* 80106648 00103448  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8010664C 0010344C  7C 08 03 A6 */	mtlr r0
/* 80106650 00103450  38 21 00 20 */	addi r1, r1, 0x20
/* 80106654 00103454  4E 80 00 20 */	blr
.endfn kar_gryakulasergate_update_kind58_ctrl_target_reset_to_idle

# .text:0x264 | 0x80106658 | size: 0x16C
.fn kar_gryakulasergate_trigger_kind58_ctrl_open_linked_gates, global
/* 80106658 00103458  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8010665C 0010345C  7C 08 02 A6 */	mflr r0
/* 80106660 00103460  90 01 00 34 */	stw r0, 0x34(r1)
/* 80106664 00103464  39 61 00 30 */	addi r11, r1, 0x30
/* 80106668 00103468  48 2A 74 DD */	bl _savegpr_23
/* 8010666C 0010346C  7C 7C 1B 78 */	mr r28, r3
/* 80106670 00103470  3C 60 80 4A */	lis r3, kar_gryakubreakcommon_kind57_lasergate_callback_table@ha
/* 80106674 00103474  82 FC 00 2C */	lwz r23, 0x2c(r28)
/* 80106678 00103478  3B 63 6C 88 */	addi r27, r3, kar_gryakubreakcommon_kind57_lasergate_callback_table@l
/* 8010667C 0010347C  80 17 00 04 */	lwz r0, 0x4(r23)
/* 80106680 00103480  2C 00 00 3A */	cmpwi r0, 0x3a
/* 80106684 00103484  41 82 00 14 */	beq .L_80106698
/* 80106688 00103488  38 7B 00 88 */	addi r3, r27, 0x88
/* 8010668C 0010348C  38 BB 01 18 */	addi r5, r27, 0x118
/* 80106690 00103490  38 80 01 98 */	li r4, 0x198
/* 80106694 00103494  48 32 1E 25 */	bl __assert
.L_80106698:
/* 80106698 00103498  80 77 00 08 */	lwz r3, 0x8(r23)
/* 8010669C 0010349C  7E FF BB 78 */	mr r31, r23
/* 801066A0 001034A0  3B A0 00 00 */	li r29, 0x0
/* 801066A4 001034A4  83 C3 00 00 */	lwz r30, 0x0(r3)
/* 801066A8 001034A8  48 00 00 BC */	b .L_80106764
.L_801066AC:
/* 801066AC 001034AC  83 3F 01 30 */	lwz r25, 0x130(r31)
/* 801066B0 001034B0  83 59 00 2C */	lwz r26, 0x2c(r25)
/* 801066B4 001034B4  80 1A 00 04 */	lwz r0, 0x4(r26)
/* 801066B8 001034B8  2C 00 00 39 */	cmpwi r0, 0x39
/* 801066BC 001034BC  41 82 00 14 */	beq .L_801066D0
/* 801066C0 001034C0  38 7B 00 88 */	addi r3, r27, 0x88
/* 801066C4 001034C4  38 BB 00 9C */	addi r5, r27, 0x9c
/* 801066C8 001034C8  38 80 00 F4 */	li r4, 0xf4
/* 801066CC 001034CC  48 32 1D ED */	bl __assert
.L_801066D0:
/* 801066D0 001034D0  80 1A 00 74 */	lwz r0, 0x74(r26)
/* 801066D4 001034D4  2C 00 00 00 */	cmpwi r0, 0x0
/* 801066D8 001034D8  40 82 00 84 */	bne .L_8010675C
/* 801066DC 001034DC  83 59 00 2C */	lwz r26, 0x2c(r25)
/* 801066E0 001034E0  82 ED 05 EC */	lwz r23, lbl_805DD6CC@sda21(r0)
/* 801066E4 001034E4  80 9A 00 08 */	lwz r4, 0x8(r26)
/* 801066E8 001034E8  80 77 01 04 */	lwz r3, 0x104(r23)
/* 801066EC 001034EC  83 24 00 00 */	lwz r25, 0x0(r4)
/* 801066F0 001034F0  80 19 00 00 */	lwz r0, 0x0(r25)
/* 801066F4 001034F4  54 00 18 38 */	slwi r0, r0, 3
/* 801066F8 001034F8  7C 63 00 2E */	lwzx r3, r3, r0
/* 801066FC 001034FC  83 03 00 7C */	lwz r24, 0x7c(r3)
/* 80106700 00103500  28 18 00 00 */	cmplwi r24, 0x0
/* 80106704 00103504  40 82 00 14 */	bne .L_80106718
/* 80106708 00103508  38 7B 00 88 */	addi r3, r27, 0x88
/* 8010670C 0010350C  38 80 00 7D */	li r4, 0x7d
/* 80106710 00103510  38 AD 92 08 */	li r5, lbl_805D62E8@sda21
/* 80106714 00103514  48 32 1D A5 */	bl __assert
.L_80106718:
/* 80106718 00103518  C0 18 00 04 */	lfs f0, 0x4(r24)
/* 8010671C 0010351C  38 80 00 10 */	li r4, 0x10
/* 80106720 00103520  D0 1A 01 30 */	stfs f0, 0x130(r26)
/* 80106724 00103524  80 19 00 04 */	lwz r0, 0x4(r25)
/* 80106728 00103528  80 77 01 04 */	lwz r3, 0x104(r23)
/* 8010672C 0010352C  54 00 18 38 */	slwi r0, r0, 3
/* 80106730 00103530  7C 63 00 2E */	lwzx r3, r3, r0
/* 80106734 00103534  48 30 56 31 */	bl HSD_JObjSetFlags
/* 80106738 00103538  C0 22 93 38 */	lfs f1, lbl_805DFA38@sda21(r0)
/* 8010673C 0010353C  7F 43 D3 78 */	mr r3, r26
/* 80106740 00103540  80 B9 00 10 */	lwz r5, 0x10(r25)
/* 80106744 00103544  38 80 00 01 */	li r4, 0x1
/* 80106748 00103548  FC 60 08 90 */	fmr f3, f1
/* 8010674C 0010354C  80 D9 00 00 */	lwz r6, 0x0(r25)
/* 80106750 00103550  C0 42 93 3C */	lfs f2, lbl_805DFA3C@sda21(r0)
/* 80106754 00103554  38 E0 00 00 */	li r7, 0x0
/* 80106758 00103558  4B FE ED F1 */	bl kar_gryaku_set_path_node_motion
.L_8010675C:
/* 8010675C 0010355C  3B FF 00 04 */	addi r31, r31, 0x4
/* 80106760 00103560  3B BD 00 01 */	addi r29, r29, 0x1
.L_80106764:
/* 80106764 00103564  80 1E 00 0C */	lwz r0, 0xc(r30)
/* 80106768 00103568  7C 1D 00 00 */	cmpw r29, r0
/* 8010676C 0010356C  41 80 FF 40 */	blt .L_801066AC
/* 80106770 00103570  83 3C 00 2C */	lwz r25, 0x2c(r28)
/* 80106774 00103574  80 19 01 1C */	lwz r0, 0x11c(r25)
/* 80106778 00103578  2C 00 00 00 */	cmpwi r0, 0x0
/* 8010677C 0010357C  40 81 00 0C */	ble .L_80106788
/* 80106780 00103580  38 79 01 18 */	addi r3, r25, 0x118
/* 80106784 00103584  4B FE 39 FD */	bl kar_graudio_stop_active_fgm_slot
.L_80106788:
/* 80106788 00103588  C0 22 93 38 */	lfs f1, lbl_805DFA38@sda21(r0)
/* 8010678C 0010358C  7F 23 CB 78 */	mr r3, r25
/* 80106790 00103590  38 80 00 01 */	li r4, 0x1
/* 80106794 00103594  38 A0 FF FF */	li r5, -0x1
/* 80106798 00103598  FC 40 08 90 */	fmr f2, f1
/* 8010679C 0010359C  38 C0 FF FF */	li r6, -0x1
/* 801067A0 001035A0  FC 60 08 90 */	fmr f3, f1
/* 801067A4 001035A4  38 E0 00 00 */	li r7, 0x0
/* 801067A8 001035A8  4B FE ED A1 */	bl kar_gryaku_set_path_node_motion
/* 801067AC 001035AC  39 61 00 30 */	addi r11, r1, 0x30
/* 801067B0 001035B0  48 2A 73 E1 */	bl _restgpr_23
/* 801067B4 001035B4  80 01 00 34 */	lwz r0, 0x34(r1)
/* 801067B8 001035B8  7C 08 03 A6 */	mtlr r0
/* 801067BC 001035BC  38 21 00 30 */	addi r1, r1, 0x30
/* 801067C0 001035C0  4E 80 00 20 */	blr
.endfn kar_gryakulasergate_trigger_kind58_ctrl_open_linked_gates

# .text:0x3D0 | 0x801067C4 | size: 0x60
.fn kar_gryakulasergate_test_kind58_ctrl_has_idle_gate_target, global
/* 801067C4 001035C4  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 801067C8 001035C8  80 64 00 08 */	lwz r3, 0x8(r4)
/* 801067CC 001035CC  80 63 00 00 */	lwz r3, 0x0(r3)
/* 801067D0 001035D0  80 03 00 0C */	lwz r0, 0xc(r3)
/* 801067D4 001035D4  7C 09 03 A6 */	mtctr r0
/* 801067D8 001035D8  2C 00 00 00 */	cmpwi r0, 0x0
/* 801067DC 001035DC  40 81 00 40 */	ble .L_8010681C
.L_801067E0:
/* 801067E0 001035E0  80 64 01 30 */	lwz r3, 0x130(r4)
/* 801067E4 001035E4  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 801067E8 001035E8  80 03 00 74 */	lwz r0, 0x74(r3)
/* 801067EC 001035EC  2C 00 00 00 */	cmpwi r0, 0x0
/* 801067F0 001035F0  41 82 00 08 */	beq .L_801067F8
/* 801067F4 001035F4  48 00 00 0C */	b .L_80106800
.L_801067F8:
/* 801067F8 001035F8  38 00 00 01 */	li r0, 0x1
/* 801067FC 001035FC  48 00 00 08 */	b .L_80106804
.L_80106800:
/* 80106800 00103600  38 00 00 00 */	li r0, 0x0
.L_80106804:
/* 80106804 00103604  2C 00 00 00 */	cmpwi r0, 0x0
/* 80106808 00103608  41 82 00 0C */	beq .L_80106814
/* 8010680C 0010360C  38 60 00 01 */	li r3, 0x1
/* 80106810 00103610  4E 80 00 20 */	blr
.L_80106814:
/* 80106814 00103614  38 84 00 04 */	addi r4, r4, 0x4
/* 80106818 00103618  42 00 FF C8 */	bdnz .L_801067E0
.L_8010681C:
/* 8010681C 0010361C  38 60 00 00 */	li r3, 0x0
/* 80106820 00103620  4E 80 00 20 */	blr
.endfn kar_gryakulasergate_test_kind58_ctrl_has_idle_gate_target

# .text:0x430 | 0x80106824 | size: 0x38
.fn kar_gryakulasergate_create_stage_linked_kind32_breakfloor, global
/* 80106824 00103624  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80106828 00103628  7C 08 02 A6 */	mflr r0
/* 8010682C 0010362C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80106830 00103630  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80106834 00103634  7C 7F 1B 78 */	mr r31, r3
/* 80106838 00103638  38 60 00 20 */	li r3, 0x20
/* 8010683C 0010363C  4B FE DC 31 */	bl kar_gryaku_create_yaku_from_main_kind
/* 80106840 00103640  7F E4 FB 78 */	mr r4, r31
/* 80106844 00103644  48 00 00 19 */	bl kar_gryakubreakfloor_init_kind32_breakfloor
/* 80106848 00103648  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8010684C 0010364C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80106850 00103650  7C 08 03 A6 */	mtlr r0
/* 80106854 00103654  38 21 00 10 */	addi r1, r1, 0x10
/* 80106858 00103658  4E 80 00 20 */	blr
.endfn kar_gryakulasergate_create_stage_linked_kind32_breakfloor

# 0x804A6CDC..0x804A6DC8 | size: 0xEC
.data
.balign 4

# .data:0x0 | 0x804A6CDC | size: 0x20
.obj kar_gryakulasergate_kind58_ctrl_callback_table, global
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte kar_gryakulasergate_update_kind58_ctrl_target_reset_to_idle
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj kar_gryakulasergate_kind58_ctrl_callback_table

# .data:0x20 | 0x804A6CFC | size: 0xCC
.obj kar_gryakulasergate_kind58_ctrl_callback_table_ptr, global
	.4byte kar_gryakulasergate_kind58_ctrl_callback_table
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x67727961
	.4byte 0x6B756C61
	.4byte 0x73657267
	.4byte 0x6174652E
	.4byte 0x63000000
	.4byte 0x6779702D
	.4byte 0x3E6B696E
	.4byte 0x64203D3D
	.4byte 0x2047725F
	.4byte 0x59616B75
	.4byte 0x4B696E64
	.4byte 0x5F4C6173
	.4byte 0x65724761
	.4byte 0x74650000
	.4byte 0x30203C20
	.4byte 0x70617261
	.4byte 0x6D2D3E74
	.4byte 0x61726765
	.4byte 0x744E756D
	.4byte 0x20262620
	.4byte 0x70617261
	.4byte 0x6D2D3E74
	.4byte 0x61726765
	.4byte 0x744E756D
	.4byte 0x203C3D20
	.4byte 0x47725961
	.4byte 0x6B754C61
	.4byte 0x73657247
	.4byte 0x61746543
	.4byte 0x74726C5F
	.4byte 0x474F626A
	.4byte 0x4E756D4D
	.4byte 0x61780000
	.4byte 0x67726F75
	.4byte 0x6E642E68
	.4byte 0x00000000
	.4byte 0x6779702D
	.4byte 0x3E6B696E
	.4byte 0x64203D3D
	.4byte 0x2047725F
	.4byte 0x59616B75
	.4byte 0x4B696E64
	.4byte 0x5F4C6173
	.4byte 0x65724761
	.4byte 0x74654374
	.4byte 0x726C0000
.endobj kar_gryakulasergate_kind58_ctrl_callback_table_ptr

# 0x805D62E8..0x805D62F8 | size: 0x10
.section .sdata, "wa"
.balign 8

# .sdata:0x0 | 0x805D62E8 | size: 0x5
.obj lbl_805D62E8, global
	.string "aobj"
.endobj lbl_805D62E8

# .sdata:0x5 | 0x805D62ED | size: 0x3
.obj gap_09_805D62ED_sdata, global
.hidden gap_09_805D62ED_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D62ED_sdata

# .sdata:0x8 | 0x805D62F0 | size: 0x2
.obj lbl_805D62F0, global
	.string "0"
.endobj lbl_805D62F0

# .sdata:0xA | 0x805D62F2 | size: 0x6
.obj gap_09_805D62F2_sdata, global
.hidden gap_09_805D62F2_sdata
	.4byte 0x00000000
	.2byte 0x0000
.endobj gap_09_805D62F2_sdata
