.include "macros.inc"
.file "mndialoguebg.c"

# 0x8017B778..0x8017CF14 | size: 0x179C
.text
.balign 4

# .text:0x0 | 0x8017B778 | size: 0xB4
.fn kar_mndialoguebg_project_box0_origin_to_screen, global
/* 8017B778 00178578  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8017B77C 0017857C  7C 08 02 A6 */	mflr r0
/* 8017B780 00178580  90 01 00 24 */	stw r0, 0x24(r1)
/* 8017B784 00178584  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8017B788 00178588  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8017B78C 0017858C  7C 7E 1B 78 */	mr r30, r3
/* 8017B790 00178590  4B FB 5A 51 */	bl fn_801311E0
/* 8017B794 00178594  80 63 11 38 */	lwz r3, 0x1138(r3)
/* 8017B798 00178598  28 03 00 00 */	cmplwi r3, 0x0
/* 8017B79C 0017859C  41 82 00 78 */	beq .L_8017B814
/* 8017B7A0 001785A0  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8017B7A4 001785A4  83 E3 00 14 */	lwz r31, 0x14(r3)
/* 8017B7A8 001785A8  28 1F 00 00 */	cmplwi r31, 0x0
/* 8017B7AC 001785AC  40 82 00 14 */	bne .L_8017B7C0
/* 8017B7B0 001785B0  38 6D 9C F0 */	li r3, kar_srcfile_jobj_h_805d6dd0@sda21
/* 8017B7B4 001785B4  38 80 03 E4 */	li r4, 0x3e4
/* 8017B7B8 001785B8  38 AD 9C F8 */	li r5, lbl_805D6DD8@sda21
/* 8017B7BC 001785BC  48 2A CC FD */	bl __assert
.L_8017B7C0:
/* 8017B7C0 001785C0  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 8017B7C4 001785C4  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 8017B7C8 001785C8  90 61 00 08 */	stw r3, 0x8(r1)
/* 8017B7CC 001785CC  90 01 00 0C */	stw r0, 0xc(r1)
/* 8017B7D0 001785D0  80 1F 00 40 */	lwz r0, 0x40(r31)
/* 8017B7D4 001785D4  90 01 00 10 */	stw r0, 0x10(r1)
/* 8017B7D8 001785D8  4B FB 5A 09 */	bl fn_801311E0
/* 8017B7DC 001785DC  80 63 00 08 */	lwz r3, 0x8(r3)
/* 8017B7E0 001785E0  28 03 00 00 */	cmplwi r3, 0x0
/* 8017B7E4 001785E4  41 82 00 1C */	beq .L_8017B800
/* 8017B7E8 001785E8  80 63 00 28 */	lwz r3, 0x28(r3)
/* 8017B7EC 001785EC  7F C5 F3 78 */	mr r5, r30
/* 8017B7F0 001785F0  38 81 00 08 */	addi r4, r1, 0x8
/* 8017B7F4 001785F4  38 C0 00 00 */	li r6, 0x0
/* 8017B7F8 001785F8  4B EE 8C B5 */	bl kar_lbvector_project_world_to_screen
/* 8017B7FC 001785FC  48 00 00 18 */	b .L_8017B814
.L_8017B800:
/* 8017B800 00178600  3C 60 80 4B */	lis r3, kar_src_mndialoguebg_c@ha
/* 8017B804 00178604  38 80 00 3E */	li r4, 0x3e
/* 8017B808 00178608  38 63 D1 BC */	addi r3, r3, kar_src_mndialoguebg_c@l
/* 8017B80C 0017860C  38 AD 9D 00 */	li r5, lbl_805D6DE0@sda21
/* 8017B810 00178610  48 2A CC A9 */	bl __assert
.L_8017B814:
/* 8017B814 00178614  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8017B818 00178618  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8017B81C 0017861C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8017B820 00178620  7C 08 03 A6 */	mtlr r0
/* 8017B824 00178624  38 21 00 20 */	addi r1, r1, 0x20
/* 8017B828 00178628  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_project_box0_origin_to_screen

# .text:0xB4 | 0x8017B82C | size: 0xB4
.fn kar_mndialoguebg_project_box0_right_edge_to_screen, global
/* 8017B82C 0017862C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8017B830 00178630  7C 08 02 A6 */	mflr r0
/* 8017B834 00178634  90 01 00 24 */	stw r0, 0x24(r1)
/* 8017B838 00178638  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8017B83C 0017863C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8017B840 00178640  7C 7E 1B 78 */	mr r30, r3
/* 8017B844 00178644  4B FB 59 9D */	bl fn_801311E0
/* 8017B848 00178648  80 63 11 38 */	lwz r3, 0x1138(r3)
/* 8017B84C 0017864C  28 03 00 00 */	cmplwi r3, 0x0
/* 8017B850 00178650  41 82 00 78 */	beq .L_8017B8C8
/* 8017B854 00178654  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8017B858 00178658  83 E3 00 18 */	lwz r31, 0x18(r3)
/* 8017B85C 0017865C  28 1F 00 00 */	cmplwi r31, 0x0
/* 8017B860 00178660  40 82 00 14 */	bne .L_8017B874
/* 8017B864 00178664  38 6D 9C F0 */	li r3, kar_srcfile_jobj_h_805d6dd0@sda21
/* 8017B868 00178668  38 80 03 E4 */	li r4, 0x3e4
/* 8017B86C 0017866C  38 AD 9C F8 */	li r5, lbl_805D6DD8@sda21
/* 8017B870 00178670  48 2A CC 49 */	bl __assert
.L_8017B874:
/* 8017B874 00178674  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 8017B878 00178678  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 8017B87C 0017867C  90 61 00 08 */	stw r3, 0x8(r1)
/* 8017B880 00178680  90 01 00 0C */	stw r0, 0xc(r1)
/* 8017B884 00178684  80 1F 00 40 */	lwz r0, 0x40(r31)
/* 8017B888 00178688  90 01 00 10 */	stw r0, 0x10(r1)
/* 8017B88C 0017868C  4B FB 59 55 */	bl fn_801311E0
/* 8017B890 00178690  80 63 00 08 */	lwz r3, 0x8(r3)
/* 8017B894 00178694  28 03 00 00 */	cmplwi r3, 0x0
/* 8017B898 00178698  41 82 00 1C */	beq .L_8017B8B4
/* 8017B89C 0017869C  80 63 00 28 */	lwz r3, 0x28(r3)
/* 8017B8A0 001786A0  7F C5 F3 78 */	mr r5, r30
/* 8017B8A4 001786A4  38 81 00 08 */	addi r4, r1, 0x8
/* 8017B8A8 001786A8  38 C0 00 00 */	li r6, 0x0
/* 8017B8AC 001786AC  4B EE 8C 01 */	bl kar_lbvector_project_world_to_screen
/* 8017B8B0 001786B0  48 00 00 18 */	b .L_8017B8C8
.L_8017B8B4:
/* 8017B8B4 001786B4  3C 60 80 4B */	lis r3, kar_src_mndialoguebg_c@ha
/* 8017B8B8 001786B8  38 80 00 3E */	li r4, 0x3e
/* 8017B8BC 001786BC  38 63 D1 BC */	addi r3, r3, kar_src_mndialoguebg_c@l
/* 8017B8C0 001786C0  38 AD 9D 00 */	li r5, lbl_805D6DE0@sda21
/* 8017B8C4 001786C4  48 2A CB F5 */	bl __assert
.L_8017B8C8:
/* 8017B8C8 001786C8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8017B8CC 001786CC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8017B8D0 001786D0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8017B8D4 001786D4  7C 08 03 A6 */	mtlr r0
/* 8017B8D8 001786D8  38 21 00 20 */	addi r1, r1, 0x20
/* 8017B8DC 001786DC  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_project_box0_right_edge_to_screen

# .text:0x168 | 0x8017B8E0 | size: 0xB4
.fn kar_mndialoguebg_project_box0_bottom_edge_to_screen, global
/* 8017B8E0 001786E0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8017B8E4 001786E4  7C 08 02 A6 */	mflr r0
/* 8017B8E8 001786E8  90 01 00 24 */	stw r0, 0x24(r1)
/* 8017B8EC 001786EC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8017B8F0 001786F0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8017B8F4 001786F4  7C 7E 1B 78 */	mr r30, r3
/* 8017B8F8 001786F8  4B FB 58 E9 */	bl fn_801311E0
/* 8017B8FC 001786FC  80 63 11 38 */	lwz r3, 0x1138(r3)
/* 8017B900 00178700  28 03 00 00 */	cmplwi r3, 0x0
/* 8017B904 00178704  41 82 00 78 */	beq .L_8017B97C
/* 8017B908 00178708  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8017B90C 0017870C  83 E3 00 1C */	lwz r31, 0x1c(r3)
/* 8017B910 00178710  28 1F 00 00 */	cmplwi r31, 0x0
/* 8017B914 00178714  40 82 00 14 */	bne .L_8017B928
/* 8017B918 00178718  38 6D 9C F0 */	li r3, kar_srcfile_jobj_h_805d6dd0@sda21
/* 8017B91C 0017871C  38 80 03 E4 */	li r4, 0x3e4
/* 8017B920 00178720  38 AD 9C F8 */	li r5, lbl_805D6DD8@sda21
/* 8017B924 00178724  48 2A CB 95 */	bl __assert
.L_8017B928:
/* 8017B928 00178728  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 8017B92C 0017872C  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 8017B930 00178730  90 61 00 08 */	stw r3, 0x8(r1)
/* 8017B934 00178734  90 01 00 0C */	stw r0, 0xc(r1)
/* 8017B938 00178738  80 1F 00 40 */	lwz r0, 0x40(r31)
/* 8017B93C 0017873C  90 01 00 10 */	stw r0, 0x10(r1)
/* 8017B940 00178740  4B FB 58 A1 */	bl fn_801311E0
/* 8017B944 00178744  80 63 00 08 */	lwz r3, 0x8(r3)
/* 8017B948 00178748  28 03 00 00 */	cmplwi r3, 0x0
/* 8017B94C 0017874C  41 82 00 1C */	beq .L_8017B968
/* 8017B950 00178750  80 63 00 28 */	lwz r3, 0x28(r3)
/* 8017B954 00178754  7F C5 F3 78 */	mr r5, r30
/* 8017B958 00178758  38 81 00 08 */	addi r4, r1, 0x8
/* 8017B95C 0017875C  38 C0 00 00 */	li r6, 0x0
/* 8017B960 00178760  4B EE 8B 4D */	bl kar_lbvector_project_world_to_screen
/* 8017B964 00178764  48 00 00 18 */	b .L_8017B97C
.L_8017B968:
/* 8017B968 00178768  3C 60 80 4B */	lis r3, kar_src_mndialoguebg_c@ha
/* 8017B96C 0017876C  38 80 00 3E */	li r4, 0x3e
/* 8017B970 00178770  38 63 D1 BC */	addi r3, r3, kar_src_mndialoguebg_c@l
/* 8017B974 00178774  38 AD 9D 00 */	li r5, lbl_805D6DE0@sda21
/* 8017B978 00178778  48 2A CB 41 */	bl __assert
.L_8017B97C:
/* 8017B97C 0017877C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8017B980 00178780  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8017B984 00178784  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8017B988 00178788  7C 08 03 A6 */	mtlr r0
/* 8017B98C 0017878C  38 21 00 20 */	addi r1, r1, 0x20
/* 8017B990 00178790  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_project_box0_bottom_edge_to_screen

# .text:0x21C | 0x8017B994 | size: 0x40
.fn kar_mndialoguebg_get_box1_screen_width, global
/* 8017B994 00178794  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8017B998 00178798  7C 08 02 A6 */	mflr r0
/* 8017B99C 0017879C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8017B9A0 001787A0  38 61 00 14 */	addi r3, r1, 0x14
/* 8017B9A4 001787A4  48 00 00 71 */	bl kar_mndialoguebg_project_box1_origin_to_screen
/* 8017B9A8 001787A8  38 61 00 08 */	addi r3, r1, 0x8
/* 8017B9AC 001787AC  48 00 01 1D */	bl kar_mndialoguebg_project_box1_right_edge_to_screen
/* 8017B9B0 001787B0  C0 21 00 08 */	lfs f1, 0x8(r1)
/* 8017B9B4 001787B4  C0 01 00 14 */	lfs f0, 0x14(r1)
/* 8017B9B8 001787B8  EC 01 00 28 */	fsubs f0, f1, f0
/* 8017B9BC 001787BC  FC 00 02 10 */	fabs f0, f0
/* 8017B9C0 001787C0  FC 20 00 18 */	frsp f1, f0
/* 8017B9C4 001787C4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8017B9C8 001787C8  7C 08 03 A6 */	mtlr r0
/* 8017B9CC 001787CC  38 21 00 20 */	addi r1, r1, 0x20
/* 8017B9D0 001787D0  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_get_box1_screen_width

# .text:0x25C | 0x8017B9D4 | size: 0x40
.fn kar_mndialoguebg_get_box1_screen_height, global
/* 8017B9D4 001787D4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8017B9D8 001787D8  7C 08 02 A6 */	mflr r0
/* 8017B9DC 001787DC  90 01 00 24 */	stw r0, 0x24(r1)
/* 8017B9E0 001787E0  38 61 00 14 */	addi r3, r1, 0x14
/* 8017B9E4 001787E4  48 00 00 31 */	bl kar_mndialoguebg_project_box1_origin_to_screen
/* 8017B9E8 001787E8  38 61 00 08 */	addi r3, r1, 0x8
/* 8017B9EC 001787EC  48 00 01 91 */	bl kar_mndialoguebg_project_box1_bottom_edge_to_screen
/* 8017B9F0 001787F0  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8017B9F4 001787F4  C0 01 00 18 */	lfs f0, 0x18(r1)
/* 8017B9F8 001787F8  EC 01 00 28 */	fsubs f0, f1, f0
/* 8017B9FC 001787FC  FC 00 02 10 */	fabs f0, f0
/* 8017BA00 00178800  FC 20 00 18 */	frsp f1, f0
/* 8017BA04 00178804  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8017BA08 00178808  7C 08 03 A6 */	mtlr r0
/* 8017BA0C 0017880C  38 21 00 20 */	addi r1, r1, 0x20
/* 8017BA10 00178810  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_get_box1_screen_height

# .text:0x29C | 0x8017BA14 | size: 0xB4
.fn kar_mndialoguebg_project_box1_origin_to_screen, global
/* 8017BA14 00178814  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8017BA18 00178818  7C 08 02 A6 */	mflr r0
/* 8017BA1C 0017881C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8017BA20 00178820  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8017BA24 00178824  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8017BA28 00178828  7C 7E 1B 78 */	mr r30, r3
/* 8017BA2C 0017882C  4B FB 57 B5 */	bl fn_801311E0
/* 8017BA30 00178830  80 63 11 38 */	lwz r3, 0x1138(r3)
/* 8017BA34 00178834  28 03 00 00 */	cmplwi r3, 0x0
/* 8017BA38 00178838  41 82 00 78 */	beq .L_8017BAB0
/* 8017BA3C 0017883C  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8017BA40 00178840  83 E3 00 20 */	lwz r31, 0x20(r3)
/* 8017BA44 00178844  28 1F 00 00 */	cmplwi r31, 0x0
/* 8017BA48 00178848  40 82 00 14 */	bne .L_8017BA5C
/* 8017BA4C 0017884C  38 6D 9C F0 */	li r3, kar_srcfile_jobj_h_805d6dd0@sda21
/* 8017BA50 00178850  38 80 03 E4 */	li r4, 0x3e4
/* 8017BA54 00178854  38 AD 9C F8 */	li r5, lbl_805D6DD8@sda21
/* 8017BA58 00178858  48 2A CA 61 */	bl __assert
.L_8017BA5C:
/* 8017BA5C 0017885C  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 8017BA60 00178860  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 8017BA64 00178864  90 61 00 08 */	stw r3, 0x8(r1)
/* 8017BA68 00178868  90 01 00 0C */	stw r0, 0xc(r1)
/* 8017BA6C 0017886C  80 1F 00 40 */	lwz r0, 0x40(r31)
/* 8017BA70 00178870  90 01 00 10 */	stw r0, 0x10(r1)
/* 8017BA74 00178874  4B FB 57 6D */	bl fn_801311E0
/* 8017BA78 00178878  80 63 00 08 */	lwz r3, 0x8(r3)
/* 8017BA7C 0017887C  28 03 00 00 */	cmplwi r3, 0x0
/* 8017BA80 00178880  41 82 00 1C */	beq .L_8017BA9C
/* 8017BA84 00178884  80 63 00 28 */	lwz r3, 0x28(r3)
/* 8017BA88 00178888  7F C5 F3 78 */	mr r5, r30
/* 8017BA8C 0017888C  38 81 00 08 */	addi r4, r1, 0x8
/* 8017BA90 00178890  38 C0 00 00 */	li r6, 0x0
/* 8017BA94 00178894  4B EE 8A 19 */	bl kar_lbvector_project_world_to_screen
/* 8017BA98 00178898  48 00 00 18 */	b .L_8017BAB0
.L_8017BA9C:
/* 8017BA9C 0017889C  3C 60 80 4B */	lis r3, kar_src_mndialoguebg_c@ha
/* 8017BAA0 001788A0  38 80 00 3E */	li r4, 0x3e
/* 8017BAA4 001788A4  38 63 D1 BC */	addi r3, r3, kar_src_mndialoguebg_c@l
/* 8017BAA8 001788A8  38 AD 9D 00 */	li r5, lbl_805D6DE0@sda21
/* 8017BAAC 001788AC  48 2A CA 0D */	bl __assert
.L_8017BAB0:
/* 8017BAB0 001788B0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8017BAB4 001788B4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8017BAB8 001788B8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8017BABC 001788BC  7C 08 03 A6 */	mtlr r0
/* 8017BAC0 001788C0  38 21 00 20 */	addi r1, r1, 0x20
/* 8017BAC4 001788C4  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_project_box1_origin_to_screen

# .text:0x350 | 0x8017BAC8 | size: 0xB4
.fn kar_mndialoguebg_project_box1_right_edge_to_screen, global
/* 8017BAC8 001788C8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8017BACC 001788CC  7C 08 02 A6 */	mflr r0
/* 8017BAD0 001788D0  90 01 00 24 */	stw r0, 0x24(r1)
/* 8017BAD4 001788D4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8017BAD8 001788D8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8017BADC 001788DC  7C 7E 1B 78 */	mr r30, r3
/* 8017BAE0 001788E0  4B FB 57 01 */	bl fn_801311E0
/* 8017BAE4 001788E4  80 63 11 38 */	lwz r3, 0x1138(r3)
/* 8017BAE8 001788E8  28 03 00 00 */	cmplwi r3, 0x0
/* 8017BAEC 001788EC  41 82 00 78 */	beq .L_8017BB64
/* 8017BAF0 001788F0  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8017BAF4 001788F4  83 E3 00 24 */	lwz r31, 0x24(r3)
/* 8017BAF8 001788F8  28 1F 00 00 */	cmplwi r31, 0x0
/* 8017BAFC 001788FC  40 82 00 14 */	bne .L_8017BB10
/* 8017BB00 00178900  38 6D 9C F0 */	li r3, kar_srcfile_jobj_h_805d6dd0@sda21
/* 8017BB04 00178904  38 80 03 E4 */	li r4, 0x3e4
/* 8017BB08 00178908  38 AD 9C F8 */	li r5, lbl_805D6DD8@sda21
/* 8017BB0C 0017890C  48 2A C9 AD */	bl __assert
.L_8017BB10:
/* 8017BB10 00178910  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 8017BB14 00178914  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 8017BB18 00178918  90 61 00 08 */	stw r3, 0x8(r1)
/* 8017BB1C 0017891C  90 01 00 0C */	stw r0, 0xc(r1)
/* 8017BB20 00178920  80 1F 00 40 */	lwz r0, 0x40(r31)
/* 8017BB24 00178924  90 01 00 10 */	stw r0, 0x10(r1)
/* 8017BB28 00178928  4B FB 56 B9 */	bl fn_801311E0
/* 8017BB2C 0017892C  80 63 00 08 */	lwz r3, 0x8(r3)
/* 8017BB30 00178930  28 03 00 00 */	cmplwi r3, 0x0
/* 8017BB34 00178934  41 82 00 1C */	beq .L_8017BB50
/* 8017BB38 00178938  80 63 00 28 */	lwz r3, 0x28(r3)
/* 8017BB3C 0017893C  7F C5 F3 78 */	mr r5, r30
/* 8017BB40 00178940  38 81 00 08 */	addi r4, r1, 0x8
/* 8017BB44 00178944  38 C0 00 00 */	li r6, 0x0
/* 8017BB48 00178948  4B EE 89 65 */	bl kar_lbvector_project_world_to_screen
/* 8017BB4C 0017894C  48 00 00 18 */	b .L_8017BB64
.L_8017BB50:
/* 8017BB50 00178950  3C 60 80 4B */	lis r3, kar_src_mndialoguebg_c@ha
/* 8017BB54 00178954  38 80 00 3E */	li r4, 0x3e
/* 8017BB58 00178958  38 63 D1 BC */	addi r3, r3, kar_src_mndialoguebg_c@l
/* 8017BB5C 0017895C  38 AD 9D 00 */	li r5, lbl_805D6DE0@sda21
/* 8017BB60 00178960  48 2A C9 59 */	bl __assert
.L_8017BB64:
/* 8017BB64 00178964  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8017BB68 00178968  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8017BB6C 0017896C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8017BB70 00178970  7C 08 03 A6 */	mtlr r0
/* 8017BB74 00178974  38 21 00 20 */	addi r1, r1, 0x20
/* 8017BB78 00178978  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_project_box1_right_edge_to_screen

# .text:0x404 | 0x8017BB7C | size: 0xB4
.fn kar_mndialoguebg_project_box1_bottom_edge_to_screen, global
/* 8017BB7C 0017897C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8017BB80 00178980  7C 08 02 A6 */	mflr r0
/* 8017BB84 00178984  90 01 00 24 */	stw r0, 0x24(r1)
/* 8017BB88 00178988  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8017BB8C 0017898C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8017BB90 00178990  7C 7E 1B 78 */	mr r30, r3
/* 8017BB94 00178994  4B FB 56 4D */	bl fn_801311E0
/* 8017BB98 00178998  80 63 11 38 */	lwz r3, 0x1138(r3)
/* 8017BB9C 0017899C  28 03 00 00 */	cmplwi r3, 0x0
/* 8017BBA0 001789A0  41 82 00 78 */	beq .L_8017BC18
/* 8017BBA4 001789A4  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8017BBA8 001789A8  83 E3 00 30 */	lwz r31, 0x30(r3)
/* 8017BBAC 001789AC  28 1F 00 00 */	cmplwi r31, 0x0
/* 8017BBB0 001789B0  40 82 00 14 */	bne .L_8017BBC4
/* 8017BBB4 001789B4  38 6D 9C F0 */	li r3, kar_srcfile_jobj_h_805d6dd0@sda21
/* 8017BBB8 001789B8  38 80 03 E4 */	li r4, 0x3e4
/* 8017BBBC 001789BC  38 AD 9C F8 */	li r5, lbl_805D6DD8@sda21
/* 8017BBC0 001789C0  48 2A C8 F9 */	bl __assert
.L_8017BBC4:
/* 8017BBC4 001789C4  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 8017BBC8 001789C8  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 8017BBCC 001789CC  90 61 00 08 */	stw r3, 0x8(r1)
/* 8017BBD0 001789D0  90 01 00 0C */	stw r0, 0xc(r1)
/* 8017BBD4 001789D4  80 1F 00 40 */	lwz r0, 0x40(r31)
/* 8017BBD8 001789D8  90 01 00 10 */	stw r0, 0x10(r1)
/* 8017BBDC 001789DC  4B FB 56 05 */	bl fn_801311E0
/* 8017BBE0 001789E0  80 63 00 08 */	lwz r3, 0x8(r3)
/* 8017BBE4 001789E4  28 03 00 00 */	cmplwi r3, 0x0
/* 8017BBE8 001789E8  41 82 00 1C */	beq .L_8017BC04
/* 8017BBEC 001789EC  80 63 00 28 */	lwz r3, 0x28(r3)
/* 8017BBF0 001789F0  7F C5 F3 78 */	mr r5, r30
/* 8017BBF4 001789F4  38 81 00 08 */	addi r4, r1, 0x8
/* 8017BBF8 001789F8  38 C0 00 00 */	li r6, 0x0
/* 8017BBFC 001789FC  4B EE 88 B1 */	bl kar_lbvector_project_world_to_screen
/* 8017BC00 00178A00  48 00 00 18 */	b .L_8017BC18
.L_8017BC04:
/* 8017BC04 00178A04  3C 60 80 4B */	lis r3, kar_src_mndialoguebg_c@ha
/* 8017BC08 00178A08  38 80 00 3E */	li r4, 0x3e
/* 8017BC0C 00178A0C  38 63 D1 BC */	addi r3, r3, kar_src_mndialoguebg_c@l
/* 8017BC10 00178A10  38 AD 9D 00 */	li r5, lbl_805D6DE0@sda21
/* 8017BC14 00178A14  48 2A C8 A5 */	bl __assert
.L_8017BC18:
/* 8017BC18 00178A18  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8017BC1C 00178A1C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8017BC20 00178A20  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8017BC24 00178A24  7C 08 03 A6 */	mtlr r0
/* 8017BC28 00178A28  38 21 00 20 */	addi r1, r1, 0x20
/* 8017BC2C 00178A2C  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_project_box1_bottom_edge_to_screen

# .text:0x4B8 | 0x8017BC30 | size: 0xB4
.fn kar_mndialoguebg_project_box2_origin_to_screen, global
/* 8017BC30 00178A30  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8017BC34 00178A34  7C 08 02 A6 */	mflr r0
/* 8017BC38 00178A38  90 01 00 24 */	stw r0, 0x24(r1)
/* 8017BC3C 00178A3C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8017BC40 00178A40  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8017BC44 00178A44  7C 7E 1B 78 */	mr r30, r3
/* 8017BC48 00178A48  4B FB 55 99 */	bl fn_801311E0
/* 8017BC4C 00178A4C  80 63 11 38 */	lwz r3, 0x1138(r3)
/* 8017BC50 00178A50  28 03 00 00 */	cmplwi r3, 0x0
/* 8017BC54 00178A54  41 82 00 78 */	beq .L_8017BCCC
/* 8017BC58 00178A58  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8017BC5C 00178A5C  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8017BC60 00178A60  28 1F 00 00 */	cmplwi r31, 0x0
/* 8017BC64 00178A64  40 82 00 14 */	bne .L_8017BC78
/* 8017BC68 00178A68  38 6D 9C F0 */	li r3, kar_srcfile_jobj_h_805d6dd0@sda21
/* 8017BC6C 00178A6C  38 80 03 E4 */	li r4, 0x3e4
/* 8017BC70 00178A70  38 AD 9C F8 */	li r5, lbl_805D6DD8@sda21
/* 8017BC74 00178A74  48 2A C8 45 */	bl __assert
.L_8017BC78:
/* 8017BC78 00178A78  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 8017BC7C 00178A7C  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 8017BC80 00178A80  90 61 00 08 */	stw r3, 0x8(r1)
/* 8017BC84 00178A84  90 01 00 0C */	stw r0, 0xc(r1)
/* 8017BC88 00178A88  80 1F 00 40 */	lwz r0, 0x40(r31)
/* 8017BC8C 00178A8C  90 01 00 10 */	stw r0, 0x10(r1)
/* 8017BC90 00178A90  4B FB 55 51 */	bl fn_801311E0
/* 8017BC94 00178A94  80 63 00 08 */	lwz r3, 0x8(r3)
/* 8017BC98 00178A98  28 03 00 00 */	cmplwi r3, 0x0
/* 8017BC9C 00178A9C  41 82 00 1C */	beq .L_8017BCB8
/* 8017BCA0 00178AA0  80 63 00 28 */	lwz r3, 0x28(r3)
/* 8017BCA4 00178AA4  7F C5 F3 78 */	mr r5, r30
/* 8017BCA8 00178AA8  38 81 00 08 */	addi r4, r1, 0x8
/* 8017BCAC 00178AAC  38 C0 00 00 */	li r6, 0x0
/* 8017BCB0 00178AB0  4B EE 87 FD */	bl kar_lbvector_project_world_to_screen
/* 8017BCB4 00178AB4  48 00 00 18 */	b .L_8017BCCC
.L_8017BCB8:
/* 8017BCB8 00178AB8  3C 60 80 4B */	lis r3, kar_src_mndialoguebg_c@ha
/* 8017BCBC 00178ABC  38 80 00 3E */	li r4, 0x3e
/* 8017BCC0 00178AC0  38 63 D1 BC */	addi r3, r3, kar_src_mndialoguebg_c@l
/* 8017BCC4 00178AC4  38 AD 9D 00 */	li r5, lbl_805D6DE0@sda21
/* 8017BCC8 00178AC8  48 2A C7 F1 */	bl __assert
.L_8017BCCC:
/* 8017BCCC 00178ACC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8017BCD0 00178AD0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8017BCD4 00178AD4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8017BCD8 00178AD8  7C 08 03 A6 */	mtlr r0
/* 8017BCDC 00178ADC  38 21 00 20 */	addi r1, r1, 0x20
/* 8017BCE0 00178AE0  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_project_box2_origin_to_screen

# .text:0x56C | 0x8017BCE4 | size: 0x24
.fn kar_mndialoguebg_proc_anim_bg_panel, global
/* 8017BCE4 00178AE4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017BCE8 00178AE8  7C 08 02 A6 */	mflr r0
/* 8017BCEC 00178AEC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017BCF0 00178AF0  80 63 00 28 */	lwz r3, 0x28(r3)
/* 8017BCF4 00178AF4  48 28 E9 59 */	bl HSD_JObjAnimAll
/* 8017BCF8 00178AF8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017BCFC 00178AFC  7C 08 03 A6 */	mtlr r0
/* 8017BD00 00178B00  38 21 00 10 */	addi r1, r1, 0x10
/* 8017BD04 00178B04  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_proc_anim_bg_panel

# .text:0x590 | 0x8017BD08 | size: 0x4C
.fn kar_mndialoguebg_load_bg_scene_models, global
/* 8017BD08 00178B08  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017BD0C 00178B0C  7C 08 02 A6 */	mflr r0
/* 8017BD10 00178B10  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017BD14 00178B14  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8017BD18 00178B18  4B FB 54 C9 */	bl fn_801311E0
/* 8017BD1C 00178B1C  7C 7F 1B 78 */	mr r31, r3
/* 8017BD20 00178B20  4B FB D1 05 */	bl fn_80138E24
/* 8017BD24 00178B24  3C 80 80 4B */	lis r4, kar_mndialoguebg_bg_scene_models_name@ha
/* 8017BD28 00178B28  80 63 00 00 */	lwz r3, 0x0(r3)
/* 8017BD2C 00178B2C  38 A4 D1 CC */	addi r5, r4, kar_mndialoguebg_bg_scene_models_name@l
/* 8017BD30 00178B30  38 C0 00 00 */	li r6, 0x0
/* 8017BD34 00178B34  38 9F 11 34 */	addi r4, r31, 0x1134
/* 8017BD38 00178B38  4C C6 31 82 */	crclr cr1eq
/* 8017BD3C 00178B3C  4B ED D7 E5 */	bl kar_lbarchive__near_80059520
/* 8017BD40 00178B40  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017BD44 00178B44  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8017BD48 00178B48  7C 08 03 A6 */	mtlr r0
/* 8017BD4C 00178B4C  38 21 00 10 */	addi r1, r1, 0x10
/* 8017BD50 00178B50  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_load_bg_scene_models

# .text:0x5DC | 0x8017BD54 | size: 0x130
.fn kar_mndialoguebg_create_bg_panel_and_cache_child_jobjs, global
/* 8017BD54 00178B54  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8017BD58 00178B58  7C 08 02 A6 */	mflr r0
/* 8017BD5C 00178B5C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8017BD60 00178B60  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8017BD64 00178B64  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8017BD68 00178B68  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8017BD6C 00178B6C  4B FB 54 75 */	bl fn_801311E0
/* 8017BD70 00178B70  7C 7E 1B 78 */	mr r30, r3
/* 8017BD74 00178B74  80 63 11 34 */	lwz r3, 0x1134(r3)
/* 8017BD78 00178B78  80 63 00 00 */	lwz r3, 0x0(r3)
/* 8017BD7C 00178B7C  80 63 00 00 */	lwz r3, 0x0(r3)
/* 8017BD80 00178B80  4B FB CB 29 */	bl fn_801388A8
/* 8017BD84 00178B84  3C 80 80 18 */	lis r4, kar_mndialoguebg_proc_anim_bg_panel@ha
/* 8017BD88 00178B88  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 8017BD8C 00178B8C  7C 7D 1B 78 */	mr r29, r3
/* 8017BD90 00178B90  38 A0 00 01 */	li r5, 0x1
/* 8017BD94 00178B94  38 84 BC E4 */	addi r4, r4, kar_mndialoguebg_proc_anim_bg_panel@l
/* 8017BD98 00178B98  48 2A CB 0D */	bl HSD_GObjProcCreate
/* 8017BD9C 00178B9C  80 9E 11 34 */	lwz r4, 0x1134(r30)
/* 8017BDA0 00178BA0  7F E3 FB 78 */	mr r3, r31
/* 8017BDA4 00178BA4  C0 22 A6 10 */	lfs f1, lbl_805E0D10@sda21(r0)
/* 8017BDA8 00178BA8  80 84 00 00 */	lwz r4, 0x0(r4)
/* 8017BDAC 00178BAC  C0 42 A6 14 */	lfs f2, lbl_805E0D14@sda21(r0)
/* 8017BDB0 00178BB0  4B FB CC 29 */	bl fn_801389D8
/* 8017BDB4 00178BB4  7F A3 EB 78 */	mr r3, r29
/* 8017BDB8 00178BB8  38 80 00 BA */	li r4, 0xba
/* 8017BDBC 00178BBC  4B FB CC 45 */	bl kar_diag__80138a00
/* 8017BDC0 00178BC0  7C 7F 1B 78 */	mr r31, r3
/* 8017BDC4 00178BC4  7F A3 EB 78 */	mr r3, r29
/* 8017BDC8 00178BC8  38 80 00 01 */	li r4, 0x1
/* 8017BDCC 00178BCC  4B ED 9D 25 */	bl kar_lbairride__near_80055af0
/* 8017BDD0 00178BD0  90 7F 00 0C */	stw r3, 0xc(r31)
/* 8017BDD4 00178BD4  7F A3 EB 78 */	mr r3, r29
/* 8017BDD8 00178BD8  38 80 00 02 */	li r4, 0x2
/* 8017BDDC 00178BDC  4B ED 9D 15 */	bl kar_lbairride__near_80055af0
/* 8017BDE0 00178BE0  90 7F 00 10 */	stw r3, 0x10(r31)
/* 8017BDE4 00178BE4  7F A3 EB 78 */	mr r3, r29
/* 8017BDE8 00178BE8  38 80 00 03 */	li r4, 0x3
/* 8017BDEC 00178BEC  4B ED 9D 05 */	bl kar_lbairride__near_80055af0
/* 8017BDF0 00178BF0  90 7F 00 14 */	stw r3, 0x14(r31)
/* 8017BDF4 00178BF4  7F A3 EB 78 */	mr r3, r29
/* 8017BDF8 00178BF8  38 80 00 04 */	li r4, 0x4
/* 8017BDFC 00178BFC  4B ED 9C F5 */	bl kar_lbairride__near_80055af0
/* 8017BE00 00178C00  90 7F 00 18 */	stw r3, 0x18(r31)
/* 8017BE04 00178C04  7F A3 EB 78 */	mr r3, r29
/* 8017BE08 00178C08  38 80 00 05 */	li r4, 0x5
/* 8017BE0C 00178C0C  4B ED 9C E5 */	bl kar_lbairride__near_80055af0
/* 8017BE10 00178C10  90 7F 00 1C */	stw r3, 0x1c(r31)
/* 8017BE14 00178C14  7F A3 EB 78 */	mr r3, r29
/* 8017BE18 00178C18  38 80 00 06 */	li r4, 0x6
/* 8017BE1C 00178C1C  4B ED 9C D5 */	bl kar_lbairride__near_80055af0
/* 8017BE20 00178C20  90 7F 00 20 */	stw r3, 0x20(r31)
/* 8017BE24 00178C24  7F A3 EB 78 */	mr r3, r29
/* 8017BE28 00178C28  38 80 00 07 */	li r4, 0x7
/* 8017BE2C 00178C2C  4B ED 9C C5 */	bl kar_lbairride__near_80055af0
/* 8017BE30 00178C30  90 7F 00 24 */	stw r3, 0x24(r31)
/* 8017BE34 00178C34  7F A3 EB 78 */	mr r3, r29
/* 8017BE38 00178C38  38 80 00 08 */	li r4, 0x8
/* 8017BE3C 00178C3C  4B ED 9C B5 */	bl kar_lbairride__near_80055af0
/* 8017BE40 00178C40  90 7F 00 28 */	stw r3, 0x28(r31)
/* 8017BE44 00178C44  7F A3 EB 78 */	mr r3, r29
/* 8017BE48 00178C48  38 80 00 09 */	li r4, 0x9
/* 8017BE4C 00178C4C  4B ED 9C A5 */	bl kar_lbairride__near_80055af0
/* 8017BE50 00178C50  90 7F 00 2C */	stw r3, 0x2c(r31)
/* 8017BE54 00178C54  7F A3 EB 78 */	mr r3, r29
/* 8017BE58 00178C58  38 80 00 0A */	li r4, 0xa
/* 8017BE5C 00178C5C  4B ED 9C 95 */	bl kar_lbairride__near_80055af0
/* 8017BE60 00178C60  90 7F 00 30 */	stw r3, 0x30(r31)
/* 8017BE64 00178C64  93 BE 11 38 */	stw r29, 0x1138(r30)
/* 8017BE68 00178C68  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8017BE6C 00178C6C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8017BE70 00178C70  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8017BE74 00178C74  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8017BE78 00178C78  7C 08 03 A6 */	mtlr r0
/* 8017BE7C 00178C7C  38 21 00 20 */	addi r1, r1, 0x20
/* 8017BE80 00178C80  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_create_bg_panel_and_cache_child_jobjs

# .text:0x70C | 0x8017BE84 | size: 0x44
.fn kar_mndialoguebg_destroy_bg_panel, global
/* 8017BE84 00178C84  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017BE88 00178C88  7C 08 02 A6 */	mflr r0
/* 8017BE8C 00178C8C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017BE90 00178C90  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8017BE94 00178C94  4B FB 53 4D */	bl fn_801311E0
/* 8017BE98 00178C98  7C 7F 1B 78 */	mr r31, r3
/* 8017BE9C 00178C9C  80 63 11 38 */	lwz r3, 0x1138(r3)
/* 8017BEA0 00178CA0  28 03 00 00 */	cmplwi r3, 0x0
/* 8017BEA4 00178CA4  41 82 00 10 */	beq .L_8017BEB4
/* 8017BEA8 00178CA8  48 2A D0 BD */	bl HSD_GObjDestroy
/* 8017BEAC 00178CAC  38 00 00 00 */	li r0, 0x0
/* 8017BEB0 00178CB0  90 1F 11 38 */	stw r0, 0x1138(r31)
.L_8017BEB4:
/* 8017BEB4 00178CB4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017BEB8 00178CB8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8017BEBC 00178CBC  7C 08 03 A6 */	mtlr r0
/* 8017BEC0 00178CC0  38 21 00 10 */	addi r1, r1, 0x10
/* 8017BEC4 00178CC4  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_destroy_bg_panel

# .text:0x750 | 0x8017BEC8 | size: 0x58
.fn kar_mndialoguebg_request_cursor_slot_closed_anim, global
/* 8017BEC8 00178CC8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017BECC 00178CCC  7C 08 02 A6 */	mflr r0
/* 8017BED0 00178CD0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017BED4 00178CD4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8017BED8 00178CD8  7C 7F 1B 78 */	mr r31, r3
/* 8017BEDC 00178CDC  4B FB 53 05 */	bl fn_801311E0
/* 8017BEE0 00178CE0  57 E0 10 3A */	slwi r0, r31, 2
/* 8017BEE4 00178CE4  7C 63 02 14 */	add r3, r3, r0
/* 8017BEE8 00178CE8  80 63 11 40 */	lwz r3, 0x1140(r3)
/* 8017BEEC 00178CEC  28 03 00 00 */	cmplwi r3, 0x0
/* 8017BEF0 00178CF0  41 82 00 1C */	beq .L_8017BF0C
/* 8017BEF4 00178CF4  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 8017BEF8 00178CF8  C0 22 A6 18 */	lfs f1, lbl_805E0D18@sda21(r0)
/* 8017BEFC 00178CFC  7F E3 FB 78 */	mr r3, r31
/* 8017BF00 00178D00  48 28 D3 51 */	bl HSD_JObjReqAnimAll
/* 8017BF04 00178D04  7F E3 FB 78 */	mr r3, r31
/* 8017BF08 00178D08  48 28 E2 99 */	bl HSD_JObjAnim
.L_8017BF0C:
/* 8017BF0C 00178D0C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017BF10 00178D10  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8017BF14 00178D14  7C 08 03 A6 */	mtlr r0
/* 8017BF18 00178D18  38 21 00 10 */	addi r1, r1, 0x10
/* 8017BF1C 00178D1C  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_request_cursor_slot_closed_anim

# .text:0x7A8 | 0x8017BF20 | size: 0x58
.fn kar_mndialoguebg_request_cursor_slot_open_anim, global
/* 8017BF20 00178D20  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017BF24 00178D24  7C 08 02 A6 */	mflr r0
/* 8017BF28 00178D28  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017BF2C 00178D2C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8017BF30 00178D30  7C 7F 1B 78 */	mr r31, r3
/* 8017BF34 00178D34  4B FB 52 AD */	bl fn_801311E0
/* 8017BF38 00178D38  57 E0 10 3A */	slwi r0, r31, 2
/* 8017BF3C 00178D3C  7C 63 02 14 */	add r3, r3, r0
/* 8017BF40 00178D40  80 63 11 40 */	lwz r3, 0x1140(r3)
/* 8017BF44 00178D44  28 03 00 00 */	cmplwi r3, 0x0
/* 8017BF48 00178D48  41 82 00 1C */	beq .L_8017BF64
/* 8017BF4C 00178D4C  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 8017BF50 00178D50  C0 22 A6 1C */	lfs f1, lbl_805E0D1C@sda21(r0)
/* 8017BF54 00178D54  7F E3 FB 78 */	mr r3, r31
/* 8017BF58 00178D58  48 28 D2 F9 */	bl HSD_JObjReqAnimAll
/* 8017BF5C 00178D5C  7F E3 FB 78 */	mr r3, r31
/* 8017BF60 00178D60  48 28 E2 41 */	bl HSD_JObjAnim
.L_8017BF64:
/* 8017BF64 00178D64  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017BF68 00178D68  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8017BF6C 00178D6C  7C 08 03 A6 */	mtlr r0
/* 8017BF70 00178D70  38 21 00 10 */	addi r1, r1, 0x10
/* 8017BF74 00178D74  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_request_cursor_slot_open_anim

# .text:0x800 | 0x8017BF78 | size: 0xF0
.fn kar_mndialoguebg_proc_align_cursor_slots_to_bg_children, global
/* 8017BF78 00178D78  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8017BF7C 00178D7C  7C 08 02 A6 */	mflr r0
/* 8017BF80 00178D80  90 01 00 34 */	stw r0, 0x34(r1)
/* 8017BF84 00178D84  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 8017BF88 00178D88  93 C1 00 28 */	stw r30, 0x28(r1)
/* 8017BF8C 00178D8C  93 A1 00 24 */	stw r29, 0x24(r1)
/* 8017BF90 00178D90  4B FB 52 51 */	bl fn_801311E0
/* 8017BF94 00178D94  3B A0 00 00 */	li r29, 0x0
/* 8017BF98 00178D98  3B E3 11 3C */	addi r31, r3, 0x113c
.L_8017BF9C:
/* 8017BF9C 00178D9C  80 7F 00 04 */	lwz r3, 0x4(r31)
/* 8017BFA0 00178DA0  28 03 00 00 */	cmplwi r3, 0x0
/* 8017BFA4 00178DA4  41 82 00 98 */	beq .L_8017C03C
/* 8017BFA8 00178DA8  83 C3 00 28 */	lwz r30, 0x28(r3)
/* 8017BFAC 00178DAC  7F A3 07 74 */	extsb r3, r29
/* 8017BFB0 00178DB0  38 81 00 08 */	addi r4, r1, 0x8
/* 8017BFB4 00178DB4  4B FF F6 A1 */	bl kar_mndialoguebg_get_child_screen_translation_by_index
/* 8017BFB8 00178DB8  28 1E 00 00 */	cmplwi r30, 0x0
/* 8017BFBC 00178DBC  40 82 00 14 */	bne .L_8017BFD0
/* 8017BFC0 00178DC0  38 6D 9D 08 */	li r3, kar_srcfile_jobj_h_805d6de8@sda21
/* 8017BFC4 00178DC4  38 80 03 A9 */	li r4, 0x3a9
/* 8017BFC8 00178DC8  38 AD 9D 10 */	li r5, lbl_805D6DF0@sda21
/* 8017BFCC 00178DCC  48 2A C4 ED */	bl __assert
.L_8017BFD0:
/* 8017BFD0 00178DD0  80 61 00 08 */	lwz r3, 0x8(r1)
/* 8017BFD4 00178DD4  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017BFD8 00178DD8  90 7E 00 38 */	stw r3, 0x38(r30)
/* 8017BFDC 00178DDC  90 1E 00 3C */	stw r0, 0x3c(r30)
/* 8017BFE0 00178DE0  80 01 00 10 */	lwz r0, 0x10(r1)
/* 8017BFE4 00178DE4  90 1E 00 40 */	stw r0, 0x40(r30)
/* 8017BFE8 00178DE8  80 1E 00 14 */	lwz r0, 0x14(r30)
/* 8017BFEC 00178DEC  54 00 01 8D */	rlwinm. r0, r0, 0, 6, 6
/* 8017BFF0 00178DF0  40 82 00 4C */	bne .L_8017C03C
/* 8017BFF4 00178DF4  28 1E 00 00 */	cmplwi r30, 0x0
/* 8017BFF8 00178DF8  41 82 00 44 */	beq .L_8017C03C
/* 8017BFFC 00178DFC  40 82 00 14 */	bne .L_8017C010
/* 8017C000 00178E00  38 6D 9D 08 */	li r3, kar_srcfile_jobj_h_805d6de8@sda21
/* 8017C004 00178E04  38 80 02 5D */	li r4, 0x25d
/* 8017C008 00178E08  38 AD 9D 10 */	li r5, lbl_805D6DF0@sda21
/* 8017C00C 00178E0C  48 2A C4 AD */	bl __assert
.L_8017C010:
/* 8017C010 00178E10  80 9E 00 14 */	lwz r4, 0x14(r30)
/* 8017C014 00178E14  38 60 00 00 */	li r3, 0x0
/* 8017C018 00178E18  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 8017C01C 00178E1C  40 82 00 10 */	bne .L_8017C02C
/* 8017C020 00178E20  54 80 06 73 */	rlwinm. r0, r4, 0, 25, 25
/* 8017C024 00178E24  41 82 00 08 */	beq .L_8017C02C
/* 8017C028 00178E28  38 60 00 01 */	li r3, 0x1
.L_8017C02C:
/* 8017C02C 00178E2C  2C 03 00 00 */	cmpwi r3, 0x0
/* 8017C030 00178E30  40 82 00 0C */	bne .L_8017C03C
/* 8017C034 00178E34  7F C3 F3 78 */	mr r3, r30
/* 8017C038 00178E38  48 29 18 F5 */	bl HSD_JObjSetMtxDirtySub
.L_8017C03C:
/* 8017C03C 00178E3C  3B BD 00 01 */	addi r29, r29, 0x1
/* 8017C040 00178E40  3B FF 00 04 */	addi r31, r31, 0x4
/* 8017C044 00178E44  2C 1D 00 02 */	cmpwi r29, 0x2
/* 8017C048 00178E48  41 80 FF 54 */	blt .L_8017BF9C
/* 8017C04C 00178E4C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8017C050 00178E50  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 8017C054 00178E54  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 8017C058 00178E58  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 8017C05C 00178E5C  7C 08 03 A6 */	mtlr r0
/* 8017C060 00178E60  38 21 00 30 */	addi r1, r1, 0x30
/* 8017C064 00178E64  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_proc_align_cursor_slots_to_bg_children

# .text:0x8F0 | 0x8017C068 | size: 0x44
.fn kar_mndialoguebg_hide_cursor_slot, global
/* 8017C068 00178E68  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017C06C 00178E6C  7C 08 02 A6 */	mflr r0
/* 8017C070 00178E70  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017C074 00178E74  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8017C078 00178E78  7C 7F 1B 78 */	mr r31, r3
/* 8017C07C 00178E7C  4B FB 51 65 */	bl fn_801311E0
/* 8017C080 00178E80  57 E0 10 3A */	slwi r0, r31, 2
/* 8017C084 00178E84  7C 63 02 14 */	add r3, r3, r0
/* 8017C088 00178E88  80 63 11 40 */	lwz r3, 0x1140(r3)
/* 8017C08C 00178E8C  28 03 00 00 */	cmplwi r3, 0x0
/* 8017C090 00178E90  41 82 00 08 */	beq .L_8017C098
/* 8017C094 00178E94  4B FB CA 1D */	bl kar_menu_gobj_userdata_hide
.L_8017C098:
/* 8017C098 00178E98  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017C09C 00178E9C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8017C0A0 00178EA0  7C 08 03 A6 */	mtlr r0
/* 8017C0A4 00178EA4  38 21 00 10 */	addi r1, r1, 0x10
/* 8017C0A8 00178EA8  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_hide_cursor_slot

# .text:0x934 | 0x8017C0AC | size: 0x44
.fn kar_mndialoguebg_show_cursor_slot, global
/* 8017C0AC 00178EAC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017C0B0 00178EB0  7C 08 02 A6 */	mflr r0
/* 8017C0B4 00178EB4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017C0B8 00178EB8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8017C0BC 00178EBC  7C 7F 1B 78 */	mr r31, r3
/* 8017C0C0 00178EC0  4B FB 51 21 */	bl fn_801311E0
/* 8017C0C4 00178EC4  57 E0 10 3A */	slwi r0, r31, 2
/* 8017C0C8 00178EC8  7C 63 02 14 */	add r3, r3, r0
/* 8017C0CC 00178ECC  80 63 11 40 */	lwz r3, 0x1140(r3)
/* 8017C0D0 00178ED0  28 03 00 00 */	cmplwi r3, 0x0
/* 8017C0D4 00178ED4  41 82 00 08 */	beq .L_8017C0DC
/* 8017C0D8 00178ED8  4B FB C9 F1 */	bl kar_menu_gobj_userdata_show
.L_8017C0DC:
/* 8017C0DC 00178EDC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017C0E0 00178EE0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8017C0E4 00178EE4  7C 08 03 A6 */	mtlr r0
/* 8017C0E8 00178EE8  38 21 00 10 */	addi r1, r1, 0x10
/* 8017C0EC 00178EEC  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_show_cursor_slot

# .text:0x978 | 0x8017C0F0 | size: 0x4
.fn fn_8017C0F0, global
/* 8017C0F0 00178EF0  4E 80 00 20 */	blr
.endfn fn_8017C0F0

# .text:0x97C | 0x8017C0F4 | size: 0x4C
.fn kar_mndialoguebg_load_cursor_scene_models, global
/* 8017C0F4 00178EF4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017C0F8 00178EF8  7C 08 02 A6 */	mflr r0
/* 8017C0FC 00178EFC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017C100 00178F00  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8017C104 00178F04  4B FB 50 DD */	bl fn_801311E0
/* 8017C108 00178F08  7C 7F 1B 78 */	mr r31, r3
/* 8017C10C 00178F0C  4B FB CD 19 */	bl fn_80138E24
/* 8017C110 00178F10  3C 80 80 4B */	lis r4, kar_mndialoguebg_cursor_scene_models_name@ha
/* 8017C114 00178F14  80 63 00 00 */	lwz r3, 0x0(r3)
/* 8017C118 00178F18  38 A4 D1 F0 */	addi r5, r4, kar_mndialoguebg_cursor_scene_models_name@l
/* 8017C11C 00178F1C  38 C0 00 00 */	li r6, 0x0
/* 8017C120 00178F20  38 9F 11 3C */	addi r4, r31, 0x113c
/* 8017C124 00178F24  4C C6 31 82 */	crclr cr1eq
/* 8017C128 00178F28  4B ED D3 F9 */	bl kar_lbarchive__near_80059520
/* 8017C12C 00178F2C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017C130 00178F30  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8017C134 00178F34  7C 08 03 A6 */	mtlr r0
/* 8017C138 00178F38  38 21 00 10 */	addi r1, r1, 0x10
/* 8017C13C 00178F3C  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_load_cursor_scene_models

# .text:0x9C8 | 0x8017C140 | size: 0x9C
.fn kar_mndialoguebg_create_cursor_slots, global
/* 8017C140 00178F40  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8017C144 00178F44  7C 08 02 A6 */	mflr r0
/* 8017C148 00178F48  90 01 00 24 */	stw r0, 0x24(r1)
/* 8017C14C 00178F4C  39 61 00 20 */	addi r11, r1, 0x20
/* 8017C150 00178F50  48 23 1A 01 */	bl _savegpr_26
/* 8017C154 00178F54  4B FB 50 8D */	bl fn_801311E0
/* 8017C158 00178F58  3B A3 11 3C */	addi r29, r3, 0x113c
/* 8017C15C 00178F5C  3C 60 80 18 */	lis r3, fn_8017C0F0@ha
/* 8017C160 00178F60  7F BE EB 78 */	mr r30, r29
/* 8017C164 00178F64  3B 40 00 00 */	li r26, 0x0
/* 8017C168 00178F68  3B E3 C0 F0 */	addi r31, r3, fn_8017C0F0@l
.L_8017C16C:
/* 8017C16C 00178F6C  80 7D 00 00 */	lwz r3, 0x0(r29)
/* 8017C170 00178F70  80 63 00 00 */	lwz r3, 0x0(r3)
/* 8017C174 00178F74  80 63 00 00 */	lwz r3, 0x0(r3)
/* 8017C178 00178F78  4B FB C7 31 */	bl fn_801388A8
/* 8017C17C 00178F7C  83 63 00 28 */	lwz r27, 0x28(r3)
/* 8017C180 00178F80  7F E4 FB 78 */	mr r4, r31
/* 8017C184 00178F84  7C 7C 1B 78 */	mr r28, r3
/* 8017C188 00178F88  38 A0 00 01 */	li r5, 0x1
/* 8017C18C 00178F8C  48 2A C7 19 */	bl HSD_GObjProcCreate
/* 8017C190 00178F90  80 9D 00 00 */	lwz r4, 0x0(r29)
/* 8017C194 00178F94  7F 63 DB 78 */	mr r3, r27
/* 8017C198 00178F98  C0 22 A6 18 */	lfs f1, lbl_805E0D18@sda21(r0)
/* 8017C19C 00178F9C  80 84 00 00 */	lwz r4, 0x0(r4)
/* 8017C1A0 00178FA0  C0 42 A6 1C */	lfs f2, lbl_805E0D1C@sda21(r0)
/* 8017C1A4 00178FA4  4B FB C8 35 */	bl fn_801389D8
/* 8017C1A8 00178FA8  7F 83 E3 78 */	mr r3, r28
/* 8017C1AC 00178FAC  38 80 00 BB */	li r4, 0xbb
/* 8017C1B0 00178FB0  4B FB C8 51 */	bl kar_diag__80138a00
/* 8017C1B4 00178FB4  3B 5A 00 01 */	addi r26, r26, 0x1
/* 8017C1B8 00178FB8  97 9E 00 04 */	stwu r28, 0x4(r30)
/* 8017C1BC 00178FBC  2C 1A 00 02 */	cmpwi r26, 0x2
/* 8017C1C0 00178FC0  41 80 FF AC */	blt .L_8017C16C
/* 8017C1C4 00178FC4  39 61 00 20 */	addi r11, r1, 0x20
/* 8017C1C8 00178FC8  48 23 19 D5 */	bl _restgpr_26
/* 8017C1CC 00178FCC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8017C1D0 00178FD0  7C 08 03 A6 */	mtlr r0
/* 8017C1D4 00178FD4  38 21 00 20 */	addi r1, r1, 0x20
/* 8017C1D8 00178FD8  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_create_cursor_slots

# .text:0xA64 | 0x8017C1DC | size: 0x68
.fn kar_mndialoguebg_destroy_cursor_slots, global
/* 8017C1DC 00178FDC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8017C1E0 00178FE0  7C 08 02 A6 */	mflr r0
/* 8017C1E4 00178FE4  90 01 00 24 */	stw r0, 0x24(r1)
/* 8017C1E8 00178FE8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8017C1EC 00178FEC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8017C1F0 00178FF0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8017C1F4 00178FF4  4B FB 4F ED */	bl fn_801311E0
/* 8017C1F8 00178FF8  3B C3 11 3C */	addi r30, r3, 0x113c
/* 8017C1FC 00178FFC  3B A0 00 00 */	li r29, 0x0
/* 8017C200 00179000  3B E0 00 00 */	li r31, 0x0
.L_8017C204:
/* 8017C204 00179004  80 7E 00 04 */	lwz r3, 0x4(r30)
/* 8017C208 00179008  28 03 00 00 */	cmplwi r3, 0x0
/* 8017C20C 0017900C  41 82 00 0C */	beq .L_8017C218
/* 8017C210 00179010  48 2A CD 55 */	bl HSD_GObjDestroy
/* 8017C214 00179014  93 FE 00 04 */	stw r31, 0x4(r30)
.L_8017C218:
/* 8017C218 00179018  3B BD 00 01 */	addi r29, r29, 0x1
/* 8017C21C 0017901C  3B DE 00 04 */	addi r30, r30, 0x4
/* 8017C220 00179020  2C 1D 00 02 */	cmpwi r29, 0x2
/* 8017C224 00179024  41 80 FF E0 */	blt .L_8017C204
/* 8017C228 00179028  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8017C22C 0017902C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8017C230 00179030  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8017C234 00179034  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8017C238 00179038  7C 08 03 A6 */	mtlr r0
/* 8017C23C 0017903C  38 21 00 20 */	addi r1, r1, 0x20
/* 8017C240 00179040  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_destroy_cursor_slots

# .text:0xACC | 0x8017C244 | size: 0x14C
.fn kar_mndialoguebg_destroy_all_sis_text_windows, global
/* 8017C244 00179044  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8017C248 00179048  7C 08 02 A6 */	mflr r0
/* 8017C24C 0017904C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8017C250 00179050  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8017C254 00179054  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8017C258 00179058  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8017C25C 0017905C  93 81 00 10 */	stw r28, 0x10(r1)
/* 8017C260 00179060  4B FB 4F 81 */	bl fn_801311E0
/* 8017C264 00179064  3B E3 00 28 */	addi r31, r3, 0x28
/* 8017C268 00179068  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8017C26C 0017906C  28 03 00 00 */	cmplwi r3, 0x0
/* 8017C270 00179070  41 82 00 10 */	beq .L_8017C280
/* 8017C274 00179074  48 2D 30 DD */	bl HSD_SisLib_803A5CC4
/* 8017C278 00179078  38 00 00 00 */	li r0, 0x0
/* 8017C27C 0017907C  90 1F 00 04 */	stw r0, 0x4(r31)
.L_8017C280:
/* 8017C280 00179080  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 8017C284 00179084  28 03 00 00 */	cmplwi r3, 0x0
/* 8017C288 00179088  41 82 00 10 */	beq .L_8017C298
/* 8017C28C 0017908C  48 2D 30 C5 */	bl HSD_SisLib_803A5CC4
/* 8017C290 00179090  38 00 00 00 */	li r0, 0x0
/* 8017C294 00179094  90 1F 00 08 */	stw r0, 0x8(r31)
.L_8017C298:
/* 8017C298 00179098  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 8017C29C 0017909C  28 03 00 00 */	cmplwi r3, 0x0
/* 8017C2A0 001790A0  41 82 00 10 */	beq .L_8017C2B0
/* 8017C2A4 001790A4  48 2D 30 AD */	bl HSD_SisLib_803A5CC4
/* 8017C2A8 001790A8  38 00 00 00 */	li r0, 0x0
/* 8017C2AC 001790AC  90 1F 00 0C */	stw r0, 0xc(r31)
.L_8017C2B0:
/* 8017C2B0 001790B0  80 7F 00 10 */	lwz r3, 0x10(r31)
/* 8017C2B4 001790B4  28 03 00 00 */	cmplwi r3, 0x0
/* 8017C2B8 001790B8  41 82 00 10 */	beq .L_8017C2C8
/* 8017C2BC 001790BC  48 2D 30 95 */	bl HSD_SisLib_803A5CC4
/* 8017C2C0 001790C0  38 00 00 00 */	li r0, 0x0
/* 8017C2C4 001790C4  90 1F 00 10 */	stw r0, 0x10(r31)
.L_8017C2C8:
/* 8017C2C8 001790C8  80 7F 00 14 */	lwz r3, 0x14(r31)
/* 8017C2CC 001790CC  28 03 00 00 */	cmplwi r3, 0x0
/* 8017C2D0 001790D0  41 82 00 10 */	beq .L_8017C2E0
/* 8017C2D4 001790D4  48 2D 30 7D */	bl HSD_SisLib_803A5CC4
/* 8017C2D8 001790D8  38 00 00 00 */	li r0, 0x0
/* 8017C2DC 001790DC  90 1F 00 14 */	stw r0, 0x14(r31)
.L_8017C2E0:
/* 8017C2E0 001790E0  7F FD FB 78 */	mr r29, r31
/* 8017C2E4 001790E4  3B 80 00 00 */	li r28, 0x0
/* 8017C2E8 001790E8  3B C0 00 00 */	li r30, 0x0
.L_8017C2EC:
/* 8017C2EC 001790EC  80 7D 00 18 */	lwz r3, 0x18(r29)
/* 8017C2F0 001790F0  28 03 00 00 */	cmplwi r3, 0x0
/* 8017C2F4 001790F4  41 82 00 0C */	beq .L_8017C300
/* 8017C2F8 001790F8  48 2D 30 59 */	bl HSD_SisLib_803A5CC4
/* 8017C2FC 001790FC  93 DD 00 18 */	stw r30, 0x18(r29)
.L_8017C300:
/* 8017C300 00179100  3B 9C 00 01 */	addi r28, r28, 0x1
/* 8017C304 00179104  3B BD 00 04 */	addi r29, r29, 0x4
/* 8017C308 00179108  2C 1C 00 08 */	cmpwi r28, 0x8
/* 8017C30C 0017910C  41 80 FF E0 */	blt .L_8017C2EC
/* 8017C310 00179110  3B 80 00 00 */	li r28, 0x0
/* 8017C314 00179114  7F FD FB 78 */	mr r29, r31
/* 8017C318 00179118  7F 9E E3 78 */	mr r30, r28
.L_8017C31C:
/* 8017C31C 0017911C  80 7D 00 38 */	lwz r3, 0x38(r29)
/* 8017C320 00179120  28 03 00 00 */	cmplwi r3, 0x0
/* 8017C324 00179124  41 82 00 0C */	beq .L_8017C330
/* 8017C328 00179128  48 2D 30 29 */	bl HSD_SisLib_803A5CC4
/* 8017C32C 0017912C  93 DD 00 38 */	stw r30, 0x38(r29)
.L_8017C330:
/* 8017C330 00179130  3B 9C 00 01 */	addi r28, r28, 0x1
/* 8017C334 00179134  3B BD 00 04 */	addi r29, r29, 0x4
/* 8017C338 00179138  2C 1C 00 04 */	cmpwi r28, 0x4
/* 8017C33C 0017913C  41 80 FF E0 */	blt .L_8017C31C
/* 8017C340 00179140  3B C0 00 00 */	li r30, 0x0
/* 8017C344 00179144  7F FD FB 78 */	mr r29, r31
/* 8017C348 00179148  7F DF F3 78 */	mr r31, r30
.L_8017C34C:
/* 8017C34C 0017914C  80 7D 00 48 */	lwz r3, 0x48(r29)
/* 8017C350 00179150  28 03 00 00 */	cmplwi r3, 0x0
/* 8017C354 00179154  41 82 00 0C */	beq .L_8017C360
/* 8017C358 00179158  48 2D 2F F9 */	bl HSD_SisLib_803A5CC4
/* 8017C35C 0017915C  93 FD 00 48 */	stw r31, 0x48(r29)
.L_8017C360:
/* 8017C360 00179160  3B DE 00 01 */	addi r30, r30, 0x1
/* 8017C364 00179164  3B BD 00 04 */	addi r29, r29, 0x4
/* 8017C368 00179168  2C 1E 00 08 */	cmpwi r30, 0x8
/* 8017C36C 0017916C  41 80 FF E0 */	blt .L_8017C34C
/* 8017C370 00179170  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8017C374 00179174  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8017C378 00179178  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8017C37C 0017917C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8017C380 00179180  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8017C384 00179184  7C 08 03 A6 */	mtlr r0
/* 8017C388 00179188  38 21 00 20 */	addi r1, r1, 0x20
/* 8017C38C 0017918C  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_destroy_all_sis_text_windows

# .text:0xC18 | 0x8017C390 | size: 0x34
.fn kar_si_assets_load_sisdialogue_dat, global
/* 8017C390 00179190  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017C394 00179194  7C 08 02 A6 */	mflr r0
/* 8017C398 00179198  3C 60 80 4B */	lis r3, kar_mndialoguebg_sisdialogue_dat_name@ha
/* 8017C39C 0017919C  3C A0 80 4B */	lis r5, kar_mndialoguebg_sis_dialogue_group_name@ha
/* 8017C3A0 001791A0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017C3A4 001791A4  38 83 D2 18 */	addi r4, r3, kar_mndialoguebg_sisdialogue_dat_name@l
/* 8017C3A8 001791A8  38 60 00 00 */	li r3, 0x0
/* 8017C3AC 001791AC  38 A5 D2 28 */	addi r5, r5, kar_mndialoguebg_sis_dialogue_group_name@l
/* 8017C3B0 001791B0  48 2D 34 51 */	bl HSD_SisLib_803A62A0
/* 8017C3B4 001791B4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017C3B8 001791B8  7C 08 03 A6 */	mtlr r0
/* 8017C3BC 001791BC  38 21 00 10 */	addi r1, r1, 0x10
/* 8017C3C0 001791C0  4E 80 00 20 */	blr
.endfn kar_si_assets_load_sisdialogue_dat

# .text:0xC4C | 0x8017C3C4 | size: 0x54
.fn kar_mndialoguebg_init_sis_dialogue_text_style, global
/* 8017C3C4 001791C4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017C3C8 001791C8  7C 08 02 A6 */	mflr r0
/* 8017C3CC 001791CC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017C3D0 001791D0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8017C3D4 001791D4  4B FB 4E 0D */	bl fn_801311E0
/* 8017C3D8 001791D8  7C 7F 1B 78 */	mr r31, r3
/* 8017C3DC 001791DC  38 60 00 00 */	li r3, 0x0
/* 8017C3E0 001791E0  38 80 00 00 */	li r4, 0x0
/* 8017C3E4 001791E4  38 A0 00 29 */	li r5, 0x29
/* 8017C3E8 001791E8  38 C0 00 11 */	li r6, 0x11
/* 8017C3EC 001791EC  38 E0 00 00 */	li r7, 0x0
/* 8017C3F0 001791F0  39 00 00 03 */	li r8, 0x3
/* 8017C3F4 001791F4  39 20 00 00 */	li r9, 0x0
/* 8017C3F8 001791F8  39 40 00 05 */	li r10, 0x5
/* 8017C3FC 001791FC  48 2D 32 79 */	bl HSD_SisLib_803A611C
/* 8017C400 00179200  98 7F 00 28 */	stb r3, 0x28(r31)
/* 8017C404 00179204  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017C408 00179208  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8017C40C 0017920C  7C 08 03 A6 */	mtlr r0
/* 8017C410 00179210  38 21 00 10 */	addi r1, r1, 0x10
/* 8017C414 00179214  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_init_sis_dialogue_text_style

# .text:0xCA0 | 0x8017C418 | size: 0x188
.fn kar_mndialoguebg_create_sis_dialogue_text_windows, global
/* 8017C418 00179218  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 8017C41C 0017921C  7C 08 02 A6 */	mflr r0
/* 8017C420 00179220  90 01 00 54 */	stw r0, 0x54(r1)
/* 8017C424 00179224  DB E1 00 40 */	stfd f31, 0x40(r1)
/* 8017C428 00179228  F3 E1 00 48 */	psq_st f31, 0x48(r1), 0, qr0
/* 8017C42C 0017922C  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 8017C430 00179230  4B FB 4D B1 */	bl fn_801311E0
/* 8017C434 00179234  7C 7F 1B 78 */	mr r31, r3
/* 8017C438 00179238  38 61 00 20 */	addi r3, r1, 0x20
/* 8017C43C 0017923C  4B FF F3 3D */	bl kar_mndialoguebg_project_box0_origin_to_screen
/* 8017C440 00179240  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 8017C444 00179244  28 03 00 00 */	cmplwi r3, 0x0
/* 8017C448 00179248  41 82 00 10 */	beq .L_8017C458
/* 8017C44C 0017924C  48 2D 2F 05 */	bl HSD_SisLib_803A5CC4
/* 8017C450 00179250  38 00 00 00 */	li r0, 0x0
/* 8017C454 00179254  90 1F 00 2C */	stw r0, 0x2c(r31)
.L_8017C458:
/* 8017C458 00179258  4B FF F2 E1 */	bl kar_mndialoguebg_get_box0_screen_height
/* 8017C45C 0017925C  FF E0 08 90 */	fmr f31, f1
/* 8017C460 00179260  4B FF F2 99 */	bl kar_mndialoguebg_get_box0_screen_width
/* 8017C464 00179264  FC 80 08 90 */	fmr f4, f1
/* 8017C468 00179268  88 9F 00 28 */	lbz r4, 0x28(r31)
/* 8017C46C 0017926C  FC A0 F8 90 */	fmr f5, f31
/* 8017C470 00179270  C0 21 00 20 */	lfs f1, 0x20(r1)
/* 8017C474 00179274  C0 41 00 24 */	lfs f2, 0x24(r1)
/* 8017C478 00179278  38 60 00 00 */	li r3, 0x0
/* 8017C47C 0017927C  C0 62 A6 20 */	lfs f3, lbl_805E0D20@sda21(r0)
/* 8017C480 00179280  48 2D 2C A9 */	bl HSD_SisLib_803A5ACC
/* 8017C484 00179284  90 7F 00 2C */	stw r3, 0x2c(r31)
/* 8017C488 00179288  38 00 00 00 */	li r0, 0x0
/* 8017C48C 0017928C  C0 02 A6 24 */	lfs f0, lbl_805E0D24@sda21(r0)
/* 8017C490 00179290  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 8017C494 00179294  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 8017C498 00179298  98 03 00 4C */	stb r0, 0x4c(r3)
/* 8017C49C 0017929C  4B FB 4D 45 */	bl fn_801311E0
/* 8017C4A0 001792A0  7C 7F 1B 78 */	mr r31, r3
/* 8017C4A4 001792A4  38 61 00 14 */	addi r3, r1, 0x14
/* 8017C4A8 001792A8  4B FF F5 6D */	bl kar_mndialoguebg_project_box1_origin_to_screen
/* 8017C4AC 001792AC  80 7F 00 30 */	lwz r3, 0x30(r31)
/* 8017C4B0 001792B0  28 03 00 00 */	cmplwi r3, 0x0
/* 8017C4B4 001792B4  41 82 00 10 */	beq .L_8017C4C4
/* 8017C4B8 001792B8  48 2D 2E 99 */	bl HSD_SisLib_803A5CC4
/* 8017C4BC 001792BC  38 00 00 00 */	li r0, 0x0
/* 8017C4C0 001792C0  90 1F 00 30 */	stw r0, 0x30(r31)
.L_8017C4C4:
/* 8017C4C4 001792C4  4B FF F5 11 */	bl kar_mndialoguebg_get_box1_screen_height
/* 8017C4C8 001792C8  FF E0 08 90 */	fmr f31, f1
/* 8017C4CC 001792CC  4B FF F4 C9 */	bl kar_mndialoguebg_get_box1_screen_width
/* 8017C4D0 001792D0  C0 42 A6 28 */	lfs f2, lbl_805E0D28@sda21(r0)
/* 8017C4D4 001792D4  FC 80 08 90 */	fmr f4, f1
/* 8017C4D8 001792D8  C0 01 00 18 */	lfs f0, 0x18(r1)
/* 8017C4DC 001792DC  FC A0 F8 90 */	fmr f5, f31
/* 8017C4E0 001792E0  88 9F 00 28 */	lbz r4, 0x28(r31)
/* 8017C4E4 001792E4  38 60 00 00 */	li r3, 0x0
/* 8017C4E8 001792E8  EC 42 00 2A */	fadds f2, f2, f0
/* 8017C4EC 001792EC  C0 21 00 14 */	lfs f1, 0x14(r1)
/* 8017C4F0 001792F0  C0 62 A6 20 */	lfs f3, lbl_805E0D20@sda21(r0)
/* 8017C4F4 001792F4  48 2D 2C 35 */	bl HSD_SisLib_803A5ACC
/* 8017C4F8 001792F8  90 7F 00 30 */	stw r3, 0x30(r31)
/* 8017C4FC 001792FC  38 00 00 00 */	li r0, 0x0
/* 8017C500 00179300  C0 02 A6 24 */	lfs f0, lbl_805E0D24@sda21(r0)
/* 8017C504 00179304  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 8017C508 00179308  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 8017C50C 0017930C  98 03 00 4C */	stb r0, 0x4c(r3)
/* 8017C510 00179310  4B FB 4C D1 */	bl fn_801311E0
/* 8017C514 00179314  7C 7F 1B 78 */	mr r31, r3
/* 8017C518 00179318  38 61 00 08 */	addi r3, r1, 0x8
/* 8017C51C 0017931C  4B FF F7 15 */	bl kar_mndialoguebg_project_box2_origin_to_screen
/* 8017C520 00179320  80 7F 00 34 */	lwz r3, 0x34(r31)
/* 8017C524 00179324  28 03 00 00 */	cmplwi r3, 0x0
/* 8017C528 00179328  41 82 00 10 */	beq .L_8017C538
/* 8017C52C 0017932C  48 2D 2E 25 */	bl HSD_SisLib_803A5CC4
/* 8017C530 00179330  38 00 00 00 */	li r0, 0x0
/* 8017C534 00179334  90 1F 00 34 */	stw r0, 0x34(r31)
.L_8017C538:
/* 8017C538 00179338  4B FF F4 9D */	bl kar_mndialoguebg_get_box1_screen_height
/* 8017C53C 0017933C  FF E0 08 90 */	fmr f31, f1
/* 8017C540 00179340  4B FF F4 55 */	bl kar_mndialoguebg_get_box1_screen_width
/* 8017C544 00179344  C0 42 A6 28 */	lfs f2, lbl_805E0D28@sda21(r0)
/* 8017C548 00179348  FC 80 08 90 */	fmr f4, f1
/* 8017C54C 0017934C  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8017C550 00179350  FC A0 F8 90 */	fmr f5, f31
/* 8017C554 00179354  88 9F 00 28 */	lbz r4, 0x28(r31)
/* 8017C558 00179358  38 60 00 00 */	li r3, 0x0
/* 8017C55C 0017935C  EC 42 00 2A */	fadds f2, f2, f0
/* 8017C560 00179360  C0 21 00 08 */	lfs f1, 0x8(r1)
/* 8017C564 00179364  C0 62 A6 20 */	lfs f3, lbl_805E0D20@sda21(r0)
/* 8017C568 00179368  48 2D 2B C1 */	bl HSD_SisLib_803A5ACC
/* 8017C56C 0017936C  90 7F 00 34 */	stw r3, 0x34(r31)
/* 8017C570 00179370  38 00 00 00 */	li r0, 0x0
/* 8017C574 00179374  C0 02 A6 24 */	lfs f0, lbl_805E0D24@sda21(r0)
/* 8017C578 00179378  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 8017C57C 0017937C  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 8017C580 00179380  98 03 00 4C */	stb r0, 0x4c(r3)
/* 8017C584 00179384  E3 E1 00 48 */	psq_l f31, 0x48(r1), 0, qr0
/* 8017C588 00179388  80 01 00 54 */	lwz r0, 0x54(r1)
/* 8017C58C 0017938C  CB E1 00 40 */	lfd f31, 0x40(r1)
/* 8017C590 00179390  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 8017C594 00179394  7C 08 03 A6 */	mtlr r0
/* 8017C598 00179398  38 21 00 50 */	addi r1, r1, 0x50
/* 8017C59C 0017939C  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_create_sis_dialogue_text_windows

# .text:0xE28 | 0x8017C5A0 | size: 0x38
.fn kar_mndialoguebg_set_sis_dialogue_box0_message_id, global
/* 8017C5A0 001793A0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017C5A4 001793A4  7C 08 02 A6 */	mflr r0
/* 8017C5A8 001793A8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017C5AC 001793AC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8017C5B0 001793B0  7C 7F 1B 78 */	mr r31, r3
/* 8017C5B4 001793B4  4B FB 4C 2D */	bl fn_801311E0
/* 8017C5B8 001793B8  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8017C5BC 001793BC  7F E4 07 74 */	extsb r4, r31
/* 8017C5C0 001793C0  48 2D 33 09 */	bl HSD_SisLib_803A6368
/* 8017C5C4 001793C4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017C5C8 001793C8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8017C5CC 001793CC  7C 08 03 A6 */	mtlr r0
/* 8017C5D0 001793D0  38 21 00 10 */	addi r1, r1, 0x10
/* 8017C5D4 001793D4  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_set_sis_dialogue_box0_message_id

# .text:0xE60 | 0x8017C5D8 | size: 0x38
.fn kar_mndialoguebg_set_sis_dialogue_box1_message_id, global
/* 8017C5D8 001793D8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017C5DC 001793DC  7C 08 02 A6 */	mflr r0
/* 8017C5E0 001793E0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017C5E4 001793E4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8017C5E8 001793E8  7C 7F 1B 78 */	mr r31, r3
/* 8017C5EC 001793EC  4B FB 4B F5 */	bl fn_801311E0
/* 8017C5F0 001793F0  80 63 00 30 */	lwz r3, 0x30(r3)
/* 8017C5F4 001793F4  7F E4 07 74 */	extsb r4, r31
/* 8017C5F8 001793F8  48 2D 32 D1 */	bl HSD_SisLib_803A6368
/* 8017C5FC 001793FC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017C600 00179400  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8017C604 00179404  7C 08 03 A6 */	mtlr r0
/* 8017C608 00179408  38 21 00 10 */	addi r1, r1, 0x10
/* 8017C60C 0017940C  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_set_sis_dialogue_box1_message_id

# .text:0xE98 | 0x8017C610 | size: 0x38
.fn kar_mndialoguebg_set_sis_dialogue_box2_message_id, global
/* 8017C610 00179410  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017C614 00179414  7C 08 02 A6 */	mflr r0
/* 8017C618 00179418  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017C61C 0017941C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8017C620 00179420  7C 7F 1B 78 */	mr r31, r3
/* 8017C624 00179424  4B FB 4B BD */	bl fn_801311E0
/* 8017C628 00179428  80 63 00 34 */	lwz r3, 0x34(r3)
/* 8017C62C 0017942C  7F E4 07 74 */	extsb r4, r31
/* 8017C630 00179430  48 2D 32 99 */	bl HSD_SisLib_803A6368
/* 8017C634 00179434  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017C638 00179438  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8017C63C 0017943C  7C 08 03 A6 */	mtlr r0
/* 8017C640 00179440  38 21 00 10 */	addi r1, r1, 0x10
/* 8017C644 00179444  4E 80 00 20 */	blr
.endfn kar_mndialoguebg_set_sis_dialogue_box2_message_id

# .text:0xED0 | 0x8017C648 | size: 0x30
.fn kar_si_assets_load_sislan_dat, global
/* 8017C648 00179448  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017C64C 0017944C  7C 08 02 A6 */	mflr r0
/* 8017C650 00179450  3C 80 80 4B */	lis r4, kar_gmlanmenu_sislan_dat_name@ha
/* 8017C654 00179454  38 60 00 00 */	li r3, 0x0
/* 8017C658 00179458  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017C65C 0017945C  38 84 D2 38 */	addi r4, r4, kar_gmlanmenu_sislan_dat_name@l
/* 8017C660 00179460  38 AD 9D 18 */	li r5, lbl_805D6DF8@sda21
/* 8017C664 00179464  48 2D 31 9D */	bl HSD_SisLib_803A62A0
/* 8017C668 00179468  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017C66C 0017946C  7C 08 03 A6 */	mtlr r0
/* 8017C670 00179470  38 21 00 10 */	addi r1, r1, 0x10
/* 8017C674 00179474  4E 80 00 20 */	blr
.endfn kar_si_assets_load_sislan_dat

# .text:0xF00 | 0x8017C678 | size: 0x54
.fn kar_gmlanmenu_init_sis_lan_text_style, global
/* 8017C678 00179478  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017C67C 0017947C  7C 08 02 A6 */	mflr r0
/* 8017C680 00179480  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017C684 00179484  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8017C688 00179488  4B FB 4B 59 */	bl fn_801311E0
/* 8017C68C 0017948C  7C 7F 1B 78 */	mr r31, r3
/* 8017C690 00179490  38 60 00 00 */	li r3, 0x0
/* 8017C694 00179494  38 80 00 00 */	li r4, 0x0
/* 8017C698 00179498  38 A0 00 29 */	li r5, 0x29
/* 8017C69C 0017949C  38 C0 00 11 */	li r6, 0x11
/* 8017C6A0 001794A0  38 E0 00 00 */	li r7, 0x0
/* 8017C6A4 001794A4  39 00 00 03 */	li r8, 0x3
/* 8017C6A8 001794A8  39 20 00 00 */	li r9, 0x0
/* 8017C6AC 001794AC  39 40 00 05 */	li r10, 0x5
/* 8017C6B0 001794B0  48 2D 2F C5 */	bl HSD_SisLib_803A611C
/* 8017C6B4 001794B4  98 7F 00 28 */	stb r3, 0x28(r31)
/* 8017C6B8 001794B8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017C6BC 001794BC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8017C6C0 001794C0  7C 08 03 A6 */	mtlr r0
/* 8017C6C4 001794C4  38 21 00 10 */	addi r1, r1, 0x10
/* 8017C6C8 001794C8  4E 80 00 20 */	blr
.endfn kar_gmlanmenu_init_sis_lan_text_style

# .text:0xF54 | 0x8017C6CC | size: 0x240
.fn kar_gmlanmenu_create_sis_lan_text_windows, global
/* 8017C6CC 001794CC  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 8017C6D0 001794D0  7C 08 02 A6 */	mflr r0
/* 8017C6D4 001794D4  90 01 00 54 */	stw r0, 0x54(r1)
/* 8017C6D8 001794D8  DB E1 00 40 */	stfd f31, 0x40(r1)
/* 8017C6DC 001794DC  F3 E1 00 48 */	psq_st f31, 0x48(r1), 0, qr0
/* 8017C6E0 001794E0  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 8017C6E4 001794E4  4B FB 4A FD */	bl fn_801311E0
/* 8017C6E8 001794E8  7C 7F 1B 78 */	mr r31, r3
/* 8017C6EC 001794EC  38 61 00 2C */	addi r3, r1, 0x2c
/* 8017C6F0 001794F0  48 00 73 69 */	bl kar_mnlandialogue_project_box0_origin_to_screen
/* 8017C6F4 001794F4  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 8017C6F8 001794F8  28 03 00 00 */	cmplwi r3, 0x0
/* 8017C6FC 001794FC  41 82 00 10 */	beq .L_8017C70C
/* 8017C700 00179500  48 2D 2C 51 */	bl HSD_SisLib_803A5CC4
/* 8017C704 00179504  38 00 00 00 */	li r0, 0x0
/* 8017C708 00179508  90 1F 00 2C */	stw r0, 0x2c(r31)
.L_8017C70C:
/* 8017C70C 0017950C  48 00 73 0D */	bl kar_mnlandialogue_get_box0_screen_height
/* 8017C710 00179510  FF E0 08 90 */	fmr f31, f1
/* 8017C714 00179514  48 00 72 C5 */	bl kar_mnlandialogue_get_box0_screen_width
/* 8017C718 00179518  FC 80 08 90 */	fmr f4, f1
/* 8017C71C 0017951C  88 9F 00 28 */	lbz r4, 0x28(r31)
/* 8017C720 00179520  FC A0 F8 90 */	fmr f5, f31
/* 8017C724 00179524  C0 21 00 2C */	lfs f1, 0x2c(r1)
/* 8017C728 00179528  C0 41 00 30 */	lfs f2, 0x30(r1)
/* 8017C72C 0017952C  38 60 00 00 */	li r3, 0x0
/* 8017C730 00179530  C0 62 A6 20 */	lfs f3, lbl_805E0D20@sda21(r0)
/* 8017C734 00179534  48 2D 29 F5 */	bl HSD_SisLib_803A5ACC
/* 8017C738 00179538  90 7F 00 2C */	stw r3, 0x2c(r31)
/* 8017C73C 0017953C  38 00 00 00 */	li r0, 0x0
/* 8017C740 00179540  C0 02 A6 24 */	lfs f0, lbl_805E0D24@sda21(r0)
/* 8017C744 00179544  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 8017C748 00179548  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 8017C74C 0017954C  98 03 00 4C */	stb r0, 0x4c(r3)
/* 8017C750 00179550  4B FB 4A 91 */	bl fn_801311E0
/* 8017C754 00179554  7C 7F 1B 78 */	mr r31, r3
/* 8017C758 00179558  80 63 00 30 */	lwz r3, 0x30(r3)
/* 8017C75C 0017955C  28 03 00 00 */	cmplwi r3, 0x0
/* 8017C760 00179560  41 82 00 10 */	beq .L_8017C770
/* 8017C764 00179564  48 2D 2B ED */	bl HSD_SisLib_803A5CC4
/* 8017C768 00179568  38 00 00 00 */	li r0, 0x0
/* 8017C76C 0017956C  90 1F 00 30 */	stw r0, 0x30(r31)
.L_8017C770:
/* 8017C770 00179570  88 9F 00 28 */	lbz r4, 0x28(r31)
/* 8017C774 00179574  38 60 00 00 */	li r3, 0x0
/* 8017C778 00179578  C0 22 A6 2C */	lfs f1, lbl_805E0D2C@sda21(r0)
/* 8017C77C 0017957C  C0 42 A6 30 */	lfs f2, lbl_805E0D30@sda21(r0)
/* 8017C780 00179580  C0 62 A6 20 */	lfs f3, lbl_805E0D20@sda21(r0)
/* 8017C784 00179584  C0 82 A6 34 */	lfs f4, lbl_805E0D34@sda21(r0)
/* 8017C788 00179588  C0 A2 A6 38 */	lfs f5, lbl_805E0D38@sda21(r0)
/* 8017C78C 0017958C  48 2D 29 9D */	bl HSD_SisLib_803A5ACC
/* 8017C790 00179590  90 7F 00 30 */	stw r3, 0x30(r31)
/* 8017C794 00179594  38 00 00 00 */	li r0, 0x0
/* 8017C798 00179598  C0 02 A6 24 */	lfs f0, lbl_805E0D24@sda21(r0)
/* 8017C79C 0017959C  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 8017C7A0 001795A0  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 8017C7A4 001795A4  98 03 00 4C */	stb r0, 0x4c(r3)
/* 8017C7A8 001795A8  4B FB 4A 39 */	bl fn_801311E0
/* 8017C7AC 001795AC  7C 7F 1B 78 */	mr r31, r3
/* 8017C7B0 001795B0  38 61 00 20 */	addi r3, r1, 0x20
/* 8017C7B4 001795B4  48 00 6D 79 */	bl kar_mnlannumber_project_box_origin_to_screen
/* 8017C7B8 001795B8  80 7F 00 3C */	lwz r3, 0x3c(r31)
/* 8017C7BC 001795BC  28 03 00 00 */	cmplwi r3, 0x0
/* 8017C7C0 001795C0  41 82 00 10 */	beq .L_8017C7D0
/* 8017C7C4 001795C4  48 2D 2B 8D */	bl HSD_SisLib_803A5CC4
/* 8017C7C8 001795C8  38 00 00 00 */	li r0, 0x0
/* 8017C7CC 001795CC  90 1F 00 3C */	stw r0, 0x3c(r31)
.L_8017C7D0:
/* 8017C7D0 001795D0  48 00 6D 1D */	bl kar_mnlannumber_get_box_screen_height
/* 8017C7D4 001795D4  FF E0 08 90 */	fmr f31, f1
/* 8017C7D8 001795D8  48 00 6C D5 */	bl kar_mnlannumber_get_box_screen_width
/* 8017C7DC 001795DC  C0 62 A6 20 */	lfs f3, lbl_805E0D20@sda21(r0)
/* 8017C7E0 001795E0  FC 80 08 90 */	fmr f4, f1
/* 8017C7E4 001795E4  C0 01 00 24 */	lfs f0, 0x24(r1)
/* 8017C7E8 001795E8  FC A0 F8 90 */	fmr f5, f31
/* 8017C7EC 001795EC  88 9F 00 28 */	lbz r4, 0x28(r31)
/* 8017C7F0 001795F0  38 60 00 00 */	li r3, 0x0
/* 8017C7F4 001795F4  EC 43 00 2A */	fadds f2, f3, f0
/* 8017C7F8 001795F8  C0 21 00 20 */	lfs f1, 0x20(r1)
/* 8017C7FC 001795FC  48 2D 29 2D */	bl HSD_SisLib_803A5ACC
/* 8017C800 00179600  90 7F 00 3C */	stw r3, 0x3c(r31)
/* 8017C804 00179604  38 00 00 00 */	li r0, 0x0
/* 8017C808 00179608  C0 02 A6 24 */	lfs f0, lbl_805E0D24@sda21(r0)
/* 8017C80C 0017960C  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 8017C810 00179610  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 8017C814 00179614  98 03 00 4C */	stb r0, 0x4c(r3)
/* 8017C818 00179618  4B FB 49 C9 */	bl fn_801311E0
/* 8017C81C 0017961C  7C 7F 1B 78 */	mr r31, r3
/* 8017C820 00179620  38 61 00 14 */	addi r3, r1, 0x14
/* 8017C824 00179624  48 00 74 D1 */	bl kar_mnlandialogue_project_box1_origin_to_screen
/* 8017C828 00179628  80 7F 00 34 */	lwz r3, 0x34(r31)
/* 8017C82C 0017962C  28 03 00 00 */	cmplwi r3, 0x0
/* 8017C830 00179630  41 82 00 10 */	beq .L_8017C840
/* 8017C834 00179634  48 2D 2B 1D */	bl HSD_SisLib_803A5CC4
/* 8017C838 00179638  38 00 00 00 */	li r0, 0x0
/* 8017C83C 0017963C  90 1F 00 34 */	stw r0, 0x34(r31)
.L_8017C840:
/* 8017C840 00179640  48 00 74 75 */	bl kar_mnlandialogue_get_box1_screen_height
/* 8017C844 00179644  FF E0 08 90 */	fmr f31, f1
/* 8017C848 00179648  48 00 74 2D */	bl kar_mnlandialogue_get_box1_screen_width
/* 8017C84C 0017964C  FC 80 08 90 */	fmr f4, f1
/* 8017C850 00179650  88 9F 00 28 */	lbz r4, 0x28(r31)
/* 8017C854 00179654  FC A0 F8 90 */	fmr f5, f31
/* 8017C858 00179658  C0 21 00 14 */	lfs f1, 0x14(r1)
/* 8017C85C 0017965C  C0 41 00 18 */	lfs f2, 0x18(r1)
/* 8017C860 00179660  38 60 00 00 */	li r3, 0x0
/* 8017C864 00179664  C0 62 A6 20 */	lfs f3, lbl_805E0D20@sda21(r0)
/* 8017C868 00179668  48 2D 28 C1 */	bl HSD_SisLib_803A5ACC
/* 8017C86C 0017966C  90 7F 00 34 */	stw r3, 0x34(r31)
/* 8017C870 00179670  38 00 00 00 */	li r0, 0x0
/* 8017C874 00179674  C0 02 A6 24 */	lfs f0, lbl_805E0D24@sda21(r0)
/* 8017C878 00179678  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 8017C87C 0017967C  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 8017C880 00179680  98 03 00 4C */	stb r0, 0x4c(r3)
/* 8017C884 00179684  4B FB 49 5D */	bl fn_801311E0
/* 8017C888 00179688  7C 7F 1B 78 */	mr r31, r3
/* 8017C88C 0017968C  38 61 00 08 */	addi r3, r1, 0x8
/* 8017C890 00179690  48 00 76 81 */	bl kar_mnlandialogue_project_box2_origin_to_screen
/* 8017C894 00179694  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 8017C898 00179698  28 03 00 00 */	cmplwi r3, 0x0
/* 8017C89C 0017969C  41 82 00 10 */	beq .L_8017C8AC
/* 8017C8A0 001796A0  48 2D 2A B1 */	bl HSD_SisLib_803A5CC4
/* 8017C8A4 001796A4  38 00 00 00 */	li r0, 0x0
/* 8017C8A8 001796A8  90 1F 00 38 */	stw r0, 0x38(r31)
.L_8017C8AC:
/* 8017C8AC 001796AC  48 00 74 09 */	bl kar_mnlandialogue_get_box1_screen_height
/* 8017C8B0 001796B0  FF E0 08 90 */	fmr f31, f1
/* 8017C8B4 001796B4  48 00 73 C1 */	bl kar_mnlandialogue_get_box1_screen_width
/* 8017C8B8 001796B8  FC 80 08 90 */	fmr f4, f1
/* 8017C8BC 001796BC  88 9F 00 28 */	lbz r4, 0x28(r31)
/* 8017C8C0 001796C0  FC A0 F8 90 */	fmr f5, f31
/* 8017C8C4 001796C4  C0 21 00 08 */	lfs f1, 0x8(r1)
/* 8017C8C8 001796C8  C0 41 00 0C */	lfs f2, 0xc(r1)
/* 8017C8CC 001796CC  38 60 00 00 */	li r3, 0x0
/* 8017C8D0 001796D0  C0 62 A6 20 */	lfs f3, lbl_805E0D20@sda21(r0)
/* 8017C8D4 001796D4  48 2D 28 55 */	bl HSD_SisLib_803A5ACC
/* 8017C8D8 001796D8  90 7F 00 38 */	stw r3, 0x38(r31)
/* 8017C8DC 001796DC  38 00 00 00 */	li r0, 0x0
/* 8017C8E0 001796E0  C0 02 A6 24 */	lfs f0, lbl_805E0D24@sda21(r0)
/* 8017C8E4 001796E4  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 8017C8E8 001796E8  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 8017C8EC 001796EC  98 03 00 4C */	stb r0, 0x4c(r3)
/* 8017C8F0 001796F0  E3 E1 00 48 */	psq_l f31, 0x48(r1), 0, qr0
/* 8017C8F4 001796F4  80 01 00 54 */	lwz r0, 0x54(r1)
/* 8017C8F8 001796F8  CB E1 00 40 */	lfd f31, 0x40(r1)
/* 8017C8FC 001796FC  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 8017C900 00179700  7C 08 03 A6 */	mtlr r0
/* 8017C904 00179704  38 21 00 50 */	addi r1, r1, 0x50
/* 8017C908 00179708  4E 80 00 20 */	blr
.endfn kar_gmlanmenu_create_sis_lan_text_windows

# .text:0x1194 | 0x8017C90C | size: 0x84
.fn kar_gmlanmenu_set_sis_lan_box0_message_id_adjusted, global
/* 8017C90C 0017970C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8017C910 00179710  7C 08 02 A6 */	mflr r0
/* 8017C914 00179714  90 01 00 24 */	stw r0, 0x24(r1)
/* 8017C918 00179718  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8017C91C 0017971C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8017C920 00179720  7C 7E 1B 78 */	mr r30, r3
/* 8017C924 00179724  4B FB 48 BD */	bl fn_801311E0
/* 8017C928 00179728  7C 7F 1B 78 */	mr r31, r3
/* 8017C92C 0017972C  38 61 00 08 */	addi r3, r1, 0x8
/* 8017C930 00179730  48 00 71 29 */	bl kar_mnlandialogue_project_box0_origin_to_screen
/* 8017C934 00179734  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 8017C938 00179738  7F C4 07 74 */	extsb r4, r30
/* 8017C93C 0017973C  48 2D 30 99 */	bl kar_sislib__near_8044f9d4
/* 8017C940 00179740  2C 03 00 03 */	cmpwi r3, 0x3
/* 8017C944 00179744  40 82 00 1C */	bne .L_8017C960
/* 8017C948 00179748  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8017C94C 0017974C  C0 02 A6 3C */	lfs f0, lbl_805E0D3C@sda21(r0)
/* 8017C950 00179750  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 8017C954 00179754  EC 01 00 28 */	fsubs f0, f1, f0
/* 8017C958 00179758  D0 03 00 04 */	stfs f0, 0x4(r3)
/* 8017C95C 0017975C  48 00 00 10 */	b .L_8017C96C
.L_8017C960:
/* 8017C960 00179760  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8017C964 00179764  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 8017C968 00179768  D0 03 00 04 */	stfs f0, 0x4(r3)
.L_8017C96C:
/* 8017C96C 0017976C  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 8017C970 00179770  7F C4 07 74 */	extsb r4, r30
/* 8017C974 00179774  48 2D 2F 55 */	bl HSD_SisLib_803A6368
/* 8017C978 00179778  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8017C97C 0017977C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8017C980 00179780  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8017C984 00179784  7C 08 03 A6 */	mtlr r0
/* 8017C988 00179788  38 21 00 20 */	addi r1, r1, 0x20
/* 8017C98C 0017978C  4E 80 00 20 */	blr
.endfn kar_gmlanmenu_set_sis_lan_box0_message_id_adjusted

# .text:0x1218 | 0x8017C990 | size: 0x38
.fn kar_gmlanmenu_set_sis_lan_box1_message_id, global
/* 8017C990 00179790  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017C994 00179794  7C 08 02 A6 */	mflr r0
/* 8017C998 00179798  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017C99C 0017979C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8017C9A0 001797A0  7C 7F 1B 78 */	mr r31, r3
/* 8017C9A4 001797A4  4B FB 48 3D */	bl fn_801311E0
/* 8017C9A8 001797A8  80 63 00 30 */	lwz r3, 0x30(r3)
/* 8017C9AC 001797AC  7F E4 07 74 */	extsb r4, r31
/* 8017C9B0 001797B0  48 2D 2F 19 */	bl HSD_SisLib_803A6368
/* 8017C9B4 001797B4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017C9B8 001797B8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8017C9BC 001797BC  7C 08 03 A6 */	mtlr r0
/* 8017C9C0 001797C0  38 21 00 10 */	addi r1, r1, 0x10
/* 8017C9C4 001797C4  4E 80 00 20 */	blr
.endfn kar_gmlanmenu_set_sis_lan_box1_message_id

# .text:0x1250 | 0x8017C9C8 | size: 0x38
.fn kar_gmlanmenu_set_sis_lan_box2_message_id, global
/* 8017C9C8 001797C8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017C9CC 001797CC  7C 08 02 A6 */	mflr r0
/* 8017C9D0 001797D0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017C9D4 001797D4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8017C9D8 001797D8  7C 7F 1B 78 */	mr r31, r3
/* 8017C9DC 001797DC  4B FB 48 05 */	bl fn_801311E0
/* 8017C9E0 001797E0  80 63 00 34 */	lwz r3, 0x34(r3)
/* 8017C9E4 001797E4  7F E4 07 74 */	extsb r4, r31
/* 8017C9E8 001797E8  48 2D 2E E1 */	bl HSD_SisLib_803A6368
/* 8017C9EC 001797EC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017C9F0 001797F0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8017C9F4 001797F4  7C 08 03 A6 */	mtlr r0
/* 8017C9F8 001797F8  38 21 00 10 */	addi r1, r1, 0x10
/* 8017C9FC 001797FC  4E 80 00 20 */	blr
.endfn kar_gmlanmenu_set_sis_lan_box2_message_id

# .text:0x1288 | 0x8017CA00 | size: 0x38
.fn kar_gmlanmenu_set_sis_lan_box3_message_id, global
/* 8017CA00 00179800  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017CA04 00179804  7C 08 02 A6 */	mflr r0
/* 8017CA08 00179808  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017CA0C 0017980C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8017CA10 00179810  7C 7F 1B 78 */	mr r31, r3
/* 8017CA14 00179814  4B FB 47 CD */	bl fn_801311E0
/* 8017CA18 00179818  80 63 00 38 */	lwz r3, 0x38(r3)
/* 8017CA1C 0017981C  7F E4 07 74 */	extsb r4, r31
/* 8017CA20 00179820  48 2D 2E A9 */	bl HSD_SisLib_803A6368
/* 8017CA24 00179824  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017CA28 00179828  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8017CA2C 0017982C  7C 08 03 A6 */	mtlr r0
/* 8017CA30 00179830  38 21 00 10 */	addi r1, r1, 0x10
/* 8017CA34 00179834  4E 80 00 20 */	blr
.endfn kar_gmlanmenu_set_sis_lan_box3_message_id

# .text:0x12C0 | 0x8017CA38 | size: 0x38
.fn kar_gmlanmenu_set_sis_lan_box4_message_id, global
/* 8017CA38 00179838  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017CA3C 0017983C  7C 08 02 A6 */	mflr r0
/* 8017CA40 00179840  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017CA44 00179844  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8017CA48 00179848  7C 7F 1B 78 */	mr r31, r3
/* 8017CA4C 0017984C  4B FB 47 95 */	bl fn_801311E0
/* 8017CA50 00179850  80 63 00 3C */	lwz r3, 0x3c(r3)
/* 8017CA54 00179854  7F E4 07 74 */	extsb r4, r31
/* 8017CA58 00179858  48 2D 2E 71 */	bl HSD_SisLib_803A6368
/* 8017CA5C 0017985C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017CA60 00179860  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8017CA64 00179864  7C 08 03 A6 */	mtlr r0
/* 8017CA68 00179868  38 21 00 10 */	addi r1, r1, 0x10
/* 8017CA6C 0017986C  4E 80 00 20 */	blr
.endfn kar_gmlanmenu_set_sis_lan_box4_message_id

# .text:0x12F8 | 0x8017CA70 | size: 0x20
.fn kar_gmlanmenu_destroy_sis_lan_text_windows, global
/* 8017CA70 00179870  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017CA74 00179874  7C 08 02 A6 */	mflr r0
/* 8017CA78 00179878  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017CA7C 0017987C  4B FF F7 C9 */	bl kar_mndialoguebg_destroy_all_sis_text_windows
/* 8017CA80 00179880  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017CA84 00179884  7C 08 03 A6 */	mtlr r0
/* 8017CA88 00179888  38 21 00 10 */	addi r1, r1, 0x10
/* 8017CA8C 0017988C  4E 80 00 20 */	blr
.endfn kar_gmlanmenu_destroy_sis_lan_text_windows

# .text:0x1318 | 0x8017CA90 | size: 0x34
.fn kar_si_assets_load_sisprogressive_dat, global
/* 8017CA90 00179890  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017CA94 00179894  7C 08 02 A6 */	mflr r0
/* 8017CA98 00179898  3C 60 80 4B */	lis r3, kar_gmlanmenu_sisprogressive_dat_name@ha
/* 8017CA9C 0017989C  3C A0 80 4B */	lis r5, kar_gmlanmenu_sis_progressive_group_name@ha
/* 8017CAA0 001798A0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017CAA4 001798A4  38 83 D2 44 */	addi r4, r3, kar_gmlanmenu_sisprogressive_dat_name@l
/* 8017CAA8 001798A8  38 60 00 00 */	li r3, 0x0
/* 8017CAAC 001798AC  38 A5 D2 58 */	addi r5, r5, kar_gmlanmenu_sis_progressive_group_name@l
/* 8017CAB0 001798B0  48 2D 2D 51 */	bl HSD_SisLib_803A62A0
/* 8017CAB4 001798B4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017CAB8 001798B8  7C 08 03 A6 */	mtlr r0
/* 8017CABC 001798BC  38 21 00 10 */	addi r1, r1, 0x10
/* 8017CAC0 001798C0  4E 80 00 20 */	blr
.endfn kar_si_assets_load_sisprogressive_dat

# .text:0x134C | 0x8017CAC4 | size: 0x1C4
.fn kar_gmlanmenu_create_sis_progressive_text_windows, global
/* 8017CAC4 001798C4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8017CAC8 001798C8  7C 08 02 A6 */	mflr r0
/* 8017CACC 001798CC  90 01 00 24 */	stw r0, 0x24(r1)
/* 8017CAD0 001798D0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8017CAD4 001798D4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8017CAD8 001798D8  4B FB 47 09 */	bl fn_801311E0
/* 8017CADC 001798DC  7C 7E 1B 78 */	mr r30, r3
/* 8017CAE0 001798E0  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8017CAE4 001798E4  28 03 00 00 */	cmplwi r3, 0x0
/* 8017CAE8 001798E8  41 82 00 10 */	beq .L_8017CAF8
/* 8017CAEC 001798EC  48 2D 28 65 */	bl HSD_SisLib_803A5CC4
/* 8017CAF0 001798F0  38 00 00 00 */	li r0, 0x0
/* 8017CAF4 001798F4  90 1E 00 2C */	stw r0, 0x2c(r30)
.L_8017CAF8:
/* 8017CAF8 001798F8  80 7E 00 30 */	lwz r3, 0x30(r30)
/* 8017CAFC 001798FC  28 03 00 00 */	cmplwi r3, 0x0
/* 8017CB00 00179900  41 82 00 10 */	beq .L_8017CB10
/* 8017CB04 00179904  48 2D 28 4D */	bl HSD_SisLib_803A5CC4
/* 8017CB08 00179908  38 00 00 00 */	li r0, 0x0
/* 8017CB0C 0017990C  90 1E 00 30 */	stw r0, 0x30(r30)
.L_8017CB10:
/* 8017CB10 00179910  80 7E 00 34 */	lwz r3, 0x34(r30)
/* 8017CB14 00179914  28 03 00 00 */	cmplwi r3, 0x0
/* 8017CB18 00179918  41 82 00 10 */	beq .L_8017CB28
/* 8017CB1C 0017991C  48 2D 28 35 */	bl HSD_SisLib_803A5CC4
/* 8017CB20 00179920  38 00 00 00 */	li r0, 0x0
/* 8017CB24 00179924  90 1E 00 34 */	stw r0, 0x34(r30)
.L_8017CB28:
/* 8017CB28 00179928  88 9E 00 28 */	lbz r4, 0x28(r30)
/* 8017CB2C 0017992C  38 60 00 00 */	li r3, 0x0
/* 8017CB30 00179930  C0 22 A6 40 */	lfs f1, lbl_805E0D40@sda21(r0)
/* 8017CB34 00179934  C0 42 A6 44 */	lfs f2, lbl_805E0D44@sda21(r0)
/* 8017CB38 00179938  C0 62 A6 20 */	lfs f3, lbl_805E0D20@sda21(r0)
/* 8017CB3C 0017993C  C0 82 A6 48 */	lfs f4, lbl_805E0D48@sda21(r0)
/* 8017CB40 00179940  C0 A2 A6 4C */	lfs f5, lbl_805E0D4C@sda21(r0)
/* 8017CB44 00179944  48 2D 25 E5 */	bl HSD_SisLib_803A5ACC
/* 8017CB48 00179948  7C 7F 1B 78 */	mr r31, r3
/* 8017CB4C 0017994C  C0 02 A6 24 */	lfs f0, lbl_805E0D24@sda21(r0)
/* 8017CB50 00179950  93 FE 00 2C */	stw r31, 0x2c(r30)
/* 8017CB54 00179954  38 80 00 02 */	li r4, 0x2
/* 8017CB58 00179958  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 8017CB5C 0017995C  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 8017CB60 00179960  48 2D 2E 75 */	bl kar_sislib__near_8044f9d4
/* 8017CB64 00179964  38 03 FF FF */	subi r0, r3, 0x1
/* 8017CB68 00179968  3C A0 43 30 */	lis r5, 0x4330
/* 8017CB6C 0017996C  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 8017CB70 00179970  6C 66 80 00 */	xoris r6, r3, 0x8000
/* 8017CB74 00179974  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017CB78 00179978  7F E3 FB 78 */	mr r3, r31
/* 8017CB7C 0017997C  C0 02 A6 58 */	lfs f0, lbl_805E0D58@sda21(r0)
/* 8017CB80 00179980  38 80 00 02 */	li r4, 0x2
/* 8017CB84 00179984  90 A1 00 10 */	stw r5, 0x10(r1)
/* 8017CB88 00179988  C8 C2 A6 70 */	lfd f6, lbl_805E0D70@sda21(r0)
/* 8017CB8C 0017998C  C8 21 00 10 */	lfd f1, 0x10(r1)
/* 8017CB90 00179990  90 C1 00 0C */	stw r6, 0xc(r1)
/* 8017CB94 00179994  EC 21 30 28 */	fsubs f1, f1, f6
/* 8017CB98 00179998  C0 42 A6 54 */	lfs f2, lbl_805E0D54@sda21(r0)
/* 8017CB9C 0017999C  90 A1 00 08 */	stw r5, 0x8(r1)
/* 8017CBA0 001799A0  C0 E2 A6 50 */	lfs f7, lbl_805E0D50@sda21(r0)
/* 8017CBA4 001799A4  C8 A1 00 08 */	lfd f5, 0x8(r1)
/* 8017CBA8 001799A8  EC 82 00 72 */	fmuls f4, f2, f1
/* 8017CBAC 001799AC  C0 62 A6 5C */	lfs f3, lbl_805E0D5C@sda21(r0)
/* 8017CBB0 001799B0  EC A5 30 28 */	fsubs f5, f5, f6
/* 8017CBB4 001799B4  C0 42 A6 44 */	lfs f2, lbl_805E0D44@sda21(r0)
/* 8017CBB8 001799B8  D0 1F 00 00 */	stfs f0, 0x0(r31)
/* 8017CBBC 001799BC  C0 22 A6 20 */	lfs f1, lbl_805E0D20@sda21(r0)
/* 8017CBC0 001799C0  EC 87 21 7A */	fmadds f4, f7, f5, f4
/* 8017CBC4 001799C4  C0 02 A6 48 */	lfs f0, lbl_805E0D48@sda21(r0)
/* 8017CBC8 001799C8  EC 44 10 FC */	fnmsubs f2, f4, f3, f2
/* 8017CBCC 001799CC  D0 5F 00 04 */	stfs f2, 0x4(r31)
/* 8017CBD0 001799D0  D0 3F 00 08 */	stfs f1, 0x8(r31)
/* 8017CBD4 001799D4  D0 1F 00 0C */	stfs f0, 0xc(r31)
/* 8017CBD8 001799D8  D0 9F 00 10 */	stfs f4, 0x10(r31)
/* 8017CBDC 001799DC  48 2D 2C ED */	bl HSD_SisLib_803A6368
/* 8017CBE0 001799E0  38 00 00 00 */	li r0, 0x0
/* 8017CBE4 001799E4  C0 22 A6 60 */	lfs f1, lbl_805E0D60@sda21(r0)
/* 8017CBE8 001799E8  98 1F 00 4C */	stb r0, 0x4c(r31)
/* 8017CBEC 001799EC  38 60 00 00 */	li r3, 0x0
/* 8017CBF0 001799F0  C0 42 A6 64 */	lfs f2, lbl_805E0D64@sda21(r0)
/* 8017CBF4 001799F4  88 9E 00 28 */	lbz r4, 0x28(r30)
/* 8017CBF8 001799F8  C0 62 A6 20 */	lfs f3, lbl_805E0D20@sda21(r0)
/* 8017CBFC 001799FC  C0 82 A6 68 */	lfs f4, lbl_805E0D68@sda21(r0)
/* 8017CC00 00179A00  C0 A2 A6 50 */	lfs f5, lbl_805E0D50@sda21(r0)
/* 8017CC04 00179A04  48 2D 25 25 */	bl HSD_SisLib_803A5ACC
/* 8017CC08 00179A08  7C 7F 1B 78 */	mr r31, r3
/* 8017CC0C 00179A0C  C0 02 A6 24 */	lfs f0, lbl_805E0D24@sda21(r0)
/* 8017CC10 00179A10  93 FE 00 30 */	stw r31, 0x30(r30)
/* 8017CC14 00179A14  38 80 00 03 */	li r4, 0x3
/* 8017CC18 00179A18  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 8017CC1C 00179A1C  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 8017CC20 00179A20  48 2D 2C A9 */	bl HSD_SisLib_803A6368
/* 8017CC24 00179A24  38 00 00 00 */	li r0, 0x0
/* 8017CC28 00179A28  C0 22 A6 6C */	lfs f1, lbl_805E0D6C@sda21(r0)
/* 8017CC2C 00179A2C  98 1F 00 4C */	stb r0, 0x4c(r31)
/* 8017CC30 00179A30  38 60 00 00 */	li r3, 0x0
/* 8017CC34 00179A34  C0 42 A6 64 */	lfs f2, lbl_805E0D64@sda21(r0)
/* 8017CC38 00179A38  88 9E 00 28 */	lbz r4, 0x28(r30)
/* 8017CC3C 00179A3C  C0 62 A6 20 */	lfs f3, lbl_805E0D20@sda21(r0)
/* 8017CC40 00179A40  C0 82 A6 68 */	lfs f4, lbl_805E0D68@sda21(r0)
/* 8017CC44 00179A44  C0 A2 A6 50 */	lfs f5, lbl_805E0D50@sda21(r0)
/* 8017CC48 00179A48  48 2D 24 E1 */	bl HSD_SisLib_803A5ACC
/* 8017CC4C 00179A4C  7C 7F 1B 78 */	mr r31, r3
/* 8017CC50 00179A50  C0 02 A6 24 */	lfs f0, lbl_805E0D24@sda21(r0)
/* 8017CC54 00179A54  93 FE 00 34 */	stw r31, 0x34(r30)
/* 8017CC58 00179A58  38 80 00 04 */	li r4, 0x4
/* 8017CC5C 00179A5C  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 8017CC60 00179A60  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 8017CC64 00179A64  48 2D 2C 65 */	bl HSD_SisLib_803A6368
/* 8017CC68 00179A68  38 00 00 00 */	li r0, 0x0
/* 8017CC6C 00179A6C  98 1F 00 4C */	stb r0, 0x4c(r31)
/* 8017CC70 00179A70  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8017CC74 00179A74  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8017CC78 00179A78  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8017CC7C 00179A7C  7C 08 03 A6 */	mtlr r0
/* 8017CC80 00179A80  38 21 00 20 */	addi r1, r1, 0x20
/* 8017CC84 00179A84  4E 80 00 20 */	blr
.endfn kar_gmlanmenu_create_sis_progressive_text_windows

# .text:0x1510 | 0x8017CC88 | size: 0x74
.fn kar_gmlanmenu_destroy_sis_progressive_text_windows, global
/* 8017CC88 00179A88  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8017CC8C 00179A8C  7C 08 02 A6 */	mflr r0
/* 8017CC90 00179A90  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017CC94 00179A94  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8017CC98 00179A98  4B FB 45 49 */	bl fn_801311E0
/* 8017CC9C 00179A9C  7C 7F 1B 78 */	mr r31, r3
/* 8017CCA0 00179AA0  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8017CCA4 00179AA4  28 03 00 00 */	cmplwi r3, 0x0
/* 8017CCA8 00179AA8  41 82 00 10 */	beq .L_8017CCB8
/* 8017CCAC 00179AAC  48 2D 26 A5 */	bl HSD_SisLib_803A5CC4
/* 8017CCB0 00179AB0  38 00 00 00 */	li r0, 0x0
/* 8017CCB4 00179AB4  90 1F 00 2C */	stw r0, 0x2c(r31)
.L_8017CCB8:
/* 8017CCB8 00179AB8  80 7F 00 30 */	lwz r3, 0x30(r31)
/* 8017CCBC 00179ABC  28 03 00 00 */	cmplwi r3, 0x0
/* 8017CCC0 00179AC0  41 82 00 10 */	beq .L_8017CCD0
/* 8017CCC4 00179AC4  48 2D 26 8D */	bl HSD_SisLib_803A5CC4
/* 8017CCC8 00179AC8  38 00 00 00 */	li r0, 0x0
/* 8017CCCC 00179ACC  90 1F 00 30 */	stw r0, 0x30(r31)
.L_8017CCD0:
/* 8017CCD0 00179AD0  80 7F 00 34 */	lwz r3, 0x34(r31)
/* 8017CCD4 00179AD4  28 03 00 00 */	cmplwi r3, 0x0
/* 8017CCD8 00179AD8  41 82 00 10 */	beq .L_8017CCE8
/* 8017CCDC 00179ADC  48 2D 26 75 */	bl HSD_SisLib_803A5CC4
/* 8017CCE0 00179AE0  38 00 00 00 */	li r0, 0x0
/* 8017CCE4 00179AE4  90 1F 00 34 */	stw r0, 0x34(r31)
.L_8017CCE8:
/* 8017CCE8 00179AE8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8017CCEC 00179AEC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8017CCF0 00179AF0  7C 08 03 A6 */	mtlr r0
/* 8017CCF4 00179AF4  38 21 00 10 */	addi r1, r1, 0x10
/* 8017CCF8 00179AF8  4E 80 00 20 */	blr
.endfn kar_gmlanmenu_destroy_sis_progressive_text_windows

# .text:0x1584 | 0x8017CCFC | size: 0x10C
.fn kar_gmlanmenu_create_sis_progressive_message5_window, global
/* 8017CCFC 00179AFC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8017CD00 00179B00  7C 08 02 A6 */	mflr r0
/* 8017CD04 00179B04  90 01 00 24 */	stw r0, 0x24(r1)
/* 8017CD08 00179B08  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8017CD0C 00179B0C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8017CD10 00179B10  4B FB 44 D1 */	bl fn_801311E0
/* 8017CD14 00179B14  7C 7F 1B 78 */	mr r31, r3
/* 8017CD18 00179B18  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8017CD1C 00179B1C  28 03 00 00 */	cmplwi r3, 0x0
/* 8017CD20 00179B20  41 82 00 10 */	beq .L_8017CD30
/* 8017CD24 00179B24  48 2D 26 2D */	bl HSD_SisLib_803A5CC4
/* 8017CD28 00179B28  38 00 00 00 */	li r0, 0x0
/* 8017CD2C 00179B2C  90 1F 00 2C */	stw r0, 0x2c(r31)
.L_8017CD30:
/* 8017CD30 00179B30  88 9F 00 28 */	lbz r4, 0x28(r31)
/* 8017CD34 00179B34  38 60 00 00 */	li r3, 0x0
/* 8017CD38 00179B38  C0 22 A6 78 */	lfs f1, lbl_805E0D78@sda21(r0)
/* 8017CD3C 00179B3C  C0 42 A6 7C */	lfs f2, lbl_805E0D7C@sda21(r0)
/* 8017CD40 00179B40  C0 62 A6 20 */	lfs f3, lbl_805E0D20@sda21(r0)
/* 8017CD44 00179B44  C0 82 A6 80 */	lfs f4, lbl_805E0D80@sda21(r0)
/* 8017CD48 00179B48  C0 A2 A6 84 */	lfs f5, lbl_805E0D84@sda21(r0)
/* 8017CD4C 00179B4C  48 2D 23 DD */	bl HSD_SisLib_803A5ACC
/* 8017CD50 00179B50  7C 7E 1B 78 */	mr r30, r3
/* 8017CD54 00179B54  C0 02 A6 24 */	lfs f0, lbl_805E0D24@sda21(r0)
/* 8017CD58 00179B58  93 DF 00 2C */	stw r30, 0x2c(r31)
/* 8017CD5C 00179B5C  38 80 00 05 */	li r4, 0x5
/* 8017CD60 00179B60  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 8017CD64 00179B64  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 8017CD68 00179B68  48 2D 2C 6D */	bl kar_sislib__near_8044f9d4
/* 8017CD6C 00179B6C  38 03 FF FF */	subi r0, r3, 0x1
/* 8017CD70 00179B70  3C A0 43 30 */	lis r5, 0x4330
/* 8017CD74 00179B74  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 8017CD78 00179B78  6C 66 80 00 */	xoris r6, r3, 0x8000
/* 8017CD7C 00179B7C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017CD80 00179B80  7F C3 F3 78 */	mr r3, r30
/* 8017CD84 00179B84  C0 02 A6 88 */	lfs f0, lbl_805E0D88@sda21(r0)
/* 8017CD88 00179B88  38 80 00 05 */	li r4, 0x5
/* 8017CD8C 00179B8C  90 A1 00 10 */	stw r5, 0x10(r1)
/* 8017CD90 00179B90  C8 C2 A6 70 */	lfd f6, lbl_805E0D70@sda21(r0)
/* 8017CD94 00179B94  C8 21 00 10 */	lfd f1, 0x10(r1)
/* 8017CD98 00179B98  90 C1 00 0C */	stw r6, 0xc(r1)
/* 8017CD9C 00179B9C  EC 21 30 28 */	fsubs f1, f1, f6
/* 8017CDA0 00179BA0  C0 42 A6 54 */	lfs f2, lbl_805E0D54@sda21(r0)
/* 8017CDA4 00179BA4  90 A1 00 08 */	stw r5, 0x8(r1)
/* 8017CDA8 00179BA8  C0 E2 A6 50 */	lfs f7, lbl_805E0D50@sda21(r0)
/* 8017CDAC 00179BAC  C8 A1 00 08 */	lfd f5, 0x8(r1)
/* 8017CDB0 00179BB0  EC 82 00 72 */	fmuls f4, f2, f1
/* 8017CDB4 00179BB4  C0 62 A6 5C */	lfs f3, lbl_805E0D5C@sda21(r0)
/* 8017CDB8 00179BB8  EC A5 30 28 */	fsubs f5, f5, f6
/* 8017CDBC 00179BBC  C0 42 A6 7C */	lfs f2, lbl_805E0D7C@sda21(r0)
/* 8017CDC0 00179BC0  D0 1E 00 00 */	stfs f0, 0x0(r30)
/* 8017CDC4 00179BC4  C0 22 A6 20 */	lfs f1, lbl_805E0D20@sda21(r0)
/* 8017CDC8 00179BC8  EC 87 21 7A */	fmadds f4, f7, f5, f4
/* 8017CDCC 00179BCC  C0 02 A6 80 */	lfs f0, lbl_805E0D80@sda21(r0)
/* 8017CDD0 00179BD0  EC 44 10 FC */	fnmsubs f2, f4, f3, f2
/* 8017CDD4 00179BD4  D0 5E 00 04 */	stfs f2, 0x4(r30)
/* 8017CDD8 00179BD8  D0 3E 00 08 */	stfs f1, 0x8(r30)
/* 8017CDDC 00179BDC  D0 1E 00 0C */	stfs f0, 0xc(r30)
/* 8017CDE0 00179BE0  D0 9E 00 10 */	stfs f4, 0x10(r30)
/* 8017CDE4 00179BE4  48 2D 2A E5 */	bl HSD_SisLib_803A6368
/* 8017CDE8 00179BE8  38 00 00 00 */	li r0, 0x0
/* 8017CDEC 00179BEC  98 1E 00 4C */	stb r0, 0x4c(r30)
/* 8017CDF0 00179BF0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8017CDF4 00179BF4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8017CDF8 00179BF8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8017CDFC 00179BFC  7C 08 03 A6 */	mtlr r0
/* 8017CE00 00179C00  38 21 00 20 */	addi r1, r1, 0x20
/* 8017CE04 00179C04  4E 80 00 20 */	blr
.endfn kar_gmlanmenu_create_sis_progressive_message5_window

# .text:0x1690 | 0x8017CE08 | size: 0x10C
.fn kar_gmlanmenu_create_sis_progressive_message6_window, global
/* 8017CE08 00179C08  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8017CE0C 00179C0C  7C 08 02 A6 */	mflr r0
/* 8017CE10 00179C10  90 01 00 24 */	stw r0, 0x24(r1)
/* 8017CE14 00179C14  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8017CE18 00179C18  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8017CE1C 00179C1C  4B FB 43 C5 */	bl fn_801311E0
/* 8017CE20 00179C20  7C 7F 1B 78 */	mr r31, r3
/* 8017CE24 00179C24  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8017CE28 00179C28  28 03 00 00 */	cmplwi r3, 0x0
/* 8017CE2C 00179C2C  41 82 00 10 */	beq .L_8017CE3C
/* 8017CE30 00179C30  48 2D 25 21 */	bl HSD_SisLib_803A5CC4
/* 8017CE34 00179C34  38 00 00 00 */	li r0, 0x0
/* 8017CE38 00179C38  90 1F 00 2C */	stw r0, 0x2c(r31)
.L_8017CE3C:
/* 8017CE3C 00179C3C  88 9F 00 28 */	lbz r4, 0x28(r31)
/* 8017CE40 00179C40  38 60 00 00 */	li r3, 0x0
/* 8017CE44 00179C44  C0 22 A6 78 */	lfs f1, lbl_805E0D78@sda21(r0)
/* 8017CE48 00179C48  C0 42 A6 7C */	lfs f2, lbl_805E0D7C@sda21(r0)
/* 8017CE4C 00179C4C  C0 62 A6 20 */	lfs f3, lbl_805E0D20@sda21(r0)
/* 8017CE50 00179C50  C0 82 A6 80 */	lfs f4, lbl_805E0D80@sda21(r0)
/* 8017CE54 00179C54  C0 A2 A6 84 */	lfs f5, lbl_805E0D84@sda21(r0)
/* 8017CE58 00179C58  48 2D 22 D1 */	bl HSD_SisLib_803A5ACC
/* 8017CE5C 00179C5C  7C 7E 1B 78 */	mr r30, r3
/* 8017CE60 00179C60  C0 02 A6 24 */	lfs f0, lbl_805E0D24@sda21(r0)
/* 8017CE64 00179C64  93 DF 00 2C */	stw r30, 0x2c(r31)
/* 8017CE68 00179C68  38 80 00 06 */	li r4, 0x6
/* 8017CE6C 00179C6C  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 8017CE70 00179C70  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 8017CE74 00179C74  48 2D 2B 61 */	bl kar_sislib__near_8044f9d4
/* 8017CE78 00179C78  38 03 FF FF */	subi r0, r3, 0x1
/* 8017CE7C 00179C7C  3C A0 43 30 */	lis r5, 0x4330
/* 8017CE80 00179C80  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 8017CE84 00179C84  6C 66 80 00 */	xoris r6, r3, 0x8000
/* 8017CE88 00179C88  90 01 00 14 */	stw r0, 0x14(r1)
/* 8017CE8C 00179C8C  7F C3 F3 78 */	mr r3, r30
/* 8017CE90 00179C90  C0 02 A6 88 */	lfs f0, lbl_805E0D88@sda21(r0)
/* 8017CE94 00179C94  38 80 00 06 */	li r4, 0x6
/* 8017CE98 00179C98  90 A1 00 10 */	stw r5, 0x10(r1)
/* 8017CE9C 00179C9C  C8 C2 A6 70 */	lfd f6, lbl_805E0D70@sda21(r0)
/* 8017CEA0 00179CA0  C8 21 00 10 */	lfd f1, 0x10(r1)
/* 8017CEA4 00179CA4  90 C1 00 0C */	stw r6, 0xc(r1)
/* 8017CEA8 00179CA8  EC 21 30 28 */	fsubs f1, f1, f6
/* 8017CEAC 00179CAC  C0 42 A6 54 */	lfs f2, lbl_805E0D54@sda21(r0)
/* 8017CEB0 00179CB0  90 A1 00 08 */	stw r5, 0x8(r1)
/* 8017CEB4 00179CB4  C0 E2 A6 50 */	lfs f7, lbl_805E0D50@sda21(r0)
/* 8017CEB8 00179CB8  C8 A1 00 08 */	lfd f5, 0x8(r1)
/* 8017CEBC 00179CBC  EC 82 00 72 */	fmuls f4, f2, f1
/* 8017CEC0 00179CC0  C0 62 A6 5C */	lfs f3, lbl_805E0D5C@sda21(r0)
/* 8017CEC4 00179CC4  EC A5 30 28 */	fsubs f5, f5, f6
/* 8017CEC8 00179CC8  C0 42 A6 7C */	lfs f2, lbl_805E0D7C@sda21(r0)
/* 8017CECC 00179CCC  D0 1E 00 00 */	stfs f0, 0x0(r30)
/* 8017CED0 00179CD0  C0 22 A6 20 */	lfs f1, lbl_805E0D20@sda21(r0)
/* 8017CED4 00179CD4  EC 87 21 7A */	fmadds f4, f7, f5, f4
/* 8017CED8 00179CD8  C0 02 A6 80 */	lfs f0, lbl_805E0D80@sda21(r0)
/* 8017CEDC 00179CDC  EC 44 10 FC */	fnmsubs f2, f4, f3, f2
/* 8017CEE0 00179CE0  D0 5E 00 04 */	stfs f2, 0x4(r30)
/* 8017CEE4 00179CE4  D0 3E 00 08 */	stfs f1, 0x8(r30)
/* 8017CEE8 00179CE8  D0 1E 00 0C */	stfs f0, 0xc(r30)
/* 8017CEEC 00179CEC  D0 9E 00 10 */	stfs f4, 0x10(r30)
/* 8017CEF0 00179CF0  48 2D 29 D9 */	bl HSD_SisLib_803A6368
/* 8017CEF4 00179CF4  38 00 00 00 */	li r0, 0x0
/* 8017CEF8 00179CF8  98 1E 00 4C */	stb r0, 0x4c(r30)
/* 8017CEFC 00179CFC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8017CF00 00179D00  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8017CF04 00179D04  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8017CF08 00179D08  7C 08 03 A6 */	mtlr r0
/* 8017CF0C 00179D0C  38 21 00 20 */	addi r1, r1, 0x20
/* 8017CF10 00179D10  4E 80 00 20 */	blr
.endfn kar_gmlanmenu_create_sis_progressive_message6_window
