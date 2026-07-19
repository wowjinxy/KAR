#ifndef KAR_EM_EMANIM_H
#define KAR_EM_EMANIM_H

#include <dolphin/types.h>
#include <dolphin/mtx/mtxtypes.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/jobj.h>

typedef struct EmAnim EmAnim;

void kar_emanim__near_801ff2bc(HSD_JObj* jobj, f32 alpha);
void kar_emanim__near_801ff520(HSD_GObj* gobj);
void kar_emanim__near_801ff698(HSD_GObj* gobj);
BOOL kar_emanim__near_801ff72c(HSD_GObj* gobj);
void kar_emanim__near_801ff754(EmAnim* anim);
void kar_emanim__near_801ff7b0(EmAnim* anim);
BOOL kar_emanim__near_801ff80c(s32 player_id, void* arg1, void* arg2);
void kar_emanim__near_801ff864(void* arg0, s32 arg1);
BOOL kar_emanim__near_801ff884(EmAnim* anim);
BOOL kar_emanim__near_801ff8b4(EmAnim* anim);
f32 kar_emanim__near_801ffccc(EmAnim* anim);
s32 kar_emanim__near_801ffce4(EmAnim* anim, f32 max_distance);
void kar_emanim__near_801fff84(s32 slot, Vec* out);
f32 kar_emanim__near_801fffa4(s32 slot, Vec* pos);
void kar_emanim__near_80200004(EmAnim* anim);
void kar_emanim__near_802000ac(EmAnim* anim);
void kar_emanim__near_802000c0(EmAnim* anim);
void kar_emanim__near_802000d4(EmAnim* anim);
void kar_emanim__near_8020012c(EmAnim* anim);
void kar_emanim__near_80200180(EmAnim* anim, BOOL visible);
void kar_emanim__near_802001bc(EmAnim* anim);
u32 kar_emanim__near_802005e0(EmAnim* anim);
void kar_emanim__near_80200604(EmAnim* anim);
s32 kar_emanim__near_80200638(void);
#if !defined(VERSION_GKYJ01)
BOOL kar_emanim__near_8020065c(EmAnim* anim);
#endif
void kar_emanim__near_8020067c(EmAnim* anim);
void kar_emanim__near_802006b4(EmAnim* anim);
void kar_emanim__near_8020072c(EmAnim* anim);
void kar_emanim__near_802007e0(void);
void kar_emanim__near_80200ba4(EmAnim* anim);
void kar_emanim__near_80200bd8(EmAnim* anim);
void kar_emanim__near_80200c04(EmAnim* anim, f32 frame, f32 rate);
BOOL kar_emanim__near_80200d10(EmAnim* anim);
void kar_emanim__near_80200df4(EmAnim* anim, s32 index, f32 rate);
void kar_emanim__near_80201138(EmAnim* anim, void* bytecode);
void kar_emanim__near_80201180(EmAnim* anim, void* bytecode);
void kar_emanim__near_80201798(EmAnim* anim, void* bytecode);
void kar_emanim__near_802018ec(EmAnim* anim, void* arg1);
void* kar_emanim__near_80201904(EmAnim* anim);
void kar_emanim__near_80201928(EmAnim* anim, void* bytecode);
void kar_emanim__near_80201948(EmAnim* anim, void* bytecode);
void* kar_emanim__near_802019fc(EmAnim* anim, s32 arg1, s32 arg2);
void* kar_emanim__near_80201a34(EmAnim* anim);
void* kar_emanim__near_80201ad0(EmAnim* anim);
void* kar_emanim__near_80201af4(EmAnim* anim);
void* kar_emanim__near_80201b18(EmAnim* anim);
void* kar_emanim__near_80201b3c(EmAnim* anim, void* arg1);
void kar_emanim__near_80201b6c(EmAnim* anim);

#endif
