#include "functions.h"
#include <dolphin/types.h>
#include <kar/gm/gmlanmenu.h>
#include <kar/gr/graudio.h>
#include <kar/gr/grcoll.h>
#include <kar/gr/gryaku.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/random.h>

typedef struct Ground Ground;
typedef struct GroundJObjEntry GroundJObjEntry;
typedef struct Yaku Yaku;
typedef struct YakuParamLink YakuParamLink;
typedef struct WhispyParam WhispyParam;
typedef struct WhispyEditParam WhispyEditParam;
typedef struct FgmEntry FgmEntry;
typedef void (*GroundCallback)(void);

struct Ground {
    u8 pad_00[0x54];
    u8 collision_root[0x20];
    u8 pad_74[0x90];
    GroundJObjEntry* jobjs;
};

struct GroundJObjEntry {
    void* jobj;
    u8 pad_04[0x04];
};

struct FgmEntry {
    u8 pad_00[0x04];
    s32 count;
};

struct YakuParamLink {
    WhispyParam* param;
    u8 pad_04[0x10];
    void* fgm_param;
};

struct Yaku {
    void* owner;
    u8 pad_04[0x04];
    YakuParamLink* param_link;
    u8 pad_0C[0x10C];
    FgmEntry fgm_entry;
    u8 pad_120[0x10];
    void* collision;
    s32 hit_count;
    s32 wait_timer;
};

struct WhispyParam {
    s32 joint_index;
    void* idle_path_nodes;
    void* extra_path_nodes;
    void* damage_path_nodes;
    void* break_path_nodes;
    WhispyEditParam* edit;
};

struct WhispyEditParam {
    s32 hit_count;
    s32 wait_ex_motion_req_count_min;
    s32 wait_ex_motion_req_count_max;
};

#define WHISPY_ZERO lbl_805DFAE0
#define WHISPY_ONE lbl_805DFAE4

__declspec(section ".sdata2") extern const f32 WHISPY_ZERO;
__declspec(section ".sdata2") extern const f32 WHISPY_ONE;

void kar_gryakuwhispywoods_init_kind69_collision_wait_state(HSD_GObj* gobj,
                                                            HSD_GObj* ground_gobj);
void kar_gryakuwhispywoods_start_kind69_idle_motion(HSD_GObj* gobj);
void kar_gryakuwhispywoods_update_kind69_wait_random_extra_motion(HSD_GObj* gobj);
void kar_gryakuwhispywoods_update_kind69_return_idle_when_clear(HSD_GObj* gobj);
void kar_gryakuwhispywoods_update_kind69_reseed_extra_motion_when_clear(HSD_GObj* gobj);
s32 kar_gryakuwhispywoods_handle_kind69_grcoll_hit_damage(HSD_GObj* gobj,
                                                          void* root, s32 pass);
void fn_8010E098(void);
void kar_gryakuwhispywoods_create_stage_linked_catchzones(Ground* ground);

void kar_gryakuaudio_configure_fgm_track_from_joint(HSD_GObj* gobj,
                                                    s32 joint_index,
                                                    s32 use_yaku_anchor);
void kar_gryaku_set_path_node_motion(Yaku* yaku, s32 state, void* path_nodes,
                                     s32 joint_index, s32 arg4, f32 start,
                                     f32 end, f32 arg7);
s32 kar_lbairride__800549a0(void* jobj);
s32 kar_gryakulib_get_yaku_state_or_none(HSD_GObj* gobj);
s32 kar_grcoll__near_800d7b8c(void* root, s32 pass, void* collision);
s32 kar_gryakubreakcommon_resolve_break_credit_player(void* root);
void fn_8027AA74(s32 player);

GroundCallback kar_gryakuwhispywoods_kind69_callback_table[16] = {
    (GroundCallback) kar_gryakuwhispywoods_update_kind69_wait_random_extra_motion,
    NULL,
    NULL,
    NULL,
    (GroundCallback) kar_gryakuwhispywoods_update_kind69_return_idle_when_clear,
    NULL,
    NULL,
    NULL,
    (GroundCallback) kar_gryakuwhispywoods_update_kind69_reseed_extra_motion_when_clear,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

void* kar_gryakuwhispywoods_kind69_callback_table_ptr[5] = {
    kar_gryakuwhispywoods_kind69_callback_table,
    kar_gryakuwhispywoods_handle_kind69_grcoll_hit_damage,
    NULL,
    NULL,
    NULL,
};

char kar_src_gryakuwhispywoods_c[0x14] = "gryakuwhispywoods.c";
char kar_gryakuwhispywoods_assert_wait_ex_motion_req_count_range[0x50] =
    "param->edit->waitExMotionReqCountMax > param->edit->waitExMotionReqCountMin";

void kar_gryakuwhispywoods_init_kind69_collision_wait_state(HSD_GObj* gobj,
                                                            HSD_GObj* ground_gobj)
{
    Yaku* yaku = gobj->user_data;
    Ground* ground_data = ground_gobj->user_data;
    WhispyParam* param = yaku->param_link->param;

    yaku->collision =
        kar_grcoll__800d7954(&kar_gryaku_current_ground->collision_root,
                             ground_data->jobjs[param->joint_index].jobj);
    *(void**) ((u8*) yaku->collision + 0x90) = yaku->owner;

    if (param->edit->wait_ex_motion_req_count_max <=
        param->edit->wait_ex_motion_req_count_min) {
        __assert(kar_src_gryakuwhispywoods_c, 0x61,
                 kar_gryakuwhispywoods_assert_wait_ex_motion_req_count_range);
    }

    yaku->hit_count = param->edit->hit_count;
    yaku->wait_timer =
        param->edit->wait_ex_motion_req_count_min +
        HSD_Randi(param->edit->wait_ex_motion_req_count_max -
                  param->edit->wait_ex_motion_req_count_min + 1);

    if (yaku->param_link->fgm_param != NULL) {
        kar_gryakuaudio_configure_fgm_track_from_joint(gobj, param->joint_index, 0);
    }

    kar_gryakuwhispywoods_start_kind69_idle_motion(gobj);
}

void kar_gryakuwhispywoods_start_kind69_idle_motion(HSD_GObj* gobj)
{
    Yaku* yaku = gobj->user_data;
    WhispyParam* param = yaku->param_link->param;
    f32 zero = WHISPY_ZERO;

    kar_gryaku_set_path_node_motion(yaku, 0, param->idle_path_nodes,
                                    param->joint_index, 0, zero, WHISPY_ONE,
                                    zero);
}

void kar_gryakuwhispywoods_update_kind69_wait_random_extra_motion(HSD_GObj* gobj)
{
    Yaku* yaku = gobj->user_data;
    WhispyParam* param = yaku->param_link->param;
    Ground* ground = kar_gryaku_current_ground;
    void* jobj = ground->jobjs[param->joint_index].jobj;

    if (kar_gmlanmenu__near_800547e0(jobj) == 0 &&
        kar_lbairride__800549a0(jobj) == 0) {
        yaku->wait_timer--;

        if (yaku->wait_timer <= 0) {
            Yaku* yaku2;
            WhispyParam* param2;
            f32 zero;

            yaku2 = gobj->user_data;
            param2 = yaku2->param_link->param;
            yaku2->wait_timer =
                param2->edit->wait_ex_motion_req_count_min +
                HSD_Randi(param2->edit->wait_ex_motion_req_count_max -
                          param2->edit->wait_ex_motion_req_count_min + 1);

            zero = WHISPY_ZERO;
            kar_gryaku_set_path_node_motion(yaku2, 1, param2->extra_path_nodes,
                                            param2->joint_index, 0, zero,
                                            WHISPY_ONE, zero);
        } else {
            f32 zero = WHISPY_ZERO;

            yaku = gobj->user_data;
            param = yaku->param_link->param;
            kar_gryaku_set_path_node_motion(yaku, 0, param->idle_path_nodes,
                                            param->joint_index, 0, zero,
                                            WHISPY_ONE, zero);
        }
    }
}

void kar_gryakuwhispywoods_update_kind69_return_idle_when_clear(HSD_GObj* gobj)
{
    Yaku* yaku = gobj->user_data;
    WhispyParam* param = yaku->param_link->param;
    Ground* ground = kar_gryaku_current_ground;
    void* jobj = ground->jobjs[param->joint_index].jobj;

    if (kar_gmlanmenu__near_800547e0(jobj) == 0 &&
        kar_lbairride__800549a0(jobj) == 0) {
        f32 zero = WHISPY_ZERO;

        yaku = gobj->user_data;
        param = yaku->param_link->param;
        kar_gryaku_set_path_node_motion(yaku, 0, param->idle_path_nodes,
                                        param->joint_index, 0, zero,
                                        WHISPY_ONE, zero);
    }
}

void kar_gryakuwhispywoods_update_kind69_reseed_extra_motion_when_clear(HSD_GObj* gobj)
{
    WhispyParam* param;
    Yaku* yaku;
    Ground* ground = kar_gryaku_current_ground;
    void* jobj;

    yaku = gobj->user_data;
    param = yaku->param_link->param;
    jobj = ground->jobjs[param->joint_index].jobj;

    if (kar_gmlanmenu__near_800547e0(jobj) == 0 &&
        kar_lbairride__800549a0(jobj) == 0) {
        f32 zero;

        yaku = gobj->user_data;
        param = yaku->param_link->param;
        yaku->wait_timer =
            param->edit->wait_ex_motion_req_count_min +
            HSD_Randi(param->edit->wait_ex_motion_req_count_max -
                      param->edit->wait_ex_motion_req_count_min + 1);

        zero = WHISPY_ZERO;
        kar_gryaku_set_path_node_motion(yaku, 1, param->extra_path_nodes,
                                        param->joint_index, 0, zero,
                                        WHISPY_ONE, zero);
    }
}

s32 kar_gryakuwhispywoods_handle_kind69_grcoll_hit_damage(HSD_GObj* gobj,
                                                          void* root, s32 pass)
{
    Yaku* yaku = gobj->user_data;
    s32 state = kar_gryakulib_get_yaku_state_or_none(gobj);

    if (state == 0 || state == 1) {
        if (kar_grcoll__near_800d7b8c(root, pass, yaku->collision) != 0) {
            return 0;
        }

        yaku->hit_count--;
        if (yaku->hit_count <= 0) {
            WhispyParam* param2;
            Yaku* yaku2;
            f32 zero;

            fn_8027AA74(kar_gryakubreakcommon_resolve_break_credit_player(root));

            yaku2 = gobj->user_data;
            param2 = yaku2->param_link->param;
            if (yaku2->fgm_entry.count > 1) {
                kar_graudio_play_fgm_entry_id(&yaku2->fgm_entry, 1);
            }

            zero = WHISPY_ZERO;
            kar_gryaku_set_path_node_motion(yaku2, 3, param2->break_path_nodes,
                                            param2->joint_index, 0, zero,
                                            WHISPY_ONE, zero);
        } else {
            WhispyParam* param;
            f32 zero;

            yaku = gobj->user_data;
            param = yaku->param_link->param;
            if (yaku->fgm_entry.count > 0) {
                kar_graudio_play_fgm_entry_id(&yaku->fgm_entry, 0);
            }

            zero = WHISPY_ZERO;
            kar_gryaku_set_path_node_motion(yaku, 2, param->damage_path_nodes,
                                            param->joint_index, 0, zero,
                                            WHISPY_ONE, zero);
        }
    }

    return 0;
}

void fn_8010E098(void)
{
}

void kar_gryakuwhispywoods_create_stage_linked_catchzones(Ground* ground)
{
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 0);
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 1);
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 2);
}

GroundCallback lbl_804A7528[4] = {
    fn_8010E098,
    (GroundCallback) kar_gryakuwhispywoods_create_stage_linked_catchzones,
    NULL,
    NULL,
};

__declspec(section ".sdata2") const f32 lbl_805DFAE0 = 0.0F;
__declspec(section ".sdata2") const f32 lbl_805DFAE4 = 1.0F;
