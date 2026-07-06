#ifndef _spline_h_
#define _spline_h_

#include <global.h>

#include <sysdolphin/forward.h>

#include <dolphin/types.h>
#include <dolphin/mtx/mtxtypes.h>

struct _HSD_Spline {
    /*  +0 */ u8 type;
    /*  +2 */ s16 numcv;
    /*  +4 */ f32 tension;
    /*  +8 */ Vec* cv;
    /*  +C */ f32 totalLength;
    /* +10 */ f32* segLength;
    /* +14 */ f32 (*segPoly)[5];
};

f32 splGetHelmite(f32 fterm, f32 time, f32 p0, f32 p1, f32 d0, f32 d1);
void splGetCardinalPoint(Vec* p, Vec* cp, f32 u);
void splGetSplinePoint(Vec* p, HSD_Spline* spline, f32 u);
f32 splArcLength(const f32 coeffs[5], f32 start, f32 end);
f32 splArcLengthGetParameter(HSD_Spline* spl, f32 arg1);
void splArcLengthPoint(Vec* vec, HSD_Spline* spline, f32 param);

#endif
