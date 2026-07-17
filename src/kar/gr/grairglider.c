#include "functions.h"
#include <dolphin/mtx/vec.h>
#include <dolphin/types.h>
#include <kar/gr/grairglider.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/objalloc.h>

#define GR_SDK_AIR_GLIDER 0
#define AIR_GLIDER_SLOT_STRIDE 0x5C

typedef struct Ground Ground;
typedef struct GroundData GroundData;
typedef struct StadiumData StadiumData;
typedef struct AirGliderStadiumParam AirGliderStadiumParam;
typedef struct AirGliderConfig AirGliderConfig;
typedef struct AirGliderConfigRoot AirGliderConfigRoot;
typedef struct AirGliderEnemyEntry AirGliderEnemyEntry;
typedef struct AirGliderPickPair AirGliderPickPair;
typedef struct AirGliderPickTable AirGliderPickTable;
typedef struct AirGliderRuntime AirGliderRuntime;
typedef struct AirGliderSlot AirGliderSlot;
typedef struct AirGliderClearChecker AirGliderClearChecker;
typedef struct AirGliderCollisionPoly AirGliderCollisionPoly;
typedef struct AirGliderLightUserDesc AirGliderLightUserDesc;
typedef union AirGliderFlagByte AirGliderFlagByte;

union AirGliderFlagByte {
    u8 raw;
    struct {
        u8 blocked : 1;
        u8 has_effect : 1;
        u8 bit2 : 1;
        u8 bit3 : 1;
        u8 bit4 : 1;
        u8 bit5 : 1;
        u8 bit6 : 1;
        u8 bit7 : 1;
    } bits;
};

struct Ground {
    void* model;
    u8 pad_04[0x04];
    GroundData* data;
    u8 pad_0C[0x14];
    AirGliderCollisionPoly* collision_polys;
    u8 pad_24[0x6F0];
    void* fade_handle;
    void* light_user;
};

struct GroundData {
    u8 pad_00[0x50];
    StadiumData* stadium_data;
};

struct StadiumData {
    s32 kind;
    AirGliderStadiumParam* airglider;
};

struct AirGliderStadiumParam {
    s32 pad_00;
    s32 collision_joint;
};

struct AirGliderConfig {
    u8 pad_00[0x26];
    s16 respawn_random;
    s16 mode;
};

struct AirGliderConfigRoot {
    s16 field_00;
    u8 pad_02[0x02];
    AirGliderEnemyEntry* entries;
    s16 route_count;
    u8 pad_0A[0x02];
    AirGliderPickTable* pick_table;
    AirGliderConfig* config;
};

struct AirGliderEnemyEntry {
    u8 pad_00[0x06];
    s16 enemy_kind;
    s16 weights[0x18];
};

struct AirGliderPickPair {
    s16 kind;
    s16 weight;
};

struct AirGliderPickTable {
    AirGliderPickPair* pairs;
};

struct AirGliderSlot {
    u8 pad_00[0x34];
    s16 respawn_delay;
    u8 pad_36[0x14];
    u8 flags_4A;
    u8 flags_4B;
    s16 enemy_kind;
    s16 field_4E;
    s16 field_50;
    AirGliderFlagByte flags_52;
    u8 pad_53;
    s16 field_54;
    u8 pad_56[0x02];
    void* spawn_handle;
};

struct AirGliderRuntime {
    HSD_GObj* update_gobj;
    AirGliderSlot* slots;
    void* route_state;
    u32 frame_counter;
    u32 spawned_count;
    u16 low_kind_count;
    u16 high_kind_count;
    u8 pad_18[0x1C];
    f32 field_34;
    u8 pad_38[0x04];
};

struct AirGliderClearChecker {
    void* checker;
    Vec pos;
    Vec forward;
    Vec side;
    s32 field_28;
    f32 field_2C;
    f32 field_30;
    s16 field_34;
    s16 field_36;
    f32 field_38;
    f32 field_3C;
    s16 field_40;
    s16 field_42;
    AirGliderFlagByte flags_44;
    u8 pad_45;
    u16 active;
};

struct AirGliderCollisionPoly {
    u8 pad_00[0x138];
    void* light_zone;
    u8 pad_13C[0x04];
};

struct AirGliderLightUserDesc {
    void* field_00;
    u8 field_04;
    u8 field_05;
    u8 pad_06[0x02];
    f32 field_08;
    f32 field_0C;
    f32 field_10;
    u8 pad_14[0x08];
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    f32 field_20;
    f32 field_24;
    f32 field_28;
};

extern u32 lbl_805DD700;
extern u32 lbl_805DD704;
extern u32* volatile HSD_RandSeedPtr;
extern u32 HSD_RandDefaultSeed;
extern u16 lbl_805DD708;
extern AirGliderClearChecker* lbl_805DD70C;
extern AirGliderConfigRoot* lbl_805DD710;
extern AirGliderRuntime* volatile lbl_805DD714;
extern char kar_src_grairglider_804a56f0[];
extern char lbl_804A5700[];

void* kar_lbvector__near_80065a80(s32 kind);
void kar_lbvector__near_80065ae4(void* handle);
void kar_lbfade_set_draw_priority(void* handle, s32 priority);
void kar_lbfade_set_state_field_0c(void* handle, s32 value);
void kar_lbfade_get_current_color(void* handle, void* out);
void kar_lbfade_start_color_ramp(void* handle, void* from, void* to,
                                 s32 duration);
void kar_lbhvqm__near_80079314(void);
void kar_lbhvqm__near_800793ac(void* callback);
void kar_lbhvqm__near_800793b8(void);
void kar_grlib2__near_800d61e8(f32* arg0, f32* arg1, f32* arg2);
void* kar_lbarealightuser__near_8007a4d0(AirGliderLightUserDesc* desc);
void* kar_lbarealightzone__8007ac30(void* light_zone);
void kar_lbarealightuser__near_8007a598(void* draw, void* arg,
                                        void* light_user);
void kar_lbarealightzone__near_8007ad58(void* model, void* arg,
                                        void* light_zone);
void* kar_gryakubreakhpcoll_create_airglider_kind64_translated_collision_marker(
    void* model, s32 joint, void* pos);
void kar_emupdate__near_80203fac(void* handle, Vec* out);
void* kar_emupdate__near_80204054(void* handle);
void* kar_emupdate__near_802049c4(s32 enemy_id);
void kar_lbkdcoll__near_80072c90(s32 arg0, void* arg1, s32 arg2, s32 arg3,
                                 s32 arg4, s32 arg5, s32 arg6, s32 arg7,
                                 s32 arg8);
void kar_efdata__near_80235720(void);
void kar_lbvector_normalize_with_axis_fallback(Vec* dst, Vec* src);
f32 kar_lbvector_angle_between(Vec* a, Vec* b);
s32 fn_801FD0E0(Vec* v);
void fn_801FD060(s32 enemy_id);
void fn_80261ECC(void);
s16* fn_80262808(void);
void HSD_ObjAllocInit(HSD_ObjAllocData* data, u32 size, u32 align);
void* HSD_ObjAlloc(HSD_ObjAllocData* data);
void HSD_ObjFree(HSD_ObjAllocData* data, void* obj);
s32 HSD_Randi(s32 max_val);
s8 kar_gmracenormal__8000aea8(void);
s8 kar_gmracenormal__8003d5f0(void);
s8 kar_gmracenormal__8003f6cc(void);

char kar_src_grairglider_804a56f0[0x10] = "grairglider.c";
char lbl_804A5700[0x38] =
    "stadium_data && stadium_data->kind == GrSDK_AirGlider";
char kar_src_lbkdtree_804a5738[0x0C] = "lbkdtree.h";
char lbl_804A5744[0x44] =
    "lbKdtreeObjGetFlags(kdtree, objKind) & LbKdtree_Flags_Type_Static";
u32 lbl_804A5788[0x18] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x3F800000, 0x00000000, 0x3F800000,
    0x00000000, 0x67725A47, 0x656E6541, 0x64642020,
    0x20207468, 0x69732070, 0x6F696E74, 0x20697320,
    0x756E6B6E, 0x6F776E20, 0x636F7572, 0x73652020,
    0x2020706F, 0x696E743A, 0x25640A00, 0x00000000,
};

HSD_ObjAllocData grairglider_runtime_objalloc_data[4];
Vec lbl_80557808;
Vec lbl_80557814;

__declspec(section ".sdata") s16 lbl_805D6198[4] = { 1, 2, 4, 8 };
__declspec(section ".sdata") u32 lbl_805D61A0[2] = { 0x00010002, 0x00040008 };

__declspec(section ".sdata2") const f32 lbl_805DF798 = -3.4028235e38f;
__declspec(section ".sdata2") const f32 lbl_805DF79C = 0.0f;
__declspec(section ".sdata2") const f32 lbl_805DF7A0 = 0.01f;
__declspec(section ".sdata2") const f32 lbl_805DF7A4 = 1.0f;
__declspec(section ".sdata2") const f32 lbl_805DF7A8 = -1.0f;
__declspec(section ".sdata2") const f32 lbl_805DF7AC = 0.00001f;
__declspec(section ".sdata2") const f32 lbl_805DF7B0[2] = { -0.00001f, 0.0f };
__declspec(section ".sdata2") const f32 lbl_805DF7B8 = 0.0f;
__declspec(section ".sdata2") const f32 lbl_805DF7BC = -80.0f;
__declspec(section ".sdata2") const f32 lbl_805DF7C0 = 3.4028235e38f;
__declspec(section ".sdata2") const f32 lbl_805DF7C4 = -1.0f;
__declspec(section ".sdata2") const f64 lbl_805DF7C8 = 4503601774854144.0;
__declspec(section ".sdata2") const f32 lbl_805DF7D0 = 1.0f;
__declspec(section ".sdata2") const f32 lbl_805DF7D4 = 4.0f;
__declspec(section ".sdata2") const f32 lbl_805DF7D8 = 0.6f;
__declspec(section ".sdata2") const f32 lbl_805DF7DC = 0.87266463f;

void* kar_grairglider_create_airglider_hp_collision(Ground* ground, void* pos)
{
    StadiumData* stadium_data;
    BOOL valid;

    stadium_data = ground->data->stadium_data;
    valid = FALSE;
    if (stadium_data != NULL && stadium_data->kind == GR_SDK_AIR_GLIDER) {
        valid = TRUE;
    }
    if (!valid) {
        __assert(kar_src_grairglider_804a56f0, 0x18, lbl_804A5700);
    }

    return kar_gryakubreakhpcoll_create_airglider_kind64_translated_collision_marker(
        ground->model, stadium_data->airglider->collision_joint, pos);
}

void kar_grairglider_init_fade_handle(Ground* ground)
{
    ground->fade_handle = kar_lbvector__near_80065a80(3);
    kar_lbfade_set_draw_priority(ground->fade_handle, 1);
    kar_lbfade_set_state_field_0c(ground->fade_handle, 0);
}

void kar_grairglider_start_fade_color_ramp(Ground* ground, void* color,
                                           s32 duration)
{
    u32 current_color;

    kar_lbfade_get_current_color(ground->fade_handle, &current_color);
    kar_lbfade_start_color_ramp(ground->fade_handle, &current_color, color,
                                duration);
}

void kar_grairglider_destroy_fade_handle(Ground* ground)
{
    kar_lbvector__near_80065ae4(ground->fade_handle);
}

void kar_grairglider_init_realtime_lighting(Ground* ground)
{
    AirGliderLightUserDesc desc;
    f32 zero;

    kar_lbhvqm__near_80079314();
    kar_lbhvqm__near_800793ac(kar_grairglider_apply_collision_lighting_at_point);

    desc.field_00 = NULL;
    desc.field_04 = 0x28;
    desc.field_05 = 3;
    kar_grlib2__near_800d61e8(&desc.field_08, &desc.field_0C,
                              &desc.field_10);
    desc.b = 0;
    desc.g = 0;
    desc.r = 0;
    desc.a = 0xFF;
    zero = *(volatile const f32*) &lbl_805DF79C;
    desc.field_20 = zero;
    desc.field_24 = zero;
    desc.field_28 = *(volatile const f32*) &lbl_805DF7A8;

    ground->light_user = kar_lbarealightuser__near_8007a4d0(&desc);
}

void kar_grairglider_shutdown_hvqm_lighting_hook(void)
{
    kar_lbhvqm__near_800793b8();
}

void kar_grairglider_bind_lightzone_to_collision_poly(Ground* ground,
                                                      s32 poly_idx)
{
    AirGliderCollisionPoly* poly;

    poly = &ground->collision_polys[poly_idx];
    poly->light_zone = kar_lbarealightzone__8007ac30(poly->light_zone);
}

void kar_grairglider_apply_lightuser_to_draw(Ground* ground, void* draw,
                                             void* arg)
{
    kar_lbarealightuser__near_8007a598(draw, arg, ground->light_user);
}

void kar_grairglider_apply_lightzone_to_model(Ground* ground, s32 poly_idx,
                                              void* model, void* arg)
{
    kar_lbarealightzone__near_8007ad58(
        model, arg,
        *(void**) ((u8*) ground->collision_polys +
                   poly_idx * sizeof(AirGliderCollisionPoly) + 0x138));
}

s32 kar_grairglider_pick_weighted_enemy_kind(s32* out_entry_idx)
{
    AirGliderConfigRoot* root;
    AirGliderRuntime* runtime;
    AirGliderPickPair* pairs;
    AirGliderPickPair* pair;
    AirGliderEnemyEntry* entries;
    AirGliderEnemyEntry* entry;
    s32 total_pair_weight;
    s32 threshold;
    s32 pair_idx;
    s32 weight_idx;
    s32 total_entry_weight;
    s32 roll;
    s32 running_weight;
    s32 i;
    s32 result;
    s16 weight;

    *out_entry_idx = -1;
    result = -1;
    total_pair_weight = 0;
    root = lbl_805DD710;
    pairs = root->pick_table->pairs;
    pair = pairs;
    while (pair->kind != -1 && pair->weight != -1) {
        total_pair_weight += pair->weight;
        pair++;
    }

    if (total_pair_weight > 0) {
        runtime = lbl_805DD714;
        threshold =
            (s32) ((f32) total_pair_weight * (1.0f - runtime->field_34));
        pair_idx = 0;
        weight_idx = -1;
        pair = pairs;
        while (pair->kind != -1 && pair->weight != -1) {
            if (threshold < pair->weight) {
                weight_idx = pairs[pair_idx].kind - 0x50;
                break;
            }
            pair++;
            pair_idx++;
        }

        total_entry_weight = 0;
        entries = root->entries;
        for (i = 0; i < root->field_00; i++) {
            weight = entries[i].weights[weight_idx];
            if (weight > 0) {
                total_entry_weight += weight;
            }
        }

        if (total_entry_weight > 0) {
            HSD_RandSeedPtr = (u32*) lbl_805DD700;
            roll = HSD_Randi(total_entry_weight);
            HSD_RandSeedPtr = &HSD_RandDefaultSeed;

            running_weight = 0;
            for (i = 0; i < root->field_00; i++) {
                entry = &entries[i];
                weight = entry->weights[weight_idx];
                if (weight > 0) {
                    running_weight += weight;
                    if (roll < running_weight) {
                        result = entry->enemy_kind;
                        *out_entry_idx = i;
                        break;
                    }
                }
            }
        }
    }

    return result;
}

s32 kar_grairglider_any_clearchecker_blocked(void)
{
    AirGliderClearChecker* checker = lbl_805DD70C;
    u8 flag0;
    u8 flag1;
    u8 flag2;
    u8 flag3;
    s32 bit0;
    s32 bit1;
    s32 bit2;
    s32 bit3;

    flag0 = checker[0].flags_44.raw;
    flag1 = checker[1].flags_44.raw;
    flag2 = checker[2].flags_44.raw;
    bit0 = (flag0 >> 7) & 1;
    bit1 = (flag1 >> 7) & 1;
    flag3 = checker[3].flags_44.raw;
    bit2 = (flag2 >> 7) & 1;
    bit3 = (flag3 >> 7) & 1;
    return (bit3 | (bit2 | (bit0 | bit1))) != 0;
}

s32 kar_grairglider_any_clearchecker_has_effect(void)
{
    AirGliderClearChecker* checker = lbl_805DD70C;
    u8 flag0;
    u8 flag1;
    u8 flag2;
    u8 flag3;
    s32 bit0;
    s32 bit1;
    s32 bit2;
    s32 bit3;

    flag0 = checker[0].flags_44.raw;
    flag1 = checker[1].flags_44.raw;
    flag2 = checker[2].flags_44.raw;
    bit0 = (flag0 >> 6) & 1;
    bit1 = (flag1 >> 6) & 1;
    flag3 = checker[3].flags_44.raw;
    bit2 = (flag2 >> 6) & 1;
    bit3 = (flag3 >> 6) & 1;
    return (bit3 | (bit2 | (bit0 | bit1))) != 0;
}

void kar_grairglider_reset_globals(void)
{
    BOOL use_fixed_seed;

    use_fixed_seed = FALSE;
    if (kar_gmracenormal__8000aea8() == 4 && kar_gmracenormal__8003d5f0() == 1) {
        use_fixed_seed = TRUE;
    }

    if (use_fixed_seed) {
        lbl_805DD700 = (u32) &lbl_805DD704;
        HSD_RandSeedPtr = &lbl_805DD704;
        lbl_805DD704 = 1;
        HSD_RandSeedPtr = &HSD_RandDefaultSeed;
    } else {
        lbl_805DD700 = (u32) HSD_RandSeedPtr;
    }

    lbl_805DD710 = NULL;
    lbl_805DD714 = NULL;
    lbl_805DD70C = NULL;
}

void kar_grairglider_cleanup_spawned_enemies(void)
{
    BOOL skip_cleanup;
    s16* list;
    s16* enemy_ids;

    skip_cleanup = FALSE;
    if (kar_gmracenormal__8000aea8() == 6 && kar_gmracenormal__8003f6cc() == 2) {
        skip_cleanup = TRUE;
    }

    if (!skip_cleanup) {
        fn_80261ECC();
        list = fn_80262808();
        if (list != NULL) {
            enemy_ids = list;
            while (*enemy_ids != -1) {
                fn_801FD060(*enemy_ids);
                enemy_ids++;
            }
        }
    }
}

void kar_grairglider_register_spawned_enemy_kdcoll(void)
{
    s32 seen_kind_mask;
    s16* enemy_ids;
    s32 enemy_id;
    void* object;

    seen_kind_mask = 0;
    enemy_ids = fn_80262808();
    if (enemy_ids != NULL) {
        while ((enemy_id = *enemy_ids) != -1) {
            object = kar_emupdate__near_802049c4(enemy_id);
            if (object != NULL) {
                if (enemy_id < 0x4C) {
                    seen_kind_mask |= 1;
                } else {
                    seen_kind_mask |= 2;
                }
                kar_lbkdcoll__near_80072c90(2, object, 4, 4, 0, 1, 7, 8,
                                            0);
            }
            enemy_ids++;
        }
        if (seen_kind_mask & 1) {
            kar_efdata__near_80235720();
        }
    }
}

void kar_grairglider_mark_spawn_handle_inactive(void* handle)
{
    s32 slot;
    s32 offset;
    u8* slots;
    AirGliderRuntime* runtime;

    if (handle != NULL) {
        slot = (s32) kar_emupdate__near_80204054(handle);
        if (slot >= 0) {
            runtime = lbl_805DD714;
            offset = slot * AIR_GLIDER_SLOT_STRIDE;
            slots = (u8*) runtime->slots;
            if (*(void**) (slots + offset + 0x58) == handle) {
                ((AirGliderFlagByte*) (slots + offset + 0x52))->bits.blocked =
                    FALSE;
            }
        }
    }
}

s32 kar_grairglider_release_spawn_handle(HSD_GObj* gobj)
{
    s32 result;
    s32 slot;
    s32 offset;
    s16 enemy_kind;
    s32 delay;
    AirGliderRuntime* runtime;
    AirGliderSlot* slot_data;
    AirGliderConfig* config;

    result = FALSE;
    if (gobj != NULL) {
        slot = (s32) kar_emupdate__near_80204054(gobj);
        if (slot >= 0) {
            runtime = lbl_805DD714;
            offset = slot * AIR_GLIDER_SLOT_STRIDE;
            slot_data =
                (AirGliderSlot*) ((u8*) runtime->slots + offset);
            if (slot_data->spawn_handle == gobj) {
                enemy_kind = slot_data->enemy_kind;
                slot_data->enemy_kind = -1;
                slot_data->field_4E = 0;
                slot_data->field_50 = 0;
                slot_data->flags_52.bits.blocked = FALSE;
                slot_data->flags_52.bits.has_effect = FALSE;
                slot_data->spawn_handle = NULL;
                slot_data->field_54 = -1;

                config = lbl_805DD710->config;
                switch (config->mode) {
                case 1:
                case 2:
                    lbl_805DD714->low_kind_count--;
                    break;
                case 3:
                    if (enemy_kind < 0x18) {
                        lbl_805DD714->low_kind_count--;
                    } else {
                        lbl_805DD714->high_kind_count--;
                    }
                    break;
                }

                HSD_RandSeedPtr = (u32*) lbl_805DD700;
                delay = HSD_Randi(config->respawn_random);
                HSD_RandSeedPtr = &HSD_RandDefaultSeed;
                result = TRUE;
                slot_data =
                    (AirGliderSlot*) ((u8*) lbl_805DD714->slots + offset);
                slot_data->respawn_delay += delay;
            }
        }
    }
    return result;
}

s32 kar_grairglider_is_position_clear_of_checker_planes(Vec* pos,
                                                        f32 threshold)
{
    s32 i;
    s32 offset;
    s32 result;
    AirGliderClearChecker* checker;
    f32 delta;
    f32 distance;

    i = 0;
    offset = 0;
    result = TRUE;
    while (i < 4) {
        checker = (AirGliderClearChecker*) ((u8*) lbl_805DD70C + offset);
        if (checker->active == 1) {
            delta = pos->x - checker->pos.x;
            if (delta < 0.0f) {
                delta = -delta;
            }
            if (delta < threshold) {
                delta = pos->z - checker->pos.z;
                if (delta < 0.0f) {
                    delta = -delta;
                }
                if (delta < threshold) {
                    delta = pos->y - checker->pos.y;
                    if (delta < 0.0f) {
                        delta = -delta;
                    }
                    if (delta < threshold) {
                        distance = PSVECDistance(pos, &checker->pos);
                        if (distance < 0.0f) {
                            distance = -PSVECDistance(pos, &checker->pos);
                        } else {
                            distance = PSVECDistance(pos, &checker->pos);
                        }
                        if (distance < threshold) {
                            result = FALSE;
                        }
                    }
                }
            }
        }
        i++;
        offset += sizeof(AirGliderClearChecker);
    }
    return result;
}

s32 kar_grairglider_is_position_outside_checker_forward_cones(Vec* pos)
{
    s32 i;
    s32 offset;
    s32 result;
    AirGliderClearChecker* checker;
    Vec delta;

    i = 0;
    offset = 0;
    result = TRUE;
    while (i < 4) {
        checker = (AirGliderClearChecker*) ((u8*) lbl_805DD70C + offset);
        if (checker->active == 1) {
            delta.x = pos->x - checker->forward.x;
            delta.y = pos->y - checker->forward.y;
            delta.z = pos->z - checker->forward.z;
            if (fn_801FD0E0(&delta) == 0) {
                kar_lbvector_normalize_with_axis_fallback(&delta, &delta);
                if (kar_lbvector_angle_between(&checker->side, &delta) <
                    lbl_805DF7DC) {
                    result = FALSE;
                    break;
                }
            }
        }
        i++;
        offset += sizeof(AirGliderClearChecker);
    }
    return result;
}

s32 kar_grairglider_is_chain_spawn_mode(void)
{
    AirGliderConfigRoot* root;
    AirGliderConfig* config;
    s32 result;

    result = FALSE;
    root = lbl_805DD710;
    if (root != NULL) {
        config = root->config;
        if (config != NULL && config->mode == 3) {
            result = TRUE;
        }
    }
    return result;
}

s32 kar_grairglider_is_slot_spawned(s32 slot)
{
    AirGliderSlot* slot_data;
    AirGliderRuntime* runtime;
    AirGliderSlot* slots;

    runtime = lbl_805DD714;
    slots = runtime->slots;
    slot_data = &slots[slot];
    return slot_data->spawn_handle != NULL;
}

s16 kar_grairglider_get_slot_enemy_kind(s32 slot)
{
    AirGliderSlot* slot_data;
    AirGliderRuntime* runtime;
    AirGliderSlot* slots;

    runtime = lbl_805DD714;
    slots = runtime->slots;
    slot_data = &slots[slot];
    return slot_data->enemy_kind;
}

void kar_grairglider_get_slot_enemy_position(s32 slot, Vec* out)
{
    void* handle;
    AirGliderSlot* slot_data;
    AirGliderRuntime* runtime;
    AirGliderSlot* slots;

    runtime = lbl_805DD714;
    slots = runtime->slots;
    slot_data = &slots[slot];
    handle = slot_data->spawn_handle;
    if (handle != NULL) {
        kar_emupdate__near_80203fac(handle, out);
    } else {
        f32 fallback = *(volatile const f32*) &lbl_805DF7C0;

        out->z = fallback;
        out->y = fallback;
        out->x = fallback;
    }
}
