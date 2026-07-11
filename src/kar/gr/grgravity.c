#include "functions.h"
#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/mtx/vec.h>
#include <dolphin/types.h>

typedef struct Ground Ground;
typedef struct GroundData GroundData;
typedef struct GravityParams GravityParams;
typedef struct GravitySplineSet GravitySplineSet;
typedef struct SplineList SplineList;
typedef struct HSD_Spline HSD_Spline;

#if defined(VERSION_GKYJ01)
#define GRGRAVITY_ASSERT_TMP_PARAM_LINE 0x65
#define GRGRAVITY_INIT_DIST lbl_805D7304
#define GRGRAVITY_ZERO lbl_805DA150
#define GRGRAVITY_NO_PARAM lbl_805DA154
#define GRGRAVITY_ONE_ZERO lbl_805DA158
#elif defined(VERSION_GKYP01)
#define GRGRAVITY_ASSERT_TMP_PARAM_LINE 0x73
#define GRGRAVITY_INIT_DIST lbl_805CF26C
#define GRGRAVITY_ZERO lbl_805D2190
#define GRGRAVITY_NO_PARAM lbl_805D2194
#define GRGRAVITY_ONE_ZERO lbl_805D2198
#else
#define GRGRAVITY_ASSERT_TMP_PARAM_LINE 0x65
#define GRGRAVITY_INIT_DIST lbl_805DC8BC
#define GRGRAVITY_ZERO lbl_805DF728
#define GRGRAVITY_NO_PARAM lbl_805DF72C
#define GRGRAVITY_ONE_ZERO lbl_805DF730
#endif

struct Ground {
    u8 pad_0[0x08];
    GroundData* data;
};

struct GroundData {
    u8 pad_00[0x04];
    GravityParams* gravity_params;
    u8 pad_08[0x14];
    GravitySplineSet** spline_sets;
};

struct GravityParams {
    u8 pad_00[0x74];
    f32* spline_params;
};

struct SplineList {
    HSD_Spline** splines;
    s32 count;
};

struct GravitySplineSet {
    SplineList* list;
    u8 flags;
};

char kar_src_grgravity_804a4a60[] = "grgravity.c";
char lbl_804A4A6C[] = "tmpParam != -1.0F";

#if defined(VERSION_GKYJ01)
const f32 lbl_805DA158[2] = { 1.0f, 0.0f };

extern const f32 lbl_805D7304[];
extern const f32 lbl_805DA150;
extern const f32 lbl_805DA154;
#elif defined(VERSION_GKYP01)
const f32 lbl_805D2198[2] = { 1.0f, 0.0f };

extern const f32 lbl_805CF26C[];
extern const f32 lbl_805D2190;
extern const f32 lbl_805D2194;
#else
const f32 lbl_805DF730[2] = { 1.0f, 0.0f };

extern const f32 lbl_805DC8BC[];
extern const f32 lbl_805DF728;
extern const f32 lbl_805DF72C;
#endif

void* memcpy(void* dst, const void* src, unsigned long n);
f32 kar_lbcolanim__near_8006bac8(HSD_Spline* spline, Vec* pos, s32 arg2);
void splArcLengthPoint(Vec* out, HSD_Spline* spline, f32 param);
void kar_lbvector_normalize_with_axis_fallback(Vec* dst, Vec* src);

#define GET_U8(base, offset) (*(u8*) ((u8*) (base) + (offset)))
#define GET_S32(base, offset) (*(s32*) ((u8*) (base) + (offset)))
#define GET_PTR(base, offset) (*(void**) ((u8*) (base) + (offset)))
#define GET_F32(base, offset) (*(f32*) ((u8*) (base) + (offset)))
#define LOAD_F32(sym) (*(volatile const f32*) &(sym))

f32 kar_grgravity_calc_nearest_spline_gravity(Ground* ground, Vec* pos,
                                              Vec* out)
{
    GroundData* data = ground->data;
    GravitySplineSet* spline_set = data->spline_sets[2];
    GravityParams* gravity_params;
    Vec nearest_pos;
    Vec spline_pos;
    f32 nearest_dist;
    f32 zero;
    f32 no_param;
    s32 spline_offset;
    s32 param_offset;
    s32 best_index;
    s32 i;

    if (spline_set != NULL) {
        spline_offset = 0;
        gravity_params = data->gravity_params;
        param_offset = spline_offset;
        nearest_dist = GRGRAVITY_INIT_DIST[0];
        best_index = -1;
        no_param = GRGRAVITY_NO_PARAM;
        i = 0;
        zero = GRGRAVITY_ZERO;
        while (i < spline_set->list->count) {
            HSD_Spline* spline =
                GET_PTR(spline_set->list->splines, spline_offset);
            f32 spline_param =
                kar_lbcolanim__near_8006bac8(spline, pos,
                                             (spline_set->flags >> 7) &
                                                 1);

            if (no_param == spline_param) {
                __assert(kar_src_grgravity_804a4a60,
                         GRGRAVITY_ASSERT_TMP_PARAM_LINE, lbl_804A4A6C);
            }

            if (spline_param > zero &&
                spline_param < LOAD_F32(GRGRAVITY_ONE_ZERO[0])) {
                f32 dist;

                splArcLengthPoint(&spline_pos, spline, spline_param);
                dist = PSVECDistance(pos, &spline_pos);
                if (dist < GET_F32(gravity_params->spline_params, param_offset) &&
                    dist < nearest_dist) {
                    memcpy(&nearest_pos, &spline_pos, sizeof(Vec));
                    nearest_dist = dist;
                    best_index = i;
                }
            }

            spline_offset += 4;
            param_offset += 0xC;
            i++;
        }

        if (best_index >= 0) {
            f32* selected_params;
            f32 gravity;
            f32 min_gravity;
            f32 max_gravity;
            f32 radius;

            selected_params = gravity_params->spline_params + best_index * 3;
            zero = GRGRAVITY_ZERO;
            out->x = pos->x - nearest_pos.x;
            out->y = pos->y - nearest_pos.y;
            out->z = pos->z - nearest_pos.z;

            radius = selected_params[0];
            min_gravity = selected_params[1];
            max_gravity = selected_params[2];
            gravity = nearest_dist * ((max_gravity - min_gravity) / radius) +
                      min_gravity;

            if (gravity < zero) {
                f32 neg_one = GRGRAVITY_NO_PARAM;

                gravity = -gravity;
                out->x *= neg_one;
                out->y *= neg_one;
                out->z *= neg_one;
            }

            kar_lbvector_normalize_with_axis_fallback(out, out);
            return gravity;
        }
    }

    return GRGRAVITY_ZERO;
}
