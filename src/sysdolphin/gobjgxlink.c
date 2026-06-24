#include <sysdolphin/gobj.h>

char kar_src_gobjgxlink_80504e10[0x10] = "gobjgxlink.c";
char lbl_80504E20[0x2C] = "gx_link <= HSD_GObjLibInitData.gx_link_max";
char lbl_80504E4C[0x26] = "gobj->gx_link != HSD_GOBJ_GXLINK_NONE";

static inline void gx_link_after(HSD_GObj* gobj, HSD_GObj* position)
{
    s32 link = gobj->gx_link;

    gobj->prev_gx = position;
    if (position != NULL) {
        gobj->next_gx = position->next_gx;
        position->next_gx = gobj;
    } else {
        gobj->next_gx = hsdGObj_gx_link_heads[link];
        hsdGObj_gx_link_heads[link] = gobj;
    }

    if (gobj->next_gx != NULL) {
        gobj->next_gx->prev_gx = gobj;
    } else {
        hsdGObj_gx_link_tails[gobj->gx_link] = gobj;
    }
}

static inline void gx_link_first_lower_prio(HSD_GObj* gobj)
{
    HSD_GObj* cur = hsdGObj_gx_link_tails[gobj->gx_link];

    while (cur != NULL && cur->render_priority > gobj->render_priority) {
        cur = cur->prev_gx;
    }
    gx_link_after(gobj, cur);
}

static inline void gx_link_first_higher_prio(HSD_GObj* gobj)
{
    HSD_GObj* cur = hsdGObj_gx_link_heads[gobj->gx_link];

    while (cur != NULL && cur->render_priority < gobj->render_priority) {
        cur = cur->next_gx;
    }
    gx_link_after(gobj, cur != NULL ? cur->prev_gx : hsdGObj_gx_link_tails[gobj->gx_link]);
}

static inline void gx_link_before_position(HSD_GObj* gobj, HSD_GObj* position)
{
    gx_link_after(gobj, position->prev_gx);
}

static inline void gx_unlink(HSD_GObj* gobj)
{
    if (gobj->prev_gx != NULL) {
        gobj->prev_gx->next_gx = gobj->next_gx;
    } else {
        hsdGObj_gx_link_heads[gobj->gx_link] = gobj->next_gx;
    }

    if (gobj->next_gx != NULL) {
        gobj->next_gx->prev_gx = gobj->prev_gx;
    } else {
        hsdGObj_gx_link_tails[gobj->gx_link] = gobj->prev_gx;
    }
}

static inline void gx_clear_link(HSD_GObj* gobj)
{
    gobj->gx_link = HSD_GOBJ_GXLINK_NONE;
    gobj->render_priority = 0;
    gobj->prev_gx = NULL;
    gobj->next_gx = NULL;
}

HSD_GObj* HSD_GObjGXLink_Internal(s32 where, HSD_GObj* gobj, void (*render_cb)(HSD_GObj*, s32),
                                  u8 gx_link, u8 priority, HSD_GObj* position)
{
    gobj->render_cb = render_cb;
    gobj->gx_link = gx_link;
    gobj->render_priority = priority;

    switch (where) {
    case 0:
        gx_link_first_lower_prio(gobj);
        break;
    case 1:
        gx_link_first_higher_prio(gobj);
        break;
    case 2:
        gx_link_after(gobj, position);
        break;
    case 3:
        gx_link_before_position(gobj, position);
        break;
    }
    return gobj;
}

HSD_GObj* HSD_GObjGXLink(HSD_GObj* gobj, void (*render_cb)(HSD_GObj*, s32), u8 gx_link,
                         u8 priority)
{
    if (!(gx_link <= hsdGObj_p_link_max.gx_link_max)) {
        __assert(kar_src_gobjgxlink_80504e10, 0xA7, lbl_80504E20);
    }
    return HSD_GObjGXLink_Internal(0, gobj, render_cb, gx_link, priority, NULL);
}

HSD_GObj* GObj_SetupGXLinkMax(HSD_GObj* gobj, void (*render_cb)(HSD_GObj*, s32), u8 priority)
{
    return HSD_GObjGXLink_Internal(0, gobj, render_cb, hsdGObj_p_link_max.gx_link_max + 1,
                                   priority, NULL);
}

void HSD_GObjGXLinkRemove(HSD_GObj* gobj)
{
    if (gobj->gx_link == HSD_GOBJ_GXLINK_NONE) {
        __assert(kar_src_gobjgxlink_80504e10, 0x19F, lbl_80504E4C);
    }

    gx_unlink(gobj);
    gx_clear_link(gobj);
}

void HSD_GObjGXLinkChange_Internal(s32 where, HSD_GObj* gobj, u8 gx_link, u8 priority,
                                   HSD_GObj* position)
{
    if (gobj->gx_link == HSD_GOBJ_GXLINK_NONE) {
        __assert(kar_src_gobjgxlink_80504e10, 0x19F, lbl_80504E4C);
    }

    gx_unlink(gobj);
    gx_clear_link(gobj);

    gobj->gx_link = gx_link;
    gobj->render_priority = priority;

    switch (where) {
    case 0:
        gx_link_first_lower_prio(gobj);
        break;
    case 1:
        gx_link_first_higher_prio(gobj);
        break;
    case 2:
        gx_link_after(gobj, position);
        break;
    case 3:
        gx_link_before_position(gobj, position);
        break;
    }
}

void HSD_GObjGXLinkChange(HSD_GObj* gobj, u8 gx_link, u8 priority)
{
    if (!(gx_link <= hsdGObj_p_link_max.gx_link_max)) {
        __assert(kar_src_gobjgxlink_80504e10, 0x1F7, lbl_80504E20);
    }
    HSD_GObjGXLinkChange_Internal(0, gobj, gx_link, priority, NULL);
}

void HSD_GObjGXLinkBefore(HSD_GObj* gobj, HSD_GObj* position)
{
    HSD_GObjGXLinkChange_Internal(2, gobj, position->gx_link, position->render_priority, position);
}

void HSD_GObjGXLinkAfter(HSD_GObj* gobj, HSD_GObj* position)
{
    HSD_GObjGXLinkChange_Internal(3, gobj, position->gx_link, position->render_priority, position);
}
