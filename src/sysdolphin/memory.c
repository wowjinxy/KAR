#include <dolphin/types.h>

#include <sysdolphin/cobj.h>
#include <sysdolphin/memory.h>
#include <sysdolphin/mobj.h>
#include <sysdolphin/objalloc.h>
#include <sysdolphin/shadow.h>
#include <sysdolphin/tobj.h>

typedef struct _HSD_MemCallbackData {
    HSD_MemCallbacks callbacks;
    u32 unused;
} HSD_MemCallbackData;

extern void HSD_CObjSetViewportfx4(HSD_CObj* cobj, f32 left, f32 right, f32 top, f32 bottom);
extern void HSD_CObjSetScissorx4(HSD_CObj* cobj, s32 left, u16 right, s32 top, u16 bottom);
extern HSD_CObj* HSD_CObjAlloc(void);
extern void HSD_ImageDescRemove(HSD_ImageDesc* idesc);
extern void HSD_TObjRemove(HSD_TObj* tobj);

char MemorySourceFile[] = "memory.c";
char MemoryAssertCallbackSize[] = "size == sizeof(__mem_cb)";

HSD_MemCallbackData HSD_MemCallbackState;
u8 HSD_ShadowAllocData[0x30];
u8 hsd_saved_context[0x2C8];

extern const f32 ShadowHalf;
extern const f32 ShadowNegHalf;
extern const f32 ShadowZero;
extern const f32 ShadowTextureSize;

#define SHADOW_ALLOC_DATA ((HSD_ObjAllocData*) HSD_ShadowAllocData)

void _HSD_MemSetCallbacks(HSD_MemCallbacks* callbacks, u32 size)
{
    if (size != sizeof(HSD_MemCallbacks)) {
        __assert(MemorySourceFile, 0x14, MemoryAssertCallbackSize);
    }
    HSD_MemCallbackState.callbacks = *callbacks;
}

void* _HSD_MemAlloc(u32 size, u32 align, u32 flags)
{
    return HSD_MemCallbackState.callbacks.alloc(size, align, flags);
}

u32 _HSD_MemGetRemain(void)
{
    return HSD_MemCallbackState.callbacks.get_remain();
}

void _HSD_MemClear(void)
{
    HSD_MemCallbackState.callbacks.clear();
}

s32 _HSD_MemCheckOwn(void* ptr)
{
    return HSD_MemCallbackState.callbacks.check_own(ptr);
}

#pragma push
#pragma dont_inline on
void HSD_Free(void* ptr)
{
    HSD_MemCallbackState.callbacks.free(ptr);
}

void* HSD_Alloc(u32 size)
{
    return HSD_MemCallbackState.callbacks.alloc(size, 0x20, 0);
}
#pragma pop

HSD_ObjAllocData* HSD_ShadowGetAllocData(void)
{
    return SHADOW_ALLOC_DATA;
}

void HSD_ShadowInitAllocData(void)
{
    HSD_ObjAllocInit(SHADOW_ALLOC_DATA, sizeof(HSD_Shadow), 4);
}

HSD_Shadow* HSD_ShadowAlloc(void)
{
    HSD_Shadow* shadow;
    HSD_TObj* tobj;

    shadow = HSD_ObjAlloc(SHADOW_ALLOC_DATA);
    memset(shadow, 0, sizeof(HSD_Shadow));
    shadow->camera = HSD_CObjAlloc();
    tobj = HSD_TObjAlloc();
    tobj->src = 0;
    tobj->wrap_s = 0;
    tobj->wrap_t = 0;
    tobj->flags = 0x540103;
    tobj->imagedesc = HSD_ImageDescAlloc();
    shadow->texture = tobj;
    shadow->scaleS = ShadowHalf;
    shadow->scaleT = ShadowNegHalf;
    shadow->transS = ShadowHalf;
    shadow->transT = ShadowHalf;
    shadow->intensity = 0;
    shadow->texture->imagedesc->format = 0;
    shadow->texture->imagedesc->width = 0x100;
    shadow->texture->imagedesc->height = 0x100;
    {
        f32 lo = ShadowZero;
        f32 hi = ShadowTextureSize;
        HSD_CObjSetViewportfx4(shadow->camera, lo, hi, lo, hi);
    }
    HSD_CObjSetScissorx4(shadow->camera, 0, 0x100, 0, 0x100);
    return shadow;
}

__declspec(section ".sdata2") const f32 ShadowHalf = 0.5F;
__declspec(section ".sdata2") const f32 ShadowNegHalf = -0.5F;
__declspec(section ".sdata2") const f32 ShadowZero = 0.0F;
__declspec(section ".sdata2") const f32 ShadowTextureSize = 256.0F;

static inline BOOL decref(HSD_Obj* obj)
{
    u16 ref_count = obj->ref_count;
    BOOL noref = ref_count == 0xffff;
    if (noref) {
        return noref;
    }
    obj->ref_count--;
    return ref_count == 0;
}

void HSD_ShadowRemove(HSD_Shadow* shadow)
{
    HSD_CObj* camera;
    HSD_TObj* tobj;

    if (shadow == NULL) {
        return;
    }
    camera = shadow->camera;
    if (camera != NULL) {
        if (decref((HSD_Obj*) camera) && camera != NULL) {
            camera->parent.parent.class_info->release((HSD_Class*) camera);
            camera->parent.parent.class_info->destroy((HSD_Class*) camera);
        }
    }
    HSD_ShadowDeleteObject(shadow, 0);
    if (shadow->active) {
        HSD_MObjDeleteShadowTexture(shadow->texture);
    }
    if (shadow->texture->imagedesc->img_ptr != NULL) {
        HSD_Free(shadow->texture->imagedesc->img_ptr);
    }
    tobj = shadow->texture;
    HSD_ImageDescRemove(tobj->imagedesc);
    HSD_TObjRemove(tobj);
    HSD_ObjFree(SHADOW_ALLOC_DATA, shadow);
}
