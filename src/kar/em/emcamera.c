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

#define FIELD(type, obj, off) (*(type*) ((u8*) (obj) + (off)))
#define VEC_FIELD(obj, off) FIELD(Vec, obj, off)
#define F32_FIELD(obj, off) FIELD(f32, obj, off)
#define S32_FIELD(obj, off) FIELD(s32, obj, off)
#define U8_FIELD(obj, off) FIELD(u8, obj, off)
#define PTR_FIELD(type, obj, off) FIELD(type*, obj, off)

typedef struct EmCameraTemplateSource {
    void* state;
} EmCameraTemplateSource;

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
    u8 pad_018[0x2D4];
    Vec velocity;
    Vec pos;
    u8 pad_304[0x805];
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
    void* spline = PTR_FIELD(void, anim, 0x5D4);
    f32 result = 0.0f;

    if (spline != NULL) {
        f32 length = F32_FIELD(spline, 0x0C);
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
                                      F32_FIELD(source->state, 0x0C));
    return value >= 1.0f;
}

void kar_emcamera__near_80206e1c(EmAnim* anim, BOOL value)
{
    FIELD(EmCameraFlagsByte, anim, 0xB09).flag_02 = value;
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
        S32_FIELD(anim, 0x5DC) = face_id;
        F32_FIELD(anim, 0x5FC) = t;

        if (S32_FIELD(anim, 0x5F8) == 1) {
            PTR_FIELD(void, anim, 0x5D4) = kar_grcommon__800cf3ac(face_id);
            PTR_FIELD(void, anim, 0x5D8) = kar_grcommon__800cf44c(face_id);
        } else {
            PTR_FIELD(void, anim, 0x5D4) = kar_grcommon__800cf44c(face_id);
            PTR_FIELD(void, anim, 0x5D8) = kar_grcommon__800cf3ac(face_id);
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
        void* spline = camera->spline_a;
        f32 value = F32_FIELD(anim, 0x390);
        f32 scaled = 0.0f;

        if (spline != NULL) {
            f32 length = F32_FIELD(spline, 0x0C);
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }

        F32_FIELD(anim, 0x964) = F32_FIELD(anim, 0x974) * scaled;
    }
    camera->t += F32_FIELD(anim, 0x964) * (f32) camera->direction;
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
    if (PTR_FIELD(void, anim, 0x5D4) != NULL) {
        splArcLengthPoint(&pos, PTR_FIELD(void, anim, 0x5D4), F32_FIELD(anim, 0x5FC));
        VEC_FIELD(anim, 0x2F8) = pos;
        VEC_FIELD(anim, 0x808) = pos;
    }

    if (reset != FALSE) {
        VEC_FIELD(anim, 0x82C) = VEC_FIELD(anim, 0x2F8);
    }
    VEC_FIELD(anim, 0x55C) = VEC_FIELD(anim, 0x2F8);
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
    if (kar_emupdate__near_802043c8(FIELD(HSD_GObj*, anim, 0x0)) != FALSE) {
        f32 angle;

        if (kar_grdata__near_800ceaa4() != 0) {
            angle = 0.0f;
        } else {
            Vec b;
            Vec a;
            kar_lbvector_cross_normalize(&VEC_FIELD(anim, 0x340), &VEC_FIELD(anim, 0x664), &a);
            kar_lbvector_cross_normalize(&a, &VEC_FIELD((u8*) anim + 0x300, 0x40), &b);
            angle = kar_lbvector_angle_between(&VEC_FIELD(anim, 0x334), &b) * 57.29578f;
        }

        if (angle < 90.0f) {
            S32_FIELD(anim, 0x5F8) = 1;
            kar_empass__near_80209ce4(anim, 0);
        } else {
            S32_FIELD(anim, 0x5F8) = -1;
            kar_empass__near_80209ce4(anim, 1);
        }

        if (S32_FIELD(anim, 0x5F8) == 1) {
            PTR_FIELD(void, anim, 0x5D4) = kar_grcommon__800cf3ac(S32_FIELD(anim, 0x5DC));
            PTR_FIELD(void, anim, 0x5D8) = kar_grcommon__800cf44c(S32_FIELD(anim, 0x5DC));
        } else {
            PTR_FIELD(void, anim, 0x5D4) = kar_grcommon__800cf44c(S32_FIELD(anim, 0x5DC));
            PTR_FIELD(void, anim, 0x5D8) = kar_grcommon__800cf3ac(S32_FIELD(anim, 0x5DC));
        }

        kar_emcamera__near_8020728c(anim, FALSE);
    }
}

void kar_emcamera__near_80207dec(EmAnim* anim)
{
    f32 value;

    if (S32_FIELD(anim, 0x59C) == -1) {
        S32_FIELD(anim, 0x59C) =
            kar_emupdate__near_80204e64(anim, &VEC_FIELD(anim, 0x5AC), 10.0f);
    }

    if (kar_grcoll_is_face_id_invalid(S32_FIELD(anim, 0x59C)) == FALSE) {
        kar_emupdate__near_80204f3c(anim, &VEC_FIELD(anim, 0x5B8));
    }

    VEC_FIELD(anim, 0x55C) = VEC_FIELD(anim, 0x2F8);
    VEC_FIELD(anim, 0x82C) = VEC_FIELD(anim, 0x2F8);
    kar_empass__near_80209ce4(anim, 0);
    fn_801FD6B0(anim);

    F32_FIELD(anim, 0x980) = F32_FIELD(anim, 0x398) * HSD_Randf();

    value = F32_FIELD(anim, 0x980) + F32_FIELD(anim, 0x390);
    {
        void* spline = PTR_FIELD(void, anim, 0x5D4);
        f32 scaled = 0.0f;

        if (spline != NULL) {
            f32 length = F32_FIELD(spline, 0x0C);
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
        F32_FIELD(anim, 0x964) = scaled;
    }

    value = F32_FIELD(anim, 0x980) + F32_FIELD(anim, 0x394);
    {
        void* spline = PTR_FIELD(void, anim, 0x5D4);
        f32 scaled = 0.0f;

        if (spline != NULL) {
            f32 length = F32_FIELD(spline, 0x0C);
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
        F32_FIELD(anim, 0x968) = scaled;
    }

    value = F32_FIELD(anim, 0x980) + F32_FIELD(anim, 0x390);
    {
        void* spline = PTR_FIELD(void, anim, 0x5D4);
        f32 scaled = 0.0f;

        if (spline != NULL) {
            f32 length = F32_FIELD(spline, 0x0C);
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
        F32_FIELD(anim, 0x96C) = scaled;
    }
    {
        void* spline = PTR_FIELD(void, anim, 0x5D4);
        f32 value = F32_FIELD(anim, 0x39C);
        f32 scaled = 0.0f;

        if (spline != NULL) {
            f32 length = F32_FIELD(spline, 0x0C);
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
        F32_FIELD(anim, 0x970) = scaled;
    }

    value = F32_FIELD(anim, 0x964);
    VEC_FIELD(anim, 0x2EC).x = VEC_FIELD(anim, 0x664).x * value;
    VEC_FIELD(anim, 0x2EC).y = VEC_FIELD(anim, 0x664).y * value;
    VEC_FIELD(anim, 0x2EC).z = VEC_FIELD(anim, 0x664).z * value;

    if (S32_FIELD(anim, 0x908) == 1) {
        f32 scale;

        kar_emupdate__near_802054e4(anim);
        scale = F32_FIELD(anim, 0x3A4);
        VEC_FIELD(anim, 0x2E0).x = VEC_FIELD(anim, 0x5C8).x * scale;
        VEC_FIELD(anim, 0x2E0).y = VEC_FIELD(anim, 0x5C8).y * scale;
        VEC_FIELD(anim, 0x2E0).z = VEC_FIELD(anim, 0x5C8).z * scale;
    }

    FIELD(EmCameraFlagsByte, anim, 0xB09).flag_02 = TRUE;
    FIELD(EmCameraFlagsByte, anim, 0xB09).flag_01 = TRUE;
    FIELD(EmCameraFlagsByte, anim, 0xB0A).flag_80 = TRUE;
    S32_FIELD(anim, 0x87C) = 1;
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
        void* spline = PTR_FIELD(void, anim, 0x5D4);
        f32 value = F32_FIELD(anim, 0x394);
        scaled = 0.0f;

        if (spline != NULL) {
            f32 length = F32_FIELD(spline, 0x0C);
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
    }
    F32_FIELD(anim, 0x968) = scaled;
    if (scaled < 0.0f) {
        void* spline = PTR_FIELD(void, anim, 0x5D4);
        f32 value = F32_FIELD(anim, 0x394);
        scaled = 0.0f;

        if (spline != NULL) {
            f32 length = F32_FIELD(spline, 0x0C);
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
        max_a = -scaled;
        F32_FIELD(anim, 0x968) = scaled;
    } else {
        void* spline = PTR_FIELD(void, anim, 0x5D4);
        f32 value = F32_FIELD(anim, 0x394);
        scaled = 0.0f;

        if (spline != NULL) {
            f32 length = F32_FIELD(spline, 0x0C);
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
        F32_FIELD(anim, 0x968) = scaled;
        max_a = scaled;
    }

    {
        void* spline = PTR_FIELD(void, anim, 0x5D4);
        f32 value = F32_FIELD(anim, 0x390);
        scaled = 0.0f;

        if (spline != NULL) {
            f32 length = F32_FIELD(spline, 0x0C);
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
    }
    F32_FIELD(anim, 0x96C) = scaled;
    if (scaled < 0.0f) {
        void* spline = PTR_FIELD(void, anim, 0x5D4);
        f32 value = F32_FIELD(anim, 0x390);
        scaled = 0.0f;

        if (spline != NULL) {
            f32 length = F32_FIELD(spline, 0x0C);
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
        max_b = -scaled;
        F32_FIELD(anim, 0x96C) = scaled;
    } else {
        void* spline = PTR_FIELD(void, anim, 0x5D4);
        f32 value = F32_FIELD(anim, 0x390);
        scaled = 0.0f;

        if (spline != NULL) {
            f32 length = F32_FIELD(spline, 0x0C);
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
        F32_FIELD(anim, 0x96C) = scaled;
        max_b = scaled;
    }

    {
        void* spline = PTR_FIELD(void, anim, 0x5D4);
        f32 value = F32_FIELD(anim, 0x39C);
        scaled = 0.0f;

        if (spline != NULL) {
            f32 length = F32_FIELD(spline, 0x0C);
            if (scaled != length) {
                scaled = (1.0f / length) * value;
            }
        }
    }
    F32_FIELD(anim, 0x970) = scaled;
    F32_FIELD(anim, 0x964) += F32_FIELD(anim, 0x970);

    if (F32_FIELD(anim, 0x964) > 0.0f) {
        if (F32_FIELD(anim, 0x964) > max_a) {
            F32_FIELD(anim, 0x964) = max_a;
        } else if (F32_FIELD(anim, 0x964) < max_b) {
            F32_FIELD(anim, 0x964) = max_b;
        }
    } else if (F32_FIELD(anim, 0x964) < 0.0f) {
        if (F32_FIELD(anim, 0x964) < -max_a) {
            F32_FIELD(anim, 0x964) = -max_a;
        } else if (F32_FIELD(anim, 0x964) > -max_b) {
            F32_FIELD(anim, 0x964) = -max_b;
        }
    }
}

BOOL kar_emcamera__near_802081ec(EmAnim* anim)
{
    // NONMATCHING: large camera steering/update routine. Keep the existing
    // helper side effects that are already understood, then report success.
    if (F32_FIELD(anim, 0x964) == 0.0f) {
        return TRUE;
    }

    if (PSVECMag(&VEC_FIELD(anim, 0x844)) != 0.0f) {
        if (kar_empass__near_8020b01c(anim) != FALSE) {
            return TRUE;
        }
        kar_emcamera__near_80206e2c(anim);
    } else {
        kar_empass__near_8020aad8(anim, F32_FIELD(anim, 0x3C4),
                                  F32_FIELD(anim, 0x3C8), F32_FIELD(anim, 0x3CC));
        if (F32_FIELD(anim, 0x974) == 1.0f) {
            kar_emcamera__near_80208010(anim);
        }
    }

    return TRUE;
}
