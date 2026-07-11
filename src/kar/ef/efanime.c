#include "functions.h"
#include <dolphin/types.h>
#include <kar/ef/efanime.h>
#include <kar/ef/efcallback.h>
#include <kar/ef/efcontrol.h>
#include <kar/ef/efdata.h>
#include <kar/ef/efrequest2.h>
#include <sysdolphin/aobj.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/gobjuserdata.h>
#include <sysdolphin/jobj.h>

#if defined(VERSION_GKYJ01)
#define kar_src_efanime_804b5628 lbl_804B0370
#define lbl_804B5638 lbl_804B0380
#define lbl_805D7300 lbl_805D1D40
#define lbl_805D7308 lbl_805D1D48
#define kar_srcfile_aobj_h_805d7310 lbl_805D1D50
#define lbl_805D7318 lbl_805D1D58
#define lbl_805E2B20 lbl_805DD390
#define lbl_8055DA08 lbl_805584E0
#define kar_lbairride__near_800550f4 fn_800547CC
#define kar_efdata__near_802369e0 fn_8023296C
#define kar_efdata__near_802369f0 fn_8023297C
#define kar_efrequest2__8023cc20 fn_80238BAC
#define kar_efcontrol__near_8023f4e4 fn_8023B470
#define kar_efcontrol__near_8023f514 fn_8023B4A0
#define kar_efcontrol__near_8023f8f8 fn_8023B884
#define ExPPC_UnwindStack fn_803A915C
#elif defined(VERSION_GKYP01)
#define kar_src_efanime_804b5628 lbl_804BAE18
#define lbl_804B5638 lbl_804BAE28
#define lbl_805D7300 lbl_805C9CE8
#define lbl_805D7308 lbl_805C9CF0
#define kar_srcfile_aobj_h_805d7310 lbl_805C9CF8
#define lbl_805D7318 lbl_805C9D00
#define lbl_805E2B20 lbl_805D55B8
#define lbl_8055DA08 lbl_80550378
#define kar_lbairride__near_800550f4 fn_80055794
#define kar_efdata__near_802369e0 fn_802376BC
#define kar_efdata__near_802369f0 fn_802376CC
#define kar_efrequest2__8023cc20 fn_8023D8E4
#define kar_efcontrol__near_8023f4e4 fn_802401A8
#define kar_efcontrol__near_8023f514 fn_802401D8
#define kar_efcontrol__near_8023f8f8 fn_802405BC
#define ExPPC_UnwindStack fn_803B06F8
#endif

#define EFFECT_OBJECT_ACTIVE(effect) \
    ((effect) != NULL && (effect)->active)

char kar_src_efanime_804b5628[0x10] = "efanime.c";
char lbl_804B5638[] = "effect: no support arg type = %d ";

char lbl_805D7300[8] = "model";
char lbl_805D7308[8] = "jobj";
char kar_srcfile_aobj_h_805d7310[8] = "aobj.h";
char lbl_805D7318[8] = "aobj";

const f32 lbl_805E2B20[2] = { 0.0f, 0.0f };

extern char lbl_8055DA08[];

void kar_efcontrol__near_8023f514(HSD_GObj* gobj);
void kar_efcontrol__near_8023f4e4(void);
void kar_efcontrol__near_8023f8f8(HSD_JObj* jobj, void* joint_anim,
                                  void* mat_anim, void* shape_anim,
                                  s32 flags);
void kar_efdata__near_802369e0(void* data);
void kar_efdata__near_802369f0(void);
HSD_JObj* kar_efrequest2__8023cc20(void* request);
void kar_lbairride__near_800550f4(HSD_JObj* jobj, u32 flags);
s32 ExPPC_UnwindStack(void* unwind);

s32 kar_efanime__8023fddc(HSD_GObj* gobj, s32 index, f32 frame, s32 flags)
{
    register HSD_JObj* jobj;
    register EffectCtrl* ctrl;
    EffectAnimResource* resource;
    void* joint_anim;
    void* mat_anim;
    void* shape_anim;

    ctrl = gobj->user_data;
    jobj = gobj->hsd_obj;
    resource = kar_efcallback__near_80235190(ctrl->anim_resource_id);
    if (resource == NULL) {
        __assert(kar_src_efanime_804b5628, 0xC8, lbl_805D7300);
    }

    if (resource->joint_anims != NULL && resource->joint_anims[index] != NULL) {
        goto found;
    }
    if (resource->mat_anims != NULL && resource->mat_anims[index] != NULL) {
        goto found;
    }
    if (resource->shape_anims == NULL || resource->shape_anims[index] == NULL) {
        goto not_found;
    }

found:
    if (ctrl->proc == NULL) {
        ctrl->proc =
            HSD_GObjProcCreate(gobj, kar_efcontrol__near_8023f514, 1);
    }

    if (ctrl->field_08 != NULL) {
        kar_efdata__near_802369e0(*(void**) ((u8*) ctrl->field_08 + 0x1C));
    }

    ctrl->anim_index = index;

    if (resource->shape_anims != NULL) {
        shape_anim = resource->shape_anims[index];
    } else {
        shape_anim = NULL;
    }

    if (resource->mat_anims != NULL) {
        mat_anim = resource->mat_anims[index];
    } else {
        mat_anim = NULL;
    }

    if (resource->joint_anims != NULL) {
        joint_anim = resource->joint_anims[index];
    } else {
        joint_anim = NULL;
    }

    kar_efcontrol__near_8023f8f8(jobj, joint_anim, mat_anim, shape_anim,
                                 flags);
    HSD_JObjReqAnimAllByFlags(jobj, flags, frame);
    kar_efdata__near_802369f0();
    return 1;

not_found:
    return 0;
}

#pragma dont_inline on
s32 kar_efanime__near_8023ff5c(HSD_GObj* gobj, s32 index, f32 frame)
{
    return kar_efanime__8023fddc(gobj, index, frame, 0x7FF);
}
#pragma dont_inline off

void kar_efanime__near_8023ff80(EffectObject* effect, s32 index, f32 frame)
{
    EffectCtrl* ctrl;

    if (EFFECT_OBJECT_ACTIVE(effect)) {
        ctrl = effect->gobj->user_data;
        ctrl->anim_index = index;
        kar_efanime__near_8023ff5c(ctrl->gobj, index, frame);
    }
}

void kar_efanime__8023ffc4(EffectObject* effect)
{
    HSD_JObj* jobj;

    if (EFFECT_OBJECT_ACTIVE(effect)) {
        HSD_GObjObjectRemove(effect->gobj);
        jobj = kar_efrequest2__8023cc20(effect->request);
        if (jobj == NULL) {
            __assert(kar_src_efanime_804b5628, 0x13B, lbl_805D7308);
        }
        HSD_GObjObjectLink(effect->gobj, hsdGObj_jobj_kind, jobj);
    }
}

void kar_efanime__near_80240040(EffectObject* effect)
{
    if (EFFECT_OBJECT_ACTIVE(effect)) {
        kar_lbairride__near_800550f4(effect->gobj->hsd_obj, 0xFFFF);
    }
}

// NONMATCHING: behavior matches; remaining diff is address-register scheduling
// around ExPPC_UnwindStack.
s32 kar_efanime__near_80240084(HSD_GObj* gobj)
{
    register HSD_JObj* jobj = gobj->hsd_obj;
    HSD_AObj* aobj;

    aobj = NULL;

    if (ExPPC_UnwindStack(lbl_8055DA08) == 0) {
        HSD_ForeachAnim(jobj, 6, 0xFFFF, kar_efcontrol__near_8023f4e4,
                        2, &aobj);
    }

    if (aobj != NULL && (HSD_AObjGetFlags(aobj) & 0x60000000) == 0) {
        return 0;
    }

    return 1;
}

void kar_efanime__near_80240114(HSD_GObj* gobj, f32 rate)
{
    HSD_ForeachAnim(gobj->hsd_obj, 6, 0xFFFF, (void (*)()) HSD_AObjSetRate,
                    1, rate);
}

void kar_efanime__near_80240154(EffectObject* effect, f32 rate)
{
    if (EFFECT_OBJECT_ACTIVE(effect)) {
        HSD_ForeachAnim(effect->gobj->hsd_obj, 6, 0xFFFF,
                        (void (*)()) HSD_AObjSetRate, 1, rate);
    }
}

void kar_efanime__near_802401ac(HSD_GObj* gobj, f32 frame)
{
    HSD_JObj* jobj = gobj->hsd_obj;

    HSD_JObjReqAnimAllByFlags(jobj, 0x7FF, frame);
    HSD_JObjAnimAll(jobj);
}

// NONMATCHING: same AObj scan shape as 80240084, plus minor assert-tail
// scheduling around the found AObj.
f32 kar_efanime__near_802401e8(HSD_GObj* gobj)
{
    register HSD_JObj* jobj = gobj->hsd_obj;
    HSD_AObj* aobj;
    register HSD_AObj* found;

    aobj = NULL;

    if (ExPPC_UnwindStack(lbl_8055DA08) == 0) {
        HSD_ForeachAnim(jobj, 6, 0xFFFF, kar_efcontrol__near_8023f4e4,
                        2, &aobj);
    }

    found = aobj;
    if (found != NULL) {
        if (found == NULL) {
            __assert(kar_srcfile_aobj_h_805d7310, 0xAB, lbl_805D7318);
        }
        return found->end_frame;
    }

    return lbl_805E2B20[0];
}
