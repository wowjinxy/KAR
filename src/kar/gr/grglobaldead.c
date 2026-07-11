#include "functions.h"
#include <dolphin/mtx/mtxtypes.h>
#include <sysdolphin/memory.h>

typedef struct GlobalDeadConfig GlobalDeadConfig;
typedef struct GlobalDeadEntry GlobalDeadEntry;
typedef struct GlobalDeadQuery GlobalDeadQuery;
typedef struct Ground Ground;
typedef struct GroundData GroundData;

struct GlobalDeadConfig {
    s32* pos_ids;
    s32 count;
};

struct GlobalDeadEntry {
    s32 pos_id;
    u8 pad_4[0x04];
    f32 distance_param;
};

struct GlobalDeadQuery {
    s32 pos_id;
    u8 pad_4[0x04];
    f32 distance_param;
};

struct Ground {
    u8 pad_0[0x08];
    GroundData* data;
    u8 pad_C[0x6FC];
    GlobalDeadConfig* global_dead_config;
    GlobalDeadEntry* global_dead_entries;
};

struct GroundData {
    u8 pad_0[0x4C];
    GlobalDeadConfig* global_dead_config;
};

static const f32 lbl_805DF790 = 3.4028234663852886e38f;
static const f32 lbl_805DF794 = -1.0f;

#if defined(VERSION_GKYP01)
#define GRGLOBALDEAD_ASSERT_COUNT_LINE 0x5D
#else
#define GRGLOBALDEAD_ASSERT_COUNT_LINE 0x59
#endif

s32 kar_grnullpos_get_global_dead_pos_count(void);
void kar_grnullpos_get_global_dead_pos(s32 index, Vec* pos, Vec* dir, Vec* scale);
void kar_grcommon__800ceeb8(Vec* pos, s32 pos_id, GlobalDeadEntry* out);
f32 kar_grcommon__near_800d066c(s32 a, s32 b, f32 c, f32 d);

void kar_grglobaldead_init(Ground* ground)
{
    GlobalDeadConfig* config;
    s32 count;
    s32 i;

    config = ground->data->global_dead_config;
    count = config ? config->count : 0;

    if (count != 0) {
        if (count > kar_grnullpos_get_global_dead_pos_count()) {
            __assert("grglobaldead.c", 0x2C, "num <= grGetGlobalDeadPosNum()");
        }

        ground->global_dead_config = config;
        ground->global_dead_entries = HSD_Alloc(count * sizeof(GlobalDeadEntry));
        for (i = 0; i < count; i++) {
            Vec pos;
            Vec dir;
            Vec scale;

            kar_grnullpos_get_global_dead_pos(i, &pos, &dir, &scale);
            kar_grcommon__800ceeb8(&pos, config->pos_ids[i], &ground->global_dead_entries[i]);
        }
    }
}

void kar_grglobaldead_destroy(Ground* ground)
{
    GlobalDeadConfig* config = ground->data->global_dead_config;
    s32 count;

    if (config != NULL) {
        count = config->count;
    } else {
        count = 0;
    }

    if (count != 0) {
        HSD_Free((void*) ground->global_dead_entries);
    }
}

s32 kar_grglobaldead_find_nearest_index(Ground* ground, GlobalDeadQuery* query)
{
    GlobalDeadConfig* config = ground->data->global_dead_config;
    s32 count;
    s32 offset;
    s32 best_index;
    s32 i;
    f32 no_hit;
    f32 best_dist;

    if (config != NULL) {
        count = config->count;
    } else {
        count = 0;
    }

    best_dist = lbl_805DF790;
    best_index = -1;

    if (count == 0) {
        __assert("grglobaldead.c", GRGLOBALDEAD_ASSERT_COUNT_LINE, "num");
    }

    no_hit = lbl_805DF794;

    i = 0;
    offset = 0;
    while (i < count) {
        GlobalDeadEntry* entry = (GlobalDeadEntry*) ((u8*) ground->global_dead_entries + offset);
        f32 dist = kar_grcommon__near_800d066c(entry->pos_id, query->pos_id,
                                               entry->distance_param, query->distance_param);

        if (no_hit != dist && dist < best_dist) {
            best_dist = dist;
            best_index = i;
        }

        offset += sizeof(GlobalDeadEntry);
        i++;
    }

    if (best_index == -1) {
        best_index = 0;
    }

    return best_index;
}
