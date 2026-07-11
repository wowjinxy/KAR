#ifndef _KAR_LB_LBVECTOR_H_
#define _KAR_LB_LBVECTOR_H_

#include <dolphin/types.h>
#include <dolphin/mtx/mtxtypes.h>

#if defined(VERSION_GKYJ01)
#define kar_lbvector_project_world_to_screen fn_80063BD4
#elif defined(VERSION_GKYP01)
#define kar_lbvector_project_world_to_screen fn_80064DEC
#endif

void kar_lbvector_normalize_with_axis_fallback(Vec* dst, Vec* src);
void kar_lbvector_project_world_to_screen(void* cobj, Vec* world, Vec* screen,
                                          s32 arg3);

#endif
