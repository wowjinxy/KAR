#include <dolphin/mtx/mtx.h>
#include <sysdolphin/wobj.h>
#include <sysdolphin/jobj.h>
#include <sysdolphin/robj.h>

void WObjInfoInit(void);

HSD_WObjInfo hsdWObj = { WObjInfoInit };
char WObjAssertAObj[] = "wobj->aobj";
char WObjAssertSpline[0x58] =
    "jp->u.spline\0\0\0\0"
    "hsdIsDescendantOf(info, &hsdWObj)\0\0\0"
    "sysdolphin_base_library\0"
    "had_wobj";
extern HSD_WObjInfo* WObjCurrentInfo;

extern char WObjSourceFile[7];     // "wobj.c"
extern char WObjAssertWObj[5];     // "wobj"
extern char WObjAssertJP[3];       // "jp"
extern char WObjJObjHeaderFile[7]; // "jobj.h"
extern char WObjAssertJObj[5];     // "jobj"
#define assert_line_named(line, cond, condstr)                                 \
    ((cond) ? ((void) 0) : __assert(WObjSourceFile, line, condstr))
#define assert_line_jobjh(line, cond)                                          \
    ((cond) ? ((void) 0) : __assert(WObjJObjHeaderFile, line, WObjAssertJObj))

extern double WObjDoubleZero; // 0.0
extern float WObjFloatZero;  // 0.0f
extern double WObjDoubleOne;  // 1.0
extern float WObjFloatOne;   // 1.0f

static inline void wobj_JObjSetupMatrix(HSD_JObj* jobj)
{
    BOOL dirty;

    if (jobj == NULL) {
        return;
    }
    assert_line_jobjh(0x25d, jobj);
    dirty = FALSE;
    if (!(jobj->flags & 0x800000) && (jobj->flags & 0x40)) {
        dirty = TRUE;
    }
    if (dirty) {
        HSD_JObjSetupMatrixSub(jobj);
    }
}

static inline void HSD_WObjRemoveAnim(HSD_WObj* wobj)
{
    if (wobj != NULL) {
        HSD_AObjRemove(wobj->aobj);
        wobj->aobj = NULL;
        HSD_RObjRemoveAnimAll(wobj->robj);
    }
}

void HSD_WObjReqAnim(HSD_WObj* wobj, f32 frame)
{
    if (wobj != NULL) {
        HSD_AObjReqAnim(wobj->aobj, frame);
        HSD_RObjReqAnimAll(wobj->robj, frame);
    }
}

void HSD_WObjAddAnim(HSD_WObj* wobj, HSD_WObjAnim* anim)
{
    if (wobj != NULL && anim != NULL) {
        if (wobj->aobj != NULL) {
            HSD_AObjRemove(wobj->aobj);
        }
        wobj->aobj = HSD_AObjLoadDesc(anim->aobjdesc);
        HSD_RObjAddAnimAll(wobj->robj, anim->robjanim);
    }
}

void WObjUpdateFunc(void* obj, u32 type, f32* fval)
{
    HSD_WObj* wobj;
    Vec p;
    HSD_JObj* jp;

    wobj = obj;
    if (wobj != NULL) {
        switch (type) {
        case 4:
            if (*fval < WObjDoubleZero) {
                *fval = WObjFloatZero;
            }
            if (WObjDoubleOne < *fval) {
                *fval = WObjFloatOne;
            }

            assert_line_named(152, wobj->aobj, WObjAssertAObj);
            jp = (HSD_JObj*)wobj->aobj->hsd_obj;
            assert_line_named(154, jp, WObjAssertJP);
            assert_line_named(155, jp->u.spline, WObjAssertSpline);

            splArcLengthPoint(&p, jp->u.spline, *fval);
            HSD_WObjSetPosition(wobj, &p);
            wobj->flags |= 1;
            break;

        case 5:
            HSD_WObjSetPositionX(wobj, *fval);
            break;

        case 6:
            HSD_WObjSetPositionY(wobj, *fval);
            break;

        case 7:
            HSD_WObjSetPositionZ(wobj, *fval);
            break;
        }
    }
}

void HSD_RObjAnimAll();

void HSD_WObjInterpretAnim(HSD_WObj* wobj)
{
    if (wobj != NULL) {
        HSD_AObjInterpretAnim(wobj->aobj, wobj,
                              (HSD_ObjUpdateFunc) HSD_WOBJ_METHOD(wobj)->update);
        HSD_RObjAnimAll(wobj->robj);
    }
}

int WObjLoad(HSD_WObj* wobj, HSD_WObjDesc* desc)
{
    HSD_WObjSetPosition(wobj, &desc->pos);
    if (wobj->robj != NULL) {
        HSD_RObjRemoveAll(wobj->robj);
    }
    wobj->robj = HSD_RObjLoadDesc(desc->robjdesc);
    HSD_RObjResolveRefsAll(wobj->robj, desc->robjdesc);
    return 0;
}

void HSD_WObjInit(HSD_WObj* wobj, HSD_WObjDesc* desc)
{
    if (wobj == NULL || desc == NULL) {
        return;
    }

    HSD_WObjSetPosition(wobj, &desc->pos);
    if (wobj->robj != NULL) {
        HSD_RObjRemoveAll(wobj->robj);
    }
    wobj->robj = HSD_RObjLoadDesc(desc->robjdesc);
    HSD_RObjResolveRefsAll(wobj->robj, desc->robjdesc);
}

void* hsdNew();

HSD_WObj* HSD_WObjLoadDesc(HSD_WObjDesc* desc)
{
    if (desc != NULL) {
        HSD_WObj* wobj;
        HSD_ClassInfo* info;
        if (desc->class_name == NULL || !(info = hsdSearchClassInfo(desc->class_name))) {
            wobj = HSD_WObjAlloc();
        } else {
            wobj = hsdNew(info);
            assert_line_named(260, wobj, WObjAssertWObj);
        }
        HSD_WOBJ_METHOD(wobj)->load(wobj, desc);
        return wobj;
    }
    return NULL;
}

void HSD_WObjSetPosition(HSD_WObj* wobj, Vec* pos)
{
    if (wobj == NULL || pos == NULL) {
        return;
    }

    wobj->pos = *pos;
    wobj->flags |= 0x2;
    wobj->flags &= 0xFFFFFFFE;
}

void HSD_WObjSetPositionX(HSD_WObj* wobj, f32 val)
{
    HSD_JObj* jp;

    if (wobj != NULL) {
        if ((wobj->flags & 1) != 0) {
            if (wobj->aobj != NULL && wobj->aobj->hsd_obj != NULL) {
                jp = (HSD_JObj*) wobj->aobj->hsd_obj;
                wobj_JObjSetupMatrix((HSD_JObj*) wobj->aobj->hsd_obj);
                PSMTXMultVec(jp->mtx, &wobj->pos, &wobj->pos);
            }
            wobj->flags &= 0xFFFFFFFE;
        }
        wobj->pos.x = val;
        wobj->flags |= 0x2;
    }
}

void HSD_WObjSetPositionY(HSD_WObj* wobj, f32 val)
{
    HSD_JObj* jp;

    if (wobj != NULL) {
        if ((wobj->flags & 1) != 0) {
            if (wobj->aobj != NULL && wobj->aobj->hsd_obj != NULL) {
                jp = (HSD_JObj*) wobj->aobj->hsd_obj;
                wobj_JObjSetupMatrix((HSD_JObj*) wobj->aobj->hsd_obj);
                PSMTXMultVec(jp->mtx, &wobj->pos, &wobj->pos);
            }
            wobj->flags &= 0xFFFFFFFE;
        }
        wobj->pos.y = val;
        wobj->flags |= 0x2;
    }
}

void HSD_WObjSetPositionZ(HSD_WObj* wobj, f32 val)
{
    HSD_JObj* jp;

    if (wobj != NULL) {
        if ((wobj->flags & 1) != 0) {
            if (wobj->aobj != NULL && wobj->aobj->hsd_obj != NULL) {
                jp = (HSD_JObj*) wobj->aobj->hsd_obj;
                wobj_JObjSetupMatrix((HSD_JObj*) wobj->aobj->hsd_obj);
                PSMTXMultVec(jp->mtx, &wobj->pos, &wobj->pos);
            }
            wobj->flags &= 0xFFFFFFFE;
        }
        wobj->pos.z = val;
        wobj->flags |= 0x2;
    }
}

void HSD_WObjGetPosition(HSD_WObj* wobj, Vec* vec)
{
    HSD_JObj* jp;

    if (wobj == NULL || vec == NULL) {
        return;
    }
    if ((wobj->flags & 1) != 0) {
        if (wobj->aobj != NULL && wobj->aobj->hsd_obj != NULL) {
            jp = (HSD_JObj*)wobj->aobj->hsd_obj;
            wobj_JObjSetupMatrix((HSD_JObj*)wobj->aobj->hsd_obj);
            PSMTXMultVec(jp->mtx, &wobj->pos, &wobj->pos);
        }
        wobj->flags &= 0xFFFFFFFE;
    }
    *vec = wobj->pos;
}

HSD_WObj* HSD_WObjAlloc(void)
{
    HSD_WObj* wobj =
        hsdNew((HSD_ClassInfo*) (WObjCurrentInfo ? WObjCurrentInfo : &hsdWObj));
    assert_line_named(599, wobj, WObjAssertWObj);
    return wobj;
}

void WObjRelease(HSD_Class* o)
{
    HSD_WObj* wobj = (HSD_WObj*) o;
    HSD_RObjRemoveAll(wobj->robj);
    HSD_AObjRemove(wobj->aobj);
    HSD_OBJECT_PARENT_INFO(&hsdWObj)->release(o);
}

void WObjAmnesia(HSD_ClassInfo* info)
{
    if (info == HSD_CLASS_INFO(WObjCurrentInfo)) {
        WObjCurrentInfo = NULL;
    }
    HSD_OBJECT_PARENT_INFO(&hsdWObj)->amnesia(info);
}

#pragma push
asm void WObjInfoInit(void)
{
    nofralloc
    stwu r1, -0x10(r1)
    mflr r0
    lis r4, hsdWObj@ha
    lis r3, hsdObj@ha
    stw r0, 0x14(r1)
    li r7, 0x44
    li r8, 0x20
    stw r31, 0xc(r1)
    addi r31, r4, hsdWObj@l
    addi r4, r3, hsdObj@l
    addi r3, r31, 0
    addi r5, r31, 0x84
    addi r6, r31, 0x9c
    bl hsdInitClassInfo
    lis r6, WObjRelease@ha
    lis r5, WObjAmnesia@ha
    lis r4, WObjLoad@ha
    lis r3, WObjUpdateFunc@ha
    addi r7, r6, WObjRelease@l
    addi r6, r31, 0
    addi r5, r5, WObjAmnesia@l
    addi r4, r4, WObjLoad@l
    addi r0, r3, WObjUpdateFunc@l
    stw r7, 0x30(r6)
    stw r5, 0x38(r6)
    stw r4, 0x3c(r6)
    stw r0, 0x40(r6)
    lwz r31, 0xc(r1)
    lwz r0, 0x14(r1)
    mtlr r0
    addi r1, r1, 0x10
    blr
}
#pragma pop
