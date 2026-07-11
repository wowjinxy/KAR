#include <global.h>
#include <dolphin/mtx/mtx.h>
#include <dolphin/mtx/vec.h>
#include <sysdolphin/lobj.h>
#include <sysdolphin/wobj.h>
#include <sysdolphin/aobj.h>
#include <sysdolphin/list.h>
#include <sysdolphin/cobj.h>
#include <sysdolphin/gobjproc.h>

#undef MAX_GXLIGHT
#define MAX_GXLIGHT 9

typedef u32 GXLightID;
#define GX_LIGHT0 0x001
#define GX_LIGHT1 0x002
#define GX_LIGHT2 0x004
#define GX_LIGHT3 0x008
#define GX_LIGHT4 0x010
#define GX_LIGHT5 0x020
#define GX_LIGHT6 0x040
#define GX_LIGHT7 0x080
#define GX_MAX_LIGHT 0x100
#define GX_LIGHT_NULL 0

void GXInitLightColor(GXLightObj*, GXColor);
void GXInitLightPos(GXLightObj*, f32, f32, f32);
void GXInitLightDir(GXLightObj*, f32, f32, f32);
void GXInitLightAttn(GXLightObj*, f32, f32, f32, f32, f32, f32);
void GXInitLightDistAttn(GXLightObj*, f32, f32, s32);
void GXInitLightSpot(GXLightObj*, f32, s32);
void GXLoadLightObjImm(GXLightObj*, GXLightID);

void MTXMultVec(Mtx, Vec*, Vec*);

void* hsdNew(HSD_ClassInfo*);
BOOL hsdIsDescendantOf(HSD_ClassInfo*, HSD_ClassInfo*);

extern HSD_LObjInfo* LObjDefaultClass; /* default_class */
extern HSD_SList* LObjCurrentLights; /* current_lights */
extern s32 LObjActiveCount;        /* nb_active_lights */
extern s32 LObjLightMaskDiffuse;        /* lightmask_diffuse */
extern s32 LObjLightMaskSpecular;        /* lightmask_specular */
extern s32 LObjLightMaskAttnFunc;        /* lightmask_attnfunc */
extern s32 LObjLightMaskAlpha;        /* lightmask_alpha */

extern HSD_LObj* LObjActiveLights[MAX_GXLIGHT]; /* active_lights */

extern f32 HSD_FloatMin[]; /* epsilon */
extern f32 HSD_FloatEpsilon;   /* epsilon */
extern Vec LObjZeroVecPosition;  /* zero vector */
extern Vec LObjZeroVecInterest;  /* zero vector */
extern char kar_srcfile_lobj_c[8]; /* "lobj.c" */
extern char LObjAssertZero[8]; /* "0" */

extern f64 LObjDoubleHalf; /* 0.5 (double) */
extern f32 LObjFloatZero; /* 0.0 */
extern f32 LObjFloatOne; /* 1.0 */
extern f32 LObjFloat255; /* 255.0 */
extern f32 LObjFloatHalf; /* 0.5 */
extern f32 LObjFloatNegOne; /* -1.0 */
extern f32 LObjFloat50; /* 50.0 */
extern f32 LObjFloatBigScale; /* 1048576.0 */

void LObjInfoInit(void);
HSD_LObjInfo hsdLObj = { LObjInfoInit };

s32 HSD_LightID2Index(GXLightID);
s32 HSD_Index2LightID(s32);
HSD_WObj* HSD_LObjGetPositionWObj(HSD_LObj*);
HSD_WObj* HSD_LObjGetInterestWObj(HSD_LObj*);
void HSD_LObjDeleteCurrent(HSD_LObj*);

HSD_SList* HSD_SListPrepend(HSD_SList* prev, void* data);

static inline f32 HSD_ClampFloat(f32 val, f32 min, f32 max)
{
    if (val <= min) {
        return min;
    } else if (val >= max) {
        return max;
    }
    return val;
}

u32 HSD_LObjGetFlags(HSD_LObj* lobj)
{
    if (lobj) {
        return lobj->flags;
    }
    return 0;
}

void HSD_LObjSetFlags(HSD_LObj* lobj, u32 flags)
{
    if (lobj == NULL) {
        return;
    }
    lobj->flags |= flags;
}

void HSD_LObjClearFlags(HSD_LObj* lobj, u32 flags)
{
    if (lobj == NULL) {
        return;
    }
    lobj->flags &= ~flags;
}

s32 HSD_LObjGetLightMaskDiffuse(void)
{
    return LObjLightMaskDiffuse;
}

s32 HSD_LObjGetLightMaskAttnFunc(void)
{
    return LObjLightMaskAttnFunc;
}

s32 HSD_LObjGetLightMaskAlpha(void)
{
    return LObjLightMaskAlpha;
}

s32 HSD_LObjGetLightMaskSpecular(void)
{
    return LObjLightMaskSpecular;
}

s32 HSD_LObjGetNbActive(void)
{
    return LObjActiveCount;
}

HSD_LObj* HSD_LObjGetActiveByID(GXLightID id)
{
    s32 idx = HSD_LightID2Index(id);
    if (idx >= 0 && idx < MAX_GXLIGHT) {
        return LObjActiveLights[idx];
    }
    return NULL;
}

HSD_LObj* HSD_LObjGetActiveByIndex(s32 idx)
{
    if (idx >= 0 && idx < MAX_GXLIGHT - 1) {
        return LObjActiveLights[idx];
    }
    return NULL;
}

void LObjUpdateFunc(HSD_LObj* lobj, s32 type, FObjData* val)
{
    if (lobj == NULL) {
        return;
    }
    switch (type) {
    case HSD_A_L_VIS:
        if (val->fv >= LObjDoubleHalf) {
            lobj->flags &= ~LOBJ_HIDDEN;
        } else {
            lobj->flags |= LOBJ_HIDDEN;
        }
        break;
    case HSD_A_L_A0:
    case HSD_A_L_CUTOFF:
        if (lobj->flags & LOBJ_RAW_PARAM) {
            lobj->u.attn.a0 = val->fv;
        } else {
            lobj->u.spot.cutoff = val->fv;
        }
        break;
    case HSD_A_L_A1:
    case HSD_A_L_REFDIST:
        if (lobj->flags & LOBJ_RAW_PARAM) {
            lobj->u.attn.a1 = val->fv;
        } else {
            lobj->u.spot.ref_dist = val->fv;
        }
        break;
    case HSD_A_L_A2:
    case HSD_A_L_REFBRIGHT:
        if (lobj->flags & LOBJ_RAW_PARAM) {
            lobj->u.attn.a2 = val->fv;
        } else {
            lobj->u.spot.ref_br = val->fv;
        }
        break;
    case HSD_A_L_K0:
        if (lobj->flags & LOBJ_RAW_PARAM) {
            lobj->u.attn.k0 = val->fv;
        }
        break;
    case HSD_A_L_K1:
        if (lobj->flags & LOBJ_RAW_PARAM) {
            lobj->u.attn.k1 = val->fv;
        }
        break;
    case HSD_A_L_K2:
        if (lobj->flags & LOBJ_RAW_PARAM) {
            lobj->u.attn.k2 = val->fv;
        }
        break;
    case HSD_A_L_LITC_R:
        lobj->color.r = LObjFloat255 *
            (val->fv <= LObjFloatZero ? LObjFloatZero :
             val->fv >= LObjFloatOne ? LObjFloatOne : val->fv);
        break;
    case HSD_A_L_LITC_G:
        lobj->color.g = LObjFloat255 *
            (val->fv <= LObjFloatZero ? LObjFloatZero :
             val->fv >= LObjFloatOne ? LObjFloatOne : val->fv);
        break;
    case HSD_A_L_LITC_B:
        lobj->color.b = LObjFloat255 *
            (val->fv <= LObjFloatZero ? LObjFloatZero :
             val->fv >= LObjFloatOne ? LObjFloatOne : val->fv);
        break;
    case HSD_A_L_LITC_A:
        lobj->color.a = LObjFloat255 *
            (val->fv <= LObjFloatZero ? LObjFloatZero :
             val->fv >= LObjFloatOne ? LObjFloatOne : val->fv);
        break;
    }
}

void HSD_LObjAnim(HSD_LObj* lobj)
{
    if (lobj != NULL) {
        HSD_AObjInterpretAnim(lobj->aobj, lobj, HSD_LOBJ_METHOD(lobj)->update);
        HSD_WObjInterpretAnim(HSD_LObjGetPositionWObj(lobj));
        HSD_WObjInterpretAnim(HSD_LObjGetInterestWObj(lobj));
    }
}

void HSD_LObjAnimAll(HSD_LObj* lobj)
{
    HSD_LObj* lp;

    if (lobj == NULL) {
        return;
    }

    for (lp = lobj; lp; lp = lp->next) {
        HSD_LObjAnim(lp);
    }
}

void HSD_LObjReqAnim(HSD_LObj* lobj, f32 startframe)
{
    if (lobj == NULL) {
        return;
    }

    HSD_AObjReqAnim(lobj->aobj, startframe);
    HSD_WObjReqAnim(HSD_LObjGetPositionWObj(lobj), startframe);
    HSD_WObjReqAnim(HSD_LObjGetInterestWObj(lobj), startframe);
}

void HSD_LObjReqAnimAll(HSD_LObj* lobj, f32 startframe)
{
    HSD_LObj* lp;

    if (lobj == NULL) {
        return;
    }

    for (lp = lobj; lp; lp = lp->next) {
        HSD_LObjReqAnim(lp, startframe);
    }
}

static inline BOOL TryNormalize(Vec* v)
{
    if (v == NULL || v == NULL) {
        return ~0;
    }
    if (__fabs(v->x) <= HSD_FloatMin[0] && __fabs(v->y) <= HSD_FloatMin[0] &&
        __fabs(v->z) <= HSD_FloatMin[0]) {
        return ~0;
    }
    PSVECNormalize(v, v);
    return 0;
}

void HSD_LObjGetLightVector(HSD_LObj* lobj, Vec* v)
{
    Vec position = LObjZeroVecPosition;
    Vec interest = LObjZeroVecInterest;

    if (lobj == NULL) {
        return;
    }
    HSD_LObjGetPosition(lobj, &position);
    HSD_LObjGetInterest(lobj, &interest);
    PSVECSubtract(&interest, &position, v);
    if (TryNormalize(v)) {
        f32 a = LObjFloatZero;
        f32 b = LObjFloatOne;
        v->x = a;
        v->y = a;
        v->z = b;
    }
}

void HSD_LObjSetup(HSD_LObj* lobj, GXColor* color, f32 shininess)
{
    f32 k0 = shininess;

    if (lobj->flags & LOBJ_HIDDEN || HSD_LObjGetType(lobj) == LOBJ_AMBIENT) {
        return;
    }
    if (lobj->flags & (LOBJ_DIFFUSE | LOBJ_ALPHA)) {
        if (lobj->hw_color.r != color->r || lobj->hw_color.g != color->g ||
            lobj->hw_color.b != color->b || lobj->hw_color.a != color->a) {
            GXInitLightColor(&lobj->lightobj, *color);
            lobj->hw_color = *color;
            lobj->flags |= LOBJ_DIFF_DIRTY;
        }
        if (lobj->flags & LOBJ_DIFF_DIRTY) {
            GXLoadLightObjImm(&lobj->lightobj, lobj->id);
            lobj->flags &= ~LOBJ_DIFF_DIRTY;
        }
    }
    if (lobj->spec_id != GX_LIGHT_NULL) {
        if (lobj->shininess != shininess) {
            k0 *= LObjFloatHalf;
            lobj->shininess = shininess;
            GXInitLightAttn(&lobj->spec_lightobj, LObjFloatZero, LObjFloatZero,
                            LObjFloatOne, k0, LObjFloatZero,
                            LObjFloatOne - k0);
            lobj->flags |= LOBJ_SPEC_DIRTY;
        }
        if (lobj->flags & LOBJ_SPEC_DIRTY) {
            GXLoadLightObjImm(&lobj->spec_lightobj, lobj->spec_id);
            lobj->flags &= ~LOBJ_SPEC_DIRTY;
        }
    }
}

static inline BOOL TryNormalize2(Vec* src, Vec* dst)
{
    if (__fabs(src->x) <= HSD_FloatMin[0] && __fabs(src->y) <= HSD_FloatMin[0] &&
        __fabs(src->z) <= HSD_FloatMin[0]) {
        return ~0;
    }
    PSVECNormalize(src, dst);
    return 0;
}

void HSD_LObjSetupSpecularInit(Mtx pmtx)
{
    s32 i;
    s32 num;
    Vec cdir;
    Vec jpos;

    jpos.x = pmtx[0][3];
    jpos.y = pmtx[1][3];
    jpos.z = pmtx[2][3];

    if (TryNormalize2(&jpos, &cdir)) {
        cdir.x = LObjFloatZero;
        cdir.y = LObjFloatZero;
        cdir.z = LObjFloatNegOne;
    }

    num = HSD_LObjGetNbActive();
    for (i = 0; i < num; i++) {
        Vec half, ldir;
        HSD_LObj* lobj = HSD_LObjGetActiveByIndex(i);

        if (lobj->spec_id == GX_LIGHT_NULL) {
            continue;
        }

        switch (HSD_LObjGetType(lobj)) {
        case LOBJ_POINT:
        case LOBJ_SPOT:
            PSVECSubtract(&jpos, &lobj->lvec, &ldir);
            if (!TryNormalize2(&ldir, &ldir)) {
                PSVECAdd(&ldir, &cdir, &half);
                break;
            }
            half.x = LObjFloatZero;
            half.y = LObjFloatZero;
            half.z = LObjFloatOne;
            goto init_light_dir;

        case LOBJ_INFINITE:
            PSVECAdd(&lobj->lvec, &cdir, &half);
            break;

        default:
            assert_line(634, 0);
        }

        if (TryNormalize2(&half, &half)) {
            half.x = LObjFloatZero;
            half.y = LObjFloatZero;
            half.z = LObjFloatOne;
        }

    init_light_dir:
        GXInitLightDir(&lobj->spec_lightobj, half.x, half.y, half.z);
        lobj->flags |= LOBJ_SPEC_DIRTY;
    }
}

static inline void LObjSetActive(HSD_LObj* lobj)
{
    s32 idx;

    if (HSD_LObjGetType(lobj) == LOBJ_AMBIENT) {
        idx = MAX_GXLIGHT - 1;
        if (LObjActiveLights[idx]) {
            return;
        }
    } else {
        idx = LObjActiveCount++;
    }
    LObjActiveLights[idx] = lobj;
    lobj->id = HSD_Index2LightID(idx);
}

static inline void setup_infinite_lightobj(HSD_LObj* lobj, MtxPtr vmtx)
{
    Vec lpos;

    HSD_LObjGetPosition(lobj, &lpos);
    lpos.x *= LObjFloatBigScale;
    lpos.y *= LObjFloatBigScale;
    lpos.z *= LObjFloatBigScale;
    PSMTXMultVec(vmtx, &lpos, &lpos);
    if (lobj->flags & LOBJ_DIFFUSE) {
        GXInitLightPos(&lobj->lightobj, lpos.x, lpos.y, lpos.z);
        GXInitLightAttn(&lobj->lightobj, LObjFloatOne, LObjFloatZero,
                        LObjFloatZero, LObjFloatOne, LObjFloatZero,
                        LObjFloatZero);
    }
    if (lobj->flags & LOBJ_SPECULAR) {
        GXInitLightPos(&lobj->spec_lightobj, lpos.x, lpos.y, lpos.z);
    }
}

static inline void setup_point_lightobj(HSD_LObj* lobj, Mtx mtx)
{
    Vec lpos;

    GXInitLightColor(&lobj->lightobj, lobj->color);
    lobj->hw_color = lobj->color;
    HSD_LObjGetPosition(lobj, &lpos);
    PSMTXMultVec(mtx, &lpos, &lpos);
    GXInitLightPos(&lobj->lightobj, lpos.x, lpos.y, lpos.z);
    GXInitLightPos(&lobj->spec_lightobj, lpos.x, lpos.y, lpos.z);
    if (lobj->flags & LOBJ_RAW_PARAM) {
        GXInitLightAttn(&lobj->lightobj, LObjFloatOne, LObjFloatZero,
                        LObjFloatZero, lobj->u.attn.k0, lobj->u.attn.k1,
                        lobj->u.attn.k2);
    } else {
        f32 ref_br = lobj->u.point.ref_br;
        f32 cutoff = lobj->u.point.cutoff;
        s32 dist_func = lobj->u.point.dist_func;

        if (ref_br < HSD_FloatEpsilon) {
            ref_br = HSD_FloatEpsilon;
        }
        if (cutoff < HSD_FloatEpsilon) {
            cutoff = HSD_FloatEpsilon;
        }
        GXInitLightDistAttn(&lobj->lightobj, cutoff, ref_br, dist_func);
        GXInitLightSpot(&lobj->lightobj, LObjFloatZero, 0);
        GXInitLightDistAttn(&lobj->spec_lightobj, cutoff, ref_br, dist_func);
    }
}

static inline void setup_spot_lightobj(HSD_LObj* lobj, Mtx mtx)
{
    Vec lpos;
    Vec ldir;

    HSD_LObjGetPosition(lobj, &lpos);
    PSMTXMultVec(mtx, &lpos, &lpos);
    HSD_LObjGetLightVector(lobj, &ldir);
    PSMTXMultVecSR(mtx, &ldir, &ldir);
    PSVECNormalize(&ldir, &ldir);
    GXInitLightPos(&lobj->lightobj, lpos.x, lpos.y, lpos.z);
    GXInitLightPos(&lobj->spec_lightobj, lpos.x, lpos.y, lpos.z);
    GXInitLightDir(&lobj->lightobj, ldir.x, ldir.y, ldir.z);
    if (lobj->flags & LOBJ_RAW_PARAM) {
        GXInitLightAttn(&lobj->lightobj, lobj->u.attn.a0, lobj->u.attn.a1,
                        lobj->u.attn.a2, lobj->u.attn.k0, lobj->u.attn.k1,
                        lobj->u.attn.k2);
    } else {
        f32 ref_br = lobj->u.spot.ref_br;
        f32 ref_dist = lobj->u.spot.ref_dist;
        f32 cutoff = lobj->u.spot.cutoff;
        s32 spot_func = lobj->u.spot.spot_func;
        s32 dist_func = lobj->u.spot.dist_func;

        if (ref_br < HSD_FloatEpsilon) {
            ref_br = HSD_FloatEpsilon;
        }
        if (ref_dist < HSD_FloatEpsilon) {
            ref_dist = HSD_FloatEpsilon;
        }
        GXInitLightDistAttn(&lobj->lightobj, ref_dist, ref_br, dist_func);
        GXInitLightSpot(&lobj->lightobj, cutoff, 0);
        GXInitLightDistAttn(&lobj->spec_lightobj, ref_dist, ref_br, dist_func);
    }
}

static inline void setup_diffuse_lightobj(HSD_LObj* lobj)
{
    GXInitLightColor(&lobj->lightobj, lobj->color);
    lobj->hw_color = lobj->color;
    lobj->flags |= LOBJ_DIFF_DIRTY;
    LObjLightMaskDiffuse |= lobj->id;

    switch (HSD_LObjGetType(lobj)) {
    case LOBJ_SPOT:
    case LOBJ_POINT:
        LObjLightMaskAttnFunc |= lobj->id;
        break;
    case LOBJ_INFINITE:
        break;
    default:
        assert_line(664, 0);
    }

    if (lobj->flags & LOBJ_ALPHA) {
        LObjLightMaskAlpha |= lobj->id;
    }
}

static inline void setup_spec_lightobj(HSD_LObj* lobj, Mtx mtx, GXLightID spec_id)
{
    f32 x;

    lobj->spec_id = spec_id;
    if (spec_id != GX_LIGHT_NULL) {
        GXInitLightColor(&lobj->spec_lightobj, lobj->color);
        lobj->shininess = LObjFloat50;

        x = lobj->shininess;
        x *= LObjFloatHalf;
        GXInitLightAttn(&lobj->spec_lightobj, LObjFloatZero, LObjFloatZero,
                        LObjFloatOne, x, LObjFloatZero, LObjFloatOne - x);
        switch (HSD_LObjGetType(lobj)) {
        case LOBJ_POINT:
        case LOBJ_SPOT:
            HSD_LObjGetPosition(lobj, &lobj->lvec);
            PSMTXMultVec(mtx, &lobj->lvec, &lobj->lvec);
            break;
        case LOBJ_INFINITE:
            HSD_LObjGetLightVector(lobj, &lobj->lvec);
            PSMTXMultVecSR(mtx, &lobj->lvec, &lobj->lvec);
            PSVECNormalize(&lobj->lvec, &lobj->lvec);
            break;
        default:
            assert_line(704, 0);
        }
        lobj->flags |= LOBJ_SPEC_DIRTY;
        LObjLightMaskSpecular |= spec_id;
    }
}

void HSD_LObjSetupInit(HSD_CObj* cobj)
{
    MtxPtr vmtx;
    s32 idx, num, i;
    HSD_SList* list;

    LObjLightMaskDiffuse = GX_LIGHT_NULL;
    list = LObjCurrentLights;
    vmtx = cobj->view_mtx;

    LObjActiveLights[0] = NULL;
    LObjActiveLights[1] = NULL;
    LObjActiveLights[2] = NULL;
    LObjActiveLights[3] = NULL;
    LObjActiveLights[4] = NULL;
    LObjActiveLights[5] = NULL;
    LObjActiveLights[6] = NULL;
    LObjActiveLights[7] = NULL;
    LObjActiveLights[8] = NULL;
    LObjLightMaskSpecular = GX_LIGHT_NULL;
    LObjLightMaskAttnFunc = GX_LIGHT_NULL;
    LObjLightMaskAlpha = GX_LIGHT_NULL;
    LObjActiveCount = 0;
    idx = 0;

    for (; idx < MAX_GXLIGHT - 1 && list; list = list->next) {
        HSD_LObj* lobj = list->data;
        u32 flags;
        u32 type;
        s32 ref_type;

        if (lobj == NULL) {
            continue;
        }

        flags = lobj->flags;

        if (flags & LOBJ_HIDDEN) {
            continue;
        }

        type = HSD_LObjGetType(lobj);
        ref_type = flags & (LOBJ_DIFFUSE | LOBJ_SPECULAR | LOBJ_ALPHA);

        if (ref_type == 0) {
            continue;
        }

        LObjSetActive(lobj);
        idx = HSD_LObjGetNbActive();

        lobj->spec_id = GX_LIGHT_NULL;

        switch (type) {
        case LOBJ_INFINITE:
            setup_infinite_lightobj(lobj, vmtx);
            break;
        case LOBJ_POINT:
            setup_point_lightobj(lobj, vmtx);
            break;
        case LOBJ_SPOT:
            setup_spot_lightobj(lobj, vmtx);
            break;
        case LOBJ_AMBIENT:
            continue;
        }

        if (ref_type & (LOBJ_DIFFUSE | LOBJ_ALPHA)) {
            setup_diffuse_lightobj(lobj);
        } else if (ref_type & LOBJ_SPECULAR) {
            setup_spec_lightobj(lobj, vmtx, lobj->id);
        }
    }

    if (!HSD_LObjGetActiveByID(GX_MAX_LIGHT)) {
        for (; list; list = list->next) {
            HSD_LObj* lobj = list->data;
            u32 flags;

            if (lobj == NULL) {
                continue;
            }
            flags = lobj->flags;
            if (flags & LOBJ_HIDDEN) {
                continue;
            }
            if (HSD_LObjGetType(lobj) != LOBJ_AMBIENT) {
                continue;
            }
            if (!(flags & (LOBJ_DIFFUSE | LOBJ_ALPHA))) {
                continue;
            }
            LObjSetActive(lobj);
            break;
        }
    }

    num = HSD_LObjGetNbActive();
    for (i = 0; idx < MAX_GXLIGHT - 1 && i < num; i++) {
        HSD_LObj* lobj = HSD_LObjGetActiveByIndex(i);

        if (lobj == NULL) {
            continue;
        }
        if (!(lobj->flags & LOBJ_SPECULAR)) {
            continue;
        }
        if (!(lobj->flags & (LOBJ_DIFFUSE | LOBJ_ALPHA))) {
            continue;
        }
        setup_spec_lightobj(lobj, vmtx, HSD_Index2LightID(idx++));
    }

    for (i = 0; i < MAX_GXLIGHT - 1; i++) {
        HSD_LObj* lobj;

        if (!(lobj = HSD_LObjGetActiveByIndex(i))) {
            return;
        }
        HSD_LObjSetup(lobj, &lobj->color, lobj->shininess);
    }
}

void HSD_LObjAddCurrent(HSD_LObj* lobj)
{
    HSD_SList* node;
    HSD_SList** p;

    if (lobj != NULL) {
        node = LObjCurrentLights;
        while (node != NULL) {
            if (node->data == lobj) {
                HSD_LObjDeleteCurrent(lobj);
                break;
            }
            node = node->next;
        }
        ref_INC(lobj);
        for (p = &LObjCurrentLights; *p != NULL; p = &(*p)->next) {
            if (HSD_LObjGetPriority((*p)->data) > HSD_LObjGetPriority(lobj)) {
                break;
            }
        }
        *p = HSD_SListPrepend(*p, lobj);
    }
}

static inline bool ref_DEC(void* o)
{
    bool ret;
    if ((ret = (HSD_OBJ(o)->ref_count == HSD_OBJ_NOREF))) {
        return ret;
    }
    return HSD_OBJ(o)->ref_count-- == 0;
}

static inline void HSD_WObjUnref(HSD_WObj* wobj)
{
    if (wobj == NULL) {
        return;
    }
    if (ref_DEC(wobj)) {
        if (wobj != NULL) {
            HSD_OBJECT_METHOD(wobj)->release((HSD_Class*) wobj);
            HSD_OBJECT_METHOD(wobj)->destroy((HSD_Class*) wobj);
        }
    }
}

static inline void HSD_LObjUnrefThis(HSD_LObj* lobj)
{
    if (lobj != NULL && ref_DEC(lobj)) {
        if (lobj != NULL) {
            HSD_OBJECT_METHOD(lobj)->release((HSD_Class*) lobj);
            HSD_OBJECT_METHOD(lobj)->destroy((HSD_Class*) lobj);
        }
    }
}

void HSD_LObjDeleteCurrent(HSD_LObj* lobj)
{
    if (lobj != NULL) {
        HSD_SList** p;
        for (p = &LObjCurrentLights; *p != NULL; p = &(*p)->next) {
            if ((*p)->data == lobj) {
                s32 i;
                for (i = 0; i < MAX_GXLIGHT; i++) {
                    if (lobj == LObjActiveLights[i]) {
                        LObjActiveLights[i] = NULL;
                    }
                }
                *p = HSD_SListRemove(*p);
                HSD_LObjUnrefThis(lobj);
                return;
            }
        }
    }
}

static inline void LObjRemoveAll(void)
{
    LObjActiveLights[0] = NULL;
    LObjActiveLights[1] = NULL;
    LObjActiveLights[2] = NULL;
    LObjActiveLights[3] = NULL;
    LObjActiveLights[4] = NULL;
    LObjActiveLights[5] = NULL;
    LObjActiveLights[6] = NULL;
    LObjActiveLights[7] = NULL;
    LObjActiveLights[8] = NULL;
    LObjActiveCount = 0;
    while (LObjCurrentLights != NULL) {
        HSD_LObjUnrefThis(LObjCurrentLights->data);
        LObjCurrentLights = HSD_SListRemove(LObjCurrentLights);
    }
}

void HSD_LObjDeleteCurrentAll(HSD_LObj* lobj)
{
    if (lobj != NULL) {
        while (lobj != NULL) {
            HSD_LObjDeleteCurrent(lobj);
            lobj = lobj->next;
        }
        return;
    }
    LObjRemoveAll();
}

void HSD_LObjSetCurrentAll(HSD_LObj* lobj)
{
    HSD_LObj* cur;

    LObjRemoveAll();
    for (cur = lobj; cur != NULL; cur = cur->next) {
        HSD_LObjAddCurrent(cur);
    }
}

HSD_LObj* HSD_LObjGetCurrentByType(u16 flags)
{
    u32 type = flags & LOBJ_TYPE_MASK;
    HSD_SList* cur = LObjCurrentLights;
    while (cur != NULL) {
        HSD_LObj* lobj = cur->data;
        if (type == (lobj->flags & LOBJ_TYPE_MASK)) {
            return lobj;
        }
        cur = cur->next;
    }
    return NULL;
}

s32 HSD_LightID2Index(GXLightID id)
{
    s32 idx;

    switch (id) {
    case GX_LIGHT0:
        idx = 0;
        break;
    case GX_LIGHT1:
        idx = 1;
        break;
    case GX_LIGHT2:
        idx = 2;
        break;
    case GX_LIGHT3:
        idx = 3;
        break;
    case GX_LIGHT4:
        idx = 4;
        break;
    case GX_LIGHT5:
        idx = 5;
        break;
    case GX_LIGHT6:
        idx = 6;
        break;
    case GX_LIGHT7:
        idx = 7;
        break;
    case GX_MAX_LIGHT:
        idx = 8;
        break;
    default:
        assert_line(1192, 0);
    }
    return idx;
}

s32 HSD_Index2LightID(s32 index)
{
    switch (index) {
    case 0:
        return GX_LIGHT0;
    case 1:
        return GX_LIGHT1;
    case 2:
        return GX_LIGHT2;
    case 3:
        return GX_LIGHT3;
    case 4:
        return GX_LIGHT4;
    case 5:
        return GX_LIGHT5;
    case 6:
        return GX_LIGHT6;
    case 7:
        return GX_LIGHT7;
    case 8:
        return GX_MAX_LIGHT;
    default:
        return GX_LIGHT_NULL;
    }
}

void HSD_LObjRemoveAll(HSD_LObj* lobj)
{
    HSD_LObj* next;
    HSD_LObj* cur;

    cur = lobj;
    while (cur != NULL) {
        next = cur->next;
        HSD_LObjDeleteCurrent(cur);
        HSD_LObjUnrefThis(cur);
        cur = next;
    }
}

void HSD_LObjSetColor(HSD_LObj* lobj, GXColor color)
{
    lobj->color = color;
}

void HSD_LObjGetColor(HSD_LObj* lobj, GXColor* color)
{
    *color = lobj->color;
}

void HSD_LObjSetPosition(HSD_LObj* lobj, Vec* position)
{
    assert_line(1391, lobj);
    if (lobj->position == NULL) {
        lobj->position = HSD_WObjAlloc();
        assert_line(1394, lobj->position);
    }
    HSD_WObjSetPosition(lobj->position, position);
}

BOOL HSD_LObjGetPosition(HSD_LObj* lobj, Vec* pos)
{
    if (lobj != NULL && lobj->position != NULL) {
        HSD_WObjGetPosition(lobj->position, pos);
        return TRUE;
    }
    return FALSE;
}

void HSD_LObjSetInterest(HSD_LObj* lobj, Vec* interest)
{
    assert_line(1427, lobj);
    if (lobj->interest == NULL) {
        lobj->interest = HSD_WObjAlloc();
        assert_line(1430, lobj->interest);
    }
    HSD_WObjSetPosition(lobj->interest, interest);
}

BOOL HSD_LObjGetInterest(HSD_LObj* lobj, Vec* interest)
{
    if (lobj != NULL && lobj->interest != NULL) {
        HSD_WObjGetPosition(lobj->interest, interest);
        return TRUE;
    }
    return FALSE;
}

HSD_WObj* HSD_LObjGetPositionWObj(HSD_LObj* lobj)
{
    if (lobj != NULL) {
        return lobj->position;
    }
    return NULL;
}

HSD_WObj* HSD_LObjGetInterestWObj(HSD_LObj* lobj)
{
    if (lobj != NULL) {
        return lobj->interest;
    }
    return NULL;
}

static inline void HSD_LObjSetPositionWObj(HSD_LObj* lobj, HSD_WObj* wobj)
{
    if (lobj == NULL) {
        return;
    }
    HSD_WObjUnref(lobj->position);
    lobj->position = wobj;
}

static inline void HSD_LObjSetInterestWObj(HSD_LObj* lobj, HSD_WObj* wobj)
{
    if (lobj == NULL) {
        return;
    }
    HSD_WObjUnref(lobj->interest);
    lobj->interest = wobj;
}

static inline void HSD_LObjSetSpot(HSD_LObj* lobj, f32 cutoff, s32 point_func)
{
    if (lobj != NULL) {
        lobj->u.point.cutoff = cutoff;
        lobj->u.point.point_func = point_func;
    }
}

static inline void HSD_LObjSetDistAttn(HSD_LObj* lobj, f32 ref_dist, f32 ref_br,
                                       s32 dist_func)
{
    if (lobj != NULL) {
        lobj->u.point.ref_dist = ref_dist;
        lobj->u.point.ref_br = ref_br;
        lobj->u.point.dist_func = dist_func;
    }
}

static inline void HSD_LObjSetAttnA(HSD_LObj* lobj, f32 a0, f32 a1, f32 a2)
{
    if (lobj == NULL) {
        return;
    }
    lobj->u.attn.a0 = a0;
    lobj->u.attn.a1 = a1;
    lobj->u.attn.a2 = a2;
}

static inline void HSD_LObjSetAttnK(HSD_LObj* lobj, f32 k0, f32 k1, f32 k2)
{
    if (lobj == NULL) {
        return;
    }
    lobj->u.attn.k0 = k0;
    lobj->u.attn.k1 = k1;
    lobj->u.attn.k2 = k2;
}

static inline void HSD_LObjSetAttn(HSD_LObj* lobj, f32 a0, f32 a1, f32 a2,
                                   f32 k0, f32 k1, f32 k2)
{
    HSD_LObjSetAttnA(lobj, a0, a1, a2);
    HSD_LObjSetAttnK(lobj, k0, k1, k2);
}

#pragma push
#pragma force_active on
static char unused[] = "hsdIsDescendantOf(info, &hsdLObj)";
#pragma pop

int LObjLoad(HSD_LObj* lobj, HSD_LightDesc* ldesc)
{
    HSD_LObjSetColor(lobj, ldesc->color);
    HSD_LObjSetFlags(lobj, ldesc->flags);
    switch (ldesc->flags & LOBJ_TYPE_MASK) {
    case LOBJ_AMBIENT:
        break;
    case LOBJ_INFINITE:
        HSD_LObjSetPositionWObj(lobj, HSD_WObjLoadDesc(ldesc->position));
        break;
    case LOBJ_POINT:
        HSD_LObjSetPositionWObj(lobj, HSD_WObjLoadDesc(ldesc->position));
        if (ldesc->attnflags & LOBJ_LIGHT_ATTN) {
            HSD_LObjSetFlags(lobj, LOBJ_RAW_PARAM);
            HSD_LObjSetAttnK(lobj, ldesc->u.attn->k0, ldesc->u.attn->k1,
                             ldesc->u.attn->k2);
        } else {
            HSD_LObjSetDistAttn(lobj, ldesc->u.point->ref_dist,
                                ldesc->u.point->ref_br,
                                ldesc->u.point->dist_func);
        }
        break;
    case LOBJ_SPOT:
        HSD_LObjSetPositionWObj(lobj, HSD_WObjLoadDesc(ldesc->position));
        HSD_LObjSetInterestWObj(lobj, HSD_WObjLoadDesc(ldesc->interest));
        if (ldesc->attnflags & LOBJ_LIGHT_ATTN) {
            HSD_LObjSetFlags(lobj, LOBJ_RAW_PARAM);
            HSD_LObjSetAttn(lobj, ldesc->u.attn->a0, ldesc->u.attn->a1,
                            ldesc->u.attn->a2, ldesc->u.attn->k0,
                            ldesc->u.attn->k1, ldesc->u.attn->k2);
        } else {
            HSD_LObjSetDistAttn(lobj, ldesc->u.spot->ref_dist,
                                ldesc->u.spot->ref_br,
                                ldesc->u.spot->dist_func);
            HSD_LObjSetSpot(lobj, ldesc->u.spot->cutoff,
                            ldesc->u.spot->spot_func);
        }
        break;
    default:
        OSReport("unexpected lightdesc flags (%x)\n", ldesc->flags);
        HSD_Panic(__FILE__, 0x660, "");
        break;
    }
    return 0;
}

HSD_LObj* HSD_LObjLoadDesc(HSD_LightDesc* ldesc)
{
    HSD_LObj *top, **p = &top;

    for (; ldesc; ldesc = ldesc->next) {
        HSD_ClassInfo* info;

        if (!ldesc->class_name ||
            !(info = hsdSearchClassInfo(ldesc->class_name))) {
            HSD_LObj* new =
                hsdNew(LObjDefaultClass ? HSD_CLASS_INFO(LObjDefaultClass)
                                     : HSD_CLASS_INFO(&hsdLObj));
            assert_line(1500, new);
            *p = new;
        } else {
            *p = hsdNew(info);
            assert_line(1666, *p);
        }
        HSD_LOBJ_INFO(HSD_CLASS_METHOD(*p))->load(*p, ldesc);
        p = &(*p)->next;
    }
    *p = NULL;

    return top;
}

void HSD_LObjAddAnim(HSD_LObj* lobj, HSD_LightAnim* lanim)
{
    if (lobj == NULL) {
        return;
    }

    if (lanim != NULL) {
        if (lobj->aobj) {
            HSD_AObjRemove(lobj->aobj);
        }
        lobj->aobj = HSD_AObjLoadDesc(lanim->aobjdesc);
        HSD_WObjAddAnim(HSD_LObjGetPositionWObj(lobj), lanim->position_anim);
        HSD_WObjAddAnim(HSD_LObjGetInterestWObj(lobj), lanim->interest_anim);
    }
}

void HSD_LObjAddAnimAll(HSD_LObj* lobj, HSD_LightAnim* lanim)
{
    HSD_LObj* lp;
    HSD_LightAnim* la;

    if (lobj == NULL) {
        return;
    }

    for (lp = lobj, la = lanim; lp; lp = next_p(lp), la = next_p(la)) {
        HSD_LObjAddAnim(lp, la);
    }
}

void LObjRelease(HSD_Class* o)
{
    HSD_LObj* lobj = HSD_LOBJ(o);

    HSD_AObjRemove(lobj->aobj);
    HSD_WObjUnref(HSD_LObjGetPositionWObj(lobj));
    HSD_WObjUnref(HSD_LObjGetInterestWObj(lobj));

    HSD_OBJECT_PARENT_INFO(&hsdLObj)->release(o);
}

void LObjAmnesia(HSD_ClassInfo* info)
{
    if (info == HSD_CLASS_INFO(LObjDefaultClass)) {
        LObjDefaultClass = NULL;
    }
    if (info == HSD_CLASS_INFO(&hsdLObj)) {
        LObjCurrentLights = NULL;
    }
    HSD_OBJECT_PARENT_INFO(&hsdLObj)->amnesia(info);
}

void LObjInfoInit(void)
{
    hsdInitClassInfo(HSD_CLASS_INFO(&hsdLObj), &hsdObj,
                     "sysdolphin_base_library", "hsd_lobj",
                     sizeof(HSD_LObjInfo), sizeof(HSD_LObj));
    HSD_CLASS_INFO(&hsdLObj)->release = LObjRelease;
    HSD_CLASS_INFO(&hsdLObj)->amnesia = LObjAmnesia;
    HSD_LOBJ_INFO(&hsdLObj)->load = LObjLoad;
    HSD_LOBJ_INFO(&hsdLObj)->update = (void (*)()) LObjUpdateFunc;
}
