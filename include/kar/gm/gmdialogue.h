#ifndef __GMDIALOGUE_H_
#define __GMDIALOGUE_H_

#include <dolphin/types.h>

typedef struct GmDialogueWork GmDialogueWork;

struct GmDialogueWork {
    s8 field_0;
    s8 field_1;
    s8 field_2;
    s8 field_3;
    s8 field_4;
    s8 state;
    s8 field_6;
    s8 result;
    s8 field_8;
    s8 field_9;
    s8 field_A;
    s8 force_save_dialogue;
};

void kar_gmdialogue__near_800460bc(void);
void kar_gmdialogue__near_800461a0(void);
void kar_gmdialogue__near_800461c4(void);
void kar_gmdialogue__near_800461e4(void);
void kar_gmdialogue__near_800462a4(void);
void kar_gmdialogue__near_800462c8(void);
void* kar_gmdialogue__near_8004640c(void);
void kar_gmdialogue__near_80046430(void);
void kar_gmdialogue__near_80046d48(void);
void kar_gmdialogue__near_80046da0(void);
void kar_gmdialogue__near_80046dc8(void);
void kar_gmdialogue__near_80046df0(void);
void kar_gmdialogue__near_80046ff0(void);
void kar_gmdialogue__near_8004730c(void);
void kar_gmdialogue__near_80047330(void);
s32 kar_gmdialogue__near_80047350(void);
void kar_gmdialogue__near_80047380(void);
void kar_gmdialogue__near_800473d0(void);
void kar_gmdialogue__near_800473f0(void);
void kar_gmdialogue__near_800476b8(void);
void kar_gmdialogue__near_800477ac(void);
GmDialogueWork* kar_diagnostic__80047844(void);
void kar_gmdialogue__near_80047864(void);
void kar_gmdialogue__8004788c(s32 state);
void kar_gmdialogue__80047a08(void);
void kar_gmdialogue__near_80047b4c(void);
void kar_gmdialogue__near_80047d60(void);
void kar_gmdialogue__near_80047f0c(void);
void kar_gmdialogue__near_80047f30(void);
s32 kar_diag__800480b8(s32 status);
void kar_diag__800481dc(void);
void kar_gmdialoguesub__near_80048370(void);
void kar_gmdialoguesub__near_800483c0(void);
void kar_gmdialoguesub__near_8004840c(void);
void kar_gmdialoguesub__near_80048440(void);
void kar_gmdialoguesub__near_80048490(void);
void kar_gmdialoguesub__near_800484d8(void);
void kar_gmdialoguesub__near_80048514(void);
void kar_gmdialoguesub__near_80048548(void);
void kar_gmdialoguesub__near_8004857c(void);
void kar_gmdialoguesub__near_800485b0(void);
void kar_gmdialoguesub__near_80048600(void);
void kar_gmdialoguesub__near_80048644(void);
void kar_gmdialoguesub__near_80048678(void);
void kar_gmdialoguesub__near_800486ac(void);
void kar_gmdialoguesub__near_800486e0(void);
void kar_gmdialoguesub__near_80048714(void);
void kar_gmdialoguesub__near_80048748(void);
void kar_gmdialoguesub__8004877c(void);
void kar_gmdialoguesub__near_800487ac(void);
void kar_gmdialoguesub__near_80048800(void);
void kar_gmdialoguesub__near_80048854(void);
void kar_gmdialoguesub__80048888(void);
void kar_gmdialoguesub__near_800488b8(void);
void kar_diag__800488ec(void);
void kar_gmdialoguesub__near_80048a24(void);
void kar_gmdialoguesub__near_80048a70(void);
void kar_gmdialoguesub__near_80048a98(void);
void kar_gmdialoguesub__near_80048ad4(void);
void kar_gmdialoguesub__near_80048b10(void);
void kar_gmdialoguesub__near_80048b78(void);
void kar_gmdialoguesub__near_80048bac(void);
void kar_gmdialoguesub__near_80048be4(void);

#endif
