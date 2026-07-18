#ifndef KAR_LB_LBCAMERA_H
#define KAR_LB_LBCAMERA_H

#include <dolphin/types.h>
#include <sysdolphin/cobj.h>

HSD_CObj* kar_lbcamera_load_desc_update_aspect(HSD_CObjDesc* desc);
void kar_lbcamera_apply_viewport_preset1(HSD_CObj* cobj);
void kar_lbcamera_apply_viewport_preset2(HSD_CObj* cobj);
void kar_lbcamera_apply_viewport_preset3(HSD_CObj* cobj);
void kar_lbcamera_apply_viewport_preset4(HSD_CObj* cobj);
void kar_lbcamera_apply_split_viewport_preset1(HSD_CObj* cobj, s32 player);
void kar_lbcamera_apply_quad_viewport_preset1(HSD_CObj* cobj, s32 player);
void kar_lbcamera__near_80068574(Scissor* rect);
void kar_lbcamera__near_80068588(s32 player, Scissor* rect);
void kar_lbcamera__near_800685ac(s32 player, Scissor* rect);

#endif
