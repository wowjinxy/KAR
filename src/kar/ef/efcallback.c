#include "functions.h"
#include <dolphin/types.h>
#include <sysdolphin/gobj.h>

#if defined(VERSION_GKYJ01)
#define lbl_804B4E08 lbl_804AFB50
#define kar_src_efcallback_804b4e14 lbl_804AFB5C
#define lbl_804B510C lbl_804AFE54
#define lbl_8055D7A0 lbl_80558278
#define lbl_805D7270 lbl_805D1CB0
#define kar_pltrick__near_80233ecc fn_8022FE58
#define kar_pltrick__near_802341c0 fn_8023014C
#define kar_effect__802341ec fn_80230178
#define kar_effect_find_entry_by_owner_key fn_80230284
#define kar_effect__near_802344dc fn_80230468
#define kar_effect__near_802349b0 fn_8023093C
#define kar_effect__near_80234a04 fn_80230990
#elif defined(VERSION_GKYP01)
#define lbl_804B4E08 lbl_804BA5F8
#define kar_src_efcallback_804b4e14 lbl_804BA604
#define lbl_804B510C lbl_804BA8FC
#define lbl_8055D7A0 lbl_80550110
#define lbl_805D7270 lbl_805C9C58
#define kar_pltrick__near_80233ecc fn_80234BA8
#define kar_pltrick__near_802341c0 fn_80234E9C
#define kar_effect__802341ec fn_80234EC8
#define kar_effect_find_entry_by_owner_key fn_80234FD4
#define kar_effect__near_802344dc fn_802351B8
#define kar_effect__near_802349b0 fn_8023568C
#define kar_effect__near_80234a04 fn_802356E0
#endif

#include <kar/ef/efcallback.h>
#include <kar/ef/effect.h>
#include <kar/ef/particle.h>
#include <kar/ef/pltrick.h>

extern void* lbl_8055D7A0[];
extern char lbl_804B510C[];

typedef struct EffectGObj {
    u8 pad_00[0x04];
    u32 flags;
    u8 pad_08[0x24];
    f32 position[3];
    u8 pad_38[0x04];
    f32 field_3C;
    u8 pad_40[0x19];
    u8 particle_kind;
    u8 pad_5A[0x32];
    void* gp;
    u8 pad_90[0x0C];
    u16 transform_flags;
    u8 pad_9E[0x02];
    f32 scale[3];
    f32 field_AC;
} EffectGObj;

typedef struct ParticleInstance {
    u8 pad_00[0x5C];
    void (*destroy_callback)(void*);
} ParticleInstance;

typedef struct ParticleBankData {
    u16 version;
    u16 resource_id;
} ParticleBankData;

typedef struct EffectAnimResourceTableEntry {
    EffectAnimResource* resource;
    u8 pad_04[0x04];
} EffectAnimResourceTableEntry;

void* lbl_804B4E08[] = {
    kar_efcallback__80234e4c,
    NULL,
    NULL,
};

char kar_src_efcallback_804b4e14[] = "efcallback.c";
char lbl_805D7270[] = "gp";

s32 kar_efcallback__80234e4c(void* gobj)
{
    EffectGObj* effect_gobj = gobj;
    EffectEntry* entry;
    void* gp;

    gp = effect_gobj->gp;
    if (gp == NULL) {
        __assert(kar_src_efcallback_804b4e14, 0x24, lbl_805D7270);
    }

    entry = kar_effect__near_80234a04(gp, NULL);
    if (entry == NULL) {
        return 0;
    }

    if (entry->particle != NULL) {
        kar_particle__near_8042b5a8(entry->particle_kind, entry->particle);
        effect_gobj->particle_kind = entry->particle_kind;
    }

    if ((entry->flags >> 7) & 1) {
        effect_gobj->position[0] = entry->position[0];
        effect_gobj->position[1] = entry->position[1];
        effect_gobj->position[2] = entry->position[2];
        effect_gobj->transform_flags |= 1;
    }

    if ((entry->flags >> 6) & 1) {
        effect_gobj->flags |= 2;
        effect_gobj->field_3C = entry->field_48;
    }

    if ((entry->flags >> 5) & 1) {
        effect_gobj->scale[0] = entry->scale[0];
        effect_gobj->scale[1] = entry->scale[1];
        effect_gobj->scale[2] = entry->scale[2];
        effect_gobj->field_AC = entry->field_4C;
        effect_gobj->transform_flags |= 2;
    }

    return 0;
}

void kar_efcallback__near_80234f60(void* handle, void* particle, void* arg2,
                                   void* owner)
{
    ParticleInstance* instance = particle;
    EffectEntry* entry;
    EffectEntry* created;
    EffectCallback callback;

    entry = kar_effect__near_80234a04(handle, NULL);
    if (entry != NULL) {
        kar_particle__near_8042ba60(particle, lbl_804B4E08);
        instance->destroy_callback = kar_efcallback__near_80235008;

        created = kar_effect__near_802344dc(owner, particle, -1, 0);
        if (created != NULL) {
            kar_pltrick__near_802341c0(created, entry);
            callback = entry->callback;
            if (callback != NULL) {
                callback(created, owner);
            }
        }
    }
}

void kar_efcallback__near_80235008(void* handle)
{
    EffectEntry* entry;
    EffectEntry* prev;

    entry = kar_effect__near_80234a04(handle, &prev);
    if (entry != NULL) {
        if (entry->gobj != NULL) {
            HSD_GObjDestroy(entry->gobj);
        }

        if (entry->reference_count != 0) {
            entry->particle_handle = NULL;
        } else {
            if (entry->pltrick != NULL &&
                kar_pltrick__near_80233ecc(entry->pltrick) != 0) {
                kar_effect_find_entry_by_owner_key(entry->owner, entry->key,
                                                   &prev);
            }
            kar_effect__802341ec(entry, prev);
            kar_effect__near_802349b0(entry);
        }
    }
}

s32 kar_efcallback__near_802350a0(s32 bank, void* particle, void* arg2,
                                  void* arg3, void* arg4)
{
    ParticleBankData* data = particle;
    s32 valid;
    u16 version;
    void* particle_ptr = particle;
    void* arg2_ptr = arg2;
    void* arg3_ptr = arg3;
    void* arg4_ptr = arg4;

    if (bank < 0 || bank >= 0x18) {
        return 0;
    }

    version = data->version;
    if ((s32) version < 0x43) {
        OSReport(lbl_804B510C, version, 0x43);
        valid = 0;
    } else {
        valid = 1;
    }

    if (valid == 0) {
        return 0;
    }

    kar_particle__8042a734(data->resource_id, particle_ptr, arg2_ptr,
                           arg3_ptr, arg4_ptr);
    return 1;
}

s32 kar_efcallback__near_8023515c(s32 bank, void* table)
{
    if (bank < 0x18 || bank >= 0x25) {
        return 0;
    }

    lbl_8055D7A0[bank + 9] = table;
    return 1;
}

EffectAnimResource* kar_efcallback__near_80235190(s32 id)
{
    s32 bank;
    void* table;

    bank = id / 10000;
    if (bank < 0x18 || bank >= 0x25) {
        return NULL;
    }

    table = lbl_8055D7A0[bank + 9];
    if (table != NULL) {
        EffectAnimResourceTableEntry* entries = table;
        return entries[id % 10000].resource;
    }

    return NULL;
}
