#include "functions.h"
#include <kar/gr/graudio.h>
#include <kar/gr/gryaku.h>
#include <sysdolphin/gobj.h>

#define GRICE1_FGM_COUNTER_NUM 10
#ifdef VERSION_GKYP01
#define GRICE1_ASSERT_FGM_COUNT_LINE 64
#else
#define GRICE1_ASSERT_FGM_COUNT_LINE 60
#endif

typedef struct Ground Ground;
typedef struct GroundData GroundData;
typedef struct GroundIceParam GroundIceParam;
typedef struct IndividualFgmAll IndividualFgmAll;
typedef struct IndividualFgmParam IndividualFgmParam;
typedef void (*GroundCallback)(void);
typedef void (*GrSwitchCallback)(HSD_GObj* gobj, s32 ref_id);

struct Ground {
    u8 pad_0[0x08];
    GroundData* data;
    u8 pad_C[0x71C];
    s32 fgm_counters[GRICE1_FGM_COUNTER_NUM];
};

struct GroundData {
    u8 pad_0[0x08];
    GroundIceParam* ice_param;
};

struct GroundIceParam {
    IndividualFgmAll* indiviFgmAll;
};

struct IndividualFgmParam {
    u8 pad_0[0x08];
    s32 initial_counter;
    u8 pad_C[0x04];
};

struct IndividualFgmAll {
    IndividualFgmParam* params;
    s32 indiviFgmNum;
};

typedef struct GrIce1CallbackTable {
    GroundCallback callbacks[6];
    char file[0x0C];
    char assert_indivi_fgm_count[0x44];
} GrIce1CallbackTable;

void kar_grswitch__800e85a8(Ground* ground, GrSwitchCallback* callbacks,
                            s32 func_num);
void kar_gryakupushoutwall_create_stage_linked_kind49_wall(Ground* ground,
                                                           s32 link);
void kar_gryakupushoutwall_create_stage_linked_kind50_switch_controller(
    Ground* ground, s32 link);
void kar_gryakupushoutwall_create_stage_linked_kind51_lightzone_controller(
    Ground* ground, s32 link);
void kar_gryakucatchzone_create_stage_linked_kind19_yaku(Ground* ground,
                                                         s32 link);
void kar_gryakubreakhouse_create_stage_linked_kind54_animfloor(Ground* ground,
                                                               s32 link);
void kar_gryakubreakcommon_create_stage_linked_kind57_lasergate(Ground* ground,
                                                                s32 link);
void kar_gryakubreakcommon_create_stage_linked_kind58_lasergate_ctrl(
    Ground* ground, s32 link);
void kar_gryakulasergate_create_stage_linked_kind32_breakfloor(Ground* ground,
                                                               s32 link);
void kar_gryakubreakcoral_create_stage_linked_kind31_breakicicle(Ground* ground,
                                                                 s32 link);
void kar_gryakupillar_create_stage_linked_kind39_ice_pillar(Ground* ground,
                                                            s32 link);
void kar_gryakupushoutwall_trigger_kind50_target_wall_pushes(void* target);
void kar_gryakulighttunnel_trigger_kind52_pillar_entry_motion(void* target);
void kar_gryakulasergate_trigger_kind58_ctrl_open_linked_gates(void* target);

void kar_grice1_init_switch_group_and_individual_fgm_ids(HSD_GObj* gobj);
void kar_grice1_create_stage_ice_yaku_objects(Ground* ground);
void kar_grice1_update_individual_fgm_timers(HSD_GObj* gobj);
void kar_grice1_switch_trigger_pushoutwall_targets_by_stage_index(HSD_GObj* gobj,
                                                                  s32 stage_index);
void kar_grice1_switch_trigger_lighttunnel_pillar_entry_by_stage_index(
    HSD_GObj* gobj, s32 stage_index);
void kar_grice1_switch_trigger_lasergate_ctrl_open_by_stage_index(
    HSD_GObj* gobj, s32 stage_index);

#define GET_PTR(base, offset) (*(void**) ((u8*) (base) + (offset)))

GrIce1CallbackTable kar_grice1_callback_table = {
    {
        (GroundCallback) kar_grice1_init_switch_group_and_individual_fgm_ids,
        (GroundCallback) kar_grice1_create_stage_ice_yaku_objects,
        (GroundCallback) kar_grice1_update_individual_fgm_timers,
        (GroundCallback) kar_grice1_switch_trigger_pushoutwall_targets_by_stage_index,
        (GroundCallback) kar_grice1_switch_trigger_lighttunnel_pillar_entry_by_stage_index,
        (GroundCallback) kar_grice1_switch_trigger_lasergate_ctrl_open_by_stage_index,
    },
    "grice1.c",
    "indiviParam->indiviFgmAll->indiviFgmNum <= GrIce1_FgmCounterNum",
};

void kar_grice1_init_switch_group_and_individual_fgm_ids(HSD_GObj* gobj)
{
    GrIce1CallbackTable* table;
    Ground* ground;
    GroundIceParam* indiviParam;
    s32 i;

    table = &kar_grice1_callback_table;
    ground = gobj->user_data;
    indiviParam = ground->data->ice_param;
    kar_grswitch__800e85a8(ground, (GrSwitchCallback*) &table->callbacks[3],
                           3);

    if (indiviParam->indiviFgmAll->indiviFgmNum > GRICE1_FGM_COUNTER_NUM) {
        __assert(table->file, GRICE1_ASSERT_FGM_COUNT_LINE,
                 table->assert_indivi_fgm_count);
    }

    for (i = 0; i < indiviParam->indiviFgmAll->indiviFgmNum; i++) {
        ground->fgm_counters[i] =
            indiviParam->indiviFgmAll->params[i].initial_counter;
    }
}

void kar_grice1_create_stage_ice_yaku_objects(Ground* ground)
{
    kar_gryakupushoutwall_create_stage_linked_kind49_wall(ground, 0);
    kar_gryakupushoutwall_create_stage_linked_kind49_wall(ground, 1);
    kar_gryakupushoutwall_create_stage_linked_kind49_wall(ground, 2);
    kar_gryakupushoutwall_create_stage_linked_kind49_wall(ground, 3);
    kar_gryakupushoutwall_create_stage_linked_kind49_wall(ground, 4);
    kar_gryakupushoutwall_create_stage_linked_kind49_wall(ground, 5);
    kar_gryakupushoutwall_create_stage_linked_kind50_switch_controller(ground, 6);
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 7);
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 8);
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 9);
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 10);
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 11);
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 12);
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 13);
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 14);
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 15);
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 16);
    kar_gryakubreakhouse_create_stage_linked_kind54_animfloor(ground, 17);
    kar_gryakubreakhouse_create_stage_linked_kind54_animfloor(ground, 18);
    kar_gryakubreakhouse_create_stage_linked_kind54_animfloor(ground, 19);
    kar_gryakubreakcommon_create_stage_linked_kind57_lasergate(ground, 20);
    kar_gryakubreakcommon_create_stage_linked_kind57_lasergate(ground, 21);
    kar_gryakubreakcommon_create_stage_linked_kind57_lasergate(ground, 22);
    kar_gryakubreakcommon_create_stage_linked_kind57_lasergate(ground, 23);
    kar_gryakubreakcommon_create_stage_linked_kind58_lasergate_ctrl(ground, 24);
    kar_gryakulasergate_create_stage_linked_kind32_breakfloor(ground, 25);
    kar_gryakulasergate_create_stage_linked_kind32_breakfloor(ground, 26);
    kar_gryakulasergate_create_stage_linked_kind32_breakfloor(ground, 27);
    kar_gryakulasergate_create_stage_linked_kind32_breakfloor(ground, 28);
    kar_gryakulasergate_create_stage_linked_kind32_breakfloor(ground, 29);
    kar_gryakulasergate_create_stage_linked_kind32_breakfloor(ground, 30);
    kar_gryakubreakcoral_create_stage_linked_kind31_breakicicle(ground, 31);
    kar_gryakubreakcoral_create_stage_linked_kind31_breakicicle(ground, 32);
    kar_gryakubreakcoral_create_stage_linked_kind31_breakicicle(ground, 33);
    kar_gryakubreakcoral_create_stage_linked_kind31_breakicicle(ground, 34);
    kar_gryakubreakcoral_create_stage_linked_kind31_breakicicle(ground, 35);
    kar_gryakubreakcoral_create_stage_linked_kind31_breakicicle(ground, 36);
    kar_gryakupillar_create_stage_linked_kind39_ice_pillar(ground, 37);
    kar_gryakupillar_create_stage_linked_kind39_ice_pillar(ground, 38);
    kar_gryakupillar_create_stage_linked_kind39_ice_pillar(ground, 39);
    kar_gryakupillar_create_stage_linked_kind39_ice_pillar(ground, 40);
    kar_gryakupushoutwall_create_stage_linked_kind51_lightzone_controller(ground,
                                                                         41);
}

void kar_grice1_update_individual_fgm_timers(HSD_GObj* gobj)
{
    Ground* ground;
    GroundIceParam* indiviParam;

    ground = gobj->user_data;
    indiviParam = ground->data->ice_param;
    kar_graudio_configure_individual_fgm_tracks(ground,
                                                indiviParam->indiviFgmAll);
    kar_graudio_update_individual_fgm_timers(ground, indiviParam->indiviFgmAll,
                                             ground->fgm_counters,
                                             GRICE1_FGM_COUNTER_NUM);
}

void kar_grice1_switch_trigger_pushoutwall_targets_by_stage_index(HSD_GObj* gobj,
                                                                  s32 stage_index)
{
    void* target = GET_PTR(kar_gryaku_current_ground, 0x218 + stage_index * 0x48);

    if (target != NULL) {
        kar_gryakupushoutwall_trigger_kind50_target_wall_pushes(target);
    }
}

void kar_grice1_switch_trigger_lighttunnel_pillar_entry_by_stage_index(
    HSD_GObj* gobj, s32 stage_index)
{
    void* target = GET_PTR(kar_gryaku_current_ground, 0x218 + stage_index * 0x48);

    if (target != NULL) {
        kar_gryakulighttunnel_trigger_kind52_pillar_entry_motion(target);
    }
}

void kar_grice1_switch_trigger_lasergate_ctrl_open_by_stage_index(
    HSD_GObj* gobj, s32 stage_index)
{
    void* target = GET_PTR(kar_gryaku_current_ground, 0x218 + stage_index * 0x48);

    if (target != NULL) {
        kar_gryakulasergate_trigger_kind58_ctrl_open_linked_gates(target);
    }
}
