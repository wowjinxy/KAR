#include <sysdolphin/pobj.h>

u32 HSD_PObjGetFlags(HSD_PObj* pobj)
{
    if (pobj != NULL) {
        return pobj->flags;
    }
    return 0;
}

void HSD_PObjRemoveAnimAllByFlags(HSD_PObj* pobj, u32 flags)
{
    if (pobj != NULL) {
        HSD_PObj* cur;
        for (cur = pobj; cur != NULL; cur = cur->next) {
            if (cur != NULL && flags & POBJ_ANIM &&
                pobj_type(cur) == POBJ_SHAPEANIM && cur->u.shape_set != NULL)
            {
                HSD_AObjRemove(cur->u.shape_set->aobj);
                cur->u.shape_set->aobj = NULL;
            }
        }
    }
}

void HSD_PObjRemoveAnimAll(HSD_PObj* pobj, HSD_ShapeAnim* anim)
{
    HSD_PObj* cur_pobj;
    HSD_ShapeAnim* cur_anim;

    if (pobj == NULL || anim == NULL) {
        return;
    }
    cur_pobj = pobj;
    cur_anim = anim;
    while (cur_pobj != NULL) {
        if (cur_pobj != NULL && pobj_type(cur_pobj) == POBJ_SHAPEANIM &&
            cur_pobj->u.shape_set != NULL)
        {
            if (cur_pobj->u.shape_set->aobj != NULL) {
                HSD_AObjRemove(cur_pobj->u.shape_set->aobj);
            }
            cur_pobj->u.shape_set->aobj = HSD_AObjLoadDesc(cur_anim->aobjdesc);
        }
        cur_pobj = cur_pobj->next;
        if (cur_anim != NULL) {
            cur_anim = cur_anim->next;
        } else {
            cur_anim = NULL;
        }
    }
}

void HSD_PObjReqAnimAllByFlags(HSD_PObj* pobj, f32 arg8, u32 flags)
{
    HSD_PObj* cur;
    if (pobj == NULL) {
        return;
    }
    for (cur = pobj; cur != NULL; cur = cur->next) {
        if (cur != NULL && flags & POBJ_ANIM &&
            pobj_type(cur) == POBJ_SHAPEANIM && cur->u.shape_set != NULL)
        {
            HSD_AObjReqAnim(cur->u.shape_set->aobj, arg8);
        }
    }
}
