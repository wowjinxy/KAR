#include "dolphin/types.h"
#include "dolphin/mtx/mtxtypes.h"

extern f32 fn_803BD518(f32 x);

extern const f32 lbl_805E58D0; // 1.0F
extern const f32 lbl_805E58D4; // 2.0F
extern const f32 lbl_805E58D8; // 0.0F
extern const f32 lbl_805E58DC; // -1.0F
extern const f32 lbl_805E58E0; // 0.5F
extern const f32 lbl_805E58E4; // (PI / 180)

void C_MTXFrustum(Mtx44 m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f)
{
    f32 tmp;

    tmp = lbl_805E58D0 / (r - l);
    m[0][0] = tmp * (lbl_805E58D4 * n);
    m[0][1] = lbl_805E58D8;
    m[0][2] = (r + l) * tmp;
    m[0][3] = lbl_805E58D8;

    tmp = lbl_805E58D0 / (t - b);
    m[1][0] = lbl_805E58D8;
    m[1][1] = tmp * (lbl_805E58D4 * n);
    m[1][2] = (t + b) * tmp;
    m[1][3] = lbl_805E58D8;

    m[2][0] = lbl_805E58D8;
    m[2][1] = lbl_805E58D8;
    tmp = lbl_805E58D0 / (f - n);
    m[2][2] = -(n)*tmp;
    m[2][3] = -(f * n) * tmp;

    m[3][0] = lbl_805E58D8;
    m[3][1] = lbl_805E58D8;
    m[3][2] = lbl_805E58DC;
    m[3][3] = lbl_805E58D8;
}

void C_MTXPerspective(Mtx44 m, f32 fovY, f32 aspect, f32 n, f32 f)
{
    f32 angle;
    f32 cot;
    f32 tmp;

    angle = lbl_805E58E0 * fovY;
    angle = lbl_805E58E4 * angle;

    cot = lbl_805E58D0 / fn_803BD518(angle);

    m[0][0] = cot / aspect;
    m[0][1] = lbl_805E58D8;
    m[0][2] = lbl_805E58D8;
    m[0][3] = lbl_805E58D8;

    m[1][0] = lbl_805E58D8;
    m[1][1] = cot;
    m[1][2] = lbl_805E58D8;
    m[1][3] = lbl_805E58D8;

    m[2][0] = lbl_805E58D8;
    m[2][1] = lbl_805E58D8;
    tmp = lbl_805E58D0 / (f - n);
    m[2][2] = -(n)*tmp;
    m[2][3] = -(f * n) * tmp;

    m[3][0] = lbl_805E58D8;
    m[3][1] = lbl_805E58D8;
    m[3][2] = lbl_805E58DC;
    m[3][3] = lbl_805E58D8;
}

void C_MTXOrtho(Mtx44 m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f)
{
    f32 tmp;

    tmp = lbl_805E58D0 / (r - l);
    m[0][0] = lbl_805E58D4 * tmp;
    m[0][1] = lbl_805E58D8;
    m[0][2] = lbl_805E58D8;
    m[0][3] = -(r + l) * tmp;

    tmp = lbl_805E58D0 / (t - b);
    m[1][0] = lbl_805E58D8;
    m[1][1] = lbl_805E58D4 * tmp;
    m[1][2] = lbl_805E58D8;
    m[1][3] = -(t + b) * tmp;

    m[2][0] = lbl_805E58D8;
    m[2][1] = lbl_805E58D8;
    tmp = lbl_805E58D0 / (f - n);
    m[2][2] = lbl_805E58DC * tmp;
    m[2][3] = -(f)*tmp;

    m[3][0] = lbl_805E58D8;
    m[3][1] = lbl_805E58D8;
    m[3][2] = lbl_805E58D8;
    m[3][3] = lbl_805E58D0;
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
