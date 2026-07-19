#ifndef KAR_EM_EMCAMERA_H
#define KAR_EM_EMCAMERA_H

#include <dolphin/types.h>
#include <dolphin/mtx/mtxtypes.h>
#include <kar/em/emanim.h>
#include <sysdolphin/gobj.h>

#if defined(VERSION_GKYJ01)
#define kar_emcamera__80206d90 fn_80202FAC
#define kar_emcamera__near_80206e1c fn_80203038
#define kar_emcamera__near_80206e2c fn_80203048
#define kar_emcamera__near_80206f00 fn_8020311C
#define kar_emcamera__near_802070b8 fn_802032B0
#define kar_emcamera__near_802070e8 fn_802032E0
#define kar_emcamera__near_8020728c fn_80203484
#define kar_emcamera__near_8020789c fn_80203A94
#define kar_emcamera__near_80207ce8 fn_80203EE0
#define kar_emcamera__near_80207dec fn_80203FE4
#define kar_emcamera__near_80208008 fn_80204200
#define kar_emcamera__near_80208010 fn_80204208
#define kar_emcamera__near_802081ec fn_802043E4
#elif defined(VERSION_GKYP01)
#define kar_emcamera__80206d90 fn_80207A64
#define kar_emcamera__near_80206e1c fn_80207AF0
#define kar_emcamera__near_80206e2c fn_80207B00
#define kar_emcamera__near_80206f00 fn_80207BD4
#define kar_emcamera__near_802070b8 fn_80207D8C
#define kar_emcamera__near_802070e8 fn_80207DBC
#define kar_emcamera__near_8020728c fn_80207F60
#define kar_emcamera__near_8020789c fn_80208570
#define kar_emcamera__near_80207ce8 fn_802089BC
#define kar_emcamera__near_80207dec fn_80208AC0
#define kar_emcamera__near_80208008 fn_80208CDC
#define kar_emcamera__near_80208010 fn_80208CE4
#define kar_emcamera__near_802081ec fn_80208EC0
#endif

BOOL kar_emcamera__80206d90(HSD_GObj* gobj, Vec* pos);
void kar_emcamera__near_80206e1c(EmAnim* anim, BOOL value);
void kar_emcamera__near_80206e2c(EmAnim* anim);
s32 kar_emcamera__near_80206f00(EmAnim* anim);
f32 kar_emcamera__near_802070b8(EmAnim* anim, f32 value);
s32 kar_emcamera__near_802070e8(EmAnim* anim);
void kar_emcamera__near_8020728c(EmAnim* anim, BOOL reset);
f32 kar_emcamera__near_8020789c(f32 angle);
void kar_emcamera__near_80207ce8(EmAnim* anim);
void kar_emcamera__near_80207dec(EmAnim* anim);
BOOL kar_emcamera__near_80208008(EmAnim* anim);
void kar_emcamera__near_80208010(EmAnim* anim);
BOOL kar_emcamera__near_802081ec(EmAnim* anim);

#endif
