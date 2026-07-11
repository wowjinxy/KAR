#include "dolphin/types.h"
#include "dolphin/mtx/mtx.h"

void C_MTXFrustum(Mtx44 m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f)
{
    f32 tmp;

    tmp = 1.0F / (r - l);
    m[0][0] = tmp * (2.0F * n);
    m[0][1] = 0.0F;
    m[0][2] = (r + l) * tmp;
    m[0][3] = 0.0F;

    tmp = 1.0F / (t - b);
    m[1][0] = 0.0F;
    m[1][1] = tmp * (2.0F * n);
    m[1][2] = (t + b) * tmp;
    m[1][3] = 0.0F;

    m[2][0] = 0.0F;
    m[2][1] = 0.0F;
    tmp = 1.0F / (f - n);
    m[2][2] = -(n)*tmp;
    m[2][3] = -(f * n) * tmp;

    m[3][0] = 0.0F;
    m[3][1] = 0.0F;
    m[3][2] = -1.0F;
    m[3][3] = 0.0F;
}

void C_MTXPerspective(Mtx44 m, f32 fovY, f32 aspect, f32 n, f32 f)
{
    f32 angle;
    f32 cot;
    f32 tmp;

    angle = 0.5F * fovY;
    angle = 0.017453292F * angle;

    cot = 1.0F / mtx_tanf(angle);

    m[0][0] = cot / aspect;
    m[0][1] = 0.0F;
    m[0][2] = 0.0F;
    m[0][3] = 0.0F;

    m[1][0] = 0.0F;
    m[1][1] = cot;
    m[1][2] = 0.0F;
    m[1][3] = 0.0F;

    m[2][0] = 0.0F;
    m[2][1] = 0.0F;
    tmp = 1.0F / (f - n);
    m[2][2] = -(n)*tmp;
    m[2][3] = -(f * n) * tmp;

    m[3][0] = 0.0F;
    m[3][1] = 0.0F;
    m[3][2] = -1.0F;
    m[3][3] = 0.0F;
}

void C_MTXOrtho(Mtx44 m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f)
{
    f32 tmp;

    tmp = 1.0F / (r - l);
    m[0][0] = 2.0F * tmp;
    m[0][1] = 0.0F;
    m[0][2] = 0.0F;
    m[0][3] = -(r + l) * tmp;

    tmp = 1.0F / (t - b);
    m[1][0] = 0.0F;
    m[1][1] = 2.0F * tmp;
    m[1][2] = 0.0F;
    m[1][3] = -(t + b) * tmp;

    m[2][0] = 0.0F;
    m[2][1] = 0.0F;
    tmp = 1.0F / (f - n);
    m[2][2] = -1.0F * tmp;
    m[2][3] = -(f)*tmp;

    m[3][0] = 0.0F;
    m[3][1] = 0.0F;
    m[3][2] = 0.0F;
    m[3][3] = 1.0F;
}

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
