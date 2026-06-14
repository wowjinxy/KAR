.include "macros.inc"
.file "gryakulighttunnel.c"

# 0x801006F4..0x80100FEC | size: 0x8F8
.text
.balign 4

# .text:0x0 | 0x801006F4 | size: 0x108
.fn kar_gryakulighttunnel_trigger_kind52_pillar_entry_motion, global
/* 801006F4 000FD4F4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801006F8 000FD4F8  7C 08 02 A6 */	mflr r0
/* 801006FC 000FD4FC  90 01 00 24 */	stw r0, 0x24(r1)
/* 80100700 000FD500  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80100704 000FD504  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80100708 000FD508  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8010070C 000FD50C  83 A3 00 2C */	lwz r29, 0x2c(r3)
/* 80100710 000FD510  80 1D 00 74 */	lwz r0, 0x74(r29)
/* 80100714 000FD514  80 7D 00 08 */	lwz r3, 0x8(r29)
/* 80100718 000FD518  2C 00 00 02 */	cmpwi r0, 0x2
/* 8010071C 000FD51C  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80100720 000FD520  41 82 00 20 */	beq .L_80100740
/* 80100724 000FD524  40 80 00 10 */	bge .L_80100734
/* 80100728 000FD528  2C 00 00 00 */	cmpwi r0, 0x0
/* 8010072C 000FD52C  41 82 00 24 */	beq .L_80100750
/* 80100730 000FD530  48 00 00 B0 */	b .L_801007E0
.L_80100734:
/* 80100734 000FD534  2C 00 00 04 */	cmpwi r0, 0x4
/* 80100738 000FD538  40 80 00 A8 */	bge .L_801007E0
/* 8010073C 000FD53C  48 00 00 14 */	b .L_80100750
.L_80100740:
/* 80100740 000FD540  80 63 00 20 */	lwz r3, 0x20(r3)
/* 80100744 000FD544  80 03 00 00 */	lwz r0, 0x0(r3)
/* 80100748 000FD548  90 1D 01 30 */	stw r0, 0x130(r29)
/* 8010074C 000FD54C  48 00 00 94 */	b .L_801007E0
.L_80100750:
/* 80100750 000FD550  80 1D 00 74 */	lwz r0, 0x74(r29)
/* 80100754 000FD554  80 7D 00 08 */	lwz r3, 0x8(r29)
/* 80100758 000FD558  2C 00 00 00 */	cmpwi r0, 0x0
/* 8010075C 000FD55C  80 8D 05 EC */	lwz r4, lbl_805DD6CC@sda21(r0)
/* 80100760 000FD560  83 E3 00 00 */	lwz r31, 0x0(r3)
/* 80100764 000FD564  40 82 00 0C */	bne .L_80100770
/* 80100768 000FD568  C0 22 92 38 */	lfs f1, lbl_805DF938@sda21(r0)
/* 8010076C 000FD56C  48 00 00 54 */	b .L_801007C0
.L_80100770:
/* 80100770 000FD570  80 1F 00 00 */	lwz r0, 0x0(r31)
/* 80100774 000FD574  80 64 01 04 */	lwz r3, 0x104(r4)
/* 80100778 000FD578  54 00 18 38 */	slwi r0, r0, 3
/* 8010077C 000FD57C  7C 63 00 2E */	lwzx r3, r3, r0
/* 80100780 000FD580  83 C3 00 7C */	lwz r30, 0x7c(r3)
/* 80100784 000FD584  28 1E 00 00 */	cmplwi r30, 0x0
/* 80100788 000FD588  40 82 00 18 */	bne .L_801007A0
/* 8010078C 000FD58C  3C 60 80 4A */	lis r3, kar_src_gryakulighttunnel_c@ha
/* 80100790 000FD590  38 80 00 8B */	li r4, 0x8b
/* 80100794 000FD594  38 63 66 2C */	addi r3, r3, kar_src_gryakulighttunnel_c@l
/* 80100798 000FD598  38 AD 91 B0 */	li r5, lbl_805D6290@sda21
/* 8010079C 000FD59C  48 32 7D 1D */	bl __assert
.L_801007A0:
/* 801007A0 000FD5A0  C0 5E 00 0C */	lfs f2, 0xc(r30)
/* 801007A4 000FD5A4  C0 1E 00 04 */	lfs f0, 0x4(r30)
/* 801007A8 000FD5A8  C0 22 92 38 */	lfs f1, lbl_805DF938@sda21(r0)
/* 801007AC 000FD5AC  EC 02 00 28 */	fsubs f0, f2, f0
/* 801007B0 000FD5B0  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 801007B4 000FD5B4  40 80 00 08 */	bge .L_801007BC
/* 801007B8 000FD5B8  48 00 00 08 */	b .L_801007C0
.L_801007BC:
/* 801007BC 000FD5BC  FC 20 00 90 */	fmr f1, f0
.L_801007C0:
/* 801007C0 000FD5C0  80 BF 00 04 */	lwz r5, 0x4(r31)
/* 801007C4 000FD5C4  7F A3 EB 78 */	mr r3, r29
/* 801007C8 000FD5C8  80 DF 00 00 */	lwz r6, 0x0(r31)
/* 801007CC 000FD5CC  38 80 00 01 */	li r4, 0x1
/* 801007D0 000FD5D0  C0 42 92 3C */	lfs f2, lbl_805DF93C@sda21(r0)
/* 801007D4 000FD5D4  38 E0 00 00 */	li r7, 0x0
/* 801007D8 000FD5D8  C0 62 92 38 */	lfs f3, lbl_805DF938@sda21(r0)
/* 801007DC 000FD5DC  4B FF 4D 6D */	bl kar_gryaku_set_path_node_motion
.L_801007E0:
/* 801007E0 000FD5E0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801007E4 000FD5E4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801007E8 000FD5E8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801007EC 000FD5EC  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 801007F0 000FD5F0  7C 08 03 A6 */	mtlr r0
/* 801007F4 000FD5F4  38 21 00 20 */	addi r1, r1, 0x20
/* 801007F8 000FD5F8  4E 80 00 20 */	blr
.endfn kar_gryakulighttunnel_trigger_kind52_pillar_entry_motion

# .text:0x108 | 0x801007FC | size: 0x38
.fn kar_gryakulighttunnel_create_stage_linked_kind52_pillar, global
/* 801007FC 000FD5FC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80100800 000FD600  7C 08 02 A6 */	mflr r0
/* 80100804 000FD604  90 01 00 14 */	stw r0, 0x14(r1)
/* 80100808 000FD608  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8010080C 000FD60C  7C 7F 1B 78 */	mr r31, r3
/* 80100810 000FD610  38 60 00 34 */	li r3, 0x34
/* 80100814 000FD614  4B FF 3C 59 */	bl kar_gryaku_create_yaku_from_main_kind
/* 80100818 000FD618  7F E4 FB 78 */	mr r4, r31
/* 8010081C 000FD61C  48 00 00 19 */	bl kar_gryakulighttunnel_init_stage_linked_kind52_pillar
/* 80100820 000FD620  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80100824 000FD624  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80100828 000FD628  7C 08 03 A6 */	mtlr r0
/* 8010082C 000FD62C  38 21 00 10 */	addi r1, r1, 0x10
/* 80100830 000FD630  4E 80 00 20 */	blr
.endfn kar_gryakulighttunnel_create_stage_linked_kind52_pillar

# .text:0x140 | 0x80100834 | size: 0x130
.fn kar_gryakulighttunnel_init_stage_linked_kind52_pillar, global
/* 80100834 000FD634  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80100838 000FD638  7C 08 02 A6 */	mflr r0
/* 8010083C 000FD63C  90 01 00 24 */	stw r0, 0x24(r1)
/* 80100840 000FD640  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80100844 000FD644  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80100848 000FD648  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8010084C 000FD64C  7C 7D 1B 78 */	mr r29, r3
/* 80100850 000FD650  93 81 00 10 */	stw r28, 0x10(r1)
/* 80100854 000FD654  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80100858 000FD658  83 84 00 2C */	lwz r28, 0x2c(r4)
/* 8010085C 000FD65C  80 BF 00 08 */	lwz r5, 0x8(r31)
/* 80100860 000FD660  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 80100864 000FD664  83 C5 00 00 */	lwz r30, 0x0(r5)
/* 80100868 000FD668  80 9C 01 04 */	lwz r4, 0x104(r28)
/* 8010086C 000FD66C  38 63 00 54 */	addi r3, r3, 0x54
/* 80100870 000FD670  80 1E 00 04 */	lwz r0, 0x4(r30)
/* 80100874 000FD674  54 00 18 38 */	slwi r0, r0, 3
/* 80100878 000FD678  7C 84 00 2E */	lwzx r4, r4, r0
/* 8010087C 000FD67C  4B FD 70 D9 */	bl kar_grcoll__800d7954
/* 80100880 000FD680  90 7F 01 30 */	stw r3, 0x130(r31)
/* 80100884 000FD684  80 1E 00 08 */	lwz r0, 0x8(r30)
/* 80100888 000FD688  80 7C 01 04 */	lwz r3, 0x104(r28)
/* 8010088C 000FD68C  54 00 18 38 */	slwi r0, r0, 3
/* 80100890 000FD690  7C 03 00 2E */	lwzx r0, r3, r0
/* 80100894 000FD694  90 1F 01 34 */	stw r0, 0x134(r31)
/* 80100898 000FD698  83 9F 01 34 */	lwz r28, 0x134(r31)
/* 8010089C 000FD69C  28 1C 00 00 */	cmplwi r28, 0x0
/* 801008A0 000FD6A0  40 82 00 14 */	bne .L_801008B4
/* 801008A4 000FD6A4  38 6D 91 C0 */	li r3, kar_srcfile_jobj_h_805d62a0@sda21
/* 801008A8 000FD6A8  38 80 03 FD */	li r4, 0x3fd
/* 801008AC 000FD6AC  38 AD 91 C8 */	li r5, lbl_805D62A8@sda21
/* 801008B0 000FD6B0  48 32 7C 09 */	bl __assert
.L_801008B4:
/* 801008B4 000FD6B4  C0 1C 00 3C */	lfs f0, 0x3c(r28)
/* 801008B8 000FD6B8  3C 00 43 30 */	lis r0, 0x4330
/* 801008BC 000FD6BC  90 01 00 08 */	stw r0, 0x8(r1)
/* 801008C0 000FD6C0  38 80 00 00 */	li r4, 0x0
/* 801008C4 000FD6C4  C8 22 92 40 */	lfd f1, lbl_805DF940@sda21(r0)
/* 801008C8 000FD6C8  38 60 00 01 */	li r3, 0x1
/* 801008CC 000FD6CC  D0 1F 01 44 */	stfs f0, 0x144(r31)
/* 801008D0 000FD6D0  80 1E 00 18 */	lwz r0, 0x18(r30)
/* 801008D4 000FD6D4  C0 5E 00 14 */	lfs f2, 0x14(r30)
/* 801008D8 000FD6D8  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 801008DC 000FD6DC  90 01 00 0C */	stw r0, 0xc(r1)
/* 801008E0 000FD6E0  C8 01 00 08 */	lfd f0, 0x8(r1)
/* 801008E4 000FD6E4  EC 00 08 28 */	fsubs f0, f0, f1
/* 801008E8 000FD6E8  EC 02 00 24 */	fdivs f0, f2, f0
/* 801008EC 000FD6EC  D0 1F 01 40 */	stfs f0, 0x140(r31)
/* 801008F0 000FD6F0  90 9F 01 38 */	stw r4, 0x138(r31)
/* 801008F4 000FD6F4  90 9F 01 3C */	stw r4, 0x13c(r31)
/* 801008F8 000FD6F8  88 1F 01 48 */	lbz r0, 0x148(r31)
/* 801008FC 000FD6FC  50 80 3E 30 */	rlwimi r0, r4, 7, 24, 24
/* 80100900 000FD700  98 1F 01 48 */	stb r0, 0x148(r31)
/* 80100904 000FD704  88 1F 01 48 */	lbz r0, 0x148(r31)
/* 80100908 000FD708  50 60 36 72 */	rlwimi r0, r3, 6, 25, 25
/* 8010090C 000FD70C  98 1F 01 48 */	stb r0, 0x148(r31)
/* 80100910 000FD710  88 1F 01 48 */	lbz r0, 0x148(r31)
/* 80100914 000FD714  50 60 2E B4 */	rlwimi r0, r3, 5, 26, 26
/* 80100918 000FD718  98 1F 01 48 */	stb r0, 0x148(r31)
/* 8010091C 000FD71C  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80100920 000FD720  80 03 00 14 */	lwz r0, 0x14(r3)
/* 80100924 000FD724  28 00 00 00 */	cmplwi r0, 0x0
/* 80100928 000FD728  41 82 00 14 */	beq .L_8010093C
/* 8010092C 000FD72C  80 9E 00 00 */	lwz r4, 0x0(r30)
/* 80100930 000FD730  7F A3 EB 78 */	mr r3, r29
/* 80100934 000FD734  38 A0 00 00 */	li r5, 0x0
/* 80100938 000FD738  4B FF 6F 39 */	bl kar_gryakuaudio_configure_fgm_track_from_joint
.L_8010093C:
/* 8010093C 000FD73C  7F A3 EB 78 */	mr r3, r29
/* 80100940 000FD740  48 00 00 25 */	bl kar_gryakulighttunnel_start_kind52_pillar_idle_motion
/* 80100944 000FD744  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80100948 000FD748  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8010094C 000FD74C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80100950 000FD750  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80100954 000FD754  83 81 00 10 */	lwz r28, 0x10(r1)
/* 80100958 000FD758  7C 08 03 A6 */	mtlr r0
/* 8010095C 000FD75C  38 21 00 20 */	addi r1, r1, 0x20
/* 80100960 000FD760  4E 80 00 20 */	blr
.endfn kar_gryakulighttunnel_init_stage_linked_kind52_pillar

# .text:0x270 | 0x80100964 | size: 0x11C
.fn kar_gryakulighttunnel_start_kind52_pillar_idle_motion, global
/* 80100964 000FD764  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80100968 000FD768  7C 08 02 A6 */	mflr r0
/* 8010096C 000FD76C  90 01 00 34 */	stw r0, 0x34(r1)
/* 80100970 000FD770  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 80100974 000FD774  F3 E1 00 28 */	psq_st f31, 0x28(r1), 0, qr0
/* 80100978 000FD778  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8010097C 000FD77C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80100980 000FD780  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80100984 000FD784  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 80100988 000FD788  88 7E 01 48 */	lbz r3, 0x148(r30)
/* 8010098C 000FD78C  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 80100990 000FD790  54 60 DF FF */	extrwi. r0, r3, 1, 26
/* 80100994 000FD794  83 A4 00 00 */	lwz r29, 0x0(r4)
/* 80100998 000FD798  41 82 00 90 */	beq .L_80100A28
/* 8010099C 000FD79C  38 00 00 00 */	li r0, 0x0
/* 801009A0 000FD7A0  50 03 2E B4 */	rlwimi r3, r0, 5, 26, 26
/* 801009A4 000FD7A4  98 7E 01 48 */	stb r3, 0x148(r30)
/* 801009A8 000FD7A8  83 FE 01 34 */	lwz r31, 0x134(r30)
/* 801009AC 000FD7AC  C0 3E 01 44 */	lfs f1, 0x144(r30)
/* 801009B0 000FD7B0  C0 1D 00 14 */	lfs f0, 0x14(r29)
/* 801009B4 000FD7B4  28 1F 00 00 */	cmplwi r31, 0x0
/* 801009B8 000FD7B8  EF E1 00 28 */	fsubs f31, f1, f0
/* 801009BC 000FD7BC  40 82 00 14 */	bne .L_801009D0
/* 801009C0 000FD7C0  38 6D 91 C0 */	li r3, kar_srcfile_jobj_h_805d62a0@sda21
/* 801009C4 000FD7C4  38 80 03 C6 */	li r4, 0x3c6
/* 801009C8 000FD7C8  38 AD 91 C8 */	li r5, lbl_805D62A8@sda21
/* 801009CC 000FD7CC  48 32 7A ED */	bl __assert
.L_801009D0:
/* 801009D0 000FD7D0  D3 FF 00 3C */	stfs f31, 0x3c(r31)
/* 801009D4 000FD7D4  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 801009D8 000FD7D8  54 00 01 8D */	rlwinm. r0, r0, 0, 6, 6
/* 801009DC 000FD7DC  40 82 00 4C */	bne .L_80100A28
/* 801009E0 000FD7E0  28 1F 00 00 */	cmplwi r31, 0x0
/* 801009E4 000FD7E4  41 82 00 44 */	beq .L_80100A28
/* 801009E8 000FD7E8  40 82 00 14 */	bne .L_801009FC
/* 801009EC 000FD7EC  38 6D 91 C0 */	li r3, kar_srcfile_jobj_h_805d62a0@sda21
/* 801009F0 000FD7F0  38 80 02 5D */	li r4, 0x25d
/* 801009F4 000FD7F4  38 AD 91 C8 */	li r5, lbl_805D62A8@sda21
/* 801009F8 000FD7F8  48 32 7A C1 */	bl __assert
.L_801009FC:
/* 801009FC 000FD7FC  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 80100A00 000FD800  38 60 00 00 */	li r3, 0x0
/* 80100A04 000FD804  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 80100A08 000FD808  40 82 00 10 */	bne .L_80100A18
/* 80100A0C 000FD80C  54 80 06 73 */	rlwinm. r0, r4, 0, 25, 25
/* 80100A10 000FD810  41 82 00 08 */	beq .L_80100A18
/* 80100A14 000FD814  38 60 00 01 */	li r3, 0x1
.L_80100A18:
/* 80100A18 000FD818  2C 03 00 00 */	cmpwi r3, 0x0
/* 80100A1C 000FD81C  40 82 00 0C */	bne .L_80100A28
/* 80100A20 000FD820  7F E3 FB 78 */	mr r3, r31
/* 80100A24 000FD824  48 30 CF 09 */	bl HSD_JObjSetMtxDirtySub
.L_80100A28:
/* 80100A28 000FD828  88 1E 01 48 */	lbz r0, 0x148(r30)
/* 80100A2C 000FD82C  38 60 00 00 */	li r3, 0x0
/* 80100A30 000FD830  C0 22 92 48 */	lfs f1, lbl_805DF948@sda21(r0)
/* 80100A34 000FD834  50 60 3E 30 */	rlwimi r0, r3, 7, 24, 24
/* 80100A38 000FD838  98 1E 01 48 */	stb r0, 0x148(r30)
/* 80100A3C 000FD83C  7F C3 F3 78 */	mr r3, r30
/* 80100A40 000FD840  FC 40 08 90 */	fmr f2, f1
/* 80100A44 000FD844  38 80 00 00 */	li r4, 0x0
/* 80100A48 000FD848  FC 60 08 90 */	fmr f3, f1
/* 80100A4C 000FD84C  80 DD 00 00 */	lwz r6, 0x0(r29)
/* 80100A50 000FD850  38 A0 FF FF */	li r5, -0x1
/* 80100A54 000FD854  38 E0 00 00 */	li r7, 0x0
/* 80100A58 000FD858  4B FF 4A F1 */	bl kar_gryaku_set_path_node_motion
/* 80100A5C 000FD85C  E3 E1 00 28 */	psq_l f31, 0x28(r1), 0, qr0
/* 80100A60 000FD860  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80100A64 000FD864  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 80100A68 000FD868  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80100A6C 000FD86C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80100A70 000FD870  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80100A74 000FD874  7C 08 03 A6 */	mtlr r0
/* 80100A78 000FD878  38 21 00 30 */	addi r1, r1, 0x30
/* 80100A7C 000FD87C  4E 80 00 20 */	blr
.endfn kar_gryakulighttunnel_start_kind52_pillar_idle_motion

# .text:0x38C | 0x80100A80 | size: 0x78
.fn kar_gryakulighttunnel_update_kind52_pillar_delay_to_motion, global
/* 80100A80 000FD880  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80100A84 000FD884  7C 08 02 A6 */	mflr r0
/* 80100A88 000FD888  90 01 00 14 */	stw r0, 0x14(r1)
/* 80100A8C 000FD88C  80 A3 00 2C */	lwz r5, 0x2c(r3)
/* 80100A90 000FD890  88 05 01 48 */	lbz r0, 0x148(r5)
/* 80100A94 000FD894  54 00 CF FF */	extrwi. r0, r0, 1, 24
/* 80100A98 000FD898  41 82 00 50 */	beq .L_80100AE8
/* 80100A9C 000FD89C  80 85 01 3C */	lwz r4, 0x13c(r5)
/* 80100AA0 000FD8A0  38 04 FF FF */	subi r0, r4, 0x1
/* 80100AA4 000FD8A4  90 05 01 3C */	stw r0, 0x13c(r5)
/* 80100AA8 000FD8A8  80 05 01 3C */	lwz r0, 0x13c(r5)
/* 80100AAC 000FD8AC  2C 00 00 00 */	cmpwi r0, 0x0
/* 80100AB0 000FD8B0  41 81 00 38 */	bgt .L_80100AE8
/* 80100AB4 000FD8B4  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80100AB8 000FD8B8  38 80 00 01 */	li r4, 0x1
/* 80100ABC 000FD8BC  C0 22 92 48 */	lfs f1, lbl_805DF948@sda21(r0)
/* 80100AC0 000FD8C0  38 E0 00 00 */	li r7, 0x0
/* 80100AC4 000FD8C4  80 A3 00 08 */	lwz r5, 0x8(r3)
/* 80100AC8 000FD8C8  FC 60 08 90 */	fmr f3, f1
/* 80100ACC 000FD8CC  C0 42 92 4C */	lfs f2, lbl_805DF94C@sda21(r0)
/* 80100AD0 000FD8D0  80 C5 00 00 */	lwz r6, 0x0(r5)
/* 80100AD4 000FD8D4  80 06 00 1C */	lwz r0, 0x1c(r6)
/* 80100AD8 000FD8D8  90 03 01 38 */	stw r0, 0x138(r3)
/* 80100ADC 000FD8DC  80 A6 00 0C */	lwz r5, 0xc(r6)
/* 80100AE0 000FD8E0  80 C6 00 00 */	lwz r6, 0x0(r6)
/* 80100AE4 000FD8E4  4B FF 4A 65 */	bl kar_gryaku_set_path_node_motion
.L_80100AE8:
/* 80100AE8 000FD8E8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80100AEC 000FD8EC  7C 08 03 A6 */	mtlr r0
/* 80100AF0 000FD8F0  38 21 00 10 */	addi r1, r1, 0x10
/* 80100AF4 000FD8F4  4E 80 00 20 */	blr
.endfn kar_gryakulighttunnel_update_kind52_pillar_delay_to_motion

# .text:0x404 | 0x80100AF8 | size: 0xF0
.fn kar_gryakulighttunnel_update_kind52_pillar_ground_clear_motion, global
/* 80100AF8 000FD8F8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80100AFC 000FD8FC  7C 08 02 A6 */	mflr r0
/* 80100B00 000FD900  90 01 00 14 */	stw r0, 0x14(r1)
/* 80100B04 000FD904  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80100B08 000FD908  7C 7F 1B 78 */	mr r31, r3
/* 80100B0C 000FD90C  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80100B10 000FD910  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 80100B14 000FD914  83 DF 00 2C */	lwz r30, 0x2c(r31)
/* 80100B18 000FD918  80 83 01 04 */	lwz r4, 0x104(r3)
/* 80100B1C 000FD91C  80 7E 00 08 */	lwz r3, 0x8(r30)
/* 80100B20 000FD920  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80100B24 000FD924  80 03 00 00 */	lwz r0, 0x0(r3)
/* 80100B28 000FD928  54 00 18 38 */	slwi r0, r0, 3
/* 80100B2C 000FD92C  7C 64 00 2E */	lwzx r3, r4, r0
/* 80100B30 000FD930  4B F5 3C B1 */	bl kar_gmlanmenu__near_800547e0
/* 80100B34 000FD934  2C 03 00 00 */	cmpwi r3, 0x0
/* 80100B38 000FD938  40 82 00 58 */	bne .L_80100B90
/* 80100B3C 000FD93C  83 DF 00 2C */	lwz r30, 0x2c(r31)
/* 80100B40 000FD940  38 00 00 00 */	li r0, 0x0
/* 80100B44 000FD944  80 7E 00 08 */	lwz r3, 0x8(r30)
/* 80100B48 000FD948  83 E3 00 00 */	lwz r31, 0x0(r3)
/* 80100B4C 000FD94C  90 1E 01 38 */	stw r0, 0x138(r30)
/* 80100B50 000FD950  80 1E 01 1C */	lwz r0, 0x11c(r30)
/* 80100B54 000FD954  2C 00 00 00 */	cmpwi r0, 0x0
/* 80100B58 000FD958  40 81 00 10 */	ble .L_80100B68
/* 80100B5C 000FD95C  38 7E 01 18 */	addi r3, r30, 0x118
/* 80100B60 000FD960  38 80 00 00 */	li r4, 0x0
/* 80100B64 000FD964  4B FE 95 21 */	bl kar_graudio_play_fgm_entry_id
.L_80100B68:
/* 80100B68 000FD968  C0 22 92 48 */	lfs f1, lbl_805DF948@sda21(r0)
/* 80100B6C 000FD96C  7F C3 F3 78 */	mr r3, r30
/* 80100B70 000FD970  80 DF 00 00 */	lwz r6, 0x0(r31)
/* 80100B74 000FD974  38 80 00 02 */	li r4, 0x2
/* 80100B78 000FD978  FC 40 08 90 */	fmr f2, f1
/* 80100B7C 000FD97C  38 A0 FF FF */	li r5, -0x1
/* 80100B80 000FD980  FC 60 08 90 */	fmr f3, f1
/* 80100B84 000FD984  38 E0 00 00 */	li r7, 0x0
/* 80100B88 000FD988  4B FF 49 C1 */	bl kar_gryaku_set_path_node_motion
/* 80100B8C 000FD98C  48 00 00 44 */	b .L_80100BD0
.L_80100B90:
/* 80100B90 000FD990  80 7E 01 38 */	lwz r3, 0x138(r30)
/* 80100B94 000FD994  38 03 FF FF */	subi r0, r3, 0x1
/* 80100B98 000FD998  90 1E 01 38 */	stw r0, 0x138(r30)
/* 80100B9C 000FD99C  88 7E 01 48 */	lbz r3, 0x148(r30)
/* 80100BA0 000FD9A0  54 60 D7 FF */	extrwi. r0, r3, 1, 25
/* 80100BA4 000FD9A4  41 82 00 2C */	beq .L_80100BD0
/* 80100BA8 000FD9A8  80 1E 01 38 */	lwz r0, 0x138(r30)
/* 80100BAC 000FD9AC  2C 00 00 00 */	cmpwi r0, 0x0
/* 80100BB0 000FD9B0  41 81 00 20 */	bgt .L_80100BD0
/* 80100BB4 000FD9B4  38 00 00 00 */	li r0, 0x0
/* 80100BB8 000FD9B8  50 03 36 72 */	rlwimi r3, r0, 6, 25, 25
/* 80100BBC 000FD9BC  98 7E 01 48 */	stb r3, 0x148(r30)
/* 80100BC0 000FD9C0  88 1E 01 48 */	lbz r0, 0x148(r30)
/* 80100BC4 000FD9C4  80 7E 01 30 */	lwz r3, 0x130(r30)
/* 80100BC8 000FD9C8  54 04 D7 FE */	extrwi r4, r0, 1, 25
/* 80100BCC 000FD9CC  4B FD 6F 05 */	bl kar_grcoll__near_800d7ad0
.L_80100BD0:
/* 80100BD0 000FD9D0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80100BD4 000FD9D4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80100BD8 000FD9D8  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80100BDC 000FD9DC  7C 08 03 A6 */	mtlr r0
/* 80100BE0 000FD9E0  38 21 00 10 */	addi r1, r1, 0x10
/* 80100BE4 000FD9E4  4E 80 00 20 */	blr
.endfn kar_gryakulighttunnel_update_kind52_pillar_ground_clear_motion

# .text:0x4F4 | 0x80100BE8 | size: 0x280
.fn kar_gryakulighttunnel_update_kind52_pillar_progress_motion, global
/* 80100BE8 000FD9E8  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80100BEC 000FD9EC  7C 08 02 A6 */	mflr r0
/* 80100BF0 000FD9F0  90 01 00 34 */	stw r0, 0x34(r1)
/* 80100BF4 000FD9F4  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 80100BF8 000FD9F8  F3 E1 00 28 */	psq_st f31, 0x28(r1), 0, qr0
/* 80100BFC 000FD9FC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80100C00 000FDA00  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80100C04 000FDA04  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80100C08 000FDA08  93 81 00 10 */	stw r28, 0x10(r1)
/* 80100C0C 000FDA0C  7C 7D 1B 78 */	mr r29, r3
/* 80100C10 000FDA10  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80100C14 000FDA14  80 9F 00 08 */	lwz r4, 0x8(r31)
/* 80100C18 000FDA18  80 7F 01 38 */	lwz r3, 0x138(r31)
/* 80100C1C 000FDA1C  83 C4 00 00 */	lwz r30, 0x0(r4)
/* 80100C20 000FDA20  38 03 00 01 */	addi r0, r3, 0x1
/* 80100C24 000FDA24  90 1F 01 38 */	stw r0, 0x138(r31)
/* 80100C28 000FDA28  80 7F 01 38 */	lwz r3, 0x138(r31)
/* 80100C2C 000FDA2C  80 1E 00 18 */	lwz r0, 0x18(r30)
/* 80100C30 000FDA30  7C 03 00 00 */	cmpw r3, r0
/* 80100C34 000FDA34  41 81 00 88 */	bgt .L_80100CBC
/* 80100C38 000FDA38  83 9F 01 34 */	lwz r28, 0x134(r31)
/* 80100C3C 000FDA3C  C3 FF 01 40 */	lfs f31, 0x140(r31)
/* 80100C40 000FDA40  28 1C 00 00 */	cmplwi r28, 0x0
/* 80100C44 000FDA44  40 82 00 14 */	bne .L_80100C58
/* 80100C48 000FDA48  38 6D 91 C0 */	li r3, kar_srcfile_jobj_h_805d62a0@sda21
/* 80100C4C 000FDA4C  38 80 04 60 */	li r4, 0x460
/* 80100C50 000FDA50  38 AD 91 C8 */	li r5, lbl_805D62A8@sda21
/* 80100C54 000FDA54  48 32 78 65 */	bl __assert
.L_80100C58:
/* 80100C58 000FDA58  C0 1C 00 3C */	lfs f0, 0x3c(r28)
/* 80100C5C 000FDA5C  EC 00 F8 2A */	fadds f0, f0, f31
/* 80100C60 000FDA60  D0 1C 00 3C */	stfs f0, 0x3c(r28)
/* 80100C64 000FDA64  80 1C 00 14 */	lwz r0, 0x14(r28)
/* 80100C68 000FDA68  54 00 01 8D */	rlwinm. r0, r0, 0, 6, 6
/* 80100C6C 000FDA6C  40 82 00 E4 */	bne .L_80100D50
/* 80100C70 000FDA70  28 1C 00 00 */	cmplwi r28, 0x0
/* 80100C74 000FDA74  41 82 00 DC */	beq .L_80100D50
/* 80100C78 000FDA78  40 82 00 14 */	bne .L_80100C8C
/* 80100C7C 000FDA7C  38 6D 91 C0 */	li r3, kar_srcfile_jobj_h_805d62a0@sda21
/* 80100C80 000FDA80  38 80 02 5D */	li r4, 0x25d
/* 80100C84 000FDA84  38 AD 91 C8 */	li r5, lbl_805D62A8@sda21
/* 80100C88 000FDA88  48 32 78 31 */	bl __assert
.L_80100C8C:
/* 80100C8C 000FDA8C  80 9C 00 14 */	lwz r4, 0x14(r28)
/* 80100C90 000FDA90  38 60 00 00 */	li r3, 0x0
/* 80100C94 000FDA94  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 80100C98 000FDA98  40 82 00 10 */	bne .L_80100CA8
/* 80100C9C 000FDA9C  54 80 06 73 */	rlwinm. r0, r4, 0, 25, 25
/* 80100CA0 000FDAA0  41 82 00 08 */	beq .L_80100CA8
/* 80100CA4 000FDAA4  38 60 00 01 */	li r3, 0x1
.L_80100CA8:
/* 80100CA8 000FDAA8  2C 03 00 00 */	cmpwi r3, 0x0
/* 80100CAC 000FDAAC  40 82 00 A4 */	bne .L_80100D50
/* 80100CB0 000FDAB0  7F 83 E3 78 */	mr r3, r28
/* 80100CB4 000FDAB4  48 30 CC 79 */	bl HSD_JObjSetMtxDirtySub
/* 80100CB8 000FDAB8  48 00 00 98 */	b .L_80100D50
.L_80100CBC:
/* 80100CBC 000FDABC  88 1F 01 48 */	lbz r0, 0x148(r31)
/* 80100CC0 000FDAC0  54 00 DF FF */	extrwi. r0, r0, 1, 26
/* 80100CC4 000FDAC4  40 82 00 8C */	bne .L_80100D50
/* 80100CC8 000FDAC8  83 9F 01 34 */	lwz r28, 0x134(r31)
/* 80100CCC 000FDACC  C3 FF 01 44 */	lfs f31, 0x144(r31)
/* 80100CD0 000FDAD0  28 1C 00 00 */	cmplwi r28, 0x0
/* 80100CD4 000FDAD4  40 82 00 14 */	bne .L_80100CE8
/* 80100CD8 000FDAD8  38 6D 91 C0 */	li r3, kar_srcfile_jobj_h_805d62a0@sda21
/* 80100CDC 000FDADC  38 80 03 C6 */	li r4, 0x3c6
/* 80100CE0 000FDAE0  38 AD 91 C8 */	li r5, lbl_805D62A8@sda21
/* 80100CE4 000FDAE4  48 32 77 D5 */	bl __assert
.L_80100CE8:
/* 80100CE8 000FDAE8  D3 FC 00 3C */	stfs f31, 0x3c(r28)
/* 80100CEC 000FDAEC  80 1C 00 14 */	lwz r0, 0x14(r28)
/* 80100CF0 000FDAF0  54 00 01 8D */	rlwinm. r0, r0, 0, 6, 6
/* 80100CF4 000FDAF4  40 82 00 4C */	bne .L_80100D40
/* 80100CF8 000FDAF8  28 1C 00 00 */	cmplwi r28, 0x0
/* 80100CFC 000FDAFC  41 82 00 44 */	beq .L_80100D40
/* 80100D00 000FDB00  40 82 00 14 */	bne .L_80100D14
/* 80100D04 000FDB04  38 6D 91 C0 */	li r3, kar_srcfile_jobj_h_805d62a0@sda21
/* 80100D08 000FDB08  38 80 02 5D */	li r4, 0x25d
/* 80100D0C 000FDB0C  38 AD 91 C8 */	li r5, lbl_805D62A8@sda21
/* 80100D10 000FDB10  48 32 77 A9 */	bl __assert
.L_80100D14:
/* 80100D14 000FDB14  80 9C 00 14 */	lwz r4, 0x14(r28)
/* 80100D18 000FDB18  38 60 00 00 */	li r3, 0x0
/* 80100D1C 000FDB1C  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 80100D20 000FDB20  40 82 00 10 */	bne .L_80100D30
/* 80100D24 000FDB24  54 80 06 73 */	rlwinm. r0, r4, 0, 25, 25
/* 80100D28 000FDB28  41 82 00 08 */	beq .L_80100D30
/* 80100D2C 000FDB2C  38 60 00 01 */	li r3, 0x1
.L_80100D30:
/* 80100D30 000FDB30  2C 03 00 00 */	cmpwi r3, 0x0
/* 80100D34 000FDB34  40 82 00 0C */	bne .L_80100D40
/* 80100D38 000FDB38  7F 83 E3 78 */	mr r3, r28
/* 80100D3C 000FDB3C  48 30 CB F1 */	bl HSD_JObjSetMtxDirtySub
.L_80100D40:
/* 80100D40 000FDB40  88 1F 01 48 */	lbz r0, 0x148(r31)
/* 80100D44 000FDB44  38 60 00 01 */	li r3, 0x1
/* 80100D48 000FDB48  50 60 2E B4 */	rlwimi r0, r3, 5, 26, 26
/* 80100D4C 000FDB4C  98 1F 01 48 */	stb r0, 0x148(r31)
.L_80100D50:
/* 80100D50 000FDB50  80 7F 01 38 */	lwz r3, 0x138(r31)
/* 80100D54 000FDB54  80 1E 00 20 */	lwz r0, 0x20(r30)
/* 80100D58 000FDB58  7C 03 00 00 */	cmpw r3, r0
/* 80100D5C 000FDB5C  41 80 00 E4 */	blt .L_80100E40
/* 80100D60 000FDB60  83 BD 00 2C */	lwz r29, 0x2c(r29)
/* 80100D64 000FDB64  38 60 00 01 */	li r3, 0x1
/* 80100D68 000FDB68  80 9D 00 08 */	lwz r4, 0x8(r29)
/* 80100D6C 000FDB6C  88 1D 01 48 */	lbz r0, 0x148(r29)
/* 80100D70 000FDB70  50 60 36 72 */	rlwimi r0, r3, 6, 25, 25
/* 80100D74 000FDB74  83 84 00 00 */	lwz r28, 0x0(r4)
/* 80100D78 000FDB78  98 1D 01 48 */	stb r0, 0x148(r29)
/* 80100D7C 000FDB7C  88 1D 01 48 */	lbz r0, 0x148(r29)
/* 80100D80 000FDB80  80 7D 01 30 */	lwz r3, 0x130(r29)
/* 80100D84 000FDB84  54 04 D7 FE */	extrwi r4, r0, 1, 25
/* 80100D88 000FDB88  4B FD 6D 49 */	bl kar_grcoll__near_800d7ad0
/* 80100D8C 000FDB8C  88 1D 01 48 */	lbz r0, 0x148(r29)
/* 80100D90 000FDB90  38 60 00 00 */	li r3, 0x0
/* 80100D94 000FDB94  50 60 2E B4 */	rlwimi r0, r3, 5, 26, 26
/* 80100D98 000FDB98  98 1D 01 48 */	stb r0, 0x148(r29)
/* 80100D9C 000FDB9C  83 DD 01 34 */	lwz r30, 0x134(r29)
/* 80100DA0 000FDBA0  C0 3D 01 44 */	lfs f1, 0x144(r29)
/* 80100DA4 000FDBA4  C0 1C 00 14 */	lfs f0, 0x14(r28)
/* 80100DA8 000FDBA8  28 1E 00 00 */	cmplwi r30, 0x0
/* 80100DAC 000FDBAC  EF E1 00 28 */	fsubs f31, f1, f0
/* 80100DB0 000FDBB0  40 82 00 14 */	bne .L_80100DC4
/* 80100DB4 000FDBB4  38 6D 91 C0 */	li r3, kar_srcfile_jobj_h_805d62a0@sda21
/* 80100DB8 000FDBB8  38 80 03 C6 */	li r4, 0x3c6
/* 80100DBC 000FDBBC  38 AD 91 C8 */	li r5, lbl_805D62A8@sda21
/* 80100DC0 000FDBC0  48 32 76 F9 */	bl __assert
.L_80100DC4:
/* 80100DC4 000FDBC4  D3 FE 00 3C */	stfs f31, 0x3c(r30)
/* 80100DC8 000FDBC8  80 1E 00 14 */	lwz r0, 0x14(r30)
/* 80100DCC 000FDBCC  54 00 01 8D */	rlwinm. r0, r0, 0, 6, 6
/* 80100DD0 000FDBD0  40 82 00 4C */	bne .L_80100E1C
/* 80100DD4 000FDBD4  28 1E 00 00 */	cmplwi r30, 0x0
/* 80100DD8 000FDBD8  41 82 00 44 */	beq .L_80100E1C
/* 80100DDC 000FDBDC  40 82 00 14 */	bne .L_80100DF0
/* 80100DE0 000FDBE0  38 6D 91 C0 */	li r3, kar_srcfile_jobj_h_805d62a0@sda21
/* 80100DE4 000FDBE4  38 80 02 5D */	li r4, 0x25d
/* 80100DE8 000FDBE8  38 AD 91 C8 */	li r5, lbl_805D62A8@sda21
/* 80100DEC 000FDBEC  48 32 76 CD */	bl __assert
.L_80100DF0:
/* 80100DF0 000FDBF0  80 9E 00 14 */	lwz r4, 0x14(r30)
/* 80100DF4 000FDBF4  38 60 00 00 */	li r3, 0x0
/* 80100DF8 000FDBF8  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 80100DFC 000FDBFC  40 82 00 10 */	bne .L_80100E0C
/* 80100E00 000FDC00  54 80 06 73 */	rlwinm. r0, r4, 0, 25, 25
/* 80100E04 000FDC04  41 82 00 08 */	beq .L_80100E0C
/* 80100E08 000FDC08  38 60 00 01 */	li r3, 0x1
.L_80100E0C:
/* 80100E0C 000FDC0C  2C 03 00 00 */	cmpwi r3, 0x0
/* 80100E10 000FDC10  40 82 00 0C */	bne .L_80100E1C
/* 80100E14 000FDC14  7F C3 F3 78 */	mr r3, r30
/* 80100E18 000FDC18  48 30 CB 15 */	bl HSD_JObjSetMtxDirtySub
.L_80100E1C:
/* 80100E1C 000FDC1C  C0 22 92 48 */	lfs f1, lbl_805DF948@sda21(r0)
/* 80100E20 000FDC20  7F A3 EB 78 */	mr r3, r29
/* 80100E24 000FDC24  80 BC 00 10 */	lwz r5, 0x10(r28)
/* 80100E28 000FDC28  38 80 00 03 */	li r4, 0x3
/* 80100E2C 000FDC2C  FC 60 08 90 */	fmr f3, f1
/* 80100E30 000FDC30  80 DC 00 00 */	lwz r6, 0x0(r28)
/* 80100E34 000FDC34  C0 42 92 4C */	lfs f2, lbl_805DF94C@sda21(r0)
/* 80100E38 000FDC38  38 E0 00 00 */	li r7, 0x0
/* 80100E3C 000FDC3C  4B FF 47 0D */	bl kar_gryaku_set_path_node_motion
.L_80100E40:
/* 80100E40 000FDC40  E3 E1 00 28 */	psq_l f31, 0x28(r1), 0, qr0
/* 80100E44 000FDC44  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80100E48 000FDC48  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 80100E4C 000FDC4C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80100E50 000FDC50  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80100E54 000FDC54  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80100E58 000FDC58  83 81 00 10 */	lwz r28, 0x10(r1)
/* 80100E5C 000FDC5C  7C 08 03 A6 */	mtlr r0
/* 80100E60 000FDC60  38 21 00 30 */	addi r1, r1, 0x30
/* 80100E64 000FDC64  4E 80 00 20 */	blr
.endfn kar_gryakulighttunnel_update_kind52_pillar_progress_motion

# .text:0x774 | 0x80100E68 | size: 0x14C
.fn kar_gryakulighttunnel_update_kind52_pillar_return_to_idle, global
/* 80100E68 000FDC68  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80100E6C 000FDC6C  7C 08 02 A6 */	mflr r0
/* 80100E70 000FDC70  90 01 00 34 */	stw r0, 0x34(r1)
/* 80100E74 000FDC74  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 80100E78 000FDC78  F3 E1 00 28 */	psq_st f31, 0x28(r1), 0, qr0
/* 80100E7C 000FDC7C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80100E80 000FDC80  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80100E84 000FDC84  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80100E88 000FDC88  7C 7D 1B 78 */	mr r29, r3
/* 80100E8C 000FDC8C  80 8D 05 EC */	lwz r4, lbl_805DD6CC@sda21(r0)
/* 80100E90 000FDC90  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80100E94 000FDC94  80 84 01 04 */	lwz r4, 0x104(r4)
/* 80100E98 000FDC98  80 63 00 08 */	lwz r3, 0x8(r3)
/* 80100E9C 000FDC9C  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80100EA0 000FDCA0  80 03 00 00 */	lwz r0, 0x0(r3)
/* 80100EA4 000FDCA4  54 00 18 38 */	slwi r0, r0, 3
/* 80100EA8 000FDCA8  7C 64 00 2E */	lwzx r3, r4, r0
/* 80100EAC 000FDCAC  4B F5 39 35 */	bl kar_gmlanmenu__near_800547e0
/* 80100EB0 000FDCB0  2C 03 00 00 */	cmpwi r3, 0x0
/* 80100EB4 000FDCB4  40 82 00 DC */	bne .L_80100F90
/* 80100EB8 000FDCB8  83 DD 00 2C */	lwz r30, 0x2c(r29)
/* 80100EBC 000FDCBC  88 7E 01 48 */	lbz r3, 0x148(r30)
/* 80100EC0 000FDCC0  80 9E 00 08 */	lwz r4, 0x8(r30)
/* 80100EC4 000FDCC4  54 60 DF FF */	extrwi. r0, r3, 1, 26
/* 80100EC8 000FDCC8  83 E4 00 00 */	lwz r31, 0x0(r4)
/* 80100ECC 000FDCCC  41 82 00 90 */	beq .L_80100F5C
/* 80100ED0 000FDCD0  38 00 00 00 */	li r0, 0x0
/* 80100ED4 000FDCD4  50 03 2E B4 */	rlwimi r3, r0, 5, 26, 26
/* 80100ED8 000FDCD8  98 7E 01 48 */	stb r3, 0x148(r30)
/* 80100EDC 000FDCDC  83 BE 01 34 */	lwz r29, 0x134(r30)
/* 80100EE0 000FDCE0  C0 3E 01 44 */	lfs f1, 0x144(r30)
/* 80100EE4 000FDCE4  C0 1F 00 14 */	lfs f0, 0x14(r31)
/* 80100EE8 000FDCE8  28 1D 00 00 */	cmplwi r29, 0x0
/* 80100EEC 000FDCEC  EF E1 00 28 */	fsubs f31, f1, f0
/* 80100EF0 000FDCF0  40 82 00 14 */	bne .L_80100F04
/* 80100EF4 000FDCF4  38 6D 91 C0 */	li r3, kar_srcfile_jobj_h_805d62a0@sda21
/* 80100EF8 000FDCF8  38 80 03 C6 */	li r4, 0x3c6
/* 80100EFC 000FDCFC  38 AD 91 C8 */	li r5, lbl_805D62A8@sda21
/* 80100F00 000FDD00  48 32 75 B9 */	bl __assert
.L_80100F04:
/* 80100F04 000FDD04  D3 FD 00 3C */	stfs f31, 0x3c(r29)
/* 80100F08 000FDD08  80 1D 00 14 */	lwz r0, 0x14(r29)
/* 80100F0C 000FDD0C  54 00 01 8D */	rlwinm. r0, r0, 0, 6, 6
/* 80100F10 000FDD10  40 82 00 4C */	bne .L_80100F5C
/* 80100F14 000FDD14  28 1D 00 00 */	cmplwi r29, 0x0
/* 80100F18 000FDD18  41 82 00 44 */	beq .L_80100F5C
/* 80100F1C 000FDD1C  40 82 00 14 */	bne .L_80100F30
/* 80100F20 000FDD20  38 6D 91 C0 */	li r3, kar_srcfile_jobj_h_805d62a0@sda21
/* 80100F24 000FDD24  38 80 02 5D */	li r4, 0x25d
/* 80100F28 000FDD28  38 AD 91 C8 */	li r5, lbl_805D62A8@sda21
/* 80100F2C 000FDD2C  48 32 75 8D */	bl __assert
.L_80100F30:
/* 80100F30 000FDD30  80 9D 00 14 */	lwz r4, 0x14(r29)
/* 80100F34 000FDD34  38 60 00 00 */	li r3, 0x0
/* 80100F38 000FDD38  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 80100F3C 000FDD3C  40 82 00 10 */	bne .L_80100F4C
/* 80100F40 000FDD40  54 80 06 73 */	rlwinm. r0, r4, 0, 25, 25
/* 80100F44 000FDD44  41 82 00 08 */	beq .L_80100F4C
/* 80100F48 000FDD48  38 60 00 01 */	li r3, 0x1
.L_80100F4C:
/* 80100F4C 000FDD4C  2C 03 00 00 */	cmpwi r3, 0x0
/* 80100F50 000FDD50  40 82 00 0C */	bne .L_80100F5C
/* 80100F54 000FDD54  7F A3 EB 78 */	mr r3, r29
/* 80100F58 000FDD58  48 30 C9 D5 */	bl HSD_JObjSetMtxDirtySub
.L_80100F5C:
/* 80100F5C 000FDD5C  88 1E 01 48 */	lbz r0, 0x148(r30)
/* 80100F60 000FDD60  38 60 00 00 */	li r3, 0x0
/* 80100F64 000FDD64  C0 22 92 48 */	lfs f1, lbl_805DF948@sda21(r0)
/* 80100F68 000FDD68  50 60 3E 30 */	rlwimi r0, r3, 7, 24, 24
/* 80100F6C 000FDD6C  98 1E 01 48 */	stb r0, 0x148(r30)
/* 80100F70 000FDD70  7F C3 F3 78 */	mr r3, r30
/* 80100F74 000FDD74  FC 40 08 90 */	fmr f2, f1
/* 80100F78 000FDD78  38 80 00 00 */	li r4, 0x0
/* 80100F7C 000FDD7C  FC 60 08 90 */	fmr f3, f1
/* 80100F80 000FDD80  80 DF 00 00 */	lwz r6, 0x0(r31)
/* 80100F84 000FDD84  38 A0 FF FF */	li r5, -0x1
/* 80100F88 000FDD88  38 E0 00 00 */	li r7, 0x0
/* 80100F8C 000FDD8C  4B FF 45 BD */	bl kar_gryaku_set_path_node_motion
.L_80100F90:
/* 80100F90 000FDD90  E3 E1 00 28 */	psq_l f31, 0x28(r1), 0, qr0
/* 80100F94 000FDD94  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80100F98 000FDD98  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 80100F9C 000FDD9C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80100FA0 000FDDA0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80100FA4 000FDDA4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80100FA8 000FDDA8  7C 08 03 A6 */	mtlr r0
/* 80100FAC 000FDDAC  38 21 00 30 */	addi r1, r1, 0x30
/* 80100FB0 000FDDB0  4E 80 00 20 */	blr
.endfn kar_gryakulighttunnel_update_kind52_pillar_return_to_idle

# .text:0x8C0 | 0x80100FB4 | size: 0x38
.fn kar_gryakupillar_create_stage_linked_kind53_pillar_controller, global
/* 80100FB4 000FDDB4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80100FB8 000FDDB8  7C 08 02 A6 */	mflr r0
/* 80100FBC 000FDDBC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80100FC0 000FDDC0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80100FC4 000FDDC4  7C 7F 1B 78 */	mr r31, r3
/* 80100FC8 000FDDC8  38 60 00 35 */	li r3, 0x35
/* 80100FCC 000FDDCC  4B FF 34 A1 */	bl kar_gryaku_create_yaku_from_main_kind
/* 80100FD0 000FDDD0  7F E4 FB 78 */	mr r4, r31
/* 80100FD4 000FDDD4  48 00 00 19 */	bl kar_gryakupillar_init_kind53_pillar_controller
/* 80100FD8 000FDDD8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80100FDC 000FDDDC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80100FE0 000FDDE0  7C 08 03 A6 */	mtlr r0
/* 80100FE4 000FDDE4  38 21 00 10 */	addi r1, r1, 0x10
/* 80100FE8 000FDDE8  4E 80 00 20 */	blr
.endfn kar_gryakupillar_create_stage_linked_kind53_pillar_controller

# 0x804A662C..0x804A6694 | size: 0x68
.data
.balign 4

# .data:0x0 | 0x804A662C | size: 0x14
.obj kar_src_gryakulighttunnel_c, global
	.string "gryakulighttunnel.c"
.endobj kar_src_gryakulighttunnel_c

# .data:0x14 | 0x804A6640 | size: 0x40
.obj kar_gryakulighttunnel_kind52_callback_table, global
	.4byte kar_gryakulighttunnel_update_kind52_pillar_delay_to_motion
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte kar_gryakulighttunnel_update_kind52_pillar_ground_clear_motion
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte kar_gryakulighttunnel_update_kind52_pillar_progress_motion
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte kar_gryakulighttunnel_update_kind52_pillar_return_to_idle
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj kar_gryakulighttunnel_kind52_callback_table

# .data:0x54 | 0x804A6680 | size: 0x14
.obj kar_gryakulighttunnel_kind52_callback_table_ptr, global
	.4byte kar_gryakulighttunnel_kind52_callback_table
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj kar_gryakulighttunnel_kind52_callback_table_ptr

# 0x805D62A0..0x805D62B0 | size: 0x10
.section .sdata, "wa"
.balign 8

# .sdata:0x0 | 0x805D62A0 | size: 0x7
.obj kar_srcfile_jobj_h_805d62a0, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d62a0

# .sdata:0x7 | 0x805D62A7 | size: 0x1
.obj gap_09_805D62A7_sdata, global
.hidden gap_09_805D62A7_sdata
	.byte 0x00
.endobj gap_09_805D62A7_sdata

# .sdata:0x8 | 0x805D62A8 | size: 0x5
.obj lbl_805D62A8, global
	.string "jobj"
.endobj lbl_805D62A8

# .sdata:0xD | 0x805D62AD | size: 0x3
.obj gap_09_805D62AD_sdata, global
.hidden gap_09_805D62AD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D62AD_sdata

# 0x805DF940..0x805DF950 | size: 0x10
.section .sdata2, "a"
.balign 8

# .sdata2:0x0 | 0x805DF940 | size: 0x8
.obj lbl_805DF940, global
	.double 4503601774854144
.endobj lbl_805DF940

# .sdata2:0x8 | 0x805DF948 | size: 0x4
.obj lbl_805DF948, global
	.float 0
.endobj lbl_805DF948

# .sdata2:0xC | 0x805DF94C | size: 0x4
.obj lbl_805DF94C, global
	.float 1
.endobj lbl_805DF94C
