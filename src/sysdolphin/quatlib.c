#include <global.h>
#include <sysdolphin/mtx.h>

extern f32 lbl_805E5D40; /* 0.0F */
extern f64 lbl_805E5D48; /* 0.5 */
extern f64 lbl_805E5D50; /* 3.0 */
extern f32 lbl_805E5D58; /* 1.0F */
extern f32 lbl_805E5D5C; /* 0.5F */
extern f64 lbl_805E5D60; /* 2*PI */
extern f64 lbl_805E5D68; /* PI */
extern f64 lbl_805E5D70; /* PI/2 */
extern f32 lbl_805E5D78;
extern f32 lbl_805E5D7C;
extern f32 lbl_805E5D80;
extern f32 lbl_805E5D84;
extern f32 lbl_805E5D88;
extern f32 lbl_805E5D8C;
extern f32 lbl_805E5D90;
extern f64 lbl_805E5D98; /* PI/4 */
extern f32 lbl_805E5DA0; /* 1e-10F */
extern f64 lbl_805E5DA8; /* 1.0 */
extern f32 lbl_805E5DB0; /* 2.0F */
extern f32 lbl_805DC8B8[]; /* FLT_MIN */

extern f64 __frsqrte(f64 x);
extern f64 __fnmsub(f64 a, f64 c, f64 b);
extern f32 __fnmsubs(f32 a, f32 c, f32 b);
extern f32 __fmadds(f32 a, f32 c, f32 b); /* = a*c+b */
extern f32 __fmsubs(f32 a, f32 c, f32 b); /* = a*c-b */
extern f64 fn_803BD388(f64 x); /* acos */

f32 kar_math_quat_sinf_approx(f32 x);
f32 kar_math_quat_cosf_approx(f32 x);

s32 QuatMul(Quaternion* p, Quaternion* q, Quaternion* out)
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;

    y = __fmadds(q->w, p->y, p->w * q->y) + __fmsubs(q->x, p->z, p->x * q->z);
    x = __fmadds(q->w, p->x, p->w * q->x) + __fmsubs(p->y, q->z, q->y * p->z);
    z = __fmadds(q->w, p->z, p->w * q->z) + __fmsubs(p->x, q->y, q->x * p->y);
    w = __fmsubs(p->w, q->w,
                 __fmadds(p->z, q->z, __fmadds(p->x, q->x, p->y * q->y)));

    out->x = x;
    out->y = y;
    out->z = z;
    out->w = w;

    return 1;
}

s32 QuatSetUp(Vec* axis, Quaternion* q, f32 angle)
{
    f32 lensq;
    f32 inv_len;
    f32 half_angle;
    f32 s;

    lensq = axis->x * axis->x + axis->y * axis->y + axis->z * axis->z;
    if (lensq > lbl_805E5D40) {
        volatile f32 y;
        f64 guess = __frsqrte((f64) lensq);
        guess = lbl_805E5D48 * guess *
                __fnmsub(lensq, guess * guess, lbl_805E5D50);
        guess = lbl_805E5D48 * guess *
                __fnmsub(lensq, guess * guess, lbl_805E5D50);
        guess = lbl_805E5D48 * guess *
                __fnmsub(lensq, guess * guess, lbl_805E5D50);
        y = (f32) (lensq * guess);
        lensq = y;
    }
    if (__fabsf(lensq) < lbl_805DC8B8[0]) {
        return 0;
    }
    inv_len = lbl_805E5D58 / lensq;
    half_angle = lbl_805E5D5C * angle;
    q->w = kar_math_quat_cosf_approx(half_angle);
    s = kar_math_quat_sinf_approx(half_angle);
    q->x = s * (inv_len * axis->x);
    q->y = s * (inv_len * axis->y);
    q->z = s * (inv_len * axis->z);

    return 1;
}

static inline f32 kar_quat_poly(f32 y)
{
    f32 z;

    if (y <= lbl_805E5D98) {
        z = y * y;
        return y * (lbl_805E5D58 -
                     z * __fnmsubs(z, __fnmsubs(lbl_805E5D80, z, lbl_805E5D7C),
                                   lbl_805E5D78));
    }
    z = (f32) (lbl_805E5D70 - (f64) y);
    z = z * z;
    return lbl_805E5D84 -
           z * __fnmsubs(z, __fnmsubs(lbl_805E5D90, z, lbl_805E5D8C),
                         lbl_805E5D88);
}

static inline f32 kar_quat_half(f32 y)
{
    if (y <= lbl_805E5D70) {
        return kar_quat_poly(y);
    }
    return kar_quat_poly((f32) (lbl_805E5D68 - (f64) y));
}

static inline f32 kar_quat_reduce(f32 y)
{
    while (y > lbl_805E5D60) {
        y = (f32) (y - lbl_805E5D60);
    }
    if (y <= lbl_805E5D68) {
        return kar_quat_half(y);
    }
    return -kar_quat_half((f32) (y - lbl_805E5D68));
}

f32 kar_math_quat_sinf_approx(f32 x)
{
    if (x != lbl_805E5D40) {
        if (x < lbl_805E5D40) {
            return -kar_quat_reduce(-x);
        }
        return kar_quat_reduce(x);
    }
    return lbl_805E5D40;
}

f32 kar_math_quat_cosf_approx(f32 x)
{
    f32 y;

    if (x != lbl_805E5D40) {
        y = (f32) ((f64) x + lbl_805E5D70);
        if (y < lbl_805E5D40) {
            return -kar_quat_reduce(-y);
        }
        return kar_quat_reduce(y);
    }
    return lbl_805E5D58;
}

s32 EulerToQuat(Vec* euler, Quaternion* q)
{
    f32 hx;
    f32 hy;
    f32 hz;
    f32 cx;
    f32 cy;
    f32 cz;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 cc;
    f32 ss;

    hx = lbl_805E5D5C * euler->x;
    hy = lbl_805E5D5C * euler->y;
    hz = lbl_805E5D5C * euler->z;

    cx = kar_math_quat_cosf_approx(hx);
    cy = kar_math_quat_cosf_approx(hy);
    cz = kar_math_quat_cosf_approx(hz);
    sx = kar_math_quat_sinf_approx(hx);
    sy = kar_math_quat_sinf_approx(hy);
    sz = kar_math_quat_sinf_approx(hz);

    ss = sy * sz;
    cc = cy * cz;
    q->w = __fmadds(cx, cc, sx * ss);
    q->x = __fmsubs(sx, cc, cx * ss);
    q->y = __fmadds(cz, cx * sy, sz * (sx * cy));
    q->z = __fmsubs(sz, cx * cy, cz * (sx * sy));

    return 1;
}

s32 QuatSlerp(Quaternion* p, Quaternion* q, Quaternion* out, f32 t)
{
    f32 cosom;
    f32 theta;
    f32 sinom;
    f32 sp;
    f32 sq;
    f32 t2;

    cosom = __fmadds(
        p->w, q->w, __fmadds(p->z, q->z, __fmadds(p->x, q->x, p->y * q->y)));

    if ((lbl_805E5D58 + cosom) > lbl_805E5DA0) {
        if ((lbl_805E5D58 - cosom) > lbl_805E5DA0) {
            theta = (f32) fn_803BD388(cosom);
            sinom = kar_math_quat_sinf_approx(theta);
            sp = kar_math_quat_sinf_approx((lbl_805E5D58 - t) * theta) / sinom;
            sq = kar_math_quat_sinf_approx(t * theta) / sinom;
        } else {
            sq = t;
            sp = (f32) (lbl_805E5DA8 - (f64) t);
        }
        out->x = __fmadds(sp, p->x, sq * q->x);
        out->y = __fmadds(sp, p->y, sq * q->y);
        out->z = __fmadds(sp, p->z, sq * q->z);
        out->w = __fmadds(sp, p->w, sq * q->w);
    } else {
        out->x = -p->y;
        out->y = p->x;
        out->z = -p->w;
        out->w = p->z;

        if (t < lbl_805E5D5C) {
            sp = kar_math_quat_sinf_approx(
                (f32) (lbl_805E5D70 * (lbl_805E5D58 - (lbl_805E5DB0 * t))));
            sq = kar_math_quat_sinf_approx(
                (f32) (lbl_805E5D70 * (lbl_805E5DB0 * t)));
            out->x = __fmadds(sp, p->x, sq * q->x);
            out->y = __fmadds(sp, p->y, sq * q->y);
            out->z = __fmadds(sp, p->z, sq * q->z);
            out->w = __fmadds(sp, p->w, sq * q->w);
        } else {
            t -= lbl_805E5D5C;
            t2 = lbl_805E5DB0 * t;
            sp = kar_math_quat_sinf_approx(
                (f32) (lbl_805E5D70 * (lbl_805E5D58 - t2)));
            sq = kar_math_quat_sinf_approx((f32) (lbl_805E5D70 * t2));
            out->x = __fmadds(sp, p->x, sq * q->x);
            out->y = __fmadds(sp, p->y, sq * q->y);
            out->z = __fmadds(sp, p->z, sq * q->z);
            out->w = __fmadds(sp, p->w, sq * q->w);
        }
    }

    return 1;
}
