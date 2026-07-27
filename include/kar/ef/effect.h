#ifndef __EFFECT_H_
#define __EFFECT_H_

#include <dolphin/types.h>

typedef struct EffectEntry EffectEntry;

struct EffectEntry {
    u8 pad_00[0x04];
    void* pltrick;
    u8 pad_08[0x08];
    void* owner;
    void* key;
    u8 pad_18[0x08];
    void* particle;
    u8 particle_kind;
    u8 pad_25;
    u16 reference_count;
    u8 pad_28[0x04];
    u8 flags;
    u8 pad_2D[0x03];
    f32 position[3];
    f32 scale[3];
    f32 field_48;
    f32 field_4C;
    u8 pad_50[0x04];
    s32 (*callback)(EffectEntry*, void*);
    u8 pad_58[0x04];
    void* particle_handle;
    void* gobj;
};

EffectEntry* kar_effect__near_80234a04(void* handle, EffectEntry** prev);
EffectEntry* kar_effect__near_802344dc(void* owner, void* particle, s32 arg2,
                                       s32 arg3);
EffectEntry* kar_effect_find_entry_by_owner_key(void* owner, void* key,
                                                EffectEntry** prev);
void kar_effect__802341ec(EffectEntry* entry, EffectEntry* prev);
void kar_effect__near_802349b0(EffectEntry* entry);

#endif
