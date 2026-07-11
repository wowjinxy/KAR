#include <global.h>

#include <dolphin/gx/gxtypes.h>
#include <dolphin/mtx/mtxtypes.h>
#include <sysdolphin/cobj.h>
#include <sysdolphin/displayfunc.h>
#include <sysdolphin/dobj.h>
#include <sysdolphin/jobj.h>
#include <sysdolphin/video.h>

#define HSD_JOBJ_METHOD(o) ((HSD_JObjInfo*) ((o)->object.parent.class_info))
#define HSD_ZLIST_NEXT(list, offset) (*(HSD_ZList**) ((u8*) (list) + (offset)))
#define HSD_ZLIST_DEPTH(list) (*(f32*) ((u8*) (list) + 0x2C))
#define GX_FIFO_U8 (*(volatile u8*) 0xCC008000)
#define GX_FIFO_F32 (*(volatile f32*) 0xCC008000)

typedef struct _GXTexObj {
    u8 pad[0x20];
} GXTexObj;

typedef struct _HSD_ZList {
    Mtx pmtx;
    MtxPtr vmtx;
    HSD_JObj* jobj;
    u32 rendermode;
    struct _HSD_ZList* next_opa;
    struct _HSD_ZList* next_xlu;
    struct _HSD_ZList* next_all;
} HSD_ZList;

extern void HSD_Panic(char* file, s32 line, char* msg);
extern void HSD_LObjSetupSpecularInit(Mtx pmtx);
extern void HSD_JObjSetCurrent(HSD_JObj* jobj);
extern HSD_CObj* HSD_CObjGetCurrent(void);
extern MtxPtr HSD_MtxAlloc(void);
extern void HSD_MtxFree(MtxPtr mtx);
extern void PSMTXConcat(Mtx a, Mtx b, Mtx ab);
extern void PSMTXCopy(Mtx src, Mtx dst);
extern void HSD_MtxInverseConcat(Mtx inv, Mtx src, Mtx dest);
extern void PSMTXInverse(MtxPtr src, Mtx dst);
extern void memset(void* ptr, s32 value, u32 size);
extern f32 PSVECMag(Vec* vec);
extern void PSVECScale(f32 scale, Vec* src, Vec* dst);
extern void PSVECCrossProduct(Vec* a, Vec* b, Vec* dst);
extern void PSVECNormalize(Vec* src, Vec* dst);
extern void HSD_ClearVtxDesc(void);
extern void HSD_StateInitTev(void);
extern void HSD_SetupRenderMode(u32 rendermode);
extern void PSMTXScale(Mtx m, f32 xs, f32 ys, f32 zs);
extern void kar_grcoll__near_803d1738(Mtx m, s32 axis, f32 rad);
extern f32 HSD_FloatEpsilon[];
extern Vec HSD_UnitZVec;

extern void GXInitTexObj(GXTexObj* obj, void* image_ptr, u16 width, u16 height, u32 format,
                         u32 wrap_s, u32 wrap_t, u32 mipmap);
extern void GXLoadTexObj(GXTexObj* obj, u32 mapid);
extern void GXSetNumTexGens(u32 n);
extern void GXSetTexCoordGen2(u16 dst_coord, u32 func, u32 src_param, u32 mtx, u32 normalize,
                              u32 post_mtx);
extern void GXSetNumTevStages(u8 n);
extern void GXSetTevOrder(u8 stage, u32 coord, u32 map, u32 color);
extern void GXSetTevOp(u8 stage, u32 mode);
extern void GXSetZTexture(u32 op, u32 fmt, u32 bias);
extern void GXSetCullMode(u32 mode);
extern void GXSetAlphaCompare(u32 comp0, u8 ref0, u32 op, u32 comp1, u8 ref1);
extern void GXSetZCompLoc(u32 before_tex);
extern void GXSetZMode(u32 enable, u32 func, u32 update_enable);
extern void GXSetBlendMode(u32 type, u32 src_factor, u32 dst_factor, u32 op);
extern void GXSetColorUpdate(u32 update_enable);
extern void GXSetAlphaUpdate(u32 update_enable);
extern void GXSetNumChans(u8 n);
extern void GXSetChanCtrl(u8 chan, u32 enable, u32 amb_src, u32 mat_src, u32 light_mask,
                          u32 diff_fn, u32 attn_fn);
extern void GXClearVtxDesc(void);
extern void GXSetVtxAttrFmt(u32 vtxfmt, u32 attr, u32 comp_cnt, u32 comp_type, u8 frac);
extern void GXLoadPosMtxImm(MtxPtr mtx, u32 id);
extern void GXSetCurrentMtx(u32 id);
extern void GXSetVtxDesc(u32 attr, u32 type);
extern void GXBegin(u8 prim, u8 vtxfmt, u16 nverts);
extern void HSD_StateInvalidate(s32 mask);

extern u8 JObjSPtclColor[4];
extern HSD_ObjAllocData HSD_ZListAllocData;
extern GXRenderModeObj HSD_DefaultRenderModeObj;
extern Mtx HSD_IdentityMtx;

void _HSD_ZListClear(void);

extern HSD_ZList* HSD_ZListAll;
extern HSD_ZList* HSD_ZListOpaque;
extern HSD_ZList* HSD_ZListTranslucent;

char DisplayFuncSourceFile[] = "displayfunc.c";
char DisplayFuncUnknownBillboardMsg[] = "unkown type of billboard.\n";
u32 DisplayFuncWhiteTexImage[32] = {
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
};

HSD_ZList** HSD_ZListAllTail = &HSD_ZListAll;
HSD_ZList** HSD_ZListOpaqueTail = &HSD_ZListOpaque;
HSD_ZList** HSD_ZListTranslucentTail = &HSD_ZListTranslucent;
char DisplayFuncJObjString[] = "jobj";
char DisplayFuncXString[] = "x";
char JObjHeaderSourceFile[] = "jobj.h";
s32 HSD_CurrentHeap = -1;
GXRenderModeObj* HSD_RenderMode = &HSD_DefaultRenderModeObj;
s32 HSD_ZBufferFormat = 2;
s32 HSD_FIFOSize = 0x40000;
s32 HSD_XFBMaxNum = 2;
s32 HSD_ClearColor = 0;
char HSD_AssertAddrString[] = "addr";

s32 HSD_ZSortMode;
s32 HSD_ZSortCompare;
HSD_ZList* HSD_ZListAll;
HSD_ZList* HSD_ZListOpaque;
s32 HSD_ZListOpaqueCount;
HSD_ZList* HSD_ZListTranslucent;
s32 HSD_ZListTranslucentCount[2];
const u32 HSD_DefaultClearColor[2];

void HSD_ZListInitAllocData(void)
{
    HSD_ObjAllocInit(&HSD_ZListAllocData, sizeof(HSD_ZList), 4);
}

void HSD_StateInitDirect(u32 vtxfmt, u32 rendermode)
{
    HSD_ClearVtxDesc();
    GXSetVtxAttrFmt(vtxfmt, 9, 1, 4, 0);
    GXSetVtxAttrFmt(vtxfmt, 0xB, 1, 5, 0);
    HSD_StateInitTev();
    HSD_SetupRenderMode(rendermode | 0x28000000);
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xB, 1);
    GXSetCurrentMtx(0);
}

extern f64 __frsqrte(f64 x);

extern f64 __fnmsub(f64 a, f64 c, f64 b);
extern f32 __fmadds(f32 a, f32 c, f32 b);

static inline f32 displayfunc_sqrtf(f32 x)
{
    volatile f32 y;

    if (x > 0.0F) {
        f64 guess = __frsqrte((f64) x);
        guess = 0.5 * guess * __fnmsub(x, guess * guess, 3.0);
        guess = 0.5 * guess * __fnmsub(x, guess * guess, 3.0);
        guess = 0.5 * guess * __fnmsub(x, guess * guess, 3.0);
        y = (f32) (x * guess);
        return y;
    }
    return x;
}

static inline f32 displayfunc_col_mag(MtxPtr mtx, s32 col)
{
    return displayfunc_sqrtf(mtx[0][col] * mtx[0][col] + mtx[1][col] * mtx[1][col] +
                              mtx[2][col] * mtx[2][col]);
}

void mkVBillBoardMtx(HSD_JObj* jobj, Mtx src, Mtx dst)
{
    Vec pos, ay, ay_n, ax, az;
    f32 sx, sz;
    f32 mag;

    pos.x = src[0][3];
    pos.y = src[1][3];
    pos.z = src[2][3];

    ay.x = src[0][1];
    ay.y = src[1][1];
    ay.z = src[2][1];

    mag = PSVECMag(&ay);
    PSVECScale(1.0F / (HSD_FloatEpsilon[0] + mag), &ay, &ay_n);

    sx = displayfunc_col_mag(src, 0);
    sz = displayfunc_col_mag(src, 2);

    if (jobj->flags & PBILLBOARD) {
        Vec pos_n;

        mag = PSVECMag(&pos);
        PSVECScale(-1.0F / (HSD_FloatEpsilon[0] + mag), &pos, &pos_n);
        PSVECCrossProduct(&ay_n, &pos_n, &ax);
    } else {
        Vec zOne = HSD_UnitZVec;
        PSVECCrossProduct(&ay_n, &zOne, &ax);
    }

    mag = PSVECMag(&ax);
    if (mag < HSD_FloatEpsilon[0]) {
        PSMTXCopy(src, dst);
    } else {
        f32 sxFactor = sx / mag;
        f32 szFactor;

        PSVECCrossProduct(&ax, &ay_n, &az);
        mag = PSVECMag(&az);
        szFactor = sz / (HSD_FloatEpsilon[0] + mag);

        dst[0][0] = sxFactor * ax.x;
        dst[1][0] = sxFactor * ax.y;
        dst[2][0] = sxFactor * ax.z;

        dst[0][1] = ay.x;
        dst[1][1] = ay.y;
        dst[2][1] = ay.z;

        dst[0][2] = szFactor * az.x;
        dst[1][2] = szFactor * az.y;
        dst[2][2] = szFactor * az.z;

        dst[0][3] = pos.x;
        dst[1][3] = pos.y;
        dst[2][3] = pos.z;
    }
}

void mkHBillBoardMtx(HSD_JObj* jobj, Mtx src, Mtx dst)
{
    Vec pos, ax, ax_n, ay, az, uy;
    f32 sy, sz;
    f32 mag;

    pos.x = src[0][3];
    pos.y = src[1][3];
    pos.z = src[2][3];

    ax.x = src[0][0];
    ax.y = src[1][0];
    ax.z = src[2][0];

    mag = PSVECMag(&ax);
    PSVECScale(1.0F / (HSD_FloatEpsilon[0] + mag), &ax, &ax_n);

    sy = displayfunc_col_mag(src, 1);
    sz = displayfunc_col_mag(src, 2);

    if (jobj->flags & PBILLBOARD) {
        f32 t;

        uy.y = displayfunc_sqrtf(__fmadds(pos.x, pos.x, pos.z * pos.z));
        t = -pos.y / (HSD_FloatEpsilon[0] + uy.y);
        uy.x = pos.x * t;
        uy.y = HSD_FloatEpsilon[0] + uy.y;
        uy.z = pos.z * t;
        PSVECNormalize(&uy, &uy);
    } else {
        uy.x = 0.0F;
        uy.y = 1.0F;
        uy.z = 0.0F;
    }

    PSVECCrossProduct(&ax_n, &uy, &az);
    mag = PSVECMag(&az);
    if (mag < HSD_FloatEpsilon[0]) {
        PSMTXCopy(src, dst);
    } else {
        f32 szFactor = sz / mag;
        f32 syFactor;

        PSVECCrossProduct(&az, &ax_n, &ay);
        mag = PSVECMag(&ay);
        syFactor = sy / (HSD_FloatEpsilon[0] + mag);

        dst[0][0] = ax.x;
        dst[1][0] = ax.y;
        dst[2][0] = ax.z;

        dst[0][1] = syFactor * ay.x;
        dst[1][1] = syFactor * ay.y;
        dst[2][1] = syFactor * ay.z;

        dst[0][2] = szFactor * az.x;
        dst[1][2] = szFactor * az.y;
        dst[2][2] = szFactor * az.z;

        dst[0][3] = pos.x;
        dst[1][3] = pos.y;
        dst[2][3] = pos.z;
    }
}

void mkBillBoardMtx(HSD_JObj* jobj, Mtx src, Mtx dst)
{
    Vec ax, ay, az, pos;
    f32 sx, sy, sz;
    f32 mag;

    sx = displayfunc_col_mag(src, 0);
    sz = displayfunc_col_mag(src, 2);

    ay.x = src[0][1];
    ay.y = src[1][1];
    ay.z = src[2][1];
    sy = PSVECMag(&ay);

    pos.x = src[0][3];
    pos.y = src[1][3];
    pos.z = src[2][3];

    if (jobj->flags & PBILLBOARD) {
        mag = PSVECMag(&pos);
        PSVECScale(-1.0F / (HSD_FloatEpsilon[0] + mag), &pos, &az);
    } else {
        az.x = 0.0F;
        az.y = 0.0F;
        az.z = 1.0F;
    }

    PSVECScale(1.0F / (sy + HSD_FloatEpsilon[0]), &ay, &ay);

    PSVECCrossProduct(&ay, &az, &ax);
    mag = PSVECMag(&ax);
    if (mag >= HSD_FloatEpsilon[0]) {
        f32 sxFactor = sx / mag;
        f32 syFactor;

        PSVECCrossProduct(&az, &ax, &ay);
        mag = PSVECMag(&ay);
        syFactor = sy / (HSD_FloatEpsilon[0] + mag);

        dst[0][0] = sxFactor * ax.x;
        dst[1][0] = sxFactor * ax.y;
        dst[2][0] = sxFactor * ax.z;

        dst[0][1] = syFactor * ay.x;
        dst[1][1] = syFactor * ay.y;
        dst[2][1] = syFactor * ay.z;
    } else {
        Vec ay2;
        f32 t;

        mag = displayfunc_sqrtf(az.x * az.x + az.z * az.z);
        t = -az.y / (HSD_FloatEpsilon[0] + mag);
        ay2.x = az.x * t;
        ay2.y = HSD_FloatEpsilon[0] + mag;
        ay2.z = az.z * t;

        PSVECCrossProduct(&ay2, &az, &ax);
        mag = PSVECMag(&ax);
        sx /= (HSD_FloatEpsilon[0] + mag);

        dst[0][0] = sx * ax.x;
        dst[1][0] = sx * ax.y;
        dst[2][0] = sx * ax.z;

        dst[0][1] = ay2.x;
        dst[1][1] = ay2.y;
        dst[2][1] = ay2.z;
    }

    dst[0][2] = sz * az.x;
    dst[1][2] = sz * az.y;
    dst[2][2] = sz * az.z;

    dst[0][3] = pos.x;
    dst[1][3] = pos.y;
    dst[2][3] = pos.z;
}

void mkRBillBoardMtx(HSD_JObj* jobj, Mtx src, Mtx dst)
{
    Mtx rot, scl;
    f32 sx, sy, sz;

    sx = displayfunc_col_mag(src, 0);
    sy = displayfunc_col_mag(src, 1);
    sz = displayfunc_col_mag(src, 2);

    PSMTXScale(scl, sx, sy, sz);
    kar_grcoll__near_803d1738(rot, 'z', jobj->rotate.z);

    rot[0][3] = src[0][3];
    rot[1][3] = src[1][3];
    rot[2][3] = src[2][3];

    PSMTXConcat(rot, scl, dst);
}

static inline BOOL displayfunc_jobj_mtx_is_dirty(HSD_JObj* jobj)
{
    BOOL result;

    if (jobj == NULL) {
        __assert(JObjHeaderSourceFile, 0x25D, DisplayFuncJObjString);
    }
    result = FALSE;
    if (!(jobj->flags & 0x800000) && (jobj->flags & MTX_DIRTY)) {
        result = TRUE;
    }
    return result;
}

#pragma push
#pragma dont_inline on
void HSD_JObjMakePositionMtx(HSD_JObj* jobj, Mtx vmtx, Mtx pmtx)
{
    Mtx sp8;

    if (jobj->flags & 0xE00) {
        PSMTXConcat(vmtx, jobj->mtx, sp8);
        switch (jobj->flags & 0xE00) {
        case 0x200:
            mkBillBoardMtx(jobj, sp8, pmtx);
            break;
        case 0x400:
            mkVBillBoardMtx(jobj, sp8, pmtx);
            break;
        case 0x600:
            mkHBillBoardMtx(jobj, sp8, pmtx);
            break;
        case 0x800:
            mkRBillBoardMtx(jobj, sp8, pmtx);
            break;
        default:
            HSD_Panic(DisplayFuncSourceFile, 0x16E, DisplayFuncUnknownBillboardMsg);
            break;
        }
    } else {
        PSMTXConcat(vmtx, jobj->mtx, pmtx);
    }
}
#pragma pop

static inline HSD_JObj* displayfunc_find_skeleton(HSD_JObj* jobj)
{
    if (jobj == NULL) {
        __assert(DisplayFuncSourceFile, 0x182, DisplayFuncJObjString);
    }
    for (; jobj != NULL; jobj = jobj->parent) {
        if (jobj->flags & 3) {
            return jobj;
        }
    }
    return NULL;
}

MtxPtr _HSD_mkEnvelopeModelNodeMtx(HSD_JObj* jobj, Mtx dst)
{
    HSD_JObj* x;
    Mtx sp8;

    if (jobj->flags & SKELETON_ROOT) {
        return NULL;
    }
    x = displayfunc_find_skeleton(jobj);
    if (x == NULL) {
        __assert(DisplayFuncSourceFile, 0x1D2, DisplayFuncXString);
    }

    if (x == jobj) {
        PSMTXInverse(x->envelopemtx, dst);
    } else if (x->flags & SKELETON_ROOT) {
        HSD_MtxInverseConcat(x->mtx, jobj->mtx, dst);
    } else {
        PSMTXConcat(x->mtx, x->envelopemtx, sp8);
        HSD_MtxInverseConcat(sp8, jobj->mtx, dst);
    }
    return dst;
}

void HSD_JObjDispSub(HSD_JObj* jobj, Mtx vmtx, Mtx pmtx, HSD_TrspMask trsp_mask,
                     u32 rendermode)
{
    HSD_DObj* dobj;

    HSD_JObjSetCurrent(jobj);
    trsp_mask <<= 1;
    if (!(rendermode & 0x4000000) && (jobj->flags & SPECULAR)) {
        HSD_LObjSetupSpecularInit(pmtx);
    }
    HSD_PObjClearMtxMark(NULL, 0);

    for (dobj = jobj->u.dobj; dobj != NULL; dobj = dobj->next) {
        if (!(dobj->flags & 1) && (dobj->flags & trsp_mask)) {
            HSD_DObjSetCurrent(dobj);
            HSD_DOBJ_METHOD(dobj)->disp(dobj, vmtx, pmtx, rendermode);
        }
    }

    HSD_DObjSetCurrent(NULL);
    HSD_JObjSetCurrent(NULL);
}

void HSD_JObjDispDObj(HSD_JObj* jobj, Mtx vmtx, HSD_TrspMask trsp_mask, u32 rendermode)
{
    HSD_DObj* dobj;
    u32 mask;
    Mtx pmtx;
    HSD_ZList* entry;

    if (jobj->flags & HIDDEN) {
        return;
    }

    for (dobj = jobj->u.dobj; dobj != NULL; dobj = dobj->next) {
        if (!(dobj->flags & 1)) {
            break;
        }
    }
    if (dobj == NULL) {
        return;
    }

    mask = jobj->flags & (trsp_mask << 18);
    if (mask == 0) {
        return;
    }

    if (jobj != NULL && displayfunc_jobj_mtx_is_dirty(jobj)) {
        HSD_JObjSetupMatrixSub(jobj);
    }
    if (vmtx == NULL) {
        vmtx = HSD_CObjGetCurrent()->view_mtx;
    }

    HSD_JOBJ_METHOD(jobj)->make_pmtx(jobj, vmtx, pmtx);

    if (mask & 0x40000) {
        HSD_JOBJ_METHOD(jobj)->disp(jobj, vmtx, pmtx, 1, rendermode);
    }

    if (HSD_ZSortMode == 0) {
        if (mask & 0x100000) {
            HSD_JOBJ_METHOD(jobj)->disp(jobj, vmtx, pmtx, 4, rendermode);
        }
        if (mask & 0x80000) {
            HSD_JOBJ_METHOD(jobj)->disp(jobj, vmtx, pmtx, 2, rendermode);
        }
    } else if (mask & 0x180000) {
        entry = HSD_ObjAlloc(&HSD_ZListAllocData);
        memset(&entry->vmtx, 0, 0x18);
        PSMTXCopy(pmtx, entry->pmtx);
        if (vmtx != NULL) {
            entry->vmtx = HSD_MtxAlloc();
            PSMTXCopy(vmtx, entry->vmtx);
        }
        entry->jobj = jobj;
        entry->rendermode = rendermode;
        *HSD_ZListAllTail = entry;
        HSD_ZListAllTail = &entry->next_all;
        if (mask & 0x100000) {
            *HSD_ZListOpaqueTail = entry;
            HSD_ZListOpaqueTail = &entry->next_opa;
            HSD_ZListOpaqueCount++;
        }
        if (mask & 0x80000) {
            *HSD_ZListTranslucentTail = entry;
            HSD_ZListTranslucentTail = &entry->next_xlu;
            HSD_ZListTranslucentCount[0]++;
        }
    }
}

HSD_ZList* zlist_sort(HSD_ZList* list, s32 count, s32 next_offset)
{
    HSD_ZList* left;
    HSD_ZList* right;
    HSD_ZList** tail;
    s32 left_count;
    s32 right_count;
    s32 i;

    if (count <= 1) {
        if (list != NULL) {
            HSD_ZLIST_NEXT(list, next_offset) = NULL;
        }
        return list;
    }

    left_count = count / 2;
    right_count = count - left_count;
    right = list;
    for (i = 0; i < left_count; i++) {
        right = HSD_ZLIST_NEXT(right, next_offset);
    }

    left = zlist_sort(list, left_count, next_offset);
    right = zlist_sort(right, right_count, next_offset);

    list = NULL;
    tail = &list;
    while (left != NULL && right != NULL) {
        if (HSD_ZLIST_DEPTH(left) <= HSD_ZLIST_DEPTH(right)) {
            *tail = left;
            left = HSD_ZLIST_NEXT(left, next_offset);
        } else {
            *tail = right;
            right = HSD_ZLIST_NEXT(right, next_offset);
        }
        tail = &HSD_ZLIST_NEXT(*tail, next_offset);
    }
    if (left != NULL) {
        *tail = left;
    } else if (right != NULL) {
        *tail = right;
    }
    return list;
}

void _HSD_ZListSort(void)
{
    if (HSD_ZSortCompare != 0) {
        HSD_ZListOpaque = zlist_sort(HSD_ZListOpaque, HSD_ZListOpaqueCount, 0x3C);
        HSD_ZListTranslucent =
            zlist_sort(HSD_ZListTranslucent, HSD_ZListTranslucentCount[0], 0x40);
    }
}

void _HSD_ZListDisp(void)
{
    HSD_ZList* entry;
    MtxPtr default_vmtx;
    MtxPtr vmtx;

    default_vmtx = HSD_CObjGetCurrent()->view_mtx;
    for (entry = HSD_ZListOpaque; entry != NULL; entry = entry->next_opa) {
        vmtx = entry->vmtx != NULL ? entry->vmtx : default_vmtx;
        HSD_JOBJ_METHOD(entry->jobj)->disp(entry->jobj, vmtx, entry->pmtx, 4, entry->rendermode);
    }
    for (entry = HSD_ZListTranslucent; entry != NULL; entry = entry->next_xlu) {
        vmtx = entry->vmtx != NULL ? entry->vmtx : default_vmtx;
        HSD_JOBJ_METHOD(entry->jobj)->disp(entry->jobj, vmtx, entry->pmtx, 2, entry->rendermode);
    }
    _HSD_ZListClear();
}

static inline void reset_zlist(void)
{
    HSD_ZListAll = NULL;
    HSD_ZListAllTail = &HSD_ZListAll;
    HSD_ZListOpaque = NULL;
    HSD_ZListOpaqueTail = &HSD_ZListOpaque;
    HSD_ZListOpaqueCount = 0;
    HSD_ZListTranslucent = NULL;
    HSD_ZListTranslucentTail = &HSD_ZListTranslucent;
    HSD_ZListTranslucentCount[0] = 0;
}

void _HSD_ZListClear(void)
{
    HSD_ZList* entry;
    HSD_ZList* next;

    for (entry = HSD_ZListAll; entry != NULL; entry = next) {
        next = entry->next_all;
        if (entry->vmtx != NULL) {
            HSD_MtxFree(entry->vmtx);
        }
        HSD_ObjFree(&HSD_ZListAllocData, entry);
    }
    reset_zlist();
}

void HSD_SetZSortMode(s32 mode, s32 sort)
{
    HSD_ZSortMode = mode;
    HSD_ZSortCompare = sort;
}

void HSD_JObjDisp(HSD_JObj* jobj, Mtx vmtx, HSD_TrspMask trsp_mask, u32 rendermode)
{
    if (jobj != NULL && union_type_dobj(jobj)) {
        HSD_JObjDispDObj(jobj, vmtx, trsp_mask, rendermode);
    }
}

void HSD_JObjSetSPtclCallback(u8 arg0, u8 arg1, u8 arg2, u8 arg3)
{
    JObjSPtclColor[0] = arg0;
    JObjSPtclColor[1] = arg1;
    JObjSPtclColor[2] = arg2;
    JObjSPtclColor[3] = arg3;
}

u32 HSD_JObjGetSPtclColor(void)
{
    return *(u32*) JObjSPtclColor;
}

static inline void write_quad_vertex(f32 x, f32 y, f32 z, u8* color, u8 s, u8 t)
{
    GX_FIFO_F32 = x;
    GX_FIFO_F32 = y;
    GX_FIFO_F32 = z;
    GX_FIFO_U8 = color[0];
    GX_FIFO_U8 = color[1];
    GX_FIFO_U8 = color[2];
    GX_FIFO_U8 = color[3];
    GX_FIFO_U8 = s;
    GX_FIFO_U8 = t;
}

void kar_displayfunc_draw_viewport_scale_quad(s32 color_update, f32 top, f32 bottom,
                                              s32 alpha_update, f32 left, s32 tex_enable,
                                              f32 right, f32 z)
{
    GXTexObj texobj;
    u32 color;

    if (color_update == 0 && alpha_update == 0 && tex_enable == 0) {
        return;
    }

    if (tex_enable != 0) {
        GXInitTexObj(&texobj, DisplayFuncWhiteTexImage, 4, 4, 0x11, 1, 1, 0);
        GXLoadTexObj(&texobj, 0);
        GXSetNumTexGens(1);
        GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
        GXSetNumTevStages(1);
        GXSetTevOrder(0, 0, 0, 4);
        GXSetTevOp(0, 4);
        GXSetZTexture(2, 0x11, 0);
    } else {
        GXSetNumTexGens(0);
        GXSetNumTevStages(1);
        GXSetTevOrder(0, 0xFF, 0xFF, 4);
        GXSetTevOp(0, 4);
    }

    GXSetCullMode(0);
    GXSetAlphaCompare(7, 0, 1, 7, 0);
    GXSetZCompLoc(1);
    GXSetZMode(1, 7, tex_enable != 0);
    GXSetBlendMode(2, 1, 0, 3);
    GXSetColorUpdate(color_update != 0);
    GXSetAlphaUpdate(alpha_update != 0);
    GXSetNumChans(1);
    GXSetChanCtrl(4, 0, 0, 1, 0, 0, 2);
    GXClearVtxDesc();
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
    GXSetVtxAttrFmt(0, 0xB, 1, 5, 0);
    GXSetVtxAttrFmt(0, 0xD, 1, 0, 0);
    GXLoadPosMtxImm(HSD_IdentityMtx, 0);
    GXSetCurrentMtx(0);
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xB, 1);
    GXSetVtxDesc(0xD, 1);

    color = *(u32*) JObjSPtclColor;
    GXBegin(0x80, 0, 4);
    write_quad_vertex(left, top, z, (u8*) &color, 0, 0);
    write_quad_vertex(right, top, z, (u8*) &color, 1, 0);
    write_quad_vertex(right, bottom, z, (u8*) &color, 1, 1);
    write_quad_vertex(left, bottom, z, (u8*) &color, 0, 1);

    GXSetZTexture(0, 0x11, 0);
    HSD_StateInvalidate(-1);
}

void _HSD_DispForgetMemory(void)
{
    reset_zlist();
}
