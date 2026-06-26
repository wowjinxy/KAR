#include <dolphin/types.h>
#include <sysdolphin/aobj.h>
#include <sysdolphin/dobj.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/jobj.h>
#include <sysdolphin/lobj.h>
#include <sysdolphin/mobj.h>
#include <sysdolphin/robj.h>

typedef struct LbAirRideAnimSet {
    void* unk0;
    HSD_AnimJoint** joints;
    HSD_MatAnimJoint** materials;
    HSD_ShapeAnimDObj** shapes;
} LbAirRideAnimSet;

typedef struct LbAirRideSlotNodeA {
    void* unk0;
    struct LbAirRideSlotNodeA* next;
    u8 pad[6];
    u8 slot;
} LbAirRideSlotNodeA;

typedef struct LbAirRideSlotNodeB {
    struct LbAirRideSlotNodeB* next;
    u8 pad[0x34];
    s32 slot_kind;
} LbAirRideSlotNodeB;

typedef struct LbAirRideSlotOwner {
    u8 pad[0x18];
    LbAirRideSlotNodeB* used_objects;
    LbAirRideSlotNodeA* used_slots;
} LbAirRideSlotOwner;

typedef struct LbAirRideLightEntry {
    HSD_LightDesc* desc;
    HSD_LightAnim** anim;
} LbAirRideLightEntry;

extern s32 lbl_80497CA8[8];
extern s32 lbl_80497CC8[4];
extern s32 kar_object_slot_remap_table[4];
extern s32 lbl_80497CE8[8];
extern s32 lbl_80497D08[8];
extern HSD_Joint lbl_80497D28;

extern void HSD_JObjSetFlags(HSD_JObj* jobj, u32 flags);
extern void HSD_JObjClearFlags(HSD_JObj* jobj, u32 flags);
extern void HSD_JObjAddAnimAll(HSD_JObj* jobj, HSD_AnimJoint* animjoint,
                               HSD_MatAnimJoint* matanim,
                               HSD_ShapeAnimDObj* shapeanim);
extern void HSD_JObjCheckDepend(HSD_JObj* jobj);
extern void HSD_JObjPrependRObj(HSD_JObj* jobj, HSD_RObj* robj);
extern void HSD_JObjDeleteRObj(HSD_JObj* jobj, HSD_RObj* robj);
extern void HSD_JObjUnref(HSD_JObj* jobj);
extern HSD_RObj* HSD_RObjAlloc(void);
extern HSD_RObj* HSD_RObjGetByType(HSD_RObj* robj, u32 type, u32 subtype);
extern void HSD_RObjSetConstraintObj(HSD_RObj* robj, void* obj);
extern void HSD_RObjRemove(HSD_RObj* robj);
extern void HSD_RObjAnimAll(HSD_RObj* robj);
extern HSD_LObj* HSD_LObjLoadDesc(HSD_LightDesc* desc);
extern void HSD_LObjAddAnimAll(HSD_LObj* lobj, HSD_LightAnim* anim);

HSD_Joint* kar_lbairride__near_80055da0(void);

#define HSD_LObjSetNextInline(lobj, next_lobj)                                \
    do {                                                                       \
        if ((lobj) == NULL) {                                                  \
            __assert("lobj.h", 0x12D, "lobj");                                \
        }                                                                      \
        (lobj)->next = (next_lobj);                                            \
    } while (0)

BOOL kar_lbairride__80054904(HSD_JObj* jobj)
{
    HSD_DObj* dobj;
    HSD_AObj* aobj;

    if (!union_type_dobj(jobj)) {
        __assert("lbairride.c", 0x1B8, "union_type_dobj(jobj)");
    }

    for (dobj = jobj->u.dobj; dobj != NULL; dobj = dobj->next) {
        if (dobj->mobj != NULL) {
            aobj = dobj->mobj->aobj;
            if (aobj != NULL) {
                if (aobj != NULL && (HSD_AObjGetFlags(aobj) & AOBJ_NO_ANIM) == 0) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

BOOL kar_lbairride__near_80054cac(HSD_JObj* jobj)
{
    HSD_AObj* aobj = jobj->aobj;

    if (aobj != NULL && (aobj->flags & AOBJ_REWINDED) != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL kar_lbairride__near_80054cd4(HSD_JObj* jobj)
{
    HSD_JObj* root = jobj;
    HSD_JObj* parent;
    HSD_AObj* aobj;
    BOOL rewound;

    if (jobj == NULL || (jobj->flags & INSTANCE) != 0) {
        return FALSE;
    }

    if (jobj->child == NULL) {
        aobj = jobj->aobj;
        if (aobj != NULL && (aobj->flags & AOBJ_REWINDED) != 0) {
            return TRUE;
        }
        return FALSE;
    }

check_jobj:
    aobj = jobj->aobj;
    if (aobj != NULL && (aobj->flags & AOBJ_REWINDED) != 0) {
        rewound = TRUE;
    } else {
        rewound = FALSE;
    }
    if (rewound) {
        return TRUE;
    }

    if (jobj->child != NULL || jobj->next != NULL) {
        if ((jobj->flags & INSTANCE) == 0) {
            goto descend;
        }
    }

find_next_parent:
    parent = jobj->parent;
    if (parent == root) {
        return FALSE;
    }
    jobj = parent->next;
    if (jobj == NULL) {
        goto no_parent_next;
    }
    goto check_jobj;

no_parent_next:
    jobj = parent;
    goto find_next_parent;

descend:
    if (jobj->child != NULL) {
        jobj = jobj->child;
        goto check_jobj;
    }
    jobj = jobj->next;
    goto check_jobj;
}

void fn_80054DC4(void)
{
}

void kar_lbairride__near_800550bc(HSD_JObj* jobj, u32 mask, f32 rate)
{
    HSD_ForeachAnim(jobj, JOBJ_TYPE, mask, HSD_AObjSetRate, AOBJ_ARG_AF,
                    rate);
}

void kar_lbairride__near_800550f4(HSD_JObj* jobj, u32 mask)
{
    HSD_ForeachAnim(jobj, JOBJ_TYPE, mask, HSD_AObjSetFlags, AOBJ_ARG_AU,
                    0x20000000);
}

HSD_JObj* kar_lbairride__near_80055130(HSD_JObj* parent)
{
    HSD_JObj* jobj = HSD_JObjLoadJoint(kar_lbairride__near_80055da0());
    HSD_JObj* child;

    HSD_JObjSetFlags(jobj, 0x70000008);
    if (parent == NULL) {
        child = NULL;
    } else {
        child = parent->child;
    }
    jobj->child = child;
    jobj->parent = parent;
    parent->child = jobj;
    if (child != NULL) {
        child->parent = jobj;
    }
    return jobj;
}

void kar_lbairride__near_800551a8(HSD_JObj* dst, HSD_Joint* joint)
{
    u16 has_dst;

    has_dst = dst != NULL;
    if (has_dst) {
        if (joint != NULL) {
            goto copy;
        }
        if (dst && dst) {
        }
        goto done;
    copy:
        dst->rotate.x = joint->rotation.x;
        dst->rotate.y = joint->rotation.y;
        dst->rotate.z = joint->rotation.z;
        dst->scale = joint->scale;
        dst->translate = joint->position;
        HSD_JObjClearFlags(dst, USE_QUATERNION);
        HSD_JObjSetFlags(dst, MTX_DIRTY);
    }
done:;
}

void kar_lbairride__near_80055658(HSD_JObj* src, HSD_JObj* dst)
{
    dst->rotate = src->rotate;
    dst->scale = src->scale;
    dst->translate = src->translate;
    if ((HSD_JObjGetFlags(src) & USE_QUATERNION) != 0) {
        HSD_JObjSetFlags(dst, USE_QUATERNION);
    } else {
        HSD_JObjClearFlags(dst, USE_QUATERNION);
    }
    HSD_JObjSetFlags(dst, MTX_DIRTY);
}

void kar_lbairride__near_80055a30(HSD_JObj* jobj, s32 index,
                                  LbAirRideAnimSet* anim)
{
    HSD_AnimJoint* joint;
    HSD_MatAnimJoint* mat;
    HSD_ShapeAnimDObj* shape;
    HSD_AnimJoint** joints = anim->joints;
    HSD_ShapeAnimDObj** shapes = anim->shapes;
    HSD_MatAnimJoint** materials = anim->materials;

    if (joints != NULL) {
        joint = joints[index];
    } else {
        joint = NULL;
    }
    if (materials != NULL) {
        mat = materials[index];
    } else {
        mat = NULL;
    }
    if (shapes != NULL) {
        shape = shapes[index];
    } else {
        shape = NULL;
    }
    HSD_JObjAddAnimAll(jobj, joint, mat, shape);
}

void kar_lbairride__near_80055aa8(HSD_JObj* jobj, f32 frame)
{
    HSD_JObjReqAnimAllByFlags(jobj, 4, frame);
}

void kar_lbairride__near_80055acc(HSD_JObj* jobj, f32 frame)
{
    HSD_JObjReqAnimAllByFlags(jobj, HIDDEN, frame);
}

HSD_JObj* kar_lbairride__near_80055af0(HSD_GObj* gobj, s32 index)
{
    HSD_JObj* jobj = gobj->hsd_obj;
    HSD_JObj* child;
    HSD_JObj* next;
    HSD_JObj* parent;

    if (index == 0) {
        return jobj;
    }

    while (index > 0) {
        if (jobj == NULL) {
            child = NULL;
        } else {
            child = jobj->child;
        }
        if (child != NULL) {
            if (jobj == NULL) {
                jobj = NULL;
            } else {
                jobj = jobj->child;
            }
        } else {
            if (jobj == NULL) {
                next = NULL;
            } else {
                next = jobj->next;
            }
            if (next != NULL) {
                if (jobj == NULL) {
                    jobj = NULL;
                } else {
                    jobj = jobj->next;
                }
            } else {
            parent_loop:
                if (jobj == NULL) {
                    parent = NULL;
                } else {
                    parent = jobj->parent;
                }
                if (parent == NULL) {
                    jobj = NULL;
                } else {
                    if (jobj == NULL) {
                        parent = NULL;
                    } else {
                        parent = jobj->parent;
                    }
                    if (parent == NULL) {
                        next = NULL;
                    } else {
                        next = parent->next;
                    }
                    if (next != NULL) {
                        if (jobj == NULL) {
                            jobj = NULL;
                        } else {
                            jobj = jobj->parent;
                        }
                        if (jobj == NULL) {
                            jobj = NULL;
                        } else {
                            jobj = jobj->next;
                        }
                    } else {
                        if (jobj == NULL) {
                            jobj = NULL;
                        } else {
                            jobj = jobj->parent;
                        }
                        goto parent_loop;
                    }
                }
            }
        }
        if (jobj == NULL) {
            return jobj;
        }
        --index;
    }

    return jobj;
}

void kar_lbairride__near_80055c14(HSD_JObj* jobj, void* constraint)
{
    HSD_RObj* robj = HSD_RObjAlloc();

    HSD_RObjSetFlags(robj, 0x90000001);
    HSD_RObjSetConstraintObj(robj, constraint);
    HSD_JObjPrependRObj(jobj, robj);
}

void kar_lbairride__near_80055c7c(HSD_JObj* jobj, void* constraint)
{
    HSD_RObj* robj = HSD_RObjAlloc();

    HSD_RObjSetFlags(robj, 0x90000001);
    HSD_RObjSetConstraintObj(robj, constraint);
    HSD_JObjPrependRObj(jobj, robj);

    robj = HSD_RObjAlloc();
    HSD_RObjSetFlags(robj, 0x90000004);
    HSD_RObjSetConstraintObj(robj, constraint);
    HSD_JObjPrependRObj(jobj, robj);
}

void kar_lbairride__near_80055d10(HSD_JObj* jobj)
{
    HSD_RObj* next;
    HSD_RObj* robj;

    if (jobj == NULL) {
        __assert("jobj.h", 0x1C7, "jobj");
    }

    next = jobj->robj;
    while (TRUE) {
        robj = HSD_RObjGetByType(next, REFTYPE_JOBJ, 0);
        if (robj == NULL) {
            break;
        }
        if (robj != NULL) {
            next = robj->next;
        } else {
            next = NULL;
        }
        HSD_JObjDeleteRObj(jobj, robj);
        HSD_RObjRemove(robj);
    }
}

HSD_Joint* kar_lbairride__near_80055da0(void)
{
    return &lbl_80497D28;
}

void kar_lbairride__near_80055dac(HSD_JObj* jobj)
{
    if (jobj != NULL) {
        HSD_JObjCheckDepend(jobj);
        HSD_AObjInterpretAnim(jobj->aobj, jobj,
                              *(HSD_ObjUpdateFunc*) ((u8*) jobj->object.parent.class_info + 0x50));
        HSD_RObjAnimAll(jobj->robj);
    }
}

void kar_lbairride__near_80055df8(HSD_JObj* jobj)
{
    HSD_JObj* child;

    if (jobj == NULL) {
        return;
    }

    kar_lbairride__near_80055dac(jobj);
    if ((jobj->flags & INSTANCE) != 0) {
        return;
    }

    for (child = jobj->child; child != NULL; child = child->next) {
        kar_lbairride__near_80055df8(child);
    }
}

void kar_lbairride__near_80056038(HSD_JObj* jobj)
{
    if (jobj != NULL) {
        HSD_AObjInitEndCallBack();
        kar_lbairride__near_80055df8(jobj);
        HSD_AObjInvokeCallBacks();
    }
}

void kar_lbairride__near_80056074(HSD_MObj* mobj)
{
    if (mobj != NULL) {
        HSD_AObjInterpretAnim(mobj->aobj, mobj, HSD_MOBJ_METHOD(mobj)->update);
    }
}

void kar_lbairride__near_800560ac(HSD_DObj* dobj, HSD_MatAnim* matanim)
{
    HSD_DObj* cur;
    HSD_MatAnim* ma;

    if (dobj != NULL) {
        cur = dobj;
        ma = matanim;
        while (cur != NULL) {
            if (cur->mobj != NULL && ma != NULL) {
                HSD_TObjAddAnimAll(cur->mobj->tobj, ma->texanim);
            }
            cur = cur->next;
            if (ma != NULL) {
                ma = ma->next;
            } else {
                ma = NULL;
            }
        }
    }
}

void kar_lbairride__near_80056440(HSD_DObj* dobj)
{
    HSD_DObj* cur;

    if (dobj != NULL) {
        cur = dobj;
        while (cur != NULL) {
            if (cur->mobj != NULL) {
                HSD_TObjAnimAll(cur->mobj->tobj);
            }
            cur = cur->next;
        }
    }
}

void kar_object_attach_ref_to_jobj(HSD_JObj* jobj, HSD_JObj* ref)
{
    HSD_JObjSetFlags(jobj, INSTANCE);
    jobj->child = ref;
    ref_INC(jobj->child);
}

void kar_object_detach_ref_from_jobj(HSD_JObj* jobj)
{
    HSD_JObjClearFlags(jobj, INSTANCE);
    HSD_JObjUnref(jobj->child);
    jobj->child = NULL;
}

s32 kar_object_find_unused_slot_index(s32 start, LbAirRideSlotNodeB* objects,
                                      LbAirRideSlotNodeA* slots,
                                      LbAirRideSlotNodeA* extra_slots)
{
    s32 used[8];
    s32 i;

    used[0] = 0;
    used[1] = 0;
    used[2] = 0;
    used[3] = 0;
    used[4] = 0;
    used[5] = 0;
    used[6] = 0;
    used[7] = 0;

    while (slots != NULL) {
        if (slots->slot < ARRAY_SIZE(used)) {
            used[slots->slot] = TRUE;
        }
        slots = slots->next;
    }

    while (objects != NULL) {
        used[kar_object_slot_remap_table[objects->slot_kind]] = TRUE;
        objects = objects->next;
    }

    while (extra_slots != NULL) {
        if (extra_slots->slot < ARRAY_SIZE(used)) {
            used[extra_slots->slot] = TRUE;
        }
        extra_slots = extra_slots->next;
    }

    for (i = start; i < (s32) ARRAY_SIZE(used) - 1; i++) {
        if (used[i] == FALSE) {
            return i;
        }
    }
    return -1;
}

#pragma push
#pragma dont_inline on
s32 kar_lbairride__near_8005729c(s32 start, LbAirRideSlotOwner* owner,
                                 LbAirRideSlotNodeA* extra_slots)
{
    return kar_object_find_unused_slot_index(start, owner->used_objects,
                                            owner->used_slots, extra_slots);
}
#pragma pop

s32 kar_lbairride__near_800572cc(s32 index)
{
    return lbl_80497CA8[index];
}

s32 kar_lbairride__near_800572e0(s32 index)
{
    return lbl_80497CC8[index];
}

s32 kar_lbairride__near_800572f4(s32 index)
{
    return lbl_80497CE8[index];
}

s32 kar_lbairride__near_80057308(s32 index)
{
    return lbl_80497D08[index];
}

HSD_LObj* kar_lbairride__near_80057468(LbAirRideLightEntry** entries)
{
    HSD_LObj* prev = NULL;
    HSD_LObj* lobj;
    HSD_LObj* first;

    while (*entries != NULL) {
        lobj = HSD_LObjLoadDesc((*entries)->desc);
        if ((*entries)->anim != NULL) {
            HSD_LObjAddAnimAll(lobj, *(*entries)->anim);
        }

        if (prev != NULL) {
            HSD_LObjSetNextInline(prev, lobj);
        } else {
            first = lobj;
        }

        prev = lobj;
        entries++;
    }

    return first;
}
