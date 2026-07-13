#include "dolphin/types.h"
#include "dolphin/mtx/mtxtypes.h"

extern const f32 vec_half;
extern const f32 vec_three;

asm void PSVECSubtract(Vec* a, Vec* b, Vec* result)
{
    nofralloc
    psq_l f2, 0(r3), 0, 0
    psq_l f4, 0(r4), 0, 0
    ps_sub f6, f2, f4
    psq_st f6, 0(r5), 0, 0
    psq_l f3, 8(r3), 1, 0
    psq_l f5, 8(r4), 1, 0
    ps_sub f7, f3, f5
    psq_st f7, 8(r5), 1, 0
    blr
}

asm void PSVECScale(Vec* src, Vec* dst, f32 scale)
{
    nofralloc
    psq_l f0, 0(r3), 0, 0
    psq_l f2, 8(r3), 1, 0
    ps_muls0 f0, f0, f1
    psq_st f0, 0(r4), 0, 0
    ps_muls0 f0, f2, f1
    psq_st f0, 8(r4), 1, 0
    blr
}

asm void PSVECNormalize(Vec* src, Vec* unit)
{
    nofralloc
    lfs f0, vec_half(r0)
    lfs f1, vec_three(r0)
    psq_l f2, 0(r3), 0, 0
    ps_mul f5, f2, f2
    psq_l f3, 8(r3), 1, 0
    ps_madd f4, f3, f3, f5
    ps_sum0 f4, f4, f3, f5
    frsqrte f5, f4
    fmuls f6, f5, f5
    fmuls f0, f5, f0
    fnmsubs f6, f6, f4, f1
    fmuls f5, f6, f0
    ps_muls0 f2, f2, f5
    psq_st f2, 0(r4), 0, 0
    ps_muls0 f3, f3, f5
    psq_st f3, 8(r4), 1, 0
    blr
}

asm f32 PSVECSquareMag(Vec* v)
{
    nofralloc
    psq_l f0, 0(r3), 0, 0
    ps_mul f0, f0, f0
    lfs f1, 8(r3)
    ps_madd f1, f1, f1, f0
    ps_sum0 f1, f1, f0, f0
    blr
}

asm f32 PSVECMag(Vec* v)
{
    nofralloc
    lfs f4, vec_half(r0)
    psq_l f0, 0(r3), 0, 0
    ps_mul f0, f0, f0
    lfs f1, 8(r3)
    fsubs f2, f4, f4
    ps_madd f1, f1, f1, f0
    ps_sum0 f1, f1, f0, f0
    fcmpu cr0, f1, f2
    beq magret
    frsqrte f0, f1
    lfs f3, vec_three(r0)
    fmuls f2, f0, f0
    fmuls f0, f0, f4
    fnmsubs f2, f2, f1, f3
    fmuls f0, f2, f0
    fmuls f1, f1, f0
magret:
    blr
}

asm f32 PSVECDotProduct(Vec* a, Vec* b)
{
    nofralloc
    psq_l f2, 4(r3), 0, 0
    psq_l f3, 4(r4), 0, 0
    ps_mul f2, f2, f3
    psq_l f5, 0(r3), 0, 0
    psq_l f4, 0(r4), 0, 0
    ps_madd f3, f5, f4, f2
    ps_sum0 f1, f3, f2, f2
    blr
}

asm void PSVECCrossProduct(Vec* a, Vec* b, Vec* result)
{
    nofralloc
    psq_l f1, 0(r4), 0, 0
    lfs f2, 8(r3)
    psq_l f0, 0(r3), 0, 0
    ps_merge10 f6, f1, f1
    lfs f3, 8(r4)
    ps_mul f4, f1, f2
    ps_muls0 f7, f1, f0
    ps_msub f5, f0, f3, f4
    ps_msub f8, f0, f6, f7
    ps_merge11 f9, f5, f5
    ps_merge01 f10, f5, f8
    psq_st f9, 0(r5), 1, 0
    ps_neg f10, f10
    psq_st f10, 4(r5), 0, 0
    blr
}

#pragma peephole off
void PSVECReflect(Vec* src, Vec* normal, Vec* dst)
{
    Vec negSrc;
    Vec unitNormal;
    f32 dot;

    negSrc.x = -src->x;
    negSrc.y = -src->y;
    negSrc.z = -src->z;
    PSVECNormalize(&negSrc, &negSrc);

    PSVECNormalize(normal, &unitNormal);

    dot = PSVECDotProduct(&negSrc, &unitNormal);

    dst->x = 2.0f * unitNormal.x * dot - negSrc.x;
    dst->y = 2.0f * unitNormal.y * dot - negSrc.y;
    dst->z = 2.0f * unitNormal.z * dot - negSrc.z;

    PSVECNormalize(dst, dst);
}
#pragma peephole reset

asm f32 PSVECSquareDistance(Vec* a, Vec* b)
{
    nofralloc
    psq_l f0, 4(r3), 0, 0
    psq_l f1, 4(r4), 0, 0
    ps_sub f2, f0, f1
    psq_l f0, 0(r3), 0, 0
    psq_l f1, 0(r4), 0, 0
    ps_mul f2, f2, f2
    ps_sub f0, f0, f1
    ps_madd f1, f0, f0, f2
    ps_sum0 f1, f1, f2, f2
    blr
}

asm f32 PSVECDistance(Vec* a, Vec* b)
{
    nofralloc
    psq_l f0, 4(r3), 0, 0
    psq_l f1, 4(r4), 0, 0
    ps_sub f2, f0, f1
    psq_l f0, 0(r3), 0, 0
    psq_l f1, 0(r4), 0, 0
    ps_mul f2, f2, f2
    ps_sub f0, f0, f1
    lfs f3, vec_half(r0)
    ps_madd f1, f0, f0, f2
    fsubs f0, f3, f3
    ps_sum0 f1, f1, f2, f2
    fcmpu cr0, f0, f1
    beq distret
    lfs f4, vec_three(r0)
    frsqrte f0, f1
    fmuls f2, f0, f0
    fmuls f0, f0, f3
    fnmsubs f2, f2, f1, f4
    fmuls f0, f2, f0
    fmuls f1, f1, f0
distret:
    blr
}
