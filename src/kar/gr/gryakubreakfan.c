#include "functions.h"
#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>
#include <kar/gr/gryaku.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/jobj.h>
#include <sysdolphin/memory.h>

typedef struct Ground Ground;
typedef struct GroundJObjEntry GroundJObjEntry;
typedef struct Yaku Yaku;
typedef struct YakuParamLink YakuParamLink;
typedef struct BreakFanParam BreakFanParam;
typedef struct FgmEntry FgmEntry;
typedef void (*GroundCallback)(void);

struct FgmEntry {
    u8 pad[0x08];
};

struct Ground {
    u8 pad_0[0x104];
    GroundJObjEntry* jobjs;
};

struct GroundJObjEntry {
    HSD_JObj* jobj;
    u8 pad[0x04];
};

struct Yaku {
    u8 pad_00[0x08];
    YakuParamLink* param_link;
    u8 pad_0C[0xE0];
    void* collision_object;
    u8 pad_F0[0x28];
    FgmEntry break_fgm_entry;
    u8 pad_120[0x10];
    u64 effect_keys[4];
    s32* fgm_handles;
};

struct YakuParamLink {
    BreakFanParam* param;
};

struct BreakFanParam {
    s32 joint_index;
    s32 effect_resource;
    u8 pad_08[0x04];
    void* path_nodes;
    u8 pad_10[0x04];
    void* effect_entries;
    s32 remove_effect_count;
    s32 hide_joint;
};

#define YAKU_EFFECT_ALLOC(yaku) (*(void**) ((u8*) (yaku) + 0x130))
#define FGM_ENTRY_COUNT(entry) (*(s32*) ((u8*) (entry) + 0x04))

#if defined(VERSION_GKYJ01)
#define GRYAKUBREAKFAN_ASSERT_REMOVE_EFFECT_COUNT_LINE 0xA1
#elif defined(VERSION_GKYP01)
#define GRYAKUBREAKFAN_ASSERT_REMOVE_EFFECT_COUNT_LINE 0xA9
#else
#define GRYAKUBREAKFAN_ASSERT_REMOVE_EFFECT_COUNT_LINE 0xA1
#endif

#define GRYAKUBREAKFAN_PATH_START 0.0F
#define GRYAKUBREAKFAN_PATH_END 1.0F

char kar_src_gryakubreakfan_c[] = "gryakubreakfan.c";
char kar_gryakubreakfan_assert_remove_effect_count[] =
    "param->efBreakNum <= GrYakuBreakFan_RemoveEffectIdNumMax";

void kar_gryakubreakfloor_configure_kind30_breakfan_fgm(HSD_GObj* gobj);
void kar_gryakubreakfloor_update_kind30_breakfan_effects_then_destroy(HSD_GObj* gobj);
void kar_collision_object_begin_disable(void* collision_object);
u64 kar_gryakueffect_request_by_entry_mode(HSD_GObj* gobj, void* effect_entry,
                                           s32 effect_resource, s32 arg3, s32 arg4,
                                           Vec* pos, s32 arg6);
void kar_graudio_play_fgm_entry_id(FgmEntry* entry, s32 id);
void kar_gryaku_set_path_node_motion(Yaku* yaku, s32 arg1, void* path_nodes,
                                     s32 joint_index, s32 arg4, f32 start, f32 end,
                                     f32 arg7);
void kar_graudio_release_fgm_track_group_handle(s32 handle);

GroundCallback kar_gryakubreakfloor_kind30_breakfan_callback_table[] = {
    (GroundCallback) kar_gryakubreakfloor_configure_kind30_breakfan_fgm,
    NULL,
    NULL,
    NULL,
    (GroundCallback) kar_gryakubreakfloor_update_kind30_breakfan_effects_then_destroy,
    NULL,
    NULL,
    NULL,
};

void* kar_gryakubreakfloor_kind30_breakfan_callback_table_ptr[] = {
    kar_gryakubreakfloor_kind30_breakfan_callback_table,
    NULL,
    NULL,
    NULL,
    NULL,
};

void kar_gryakubreakfan_trigger_kind30_break_effects_from_event(HSD_GObj* gobj,
                                                               void** event_ptr)
{
    void* event = *event_ptr;
    s32 event_kind = *(u16*) event;

    if (event_kind == 0x10 || event_kind == 0x11) {
        Vec pos;
        s32 i;
        BreakFanParam* param;
        Yaku* yaku;
        s32 entry_offset;
        Yaku* slot;
        Ground* ground;
        f32 start;

        switch (event_kind) {
        case 0x10:
            fn_801C7628(event, &pos);
            break;
        case 0x11:
            fn_80191B4C(event, &pos);
            break;
        }

        yaku = gobj->user_data;
        ground = kar_gryaku_current_ground;
        param = yaku->param_link->param;
        if (param->hide_joint != 0) {
            HSD_JObjSetFlagsAll(ground->jobjs[param->joint_index].jobj, 0x10);
        }

        kar_collision_object_begin_disable(yaku->collision_object);

        if (param->remove_effect_count > 3) {
            __assert(kar_src_gryakubreakfan_c, GRYAKUBREAKFAN_ASSERT_REMOVE_EFFECT_COUNT_LINE,
                     kar_gryakubreakfan_assert_remove_effect_count);
        }

        i = 0;
        slot = yaku;
        entry_offset = i;
        while (i < param->remove_effect_count) {
            slot->effect_keys[0] =
                kar_gryakueffect_request_by_entry_mode(gobj,
                                                       (u8*) param->effect_entries + entry_offset,
                                                       param->effect_resource, 0, 0, &pos, 0);
            entry_offset += 0x1C;
            i++;
            slot = (Yaku*) ((u8*) slot + 0x08);
        }

        if (FGM_ENTRY_COUNT(&yaku->break_fgm_entry) > 0) {
            kar_graudio_play_fgm_entry_id(&yaku->break_fgm_entry, 0);
        }

        start = GRYAKUBREAKFAN_PATH_START;
        kar_gryaku_set_path_node_motion(yaku, 1, param->path_nodes, param->joint_index, 0, start,
                                        GRYAKUBREAKFAN_PATH_END, start);
    }
}

void kar_gryakubreakfan_cleanup_shared_allocs_and_fgm_handles(HSD_GObj* gobj)
{
    Yaku* yaku = gobj->user_data;
    BreakFanParam* param = yaku->param_link->param;
    s32* handles;
    s32 i;

    HSD_Free(YAKU_EFFECT_ALLOC(yaku));

    if (yaku->fgm_handles != NULL) {
        for (i = 0; i < param->effect_resource; i++) {
            s32 handle = yaku->fgm_handles[i];

            if (((u32) ((-1 - handle) | (handle + 1)) >> 31) != 0) {
                kar_graudio_release_fgm_track_group_handle(handle);
                yaku->fgm_handles[i] = -1;
            }
        }

        handles = yaku->fgm_handles;
        HSD_Free(handles);
    }
}
