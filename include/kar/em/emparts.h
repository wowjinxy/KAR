#ifndef KAR_EM_EMPARTS_H
#define KAR_EM_EMPARTS_H

#include <dolphin/types.h>
#include <kar/em/emanim.h>

#if defined(VERSION_GKYJ01)
#define kar_emparts__802026d4 fn_801FE9A0
#define kar_emparts__80202a40 fn_801FED0C
#define kar_emparts__near_80202b88 fn_801FEE54
#define kar_emparts__near_80202c18 fn_801FEEE4
#define kar_emparts__near_80202c80 fn_801FEF4C
#define kar_emparts__near_80202d60 fn_801FF02C
#define kar_emparts__near_8020335c fn_801FF628
#define kar_emparts__near_80203458 fn_801FF724
#elif defined(VERSION_GKYP01)
#define kar_emparts__802026d4 fn_802033A8
#define kar_emparts__80202a40 fn_80203714
#define kar_emparts__near_80202b88 fn_8020385C
#define kar_emparts__near_80202c18 fn_802038EC
#define kar_emparts__near_80202c80 fn_80203954
#define kar_emparts__near_80202d60 fn_80203A34
#define kar_emparts__near_8020335c fn_80204030
#define kar_emparts__near_80203458 fn_8020412C
#endif

void kar_emparts__802026d4(EmAnim* anim);
void kar_emparts__80202a40(EmAnim* anim);
void kar_emparts__near_80202b88(EmAnim* anim);
void kar_emparts__near_80202c18(EmAnim* anim, s32 index, s32 value);
void kar_emparts__near_80202c80(void* config, s32 kind, void* tables);
void kar_emparts__near_80202d60(EmAnim* anim, s32 mode);
void kar_emparts__near_8020335c(EmAnim* anim);
void kar_emparts__near_80203458(EmAnim* anim);

#endif
