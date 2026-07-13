#ifndef _tev_state_h_
#define _tev_state_h_

#include <global.h>

#include <sysdolphin/objalloc.h>

void HSD_StateInvalidate(s32 mask);
void HSD_RenderInitAllocData(void);
HSD_ObjAllocData* HSD_RenderGetAllocData(void);
HSD_ObjAllocData* HSD_TevRegGetAllocData(void);
HSD_ObjAllocData* HSD_ChanGetAllocData(void);
u32 HSD_StateAssignTev(void);

#endif
