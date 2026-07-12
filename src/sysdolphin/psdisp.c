#include <global.h>
#include <sysdolphin/psdisp.h>
#include <sysdolphin/memory.h>
#include <sysdolphin/lobj.h>
#include <sysdolphin/util.h>
#include <sysdolphin/mtx.h>
#include <sysdolphin/fog.h>

void memset(void*, int, int);
void memcpy(void*, const void*, int);

#define GX_TF_I4 0
#define GX_TF_CI4 8
#define GX_TF_CI8 9
#define GX_TF_CMPR 14
#define GX_MIRROR 2
#define GX_REPEAT 1
#define GX_AF_SPEC 0
#define GX_AF_SPOT 1
#define GX_AF_NONE 2
#define GX_DF_NONE 0
#define GX_SRC_REG 0
#define GX_SRC_VTX 1
#define GX_LIGHT_NULL 0
#define GX_CULL_BACK 2
#define GX_TEX_ST 0
#define GX_RGB565 3
#define GX_RGBA6 5
#define GX_RGBA8 6
#define GX_PNMTX0 0
#define GX_PNMTX1 3
#define GX_TEVREG0 1
#define GX_TEVREG1 2
#define GX_TEVREG2 3
#define GX_BM_BLEND 1
#define GX_BM_SUBTRACT 2
#define GX_BL_SRCALPHA 4
#define GX_BL_INVSRCALPHA 5
#define GX_BL_ONE 1
#define GX_BL_ZERO 0
#define GX_BL_DSTCLR 3
#define GX_LO_CLEAR 0
#define GX_CLAMP 0
#define GX_COLOR0 0
#define GX_ALPHA0 2
#define GX_COLOR0A0 4
#define GX_COLOR1A1 5
#define GX_ENABLE 1
#define GX_DISABLE 0
#define GX_LEQUAL 3
#define GX_TEXCOORD0 0
#define GX_TG_MTX2x4 1
#define GX_TG_TEX0 4
#define GX_POINTS 0xB8

typedef struct {
    u8 pad[0x20];
} GXTexObj;

extern void kar_pslist__near_8043845c(s32 bank, void** opaHead, void** xluHead);

extern void HSD_StateInvalidate(s32 mask);
extern void OSReport(const char* fmt, ...);
extern HSD_CObj* HSD_CObjGetCurrent(void);
extern void HSD_CObjGetViewingMtx(HSD_CObj* cobj, Mtx out);
extern void fn_803D1578(Mtx viewMtx, f32* out);
extern void fn_803D06DC(f32* ptr);
extern void GXEnableTexOffsets(u8 chan, u32 x, u32 y);
extern void GXSetCullMode(u32 mode);
extern void GXSetArray(u32 attr, void* data, u32 stride);
extern void GXSetVtxAttrFmt(u32 vtxfmt, u32 attr, u32 cnt, u32 type, u32 frac);
extern void GXSetBlendMode(u32 type, u32 src, u32 dst, u32 op);
extern void GXSetChanCtrl(u32 chan, u32 enable, u32 amb_src, u32 mat_src, u32 light_mask,
                          u32 diff_fn, u32 attn_fn);
extern void GXSetZMode(u32 compare_enable, u32 func, u32 update_enable);
extern void GXInitTlutObj(void* tlutObj, void* lut, u32 fmt, u16 nEntries);
extern void GXLoadTlut(void* tlutObj, u32 tlutName);
extern void GXInitTexObjCI(GXTexObj* obj, void* img, u16 w, u16 h, u32 fmt, u32 wrapS, u32 wrapT,
                           u8 tlutName);
extern void GXInitTexObj(GXTexObj* obj, void* img, u16 w, u16 h, u32 fmt, u32 wrapS, u32 wrapT,
                         u8 mipmap);
extern void GXLoadTexObj(GXTexObj* obj, u32 texmap);
extern void fn_803CDA90(GXTexObj* obj, s32 minFilt, s32 magFilt, s32 a, s32 b, s32 c, f32 x, f32 y,
                        f32 z);
extern void GXLoadTexMtxImm(Mtx mtx, u32 texmtx, u32 type);
extern void GXSetTexCoordGen2(u32 dst, u32 func, u32 src, u32 mtx, u32 normalize, u32 postmtx);
extern void GXLoadPosMtxImm(Mtx mtx, u32 id);
extern void GXSetCurrentMtx(u32 id);
extern void GXSetTevColor(u32 reg, GXColor* color);
extern void GXSetZCompLoc(u32 before_tex);
extern void GXSetAlphaCompare(u32 comp0, u8 ref0, u32 op, u32 comp1, u8 ref1);
extern void GXSetNumChans(u8 n);
extern void GXClearVtxDesc(void);
extern void GXSetVtxDesc(u32 attr, u32 type);
extern void GXBegin(u8 prim, u8 vtxfmt, u16 nverts);
extern void GXSetPointSize(u8 size, u32 tex_offsets);
extern void fn_803D19AC(Mtx out, HSD_psAppSRT* srt, f32 sx, f32 sy, f32 sz);

extern void* lbl_8058C408[64];
extern void* lbl_8058C508[64];
extern f32 lbl_805DC8C0;
extern s8 lbl_805DCDEC;
extern HSD_Fog* lbl_805DE390;
extern u32 lbl_805DE3AC;
extern s32 lbl_805DE3B0;
extern u8 lbl_805DCDE8;
extern s32 lbl_805DE3D0;
extern s32 lbl_805DE3CC;
extern s32 lbl_805DE394;
extern f32 lbl_805E5FA0;
extern f32 lbl_805E5FC0;
extern GXColor lbl_805DE398;
extern GXColor lbl_805DE39C;
extern GXColor lbl_805DE3A0;
extern GXColor lbl_805DE3A4;
extern GXColor lbl_805DE3A8;
extern void kar_grcoll__803cd2b8(s32 chan, GXColor* color);
extern void kar_grcoll__803cd3ac(s32 chan, GXColor* color);

static const Mtx lbl_8048C570 = { { 1.0F, 0.0F, 0.0F, 0.0F },
                                   { 0.0F, 1.0F, 0.0F, 0.0F },
                                   { 0.0F, 0.0F, 1.0F, 0.0F } };

static const u16 lbl_ps_texidx_tbl[16] = { 0x0001, 0x0000, 0x0100, 0x0101, 0x0101, 0x0101, 0x0000,
                                           0x0001, 0x0000, 0x0001, 0x0101, 0x0100, 0x0100, 0x0101,
                                           0x0001, 0x0000 };

extern void kar_psdisp__near_804373dc(void);
extern void kar_psdisp__near_8043750c(void);
extern void kar_psdisp__near_80437518(HSD_Particle* pp);
extern void kar_psdisp__near_80437168(HSD_Particle* pp);
extern void kar_psdisp__near_80436d4c(HSD_Particle* pp);
extern void* kar_psdisp__near_80436460(HSD_Particle* pp);
extern void kar_psdisp__near_80436774(HSD_Particle* pp);
extern void kar_psdisp__near_80434d84(HSD_Particle* pp, u32* cmdList);
extern void kar_psdisp__near_80435c0c(HSD_Particle* pp, u32* cmdList);

static u16 lbl_805DE35C;
static u16 lbl_805DE360;
static u16 lbl_805DE362;
static u16 lbl_805DE366;
static u16 lbl_805DE3E0;
static HSD_psAppSRT* lbl_805DE3E4;

static struct {
    void* head;
    u32 pad4;
} lbl_805DE3E8;

static void* lbl_8058CCE8[32];
static u32 lbl_8058CD68[64];

#define GX_DIRECT 1
#define GX_INDEX8 2
#define GX_LINES 0xA8
#define GX_VTXFMT2 2
#define GX_VTXFMT3 3
#define GX_PNMTX0 0

#define GX_FIFO_U8 (*(volatile u8*) 0xCC008000)
#define GX_FIFO_F32 (*(volatile f32*) 0xCC008000)

extern void GXSetCurrentMtx(u32 id);
extern void GXSetLineWidth(u8 width, u32 tex_offsets);
extern void GXClearVtxDesc(void);
extern void GXSetVtxDesc(u32 attr, u32 type);
extern void GXBegin(u8 prim, u8 vtxfmt, u16 nverts);

extern s32 lbl_805DE394;
extern s32 lbl_805DE3CC;
extern f32 lbl_805E5FA0;
extern f32 lbl_805E5FC0;

#define GX_VTXFMT0 0
#define GX_VTXFMT1 1

extern void kar_generator__near_804333d4(HSD_Particle* pp, f32* dx, f32* dy, f32* dz);
extern void kar_generator__near_80433e54(HSD_Particle* pp, f32* dx, f32* dy, f32* dz);

extern f32 lbl_805DC8B8[];
extern f32 lbl_805DE3B4;
extern f32 lbl_805DE3B8;
extern f32 lbl_805DE3BC;
extern f32 lbl_805DE3C0;
extern f32 lbl_805DE3C4;
extern f32 lbl_805DE3C8;

static struct {
    u8 pad00[0xC];
    f32 unk0C;
    u8 pad10[0xC];
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    u8 pad34[0x4C - 0x34];
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    f32 unk64;
    f32 unk68;
    u8 pad6C[0x7C - 0x6C];
    Mtx cam;
} lbl_8058CC08;

typedef f32 Mtx9[3][3];

extern f64 __frsqrte(f64 x);
extern void kar_grcoll__near_803d1908(Mtx9 out, Vec* axis, f32 angle);
extern void fn_803D19AC(Mtx out, HSD_psAppSRT* srt, f32 sx, f32 sy, f32 sz);
extern void PSMTXConcat(Mtx a, Mtx b, Mtx ab);
extern void PSMTXCopy(Mtx src, Mtx dst);
extern void PSMTXMultVec(Mtx mtx, Vec* src, Vec* dst);

static struct {
    Mtx m;
    u32 unk30;
} lbl_8058CCB4;

static inline f32 psdisp_sqrtf(f32 x)
{
    volatile f32 y;

    if (x > 0.0F) {
        f64 guess = __frsqrte((f64) x);
        guess = 0.5 * guess * -(((f64) x * (guess * guess)) - 3.0);
        guess = 0.5 * guess * -(((f64) x * (guess * guess)) - 3.0);
        guess = 0.5 * guess * -(((f64) x * (guess * guess)) - 3.0);
        y = (f32) ((f64) x * guess);
        return y;
    }
    return x;
}

#define GX_QUADS 0x80
#define GX_VTXFMT4 4
#define GX_VTXFMT5 5

typedef struct {
    u8 kind;
    u8 count;
} TrailStripHdr;

void kar_psdisp__80433f00(s32 bankMask, s32 kind)
{
    s32 i;
    void* opaHead;
    void* xluHead;
    HSD_Particle* pp;
    s32 prevKind;
    s32 first;
    s32 alphaCache;
    u8 alphaRefA;
    u8 alphaRefB;

    if (kind == 0) {
        u8 n = 1;
        if (lbl_805DCDE8 < 0xFF) {
            n = (u8) (lbl_805DCDE8 + 1);
        }
        lbl_805DCDE8 = n;
        return;
    }

    prevKind = 0;
    alphaCache = 0;
    alphaRefA = 0;
    alphaRefB = 0xFF;
    first = 1;

    for (i = 0; i < 32; i++) {
        if (bankMask & (1 << i)) {
            kar_pslist__near_8043845c(i, &opaHead, &xluHead);

            switch (kind) {
            case 1:
                pp = (HSD_Particle*) opaHead;
                break;
            case 2:
                pp = (HSD_Particle*) xluHead;
                break;
            default:
                pp = NULL;
                break;
            }

            while (pp != NULL) {
                if (kind != 1 || (pp->kind & 8)) {
                    if (!(pp->size < lbl_805DC8C0)) {
                        s32 blendMode;
                        u32 lightMode;
                        u32 zMode;
                        u32* cmdList;

                        if (first) {
                            GXColor c;

                            lbl_805DE3D0 = -1;
                            lbl_805DE3CC = -1;
                            lbl_805DE3AC = -1U;
                            kar_psdisp__near_8043750c();
                            prevKind &= 0xFEFFFFFF;
                            alphaCache = -1;
                            HSD_FogSet(NULL);

                            c.r = 0xFF;
                            c.g = 0xFF;
                            c.b = 0xFF;
                            c.a = 0xFF;
                            lbl_805DE3A8 = c;
                            kar_grcoll__803cd3ac(4, &lbl_805DE3A8);
                            lbl_805DE3A4 = c;
                            kar_grcoll__803cd2b8(4, &lbl_805DE3A4);

                            kar_psdisp__near_8043750c();
                            kar_psdisp__near_804373dc();

                            lbl_805DE3A0.r = 0xFF;
                            lbl_805DE3A0.g = 0xFF;
                            lbl_805DE3A0.b = 0xFF;
                            lbl_805DE3A0.a = 0xFF;
                            lbl_805DE39C.r = 0;
                            lbl_805DE39C.g = 0;
                            lbl_805DE39C.b = 0;
                            lbl_805DE39C.a = 0;
                            lbl_805DE398.r = 0xFF;
                            lbl_805DE398.g = 0xFF;
                            lbl_805DE398.b = 0xFF;
                            lbl_805DE398.a = 0xFF;
                            GXSetTevColor(GX_TEVREG0, &lbl_805DE3A0);
                            GXSetTevColor(GX_TEVREG1, &lbl_805DE39C);
                            GXSetTevColor(GX_TEVREG2, &lbl_805DE398);

                            lbl_805DE3B0 = -1;
                            GXSetZCompLoc(GX_DISABLE);

                            {
                                HSD_CObj* cobj = HSD_CObjGetCurrent();
                                HSD_CObjGetViewingMtx(cobj, (f32(*)[4]) &lbl_8058CC08);
                            }
                            fn_803D1578((f32(*)[4]) &lbl_8058CC08, (f32*) &lbl_8058CC08.cam);
                            fn_803D06DC(&lbl_8058CC08.unk30);

                            GXLoadPosMtxImm((f32(*)[4]) &lbl_8058CC08, GX_PNMTX0);
                            {
                                Mtx m2;
                                memcpy(m2, &lbl_8048C570, sizeof(Mtx));
                                GXLoadPosMtxImm(m2, GX_PNMTX1);
                            }

                            lbl_805DE394 = 3;
                            if (lbl_805DE394 != 0) {
                                lbl_805DE394 = 0;
                                GXSetCurrentMtx(GX_PNMTX0);
                            }

                            GXEnableTexOffsets(0, 1, 1);
                            HSD_MtxGetRotationMtx(lbl_8058CC08.cam, lbl_8058CCB4.m, 'z', 'x');
                            GXSetCullMode(GX_CULL_BACK);
                            GXSetArray(0xD, (void*) lbl_ps_texidx_tbl, 2);

                            GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_TEX_ST, GX_RGBA6, 0);
                            GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_RGB565, 0);
                            GXSetVtxAttrFmt(GX_VTXFMT1, GX_VA_POS, GX_TEX_ST, GX_RGBA6, 0);
                            GXSetVtxAttrFmt(GX_VTXFMT2, GX_VA_POS, GX_TEX_ST, GX_RGBA6, 0);
                            GXSetVtxAttrFmt(GX_VTXFMT2, GX_VA_CLR0, GX_TEX_ST, GX_RGBA8, 0);
                            GXSetVtxAttrFmt(GX_VTXFMT2, GX_VA_TEX0, GX_TEX_ST, GX_RGB565, 0);
                            GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_POS, GX_TEX_ST, GX_RGBA6, 0);
                            GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_CLR0, GX_TEX_ST, GX_RGBA8, 0);
                            GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_POS, GX_TEX_ST, GX_RGBA6, 0);
                            GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_TEX0, GX_TEX_ST, GX_RGBA6, 0);
                            GXSetVtxAttrFmt(GX_VTXFMT5, GX_VA_POS, GX_TEX_ST, GX_RGBA6, 0);
                            GXSetVtxAttrFmt(GX_VTXFMT5, GX_VA_CLR0, GX_TEX_ST, GX_RGBA8, 0);
                            GXSetVtxAttrFmt(GX_VTXFMT5, GX_VA_TEX0, GX_TEX_ST, GX_RGBA6, 0);

                            first = 0;
                        }

                        blendMode = ((u32) pp->kind >> 0x16) & 3;
                        if (lbl_805DE3B0 != blendMode) {
                            lbl_805DE3B0 = blendMode;
                            switch (blendMode) {
                            case 0:
                                GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA,
                                               GX_LO_CLEAR);
                                break;
                            case 1:
                                GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, 5 /* GX_BL_ONE */,
                                               GX_LO_CLEAR);
                                break;
                            case 2:
                                GXSetBlendMode(2 /* GX_BM_SUBTRACT */, GX_BL_SRCALPHA,
                                               GX_BL_INVSRCALPHA, GX_LO_CLEAR);
                                break;
                            case 3:
                                GXSetBlendMode(GX_BM_BLEND, 8 /* GX_BL_DSTCLR */, 0 /* GX_BL_ZERO */,
                                               GX_LO_CLEAR);
                                break;
                            default:
                                OSReport("unknown blend mode");
                                break;
                            }
                        }

                        {
                            u8 refA, refB;
                            u8 aCompMode = pp->aCmpMode;

                            if (pp->aCmpCount != 0) {
                                s32 t = (s32)(pp->aCmpRemain << 16) / (s32) pp->aCmpCount;
                                refA = (u8) ((s32) ((pp->aCmpParam1 << 16) +
                                                     t * (pp->aCmpParam1Target - pp->aCmpParam1)) >>
                                             16);
                                refB = (u8) ((s32) ((pp->aCmpParam2 << 16) +
                                                     t * (pp->aCmpParam2Target - pp->aCmpParam2)) >>
                                             16);
                            } else {
                                refA = pp->aCmpParam1;
                                refB = pp->aCmpParam2;
                            }

                            if (alphaCache != (s32) aCompMode || alphaRefA != refA ||
                                alphaRefB != refB) {
                                alphaCache = aCompMode;
                                alphaRefA = refA;
                                alphaRefB = refB;
                                GXSetAlphaCompare((aCompMode >> 3) & 7, refA, (aCompMode >> 6) & 3,
                                                  aCompMode & 7, refB);
                            }
                        }

                        kar_psdisp__near_80437518(pp);

                        lightMode = pp->kind & 0x80100000;
                        if (lightMode != lbl_805DE3AC) {
                            lbl_805DE3AC = lightMode;
                            GXSetNumChans(1);
                            if ((s32) lbl_805DE3AC == 0x80100000) {
                                u32 af = HSD_LObjGetLightMaskAttnFunc() != 0 ? GX_AF_SPOT : GX_AF_NONE;
                                GXSetChanCtrl(GX_COLOR0, GX_ENABLE, GX_SRC_REG, GX_SRC_REG,
                                              HSD_LObjGetLightMaskDiffuse(), GX_DF_NONE, af);
                                GXSetChanCtrl(GX_ALPHA0, GX_DISABLE, GX_SRC_VTX, GX_SRC_VTX,
                                              GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
                            } else if ((s32) lbl_805DE3AC < 0x80100000) {
                                if ((s32) lbl_805DE3AC < 0x80000001) {
                                    u32 af = HSD_LObjGetLightMaskAttnFunc() != 0 ? GX_AF_SPOT
                                                                                 : GX_AF_NONE;
                                    GXSetChanCtrl(GX_COLOR0, GX_ENABLE, GX_SRC_REG, GX_SRC_REG,
                                                  HSD_LObjGetLightMaskDiffuse(), GX_DF_NONE, af);
                                    GXSetChanCtrl(GX_ALPHA0, GX_DISABLE, GX_SRC_REG, GX_SRC_REG,
                                                  GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
                                } else if ((s32) lbl_805DE3AC == 0x100000) {
                                    GXSetChanCtrl(GX_COLOR0A0, GX_DISABLE, GX_SRC_VTX, GX_SRC_VTX,
                                                  GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
                                } else {
                                    GXSetChanCtrl(GX_COLOR0A0, GX_DISABLE, GX_SRC_REG, GX_SRC_REG,
                                                  GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
                                }
                            } else {
                                GXSetChanCtrl(GX_COLOR0A0, GX_DISABLE, GX_SRC_REG, GX_SRC_REG,
                                              GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
                            }
                            GXSetChanCtrl(GX_COLOR1A1, GX_DISABLE, GX_SRC_REG, GX_SRC_REG,
                                          GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
                        }

                        kar_psdisp__near_80437168(pp);
                        kar_psdisp__near_80436d4c(pp);

                        zMode = pp->kind & 0x10000008;
                        if (zMode != (u32) prevKind) {
                            prevKind = zMode;
                            if (zMode & 8) {
                                GXSetZMode(((pp->kind >> 0x1C) & 1) ^ 1, GX_LEQUAL, GX_ENABLE);
                            } else {
                                GXSetZMode(((pp->kind >> 0x1C) & 1) ^ 1, GX_LEQUAL, GX_DISABLE);
                            }
                        }

                        if ((pp->kind ^ (u32) prevKind) & 0x01000000) {
                            if (pp->kind & 0x01000000) {
                                HSD_FogSet(lbl_805DE390);
                            } else {
                                HSD_FogSet(NULL);
                            }
                        }

                        cmdList = NULL;
                        {
                            void* fmtGroup = lbl_8058C508[pp->bank];
                            if (fmtGroup != NULL) {
                                u32* formTable = (u32*) fmtGroup;
                                u32* poseTable = (u32*) formTable[1 + pp->texGroup];
                                if (poseTable != NULL) {
                                    cmdList = (u32*) poseTable[1 + pp->poseNum];
                                }
                            }
                        }

                        if (pp->kind & 0x400) {
                            f32 sWrap, tWrap;
                            u32 wrapS, wrapT;
                            u32 mask;

                            if (pp->kind & 0x20) {
                                sWrap = 2.0F;
                                wrapS = GX_MIRROR;
                            } else {
                                sWrap = lbl_805E5FC0;
                                wrapS = GX_CLAMP;
                            }
                            if (pp->kind & 0x40) {
                                tWrap = 2.0F;
                                wrapT = GX_MIRROR;
                            } else {
                                tWrap = lbl_805E5FC0;
                                wrapT = GX_CLAMP;
                            }

                            mask = pp->kind & 0x60;
                            if (mask != lbl_805DE3B0) {
                                Mtx texMtx;

                                lbl_805DE3B0 = mask;
                                fn_803D19AC(texMtx, NULL, sWrap, tWrap, lbl_805E5FC0);
                                GXLoadTexMtxImm(texMtx, 0x1E, 1);
                                GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x1E,
                                                  GX_DISABLE, 0x7D);
                            }

                            {
                                void* texGroup = lbl_8058C408[pp->bank];
                                void* texEntry = NULL;
                                u32 fmt = GX_TF_I4;
                                u32 w = 0, h = 0;
                                void* imgBase = NULL;
                                void* img = NULL;

                                if (texGroup != NULL) {
                                    u32* texGroupW = (u32*) texGroup;
                                    void* group = (void*) texGroupW[1 + pp->texGroup];
                                    if (group != NULL) {
                                        u32* g = (u32*) group;
                                        fmt = g[1];
                                        imgBase = (void*) &g[6];
                                        h = g[3];
                                        w = g[4];
                                    }
                                    if (imgBase != NULL) {
                                        img = ((void**) imgBase)[pp->poseNum];
                                    }

                                    if ((fmt == GX_TF_CI4 || fmt == GX_TF_CI8) && imgBase != NULL) {
                                        u32* pal = (u32*) ((u8*) group + ((u32*) group)[0] * 4);
                                        void* lut = NULL;
                                        if (pal != NULL) {
                                            if (pp->palNum != 0xFF) {
                                                lut = ((void**) pal)[pp->palNum & 0xFF];
                                            } else if (!(pp->kind & 0x10)) {
                                                lut = ((void**) pal)[pp->poseNum];
                                            } else {
                                                lut = ((void**) pal)[0];
                                            }
                                            if (lut != NULL) {
                                                u16 nEntries = (fmt == GX_TF_CI4) ? 0x10 : 0x100;
                                                void* tlutObj_ = (void*) 0;
                                                u32 tlutFmt = ((u32*) group)[2];
                                                {
                                                    u8 tlutObj[0x10];
                                                    GXInitTlutObj(tlutObj, lut, tlutFmt, nEntries);
                                                    GXLoadTlut(tlutObj, 0);
                                                }
                                            }
                                        }
                                        texEntry = NULL;
                                    }

                                    if (texEntry != img && img != NULL) {
                                        GXTexObj to;

                                        texEntry = img;
                                        if (fmt < 0xA) {
                                            if (fmt == 7) {
                                                assert_line(1902, 0);
                                            } else if (fmt < 7) {
                                                GXInitTexObj(&to, img, (u16) w, (u16) h, fmt, wrapS,
                                                             wrapT, GX_DISABLE);
                                            } else {
                                                GXInitTexObjCI(&to, img, (u16) w, (u16) h, fmt, wrapS,
                                                               wrapT, 0);
                                            }
                                        } else if (fmt == GX_TF_CMPR) {
                                            GXInitTexObj(&to, img, (u16) w, (u16) h, fmt, wrapS,
                                                         wrapT, GX_DISABLE);
                                        } else {
                                            assert_line(1902, 0);
                                        }

                                        {
                                            u32 mip = pp->kind & 0x200;
                                            mask = mip;
                                            fn_803CDA90(&to, mip == 0, ((pp->kind >> 9) & 1) ^ 1, 0,
                                                       0, 0, lbl_805E5FA0, lbl_805E5FA0,
                                                       lbl_805E5FA0);
                                            GXLoadTexObj(&to, GX_TEXMAP0);
                                        }
                                    }

                                    if ((pp->kind & 0x200) != mask) {
                                        GXTexObj to2;
                                        u32 mip2 = pp->kind & 0x200;
                                        s32 same = mip2 == 0;

                                        mask = mip2;
                                        fn_803CDA90(&to2, same, same, 0, 0, 0, lbl_805E5FA0,
                                                   lbl_805E5FA0, lbl_805E5FA0);
                                        GXLoadTexObj(&to2, GX_TEXMAP0);
                                    }
                                }
                            }
                        }

                        if (pp->kind & 0x40000000) {
                            if (pp->appsrt != NULL) {
                                kar_psdisp__near_80436774(pp);
                            } else if (pp->kind & 0x100000) {
                                kar_psdisp__near_80436460(pp);
                            } else {
                                f32 width;
                                u32 lw;

                                if (lbl_805DE394 != 0) {
                                    lbl_805DE394 = 0;
                                    GXSetCurrentMtx(GX_PNMTX0);
                                }
                                width = pp->size;
                                if (width > 42.5) {
                                    width = 255.0F;
                                } else {
                                    width = 6.0F * width;
                                }
                                lw = (u8) width;
                                if (lbl_805DE3D0 != (s32) lw) {
                                    lbl_805DE3D0 = lw;
                                    GXSetPointSize((u8) lw, 5);
                                }
                                if (pp->kind & 0x400) {
                                    GXClearVtxDesc();
                                    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
                                    GXSetVtxDesc(GX_VA_TEX0, GX_INDEX8);
                                    GXBegin(GX_POINTS, GX_VTXFMT0, 1);
                                } else {
                                    GXClearVtxDesc();
                                    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
                                    GXBegin(GX_POINTS, GX_VTXFMT1, 1);
                                }
                                GX_FIFO_F32 = pp->pos.x;
                                GX_FIFO_F32 = pp->pos.y;
                                GX_FIFO_F32 = pp->pos.z;
                                if (pp->kind & 0x400) {
                                    GX_FIFO_U8 = 1;
                                }
                            }
                        } else if (pp->appsrt != NULL) {
                            kar_psdisp__near_80435c0c(pp, cmdList);
                        } else {
                            kar_psdisp__near_80434d84(pp, cmdList);
                        }
                    }
                }
                prevKind = pp->kind;
                pp = pp->next;
            }
        }
    }

    if (!first) {
        HSD_StateInvalidate(-1);
    }
}

extern s32 kar_psdisp__near_80435268(HSD_Particle* pp, u32* cmdList, f32 curX, f32 curY, f32 curZ,
                                      f32 prevX, f32 prevY, f32 prevZ, f32 rightX, f32 rightY,
                                      f32 rightZ, f32 upX, f32 upY, f32 upZ);

static f64 lbl_805E6010 = 0.01;

void kar_psdisp__near_80434d84(HSD_Particle* pp, u32* cmdList)
{
    f32 curX;
    f32 curY;
    f32 curZ;
    f32 rightX;
    f32 rightY;
    f32 rightZ;
    f32 upX;
    f32 upY;
    f32 upZ;
    f32 angle;

    curX = pp->pos.x;
    curY = pp->pos.y;
    curZ = pp->pos.z;

    if (cmdList != NULL) {
        f32 size = pp->size;
        rightX = lbl_8058CC08.cam[0][0] * size;
        upX = -lbl_8058CC08.cam[0][1] * size;
        rightY = lbl_8058CC08.cam[1][0] * size;
        upY = -lbl_8058CC08.cam[1][1] * size;
        rightZ = lbl_8058CC08.cam[2][0] * size;
        upZ = -lbl_8058CC08.cam[2][1] * size;
    } else {
        f32 size = pp->size;
        rightX = lbl_805DE3C8 * size;
        upX = lbl_805DE3C4 * size;
        rightY = lbl_805DE3C0 * size;
        upY = lbl_805DE3BC * size;
        rightZ = lbl_805DE3B8 * size;
        upZ = lbl_805DE3B4 * size;
    }

    if (pp->kind & 0x100000 || pp->kind & 0x200000) {
        f32 vx = 0.0F;
        f32 vy = 0.0F;
        s32 skip = 0;

        if (lbl_805E5FA0 == lbl_8058CC08.unk30) {
            f32 dx, dy, dz;
            f32 d0, d1;

            if (pp->kind & 4) {
                kar_generator__near_804333d4(pp, &dx, &dy, &dz);
            } else {
                dx = pp->pos.x - pp->vel.x;
                dy = pp->pos.y - pp->vel.y;
                dz = pp->pos.z - pp->vel.z;
            }

            d0 = lbl_8058CC08.unk2C +
                 (lbl_8058CC08.unk28 * pp->pos.z + lbl_8058CC08.unk20 * pp->pos.x +
                  lbl_8058CC08.unk24 * pp->pos.y);
            skip = 1;
            if (lbl_805E5FA0 != d0) {
                f32 inv0 = -1.0F / d0;
                d1 = lbl_8058CC08.unk2C + (lbl_8058CC08.unk28 * dz + lbl_8058CC08.unk20 * dx +
                                           lbl_8058CC08.unk24 * dy);
                if (lbl_805E5FA0 != d1) {
                    f32 inv1 = -1.0F / d1;
                    vx = (inv0 * (lbl_8058CC08.unk58 + lbl_8058CC08.unk54 * pp->pos.z +
                                  lbl_8058CC08.unk4C * pp->pos.x + lbl_8058CC08.unk50 * pp->pos.y)) -
                         (inv1 * (lbl_8058CC08.unk58 + lbl_8058CC08.unk54 * dz +
                                  lbl_8058CC08.unk4C * dx + lbl_8058CC08.unk50 * dy));
                    vy = (inv0 * (lbl_8058CC08.unk68 + lbl_8058CC08.unk64 * pp->pos.z +
                                  lbl_8058CC08.unk5C * pp->pos.x + lbl_8058CC08.unk60 * pp->pos.y)) -
                         (inv1 * (lbl_8058CC08.unk68 + lbl_8058CC08.unk64 * dz +
                                  lbl_8058CC08.unk5C * dx + lbl_8058CC08.unk60 * dy));
                    skip = 0;
                }
            }
        } else {
            f32 dx, dy, dz;

            if (pp->kind & 4) {
                kar_generator__near_804333d4(pp, &dx, &dy, &dz);
                dx = pp->pos.x - dx;
                dy = pp->pos.y - dy;
                dz = pp->pos.z - dz;
            } else {
                dx = pp->pos.x - pp->vel.x;
                dy = pp->pos.y - pp->vel.y;
                dz = pp->pos.z - pp->vel.z;
            }
            vx = (lbl_8058CC08.unk54 * dz) + (lbl_8058CC08.unk4C * dx) + (lbl_8058CC08.unk50 * dy);
            vy = (lbl_8058CC08.unk64 * dz) + (lbl_8058CC08.unk5C * dx) + (lbl_8058CC08.unk60 * dy);
        }

        if (skip) {
            angle = pp->rotate;
        } else {
            angle = (__fabs(vy) < lbl_805DC8B8[0])
                        ? (vx == lbl_805E5FA0 ? 1.5707964F : -1.5707964F)
                        : (f32) fn_803BD3C8(vy, vx);
            if (pp->kind & 0x200000) {
                angle += pp->rotate;
            }
        }
    } else {
        angle = pp->rotate;
    }

    if (__fabs(angle) > lbl_805E6010) {
        Vec axis;
        Mtx9 rot;

        axis.x = (rightY * upZ) - (rightZ * upY);
        axis.y = (rightZ * upX) - (rightX * upZ);
        axis.z = (rightX * upY) - (rightY * upX);
        kar_grcoll__near_803d1908(rot, &axis, angle);

        {
            f32 nrx = (rot[0][0] * rightX) + (rot[0][1] * rightY) + (rot[0][2] * rightZ);
            f32 nux = (rot[0][0] * upX) + (rot[0][1] * upY) + (rot[0][2] * upZ);
            f32 nry = (rot[1][0] * rightX) + (rot[1][1] * rightY) + (rot[1][2] * rightZ);
            f32 nuy = (rot[1][0] * upX) + (rot[1][1] * upY) + (rot[1][2] * upZ);
            f32 nrz = (rot[2][0] * rightX) + (rot[2][1] * rightY) + (rot[2][2] * rightZ);
            f32 nuz = (rot[2][0] * upX) + (rot[2][1] * upY) + (rot[2][2] * upZ);
            rightX = nrx;
            upX = nux;
            rightY = nry;
            upY = nuy;
            rightZ = nrz;
            upZ = nuz;
        }
    }

    kar_psdisp__near_80435268(pp, cmdList, curX, curY, curZ, pp->vel.x, pp->vel.y,
                               pp->vel.z, rightX, rightY, rightZ, upX, upY, upZ);
}

s32 kar_psdisp__near_80435268(HSD_Particle* pp, u32* cmdList, f32 curX, f32 curY, f32 curZ,
                               f32 prevX, f32 prevY, f32 prevZ, f32 rightX, f32 rightY,
                               f32 rightZ, f32 upX, f32 upY, f32 upZ)
{
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    u8* p;
    u32 stripCount;
    s32 vtxCount;
    f32 dist;
    f32 invDist;
    f32 half;
    f32 hueScale;

    if (pp->kind & 0x100000) {
        if (pp->kind & 4) {
            if (pp->appsrt != NULL) {
                kar_generator__near_80433e54(pp, &curX, &curY, &curZ);
            } else {
                kar_generator__near_804333d4(pp, &curX, &curY, &curZ);
            }
        } else {
            curX -= prevX;
            curY -= prevY;
            curZ -= prevZ;
        }

        switch (pp->kind & 0x80000080) {
        default:
        case 0x0: {
            u16 count = pp->primColCount;
            if (count != 0) {
                s32 t = (s32)(pp->primColRemain << 16) / (s32) count;
                r = (u8) ((s32) ((pp->primCol.r << 16) + t * (pp->primColTarget.r - pp->primCol.r)) >> 16);
                g = (u8) ((s32) ((pp->primCol.g << 16) + t * (pp->primColTarget.g - pp->primCol.g)) >> 16);
                b = (u8) ((s32) ((pp->primCol.b << 16) + t * (pp->primColTarget.b - pp->primCol.b)) >> 16);
                a = (u8) ((s32) ((pp->primCol.a << 16) + t * (pp->primColTarget.a - pp->primCol.a)) >> 16);
            } else {
                r = pp->primCol.r;
            }
            break;
        }
        case 0x80:
        case 0x80000080:
            a = 0xFF;
            b = 0xFF;
            g = 0xFF;
            r = 0xFF;
            break;
        }

        if (cmdList == NULL) {
            if (pp->kind & 0x400) {
                GXClearVtxDesc();
                GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
                GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
                GXSetVtxDesc(GX_VA_TEX0, GX_INDEX8);
                GXBegin(GX_QUADS, GX_VTXFMT2, 4);
            } else {
                GXClearVtxDesc();
                GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
                GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
                GXBegin(GX_QUADS, GX_VTXFMT3, 4);
            }

            GX_FIFO_F32 = curX - rightX;
            GX_FIFO_F32 = curY - rightY;
            GX_FIFO_F32 = curZ - rightZ;
            GX_FIFO_U8 = r;
            GX_FIFO_U8 = g;
            GX_FIFO_U8 = b;
            GX_FIFO_U8 = (u8) ((f32) a * pp->trail);
            if (pp->kind & 0x400) {
                GX_FIFO_U8 = (u8) ((pp->kind >> 16) & 0xC);
            }
            GX_FIFO_F32 = curX - upX;
            GX_FIFO_F32 = curY - upY;
            GX_FIFO_F32 = curZ - upZ;
            GX_FIFO_U8 = r;
            GX_FIFO_U8 = g;
            GX_FIFO_U8 = b;
            GX_FIFO_U8 = a;
            if (pp->kind & 0x400) {
                GX_FIFO_U8 = (u8) (((pp->kind >> 16) & 0xC) + 1);
            }
            GX_FIFO_F32 = curX + rightX;
            GX_FIFO_F32 = curY + rightY;
            GX_FIFO_F32 = curZ + rightZ;
            GX_FIFO_U8 = r;
            GX_FIFO_U8 = g;
            GX_FIFO_U8 = b;
            GX_FIFO_U8 = a;
            if (pp->kind & 0x400) {
                GX_FIFO_U8 = (u8) (((pp->kind >> 16) & 0xC) + 2);
            }
            GX_FIFO_F32 = curX + upX;
            GX_FIFO_F32 = curY + upY;
            GX_FIFO_F32 = curZ + upZ;
            GX_FIFO_U8 = r;
            GX_FIFO_U8 = g;
            GX_FIFO_U8 = b;
            GX_FIFO_U8 = (u8) ((f32) a * pp->trail);
            if (pp->kind & 0x400) {
                GX_FIFO_U8 = (u8) (((pp->kind >> 16) & 0xC) + 3);
            }
        } else {
            dist = (curZ * curZ) + ((curX * curX) + (curY * curY));
            hueScale = 255.0F * (lbl_805E5FC0 - pp->trail);
            if (dist > lbl_805E5FA0) {
                dist = psdisp_sqrtf(dist);
            }
            if (!(__fabs(dist) < lbl_805DC8B8[0])) {
                f32 dx = prevX - curX;
                f32 dy = prevY - curY;
                f32 dz = prevZ - curZ;
                f32 len = (dz * dz) + ((dx * dx) + (dy * dy));
                if (len > lbl_805E5FA0) {
                    len = psdisp_sqrtf(len);
                }
                half = len / dist;
                if (half < lbl_805E5FC0) {
                    half = lbl_805E5FC0;
                }

                stripCount = *cmdList;
                p = (u8*) (cmdList + 1);
                while (stripCount != 0) {
                    TrailStripHdr* hdr = (TrailStripHdr*) p;
                    p += 4;
                    if (pp->kind & 0x400) {
                        GXClearVtxDesc();
                        GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
                        GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
                        GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
                        GXBegin(hdr->kind, GX_VTXFMT5, hdr->count);
                    } else {
                        GXClearVtxDesc();
                        GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
                        GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
                        GXBegin(hdr->kind, GX_VTXFMT3, hdr->count);
                    }

                    vtxCount = hdr->count;
                    if (vtxCount > 0) {
                        do {
                            f32 uu = *(f32*) p;
                            f32 vv = *(f32*) (p + 4);
                            f32 su = 2.0F * (uu - 0.5F);
                            s32 clr;

                            p += 8;
                            if (pp->kind & 0x40000) {
                                uu = lbl_805E5FC0 - uu;
                            }
                            clr = (s32) -((vv * hueScale) - 255.0F);
                            if (clr < 0) {
                                clr = 0;
                            }
                            if (clr > 0xFF) {
                                clr = -1;
                            }

                            {
                                f32 sv = 2.0F * (vv - 0.5F);
                                if (pp->kind & 0x80000) {
                                    vv = lbl_805E5FC0 - vv;
                                }

                                GX_FIFO_F32 = (rightX * half * sv) + (curX * su + curX);
                                GX_FIFO_F32 = (rightY * half * sv) + (curY * su + curY);
                                GX_FIFO_F32 = (rightZ * half * sv) + (curZ * su + curZ);
                                GX_FIFO_U8 = r;
                                GX_FIFO_U8 = g;
                                GX_FIFO_U8 = b;
                                GX_FIFO_U8 = (u8) clr;
                                if (pp->kind & 0x400) {
                                    GX_FIFO_F32 = uu;
                                    GX_FIFO_F32 = vv;
                                }
                            }
                            vtxCount--;
                        } while (vtxCount != 0);
                    }
                    stripCount--;
                }
            }
        }
    } else if (cmdList == NULL) {
        if (pp->kind & 0x400) {
            GXClearVtxDesc();
            GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
            GXSetVtxDesc(GX_VA_TEX0, GX_INDEX8);
            GXBegin(GX_QUADS, GX_VTXFMT0, 4);
        } else {
            GXClearVtxDesc();
            GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
            GXBegin(GX_QUADS, GX_VTXFMT1, 4);
        }

        GX_FIFO_F32 = curX - rightX;
        GX_FIFO_F32 = curY - rightY;
        GX_FIFO_F32 = curZ - rightZ;
        if (pp->kind & 0x400) {
            GX_FIFO_U8 = (u8) ((pp->kind >> 16) & 0xC);
        }
        GX_FIFO_F32 = curX - upX;
        GX_FIFO_F32 = curY - upY;
        GX_FIFO_F32 = curZ - upZ;
        if (pp->kind & 0x400) {
            GX_FIFO_U8 = (u8) (((pp->kind >> 16) & 0xC) + 1);
        }
        GX_FIFO_F32 = curX + rightX;
        GX_FIFO_F32 = curY + rightY;
        GX_FIFO_F32 = curZ + rightZ;
        if (pp->kind & 0x400) {
            GX_FIFO_U8 = (u8) (((pp->kind >> 16) & 0xC) + 2);
        }
        GX_FIFO_F32 = curX + upX;
        GX_FIFO_F32 = curY + upY;
        GX_FIFO_F32 = curZ + upZ;
        if (pp->kind & 0x400) {
            GX_FIFO_U8 = (u8) (((pp->kind >> 16) & 0xC) + 3);
        }
    } else {
        stripCount = *cmdList;
        p = (u8*) (cmdList + 1);
        while (stripCount != 0) {
            TrailStripHdr* hdr = (TrailStripHdr*) p;
            p += 4;
            if (pp->kind & 0x400) {
                GXClearVtxDesc();
                GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
                GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
                GXBegin(hdr->kind, GX_VTXFMT4, hdr->count);
            } else {
                GXClearVtxDesc();
                GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
                GXBegin(hdr->kind, GX_VTXFMT1, hdr->count);
            }

            vtxCount = hdr->count;
            if (vtxCount > 0) {
                do {
                    f32 uu = *(f32*) p;
                    f32 vv = *(f32*) (p + 4);
                    f32 su = 2.0F * (uu - 0.5F);
                    f32 sv;

                    p += 8;
                    if (pp->kind & 0x40000) {
                        uu = lbl_805E5FC0 - uu;
                    }
                    sv = 2.0F * (vv - 0.5F);
                    if (pp->kind & 0x80000) {
                        vv = lbl_805E5FC0 - vv;
                    }

                    GX_FIFO_F32 = (rightX * sv) + (curX * su + curX);
                    GX_FIFO_F32 = (rightY * sv) + (curY * su + curY);
                    GX_FIFO_F32 = (rightZ * sv) + (curZ * su + curZ);
                    if (pp->kind & 0x400) {
                        GX_FIFO_F32 = uu;
                        GX_FIFO_F32 = vv;
                    }
                    vtxCount--;
                } while (vtxCount != 0);
            }
            stripCount--;
        }
    }
    return 0;
}

extern u8 lbl_805DCDE8;

void kar_psdisp__near_80435c0c(HSD_Particle* pp, u32* cmdList)
{
    HSD_psAppSRT* srt;
    Mtx worldMtx;
    Vec prevPos;
    Vec curPos;
    f32 rightX, rightY, rightZ;
    f32 upX, upY, upZ;
    f32 angle;

    srt = pp->appsrt;
    if (srt->frameNum != lbl_805DCDE8) {
        if (srt->status != 2) {
            Vec t;
            t.x = srt->translate.x + srt->unk30.x;
            t.y = srt->translate.y + srt->unk30.y;
            t.z = srt->translate.z + srt->unk30.z;
            HSD_MtxSRT(srt->mmtx, &srt->scale, &srt->rot, &t, NULL);
        }
        srt = pp->appsrt;
        if (srt->status == 1) {
            srt->status = 2;
        }
    }
    pp->appsrt->frameNum = lbl_805DCDE8;

    PSMTXCopy(pp->appsrt->mmtx, worldMtx);
    srt = pp->appsrt;
    worldMtx[0][3] -= srt->translate.x;
    worldMtx[1][3] -= srt->translate.y;
    worldMtx[2][3] -= srt->translate.z;

    prevPos = pp->vel;
    PSMTXMultVec(worldMtx, &prevPos, &prevPos);
    if (pp->appsrt->xA2 != 0 && !(pp->kind & 4)) {
        PSMTXMultVec(lbl_8058CCB4.m, &prevPos, &prevPos);
    }

    curPos = pp->pos;
    if (pp->appsrt->xA2 != 0) {
        PSMTXMultVec(worldMtx, &curPos, &curPos);
        PSMTXMultVec(lbl_8058CCB4.m, &curPos, &curPos);
        srt = pp->appsrt;
        curPos.x += srt->translate.x;
        curPos.y += srt->translate.y;
        curPos.z += srt->translate.z;
    } else {
        PSMTXMultVec(worldMtx, &curPos, &curPos);
    }

    if (cmdList != NULL) {
        Mtx scaleMtx;
        f32 size;

        srt = pp->appsrt;
        fn_803D19AC(scaleMtx, srt, srt->scale.x, srt->scale.y, lbl_805E5FC0);
        PSMTXConcat(lbl_8058CC08.cam, scaleMtx, scaleMtx);
        size = pp->size;
        rightX = scaleMtx[0][0] * size;
        upX = -scaleMtx[0][1] * size;
        rightY = scaleMtx[1][0] * size;
        upY = -scaleMtx[1][1] * size;
        rightZ = scaleMtx[2][0] * size;
        upZ = -scaleMtx[2][1] * size;
    } else {
        Vec right, up;
        f32 size;

        srt = pp->appsrt;
        right.x = srt->scale.x + lbl_8058CC08.unk0C;
        right.z = lbl_8058CC08.unk2C;
        up.x = srt->scale.x + lbl_8058CC08.unk0C;
        right.y = srt->scale.y + lbl_8058CC08.unk1C;
        up.y = -srt->scale.y + lbl_8058CC08.unk1C;
        up.z = lbl_8058CC08.unk2C;
        PSMTXMultVec(lbl_8058CC08.cam, &right, &right);
        size = pp->size;
        rightX = right.x * size;
        rightY = right.y * size;
        rightZ = right.z * size;
        PSMTXMultVec(lbl_8058CC08.cam, &up, &up);
        upX = up.x * size;
        upY = up.y * size;
        upZ = up.z * size;
    }

    if (pp->kind & 0x100000 || pp->kind & 0x200000) {
        f32 vx = 0.0F;
        f32 vy = 0.0F;
        s32 skip = 0;

        if (lbl_805E5FA0 == lbl_8058CC08.unk30) {
            Vec dv;
            f32 d0, d1;

            if (pp->kind & 4) {
                kar_generator__near_804333d4(pp, &dv.x, &dv.y, &dv.z);
                if (pp->appsrt->xA2 != 0) {
                    PSMTXMultVec(worldMtx, &dv, &dv);
                    PSMTXMultVec(lbl_8058CCB4.m, &dv, &dv);
                    srt = pp->appsrt;
                    dv.x += srt->translate.x;
                    dv.y += srt->translate.y;
                    dv.z += srt->translate.z;
                } else {
                    PSMTXMultVec(worldMtx, &dv, &dv);
                }
            } else {
                dv.x = curPos.x - prevPos.x;
                dv.y = curPos.y - prevPos.y;
                dv.z = curPos.z - prevPos.z;
            }

            d0 = lbl_8058CC08.unk2C +
                 (lbl_8058CC08.unk28 * curPos.z + lbl_8058CC08.unk20 * curPos.x +
                  lbl_8058CC08.unk24 * curPos.y);
            skip = 1;
            if (lbl_805E5FA0 != d0) {
                f32 inv0 = -1.0F / d0;
                d1 = lbl_8058CC08.unk2C + (lbl_8058CC08.unk28 * dv.z + lbl_8058CC08.unk20 * dv.x +
                                           lbl_8058CC08.unk24 * dv.y);
                if (lbl_805E5FA0 != d1) {
                    f32 inv1 = -1.0F / d1;
                    vx = (inv0 * (lbl_8058CC08.unk58 + lbl_8058CC08.unk54 * curPos.z +
                                  lbl_8058CC08.unk4C * curPos.x + lbl_8058CC08.unk50 * curPos.y)) -
                         (inv1 * (lbl_8058CC08.unk58 + lbl_8058CC08.unk54 * dv.z +
                                  lbl_8058CC08.unk4C * dv.x + lbl_8058CC08.unk50 * dv.y));
                    vy = (inv0 * (lbl_8058CC08.unk68 + lbl_8058CC08.unk64 * curPos.z +
                                  lbl_8058CC08.unk5C * curPos.x + lbl_8058CC08.unk60 * curPos.y)) -
                         (inv1 * (lbl_8058CC08.unk68 + lbl_8058CC08.unk64 * dv.z +
                                  lbl_8058CC08.unk5C * dv.x + lbl_8058CC08.unk60 * dv.y));
                    skip = 0;
                }
            }
        } else if (pp->kind & 4) {
            Vec dv;

            kar_generator__near_804333d4(pp, &dv.x, &dv.y, &dv.z);
            if (pp->appsrt->xA2 != 0) {
                PSMTXMultVec(worldMtx, &dv, &dv);
                PSMTXMultVec(lbl_8058CCB4.m, &dv, &dv);
                srt = pp->appsrt;
                dv.x += srt->translate.x;
                dv.y += srt->translate.y;
                dv.z += srt->translate.z;
            } else {
                PSMTXMultVec(worldMtx, &dv, &dv);
            }
            {
                f32 ddx = curPos.x - dv.x;
                f32 ddy = curPos.y - dv.y;
                f32 ddz = curPos.z - dv.z;
                vx = (lbl_8058CC08.unk54 * ddz) + (lbl_8058CC08.unk4C * ddx) +
                     (lbl_8058CC08.unk50 * ddy);
                vy = (lbl_8058CC08.unk64 * ddz) + (lbl_8058CC08.unk5C * ddx) +
                     (lbl_8058CC08.unk60 * ddy);
            }
        } else {
            vx = (lbl_8058CC08.unk54 * prevPos.z) + (lbl_8058CC08.unk4C * prevPos.x) +
                 (lbl_8058CC08.unk50 * prevPos.y);
            vy = (lbl_8058CC08.unk64 * prevPos.z) + (lbl_8058CC08.unk5C * prevPos.x) +
                 (lbl_8058CC08.unk60 * prevPos.y);
        }

        if (skip) {
            angle = pp->rotate;
        } else {
            angle = (__fabs(vy) < lbl_805DC8B8[0])
                        ? (vx == lbl_805E5FA0 ? 1.5707964F : -1.5707964F)
                        : (f32) fn_803BD3C8(vy, vx);
            if (pp->kind & 0x200000) {
                angle += pp->rotate;
            }
        }
    } else {
        angle = pp->rotate;
    }

    if (__fabs(angle) > lbl_805E6010) {
        Vec axis;
        Mtx9 rot;

        axis.x = (rightY * upZ) - (rightZ * upY);
        axis.y = (rightZ * upX) - (rightX * upZ);
        axis.z = (rightX * upY) - (rightY * upX);
        kar_grcoll__near_803d1908(rot, &axis, angle);

        {
            f32 nrx = (rot[0][0] * rightX) + (rot[0][1] * rightY) + (rot[0][2] * rightZ);
            f32 nux = (rot[0][0] * upX) + (rot[0][1] * upY) + (rot[0][2] * upZ);
            f32 nry = (rot[1][0] * rightX) + (rot[1][1] * rightY) + (rot[1][2] * rightZ);
            f32 nuy = (rot[1][0] * upX) + (rot[1][1] * upY) + (rot[1][2] * upZ);
            f32 nrz = (rot[2][0] * rightX) + (rot[2][1] * rightY) + (rot[2][2] * rightZ);
            f32 nuz = (rot[2][0] * upX) + (rot[2][1] * upY) + (rot[2][2] * upZ);
            rightX = nrx;
            upX = nux;
            rightY = nry;
            upY = nuy;
            rightZ = nrz;
            upZ = nuz;
        }
    }

    kar_psdisp__near_80435268(pp, cmdList, curPos.x, curPos.y, curPos.z, prevPos.x, prevPos.y,
                               prevPos.z, rightX, rightY, rightZ, upX, upY, upZ);
}

void* kar_psdisp__near_80436460(HSD_Particle* pp)
{
    f32 dx;
    f32 dy;
    f32 dz;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    f32 width;
    u32 lineWidth;
    u16 count;

    if (lbl_805DE394 != 0) {
        lbl_805DE394 = 0;
        GXSetCurrentMtx(GX_PNMTX0);
    }

    width = pp->size;
    if (width > 42.5) {
        width = 255.0F;
    } else {
        width = 6.0F * width;
    }
    lineWidth = (u8) width;
    if (lbl_805DE3CC != (s32) lineWidth) {
        lbl_805DE3CC = lineWidth;
        GXSetLineWidth((u8) lineWidth, 5);
    }

    if (pp->kind & 4) {
        kar_generator__near_804333d4(pp, &dx, &dy, &dz);
    } else {
        dx = pp->pos.x - pp->vel.x;
        dy = pp->pos.y - pp->vel.y;
        dz = pp->pos.z - pp->vel.z;
    }

    switch (pp->kind & 0x80000080) {
    default:
    case 0x0:
        count = pp->primColCount;
        if (count != 0) {
            s32 t = (s32)(pp->primColRemain << 16) / (s32) count;
            r = (u8) ((s32) ((pp->primCol.r << 16) + t * (pp->primColTarget.r - pp->primCol.r)) >> 16);
            g = (u8) ((s32) ((pp->primCol.g << 16) + t * (pp->primColTarget.g - pp->primCol.g)) >> 16);
            b = (u8) ((s32) ((pp->primCol.b << 16) + t * (pp->primColTarget.b - pp->primCol.b)) >> 16);
            a = (u8) ((s32) ((pp->primCol.a << 16) + t * (pp->primColTarget.a - pp->primCol.a)) >> 16);
        } else {
            r = pp->primCol.r;
        }
        break;
    case 0x80:
    case 0x80000080:
        a = 0xFF;
        b = 0xFF;
        g = 0xFF;
        r = 0xFF;
        break;
    }

    if (pp->kind & 0x400) {
        GXClearVtxDesc();
        GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
        GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
        GXSetVtxDesc(GX_VA_TEX0, GX_INDEX8);
        GXBegin(GX_LINES, GX_VTXFMT2, 2);
    } else {
        GXClearVtxDesc();
        GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
        GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
        GXBegin(GX_LINES, GX_VTXFMT3, 2);
    }

    GX_FIFO_F32 = dx;
    GX_FIFO_F32 = dy;
    GX_FIFO_F32 = dz;
    GX_FIFO_U8 = r;
    GX_FIFO_U8 = g;
    GX_FIFO_U8 = b;
    GX_FIFO_U8 = (u8) ((f32) a * pp->trail);
    if (pp->kind & 0x400) {
        GX_FIFO_U8 = 0;
    }
    GX_FIFO_F32 = pp->pos.x;
    GX_FIFO_F32 = pp->pos.y;
    GX_FIFO_F32 = pp->pos.z;
    GX_FIFO_U8 = r;
    GX_FIFO_U8 = g;
    GX_FIFO_U8 = b;
    GX_FIFO_U8 = a;
    if (pp->kind & 0x400) {
        GX_FIFO_U8 = 1;
    }
    return pp;
}

extern u8 lbl_805DCDE8;
extern s32 lbl_805DE3D0;

extern void GXSetPointSize(u8 size, u32 tex_offsets);

#define GX_POINTS 0xB8
#define GX_VTXFMT0 0
#define GX_VTXFMT1 1

void kar_psdisp__near_80436774(HSD_Particle* pp)
{
    HSD_psAppSRT* srt;
    Mtx worldMtx;
    Vec prevPos;
    Vec curPos;
    f32 dx;
    f32 dy;
    f32 dz;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    f32 width;
    u32 lineWidth;
    u16 count;

    if (lbl_805DE394 != 0) {
        lbl_805DE394 = 0;
        GXSetCurrentMtx(GX_PNMTX0);
    }

    srt = pp->appsrt;
    if (srt->frameNum != lbl_805DCDE8) {
        if (srt->status != 2) {
            Vec t;
            t.x = srt->translate.x + srt->unk30.x;
            t.y = srt->translate.y + srt->unk30.y;
            t.z = srt->translate.z + srt->unk30.z;
            HSD_MtxSRT(srt->mmtx, &srt->scale, &srt->rot, &t, NULL);
        }
        srt = pp->appsrt;
        if (srt->status == 1) {
            srt->status = 2;
        }
    }
    pp->appsrt->frameNum = lbl_805DCDE8;

    PSMTXCopy(pp->appsrt->mmtx, worldMtx);
    srt = pp->appsrt;
    worldMtx[0][3] -= srt->translate.x;
    worldMtx[1][3] -= srt->translate.y;
    worldMtx[2][3] -= srt->translate.z;

    prevPos = pp->vel;
    PSMTXMultVec(worldMtx, &prevPos, &prevPos);
    if (pp->appsrt->xA2 != 0) {
        PSMTXMultVec(lbl_8058CCB4.m, &prevPos, &prevPos);
    }

    curPos = pp->pos;
    if (pp->appsrt->xA2 != 0) {
        PSMTXMultVec(worldMtx, &curPos, &curPos);
        PSMTXMultVec(lbl_8058CCB4.m, &curPos, &curPos);
        srt = pp->appsrt;
        curPos.x += srt->translate.x;
        curPos.y += srt->translate.y;
        curPos.z += srt->translate.z;
    } else {
        PSMTXMultVec(worldMtx, &curPos, &curPos);
    }

    if (pp->kind & 4) {
        kar_generator__near_80433e54(pp, &dx, &dy, &dz);
    } else {
        dx = curPos.x - prevPos.x;
        dy = curPos.y - prevPos.y;
        dz = curPos.z - prevPos.z;
    }

    width = pp->size;
    if (width > 42.5) {
        width = 255.0F;
    } else {
        width = 6.0F * width;
    }
    lineWidth = (u8) width;

    if (pp->kind & 0x100000) {
        if (lbl_805DE3CC != (s32) lineWidth) {
            lbl_805DE3CC = lineWidth;
            GXSetLineWidth((u8) lineWidth, 5);
        }

        switch (pp->kind & 0x80000080) {
        default:
        case 0x0:
            count = pp->primColCount;
            if (count != 0) {
                s32 t = (s32)(pp->primColRemain << 16) / (s32) count;
                r = (u8) ((s32) ((pp->primCol.r << 16) + t * (pp->primColTarget.r - pp->primCol.r)) >> 16);
                g = (u8) ((s32) ((pp->primCol.g << 16) + t * (pp->primColTarget.g - pp->primCol.g)) >> 16);
                b = (u8) ((s32) ((pp->primCol.b << 16) + t * (pp->primColTarget.b - pp->primCol.b)) >> 16);
                a = (u8) ((s32) ((pp->primCol.a << 16) + t * (pp->primColTarget.a - pp->primCol.a)) >> 16);
            } else {
                r = pp->primCol.r;
            }
            break;
        case 0x80:
        case 0x80000080:
            a = 0xFF;
            b = 0xFF;
            g = 0xFF;
            r = 0xFF;
            break;
        }

        if (pp->kind & 0x400) {
            GXClearVtxDesc();
            GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
            GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
            GXSetVtxDesc(GX_VA_TEX0, GX_INDEX8);
            GXBegin(GX_LINES, GX_VTXFMT2, 2);
        } else {
            GXClearVtxDesc();
            GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
            GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
            GXBegin(GX_LINES, GX_VTXFMT3, 2);
        }

        GX_FIFO_F32 = dx;
        GX_FIFO_F32 = dy;
        GX_FIFO_F32 = dz;
        GX_FIFO_U8 = r;
        GX_FIFO_U8 = g;
        GX_FIFO_U8 = b;
        GX_FIFO_U8 = (u8) ((f32) a * pp->trail);
        if (pp->kind & 0x400) {
            GX_FIFO_U8 = 0;
        }
        GX_FIFO_F32 = curPos.x;
        GX_FIFO_F32 = curPos.y;
        GX_FIFO_F32 = curPos.z;
        GX_FIFO_U8 = r;
        GX_FIFO_U8 = g;
        GX_FIFO_U8 = b;
        GX_FIFO_U8 = a;
        if (pp->kind & 0x400) {
            GX_FIFO_U8 = 1;
        }
    } else {
        if (lbl_805DE3D0 != (s32) lineWidth) {
            lbl_805DE3D0 = lineWidth;
            GXSetPointSize((u8) lineWidth, 5);
        }

        if (pp->kind & 0x400) {
            GXClearVtxDesc();
            GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
            GXSetVtxDesc(GX_VA_TEX0, GX_INDEX8);
            GXBegin(GX_POINTS, GX_VTXFMT0, 1);
        } else {
            GXClearVtxDesc();
            GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
            GXBegin(GX_POINTS, GX_VTXFMT1, 1);
        }

        GX_FIFO_F32 = curPos.x;
        GX_FIFO_F32 = curPos.y;
        GX_FIFO_F32 = curPos.z;
        if (pp->kind & 0x400) {
            GX_FIFO_U8 = 1;
        }
    }
}

#define GX_TEVREG0 1
#define GX_TEVREG1 2
#define GX_TEVREG2 3

extern GXColor lbl_805DE398;
extern GXColor lbl_805DE39C;
extern GXColor lbl_805DE3A0;

extern void GXSetTevColor(u32 reg, GXColor* color);

void kar_psdisp__near_80436d4c(HSD_Particle* pp)
{
    GXColor prim;
    GXColor env;
    GXColor mat;
    GXColor tmp;
    s32 t;

    if (pp->primColCount != 0) {
        t = (s32)(pp->primColRemain << 16) / (s32) pp->primColCount;
        prim.r = (u8) ((s32) ((pp->primCol.r << 16) + t * (pp->primColTarget.r - pp->primCol.r)) >> 16);
        prim.g = (u8) ((s32) ((pp->primCol.g << 16) + t * (pp->primColTarget.g - pp->primCol.g)) >> 16);
        prim.b = (u8) ((s32) ((pp->primCol.b << 16) + t * (pp->primColTarget.b - pp->primCol.b)) >> 16);
        prim.a = (u8) ((s32) ((pp->primCol.a << 16) + t * (pp->primColTarget.a - pp->primCol.a)) >> 16);
    } else {
        prim = pp->primCol;
    }

    if (pp->envColCount != 0) {
        t = (s32)(pp->envColRemain << 16) / (s32) pp->envColCount;
        env.r = (u8) ((s32) ((pp->envCol.r << 16) + t * (pp->envColTarget.r - pp->envCol.r)) >> 16);
        env.g = (u8) ((s32) ((pp->envCol.g << 16) + t * (pp->envColTarget.g - pp->envCol.g)) >> 16);
        env.b = (u8) ((s32) ((pp->envCol.b << 16) + t * (pp->envColTarget.b - pp->envCol.b)) >> 16);
        env.a = (u8) ((s32) ((pp->envCol.a << 16) + t * (pp->envColTarget.a - pp->envCol.a)) >> 16);
    } else {
        env = pp->envCol;
    }

    if ((pp->kind & 0x80) || (!(pp->kind & 0x80000000) && !(pp->kind & 0x100000))) {
        if (prim.r != lbl_805DE3A0.r || prim.g != lbl_805DE3A0.g || prim.b != lbl_805DE3A0.b ||
            prim.a != lbl_805DE3A0.a) {
            lbl_805DE3A0 = prim;
            tmp = prim;
            GXSetTevColor(GX_TEVREG0, &tmp);
        }

        if (pp->kind & 0x80) {
            if (env.r != lbl_805DE39C.r || env.g != lbl_805DE39C.g || env.b != lbl_805DE39C.b ||
                env.a != lbl_805DE39C.a) {
                lbl_805DE39C = env;
                tmp = env;
                GXSetTevColor(GX_TEVREG1, &tmp);
            }
        } else if (lbl_805DE39C.r != 0 || lbl_805DE39C.g != 0 || lbl_805DE39C.b != 0 ||
                   lbl_805DE39C.a != 0) {
            lbl_805DE39C.a = 0;
            lbl_805DE39C.b = 0;
            lbl_805DE39C.g = 0;
            lbl_805DE39C.r = 0;
            tmp = lbl_805DE39C;
            GXSetTevColor(GX_TEVREG1, &tmp);
        }
    }

    if (pp->kind & 0x80000000) {
        if (pp->matColCount != 0) {
            t = (s32)(pp->matColRemain << 16) / (s32) pp->matColCount;
            mat.r = mat.g = mat.b =
                (u8) ((s32) ((pp->matRGB << 16) + t * (pp->matRGBTarget - pp->matRGB)) >> 16);
            mat.a = (u8) ((s32) ((pp->matA << 16) + t * (pp->matATarget - pp->matA)) >> 16);
        } else {
            mat.r = mat.g = mat.b = pp->matRGB;
            mat.a = pp->matA;
        }

        if (pp->kind & 0x80) {
            if (mat.r != lbl_805DE398.r || mat.g != lbl_805DE398.g || mat.b != lbl_805DE398.b ||
                mat.a != lbl_805DE398.a) {
                lbl_805DE398 = mat;
                tmp = mat;
                GXSetTevColor(GX_TEVREG2, &tmp);
            }
        } else {
            mat.a = (u8) ((s32) (mat.a * prim.a) >> 8);
            if (mat.r != lbl_805DE398.r || mat.g != lbl_805DE398.g || mat.b != lbl_805DE398.b ||
                mat.a != lbl_805DE398.a) {
                lbl_805DE398 = mat;
                tmp = mat;
                GXSetTevColor(GX_TEVREG2, &tmp);
            }
        }
    }
}

extern GXColor lbl_805DE3A4;
extern GXColor lbl_805DE3A8;

extern HSD_LObj* HSD_LObjGetActiveByID(u32 id);
extern void kar_grcoll__803cd2b8(s32 chan, GXColor* color);
extern void kar_grcoll__803cd3ac(s32 chan, GXColor* color);

void kar_psdisp__near_80437168(HSD_Particle* pp)
{
    GXColor amb;
    GXColor prim;
    GXColor tmp;
    HSD_LObj* light;
    s32 t;

    if (pp->kind & 0x80000000) {
        if (pp->ambColCount != 0) {
            t = (s32)(pp->ambColRemain << 16) / (s32) pp->ambColCount;
            amb.r = amb.g = amb.b =
                (u8) ((s32) ((pp->ambRGB << 16) + t * (pp->ambRGBTarget - pp->ambRGB)) >> 16);
            amb.a = (u8) ((s32) ((pp->ambA << 16) + t * (pp->ambATarget - pp->ambA)) >> 16);
        } else {
            amb.r = amb.g = amb.b = pp->ambRGB;
            amb.a = pp->ambA;
        }

        if (pp->kind & 0x80) {
            prim.r = prim.g = prim.b = 0xFF;
        } else {
            if (pp->primColCount != 0) {
                t = (s32)(pp->primColRemain << 16) / (s32) pp->primColCount;
                prim.r = (u8) ((s32) ((pp->primCol.r << 16) + t * (pp->primColTarget.r - pp->primCol.r)) >> 16);
                prim.g = (u8) ((s32) ((pp->primCol.g << 16) + t * (pp->primColTarget.g - pp->primCol.g)) >> 16);
                prim.b = (u8) ((s32) ((pp->primCol.b << 16) + t * (pp->primColTarget.b - pp->primCol.b)) >> 16);
                prim.a = (u8) ((s32) ((pp->primCol.a << 16) + t * (pp->primColTarget.a - pp->primCol.a)) >> 16);
            } else {
                prim = pp->primCol;
            }
            amb.r = (u8) ((s32) (amb.r * prim.r) >> 8);
            amb.g = (u8) ((s32) (amb.g * prim.g) >> 8);
            amb.b = (u8) ((s32) (amb.b * prim.b) >> 8);
        }

        if (prim.r != lbl_805DE3A8.r || prim.g != lbl_805DE3A8.g || prim.b != lbl_805DE3A8.b) {
            lbl_805DE3A8 = prim;
            tmp = prim;
            kar_grcoll__803cd3ac(0, &tmp);
        }

        light = HSD_LObjGetActiveByID(0x100);
        if (light != NULL) {
            HSD_MulColor(&amb, &light->color, &amb);
        } else {
            amb.r = amb.g = amb.b = 0;
        }

        if (amb.r != lbl_805DE3A4.r || amb.g != lbl_805DE3A4.g || amb.b != lbl_805DE3A4.b) {
            lbl_805DE3A4 = amb;
            tmp = amb;
            kar_grcoll__803cd2b8(0, &tmp);
        }
    }
}

#define GX_TEVSTAGE0 0
#define GX_TEVSTAGE1 1
#define GX_TEVSTAGE2 2
#define GX_TEXCOORD0 0
#define GX_TEXMAP0 0
#define GX_COLOR0A0 4

extern void GXSetTevOrder(u8 stage, u32 coord, u32 map, u32 color);
extern void GXSetTevSwapMode(u8 stage, u32 ras_swap, u32 tex_swap);
extern void fn_803CEC68(u8 stage, u32 op, u32 bias, u32 scale, u32 clamp, u32 out_reg);
extern void fn_803CECD0(u8 stage, u32 op, u32 bias, u32 scale, u32 clamp, u32 out_reg);

void kar_psdisp__near_804373dc(void)
{
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    fn_803CEC68(GX_TEVSTAGE0, 0, 0, 0, 1, 0);
    fn_803CECD0(GX_TEVSTAGE0, 0, 0, 0, 1, 0);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    fn_803CEC68(GX_TEVSTAGE1, 0, 0, 0, 1, 0);
    fn_803CECD0(GX_TEVSTAGE1, 0, 0, 0, 1, 0);
    GXSetTevOrder(GX_TEVSTAGE2, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    fn_803CEC68(GX_TEVSTAGE2, 0, 0, 0, 1, 0);
    fn_803CECD0(GX_TEVSTAGE2, 0, 0, 0, 1, 0);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    GXSetTevSwapMode(2, 0, 0);
}

extern s32 lbl_805DE3D8;

void kar_psdisp__near_8043750c(void)
{
    lbl_805DE3D8 = -1;
}

#define GX_CC_CPREV 0
#define GX_CC_C0 2
#define GX_CC_C1 4
#define GX_CC_C2 6
#define GX_CC_TEXC 8
#define GX_CC_RASC 10
#define GX_CC_ZERO 15

#define GX_CA_APREV 0
#define GX_CA_A0 1
#define GX_CA_A1 2
#define GX_CA_A2 3
#define GX_CA_TEXA 4
#define GX_CA_RASA 5
#define GX_CA_ZERO 7

#define GX_TEXCOORD_NULL 0xFF
#define GX_MODULATE 0

extern void GXSetNumTevStages(u8 n);
extern void GXSetNumTexGens(u8 n);
extern void GXSetTevColorIn(u8 stage, u32 a, u32 b, u32 c, u32 d);
extern void GXSetTevAlphaIn(u8 stage, u32 a, u32 b, u32 c, u32 d);
extern void GXSetTevOp(u8 stage, u32 mode);

void kar_psdisp__near_80437518(HSD_Particle* pp)
{
    s32 kind;

    kind = (s32) (pp->kind & 0x80100480);
    if (kind != lbl_805DE3D8) {
        lbl_805DE3D8 = kind;
        switch (kind) {
        case 0x80:
            pp->kind &= 0xFFFFFF7F;
            lbl_805DE3D8 &= 0xFFFFFF7F;
            /* fallthrough */
        case 0x0:
            GXSetNumTevStages(1);
            GXSetNumTexGens(0);
            GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
            GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_C0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
            GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_A0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
            return;
        case 0x400:
        case 0x480:
            GXSetNumTevStages(1);
            GXSetNumTexGens(1);
            GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
            GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_C1, GX_CC_C0, GX_CC_TEXC, GX_CC_ZERO);
            GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_A1, GX_CA_A0, GX_CA_TEXA, GX_CA_ZERO);
            return;
        case 0x100400:
            GXSetNumTevStages(1);
            GXSetNumTexGens(1);
            GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
            GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
            return;
        case 0x100480:
            GXSetNumTevStages(2);
            GXSetNumTexGens(1);
            GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
            GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_C1, GX_CC_C0, GX_CC_TEXC, GX_CC_ZERO);
            GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_A1, GX_CA_A0, GX_CA_TEXA, GX_CA_ZERO);
            GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_CPREV, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
            GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_RASA, GX_CA_APREV, GX_CA_ZERO);
            return;
        case 0x100080:
            pp->kind &= 0xFFFFFF7F;
            lbl_805DE3D8 &= 0xFFFFFF7F;
            /* fallthrough */
        case 0x100000:
            GXSetNumTevStages(1);
            GXSetNumTexGens(0);
            GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
            GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_RASC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
            GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_RASA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
            return;
        case 0x80000080:
            pp->kind &= 0xFFFFFF7F;
            lbl_805DE3D8 &= 0xFFFFFF7F;
            /* fallthrough */
        case 0x80000000:
            GXSetNumTevStages(2);
            GXSetNumTexGens(0);
            GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
            GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_C2, GX_CC_RASC, GX_CC_ZERO);
            GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_A2, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
            GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_C0, GX_CC_CPREV, GX_CC_ZERO);
            GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_A0, GX_CA_APREV, GX_CA_ZERO);
            return;
        case 0x80000480:
            GXSetNumTevStages(3);
            GXSetNumTexGens(1);
            GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
            GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_C1, GX_CC_C0, GX_CC_TEXC, GX_CC_ZERO);
            GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_A1, GX_CA_A0, GX_CA_TEXA, GX_CA_ZERO);
            GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_C2, GX_CC_CPREV, GX_CC_ZERO);
            GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_A2, GX_CA_APREV, GX_CA_ZERO);
            GXSetTevColorIn(GX_TEVSTAGE2, GX_CC_ZERO, GX_CC_RASC, GX_CC_CPREV, GX_CC_ZERO);
            GXSetTevAlphaIn(GX_TEVSTAGE2, GX_CA_APREV, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
            return;
        case 0x80000400:
            GXSetNumTevStages(2);
            GXSetNumTexGens(1);
            GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
            GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_C2, GX_CC_RASC, GX_CC_ZERO);
            GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_A2, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
            GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_TEXC, GX_CC_CPREV, GX_CC_ZERO);
            GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_TEXA, GX_CA_APREV, GX_CA_ZERO);
            return;
        case 0x80100080:
            pp->kind &= 0xFFFFFF7F;
            lbl_805DE3D8 &= 0xFFFFFF7F;
            /* fallthrough */
        case 0x80100000:
            GXSetNumTevStages(2);
            GXSetNumTexGens(0);
            GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
            GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_C2, GX_CC_RASC, GX_CC_ZERO);
            GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_A2, GX_CA_RASA, GX_CA_ZERO);
            GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_C0, GX_CC_CPREV, GX_CC_ZERO);
            GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_A0, GX_CA_APREV, GX_CA_ZERO);
            return;
        case 0x80100400:
            GXSetNumTevStages(2);
            GXSetNumTexGens(1);
            GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
            GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_C2, GX_CC_RASC, GX_CC_ZERO);
            GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_A2, GX_CA_RASA, GX_CA_ZERO);
            GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_TEXC, GX_CC_CPREV, GX_CC_ZERO);
            GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_TEXA, GX_CA_APREV, GX_CA_ZERO);
            return;
        case 0x80100480:
            GXSetNumTevStages(3);
            GXSetNumTexGens(1);
            GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
            GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_C1, GX_CC_C0, GX_CC_TEXC, GX_CC_ZERO);
            GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_A1, GX_CA_A0, GX_CA_TEXA, GX_CA_ZERO);
            GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_C2, GX_CC_CPREV, GX_CC_ZERO);
            GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_A2, GX_CA_APREV, GX_CA_ZERO);
            GXSetTevColorIn(GX_TEVSTAGE2, GX_CC_ZERO, GX_CC_RASC, GX_CC_CPREV, GX_CC_ZERO);
            GXSetTevAlphaIn(GX_TEVSTAGE2, GX_CA_ZERO, GX_CA_RASA, GX_CA_APREV, GX_CA_ZERO);
            return;
        }
    }
}

s32 kar_psdisp__near_80437bf0(s32 num, s32 size)
{
    HSD_psAppSRT* node;
    s32 i;

    lbl_805DE3E0 = (u16) size;
    lbl_805DE362 = 0;
    lbl_805DE35C = 0;
    lbl_805DE3E4 = NULL;

    for (i = 0; i < num; i++) {
        node = HSD_Alloc(size);
        if (node == NULL) {
            return i;
        }
        memset(node, 0, size);
        node->next = lbl_805DE3E4;
        lbl_805DE3E4 = node;
    }
    return i;
}

void kar_psdisp__near_80437c90(void)
{
    HSD_psAppSRT* node;
    HSD_psAppSRT* next;

    for (node = lbl_805DE3E4; node != NULL; node = next) {
        next = node->next;
        HSD_Free(node);
    }
    lbl_805DE3E4 = NULL;
}

void kar_psdisp__near_80437cd8(HSD_Generator* gp, s32 status)
{
    HSD_psAppSRT* srt;
    u16 idnum;
    u16 used;

    idnum = gp->idnum;
    if (lbl_805DE3E4 == NULL) {
        srt = HSD_Alloc(lbl_805DE3E0);
        lbl_805DE3E4 = srt;
        if (srt != NULL) {
            memset(srt, 0, lbl_805DE3E0);
        }
    }

    srt = lbl_805DE3E4;
    if (srt != NULL) {
        lbl_805DE3E4 = srt->next;
        srt->next = NULL;
        srt->usedCount = 1;
        srt->frameNum = 0;
        srt->status = status;
        srt->translate.z = 0.0F;
        srt->translate.y = 0.0F;
        srt->translate.x = 0.0F;
        srt->rot.z = 0.0F;
        srt->rot.y = 0.0F;
        srt->rot.x = 0.0F;
        srt->scale.z = 1.0F;
        srt->scale.y = 1.0F;
        srt->scale.x = 1.0F;
        srt->unk30.z = 0.0F;
        srt->unk30.y = 0.0F;
        srt->unk30.x = 0.0F;
        srt->freefunc = NULL;
        srt->xA2 = 0;
        srt->gp = NULL;
        srt->idnum = idnum;

        used = lbl_805DE362 + 1;
        lbl_805DE362 = used;
        if (used > lbl_805DE35C) {
            lbl_805DE35C = used;
        }
    }
    gp->appsrt = srt;
}

s32 kar_psdisp__near_80437ddc(HSD_Particle* pp, HSD_psAppSRT* srt)
{
    if (srt == NULL || pp == NULL || pp->appsrt != NULL) {
        return -1;
    }
    pp->appsrt = srt;
    return (u16) ++srt->usedCount;
}

s32 kar_psdisp__near_80437e18(HSD_Generator* gp, HSD_psAppSRT* srt)
{
    if (srt == NULL || gp == NULL || gp->appsrt != NULL) {
        return -1;
    }
    gp->appsrt = srt;
    return (u16) ++srt->usedCount;
}

s32 kar_psdisp__near_80437e54(HSD_Particle* pp, HSD_psAppSRT* srt)
{
    if (srt == NULL || pp == NULL) {
        return -1;
    }
    if (pp->appsrt != NULL) {
        psRemoveParticleAppSRT(pp);
    }
    pp->appsrt = srt;
    return (u16) ++srt->usedCount;
}

s32 kar_psdisp__near_80437ec0(HSD_Generator* gp, HSD_psAppSRT* srt)
{
    if (srt == NULL || gp == NULL) {
        return -1;
    }
    if (gp->appsrt != NULL) {
        kar_psdisp__near_80437fcc(gp);
    }
    gp->appsrt = srt;
    return (u16) ++srt->usedCount;
}

s32 psRemoveParticleAppSRT(HSD_Particle* pp)
{
    HSD_psAppSRT* srt;
    s32 count;

    srt = pp->appsrt;
    if (srt == NULL) {
        return -1;
    }
    count = --srt->usedCount;
    if (count == 0) {
        srt = pp->appsrt;
        if (srt->freefunc != NULL) {
            srt->freefunc(srt);
        }
        srt->next = lbl_805DE3E4;
        lbl_805DE3E4 = srt;
        lbl_805DE362--;
    }
    pp->appsrt = NULL;
    return count;
}

s32 kar_psdisp__near_80437fcc(HSD_Generator* gp)
{
    HSD_psAppSRT* srt;
    s32 count;

    srt = gp->appsrt;
    if (srt == NULL) {
        return -1;
    }
    if (srt->gp == gp) {
        srt->gp = NULL;
    }
    srt = gp->appsrt;
    count = --srt->usedCount;
    if (count == 0) {
        srt = gp->appsrt;
        if (srt->freefunc != NULL) {
            srt->freefunc(srt);
        }
        srt->next = lbl_805DE3E4;
        lbl_805DE3E4 = srt;
        lbl_805DE362--;
    }
    gp->appsrt = NULL;
    return count;
}

s32 kar_psdisp__near_80438084(s32 num)
{
    s32 i;
    void* node;

    for (i = 0; i != 32; i++) {
        lbl_8058CCE8[i] = NULL;
        ((u32*) ((u8*) lbl_8058CCE8 + 0x80))[i] = 0;
        ((u32*) ((u8*) lbl_8058CCE8 + 0x100))[i] = 0;
    }

    lbl_805DE3E8.head = NULL;

    for (i = num - 1; i >= 0; i--) {
        node = HSD_Alloc(0xB0);
        memset(node, 0, 0xB0);
        if (node == NULL) {
            return -1;
        }
        *(void**) node = lbl_805DE3E8.head;
        lbl_805DE3E8.head = node;
    }
    return i;
}

void kar_psdisp__near_80438190(void)
{
    void* node;
    void* next;
    s32 i;

    for (node = lbl_805DE3E8.head; node != NULL; node = next) {
        next = *(void**) node;
        HSD_Free(node);
    }
    lbl_805DE3E8.head = NULL;

    for (i = 0; i < 32; i++) {
        for (node = lbl_8058CCE8[i]; node != NULL; node = next) {
            next = *(void**) node;
            HSD_Free(node);
        }
        lbl_8058CCE8[i] = NULL;
        ((u32*) ((u8*) lbl_8058CCE8 + 0x80))[i] = 0;
        ((u32*) ((u8*) lbl_8058CCE8 + 0x100))[i] = 0;
    }
}

void* kar_psdisp__near_80438238(void** dst, u32 bank)
{
    void* node;
    void* head;
    u16 used;

    if (lbl_805DE3E8.head == NULL) {
        lbl_805DE3E8.head = HSD_Alloc(0xB0);
        memset(lbl_805DE3E8.head, 0, 0xB0);
    }

    head = lbl_805DE3E8.head;
    if (head == NULL) {
        return NULL;
    }
    node = head;

    used = lbl_805DE366 + 1;
    lbl_805DE366 = used;
    if (used > lbl_805DE360) {
        lbl_805DE360 = used;
    }

    lbl_805DE3E8.head = *(void**) node;
    if (dst == NULL) {
        *(void**) node = lbl_8058CCE8[bank];
        lbl_8058CCE8[bank] = node;
    } else {
        *(void**) node = *dst;
        *dst = node;
    }
    lbl_8058CD68[bank] = 1;
    return node;
}
