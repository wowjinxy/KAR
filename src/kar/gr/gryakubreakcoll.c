#include "functions.h"
#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>
#include <kar/gr/grcoll.h>
#include <kar/gr/gryakubreakcoll.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/jobj.h>
#include <sysdolphin/memory.h>

typedef struct GroundData GroundData;
typedef struct StageGround StageGround;
typedef struct GroundJObjEntry GroundJObjEntry;
typedef struct Yaku Yaku;
typedef struct YakuParamLink YakuParamLink;
typedef struct BreakCollParam BreakCollParam;
typedef struct BreakCollTarget BreakCollTarget;
typedef struct BreakCollFgmParam BreakCollFgmParam;
typedef struct BreakCollSharedData BreakCollSharedData;
typedef void (*GroundCallback)(void);

struct Ground {
    u8 pad_00[0x2C];
    GroundData* user_data;
};

struct GroundData {
    u8 pad_00[0x104];
    GroundJObjEntry* jobjs;
};

struct StageGround {
    u8 pad_00[0x54];
    u8 collision_root[0x20];
    u8 pad_74[0x90];
    GroundJObjEntry* jobjs;
};

struct GroundJObjEntry {
    void* jobj;
    u8 pad_04[0x04];
};

struct Yaku {
    void* owner;
    u8 pad_04[0x04];
    YakuParamLink* param_link;
    u8 pad_0C[0x10C];
    u8 fgm_entry[0x18];
    void** collisions;
    s32 active_target_count;
    u64 effect_keys[3];
    s32* fgm_handles;
};

struct YakuParamLink {
    BreakCollParam* param;
    u8 pad_04[0x10];
    BreakCollFgmParam* fgm_param;
};

struct BreakCollTarget {
    s32 joint_index;
    s32 collision_joint_index;
    s32 effect_resource;
    void* path_nodes;
};

struct BreakCollParam {
    BreakCollTarget* targets;
    s32 target_count;
    void* damage_falloff;
    void* effect_entries;
    s32 remove_effect_count;
    s32 hide_joint;
};

struct BreakCollFgmParam {
    u8 pad_00[0x0C];
    s32 mode;
    f32 scale;
};

struct BreakCollSharedData {
    GroundCallback callbacks[8];
    char src[0x14];
    char assert_fgm_id[0x2C];
    char assert_remove_effect_count[0x3C];
    char assert_target_index[0x18];
};

#define BREAKCOLL_ZERO 0.0F
#define BREAKCOLL_ONE 1.0F
#define BREAKCOLL_MAX_REMOVE_EFFECTS 3
#define BREAKCOLL_EFFECT_ENTRY_SIZE 0x1C
#define BREAKCOLL_TARGET_HIT_STRIDE 0x40
#define BREAKCOLL_TARGET_HIT_COLLISION_OFFSET 0x38

#define YAKU_FGM_ENTRY_COUNT(yaku) (*(s32*) ((u8*) (yaku) + 0x11C))
#define YAKU_FGM_ENTRY_DATA(yaku) (*(void**) ((u8*) (yaku) + 0x118))
#define YAKU_FGM_ENTRY_FLAGS(yaku) (*(u8*) ((u8*) (yaku) + 0x11C))
#define YAKU_FGM_SLOT_ARG(yaku) (*(void**) ((u8*) (yaku) + 0x120))
#define YAKU_FGM_SLOT_POS(yaku) ((Vec*) ((u8*) (yaku) + 0x128))
#define YAKU_RAW_PTR(yaku, offset) (*(void**) ((u8*) (yaku) + (offset)))

extern StageGround* kar_gryaku_current_ground;

HSD_GObj* kar_gryaku_create_yaku_from_main_kind(s32 kind);
u64 kar_gryakueffect_request_by_entry_mode(HSD_GObj* gobj, void* effect_entry,
                                           s32 effect_resource, s32 arg3,
                                           s32 arg4, Vec* pos, s32 arg6);
s32 kar_gryakueffect_is_effect_key_active(u64 key);
void kar_gryaku_set_path_node_motion(Yaku* yaku, s32 state, void* path_nodes,
                                     s32 joint_index, s32 arg4, f32 start,
                                     f32 end, f32 arg7);
s32 kar_grcoll__near_800d7b8c(void* root, void* hit, void* collision);
void kar_grcommon__near_800d4bf4(s32 joint_index, Vec* out);
s32 kar_gryakubreakicicle_test_damage_falloff_threshold(
    void* damage_falloff, void* root, void* hit, s32 pass, void* arg);
s32 kar_gryakubreakcommon_resolve_break_credit_player(void* root);
void kar_gryakubreakcommon_award_clearchecker_break_credit(HSD_GObj* gobj,
                                                           s32 player);
s32 kar_graudio_alloc_map_fgm_track_group(s32 count);
void kar_graudio_configure_fgm_track_mode(s32 mode, s32 handle, f32 scale,
                                          Vec* pos);
void kar_graudio_start_fgm_slot_core(void* entry_data, void* slot_arg,
                                     s32 handle, s32 flag, Vec* pos);
void kar_graudio_stop_active_fgm_slot(void* entry);
void kar_graudio_release_fgm_entry_track_group(void* entry);
void kar_graudio_release_fgm_track_group_handle(s32 handle);
s32 kar_lbaudio__near_800623ec(s32 handle);
void kar_lbaudio__near_80061168(s32 handle);
void kar_gryakubreakfan_cleanup_shared_allocs_and_fgm_handles(HSD_GObj* gobj);

BreakCollSharedData kar_gryakubreakcoll_shared_callback_table = {
    {
        NULL,
        NULL,
        NULL,
        NULL,
        (GroundCallback) kar_gryakubreakcoll_update_effects_audio_then_destroy,
        NULL,
        NULL,
        NULL,
    },
    "gryakubreakcoll.c",
    "0 <= fgmId && fgmId < gyp->fgm.idDataNum",
    "param->efBreakNum <= GrYakuBreakColl_RemoveEffectIdNumMax",
    "i < param->targetNum",
};

void* kar_gryakubreakcoll_kind33_callback_table_ptr[5] = {
    &kar_gryakubreakcoll_shared_callback_table,
    kar_gryakubreakcoll_handle_damage_falloff_grcoll_hit,
    kar_gryakubreakfan_cleanup_shared_allocs_and_fgm_handles,
    NULL,
    NULL,
};

void* kar_gryakubreakcoll_kind34_callback_table_ptr[5] = {
    &kar_gryakubreakcoll_shared_callback_table,
    kar_gryakubreakcoll_handle_damage_falloff_grcoll_hit,
    kar_gryakubreakfan_cleanup_shared_allocs_and_fgm_handles,
    NULL,
    NULL,
};

void* kar_gryakubreakcoll_kind35_callback_table_ptr[5] = {
    &kar_gryakubreakcoll_shared_callback_table,
    kar_gryakubreakcoll_handle_damage_falloff_grcoll_hit,
    kar_gryakubreakfan_cleanup_shared_allocs_and_fgm_handles,
    NULL,
    NULL,
};

void kar_gryakubreakcoll_break_target_by_index(HSD_GObj* gobj, s32 index,
                                               Vec* dir, s32 player)
{
    Yaku* yaku = gobj->user_data;
    YakuParamLink* link = yaku->param_link;
    BreakCollParam* param = link->param;
    BreakCollTarget* target = &param->targets[index];
    s32 i;

    if (kar_grcoll__near_800d7b0c(yaku->collisions[index], 1) == 0) {
        return;
    }

    kar_grcoll__near_800d7ad0(yaku->collisions[index], 0);
    yaku->active_target_count--;

    if (param->hide_joint != 0) {
        HSD_JObjSetFlagsAll(kar_gryaku_current_ground->jobjs[target->joint_index].jobj,
                            0x10);
    }

    if (param->remove_effect_count > BREAKCOLL_MAX_REMOVE_EFFECTS) {
        __assert(kar_gryakubreakcoll_shared_callback_table.src, 0xD0,
                 kar_gryakubreakcoll_shared_callback_table.assert_remove_effect_count);
    }

    for (i = 0; i < param->remove_effect_count; i++) {
        yaku->effect_keys[i] =
            kar_gryakueffect_request_by_entry_mode(
                gobj, (u8*) param->effect_entries + i * BREAKCOLL_EFFECT_ENTRY_SIZE,
                target->effect_resource, 0, 0, dir, 0);
    }

    if (YAKU_FGM_ENTRY_COUNT(yaku) > 0) {
        if (yaku->fgm_handles[index] == -1) {
            Vec pos;
            s32 handle = kar_graudio_alloc_map_fgm_track_group(1);

            yaku->fgm_handles[index] = handle;
            kar_grcommon__near_800d4bf4(target->joint_index, &pos);
            kar_graudio_configure_fgm_track_mode(link->fgm_param->mode, handle,
                                                 link->fgm_param->scale, &pos);
            kar_lbaudio__near_80061168(handle);
        }

        kar_graudio_start_fgm_slot_core(
            YAKU_FGM_ENTRY_DATA(yaku), YAKU_FGM_SLOT_ARG(yaku),
            yaku->fgm_handles[index],
            (YAKU_FGM_ENTRY_FLAGS(yaku) & 0x80) ? -1 : 0,
            YAKU_FGM_SLOT_POS(yaku));
    }

    if (player != 5) {
        kar_gryakubreakcommon_award_clearchecker_break_credit(gobj, player);
    }

    kar_gryaku_set_path_node_motion(yaku, 1, target->path_nodes,
                                    target->joint_index, 0, BREAKCOLL_ZERO,
                                    BREAKCOLL_ONE, BREAKCOLL_ZERO);
}

void kar_gryakubreakcoll_update_effects_audio_then_destroy(HSD_GObj* gobj)
{
    Yaku* yaku = gobj->user_data;
    BreakCollParam* param = yaku->param_link->param;
    s32 i;

    if (yaku->active_target_count <= 0) {
        for (i = 0; i < param->remove_effect_count; i++) {
            if (yaku->effect_keys[i] != 0 &&
                kar_gryakueffect_is_effect_key_active(yaku->effect_keys[i]) == 0) {
                yaku->effect_keys[i] = 0;
            }
        }

        for (i = 0; i < param->remove_effect_count; i++) {
            if (yaku->effect_keys[i] != 0) {
                break;
            }
        }

        if (i == param->remove_effect_count) {
            if (YAKU_FGM_ENTRY_DATA(yaku) != NULL &&
                (YAKU_FGM_ENTRY_FLAGS(yaku) & 0x80) != 0) {
                kar_graudio_stop_active_fgm_slot(yaku->fgm_entry);
            }

            HSD_GObjDestroy(gobj);
        }
    }

    if (yaku->fgm_handles != NULL) {
        for (i = 0; i < param->target_count; i++) {
            s32 handle = yaku->fgm_handles[i];

            if (handle != -1 && kar_lbaudio__near_800623ec(handle) == 0) {
                kar_graudio_release_fgm_track_group_handle(handle);
                yaku->fgm_handles[i] = -1;
            }
        }
    }
}

s32 kar_gryakubreakcoll_handle_damage_falloff_grcoll_hit(HSD_GObj* gobj,
                                                          void* root,
                                                          void* hit, s32 pass,
                                                          void* arg)
{
    Yaku* yaku = gobj->user_data;
    BreakCollParam* param = yaku->param_link->param;
    void* collision =
        *(void**) (*(u8**) ((u8*) hit + 0x08) +
                   pass * BREAKCOLL_TARGET_HIT_STRIDE +
                   BREAKCOLL_TARGET_HIT_COLLISION_OFFSET);
    s32 i;

    if (kar_grcoll__near_800d7b8c(root, hit, collision) != 0) {
        return 0;
    }

    for (i = 0; i < param->target_count; i++) {
        if (yaku->collisions[i] == collision) {
            break;
        }
    }

    if (i >= param->target_count) {
        __assert(kar_gryakubreakcoll_shared_callback_table.src, 0x13C,
                 kar_gryakubreakcoll_shared_callback_table.assert_target_index);
    }

    if (kar_gryakubreakicicle_test_damage_falloff_threshold(
            param->damage_falloff, root, hit, pass, arg) != 0) {
        kar_gryakubreakcoll_break_target_by_index(
            gobj, i, (Vec*) ((u8*) root + 0x14),
            kar_gryakubreakcommon_resolve_break_credit_player(root));
        return 1;
    }

    return 0;
}

#define DEFINE_BREAKCOLL_CREATE(func_name, kind_value)                         \
    void func_name(struct Ground* ground_gobj, s32 link)                       \
    {                                                                          \
        HSD_GObj* yaku_gobj;                                                   \
        GroundData* ground_data;                                               \
        Yaku* yaku;                                                            \
        BreakCollParam* param;                                                 \
        s32 i;                                                                 \
                                                                               \
        (void) link;                                                           \
        yaku_gobj = kar_gryaku_create_yaku_from_main_kind(kind_value);         \
        ground_data = ground_gobj->user_data;                                  \
        yaku = yaku_gobj->user_data;                                           \
        param = yaku->param_link->param;                                       \
                                                                               \
        yaku->collisions = HSD_Alloc(param->target_count * sizeof(void*));     \
        yaku->active_target_count = param->target_count;                       \
        for (i = 0; i < param->target_count; i++) {                            \
            yaku->collisions[i] =                                              \
                kar_grcoll__800d7954(                                          \
                    &kar_gryaku_current_ground->collision_root,                \
                    ground_data->jobjs[param->targets[i].collision_joint_index]\
                        .jobj);                                                \
            *(void**) ((u8*) yaku->collisions[i] + 0x90) = yaku->owner;        \
        }                                                                      \
                                                                               \
        yaku->effect_keys[0] = 0;                                               \
        yaku->effect_keys[1] = 0;                                               \
        yaku->effect_keys[2] = 0;                                               \
                                                                               \
        if (yaku->param_link->fgm_param != NULL) {                             \
            yaku->fgm_handles =                                                \
                HSD_Alloc(param->target_count * sizeof(s32));                  \
            kar_graudio_release_fgm_entry_track_group(yaku->fgm_entry);        \
            for (i = 0; i < param->target_count; i++) {                        \
                yaku->fgm_handles[i] = -1;                                     \
            }                                                                  \
        } else {                                                               \
            yaku->fgm_handles = NULL;                                          \
        }                                                                      \
                                                                               \
        kar_gryaku_set_path_node_motion(yaku, 0, (void*) -1, -1, 0,            \
                                        BREAKCOLL_ZERO, BREAKCOLL_ZERO,        \
                                        BREAKCOLL_ZERO);                       \
    }

DEFINE_BREAKCOLL_CREATE(kar_gryakubreakcoll_create_stage_linked_kind33_breakcoll,
                        0x21)
DEFINE_BREAKCOLL_CREATE(kar_gryakubreakcoll_create_stage_linked_kind34_breakcoll,
                        0x22)
DEFINE_BREAKCOLL_CREATE(kar_gryakubreakcoll_create_stage_linked_kind35_breakcoll,
                        0x23)

void kar_gryakubreakcoll_cleanup_multi_target_allocs_and_fgm_handles(
    HSD_GObj* gobj)
{
    Yaku* yaku = gobj->user_data;
    BreakCollParam* param = yaku->param_link->param;
    s32* handles;
    s32 i;

    HSD_Free(YAKU_RAW_PTR(yaku, 0x130));
    HSD_Free(YAKU_RAW_PTR(yaku, 0x134));
    HSD_Free(YAKU_RAW_PTR(yaku, 0x138));
    HSD_Free(YAKU_RAW_PTR(yaku, 0x13C));

    handles = YAKU_RAW_PTR(yaku, 0x160);
    if (handles != NULL) {
        for (i = 0; i < param->target_count; i++) {
            s32 handle = handles[i];

            if (handle != -1) {
                kar_graudio_release_fgm_track_group_handle(handle);
                handles[i] = -1;
            }
        }

        HSD_Free(handles);
    }
}
