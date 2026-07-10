#include <kar/gr/grspline.h>
#include <sysdolphin/forward.h>

typedef struct SplineList SplineList;
typedef struct SplineSet SplineSet;
typedef struct SplinePair SplinePair;
typedef struct SplinePairList SplinePairList;

struct SplineList {
    HSD_Spline** splines;
    s32 count;
};

struct SplineSet {
    SplineList* list;
};

struct SplinePair {
    HSD_Spline* spline0;
    HSD_Spline* spline1;
    u8 pad_08[0x10];
};

struct SplinePairList {
    SplinePair* pairs;
    s32 count;
};

struct GroundSplineSets {
    SplineSet* course;
    SplinePairList* pairs;
    SplineSet* gravity;
    SplineSet* airflow;
    SplineSet* conveyer;
    SplineList* item;
    SplineList* vehicle;
};

void kar_lbspline__near_8006c66c(HSD_Spline* spline, f32 scale);
void kar_grcoursespline_init(Ground* ground);
void kar_grcoursespline_destroy(Ground* ground);
void kar_grrangespline_init(Ground* ground);
void kar_grrangespline_destroy(Ground* ground);

void kar_grspline_scale_all_spline_sets(GroundSplineSets* spline_sets, f32 scale)
{
    SplineSet* set;
    SplineList* list;
    SplinePairList* pairs;
    SplinePair* pair;
    s32 offset;
    s32 i;

    set = spline_sets->course;
    if (set != NULL) {
        i = 0;
        list = set->list;
        offset = i;
        while (i < list->count) {
            kar_lbspline__near_8006c66c(*(HSD_Spline**) ((u8*) list->splines + offset), scale);
            offset += sizeof(HSD_Spline*);
            i++;
        }
    }

    pairs = spline_sets->pairs;
    if (pairs != NULL) {
        i = 0;
        offset = 0;
        while (i < pairs->count) {
            pair = (SplinePair*) ((u8*) pairs->pairs + offset);
            kar_lbspline__near_8006c66c(pair->spline0, scale);
            kar_lbspline__near_8006c66c(pair->spline1, scale);
            offset += sizeof(SplinePair);
            i++;
        }
    }

    set = spline_sets->gravity;
    if (set != NULL) {
        i = 0;
        list = set->list;
        offset = i;
        while (i < list->count) {
            kar_lbspline__near_8006c66c(*(HSD_Spline**) ((u8*) list->splines + offset), scale);
            offset += sizeof(HSD_Spline*);
            i++;
        }
    }

    set = spline_sets->airflow;
    if (set != NULL) {
        i = 0;
        list = set->list;
        offset = i;
        while (i < list->count) {
            kar_lbspline__near_8006c66c(*(HSD_Spline**) ((u8*) list->splines + offset), scale);
            offset += sizeof(HSD_Spline*);
            i++;
        }
    }

    set = spline_sets->conveyer;
    if (set != NULL) {
        i = 0;
        list = set->list;
        offset = i;
        while (i < list->count) {
            kar_lbspline__near_8006c66c(*(HSD_Spline**) ((u8*) list->splines + offset), scale);
            offset += sizeof(HSD_Spline*);
            i++;
        }
    }

    list = spline_sets->item;
    if (list != NULL) {
        i = 0;
        offset = i;
        while (i < list->count) {
            kar_lbspline__near_8006c66c(*(HSD_Spline**) ((u8*) list->splines + offset), scale);
            offset += sizeof(HSD_Spline*);
            i++;
        }
    }

    list = spline_sets->vehicle;
    if (list != NULL) {
        i = 0;
        offset = i;
        while (i < list->count) {
            kar_lbspline__near_8006c66c(*(HSD_Spline**) ((u8*) list->splines + offset), scale);
            offset += sizeof(HSD_Spline*);
            i++;
        }
    }
}

void kar_grspline_init_course_range_splines(Ground* ground)
{
    kar_grcoursespline_init(ground);
    kar_grrangespline_init(ground);
}

void kar_grspline_destroy_course_range_splines(Ground* ground)
{
    kar_grcoursespline_destroy(ground);
    kar_grrangespline_destroy(ground);
}
