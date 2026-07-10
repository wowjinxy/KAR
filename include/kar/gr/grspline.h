#ifndef __GRSPLINE_H_
#define __GRSPLINE_H_

#include <dolphin/types.h>

typedef struct Ground Ground;
typedef struct GroundSplineSets GroundSplineSets;

void kar_grspline_scale_all_spline_sets(GroundSplineSets* spline_sets, f32 scale);
void kar_grspline_init_course_range_splines(Ground* ground);
void kar_grspline_destroy_course_range_splines(Ground* ground);

#endif
