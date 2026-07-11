#ifndef _gobj_h_
#define _gobj_h_

#include <dolphin/types.h>

#include <sysdolphin/objalloc.h>

#define HSD_GOBJ_GXLINK_NONE 0xFF
#define HSD_GOBJ_OBJ_NONE 0xFF

typedef struct _HSD_GObj {
    u16 classifier;
    u8 p_link;
    u8 gx_link;
    u8 p_priority;
    u8 render_priority;
    u8 obj_kind;
    u8 user_data_kind;
    struct _HSD_GObj* next; //0x08
    struct _HSD_GObj* prev; //0x0C
    struct _HSD_GObj* next_gx; //0x10
    struct _HSD_GObj* prev_gx; //0x14
    struct _HSD_GObjProc* proc; //0x18
    void (*render_cb)(struct _HSD_GObj* gobj, s32 code); //0x1C
    u64 gxlink_prios; //x20
    void* hsd_obj;  //x28
    void* user_data;  //x2C
    void (*user_data_remove_func)(void* data);  ///x30
    void* x34_unk;
} HSD_GObj;

typedef struct _HSD_GObjProc {
    struct _HSD_GObjProc* child; //0x0
    struct _HSD_GObjProc* next; //0x4
    struct _HSD_GObjProc* prev; //0x8
    u8 s_link; //0xC
    u8 flags_1:1; //0xD
    u8 flags_2:1;
    u8 flags_3:2;
    u8 flags_4:2;
    struct _HSD_GObj* gobj; //0x10
    void (*callback)(struct _HSD_GObj*); //0x14
} HSD_GObjProc;

typedef void (*GObjFunc)(struct _HSD_Obj*);

typedef struct _GObjFuncs {
    struct _GObjFuncs* next;
    u8 size;
    GObjFunc* funcs;
    u32 pad;
} GObjFuncs;

typedef struct _HSD_GObjLibInitDataType {
    u8 p_link_max; //804CE380
    u8 gx_link_max; //804CE381
    u8 gproc_pri_max; //804CE382
    u8 pad;
    GObjFuncs* funcs; //804CE384
    u64* unk_2; //804CE388
} HSD_GObjLibInitDataType;

typedef struct _HSD_GObjDeferredActionFlags {
    union {
        u32 flags;
        struct {
            u32 b0 : 1;
            u32 b1 : 1;
            u32 b2 : 1;
            u32 b3 : 1;
        };
    };
    s32 type;
    u8 p_link;
    u8 p_prio;
    u8 pad[2];
    HSD_GObj* gobj;
    u32 unused;
} HSD_GObjDeferredActionFlags;

extern HSD_GObjLibInitDataType hsdGObj_p_link_max;
extern HSD_ObjAllocData hsdGObj_alloc_data;
extern HSD_ObjAllocData hsdGObjProc_alloc_data;
extern HSD_GObjDeferredActionFlags hsdGObj_deferred_action_flags;

extern u8 hsdGObj_default_object_kind;
extern u8 hsdGObj_lobj_kind;
extern u8 hsdGObj_jobj_kind;
extern u8 hsdGObj_default_object_alt_kind;

extern HSD_GObjProc** hsdGObjProc_link_heads;
extern HSD_GObjProc** hsdGObjProc_priority_heads;
extern s32 hsdGObjProc_run_id;
extern HSD_GObjProc* hsdGObjProc_current;
extern s32 hsdGObjProc_current_s_link;
extern HSD_GObjProc* hsdGObjProc_next;

extern HSD_GObj** hsdGObj_p_link_heads;
extern HSD_GObj** hsdGObj_p_link_tails;
extern HSD_GObj** hsdGObj_gx_link_heads;
extern HSD_GObj** hsdGObj_gx_link_tails;
extern HSD_GObj* hsdGObj_current;
extern HSD_GObj* hsdGObj_current_gx;
extern HSD_GObj* hsdGObj_current_render;
extern GObjFunc* hsdGObj_obj_remove_funcs;

void func_80390C5C(HSD_GObj* gobj);
void func_80390C84(HSD_GObj* gobj);
void func_80390CAC(HSD_GObj* gobj);

void HSD_GObjObjectLink(HSD_GObj* gobj, u8 kind, void* obj);
void* HSD_GObjObjectUnlink(HSD_GObj* gobj);
void HSD_GObjObjectRemove(HSD_GObj* gobj);
HSD_GObj* HSD_GObjCreate(u16 classifier, u8 p_link, u8 priority);
HSD_GObj* HSD_GObjGXLink(HSD_GObj* gobj, void (*render_cb)(HSD_GObj*, s32),
                         u8 gx_link, u8 priority);
void HSD_GObjGXLinkRemove(HSD_GObj* gobj);
void HSD_GObjPLinkChange_Internal(s32 type, HSD_GObj* gobj, u8 p_link,
                                  u8 priority, HSD_GObj* position);
HSD_GObjProc* HSD_GObjProcCreate(HSD_GObj* gobj,
                                 void (*callback)(HSD_GObj*), u8 priority);
void HSD_GObjProcRemove(HSD_GObjProc* proc);
void HSD_GObjProcRemoveAll(HSD_GObj* gobj);
void HSD_GObjDestroy(HSD_GObj* gobj);
u32 GObj_GetFlagFromArray(s32 i);
void GObj_SetTextureCamera(HSD_GObj* gobj, u32 mask);
void GObj_RunGXLinkMaxCallbacks(void);
void GObj_SetCamera(HSD_GObj* gobj);

#endif
