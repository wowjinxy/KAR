#ifndef KAR_GR_GRYAKUBREAKCOLL_H
#define KAR_GR_GRYAKUBREAKCOLL_H

#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>
#include <sysdolphin/forward.h>

struct Ground;

void kar_gryakubreakcoll_break_target_by_index(HSD_GObj* gobj, s32 index,
                                               Vec* dir, s32 player);
void kar_gryakubreakcoll_update_effects_audio_then_destroy(HSD_GObj* gobj);
s32 kar_gryakubreakcoll_handle_damage_falloff_grcoll_hit(HSD_GObj* gobj,
                                                          void* root,
                                                          void* hit, s32 pass,
                                                          void* arg);
void kar_gryakubreakcoll_create_stage_linked_kind33_breakcoll(
    struct Ground* ground, s32 link);
void kar_gryakubreakcoll_create_stage_linked_kind34_breakcoll(
    struct Ground* ground, s32 link);
void kar_gryakubreakcoll_create_stage_linked_kind35_breakcoll(
    struct Ground* ground, s32 link);
void kar_gryakubreakcoll_cleanup_multi_target_allocs_and_fgm_handles(
    HSD_GObj* gobj);

#endif
