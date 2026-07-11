#ifndef _GX_H_
#define _GX_H_

#include <dolphin/gx/gxtypes.h>
#include <dolphin/mtx/mtxtypes.h>

void GXBegin(u8 prim, u8 vtxfmt, u16 nverts);
void GXClearVtxDesc(void);
void GXLoadPosMtxImm(MtxPtr mtx, u32 id);
void GXPixModeSync(void);
void GXSetAlphaCompare(u32 comp0, u8 ref0, u32 op, u32 comp1, u8 ref1);
void GXSetAlphaUpdate(u32 enable);
void GXSetBlendMode(u32 type, u32 src_factor, u32 dst_factor, u32 op);
void GXSetColorUpdate(u32 enable);
void GXSetCullMode(u32 mode);
void GXSetCurrentMtx(u32 id);
void GXSetNumChans(u8 n);
void GXSetNumTevStages(u8 n);
void GXSetTevOrder(u8 stage, u32 coord, u32 map, u32 color);
void GXSetVtxAttrFmt(u32 vtxfmt, u32 attr, u32 comp_cnt, u32 comp_type, u8 frac);
void GXSetVtxDesc(u32 attr, u32 type);
void GXSetZCompLoc(u32 before_tex);
void GXSetZMode(u32 enable, u32 func, u32 update);

#endif
