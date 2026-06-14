.include "macros.inc"
.file "mnlannumber.c"

# 0x8018352C..0x80183A58 | size: 0x52C
.text
.balign 4

# .text:0x0 | 0x8018352C | size: 0xB4
.fn kar_mnlannumber_project_box_origin_to_screen, global
/* 8018352C 0018032C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80183530 00180330  7C 08 02 A6 */	mflr r0
/* 80183534 00180334  90 01 00 24 */	stw r0, 0x24(r1)
/* 80183538 00180338  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8018353C 0018033C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80183540 00180340  7C 7E 1B 78 */	mr r30, r3
/* 80183544 00180344  4B FA DC 9D */	bl fn_801311E0
/* 80183548 00180348  80 63 11 60 */	lwz r3, 0x1160(r3)
/* 8018354C 0018034C  28 03 00 00 */	cmplwi r3, 0x0
/* 80183550 00180350  41 82 00 78 */	beq .L_801835C8
/* 80183554 00180354  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80183558 00180358  83 E3 00 0C */	lwz r31, 0xc(r3)
/* 8018355C 0018035C  28 1F 00 00 */	cmplwi r31, 0x0
/* 80183560 00180360  40 82 00 14 */	bne .L_80183574
/* 80183564 00180364  38 6D 9D 40 */	li r3, kar_srcfile_jobj_h_805d6e20@sda21
/* 80183568 00180368  38 80 03 E4 */	li r4, 0x3e4
/* 8018356C 0018036C  38 AD 9D 48 */	li r5, lbl_805D6E28@sda21
/* 80183570 00180370  48 2A 4F 49 */	bl __assert
.L_80183574:
/* 80183574 00180374  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 80183578 00180378  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 8018357C 0018037C  90 61 00 08 */	stw r3, 0x8(r1)
/* 80183580 00180380  90 01 00 0C */	stw r0, 0xc(r1)
/* 80183584 00180384  80 1F 00 40 */	lwz r0, 0x40(r31)
/* 80183588 00180388  90 01 00 10 */	stw r0, 0x10(r1)
/* 8018358C 0018038C  4B FA DC 55 */	bl fn_801311E0
/* 80183590 00180390  80 63 00 08 */	lwz r3, 0x8(r3)
/* 80183594 00180394  28 03 00 00 */	cmplwi r3, 0x0
/* 80183598 00180398  41 82 00 1C */	beq .L_801835B4
/* 8018359C 0018039C  80 63 00 28 */	lwz r3, 0x28(r3)
/* 801835A0 001803A0  7F C5 F3 78 */	mr r5, r30
/* 801835A4 001803A4  38 81 00 08 */	addi r4, r1, 0x8
/* 801835A8 001803A8  38 C0 00 00 */	li r6, 0x0
/* 801835AC 001803AC  4B EE 0F 01 */	bl kar_lbvector_project_world_to_screen
/* 801835B0 001803B0  48 00 00 18 */	b .L_801835C8
.L_801835B4:
/* 801835B4 001803B4  3C 60 80 4B */	lis r3, kar_src_mnlannumber_c@ha
/* 801835B8 001803B8  38 80 00 75 */	li r4, 0x75
/* 801835BC 001803BC  38 63 D6 88 */	addi r3, r3, kar_src_mnlannumber_c@l
/* 801835C0 001803C0  38 AD 9D 50 */	li r5, lbl_805D6E30@sda21
/* 801835C4 001803C4  48 2A 4E F5 */	bl __assert
.L_801835C8:
/* 801835C8 001803C8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801835CC 001803CC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801835D0 001803D0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801835D4 001803D4  7C 08 03 A6 */	mtlr r0
/* 801835D8 001803D8  38 21 00 20 */	addi r1, r1, 0x20
/* 801835DC 001803DC  4E 80 00 20 */	blr
.endfn kar_mnlannumber_project_box_origin_to_screen

# .text:0xB4 | 0x801835E0 | size: 0xB4
.fn kar_mnlannumber_project_box_right_edge_to_screen, global
/* 801835E0 001803E0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801835E4 001803E4  7C 08 02 A6 */	mflr r0
/* 801835E8 001803E8  90 01 00 24 */	stw r0, 0x24(r1)
/* 801835EC 001803EC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801835F0 001803F0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801835F4 001803F4  7C 7E 1B 78 */	mr r30, r3
/* 801835F8 001803F8  4B FA DB E9 */	bl fn_801311E0
/* 801835FC 001803FC  80 63 11 60 */	lwz r3, 0x1160(r3)
/* 80183600 00180400  28 03 00 00 */	cmplwi r3, 0x0
/* 80183604 00180404  41 82 00 78 */	beq .L_8018367C
/* 80183608 00180408  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 8018360C 0018040C  83 E3 00 10 */	lwz r31, 0x10(r3)
/* 80183610 00180410  28 1F 00 00 */	cmplwi r31, 0x0
/* 80183614 00180414  40 82 00 14 */	bne .L_80183628
/* 80183618 00180418  38 6D 9D 40 */	li r3, kar_srcfile_jobj_h_805d6e20@sda21
/* 8018361C 0018041C  38 80 03 E4 */	li r4, 0x3e4
/* 80183620 00180420  38 AD 9D 48 */	li r5, lbl_805D6E28@sda21
/* 80183624 00180424  48 2A 4E 95 */	bl __assert
.L_80183628:
/* 80183628 00180428  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 8018362C 0018042C  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 80183630 00180430  90 61 00 08 */	stw r3, 0x8(r1)
/* 80183634 00180434  90 01 00 0C */	stw r0, 0xc(r1)
/* 80183638 00180438  80 1F 00 40 */	lwz r0, 0x40(r31)
/* 8018363C 0018043C  90 01 00 10 */	stw r0, 0x10(r1)
/* 80183640 00180440  4B FA DB A1 */	bl fn_801311E0
/* 80183644 00180444  80 63 00 08 */	lwz r3, 0x8(r3)
/* 80183648 00180448  28 03 00 00 */	cmplwi r3, 0x0
/* 8018364C 0018044C  41 82 00 1C */	beq .L_80183668
/* 80183650 00180450  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80183654 00180454  7F C5 F3 78 */	mr r5, r30
/* 80183658 00180458  38 81 00 08 */	addi r4, r1, 0x8
/* 8018365C 0018045C  38 C0 00 00 */	li r6, 0x0
/* 80183660 00180460  4B EE 0E 4D */	bl kar_lbvector_project_world_to_screen
/* 80183664 00180464  48 00 00 18 */	b .L_8018367C
.L_80183668:
/* 80183668 00180468  3C 60 80 4B */	lis r3, kar_src_mnlannumber_c@ha
/* 8018366C 0018046C  38 80 00 75 */	li r4, 0x75
/* 80183670 00180470  38 63 D6 88 */	addi r3, r3, kar_src_mnlannumber_c@l
/* 80183674 00180474  38 AD 9D 50 */	li r5, lbl_805D6E30@sda21
/* 80183678 00180478  48 2A 4E 41 */	bl __assert
.L_8018367C:
/* 8018367C 0018047C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80183680 00180480  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80183684 00180484  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80183688 00180488  7C 08 03 A6 */	mtlr r0
/* 8018368C 0018048C  38 21 00 20 */	addi r1, r1, 0x20
/* 80183690 00180490  4E 80 00 20 */	blr
.endfn kar_mnlannumber_project_box_right_edge_to_screen

# .text:0x168 | 0x80183694 | size: 0xB4
.fn kar_mnlannumber_project_box_bottom_edge_to_screen, global
/* 80183694 00180494  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80183698 00180498  7C 08 02 A6 */	mflr r0
/* 8018369C 0018049C  90 01 00 24 */	stw r0, 0x24(r1)
/* 801836A0 001804A0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801836A4 001804A4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801836A8 001804A8  7C 7E 1B 78 */	mr r30, r3
/* 801836AC 001804AC  4B FA DB 35 */	bl fn_801311E0
/* 801836B0 001804B0  80 63 11 60 */	lwz r3, 0x1160(r3)
/* 801836B4 001804B4  28 03 00 00 */	cmplwi r3, 0x0
/* 801836B8 001804B8  41 82 00 78 */	beq .L_80183730
/* 801836BC 001804BC  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 801836C0 001804C0  83 E3 00 14 */	lwz r31, 0x14(r3)
/* 801836C4 001804C4  28 1F 00 00 */	cmplwi r31, 0x0
/* 801836C8 001804C8  40 82 00 14 */	bne .L_801836DC
/* 801836CC 001804CC  38 6D 9D 40 */	li r3, kar_srcfile_jobj_h_805d6e20@sda21
/* 801836D0 001804D0  38 80 03 E4 */	li r4, 0x3e4
/* 801836D4 001804D4  38 AD 9D 48 */	li r5, lbl_805D6E28@sda21
/* 801836D8 001804D8  48 2A 4D E1 */	bl __assert
.L_801836DC:
/* 801836DC 001804DC  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 801836E0 001804E0  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 801836E4 001804E4  90 61 00 08 */	stw r3, 0x8(r1)
/* 801836E8 001804E8  90 01 00 0C */	stw r0, 0xc(r1)
/* 801836EC 001804EC  80 1F 00 40 */	lwz r0, 0x40(r31)
/* 801836F0 001804F0  90 01 00 10 */	stw r0, 0x10(r1)
/* 801836F4 001804F4  4B FA DA ED */	bl fn_801311E0
/* 801836F8 001804F8  80 63 00 08 */	lwz r3, 0x8(r3)
/* 801836FC 001804FC  28 03 00 00 */	cmplwi r3, 0x0
/* 80183700 00180500  41 82 00 1C */	beq .L_8018371C
/* 80183704 00180504  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80183708 00180508  7F C5 F3 78 */	mr r5, r30
/* 8018370C 0018050C  38 81 00 08 */	addi r4, r1, 0x8
/* 80183710 00180510  38 C0 00 00 */	li r6, 0x0
/* 80183714 00180514  4B EE 0D 99 */	bl kar_lbvector_project_world_to_screen
/* 80183718 00180518  48 00 00 18 */	b .L_80183730
.L_8018371C:
/* 8018371C 0018051C  3C 60 80 4B */	lis r3, kar_src_mnlannumber_c@ha
/* 80183720 00180520  38 80 00 75 */	li r4, 0x75
/* 80183724 00180524  38 63 D6 88 */	addi r3, r3, kar_src_mnlannumber_c@l
/* 80183728 00180528  38 AD 9D 50 */	li r5, lbl_805D6E30@sda21
/* 8018372C 0018052C  48 2A 4D 8D */	bl __assert
.L_80183730:
/* 80183730 00180530  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80183734 00180534  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80183738 00180538  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8018373C 0018053C  7C 08 03 A6 */	mtlr r0
/* 80183740 00180540  38 21 00 20 */	addi r1, r1, 0x20
/* 80183744 00180544  4E 80 00 20 */	blr
.endfn kar_mnlannumber_project_box_bottom_edge_to_screen

# .text:0x21C | 0x80183748 | size: 0x44
.fn kar_mnlannumber_request_panel_anim0, global
/* 80183748 00180548  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8018374C 0018054C  7C 08 02 A6 */	mflr r0
/* 80183750 00180550  90 01 00 14 */	stw r0, 0x14(r1)
/* 80183754 00180554  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80183758 00180558  4B FA DA 89 */	bl fn_801311E0
/* 8018375C 0018055C  80 63 11 60 */	lwz r3, 0x1160(r3)
/* 80183760 00180560  C0 22 A7 70 */	lfs f1, lbl_805E0E70@sda21(r0)
/* 80183764 00180564  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 80183768 00180568  7F E3 FB 78 */	mr r3, r31
/* 8018376C 0018056C  48 28 5A E5 */	bl HSD_JObjReqAnimAll
/* 80183770 00180570  7F E3 FB 78 */	mr r3, r31
/* 80183774 00180574  48 28 6E D9 */	bl HSD_JObjAnimAll
/* 80183778 00180578  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8018377C 0018057C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80183780 00180580  7C 08 03 A6 */	mtlr r0
/* 80183784 00180584  38 21 00 10 */	addi r1, r1, 0x10
/* 80183788 00180588  4E 80 00 20 */	blr
.endfn kar_mnlannumber_request_panel_anim0

# .text:0x260 | 0x8018378C | size: 0x44
.fn kar_mnlannumber_request_panel_anim1, global
/* 8018378C 0018058C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80183790 00180590  7C 08 02 A6 */	mflr r0
/* 80183794 00180594  90 01 00 14 */	stw r0, 0x14(r1)
/* 80183798 00180598  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8018379C 0018059C  4B FA DA 45 */	bl fn_801311E0
/* 801837A0 001805A0  80 63 11 60 */	lwz r3, 0x1160(r3)
/* 801837A4 001805A4  C0 22 A7 74 */	lfs f1, lbl_805E0E74@sda21(r0)
/* 801837A8 001805A8  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 801837AC 001805AC  7F E3 FB 78 */	mr r3, r31
/* 801837B0 001805B0  48 28 5A A1 */	bl HSD_JObjReqAnimAll
/* 801837B4 001805B4  7F E3 FB 78 */	mr r3, r31
/* 801837B8 001805B8  48 28 6E 95 */	bl HSD_JObjAnimAll
/* 801837BC 001805BC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801837C0 001805C0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801837C4 001805C4  7C 08 03 A6 */	mtlr r0
/* 801837C8 001805C8  38 21 00 10 */	addi r1, r1, 0x10
/* 801837CC 001805CC  4E 80 00 20 */	blr
.endfn kar_mnlannumber_request_panel_anim1

# .text:0x2A4 | 0x801837D0 | size: 0x44
.fn kar_mnlannumber_request_panel_anim2, global
/* 801837D0 001805D0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801837D4 001805D4  7C 08 02 A6 */	mflr r0
/* 801837D8 001805D8  90 01 00 14 */	stw r0, 0x14(r1)
/* 801837DC 001805DC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801837E0 001805E0  4B FA DA 01 */	bl fn_801311E0
/* 801837E4 001805E4  80 63 11 60 */	lwz r3, 0x1160(r3)
/* 801837E8 001805E8  C0 22 A7 78 */	lfs f1, lbl_805E0E78@sda21(r0)
/* 801837EC 001805EC  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 801837F0 001805F0  7F E3 FB 78 */	mr r3, r31
/* 801837F4 001805F4  48 28 5A 5D */	bl HSD_JObjReqAnimAll
/* 801837F8 001805F8  7F E3 FB 78 */	mr r3, r31
/* 801837FC 001805FC  48 28 6E 51 */	bl HSD_JObjAnimAll
/* 80183800 00180600  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80183804 00180604  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80183808 00180608  7C 08 03 A6 */	mtlr r0
/* 8018380C 0018060C  38 21 00 10 */	addi r1, r1, 0x10
/* 80183810 00180610  4E 80 00 20 */	blr
.endfn kar_mnlannumber_request_panel_anim2

# .text:0x2E8 | 0x80183814 | size: 0x30
.fn kar_mnlannumber_hide_panel, global
/* 80183814 00180614  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80183818 00180618  7C 08 02 A6 */	mflr r0
/* 8018381C 0018061C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80183820 00180620  4B FA D9 C1 */	bl fn_801311E0
/* 80183824 00180624  80 63 11 60 */	lwz r3, 0x1160(r3)
/* 80183828 00180628  28 03 00 00 */	cmplwi r3, 0x0
/* 8018382C 0018062C  41 82 00 08 */	beq .L_80183834
/* 80183830 00180630  4B FB 52 81 */	bl kar_menu_gobj_userdata_hide
.L_80183834:
/* 80183834 00180634  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80183838 00180638  7C 08 03 A6 */	mtlr r0
/* 8018383C 0018063C  38 21 00 10 */	addi r1, r1, 0x10
/* 80183840 00180640  4E 80 00 20 */	blr
.endfn kar_mnlannumber_hide_panel

# .text:0x318 | 0x80183844 | size: 0x30
.fn kar_mnlannumber_show_panel, global
/* 80183844 00180644  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80183848 00180648  7C 08 02 A6 */	mflr r0
/* 8018384C 0018064C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80183850 00180650  4B FA D9 91 */	bl fn_801311E0
/* 80183854 00180654  80 63 11 60 */	lwz r3, 0x1160(r3)
/* 80183858 00180658  28 03 00 00 */	cmplwi r3, 0x0
/* 8018385C 0018065C  41 82 00 08 */	beq .L_80183864
/* 80183860 00180660  4B FB 52 69 */	bl kar_menu_gobj_userdata_show
.L_80183864:
/* 80183864 00180664  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80183868 00180668  7C 08 03 A6 */	mtlr r0
/* 8018386C 0018066C  38 21 00 10 */	addi r1, r1, 0x10
/* 80183870 00180670  4E 80 00 20 */	blr
.endfn kar_mnlannumber_show_panel

# .text:0x348 | 0x80183874 | size: 0x4
.fn fn_80183874, global
/* 80183874 00180674  4E 80 00 20 */	blr
.endfn fn_80183874

# .text:0x34C | 0x80183878 | size: 0x4C
.fn kar_mnlannumber_load_scene_models, global
/* 80183878 00180678  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8018387C 0018067C  7C 08 02 A6 */	mflr r0
/* 80183880 00180680  90 01 00 14 */	stw r0, 0x14(r1)
/* 80183884 00180684  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80183888 00180688  4B FA D9 59 */	bl fn_801311E0
/* 8018388C 0018068C  7C 7F 1B 78 */	mr r31, r3
/* 80183890 00180690  4B FB 58 0D */	bl fn_8013909C
/* 80183894 00180694  3C 80 80 4B */	lis r4, kar_mnlannumber_scene_models_name@ha
/* 80183898 00180698  80 63 00 00 */	lwz r3, 0x0(r3)
/* 8018389C 0018069C  38 A4 D6 98 */	addi r5, r4, kar_mnlannumber_scene_models_name@l
/* 801838A0 001806A0  38 C0 00 00 */	li r6, 0x0
/* 801838A4 001806A4  38 9F 11 5C */	addi r4, r31, 0x115c
/* 801838A8 001806A8  4C C6 31 82 */	crclr cr1eq
/* 801838AC 001806AC  4B ED 5C 75 */	bl kar_lbarchive__near_80059520
/* 801838B0 001806B0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801838B4 001806B4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801838B8 001806B8  7C 08 03 A6 */	mtlr r0
/* 801838BC 001806BC  38 21 00 10 */	addi r1, r1, 0x10
/* 801838C0 001806C0  4E 80 00 20 */	blr
.endfn kar_mnlannumber_load_scene_models

# .text:0x398 | 0x801838C4 | size: 0xD0
.fn kar_mnlannumber_create_panel_and_cache_child_jobjs, global
/* 801838C4 001806C4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801838C8 001806C8  7C 08 02 A6 */	mflr r0
/* 801838CC 001806CC  90 01 00 24 */	stw r0, 0x24(r1)
/* 801838D0 001806D0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801838D4 001806D4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801838D8 001806D8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 801838DC 001806DC  4B FA D9 05 */	bl fn_801311E0
/* 801838E0 001806E0  7C 7E 1B 78 */	mr r30, r3
/* 801838E4 001806E4  80 63 11 5C */	lwz r3, 0x115c(r3)
/* 801838E8 001806E8  80 63 00 00 */	lwz r3, 0x0(r3)
/* 801838EC 001806EC  80 63 00 00 */	lwz r3, 0x0(r3)
/* 801838F0 001806F0  4B FB 4F B9 */	bl fn_801388A8
/* 801838F4 001806F4  3C 80 80 18 */	lis r4, fn_80183874@ha
/* 801838F8 001806F8  83 E3 00 28 */	lwz r31, 0x28(r3)
/* 801838FC 001806FC  7C 7D 1B 78 */	mr r29, r3
/* 80183900 00180700  38 A0 00 01 */	li r5, 0x1
/* 80183904 00180704  38 84 38 74 */	addi r4, r4, fn_80183874@l
/* 80183908 00180708  48 2A 4F 9D */	bl HSD_GObjProcCreate
/* 8018390C 0018070C  80 9E 11 5C */	lwz r4, 0x115c(r30)
/* 80183910 00180710  7F E3 FB 78 */	mr r3, r31
/* 80183914 00180714  C0 22 A7 70 */	lfs f1, lbl_805E0E70@sda21(r0)
/* 80183918 00180718  80 84 00 00 */	lwz r4, 0x0(r4)
/* 8018391C 0018071C  C0 42 A7 74 */	lfs f2, lbl_805E0E74@sda21(r0)
/* 80183920 00180720  4B FB 50 B9 */	bl fn_801389D8
/* 80183924 00180724  7F A3 EB 78 */	mr r3, r29
/* 80183928 00180728  38 80 00 BA */	li r4, 0xba
/* 8018392C 0018072C  4B FB 50 D5 */	bl kar_diag__80138a00
/* 80183930 00180730  7C 7F 1B 78 */	mr r31, r3
/* 80183934 00180734  7F A3 EB 78 */	mr r3, r29
/* 80183938 00180738  38 80 00 08 */	li r4, 0x8
/* 8018393C 0018073C  4B ED 21 B5 */	bl kar_lbairride__near_80055af0
/* 80183940 00180740  90 7F 00 0C */	stw r3, 0xc(r31)
/* 80183944 00180744  7F A3 EB 78 */	mr r3, r29
/* 80183948 00180748  38 80 00 09 */	li r4, 0x9
/* 8018394C 0018074C  4B ED 21 A5 */	bl kar_lbairride__near_80055af0
/* 80183950 00180750  90 7F 00 10 */	stw r3, 0x10(r31)
/* 80183954 00180754  7F A3 EB 78 */	mr r3, r29
/* 80183958 00180758  38 80 00 0A */	li r4, 0xa
/* 8018395C 0018075C  4B ED 21 95 */	bl kar_lbairride__near_80055af0
/* 80183960 00180760  90 7F 00 14 */	stw r3, 0x14(r31)
/* 80183964 00180764  7F A3 EB 78 */	mr r3, r29
/* 80183968 00180768  38 80 00 04 */	li r4, 0x4
/* 8018396C 0018076C  4B ED 21 85 */	bl kar_lbairride__near_80055af0
/* 80183970 00180770  90 7F 00 18 */	stw r3, 0x18(r31)
/* 80183974 00180774  93 BE 11 60 */	stw r29, 0x1160(r30)
/* 80183978 00180778  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8018397C 0018077C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80183980 00180780  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80183984 00180784  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80183988 00180788  7C 08 03 A6 */	mtlr r0
/* 8018398C 0018078C  38 21 00 20 */	addi r1, r1, 0x20
/* 80183990 00180790  4E 80 00 20 */	blr
.endfn kar_mnlannumber_create_panel_and_cache_child_jobjs

# .text:0x468 | 0x80183994 | size: 0x44
.fn kar_mnlannumber_destroy_panel, global
/* 80183994 00180794  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80183998 00180798  7C 08 02 A6 */	mflr r0
/* 8018399C 0018079C  90 01 00 14 */	stw r0, 0x14(r1)
/* 801839A0 001807A0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801839A4 001807A4  4B FA D8 3D */	bl fn_801311E0
/* 801839A8 001807A8  7C 7F 1B 78 */	mr r31, r3
/* 801839AC 001807AC  80 63 11 60 */	lwz r3, 0x1160(r3)
/* 801839B0 001807B0  28 03 00 00 */	cmplwi r3, 0x0
/* 801839B4 001807B4  41 82 00 10 */	beq .L_801839C4
/* 801839B8 001807B8  48 2A 55 AD */	bl HSD_GObjDestroy
/* 801839BC 001807BC  38 00 00 00 */	li r0, 0x0
/* 801839C0 001807C0  90 1F 11 60 */	stw r0, 0x1160(r31)
.L_801839C4:
/* 801839C4 001807C4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801839C8 001807C8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801839CC 001807CC  7C 08 03 A6 */	mtlr r0
/* 801839D0 001807D0  38 21 00 10 */	addi r1, r1, 0x10
/* 801839D4 001807D4  4E 80 00 20 */	blr
.endfn kar_mnlannumber_destroy_panel

# .text:0x4AC | 0x801839D8 | size: 0x40
.fn kar_mnlandialogue_get_box0_screen_width, global
/* 801839D8 001807D8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801839DC 001807DC  7C 08 02 A6 */	mflr r0
/* 801839E0 001807E0  90 01 00 24 */	stw r0, 0x24(r1)
/* 801839E4 001807E4  38 61 00 14 */	addi r3, r1, 0x14
/* 801839E8 001807E8  48 00 00 71 */	bl kar_mnlandialogue_project_box0_origin_to_screen
/* 801839EC 001807EC  38 61 00 08 */	addi r3, r1, 0x8
/* 801839F0 001807F0  48 00 01 1D */	bl kar_mnlandialogue_project_box0_right_edge_to_screen
/* 801839F4 001807F4  C0 21 00 08 */	lfs f1, 0x8(r1)
/* 801839F8 001807F8  C0 01 00 14 */	lfs f0, 0x14(r1)
/* 801839FC 001807FC  EC 01 00 28 */	fsubs f0, f1, f0
/* 80183A00 00180800  FC 00 02 10 */	fabs f0, f0
/* 80183A04 00180804  FC 20 00 18 */	frsp f1, f0
/* 80183A08 00180808  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80183A0C 0018080C  7C 08 03 A6 */	mtlr r0
/* 80183A10 00180810  38 21 00 20 */	addi r1, r1, 0x20
/* 80183A14 00180814  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_get_box0_screen_width

# .text:0x4EC | 0x80183A18 | size: 0x40
.fn kar_mnlandialogue_get_box0_screen_height, global
/* 80183A18 00180818  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80183A1C 0018081C  7C 08 02 A6 */	mflr r0
/* 80183A20 00180820  90 01 00 24 */	stw r0, 0x24(r1)
/* 80183A24 00180824  38 61 00 14 */	addi r3, r1, 0x14
/* 80183A28 00180828  48 00 00 31 */	bl kar_mnlandialogue_project_box0_origin_to_screen
/* 80183A2C 0018082C  38 61 00 08 */	addi r3, r1, 0x8
/* 80183A30 00180830  48 00 01 91 */	bl kar_mnlandialogue_project_box0_bottom_edge_to_screen
/* 80183A34 00180834  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 80183A38 00180838  C0 01 00 18 */	lfs f0, 0x18(r1)
/* 80183A3C 0018083C  EC 01 00 28 */	fsubs f0, f1, f0
/* 80183A40 00180840  FC 00 02 10 */	fabs f0, f0
/* 80183A44 00180844  FC 20 00 18 */	frsp f1, f0
/* 80183A48 00180848  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80183A4C 0018084C  7C 08 03 A6 */	mtlr r0
/* 80183A50 00180850  38 21 00 20 */	addi r1, r1, 0x20
/* 80183A54 00180854  4E 80 00 20 */	blr
.endfn kar_mnlandialogue_get_box0_screen_height

# 0x804AD688..0x804AD6B8 | size: 0x30
.data
.balign 8

# .data:0x0 | 0x804AD688 | size: 0xE
.obj kar_src_mnlannumber_c, global
	.string "mnlannumber.c"
.endobj kar_src_mnlannumber_c

# .data:0xE | 0x804AD696 | size: 0x2
.obj gap_07_804AD696_data, global
.hidden gap_07_804AD696_data
	.2byte 0x0000
.endobj gap_07_804AD696_data

# .data:0x10 | 0x804AD698 | size: 0x1C
.obj kar_mnlannumber_scene_models_name, global
	.string "ScMenLanNumber_scene_models"
.endobj kar_mnlannumber_scene_models_name

# .data:0x2C | 0x804AD6B4 | size: 0x4
.obj gap_07_804AD6B4_data, global
.hidden gap_07_804AD6B4_data
	.4byte 0x00000000
.endobj gap_07_804AD6B4_data

# 0x805D6E20..0x805D6E38 | size: 0x18
.section .sdata, "wa"
.balign 8

# .sdata:0x0 | 0x805D6E20 | size: 0x7
.obj kar_srcfile_jobj_h_805d6e20, global
	.string "jobj.h"
.endobj kar_srcfile_jobj_h_805d6e20

# .sdata:0x7 | 0x805D6E27 | size: 0x1
.obj gap_09_805D6E27_sdata, global
.hidden gap_09_805D6E27_sdata
	.byte 0x00
.endobj gap_09_805D6E27_sdata

# .sdata:0x8 | 0x805D6E28 | size: 0x5
.obj lbl_805D6E28, global
	.string "jobj"
.endobj lbl_805D6E28

# .sdata:0xD | 0x805D6E2D | size: 0x3
.obj gap_09_805D6E2D_sdata, global
.hidden gap_09_805D6E2D_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D6E2D_sdata

# .sdata:0x10 | 0x805D6E30 | size: 0x2
.obj lbl_805D6E30, global
	.string "0"
.endobj lbl_805D6E30

# .sdata:0x12 | 0x805D6E32 | size: 0x6
.obj gap_09_805D6E32_sdata, global
.hidden gap_09_805D6E32_sdata
	.4byte 0x00000000
	.2byte 0x0000
.endobj gap_09_805D6E32_sdata

# 0x805E0E70..0x805E0E80 | size: 0x10
.section .sdata2, "a"
.balign 8

# .sdata2:0x0 | 0x805E0E70 | size: 0x4
.obj lbl_805E0E70, global
	.float 0
.endobj lbl_805E0E70

# .sdata2:0x4 | 0x805E0E74 | size: 0x4
.obj lbl_805E0E74, global
	.float 1
.endobj lbl_805E0E74

# .sdata2:0x8 | 0x805E0E78 | size: 0x8
.obj lbl_805E0E78, global
	.float 2
	.float 0
.endobj lbl_805E0E78
