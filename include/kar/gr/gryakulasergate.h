#ifndef KAR_GR_GRYAKULASERGATE_H
#define KAR_GR_GRYAKULASERGATE_H

#include <dolphin/types.h>
#include <sysdolphin/forward.h>

struct Ground;

void kar_gryakulasergate_init_kind58_lasergate_ctrl(HSD_GObj* gobj,
                                                    HSD_GObj* ground_gobj);
void kar_gryakulasergate_start_kind58_ctrl_idle_wait_motion(HSD_GObj* gobj);
void kar_gryakulasergate_update_kind58_ctrl_target_reset_to_idle(HSD_GObj* gobj);
void kar_gryakulasergate_trigger_kind58_ctrl_open_linked_gates(void* target);
s32 kar_gryakulasergate_test_kind58_ctrl_has_idle_gate_target(HSD_GObj* gobj);
void kar_gryakulasergate_create_stage_linked_kind32_breakfloor(
    struct Ground* ground, s32 link);

#endif
