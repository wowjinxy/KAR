#include "functions.h"
#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>
#include <kar/gm/gmautodemo.h>
#include <kar/gm/gmclearchecker.h>
#include <kar/gm/gmdiag.h>
#include <kar/gm/gmracenormal.h>
#include <kar/shadow.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/gobjuserdata.h>
#include <sysdolphin/objalloc.h>

typedef struct RaceSlot RaceSlot;
typedef struct RacePlayerMap RacePlayerMap;
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

struct RaceUserData {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u16 field_C;
    u16 active_slot_count;
    u8 bytes_10[0xA];
    u8 pad_1A[0x52];
    u32 words_6C[5];
    f32 floats_80[5];
    u8 pad_94[0x50];
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
void* kar_gmmain__near_80006c14(void);
void kar_gmautodemo__near_80011024(HSD_GObj* gobj);
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
void kar_lbaudio__near_80062874(u64 arg0);
HSD_GObj* HSD_GObjCreate(u16 classifier, u8 p_link, u8 priority);

#define GET_U8(base, offset) (*(u8*) ((u8*) (base) + (offset)))
#define GET_S8(base, offset) (*(s8*) ((u8*) (base) + (offset)))
#define GET_U16(base, offset) (*(u16*) ((u8*) (base) + (offset)))
#define GET_S16(base, offset) (*(s16*) ((u8*) (base) + (offset)))
#define GET_U32(base, offset) (*(u32*) ((u8*) (base) + (offset)))
#define GET_S32(base, offset) (*(s32*) ((u8*) (base) + (offset)))
#define GET_F32(base, offset) (*(f32*) ((u8*) (base) + (offset)))
#define LOAD_F32(sym) (*(volatile const f32*) &(sym))

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
    u8* game = kar_gmmain__near_80006c14();
    RaceSlot* slots = (RaceSlot*) (game + 0xAC8);
    RacePlayerMap* maps = (RacePlayerMap*) (game + 0xBB8);
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
    GET_S8(game, 0xA96) = active_count;

    compact_index = 0;
    for (i = 0; i < 4; i++) {
        if (maps[i].active != 0) {
            if (GET_S8(game, 0xA96) <= 2) {
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
    u8* race_common = (u8*) kar_gmmain__near_80006c14() + 0x830;
    HSD_GObj* gobj;
    RaceUserData* user_data;
    s32 i;

    memset(race_common, 0, 0x264);
    gobj = HSD_GObjCreate(0x1A, 0x19, 0);
    HSD_GObjProcCreate(gobj, kar_gmautodemo__near_80011024, 0x13);
    HSD_ObjAllocInit(&lbl_80537400, 0xE4, 4);
    user_data = HSD_ObjAlloc(&lbl_80537400);
    lbl_805DD570 = user_data;
    HSD_GObjUserDataLink(gobj, 0x1A, kar_gmracecommon__80012e84, user_data);

    race_common[2] = 1;
    race_common[3] = 0;
    GET_U32(race_common, 4) = 0;

    user_data->field_0 = 0;
    user_data->field_4 = 0;
    user_data->field_8 = 0;
    user_data->field_C = 0;
    race_common[0] = 0;
    race_common[1] = -1;
    GET_U32(race_common, 8) = 0x3C;
    GET_S32(race_common, 0xC) = -1;
    GET_S32(race_common, 0x10) = -1;
    GET_F32(race_common, 0x14) = lbl_805DE7A8;
    user_data->active_slot_count = 0;

    for (i = 0; i < 5; i++) {
        race_common[0x18 + i] = 0;
        race_common[0x1D + i] = 0;
        race_common[0x22 + i] = 0;
        race_common[0x27 + i] = 0;
        race_common[0x2C + i] = i;
        race_common[0x31 + i] = -1;
        GET_U32(race_common, 0x38 + i * 4) = 0;
        GET_U32(race_common, 0x4C + i * 4) = 0;
        GET_F32(race_common, 0x60 + i * 4) = lbl_805DE7A8;
        GET_F32(race_common, 0x74 + i * 4) = lbl_805DE7A8;
        GET_U32(race_common, 0x88 + i * 4) = 0;
        GET_U32(race_common, 0x9C + i * 4) = 0;
        GET_U32(race_common, 0xB0 + i * 0xC) = 0;
        GET_U32(race_common, 0xB4 + i * 0xC) = 0;
        GET_U32(race_common, 0xB8 + i * 0xC) = 0;
        GET_U32(race_common, 0xEC + i * 0xC) = 0;
        GET_U32(race_common, 0xF0 + i * 0xC) = 0;
        GET_U32(race_common, 0xF4 + i * 0xC) = 0;
        race_common[0x128 + i * 3] = 0;
        race_common[0x129 + i * 3] = 0;
        race_common[0x12A + i * 3] = 0;
        race_common[0x200 + i] = 0;
        GET_U32(race_common, 0x208 + i * 4) = 0;
        GET_F32(race_common, 0x21C + i * 4) = lbl_805DE7A8;
        GET_F32(race_common, 0x230 + i * 4) = lbl_805DE7A8;
        GET_F32(race_common, 0x244 + i * 4) = lbl_805DE7A8;

        GET_U32(user_data, 0x6C + i * 4) = 0;
        GET_F32(user_data, 0x80 + i * 4) = lbl_805DE7A8;
        GET_U8(user_data, 0x10 + i) = 0;
        GET_U32(user_data, 0xBC + i * 4) = 0;
        GET_U32(user_data, 0x94 + i * 4) = 0;
        GET_U8(user_data, 0x15 + i) = 0;
        GET_U32(user_data, 0xD0 + i * 4) = 0;
    }

    GET_U32(race_common, 0x258) = 0;
    GET_U32(race_common, 0x25C) = 0;
    GET_U32(race_common, 0x260) = 0;
    kar_gmracecommon__near_80012efc();
    ClearChecker_MarkUnlockSfxPlayedThisFrame();
}

u32 kar_gmracecommon__near_800132b8(void)
{
    return lbl_805DD570->field_0;
}

void kar_gmracecommon__near_800132c4(void)
{
    u8* game = kar_gmmain__near_80006c14();

    game[0xAA4] = 1;
}

void kar_gmracecommon__near_800132ec(void)
{
    u8* game = kar_gmmain__near_80006c14();

    game[0xAA4] = 0;
}

void kar_gmracecommon__near_80013314(void)
{
    u8* game = kar_gmmain__near_80006c14();
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

    if (GET_S8(game, 0x35C) == 0) {
        GET_U8(game, 0xA94) = GET_U8(game, 0x354);
        GET_U8(game, 0xA9A) = GET_S16(game, 0x356);
        GET_U16(game, 0xA9C) = GET_S16(game, 0x358);

        src = GET_U8(game, 0x35A);
        value = GET_U8(game, 0xAA5);
        value = (value & ~0x10) | ((src >> 1) & 0x10);
        GET_U8(game, 0xAA5) = value;

        src = GET_U8(game, 0x35A);
        value = GET_U8(game, 0xAA5);
        value = (value & ~0x8) | ((src >> 2) & 0x8);
        GET_U8(game, 0xAA5) = value;

        src = GET_U8(game, 0x35A);
        value = GET_U8(game, 0xAA5);
        value = (value & ~0x6) | ((src >> 5) & 0x6);
        GET_U8(game, 0xAA5) = value;

        src = GET_U8(game, 0x35A);
        value = GET_U8(game, 0xAA6);
        value = (value & ~0x40) | ((src << 2) & 0x40);
        GET_U8(game, 0xAA6) = value;

        src = GET_U8(game, 0x35A);
        value = GET_U8(game, 0xAA6);
        value = (value & ~0x6) | ((src >> 1) & 0x6);
        GET_U8(game, 0xAA6) = value;
    }

    if ((s8) kar_gmracenormal__8000af5c() != 0) {
        RaceSlot* slots = (RaceSlot*) (game + 0xAC8);

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
        GET_U8(game, 0xA95) = 4;
        GET_U8(game, 0xA94) = 0;
        GET_U8(game, 0xA9A) = 3;
        GET_U16(game, 0xA9C) = 0;

        value = GET_U8(game, 0xAA5);
        value = (value & ~0x10);
        GET_U8(game, 0xAA5) = value;
        value = GET_U8(game, 0xAA5);
        value = (value & ~0x8);
        GET_U8(game, 0xAA5) = value;
        value = GET_U8(game, 0xAA5);
        value = (value & ~0x6) | 2;
        GET_U8(game, 0xAA5) = value;
        value = GET_U8(game, 0xAA6);
        value = (value & ~0x40) | 0x40;
        GET_U8(game, 0xAA6) = value;
        value = GET_U8(game, 0xAA6);
        value = (value & ~0x6) | 2;
        GET_U8(game, 0xAA6) = value;
    }
}

void kar_gmracecommon__near_800134d4(void)
{
    u8* game = kar_gmmain__near_80006c14();
    s32 mode = (GET_U8(game, 0xAA6) >> 1) & 3;
    u64 ticks;
    f32 base;

    switch (mode) {
    case 0:
        base = (f32) (*(u32*) 0x800000F8 >> 2) * LOAD_F32(lbl_805DE7F4);
        ticks = fn_803AE0F0(base);
        base = fn_803AE03C(ticks);
        ticks = fn_803AE0F0(LOAD_F32(lbl_805DE7F0) * base);
        kar_lbaudio__near_80062874(ticks);
        break;
    case 2:
        base = (f32) (*(u32*) 0x800000F8 >> 2) * LOAD_F32(lbl_805DE7F4);
        ticks = fn_803AE0F0(base);
        base = fn_803AE03C(ticks);
        ticks = fn_803AE0F0(LOAD_F32(lbl_805DE7F8) * base);
        kar_lbaudio__near_80062874(ticks);
        break;
    default:
        base = (f32) (*(u32*) 0x800000F8 >> 2) * LOAD_F32(lbl_805DE7F4);
        ticks = fn_803AE0F0(base);
        base = fn_803AE03C(ticks);
        ticks = fn_803AE0F0(base);
        kar_lbaudio__near_80062874(ticks);
        break;
    }
}

void kar_gmracecommon__near_800135ec(s32 player)
{
    u8* game;
    u8* race_common;
    RaceSlot* slots;
    RaceSlot* slot;
    u8* auto_data;
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
    game = kar_gmmain__near_80006c14();
    slots = (RaceSlot*) (game + 0xAC8);
    race_common = game + 0x830;
    auto_data = *(u8**) kar_gmautodemo__near_8000fcb0();

    player_index = (s8) player;
    if ((s8) kar_diag__8000acb0() == 1) {
        start_pos_index = GET_S8(race_common, 0x31 + player_index);
    } else if ((s8) fn_8000AD48() == 1) {
        start_pos_index = GET_S8(race_common, 0x31 + player_index);
    } else {
        start_pos_index = GET_S8(race_common, 0x2C + player_index);
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
            s32 source_slot =
                (s8) HSD_PadState[shadow_offset + 0x13] * sizeof(RaceSlot);
            kar_plclearcheckerlib__near_8022cc10(player_index,
                                                 GET_S8(slots, source_slot + 5));
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
                                                      GET_F32(auto_data, 0xC0));
        kar_plclearcheckerlib__near_8022d660(4);
    }

    count = GET_S8(game, 0xA96);
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

    game = kar_gmmain__near_80006c14();
    slots = (RaceSlot*) (game + 0xAC8);
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
        u8* race_settings = (u8*) kar_gmmain__near_80006c14() + 0x394;
        u8* source = race_settings + player_index * 0x24;
        u8* dest = (u8*) slot;

        GET_U32(dest, 0xC) = GET_U32(source, 0xC);
        GET_U32(dest, 0x10) = GET_U32(source, 0x10);
        GET_U32(dest, 0x14) = GET_U32(source, 0x14);
        GET_U32(dest, 0x18) = GET_U32(source, 0x18);
        GET_U32(dest, 0x1C) = GET_U32(source, 0x1C);
        GET_U32(dest, 0x20) = GET_U32(source, 0x20);
        GET_U32(dest, 0x24) = GET_U32(source, 0x24);
        GET_U32(dest, 0x28) = GET_U32(source, 0x28);
        GET_U32(dest, 0x2C) = GET_U32(source, 0x2C);
        kar_plclearcheckerlib__near_8022c8c8(
            player_index, GET_S8(race_settings, 0xC0 + player_index));
        kar_plclearcheckerlib__near_8022c8f8(
            player_index, GET_S8(race_settings, 0xC5 + player_index));
    }

    kar_plclearcheckerlib__near_8022cfc8(player_index, slot->params);

    game = kar_gmmain__near_80006c14();
    auto_data = *(u8**) kar_gmautodemo__near_8000fcb0();
    if (((s8) kar_gmracenormal__8000aea8() == 4 &&
         (s8) kar_gmracenormal__8003d5f0() == 0) ||
        ((s8) kar_gmracenormal__8000aea8() == 6 &&
         (s8) kar_gmracenormal__8003f6cc() == 1)) {
        replay_index = (s8) fn_800095F8(player_index);
        GET_F32(game, 0xAA8 + player_index * 4) =
            GET_F32(auto_data, 0x9C + replay_index * 4);
    } else {
        GET_F32(game, 0xAA8 + player_index * 4) = GET_F32(auto_data, 0xBC);
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
