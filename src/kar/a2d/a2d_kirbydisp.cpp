#include <dolphin/types.h>
#include <dolphin/gx/gxtypes.h>

extern "C" {
#include <global.h>
}

class RefObj {
public:
    virtual void Release(s32);
};

class DiagObj {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual DiagObj *GetNext();
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

struct HSD_Material {
    GXColor ambient;  //0x00
    GXColor diffuse;  //0x04
    GXColor specular; //0x08
    f32 alpha;        //0x0C
    f32 shininess;    //0x10
};

struct HSD_MObj {
    void *classInfo;   //0x00
    u32 rendermode;     //0x04
    void *tobj;          //0x08
    HSD_Material *mat;    //0x0C
    void *pe;              //0x10
    void *aobj;              //0x14
    void *tevdesc;            //0x18
    void *texp;                //0x1C
};

struct HSD_PObj {
    void *classInfo; //0x00
    void *next;       //0x04
    void *verts;       //0x08
    u16 flags;           //0x0C
    u16 n_display;         //0x0E
    u8 *display;             //0x10
    void *u;                   //0x14
    void *aobj;                  //0x18
};

struct HSD_VtxDescList {
    s32 attr;      //0x00
    s32 attr_type;   //0x04
    s32 comp_cnt;      //0x08
    s32 comp_type;       //0x0C
    u8 frac;                //0x10
    u16 stride;               //0x12
    void *vertex;               //0x14
};

class KirbyEffectListItem {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual KirbyEffectListItem *GetNext();
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

struct KirbyDispModeArg {
    char pad0[0xC];
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
};

struct KirbyFlashSrc {
    s32 pad0[3];
    s32 unkC;
    s32 pad14[5];
    s32 unk24;
};

struct GameScriptTarget {
    char pad0[0xC];
    void *unkC;
    s32 unk10;
    s32 pad14;
    s32 unk18;
    s32 unk1C;
    u8 unk20;
    u8 unk21;
};

struct SlideBlurDesc {
    s32 word0;
    s32 word1;
    void *ptr;
    u8 b0, b1, b2, b3, b4, b5;
};

struct MObjInfoSetupSlot {
    char pad[0x3C];
    void *setup;
};

struct DObjInfoDispSlot {
    char pad[0x3C];
    void *disp;
};

struct PObjInfoLoadSlot {
    char pad[0x44];
    void *load;
};

extern "C" {

void kar_lbarchive__near_80059520(s32, void *, const char *, ...);

void GXSetTevColor(s32, GXColor);
void GXSetNumTexGens(u32);
void GXSetTexCoordGen2(s32, s32, s32, u32, s32, u32);
void GXLoadTexMtxImm(void *, u32, s32);
void GXSetNumChans(u32);
void GXSetNumTevStages(u32);
void GXSetTevOrder(s32, s32, s32, s32);
void GXSetTevColorIn(s32, s32, s32, s32, s32);
void GXSetTevAlphaIn(s32, s32, s32, s32, s32);
void GXSetNumIndStages(s32);
void GXSetIndTexCoordScale(s32, s32, s32);
void GXSetTevIndirect(s32, s32, s32, s32, s32, s32, s32, s32);
void GXSetColorUpdate(s32);
void GXSetAlphaUpdate(s32);
void GXSetZMode(s32, s32, s32);
void GXSetZCompLoc(s32);
void GXSetBlendMode(s32, s32, s32, s32);
void GXSetAlphaCompare(s32, u32, s32, s32, u32);
void GXSetDither(s32);
void GXSetTevDirect(s32);
void GXInvalidateVtxCache(void);
void GXInvalidateTexAll(void);

void fn_803CEC68(s32, s32, s32, s32, s32, s32);
void fn_803CECD0(s32, s32, s32, s32, s32, s32);
void fn_803CE8E0(s32, s32, s32);
void fn_803CE604(s32, void *, s32);

void hsdInitClassInfo(void *, void *, void *, void *, s32, s32);

void HSD_MObjSetup(HSD_MObj *, u32);
void HSD_DObjDisp(void *, void *, void *, u32);
void HSD_JObjSetDefaultClass(void *);
void HSD_DObjSetDefaultClass(void *);
void *kar_fl_indirectload__803f9fa4(void *);
void HSD_PObjSetCurrent(void *);

void HSD_StateInitTev(void);
void HSD_SetMaterialColor(GXColor, GXColor, GXColor, f32);
void HSD_TObjSetup(void *);
void HSD_TObjSetupTextureCoordGen(void *);
void HSD_TExpSetupTev(void *, void *);
void HSD_TObjSetupVolatileTev(void *, u32);
void HSD_SetupRenderModeWithCustomPE(u32, void *);
u32 HSD_StateAssignTev(void);
void HSD_SetupTevStage(void *);
void HSD_StateInvalidate(s32);

u8 kar_a2d_effect_slideblur__near_80382d18(s32, void *, void *, void *);
void kar_a2d_game_lib__8028b460(void *);

void HSD_CObjEndCurrent(void);
BOOL HSD_CObjSetCurrent(void *);
void HSD_StateSetColorUpdate(u32);
void kar_psdisp__80433f00(u32, s32);
void kar_a2d_effecthandle__near_8037dc54(void *, s32);

void *kar_diag__803ad760(s32, s32, void *, void *, s32);

void *kar_a2d_refract__80383f6c(void *, void *, void *);
void kar_a2d_refract__near_803842e8(void *, void *);

void DCFlushRange(void *, u32);

u32 HSD_FObjGetFlags(HSD_PObj *);

extern char hsdMObj[0x54];
extern char hsdDObj[0x48];
extern char hsdPObj[0x4C];

void kar_a2d_kirbydisp__80382e10(HSD_MObj *, u32);
void kar_a2d_kirbydisp__near_80383a5c(void *, u32, GXColor *, GXColor *);
void kar_a2d_kirbydisp__near_80383c98(void *, void *, void *, u32);

namespace {
extern "C" void kar_a2d_kirbydisp__near_80383c98(void);
}
s32 kar_a2d_kirbydisp__near_80383ce0(HSD_PObj *, void *);
void kar_a2d_kirbydisp__near_8038397c(GXColor *, KirbyFlashSrc *);

extern s32 lbl_805DDC80;

}

namespace {
extern "C" void HSD_SetMaterialColor(GXColor, GXColor, GXColor, HSD_Material *, f32);
}

extern "C" {

union KirbyFlashColor {
    s32 whole;
    struct {
        u8 unk0;
        u8 unk1;
        u8 unk2;
        u8 unk3;
    } b;
};
extern KirbyFlashColor lbl_805DDC84;

extern char lbl_804F43D0[];
extern char lbl_804BDFD8[0xC];
extern char lbl_804BE050[0xC];
extern char lbl_805699B0[0x38];
extern char lbl_804F4910[0x30];
extern char lbl_804F4940[0x18];

extern char lbl_804F46A8[];
extern char lbl_804F4698[];
extern char lbl_804F46C4[];
extern char lbl_804F46DC[];
extern char lbl_804F46D0[];
extern char lbl_804F46F4[];
extern char lbl_804F4700[];
extern char lbl_804F4760[];

}

s32 lbl_805DDAC4, lbl_805DDAC8, lbl_805DDACC, lbl_805DDAD0, lbl_805DDAD4, lbl_805DDAD8, lbl_805DDADC,
    lbl_805DDAE0, lbl_805DDAE4, lbl_805DDAE8, lbl_805DDAEC, lbl_805DDAF0, lbl_805DDAF4, lbl_805DDAF8,
    lbl_805DDAFC, lbl_805DDB00, lbl_805DDB04, lbl_805DDB08, lbl_805DDB0C, lbl_805DDB10, lbl_805DDB14,
    lbl_805DDB18, lbl_805DDB1C, lbl_805DDB20, lbl_805DDB24, lbl_805DDB28, lbl_805DDB2C, lbl_805DDB30,
    lbl_805DDB34, lbl_805DDB38, lbl_805DDB3C, lbl_805DDB40, lbl_805DDB44, lbl_805DDB48, lbl_805DDB4C,
    lbl_805DDB50, lbl_805DDB54, lbl_805DDB58, lbl_805DDB5C, lbl_805DDB60, lbl_805DDB64, lbl_805DDB68,
    lbl_805DDB6C, lbl_805DDB70, lbl_805DDB74, lbl_805DDB78, lbl_805DDB7C, lbl_805DDB80, lbl_805DDB84,
    lbl_805DDB88, lbl_805DDB8C, lbl_805DDB90, lbl_805DDB94, lbl_805DDB98, lbl_805DDB9C, lbl_805DDBA0,
    lbl_805DDBA4, lbl_805DDBA8, lbl_805DDBAC, lbl_805DDBB0, lbl_805DDBB4, lbl_805DDBB8, lbl_805DDBBC,
    lbl_805DDBC0, lbl_805DDBC4, lbl_805DDBC8, lbl_805DDBCC, lbl_805DDBD0, lbl_805DDBD4;

struct NamePair {
    char *a;
    char *b;
};

static char lbl_805DBF90[2] = "0";
static NamePair lbl_805DBF94 = {lbl_804F46A8, 0};
static NamePair lbl_805DBF9C = {lbl_804F4698, lbl_804F46C4};
static NamePair lbl_805DBFA4 = {lbl_804F46DC, 0};
static NamePair lbl_805DBFAC = {lbl_804F46D0, lbl_804F46F4};
static NamePair lbl_805DBFB4 = {lbl_804F4700, 0};
struct NameTriple {
    char *a;
    s32 b;
    s32 c;
};
static NameTriple lbl_805DBFBC = {lbl_804F4760, 0, 0};

static char lbl_804F47A0[0xB] = "GameScript";

static u32 lbl_804F47AC[0x59] = {
    0x4F626A43, 0x6F6C6C65, 0x63743C47, 0x616D6553, 0x63726970, 0x743E0000,
    0, 0x00000000,
    0x00000000, 0x02000000, 0x00000000, 0x04000000, 0xF2F2F200, 0x01000000, 0x00000002, 0x04000000,
    0x00000000, 0x01000000, 0x00000002, 0x03000000, 0x00000008, 0x05000000, 0x00000000, 0x02000000,
    0x00000000, 0x04000000, 0xF2F2F200, 0x01000000, 0x00000002, 0x04000000, 0x00000000, 0x01000000,
    0x00000002, 0x03000000, 0x00000005, 0x05000000, 0x00000000, 0x04000000, 0xF2F2F200, 0x01000000,
    0x00000003, 0x04000000, 0x00000000, 0x01000000, 0x00000003, 0x05000000, 0x00000000, 0x02000000,
    0x00000000, 0x04000000, 0xC0C0C000, 0x01000000, 0x00000004, 0x04000000, 0x00000000, 0x01000000,
    0x00000002, 0x03000000, 0xFFFFFFFF, 0x05000000, 0x00000000, 0x02000000, 0x00000000, 0x04000000,
    0xF2F2F200, 0x01000000, 0x00000004, 0x04000000, 0x00000000, 0x01000000, 0x00000002, 0x03000000,
    0xFFFFFFFF, 0x05000000, 0x00000000, 0x02000000, 0x00000000, 0x04000000, 0xFF401000, 0x01000000,
    0x00000003, 0x04000000, 0x00000000, 0x01000000, 0x00000001, 0x03000000, 0xFFFFFFFF, 0x05000000,
    0x00000000,
};

static NamePair lbl_805DBFC8 = {(char *) lbl_804F47AC, 0};

extern "C" void kar_a2d_kirbydisp__80382e10(HSD_MObj *arg0, u32 arg1) {
    switch (lbl_805DDC80) {
    case 2: {
        KirbyFlashColor sp44 = lbl_805DDC84;
        f32 avg = (f32) (sp44.b.unk0 + sp44.b.unk1 + sp44.b.unk2) / 3.0f;
        u8 delta = 0xFF - (u8) avg;
        u8 out0 = (delta + sp44.b.unk0 <= 0xFF) ? (delta + sp44.b.unk0) : 0xFF;
        u8 out1 = (delta + sp44.b.unk1 <= 0xFF) ? (delta + sp44.b.unk1) : 0xFF;
        u8 out2 = (delta + sp44.b.unk2 <= 0xFF) ? (delta + sp44.b.unk2) : 0xFF;
        s32 sp50 = out0;
        s32 sp10 = (s8) ((f32) (u8) sp50 * 0.1f);
        s32 sp48 = (s32) sp10;
        s32 sp58 = (u8) sp48;
        KirbyFlashColor sp54;
        sp54.b.unk0 = (u8) sp58;
        sp54.b.unk1 = out1;
        sp54.b.unk2 = out2;
        sp54.b.unk3 = sp44.b.unk3;
        kar_a2d_kirbydisp__near_80383a5c(arg0, arg1, (GXColor *) &sp54, (GXColor *) &sp54);
        return;
    }
    case 3: {
        KirbyFlashColor sp38 = lbl_805DDC84;
        f32 avg = (f32) (sp38.b.unk0 + sp38.b.unk1 + sp38.b.unk2) / 3.0f;
        u8 delta = 0xFF - (u8) avg;
        u8 out0 = (delta + sp38.b.unk0 <= 0xFF) ? (delta + sp38.b.unk0) : 0xFF;
        u8 out1 = (delta + sp38.b.unk1 <= 0xFF) ? (delta + sp38.b.unk1) : 0xFF;
        u8 out2 = (delta + sp38.b.unk2 <= 0xFF) ? (delta + sp38.b.unk2) : 0xFF;
        s32 sp3C = out0;
        KirbyFlashColor sp58;
        sp58.b.unk0 = (u8) sp3C;
        sp58.b.unk1 = out1;
        sp58.b.unk2 = out2;
        sp58.b.unk3 = sp38.b.unk3;
        kar_a2d_kirbydisp__near_80383a5c(arg0, arg1, (GXColor *) &sp58, (GXColor *) &sp58);
        return;
    }
    case 1:
    case 4: {
        KirbyFlashColor sp24 = lbl_805DDC84;
        HSD_StateInitTev();
        u32 rendermode = arg0->rendermode;
        GXColor amb = arg0->mat->ambient;
        GXColor dif = arg0->mat->diffuse;
        GXColor spec = arg0->mat->specular;
        HSD_SetMaterialColor(amb, dif, spec, arg0->mat, arg0->mat->alpha);
        void *tobj = arg0->tobj;
        HSD_TObjSetup(tobj);
        HSD_TObjSetupTextureCoordGen(tobj);
        if (arg0->tevdesc == NULL) {
            __assert(lbl_804F43D0 + 0x25C, 0xE9, lbl_804F43D0 + 0x270);
        }
        HSD_TExpSetupTev(arg0->tevdesc, arg0->texp);
        u32 masked = rendermode & 0xFFFFFFF7;
        HSD_TObjSetupVolatileTev(tobj, masked);
        s32 sp20 = sp24.whole;
        u8 var_r31 = kar_a2d_effect_slideblur__near_80382d18(0, arg0->tevdesc, arg0->texp, NULL);
        SlideBlurDesc local = *(SlideBlurDesc *) (lbl_804F43D0 + 0x208);
        local.word1 = 0;
        local.ptr = &sp20;
        local.b2 = var_r31;
        kar_a2d_game_lib__8028b460(&local);
        u8 temp_ret = kar_a2d_effect_slideblur__near_80382d18((var_r31 != 4) ? 4 : 0, arg0->tevdesc, arg0->texp, &local);
        s8 temp_r3 = (s8) temp_ret;
        if (temp_r3 == -1) {
            OSReport(lbl_804F43D0 + 0x280);
            __assert(lbl_804F43D0 + 0x25C, 0x105, lbl_805DBF90);
        }
        local.word1 = 0;
        local.b2 = temp_ret;
        local.ptr = &sp20;
        kar_a2d_game_lib__8028b460(&local);
        struct TevStageBuf {
            s32 words[0x70 / 4];
        };
        TevStageBuf stage_buf_s = *(TevStageBuf *) (lbl_804F43D0 + 0x190);
        char *stage_buf = (char *) &stage_buf_s;
        s32 stage = HSD_StateAssignTev();
        *(s32 *) (stage_buf + 0x8) = stage;
        s32 *tbl1 = (s32 *) (lbl_804F43D0 + 0x21C);
        *(s32 *) (stage_buf + 0x20) = tbl1[var_r31];
        *(s32 *) (stage_buf + 0x24) = tbl1[temp_r3];
        if (var_r31 < 4) {
            s32 *tbl2 = (s32 *) (lbl_804F43D0 + 0x23C);
            *(s32 *) (stage_buf + 0x6C) = tbl2[var_r31];
        } else if (temp_r3 < 4) {
            s32 *tbl2 = (s32 *) (lbl_804F43D0 + 0x23C);
            *(s32 *) (stage_buf + 0x6C) = tbl2[temp_r3];
        }
        HSD_SetupTevStage(stage_buf);
        HSD_SetupRenderModeWithCustomPE(masked, arg0->pe);
        return;
    }
    default:
        HSD_MObjSetup(arg0, arg1);
        return;
    }
}

extern "C" void kar_a2d_kirbydisp__near_80383458(void) {
    char * const base = lbl_804F43D0;
    hsdInitClassInfo(base + 0x84, hsdMObj, base + 0x16C, base + 0x184, 0x54, 0x20);
    ((MObjInfoSetupSlot *) (base + 0x84))->setup = (void *) kar_a2d_kirbydisp__80382e10;
}

extern "C" void kar_a2d_kirbydisp__near_803834b4(void *dobj, void *vmtx, void *pmtx, u32 rendermode) {
    if (lbl_805DDC80 < 4) {
        if (lbl_805DDC80 < 2) {
            goto block_4;
        }
        kar_a2d_kirbydisp__near_80383c98();
        return;
    }
block_4:
    HSD_DObjDisp(dobj, vmtx, pmtx, rendermode);
}

extern "C" void kar_a2d_kirbydisp__near_803834f4(void) {
    char * const base = lbl_804F43D0;
    hsdInitClassInfo(base + 0xD8, hsdDObj, base + 0x16C, base + 0x2A8, 0x48, 0x18);
    ((DObjInfoDispSlot *) (base + 0xD8))->disp = (void *) kar_a2d_kirbydisp__near_803834b4;
}

extern "C" void kar_a2d_kirbydisp__near_80383550(void) {
    char * const base = lbl_804F43D0;
    hsdInitClassInfo(base + 0x120, hsdPObj, base + 0x16C, base + 0x2B8, 0x4C, 0x1C);
    ((PObjInfoLoadSlot *) (base + 0x120))->load = (void *) kar_a2d_kirbydisp__near_80383ce0;
}

extern "C" void kar_a2d_kirbydisp__near_803835ac(void) {
    char * const base = lbl_804F43D0;
    HSD_JObjSetDefaultClass(base + 0x30);
    HSD_DObjSetDefaultClass(base + 0xD8);
    kar_fl_indirectload__803f9fa4(base + 0x84);
    HSD_PObjSetCurrent(base + 0x120);
}

extern "C" void kar_a2d_kirbydisp__near_803835f8(void) {
    HSD_JObjSetDefaultClass(NULL);
    HSD_DObjSetDefaultClass(NULL);
    kar_fl_indirectload__803f9fa4(NULL);
    HSD_PObjSetCurrent(NULL);
}

extern "C" void kar_a2d_kirbydisp__near_80383634(KirbyDispModeArg *arg0) {
    GXColor sp8;
    s32 temp_r0;

    lbl_805DDC80 = arg0->unkC;
    temp_r0 = arg0->unkC;
    if (temp_r0 != 4) {
        if (temp_r0 < 4) {
            if (temp_r0 != 1) {
                if (temp_r0 < 1) {
                    return;
                }
                lbl_805DDC84.b.unk0 = arg0->unk10;
                lbl_805DDC84.b.unk1 = arg0->unk11;
                lbl_805DDC84.b.unk2 = arg0->unk12;
                lbl_805DDC84.b.unk3 = arg0->unk13;
                return;
            }
            goto block_6;
        }
    } else {
block_6:
        kar_a2d_kirbydisp__near_8038397c(&sp8, (KirbyFlashSrc *) ((char *) arg0 + 0x14));
        lbl_805DDC84.b.unk0 = sp8.r;
        lbl_805DDC84.b.unk1 = sp8.g;
        lbl_805DDC84.b.unk2 = sp8.b;
        lbl_805DDC84.b.unk3 = sp8.a;
    }
}

extern "C" void kar_a2d_kirbydisp__near_803836d4(KirbyDispModeArg *arg0) {
    GXColor sp8;
    s32 temp_r0;
    s32 temp_r0_2;

    temp_r0 = arg0->unkC;
    if (temp_r0 == 1 || temp_r0 == 3) {
        lbl_805DDC80 = 0;
    } else {
        lbl_805DDC80 = temp_r0;
    }
    temp_r0_2 = arg0->unkC;
    if (temp_r0_2 != 4) {
        if (temp_r0_2 < 4) {
            if (temp_r0_2 != 1) {
                if (temp_r0_2 < 1) {
                    return;
                }
                lbl_805DDC84.b.unk0 = arg0->unk10;
                lbl_805DDC84.b.unk1 = arg0->unk11;
                lbl_805DDC84.b.unk2 = arg0->unk12;
                lbl_805DDC84.b.unk3 = arg0->unk13;
                return;
            }
            goto block_10;
        }
    } else {
block_10:
        kar_a2d_kirbydisp__near_8038397c(&sp8, (KirbyFlashSrc *) ((char *) arg0 + 0x14));
        lbl_805DDC84.b.unk0 = sp8.r;
        lbl_805DDC84.b.unk1 = sp8.g;
        lbl_805DDC84.b.unk2 = sp8.b;
        lbl_805DDC84.b.unk3 = sp8.a;
    }
}

extern "C" void kar_a2d_kirbydisp__near_80383790(KirbyDispModeArg *arg0) {
    GXColor sp8;
    s32 temp_r0;
    s32 var_r0;

    var_r0 = arg0->unkC;
    if (var_r0 != 3) {
        var_r0 = 0;
    }
    lbl_805DDC80 = var_r0;
    temp_r0 = arg0->unkC;
    if (temp_r0 != 4) {
        if (temp_r0 < 4) {
            if (temp_r0 != 1) {
                if (temp_r0 < 1) {
                    return;
                }
                lbl_805DDC84.b.unk0 = arg0->unk10;
                lbl_805DDC84.b.unk1 = arg0->unk11;
                lbl_805DDC84.b.unk2 = arg0->unk12;
                lbl_805DDC84.b.unk3 = arg0->unk13;
                return;
            }
            goto block_8;
        }
    } else {
block_8:
        kar_a2d_kirbydisp__near_8038397c(&sp8, (KirbyFlashSrc *) ((char *) arg0 + 0x14));
        lbl_805DDC84.b.unk0 = sp8.r;
        lbl_805DDC84.b.unk1 = sp8.g;
        lbl_805DDC84.b.unk2 = sp8.b;
        lbl_805DDC84.b.unk3 = sp8.a;
    }
}

extern "C" void **kar_a2d_kirbydisp__near_8038383c(void **arg0) {
    *arg0 = (void *) lbl_804BDFD8;
    lbl_805DDBD0 = (s32) arg0;
    *arg0 = (void *) lbl_804BE050;
    kar_a2d_refract__80383f6c((char *) arg0 + 4, lbl_804BE050, arg0);
    lbl_805DDC80 = 0;
    lbl_805DDC84.b.unk0 = 0;
    lbl_805DDC84.b.unk1 = 0;
    lbl_805DDC84.b.unk2 = 0;
    return arg0;
}

extern "C" void kar_a2d_kirbydisp__near_803838a8(void *arg0) {
    u8 var_r31 = 0;
    KirbyEffectListItem *var_r3 = (KirbyEffectListItem *) kar_diag__803ad760(lbl_805DDAC4, 0, &lbl_805DBF9C, &lbl_805DBF94, 0);
    while (var_r3 != NULL) {
        if (var_r3->unkC == 2 || var_r3->unkC == 3) {
            var_r31 = 1;
            break;
        }
        var_r3 = var_r3->GetNext();
    }
    if (var_r31 != 0) {
        KirbyEffectListItem *ctx = (KirbyEffectListItem *) kar_diag__803ad760(lbl_805DDB7C, 0, &lbl_805DBFAC, &lbl_805DBFA4, 0);
        kar_a2d_refract__near_803842e8((char *) arg0 + 4, (void *) ctx->unk8);
    }
}

extern "C" void kar_a2d_kirbydisp__near_8038395c(void) {
    lbl_805DDC80 = 0;
    lbl_805DDC84.b.unk0 = 0;
    lbl_805DDC84.b.unk1 = 0;
    lbl_805DDC84.b.unk2 = 0;
}

extern "C" void fn_80383978(void) {
}

extern "C" void kar_a2d_kirbydisp__near_8038397c(GXColor *arg0, KirbyFlashSrc *arg1) {
    if ((u32) arg1->unkC != 0U) {
        *(s32 *) arg0 = arg1->unk24;
        return;
    }
    GXColor z;
    z.r = 0;
    z.g = 0;
    z.b = 0;
    z.a = 0;
    *(s32 *) arg0 = *(s32 *) &z;
}

extern "C" void kar_a2d_kirbydisp__near_803839bc(GameScriptTarget *arg0, s32 arg1) {
    char *base = lbl_804F47A0;
    void *var_r4;

    switch (arg1) {
    case 0:
        var_r4 = base + 0xC8;
        break;
    case 1:
        var_r4 = base + 0x100;
        break;
    case 2:
        var_r4 = base + 0x138;
        break;
    case 3:
        var_r4 = base + 0x68;
        break;
    case 4:
        var_r4 = base + 0xA0;
        break;
    case 5:
        var_r4 = base + 0x30;
        break;
    default:
        var_r4 = base + 0x30;
        break;
    }
    if (var_r4 != NULL) {
        arg0->unkC = NULL;
        arg0->unk10 = 0;
        arg0->pad14 = 0;
        arg0->unk18 = 0;
        arg0->unk1C = 0;
        arg0->unk20 = 0;
        arg0->unk21 = 0;
        arg0->unkC = var_r4;
    }
}

extern "C" void kar_a2d_kirbydisp__near_80383a5c(void *arg0, u32 arg1, GXColor *color1, GXColor *color2) {
    volatile s32 sp8;
    volatile s32 spC;
    GXSetTevColor(1, *color1);
    GXSetTevColor(2, *color2);
    HSD_TObjSetup(*(void **) lbl_805699B0);
    GXSetNumTexGens(2);
    GXSetTexCoordGen2(0, 0, 1, 0x1e, 1, 0x40);
    GXSetTexCoordGen2(1, 0, 0, 0, 0, 0x43);
    GXLoadTexMtxImm(lbl_804F4910, 0x40, 0);
    GXLoadTexMtxImm(lbl_805699B0 + 4, 0x43, 0);
    GXSetNumChans(0);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 1, 1, 0xff);
    GXSetTevColorIn(0, 0xf, 8, 2, 4);
    GXSetTevAlphaIn(0, 7, 7, 7, 4);
    fn_803CEC68(0, 0, 0, 0, 1, 0);
    fn_803CECD0(0, 0, 0, 0, 0, 0);
    GXSetNumIndStages(1);
    fn_803CE8E0(0, 0, 0);
    GXSetIndTexCoordScale(0, 0, 0);
    fn_803CE604(1, lbl_804F4940, 1);
    sp8 = 0;
    spC = 0;
    GXSetTevIndirect(0, 0, 0, 3, 1, 0, 0, 0);
    GXSetColorUpdate(1);
    GXSetAlphaUpdate(0);
    u32 zdis = ((arg1 >> 0x1D) & 1) ^ 1;
    GXSetZMode(1, (arg1 & 0x08000000) ? 7 : 3, zdis);
    GXSetZCompLoc(1);
    GXSetBlendMode(0, 1, 0, 0xf);
    GXSetAlphaCompare(7, 0, 1, 7, 0);
    GXSetDither(0);
}

extern "C" void kar_a2d_kirbydisp__near_80383c98(void *dobj, void *vmtx, void *pmtx, u32 rendermode) {
    void (*fn)(void *, void *, void *, u32) = *(void (**)(void *, void *, void *, u32)) (hsdDObj + 0x3C);
    fn(dobj, vmtx, pmtx, rendermode);
    GXSetTevDirect(0);
    GXSetNumIndStages(0);
    HSD_StateInvalidate(-1);
}

extern "C" s32 kar_a2d_kirbydisp__near_80383ce0(HSD_PObj *arg0, void *desc) {
    s32 ret = ((s32 (*)(HSD_PObj *, void *)) * (void **) (hsdPObj + 0x44))(arg0, desc);
    if (ret != 0) {
        return ret;
    }
    if (!(HSD_FObjGetFlags(arg0) & 0x2000)) {
        return 0;
    }

    HSD_VtxDescList *var_r3 = (HSD_VtxDescList *) arg0->verts;
    s32 var_r4 = -1;
    s32 var_r6 = -1;
    s32 var_r5 = 0;
    s32 attr;
    goto loop_check;
loop_body:
    if (attr < 0xB) {
        if (attr == 0) {
            var_r4 = var_r5;
            var_r5 += 1;
        } else if (attr < 9) {
            var_r6 = var_r5;
            var_r5 += 1;
        } else {
            if (var_r3->attr_type == 3) {
                var_r5 += 2;
            } else {
                var_r5 += 1;
            }
        }
    } else if (attr < 0x15) {
        if (attr < 0xD) {
            switch (var_r3->attr_type) {
            case 3:
                var_r5 += 2;
                break;
            case 2:
                var_r5 += 1;
                break;
            default:
                switch (var_r3->comp_type) {
                case 3:
                case 0:
                    var_r5 += 2;
                    break;
                case 4:
                case 1:
                    var_r5 += 3;
                    break;
                case 2:
                    var_r5 += 4;
                    break;
                }
                break;
            }
        } else {
            if (var_r3->attr_type == 3) {
                var_r5 += 2;
            } else {
                var_r5 += 1;
            }
        }
    }
    var_r3 = (HSD_VtxDescList *) ((char *) var_r3 + 0x18);
loop_check:
    if (var_r3 != NULL) {
        attr = var_r3->attr;
        if (attr != 0xFF) {
            goto loop_body;
        }
    }

    if (var_r4 == -1 || var_r6 == -1) {
        return 0;
    }

    u8 *dispbuf = arg0->display;
    s32 var_r10 = 0;
    u8 *temp_r8 = dispbuf + var_r4;
    u8 *temp_r9 = dispbuf + var_r6;
    s32 temp_r4 = arg0->n_display << 5;

    while (var_r10 < temp_r4) {
        s32 temp_r10 = var_r10 + 1;
        if (dispbuf[var_r10] & 0xF8) {
            u8 *temp_r7 = dispbuf + temp_r10;
            s32 var_r11 = 0;
            u8 temp_r6 = temp_r7[0];
            var_r10 = temp_r10 + 2;
            s32 temp_r12 = temp_r7[1] | ((temp_r6 << 8) & 0xFF00);
            for (var_r11 = 0; var_r11 < temp_r12; var_r11++) {
                temp_r9[var_r10] = temp_r8[var_r10];
                var_r10 += var_r5;
            }
        }
    }

    DCFlushRange(dispbuf, (u32) temp_r4);
    return 0;
}
