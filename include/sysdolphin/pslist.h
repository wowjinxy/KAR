#ifndef _pslist_h_
#define _pslist_h_

#include <dolphin/types.h>

#include <sysdolphin/forward.h>

struct HSD_Particle {
    struct HSD_Particle* next; //0x00
    u8 pad04[0x19];
    u8 linkNo; //0x1D
};

void _psListDelete(HSD_Particle* pp, HSD_Particle* parent);
HSD_Particle* _psListGetFirst(s32 linkNo);

#endif
