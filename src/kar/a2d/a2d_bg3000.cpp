#include <dolphin/types.h>

extern "C" {
#include <global.h>
#include <sysdolphin/jobj.h>
}

struct Vec3f {
    f32 x, y, z;
};

struct Vec4f {
    f32 x, y, z, w;
};

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

struct ParticleBuf {
    s32 pad0[2];
    Vec3f pos;
    Vec4f quat;
    Vec3f scale;
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

struct GameEffectItem : public GameEffectItemBase {
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    Vec3f *unk24;
    Vec4f *unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    u8 unk38;
    u8 unk39;
    ParticleHandle *unk3C;
    void *unk40;
    s32 unk44;
    u16 unk48;
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
    virtual s32 v30();
    virtual u8 v34();
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
    virtual u8 v68();
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
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4(Vec3f);
    virtual void vD8(f32 *);
};

class GeneratorIface {
public:
    virtual void a00();
    virtual void a04();
    virtual void a08();
    virtual void a0c();
    virtual void a10();
    virtual void a14();
    virtual void a18();
    virtual void a1c();
    virtual void SetTarget(void *, void *);
    virtual void Commit();
};

extern "C" {

void *kar_diag__803ad760(s32, s32, void *, void *, s32);
void *fn_8038CB28(s32);
void fn_8038CB78(void *);
void *fn_8038D0A8(void *, void *);
void __construct_array(void *, void *, void *, s32, s32);
void __destroy_arr(void *, void *, s32, s32);

void fn_802CD8DC(void);
void fn_8029187C(void);
void fn_802918B4(void);
void fn_802918F8(void);
void fn_80291930(void);

void *kar_a2d_effecthandle__8037b028(GameEffectItem *, s32, s32, void *, Vec3f *, Vec4f *, f32);
void kar_a2d_effecthandle__near_8037b33c(GameEffectItem *, u8);

void kar_a2d_game_effect__near_8037afd0(GameEffectItem *, u8);

void kar_a2d_game_lib__near_8028967c(void *, u16, f32, f32);
void kar_a2d_game_lib__near_80289590(void *, u16, f32);
void kar_a2d_game_lib__near_802895c8(void *, u16, f32, f32);
void kar_a2d_game_lib__near_80289730(void *, u16, f32);
void kar_a2d_game_lib__near_80289768(void *, u16, f32);
u8 kar_a2d_game_lib__near_802897e0(void *);
f32 kar_a2d_game_lib__near_802899d0(void *);
u32 kar_a2d_game_lib__near_8028a66c(void *, void *, char *);
u16 kar_a2d_game_lib__near_8028ac98(u16, u16, u16);

void *kar_a2d_game_audio__near_80379398(void *);
void kar_a2d_game_audio__near_80379784(void *, s32, void *);

void kar_a2d_refract__near_803845f4(void *);
void kar_a2d_refract__near_80384600(void *, s32);
void kar_a2d_refract__near_80384670(void *, s32, void *, f32);
void kar_a2d_refract__near_803848e0(void *, s32, f32 *, f32);

u8 kar_fl_indirectload__80391f10(void *, void *);

s32 kar_lbaudio_is_track_handle_playing(s32);
void kar_lbvector_dirs_to_euler(f32 *, f32 *, const void *);

f32 HSD_Randf(void);
s32 HSD_Randi(s32);
void PSVECAdd(void *, void *, void *);
void PSVECSubtract(void *, void *, void *);
void PSVECScale(void *, void *, f32);
f32 PSVECMag(f32 *, f32, f32);
void PSVECNormalize(void *, void *);
void PSVECCrossProduct(void *, void *, void *, f32, f32);

f32 fn_80296264(f32);
f32 fn_8029626C(f32);
f32 fn_802D4C30(f32);
f64 fn_803BCB64(void);

s32 strcmp(const char *, const char *);

void OSReport(const char *, ...);

extern void *lbl_804BCE14;
extern void *lbl_804BDF2C;
extern void *lbl_804BDF70;
extern void *lbl_804BE0C4;
extern void *lbl_804BE104;
extern void *lbl_804D7300;
extern void *lbl_804D7700;
extern void *lbl_804BF4DC;
extern void *lbl_804F5208;
extern void *lbl_804BF3C0;

extern f32 lbl_804E55E0;
extern f32 lbl_804E5614;

extern char lbl_804E4F20[];

extern s32 lbl_805DDBC0;
extern s32 lbl_805DDBC8;
extern void *lbl_805DDC40;
extern s32 lbl_805DDC70;

extern char lbl_805DADE0[];
extern char lbl_805DADE8[];
extern char lbl_805DADF0[];
extern char lbl_805DADF8[];
extern char lbl_805DAE00[];
extern char lbl_805DAE08[];

}

static char lbl_804E588C[0x25] = "!(jobj->flags & JOBJ_USE_QUATERNION)";

static char lbl_804E58B4[0x88] = {
    't', 'r', 'a', 'n', 's', 'l', 'a', 't', 'e', 0, 0, 0,
    'U', 'K', 'I', 'S', 'H', 'I', 'M', 'A', 0, 0, 0, 0,
    'U', 'K', 'I', 'K', 'A', 'G', 'E', '*', 0, 0, 0, 0,
    'j', 'o', 'b', 'j', 'S', 'h', 'a', 'd', 'o', 'w', '_', 0,
    'U', 'K', 'I', 'S', 'H', 'I', 'M', 'A', '_', 'J', 'U', 'M', 'P', '_', 'A', 0,
    'j', 'o', 'b', 'j', 'J', 'u', 'm', 'p', '_', 0, 0, 0,
    's', 'w', 'i', 't', 'c', 'h', 'j', 'o', 'b', 'j', '_', 0,
    'U', 'K', 'I', 'H', 'A', 'S', 'H', 'I', '0', '0', '*', 0,
    'U', 'K', 'I', 'H', 'A', 'S', 'H', 'I', '0', '1', '*', 0,
    'b', 'e', 'l', 't', '0', 'j', 'o', 'b', 'j', '_', 0, 0,
    'b', 'e', 'l', 't', '1', 'j', 'o', 'b', 'j', '_', 0, 0,
};

static char lbl_804E593C[13] = "GROUND_BELT1";
static char lbl_804E594C[372] = "GROUND_BELT2";
static char lbl_804E5AC0[20] = "GROUND_MAWARUSHIMA*";

static void *lbl_804E5AEC[3] = { 0, 0, 0 };
static void *lbl_804E5AF8[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

static char lbl_804E5C60[0x28] = "PostDrawEffect";

static char lbl_805DAC1C[7] = "cloud_";
static char lbl_805DAC24[5] = "jobj";
static char lbl_805DAC2C[6] = "wool_";
static char kar_srcfile_jobj_h_805dac34[7] = "jobj.h";
static char lbl_805DAC3C[7] = "rotate";
static char lbl_805DAC44[6] = "jobj_";
static char lbl_805DAC4C[8] = "SWITCH*";
static s32 lbl_805DAC54 = 0;
static char lbl_805DAC58[5] = "hit3";
static char lbl_805DAC60[3] = "ja";
static char lbl_805DAC64[3] = "jb";
static char lbl_805DAC68[3] = "jc";

static const Vec3f lbl_8048A3C0 = { 0.0f, 1.0f, 0.0f };
static const Vec3f lbl_8048A3CC = { 0.0f, 0.0f, 0.0f };

static char lbl_805DAAD0[8];
static char lbl_805DAAD8[8];
static char lbl_805DABE8[8];
static char lbl_805DABF0[8];
static char lbl_805DADE0[8];
static char lbl_805DADE8[8];

#define ASSERT2(line, cond, file, str) \
    ((cond) ? ((void) 0) : __assert(file, line, str))

struct DiagResult {
    char pad0[0x14];
    s32 unk14;
    void *unk18;
};

struct Bg3000ExtTable {
    char pad0[4];
    f32 unk4, unk8, unkC, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
};

struct Bg3000DayTable {
    f32 unk0, unk4;
    char pad8[8];
    f32 unk10, unk14;
};

#define EXT_TABLE_SELECT(t) \
    Bg3000ExtTable *t = (Bg3000ExtTable *) (lbl_804E4F20 + 0x6F4); \
    if ((u32) ((DiagResult *) kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DABF0, &lbl_805DABE8, 0))->unk14 == 1) { \
        t = (Bg3000ExtTable *) (lbl_804E4F20 + 0x6C0); \
    }

struct Bg3000RegionTable {
    char raw[0x84];
};

static char lbl_804E6320[132];
static char lbl_804E63A4[132];

struct Bg3000Leaf {
    HSD_JObj *jobj;
    Vec3f *srcPos;
    Vec3f *dstPos;
    s32 state;
    f32 lo;
    f32 accum;
    f32 rate1;
    f32 rate2;
};

struct Bg3000ArmA {
    HSD_JObj *unk0;
    HSD_JObj *unk4;
    HSD_JObj *unk8;
    char pad0C[4];
    HSD_JObj *unk10;
    HSD_JObj *unk14;
    HSD_JObj *unk18;
    Vec3f unk1C;
    Vec3f unk28;
    s32 unk34;
    char pad38[4];
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    char pad3F[1];
    s32 unk40;
    u32 unk44;
    u32 unk48;
    char audio1[0x3C];
    u32 unk88;
    char audio2[0x3C];
    char audio3[0x3C];
    char refract0[4];
    char refract1[4];
    char refract2[4];
    s32 unk110;
    s32 unk114;
    s32 unk118;
    s32 unk11C;
};

struct Bg3000ArmB {
    HSD_JObj *unk0;
    HSD_JObj *unk4;
    HSD_JObj *unk8;
    HSD_JObj *unkC;
    HSD_JObj *unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    u32 unk30;
    u32 unk34;
    u8 unk38;
    u8 unk39;
    u8 unk3A;
    u8 unk3B;
    u8 unk3C;
    char pad3D[0x7C - 0x3D];
    char audio1[0x3C];
    char audio2[0x3C];
    u8 unkF4;
    u8 unkF5;
    char pad_end[2];
    char refract0[4];
    char refract1[4];
    char refract2[4];
};

struct Bg3000ArmC {
    HSD_JObj *unk0;
    HSD_JObj *unk4;
    HSD_JObj *unk8;
    HSD_JObj *unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    f32 unk20;
    char pad24[1];
    u8 unk19;
    char pad26[2];
    char refract0[4];
    char refract1[4];
    char refract2[4];
};

struct Bg3000Main {
    void *unk0;
    Bg3000Leaf leaves[3];
    s32 unk64;
    void *unk68;
    void *unk6C;
    s32 unk70;
    void *unk74;
    void *unk78;
    Bg3000ArmA *unk7C;
    Bg3000ArmB *unk80;
    Bg3000ArmC *unk84;
    char pad88[0xC];
    HSD_JObj *unk94;
    HSD_JObj *unk98;
    GameEffectItem unk9C;
    HSD_JObj *unkE8;
    HSD_JObj *unkEC;
    HSD_JObj *unkF0;
    HSD_JObj *unkF4;
    s32 unkF8;
    s32 unkFC;
    s32 unk100;
    s32 unk104;
};

extern "C" Bg3000Main *kar_a2d_bg3000__80335020(Bg3000Main *arg0);
extern "C" void kar_a2d_bg3000__near_80335a1c(Bg3000Main *arg0);
extern "C" void kar_a2d_bg3000__near_80335a6c(Bg3000Main *arg0);
extern "C" void kar_a2d_bg3000__near_80335ed4(Bg3000Main *arg0);
extern "C" void fn_803367D4(void);
extern "C" void kar_a2d_bg3000__near_803367d8(Bg3000Main *arg0, void *arg1);
extern "C" void kar_a2d_bg3000__near_8033682c(Bg3000Main *arg0, void *arg1);
extern "C" Bg3000ArmA *kar_a2d_bg3000__80336874(Bg3000ArmA *arg0, u8 arg1);
extern "C" void kar_a2d_bg3000__near_80336d94(Bg3000ArmA *arg0);
extern "C" void kar_a2d_bg3000__near_80336df0(Bg3000ArmA *arg0);
extern "C" f32 kar_a2d_bg3000__near_803373ec(f32 farg0);
extern "C" void kar_a2d_bg3000__near_80337848(Bg3000ArmA *arg0, void *arg1);
extern "C" void kar_a2d_bg3000__near_80337e58(Bg3000ArmA *arg0, void *arg1);
extern "C" Vec3f *kar_a2d_bg3000__near_80337fa8(Bg3000ArmA *arg0, s32 arg1);
extern "C" Bg3000ArmB *kar_a2d_bg3000__80338000(Bg3000ArmB *arg0, u8 arg1);
extern "C" void kar_a2d_bg3000__near_8033873c(Bg3000ArmB *arg0);
extern "C" void kar_a2d_bg3000__near_80338dec(Bg3000ArmB *arg0, void *arg1);
extern "C" Bg3000ArmC *kar_a2d_bg3000__80339754(Bg3000ArmC *arg0, u8 arg1);
extern "C" void kar_a2d_bg3000__near_80339a74(Bg3000ArmC *arg0);
extern "C" f32 kar_a2d_bg3000__near_80339fc0(f32 farg0);
extern "C" void kar_a2d_bg3000__near_8033a40c(Bg3000ArmC *arg0, void *arg1);
extern "C" void kar_a2d_bg3000__near_8033a61c(Bg3000ArmC *arg0, void *arg1);
extern "C" Bg3000Main *kar_a2d_bg3000__near_8033a7d4(Bg3000Main *arg0, s16 arg1);
extern "C" Bg3000RegionTable *kar_a2d_bg3000__near_8033ab00(void);
extern "C" Bg3000RegionTable *kar_a2d_bg3000__near_8033ab50(u32 arg0);
extern "C" void kar_a2d_bg3000__near_8033ab6c(f32 *arg0);

static const f32 lbl_805E4288 = 0.0f;
static const f32 lbl_805E42A0 = 1.0f;
static const f64 lbl_805E4310 = 1.5707963267948966;
static const f64 lbl_805E4318 = 6.283185307179586;
static const f64 lbl_805E4320 = 3.141592653589793;
static const f32 lbl_805E4328 = 0.1666666865348816f;
static const f32 lbl_805E432C = 0.00833282433450222f;
static const f32 lbl_805E4330 = 0.000195878412341699f;
static const f32 lbl_805E4334 = 0.9999998211860657f;
static const f32 lbl_805E4338 = 0.4999939501285553f;
static const f32 lbl_805E433C = 0.041636329144239426f;
static const f32 lbl_805E4340 = 0.0013400710886344314f;
static const f64 lbl_805E4348 = 0.7853981633974483;

static inline f32 kar_bg3000_poly(f32 y) {
    f32 z;
    f32 t;
    if (y <= lbl_805E4348) {
        z = y * y;
        t = z * __fnmsubs(z, __fnmsubs(lbl_805E4330, z, lbl_805E432C), lbl_805E4328);
        return y * (lbl_805E42A0 - t);
    }
    z = (f32) (lbl_805E4310 - (f64) y);
    z = z * z;
    t = z * __fnmsubs(z, __fnmsubs(lbl_805E4340, z, lbl_805E433C), lbl_805E4338);
    return lbl_805E4334 - t;
}

static inline f32 kar_bg3000_half(f32 y) {
    if (y <= lbl_805E4310) {
        return kar_bg3000_poly(y);
    }
    return kar_bg3000_poly((f32) (lbl_805E4320 - (f64) y));
}

static inline f32 kar_bg3000_reduce(f32 y) {
    while (y > lbl_805E4318) {
        y = (f32) (y - lbl_805E4318);
    }
    if (y <= lbl_805E4320) {
        return kar_bg3000_half(y);
    }
    return -kar_bg3000_half((f32) (y - lbl_805E4320));
}

extern "C" Bg3000Main *kar_a2d_bg3000__80335020(Bg3000Main *arg0) {
    char * const g_bg = lbl_804E4F20;
    arg0->unk0 = &lbl_804BCE14;
    arg0->unk0 = &lbl_804E5AF8;
    arg0->leaves[0].rate1 = 0;
    arg0->unk68 = NULL;
    arg0->unk6C = NULL;
    arg0->unk70 = 0;
    arg0->unk74 = NULL;
    arg0->unk78 = NULL;
    arg0->unk7C = NULL;
    arg0->unk80 = NULL;
    arg0->unk84 = NULL;
    *(void **) &arg0->unk9C = lbl_804BDF2C;
    arg0->unk9C.unk4 = 0;
    arg0->unk9C.unk8 = 0;
    arg0->unk9C.Init();
    *(void **) &arg0->unk9C = lbl_804BDF70;
    kar_a2d_effecthandle__8037b028(&arg0->unk9C, -1, 0, 0, NULL, 0, 0);

    Bg3000ArmA *newA = (Bg3000ArmA *) fn_8038CB28(0x120);
    if (newA != NULL) {
        newA = kar_a2d_bg3000__80336874(newA, (u8) 0);
    }
    Bg3000ArmA *oldA = arg0->unk7C;
    if (oldA != newA) {
        if (oldA != NULL) {
            __destroy_arr(oldA->refract0, kar_a2d_refract__near_80384600, 4, 3);
            fn_8038CB78(oldA);
        }
        arg0->unk7C = newA;
    }

    Bg3000ArmB *newB = (Bg3000ArmB *) fn_8038CB28(0x11C);
    if (newB != NULL) {
        newB = kar_a2d_bg3000__80338000(newB, (u8) 0);
    }
    Bg3000ArmB *oldB = arg0->unk80;
    if (oldB != newB) {
        if (oldB != NULL) {
            __destroy_arr(oldB->refract0, kar_a2d_refract__near_80384600, 4, 3);
            fn_8038CB78(oldB);
        }
        arg0->unk80 = newB;
    }

    Bg3000ArmC *newC = (Bg3000ArmC *) fn_8038CB28(0x30);
    if (newC != NULL) {
        newC = kar_a2d_bg3000__80339754(newC, (u8) 0);
    }
    Bg3000ArmC *oldC = arg0->unk84;
    if (oldC != newC) {
        if (oldC != NULL) {
            kar_a2d_refract__near_80384600(oldC->refract2, -1);
            kar_a2d_refract__near_80384600(oldC->refract1, -1);
            kar_a2d_refract__near_80384600(oldC->refract0, -1);
            fn_8038CB78(oldC);
        }
        arg0->unk84 = newC;
    }

    arg0->unk94 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, (void *) "KUMO*");
    if (arg0->unk94 == NULL) {
        __assert(g_bg + 0x8BC, 0xB5, lbl_805DAC1C);
    }
    kar_a2d_bg3000__near_80335a1c(arg0);

    HSD_JObj *j1 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0x8CC);
    if (j1 == NULL) {
        __assert(g_bg + 0x8D8, 0x229, lbl_805DAC24);
    }
    arg0->leaves[0].jobj = j1;
    arg0->leaves[0].lo = 0.2f;
    arg0->leaves[0].accum = 0.12f;
    arg0->leaves[0].state = 0;
    arg0->leaves[0].rate1 = 0.0f;
    arg0->leaves[0].rate2 = 0.0f;
    if (arg0->leaves[0].jobj != NULL) {
        HSD_JObjSetFlagsAll(j1, 0x10);
    }
    HSD_JObj *j2 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0x8E8);
    if (j2 == NULL) {
        __assert(g_bg + 0x8D8, 0x229, lbl_805DAC24);
    }
    arg0->leaves[1].jobj = j2;
    arg0->leaves[1].lo = 0.12f;
    arg0->leaves[1].accum = 0.1f;
    arg0->leaves[1].state = 0;
    arg0->leaves[1].rate1 = 0.0f;
    arg0->leaves[1].rate2 = 0.0f;
    if (arg0->leaves[1].jobj != NULL) {
        HSD_JObjSetFlagsAll(j2, 0x10);
    }
    HSD_JObj *j3 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0x8F4);
    if (j3 == NULL) {
        __assert(g_bg + 0x8D8, 0x229, lbl_805DAC24);
    }
    arg0->leaves[2].jobj = j3;
    arg0->leaves[2].lo = 0.24f;
    arg0->leaves[2].accum = 0.12f;
    arg0->leaves[2].state = 0;
    arg0->leaves[2].rate1 = 0.0f;
    arg0->leaves[2].rate2 = 0.0f;
    if (arg0->leaves[2].jobj != NULL) {
        HSD_JObjSetFlagsAll(j3, 0x10);
    }

    arg0->unkE8 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0x900);
    arg0->unkEC = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0x90C);
    arg0->unkF0 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0x918);
    arg0->unkF4 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0x924);
    if (arg0->unkE8 == NULL) {
        __assert(g_bg + 0x8BC, 0xC3, g_bg + 0x930);
    }
    if (arg0->unkEC == NULL) {
        __assert(g_bg + 0x8BC, 0xC4, g_bg + 0x93C);
    }
    if (arg0->unkF0 == NULL) {
        __assert(g_bg + 0x8BC, 0xC5, g_bg + 0x948);
    }
    if (arg0->unkF4 == NULL) {
        __assert(g_bg + 0x8BC, 0xC6, g_bg + 0x954);
    }
    arg0->unk68 = &arg0->unkE8->translate;
    arg0->unk6C = &arg0->unkEC->translate;
    HSD_JObj *j4 = arg0->unkF4;
    arg0->unk74 = &arg0->unkF0->translate;
    arg0->unk78 = &j4->translate;
    arg0->unk98 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0x960);
    if (arg0->unk98 == NULL) {
        __assert(g_bg + 0x8BC, 0xCE, lbl_805DAC2C);
    }
    arg0->unkF8 = 0;
    arg0->unkFC = 0;
    arg0->unk100 = 0;
    arg0->unk104 = 0;
    return arg0;
}

extern "C" void kar_a2d_bg3000__near_80335a1c(Bg3000Main *arg0) {
    kar_a2d_game_lib__near_80289768(arg0->unk94, 0xFFFF, 0.25f);
    kar_a2d_game_lib__near_80289730(arg0->unk94, 0xFFFF, 0.0f);
}

extern "C" void kar_a2d_bg3000__near_80335a6c(Bg3000Main *arg0) {
    Bg3000ArmA *a = arg0->unk7C;
    a->unk1C.x = 0.0f;
    a->unk1C.z = 0;
    a->unk1C.y = 1;
    a->unk28.x = 0;
    a->unk28.y = 0;
    a->unk28.z = 0;
    a->unk110 = 0;
    a->unk114 = 0;
    a->unk118 = 0;
    a->unk11C = 0;
    if (a->unk0 == NULL) {
        __assert("jobj.h", 0x3C6, lbl_805DAC24);
    }
    a->unk0->translate.y = 0.0f;
    if (!(a->unk0->flags & MTX_INDEP_SRT)) {
        HSD_JObjSetMtxDirty(a->unk0);
    }
    if (a->unk4 == NULL) {
        __assert("jobj.h", 0x325, lbl_805DAC24);
    }
    a->unk4->scale.x = 1.0f;
    if (!(a->unk4->flags & MTX_INDEP_SRT)) {
        HSD_JObjSetMtxDirty(a->unk4);
    }
    kar_a2d_bg3000__near_80336d94(a);
    kar_a2d_game_lib__near_8028967c(a->unk8, 0xFFFF, 1.0f, 100.0f);
    kar_a2d_game_lib__near_80289590(a->unk8, 0xFFFF, 1.0f);
    kar_a2d_game_lib__near_80289768(a->unk8, 0xFFFF, 1.0f);
    kar_a2d_game_lib__near_80289730(a->unk14, 0xFFFF, 0.0f);
    kar_a2d_game_lib__near_80289730(a->unk18, 0xFFFF, 0.0f);
    kar_a2d_game_lib__near_80289768(a->unk14, 0xFFFF, 0.0f);
    kar_a2d_game_lib__near_80289768(a->unk18, 0xFFFF, 0.0f);

    Bg3000ArmB *b = arg0->unk80;
    b->unk20 = 0.0f;
    b->unk2C = 0.0f;
    b->unk24 = 0.0f;
    b->unk28 = 0.0f;
    b->unk30 = 0;
    b->unk34 = 0;
    b->unk38 = 0;
    b->unkF4 = 0;
    b->unk39 = 0;
    b->unk3A = 0;
    b->unk3B = 0;
    b->unk3C = 0;
    kar_a2d_game_lib__near_8028967c(b->unk8, 0xFFFF, 1.0f, 100.0f);
    kar_a2d_game_lib__near_80289590(b->unk8, 0xFFFF, 1.0f);
    kar_a2d_game_lib__near_80289768(b->unk8, 0xFFFF, 1.0f);
    kar_a2d_game_lib__near_8028967c(b->unkC, 0xFFFF, 1.0f, 100.0f);
    kar_a2d_game_lib__near_80289590(b->unkC, 0xFFFF, 1.0f);
    kar_a2d_game_lib__near_80289768(b->unkC, 0xFFFF, 1.0f);
    kar_a2d_game_lib__near_8028967c(b->unk10, 0xFFFF, 1.0f, 100.0f);
    kar_a2d_game_lib__near_80289590(b->unk10, 0xFFFF, 1.0f);
    kar_a2d_game_lib__near_80289768(b->unk10, 0xFFFF, 1.0f);

    Bg3000ArmC *c = arg0->unk84;
    if (c->unk0 == NULL) {
        __assert("jobj.h", 0x2B8, lbl_805DAC24);
    }
    if (c->unk0->flags & USE_QUATERNION) {
        __assert("jobj.h", 0x2B9, lbl_804E588C);
    }
    c->unk0->rotate.y = 0.0f;
    if (!(c->unk0->flags & MTX_INDEP_SRT)) {
        HSD_JObjSetMtxDirty(c->unk0);
    }
    c->unk10 = 0;
    c->unk14 = 0;
    c->unk18 = 0;
    c->unk1C = 0;
    c->unk20 = 0.0f;
    arg0->unk64 = 0;
    arg0->leaves[0].lo = 0.0f;
    arg0->leaves[0].accum = 0.0f;
    arg0->leaves[1].state = 0;
    arg0->leaves[1].lo = 0.0f;
    arg0->leaves[1].accum = 0.0f;
    arg0->leaves[2].state = 0;
    arg0->leaves[2].lo = 0.0f;
    arg0->leaves[2].accum = 0.0f;
    kar_a2d_game_lib__near_80289768(arg0->unk94, 0xFFFF, 0.25f);
    kar_a2d_game_lib__near_80289730(arg0->unk94, 0xFFFF, 0.0f);
    arg0->unkF8 = 0;
    arg0->unkFC = 0;
    arg0->unk100 = 0;
    arg0->unk104 = 0;
}

extern "C" void kar_a2d_bg3000__near_80335ed4(Bg3000Main *arg0) {
    kar_a2d_bg3000__near_80336df0(arg0->unk7C);
    kar_a2d_bg3000__near_8033873c(arg0->unk80);
    kar_a2d_bg3000__near_80339a74(arg0->unk84);
    if (arg0->unkF4 == 0) {
        kar_a2d_game_effect__near_8037afd0(&arg0->unk9C, 0);
        kar_a2d_effecthandle__8037b028(&arg0->unk9C, 0x2841, 1, arg0->unk98, NULL, NULL, 0.0f);
    }
}

extern "C" void fn_803367D4(void) {
}

extern "C" void kar_a2d_bg3000__near_803367d8(Bg3000Main *arg0, void *arg1) {
    kar_a2d_bg3000__near_80337848(arg0->unk7C, arg1);
    kar_a2d_bg3000__near_8033a40c(arg0->unk84, arg1);
    kar_a2d_bg3000__near_80338dec(arg0->unk80, arg1);
}

extern "C" void kar_a2d_bg3000__near_8033682c(Bg3000Main *arg0, void *arg1) {
    kar_a2d_bg3000__near_80337e58(arg0->unk7C, arg1);
    kar_a2d_bg3000__near_8033a61c(arg0->unk84, arg1);
}

extern "C" Bg3000ArmA *kar_a2d_bg3000__80336874(Bg3000ArmA *arg0, u8 arg1) {
    arg0->unk1C.z = 0.0f;
    arg0->unk1C.y = 0.0f;
    arg0->unk1C.x = 0.0f;
    arg0->unk28.z = 0.0f;
    arg0->unk28.y = 0.0f;
    arg0->unk28.x = 0.0f;
    kar_a2d_game_audio__near_80379398(arg0->audio1);
    kar_a2d_game_audio__near_80379398(arg0->audio2);
    kar_a2d_game_audio__near_80379398(arg0->audio3);
    __construct_array(arg0->refract0, kar_a2d_refract__near_803845f4, kar_a2d_refract__near_80384600, 4, 3);

    char * const g_bg = lbl_804E4F20;
    arg0->unk0 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0x9A0);
    if (arg0->unk0 == NULL) {
        __assert(g_bg + 0x8BC, 0x14A, lbl_805DAC44);
    }
    arg0->unk4 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0x9AC);
    if (arg0->unk4 == NULL) {
        __assert(g_bg + 0x8BC, 0x14E, g_bg + 0x9B8);
    }
    arg0->unk8 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0x9C4);
    if (arg0->unk8 == NULL) {
        __assert(g_bg + 0x8BC, 0x152, g_bg + 0x9D4);
    }
    arg0->unk10 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, lbl_805DAC4C);
    if (arg0->unk10 == NULL) {
        __assert(g_bg + 0x8BC, 0x156, g_bg + 0x9E0);
    }
    arg0->unk14 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0x9EC);
    arg0->unk18 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0x9F8);
    if (arg0->unk14 == NULL) {
        __assert(g_bg + 0x8BC, 0x15B, g_bg + 0xA04);
    }
    if (arg0->unk18 == NULL) {
        __assert(g_bg + 0x8BC, 0x15C, g_bg + 0xA10);
    }
    arg0->unk3E = arg1;
    arg0->unk34 = 0;
    arg0->unk3C = 0;
    arg0->unk3D = 1;
    arg0->unk110 = 0;
    arg0->unk114 = 0;
    arg0->unk118 = 0;
    arg0->unk11C = 0;

    if (arg0->unk0 == NULL) {
        __assert("jobj.h", 0x3C6, lbl_805DAC24);
    }
    arg0->unk0->translate.y = 0.0f;
    if (!(arg0->unk0->flags & MTX_INDEP_SRT)) {
        HSD_JObjSetMtxDirty(arg0->unk0);
    }
    if (arg0->unk4 == NULL) {
        __assert("jobj.h", 0x325, lbl_805DAC24);
    }
    arg0->unk4->scale.x = 1.0f;
    if (!(arg0->unk4->flags & MTX_INDEP_SRT)) {
        HSD_JObjSetMtxDirty(arg0->unk4);
    }

    kar_a2d_bg3000__near_80336d94(arg0);
    kar_a2d_game_lib__near_8028967c(arg0->unk8, 0xFFFF, 1.0f, 100.0f);
    kar_a2d_game_lib__near_80289590(arg0->unk8, 0xFFFF, 1.0f);
    kar_a2d_game_lib__near_80289768(arg0->unk8, 0xFFFF, 1.0f);
    kar_a2d_game_lib__near_80289730(arg0->unk14, 0xFFFF, 0.0f);
    kar_a2d_game_lib__near_80289730(arg0->unk18, 0xFFFF, 0.0f);
    kar_a2d_game_lib__near_80289768(arg0->unk14, 0xFFFF, 0.0f);
    kar_a2d_game_lib__near_80289768(arg0->unk18, 0xFFFF, 0.0f);

    if (arg0->unk3E == 0) {
        kar_a2d_game_lib__near_80289590(arg0->unk0, 0xFFFF, 0.0f);
        kar_a2d_game_lib__near_80289768(arg0->unk0, 0xFFFF, 0.0f);
        kar_a2d_game_lib__near_802895c8(arg0->unk10, 0xFFFF, 64.0f, 79.0f);
        kar_a2d_game_lib__near_80289590(arg0->unk10, 0xFFFF, 64.0f);
        kar_a2d_game_lib__near_80289768(arg0->unk10, 0xFFFF, 0.0f);
        kar_a2d_game_lib__near_80289730(arg0->unk8, 0xFFFF, 1.0f);
        kar_a2d_game_lib__near_80289768(arg0->unk8, 0xFFFF, 0.0f);
    } else {
        f32 v0[3] = { -16.8f, 1.5f, -2.4f };
        kar_a2d_refract__near_803848e0(arg0->refract0, 4, v0, 4.5f);
        f32 v1[3] = { -16.8f, -1.5f, -2.4f };
        kar_a2d_refract__near_803848e0(arg0->refract1, 4, v1, 4.5f);
        f32 v2[3] = { -16.8f, -4.5f, -2.4f };
        kar_a2d_refract__near_803848e0(arg0->refract2, 4, v2, 4.5f);
    }
    return arg0;
}

extern "C" void kar_a2d_bg3000__near_80336d94(Bg3000ArmA *arg0) {
    kar_a2d_game_lib__near_8028967c(arg0->unk10, 0xFFFF, 0.0f, 15.0f);
    kar_a2d_game_lib__near_80289590(arg0->unk10, 0xFFFF, 0.0f);
    arg0->unk34 = 0;
}

extern "C" void kar_a2d_bg3000__near_80336df0(Bg3000ArmA *arg0) {
    if (arg0->unk3E != 0) {
        f32 *var_r3 = &lbl_804E5614;
        if (((DiagResult *) kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DABF0, &lbl_805DABE8, 0))->unk14 == 1) {
            var_r3 = &lbl_804E55E0;
        }
        f32 temp_f30 = (f32) arg0->unk48 * (6.2831855f / *var_r3);
        u32 temp_r3 = arg0->unk44;
        f32 temp_f31 = kar_a2d_bg3000__near_803373ec(temp_f30) - 1.0f;
        if (temp_r3 != 0) {
            arg0->unk44 = temp_r3 - 1;
        }
        switch (arg0->unk34) {
        case 0:
            break;
        case 1:
            arg0->unk48 = arg0->unk48 + 1;
            if (temp_f30 > 6.2831855f) {
                arg0->unk48 = 0;
            }
            if (arg0->unk3C != 0) {
                arg0->unk34 = 3;
                arg0->unk44 = 0x12C;
                arg0->unk3C = 0;
            }
            {
                Bg3000ExtTable *ext = (Bg3000ExtTable *) (lbl_804E4F20 + 0x6F4);
                if (((DiagResult *) kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DABF0, &lbl_805DABE8, 0))->unk14 == 1) {
                    ext = (Bg3000ExtTable *) (lbl_804E4F20 + 0x6C0);
                }
                HSD_JObj *j0 = (HSD_JObj *) arg0->unk0;
                f32 v = temp_f31 * ext->unk4;
                if (j0 == NULL) {
                    __assert("jobj.h", 0x3C6, lbl_805DAC24);
                }
                j0->translate.y = v;
                if (!(j0->flags & MTX_INDEP_SRT)) {
                    HSD_JObjSetMtxDirty(j0);
                }
            }
            {
                HSD_JObj *j4 = arg0->unk4;
                if (j4 == NULL) {
                    __assert("jobj.h", 0x325, lbl_805DAC24);
                }
                j4->scale.x = 1.25f * -((0.5f * temp_f31) - 1.0f);
                if (!(j4->flags & MTX_INDEP_SRT)) {
                    HSD_JObjSetMtxDirty(j4);
                }
            }
            break;
        case 2:
            if (kar_a2d_game_lib__near_802897e0(arg0->unk10) != 0) {
                kar_a2d_game_lib__near_802895c8(arg0->unk10, 0xFFFF, 32.0f, 47.0f);
                kar_a2d_game_lib__near_80289590(arg0->unk10, 0xFFFF, 32.0f);
                arg0->unk34 = 1;
            }
            break;
        case 3:
            if (kar_a2d_game_lib__near_802897e0(arg0->unk10) != 0) {
                kar_a2d_game_lib__near_8028967c(arg0->unk10, 0xFFFF, 0.0f, 15.0f);
                kar_a2d_game_lib__near_80289590(arg0->unk10, 0xFFFF, 0.0f);
                arg0->unk34 = 0;
            }
            break;
        }
        f32 *var_r3_5 = &lbl_804E5614;
        if (((DiagResult *) kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DABF0, &lbl_805DABE8, 0))->unk14 == 1) {
            var_r3_5 = &lbl_804E55E0;
        }
        f32 temp_f29 = temp_f31 * (-10.0f * ((Bg3000DayTable *) var_r3_5)->unk10);
        kar_a2d_game_lib__near_80289768(arg0->unk14, 0xFFFF, temp_f29);
        kar_a2d_game_lib__near_80289768(arg0->unk18, 0xFFFF, temp_f29);
        f32 temp_f1 = kar_a2d_game_lib__near_802899d0(arg0->unk14);
        f32 var_f30 = temp_f1 - (f32) (((s32) temp_f1 / 100) * 0x64);
        if (var_f30 < 0.0f) {
            var_f30 = -var_f30;
        }
        if ((temp_f29 > 1.5f) && ((f32) arg0->unk88 > var_f30)) {
            s32 temp_r3_2 = kar_lbaudio_is_track_handle_playing(*(s32 *) (arg0->audio1 + 0x10));
            if (((u32) (-temp_r3_2 | temp_r3_2) >> 0x1F) == 0) {
                kar_a2d_game_audio__near_80379784(arg0->audio1, 0x8002A, &arg0->unk10->translate);
            }
        }
        arg0->unk88 = (u32) var_f30;
        {
            HSD_JObj *j = arg0->unk14;
            if (j != NULL) {
                if (j->flags & MTX_INDEP_SRT) {
                    HSD_JObjSetupMatrixSub(j);
                }
            }
        }
        {
            HSD_JObj *j = arg0->unk18;
            if (j != NULL) {
                if (j->flags & MTX_INDEP_SRT) {
                    HSD_JObjSetupMatrixSub(j);
                }
            }
        }
        arg0->unk1C.x = (f32) arg0->unk14->mtx[0][3];
        arg0->unk1C.y = (f32) arg0->unk14->mtx[1][3];
        arg0->unk1C.z = (f32) arg0->unk14->mtx[2][3];
        arg0->unk28.x = (f32) arg0->unk18->mtx[0][3];
        arg0->unk28.y = (f32) arg0->unk18->mtx[1][3];
        arg0->unk28.z = (f32) arg0->unk18->mtx[2][3];
        f32 *var_r3_8 = &lbl_804E5614;
        if (((DiagResult *) kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DABF0, &lbl_805DABE8, 0))->unk14 == 1) {
            var_r3_8 = &lbl_804E55E0;
        }
        f32 temp_f29_2 = temp_f31 * (-0.005f * ((Bg3000DayTable *) var_r3_8)->unk14);
        PSVECScale(&arg0->unk1C, &arg0->unk1C, temp_f29_2);
        PSVECScale(&arg0->unk28, &arg0->unk28, temp_f29_2);
        if (kar_a2d_game_lib__near_802899d0(arg0->unk8) == 117.0f) {
            kar_a2d_game_lib__near_8028967c(arg0->unk8, 0xFFFF, 1.0f, 100.0f);
            kar_a2d_game_lib__near_80289590(arg0->unk8, 0xFFFF, 1.0f);
            kar_a2d_game_lib__near_80289768(arg0->unk8, 0xFFFF, 1.0f);
        }
    }
}

extern "C" f32 kar_a2d_bg3000__near_803373ec(f32 farg0) {
    if (farg0 != lbl_805E4288) {
        f32 y = (f32) (farg0 + lbl_805E4310);
        if (y < lbl_805E4288) {
            return -kar_bg3000_reduce(-y);
        }
        return kar_bg3000_reduce(y);
    }
    return lbl_805E42A0;
}

extern "C" void kar_a2d_bg3000__near_80337848(Bg3000ArmA *arg0, void *arg1) {
    char * const g_bg = lbl_804E4F20;
    if (arg0->unk3E != 0) {
        KartIF **holder = (KartIF **) ((char *) arg1 + 0x2C);
        if (holder != NULL) {
            char *var_r4 = *(char **) (*(char **) (*(char **) (*(char **) ((char *) arg1 + 4) + 4) + 0xC) - 4);
            if (var_r4 == NULL) {
                var_r4 = (char *) &lbl_805DAC54;
            }
            if (strcmp(g_bg + 0xA1C, var_r4) == 0) {
                if ((*holder)->v94() < 1.2f) {
                    Vec3f *v = kar_a2d_bg3000__near_80337fa8(arg0, 2);
                    if (v != NULL && PSVECMag(&v->x, v->y, v->z) > 0.0f) {
                        (*holder)->vD4(*v);
                    }
                }
            } else {
                char *var_r4_2 = *(char **) (*(char **) (*(char **) (*(char **) ((char *) arg1 + 4) + 4) + 0xC) - 4);
                if (var_r4_2 == NULL) {
                    var_r4_2 = (char *) &lbl_805DAC54;
                }
                if (strcmp(g_bg + 0xA2C, var_r4_2) == 0) {
                    if ((*holder)->v94() < 1.2f) {
                        Vec3f *v = kar_a2d_bg3000__near_80337fa8(arg0, 3);
                        if (v != NULL && PSVECMag(&v->x, v->y, v->z) > 0.0f) {
                            (*holder)->vD4(*v);
                        }
                    }
                } else {
                    char *var_r4_3 = *(char **) (*(char **) (*(char **) (*(char **) ((char *) arg1 + 4) + 4) + 0xC) - 4);
                    if (var_r4_3 == NULL) {
                        var_r4_3 = (char *) &lbl_805DAC54;
                    }
                    if (strcmp(g_bg + 0xA3C, var_r4_3) == 0) {
                        if (arg0->unk3E != 0) {
                            Bg3000ExtTable *ext = (Bg3000ExtTable *) (g_bg + 0x6F4);
                            if (((DiagResult *) kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DABF0, &lbl_805DABE8, 0))->unk14 == 1) {
                                ext = (Bg3000ExtTable *) (g_bg + 0x6C0);
                            }
                            if ((*holder)->v94() < ext->unk8) {
                                u8 var_r0;
                                if (arg0->unk44 != 0) {
                                    var_r0 = 0;
                                } else {
                                    kar_a2d_game_audio__near_80379784(arg0->audio3, 0x80001, &arg0->unk10->translate);
                                    switch (arg0->unk34) {
                                    case 0:
                                        kar_a2d_game_lib__near_802895c8(arg0->unk10, 0xFFFF, 16.0f, 31.0f);
                                        kar_a2d_game_lib__near_80289590(arg0->unk10, 0xFFFF, 16.0f);
                                        arg0->unk34 = 2;
                                        arg0->unk44 = 0x12C;
                                        break;
                                    case 3:
                                        kar_a2d_game_lib__near_8028967c(arg0->unk10, 0xFFFF, 0.0f, 15.0f);
                                        kar_a2d_game_lib__near_80289590(arg0->unk10, 0xFFFF, 0.0f);
                                        arg0->unk34 = 0;
                                        arg0->unk44 = 0x12C;
                                        break;
                                    case 1:
                                        arg0->unk3C = 1;
                                        kar_a2d_game_lib__near_802895c8(arg0->unk10, 0xFFFF, 48.0f, 63.0f);
                                        kar_a2d_game_lib__near_80289590(arg0->unk10, 0xFFFF, 48.0f);
                                        break;
                                    case 2:
                                        kar_a2d_game_lib__near_802895c8(arg0->unk10, 0xFFFF, 32.0f, 47.0f);
                                        kar_a2d_game_lib__near_80289590(arg0->unk10, 0xFFFF, 32.0f);
                                        arg0->unk34 = 1;
                                        arg0->unk44 = 0x12C;
                                        break;
                                    }
                                    var_r0 = 1;
                                }
                                if ((var_r0 != 0) && ((*holder)->v28() != 0)) {
                                    s32 idx = (*holder)->v28();
                                    Bg3000Main *slot = (Bg3000Main *) ((char *) arg0 + idx * 4);
                                    (void) slot;
                                }
                            }
                        }
                    } else {
                        char *var_r4_4 = *(char **) (*(char **) (*(char **) (*(char **) ((char *) arg1 + 4) + 4) + 0xC) - 4);
                        if (var_r4_4 == NULL) {
                            var_r4_4 = (char *) &lbl_805DAC54;
                        }
                        if ((kar_fl_indirectload__80391f10(g_bg + 0xA4C, var_r4_4) != 0) && ((*holder)->v68() != 0) && ((*holder)->v94() < 1.2f)) {
                            s32 kind = (*holder)->v28();
                            u8 hit = (kind == 5) || (kind >= 2 && kind < 5) || (kind >= 0x10);
                            if (hit) {
                                Bg3000ExtTable *ext = (Bg3000ExtTable *) (g_bg + 0x6F4);
                                if (((DiagResult *) kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DABF0, &lbl_805DABE8, 0))->unk14 == 1) {
                                    ext = (Bg3000ExtTable *) (g_bg + 0x6C0);
                                }
                                f32 rate = ext->unkC;
                                f32 a = fn_80296264(1.0f);
                                f32 b = fn_8029626C(1000.0f) * a;
                                f32 c = fn_802D4C30(3600.0f) * b;
                                f32 v = rate * (1.0f * c);
                                f32 tmp = v;
                                (*holder)->vD8(&tmp);
                                kar_a2d_game_audio__near_80379784(arg0->audio2, 0x8002B, NULL);
                                kar_a2d_game_lib__near_802895c8(arg0->unk8, 0xFFFF, 101.0f, 117.0f);
                                kar_a2d_game_lib__near_80289590(arg0->unk8, 0xFFFF, 101.0f);
                                kar_a2d_game_lib__near_80289768(arg0->unk8, 0xFFFF, 1.0f);
                            }
                        }
                    }
                }
            }
        }
    }
}

extern "C" void kar_a2d_bg3000__near_80337e58(Bg3000ArmA *arg0, void *arg1) {
    char *var_r4 = *(char **) (*(char **) (*(char **) (*(char **) ((char *) arg1 + 4) + 4) + 0xC) - 4);
    if (var_r4 == NULL) {
        var_r4 = (char *) &lbl_805DAC54;
    }
    if (strcmp(lbl_804E593C, var_r4) == 0) {
        Vec3f *v = kar_a2d_bg3000__near_80337fa8(arg0, 2);
        if (v != NULL) {
            Vec3f tmp = *v;
            if (PSVECMag(&tmp.x, tmp.y, tmp.z) > 0.0f) {
                *(Vec3f *) ((char *) arg1 + 0x38) = tmp;
            }
        }
    } else {
        char *var_r4_2 = *(char **) (*(char **) (*(char **) (*(char **) ((char *) arg1 + 4) + 4) + 0xC) - 4);
        if (var_r4_2 == NULL) {
            var_r4_2 = (char *) &lbl_805DAC54;
        }
        if (strcmp(lbl_804E594C, var_r4_2) == 0) {
            Vec3f *v = kar_a2d_bg3000__near_80337fa8(arg0, 3);
            if (v != NULL) {
                Vec3f tmp = *v;
                if (PSVECMag(&tmp.x, tmp.y, tmp.z) > 0.0f) {
                    *(Vec3f *) ((char *) arg1 + 0x38) = tmp;
                }
            }
        }
    }
}

extern "C" Vec3f *kar_a2d_bg3000__near_80337fa8(Bg3000ArmA *arg0, s32 arg1) {
    if ((f32) arg0->unk48 != 0.0f) {
        if (arg1 == 2) {
            return &arg0->unk1C;
        }
        if (arg1 == 3) {
            return &arg0->unk28;
        }
    }
    return NULL;
}

extern "C" Bg3000ArmB *kar_a2d_bg3000__80338000(Bg3000ArmB *arg0, u8 arg1) {
    char * const g_bg = lbl_804E4F20;
    __construct_array((char *) arg0 + 0x40, (void *) &fn_802CD8DC, NULL, 0xC, 4);
    arg0->unk28 = 0.0f;
    arg0->unk24 = 0.0f;
    arg0->unk20 = 0.0f;
    kar_a2d_game_audio__near_80379398(arg0->audio1);
    kar_a2d_game_audio__near_80379398(arg0->audio2);
    __construct_array(arg0->refract0, kar_a2d_refract__near_803845f4, kar_a2d_refract__near_80384600, 4, 3);

    arg0->unk0 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0xA58);
    if (arg0->unk0 == NULL) {
        __assert(g_bg + 0x8BC, 0x29F, lbl_805DAC44);
    }
    arg0->unk4 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0xA64);
    if (arg0->unk4 == NULL) {
        __assert(g_bg + 0x8BC, 0x2A3, g_bg + 0x9B8);
    }
    arg0->unk8 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0xA70);
    if (arg0->unk8 == NULL) {
        __assert(g_bg + 0x8BC, 0x2A7, g_bg + 0xA84);
    }
    arg0->unk14 = kar_a2d_game_lib__near_8028a66c(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, arg0->unk8, g_bg + 0xA90);
    if (arg0->unk14 == 0) {
        __assert(g_bg + 0x8BC, 0x2A9, g_bg + 0xA9C);
    }
    arg0->unkC = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0xAA8);
    if (arg0->unkC == NULL) {
        __assert(g_bg + 0x8BC, 0x2AC, g_bg + 0xABC);
    }
    arg0->unk18 = kar_a2d_game_lib__near_8028a66c(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, arg0->unkC, g_bg + 0xA90);
    if (arg0->unk18 == 0) {
        __assert(g_bg + 0x8BC, 0x2AE, g_bg + 0xAC8);
    }
    arg0->unk10 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0xAD4);
    if (arg0->unk10 == NULL) {
        __assert(g_bg + 0x8BC, 0x2B1, g_bg + 0xAE8);
    }
    arg0->unk1C = kar_a2d_game_lib__near_8028a66c(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, arg0->unk10, g_bg + 0xA90);
    if (arg0->unk1C == 0) {
        __assert(g_bg + 0x8BC, 0x2B3, g_bg + 0xAF4);
    }

    if (arg0->unk0 == NULL) {
        __assert("jobj.h", 0x3E4, lbl_805DAC24);
    }
    if (arg0 == NULL) {
        __assert("jobj.h", 0x3E5, g_bg + 0x994);
    }
    arg0->unk20 = arg0->unk0->translate.x;
    arg0->unk24 = arg0->unk0->translate.y;
    f32 tz = arg0->unk0->translate.z;
    arg0->unk28 = tz;
    arg0->unkF5 = arg1;
    arg0->unk34 = 0;
    arg0->unk30 = 0;
    arg0->unk2C = 0;
    arg0->unkF4 = 0;
    arg0->unk39 = 0;
    arg0->unk3A = 0;
    arg0->unk3B = 0;
    arg0->unk3C = 0;

    (void) tz;
    kar_a2d_game_lib__near_8028967c(arg0->unk8, 0xFFFF, 1.0f, 100.0f);
    kar_a2d_game_lib__near_80289590(arg0->unk8, 0xFFFF, 1.0f);
    kar_a2d_game_lib__near_80289768(arg0->unk8, 0xFFFF, 1.0f);
    kar_a2d_game_lib__near_8028967c(arg0->unkC, 0xFFFF, 1.0f, 100.0f);
    kar_a2d_game_lib__near_80289590(arg0->unkC, 0xFFFF, 1.0f);
    kar_a2d_game_lib__near_80289768(arg0->unkC, 0xFFFF, 1.0f);
    kar_a2d_game_lib__near_8028967c(arg0->unk10, 0xFFFF, 1.0f, 100.0f);
    kar_a2d_game_lib__near_80289590(arg0->unk10, 0xFFFF, 1.0f);
    kar_a2d_game_lib__near_80289768(arg0->unk10, 0xFFFF, 1.0f);

    if (arg0->unkF5 == 0) {
        kar_a2d_game_lib__near_80289590(arg0->unk0, 0xFFFF, 0.0f);
        kar_a2d_game_lib__near_80289768(arg0->unk0, 0xFFFF, 0.0f);
        if (arg0->unk0 == NULL) {
            __assert("jobj.h", 0x2CC, lbl_805DAC24);
        }
        if (arg0->unk0->flags & USE_QUATERNION) {
            __assert("jobj.h", 0x2CD, g_bg + 0x96C);
        }
        arg0->unk0->rotate.x = -0.10471976f;
        if (!(arg0->unk0->flags & MTX_INDEP_SRT)) {
            HSD_JObjSetMtxDirty(arg0->unk0);
        }
        kar_a2d_game_lib__near_80289730(arg0->unk8, 0xFFFF, 1.0f);
        kar_a2d_game_lib__near_80289768(arg0->unk8, 0xFFFF, 0.0f);
        kar_a2d_game_lib__near_80289730(arg0->unkC, 0xFFFF, 1.0f);
        kar_a2d_game_lib__near_80289768(arg0->unkC, 0xFFFF, 0.0f);
        kar_a2d_game_lib__near_80289730(arg0->unk10, 0xFFFF, 1.0f);
        kar_a2d_game_lib__near_80289768(arg0->unk10, 0xFFFF, 0.0f);
    } else {
        f32 v0[3] = { -7.0f, 3.3f, -21.3f };
        kar_a2d_refract__near_803848e0(arg0->refract1, 6, v0, 2.0f);
        f32 v1[3] = { -6.0f, 3.3f, -19.3f };
        kar_a2d_refract__near_803848e0(arg0->refract0, 6, v1, 2.0f);
        f32 v2[3] = { -6.0f, 3.3f, -17.3f };
        kar_a2d_refract__near_803848e0(arg0->refract2, 6, v2, 2.0f);
    }
    return arg0;
}

extern "C" void kar_a2d_bg3000__near_8033873c(Bg3000ArmB *arg0) {
    char * const g_bg = lbl_804E4F20;
    if (arg0->unkF5 != 0) {
        f32 var_f31 = 0.0f;
        if (arg0->unk39 != 0) {
            var_f31 = 0.0f + 1.0f;
        }
        if (arg0->unk3A != 0) {
            var_f31 += 1.0f;
        }
        if (arg0->unk3B != 0) {
            var_f31 += 1.0f;
        }
        if (arg0->unk3C != 0) {
            var_f31 += 1.0f;
        }
        f32 temp_f1 = arg0->unk2C;
        u8 var_r29 = 0;
        if (temp_f1 < var_f31) {
            arg0->unk2C = var_f31;
        } else {
            var_r29 = temp_f1 > var_f31;
            if (temp_f1 > 1.0f) {
                arg0->unk2C = -((0.012f * ((f32) fn_803BCB64() - var_f31)) - arg0->unk2C);
            } else {
                arg0->unk2C = arg0->unk2C - 0.012f;
            }
            if (arg0->unk2C < 0.0f) {
                arg0->unk2C = 0.0f;
            }
            if ((var_r29 != 0) && (arg0->unk2C < var_f31)) {
                arg0->unk34 = 0x3C;
            }
        }
        if (arg0->unk34 != 0) {
            arg0->unk34 = arg0->unk34 - 1;
        }
        EXT_TABLE_SELECT(ext1);
        f32 temp_f29 = ext1->unk18;
        EXT_TABLE_SELECT(ext2);
        f32 temp_f30 = ext2->unk20;
        f32 var_f28 = 0.0f;
        f32 var_f29 = (arg0->unk20 / 0.20943952f) * temp_f29;
        f32 temp_f27 = 0.0f;
        (void) temp_f27;
        if (var_f31 > 0.0f) {
            EXT_TABLE_SELECT(ext3);
            arg0->unk30 = (u32) ext3->unk1C;
        }
        if (arg0->unkF4 != 0) {
            s32 t = kar_lbaudio_is_track_handle_playing(0);
            if (((u32) (-t | t) >> 0x1F) == 0) {
                arg0->unkF4 = 0;
            }
        }
        EXT_TABLE_SELECT(ext4);
        u8 *flags = &arg0->unk39;
        f32 *pos0 = &arg0->unk20;
        f32 temp_f27_2 = temp_f30 * ext4->unk24;
        for (s32 i = 0; i < 4; i++) {
            if (flags[i] != 0) {
                Vec3f sub;
                PSVECSubtract(pos0, (Vec3f *) ((char *) arg0 + 0x40 + i * 0xC), &sub);
                f32 v = PSVECMag(&sub.x, sub.y, sub.z) / 25.0f;
                if (v > 1.0f) {
                    v = 1.0f;
                }
                var_f28 += v * temp_f27_2;
            }
        }
        if (var_f29 < 0.0f) {
            var_f29 *= 0.8f;
            if (arg0->unkF4 == 0) {
                f32 v = arg0->unk24;
                if (v < 0.0f) {
                    v = -v;
                }
                if (v > 0.007f) {
                    kar_a2d_game_audio__near_80379784(arg0->audio2, 0x80029, &arg0->unk20);
                    arg0->unkF4 = 1;
                }
            }
        }
        f32 var_f3;
        if (arg0->unk30 != 0) {
            var_f3 = 0.98f;
            arg0->unk30 = arg0->unk30 - 1;
        } else {
            var_f3 = 0.84f;
        }
        arg0->unk28 = (var_f28 - var_f29) / temp_f30;
        f32 v1 = arg0->unk28;
        if (v1 < 0.0f) v1 = -v1;
        if (v1 < 0.001f) {
            arg0->unk28 = 0.0f;
        }
        arg0->unk24 = arg0->unk24 + arg0->unk28;
        arg0->unk24 = arg0->unk24 * var_f3;
        f32 v2 = arg0->unk24;
        if (v2 < 0.0f) v2 = -v2;
        if (v2 < 0.001f) {
            arg0->unk24 = 0.0f;
        }
        arg0->unk20 = arg0->unk20 + arg0->unk24;
        if (arg0->unk20 > 0.20943952f) {
            arg0->unk20 = 0.20943952f;
            arg0->unk24 = 0.0f;
            arg0->unk28 = 0.0f;
        }
        if (arg0->unk0 == NULL) {
            __assert("jobj.h", 0x2CC, lbl_805DAC24);
        }
        if (arg0->unk0->flags & USE_QUATERNION) {
            __assert("jobj.h", 0x2CD, g_bg + 0x96C);
        }
        arg0->unk0->rotate.x = -arg0->unk20;
        if (!(arg0->unk0->flags & MTX_INDEP_SRT)) {
            HSD_JObjSetMtxDirty(arg0->unk0);
        }
        if (arg0->unk4 == NULL) {
            __assert("jobj.h", 0x325, lbl_805DAC24);
        }
        arg0->unk4->scale.x = -((0.5f * (arg0->unk20 / 0.20943952f)) - 1.0f);
        if (!(arg0->unk4->flags & MTX_INDEP_SRT)) {
            HSD_JObjSetMtxDirty(arg0->unk4);
        }
        arg0->unk39 = 0;
        arg0->unk3A = 0;
        arg0->unk3B = 0;
        arg0->unk3C = 0;
        if (kar_a2d_game_lib__near_802899d0(arg0->unk8) == 117.0f) {
            kar_a2d_game_lib__near_8028967c(arg0->unk8, 0xFFFF, 1.0f, 100.0f);
            kar_a2d_game_lib__near_80289590(arg0->unk8, 0xFFFF, 1.0f);
            kar_a2d_game_lib__near_80289768(arg0->unk8, 0xFFFF, 1.0f);
        }
        if (kar_a2d_game_lib__near_802899d0(arg0->unkC) == 117.0f) {
            kar_a2d_game_lib__near_8028967c(arg0->unkC, 0xFFFF, 1.0f, 100.0f);
            kar_a2d_game_lib__near_80289590(arg0->unkC, 0xFFFF, 1.0f);
            kar_a2d_game_lib__near_80289768(arg0->unkC, 0xFFFF, 1.0f);
        }
        if (kar_a2d_game_lib__near_802899d0(arg0->unk10) == 117.0f) {
            kar_a2d_game_lib__near_8028967c(arg0->unk10, 0xFFFF, 1.0f, 100.0f);
            kar_a2d_game_lib__near_80289590(arg0->unk10, 0xFFFF, 1.0f);
            kar_a2d_game_lib__near_80289768(arg0->unk10, 0xFFFF, 1.0f);
        }
    }
}

extern "C" void kar_a2d_bg3000__near_80338dec(Bg3000ArmB *arg0, void *arg1) {
    char * const g_bg = lbl_804E4F20;
    if (arg0->unkF5 != 0) {
        KartIF **holder = (KartIF **) ((char *) arg1 + 0x2C);
        if (holder != NULL) {
            char *var_r4 = *(char **) (*(char **) (*(char **) (*(char **) ((char *) arg1 + 4) + 4) + 0xC) - 4);
            if (var_r4 == NULL) var_r4 = (char *) &lbl_805DAC54;
            if (kar_fl_indirectload__80391f10((void *) "hit3", var_r4) != 0) {
                f32 mag = (*holder)->v94();
                Vec3f *v = (*holder)->v74();
                s32 idx = (*holder)->v30();
                (void) idx;
                if (mag < 30.0f) {
                    arg0->unk39 = 1;
                    *(Vec3f *) ((char *) arg0 + 0x40) = *v;
                }
            }
            u8 var_r0_2 = 0;
            char *var_r4_2 = *(char **) (*(char **) (*(char **) (*(char **) ((char *) arg1 + 4) + 4) + 0xC) - 4);
            if (var_r4_2 == NULL) var_r4_2 = (char *) &lbl_805DAC54;
            if (strcmp((char *) (u32) arg0->unk14, var_r4_2) == 0) {
                char *var_r4_3 = *(char **) (*(char **) (*(char **) (*(char **) ((char *) arg1 + 4) + 4) + 0xC) - 4);
                if (var_r4_3 == NULL) var_r4_3 = (char *) &lbl_805DAC54;
                if (kar_fl_indirectload__80391f10(g_bg + 0xA90, var_r4_3) != 0) {
                    f32 mag = (*holder)->v94();
                    Vec3f *v = (*holder)->v74();
                    if (mag < 30.0f) {
                        arg0->unk39 = 1;
                        *(Vec3f *) ((char *) arg0 + 0x40) = *v;
                    }
                    arg0->unk38 = (*holder)->v94() <= 1.0f;
                    if (((*holder)->v68() != 0) && (arg0->unk38 != 0)) {
                        s32 kind = (*holder)->v28();
                        u8 hit = (kind == 5) || (kind >= 2 && kind < 5) || (kind >= 0x10);
                        if (hit) {
                            EXT_TABLE_SELECT(ext);
                            f32 rate = ext->unk28;
                            f32 a = fn_80296264(1.0f);
                            f32 b = fn_8029626C(1000.0f) * a;
                            f32 c = fn_802D4C30(3600.0f) * b;
                            f32 v2 = rate * (1.0f * c);
                            f32 tmp = v2;
                            (*holder)->vD8(&tmp);
                            kar_a2d_game_audio__near_80379784(arg0->audio1, 0x8002B, NULL);
                            var_r0_2 = 1;
                        }
                    }
                }
            }
            if (var_r0_2 != 0) {
                kar_a2d_game_lib__near_802895c8(arg0->unk8, 0xFFFF, 101.0f, 117.0f);
                kar_a2d_game_lib__near_80289590(arg0->unk8, 0xFFFF, 101.0f);
                kar_a2d_game_lib__near_80289768(arg0->unk8, 0xFFFF, 1.0f);
            }
        }
    }
}

extern "C" Bg3000ArmC *kar_a2d_bg3000__80339754(Bg3000ArmC *arg0, u8 arg1) {
    char * const g_bg = lbl_804E4F20;
    kar_a2d_refract__near_803845f4(arg0->refract0);
    kar_a2d_refract__near_803845f4(arg0->refract1);
    kar_a2d_refract__near_803845f4(arg0->refract2);
    arg0->unk0 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0xB00);
    arg0->unk4 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0xB10);
    arg0->unk8 = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0xB20);
    arg0->unkC = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0xB30);
    if (arg0->unk0 == NULL) {
        __assert(g_bg + 0x8BC, 0x3B0, lbl_805DAC44);
    }
    if (arg0->unk4 == NULL) {
        __assert(g_bg + 0x8BC, 0x3B1, g_bg + 0xB40);
    }
    if (arg0->unk8 == NULL) {
        __assert(g_bg + 0x8BC, 0x3B2, g_bg + 0xB50);
    }
    if (arg0->unkC == NULL) {
        __assert(g_bg + 0x8BC, 0x3B3, g_bg + 0xB60);
    }
    HSD_JObj *ja = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0xB70);
    HSD_JObj *jb = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0xB80);
    HSD_JObj *jc = (HSD_JObj *) fn_8038D0A8(((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DAAD8, &lbl_805DAAD0, 0))->unk18, g_bg + 0xB90);
    if (ja == NULL) {
        __assert(g_bg + 0x8BC, 0x3B8, lbl_805DAC60);
    }
    if (jb == NULL) {
        __assert(g_bg + 0x8BC, 0x3B9, lbl_805DAC64);
    }
    if (jc == NULL) {
        __assert(g_bg + 0x8BC, 0x3BA, lbl_805DAC68);
    }
    kar_a2d_refract__near_80384670(arg0->refract0, 4, ja, 9.0f);
    kar_a2d_refract__near_80384670(arg0->refract1, 4, jb, 3.5f);
    kar_a2d_refract__near_80384670(arg0->refract2, 4, jc, 5.0f);
    arg0->unk19 = arg1;
    if (arg0->unk0 == NULL) {
        __assert("jobj.h", 0x2B8, lbl_805DAC24);
    }
    if (arg0->unk0->flags & USE_QUATERNION) {
        __assert("jobj.h", 0x2B9, g_bg + 0x96C);
    }
    arg0->unk0->rotate.y = 0.0f;
    if (!(arg0->unk0->flags & MTX_INDEP_SRT)) {
        HSD_JObjSetMtxDirty(arg0->unk0);
    }
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    arg0->unk18 = 0;
    arg0->unk1C = 0;
    arg0->unk20 = 0.0f;
    return arg0;
}

extern "C" void kar_a2d_bg3000__near_80339a74(Bg3000ArmC *arg0) {
    if (arg0->unk19 != 0) {
        if (arg0->unk10 < 0xF0) {
            arg0->unk10 = arg0->unk10 + 1;
            return;
        }
        f32 var_f30 = 1.0f;
        EXT_TABLE_SELECT(ext0);
        f32 temp_f31 = 0.017453292f * ext0->unk2C;
        switch (arg0->unk1C) {
        case 0: {
            EXT_TABLE_SELECT(ext1);
            if (ext1->unk30 > 0.0f) {
                arg0->unk14 = arg0->unk14 + 1;
                if (arg0->unk14 >= 0x190) {
                    arg0->unk1C = 1;
                    arg0->unk14 = 0;
                }
            }
            break;
        }
        case 1:
            var_f30 = 1.0f * kar_a2d_bg3000__near_803373ec(1.5707964f * ((f32) arg0->unk14 / 300.0f));
            arg0->unk14 = arg0->unk14 + 1;
            if (arg0->unk14 >= 0x12C) {
                arg0->unk1C = 2;
                arg0->unk14 = 0;
            }
            break;
        case 2:
            arg0->unk14 = arg0->unk14 + 1;
            if (arg0->unk14 >= 0x3C) {
                arg0->unk1C = 3;
                arg0->unk14 = 0;
                arg0->unk18 = (arg0->unk18 == 0);
            }
            var_f30 = 0.0f;
            break;
        case 3:
            var_f30 = 1.0f * kar_a2d_bg3000__near_80339fc0(1.5707964f * ((f32) arg0->unk14 / 300.0f));
            arg0->unk14 = arg0->unk14 + 1;
            if (arg0->unk14 >= 0x12C) {
                arg0->unk1C = 0;
                arg0->unk14 = 0;
            }
            break;
        }
        f32 var_f31;
        if (arg0->unk18 != 0) {
            var_f31 = temp_f31 * var_f30;
        } else {
            var_f31 = temp_f31 * -var_f30;
        }
        if (arg0->unk0 == NULL) {
            __assert("jobj.h", 0x2FA, lbl_805DAC24);
        }
        if (arg0->unk0->flags & USE_QUATERNION) {
            __assert("jobj.h", 0x2B9, lbl_804E4F20 + 0x96C);
        }
        arg0->unk0->rotate.y = var_f31 + arg0->unk0->rotate.y;
        if (!(arg0->unk0->flags & MTX_INDEP_SRT)) {
            HSD_JObjSetMtxDirty(arg0->unk0);
        }
        if (arg0->unk4 == NULL) {
            __assert("jobj.h", 0x2FA, lbl_805DAC24);
        }
        arg0->unk4->rotate.y = arg0->unk4->rotate.y - var_f31;
        if (!(arg0->unk4->flags & MTX_INDEP_SRT)) {
            HSD_JObjSetMtxDirty(arg0->unk4);
        }
        if (arg0->unk8 == NULL) {
            __assert("jobj.h", 0x2FA, lbl_805DAC24);
        }
        arg0->unk8->rotate.y = arg0->unk8->rotate.y - var_f31;
        if (!(arg0->unk8->flags & MTX_INDEP_SRT)) {
            HSD_JObjSetMtxDirty(arg0->unk8);
        }
        if (arg0->unkC == NULL) {
            __assert("jobj.h", 0x2FA, lbl_805DAC24);
        }
        arg0->unkC->rotate.y = arg0->unkC->rotate.y - var_f31;
        if (!(arg0->unkC->flags & MTX_INDEP_SRT)) {
            HSD_JObjSetMtxDirty(arg0->unkC);
        }
    }
}

extern "C" f32 kar_a2d_bg3000__near_80339fc0(f32 farg0) {
    if (farg0 != lbl_805E4288) {
        if (farg0 < lbl_805E4288) {
            return -kar_bg3000_reduce(-farg0);
        }
        return kar_bg3000_reduce(farg0);
    }
    return lbl_805E4288;
}

extern "C" void kar_a2d_bg3000__near_8033a40c(Bg3000ArmC *arg0, void *arg1) {
    KartIF **holder = (KartIF **) ((char *) arg1 + 0x2C);
    if (holder != NULL) {
        char *var_r4 = *(char **) (*(char **) (*(char **) (*(char **) ((char *) arg1 + 4) + 4) + 0xC) - 4);
        if (var_r4 == NULL) var_r4 = (char *) &lbl_805DAC54;
        if ((kar_fl_indirectload__80391f10((void *) lbl_804E5AC0, var_r4) != 0) && ((*holder)->v64() != 0) && ((*holder)->v94() < 1.2f)) {
            Vec3f *src = (*holder)->v74();
            Vec3f sum1, cross, result;
            HSD_JObj *j0 = (HSD_JObj *) arg0->unk0;
            if (!(j0->flags & MTX_INDEP_SRT)) {
                HSD_JObjSetupMatrixSub(j0);
            }
            Vec3f world;
            world.x = j0->mtx[0][3];
            world.y = j0->mtx[1][3];
            world.z = j0->mtx[2][3];
            PSVECSubtract(src, &world, &sum1);
            PSVECCrossProduct(&sum1, (Vec3f *) &lbl_8048A3C0, &cross, sum1.y, sum1.x);
            PSVECNormalize(&cross, &result);
            f32 mag = arg0->unk20 * -PSVECMag(&sum1.x, sum1.y, sum1.z);
            PSVECScale(&result, &result, mag);
            (*holder)->vD4(result);
        }
    }
}

extern "C" void kar_a2d_bg3000__near_8033a61c(Bg3000ArmC *arg0, void *arg1) {
    char *var_r4 = *(char **) (*(char **) (*(char **) (*(char **) ((char *) arg1 + 4) + 4) + 0xC) - 4);
    if (var_r4 == NULL) var_r4 = (char *) &lbl_805DAC54;
    if (kar_fl_indirectload__80391f10((void *) lbl_804E5AC0, var_r4) != 0) {
        Vec3f src = *(Vec3f *) ((char *) arg1 + 0x10);
        Vec3f sum1, cross, result;
        HSD_JObj *j0 = (HSD_JObj *) arg0->unk0;
        if (!(j0->flags & MTX_INDEP_SRT)) {
            HSD_JObjSetupMatrixSub(j0);
        }
        Vec3f world;
        world.x = j0->mtx[0][3];
        world.y = j0->mtx[1][3];
        world.z = j0->mtx[2][3];
        PSVECSubtract(&src, &world, &sum1);
        PSVECCrossProduct(&sum1, (Vec3f *) &lbl_8048A3C0, &cross, sum1.y, sum1.x);
        PSVECNormalize(&cross, &result);
        f32 mag = arg0->unk20 * -PSVECMag(&sum1.x, sum1.y, sum1.z);
        PSVECScale(&result, &result, mag);
        *(Vec3f *) ((char *) arg1 + 0x38) = result;
    }
}

extern "C" Bg3000Main *kar_a2d_bg3000__near_8033a7d4(Bg3000Main *arg0, s16 arg1) {
    if (arg0 != NULL) {
        arg0->unk0 = &lbl_804E5AF8;
        lbl_805DDC40 = NULL;
        *(void **) &arg0->unk9C = lbl_804BDF70;
        kar_a2d_effecthandle__near_8037b33c(&arg0->unk9C, 0);
        *(void **) &arg0->unk9C = lbl_804BDF2C;
        arg0->unk9C.v1c();
        Bg3000ArmC *c = arg0->unk84;
        if (c != NULL) {
            kar_a2d_refract__near_80384600(c->refract2, -1);
            kar_a2d_refract__near_80384600(c->refract1, -1);
            kar_a2d_refract__near_80384600(c->refract0, -1);
            fn_8038CB78(c);
        }
        Bg3000ArmB *b = arg0->unk80;
        if (b != NULL) {
            __destroy_arr(b->refract2, kar_a2d_refract__near_80384600, 4, 3);
            fn_8038CB78(b);
        }
        Bg3000ArmA *a = arg0->unk7C;
        if (a != NULL) {
            __destroy_arr(a->refract0, kar_a2d_refract__near_80384600, 4, 3);
            fn_8038CB78(a);
        }
        arg0->unk0 = &lbl_804BCE14;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" Bg3000RegionTable *kar_a2d_bg3000__near_8033ab00(void) {
    Bg3000RegionTable *r;
    if (((DiagResult *) kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DADE8, &lbl_805DADE0, 0))->unk14 == 1) {
        r = (Bg3000RegionTable *) lbl_804E6320;
    } else {
        r = (Bg3000RegionTable *) lbl_804E63A4;
    }
    return r;
}

extern "C" Bg3000RegionTable *kar_a2d_bg3000__near_8033ab50(u32 arg0) {
    if (arg0 == 0) {
        return (Bg3000RegionTable *) lbl_804E6320;
    }
    return (Bg3000RegionTable *) lbl_804E63A4;
}











































extern "C" void kar_a2d_bg3000__near_8033ab6c(f32 *arg0) {
    char * const base = lbl_804E5C60;
    OSReport(base + 0x800, base);
    OSReport(base + 0x810);
    f32 v0 = *(f32 *) ((char *) arg0 + 0x0);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0x834);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v0);
    f32 v1 = *(f32 *) ((char *) arg0 + 0x4);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0x850);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v1);
    f32 v2 = *(f32 *) ((char *) arg0 + 0x8);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0x868);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v2);
    f32 v3 = *(f32 *) ((char *) arg0 + 0xc);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0x884);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v3);
    f32 v4 = *(f32 *) ((char *) arg0 + 0x10);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0x8a0);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v4);
    f32 v5 = *(f32 *) ((char *) arg0 + 0x14);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0x8b8);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v5);
    f32 v6 = *(f32 *) ((char *) arg0 + 0x18);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0x8cc);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v6);
    f32 v7 = *(f32 *) ((char *) arg0 + 0x1c);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0x8ec);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v7);
    f32 v8 = *(f32 *) ((char *) arg0 + 0x20);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0x90c);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v8);
    f32 v9 = *(f32 *) ((char *) arg0 + 0x24);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0x930);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v9);
    f32 v10 = *(f32 *) ((char *) arg0 + 0x28);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0x954);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v10);
    f32 v11 = *(f32 *) ((char *) arg0 + 0x2c);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0x978);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v11);
    f32 v12 = *(f32 *) ((char *) arg0 + 0x30);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0x99c);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v12);
    f32 v13 = *(f32 *) ((char *) arg0 + 0x34);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0x9b8);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v13);
    f32 v14 = *(f32 *) ((char *) arg0 + 0x38);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0x9d8);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v14);
    f32 v15 = *(f32 *) ((char *) arg0 + 0x3c);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0x9f0);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v15);
    f32 v16 = *(f32 *) ((char *) arg0 + 0x40);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0xa08);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v16);
    f32 v17 = *(f32 *) ((char *) arg0 + 0x44);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0xa1c);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v17);
    f32 v18 = *(f32 *) ((char *) arg0 + 0x48);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0xa30);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v18);
    f32 v19 = *(f32 *) ((char *) arg0 + 0x4c);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0xa44);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v19);
    f32 v20 = *(f32 *) ((char *) arg0 + 0x50);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0xa60);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v20);
    f32 v21 = *(f32 *) ((char *) arg0 + 0x54);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0xa7c);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v21);
    f32 v22 = *(f32 *) ((char *) arg0 + 0x58);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0xa94);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v22);
    f32 v23 = *(f32 *) ((char *) arg0 + 0x5c);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0xaa8);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v23);
    f32 v24 = *(f32 *) ((char *) arg0 + 0x60);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0xabc);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v24);
    f32 v25 = *(f32 *) ((char *) arg0 + 0x64);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0xacc);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v25);
    f32 v26 = *(f32 *) ((char *) arg0 + 0x68);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0xae4);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v26);
    f32 v27 = *(f32 *) ((char *) arg0 + 0x6c);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0xafc);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v27);
    f32 v28 = *(f32 *) ((char *) arg0 + 0x70);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0xb1c);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v28);
    f32 v29 = *(f32 *) ((char *) arg0 + 0x74);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0xb38);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v29);
    f32 v30 = *(f32 *) ((char *) arg0 + 0x78);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0xb54);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v30);
    f32 v31 = *(f32 *) ((char *) arg0 + 0x7c);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0xb70);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v31);
    f32 v32 = *(f32 *) ((char *) arg0 + 0x80);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DADF8, base + 0xb8c);
    OSReport(lbl_805DADF0);
    OSReport(lbl_805DAE00, v32);
    OSReport(lbl_805DAE08);
}
