#include "functions.h"
#include <dolphin/types.h>
#include <kar/gr/grparts.h>
#include <sysdolphin/random.h>

#define GR_POINT_STRIKE_PANEL_MAX 0x34
#define GR_POINT_STRIKE_SELECT_MAX 0x32
#define GR_SDK_POINT_STRIKE 1
#define GR_YAKU_KIND62_COLLISION_TRIGGER 0x3E
#define GR_YAKU_KIND63_PROXIMITY_ANIM_TRIGGER 0x3F

typedef struct Ground Ground;
typedef struct GroundData GroundData;
typedef struct StadiumData StadiumData;
typedef struct PointStrikePanelData PointStrikePanelData;
typedef struct PointStrikePanelEntry PointStrikePanelEntry;

struct PointStrikePanelEntry {
    s32 kind;
    s32 effect_index;
    s32 param;
    s32 count;
};

struct PointStrikePanelData {
    s32* stadium_joints;
    s32 stadium_joint_num;
    PointStrikePanelEntry* stadium_entries;
    s32 stadium_entry_count;
    s32* airride_joints;
    s32 airride_joint_num;
    PointStrikePanelEntry* airride_entries;
    s32 airride_entry_count;
};

struct StadiumData {
    s32 kind;
    PointStrikePanelData* point_strike;
};

struct GroundData {
    u8 pad_00[0x50];
    StadiumData* stadium_data;
};

struct Ground {
    void* model;
    u8 pad_04[0x04];
    GroundData* data;
    u8 pad_0C[0x744];
    void* point_strike_panels[GR_POINT_STRIKE_PANEL_MAX];
    s32 point_strike_panel_num;
};

s32 kar_grcommon__800db234(s32* list, s32 index, s32 count);
void* kar_gryakubreakhpcoll_create_effect_indexed_kind62_collision_trigger(
    void* model, s32 effect_index, s32 joint, s32 param);
void* kar_gryakubreakhpcoll_create_effect_indexed_kind63_proximity_anim_trigger(
    void* model, s32 effect_index, s32 joint, s32 param);

void kar_grpointstrike_init_panel_handles(Ground* ground)
{
    StadiumData* stadium_data;
    PointStrikePanelData* panel_data;
    s32 stadium_select[GR_POINT_STRIKE_SELECT_MAX];
    s32 airride_select[GR_POINT_STRIKE_SELECT_MAX];
    s32 panel_num;
    s32 group;
    s32 offset;
    s32 i;
    PointStrikePanelEntry* entry;
    void* panel;
    BOOL has_point_strike;

    stadium_data = ground->data->stadium_data;
    has_point_strike = FALSE;
    if (stadium_data != NULL && stadium_data->kind == GR_SDK_POINT_STRIKE) {
        has_point_strike = TRUE;
    }

    if (!has_point_strike) {
        __assert("grpointstrike.c", 0x4C,
                 "stadium_data && stadium_data->kind == GrSDK_PointStrike");
    }

    ground->point_strike_panel_num = panel_num = 0;
    panel_data = stadium_data->point_strike;

    kar_grparts__near_800db1a8(stadium_select, GR_POINT_STRIKE_SELECT_MAX);
    group = 0;
    offset = group;
    while (group < panel_data->stadium_entry_count) {
        entry = (PointStrikePanelEntry*) ((u8*) panel_data->stadium_entries + offset);
        i = 0;
        while (i < entry->count) {
            s32 selected =
                kar_grcommon__800db234(stadium_select,
                                        HSD_Randi(panel_data->stadium_joint_num -
                                                  panel_num),
                                        GR_POINT_STRIKE_SELECT_MAX);
            s32 joint = panel_data->stadium_joints[selected];

            switch (entry->kind) {
            case GR_YAKU_KIND62_COLLISION_TRIGGER:
                panel = kar_gryakubreakhpcoll_create_effect_indexed_kind62_collision_trigger(
                    ground->model, entry->effect_index, joint, entry->param);
                break;
            case GR_YAKU_KIND63_PROXIMITY_ANIM_TRIGGER:
                panel =
                    kar_gryakubreakhpcoll_create_effect_indexed_kind63_proximity_anim_trigger(
                        ground->model, entry->effect_index, joint, entry->param);
                break;
            default:
                __assert("grpointstrike.c", 0x20, "0");
                panel = NULL;
                break;
            }

            panel_num++;
            if (ground->point_strike_panel_num >= GR_POINT_STRIKE_PANEL_MAX) {
                __assert("grpointstrike.c", 0x3B,
                         "gp->ls.pointStrike.panel_num < Gr_PointStrikePanel_Max");
            }
            ground->point_strike_panels[ground->point_strike_panel_num++] = panel;
            i++;
        }

        offset += sizeof(PointStrikePanelEntry);
        group++;
    }

    if (panel_num != panel_data->stadium_joint_num) {
        __assert("grpointstrike.c", 0x40, "panel_num == panel_data->joint_num");
    }

    panel_num = 0;
    kar_grparts__near_800db1a8(airride_select, GR_POINT_STRIKE_SELECT_MAX);
    group = 0;
    offset = group;
    while (group < panel_data->airride_entry_count) {
        entry = (PointStrikePanelEntry*) ((u8*) panel_data->airride_entries + offset);
        i = 0;
        while (i < entry->count) {
            s32 selected =
                kar_grcommon__800db234(airride_select,
                                        HSD_Randi(panel_data->airride_joint_num -
                                                  panel_num),
                                        GR_POINT_STRIKE_SELECT_MAX);
            s32 joint = panel_data->airride_joints[selected];

            switch (entry->kind) {
            case GR_YAKU_KIND62_COLLISION_TRIGGER:
                panel = kar_gryakubreakhpcoll_create_effect_indexed_kind62_collision_trigger(
                    ground->model, entry->effect_index, joint, entry->param);
                break;
            case GR_YAKU_KIND63_PROXIMITY_ANIM_TRIGGER:
                panel =
                    kar_gryakubreakhpcoll_create_effect_indexed_kind63_proximity_anim_trigger(
                        ground->model, entry->effect_index, joint, entry->param);
                break;
            default:
                __assert("grpointstrike.c", 0x20, "0");
                panel = NULL;
                break;
            }

            panel_num++;
            if (ground->point_strike_panel_num >= GR_POINT_STRIKE_PANEL_MAX) {
                __assert("grpointstrike.c", 0x3B,
                         "gp->ls.pointStrike.panel_num < Gr_PointStrikePanel_Max");
            }
            ground->point_strike_panels[ground->point_strike_panel_num++] = panel;
            i++;
        }

        offset += sizeof(PointStrikePanelEntry);
        group++;
    }

    if (panel_num != panel_data->airride_joint_num) {
        __assert("grpointstrike.c", 0x40, "panel_num == panel_data->joint_num");
    }
}
