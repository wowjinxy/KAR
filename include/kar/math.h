#ifndef _KAR_MATH_H_
#define _KAR_MATH_H_

#include <dolphin/types.h>

f64 kar_asin(f64 x);
f64 kar_acos(f64 x);
f64 kar_atan(f64 x);
f64 kar_atan2(f64 y, f64 x);
f64 kar_exp(f64 x);
f64 kar_fmod(f64 x, f64 y);
f64 kar_log(f64 x);
f64 kar_pow(f64 x, f64 y);
f64 tan(f64 x);
f64 __frsqrte(f64 x);
f64 __fnmsub(f64 a, f64 c, f64 b);
f32 __fmadds(f32 a, f32 c, f32 b);
f32 __fmsubs(f32 a, f32 c, f32 b);
f32 __fnmsubs(f32 a, f32 c, f32 b);

#endif
