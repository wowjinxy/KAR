#ifndef _displayfunc_c_
#define _displayfunc_c_

#include <global.h>

#include <sysdolphin/objalloc.h>

#include <sysdolphin/displayfunc_alloc.h>
#include <sysdolphin/jobj.h>
#include <sysdolphin/zlist.h>

void HSD_StateInitDirect(u32 vtxfmt, u32 rendermode);
void HSD_SetZSortMode(s32 mode, s32 sort);
void HSD_JObjDisp(HSD_JObj* jobj, Mtx vmtx, HSD_TrspMask trsp_mask, u32 rendermode);
void HSD_JObjDispDObj(HSD_JObj* jobj, Mtx vmtx, HSD_TrspMask trsp_mask, u32 rendermode);
void HSD_JObjDispSub(HSD_JObj* jobj, Mtx vmtx, Mtx pmtx, HSD_TrspMask trsp_mask,
                     u32 rendermode);
void HSD_JObjMakePositionMtx(HSD_JObj* jobj, Mtx vmtx, Mtx pmtx);
MtxPtr _HSD_mkEnvelopeModelNodeMtx(HSD_JObj* jobj, Mtx dst);

#endif
