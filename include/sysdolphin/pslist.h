#ifndef _pslist_h_
#define _pslist_h_

#include <dolphin/types.h>

#include <sysdolphin/forward.h>

void _psListDelete(HSD_Particle* pp, HSD_Particle* parent);
HSD_Particle* _psListGetFirst(s32 linkNo);

#endif
