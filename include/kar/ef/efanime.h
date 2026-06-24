#ifndef __EFANIME_H_
#define __EFANIME_H_

#include <dolphin/types.h>
#include <sysdolphin/gobj.h>

typedef struct EffectObject EffectObject;

struct EffectObject {
    u8 pad_00[0x18];
    void* request;
    u8 pad_1C[0x09];
    u8 pad_25_0 : 2;
    u8 active : 1;
    u8 pad_25_3 : 5;
    u8 pad_26[0x36];
    HSD_GObj* gobj;
};

s32 kar_efanime__8023fddc(HSD_GObj* gobj, s32 index, f32 frame, s32 flags);
s32 kar_efanime__near_8023ff5c(HSD_GObj* gobj, s32 index, f32 frame);
void kar_efanime__near_8023ff80(EffectObject* effect, s32 index, f32 frame);
void kar_efanime__8023ffc4(EffectObject* effect);
void kar_efanime__near_80240040(EffectObject* effect);
s32 kar_efanime__near_80240084(HSD_GObj* gobj);
void kar_efanime__near_80240114(HSD_GObj* gobj, f32 rate);
void kar_efanime__near_80240154(EffectObject* effect, f32 rate);
void kar_efanime__near_802401ac(HSD_GObj* gobj, f32 frame);
f32 kar_efanime__near_802401e8(HSD_GObj* gobj);

#endif
