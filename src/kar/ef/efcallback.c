#include "functions.h"
#include <dolphin/types.h>

typedef struct EffectEntry EffectEntry;
typedef s32 (*EffectCallback)(EffectEntry*, void*);

extern char lbl_8055D7A0[];
extern char lbl_804B510C[];

s32 kar_efcallback__80234e4c(void* gobj);
void kar_efcallback__near_80235008(void* handle);

EffectEntry* kar_effect__near_80234a04(void* handle, EffectEntry** prev);
EffectEntry* kar_effect__near_802344dc(void* owner, void* particle, s32 arg2,
                                       s32 arg3);
EffectEntry* kar_effect_find_entry_by_owner_key(void* owner, void* key,
                                                EffectEntry** prev);
void kar_effect__802341ec(EffectEntry* entry, EffectEntry* prev);
void kar_effect__near_802349b0(EffectEntry* entry);
void kar_pltrick__near_802341c0(EffectEntry* dst, EffectEntry* src);
s32 kar_pltrick__near_80233ecc(void* obj);
void kar_particle__near_8042b5a8(u8 id, void* particle);
void kar_particle__near_8042ba60(void* particle, void* callbacks);
s32 kar_particle__8042a734(u16 id, void* particle, void* arg2, void* arg3,
                           void* arg4);
void HSD_GObjDestroy(void* gobj);
void OSReport(const char* fmt, ...);

#define GET_U8(base, offset) (*(u8*) ((u8*) (base) + (offset)))
#define GET_U16(base, offset) (*(u16*) ((u8*) (base) + (offset)))
#define GET_U32(base, offset) (*(u32*) ((u8*) (base) + (offset)))
#define GET_PTR(base, offset) (*(void**) ((u8*) (base) + (offset)))
#define GET_F32(base, offset) (*(f32*) ((u8*) (base) + (offset)))

void* lbl_804B4E08[] = {
    kar_efcallback__80234e4c,
    NULL,
    NULL,
};

char kar_src_efcallback_804b4e14[] = "efcallback.c";
char lbl_805D7270[] = "gp";

s32 kar_efcallback__80234e4c(void* gobj)
{
    EffectEntry* entry;
    void* gp;

    gp = GET_PTR(gobj, 0x8C);
    if (gp == NULL) {
        __assert(kar_src_efcallback_804b4e14, 0x24, lbl_805D7270);
    }

    entry = kar_effect__near_80234a04(gp, NULL);
    if (entry == NULL) {
        return 0;
    }

    if (GET_PTR(entry, 0x20) != NULL) {
        kar_particle__near_8042b5a8(GET_U8(entry, 0x24), GET_PTR(entry, 0x20));
        GET_U8(gobj, 0x59) = GET_U8(entry, 0x24);
    }

    if (GET_U8(entry, 0x2C) & 0x80) {
        GET_F32(gobj, 0x2C) = GET_F32(entry, 0x30);
        GET_F32(gobj, 0x30) = GET_F32(entry, 0x34);
        GET_F32(gobj, 0x34) = GET_F32(entry, 0x38);
        GET_U16(gobj, 0x9C) |= 1;
    }

    if (GET_U8(entry, 0x2C) & 0x40) {
        GET_U32(gobj, 0x04) |= 2;
        GET_F32(gobj, 0x3C) = GET_F32(entry, 0x48);
    }

    if (GET_U8(entry, 0x2C) & 0x20) {
        GET_F32(gobj, 0xA0) = GET_F32(entry, 0x3C);
        GET_F32(gobj, 0xA4) = GET_F32(entry, 0x40);
        GET_F32(gobj, 0xA8) = GET_F32(entry, 0x44);
        GET_F32(gobj, 0xAC) = GET_F32(entry, 0x4C);
        GET_U16(gobj, 0x9C) |= 2;
    }

    return 0;
}

void kar_efcallback__near_80234f60(void* handle, void* particle, void* arg2,
                                   void* owner)
{
    EffectEntry* entry;
    EffectEntry* created;
    EffectCallback callback;

    entry = kar_effect__near_80234a04(handle, NULL);
    if (entry != NULL) {
        kar_particle__near_8042ba60(particle, lbl_804B4E08);
        GET_PTR(particle, 0x5C) = kar_efcallback__near_80235008;

        created = kar_effect__near_802344dc(owner, particle, -1, 0);
        if (created != NULL) {
            kar_pltrick__near_802341c0(created, entry);
            callback = GET_PTR(entry, 0x54);
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
        if (GET_PTR(entry, 0x60) != NULL) {
            HSD_GObjDestroy(GET_PTR(entry, 0x60));
        }

        if (GET_U16(entry, 0x26) != 0) {
            GET_PTR(entry, 0x5C) = NULL;
        } else {
            if (GET_PTR(entry, 0x04) != NULL &&
                kar_pltrick__near_80233ecc(GET_PTR(entry, 0x04)) != 0) {
                kar_effect_find_entry_by_owner_key(GET_PTR(entry, 0x10),
                                                   GET_PTR(entry, 0x14), &prev);
            }
            kar_effect__802341ec(entry, prev);
            kar_effect__near_802349b0(entry);
        }
    }
}

s32 kar_efcallback__near_802350a0(s32 bank, void* particle, void* arg2,
                                  void* arg3, void* arg4)
{
    s32 valid;
    u16 version;
    void* particle_ptr = particle;
    void* arg2_ptr = arg2;
    void* arg3_ptr = arg3;
    void* arg4_ptr = arg4;

    if (bank < 0 || bank >= 0x18) {
        return 0;
    }

    version = GET_U16(particle_ptr, 0);
    if (version < 0x43) {
        OSReport(lbl_804B510C, version, 0x43);
        valid = 0;
    } else {
        valid = 1;
    }

    if (valid == 0) {
        return 0;
    }

    kar_particle__8042a734(GET_U16(particle_ptr, 2), particle_ptr, arg2_ptr,
                           arg3_ptr, arg4_ptr);
    return 1;
}

s32 kar_efcallback__near_8023515c(s32 bank, void* table)
{
    void* base;

    if (bank < 0x18 || bank >= 0x25) {
        return 0;
    }

    base = lbl_8055D7A0 + bank * 4;
    GET_PTR(base, 0x24) = table;
    return 1;
}

void* kar_efcallback__near_80235190(s32 id)
{
    s32 bank;
    void* table;

    bank = id / 10000;
    if (bank < 0x18 || bank >= 0x25) {
        return NULL;
    }

    table = GET_PTR(lbl_8055D7A0 + bank * 4, 0x24);
    if (table != NULL) {
        return GET_PTR(table, (id % 10000) * 8);
    }

    return NULL;
}
