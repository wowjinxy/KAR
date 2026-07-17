#ifndef KAR_GR_GRAIRGLIDER_H
#define KAR_GR_GRAIRGLIDER_H

#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>
#include <sysdolphin/forward.h>

struct Ground;

void* kar_grairglider_create_airglider_hp_collision(struct Ground* ground,
                                                    void* pos);
void kar_grairglider_init_fade_handle(struct Ground* ground);
void kar_grairglider_start_fade_color_ramp(struct Ground* ground, void* color,
                                           s32 duration);
void kar_grairglider_destroy_fade_handle(struct Ground* ground);
void kar_grairglider_apply_collision_lighting_at_point(void* pos);
void kar_grairglider_init_realtime_lighting(struct Ground* ground);
void kar_grairglider_shutdown_hvqm_lighting_hook(void);
void kar_grairglider_bind_lightzone_to_collision_poly(struct Ground* ground,
                                                      s32 poly_idx);
void kar_grairglider_apply_lightuser_to_draw(struct Ground* ground, void* draw,
                                             void* arg);
void kar_grairglider_apply_lightzone_to_model(struct Ground* ground,
                                              s32 poly_idx, void* model,
                                              void* arg);
s32 kar_grairglider_pick_weighted_enemy_kind(s32* out_entry_idx);
s32 kar_grairglider_any_clearchecker_blocked(void);
s32 kar_grairglider_any_clearchecker_has_effect(void);
void kar_grairglider_reset_globals(void);
void kar_grairglider_cleanup_spawned_enemies(void);
void kar_grairglider_mark_spawn_handle_inactive(void* handle);
s32 kar_grairglider_release_spawn_handle(HSD_GObj* gobj);
s32 kar_grairglider_is_position_clear_of_checker_planes(Vec* pos,
                                                        f32 threshold);
s32 kar_grairglider_is_position_outside_checker_forward_cones(Vec* pos);
void kar_grairglider_register_spawned_enemy_kdcoll(void);
s32 kar_grairglider_is_chain_spawn_mode(void);
s32 kar_grairglider_is_slot_spawned(s32 slot);
s16 kar_grairglider_get_slot_enemy_kind(s32 slot);
void kar_grairglider_get_slot_enemy_position(s32 slot, Vec* out);

#endif
