#ifndef _lobj_setup_h_
#define _lobj_setup_h_

#include <dolphin/gx/gxtypes.h>
#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>
#include <sysdolphin/forward.h>

HSD_LObj* HSD_LObjGetActiveByID(u32 id);
HSD_LObj* HSD_LObjGetActiveByIndex(s32 idx);
void HSD_LObjSetup(HSD_LObj* lobj, GXColor* color, f32 shininess);
void HSD_LObjSetupInit(HSD_CObj* cobj);
void HSD_LObjSetupSpecularInit(Mtx pmtx);

#endif
