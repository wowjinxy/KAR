#ifndef __EFCALLBACK_H_
#define __EFCALLBACK_H_

#include <dolphin/types.h>
#include <kar/ef/effect.h>

typedef struct EffectAnimResource EffectAnimResource;
typedef s32 (*EffectCallback)(EffectEntry*, void*);

struct EffectAnimResource {
    u8 pad_00[0x04];
    void** joint_anims;
    void** mat_anims;
    void** shape_anims;
};

s32 kar_efcallback__80234e4c(void* gobj);
void kar_efcallback__near_80234f60(void* handle, void* particle, void* arg2,
                                   void* owner);
void kar_efcallback__near_80235008(void* handle);
s32 kar_efcallback__near_802350a0(s32 bank, void* particle, void* arg2,
                                  void* arg3, void* arg4);
s32 kar_efcallback__near_8023515c(s32 bank, void* table);
EffectAnimResource* kar_efcallback__near_80235190(s32 id);

#endif
