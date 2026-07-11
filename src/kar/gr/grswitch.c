#include "functions.h"
#include <dolphin/types.h>
#include <sysdolphin/gobj.h>

#define GR_SWITCH_ZONE_COUNT 8
#define GR_SWITCH_ENTRY_COUNT 6

typedef struct Ground Ground;
typedef struct GroundMapObject GroundMapObject;
typedef struct GrSwitchParam GrSwitchParam;
typedef struct GrSwitchEntry GrSwitchEntry;
typedef struct GrSwitchZone GrSwitchZone;
typedef struct GrSwitchAll GrSwitchAll;
typedef void (*GrSwitchCallback)(HSD_GObj* gobj, s32 ref_id);

struct GrSwitchParam {
    s32 ref_id;
    s32 func_id;
    s32 timer;
    s32 fgm_id;
};

struct GroundMapObject {
    u8 pad_000[0x24];
    u32 kind;
    u8 pad_028[0x110];
    GrSwitchParam* switch_param;
    u8 pad_13C[0x04];
};

struct GrSwitchEntry {
    HSD_GObj* gobj;
    s32 timer;
};

struct GrSwitchZone {
    GrSwitchCallback callback;
    s32 object_index;
    void* target;
    s32 active;
    s32 head;
    s32 tail;
    GrSwitchEntry entries[GR_SWITCH_ENTRY_COUNT];
};

struct GrSwitchAll {
    GrSwitchZone zones[GR_SWITCH_ZONE_COUNT];
    s32 zone_num;
};

struct Ground {
    u8 pad_000[0x74];
    GroundMapObject* map_objects;
    s32 map_object_count;
    u8 pad_07C[0x194];
    GrSwitchAll switch_all;
};

extern Ground* kar_gryaku_current_ground;

void kar_graudio_play_map_fgm_for_rider(Ground* ground, s32 rider_index,
                                        s32 fgm_id, s32 arg3, s32 arg4);

char kar_src_grswitch_804a4ee0[0x74] =
    "grswitch.c\0\0"
    "0 <= param->refId && param->refId < GrSwitchZone_Num\0\0\0\0"
    "0 <= param->funcId && param->funcId < funcNum";
char lbl_804A4F54[] =
    "0 <= param->refId && param->refId < switchAll->zoneNum";

void kar_grswitch__800e85a8(Ground* ground, GrSwitchCallback* callbacks,
                            s32 func_num)
{
    Ground* global_ground;
    GrSwitchAll* switch_all;
    char* assert_base;
    s32 object_offset;
    s32 object_index;

    global_ground = kar_gryaku_current_ground;
    assert_base = kar_src_grswitch_804a4ee0;
    switch_all = &ground->switch_all;
    object_index = 0;
    object_offset = 0;

    while (object_index < global_ground->map_object_count) {
        GroundMapObject* map_object =
            (GroundMapObject*) ((u8*) global_ground->map_objects +
                                object_offset);
        s32 kind = map_object->kind & 0x01FFFFFF;

        if (kind == 0xC || kind == 0xD) {
            GrSwitchParam* param = map_object->switch_param;
            s32 valid;

            valid = 0;
            if (param->ref_id >= 0 && param->ref_id < GR_SWITCH_ZONE_COUNT) {
                valid = 1;
            }
            if (valid == 0) {
                __assert(assert_base, 0x41, assert_base + 0x0C);
            }

            valid = 0;
            if (param->func_id >= 0 && param->func_id < func_num) {
                valid = 1;
            }
            if (valid == 0) {
                __assert(assert_base, 0x42, assert_base + 0x44);
            }

            switch_all->zones[param->ref_id].callback =
                callbacks[param->func_id];
            switch_all->zones[param->ref_id].object_index = object_index;
            switch_all->zone_num++;
        }

        object_offset += sizeof(GroundMapObject);
        object_index++;
    }
}

void kar_grswitch__near_800e86cc(Ground* ground, void* target, s32 zone_id)
{
    ground->switch_all.zones[zone_id].target = target;
}

void kar_grswitch__800e86dc(HSD_GObj* gobj, s32 object_index)
{
    Ground* ground;
    GroundMapObject* map_object;
    GrSwitchParam* param;
    GrSwitchAll* switch_all;
    GrSwitchZone* zone;
    s32 valid;
    s32 slot;

    ground = kar_gryaku_current_ground;
    map_object = (GroundMapObject*) ((u8*) ground->map_objects +
                                     object_index * sizeof(GroundMapObject));
    switch_all = &ground->switch_all;
    param = map_object->switch_param;

    valid = 0;
    if (param->ref_id >= 0 && param->ref_id < switch_all->zone_num) {
        valid = 1;
    }

    if (valid == 0) {
        __assert(kar_src_grswitch_804a4ee0, 0x6F, lbl_804A4F54);
    }

    zone = &switch_all->zones[param->ref_id];
    slot = zone->head;
    while (slot != zone->tail) {
        if (zone->entries[slot].gobj == gobj) {
            break;
        }
        slot = (slot + 1) % GR_SWITCH_ENTRY_COUNT;
    }

    if (slot == zone->tail) {
        if ((zone->tail + 1) % GR_SWITCH_ENTRY_COUNT != zone->head) {
            zone->entries[zone->tail].gobj = gobj;
            zone->entries[zone->tail].timer = param->timer;
            zone->tail++;
            zone->tail %= GR_SWITCH_ENTRY_COUNT;
        }

        if (zone->active == 0) {
            zone->callback(gobj, param->ref_id);
            if (param != NULL && param->fgm_id >= 0) {
                kar_graudio_play_map_fgm_for_rider(ground, object_index,
                                                   param->fgm_id, 0, 0);
            }
            zone->active = 1;
        }
    }
}

void kar_grswitch__near_800e8888(Ground* ground)
{
    GrSwitchAll* switch_all;
    GrSwitchZone* zone;
    s32 zone_index;

    switch_all = &ground->switch_all;
    zone = switch_all->zones;
    zone_index = 0;

    while (zone_index < switch_all->zone_num) {
        s32 slot = zone->head;

        while (slot != zone->tail) {
            GrSwitchEntry* entry = &zone->entries[slot];

            if (entry->gobj != NULL) {
                if (entry->timer > 0) {
                    entry->timer--;
                }

                if (entry->timer <= 0) {
                    entry->gobj = NULL;
                    entry->timer = 0;
                    zone->head++;
                    zone->head %= GR_SWITCH_ENTRY_COUNT;
                }
            }

            slot = (slot + 1) % GR_SWITCH_ENTRY_COUNT;
        }

        zone->active = 0;
        zone_index++;
        zone++;
    }
}
