#ifndef _mtx_h_
#define _mtx_h_

#include <global.h>
#include <dolphin/mtx/mtxtypes.h>
#include <sysdolphin/mtx_inverse.h>
#include <sysdolphin/mtx_transform.h>
#include <sysdolphin/objalloc.h>
#include <sysdolphin/vec_alloc.h>
#include <sysdolphin/vec_orthogonal.h>

void HSD_MtxInverse(Mtx src, Mtx dest);
void HSD_MtxGetRotationMtx(Mtx v0, Mtx dest, char axis0, char axis1);
void HSD_MkRotationMtx(Mtx arg0, Vec* arg1);
void HSD_MtxScaledAdd(Mtx arg0, Mtx arg1, Mtx arg2, f32 arg3);
void* HSD_MtxAlloc(void);
void HSD_MtxFree(void* arg0);
HSD_ObjAllocData* HSD_VecGetAllocData(void);
void HSD_VecInitAllocData(void);
HSD_ObjAllocData* HSD_MtxGetAllocData(void);
void HSD_MtxInitAllocData(void);

s32 QuatMul(Quaternion* p, Quaternion* q, Quaternion* out);
s32 QuatSetUp(Vec* axis, Quaternion* q, f32 angle);
s32 EulerToQuat(Vec* euler, Quaternion* q);
s32 QuatSlerp(Quaternion* p, Quaternion* q, Quaternion* out, f32 t);

inline f32 fabsf_bitwise(f32 v)
{
    *(u32*)&v &= ~0x80000000;
    return v;
}

#endif
