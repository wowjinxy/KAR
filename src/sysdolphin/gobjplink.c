#include <sysdolphin/gobj.h>

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
    HSD_GObj* gobj;
} HSD_GObjDeferredActionFlags;

typedef struct _HSD_GObjLibInfo {
    u8 p_link_max;
    u8 gx_link_max;
    u8 gproc_pri_max;
    u8 pad;
    u32 unk1;
    u32* unk2;
} HSD_GObjLibInfo;

extern HSD_GObjLibInfo hsdGObj_p_link_max;
extern HSD_ObjAllocData hsdGObj_alloc_data;
extern HSD_GObjDeferredActionFlags hsdGObj_deferred_action_flags;
extern HSD_GObj* lbl_805DE324;
extern HSD_GObj** lbl_805DE330;
extern HSD_GObj** lbl_805DE334;
extern s32 lbl_805DE344;

void HSD_GObjProcRemoveAll(HSD_GObj* gobj);
void HSD_GObjGXLinkRemove(HSD_GObj* gobj);
void HSD_GObjUserDataRemove(HSD_GObj* gobj);
void HSD_GObjProcUnlink_Internal(HSD_GObjProc* proc);
void HSD_GObjProcLink_Internal(HSD_GObjProc* proc);

char kar_src_gobjplink_80504dd8[] = "gobjplink.c";
char lbl_80504DE4[] = "p_link <= HSD_GObjLibInitData.p_link_max";

static inline void GObj_PReorder(HSD_GObj* gobj, HSD_GObj* hiprio_gobj)
{
    s32 link = gobj->p_link;
    gobj->prev = hiprio_gobj;
    if (hiprio_gobj != NULL) {
        gobj->next = hiprio_gobj->next;
        hiprio_gobj->next = gobj;
    } else {
        gobj->next = lbl_805DE334[link];
        lbl_805DE334[link] = gobj;
    }
    if (gobj->next != NULL) {
        gobj->next->prev = gobj;
    } else {
        lbl_805DE330[link] = gobj;
    }
}

static inline void gobj_first_lower_prio(HSD_GObj* gobj)
{
    HSD_GObj* cur = lbl_805DE330[gobj->p_link];
    while (cur != NULL && cur->p_priority > gobj->p_priority) {
        cur = cur->prev;
    }
    GObj_PReorder(gobj, cur);
}

static inline void gobj_first_higher_prio(HSD_GObj* gobj)
{
    HSD_GObj* cur = lbl_805DE334[gobj->p_link];
    while (cur != NULL && cur->p_priority < gobj->p_priority) {
        cur = cur->next;
    }
    GObj_PReorder(gobj, cur != NULL ? cur->prev : lbl_805DE330[gobj->p_link]);
}

static inline void gobj_insert_before(HSD_GObj* gobj, HSD_GObj* position)
{
    GObj_PReorder(gobj, position->prev);
}

static inline void gobj_unlink(HSD_GObj* gobj)
{
    if (gobj->prev != NULL) {
        gobj->prev->next = gobj->next;
    } else {
        lbl_805DE334[gobj->p_link] = gobj->next;
    }
    if (gobj->next != NULL) {
        gobj->next->prev = gobj->prev;
    } else {
        lbl_805DE330[gobj->p_link] = gobj->prev;
    }
}

HSD_GObj* HSD_GObjCreate_Internal(s32 where, u16 classifier, u8 p_link, u8 priority,
                                  HSD_GObj* position)
{
    HSD_GObj* gobj;

    if (!(p_link <= hsdGObj_p_link_max.p_link_max)) {
        __assert(kar_src_gobjplink_80504dd8, 0xA8, lbl_80504DE4);
    }

    gobj = HSD_ObjAlloc(&hsdGObj_alloc_data);
    if (gobj == NULL) {
        return NULL;
    }

    gobj->classifier = classifier;
    gobj->p_link = p_link;
    gobj->gx_link = HSD_GOBJ_GXLINK_NONE;
    gobj->p_priority = priority;
    gobj->render_priority = 0;
    gobj->obj_kind = HSD_GOBJ_OBJ_NONE;
    gobj->user_data_kind = HSD_GOBJ_GXLINK_NONE;
    gobj->prev_gx = NULL;
    gobj->next_gx = NULL;
    gobj->proc = NULL;
    gobj->render_cb = NULL;
    gobj->gxlink_prios = 0;
    gobj->hsd_obj = NULL;
    gobj->user_data = NULL;
    gobj->user_data_remove_func = NULL;

    switch (where) {
    case 0:
        gobj_first_lower_prio(gobj);
        break;
    case 1:
        gobj_first_higher_prio(gobj);
        break;
    case 2:
        GObj_PReorder(gobj, position);
        break;
    case 3:
        gobj_insert_before(gobj, position);
        break;
    }
    return gobj;
}

HSD_GObj* HSD_GObjCreate(u16 classifier, u8 p_link, u8 priority)
{
    return HSD_GObjCreate_Internal(0, classifier, p_link, priority, NULL);
}

void HSD_GObjDestroy(HSD_GObj* gobj)
{
    if (!hsdGObj_deferred_action_flags.b0 && gobj == lbl_805DE324) {
        hsdGObj_deferred_action_flags.b1 = 1;
        return;
    }

    HSD_GObjUserDataRemove(gobj);
    HSD_GObjObjectRemove(gobj);
    HSD_GObjProcRemoveAll(gobj);
    if (gobj->gx_link != HSD_GOBJ_GXLINK_NONE) {
        HSD_GObjGXLinkRemove(gobj);
    }
    gobj_unlink(gobj);
    HSD_ObjFree(&hsdGObj_alloc_data, gobj);
}

void HSD_GObjPLinkChange_Internal(s32 where, HSD_GObj* gobj, u8 p_link, u8 priority,
                                  HSD_GObj* position)
{
    s32 new_slot;
    s32 old_slot;
    HSD_GObjProc* relink_proc;
    HSD_GObjProc* relink_next;
    HSD_GObjProc* proc;
    HSD_GObjProc* proc_next;
    HSD_GObjProc* proc_list;

    if (!(p_link <= hsdGObj_p_link_max.p_link_max)) {
        __assert(kar_src_gobjplink_80504dd8, 0x19F, lbl_80504DE4);
    }

    if (!hsdGObj_deferred_action_flags.b0 && gobj == lbl_805DE324) {
        hsdGObj_deferred_action_flags.type = where;
        hsdGObj_deferred_action_flags.b3 = 1;
        hsdGObj_deferred_action_flags.p_link = p_link;
        hsdGObj_deferred_action_flags.p_prio = priority;
        hsdGObj_deferred_action_flags.gobj = position;
        return;
    }

    proc = gobj->proc;
    proc_list = NULL;
    while (proc != NULL) {
        HSD_GObjProcUnlink_Internal(proc);
        proc_next = proc->child;
        proc->child = proc_list;
        proc_list = proc;
        proc = proc_next;
    }
    gobj->proc = NULL;

    gobj_unlink(gobj);
    gobj->p_link = p_link;
    gobj->p_priority = priority;
    switch (where) {
    case 0:
        gobj_first_lower_prio(gobj);
        break;
    case 1:
        gobj_first_higher_prio(gobj);
        break;
    case 2:
        GObj_PReorder(gobj, position);
        break;
    case 3:
        gobj_insert_before(gobj, position);
        break;
    }

    new_slot = 2;
    old_slot = lbl_805DE344;
    if (old_slot != 0) {
        new_slot = old_slot - 1;
    }
    old_slot = 2;
    if (new_slot != 0) {
        old_slot = new_slot - 1;
    }

    relink_proc = proc_list;
    while (relink_proc != NULL) {
        relink_next = relink_proc->child;
        HSD_GObjProcLink_Internal(relink_proc);
        if (relink_proc->flags_3 == old_slot) {
            relink_proc->flags_3 = new_slot;
        }
        relink_proc = relink_next;
    }
}

void HSD_GObjPLinkChange(HSD_GObj* gobj, u8 p_link, u8 priority)
{
    HSD_GObjPLinkChange_Internal(0, gobj, p_link, priority, NULL);
}

void HSD_GObjPLinkChangeAfter(HSD_GObj* gobj, HSD_GObj* position)
{
    HSD_GObjPLinkChange_Internal(3, gobj, position->p_link, position->p_priority, position);
}
