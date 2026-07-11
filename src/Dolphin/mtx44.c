#include "dolphin/types.h"
#include "dolphin/mtx/mtx.h"

extern const f32 mtx44_one;
extern const f32 mtx44_two;
extern const f32 mtx44_zero;
extern const f32 mtx44_neg_one;
extern const f32 mtx44_half;
extern const f32 mtx44_deg_to_rad;

void C_MTXFrustum(Mtx44 m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f)
{
    f32 tmp;

    tmp = mtx44_one / (r - l);
    m[0][0] = tmp * (mtx44_two * n);
    m[0][1] = mtx44_zero;
    m[0][2] = (r + l) * tmp;
    m[0][3] = mtx44_zero;

    tmp = mtx44_one / (t - b);
    m[1][0] = mtx44_zero;
    m[1][1] = tmp * (mtx44_two * n);
    m[1][2] = (t + b) * tmp;
    m[1][3] = mtx44_zero;

    m[2][0] = mtx44_zero;
    m[2][1] = mtx44_zero;
    tmp = mtx44_one / (f - n);
    m[2][2] = -(n)*tmp;
    m[2][3] = -(f * n) * tmp;

    m[3][0] = mtx44_zero;
    m[3][1] = mtx44_zero;
    m[3][2] = mtx44_neg_one;
    m[3][3] = mtx44_zero;
}

void C_MTXPerspective(Mtx44 m, f32 fovY, f32 aspect, f32 n, f32 f)
{
    f32 angle;
    f32 cot;
    f32 tmp;

    angle = mtx44_half * fovY;
    angle = mtx44_deg_to_rad * angle;

    cot = mtx44_one / mtx_tanf(angle);

    m[0][0] = cot / aspect;
    m[0][1] = mtx44_zero;
    m[0][2] = mtx44_zero;
    m[0][3] = mtx44_zero;

    m[1][0] = mtx44_zero;
    m[1][1] = cot;
    m[1][2] = mtx44_zero;
    m[1][3] = mtx44_zero;

    m[2][0] = mtx44_zero;
    m[2][1] = mtx44_zero;
    tmp = mtx44_one / (f - n);
    m[2][2] = -(n)*tmp;
    m[2][3] = -(f * n) * tmp;

    m[3][0] = mtx44_zero;
    m[3][1] = mtx44_zero;
    m[3][2] = mtx44_neg_one;
    m[3][3] = mtx44_zero;
}

void C_MTXOrtho(Mtx44 m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f)
{
    f32 tmp;

    tmp = mtx44_one / (r - l);
    m[0][0] = mtx44_two * tmp;
    m[0][1] = mtx44_zero;
    m[0][2] = mtx44_zero;
    m[0][3] = -(r + l) * tmp;

    tmp = mtx44_one / (t - b);
    m[1][0] = mtx44_zero;
    m[1][1] = mtx44_two * tmp;
    m[1][2] = mtx44_zero;
    m[1][3] = -(t + b) * tmp;

    m[2][0] = mtx44_zero;
    m[2][1] = mtx44_zero;
    tmp = mtx44_one / (f - n);
    m[2][2] = mtx44_neg_one * tmp;
    m[2][3] = -(f)*tmp;

    m[3][0] = mtx44_zero;
    m[3][1] = mtx44_zero;
    m[3][2] = mtx44_zero;
    m[3][3] = mtx44_one;
}

const f32 mtx44_one = 1.0F;
const f32 mtx44_two = 2.0F;
const f32 mtx44_zero = 0.0F;
const f32 mtx44_neg_one = -1.0F;
const f32 mtx44_half = 0.5F;
const f32 mtx44_deg_to_rad = 0.017453292F;

asm void PSVECAdd(Vec* a, Vec* b, Vec* c)
{
    nofralloc
    psq_l f2, 0(r3), 0, 0
    psq_l f4, 0(r4), 0, 0
    ps_add f6, f2, f4
    psq_st f6, 0(r5), 0, 0
    psq_l f3, 8(r3), 1, 0
    psq_l f5, 8(r4), 1, 0
    ps_add f7, f3, f5
    psq_st f7, 8(r5), 1, 0
    blr
}
