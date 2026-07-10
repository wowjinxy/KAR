#include <global.h>
#include <sysdolphin/spline.h>

extern f32 lbl_805E5BE0; /* 2.0F */
extern f32 lbl_805E5BE4; /* 3.0F */
extern f32 lbl_805E5BE8; /* 1.0F */
extern f32 lbl_805E5BEC; /* 1.0F / 6.0F */
extern f32 lbl_805E5BF0; /* 4.0F */
extern f32 lbl_805E5BF4; /* 6.0F */
extern f32 lbl_805E5BF8; /* 0.0F */
extern f32 lbl_805E5C08; /* -0.001F */
extern f64 lbl_805E5C10; /* 0.5 */
extern f64 lbl_805E5C18; /* 3.0 */
extern f32 lbl_805E5C20; /* 0.125F */
extern f32 lbl_805E5C24; /* 0.5F */
extern f32 lbl_805E5C28; /* 0.00001F */

extern f64 __frsqrte(f64 x);
extern f64 __fnmsub(f64 a, f64 c, f64 b);
extern f32 __fmadds(f32 a, f32 c, f32 b); /* = a*c+b */
extern f32 __fmsubs(f32 a, f32 c, f32 b); /* = a*c-b */
extern f32 __fnmsubs(f32 a, f32 c, f32 b); /* = b-a*c */

#define ABS(x) ((x) < lbl_805E5BF8 ? -(x) : (x))

f32 splGetHelmite(f32 fterm, f32 time, f32 p0, f32 p1, f32 d0, f32 d1)
{
    f32 _3t2_T2;
    f32 _2t3_T3;
    f32 t3_T2;
    f32 t2_T;
    f32 t2;
    f32 _1_T2;
    f32 result;

    _1_T2 = time * time;
    t2 = fterm * fterm;
    t2_T = _1_T2 * fterm;
    t3_T2 = t2 * (_1_T2 * time);
    _2t3_T3 = lbl_805E5BE0 * t3_T2 * fterm;
    _3t2_T2 = lbl_805E5BE4 * _1_T2 * t2;

    result = p1 * (-_2t3_T3 + _3t2_T2);
    result = __fmadds(p0, lbl_805E5BE8 + (_2t3_T3 - _3t2_T2), result);
    result = __fmadds(d0, time + ((t3_T2 - t2_T) - t2_T), result);
    result = __fmadds(d1, t3_T2 - t2_T, result);
    return result;
}

void splGetCardinalPoint(Vec* p, Vec* cp, f32 u)
{
    f32 u2 = u * u;
    f32 u3 = u2 * u;
    f32 k1_6 = lbl_805E5BEC;
    f32 u_1 = lbl_805E5BE8 - u;
    f32 b0 = k1_6 * u_1 * u_1 * u_1;
    f32 b1 = k1_6 * (lbl_805E5BF0 + __fmsubs(lbl_805E5BE4, u3, lbl_805E5BF4 * u2));
    f32 b2 = k1_6 * __fmadds(lbl_805E5BE4, -u3 + u2 + u, lbl_805E5BE8);
    f32 b3 = k1_6 * u3;
    f32 result;

    result = cp[1].x * b1;
    result = __fmadds(cp[0].x, b0, result);
    result = __fmadds(cp[2].x, b2, result);
    result = __fmadds(cp[3].x, b3, result);
    p->x = result;

    result = cp[1].y * b1;
    result = __fmadds(cp[0].y, b0, result);
    result = __fmadds(cp[2].y, b2, result);
    result = __fmadds(cp[3].y, b3, result);
    p->y = result;

    result = cp[1].z * b1;
    result = __fmadds(cp[0].z, b0, result);
    result = __fmadds(cp[2].z, b2, result);
    result = __fmadds(cp[3].z, b3, result);
    p->z = result;
}

static inline void spl_GetBezierPoint(Vec* p, Vec* cp, f32 u)
{
    f32 u_1 = lbl_805E5BE8 - u;
    f32 u2 = u * u;
    f32 u_12 = u_1 * u_1;
    f32 bez0 = u_12 * u_1;
    f32 bez1 = lbl_805E5BE4 * u * u_12;
    f32 bez2 = lbl_805E5BE4 * u2 * u_1;
    f32 bez3 = u2 * u;
    f32 result;

    result = cp[1].x * bez1;
    result = __fmadds(cp[0].x, bez0, result);
    result = __fmadds(cp[2].x, bez2, result);
    result = __fmadds(cp[3].x, bez3, result);
    p->x = result;

    result = cp[1].y * bez1;
    result = __fmadds(cp[0].y, bez0, result);
    result = __fmadds(cp[2].y, bez2, result);
    result = __fmadds(cp[3].y, bez3, result);
    p->y = result;

    result = cp[1].z * bez1;
    result = __fmadds(cp[0].z, bez0, result);
    result = __fmadds(cp[2].z, bez2, result);
    result = __fmadds(cp[3].z, bez3, result);
    p->z = result;
}

static inline void spl_GetCardinalBlend(Vec* p, Vec* cp, f32 tension, f32 u)
{
    f32 u2 = u * u;
    f32 u3 = u2 * u;
    f32 car0 = tension * (__fmadds(lbl_805E5BE0, u2, -u3) - u);
    f32 car1 = lbl_805E5BE8 +
               __fmadds(lbl_805E5BE0 - tension, u3, (tension - lbl_805E5BE4) * u2);
    f32 car2 = __fmadds(tension, u,
                         __fmadds(tension - lbl_805E5BE0, u3,
                                  __fnmsubs(lbl_805E5BE0, tension, lbl_805E5BE4) * u2));
    f32 car3 = tension * (u3 - u2);
    f32 result;

    result = cp[1].x * car1;
    result = __fmadds(cp[0].x, car0, result);
    result = __fmadds(cp[2].x, car2, result);
    result = __fmadds(cp[3].x, car3, result);
    p->x = result;

    result = cp[1].y * car1;
    result = __fmadds(cp[0].y, car0, result);
    result = __fmadds(cp[2].y, car2, result);
    result = __fmadds(cp[3].y, car3, result);
    p->y = result;

    result = cp[1].z * car1;
    result = __fmadds(cp[0].z, car0, result);
    result = __fmadds(cp[2].z, car2, result);
    result = __fmadds(cp[3].z, car3, result);
    p->z = result;
}

void splGetSplinePoint(Vec* p, HSD_Spline* spline, f32 u)
{
    Vec* cp;
    s16 idx;

    if (u < lbl_805E5BF8 || u > lbl_805E5BE8) {
        return;
    }

    if (u < lbl_805E5BE8) {
        f32 t = (u * (spline->numcv - 1));
        idx = t;
        t = t - (f32) idx;
        switch (spline->type) {
        case 0:
            cp = &spline->cv[idx];
            p->x = __fmadds(t, cp[1].x - cp[0].x, cp[0].x);
            p->y = __fmadds(t, cp[1].y - cp[0].y, cp[0].y);
            p->z = __fmadds(t, cp[1].z - cp[0].z, cp[0].z);
            return;
        case 1:
            cp = &spline->cv[idx * 3];
            spl_GetBezierPoint(p, cp, t);
            return;
        case 2:
            cp = &spline->cv[idx];
            splGetCardinalPoint(p, cp, t);
            return;
        case 3: {
            cp = &spline->cv[idx];
            spl_GetCardinalBlend(p, cp, spline->tension, t);
            return;
        }
        }
    } else {
        idx = spline->numcv - 1;
        switch (spline->type) {
        case 0:
            *p = spline->cv[idx];
            return;
        case 1:
            *p = spline->cv[idx * 3];
            return;
        case 2:
            cp = &spline->cv[idx] - 1;
            splGetCardinalPoint(p, cp, lbl_805E5BE8);
            return;
        case 3:
            cp = &spline->cv[idx];
            *p = cp[1];
            return;
        }
    }
}

static inline f32 spl_ArcLengthPolySqrt(const f32 coeffs[5], f32 t)
{
    f32 t2 = t * t;
    f32 t3 = t2 * t;
    f32 t4 = t3 * t;
    f32 result = coeffs[1] * t3;
    result = __fmadds(coeffs[0], t4, result);
    result = __fmadds(coeffs[2], t2, result);
    result = __fmadds(coeffs[3], t, result);
    result = coeffs[4] + result;

    if (result < lbl_805E5BF8 && result > lbl_805E5C08) {
        result = lbl_805E5BF8;
    }

    if (result > lbl_805E5BF8) {
        volatile f32 y;
        f64 guess = __frsqrte((f64) result);
        guess = lbl_805E5C10 * guess * __fnmsub(result, guess * guess, lbl_805E5C18);
        guess = lbl_805E5C10 * guess * __fnmsub(result, guess * guess, lbl_805E5C18);
        guess = lbl_805E5C10 * guess * __fnmsub(result, guess * guess, lbl_805E5C18);
        y = (f32) (result * guess);
        return y;
    }
    return result;
}

f32 splArcLength(const f32 coeffs[5], f32 start, f32 end)
{
    f32 dx = (end - start) * lbl_805E5C20;
    f32 t = start + dx;
    f32 sum = lbl_805E5BF8;
    s32 i;

    for (i = 2; i <= 8; i++) {
        if (!(i & 1)) {
            sum += lbl_805E5BF0 * spl_ArcLengthPolySqrt(coeffs, t);
        } else {
            sum += lbl_805E5BE0 * spl_ArcLengthPolySqrt(coeffs, t);
        }
        t += dx;
    }

    return (dx * (sum + spl_ArcLengthPolySqrt(coeffs, start) +
                  spl_ArcLengthPolySqrt(coeffs, end))) /
           lbl_805E5BE4;
}

f32 splArcLengthGetParameter(HSD_Spline* spl, f32 arg1)
{
    s32 idx = 0;
    f32 start = lbl_805E5BF8;
    f32 end = lbl_805E5BE8;
    f32 result;

    if (arg1 <= start) {
        return start;
    }

    if (arg1 >= end) {
        return end;
    }

    while (spl->segLength[idx + 1] < arg1) {
        idx++;
    }

    switch (spl->type) {
    case 0: {
        result = (arg1 - spl->segLength[idx]) /
                 (spl->segLength[idx + 1] - spl->segLength[idx]);
    } break;
    case 1:
    case 2:
    case 3: {
        f32 epsilon = lbl_805E5C28;
        f32 half = lbl_805E5C24;
        f32 zero = lbl_805E5BF8;
        f32 var_f22 = spl->totalLength * (arg1 - spl->segLength[idx]);

        while ((start - end < zero ? -(start - end) : (start - end)) >= epsilon) {
            const f32* coeffs = spl->segPoly[idx];
            f32 simpsons;

            result = (start + end) * half;
            simpsons = splArcLength(coeffs, start, result);
            if (var_f22 < (epsilon + simpsons)) {
                end = result;
            } else {
                start = result;
                var_f22 -= simpsons;
            }
        }
    } break;
    }

    return (result + idx) / (spl->numcv - lbl_805E5BE8);
}

void splArcLengthPoint(Vec* vec, HSD_Spline* spline, f32 param)
{
    splGetSplinePoint(vec, spline, splArcLengthGetParameter(spline, param));
}
