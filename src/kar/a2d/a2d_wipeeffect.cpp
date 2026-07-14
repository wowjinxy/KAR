#include <dolphin/types.h>
#include <dolphin/gx/gxtypes.h>

extern "C" {
#include <global.h>
}

#define GX_TEX_S            0
#define GX_TEX_ST           1
#define GX_RGB565           0
#define GX_RGBA6            4
#define GX_RGBA8            5
#define GX_DIRECT           1
#define GX_QUADS            0x80
#define GX_VTXFMT0          0
#define GX_TEVSTAGE0        0
#define GX_TEXCOORD0        0
#define GX_TEXCOORD_NULL    0xff
#define GX_COLOR0A0         4
#define GX_COLOR_NULL       0xff
#define GX_SRC_REG          0
#define GX_SRC_VTX          1
#define GX_DF_NONE          0
#define GX_AF_NONE          2
#define GX_LIGHT_NULL       0
#define GX_CC_C0            2
#define GX_CC_TEXC          8
#define GX_CC_RASC          10
#define GX_CC_ONE           12
#define GX_CC_ZERO          15
#define GX_CA_A0            1
#define GX_CA_RASA          5
#define GX_CA_ONE           6
#define GX_CA_ZERO          7
#define GX_TEVREG0          1
#define GX_PASSCLR          4
#define GX_ALWAYS           7
#define GX_AOP_OR           1
#define GX_BM_BLEND         1
#define GX_BM_LOGIC         2
#define GX_BL_ZERO          0
#define GX_BL_ONE           1
#define GX_BL_SRCCLR        2
#define GX_BL_SRCALPHA      4
#define GX_BL_INVSRCALPHA   5
#define GX_BL_DSTCLR        GX_BL_SRCCLR
#define GX_LO_CLEAR         0
#define GX_LO_COPY          3
#define GX_CULL_NONE        0
#define GX_CULL_BACK        2
#define GX_PNMTX0           0
#define GX_CLAMP            0
#define GX_REPEAT           1
#define GX_TF_Z8            0x11
#define GX_TG_TEX0          4
#define GX_TG_MTX2x4        1

typedef struct _GXTexObj {
    u32 dummy[8];
} GXTexObj;

class RefObj {
public:
    virtual void Release(s32);
};

class DiagObj : public RefObj {
public:
    virtual void v04();
    virtual void Init();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual DiagObj *GetNext();
};

struct HSD_JObj {
    s32 pad0[5];
    u32 flags; //0x14
    s32 pad18;
    f32 rotate[4]; //0x1C
    f32 scale[3];  //0x2C
    f32 translate[3]; //0x38
    s32 mtx[12]; //0x44
};

extern "C" {

void HSD_JObjRemoveAnimAll(void);
void HSD_JObjReqAnimAll(void *jobj, f32 frame);
void HSD_JObjAnimAll(void *jobj);
void HSD_JObjDispAll(void *jobj, void *pmtx, s32 which, u32 rendermode);
void HSD_JObjSetMtxDirtySub(HSD_JObj *jobj);

BOOL HSD_CObjSetCurrent(void *cobj);
void HSD_CObjEndCurrent(void);
void *HSD_CObjGetCurrent(void);
f32 HSD_CObjGetFar(void *cobj);
f32 HSD_CObjGetNear(void *cobj);
s32 HSD_CObjGetProjectionType(void *cobj);
BOOL HSD_CObjGetEyeVector(s32 cobj, f32 *out);
BOOL HSD_CObjGetUpVector(s32 cobj, f32 *out);

void HSD_LObjDeleteCurrentAll(s32);
void HSD_LObjSetupInit(void);
void HSD_LObjAddCurrent(void *lobjdesc);

void *HSD_CObjLoadDesc(void *);
void *HSD_LObjLoadDesc(void *);
void *HSD_JObjLoadJoint(void *joint);
void HSD_JObjSetFlagsAll(void *jobj, u32 flags);

void HSD_ImageDescCopyFromEFB(void *img, s32, s32, s32, s32);
void HSD_StateInvalidate(s32);

void GXInvalidateVtxCache(void);
void GXInvalidateTexAll(void);
void GXClearVtxDesc(void);
void GXSetVtxAttrFmt(u32, u32, u32, u32, u32);
void GXSetVtxDesc(u32, u32);
void GXSetCurrentMtx(u32);
void GXLoadPosMtxImm(void *, u32);
void GXSetTevOrder(u32, u32, u32, u32);
void GXSetTevColorIn(u32, u32, u32, u32, u32);
void GXSetTevAlphaIn(u32, u32, u32, u32, u32);
void GXSetTevOp(u32, u32);
void GXSetTevColor(u32, void *);
void GXSetNumChans(u32);
void GXSetChanCtrl(u32, u32, u32, u32, u32, u32, u32);
void GXSetNumTexGens(u32);
void GXSetNumTevStages(u32);
void GXSetBlendMode(u32, u32, u32, u32);
void GXSetZMode(u32, u32, u32);
void GXBegin(u32, u32, u16);
void GXSetCullMode(u32);
void GXSetAlphaCompare(u32, u8, u32, u32, u8);
void GXSetZCompLoc(u32);
void GXSetColorUpdate(u32);
void GXSetAlphaUpdate(u32);
void GXSetTexCoordGen2(u32, u32, u32, u32, u32, u32);
void GXSetZTexture(u32, u32, u32);
void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
void GXLoadTexObj(void *, u32);
u16 fn_803CDC24(void *, s32);
u16 fn_803CDC34(void *);
void fn_803CEC68(u32, u32, u32, u32, u32, u32);
void fn_803CECD0(u32, u32, u32, u32, u32, u32);

void PSVECNormalize(f32 *, f32 *);
void PSVECAdd(void *, void *, void *);
void kar_lbvector_dirs_to_euler(f32 *, f32 *, f32 *, f32, f32);

void *kar_diag__803ad760(s32, s32, void *, void *, s32);

void *TopRideItem_GetDataBase(void);
void *fn_80305ABC(void *, u32);
void __construct_array(void *, void *, s32, s32, s32);
extern void *fn_802CD8DC;

double tan(double);

void kar_a2d_game_lib__802894bc(void *jobj, void *joint, s32 classId);
u8 kar_a2d_game_lib__near_802897e0(void *jobj);
void kar_a2d_game_lib__near_8028b2cc(void *cobj);
void kar_a2d_game_lib__near_8028b358(f32, f32, f32, f32, f32, f32, f32, f32);

void *kar_a2d_effecthandle__near_8037cf54(u32);

extern s32 lbl_805DDA28;
extern s32 lbl_805DDA40;
extern s32 lbl_805DDAE8;
extern s32 lbl_805DDBE0;

extern f32 lbl_80503FC0[3][4];
extern f32 lbl_805E4CB4;

extern char lbl_804BD6D4[];
extern char lbl_804BD6FC[];
extern char lbl_804BDE38[];
extern char lbl_804BDE78[];
extern char lbl_804BF238[];
extern char lbl_804BF260[];

}

#define ASSERT2(line, cond, file, str) \
    ((cond) ? ((void) 0) : __assert(file, line, str))

static char kar_src_a2d_wipeeffect_804f35f0[] = "a2d_wipeeffect.cpp";

static char lbl_804F3604[] = "WipeEffect";
static char lbl_804F3610[] = "ObjCollect<WipeEffect>";
static char lbl_804F3628[0x10];

static char lbl_804F3638[] = "EffectMapFade";
static char lbl_804F3648[] = "ObjCollect<EffectMapFade>";
static char lbl_804F3664[0x1C];

static char lbl_804F3680[] = "EffectLantern";
static char lbl_804F3690[] = "ObjCollect<EffectLantern>";
static char lbl_804F36AC[0xC];

static char lbl_804F36B8[] = "EffectLanternContainer";
static char lbl_804F36D0[] = "Singleton<EffectLanternContainer>";
static char lbl_804F36F4[0xC];

static char lbl_804F3700[] = "translate";

static u8 lbl_804F3720[0x80] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};

struct NamePair {
    char *a;
    char *b;
};

static char lbl_805DBD48[] = "jobj_";
static NamePair lbl_805DBD50 = {lbl_804F3610, 0};
static NamePair lbl_805DBD58 = {lbl_804F3604, lbl_804F3628};
static NamePair lbl_805DBD60 = {lbl_804F3648, 0};
static NamePair lbl_805DBD68 = {lbl_804F3638, lbl_804F3664};
static NamePair lbl_805DBD70 = {lbl_804F3690, 0};
static NamePair lbl_805DBD78 = {lbl_804F3680, lbl_804F36AC};
static NamePair lbl_805DBD80 = {lbl_804F36D0, 0};
static NamePair lbl_805DBD88 = {lbl_804F36B8, lbl_804F36F4};

static char lbl_805DBD98[] = "jobj";
static char lbl_805DBDA0[] = "rotate";

class WipeCameraHolder : public RefObj {
public:
    void **unk4;
    void *unk8;
    void *unkC;
    HSD_JObj *unk10;
    void *unk14;
    u8 unk18;
    u8 pad19[3];
    s32 unk1C;
};

class WipeJointAnim : public DiagObj {
public:
    s32 pad4;
    s32 pad8;
    s32 *unkC;
    HSD_JObj *unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
};

struct WipeListItem : public DiagObj {
    u32 pad4;
    u32 pad8;
    u8 unkC;
    u8 pad[3];
    s32 unk10;
};

struct EffectMapFadeObj : public DiagObj {
    u32 pad4;
    u32 pad8;
    u32 unkC;
    u32 unk10;
    u8 unk14;
    u8 unk15, unk16, unk17, unk18;
    u8 unk19, unk1A, unk1B, unk1C;
    s8 unk1D, unk1E, unk1F, unk20;
};

extern "C" void kar_a2d_wipeeffect__8037e3cc(WipeCameraHolder *arg0, void *joint) {
    if (arg0->unk10 == NULL) {
        arg0->unk10 = (HSD_JObj *) HSD_JObjLoadJoint(joint);
        ASSERT2(0x23, arg0->unk10 != NULL, kar_src_a2d_wipeeffect_804f35f0, lbl_805DBD48);
    }
}

extern "C" void kar_a2d_wipeeffect__near_8037e42c(WipeCameraHolder *arg0, void *arg1, s32 arg2) {
    if (arg0->unk10 != NULL) {
        HSD_JObjRemoveAnimAll();
        kar_a2d_game_lib__802894bc(arg0->unk10, arg1, arg2);
    }
}

extern "C" void kar_a2d_wipeeffect__near_8037e48c(WipeCameraHolder *arg0) {
    BOOL active = FALSE;
    WipeListItem *item = (WipeListItem *) kar_diag__803ad760(lbl_805DDA40, 0, &lbl_805DBD58, &lbl_805DBD50, 0);
    while (item != NULL) {
        if (item->unkC != 0) {
            if (arg0->unk18 == 0) {
                s32 classId = item->unk10;
                if (arg0->unk1C != classId) {
                    arg0->unk1C = classId;
                    kar_a2d_wipeeffect__near_8037e42c(arg0, *(void **) arg0->unk4, classId);
                }
                HSD_JObjReqAnimAll(arg0->unk10, 0.0f);
                arg0->unk18 = 1;
            }
            active = TRUE;
        }
        item = (WipeListItem *) item->GetNext();
    }
    if (!active || kar_a2d_game_lib__near_802897e0(arg0->unk10) != 0) {
        arg0->unk18 = 0;
        item = (WipeListItem *) kar_diag__803ad760(lbl_805DDA40, 0, &lbl_805DBD58, &lbl_805DBD50, 0);
        while (item != NULL) {
            item->unkC = 0;
            item = (WipeListItem *) item->GetNext();
        }
        return;
    }
    HSD_JObjAnimAll(arg0->unk10);
}

extern "C" void kar_a2d_wipeeffect__near_8037e5dc(s32 arg0, s32 arg1) {
    void *cobj = HSD_CObjGetCurrent();
    u8 alpha = 0xFF;
    f32 x0 = (f32) -arg0;
    f32 y1 = (f32) arg1;
    f32 sc22, sc1c, sc1e, sc20;

    sc22 = (f32) *(u16 *) ((char *) cobj + 0x22);
    y1 -= sc22;

    sc1c = (f32) *(u16 *) ((char *) cobj + 0x1C);
    sc1e = (f32) *(u16 *) ((char *) cobj + 0x1E);
    sc20 = (f32) *(u16 *) ((char *) cobj + 0x20);
    sc22 = (f32) *(u16 *) ((char *) cobj + 0x22);

    GXClearVtxDesc();
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_TEX_S, GX_RGBA6, 0);
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_TEX_ST, GX_RGBA8, 0);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXInvalidateVtxCache();
    GXSetCurrentMtx(GX_PNMTX0);
    GXLoadPosMtxImm((char *) cobj + 0x54, GX_PNMTX0);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ONE, GX_CC_RASC);
    fn_803CEC68(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ONE, GX_CA_RASA);
    fn_803CECD0(0, 0, 0, 0, 1, 0);
    GXSetNumChans(1);
    GXSetChanCtrl(GX_COLOR0A0, GX_DISABLE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumTexGens(0);
    GXSetNumTevStages(1);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    GXSetZMode(GX_DISABLE, GX_ALWAYS, GX_DISABLE);
    GXBegin(GX_QUADS, GX_VTXFMT0, 8);

    *(f32 *) 0xCC008000 = sc1c;
    f32 negSc22 = -sc22;
    *(f32 *) 0xCC008000 = sc20;
    *(f32 *) 0xCC008000 = (u8) 0xFF;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = sc1e;
    *(f32 *) 0xCC008000 = sc20;
    *(f32 *) 0xCC008000 = (u8) 0xFF;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = sc1e;
    *(f32 *) 0xCC008000 = x0;
    *(f32 *) 0xCC008000 = (u8) 0xFF;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = sc1c;
    *(f32 *) 0xCC008000 = x0;
    *(f32 *) 0xCC008000 = (u8) 0xFF;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = sc1c;
    *(f32 *) 0xCC008000 = y1;
    *(f32 *) 0xCC008000 = (u8) 0xFF;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = sc1e;
    *(f32 *) 0xCC008000 = y1;
    *(f32 *) 0xCC008000 = (u8) 0xFF;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = sc1e;
    *(f32 *) 0xCC008000 = negSc22;
    *(f32 *) 0xCC008000 = (u8) 0xFF;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = sc1c;
    *(f32 *) 0xCC008000 = negSc22;
    *(f32 *) 0xCC008000 = (u8) 0xFF;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = alpha;
    *(f32 *) 0xCC008000 = alpha;
}

extern "C" void kar_a2d_wipeeffect__near_8037e8f0(WipeCameraHolder *arg0) {
    if (HSD_CObjSetCurrent(arg0->unk14)) {
        kar_a2d_wipeeffect__near_8037e5dc(0x28, 0x3C);
        HSD_CObjEndCurrent();
    }
}

extern "C" void kar_a2d_wipeeffect__near_8037e92c(WipeCameraHolder *arg0) {
    if (arg0->unk18 != 0 && HSD_CObjSetCurrent(arg0->unk8)) {
        HSD_LObjDeleteCurrentAll(0);
        HSD_CObjGetCurrent();
        HSD_LObjSetupInit();
        HSD_LObjAddCurrent(arg0->unkC);
        HSD_JObjDispAll(arg0->unk10, 0, 1, 0x08000000);
        HSD_JObjDispAll(arg0->unk10, 0, 4, 0x08000000);
        HSD_JObjDispAll(arg0->unk10, 0, 2, 0x08000000);
        HSD_CObjEndCurrent();
    }
}

struct SmallDiagItem : public DiagObj {
    s32 pad4;
    s32 pad8;
    void *unkC;
    void *unk10;
    u8 unk14;
};

extern "C" DiagObj *kar_a2d_wipeeffect__near_8037e9c8(DiagObj *arg0) {
    *(void **) arg0 = lbl_804BF238;
    ((SmallDiagItem *) arg0)->pad4 = 0;
    ((SmallDiagItem *) arg0)->pad8 = 0;
    arg0->Init();
    *(void **) arg0 = lbl_804BF260;
    ((SmallDiagItem *) arg0)->unkC = 0;
    ((SmallDiagItem *) arg0)->unk10 = 0;
    ((SmallDiagItem *) arg0)->unk14 = 0;
    return arg0;
}

extern "C" void kar_a2d_wipeeffect__near_8037ea38(EffectMapFadeObj *arg0) {
    u32 total = arg0->unk10;
    f32 t;
    if (total != 0) {
        t = (f32) arg0->unkC / (f32) total;
    } else {
        t = 0.0f;
    }
    f32 inv = 1.0f - t;
    arg0->unk1D = (s8) (((f32) arg0->unk15 * t) + ((f32) arg0->unk19 * inv));
    arg0->unk1E = (s8) (((f32) arg0->unk16 * t) + ((f32) arg0->unk1A * inv));
    arg0->unk1F = (s8) (((f32) arg0->unk17 * t) + ((f32) arg0->unk1B * inv));
    arg0->unk20 = (s8) (((f32) arg0->unk18 * t) + ((f32) arg0->unk1C * inv));
    u32 count = arg0->unkC;
    if (count != 0) {
        arg0->unkC = count - 1;
        if (arg0->unk14 == 0 && arg0->unkC == 0) {
            arg0->unkC = 0;
            arg0->unk10 = 0;
            arg0->unk14 = 0;
        }
    }
}

extern "C" void kar_a2d_wipeeffect__near_8037ebd4(WipeCameraHolder *arg0) {
    f32 sumA = 0.0f, sumB = 0.0f, sumC = 0.0f, sumD = 0.0f;
    u32 n = 0;
    EffectMapFadeObj *item = (EffectMapFadeObj *) kar_diag__803ad760(lbl_805DDA28, 0, &lbl_805DBD68, &lbl_805DBD60, 0);
    while (item != NULL) {
        if (item->unkC != 0 || item->unk14 != 0) {
            n += 1;
            sumA += (f32) item->unk1D;
            sumB += (f32) item->unk1E;
            sumC += (f32) item->unk1F;
            sumD += (f32) item->unk20;
        }
        item = (EffectMapFadeObj *) item->GetNext();
    }
    if (n != 0) {
        f32 inv = 1.0f / (f32) n;
        s8 cD = (s8) (sumD * inv);
        s8 cC = (s8) (sumC * inv);
        s8 cB = (s8) (sumB * inv);
        s8 cA = (s8) (sumA * inv);
        if (HSD_CObjSetCurrent(arg0->unk4)) {
            kar_a2d_game_lib__near_8028b2cc(arg0->unk4);
            GXClearVtxDesc();
            GXSetCullMode(GX_CULL_BACK);
            GXSetNumTexGens(0);
            GXSetNumTevStages(1);
            u8 color[4];
            color[0] = cD;
            color[1] = cC;
            color[2] = cB;
            color[3] = cA;
            GXSetTevColor(GX_TEVREG0, color);
            GXSetZMode(GX_DISABLE, GX_ALWAYS, GX_DISABLE);
            GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_TEX_S, GX_RGBA6, 0);
            GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
            GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
            GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ONE, GX_CC_C0);
            fn_803CEC68(0, 0, 0, 0, 1, 0);
            GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ONE, GX_CA_A0);
            fn_803CECD0(0, 0, 0, 0, 1, 0);
            GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
            GXBegin(GX_QUADS, GX_VTXFMT0, 4);
            f32 top = -480.0f;
            *(f32 *) 0xCC008000 = 0.0f;
            *(f32 *) 0xCC008000 = 0.0f;
            *(f32 *) 0xCC008000 = 660.0f;
            *(f32 *) 0xCC008000 = 0.0f;
            *(f32 *) 0xCC008000 = 660.0f;
            *(f32 *) 0xCC008000 = top;
            *(f32 *) 0xCC008000 = 0.0f;
            *(f32 *) 0xCC008000 = top;
            HSD_CObjEndCurrent();
        }
    }
}

extern "C" void kar_a2d_wipeeffect__near_8037efb0(WipeJointAnim *arg0, s32 *arg1);

extern "C" WipeJointAnim *kar_a2d_wipeeffect__near_8037eefc(WipeJointAnim *arg0, s32 arg1) {
    *(void **) arg0 = lbl_804BD6D4;
    arg0->pad4 = 0;
    arg0->pad8 = 0;
    ((DiagObj *) arg0)->Init();
    *(void **) arg0 = lbl_804BD6FC;
    arg0->unkC = 0;
    kar_a2d_wipeeffect__near_8037efb0(arg0, (s32 *) ((WipeJointAnim *) kar_diag__803ad760(lbl_805DDBE0, 0, &lbl_805DBD88, &lbl_805DBD80, 0))->unk10);
    arg0->unk14 = arg1;
    arg0->unk24 = 0;
    arg0->unk20 = 0;
    arg0->unk18 = 0;
    arg0->unk1C = 0;
    return arg0;
}

extern "C" void kar_a2d_wipeeffect__near_8037efb0(WipeJointAnim *arg0, s32 *arg1) {
    if (arg0->unkC == NULL && arg1 != NULL) {
        arg0->unkC = arg1;
        arg0->unk10 = (HSD_JObj *) HSD_JObjLoadJoint(*(void **) arg1);
        kar_a2d_game_lib__802894bc(arg0->unk10, arg1, 0);
    }
}

extern "C" void kar_a2d_wipeeffect__near_8037f018(WipeJointAnim *arg0, s32 arg1) {
    f32 eye[3];
    f32 up[3];
    f32 euler[3];
    HSD_JObj *jobj;

    if (HSD_CObjGetEyeVector(arg1, eye) && HSD_CObjGetUpVector(arg1, up)) {
        PSVECNormalize(up, up);
        eye[0] = -eye[0];
        eye[1] = -eye[1];
        eye[2] = -eye[2];
        kar_lbvector_dirs_to_euler(euler, eye, up, eye[1], eye[0]);
        jobj = arg0->unk10;
        ASSERT2(0x290, jobj != NULL, kar_src_a2d_wipeeffect_804f35f0, lbl_805DBD98);
        ASSERT2(0x291, euler != NULL, kar_src_a2d_wipeeffect_804f35f0, lbl_805DBDA0);
        jobj->rotate[0] = euler[0];
        jobj->rotate[1] = euler[1];
        jobj->rotate[2] = euler[2];
        jobj->rotate[3] = up[0];
        if (!(jobj->flags & 0x02000000)) {
            ASSERT2(0x25D, jobj != NULL, kar_src_a2d_wipeeffect_804f35f0, lbl_805DBD98);
            if (!(jobj->flags & 0x800000) && (jobj->flags & 0x40)) {
            } else {
                HSD_JObjSetMtxDirtySub(jobj);
            }
        }
    }

    jobj = arg0->unk10;
    s32 *tr = arg0->unkC;
    ASSERT2(0x3A9, jobj != NULL, kar_src_a2d_wipeeffect_804f35f0, lbl_805DBD98);
    ASSERT2(0x3AA, tr != NULL, kar_src_a2d_wipeeffect_804f35f0, lbl_804F3700);
    jobj->translate[0] = (f32) tr[0];
    jobj->translate[1] = (f32) tr[1];
    jobj->translate[2] = (f32) tr[2];
    if (!(jobj->flags & 0x02000000)) {
        ASSERT2(0x25D, jobj != NULL, kar_src_a2d_wipeeffect_804f35f0, lbl_805DBD98);
        if (!(jobj->flags & 0x800000) && (jobj->flags & 0x40)) {
        } else {
            HSD_JObjSetMtxDirtySub(jobj);
        }
    }

    f32 t;
    switch (arg0->unk24) {
    case 1:
        t = (f32) arg0->unk20 / 60.0f;
        break;
    case 2:
        t = 0.0f;
        break;
    case 3:
        t = 1.0f - ((f32) arg0->unk20 / 60.0f);
        break;
    default:
        t = 1.0f;
        break;
    }
    if (t > 1.0f) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    jobj = arg0->unk10;
    f32 scale = 1.0001f - t;
    ASSERT2(0x325, jobj != NULL, kar_src_a2d_wipeeffect_804f35f0, lbl_805DBD98);
    jobj->scale[0] = scale;
    if (!(jobj->flags & 0x02000000)) {
        ASSERT2(0x25D, jobj != NULL, kar_src_a2d_wipeeffect_804f35f0, lbl_805DBD98);
        if (!(jobj->flags & 0x800000) && (jobj->flags & 0x40)) {
        } else {
            HSD_JObjSetMtxDirtySub(jobj);
        }
    }

    jobj = arg0->unk10;
    ASSERT2(0x333, jobj != NULL, kar_src_a2d_wipeeffect_804f35f0, lbl_805DBD98);
    jobj->scale[1] = scale;
    if (!(jobj->flags & 0x02000000)) {
        ASSERT2(0x25D, jobj != NULL, kar_src_a2d_wipeeffect_804f35f0, lbl_805DBD98);
        if (!(jobj->flags & 0x800000) && (jobj->flags & 0x40)) {
        } else {
            HSD_JObjSetMtxDirtySub(jobj);
        }
    }
}

extern "C" void kar_a2d_wipeeffect__near_8037f3bc(WipeJointAnim *arg0, s32 arg1) {
    if (arg0->unk1C != 0) {
        HSD_JObjAnimAll(arg0->unk10);
        switch (arg0->unk24) {
        case 0:
            break;
        case 1:
            if (arg0->unk20 != 0) {
                arg0->unk20 -= 1;
            } else {
                arg0->unk24 = 2;
            }
            break;
        case 2:
            if (arg0->unk18 >= 0 && arg0->unk18 <= 0x3C) {
                arg0->unk24 = 3;
                arg0->unk20 = 0x3C;
            }
            break;
        case 3:
            if (arg0->unk20 != 0) {
                arg0->unk20 -= 1;
            } else {
                arg0->unk24 = 0;
            }
            break;
        }
        if (arg0->unk18 > 0) {
            arg0->unk18 -= 1;
            if (arg0->unk18 == 0) {
                arg0->unk24 = 0;
                arg0->unk20 = 0;
                arg0->unk18 = 0;
                arg0->unk1C = 0;
                return;
            }
            kar_a2d_wipeeffect__near_8037f018(arg0, arg1);
            return;
        }
        kar_a2d_wipeeffect__near_8037f018(arg0, arg1);
    }
}

extern "C" void kar_a2d_wipeeffect__near_8037f4f8(u8 *color, s32 doColor, s32 doAlpha, s32 useTex,
                                                   f32 left, f32 right, f32 top, f32 bottom, f32 z) {
    if (doColor != 0 || doAlpha != 0 || useTex != 0) {
        if (useTex != 0) {
            GXInitTexObj(lbl_804F3720, 0, 4, 4, GX_TF_Z8, GX_REPEAT, GX_REPEAT, GX_DISABLE);
            GXLoadTexObj(lbl_804F3720, GX_TEXMAP0);
            GXSetNumTexGens(1);
            GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x3C, GX_DISABLE, 0x7D);
            GXSetNumTevStages(1);
            GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
            GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
            GXSetZTexture(2, 0x11, 0);
        } else {
            GXSetNumTexGens(0);
            GXSetNumTevStages(1);
            GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
            GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
        }
        GXSetCullMode(GX_CULL_NONE);
        GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
        GXSetZCompLoc(GX_ENABLE);
        GXSetZMode(GX_ENABLE, GX_ALWAYS, useTex != 0);
        GXSetBlendMode(GX_BM_LOGIC, GX_BL_ONE, GX_BL_ZERO, GX_LO_COPY);
        GXSetColorUpdate(doColor != 0);
        GXSetAlphaUpdate(doAlpha != 0);
        GXSetNumChans(1);
        GXSetChanCtrl(GX_COLOR0A0, GX_DISABLE, GX_SRC_REG, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
        GXClearVtxDesc();
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_TEX_ST, GX_RGBA6, 0);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_TEX_ST, GX_RGBA8, 0);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_RGB565, 0);
        GXLoadPosMtxImm(lbl_80503FC0, GX_PNMTX0);
        GXSetCurrentMtx(GX_PNMTX0);
        GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
        GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
        GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
        GXBegin(GX_QUADS, GX_VTXFMT0, 4);
        u8 c0 = color[0], c1 = color[1], c2 = color[2], c3 = color[3];
        *(f32 *) 0xCC008000 = top;
        *(f32 *) 0xCC008000 = left;
        *(f32 *) 0xCC008000 = -z;
        *(f32 *) 0xCC008000 = c0;
        *(f32 *) 0xCC008000 = c1;
        *(f32 *) 0xCC008000 = c2;
        *(f32 *) 0xCC008000 = c3;
        *(f32 *) 0xCC008000 = 0;
        *(f32 *) 0xCC008000 = 0;
        *(f32 *) 0xCC008000 = bottom;
        *(f32 *) 0xCC008000 = left;
        *(f32 *) 0xCC008000 = -z;
        *(f32 *) 0xCC008000 = c0;
        *(f32 *) 0xCC008000 = c1;
        *(f32 *) 0xCC008000 = c2;
        *(f32 *) 0xCC008000 = c3;
        *(f32 *) 0xCC008000 = 1;
        *(f32 *) 0xCC008000 = 0;
        *(f32 *) 0xCC008000 = bottom;
        *(f32 *) 0xCC008000 = right;
        *(f32 *) 0xCC008000 = -z;
        *(f32 *) 0xCC008000 = c0;
        *(f32 *) 0xCC008000 = c1;
        *(f32 *) 0xCC008000 = c2;
        *(f32 *) 0xCC008000 = c3;
        *(f32 *) 0xCC008000 = 1;
        *(f32 *) 0xCC008000 = 1;
        *(f32 *) 0xCC008000 = top;
        *(f32 *) 0xCC008000 = right;
        *(f32 *) 0xCC008000 = -z;
        *(f32 *) 0xCC008000 = c0;
        *(f32 *) 0xCC008000 = c1;
        *(f32 *) 0xCC008000 = c2;
        *(f32 *) 0xCC008000 = c3;
        *(f32 *) 0xCC008000 = 0;
        *(f32 *) 0xCC008000 = 1;
        GXSetZTexture(0, 0x11, 0);
        HSD_StateInvalidate(-1);
    }
}

struct WipeLanternDrawObj {
    void *vtbl;
    char unk4[0x18];
    HSD_JObj *unk10;
    s32 pad14;
    s32 unk18;
    u32 unk1C;
    void *unk20;
    s32 pad24;
    u8 unk28;
};

extern "C" void kar_a2d_wipeeffect__near_8037f840(WipeLanternDrawObj *arg0) {
    arg0->unk28 = 0;
    f32 minBlend = 1.0f;
    WipeJointAnim *item = (WipeJointAnim *) kar_diag__803ad760(lbl_805DDAE8, 0, &lbl_805DBD78, &lbl_805DBD70, 0);
    while (item != NULL) {
        if (item->unk18 != 0) {
            arg0->unk28 = 1;
            f32 t;
            switch (item->unk24) {
            case 1:
                t = (f32) item->unk20 / 60.0f;
                break;
            case 2:
                t = 0.0f;
                break;
            case 3:
                t = 1.0f - ((f32) item->unk20 / 60.0f);
                break;
            default:
                t = 1.0f;
                break;
            }
            if (t > 1.0f) {
                t = 1.0f;
            } else if (t < 0.0f) {
                t = 0.0f;
            }
            if (minBlend > t) {
                minBlend = t;
            }
        }
        item = (WipeJointAnim *) item->GetNext();
    }

    if (arg0->unk28 != 0) {
        if (HSD_CObjSetCurrent(arg0->unk20)) {
            void *im = TopRideItem_GetDataBase();
            f32 imAlpha = *(f32 *) ((char *) im + 0x4E0);
            void *cobj = arg0->unk20;
            f32 invAlpha = 255.0f - imAlpha;
            u8 color[4];
            color[3] = 0;
            u8 c = (u8) ((minBlend * invAlpha) + imAlpha);
            color[0] = c;
            color[2] = c;
            color[1] = c;
            if (cobj != NULL) {
                f32 farPlane = HSD_CObjGetFar(cobj);
                f32 sum = HSD_CObjGetNear(cobj) + farPlane;
                f32 half = 0.5f * sum;
                s32 projType = HSD_CObjGetProjectionType(cobj);
                f32 px, py, pw, ph;
                switch (projType) {
                case 1: {
                    f32 fov = *(f32 *) ((char *) cobj + 0x40);
                    f32 aspect = *(f32 *) ((char *) cobj + 0x44);
                    py = half * (f32) tan(0.5 * (0.017453292f * fov));
                    px = py * aspect;
                    ph = -py;
                    pw = -px;
                    break;
                }
                case 2: {
                    f32 s = half / HSD_CObjGetNear(cobj);
                    px = s * *(f32 *) ((char *) cobj + 0x4C);
                    pw = s * *(f32 *) ((char *) cobj + 0x48);
                    py = s * *(f32 *) ((char *) cobj + 0x40);
                    ph = s * *(f32 *) ((char *) cobj + 0x44);
                    break;
                }
                case 3:
                    px = *(f32 *) ((char *) cobj + 0x4C);
                    pw = *(f32 *) ((char *) cobj + 0x48);
                    py = *(f32 *) ((char *) cobj + 0x40);
                    ph = *(f32 *) ((char *) cobj + 0x44);
                    break;
                default:
                    px = py = pw = ph = 0.0f;
                    break;
                }
                kar_a2d_wipeeffect__near_8037f4f8(color, 1, 0, 0, py, ph, pw, px, -half);
            }

            WipeLanternDrawObj *jo = (WipeLanternDrawObj *) kar_diag__803ad760(lbl_805DDAE8, 0, &lbl_805DBD78, &lbl_805DBD70, 0);
            while (jo != NULL) {
                if (jo->unk1C != 0) {
                    HSD_JObjDispAll(jo->unk10, 0, 1, 0);
                    HSD_JObjDispAll(jo->unk10, 0, 4, 0);
                    HSD_JObjDispAll(jo->unk10, 0, 2, 0);
                }
                jo = (WipeLanternDrawObj *) ((DiagObj *) jo)->GetNext();
            }
            HSD_CObjEndCurrent();
        }
        HSD_ImageDescCopyFromEFB(&arg0->unk4, 0, 0, 1, 1);
    }
}

struct WipeLanternTexObj {
    void *vtbl;
    void *unk4;
    u16 unk8;
    u16 unkA;
    u32 unkC;
    u32 unk10;
    char pad14[0x10];
    void *unk24;
    u8 unk28;
};

extern "C" void kar_a2d_wipeeffect__near_8037fbd8(WipeLanternTexObj *arg0) {
    if (arg0->unk28 != 0 && HSD_CObjSetCurrent(arg0->unk24)) {
        kar_a2d_game_lib__near_8028b2cc(arg0->unk24);
        GXTexObj tex;
        GXInitTexObj(&tex, arg0->unk4, arg0->unk8, arg0->unkA, arg0->unkC, GX_CLAMP, GX_CLAMP, arg0->unk10);
        GXLoadTexObj(&tex, GX_TEXMAP0);
        GXClearVtxDesc();
        GXSetCullMode(GX_CULL_BACK);
        GXSetNumTexGens(1);
        GXSetNumTevStages(1);
        GXSetZMode(GX_DISABLE, GX_ALWAYS, GX_DISABLE);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_TEX_S, GX_RGBA6, 0);
        GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_RGBA6, 0);
        GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
        GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ONE, GX_CC_TEXC);
        fn_803CEC68(0, 0, 0, 0, 1, 0);
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ONE, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
        fn_803CECD0(0, 0, 0, 0, 1, 0);
        GXSetBlendMode(GX_BM_BLEND, GX_BL_DSTCLR, GX_BL_ZERO, GX_LO_CLEAR);
        u16 w = arg0->unk8;
        s32 rows = arg0->unkA / fn_803CDC34(&tex);
        kar_a2d_game_lib__near_8028b358(0.0f, 0.0f, (f32) w, (f32) arg0->unkA,
                                         (f32) (w / fn_803CDC24(&tex, rows)), (f32) rows, 1.0f, 1.0f);
        HSD_CObjEndCurrent();
    }
}

class WipeSlideBlurItem : public RefObj {
public:
    void *unk4;
    void *unk8;
    void *unkC;
    HSD_JObj *unk10;
    s32 unk14;
    s8 unk18, unk19, unk1A, unk1B;
    s8 unk1C, pad1D;
    u16 unk1E;
};

#define FF(p, off) (*(f32 *) ((char *) (p) + (off)))
#define BB(p, off) (*(u8 *) ((char *) (p) + (off)))

extern "C" WipeSlideBlurItem *EffectSlideBlurMgr_CreateSlideBlurSimple(WipeSlideBlurItem *arg0, u8 arg1, u16 arg2) {
    *(void **) arg0 = lbl_804BDE38;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    ((DiagObj *) arg0)->Init();
    *(void **) arg0 = lbl_804BDE78;
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    arg0->unk18 = 0;
    arg0->unk1A = 0;
    arg0->unk1C = 0;
    FF(arg0, 0x34) = lbl_805E4CB4;
    FF(arg0, 0x30) = lbl_805E4CB4;
    FF(arg0, 0x2C) = lbl_805E4CB4;
    FF(arg0, 0x40) = lbl_805E4CB4;
    FF(arg0, 0x3C) = lbl_805E4CB4;
    FF(arg0, 0x38) = lbl_805E4CB4;
    FF(arg0, 0x4C) = lbl_805E4CB4;
    FF(arg0, 0x48) = lbl_805E4CB4;
    FF(arg0, 0x44) = lbl_805E4CB4;
    *(void **) ((char *) arg0 + 0x50) = 0;
    __construct_array((char *) arg0 + 0x58, &fn_802CD8DC, 0, 0xC, 4);
    BB(arg0, 0x54) = arg1;
    if (arg1 != 0) {
        BB(arg0, 0x28) = 0x64;
        BB(arg0, 0x29) = 0x64;
        BB(arg0, 0x2A) = 0x64;
        BB(arg0, 0x2B) = 0xFF;
        BB(arg0, 0x24) = 0;
        BB(arg0, 0x25) = 0;
        BB(arg0, 0x26) = 0;
        BB(arg0, 0x27) = 0;
    } else {
        BB(arg0, 0x28) = 0xA0;
        BB(arg0, 0x29) = 0xA0;
        BB(arg0, 0x2A) = 0xA0;
        BB(arg0, 0x2B) = 0xFF;
        BB(arg0, 0x24) = 0xFF;
        BB(arg0, 0x25) = 0xFF;
        BB(arg0, 0x26) = 0xFF;
        BB(arg0, 0x27) = 0;
    }
    if (arg2 != 0) {
        arg0->unk1E = arg2;
    } else {
        if (arg1 != 0) {
            arg0->unk1E = 0x26;
        }
        arg0->unk1E = 0x2A;
    }
    fn_80305ABC((char *) arg0 + 0xC, arg0->unk1E);
    FF(arg0, 0x98) = lbl_805E4CB4;
    arg0->unk1C = 0;
    arg0->unk1A = 0;
    arg0->unk18 = 1;
    BB(arg0, 0x55) = 0;
    FF(arg0, 0x44) = lbl_805E4CB4;
    FF(arg0, 0x38) = lbl_805E4CB4;
    FF(arg0, 0x2C) = lbl_805E4CB4;
    FF(arg0, 0x48) = lbl_805E4CB4;
    FF(arg0, 0x3C) = lbl_805E4CB4;
    FF(arg0, 0x30) = lbl_805E4CB4;
    FF(arg0, 0x4C) = lbl_805E4CB4;
    FF(arg0, 0x40) = lbl_805E4CB4;
    FF(arg0, 0x34) = lbl_805E4CB4;
    return arg0;
}
