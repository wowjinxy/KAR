#include <global.h>
#include <sysdolphin/psdisp.h>
#include <sysdolphin/memory.h>
#include <sysdolphin/lobj.h>
#include <sysdolphin/util.h>
#include <sysdolphin/mtx.h>

void memset(void*, int, int);

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

extern void kar_generator__near_804333d4(HSD_Particle* pp, f32* dx, f32* dy, f32* dz);

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

static struct {
    Mtx m;
    u32 unk30;
} lbl_8058CCB4;

extern void GXSetPointSize(u8 size, u32 tex_offsets);
extern void PSMTXCopy(Mtx src, Mtx dst);
extern void PSMTXMultVec(Mtx mtx, Vec* src, Vec* dst);
extern void kar_generator__near_80433e54(HSD_Particle* pp, f32* dx, f32* dy, f32* dz);

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
