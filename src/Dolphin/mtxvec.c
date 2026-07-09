#include "dolphin/types.h"
#include "dolphin/mtx/mtxtypes.h"

asm void PSMTXMultVec(const Mtx m, const Vec* src, Vec* dst)
{
    nofralloc
    psq_l f0, 0(r4), 0, 0
    psq_l f2, 0(r3), 0, 0
    psq_l f1, 8(r4), 1, 0
    ps_mul f4, f2, f0
    psq_l f3, 8(r3), 0, 0
    ps_madd f5, f3, f1, f4
    psq_l f8, 0x10(r3), 0, 0
    ps_sum0 f6, f5, f6, f5
    psq_l f9, 0x18(r3), 0, 0
    ps_mul f10, f8, f0
    psq_st f6, 0(r5), 1, 0
    ps_madd f11, f9, f1, f10
    psq_l f2, 0x20(r3), 0, 0
    ps_sum0 f12, f11, f12, f11
    psq_l f3, 0x28(r3), 0, 0
    ps_mul f4, f2, f0
    psq_st f12, 4(r5), 1, 0
    ps_madd f5, f3, f1, f4
    ps_sum0 f6, f5, f6, f5
    psq_st f6, 8(r5), 1, 0
    blr
}

/* PSMTXMultVecSR */
asm void fn_803D1E40(const Mtx m, const Vec* src, Vec* dst)
{
    nofralloc
    psq_l f0, 0(r3), 0, 0
    psq_l f6, 0(r4), 0, 0
    psq_l f2, 0x10(r3), 0, 0
    ps_mul f8, f0, f6
    psq_l f4, 0x20(r3), 0, 0
    ps_mul f10, f2, f6
    psq_l f7, 8(r4), 1, 0
    ps_mul f12, f4, f6
    psq_l f3, 0x18(r3), 0, 0
    ps_sum0 f8, f8, f8, f8
    psq_l f5, 0x28(r3), 0, 0
    ps_sum0 f10, f10, f10, f10
    psq_l f1, 8(r3), 0, 0
    ps_sum0 f12, f12, f12, f12
    ps_madd f9, f1, f7, f8
    psq_st f9, 0(r5), 1, 0
    ps_madd f11, f3, f7, f10
    psq_st f11, 4(r5), 1, 0
    ps_madd f13, f5, f7, f12
    psq_st f13, 8(r5), 1, 0
    blr
}
