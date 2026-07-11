#ifndef _shadow_h_
#define _shadow_h_

#include <dolphin/mtx/mtxtypes.h>

#include <sysdolphin/objalloc.h>

typedef struct _HSD_Shadow {
    struct _HSD_SList* objects; // 0x0
    struct _HSD_CObj* camera; // 0x4
    struct _HSD_TObj* texture; //0x8
    f32 scaleS; // 0xC
    f32 scaleT; // 0x10
    f32 transS; // 0x14
    f32 transT; // 0x18
    BOOL active; // 0x1C
    u8 intensity; // 0x20
    void* user_data; // 0x24
} HSD_Shadow;

typedef struct _HSD_ViewingRect {
    Vec origin;
    Vec up_v;
    Vec right_v;
    Vec eye_v;
    Vec eye_vn;
    f32 distance;
    f32 top;
    f32 bottom;
    f32 left;
    f32 right;
    s8 perspective : 1; // 0x50, bit 0x80
    s8 invalid : 1;     // 0x50, bit 0x40
} HSD_ViewingRect;

void HSD_ShadowInitAllocData(void);
HSD_ObjAllocData* HSD_ShadowGetAllocData(void);
HSD_Shadow* HSD_ShadowAlloc(void);
void HSD_ShadowRemove(HSD_Shadow* shadow);
void HSD_ShadowInit(HSD_Shadow* shadow);
void HSD_ShadowSetSize(HSD_Shadow* shadow, u16 width, u16 height);
void HSD_ShadowStartRender(HSD_Shadow* shadow);
void HSD_ShadowEndRender(HSD_Shadow* shadow);
void HSD_ShadowSetActive(HSD_Shadow* shadow, s32 active);
void HSD_ShadowAddObject(HSD_Shadow* shadow, struct _HSD_Obj* obj);
void HSD_ShadowDeleteObject(HSD_Shadow*, struct _HSD_JObj*);
void HSD_ShadowSetViewingRect(HSD_Shadow* shadow, f32 top, f32 bottom, f32 left, f32 right);

void HSD_ViewingRectInit(HSD_ViewingRect* rect, Vec* position, Vec* interest, Vec* upvector, s32 perspective);
s32 HSD_ViewingRectCheck(HSD_ViewingRect* rect);
void HSD_ViewingRectAddRect(HSD_ViewingRect* rect, Vec* position, f32 top, f32 bottom, f32 left, f32 right);

#endif
