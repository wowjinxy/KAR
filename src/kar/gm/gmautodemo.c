#include "functions.h"
#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/mtx/vec.h>
#include <dolphin/os.h>
#include <dolphin/ostime.h>
#include <dolphin/types.h>
#include <kar/gm/gmautodemo.h>
#include <kar/gm/gmglobal.h>
#include <kar/gm/gmclearchecker_8004a648.h>
#include <kar/gm/gmlanmenu.h>
#include <kar/gm/gmmain.h>
#include <kar/gm/gmmovieassets.h>
#include <kar/gm/gmracenormal.h>
#include <kar/lb/lbarchive.h>
#include <kar/lb/lbaudio.h>
#include <kar/lb/lbfile.h>
#include <kar/lb/lbheap.h>
#include <kar/lb/lbhvqm.h>
#include <kar/lb/lbkdcoll.h>
#include <kar/shadow.h>
#include <sysdolphin/gobj_kinds.h>
#include <sysdolphin/random.h>
#include <sysdolphin/video.h>

#define LOAD_F32(sym) (*(const f32*) &(sym))
#define PLAYER_INPUT(i) (*(u32*) (HSD_PadCopyStatus + ((u8) (i) * 0x44) + 8))
#define PAD_MASTER_INPUT(i) (*(u32*) (HSD_PadMasterStatus + ((i) * 0x44)))

typedef struct GmMainWork {
    u8 pad_000[0xC];
    u8 autodemo_state;
    u8 field_00D;
    s16 autodemo_timer;
    u8 pad_010[0x4];
    s8 field_014;
    u8 field_015;
    u8 pad_016;
    u8 field_017;
    u8 pad_018;
    s8 field_019;
    s8 field_01A;
    s8 field_01B;
    s8 field_01C;
    s8 field_01D;
    s8 field_01E;
    s8 field_01F;
    s8 field_020;
    s8 field_021;
    s8 field_022;
    s8 field_023;
    s8 field_024;
    u8 pad_025;
    s8 field_026;
    s8 field_027;
    s8 field_028;
    s8 field_029;
    s8 flag_02A_80 : 1;
    s8 flag_02A_40 : 1;
    s8 flag_02A_20 : 1;
    s8 pad_02A_3 : 5;
} GmMainWork;

typedef struct AutodemoFlagsAA7 {
    u8 pad_80 : 1;
    u8 pad_40 : 1;
    u8 pad_20 : 1;
    u8 pad_10 : 1;
    u8 flag_08 : 1;
    u8 pad_04 : 1;
    u8 pad_02 : 1;
    u8 pad_01 : 1;
} AutodemoFlagsAA7;

typedef struct AutodemoSaveFlags1 {
    u8 high : 4;
    u8 low : 4;
} AutodemoSaveFlags1;

typedef struct AutodemoD15Flags {
    u8 high : 2;
    u8 low : 6;
} AutodemoD15Flags;

typedef struct AutodemoInputEntry {
    u64 field_00;
    u64 pressed;
    u64 held;
    u64 field_18;
    u64 field_20;
    u32 field_28;
    u32 field_2C;
} AutodemoInputEntry;

typedef struct AutodemoInputTable {
    AutodemoInputEntry entries[21];
    void (*callback)(s32);
    u16 field_3F4;
    u8 field_3F6;
    u8 pad_3F7;
    u16 field_3F8;
    u8 field_3FA;
    u8 pad_3FB;
    u16 field_3FC;
    u8 field_3FE;
    u8 pad_3FF;
} AutodemoInputTable;

typedef struct GmAutodemoGObj {
    u8 pad_00[0x20];
    u32 field_20;
    u32 field_24;
} GmAutodemoGObj;

typedef struct AutodemoChoice {
    s32 index;
    s32 weight;
} AutodemoChoice;

typedef struct AutodemoPlayerResults {
    u8 pad_000[2];
    s8 state;
    u8 field_003;
    s32 field_004;
    u8 pad_008[0xC];
    f32 field_014;
    s8 field_018[5];
    s8 field_01D[5];
    s8 field_022[5];
    s8 field_027[5];
    u8 pad_02C[0xC];
    s32 field_038[5];
    s32 field_04C[5];
    f32 field_060[5];
    f32 field_074[5];
    s32 field_088[5];
    s32 field_09C[5];
    s32 field_0B0[5][3];
    s32 field_0EC[5][3];
    s8 field_128[5][3];
    u8 pad_137[0xC9];
    s8 field_200[5];
    u8 pad_205[3];
    s32 field_208[5];
    f32 field_21C[5];
} AutodemoPlayerResults;

typedef struct AutodemoCourseSlot {
    u8 state;
    u8 field_01;
    u8 field_02;
    u8 field_03;
    u8 field_04;
    u8 pad_05[0x2B];
} AutodemoCourseSlot;

typedef struct AutodemoClearData {
    s32 field_00;
    f32 field_04;
    f32 field_08;
} AutodemoClearData;

typedef struct AutodemoSceneConfig {
    s8 scene;
    s8 next_scene;
    s8 pixel_format;
    u8 pad_03;
    void (*callback_04)(void);
    void (*callback_08)(void);
    u8 field_0C[0x14];
    s32 kdcoll_mode;
} AutodemoSceneConfig;

typedef struct GmModeTransition {
    s8 scene;
    s8 next_scene;
    u8 arg;
    u8 pad_03;
    void (*callback_04)(void);
    void (*callback_08)(void);
} GmModeTransition;

typedef struct AutodemoCObjDesc {
    u32 flags;
    u32 projection_type;
    u32 viewport_width;
    u32 viewport_height;
    u32 scissor_width;
    u32 scissor_height;
    void* eye_position;
    void* interest;
    u32 pad_20;
    u32 pad_24;
    u32 pad_28;
    u32 fov;
    u32 pad_30;
    u32 near;
    u32 pad_38;
    u32 far;
} AutodemoCObjDesc;

typedef struct AutodemoFloatTable19 {
    u32 values[19];
} AutodemoFloatTable19;

typedef struct AutodemoFloatTable7 {
    u32 values[7];
} AutodemoFloatTable7;

typedef struct AutodemoU32Table8 {
    u32 values[8];
} AutodemoU32Table8;

typedef struct AutodemoFloatTable9 {
    u32 values[9];
} AutodemoFloatTable9;

extern char lbl_80495C00[];
extern char kar_src_gmautodemo_80495c14[];
extern AutodemoInputTable lbl_80495C28;
extern char kar_linkfile_gmdata_dat_80496028[];
extern char lbl_80496034[];

u8 lbl_80536EF0[0x110];
AutodemoInputTable lbl_80537000;
void* lbl_805DD570;
void* lbl_805DD574;

extern s32 lbl_805DD540[2];
extern void* lbl_805DD548;
extern GmAutodemoGObj* lbl_805DD54C;
extern GmAutodemoGObj* lbl_805DD550;
extern void* lbl_805DD560;
extern GmAutodemoGObj* lbl_805DD564;
extern GmAutodemoGObj* lbl_805DD568;
extern const f32 lbl_805DE764;
extern const f32 lbl_805DE768;
extern const f32 lbl_805DE76C;
extern const f32 lbl_805DE770;
extern const f32 lbl_805DE774;
extern const f32 lbl_805DE778;
const f32 lbl_805DE780 = 99.0f;
const f32 lbl_805DE784 = 59.0f;
const f64 lbl_805DE788 = 4503601774854144.0;
const f32 lbl_805DE790 = 60.0f;
const f32 lbl_805DE794 = 11.428572f;
const f32 lbl_805DE798 = 100000.0f;
const f32 lbl_805DE79C = 1.0f;
const f32 lbl_805DE7A0 = 0.3333f;
const f32 lbl_805DE7A4 = 0.6666f;
const f32 lbl_805DE7A8 = 0.0f;
const f32 lbl_805DE7AC = 0.304788f;
const f32 lbl_805DE7B0 = 100.0f;
const f32 lbl_805DE7B4 = 2.0f;
const f32 lbl_805DE7B8 = 1.8f;
const f32 lbl_805DE7BC = 3.0f;
const f32 lbl_805DE7C0 = 2.6f;
const f32 lbl_805DE7C4 = 4.0f;
const f32 lbl_805DE7C8 = 1.2f;
const f32 lbl_805DE7CC = -1851.5f;
const f32 lbl_805DE7D0 = -14.8f;
const f32 lbl_805DE7D4 = 50.0f;
const f32 lbl_805DE7D8 = 30.0f;
const f32 lbl_805DE7DC = 10.0f;
const f32 lbl_805DE7E0 = 70.0f;
const u32 lbl_805DE7E4 = 0;
const f64 lbl_805DE7E8 = 4503599627370496.0;

extern char kar_linkfile_mvopening_h4m_80495bf0[];
extern char lbl_80495038[];
extern char lbl_80495048[];
extern char lbl_80495740[];
extern char lbl_8049574C[];
extern char lbl_80495784[];
extern GmModeTransition lbl_80495058[];
extern AutodemoSceneConfig lbl_80495154[];
extern AutodemoCObjDesc lbl_80495B38;
extern u8 lbl_804957C8[];
extern u8 lbl_804957E0[];
extern u8 lbl_804957EC[];
extern u8 lbl_80495800[];
extern u8 lbl_80495814[];
extern u8 lbl_80495850[];
extern u8 lbl_80495864[];
extern u8 lbl_8049587C[];
extern u8 lbl_80495894[];
extern u8 lbl_804958AC[];
extern u8 lbl_804958C4[];
extern u8 lbl_804958D0[];
extern AutodemoCObjDesc lbl_80495BB0;
extern char kar_linkfile_mvopening_h4m_80495b78[];
extern char lbl_8049B1A8[];
extern char lbl_8049B1E0[];
extern void* kar_debug_menu_top_entries_8049f608[];
extern u8 HSD_PadCopyStatus[];
extern u8 HSD_PadMasterStatus[];
extern u8 CObjRenderMode[];
__declspec(section ".sdata") extern u8 kar_srcfile_gmlib_c_805d5118[];
__declspec(section ".sdata") extern u8 lbl_805D5120[];
__declspec(section ".sdata") extern u8 lbl_805D5124[];
__declspec(section ".sdata") extern u8 lbl_805D512C[];
__declspec(section ".sdata") extern char lbl_805D5138[];
__declspec(section ".sdata") char lbl_805D5140[] = "0";
extern const f32 lbl_805DE720;
extern const f32 lbl_805DE724;
extern const u32 lbl_805DE730;
extern const u32 lbl_805DE734;
extern const f32 lbl_805DE738;
extern const f32 lbl_805DE73C;
extern const f32 lbl_805DE740;
extern const f32 lbl_805DE750;
extern const f32 lbl_805DE758;
extern const f32 lbl_805DE75C;
extern const f32 lbl_805DE760;
extern s32 lbl_805DD554;
extern void* lbl_805DD558;
extern s32 lbl_805DD630;

int sprintf(char* str, const char* format, ...);
void* memset(void* dst, int val, unsigned long n);
void fn_80078604(void);
void fn_80078620(void);
void fn_800AD1A4(void* arg0);
void OSTicksToCalendarTime(s64 ticks, void* td);
s32 fn_80261ED4(void);
s32 fn_80261F58(void);
void fn_80286BE8(s32 arg0);
void fn_80286DF0(void);
void* fn_80286D58(void);
void fn_80286D7C(void);
void fn_80015DDC(void);
void fn_80015E10(void);
s8 fn_80015DB4(void);
void fn_8000B884(void);
u8 fn_8000AECC(void);
u32 fn_8000A474(void);
s32 fn_8000A4EC(s32 arg0);
void fn_8000B2DC(s32 arg0);
void fn_8000F5EC(s32 arg0);
void* fn_803DF618(void);
u32 kar_osthread__near_803d96b4(void);
void kar_osthread__near_803d9724(s32 arg0);
void* fn_8000B9DC();
void fn_8000B82C(void);
void kar_mpcoll_init_debug_volume_system(void);
void kar_lbkdcoll__near_80072514(void);
void kar_collision_object_system_init(void);
void kar_efargs__near_80241184(void);
void kar_pltrick__near_802337e4(void);
void kar_pltrick__near_80233878(void);
void kar_plclearcheckerlib__near_8022d2ac(void);
void kar_objalloc__800b00d8(void);
void kar_itdata_init_manager(void);
void kar_st_assets__asset_80261d68(void);
void fn_80261DA4(void);
void fn_80261DCC(s32 arg0);
void kar_clobject__near_8018dd14(void);
void fn_801C4EDC(void);
void kar_greventlighthouse_show_round_ui_and_shared_panels(void);
void kar_greventlighthouse_hide_round_ui_and_shared_panels(void);
void* kar_debugconsole_main__near_80440744(s32 arg0, s32 arg1, s32 arg2,
                                           s32 arg3);
void kar_pslist__near_804397b4(void* key);
void kar_dbcamera__near_800989cc(void);
void kar_dbcamera__near_800989fc(void);
s32 kar_shadow__near_8007b624(void);
void fn_8002DC74(void);
void fn_80009094(void);
s32 fn_8000AFB8(void);
void* kar_gmracenormal__800081fc(void);
void kar_gmracenormal__near_80015400(void);
void kar_gmracecommon__near_800132ec(void);
void kar_gmracecommon__near_80013314(void);
void kar_gmracecommon__near_800134d4(void);
void kar_mpcoll_destroy_all_volume_gobjs(void);
void fn_80261E9C(void);
void* fn_8003D594(void);
void fn_8003D5B8(s32 arg0);
void fn_8003D880(void);
void* fn_8003EA40(void);
void fn_8003EA64(s32 arg0);
void fn_8003EDC4(void);
void fn_8003F694(s32 arg0);
void fn_8003F988(void);
void kar_gmracenormal__80045a8c(void);
void fn_80040E7C(void);
void fn_80041E0C(s32 arg0, s32 arg1, s32* out);
void fn_800ACF40(void);
void fn_801385B0(void);
void* kar_gmglobal__near_80008874(void);
void fn_80113F10(s32 arg0, s32 arg1, void* arg2);
void fn_80113C38(s32 arg0);
void fn_80113C70(s32 arg0);
void fn_80113CA8(s32 arg0);
void fn_80113D00(s32 arg0);
void fn_80113D58(s32 arg0);
void fn_80113BE0(s32 arg0);
void fn_8011370C(s32 arg0);
void fn_801137F0(s32 arg0);
void fn_801142FC(s32 arg0);
void fn_8012A1C0(s32 arg0);
s32 fn_8019203C(void* arg0);
s32 fn_80191F68(void* arg0);
s32 fn_801C7CF4(void* arg0);
s32 fn_801C7D24(void* arg0);
void* fn_8003F670(void);
void* fn_800B8054(s32 arg0);
void* fn_800B8188(s32 arg0);
s32 fn_800B8708(s32 arg0);
u8 fn_8000916C(void);
s32 fn_80009A30(s32 arg0);
s32 fn_800099A0(s32 arg0);
s32 fn_800098C0(s32 arg0);
s32 fn_8000A0F8(void);
s32 fn_8000A1B0(void);
s8 fn_8000A97C(void);
s8 fn_8000AAC4(void);
s8 fn_8000AAF0(void);
s8 fn_8000AB1C(void);
f32 fn_8000AB48(s32 arg0, s32 arg1, s32 arg2);
s32 kar_lbvector__near_80065a80(s32 arg0);
void kar_lbvector__near_80065ae4(void* arg0);
void kar_lbvector__near_80065b40(void* arg0, void* arg1);
void kar_lbfade_set_draw_priority(void* arg0, s32 arg1);
void kar_lbfade_start_preset0_forward(void* arg0, s32 arg1);
void kar_lbfade_start_preset0_reverse(void* arg0, s32 arg1);
u8 kar_gmracenormal__8000af94(void);
s8 kar_gmracenormal__8000af5c(void);
u8 kar_gmracenormal__8000ae08(void);
u8 kar_gmracenormal__near_8000ae74(void);
s32 fn_8000AD48(void);
u8 fn_8000948C(s32 arg0);
s32 fn_8026288C(s32 arg0);
s32 fn_80261FDC(void);
s32 ClearChecker_CheckUnlocked(s32 arg0, s32 arg1);
s8 kar_gmglobal__near_80007e34(s32 arg0);
s8 kar_gmracenormal__8003d5f0(void);
s8 fn_8003EA9C(void);
s8 kar_gmracenormal__8003f6cc(void);
s32 GObj_GetFlagFromArray(void* gobj);
GmAutodemoGObj* HSD_GObjCreate(s32 classifier, s32 p_link, s32 priority);
void HSD_GObjDestroy(GmAutodemoGObj* gobj);
void HSD_GObjGXLink(GmAutodemoGObj* gobj, void (*callback)(void*, void*),
                    s32 priority, s32 flags);
void* HSD_CObjLoadDesc(void* desc);
void HSD_GObjObjectLink(GmAutodemoGObj* gobj, u8 kind, void* object);
void GObj_SetCamera(void* gobj, void* camera);
void GObj_SetupGXLinkMax(GmAutodemoGObj* gobj,
                         void (*callback)(void*, void*), s32 priority);
void kar_smsoundtest__near_800aebc0(void);
void kar_db_assets__asset_8007cf78(void);
void kar_si_assets__asset_800ad0c8(void);
void kar_textlib__near_800aca04(s32 arg0, void* entries, s32 arg2, s32 arg3);
void* kar_textlib__near_800aba6c(void);
void kar_textlib__near_800aba74(void* arg0, void* callback);
s32 kar_plclearcheckerlib__near_8022c858(s32 arg0);
void kar_plclearcheckerlib__near_8022ce94(s32 arg0, void* arg1);
void* kar_plclearcheckerlib__near_8022cedc(s32 arg0);
void kar_plclearcheckerlib__near_8022cf6c(s32 arg0, void* arg1);
s32 kar_plclearcheckerlib__near_8022c910(s32 arg0);
void kar_plclearcheckerlib__near_8022ca38(s32 arg0, f32 arg1);
void kar_plclearcheckerlib__near_8022cc10(s32 arg0, s32 arg1);
s32 kar_cmreplay__8022cc30(s32 arg0);
void kar_plclearcheckerlib__near_8022cc80(s32 arg0, u32 arg1);
s32 kar_plclearchecker_call_clobject_func_1926f4(s32 arg0);
void kar_plclearcheckerlib__near_8022d278(s32 arg0, s32 arg1);
s32 kar_plclearcheckerlib__near_8022d49c(s32 arg0);
s32 kar_plclearcheckerlib__near_8022d528(s32 arg0);
s32 kar_plclearcheckerlib__near_8022d684(s32 arg0);
s32 kar_plclearcheckerlib__8022f2a0(s32 arg0);
void kar_plclearcheckerlib__near_8022d850(s32 arg0);
void kar_plclearchecker_update_primary_flags(s32 arg0);
void kar_plclearcheckerlib__near_8022e88c(s32 arg0);
void kar_plclearcheckerlib__near_8022ea10(s32 arg0);
void kar_plclearchecker_get_template_vec_008(s32 arg0, Vec* out);
void kar_plclearchecker_end_object_action(s32 arg0, Vec* out);
void kar_lbaudio__near_8005fca0(s32 arg0, s32 arg1);
void kar_lbaudio__near_800617cc(s32 arg0);
void HSD_SisLib_803A6048(u32 size);
void HSD_SetPixelFormat(s32 pix_fmt, s32 z_fmt);
u64 fn_803AE0F0(f32 arg0);
f32 fn_803AE03C(u64 arg0);
void fn_80279D5C(s32 arg0, s32 arg1);
void fn_8027A168(s32 arg0, s32 arg1);
void kar_pltrick__near_80232b18(void);
void kar_pltrick__near_8023295c(void);
void kar_grlib2__near_800bbcec(void* arg0, s32 arg1, s32 arg2);
f32 kar_grlib2__near_800d51fc(void);
f32 kar_grlib2__near_800d52e4(Vec* vec);
void kar_grlib2__near_800d5370(Vec* vec);
s32 kar_grdata__near_800ceaf4(void);
void kar_greventlighthouse_hide_all_round_ui_components(void);
void kar_greventlighthouse_create_ifround_panel0_for_player_if_active(s32 arg0);
void fn_801138D4(s32 arg0);
void fn_801138F4(void);
void fn_80113B28(s32 arg0);
void fn_80114178(s32 arg0);
void fn_80114234(void);
void fn_80279F68(void);
void kar_gmracenormal__near_80015a00(void);
void kar_gmracenormal__near_8001530c(void);
void kar_gmracenormal__near_8001544c(void);
void kar_gmracenormal__near_800159ac(void);
void kar_cpcmdscript_init_current_replay_cpu_work_mode8(s32 arg0);
void kar_plclearcheckerlib__near_8022ce28(void);
s32 kar_plclearcheckerlib__near_8022d434(s32 arg0);
void kar_plclearcheckerlib__near_8022df1c(void);
void kar_pltrick__near_80232c14(void);
void fn_80131804(void);
void kar_lbaudio__near_80061acc(void);
void kar_lbaudio__near_80061bfc(void);
void kar_lbkdcoll__near_80071d7c(void);
void kar_gmclearchecker__near_8004e5b8(void);
void kar_gmclearchecker__near_8004e660(void);
void kar_gmclearchecker__near_8004e810(void);
void kar_gmclearchecker__near_8004f03c(void);
void kar_plclearchecker_update_secondary_flags(s32 arg0);
s32 kar_greventgenerator_get_active_event_kind(void);
s32 fn_8000AA08(void);
void kar_cpmapdata_request_map_audio_event(s32 arg0, s32 arg1);
void fn_80040B80(void);
void fn_800B989C(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 fn_80312680(s32 arg0);
s8 fn_8000C0E0(s32 arg0);
s8 fn_8000C364(s32 arg0, s32 arg1);
s8 fn_8000C488(s32 arg0);
s8 fn_8000C508(s32 arg0);
s8 fn_8000C584(s32 arg0);
s32 kar_gmautodemo__near_8000dfb4(void);
void fn_8000BDA8(s8 arg0, s32 arg1);
void fn_8000BE2C(s8 arg0, s8 arg1);
void fn_8000BE74(s8 arg0, s32 arg1);
void fn_8000BEBC(s8 arg0, s8 arg1);
void fn_8000BF04(s8 arg0, s32 arg1);
void fn_8000BF8C(s8 arg0, s32 arg1);
void kar_lbaudio__near_8005a7ac(void);
void fn_801384F4(void);
void fn_80138580(void);
void kar_plclearchecker_create_first_player_objects(void);
void kar_plclearchecker_set_template_vec_008(s32 arg0, Vec* value);
void kar_plclearchecker_set_template_vecs_014_020(s32 arg0, Vec* value0,
                                                  Vec* value1);
void kar_plclearchecker_set_slot_player_index(s32 arg0, s32 arg1);
void kar_gmracenormal__8022c86c(s32 arg0, s32 arg1);
void kar_plclearcheckerlib__near_8022c898(s32 arg0, s32 arg1);
void kar_plclearcheckerlib__near_8022c8c8(s32 arg0, s32 arg1);
void kar_plclearcheckerlib__near_8022c8f8(s32 arg0, s32 arg1);
void kar_plclearchecker_set_template_byte_08c(s32 arg0, s32 arg1);
void kar_plclearcheckerlib__near_8022c990(s32 arg0, s32 arg1);
void kar_plclearcheckerlib__near_8022c9c0(s32 arg0, s32 arg1);
void fn_80192BB8(s32 arg0, s32 arg1, s32 arg2);
void fn_801C8C6C(s32 arg0, s32 arg1);
s32 HSD_SisLib_803A611C(s32 font_idx, void* parent_gobj, s32 class_id,
                        s32 p_link, s32 priority, s32 cobj_class_id,
                        s32 cobj_p_link, s32 cobj_priority);
void* HSD_SisLib_803A6754(s32 font_idx, s32 context_id);
s32 HSD_SisLib_803A6B98(void* text, f32 x, f32 y, char* fmt, ...);
void HSD_SisLib_803A7548(void* text, s32 entry_idx, f32 scale_x,
                         f32 scale_y);
void HSD_SisLib_803A5CC4(void* text);
s32 kar_lbfade_is_finished(s32 arg0);
void kar_lbfade_start_preset1_forward(s32 arg0, s32 arg1);
void kar_lbaudio__near_80061658(void);
void kar_lbaudio__near_800616c8(void);
void kar_lbaudio__near_8005e5d0(void);
void kar_lbaudio__near_8005e788(void);
void kar_lbaudio__near_80062978(void);
void kar_gmglobal__near_80008898(void);
void kar_gmglobal__near_80008ad4(void);

#pragma dont_inline on
void* kar_gmracenormal__800081fc(void)
{
    return (u8*) kar_gmmain__near_80006c14() + 0x7D4;
}
#pragma dont_inline off

#pragma dont_inline on
void kar_gmlanmenu__80008220(void)
{
    volatile u8* work = kar_gmmain__near_80006c14();

    work[0x7D6] = 1;
}
#pragma dont_inline off

void kar_gmglobal__near_80008248(void)
{
    volatile u8* work = kar_gmmain__near_80006c14();

    work[0x7D6] = 0;
}

void kar_gmglobal__near_80008270(void)
{
    memset((u8*) kar_gmmain__near_80006c14() + 0x7D4, 0, 3);
}

#define FIND_MODE_TRANSITION(result, scene_id, found_label)                     \
    find_i = 0;                                                                 \
    (result) = lbl_80495058;                                                    \
    for (; find_i < 20; find_i++) {                                             \
        if ((s8) (result)->scene != (s8) (scene_id)) {                          \
            (result)++;                                                         \
        } else {                                                                \
            goto found_label;                                                   \
        }                                                                       \
    }                                                                           \
    OSReport(lbl_80495038);                                                     \
    (result) = NULL;                                                            \
found_label:

#pragma dont_inline on
void kar_gmlanmenu__800082a0(s32 arg0)
{
    volatile u8* work = kar_gmmain__near_80006c14();

    work[0x7D5] = arg0;
}
#pragma dont_inline off

void kar_gmglobal__near_800082d0(void)
{
    u8* work;
    u8* loop_work;
    GmModeTransition* transition;
    void (*callback)(void);
    void* vi_result;
    u32 pads;
    s32 scene;
    s32 find_i;

    work = kar_gmmain__near_80006c14();
    memset(work + 0x7D4, 0, 3);
    kar_gmglobal__near_80008898();
    vi_result = fn_803DF618();
    kar_lbaudio__near_80062978();
    pads = PAD_MASTER_INPUT(0);
    pads |= PAD_MASTER_INPUT(1);
    pads |= PAD_MASTER_INPUT(2);
    pads |= PAD_MASTER_INPUT(3);
    if (vi_result != NULL &&
        ((pads & 0x200) != 0 || kar_osthread__near_803d96b4() == 1)) {
        work = kar_gmmain__near_80006c14();
        work[0x7D5] = 0x0D;
    } else {
        kar_osthread__near_803d9724(0);
        work = kar_gmmain__near_80006c14();
        work[0x7D5] = 0x12;
    }

    for (;;) {
        work = kar_gmmain__near_80006c14();
        work[0x7D4] = work[0x7D5];
        scene = work[0x7D4];
        kar_gmmain__near_80006c14();
        FIND_MODE_TRANSITION(transition, scene, found_next_scene);
        work[0x7D5] = transition->next_scene;

        work = kar_gmmain__near_80006c14();
        work[0x7D6] = 0;
        loop_work = kar_gmmain__near_80006c14();

        work = kar_gmmain__near_80006c14();
        scene = work[0x7D4];
        kar_gmmain__near_80006c14();
        FIND_MODE_TRANSITION(transition, scene, found_pixel_format);
        kar_gmglobal__near_800088c8(transition != NULL ? transition->arg : -1);

        work = kar_gmmain__near_80006c14();
        scene = work[0x7D4];
        kar_gmmain__near_80006c14();
        FIND_MODE_TRANSITION(transition, scene, found_entry_callback);
        if (transition != NULL) {
            callback = transition->callback_04;
            if (callback != NULL) {
                callback();
            }
        }

        while ((s8) loop_work[0x7D6] == 0) {
            kar_gmglobal__near_80008ad4();
            work = kar_gmmain__near_80006c14();
            if ((s8) kar_gmracenormal__8000aea8() == 0x12 ||
                (s8) fn_8000AECC() != 0x26) {
                if (lbl_805DD540[1] == 0) {
                    scene = work[0x7D4];
                    kar_gmmain__near_80006c14();
                    FIND_MODE_TRANSITION(transition, scene,
                                         found_update_callback);
                    if (transition != NULL) {
                        callback = transition->callback_08;
                        if (callback != NULL) {
                            callback();
                        }
                    }
                }
            }
        }

        if (lbl_805DD540[1] != 0) {
            lbl_805DD540[1] = 0;
        }
    }
}

#undef FIND_MODE_TRANSITION

#pragma dont_inline on
void* kar_gmglobal__near_80008874(void)
{
    return (u8*) kar_gmmain__near_80006c14() + 0x7D7;
}
#pragma dont_inline off

void kar_gmglobal__near_80008898(void)
{
    memset((u8*) kar_gmmain__near_80006c14() + 0x7D7, 0, 2);
}

#pragma dont_inline on
void kar_gmglobal__near_800088c8(s8 value)
{
    volatile u8* work = kar_gmmain__near_80006c14();

    work[0x7D8] = value;
}
#pragma dont_inline off

u8 kar_gmglobal__near_800088f8(void)
{
    return *((u8*) kar_gmmain__near_80006c14() + 0x7D8);
}

void kar_gmglobal__near_8000891c(void)
{
    u8* work;
    s32 scene;
    s32 selected_scene;
    s32 scene_id;
    AutodemoSceneConfig* config;
    s32 i;
    s32* load_config;

    work = kar_gmmain__near_80006c14();
    scene = work[0x7D7];
    if ((s32) scene == 0x26) {
        selected_scene = work[0x7D8];
    } else {
        selected_scene = scene;
    }

    if (kar_gmglobal__near_8000818c() != 0) {
        kar_lbkdcoll__near_80075434(0);
        HSD_SisLib_803A6048(0x4800);
        return;
    }

    kar_gmmain__near_80006c14();
    config = lbl_80495154;
    scene_id = (s8) selected_scene;
    for (i = 0x29; i != 0; i--) {
        if ((s8) config->scene == scene_id) {
            goto found;
        }
        config++;
    }
    OSReport(lbl_80495048);
    config = NULL;

found:
    if (config == NULL) {
        return;
    }

    if (kar_lbkdcoll__near_800726e0() == 5 && config->kdcoll_mode == 4) {
        kar_lbkdcoll__near_80075434(5);
    } else if (fn_8000AFB8() != 0) {
        kar_lbkdcoll__near_80075434(2);
    } else {
        kar_lbkdcoll__near_80075434(config->kdcoll_mode);
    }

    HSD_SisLib_803A6048(0x4800);
    if (kar_gmracenormal__8000af5c() != 0 &&
        (s8) kar_gmracenormal__8000af94() == 3) {
        fn_8002DC74();
    }

    load_config = kar_lbfile_get_resource_load_config();
    if (kar_lbmemory__near_80058834(2) == 0) {
        load_config[0] = 1;
    }
    kar_lbfile_queue_startup_resource_loads();
    kar_lbkdcoll__near_80075360(0x80);

    if ((s8) kar_gmracenormal__8000aea8() != 3) {
        if (kar_lbmemory__near_80058834(6) == 0) {
            load_config[3] = 1;
        }
        kar_lbfile_queue_startup_resource_loads();
        if (kar_lbmemory__near_80058834(3) == 0) {
            load_config[1] = 1;
        }
        if (kar_lbmemory__near_80058834(7) == 0) {
            load_config[2] = 1;
        }
        kar_lbfile_queue_startup_resource_loads();
    }

    kar_st_assets__asset_80261d68();
    kar_gm_assets__asset_8000fc70();
}

void kar_gmglobal__near_80008ad4(void)
{
    u8* work;
    s32 scene;
    s32 scene_id;
    AutodemoSceneConfig* config;
    s32 i;
    void (*callback)(void);

    kar_dbcamera__near_800989cc();
    work = kar_gmmain__near_80006c14();
    if ((s8) work[0x7D8] == 0x1F) {
        work = kar_gmmain__near_80006c14();
        work[0x7D7] = work[0x7D8];
        scene = work[0x7D7];
        kar_gmmain__near_80006c14();
        config = lbl_80495154;
        scene_id = (s8) scene;
        for (i = 0x29; i != 0; i--) {
            if ((s8) config->scene == scene_id) {
                goto found_next_0;
            }
            config++;
        }
        OSReport(lbl_80495048);
        config = NULL;

    found_next_0:
        work[0x7D8] = config->next_scene;
    } else if (kar_shadow__near_8007b624() != 0) {
        work = kar_gmmain__near_80006c14();
        work[0x7D7] = work[0x7D8];
        scene = work[0x7D7];
        kar_gmmain__near_80006c14();
        config = lbl_80495154;
        scene_id = (s8) scene;
        for (i = 0x29; i != 0; i--) {
            if ((s8) config->scene == scene_id) {
                goto found_next_1;
            }
            config++;
        }
        OSReport(lbl_80495048);
        config = NULL;

    found_next_1:
        work[0x7D8] = config->next_scene;
    } else if (kar_lbhvqm__near_8007865c() == 0) {
        work = kar_gmmain__near_80006c14();
        work[0x7D7] = work[0x7D8];
        scene = work[0x7D7];
        kar_gmmain__near_80006c14();
        config = lbl_80495154;
        scene_id = (s8) scene;
        for (i = 0x29; i != 0; i--) {
            if ((s8) config->scene == scene_id) {
                goto found_next_2;
            }
            config++;
        }
        OSReport(lbl_80495048);
        config = NULL;

    found_next_2:
        work[0x7D8] = config->next_scene;
    } else {
        work = kar_gmmain__near_80006c14();
        work[0x7D7] = 0x26;
    }

    kar_gmglobal__near_8000891c();

    work = kar_gmmain__near_80006c14();
    scene = work[0x7D7];
    kar_gmmain__near_80006c14();
    config = lbl_80495154;
    scene_id = (s8) scene;
    for (i = 0x29; i != 0; i--) {
        if ((s8) config->scene == scene_id) {
            goto found_callbacks;
        }
        config++;
    }
    OSReport(lbl_80495048);
    config = NULL;

found_callbacks:
    kar_gmmain__near_80006540(config->field_0C);

    work = kar_gmmain__near_80006c14();
    scene = work[0x7D7];
    kar_gmmain__near_80006c14();
    config = lbl_80495154;
    scene_id = (s8) scene;
    for (i = 0x29; i != 0; i--) {
        if ((s8) config->scene == scene_id) {
            goto found_start;
        }
        config++;
    }
    OSReport(lbl_80495048);
    config = NULL;

found_start:
    if (config != NULL) {
        HSD_SetPixelFormat(config->pixel_format, 0);
        callback = config->callback_04;
        if (callback != NULL) {
            callback();
        }
    }

    kar_gmmain__near_80006b58();
    work = kar_gmmain__near_80006c14();
    if (lbl_805DD540[1] != 0) {
        scene = (s8) work[0x7D7];
        if (scene == 0x13 || scene == 0x14) {
            fn_80286DF0();
        }
    } else {
        scene = work[0x7D7];
        kar_gmmain__near_80006c14();
        config = lbl_80495154;
        scene_id = (s8) scene;
        for (i = 0x29; i != 0; i--) {
            if ((s8) config->scene == scene_id) {
                goto found_end;
            }
            config++;
        }
        OSReport(lbl_80495048);
        config = NULL;

    found_end:
        if (config != NULL) {
            callback = config->callback_08;
            if (callback != NULL) {
                callback();
            }
        }
    }

    if (lbl_805DD540[1] != 0) {
        kar_gmmain__near_800063a8();
    }
}

void kar_gmglobal__near_80008df8(void)
{
    u8* work;
    s32 values[4];
    s32 mode;
    u64 ticks;
    f32 base;
    s32 i;

    work = kar_gmmain__near_80006c38();
    values[1] = 0;

    switch ((s8) work[0x38]) {
    case 1:
        fn_80041E0C(4, (s8) work[0x3B], values);
        break;
    case 2:
        fn_80041E0C(3, (s8) work[0x3B], values);
        break;
    }

    *(s32*) (work + 0x20) = values[1];
    *(s32*) (work + 0x28) = 0x7FFFFFFF;
    *(s32*) (work + 0x2C) = values[1];

    mode = (work[0x4D] >> 6) & 3;
    switch (mode) {
    case 0:
        base = (f32) (*(u32*) 0x800000F8 >> 2) * LOAD_F32(lbl_805DE720);
        ticks = (u64) base;
        base = (f32) (s64) ticks;
        ticks = (u64) base;
        kar_lbaudio__near_80062874(ticks);
        break;
    case 2:
        base = (f32) (*(u32*) 0x800000F8 >> 2) * LOAD_F32(lbl_805DE720);
        ticks = (u64) base;
        base = (f32) (s64) ticks;
        ticks = (u64) (LOAD_F32(lbl_805DE724) * base);
        kar_lbaudio__near_80062874(ticks);
        break;
    default:
        base = (f32) (*(u32*) 0x800000F8 >> 2) * LOAD_F32(lbl_805DE720);
        ticks = (u64) base;
        kar_lbaudio__near_80062874(ticks);
        break;
    }

    if ((s32) work[0x38] == 2) {
        for (i = 0; i < 4; i++) {
            if ((s8) work[i * 9 + 0x58] == 0) {
                work[0x54] = i;
                break;
            }
        }
    }

    work[0x30] = 0;
    fn_80286BE8((s32) work);
}

void fn_80008FC0(void)
{
    fn_80286BE8(0);
}

void fn_80008FE4(void)
{
    fn_80286DF0();
}

void fn_80009004(void) {}

void fn_80009008(void)
{
    void* obj = fn_80286D58();

    if (obj != NULL) {
        u8* global;

        kar_gmmain__near_80006c38();
        global = kar_gmglobal__near_80008874();
        kar_movie_assets__8000a498((s32) obj);
        kar_gmmain__near_800064f0();
        if ((s32) *global == 0x14) {
            kar_gmlanmenu__800082a0(0x10);
            kar_gmlanmenu__80008220();
        }
    }
}

void fn_80009070(void) {}

void fn_80009074(void)
{
    fn_80286D7C();
}

void fn_80009094(void)
{
    u8* buf = lbl_80536EF0;
    u32* head = (u32*) buf;
    u8* render_mode = CObjRenderMode;

    *(u32*) (buf + 4) = 0;
    sprintf((char*) (buf + 8), lbl_80495740,
            *(u32*) (render_mode + 0x1F0));
    *head = (u32) (lbl_80536EF0 + 0x88);
    *head = 0;
}

void* fn_80009100(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    void* result =
        kar_debugconsole_main__near_80440744(arg0, arg1, arg2, arg3);

    if (result != NULL) {
        kar_pslist__near_804397b4(fn_80009094);
        kar_pslist__near_804397b4(kar_dbcamera__near_800989fc);
    }
    return result;
}

void fn_8000914C(GmAutodemoGObj* gobj)
{
    HSD_GObjDestroy(gobj);
}

#pragma dont_inline on
u8 fn_8000916C(void)
{
    return *(u8*) ((u8*) kar_gmmain__near_80006c14() + 0xA94);
}
#pragma dont_inline off

u8 fn_80009190(void)
{
    return *(u8*) ((u8*) kar_gmmain__near_80006c14() + 0xA9A);
}

void fn_800091B4(s32 arg0)
{
    volatile u8* work = kar_gmmain__near_80006c14();

    work[0xA9A] = arg0;
}

s16 fn_800091E4(void)
{
    return *(s16*) ((u8*) kar_gmmain__near_80006c14() + 0xA9C);
}

u8 fn_80009208(void)
{
    return *(u8*) ((u8*) kar_gmmain__near_80006c14() + 0xA95);
}

void fn_8000922C(s32 arg0)
{
    volatile u8* work = kar_gmmain__near_80006c14();

    work[0xA95] = arg0;
}

s8 fn_8000925C(void)
{
    u8* work = (u8*) kar_gmmain__near_80006c14() + 0xAC8;
    s8 count = 0;
    s8 i;

    for (i = 0; i < 5; i++) {
        if (*(s8*) work == 0) {
            count++;
        }
        work += 0x30;
    }
    return count;
}

u8 fn_800092B4(void)
{
    return *(u8*) ((u8*) kar_gmmain__near_80006c14() + 0xA96);
}

u8 fn_800092D8(void)
{
    return *(u8*) ((u8*) kar_gmmain__near_80006c14() + 0xA97);
}

s32 kar_gmracenormal__800092fc(void)
{
    u8* work = kar_gmmain__near_80006c14();

    if ((s8) kar_gmracenormal__8000aea8() == 4) {
        if ((s8) kar_gmracenormal__8003d5f0() == 0) {
            return (s8) work[0xA97];
        }
        if ((s8) kar_gmracenormal__8003d5f0() == 1) {
            return (s8) (work[0xA97] - 0x22);
        }
        if ((s8) kar_gmracenormal__8003d5f0() == 2) {
            return (s8) (work[0xA97] - 0x2B);
        }
    }
    return work[0xA97];
}

void fn_80009394(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    if ((s8) kar_gmracenormal__8000aea8() == 4) {
        if ((s8) kar_gmracenormal__8003d5f0() == 0) {
            work[0xA97] = arg0;
            return;
        }
        if ((s8) kar_gmracenormal__8003d5f0() == 1) {
            work[0xA97] = arg0 + 0x22;
            return;
        }
        if ((s8) kar_gmracenormal__8003d5f0() == 2) {
            work[0xA97] = arg0 + 0x2B;
        }
    } else {
        work[0xA97] = arg0;
    }
}

void fn_8000942C(s32 arg0)
{
    volatile u8* work = kar_gmmain__near_80006c14();

    work[0xA98] = arg0;
}

void fn_8000945C(s32 arg0)
{
    volatile u8* work = kar_gmmain__near_80006c14();

    work[0xA99] = arg0;
}

u8 fn_8000948C(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += arg0 * 0x30;
    return work[0xAC8];
}

u8 fn_800094C4(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += arg0 * 0x30;
    return work[0xAC9];
}

u32 fn_800094FC(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += arg0 * 4;
    return *(u32*) (work + 0x87C);
}

u8 fn_80009534(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += arg0;
    return work[0x848];
}

f32 fn_80009568(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += arg0 * 4;
    return *(f32*) (work + 0xA4C);
}

void fn_800095A0(void)
{
    kar_gmracenormal__near_80015400();
}

u8 fn_800095C0(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += arg0 * 0x30;
    return work[0xACC];
}

u8 fn_800095F8(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += arg0 * 0x30;
    return work[0xAD0];
}

u8 fn_80009630(s32 arg0)
{
    u32 table[2];
    u8* ptr;

    table[0] = lbl_805DE730;
    ptr = (u8*) table;
    table[1] = lbl_805DE734;
    return ptr[(s8) arg0];
}

void fn_80009658(s32 arg0, u32* out)
{
    u32 table[8] = {
        0xFFAABD00, 0xFFE85200, 0x5AC9FF00, 0xA8FA8200,
        0xFFFFFF00, 0xE260FF00, 0x5E3D2500, 0xFF293600,
    };

    *out = table[arg0];
}

const AutodemoFloatTable19 lbl_804894A0 = {{
    0x3FEF5C29, 0x3FEF5C29, 0x3FEF5C29, 0x3FEF5C29, 0x40666666,
    0x40933333, 0x400CCCCD, 0x4019999A, 0x40C00000, 0x41066666,
    0x3FEF5C29, 0x40400000, 0x3FEF5C29, 0x403A5E35, 0x3FEF5C29,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
}};

const AutodemoFloatTable7 lbl_804894EC = {{
    0x00000000, 0x00000000, 0x40E66666, 0x41499999,
    0x40A66666, 0x00000000, 0x00000000,
}};

const u32 lbl_80489508[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000,
};

f32 fn_800096B8(s32 arg0, s32 arg1)
{
    AutodemoFloatTable19 table1;
    AutodemoFloatTable7 table2;
    f32 value;

    table1 = lbl_804894A0;
    table2 = lbl_804894EC;

    if (arg0 == 0) {
        value = ((f32*) table1.values)[arg1];
    } else {
        value = ((f32*) table2.values)[arg1];
    }
    return value * LOAD_F32(lbl_805DE738);
}

f32 fn_80009764(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += arg0 * 4;
    return *(f32*) (work + 0x890);
}

u8 fn_8000979C(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += arg0;
    return work[0x852];
}

s32 fn_800097D0(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 value;

    work += arg0 * 4;
    value = *(s32*) (work + 0x8B8);
    if (value >= 0x57E40) {
        value = 0x57E3F;
    }
    return value;
}

u8 fn_8000981C(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += arg0;
    return work[0x857];
}

f32 fn_80009850(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += arg0 * 4;
    return *(f32*) (work + 0x8A4);
}

u8 fn_80009888(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += arg0 * 3;
    return work[0xBB9];
}

#pragma dont_inline on
s32 fn_800098C0(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += arg0 * 3;
    return (s8) work[0xBB9] == 1;
}
#pragma dont_inline off

u8 fn_80009908(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += arg0 * 3;
    return work[0xBBA];
}

s32 fn_80009940(s32 arg0)
{
    s8* base = (s8*) kar_gmmain__near_80006c14() + 0xBB8;
    u8* work = kar_gmmain__near_80006c14();
    s32 offset = arg0 * 3;

    work += offset;
    if ((s32) work[0xBB9] == 1) {
        return base[offset];
    }
    return -1;
}

#pragma dont_inline on
s32 fn_800099A0(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    if (arg0 == (s8) work[0xBB8]) {
        return 0;
    }
    if (arg0 == (s8) work[0xBBB]) {
        return 1;
    }
    if (arg0 == (s8) work[0xBBE]) {
        return 2;
    }
    if (arg0 == (s8) work[0xBC1]) {
        goto found3;
    }
    goto fail;

found3:
    return 3;

fail:
    return -1;
}
#pragma dont_inline off

#pragma dont_inline on
s32 fn_80009A30(s32 arg0)
{
    s32 value = fn_800B8708(arg0);

    if (value == -1) {
        return value;
    }
    if (fn_8000AAC4() != 0 || kar_gmracenormal__8000af5c() != 0 ||
        fn_8000A97C() != 0) {
        return -1;
    }
    return value;
}
#pragma dont_inline off

void fn_80009A98(s32* out_minutes, s32* out_seconds, s32* out_centiseconds)
{
    u8* work = kar_gmmain__near_80006c14();
    u32 seconds = *(u32*) (work + 0x834);
    u32 frame = work[0x833];

    if (frame + seconds * 60 >= 0x57E40U) {
        *out_minutes = 99;
        *out_seconds = 59;
        *out_centiseconds = 99;
    } else {
        s32 frame_remainder;

        *out_minutes = seconds / 60;
        *out_seconds = *(u32*) (work + 0x834) % 60;
        frame_remainder = work[0x833] % 60;
        *out_centiseconds =
            (s32) (LOAD_F32(lbl_805DE73C) * (f32) frame_remainder /
                   LOAD_F32(lbl_805DE740));
    }
}

void fn_80009B9C(s32* out_minutes, s32* out_seconds, s32* out_centiseconds)
{
    kar_gmautodemo__near_8000fcb8(out_minutes, out_seconds, out_centiseconds);
}

s32 fn_80009BBC(void)
{
    u8* work = kar_gmmain__near_80006c14();

    return work[0x833] + *(s32*) (work + 0x834) * 60;
}

void fn_80009BEC(void)
{
    u8* work = kar_gmmain__near_80006c14();

    *(s32*) (work + 0x834) = 0;
    work[0x833] = 0;
}

void fn_80009C18(s32 arg0, s32 arg1, s32* out_value, s32* out_minutes,
                 s32* out_seconds, s32* out_centiseconds, s32* out_flag)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 player_offset = arg0 * 0xC;
    u8* base = work;
    s32 slot_offset = arg1 * 4;
    u8* player_base;
    u8* slot_base;
    s32 frames;
    s32 frame_remainder;

    base += 0x830;
    player_base = base + player_offset;
    slot_base = player_base;
    slot_base += slot_offset;
    frames = *(s32*) (slot_base + 0xB0);

    if (frames >= 0x57E40) {
        frames = 0x57E3F;
    }

    slot_base = player_base;
    slot_base += slot_offset;
    *out_value = *(s32*) (slot_base + 0xEC);
    *out_minutes = frames / 3600;
    *out_seconds = (frames / 60) % 60;
    frame_remainder = frames % 60;
    *out_centiseconds =
        (s32) (LOAD_F32(lbl_805DE73C) * (f32) frame_remainder /
               LOAD_F32(lbl_805DE740));
    base += arg0 * 3;
    *out_flag = (s8) base[arg1 + 0x128];
}

void fn_80009D64(s32 arg0, s32 arg1, s32 arg2)
{
    u8* work = kar_gmmain__near_80006c14();

    work += arg0 * 3;
    work[arg1 + 0x958] = arg2;
}

void fn_80009DB8(s32 arg0, s32* out_minutes, s32* out_seconds,
                 s32* out_centiseconds)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 frames;

    work += arg0 * 4;
    frames = *(s32*) (work + 0x8CC);
    if (frames >= 0x57E40) {
        *out_minutes = 99;
        *out_seconds = 59;
        *out_centiseconds = 99;
    } else {
        s32 frame_remainder;

        *out_minutes = frames / 3600;
        *out_seconds = (*(s32*) (work + 0x8CC) / 60) % 60;
        frame_remainder = *(s32*) (work + 0x8CC) % 60;
        *out_centiseconds =
            (s32) (LOAD_F32(lbl_805DE73C) * (f32) frame_remainder /
                   LOAD_F32(lbl_805DE740));
    }
}

s32 fn_80009EF8(s32 arg0, s32 arg1)
{
    u8* work = kar_gmmain__near_80006c14();

    work += arg0 * 0xC;
    work += arg1 * 4;
    return *(s32*) (work + 0x8E0);
}

s32 fn_80009F44(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 offset = arg0 * 0xC;
    s32 index = 0;

    work += offset;
    if (*(s32*) (work + 0x8E4) != 0) {
        index = 1;
        if (*(s32*) (work + 0x8E8) != 0) {
            index = 2;
        }
    }

    work = kar_gmmain__near_80006c14();
    work += offset;
    work += index * 4;
    return *(s32*) (work + 0x8E0);
}

s32 fn_80009FB8(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += arg0 * 4;
    return *(s32*) (work + 0x8CC);
}

void kar_grboxgenerator__80009ff0(s32* out_minutes, s32* out_seconds,
                                  s32* out_centiseconds)
{
    u8* work = kar_gmmain__near_80006c14();
    u32 frame = work[0x833];
    s32 seconds = *(s32*) (work + 0x834);
    s32 remaining;
    s32 centisecond_frame;

    if (frame != 0) {
        seconds++;
    }

    remaining = *(s16*) (work + 0xA9C) - seconds;
    *out_minutes = remaining / 60;
    remaining = *(s16*) (work + 0xA9C) - seconds;
    *out_seconds = remaining % 60;
    centisecond_frame = (60 - work[0x833]) % 60;
    *out_centiseconds =
        (s32) (LOAD_F32(lbl_805DE73C) * (f32) centisecond_frame /
               LOAD_F32(lbl_805DE740));
}

#pragma dont_inline on
s32 fn_8000A0F8(void)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 minutes = *(s32*) (work + 0x834) + 1;
    s32 limit = *(s16*) (work + 0xA9C);
    s32 frame = work[0x833];

    return (limit - minutes) * 60 + (60 - frame);
}
#pragma dont_inline off

u8 fn_8000A138(void)
{
    return (*((u8*) kar_gmmain__near_80006c14() + 0xAA5) >> 7) & 1;
}

u8 fn_8000A160(void)
{
    return (*((u8*) kar_gmmain__near_80006c14() + 0xAA5) >> 6) & 1;
}

u8 fn_8000A188(void)
{
    return (*((u8*) kar_gmmain__near_80006c14() + 0xAA5) >> 4) & 1;
}

#pragma dont_inline on
s32 fn_8000A1B0(void)
{
    return (*((u8*) kar_gmmain__near_80006c14() + 0xAA5) >> 3) & 1;
}
#pragma dont_inline off

u8 fn_8000A1D8(void)
{
    return (*((u8*) kar_gmmain__near_80006c14() + 0xAA5) >> 1) & 3;
}

u8 fn_8000A200(void)
{
    return *((u8*) kar_gmmain__near_80006c14() + 0xAA5) & 1;
}

u8 fn_8000A228(void)
{
    return (*((u8*) kar_gmmain__near_80006c14() + 0xAA6) >> 6) & 1;
}

u8 fn_8000A250(void)
{
    return (*((u8*) kar_gmmain__near_80006c14() + 0xAA6) >> 5) & 1;
}

u8 fn_8000A278(void)
{
    return (*((u8*) kar_gmmain__near_80006c14() + 0xAA6) >> 4) & 1;
}

u8 kar_diag__8000a2a0(void)
{
    u8* work = kar_gmmain__near_80006c14();

    if ((work[0xAA5] >> 5) & 1) {
        OSReport(lbl_8049574C);
        __assert((char*) kar_srcfile_gmlib_c_805d5118, 0x421,
                 (char*) lbl_805D5120);
    }
    return (work[0xAA5] >> 5) & 1;
}

u8 fn_8000A300(void)
{
    return (*((u8*) kar_gmmain__near_80006c14() + 0xAA6) >> 1) & 3;
}

void fn_8000A328(void)
{
    kar_gmracecommon__near_800134d4();
}

u8 fn_8000A348(void)
{
    return (*((u8*) kar_gmmain__near_80006c14() + 0xAA7) >> 4) & 1;
}

f32 kar_gmracenormal__8000a370(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();
    u8* slots = work + 0xAC8;
    s32 count = 0;
    s32 index;

    for (index = 0; index < 4; index++) {
        if (index == arg0) {
            break;
        }
        if ((s32) slots[index * 0x30] != 4) {
            count++;
        }
    }

    return LOAD_F32(lbl_805DE750) * (f32) (((s8) work[0xA95] - 1) - count);
}

void fn_8000A444(s32 arg0)
{
    *(s32*) ((u8*) kar_gmmain__near_80005cbc() + 0x38) = arg0;
}

#pragma dont_inline on
u32 fn_8000A474(void)
{
    return *(u32*) ((u8*) kar_gmmain__near_80005cbc() + 0x3C);
}
#pragma dont_inline off

#pragma dont_inline on
void kar_movie_assets__8000a498(s32 arg0)
{
    *(s32*) ((u8*) kar_gmmain__near_80005cbc() + 0x3C) = arg0;
}
#pragma dont_inline off

u32 fn_8000A4C8(void)
{
    return *(u32*) ((u8*) kar_gmmain__near_80005cbc() + 0x40);
}

#pragma dont_inline on
s32 fn_8000A4EC(s32 arg0)
{
    s32 ret = *(s32*) ((u8*) kar_gmmain__near_80005cbc() + 0x40) < arg0;

    return ret;
}
#pragma dont_inline off

void fn_8000A530(void)
{
    u8* work = kar_gmmain__near_80005cbc();
    s32 value = *(s32*) (work + 0x40);

    if (value < 0) {
        *(s32*) (work + 0x40) = 0;
    } else {
        *(s32*) (work + 0x40) = value + 1;
    }
}

u32 fn_8000A570(void)
{
    return *(u32*) ((u8*) kar_gmmain__near_80005cbc() + 0x44);
}

void fn_8000A594(s32 arg0)
{
    *(s32*) ((u8*) kar_gmmain__near_80005cbc() + 0x44) = arg0;
}

s32 fn_8000A5C4(void)
{
    u8* work = kar_gmmain__near_80005cbc();
    s32 value = *(s32*) (work + 0x44);

    if (value <= 0) {
        return 1;
    }
    *(s32*) (work + 0x44) = value - 1;
    return 0;
}

s32 fn_8000A604(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    if ((s32) work[0xAC8] != 4 && (s8) work[0x848] == arg0) {
        return 0;
    }
    if ((s32) work[0xAF8] != 4 && (s8) work[0x849] == arg0) {
        return 1;
    }
    if ((s32) work[0xB28] != 4 && (s8) work[0x84A] == arg0) {
        return 2;
    }
    if ((s32) work[0xB58] != 4 && (s8) work[0x84B] == arg0) {
        return 3;
    }
    return 5;
}

s32 fn_8000A6C4(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();
    u8* slots = work + 0xAC8;
    s32 ids[4];
    s32* id_base;
    s32 i;
    s32 j;

    if ((s8) fn_8000AD48() == 1) {
        s8 mode = kar_gmracenormal__near_8000ae74();

        if (mode == 6) {
            goto normal;
        }
        if (mode >= 6) {
            goto check_high_mode;
        }
        if (mode >= 4) {
            goto special_mode;
        }
        goto normal;

    check_high_mode:
        if (mode >= 8) {
            goto normal;
        }

    special_mode:
        {
            s32 result = 5;

            if ((s8) slots[arg0 * 0x30] != 4) {
                result = arg0;
            }
            return result;
        }
    }

normal:
    ids[0] = (s8) work[0x848];
    ids[1] = (s8) work[0x849];
    ids[2] = (s8) work[0x84A];
    ids[3] = (s8) work[0x84B];
    id_base = ids;

    for (i = 0; i < 4; i++) {
        if ((s8) slots[i * 0x30] != 4) {
            for (j = i + 1; j < 4; j++) {
                if ((s8) slots[j * 0x30] != 4 &&
                    id_base[i] == id_base[j]) {
                    id_base[j]++;
                }
            }
            for (j = i + 1; j < 4; j++) {
                if ((s8) slots[j * 0x30] != 4 &&
                    id_base[i] == id_base[j]) {
                    id_base[j]++;
                }
            }
            for (j = i + 1; j < 4; j++) {
                if ((s8) slots[j * 0x30] != 4 &&
                    id_base[i] == id_base[j]) {
                    id_base[j]++;
                }
            }
        }
    }

    if ((s8) slots[0] != 4 && arg0 == id_base[0]) {
        return 0;
    }
    if ((s8) slots[0x30] != 4 && arg0 == id_base[1]) {
        return 1;
    }
    if ((s8) slots[0x60] != 4 && arg0 == id_base[2]) {
        return 2;
    }
    if ((s8) slots[0x90] != 4 && arg0 == id_base[3]) {
        return 3;
    }
    return 5;
}

u8 fn_8000A958(void)
{
    return *((u8*) kar_gmmain__near_80006c14() + 0x832);
}

#pragma dont_inline on
s8 fn_8000A97C(void)
{
    u8* work;

    if ((s8) kar_gmracenormal__8000aea8() != 4) {
        return 0;
    }
    if ((s8) kar_gmracenormal__8003d5f0() != 1) {
        return 0;
    }

    work = kar_gmmain__near_80006c14();
    return (s8) ((s8) work[0x832] == 5);
}
#pragma dont_inline off

u8 fn_8000A9E4(void)
{
    return *((u8*) kar_gmmain__near_80006c14() + 0x831);
}

#pragma dont_inline on
s32 fn_8000AA08(void)
{
    return kar_gmmain__near_80005d04(4);
}
#pragma dont_inline off

void fn_8000AA2C(s32 arg0)
{
    switch (arg0) {
    case 0:
        kar_gmmain__near_80005d78(4);
        break;
    case 1:
        kar_greventlighthouse_show_round_ui_and_shared_panels();
        break;
    case 2:
        kar_gmmain__near_80005dcc(4);
        kar_greventlighthouse_hide_round_ui_and_shared_panels();
        break;
    }
}

void fn_8000AA8C(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    ((AutodemoFlagsAA7*) (work + 0xAA7))->flag_08 = arg0;
}

#pragma dont_inline on
s8 fn_8000AAC4(void)
{
    return (*((u8*) kar_gmmain__near_80006c14() + 0xAA7) >> 3) & 1;
}
#pragma dont_inline off

s8 fn_8000AAF0(void)
{
    return *(s32*) (*(u8**) kar_gmautodemo__near_8000fcb0() + 0x18);
}

s8 fn_8000AB1C(void)
{
    return *(s32*) (*(u8**) kar_gmautodemo__near_8000fcb0() + 0x1C);
}

char lbl_80495740[] = "\\cffff00%2d";
char lbl_8049574C[] = "mapdebug error. ";

f32 fn_8000AB48(s32 arg0, s32 arg1, s32 arg2)
{
    AutodemoFloatTable9 table;
    s32 index;

    if (arg2 == 0) {
        kar_plclearcheckerlib__near_8022cf6c(arg0, &table);
    } else {
        u8* base;

        kar_gmmain__near_80006c14();
        base = fn_8003F670();
        base += arg0 * 0x24;
        table = *(AutodemoFloatTable9*) (base + 0xC);
    }

    switch (arg1) {
    case 0:
        index = 1;
        break;
    case 1:
        index = 2;
        break;
    case 2:
        index = 3;
        break;
    case 3:
        index = 4;
        break;
    case 4:
        index = 5;
        break;
    case 5:
        index = 0;
        break;
    case 6:
        index = 6;
        break;
    case 7:
        index = 7;
        break;
    case 8:
        index = 8;
        break;
    }

    return ((f32*) table.values)[index];
}

s32 fn_8000AC60(void)
{
    return *(s32*) (*(u8**) kar_gmautodemo__near_8000fcb0() + 0x10);
}

s32 fn_8000AC88(void)
{
    return *(s32*) (*(u8**) kar_gmautodemo__near_8000fcb0() + 0x14);
}

u8 kar_diag__8000acb0(void)
{
    u8* work = kar_gmmain__near_80006c14();

    if ((s32) *(u8*) ((u8*) kar_gmmain__near_80006c14() + 0xA97) == 9 ||
        (s32) *(u8*) ((u8*) kar_gmmain__near_80006c14() + 0xA97) ==
            0x34) {
        return 1;
    }

    if ((work[0xAA6] >> 3) & 1) {
        OSReport(lbl_80495784);
        __assert((char*) kar_srcfile_gmlib_c_805d5118, 0x708,
                 (char*) lbl_805D5120);
    }

    if ((work[0xAA6] >> 3) & 1) {
        return 1;
    }
    return 0;
}

char lbl_80495784[] = "trialflag error.";

#pragma dont_inline on
s32 fn_8000AD48(void)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 value = (s8) work[0xA94] - 7;

    switch (value) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 6:
    case 7:
    case 8:
    case 9:
    case 11:
        return 1;
    }
    return 0;
}
#pragma dont_inline off

u8 lbl_804957C8[] = {
    0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04,
    0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x06, 0x06,
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x07,
};
u8 lbl_804957E0[] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05,
    0x06, 0x07, 0x08, 0xFF, 0x00, 0x00,
};
u8 lbl_804957EC[] = {
    0x12, 0x0F, 0x0A, 0x0B, 0x02, 0x07, 0x03, 0x09, 0x01, 0x00,
    0x11, 0x08, 0x06, 0x05, 0x04, 0x0D, 0x0C, 0x0E, 0x10, 0x13,
};
u8 lbl_80495800[] = {
    0x0F, 0x03, 0x09, 0x01, 0x00, 0x11, 0x08, 0x06, 0x05, 0x10,
    0x12, 0x0A, 0x0B, 0x02, 0x07, 0x04, 0x0D, 0x0C, 0x0E, 0x13,
};
u8 lbl_80495814[] = {
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0C, 0x00, 0x00, 0x07, 0x00, 0x00, 0x06, 0x00,
    0x00, 0x0B, 0x00, 0x00, 0x09, 0x00, 0x00, 0x05,
    0x00, 0x00, 0x03, 0x00, 0x00, 0x02, 0x00, 0x00,
    0x0D, 0x00, 0x00, 0x0A, 0x00, 0x01, 0x04, 0x00,
    0x01, 0x02, 0x00, 0x01, 0x03, 0x00, 0x00, 0x08,
    0x00, 0x00, 0x04, 0x00, 0x00, 0x0E, 0x01, 0x01,
    0x05, 0x02, 0x00, 0x12,
};
u8 lbl_80495850[] = {
    0x01, 0x00, 0x09, 0x08, 0x10, 0x07, 0x04, 0x03, 0x0F, 0x06,
    0x0B, 0x05, 0x02, 0x0A, 0x11, 0x01, 0x01, 0x01, 0x01, 0x00,
};
u8 lbl_80495864[] = {
    0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04,
    0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x06, 0x06,
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x07,
};
u8 lbl_8049587C[] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
    0x01, 0x02, 0x05, 0x03, 0x07, 0x05, 0x06, 0x07,
    0x07, 0x07, 0x09, 0x09, 0x07, 0x07, 0x00, 0x00,
};
u8 lbl_80495894[] = {
    0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x05,
    0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x09,
};
u8 lbl_804958AC[] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05,
    0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B,
    0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11,
    0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
};
u8 lbl_804958C4[] = {
    0x00, 0x02, 0x04, 0x03, 0xFF, 0x06,
    0x05, 0x00, 0x04, 0x00, 0xFF, 0xFF,
};
u8 lbl_804958D0[] = {
    0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x03, 0x06,
    0x06, 0x05, 0x05, 0x05, 0x05, 0x05, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

s32 fn_8000ADA0(void)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 value = (s8) work[0xA97];

    if (value != 0x21) {
        if (value < 0x21) {
            if (value < 9) {
                if (value >= 0) {
                    goto success;
                }
            } else if (value >= 0x18) {
                goto success;
            }
        } else {
            if (value >= 0x34) {
                goto fail;
            }
            goto success;
        }
    }
    goto fail;

success:
    return 1;

fail:
    return 0;
}

#pragma dont_inline on
u8 kar_gmracenormal__8000ae08(void)
{
    return *((u8*) kar_gmmain__near_80006c14() + 0x5AF);
}
#pragma dont_inline off

u8 kar_gmracenormal__near_8000ae2c(void)
{
    return *((u8*) fn_8003F670() + 5);
}

s32 kar_gmracenormal__8000ae50(void)
{
    return *((u8*) kar_gmmain__near_80006c14() + 0x5AD);
}

u8 kar_gmracenormal__near_8000ae74(void)
{
    u8* work = kar_gmmain__near_80006c14();

    return lbl_804957C8[(s8) work[0x5AD]];
}

#pragma dont_inline on
s8 kar_gmracenormal__8000aea8(void)
{
    return *(u8*) kar_gmracenormal__800081fc();
}
#pragma dont_inline off

#pragma dont_inline on
u8 fn_8000AECC(void)
{
    return *(u8*) kar_gmglobal__near_80008874();
}
#pragma dont_inline off

u8 fn_8000AEF0(void)
{
    return *((u8*) fn_8003D594() + 9);
}

u8 fn_8000AF14(void)
{
    return *((u8*) fn_8003EA40() + 0xD);
}

u8 kar_vcgenerator__8000af38(void)
{
    return *((u8*) fn_8003F670() + 5);
}

#pragma dont_inline on
s8 kar_gmracenormal__8000af5c(void)
{
    return (s8) (*(s8*) kar_gmracenormal__800081fc() == 2);
}
#pragma dont_inline off

#pragma dont_inline on
u8 kar_gmracenormal__8000af94(void)
{
    return *((u8*) kar_gmmain__near_80006c14() + 0x17);
}
#pragma dont_inline off

s32 fn_8000AFB8(void)
{
    u8* work = kar_gmmain__near_80006c14();
    u8 value = work[0x15];

    if (*(s8*) kar_gmracenormal__800081fc() == 2) {
        if ((s8) value == 0 || (s8) (u8) value == 1) {
            work = kar_gmmain__near_80006c14();
            if ((s8) work[0x17] != 3) {
                return 1;
            }
        }
    }
    return 0;
}

s32 fn_8000B024(u16* arg0, u16* arg1)
{
    s32 value;
    s32 other;

    if (arg0 == NULL) {
        goto fail;
    }
    if (arg1 == NULL) {
        goto fail;
    }
    if (arg0 == arg1) {
        return 1;
    }

    switch (arg0[0]) {
    case 0x11:
        value = fn_8019203C(arg0);
        break;
    case 0x10:
        value = fn_801C7CF4(arg0);
        break;
    default:
        return 0;
    }

    if (value == 5) {
        goto fail;
    }

    switch (arg1[0]) {
    case 0x11:
        other = fn_8019203C(arg1);
        break;
    case 0x10:
        other = fn_801C7CF4(arg1);
        break;
    default:
        return 0;
    }

    if (value == other) {
        return 1;
    }

fail:
    return 0;
}

s32 fn_8000B108(u16* arg0, u16* arg1)
{
    s32 value;
    s32 other;

    if (arg0 == NULL) {
        goto fail;
    }
    if (arg1 == NULL) {
        goto fail;
    }
    if (arg0 == arg1) {
        return 1;
    }

    switch (arg0[0]) {
    case 0x11:
        value = fn_80191F68(arg0);
        break;
    case 0x10:
        value = fn_801C7D24(arg0);
        break;
    default:
        return 0;
    }

    if (value == 0xFF) {
        goto fail;
    }

    switch (arg1[0]) {
    case 0x11:
        other = fn_80191F68(arg1);
        break;
    case 0x10:
        other = fn_801C7D24(arg1);
        break;
    default:
        return 0;
    }

    if (value == other) {
        return 1;
    }

fail:
    return 0;
}

s32 fn_8000B1EC(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += arg0 * 4;
    return *(s32*) (work + 0x868);
}

u8 fn_8000B224(void)
{
    return *((u8*) kar_gmmain__near_80006c14() + 0x354);
}

s16 fn_8000B248(void)
{
    return *(s16*) ((u8*) kar_gmmain__near_80006c14() + 0x356);
}

s16 fn_8000B26C(void)
{
    return *(s16*) ((u8*) kar_gmmain__near_80006c14() + 0x358);
}

u8 fn_8000B290(void)
{
    return (*((u8*) kar_gmmain__near_80006c14() + 0x35A) >> 5) & 1;
}

u8 fn_8000B2B8(void)
{
    return *((u8*) kar_gmmain__near_80006c14() + 0x374);
}

#pragma dont_inline on
void fn_8000B2DC(s32 arg0)
{
    volatile u8* work = kar_gmmain__near_80006c14();

    work[0x374] = arg0;
}
#pragma dont_inline off

u8 fn_8000B30C(void)
{
    return *((u8*) kar_gmmain__near_80006c14() + 0x375);
}

void fn_8000B330(s32 arg0)
{
    volatile u8* work = kar_gmmain__near_80006c14();

    work[0x375] = arg0;
}

u8 fn_8000B360(void)
{
    return *((u8*) kar_gmmain__near_80006c14() + 0x376);
}

void fn_8000B384(s32 arg0)
{
    volatile u8* work = kar_gmmain__near_80006c14();

    work[0x376] = arg0;
}

u8 fn_8000B3B4(void)
{
    return *((u8*) kar_gmmain__near_80006c14() + 0x377);
}

void fn_8000B3D8(s32 arg0)
{
    volatile u8* work = kar_gmmain__near_80006c14();

    work[0x377] = arg0;
}

u8 fn_8000B408(void)
{
    return *((u8*) kar_gmmain__near_80006c14() + 0x378);
}

void fn_8000B42C(s32 arg0)
{
    volatile u8* work = kar_gmmain__near_80006c14();

    work[0x378] = arg0;
}

u8 fn_8000B45C(void)
{
    return *((u8*) kar_gmmain__near_80006c14() + 0x379);
}

void fn_8000B480(s32 arg0)
{
    volatile u8* work = kar_gmmain__near_80006c14();

    work[0x379] = arg0;
}

u8 fn_8000B4B0(void)
{
    return *((u8*) kar_gmmain__near_80006c14() + 0x37A);
}

void fn_8000B4D4(s32 arg0)
{
    volatile u8* work = kar_gmmain__near_80006c14();

    work[0x37A] = arg0;
}

u8 fn_8000B504(void)
{
    return *((u8*) kar_gmmain__near_80006c14() + 0x37B);
}

void fn_8000B528(s32 arg0)
{
    volatile u8* work = kar_gmmain__near_80006c14();

    work[0x37B] = arg0;
}

u8 fn_8000B558(void)
{
    return *((u8*) kar_gmmain__near_80006c14() + 0x37C);
}

void fn_8000B57C(s32 arg0)
{
    volatile u8* work = kar_gmmain__near_80006c14();

    work[0x37C] = arg0;
}

void fn_8000B5AC(s32 arg0)
{
    volatile u8* work = kar_gmmain__near_80006c14();

    work[0x37D] = arg0;
}

void fn_8000B5DC(s32 arg0, s32 arg1, s32 arg2)
{
    u8* work = kar_gmmain__near_80006c14();

    work[0x37E] = arg0;
    work[0x37F] = arg1;
    work[0x380] = arg2;
}

s16 fn_8000B62C(void)
{
    return *(s16*) ((u8*) kar_gmmain__near_80006c14() + 0x394);
}

u8 fn_8000B650(void)
{
    return *((u8*) kar_gmmain__near_80006c14() + 0x396);
}

u8 fn_8000B674(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += (s8) arg0;
    return work[0xBC8];
}

u32 fn_8000B6AC(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += (s8) arg0 * 4;
    return *(u32*) (work + 0xBD0);
}

u32 fn_8000B6E8(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += (s8) arg0 * 4;
    return *(u32*) (work + 0xBF0);
}

u8 fn_8000B724(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += (s8) arg0;
    return work[0xC00];
}

u32 fn_8000B75C(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += (s8) arg0 * 4;
    return *(u32*) (work + 0xC04);
}

f32 fn_8000B798(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += (s8) arg0 * 4;
    return *(f32*) (work + 0xC14);
}

void fn_8000B7D4(void)
{
    kar_gm_assets__asset_8000fc70();
    kar_mpcoll_init_debug_volume_system();
    kar_lbkdcoll__near_80072514();
    kar_collision_object_system_init();
    kar_efargs__near_80241184();
    kar_pltrick__near_802337e4();
    kar_plclearcheckerlib__near_8022d2ac();
    kar_objalloc__800b00d8();
    kar_itdata_init_manager();
    kar_st_assets__asset_80261d68();
    fn_80261DA4();
    fn_80261DCC(0x35);
    kar_clobject__near_8018dd14();
    fn_801C4EDC();
}

#pragma dont_inline on
void fn_8000B82C(void)
{
    kar_gm_assets__asset_8000fc70();
    kar_mpcoll_init_debug_volume_system();
    kar_lbkdcoll__near_80072514();
    kar_collision_object_system_init();
    kar_efargs__near_80241184();
    kar_pltrick__near_80233878();
    kar_plclearcheckerlib__near_8022d2ac();
    kar_objalloc__800b00d8();
    kar_itdata_init_manager();
    kar_st_assets__asset_80261d68();
    fn_80261DA4();
    fn_80261DCC(0x35);
    kar_clobject__near_8018dd14();
    fn_801C4EDC();
}
#pragma dont_inline off

#pragma dont_inline on
void fn_8000B884(void)
{
    kar_mpcoll_destroy_all_volume_gobjs();
    fn_80261E9C();
}
#pragma dont_inline off

u8 fn_8000B8A8(s32 arg0)
{
    return lbl_804957E0[(s8) arg0];
}

#pragma peephole off
s32 fn_8000B8BC(s32 arg0)
{
    s32 value = (s8) arg0;
    u8* table = lbl_804957E0;

    if (value == (s8) table[0]) {
        return 0;
    }
    if (value == (s8) table[1]) {
        return 1;
    }
    if (value == (s8) table[2]) {
        return 2;
    }
    if (value == (s8) table[3]) {
        return 3;
    }
    if (value == (s8) table[4]) {
        return 4;
    }
    if (value == (s8) table[5]) {
        return 5;
    }
    if (value == (s8) table[6]) {
        return 6;
    }
    if (value == (s8) table[7]) {
        return 7;
    }
    if (value == (s8) table[8]) {
        return 8;
    }
    return 0;
}
#pragma peephole reset

u8 fn_8000B9A8(s32 arg0)
{
    return lbl_804957EC[(s8) arg0];
}

u8 fn_8000B9BC(s32 arg0, s32 arg1)
{
    s32 row = (s8) arg0 * 10;
    s32 col = (s8) arg1;
    u8* ptr = lbl_80495800 + row;

    return ptr[col];
}

#pragma dont_inline on
void* fn_8000B9DC(arg0)
s32 arg0;
{
    return &lbl_80495814[(s8) arg0 * 3];
}
#pragma dont_inline off

u8 fn_8000B9F4(s32 arg0, s32 arg1)
{
    if ((s8) arg0 == 0) {
        return lbl_80495850[(s8) arg1];
    }
    return lbl_805D5124[(s8) arg1];
}

u8 fn_8000BA20(s32 arg0)
{
    return lbl_80495864[(s8) arg0];
}

u8 fn_8000BA34(s32 arg0)
{
    return lbl_8049587C[(s8) arg0];
}

u8 fn_8000BA48(s32 arg0)
{
    return lbl_80495894[(s8) arg0];
}

u8 fn_8000BA5C(s32 arg0)
{
    return lbl_804958AC[(s8) arg0];
}

s8 fn_8000BA70(s32 arg0)
{
    u8* table = lbl_804958AC;
    s32 value = (s8) arg0;
    s32 i;

    for (i = 0; i < 24; table++, i++) {
        if (value == (s8) *table) {
            return i;
        }
    }
    return -1;
}

u8 fn_8000BB78(s32 arg0)
{
    return lbl_804958C4[(s8) arg0];
}

u8 fn_8000BB8C(s32 arg0)
{
    return lbl_804958D0[(s8) arg0];
}

void kar_gmlanmenu__8000bba0(void)
{
    if ((s8) fn_80015DB4() == -1 || kar_shadow__near_8007b650() != 0) {
        kar_lbaudio__near_8005e1a8(0x3C);
    } else {
        kar_lbaudio__near_8005e1a8((s8) fn_80015DB4());
    }
}

void fn_8000BBF0(void)
{
    fn_80015DDC();
}

void fn_8000BC10(void)
{
    fn_80015E10();
}

void fn_8000BC30(s32 arg0)
{
    u8* src = kar_gmmain__near_80006c14();
    u8* dst = kar_gmmain__near_80006c14();

    dst[0xD00] = arg0;
    dst[0xD03] = src[0x374];
    if ((s8) dst[0xD00] == 0) {
        u8 value = src[0x375];

        if ((s8) value <= 0) {
            dst[0xD05] = fn_80312680(((s8*) dst)[0xD03]);
        } else {
            dst[0xD05] = value;
        }
        dst[0xD08] = src[0x376];
        dst[0xD0D] = src[0x379];
        dst[0xD09] = src[0x377];
        dst[0xD0A] = src[0x378];
        dst[0xD0E] = src[0x37A];
        dst[0xD0F] = src[0x37B];
        ((AutodemoD15Flags*) (dst + 0xD15))->high = src[0x37C];
        dst[0xD12] = src[0x37E];
        dst[0xD13] = src[0x37F];
        dst[0xD14] = src[0x380];
    } else {
        s32 one = 1;

        dst[0xD05] = 5;
        dst[0xD08] = 0;
        dst[0xD0D] = one;
        dst[0xD09] = 0;
        dst[0xD0A] = one;
        dst[0xD0E] = 0;
        dst[0xD0F] = 0;
        ((AutodemoD15Flags*) (dst + 0xD15))->high = one;
        dst[0xD12] = src[0x37E];
        dst[0xD13] = src[0x37F];
        dst[0xD14] = src[0x380];
    }
    *(s32*) (dst + 0xD18) = 0x3C0;
    dst[0xD11] = src[0x37D];
}

u8 fn_8000BD6C(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 offset = 0xD20;

    offset += (s8) arg0 * 9;
    return work[offset];
}

#pragma dont_inline on
void fn_8000BDA8(s8 arg0, s32 arg1)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 offset = 0xD20;

    offset += (s8) arg0 * 9;
    work[offset] = arg1;
}
#pragma dont_inline off

u8 fn_8000BDF0(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 offset = 0xD21;

    offset += (s8) arg0 * 9;
    return work[offset];
}

#pragma dont_inline on
void fn_8000BE2C(s8 arg0, s8 arg1)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 offset = 0xD21;

    offset += (s8) arg0 * 9;
    work[offset] = arg1;
}
#pragma dont_inline off

#pragma dont_inline on
void fn_8000BE74(s8 arg0, s32 arg1)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 offset = 0xD22;

    offset += (s8) arg0 * 9;
    work[offset] = arg1;
}
#pragma dont_inline off

#pragma dont_inline on
void fn_8000BEBC(s8 arg0, s8 arg1)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 offset = 0xD26;

    offset += (s8) arg0 * 9;
    work[offset] = arg1;
}
#pragma dont_inline off

#pragma dont_inline on
void fn_8000BF04(s8 arg0, s32 arg1)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 offset = 0xD23;

    offset += (s8) arg0 * 9;
    work[offset] = arg1;
}
#pragma dont_inline off

s8 fn_8000BF4C(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 offset = 0xD28;

    offset += (s8) arg0 * 9;
    return work[offset];
}

#pragma dont_inline on
void fn_8000BF8C(s8 arg0, s32 arg1)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 offset = 0xD28;

    offset += (s8) arg0 * 9;
    work[offset] = arg1;
}
#pragma dont_inline off

void fn_8000BFD4(s32 arg0, s32 arg1)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 offset = 0xD25;

    offset += (s8) arg0 * 9;
    work[offset] = arg1;
}

u8 fn_8000C01C(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += (s8) arg0;
    return work[0xCC8];
}

u32 fn_8000C054(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    work += (s8) arg0 * 4;
    return *(u32*) (work + 0xCD0);
}

u32 fn_8000C090(void)
{
    return *(u32*) ((u8*) kar_gmmain__near_80006c14() + 0xCE8);
}

u64 fn_8000C0B4(void)
{
    return *(u64*) ((u8*) kar_gmmain__near_80006c14() + 0xCE0);
}

#pragma dont_inline on
s8 fn_8000C0E0(s32 arg0)
{
    kar_gmmain__near_80006c14();

    if ((s8) arg0 != 8) {
        return 0;
    }
    if (kar_shadow__near_8007b650() != 0) {
        return kar_gmglobal__near_80007e34(0x22);
    }
    return ClearChecker_CheckUnlocked(0, 0x22);
}
#pragma dont_inline off

s32 fn_8000C148(s32 arg0)
{
    switch ((s8) arg0) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 23:
        return 1;
    }
    return 0;
}

s8 fn_8000C17C(s32 arg0)
{
    s32 clearchecker_id;

    switch ((s8) arg0) {
    case 3:
        clearchecker_id = 0x25;
        break;
    case 8:
        clearchecker_id = 0x26;
        break;
    case 11:
        clearchecker_id = 0x27;
        break;
    case 12:
        clearchecker_id = 0x28;
        break;
    case 13:
        clearchecker_id = 0x29;
        break;
    case 22:
        clearchecker_id = 0x2A;
        break;
    default:
        return 0;
    }

    if (kar_shadow__near_8007b650() != 0) {
        return kar_gmglobal__near_80007e8c((s8) clearchecker_id);
    }
    return ClearChecker_CheckUnlocked(2, (u8) clearchecker_id);
}

s8 fn_8000C228(s32 arg0)
{
    s32 index = (s8) arg0;
    s32 unlocked;
    s32 clearchecker_id;

    switch (index) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 23:
        unlocked = 1;
        break;
    default:
        unlocked = 0;
        break;
    }

    if ((s8) unlocked != 0) {
        switch (index) {
        case 0:
        case 1:
        case 2:
        case 4:
        case 5:
        case 6:
        case 7:
        case 9:
        case 10:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 23:
            unlocked = 1;
            break;
        default:
            unlocked = 0;
            break;
        }

        if ((s8) unlocked != 0) {
            if ((s8) kar_gmglobal__near_80007ee4(arg0) != 0) {
                unlocked = 1;
            } else {
                unlocked = 0;
            }
        } else {
            unlocked = 0;
        }
        return unlocked;
    }

    switch (index) {
    case 3:
        clearchecker_id = 0x25;
        break;
    case 8:
        clearchecker_id = 0x26;
        break;
    case 11:
        clearchecker_id = 0x27;
        break;
    case 12:
        clearchecker_id = 0x28;
        break;
    case 13:
        clearchecker_id = 0x29;
        break;
    case 22:
        clearchecker_id = 0x2A;
        break;
    default:
        return 0;
    }

    if (kar_shadow__near_8007b650() != 0) {
        return kar_gmglobal__near_80007e8c((s8) clearchecker_id);
    }
    return ClearChecker_CheckUnlocked(2, (u8) clearchecker_id);
}

s8 fn_8000C364(s32 arg0, s32 arg1)
{
    s32 clearchecker_id;

    if ((s8) arg0 == 0) {
        switch ((s8) arg1) {
        case 2:
            clearchecker_id = 0x13;
            break;
        case 3:
            clearchecker_id = 0x1A;
            break;
        case 5:
            clearchecker_id = 0x16;
            break;
        case 6:
            clearchecker_id = 0x18;
            break;
        case 7:
            clearchecker_id = 0x19;
            break;
        case 9:
            clearchecker_id = 0x14;
            break;
        case 10:
            clearchecker_id = 0x1C;
            break;
        case 11:
            clearchecker_id = 0x15;
            break;
        case 12:
            clearchecker_id = 0x1D;
            break;
        case 13:
            clearchecker_id = 0x1E;
            break;
        default:
            return 0;
        }
    } else if ((s8) arg0 == 1) {
        switch ((s8) arg1) {
        case 2:
            clearchecker_id = 0x17;
            break;
        case 4:
            clearchecker_id = 0x1B;
            break;
        case 3:
            clearchecker_id = 0x1F;
            break;
        default:
            return 0;
        }
    }

    if (kar_shadow__near_8007b650() != 0) {
        return kar_gmglobal__near_80007e34((s8) clearchecker_id);
    }
    return ClearChecker_CheckUnlocked(0, (u8) clearchecker_id);
}

#pragma dont_inline on
s8 fn_8000C488(s32 arg0)
{
    s32 clearchecker_id;

    switch ((s8) arg0) {
    case 1:
        clearchecker_id = 0x20;
        break;
    case 2:
        clearchecker_id = 0x21;
        break;
    default:
        return 0;
    }

    if (kar_shadow__near_8007b650() != 0) {
        return kar_gmglobal__near_80007e34((s8) clearchecker_id);
    }
    return ClearChecker_CheckUnlocked(0, (u8) clearchecker_id);
}
#pragma dont_inline off

#pragma dont_inline on
s8 fn_8000C508(s32 arg0)
{
    s32 clearchecker_id;

    switch (arg0) {
    case 4:
        clearchecker_id = 0x22;
        break;
    case 8:
        clearchecker_id = 0x1E;
        break;
    default:
        return 0;
    }

    if (kar_shadow__near_8007b650() != 0) {
        return kar_gmglobal__near_80007e8c((s8) clearchecker_id);
    }
    return ClearChecker_CheckUnlocked(2, (u8) clearchecker_id);
}
#pragma dont_inline off

#pragma dont_inline on
s8 fn_8000C584(s32 arg0)
{
    s32 clearchecker_id;

    switch ((s8) arg0) {
    case 1:
        clearchecker_id = 0x23;
        break;
    case 2:
        clearchecker_id = 0x24;
        break;
    default:
        return 0;
    }

    if (kar_shadow__near_8007b650() != 0) {
        return kar_gmglobal__near_80007e34((s8) clearchecker_id);
    }
    return ClearChecker_CheckUnlocked(0, (u8) clearchecker_id);
}
#pragma dont_inline off

void fn_8000C604(void)
{
    u8* global0;
    u8* global1;
    u8* global2;
    u8* ptr0;
    u8* ptr1;
    u8* ptr2;
    s32 i;

    kar_gmmain__near_80006c20();
    global0 = (u8*) kar_gmglobal__near_8000771c();
    global1 = (u8*) kar_gmglobal__near_8000772c();
    global2 = (u8*) kar_gmglobal__near_8000774c();

    i = 0;
    if (i < 120) {
        for (; i < 120; i += 8) {
            ptr0 = global0 + i + 0x7C;
            ptr1 = global1 + i + 0x7C;
            ptr2 = global2 + i + 0x7C;

            ptr0[0] = 4;
            ptr1[0] = 4;
            ptr2[0] = 4;
            ptr0[1] = 4;
            ptr1[1] = 4;
            ptr2[1] = 4;
            ptr0[2] = 4;
            ptr1[2] = 4;
            ptr2[2] = 4;
            ptr0[3] = 4;
            ptr1[3] = 4;
            ptr2[3] = 4;
            ptr0[4] = 4;
            ptr1[4] = 4;
            ptr2[4] = 4;
            ptr0[5] = 4;
            ptr1[5] = 4;
            ptr2[5] = 4;
            ptr0[6] = 4;
            ptr1[6] = 4;
            ptr2[6] = 4;
            ptr0[7] = 4;
            ptr1[7] = 4;
            ptr2[7] = 4;
        }
    }

    global0[0] = 1;
    global1[0] = 1;
    global2[0] = 1;
}

s32 fn_8000C6F0(s32 arg0)
{
    AutodemoSaveFlags1* flags =
        (AutodemoSaveFlags1*) ((u8*) kar_gmglobal__800076a0(arg0) + 1);

    if (flags->low != 0) {
        return 0;
    }
    return flags->high != 0;
}

void fn_8000C734(s32 arg0)
{
    AutodemoSaveFlags1* flags =
        (AutodemoSaveFlags1*) ((u8*) kar_gmglobal__800076a0(arg0) + 1);

    flags->low |= 1;
}

s8 fn_8000C768(void)
{
    if (kar_shadow__near_8007b650() != 0) {
        return kar_gmglobal__near_80007e8c(0x2B);
    }
    return ClearChecker_CheckUnlocked(2, 0x2B);
}

s32 fn_8000C7AC(void)
{
    u32 flags = *(u32*) ((u8*) kar_gmmain__near_80005cbc() + 0x3C);
    s32 mode = *(s8*) kar_gmracenormal__800081fc();

    switch (mode) {
    case 4: {
        s8 flag =
            (u8) ((((u8*) kar_gmmain__near_80006c14())[0xAA7] >> 3) & 1);

        if (flag != 0) {
            return 1;
        }
        if ((flags & 0x10) != 0) {
            OSReport((char*) lbl_805D512C);
            return 0;
        }
        if (*(s8*) ((u8*) fn_8003D594() + 9) != 0) {
            break;
        }
        if ((flags & 0x100) != 0) {
            return 0;
        }
        break;
    }
    case 6: {
        s32 value;
        s32 allowed;
        u8* work;

        if (*(s8*) ((u8*) fn_8003F670() + 5) != 0 &&
            (flags & 0x10) != 0) {
            return 0;
        }

        work = kar_gmmain__near_80006c14();
        value = (s8) work[0xA94] - 7;
        switch (value) {
        case 0:
        case 1:
        case 2:
        case 4:
        case 6:
        case 7:
        case 8:
        case 9:
        case 11:
            allowed = 1;
            break;
        default:
            allowed = 0;
            break;
        }

        if ((s8) allowed != 0) {
            fn_8003F670();
            work = kar_gmmain__near_80006c14();
            mode = (s8) ((u8*) kar_gmmain__near_80006c14())[0xA94];

            switch (mode) {
            case 9:
                return (s8) work[0x5AF] == 1;
            case 11:
                return (s8) work[0x5AF] == 1;
            }
        }
        break;
    }
    }

    return 1;
}

u32 lbl_80495B10[] = { 0, 0, 0, 0x3F800000, 0 };
u32 lbl_80495B24[] = { 0, 0, 0, 0, 0 };
AutodemoCObjDesc lbl_80495B38 = {
    0, 3, 0x280, 0x1E0, 0x280, 0x1E0, lbl_80495B10, lbl_80495B24,
    0, 0, 0, 0x47000000, 0, 0x43F00000, 0, 0x44200000,
};
char kar_linkfile_mvopening_h4m_80495b78[] = "MvOpening.h4m";
u32 lbl_80495B88[] = { 0, 0, 0, 0x3F800000, 0 };
u32 lbl_80495B9C[] = { 0, 0, 0, 0, 0 };
AutodemoCObjDesc lbl_80495BB0 = {
    0, 3, 0x280, 0x1E0, 0x280, 0x1E0, lbl_80495B88, lbl_80495B9C,
    0, 0, 0, 0x47000000, 0, 0x43F00000, 0, 0x44200000,
};
char kar_linkfile_mvopening_h4m_80495bf0[] = "MvOpening.h4m";

char lbl_80495C00[] = "autodemo kind none.";
char kar_src_gmautodemo_80495c14[] = "gmautodemo.c";
AutodemoInputTable lbl_80495C28 = {
    { { 0 } }, NULL, 0x27, 7, 0, 0x4F, 3, 0, 0x77, 1, 0
};
char kar_linkfile_gmdata_dat_80496028[] = "GmData.dat";
char lbl_80496034[] = "gmDataAll";

s32 fn_8000C934(void)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 value = *(s32*) (work + 0xA8C);

    return value != 0;
}

void fn_8000C964(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    *(s32*) (work + 0xA8C) = arg0;
}

s32 fn_8000C994(void)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 value = *(s32*) (work + 0xA90);

    return value != 0;
}

void fn_8000C9C4(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();

    *(s32*) (work + 0xA90) = arg0;
}
u32 kar_gmautodemo__near_8000c9f4(void)
{
    return *(u32*) ((u8*) kar_gmmain__near_80006c14() + 0xA90);
}

f32 kar_gmautodemo__near_8000ca18(void)
{
    return *(f32*) ((u8*) kar_gmmain__near_80006c14() + 0x60C);
}

s32 kar_gmautodemo__near_8000ca3c(void)
{
    GmMainWork* work = kar_gmmain__near_80006c14();
    u8* global = kar_gmglobal__near_800077e0();

    if (kar_shadow__near_8007b650() != 0) {
        return 0;
    }
    if (kar_gmracenormal__8003d5f0() != 0) {
        return 0;
    }
    if (work->flag_02A_80 != 0) {
        return 0;
    }
    return (s8) global[8] < 5;
}

void kar_gmautodemo__near_8000cadc(void)
{
    GmMainWork* work = kar_gmmain__near_80006c14();
    u8* global = kar_gmglobal__near_800077e0();

    work->flag_02A_80 = 1;
    if ((s8) global[8] < 5) {
        global[8]++;
    }
}

s32 kar_gmautodemo__near_8000cb34(void)
{
    GmMainWork* work = kar_gmmain__near_80006c14();
    u8* global = kar_gmglobal__near_800077e0();

    if (fn_8003EA9C() != 0) {
        return 0;
    }
    if (work->flag_02A_40 != 0) {
        return 0;
    }
    return (s8) global[9] < 5;
}

void kar_gmautodemo__near_8000cbc0(void)
{
    GmMainWork* work = kar_gmmain__near_80006c14();
    u8* global = kar_gmglobal__near_800077e0();

    work->flag_02A_40 = 1;
    if ((s8) global[9] < 5) {
        global[9]++;
    }
}

s32 kar_gmautodemo__near_8000cc18(void)
{
    GmMainWork* work = kar_gmmain__near_80006c14();
    u8* global = kar_gmglobal__near_800077e0();

    if (kar_shadow__near_8007b650() != 0) {
        return 0;
    }
    if (kar_gmracenormal__8003f6cc() != 0) {
        return 0;
    }
    if (work->flag_02A_20 != 0) {
        return 0;
    }
    return (s8) global[10] < 5;
}

void kar_gmautodemo__near_8000ccb8(void)
{
    GmMainWork* work = kar_gmmain__near_80006c14();
    u8* global = kar_gmglobal__near_800077e0();

    work->flag_02A_20 = 1;
    if ((s8) global[10] < 5) {
        global[10]++;
    }
}

#pragma dont_inline on
void kar_gmautodemo__near_8000cd10(s32 arg0)
{
    GmMainWork* work = kar_gmmain__near_80006c14();

    work->field_014 = arg0;
}
#pragma dont_inline off

#pragma dont_inline on
s32 kar_gmautodemo__near_8000cd40(void)
{
    GmMainWork* work = kar_gmmain__near_80006c14();

    return work->field_014;
}
#pragma dont_inline off

void kar_gmautodemo__near_8000cd68(void)
{
    s32* flags = lbl_805DD540;
    u32 reset_code = 0x80000000 - OSGetResetCode();
    u32 is_reset = (u32) __cntlzw(reset_code) >> 5;

    flags[1] = 0;
    flags[0] = ((u32) -is_reset | is_reset) >> 31;
}

void* kar_gmautodemo__near_8000cdbc(void)
{
    GmMainWork* work = kar_gmmain__near_80006c14();

    return &work->autodemo_state;
}

void kar_gmautodemo__near_8000cde0(void* arg0, void* gobj)
{
    s32 x;
    s32 y;
    s32 z;

    if (GObj_GetFlagFromArray(gobj) == 2 && lbl_805DD548 != NULL) {
        kar_lbhvqm__near_80078028(lbl_805DD548, &x, &y, &z);
        kar_lbkdcoll__near_80076f8c(x, y, z, 0, 0, LOAD_F32(lbl_805DE764),
                                    LOAD_F32(lbl_805DE764),
                                    LOAD_F32(lbl_805DE768),
                                    LOAD_F32(lbl_805DE76C));
    }
}

void kar_gmautodemo__near_8000ce50(void)
{
    GmMainWork* work = kar_gmmain__near_80006c14();
    u32 input;
    s32 debug_enabled;
    u32 debug_mask;
    u32 skip_mask;
    s32 text_entry;
    s32 i;

    if (fn_8000A4EC(0x1E) == 1) {
        return;
    }

    input = 0;
    for (i = 0; i < 20; i++) {
        input |= PLAYER_INPUT(i);
    }

    if (lbl_805DD630 >= 3) {
        debug_enabled = 1;
        debug_mask = 0x400;
        skip_mask = 0x1100;
    } else {
        debug_enabled = 0;
        debug_mask = 0;
        skip_mask = 0x1100;
    }

    if (debug_enabled != 0) {
        if ((input & debug_mask) != 0) {
            kar_lbaudio__near_80061658();
            work->autodemo_state = 5;
            kar_gmlanmenu__800082a0(0x10);
            kar_gmmain__near_800064f0();
            kar_gmlanmenu__80008220();
            kar_lbaudio__near_8005e5d0();
            kar_lbaudio__near_8005e788();
        }

        if ((input & 0x800) != 0) {
            if (lbl_805DD558 != NULL) {
                HSD_SisLib_803A5CC4(lbl_805DD558);
                lbl_805DD558 = NULL;
            } else {
                void* text = HSD_SisLib_803A6754(0, lbl_805DD554);

                lbl_805DD558 = text;
                text_entry = HSD_SisLib_803A6B98(
                    text, LOAD_F32(lbl_805DE758), LOAD_F32(lbl_805DE758),
                    lbl_805D5138, lbl_8049B1A8);
                HSD_SisLib_803A7548(lbl_805DD558, text_entry,
                                    LOAD_F32(lbl_805DE75C),
                                    LOAD_F32(lbl_805DE75C));
                text_entry = HSD_SisLib_803A6B98(
                    lbl_805DD558, LOAD_F32(lbl_805DE758),
                    LOAD_F32(lbl_805DE760), lbl_805D5138, lbl_8049B1E0);
                HSD_SisLib_803A7548(lbl_805DD558, text_entry,
                                    LOAD_F32(lbl_805DE75C),
                                    LOAD_F32(lbl_805DE75C));
                ((u8*) lbl_805DD558)[0x49] = 1;
            }
        }
    }

    work->autodemo_timer++;
    switch (work->autodemo_state) {
    case 0:
        if ((input & skip_mask) != 0) {
            work->autodemo_state = 3;
            work->autodemo_timer = 0;
            fn_80138580();
            work->field_00D = 1;
            kar_plclearchecker_create_first_player_objects();
            kar_lbaudio__near_80061658();
            return;
        }
        if (work->autodemo_timer > 0x8B9) {
            work->autodemo_state = 1;
            fn_80138580();
        }
        break;
    case 1: {
        u32 pressed_skip = input & skip_mask;

        if (pressed_skip != 0 || work->autodemo_timer > 0x9AB) {
            work->autodemo_timer = 0;
            work->field_00D = 1;
            kar_plclearchecker_create_first_player_objects();
            if (pressed_skip != 0) {
                kar_lbaudio__near_80061658();
                work->autodemo_state = 3;
            } else {
                work->autodemo_state = 2;
            }
        }
        break;
    }
    case 2:
        if ((input & skip_mask) != 0 || work->autodemo_timer > 0xA0) {
            work->autodemo_state = 3;
            work->autodemo_timer = 0;
        }
        break;
    case 3:
        kar_lbhvqm__near_80078284(lbl_805DD548);
        if (work->autodemo_timer > 0x1E0) {
            work->autodemo_state = 4;
            work->autodemo_timer = 0;
            kar_lbfade_start_preset0_forward((void*) 1, 0x1E);
        }
        break;
    case 4:
        if (kar_lbfade_is_finished(1) != 0) {
            kar_movie_assets__8000a498(0x10);
            kar_gmmain__near_800064f0();
        }
        break;
    }

    if (work->autodemo_state >= 3) {
        if ((input & skip_mask) != 0) {
            kar_lbaudio__near_80061658();
            kar_lbaudio__near_8005e5d0();
            kar_gmglobal__near_80007808();
            kar_movie_assets__8000a498(0x100);
            kar_gmmain__near_800064f0();
            return;
        }
    }

    switch (work->autodemo_state) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        if ((input & 0x200) != 0 && (s8) fn_8000AECC() == 0) {
            kar_lbaudio__near_800616c8();
            kar_movie_assets__8000a498(0x200);
            kar_gmmain__near_800064f0();
        }
        break;
    case 4:
        break;
    }
}

void kar_gmautodemo_start_opening_movie(void)
{
    const u32* data = lbl_80489508;
    u8* work = (u8*) kar_gmmain__near_80006c14() + 0xC;
    u32 vec_data[9];
    void* cobj;
    void* text;
    s32 entry;

    memset(work, 0, 4);
    lbl_805DD548 = NULL;
    kar_lbfile_wait_for_group6_loads();
    kar_lbaudio__near_8005a7ac();
    fn_801384F4();

    vec_data[0] = data[0];
    vec_data[1] = data[1];
    vec_data[2] = data[2];
    vec_data[3] = data[3];
    vec_data[4] = data[4];
    vec_data[5] = data[5];
    vec_data[6] = data[6];
    vec_data[7] = data[7];
    vec_data[8] = data[8];

    kar_pltrick__near_8023295c();
    kar_gmlanmenu__80277748();
    fn_8000B82C();
    kar_plclearchecker_set_template_vec_008(0, (Vec*) &vec_data[0]);
    kar_plclearchecker_set_template_vecs_014_020(
        0, (Vec*) ((u8*) vec_data + 0xC), (Vec*) ((u8*) vec_data + 0x18));
    kar_plclearchecker_set_slot_player_index(0, 0);
    kar_gmracenormal__8022c86c(0, 2);
    kar_plclearcheckerlib__near_8022c898(0, 0);
    kar_plclearcheckerlib__near_8022c8c8(0, 0);
    kar_plclearcheckerlib__near_8022c8f8(0, 0);
    kar_plclearchecker_set_template_byte_08c(0, 0);
    kar_plclearcheckerlib__near_8022c990(0, 0);
    kar_plclearcheckerlib__near_8022c9c0(0, 0);
    fn_80192BB8(0, 1, 0);
    fn_801C8C6C(0, 0);

    if (kar_gmautodemo__near_8000cd40() == 0) {
        work[0] = 0;
        kar_lbhvqm_init_movie_system();
        lbl_805DD550 = NULL;
        lbl_805DD54C = NULL;
        lbl_805DD548 =
            kar_lbhvqm_open_movie(kar_linkfile_mvopening_h4m_80495b78, 1, 0,
                                  0x18, fn_80078604, fn_80078620);
        if (lbl_805DD548 != NULL) {
            GmAutodemoGObj* movie_gobj;

            lbl_805DD54C = HSD_GObjCreate(0x26, 0x1E, 0);
            HSD_GObjGXLink(lbl_805DD54C, kar_gmautodemo__near_8000cde0, 1,
                           1);
            lbl_805DD550 = HSD_GObjCreate(0x28, 0x11, 0);
            movie_gobj = lbl_805DD550;
            cobj = HSD_CObjLoadDesc(&lbl_80495B38);
            HSD_GObjObjectLink(lbl_805DD550, hsdGObj_default_object_kind,
                               cobj);
            GObj_SetupGXLinkMax(lbl_805DD550, GObj_SetCamera, 2);
            movie_gobj->field_24 = 2;
            movie_gobj->field_20 = 0;
            kar_lbhvqm__near_80077ed4(lbl_805DD548);
            goto setup_text;
        }
    }

    work[0] = 3;
    fn_80138580();
    work[1] = 1;
    kar_plclearchecker_create_first_player_objects();
    kar_lbfile_wait_for_group6_loads();

    switch ((s8) kar_gmracenormal__8000af94()) {
    case 0:
    case 2:
        kar_lbfile_queue_resource_set_mode1();
        kar_lbaudio__near_8005a348();
        break;
    case 1:
        kar_lbfile_queue_resource_set_mode3();
        kar_lbaudio__near_8005a348();
        break;
    case 3:
        kar_lbaudio__near_8005a3dc();
        break;
    }

setup_text:
    *(s16*) (work + 2) = 0;
    lbl_805DD558 = NULL;
    if (lbl_805DD630 >= 1) {
        lbl_805DD554 =
            HSD_SisLib_803A611C(0, NULL, 0x29, 0x11, 0, 0x1B, 0, 5);
        text = HSD_SisLib_803A6754(0, lbl_805DD554);
        lbl_805DD558 = text;
        entry = HSD_SisLib_803A6B98(text, LOAD_F32(lbl_805DE758),
                                    LOAD_F32(lbl_805DE758), lbl_805D5138,
                                    lbl_8049B1A8);
        HSD_SisLib_803A7548(lbl_805DD558, entry, LOAD_F32(lbl_805DE75C),
                            LOAD_F32(lbl_805DE75C));
        entry = HSD_SisLib_803A6B98(lbl_805DD558, LOAD_F32(lbl_805DE758),
                                    LOAD_F32(lbl_805DE760), lbl_805D5138,
                                    lbl_8049B1E0);
        HSD_SisLib_803A7548(lbl_805DD558, entry, LOAD_F32(lbl_805DE75C),
                            LOAD_F32(lbl_805DE75C));
        ((u8*) lbl_805DD558)[0x49] = 1;
    }
}

void kar_gmautodemo__near_8000d5c8(void)
{
    GmMainWork* work = kar_gmmain__near_80006c14();

    fn_801385B0();
    if (work->field_00D != 0) {
        fn_8000B884();
        work->field_00D = 0;
    }

    if (lbl_805DD548 != NULL) {
        GmAutodemoGObj* gobj;

        kar_lbhvqm__near_80078284(lbl_805DD548);
        while (kar_lbhvqm__near_80077f14(lbl_805DD548) != 0) {
            VIWaitForRetrace();
        }

        kar_lbhvqm__near_800780d0(lbl_805DD548);
        kar_lbhvqm__near_80077a5c();
        gobj = lbl_805DD54C;
        lbl_805DD548 = NULL;
        if (gobj != NULL) {
            HSD_GObjDestroy(gobj);
        }
        if (lbl_805DD550 != NULL) {
            HSD_GObjDestroy(lbl_805DD550);
        }
        lbl_805DD54C = NULL;
        lbl_805DD550 = NULL;
    }

    if ((s8) kar_gmracenormal__8000aea8() == 0) {
        kar_gmautodemo__near_8000cd10(0);
        kar_gmlanmenu__800082a0(2);
        kar_gmlanmenu__80008220();
    }
}

void kar_gmautodemo__near_8000d698(void)
{
    kar_gmmain__near_80006c14();
    kar_lbhvqm__near_8007859c();
    if (lbl_805DD548 != NULL && kar_lbhvqm__near_80077f14(lbl_805DD548) == 0) {
        GmAutodemoGObj* gobj;

        kar_lbhvqm__near_800780d0(lbl_805DD548);
        kar_lbhvqm__near_80077a5c();
        gobj = lbl_805DD54C;
        lbl_805DD548 = NULL;
        if (gobj != NULL) {
            HSD_GObjDestroy(gobj);
        }
        if (lbl_805DD550 != NULL) {
            HSD_GObjDestroy(lbl_805DD550);
        }
        lbl_805DD54C = NULL;
        lbl_805DD550 = NULL;
        kar_lbfile_wait_for_group6_loads();

        switch ((s8) kar_gmracenormal__8000af94()) {
        case 0:
        case 2:
            kar_lbfile_queue_resource_set_mode1();
            kar_lbaudio__near_8005a348();
            break;
        case 1:
            kar_lbfile_queue_resource_set_mode3();
            kar_lbaudio__near_8005a348();
            break;
        case 3:
            kar_lbaudio__near_8005a3dc();
            break;
        }
    }
    kar_gmautodemo__near_8000ce50();
}

void kar_gmautodemo__near_8000d768(void* arg0, void* gobj)
{
    s32 x;
    s32 y;
    s32 z;

    if (GObj_GetFlagFromArray(gobj) == 2) {
        kar_lbhvqm__near_80078028(lbl_805DD560, &x, &y, &z);
        kar_lbkdcoll__near_80076f8c(x, y, z, 0, 0, LOAD_F32(lbl_805DE770),
                                    LOAD_F32(lbl_805DE770),
                                    LOAD_F32(lbl_805DE774),
                                    LOAD_F32(lbl_805DE778));
    }
}

void kar_movie_assets__asset_8000d7d0(void)
{
    void* cobj;
    GmAutodemoGObj* gobj;

    kar_gmmain__near_80006c14();
    kar_lbhvqm_init_movie_system();
    lbl_805DD560 =
        kar_lbhvqm_open_movie(kar_linkfile_mvopening_h4m_80495bf0, 1, 0, 0x18,
                              fn_80078604, fn_80078620);
    if (lbl_805DD560 == NULL) {
        kar_gmmain__near_800064f0();
    } else {
        lbl_805DD568 = HSD_GObjCreate(0x1B, 0x1A, 0);
        HSD_GObjGXLink(lbl_805DD568, kar_gmautodemo__near_8000d768, 0x15, 1);
        lbl_805DD564 = HSD_GObjCreate(5, 0x1A, 0);
        cobj = HSD_CObjLoadDesc(&lbl_80495BB0);
        HSD_GObjObjectLink(lbl_805DD564, hsdGObj_default_object_kind,
                           cobj);
        GObj_SetupGXLinkMax(lbl_805DD564, GObj_SetCamera, 5);
        gobj = lbl_805DD564;
        gobj->field_24 = 0x200000;
        gobj->field_20 = 0;
        kar_lbhvqm__near_80077ed4(lbl_805DD560);
        kar_movie_assets__8000a498(0x10);
    }
}

void kar_gmautodemo__near_8000d8c4(void)
{
    kar_gmmain__near_80006c14();
    if (lbl_805DD564 != NULL) {
        HSD_GObjDestroy(lbl_805DD564);
    }
    if (lbl_805DD568 != NULL) {
        HSD_GObjDestroy(lbl_805DD568);
    }

    lbl_805DD568 = NULL;
    lbl_805DD564 = NULL;
    kar_lbhvqm__near_80077a5c();
    if ((s8) kar_gmracenormal__8000aea8() == 1) {
        kar_gmlanmenu__800082a0(0x10);
        kar_gmlanmenu__80008220();
    }
}

void kar_gmautodemo__near_8000d930(void)
{
    s32 i;

    kar_gmmain__near_80006c14();
    kar_lbhvqm__near_8007859c();
    if (kar_lbhvqm__near_80077f14(lbl_805DD560) == 0) {
        kar_lbhvqm__near_800780d0(lbl_805DD560);
        lbl_805DD560 = NULL;
        kar_gmmain__near_800064f0();
        return;
    }

    for (i = 0; i < 4; i++) {
        if ((s8) kar_gmracenormal__8000aea8() == 3) {
            u32 input = PLAYER_INPUT(i);

            if ((input & 0x1D60) != 0) {
                kar_movie_assets__8000a498(0x100);
                kar_lbaudio__near_80061658();
                kar_lbhvqm__near_80078284(lbl_805DD560);
                return;
            }
            if ((input & 0x200) != 0) {
                kar_movie_assets__8000a498(0x100);
                kar_lbaudio__near_800616c8();
                kar_lbhvqm__near_80078284(lbl_805DD560);
                return;
            }
        } else if ((PLAYER_INPUT(i) & 0x1100) != 0) {
            kar_movie_assets__8000a498(0x100);
            kar_lbaudio__near_80061658();
            kar_lbhvqm__near_80078284(lbl_805DD560);
            return;
        }
    }
}

void kar_gmautodemo__near_8000da34(void)
{
    GmMainWork* work = kar_gmmain__near_80006c14();

    work->field_015 = 0;
    if (kar_gmautodemo__near_8000cd40() == 0) {
        work->field_017 = 0;
        kar_gmautodemo__near_8000cd10(0);
        kar_gmglobal__near_800088c8(0);
    } else {
        kar_gmautodemo__near_8000cd10(1);
        kar_gmglobal__near_800088c8(0);
    }
}

s32 kar_gmautodemo__near_8000daa0(void)
{
    GmMainWork* work = kar_gmmain__near_80006c14();
    AutodemoChoice choices[18];
    AutodemoChoice* choice;
    AutodemoChoice* base;
    s32 i;
    s32 count;
    s32 total;
    s32 roll;
    s32 selected;
    s32 sum;

    kar_gmmain__near_80006c14();
    base = choices;
    total = 0;
    choice = base;
    count = 0;
    for (i = 0; i < 18; i++) {
        if (i != work->field_01D && i != work->field_01E &&
            i != work->field_01F && i != work->field_020) {
            u8* entry;
            if (i == 1 ||
                (entry = fn_8000B9DC((s8) i),
                 fn_8000C364(entry[1], entry[2]) != 0)) {
                choice->index = i;
                choice->weight = 1;
                count++;
                total += choice->weight;
                choice++;
            }
        }
    }

    roll = HSD_Randi(total);
    sum = 0;
    selected = 1;
    for (i = 0; i < count; i++) {
        sum += base->weight;
        if (roll < sum) {
            selected = choices[i].index;
            break;
        }
        base++;
    }

    work->field_020 = work->field_01F;
    work->field_01F = work->field_01E;
    work->field_01E = work->field_01D;
    work->field_01D = selected;
    return (s8) selected;
}

void kar_gmautodemo__near_8000dbe8(void)
{
    GmMainWork* work = kar_gmmain__near_80006c14();
    s8* usedp;
    AutodemoCourseSlot* slots;
    s8 used[4];
    s32 primary_slot;
    s32 slot_index;
    AutodemoCourseSlot* slot;
    s32 i;
    s32 zero;

    used[0] = 0;
    slots = (AutodemoCourseSlot*) ((u8*) work + 0xAC8);
    usedp = used;
    used[1] = 0;
    used[2] = 0;
    used[3] = 0;

    if (fn_8000C488(1) != 0) {
        primary_slot = HSD_Randi(4);
        slot_index = HSD_Randi(3);
        if (slot_index >= primary_slot) {
            slot_index++;
        }

        used[primary_slot] = 1;
        slot = &slots[primary_slot];
        slot->field_01 = 1;
        slot->field_02 = 1;
        slot->field_03 = 5;
        slot->field_04 = 0;
    } else {
        slot_index = HSD_Randi(4);
    }

    if (fn_8000C488(2) != 0 && HSD_Randi(3) == 0) {
        zero = 0;
        slot = &slots[slot_index];
        slot->field_01 = 2;
        used[slot_index] = 1;
        slot->field_02 = zero;
        slot->field_03 = 0x12;
        slot->field_04 = zero;
    }

    slot = slots;
    i = 0;
    zero = 0;
    for (; i < 4; i++, usedp++, slot++) {
        if (*usedp == 0) {
            u8* entry;
            u8 field_02;
            u8 field_03;

            kar_gmautodemo__near_8000daa0();
            entry = fn_8000B9DC();
            field_02 = entry[1];
            field_03 = entry[2];
            slot->field_01 = zero;
            slot->field_02 = field_02;
            slot->field_03 = field_03;
            slot->field_04 = i;
        }
    }

    *(u8*) ((u8*) work + 0xA95) = 4;
}

void kar_gmautodemo__near_8000dd4c(void)
{
    GmMainWork* work = kar_gmmain__near_80006c14();
    GmMainWork* work2;
    AutodemoChoice choices[9];
    AutodemoChoice* choice;
    AutodemoChoice* base;
    s32 i;
    s32 count;
    s32 total;
    s32 roll;
    s32 selected;
    s32 sum;

    work2 = kar_gmmain__near_80006c14();
    base = choices;
    choice = base;
    total = 0;
    count = 0;
    for (i = 0; i < 9; i++) {
        if (i != work->field_019 && i != work->field_01A &&
            i != work->field_01B && i != work->field_01C) {
            if (i != 8 || fn_8000C0E0(8) != 0) {
                choice->index = i;
                choice->weight = 1;
                count++;
                total += choice->weight;
                choice++;
            }
        }
    }

    roll = HSD_Randi(total);
    sum = 0;
    selected = 0;
    for (i = 0; i < count; i++) {
        sum += base->weight;
        if (roll < sum) {
            selected = choices[i].index;
            break;
        }
        base++;
    }

    work->field_01C = work->field_01B;
    work->field_01B = work->field_01A;
    work->field_01A = work->field_019;
    work->field_019 = selected;
    *(s8*) ((u8*) work2 + 0xA97) = selected;
}

void kar_gmautodemo__near_8000de88(void)
{
    GmMainWork* work = kar_gmmain__near_80006c14();
    AutodemoChoice choices[7];
    s32 total;
    s32 count;
    AutodemoChoice* base;
    AutodemoChoice* choice;
    s32 i;
    s32 roll;
    s32 selected;
    s32 sum;

    kar_gmmain__near_80006c14();
    base = choices;
    choice = base;
    total = 0;
    count = 0;
    for (i = 0; i < 7; i++) {
        if (i != work->field_021 && i != work->field_022 &&
            i != work->field_023 && i != work->field_024) {
            choice->index = i;
            count++;
            choice->weight = 1;
            total += choice->weight;
            choice++;
        }
    }

    roll = HSD_Randi(total);
    sum = 0;
    selected = 0;
    for (i = 0; i < count; i++) {
        sum += base->weight;
        if (roll < sum) {
            selected = choices[i].index;
            break;
        }
        base++;
    }

    work->field_024 = work->field_023;
    work->field_023 = work->field_022;
    work->field_022 = work->field_021;
    work->field_021 = selected;
    fn_8000B2DC((s8) selected);
}

s32 kar_gmautodemo__near_8000dfb4(void)
{
    GmMainWork* work = kar_gmmain__near_80006c14();
    AutodemoChoice choices[18];
    s32 count;
    AutodemoChoice* choice;
    AutodemoChoice* base;
    s32 i;
    s32 total;
    s32 roll;
    s32 selected;
    s32 sum;

    kar_gmmain__near_80006c14();
    base = choices;
    total = 0;
    choice = base;
    count = 0;
    for (i = 0; i < 18; i++) {
        if (i != work->field_026 && i != work->field_027 &&
            i != work->field_028 && i != work->field_029 && i != 0x11) {
            if (i == 0x10 || i == 0x0F) {
                s8* entry = fn_8000B9DC((s8) i);

                if (fn_8000C508(entry[2]) == 0) {
                    continue;
                }
            }
            choice->index = i;
            choice->weight = 1;
            count++;
            total += choice->weight;
            choice++;
        }
    }

    roll = HSD_Randi(total);
    sum = 0;
    selected = 1;
    for (i = 0; i < count; i++) {
        sum += base->weight;
        if (roll < sum) {
            selected = choices[i].index;
            break;
        }
        base++;
    }

    work->field_029 = work->field_028;
    work->field_028 = work->field_027;
    work->field_027 = work->field_026;
    work->field_026 = selected;
    return (s8) selected;
}

void kar_gmautodemo__near_8000e108(void)
{
    GmMainWork* work = kar_gmmain__near_80006c14();
    AutodemoCourseSlot* slots = (AutodemoCourseSlot*) ((u8*) work + 0xAC8);
    u8* course_data;
    s8 used[3];
    s8* usedp;
    AutodemoCourseSlot* slot;
    s32 i;

    course_data = fn_8003F670();
    slots[0].state = 4;
    usedp = used;
    slots[1].state = 4;
    slots[2].state = 4;
    used[0] = 0;
    used[1] = 0;
    used[2] = 0;
    slots[3].state = 4;

    slot = slots;
    for (i = 0; i < 3; i++, usedp++, slot++) {
        if (*usedp == 0) {
            u8* entry;
            u8 field_02;
            u8 field_03;
            u8* course;

            kar_gmautodemo__near_8000dfb4();
            entry = fn_8000B9DC();
            field_02 = entry[1];
            course = course_data + i;
            field_03 = entry[2];
            slot->state = 1;
            slot->field_01 = 0;
            course[0xC0] = field_02;
            course[0xC5] = field_03;
            slot->field_02 = course[0xC0];
            slot->field_03 = course[0xC5];
            slot->field_04 = i;
        }
    }

    *(u8*) ((u8*) work + 0xA95) = 3;
}

#define GMAUTODEMO_ASSERT(line)                                      \
    do {                                                            \
        OSReport(lbl_80495C00);                                     \
        __assert(kar_src_gmautodemo_80495c14, (line), lbl_805D5140); \
    } while (0)

#define GMAUTODEMO_ADVANCE_SELECTION()                        \
    do {                                                       \
        work = kar_gmmain__near_80006c14();                    \
        work[0x17]++;                                          \
        if ((s8) work[0x17] >= 4) {                            \
            work[0x17] = 0;                                    \
        }                                                      \
        if ((s8) work[0x17] != -1 && (s8) work[0x17] >= -1 &&  \
            (s8) work[0x17] < 4) {                             \
            work[0x15] = 0;                                    \
            kar_gmglobal__near_800088c8(0);                    \
        } else {                                               \
            GMAUTODEMO_ASSERT(0x341);                          \
        }                                                      \
    } while (0)

#define GMAUTODEMO_SET_RACE_MARKER() \
    do {                             \
        kar_gmmain__near_80006c14();                           \
        work = kar_gmmain__near_80006c14();                    \
        work[0xBB9] = 0;                                       \
        work[0xBBC] = 0;                                       \
        work[0xBBF] = 0;                                       \
        work[0xBC2] = 0;                                       \
        work[0xBB9] = 4;                                       \
    } while (0)

void kar_gmautodemo__8000e1d8(void)
{
    u8* root;
    u8* work;
    u32 input;
    u8 old_state;

    root = kar_gmmain__near_80006c14();
    kar_gmracenormal__800081fc();
    input = fn_8000A474();
    old_state = root[0x15];
    work = root;

    switch ((s8) old_state) {
    case 0:
        if ((input & 0x100) != 0) {
            kar_gmlanmenu__800082a0(3);
            kar_gmlanmenu__80008220();
        } else if ((input & 0x200) != 0) {
            root[0x17] = 0;
            kar_gmautodemo__near_8000cd10(0);
            GMAUTODEMO_ADVANCE_SELECTION();
        } else if ((input & 0x10) != 0) {
            work = kar_gmmain__near_80006c14();
            switch ((s8) work[0x17]) {
            case 0:
                kar_gmmain__near_80006c14();
                fn_8003D5B8(0);
                fn_8003D880();
                kar_gmracecommon__near_80013314();
                kar_gmautodemo__near_8000dbe8();
                kar_gmautodemo__near_8000dd4c();
                GMAUTODEMO_SET_RACE_MARKER();
                break;
            case 1:
                kar_gmmain__near_80006c14();
                fn_8003F694(0);
                fn_8003F988();
                kar_gmracenormal__80045a8c();
                kar_gmautodemo__near_8000e108();
                GMAUTODEMO_SET_RACE_MARKER();
                break;
            case 2:
                kar_gmmain__near_80006c14();
                fn_8003D5B8(0);
                fn_8003D880();
                kar_gmracecommon__near_80013314();
                kar_gmautodemo__near_8000dbe8();
                kar_gmautodemo__near_8000dd4c();
                GMAUTODEMO_SET_RACE_MARKER();
                break;
            case 3: {
                s32 i;

                kar_gmmain__near_80006c14();
                fn_8003EA64(0);
                for (i = 0; i < 4; i++) {
                    fn_8000BDA8(i, 1);
                    fn_8000BE2C(i, i);
                    fn_8000BE74(i, 1);
                    fn_8000BEBC(i, i);
                    fn_8000BF04(i, 2);
                    fn_8000BF8C(i, 0);
                }
                kar_gmautodemo__near_8000de88();
                fn_8003EDC4();
                break;
            }
            case -1:
            default:
                GMAUTODEMO_ASSERT(0x306);
                break;
            }

            work = kar_gmmain__near_80006c14();
            switch ((s8) work[0x17]) {
            case 0:
                work[0x15] = 1;
                kar_gmracecommon__near_800132ec();
                kar_gmglobal__near_800088c8(0x12);
                break;
            case 1:
                work[0x15] = 1;
                kar_gmracecommon__near_800132ec();
                kar_gmglobal__near_800088c8(0x12);
                break;
            case 2:
                work[0x15] = 1;
                kar_gmracecommon__near_800132ec();
                kar_gmglobal__near_800088c8(0x12);
                break;
            case 3:
                work[0x15] = 1;
                kar_gmglobal__near_800088c8(0x13);
                break;
            case -1:
            default:
                GMAUTODEMO_ASSERT(0x368);
                break;
            }
        }
        break;
    case 1:
        if ((input & 0x100) != 0) {
            kar_gmautodemo__near_8000cd10(1);
            GMAUTODEMO_ADVANCE_SELECTION();
        } else if ((input & 0x200) != 0) {
            work = kar_gmmain__near_80006c14();
            switch ((s8) work[0x17]) {
            case 0:
                work[0x15] = 2;
                kar_gmglobal__near_800088c8(0x16);
                break;
            case 1:
                work[0x15] = 2;
                kar_gmglobal__near_800088c8(0x19);
                break;
            case 2:
                work[0x15] = 2;
                kar_gmglobal__near_800088c8(0x17);
                break;
            case 3:
                work[0x15] = 2;
                kar_gmglobal__near_800088c8(0x18);
                break;
            case -1:
            default:
                GMAUTODEMO_ASSERT(0x38C);
                break;
            }
        }
        break;
    case 2:
        if ((input & 0x100) != 0) {
            kar_gmautodemo__near_8000cd10(1);
            GMAUTODEMO_ADVANCE_SELECTION();
        } else if ((input & 0x10) != 0) {
            work = kar_gmmain__near_80006c14();
            switch ((s8) work[0x17]) {
            case 0:
                kar_gmautodemo__near_8000cd10(1);
                GMAUTODEMO_ADVANCE_SELECTION();
                break;
            case 1:
                work[0x15] = 3;
                kar_gmglobal__near_800088c8(0x1A);
                break;
            case 2:
                kar_gmautodemo__near_8000cd10(1);
                GMAUTODEMO_ADVANCE_SELECTION();
                break;
            case 3:
                if ((((s8) fn_8000C488(1) != 0) ||
                     ((s8) fn_8000C584(1) != 0)) &&
                    (((s8) fn_8000C488(2) != 0) ||
                     ((s8) fn_8000C584(2) != 0)) &&
                    ((s8) fn_8000C508(4) != 0) &&
                    ((s8) fn_8000C508(8) != 0)) {
                    work[0x15] = 3;
                    kar_gmglobal__near_800088c8(0x1B);
                } else {
                    kar_gmautodemo__near_8000cd10(0);
                    GMAUTODEMO_ADVANCE_SELECTION();
                }
                break;
            case -1:
            default:
                GMAUTODEMO_ASSERT(0x3BC);
                break;
            }
        }
        break;
    case 3:
        if ((input & 0x100) != 0) {
            kar_gmautodemo__near_8000cd10(1);
            GMAUTODEMO_ADVANCE_SELECTION();
        } else if ((input & 0x10) != 0) {
            work = kar_gmmain__near_80006c14();
            switch ((s8) work[0x17]) {
            case 0:
                kar_gmautodemo__near_8000cd10(1);
                GMAUTODEMO_ADVANCE_SELECTION();
                break;
            case 1:
                kar_gmautodemo__near_8000cd10(0);
                GMAUTODEMO_ADVANCE_SELECTION();
                break;
            case 2:
                kar_gmautodemo__near_8000cd10(1);
                GMAUTODEMO_ADVANCE_SELECTION();
                break;
            case 3:
                kar_gmautodemo__near_8000cd10(0);
                GMAUTODEMO_ADVANCE_SELECTION();
                break;
            case -1:
            default:
                GMAUTODEMO_ASSERT(0x3E0);
                break;
            }
        }
        break;
    }

    root[0x16] = old_state;
}

#undef GMAUTODEMO_SET_RACE_MARKER
#undef GMAUTODEMO_ADVANCE_SELECTION
#undef GMAUTODEMO_ASSERT

u64 kar_gmautodemo__near_8000ecd0(s32 arg0)
{
    return lbl_80537000.entries[(u8) arg0].field_00;
}

u64 kar_gmautodemo__near_8000ecf0(s32 arg0)
{
    return lbl_80537000.entries[(u8) arg0].pressed;
}

u64 kar_gmautodemo__near_8000ed10(s32 arg0)
{
    return lbl_80537000.entries[(u8) arg0].held;
}

u64 kar_gmautodemo__near_8000ed30(s32 arg0)
{
    return lbl_80537000.entries[(u8) arg0].field_20;
}

#define SET_INPUT_FLAG_IF_ANY(field, mask, flag)        \
    do {                                                \
        if (((field) & (u64) (mask)) != 0) {            \
            (field) |= ((u64) (flag) << 32);            \
        }                                               \
    } while (0)

#define SET_INPUT_FLAG_IF_ALL(field, mask, flag)        \
    do {                                                \
        if (((field) & (u64) (mask)) == (u64) (mask)) { \
            (field) |= ((u64) (flag) << 32);            \
        }                                               \
    } while (0)

void kar_gmautodemo__near_8000ed50(s32 arg0)
{
    arg0 *= sizeof(AutodemoInputEntry);

#define INPUT_FIELD(offset) (*(u64*) ((u8*) &lbl_80537000 + arg0 + (offset)))

    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x00), 0x1100, 0x1);
    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x10), 0x1100, 0x1);
    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x08), 0x1100, 0x1);
    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x18), 0x1100, 0x1);

    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x00), 0x200, 0x2);
    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x10), 0x200, 0x2);
    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x08), 0x200, 0x2);
    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x18), 0x200, 0x2);

    SET_INPUT_FLAG_IF_ALL(INPUT_FIELD(0x00), 0x1060, 0x4);
    SET_INPUT_FLAG_IF_ALL(INPUT_FIELD(0x10), 0x1060, 0x4);
    if ((INPUT_FIELD(0x00) & (u64) 0x1060) == (u64) 0x1060) {
        SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x08), 0x1060, 0x4);
    }
    if ((INPUT_FIELD(0x00) & (u64) 0x1060) == (u64) 0x1060) {
        SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x18), 0x1060, 0x4);
    }

    SET_INPUT_FLAG_IF_ALL(INPUT_FIELD(0x00), 0x1160, 0x8);
    SET_INPUT_FLAG_IF_ALL(INPUT_FIELD(0x10), 0x1160, 0x8);
    if ((INPUT_FIELD(0x00) & (u64) 0x1160) == (u64) 0x1160) {
        SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x08), 0x1160, 0x8);
    }
    if ((INPUT_FIELD(0x00) & (u64) 0x1160) == (u64) 0x1160) {
        SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x18), 0x1160, 0x8);
    }

    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x00), 0x10008, 0x10);
    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x10), 0x10008, 0x10);
    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x08), 0x10008, 0x10);
    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x18), 0x10008, 0x10);

    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x00), 0x20004, 0x20);
    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x10), 0x20004, 0x20);
    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x08), 0x20004, 0x20);
    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x18), 0x20004, 0x20);

    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x00), 0x40001, 0x40);
    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x10), 0x40001, 0x40);
    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x08), 0x40001, 0x40);
    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x18), 0x40001, 0x40);

    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x00), 0x80002, 0x80);
    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x10), 0x80002, 0x80);
    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x08), 0x80002, 0x80);
    SET_INPUT_FLAG_IF_ANY(INPUT_FIELD(0x18), 0x80002, 0x80);

#undef INPUT_FIELD
}

#undef SET_INPUT_FLAG_IF_ANY
#undef SET_INPUT_FLAG_IF_ALL

void fn_8000F5EC(s32 arg0)
{
    AutodemoInputTable* table = &lbl_80537000;

    if (table->entries[arg0].pressed != 0 ||
        table->entries[arg0].field_18 != 0) {
        table->entries[arg0].field_20 = table->entries[arg0].pressed;
        table->entries[arg0].field_28 = table->field_3F4;
        table->entries[arg0].field_2C = 0;
        return;
    }

    if ((s32) table->entries[arg0].field_2C < table->field_3FC) {
        table->entries[arg0].field_2C++;
    }

    if ((s32) table->entries[arg0].field_28 != 0) {
        table->entries[arg0].field_28--;
        table->entries[arg0].field_20 = 0;
        return;
    }

    table->entries[arg0].field_20 = table->entries[arg0].field_00;
    if ((s32) table->entries[arg0].field_2C >= table->field_3FC) {
        table->entries[arg0].field_28 = table->field_3FE;
    } else if ((s32) table->entries[arg0].field_2C >= table->field_3F8) {
        table->entries[arg0].field_28 = table->field_3FA;
    } else {
        table->entries[arg0].field_28 = table->field_3F6;
    }
}

void kar_gmautodemo__near_8000f6fc(void)
{
    AutodemoInputEntry* entry;
    AutodemoInputTable* table;
    AutodemoInputEntry* aggregate;
    s32 i;
    s32 j;

    entry = lbl_80537000.entries;
    table = (AutodemoInputTable*) entry;

    for (i = 0; i < 20; i++, entry++) {
        u8* pad = HSD_PadCopyStatus + ((u8) i * 0x44);

        entry->field_00 = *(u32*) (pad + 0);
        entry->pressed = *(u32*) (pad + 8);
        entry->held = *(u32*) (pad + 0xC);
        entry->field_18 = *(u32*) (pad + 0x10);
        kar_gmautodemo__near_8000ed50(i);
        table->callback(i);
    }

    aggregate = &table->entries[20];
    aggregate->field_00 = 0;
    aggregate->pressed = 0;
    aggregate->held = 0;
    aggregate->field_18 = 0;
    aggregate->field_20 = 0;

    entry = table->entries;
    for (j = 0; j < 4; j++, entry += 5) {
        aggregate->field_00 |= entry[0].field_00;
        aggregate->pressed |= entry[0].pressed;
        aggregate->held |= entry[0].held;
        aggregate->field_18 |= entry[0].field_18;
        aggregate->field_20 |= entry[0].field_20;

        aggregate->field_00 |= entry[1].field_00;
        aggregate->pressed |= entry[1].pressed;
        aggregate->held |= entry[1].held;
        aggregate->field_18 |= entry[1].field_18;
        aggregate->field_20 |= entry[1].field_20;

        aggregate->field_00 |= entry[2].field_00;
        aggregate->pressed |= entry[2].pressed;
        aggregate->held |= entry[2].held;
        aggregate->field_18 |= entry[2].field_18;
        aggregate->field_20 |= entry[2].field_20;

        aggregate->field_00 |= entry[3].field_00;
        aggregate->pressed |= entry[3].pressed;
        aggregate->held |= entry[3].held;
        aggregate->field_18 |= entry[3].field_18;
        aggregate->field_20 |= entry[3].field_20;

        aggregate->field_00 |= entry[4].field_00;
        aggregate->pressed |= entry[4].pressed;
        aggregate->held |= entry[4].held;
        aggregate->field_18 |= entry[4].field_18;
        aggregate->field_20 |= entry[4].field_20;
    }
}

void kar_gmautodemo__near_8000fa78(void)
{
    volatile AutodemoInputTable* table = &lbl_80537000;
    void (*callback)(s32) = fn_8000F5EC;

    lbl_80537000 = lbl_80495C28;
    table->entries[0].field_28 = table->field_3F4;
    table->entries[1].field_28 = table->field_3F4;
    table->entries[2].field_28 = table->field_3F4;
    table->entries[3].field_28 = table->field_3F4;
    table->entries[4].field_28 = table->field_3F4;
    table->entries[5].field_28 = table->field_3F4;
    table->entries[6].field_28 = table->field_3F4;
    table->entries[7].field_28 = table->field_3F4;
    table->entries[8].field_28 = table->field_3F4;
    table->entries[9].field_28 = table->field_3F4;
    table->entries[10].field_28 = table->field_3F4;
    table->entries[11].field_28 = table->field_3F4;
    table->entries[12].field_28 = table->field_3F4;
    table->entries[13].field_28 = table->field_3F4;
    table->entries[14].field_28 = table->field_3F4;
    table->entries[15].field_28 = table->field_3F4;
    table->entries[16].field_28 = table->field_3F4;
    table->entries[17].field_28 = table->field_3F4;
    table->entries[18].field_28 = table->field_3F4;
    table->entries[19].field_28 = table->field_3F4;
    table->entries[20].field_28 = table->field_3F4;
    table->callback = callback;
}

s32 kar_gmautodemo__near_8000fb6c(s32 arg0)
{
    if (arg0 == 0) {
        kar_lbaudio__near_800616c8();
        kar_gmautodemo__near_8000cd10(1);
        kar_gmlanmenu__800082a0(2);
        kar_gmmain__near_800064f0();
        kar_gmlanmenu__80008220();
    }

    return 0;
}

void kar_gmautodemo__near_8000fbb0(void)
{
    GmMainWork* work = kar_gmmain__near_80006c14();
    void* textlib;

    kar_lbaudio__near_8005fd38(1);
    kar_lbaudio__near_8005fd9c(1);
    kar_lbaudio__near_8005fa48(0xFF);
    kar_lbaudio__near_8005fae4(0xFF);
    kar_lbaudio__near_8005fb64(0xFF);
    kar_smsoundtest__near_800aebc0();

    *(void**) ((u8*) work + 0x344) = kar_debug_menu_top_entries_8049f608;
    *(void**) ((u8*) work + 0x348) = kar_gmautodemo__near_8000fb6c;

    kar_db_assets__asset_8007cf78();
    fn_800ACF40();
    kar_si_assets__asset_800ad0c8();
    kar_textlib__near_800aca04(0, *(void**) ((u8*) work + 0x344), 0xA, 0xA);
    textlib = kar_textlib__near_800aba6c();
    kar_textlib__near_800aba74(textlib, *(void**) ((u8*) work + 0x348));
}

void kar_gmautodemo__near_8000fc4c(void)
{
    fn_800AD1A4(kar_gmmain__near_80006c14());
}

#pragma dont_inline on
void kar_gm_assets__asset_8000fc70(void)
{
    kar_lbarchive__80059a20(0, kar_linkfile_gmdata_dat_80496028, &lbl_805DD574,
                            lbl_80496034, 0);
}
#pragma dont_inline off

#pragma dont_inline on
void* kar_gmautodemo__near_8000fcb0(void)
{
    return lbl_805DD574;
}
#pragma dont_inline off

#pragma dont_inline on
void kar_gmautodemo__near_8000fcb8(s32* out_minutes, s32* out_seconds,
                                   s32* out_centiseconds)
{
    GmMainWork* work;
    s32* counters;
    s32 player_id;
    s32 old_seconds;
    s32 current_seconds;
    s32 old_frame;
    s32 frame;
    s32 elapsed_seconds;
    s32 elapsed_frame;
    s32 total_frames;

    work = kar_gmmain__near_80006c14();
    counters = lbl_805DD570;
    player_id = 0;
    for (;;) {
        if ((s8) fn_8000948C(player_id) == 0) {
            break;
        }
        player_id++;
        if (player_id >= 4) {
            break;
        }
    }

    old_seconds = counters[player_id + 0x25] / 60;
    old_frame = counters[player_id + 0x25] % 60;
    current_seconds = *(s32*) ((u8*) work + 0x834);
    frame = *(u8*) ((u8*) work + 0x833);

    elapsed_seconds = current_seconds - old_seconds;
    elapsed_frame = frame - old_frame;
    if (elapsed_frame < 0) {
        elapsed_seconds--;
        elapsed_frame += 60;
    }

    total_frames = elapsed_frame + elapsed_seconds * 60;
    if (total_frames >= 0x57E40) {
        *out_minutes = 99;
        *out_seconds = 59;
        *out_centiseconds = 99;
    } else {
        s32 frame_remainder = elapsed_frame % 60;

        *out_minutes = elapsed_seconds / 60;
        *out_seconds = elapsed_seconds % 60;
        *out_centiseconds = (s32) (LOAD_F32(lbl_805DE780) *
                                   (f32) frame_remainder /
                                   LOAD_F32(lbl_805DE784));
    }
}
#pragma dont_inline off

void kar_gmautodemo__near_8000fe34(void)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 unlock;
    s32 unlocked;
    s32 should_play;
    s32 state;

    if (kar_gmracenormal__8000af5c() == 0 &&
        ((work[0xAA7] >> 5) & 1) != 0) {
        state = (s8) work[0xA98];
        if (state == 1) {
            should_play = 0;
            unlock = fn_8026288C(*(s8*) &work[0xA97]);
            if (unlock != -1) {
                if (kar_shadow__near_8007b650() != 0) {
                    if ((unlock >> 16) == 0) {
                        unlocked = kar_gmglobal__near_80007e34((s8) (u16) unlock);
                    } else if ((unlock >> 16) == 2) {
                        unlocked = kar_gmglobal__near_80007e8c((s8) (u16) unlock);
                    }
                } else {
                    unlocked =
                        ClearChecker_CheckUnlocked((u8) (unlock >> 16), (u8) unlock);
                }
            } else {
                unlocked = 0;
            }

            if (unlocked != 0) {
                if ((s8) work[0xA99] != 0) {
                    should_play = 1;
                } else {
                    unlock = fn_80261FDC();
                    if (unlock > HSD_Randi(100)) {
                        should_play = 1;
                    }
                }
            }

            if (should_play != 0) {
                kar_lbaudio__near_8005e1a8(fn_80261F58());
            } else {
                kar_lbaudio__near_8005e1a8(fn_80261ED4());
            }
        } else {
            kar_lbaudio__near_8005e1a8(state);
        }
    }
}

void kar_gmautodemo__near_8000ff78(void)
{
    u8* work = kar_gmmain__near_80006c14();
    s32 state = work[0x832];
    s32 offset;
    AutodemoPlayerResults* results;
    s32 i;

    results = (AutodemoPlayerResults*) (work + 0x830);
    if (state == 4 && kar_gmmain__near_80005d54() != 0) {
        return;
    }

    if (kar_gmmain__near_80005d04(2) != 0) {
        return;
    }

    for (i = 0, offset = 0; i < 5; i++, offset += 4) {
        s32 timer;

        if (kar_plclearcheckerlib__near_8022c858(i) == 4) {
            continue;
        }

        timer = *(s32*) ((u8*) lbl_805DD570 + offset + 0xBC);
        if (timer <= 0) {
            if (kar_cmreplay__8022cc30(i) != 0 && results->field_027[i] == 0) {
                *(s32*) ((u8*) lbl_805DD570 + offset + 0xBC) = 0x96;
            }
            continue;
        }

        timer--;
        *(s32*) ((u8*) lbl_805DD570 + offset + 0xBC) = timer;
        timer = *(s32*) ((u8*) lbl_805DD570 + offset + 0xBC);
        if (timer == 0x5A) {
            s32 object_id = fn_800099A0(i);

            if (object_id != -1) {
                if (results->field_027[i] != 0) {
                    continue;
                }

                {
                    void* object = fn_800B8054(object_id);
                    s32 fade;

                    if (object == NULL) {
                        continue;
                    }

                    fade = kar_lbvector__near_80065a80(0x20);
                    *(s32*) ((u8*) lbl_805DD570 + offset + 0xA8) = fade;
                    fade = *(s32*) ((u8*) lbl_805DD570 + offset + 0xA8);
                    if (fade == 0) {
                        continue;
                    }

                    kar_lbfade_set_draw_priority((void*) fade, 1);
                    kar_lbvector__near_80065b40(
                        *(void**) ((u8*) lbl_805DD570 + offset + 0xA8), object);
                    kar_lbfade_start_preset0_forward(
                        *(void**) ((u8*) lbl_805DD570 + offset + 0xA8), 0x3C);
                }
            } else {
                *(void**) ((u8*) lbl_805DD570 + offset + 0xA8) = NULL;
            }
        } else if (timer == 0x1E) {
            if (kar_plclearchecker_call_clobject_func_1926f4(i) != 0 &&
                (s8) fn_8000916C() != 0xE) {
                results->field_027[i] = 1;
                continue;
            }

            if (fn_8000A1B0() != 0) {
                results->field_027[i] = 1;
                continue;
            }

            if (fn_8000A1B0() != 0) {
                results->field_027[i] = 1;
                continue;
            }

            results->field_027[i] = 0;
            {
                s32 fade = *(s32*) ((u8*) lbl_805DD570 + offset + 0xA8);

                if (fade != 0) {
                    kar_lbfade_start_preset0_reverse((void*) fade, 0x1E);
                }
            }

            kar_plclearcheckerlib__near_8022cc80(i, 1);
            if ((s32) work[0xA94] == 0xE) {
                kar_plclearcheckerlib__near_8022ca38(i,
                                                     LOAD_F32(lbl_805DE79C));
            }
        } else if (timer == 0) {
            s32 fade = *(s32*) ((u8*) lbl_805DD570 + offset + 0xA8);

            if (fade != 0 && results->field_027[i] == 0) {
                kar_lbvector__near_80065ae4((void*) fade);
                *(void**) ((u8*) lbl_805DD570 + offset + 0xA8) = NULL;
            }
        }
    }
}

void kar_gmautodemo__near_800101f4(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();
    AutodemoPlayerResults* result_word;
    AutodemoPlayerResults* results;
    s32 slot;
    s32 did_update = 0;
    s32 entry_offset;
    s32* slot_word;
    s32* counters;

    results = (AutodemoPlayerResults*) (work + 0x830);
    result_word = (AutodemoPlayerResults*) ((u8*) results + arg0 * 4);

    if (result_word->field_04C[0] >= result_word->field_038[0]) {
        return;
    }

    result_word->field_04C[0]++;
    switch ((s8) work[0xA94]) {
    case 0:
    case 4:
    case 0xF:
        if (result_word->field_04C[0] == (s8) work[0xA9A] - 1 &&
            fn_80009A30(arg0) != -1) {
            fn_801137F0(arg0);
        }
        if (result_word->field_04C[0] > (s8) work[0xA9A]) {
            return;
        }
        break;
    }

    entry_offset = arg0 * 0xC;
    if (*(s32*) ((u8*) results + entry_offset + 0xB8) != 0) {
        *(s32*) ((u8*) results + entry_offset + 0xB0) =
            *(s32*) ((u8*) results + entry_offset + 0xB4);
        *(s32*) ((u8*) results + entry_offset + 0xEC) =
            *(s32*) ((u8*) results + entry_offset + 0xF0);
        *(s32*) ((u8*) results + entry_offset + 0xB4) =
            *(s32*) ((u8*) results + entry_offset + 0xB8);
        *(s32*) ((u8*) results + entry_offset + 0xF0) =
            *(s32*) ((u8*) results + entry_offset + 0xF4);
    }

    entry_offset = arg0 * 0xC;
    slot = 0;
    if (*(s32*) ((u8*) results + entry_offset + 0xB0) != 0) {
        slot = 1;
        if (*(s32*) ((u8*) results + entry_offset + 0xB4) != 0) {
            slot = 2;
        }
    }

    slot_word = (s32*) ((u8*) results + entry_offset + slot * 4);
    *(s32*) ((u8*) slot_word + 0xB0) =
        results->field_003 + results->field_004 * 0x3C;
    counters = (s32*) ((u8*) lbl_805DD570 + arg0 * 4);
    *(s32*) ((u8*) slot_word + 0xB0) -= counters[0x94 / 4];
    *(s32*) ((u8*) slot_word + 0xEC) = result_word->field_04C[0];

    if (result_word->field_09C[0] == 0 ||
        *(s32*) ((u8*) slot_word + 0xB0) < result_word->field_09C[0]) {
        result_word->field_09C[0] = *(s32*) ((u8*) slot_word + 0xB0);
        OSTicksToCalendarTime(OSGetTime(),
                              (void*) ((u8*) results + arg0 * 0x28 + 0x138));
        results->field_128[arg0][slot] = 1;
        did_update = 1;
        kar_grlib2__near_800bbcec(fn_800B8188(arg0), 6, 0);
        kar_plclearcheckerlib__near_8022d278(arg0, 0);
    }

    counters[0x94 / 4] = results->field_003 + results->field_004 * 0x3C;
    fn_8027A168(arg0, did_update);
    if ((s8) kar_gmracenormal__8003d5f0() == 2) {
        kar_pltrick__near_80232b18();
    }

    if (results->field_022[arg0] == 0) {
        kar_plclearcheckerlib__near_8022e88c(arg0);
        kar_plclearcheckerlib__near_8022ea10(arg0);
        kar_gmclearchecker__near_8004a90c(arg0);
    }

    if ((s8) work[0xA94] == 0 && fn_800098C0(fn_800B8708(arg0)) != 0) {
        if (did_update != 0) {
            kar_lbaudio__near_8006176c(0x2000B);
        } else {
            kar_lbaudio__near_8006176c(0x2000A);
        }
    }
}

void kar_gmautodemo__near_80010478(void)
{
    AutodemoPlayerResults* results =
        (AutodemoPlayerResults*) ((u8*) kar_gmmain__near_80006c14() + 0x830);
    AutodemoPlayerResults* result_word;
    AutodemoClearData data;
    s32 offset;
    s32 i;

    i = 0;
    result_word = results;
    offset = 0;
    for (; i < 5; i++, offset += 4,
        result_word = (void*) ((u8*) result_word + 4)) {
        f32 progress;
        f32 scaled_progress;
        u8 state;
        s32 signed_state;

        if (kar_plclearcheckerlib__near_8022c858(i) == 4) {
            continue;
        }

        kar_plclearcheckerlib__near_8022ce94(i, &data);
        if (data.field_00 == -1) {
            return;
        }

        if (results->field_200[i] != 0) {
            continue;
        }

        if ((s32) kar_plclearcheckerlib__near_8022cedc(i) != 0 &&
            fn_80009A30(i) != -1) {
            fn_8011370C(i);
        }

        *(s32*) ((u8*) lbl_805DD570 + offset + 0x6C) = data.field_00;
        *(f32*) ((u8*) lbl_805DD570 + offset + 0x80) = data.field_08;
        progress = data.field_04;
        result_word->field_060[0] = progress;

        state = results->field_01D[i];
        signed_state = (s8) state;
        switch (signed_state) {
        case 0:
            if (progress >= LOAD_F32(lbl_805DE7A0) &&
                progress < LOAD_F32(lbl_805DE7A4)) {
                results->field_01D[i] = state + 1;
            }
            if (progress >= LOAD_F32(lbl_805DE7A4) &&
                progress < LOAD_F32(lbl_805DE79C)) {
                results->field_01D[i] = 2;
                if (result_word->field_038[0] >= 0) {
                    result_word->field_038[0]--;
                }
            }
            break;
        case 1:
            if (progress >= LOAD_F32(lbl_805DE7A4)) {
                results->field_01D[i] = state + 1;
            }
            if (progress >= LOAD_F32(lbl_805DE7A8) &&
                progress < LOAD_F32(lbl_805DE7A0)) {
                results->field_01D[i]--;
            }
            break;
        case 2:
            if ((progress >= LOAD_F32(lbl_805DE7A8) &&
                 progress < LOAD_F32(lbl_805DE7A0)) ||
                progress >= LOAD_F32(lbl_805DE79C)) {
                results->field_01D[i] = 0;
                result_word->field_038[0]++;
                kar_gmautodemo__near_800101f4(i);
            }
            if (progress >= LOAD_F32(lbl_805DE7A0) &&
                progress < LOAD_F32(lbl_805DE7A4)) {
                results->field_01D[i]--;
            }
            break;
        }

        scaled_progress = result_word->field_060[0] * results->field_014;
        result_word->field_21C[0] =
            (f32) result_word->field_038[0] * results->field_014 +
            scaled_progress;
        if (result_word->field_21C[0] < LOAD_F32(lbl_805DE7A8)) {
            result_word->field_21C[0] = LOAD_F32(lbl_805DE7A8);
        }
    }
}

s32 kar_gmautodemo__near_800106ec(s32 arg0)
{
    AutodemoPlayerResults* results =
        (AutodemoPlayerResults*) ((u8*) kar_gmmain__near_80006c14() + 0x830);
    AutodemoClearData data;
    u8* save_data;
    s32 checkpoint;
    f32 progress;
    u8 state;
    s32 signed_state;

    kar_plclearcheckerlib__near_8022ce94(arg0, &data);
    checkpoint = data.field_00;
    if (checkpoint == -1) {
        return 0;
    }

    save_data = (u8*) lbl_805DD570 + arg0 * 4;
    *(s32*) (save_data + 0x6C) = checkpoint;
    *(f32*) (save_data + 0x80) = data.field_08;
    progress = data.field_04;
    results->field_060[arg0] = progress;

    state = results->field_01D[arg0];
    signed_state = (s8) state;
    switch (signed_state) {
    case 0:
        if (progress >= LOAD_F32(lbl_805DE7A0) &&
            progress < LOAD_F32(lbl_805DE7A4)) {
            results->field_01D[arg0] = state + 1;
        }
        if (progress >= LOAD_F32(lbl_805DE7A4) &&
            progress < LOAD_F32(lbl_805DE79C)) {
            results->field_01D[arg0] = 2;
            if (results->field_038[arg0] >= 0) {
                results->field_038[arg0]--;
            }
        }
        break;
    case 1:
        if (progress >= LOAD_F32(lbl_805DE7A4)) {
            results->field_01D[arg0] = state + 1;
        }
        if (progress >= LOAD_F32(lbl_805DE7A8) &&
            progress < LOAD_F32(lbl_805DE7A0)) {
            results->field_01D[arg0]--;
        }
        break;
    case 2:
        if ((progress >= LOAD_F32(lbl_805DE7A8) &&
             progress < LOAD_F32(lbl_805DE7A0)) ||
            progress >= LOAD_F32(lbl_805DE79C)) {
            results->field_01D[arg0] = 0;
            return 1;
        }
        if (progress >= LOAD_F32(lbl_805DE7A0) &&
            progress < LOAD_F32(lbl_805DE7A4)) {
            results->field_01D[arg0]--;
        }
        break;
    }

    return 0;
}

void kar_gmautodemo__near_800108b0(void)
{
    AutodemoPlayerResults* results =
        (AutodemoPlayerResults*) ((u8*) kar_gmmain__near_80006c14() + 0x830);
    s32 i;
    s32 j;

    for (i = 0; i < 5; i++) {
        if (kar_plclearcheckerlib__near_8022c858(i) != 4 &&
            results->field_200[i] == 0) {
            results->field_018[i] = 0;
            for (j = 0; j < 5; j++) {
                if (i != j && kar_plclearcheckerlib__near_8022c858(j) != 4 &&
                    results->field_200[j] == 0) {
                    if (results->field_022[i] != 0) {
                        if (results->field_022[j] != 0 &&
                            results->field_088[i] > results->field_088[j]) {
                            results->field_018[i]++;
                        }
                    } else if (results->field_022[j] != 0) {
                        results->field_018[i]++;
                    } else if ((s32) (results->field_21C[i] /
                                      lbl_805DE7AC) <
                               (s32) (results->field_21C[j] /
                                      lbl_805DE7AC)) {
                        results->field_018[i]++;
                    }
                }
            }
        }
    }
}

void kar_gmautodemo__near_800109f8(void)
{
    AutodemoPlayerResults* results =
        (AutodemoPlayerResults*) ((u8*) kar_gmmain__near_80006c14() + 0x830);
    s32 i;
    s32 j;

    for (i = 0; i < 5; i++) {
        if (kar_plclearcheckerlib__near_8022c858(i) != 4 &&
            results->field_200[i] == 0) {
            results->field_018[i] = 0;
            for (j = 0; j < 5; j++) {
                if (i != j && kar_plclearcheckerlib__near_8022c858(j) != 4 &&
                    results->field_200[j] == 0 &&
                    results->field_208[i] < results->field_208[j]) {
                    results->field_018[i]++;
                }
            }
        }
    }
}

void kar_gmautodemo__near_80010ac8(void)
{
    AutodemoPlayerResults* results =
        (AutodemoPlayerResults*) ((u8*) kar_gmmain__near_80006c14() + 0x830);
    s32 i;
    s32 j;

    for (i = 0; i < 5; i++) {
        if (kar_plclearcheckerlib__near_8022c858(i) != 4 &&
            results->field_200[i] == 0) {
            results->field_018[i] = 0;
            for (j = 0; j < 5; j++) {
                if (i != j && kar_plclearcheckerlib__near_8022c858(j) != 4 &&
                    results->field_200[j] == 0) {
                    if ((s32) (results->field_21C[i] /
                               lbl_805DE7AC) <
                        (s32) (results->field_21C[j] /
                               lbl_805DE7AC)) {
                        results->field_018[i]++;
                    }
                }
            }
        }
    }
}

s32 kar_gmautodemo__near_80010bbc(s32 arg0)
{
    u8* work = kar_gmmain__near_80006c14();
    AutodemoPlayerResults* results =
        (AutodemoPlayerResults*) (work + 0x830);
    s32 ret = 0;

    if (kar_plclearcheckerlib__near_8022c858(arg0) != 4) {
        if (results->field_022[arg0] != 0) {
            ret = 1;
        } else if (results->field_038[arg0] >= (s8) work[0xA9A]) {
            results->field_022[arg0] = 1;
            results->field_088[arg0] =
                results->field_003 + results->field_004 * 0x3C;
            OSTicksToCalendarTime(
                OSGetTime(), (void*) ((u8*) results + arg0 * 0x28 + 0x138));

            if (kar_plclearcheckerlib__near_8022c858(arg0) == 1) {
                fn_8012A1C0(arg0);
                kar_lbaudio__near_800617cc(0x200A3);
                kar_plclearcheckerlib__near_8022d278(arg0, 0);
            } else {
                if (fn_800B8708(arg0) != -1) {
                    s32 rank;

                    results = (AutodemoPlayerResults*) ((u8*) results + arg0);
                    rank = results->field_018[0];

                    if (((((u8*) kar_gmmain__near_80006c14())[0xAA7] >> 5) &
                         1) != 0) {
                        if (rank == 0) {
                            *(s32*) ((u8*) lbl_805DD570 + 8) = 0x12C;
                            kar_lbaudio__near_8005fca0(0x19, 1);
                            kar_lbaudio__near_800617cc(0x200A1);
                        } else {
                            kar_lbaudio__near_800617cc(0x200A2);
                        }
                    }

                    fn_80279D5C(arg0, results->field_018[0]);
                    kar_grlib2__near_800bbcec(fn_800B8188(arg0), 7, 0);
                    kar_plclearcheckerlib__near_8022d278(arg0, 1);
                    kar_plclearcheckerlib__near_8022d850(arg0);
                }
            }

            if (kar_plclearcheckerlib__near_8022c858(arg0) == 0 &&
                fn_80009A30(arg0) != -1) {
                fn_801142FC(arg0);
            }

            kar_plclearchecker_update_primary_flags(arg0);
            kar_gmclearchecker__near_8004a994(arg0);
            ret = 1;
        } else if (kar_plclearcheckerlib__near_8022c858(arg0) == 1) {
            ret = 1;
        }
    }

    return ret;
}

s32 kar_gmautodemo__near_80010dac(s32 arg0)
{
    AutodemoPlayerResults* results =
        (AutodemoPlayerResults*) ((u8*) kar_gmmain__near_80006c14() + 0x830);
    Vec pos;
    f32 progress;

    kar_plclearchecker_get_template_vec_008(arg0, &pos);
    switch ((s8) ((u8*) lbl_805DD570)[arg0 + 0x15]) {
    case 0:
        if (kar_grlib2__near_800d52e4(&pos) >= LOAD_F32(lbl_805DE7A8)) {
            ((u8*) lbl_805DD570)[arg0 + 0x15] = 1;
            fn_80113C70(arg0);
        }
        break;
    case 1:
        progress = lbl_805DE794 * kar_grlib2__near_800d52e4(&pos) /
                   lbl_805DE7B0;
        results->field_21C[arg0] = progress;
        if (results->field_21C[arg0] < lbl_805DE7A8) {
            results->field_21C[arg0] = lbl_805DE7A8;
        }

        if (kar_plclearcheckerlib__near_8022d49c(arg0) != 0) {
            if (pos.x < LOAD_F32(lbl_805DE7A8)) {
                pos.x += LOAD_F32(lbl_805DE7B4);
            } else {
                pos.x -= LOAD_F32(lbl_805DE7B4);
            }

            switch (kar_plclearcheckerlib__near_8022c910(arg0)) {
            case 8:
                pos.y -= LOAD_F32(lbl_805DE7B8);
                break;
            case 9:
                pos.y -= LOAD_F32(lbl_805DE7BC);
                break;
            case 0x15:
            case 0x17:
                pos.y -= LOAD_F32(lbl_805DE7C0);
                break;
            case 0x16:
                pos.y -= LOAD_F32(lbl_805DE7C4);
                break;
            default:
                pos.y -= LOAD_F32(lbl_805DE7C8);
                break;
            }

            kar_grlib2__near_800d5370(&pos);
            results->field_022[arg0] = 1;
            ((u8*) lbl_805DD570)[arg0 + 0x15] = 2;
            fn_80113D58(arg0);
            OSTicksToCalendarTime(
                OSGetTime(), (void*) ((u8*) results + arg0 * 0x28 + 0x138));
        }
        break;
    default:
        return 1;
    }

    return 0;
}

void kar_gmautodemo__near_80010fa8(void)
{
}

void kar_gmautodemo__near_80010fac(s32 arg0, s32 arg1, u8* arg2)
{
    fn_80113F10(arg0, 0, arg2 + arg1 * 10);
}

void kar_gmautodemo__near_80010fd8(s32 arg0, void* arg1)
{
    u32* counters;

    fn_80113F10(arg0, 1, arg1);
    counters = lbl_805DD570;
    counters[arg0 + 0x34]++;
}

#define AUTODEMO_COUNTERS ((u8*) lbl_805DD570)

void kar_gmautodemo__near_80011024(HSD_GObj* gobj)
{
    GmMainWork* work;
    AutodemoPlayerResults* results;
    AutodemoPlayerResults* speed_results;
    u8* resource;
    u8* race_work;
    s32 i;
    s32 j;
    s32 finished_count;
    s32 special_count;
    f32 speed_scale;
    f32 frame_scale;
    f32 speed_divisor;

    (void) gobj;

    work = kar_gmmain__near_80006c14();
    resource = *(u8**) lbl_805DD574;
    results = (AutodemoPlayerResults*) ((u8*) work + 0x830);
    race_work = (u8*) work + 0x5AC;
    finished_count = 0;
    special_count = 0;
    (*(s32*) AUTODEMO_COUNTERS)++;

    kar_gmmain__near_80006c14();
    if (*(s32*) (AUTODEMO_COUNTERS + 8) > 0) {
        (*(s32*) (AUTODEMO_COUNTERS + 8))--;
        if (*(s32*) (AUTODEMO_COUNTERS + 8) == 0) {
            kar_lbaudio__near_8005fca0(0xFF, 1);
        } else if (*(s32*) (AUTODEMO_COUNTERS + 8) == 0x78) {
            kar_lbaudio__near_8005fca0(0xFF, 0x78);
        }
    }

    speed_results = (AutodemoPlayerResults*) kar_gmmain__near_80006c14();
    speed_scale = LOAD_F32(lbl_805DE794);
    speed_results = (AutodemoPlayerResults*) ((u8*) speed_results + 0x830);
    frame_scale = LOAD_F32(lbl_805DE790);
    i = 0;
    speed_divisor = LOAD_F32(lbl_805DE798);
    for (; i < 5; i++) {
        if (kar_plclearcheckerlib__near_8022c858(i) != 4) {
            Vec pos;
            f32 value;

            kar_plclearchecker_end_object_action(i, &pos);
            value = speed_scale * PSVECMag(&pos);
            value = frame_scale * value;
            value = frame_scale * value;
            value = frame_scale * value;
            speed_results->field_074[i] = value / speed_divisor;
        }
    }

    kar_gmautodemo__near_8000ff78();
    kar_gmclearchecker__near_8004a7f0();

    switch (results->state) {
    case 1:
        results->state = 2;
        kar_gmautodemo__near_8000fe34();
        if (kar_grdata__near_800ceaf4() != 0) {
            results->field_014 = LOAD_F32(lbl_805DE794) *
                                  kar_grlib2__near_800d51fc() /
                                  LOAD_F32(lbl_805DE7B0);
        } else {
            results->field_014 = LOAD_F32(lbl_805DE7A8);
        }
        break;
    case 2:
        if (kar_gmracenormal__8000af5c() != 0) {
            *(s32*) AUTODEMO_COUNTERS = 0;
            results->state = 3;
            kar_greventlighthouse_hide_all_round_ui_components();
        } else if ((s8) fn_8000AD48() == 1 &&
                   (s8) kar_gmracenormal__8000ae08() >= 1 &&
                   *(u32*) AUTODEMO_COUNTERS >= 0x14) {
            *(s32*) AUTODEMO_COUNTERS = 0;
            results->state = 3;
            kar_greventlighthouse_hide_all_round_ui_components();
            if ((s8) ((u8*) work)[0xA94] == 9 ||
                (s8) ((u8*) work)[0xA94] == 0xB) {
                fn_801138D4(race_work[3]);
            }
        } else if (*(u32*) AUTODEMO_COUNTERS >= *(u32*) resource) {
            for (i = 0; i < 4; i++) {
                if (fn_800098C0(i) != 0) {
                    if ((s8) fn_8000AD48() != 0) {
                        fn_80113BE0(i);
                    } else {
                        kar_greventlighthouse_create_ifround_panel0_for_player_if_active(i);
                    }
                }
            }

            if ((s8) ((u8*) work)[0xA94] == 9 ||
                (s8) ((u8*) work)[0xA94] == 0xB) {
                fn_801138D4(race_work[3]);
            }
            kar_greventlighthouse_hide_all_round_ui_components();
            *(s32*) AUTODEMO_COUNTERS = 0;
            results->state = 3;
        }
        break;
    case 3:
        kar_gmracenormal__near_8001530c();
        if (kar_gmracenormal__8000af5c() != 0) {
            results->state = 0;
            kar_plclearcheckerlib__near_8022ce28();
            fn_80131804();
        } else if ((s8) fn_8000AD48() == 1 &&
                   (s8) kar_gmracenormal__8000ae08() >= 1) {
            if (*(u32*) AUTODEMO_COUNTERS >= 0x28) {
                *(s32*) AUTODEMO_COUNTERS = 0;
                results->state = 0;
                kar_plclearcheckerlib__near_8022ce28();
                fn_80131804();
                kar_lbaudio__near_8006176c(0x20012);
            }
        } else {
            {
                u32 counter = *(u32*) AUTODEMO_COUNTERS;
                f32 speed = *(f32*) (resource + 4);

                if (counter == (s32) (LOAD_F32(lbl_805DE7D4) / speed) ||
                    counter == (s32) (LOAD_F32(lbl_805DE7D8) / speed) ||
                    counter == (s32) (LOAD_F32(lbl_805DE7DC) / speed)) {
                    if ((s8) fn_8000AD48() != 0) {
                        kar_lbaudio__near_8006176c(0x20011);
                    } else {
                        kar_lbaudio__near_8006176c(0x20013);
                    }
                }
            }

            if ((f32) *(u32*) AUTODEMO_COUNTERS >=
                LOAD_F32(lbl_805DE7E0) / *(f32*) (resource + 4)) {
                results->state = 0;
                kar_plclearcheckerlib__near_8022ce28();
                fn_80131804();
                if ((s8) ((u8*) work)[0xA94] == 0xD ||
                    (s8) ((u8*) work)[0xA94] == 0xE) {
                    kar_lbaudio__near_8006176c(0x20010);
                } else if ((s8) fn_8000AD48() != 0) {
                    kar_lbaudio__near_8006176c(0x20012);
                } else {
                    kar_lbaudio__near_8006176c(0x20014);
                }
            }
        }
        break;
    case 0:
        {
            GmMainWork* timer_work = kar_gmmain__near_80006c14();
            AutodemoPlayerResults* timer_results =
                (AutodemoPlayerResults*) ((u8*) timer_work + 0x830);

            timer_results->field_003++;
            if (timer_results->field_003 >= 0x3C) {
                timer_results->field_004++;
                timer_results->field_003 -= 0x3C;
            }
        }
        if (results->field_003 == 2 && results->field_004 == 0) {
            fn_801138F4();
        }
        kar_plclearcheckerlib__near_8022df1c();
        switch ((s8) ((u8*) work)[0xA94]) {
        case 0:
        case 4:
        case 7:
        case 0xF:
            kar_gmautodemo__near_80010478();
            for (i = 0; i < 5; i++) {
                if (kar_plclearcheckerlib__near_8022c858(i) != 4) {
                    s32 is_done;

                    work = kar_gmmain__near_80006c14();
                    results = (AutodemoPlayerResults*) ((u8*) work + 0x830);
                    if (results->field_200[i] != 0) {
                        is_done = 1;
                    } else if (results->field_022[i] != 0) {
                        is_done = 0;
                    } else if (kar_plclearcheckerlib__near_8022d434(i) != 0 ||
                               results->field_027[i] != 0) {
                        s32 finished = 0;

                        for (j = 0; j < 4; j++) {
                            if (results->field_200[j] != 0) {
                                finished++;
                            }
                        }
                        results->field_018[i] =
                            (*(u16*) (AUTODEMO_COUNTERS + 0xE) - finished) - 1;
                        if (fn_80009A30(i) != -1) {
                            fn_80113B28(i);
                        }
                        results->field_200[i] = 1;
                        is_done = 1;
                    } else {
                        is_done = 0;
                    }

                    if (is_done != 0) {
                        finished_count++;
                    } else if (kar_gmautodemo__near_80010bbc(i) != 0) {
                        finished_count++;
                    }
                    if ((s8) ((u8*) work)[0xA94] == 0 &&
                        ((((u8*) work)[0xAA5] >> 4) & 1) &&
                        results->field_200[i] != 0) {
                        special_count++;
                    }
                }
            }
            work = kar_gmmain__near_80006c14();
            results = (AutodemoPlayerResults*) ((u8*) work + 0x830);
            for (i = 0; i < 5; i++) {
                if (kar_plclearcheckerlib__near_8022c858(i) != 4 &&
                    results->field_200[i] == 0) {
                    results->field_018[i] = 0;
                    for (j = 0; j < 5; j++) {
                        if (i != j &&
                            kar_plclearcheckerlib__near_8022c858(j) != 4 &&
                            results->field_200[j] == 0) {
                            if (results->field_022[i] != 0) {
                                if (results->field_022[j] != 0 &&
                                    results->field_088[i] >
                                        results->field_088[j]) {
                                    results->field_018[i]++;
                                }
                            } else if (results->field_022[j] != 0) {
                                results->field_018[i]++;
                            } else if ((s32) (results->field_21C[i] /
                                             lbl_805DE7AC) <
                                       (s32) (results->field_21C[j] /
                                              lbl_805DE7AC)) {
                                results->field_018[i]++;
                            }
                        }
                    }
                }
            }
            kar_gmracenormal__near_8001544c();
            kar_gmracenormal__near_800159ac();
            if ((s8) kar_gmracenormal__8003d5f0() == 2) {
                kar_pltrick__near_80232c14();
            }
            break;
        case 3:
            kar_gmautodemo__near_80010478();
            for (i = 0; i < 5; i++) {
                if (kar_plclearcheckerlib__near_8022c858(i) != 4) {
                    s32 is_done;

                    work = kar_gmmain__near_80006c14();
                    results = (AutodemoPlayerResults*) ((u8*) work + 0x830);
                    if (results->field_200[i] != 0) {
                        is_done = 1;
                    } else if (results->field_022[i] != 0) {
                        is_done = 0;
                    } else if (kar_plclearcheckerlib__near_8022d434(i) != 0 ||
                               results->field_027[i] != 0) {
                        s32 finished = 0;

                        for (j = 0; j < 4; j++) {
                            if (results->field_200[j] != 0) {
                                finished++;
                            }
                        }
                        results->field_018[i] =
                            (*(u16*) (AUTODEMO_COUNTERS + 0xE) - finished) - 1;
                        if (fn_80009A30(i) != -1) {
                            fn_80113B28(i);
                        }
                        results->field_200[i] = 1;
                        is_done = 1;
                    } else {
                        is_done = 0;
                    }

                    if (is_done != 0) {
                        finished_count++;
                    }
                }
            }
            work = kar_gmmain__near_80006c14();
            results = (AutodemoPlayerResults*) ((u8*) work + 0x830);
            for (i = 0; i < 5; i++) {
                if (kar_plclearcheckerlib__near_8022c858(i) != 4 &&
                    results->field_200[i] == 0) {
                    results->field_018[i] = 0;
                    for (j = 0; j < 5; j++) {
                        if (i != j &&
                            kar_plclearcheckerlib__near_8022c858(j) != 4 &&
                            results->field_200[j] == 0) {
                            if (results->field_022[i] != 0) {
                                if (results->field_022[j] != 0 &&
                                    results->field_088[i] >
                                        results->field_088[j]) {
                                    results->field_018[i]++;
                                }
                            } else if (results->field_022[j] != 0) {
                                results->field_018[i]++;
                            } else if ((s32) (results->field_21C[i] /
                                             lbl_805DE7AC) <
                                       (s32) (results->field_21C[j] /
                                              lbl_805DE7AC)) {
                                results->field_018[i]++;
                            }
                        }
                    }
                }
            }
            kar_pltrick__near_80232c14();
            break;
        case 1:
            kar_gmautodemo__near_80010478();
            for (i = 0; i < 5; i++) {
                if (kar_plclearcheckerlib__near_8022c858(i) != 4) {
                    s32 is_done;

                    work = kar_gmmain__near_80006c14();
                    results = (AutodemoPlayerResults*) ((u8*) work + 0x830);
                    if (results->field_200[i] != 0) {
                        is_done = 1;
                    } else if (results->field_022[i] != 0) {
                        is_done = 0;
                    } else if (kar_plclearcheckerlib__near_8022d434(i) != 0 ||
                               results->field_027[i] != 0) {
                        s32 finished = 0;

                        for (j = 0; j < 4; j++) {
                            if (results->field_200[j] != 0) {
                                finished++;
                            }
                        }
                        results->field_018[i] =
                            (*(u16*) (AUTODEMO_COUNTERS + 0xE) - finished) - 1;
                        if (fn_80009A30(i) != -1) {
                            fn_80113B28(i);
                        }
                        results->field_200[i] = 1;
                        is_done = 1;
                    } else {
                        work = kar_gmmain__near_80006c14();
                        results =
                            (AutodemoPlayerResults*) ((u8*) work + 0x830);
                        if ((u32) results->field_004 >=
                            (u32) *(s16*) ((u8*) work + 0xA9C)) {
                            kar_lbaudio__near_8006176c(0x130003);
                            fn_80279F68();
                            if (fn_80009A30(i) != -1) {
                                fn_80114178(i);
                            }
                            OSTicksToCalendarTime(
                                OSGetTime(),
                                (void*) ((u8*) results + i * 0x28 + 0x138));
                            is_done = 1;
                        } else {
                            is_done = 0;
                        }
                    }

                    if (is_done != 0) {
                        finished_count++;
                    } else if (kar_plclearcheckerlib__near_8022c858(i) == 1) {
                        finished_count++;
                    }
                    if ((((u8*) work)[0xAA5] >> 4) & 1 &&
                        results->field_200[i] != 0) {
                        special_count++;
                    }
                }
            }
            work = kar_gmmain__near_80006c14();
            results = (AutodemoPlayerResults*) ((u8*) work + 0x830);
            for (i = 0; i < 5; i++) {
                if (kar_plclearcheckerlib__near_8022c858(i) != 4 &&
                    results->field_200[i] == 0) {
                    results->field_018[i] = 0;
                    for (j = 0; j < 5; j++) {
                        if (i != j &&
                            kar_plclearcheckerlib__near_8022c858(j) != 4 &&
                            results->field_200[j] == 0) {
                            if (results->field_022[i] != 0) {
                                if (results->field_022[j] != 0 &&
                                    results->field_088[i] >
                                        results->field_088[j]) {
                                    results->field_018[i]++;
                                }
                            } else if (results->field_022[j] != 0) {
                                results->field_018[i]++;
                            } else if ((s32) (results->field_21C[i] /
                                             lbl_805DE7AC) <
                                       (s32) (results->field_21C[j] /
                                              lbl_805DE7AC)) {
                                results->field_018[i]++;
                            }
                        }
                    }
                }
            }
            kar_gmracenormal__near_8001544c();
            kar_gmracenormal__near_800159ac();
            break;
        case 0xD:
            kar_gmclearchecker__near_8004f03c();
            for (i = 0; i < 5; i++) {
                if (kar_plclearcheckerlib__near_8022c858(i) != 4) {
                    s32 is_done;

                    work = kar_gmmain__near_80006c14();
                    results = (AutodemoPlayerResults*) ((u8*) work + 0x830);
                    if (results->field_200[i] != 0) {
                        is_done = 1;
                    } else if (results->field_022[i] != 0) {
                        is_done = 0;
                    } else if (kar_plclearcheckerlib__near_8022d434(i) != 0 ||
                               results->field_027[i] != 0) {
                        s32 finished = 0;

                        for (j = 0; j < 4; j++) {
                            if (results->field_200[j] != 0) {
                                finished++;
                            }
                        }
                        results->field_018[i] =
                            (*(u16*) (AUTODEMO_COUNTERS + 0xE) - finished) - 1;
                        if (fn_80009A30(i) != -1) {
                            fn_80113B28(i);
                        }
                        results->field_200[i] = 1;
                        is_done = 1;
                    } else {
                        work = kar_gmmain__near_80006c14();
                        results =
                            (AutodemoPlayerResults*) ((u8*) work + 0x830);
                        if ((u32) results->field_004 >=
                            (u32) *(s16*) ((u8*) work + 0xA9C)) {
                            kar_lbaudio__near_8006176c(0x130003);
                            fn_80279F68();
                            if (fn_80009A30(i) != -1) {
                                fn_80114178(i);
                            }
                            OSTicksToCalendarTime(
                                OSGetTime(),
                                (void*) ((u8*) results + i * 0x28 + 0x138));
                            is_done = 1;
                        } else {
                            is_done = 0;
                        }
                    }

                    if (is_done != 0) {
                        finished_count++;
                    } else {
                        results->field_208[i] =
                            *(s32*) (AUTODEMO_COUNTERS + 0xD0 + i * 4);
                    }
                }
            }
            work = kar_gmmain__near_80006c14();
            results = (AutodemoPlayerResults*) ((u8*) work + 0x830);
            for (i = 0; i < 5; i++) {
                if (kar_plclearcheckerlib__near_8022c858(i) != 4 &&
                    results->field_200[i] == 0) {
                    results->field_018[i] = 0;
                    for (j = 0; j < 5; j++) {
                        if (i != j &&
                            kar_plclearcheckerlib__near_8022c858(j) != 4 &&
                            results->field_200[j] == 0 &&
                            results->field_208[i] < results->field_208[j]) {
                            results->field_018[i]++;
                        }
                    }
                }
            }
            break;
        case 5:
            if (fn_8000A0F8() == 0x708) {
                kar_lbaudio__near_80061bfc();
                if (kar_greventgenerator_get_active_event_kind() == -1) {
                    kar_lbaudio__near_8006176c(0x2000C);
                }
            }
            kar_gmclearchecker__near_8004e5b8();
            for (i = 0; i < 5; i++) {
                if (kar_plclearcheckerlib__near_8022c858(i) != 4) {
                    s32 is_done;

                    work = kar_gmmain__near_80006c14();
                    results = (AutodemoPlayerResults*) ((u8*) work + 0x830);
                    if ((u32) results->field_004 >=
                        (u32) *(s16*) ((u8*) work + 0xA9C)) {
                        kar_lbaudio__near_8006176c(0x130003);
                        fn_80279F68();
                        if (fn_80009A30(i) != -1) {
                            fn_80114178(i);
                        }
                        OSTicksToCalendarTime(
                            OSGetTime(),
                            (void*) ((u8*) results + i * 0x28 + 0x138));
                        is_done = 1;
                    } else {
                        is_done = 0;
                    }

                    if (is_done != 0) {
                        finished_count++;
                        kar_plclearchecker_update_secondary_flags(i);
                    }
                }
            }
            kar_gmracenormal__near_80015a00();
            break;
        case 6:
            kar_gmclearchecker__near_8004e660();
            break;
        case 8:
            for (i = 0; i < 5; i++) {
                if (kar_plclearcheckerlib__near_8022c858(i) != 4) {
                    s32 is_done;

                    work = kar_gmmain__near_80006c14();
                    results = (AutodemoPlayerResults*) ((u8*) work + 0x830);
                    if (results->field_200[i] != 0) {
                        is_done = 1;
                    } else if (results->field_022[i] != 0) {
                        is_done = 0;
                    } else if (kar_plclearcheckerlib__near_8022d434(i) != 0 ||
                               results->field_027[i] != 0) {
                        s32 finished = 0;

                        for (j = 0; j < 4; j++) {
                            if (results->field_200[j] != 0) {
                                finished++;
                            }
                        }
                        results->field_018[i] =
                            (*(u16*) (AUTODEMO_COUNTERS + 0xE) - finished) - 1;
                        if (fn_80009A30(i) != -1) {
                            fn_80113B28(i);
                        }
                        results->field_200[i] = 1;
                        is_done = 1;
                    } else {
                        is_done = 0;
                    }

                    if (is_done != 0) {
                        finished_count++;
                    } else if (kar_gmautodemo__near_80010dac(i) != 0) {
                        finished_count++;
                    }
                }
            }
            break;
        case 0xB:
            for (i = 0; i < 5; i++) {
                if (kar_plclearcheckerlib__near_8022c858(i) != 4) {
                    s32 is_done;

                    work = kar_gmmain__near_80006c14();
                    results = (AutodemoPlayerResults*) ((u8*) work + 0x830);
                    if (results->field_200[i] != 0) {
                        is_done = 1;
                    } else if (results->field_022[i] != 0) {
                        is_done = 0;
                    } else if (kar_plclearcheckerlib__near_8022d434(i) != 0 ||
                               results->field_027[i] != 0) {
                        s32 finished = 0;

                        for (j = 0; j < 4; j++) {
                            if (results->field_200[j] != 0) {
                                finished++;
                            }
                        }
                        results->field_018[i] =
                            (*(u16*) (AUTODEMO_COUNTERS + 0xE) - finished) - 1;
                        if (fn_80009A30(i) != -1) {
                            fn_80113B28(i);
                        }
                        results->field_200[i] = 1;
                        is_done = 1;
                    } else {
                        is_done = 0;
                    }

                    if (is_done != 0) {
                        finished_count++;
                    } else {
                        Vec pos;
                        s32 did_finish;

                        work = kar_gmmain__near_80006c14();
                        results =
                            (AutodemoPlayerResults*) ((u8*) work + 0x830);
                        kar_plclearchecker_get_template_vec_008(i, &pos);
                        switch ((s8) AUTODEMO_COUNTERS[i + 0x15]) {
                        case 0:
                            if (pos.x >= LOAD_F32(lbl_805DE7CC)) {
                                AUTODEMO_COUNTERS[i + 0x15] = 1;
                                fn_80113C38(i);
                            }
                            did_finish = 0;
                            break;
                        case 1:
                            if (results->field_21C[i] <
                                LOAD_F32(lbl_805DE7D0) + pos.y) {
                                results->field_21C[i] =
                                    LOAD_F32(lbl_805DE7D0) + pos.y;
                            }
                            if (kar_plclearcheckerlib__near_8022d49c(i) != 0) {
                                results->field_022[i] = 1;
                                AUTODEMO_COUNTERS[i + 0x15] = 2;
                                fn_80113D00(i);
                                OSTicksToCalendarTime(
                                    OSGetTime(),
                                    (void*) ((u8*) results + i * 0x28 +
                                             0x138));
                            }
                            did_finish = 0;
                            break;
                        default:
                            did_finish = 1;
                            break;
                        }
                        if (did_finish != 0) {
                            finished_count++;
                        }
                    }
                }
            }
            break;
        case 9:
            for (i = 0; i < 5; i++) {
                if (kar_plclearcheckerlib__near_8022c858(i) != 4) {
                    s32 is_done;

                    work = kar_gmmain__near_80006c14();
                    results = (AutodemoPlayerResults*) ((u8*) work + 0x830);
                    if (results->field_200[i] != 0) {
                        is_done = 1;
                    } else if (results->field_022[i] != 0) {
                        is_done = 0;
                    } else if (kar_plclearcheckerlib__near_8022d434(i) != 0 ||
                               results->field_027[i] != 0) {
                        s32 finished = 0;

                        for (j = 0; j < 4; j++) {
                            if (results->field_200[j] != 0) {
                                finished++;
                            }
                        }
                        results->field_018[i] =
                            (*(u16*) (AUTODEMO_COUNTERS + 0xE) - finished) - 1;
                        if (fn_80009A30(i) != -1) {
                            fn_80113B28(i);
                        }
                        results->field_200[i] = 1;
                        is_done = 1;
                    } else {
                        is_done = 0;
                    }

                    if (is_done != 0) {
                        finished_count++;
                    } else if ((s8) AUTODEMO_COUNTERS[i + 0x15] != 0) {
                        finished_count++;
                    } else if (kar_plclearcheckerlib__near_8022d49c(i) != 0) {
                        results->field_022[i] = 1;
                        AUTODEMO_COUNTERS[i + 0x15] = 1;
                        results->field_208[i] =
                            kar_plclearcheckerlib__near_8022d528(i);
                        fn_80113CA8(i);
                        OSTicksToCalendarTime(
                            OSGetTime(),
                            (void*) ((u8*) results + i * 0x28 + 0x138));
                    }
                }
            }
            break;
        case 0xE:
            kar_gmclearchecker__near_8004f03c();
            for (i = 0; i < 5; i++) {
                if (kar_plclearcheckerlib__near_8022c858(i) != 4) {
                    s32 is_done;

                    work = kar_gmmain__near_80006c14();
                    results = (AutodemoPlayerResults*) ((u8*) work + 0x830);
                    if ((u32) results->field_004 >=
                        (u32) *(s16*) ((u8*) work + 0xA9C)) {
                        kar_lbaudio__near_8006176c(0x130003);
                        fn_80279F68();
                        if (fn_80009A30(i) != -1) {
                            fn_80114178(i);
                        }
                        OSTicksToCalendarTime(
                            OSGetTime(),
                            (void*) ((u8*) results + i * 0x28 + 0x138));
                        is_done = 1;
                    } else {
                        is_done = 0;
                    }

                    if (is_done != 0) {
                        finished_count++;
                    } else {
                        results->field_208[i] =
                            kar_plclearcheckerlib__8022f2a0(i);
                    }
                }
            }

            work = kar_gmmain__near_80006c14();
            results = (AutodemoPlayerResults*) ((u8*) work + 0x830);
            for (i = 0; i < 5; i++) {
                if (kar_plclearcheckerlib__near_8022c858(i) != 4 &&
                    results->field_200[i] == 0) {
                    results->field_018[i] = 0;
                    for (j = 0; j < 5; j++) {
                        if (i != j &&
                            kar_plclearcheckerlib__near_8022c858(j) != 4 &&
                            results->field_200[j] == 0 &&
                            results->field_208[i] < results->field_208[j]) {
                            results->field_018[i]++;
                        }
                    }
                }
            }
            break;
        case 0x12:
            for (i = 0; i < 4; i++) {
                if (kar_plclearcheckerlib__near_8022c858(i) != 4) {
                    s32 is_done;

                    work = kar_gmmain__near_80006c14();
                    results = (AutodemoPlayerResults*) ((u8*) work + 0x830);
                    if ((u32) results->field_004 >=
                        (u32) *(s16*) ((u8*) work + 0xA9C)) {
                        kar_lbaudio__near_8006176c(0x130003);
                        fn_80279F68();
                        if (fn_80009A30(i) != -1) {
                            fn_80114178(i);
                        }
                        OSTicksToCalendarTime(
                            OSGetTime(),
                            (void*) ((u8*) results + i * 0x28 + 0x138));
                        is_done = 1;
                    } else {
                        is_done = 0;
                    }

                    if (is_done != 0) {
                        finished_count++;
                    } else if (results->field_200[i] != 0) {
                        finished_count++;
                    } else {
                        if (kar_plclearcheckerlib__near_8022c858(i) == 1) {
                            finished_count++;
                        }
                        if (kar_plclearcheckerlib__near_8022d684(i) != 0) {
                            s32 finished = 0;

                            if (results->field_200[0] != 0) {
                                finished = 1;
                            }
                            if (results->field_200[1] != 0) {
                                finished++;
                            }
                            if (results->field_200[2] != 0) {
                                finished++;
                            }
                            if (results->field_200[3] != 0) {
                                finished++;
                            }
                            results->field_018[i] =
                                ((u8*) work)[0xA95] - finished - 1;
                            if (results->field_200[i] == 0) {
                                if (fn_80009A30(i) != -1) {
                                    fn_80113B28(i);
                                }
                            }
                            results->field_200[i] = 1;
                        }
                    }
                }
            }

            if (kar_plclearcheckerlib__near_8022d684(4) != 0) {
                for (i = 0; i < 4; i++) {
                    if (results->field_200[i] == 0) {
                        results->field_018[i] = 0;
                        results->field_022[i] = 1;
                        results->field_088[i] =
                            results->field_003 + results->field_004 * 0x3C;
                        OSTicksToCalendarTime(
                            OSGetTime(),
                            (void*) ((u8*) results + i * 0x28 + 0x138));
                    }
                }
                finished_count = *(u16*) (AUTODEMO_COUNTERS + 0xE);
                kar_cpmapdata_request_map_audio_event(1, 0);
                kar_cpmapdata_request_map_audio_event(6, 0);
            } else if (finished_count >= (s8) ((u8*) work)[0xA95]) {
                finished_count = *(u16*) (AUTODEMO_COUNTERS + 0xE);
                if (results->field_022[0] == 0) {
                    results->field_200[0] = 1;
                }
                if (results->field_022[1] == 0) {
                    results->field_200[1] = 1;
                }
                if (results->field_022[2] == 0) {
                    results->field_200[2] = 1;
                }
                if (results->field_022[3] == 0) {
                    results->field_200[3] = 1;
                }
            }
            fn_80040B80();
            break;
        }
        if ((s8) kar_gmracenormal__8000af5c() == 0) {
            if (special_count != 0 &&
                special_count == (*(u16*) (AUTODEMO_COUNTERS + 0xE) - 1)) {
                finished_count = *(u16*) (AUTODEMO_COUNTERS + 0xE);
                if (results->field_200[0] == 0) {
                    results->field_088[0] =
                        results->field_003 + results->field_004 * 0x3C;
                }
                if (results->field_200[1] == 0) {
                    results->field_088[1] =
                        results->field_003 + results->field_004 * 0x3C;
                }
                if (results->field_200[2] == 0) {
                    results->field_088[2] =
                        results->field_003 + results->field_004 * 0x3C;
                }
                if (results->field_200[3] == 0) {
                    results->field_088[3] =
                        results->field_003 + results->field_004 * 0x3C;
                }
            }

            if (finished_count >= *(u16*) (AUTODEMO_COUNTERS + 0xE) &&
                fn_8000AA08() == 0) {
                *(u32*) (AUTODEMO_COUNTERS + 4) = *(u32*) AUTODEMO_COUNTERS;
                switch ((s8) ((u8*) work)[0xA94]) {
                case 0:
                case 7:
                case 0xF:
                    results->state = 4;
                    kar_lbaudio__near_8006176c(0x2000F);
                    break;
                case 1:
                case 0xD:
                case 0x12:
                    if ((u32) results->field_004 <
                        (u32) *(s16*) ((u8*) work + 0xA9C)) {
                        results->state = 4;
                        kar_lbaudio__near_8006176c(0x2000F);
                        kar_lbkdcoll__near_80071d7c();
                    } else {
                        results->state = 4;
                        kar_gmmain__near_80005d78(3);
                        fn_80114234();
                        kar_lbaudio__near_80061acc();
                        kar_lbkdcoll__near_80071d7c();
                    }
                    break;
                case 4:
                    results->state = 5;
                    kar_lbkdcoll__near_80071d7c();
                    break;
                case 5:
                case 0xE:
                    results->state = 4;
                    kar_gmmain__near_80005d78(3);
                    fn_80114234();
                    kar_lbaudio__near_80061acc();
                    kar_lbkdcoll__near_80071d7c();
                    break;
                default:
                    results->state = 4;
                    break;
                }
                kar_gmclearchecker__near_8004e810();
                for (i = 0; i < 5; i++) {
                    if (kar_plclearcheckerlib__near_8022c858(i) != 4) {
                        if ((s8) ((u8*) work)[0xA94] == 9) {
                            *(s32*) (race_work + i * 8 + 0xC) =
                                *(s32*) (race_work + i * 8 + 8);
                            *(s32*) (race_work + i * 8 + 8) =
                                results->field_208[i];
                        }

                        if ((s8) ((u8*) work)[0xA94] == 0xB) {
                            s32 copy0;
                            s32 copy1;

                            if (results->field_200[i] != 0) {
                                results->field_21C[i] =
                                    LOAD_F32(lbl_805DE7A8);
                            }
                            *(f32*) (race_work + i * 8 + 0x34) =
                                *(f32*) (race_work + i * 8 + 0x30);
                            copy0 = *(s32*) (race_work + i * 0x50 + 0x88);
                            copy1 = *(s32*) (race_work + i * 0x50 + 0x8C);
                            *(s32*) (race_work + i * 0x50 + 0xB0) = copy0;
                            *(s32*) (race_work + i * 0x50 + 0xB4) = copy1;
                            copy0 = *(s32*) (race_work + i * 0x50 + 0x90);
                            copy1 = *(s32*) (race_work + i * 0x50 + 0x94);
                            *(s32*) (race_work + i * 0x50 + 0xB8) = copy0;
                            *(s32*) (race_work + i * 0x50 + 0xBC) = copy1;
                            copy0 = *(s32*) (race_work + i * 0x50 + 0x98);
                            copy1 = *(s32*) (race_work + i * 0x50 + 0x9C);
                            *(s32*) (race_work + i * 0x50 + 0xC0) = copy0;
                            *(s32*) (race_work + i * 0x50 + 0xC4) = copy1;
                            copy0 = *(s32*) (race_work + i * 0x50 + 0xA0);
                            copy1 = *(s32*) (race_work + i * 0x50 + 0xA4);
                            *(s32*) (race_work + i * 0x50 + 0xC8) = copy0;
                            *(s32*) (race_work + i * 0x50 + 0xCC) = copy1;
                            copy0 = *(s32*) (race_work + i * 0x50 + 0xA8);
                            copy1 = *(s32*) (race_work + i * 0x50 + 0xAC);
                            *(s32*) (race_work + i * 0x50 + 0xD0) = copy0;
                            *(s32*) (race_work + i * 0x50 + 0xD4) = copy1;
                            *(f32*) (race_work + i * 8 + 0x30) =
                                results->field_21C[i];
                            copy0 = *(s32*) ((u8*) results + i * 0x28 + 0x138);
                            copy1 = *(s32*) ((u8*) results + i * 0x28 + 0x13C);
                            *(s32*) (race_work + i * 0x50 + 0x88) = copy0;
                            *(s32*) (race_work + i * 0x50 + 0x8C) = copy1;
                            copy0 = *(s32*) ((u8*) results + i * 0x28 + 0x140);
                            copy1 = *(s32*) ((u8*) results + i * 0x28 + 0x144);
                            *(s32*) (race_work + i * 0x50 + 0x90) = copy0;
                            *(s32*) (race_work + i * 0x50 + 0x94) = copy1;
                            copy0 = *(s32*) ((u8*) results + i * 0x28 + 0x148);
                            copy1 = *(s32*) ((u8*) results + i * 0x28 + 0x14C);
                            *(s32*) (race_work + i * 0x50 + 0x98) = copy0;
                            *(s32*) (race_work + i * 0x50 + 0x9C) = copy1;
                            copy0 = *(s32*) ((u8*) results + i * 0x28 + 0x150);
                            copy1 = *(s32*) ((u8*) results + i * 0x28 + 0x154);
                            *(s32*) (race_work + i * 0x50 + 0xA0) = copy0;
                            *(s32*) (race_work + i * 0x50 + 0xA4) = copy1;
                            copy0 = *(s32*) ((u8*) results + i * 0x28 + 0x158);
                            copy1 = *(s32*) ((u8*) results + i * 0x28 + 0x15C);
                            *(s32*) (race_work + i * 0x50 + 0xA8) = copy0;
                            *(s32*) (race_work + i * 0x50 + 0xAC) = copy1;
                        }
                    }

                    if (kar_plclearcheckerlib__near_8022c858(i) == 0 &&
                        (s8) ((u8*) work)[0xA94] == 4) {
                        s32* script_ids = (s32*) ((u8*) work + 0xBB8);
                        u8* script_data = (u8*) work + 0xAC8;

                        kar_cpcmdscript_init_current_replay_cpu_work_mode8(i);
                        kar_plclearcheckerlib__near_8022cc10(i, 0);
                        kar_gmracenormal__8022c86c(i, 1);
                        for (j = 0; j < 4; j++) {
                            s32 script_id =
                                (s8) *(u8*) ((u8*) script_ids + j * 3);
                            if (script_id != -1) {
                                fn_800B989C(
                                    1, script_id,
                                    (s8) script_data[script_id * 0x30 + 6], 0);
                            }
                        }
                    }
                }
            }
        }
        break;
    case 4:
        switch ((s8) ((u8*) work)[0xA94]) {
        case 0:
        case 7:
        case 0xF:
            work = kar_gmmain__near_80006c14();
            results = (AutodemoPlayerResults*) ((u8*) work + 0x830);
            results->field_003++;
            if (results->field_003 >= 0x3C) {
                results->field_004++;
                results->field_003 -= 0x3C;
            }
            kar_gmautodemo__near_80010478();
            for (i = 0; i < 5; i++) {
                if (kar_plclearcheckerlib__near_8022c858(i) == 1) {
                    s32 is_done;

                    work = kar_gmmain__near_80006c14();
                    results = (AutodemoPlayerResults*) ((u8*) work + 0x830);
                    if (results->field_200[i] != 0) {
                        is_done = 1;
                    } else if (results->field_022[i] != 0) {
                        is_done = 0;
                    } else if (kar_plclearcheckerlib__near_8022d434(i) != 0 ||
                               results->field_027[i] != 0) {
                        s32 finished = 0;

                        if (results->field_200[0] != 0) {
                            finished = 1;
                        }
                        if (results->field_200[1] != 0) {
                            finished++;
                        }
                        if (results->field_200[2] != 0) {
                            finished++;
                        }
                        if (results->field_200[3] != 0) {
                            finished++;
                        }
                        results->field_018[i] =
                            (*(u16*) (AUTODEMO_COUNTERS + 0xE) - finished) - 1;
                        if (fn_80009A30(i) != -1) {
                            fn_80113B28(i);
                        }
                        results->field_200[i] = 1;
                        is_done = 1;
                    } else {
                        is_done = 0;
                    }

                    if (is_done == 0) {
                        kar_gmautodemo__near_80010bbc(i);
                    }
                }
            }
            break;
        }

        if (*(u32*) AUTODEMO_COUNTERS == *(u32*) (AUTODEMO_COUNTERS + 4) +
                                  *(u32*) (resource + 8)) {
            s32 fade_time = *(s32*) (resource + 0xC);

            work = kar_gmmain__near_80006c14();
            if (*(s16*) (AUTODEMO_COUNTERS + 0xC) == 0 &&
                kar_lbfade_is_finished(1) != 0) {
                kar_lbfade_start_preset1_forward(1, fade_time - 1);
                *(s16*) (AUTODEMO_COUNTERS + 0xC) = fade_time;
            }
        }

        if (*(u32*) AUTODEMO_COUNTERS == *(u32*) (AUTODEMO_COUNTERS + 4) + 0x3C) {
            switch ((s8) ((u8*) work)[0xA94]) {
            case 1:
            case 5:
            case 0xD:
            case 0xE:
            case 0x12:
                kar_cpmapdata_request_map_audio_event(6, 0);
                break;
            }
        }

        work = kar_gmmain__near_80006c14();
        if (*(s16*) (AUTODEMO_COUNTERS + 0xC) > 0) {
            (*(s16*) (AUTODEMO_COUNTERS + 0xC))--;
            if (*(s16*) (AUTODEMO_COUNTERS + 0xC) == 0) {
                *(s16*) (AUTODEMO_COUNTERS + 0xC) = -1;
                results->state = 6;
                kar_movie_assets__8000a498(0x100);
                kar_gmmain__near_800064f0();
                kar_lbaudio__near_8005e5d0();
                kar_lbaudio__near_8005e788();
                kar_lbkdcoll__near_80071d7c();
            }
        }
        break;
    case 5:
        if (*(u32*) AUTODEMO_COUNTERS >=
            *(u32*) (AUTODEMO_COUNTERS + 4) + *(u32*) (resource + 8)) {
            s32 should_fade = 0;

            for (i = 0; i < 4; i++) {
                if ((PLAYER_INPUT(i) & 0x1360) != 0) {
                    should_fade = 1;
                }
                if (kar_plclearcheckerlib__near_8022c858(i) != 4 &&
                    kar_gmautodemo__near_800106ec(i) != 0) {
                    should_fade = 1;
                }
            }
            if (*(u32*) AUTODEMO_COUNTERS >= *(u32*) (AUTODEMO_COUNTERS + 4) + 0x4650) {
                should_fade = 1;
            }
            if (should_fade != 0) {
                s32 fade_time = *(s32*) (resource + 0xC);

                work = kar_gmmain__near_80006c14();
                if (*(s16*) (AUTODEMO_COUNTERS + 0xC) == 0 &&
                    kar_lbfade_is_finished(1) != 0) {
                    kar_lbfade_start_preset1_forward(1, fade_time - 1);
                    *(s16*) (AUTODEMO_COUNTERS + 0xC) = fade_time;
                }
            }
        }

        work = kar_gmmain__near_80006c14();
        if (*(s16*) (AUTODEMO_COUNTERS + 0xC) > 0) {
            (*(s16*) (AUTODEMO_COUNTERS + 0xC))--;
            if (*(s16*) (AUTODEMO_COUNTERS + 0xC) == 0) {
                *(s16*) (AUTODEMO_COUNTERS + 0xC) = -1;
                results->state = 6;
                kar_movie_assets__8000a498(0x100);
                kar_gmmain__near_800064f0();
                kar_lbaudio__near_8005e5d0();
                kar_lbaudio__near_8005e788();
                kar_lbkdcoll__near_80071d7c();
            }
        }
        break;
    case 6:
        break;
    }
}

#undef AUTODEMO_COUNTERS

void kar_gmautodemo__near_80012e64(void)
{
    fn_80040E7C();
}

char lbl_80496140[] =
    "Race User Data Free Error!\n\0gmracecommon.c\0\0grcp == gp\0";

