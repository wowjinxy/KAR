#ifndef _VEC_H_
#define _VEC_H_

#include <dolphin/mtx/mtxtypes.h>

void PSVECSubtract(Vec* a, Vec* b, Vec* result);
void PSVECAdd(Vec* a, Vec* b, Vec* result);
void PSVECNormalize(Vec* src, Vec* unit);
f32 PSVECSquareMag(Vec* v);
f32 PSVECMag(Vec* v);
f32 PSVECDotProduct(Vec* a, Vec* b);
void PSVECCrossProduct(Vec* a, Vec* b, Vec* result);
void PSVECReflect(Vec* src, Vec* normal, Vec* dst);
f32 PSVECSquareDistance(Vec* a, Vec* b);
f32 PSVECDistance(Vec* a, Vec* b);

#endif
