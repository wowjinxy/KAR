#ifndef __EFFECT_H_
#define __EFFECT_H_

#include <dolphin/types.h>

typedef struct EffectEntry EffectEntry;

EffectEntry* kar_effect__near_80234a04(void* handle, EffectEntry** prev);
EffectEntry* kar_effect__near_802344dc(void* owner, void* particle, s32 arg2,
                                       s32 arg3);
EffectEntry* kar_effect_find_entry_by_owner_key(void* owner, void* key,
                                                EffectEntry** prev);
void kar_effect__802341ec(EffectEntry* entry, EffectEntry* prev);
void kar_effect__near_802349b0(EffectEntry* entry);

#endif
