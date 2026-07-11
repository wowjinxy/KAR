#include "functions.h"
#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>
#include <kar/gr/gryaku.h>
#include <kar/gr/grspline.h>
#include <kar/lb/lbarchive.h>

#if defined(VERSION_GKYJ01)
#define lbl_805DF5C8 lbl_805D9FF0
#define lbl_805DF5D0 lbl_805D9FF8
#define lbl_805DF5D4 lbl_805D9FFC
#define lbl_805DF5D8 lbl_805DA000
#define lbl_805DF5DC lbl_805DA004
#define lbl_805DF5E0 lbl_805DA008
#define lbl_805DF5E4 lbl_805DA00C
#define lbl_80557638 lbl_805521A8
#define lbl_804A2408 lbl_8049D1A8
#define kar_course_dat_model_resource_table lbl_8049DD9C
#define kar_asset_grcity1event_804a329c lbl_8049E03C
#define lbl_804A32F4 lbl_8049E094
#define fn_80261CE8 fn_8025DA3C
#define fn_80261ECC fn_8025DC20
#define fn_80262574 fn_8025E2C8
#define kar_grcity1_patch_asset_material_anim_params fn_8010E28C
#define kar_grnullpos_scale_setup_position_data fn_800E4854
#define kar_lbspline__near_8006e664 fn_8006DD78
#define kar_lbkdcoll__near_80072c90 fn_800723A4
#define kar_efdata__near_802358c4 fn_80231850
#define kar_grgravity_calc_nearest_nullpos_gravity fn_800E5660
#elif defined(VERSION_GKYP01)
#define lbl_805DF5C8 lbl_805D2030
#define lbl_805DF5D0 lbl_805D2038
#define lbl_805DF5D4 lbl_805D203C
#define lbl_805DF5D8 lbl_805D2040
#define lbl_805DF5DC lbl_805D2044
#define lbl_805DF5E0 lbl_805D2048
#define lbl_805DF5E4 lbl_805D204C
#define lbl_80557638 lbl_80549FA0
#define lbl_804A2408 lbl_804A78A8
#define kar_course_dat_model_resource_table lbl_804A849C
#define kar_asset_grcity1event_804a329c lbl_804A873C
#define lbl_804A32F4 lbl_804A8794
#define fn_80261CE8 fn_802629A4
#define fn_80261ECC fn_80262B88
#define fn_80262574 fn_80263230
#define kar_grcity1_patch_asset_material_anim_params fn_80110F20
#define kar_grnullpos_scale_setup_position_data fn_800E7184
#define kar_lbspline__near_8006e664 fn_8006EFA4
#define kar_lbkdcoll__near_80072c90 fn_800735D0
#define kar_efdata__near_802358c4 fn_802365A0
#define kar_grgravity_calc_nearest_nullpos_gravity fn_800E7F90
#endif

typedef struct Ground Ground;
typedef struct GroundData GroundData;
typedef struct GroundDataExtra GroundDataExtra;
typedef struct GroundModelParam GroundModelParam;
typedef struct NullPosAll NullPosAll;
typedef struct NullPosData NullPosData;
typedef struct CourseSplineAll CourseSplineAll;
typedef struct CourseResource CourseResource;

struct Ground {
    u8 pad_0[0x08];
    GroundData* data;
};

struct GroundModelParam {
    u8 pad_00[0x04];
    f32 default_camera_scale;
    f32 stage_scale;
    f32 default_gravity;
    Vec default_gravity_dir;
    u8 pad_1C[0x44];
    f32 round_scale;
    Vec round_position;
    u8 pad_70[0x10];
    u8 flag_80;
    u8 flag_81;
};

struct GroundDataExtra {
    u8 pad_0[0x04];
    void* data;
};

struct NullPosData {
    u8 pad_0[0x10];
    void* position_data;
};

struct NullPosAll {
    NullPosData* data;
};

struct CourseSplineAll {
    void* spline;
};

struct GroundData {
    u8 initialized;
    u8 pad_01[0x03];
    GroundModelParam* model_param;
    u8 pad_08[0x04];
    NullPosAll* nullpos_all;
    u8 pad_10[0x04];
    GroundDataExtra* extra;
    u8 pad_18[0x04];
    GroundSplineSets* spline_sets;
    u8 pad_20[0x28];
    CourseSplineAll* course_spline;
};

struct CourseResource {
    char* data_file;
    char* data_symbol;
    char* model_file;
    char* model_symbol;
    char* model_motion_symbol;
};

const f32 lbl_805DF5C8[2] = { 1.0f, 0.0f };
const f32 lbl_805DF5D0 = 1.21f;
const f32 lbl_805DF5D4 = 0.00001f;
const f32 lbl_805DF5D8 = -0.00001f;
const f32 lbl_805DF5DC = 0.0f;
const f32 lbl_805DF5E0 = 1.0f;
const f32 lbl_805DF5E4 = 0.025f;

extern GroundData* lbl_80557638[];
extern u8 lbl_804A2408[];
extern CourseResource kar_course_dat_model_resource_table[];
extern char kar_asset_grcity1event_804a329c[];
extern char lbl_804A32F4[];

s32 fn_80261CE8(s32 arg0);
s32 fn_80261ECC(void);
s32 fn_80262574(s32 arg0);
void kar_grcity1_patch_asset_material_anim_params(GroundData* data);
void kar_grnullpos_scale_setup_position_data(void* data, f32 scale);
void kar_lbspline__near_8006e664(void* spline, f32 scale);
void kar_lbkdcoll__near_80072c90(s32 arg0, char* archive_name, s32 arg2, s32 arg3, s32 arg4,
                                 s32 arg5, s32 arg6, s32 arg7, s32 arg8);
void kar_efdata__near_802358c4(s32 kind);
f32 kar_grgravity_calc_nearest_nullpos_gravity(Ground* ground, Vec* pos, Vec* out);
f32 kar_grgravity_calc_nearest_spline_gravity(Ground* ground, Vec* pos, Vec* out);

#define LOAD_F32(sym) (*(volatile const f32*) &(sym))

void kar_grdata__800ce7a0(s32 kind)
{
    u8* base = lbl_804A2408;
    GroundData* data;
    GroundData** slot = &lbl_80557638[kind];

    if (*slot == NULL) {
        f32 scale;

        if (kind == 0x16) {
            *slot = (GroundData*) (base + 0x258);
        } else {
            CourseResource* resource = (CourseResource*) (base + 0xBF4);
            CourseResource* resource_for_symbol;
            char** model_file;

            resource_for_symbol = resource + kind;
            resource += kind;
            model_file = &resource->model_file;
            kar_lbarchive__80059a20(0, resource->data_file, slot,
                                    resource_for_symbol->data_symbol, 0);
            kar_lbarchive__80059a20(0, resource->model_file, &(*slot)->nullpos_all,
                                    resource->model_symbol, &(*slot)->pad_10,
                                    model_file[2], 0);
        }

        data = *slot;
        if (fn_80262574(fn_80261ECC()) != 0) {
            if (kind != 9) {
                __assert((char*) (base + 0xEC8), 0xAC, (char*) (base + 0xED4));
            }
            kar_grcity1_patch_asset_material_anim_params(data);
        }

        data = *slot;
        if (!data->initialized) {
            GroundModelParam* model_param = data->model_param;
            NullPosAll* nullpos_all;
            CourseSplineAll* course_spline;
            GroundSplineSets* spline_sets;

            data->initialized = TRUE;

            if (model_param != NULL) {
                scale = model_param->stage_scale;
            } else {
                scale = LOAD_F32(lbl_805DF5C8[0]);
            }

            nullpos_all = data->nullpos_all;
            course_spline = data->course_spline;
            spline_sets = data->spline_sets;
            if (nullpos_all != NULL) {
                kar_grnullpos_scale_setup_position_data(nullpos_all->data->position_data, scale);
            }

            kar_lbspline__near_8006e664(course_spline->spline, scale);
            kar_grspline_scale_all_spline_sets(spline_sets, scale);
        }
    }
}

void kar_gr_assets__asset_800ce924(void* out)
{
    kar_lbarchive__80059a20(0, kar_asset_grcity1event_804a329c, out, lbl_804A32F4, 0);
}

void kar_gr_assets__asset_800ce964(s32 arg0)
{
    s32 kind = fn_80261CE8(arg0);

    kar_lbkdcoll__near_80072c90(2, kar_course_dat_model_resource_table[kind].data_file, 4, 4, 0,
                                1, 8, 0x10, 0);
    kar_lbkdcoll__near_80072c90(2, kar_course_dat_model_resource_table[kind].model_file, 4, 4, 0,
                                1, 8, 0x10, 0);
    kar_efdata__near_802358c4(kind);
    if (fn_80262574(arg0) != 0) {
        kar_lbkdcoll__near_80072c90(2, kar_asset_grcity1event_804a329c, 4, 4, 0, 1, 8, 0x10, 0);
    }
}

void* kar_grdata__near_800cea5c(void)
{
    GroundDataExtra* extra = kar_gryaku_current_ground->data->extra;

    if (extra != NULL) {
        return extra->data;
    }

    return NULL;
}

f32 kar_grdata__near_800cea80(void)
{
    GroundModelParam* model_param = kar_gryaku_current_ground->data->model_param;

    if (model_param != NULL) {
        return model_param->default_camera_scale;
    }

    return LOAD_F32(lbl_805DF5D0);
}

u8 kar_grdata__near_800ceaa4(void)
{
    return kar_gryaku_current_ground->data->model_param->flag_81;
}

f32 kar_grdata__near_800ceab8(void)
{
    return kar_gryaku_current_ground->data->model_param->round_scale;
}

void kar_grdata__near_800ceacc(Vec* out)
{
    *out = kar_gryaku_current_ground->data->model_param->round_position;
}

u8 kar_grdata__near_800ceaf4(void)
{
    GroundModelParam* model_param = kar_gryaku_current_ground->data->model_param;

    if (model_param != NULL) {
        return model_param->flag_80;
    }

    return FALSE;
}

f32 kar_grdata__near_800ceb18(Vec* pos, Vec* out)
{
    GroundModelParam* model_param;
    Ground* ground;
    f32 gravity;
    s32 use_default;

    ground = kar_gryaku_current_ground;
    model_param = ground->data->model_param;
    gravity = kar_grgravity_calc_nearest_nullpos_gravity(ground, pos, out);
    if (gravity < LOAD_F32(lbl_805DF5D4) && gravity > LOAD_F32(lbl_805DF5D8)) {
        use_default = TRUE;
    } else {
        use_default = FALSE;
    }

    switch (use_default) {
    case FALSE:
        goto done;
    default:
        break;
    }

    gravity = kar_grgravity_calc_nearest_spline_gravity(ground, pos, out);
    if (gravity < LOAD_F32(lbl_805DF5D4) && gravity > LOAD_F32(lbl_805DF5D8)) {
        use_default = TRUE;
    } else {
        use_default = FALSE;
    }

    switch (use_default) {
    case FALSE:
        goto done;
    default:
        break;
    }

    if (model_param != NULL) {
        *out = model_param->default_gravity_dir;
        gravity = model_param->default_gravity;
    } else {
        f32 zero = LOAD_F32(lbl_805DF5DC);
        f32 one = LOAD_F32(lbl_805DF5E0);

        out->x = zero;
        gravity = LOAD_F32(lbl_805DF5E4);
        out->y = one;
        out->z = zero;
    }

done:
    return gravity;
}
