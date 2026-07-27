#include "functions.h"
#include <dolphin/mtx/mtx.h>
#include <dolphin/types.h>
#include <kar/em/emanim.h>
#include <kar/em/emcamera.h>
#include <kar/lb/lbvector.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/random.h>

#if defined(VERSION_GKYJ01)
#define lbl_804B2AD0 lbl_804AD818
#define kar_src_emcamera_804b2af8 lbl_804AD840
#define lbl_804B2B08 lbl_804AD850
#define lbl_805D715C lbl_805D1B9C
#define lbl_805E236C lbl_805DCC0C
#define lbl_805E2370 lbl_805DCC10
#define lbl_805E2374 lbl_805DCC14
#define lbl_805E2378 lbl_805DCC18
#define lbl_805E2380 lbl_805DCC20
#define lbl_805E2384 lbl_805DCC24
#define lbl_805E2388 lbl_805DCC28
#define lbl_805E2390 lbl_805DCC30
#define lbl_805E2398 lbl_805DCC38
#define lbl_805E23A0 lbl_805DCC40
#define lbl_805E23A8 lbl_805DCC48
#define lbl_805E23AC lbl_805DCC4C
#define lbl_805E23B0 lbl_805DCC50
#define lbl_805E23B4 lbl_805DCC54
#define lbl_805E23B8 lbl_805DCC58
#define lbl_805E23BC lbl_805DCC5C
#define lbl_805E23C0 lbl_805DCC60
#define lbl_805E23C8 lbl_805DCC68
#define lbl_805E23D0 lbl_805DCC70
#define lbl_805E23D4 lbl_805DCC74
#define lbl_805E23D8 lbl_805DCC78
#define lbl_805E23DC lbl_805DCC7C
#define lbl_805E23E0 lbl_805DCC80
#define lbl_805E23E4 lbl_805DCC84
#define lbl_805E23E8 lbl_805DCC88
#define lbl_805E23EC lbl_805DCC8C
#define lbl_805E23F0 lbl_805DCC90
#define lbl_805E23F4 lbl_805DCC94
#define lbl_805E23F8 lbl_805DCC98
#define fn_801FD0E0 fn_801F93D0
#define fn_801FD6B0 fn_801F99A0
#elif defined(VERSION_GKYP01)
#define lbl_804B2AD0 lbl_804B82C0
#define kar_src_emcamera_804b2af8 lbl_804B82E8
#define lbl_804B2B08 lbl_804B82F8
#define lbl_805D715C lbl_805C9B44
#define lbl_805E236C lbl_805D4E04
#define lbl_805E2370 lbl_805D4E08
#define lbl_805E2374 lbl_805D4E0C
#define lbl_805E2378 lbl_805D4E10
#define lbl_805E2380 lbl_805D4E18
#define lbl_805E2384 lbl_805D4E1C
#define lbl_805E2388 lbl_805D4E20
#define lbl_805E2390 lbl_805D4E28
#define lbl_805E2398 lbl_805D4E30
#define lbl_805E23A0 lbl_805D4E38
#define lbl_805E23A8 lbl_805D4E40
#define lbl_805E23AC lbl_805D4E44
#define lbl_805E23B0 lbl_805D4E48
#define lbl_805E23B4 lbl_805D4E4C
#define lbl_805E23B8 lbl_805D4E50
#define lbl_805E23BC lbl_805D4E54
#define lbl_805E23C0 lbl_805D4E58
#define lbl_805E23C8 lbl_805D4E60
#define lbl_805E23D0 lbl_805D4E68
#define lbl_805E23D4 lbl_805D4E6C
#define lbl_805E23D8 lbl_805D4E70
#define lbl_805E23DC lbl_805D4E74
#define lbl_805E23E0 lbl_805D4E78
#define lbl_805E23E4 lbl_805D4E7C
#define lbl_805E23E8 lbl_805D4E80
#define lbl_805E23EC lbl_805D4E84
#define lbl_805E23F0 lbl_805D4E88
#define lbl_805E23F4 lbl_805D4E8C
#define lbl_805E23F8 lbl_805D4E90
#define fn_801FD0E0 fn_801FDDB4
#define fn_801FD6B0 fn_801FE37C
#endif

typedef struct EmCameraFloatState {
    u8 pad_00[0x0C];
    f32 value;
} EmCameraFloatState;

typedef struct EmCameraTemplateSource {
    EmCameraFloatState* state;
} EmCameraTemplateSource;

typedef struct EmCameraSpline {
    u8 pad_00[0x0C];
    f32 length;
} EmCameraSpline;

typedef struct EmCameraFlagsByte {
    u8 flag_80 : 1;
    u8 flag_40 : 1;
    u8 flag_20 : 1;
    u8 flag_10 : 1;
    u8 flag_08 : 1;
    u8 flag_04 : 1;
    u8 flag_02 : 1;
    u8 flag_01 : 1;
} EmCameraFlagsByte;

struct EmAnim {
    HSD_GObj* gobj;
    u8 pad_004[0x10];
    EmCameraTemplateSource* field_014;
    u8 pad_018[0x2C8];
    Vec velocity;
    Vec pos;
    Vec camera_pos;
    u8 pad_304[0x30];
    Vec forward;
    Vec right;
    u8 pad_34C[0x44];
    f32 speed_min;
    f32 speed_mid;
    f32 speed_random;
    f32 speed_max;
    u8 pad_3A0[0x04];
    f32 velocity_scale;
    u8 pad_3A8[0x1C];
    f32 pass_x;
    f32 pass_y;
    f32 pass_z;
    u8 pad_3D0[0x18C];
    Vec target_pos;
    u8 pad_568[0x34];
    s32 ground_face_id;
    u8 pad_5A0[0x0C];
    Vec ground_query_pos;
    Vec ground_pos;
    u8 pad_5C4[0x04];
    Vec axis_scale;
    EmCameraSpline* spline_a;
    EmCameraSpline* spline_b;
    s32 spline_face_id;
    u8 pad_5E0[0x18];
    s32 spline_direction;
    f32 spline_t;
    u8 pad_600[0x64];
    Vec surface_normal;
    u8 pad_670[0x198];
    Vec camera_pos_copy;
    u8 pad_814[0x18];
    Vec target_pos_copy;
    u8 pad_838[0x0C];
    Vec motion;
    u8 pad_850[0x2C];
    s32 camera_mode;
    u8 pad_880[0x88];
    s32 movement_state;
    u8 pad_90C[0x58];
    f32 spline_speed;
    f32 lateral_speed;
    f32 forward_speed;
    f32 acceleration;
    f32 direction_scale;
    u8 pad_978[0x08];
    f32 random_speed;
    u8 pad_984[0x185];
    EmCameraFlagsByte flags_B09;
    EmCameraFlagsByte flags_B0A;
};

typedef struct EmCameraState {
    void* spline_a;
    void* spline_b;
    s32 face_id;
    s32 selected_direction;
    s32 previous_face_id;
    u8 pad_014[0x10];
    s32 direction;
    f32 t;
    s32 adjacent_count;
    s32 adjacent_faces[10];
    s32 adjacent_dirs[10];
    s32 next_direction;
} EmCameraState;

extern char lbl_804B2AD0[];

f32 kar_grlib2__near_800bad8c(Vec* pos, Vec* origin, f32 radius);
BOOL kar_grcommon__near_800cf07c(Vec* pos, s32* face_id, f32* t);
s32 kar_grcommon__800cf1c0(s32 face_id, s32 direction, s32* faces, s32* dirs);
void* kar_grcommon__800cf3ac(s32 face_id);
void* kar_grcommon__800cf44c(s32 face_id);
s32 kar_grcommon__near_800cf598(s32 face_id);
BOOL kar_grcommon__near_800cf600(s32 face_id);
BOOL kar_grcommon__near_800cf66c(s32 face_id);
s32 kar_grdata__near_800ceaa4(void);
BOOL kar_grcoll_is_face_id_invalid(s32 face_id);
BOOL kar_emupdate__near_802043c8(HSD_GObj* gobj);
s32 kar_emupdate__near_80204e64(EmAnim* anim, Vec* pos, f32 radius);
void kar_emupdate__near_80204f3c(EmAnim* anim, Vec* pos);
void kar_emupdate__near_802054e4(EmAnim* anim);
BOOL fn_801FD0E0(Vec* vec);
void fn_801FD6B0(EmAnim* anim);
void kar_empass__near_80209ce4(EmAnim* anim, s32 direction);
void kar_empass__near_8020a040(EmAnim* anim, Vec* pos, Vec* out, f32 amount);
void kar_empass__near_8020aad8(EmAnim* anim, f32 x, f32 y, f32 z);
BOOL kar_empass__near_8020b01c(EmAnim* anim);
void splArcLengthPoint(Vec* out, void* spline, f32 t);
f32 kar_lbvector_angle_between(Vec* a, Vec* b);
f32 PSVECMag(Vec* v);

char kar_src_emcamera_804b2af8[] = "emcamera.c";
char lbl_804B2B08[] = "vec error\n";
char lbl_805D715C[] = "0";
const f32 lbl_805E236C = 1.0f;
const f32 lbl_805E2370 = 0.0f;
const f32 lbl_805E2374 = 1.0f;
const f64 lbl_805E2378 = 4503601774854144.0;
const f32 lbl_805E2380 = 3.1415927f;
const f32 lbl_805E2384 = 0.0001f;
const f32 lbl_805E2388 = 0.9999f;
const f64 lbl_805E2390 = 6.283185307179586;
const f64 lbl_805E2398 = 3.141592653589793;
const f64 lbl_805E23A0 = 1.5707963267948966;
const f32 lbl_805E23A8 = 0.16666669f;
const f32 lbl_805E23AC = 0.008332824f;
const f32 lbl_805E23B0 = 0.00019587841f;
const f32 lbl_805E23B4 = 0.9999998f;
const f32 lbl_805E23B8 = 0.49999395f;
const f32 lbl_805E23BC = 0.04163633f;
const f32 lbl_805E23C0 = 0.0013400711f;
const f64 lbl_805E23C8 = 0.7853981633974483;
const f32 lbl_805E23D0 = 57.29578f;
const f32 lbl_805E23D4 = 90.0f;
const f32 lbl_805E23D8 = 10.0f;
const f32 lbl_805E23DC = 5.0f;
const f32 lbl_805E23E0 = 50.0f;
const f32 lbl_805E23E4 = -2.0f;
const f32 lbl_805E23E8 = -0.2f;
const f32 lbl_805E23EC = 20.0f;
const f32 lbl_805E23F0 = 0.1f;
const f32 lbl_805E23F4 = 0.017453292f;
const f32 lbl_805E23F8 = 0.2f;

static f32 emcamera_scale_by_spline(EmAnim* anim, f32 value)
{
    EmCameraSpline* spline = anim->spline_a;
    f32 result = 0.0f;

    if (spline != NULL) {
        f32 length = spline->length;
        if (length != 0.0f) {
            result = (1.0f / length) * value;
        }
    }

    return result;
}

BOOL kar_emcamera__80206d90(HSD_GObj* gobj, Vec* pos)
{
    EmAnim* anim = gobj->user_data;
    EmCameraTemplateSource* source;
    f32 value;

    if (anim == NULL) {
        OSReport(lbl_804B2AD0);
        __assert(kar_src_emcamera_804b2af8, 0x6D, lbl_805D715C);
    }

    source = anim->field_014;
    value = kar_grlib2__near_800bad8c(pos, &anim->pos,
                                      source->state->value);
    return value >= 1.0f;
}

void kar_emcamera__near_80206e1c(EmAnim* anim, BOOL value)
{
    anim->flags_B09.flag_02 = value;
}

void kar_emcamera__near_80206e2c(EmAnim* anim)
{
    Vec old_pos = anim->pos;
    s32 face_id;
    f32 t;

    if (kar_grcommon__near_800cf07c(&anim->pos, &face_id, &t) == FALSE) {
        anim->pos = old_pos;
        anim->flags_B0A.flag_04 = TRUE;
    } else {
        anim->spline_face_id = face_id;
        anim->spline_t = t;

        if (anim->spline_direction == 1) {
            anim->spline_a = kar_grcommon__800cf3ac(face_id);
            anim->spline_b = kar_grcommon__800cf44c(face_id);
        } else {
            anim->spline_a = kar_grcommon__800cf44c(face_id);
            anim->spline_b = kar_grcommon__800cf3ac(face_id);
        }
    }
}

s32 kar_emcamera__near_80206f00(EmAnim* anim)
{
    EmCameraState* camera = (EmCameraState*) ((u8*) anim + 0x5D4);
    s32 temp_faces[10];
    s32 temp_dirs[10];
    s32 direction = (camera->direction == 1) ? 1 : 0;
    s32 count;
    s32 out_count;
    s32 i;

    count = kar_grcommon__800cf1c0(camera->face_id, direction,
                                   camera->adjacent_faces, camera->adjacent_dirs);

    if (count > 1) {
        memcpy(temp_faces, camera->adjacent_faces, sizeof(temp_faces));
        memcpy(temp_dirs, camera->adjacent_dirs, sizeof(temp_dirs));

        if (kar_grdata__near_800ceaa4() != 0) {
            out_count = 0;
            for (i = 0; i < count; i++) {
                if (kar_grcommon__near_800cf66c(temp_faces[i]) == FALSE &&
                    kar_grcommon__near_800cf600(temp_faces[i]) == FALSE &&
                    direction != temp_dirs[i]) {
                    camera->adjacent_faces[out_count] = temp_faces[i];
                    camera->adjacent_dirs[out_count] = temp_dirs[i];
                    out_count++;
                }
            }

            count = out_count;
        } else {
            out_count = 0;
            {
                s32 current_group = kar_grcommon__near_800cf598(camera->face_id);
                for (i = 0; i < count; i++) {
                    if (kar_grcommon__near_800cf66c(temp_faces[i]) == FALSE &&
                        kar_grcommon__near_800cf600(temp_faces[i]) == FALSE) {
                        if (current_group == -1 ||
                            kar_grcommon__near_800cf598(temp_faces[i]) != current_group) {
                            camera->adjacent_faces[out_count] = temp_faces[i];
                            camera->adjacent_dirs[out_count] = temp_dirs[i];
                            out_count++;
                            count = out_count;
                        }
                    }
                }
            }
        }
    }

    return count;
}

f32 kar_emcamera__near_802070b8(EmAnim* anim, f32 value)
{
    return emcamera_scale_by_spline(anim, value);
}

s32 kar_emcamera__near_802070e8(EmAnim* anim)
{
    EmCameraState* camera = (EmCameraState*) ((u8*) anim + 0x5D4);
    s32 chosen = 0;

    camera->previous_face_id = camera->face_id;
    camera->adjacent_count = kar_emcamera__near_80206f00(anim);

    if (camera->adjacent_count == 0) {
        camera->next_direction = (camera->direction == 1) ? -1 : 1;
    } else {
        if (camera->adjacent_count > 1) {
            chosen = HSD_Randi(camera->adjacent_count);
        }

        camera->face_id = camera->adjacent_faces[chosen];
        camera->selected_direction = camera->adjacent_dirs[chosen];
        if (camera->selected_direction == 0) {
            camera->next_direction = 1;
        } else {
            camera->next_direction = -1;
        }
    }

    if (camera->next_direction == 1) {
        camera->t = 0.0f;
        camera->spline_a = kar_grcommon__800cf3ac(camera->face_id);
        camera->spline_b = kar_grcommon__800cf44c(camera->face_id);
    } else {
        camera->t = 1.0f;
        camera->spline_a = kar_grcommon__800cf44c(camera->face_id);
        camera->spline_b = kar_grcommon__800cf3ac(camera->face_id);
    }

    if (camera->direction != camera->next_direction) {
        camera->direction = camera->next_direction;
        kar_emcamera__near_8020728c(anim, FALSE);
    } else {
        camera->direction = camera->next_direction;
    }

    {
        EmCameraSpline* spline = camera->spline_a;
        f32 value = anim->speed_min;
        f32 scaled = 0.0f;

        if (spline != NULL) {
            f32 length = spline->length;
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }

        anim->spline_speed = anim->direction_scale * scaled;
    }
    camera->t += anim->spline_speed * (f32) camera->direction;
    return camera->adjacent_count;
}

#pragma push
#pragma dont_inline on
void kar_emcamera__near_8020728c(EmAnim* anim, BOOL reset)
{
    Vec pos;

    // NONMATCHING: this routine builds the camera frame from the active spline.
    // The fallback preserves the important position snapshots while the path
    // math is still being reconstructed.
    if (anim->spline_a != NULL) {
        splArcLengthPoint(&pos, anim->spline_a, anim->spline_t);
        anim->camera_pos = pos;
        anim->camera_pos_copy = pos;
    }

    if (reset != FALSE) {
        anim->target_pos_copy = anim->camera_pos;
    }
    anim->target_pos = anim->camera_pos;
}
#pragma pop

f32 kar_emcamera__near_8020789c(f32 angle)
{
    f32 sign = 1.0f;
    f32 x = angle;
    f32 x2;

    if (x == 0.0f) {
        return 0.0f;
    }

    if (x < 0.0f) {
        x = -x;
        sign = -1.0f;
    }

    while (x > (f32) 6.283185307179586) {
        x -= (f32) 6.283185307179586;
    }

    if (x > (f32) 3.141592653589793) {
        x -= (f32) 3.141592653589793;
        sign = -sign;
    }

    if (x > (f32) 1.5707963267948966) {
        x = (f32) 3.141592653589793 - x;
    }

    x2 = x * x;
    return sign * x *
           (((-0.00019587841f * x2 + 0.008332824f) * x2 - 0.16666669f) * x2 + 0.9999998f);
}

void kar_emcamera__near_80207ce8(EmAnim* anim)
{
    if (kar_emupdate__near_802043c8(anim->gobj) != FALSE) {
        f32 angle;

        if (kar_grdata__near_800ceaa4() != 0) {
            angle = 0.0f;
        } else {
            Vec b;
            Vec a;
            kar_lbvector_cross_normalize(&anim->right, &anim->surface_normal, &a);
            kar_lbvector_cross_normalize(&a, &anim->right, &b);
            angle = kar_lbvector_angle_between(&anim->forward, &b) * 57.29578f;
        }

        if (angle < 90.0f) {
            anim->spline_direction = 1;
            kar_empass__near_80209ce4(anim, 0);
        } else {
            anim->spline_direction = -1;
            kar_empass__near_80209ce4(anim, 1);
        }

        if (anim->spline_direction == 1) {
            anim->spline_a = kar_grcommon__800cf3ac(anim->spline_face_id);
            anim->spline_b = kar_grcommon__800cf44c(anim->spline_face_id);
        } else {
            anim->spline_a = kar_grcommon__800cf44c(anim->spline_face_id);
            anim->spline_b = kar_grcommon__800cf3ac(anim->spline_face_id);
        }

        kar_emcamera__near_8020728c(anim, FALSE);
    }
}

void kar_emcamera__near_80207dec(EmAnim* anim)
{
    f32 value;

    if (anim->ground_face_id == -1) {
        anim->ground_face_id =
            kar_emupdate__near_80204e64(anim, &anim->ground_query_pos, 10.0f);
    }

    if (kar_grcoll_is_face_id_invalid(anim->ground_face_id) == FALSE) {
        kar_emupdate__near_80204f3c(anim, &anim->ground_pos);
    }

    anim->target_pos = anim->camera_pos;
    anim->target_pos_copy = anim->camera_pos;
    kar_empass__near_80209ce4(anim, 0);
    fn_801FD6B0(anim);

    anim->random_speed = anim->speed_random * HSD_Randf();

    value = anim->random_speed + anim->speed_min;
    {
        EmCameraSpline* spline = anim->spline_a;
        f32 scaled = 0.0f;

        if (spline != NULL) {
            f32 length = spline->length;
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
        anim->spline_speed = scaled;
    }

    value = anim->random_speed + anim->speed_mid;
    {
        EmCameraSpline* spline = anim->spline_a;
        f32 scaled = 0.0f;

        if (spline != NULL) {
            f32 length = spline->length;
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
        anim->lateral_speed = scaled;
    }

    value = anim->random_speed + anim->speed_min;
    {
        EmCameraSpline* spline = anim->spline_a;
        f32 scaled = 0.0f;

        if (spline != NULL) {
            f32 length = spline->length;
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
        anim->forward_speed = scaled;
    }
    {
        EmCameraSpline* spline = anim->spline_a;
        f32 value = anim->speed_max;
        f32 scaled = 0.0f;

        if (spline != NULL) {
            f32 length = spline->length;
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
        anim->acceleration = scaled;
    }

    value = anim->spline_speed;
    anim->pos.x = anim->surface_normal.x * value;
    anim->pos.y = anim->surface_normal.y * value;
    anim->pos.z = anim->surface_normal.z * value;

    if (anim->movement_state == 1) {
        f32 scale;

        kar_emupdate__near_802054e4(anim);
        scale = anim->velocity_scale;
        anim->velocity.x = anim->axis_scale.x * scale;
        anim->velocity.y = anim->axis_scale.y * scale;
        anim->velocity.z = anim->axis_scale.z * scale;
    }

    anim->flags_B09.flag_02 = TRUE;
    anim->flags_B09.flag_01 = TRUE;
    anim->flags_B0A.flag_80 = TRUE;
    anim->camera_mode = 1;
}

BOOL kar_emcamera__near_80208008(EmAnim* anim)
{
    return TRUE;
}

void kar_emcamera__near_80208010(EmAnim* anim)
{
    f32 max_a;
    f32 max_b;
    f32 scaled;

    {
        EmCameraSpline* spline = anim->spline_a;
        f32 value = anim->speed_mid;
        scaled = 0.0f;

        if (spline != NULL) {
            f32 length = spline->length;
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
    }
    anim->lateral_speed = scaled;
    if (scaled < 0.0f) {
        EmCameraSpline* spline = anim->spline_a;
        f32 value = anim->speed_mid;
        scaled = 0.0f;

        if (spline != NULL) {
            f32 length = spline->length;
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
        max_a = -scaled;
        anim->lateral_speed = scaled;
    } else {
        EmCameraSpline* spline = anim->spline_a;
        f32 value = anim->speed_mid;
        scaled = 0.0f;

        if (spline != NULL) {
            f32 length = spline->length;
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
        anim->lateral_speed = scaled;
        max_a = scaled;
    }

    {
        EmCameraSpline* spline = anim->spline_a;
        f32 value = anim->speed_min;
        scaled = 0.0f;

        if (spline != NULL) {
            f32 length = spline->length;
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
    }
    anim->forward_speed = scaled;
    if (scaled < 0.0f) {
        EmCameraSpline* spline = anim->spline_a;
        f32 value = anim->speed_min;
        scaled = 0.0f;

        if (spline != NULL) {
            f32 length = spline->length;
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
        max_b = -scaled;
        anim->forward_speed = scaled;
    } else {
        EmCameraSpline* spline = anim->spline_a;
        f32 value = anim->speed_min;
        scaled = 0.0f;

        if (spline != NULL) {
            f32 length = spline->length;
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
        anim->forward_speed = scaled;
        max_b = scaled;
    }

    {
        EmCameraSpline* spline = anim->spline_a;
        f32 value = anim->speed_max;
        scaled = 0.0f;

        if (spline != NULL) {
            f32 length = spline->length;
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
    }
    anim->acceleration = scaled;
    anim->spline_speed += anim->acceleration;

    if (anim->spline_speed > 0.0f) {
        if (anim->spline_speed > max_a) {
            anim->spline_speed = max_a;
        } else if (anim->spline_speed < max_b) {
            anim->spline_speed = max_b;
        }
    } else if (anim->spline_speed < 0.0f) {
        if (anim->spline_speed < -max_a) {
            anim->spline_speed = -max_a;
        } else if (anim->spline_speed > -max_b) {
            anim->spline_speed = -max_b;
        }
    }
}

BOOL kar_emcamera__near_802081ec(EmAnim* anim)
{
    // NONMATCHING: large camera steering/update routine. Keep the existing
    // helper side effects that are already understood, then report success.
    if (anim->spline_speed == 0.0f) {
        return TRUE;
    }

    if (PSVECMag(&anim->motion) != 0.0f) {
        if (kar_empass__near_8020b01c(anim) != FALSE) {
            return TRUE;
        }
        kar_emcamera__near_80206e2c(anim);
    } else {
        kar_empass__near_8020aad8(anim, anim->pass_x,
                                  anim->pass_y, anim->pass_z);
        if (anim->direction_scale == 1.0f) {
            kar_emcamera__near_80208010(anim);
        }
    }

    return TRUE;
}
