#include "functions.h"
#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>
#include <kar/gm/gmlanmenu.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/memory.h>

typedef struct Ground Ground;
typedef struct GroundData GroundData;
typedef struct GroundJObjEntry GroundJObjEntry;
typedef struct Yaku Yaku;
typedef struct YakuParamLink YakuParamLink;
typedef struct RecoveryZoneParam RecoveryZoneParam;
typedef struct Kind41Param Kind41Param;
typedef struct GroundGroupParam GroundGroupParam;
typedef union YakuFlagByte YakuFlagByte;
typedef union YakuKind41FlagByte YakuKind41FlagByte;

struct Ground {
    u8 pad_0[0x54];
    u8 collision_root[0x20];
    void* player_slots;
    u8 pad_78[0x8C];
    GroundJObjEntry* jobjs;
};

struct GroundData {
    u8 pad_0[0x104];
    GroundJObjEntry* jobjs;
};

struct GroundJObjEntry {
    void* jobj;
    u8 pad[0x04];
};

struct Yaku {
    void* owner;
    u8 pad_04[0x04];
    YakuParamLink* param_link;
    u8 pad_0C[0x58];
    GroundJObjEntry* jobjs;
};

struct YakuParamLink {
    void* param;
};

struct RecoveryZoneParam {
    s32 joint_index;
    s32 kind41_joint_index;
    s32 motion_joint_index;
    void* path_nodes;
    void* state1_path_nodes;
    void* dobj_anim_entries;
    void* jobj_anim_entries;
    void* enabled_path_nodes;
    void* loop_effect_entries;
    s32 loop_effect_count;
    void* enabled_effect_entries;
    s32 enabled_effect_count;
    f32* timing;
};

struct Kind41Param {
    void* motion_param;
    s32 joint_index;
    s32 motion_joint_index;
    void* path_nodes;
};

struct GroundGroupParam {
    s32 joint_index;
    u8 pad_04[0x08];
    s32* ground_indices;
    s32 ground_count;
};

union YakuFlagByte {
    u8 flags;
    struct {
        u8 b7 : 1;
    };
};

union YakuKind41FlagByte {
    u8 flags;
    struct {
        u8 b7 : 1;
        u8 b6 : 1;
    };
};

#define YAKU_PARAM(yaku, type) ((type*) ((yaku)->param_link->param))
#define YAKU_FIELD_130(yaku) (*(void**) ((u8*) (yaku) + 0x130))
#define YAKU_FIELD_134_F(yaku) (*(f32*) ((u8*) (yaku) + 0x134))
#define YAKU_FIELD_134_S32(yaku) (*(s32*) ((u8*) (yaku) + 0x134))
#define YAKU_FIELD_138(yaku) (*(void**) ((u8*) (yaku) + 0x138))
#define YAKU_FIELD_140(yaku) (*(s32*) ((u8*) (yaku) + 0x140))
#define YAKU_FIELD_11C(yaku) (*(s32*) ((u8*) (yaku) + 0x11C))
#define YAKU_FLAGS_158(yaku) (*(u8*) ((u8*) (yaku) + 0x158))
#define YAKU_FLAGS_13C(yaku) (*(u8*) ((u8*) (yaku) + 0x13C))
#define YAKU_FLAGS_13C_BITS(yaku) (*(YakuFlagByte*) ((u8*) (yaku) + 0x13C))
#define YAKU_FLAGS_144_BITS(yaku) (*(YakuKind41FlagByte*) ((u8*) (yaku) + 0x144))
extern Ground* lbl_805DD6CC;
extern const f32 lbl_805DC8BC[];
extern const f32 lbl_805DF8D4;
extern const f32 lbl_805DF8D8;
extern const f32 lbl_805DF8E4;
extern const f32 lbl_805DF8E8;
extern char kar_src_gryakurecoveryzone_c[];
extern char kar_gryakurecoveryzone_assert_kind_recoveryzone[];
extern char kar_src_ground_h_804a6170[];
extern char lbl_805D6248;

HSD_GObj* kar_gryaku_create_yaku_from_main_kind(s32 kind);
void kar_gryakurecoveryzone_enter_enabled_state_sequence(HSD_GObj* gobj);
void kar_gryakurecoveryzone_init_stage_linked_recoveryzone_yaku(HSD_GObj* gobj,
                                                                HSD_GObj* ground_gobj);
void kar_gryakurecoveryzone_init_stage_indexed_kind41_joint_yaku(HSD_GObj* gobj,
                                                                 HSD_GObj* ground_gobj,
                                                                 s32 index);
void kar_gryakurecoveryzone_init_stage_linked_kind42_ground_group_yaku(
    HSD_GObj* gobj, HSD_GObj* ground_gobj);
void kar_gryakurecoveryzone_start_state1_path_motion(HSD_GObj* gobj);
void kar_gryakurecoveryzone_start_state2_path_motion(HSD_GObj* gobj);
void kar_gryakurecoveryzone_update_kind41_wait_then_extend(HSD_GObj* gobj);
void kar_gryakurecoveryzone_start_kind42_ground_group_idle_motion(HSD_GObj* gobj);
void* kar_grcoll__800d79c0(void* collision_root, void* jobj, s32 arg2);
void kar_grcoll__near_800d7ad0(void* collision, s32 enabled);
void kar_gryaku_set_path_node_motion(Yaku* yaku, s32 state, void* path_nodes,
                                     s32 joint_index, s32 arg4, f32 start, f32 end,
                                     f32 arg7);
u64 kar_gryakueffect_request_by_entry_mode(HSD_GObj* gobj, void* effect_entry,
                                           s32 effect_resource, s32 arg3, s32 arg4,
                                           Vec* pos, s32 arg6);
void kar_gryakuanim_apply_zone_enabled_state(Yaku* yaku, s32 state);
void kar_graudio_play_fgm_entry_id(void* entry, s32 id);
s32 kar_gryakulib_get_yaku_data_checked(HSD_GObj* gobj);
s32 kar_gryakulib_get_yaku_state_or_none(HSD_GObj* gobj);
void kar_gryakulib_get_model_root_position(HSD_GObj* gobj, Vec* out);
f32 fn_803D22F4(Vec* a, Vec* b);
f32 kar_gryakurecoveryzone_update_recovery_progress(HSD_GObj* gobj, void* arg,
                                                    f32 delta);

void kar_gryakurecoveryzone_create_stage_linked_recoveryzone_yaku(HSD_GObj* ground_gobj)
{
    HSD_GObj* gobj = kar_gryaku_create_yaku_from_main_kind(0x14);
    kar_gryakurecoveryzone_init_stage_linked_recoveryzone_yaku(gobj, ground_gobj);
}

// NONMATCHING: flow is correct, remaining diff is register allocation around
// the collision pointer reload and bit 7 write at yaku+0x158.
void kar_gryakurecoveryzone_init_stage_linked_recoveryzone_yaku(HSD_GObj* gobj,
                                                                HSD_GObj* ground_gobj)
{
    s32 flag;
    Yaku* yaku = gobj->user_data;
    GroundData* ground_data = ground_gobj->user_data;
    RecoveryZoneParam* param = YAKU_PARAM(yaku, RecoveryZoneParam);

    YAKU_FIELD_130(yaku) =
        kar_grcoll__800d79c0(&lbl_805DD6CC->collision_root,
                             ground_data->jobjs[param->joint_index].jobj, 0);
    flag = 1;
    *(void**) ((u8*) YAKU_FIELD_130(yaku) + 0x138) = yaku->owner;
    YAKU_FIELD_134_F(yaku) = param->timing[0];
    YAKU_FLAGS_158(yaku) = (YAKU_FLAGS_158(yaku) & ~(flag << 7)) | (flag << 7);
    kar_gryakurecoveryzone_start_state1_path_motion(gobj);
}

void kar_gryakurecoveryzone_start_state1_path_motion(HSD_GObj* gobj)
{
    Yaku* yaku = gobj->user_data;
    RecoveryZoneParam* param = YAKU_PARAM(yaku, RecoveryZoneParam);
    f32 zero = lbl_805DF8D4;

    kar_gryaku_set_path_node_motion(yaku, 1, (void*) -1, param->joint_index, 0, zero,
                                    zero, zero);
}

void kar_gryakurecoveryzone_start_state2_path_motion(HSD_GObj* gobj)
{
    Yaku* yaku = gobj->user_data;
    RecoveryZoneParam* param = YAKU_PARAM(yaku, RecoveryZoneParam);
    f32 zero = lbl_805DF8D4;

    YAKU_FIELD_134_F(yaku) = zero;
    kar_gryaku_set_path_node_motion(yaku, 2, (void*) -1, param->joint_index, 0, zero,
                                    zero, zero);
}

// NONMATCHING: flow is correct, remaining diff is register allocation in the
// effect loop and final enabled-state motion setup.
void kar_gryakurecoveryzone_enter_enabled_state_sequence(HSD_GObj* gobj)
{
    RecoveryZoneParam* param;
    Yaku* yaku;

    yaku = gobj->user_data;
    param = YAKU_PARAM(yaku, RecoveryZoneParam);

    if (kar_gmlanmenu__near_800547e0(yaku->jobjs[param->joint_index].jobj) == 0) {
        s32 offset;
        s32 i;

        i = 0;
        offset = 0;
        while (i < param->enabled_effect_count) {
            kar_gryakueffect_request_by_entry_mode(
                gobj, (u8*) param->enabled_effect_entries + offset, param->joint_index,
                0, 0, NULL, 1);
            offset += 0x1C;
            i++;
        }

        yaku = gobj->user_data;
        param = YAKU_PARAM(yaku, RecoveryZoneParam);
        kar_gryakuanim_apply_zone_enabled_state(yaku, 0);
        {
            f32 zero = lbl_805DF8D4;
            kar_gryaku_set_path_node_motion(yaku, 3, param->enabled_path_nodes, -1,
                                            4, zero, lbl_805DF8D8, zero);
        }
    }
}

s32 kar_gryakurecoveryzone_find_nearest_active_recoveryzone_pos(Vec* pos, Vec* out)
{
    Vec zone_pos;
    f32 nearest_dist = lbl_805DC8BC[0];
    f32 dist;
    HSD_GObj* gobj;
    s32 found;

    for (gobj = hsdGObj_p_link_tails[8]; gobj != NULL; gobj = gobj->prev) {
        if (kar_gryakulib_get_yaku_data_checked(gobj) == 0x14) {
            s32 state = kar_gryakulib_get_yaku_state_or_none(gobj);

            switch (state) {
            case 0:
            case 1:
                kar_gryakulib_get_model_root_position(gobj, &zone_pos);
                dist = fn_803D22F4(pos, &zone_pos);
                if (dist < nearest_dist) {
                    *out = zone_pos;
                    nearest_dist = dist;
                }
                break;
            }
        }
    }

    if (nearest_dist < lbl_805DC8BC[0]) {
        found = 1;
    } else {
        found = 0;
    }

    return found;
}

// NONMATCHING: flow is correct, but player-slot address calculation and one
// state branch still compile differently from 800FB2BC.
f32 kar_gryakurecoveryzone_try_update_player_slot_recovery(s32 player, void* arg,
                                                           f32 delta)
{
    Ground* ground = lbl_805DD6CC;
    u8* player_slot = (u8*) ground->player_slots + player * 0x140;
    HSD_GObj* gobj = *(HSD_GObj**) (player_slot + 0x138);

    if (gobj != NULL) {
        if (kar_gryakulib_get_yaku_data_checked(gobj) != 0x14) {
            __assert(kar_src_gryakurecoveryzone_c, 0x19D,
                     kar_gryakurecoveryzone_assert_kind_recoveryzone);
        }

        if (kar_gryakulib_get_yaku_state_or_none(gobj) == 1) {
            return kar_gryakurecoveryzone_update_recovery_progress(gobj, arg, delta);
        }
    }

    return lbl_805DF8D4;
}

void kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(HSD_GObj* ground_gobj,
                                                                   s32 unused, s32 index)
{
    HSD_GObj* gobj = kar_gryaku_create_yaku_from_main_kind(0x29);
    kar_gryakurecoveryzone_init_stage_indexed_kind41_joint_yaku(gobj, ground_gobj, index);
}

void kar_gryakurecoveryzone_start_kind41_joint_idle_motion(HSD_GObj* gobj)
{
    Yaku* yaku = gobj->user_data;
    Kind41Param* param = YAKU_PARAM(yaku, Kind41Param);

    YAKU_FIELD_140(yaku) = *(s32*) ((u8*) param->motion_param + 0x18);
    kar_grcoll__near_800d7ad0(YAKU_FIELD_130(yaku), 0);
    {
        f32 zero = lbl_805DF8E4;
        kar_gryaku_set_path_node_motion(yaku, 0, param->path_nodes,
                                        param->motion_joint_index, 0, zero, zero, zero);
    }
}

// NONMATCHING: flow is correct, remaining diff is register allocation in the
// transition block after the wait flags fire.
void kar_gryakurecoveryzone_update_kind41_wait_then_extend(HSD_GObj* gobj)
{
    Yaku* yaku = gobj->user_data;

    if (YAKU_FIELD_140(yaku) > 0) {
        YAKU_FIELD_140(yaku)--;
    }

    if ((YAKU_FLAGS_144_BITS(yaku).b7 && YAKU_FIELD_140(yaku) <= 0) ||
        YAKU_FLAGS_144_BITS(yaku).b6) {
        Yaku* yaku2;
        Kind41Param* param;
        s32 flag;

        yaku2 = gobj->user_data;
        param = YAKU_PARAM(yaku2, Kind41Param);
        flag = 0;
        YAKU_FIELD_140(yaku2) = *(s32*) ((u8*) param->motion_param + 0x10);
        YAKU_FLAGS_144_BITS(yaku2).b6 = flag;

        if (YAKU_FIELD_11C(yaku2) > 0) {
            kar_graudio_play_fgm_entry_id((u8*) yaku2 + 0x118, 0);
        }

        {
            f32 zero = lbl_805DF8E4;
            kar_gryaku_set_path_node_motion(yaku2, 1, param->path_nodes,
                                            param->motion_joint_index, 0, zero,
                                            lbl_805DF8E8, zero);
        }
    }
}

void kar_gryakurecoveryzone_create_stage_linked_kind42_ground_group_yaku(HSD_GObj* ground_gobj)
{
    HSD_GObj* gobj = kar_gryaku_create_yaku_from_main_kind(0x2A);
    kar_gryakurecoveryzone_init_stage_linked_kind42_ground_group_yaku(gobj, ground_gobj);
}

// NONMATCHING: the inner ground-list search still inverts one compare branch.
void kar_gryakurecoveryzone_init_stage_linked_kind42_ground_group_yaku(
    HSD_GObj* gobj, HSD_GObj* ground_gobj)
{
    s32 offset;
    Yaku* yaku = gobj->user_data;
    GroundGroupParam* param = YAKU_PARAM(yaku, GroundGroupParam);
    s32 i;

    YAKU_FIELD_130(yaku) = HSD_Alloc(param->ground_count * sizeof(HSD_GObj*));

    i = 0;
    offset = 0;
    while (i < param->ground_count) {
        s32 index = *(s32*) ((u8*) param->ground_indices + offset);
        s32 ground_index = 0;
        HSD_GObj* ground = hsdGObj_p_link_heads[8];

        while (ground != NULL) {
            if (index != ground_index) {
                ground = ground->next;
                ground_index++;
            } else {
                goto found_ground;
            }
        }

        __assert(kar_src_ground_h_804a6170, 0x96C, &lbl_805D6248);
        ground = NULL;

    found_ground:
        *(HSD_GObj**) ((u8*) YAKU_FIELD_130(yaku) + offset) = ground;
        i++;
        offset += 4;
    }

    {
        s32 flag = 0;

        YAKU_FIELD_134_S32(yaku) = flag;
        YAKU_FIELD_138(yaku) = (void*) flag;
        YAKU_FLAGS_13C_BITS(yaku).b7 = flag;
    }

    kar_gryakurecoveryzone_start_kind42_ground_group_idle_motion(gobj);
}

void kar_gryakurecoveryzone_destroy_kind42_ground_group_yaku(HSD_GObj* gobj)
{
    Yaku* yaku = gobj->user_data;
    HSD_Free(YAKU_FIELD_130(yaku));
}

void kar_gryakurecoveryzone_start_kind42_ground_group_idle_motion(HSD_GObj* gobj)
{
    Yaku* yaku = gobj->user_data;
    GroundGroupParam* param = YAKU_PARAM(yaku, GroundGroupParam);
    f32 zero = lbl_805DF8E4;

    YAKU_FIELD_134_S32(yaku) = param->joint_index;
    kar_gryaku_set_path_node_motion(yaku, 0, (void*) -1, -1, 0, zero, zero, zero);
}
