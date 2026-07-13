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
#define GX_TRIANGLESTRIP    0x98
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
#define GX_CC_ZERO          15
#define GX_CC_ONE           12
#define GX_CC_RASC          10
#define GX_CC_TEXC          8
#define GX_CA_ZERO          7
#define GX_CA_ONE           6
#define GX_CA_RASA          5
#define GX_CA_TEXA          4
#define GX_TEVREG0          1
#define GX_PASSCLR          4
#define GX_ALWAYS           7
#define GX_LESS             1
#define GX_AOP_OR           1
#define GX_BM_BLEND         1
#define GX_BM_SUBTRACT      3
#define GX_BL_ZERO          0
#define GX_BL_ONE           1
#define GX_BL_SRCALPHA      4
#define GX_BL_INVSRCALPHA   5
#define GX_LO_CLEAR         0
#define GX_CULL_BACK        2
#define GX_PNMTX0           0
#define GX_CLAMP            0
#define GX_TG_TEX0          4
#define GX_TG_MTX2x4        1

#define GX_FIFO_U8  (*(volatile u8 *) 0xCC008000)
#define GX_FIFO_F32 (*(volatile f32 *) 0xCC008000)

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
    u32 flags;        //0x14
    s32 pad18;
    f32 rotate[4];    //0x1C
    f32 scale[3];     //0x2C
    f32 translate[3]; //0x38
    f32 mtx[12];      //0x44
};

class TargetObj {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual s32 IsMoving();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void *GetVec74();
    virtual void v28();
    virtual void *GetVec7C();
    virtual void v30();
    virtual void *GetVec84();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void Prepare();
};

struct Vec3Result {
    f32 x, y, z;
};

extern "C" {

void *HSD_JObjLoadJoint(void *joint);
void HSD_JObjAnimAll(void *jobj);
void HSD_JObjReqAnimAll(void *jobj, f32 frame);
void HSD_JObjSetFlagsAll(void *jobj, u32 flags);
void HSD_JObjClearFlagsAll(void *jobj, u32 flags);
void HSD_JObjSetMtxDirtySub(HSD_JObj *jobj);
void HSD_JObjSetupMatrixSub(HSD_JObj *jobj);
void HSD_ForeachAnim(void *jobj, s32, u32, void *fn, s32, u32);
extern void *HSD_AObjSetFlags;
extern void *HSD_AObjClearFlags;

BOOL HSD_CObjSetCurrent(void *cobj);
void HSD_CObjEndCurrent(void);
void *HSD_CObjGetCurrent(void);
void *HSD_CObjLoadDesc(void *desc);
void HSD_StateInvalidate(s32);

void GXInvalidateVtxCache(void);
void GXClearVtxDesc(void);
void GXSetVtxAttrFmt(u32, u32, u32, u32, u32);
void GXSetVtxDesc(u32, u32);
void GXSetCurrentMtx(u32);
void GXLoadPosMtxImm(void *, u32);
void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u32);
void GXLoadTexObj(void *, u32);
void GXSetTevOrder(u32, u32, u32, u32);
void GXSetTevColorIn(u32, u32, u32, u32, u32);
void GXSetTevAlphaIn(u32, u32, u32, u32, u32);
void GXSetTexCoordGen2(u32, u32, u32, u32, u32, u32);
void GXSetNumChans(u32);
void GXSetChanCtrl(u32, u32, u32, u32, u32, u32, u32);
void GXSetNumTexGens(u32);
void GXSetNumTevStages(u32);
void GXSetBlendMode(u32, u32, u32, u32);
void GXSetZMode(u32, u32, u32);
void GXSetCullMode(u32);
void GXBegin(u32, u32, u16);
void GXSetTevColor(u32, void *);
void fn_803CEC68(u32, u32, u32, u32, u32, u32);
void fn_803CECD0(u32, u32, u32, u32, u32, u32);

void PSVECAdd(void *, void *, void *);
void PSVECSubtract(void *, void *, void *);
void PSVECScale(void *, void *, f32);
f32 PSVECMag(void *, f32, f32);
f32 PSVECDotProduct(void *, void *, f32);
void PSVECCrossProduct(void *, void *, void *, f32, f32);

void *__construct_array(void *, void *, s32, s32, s32);
void fn_802CD8DC(void *);

void *fn_8038D0A8(const char *);
u16 fn_80305ABC(void *, u16);

void *kar_diag__803ad760(s32, s32, void *, void *, s32);

void *kar_a2d_effecthandle__near_8037d0cc(void);

void kar_a2d_game_lib__802894bc(void *jobj, void *joint, s32 classId);
u8 kar_a2d_game_lib__near_8028b11c(s32, s32);
void kar_a2d_kurakko__near_80376c50(u8 *, void *, void *, f32);
void kar_pslist__near_80438c50(s32, f32, f32, f32, f32, f32);

void hsdInitClassInfo(void *, void *, void *, void *, s32, s32);
extern char hsdJObj[0x54];

void *memset(void *, s32, u32);
void OSReport(const char *, ...);

f64 __frsqrte(f64 x);
f64 __fnmsub(f64 a, f64 c, f64 b);

extern s32 lbl_805DDA34;
extern s32 lbl_805DDB44;
extern s32 lbl_805DDBDC;
extern void *lbl_805DDC78;

extern f32 lbl_805E4CB4; /* 0.0F */
extern f32 lbl_805E4CF8; /* 0.0F */

extern char lbl_804BDE38[];
extern char lbl_804BDE78[];
extern char lbl_804BD7B4[];
extern char lbl_804BD7DC[];

}

namespace {
extern "C" void kar_a2d_game_lib__near_8028b050(void *, s32, s32, s32);
}

extern "C" void kar_a2d_game_lib__near_8028b050(void *, s32, s32, s32, void *);

#define ASSERT2(line, cond, file, str) \
    ((cond) ? ((void) 0) : __assert(file, line, str))

extern "C" char lbl_804F37A0[] = "PostDrawEffect";
extern "C" char lbl_804F37B0[0x38] = "ObjCollect<PostDrawEffect>\0\0\0\0\0\0\0\0\0\0\0\0\0\0EffectLantern\0\0";
extern "C" char lbl_804F37E8[0x34] = "ObjCollect<EffectLantern>\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0CommicSign\0";
extern "C" char lbl_804F381C[0x30] = "ObjCollect<CommicSign>\0\0\0\0\0\0\0\0\0\0\0\0\0\0GameScript\0";
extern "C" char lbl_804F384C[0xD8] = "ObjCollect<GameScript>\0\0\0\0\0\0\0\0\0\0\0\0\0\0a2d_effect_slideblur.cpp\0\0\0\0jobjTbl_[EffectSlideBlurPoint_Front]\0\0\0\0jobjTbl_[EffectSlideBlurPoint_Rear]\0jobjTbl_[EffectSlideBlurPoint_Left]\0jobjTbl_[EffectSlideBlurPoint_Right]\0\0\0";

extern "C" char kar_srcfile_jobj_h_805dbdc8[] = "jobj.h";
extern "C" char lbl_805DBDD0[] = "jobj";
extern "C" char lbl_805DBDD8[] = "OBI_F*";
extern "C" char lbl_805DBDE0[] = "OBI_B*";
extern "C" char lbl_805DBDE8[] = "OBI_L*";
extern "C" char lbl_805DBDF0[] = "OBI_R*";

struct NamePair {
    char *a;
    char *b;
};

extern "C" char lbl_804F3924[] = "SlideBlur";
extern "C" char lbl_804F3930[] = "ObjCollect<SlideBlur>";
extern "C" NamePair lbl_805DBDF8 = {lbl_804F3930, 0};
extern "C" NamePair lbl_805DBE00 = {lbl_804F3924, 0};

class SlideBlurObj : public DiagObj {
public:
    void *unk4;
    void *unk8;
    void *unkC;
    s32 unk10;
    Vec3Result *unk14;
    u8 unk18;
    u8 unk19;
    u16 unk1A;
    u16 unk1C;
    u16 unk1E;
    u8 unk20, unk21, unk22, unk23;
    u8 unk24, unk25, unk26, unk27;
    u8 unk28, unk29, unk2A, unk2B;
    f32 unk2C, unk30, unk34;
    f32 unk38, unk3C, unk40;
    f32 unk44, unk48, unk4C;
    TargetObj *unk50;
    u8 unk54;
    u8 unk55;
    u8 pad56[2];
    f32 unk58, unk5C, unk60;
    f32 unk64, unk68, unk6C;
    f32 unk70, unk74, unk78;
    f32 unk7C, unk80, unk84;
    HSD_JObj *unk88;
    HSD_JObj *unk8C;
    HSD_JObj *unk90;
    HSD_JObj *unk94;
    f32 unk98;
};

extern "C" void EffectSlideBlurMgr_UpdateObject(SlideBlurObj *arg0);
extern "C" void EffectSlideBlurMgr_RenderObject(SlideBlurObj *arg0);
extern "C" f32 EffectSlideBlurMgr_CalculateTransform(SlideBlurObj *arg0, f32 *arg1, f32 *arg2, f32 *arg3);

typedef struct _GXTexObj {
    u32 dummy[8];
} GXTexObj;

static inline HSD_JObj *Jobj_EnsureMatrix(HSD_JObj *jobj) {
    ASSERT2(0x47C, jobj != NULL, kar_srcfile_jobj_h_805dbdc8, lbl_805DBDD0);
    if (jobj != NULL) {
        ASSERT2(0x25D, jobj != NULL, kar_srcfile_jobj_h_805dbdc8, lbl_805DBDD0);
        if (!(jobj->flags & 0x800000) && (jobj->flags & 0x40)) {
            HSD_JObjSetupMatrixSub(jobj);
        }
    }
    return jobj;
}

static inline HSD_JObj *Jobj_FetchWorld(const char *name) {
    return Jobj_EnsureMatrix((HSD_JObj *) fn_8038D0A8(name));
}

static inline Vec3Result ScaleGroup(f32 *v, f32 scale) {
    Vec3Result r;
    r.x = v[0];
    r.y = v[1];
    r.z = v[2];
    PSVECScale(&r.x, &r.x, scale);
    return r;
}


static inline f32 slideblur_sqrtf(f32 x) {
    volatile f32 y;
    if (x > 0.0f) {
        f64 guess = __frsqrte((f64) x);
        guess = 0.5 * guess * __fnmsub(x, guess * guess, 3.0);
        guess = 0.5 * guess * __fnmsub(x, guess * guess, 3.0);
        guess = 0.5 * guess * __fnmsub(x, guess * guess, 3.0);
        y = (f32) (x * guess);
        return y;
    }
    return x;
}

extern "C" SlideBlurObj *EffectSlideBlurMgr_CreateSlideBlur(SlideBlurObj *arg0, TargetObj *arg1, u8 arg2, u16 arg3, s32 arg4) {
    char *base = lbl_804F37A0;
    *(void **) arg0 = lbl_804BDE38;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    ((DiagObj *) arg0)->Init();
    *(void **) arg0 = lbl_804BDE78;
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    arg0->unk1A = 0;
    arg0->unk1C = 0;
    arg0->unk34 = 0.0f;
    arg0->unk30 = 0.0f;
    arg0->unk2C = 0.0f;
    arg0->unk40 = 0.0f;
    arg0->unk3C = 0.0f;
    arg0->unk38 = 0.0f;
    arg0->unk4C = 0.0f;
    arg0->unk48 = 0.0f;
    arg0->unk44 = 0.0f;
    arg0->unk50 = arg1;
    __construct_array((char *) arg0 + 0x58, &fn_802CD8DC, 0, 0xC, 4);
    arg0->unk54 = arg2;
    if (arg2 != 0) {
        arg0->unk28 = 0x64;
        arg0->unk29 = 0x64;
        arg0->unk2A = 0x64;
        arg0->unk2B = 0xFF;
        arg0->unk24 = 0;
        arg0->unk25 = 0;
        arg0->unk26 = 0;
        arg0->unk27 = 0;
    } else {
        arg0->unk28 = 0xA0;
        arg0->unk29 = 0xA0;
        arg0->unk2A = 0xA0;
        arg0->unk2B = 0xFF;
        arg0->unk24 = 0xFF;
        arg0->unk25 = 0xFF;
        arg0->unk26 = 0xFF;
        arg0->unk27 = 0;
    }
    if (arg3 != 0) {
        arg0->unk1E = arg3;
    } else {
        if (arg2 != 0) {
            arg0->unk1E = 0x26;
        }
        arg0->unk1E = 0x2A;
    }
    fn_80305ABC((char *) arg0 + 0xC, arg0->unk1E);
    arg0->unk98 = 0.0f;
    arg1->Prepare();
    arg0->unk88 = (HSD_JObj *) fn_8038D0A8(lbl_805DBDD8);
    ASSERT2(0x64, arg0->unk88 != NULL, base + 0xD0, base + 0xEC);
    arg1->Prepare();
    arg0->unk8C = (HSD_JObj *) fn_8038D0A8(lbl_805DBDE0);
    ASSERT2(0x66, arg0->unk8C != NULL, base + 0xD0, base + 0x114);
    arg1->Prepare();
    arg0->unk94 = (HSD_JObj *) fn_8038D0A8(lbl_805DBDE8);
    ASSERT2(0x68, arg0->unk94 != NULL, base + 0xD0, base + 0x138);
    arg1->Prepare();
    arg0->unk90 = (HSD_JObj *) fn_8038D0A8(lbl_805DBDF0);
    ASSERT2(0x6A, arg0->unk90 != NULL, base + 0xD0, base + 0x15C);

    f32 sp10 = 0.0f, spC = 0.0f, sp8 = 0.0f;
    arg1->Prepare();
    HSD_JObj *jobj0 = Jobj_FetchWorld(NULL);
    sp8 = jobj0->mtx[3];
    spC = jobj0->mtx[7];
    sp10 = jobj0->mtx[11];

    arg1->Prepare();
    HSD_JObj *jF = Jobj_FetchWorld(lbl_805DBDD8);
    arg0->unk58 = jF->mtx[3];
    arg0->unk5C = jF->mtx[7];
    arg0->unk60 = jF->mtx[11];

    arg1->Prepare();
    HSD_JObj *jB = Jobj_FetchWorld(lbl_805DBDE0);
    arg0->unk64 = jB->mtx[3];
    arg0->unk68 = jB->mtx[7];
    arg0->unk6C = jB->mtx[11];

    arg1->Prepare();
    HSD_JObj *jL = Jobj_FetchWorld(lbl_805DBDE8);
    arg0->unk7C = jL->mtx[3];
    arg0->unk80 = jL->mtx[7];
    arg0->unk84 = jL->mtx[11];

    arg1->Prepare();
    HSD_JObj *jR = Jobj_FetchWorld(lbl_805DBDF0);
    arg0->unk70 = jR->mtx[3];
    arg0->unk74 = jR->mtx[7];
    arg0->unk78 = jR->mtx[11];

    PSVECSubtract(&arg0->unk58, &sp8, &arg0->unk58);
    PSVECSubtract(&arg0->unk64, &sp8, &arg0->unk64);
    PSVECSubtract(&arg0->unk7C, &sp8, &arg0->unk7C);
    PSVECSubtract(&arg0->unk70, &sp8, &arg0->unk70);

    arg0->unk1C = 0;
    arg0->unk1A = 0;
    arg0->unk18 = 1;
    arg0->unk55 = 0;
    arg0->unk44 = 0.0f;
    arg0->unk38 = 0.0f;
    arg0->unk2C = 0.0f;
    arg0->unk48 = 0.0f;
    arg0->unk3C = 0.0f;
    arg0->unk30 = 0.0f;
    arg0->unk4C = 0.0f;
    arg0->unk40 = 0.0f;
    arg0->unk34 = 0.0f;
    return arg0;
}

extern "C" void EffectSlideBlurMgr_UpdateAllObjects(void) {
    SlideBlurObj *item = (SlideBlurObj *) kar_diag__803ad760(lbl_805DDA34, 0, &lbl_805DBE00, &lbl_805DBDF8, 0);
    while (item != NULL) {
        EffectSlideBlurMgr_UpdateObject(item);
        item = (SlideBlurObj *) item->GetNext();
    }
}

struct TexInfo {
    void *img;
    u16 w;
    u16 h;
    u32 fmt;
    u32 clamp;
};

extern "C" void EffectSlideBlurMgr_RenderAllObjects(void) {
    TexInfo *tex = (TexInfo *) kar_a2d_effecthandle__near_8037d0cc();
    GXTexObj texObj;
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_TEX_ST, GX_RGBA6, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_TEX_ST, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_RGBA6, 0);
    GXInvalidateVtxCache();
    GXSetCurrentMtx(GX_PNMTX0);
    GXLoadPosMtxImm((char *) HSD_CObjGetCurrent() + 0x54, GX_PNMTX0);
    GXInitTexObj(&texObj, tex->img, tex->w, tex->h, tex->fmt, GX_CLAMP, GX_CLAMP, tex->clamp);
    GXLoadTexObj(&texObj, GX_TEXMAP0);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x3C, GX_DISABLE, 0x7D);
    GXSetNumTexGens(1);
    GXSetChanCtrl(GX_COLOR0A0, GX_DISABLE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetNumTevStages(1);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_TEXA, GX_CA_RASA, GX_CA_ZERO);
    fn_803CECD0(0, 0, 0, 0, 1, 0);
    GXSetZMode(GX_ENABLE, GX_LESS, GX_DISABLE);
    SlideBlurObj *item = (SlideBlurObj *) kar_diag__803ad760(lbl_805DDA34, 0, &lbl_805DBE00, &lbl_805DBDF8, 0);
    while (item != NULL) {
        EffectSlideBlurMgr_RenderObject(item);
        item = (SlideBlurObj *) item->GetNext();
    }
    HSD_StateInvalidate(-1);
}

extern "C" f32 EffectSlideBlurMgr_CalculateTransform(SlideBlurObj *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    f32 center[3];
    center[0] = 0.0f;
    center[1] = 0.0f;
    center[2] = 0.0f;
    arg0->unk50->Prepare();
    HSD_JObj *jobj0 = Jobj_FetchWorld(NULL);
    center[0] = jobj0->mtx[3];
    center[1] = jobj0->mtx[7];
    center[2] = jobj0->mtx[11];

    Vec3Result *fwd = (Vec3Result *) arg0->unk50->GetVec7C();
    f32 fwdCopy[3];
    fwdCopy[0] = fwd->x;
    fwdCopy[1] = fwd->y;
    fwdCopy[2] = fwd->z;
    f32 side[3];
    side[0] = 0.0f;
    side[1] = 1.0f;
    side[2] = 0.0f;
    PSVECCrossProduct(side, fwdCopy, side, 0.0f, fwdCopy[2]);

    arg3[1] = 0.0f;
    f32 ax = arg3[0], az = arg3[2];
    f32 magSq = (ax * ax) + (az * az);
    magSq = slideblur_sqrtf(magSq);
    f32 invMag = 1.0f / magSq;
    arg3[0] *= invMag;
    arg3[2] = arg3[2] * invMag;
    f32 dotF = PSVECDotProduct(fwdCopy, arg3, invMag);
    f32 dotS = PSVECDotProduct(side, arg3, invMag);

    HSD_JObj *jF = Jobj_EnsureMatrix(arg0->unk88);
    arg0->unk58 = jF->mtx[3];
    arg0->unk5C = jF->mtx[7];
    arg0->unk60 = jF->mtx[11];

    HSD_JObj *jB = Jobj_EnsureMatrix(arg0->unk8C);
    arg0->unk64 = jB->mtx[3];
    arg0->unk68 = jB->mtx[7];
    arg0->unk6C = jB->mtx[11];

    HSD_JObj *jL = Jobj_EnsureMatrix(arg0->unk94);
    arg0->unk7C = jL->mtx[3];
    arg0->unk80 = jL->mtx[7];
    arg0->unk84 = jL->mtx[11];

    HSD_JObj *jR = Jobj_EnsureMatrix(arg0->unk90);
    arg0->unk70 = jR->mtx[3];
    arg0->unk74 = jR->mtx[7];
    arg0->unk78 = jR->mtx[11];

    f32 lenFB, lenLR;
    {
        f32 t[3] = {arg0->unk58, arg0->unk5C, arg0->unk60};
        PSVECSubtract(t, &arg0->unk64, t);
        lenFB = PSVECMag(t, t[1], t[2]);
    }
    {
        f32 t[3] = {arg0->unk7C, arg0->unk80, arg0->unk84};
        PSVECSubtract(t, &arg0->unk70, t);
        lenLR = PSVECMag(t, t[1], t[2]);
    }
    f32 absDotF = (dotF < 0.0f) ? -dotF : dotF;

    PSVECSubtract(&arg0->unk58, center, &arg0->unk58);
    PSVECSubtract(&arg0->unk64, center, &arg0->unk64);
    PSVECSubtract(&arg0->unk7C, center, &arg0->unk7C);
    PSVECSubtract(&arg0->unk70, center, &arg0->unk70);

    if (dotF > 0.0f) {
        if (dotS > 0.0f) {
            Vec3Result a = ScaleGroup(&arg0->unk64, dotS);
            Vec3Result b = ScaleGroup(&arg0->unk7C, dotF);
            PSVECAdd(&b.x, &a.x, &b.x);
            arg1[0] = b.x; arg1[1] = b.y; arg1[2] = b.z;

            Vec3Result c = ScaleGroup(&arg0->unk58, dotS);
            Vec3Result d = ScaleGroup(&arg0->unk70, dotF);
            PSVECAdd(&d.x, &c.x, &d.x);
            arg2[0] = d.x; arg2[1] = d.y; arg2[2] = d.z;
        } else {
            Vec3Result a = ScaleGroup(&arg0->unk58, dotS);
            Vec3Result b = ScaleGroup(&arg0->unk7C, dotF);
            PSVECSubtract(&b.x, &a.x, &b.x);
            arg1[0] = b.x; arg1[1] = b.y; arg1[2] = b.z;

            Vec3Result c = ScaleGroup(&arg0->unk64, dotS);
            Vec3Result d = ScaleGroup(&arg0->unk70, dotF);
            PSVECSubtract(&d.x, &c.x, &d.x);
            arg2[0] = d.x; arg2[1] = d.y; arg2[2] = d.z;
        }
    } else if (dotS > 0.0f) {
        Vec3Result a = ScaleGroup(&arg0->unk64, dotS);
        Vec3Result b = ScaleGroup(&arg0->unk70, dotF);
        Vec3Result nb;
        nb.x = -b.x; nb.y = -b.y; nb.z = -b.z;
        PSVECAdd(&nb.x, &a.x, &nb.x);
        arg1[0] = nb.x; arg1[1] = nb.y; arg1[2] = nb.z;

        Vec3Result c = ScaleGroup(&arg0->unk58, dotS);
        Vec3Result d = ScaleGroup(&arg0->unk7C, dotF);
        Vec3Result nd;
        nd.x = -d.x; nd.y = -d.y; nd.z = -d.z;
        PSVECAdd(&nd.x, &c.x, &nd.x);
        arg2[0] = nd.x; arg2[1] = nd.y; arg2[2] = nd.z;
    } else {
        Vec3Result a = ScaleGroup(&arg0->unk58, dotS);
        Vec3Result b = ScaleGroup(&arg0->unk70, dotF);
        Vec3Result nb;
        nb.x = -b.x; nb.y = -b.y; nb.z = -b.z;
        PSVECSubtract(&nb.x, &a.x, &nb.x);
        arg1[0] = nb.x; arg1[1] = nb.y; arg1[2] = nb.z;

        Vec3Result c = ScaleGroup(&arg0->unk64, dotS);
        Vec3Result d = ScaleGroup(&arg0->unk7C, dotF);
        Vec3Result nd;
        nd.x = -d.x; nd.y = -d.y; nd.z = -d.z;
        PSVECSubtract(&nd.x, &c.x, &nd.x);
        arg2[0] = nd.x; arg2[1] = nd.y; arg2[2] = nd.z;
    }

    void *velocity = arg0->unk50->GetVec74();
    PSVECAdd(arg1, velocity, arg1);
    velocity = arg0->unk50->GetVec74();
    PSVECAdd(arg2, velocity, arg2);
    return 1.0f - absDotF;
}

extern "C" void EffectSlideBlurMgr_UpdateObject(SlideBlurObj *arg0) {
    f32 var_f31 = 0.0f;
    TargetObj *target = arg0->unk50;
    if (target != NULL) {
        Vec3Result *v = (Vec3Result *) target->GetVec84();
        f32 vx = v->x, vy = v->y, vz = v->z;
        if (vx > 0.00001f || vz > 0.00001f) {
            f32 p2x = arg0->unk38, p2y = arg0->unk3C, p2z = arg0->unk40;
            f32 p1x = arg0->unk2C, p1y = arg0->unk30, p1z = arg0->unk34;
            var_f31 = EffectSlideBlurMgr_CalculateTransform(arg0, &arg0->unk2C, &arg0->unk38, &v->x);
            f32 d1[3] = {p2x, p2y, p2z};
            PSVECSubtract(d1, &arg0->unk38, d1);
            f32 m1 = PSVECMag(d1, d1[1], d1[2]);
            f32 d2[3] = {p1x, p1y, p1z};
            PSVECSubtract(d2, &arg0->unk2C, d2);
            f32 m2 = PSVECMag(d2, d2[1], d2[2]);
            if ((0.5f * (m2 + m1)) > 4.0f) {
                arg0->unk1C = 0;
            }
        }
        if (target->IsMoving() != 0) {
            arg0->unk98 = (0.1f * var_f31) + arg0->unk98;
            if (arg0->unk98 > 1.0f) {
                arg0->unk98 = 1.0f;
            }
        } else {
            if (arg0->unk54 != 0) {
                arg0->unk98 = arg0->unk98 - ((0.06f * (1.0f - var_f31)) + 0.02f);
            } else {
                arg0->unk98 = arg0->unk98 - ((0.03f * (1.0f - var_f31)) + 0.01f);
            }
            if (arg0->unk98 < 0.0f) {
                arg0->unk98 = 0.0f;
            }
        }
        Vec3Result *v2 = (Vec3Result *) target->GetVec84();
        f32 var_f1 = (PSVECMag(&v2->x, v2->y, v2->z) - 0.02f) / 0.099999994f;
        if (var_f1 > 1.0f) {
            var_f1 = 1.0f;
        } else if (var_f1 < 0.0f) {
            var_f1 = 0.0f;
        }
        goto block_20;
    }
    if (arg0->unk55 != 0) {
        f32 var_f2 = 1.0f;
block_20:
        f32 f2 = var_f2;
        if (arg0->unk54 != 0) {
            arg0->unk23 = (s8) (255.0f * (arg0->unk98 * f2));
            arg0->unk20 = arg0->unk28;
            arg0->unk21 = arg0->unk29;
            arg0->unk22 = arg0->unk2A;
        } else {
            f32 t3 = arg0->unk98 * f2;
            arg0->unk20 = (u8) (s32) -((t3 * (255.0f - (f32) arg0->unk28)) - 255.0f);
            arg0->unk21 = (u8) (s32) -((t3 * (255.0f - (f32) arg0->unk29)) - 255.0f);
            arg0->unk22 = (u8) (s32) -((t3 * (255.0f - (f32) arg0->unk2A)) - 255.0f);
        }
        Vec3Result *hist0 = &arg0->unk14[arg0->unk1A * 2];
        hist0->x = arg0->unk2C;
        hist0->y = arg0->unk30;
        hist0->z = arg0->unk34;
        Vec3Result *hist1 = &arg0->unk14[arg0->unk1A * 2 + 1];
        hist1->x = arg0->unk38;
        hist1->y = arg0->unk3C;
        hist1->z = arg0->unk40;
        u16 idx = arg0->unk1A + 1;
        arg0->unk1A = idx;
        if (idx >= (u32) arg0->unk10) {
            arg0->unk1A = 0;
        }
        u16 cnt = arg0->unk1C + 1;
        arg0->unk1C = cnt;
        if (cnt >= (u32) arg0->unk10) {
            arg0->unk1C = (u16) arg0->unk10;
        }
        for (u32 i = 0; i < (u16) arg0->unk1C; i++) {
            Vec3Result *hp0 = &arg0->unk14[i * 2];
            PSVECAdd(hp0, &arg0->unk44, hp0);
            Vec3Result *hp1 = &arg0->unk14[i * 2 + 1];
            PSVECAdd(hp1, &arg0->unk44, hp1);
        }
    }
}

extern "C" void EffectSlideBlurMgr_RenderObject(SlideBlurObj *arg0) {
    if (arg0->unk18 != 0 && (arg0->unk50 != NULL || arg0->unk55 != 0) && (u16) arg0->unk1C > 1) {
        if (arg0->unk54 != 0) {
            GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_RASC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
            fn_803CEC68(0, 0, 0, 0, 1, 0);
            GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
        } else {
            GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_RASC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
            fn_803CEC68(0, 1, 0, 0, 1, 0);
            GXSetBlendMode(GX_BM_SUBTRACT, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
        }
        GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT0, (arg0->unk1C * 2) & 0xFFFE);
        for (u32 i = 0; i < (u16) arg0->unk1C; i++) {
            u32 cap = arg0->unk10;
            s32 ring = (((arg0->unk1A + cap) - i) - 1) % cap;
            u32 count = arg0->unk1C;
            u32 thresh;
            if (arg0->unk54 != 0) {
                thresh = (u32) (0.1f * (f32) count);
            } else {
                thresh = (u32) (0.3f * (f32) count);
            }
            f32 t;
            if (i > thresh) {
                t = (f32) (i - thresh) / (f32) ((count - 1) - thresh);
            } else {
                t = 0.0f;
            }
            u8 color[4];
            kar_a2d_kurakko__near_80376c50(color, &arg0->unk20, &arg0->unk24, t);
            union { u32 w; u8 b[4]; } colorU;
            colorU.w = *(u32 *) color;
            Vec3Result *p0 = &arg0->unk14[ring * 2];
            GX_FIFO_F32 = p0->x;
            GX_FIFO_F32 = p0->y;
            GX_FIFO_F32 = p0->z;
            GX_FIFO_U8 = colorU.b[0];
            GX_FIFO_U8 = colorU.b[1];
            GX_FIFO_U8 = colorU.b[2];
            GX_FIFO_U8 = colorU.b[3];
            GX_FIFO_F32 = 0.0f;
            GX_FIFO_F32 = t;
            Vec3Result *p1 = p0 + 1;
            GX_FIFO_F32 = p1->x;
            GX_FIFO_F32 = p1->y;
            GX_FIFO_F32 = p1->z;
            GX_FIFO_U8 = colorU.b[0];
            GX_FIFO_U8 = colorU.b[1];
            GX_FIFO_U8 = colorU.b[2];
            GX_FIFO_U8 = colorU.b[3];
            GX_FIFO_F32 = 1.0f;
            GX_FIFO_F32 = t;
        }
    }
}

extern "C" char kar_src_a2d_commicsign_804f41f4[] = "a2d_commicsign.h";
extern "C" char lbl_805DBF6C[] = "jobj_";
extern "C" char lbl_804F41B4[] = "CommicSignContainer";
extern "C" char lbl_804F41C8[] = "Singleton<CommicSignContainer>";
extern "C" NamePair lbl_805DBF64 = {lbl_804F41C8, 0};
extern "C" NamePair lbl_805DBF5C = {lbl_804F41B4, 0};

extern "C" char lbl_804F3B64[] = "SphereBase";
extern "C" char lbl_804F3B7C[] = "CollSphere";
extern "C" NamePair lbl_805DBF38 = {lbl_804F3B7C, 0};
extern "C" NamePair lbl_805DBF30 = {lbl_804F3B64, 0};

extern "C" char kar_srcfile_jobj_h_805dbf74[] = "jobj.h";
extern "C" char lbl_805DBF7C[] = "jobj";

struct CommicSignInfo {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s32 unk10;
    f32 unk14;
};

extern "C" u8 lbl_804F40A0[0x114] = {
    0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0xa0, 0x00, 0x00,
    0x42, 0x20, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x2f, 0x2f, 0x2f, 0x20, 0x96, 0x9f, 0x95, 0x84, 0x8f, 0xee, 0x95, 0xf1, 0x0a, 0x00, 0x00, 0x00,
    0x73, 0x74, 0x61, 0x74, 0x69, 0x63, 0x20, 0x43, 0x6f, 0x6d, 0x6d, 0x69, 0x63, 0x53, 0x69, 0x67,
    0x6e, 0x49, 0x6e, 0x66, 0x6f, 0x20, 0x20, 0x20, 0x69, 0x6e, 0x66, 0x6f, 0x44, 0x65, 0x73, 0x63,
    0x20, 0x3d, 0x20, 0x7b, 0x0a, 0x00, 0x00, 0x00, 0x96, 0xb3, 0x8c, 0xf8, 0x81, 0x5e, 0x97, 0x4c,
    0x8c, 0xf8, 0x00, 0x00, 0x95, 0x5c, 0x8e, 0xa6, 0x83, 0x58, 0x83, 0x50, 0x81, 0x5b, 0x83, 0x8b,
    0x28, 0x8b, 0xc1, 0x82, 0xab, 0x29, 0x00, 0x00, 0x95, 0x5c, 0x8e, 0xa6, 0x82, 0x77, 0x83, 0x49,
    0x83, 0x74, 0x83, 0x5a, 0x83, 0x62, 0x83, 0x67, 0x28, 0x8b, 0xc1, 0x82, 0xab, 0x29, 0x5b, 0x64,
    0x6f, 0x74, 0x5d, 0x00, 0x95, 0x5c, 0x8e, 0xa6, 0x82, 0x78, 0x83, 0x49, 0x83, 0x74, 0x83, 0x5a,
    0x83, 0x62, 0x83, 0x67, 0x28, 0x8b, 0xc1, 0x82, 0xab, 0x29, 0x5b, 0x64, 0x6f, 0x74, 0x5d, 0x00,
    0x95, 0x5c, 0x8e, 0xa6, 0x83, 0x58, 0x83, 0x50, 0x81, 0x5b, 0x83, 0x8b, 0x28, 0x83, 0x8c, 0x83,
    0x6f, 0x83, 0x4b, 0x83, 0x60, 0x83, 0x83, 0x29, 0x00, 0x00, 0x00, 0x00, 0x95, 0x5c, 0x8e, 0xa6,
    0x82, 0x77, 0x83, 0x49, 0x83, 0x74, 0x83, 0x5a, 0x83, 0x62, 0x83, 0x67, 0x28, 0x83, 0x8c, 0x83,
    0x6f, 0x83, 0x4b, 0x83, 0x60, 0x83, 0x83, 0x29, 0x5b, 0x64, 0x6f, 0x74, 0x5d, 0x00, 0x00, 0x00,
    0x95, 0x5c, 0x8e, 0xa6, 0x82, 0x78, 0x83, 0x49, 0x83, 0x74, 0x83, 0x5a, 0x83, 0x62, 0x83, 0x67,
    0x28, 0x83, 0x8c, 0x83, 0x6f, 0x83, 0x4b, 0x83, 0x60, 0x83, 0x83, 0x29, 0x5b, 0x64, 0x6f, 0x74,
    0x5d, 0x00, 0x00, 0x00,
};

extern "C" void *kar_a2d_effect_slideblur__near_80381a44(void) {
    return &lbl_804F40A0;
}

extern "C" char lbl_804F39E0[] = "CommicSign";

extern "C" void kar_a2d_effect_slideblur__near_80381a50(CommicSignInfo *arg0) {
    char *base = lbl_804F39E0;
    OSReport(base + 0x6E0, base);
    OSReport(base + 0x6F0);
    OSReport("    ");
    OSReport("/// %s\n", base + 0x718);
    OSReport("    ");
    OSReport("%ff,\n", arg0->unk0);
    OSReport("    ");
    OSReport("/// %s\n", base + 0x724);
    OSReport("    ");
    OSReport("%ff,\n", arg0->unk4);
    OSReport("    ");
    OSReport("/// %s\n", base + 0x738);
    OSReport("    ");
    OSReport("%ff,\n", arg0->unk8);
    OSReport("    ");
    OSReport("/// %s\n", base + 0x754);
    OSReport("    ");
    OSReport("%ff,\n", arg0->unkC);
    OSReport("    ");
    OSReport("/// %s\n", base + 0x770);
    OSReport("    ");
    OSReport("%ff,\n", (f32) arg0->unk10);
    OSReport("    ");
    OSReport("/// %s\n", base + 0x78C);
    OSReport("    ");
    OSReport("%ff,\n", arg0->unk14);
    OSReport("};\n");
}

class CommicSignObj : public DiagObj {
public:
    void *unk4;
    void *unk8;
    s32 *unkC;
    HSD_JObj *unk10;
    s32 unk14;
    s32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    s32 unk28;
    s32 unk2C;
};

extern "C" void *kar_a2d_effect_slideblur__near_80381c60(CommicSignObj *arg0, s32 arg1) {
    *(void **) arg0 = lbl_804BD7B4;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    ((DiagObj *) arg0)->Init();
    *(void **) arg0 = lbl_804BD7DC;
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk2C = arg1;
    s32 *ptr = (s32 *) kar_diag__803ad760(lbl_805DDBDC, 0, &lbl_805DBF64, &lbl_805DBF5C, 0);
    ptr = (s32 *) ((CommicSignObj *) ptr)->unk4;
    if (ptr != NULL) {
        arg0->unkC = ptr;
        void *deref = *(void **) ptr;
        if (arg0->unk10 == NULL) {
            arg0->unk10 = (HSD_JObj *) HSD_JObjLoadJoint(deref);
            ASSERT2(0x48, arg0->unk10 != NULL, kar_src_a2d_commicsign_804f41f4, lbl_805DBF6C);
            HSD_JObjSetFlagsAll(arg0->unk10, 0x10);
        }
    }
    arg0->unk14 = 0;
    arg0->unk18 = 2;
    arg0->unk24 = 0.0f;
    arg0->unk20 = 0.0f;
    arg0->unk1C = 0.0f;
    arg0->unk28 = 0;
    return arg0;
}

extern "C" void kar_a2d_effect_slideblur__near_80381d6c(CommicSignObj *arg0, s32 arg1, u32 arg2) {
    u32 var_r29 = arg2;
    s32 slot = arg0->unk2C;
    void *base = kar_diag__803ad760(lbl_805DDB44, 0, &lbl_805DBF38, &lbl_805DBF30, 0);
    void *target = *(void **) ((char *) base + (slot * 4) + 8);
    if (*(s32 *) (*(void **) target) != 0) {
        if (arg1 == 0 && var_r29 == 0xFFFF0000U) {
            var_r29 = (u32) ((CommicSignInfo *) lbl_804F40A0)->unk10;
        }
        if (arg0->unk14 == 0) {
            arg0->unk14 = 1;
            arg0->unk18 = arg1;
            arg0->unk28 = var_r29;
            if (arg0->unkC != 0 && arg0->unk10 != 0) {
                kar_a2d_game_lib__802894bc(0, 0, arg1);
            }
            if (arg1 == 1) {
                HSD_ForeachAnim(arg0->unk10, 6, 0xFFFF, &HSD_AObjSetFlags, 3, 0x20000000);
            } else {
                HSD_ForeachAnim(arg0->unk10, 6, 0xFFFF, &HSD_AObjClearFlags, 3, 0x20000000);
            }
            HSD_JObjClearFlagsAll(arg0->unk10, 0x10);
            HSD_JObjReqAnimAll(arg0->unk10, 0.0f);
            return;
        }
        if (arg0->unk18 != arg1) {
            arg0->unk18 = arg1;
            arg0->unk28 = var_r29;
            if (arg0->unkC != 0 && arg0->unk10 != 0) {
                kar_a2d_game_lib__802894bc(0, 0, arg1);
            }
            if (arg1 == 1) {
                HSD_ForeachAnim(arg0->unk10, 6, 0xFFFF, &HSD_AObjSetFlags, 3, 0x20000000);
            } else {
                HSD_ForeachAnim(arg0->unk10, 6, 0xFFFF, &HSD_AObjClearFlags, 3, 0x20000000);
            }
            HSD_JObjClearFlagsAll(arg0->unk10, 0x10);
            HSD_JObjReqAnimAll(arg0->unk10, 0.0f);
        }
    }
}

extern "C" void kar_a2d_effect_slideblur__near_80381f78(CommicSignObj *arg0) {
    if (arg0->unk14 != 0) {
        HSD_JObjAnimAll(arg0->unk10);
        s32 slot = arg0->unk2C;
        void *base = kar_diag__803ad760(lbl_805DDB44, 0, &lbl_805DBF38, &lbl_805DBF30, 0);
        void *target = *(void **) ((char *) base + (slot * 4) + 8);
        s32 spC, sp8;
        (*(void (**)(void *, s32 *, s32 *)) ((char *) *(void **) target + 0x128))(target, &spC, &sp8);
        f32 var_f29, var_f30, var_f31;
        switch (arg0->unk18) {
        case 0:
            var_f31 = ((CommicSignInfo *) lbl_804F40A0)->unk4;
            var_f30 = ((CommicSignInfo *) lbl_804F40A0)->unk8;
            var_f29 = ((CommicSignInfo *) lbl_804F40A0)->unkC;
            break;
        case 1:
            var_f31 = ((CommicSignInfo *) lbl_804F40A0)->unk14;
            var_f30 = 0.0f;
            var_f29 = 0.0f;
            break;
        default:
            var_f29 = 0.0f;
            var_f31 = 1.0f;
            var_f30 = 0.0f;
            break;
        }
        HSD_JObj *jobj = arg0->unk10;
        ASSERT2(0x3B8, jobj != NULL, kar_srcfile_jobj_h_805dbf74, lbl_805DBF7C);
        jobj->translate[0] = (((f32) spC - 320.0f) + var_f30) / 100.0f;
        if (!(jobj->flags & 0x02000000)) {
            ASSERT2(0x25D, jobj != NULL, kar_srcfile_jobj_h_805dbf74, lbl_805DBF7C);
            if (!(jobj->flags & 0x800000) && (jobj->flags & 0x40)) {
            } else {
                HSD_JObjSetMtxDirtySub(jobj);
            }
        }
        jobj = arg0->unk10;
        ASSERT2(0x3C6, jobj != NULL, kar_srcfile_jobj_h_805dbf74, lbl_805DBF7C);
        jobj->translate[1] = -(((f32) sp8 - 240.0f) - var_f29) / 100.0f;
        if (!(jobj->flags & 0x02000000)) {
            ASSERT2(0x25D, jobj != NULL, kar_srcfile_jobj_h_805dbf74, lbl_805DBF7C);
            if (!(jobj->flags & 0x800000) && (jobj->flags & 0x40)) {
            } else {
                HSD_JObjSetMtxDirtySub(jobj);
            }
        }
        jobj = arg0->unk10;
        ASSERT2(0x3D4, jobj != NULL, kar_srcfile_jobj_h_805dbf74, lbl_805DBF7C);
        jobj->translate[2] = 0.0f;
        if (!(jobj->flags & 0x02000000)) {
            ASSERT2(0x25D, jobj != NULL, kar_srcfile_jobj_h_805dbf74, lbl_805DBF7C);
            if (!(jobj->flags & 0x800000) && (jobj->flags & 0x40)) {
            } else {
                HSD_JObjSetMtxDirtySub(jobj);
            }
        }
        jobj = arg0->unk10;
        ASSERT2(0x325, jobj != NULL, kar_srcfile_jobj_h_805dbf74, lbl_805DBF7C);
        jobj->scale[0] = var_f31;
        if (!(jobj->flags & 0x02000000)) {
            ASSERT2(0x25D, jobj != NULL, kar_srcfile_jobj_h_805dbf74, lbl_805DBF7C);
            if (!(jobj->flags & 0x800000) && (jobj->flags & 0x40)) {
            } else {
                HSD_JObjSetMtxDirtySub(jobj);
            }
        }
        jobj = arg0->unk10;
        ASSERT2(0x333, jobj != NULL, kar_srcfile_jobj_h_805dbf74, lbl_805DBF7C);
        jobj->scale[1] = var_f31;
        if (!(jobj->flags & 0x02000000)) {
            ASSERT2(0x25D, jobj != NULL, kar_srcfile_jobj_h_805dbf74, lbl_805DBF7C);
            if (!(jobj->flags & 0x800000) && (jobj->flags & 0x40)) {
            } else {
                HSD_JObjSetMtxDirtySub(jobj);
            }
        }
        if (arg0->unk28 != 0) {
            arg0->unk28 -= 1;
            if (arg0->unk28 == 0) {
                HSD_JObjSetFlagsAll(arg0->unk10, 0x10);
                arg0->unk14 = 0;
                arg0->unk18 = 2;
                arg0->unk24 = 0.0f;
                arg0->unk20 = 0.0f;
                arg0->unk1C = 0.0f;
                arg0->unk28 = 0;
            }
        }
    }
}

struct ScriptOpEntry {
    u8 op;
    u8 pad[3];
    s32 arg;
};

class ScriptQueueObj : public DiagObj {
public:
    virtual void v28(s32);
    char pad4[8];
    ScriptOpEntry *unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 unk20;
    u8 unk21;
};

extern "C" void kar_a2d_effect_slideblur__near_80382380(ScriptQueueObj *arg0) {
    if (arg0->unkC != 0 && arg0->unk20 == 0) {
        if (arg0->unk14 != 0) {
            arg0->unk14 -= 1;
        } else {
            while (arg0->unkC != 0 && arg0->unk14 == 0) {
                s32 idx = arg0->unk10;
                ScriptOpEntry *entry = &arg0->unkC[idx];
                switch (entry->op) {
                case 1:
                    arg0->unk14 = entry->arg;
                    break;
                case 2:
                    arg0->unk18 = idx;
                    break;
                case 3:
                    if (arg0->unk21 == 0) {
                        if (entry->arg > 0) {
                            arg0->unk1C = entry->arg - 1;
                        } else {
                            arg0->unk1C = -1;
                        }
                        arg0->unk21 = 1;
                    }
                    {
                        s32 cnt = arg0->unk1C;
                        if (cnt >= 0) {
                            arg0->unk1C = cnt - 1;
                            if (cnt == 0) {
                                arg0->unk21 = 0;
                                goto skip_80382380;
                            }
                        }
                        arg0->unk10 = arg0->unk18;
                    skip_80382380:;
                    }
                    break;
                case 4:
                    arg0->v28(entry->arg);
                    break;
                case 5:
                    arg0->unkC = 0;
                    break;
                default:
                    break;
                }
                arg0->unk10 += 1;
            }
        }
    }
}

extern char lbl_804F4280[0x38];

extern "C" CommicSignObj *kar_a2d_effect_slideblur__near_803824ec(CommicSignObj *arg0) {
    lbl_805DDC78 = arg0;
    arg0->unk4 = HSD_CObjLoadDesc(&lbl_804F4280);
    arg0->unk18 = 0;
    arg0->unk28 = 0;
    arg0->unk14 = kar_a2d_game_lib__near_8028b11c(0x280, 0x1E0);
    memset((char *) arg0 + 0x20, 0, 0x18);
    kar_a2d_game_lib__near_8028b050((char *) arg0 + 0x20, 0x80, 0x80, 5);
    return arg0;
}

struct ColorRGBA {
    u8 r, g, b, a;
};

class ColorFadeObj {
public:
    void *unk0;
    u8 unk4, unk5, unk6, unk7;
    u8 unk8, unk9, unkA, unkB;
    s8 unkC, unkD, unkE, unkF;
    f32 unk10;
    f32 unk14;
    u8 unk18;
    u8 unk19;
    char pad1A[0x1E];
    ScriptOpEntry *unk38;
    u16 unk3C;
    u8 unk3E;
    u8 unk3F;
};

extern "C" void kar_a2d_effect_slideblur__near_80382b44(ColorFadeObj *arg0, ColorRGBA *arg1, ColorRGBA *arg2, u32 arg3, u8 arg4);

extern "C" void kar_a2d_effect_slideblur__near_8038256c(ColorFadeObj *arg0) {
    ScriptOpEntry *queue = arg0->unk38;
    if (queue != NULL) {
        if (arg0->unk3E != 0) {
            arg0->unk3E -= 1;
            return;
        }
        u16 idx = arg0->unk3C;
        u8 *entry = (u8 *) queue + (idx * 6);
        switch (entry[0]) {
        case 0:
            arg0->unk3C = idx + 1;
            return;
        case 1:
            arg0->unk3E = entry[1];
            arg0->unk3C = arg0->unk3C + 1;
            return;
        case 2: {
            ColorRGBA target;
            target.r = entry[1];
            target.g = entry[2];
            target.b = entry[3];
            target.a = entry[4];
            ColorRGBA current;
            *(u32 *) &current = *(u32 *) &arg0->unkC;
            kar_a2d_effect_slideblur__near_80382b44(arg0, &current, &target, 1, entry[5]);
            arg0->unk3C = arg0->unk3C + 1;
            return;
        }
        case 3:
            arg0->unkC = entry[1];
            arg0->unkD = entry[2];
            arg0->unkE = entry[3];
            arg0->unkF = entry[4];
            arg0->unk4 = (u8) arg0->unkC;
            arg0->unk5 = (u8) arg0->unkD;
            arg0->unk6 = (u8) arg0->unkE;
            arg0->unk7 = (u8) arg0->unkF;
            arg0->unk3C = arg0->unk3C + 1;
            return;
        case 4:
            arg0->unk38 = 0;
            if (arg0->unk3F == 0) {
                arg0->unk18 = 0;
            }
            break;
        default:
            break;
        }
    }
}

extern "C" void kar_a2d_effect_slideblur__near_803826e4(ColorFadeObj *arg0) {
    kar_a2d_effect_slideblur__near_8038256c(arg0);
    if (arg0->unk18 != 0) {
        f32 t = arg0->unk14;
        if (t >= 1.0f) {
            arg0->unk14 = 1.0f;
        } else if (t < 0.0f) {
            arg0->unk14 = 0.0f;
        }
        u8 c1r = arg0->unk4, c1g = arg0->unk5, c1b = arg0->unk6, c1a = arg0->unk7;
        t = arg0->unk14;
        arg0->unkC = (s8) ((t * ((f32) arg0->unk8 - (f32) c1r)) + (f32) c1r);
        arg0->unkD = (s8) ((t * ((f32) arg0->unk9 - (f32) c1g)) + (f32) c1g);
        arg0->unkE = (s8) ((t * ((f32) arg0->unkA - (f32) c1b)) + (f32) c1b);
        arg0->unkF = (s8) ((t * ((f32) arg0->unkB - (f32) c1a)) + (f32) c1a);
        arg0->unk14 = arg0->unk14 + arg0->unk10;
    }
}

struct ScreenRect {
    f32 xMin, xMax, yMin, yMax;
};

extern "C" ScreenRect lbl_8048B3F8;

extern "C" void kar_a2d_effect_slideblur__near_803828a4(ColorFadeObj *arg0) {
    if (arg0->unk18 != 0 && HSD_CObjSetCurrent(arg0->unk0)) {
        s32 colorWord = *(s32 *) &arg0->unkC;
        u8 *colorBytes = (u8 *) &colorWord;
        f32 xMin = lbl_8048B3F8.xMin;
        f32 xMax = lbl_8048B3F8.xMax;
        f32 yMin = lbl_8048B3F8.yMin;
        f32 yMax = lbl_8048B3F8.yMax;
        if (arg0->unkF != 0) {
            f32 width = xMax - xMin;
            f32 widthRatio = width / 640.0f;
            f32 height = yMax - yMin;
            f32 heightRatio = height / 480.0f;
            s32 x0 = (s32) ((0.0f * widthRatio) + xMin);
            s32 y0 = (s32) ((0.0f * heightRatio) + yMin);
            kar_pslist__near_80438c50(1, 1.0f, 1.0f, width, xMin, yMin);
            GXSetZMode(GX_DISABLE, GX_ALWAYS, GX_DISABLE);
            GXBegin(GX_QUADS, GX_VTXFMT0, 4);
            s32 negY0 = -y0;
            s32 x1 = x0 + (s32) (640.0f * widthRatio);
            GX_FIFO_F32 = (f32) x0;
            GX_FIFO_F32 = (f32) negY0;
            GX_FIFO_U8 = (u8) colorWord;
            GX_FIFO_U8 = colorBytes[1];
            GX_FIFO_U8 = colorBytes[2];
            GX_FIFO_U8 = colorBytes[3];
            s32 negY1 = -(y0 + (s32) (480.0f * heightRatio));
            GX_FIFO_F32 = (f32) x1;
            GX_FIFO_F32 = (f32) negY0;
            GX_FIFO_U8 = (u8) colorWord;
            GX_FIFO_U8 = colorBytes[1];
            GX_FIFO_U8 = colorBytes[2];
            GX_FIFO_U8 = colorBytes[3];
            GX_FIFO_F32 = (f32) x1;
            GX_FIFO_F32 = (f32) negY1;
            GX_FIFO_U8 = (u8) colorWord;
            GX_FIFO_U8 = colorBytes[1];
            GX_FIFO_U8 = colorBytes[2];
            GX_FIFO_U8 = colorBytes[3];
            GX_FIFO_F32 = (f32) x0;
            GX_FIFO_F32 = (f32) negY1;
            GX_FIFO_U8 = (u8) colorWord;
            GX_FIFO_U8 = colorBytes[1];
            GX_FIFO_U8 = colorBytes[2];
            GX_FIFO_U8 = colorBytes[3];
        }
        if (arg0->unk14 >= 1.0f && arg0->unk19 == 0) {
            arg0->unk18 = 0;
        }
        HSD_CObjEndCurrent();
    }
}

extern "C" void kar_a2d_effect_slideblur__near_80382b44(ColorFadeObj *arg0, ColorRGBA *arg1, ColorRGBA *arg2, u32 arg3, u8 arg4) {
    arg0->unk4 = arg1->r;
    arg0->unk5 = arg1->g;
    arg0->unk6 = arg1->b;
    arg0->unk7 = arg1->a;
    arg0->unk8 = arg2->r;
    arg0->unk9 = arg2->g;
    arg0->unkA = arg2->b;
    arg0->unkB = arg2->a;
    arg0->unk10 = 1.0f / (f32) arg3;
    arg0->unk14 = 0.0f;
    arg0->unk18 = 1;
    arg0->unk19 = arg4;
}

extern "C" void kar_a2d_effect_slideblur__near_80382bc8(ColorFadeObj *arg0, s32 arg1, s8 arg2) {
    arg0->unk18 = 0;
    arg0->unk3E = 0;
    arg0->unk3C = 0;
    arg0->unk38 = (ScriptOpEntry *) arg1;
    arg0->unk3F = arg2;
    arg0->unkC = 0;
    arg0->unkD = 0;
    arg0->unkE = 0;
    arg0->unkF = 0;
}

extern "C" s32 lbl_804F4398[7][2] = {
    {1, 0},
    {2, 0},
    {3, 0},
    {4, 0},
    {5, 0},
    {6, 0},
    {7, 0},
};

extern "C" s32 kar_a2d_effect_slideblur__near_80382bf4(s32 *arg0, s32 arg1, s8 arg2) {
    s32 found;
    s32 i;
    for (i = 0; i < 7; i++) {
        if (arg1 == lbl_804F4398[i][0]) {
            found = lbl_804F4398[i][1];
            goto found_it;
        }
    }
    found = 0;
found_it:
    if (found != 0 && lbl_805DDC78 != NULL) {
        ColorFadeObj *obj = (ColorFadeObj *) lbl_805DDC78;
        obj->unk18 = 0;
        obj->unk3E = 0;
        obj->unk3C = 0;
        obj->unk38 = (ScriptOpEntry *) found;
        obj->unk3F = arg2;
        obj->unkC = 0;
        obj->unkD = 0;
        obj->unkE = 0;
        obj->unkF = 0;
        *arg0 = arg1;
        return 1;
    }
    return 0;
}

extern "C" void kar_a2d_effect_slideblur__near_80382c8c(void) {
    (*(void (**)(void *)) ((char *) hsdJObj + 0x48))(hsdJObj);
}

extern "C" char lbl_804F43D0[] = "GameScript";
extern "C" char lbl_804F43DC[0x240];

extern "C" void kar_a2d_effect_slideblur__near_80382cbc(void) {
    char *base = lbl_804F43D0;
    hsdInitClassInfo(base + 0x30, hsdJObj, base + 0x16C, base + 0x184, 0x54, 0x88);
    *(void **) (base + 0x30 + 0x48) = (void *) kar_a2d_effect_slideblur__near_80382c8c;
}

extern "C" u8 kar_a2d_effect_slideblur__near_80382d18(s32 arg0, ScriptOpEntry *arg1, ScriptOpEntry *arg2, ScriptOpEntry *arg3) {
    u8 sp[8];
    for (s32 i = 0; i < 8; i++) sp[i] = 0;
    while (arg2 != NULL) {
        if (arg2->pad[2] < 8) {
            sp[arg2->pad[2]] = 1;
        }
        arg2 = *(ScriptOpEntry **) arg2;
    }
    while (arg1 != NULL) {
        s32 v = arg1->arg;
        arg1 = *(ScriptOpEntry **) arg1;
        sp[v] = 1;
    }
    while (arg3 != NULL) {
        if (arg3->pad[2] < 8) {
            sp[arg3->pad[2]] = 1;
        }
        arg3 = *(ScriptOpEntry **) arg3;
    }
    for (s32 i = arg0; i < 7; i++) {
        if (sp[i] == 0) {
            return (u8) i;
        }
    }
    return (u8) -1;
}
