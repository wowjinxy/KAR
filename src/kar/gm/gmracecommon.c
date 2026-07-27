#include "functions.h"
#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>
#include <kar/gm/gmautodemo.h>
#include <kar/gm/gmclearchecker.h>
#include <kar/gm/gmdiag.h>
#include <kar/gm/gmmain.h>
#include <kar/gm/gmracenormal.h>
#include <kar/lb/lbaudio.h>
#include <kar/shadow.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/gobjuserdata.h>
#include <sysdolphin/objalloc.h>

typedef struct AutoDemoData AutoDemoData;
typedef struct RaceCommon RaceCommon;
typedef struct RaceGame RaceGame;
typedef struct RaceSlot RaceSlot;
typedef struct RacePlayerMap RacePlayerMap;
typedef struct RaceSettingWindow RaceSettingWindow;
typedef struct RaceSettings RaceSettings;
typedef struct RaceUserData RaceUserData;

struct RaceSlot {
    s8 kind;
    s8 field_1;
    s8 field_2;
    s8 field_3;
    s8 field_4;
    s8 field_5;
    s8 player_index;
    u8 pad_7;
    s8 field_8;
    s8 field_9;
    u8 pad_A[2];
    f32 params[9];
};

struct RacePlayerMap {
    s8 slot_index;
    s8 active;
    s8 mapped_index;
};

struct RaceCommon {
    u8 state;
    s8 current_slot;
    u8 enabled;
    u8 status;
    u32 flags;
    u32 timer;
    s32 current_index;
    s32 previous_index;
    f32 elapsed;
    u8 flags_18[5];
    u8 flags_1D[5];
    u8 flags_22[5];
    u8 flags_27[5];
    s8 start_positions[5];
    s8 alternate_start_positions[5];
    u8 pad_36[2];
    u32 words_38[5];
    u32 words_4C[5];
    f32 floats_60[5];
    f32 floats_74[5];
    u32 words_88[5];
    u32 words_9C[5];
    Vec vectors_B0[5];
    Vec vectors_EC[5];
    u8 triplets_128[5][3];
    u8 pad_137[0xC9];
    u8 flags_200[5];
    u8 pad_205[3];
    u32 words_208[5];
    f32 floats_21C[5];
    f32 floats_230[5];
    f32 floats_244[5];
    u32 field_258;
    u32 field_25C;
    u32 field_260;
};

struct RaceSettingWindow {
    u8 pad_00[0x0C];
    f32 params[9];
};

struct RaceSettings {
    u8 data[0xC0];
    s8 field_C0[5];
    s8 field_C5[5];
    u8 pad_CA[0x3D2];
};

struct RaceGame {
    u8 pad_000[0x354];
    u8 source_course;
    u8 pad_355;
    s16 source_mode;
    s16 source_value;
    u8 source_flags;
    u8 pad_35B;
    s8 source_disabled;
    u8 pad_35D[0x37];
    RaceSettings race_settings;
    RaceCommon race_common;
    u8 course;
    u8 player_count;
    s8 active_player_count;
    u8 pad_A97[3];
    u8 mode;
    u8 pad_A9B;
    u16 value_A9C;
    u8 pad_A9E[6];
    u8 enabled_AA4;
    u8 settings_AA5;
    u8 settings_AA6;
    u8 pad_AA7;
    f32 player_speeds[5];
    u8 pad_ABC[0x0C];
    RaceSlot slots[5];
    RacePlayerMap player_maps[4];
};

struct AutoDemoData {
    u8 pad_00[0x9C];
    f32 replay_speeds[8];
    f32 default_speed;
    f32 template_float;
};

struct RaceUserData {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u16 field_C;
    u16 active_slot_count;
    u8 bytes_10[5];
    u8 bytes_15[5];
    u8 pad_1A[0x52];
    u32 words_6C[5];
    f32 floats_80[5];
    u32 words_94[5];
    u8 pad_A8[0x14];
    u32 words_BC[5];
    u32 words_D0[5];
};

HSD_ObjAllocData lbl_80537400;

const f32 lbl_805DE7F0 = 0.5f;
const f32 lbl_805DE7F4 = 0.016666668f;
const f32 lbl_805DE7F8 = 1.5f;
const f64 lbl_805DE800 = 4503599627370496.0;
const f32 lbl_805DE808 = 0.0f;
const f32 lbl_805DE80C = -1.0f;
const f64 lbl_805DE810 = 4503601774854144.0;
const f32 lbl_805DE818 = 0.0f;
const f32 lbl_805DE81C = 4.0f;
const f64 lbl_805DE820 = 4503601774854144.0;
const f32 lbl_805DE828 = 1.0f;
const f32 lbl_805DE82C = 0.0f;
const f32 lbl_805DE830 = 1.0f;
const f32 lbl_805DE834 = -10.0f;
const f32 lbl_805DE838 = 10.0f;
const f32 lbl_805DE83C = 0.0f;
const f64 lbl_805DE840 = 255.0;
const f64 lbl_805DE848 = 0.7;
const f64 lbl_805DE850 = 0.03;
const f64 lbl_805DE858 = 0.07;
const f32 lbl_805DE860 = 99.0f;
const f32 lbl_805DE864 = 59.0f;
const f64 lbl_805DE868 = 4503601774854144.0;
const f32 lbl_805DE870 = 99.0f;
const f32 lbl_805DE874 = 59.0f;
const f64 lbl_805DE878 = 4503601774854144.0;
const f32 lbl_805DE880 = -2.0f;
const f32 lbl_805DE884 = 0.0f;
const f32 lbl_805DE888 = 0.0f;
const f64 lbl_805DE890 = 4503601774854144.0;
const f32 lbl_805DE898[2] = { 1.0f, 0.0f };
const f32 lbl_805DE8A0 = 99.0f;
const f32 lbl_805DE8A4 = 59.0f;
const f64 lbl_805DE8A8 = 4503601774854144.0;
const f32 lbl_805DE8B0 = 99.0f;
const f32 lbl_805DE8B4 = 59.0f;
const f64 lbl_805DE8B8 = 4503601774854144.0;
const f32 lbl_805DE8C0 = 99.0f;
const f32 lbl_805DE8C4 = 59.0f;
const f32 lbl_805DE8C8 = 0.0f;
const f64 lbl_805DE8D0 = 4503601774854144.0;
const f32 lbl_805DE8D8 = 0.175f;
const f32 lbl_805DE8DC = 0.0f;
const f32 lbl_805DE8E0 = 100.0f;
const f32 lbl_805DE8E4 = 200.0f;
const f32 lbl_805DE8E8[2] = { 300.0f, 0.0f };
const f32 lbl_805DE8F0 = 0.0f;
const f64 lbl_805DE8F8 = 4503601774854144.0;

extern RaceUserData* lbl_805DD570;
extern char kar_linkfile_gmdata_dat_80496028[];
extern u8 HSD_PadState[];
extern const f32 lbl_805DE7A8;

void* memset(void* dst, int val, unsigned long n);
s32 fn_8000AD48(void);
s32 kar_gmracenormal__8000ae08(void);
f32 kar_gmracenormal__8000a370(s32 arg0);
s32 kar_gmracenormal__8000af5c(void);
s32 kar_gmracenormal__8000af94(void);
s32 kar_gmracenormal__8003d5f0(void);
s32 kar_gmracenormal__8003f6cc(void);
s32 fn_800095F8(s32 arg0);
s32 fn_80262060(s32 arg0);
void kar_grcommon_get_startpos_vectors_by_index(s32 index, Vec* pos, Vec* dir,
                                                Vec* scale);
void kar_plclearchecker_set_template_vec_008(s32 arg0, Vec* arg1);
void kar_plclearchecker_set_template_vecs_014_020(s32 arg0, Vec* arg1,
                                                  Vec* arg2);
void kar_plclearchecker_set_slot_player_index(s32 arg0, s32 arg1);
void kar_gmracenormal__8022c86c(s32 arg0, s32 arg1);
void kar_plclearcheckerlib__near_8022c898(s32 arg0, s32 arg1);
void kar_plclearcheckerlib__near_8022c8c8(s32 arg0, s32 arg1);
void kar_plclearcheckerlib__near_8022c8f8(s32 arg0, s32 arg1);
void kar_plclearchecker_set_template_byte_08c(s32 arg0, s32 arg1);
void kar_plclearcheckerlib__near_8022c960(s32 arg0, s32 arg1);
void kar_plclearcheckerlib__near_8022c990(s32 arg0, s32 arg1);
void kar_plclearcheckerlib__near_8022c9c0(s32 arg0, s32 arg1);
void kar_plclearcheckerlib__near_8022c9f0(s32 arg0, s32 arg1);
void kar_plclearcheckerlib__near_8022ca20(s32 arg0, f32 arg1);
void kar_plclearcheckerlib__near_8022ca90(s32 arg0, f32 arg1);
void kar_plclearcheckerlib__near_8022cac0(s32 arg0, s32 arg1);
void kar_plclearcheckerlib__near_8022cc10(s32 arg0, s32 arg1);
void kar_plclearcheckerlib__near_8022cfc8(s32 arg0, f32* arg1);
void kar_plclearcheckerlib__near_8022d660(s32 arg0);
void kar_plclearcheckerlib__near_8022d798(s32 arg0, s32 arg1);
void kar_plclearcheckerlib__near_8022d7c8(s32 arg0);
void kar_plclearchecker_set_template_float_02c_030(s32 arg0, f32 arg1);
void fn_8022BA5C(s32 arg0);
void fn_8022B768(s32 arg0);
u64 fn_803AE0F0(f32 arg0);
f32 fn_803AE03C(u64 arg0);

void kar_gmracecommon__80012e84(void* gp)
{
    char* base = kar_linkfile_gmdata_dat_80496028;

    if (lbl_805DD570 != gp) {
        OSReport(base + 0x118);
        __assert(base + 0x134, 0x766, base + 0x144);
    }

    HSD_ObjFree(&lbl_80537400, gp);
    lbl_805DD570 = NULL;
}

void kar_gmracecommon__near_80012efc(void)
{
    RaceGame* game = (RaceGame*) kar_gmmain__near_80006c14();
    RaceSlot* slots = game->slots;
    RacePlayerMap* maps = game->player_maps;
    s8 first_slot;
    s8 active_count;
    s8 compact_index;
    s8 i;

    for (i = 0; i < 5; i++) {
        if (slots[i].kind != 4) {
            first_slot = i;
            break;
        }
    }

    active_count = 0;
    for (i = 0; i < 4; i++) {
        if (maps[i].active != 0) {
            active_count++;
        }
    }
    game->active_player_count = active_count;

    compact_index = 0;
    for (i = 0; i < 4; i++) {
        if (maps[i].active != 0) {
            if (game->active_player_count <= 2) {
                maps[i].mapped_index = compact_index;
            } else {
                maps[i].mapped_index = i;
            }
            compact_index++;
        } else {
            maps[i].mapped_index = -1;
        }
    }

    for (i = 0; i < 4; i++) {
        if (maps[i].active != 0) {
            maps[i].slot_index = i;
            if (slots[i].kind == 4) {
                maps[i].slot_index = first_slot;
            }
        } else if (slots[i].kind == 0 || slots[i].kind == 1) {
            maps[i].slot_index = i;
        } else {
            maps[i].slot_index = -1;
        }
    }

    for (i = 0; i < 5; i++) {
        if (slots[i].kind != 4) {
            lbl_805DD570->active_slot_count++;
        }
    }
}

void kar_gmracecommon__near_800130a8(void)
{
    RaceGame* game = (RaceGame*) kar_gmmain__near_80006c14();
    RaceCommon* race_common = &game->race_common;
    HSD_GObj* gobj;
    RaceUserData* user_data;
    s32 i;

    memset(race_common, 0, sizeof(RaceCommon));
    gobj = HSD_GObjCreate(0x1A, 0x19, 0);
    HSD_GObjProcCreate(gobj, kar_gmautodemo__near_80011024, 0x13);
    HSD_ObjAllocInit(&lbl_80537400, 0xE4, 4);
    user_data = HSD_ObjAlloc(&lbl_80537400);
    lbl_805DD570 = user_data;
    HSD_GObjUserDataLink(gobj, 0x1A, kar_gmracecommon__80012e84, user_data);

    race_common->enabled = 1;
    race_common->status = 0;
    race_common->flags = 0;

    user_data->field_0 = 0;
    user_data->field_4 = 0;
    user_data->field_8 = 0;
    user_data->field_C = 0;
    race_common->state = 0;
    race_common->current_slot = -1;
    race_common->timer = 0x3C;
    race_common->current_index = -1;
    race_common->previous_index = -1;
    race_common->elapsed = lbl_805DE7A8;
    user_data->active_slot_count = 0;

    for (i = 0; i < 5; i++) {
        race_common->flags_18[i] = 0;
        race_common->flags_1D[i] = 0;
        race_common->flags_22[i] = 0;
        race_common->flags_27[i] = 0;
        race_common->start_positions[i] = i;
        race_common->alternate_start_positions[i] = -1;
        race_common->words_38[i] = 0;
        race_common->words_4C[i] = 0;
        race_common->floats_60[i] = lbl_805DE7A8;
        race_common->floats_74[i] = lbl_805DE7A8;
        race_common->words_88[i] = 0;
        race_common->words_9C[i] = 0;
        race_common->vectors_B0[i].x = 0.0f;
        race_common->vectors_B0[i].y = 0.0f;
        race_common->vectors_B0[i].z = 0.0f;
        race_common->vectors_EC[i].x = 0.0f;
        race_common->vectors_EC[i].y = 0.0f;
        race_common->vectors_EC[i].z = 0.0f;
        race_common->triplets_128[i][0] = 0;
        race_common->triplets_128[i][1] = 0;
        race_common->triplets_128[i][2] = 0;
        race_common->flags_200[i] = 0;
        race_common->words_208[i] = 0;
        race_common->floats_21C[i] = lbl_805DE7A8;
        race_common->floats_230[i] = lbl_805DE7A8;
        race_common->floats_244[i] = lbl_805DE7A8;

        user_data->words_6C[i] = 0;
        user_data->floats_80[i] = lbl_805DE7A8;
        user_data->bytes_10[i] = 0;
        user_data->words_BC[i] = 0;
        user_data->words_94[i] = 0;
        user_data->bytes_15[i] = 0;
        user_data->words_D0[i] = 0;
    }

    race_common->field_258 = 0;
    race_common->field_25C = 0;
    race_common->field_260 = 0;
    kar_gmracecommon__near_80012efc();
    ClearChecker_MarkUnlockSfxPlayedThisFrame();
}

u32 kar_gmracecommon__near_800132b8(void)
{
    return lbl_805DD570->field_0;
}

void kar_gmracecommon__near_800132c4(void)
{
    RaceGame* game = (RaceGame*) kar_gmmain__near_80006c14();

    game->enabled_AA4 = 1;
}

void kar_gmracecommon__near_800132ec(void)
{
    RaceGame* game = (RaceGame*) kar_gmmain__near_80006c14();

    game->enabled_AA4 = 0;
}

void kar_gmracecommon__near_80013314(void)
{
    RaceGame* game = (RaceGame*) kar_gmmain__near_80006c14();
    u8 src;
    u8 value;

    if ((s8) kar_gmracenormal__8000aea8() != 4 &&
        (s8) kar_gmracenormal__8000aea8() != 2) {
        return;
    }
    if ((s8) kar_gmracenormal__8003d5f0() == 1) {
        return;
    }
    if ((s8) kar_gmracenormal__8003d5f0() == 2) {
        return;
    }
    if ((s8) kar_gmracenormal__8000aea8() == 2 &&
        (s8) kar_gmracenormal__8000af94() != 0 &&
        (s8) kar_gmracenormal__8000af94() != 2) {
        return;
    }

    if (game->source_disabled == 0) {
        game->course = game->source_course;
        game->mode = game->source_mode;
        game->value_A9C = game->source_value;

        src = game->source_flags;
        value = game->settings_AA5;
        value = (value & ~0x10) | ((src >> 1) & 0x10);
        game->settings_AA5 = value;

        src = game->source_flags;
        value = game->settings_AA5;
        value = (value & ~0x8) | ((src >> 2) & 0x8);
        game->settings_AA5 = value;

        src = game->source_flags;
        value = game->settings_AA5;
        value = (value & ~0x6) | ((src >> 5) & 0x6);
        game->settings_AA5 = value;

        src = game->source_flags;
        value = game->settings_AA6;
        value = (value & ~0x40) | ((src << 2) & 0x40);
        game->settings_AA6 = value;

        src = game->source_flags;
        value = game->settings_AA6;
        value = (value & ~0x6) | ((src >> 1) & 0x6);
        game->settings_AA6 = value;
    }

    if ((s8) kar_gmracenormal__8000af5c() != 0) {
        RaceSlot* slots = game->slots;

        slots[0].kind = 1;
        slots[0].player_index = 0;
        slots[0].field_8 = 8;
        slots[0].field_9 = 8;
        slots[1].kind = 1;
        slots[1].player_index = 1;
        slots[1].field_8 = 8;
        slots[1].field_9 = 8;
        slots[2].kind = 1;
        slots[2].player_index = 2;
        slots[2].field_8 = 8;
        slots[2].field_9 = 8;
        slots[3].kind = 1;
        slots[3].player_index = 3;
        slots[3].field_8 = 8;
        slots[3].field_9 = 8;
        game->player_count = 4;
        game->course = 0;
        game->mode = 3;
        game->value_A9C = 0;

        value = game->settings_AA5;
        value = (value & ~0x10);
        game->settings_AA5 = value;
        value = game->settings_AA5;
        value = (value & ~0x8);
        game->settings_AA5 = value;
        value = game->settings_AA5;
        value = (value & ~0x6) | 2;
        game->settings_AA5 = value;
        value = game->settings_AA6;
        value = (value & ~0x40) | 0x40;
        game->settings_AA6 = value;
        value = game->settings_AA6;
        value = (value & ~0x6) | 2;
        game->settings_AA6 = value;
    }
}

void kar_gmracecommon__near_800134d4(void)
{
    RaceGame* game = (RaceGame*) kar_gmmain__near_80006c14();
    s32 mode = (game->settings_AA6 >> 1) & 3;
    u64 ticks;
    f32 base;

    switch (mode) {
    case 0:
        base = (f32) (*(u32*) 0x800000F8 >> 2) * lbl_805DE7F4;
        ticks = fn_803AE0F0(base);
        base = fn_803AE03C(ticks);
        ticks = fn_803AE0F0(lbl_805DE7F0 * base);
        kar_lbaudio__near_80062874(ticks);
        break;
    case 2:
        base = (f32) (*(u32*) 0x800000F8 >> 2) * lbl_805DE7F4;
        ticks = fn_803AE0F0(base);
        base = fn_803AE03C(ticks);
        ticks = fn_803AE0F0(lbl_805DE7F8 * base);
        kar_lbaudio__near_80062874(ticks);
        break;
    default:
        base = (f32) (*(u32*) 0x800000F8 >> 2) * lbl_805DE7F4;
        ticks = fn_803AE0F0(base);
        base = fn_803AE03C(ticks);
        ticks = fn_803AE0F0(base);
        kar_lbaudio__near_80062874(ticks);
        break;
    }
}

void kar_gmracecommon__near_800135ec(s32 player)
{
    RaceGame* game;
    RaceCommon* race_common;
    RaceSlot* slots;
    RaceSlot* slot;
    AutoDemoData* auto_data;
    s32 player_index;
    s32 start_pos_index;
    s32 route_index;
    f32 speed;
    Vec pos;
    Vec dir;
    Vec scale;
    s32 count;
    s32 replay_index;
    f32* slot_params;

    kar_gmmain__near_80006c14();
    game = (RaceGame*) kar_gmmain__near_80006c14();
    slots = game->slots;
    race_common = &game->race_common;
    auto_data = *(AutoDemoData**) kar_gmautodemo__near_8000fcb0();

    player_index = (s8) player;
    if ((s8) kar_diag__8000acb0() == 1) {
        start_pos_index =
            race_common->alternate_start_positions[player_index];
    } else if ((s8) fn_8000AD48() == 1) {
        start_pos_index =
            race_common->alternate_start_positions[player_index];
    } else {
        start_pos_index = race_common->start_positions[player_index];
    }

    kar_grcommon_get_startpos_vectors_by_index(start_pos_index, &pos, &dir,
                                               &scale);
    route_index = (s8) fn_80262060(start_pos_index);
    speed = kar_gmracenormal__8000a370(player_index);
    if ((s8) kar_gmracenormal__8000af5c() != 0) {
        speed = lbl_805DE808;
        route_index = 3;
    } else if ((s8) fn_8000AD48() == 1 &&
               (s8) kar_gmracenormal__8000ae08() >= 1) {
        route_index = 3;
        speed = lbl_805DE808;
    }

    kar_plclearchecker_set_template_vec_008(player_index, &pos);
    kar_plclearchecker_set_template_vecs_014_020(player_index, &dir, &scale);
    slot = &slots[player_index];
    kar_plclearchecker_set_slot_player_index(player_index, slot->player_index);
    kar_gmracenormal__8022c86c(player_index, slot->kind);
    kar_plclearcheckerlib__near_8022c898(player_index, slot->field_1);
    kar_plclearcheckerlib__near_8022c8c8(player_index, slot->field_2);
    kar_plclearcheckerlib__near_8022c8f8(player_index, slot->field_3);
    kar_plclearchecker_set_template_byte_08c(player_index, slot->field_4);

    if (kar_shadow__near_8007b650() != 0) {
        s32 shadow_offset = player_index * 2;
        s32 shadow_player = (s8) HSD_PadState[shadow_offset + 0x12];

        if (shadow_player == (u8) kar_shadow__near_8007b990()) {
            s32 source_slot = (s8) HSD_PadState[shadow_offset + 0x13];
            kar_plclearcheckerlib__near_8022cc10(player_index,
                                                 slots[source_slot].field_5);
        } else {
            kar_plclearcheckerlib__near_8022cc10(player_index, 0);
        }
    } else {
        kar_plclearcheckerlib__near_8022cc10(player_index, slot->field_5);
    }

    kar_plclearcheckerlib__near_8022c960(player_index, player_index);
    kar_plclearcheckerlib__near_8022c9f0(player_index, (s8) route_index);
    kar_plclearcheckerlib__near_8022cac0(player_index, (s32) speed);
    kar_plclearcheckerlib__near_8022d798(player_index, slot->field_9);

    if ((s8) fn_8000AD48() == 1 &&
        (s8) kar_gmracenormal__8000ae50() == 0x17 && player_index == 4) {
        kar_plclearchecker_set_template_float_02c_030(4,
                                                      auto_data->template_float);
        kar_plclearcheckerlib__near_8022d660(4);
    }

    count = game->active_player_count;
    if (count > 2) {
        kar_plclearcheckerlib__near_8022c990(player_index, 1);
        kar_plclearcheckerlib__near_8022c9c0(player_index, 2);
    } else if (count > 1) {
        kar_plclearcheckerlib__near_8022c990(player_index, 0);
        kar_plclearcheckerlib__near_8022c9c0(player_index, 1);
    } else {
        kar_plclearcheckerlib__near_8022c990(player_index, 0);
        kar_plclearcheckerlib__near_8022c9c0(player_index, 0);
    }

    game = (RaceGame*) kar_gmmain__near_80006c14();
    slots = game->slots;
    kar_gmautodemo__near_8000fcb0();
    slot = &slots[player_index];
    slot_params = slot->params;
    slot_params[0] = lbl_805DE808;
    slot_params[1] = lbl_805DE808;
    slot_params[2] = lbl_805DE808;
    slot_params[3] = lbl_805DE808;
    slot_params[4] = lbl_805DE808;
    slot_params[5] = lbl_805DE808;
    slot_params[6] = lbl_805DE808;
    slot_params[7] = lbl_805DE808;
    slot_params[8] = lbl_805DE808;

    if ((s8) kar_diag__8000acb0() == 1 || (s8) fn_8000AD48() == 1) {
        RaceSettings* race_settings = &game->race_settings;
        RaceSettingWindow* source =
            (RaceSettingWindow*) &race_settings->data[player_index * 0x24];

        slot->params[0] = source->params[0];
        slot->params[1] = source->params[1];
        slot->params[2] = source->params[2];
        slot->params[3] = source->params[3];
        slot->params[4] = source->params[4];
        slot->params[5] = source->params[5];
        slot->params[6] = source->params[6];
        slot->params[7] = source->params[7];
        slot->params[8] = source->params[8];
        kar_plclearcheckerlib__near_8022c8c8(
            player_index, race_settings->field_C0[player_index]);
        kar_plclearcheckerlib__near_8022c8f8(
            player_index, race_settings->field_C5[player_index]);
    }

    kar_plclearcheckerlib__near_8022cfc8(player_index, slot->params);

    game = (RaceGame*) kar_gmmain__near_80006c14();
    auto_data = *(AutoDemoData**) kar_gmautodemo__near_8000fcb0();
    if (((s8) kar_gmracenormal__8000aea8() == 4 &&
         (s8) kar_gmracenormal__8003d5f0() == 0) ||
        ((s8) kar_gmracenormal__8000aea8() == 6 &&
         (s8) kar_gmracenormal__8003f6cc() == 1)) {
        replay_index = (s8) fn_800095F8(player_index);
        game->player_speeds[player_index] =
            auto_data->replay_speeds[replay_index];
    } else {
        game->player_speeds[player_index] = auto_data->default_speed;
    }

    kar_plclearcheckerlib__near_8022ca20(player_index, lbl_805DE808);
    kar_plclearcheckerlib__near_8022ca90(player_index, lbl_805DE808);

    if ((s8) kar_gmracenormal__8000af5c() != 0) {
        fn_8022BA5C(player_index);
    } else if ((s8) fn_8000AD48() == 1 &&
               (s8) kar_gmracenormal__8000ae08() >= 1) {
        fn_8022BA5C(player_index);
    } else {
        fn_8022B768(player_index);
    }

    if (slot->kind == 1) {
        kar_plclearcheckerlib__near_8022cc10(player_index, 0);
        kar_plclearcheckerlib__near_8022d7c8(player_index);
    }
}
