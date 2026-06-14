#include <sysdolphin/gobj.h>

extern void (**lbl_805DE318)(void*);

void HSD_GObjObjectLink(HSD_GObj* gobj, u8 kind, void* obj)
{
    assert_line(42, gobj->obj_kind == HSD_GOBJ_OBJ_NONE);
    gobj->obj_kind = kind;
    gobj->hsd_obj = obj;
}

void* HSD_GObjObjectUnlink(HSD_GObj* gobj)
{
    void* obj;
    if (gobj->obj_kind != HSD_GOBJ_OBJ_NONE) {
        gobj->obj_kind = HSD_GOBJ_OBJ_NONE;
        obj = gobj->hsd_obj;
        gobj->hsd_obj = NULL;
    } else {
        obj = NULL;
    }
    return obj;
}

void HSD_GObjObjectRemove(HSD_GObj* gobj)
{
    if (gobj->obj_kind != HSD_GOBJ_OBJ_NONE) {
        lbl_805DE318[gobj->obj_kind](gobj->hsd_obj);
        gobj->obj_kind = HSD_GOBJ_OBJ_NONE;
        gobj->hsd_obj = NULL;
    }
}
