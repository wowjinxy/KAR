#include "functions.h"
#include <sysdolphin/objalloc.h>

typedef struct VecBits {
    u32 x;
    u32 y;
    u32 z;
} VecBits;

typedef struct AreaLight {
    u8 pad_0[0x34];
    struct AreaLightZone* zone;
} AreaLight;

typedef struct AreaLightZoneDesc {
    u8 pad_0[0x2C];
    f32 unk_2C;
    VecBits vec_30;
    u8 unk_3C;
} AreaLightZoneDesc;

typedef struct AreaLightZone {
    u8 pad_0[0x24];
    f32 unk_24;
    VecBits vec_28;
    u8 unk_34;
} AreaLightZone;

typedef struct ObjAllocDataStorage {
    HSD_ObjAllocData alloc;
    u8 pad_2C[4];
} ObjAllocDataStorage;

// This TU owns the contiguous allocator storage from 0x80552978 to
// 0x80552A30. MWCC emits BSS in reverse declaration order, so keep these
// declarations in address-descending order.
ObjAllocDataStorage lbl_80552A00;
ObjAllocDataStorage lbl_805529D0;
HSD_ObjAllocData lbl_805529A4;
HSD_ObjAllocData lbl_80552978;

void* kar_lbhvqm__near_80079428(s32 kind, void* desc, void* data);
void kar_lbarealight__80079518(AreaLight* light);
void kar_lbarealight__800797a8();
void kar_lbarealightuser__near_8007a7e0(void* arg0, void* arg1, u8 kind, void* arg3);

void* kar_lbarealightzone__8007ac30(AreaLightZoneDesc* zone_desc)
{
    AreaLightZone* zone = HSD_ObjAlloc(&lbl_805529A4);

    if (zone_desc == NULL) {
        __assert("lbarealightzone.c", 25, "zone_desc");
    }

    zone->unk_24 = zone_desc->unk_2C;
    zone->vec_28 = zone_desc->vec_30;
    zone->unk_34 = zone_desc->unk_3C;
    return kar_lbhvqm__near_80079428(3, zone_desc, zone);
}

void kar_lbarealightzone__near_8007acc8(AreaLight* light)
{
    HSD_ObjFree(&lbl_805529A4, light->zone);
    kar_lbarealight__80079518(light);
}

void kar_lbarealightzone__near_8007ad08(void* arg0, AreaLight** light_ref, void* arg2)
{
    AreaLight* light = *light_ref;
    kar_lbarealightuser__near_8007a7e0(arg0, light_ref, light->zone->unk_34, arg2);
}

void kar_lbarealightzone__near_8007ad38(AreaLight* light, VecBits* vec)
{
    light->zone->vec_28 = *vec;
}

void kar_lbarealightzone__near_8007ad58(void* arg0, AreaLightZoneDesc* zone_desc, AreaLight* light)
{
    AreaLightZone* zone = light->zone;

    kar_lbarealight__800797a8(arg0, zone_desc, light);
    zone->unk_24 = zone_desc->unk_2C;
    zone->vec_28 = zone_desc->vec_30;
    zone->unk_34 = zone_desc->unk_3C;
}

void kar_lbarealightzone__near_8007adb8(void)
{
    HSD_ObjAllocInit(&lbl_80552A00.alloc, 0x24, 4);
}
