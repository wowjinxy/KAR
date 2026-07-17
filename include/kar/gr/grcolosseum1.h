#ifndef KAR_GR_GRCOLOSSEUM1_H
#define KAR_GR_GRCOLOSSEUM1_H

#include <dolphin/types.h>

struct Ground;
struct _HSD_GObj;

extern void* kar_grcolosseum1_main_callback_table[3];
extern void* kar_grcolosseum1_effect_9c47_callback_table[4];
extern void* kar_grcolosseum1_pointstrike_callback_table[4];
extern void* kar_grcolosseum1_risingcube_controller_callback_table[4];
extern void* kar_grcolosseum1_arealight_recovery_callback_table[4];
extern void* kar_grcolosseum1_airflow_and_yaku_callback_table[3];
extern void* kar_grcolosseum1_airflow_switch_callback_table[7];

void kar_grcolosseum1_init_course_dependent_common_setup_list(
    struct _HSD_GObj* gobj);
void kar_grcolosseum1_create_course19_kind23_breakhouse_pair(
    struct Ground* ground);
void kar_grcolosseum1_request_effect_9c47_at_configured_joint(
    struct _HSD_GObj* gobj);
void kar_grcolosseum1_init_pointstrike_panel_handles(struct _HSD_GObj* gobj);
void kar_grcolosseum1_init_risingcube_controller_switch_group(
    struct _HSD_GObj* gobj);
void kar_grcolosseum1_create_risingcube_pair_and_controller(
    struct Ground* ground);
void kar_grcolosseum1_update_risingcube_controller_targets_by_stage_index(
    struct _HSD_GObj* gobj, s32 stage_index);
void kar_grcolosseum1_init_two_area_light_users(struct _HSD_GObj* gobj);
void kar_grcolosseum1_create_kind41_recovery_joint_index0(
    struct Ground* ground);
void kar_grcolosseum1_create_external_airflow_shapes(struct _HSD_GObj* gobj);
void kar_grcolosseum1_init_airflow_slots_and_switch_group(
    struct _HSD_GObj* gobj);
void kar_grcolosseum1_create_stage_colosseum_yaku_objects(
    struct Ground* ground);
void kar_grcolosseum1_switch0_trigger_risingcube_by_stage_index(
    struct _HSD_GObj* gobj, s32 stage_index);
void kar_grcolosseum1_switch1_trigger_risingcube_by_stage_index(
    struct _HSD_GObj* gobj, s32 stage_index);
void kar_grcolosseum1_switch5_trigger_lasergate_ctrl_open_by_stage_index(
    struct _HSD_GObj* gobj, s32 stage_index);

#endif
