#ifndef _GX_H_
#define _GX_H_

#include <dolphin/gx/gxtypes.h>
#include <dolphin/mtx/mtxtypes.h>

void GXBegin(u8 prim, u8 vtxfmt, u16 nverts);
void GXClearVtxDesc(void);
void GXGetProjectionv(f32* ptr);
void GXGetViewportv(f32* vp);
void GXInvalidateTexAll(void);
void GXInvalidateVtxCache(void);
void GXInitFogAdjTable(void* table, u16 width, Mtx44Ptr projmtx);
void GXLoadPosMtxImm(MtxPtr mtx, u32 id);
void GXLoadTexMtxImm(MtxPtr mtx, u32 id, u32 type);
void GXPixModeSync(void);
void GXSetProjection(Mtx mtx, s32 projection_type);
void GXSetScissor(u32 left, u32 top, u32 width, u32 height);
void GXSetAlphaCompare(u32 comp0, u8 ref0, u32 op, u32 comp1, u8 ref1);
void GXSetAlphaUpdate(u32 enable);
void GXSetBlendMode(u32 type, u32 src_factor, u32 dst_factor, u32 op);
void GXSetChanAmbColor(u32 chan, GXColor color);
void GXSetChanMatColor(u32 chan, GXColor color);
void GXSetColorUpdate(u32 enable);
void GXSetCullMode(u32 mode);
void GXSetCurrentMtx(u32 id);
void GXSetDither(u32 enable);
void GXSetDstAlpha(u32 enable, u8 value);
void GXSetFog(u32 type, f32 startz, f32 endz, f32 nearz, f32 farz, GXColor color);
void GXSetFogRangeAdj(u32 enable, u16 center, void* table);
void GXSetLineWidth(u8 width, u32 tex_offsets);
void GXSetNumChans(u8 n);
void GXSetNumTevStages(u8 n);
void GXSetPointSize(u8 size, u32 tex_offsets);
void GXSetTevAlphaIn(u8 stage, u32 a, u32 b, u32 c, u32 d);
void GXSetTevAlphaOp(u8 stage, u32 op, u32 bias, u32 scale, u32 clamp, u32 out_reg);
void GXSetTevColor(u32 id, GXColor color);
void GXSetTevColorS10(u32 reg, GXColorS10 color);
void GXSetTevColorIn(u8 stage, u32 a, u32 b, u32 c, u32 d);
void GXSetTevColorOp(u8 stage, u32 op, u32 bias, u32 scale, u32 clamp, u32 out_reg);
void GXSetTevKAlphaSel(u8 stage, u32 sel);
void GXSetTevKColor(u32 id, GXColor color);
void GXSetTevKColorSel(u8 stage, u32 sel);
void GXSetTevOp(u8 stage, u32 mode);
void GXSetTevOrder(u8 stage, u32 coord, u32 map, u32 color);
void GXSetTevSwapMode(u8 stage, u32 ras_swap, u32 tex_swap);
void GXSetViewport(f32 left, f32 top, f32 width, f32 height, f32 near_z, f32 far_z);
void GXSetViewportJitter(f32 left, f32 top, f32 width, f32 height, f32 near_z,
                         f32 far_z, u32 field);
void GXSetVtxAttrFmt(u32 vtxfmt, u32 attr, u32 comp_cnt, u32 comp_type, u8 frac);
void GXSetVtxDesc(u32 attr, u32 type);
void GXSetZCompLoc(u32 before_tex);
void GXSetZMode(u32 enable, u32 func, u32 update);

#endif
