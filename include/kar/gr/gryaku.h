#ifndef KAR_GR_GRYAKU_H
#define KAR_GR_GRYAKU_H

#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>

struct Ground;
struct _HSD_GObj;

extern struct Ground* kar_gryaku_current_ground;

struct _HSD_GObj* kar_gryaku_create_yaku_from_main_kind(s32 kind);
void kar_gryakucatchzone_create_stage_linked_kind18_yaku(
    struct Ground* ground, s32 link);
void kar_gryakucatchzone_create_stage_linked_kind19_yaku(
    struct Ground* ground, s32 link);
void kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(
    struct Ground* ground, s32 link);
void kar_gryakugondola_create_stage_linked_kind47_ground_audio_yaku(
    struct Ground* ground, s32 link);
void kar_gryakugondola_create_stage_linked_kind48_route_yaku(
    struct Ground* ground, s32 link);
void kar_gryakubreakcoral_create_stage_linked_kind31_breakicicle(
    struct Ground* ground, s32 link);
void kar_gryakulasergate_create_stage_linked_kind32_breakfloor(
    struct Ground* ground, s32 link);
void kar_gryakupillar_create_stage_linked_kind39_ice_pillar(
    struct Ground* ground, s32 link);
void kar_gryakupushoutwall_create_stage_linked_kind49_wall(
    struct Ground* ground, s32 link);
void kar_gryakupushoutwall_create_stage_linked_kind50_switch_controller(
    struct Ground* ground, s32 link);
void kar_gryakupushoutwall_create_stage_linked_kind51_lightzone_controller(
    struct Ground* ground, s32 link);
void kar_gryakubreakhouse_create_stage_linked_kind54_animfloor(
    struct Ground* ground, s32 link);
void kar_gryakuanimfloor_create_stage_linked_kind55_reactive_floor(
    struct Ground* ground, s32 link);
void kar_gryakubreakcommon_create_stage_linked_kind56_delayed_collision(
    struct Ground* ground, s32 link);
void kar_gryakubreakcommon_create_stage_linked_kind57_lasergate(
    struct Ground* ground, s32 link);
void kar_gryakubreakcommon_create_stage_linked_kind58_lasergate_ctrl(
    struct Ground* ground, s32 link);
void kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(
    struct Ground* ground, s32 link);
void kar_gryakubreakhpcoll_create_stage_linked_kind61_timed_anim_audio_cycle(
    struct Ground* ground, s32 link);
void kar_gryakupushoutwall_trigger_kind50_target_wall_pushes(void* target);
void kar_gryakulighttunnel_trigger_kind52_pillar_entry_motion(void* target);
void kar_gryakulasergate_trigger_kind58_ctrl_open_linked_gates(void* target);
void fn_80191B4C(void* event, Vec* out);
void fn_801C7628(void* event, Vec* out);

#endif
