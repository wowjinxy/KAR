#ifndef _KAR_LB_LBVECTOR_H_
#define _KAR_LB_LBVECTOR_H_

#include <dolphin/types.h>
#include <dolphin/mtx/mtxtypes.h>

#if defined(VERSION_GKYJ01)
#define kar_lbvector_lerp_float_table_sample fn_80062374
#define kar_lbvector_cross_normalize fn_800624F8
#define kar_lbvector_project_world_to_screen fn_80063BD4
#define kar_lbvector__near_8006595c fn_80065084
#elif defined(VERSION_GKYP01)
#define kar_lbvector_lerp_float_table_sample fn_8006355C
#define kar_lbvector_cross_normalize fn_800636E0
#define kar_lbvector_project_world_to_screen fn_80064DEC
#define kar_lbvector__near_8006595c fn_8006629C
#endif

f32 kar_lbvector_lerp_float_table_sample(void* table, f32 arg1, f32 arg2);
void kar_lbvector_normalize_with_axis_fallback(Vec* dst, Vec* src);
void kar_lbvector_cross_normalize(Vec* a, Vec* b, Vec* out);
void kar_lbvector_project_world_to_screen(void* cobj, Vec* world, Vec* screen,
                                          s32 arg3);
void kar_lbvector__near_8006595c(void);

#endif
