#include <global.h>
#include <sysdolphin/mtx.h>

extern HSD_ObjAllocData lbl_8058BBB8; /* Vec alloc data */
extern HSD_ObjAllocData lbl_8058BBE4; /* Mtx alloc data */

extern char kar_srcfile_mtx_c_805dcc40[6]; /* "mtx.c" */
extern char lbl_805DCC48[4];               /* "vec" */
extern char lbl_805DCC4C[4];                /* "mtx" */
#define assert_line_named(line, cond, condstr) \
    ((cond) ? ((void) 0) : __assert(kar_srcfile_mtx_c_805dcc40, line, condstr))

extern f64 lbl_805E5C30; /* EPSILON */
extern f32 lbl_805E5C38; /* 1.0F */
extern f32 lbl_805E5C3C; /* 0.0F */
extern f64 lbl_805E5C40; /* 0.5 */
extern f64 lbl_805E5C48; /* 3.0 */
extern f32 lbl_805E5C50; /* PI/2 */
extern f32 lbl_805E5C54; /* -1.0F */
extern f32 lbl_805E5C58; /* -PI/2 */
extern f64 lbl_805E5C60; /* PI/2 */
extern f64 lbl_805E5C68; /* 2*PI */
extern f64 lbl_805E5C70; /* PI */
extern f32 lbl_805E5C78; /* sin c1 */
extern f32 lbl_805E5C7C; /* sin c2 */
extern f32 lbl_805E5C80; /* sin c3 */
extern f32 lbl_805E5C84; /* cos c0 */
extern f32 lbl_805E5C88; /* cos c1 */
extern f32 lbl_805E5C8C; /* cos c2 */
extern f32 lbl_805E5C90; /* cos c3 */
extern f64 lbl_805E5C98; /* PI/4 */
extern f32 lbl_805E5CA0; /* EPSILON (f32) */
extern f64 lbl_805E5CA8; /* 0.0 */
extern f64 lbl_805E5CB0; /* -1.0 */

extern f32 lbl_805DC8B8[]; /* FLOAT_MIN */
extern f32 lbl_805DC8C0[]; /* FLT_EPSILON */

extern void kar_fl_indirectload__803d13fc(Mtx dest); /* PSMTXIdentity */
extern void PSMTXCopy(Mtx src, Mtx dst);
extern void PSMTXConcat(Mtx a, Mtx b, Mtx ab);
extern void fn_803D19AC(Mtx m, f32 xs, f32 ys, f32 zs); /* PSMTXScale */
extern void fn_803D19D4(Mtx m, Quaternion* q);          /* PSMTXQuat */

extern void PSVECNormalize(Vec* src, Vec* dst);
extern void PSVECScale(f32 scale, Vec* src, Vec* dst);
extern void PSVECSubtract(Vec* a, Vec* b, Vec* dst);
extern void PSVECCrossProduct(Vec* a, Vec* b, Vec* dst);
extern f32 PSVECDotProduct(Vec* a, Vec* b);
extern f32 PSVECMag(Vec* v);
extern f32 PSVECSquareMag(Vec* v);

extern f64 fn_803BD3A8(f64 x);      /* asin */
extern f64 fn_803BD3C8(f64 y, f64 x); /* atan2 */

extern f64 __frsqrte(f64 x);
extern f64 __fnmsub(f64 a, f64 c, f64 b);
extern f32 __fnmsubs(f32 a, f32 c, f32 b);
extern f32 __fmadds(f32 a, f32 c, f32 b); /* = a*c+b */
extern f32 __fmsubs(f32 a, f32 c, f32 b); /* = a*c-b */

f32 kar_math_mtx_cosf_approx(f32 x);
f32 kar_math_mtx_sinf_approx(f32 x);

static inline f32 mtx_sqrtf(f32 x)
{
    volatile f32 y;

    if (x > lbl_805E5C3C) {
        f64 guess = __frsqrte((f64) x);
        guess = lbl_805E5C40 * guess * __fnmsub(x, guess * guess, lbl_805E5C48);
        guess = lbl_805E5C40 * guess * __fnmsub(x, guess * guess, lbl_805E5C48);
        guess = lbl_805E5C40 * guess * __fnmsub(x, guess * guess, lbl_805E5C48);
        y = (f32) (x * guess);
        return y;
    }
    return x;
}

static inline f32 mtx_calcVal(f32 x, f32 y)
{
    if (lbl_805E5C3C == x) {
        return y >= lbl_805E5C3C ? lbl_805E5C50 : lbl_805E5C58;
    }
    return (f32) fn_803BD3C8(y, x);
}

static inline f32 mtx_safe_recip(f32 x)
{
    if (x >= lbl_805E5C3C) {
        return lbl_805E5C38 / (x + lbl_805DC8C0[0]);
    }
    return lbl_805E5C38 / (x - lbl_805DC8C0[0]);
}

static inline f32 HSD_CalcDeterminantMatrix3x4(Mtx m)
{
    f32 det = m[2][0] * (m[0][1] * m[1][2]);
    det = __fmadds(m[2][2], m[0][0] * m[1][1], det);
    det = __fmadds(m[2][1], m[0][2] * m[1][0], det);
    det = __fnmsubs(m[0][2], m[2][0] * m[1][1], det);
    det = __fnmsubs(m[2][2], m[1][0] * m[0][1], det);
    det = __fnmsubs(m[1][2], m[0][0] * m[2][1], det);
    return det;
}

void HSD_MtxInverse(Mtx src, Mtx dest)
{
    Mtx tempMatrix;
    MtxPtr m;
    f32 det = HSD_CalcDeterminantMatrix3x4(src);

    if (__fabs(det) < lbl_805E5C30) {
        kar_fl_indirectload__803d13fc(dest);
        return;
    }

    if (src == dest) {
        PSMTXCopy(src, tempMatrix);
        m = tempMatrix;
    } else {
        m = src;
    }

    det = lbl_805E5C38 / det;

    {
        f32 t;
        t = m[2][1] * m[1][2];
        dest[0][0] = __fmsubs(m[1][1], m[2][2], t) * det;
        t = m[2][1] * m[0][2];
        dest[0][1] = __fnmsubs(m[0][1], m[2][2], t) * det;
        t = m[1][1] * m[0][2];
        dest[0][2] = __fmsubs(m[0][1], m[1][2], t) * det;
        t = m[2][0] * m[1][2];
        dest[1][0] = __fnmsubs(m[1][0], m[2][2], t) * det;
        t = m[2][0] * m[0][2];
        dest[1][1] = __fmsubs(m[0][0], m[2][2], t) * det;
        t = m[1][0] * m[0][2];
        dest[1][2] = __fnmsubs(m[0][0], m[1][2], t) * det;
        t = m[2][0] * m[1][1];
        dest[2][0] = __fmsubs(m[1][0], m[2][1], t) * det;
        t = m[2][0] * m[0][1];
        dest[2][1] = __fnmsubs(m[0][0], m[2][1], t) * det;
        t = m[1][0] * m[0][1];
        dest[2][2] = __fmsubs(m[0][0], m[1][1], t) * det;
    }

    {
        f32 t, v;
        t = dest[0][1] * m[1][3];
        v = __fmsubs(-dest[0][0], m[0][3], t);
        dest[0][3] = __fnmsubs(dest[0][2], m[2][3], v);

        t = dest[1][1] * m[1][3];
        v = __fmsubs(-dest[1][0], m[0][3], t);
        dest[1][3] = __fnmsubs(dest[1][2], m[2][3], v);

        t = dest[2][1] * m[1][3];
        v = __fmsubs(-dest[2][0], m[0][3], t);
        dest[2][3] = __fnmsubs(dest[2][2], m[2][3], v);
    }
}

BOOL HSD_MtxInverseConcat(Mtx inv, Mtx src, Mtx dest)
{
    Mtx m;
    f32 det;
    f32 temp1, temp2, temp3, temp4, temp5, temp6;
    f32 temp7, temp8, temp9, temp10, temp11, temp12;
    f32 new_var;

    det = HSD_CalcDeterminantMatrix3x4(inv);

    if (__fabs(det) < lbl_805E5C30) {
        if (src != dest) {
            PSMTXCopy(src, dest);
        }
        return FALSE;
    } else {
        f32 t, v;

        det = lbl_805E5C38 / det;
        new_var = inv[1][1];

        t = inv[2][1] * inv[1][2];
        temp1 = __fmsubs(inv[1][1], inv[2][2], t) * det;
        t = inv[2][1] * inv[0][2];
        temp2 = __fnmsubs(inv[0][1], inv[2][2], t) * det;
        t = inv[2][0] * inv[1][2];
        temp3 = __fnmsubs(inv[1][0], inv[2][2], t) * det;
        t = inv[2][0] * inv[0][2];
        temp4 = __fmsubs(inv[0][0], inv[2][2], t) * det;
        t = inv[2][0] * new_var;
        temp5 = __fmsubs(inv[1][0], inv[2][1], t) * det;
        t = inv[2][0] * inv[0][1];
        temp6 = __fnmsubs(inv[0][0], inv[2][1], t) * det;
        t = new_var * inv[0][2];
        temp7 = __fmsubs(inv[0][1], inv[1][2], t) * det;
        t = inv[0][2] * inv[1][0];
        temp8 = __fnmsubs(inv[0][0], inv[1][2], t) * det;
        t = inv[1][0] * inv[0][1];
        temp9 = __fmsubs(inv[0][0], inv[1][1], t) * det;

        t = temp2 * inv[1][3];
        v = __fmsubs(-temp1, inv[0][3], t);
        temp10 = __fnmsubs(temp7, inv[2][3], v);

        t = temp4 * inv[1][3];
        v = __fmsubs(-temp3, inv[0][3], t);
        temp11 = __fnmsubs(temp8, inv[2][3], v);

        t = temp6 * inv[1][3];
        v = __fmsubs(-temp5, (new_var = inv[0][3]), t);
        temp12 = __fnmsubs(temp9, inv[2][3], v);

        if (inv == dest || src == dest) {
            m[0][0] = temp7 * src[2][0] + (temp1 * src[0][0] + temp2 * src[1][0]);
            m[0][1] = temp7 * src[2][1] + (temp1 * src[0][1] + temp2 * src[1][1]);
            m[0][2] = temp7 * src[2][2] + (temp1 * src[0][2] + temp2 * src[1][2]);
            m[0][3] = temp7 * src[2][3] +
                      (temp1 * src[0][3] + temp2 * src[1][3]) + temp10;
            m[1][0] = temp8 * src[2][0] + (temp3 * src[0][0] + temp4 * src[1][0]);
            m[1][1] = temp8 * src[2][1] + (temp3 * src[0][1] + temp4 * src[1][1]);
            m[1][2] = temp8 * src[2][2] + (temp3 * src[0][2] + temp4 * src[1][2]);
            m[1][3] = temp8 * src[2][3] +
                      (temp3 * src[0][3] + temp4 * src[1][3]) + temp11;
            m[2][0] = temp9 * src[2][0] + (temp5 * src[0][0] + temp6 * src[1][0]);
            m[2][1] = temp9 * src[2][1] + (temp5 * src[0][1] + temp6 * src[1][1]);
            m[2][2] = temp9 * src[2][2] + (temp5 * src[0][2] + temp6 * src[1][2]);
            m[2][3] = temp9 * src[2][3] +
                      (temp5 * src[0][3] + temp6 * src[1][3]) + temp12;

            PSMTXCopy(m, dest);
        } else {
            dest[0][0] = temp7 * src[2][0] + (temp1 * src[0][0] + temp2 * src[1][0]);
            dest[0][1] = temp7 * src[2][1] + (temp1 * src[0][1] + temp2 * src[1][1]);
            dest[0][2] = temp7 * src[2][2] + (temp1 * src[0][2] + temp2 * src[1][2]);
            dest[0][3] = temp7 * src[2][3] +
                         (temp1 * src[0][3] + temp2 * src[1][3]) + temp10;
            dest[1][0] = temp8 * src[2][0] + (temp3 * src[0][0] + temp4 * src[1][0]);
            dest[1][1] = temp8 * src[2][1] + (temp3 * src[0][1] + temp4 * src[1][1]);
            dest[1][2] = temp8 * src[2][2] + (temp3 * src[0][2] + temp4 * src[1][2]);
            dest[1][3] = temp8 * src[2][3] +
                         (temp3 * src[0][3] + temp4 * src[1][3]) + temp11;
            dest[2][0] = temp9 * src[2][0] + (temp5 * src[0][0] + temp6 * src[1][0]);
            dest[2][1] = temp9 * src[2][1] + (temp5 * src[0][1] + temp6 * src[1][1]);
            dest[2][2] = temp9 * src[2][2] + (temp5 * src[0][2] + temp6 * src[1][2]);
            dest[2][3] = temp9 * src[2][3] +
                         (temp5 * src[0][3] + temp6 * src[1][3]) + temp12;
        }
        return TRUE;
    }
}

void HSD_MtxGetRotation(Mtx m, Vec* vec)
{
    f32 length0;
    f32 length1;
    f32 length2;
    f32 testVal_1;
    f32 val_01;

    length0 = mtx_sqrtf(m[0][0] * m[0][0] + m[1][0] * m[1][0] + m[2][0] * m[2][0]);
    if (!(length0 < lbl_805DC8B8[0])) {
        length1 = mtx_sqrtf(m[0][1] * m[0][1] + m[1][1] * m[1][1] + m[2][1] * m[2][1]);
        if (!(length1 < lbl_805DC8B8[0])) {
            length2 = mtx_sqrtf(m[0][2] * m[0][2] + m[1][2] * m[1][2] + m[2][2] * m[2][2]);
            if (!(length2 < lbl_805DC8B8[0])) {
                testVal_1 = -m[2][0];
                testVal_1 /= length0;

                if (testVal_1 >= lbl_805E5C38) {
                    val_01 = lbl_805E5C50;
                } else if (testVal_1 <= lbl_805E5C54) {
                    val_01 = lbl_805E5C58;
                } else {
                    val_01 = (f32) fn_803BD3A8(testVal_1);
                }

                vec->y = val_01;

                if (kar_math_mtx_cosf_approx(vec->y) >= lbl_805DC8B8[0]) {
                    f32 testVal_3_pre = m[2][1] / length1;
                    f32 testVal_2_pre = m[2][2] / length2;

                    vec->x = mtx_calcVal(testVal_2_pre, testVal_3_pre);
                    vec->z = mtx_calcVal(m[0][0], m[1][0]);
                    return;
                }

                vec->x = mtx_calcVal(m[1][1], m[0][1]);
                vec->z = lbl_805E5C3C;
                return;
            }
        }
    }

    {
        f32 zero = lbl_805E5C3C;
        vec->x = zero;
        vec->y = zero;
        vec->z = zero;
    }
}

static inline f32 kar_math_mtx_poly(f32 y)
{
    f32 z;

    if (y <= lbl_805E5C98) {
        z = y * y;
        return y *
               (lbl_805E5C38 -
                z * __fnmsubs(z, __fnmsubs(lbl_805E5C80, z, lbl_805E5C7C),
                              lbl_805E5C78));
    }
    z = (f32) (lbl_805E5C60 - (f64) y);
    z = z * z;
    return lbl_805E5C84 -
           z * __fnmsubs(z, __fnmsubs(lbl_805E5C90, z, lbl_805E5C8C),
                         lbl_805E5C88);
}

static inline f32 kar_math_mtx_half(f32 y)
{
    if (y <= lbl_805E5C60) {
        return kar_math_mtx_poly(y);
    }
    return kar_math_mtx_poly((f32) (lbl_805E5C70 - (f64) y));
}

static inline f32 kar_math_mtx_sin_reduce(f32 y)
{
    while (y > lbl_805E5C68) {
        y = (f32) (y - lbl_805E5C68);
    }
    if (y <= lbl_805E5C70) {
        return kar_math_mtx_half(y);
    }
    return -kar_math_mtx_half((f32) (y - lbl_805E5C70));
}

f32 kar_math_mtx_cosf_approx(f32 x)
{
    f32 y;

    if (x != lbl_805E5C3C) {
        y = (f32) ((f64) x + lbl_805E5C60);
        if (y < lbl_805E5C3C) {
            return -kar_math_mtx_sin_reduce(-y);
        }
        return kar_math_mtx_sin_reduce(y);
    }
    return lbl_805E5C38;
}

void HSD_MtxGetRotationMtx(Mtx v0, Mtx dest, char axis0, char axis1)
{
    Vec vAxis0, vAxis1, vAxis2;
    f32 zero;

    switch (axis0) {
    case 'x':
    case 'X':
        vAxis0.x = v0[0][0];
        vAxis0.y = v0[1][0];
        vAxis0.z = v0[2][0];
        PSVECNormalize(&vAxis0, &vAxis0);
        switch (axis1) {
        case 'z':
        case 'Z':
            vAxis2.x = v0[0][2];
            vAxis2.y = v0[1][2];
            vAxis2.z = v0[2][2];
            PSVECNormalize(&vAxis2, &vAxis2);
            PSVECCrossProduct(&vAxis2, &vAxis0, &vAxis1);
            PSVECCrossProduct(&vAxis0, &vAxis1, &vAxis2);
            break;
        default:
            vAxis1.x = v0[0][1];
            vAxis1.y = v0[1][1];
            vAxis1.z = v0[2][1];
            PSVECNormalize(&vAxis1, &vAxis1);
            PSVECCrossProduct(&vAxis0, &vAxis1, &vAxis2);
            PSVECCrossProduct(&vAxis2, &vAxis0, &vAxis1);
            break;
        }
        break;
    case 'y':
    case 'Y':
        vAxis1.x = v0[0][1];
        vAxis1.y = v0[1][1];
        vAxis1.z = v0[2][1];
        PSVECNormalize(&vAxis1, &vAxis1);
        switch (axis1) {
        case 'x':
        case 'X':
            vAxis0.x = v0[0][0];
            vAxis0.y = v0[1][0];
            vAxis0.z = v0[2][0];
            PSVECNormalize(&vAxis0, &vAxis0);
            PSVECCrossProduct(&vAxis0, &vAxis1, &vAxis2);
            PSVECCrossProduct(&vAxis1, &vAxis2, &vAxis0);
            break;
        default:
            vAxis2.x = v0[0][2];
            vAxis2.y = v0[1][2];
            vAxis2.z = v0[2][2];
            PSVECNormalize(&vAxis2, &vAxis2);
            PSVECCrossProduct(&vAxis1, &vAxis2, &vAxis0);
            PSVECCrossProduct(&vAxis0, &vAxis1, &vAxis2);
            break;
        }
        break;
    default:
        vAxis2.x = v0[0][2];
        vAxis2.y = v0[1][2];
        vAxis2.z = v0[2][2];
        PSVECNormalize(&vAxis2, &vAxis2);
        switch (axis1) {
        case 'y':
        case 'Y':
            vAxis1.x = v0[0][1];
            vAxis1.y = v0[1][1];
            vAxis1.z = v0[2][1];
            PSVECNormalize(&vAxis1, &vAxis1);
            PSVECCrossProduct(&vAxis1, &vAxis2, &vAxis0);
            PSVECCrossProduct(&vAxis2, &vAxis0, &vAxis1);
            break;
        default:
            vAxis0.x = v0[0][0];
            vAxis0.y = v0[1][0];
            vAxis0.z = v0[2][0];
            PSVECNormalize(&vAxis0, &vAxis0);
            PSVECCrossProduct(&vAxis2, &vAxis0, &vAxis1);
            PSVECCrossProduct(&vAxis1, &vAxis2, &vAxis0);
            break;
        }
        break;
    }

    zero = lbl_805E5C3C;
    dest[0][0] = vAxis0.x;
    dest[1][0] = vAxis0.y;
    dest[2][0] = vAxis0.z;
    dest[0][1] = vAxis1.x;
    dest[1][1] = vAxis1.y;
    dest[2][1] = vAxis1.z;
    dest[0][2] = vAxis2.x;
    dest[1][2] = vAxis2.y;
    dest[2][2] = vAxis2.z;
    dest[0][3] = zero;
    dest[1][3] = zero;
    dest[2][3] = zero;
}

void HSD_MtxGetTranslate(Mtx mat, Vec* vec)
{
    vec->x = mat[0][3];
    vec->y = mat[1][3];
    vec->z = mat[2][3];
}

void HSD_MtxGetScale(Mtx arg0, Vec* arg1)
{
    Vec vec1;
    Vec vec2;
    Vec vec3;
    Vec vec4;
    f32 sq1, sq2, sq3;

    vec1.x = arg0[0][0];
    vec1.y = arg0[1][0];
    vec1.z = arg0[2][0];

    sq1 = PSVECSquareMag(&vec1);
    if (sq1 > lbl_805E5CA0) {
        f32 invMag = mtx_sqrtf(lbl_805E5C38 / sq1);
        arg1->x = lbl_805E5C38 / invMag;
        PSVECScale(invMag, &vec1, &vec1);

        vec2.x = arg0[0][1];
        vec2.y = arg0[1][1];
        vec2.z = arg0[2][1];

        PSVECScale(PSVECDotProduct(&vec1, &vec2), &vec1, &vec4);
        PSVECSubtract(&vec2, &vec4, &vec2);

        sq2 = PSVECSquareMag(&vec2);
        if (sq2 > lbl_805E5CA0) {
            f32 invMag2 = mtx_sqrtf(lbl_805E5C38 / sq2);
            arg1->y = lbl_805E5C38 / invMag2;
            PSVECScale(invMag2, &vec2, &vec2);

            vec3.x = arg0[0][2];
            vec3.y = arg0[1][2];
            vec3.z = arg0[2][2];

            PSVECScale(PSVECDotProduct(&vec2, &vec3), &vec2, &vec4);
            PSVECSubtract(&vec3, &vec4, &vec3);
            PSVECScale(PSVECDotProduct(&vec1, &vec3), &vec1, &vec4);
            PSVECSubtract(&vec3, &vec4, &vec3);

            sq3 = PSVECSquareMag(&vec3);
            if (sq3 > lbl_805E5CA0) {
                arg1->z = mtx_sqrtf(sq3);

                PSVECCrossProduct(&vec2, &vec3, &vec4);
                if (PSVECDotProduct(&vec1, &vec4) < lbl_805E5CA8) {
                    f64 neg;
                    arg1->x = (f32) (arg1->x * (neg = lbl_805E5CB0));
                    arg1->y = (f32) (arg1->y * neg);
                    arg1->z = (f32) (arg1->z * neg);
                }
            } else {
                arg1->z = lbl_805E5C3C;
            }
        } else {
            arg1->y = lbl_805E5C3C;

            vec3.x = arg0[0][2];
            vec3.y = arg0[1][2];
            vec3.z = arg0[2][2];

            PSVECScale(PSVECDotProduct(&vec1, &vec3), &vec1, &vec4);
            PSVECSubtract(&vec3, &vec4, &vec3);

            sq3 = PSVECSquareMag(&vec3);
            if (sq3 > lbl_805E5CA0) {
                arg1->z = mtx_sqrtf(sq3);
            } else {
                arg1->z = lbl_805E5C3C;
            }
        }
    } else {
        arg1->x = lbl_805E5C3C;

        vec2.x = arg0[0][1];
        vec2.y = arg0[1][1];
        vec2.z = arg0[2][1];

        sq2 = PSVECSquareMag(&vec2);
        if (sq2 > lbl_805E5CA0) {
            f32 invMag2 = mtx_sqrtf(lbl_805E5C38 / sq2);
            arg1->y = lbl_805E5C38 / invMag2;
            PSVECScale(invMag2, &vec2, &vec2);

            vec3.x = arg0[0][2];
            vec3.y = arg0[1][2];
            vec3.z = arg0[2][2];

            PSVECScale(PSVECDotProduct(&vec2, &vec3), &vec2, &vec4);
            PSVECSubtract(&vec3, &vec4, &vec3);
            arg1->z = PSVECMag(&vec3);
        } else {
            arg1->y = lbl_805E5C3C;

            vec3.x = arg0[0][2];
            vec3.y = arg0[1][2];
            vec3.z = arg0[2][2];

            arg1->z = PSVECMag(&vec3);
        }
    }
}

void HSD_MkRotationMtx(Mtx arg0, Vec* arg1)
{
    f32 sinX;
    f32 cosX;
    f32 sinY;
    f32 cosY;
    f32 sinZ;
    f32 cosZ;
    f32 temp1;
    f32 temp2;

    sinX = kar_math_mtx_sinf_approx(arg1->x);
    cosX = kar_math_mtx_cosf_approx(arg1->x);
    sinY = kar_math_mtx_sinf_approx(arg1->y);
    cosY = kar_math_mtx_cosf_approx(arg1->y);
    sinZ = kar_math_mtx_sinf_approx(arg1->z);
    cosZ = kar_math_mtx_cosf_approx(arg1->z);

    {
        f32 zero;
        temp1 = sinX * sinY;
        zero = lbl_805E5C3C;
        arg0[0][0] = cosY * cosZ;
        arg0[1][0] = cosY * sinZ;
        arg0[2][0] = -sinY;
        temp2 = cosX * sinY;
        arg0[0][1] = __fmsubs(cosZ, temp1, cosX * sinZ);
        arg0[1][1] = __fmadds(sinZ, temp1, cosX * cosZ);
        arg0[2][1] = sinX * cosY;
        arg0[0][2] = __fmadds(cosZ, temp2, sinX * sinZ);
        arg0[1][2] = __fmsubs(sinZ, temp2, sinX * cosZ);
        arg0[2][2] = cosX * cosY;
        arg0[0][3] = zero;
        arg0[1][3] = zero;
        arg0[2][3] = zero;
    }
}

f32 kar_math_mtx_sinf_approx(f32 x)
{
    if (x != lbl_805E5C3C) {
        if (x < lbl_805E5C3C) {
            return -kar_math_mtx_sin_reduce(-x);
        }
        return kar_math_mtx_sin_reduce(x);
    }
    return lbl_805E5C3C;
}

void HSD_MtxSRT(Mtx m, Vec* vec1, Vec* vec2, Vec* vec3, Vec* vec4)
{
    f32 vec1x_2;
    f32 vec1y_2;
    f32 vec1z_2;
    f32 vec1x_1;
    f32 vec1y_1;
    f32 vec1z_1;
    f32 vec1x;
    f32 vec1y;
    f32 vec1z;

    f32 sinX = kar_math_mtx_sinf_approx(vec2->x);
    f32 cosX = kar_math_mtx_cosf_approx(vec2->x);
    f32 sinY = kar_math_mtx_sinf_approx(vec2->y);
    f32 cosY = kar_math_mtx_cosf_approx(vec2->y);
    f32 sinZ = kar_math_mtx_sinf_approx(vec2->z);
    f32 cosZ = kar_math_mtx_cosf_approx(vec2->z);

    vec1x_2 = vec1x_1 = vec1x = vec1->x;
    vec1y_2 = vec1y_1 = vec1y = vec1->y;
    vec1z_2 = vec1z_1 = vec1z = vec1->z;

    if (vec4 != NULL) {
        f32 temp1 = mtx_safe_recip(vec4->x);
        f32 temp2 = mtx_safe_recip(vec4->y);
        f32 temp3 = mtx_safe_recip(vec4->z);

        vec1y_2 *= vec4->y * temp1;
        vec1z_2 *= vec4->z * temp1;
        vec1x_1 *= vec4->x * temp2;
        vec1z_1 *= vec4->z * temp2;
        vec1x *= vec4->x * temp3;
        vec1y *= vec4->y * temp3;
    }

    m[0][0] = cosZ * (vec1x_2 * cosY);
    m[1][0] = sinZ * (vec1x_1 * cosY);
    m[2][0] = -vec1x * sinY;
    m[0][1] = vec1y_2 * __fmsubs(cosZ, sinX * sinY, cosX * sinZ);
    m[1][1] = vec1y_1 * __fmadds(sinZ, sinX * sinY, cosX * cosZ);
    m[2][1] = cosY * (vec1y * sinX);
    m[0][2] = vec1z_2 * __fmadds(cosZ, cosX * sinY, sinX * sinZ);
    m[1][2] = vec1z_1 * __fmsubs(sinZ, cosX * sinY, sinX * cosZ);
    m[2][2] = cosY * (vec1z * cosX);
    m[0][3] = vec3->x;
    m[1][3] = vec3->y;
    m[2][3] = vec3->z;
}

void HSD_MtxSRTQuat(Mtx arg0, Vec* arg1, Quaternion* arg2, Vec* arg3, Vec* arg4)
{
    Mtx temp;

    fn_803D19AC(arg0, arg1->x, arg1->y, arg1->z);
    fn_803D19D4(temp, arg2);

    if (arg4 != NULL) {
        f32 rx = mtx_safe_recip(arg4->x);
        f32 ry = mtx_safe_recip(arg4->y);
        f32 rz = mtx_safe_recip(arg4->z);

        temp[0][1] *= arg4->y * rx;
        temp[0][2] *= arg4->y * rx;
        temp[1][0] *= arg4->x * ry;
        temp[2][0] *= arg4->x * rz;
        temp[1][2] *= arg4->z * ry;
        temp[2][1] *= arg4->y * rz;
    }

    PSMTXConcat(temp, arg0, arg0);

    arg0[0][3] = arg3->x;
    arg0[1][3] = arg3->y;
    arg0[2][3] = arg3->z;
}

void HSD_MtxScaledAdd(Mtx arg0, Mtx arg1, Mtx arg2, f32 arg3)
{
    f32* arr0 = (f32*) &arg0[0][0];
    f32* arr1 = (f32*) &arg1[0][0];
    f32* arr2 = (f32*) &arg2[0][0];

    *(arr2)++ = __fmadds(arg3, *(arr0)++, *(arr1)++);
    *(arr2)++ = __fmadds(arg3, *(arr0)++, *(arr1)++);
    *(arr2)++ = __fmadds(arg3, *(arr0)++, *(arr1)++);
    *(arr2)++ = __fmadds(arg3, *(arr0)++, *(arr1)++);

    *(arr2)++ = __fmadds(arg3, *(arr0)++, *(arr1)++);
    *(arr2)++ = __fmadds(arg3, *(arr0)++, *(arr1)++);
    *(arr2)++ = __fmadds(arg3, *(arr0)++, *(arr1)++);
    *(arr2)++ = __fmadds(arg3, *(arr0)++, *(arr1)++);

    *(arr2)++ = __fmadds(arg3, *(arr0)++, *(arr1)++);
    *(arr2)++ = __fmadds(arg3, *(arr0)++, *(arr1)++);
    *(arr2)++ = __fmadds(arg3, *(arr0)++, *(arr1)++);
    *(arr2)++ = __fmadds(arg3, *(arr0)++, *(arr1)++);
}

void HSD_VecGetOrthogonal(Vec* v, Vec* out)
{
    Vec e;

    if (v->x <= v->y) {
        if (v->x <= v->z) {
            e.y = lbl_805E5C3C;
            e.x = lbl_805E5C38;
            e.z = lbl_805E5C3C;
            PSVECCrossProduct(&e, v, out);
        } else {
            e.x = lbl_805E5C3C;
            e.y = lbl_805E5C3C;
            e.z = lbl_805E5C38;
            PSVECCrossProduct(&e, v, out);
        }
    } else {
        if (v->y <= v->z) {
            e.x = lbl_805E5C3C;
            e.y = lbl_805E5C38;
            e.z = lbl_805E5C3C;
            PSVECCrossProduct(&e, v, out);
        } else {
            e.x = lbl_805E5C3C;
            e.y = lbl_805E5C3C;
            e.z = lbl_805E5C38;
            PSVECCrossProduct(&e, v, out);
        }
    }
}

Vec* HSD_VecAlloc(void)
{
    Vec* vec = HSD_ObjAlloc(&lbl_8058BBB8);
    assert_line_named(0x3CF, vec, lbl_805DCC48);
    return vec;
}

void HSD_VecFree(Vec* arg0)
{
    if (arg0 != NULL) {
        HSD_ObjFree(&lbl_8058BBB8, arg0);
    }
}

void* HSD_MtxAlloc(void)
{
    void* mtx;

    mtx = HSD_ObjAlloc(&lbl_8058BBE4);
    assert_line_named(0x3EE, mtx, lbl_805DCC4C);
    return mtx;
}

void HSD_MtxFree(void* arg0)
{
    if (arg0 != NULL) {
        HSD_ObjFree(&lbl_8058BBE4, arg0);
    }
}

HSD_ObjAllocData* HSD_VecGetAllocData(void)
{
    return &lbl_8058BBB8;
}

void HSD_VecInitAllocData(void)
{
    HSD_ObjAllocInit(&lbl_8058BBB8, 0xC, 4);
}

HSD_ObjAllocData* HSD_MtxGetAllocData(void)
{
    return &lbl_8058BBE4;
}

void HSD_MtxInitAllocData(void)
{
    HSD_ObjAllocInit(&lbl_8058BBE4, 0x30, 4);
}
