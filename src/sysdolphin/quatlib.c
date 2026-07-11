#include <global.h>
#include <kar/math.h>
#include <sysdolphin/mtx.h>

extern f32 QuatZero; /* 0.0F */
extern f64 QuatHalfDouble; /* 0.5 */
extern f64 QuatThreeDouble; /* 3.0 */
extern f32 QuatOne; /* 1.0F */
extern f32 QuatHalf; /* 0.5F */
extern f64 QuatTwoPi; /* 2*PI */
extern f64 QuatPi; /* PI */
extern f64 QuatHalfPi; /* PI/2 */
extern f32 QuatSinPolyC0;
extern f32 QuatSinPolyC1;
extern f32 QuatSinPolyC2;
extern f32 QuatCosPolyBase;
extern f32 QuatCosPolyC0;
extern f32 QuatCosPolyC1;
extern f32 QuatCosPolyC2;
extern f64 QuatQuarterPi; /* PI/4 */
extern f32 QuatSlerpEpsilon; /* 1e-10F */
extern f64 QuatOneDouble; /* 1.0 */
extern f32 QuatTwo; /* 2.0F */
extern f32 HSD_FloatMin[]; /* FLT_MIN */

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
    if (lensq > QuatZero) {
        volatile f32 y;
        f64 guess = __frsqrte((f64) lensq);
        guess = QuatHalfDouble * guess *
                __fnmsub(lensq, guess * guess, QuatThreeDouble);
        guess = QuatHalfDouble * guess *
                __fnmsub(lensq, guess * guess, QuatThreeDouble);
        guess = QuatHalfDouble * guess *
                __fnmsub(lensq, guess * guess, QuatThreeDouble);
        y = (f32) (lensq * guess);
        lensq = y;
    }
    if (__fabsf(lensq) < HSD_FloatMin[0]) {
        return 0;
    }
    inv_len = QuatOne / lensq;
    half_angle = QuatHalf * angle;
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

    if (y <= QuatQuarterPi) {
        z = y * y;
        return y * (QuatOne -
                     z * __fnmsubs(z, __fnmsubs(QuatSinPolyC2, z, QuatSinPolyC1),
                                   QuatSinPolyC0));
    }
    z = (f32) (QuatHalfPi - (f64) y);
    z = z * z;
    return QuatCosPolyBase -
           z * __fnmsubs(z, __fnmsubs(QuatCosPolyC2, z, QuatCosPolyC1),
                         QuatCosPolyC0);
}

static inline f32 kar_quat_half(f32 y)
{
    if (y <= QuatHalfPi) {
        return kar_quat_poly(y);
    }
    return kar_quat_poly((f32) (QuatPi - (f64) y));
}

static inline f32 kar_quat_reduce(f32 y)
{
    while (y > QuatTwoPi) {
        y = (f32) (y - QuatTwoPi);
    }
    if (y <= QuatPi) {
        return kar_quat_half(y);
    }
    return -kar_quat_half((f32) (y - QuatPi));
}

f32 kar_math_quat_sinf_approx(f32 x)
{
    if (x != QuatZero) {
        if (x < QuatZero) {
            return -kar_quat_reduce(-x);
        }
        return kar_quat_reduce(x);
    }
    return QuatZero;
}

f32 kar_math_quat_cosf_approx(f32 x)
{
    f32 y;

    if (x != QuatZero) {
        y = (f32) ((f64) x + QuatHalfPi);
        if (y < QuatZero) {
            return -kar_quat_reduce(-y);
        }
        return kar_quat_reduce(y);
    }
    return QuatOne;
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

    hx = QuatHalf * euler->x;
    hy = QuatHalf * euler->y;
    hz = QuatHalf * euler->z;

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

    if ((QuatOne + cosom) > QuatSlerpEpsilon) {
        if ((QuatOne - cosom) > QuatSlerpEpsilon) {
            theta = (f32) kar_acos(cosom);
            sinom = kar_math_quat_sinf_approx(theta);
            sp = kar_math_quat_sinf_approx((QuatOne - t) * theta) / sinom;
            sq = kar_math_quat_sinf_approx(t * theta) / sinom;
        } else {
            sq = t;
            sp = (f32) (QuatOneDouble - (f64) t);
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

        if (t < QuatHalf) {
            sp = kar_math_quat_sinf_approx(
                (f32) (QuatHalfPi * (QuatOne - (QuatTwo * t))));
            sq = kar_math_quat_sinf_approx(
                (f32) (QuatHalfPi * (QuatTwo * t)));
            out->x = __fmadds(sp, p->x, sq * q->x);
            out->y = __fmadds(sp, p->y, sq * q->y);
            out->z = __fmadds(sp, p->z, sq * q->z);
            out->w = __fmadds(sp, p->w, sq * q->w);
        } else {
            t -= QuatHalf;
            t2 = QuatTwo * t;
            sp = kar_math_quat_sinf_approx(
                (f32) (QuatHalfPi * (QuatOne - t2)));
            sq = kar_math_quat_sinf_approx((f32) (QuatHalfPi * t2));
            out->x = __fmadds(sp, p->x, sq * q->x);
            out->y = __fmadds(sp, p->y, sq * q->y);
            out->z = __fmadds(sp, p->z, sq * q->z);
            out->w = __fmadds(sp, p->w, sq * q->w);
        }
    }

    return 1;
}
