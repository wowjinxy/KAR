#include "functions.h"
#include <dolphin/mtx/mtxtypes.h>
#include <sysdolphin/jobj.h>

typedef struct Ground Ground;
typedef struct GroundData GroundData;
typedef struct Yaku Yaku;
typedef struct YakuFgmParam YakuFgmParam;
typedef struct GrPartJoint GrPartJoint;

struct Yaku {
    u8 pad_0[0x2C];
    Ground* ground;
};

struct Ground {
    u8 pad_0[0x08];
    GroundData* data;
    u8 pad_C[0x64];
    HSD_JObj* jobj;
    u8 pad_74[0xB0];
    void* fgm_track_group;
};

struct GroundData {
    u8 pad_0[0x14];
    YakuFgmParam* fgm_param;
};

struct YakuFgmParam {
    u8 pad_0[0x0C];
    s32 mode;
    f32 scale;
    Vec* position;
};

struct GrPartJoint {
    u16 joint_name;
};

static const f32 lbl_805DF820[2] = { 1.0f, 0.0f };

#if defined(VERSION_GKYP01)
#define GRYAKUAUDIO_ASSERT_JOINT_LINE 0xBA
#else
#define GRYAKUAUDIO_ASSERT_JOINT_LINE 0xB6
#endif

void PSMTXCopy(Mtx src, Mtx dst);
void HSD_MtxGetScale(Mtx mtx, Vec* scale);
void kar_graudio_configure_fgm_track_mode(s32 mode, void* track_group, f32 scale, Vec* pos);
void kar_gryakulib_get_anchor_world_translate(Yaku* yaku, s32 joint_name, Vec* out);
void kar_grcommon__near_800d4bf4(s32 joint_name, Vec* out);
f32 kar_grcommon__near_800d3058(void);
void kar_gryakueffect_scale_orientation_matrix(Mtx mtx, f32 scale);

void kar_gryakuaudio_configure_fgm_track_from_joint(Yaku* yaku, s32 joint_name,
                                                    BOOL use_yaku_anchor)
{
    Ground* ground = yaku->ground;
    YakuFgmParam* fgm_param = ground->data->fgm_param;

    if (fgm_param->position != NULL) {
        kar_graudio_configure_fgm_track_mode(fgm_param->mode, ground->fgm_track_group,
                                             fgm_param->scale, fgm_param->position);
    } else {
        Vec pos;

        if (joint_name == -1) {
            __assert("gryakuaudio.c", GRYAKUAUDIO_ASSERT_JOINT_LINE,
                     "jointName != Gr_Parts_None");
        }

        if (use_yaku_anchor) {
            kar_gryakulib_get_anchor_world_translate(yaku, joint_name, &pos);
        } else {
            kar_grcommon__near_800d4bf4(joint_name, &pos);
        }

        kar_graudio_configure_fgm_track_mode(fgm_param->mode, ground->fgm_track_group,
                                             fgm_param->scale, &pos);
    }
}

void kar_gryakuaudio_update_scaled_joint_fgm_track(Yaku* yaku, s32 joint_name)
{
    HSD_JObj* jobj;
    Ground* ground = yaku->ground;
    YakuFgmParam* fgm_param;
    Vec pos;
    Vec scale;
    Mtx mtx;
    register f32 max_scale;

    jobj = ground->jobj;
    fgm_param = ground->data->fgm_param;

    if (jobj == NULL) {
        __assert("jobj.h", 0x47C, "jobj");
    }

    HSD_JObjSetupMatrix(jobj);
    PSMTXCopy(jobj->mtx, mtx);
    kar_gryakueffect_scale_orientation_matrix(mtx, lbl_805DF820[0] / kar_grcommon__near_800d3058());
    HSD_MtxGetScale(mtx, &scale);

    max_scale = scale.x > scale.z ? scale.x : scale.z;

    kar_gryakulib_get_anchor_world_translate(yaku, joint_name, &pos);
    kar_graudio_configure_fgm_track_mode(fgm_param->mode, ground->fgm_track_group,
                                         fgm_param->scale * max_scale, &pos);
}

BOOL kar_gryakuaudio_is_gr_parts_none_joint(GrPartJoint* joint)
{
    return joint->joint_name == 15;
}
