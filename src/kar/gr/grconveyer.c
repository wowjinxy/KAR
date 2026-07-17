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

extern void* kar_gryaku_current_ground;
extern f32 kar_lbcolanim__near_8006bac8(HSD_Spline* spline, Vec* pos,
                                        s32 flag);
extern void kar_lbcolanim__near_8006b048(Vec* out, HSD_Spline* spline);

#define LOAD_PTR(base, offset) (*(void**) ((u8*) (base) + (offset)))
#define LOAD_S32(base, offset) (*(s32*) ((u8*) (base) + (offset)))
#define LOAD_U32(base, offset) (*(u32*) ((u8*) (base) + (offset)))
#define LOAD_U8(base, offset) (*(u8*) ((u8*) (base) + (offset)))
#define STORE_S32(base, offset, value) \
    (*(s32*) ((u8*) (base) + (offset)) = (value))
#define FACE_AT(faces, index) ((u8*) (faces) + ((index) * 0x40))
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
    void* ground = kar_gryaku_current_ground;
    void* data = LOAD_PTR(ground, 0x8);
    void* spline_data = LOAD_PTR(LOAD_PTR(data, 0x1C), 0x10);
    u8* face = FACE_AT(LOAD_PTR(gcp, 0x8), face_id);
    void* face_data = LOAD_PTR(face, 0x38);
    GrConveyerParam* param = LOAD_PTR(face_data, 0x90);
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

    if (LOAD_U8(face, 0x3C) & 0x80) {
        __assert(assert_data->grcoll_src, 0xDD, assert_data->face_assert);
    }

    spline = ((HSD_Spline**) LOAD_PTR(LOAD_PTR(spline_data, 0x0), 0x0))[param->index];
    if (spline == NULL) {
        __assert(assert_data->src, 0x7E, assert_data->spline_assert);
    }

    kar_lbcolanim__near_8006bac8(spline, pos, LOAD_U8(spline_data, 0x4) >> 7);
    kar_lbcolanim__near_8006b048(&tangent, spline);

    VEC_CROSS(&side, (Vec*) (face + 0xC), &tangent);
    kar_lbvector_normalize_with_axis_fallback(&side, &side);
    VEC_CROSS(&tangent, &side, (Vec*) (face + 0xC));
    kar_lbvector_normalize_with_axis_fallback(&tangent, &tangent);

    dir_index = (LOAD_U32(face, 0x34) >> 6) & 0xF;
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
    void* ground = kar_gryaku_current_ground;
    u8* face = FACE_AT(LOAD_PTR(ground, 0x5C), face_id);
    void* face_data = LOAD_PTR(face, 0x38);
    s32 type = LOAD_S32(face_data, 0x8C);
    GrConveyerDataStrings* assert_data = &kar_src_grconveyer_804a4bc0;
    GrConveyerParam* param;
    Vec origin;
    Vec axis_a;
    Vec axis_b;
    Vec delta;
    s32 dir_index;
    s32 side_bits;

    if (((LOAD_U32(face, 0x34) >> 6) & 0xF) == 0) {
        return 0.0f;
    }

    if (type == 2) {
        return kar_grconveyer__800e8000((u8*) ground + 0x54, pos, face_id, out);
    }

    if (type < 2 && type >= 1) {
        if (LOAD_PTR(LOAD_PTR(LOAD_PTR(ground, 0x8), 0x20), 0x14) == NULL) {
            return 0.0f;
        }

        param = LOAD_PTR(face_data, 0x90);
        kar_grcommon_get_conveyerpos_vectors_by_index(param->index, &origin,
                                                      &axis_a, &axis_b);
        VEC_SUB(&delta, pos, &origin);
        VEC_CROSS(out, &delta, &axis_b);
        kar_lbvector_normalize_with_axis_fallback(out, out);

        dir_index = (LOAD_U32(face, 0x34) >> 6) & 0xF;
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
    u8* work = (u8*) ground + 0x210;
    s32 i;

    for (i = 0; i < 8; i++) {
        STORE_S32(work, 0x0, 0);
        STORE_S32(work, 0x4, -1);
        STORE_S32(work, 0x8, 0);
        STORE_S32(work, 0xC, 0);
        STORE_S32(work, 0x10, 0);
        STORE_S32(work, 0x14, 0);
        STORE_S32(work, 0x18, 0);
        STORE_S32(work, 0x1C, 0);
        STORE_S32(work, 0x20, 0);
        STORE_S32(work, 0x24, 0);
        STORE_S32(work, 0x28, 0);
        STORE_S32(work, 0x2C, 0);
        STORE_S32(work, 0x30, 0);
        STORE_S32(work, 0x34, 0);
        STORE_S32(work, 0x38, 0);
        STORE_S32(work, 0x3C, 0);
        STORE_S32(work, 0x40, 0);
        STORE_S32(work, 0x44, 0);
        work += 0x48;
    }

    STORE_S32(ground, 0x450, 0);
}
