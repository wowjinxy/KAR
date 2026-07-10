#ifndef _util_h_
#define _util_h_

#include <global.h>

#include <dolphin/gx/gxtypes.h>
#include <sysdolphin/objalloc.h>

void HSD_MulColor(GXColor* arg0, GXColor* arg1, GXColor* dest);
u32 HSD_GetNbBits(u32 arg0);
void HSD_ObjSetHeap(u32 size, void* ptr);

#endif
