#include "functions.h"
#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/mtx/vec.h>
#include <dolphin/types.h>
#include <kar/gr/graudio.h>
#include <kar/gr/grcoll.h>
#include <kar/gr/gryaku.h>
#include <kar/lb/lbvector.h>
#include <sysdolphin/gobj.h>

typedef struct Ground Ground;
typedef struct GroundMapObject GroundMapObject;
typedef struct GroundMapPrimitive GroundMapPrimitive;
typedef struct GroundMapPrimitiveTable GroundMapPrimitiveTable;
typedef struct GroundJObjEntry GroundJObjEntry;
typedef struct Yaku Yaku;
typedef struct YakuCollision YakuCollision;
typedef struct YakuFgmEntry YakuFgmEntry;
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

struct GroundMapPrimitive {
    u32 kind;
    u8 pad_04[0x20];
};

struct GroundMapPrimitiveTable {
    u8 pad_00[0x24];
    GroundMapPrimitive primitives[1];
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

struct YakuCollision {
    u8 pad_000[0x138];
    void* owner;
};

struct YakuFgmEntry {
    u8 pad_00[0x0C];
    void* track;
    u8 pad_10[0x04];
};

struct Yaku {
    void* owner;
    s32 kind;
    YakuParamLink* param_link;
    u8 pad_00C[0x124];
    YakuCollision* collision;
    YakuFgmEntry fgm_entries[4];
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
    s32 map_object_index;
    s32 primitive_index;
    Vec pos;
    u8 pad_14[0x0C];
};

struct CollisionReport {
    u8 pad_000[0x04];
    void* event;
    u8 pad_008[0x94];
    CollisionReportFace faces[20];
    s32 face_count;
};

typedef struct CollisionEvent {
    u16 kind;
} CollisionEvent;

#if defined(VERSION_GKYJ01)
#define GRYAKUDOWNFORCEZONE_ASSERT_KIND_LINE 0xAB
#define GRYAKUDOWNFORCEZONE_EPS lbl_805DA2D4
#define GRYAKUDOWNFORCEZONE_NEG_EPS lbl_805DA2D8
#define GRYAKUDOWNFORCEZONE_PATH_ZERO lbl_805DA2E0

const f32 lbl_805DA2D4 = 0.00001f;
const f32 lbl_805DA2D8[2] = { -0.00001f, 0.0f };
const f32 lbl_805DA2E0[2] = { 0.0f, 0.0f };
#elif defined(VERSION_GKYP01)
#define GRYAKUDOWNFORCEZONE_ASSERT_KIND_LINE 0xB3
#define GRYAKUDOWNFORCEZONE_EPS lbl_805D2314
#define GRYAKUDOWNFORCEZONE_NEG_EPS lbl_805D2318
#define GRYAKUDOWNFORCEZONE_PATH_ZERO lbl_805D2320

const f32 lbl_805D2314 = 0.00001f;
const f32 lbl_805D2318[2] = { -0.00001f, 0.0f };
const f32 lbl_805D2320[2] = { 0.0f, 0.0f };
#else
#define GRYAKUDOWNFORCEZONE_ASSERT_KIND_LINE 0xAB
#define GRYAKUDOWNFORCEZONE_EPS lbl_805DF8AC
#define GRYAKUDOWNFORCEZONE_NEG_EPS lbl_805DF8B0
#define GRYAKUDOWNFORCEZONE_PATH_ZERO lbl_805DF8B8

const f32 lbl_805DF8AC = 0.00001f;
const f32 lbl_805DF8B0[2] = { -0.00001f, 0.0f };
const f32 lbl_805DF8B8[2] = { 0.0f, 0.0f };
#endif

#define GRYAKUDOWNFORCEZONE_ZERO 0.0F

char kar_src_gryakudownforcezone_c[0x18] = "gryakudownforcezone.c";
char kar_gryakudownforcezone_assert_kind_downforcezone[0x2C] =
    "gyp->kind == Gr_YakuKind_DownForceZone";
void* lbl_804A5F40[4] = { NULL, NULL, NULL, NULL };
void* lbl_804A5F50[5] = { lbl_804A5F40, NULL, NULL, NULL, NULL };

void kar_grcoll__near_800d78b4(void* collision_root, s32 index, Vec* out);
void kar_gryakuaudio_configure_fgm_track_from_joint(HSD_GObj* gobj,
                                                    s32 joint_name, s32 arg2);
void kar_gryaku_set_path_node_motion(Yaku* yaku, s32 state, void* path_nodes,
                                     s32 joint_index, s32 arg4, f32 start,
                                     f32 end, f32 arg7);
s32 kar_graudio_is_active_fgm_slot_playing(void* entry);
void kar_graudio_configure_fgm_track_mode(s32 mode, void* track_group,
                                          f32 scale, Vec* pos);
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
        switch (((CollisionEvent*) event)->kind) {
        case 0x11:
            fn_80191B4C(event, &pos);
            break;
        case 0x10:
            fn_801C7628(event, &pos);
            break;
        }
    }

    check_pos = pos;
    eps = GRYAKUDOWNFORCEZONE_EPS;
    neg = GRYAKUDOWNFORCEZONE_NEG_EPS[0];
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
    for (i = 0; i < report->face_count; i++) {
        GroundMapPrimitiveTable* map_object =
            (GroundMapPrimitiveTable*)
                &ground->map_objects[face->map_object_index];
        if ((s32) (map_object->primitives[face->primitive_index].kind &
                   0x01FFFFFF) == 0x11) {
            pos = &face->pos;
        }
        face++;
    }

    if (pos != NULL) {
        FgmParam* fgm_param;
        s32 slot;

        slot = 0;
        while (slot < 4) {
            YakuFgmEntry* entry = &yaku->fgm_entries[slot];

            if (kar_graudio_is_active_fgm_slot_playing(entry) == 0) {
                fgm_param = yaku->param_link->fgm_param;
                kar_graudio_configure_fgm_track_mode(
                    fgm_param->mode, entry->track, fgm_param->scale, pos);
                kar_graudio_play_fgm_entry_id(entry, 0);
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
    yaku->collision =
        kar_grcoll__800d79c0(&kar_gryaku_current_ground->collision_root,
                             ground_data->jobjs[param->joint_index].jobj, 0);
    yaku->collision->owner = yaku->owner;

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
