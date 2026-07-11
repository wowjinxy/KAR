#include "functions.h"
#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>
#include <sysdolphin/gobj.h>

typedef struct Ground Ground;
typedef struct GroundMapObject GroundMapObject;
typedef struct GroundJObjEntry GroundJObjEntry;
typedef struct Yaku Yaku;
typedef struct YakuParamLink YakuParamLink;
typedef struct DownForceZoneParam DownForceZoneParam;
typedef struct FgmParam FgmParam;
typedef struct CollisionReport CollisionReport;
typedef struct CollisionReportFace CollisionReportFace;

struct Ground {
    u8 pad_00[0x54];
    u8 collision_root[0x20];
    GroundMapObject* map_objects;
    u8 pad_78[0x8C];
    GroundJObjEntry* jobjs;
};

struct GroundMapObject {
    u8 pad_000[0x24];
    u32 kind;
    u8 pad_028[0x110];
    HSD_GObj* yaku_gobj;
    u8 pad_13C[0x04];
};

struct GroundJObjEntry {
    void* jobj;
    u8 pad[0x04];
};

struct YakuParamLink {
    DownForceZoneParam* param;
    u8 pad_04[0x10];
    FgmParam* fgm_param;
};

struct Yaku {
    void* owner;
    s32 kind;
    YakuParamLink* param_link;
};

struct DownForceZoneParam {
    s32 joint_index;
    f32 force;
    f32 min_contact_speed;
    s32 audio_id;
};

struct FgmParam {
    u8 pad_00[0x0C];
    s32 mode;
    f32 scale;
};

struct CollisionReportFace {
    u8 pad_00[0x58];
    s32 map_object_index;
    s32 primitive_index;
    Vec pos;
};

struct CollisionReport {
    u8 pad_000[0x04];
    void* event;
    u8 pad_008[0x3C];
    CollisionReportFace faces[1];
};

#define GET_PTR(base, offset) (*(void**) ((u8*) (base) + (offset)))
#define GET_S32(base, offset) (*(s32*) ((u8*) (base) + (offset)))
#define GET_U16(base, offset) (*(u16*) ((u8*) (base) + (offset)))
#define GET_U32(base, offset) (*(u32*) ((u8*) (base) + (offset)))
#define GET_F32(base, offset) (*(f32*) ((u8*) (base) + (offset)))
#define YAKU_COLLISION(yaku) (*(void**) ((u8*) (yaku) + 0x130))
#define YAKU_FGM_ENTRY(yaku, index) ((u8*) (yaku) + 0x134 + (index) * 0x14)
#define YAKU_FGM_TRACK(yaku, index) (*(void**) ((u8*) (yaku) + 0x140 + (index) * 0x14))
#define REPORT_FACE_COUNT(report) (*(s32*) ((u8*) (report) + 0x31C))
#define LOAD_F32(sym) (*(volatile const f32*) &(sym))

extern Ground* kar_gryaku_current_ground;

#if defined(VERSION_GKYJ01)
#define GRYAKUDOWNFORCEZONE_ASSERT_KIND_LINE 0xAB
#define GRYAKUDOWNFORCEZONE_ZERO lbl_805DA2D0
#define GRYAKUDOWNFORCEZONE_EPS lbl_805DA2D4
#define GRYAKUDOWNFORCEZONE_NEG_EPS lbl_805DA2D8
#define GRYAKUDOWNFORCEZONE_PATH_ZERO lbl_805DA2E0

extern const f32 lbl_805DA2D0;
const f32 lbl_805DA2D4 = 0.00001f;
const f32 lbl_805DA2D8[2] = { -0.00001f, 0.0f };
const f32 lbl_805DA2E0[2] = { 0.0f, 0.0f };
#elif defined(VERSION_GKYP01)
#define GRYAKUDOWNFORCEZONE_ASSERT_KIND_LINE 0xB3
#define GRYAKUDOWNFORCEZONE_ZERO lbl_805D2310
#define GRYAKUDOWNFORCEZONE_EPS lbl_805D2314
#define GRYAKUDOWNFORCEZONE_NEG_EPS lbl_805D2318
#define GRYAKUDOWNFORCEZONE_PATH_ZERO lbl_805D2320

extern const f32 lbl_805D2310;
const f32 lbl_805D2314 = 0.00001f;
const f32 lbl_805D2318[2] = { -0.00001f, 0.0f };
const f32 lbl_805D2320[2] = { 0.0f, 0.0f };
#else
#define GRYAKUDOWNFORCEZONE_ASSERT_KIND_LINE 0xAB
#define GRYAKUDOWNFORCEZONE_ZERO lbl_805DF8A8
#define GRYAKUDOWNFORCEZONE_EPS lbl_805DF8AC
#define GRYAKUDOWNFORCEZONE_NEG_EPS lbl_805DF8B0
#define GRYAKUDOWNFORCEZONE_PATH_ZERO lbl_805DF8B8

extern const f32 lbl_805DF8A8;
const f32 lbl_805DF8AC = 0.00001f;
const f32 lbl_805DF8B0[2] = { -0.00001f, 0.0f };
const f32 lbl_805DF8B8[2] = { 0.0f, 0.0f };
#endif

char kar_src_gryakudownforcezone_c[0x18] = "gryakudownforcezone.c";
char kar_gryakudownforcezone_assert_kind_downforcezone[0x2C] =
    "gyp->kind == Gr_YakuKind_DownForceZone";
void* lbl_804A5F40[4] = { NULL, NULL, NULL, NULL };
void* lbl_804A5F50[5] = { lbl_804A5F40, NULL, NULL, NULL, NULL };

void kar_grcoll__near_800d78b4(void* collision_root, s32 index, Vec* out);
void* kar_grcoll__800d79c0(void* collision_root, void* jobj, s32 arg2);
void kar_lbvector_normalize_with_axis_fallback(Vec* dst, Vec* src);
void fn_80191B4C(void* event, Vec* out);
void fn_801C7628(void* event, Vec* out);
f32 PSVECMag(Vec* vec);
HSD_GObj* kar_gryaku_create_yaku_from_main_kind(s32 kind);
void kar_gryakuaudio_configure_fgm_track_from_joint(HSD_GObj* gobj,
                                                    s32 joint_name, s32 arg2);
void kar_gryaku_set_path_node_motion(Yaku* yaku, s32 state, void* path_nodes,
                                     s32 joint_index, s32 arg4, f32 start,
                                     f32 end, f32 arg7);
s32 kar_graudio_is_active_fgm_slot_playing(void* entry);
void kar_graudio_configure_fgm_track_mode(s32 mode, void* track_group,
                                          f32 scale, Vec* pos);
void kar_graudio_play_fgm_entry_id(void* entry, s32 id);

void kar_gryakudownforcezone_play_contact_fgm_at_report(Yaku* yaku,
                                                        CollisionReport* report);
void kar_gryakudownforcezone_init_stage_linked_kind17_yaku(HSD_GObj* gobj,
                                                           HSD_GObj* ground_gobj);
void kar_gryakudownforcezone_start_path_motion(HSD_GObj* gobj);

// NONMATCHING: flow and data are correct; remaining diff is map-object address
// calculation/register allocation at the top of the function.
f32 kar_gryakudownforcezone_query_force_vector(s32 map_object_index, Vec* out,
                                               s32* audio_id)
{
    Ground* ground;
    void* collision_root;
    GroundMapObject* map_object;
    HSD_GObj* gobj;
    Yaku* yaku;
    DownForceZoneParam* param;

    ground = kar_gryaku_current_ground;
    collision_root = &ground->collision_root;
    map_object = (GroundMapObject*) ((u8*) ground->map_objects +
                                     map_object_index * sizeof(GroundMapObject));
    gobj = map_object->yaku_gobj;

    if (gobj != NULL) {
        yaku = gobj->user_data;
        if (yaku->kind != 0x10) {
            __assert(kar_src_gryakudownforcezone_c,
                     GRYAKUDOWNFORCEZONE_ASSERT_KIND_LINE,
                     kar_gryakudownforcezone_assert_kind_downforcezone);
        }

        param = yaku->param_link->param;
        kar_grcoll__near_800d78b4(collision_root, map_object_index, out);
        kar_lbvector_normalize_with_axis_fallback(out, out);
        *audio_id = param->audio_id;
        return param->force;
    }

    out->x = GRYAKUDOWNFORCEZONE_ZERO;
    out->y = GRYAKUDOWNFORCEZONE_ZERO;
    out->z = GRYAKUDOWNFORCEZONE_ZERO;
    *audio_id = -1;
    return GRYAKUDOWNFORCEZONE_ZERO;
}

// NONMATCHING: flow is correct; remaining diff is float compare register order
// in the deadzone test and map-object address calculation.
void kar_gryakudownforcezone_handle_collision_report_audio(CollisionReport* report,
                                                           s32 map_object_index)
{
    Ground* ground;
    HSD_GObj* gobj;
    Yaku* yaku;
    DownForceZoneParam* param;
    Vec pos;
    Vec check_pos;
    void* event;
    s32 in_deadzone;
    f32 eps;
    f32 neg;

    ground = kar_gryaku_current_ground;
    {
        GroundMapObject* map_object =
            (GroundMapObject*) ((u8*) ground->map_objects +
                                map_object_index * sizeof(GroundMapObject));
        gobj = map_object->yaku_gobj;
    }
    if (gobj == NULL) {
        return;
    }

    yaku = gobj->user_data;
    param = yaku->param_link->param;
    if (yaku->param_link->fgm_param == NULL) {
        return;
    }

    pos.x = GRYAKUDOWNFORCEZONE_ZERO;
    pos.y = GRYAKUDOWNFORCEZONE_ZERO;
    pos.z = GRYAKUDOWNFORCEZONE_ZERO;
    event = report->event;
    if (event != NULL) {
        switch (GET_U16(event, 0)) {
        case 0x11:
            fn_80191B4C(event, &pos);
            break;
        case 0x10:
            fn_801C7628(event, &pos);
            break;
        }
    }

    check_pos = pos;
    eps = LOAD_F32(GRYAKUDOWNFORCEZONE_EPS);
    neg = LOAD_F32(GRYAKUDOWNFORCEZONE_NEG_EPS[0]);
    if (check_pos.x >= eps || check_pos.x <= neg || check_pos.y >= eps ||
        check_pos.y <= neg || check_pos.z >= eps || check_pos.z <= neg) {
        in_deadzone = 0;
    } else {
        in_deadzone = 1;
    }

    if (in_deadzone == 0) {
        if (PSVECMag(&pos) > param->min_contact_speed) {
            kar_gryakudownforcezone_play_contact_fgm_at_report(yaku, report);
        }
    }
}

// NONMATCHING: behavior matches the collision-face scan and FGM slot setup;
// remaining diff is register allocation in the slot loop.
void kar_gryakudownforcezone_play_contact_fgm_at_report(Yaku* yaku,
                                                        CollisionReport* report)
{
    Ground* ground;
    Vec* pos;
    CollisionReportFace* face;
    s32 i;

    pos = NULL;
    face = report->faces;
    ground = kar_gryaku_current_ground;
    for (i = 0; i < REPORT_FACE_COUNT(report); i++) {
        GroundMapObject* map_object =
            (GroundMapObject*) ((u8*) ground->map_objects +
                                face->map_object_index * sizeof(GroundMapObject) +
                                face->primitive_index * 0x24);
        if ((s32) (map_object->kind & 0x01FFFFFF) == 0x11) {
            pos = &face->pos;
        }
        face = (CollisionReportFace*) ((u8*) face + 0x20);
    }

    if (pos != NULL) {
        FgmParam* fgm_param;
        s32 slot;

        slot = 0;
        while (slot < 4) {
            if (kar_graudio_is_active_fgm_slot_playing(YAKU_FGM_ENTRY(yaku, slot)) == 0) {
                fgm_param = yaku->param_link->fgm_param;
                kar_graudio_configure_fgm_track_mode(
                    fgm_param->mode, YAKU_FGM_TRACK(yaku, slot), fgm_param->scale,
                    pos);
                kar_graudio_play_fgm_entry_id(YAKU_FGM_ENTRY(yaku, slot), 0);
                break;
            }
            slot++;
        }
    }
}

void kar_gryakudownforcezone_create_stage_linked_kind17_yaku(HSD_GObj* ground_gobj,
                                                             s32 link)
{
    HSD_GObj* gobj;

    gobj = kar_gryaku_create_yaku_from_main_kind(0x11);
    kar_gryakudownforcezone_init_stage_linked_kind17_yaku(gobj, ground_gobj);
}

void kar_gryakudownforcezone_init_stage_linked_kind17_yaku(HSD_GObj* gobj,
                                                           HSD_GObj* ground_gobj)
{
    Yaku* yaku;
    Ground* ground_data;
    DownForceZoneParam* param;

    yaku = gobj->user_data;
    ground_data = ground_gobj->user_data;
    param = yaku->param_link->param;
    YAKU_COLLISION(yaku) =
        kar_grcoll__800d79c0(&kar_gryaku_current_ground->collision_root,
                             ground_data->jobjs[param->joint_index].jobj, 0);
    GET_PTR(YAKU_COLLISION(yaku), 0x138) = yaku->owner;

    if (yaku->param_link->fgm_param != NULL) {
        kar_gryakuaudio_configure_fgm_track_from_joint(gobj, param->joint_index, 0);
    }

    kar_gryakudownforcezone_start_path_motion(gobj);
}

void kar_gryakudownforcezone_start_path_motion(HSD_GObj* gobj)
{
    Yaku* yaku;
    DownForceZoneParam* param;
    f32 zero;

    yaku = gobj->user_data;
    param = yaku->param_link->param;
    zero = GRYAKUDOWNFORCEZONE_PATH_ZERO[0];
    kar_gryaku_set_path_node_motion(yaku, 0, (void*) -1, param->joint_index, 0,
                                    zero, zero, zero);
}
