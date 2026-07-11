#include <sysdolphin/gobj.h>
#include <sysdolphin/gobjuserdata.h>
#include <sysdolphin/cobj.h>
#include <sysdolphin/jobj.h>
#include <sysdolphin/lobj.h>
#include <sysdolphin/memory.h>
#include <sysdolphin/object.h>

typedef struct _GObjDefaultInitData {
    u8 p_link_max;
    u8 gx_link_max;
    u8 gproc_pri_max;
    u8 pad;
    GObjFuncs* funcs;
    u64* unk_2;
    u32 unused;
} GObjDefaultInitData;

extern void HSD_LObjSetCurrentAll(void* obj);
extern void HSD_LObjSetupInit(HSD_CObj* cobj);
extern void HSD_LObjRemoveAll(void* obj);
extern void HSD_JObjDispAll(HSD_JObj* jobj, void* arg1, u32 flags, u32 rendermode);
extern s32 HSD_CObjSetCurrent(void* cobj);
extern void HSD_CObjEndCurrent(void);
extern void RecalcParentTrspBits(void* obj);

char GObjUserDataSourceFile[0x10] = "gobjuserdata.c";
char GObjUserDataKindNoneAssert[0x30] = "gobj->user_data_kind == HSD_GOBJ_USER_DATA_NONE";
char GObjUserDataRemoveFuncAssert[0x20] = "gobj->user_data_remove_func";

u32 hsdGObj_gxlink_render_masks[] = { 1, 4, 2, 0 };

u8 hsdGObj_default_object_kind;
u8 hsdGObj_lobj_kind;
u8 hsdGObj_jobj_kind;
u8 hsdGObj_default_object_alt_kind;
HSD_GObjProc** hsdGObjProc_link_heads;
HSD_GObjProc** hsdGObjProc_priority_heads;
s32 hsdGObjProc_run_id;
HSD_GObjProc* hsdGObjProc_current;
s32 hsdGObjProc_current_s_link;
HSD_GObjProc* hsdGObjProc_next;
HSD_GObj** hsdGObj_p_link_heads;
HSD_GObj** hsdGObj_p_link_tails;
HSD_GObj** hsdGObj_gx_link_heads;
HSD_GObj** hsdGObj_gx_link_tails;
HSD_GObj* hsdGObj_current;
HSD_GObj* hsdGObj_current_gx;
HSD_GObj* hsdGObj_current_render;
GObjFunc* hsdGObj_obj_remove_funcs;

void HSD_GObjDefaultObjectRemove(HSD_Obj* obj);
void HSD_GObjDefaultObjectRemoveAlt(HSD_Obj* obj);

GObjFunc gobj_default_obj_remove_funcs[] = {
    HSD_GObjDefaultObjectRemove,
    (GObjFunc) HSD_LObjRemoveAll,
    (GObjFunc) RecalcParentTrspBits,
    HSD_GObjDefaultObjectRemoveAlt,
};

GObjFuncs gobj_default_func_node = {
    NULL,
    4,
    gobj_default_obj_remove_funcs,
    0,
};

GObjDefaultInitData gobj_default_init_data = {
    0x3F,
    0x3F,
    2,
    0,
    NULL,
    NULL,
};

void HSD_GObjUserDataLink(HSD_GObj* gobj, u8 kind, void (*remove_func)(void*), void* data)
{
    if (gobj->user_data_kind != HSD_GOBJ_USER_DATA_NONE) {
        __assert(GObjUserDataSourceFile, 40, GObjUserDataKindNoneAssert);
    }
    gobj->user_data_kind = kind;
    gobj->user_data = data;
    gobj->user_data_remove_func = remove_func;
}

void* HSD_GObjUserDataUnlink(HSD_GObj* gobj)
{
    void* ret;
    if (gobj->user_data_kind != HSD_GOBJ_USER_DATA_NONE) {
        gobj->user_data_kind = HSD_GOBJ_USER_DATA_NONE;
        ret = gobj->user_data;
        gobj->user_data = NULL;
        gobj->user_data_remove_func = NULL;
    } else {
        ret = NULL;
    }
    return ret;
}

void HSD_GObjUserDataRemove(HSD_GObj* gobj)
{
    if (gobj->user_data_kind == HSD_GOBJ_USER_DATA_NONE)
        return;

    if (gobj->user_data_remove_func == NULL) {
        __assert(GObjUserDataSourceFile, 99, GObjUserDataRemoveFuncAssert);
    }
    (*gobj->user_data_remove_func)(gobj->user_data);
    gobj->user_data_kind = HSD_GOBJ_USER_DATA_NONE;
    gobj->user_data = NULL;
}

static inline void GObj_SetPauseFlagAll(HSD_GObjProc* proc, u8 value)
{
    while (proc != NULL) {
        proc->flags_1 = value;
        proc = proc->child;
    }
}

static inline void GObj_SetSkipFlagAll(HSD_GObjProc* proc, u8 value)
{
    while (proc != NULL) {
        proc->flags_2 = value;
        proc = proc->child;
    }
}

void HSD_GObjProcSetPauseFlagAll(HSD_GObj* gobj)
{
    GObj_SetPauseFlagAll(gobj->proc, 1);
}

void HSD_GObjProcClearPauseFlagAll(HSD_GObj* gobj)
{
    GObj_SetPauseFlagAll(gobj->proc, 0);
}

void HSD_GObjProcSetSkipFlagAll(HSD_GObj* gobj)
{
    GObj_SetSkipFlagAll(gobj->proc, 1);
}

void HSD_GObjProcClearSkipFlagAll(HSD_GObj* gobj)
{
    GObj_SetSkipFlagAll(gobj->proc, 0);
}

void HSD_GObjProcRunAll(void)
{
    u64 mask;
    s32 i;
    HSD_GObjProc* proc;

    mask = hsdGObj_p_link_max.unk_2 != NULL ? *hsdGObj_p_link_max.unk_2 : 0;
    hsdGObjProc_run_id++;
    if (hsdGObjProc_run_id > 2) {
        hsdGObjProc_run_id = 0;
    }

    for (i = 0; i <= hsdGObj_p_link_max.gproc_pri_max; i++) {
        hsdGObjProc_current_s_link = i;
        proc = hsdGObjProc_priority_heads[i];
        while (proc != NULL) {
            HSD_GObj* gobj;

            hsdGObjProc_next = proc->next;
            if (proc->flags_3 != hsdGObjProc_run_id) {
                proc->flags_3 = hsdGObjProc_run_id;
                gobj = proc->gobj;
                if (!(mask & (1ULL << gobj->p_link)) && !proc->flags_1 && !proc->flags_2) {
                    hsdGObj_current = gobj;
                    hsdGObjProc_current = proc;
                    proc->callback(proc->gobj);
                    hsdGObjProc_next = proc->next;
                    if (hsdGObj_deferred_action_flags.flags != 0) {
                        hsdGObj_deferred_action_flags.b0 = 1;
                        if (hsdGObj_deferred_action_flags.b1) {
                            HSD_GObjDestroy(proc->gobj);
                        } else {
                            if (hsdGObj_deferred_action_flags.b3) {
                                HSD_GObjPLinkChange_Internal(hsdGObj_deferred_action_flags.type,
                                                             proc->gobj,
                                                             hsdGObj_deferred_action_flags.p_link,
                                                             hsdGObj_deferred_action_flags.p_prio,
                                                             hsdGObj_deferred_action_flags.gobj);
                            }
                            if (hsdGObj_deferred_action_flags.b2) {
                                HSD_GObjProcRemove(proc);
                            }
                        }
                        hsdGObj_deferred_action_flags.flags = 0;
                    }
                    hsdGObj_current = NULL;
                    hsdGObjProc_current = NULL;
                }
            }
            proc = hsdGObjProc_next;
        }
    }
}

u32 GObj_GetFlagFromArray(s32 i)
{
    return hsdGObj_gxlink_render_masks[i];
}

static inline void render_gobj(HSD_GObj* gobj, s32 pass)
{
    HSD_GObj* saved = hsdGObj_current_render;
    hsdGObj_current_render = gobj;
    gobj->render_cb(gobj, pass);
    hsdGObj_current_render = saved;
}

void GObj_SetTextureCamera(HSD_GObj* gobj, u32 mask)
{
    s32 i = 0;

    while (mask != 0) {
        if (mask & 1) {
            u64 prios = gobj->gxlink_prios;
            s32 j = 0;

            while (prios != 0) {
                if (prios & 1) {
                    HSD_GObj* cur;

                    for (cur = hsdGObj_gx_link_heads[j]; cur != NULL; cur = cur->next_gx) {
                        if (cur->render_cb != NULL) {
                            render_gobj(cur, i);
                        }
                    }
                }
                j++;
                prios >>= 1;
            }
        }
        i++;
        mask >>= 1;
    }
}

void GObj_RunGXLinkMaxCallbacks(void)
{
    HSD_GObj* saved;
    HSD_GObj* cur = hsdGObj_gx_link_heads[hsdGObj_p_link_max.gx_link_max + 1];

    while (cur != NULL) {
        if (cur->render_cb != NULL) {
            saved = hsdGObj_current_gx;
            hsdGObj_current_gx = cur;
            cur->render_cb(cur, 0);
            hsdGObj_current_gx = saved;
        }
        cur = cur->next_gx;
    }
}

void HSD_GObjJObjRemove(HSD_GObj* gobj)
{
    HSD_LObjSetCurrentAll(gobj->hsd_obj);
    HSD_LObjSetupInit(HSD_CObjGetCurrent());
}

#pragma push
#pragma dont_inline on
void HSD_GObjJObjDisp(HSD_GObj* gobj, s32 pass)
{
    HSD_JObj* jobj = gobj->hsd_obj;
    HSD_JObjDispAll(jobj, NULL, GObj_GetFlagFromArray(pass), 0);
}
#pragma pop

#pragma push
#pragma dont_inline on
void GObj_SetCamera(HSD_GObj* gobj)
{
    if (HSD_CObjSetCurrent(gobj->hsd_obj)) {
        GObj_SetTextureCamera(gobj, 7);
        HSD_CObjEndCurrent();
    }
}
#pragma pop

static inline BOOL HSD_GObjDecRef(HSD_Obj* obj)
{
    u16 ref_count = obj->ref_count;
    BOOL no_ref = ref_count == 0xFFFF;

    if (no_ref) {
        return no_ref;
    }

    obj->ref_count--;
    return ref_count == 0;
}

static inline void HSD_GObjDefaultObjectRemoveCommon(HSD_Obj* obj)
{
    HSD_Obj* hsd_obj = obj;

    if (hsd_obj != NULL && HSD_GObjDecRef(hsd_obj) && hsd_obj != NULL) {
        hsd_obj->parent.class_info->release((HSD_Class*) hsd_obj);
        hsd_obj->parent.class_info->destroy((HSD_Class*) hsd_obj);
    }
}

void HSD_GObjDefaultObjectRemove(HSD_Obj* obj)
{
    HSD_GObjDefaultObjectRemoveCommon(obj);
}

void HSD_GObjDefaultObjectRemoveAlt(HSD_Obj* obj)
{
    HSD_GObjDefaultObjectRemoveCommon(obj);
}

u8 GObj_AddFuncTable(HSD_GObjLibInitDataType* init_data, GObjFuncs* funcs);

void GObj_RegisterDefaultFuncs(HSD_GObjLibInitDataType* init_data)
{
    u8 count = GObj_AddFuncTable(init_data, &gobj_default_func_node);

    hsdGObj_default_object_kind = count++;
    hsdGObj_lobj_kind = count++;
    hsdGObj_jobj_kind = count++;
    hsdGObj_default_object_alt_kind = count;
}

u8 GObj_AddFuncTable(HSD_GObjLibInitDataType* init_data, GObjFuncs* funcs)
{
    GObjFuncs* cur;
    GObjFuncs** pcur = &init_data->funcs;
    u8 count = 0;

    while ((cur = *pcur) != NULL) {
        pcur = &cur->next;
        count += cur->size;
    }

    *pcur = funcs;
    (*pcur)->next = NULL;
    return count;
}

void GObj_InitializeLibInitData(HSD_GObjLibInitDataType* init_data)
{
    *init_data = *(HSD_GObjLibInitDataType*) &gobj_default_init_data;
}

#pragma push
#pragma dont_inline on
void GObj_Init(HSD_GObjLibInitDataType* init_data)
{
    int i;
    int count;
    GObjFuncs* funcs;

    GObj_RegisterDefaultFuncs(init_data);
    hsdGObj_p_link_max = *init_data;

    hsdGObj_p_link_heads = HSD_Alloc(sizeof(HSD_GObj*) * (init_data->p_link_max + 1));
    hsdGObj_p_link_tails = HSD_Alloc(sizeof(HSD_GObj*) * (init_data->p_link_max + 1));
    for (i = 0; i < init_data->p_link_max + 1; i++) {
        hsdGObj_p_link_heads[i] = hsdGObj_p_link_tails[i] = NULL;
    }

    hsdGObj_gx_link_heads = HSD_Alloc(sizeof(HSD_GObj*) * (init_data->gx_link_max + 2));
    hsdGObj_gx_link_tails = HSD_Alloc(sizeof(HSD_GObj*) * (init_data->gx_link_max + 2));
    for (i = 0; i < init_data->gx_link_max + 2; i++) {
        hsdGObj_gx_link_heads[i] = hsdGObj_gx_link_tails[i] = NULL;
    }

    hsdGObjProc_priority_heads = HSD_Alloc(sizeof(HSD_GObjProc*) * (init_data->gproc_pri_max + 1));
    for (i = 0; i < init_data->gproc_pri_max + 1; i++) {
        hsdGObjProc_priority_heads[i] = NULL;
    }

    hsdGObjProc_link_heads = HSD_Alloc(sizeof(HSD_GObjProc*) *
                             (init_data->gproc_pri_max + 1) *
                             (init_data->p_link_max + 1));
    for (i = 0; i < (init_data->gproc_pri_max + 1) * (init_data->p_link_max + 1); i++) {
        hsdGObjProc_link_heads[i] = NULL;
    }

    HSD_ObjAllocInit(&hsdGObj_alloc_data, sizeof(HSD_GObj), 4);
    HSD_ObjAllocInit(&hsdGObjProc_alloc_data, sizeof(HSD_GObjProc), 4);

    count = 0;
    for (funcs = init_data->funcs; funcs != NULL; funcs = funcs->next) {
        count += funcs->size;
    }

    if (count != 0) {
        hsdGObj_obj_remove_funcs = HSD_Alloc(sizeof(GObjFunc) * count);

        count = 0;
        for (funcs = init_data->funcs; funcs != NULL; funcs = funcs->next) {
            for (i = 0; i < funcs->size; i++, count++) {
                hsdGObj_obj_remove_funcs[count] = funcs->funcs[i];
            }
        }
    } else {
        hsdGObj_obj_remove_funcs = NULL;
    }

    hsdGObjProc_run_id = 0;
    hsdGObj_current = NULL;
    hsdGObjProc_current = NULL;
    hsdGObj_deferred_action_flags.flags = 0;
    hsdGObj_current_gx = NULL;
    hsdGObj_current_render = NULL;
}
#pragma pop

HSD_GObjDeferredActionFlags hsdGObj_deferred_action_flags;
HSD_ObjAllocData hsdGObjProc_alloc_data;
HSD_ObjAllocData hsdGObj_alloc_data;
HSD_GObjLibInitDataType hsdGObj_p_link_max;
