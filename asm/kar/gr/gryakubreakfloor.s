.include "macros.inc"
.file "gryakubreakfloor.c"

# 0x8010685C..0x80107370 | size: 0xB14
.text
.balign 4

# .text:0x0 | 0x8010685C | size: 0x11C
.fn kar_gryakubreakfloor_init_kind32_breakfloor, global
/* 8010685C 0010365C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80106860 00103660  7C 08 02 A6 */	mflr r0
/* 80106864 00103664  90 01 00 24 */	stw r0, 0x24(r1)
/* 80106868 00103668  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8010686C 0010366C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80106870 00103670  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80106874 00103674  7C 7D 1B 78 */	mr r29, r3
/* 80106878 00103678  93 81 00 10 */	stw r28, 0x10(r1)
/* 8010687C 0010367C  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80106880 00103680  83 84 00 2C */	lwz r28, 0x2c(r4)
/* 80106884 00103684  80 BF 00 08 */	lwz r5, 0x8(r31)
/* 80106888 00103688  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 8010688C 0010368C  83 C5 00 00 */	lwz r30, 0x0(r5)
/* 80106890 00103690  80 9C 01 04 */	lwz r4, 0x104(r28)
/* 80106894 00103694  38 63 00 54 */	addi r3, r3, 0x54
/* 80106898 00103698  80 1E 00 00 */	lwz r0, 0x0(r30)
/* 8010689C 0010369C  54 00 18 38 */	slwi r0, r0, 3
/* 801068A0 001036A0  7C 84 00 2E */	lwzx r4, r4, r0
/* 801068A4 001036A4  4B FD 10 B1 */	bl kar_grcoll__800d7954
/* 801068A8 001036A8  90 7F 01 30 */	stw r3, 0x130(r31)
/* 801068AC 001036AC  80 1E 00 14 */	lwz r0, 0x14(r30)
/* 801068B0 001036B0  2C 00 FF FF */	cmpwi r0, -0x1
/* 801068B4 001036B4  41 82 00 54 */	beq .L_80106908
/* 801068B8 001036B8  80 7C 01 04 */	lwz r3, 0x104(r28)
/* 801068BC 001036BC  54 00 18 38 */	slwi r0, r0, 3
/* 801068C0 001036C0  80 CD 05 EC */	lwz r6, lbl_805DD6CC@sda21(r0)
/* 801068C4 001036C4  38 A0 00 00 */	li r5, 0x0
/* 801068C8 001036C8  7C 83 00 2E */	lwzx r4, r3, r0
/* 801068CC 001036CC  38 66 00 54 */	addi r3, r6, 0x54
/* 801068D0 001036D0  4B FD 10 F1 */	bl kar_grcoll__800d79c0
/* 801068D4 001036D4  7C 7C 1B 78 */	mr r28, r3
/* 801068D8 001036D8  80 03 01 38 */	lwz r0, 0x138(r3)
/* 801068DC 001036DC  28 00 00 00 */	cmplwi r0, 0x0
/* 801068E0 001036E0  40 82 00 1C */	bne .L_801068FC
/* 801068E4 001036E4  3C 60 80 4A */	lis r3, kar_src_gryakubreakfloor_c@ha
/* 801068E8 001036E8  3C A0 80 4A */	lis r5, kar_gryakubreakfloor_assert_zone_voidptr@ha
/* 801068EC 001036EC  38 63 6E 1C */	addi r3, r3, kar_src_gryakubreakfloor_c@l
/* 801068F0 001036F0  38 80 00 51 */	li r4, 0x51
/* 801068F4 001036F4  38 A5 6E 30 */	addi r5, r5, kar_gryakubreakfloor_assert_zone_voidptr@l
/* 801068F8 001036F8  48 32 1B C1 */	bl __assert
.L_801068FC:
/* 801068FC 001036FC  80 1C 01 38 */	lwz r0, 0x138(r28)
/* 80106900 00103700  90 1F 01 34 */	stw r0, 0x134(r31)
/* 80106904 00103704  48 00 00 0C */	b .L_80106910
.L_80106908:
/* 80106908 00103708  38 00 00 00 */	li r0, 0x0
/* 8010690C 0010370C  90 1F 01 34 */	stw r0, 0x134(r31)
.L_80106910:
/* 80106910 00103710  80 BF 00 00 */	lwz r5, 0x0(r31)
/* 80106914 00103714  38 60 00 00 */	li r3, 0x0
/* 80106918 00103718  80 9F 01 30 */	lwz r4, 0x130(r31)
/* 8010691C 0010371C  38 00 00 05 */	li r0, 0x5
/* 80106920 00103720  90 A4 00 90 */	stw r5, 0x90(r4)
/* 80106924 00103724  90 7F 01 38 */	stw r3, 0x138(r31)
/* 80106928 00103728  90 7F 01 3C */	stw r3, 0x13c(r31)
/* 8010692C 0010372C  90 1F 01 40 */	stw r0, 0x140(r31)
/* 80106930 00103730  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80106934 00103734  80 03 00 14 */	lwz r0, 0x14(r3)
/* 80106938 00103738  28 00 00 00 */	cmplwi r0, 0x0
/* 8010693C 0010373C  41 82 00 14 */	beq .L_80106950
/* 80106940 00103740  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 80106944 00103744  7F A3 EB 78 */	mr r3, r29
/* 80106948 00103748  38 A0 00 00 */	li r5, 0x0
/* 8010694C 0010374C  4B FF 0F 25 */	bl kar_gryakuaudio_configure_fgm_track_from_joint
.L_80106950:
/* 80106950 00103750  7F A3 EB 78 */	mr r3, r29
/* 80106954 00103754  48 00 00 25 */	bl kar_gryakubreakfloor_start_kind32_intact_motion
/* 80106958 00103758  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8010695C 0010375C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80106960 00103760  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80106964 00103764  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80106968 00103768  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8010696C 0010376C  7C 08 03 A6 */	mtlr r0
/* 80106970 00103770  38 21 00 20 */	addi r1, r1, 0x20
/* 80106974 00103774  4E 80 00 20 */	blr
.endfn kar_gryakubreakfloor_init_kind32_breakfloor

# .text:0x11C | 0x80106978 | size: 0x6C
.fn kar_gryakubreakfloor_start_kind32_intact_motion, global
/* 80106978 00103778  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010697C 0010377C  7C 08 02 A6 */	mflr r0
/* 80106980 00103780  C0 42 93 40 */	lfs f2, lbl_805DFA40@sda21(r0)
/* 80106984 00103784  38 A0 00 00 */	li r5, 0x0
/* 80106988 00103788  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010698C 0010378C  3C 00 43 30 */	lis r0, 0x4330
/* 80106990 00103790  C8 22 93 48 */	lfd f1, lbl_805DFA48@sda21(r0)
/* 80106994 00103794  FC 60 10 90 */	fmr f3, f2
/* 80106998 00103798  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8010699C 0010379C  38 E0 00 00 */	li r7, 0x0
/* 801069A0 001037A0  90 01 00 08 */	stw r0, 0x8(r1)
/* 801069A4 001037A4  80 83 00 08 */	lwz r4, 0x8(r3)
/* 801069A8 001037A8  80 C4 00 00 */	lwz r6, 0x0(r4)
/* 801069AC 001037AC  38 80 00 00 */	li r4, 0x0
/* 801069B0 001037B0  90 A3 01 3C */	stw r5, 0x13c(r3)
/* 801069B4 001037B4  80 03 01 3C */	lwz r0, 0x13c(r3)
/* 801069B8 001037B8  80 A6 00 04 */	lwz r5, 0x4(r6)
/* 801069BC 001037BC  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 801069C0 001037C0  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 801069C4 001037C4  90 01 00 0C */	stw r0, 0xc(r1)
/* 801069C8 001037C8  C8 01 00 08 */	lfd f0, 0x8(r1)
/* 801069CC 001037CC  EC 20 08 28 */	fsubs f1, f0, f1
/* 801069D0 001037D0  4B FE EB 79 */	bl kar_gryaku_set_path_node_motion
/* 801069D4 001037D4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801069D8 001037D8  7C 08 03 A6 */	mtlr r0
/* 801069DC 001037DC  38 21 00 10 */	addi r1, r1, 0x10
/* 801069E0 001037E0  4E 80 00 20 */	blr
.endfn kar_gryakubreakfloor_start_kind32_intact_motion

# .text:0x188 | 0x801069E4 | size: 0x3C
.fn kar_gryakubreakfloor_update_kind32_crack_delay_to_advance, global
/* 801069E4 001037E4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801069E8 001037E8  7C 08 02 A6 */	mflr r0
/* 801069EC 001037EC  90 01 00 14 */	stw r0, 0x14(r1)
/* 801069F0 001037F0  80 A3 00 2C */	lwz r5, 0x2c(r3)
/* 801069F4 001037F4  80 85 01 38 */	lwz r4, 0x138(r5)
/* 801069F8 001037F8  38 04 FF FF */	subi r0, r4, 0x1
/* 801069FC 001037FC  90 05 01 38 */	stw r0, 0x138(r5)
/* 80106A00 00103800  80 05 01 38 */	lwz r0, 0x138(r5)
/* 80106A04 00103804  2C 00 00 00 */	cmpwi r0, 0x0
/* 80106A08 00103808  41 81 00 08 */	bgt .L_80106A10
/* 80106A0C 0010380C  48 00 02 49 */	bl kar_gryakubreakfloor_advance_kind32_crack_or_break_sequence
.L_80106A10:
/* 80106A10 00103810  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80106A14 00103814  7C 08 03 A6 */	mtlr r0
/* 80106A18 00103818  38 21 00 10 */	addi r1, r1, 0x10
/* 80106A1C 0010381C  4E 80 00 20 */	blr
.endfn kar_gryakubreakfloor_update_kind32_crack_delay_to_advance

# .text:0x1C4 | 0x80106A20 | size: 0xF0
.fn kar_gryakubreakfloor_update_kind32_restore_after_contact_clear, global
/* 80106A20 00103820  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80106A24 00103824  7C 08 02 A6 */	mflr r0
/* 80106A28 00103828  90 01 00 24 */	stw r0, 0x24(r1)
/* 80106A2C 0010382C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80106A30 00103830  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80106A34 00103834  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80106A38 00103838  7C 7D 1B 78 */	mr r29, r3
/* 80106A3C 0010383C  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 80106A40 00103840  80 64 01 38 */	lwz r3, 0x138(r4)
/* 80106A44 00103844  38 03 FF FF */	subi r0, r3, 0x1
/* 80106A48 00103848  90 04 01 38 */	stw r0, 0x138(r4)
/* 80106A4C 0010384C  80 04 01 38 */	lwz r0, 0x138(r4)
/* 80106A50 00103850  2C 00 00 00 */	cmpwi r0, 0x0
/* 80106A54 00103854  41 81 00 A0 */	bgt .L_80106AF4
/* 80106A58 00103858  80 64 01 34 */	lwz r3, 0x134(r4)
/* 80106A5C 0010385C  28 03 00 00 */	cmplwi r3, 0x0
/* 80106A60 00103860  41 82 00 94 */	beq .L_80106AF4
/* 80106A64 00103864  4B FF 40 25 */	bl kar_gryakucatchzone_is_contact_flag_set
/* 80106A68 00103868  2C 03 00 00 */	cmpwi r3, 0x0
/* 80106A6C 0010386C  40 82 00 88 */	bne .L_80106AF4
/* 80106A70 00103870  83 DD 00 2C */	lwz r30, 0x2c(r29)
/* 80106A74 00103874  38 80 00 01 */	li r4, 0x1
/* 80106A78 00103878  83 AD 05 EC */	lwz r29, lbl_805DD6CC@sda21(r0)
/* 80106A7C 0010387C  80 BE 00 08 */	lwz r5, 0x8(r30)
/* 80106A80 00103880  80 7E 01 30 */	lwz r3, 0x130(r30)
/* 80106A84 00103884  83 E5 00 00 */	lwz r31, 0x0(r5)
/* 80106A88 00103888  4B FD 10 49 */	bl kar_grcoll__near_800d7ad0
/* 80106A8C 0010388C  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 80106A90 00103890  38 80 00 10 */	li r4, 0x10
/* 80106A94 00103894  80 7D 01 04 */	lwz r3, 0x104(r29)
/* 80106A98 00103898  54 00 18 38 */	slwi r0, r0, 3
/* 80106A9C 0010389C  7C 63 00 2E */	lwzx r3, r3, r0
/* 80106AA0 001038A0  48 30 56 D5 */	bl HSD_JObjClearFlagsAll
/* 80106AA4 001038A4  80 1E 01 1C */	lwz r0, 0x11c(r30)
/* 80106AA8 001038A8  2C 00 00 00 */	cmpwi r0, 0x0
/* 80106AAC 001038AC  40 81 00 10 */	ble .L_80106ABC
/* 80106AB0 001038B0  38 7E 01 18 */	addi r3, r30, 0x118
/* 80106AB4 001038B4  38 80 00 02 */	li r4, 0x2
/* 80106AB8 001038B8  4B FE 35 CD */	bl kar_graudio_play_fgm_entry_id
.L_80106ABC:
/* 80106ABC 001038BC  38 60 00 00 */	li r3, 0x0
/* 80106AC0 001038C0  C0 22 93 40 */	lfs f1, lbl_805DFA40@sda21(r0)
/* 80106AC4 001038C4  90 7E 01 38 */	stw r3, 0x138(r30)
/* 80106AC8 001038C8  38 00 00 05 */	li r0, 0x5
/* 80106ACC 001038CC  FC 60 08 90 */	fmr f3, f1
/* 80106AD0 001038D0  C0 42 93 50 */	lfs f2, lbl_805DFA50@sda21(r0)
/* 80106AD4 001038D4  90 7E 01 3C */	stw r3, 0x13c(r30)
/* 80106AD8 001038D8  7F C3 F3 78 */	mr r3, r30
/* 80106ADC 001038DC  38 80 00 03 */	li r4, 0x3
/* 80106AE0 001038E0  38 E0 00 00 */	li r7, 0x0
/* 80106AE4 001038E4  90 1E 01 40 */	stw r0, 0x140(r30)
/* 80106AE8 001038E8  80 BF 00 0C */	lwz r5, 0xc(r31)
/* 80106AEC 001038EC  80 DF 00 00 */	lwz r6, 0x0(r31)
/* 80106AF0 001038F0  4B FE EA 59 */	bl kar_gryaku_set_path_node_motion
.L_80106AF4:
/* 80106AF4 001038F4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80106AF8 001038F8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80106AFC 001038FC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80106B00 00103900  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80106B04 00103904  7C 08 03 A6 */	mtlr r0
/* 80106B08 00103908  38 21 00 20 */	addi r1, r1, 0x20
/* 80106B0C 0010390C  4E 80 00 20 */	blr
.endfn kar_gryakubreakfloor_update_kind32_restore_after_contact_clear

# .text:0x2B4 | 0x80106B10 | size: 0xC0
.fn kar_gryakubreakfloor_update_kind32_airride_clear_to_intact, global
/* 80106B10 00103910  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80106B14 00103914  7C 08 02 A6 */	mflr r0
/* 80106B18 00103918  90 01 00 24 */	stw r0, 0x24(r1)
/* 80106B1C 0010391C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80106B20 00103920  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80106B24 00103924  7C 7E 1B 78 */	mr r30, r3
/* 80106B28 00103928  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80106B2C 0010392C  80 8D 05 EC */	lwz r4, lbl_805DD6CC@sda21(r0)
/* 80106B30 00103930  80 63 00 08 */	lwz r3, 0x8(r3)
/* 80106B34 00103934  80 84 01 04 */	lwz r4, 0x104(r4)
/* 80106B38 00103938  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80106B3C 0010393C  80 03 00 00 */	lwz r0, 0x0(r3)
/* 80106B40 00103940  54 00 18 38 */	slwi r0, r0, 3
/* 80106B44 00103944  7F E4 00 2E */	lwzx r31, r4, r0
/* 80106B48 00103948  7F E3 FB 78 */	mr r3, r31
/* 80106B4C 0010394C  4B F4 DC 95 */	bl kar_gmlanmenu__near_800547e0
/* 80106B50 00103950  2C 03 00 00 */	cmpwi r3, 0x0
/* 80106B54 00103954  40 82 00 64 */	bne .L_80106BB8
/* 80106B58 00103958  7F E3 FB 78 */	mr r3, r31
/* 80106B5C 0010395C  4B F4 DE 45 */	bl kar_lbairride__800549a0
/* 80106B60 00103960  2C 03 00 00 */	cmpwi r3, 0x0
/* 80106B64 00103964  40 82 00 54 */	bne .L_80106BB8
/* 80106B68 00103968  80 7E 00 2C */	lwz r3, 0x2c(r30)
/* 80106B6C 0010396C  3C 00 43 30 */	lis r0, 0x4330
/* 80106B70 00103970  C0 42 93 40 */	lfs f2, lbl_805DFA40@sda21(r0)
/* 80106B74 00103974  38 A0 00 00 */	li r5, 0x0
/* 80106B78 00103978  80 83 00 08 */	lwz r4, 0x8(r3)
/* 80106B7C 0010397C  38 E0 00 00 */	li r7, 0x0
/* 80106B80 00103980  90 01 00 08 */	stw r0, 0x8(r1)
/* 80106B84 00103984  FC 60 10 90 */	fmr f3, f2
/* 80106B88 00103988  80 C4 00 00 */	lwz r6, 0x0(r4)
/* 80106B8C 0010398C  38 80 00 00 */	li r4, 0x0
/* 80106B90 00103990  C8 22 93 48 */	lfd f1, lbl_805DFA48@sda21(r0)
/* 80106B94 00103994  90 A3 01 3C */	stw r5, 0x13c(r3)
/* 80106B98 00103998  80 03 01 3C */	lwz r0, 0x13c(r3)
/* 80106B9C 0010399C  80 A6 00 04 */	lwz r5, 0x4(r6)
/* 80106BA0 001039A0  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 80106BA4 001039A4  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 80106BA8 001039A8  90 01 00 0C */	stw r0, 0xc(r1)
/* 80106BAC 001039AC  C8 01 00 08 */	lfd f0, 0x8(r1)
/* 80106BB0 001039B0  EC 20 08 28 */	fsubs f1, f0, f1
/* 80106BB4 001039B4  4B FE E9 95 */	bl kar_gryaku_set_path_node_motion
.L_80106BB8:
/* 80106BB8 001039B8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80106BBC 001039BC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80106BC0 001039C0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80106BC4 001039C4  7C 08 03 A6 */	mtlr r0
/* 80106BC8 001039C8  38 21 00 20 */	addi r1, r1, 0x20
/* 80106BCC 001039CC  4E 80 00 20 */	blr
.endfn kar_gryakubreakfloor_update_kind32_airride_clear_to_intact

# .text:0x374 | 0x80106BD0 | size: 0x84
.fn kar_gryakubreakfloor_handle_kind32_grcoll_hit, global
/* 80106BD0 001039D0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80106BD4 001039D4  7C 08 02 A6 */	mflr r0
/* 80106BD8 001039D8  90 01 00 24 */	stw r0, 0x24(r1)
/* 80106BDC 001039DC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80106BE0 001039E0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80106BE4 001039E4  7C 9E 23 78 */	mr r30, r4
/* 80106BE8 001039E8  7C A4 2B 78 */	mr r4, r5
/* 80106BEC 001039EC  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80106BF0 001039F0  7C 7D 1B 78 */	mr r29, r3
/* 80106BF4 001039F4  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80106BF8 001039F8  7F C3 F3 78 */	mr r3, r30
/* 80106BFC 001039FC  80 BF 01 30 */	lwz r5, 0x130(r31)
/* 80106C00 00103A00  4B FD 0F 8D */	bl kar_grcoll__near_800d7b8c
/* 80106C04 00103A04  2C 03 00 00 */	cmpwi r3, 0x0
/* 80106C08 00103A08  41 82 00 0C */	beq .L_80106C14
/* 80106C0C 00103A0C  38 60 00 00 */	li r3, 0x0
/* 80106C10 00103A10  48 00 00 28 */	b .L_80106C38
.L_80106C14:
/* 80106C14 00103A14  80 1F 00 74 */	lwz r0, 0x74(r31)
/* 80106C18 00103A18  2C 00 00 00 */	cmpwi r0, 0x0
/* 80106C1C 00103A1C  40 82 00 18 */	bne .L_80106C34
/* 80106C20 00103A20  7F A3 EB 78 */	mr r3, r29
/* 80106C24 00103A24  48 00 00 31 */	bl kar_gryakubreakfloor_advance_kind32_crack_or_break_sequence
/* 80106C28 00103A28  7F C3 F3 78 */	mr r3, r30
/* 80106C2C 00103A2C  4B FF F0 85 */	bl kar_gryakubreakcommon_resolve_break_credit_player
/* 80106C30 00103A30  90 7F 01 40 */	stw r3, 0x140(r31)
.L_80106C34:
/* 80106C34 00103A34  38 60 00 00 */	li r3, 0x0
.L_80106C38:
/* 80106C38 00103A38  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80106C3C 00103A3C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80106C40 00103A40  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80106C44 00103A44  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80106C48 00103A48  7C 08 03 A6 */	mtlr r0
/* 80106C4C 00103A4C  38 21 00 20 */	addi r1, r1, 0x20
/* 80106C50 00103A50  4E 80 00 20 */	blr
.endfn kar_gryakubreakfloor_handle_kind32_grcoll_hit

# .text:0x3F8 | 0x80106C54 | size: 0x23C
.fn kar_gryakubreakfloor_advance_kind32_crack_or_break_sequence, global
/* 80106C54 00103A54  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80106C58 00103A58  7C 08 02 A6 */	mflr r0
/* 80106C5C 00103A5C  90 01 00 34 */	stw r0, 0x34(r1)
/* 80106C60 00103A60  39 61 00 30 */	addi r11, r1, 0x30
/* 80106C64 00103A64  48 2A 6E F1 */	bl _savegpr_27
/* 80106C68 00103A68  7C 7D 1B 78 */	mr r29, r3
/* 80106C6C 00103A6C  80 A3 00 2C */	lwz r5, 0x2c(r3)
/* 80106C70 00103A70  80 85 00 08 */	lwz r4, 0x8(r5)
/* 80106C74 00103A74  80 65 01 3C */	lwz r3, 0x13c(r5)
/* 80106C78 00103A78  80 84 00 00 */	lwz r4, 0x0(r4)
/* 80106C7C 00103A7C  38 03 00 01 */	addi r0, r3, 0x1
/* 80106C80 00103A80  90 05 01 3C */	stw r0, 0x13c(r5)
/* 80106C84 00103A84  80 64 00 10 */	lwz r3, 0x10(r4)
/* 80106C88 00103A88  80 85 01 3C */	lwz r4, 0x13c(r5)
/* 80106C8C 00103A8C  80 03 00 04 */	lwz r0, 0x4(r3)
/* 80106C90 00103A90  7C 04 00 00 */	cmpw r4, r0
/* 80106C94 00103A94  40 81 00 DC */	ble .L_80106D70
/* 80106C98 00103A98  83 9D 00 2C */	lwz r28, 0x2c(r29)
/* 80106C9C 00103A9C  38 80 00 00 */	li r4, 0x0
/* 80106CA0 00103AA0  83 6D 05 EC */	lwz r27, lbl_805DD6CC@sda21(r0)
/* 80106CA4 00103AA4  80 BC 00 08 */	lwz r5, 0x8(r28)
/* 80106CA8 00103AA8  80 7C 01 30 */	lwz r3, 0x130(r28)
/* 80106CAC 00103AAC  83 E5 00 00 */	lwz r31, 0x0(r5)
/* 80106CB0 00103AB0  4B FD 0E 21 */	bl kar_grcoll__near_800d7ad0
/* 80106CB4 00103AB4  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 80106CB8 00103AB8  38 80 00 10 */	li r4, 0x10
/* 80106CBC 00103ABC  80 7B 01 04 */	lwz r3, 0x104(r27)
/* 80106CC0 00103AC0  54 00 18 38 */	slwi r0, r0, 3
/* 80106CC4 00103AC4  7C 63 00 2E */	lwzx r3, r3, r0
/* 80106CC8 00103AC8  48 30 51 39 */	bl HSD_JObjSetFlagsAll
/* 80106CCC 00103ACC  80 7F 00 10 */	lwz r3, 0x10(r31)
/* 80106CD0 00103AD0  3B C0 00 00 */	li r30, 0x0
/* 80106CD4 00103AD4  7F DB F3 78 */	mr r27, r30
/* 80106CD8 00103AD8  80 03 00 08 */	lwz r0, 0x8(r3)
/* 80106CDC 00103ADC  90 1C 01 38 */	stw r0, 0x138(r28)
/* 80106CE0 00103AE0  48 00 00 30 */	b .L_80106D10
.L_80106CE4:
/* 80106CE4 00103AE4  80 1F 00 20 */	lwz r0, 0x20(r31)
/* 80106CE8 00103AE8  7F A3 EB 78 */	mr r3, r29
/* 80106CEC 00103AEC  80 BF 00 00 */	lwz r5, 0x0(r31)
/* 80106CF0 00103AF0  38 C0 00 00 */	li r6, 0x0
/* 80106CF4 00103AF4  7C 80 DA 14 */	add r4, r0, r27
/* 80106CF8 00103AF8  38 E0 00 00 */	li r7, 0x0
/* 80106CFC 00103AFC  39 00 00 00 */	li r8, 0x0
/* 80106D00 00103B00  39 20 00 00 */	li r9, 0x0
/* 80106D04 00103B04  4B FF 03 41 */	bl kar_gryakueffect_request_by_entry_mode
/* 80106D08 00103B08  3B 7B 00 1C */	addi r27, r27, 0x1c
/* 80106D0C 00103B0C  3B DE 00 01 */	addi r30, r30, 0x1
.L_80106D10:
/* 80106D10 00103B10  80 1F 00 24 */	lwz r0, 0x24(r31)
/* 80106D14 00103B14  7C 1E 00 00 */	cmpw r30, r0
/* 80106D18 00103B18  41 80 FF CC */	blt .L_80106CE4
/* 80106D1C 00103B1C  80 1C 01 1C */	lwz r0, 0x11c(r28)
/* 80106D20 00103B20  2C 00 00 00 */	cmpwi r0, 0x0
/* 80106D24 00103B24  40 81 00 10 */	ble .L_80106D34
/* 80106D28 00103B28  38 7C 01 18 */	addi r3, r28, 0x118
/* 80106D2C 00103B2C  38 80 00 01 */	li r4, 0x1
/* 80106D30 00103B30  4B FE 33 55 */	bl kar_graudio_play_fgm_entry_id
.L_80106D34:
/* 80106D34 00103B34  80 9C 01 40 */	lwz r4, 0x140(r28)
/* 80106D38 00103B38  2C 04 00 05 */	cmpwi r4, 0x5
/* 80106D3C 00103B3C  41 82 00 0C */	beq .L_80106D48
/* 80106D40 00103B40  7F A3 EB 78 */	mr r3, r29
/* 80106D44 00103B44  4B FF F0 3D */	bl kar_gryakubreakcommon_award_clearchecker_break_credit
.L_80106D48:
/* 80106D48 00103B48  C0 22 93 40 */	lfs f1, lbl_805DFA40@sda21(r0)
/* 80106D4C 00103B4C  7F 83 E3 78 */	mr r3, r28
/* 80106D50 00103B50  80 BF 00 08 */	lwz r5, 0x8(r31)
/* 80106D54 00103B54  38 80 00 02 */	li r4, 0x2
/* 80106D58 00103B58  FC 60 08 90 */	fmr f3, f1
/* 80106D5C 00103B5C  80 DF 00 00 */	lwz r6, 0x0(r31)
/* 80106D60 00103B60  C0 42 93 50 */	lfs f2, lbl_805DFA50@sda21(r0)
/* 80106D64 00103B64  38 E0 00 00 */	li r7, 0x0
/* 80106D68 00103B68  4B FE E7 E1 */	bl kar_gryaku_set_path_node_motion
/* 80106D6C 00103B6C  48 00 01 0C */	b .L_80106E78
.L_80106D70:
/* 80106D70 00103B70  83 DD 00 2C */	lwz r30, 0x2c(r29)
/* 80106D74 00103B74  38 80 00 00 */	li r4, 0x0
/* 80106D78 00103B78  80 BE 01 3C */	lwz r5, 0x13c(r30)
/* 80106D7C 00103B7C  80 7E 00 08 */	lwz r3, 0x8(r30)
/* 80106D80 00103B80  2C 05 00 01 */	cmpwi r5, 0x1
/* 80106D84 00103B84  83 E3 00 00 */	lwz r31, 0x0(r3)
/* 80106D88 00103B88  41 80 00 18 */	blt .L_80106DA0
/* 80106D8C 00103B8C  80 7F 00 10 */	lwz r3, 0x10(r31)
/* 80106D90 00103B90  80 03 00 04 */	lwz r0, 0x4(r3)
/* 80106D94 00103B94  7C 05 00 00 */	cmpw r5, r0
/* 80106D98 00103B98  41 81 00 08 */	bgt .L_80106DA0
/* 80106D9C 00103B9C  38 80 00 01 */	li r4, 0x1
.L_80106DA0:
/* 80106DA0 00103BA0  2C 04 00 00 */	cmpwi r4, 0x0
/* 80106DA4 00103BA4  40 82 00 1C */	bne .L_80106DC0
/* 80106DA8 00103BA8  3C 60 80 4A */	lis r3, kar_src_gryakubreakfloor_c@ha
/* 80106DAC 00103BAC  3C A0 80 4A */	lis r5, kar_gryakubreakfloor_assert_crack_anim_range@ha
/* 80106DB0 00103BB0  38 63 6E 1C */	addi r3, r3, kar_src_gryakubreakfloor_c@l
/* 80106DB4 00103BB4  38 80 00 8E */	li r4, 0x8e
/* 80106DB8 00103BB8  38 A5 6E 40 */	addi r5, r5, kar_gryakubreakfloor_assert_crack_anim_range@l
/* 80106DBC 00103BBC  48 32 16 FD */	bl __assert
.L_80106DC0:
/* 80106DC0 00103BC0  80 7F 00 10 */	lwz r3, 0x10(r31)
/* 80106DC4 00103BC4  3B 80 00 00 */	li r28, 0x0
/* 80106DC8 00103BC8  80 1E 01 3C */	lwz r0, 0x13c(r30)
/* 80106DCC 00103BCC  7F 9B E3 78 */	mr r27, r28
/* 80106DD0 00103BD0  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80106DD4 00103BD4  54 00 10 3A */	slwi r0, r0, 2
/* 80106DD8 00103BD8  7C 63 02 14 */	add r3, r3, r0
/* 80106DDC 00103BDC  80 03 FF FC */	lwz r0, -0x4(r3)
/* 80106DE0 00103BE0  90 1E 01 38 */	stw r0, 0x138(r30)
/* 80106DE4 00103BE4  48 00 00 30 */	b .L_80106E14
.L_80106DE8:
/* 80106DE8 00103BE8  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 80106DEC 00103BEC  7F A3 EB 78 */	mr r3, r29
/* 80106DF0 00103BF0  80 BF 00 00 */	lwz r5, 0x0(r31)
/* 80106DF4 00103BF4  38 C0 00 00 */	li r6, 0x0
/* 80106DF8 00103BF8  7C 80 DA 14 */	add r4, r0, r27
/* 80106DFC 00103BFC  38 E0 00 00 */	li r7, 0x0
/* 80106E00 00103C00  39 00 00 00 */	li r8, 0x0
/* 80106E04 00103C04  39 20 00 00 */	li r9, 0x0
/* 80106E08 00103C08  4B FF 02 3D */	bl kar_gryakueffect_request_by_entry_mode
/* 80106E0C 00103C0C  3B 7B 00 1C */	addi r27, r27, 0x1c
/* 80106E10 00103C10  3B 9C 00 01 */	addi r28, r28, 0x1
.L_80106E14:
/* 80106E14 00103C14  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 80106E18 00103C18  7C 1C 00 00 */	cmpw r28, r0
/* 80106E1C 00103C1C  41 80 FF CC */	blt .L_80106DE8
/* 80106E20 00103C20  80 1E 01 1C */	lwz r0, 0x11c(r30)
/* 80106E24 00103C24  2C 00 00 00 */	cmpwi r0, 0x0
/* 80106E28 00103C28  40 81 00 10 */	ble .L_80106E38
/* 80106E2C 00103C2C  38 7E 01 18 */	addi r3, r30, 0x118
/* 80106E30 00103C30  38 80 00 00 */	li r4, 0x0
/* 80106E34 00103C34  4B FE 32 51 */	bl kar_graudio_play_fgm_entry_id
.L_80106E38:
/* 80106E38 00103C38  80 9E 01 3C */	lwz r4, 0x13c(r30)
/* 80106E3C 00103C3C  3C 00 43 30 */	lis r0, 0x4330
/* 80106E40 00103C40  C0 42 93 40 */	lfs f2, lbl_805DFA40@sda21(r0)
/* 80106E44 00103C44  7F C3 F3 78 */	mr r3, r30
/* 80106E48 00103C48  6C 84 80 00 */	xoris r4, r4, 0x8000
/* 80106E4C 00103C4C  90 01 00 08 */	stw r0, 0x8(r1)
/* 80106E50 00103C50  C8 22 93 48 */	lfd f1, lbl_805DFA48@sda21(r0)
/* 80106E54 00103C54  FC 60 10 90 */	fmr f3, f2
/* 80106E58 00103C58  90 81 00 0C */	stw r4, 0xc(r1)
/* 80106E5C 00103C5C  38 80 00 01 */	li r4, 0x1
/* 80106E60 00103C60  80 BF 00 04 */	lwz r5, 0x4(r31)
/* 80106E64 00103C64  38 E0 00 00 */	li r7, 0x0
/* 80106E68 00103C68  C8 01 00 08 */	lfd f0, 0x8(r1)
/* 80106E6C 00103C6C  80 DF 00 00 */	lwz r6, 0x0(r31)
/* 80106E70 00103C70  EC 20 08 28 */	fsubs f1, f0, f1
/* 80106E74 00103C74  4B FE E6 D5 */	bl kar_gryaku_set_path_node_motion
.L_80106E78:
/* 80106E78 00103C78  39 61 00 30 */	addi r11, r1, 0x30
/* 80106E7C 00103C7C  48 2A 6D 25 */	bl _restgpr_27
/* 80106E80 00103C80  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80106E84 00103C84  7C 08 03 A6 */	mtlr r0
/* 80106E88 00103C88  38 21 00 30 */	addi r1, r1, 0x30
/* 80106E8C 00103C8C  4E 80 00 20 */	blr
.endfn kar_gryakubreakfloor_advance_kind32_crack_or_break_sequence

# .text:0x634 | 0x80106E90 | size: 0x5C
.fn kar_gryakubreakfloor_update_kind59_bounce_wait_to_motion, global
/* 80106E90 00103C90  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80106E94 00103C94  7C 08 02 A6 */	mflr r0
/* 80106E98 00103C98  90 01 00 14 */	stw r0, 0x14(r1)
/* 80106E9C 00103C9C  80 A3 00 2C */	lwz r5, 0x2c(r3)
/* 80106EA0 00103CA0  80 85 01 58 */	lwz r4, 0x158(r5)
/* 80106EA4 00103CA4  38 04 FF FF */	subi r0, r4, 0x1
/* 80106EA8 00103CA8  90 05 01 58 */	stw r0, 0x158(r5)
/* 80106EAC 00103CAC  80 05 01 58 */	lwz r0, 0x158(r5)
/* 80106EB0 00103CB0  2C 00 00 00 */	cmpwi r0, 0x0
/* 80106EB4 00103CB4  41 81 00 28 */	bgt .L_80106EDC
/* 80106EB8 00103CB8  C0 22 93 58 */	lfs f1, lbl_805DFA58@sda21(r0)
/* 80106EBC 00103CBC  38 80 00 01 */	li r4, 0x1
/* 80106EC0 00103CC0  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80106EC4 00103CC4  38 A0 FF FF */	li r5, -0x1
/* 80106EC8 00103CC8  FC 40 08 90 */	fmr f2, f1
/* 80106ECC 00103CCC  38 C0 FF FF */	li r6, -0x1
/* 80106ED0 00103CD0  FC 60 08 90 */	fmr f3, f1
/* 80106ED4 00103CD4  38 E0 00 00 */	li r7, 0x0
/* 80106ED8 00103CD8  4B FE E6 71 */	bl kar_gryaku_set_path_node_motion
.L_80106EDC:
/* 80106EDC 00103CDC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80106EE0 00103CE0  7C 08 03 A6 */	mtlr r0
/* 80106EE4 00103CE4  38 21 00 10 */	addi r1, r1, 0x10
/* 80106EE8 00103CE8  4E 80 00 20 */	blr
.endfn kar_gryakubreakfloor_update_kind59_bounce_wait_to_motion

# .text:0x690 | 0x80106EEC | size: 0x234
.fn kar_gryakubreakfloor_update_kind59_bounce_between_endpoints, global
/* 80106EEC 00103CEC  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 80106EF0 00103CF0  7C 08 02 A6 */	mflr r0
/* 80106EF4 00103CF4  90 01 00 64 */	stw r0, 0x64(r1)
/* 80106EF8 00103CF8  38 81 00 44 */	addi r4, r1, 0x44
/* 80106EFC 00103CFC  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 80106F00 00103D00  93 C1 00 58 */	stw r30, 0x58(r1)
/* 80106F04 00103D04  7C 7E 1B 78 */	mr r30, r3
/* 80106F08 00103D08  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80106F0C 00103D0C  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 80106F10 00103D10  48 0F D0 9D */	bl kar_emupdate__near_80203fac
/* 80106F14 00103D14  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 80106F18 00103D18  38 81 00 2C */	addi r4, r1, 0x2c
/* 80106F1C 00103D1C  38 A1 00 20 */	addi r5, r1, 0x20
/* 80106F20 00103D20  48 0F D2 41 */	bl kar_emupdate__near_80204160
/* 80106F24 00103D24  C0 21 00 44 */	lfs f1, 0x44(r1)
/* 80106F28 00103D28  C0 1F 01 4C */	lfs f0, 0x14c(r31)
/* 80106F2C 00103D2C  C0 41 00 48 */	lfs f2, 0x48(r1)
/* 80106F30 00103D30  EC 01 00 2A */	fadds f0, f1, f0
/* 80106F34 00103D34  C0 21 00 4C */	lfs f1, 0x4c(r1)
/* 80106F38 00103D38  D0 01 00 44 */	stfs f0, 0x44(r1)
/* 80106F3C 00103D3C  C0 1F 01 50 */	lfs f0, 0x150(r31)
/* 80106F40 00103D40  EC 02 00 2A */	fadds f0, f2, f0
/* 80106F44 00103D44  D0 01 00 48 */	stfs f0, 0x48(r1)
/* 80106F48 00103D48  C0 1F 01 54 */	lfs f0, 0x154(r31)
/* 80106F4C 00103D4C  EC 01 00 2A */	fadds f0, f1, f0
/* 80106F50 00103D50  D0 01 00 4C */	stfs f0, 0x4c(r1)
/* 80106F54 00103D54  88 1F 01 5C */	lbz r0, 0x15c(r31)
/* 80106F58 00103D58  54 00 CF FF */	extrwi. r0, r0, 1, 24
/* 80106F5C 00103D5C  41 82 00 0C */	beq .L_80106F68
/* 80106F60 00103D60  38 9F 01 40 */	addi r4, r31, 0x140
/* 80106F64 00103D64  48 00 00 08 */	b .L_80106F6C
.L_80106F68:
/* 80106F68 00103D68  38 9F 01 34 */	addi r4, r31, 0x134
.L_80106F6C:
/* 80106F6C 00103D6C  80 64 00 00 */	lwz r3, 0x0(r4)
/* 80106F70 00103D70  80 04 00 04 */	lwz r0, 0x4(r4)
/* 80106F74 00103D74  C0 01 00 44 */	lfs f0, 0x44(r1)
/* 80106F78 00103D78  90 61 00 38 */	stw r3, 0x38(r1)
/* 80106F7C 00103D7C  C0 21 00 48 */	lfs f1, 0x48(r1)
/* 80106F80 00103D80  90 01 00 3C */	stw r0, 0x3c(r1)
/* 80106F84 00103D84  C0 41 00 38 */	lfs f2, 0x38(r1)
/* 80106F88 00103D88  80 04 00 08 */	lwz r0, 0x8(r4)
/* 80106F8C 00103D8C  EC 62 00 28 */	fsubs f3, f2, f0
/* 80106F90 00103D90  C0 41 00 3C */	lfs f2, 0x3c(r1)
/* 80106F94 00103D94  90 01 00 40 */	stw r0, 0x40(r1)
/* 80106F98 00103D98  C0 01 00 4C */	lfs f0, 0x4c(r1)
/* 80106F9C 00103D9C  EC 42 08 28 */	fsubs f2, f2, f1
/* 80106FA0 00103DA0  D0 61 00 14 */	stfs f3, 0x14(r1)
/* 80106FA4 00103DA4  C0 21 00 40 */	lfs f1, 0x40(r1)
/* 80106FA8 00103DA8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80106FAC 00103DAC  EC 01 00 28 */	fsubs f0, f1, f0
/* 80106FB0 00103DB0  D0 41 00 18 */	stfs f2, 0x18(r1)
/* 80106FB4 00103DB4  C0 22 93 5C */	lfs f1, lbl_805DFA5C@sda21(r0)
/* 80106FB8 00103DB8  90 01 00 08 */	stw r0, 0x8(r1)
/* 80106FBC 00103DBC  80 61 00 18 */	lwz r3, 0x18(r1)
/* 80106FC0 00103DC0  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 80106FC4 00103DC4  C0 41 00 08 */	lfs f2, 0x8(r1)
/* 80106FC8 00103DC8  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80106FCC 00103DCC  FC 02 08 40 */	fcmpo cr0, f2, f1
/* 80106FD0 00103DD0  90 61 00 0C */	stw r3, 0xc(r1)
/* 80106FD4 00103DD4  90 01 00 10 */	stw r0, 0x10(r1)
/* 80106FD8 00103DD8  4C 41 13 82 */	cror eq, gt, eq
/* 80106FDC 00103DDC  41 82 00 4C */	beq .L_80107028
/* 80106FE0 00103DE0  C0 02 93 60 */	lfs f0, lbl_805DFA60@sda21(r0)
/* 80106FE4 00103DE4  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80106FE8 00103DE8  4C 40 13 82 */	cror eq, lt, eq
/* 80106FEC 00103DEC  41 82 00 3C */	beq .L_80107028
/* 80106FF0 00103DF0  C0 41 00 0C */	lfs f2, 0xc(r1)
/* 80106FF4 00103DF4  FC 02 08 40 */	fcmpo cr0, f2, f1
/* 80106FF8 00103DF8  4C 41 13 82 */	cror eq, gt, eq
/* 80106FFC 00103DFC  41 82 00 2C */	beq .L_80107028
/* 80107000 00103E00  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80107004 00103E04  4C 40 13 82 */	cror eq, lt, eq
/* 80107008 00103E08  41 82 00 20 */	beq .L_80107028
/* 8010700C 00103E0C  C0 41 00 10 */	lfs f2, 0x10(r1)
/* 80107010 00103E10  FC 02 08 40 */	fcmpo cr0, f2, f1
/* 80107014 00103E14  4C 41 13 82 */	cror eq, gt, eq
/* 80107018 00103E18  41 82 00 10 */	beq .L_80107028
/* 8010701C 00103E1C  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80107020 00103E20  4C 40 13 82 */	cror eq, lt, eq
/* 80107024 00103E24  40 82 00 0C */	bne .L_80107030
.L_80107028:
/* 80107028 00103E28  38 00 00 00 */	li r0, 0x0
/* 8010702C 00103E2C  48 00 00 08 */	b .L_80107034
.L_80107030:
/* 80107030 00103E30  38 00 00 01 */	li r0, 0x1
.L_80107034:
/* 80107034 00103E34  2C 00 00 00 */	cmpwi r0, 0x0
/* 80107038 00103E38  40 82 00 38 */	bne .L_80107070
/* 8010703C 00103E3C  C0 3F 01 50 */	lfs f1, 0x150(r31)
/* 80107040 00103E40  C0 01 00 18 */	lfs f0, 0x18(r1)
/* 80107044 00103E44  C0 5F 01 4C */	lfs f2, 0x14c(r31)
/* 80107048 00103E48  EC 01 00 32 */	fmuls f0, f1, f0
/* 8010704C 00103E4C  C0 21 00 14 */	lfs f1, 0x14(r1)
/* 80107050 00103E50  C0 9F 01 54 */	lfs f4, 0x154(r31)
/* 80107054 00103E54  C0 61 00 1C */	lfs f3, 0x1c(r1)
/* 80107058 00103E58  EC 22 00 7A */	fmadds f1, f2, f1, f0
/* 8010705C 00103E5C  C0 02 93 58 */	lfs f0, lbl_805DFA58@sda21(r0)
/* 80107060 00103E60  EC 24 08 FA */	fmadds f1, f4, f3, f1
/* 80107064 00103E64  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80107068 00103E68  4C 40 13 82 */	cror eq, lt, eq
/* 8010706C 00103E6C  40 82 00 88 */	bne .L_801070F4
.L_80107070:
/* 80107070 00103E70  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 80107074 00103E74  38 81 00 38 */	addi r4, r1, 0x38
/* 80107078 00103E78  38 A1 00 20 */	addi r5, r1, 0x20
/* 8010707C 00103E7C  38 C1 00 2C */	addi r6, r1, 0x2c
/* 80107080 00103E80  48 0F D7 6D */	bl kar_emupdate__near_802047ec
/* 80107084 00103E84  80 7E 00 2C */	lwz r3, 0x2c(r30)
/* 80107088 00103E88  38 80 00 00 */	li r4, 0x0
/* 8010708C 00103E8C  C0 22 93 58 */	lfs f1, lbl_805DFA58@sda21(r0)
/* 80107090 00103E90  38 A0 FF FF */	li r5, -0x1
/* 80107094 00103E94  80 E3 00 08 */	lwz r7, 0x8(r3)
/* 80107098 00103E98  38 C0 FF FF */	li r6, -0x1
/* 8010709C 00103E9C  FC 40 08 90 */	fmr f2, f1
/* 801070A0 00103EA0  81 07 00 00 */	lwz r8, 0x0(r7)
/* 801070A4 00103EA4  FC 60 08 90 */	fmr f3, f1
/* 801070A8 00103EA8  38 E0 00 00 */	li r7, 0x0
/* 801070AC 00103EAC  80 08 00 14 */	lwz r0, 0x14(r8)
/* 801070B0 00103EB0  90 03 01 58 */	stw r0, 0x158(r3)
/* 801070B4 00103EB4  C0 03 01 4C */	lfs f0, 0x14c(r3)
/* 801070B8 00103EB8  FC 00 00 50 */	fneg f0, f0
/* 801070BC 00103EBC  D0 03 01 4C */	stfs f0, 0x14c(r3)
/* 801070C0 00103EC0  C0 03 01 50 */	lfs f0, 0x150(r3)
/* 801070C4 00103EC4  FC 00 00 50 */	fneg f0, f0
/* 801070C8 00103EC8  D0 03 01 50 */	stfs f0, 0x150(r3)
/* 801070CC 00103ECC  C0 03 01 54 */	lfs f0, 0x154(r3)
/* 801070D0 00103ED0  FC 00 00 50 */	fneg f0, f0
/* 801070D4 00103ED4  D0 03 01 54 */	stfs f0, 0x154(r3)
/* 801070D8 00103ED8  89 03 01 5C */	lbz r8, 0x15c(r3)
/* 801070DC 00103EDC  55 00 CF FE */	extrwi r0, r8, 1, 24
/* 801070E0 00103EE0  7C 00 00 34 */	cntlzw r0, r0
/* 801070E4 00103EE4  50 08 16 30 */	rlwimi r8, r0, 2, 24, 24
/* 801070E8 00103EE8  99 03 01 5C */	stb r8, 0x15c(r3)
/* 801070EC 00103EEC  4B FE E4 5D */	bl kar_gryaku_set_path_node_motion
/* 801070F0 00103EF0  48 00 00 18 */	b .L_80107108
.L_801070F4:
/* 801070F4 00103EF4  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 801070F8 00103EF8  38 81 00 44 */	addi r4, r1, 0x44
/* 801070FC 00103EFC  38 A1 00 20 */	addi r5, r1, 0x20
/* 80107100 00103F00  38 C1 00 2C */	addi r6, r1, 0x2c
/* 80107104 00103F04  48 0F D6 E9 */	bl kar_emupdate__near_802047ec
.L_80107108:
/* 80107108 00103F08  80 01 00 64 */	lwz r0, 0x64(r1)
/* 8010710C 00103F0C  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 80107110 00103F10  83 C1 00 58 */	lwz r30, 0x58(r1)
/* 80107114 00103F14  7C 08 03 A6 */	mtlr r0
/* 80107118 00103F18  38 21 00 60 */	addi r1, r1, 0x60
/* 8010711C 00103F1C  4E 80 00 20 */	blr
.endfn kar_gryakubreakfloor_update_kind59_bounce_between_endpoints

# .text:0x8C4 | 0x80107120 | size: 0x38
.fn kar_gryakubreakfloor_create_stage_linked_kind30_breakfan, global
/* 80107120 00103F20  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80107124 00103F24  7C 08 02 A6 */	mflr r0
/* 80107128 00103F28  90 01 00 14 */	stw r0, 0x14(r1)
/* 8010712C 00103F2C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80107130 00103F30  7C 7F 1B 78 */	mr r31, r3
/* 80107134 00103F34  38 60 00 1E */	li r3, 0x1e
/* 80107138 00103F38  4B FE D3 35 */	bl kar_gryaku_create_yaku_from_main_kind
/* 8010713C 00103F3C  7F E4 FB 78 */	mr r4, r31
/* 80107140 00103F40  48 00 00 19 */	bl kar_gryakubreakfloor_init_kind30_breakfan
/* 80107144 00103F44  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80107148 00103F48  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010714C 00103F4C  7C 08 03 A6 */	mtlr r0
/* 80107150 00103F50  38 21 00 10 */	addi r1, r1, 0x10
/* 80107154 00103F54  4E 80 00 20 */	blr
.endfn kar_gryakubreakfloor_create_stage_linked_kind30_breakfan

# .text:0x8FC | 0x80107158 | size: 0x74
.fn kar_gryakubreakfloor_init_kind30_breakfan, global
/* 80107158 00103F58  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8010715C 00103F5C  7C 08 02 A6 */	mflr r0
/* 80107160 00103F60  90 01 00 14 */	stw r0, 0x14(r1)
/* 80107164 00103F64  38 00 00 00 */	li r0, 0x0
/* 80107168 00103F68  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010716C 00103F6C  7C 7F 1B 78 */	mr r31, r3
/* 80107170 00103F70  80 A3 00 2C */	lwz r5, 0x2c(r3)
/* 80107174 00103F74  80 85 00 08 */	lwz r4, 0x8(r5)
/* 80107178 00103F78  80 C4 00 00 */	lwz r6, 0x0(r4)
/* 8010717C 00103F7C  90 05 01 34 */	stw r0, 0x134(r5)
/* 80107180 00103F80  90 05 01 30 */	stw r0, 0x130(r5)
/* 80107184 00103F84  90 05 01 3C */	stw r0, 0x13c(r5)
/* 80107188 00103F88  90 05 01 38 */	stw r0, 0x138(r5)
/* 8010718C 00103F8C  90 05 01 44 */	stw r0, 0x144(r5)
/* 80107190 00103F90  90 05 01 40 */	stw r0, 0x140(r5)
/* 80107194 00103F94  80 85 00 08 */	lwz r4, 0x8(r5)
/* 80107198 00103F98  80 04 00 14 */	lwz r0, 0x14(r4)
/* 8010719C 00103F9C  28 00 00 00 */	cmplwi r0, 0x0
/* 801071A0 00103FA0  41 82 00 10 */	beq .L_801071B0
/* 801071A4 00103FA4  80 86 00 04 */	lwz r4, 0x4(r6)
/* 801071A8 00103FA8  38 A0 00 00 */	li r5, 0x0
/* 801071AC 00103FAC  4B FF 06 C5 */	bl kar_gryakuaudio_configure_fgm_track_from_joint
.L_801071B0:
/* 801071B0 00103FB0  7F E3 FB 78 */	mr r3, r31
/* 801071B4 00103FB4  48 00 00 19 */	bl kar_gryakubreakfloor_start_kind30_breakfan_idle_and_event_callback
/* 801071B8 00103FB8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801071BC 00103FBC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801071C0 00103FC0  7C 08 03 A6 */	mtlr r0
/* 801071C4 00103FC4  38 21 00 10 */	addi r1, r1, 0x10
/* 801071C8 00103FC8  4E 80 00 20 */	blr
.endfn kar_gryakubreakfloor_init_kind30_breakfan

# .text:0x970 | 0x801071CC | size: 0x60
.fn kar_gryakubreakfloor_start_kind30_breakfan_idle_and_event_callback, global
/* 801071CC 00103FCC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801071D0 00103FD0  7C 08 02 A6 */	mflr r0
/* 801071D4 00103FD4  C0 22 93 68 */	lfs f1, lbl_805DFA68@sda21(r0)
/* 801071D8 00103FD8  38 80 00 00 */	li r4, 0x0
/* 801071DC 00103FDC  90 01 00 14 */	stw r0, 0x14(r1)
/* 801071E0 00103FE0  38 E0 00 00 */	li r7, 0x0
/* 801071E4 00103FE4  FC 60 08 90 */	fmr f3, f1
/* 801071E8 00103FE8  C0 42 93 6C */	lfs f2, lbl_805DFA6C@sda21(r0)
/* 801071EC 00103FEC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801071F0 00103FF0  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 801071F4 00103FF4  80 BF 00 08 */	lwz r5, 0x8(r31)
/* 801071F8 00103FF8  7F E3 FB 78 */	mr r3, r31
/* 801071FC 00103FFC  80 C5 00 00 */	lwz r6, 0x0(r5)
/* 80107200 00104000  80 A6 00 08 */	lwz r5, 0x8(r6)
/* 80107204 00104004  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 80107208 00104008  4B FE E3 41 */	bl kar_gryaku_set_path_node_motion
/* 8010720C 0010400C  3C 60 80 10 */	lis r3, kar_gryakubreakfan_trigger_kind30_break_effects_from_event@ha
/* 80107210 00104010  38 03 73 70 */	addi r0, r3, kar_gryakubreakfan_trigger_kind30_break_effects_from_event@l
/* 80107214 00104014  90 1F 01 04 */	stw r0, 0x104(r31)
/* 80107218 00104018  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8010721C 0010401C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80107220 00104020  7C 08 03 A6 */	mtlr r0
/* 80107224 00104024  38 21 00 10 */	addi r1, r1, 0x10
/* 80107228 00104028  4E 80 00 20 */	blr
.endfn kar_gryakubreakfloor_start_kind30_breakfan_idle_and_event_callback

# .text:0x9D0 | 0x8010722C | size: 0x40
.fn kar_gryakubreakfloor_configure_kind30_breakfan_fgm, global
/* 8010722C 0010402C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80107230 00104030  7C 08 02 A6 */	mflr r0
/* 80107234 00104034  90 01 00 14 */	stw r0, 0x14(r1)
/* 80107238 00104038  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 8010723C 0010403C  80 84 00 08 */	lwz r4, 0x8(r4)
/* 80107240 00104040  80 04 00 14 */	lwz r0, 0x14(r4)
/* 80107244 00104044  80 84 00 00 */	lwz r4, 0x0(r4)
/* 80107248 00104048  28 00 00 00 */	cmplwi r0, 0x0
/* 8010724C 0010404C  41 82 00 10 */	beq .L_8010725C
/* 80107250 00104050  80 84 00 04 */	lwz r4, 0x4(r4)
/* 80107254 00104054  38 A0 00 00 */	li r5, 0x0
/* 80107258 00104058  4B FF 06 19 */	bl kar_gryakuaudio_configure_fgm_track_from_joint
.L_8010725C:
/* 8010725C 0010405C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80107260 00104060  7C 08 03 A6 */	mtlr r0
/* 80107264 00104064  38 21 00 10 */	addi r1, r1, 0x10
/* 80107268 00104068  4E 80 00 20 */	blr
.endfn kar_gryakubreakfloor_configure_kind30_breakfan_fgm

# .text:0xA10 | 0x8010726C | size: 0x104
.fn kar_gryakubreakfloor_update_kind30_breakfan_effects_then_destroy, global
/* 8010726C 0010406C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80107270 00104070  7C 08 02 A6 */	mflr r0
/* 80107274 00104074  90 01 00 24 */	stw r0, 0x24(r1)
/* 80107278 00104078  39 61 00 20 */	addi r11, r1, 0x20
/* 8010727C 0010407C  48 2A 68 D5 */	bl _savegpr_26
/* 80107280 00104080  7C 7E 1B 78 */	mr r30, r3
/* 80107284 00104084  3B 40 00 00 */	li r26, 0x0
/* 80107288 00104088  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8010728C 0010408C  3B A0 00 00 */	li r29, 0x0
/* 80107290 00104090  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80107294 00104094  7F FC FB 78 */	mr r28, r31
/* 80107298 00104098  83 63 00 00 */	lwz r27, 0x0(r3)
/* 8010729C 0010409C  48 00 00 38 */	b .L_801072D4
.L_801072A0:
/* 801072A0 001040A0  80 7C 01 30 */	lwz r3, 0x130(r28)
/* 801072A4 001040A4  80 9C 01 34 */	lwz r4, 0x134(r28)
/* 801072A8 001040A8  7C 60 EA 78 */	xor r0, r3, r29
/* 801072AC 001040AC  7C 85 EA 78 */	xor r5, r4, r29
/* 801072B0 001040B0  7C A0 03 79 */	or. r0, r5, r0
/* 801072B4 001040B4  41 82 00 18 */	beq .L_801072CC
/* 801072B8 001040B8  4B FE FF D5 */	bl kar_gryakueffect_is_effect_key_active
/* 801072BC 001040BC  2C 03 00 00 */	cmpwi r3, 0x0
/* 801072C0 001040C0  40 82 00 0C */	bne .L_801072CC
/* 801072C4 001040C4  93 BC 01 34 */	stw r29, 0x134(r28)
/* 801072C8 001040C8  93 BC 01 30 */	stw r29, 0x130(r28)
.L_801072CC:
/* 801072CC 001040CC  3B 9C 00 08 */	addi r28, r28, 0x8
/* 801072D0 001040D0  3B 5A 00 01 */	addi r26, r26, 0x1
.L_801072D4:
/* 801072D4 001040D4  80 FB 00 18 */	lwz r7, 0x18(r27)
/* 801072D8 001040D8  7C 1A 38 00 */	cmpw r26, r7
/* 801072DC 001040DC  41 80 FF C4 */	blt .L_801072A0
/* 801072E0 001040E0  39 00 00 00 */	li r8, 0x0
/* 801072E4 001040E4  7F E6 FB 78 */	mr r6, r31
/* 801072E8 001040E8  7D 05 43 78 */	mr r5, r8
/* 801072EC 001040EC  7D 04 43 78 */	mr r4, r8
/* 801072F0 001040F0  7C E9 03 A6 */	mtctr r7
/* 801072F4 001040F4  2C 07 00 00 */	cmpwi r7, 0x0
/* 801072F8 001040F8  40 81 00 28 */	ble .L_80107320
.L_801072FC:
/* 801072FC 001040FC  80 06 01 30 */	lwz r0, 0x130(r6)
/* 80107300 00104100  80 66 01 34 */	lwz r3, 0x134(r6)
/* 80107304 00104104  7C 00 22 78 */	xor r0, r0, r4
/* 80107308 00104108  7C 63 2A 78 */	xor r3, r3, r5
/* 8010730C 0010410C  7C 60 03 79 */	or. r0, r3, r0
/* 80107310 00104110  40 82 00 10 */	bne .L_80107320
/* 80107314 00104114  38 C6 00 08 */	addi r6, r6, 0x8
/* 80107318 00104118  39 08 00 01 */	addi r8, r8, 0x1
/* 8010731C 0010411C  42 00 FF E0 */	bdnz .L_801072FC
.L_80107320:
/* 80107320 00104120  7C 08 38 00 */	cmpw r8, r7
/* 80107324 00104124  40 82 00 34 */	bne .L_80107358
/* 80107328 00104128  80 7F 01 18 */	lwz r3, 0x118(r31)
/* 8010732C 0010412C  28 03 00 00 */	cmplwi r3, 0x0
/* 80107330 00104130  41 82 00 20 */	beq .L_80107350
/* 80107334 00104134  88 03 00 04 */	lbz r0, 0x4(r3)
/* 80107338 00104138  54 00 C0 02 */	extlwi r0, r0, 2, 24
/* 8010733C 0010413C  7C 00 FE 70 */	srawi r0, r0, 31
/* 80107340 00104140  7C 00 07 75 */	extsb. r0, r0
/* 80107344 00104144  41 82 00 0C */	beq .L_80107350
/* 80107348 00104148  38 7F 01 18 */	addi r3, r31, 0x118
/* 8010734C 0010414C  4B FE 2E 35 */	bl kar_graudio_stop_active_fgm_slot
.L_80107350:
/* 80107350 00104150  7F C3 F3 78 */	mr r3, r30
/* 80107354 00104154  48 32 1C 11 */	bl HSD_GObjDestroy
.L_80107358:
/* 80107358 00104158  39 61 00 20 */	addi r11, r1, 0x20
/* 8010735C 0010415C  48 2A 68 41 */	bl _restgpr_26
/* 80107360 00104160  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80107364 00104164  7C 08 03 A6 */	mtlr r0
/* 80107368 00104168  38 21 00 20 */	addi r1, r1, 0x20
/* 8010736C 0010416C  4E 80 00 20 */	blr
.endfn kar_gryakubreakfloor_update_kind30_breakfan_effects_then_destroy
