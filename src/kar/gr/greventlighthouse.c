#include "functions.h"
#include <dolphin/gx/gx.h>
#include <dolphin/mtx/vec.h>
#include <dolphin/types.h>
#include <kar/gm/gmdiag.h>
#include <kar/gm/gmlanmenu.h>
#include <kar/gm/gmmain.h>
#include <kar/gm/gmracenormal.h>
#include <kar/gr/greventgenerator.h>
#include <kar/gr/greventlighthouse.h>
#include <kar/lb/lbairride.h>
#include <kar/lb/lbarchive.h>
#include <kar/lb/lbcamera.h>
#include <sysdolphin/cobj.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/gobj_kinds.h>
#include <sysdolphin/gobjuserdata.h>
#include <sysdolphin/jobj.h>
#include <sysdolphin/lobj.h>
#include <sysdolphin/objalloc.h>
#include <sysdolphin/sislib.h>

typedef struct LighthouseUIWorkState {
    s8 ui_mode;
    s8 player_slots[4];
    s8 refresh_flag;
    u8 pad_06[2];
    void* gpanel_scene_data;
    HSD_GObj* gobj_0C;
    HSD_GObj* gobj_10;
    HSD_GObj* player_gobjs[4];
    HSD_GObj* gobj_24;
    HSD_GObj* gobj_28;
    HSD_GObj* gobj_2C;
    HSD_GObj* light_gobj;
    HSD_GObj* player_panel_gobjs[4];
    u8 sis_context_44;
    u8 pad_45[3];
    HSD_Text* text_48;
    HSD_Text* text_4C;
    HSD_Text* text_50;
    HSD_Text* text_54;
    u8 pad_58[0xE44 - 0x58];
} LighthouseUIWorkState;

typedef struct HSD_ObjAllocDataWithTailPad {
    HSD_ObjAllocData data;
    u32 pad;
} HSD_ObjAllocDataWithTailPad;

typedef struct LighthousePanelUserData {
    u8 pad_00[4];
    void* data_04;
    struct {
        u8 arg2 : 4;
        u8 player : 2;
        u8 visible : 1;
        u8 pad : 1;
    } flags_08;
    u8 pad_09[3];
    f32 scale_0C;
    f32 mode_scale_10;
    u8 pad_14[0xE4 - 0x14];
} LighthousePanelUserData;

typedef struct LighthouseCameraUserData {
    u8 pad_00[0x14];
    s8 mode_14;
    u8 pad_15[3];
    f32 angle_x_18;
    f32 angle_y_1C;
    f32 unk_20;
    Vec eye_24;
    Vec step_30;
} LighthouseCameraUserData;

typedef struct LighthouseCamWObjDesc {
    char* class_name;
    Vec pos;
    void* robjdesc;
} LighthouseCamWObjDesc;

typedef struct LighthouseCameraDesc {
    char* class_name;
    u16 flags;
    u16 projection_type;
    s16 viewport_left;
    s16 viewport_right;
    s16 viewport_top;
    s16 viewport_bottom;
    u16 scissor_left;
    u16 scissor_right;
    u16 scissor_top;
    u16 scissor_bottom;
    LighthouseCamWObjDesc* eye_desc;
    LighthouseCamWObjDesc* interest_desc;
    f32 roll;
    Vec* vector;
    f32 near;
    f32 far;
    f32 top;
    f32 bottom;
    f32 left;
    f32 right;
} LighthouseCameraDesc;

typedef struct LighthouseGObjTrackerUserData {
    u8 pad_00[0x30];
    HSD_GObj* gobjs[0x20];
} LighthouseGObjTrackerUserData;

typedef struct LighthouseClearCheckerValues {
    f32 values[9];
} LighthouseClearCheckerValues;

typedef struct LighthouseClearCheckerPanelUserData {
    u8 pad_00[4];
    void* data_04;
    struct {
        u8 arg2 : 4;
        u8 player : 2;
        u8 visible : 1;
        u8 pad : 1;
    } flags_08;
    u8 pad_09[3];
    f32 scale_0C;
    f32 mode_scale_10;
    s8 last_clear_event_14;
    s8 sub_state_15;
    u8 pad_16[2];
    f32 did_state4_18;
    f32 did_state5_1C;
    s8 field_20;
    s8 counters_21[9];
    s8 rank_counter_2A;
    u8 pad_2B;
    s32 cooldown_2C;
    HSD_GObj* tracked_gobjs_30[0x20];
} LighthouseClearCheckerPanelUserData;

#define IFALL_NAME(index) kar_greventlighthouse_ifall1c_archive_name[(index)]
#define WORK_MODE ((s8) kar_greventlighthouse_ui_work_state_block.ui_mode)
#define PLAYER_SLOT(player) \
    ((s8) kar_greventlighthouse_ui_work_state_block.player_slots[(player)])
#define ACTIVE_LIGHTHOUSE_GOBJ lbl_805DD750[0]

#define SPECIAL_CITYTRIAL_LAN_DIAG                                      \
    ((s8) kar_gmracenormal__8000aea8() == 6 &&                         \
     (s8) kar_gmracenormal__near_8000ae2c() == 0 &&                    \
     (s8) kar_diag__8000acb0() == 1)

void* memset(void* dst, int val, unsigned long n);
f64 sin(f64 x);

s8 fn_8000916C(void);
s8 fn_800092B4(void);
s32 fn_800097D0(s32 slot);
s8 fn_80009888(s32 player);
s32 fn_800098C0(s32 player);
s8 fn_80009908(s32 player);
s32 fn_80009940(s32 player);
s32 fn_8000A188(void);
s8 fn_8000A958(void);
s8 fn_8000A97C(void);
s8 fn_8000AAC4(void);
s8 fn_8000AAF0(void);
s8 fn_8000AB1C(void);
s32 fn_8000AD48(void);
s32 fn_8000ADA0(void);
s8 fn_8000C768(void);
s32 fn_800419B8(s32 arg0, s8 arg1, s32* out);
s8 kar_gmracenormal__near_8000ae2c(void);
s8 kar_gmracenormal__near_8000ae74(void);
s8 kar_gmracenormal__8000af5c(void);
s8 kar_gmracenormal__8003d5f0(void);
f32 fn_803BCCD0(f32 arg0);

void kar_grcommon__near_800d4bf4(s32 joint_name, Vec* out);
void kar_lbkdcoll__near_80072c90(s32 arg0, char* name, s32 arg2, s32 arg3,
                                 s32 arg4, s32 arg5, s32 arg6, s32 arg7,
                                 s32 arg8);
s32 kar_gryakulib_get_yaku_data_checked(HSD_GObj* gobj);
void kar_gryakubreakhpcoll_arm_kind68_lighthouse_event_handle(
    HSD_GObj* lighthouse, void* event);
void kar_gryakubreakhpcoll_mark_kind68_lighthouse_event_complete(
    HSD_GObj* lighthouse);

__declspec(section ".sdata2") extern const f32 lbl_805DFB48;
__declspec(section ".sdata2") extern const f64 lbl_805DFB50;
__declspec(section ".sdata2") extern const f32 lbl_805DFB58;
__declspec(section ".sdata2") extern const f32 lbl_805DFB5C;
__declspec(section ".sdata2") extern const f32 lbl_805DFB60;
__declspec(section ".sdata2") extern const f32 lbl_805DFB64;
__declspec(section ".sdata2") extern const f32 lbl_805DFB68;
__declspec(section ".sdata2") extern const f32 lbl_805DFB6C;
__declspec(section ".sdata2") extern const f32 lbl_805DFB70;
__declspec(section ".sdata2") extern const f32 lbl_805DFB74;
__declspec(section ".sdata2") extern const f32 lbl_805DFB78;
__declspec(section ".sdata2") extern const f32 lbl_805DFB80;
__declspec(section ".sdata2") extern const f32 lbl_805DFB84;
__declspec(section ".sdata2") extern const f32 lbl_805DFB88;
__declspec(section ".sdata2") extern const f32 lbl_805DFB8C;
__declspec(section ".sdata2") extern const f32 lbl_805DFB90;
__declspec(section ".sdata2") extern const f32 lbl_805DFB94;
__declspec(section ".sdata2") extern const f32 lbl_805DFB98;
__declspec(section ".sdata2") extern const f32 lbl_805DFB9C;
__declspec(section ".sdata2") extern const f32 lbl_805DFBA0;
__declspec(section ".sdata2") extern const f64 lbl_805DFBE8;
__declspec(section ".sdata2") extern const f32 lbl_805DFBF0;
__declspec(section ".sdata2") extern const f32 lbl_805DFBF8;
__declspec(section ".sdata2") extern const f32 lbl_805DFBFC;
__declspec(section ".sdata2") extern const f32 lbl_805DFC00;
__declspec(section ".sdata2") extern const f32 lbl_805DFC04;
__declspec(section ".sdata2") extern const f32 lbl_805DFC08;
__declspec(section ".sdata2") extern const f32 lbl_805DFC0C;
__declspec(section ".sdata2") extern const f32 lbl_805DFC10;
__declspec(section ".sdata2") extern const f32 lbl_805DFC14;
__declspec(section ".sdata2") extern const f32 lbl_805DFC18;
__declspec(section ".sdata2") extern const f32 lbl_805DFC1C;
__declspec(section ".sdata2") extern const f32 lbl_805DFC20;

void fn_801143E8(s32 player);
void fn_801144A0(s32 arg0);
void fn_80114524(void);
void fn_80114544(void);
void fn_80114564(void);
void fn_80114584(void);
void fn_801145A4(void);
void fn_801151E8(void* data);
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
void fn_80117B28(s32 player);
void fn_80117B6C(s32 player);
void fn_80117DE8(void);
void fn_80117F40(s32 slot, s32 player);
void fn_80118254(s32 player);
void fn_80118298(s32 player);
void fn_8011878C(void);
void fn_80118930(s32 slot, s32 player);
void fn_80118EF0(void);
void fn_80118F20(void);
void fn_801191A0(void);
void fn_80119218(void);
void fn_80119490(s32 player);
void fn_801194D4(s32 player);
void fn_801196EC(void);
void fn_80119CF8(s32 player);
void fn_80119D3C(s32 player);
void fn_80119DB4(void);
void fn_8011A138(s32 player);
void fn_8011A17C(s32 player);
void fn_8011A374(void);
void fn_8011A434(s32 slot, s32 player);
void fn_8011A674(s32 player);
void fn_8011A6B8(s32 player);
void fn_8011AC3C(void);
void fn_8011ACFC(s32 slot, s32 player);
void fn_8011B22C(s32 player, s32 index);
void fn_8011B284(s32 player, s32 index);
void fn_8011B678(void);
void fn_8011B6C8(s32 slot, s32 player, s32 index);
void fn_8011E824(void);
void fn_8011FF78(void);
void fn_80121100(void);
void fn_80121534(s32 arg0);
void fn_801216B4(void);
void fn_801217AC(void);
void fn_801218A4(void);
void fn_80121970(void);
void fn_801221C8(void);
void fn_8012229C(void);
void fn_80122A6C(void);
void fn_80122F50(void);
void fn_8012350C(void);
void fn_80123AB8(void);
void fn_80123E80(void);
void fn_8012434C(void);
void fn_801246D8(void);
void kar_ifround_load_laprec_scene_models(void);
void kar_ifround_create_laprec_player_panel(s32 slot, s32 player);
void kar_ifround_hide_laprec_player_panel(s32 player);
void kar_ifround_show_laprec_player_panel(s32 player);
void kar_ifround_destroy_laprec_split_digit_gobjs_all_players(void);
void kar_ifround_destroy_laprec_player_panels(void);
void kar_ifround_load_wrongway_scene_models(void);
void kar_ifround_create_or_retrigger_wrongway_warning_panel(s32 slot,
                                                            s32 player);
void kar_ifround_hide_wrongway_player_panel(s32 player);
void kar_ifround_show_wrongway_player_panel(s32 player);
void kar_ifround_destroy_wrongway_warnings_all_players(void);
void kar_diag__8011c3b4(void);
void kar_ifround_hide_clearchecker_warning_player_panel(s32 player);
void kar_ifround_show_clearchecker_warning_player_panel(s32 player);
void kar_ifround_destroy_clearchecker_warnings_all_players(void);
void kar_ifround_load_readygo_timeup_finish_scene_models(void);
void kar_ifround_create_readygo_timeup_finish_panel_kind(s32 slot, s32 player,
                                                        s32 kind);
void kar_ifround_hide_readygo_timeup_finish_player_panel(s32 player);
void kar_ifround_show_readygo_timeup_finish_player_panel(s32 player);
void kar_ifround_destroy_readygo_timeup_finish_all_players(void);
void kar_ifround_load_finallap_scene_models(void);
void kar_ifround_create_finallap_player_panel(s32 slot, s32 player);
void kar_ifround_hide_finallap_player_panel(s32 player);
void kar_ifround_show_finallap_player_panel(s32 player);
void kar_ifround_destroy_finallap_panels_all_players(void);
void kar_ifround_load_round_number_scene_models(void);
void kar_ifround_create_round_number_panel(void);
void kar_ifround_hide_round_number_panel(void);
void kar_ifround_show_round_number_panel(void);
void kar_ifround_destroy_round_number_panel(void);
void kar_ifround_hide_course_line_map_renderer(void);
void kar_ifround_show_course_line_map_renderer(void);
void kar_ifround_create_course_line_map_renderer(s32 mode);
void kar_ifround_destroy_course_line_map_renderer(void);
void kar_ifround_hide_mmapply_player_marker(s32 player);
void kar_ifround_show_mmapply_player_marker(s32 player);
void kar_ifround_load_mmapply_scene_models(void);
void kar_ifround_create_mmapply_player_markers_all_slots(void);
void kar_ifround_destroy_mmapply_player_markers_all_slots(void);
void kar_ifround_hide_mmapstart_marker(void);
void kar_ifround_show_mmapstart_marker(void);
void kar_ifround_load_mmapstart_scene_models(void);
void kar_ifround_create_mmapstart_marker(void);

void fn_8011E868(s32 player);
void fn_8011E8AC(s32 player);
void fn_8011EF70(void);
void fn_8011F144(s32 slot, s32 player);
void fn_8011F688(s32 player);
void fn_8011F754(s32 player, s32 index);
void fn_8011F7AC(s32 player, s32 index);
void fn_8011F8A8(void);
void fn_8011FEBC(s32 slot, s32 player);
void fn_8011FFFC(s32 player, s32 index);
void fn_80120054(s32 player, s32 index);
void fn_801202CC(void);
void fn_801210A8(s32 slot, s32 player);
void fn_80121178(s32 player, s32 index);
void fn_801211D0(s32 player, s32 index);
void fn_8012122C(void);
BOOL fn_80121B24(HSD_GObj* gobj, s32 arg1, s32 arg2);
void fn_80121FF8(HSD_GObj* gobj, s32 arg1, s32 arg2);
void fn_80122128(HSD_GObj* gobj, s32 arg1, s32 arg2);
void fn_80122E24(s32 arg0, s32 arg1);
void fn_80123278(s32 arg0, s32 arg1);
void fn_80123830(s32 arg0, s32 arg1);
void fn_80123D50(s32 arg0, s32 arg1);
void fn_80124184(s32 arg0, s32 arg1);
void fn_80124594(s32 arg0, s32 arg1);
void kar_ifround_create_clearchecker_warning_panel(s32 arg0, s32 arg1);
void fn_80127234(s32 arg0, s32 arg1, s32 index, s32 enabled);
s32 kar_plclearcheckerlib__near_8022cad8(s32 arg0);
s32 kar_plclearchecker_call_clobject_func_191f74(s32 arg0);
s32 kar_plclearcheckerlib__near_8022cbc0(s32 arg0);
s32 kar_cmreplay__8022cc30(s32 arg0);
f32 kar_plclearcheckerlib__near_8022cf20(s32 arg0);
void kar_plclearcheckerlib__near_8022cf6c(
    s32 arg0, LighthouseClearCheckerValues* out);
s32 kar_plclearcheckerlib__near_8022d024(s32 arg0);
s32 kar_plclearcheckerlib__near_8022d434(s32 arg0);
s32 kar_plclearchecker_call_clobject_func_1926f4(s32 arg0);
s32 kar_plclearcheckerlib__near_8022d584(s32 arg0);
void fn_801219F4(s32 player, s32 index);
void fn_80121A4C(s32 player, s32 index);
void fn_80121AD8(void);
void fn_80122320(void);
void fn_80122350(void);
void fn_801226E8(void);
void fn_80122CD0(s32 player);
void fn_80122D14(s32 player);
void fn_80122DD8(void);
void fn_80122FC8(s32 player);
void fn_8012300C(s32 player);
void fn_8012322C(void);
void fn_8012358C(s32 player);
void fn_801235D0(s32 player);
void fn_801237E4(void);
void fn_80123B38(s32 player);
void fn_80123B7C(s32 player);
void fn_80123C90(void);
void fn_80123EF8(s32 player);
void fn_80123F3C(s32 player);
void fn_80123FE0(void);
void fn_801243C4(s32 player);
void fn_80124408(s32 player);
void fn_801244D4(void);
void fn_801247E0(void);
void fn_80124810(void);
void fn_80124844(void);
void fn_80124890(void);
void fn_80124B28(s32 player);
void fn_80124B6C(s32 player);
void fn_80124BD4(void);
void fn_80124E98(s32 arg0, void* arg1);
void fn_80124F9C(s32 arg0, s32 arg1);
void fn_80125004(void);
void fn_8012506C(void);
void fn_8012509C(void);
void fn_801250D0(void);
void fn_80125174(void);
void fn_8012532C(void);
void fn_8012535C(void);
void fn_80125390(void);
void fn_801254F4(void);
void fn_80125700(void);
void fn_80125730(void);
void fn_80125780(void);
void fn_8012581C(void);
void fn_80125940(void);
void fn_801259DC(void);
void fn_80125DF0(s32 player);
void fn_80125E34(s32 player);
void fn_80125E7C(void);
void fn_80125FD0(s32 slot, s32 player);
void fn_80126310(void);
void fn_80126340(void);
void fn_80126390(void);
void fn_80126408(void);
void fn_801265B8(s32 player);
void fn_801265FC(s32 player);
void fn_801267EC(void);
void fn_80126B1C(void);
void fn_80126B54(void);
void fn_80126C4C(s32 player);
void fn_80126C90(s32 player);
void fn_80126D40(void);
void fn_80127624(void);
void fn_8012768C(void);
void fn_801277F0(void);
void fn_80127864(s32 arg0, s32 arg1, s32 arg2);
void fn_80127A4C(s32 player);
void fn_80127A90(s32 player);
void fn_80127E94(void);
void fn_80127F54(s32 slot, s32 player, void* arg2);
void fn_80128108(s32 player, s32 arg1);
void fn_80128170(void);
void fn_80128244(void);
void fn_80128328(s32 arg0);
void fn_80128448(void);
void fn_801284F8(void);
void fn_801285DC(s32 arg0);
void fn_80128A68(void);
void fn_80128AFC(void);
void fn_80128BB8(s32 slot, s32 player);
void fn_80129034(void);
void fn_80129108(void);
void fn_80129154(s32 slot, s32 player, s32 index);
void fn_801294A8(void);
void fn_8012979C(void);
void fn_801297E8(s32 arg0);
void fn_8012993C(void);
void fn_801299C8(void);
void fn_80129A14(void);
void fn_80129D90(void);
void fn_80129DDC(s32 slot);
void fn_80129F30(void);
void fn_80129F7C(s32 slot);
void fn_8012A02C(void);
void fn_8012A05C(void);
void fn_8012A104(void);
void fn_8012A3B0(s32 player);
void fn_8012A414(s32 player);
void fn_8012A56C(void);
void fn_8012A640(s32 slot, s32 player, s32 arg2, void* arg3);
void fn_8012AB18(s32 player);
void fn_8012AB9C(s32 player);
void fn_8012B39C(void);
void fn_8012B580(s32 slot, s32 player);
void fn_8012B798(s32 player);
void fn_8012B7FC(s32 player);
void fn_8012B9BC(void);
void fn_8012BAE0(s32 slot, s32 player);
void fn_8012C578(s32 player);
void fn_8012C5BC(s32 player);
void fn_8012C7E4(void);
void fn_8012C908(s32 slot, s32 player);
void fn_8012D3AC(s32 player);
void fn_8012D3F0(s32 player);
void fn_8012D6F8(void);
void fn_8012D7B4(s32 slot, s32 player);
void fn_8012DCB0(s32 player);
void fn_8012DD14(s32 player);
void fn_8012DE70(void);
void fn_8012DF94(s32 slot, s32 player);
void fn_8012EB0C(s32 player);
void fn_8012EB50(s32 player);
void fn_8012EB94(void);
void fn_8012ECB8(s32 player);
void fn_8012ECFC(s32 player);
void fn_8012EE4C(void);
void fn_8012EF08(s32 slot, s32 player);
void fn_8012F084(s32 player);
void fn_8012F0C8(s32 player);
void fn_8012F27C(void);
void fn_8012F338(s32 slot, s32 player);
void fn_8012F4C4(s32 player);
void fn_8012F508(s32 player);
void fn_8012F744(void);
void fn_8012F800(s32 slot, s32 player);
void fn_8012F9AC(s32 player);
void fn_8012F9F0(s32 player);
void fn_8012FA34(void);
void fn_8012FAF0(s32 slot, s32 player);
void fn_8012FEB0(s32 player);
void fn_8012FEF4(s32 player);
void fn_8012FF38(void);
void fn_8012FFF4(s32 slot, s32 player);
void fn_801301D4(s32 player);
void fn_80130218(s32 player);
void fn_80130574(void);
void fn_8013065C(s32 slot, s32 player);
void fn_801308F8(s32 player);
void fn_8013093C(s32 player);
void fn_80130980(void);
void fn_80130AA4(s32 player);
void fn_80130AE8(s32 player);
void fn_80130B2C(void);
void fn_80130C50(s32 player);
void fn_80130C94(s32 player);
void fn_80130CFC(void);
void fn_80130DB8(s32 slot, s32 player);
void fn_80130EEC(s32 player);
void fn_80130F30(s32 player);
void fn_80131008(void);
void fn_801310C4(s32 slot, s32 player);

void fn_8011693C(void);
void fn_80117AC0(void);
void fn_801181EC(void);
void fn_80118E88(void);
void fn_8011944C(void);
void fn_80119C88(void);
void fn_8011A0C8(void);
void fn_8011A60C(void);
void fn_8011B1C4(void);
void fn_8011F6EC(void);
void fn_80124AE4(void);
void fn_80124750(void);
void fn_80124798(void);
void fn_801252E8(void);
void fn_801256BC(void);
void fn_801258DC(void);
void fn_80125DAC(void);
void fn_801262A8(void);
void fn_80126574(void);
void fn_80126BE4(void);
void fn_801275B4(void);
void fn_80127A04(void);
void fn_80129AB8(void);
void fn_8012A36C(void);
void fn_8012AAA0(void);
void fn_8012B6C8(void);
void fn_8012C4FC(void);
void fn_8012D344(void);
void fn_8012DC48(void);
void fn_8012EA90(void);
void fn_8012EC50(void);
void fn_8012F01C(void);
void fn_8012F45C(void);
void fn_8012F944(void);
void fn_8012FE48(void);
void fn_8013016C(void);
void fn_80130878(void);
void fn_80130A3C(void);
void fn_80130BE8(void);
void fn_80130E84(void);
void fn_80131178(void);

extern s32 lbl_805DD638;

char kar_src_greventlighthouse_c[0x14] = "greventlighthouse.c";
char kar_greventlighthouse_assert_lighthouse_gobj[0x0F] = "lighthouseGObj";
__declspec(section ".data") u8 gap_804A7A43_data[5] = { 0, 0, 0, 0, 0 };

char kar_greventlighthouse_ifall1c_archive_name[16][12] = {
    "IfAll1c.",  "IfAll11s.", "IfAll12s.", "IfAll14s.",
    "IfAll11.",  "IfAll12.",  "IfAll14.",  "IfAll2c.",
    "IfAll21.",  "IfAll22.",  "IfAll24.",  "IfAll3c.",
    "IfAll31.",  "IfAll32.",  "IfAll34.",  "IfAllTmp.",
};

char kar_greventlighthouse_gpanel_scene_data_name[0x17] =
    "ScInfGpanel_scene_data";
__declspec(section ".data") u8 gap_804A7B1F_data[1] = { 0 };

LighthouseUIWorkState kar_greventlighthouse_ui_work_state_block;
HSD_ObjAllocData kar_greventlighthouse_panel_obj_allocator_e4;
HSD_ObjAllocDataWithTailPad kar_greventlighthouse_panel_obj_allocator_600;

HSD_GObj* lbl_805DD750[2];
void* lbl_805DD758;
void* lbl_805DD75C;
void* lbl_805DD760;
void* lbl_805DD764;
void* lbl_805DD768;
void* lbl_805DD76C;
void* lbl_805DD770[2];
void* lbl_805DD778[2];
void* lbl_805DD780;
void* lbl_805DD784;
void* lbl_805DD788;
void* lbl_805DD78C;
void* lbl_805DD790;
void* lbl_805DD794;
void* lbl_805DD798;
void* lbl_805DD79C;
void* lbl_805DD7A0;
void* lbl_805DD7A4;
void* lbl_805DD7A8;
void* lbl_805DD7AC;
void* lbl_805DD7B0;
void* lbl_805DD7B4;
void* lbl_805DD7B8;
void* lbl_805DD7BC;
void* lbl_805DD7C0;
void* lbl_805DD7C4;
void* lbl_805DD7C8;
void* lbl_805DD7CC;
void* lbl_805DD7D0;
void* lbl_805DD7D4;
void* lbl_805DD7D8;
void* lbl_805DD7DC;
void* lbl_805DD7E0[2];
void* lbl_805DD7E8;
void* lbl_805DD7EC;
void* lbl_805DD7F0[2];

void event_lighthouse_start(void* event)
{
    void* param;
    HSD_GObj* gobj;
    Vec pos;

    param = kar_greventgenerator_get_current_event_param();
    ACTIVE_LIGHTHOUSE_GOBJ = hsdGObj_p_link_tails[8];

    while (ACTIVE_LIGHTHOUSE_GOBJ != NULL) {
        gobj = ACTIVE_LIGHTHOUSE_GOBJ;
        if (kar_gryakulib_get_yaku_data_checked(gobj) == 0x44) {
            break;
        }
        ACTIVE_LIGHTHOUSE_GOBJ = gobj->prev;
    }

    if (ACTIVE_LIGHTHOUSE_GOBJ == NULL) {
        __assert(kar_src_greventlighthouse_c, 0x31,
                 kar_greventlighthouse_assert_lighthouse_gobj);
    }

    kar_gryakubreakhpcoll_arm_kind68_lighthouse_event_handle(
        ACTIVE_LIGHTHOUSE_GOBJ, event);
    kar_grcommon__near_800d4bf4(*(s32*) param, &pos);
    fn_80114010(&pos);
}

void event_lighthouse(void* event)
{
    s32 key_frame;
    s32 elapsed;

    kar_greventgenerator_get_current_event_param();
    key_frame = kar_greventgenerator_get_current_event_key_frame(event);
    elapsed = kar_greventgenerator_get_state_elapsed_frames(event);

    if (key_frame - elapsed == 0) {
        kar_gryakubreakhpcoll_mark_kind68_lighthouse_event_complete(
            ACTIVE_LIGHTHOUSE_GOBJ);
    }
}

void kar_greventlighthouse_finish_active_kind68_lighthouse_event(void* event)
{
    ACTIVE_LIGHTHOUSE_GOBJ = NULL;
    fn_80114154();
    kar_greventgenerator_enter_finish_state(event);
}

#pragma push
#pragma dont_inline on
void* kar_greventlighthouse_get_ui_work_state_block(void)
{
    return &kar_greventlighthouse_ui_work_state_block;
}
#pragma pop

void* kar_greventlighthouse_get_ifall1c_archive_slot(void)
{
    return lbl_805DD770;
}

void* kar_greventlighthouse_get_ifall1_variant_archive_slot(void)
{
    return &lbl_805DD76C;
}

void kar_greventlighthouse_queue_ifall1c_kdcollision_group(void)
{
    kar_lbkdcoll__near_80072c90(2, IFALL_NAME(0), 3, 3, 0, 1, 1, 0x40, 0);
}

void kar_greventlighthouse_queue_mode_variant_ifall_kdcoll_groups(s32 ground_variant,
                                                                  s32 mode_variant)
{
    s32 name_index;

    if ((s8) kar_gmracenormal__8000aea8() == 6 &&
        (s8) kar_gmracenormal__near_8000ae2c() == 0) {
        switch (mode_variant) {
        case 1:
            name_index = 1;
            break;
        case 2:
            name_index = 2;
            break;
        case 3:
        case 4:
            name_index = 3;
            break;
        default:
            name_index = -1;
            break;
        }
    } else {
        switch (mode_variant) {
        case 1:
            name_index = 4;
            break;
        case 2:
            name_index = 5;
            break;
        case 3:
        case 4:
            name_index = 6;
            break;
        default:
            name_index = -1;
            break;
        }
    }

    if (name_index != -1) {
        kar_lbkdcoll__near_80072c90(2, IFALL_NAME(name_index), 4, 4, 0, 1, 3,
                                    1, 0);
    }

    if (mode_variant == 2) {
        kar_lbkdcoll__near_80072c90(2, IFALL_NAME(7), 4, 4, 0, 1, 3, 1, 0);
        switch (ground_variant) {
        case 1:
            name_index = 8;
            break;
        case 2:
            name_index = 9;
            break;
        case 3:
        case 4:
            name_index = 10;
            break;
        default:
            name_index = -1;
            break;
        }
        if (name_index != -1) {
            kar_lbkdcoll__near_80072c90(2, IFALL_NAME(name_index), 4, 4, 0, 1,
                                        3, 1, 0);
        }
    } else if (mode_variant == 3) {
        kar_lbkdcoll__near_80072c90(2, IFALL_NAME(11), 4, 4, 0, 1, 3, 1, 0);
        switch (ground_variant) {
        case 1:
            name_index = 12;
            break;
        case 2:
            name_index = 13;
            break;
        case 3:
        case 4:
            name_index = 14;
            break;
        default:
            name_index = -1;
            break;
        }
        if (name_index != -1) {
            kar_lbkdcoll__near_80072c90(2, IFALL_NAME(name_index), 4, 4, 0, 1,
                                        3, 1, 0);
        }
    }
}

void* kar_greventlighthouse_get_ifall2c_archive_slot(void)
{
    return &lbl_805DD768;
}

void* kar_greventlighthouse_get_ifall2_variant_archive_slot(void)
{
    return &lbl_805DD764;
}

void* kar_greventlighthouse_get_ifall3c_archive_slot(void)
{
    return &lbl_805DD760;
}

void* kar_greventlighthouse_get_ifall3_variant_archive_slot(void)
{
    return &lbl_805DD75C;
}

void kar_greventlighthouse_hide_all_round_ui_components(void)
{
    s32 player;
    s32 index;

    for (player = 0; player < 4; player++) {
        fn_80116AC0(player);
        fn_80117B28(player);
        fn_80118254(player);
        fn_80119490(player);
        fn_80119CF8(player);
        fn_8011A138(player);
        fn_8011A674(player);

        for (index = 0; index < 3; index++) {
            fn_8011B22C(player, index);
        }
        for (index = 0; index < 5; index++) {
            fn_8011F754(player, index);
            fn_8011FFFC(player, index);
        }

        kar_ifround_hide_laprec_player_panel(player);
        fn_8011E868(player);
        kar_ifround_hide_wrongway_player_panel(player);
        kar_ifround_hide_clearchecker_warning_player_panel(player);
        kar_ifround_hide_readygo_timeup_finish_player_panel(player);
        kar_ifround_hide_finallap_player_panel(player);

        for (index = 0; index < 0x20; index++) {
            fn_80121178(player, index);
        }

        fn_80122CD0(player);
        fn_80122FC8(player);
        fn_8012358C(player);
        fn_80125DF0(player);
        fn_80123B38(player);
        fn_80123EF8(player);
        fn_801243C4(player);
        fn_8012A3B0(player);
        fn_80130C50(player);
        fn_8012D3AC(player);

        for (index = 0; index < 0x20; index++) {
            fn_801219F4(player, index);
        }

        fn_80122320();
        fn_80126C4C(player);
        fn_80127A4C(player);
        fn_801265B8(player);
        fn_801308F8(player);
        fn_80130AA4(player);
        fn_80130EEC(player);
        fn_8012B798(player);
        fn_8012C578(player);
        fn_8012DCB0(player);
        fn_8012EB0C(player);
        fn_8012ECB8(player);
        fn_8012F084(player);
        fn_8012F4C4(player);
        fn_8012F9AC(player);
        fn_8012FEB0(player);
        fn_801301D4(player);
        fn_8012AB18(player);
    }

    fn_80118EF0();
    for (player = 0; player < 4; player++) {
        fn_80124B28(player);
    }

    if (WORK_MODE <= 1) {
        kar_ifround_hide_course_line_map_renderer();
        kar_ifround_hide_mmapstart_marker();
        fn_8012506C();
        fn_8012532C();
    }

    if (WORK_MODE <= 1 || WORK_MODE == 2) {
        fn_801247E0();
        for (player = 0; player < 5; player++) {
            kar_ifround_hide_mmapply_player_marker(player);
        }
    }

    kar_ifround_hide_round_number_panel();
    fn_80125700();
    fn_80126310();
    fn_80127624();
    fn_8012A02C();
}

void kar_greventlighthouse_show_all_round_ui_components(void)
{
    s32 player;
    s32 index;

    for (player = 0; player < 4; player++) {
        fn_80116B04(player);
        fn_80117B6C(player);
        fn_80118298(player);
        fn_801194D4(player);
        fn_80119D3C(player);
        fn_8011A17C(player);
        fn_8011A6B8(player);

        for (index = 0; index < 3; index++) {
            fn_8011B284(player, index);
        }
        for (index = 0; index < 5; index++) {
            fn_8011F7AC(player, index);
            fn_80120054(player, index);
        }

        kar_ifround_show_laprec_player_panel(player);
        fn_8011E8AC(player);
        kar_ifround_show_wrongway_player_panel(player);
        kar_ifround_show_clearchecker_warning_player_panel(player);
        kar_ifround_show_readygo_timeup_finish_player_panel(player);
        kar_ifround_show_finallap_player_panel(player);

        for (index = 0; index < 0x20; index++) {
            fn_801211D0(player, index);
        }

        fn_80122D14(player);
        fn_8012300C(player);
        fn_801235D0(player);
        fn_80125E34(player);
        fn_80123B7C(player);
        fn_80123F3C(player);
        fn_80124408(player);
        fn_8012A414(player);
        fn_80130C94(player);
        fn_8012D3F0(player);

        for (index = 0; index < 0x20; index++) {
            fn_80121A4C(player, index);
        }

        fn_80122350();
        fn_80126C90(player);
        fn_80127A90(player);
        fn_801265FC(player);
        fn_8013093C(player);
        fn_80130AE8(player);
        fn_80130F30(player);
        fn_8012B7FC(player);
        fn_8012C5BC(player);
        fn_8012DD14(player);
        fn_8012EB50(player);
        fn_8012ECFC(player);
        fn_8012F0C8(player);
        fn_8012F508(player);
        fn_8012F9F0(player);
        fn_8012FEF4(player);
        fn_80130218(player);
        fn_8012AB9C(player);
    }

    fn_80118F20();
    for (player = 0; player < 4; player++) {
        fn_80124B6C(player);
    }

    if (WORK_MODE <= 1) {
        kar_ifround_show_course_line_map_renderer();
        kar_ifround_show_mmapstart_marker();
        fn_8012509C();
        fn_8012535C();
    }

    if (WORK_MODE <= 1 || WORK_MODE == 2) {
        fn_80124810();
        for (player = 0; player < 5; player++) {
            kar_ifround_show_mmapply_player_marker(player);
        }
    }

    kar_ifround_show_round_number_panel();
    fn_80125730();
    fn_80126340();
    fn_8012768C();
    fn_8012A05C();
}

void kar_greventlighthouse_show_round_ui_with_race_variant_toggle(void)
{
    kar_greventlighthouse_show_all_round_ui_components();

    if ((s8) kar_gmracenormal__8000aea8() == 4 &&
        (s8) kar_gmracenormal__8003d5f0() == 2) {
        fn_80118EF0();
    } else if ((s8) kar_gmracenormal__8000aea8() == 4 &&
               (s8) kar_gmracenormal__8003d5f0() == 1) {
        fn_80118EF0();
    } else {
        fn_80118F20();
    }
}

void kar_greventlighthouse_show_round_ui_and_shared_panels(void)
{
    s32 player;

    kar_greventlighthouse_show_all_round_ui_components();
    if (WORK_MODE <= 1 ||
        (WORK_MODE == 4 && (s8) fn_800092B4() == 3)) {
        for (player = 0; player < 5; player++) {
            kar_ifround_show_mmapply_player_marker(player);
        }
        kar_ifround_show_course_line_map_renderer();
        kar_ifround_show_mmapstart_marker();
        fn_80124810();
        fn_8012509C();
        fn_8012535C();
    }
}

void kar_greventlighthouse_hide_round_ui_and_shared_panels(void)
{
    s32 player;

    kar_greventlighthouse_hide_all_round_ui_components();
    if (WORK_MODE <= 1 ||
        (WORK_MODE == 4 && (s8) fn_800092B4() == 3)) {
        for (player = 0; player < 5; player++) {
            kar_ifround_hide_mmapply_player_marker(player);
        }
        kar_ifround_hide_course_line_map_renderer();
        kar_ifround_hide_mmapstart_marker();
        fn_801247E0();
        fn_8012506C();
        fn_8012532C();
    }
}

void kar_greventlighthouse_set_ui_refresh_flag(void)
{
    kar_greventlighthouse_ui_work_state_block.refresh_flag = 1;
}

void kar_greventlighthouse_clear_ui_refresh_flag(void)
{
    kar_greventlighthouse_ui_work_state_block.refresh_flag = 0;
}

#pragma push
#pragma dont_inline on
s32 kar_greventlighthouse_get_ui_refresh_flag(void)
{
    s8 flag = kar_greventlighthouse_ui_work_state_block.refresh_flag;

    return flag;
}
#pragma pop

void kar_greventlighthouse_init_ui_work_state_and_base_light(void)
{
    s32 player;
    void* scene_data;
    void* light_array;
    void* first_light;
    HSD_LightDesc* light_desc;
    HSD_GObj* gobj;
    HSD_LObj* lobj;

    memset(&kar_greventlighthouse_ui_work_state_block, 0,
           sizeof(kar_greventlighthouse_ui_work_state_block));

    switch ((s8) fn_800092B4()) {
    case 1:
        kar_greventlighthouse_ui_work_state_block.ui_mode = 1;
        break;
    case 2:
        kar_greventlighthouse_ui_work_state_block.ui_mode = 2;
        break;
    default:
        kar_greventlighthouse_ui_work_state_block.ui_mode = 4;
        break;
    }

    for (player = 0; player < 4; player++) {
        kar_greventlighthouse_ui_work_state_block.player_slots[player] =
            fn_80009940(player);
    }

    kar_greventlighthouse_ui_work_state_block.refresh_flag = 1;
    kar_lbarchive__80059818(lbl_805DD770, IFALL_NAME(0));
    kar_lbarchive__near_80059520(lbl_805DD770[0], &scene_data,
                                 kar_greventlighthouse_gpanel_scene_data_name, 0);
    kar_greventlighthouse_ui_work_state_block.gpanel_scene_data = scene_data;

    HSD_ObjAllocInit(&kar_greventlighthouse_panel_obj_allocator_e4, 0xE4, 4);
    HSD_ObjAllocInit(&kar_greventlighthouse_panel_obj_allocator_600.data, 0x600,
                     4);

    fn_801158C0();
    fn_801159C0();

    light_array = *(void**) ((u8*) scene_data + 8);
    first_light = *(void**) light_array;
    light_desc = *(HSD_LightDesc**) first_light;
    gobj = HSD_GObjCreate(0x1B, 1, 0);
    lobj = HSD_LObjLoadDesc(light_desc);
    HSD_GObjObjectLink(gobj, hsdGObj_lobj_kind, lobj);
    HSD_GObjGXLink(gobj, (void (*)(HSD_GObj*, s32)) HSD_GObjJObjRemove, 0x11,
                   1);
    kar_greventlighthouse_ui_work_state_block.light_gobj = gobj;
}

void kar_greventlighthouse_load_ifall_archives_and_init_panels(void)
{
    if (SPECIAL_CITYTRIAL_LAN_DIAG) {
        switch (WORK_MODE) {
        case 1:
            kar_lbarchive__80059818(&lbl_805DD76C, IFALL_NAME(1));
            break;
        case 2:
            kar_lbarchive__80059818(&lbl_805DD76C, IFALL_NAME(2));
            break;
        default:
            kar_lbarchive__80059818(&lbl_805DD76C, IFALL_NAME(3));
            break;
        }
    } else {
        switch (WORK_MODE) {
        case 1:
            kar_lbarchive__80059818(&lbl_805DD76C, IFALL_NAME(4));
            break;
        case 2:
            kar_lbarchive__80059818(&lbl_805DD76C, IFALL_NAME(5));
            break;
        default:
            kar_lbarchive__80059818(&lbl_805DD76C, IFALL_NAME(6));
            break;
        }
    }

    fn_80117DE8();
    fn_8011878C();
    fn_801191A0();
    fn_8011F8A8();
    fn_801202CC();
    fn_801196EC();
    fn_80119DB4();
    fn_8011EF70();
    kar_diag__8011c3b4();
    kar_ifround_load_readygo_timeup_finish_scene_models();
    kar_ifround_load_mmapply_scene_models();
    kar_ifround_load_mmapstart_scene_models();
    fn_80124844();
    fn_80124BD4();
    fn_80125390();
    fn_80122DD8();
    fn_8012322C();
    fn_801237E4();
    fn_80125E7C();
    fn_80125780();
    fn_80125940();
    fn_80123C90();
    fn_80123FE0();
    fn_801244D4();
    fn_8012A56C();
    fn_80130CFC();
    fn_801284F8();
    fn_80128AFC();
    fn_80129108();

    if (!SPECIAL_CITYTRIAL_LAN_DIAG) {
        fn_8011A374();
        fn_8011AC3C();
        fn_8011B678();
        kar_ifround_load_laprec_scene_models();
        kar_ifround_load_wrongway_scene_models();
        kar_ifround_load_finallap_scene_models();
        fn_801250D0();
        fn_8012122C();
        fn_80126390();
        fn_801267EC();
        fn_80128244();
        fn_8012A104();
        fn_801299C8();
        fn_8012D6F8();
    }

    if ((s8) kar_gmracenormal__8000aea8() == 4) {
        if ((s8) kar_gmracenormal__8003d5f0() == 2) {
            fn_8012979C();
        }
        if ((s8) kar_gmracenormal__8003d5f0() == 1) {
            fn_80129D90();
            fn_80129F30();
        }
    }

    if ((s8) kar_diag__8000acb0() == 1) {
        kar_lbarchive__80059818(&lbl_805DD768, IFALL_NAME(7));
        switch (WORK_MODE) {
        case 1:
            kar_lbarchive__80059818(&lbl_805DD764, IFALL_NAME(8));
            break;
        case 2:
            kar_lbarchive__80059818(&lbl_805DD764, IFALL_NAME(9));
            break;
        default:
            kar_lbarchive__80059818(&lbl_805DD764, IFALL_NAME(10));
            break;
        }

        fn_80121AD8();
        fn_801226E8();
        fn_80126D40();
        fn_801277F0();
        fn_80127E94();
        fn_8012B39C();
        kar_si_assets__asset_801169c8();
        fn_801168E8();
    }

    if ((s8) fn_8000AD48() == 1) {
        kar_lbarchive__80059818(&lbl_805DD760, IFALL_NAME(11));
        switch (WORK_MODE) {
        case 1:
            kar_lbarchive__80059818(&lbl_805DD75C, IFALL_NAME(12));
            break;
        case 2:
            kar_lbarchive__80059818(&lbl_805DD75C, IFALL_NAME(13));
            break;
        default:
            kar_lbarchive__80059818(&lbl_805DD75C, IFALL_NAME(14));
            break;
        }

        kar_ifround_load_round_number_scene_models();
        fn_80130980();
        fn_80130B2C();
        fn_80131008();
        fn_8012B9BC();
        fn_8012C7E4();
        fn_8012DE70();
        fn_8012EB94();
        fn_8012EE4C();
        fn_8012F27C();
        fn_8012F744();
        fn_8012FA34();
        fn_8012FF38();
        fn_80130574();
    }
}

void kar_greventlighthouse_apply_mode_dependent_round_ui_panels(void)
{
    if (*(u8*) ((u8*) kar_gmmain__near_80006c14() + 0xA97) == 0x35) {
        return;
    }

    if (WORK_MODE <= 1 ||
        (WORK_MODE == 4 && (s8) fn_800092B4() == 3)) {
        fn_801166B4();
        fn_80115A64();
        fn_801254F4();

        if ((s8) kar_diag__8000acb0() == 1) {
            fn_80124890();
        } else if ((s8) fn_8000ADA0() == 1) {
            fn_80125174();
        } else {
            if ((s8) fn_8000AD48() == 1) {
                s8 mode = kar_gmracenormal__near_8000ae74();
                if ((mode >= 1 && mode < 6) || mode == 7) {
                    return;
                }
            }
            kar_ifround_create_course_line_map_renderer(WORK_MODE);
        }

        if ((s8) kar_diag__8000acb0() == 0) {
            kar_ifround_create_mmapstart_marker();
        }
        kar_ifround_create_mmapply_player_markers_all_slots();
    } else {
        fn_8012581C();
        if ((s8) kar_diag__8000acb0() == 0) {
            if ((s8) fn_8000AD48() == 1) {
                s8 mode = kar_gmracenormal__near_8000ae74();
                if (mode != 0 && mode != 6) {
                    return;
                }
            }
            fn_80126408();
            fn_80126B1C();
        } else if (WORK_MODE == 2) {
            fn_801166B4();
            fn_80115A64();
            fn_80124890();
            kar_ifround_create_mmapply_player_markers_all_slots();
        }
    }
}

void kar_greventlighthouse_update_round_ui_for_race_state(void)
{
    s32 player;
    s32 slot;
    s32 index;

    if ((s8) fn_8000AAC4() == 1) {
        fn_80113A98();
        return;
    }
    if ((s8) kar_gmracenormal__8000af5c() != 0) {
        fn_80113AD8();
        return;
    }

    for (player = 0; player < 4; player++) {
        if (fn_800098C0(player) != 0) {
            slot = PLAYER_SLOT(player);
            if (slot != -1) {
                fn_80115AF4(player, (s8) fn_80009908(player));
                fn_80117800(slot, player);
            }
        }
    }

    if (WORK_MODE >= 2) {
        fn_801259DC();
    }

    switch ((s8) fn_8000916C()) {
    case 7:
    case 15:
        kar_greventlighthouse_apply_mode_dependent_round_ui_panels();
        for (player = 0; player < 4; player++) {
            if (fn_800098C0(player) != 0) {
                slot = PLAYER_SLOT(player);
                if (slot != -1) {
                    fn_8011A434(slot, player);
                }
            }
        }
        break;
    case 13:
        for (player = 0; player < 4; player++) {
            fn_8012DF94(PLAYER_SLOT(player), player);
        }
        break;
    case 0:
        kar_greventlighthouse_apply_mode_dependent_round_ui_panels();
        for (player = 0; player < 4; player++) {
            if (fn_800098C0(player) != 0) {
                slot = PLAYER_SLOT(player);
                if (slot != -1) {
                    fn_8011A434(slot, player);
                    fn_8011ACFC(slot, player);
                    if (WORK_MODE <= 1) {
                        kar_ifround_create_laprec_player_panel(slot, player);
                        for (index = 0; index < 3; index++) {
                            fn_8011B6C8(slot, player, index);
                        }
                    }
                }
            }
        }
        break;
    case 1:
        kar_greventlighthouse_apply_mode_dependent_round_ui_panels();
        for (player = 0; player < 4; player++) {
            if (fn_800098C0(player) != 0) {
                slot = PLAYER_SLOT(player);
                if (slot != -1) {
                    fn_8011A434(slot, player);
                    fn_8012D7B4(slot, player);
                }
            }
        }
        break;
    case 3:
    case 4:
        kar_greventlighthouse_apply_mode_dependent_round_ui_panels();
        for (player = 0; player < 4; player++) {
            if (fn_800098C0(player) != 0) {
                slot = PLAYER_SLOT(player);
                if (slot != -1) {
                    fn_8011ACFC(slot, player);
                    if (WORK_MODE <= 1) {
                        kar_ifround_create_laprec_player_panel(slot, player);
                        for (index = 0; index < 3; index++) {
                            fn_8011B6C8(slot, player, index);
                        }
                    }
                }
            }
        }
        break;
    case 9:
        kar_greventlighthouse_apply_mode_dependent_round_ui_panels();
        for (player = 0; player < 4; player++) {
            if (PLAYER_SLOT(player) != -1) {
                fn_80113E08(player);
            }
        }
        break;
    case 11:
        kar_greventlighthouse_apply_mode_dependent_round_ui_panels();
        for (player = 0; player < 4; player++) {
            if (PLAYER_SLOT(player) != -1) {
                fn_80113DB0(player);
            }
        }
        break;
    case 5:
        kar_greventlighthouse_apply_mode_dependent_round_ui_panels();
        for (player = 0; player < 4; player++) {
            if (PLAYER_SLOT(player) != -1) {
                fn_80113EB8(player);
            }
        }
        break;
    case 6:
    case 8:
        kar_greventlighthouse_apply_mode_dependent_round_ui_panels();
        break;
    case 14:
        kar_greventlighthouse_apply_mode_dependent_round_ui_panels();
        for (player = 0; player < 4; player++) {
            if (PLAYER_SLOT(player) != -1) {
                fn_80113E60(player);
            }
        }
        break;
    default:
        break;
    }

    fn_80119218();
    for (player = 0; player < 4; player++) {
        if (fn_800098C0(player) != 0) {
            slot = PLAYER_SLOT(player);
            if (slot != -1) {
                fn_80118930(slot, player);
                fn_80117F40(slot, player);
                fn_8011FEBC(slot, player);
                fn_801210A8(slot, player);
                if (fn_8000A188() != 0) {
                    fn_8011F144(slot, player);
                }
                if (WORK_MODE >= 2) {
                    fn_80125FD0(slot, player);
                }
            }
        }
    }
}

void kar_greventlighthouse_create_ifround_panel0_for_player_if_active(s32 player)
{
    s32 slot;

    if (fn_800098C0(player) != 0) {
        slot = PLAYER_SLOT(player);
        if (slot != -1) {
            kar_ifround_create_readygo_timeup_finish_panel_kind(slot, player, 0);
        }
    }
}

void fn_8011370C(s32 slot)
{
    s32 player;
    s32 mapped_player = -1;

    if (SPECIAL_CITYTRIAL_LAN_DIAG) {
        return;
    }

    for (player = 0; player < 4; player++) {
        if (PLAYER_SLOT(player) == slot) {
            mapped_player = player;
            break;
        }
    }

    if (fn_800098C0(mapped_player) != 0) {
        kar_ifround_create_or_retrigger_wrongway_warning_panel(slot, mapped_player);
    }
}

void fn_801137F0(s32 slot)
{
    s32 player;
    s32 mapped_player = -1;

    if (SPECIAL_CITYTRIAL_LAN_DIAG) {
        return;
    }

    for (player = 0; player < 4; player++) {
        if (PLAYER_SLOT(player) == slot) {
            mapped_player = player;
            break;
        }
    }

    if (fn_800098C0(mapped_player) != 0) {
        kar_ifround_create_finallap_player_panel(slot, mapped_player);
    }
}

void fn_801138D4(s32 arg0)
{
    kar_ifround_create_round_number_panel();
}

void fn_801138F4(void)
{
    fn_80126B54();
}

void fn_80113914(s32 arg0)
{
    s32 player;
    s32 slot;
    s32 index;

    if ((s8) kar_gmracenormal__8000aea8() == 4 ||
        (s8) kar_gmracenormal__8000aea8() == 7) {
        if ((s8) kar_gmracenormal__8003d5f0() == 2) {
            fn_801297E8(arg0);
        } else {
            fn_80128328(arg0);
        }
    } else {
        fn_801285DC(arg0);

        if ((s8) kar_gmracenormal__near_8000ae2c() == 0 &&
            (s8) fn_8000C768() != 0) {
            for (player = 0; player < 4; player++) {
                if (fn_800098C0(player) != 0) {
                    slot = PLAYER_SLOT(player);
                    if (slot != -1) {
                        fn_80128BB8(slot, player);
                        for (index = 0; index < 9; index++) {
                            fn_80129154(slot, player, index);
                        }
                    }
                }
            }
        }
    }
}

void fn_80113A24(void)
{
    if (lbl_805DD638 != 0) {
        fn_80128448();
    } else if ((s8) kar_diag__8000acb0() == 0 &&
               (s8) fn_8000AD48() == 0) {
        if ((s8) kar_gmracenormal__8003d5f0() == 2) {
            fn_8012993C();
        } else {
            fn_80128448();
        }
    } else {
        fn_80128A68();
        fn_80129034();
        fn_801294A8();
    }
}

void fn_80113A98(void)
{
    s32 player;

    fn_80129A14();
    for (player = 0; player < 4; player++) {
        fn_80009888(player);
    }
}

void fn_80113AD8(void)
{
    s32 player;

    for (player = 0; player < 4; player++) {
        if ((s8) fn_80009888(player) != 4) {
            fn_80009888(player);
        }
    }
}

void fn_80113B28(s32 slot)
{
    s32 player;
    s32 mapped_player = -1;

    for (player = 0; player < 4; player++) {
        if (PLAYER_SLOT(player) == slot) {
            mapped_player = player;
            break;
        }
    }

    if (fn_800098C0(mapped_player) != 0) {
        fn_80130DB8(slot, mapped_player);
    }
}

void fn_80113BE0(s32 player)
{
    if (fn_800098C0(player) != 0) {
        fn_801310C4(PLAYER_SLOT(player), player);
    }
}

void fn_80113C38(s32 player)
{
    fn_8012BAE0(PLAYER_SLOT(player), player);
}

void fn_80113C70(s32 player)
{
    fn_8012C908(PLAYER_SLOT(player), player);
}

void fn_80113CA8(s32 player)
{
    if (fn_800098C0(player) != 0) {
        fn_8012EF08(PLAYER_SLOT(player), player);
    }
}

void fn_80113D00(s32 player)
{
    if (fn_800098C0(player) != 0) {
        fn_8012F338(PLAYER_SLOT(player), player);
    }
}

void fn_80113D58(s32 player)
{
    if (fn_800098C0(player) != 0) {
        fn_8012F800(PLAYER_SLOT(player), player);
    }
}

void fn_80113DB0(s32 player)
{
    if (fn_800098C0(player) != 0) {
        fn_8012FAF0(PLAYER_SLOT(player), player);
    }
}

void fn_80113E08(s32 player)
{
    if (fn_800098C0(player) != 0) {
        fn_8012FFF4(PLAYER_SLOT(player), player);
    }
}

void fn_80113E60(s32 player)
{
    if (fn_800098C0(player) != 0) {
        fn_8013065C(PLAYER_SLOT(player), player);
    }
}

void fn_80113EB8(s32 player)
{
    if (fn_800098C0(player) != 0) {
        fn_8012B580(PLAYER_SLOT(player), player);
    }
}

void fn_80113F10(s32 player, s32 arg1, void* arg2)
{
    if ((s8) fn_8000AAC4() == 0 &&
        (s8) kar_gmracenormal__8000af5c() == 0 &&
        (s8) fn_8000A97C() == 0 && fn_800098C0(player) != 0) {
        fn_8012A640(PLAYER_SLOT(player), player, arg1, arg2);
    }
}

void fn_80113FB4(s32 arg0, s32 arg1)
{
    if ((s8) kar_diag__8000acb0() != 0 || (s8) fn_8000AD48() != 0) {
        fn_80127864(arg0, arg1, 1);
    }
}

void fn_80114010(void* arg0)
{
    s32 player;
    s32 slot;

    if ((s8) kar_diag__8000acb0() != 0 || (s8) fn_8000AD48() != 0) {
        for (player = 0; player < 4; player++) {
            if (fn_800098C0(player) != 0) {
                slot = PLAYER_SLOT(player);
                if (slot != -1) {
                    fn_80127F54(slot, player, arg0);
                }
            }
        }

        if (WORK_MODE <= 1 || WORK_MODE == 2 ||
            (WORK_MODE == 4 && (s8) fn_800092B4() == 3)) {
            fn_80124E98(0, arg0);
        }
    }
}

void fn_801140E4(s32 arg0)
{
    s32 player;

    if ((s8) kar_diag__8000acb0() != 0 || (s8) fn_8000AD48() != 0) {
        for (player = 0; player < 4; player++) {
            fn_80128108(player, arg0);
        }
        fn_80124F9C(0, arg0);
    }
}

void fn_80114154(void)
{
    fn_80128170();
    fn_80125004();
}

void fn_80114178(s32 slot)
{
    s32 player;
    s32 mapped_player = -1;

    for (player = 0; player < 4; player++) {
        if (PLAYER_SLOT(player) == slot) {
            mapped_player = player;
            break;
        }
    }

    if (fn_800098C0(mapped_player) != 0) {
        kar_ifround_create_readygo_timeup_finish_panel_kind(slot, mapped_player,
                                                           1);
    }
}

void fn_80114234(void)
{
    s32 slot;
    s32 player;

    for (slot = 0; slot < 4; slot++) {
        player = -1;
        if (PLAYER_SLOT(0) == slot) {
            player = 0;
        } else if (PLAYER_SLOT(1) == slot) {
            player = 1;
        } else if (PLAYER_SLOT(2) == slot) {
            player = 2;
        } else if (PLAYER_SLOT(3) == slot) {
            player = 3;
        }

        if (fn_800098C0(player) != 0) {
            fn_8011F688(player);
        }
    }
}

void fn_801142FC(s32 slot)
{
    s32 player;
    s32 mapped_player = -1;

    for (player = 0; player < 4; player++) {
        if (PLAYER_SLOT(player) == slot) {
            mapped_player = player;
            break;
        }
    }

    if ((s8) kar_gmracenormal__8000aea8() == 4 &&
        (s8) kar_gmracenormal__8003d5f0() == 1) {
        fn_801143E8(mapped_player);
        fn_80118F20();
    } else if (fn_800098C0(mapped_player) != 0) {
        kar_ifround_create_readygo_timeup_finish_panel_kind(slot, mapped_player,
                                                           2);
    }
}

void fn_801143E8(s32 player)
{
    LighthouseUIWorkState* work = &kar_greventlighthouse_ui_work_state_block;
    s32 slot;
    s32 should_create;
    s32 out[8];

    if (fn_800098C0(player) != 0) {
        if ((slot = (s8) work->player_slots[player]) != -1) {
            kar_greventlighthouse_show_all_round_ui_components();
            fn_80129DDC(slot);

            if (fn_800419B8(4, (s8) kar_gmracenormal__800092fc(), out) == 1) {
                if (fn_800097D0(slot) < out[2]) {
                    should_create = 1;
                } else {
                    should_create = 0;
                }
            } else {
                should_create = 1;
            }

            if (should_create != 0) {
                fn_80129F7C(slot);
            }
        }
    }
}

void fn_801144A0(s32 arg0)
{
    if ((s8) fn_8000AAC4() != 0) {
        goto done;
    }

    if ((s8) kar_gmracenormal__8000af5c() == 0) {
        goto check_a97c;
    }
    goto done;

check_a97c:
    if ((s8) fn_8000A97C() == 0) {
        if (!SPECIAL_CITYTRIAL_LAN_DIAG) {
            fn_80121534(arg0);
        }
    }

done:;
}

void fn_80114524(void)
{
    fn_801218A4();
}

void fn_80114544(void)
{
    fn_801217AC();
}

void fn_80114564(void)
{
    fn_801216B4();
}

void fn_80114584(void)
{
    fn_801221C8();
}

void fn_801145A4(void)
{
    LighthouseUIWorkState* work = &kar_greventlighthouse_ui_work_state_block;
    s32 i;

    if (work->gobj_0C != NULL) {
        HSD_GObjDestroy(work->gobj_0C);
        work->gobj_0C = NULL;
    }

    if (work->gobj_10 != NULL) {
        HSD_GObjDestroy(work->gobj_10);
        work->gobj_10 = NULL;
    }

    for (i = 0; i < 4; i++) {
        if (work->player_gobjs[i] != NULL) {
            HSD_GObjDestroy(work->player_gobjs[i]);
            work->player_gobjs[i] = NULL;
        }
    }

    if (work->gobj_24 != NULL) {
        HSD_GObjDestroy(work->gobj_24);
        work->gobj_24 = NULL;
    }

    if (work->gobj_28 != NULL) {
        HSD_GObjDestroy(work->gobj_28);
        work->gobj_28 = NULL;
    }

    if (work->gobj_2C != NULL) {
        HSD_GObjDestroy(work->gobj_2C);
        work->gobj_2C = NULL;
    }

    if (work->light_gobj != NULL) {
        HSD_GObjDestroy(work->light_gobj);
        work->light_gobj = NULL;
    }

    lbl_805DD770[0] = NULL;
    lbl_805DD76C = NULL;
    lbl_805DD768 = NULL;
    lbl_805DD764 = NULL;
    lbl_805DD760 = NULL;
    lbl_805DD75C = NULL;
    lbl_805DD758 = NULL;

    fn_8011693C();
    fn_80117AC0();
    fn_801181EC();
    fn_80118E88();
    fn_8011944C();
    fn_8011FF78();
    fn_80121100();
    fn_80119C88();
    fn_8011A0C8();
    fn_8011A60C();
    fn_8011B1C4();
    kar_ifround_destroy_laprec_split_digit_gobjs_all_players();
    kar_ifround_destroy_laprec_player_panels();
    fn_8011F6EC();
    kar_ifround_destroy_wrongway_warnings_all_players();
    kar_ifround_destroy_clearchecker_warnings_all_players();
    kar_ifround_destroy_readygo_timeup_finish_all_players();
    kar_ifround_destroy_finallap_panels_all_players();
    kar_ifround_destroy_course_line_map_renderer();
    kar_ifround_destroy_mmapply_player_markers_all_slots();
    fn_8011E824();
    fn_80124AE4();
    fn_80125004();
    fn_801252E8();
    fn_801256BC();
    fn_80121970();
    fn_80122F50();
    fn_8012350C();
    fn_80123AB8();
    fn_80124750();
    fn_80124798();
    fn_801262A8();
    fn_801258DC();
    fn_80125DAC();
    fn_80126574();
    fn_80126BE4();
    fn_80128448();
    fn_8012A36C();
    fn_80123E80();
    fn_8012434C();
    fn_801246D8();
    fn_8012AAA0();
    fn_80130E84();
    kar_ifround_destroy_round_number_panel();
    fn_8012229C();
    fn_80122A6C();
    fn_801275B4();
    fn_80127A04();
    fn_80128170();
    fn_80128A68();
    fn_80129034();
    fn_801294A8();
    fn_8012993C();
    fn_80129AB8();
    fn_8012DC48();
    fn_80130A3C();
    fn_80130BE8();
    fn_80131178();
    fn_8012C4FC();
    fn_8012D344();
    fn_8012EA90();
    fn_8012EC50();
    fn_8012F01C();
    fn_8012F45C();
    fn_8012F944();
    fn_8012FE48();
    fn_8013016C();
    fn_80130878();
    fn_8012B6C8();
}

char lbl_804A7B60[0x0A] = "translate";
__declspec(section ".data") u8 gap_804A7B6A_data[2] = { 0, 0 };
char lbl_804A7B6C[0x16] = "info userdata error!\n";
__declspec(section ".data") u8 gap_804A7B82_data[2] = { 0, 0 };
u8 lbl_804A7B84[0x14] = {
    0x01, 0x00, 0x09, 0x08, 0x10, 0x07, 0x04, 0x03, 0x0F, 0x06,
    0x0B, 0x05, 0x02, 0x0A, 0x0D, 0x0E, 0x0C, 0x00, 0x00, 0x00,
};
s32 lbl_804A7B98[0x28] = {
    0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,
    0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11,
    0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,
    0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21,
    0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29,
};
LighthouseCamWObjDesc lbl_804A7C38 = {
    NULL,
    { 0.0F, 0.0F, 30.0F },
    NULL,
};
LighthouseCamWObjDesc lbl_804A7C4C = {
    NULL,
    { 0.0F, 0.0F, 0.0F },
    NULL,
};
LighthouseCameraDesc lbl_804A7C60 = {
    NULL,
    0,
    PROJ_ORTHO,
    0, 0x280, 0, 0x1E0,
    0, 0x280, 0, 0x1E0,
    &lbl_804A7C38,
    &lbl_804A7C4C,
    0.0F,
    NULL,
    0.1F,
    32768.0F,
    0.0F, -48.0F, 0.0F, 64.0F,
};
char kar_linkfile_siscitytrial_dat_804a7ca0[0x11] = "SisCitytrial.dat";
__declspec(section ".data") u8 gap_804A7CB1_data[3] = { 0, 0, 0 };
char lbl_804A7CB4[0x12] = "SIS_CitytrialData";
__declspec(section ".data") u8 gap_804A7CC6_data[2] = { 0, 0 };

__declspec(section ".sdata") char kar_srcfile_jobj_h_805d6388[7] = "jobj.h";
__declspec(section ".sdata") char lbl_805D6390[5] = "jobj";
__declspec(section ".sdata") char kar_srcfile_iflib_c_805d6398[8] = "iflib.c";
__declspec(section ".sdata") char lbl_805D63A0[2] = "";

HSD_GObj* fn_801147DC(HSD_Joint* joint, u8 p_link, u8 gx_link, u8 priority)
{
    HSD_GObj* gobj;
    HSD_JObj* jobj;

    gobj = HSD_GObjCreate(0x1B, p_link, 0);
    jobj = HSD_JObjLoadJoint(joint);
    HSD_GObjObjectLink(gobj, hsdGObj_jobj_kind, jobj);
    HSD_GObjGXLink(gobj, fn_8011500C, gx_link, priority);
    kar_gmlanmenu__near_80052fb8(jobj, 0x28000000);
    return gobj;
}

HSD_GObj* fn_8011487C(HSD_Joint* joint)
{
    HSD_JObj* jobj;
    HSD_GObj* gobj;

    gobj = HSD_GObjCreate(0x1B, 0x1A, 0);
    jobj = HSD_JObjLoadJoint(joint);
    HSD_GObjObjectLink(gobj, hsdGObj_jobj_kind, jobj);
    HSD_GObjGXLink(gobj, fn_8011500C, 0x15, 1);
    kar_gmlanmenu__near_80052fb8(jobj, 0x28000000);
    return gobj;
}

HSD_GObj* fn_80114904(s32 player, HSD_Joint* joint)
{
    HSD_GObj* gobj;
    HSD_JObj* jobj;

    gobj = HSD_GObjCreate(0x1B, 0x1A, 0);
    jobj = HSD_JObjLoadJoint(joint);
    HSD_GObjObjectLink(gobj, hsdGObj_jobj_kind, jobj);
    HSD_GObjGXLink(gobj, fn_8011500C, (u8) (player + 0x16), 1);
    kar_gmlanmenu__near_80052fb8(jobj, 0x28000000);
    return gobj;
}

HSD_GObj* fn_801149A0(s32 arg0, HSD_Joint* joint,
                      void (*render_cb)(HSD_GObj*, s32))
{
    HSD_GObj* gobj;
    HSD_JObj* jobj;

    gobj = HSD_GObjCreate(0x1B, 0x1A, 0);
    HSD_GObjGXLink(gobj, render_cb, 0x12, 1);
    if (joint != NULL) {
        jobj = HSD_JObjLoadJoint(joint);
        HSD_GObjObjectLink(gobj, hsdGObj_jobj_kind, jobj);
        kar_gmlanmenu__near_80052fb8(jobj, 0x28000000);
    }
    return gobj;
}

void fn_80114D08(HSD_JObj* jobj, s32 index, void* anim, f32 frame, f32 rate)
{
    HSD_JObjRemoveAnimAll(jobj);
    kar_lbairride__near_80055a30(jobj, index, anim);
    HSD_JObjReqAnimAll(jobj, frame);
    kar_lbairride__near_800550bc(jobj, 0xFFFF, rate);
    HSD_JObjAnimAll(jobj);
}

void fn_80114D9C(HSD_JObj* jobj, void* anim, f32 frame, f32 rate)
{
    HSD_JObjRemoveAnimAll(jobj);
    kar_lbairride__near_80055a30(jobj, 0, anim);
    HSD_JObjReqAnimAll(jobj, frame);
    kar_lbairride__near_800550bc(jobj, 0xFFFF, rate);
    HSD_JObjAnimAll(jobj);
}

#pragma push
#pragma dont_inline on
void* kar_diag__80114e24(HSD_GObj* gobj, void* arg1, s32 arg2, s32 arg3)
{
    LighthousePanelUserData* data;

    data = HSD_ObjAlloc(&kar_greventlighthouse_panel_obj_allocator_e4);
    if (data == NULL) {
        OSReport(lbl_804A7B6C);
        __assert(kar_srcfile_iflib_c_805d6398, 0x9C4, lbl_805D63A0);
    }

    memset(data, 0, sizeof(LighthousePanelUserData));
    HSD_GObjUserDataLink(gobj, 0x1B, fn_801151E8, data);
    data->data_04 = arg1;
    data->flags_08.arg2 = arg2;
    data->flags_08.player = arg3;
    data->flags_08.visible = 1;
    return data;
}
#pragma pop

#pragma push
#pragma dont_inline on
void fn_80114EEC(HSD_GObj* gobj)
{
    LighthousePanelUserData* data = gobj->user_data;

    data->flags_08.visible = 1;
}
#pragma pop

#pragma push
#pragma dont_inline on
void fn_80114F04(HSD_GObj* gobj)
{
    LighthousePanelUserData* data = gobj->user_data;

    data->flags_08.visible = 0;
}
#pragma pop

void fn_80114F1C(HSD_GObj* gobj, s32 pass)
{
    LighthousePanelUserData* data;
    Scissor rect;
    s32 player;

    data = gobj->user_data;
    if (data->flags_08.visible) {
        player = (s8) fn_80009908(data->flags_08.player);
        switch (WORK_MODE) {
        case 2:
            kar_lbcamera__near_80068588(player, &rect);
            GXSetScissor(rect.left, rect.top, rect.right - rect.left,
                         rect.bottom - rect.top);
            break;
        case 3:
        case 4:
            kar_lbcamera__near_800685ac(player, &rect);
            GXSetScissor(rect.left, rect.top, rect.right - rect.left,
                         rect.bottom - rect.top);
            break;
        default:
            break;
        }
        HSD_GObjJObjDisp(gobj, pass);
        kar_lbcamera__near_80068574(&rect);
        GXSetScissor(rect.left, rect.top, rect.right - rect.left,
                     rect.bottom - rect.top);
    }
}

void fn_8011500C(HSD_GObj* gobj, s32 pass)
{
    LighthousePanelUserData* data = gobj->user_data;

    if (data->flags_08.visible) {
        HSD_GObjJObjDisp(gobj, pass);
    }
}

void fn_8011503C(HSD_JObj* jobj, s32 frame)
{
    HSD_JObjReqAnimAll(jobj, (f32) frame);
    kar_lbairride__near_800550bc(jobj, 0xFFFF, lbl_805DFB48);
    HSD_JObjAnimAll(jobj);
}

void fn_801150A0(HSD_JObj* jobj, s32 frame, f32 rate)
{
    kar_lbairride__near_80055acc(jobj, (f32) frame);
    kar_lbairride__near_800550bc(jobj, 0x400, rate);
    HSD_JObjAnimAll(jobj);
}

void fn_80115114(HSD_JObj* jobj, s32 frame)
{
    kar_lbairride__near_80055acc(jobj, (f32) frame);
    kar_lbairride__near_800550bc(jobj, 0x400, lbl_805DFB48);
    HSD_JObjAnimAll(jobj);
}

void fn_80115174(HSD_JObj* jobj, s32 frame, f32 rate)
{
    kar_lbairride__near_80055aa8(jobj, (f32) frame);
    kar_lbairride__near_800550bc(jobj, 0x80, rate);
    HSD_JObjAnimAll(jobj);
}

void fn_801151E8(void* data)
{
    HSD_ObjFree(&kar_greventlighthouse_panel_obj_allocator_e4, data);
}

f32 fn_80115214(void)
{
    if ((s8) fn_800092B4() <= 1) {
        return lbl_805DFB58;
    }
    if ((s8) fn_800092B4() == 2) {
        return lbl_805DFB5C;
    }
    return lbl_805DFB60;
}

void fn_80115264(HSD_GObj* gobj)
{
    LighthousePanelUserData* data = gobj->user_data;
    f32 scale;

    data->scale_0C = lbl_805DFB58;
    if ((s8) fn_800092B4() <= 1) {
        scale = lbl_805DFB58;
    } else if ((s8) fn_800092B4() == 2) {
        scale = lbl_805DFB5C;
    } else {
        scale = lbl_805DFB60;
    }
    data->mode_scale_10 = scale;
}

void fn_801152CC(HSD_GObj* gobj, HSD_JObj* jobj)
{
    LighthousePanelUserData* data = gobj->user_data;
    Vec scale;
    f32 value;

    data->scale_0C = lbl_805DFB58;
    value = data->mode_scale_10 * data->scale_0C;
    scale.x = value;
    scale.y = value;
    scale.z = value;
    if (jobj == NULL) {
        __assert(kar_srcfile_jobj_h_805d6388, 0x316, lbl_805D6390);
    }
    jobj->scale = scale;
    if (!(jobj->flags & 0x02000000)) {
        HSD_JObjSetMtxDirty(jobj);
    }
}

void fn_80115398(HSD_GObj* gobj, HSD_JObj* jobj, f32 arg2, f32 arg3)
{
    LighthousePanelUserData* data = gobj->user_data;
    Vec scale;
    f32 value;

    if (arg2 >= lbl_805DFB64) {
        data->scale_0C = lbl_805DFB68 + (lbl_805DFB58 - (arg2 / arg3));
    } else {
        data->scale_0C = lbl_805DFB64;
    }
    value = data->mode_scale_10 * data->scale_0C;
    scale.x = value;
    scale.y = value;
    scale.z = value;
    if (jobj == NULL) {
        __assert(kar_srcfile_jobj_h_805d6388, 0x316, lbl_805D6390);
    }
    jobj->scale = scale;
    if (!(jobj->flags & 0x02000000)) {
        HSD_JObjSetMtxDirty(jobj);
    }
}

s32 fn_80115490(s32 mode, s32 player, Vec* pos, f32 top, f32 bottom, f32 left,
                f32 right)
{
    s32 viewport = (s8) fn_80009908(player);

    switch ((u8) mode) {
    case 1:
        if (viewport == 0) {
            goto mode1_viewport0;
        }
        goto success;
mode1_viewport0:
        if (pos->y < top) {
            return 0;
        }
        if (pos->y > lbl_805DFB6C - bottom) {
            return 0;
        }
        if (pos->x < left) {
            return 0;
        }
        if (pos->x > lbl_805DFB70 - right) {
            return 0;
        }
        break;
    case 2:
        switch (viewport) {
        case 0:
            if (pos->y < top) {
                return 0;
            }
            if (pos->y > lbl_805DFB74 - bottom) {
                return 0;
            }
            if (pos->x < left) {
                return 0;
            }
            if (pos->x > lbl_805DFB70 - right) {
                return 0;
            }
            break;
        case 1:
            if (pos->y < lbl_805DFB74 + top) {
                return 0;
            }
            if (pos->y > lbl_805DFB6C - bottom) {
                return 0;
            }
            if (pos->x < left) {
                return 0;
            }
            if (pos->x > lbl_805DFB70 - right) {
                return 0;
            }
            break;
        default:
            break;
        }
        break;
    case 4:
        switch (viewport) {
        case 0:
            if (pos->y < top) {
                return 0;
            }
            if (pos->y > lbl_805DFB74 - bottom) {
                return 0;
            }
            if (pos->x < left) {
                return 0;
            }
            if (pos->x > lbl_805DFB78 - right) {
                return 0;
            }
            break;
        case 1:
            if (pos->y < lbl_805DFB74 + top) {
                return 0;
            }
            if (pos->y > lbl_805DFB6C - bottom) {
                return 0;
            }
            if (pos->x < left) {
                return 0;
            }
            if (pos->x > lbl_805DFB78 - right) {
                return 0;
            }
            break;
        case 2:
            if (pos->y < top) {
                return 0;
            }
            if (pos->y > lbl_805DFB74 - bottom) {
                return 0;
            }
            if (pos->x < lbl_805DFB78 + left) {
                return 0;
            }
            if (pos->x > lbl_805DFB70 - right) {
                return 0;
            }
            break;
        case 3:
            if (pos->y < lbl_805DFB74 + top) {
                return 0;
            }
            if (pos->y > lbl_805DFB6C - bottom) {
                return 0;
            }
            if (pos->x < lbl_805DFB78 + left) {
                return 0;
            }
            if (pos->x > lbl_805DFB70 - right) {
                return 0;
            }
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }

success:
    return 1;
}

void fn_8011582C(HSD_GObj* gobj)
{
    HSD_GObjDestroy(gobj);
}

u8 fn_8011584C(s32 row, s32 column)
{
    return lbl_804A7B84[(s8) column + (s8) row * 0xC];
}

void fn_8011586C(HSD_GObj* gobj, s32 pass)
{
    if (kar_greventlighthouse_get_ui_refresh_flag() != 0) {
        if (HSD_CObjSetCurrent(gobj->hsd_obj)) {
            GObj_SetTextureCamera(gobj, 7);
            HSD_CObjEndCurrent();
        }
    }
}

void fn_801158C0(void)
{
    LighthouseUIWorkState* work;
    HSD_CObjDesc* desc;
    HSD_GObj* gobj;
    HSD_CObj* cobj;

    work = kar_greventlighthouse_get_ui_work_state_block();
    desc = (*(HSD_CObjDesc***) ((u8*) work->gpanel_scene_data + 4))[0];
    gobj = HSD_GObjCreate(5, 0x13, 0);
    cobj = kar_lbcamera_load_desc_update_aspect(desc);
    HSD_GObjObjectLink(gobj, hsdGObj_default_object_kind, cobj);
    GObj_SetupGXLinkMax(gobj, fn_8011586C, 5);
    ((u32*) &gobj->gxlink_prios)[1] = 0x220000;
    ((u32*) &gobj->gxlink_prios)[0] = 0;
    work->gobj_0C = gobj;
    kar_lbcamera_apply_viewport_preset1(cobj);
}

void fn_8011596C(HSD_GObj* gobj, s32 pass)
{
    if (kar_greventlighthouse_get_ui_refresh_flag() != 0) {
        if (HSD_CObjSetCurrent(gobj->hsd_obj)) {
            GObj_SetTextureCamera(gobj, 7);
            HSD_CObjEndCurrent();
        }
    }
}

void fn_801159C0(void)
{
    LighthouseUIWorkState* work;
    HSD_GObj* gobj;
    HSD_CObj* cobj;

    work = kar_greventlighthouse_get_ui_work_state_block();
    gobj = HSD_GObjCreate(5, 0x13, 0);
    cobj = kar_lbcamera_load_desc_update_aspect((HSD_CObjDesc*) &lbl_804A7C60);
    HSD_GObjObjectLink(gobj, hsdGObj_default_object_kind, cobj);
    GObj_SetupGXLinkMax(gobj, fn_8011596C, 4);
    ((u32*) &gobj->gxlink_prios)[1] = 0x40000;
    ((u32*) &gobj->gxlink_prios)[0] = 0;
    work->gobj_24 = gobj;
    kar_lbcamera_apply_viewport_preset1(cobj);
}

void fn_80115A64(void)
{
    LighthouseUIWorkState* work;
    HSD_CObj* cobj;
    HSD_GObj* gobj;

    work = kar_greventlighthouse_get_ui_work_state_block();
    gobj = HSD_GObjCreate(5, 0x13, 0);
    cobj = kar_lbcamera_load_desc_update_aspect((HSD_CObjDesc*) &lbl_804A7C60);
    HSD_GObjObjectLink(gobj, hsdGObj_default_object_kind, cobj);
    GObj_SetupGXLinkMax(gobj, fn_8011596C, 4);
    ((u32*) &gobj->gxlink_prios)[1] = 0x100000;
    ((u32*) &gobj->gxlink_prios)[0] = 0;
    work->gobj_2C = gobj;
}

void fn_80115AF4(s32 player, s32 arg1)
{
    LighthouseUIWorkState* work;
    HSD_CObjDesc* desc;
    HSD_GObj* gobj;
    HSD_CObj* cobj;

    work = kar_greventlighthouse_get_ui_work_state_block();
    desc = (*(HSD_CObjDesc***) ((u8*) work->gpanel_scene_data + 4))[0];
    gobj = HSD_GObjCreate(5, 0x13, 0);
    cobj = kar_lbcamera_load_desc_update_aspect(desc);
    HSD_GObjObjectLink(gobj, hsdGObj_default_object_kind, cobj);
    GObj_SetupGXLinkMax(gobj, fn_8011586C, 5);
    gobj->gxlink_prios = ((u64) 1 << (player + 0x16)) | 0x20000;
    work->player_gobjs[player] = gobj;

    if ((s8) work->ui_mode == 1) {
        kar_lbcamera_apply_viewport_preset1(cobj);
    } else if ((s8) work->ui_mode == 2) {
        kar_lbcamera_apply_split_viewport_preset1(cobj, arg1);
    } else if ((s8) work->ui_mode == 4) {
        kar_lbcamera_apply_quad_viewport_preset1(cobj, arg1);
    }
}

void fn_80115BF8(HSD_GObj* gobj)
{
    HSD_CObj* cobj;
    LighthouseCameraUserData* data;
    Vec up;
    f32 target_x;
    f32 target_y;
    f32 cos_y;
    f32 sin_x;
    f32 zero;
    f32 target_z;
    f32 neg_zero;

    kar_greventlighthouse_get_ui_work_state_block();
    data = gobj->user_data;
    cobj = gobj->hsd_obj;

    target_x = lbl_805DFB90 * fn_80116268(data->angle_y_1C) - lbl_805DFB88;
    target_y = lbl_805DFB90 * fn_80116268(data->angle_x_18) - lbl_805DFB88;
    cos_y = fn_803BCCD0(data->angle_y_1C);
    sin_x = fn_80115E0C(data->angle_x_18);
    zero = lbl_805DFB88;
    target_z = lbl_805DFB90 * sin_x;
    neg_zero = -zero;
    target_z = (f32) ((f64) target_z * cos_y - zero);

    if (data->mode_14 == 0) {
        if (data->eye_24.y != target_y) {
            if (data->eye_24.y < lbl_805DFB94 + target_y) {
                data->eye_24.x = target_x;
                data->eye_24.y = target_y;
                data->eye_24.z = target_z;
            } else {
                data->eye_24.x += data->step_30.x;
                data->eye_24.y += data->step_30.y;
                data->eye_24.z += data->step_30.z;
            }
        }
    } else {
        if (data->eye_24.y != lbl_805DFB8C) {
            if (data->eye_24.y > lbl_805DFB98) {
                data->eye_24.x = neg_zero;
                data->eye_24.y = lbl_805DFB8C;
                data->eye_24.z = neg_zero;
            } else {
                data->eye_24.x += data->step_30.x;
                data->eye_24.y += data->step_30.y;
                data->eye_24.z += data->step_30.z;
            }
        }
    }

    if ((s8) kar_diag__8000acb0() != 0) {
        data->eye_24.x = neg_zero;
        data->eye_24.y = lbl_805DFB8C;
        data->eye_24.z = neg_zero;
    }

    HSD_CObjSetEyePosition(cobj, &data->eye_24);
    HSD_CObjSetFlags(cobj, 1);
    if (data->mode_14 == 0) {
        up.x = lbl_805DFB88;
        up.y = lbl_805DFB9C;
        up.z = lbl_805DFB88;
    } else {
        up.x = lbl_805DFB88;
        up.y = lbl_805DFB9C;
        up.z = lbl_805DFBA0;
    }
    HSD_CObjSetUpVector(cobj, &up);
}

void fn_801166B4(void)
{
    LighthouseUIWorkState* work;
    HSD_CObjDesc* desc;
    HSD_GObj* gobj;
    HSD_CObj* cobj;
    LighthouseCameraUserData* data;
    Vec vec;
    s32 player;
    f32 cos_y;
    f32 neg_zero;
    f64 z;

    work = kar_greventlighthouse_get_ui_work_state_block();
    desc = (*(HSD_CObjDesc***) ((u8*) work->gpanel_scene_data + 4))[0];
    gobj = HSD_GObjCreate(5, 0x13, 0);
    cobj = kar_lbcamera_load_desc_update_aspect(desc);
    HSD_GObjObjectLink(gobj, hsdGObj_default_object_kind, cobj);
    GObj_SetupGXLinkMax(gobj, fn_8011586C, 4);
    ((u32*) &gobj->gxlink_prios)[1] = 0xA0000;
    ((u32*) &gobj->gxlink_prios)[0] = 0;
    work->gobj_28 = gobj;
    data = kar_diag__80114e24(gobj, (void*) 0x10, 0, 0);

    if ((s8) fn_800092B4() == 3) {
        player = 0;
        do {
            if (fn_800098C0(player) == 0) {
                break;
            }
            player++;
        } while (player < 4);
        kar_lbcamera_apply_quad_viewport_preset1(cobj, player);
    } else if ((s8) fn_800092B4() == 2) {
        kar_lbcamera_apply_viewport_preset4(cobj);
    } else if ((s8) kar_diag__8000acb0() == 0) {
        kar_lbcamera_apply_viewport_preset2(cobj);
    } else {
        kar_lbcamera_apply_viewport_preset3(cobj);
    }

    vec.x = (f32) (lbl_805DFBE8 * sin(data->angle_y_1C) - lbl_805DFB88);
    vec.y = (f32) (lbl_805DFBE8 * sin(data->angle_x_18) - lbl_805DFB88);
    cos_y = fn_803BCCD0(data->angle_y_1C);
    z = lbl_805DFBE8 * fn_803BCCD0(data->angle_x_18);
    vec.z = (f32) (z * cos_y - lbl_805DFB88);
    HSD_CObjSetEyePosition(cobj, &vec);

    neg_zero = -lbl_805DFB88;
    vec.x = neg_zero;
    vec.y = neg_zero;
    vec.z = neg_zero;
    HSD_CObjSetInterest(cobj, &vec);
    HSD_CObjSetFar(cobj, lbl_805DFBF0);

    data = gobj->user_data;
    data->mode_14 = 1;
    data->angle_x_18 = lbl_805DFB80;
    data->angle_y_1C = lbl_805DFB84;
    data->unk_20 = lbl_805DFB88;
    data->eye_24.x = neg_zero;
    data->eye_24.y = lbl_805DFB8C;
    data->eye_24.z = lbl_805DFB88;
    HSD_GObjProcCreate(gobj, fn_80115BF8, 0x14);
}

void fn_801168E8(void)
{
    LighthouseUIWorkState* work;

    work = kar_greventlighthouse_get_ui_work_state_block();
    work->sis_context_44 = HSD_SisLib_803A611C(0, NULL, 0x1C, 0x13, 0, 0x1B,
                                               1, 7);
}

void fn_8011693C(void)
{
    LighthouseUIWorkState* work;

    work = kar_greventlighthouse_get_ui_work_state_block();
    if (work->text_48 != NULL) {
        HSD_SisLib_803A5CC4(work->text_48);
        work->text_48 = NULL;
    }
    if (work->text_4C != NULL) {
        HSD_SisLib_803A5CC4(work->text_4C);
        work->text_4C = NULL;
    }
    if (work->text_50 != NULL) {
        HSD_SisLib_803A5CC4(work->text_50);
        work->text_50 = NULL;
    }
    if (work->text_54 != NULL) {
        HSD_SisLib_803A5CC4(work->text_54);
        work->text_54 = NULL;
    }
}

void kar_si_assets__asset_801169c8(void)
{
    HSD_SisLib_803A62A0(0, kar_linkfile_siscitytrial_dat_804a7ca0,
                        lbl_804A7CB4);
}

void fn_801169FC(s32 arg0)
{
    LighthouseUIWorkState* work;
    HSD_Text* text;
    f32 pos_x;
    f32 pos_y;

    work = kar_greventlighthouse_get_ui_work_state_block();
    if (work->text_48 != NULL) {
        HSD_SisLib_803A5CC4(work->text_48);
        work->text_48 = NULL;
    }

    if ((s8) arg0 != -1) {
        if ((s8) work->ui_mode >= 2) {
            pos_x = lbl_805DFBF8;
            pos_y = lbl_805DFBFC;
        } else {
            pos_x = lbl_805DFC00;
            pos_y = lbl_805DFC04;
        }

        text = HSD_SisLib_803A5ACC(0, work->sis_context_44, pos_x, pos_y,
                                   lbl_805DFC08, lbl_805DFC0C,
                                   lbl_805DFC10);
        work->text_48 = text;
        text->font_size.x = lbl_805DFC14;
        text->font_size.y = lbl_805DFC14;
        HSD_SisLib_803A6368(text, (s8) arg0);
        text->x4C = 0;
    }
}

void fn_80116AC0(s32 player)
{
    LighthouseUIWorkState* work;
    HSD_GObj* gobj;

    work = kar_greventlighthouse_get_ui_work_state_block();
    gobj = work->player_panel_gobjs[player];
    if (gobj != NULL) {
        fn_80114EEC(gobj);
    }
}

void fn_80116B04(s32 player)
{
    LighthouseUIWorkState* work;
    HSD_GObj* gobj;

    work = kar_greventlighthouse_get_ui_work_state_block();
    gobj = work->player_panel_gobjs[player];
    if (gobj != NULL) {
        fn_80114F04(gobj);
    }
}

void fn_80116B48(HSD_GObj* gobj, s32 arg1, s32 arg2)
{
    LighthouseGObjTrackerUserData* data;
    HSD_GObj* cur;
    HSD_GObj* tracked;
    s32 i;
    s8 found;

    data = gobj->user_data;

    for (i = 0; i < 0x20; i++) {
        if (data->gobjs[i] != NULL) {
            cur = hsdGObj_p_link_heads[0xD];
            found = 0;
            while (cur != NULL) {
                if (data->gobjs[i] == cur) {
                    if (fn_80121B24(cur, arg1, arg2) == 1) {
                        found = 1;
                    }
                    break;
                }
                cur = cur->next;
            }
            if (found == 0) {
                data->gobjs[i] = NULL;
                fn_80122128(cur, arg1, arg2);
            }
        }
    }

    cur = hsdGObj_p_link_heads[0xD];
    while (cur != NULL) {
        found = 0;
        for (i = 0; i < 0x20; i++) {
            tracked = data->gobjs[i];
            if (tracked != NULL && tracked == cur) {
                found = 1;
                break;
            }
        }

        if (found == 0 && fn_80121B24(cur, arg1, arg2) == 1) {
            for (i = 0; i < 0x20; i++) {
                if (data->gobjs[i] == NULL) {
                    data->gobjs[i] = cur;
                    fn_80121FF8(cur, arg1, arg2);
                    break;
                }
            }
        }
        cur = cur->next;
    }
}

void fn_80116D8C(HSD_GObj* gobj)
{
    s32 checker_index;
    LighthouseClearCheckerPanelUserData* data;
    s32 player;
    LighthouseClearCheckerValues values;
    s8 counter_6;
    s8 counter_1;
    s8 counter_2;
    s8 counter_3;
    s8 counter_4;
    s8 counter_0;
    s8 counter_7;
    s8 counter_5;
    s8 counter_8;
    s8 event;
    s8 next_state;
    s8 limit;

    kar_greventlighthouse_get_ui_work_state_block();
    data = gobj->user_data;

    if ((s8) fn_8000A958() != 0) {
        if ((s8) fn_8000A958() != 4) {
            return;
        }
    }
    if ((s8) fn_8000AAC4() == 1) {
        return;
    }

    checker_index = data->flags_08.arg2;
    player = data->flags_08.player;
    event = kar_plclearcheckerlib__near_8022cbc0(checker_index);
    if (event != -1) {
        if (data->last_clear_event_14 != event) {
            fn_80119858(checker_index, player, 1);
            data->last_clear_event_14 = event;
        }
        event = -1;
    } else {
        event = kar_plclearchecker_call_clobject_func_191f74(checker_index);
        if (event != -1) {
            if (data->last_clear_event_14 != event) {
                fn_80119858(checker_index, player, 0);
                data->last_clear_event_14 = event;
            }
        } else {
            data->last_clear_event_14 = event;
        }
    }

    switch ((s8) event) {
    case 2:
        next_state = kar_plclearcheckerlib__near_8022cad8(checker_index);
        if (data->sub_state_15 != next_state) {
            if (next_state != 0) {
                fn_80122E24(checker_index, player);
            }
            data->sub_state_15 = next_state;
        }
        break;
    case 4:
        if (lbl_805DFC18 == data->did_state4_18) {
            fn_80123278(checker_index, player);
            data->did_state4_18 = lbl_805DFC1C;
        }
        break;
    case 5:
        if (lbl_805DFC18 == data->did_state5_1C) {
            fn_80123830(checker_index, player);
            data->did_state5_1C = lbl_805DFC1C;
        }
        break;
    default:
        data->sub_state_15 = 0;
        data->did_state4_18 = lbl_805DFC18;
        data->did_state5_1C = lbl_805DFC18;
        break;
    }

    if (kar_plclearcheckerlib__near_8022cf20(checker_index) <=
        lbl_805DFC20) {
        if (kar_cmreplay__8022cc30(checker_index) == 0) {
            kar_ifround_create_clearchecker_warning_panel(checker_index,
                                                          player);
        }
    }

    if (kar_plclearcheckerlib__near_8022d584(checker_index) != 0) {
        fn_80123D50(checker_index, player);
    }

    if (kar_plclearchecker_call_clobject_func_1926f4(checker_index) != 0) {
        if (kar_plclearcheckerlib__near_8022d434(checker_index) != 0) {
            fn_80124184(checker_index, player);
        } else {
            fn_80124594(checker_index, player);
        }
    }

    if ((s8) kar_diag__8000acb0() == 0) {
        if ((s8) fn_8000AD48() == 0) {
            return;
        }
    }
    if ((s8) kar_diag__8000acb0() == 0) {
        return;
    }

    fn_80116B48(gobj, checker_index, player);
    kar_plclearcheckerlib__near_8022cf6c(checker_index, &values);

    if (data->cooldown_2C <= 0) {
        if (data->rank_counter_2A <
            kar_plclearcheckerlib__near_8022d024(checker_index)) {
            limit = (s8) fn_8000AAF0();
            if (data->counters_21[0] < limit) {
                data->counters_21[0]++;
            }
            limit = (s8) fn_8000AAF0();
            if (data->counters_21[1] < limit) {
                data->counters_21[1]++;
            }
            limit = (s8) fn_8000AAF0();
            if (data->counters_21[2] < limit) {
                data->counters_21[2]++;
            }
            limit = (s8) fn_8000AAF0();
            if (data->counters_21[3] < limit) {
                data->counters_21[3]++;
            }
            limit = (s8) fn_8000AAF0();
            if (data->counters_21[4] < limit) {
                data->counters_21[4]++;
            }
            limit = (s8) fn_8000AAF0();
            if (data->counters_21[5] < limit) {
                data->counters_21[5]++;
            }
            limit = (s8) fn_8000AAF0();
            if (data->counters_21[6] < limit) {
                data->counters_21[6]++;
            }
            limit = (s8) fn_8000AAF0();
            if (data->counters_21[7] < limit) {
                data->counters_21[7]++;
            }
            limit = (s8) fn_8000AAF0();
            if (data->counters_21[8] < limit) {
                data->counters_21[8]++;
            }
            data->rank_counter_2A++;
            fn_80127234(checker_index, player, 9, 1);
            data->cooldown_2C = 0x1E;
            return;
        }

        if (data->rank_counter_2A >
            kar_plclearcheckerlib__near_8022d024(checker_index)) {
            limit = (s8) fn_8000AB1C();
            if (data->counters_21[0] > limit) {
                data->counters_21[0]--;
            }
            limit = (s8) fn_8000AB1C();
            if (data->counters_21[1] > limit) {
                data->counters_21[1]--;
            }
            limit = (s8) fn_8000AB1C();
            if (data->counters_21[2] > limit) {
                data->counters_21[2]--;
            }
            limit = (s8) fn_8000AB1C();
            if (data->counters_21[3] > limit) {
                data->counters_21[3]--;
            }
            limit = (s8) fn_8000AB1C();
            if (data->counters_21[4] > limit) {
                data->counters_21[4]--;
            }
            limit = (s8) fn_8000AB1C();
            if (data->counters_21[5] > limit) {
                data->counters_21[5]--;
            }
            limit = (s8) fn_8000AB1C();
            if (data->counters_21[6] > limit) {
                data->counters_21[6]--;
            }
            limit = (s8) fn_8000AB1C();
            if (data->counters_21[7] > limit) {
                data->counters_21[7]--;
            }
            limit = (s8) fn_8000AB1C();
            if (data->counters_21[8] > limit) {
                data->counters_21[8]--;
            }
            data->rank_counter_2A--;
            fn_80127234(checker_index, player, 9, 0);
            data->cooldown_2C = 0x1E;
            return;
        }

        counter_6 = data->counters_21[0];
        if (counter_6 < values.values[6]) {
            data->counters_21[0] = counter_6 + 1;
            fn_80127234(checker_index, player, 6, 1);
            data->cooldown_2C = 0x1E;
            return;
        }
        counter_2 = data->counters_21[1];
        if (counter_2 < values.values[2]) {
            data->counters_21[1] = counter_2 + 1;
            fn_80127234(checker_index, player, 2, 1);
            data->cooldown_2C = 0x1E;
            return;
        }
        counter_1 = data->counters_21[2];
        if (counter_1 < values.values[1]) {
            data->counters_21[2] = counter_1 + 1;
            fn_80127234(checker_index, player, 1, 1);
            data->cooldown_2C = 0x1E;
            return;
        }
        counter_3 = data->counters_21[3];
        if (counter_3 < values.values[3]) {
            data->counters_21[3] = counter_3 + 1;
            fn_80127234(checker_index, player, 3, 1);
            data->cooldown_2C = 0x1E;
            return;
        }
        counter_4 = data->counters_21[4];
        if (counter_4 < values.values[4]) {
            data->counters_21[4] = counter_4 + 1;
            fn_80127234(checker_index, player, 4, 1);
            data->cooldown_2C = 0x1E;
            return;
        }
        counter_0 = data->counters_21[5];
        if (counter_0 < values.values[0]) {
            data->counters_21[5] = counter_0 + 1;
            fn_80127234(checker_index, player, 0, 1);
            data->cooldown_2C = 0x1E;
            return;
        }
        counter_7 = data->counters_21[6];
        if (counter_7 < values.values[7]) {
            data->counters_21[6] = counter_7 + 1;
            fn_80127234(checker_index, player, 7, 1);
            data->cooldown_2C = 0x1E;
            return;
        }
        counter_5 = data->counters_21[7];
        if (counter_5 < values.values[5]) {
            data->counters_21[7] = counter_5 + 1;
            fn_80127234(checker_index, player, 5, 1);
            data->cooldown_2C = 0x1E;
            return;
        }
        counter_8 = data->counters_21[8];
        if (counter_8 < values.values[8]) {
            data->counters_21[8] = counter_8 + 1;
            fn_80127234(checker_index, player, 8, 1);
            data->cooldown_2C = 0x1E;
            return;
        }

        if (counter_6 > values.values[6]) {
            data->counters_21[0] = counter_6 - 1;
            fn_80127234(checker_index, player, 6, 0);
            data->cooldown_2C = 0x1E;
            return;
        }
        if (counter_2 > values.values[2]) {
            data->counters_21[1] = counter_2 - 1;
            fn_80127234(checker_index, player, 2, 0);
            data->cooldown_2C = 0x1E;
            return;
        }
        if (counter_1 > values.values[1]) {
            data->counters_21[2] = counter_1 - 1;
            fn_80127234(checker_index, player, 1, 0);
            data->cooldown_2C = 0x1E;
            return;
        }
        if (counter_3 > values.values[3]) {
            data->counters_21[3] = counter_3 - 1;
            fn_80127234(checker_index, player, 3, 0);
            data->cooldown_2C = 0x1E;
            return;
        }
        if (counter_4 > values.values[4]) {
            data->counters_21[4] = counter_4 - 1;
            fn_80127234(checker_index, player, 4, 0);
            data->cooldown_2C = 0x1E;
            return;
        }
        if (counter_0 > values.values[0]) {
            data->counters_21[5] = counter_0 - 1;
            fn_80127234(checker_index, player, 0, 0);
            data->cooldown_2C = 0x1E;
            return;
        }
        if (counter_7 > values.values[7]) {
            data->counters_21[6] = counter_7 - 1;
            fn_80127234(checker_index, player, 7, 0);
            data->cooldown_2C = 0x1E;
            return;
        }
        if (counter_5 > values.values[5]) {
            data->counters_21[7] = counter_5 - 1;
            fn_80127234(checker_index, player, 5, 0);
            data->cooldown_2C = 0x1E;
            return;
        }
        if (counter_8 > values.values[8]) {
            data->counters_21[8] = counter_8 - 1;
            fn_80127234(checker_index, player, 8, 0);
            data->cooldown_2C = 0x1E;
        }
    } else {
        data->cooldown_2C--;
    }
}

void fn_80117800(s32 slot, s32 player)
{
    LighthouseUIWorkState* work;
    HSD_GObj* gobj;
    LighthouseClearCheckerPanelUserData* data;
    LighthouseClearCheckerValues values;
    s32 i;

    work = kar_greventlighthouse_get_ui_work_state_block();
    if (slot >= 4) {
        return;
    }
    if (player >= 4) {
        return;
    }

    gobj = HSD_GObjCreate(0x1B, 0x1A, 0);
    HSD_GObjProcCreate(gobj, fn_80116D8C, 0x14);
    data = kar_diag__80114e24(gobj, NULL, slot, player);
    data->last_clear_event_14 = -1;
    data->sub_state_15 = 0;
    data->did_state4_18 = lbl_805DFC18;
    data->did_state5_1C = lbl_805DFC18;
    data->field_20 = 1;

    kar_plclearcheckerlib__near_8022cf6c(slot, &values);
    data->counters_21[0] = values.values[6];
    data->counters_21[1] = values.values[2];
    data->counters_21[2] = values.values[1];
    data->counters_21[3] = values.values[3];
    data->counters_21[4] = values.values[4];
    data->counters_21[5] = values.values[0];
    data->counters_21[6] = values.values[7];
    data->counters_21[7] = values.values[5];
    data->counters_21[8] = values.values[8];
    data->cooldown_2C = 0;

    for (i = 0; i < 0x20; i++) {
        data->tracked_gobjs_30[i] = NULL;
    }
    work->player_panel_gobjs[player] = gobj;
}
