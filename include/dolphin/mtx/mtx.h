#ifndef _MTX_H_
#define _MTX_H_

#include <dolphin/mtx/mtxtypes.h>

f32 mtx_tanf(f32 x);
f32 mtx_sinf(f32 x);
f32 mtx_cosf(f32 x);
void PSMTXIdentity(Mtx m);
void PSMTXCopy(Mtx src, Mtx dst);
void PSMTXConcat(Mtx a, Mtx b, Mtx ab);
BOOL PSMTXInverse(Mtx src, Mtx inv);
void PSMTXScale(Mtx m, f32 xS, f32 yS, f32 zS);
void PSMTXQuat(Mtx m, Quaternion* q);
void C_MTXLookAt(Mtx m, Vec* camPos, Vec* camUp, Vec* target);
void PSMTXMultVec(Mtx m, Vec* src, Vec* dst);
void PSMTXMultVecSR(Mtx m, Vec* src, Vec* dst);

#endif
