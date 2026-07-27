#include "functions.h"
#include <dolphin/mtx/vec.h>
#include <kar/gr/grcommon.h>
#include <kar/gr/grconveyer.h>
#include <kar/lb/lbvector.h>
#include <sysdolphin/spline.h>

typedef struct GrConveyerDataStrings {
    char src[0x10];
    char bitfield_assert[0x38];
    char left_right_assert[0x80];
    char left_right_assert_no_space[0x74];
    char grcoll_src[0xC];
    char face_assert[0x20];
    char spline_assert[0xC];
    char left_right_assert_spaced[0x74];
    char front_back_assert[0x78];
} GrConveyerDataStrings;

typedef struct GrConveyerParam {
    f32 unk0;
    f32 unk4;
    s32 index;
} GrConveyerParam;

typedef struct GroundData GroundData;
typedef struct GroundSplineRoot GroundSplineRoot;
typedef struct GroundConveyerInfo GroundConveyerInfo;
typedef struct GrConveyerSplineData GrConveyerSplineData;
typedef struct GrConveyerSplineList GrConveyerSplineList;
typedef struct GrConveyerFace GrConveyerFace;
typedef struct GrConveyerFaceData GrConveyerFaceData;
typedef struct GrConveyerCollision GrConveyerCollision;
typedef struct GrConveyerWork GrConveyerWork;

struct GroundData {
    u8 pad_00[0x1C];
    GroundSplineRoot* spline_root;
    GroundConveyerInfo* conveyer_info;
};

struct GroundSplineRoot {
    u8 pad_00[0x10];
    GrConveyerSplineData* spline_data;
};

struct GroundConveyerInfo {
    u8 pad_00[0x14];
    void* vectors;
};

struct GrConveyerSplineList {
    HSD_Spline** splines;
};

struct GrConveyerSplineData {
    GrConveyerSplineList* list;
    u8 flags;
};

struct GrConveyerFaceData {
    u8 pad_00[0x8C];
    s32 type;
    GrConveyerParam* param;
};

struct GrConveyerFace {
    u8 pad_00[0x0C];
    Vec normal;
    u8 pad_18[0x1C];
    u32 flags;
    GrConveyerFaceData* data;
    u8 status;
    u8 pad_3D[0x03];
};

struct GrConveyerCollision {
    u8 pad_00[0x08];
    GrConveyerFace* faces;
};

struct GrConveyerWork {
    s32 values[18];
};

struct Ground {
    u8 pad_000[0x08];
    GroundData* data;
    u8 pad_00C[0x48];
    GrConveyerCollision collision;
    u8 pad_060[0x1B0];
    GrConveyerWork conveyer_work[8];
    s32 conveyer_work_count;
};

extern Ground* kar_gryaku_current_ground;
extern f32 kar_lbcolanim__near_8006bac8(HSD_Spline* spline, Vec* pos,
                                        s32 flag);
extern void kar_lbcolanim__near_8006b048(Vec* out, HSD_Spline* spline);

#define VEC_ZERO(vec)                   \
    do {                                \
        (vec)->x = 0.0f;                \
        (vec)->y = 0.0f;                \
        (vec)->z = 0.0f;                \
    } while (0)
#define VEC_SCALE(vec, scale)           \
    do {                                \
        (vec)->x *= (scale);            \
        (vec)->y *= (scale);            \
        (vec)->z *= (scale);            \
    } while (0)
#define VEC_ADD(out, lhs, rhs)          \
    do {                                \
        (out)->x = (lhs)->x + (rhs)->x; \
        (out)->y = (lhs)->y + (rhs)->y; \
        (out)->z = (lhs)->z + (rhs)->z; \
    } while (0)
#define VEC_SUB(out, lhs, rhs)          \
    do {                                \
        (out)->x = (lhs)->x - (rhs)->x; \
        (out)->y = (lhs)->y - (rhs)->y; \
        (out)->z = (lhs)->z - (rhs)->z; \
    } while (0)
#define VEC_CROSS(out, lhs, rhs)                                      \
    do {                                                              \
        (out)->x = ((lhs)->y * (rhs)->z) - ((lhs)->z * (rhs)->y);      \
        (out)->y = ((lhs)->z * (rhs)->x) - ((lhs)->x * (rhs)->z);      \
        (out)->z = ((lhs)->x * (rhs)->y) - ((lhs)->y * (rhs)->x);      \
    } while (0)

GrConveyerDataStrings kar_src_grconveyer_804a4bc0 = {
    "grconveyer.c",
    "0 < bitField && bitField <= GrConveyorDebug_BitFieldMax",
    "(dirIndex & (GrCFF_ConveyerDirLeft | GrCFF_ConveyerDirRight)) == GrCFF_ConveyerDirLeft || dirIndex == GrCFF_ConveyerDirRight",
    "(dirIndex & (GrCFF_ConveyerDirLeft | GrCFF_ConveyerDirRight))!= (GrCFF_ConveyerDirLeft | GrCFF_ConveyerDirRight)",
    "grcoll.h",
    "!grCollChkFaceIllegal(gcp, id)",
    "sp != NULL",
    "(dirIndex & (GrCFF_ConveyerDirLeft | GrCFF_ConveyerDirRight)) != (GrCFF_ConveyerDirLeft | GrCFF_ConveyerDirRight)",
    "(dirIndex & (GrCFF_ConveyerDirFront | GrCFF_ConveyerDirBack)) != (GrCFF_ConveyerDirFront | GrCFF_ConveyerDirBack)",
};

f32 lbl_804A4E20[48] = {
    3.0f, 3.0f, 3.0f, 3.0f,
    3.0f, 3.0f, 3.0f, 3.0f,
    3.0f, 3.0f, 3.0f, 3.0f,
    3.0f, 3.0f, 3.0f, 3.0f,
    3.0f, 3.0f, 3.0f, 3.0f,
    3.0f, 3.0f, 3.0f, 3.0f,
    3.0f, 3.0f, 3.0f, 3.0f,
    3.0f, 3.0f, 3.0f, 3.0f,
    3.0f, 3.0f, 3.0f, 3.0f,
    3.0f, 3.0f, 3.0f, 3.0f,
    3.0f, 3.0f, 3.0f, 3.0f,
    3.0f, 3.0f, 3.0f,
};

__declspec(section ".sdata2") const f32 lbl_805DF750 = -1.0f;
__declspec(section ".sdata2") const f32 lbl_805DF754 = 0.0f;

f32 kar_grconveyer__800e8000(void* gcp, Vec* pos, s32 face_id, Vec* out)
{
    Ground* ground = kar_gryaku_current_ground;
    GroundData* data = ground->data;
    GrConveyerSplineData* spline_data = data->spline_root->spline_data;
    GrConveyerCollision* collision = gcp;
    GrConveyerFace* face = &collision->faces[face_id];
    GrConveyerFaceData* face_data = face->data;
    GrConveyerParam* param = face_data->param;
    GrConveyerDataStrings* assert_data = &kar_src_grconveyer_804a4bc0;
    HSD_Spline* spline;
    Vec tangent;
    Vec side;
    s32 dir_index;
    s32 side_bits;
    s32 forward_bits;
    f32 mag;

    if (spline_data == NULL) {
        return 0.0f;
    }

    if (face->status & 0x80) {
        __assert(assert_data->grcoll_src, 0xDD, assert_data->face_assert);
    }

    spline = spline_data->list->splines[param->index];
    if (spline == NULL) {
        __assert(assert_data->src, 0x7E, assert_data->spline_assert);
    }

    kar_lbcolanim__near_8006bac8(spline, pos, spline_data->flags >> 7);
    kar_lbcolanim__near_8006b048(&tangent, spline);

    VEC_CROSS(&side, &face->normal, &tangent);
    kar_lbvector_normalize_with_axis_fallback(&side, &side);
    VEC_CROSS(&tangent, &side, &face->normal);
    kar_lbvector_normalize_with_axis_fallback(&tangent, &tangent);

    dir_index = (face->flags >> 6) & 0xF;
    side_bits = dir_index & 0xC;
    if (side_bits == 0xC) {
        __assert(assert_data->src, 0x95, assert_data->left_right_assert_spaced);
    }

    forward_bits = dir_index & 0x3;
    if (forward_bits == 0x3) {
        __assert(assert_data->src, 0x96, assert_data->front_back_assert);
    }

    if (side_bits != 0) {
        if (dir_index & 0x8) {
            VEC_SCALE(&side, -1.0f);
        }
        VEC_SCALE(&side, param->unk4);
    } else {
        VEC_ZERO(&side);
    }

    if (forward_bits != 0) {
        if (dir_index & 0x2) {
            VEC_SCALE(&tangent, -1.0f);
        }
        VEC_SCALE(&tangent, param->unk0);
    } else {
        VEC_ZERO(&tangent);
    }

    VEC_ADD(out, &side, &tangent);
    mag = PSVECMag(out);
    kar_lbvector_normalize_with_axis_fallback(out, out);
    return mag;
}

f32 kar_grconveyer__800e8338(Vec* pos, s32 face_id, Vec* out)
{
    Ground* ground = kar_gryaku_current_ground;
    GrConveyerFace* face = &ground->collision.faces[face_id];
    GrConveyerFaceData* face_data = face->data;
    s32 type = face_data->type;
    GrConveyerDataStrings* assert_data = &kar_src_grconveyer_804a4bc0;
    GrConveyerParam* param;
    Vec origin;
    Vec axis_a;
    Vec axis_b;
    Vec delta;
    s32 dir_index;
    s32 side_bits;

    if (((face->flags >> 6) & 0xF) == 0) {
        return 0.0f;
    }

    if (type == 2) {
        return kar_grconveyer__800e8000(&ground->collision, pos, face_id, out);
    }

    if (type < 2 && type >= 1) {
        if (ground->data->conveyer_info->vectors == NULL) {
            return 0.0f;
        }

        param = face_data->param;
        kar_grcommon_get_conveyerpos_vectors_by_index(param->index, &origin,
                                                      &axis_a, &axis_b);
        VEC_SUB(&delta, pos, &origin);
        VEC_CROSS(out, &delta, &axis_b);
        kar_lbvector_normalize_with_axis_fallback(out, out);

        dir_index = (face->flags >> 6) & 0xF;
        side_bits = dir_index & 0xC;
        if (side_bits != 0x4 && dir_index != 0x8) {
            __assert(assert_data->src, 0x4E, assert_data->left_right_assert);
        }

        if (side_bits == 0xC) {
            __assert(assert_data->src, 0x4F,
                     assert_data->left_right_assert_no_space);
        }

        if (dir_index == 0x4) {
            VEC_SCALE(out, -1.0f);
        }

        return PSVECMag(&axis_a) * (param->unk0 / param->unk4);
    }

    return 0.0f;
}

void kar_grconveyer__near_800e853c(Ground* ground)
{
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        ground->conveyer_work[i].values[0] = 0;
        ground->conveyer_work[i].values[1] = -1;
        for (j = 2; j < 18; j++) {
            ground->conveyer_work[i].values[j] = 0;
        }
    }

    ground->conveyer_work_count = 0;
}
