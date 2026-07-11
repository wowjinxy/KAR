#include <global.h>
#include <dolphin/gx/gx.h>
#include <dolphin/mtx/mtx.h>
#include <dolphin/mtx/vec.h>
#include <sysdolphin/tobj.h>

#include <sysdolphin/aobj.h>
#include <sysdolphin/cobj.h>
#include <sysdolphin/initialize.h>
#include <sysdolphin/memory.h>
#include <sysdolphin/mtx.h>

extern f32 TObjFloatZero; /* 0.0F */
extern f32 TObjFloatOne; /* 1.0F */
extern f32 TObjFloat255; /* 255.0F */
extern f32 TObjFloatEpsilon; /* ~1e-10F */
extern f32 TObjFloatHalf; /* 0.5F */
extern f32 TObjFloatNegHalf; /* -0.5F */
extern f32 TObjFloatNegOne; /* -1.0F */
extern f64 TObjDoubleNegHalf; /* -0.5 (double) */

#define ClampUnit(v) \
    ((v) <= TObjFloatZero ? TObjFloatZero : ((v) >= TObjFloatOne ? TObjFloatOne : (v)))

#define GX_MTX3x4 0
#define GX_MTX2x4 1

#define GX_TG_MTX3x4 0
#define GX_TG_MTX2x4 1
#define GX_TG_BUMP0 2
#define GX_TG_BUMP1 3
#define GX_TG_BUMP2 4
#define GX_TG_BUMP3 5
#define GX_TG_BUMP4 6
#define GX_TG_BUMP5 7
#define GX_TG_BUMP6 8
#define GX_TG_BUMP7 9
#define GX_TG_SRTG 10

#define GX_TG_POS 0
#define GX_TG_NRM 1
#define GX_TG_TEX0 4
#define GX_TG_TEXCOORD0 12

#define GX_TEXCOORD0 0

#define GX_LEQUAL 3

#define GX_PNMTX0 0

#define GX_CLAMP 0
#define GX_REPEAT 1
#define GX_MIRROR 2

#define LOBJ_INFINITE (1 << 0)

#define GX_TEXCOORD_NULL 0xff
#define GX_COLOR_NULL 0xff
#define GX_COLOR0A0 4

#define GX_CC_CPREV 0
#define GX_CC_ZERO 15
#define GX_CC_ONE 12
#define GX_CC_HALF 13
#define GX_CC_TEXC 8
#define GX_CC_TEXA 9
#define GX_CC_RASC 10

#define GX_CA_ZERO 7
#define GX_CA_APREV 0
#define GX_CA_TEXA 4

#define GX_TEV_ADD 0
#define GX_TEV_SUB 1
#define GX_TB_ZERO 0
#define GX_CS_SCALE_1 0
#define GX_TEVPREV 0

#define TEVCONF_MODE 0

#define GX_TF_I4 0x0
#define GX_TF_I8 0x1
#define GX_TF_IA4 0x2
#define GX_TF_IA8 0x3
#define GX_TF_RGB565 0x4
#define GX_TF_RGB5A3 0x5
#define GX_TF_RGBA8 0x6
#define GX_TF_C4 0x8
#define GX_TF_C8 0x9
#define GX_TF_C14X2 0xA
#define GX_TF_CMPR 0xE

#define GX_LIN_MIP_NEAR 3
#define GX_LIN_MIP_LIN 5

#define GX_TLUT0 0
#define GX_BIGTLUT0 0x10
#define GX_ANISO_1 0

typedef struct _GXTlutObj {
    u32 unused[3];
} GXTlutObj;

typedef struct _GXTexObj {
    u8 pad[0x20];
} GXTexObj;

char kar_srcfile_tobj_c[] = "tobj.c";
char TObjAssertTObj[] = "tobj";
char TObjAssertCObj[] = "cobj";
char TObjAssertZero[] = "0";
char TObjAssertTlut[] = "tlut";
char TObjAssertEmpty[] = "";
char TObjAssertNew[] = "new";
char TObjAssertTev[] = "tev";
char TObjAssertIDesc[] = "idesc";

#define TOBJ_ASSERT(line, cond, str) \
    ((cond) ? ((void) 0) : __assert(kar_srcfile_tobj_c, line, str))

extern void* hsdNew(HSD_ClassInfo* info);
extern void HSD_Panic(char* file, s32 line, char* msg);

extern void* hsdAllocMemPiece(u32 size);
extern void memcpy(void* dst, const void* src, u32 size);
extern void memset(void* ptr, s32 value, u32 size);

extern HSD_LObj* HSD_LObjGetCurrentByType(u16 flags);
extern void HSD_LObjGetLightVector(HSD_LObj* lobj, Vec* v);
extern u32 HSD_LObjGetLightMaskDiffuse(void);

extern MtxPtr HSD_CObjGetInvViewingMtxPtrDirect(HSD_CObj* cobj);

extern void kar_grcoll__803d1978(Mtx m, f32 x, f32 y, f32 z); /* PSMTXTrans */

extern void GXSetTexCoordGen2(u32 dst_coord, u32 func, u32 src_param, u32 mtx,
                              u32 normalize, u32 postmtx);

extern u32 HSD_StateAssignTev(void);
extern void HSD_SetupTevStage(HSD_TevDesc* tevdesc);
extern void HSD_StateAssignTexGen(u32 coord);

extern HSD_TExp* HSD_TExpTev(HSD_TExp** list);
extern HSD_TExp* HSD_TExpCnst(void* val, u32 comp, u32 ctype, HSD_TExp** list);
extern void HSD_TExpOrder(HSD_TExp* texp, HSD_TObj* tobj, u32 channel);
extern void HSD_TExpColorOp(HSD_TExp* texp, u32 op, u32 bias, u32 scale,
                            u32 clamp);
extern void HSD_TExpColorIn(HSD_TExp* texp, u32 sel_a, HSD_TExp* exp_a,
                            u32 sel_b, HSD_TExp* exp_b, u32 sel_c,
                            HSD_TExp* exp_c, u32 sel_d, HSD_TExp* exp_d);
extern void HSD_TExpAlphaOp(HSD_TExp* texp, u32 op, u32 bias, u32 scale,
                            u32 clamp);
extern void HSD_TExpAlphaIn(HSD_TExp* texp, u32 sel_a, HSD_TExp* exp_a,
                            u32 sel_b, HSD_TExp* exp_b, u32 sel_c,
                            HSD_TExp* exp_c, u32 sel_d, HSD_TExp* exp_d);

extern void GXInitTlutObj(void* tlutobj, void* lut, u32 fmt, u16 n_entries);
extern void GXLoadTlut(void* tlutobj, u32 tlut_name);
extern void GXInitTexObjCI(void* texobj, void* image_ptr, u16 width,
                           u16 height, u32 format, u32 wrap_s, u32 wrap_t,
                           u32 mipmap, u32 tlut_name);
extern void GXInitTexObj(void* texobj, void* image_ptr, u16 width, u16 height,
                         u32 format, u32 wrap_s, u32 wrap_t, u32 mipmap);
extern void fn_803CDA90(void* texobj, u32 min_filter, u32 mag_filter,
                        f32 minLOD, f32 maxLOD, f32 lodbias, u32 bias_clamp,
                        u32 edgeLODEnable, u32 max_anisotropy); /* GXInitTexObjLOD */
extern void GXLoadTexObj(void* texobj, u32 mapid);

extern void GXSetTexCopySrc(u16 orig_x, u16 orig_y, u16 width, u16 height);
extern void GXSetTexCopyDst(u16 width, u16 height, u32 format, u32 mipmap);
extern void GXCopyTex(void* dest, u8 clear);
extern void HSD_StateSetZMode(u32 enable, u32 func, u32 update_enable);

void TObjInfoInit(void);

HSD_TObjInfoBlock hsdTObj = {
    { TObjInfoInit },
    {
        GX_TEXCOORD0,     GX_TEXCOORD0 + 1, GX_TEXCOORD0 + 2, GX_TEXCOORD0 + 3,
        GX_TEXCOORD0 + 4, GX_TEXCOORD0 + 5, GX_TEXCOORD0 + 6, GX_TEXCOORD0 + 7,
    },
    {
        GX_TEXMAP0, GX_TEXMAP1, GX_TEXMAP2, GX_TEXMAP3,
        GX_TEXMAP4, GX_TEXMAP5, GX_TEXMAP6, GX_TEXMAP7,
    },
};

static HSD_TObjInfo* TObjDefaultClass = NULL;

HSD_TObj* TObjCurrent;

static inline void TObjRemoveAnim(HSD_TObj* tobj)
{
    if (tobj == NULL) {
        return;
    }
    HSD_AObjRemove(tobj->aobj);
    tobj->aobj = NULL;
}

void HSD_TObjRemoveAnimAll(HSD_TObj* tobj)
{
    HSD_TObj* tp;

    if (tobj != NULL) {
        for (tp = tobj; tp != NULL; tp = tp->next) {
            TObjRemoveAnim(tp);
        }
    }
}

static inline HSD_TexAnim* lookupTextureAnim(s32 id, HSD_TexAnim* texanim)
{
    HSD_TexAnim* ta;
    for (ta = texanim; ta; ta = ta->next) {
        if (ta->id == (GXTexMapID) id) {
            return ta;
        }
    }
    return NULL;
}

static inline void TObjAddAnim(HSD_TObj* tobj, HSD_TexAnim* texanim)
{
    s32 i;
    HSD_TexAnim* ta;

    if (tobj != NULL) {
        if ((ta = lookupTextureAnim(tobj->id, texanim)) != NULL) {
            if (tobj->aobj != NULL) {
                HSD_AObjRemove(tobj->aobj);
            }
            tobj->aobj = HSD_AObjLoadDesc(ta->aobjdesc);
            tobj->imagetbl = ta->imagetbl;

            if (tobj->tluttbl != NULL) {
                for (i = 0; tobj->tluttbl[i]; i++) {
                    HSD_TlutRemove(tobj->tluttbl[i]);
                }
                HSD_Free(tobj->tluttbl);
            }

            if (ta->n_tluttbl) {
                tobj->tluttbl = (HSD_Tlut**) HSD_Alloc(
                    (s32) sizeof(HSD_Tlut*) * (ta->n_tluttbl + 1));
                for (i = 0; i < ta->n_tluttbl; i++) {
                    tobj->tluttbl[i] = HSD_TlutLoadDesc(ta->tluttbl[i]);
                }
                tobj->tluttbl[i] = NULL;
            } else {
                tobj->tluttbl = NULL;
            }
            tobj->tlut_no = (u8) -1;
        }
    }
}

void HSD_TObjAddAnimAll(HSD_TObj* tobj, HSD_TexAnim* texanim)
{
    HSD_TObj* tp;

    if (tobj != NULL) {
        for (tp = tobj; tp; tp = tp->next) {
            TObjAddAnim(tp, texanim);
        }
    }
}

static inline void TObjReqAnimByFlags(HSD_TObj* tobj, f32 startframe,
                                      u32 flags)
{
    if (tobj == NULL) {
        return;
    }
    if (flags & TOBJ_ANIM) {
        HSD_AObjReqAnim(tobj->aobj, startframe);
    }
}

void HSD_TObjReqAnimAllByFlags(HSD_TObj* tobj, f32 startframe, u32 flags)
{
    HSD_TObj* tp;

    if (tobj != NULL) {
        for (tp = tobj; tp != NULL; tp = tp->next) {
            TObjReqAnimByFlags(tp, startframe, flags);
        }
    }
}

void TObjUpdateFunc(void* obj, enum_t type, HSD_ObjData* val)
{
    HSD_TObj* tobj = obj;

    if (tobj == NULL) {
        return;
    }

    switch (type) {
    case HSD_A_T_TIMG: {
        int n;
        TOBJ_ASSERT(0x155, tobj->imagetbl, "tobj->imagetbl");
        n = (int) val->fv;
        if (tobj->imagetbl[n]) {
            tobj->imagedesc = tobj->imagetbl[n];
        }
    } break;
    case HSD_A_T_TCLT: {
        if (tobj->tluttbl) {
            tobj->tlut_no = (u8) val->fv;
        }
    } break;
    case HSD_A_T_BLEND:
        tobj->blending = ClampUnit(val->fv);
        break;
    case HSD_A_T_ROTX:
        tobj->rotate.x = val->fv;
        goto mtxdirty;
    case HSD_A_T_ROTY:
        tobj->rotate.y = val->fv;
        goto mtxdirty;
    case HSD_A_T_ROTZ:
        tobj->rotate.z = val->fv;
        goto mtxdirty;
    case HSD_A_T_TRAU:
        tobj->translate.x = val->fv;
        goto mtxdirty;
    case HSD_A_T_TRAV:
        tobj->translate.y = val->fv;
        goto mtxdirty;
    case HSD_A_T_SCAU:
        tobj->scale.x = val->fv;
        goto mtxdirty;
    case HSD_A_T_SCAV:
        tobj->scale.y = val->fv;
        goto mtxdirty;
    mtxdirty:
        tobj->flags |= TEX_MTX_DIRTY;
        break;
    case HSD_A_T_LOD_BIAS:
        if (tobj->lod) {
            tobj->lod->LODBias = val->fv;
        }
        break;
    case HSD_A_T_KONST_R:
        if (tobj->tev) {
            tobj->tev->konst.r = (u8) (TObjFloat255 * ClampUnit(val->fv));
        }
        break;
    case HSD_A_T_KONST_G:
        if (tobj->tev) {
            tobj->tev->konst.g = (u8) (TObjFloat255 * ClampUnit(val->fv));
        }
        break;
    case HSD_A_T_KONST_B:
        if (tobj->tev) {
            tobj->tev->konst.b = (u8) (TObjFloat255 * ClampUnit(val->fv));
        }
        break;
    case HSD_A_T_KONST_A:
        if (tobj->tev) {
            tobj->tev->konst.a = (u8) (TObjFloat255 * ClampUnit(val->fv));
        }
        break;
    case HSD_A_T_TEV0_R:
        if (tobj->tev) {
            tobj->tev->tev0.r = (u8) (TObjFloat255 * ClampUnit(val->fv));
        }
        break;
    case HSD_A_T_TEV0_G:
        if (tobj->tev) {
            tobj->tev->tev0.g = (u8) (TObjFloat255 * ClampUnit(val->fv));
        }
        break;
    case HSD_A_T_TEV0_B:
        if (tobj->tev) {
            tobj->tev->tev0.b = (u8) (TObjFloat255 * ClampUnit(val->fv));
        }
        break;
    case HSD_A_T_TEV0_A:
        if (tobj->tev) {
            tobj->tev->tev0.a = (u8) (TObjFloat255 * ClampUnit(val->fv));
        }
        break;
    case HSD_A_T_TEV1_R:
        if (tobj->tev) {
            tobj->tev->tev1.r = (u8) (TObjFloat255 * ClampUnit(val->fv));
        }
        break;
    case HSD_A_T_TEV1_G:
        if (tobj->tev) {
            tobj->tev->tev1.g = (u8) (TObjFloat255 * ClampUnit(val->fv));
        }
        break;
    case HSD_A_T_TEV1_B:
        if (tobj->tev) {
            tobj->tev->tev1.b = (u8) (TObjFloat255 * ClampUnit(val->fv));
        }
        break;
    case HSD_A_T_TEV1_A:
        if (tobj->tev) {
            tobj->tev->tev1.a = (u8) (TObjFloat255 * ClampUnit(val->fv));
        }
        break;
    case HSD_A_T_TS_BLEND:
        tobj->blending = ClampUnit(val->fv);
        break;
    }
}

void HSD_TObjInterpretAnim(HSD_TObj* tobj)
{
    if (tobj == NULL) {
        return;
    }

    HSD_AObjInterpretAnim(tobj->aobj, tobj, HSD_TOBJ_METHOD(tobj)->update);
}

void HSD_TObjAnimAll(HSD_TObj* tobj)
{
    HSD_TObj* i;

    if (tobj == NULL) {
        return;
    }

    for (i = tobj; i != NULL; i = i->next) {
        HSD_TObjInterpretAnim(i);
    }
}

int TObjLoad(HSD_TObj* tobj, HSD_TObjDesc* td)
{
    tobj->next = HSD_TObjLoadDesc(td->next);
    tobj->id = (u16) td->id;
    tobj->src = td->src;
    tobj->mtxid = GX_IDENTITY;
    tobj->rotate.x = td->rotate.x;
    tobj->rotate.y = td->rotate.y;
    tobj->rotate.z = td->rotate.z;
    tobj->scale = td->scale;
    tobj->translate = td->translate;
    tobj->wrap_s = td->wrap_s;
    tobj->wrap_t = td->wrap_t;
    tobj->repeat_s = td->repeat_s;
    tobj->repeat_t = td->repeat_t;
    tobj->flags = td->blend_flags;
    tobj->blending = td->blending;
    tobj->magFilt = td->magFilt;
    tobj->imagedesc = td->imagedesc;
    tobj->tlut = HSD_TlutLoadDesc(td->tlutdesc);
    tobj->lod = td->lod;
    tobj->aobj = NULL;
    tobj->flags |= TEX_MTX_DIRTY;
    tobj->tlut_no = (u8) -1;
    tobj->tev = HSD_TObjTevLoadDesc(td->tev);

    _HSD_NeedCacheInvalidate(2);

    return 0;
}

HSD_TObj* HSD_TObjLoadDesc(HSD_TObjDesc* td)
{
    if (td != NULL) {
        HSD_TObj* tobj;
        HSD_ClassInfo* info;

        if (!td->class_name || !(info = hsdSearchClassInfo(td->class_name))) {
            tobj = HSD_TObjAlloc();
        } else {
            tobj = hsdNew(info);
            TOBJ_ASSERT(0x22C, tobj, TObjAssertTObj);
        }
        HSD_TOBJ_METHOD(tobj)->load(tobj, td);
        return tobj;
    } else {
        return NULL;
    }
}

HSD_Tlut* HSD_TlutLoadDesc(HSD_TlutDesc* tlutdesc)
{
    if (tlutdesc != NULL) {
        HSD_Tlut* tlut = HSD_TlutAlloc();
        memcpy(tlut, tlutdesc, sizeof(HSD_Tlut));
        return tlut;
    }
    return NULL;
}

HSD_TObjTev* HSD_TObjTevLoadDesc(HSD_TObjTevDesc* tevdesc)
{
    if (tevdesc != NULL) {
        HSD_TObjTev* new = HSD_TObjTevAlloc();
        memcpy(new, tevdesc, sizeof(HSD_TObjTev));
        return new;
    }
    return NULL;
}

HSD_TObj* _HSD_TObjGetCurrentByType(HSD_TObj* from, u32 mapping)
{
    HSD_TObj* tp;

    if (from == NULL) {
        tp = TObjCurrent;
    } else {
        tp = from->next;
    }

    for (; tp != NULL; tp = tp->next) {
        if (tobj_coord(tp) == mapping) {
            return tp;
        }
    }

    return NULL;
}

u32 HSD_TexMapID2PTTexMtx(u32 id)
{
    switch (id) {
    case GX_TEXMAP0:
        return GX_PTTEXMTX0;
    case GX_TEXMAP1:
        return GX_PTTEXMTX1;
    case GX_TEXMAP2:
        return GX_PTTEXMTX2;
    case GX_TEXMAP3:
        return GX_PTTEXMTX3;
    case GX_TEXMAP4:
        return GX_PTTEXMTX4;
    case GX_TEXMAP5:
        return GX_PTTEXMTX5;
    case GX_TEXMAP6:
        return GX_PTTEXMTX6;
    case GX_TEXMAP7:
        return GX_PTTEXMTX7;
    default:
        HSD_Panic(kar_srcfile_tobj_c, 0x297, "unexpected texmap id.\n");
    }
    return 0;
}

void MakeTextureMtx(HSD_TObj* tobj)
{
    Vec scale;
    Mtx m;
    Vec trans;
    Quaternion rot;

    TOBJ_ASSERT(0x2A6, tobj->repeat_s && tobj->repeat_t,
               "tobj->repeat_s && tobj->repeat_t");

    scale.x = __fabsf(tobj->scale.x) < TObjFloatEpsilon
                  ? TObjFloatZero
                  : (f32) tobj->repeat_s / tobj->scale.x;
    scale.y = __fabsf(tobj->scale.y) < TObjFloatEpsilon
                  ? TObjFloatZero
                  : (f32) tobj->repeat_t / tobj->scale.y;
    scale.z = tobj->scale.z;
    rot.x = tobj->rotate.x;
    rot.y = tobj->rotate.y;
    rot.z = -tobj->rotate.z;
    trans.x = -tobj->translate.x;
    trans.y =
        -(tobj->translate.y + (tobj->wrap_t == GX_MIRROR
                                   ? TObjFloatOne / ((f32) tobj->repeat_t / tobj->scale.y)
                                   : TObjFloatZero));
    trans.z = tobj->translate.z;

    kar_grcoll__803d1978(tobj->mtx, trans.x, trans.y, trans.z);
    HSD_MkRotationMtx(m, (Vec*) &rot);
    PSMTXConcat(m, tobj->mtx, tobj->mtx);
    PSMTXScale(m, scale.x, scale.y, scale.z);
    PSMTXConcat(m, tobj->mtx, tobj->mtx);
}

void TObjSetupMtx(HSD_TObj* tobj)
{
    int i;

    if (tobj_coord(tobj) == TEX_COORD_TOON) {
        return;
    }

    if (tobj->flags & TEX_MTX_DIRTY) {
        HSD_TOBJ_METHOD(tobj)->make_mtx(tobj);
        tobj->flags &= ~TEX_MTX_DIRTY;
    }

    switch (tobj_coord(tobj)) {
    case TEX_COORD_REFLECTION: {
        Mtx mtx;

        for (i = 0; i < 3; i++) {
            mtx[i][0] = TObjFloatHalf * tobj->mtx[i][0];
            mtx[i][1] = TObjFloatNegHalf * tobj->mtx[i][1];
            mtx[i][2] = TObjFloatZero;
            mtx[i][3] = TObjFloatHalf * tobj->mtx[i][0] +
                        TObjFloatHalf * tobj->mtx[i][1] + tobj->mtx[i][2] +
                        tobj->mtx[i][3];
        }
        GXLoadTexMtxImm(mtx, tobj->mtxid, GX_MTX3x4);
    } break;

    case TEX_COORD_HILIGHT: {
        HSD_LObj* lobj;

        if ((lobj = HSD_LObjGetCurrentByType(LOBJ_INFINITE)) != NULL) {
            HSD_CObj* cobj;
            Vec ldir, half;
            Mtx mtx;

            cobj = HSD_CObjGetCurrent();
            TOBJ_ASSERT(0x301, cobj, TObjAssertCObj);
            HSD_LObjGetLightVector(lobj, &ldir);
            PSMTXMultVecSR(cobj->view_mtx, &ldir, &ldir);
            ldir.z += TObjFloatNegOne;

            PSVECNormalize(&ldir, &half);

            half.x *= TObjDoubleNegHalf;
            half.y *= TObjDoubleNegHalf;
            half.z *= TObjDoubleNegHalf;

            mtx[0][0] = tobj->mtx[0][0] * half.x;
            mtx[0][1] = tobj->mtx[0][0] * half.y;
            mtx[0][2] = tobj->mtx[0][0] * half.z;
            mtx[0][3] = tobj->mtx[0][0] * TObjFloatHalf + tobj->mtx[0][3];
            mtx[1][0] = tobj->mtx[1][0] * half.x;
            mtx[1][1] = tobj->mtx[1][0] * half.y;
            mtx[1][2] = tobj->mtx[1][0] * half.z;
            mtx[1][3] = tobj->mtx[1][0] * TObjFloatHalf + tobj->mtx[1][3];
            mtx[2][0] = mtx[2][1] = mtx[2][2] = TObjFloatZero;
            mtx[2][3] = TObjFloatOne;

            GXLoadTexMtxImm(mtx, tobj->mtxid, GX_MTX3x4);
        } else {
            static Mtx zero = { 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F,
                                0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F };
            GXLoadTexMtxImm(zero, tobj->mtxid, GX_MTX3x4);
        }
    } break;

    case TEX_COORD_SHADOW: {
        HSD_CObj* cobj = HSD_CObjGetCurrent();
        Mtx mtx;

        PSMTXConcat(tobj->mtx, HSD_CObjGetInvViewingMtxPtrDirect(cobj), mtx);
        GXLoadTexMtxImm(mtx, tobj->mtxid, GX_MTX3x4);
    } break;

    default:
        if (tobj_bump(tobj)) {
            GXLoadTexMtxImm(tobj->mtx, tobj->mtxid, GX_MTX2x4);
        } else {
            GXLoadTexMtxImm(tobj->mtx, tobj->mtxid, GX_MTX3x4);
        }
        break;
    }
}

static inline void setupTextureCoordGen(HSD_TObj* tobj)
{
    switch (tobj_coord(tobj)) {
    case TEX_COORD_SHADOW:
        GXSetTexCoordGen2(tobj->coord, GX_TG_MTX3x4, GX_TG_POS, GX_PNMTX0,
                          GX_DISABLE, tobj->mtxid);
        break;
    case TEX_COORD_REFLECTION:
    case TEX_COORD_HILIGHT:
        GXSetTexCoordGen2(tobj->coord, GX_TG_MTX3x4, GX_TG_NRM, GX_TEXMTX0,
                          GX_ENABLE, tobj->mtxid);
        break;
    default:
        if (tobj_bump(tobj)) {
            GXSetTexCoordGen2(tobj->coord, GX_TG_MTX2x4, tobj->src,
                              tobj->mtxid, GX_DISABLE, GX_PTIDENTITY);
        } else {
            GXSetTexCoordGen2(tobj->coord, GX_TG_MTX2x4, tobj->src,
                              GX_IDENTITY, GX_DISABLE, tobj->mtxid);
        }
    }
}

static inline void setupTextureCoordGenBump(HSD_TObj* bump)
{
    u32 mask;
    int i;
    static u32 func[] = {
        GX_TG_BUMP0, GX_TG_BUMP1, GX_TG_BUMP2, GX_TG_BUMP3,
        GX_TG_BUMP4, GX_TG_BUMP5, GX_TG_BUMP6, GX_TG_BUMP7,
    };

    mask = HSD_LObjGetLightMaskDiffuse();

    for (i = 0; i < 8; i++) {
        if (mask & (1 << i)) {
            break;
        }
    }
    if (i >= 8) {
        i = 0;
    }

    GXSetTexCoordGen2((u32) (bump->coord + 1), func[i],
                      HSD_TexCoordID2TexGenSrc(bump->coord), GX_IDENTITY,
                      GX_DISABLE, GX_PTIDENTITY);
}

static inline void setupTextureCoordGenToon(HSD_TObj* toon)
{
    GXSetTexCoordGen2(toon->coord, GX_TG_SRTG, toon->src, GX_IDENTITY,
                      GX_DISABLE, GX_PTIDENTITY);
}

void HSD_TObjSetupTextureCoordGen(HSD_TObj* tobj)
{
    for (; tobj != NULL; tobj = tobj->next) {
        if (tobj->map_id == GX_TEXMAP_NULL) {
            continue;
        }
        if (tobj_bump(tobj)) {
            setupTextureCoordGen(tobj);
            setupTextureCoordGenBump(tobj);
        } else if (tobj_coord(tobj) == TEX_COORD_TOON) {
            setupTextureCoordGenToon(tobj);
        } else {
            setupTextureCoordGen(tobj);
        }
    }
}

static HSD_TevDesc lbl_80501FDC = {
    NULL,           TEVCONF_MODE,  (u32) (-1),    GX_TEXCOORD_NULL,
    GX_TEXMAP_NULL, GX_COLOR_NULL, GX_TEV_ADD,    GX_CC_ZERO,
    GX_CC_CPREV,    GX_CC_TEXC,    GX_CC_ZERO,    GX_CS_SCALE_1,
    GX_TB_ZERO,     GX_ENABLE,     GX_TEVPREV,    GX_TEV_ADD,
    GX_CA_ZERO,     GX_CA_ZERO,    GX_CA_ZERO,    GX_CA_APREV,
    GX_CS_SCALE_1,  GX_TB_ZERO,    GX_ENABLE,     GX_TEVPREV,
};

static inline void TObjSetupTevModulateShadow(HSD_TObj* shadow)
{
    for (; shadow && tobj_coord(shadow) == TEX_COORD_SHADOW;
         shadow = shadow->next)
    {
        lbl_80501FDC.stage = HSD_StateAssignTev();
        lbl_80501FDC.coord = shadow->coord;
        lbl_80501FDC.map = shadow->map_id;
        HSD_SetupTevStage(&lbl_80501FDC);
    }
}

static HSD_TevDesc lbl_80502050 = {
    NULL,           TEVCONF_MODE, (u32) (-1),    GX_TEXCOORD_NULL,
    GX_TEXMAP_NULL, GX_COLOR0A0,  GX_TEV_SUB,    GX_CC_ZERO,
    GX_CC_TEXC,     GX_CC_RASC,   GX_CC_CPREV,   GX_CS_SCALE_1,
    GX_TB_ZERO,     GX_ENABLE,    GX_TEVPREV,    GX_TEV_SUB,
    GX_CA_ZERO,     GX_CA_ZERO,   GX_CA_ZERO,    GX_CA_APREV,
    GX_CS_SCALE_1,  GX_TB_ZERO,   GX_ENABLE,     GX_TEVPREV,
};

static inline void SetupEmbossBumpTev(HSD_TObj* bump)
{
    lbl_80502050.stage = HSD_StateAssignTev();
    lbl_80502050.coord = bump->coord;
    lbl_80502050.map = bump->map_id;
    lbl_80502050.u.tevconf.clr_op = GX_TEV_ADD;
    lbl_80502050.u.tevconf.alpha_op = GX_TEV_ADD;
    lbl_80502050.u.tevconf.clr_clamp = GX_DISABLE;
    HSD_SetupTevStage(&lbl_80502050);
    lbl_80502050.stage = HSD_StateAssignTev();
    lbl_80502050.coord = (u32) (bump->coord + 1);
    lbl_80502050.u.tevconf.clr_op = GX_TEV_SUB;
    lbl_80502050.u.tevconf.alpha_op = GX_TEV_SUB;
    lbl_80502050.u.tevconf.clr_clamp = GX_ENABLE;
    HSD_SetupTevStage(&lbl_80502050);
}

void HSD_TObjSetupVolatileTev(HSD_TObj* tobj, u32 rendermode)
{
    for (; tobj; tobj = tobj->next) {
        if (tobj->map_id == GX_TEXMAP_NULL) {
            continue;
        }

        if (tobj_bump(tobj)) {
            SetupEmbossBumpTev(tobj);
        }

        if (tobj_lightmap(tobj) & TEX_LIGHTMAP_SHADOW) {
            TObjSetupTevModulateShadow(tobj);
            break;
        }
    }
}

void MakeColorGenTExp(u32 lightmap, HSD_TObj* tobj, HSD_TExp** c, HSD_TExp** a,
                     HSD_TExp** list, int repeat)
{
    HSD_TObjTev* tev = tobj->tev;
    u8* in;
    HSD_TExp *e0, *tmp;
    int i;

    HSD_TExp* konst_rgb;
    HSD_TExp* konst_r;
    HSD_TExp* konst_g;
    HSD_TExp* konst_b;
    HSD_TExp* konst_a;
    HSD_TExp* reg0_rgb;
    HSD_TExp* reg0_a;
    HSD_TExp* reg1_rgb;
    HSD_TExp* reg1_a;

    int use_k_rgb = 0;
    int use_k_r = 0;
    int use_k_g = 0;
    int use_k_b = 0;
    int use_k_a = 0;
    int use_reg0_rgb = 0;
    int use_reg0_a = 0;
    int use_reg1_rgb = 0;
    int use_reg1_a = 0;

    in = &tev->color_a;
    for (i = 0; i < 4; i++) {
        switch (in[i]) {
        case TOBJ_TEV_CC_KONST_RGB:
            use_k_rgb = 1;
            break;
        case TOBJ_TEV_CC_KONST_RRR:
            use_k_r = 1;
            break;
        case TOBJ_TEV_CC_KONST_GGG:
            use_k_g = 1;
            break;
        case TOBJ_TEV_CC_KONST_BBB:
            use_k_b = 1;
            break;
        case TOBJ_TEV_CC_KONST_AAA:
            use_k_a = 1;
            break;
        case TOBJ_TEV_CC_TEX0_RGB:
            use_reg0_rgb = 1;
            break;
        case TOBJ_TEV_CC_TEX0_AAA:
            use_reg0_a = 1;
            break;
        case TOBJ_TEV_CC_TEX1_RGB:
            use_reg1_rgb = 1;
            break;
        case TOBJ_TEV_CC_TEX1_AAA:
            use_reg1_a = 1;
            break;
        default:
            break;
        }
    }
    in = &tev->alpha_a;
    for (i = 0; i < 4; i++) {
        switch (in[i]) {
        case TOBJ_TEV_CA_KONST_R:
            use_k_r = 1;
            break;
        case TOBJ_TEV_CA_KONST_G:
            use_k_g = 1;
            break;
        case TOBJ_TEV_CA_KONST_B:
            use_k_b = 1;
            break;
        case TOBJ_TEV_CA_KONST_A:
            use_k_a = 1;
            break;
        case TOBJ_TEV_CA_TEX0_A:
            use_reg0_a = 1;
            break;
        case TOBJ_TEV_CA_TEX1_A:
            use_reg1_a = 1;
            break;
        default:
            break;
        }
    }

    if (use_k_rgb) {
        konst_rgb = HSD_TExpCnst(&tobj->tev->konst, HSD_TE_RGB, HSD_TE_U8, list);
    }
    if (use_k_r) {
        konst_r = HSD_TExpCnst(&tobj->tev->konst.r, HSD_TE_X, HSD_TE_U8, list);
    }
    if (use_k_g) {
        konst_g = HSD_TExpCnst(&tobj->tev->konst.g, HSD_TE_X, HSD_TE_U8, list);
    }
    if (use_k_b) {
        konst_b = HSD_TExpCnst(&tobj->tev->konst.b, HSD_TE_X, HSD_TE_U8, list);
    }
    if (use_k_a) {
        konst_a = HSD_TExpCnst(&tobj->tev->konst.a, HSD_TE_X, HSD_TE_U8, list);
    }
    if (use_reg0_rgb) {
        reg0_rgb = HSD_TExpCnst(&tobj->tev->tev0, HSD_TE_RGB, HSD_TE_U8, list);
    }
    if (use_reg0_a) {
        reg0_a = HSD_TExpCnst(&tobj->tev->tev0.a, HSD_TE_X, HSD_TE_U8, list);
    }
    if (use_reg1_rgb) {
        reg1_rgb = HSD_TExpCnst(&tobj->tev->tev1, HSD_TE_RGB, HSD_TE_U8, list);
    }
    if (use_reg1_a) {
        reg1_a = HSD_TExpCnst(&tobj->tev->tev1.a, HSD_TE_X, HSD_TE_U8, list);
    }

    e0 = HSD_TExpTev(list);
    HSD_TExpOrder(e0, tobj, GX_COLOR_NULL);

    if (tev->active & TOBJ_TEVREG_ACTIVE_COLOR_TEV) {
        HSD_TEInput sel[4];
        HSD_TExp* exp[4];
        int i;

        in = &tev->color_a;
        for (i = 0; i < 4; i++) {
            switch (in[i]) {
            case GX_CC_ZERO:
                sel[i] = HSD_TE_0;
                exp[i] = HSD_TEXP_ZERO;
                break;
            case GX_CC_ONE:
                sel[i] = HSD_TE_1;
                exp[i] = HSD_TEXP_ZERO;
                break;
            case GX_CC_HALF:
                sel[i] = HSD_TE_4_8;
                exp[i] = HSD_TEXP_ZERO;
                break;
            case GX_CC_TEXC:
                sel[i] = HSD_TE_RGB;
                exp[i] = HSD_TEXP_TEX;
                break;
            case GX_CC_TEXA:
                sel[i] = HSD_TE_A;
                exp[i] = HSD_TEXP_TEX;
                break;
            case TOBJ_TEV_CC_KONST_RGB:
                sel[i] = HSD_TE_RGB;
                exp[i] = konst_rgb;
                break;
            case TOBJ_TEV_CC_KONST_RRR:
                sel[i] = HSD_TE_X;
                exp[i] = konst_r;
                break;
            case TOBJ_TEV_CC_KONST_GGG:
                sel[i] = HSD_TE_X;
                exp[i] = konst_g;
                break;
            case TOBJ_TEV_CC_KONST_BBB:
                sel[i] = HSD_TE_X;
                exp[i] = konst_b;
                break;
            case TOBJ_TEV_CC_KONST_AAA:
                sel[i] = HSD_TE_X;
                exp[i] = konst_a;
                break;
            case TOBJ_TEV_CC_TEX0_RGB:
                tmp = HSD_TExpTev(list);
                HSD_TExpOrder(tmp, NULL, GX_COLOR_NULL);
                HSD_TExpColorOp(tmp, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                                GX_ENABLE);
                HSD_TExpColorIn(tmp, HSD_TE_0, HSD_TEXP_ZERO, HSD_TE_0,
                                HSD_TEXP_ZERO, HSD_TE_0, HSD_TEXP_ZERO,
                                HSD_TE_RGB, reg0_rgb);
                sel[i] = HSD_TE_RGB;
                exp[i] = tmp;
                break;
            case TOBJ_TEV_CC_TEX0_AAA:
                tmp = HSD_TExpTev(list);
                HSD_TExpOrder(tmp, NULL, GX_COLOR_NULL);
                HSD_TExpColorOp(tmp, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                                GX_ENABLE);
                HSD_TExpColorIn(tmp, HSD_TE_0, HSD_TEXP_ZERO, HSD_TE_0,
                                HSD_TEXP_ZERO, HSD_TE_0, HSD_TEXP_ZERO,
                                HSD_TE_X, reg0_a);
                sel[i] = HSD_TE_RGB;
                exp[i] = tmp;
                break;
            case TOBJ_TEV_CC_TEX1_RGB:
                tmp = HSD_TExpTev(list);
                HSD_TExpOrder(tmp, NULL, GX_COLOR_NULL);
                HSD_TExpColorOp(tmp, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                                GX_ENABLE);
                HSD_TExpColorIn(tmp, HSD_TE_0, HSD_TEXP_ZERO, HSD_TE_0,
                                HSD_TEXP_ZERO, HSD_TE_0, HSD_TEXP_ZERO,
                                HSD_TE_RGB, reg1_rgb);
                sel[i] = HSD_TE_RGB;
                exp[i] = tmp;
                break;
            case TOBJ_TEV_CC_TEX1_AAA:
                tmp = HSD_TExpTev(list);
                HSD_TExpOrder(tmp, NULL, GX_COLOR_NULL);
                HSD_TExpColorOp(tmp, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                                GX_ENABLE);
                HSD_TExpColorIn(tmp, HSD_TE_0, HSD_TEXP_ZERO, HSD_TE_0,
                                HSD_TEXP_ZERO, HSD_TE_0, HSD_TEXP_ZERO,
                                HSD_TE_X, reg1_a);
                sel[i] = HSD_TE_RGB;
                exp[i] = tmp;
                break;
            default:
                TOBJ_ASSERT(0x500, 0, TObjAssertZero);
                break;
            }
        }

        HSD_TExpColorOp(e0, tev->color_op, tev->color_bias, tev->color_scale,
                        tev->color_clamp);
        HSD_TExpColorIn(e0, sel[0], exp[0], sel[1], exp[1], sel[2], exp[2],
                        sel[3], exp[3]);
        *c = e0;
    }

    if (tev->active & TOBJ_TEVREG_ACTIVE_ALPHA_TEV) {
        HSD_TEInput sel[4];
        HSD_TExp* exp[4];
        int i;

        in = &tev->alpha_a;
        for (i = 0; i < 4; i++) {
            switch (in[i]) {
            case GX_CA_ZERO:
                sel[i] = HSD_TE_0;
                exp[i] = HSD_TEXP_ZERO;
                break;
            case GX_CA_TEXA:
                sel[i] = HSD_TE_A;
                exp[i] = HSD_TEXP_TEX;
                break;
            case TOBJ_TEV_CA_KONST_R:
                sel[i] = HSD_TE_X;
                exp[i] = konst_r;
                break;
            case TOBJ_TEV_CA_KONST_G:
                sel[i] = HSD_TE_X;
                exp[i] = konst_g;
                break;
            case TOBJ_TEV_CA_KONST_B:
                sel[i] = HSD_TE_X;
                exp[i] = konst_b;
                break;
            case TOBJ_TEV_CA_KONST_A:
                sel[i] = HSD_TE_X;
                exp[i] = konst_a;
                break;
            case TOBJ_TEV_CA_TEX0_A:
                tmp = HSD_TExpTev(list);
                HSD_TExpOrder(tmp, NULL, GX_COLOR_NULL);
                HSD_TExpAlphaOp(tmp, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                                GX_ENABLE);
                HSD_TExpAlphaIn(tmp, HSD_TE_0, HSD_TEXP_ZERO, HSD_TE_0,
                                HSD_TEXP_ZERO, HSD_TE_0, HSD_TEXP_ZERO,
                                HSD_TE_X, reg0_a);
                sel[i] = HSD_TE_A;
                exp[i] = tmp;
                break;
            case TOBJ_TEV_CA_TEX1_A:
                tmp = HSD_TExpTev(list);
                HSD_TExpOrder(tmp, NULL, GX_COLOR_NULL);
                HSD_TExpAlphaOp(tmp, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                                GX_ENABLE);
                HSD_TExpAlphaIn(tmp, HSD_TE_0, HSD_TEXP_ZERO, HSD_TE_0,
                                HSD_TEXP_ZERO, HSD_TE_0, HSD_TEXP_ZERO,
                                HSD_TE_X, reg1_a);
                sel[i] = HSD_TE_A;
                exp[i] = tmp;
                break;
            default:
                TOBJ_ASSERT(0x549, 0, TObjAssertZero);
                break;
            }
        }

        HSD_TExpAlphaOp(e0, tev->alpha_op, tev->alpha_bias, tev->alpha_scale,
                        tev->alpha_clamp);
        HSD_TExpAlphaIn(e0, sel[0], exp[0], sel[1], exp[1], sel[2], exp[2],
                        sel[3], exp[3]);

        *a = e0;
    }
}

void TObjMakeTExp(HSD_TObj* tobj, u32 lightmap, u32 lightmap_done,
                 HSD_TExp** c, HSD_TExp** a, HSD_TExp** list)
{
    HSD_TExp *e0, *e1;
    HSD_TExp *c_src, *a_src;
    HSD_TEInput c_sel, a_sel;
    int repeat = (lightmap_done & tobj_lightmap(tobj)) != 0;

    c_src = HSD_TEXP_TEX;
    c_sel = HSD_TE_RGB;

    a_src = HSD_TEXP_TEX;
    a_sel = HSD_TE_A;

    e0 = HSD_TExpTev(list);

    if (tobj->tev && (tobj->tev->active & (TOBJ_TEVREG_ACTIVE_COLOR_TEV |
                                           TOBJ_TEVREG_ACTIVE_ALPHA_TEV)))
    {
        MakeColorGenTExp(lightmap, tobj, &c_src, &a_src, list, repeat);
    }

    HSD_TExpOrder(e0, tobj, GX_COLOR_NULL);

    switch (tobj_colormap(tobj)) {
    case TEX_COLORMAP_ALPHA_MASK:
        HSD_TExpColorOp(e0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_ENABLE);
        HSD_TExpColorIn(e0, HSD_TE_RGB, *c, c_sel, c_src, a_sel, a_src,
                        HSD_TE_0, HSD_TEXP_ZERO);
        break;
    case TEX_COLORMAP_RGB_MASK:
        HSD_TExpColorOp(e0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_ENABLE);
        HSD_TExpColorIn(e0, HSD_TE_RGB, *c, c_sel, c_src, c_sel, c_src,
                        HSD_TE_0, HSD_TEXP_ZERO);
        break;
    case TEX_COLORMAP_BLEND:
        e1 = HSD_TExpCnst(&tobj->blending, HSD_TE_X, HSD_TE_F32, list);
        HSD_TExpColorOp(e0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_ENABLE);
        HSD_TExpColorIn(e0, HSD_TE_RGB, *c, c_sel, c_src, HSD_TE_X, e1,
                        HSD_TE_0, HSD_TEXP_ZERO);
        break;
    case TEX_COLORMAP_MODULATE:
        HSD_TExpColorOp(e0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_ENABLE);
        HSD_TExpColorIn(e0, HSD_TE_0, HSD_TEXP_ZERO, HSD_TE_RGB, *c, c_sel,
                        c_src, HSD_TE_0, HSD_TEXP_ZERO);
        break;
    case TEX_COLORMAP_REPLACE:
        HSD_TExpColorOp(e0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_ENABLE);
        HSD_TExpColorIn(e0, HSD_TE_0, HSD_TEXP_ZERO, HSD_TE_0, HSD_TEXP_ZERO,
                        HSD_TE_0, HSD_TEXP_ZERO, c_sel, c_src);
        break;
    case TEX_COLORMAP_NONE:
    case TEX_COLORMAP_PASS:
        HSD_TExpColorOp(e0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_ENABLE);
        HSD_TExpColorIn(e0, HSD_TE_0, HSD_TEXP_ZERO, HSD_TE_0, HSD_TEXP_ZERO,
                        HSD_TE_0, HSD_TEXP_ZERO, HSD_TE_RGB, *c);
        break;
    case TEX_COLORMAP_ADD:
        HSD_TExpColorOp(e0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_ENABLE);
        HSD_TExpColorIn(e0, c_sel, c_src, HSD_TE_0, HSD_TEXP_ZERO, HSD_TE_0,
                        HSD_TEXP_ZERO, HSD_TE_RGB, *c);
        break;
    case TEX_COLORMAP_SUB:
        HSD_TExpColorOp(e0, GX_TEV_SUB, GX_TB_ZERO, GX_CS_SCALE_1, GX_ENABLE);
        HSD_TExpColorIn(e0, c_sel, c_src, HSD_TE_0, HSD_TEXP_ZERO, HSD_TE_0,
                        HSD_TEXP_ZERO, HSD_TE_RGB, *c);
        break;
    default:
        TOBJ_ASSERT(0x5B5, 0, TObjAssertZero);
    }
    *c = e0;

    if (!repeat) {
        switch (tobj_alphamap(tobj)) {
        case TEX_ALPHAMAP_ALPHA_MASK:
            HSD_TExpAlphaOp(e0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                            GX_ENABLE);
            HSD_TExpAlphaIn(e0, HSD_TE_A, *a, a_sel, a_src, a_sel, a_src,
                            HSD_TE_0, HSD_TEXP_ZERO);
            break;
        case TEX_ALPHAMAP_BLEND:
            e1 = HSD_TExpCnst(&tobj->blending, HSD_TE_X, HSD_TE_F32, list);
            HSD_TExpAlphaOp(e0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                            GX_ENABLE);
            HSD_TExpAlphaIn(e0, HSD_TE_A, *a, a_sel, a_src, HSD_TE_X, e1,
                            HSD_TE_0, HSD_TEXP_ZERO);
            break;
        case TEX_ALPHAMAP_MODULATE:
            HSD_TExpAlphaOp(e0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                            GX_ENABLE);
            HSD_TExpAlphaIn(e0, HSD_TE_0, HSD_TEXP_ZERO, HSD_TE_A, *a, a_sel,
                            a_src, HSD_TE_0, HSD_TEXP_ZERO);
            break;
        case TEX_ALPHAMAP_REPLACE:
            HSD_TExpAlphaOp(e0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                            GX_ENABLE);
            HSD_TExpAlphaIn(e0, HSD_TE_0, HSD_TEXP_ZERO, HSD_TE_0,
                            HSD_TEXP_ZERO, HSD_TE_0, HSD_TEXP_ZERO, a_sel,
                            a_src);
            break;
        case TEX_ALPHAMAP_NONE:
        case TEX_ALPHAMAP_PASS:
            HSD_TExpAlphaOp(e0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                            GX_ENABLE);
            HSD_TExpAlphaIn(e0, HSD_TE_0, HSD_TEXP_ZERO, HSD_TE_0,
                            HSD_TEXP_ZERO, HSD_TE_0, HSD_TEXP_ZERO, HSD_TE_A,
                            *a);
            break;
        case TEX_ALPHAMAP_ADD:
            HSD_TExpAlphaOp(e0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                            GX_ENABLE);
            HSD_TExpAlphaIn(e0, a_sel, a_src, HSD_TE_0, HSD_TEXP_ZERO,
                            HSD_TE_0, HSD_TEXP_ZERO, HSD_TE_A, *a);
            break;
        case TEX_ALPHAMAP_SUB:
            HSD_TExpAlphaOp(e0, GX_TEV_SUB, GX_TB_ZERO, GX_CS_SCALE_1,
                            GX_ENABLE);
            HSD_TExpAlphaIn(e0, a_sel, a_src, HSD_TE_0, HSD_TEXP_ZERO,
                            HSD_TE_0, HSD_TEXP_ZERO, HSD_TE_A, *a);
            break;
        default:
            TOBJ_ASSERT(0x5EF, 0, TObjAssertZero);
        }
        *a = e0;
    }
}

s32 HSD_TObjAssignResources(HSD_TObj* tobj_top)
{
    HSD_TObj* tobj;
    u32 texmap_no = 0;
    u32 texcoord_no = 0;
    u32 limit = 8;
    HSD_TObj* bump = NULL;
    HSD_TObj* toon = NULL;
    HSD_TObjInfoBlock* info = &hsdTObj;

    if (tobj_top == NULL) {
        return 0;
    }

    for (tobj = tobj_top; tobj; tobj = tobj->next) {
        if (tobj_coord(tobj) == TEX_COORD_TOON) {
            toon = tobj;
        } else if (tobj_bump(tobj)) {
            bump = tobj;
        }
    }

    if (toon) {
        limit -= 1;
    }
    if (bump) {
        limit -= 2;
    }

    for (tobj = tobj_top; tobj; tobj = tobj->next) {
        if (tobj_coord(tobj) == TEX_COORD_TOON) {
            if (tobj != toon) {
                tobj->map_id = GX_TEXMAP_NULL;
            }
        } else if (tobj_bump(tobj)) {
            if (tobj != bump) {
                tobj->map_id = GX_TEXMAP_NULL;
            }
        } else if (texmap_no < limit) {
            tobj->map_id = info->texmap_tbl[texmap_no++];
            tobj->mtxid = HSD_TexMapID2PTTexMtx(tobj->map_id);
            switch (tobj_coord(tobj)) {
            case TEX_COORD_REFLECTION:
            case TEX_COORD_HILIGHT:
            case TEX_COORD_SHADOW:
                tobj->coord = info->texcoord_tbl[texcoord_no++];
                break;
            default:
                break;
            }
        } else {
            tobj->map_id = GX_TEXMAP_NULL;
        }
    }

    for (tobj = tobj_top; tobj; tobj = tobj->next) {
        if (tobj->map_id != GX_TEXMAP_NULL && !tobj_bump(tobj)) {
            switch (tobj_coord(tobj)) {
            case TEX_COORD_UV:
                tobj->coord = info->texcoord_tbl[texcoord_no++];
                break;
            default:
                break;
            }
        }
    }

    if (bump) {
        bump->map_id = info->texmap_tbl[texmap_no++];
        bump->mtxid = GX_TEXMTX9;
        bump->coord = info->texcoord_tbl[texcoord_no];
        texcoord_no += 2;
    }
    if (toon) {
        toon->map_id = info->texmap_tbl[texmap_no++];
        toon->coord = info->texcoord_tbl[texcoord_no++];
    }

    return (int) texcoord_no;
}

static inline int DifferentTluts(HSD_Tlut* t0, HSD_Tlut* t1)
{
    return (t0->lut != t0->lut) || (t0->n_entries != t1->n_entries);
}

void HSD_TObjSetup(HSD_TObj* tobj)
{
    GXTlutObj tlutobj;
    GXTexObj texobj;
    int num;
    HSD_Tlut* tluts[8];
    int nb_tluts = 0;
    u32 tlut_name = GX_TLUT0;
    u32 big_tlut_name = GX_BIGTLUT0;
    int i;

    TObjCurrent = tobj;

    if (tobj == NULL) {
        return;
    }

    num = HSD_TObjAssignResources(tobj);
    if (num > 0) {
        int lastcoord = num - 1;
        HSD_StateAssignTexGen(hsdTObj.texcoord_tbl[lastcoord]);
    }

    for (; tobj; tobj = tobj->next) {
        static HSD_TexLODDesc default_lod = {
            GX_LIN_MIP_LIN, 0.0F, GX_FALSE, GX_FALSE, GX_ANISO_1,
        };
        HSD_TexLODDesc* lod;
        HSD_ImageDesc* imagedesc = tobj->imagedesc;
        s32 min_filter;

        if (tobj->map_id == GX_TEXMAP_NULL) {
            continue;
        }

        TObjSetupMtx(tobj);
        TOBJ_ASSERT(0x683, imagedesc, "imagedesc");
        TOBJ_ASSERT(0x684, imagedesc->img_ptr, "imagedesc->image_ptr");

        lod = tobj->lod != NULL ? tobj->lod : &default_lod;
        min_filter = lod->minFilt;

        switch (imagedesc->format) {
        case GX_TF_C4:
        case GX_TF_C8:
        case GX_TF_C14X2: {
            HSD_Tlut* tlut;

            if (tobj->tlut_no != (u8) -1) {
                tlut = tobj->tluttbl[tobj->tlut_no];
            } else {
                tlut = tobj->tlut;
            }

            TOBJ_ASSERT(0x694, tlut, TObjAssertTlut);

            for (i = 0; i < nb_tluts; i++) {
                if (!DifferentTluts(tluts[i], tlut)) {
                    break;
                }
            }
            if (i < nb_tluts) {
                tlut->tlut_name = tluts[i]->tlut_name;
            } else if (nb_tluts < 8) {
                if (tlut->n_entries >= 256) {
                    tlut->tlut_name = big_tlut_name++;
                } else {
                    tlut->tlut_name = tlut_name++;
                }
                GXInitTlutObj(&tlutobj, tlut->lut, tlut->fmt, tlut->n_entries);
                GXLoadTlut(&tlutobj, tlut->tlut_name);
                tluts[nb_tluts++] = tlut;
            } else {
                tlut->tlut_name = GX_TLUT0;
            }

            GXInitTexObjCI(&texobj, imagedesc->img_ptr, imagedesc->width,
                           imagedesc->height, imagedesc->format, tobj->wrap_s,
                           tobj->wrap_t,
                           imagedesc->mipmap ? GX_TRUE : GX_FALSE,
                           tlut->tlut_name);
            if (min_filter == GX_LIN_MIP_LIN) {
                min_filter = GX_LIN_MIP_NEAR;
            }
        } break;

        case GX_TF_I4:
        case GX_TF_I8:
        case GX_TF_IA4:
        case GX_TF_IA8:
        case GX_TF_RGB565:
        case GX_TF_RGB5A3:
        case GX_TF_RGBA8:
        case GX_TF_CMPR:
            GXInitTexObj(&texobj, imagedesc->img_ptr, imagedesc->width,
                        imagedesc->height, imagedesc->format, tobj->wrap_s,
                        tobj->wrap_t, imagedesc->mipmap ? GX_TRUE : GX_FALSE);
            break;

        default:
            TOBJ_ASSERT(0x6D0, 0, TObjAssertZero);
        }

        if (!imagedesc->mipmap) {
            min_filter &= 0x01;
        }
        fn_803CDA90(&texobj, min_filter, tobj->magFilt, imagedesc->minLOD,
                   imagedesc->maxLOD, lod->LODBias, lod->bias_clamp,
                   lod->edgeLODEnable, lod->max_anisotropy);

        GXLoadTexObj(&texobj, tobj->map_id);
    }
}

u32 HSD_TGTex2Index(u32 tgtex)
{
    switch (tgtex) {
    case GX_TG_TEX0:
        return 0;
    case GX_TG_TEX0 + 1:
        return 1;
    case GX_TG_TEX0 + 2:
        return 2;
    case GX_TG_TEX0 + 3:
        return 3;
    case GX_TG_TEX0 + 4:
        return 4;
    case GX_TG_TEX0 + 5:
        return 5;
    case GX_TG_TEX0 + 6:
        return 6;
    case GX_TG_TEX0 + 7:
        return 7;
    default:
        TOBJ_ASSERT(0x6FE, 0, TObjAssertZero);
    }
    return GX_TG_TEX0;
}

u32 HSD_TexCoordID2TexGenSrc(u32 coord)
{
    switch (coord) {
    case GX_TEXCOORD0:
        return GX_TG_TEXCOORD0;
    case GX_TEXCOORD0 + 1:
        return GX_TG_TEXCOORD0 + 1;
    case GX_TEXCOORD0 + 2:
        return GX_TG_TEXCOORD0 + 2;
    case GX_TEXCOORD0 + 3:
        return GX_TG_TEXCOORD0 + 3;
    case GX_TEXCOORD0 + 4:
        return GX_TG_TEXCOORD0 + 4;
    case GX_TEXCOORD0 + 5:
        return GX_TG_TEXCOORD0 + 5;
    case GX_TEXCOORD0 + 6:
        return GX_TG_TEXCOORD0 + 6;
    case GX_TEXCOORD0 + 7:
    default:
        TOBJ_ASSERT(0x723, 0, TObjAssertZero);
    }
    return GX_TG_TEXCOORD0;
}

u32 HSD_TexCoord2Index(u32 coord_id)
{
    switch (coord_id) {
    case GX_TEXCOORD0:
        return 0;
    case GX_TEXCOORD0 + 1:
        return 1;
    case GX_TEXCOORD0 + 2:
        return 2;
    case GX_TEXCOORD0 + 3:
        return 3;
    case GX_TEXCOORD0 + 4:
        return 4;
    case GX_TEXCOORD0 + 5:
        return 5;
    case GX_TEXCOORD0 + 6:
        return 6;
    case GX_TEXCOORD0 + 7:
        return 7;
    default:
        TOBJ_ASSERT(0x749, 0, TObjAssertZero);
    }
    return GX_TEXCOORD0;
}

u32 HSD_TexMtx2Index(u32 texmtx)
{
    switch (texmtx) {
    case GX_TEXMTX0:
        return 0;
    case GX_TEXMTX1:
        return 1;
    case GX_TEXMTX2:
        return 2;
    case GX_TEXMTX3:
        return 3;
    case GX_TEXMTX4:
        return 4;
    case GX_TEXMTX5:
        return 5;
    case GX_TEXMTX6:
        return 6;
    case GX_TEXMTX7:
        return 7;
    case GX_TEXMTX8:
        return 8;
    case GX_TEXMTX9:
        return 9;
    case GX_IDENTITY:
        return 10;
    default:
        HSD_Panic(kar_srcfile_tobj_c, 0x790,
                 "specified texmtx id desn't exist.\n");
    }
    return (u32) -1;
}

u32 HSD_Index2TexMtx(u32 index)
{
    switch (index) {
    case 0:
        return GX_TEXMTX0;
    case 1:
        return GX_TEXMTX1;
    case 2:
        return GX_TEXMTX2;
    case 3:
        return GX_TEXMTX3;
    case 4:
        return GX_TEXMTX4;
    case 5:
        return GX_TEXMTX5;
    case 6:
        return GX_TEXMTX6;
    case 7:
        return GX_TEXMTX7;
    case 8:
        return GX_TEXMTX8;
    case 9:
        return GX_TEXMTX9;
    case 10:
        return GX_IDENTITY;
    default:
        OSReport("texmtx index exceed hardware limit (%d).\n", index);
        HSD_Panic(kar_srcfile_tobj_c, 0x7b0, TObjAssertEmpty);
    }
    return GX_IDENTITY;
}

u32 HSD_Index2TexMap(u32 index)
{
    switch (index) {
    case 0:
        return GX_TEXMAP0;
    case 1:
        return GX_TEXMAP1;
    case 2:
        return GX_TEXMAP2;
    case 3:
        return GX_TEXMAP3;
    case 4:
        return GX_TEXMAP4;
    case 5:
        return GX_TEXMAP5;
    case 6:
        return GX_TEXMAP6;
    case 7:
        return GX_TEXMAP7;
    default:
        TOBJ_ASSERT(0x7F0, 0, TObjAssertZero);
    }
    return GX_TEXMAP0;
}

static inline void TObjRemove(HSD_TObj* tobj)
{
    if (tobj == NULL) {
        return;
    }
    HSD_CLASS_METHOD(tobj)->release((HSD_Class*) tobj);
    HSD_CLASS_METHOD(tobj)->destroy((HSD_Class*) tobj);
}

void HSD_TObjRemoveAll(HSD_TObj* tobj)
{
    while (tobj) {
        HSD_TObj* next = tobj->next;
        TObjRemove(tobj);
        tobj = next;
    }
}

HSD_TObj* HSD_TObjGetNext(HSD_TObj* tobj)
{
    if (tobj == NULL) {
        return NULL;
    }

    return tobj->next;
}

void HSD_TObjInsertNext(HSD_TObj* tobj, HSD_TObj* next)
{
    if (tobj == NULL) {
        return;
    }
    if (next != NULL) {
        next->next = tobj->next;
        tobj->next = next;
    }
}

HSD_TObj* HSD_TObjAlloc(void)
{
    HSD_TObj* new = hsdNew((HSD_ClassInfo*) (TObjDefaultClass ? TObjDefaultClass
                                                            : &hsdTObj.info));
    TOBJ_ASSERT(0x855, new, TObjAssertNew);
    return new;
}

void HSD_TObjRemove(HSD_TObj* tobj)
{
    if (tobj) {
        HSD_CLASS_METHOD(tobj)->destroy((HSD_Class*) tobj);
    }
}

HSD_Tlut* HSD_TlutAlloc(void)
{
    HSD_Tlut* tlut = hsdAllocMemPiece(sizeof(HSD_Tlut));
    TOBJ_ASSERT(0x872, tlut, TObjAssertTlut);
    memset(tlut, 0, sizeof(HSD_Tlut));
    return tlut;
}

void HSD_TlutRemove(HSD_Tlut* tlut)
{
    if (tlut) {
        hsdFreeMemPiece(tlut, sizeof(HSD_Tlut));
    }
}

HSD_TObjTev* HSD_TObjTevAlloc(void)
{
    HSD_TObjTev* tev = hsdAllocMemPiece(sizeof(HSD_TObjTev));
    TOBJ_ASSERT(0x89D, tev, TObjAssertTev);
    memset(tev, 0, sizeof(HSD_TObjTev));
    return tev;
}

HSD_ImageDesc* HSD_ImageDescAlloc(void)
{
    HSD_ImageDesc* idesc = hsdAllocMemPiece(sizeof(HSD_ImageDesc));
    TOBJ_ASSERT(0x8C8, idesc, TObjAssertIDesc);
    memset(idesc, 0, sizeof(HSD_ImageDesc));
    return idesc;
}

void HSD_ImageDescRemove(HSD_ImageDesc* idesc)
{
    hsdFreeMemPiece(idesc, sizeof(HSD_ImageDesc));
}

void HSD_ImageDescCopyFromEFB(HSD_ImageDesc* idesc, u16 origx, u16 origy,
                              u8 clear, s32 sync)
{
    if (!idesc) {
        return;
    }

    GXSetTexCopySrc(origx, origy, idesc->width, idesc->height);
    GXSetTexCopyDst(idesc->width, idesc->height, idesc->format,
                   idesc->mipmap ? GX_TRUE : GX_FALSE);
    if (clear) {
        HSD_StateSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    }
    GXCopyTex(idesc->img_ptr, clear);
    if (sync) {
        GXPixModeSync();
        GXInvalidateTexAll();
    }
}

int TObjInit(HSD_Class* o)
{
    int result = HSD_PARENT_INFO(&hsdTObj.info)->init(o);
    if (result >= 0) {
        result = 0;
        ((HSD_TObj*) o)->id = (u16) -1;
    }
    return result;
}

void TObjRelease(HSD_Class* o)
{
    HSD_TObj* tobj = HSD_TOBJ(o);

    HSD_AObjRemove(tobj->aobj);
    if (tobj->tlut) {
        hsdFreeMemPiece(tobj->tlut, sizeof(HSD_Tlut));
    }
    if (tobj->tev) {
        hsdFreeMemPiece(tobj->tev, sizeof(HSD_TObjTev));
    }
    if (tobj->tluttbl) {
        int i;
        for (i = 0; tobj->tluttbl[i]; i++) {
            HSD_TlutRemove(tobj->tluttbl[i]);
        }
        HSD_Free(tobj->tluttbl);
    }

    HSD_PARENT_INFO(&hsdTObj.info)->release(o);
}

void TObjAmnesia(HSD_ClassInfo* info)
{
    if (info == HSD_CLASS_INFO(TObjDefaultClass)) {
        TObjDefaultClass = NULL;
    }
    if (info == HSD_CLASS_INFO(&hsdTObj)) {
        TObjCurrent = NULL;
    }
    HSD_PARENT_INFO(&hsdTObj.info)->amnesia(info);
}

#pragma push
#pragma force_active on
static char unused_hsdIsDescendantOf[] = "hsdIsDescendantOf(info, &hsdTObj)";
#pragma pop

void TObjInfoInit(void)
{
    hsdInitClassInfo(HSD_CLASS_INFO(&hsdTObj), &hsdObj,
                     "sysdolphin_base_library", "hsd_tobj",
                     sizeof(HSD_TObjInfo), sizeof(HSD_TObj));

    HSD_CLASS_INFO(&hsdTObj)->init = TObjInit;
    HSD_CLASS_INFO(&hsdTObj)->release = TObjRelease;
    HSD_CLASS_INFO(&hsdTObj)->amnesia = TObjAmnesia;
    HSD_TOBJ_INFO(&hsdTObj)->load = TObjLoad;
    HSD_TOBJ_INFO(&hsdTObj)->make_texp = TObjMakeTExp;

    hsdTObj.info.make_mtx = MakeTextureMtx;

    HSD_TOBJ_INFO(&hsdTObj)->update = TObjUpdateFunc;
}
