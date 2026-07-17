#include "functions.h"
#include <dolphin/mtx/vec.h>
#include <kar/gr/granim.h>
#include <kar/gr/grcommon.h>
#include <kar/gr/gryaku.h>
#include <kar/lb/lbvector.h>
#include <sysdolphin/gobj.h>

typedef struct Ground Ground;
typedef struct GroundData GroundData;
typedef struct GroundCityParam GroundCityParam;
typedef struct GroundStageYakuObject GroundStageYakuObject;
typedef struct CityScriptAll CityScriptAll;
typedef struct CityScriptGroup CityScriptGroup;
typedef struct CityBitCounterIdAll CityBitCounterIdAll;
typedef struct CityBitCounterIdParamAll CityBitCounterIdParamAll;
typedef struct CityAsset CityAsset;
typedef struct CityAssetAnimParams CityAssetAnimParams;
typedef struct CityAssetMObjParams CityAssetMObjParams;
typedef struct CityAssetTarget CityAssetTarget;
typedef void (*GroundCallback)(void);
typedef void (*GrSwitchCallback)(HSD_GObj* gobj, s32 stage_index);

__declspec(section ".sdata") extern char lbl_805D6368[];
__declspec(section ".sdata") extern GrSwitchCallback lbl_805D6370[];

struct GroundStageYakuObject {
    void* object;
    u8 pad_04[0x44];
};

struct Ground {
    u8 pad_00[0x08];
    GroundData* data;
    u8 pad_0C[0x20C];
    GroundStageYakuObject stage_yaku_objects[1];
};

struct GroundData {
    u8 pad_00[0x08];
    GroundCityParam* indiviParam;
    u8 pad_0C[0x24];
    void* city_asset_anim;
    u8 pad_34[0x0C];
    CityAssetTarget* city_asset_target;
};

struct GroundCityParam {
    void* loopAnimAll;
    void* mode9_route_a;
    void* mode9_route_b;
    void* mode9_anim_select;
    CityScriptAll* scriptAll;
    CityBitCounterIdAll* bitCounterIdAll;
};

struct CityScriptAll {
    CityScriptGroup* groups;
    s32 group_count;
};

struct CityScriptGroup {
    s32* joint_names;
    s32 entry_count;
    s32 yaku_kind;
};

struct CityBitCounterIdAll {
    CityBitCounterIdParamAll* idParamAll;
    s32 idParamNum;
};

struct CityBitCounterIdParamAll {
    u8 pad_00[0x30];
    s32* ids;
    s32 count;
};

struct CityAssetMObjParams {
    void* material_anim;
    void* texture_anim;
};

struct CityAssetAnimParams {
    CityAssetMObjParams* mobj_params;
    u8 pad_04[0x04];
    void* field_08;
    void* field_0C;
};

struct CityAsset {
    void* anim;
    CityAssetAnimParams* anim_params;
};

struct CityAssetTarget {
    void* mobj;
    u8 pad_04[0x04];
    void* field_08;
    void* field_0C;
};

void kar_grcommon__near_800d4bf4(s32 joint_name, Vec* out);
void kar_grcommon__near_800db774(Ground* ground, void* arg1);
s32 kar_grcommon__near_800db2b8(void* arg0, s32 arg1);
void kar_granim__near_800dc630(Ground* ground, s32 anim_id);
void kar_granim__near_800dc1b4(Ground* ground);
void kar_grswitch__800e85a8(Ground* ground, GrSwitchCallback* callbacks,
                            s32 func_num);
void kar_gr_assets__asset_800ce924(CityAsset** out);
s32 fn_80261ECC(void);
s32 kar_gryakucommon_lookup_script_entry_value(void* script, s32 value);
s32 kar_plclearcheckerlib__near_8022c858(s32 slot);
s32 kar_gryakulib_get_yaku_data_checked(HSD_GObj* gobj);
void kar_gryakudownforcezone_create_stage_linked_kind17_yaku(Ground* ground,
                                                             s32 link);
void kar_gryakubreakhpcoll_create_kind68_lighthouse_flag_controller(
    Ground* ground, s32 link);
void kar_gryakuwhispywoods_create_stage_linked_kind69(Ground* ground,
                                                      s32 link);
void kar_gryakubreakhpcoll_create_stage_linked_kind37_breakhpcoll_mid(
    Ground* ground, s32 link);
void kar_gryakubreakhpcoll_create_stage_linked_kind36_breakhpcoll_door(
    Ground* ground, s32 link);
void kar_gryakubreakhpcoll_create_stage_linked_kind38_breakhpcoll_house(
    Ground* ground, s32 link);
void kar_gryakubreakcoll_create_stage_linked_kind33_breakcoll(Ground* ground,
                                                              s32 link);
void kar_gryakubreakcoll_create_stage_linked_kind34_breakcoll(Ground* ground,
                                                              s32 link);
void kar_gryakubreakcoll_create_stage_linked_kind35_breakcoll(Ground* ground,
                                                              s32 link);
void kar_gryakubreakcoral_create_stage_linked_kind29_breakcoral(Ground* ground,
                                                                s32 link);
void kar_gryakurisingcube_create_stage_linked_cube_yaku(Ground* ground,
                                                        s32 link);
void kar_gryakurisingcube_trigger_cube_state_toggle(void* target);
void kar_gryakubreakhpcoll_break_target_by_index_with_credit(
    HSD_GObj* gobj, s32 index, Vec* pos, Vec* dir0, Vec* dir1, s32 player);
void kar_gryakubreakcoll_break_target_by_index(HSD_GObj* gobj, s32 index,
                                               Vec* dir, s32 player);

void kar_grcity1_init_mode_dependent_anim_and_bitcounter_params(HSD_GObj* gobj);
void kar_grcity1_create_stage_city_yaku_objects(Ground* ground);
void kar_grcity1_break_nearby_scripted_city_targets(Vec* pos, f32 radius);
s32 kar_grcity1_lookup_script_entry_value(s32 value);
void kar_grcity1_start_bit_counter_id0_duration500(void);
void kar_grcity1_start_bit_counter_id1_duration500(void);
void kar_grcity1_start_bit_counter_id2_duration500(void);
void kar_grcity1_start_bit_counter_id3_duration500(void);
void kar_grcity1_start_bit_counter_id4_duration100(void);
void kar_grcity1_start_bit_counter_id5_duration100(void);
s32 kar_grcity1_check_bit_counter_param_id_membership(s32 id);
void kar_grcity1_patch_asset_material_anim_params(GroundData* data);
void kar_grcity1_init_risingcube_switch_group(HSD_GObj* gobj);
void kar_grcity1_create_stage_risingcube_pair(Ground* ground);
void kar_grcity1_switch0_trigger_risingcube_by_stage_index(HSD_GObj* gobj,
                                                           s32 stage_index);
void kar_grcity1_switch1_trigger_risingcube_by_stage_index(HSD_GObj* gobj,
                                                           s32 stage_index);
void fn_8010F91C(void);
void fn_8010F920(void);
void fn_8010F924(void);
void fn_8010F928(void);

#define GET_PTR(base, offset) (*(void**) ((u8*) (base) + (offset)))

GroundCallback kar_grcity1_main_callback_table[3] = {
    (GroundCallback) kar_grcity1_init_mode_dependent_anim_and_bitcounter_params,
    (GroundCallback) kar_grcity1_create_stage_city_yaku_objects,
    NULL,
};

s32 kar_grcity1_mode9_anim_id_lookup_table[4] = { 0, 10, 11, 12 };
char kar_src_grcity1_c[0x0C] = "grcity1.c";
char kar_grcity1_assert_bit_counter_id_count_at_least7[0x58] =
    "indiviParam->bitCounterIdAll->idParamNum > GrBitCounterIdParamCity1_RapidRiverRail";

GroundCallback kar_grcity1_risingcube_callback_table[4] = {
    (GroundCallback) kar_grcity1_init_risingcube_switch_group,
    (GroundCallback) kar_grcity1_create_stage_risingcube_pair,
    NULL,
    NULL,
};

GroundCallback lbl_804A7868[4] = { fn_8010F91C, NULL, NULL, NULL };
GroundCallback lbl_804A7878[4] = { fn_8010F920, NULL, NULL, NULL };
GroundCallback lbl_804A7888[4] = { fn_8010F924, NULL, NULL, NULL };
GroundCallback lbl_804A7898[4] = { fn_8010F928, NULL, NULL, NULL };

void kar_grcity1_init_mode_dependent_anim_and_bitcounter_params(HSD_GObj* gobj)
{
    Ground* ground = gobj->user_data;
    GroundCityParam* indiviParam = ground->data->indiviParam;
    s32 mode;

    if (indiviParam != NULL && indiviParam->loopAnimAll != NULL) {
        kar_granim__800dbe48(ground, indiviParam->loopAnimAll);
    }

    mode = fn_80261ECC();
    indiviParam = ground->data->indiviParam;

    switch (mode) {
    case 9:
        kar_grcommon__near_800db774(ground, indiviParam->mode9_route_a);
        kar_grcommon__near_800db774(ground, indiviParam->mode9_route_b);
        kar_granim__near_800dc630(
            ground,
            kar_grcity1_mode9_anim_id_lookup_table[kar_grcommon__near_800db2b8(
                ground->data->indiviParam->mode9_anim_select, 4)]);
        break;
    case 0x16:
        kar_grcommon__near_800db774(ground, indiviParam->mode9_route_b);
        kar_granim__near_800dc630(ground, 0xF);
        break;
    case 0x17:
        kar_grcommon__near_800db774(ground, indiviParam->mode9_route_a);
        kar_granim__near_800dc630(ground, 0x10);
        break;
    case 0x34:
        kar_grcommon__near_800db774(ground, indiviParam->mode9_route_a);
        kar_grcommon__near_800db774(ground, indiviParam->mode9_route_b);
        kar_granim__near_800dc630(ground, 0);
        break;
    default:
        __assert(kar_src_grcity1_c, 0x6A, lbl_805D6368);
        break;
    }

    kar_granim__near_800dc1b4(ground);
}

void kar_grcity1_create_stage_city_yaku_objects(Ground* ground)
{
    kar_gryakudownforcezone_create_stage_linked_kind17_yaku(ground, 0);
    kar_gryakucatchzone_create_stage_linked_kind18_yaku(ground, 1);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 2);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 3);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 4);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 5);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 6);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 7);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 8);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 9);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 10);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 11);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 12);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 13);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 14);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 15);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 16);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 17);
    kar_gryakubreakhpcoll_create_stage_linked_kind61_timed_anim_audio_cycle(
        ground, 18);
    kar_gryakubreakhpcoll_create_stage_linked_kind61_timed_anim_audio_cycle(
        ground, 19);
    kar_gryakubreakhpcoll_create_kind68_lighthouse_flag_controller(ground, 20);
    kar_gryakuwhispywoods_create_stage_linked_kind69(ground, 21);
    kar_gryakulasergate_create_stage_linked_kind32_breakfloor(ground, 22);
    kar_gryakulasergate_create_stage_linked_kind32_breakfloor(ground, 23);
    kar_gryakubreakhpcoll_create_stage_linked_kind37_breakhpcoll_mid(ground,
                                                                     24);
    kar_gryakubreakhpcoll_create_stage_linked_kind36_breakhpcoll_door(ground,
                                                                      25);
    kar_gryakubreakhpcoll_create_stage_linked_kind38_breakhpcoll_house(ground,
                                                                       26);
    kar_gryakubreakcoll_create_stage_linked_kind33_breakcoll(ground, 27);
    kar_gryakubreakcoll_create_stage_linked_kind34_breakcoll(ground, 28);
    kar_gryakubreakcoll_create_stage_linked_kind35_breakcoll(ground, 29);
    kar_gryakubreakcoral_create_stage_linked_kind29_breakcoral(ground, 30);
}

void kar_grcity1_break_nearby_scripted_city_targets(Vec* pos, f32 radius)
{
    s32 player;
    HSD_GObj* yaku_gobj;
    s32 yaku_kind;
    s32 entry_offset;
    s32 group_offset;
    CityScriptAll* script;
    s32 group_idx;
    CityScriptGroup* group;
    s32 entry_idx;
    Vec target_pos;
    Vec dir;
    Ground* ground = kar_gryaku_current_ground;

    script = ground->data->indiviParam->scriptAll;

    if (script == NULL) {
        return;
    }

    for (group_idx = 0, group_offset = 0; group_idx < script->group_count;
         group_offset += sizeof(CityScriptGroup), group_idx++) {
        group = (CityScriptGroup*) ((u8*) script->groups + group_offset);
        for (entry_idx = 0, entry_offset = 0; entry_idx < group->entry_count;
             entry_offset += 4, entry_idx++) {
            kar_grcommon__near_800d4bf4(
                *(s32*) ((u8*) group->joint_names + entry_offset),
                &target_pos);
            dir.x = target_pos.x - pos->x;
            dir.y = target_pos.y - pos->y;
            dir.z = target_pos.z - pos->z;

            if (PSVECMag(&dir) <= radius) {
                kar_lbvector_normalize_with_axis_fallback(&dir, &dir);
                yaku_kind = group->yaku_kind;

                for (player = 0; player < 5; player++) {
                    if (kar_plclearcheckerlib__near_8022c858(player) != 4) {
                        break;
                    }
                }

                for (yaku_gobj = hsdGObj_p_link_tails[8]; yaku_gobj != NULL;
                     yaku_gobj = yaku_gobj->prev) {
                    if (yaku_kind ==
                        kar_gryakulib_get_yaku_data_checked(yaku_gobj)) {
                        switch (yaku_kind) {
                        case 0x26:
                            kar_gryakubreakhpcoll_break_target_by_index_with_credit(
                                yaku_gobj, entry_idx, &target_pos, &dir, &dir,
                                player);
                            break;
                        case 0x21:
                        case 0x22:
                        case 0x23:
                            kar_gryakubreakcoll_break_target_by_index(
                                yaku_gobj, entry_idx, &dir, player);
                            break;
                        }
                    }
                }
            }

        }
    }
}

s32 kar_grcity1_lookup_script_entry_value(s32 value)
{
    CityScriptAll* script = kar_gryaku_current_ground->data->indiviParam->scriptAll;

    if (script != NULL) {
        return kar_gryakucommon_lookup_script_entry_value(script, value);
    }

    return 0;
}

#define DEFINE_CITY1_START_BIT_COUNTER_500(fn_name, id)                    \
    void fn_name(void)                                                      \
    {                                                                       \
        Ground* ground = kar_gryaku_current_ground;                         \
        kar_grcommon__800db5d4(ground, ground->data->indiviParam->bitCounterIdAll, id); \
    }

#define DEFINE_CITY1_START_BIT_COUNTER_100(fn_name, id)                    \
    void fn_name(void)                                                      \
    {                                                                       \
        Ground* ground = kar_gryaku_current_ground;                         \
        kar_grcommon__800db654(ground, ground->data->indiviParam->bitCounterIdAll, id); \
    }

DEFINE_CITY1_START_BIT_COUNTER_500(kar_grcity1_start_bit_counter_id0_duration500, 0)
DEFINE_CITY1_START_BIT_COUNTER_500(kar_grcity1_start_bit_counter_id1_duration500, 1)
DEFINE_CITY1_START_BIT_COUNTER_500(kar_grcity1_start_bit_counter_id2_duration500, 2)
DEFINE_CITY1_START_BIT_COUNTER_500(kar_grcity1_start_bit_counter_id3_duration500, 3)
DEFINE_CITY1_START_BIT_COUNTER_100(kar_grcity1_start_bit_counter_id4_duration100, 4)
DEFINE_CITY1_START_BIT_COUNTER_100(kar_grcity1_start_bit_counter_id5_duration100, 5)

s32 kar_grcity1_check_bit_counter_param_id_membership(s32 id)
{
    GroundCityParam* indiviParam =
        kar_gryaku_current_ground->data->indiviParam;
    CityBitCounterIdParamAll* idParamAll;
    s32 i;
    s32 offset;

    if (indiviParam->bitCounterIdAll->idParamNum <= 6) {
        __assert(kar_src_grcity1_c, 0x1C3,
                 kar_grcity1_assert_bit_counter_id_count_at_least7);
    }

    idParamAll = indiviParam->bitCounterIdAll->idParamAll;
    offset = 0;
    for (i = 0; i < idParamAll->count; i++) {
        if (id == *(s32*) ((u8*) idParamAll->ids + offset)) {
            return 1;
        }
        offset += sizeof(s32);
    }

    return 0;
}

void kar_grcity1_patch_asset_material_anim_params(GroundData* data)
{
    CityAsset* asset;
    CityAssetTarget* target;

    kar_gr_assets__asset_800ce924(&asset);

    data->city_asset_anim = asset->anim;
    target = data->city_asset_target;
    *(void**) ((u8*) target->mobj + 0x7C) =
        asset->anim_params->mobj_params->material_anim;
    *(void**) ((u8*) target->mobj + 0x80) =
        asset->anim_params->mobj_params->texture_anim;
    target->field_08 = asset->anim_params->field_08;
    target->field_0C = asset->anim_params->field_0C;
}

void kar_grcity1_init_risingcube_switch_group(HSD_GObj* gobj)
{
    kar_grswitch__800e85a8(gobj->user_data, lbl_805D6370, 2);
}

void kar_grcity1_create_stage_risingcube_pair(Ground* ground)
{
    kar_gryakurisingcube_create_stage_linked_cube_yaku(ground, 0);
    kar_gryakurisingcube_create_stage_linked_cube_yaku(ground, 1);
}

void kar_grcity1_switch0_trigger_risingcube_by_stage_index(HSD_GObj* gobj,
                                                           s32 stage_index)
{
    Ground* ground = kar_gryaku_current_ground;

    kar_gryakurisingcube_trigger_cube_state_toggle(
        ground->stage_yaku_objects[stage_index].object);
}

void kar_grcity1_switch1_trigger_risingcube_by_stage_index(HSD_GObj* gobj,
                                                           s32 stage_index)
{
    Ground* ground = kar_gryaku_current_ground;

    kar_gryakurisingcube_trigger_cube_state_toggle(
        ground->stage_yaku_objects[stage_index].object);
}

void fn_8010F91C(void)
{
}

void fn_8010F920(void)
{
}

void fn_8010F924(void)
{
}

void fn_8010F928(void)
{
}

__declspec(section ".sdata") char lbl_805D6368[8] = "0";
__declspec(section ".sdata") GrSwitchCallback lbl_805D6370[2] = {
    kar_grcity1_switch0_trigger_risingcube_by_stage_index,
    kar_grcity1_switch1_trigger_risingcube_by_stage_index,
};
