#include "functions.h"
#include <kar/gr/granim.h>
#include <kar/gr/gryaku.h>
#include <sysdolphin/gobj.h>

typedef struct Ground Ground;
typedef struct GroundData GroundData;
typedef struct GroundIndiviParam GroundIndiviParam;
typedef struct GroundStageYakuObject GroundStageYakuObject;
typedef void (*GroundCallback)(void);
typedef void (*GrSwitchCallback)(s32 arg0, s32 stage_index);

__declspec(section ".sdata") extern GrSwitchCallback lbl_805D6358[];
__declspec(section ".sdata") extern GrSwitchCallback lbl_805D6360[];

struct GroundStageYakuObject {
    void* object;
    u8 pad_04[0x44];
};

struct Ground {
    u8 pad_0[0x08];
    GroundData* data;
    u8 pad_C[0x20C];
    GroundStageYakuObject stage_yaku_objects[1];
};

struct GroundData {
    u8 pad_0[0x08];
    GroundIndiviParam* indiviParam;
};

struct GroundIndiviParam {
    void* loopAnimAll;
    void* scriptAll;
};

void kar_grswitch__800e85a8(Ground* ground, GrSwitchCallback* callbacks,
                            s32 func_num);
void kar_gryakucommon_create_stage_linked_kind16_yaku(Ground* ground, s32 link);
void kar_gryakuinvisibleball_create_stage_linked_invisibleball_yaku(Ground* ground,
                                                                    s32 link);
void kar_gryakulighttunnel_create_stage_linked_kind52_pillar(Ground* ground,
                                                             s32 link);
void kar_gryakupillar_create_stage_linked_kind53_pillar_controller(Ground* ground,
                                                                   s32 link);
void kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor(Ground* ground,
                                                                     s32 link);
void kar_gryakuinvisibleball_trigger_hidden_collision_state(void* target,
                                                           s32 state);
void kar_gryakupillar_trigger_kind53_random_child_pillars(void* target,
                                                         s32 state);
s32 kar_gryakucommon_lookup_script_entry_value(void* script, s32 value);
void kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(Ground* ground,
                                                                   s32 unused,
                                                                   s32 index);
void kar_gryakurecoveryzone_create_stage_linked_kind42_ground_group_yaku(
    Ground* ground, s32 link);
void kar_gryakurotjumphill_create_stage_linked_rotjumphill_yaku(Ground* ground,
                                                                s32 link);
void kar_gryakurisingcube_create_stage_linked_cube_yaku(Ground* ground,
                                                        s32 link);
void kar_gryakurisingcube_trigger_cube_state_toggle(void* target);

void kar_grdesert1_init_loop_anim_and_switch_group(HSD_GObj* gobj);
void kar_grdesert1_create_main_stage_yaku_objects(Ground* ground);
void kar_grdesert1_trigger_invisibleball_by_stage_index(s32 state,
                                                        s32 stage_index);
void kar_grdesert1_trigger_pillar_controller_by_stage_index(s32 state,
                                                            s32 stage_index);
s32 kar_grdesert1_lookup_script_entry_value(s32 value);
void kar_grdesert1_init_recovery_area_switch_group(HSD_GObj* gobj);
void kar_grdesert1_create_recovery_zone_stage_yaku_objects(Ground* ground);
void kar_grdesert1_trigger_risingcube_by_stage_index(s32 unused,
                                                     s32 stage_index);

#define GET_PTR(base, offset) (*(void**) ((u8*) (base) + (offset)))

GroundCallback kar_grdesert1_main_callback_table[] = {
    (GroundCallback) kar_grdesert1_init_loop_anim_and_switch_group,
    (GroundCallback) kar_grdesert1_create_main_stage_yaku_objects,
    NULL,
};

void kar_grdesert1_init_loop_anim_and_switch_group(HSD_GObj* gobj)
{
    Ground* ground = gobj->user_data;
    GroundIndiviParam* indiviParam = ground->data->indiviParam;
    BOOL hasLoopAnim = FALSE;

    if (indiviParam != NULL && indiviParam->loopAnimAll != NULL) {
        hasLoopAnim = TRUE;
    }

    if (!hasLoopAnim) {
        __assert("grdesert1.c", 0x31, "indiviParam && indiviParam->loopAnimAll");
    }

    kar_granim__800dbe48(ground, indiviParam->loopAnimAll);
    kar_grswitch__800e85a8(ground, lbl_805D6358, 2);
}

void kar_grdesert1_create_main_stage_yaku_objects(Ground* ground)
{
    kar_gryakucommon_create_stage_linked_kind16_yaku(ground, 0);
    kar_gryakucommon_create_stage_linked_kind16_yaku(ground, 1);
    kar_gryakucommon_create_stage_linked_kind16_yaku(ground, 2);
    kar_gryakucommon_create_stage_linked_kind16_yaku(ground, 3);
    kar_gryakucommon_create_stage_linked_kind16_yaku(ground, 4);
    kar_gryakucommon_create_stage_linked_kind16_yaku(ground, 5);
    kar_gryakucommon_create_stage_linked_kind16_yaku(ground, 6);
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 7);
    kar_gryakuinvisibleball_create_stage_linked_invisibleball_yaku(ground, 8);
    kar_gryakulighttunnel_create_stage_linked_kind52_pillar(ground, 9);
    kar_gryakulighttunnel_create_stage_linked_kind52_pillar(ground, 10);
    kar_gryakulighttunnel_create_stage_linked_kind52_pillar(ground, 11);
    kar_gryakulighttunnel_create_stage_linked_kind52_pillar(ground, 12);
    kar_gryakulighttunnel_create_stage_linked_kind52_pillar(ground, 13);
    kar_gryakulighttunnel_create_stage_linked_kind52_pillar(ground, 14);
    kar_gryakulighttunnel_create_stage_linked_kind52_pillar(ground, 15);
    kar_gryakupillar_create_stage_linked_kind53_pillar_controller(ground, 16);
    kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor(ground, 17);
    kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor(ground, 18);
    kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor(ground, 19);
    kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor(ground, 20);
    kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor(ground, 21);
    kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor(ground, 22);
    kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor(ground, 23);
    kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor(ground, 24);
    kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor(ground, 25);
    kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor(ground, 26);
    kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor(ground, 27);
    kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor(ground, 28);
    kar_gryakuanimfloor_create_stage_linked_kind24_breakcoral_floor(ground, 29);
}

void kar_grdesert1_trigger_invisibleball_by_stage_index(s32 state,
                                                        s32 stage_index)
{
    kar_gryakuinvisibleball_trigger_hidden_collision_state(
        kar_gryaku_current_ground->stage_yaku_objects[stage_index].object,
        state);
}

void kar_grdesert1_trigger_pillar_controller_by_stage_index(s32 state,
                                                            s32 stage_index)
{
    kar_gryakupillar_trigger_kind53_random_child_pillars(
        kar_gryaku_current_ground->stage_yaku_objects[stage_index].object,
        state);
}

s32 kar_grdesert1_lookup_script_entry_value(s32 value)
{
    Ground* ground = kar_gryaku_current_ground;
    void* script = ground->data->indiviParam->scriptAll;

    if (script != NULL) {
        return kar_gryakucommon_lookup_script_entry_value(script, value);
    }

    return 0;
}

__declspec(section ".sdata") GrSwitchCallback lbl_805D6358[] = {
    kar_grdesert1_trigger_invisibleball_by_stage_index,
    kar_grdesert1_trigger_pillar_controller_by_stage_index,
};

GroundCallback kar_grdesert1_recovery_callback_table[] = {
    (GroundCallback) kar_grdesert1_init_recovery_area_switch_group,
    (GroundCallback) kar_grdesert1_create_recovery_zone_stage_yaku_objects,
    NULL,
    NULL,
};

void kar_grdesert1_init_recovery_area_switch_group(HSD_GObj* gobj)
{
    kar_grswitch__800e85a8(gobj->user_data, lbl_805D6360, 1);
}

void kar_grdesert1_create_recovery_zone_stage_yaku_objects(Ground* ground)
{
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 0, 0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 1, 0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 2, 0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 3, 0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 4, 0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 5, 0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 6, 0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 7, 0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 8, 0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 9, 0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 10, 0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 11, 0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 12, 0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 13, 0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 14, 0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 15, 0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 16, 0);
    kar_gryakurecoveryzone_create_stage_indexed_kind41_joint_yaku(ground, 17, 0);
    kar_gryakurecoveryzone_create_stage_linked_kind42_ground_group_yaku(ground, 18);
    kar_gryakurotjumphill_create_stage_linked_rotjumphill_yaku(ground, 19);
    kar_gryakurotjumphill_create_stage_linked_rotjumphill_yaku(ground, 20);
    kar_gryakurisingcube_create_stage_linked_cube_yaku(ground, 21);
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 22);
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 23);
}

void kar_grdesert1_trigger_risingcube_by_stage_index(s32 unused, s32 stage_index)
{
    u8* stage_object = (u8*) kar_gryaku_current_ground;

    stage_object += stage_index * 0x48;
    kar_gryakurisingcube_trigger_cube_state_toggle(GET_PTR(stage_object, 0x218));
}

__declspec(section ".sdata") GrSwitchCallback lbl_805D6360[] = {
    kar_grdesert1_trigger_risingcube_by_stage_index,
    NULL,
};
