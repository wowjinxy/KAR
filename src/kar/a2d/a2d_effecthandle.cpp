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
#define GX_TEVSTAGE1        1
#define GX_TEXCOORD0        0
#define GX_TEXCOORD1        1
#define GX_TEXCOORD2        2
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
#define GX_CC_CPREV         0
#define GX_CC_RASC          10
#define GX_CC_ONE           12
#define GX_CC_ZERO          15
#define GX_CA_A0            1
#define GX_CA_RASA          5
#define GX_CA_ONE           6
#define GX_CA_ZERO          7
#define GX_CA_TEXA          4
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
#define GX_LO_CLEAR         0
#define GX_LO_COPY          3
#define GX_CULL_NONE        0
#define GX_CULL_BACK        2
#define GX_PNMTX0           0
#define GX_CLAMP            0
#define GX_MIRROR           2
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

struct Vec3f {
    f32 x, y, z;
};

struct Vec4f {
    f32 x, y, z, w;
};

struct KurakkoInfo {
    char pad0[0x60];
    f32 unk60;
    f32 unk64;
};

struct HSD_JObj {
    s32 pad0[5];
    u32 flags;         //0x14
    s32 pad18;
    f32 rotate[4];       //0x1C
    f32 scale[3];         //0x2C
    f32 translate[3];      //0x38
    f32 mtx[12];             //0x44
};

struct ParticleBuf {
    s32 pad0[2];        //0x00
    Vec3f pos;           //0x08
    Vec4f quat;           //0x14
    Vec3f scale;          //0x24
};

struct ParticleHandle {
    char pad0[0x10];
    u32 unk10;
    char pad14[0x8];
    u16 unk1C;
    char pad1E[0x36];
    ParticleBuf *unk54;
    char pad58[4];
    void *unk5C;
};

class GameEffectItem;

class GameEffectItemBase {
public:
    virtual void v00();
    virtual void v04();
    virtual void Init();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual GameEffectItem *GetNext();
};

struct GameEffectItem : public GameEffectItemBase {
    s32 unk4;     //0x04
    s32 unk8;     //0x08
    s32 unkC;     //0x0C
    s32 unk10;    //0x10
    s32 unk14;    //0x14
    f32 unk18;    //0x18
    f32 unk1C;    //0x1C
    f32 unk20;    //0x20
    Vec3f *unk24; //0x24
    Vec4f *unk28; //0x28
    s32 unk2C;    //0x2C
    s32 unk30;    //0x30
    s32 unk34;    //0x34
    u8 unk38;     //0x38
    u8 unk39;     //0x39
    ParticleHandle *unk3C; //0x3C
    void *unk40;  //0x40
    s32 unk44;    //0x44
    u16 unk48;    //0x48
};

struct _HSD_ImageDesc {
    void *img_ptr;
    u16 width;
    u16 height;
    u32 format;
    u32 mipmap;
    f32 minLOD;
    f32 maxLOD;
};

struct IndTexDesc {
    void *unk0;
    u16 unk4;
    u16 unk6;
    u32 unk8;
    u8 unkC;
};

class KartIF {
public:
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual s32 v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual u8 v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual Vec3f *v74();
    virtual void v78();
    virtual Vec3f *v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual f32 v94();
    virtual u32 v98();
    virtual void v9c();
    virtual void vA0();
    virtual void vA4();
};

extern "C" {

void GXLoadTexMtxImm(f32 *, u32, s32);
void GXSetNumIndStages(s32);
void GXSetTevDirect(s32);
void GXSetTevIndirect(s32, s32, s32, s32, s32, s32, s32, s32);
void GXSetTevKColor(s32, void *);
void GXSetTevKAlphaSel(s32, s32);
void HSD_CObjEndCurrent();
void HSD_CObjGetViewport(s32, void *);
s32 HSD_CObjSetCurrent(s32);
BOOL HSD_JObjClearFlagsAll(void *, u32);
void *HSD_JObjLoadJoint(s32);
void HSD_JObjReqAnimAll(void *, f32);
void HSD_JObjSetFlagsAll(void *, u32);
void HSD_JObjSetMtxDirtySub(void *);
void HSD_JObjSetupMatrixSub(void *);
void HSD_JObjDispAll(void *, void *, s32, u32);
void HSD_JObjRemoveAnimAll(void);
void HSD_JObjAnimAll(void *);
void HSD_StateInvalidate(s32);
void HSD_StateSetColorUpdate(u32);
void HSD_ImageDescCopyFromEFB(void *, s32, s32, s32, s32);
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
void fn_803CE604(s32, void *, s32);
void fn_803CE8E0(s32, s32, s32);
void fn_803D19AC(f32 *, s32, f32, f32, f32, f32, f32, f32);

void PSVECNormalize(f32 *, f32 *);
void PSVECAdd(void *, void *, void *);
void PSVECScale(void *, void *, f32);
f32 PSVECMag();
void PSMTXConcat(f32 *, f32 *, f32 *);
void kar_lbvector_dirs_to_euler(f32 *, f32 *, f32 *, f32, f32);
void kar_lbvector_dir_up_to_euler(f32 *);
void kar_lbvector_rotate_about_cardinal_axis(f32 *, s32, f32, f32, f32, f32, f32, f32);
void kar_lbvector__near_80064770(s32, void *);
void kar_lbvector__near_80064900(s32, f32 *, f32 *, s32, s32, f32, f32, f32);

void *kar_diag__803ad760(s32, s32, void *, void *, s32);

void *fn_8034D1F8(void);
void *fn_80305ABC(void *, u32);
void __construct_array(void *, void *, void *, s32, s32);
extern void *fn_802CD8DC;
extern void *fn_8028DF40;
extern void *fn_8028DFC8;

double tan(double);
s32 HSD_Randi(s32);

void kar_a2d_game_lib__802894bc(void *, void *, s32);
u8 kar_a2d_game_lib__near_802897e0(void *);
}
namespace {
extern "C" void kar_a2d_game_lib__802894bc(void *, s32);
}
extern "C" {
void kar_a2d_game_lib__near_8028aec0(s32, s32, f32 *, f32 *, f32 *, f32, f32);
void kar_a2d_game_lib__near_8028b050(void *, s32, s32, s32);
s32 kar_a2d_game_lib__near_8028b11c(s32, s32);
void kar_a2d_game_lib__near_8028b2cc(s32);
void kar_a2d_game_lib__near_8028b358(f32, f32, f32, f32, f32, f32, f32, f32);
void kar_a2d_game_lib__near_80289768(void *, u16, f32);
f32 kar_a2d_game_lib__near_80289928(s32);

void kar_a2d_game_effect__near_8037afd0(GameEffectItem *, u8);
u16 kar_a2d_game_effect__near_8037adf8(void *, s32);

KurakkoInfo *kar_a2d_kurakko__near_803785b0(f32);
void kar_grcoll__803d1978(f32 *, f32, f32, f32);

void *kar_generator__near_804328a0(s32, u32, s32, void *);
void *kar_generator__near_8043294c(s32, u32, s32);
u32 kar_psdisp__near_80437cd8(s32);
void kar_psdisp__80433f00(u32, s32);
void kar_a2d_soundhandle__near_80379cdc(void *, u32);
void kar_particle__near_8042b840(u16, s32);
void kar_psinterpret__near_80430394(u16);
void kar_a2d_game_audio__near_80379784(void *, s32, s32, f32);
void kar_a2d_game_audio__near_80379a0c(void *, s32);
void kar_a2d_game_audio__near_80379a94(void *, s32);
void kar_shadow__803cd5b0(u16, u16, u32, s32, s32);

f32 fn_80296264(f32);
f32 fn_8029626C(f32);
f32 fn_802D4C30(f32);
void fn_802E5DCC(f32 *, f32 *);
s32 fn_80312F6C();
s32 fn_80312F94();
f32 *fn_8038D0A8(s32);
void *fn_8038CB28(s32);

void kar_a2d_wipeeffect__8037e3cc(void *, void *);
void kar_a2d_wipeeffect__near_8037e42c(void *, void *, void *);

extern GXTexObj lbl_80569950;
extern s32 lbl_805DDB00;
extern s32 lbl_805DDB90;
extern s32 lbl_805DDB9C;
extern s32 lbl_805DDBA0;
extern s32 lbl_805DDBC0;
extern s32 lbl_805DDBE4;
extern void *lbl_805DE378;

extern char lbl_804BD724[];
extern char lbl_804BDD30[];
extern char lbl_804BDD58[];
extern char lbl_804BDD98[];
extern char lbl_804BDDD8[];
extern char lbl_804BDF2C[];
extern char lbl_804BDF70[];

}

#define ASSERT2(line, cond, file, str) \
    ((cond) ? ((void) 0) : __assert(file, line, str))

static char kar_src_a2d_effecthandle_804f3158[] = "a2d_effecthandle.cpp";
static char lbl_804F3170[] = "translate";
static char lbl_804F317C[] = "CourseFactory";
static char lbl_804F318C[] = "Singleton<CourseFactory>";

struct NamePair {
    char *a;
    char *b;
};

struct ClassInfo3 {
    void *a, *b, *c;
};

extern "C" char lbl_804F3128[]; /* "GameEffect" (a2d_soundhandle.cpp) */
extern "C" char lbl_804F3134[]; /* "Singleton<GameEffect>" (a2d_soundhandle.cpp) */
extern ClassInfo3 lbl_804F314C; /* a2d_soundhandle.cpp */

static NamePair lbl_805DBC58 = {lbl_804F3134, 0};
static NamePair lbl_805DBC60 = {lbl_804F3128, (char *) &lbl_804F314C};

static char lbl_805DBC68[] = "jobj";
static char lbl_805DBC70[] = "0";

static char kar_srcfile_jobj_h_805dbc78[] = "jobj.h";
static char lbl_805DBC80[] = "jobj";
static s32 lbl_805DBC88 = 0;
static s32 lbl_805DBC8C = 0xFF;

static NamePair lbl_805DBC90 = {lbl_804F318C, 0};
static ClassInfo3 lbl_804F31A8 = {&lbl_805DBC90, 0, 0};
static NamePair lbl_805DBC98 = {lbl_804F317C, (char *) &lbl_804F31A8};

static char kar_srcfile_jobj_h_805dbca0[] = "jobj.h";
static char lbl_805DBCA8[] = "jobj";

static char lbl_804F31E8[] = "CourseFactory";
static char lbl_804F31F8[] = "Singleton<CourseFactory>";
static NamePair lbl_805DBCB0 = {lbl_804F31F8, 0};
static ClassInfo3 lbl_804F3214 = {&lbl_805DBCB0, 0, 0};
static NamePair lbl_805DBCB8 = {lbl_804F31E8, (char *) &lbl_804F3214};

static char lbl_804F3250[] = "PostDrawEffect";
static char lbl_804F3260[] = "ObjCollect<PostDrawEffect>";
static NamePair lbl_805DBCC0 = {lbl_804F3260, 0};

static ClassInfo3 lbl_804F327C = {&lbl_805DBCC0, 0, 0};

struct ClassHdr {
    void *a, *b;
};

static ClassHdr lbl_805DBCC8 = {lbl_804F3250, &lbl_804F327C};

struct RippleFadeState;
struct SoundFadeVol;

extern "C" {
s32 fn_8037CAF0(void);
void kar_a2d_effecthandle__near_8037caf8(void);
void fn_8037CB18(RippleFadeState *, Vec4f *);
void kar_a2d_grindrail__near_803343f8(void *);
void kar_a2d_effecthandle__near_8037d550(void *, s32, s32, void *);
void kar_a2d_effecthandle__near_8037c948(RippleFadeState *);
void fn_802D4024();
void fn_80295C34();
void fn_80292960();
void fn_80295C68();
void fn_80295CA0();
void fn_80295CDC();
void fn_80295D58();
void fn_8029292C();
void fn_80292B40();
void fn_8033441C();
}

static void *lbl_804F32A8[] = {
    &lbl_805DBCC8, 0,
    (void *) fn_802D4024, (void *) fn_80295C34, (void *) fn_80292960, (void *) fn_80295C68,
    (void *) fn_80295CA0, (void *) fn_80295CDC, (void *) fn_80295D58, (void *) fn_8029292C,
    (void *) fn_8037CAF0, (void *) kar_a2d_effecthandle__near_8037caf8,
    (void *) kar_a2d_grindrail__near_803343f8, (void *) fn_80292B40,
    (void *) fn_8037CB18, (void *) fn_8033441C,
    (void *) kar_a2d_effecthandle__near_8037d550, (void *) kar_a2d_effecthandle__near_8037c948,
};

class SmallDiagBase {
public:
    void *unk0;
    s32 unk4, unk8;
};

static inline void kar_a2d_effecthandle__SetParticleKeep(GameEffectItem *arg0, u8 arg1) {
    ParticleHandle *particle;
    u8 keep;
    particle = arg0->unk3C;
    keep = arg1;
    if (particle != NULL) {
        if (particle->unk10 != 0) {
            keep = 1;
        }
        if (keep != 0) {
            kar_particle__near_8042b840(arg0->unk48, 0);
            return;
        }
        kar_psinterpret__near_80430394(arg0->unk48);
    }
}

extern "C" void *kar_a2d_effecthandle__8037b028(GameEffectItem *arg0, s32 arg1, s32 arg2,
                                                 void *arg3, Vec3f *arg4, Vec4f *arg5) {
    arg0->unkC = 0x7531;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    arg0->unk40 = 0;
    arg0->unk44 = 0;
    arg0->unk3C = 0;
    arg0->unk38 = 0;
    arg0->unk39 = 0;
    arg0->unk48 = 0;
    arg0->unk30 = 0;
    arg0->unk24 = 0;
    arg0->unk28 = 0;
    arg0->unk2C = 0;
    if (arg1 == -1) {
        arg0->unkC = -1;
        return (void *) 1;
    }
    if (arg2 == 1) {
        ASSERT2(0x9F, arg3 != 0, kar_src_a2d_effecthandle_804f3158, lbl_805DBC68);
        arg0->unk3C = (ParticleHandle *) kar_generator__near_804328a0(0, kar_a2d_game_effect__near_8037adf8(kar_diag__803ad760(lbl_805DDB90, 0, &lbl_805DBC60, &lbl_805DBC58, 0), arg1), arg1, arg3);
        u8 ok;
        if (arg0->unk3C != NULL) {
            arg0->unk10 = 1;
            arg0->unkC = arg1;
            arg0->unk30 = (s32) arg3;
            arg0->unk48 = arg0->unk3C->unk1C;
            if (arg0->unk3C->unk54 != NULL) {
                arg0->unk3C->unk54->pad0[1] = (s32) arg0->unk3C;
            }
            arg0->unk3C->unk5C = (void *) &kar_a2d_soundhandle__near_80379cdc;
            ok = 1;
        } else {
            ok = 0;
        }
        if (ok != 0) {
            return (void *) 1;
        }
        goto block_ret0;
    }
    arg0->unk3C = (ParticleHandle *) kar_generator__near_8043294c(0, kar_a2d_game_effect__near_8037adf8(kar_diag__803ad760(lbl_805DDB90, 0, &lbl_805DBC60, &lbl_805DBC58, 0), arg1), arg1);
    if (arg0->unk3C != NULL) {
        if (arg4 != NULL || arg5 != NULL) {
            if (arg0->unk3C->unk54 == NULL && kar_psdisp__near_80437cd8(0) == 0) {
                kar_a2d_effecthandle__SetParticleKeep(arg0, 1);
                arg0->unk3C = 0;
                return (void *) 0;
            }
            arg0->unkC = arg1;
            arg0->unk10 = arg2;
            arg0->unk48 = arg0->unk3C->unk1C;
            if (arg4 != NULL) {
                arg0->unk3C->unk54->pos = *arg4;
            }
            if (arg5 != NULL) {
                arg0->unk3C->unk54->quat = *arg5;
            }
            switch (arg0->unk10) {
            case 3:
                arg0->unk18 = arg4->x;
                arg0->unk1C = arg4->y;
                arg0->unk20 = arg4->z;
                arg0->unk39 = 1;
                break;
            case 2:
                arg0->unk24 = arg4;
                arg0->unk28 = arg5;
                break;
            default:
                ASSERT2(0x104, 0, kar_src_a2d_effecthandle_804f3158, lbl_805DBC70);
                break;
            }
            arg0->unk3C->unk54->pad0[1] = (s32) arg0->unk3C;
            arg0->unk3C->unk5C = (void *) &kar_a2d_soundhandle__near_80379cdc;
            return (void *) 1;
        }
        arg0->unk10 = 0;
        return (void *) 1;
    }
block_ret0:
    return (void *) 0;
}

extern "C" void kar_a2d_effecthandle__near_8037b33c(GameEffectItem *arg0, u8 arg1) {
    kar_a2d_effecthandle__SetParticleKeep(arg0, arg1);
    arg0->unkC = 0x7531;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    arg0->unk40 = 0;
    arg0->unk44 = 0;
    arg0->unk3C = 0;
    arg0->unk38 = 0;
    arg0->unk39 = 0;
    arg0->unk48 = 0;
    arg0->unk30 = 0;
    arg0->unk24 = 0;
    arg0->unk28 = 0;
    arg0->unk2C = 0;
}

extern "C" s32 kar_a2d_effecthandle__near_8037b3dc(GameEffectItem *arg0, Vec3f *arg1) {
    if (arg0->unk10 == 2) {
        arg0->unk18 = arg1->x;
        arg0->unk1C = arg1->y;
        arg0->unk20 = arg1->z;
        arg0->unk39 = 1;
        return 1;
    }
    return 0;
}

extern "C" s32 kar_a2d_effecthandle__near_8037b418(GameEffectItem *arg0, Vec4f *arg1) {
    ParticleHandle *ph = arg0->unk3C;
    ParticleBuf *buf = ph->unk54;
    if (buf != NULL) {
        buf->quat.x = arg1->x;
        buf->quat.y = arg1->y;
        buf->quat.z = arg1->z;
        buf->quat.w = arg1->w;
        goto b418_ret1;
    }
    if (kar_psdisp__near_80437cd8(0) != 0) {
        ParticleBuf *buf2 = arg0->unk3C->unk54;
        buf2->quat.x = arg1->x;
        buf2->quat.y = arg1->y;
        buf2->quat.z = arg1->z;
        buf2->quat.w = arg1->w;
        goto b418_ret1;
    }
    return 0;
b418_ret1:
    return 1;
}

extern "C" s32 kar_a2d_effecthandle__near_8037b4c8(GameEffectItem *arg0) {
    Vec4f euler;
    kar_lbvector_dir_up_to_euler((f32 *) &euler);
    ParticleBuf *buf = arg0->unk3C->unk54;
    if (buf != NULL) {
        buf->quat.x = euler.x;
        buf->quat.y = euler.y;
        buf->quat.z = euler.z;
        buf->quat.w = euler.w;
        goto b4c8_ret1;
    }
    if (kar_psdisp__near_80437cd8(0) != 0) {
        ParticleBuf *buf2 = arg0->unk3C->unk54;
        buf2->quat.x = euler.x;
        buf2->quat.y = euler.y;
        buf2->quat.z = euler.z;
        buf2->quat.w = euler.w;
        goto b4c8_ret1;
    }
    return 0;
b4c8_ret1:
    return 1;
}

extern "C" s32 kar_a2d_effecthandle__near_8037b574(GameEffectItem *arg0, Vec3f *arg1) {
    ParticleBuf *buf = arg0->unk3C->unk54;
    if (buf != NULL) {
        buf->scale.x = arg1->x;
        buf->scale.y = arg1->y;
        buf->scale.z = arg1->z;
        goto b574_ret1;
    }
    if (kar_psdisp__near_80437cd8(0) != 0) {
        ParticleBuf *buf2 = arg0->unk3C->unk54;
        buf2->scale.x = arg1->x;
        buf2->scale.y = arg1->y;
        buf2->scale.z = arg1->z;
        goto b574_ret1;
    }
    return 0;
b574_ret1:
    return 1;
}

extern "C" void kar_a2d_effecthandle__near_8037b614(GameEffectItem *arg0, s32 arg1) {
    arg0->unk2C = arg1;
}

struct PtclTargetNode {
    PtclTargetNode *unk0;
    char pad4[0x18];
    u16 unk1C;
};

extern "C" s32 kar_a2d_effecthandle__near_8037b61c(GameEffectItem *arg0) {
    u16 target = arg0->unk48;
    PtclTargetNode *node = (PtclTargetNode *) lbl_805DE378;
    while (node != NULL) {
        if (node->unk1C == target) {
            return 1;
        }
        node = node->unk0;
    }
    return 0;
}

struct SoundFadeVol {
    char pad0[8];
    f32 unk8;
    f32 unkC;
};

extern "C" void kar_a2d_effecthandle__near_8037b650(SoundFadeVol *arg0, u8 arg1, f32 farg0) {
    f32 var_f1;
    if (arg1 != 0) {
        var_f1 = 0.75f;
    } else {
        var_f1 = farg0 / 0.5f;
        if (var_f1 > 1.0f) {
            var_f1 = 1.0f;
        }
    }
    arg0->unk8 = 0.4f * (arg0->unkC * var_f1) + arg0->unk8;
}

extern "C" u8 kar_a2d_effecthandle__near_8037b694(SoundFadeVol *arg0) {
    f32 v = arg0->unk8;
    if (v >= 1.0f) {
        arg0->unk8 = v - 1.0f;
        return 1;
    }
    if (v < 0.1f) {
        arg0->unk8 = 0.0f;
    }
    return 0;
}

struct GameEffectItem10;

struct SpraySubMgr {
    s32 unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    char items[10][0x4C];
};

extern "C" void kar_a2d_effecthandle__near_8037b6d4(SpraySubMgr *arg0, s32 kind, Vec3f *pos, Vec3f *dir,
                                                     void *jobj, u8 flag, f32 farg0) {
    if (pos != NULL) {
        Vec3f euler;
        Vec3f sc;
        euler.z = 0.0f;
        euler.y = 0.0f;
        euler.x = 0.0f;
        sc.x = 1.0f;
        sc.y = 1.0f;
        sc.z = 1.0f;
        s32 idx = HSD_Randi(5);
        if (idx >= arg0->unk0) {
            idx += 1;
        }
        f32 negDirZ = -dir->z;
        f32 dirX = dir->x;
        f32 negDirY = -dir->y;
        arg0->unk0 = idx;
        f32 negDirX = -dirX;
        euler.y = negDirY;
        euler.x = negDirX;
        euler.z = negDirZ;
        kar_lbvector_rotate_about_cardinal_axis(&euler.x, 2, ((2.0f * (f32) idx * 1.0471976f) / 5.0f) - 1.0471976f, 1.0471976f, negDirX, dirX, negDirY, negDirZ);
        PSVECScale(&euler, &euler, arg0->unk10 * farg0);
        PSVECAdd(&euler, pos, &euler);
        GameEffectItem *item = (GameEffectItem *) (arg0->items[arg0->unk4] + 0x14);
        s32 particleCheck = (s32) item->unk3C;
        if (((u32) (-particleCheck | particleCheck) >> 31) == 0) {
            if (kar_a2d_effecthandle__8037b028(item, kind, 3, NULL, &euler, NULL) != 0) {
                PSVECScale(&sc, &sc, arg0->unk10);
                if (flag != 0) {
                    PSVECScale(&sc, &sc, 1.2f);
                }
                kar_a2d_effecthandle__near_8037b574((GameEffectItem *) (arg0->items[arg0->unk4] + 0x14), &sc);
                kar_a2d_effecthandle__near_8037b418((GameEffectItem *) (arg0->items[arg0->unk4] + 0x14), (Vec4f *) ((char *) jobj + 0x1C));
            }
        }
    } else {
        GameEffectItem *item = (GameEffectItem *) (arg0->items[arg0->unk4] + 0x14);
        kar_a2d_game_effect__near_8037afd0(item, 0);
        kar_a2d_effecthandle__8037b028(item, kind, 1, jobj, NULL, NULL);
    }
    s32 next = arg0->unk4 + 1;
    arg0->unk4 = next;
    if (next >= 10) {
        arg0->unk4 = 0;
    }
}

extern "C" u8 kar_a2d_effecthandle__near_8037be50(SpraySubMgr *arg0, s32 kind, Vec3f *pos, Vec3f *dir,
                                                   void *jobj, u8 flag, f32 farg0, f32 farg1) {
    u8 result = 0;
    f32 var_f1;
    if (flag != 0) {
        var_f1 = 0.75f;
    } else {
        var_f1 = farg0 / 0.5f;
        if (var_f1 > 1.0f) {
            var_f1 = 1.0f;
        }
    }
    arg0->unk8 = 0.4f * (arg0->unkC * var_f1) + arg0->unk8;
    for (;;) {
        f32 v = arg0->unk8;
        u8 fire;
        if (v >= 1.0f) {
            fire = 1;
            arg0->unk8 = v - 1.0f;
        } else {
            if (v < 0.1f) {
                arg0->unk8 = 0.0f;
            }
            fire = 0;
        }
        if (fire == 0) {
            break;
        }
        if (pos != NULL) {
            Vec3f euler;
            Vec3f sc;
            euler.z = 0.0f;
            euler.y = 0.0f;
            euler.x = 0.0f;
            sc.x = 1.0f;
            sc.y = 1.0f;
            sc.z = 1.0f;
            s32 idx = HSD_Randi(5);
            if (idx >= arg0->unk0) {
                idx += 1;
            }
            f32 negDirZ = -dir->z;
            f32 dirX = dir->x;
            f32 negDirY = -dir->y;
            arg0->unk0 = idx;
            f32 negDirX = -dirX;
            euler.y = negDirY;
            euler.x = negDirX;
            euler.z = negDirZ;
            kar_lbvector_rotate_about_cardinal_axis(&euler.x, 2, ((2.0f * (f32) idx * 1.0471976f) / 5.0f) - 1.0471976f, 1.0471976f, negDirX, dirX, negDirY, negDirZ);
            PSVECScale(&euler, &euler, arg0->unk10 * farg1);
            PSVECAdd(&euler, pos, &euler);
            char *slot = arg0->items[arg0->unk4];
            s32 particleCheck = *(s32 *) (slot + 0x50);
            if (((u32) (-particleCheck | particleCheck) >> 31) == 0) {
                if (kar_a2d_effecthandle__8037b028((GameEffectItem *) (slot + 0x14), kind, 3, NULL, &euler, NULL) != 0) {
                    PSVECScale(&sc, &sc, arg0->unk10);
                    if (flag != 0) {
                        PSVECScale(&sc, &sc, 1.2f);
                    }
                    kar_a2d_effecthandle__near_8037b574((GameEffectItem *) (arg0->items[arg0->unk4] + 0x14), &sc);
                    kar_a2d_effecthandle__near_8037b418((GameEffectItem *) (arg0->items[arg0->unk4] + 0x14), (Vec4f *) ((char *) jobj + 0x1C));
                }
            }
        } else {
            GameEffectItem *item = (GameEffectItem *) (arg0->items[arg0->unk4] + 0x14);
            kar_a2d_game_effect__near_8037afd0(item, 0);
            kar_a2d_effecthandle__8037b028(item, kind, 1, jobj, NULL, NULL);
        }
        s32 next = arg0->unk4 + 1;
        arg0->unk4 = next;
        if (next >= 10) {
            arg0->unk4 = 0;
        }
        result = 1;
    }
    return result;
}

struct SlipstreamMgr {
    s32 unk0;                   //0x0
    char pad4[0x4C];             //0x4
    GameEffectItem unk50;         //0x50
    char pad9C[0xE8 - 0x9C];       //0x9C
    u8 unkE8;                       //0xE8
    u8 unkE9;                        //0xE9
    char padEA[2];
    s32 unkEC;                         //0xEC
    char padF0[0x180 - 0xF0];
    f32 unk180;                          //0x180
    f32 unk184;                           //0x184
    char pad188[4];
    s32 unk18C;                             //0x18C
    f32 unk190;                              //0x190
    f32 unk194;                               //0x194
    f32 unk198;                                //0x198
    char pad19C[0x1B8 - 0x19C];
    void *unk1B8;                                 //0x1B8
    u32 unk1BC;                                    //0x1BC
    KartIF *unk1C0;                                 //0x1C0
    char pad1C4[0x200 - 0x1C4];
    s32 unk200;                                       //0x200
    f32 unk204;                                        //0x204
    SpraySubMgr unk208;                                 //0x208
};

extern "C" void kar_a2d_effecthandle__near_8037c4a8(SlipstreamMgr *arg0);
extern "C" void kar_a2d_effecthandle__near_8037c59c(SlipstreamMgr *arg0);
extern "C" void kar_a2d_effecthandle__near_8037c128(SlipstreamMgr *arg0);

extern "C" void kar_a2d_effecthandle__near_8037b908(GameEffectItem *item) {
    SlipstreamMgr *arg0 = (SlipstreamMgr *) item->unk44;
    arg0->unkE9 = 0;
    kar_a2d_effecthandle__near_8037c4a8(arg0);
    kar_a2d_effecthandle__near_8037c59c(arg0);
    if (arg0->unkE8 != 0) {
        if (arg0->unk1C0->v94() < 1.0f) {
            arg0->unk1C0->vA0();
            f32 *offs = fn_8038D0A8(0);
            Vec3f *vel = arg0->unk1C0->v7c();
            Vec3f pos;
            pos.x = vel->x;
            pos.y = vel->y;
            pos.z = vel->z;
            PSVECScale(&pos, &pos, 2.0f);
            PSVECAdd(&pos, arg0->unk1C0->v74(), &pos);
            GameEffectItem *puff = &arg0->unk50;
            kar_a2d_game_effect__near_8037afd0(puff, 0);
            kar_a2d_effecthandle__8037b028(puff, 0x2910, 1, &pos, NULL, NULL);
            kar_a2d_effecthandle__near_8037b418(puff, (Vec4f *) (offs + 7));
            arg0->unkE8 = 0;
        }
    }
    if (arg0->unkE9 != 0 && arg0->unk1C0->v64() != 0 && arg0->unk1C0->v94() < 1.0f && arg0->unk1C0->v28() != 9) {
        Vec3f *pos = arg0->unk1C0->v74();
        if (arg0->unk1BC == 0) {
            HSD_JObjClearFlagsAll(arg0->unk1B8, 0x10);
            HSD_JObjReqAnimAll(arg0->unk1B8, 0.0f);
            arg0->unk1BC = 1;
            HSD_JObj *jobj = (HSD_JObj *) arg0->unk1B8;
            jobj->translate[0] = pos->x;
            jobj->translate[1] = pos->y;
            jobj->translate[2] = pos->z;
        } else {
            HSD_JObj *jobj = (HSD_JObj *) arg0->unk1B8;
            ASSERT2(0x3A9, jobj != NULL, kar_srcfile_jobj_h_805dbc78, lbl_805DBC80);
            ASSERT2(0x3AA, pos != NULL, kar_srcfile_jobj_h_805dbc78, lbl_804F3170);
            jobj->translate[0] = pos->x;
            jobj->translate[1] = pos->y;
            jobj->translate[2] = pos->z;
            if (!(jobj->flags & 0x02000000)) {
                ASSERT2(0x25D, jobj != NULL, kar_srcfile_jobj_h_805dbc78, lbl_805DBC80);
                if (!(jobj->flags & 0x800000) && (jobj->flags & 0x40)) {
                } else {
                    HSD_JObjSetMtxDirtySub(jobj);
                }
            }
        }
    } else if (arg0->unk1BC != 0) {
        HSD_JObjSetFlagsAll(arg0->unk1B8, 0x10);
        arg0->unk1BC = 0;
    }
    if (arg0->unk0 != 0x7531) {
        arg0->unk1C0->v84();
        f32 mag = PSVECMag();
        if (arg0->unk0 == 0x2908 && arg0->unk1C0->v94() < 1.0f && arg0->unk1C0->v28() != 9) {
            f32 t = mag / 0.5f;
            if (t > 1.0f) {
                t = 1.0f;
            }
            f32 sc = 2.0f * (0.5f + t);
            if (sc > 2.4f) {
                sc = 2.4f;
            }
            Vec3f *pos = arg0->unk1C0->v74();
            arg0->unk190 = pos->x;
            arg0->unk194 = pos->y;
            arg0->unk198 = pos->z;
            arg0->unk18C = 1;
            arg0->unk180 = sc;
            arg0->unk184 = sc;
        } else {
            arg0->unk18C = 0;
        }
        if (arg0->unk0 == 0x2A30) {
            if (arg0->unk1C0->v28() == 0xE) {
                u8 flag = arg0->unk1C0->v64();
                arg0->unk1C0->vA4();
                f32 *offs = fn_8038D0A8(0);
                if (kar_a2d_effecthandle__near_8037be50(&arg0->unk208, arg0->unk0, NULL, arg0->unk1C0->v7c(), offs, flag, 0.5f, 4.0f) != 0) {
                    kar_a2d_effecthandle__near_8037c128(arg0);
                }
            }
        } else {
            if (arg0->unk1C0->v94() < 1.0f) {
                u8 flag = arg0->unk1C0->v64();
                arg0->unk1C0->vA4();
                f32 *offs = fn_8038D0A8(0);
                Vec3f *vel = arg0->unk1C0->v7c();
                if (kar_a2d_effecthandle__near_8037be50(&arg0->unk208, arg0->unk0, arg0->unk1C0->v74(), vel, offs, flag, mag, 1.94f) != 0) {
                    kar_a2d_effecthandle__near_8037c128(arg0);
                }
            }
        }
    }
}

extern "C" void kar_a2d_effecthandle__near_8037c128(SlipstreamMgr *arg0) {
    if (arg0->unk204 > 0.0f) {
        arg0->unk204 = arg0->unk204 - 0.75f;
        return;
    }
    if ((arg0->unk1C0->v64() != 0 || (u32) (arg0->unk200 + 0xFFFA0000) == 0x13) && arg0->unk200 != -1) {
        arg0->unk1C0->v84();
        f32 mag = PSVECMag();
        f32 a = fn_80296264(1.0f);
        f32 b = fn_8029626C(1.0f) * a;
        f32 rate = fn_802D4C30(0.016666668f) * b;
        f32 vol = mag * (1.0f * rate);
        kar_a2d_game_audio__near_80379784((char *) arg0 + 0x1C4, arg0->unk200, 0, rate);
        kar_a2d_game_audio__near_80379a0c((char *) arg0 + 0x1C4, HSD_Randi(0xC8) - 0x64);
        f32 pan;
        fn_802E5DCC(&pan, &vol);
        f32 c = fn_80296264(1.0f);
        f32 d = fn_8029626C(1000.0f) * c;
        f32 range = fn_802D4C30(3600.0f) * d;
        f32 e = kar_a2d_kurakko__near_803785b0(range)->unk60;
        s32 v = (s32) ((vol / (1.0f * range)) * kar_a2d_kurakko__near_803785b0(range)->unk64 + e);
        if (v < lbl_805DBC88) {
            v = lbl_805DBC88;
        }
        if (lbl_805DBC8C < v) {
            v = lbl_805DBC8C;
        }
        kar_a2d_game_audio__near_80379a94((char *) arg0 + 0x1C4, v);
        arg0->unk204 = arg0->unk204 + 1.0f;
    }
}

extern "C" void kar_a2d_effecthandle__near_8037c2fc(SlipstreamMgr *arg0) {
    arg0->unk0 = 0x7531;
    arg0->unkE8 = 0;
    arg0->unkE9 = 0;
    arg0->unk200 = -1;
    arg0->unk204 = 0.0f;
    if (arg0->unk1BC != 0) {
        HSD_JObjSetFlagsAll(arg0->unk1B8, 0x10);
        arg0->unk1BC = 0;
    }
    arg0->unk18C = 0;
    arg0->unk208.unk0 = -1;
    arg0->unk208.unk4 = 0;
    arg0->unk208.unkC = 1.0f;
    arg0->unk208.unk10 = 1.0f;
    arg0->unk208.unk8 = 0.0f;
}

extern "C" void kar_a2d_effecthandle__near_8037c390(GameEffectItem *arg0) {
    if (arg0->unk10 == 0x7531) {
        GameEffectItem *item = (GameEffectItem *) ((char *) arg0 + 4);
        kar_a2d_game_effect__near_8037afd0(item, 0);
        kar_a2d_effecthandle__8037b028(item, -1, 0, NULL, NULL, NULL);
    }
    arg0->unk40 = (void *) &kar_a2d_effecthandle__near_8037b908;
    arg0->unk44 = (s32) arg0;
}

extern "C" void kar_a2d_effecthandle__near_8037c3fc(SlipstreamMgr *arg0) {
    GameEffectItem *item = (GameEffectItem *) ((char *) arg0 + 4);
    if (item->unk10 != 0x7531) {
        item->unk40 = 0;
        item->unk44 = (s32) item;
    }
    arg0->unk0 = 0x7531;
    arg0->unkE8 = 0;
    arg0->unkE9 = 0;
    arg0->unk200 = -1;
    arg0->unk204 = 0.0f;
    if (arg0->unk1BC != 0) {
        HSD_JObjSetFlagsAll(arg0->unk1B8, 0x10);
        arg0->unk1BC = 0;
    }
    arg0->unk18C = 0;
    arg0->unk208.unk0 = -1;
    arg0->unk208.unk4 = 0;
    arg0->unk208.unkC = 1.0f;
    arg0->unk208.unk10 = 1.0f;
    arg0->unk208.unk8 = 0.0f;
}

extern "C" void kar_a2d_effecthandle__near_8037c4a8(SlipstreamMgr *arg0) {
    switch (arg0->unk1C0->v98()) {
    case 0:
        arg0->unk0 = 0x2710;
        return;
    case 1:
        arg0->unk0 = 0x2711;
        return;
    case 2:
        arg0->unk0 = 0x2714;
        return;
    case 3:
        arg0->unk0 = 0x2840;
        return;
    case 4:
    case 5:
    case 6:
    case 7:
        arg0->unk0 = 0x7531;
        return;
    case 8:
    case 9:
        if (arg0->unk0 != 0x2908) {
            arg0->unkE8 = 1;
            arg0->unkEC = 0;
        }
        arg0->unkE9 = 1;
        arg0->unk0 = 0x2908;
        return;
    case 11:
        kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DBC98, &lbl_805DBC90, 0);
        arg0->unk0 = fn_80312F6C();
        return;
    default:
        arg0->unk0 = 0x7531;
        return;
    }
}

extern "C" void kar_a2d_effecthandle__near_8037c59c(SlipstreamMgr *arg0) {
    switch (arg0->unk1C0->v98()) {
    case 0:
    case 1:
        arg0->unk200 = 0x60015;
        return;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    case 8:
    case 9:
        arg0->unk200 = 0x60013;
        return;
    case 10:
        kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DBC98, &lbl_805DBC90, 0);
        arg0->unk200 = fn_80312F94();
        return;
    case 11:
        break;
    default:
        break;
    }
    arg0->unk200 = 0x60016;
}

struct TireMgrOuter {
    s32 unk0;
    char pad4[0x310 - 4];
    GameEffectItem unk310;
    KartIF *unk35C;
    HSD_JObj *unk360;
};

extern "C" void kar_a2d_effecthandle__near_8037c878(TireMgrOuter *arg0);

extern "C" void kar_a2d_effecthandle__near_8037c660(GameEffectItem *item) {
    TireMgrOuter *arg0 = (TireMgrOuter *) item->unk44;
    kar_a2d_effecthandle__near_8037c878(arg0);
    if (arg0->unk0 != 0x7531 && arg0->unk0 != 0x2A30) {
        arg0->unk35C->v84();
        f32 mag = PSVECMag();
        if (arg0->unk35C->v94() < 1.0f) {
            HSD_JObj *jobj = arg0->unk360;
            ASSERT2(0x25D, jobj != NULL, kar_srcfile_jobj_h_805dbca0, lbl_805DBCA8);
            if (!(jobj->flags & 0x800000) && (jobj->flags & 0x40)) {
                HSD_JObjSetupMatrixSub(jobj);
            }
            f32 velx = jobj->mtx[3];
            f32 vely = jobj->mtx[7];
            f32 velz = jobj->mtx[11];
            Vec3f velVec;
            velVec.x = velx;
            velVec.y = vely;
            velVec.z = velz;
            u8 flag = arg0->unk35C->v64();
            HSD_JObj *jobj2 = arg0->unk360;
            Vec3f *pos = arg0->unk35C->v7c();
            s32 kind = arg0->unk0;
            kar_a2d_effecthandle__near_8037b650((SoundFadeVol *) ((char *) item + 4), flag, mag);
            while (kar_a2d_effecthandle__near_8037b694((SoundFadeVol *) ((char *) item + 4)) != 0) {
                kar_a2d_effecthandle__near_8037b6d4((SpraySubMgr *) ((char *) item + 4), kind, &velVec, pos, jobj2, flag, 1.94f);
            }
        }
    }
}

extern "C" void kar_a2d_effecthandle__near_8037c7dc(SoundFadeVol *arg0) {
    s32 *raw = (s32 *) arg0;
    raw[0] = 0x7531;
    raw[1] = -1;
    raw[2] = 0;
    arg0->unk8 = 1.0f;
    arg0->unkC = 1.0f;
    ((f32 *) arg0)[1] = 0.0f;
}

extern "C" void kar_a2d_effecthandle__near_8037c80c(TireMgrOuter *arg0) {
    if (arg0->unk310.unkC == 0x7531) {
        kar_a2d_game_effect__near_8037afd0(&arg0->unk310, 0);
        kar_a2d_effecthandle__8037b028(&arg0->unk310, -1, 0, NULL, NULL, NULL);
    }
    arg0->unk310.unk40 = (void *) &kar_a2d_effecthandle__near_8037c660;
    arg0->unk310.unk44 = (s32) arg0;
}

extern "C" void kar_a2d_effecthandle__near_8037c878(TireMgrOuter *arg0) {
    switch (arg0->unk35C->v98()) {
    case 0:
        arg0->unk0 = 0x2710;
        return;
    case 1:
        arg0->unk0 = 0x2711;
        return;
    case 2:
        arg0->unk0 = 0x2714;
        return;
    case 3:
        arg0->unk0 = 0x2840;
        return;
    case 4:
    case 5:
    case 6:
    case 7:
        arg0->unk0 = 0x7531;
        return;
    case 8:
    case 9:
        arg0->unk0 = 0x2908;
        return;
    case 11:
        kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DBCB8, &lbl_805DBCB0, 0);
        arg0->unk0 = fn_80312F6C();
        return;
    default:
        arg0->unk0 = 0x7531;
        return;
    }
}

struct RippleFadeState {
    char pad0[0xC];
    s32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    char pad1C[0x2C - 0x1C];
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    char pad38[0x40 - 0x38];
    f32 unk40;
    s32 unk44;
    char pad48[0x60 - 0x48];
    f32 unk60;
    Vec3f *unk64;
    s32 unk68;
    s32 unk6C;
    u8 unk70;
    char pad71[3];
    f32 unk74;
};

extern "C" void kar_a2d_effecthandle__near_8037c948(RippleFadeState *arg0) {
    if (arg0->unk68 != 0) {
        f32 t = 1.0f - ((f32) arg0->unk68 / (f32) arg0->unk6C);
        f32 v;
        if (arg0->unk70 != 0) {
            arg0->unk70 = 0;
            v = t + 0.05f;
        } else {
            v = t - 0.05f;
            arg0->unk70 = 1;
            if (v <= 0.0f) {
                v = 0.001f;
            }
        }
        arg0->unk34 = v;
        arg0->unk30 = v;
        arg0->unk2C = v;
        if (arg0->unk68 < 0x12) {
            arg0->unk60 = -0.5f + (((f32) arg0->unk68 / 18.0f) * arg0->unk74);
        }
        if (arg0->unk68 > 0) {
            arg0->unk68 = arg0->unk68 - 1;
            if (arg0->unk68 == 0) {
                arg0->unk44 = 0;
            }
        }
    }
}

extern "C" void kar_a2d_effecthandle__near_8037ca5c(RippleFadeState *arg0, s32 arg1, f32 farg0) {
    f32 sp10, spC, sp8;
    Vec3f *src = arg0->unk64;
    if (src != NULL) {
        sp8 = src->x;
        spC = src->y;
        sp10 = src->z;
    } else {
        sp10 = 0.0f;
        spC = 0.0f;
        sp8 = 0.0f;
    }
    arg0->unk6C = arg1;
    arg0->unk68 = arg1;
    arg0->unk74 = farg0;
    arg0->unkC = 2;
    arg0->unk10 = sp8;
    arg0->unk14 = spC;
    arg0->unk18 = sp10;
    arg0->unk44 = 1;
    arg0->unk34 = 0.0f;
    arg0->unk30 = 0.0f;
    arg0->unk2C = 0.0f;
    arg0->unk40 = 0.0f;
    arg0->unk60 = -0.19999999f;
}

extern "C" s32 fn_8037CAF0(void) {
    return 0;
}

extern "C" void *kar_a2d_effecthandle__near_8037d094(void);

extern "C" void kar_a2d_effecthandle__near_8037caf8(void) {
    kar_a2d_effecthandle__near_8037d094();
}

extern "C" void fn_8037CB18(RippleFadeState *arg0, Vec4f *arg1) {
    arg1->x = 0.5f;
    arg1->y = 0.0f;
    arg1->z = arg0->unk60;
    arg1->w = 0.0f;
    ((f32 *) arg1)[4] = 0.5f;
    ((f32 *) arg1)[5] = arg0->unk60;
}

static char lbl_804F345C[] = "GameEffect";
static char lbl_804F3468[] = "Singleton<GameEffect>";
static NamePair lbl_805DBCF0 = {lbl_804F3468, 0};
static ClassInfo3 lbl_804F3480 = {&lbl_805DBCF0, 0, 0};
static NamePair lbl_805DBCF8 = {lbl_804F345C, (char *) &lbl_804F3480};

struct GameEffectArchives {
    char pad0[0x3C];
    void *archives[7];
};

extern "C" void *kar_a2d_effecthandle__near_8037cf7c(void) {
    return ((GameEffectArchives *) kar_diag__803ad760(lbl_805DDB90, 0, &lbl_805DBCF8, &lbl_805DBCF0, 0))->archives[0];
}

extern "C" void *kar_a2d_effecthandle__near_8037cfb4(void) {
    return ((GameEffectArchives *) kar_diag__803ad760(lbl_805DDB90, 0, &lbl_805DBCF8, &lbl_805DBCF0, 0))->archives[1];
}

extern "C" void *kar_a2d_effecthandle__near_8037cfec(void) {
    return ((GameEffectArchives *) kar_diag__803ad760(lbl_805DDB90, 0, &lbl_805DBCF8, &lbl_805DBCF0, 0))->archives[2];
}

extern "C" void *kar_a2d_effecthandle__near_8037d024(void) {
    return ((GameEffectArchives *) kar_diag__803ad760(lbl_805DDB90, 0, &lbl_805DBCF8, &lbl_805DBCF0, 0))->archives[4];
}

extern "C" void *kar_a2d_effecthandle__near_8037d05c(void) {
    return ((GameEffectArchives *) kar_diag__803ad760(lbl_805DDB90, 0, &lbl_805DBCF8, &lbl_805DBCF0, 0))->archives[3];
}

extern "C" void *kar_a2d_effecthandle__near_8037d094(void) {
    return ((GameEffectArchives *) kar_diag__803ad760(lbl_805DDB90, 0, &lbl_805DBCF8, &lbl_805DBCF0, 0))->archives[5];
}

extern "C" void *kar_a2d_effecthandle__near_8037d0cc(void) {
    return ((GameEffectArchives *) kar_diag__803ad760(lbl_805DDB90, 0, &lbl_805DBCF8, &lbl_805DBCF0, 0))->archives[6];
}

extern "C" void kar_a2d_effecthandle__near_8037ce94(SpraySubMgr *arg0, s32 arg1) {
    ((s32 *) arg0)[0x4B4 / 4] = arg1;
}

#pragma push
#pragma dont_inline on
extern "C" void kar_a2d_effecthandle__near_8037ce9c(void) {
    kar_a2d_effecthandle__near_8037d05c();
}

extern "C" void kar_a2d_effecthandle__near_8037cebc(void) {
    kar_a2d_effecthandle__near_8037d024();
}
#pragma pop

extern "C" void kar_a2d_effecthandle__near_8037cedc(void *arg0, f32 *mtx) {
    f32 *f = (f32 *) arg0;
    kar_grcoll__803d1978(mtx, 0.0f, f[0x60 / 4], 0.0f);
    f[0x60 / 4] = f[0x60 / 4] + f[0x64 / 4];
}

extern "C" void fn_8037CF28(void *arg0, Vec4f *arg1) {
    f32 *f = (f32 *) arg0;
    arg1->x = 0.5f;
    arg1->y = 0.0f;
    arg1->z = f[0x68 / 4];
    arg1->w = 0.0f;
    ((f32 *) arg1)[4] = 0.5f;
    ((f32 *) arg1)[5] = f[0x68 / 4];
}

static char kar_src_a2d_modeleffect_804f3558[] = "a2d_modeleffect.h";
static char lbl_805DBD20[] = "jobj_";
static char lbl_804F356C[] = "ModelEffectContainer";
static char lbl_804F3584[] = "Singleton<ModelEffectContainer>";
static NamePair lbl_805DBD28 = {lbl_804F3584, 0};
static ClassInfo3 lbl_804F35A4 = {&lbl_805DBD28, 0, 0};
static NamePair lbl_805DBD30 = {lbl_804F356C, (char *) &lbl_804F35A4};

struct ModelHolder {
    void *vtbl;
    s32 pad4;
    s32 pad8;
    void *unkC;
    u8 unk10;
    u8 pad11[3];
};

extern "C" void *kar_a2d_effecthandle__near_8037e0e0(ModelHolder *arg0) {
    *(void **) arg0 = lbl_804BDD98;
    arg0->pad4 = 0;
    arg0->pad8 = 0;
    ((DiagObj *) arg0)->Init();
    *(void **) arg0 = lbl_804BDDD8;
    arg0->unkC = 0;
    arg0->unk10 = 0;
    return arg0;
}

extern "C" void *kar_a2d_effecthandle__near_8037dde0(ModelHolder *arg0, s32 *arg1) {
    *(void **) arg0 = lbl_804BDD98;
    arg0->pad4 = 0;
    arg0->pad8 = 0;
    ((DiagObj *) arg0)->Init();
    *(void **) arg0 = lbl_804BDDD8;
    arg0->unkC = NULL;
    if (arg1 != NULL) {
        s32 joint = *arg1;
        if (arg0->unkC == NULL) {
            arg0->unkC = HSD_JObjLoadJoint(joint);
            ASSERT2(0x24, arg0->unkC != NULL, kar_src_a2d_modeleffect_804f3558, lbl_805DBD20);
            HSD_JObjSetFlagsAll(arg0->unkC, 0x10);
        }
        if (arg0->unkC != NULL) {
            kar_a2d_game_lib__802894bc(arg0->unkC, arg1, 0);
        }
    }
    arg0->unk10 = 0;
    return arg0;
}

extern "C" void *kar_a2d_effecthandle__near_8037dec0(ModelHolder *arg0, s32 arg1) {
    *(void **) arg0 = lbl_804BDD98;
    arg0->pad4 = 0;
    arg0->pad8 = 0;
    ((DiagObj *) arg0)->Init();
    *(void **) arg0 = lbl_804BDDD8;
    arg0->unkC = NULL;
    s32 *ptr = ((s32 **) ((char *) kar_diag__803ad760(lbl_805DDBA0, 0, &lbl_805DBD30, &lbl_805DBD28, 0) + 4))[arg1];
    if (ptr != NULL) {
        s32 joint = *ptr;
        if (arg0->unkC == NULL) {
            arg0->unkC = HSD_JObjLoadJoint(joint);
            ASSERT2(0x24, arg0->unkC != NULL, kar_src_a2d_modeleffect_804f3558, lbl_805DBD20);
            HSD_JObjSetFlagsAll(arg0->unkC, 0x10);
        }
        if (arg0->unkC != NULL) {
            kar_a2d_game_lib__802894bc(arg0->unkC, ptr, 0);
        }
    }
    arg0->unk10 = 0;
    return arg0;
}

namespace {
extern "C" void kar_a2d_effecthandle__near_8037e14c(char *arg0);
}

extern "C" void kar_a2d_effecthandle__near_8037e14c(char *arg0, s32 *arg1) {
    if (*(s32 **) (arg0 + 0xB8) == NULL) {
        *(s32 **) (arg0 + 0xB8) = arg1;
        char *var_r31 = arg0;
        s32 var_r30 = 0;
        do {
            if (arg1 != NULL) {
                s32 joint = *arg1;
                if (*(void **) (var_r31 + 0x18) == NULL) {
                    *(void **) (var_r31 + 0x18) = HSD_JObjLoadJoint(joint);
                    ASSERT2(0x24, *(void **) (var_r31 + 0x18) != NULL, kar_src_a2d_modeleffect_804f3558, lbl_805DBD20);
                    HSD_JObjSetFlagsAll(*(void **) (var_r31 + 0x18), 0x10);
                }
                if (*(void **) (var_r31 + 0x18) != NULL) {
                    kar_a2d_game_lib__802894bc(*(void **) (var_r31 + 0x18), arg1, 0);
                }
            }
            var_r30 += 1;
            var_r31 += 0x14;
        } while (var_r30 < 6);
    }
}

extern "C" void kar_a2d_effecthandle__near_8037e374(char *arg0, s32 arg1) {
    *(u8 *) (arg0 + 0xC) = 1;
    *(s32 *) (arg0 + 0x10) = arg1;
}

extern "C" void *kar_a2d_effecthandle__near_8037dfc4(char *arg0) {
    *(void **) arg0 = lbl_804BDD30;
    *(s32 *) (arg0 + 4) = 0;
    *(s32 *) (arg0 + 8) = 0;
    ((DiagObj *) arg0)->Init();
    *(void **) arg0 = lbl_804BDD58;
    __construct_array(arg0 + 0xC, (void *) &kar_a2d_effecthandle__near_8037e0e0, &fn_8028DFC8, 0x14, 6);
    *(s32 *) (arg0 + 0xB8) = 0;
    s32 idx = 0;
    char *item = arg0;
    do {
        if (*(u8 *) (item + 0x1C) != 0) {
            HSD_JObjSetFlagsAll(*(void **) (item + 0x18), 0x10);
            *(u8 *) (item + 0x1C) = 0;
        }
        *(u8 *) (arg0 + 0x84 + idx) = 0;
        idx += 1;
        item += 0x14;
    } while (idx < 6);
    *(s32 *) (arg0 + 0x8C) = 0;
    *(f32 *) (arg0 + 0x90) = 1.0f;
    *(f32 *) (arg0 + 0x94) = 1.0f;
    *(f32 *) (arg0 + 0x98) = 0.0f;
    *(u8 *) (arg0 + 0x9C) = 0;
    if (*(s32 *) ((char *) kar_diag__803ad760(lbl_805DDBA0, 0, &lbl_805DBD30, &lbl_805DBD28, 0) + 8) != 0) {
        kar_a2d_effecthandle__near_8037e14c(arg0);
    }
    return arg0;
}

extern "C" void kar_a2d_effecthandle__near_8037e210(char *arg0) {
    if (*(u8 *) (arg0 + 0x9C) != 0) {
        *(f32 *) (arg0 + 0x98) = 0.0625f * *(f32 *) (arg0 + 0x90) + *(f32 *) (arg0 + 0x98);
        for (;;) {
            f32 v = *(f32 *) (arg0 + 0x98);
            u8 fire;
            if (v >= 1.0f) {
                fire = 1;
                *(f32 *) (arg0 + 0x98) = v - 1.0f;
            } else {
                if (v < 0.0001f) {
                    *(f32 *) (arg0 + 0x98) = 0.0f;
                }
                fire = 0;
            }
            if (fire == 0) {
                break;
            }
            char *item = arg0 + *(s32 *) (arg0 + 0x8C) * 0x14;
            if (*(u8 *) (item + 0x1C) != 0) {
                HSD_JObjSetFlagsAll(*(void **) (item + 0x18), 0x10);
                *(u8 *) (item + 0x1C) = 0;
            }
            char *item2 = arg0 + (*(s32 *) (arg0 + 0x8C) * 0x14 + 0xC);
            HSD_JObjClearFlagsAll(*(void **) (item2 + 0xC), 0x10);
            HSD_JObjReqAnimAll(*(void **) (item2 + 0xC), 0.0f);
            *(u8 *) (item2 + 0x10) = 1;
            HSD_JObj *jobj = *(HSD_JObj **) (item2 + 0xC);
            jobj->translate[0] = *(f32 *) (arg0 + 0xA0);
            jobj->translate[1] = *(f32 *) (arg0 + 0xA4);
            jobj->translate[2] = *(f32 *) (arg0 + 0xA8);
            kar_a2d_game_lib__near_80289768(*(void **) (arg0 + *(s32 *) (arg0 + 0x8C) * 0x14 + 0x18), 0xFFFF, *(f32 *) (arg0 + 0x94));
            s32 next = *(s32 *) (arg0 + 0x8C) + 1;
            *(s32 *) (arg0 + 0x8C) = next;
            if (next >= 6) {
                *(s32 *) (arg0 + 0x8C) = 0;
            }
        }
    }
}

static char lbl_804F35B0[] = "WipeEffectContainer";
static char lbl_804F35C4[] = "Singleton<WipeEffectContainer>";
static NamePair lbl_805DBD38 = {lbl_804F35C4, 0};
static ClassInfo3 lbl_804F35E4 = {&lbl_805DBD38, 0, 0};
static NamePair lbl_805DBD40 = {lbl_804F35B0, (char *) &lbl_804F35E4};

struct WipeEffectContainerRoot {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 kar_a2d_effecthandle__near_8037e384(void) {
    return kar_a2d_game_lib__near_80289928(((WipeEffectContainerRoot *) kar_diag__803ad760(lbl_805DDB9C, 0, &lbl_805DBD40, &lbl_805DBD38, 0))->unk10);
}

struct IdxNamePair {
    s32 idx;
    char *name;
};

static char lbl_804F3398[] = "com00_image_desc";
static char lbl_804F33AC[] = "com01_image_desc";
static char lbl_804F33C0[] = "com02_image_desc";
static char lbl_804F33D4[] = "com03_image_desc";
static char lbl_804F33E8[] = "com04_image_desc";
static char lbl_804F33FC[] = "com05_image_desc";
static char lbl_804F3410[] = "com06_image_desc";

static IdxNamePair lbl_804F3424[7] = {
    {0, lbl_804F3398},
    {1, lbl_804F33AC},
    {2, lbl_804F33C0},
    {3, lbl_804F33D4},
    {4, lbl_804F33E8},
    {5, lbl_804F33FC},
    {6, lbl_804F3410},
};

extern "C" char *kar_a2d_effecthandle__near_8037cf54(u32 arg0) {
    if (arg0 < 7) {
        return lbl_804F3424[arg0].name;
    }
    return NULL;
}

extern "C" void fn_8037D528(void *arg0, Vec4f *arg1) {
    arg1->x = 0.5f;
    arg1->y = 0.0f;
    arg1->z = 1.0f;
    arg1->w = 0.0f;
    ((f32 *) arg1)[4] = 0.5f;
    ((f32 *) arg1)[5] = 1.0f;
}
