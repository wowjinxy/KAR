#include "functions.h"
#include <dolphin/mtx/vec.h>
#include <kar/gr/grcolosseum1.h>
#include <kar/gr/gryaku.h>
#include <sysdolphin/gobj.h>

typedef struct Ground Ground;
typedef struct GroundData GroundData;
typedef void (*GroundCallback)(void);
typedef void (*GrSwitchCallback)(HSD_GObj* gobj, s32 stage_index);

struct Ground {
    u8 pad_00[0x08];
    GroundData* data;
    u8 pad_0C[0xF8];
    void** jobjs;
    u8 pad_108[0x620];
    HSD_GObj* external_airflows[8];
    s32 external_airflow_count;
};

struct GroundData {
    u8 pad_00[0x08];
    void* indiviParam;
};

#define GET_PTR(base, offset) (*(void**) ((u8*) (base) + (offset)))
#define GET_S32(base, offset) (*(s32*) ((u8*) (base) + (offset)))

extern s32 fn_80261ECC(void);
extern void kar_grcommon__near_800db774(Ground* ground, void* entry);
extern void kar_efrequest__80236c40(HSD_GObj* gobj, s32 effect_id, s32 arg2,
                                    s32 arg3, void* jobj, ...);
extern void kar_grpointstrike_init_panel_handles(Ground* ground);
extern void kar_grswitch__800e85a8(Ground* ground, GrSwitchCallback* callbacks,
                                   s32 func_num);
extern void kar_lbarealightuser__near_8007a958(void* user);
extern HSD_GObj* kar_grairflow_create_external_gobj(HSD_GObj* gobj);
extern void kar_grairflow_set_external_point(HSD_GObj* gobj, Vec* pos);
extern void kar_grairflow_set_external_segment_radial(HSD_GObj* gobj,
                                                      Vec* pos, Vec* dir);
extern void kar_grairflow_set_external_segment_directional(HSD_GObj* gobj,
                                                           Vec* pos, Vec* dir);
extern void kar_grairflow_set_external_linked_segment(HSD_GObj* gobj,
                                                      Vec* pos, Vec* dir);
extern void kar_grairflow_set_point_strength_range(HSD_GObj* gobj, f32 min,
                                                   f32 max);
extern void kar_grairflow_set_segment_radial_strength_range(HSD_GObj* gobj,
                                                            f32 min, f32 max);
extern void kar_grairflow_set_segment_directional_strength_range(HSD_GObj* gobj,
                                                                 f32 min,
                                                                 f32 max);
extern void kar_grairflow_set_linked_segment_strength_range(HSD_GObj* gobj,
                                                            f32 min, f32 max);
extern void kar_grairflow_set_point_radius(HSD_GObj* gobj, f32 radius);
extern void kar_grairflow_set_segment_radial_radius(HSD_GObj* gobj,
                                                    f32 radius);
extern void kar_grairflow_set_segment_directional_radius(HSD_GObj* gobj,
                                                         f32 radius);
extern void kar_grairflow_set_linked_segment_radius(HSD_GObj* gobj,
                                                    f32 radius);
extern void kar_gryakucommon_create_stage_linked_kind16_yaku(Ground* ground,
                                                             s32 link);
extern void kar_gryakudownforcezone_create_stage_linked_kind17_yaku(
    Ground* ground, s32 link);
extern void kar_gryakurecoveryzone_create_stage_linked_recoveryzone_yaku(
    Ground* ground, s32 link);
extern void kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(
    Ground* ground, s32 link, s32 index);
extern void kar_gryakurecoveryzone_create_stage_linked_kind42_ground_group_yaku(
    Ground* ground, s32 link);
extern void kar_gryakurisingcube_create_stage_linked_cube_yaku(Ground* ground,
                                                               s32 link);
extern void kar_gryakurisingcube_create_stage_linked_controller_yaku(
    Ground* ground, s32 link);
extern void kar_gryakurisingcube_update_controller_target_groups(void* target);
extern void kar_gryakurisingcube_trigger_cube_state_toggle(void* target);
extern void kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(
    Ground* ground, s32 link);
extern void kar_gryakugondola_create_stage_linked_kind48_route_yaku(
    Ground* ground, s32 link);
extern void kar_gryakubreakhouse_create_colosseum_kind23_breakhouse(
    Ground* ground, s32 link);
extern void kar_gryakubreakhouse_create_stage_linked_kind54_animfloor(
    Ground* ground, s32 link);
extern void kar_gryakuanimfloor_create_stage_linked_kind55_reactive_floor(
    Ground* ground, s32 link);
extern void kar_gryakubreakcommon_create_stage_linked_kind56_delayed_collision(
    Ground* ground, s32 link);
extern void kar_gryakubreakcommon_create_stage_linked_kind57_lasergate(
    Ground* ground, s32 link);
extern void kar_gryakubreakcommon_create_stage_linked_kind58_lasergate_ctrl(
    Ground* ground, s32 link);
extern void kar_gryakubreakrock_create_colosseum_kind22_breakrock(
    Ground* ground, s32 link);
extern void kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor(
    Ground* ground, s32 link);
extern void kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(
    Ground* ground, s32 link);
extern void kar_gryakubreakcoll_create_stage_linked_kind33_breakcoll(
    Ground* ground, s32 link);
extern void kar_gryakubreakcoll_create_stage_linked_kind34_breakcoll(
    Ground* ground, s32 link);
extern void kar_gryakubreakhpcoll_create_stage_linked_kind38_breakhpcoll_house(
    Ground* ground, s32 link);

void fn_8010FAA8(void);
void fn_8010FAAC(void);
void fn_8010FAB0(void);
void fn_8010FAB4(void);
void fn_8010FADC(void);
void fn_8010FB84(void);
void fn_8010FB88(void);
void fn_8010FB8C(void);
void fn_8010FB90(void);
void fn_801100E4(void);
void fn_80110148(void);
void fn_8011014C(void);
void fn_80110150(void);
void event_dynablade_start(void* event);
void event_dynablade(void* event);
void event_dynablade_end(void);
void event_dynablade_end2(void* event);
void event_tac_start(void* event);
void event_tac(void* event);
void event_tac_end(void);
void event_tac_end2(void* event);
f32 kar_grcolosseum1_get_event_kind4e_spawn_scaled_angle(f32 angle);
void kar_grcolosseum1_get_event_kind4e_spawn_vector(s32 index, Vec* pos,
                                                    Vec* dir, Vec* scale);
void kar_grcolosseum1_event_kind4e_build_weighted_spawn_pattern(void* event);
void event_meteor_start(void* event);
void event_meteor(void* event);
void event_meteor_end(void);
void event_meteor_end2(void* event);
void event_runAmok_start(void* event);
void event_runAmok(void* event);
void event_runAmok_end(void);
void event_runAmok_end2(void);
void event_restorationAreas_start(void* event);
void event_pillar_start(void* event);

const Vec lbl_80489E60 = { 0.0f, 15.0f, 0.0f };
const Vec lbl_80489E6C = { 0.0f, 15.0f, 0.0f };
const u32 lbl_80489E78[4] = { 0x2E87FF00, 0x00CF0000, 0xFFC30000,
                              0xFF000000 };
const f32 lbl_80489E88[4] = { 0.0f, 15.0f, 45.0f, 0.0f };
const Vec lbl_80489E98 = { 1.15f, 1.15f, 1.15f };
const Vec lbl_80489EA4 = { 1.0f, 1.0f, 1.0f };
const Vec lbl_80489EB0 = { 0.0f, 0.0f, -1.0f };
const Vec lbl_80489EBC = { -1.0f, 0.0f, 0.0f };
const Vec lbl_80489EC8 = { 0.0f, 0.0f, -1.0f };
const Vec lbl_80489ED4 = { -1.0f, 0.0f, 0.0f };

void* kar_grcolosseum1_main_callback_table[3] = {
    kar_grcolosseum1_init_course_dependent_common_setup_list,
    kar_grcolosseum1_create_course19_kind23_breakhouse_pair,
    NULL,
};

char kar_src_grcolosseum1_c[0x0F] = "grcolosseum1.c";

void* kar_grcolosseum1_effect_9c47_callback_table[4] = {
    kar_grcolosseum1_request_effect_9c47_at_configured_joint,
    NULL,
    NULL,
    NULL,
};

void* lbl_804A78D8[4] = { fn_8010FAA8, fn_8010FAAC, NULL, NULL };
void* lbl_804A78E8[4] = { fn_8010FAB0, NULL, NULL, NULL };

void* kar_grcolosseum1_pointstrike_callback_table[4] = {
    fn_8010FAB4,
    kar_grcolosseum1_init_pointstrike_panel_handles,
    NULL,
    NULL,
};

void* lbl_804A7908[4] = { fn_8010FADC, NULL, NULL, NULL };

void* kar_grcolosseum1_risingcube_controller_callback_table[4] = {
    kar_grcolosseum1_init_risingcube_controller_switch_group,
    kar_grcolosseum1_create_risingcube_pair_and_controller,
    NULL,
    NULL,
};

void* lbl_804A7928[4] = { fn_8010FB84, NULL, NULL, NULL };
void* lbl_804A7938[4] = { fn_8010FB88, NULL, NULL, NULL };
void* lbl_804A7948[4] = { fn_8010FB8C, NULL, NULL, NULL };
void* lbl_804A7958[4] = { fn_8010FB90, NULL, NULL, NULL };

void* kar_grcolosseum1_arealight_recovery_callback_table[4] = {
    kar_grcolosseum1_init_two_area_light_users,
    kar_grcolosseum1_create_kind41_recovery_joint_index0,
    NULL,
    NULL,
};

void* kar_grcolosseum1_airflow_and_yaku_callback_table[3] = {
    kar_grcolosseum1_init_airflow_slots_and_switch_group,
    kar_grcolosseum1_create_stage_colosseum_yaku_objects,
    fn_801100E4,
};

void* kar_grcolosseum1_airflow_switch_callback_table[7] = {
    kar_grcolosseum1_switch0_trigger_risingcube_by_stage_index,
    kar_grcolosseum1_switch1_trigger_risingcube_by_stage_index,
    fn_80110148,
    fn_8011014C,
    fn_80110150,
    kar_grcolosseum1_switch5_trigger_lasergate_ctrl_open_by_stage_index,
    NULL,
};

u8 kar_grcolosseum1_event_position_order_buffer[0x18];
u8 kar_grcolosseum1_kind4e_pattern_state_allocator[0x30];

__declspec(section ".sdata") char lbl_805D6378[8] = "0";
__declspec(section ".sdata") GrSwitchCallback lbl_805D6380[2] = {
    kar_grcolosseum1_update_risingcube_controller_targets_by_stage_index,
    NULL,
};

__declspec(section ".sdata2") const f32 lbl_805DFAE8 = 420.0f;
__declspec(section ".sdata2") const f32 lbl_805DFAEC = 2.0f;
__declspec(section ".sdata2") const f32 lbl_805DFAF0 = 1.0f;
__declspec(section ".sdata2") const f32 lbl_805DFAF4 = 15.0f;
__declspec(section ".sdata2") const f32 lbl_805DFAF8 = 390.0f;
__declspec(section ".sdata2") const f32 lbl_805DFAFC = 330.0f;
__declspec(section ".sdata2") const f32 lbl_805DFB00 = 360.0f;
__declspec(section ".sdata2") const f32 lbl_805DFB04 = 240.0f;
__declspec(section ".sdata2") const f32 lbl_805DFB08 = 280.0f;
__declspec(section ".sdata2") const f32 lbl_805DFB0C = 200.0f;
__declspec(section ".sdata2") const f32 lbl_805DFB10 = 0.0f;
__declspec(section ".sdata2") const f32 lbl_805DFB14 = 1.0f;
__declspec(section ".sdata2") const f64 lbl_805DFB18 = 6.283185307179586;
__declspec(section ".sdata2") const f32 lbl_805DFB20[2] = { -1.0f, 0.0f };

void kar_grcolosseum1_init_course_dependent_common_setup_list(HSD_GObj* gobj)
{
    s32 offset;
    s32 i;
    GroundData* data;
    Ground* ground;
    u8* param;

    ground = gobj->user_data;
    data = ground->data;
    param = data->indiviParam;

    switch (fn_80261ECC()) {
    case 0x13:
        for (i = 0, offset = 0; i < GET_S32(param, 0x0C);
             offset += sizeof(void*), i++) {
            kar_grcommon__near_800db774(
                ground, GET_PTR(GET_PTR(param, 0x08), offset));
        }
        break;
    case 0x21:
        for (i = 0, offset = 0; i < GET_S32(param, 0x04);
             offset += sizeof(void*), i++) {
            kar_grcommon__near_800db774(
                ground, GET_PTR(GET_PTR(param, 0x00), offset));
        }
        break;
    default:
        __assert(kar_src_grcolosseum1_c, 0x43, lbl_805D6378);
        break;
    }
}

void kar_grcolosseum1_create_course19_kind23_breakhouse_pair(Ground* ground)
{
    if (fn_80261ECC() == 0x13) {
        kar_gryakubreakhouse_create_colosseum_kind23_breakhouse(ground, 0);
        kar_gryakubreakhouse_create_colosseum_kind23_breakhouse(ground, 1);
    }
}

void kar_grcolosseum1_request_effect_9c47_at_configured_joint(HSD_GObj* gobj)
{
    Ground* ground = gobj->user_data;
    u8* param = ground->data->indiviParam;
    void* jobj = GET_PTR(ground->jobjs, GET_S32(param, 0x00) * 8);

    kar_efrequest__80236c40(gobj, 0x9C47, 4, 0xCF, jobj);
}

void fn_8010FAA8(void) {}
void fn_8010FAAC(void) {}
void fn_8010FAB0(void) {}
void fn_8010FAB4(void) {}

void kar_grcolosseum1_init_pointstrike_panel_handles(HSD_GObj* gobj)
{
    kar_grpointstrike_init_panel_handles(gobj->user_data);
}

void fn_8010FADC(void) {}

void kar_grcolosseum1_init_risingcube_controller_switch_group(HSD_GObj* gobj)
{
    kar_grswitch__800e85a8(gobj->user_data, lbl_805D6380, 1);
}

void kar_grcolosseum1_create_risingcube_pair_and_controller(Ground* ground)
{
    kar_gryakurisingcube_create_stage_linked_cube_yaku(ground, 0);
    kar_gryakurisingcube_create_stage_linked_cube_yaku(ground, 1);
    kar_gryakurisingcube_create_stage_linked_controller_yaku(ground, 2);
}

void kar_grcolosseum1_update_risingcube_controller_targets_by_stage_index(
    HSD_GObj* gobj, s32 stage_index)
{
    u8* stage_object = (u8*) kar_gryaku_current_ground;

    stage_object += stage_index * 0x48;
    kar_gryakurisingcube_update_controller_target_groups(
        GET_PTR(stage_object, 0x218));
}

void fn_8010FB84(void) {}
void fn_8010FB88(void) {}
void fn_8010FB8C(void) {}
void fn_8010FB90(void) {}

void kar_grcolosseum1_init_two_area_light_users(HSD_GObj* gobj)
{
    u8* users = ((Ground*) gobj->user_data)->data->indiviParam;

    kar_lbarealightuser__near_8007a958(users);
    kar_lbarealightuser__near_8007a958(users + 0x50);
}

void kar_grcolosseum1_create_kind41_recovery_joint_index0(Ground* ground)
{
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 0, 1);
}

static void kar_grcolosseum1_store_external_airflow(Ground* ground,
                                                    HSD_GObj* airflow)
{
    ground->external_airflows[ground->external_airflow_count] = airflow;
}

static HSD_GObj* kar_grcolosseum1_current_external_airflow(Ground* ground)
{
    return ground->external_airflows[ground->external_airflow_count];
}

static void kar_grcolosseum1_advance_external_airflow(Ground* ground)
{
    ground->external_airflow_count++;
}

void kar_grcolosseum1_create_external_airflow_shapes(HSD_GObj* gobj)
{
    Ground* ground = gobj->user_data;
    Vec start = lbl_80489E60;
    Vec end = lbl_80489E6C;
    HSD_GObj* airflow;

    if (ground->external_airflow_count < 8) {
        airflow = kar_grairflow_create_external_gobj(gobj);
        kar_grcolosseum1_store_external_airflow(ground, airflow);
        start.z = lbl_805DFAE8;
        kar_grairflow_set_external_point(
            kar_grcolosseum1_current_external_airflow(ground), &start);
        kar_grairflow_set_point_strength_range(
            kar_grcolosseum1_current_external_airflow(ground), lbl_805DFAEC,
            lbl_805DFAF0);
        kar_grairflow_set_point_radius(
            kar_grcolosseum1_current_external_airflow(ground), lbl_805DFAF4);
        kar_grcolosseum1_advance_external_airflow(ground);
    }

    if (ground->external_airflow_count < 8) {
        airflow = kar_grairflow_create_external_gobj(gobj);
        kar_grcolosseum1_store_external_airflow(ground, airflow);
        start.z = lbl_805DFAF8;
        end.z = lbl_805DFAFC;
        kar_grairflow_set_external_segment_radial(
            kar_grcolosseum1_current_external_airflow(ground), &start, &end);
        kar_grairflow_set_segment_radial_strength_range(
            kar_grcolosseum1_current_external_airflow(ground), lbl_805DFAEC,
            lbl_805DFAF0);
        kar_grairflow_set_segment_radial_radius(
            kar_grcolosseum1_current_external_airflow(ground), lbl_805DFAF4);
        kar_grcolosseum1_advance_external_airflow(ground);
    }

    if (ground->external_airflow_count < 8) {
        airflow = kar_grairflow_create_external_gobj(gobj);
        kar_grcolosseum1_store_external_airflow(ground, airflow);
        start.z = lbl_805DFB00;
        end.z = lbl_805DFB04;
        kar_grairflow_set_external_segment_directional(
            kar_grcolosseum1_current_external_airflow(ground), &start, &end);
        kar_grairflow_set_segment_directional_strength_range(
            kar_grcolosseum1_current_external_airflow(ground), lbl_805DFAEC,
            lbl_805DFAF0);
        kar_grairflow_set_segment_directional_radius(
            kar_grcolosseum1_current_external_airflow(ground), lbl_805DFAF4);
        kar_grcolosseum1_advance_external_airflow(ground);
    }

    if (ground->external_airflow_count < 8) {
        airflow = kar_grairflow_create_external_gobj(gobj);
        kar_grcolosseum1_store_external_airflow(ground, airflow);
        start.z = lbl_805DFB08;
        end.z = lbl_805DFB0C;
        kar_grairflow_set_external_linked_segment(
            kar_grcolosseum1_current_external_airflow(ground), &start, &end);
        kar_grairflow_set_linked_segment_strength_range(
            kar_grcolosseum1_current_external_airflow(ground), lbl_805DFAF0,
            lbl_805DFAEC);
        kar_grairflow_set_linked_segment_radius(
            kar_grcolosseum1_current_external_airflow(ground), lbl_805DFAF4);
        kar_grcolosseum1_advance_external_airflow(ground);
    }
}

void kar_grcolosseum1_init_airflow_slots_and_switch_group(HSD_GObj* gobj)
{
    Ground* ground = gobj->user_data;
    s32 i;

    for (i = 0; i < 8; i++) {
        ground->external_airflows[i] = NULL;
    }
    ground->external_airflow_count = 0;

    kar_grswitch__800e85a8(ground,
                           (GrSwitchCallback*) kar_grcolosseum1_airflow_switch_callback_table,
                           6);
    kar_grcolosseum1_create_external_airflow_shapes(gobj);
}

void kar_grcolosseum1_create_stage_colosseum_yaku_objects(Ground* ground)
{
    kar_gryakucommon_create_stage_linked_kind16_yaku(ground, 0);
    kar_gryakudownforcezone_create_stage_linked_kind17_yaku(ground, 1);
    kar_gryakudownforcezone_create_stage_linked_kind17_yaku(ground, 2);
    kar_gryakucatchzone_create_stage_linked_kind18_yaku(ground, 3);
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 4);
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 5);
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 6);
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 7);
    kar_gryakurecoveryzone_create_stage_linked_recoveryzone_yaku(ground, 8);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 9, 0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 10,
                                                                  0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 11,
                                                                  0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 12,
                                                                  0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 13,
                                                                  0);
    kar_gryakurecoveryzone_create_stage_linked_kind42_ground_group_yaku(ground,
                                                                       14);
    kar_gryakurisingcube_create_stage_linked_cube_yaku(ground, 15);
    kar_gryakurisingcube_create_stage_linked_cube_yaku(ground, 16);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 17);
    kar_gryakugondola_create_stage_linked_kind48_route_yaku(ground, 18);
    kar_gryakubreakhouse_create_stage_linked_kind54_animfloor(ground, 19);
    kar_gryakubreakhouse_create_stage_linked_kind54_animfloor(ground, 20);
    kar_gryakuanimfloor_create_stage_linked_kind55_reactive_floor(ground, 21);
    kar_gryakubreakcommon_create_stage_linked_kind56_delayed_collision(ground,
                                                                       22);
    kar_gryakubreakcommon_create_stage_linked_kind57_lasergate(ground, 23);
    kar_gryakubreakcommon_create_stage_linked_kind58_lasergate_ctrl(ground, 24);
    kar_gryakulasergate_create_stage_linked_kind32_breakfloor(ground, 25);
    kar_gryakubreakcoral_create_stage_linked_kind31_breakicicle(ground, 26);
    kar_gryakubreakrock_create_colosseum_kind22_breakrock(ground, 27);
    kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor(ground, 28);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 29);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 30);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 31);
    kar_gryakubreakcoll_create_stage_linked_kind33_breakcoll(ground, 32);
    kar_gryakubreakcoll_create_stage_linked_kind34_breakcoll(ground, 33);
    kar_gryakubreakhpcoll_create_stage_linked_kind38_breakhpcoll_house(ground,
                                                                       34);
}

void fn_801100E4(void) {}

void kar_grcolosseum1_switch0_trigger_risingcube_by_stage_index(
    HSD_GObj* gobj, s32 stage_index)
{
    u8* stage_object = (u8*) kar_gryaku_current_ground;

    stage_object += stage_index * 0x48;
    kar_gryakurisingcube_trigger_cube_state_toggle(GET_PTR(stage_object, 0x218));
}

void kar_grcolosseum1_switch1_trigger_risingcube_by_stage_index(
    HSD_GObj* gobj, s32 stage_index)
{
    u8* stage_object = (u8*) kar_gryaku_current_ground;

    stage_object += stage_index * 0x48;
    kar_gryakurisingcube_trigger_cube_state_toggle(GET_PTR(stage_object, 0x218));
}

void fn_80110148(void) {}
void fn_8011014C(void) {}
void fn_80110150(void) {}

void kar_grcolosseum1_switch5_trigger_lasergate_ctrl_open_by_stage_index(
    HSD_GObj* gobj, s32 stage_index)
{
    u8* stage_object = (u8*) kar_gryaku_current_ground;

    stage_object += stage_index * 0x48;
    kar_gryakulasergate_trigger_kind58_ctrl_open_linked_gates(
        GET_PTR(stage_object, 0x218));
}

// NONMATCHING: event state machine not recovered yet.
void event_dynablade_start(void* event) {}

// NONMATCHING: event state machine not recovered yet.
void event_dynablade(void* event) {}

void event_dynablade_end(void) {}

// NONMATCHING: event state machine not recovered yet.
void event_dynablade_end2(void* event) {}

// NONMATCHING: event state machine not recovered yet.
void event_tac_start(void* event) {}

// NONMATCHING: event state machine not recovered yet.
void event_tac(void* event) {}

void event_tac_end(void) {}

// NONMATCHING: event state machine not recovered yet.
void event_tac_end2(void* event) {}

// NONMATCHING: event helper not recovered yet.
f32 kar_grcolosseum1_get_event_kind4e_spawn_scaled_angle(f32 angle)
{
    return angle;
}

// NONMATCHING: event helper not recovered yet.
void kar_grcolosseum1_get_event_kind4e_spawn_vector(s32 index, Vec* pos,
                                                    Vec* dir, Vec* scale)
{
}

// NONMATCHING: event helper not recovered yet.
void kar_grcolosseum1_event_kind4e_build_weighted_spawn_pattern(void* event) {}

// NONMATCHING: event state machine not recovered yet.
void event_meteor_start(void* event) {}

// NONMATCHING: event state machine not recovered yet.
void event_meteor(void* event) {}

void event_meteor_end(void) {}

// NONMATCHING: event state machine not recovered yet.
void event_meteor_end2(void* event) {}

// NONMATCHING: event state machine not recovered yet.
void event_runAmok_start(void* event) {}

// NONMATCHING: event state machine not recovered yet.
void event_runAmok(void* event) {}

void event_runAmok_end(void) {}
void event_runAmok_end2(void) {}

// NONMATCHING: event state machine not recovered yet.
void event_restorationAreas_start(void* event) {}

// NONMATCHING: event state machine not recovered yet.
void event_pillar_start(void* event) {}
