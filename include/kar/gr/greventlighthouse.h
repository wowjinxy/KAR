#ifndef KAR_GR_GREVENTLIGHTHOUSE_H
#define KAR_GR_GREVENTLIGHTHOUSE_H

#include <dolphin/mtx/vec.h>
#include <dolphin/types.h>
#include <sysdolphin/forward.h>

void event_lighthouse_start(void* event);
void event_lighthouse(void* event);
void kar_greventlighthouse_finish_active_kind68_lighthouse_event(void* event);
void* kar_greventlighthouse_get_ui_work_state_block(void);
void* kar_greventlighthouse_get_ifall1c_archive_slot(void);
void* kar_greventlighthouse_get_ifall1_variant_archive_slot(void);
void kar_greventlighthouse_queue_ifall1c_kdcollision_group(void);
void kar_greventlighthouse_queue_mode_variant_ifall_kdcoll_groups(s32 ground_variant,
                                                                  s32 mode_variant);
void* kar_greventlighthouse_get_ifall2c_archive_slot(void);
void* kar_greventlighthouse_get_ifall2_variant_archive_slot(void);
void* kar_greventlighthouse_get_ifall3c_archive_slot(void);
void* kar_greventlighthouse_get_ifall3_variant_archive_slot(void);
void kar_greventlighthouse_hide_all_round_ui_components(void);
void kar_greventlighthouse_show_all_round_ui_components(void);
void kar_greventlighthouse_show_round_ui_with_race_variant_toggle(void);
void kar_greventlighthouse_show_round_ui_and_shared_panels(void);
void kar_greventlighthouse_hide_round_ui_and_shared_panels(void);
void kar_greventlighthouse_set_ui_refresh_flag(void);
void kar_greventlighthouse_clear_ui_refresh_flag(void);
s32 kar_greventlighthouse_get_ui_refresh_flag(void);
void kar_greventlighthouse_init_ui_work_state_and_base_light(void);
void kar_greventlighthouse_load_ifall_archives_and_init_panels(void);
void kar_greventlighthouse_apply_mode_dependent_round_ui_panels(void);
void kar_greventlighthouse_update_round_ui_for_race_state(void);
void kar_greventlighthouse_create_ifround_panel0_for_player_if_active(s32 player);
void fn_8011370C(s32 slot);
void fn_801137F0(s32 slot);
void fn_801138D4(s32 arg0);
void fn_801138F4(void);
void fn_80113914(s32 arg0);
void fn_80113A24(void);
void fn_80113A98(void);
void fn_80113AD8(void);
void fn_80113B28(s32 slot);
void fn_80113BE0(s32 player);
void fn_80113C38(s32 player);
void fn_80113C70(s32 player);
void fn_80113CA8(s32 player);
void fn_80113D00(s32 player);
void fn_80113D58(s32 player);
void fn_80113DB0(s32 player);
void fn_80113E08(s32 player);
void fn_80113E60(s32 player);
void fn_80113EB8(s32 player);
void fn_80113F10(s32 player, s32 arg1, void* arg2);
void fn_80113FB4(s32 arg0, s32 arg1);
void fn_80114010(void* arg0);
void fn_801140E4(s32 arg0);
void fn_80114154(void);
void fn_80114178(s32 slot);
void fn_80114234(void);
void fn_801142FC(s32 slot);
void fn_801143E8(s32 player);
void fn_801144A0(s32 arg0);
void fn_80114524(void);
void fn_80114544(void);
void fn_80114564(void);
void fn_80114584(void);
void fn_801145A4(void);
HSD_GObj* fn_801147DC(HSD_Joint* joint, u8 p_link, u8 gx_link, u8 priority);
HSD_GObj* fn_8011487C(HSD_Joint* joint);
HSD_GObj* fn_80114904(s32 player, HSD_Joint* joint);
HSD_GObj* fn_801149A0(s32 arg0, HSD_Joint* joint,
                      void (*render_cb)(HSD_GObj*, s32));
void fn_80114D08(HSD_JObj* jobj, s32 index, void* anim, f32 frame, f32 rate);
void fn_80114D9C(HSD_JObj* jobj, void* anim, f32 frame, f32 rate);
void* kar_diag__80114e24(HSD_GObj* gobj, void* arg1, s32 arg2, s32 arg3);
void fn_80114EEC(HSD_GObj* gobj);
void fn_80114F04(HSD_GObj* gobj);
void fn_80114F1C(HSD_GObj* gobj, s32 pass);
void fn_8011500C(HSD_GObj* gobj, s32 pass);
void fn_8011503C(HSD_JObj* jobj, s32 frame);
void fn_801150A0(HSD_JObj* jobj, s32 frame, f32 rate);
void fn_80115114(HSD_JObj* jobj, s32 frame);
void fn_80115174(HSD_JObj* jobj, s32 frame, f32 rate);
void fn_801151E8(void* data);
f32 fn_80115214(void);
void fn_80115264(HSD_GObj* gobj);
void fn_801152CC(HSD_GObj* gobj, HSD_JObj* jobj);
void fn_80115398(HSD_GObj* gobj, HSD_JObj* jobj, f32 arg2, f32 arg3);
s32 fn_80115490(s32 mode, s32 player, Vec* pos, f32 top, f32 bottom, f32 left,
                f32 right);
void fn_8011582C(HSD_GObj* gobj);
u8 fn_8011584C(s32 row, s32 column);
void fn_8011586C(HSD_GObj* gobj, s32 pass);
void fn_801158C0(void);
void fn_8011596C(HSD_GObj* gobj, s32 pass);
void fn_801159C0(void);
void fn_80115A64(void);
void fn_80115AF4(s32 player, s32 arg1);
void fn_80115BF8(HSD_GObj* gobj);
f32 fn_80115E0C(f32 angle);
f32 fn_80116268(f32 angle);
void fn_801166B4(void);
void fn_801168E8(void);
void fn_8011693C(void);
void kar_si_assets__asset_801169c8(void);
void fn_801169FC(s32 arg0);
void fn_80116AC0(s32 player);
void fn_80116B04(s32 player);
void fn_80116B48(HSD_GObj* gobj, s32 arg1, s32 arg2);
void fn_80116D8C(HSD_GObj* gobj);
void fn_80117800(s32 slot, s32 player);

#endif
