#ifndef _KAR_LB_LBAIRRIDE_H_
#define _KAR_LB_LBAIRRIDE_H_

#include <dolphin/types.h>
#include <sysdolphin/forward.h>

typedef struct LbAirRideAnimSet {
    void* unk0;
    HSD_AnimJoint** joints;
    HSD_MatAnimJoint** materials;
    HSD_ShapeAnimDObj** shapes;
} LbAirRideAnimSet;

#if defined(VERSION_GKYJ01)
#define kar_lbairride__near_80054cd4 fn_800543AC
#define kar_lbairride__near_800550bc fn_80054794
#define kar_lbairride__near_800550f4 fn_800547CC
#define kar_lbairride__near_8005523c fn_80054964
#define kar_lbairride__near_80055af0 fn_80055218
#elif defined(VERSION_GKYP01)
#define kar_lbairride__near_80054cd4 fn_80055374
#define kar_lbairride__near_800550bc fn_8005575C
#define kar_lbairride__near_800550f4 fn_80055794
#define kar_lbairride__near_8005523c fn_800558DC
#define kar_lbairride__near_80055af0 fn_80056190
#endif

BOOL kar_lbairride__near_80054cd4(HSD_JObj* jobj);
void kar_lbairride__near_800550bc(HSD_JObj* jobj, u32 mask, f32 rate);
void kar_lbairride__near_800550f4(HSD_JObj* jobj, u32 mask);
void kar_lbairride__near_8005523c(HSD_JObj* jobj, void* arg);
void kar_lbairride__near_80055a30(HSD_JObj* jobj, s32 index,
                                  LbAirRideAnimSet* anim);
void kar_lbairride__near_80055aa8(HSD_JObj* jobj, f32 frame);
void kar_lbairride__near_80055acc(HSD_JObj* jobj, f32 frame);
HSD_JObj* kar_lbairride__near_80055af0(HSD_GObj* gobj, s32 index);

#endif
