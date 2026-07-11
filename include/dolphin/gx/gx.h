#ifndef _GX_H_
#define _GX_H_

#include <dolphin/gx/gxtypes.h>

void GXPixModeSync(void);
void GXSetBlendMode(u32 type, u32 src_factor, u32 dst_factor, u32 op);
void GXSetCullMode(u32 mode);
void GXSetNumTevStages(u8 n);
void GXSetTevOrder(u8 stage, u32 coord, u32 map, u32 color);

#endif
