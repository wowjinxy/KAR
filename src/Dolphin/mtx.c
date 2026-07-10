#include "dolphin/types.h"
#include "dolphin/mtx/mtxtypes.h"

extern const f32 lbl_805E58B0; // 1.0F
extern const f32 lbl_805E58B4; // 0.0F
extern const f32 lbl_805E58B8; // 0.5F
extern const f32 lbl_805E58BC; // 3.0F
extern const f32 lbl_805E58C0; // 2.0F
extern const f32 lbl_805E58C4; // -1.0F
extern const f32 lbl_805E58C8; // (PI / 180)
extern const f32 lbl_805DC960; // {0.0F, 1.0F}

extern f32 fn_803BD518(f32 x);
extern f32 fn_803BD53C(f32 x);
extern f32 fn_803BD560(f32 x);

asm void kar_fl_indirectload__803d13fc(Mtx m)
{
    nofralloc
    lfs f0, lbl_805E58B4(r0)
    lfs f1, lbl_805E58B0(r0)
    psq_st f0, 0x8(r3), 0, 0
    ps_merge01 f2, f0, f1
    psq_st f0, 0x18(r3), 0, 0
    ps_merge10 f1, f1, f0
    psq_st f0, 0x20(r3), 0, 0
    psq_st f2, 0x10(r3), 0, 0
    psq_st f1, 0x0(r3), 0, 0
    psq_st f1, 0x28(r3), 0, 0
    blr
}

asm void PSMTXCopy(Mtx src, Mtx dst)
{
    nofralloc
    psq_l f0, 0x0(r3), 0, 0
    psq_st f0, 0x0(r4), 0, 0
    psq_l f1, 0x8(r3), 0, 0
    psq_st f1, 0x8(r4), 0, 0
    psq_l f2, 0x10(r3), 0, 0
    psq_st f2, 0x10(r4), 0, 0
    psq_l f3, 0x18(r3), 0, 0
    psq_st f3, 0x18(r4), 0, 0
    psq_l f4, 0x20(r3), 0, 0
    psq_st f4, 0x20(r4), 0, 0
    psq_l f5, 0x28(r3), 0, 0
    psq_st f5, 0x28(r4), 0, 0
    blr
}

asm void PSMTXConcat(Mtx a, Mtx b, Mtx ab)
{
    nofralloc
    stwu r1, -0x40(r1)
    psq_l f0, 0x0(r3), 0, 0
    stfd f14, 0x8(r1)
    psq_l f6, 0x0(r4), 0, 0
    lis r6, lbl_805DC960@ha
    psq_l f7, 0x8(r4), 0, 0
    stfd f15, 0x10(r1)
    addi r6, r6, lbl_805DC960@l
    stfd f31, 0x28(r1)
    psq_l f8, 0x10(r4), 0, 0
    ps_muls0 f12, f6, f0
    psq_l f2, 0x10(r3), 0, 0
    ps_muls0 f13, f7, f0
    psq_l f31, 0x0(r6), 0, 0
    ps_muls0 f14, f6, f2
    psq_l f9, 0x18(r4), 0, 0
    ps_muls0 f15, f7, f2
    psq_l f1, 0x8(r3), 0, 0
    ps_madds1 f12, f8, f0, f12
    psq_l f3, 0x18(r3), 0, 0
    ps_madds1 f14, f8, f2, f14
    psq_l f10, 0x20(r4), 0, 0
    ps_madds1 f13, f9, f0, f13
    psq_l f11, 0x28(r4), 0, 0
    ps_madds1 f15, f9, f2, f15
    psq_l f4, 0x20(r3), 0, 0
    psq_l f5, 0x28(r3), 0, 0
    ps_madds0 f12, f10, f1, f12
    ps_madds0 f13, f11, f1, f13
    ps_madds0 f14, f10, f3, f14
    ps_madds0 f15, f11, f3, f15
    psq_st f12, 0x0(r5), 0, 0
    ps_muls0 f2, f6, f4
    ps_madds1 f13, f31, f1, f13
    ps_muls0 f0, f7, f4
    psq_st f14, 0x10(r5), 0, 0
    ps_madds1 f15, f31, f3, f15
    psq_st f13, 0x8(r5), 0, 0
    ps_madds1 f2, f8, f4, f2
    ps_madds1 f0, f9, f4, f0
    ps_madds0 f2, f10, f5, f2
    lfd f14, 0x8(r1)
    psq_st f15, 0x18(r5), 0, 0
    ps_madds0 f0, f11, f5, f0
    psq_st f2, 0x20(r5), 0, 0
    ps_madds1 f0, f31, f5, f0
    lfd f15, 0x10(r1)
    psq_st f0, 0x28(r5), 0, 0
    lfd f31, 0x28(r1)
    addi r1, r1, 0x40
    blr
}

/* PSMTXTranspose */
asm void fn_803D1528(Mtx src, Mtx xPose)
{
    nofralloc
    lfs f0, lbl_805E58B4(r0)
    psq_l f1, 0x0(r3), 0, 0
    stfs f0, 0x2c(r4)
    psq_l f2, 0x10(r3), 0, 0
    ps_merge00 f4, f1, f2
    psq_l f3, 0x8(r3), 1, 0
    ps_merge11 f5, f1, f2
    psq_l f2, 0x18(r3), 1, 0
    psq_st f4, 0x0(r4), 0, 0
    psq_l f1, 0x20(r3), 0, 0
    ps_merge00 f2, f3, f2
    psq_st f5, 0x10(r4), 0, 0
    ps_merge00 f4, f1, f0
    psq_st f2, 0x20(r4), 0, 0
    ps_merge10 f5, f1, f0
    psq_st f4, 0x8(r4), 0, 0
    lfs f3, 0x28(r3)
    psq_st f5, 0x18(r4), 0, 0
    stfs f3, 0x28(r4)
    blr
}

/* PSMTXInverse */
asm BOOL fn_803D1578(Mtx src, Mtx inv)
{
    nofralloc
    psq_l f0, 0x0(r3), 1, 0
    psq_l f1, 0x4(r3), 0, 0
    psq_l f2, 0x10(r3), 1, 0
    ps_merge10 f6, f1, f0
    psq_l f3, 0x14(r3), 0, 0
    psq_l f4, 0x20(r3), 1, 0
    ps_merge10 f7, f3, f2
    psq_l f5, 0x24(r3), 0, 0
    ps_mul f11, f3, f6
    ps_mul f13, f5, f7
    ps_merge10 f8, f5, f4
    ps_msub f11, f1, f7, f11
    ps_mul f12, f1, f8
    ps_msub f13, f3, f8, f13
    ps_mul f10, f3, f4
    ps_msub f12, f5, f6, f12
    ps_mul f9, f0, f5
    ps_mul f8, f1, f2
    ps_sub f6, f6, f6
    ps_msub f10, f2, f5, f10
    ps_mul f7, f0, f13
    ps_msub f9, f1, f4, f9
    ps_madd f7, f2, f12, f7
    ps_msub f8, f0, f3, f8
    ps_madd f7, f4, f11, f7
    ps_cmpo0 cr0, f7, f6
    bne inv_nonzero
    li r3, 0x0
    blr
inv_nonzero:
    fres f0, f7
    ps_add f6, f0, f0
    ps_mul f5, f0, f0
    ps_nmsub f0, f7, f5, f6
    lfs f1, 0xc(r3)
    ps_muls0 f13, f13, f0
    lfs f2, 0x1c(r3)
    ps_muls0 f12, f12, f0
    lfs f3, 0x2c(r3)
    ps_muls0 f11, f11, f0
    ps_merge00 f5, f13, f12
    ps_muls0 f10, f10, f0
    ps_merge11 f4, f13, f12
    ps_muls0 f9, f9, f0
    psq_st f5, 0x0(r4), 0, 0
    ps_mul f6, f13, f1
    psq_st f4, 0x10(r4), 0, 0
    ps_muls0 f8, f8, f0
    ps_madd f6, f12, f2, f6
    psq_st f10, 0x20(r4), 1, 0
    ps_nmadd f6, f11, f3, f6
    psq_st f9, 0x24(r4), 1, 0
    ps_mul f7, f10, f1
    ps_merge00 f5, f11, f6
    psq_st f8, 0x28(r4), 1, 0
    ps_merge11 f4, f11, f6
    psq_st f5, 0x8(r4), 0, 0
    ps_madd f7, f9, f2, f7
    psq_st f4, 0x18(r4), 0, 0
    ps_nmadd f7, f8, f3, f7
    li r3, 0x1
    psq_st f7, 0x2c(r4), 1, 0
    blr
}

/* PSMTXInvXpose */
asm BOOL kar_grcoll__803d1670(Mtx src, Mtx invX)
{
    nofralloc
    psq_l f0, 0x0(r3), 1, 0
    psq_l f1, 0x4(r3), 0, 0
    psq_l f2, 0x10(r3), 1, 0
    ps_merge10 f6, f1, f0
    psq_l f3, 0x14(r3), 0, 0
    psq_l f4, 0x20(r3), 1, 0
    ps_merge10 f7, f3, f2
    psq_l f5, 0x24(r3), 0, 0
    ps_mul f11, f3, f6
    ps_merge10 f8, f5, f4
    ps_mul f13, f5, f7
    ps_msub f11, f1, f7, f11
    ps_mul f12, f1, f8
    ps_msub f13, f3, f8, f13
    ps_msub f12, f5, f6, f12
    ps_mul f10, f3, f4
    ps_mul f9, f0, f5
    ps_mul f8, f1, f2
    ps_msub f10, f2, f5, f10
    ps_msub f9, f1, f4, f9
    ps_msub f8, f0, f3, f8
    ps_mul f7, f0, f13
    ps_sub f1, f1, f1
    ps_madd f7, f2, f12, f7
    ps_madd f7, f4, f11, f7
    ps_cmpo0 cr0, f7, f1
    bne invx_nonzero
    li r3, 0x0
    blr
invx_nonzero:
    fres f0, f7
    psq_st f1, 0xc(r4), 1, 0
    ps_add f6, f0, f0
    ps_mul f5, f0, f0
    psq_st f1, 0x1c(r4), 1, 0
    ps_nmsub f0, f7, f5, f6
    psq_st f1, 0x2c(r4), 1, 0
    ps_muls0 f13, f13, f0
    ps_muls0 f12, f12, f0
    ps_muls0 f11, f11, f0
    psq_st f13, 0x0(r4), 0, 0
    psq_st f12, 0x10(r4), 0, 0
    ps_muls0 f10, f10, f0
    ps_muls0 f9, f9, f0
    psq_st f11, 0x20(r4), 0, 0
    psq_st f10, 0x8(r4), 1, 0
    ps_muls0 f8, f8, f0
    li r3, 0x1
    psq_st f9, 0x18(r4), 1, 0
    psq_st f8, 0x28(r4), 1, 0
    blr
}

extern void kar_grcoll__near_803d17a8(Mtx m, char axis, f32 sinA, f32 cosA);

/* PSMTXRotRad */
void kar_grcoll__near_803d1738(Mtx m, char axis, f32 rad)
{
    f32 sinA = fn_803BD53C(rad);
    f32 cosA = fn_803BD560(rad);
    kar_grcoll__near_803d17a8(m, axis, sinA, cosA);
}

/* PSMTXRotTrig */
asm void kar_grcoll__near_803d17a8(Mtx m, char axis, f32 sinA, f32 cosA)
{
    nofralloc
    frsp f5, f1
    frsp f4, f2
    lfs f0, lbl_805E58B4(r0)
    lfs f1, lbl_805E58B0(r0)
    ori r0, r4, 0x20
    ps_neg f2, f5
    cmplwi r0, 0x78
    beq rot_x
    cmplwi r0, 0x79
    beq rot_y
    cmplwi r0, 0x7a
    beq rot_z
    b rot_done
rot_x:
    psq_st f1, 0x0(r3), 1, 0
    psq_st f0, 0x4(r3), 0, 0
    ps_merge00 f3, f5, f4
    psq_st f0, 0xc(r3), 0, 0
    ps_merge00 f1, f4, f2
    psq_st f0, 0x1c(r3), 0, 0
    psq_st f0, 0x2c(r3), 1, 0
    psq_st f3, 0x24(r3), 0, 0
    psq_st f1, 0x14(r3), 0, 0
    b rot_done
rot_y:
    ps_merge00 f3, f4, f0
    ps_merge00 f1, f0, f1
    psq_st f0, 0x18(r3), 0, 0
    psq_st f3, 0x0(r3), 0, 0
    ps_merge00 f2, f2, f0
    ps_merge00 f0, f5, f0
    psq_st f3, 0x28(r3), 0, 0
    psq_st f1, 0x10(r3), 0, 0
    psq_st f0, 0x8(r3), 0, 0
    psq_st f2, 0x20(r3), 0, 0
    b rot_done
rot_z:
    psq_st f0, 0x8(r3), 0, 0
    ps_merge00 f3, f5, f4
    ps_merge00 f2, f4, f2
    psq_st f0, 0x18(r3), 0, 0
    psq_st f0, 0x20(r3), 0, 0
    ps_merge00 f1, f1, f0
    psq_st f3, 0x10(r3), 0, 0
    psq_st f2, 0x0(r3), 0, 0
    psq_st f1, 0x28(r3), 0, 0
rot_done:
    blr
}

/* PSMTXRotAxisRadInternal */
asm void kar_grcoll__near_803d1858(Mtx m, Vec* axis, f32 sinA, f32 cosA)
{
    nofralloc
    lfs f10, lbl_805E58B8(r0)
    lfs f9, lbl_805E58BC(r0)
    frsp f11, f2
    psq_l f2, 0x0(r4), 0, 0
    frsp f12, f1
    lfs f3, 0x8(r4)
    ps_mul f4, f2, f2
    fadds f8, f10, f10
    ps_madd f5, f3, f3, f4
    fsubs f1, f10, f10
    ps_sum0 f6, f5, f3, f4
    fsubs f0, f8, f11
    frsqrte f7, f6
    fmuls f4, f7, f7
    fmuls f5, f7, f10
    fnmsubs f4, f4, f6, f9
    fmuls f7, f4, f5
    ps_merge00 f11, f11, f11
    ps_muls0 f2, f2, f7
    ps_muls0 f3, f3, f7
    ps_muls0 f6, f2, f0
    ps_muls0 f10, f2, f12
    ps_muls0 f7, f3, f0
    ps_muls1 f5, f6, f2
    ps_muls0 f4, f6, f2
    ps_muls0 f6, f6, f3
    fnmsubs f0, f3, f12, f5
    fmadds f8, f3, f12, f5
    ps_neg f2, f10
    ps_sum0 f9, f6, f1, f10
    ps_sum0 f4, f4, f0, f11
    ps_sum1 f5, f11, f8, f5
    ps_sum0 f0, f2, f1, f6
    psq_st f9, 0x8(r3), 0, 0
    ps_sum0 f2, f6, f6, f2
    psq_st f4, 0x0(r3), 0, 0
    ps_muls0 f7, f7, f3
    psq_st f5, 0x10(r3), 0, 0
    ps_sum1 f6, f10, f2, f6
    psq_st f0, 0x18(r3), 0, 0
    ps_sum0 f7, f7, f1, f11
    psq_st f6, 0x20(r3), 0, 0
    psq_st f7, 0x28(r3), 0, 0
    blr
}

/* PSMTXRotAxisRad */
void kar_grcoll__near_803d1908(Mtx m, Vec* axis, f32 rad)
{
    f32 sinA = fn_803BD53C(rad);
    f32 cosA = fn_803BD560(rad);
    kar_grcoll__near_803d1858(m, axis, sinA, cosA);
}

/* PSMTXTrans */
asm void kar_grcoll__803d1978(Mtx m, f32 xT, f32 yT, f32 zT)
{
    nofralloc
    lfs f0, lbl_805E58B4(r0)
    lfs f4, lbl_805E58B0(r0)
    stfs f1, 0xc(r3)
    stfs f2, 0x1c(r3)
    psq_st f0, 0x4(r3), 0, 0
    psq_st f0, 0x20(r3), 0, 0
    stfs f0, 0x10(r3)
    stfs f4, 0x14(r3)
    stfs f0, 0x18(r3)
    stfs f4, 0x28(r3)
    stfs f3, 0x2c(r3)
    stfs f4, 0x0(r3)
    blr
}

/* PSMTXScale */
asm void fn_803D19AC(Mtx m, f32 xS, f32 yS, f32 zS)
{
    nofralloc
    lfs f0, lbl_805E58B4(r0)
    stfs f1, 0x0(r3)
    psq_st f0, 0x4(r3), 0, 0
    psq_st f0, 0xc(r3), 0, 0
    stfs f2, 0x14(r3)
    psq_st f0, 0x18(r3), 0, 0
    psq_st f0, 0x20(r3), 0, 0
    stfs f3, 0x28(r3)
    stfs f0, 0x2c(r3)
    blr
}

/* PSMTXQuat */
asm void fn_803D19D4(Mtx m, Quaternion* q)
{
    nofralloc
    lfs f1, lbl_805E58B0(r0)
    psq_l f4, 0x0(r4), 0, 0
    psq_l f5, 0x8(r4), 0, 0
    fsubs f0, f1, f1
    fadds f2, f1, f1
    ps_mul f6, f4, f4
    ps_merge10 f9, f4, f4
    ps_madd f8, f5, f5, f6
    ps_mul f7, f5, f5
    ps_sum0 f3, f8, f8, f8
    ps_muls1 f10, f9, f5
    fres f11, f3
    ps_sum1 f8, f7, f8, f6
    ps_nmsub f3, f3, f11, f2
    ps_muls1 f7, f5, f5
    ps_mul f3, f11, f3
    ps_sum0 f6, f6, f6, f6
    fmuls f3, f3, f2
    ps_madd f11, f4, f9, f7
    ps_msub f7, f4, f9, f7
    psq_st f0, 0xc(r3), 1, 0
    ps_nmsub f6, f6, f3, f1
    ps_nmsub f8, f8, f3, f1
    psq_st f0, 0x2c(r3), 1, 0
    ps_mul f11, f11, f3
    ps_mul f7, f7, f3
    psq_st f6, 0x28(r3), 1, 0
    ps_madds0 f9, f4, f5, f10
    ps_merge00 f5, f11, f8
    ps_nmsub f10, f10, f2, f9
    ps_merge10 f4, f8, f7
    psq_st f5, 0x10(r3), 0, 0
    ps_mul f9, f9, f3
    ps_mul f10, f10, f3
    psq_st f4, 0x0(r3), 0, 0
    psq_st f9, 0x8(r3), 1, 0
    ps_merge10 f7, f10, f0
    ps_merge01 f11, f10, f9
    psq_st f7, 0x18(r3), 0, 0
    psq_st f11, 0x20(r3), 0, 0
    blr
}

extern void PSVECNormalize(Vec* src, Vec* unit);
extern void PSVECCrossProduct(Vec* a, Vec* b, Vec* result);

#pragma fp_contract off
void C_MTXLookAt(Mtx m, Vec* camPos, Vec* camUp, Vec* target)
{
    Vec vLook;
    Vec vRight;
    Vec vUp;

    vLook.x = camPos->x - target->x;
    vLook.y = camPos->y - target->y;
    vLook.z = camPos->z - target->z;
    PSVECNormalize(&vLook, &vLook);

    PSVECCrossProduct(camUp, &vLook, &vRight);
    PSVECNormalize(&vRight, &vRight);

    PSVECCrossProduct(&vLook, &vRight, &vUp);

    m[0][0] = vRight.x;
    m[0][1] = vRight.y;
    m[0][2] = vRight.z;
    m[0][3] = -((camPos->z * vRight.z) + ((camPos->x * vRight.x) + (camPos->y * vRight.y)));

    m[1][0] = vUp.x;
    m[1][1] = vUp.y;
    m[1][2] = vUp.z;
    m[1][3] = -((camPos->z * vUp.z) + ((camPos->x * vUp.x) + (camPos->y * vUp.y)));

    m[2][0] = vLook.x;
    m[2][1] = vLook.y;
    m[2][2] = vLook.z;
    m[2][3] = -((camPos->z * vLook.z) + ((camPos->x * vLook.x) + (camPos->y * vLook.y)));
}
#pragma fp_contract reset

#pragma fp_contract off
void C_MTXLightFrustum(Mtx m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 scaleS,
                        f32 scaleT, f32 transS, f32 transT)
{
    f32 tmp;

    tmp = lbl_805E58B0 / (r - l);
    m[0][0] = scaleS * (lbl_805E58C0 * n * tmp);
    m[0][1] = lbl_805E58B4;
    m[0][2] = scaleS * ((r + l) * tmp) - transS;
    m[0][3] = lbl_805E58B4;

    tmp = lbl_805E58B0 / (t - b);
    m[1][0] = lbl_805E58B4;
    m[1][1] = scaleT * (lbl_805E58C0 * n * tmp);
    m[1][2] = scaleT * ((t + b) * tmp) - transT;
    m[1][3] = lbl_805E58B4;

    m[2][0] = lbl_805E58B4;
    m[2][1] = lbl_805E58B4;
    m[2][2] = lbl_805E58C4;
    m[2][3] = lbl_805E58B4;
}
#pragma fp_contract reset

#pragma fp_contract off
void C_MTXLightPerspective(Mtx m, f32 fovY, f32 aspect, f32 scaleS, f32 scaleT,
                            f32 transS, f32 transT)
{
    f32 angle;
    f32 cot;

    angle = lbl_805E58B8 * fovY;
    angle = lbl_805E58C8 * angle;

    cot = lbl_805E58B0 / fn_803BD518(angle);

    m[0][0] = scaleS * (cot / aspect);
    m[0][1] = lbl_805E58B4;
    m[0][2] = -transS;
    m[0][3] = lbl_805E58B4;

    m[1][0] = lbl_805E58B4;
    m[1][1] = cot * scaleT;
    m[1][2] = -transT;
    m[1][3] = lbl_805E58B4;

    m[2][0] = lbl_805E58B4;
    m[2][1] = lbl_805E58B4;
    m[2][2] = lbl_805E58C4;
    m[2][3] = lbl_805E58B4;
}
#pragma fp_contract reset

#pragma fp_contract off
void C_MTXLightOrtho(Mtx m, f32 t, f32 b, f32 l, f32 r, f32 scaleS, f32 scaleT,
                      f32 transS, f32 transT)
{
    f32 tmp;

    tmp = lbl_805E58B0 / (r - l);
    m[0][0] = (lbl_805E58C0 * tmp) * scaleS;
    m[0][1] = lbl_805E58B4;
    m[0][2] = lbl_805E58B4;
    m[0][3] = transS + scaleS * (tmp * -(r + l));

    tmp = lbl_805E58B0 / (t - b);
    m[1][0] = lbl_805E58B4;
    m[1][1] = (lbl_805E58C0 * tmp) * scaleT;
    m[1][2] = lbl_805E58B4;
    m[1][3] = transT + scaleT * (tmp * -(t + b));

    m[2][0] = lbl_805E58B4;
    m[2][1] = lbl_805E58B4;
    m[2][2] = lbl_805E58B4;
    m[2][3] = lbl_805E58B0;
}
#pragma fp_contract reset
