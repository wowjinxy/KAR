#include <dolphin/types.h>

extern "C" {
#include <global.h>
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
    virtual void vD4(f32, f32, f32);
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

struct JobjXform {
    char pad0[0x50];
    f32 posX;
    char pad54[0xC];
    f32 posY;
    char pad64[0xC];
    f32 posZ;
};

struct JobjFlags {
    char pad0[0x14];
    u32 flags;
};

struct BgObj {
    void *unk0;
    void *unk4;
    void *unk8;
    void *unkC;
    u8 unk10;
    char pad11[3];
    DiagObj unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    GeneratorIface *unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    f32 unk64;
    f32 unk68;
    f32 unk6C;
    f32 unk70;
    u16 unk74;
    u16 unk76;
    u16 unk78;
    char pad7A[2];
    GameEffectItem unk7C;
    s32 unkC8;
    GameEffectItem unkCC;
    s32 unk118;
    char unk11C[4];
};

struct BgManager {
    void *unk0;
    BgObj *unk4;
    BgObj *unk8;
    RefObj **unkC;
    RefObj **unk10;
};

struct BgState {
    void *unk0;
    u32 unk4;
    u32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    s32 unk18;
    u32 unk1C;
    f32 unk20;
    u8 unk24;
};

struct BgColorTable {
    char pad0[4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    char pad24[4];
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
};

typedef BgColorTable BgTimeTable;

extern "C" {

void *kar_diag__803ad760(s32, s32, void *, void *, s32);
void HSD_JObjSetupMatrixSub(void *);
f32 HSD_Randf(void);
s32 HSD_Randi(s32);
void PSVECAdd(void *, void *, void *, void *, f32, f32, f32, f32);
void PSVECScale(void *, void *, f32, f32, f32);

void *kar_a2d_effecthandle__8037b028(GameEffectItem *, s32, s32, void *, Vec3f *, Vec4f *, f32);
void kar_a2d_effecthandle__near_8037b33c(GameEffectItem *, u8);

void kar_a2d_game_effect__near_8037afd0(GameEffectItem *, u8);

void kar_a2d_game_lib__near_8028967c(void *, u16, f32, f32);
void kar_a2d_game_lib__near_80289730(void *, u16, f32);
void kar_a2d_game_lib__near_80289768(void *, u16, f32);
f32 kar_a2d_game_lib__near_802899d0(void *);
u16 kar_a2d_game_lib__near_8028ac98(u16, u16, u16);

void kar_a2d_refract__near_803845f4(void *);
void kar_a2d_refract__near_80384600(void *, s32);
void kar_a2d_refract__near_803848e0(void *, s32, f32 *, f32);

void *fn_8038CB78(void *);

u8 kar_fl_indirectload__80391f10(void *, void *);

f32 fn_80296264(f32);
f32 fn_8029626C(f32);
f32 fn_802D4C30(f32);

void OSReport(const char *, ...);

extern s32 lbl_805DDBC0;
extern s32 lbl_805DDC50;

extern void *lbl_804BF4DC;
extern void *lbl_804D7300;
extern void *lbl_804D7700;
extern void *lbl_804BDF2C;
extern void *lbl_804BDF70;
extern void *lbl_804F5208;
extern void *lbl_804BF3C0;
extern void *lbl_804E0EB8;
extern void *lbl_804E7ADC;
extern void *lbl_804E7B10;
extern void *lbl_804BCE14;

extern char lbl_804E7518[];
extern char lbl_804E83B0[];
extern char lbl_804E8474[];
extern char lbl_804E79F8[];
extern char lbl_804E7614[];
extern char lbl_804E7660[];

extern f32 lbl_805E4480; /* 0.0F */
extern f32 lbl_805E4484; /* 1023.0F */
extern f32 lbl_805E4488; /* 1.0F */

extern void *lbl_805DAEF8;
extern void *lbl_805DAEF0;
extern void *lbl_805DB0C8;
extern void *lbl_805DB0D0;

extern char lbl_805DB0D8[5];
extern char lbl_805DB0E0[8];
extern char lbl_805DB0E8[6];
extern char lbl_805DB0F0[4];

}

static char lbl_805DAF1C[6] = "jobj_";
static char kar_srcfile_jobj_h_805daf24[7] = "jobj.h";
static char lbl_805DAF2C[5] = "jobj";
static char lbl_805DAF34[] = "0";
static s32 lbl_805DAF38 = 0;

#define ASSERT2(line, cond, file, str) \
    ((cond) ? ((void) 0) : __assert(file, line, str))

#define BG_SELECT_TABLE(t) \
    BgColorTable *t; \
    if ((u32) ((DiagResult *) kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DAEF8, &lbl_805DAEF0, 0))->unk14 == 1) { \
        t = (BgColorTable *) lbl_804E7614; \
    } else { \
        t = (BgColorTable *) lbl_804E7660; \
    }

extern "C" void kar_a2d_bg5000__8034061c(BgState *arg0);
extern "C" f32 kar_a2d_bg5000__near_8034093c(f32 farg0);
extern "C" void kar_a2d_bg5000__near_80340498(BgState *arg0);
extern "C" void kar_a2d_bg5000__near_80341860(f32 *arg0, void *arg2, s32 kind, u8 arg3);
static const f32 lbl_805E448C = 3.0f;
static const f32 lbl_805E4490 = 6.0f;
static const f32 lbl_805E4494 = 255.0f;
static const f32 lbl_805E4498 = 256.0f;
static const f32 lbl_805E449C = 511.0f;
static const f32 lbl_805E44A0 = 512.0f;
static const f32 lbl_805E44A4 = 767.0f;
static const f32 lbl_805E44A8 = 768.0f;
static const f32 lbl_805E44AC = 3.1415927f;
static const f32 lbl_805E44B0 = 0.5f;
static const f64 lbl_805E44B8 = 6.283185307179586;
static const f64 lbl_805E44C0 = 3.141592653589793;
static const f64 lbl_805E44C8 = 1.5707963267948966;
static const f32 lbl_805E44D0 = 0.16666669f;
static const f32 lbl_805E44D4 = 0.008332824f;
static const f32 lbl_805E44D8 = 0.00019587841f;
static const f32 lbl_805E44DC = 0.9999998f;
static const f32 lbl_805E44E0 = 0.49999395f;
static const f32 lbl_805E44E4 = 0.04163633f;
static const f32 lbl_805E44E8 = 0.0013400711f;
static const f64 lbl_805E44F0 = 0.7853981633974483;
static const f32 lbl_805E44F8 = 3600.0f;
static const f32 lbl_805E44FC = 1000.0f;
static const f32 lbl_805E4500 = 0.016666668f;
static const f32 lbl_805E4504 = 0.05f;


struct DiagResult {
    char pad0[0x14];
    s32 unk14;
};

static inline BgColorTable *BgGetColorTable(char *base) {
    BgColorTable *tbl = (BgColorTable *) (base + 0x148);
    if ((u32) ((DiagResult *) kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DAEF8, &lbl_805DAEF0, 0))->unk14 == 1) {
        tbl = (BgColorTable *) (base + 0xFC);
    }
    return tbl;
}

extern "C" void *kar_a2d_bg5000__8033fc54(BgObj *arg0, u8 arg1, void *arg2, void *arg3, u32 arg4, s32 arg5, u32 arg6, s32 arg7) {
    Vec3f v;
    f32 f28;
    char * const g_bg = lbl_804E7518;

    arg0->unk0 = arg2;
    arg0->unk4 = arg3;
    arg0->unk8 = (void *) arg4;
    arg0->unkC = (void *) arg6;

    *(void **) &arg0->unk14 = lbl_804BF4DC;
    arg0->unk18 = 0;
    arg0->unk1C = 0;
    arg0->unk14.Init();
    *(void **) &arg0->unk14 = lbl_804D7700;
    arg0->unk20 = 0;
    arg0->unk24 = 0;
    arg0->unk28 = 0;
    arg0->unk2C = 0;
    arg0->unk30 = 0;
    arg0->unk34 = 0;
    arg0->unk38 = (GeneratorIface *) lbl_804F5208;
    arg0->unk38 = (GeneratorIface *) lbl_804BF3C0;
    arg0->unk3C = lbl_805E4480;
    arg0->unk40 = lbl_805E4480;
    arg0->unk44 = lbl_805E4480;
    arg0->unk48 = lbl_805E4488;
    arg0->unk4C = lbl_805E4480;
    arg0->unk50 = lbl_805E4480;
    arg0->unk54 = lbl_805E4488;
    arg0->unk58 = lbl_805E4488;
    *(void **) &arg0->unk14 = lbl_804D7300;
    arg0->unk38 = (GeneratorIface *) ((char *) lbl_804D7300 + 0x38);
    arg0->unk64 = lbl_805E4480;
    arg0->unk60 = lbl_805E4480;
    arg0->unk5C = lbl_805E4480;
    arg0->unk70 = lbl_805E4480;
    arg0->unk6C = lbl_805E4480;
    arg0->unk68 = lbl_805E4480;
    arg0->unk78 = 0;

    *(void **) &arg0->unk7C = lbl_804BDF2C;
    arg0->unk7C.unk4 = 0;
    arg0->unk7C.unk8 = 0;
    arg0->unk7C.Init();
    *(void **) &arg0->unk7C = lbl_804BDF70;
    kar_a2d_effecthandle__8037b028(&arg0->unk7C, -1, 0, 0, NULL, 0, 0);

    *(void **) &arg0->unkCC = lbl_804BDF2C;
    arg0->unkCC.unk4 = 0;
    arg0->unkCC.unk8 = 0;
    arg0->unkCC.Init();
    *(void **) &arg0->unkCC = lbl_804BDF70;
    kar_a2d_effecthandle__8037b028(&arg0->unkCC, -1, 0, 0, NULL, 0, 0);

    kar_a2d_refract__near_803845f4(arg0->unk11C);

    f28 = BgGetColorTable(g_bg)->unk40;

    if (arg0->unk0 == NULL) {
        __assert(lbl_804E7518 + 0x4A0, 0xEF, lbl_805DAF1C);
    }
    if (arg0->unk4 == NULL) {
        __assert(lbl_804E7518 + 0x4A0, 0xF0, lbl_804E7518 + 0x4B0);
    }
    if (arg0->unk8 == NULL) {
        __assert(lbl_804E7518 + 0x4A0, 0xF1, lbl_804E7518 + 0x4BC);
    }
    if (arg0->unkC == NULL) {
        __assert(lbl_804E7518 + 0x4A0, 0xF2, lbl_804E7518 + 0x4C8);
    }

    arg0->unk10 = arg1;
    arg0->unkC8 = arg5;
    arg0->unk118 = arg7;

    if (arg0->unk10 != 0) {
        JobjFlags *j2 = (JobjFlags *) arg2;
        if (j2 != NULL) {
            ASSERT2(0x25D, j2 != NULL, kar_srcfile_jobj_h_805daf24, lbl_805DAF2C);
            if (!(j2->flags & 0x800000) && (j2->flags & 0x40)) {
                HSD_JObjSetupMatrixSub(j2);
            }
        }
        JobjFlags *j3 = (JobjFlags *) arg3;
        if (j3 != NULL) {
            ASSERT2(0x25D, j3 != NULL, kar_srcfile_jobj_h_805daf24, lbl_805DAF2C);
            if (!(j3->flags & 0x800000) && (j3->flags & 0x40)) {
                HSD_JObjSetupMatrixSub(j3);
            }
        }
        JobjXform *jx = (JobjXform *) arg2;
        JobjXform *jx2 = (JobjXform *) arg3;
        v.x = jx->posX;
        v.y = jx->posY;
        v.z = jx->posZ;

        arg0->unk20 = 1;
        Vec3f sum;
        PSVECAdd(&sum, &v, &v, jx2, jx->posY, v.x, lbl_805E448C, lbl_805E4480);
        arg0->unk5C = sum.x;
        arg0->unk60 = v.y;
        arg0->unk64 = v.z;
        arg0->unk68 = jx2->posZ;
        arg0->unk6C = jx2->posY;
        arg0->unk70 = jx2->posX;
        arg0->unk38->SetTarget(&sum, &sum.y);
        arg0->unk38->Commit();

        f32 f1_2 = BgGetColorTable(g_bg)->unk44;
        arg0->unk74 = (u16) f1_2;
        arg0->unk76 = (u16) BgGetColorTable(g_bg)->unk48;
        kar_a2d_refract__near_803848e0(arg0->unk11C, 1, &sum.x, lbl_805E4490);
    }
    return arg0;
}

extern "C" void kar_a2d_bg5000__near_8034011c(BgObj *arg0) {
    if (arg0->unk7C.unkC != 0x7531) {
        JobjFlags *jf = (JobjFlags *) arg0->unk8;
        if (jf != NULL) {
            ASSERT2(0x25D, jf != NULL, kar_srcfile_jobj_h_805daf24, lbl_805DAF2C);
            if (!(jf->flags & 0x800000) && (jf->flags & 0x40)) {
                HSD_JObjSetupMatrixSub(jf);
            }
        }
        JobjXform *jx = (JobjXform *) arg0->unk8;
        Vec3f pos;
        pos.x = jx->posX;
        pos.y = jx->posY;
        pos.z = jx->posZ;
        kar_a2d_game_effect__near_8037afd0(&arg0->unk7C, 0);
        kar_a2d_effecthandle__8037b028(&arg0->unk7C, arg0->unkC8, 3, 0, &pos, 0, pos.y);
    }
    if (arg0->unkCC.unkC != 0x7531) {
        JobjFlags *jf = (JobjFlags *) arg0->unkC;
        if (jf != NULL) {
            ASSERT2(0x25D, jf != NULL, kar_srcfile_jobj_h_805daf24, lbl_805DAF2C);
            if (!(jf->flags & 0x800000) && (jf->flags & 0x40)) {
                HSD_JObjSetupMatrixSub(jf);
            }
        }
        JobjXform *jx = (JobjXform *) arg0->unkC;
        Vec3f pos;
        pos.x = jx->posX;
        pos.y = jx->posY;
        pos.z = jx->posZ;
        kar_a2d_game_effect__near_8037afd0(&arg0->unkCC, 0);
        kar_a2d_effecthandle__8037b028(&arg0->unkCC, arg0->unk118, 3, 0, &pos, 0, pos.y);
    }
    if (arg0->unk10 != 0) {
        BG_SELECT_TABLE(var_r3)
        f32 f1_3 = var_r3->unk44;
        arg0->unk74 = (u16) f1_3;
        BG_SELECT_TABLE(var_r3_4)
        arg0->unk76 = (u16) var_r3_4->unk48;
    }
}

extern "C" void *kar_a2d_bg5000__80340348(BgState *arg0, s8 arg1, u32 arg2, u32 arg3) {
    char * const g_bg = lbl_804E7518;
    arg0->unk0 = lbl_804E0EB8;
    arg0->unk0 = lbl_804E7ADC;
    arg0->unk4 = arg2;
    arg0->unk8 = arg3;
    if (arg0->unk4 == 0U) {
        __assert(lbl_804E7518 + 0x4A0, 0x15D, lbl_805DAF1C);
    }
    if (arg0->unk8 == 0U) {
        __assert(lbl_804E7518 + 0x4A0, 0x15E, lbl_804E7518 + 0x4D4);
    }
    arg0->unk24 = arg1;
    arg0->unk18 = 0;
    arg0->unk1C = 0;
    arg0->unk20 = lbl_805E4480;
    arg0->unkC = BgGetColorTable(g_bg)->unk4;
    kar_a2d_game_lib__near_8028967c((void *) arg0->unk8, 0xFFFF, lbl_805E4480, lbl_805E4484);
    kar_a2d_game_lib__near_80289730((void *) arg0->unk8, 0xFFFF, lbl_805E4480);
    kar_a2d_game_lib__near_80289768((void *) arg0->unk8, 0xFFFF, lbl_805E4488);
    kar_a2d_game_lib__near_80289768((void *) arg0->unk4, 0xFFFF, arg0->unkC);
    kar_a2d_game_lib__near_80289768((void *) arg0->unk8, 0x20, arg0->unkC);
    return arg0;
}

#pragma push
#pragma dont_inline on
extern "C" void kar_a2d_bg5000__near_80340498(BgState *arg0) {
    u16 sp8;
    u16 spC;
    kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DAEF8, &lbl_805DAEF0, 0);
    kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DAEF8, &lbl_805DAEF0, 0);
    arg0->unk1C = kar_a2d_game_lib__near_8028ac98((u16) (((s32) (spC + sp8)) >> 1), (u16) (spC - sp8), 2);
    if ((arg0->unk1C != 0U) || (arg0->unk24 == 0)) {
        arg0->unk18 = 1;
        arg0->unk20 = lbl_805E4480;
        arg0->unk10 = lbl_805E4480;
        arg0->unk14 = lbl_805E4494;
        kar_a2d_game_lib__near_8028967c((void *) arg0->unk4, 0xFFFF, arg0->unk10, arg0->unk14);
        kar_a2d_game_lib__near_80289730((void *) arg0->unk4, 0xFFFF, arg0->unk10);
        kar_a2d_game_lib__near_8028967c((void *) arg0->unk8, 0x20, arg0->unk10, arg0->unk14);
        kar_a2d_game_lib__near_80289730((void *) arg0->unk8, 0x20, arg0->unk10);
        return;
    }
    kar_a2d_bg5000__8034061c(arg0);
}
#pragma pop

extern "C" void kar_a2d_bg5000__8034061c(BgState *arg0) {
    char * const g_bg = lbl_804E7518;
    BgTimeTable *t1 = (BgTimeTable *) BgGetColorTable(g_bg);
    BgTimeTable *t2 = (BgTimeTable *) BgGetColorTable(g_bg);
    f32 v = t1->unk3C + (t2->unk34 + ((BgTimeTable *) BgGetColorTable(g_bg))->unk38);
    v = v * HSD_Randf();
    if (v < ((BgTimeTable *) BgGetColorTable(g_bg))->unk34) {
        arg0->unk18 = 2;
    } else {
        BgTimeTable *t5 = (BgTimeTable *) BgGetColorTable(g_bg);
        if (v < (t5->unk34 + ((BgTimeTable *) BgGetColorTable(g_bg))->unk38)) {
            arg0->unk18 = 3;
        } else {
            arg0->unk18 = 4;
        }
    }
    switch (arg0->unk18) {
    case 2:
        arg0->unk10 = lbl_805E4498;
        arg0->unk14 = lbl_805E449C;
        break;
    case 3:
        arg0->unk10 = lbl_805E44A0;
        arg0->unk14 = lbl_805E44A4;
        break;
    case 4:
        arg0->unk10 = lbl_805E44A8;
        arg0->unk14 = lbl_805E4484;
        break;
    default:
        __assert(lbl_804E7518 + 0x4A0, 0x18F, lbl_805DAF34);
        break;
    }
    kar_a2d_game_lib__near_8028967c((void *) arg0->unk4, 0xFFFF, arg0->unk10, arg0->unk14);
    kar_a2d_game_lib__near_80289730((void *) arg0->unk4, 0xFFFF, arg0->unk10);
    kar_a2d_game_lib__near_8028967c((void *) arg0->unk8, 0x20, arg0->unk10, arg0->unk14);
    kar_a2d_game_lib__near_80289730((void *) arg0->unk8, 0x20, arg0->unk10);
}

extern "C" void kar_a2d_bg5000__near_80340894(BgState *arg0, f32 farg0) {
    f32 t = kar_a2d_game_lib__near_802899d0((void *) arg0->unk4);
    f32 hi = arg0->unk14;
    f32 lo = arg0->unk10;
    arg0->unk20 = kar_a2d_bg5000__near_8034093c(lbl_805E44AC * ((t - lbl_805E44B0 * (lo + hi)) / (hi - lo))) * farg0;
    if (t >= (arg0->unk14 - lbl_805E4488)) {
        kar_a2d_bg5000__near_80340498(arg0);
    }
}

static inline f32 kar_bg5000_poly(f32 y) {
    f32 z;
    if (y <= lbl_805E44F0) {
        z = y * y;
        return y * (lbl_805E4488 - z * __fnmsubs(z, __fnmsubs(lbl_805E44D8, z, lbl_805E44D4), lbl_805E44D0));
    }
    z = (f32) (lbl_805E44C8 - (f64) y);
    z = z * z;
    return lbl_805E44DC - z * __fnmsubs(z, __fnmsubs(lbl_805E44E8, z, lbl_805E44E4), lbl_805E44E0);
}

static inline f32 kar_bg5000_half(f32 y) {
    if (y <= lbl_805E44C8) {
        return kar_bg5000_poly(y);
    }
    return kar_bg5000_poly((f32) (lbl_805E44C0 - (f64) y));
}

static inline f32 kar_bg5000_sin_reduce(f32 y) {
    while (y > lbl_805E44B8) {
        y = (f32) (y - lbl_805E44B8);
    }
    if (y <= lbl_805E44C0) {
        return kar_bg5000_half(y);
    }
    return -kar_bg5000_half((f32) (y - lbl_805E44C0));
}

extern "C" f32 kar_a2d_bg5000__near_8034093c(f32 farg0) {
    if (farg0 != lbl_805E4480) {
        if (farg0 < lbl_805E4480) {
            return -kar_bg5000_sin_reduce(-farg0);
        }
        return kar_bg5000_sin_reduce(farg0);
    }
    return lbl_805E4480;
}

extern "C" void kar_a2d_bg5000__80340d88(BgState *arg0) {
    char * const g_bg = lbl_804E7518;
    BgColorTable *ct = BgGetColorTable(g_bg);
    if (arg0->unkC != ct->unk4) {
        arg0->unkC = BgGetColorTable(g_bg)->unk4;
        kar_a2d_game_lib__near_80289768((void *) arg0->unk4, 0xFFFF, arg0->unkC);
        kar_a2d_game_lib__near_80289768((void *) arg0->unk8, 0x20, arg0->unkC);
    }
    switch (arg0->unk18) {
    case 0:
        kar_a2d_bg5000__near_80340498(arg0);
        return;
    case 1:
        if (arg0->unk1C != 0U) {
            arg0->unk1C = arg0->unk1C - 1;
            return;
        }
        {
            f32 tgt = arg0->unk14;
            if (kar_a2d_game_lib__near_802899d0((void *) arg0->unk4) >= (tgt - lbl_805E4488)) {
                if (arg0->unk24 != 0) {
                    BgTimeTable *t1 = (BgTimeTable *) BgGetColorTable(g_bg);
                    BgTimeTable *t2 = (BgTimeTable *) BgGetColorTable(g_bg);
                    f32 v = t1->unk3C + (t2->unk34 + ((BgTimeTable *) BgGetColorTable(g_bg))->unk38);
                    v = v * HSD_Randf();
                    if (v < ((BgTimeTable *) BgGetColorTable(g_bg))->unk34) {
                        arg0->unk18 = 2;
                    } else {
                        BgTimeTable *t5 = (BgTimeTable *) BgGetColorTable(g_bg);
                        if (v < (t5->unk34 + ((BgTimeTable *) BgGetColorTable(g_bg))->unk38)) {
                            arg0->unk18 = 3;
                        } else {
                            arg0->unk18 = 4;
                        }
                    }
                    switch (arg0->unk18) {
                    case 2:
                        arg0->unk10 = lbl_805E4498;
                        arg0->unk14 = lbl_805E449C;
                        break;
                    case 3:
                        arg0->unk10 = lbl_805E44A0;
                        arg0->unk14 = lbl_805E44A4;
                        break;
                    case 4:
                        arg0->unk10 = lbl_805E44A8;
                        arg0->unk14 = lbl_805E4484;
                        break;
                    default:
                        __assert(lbl_804E7518 + 0x4A0, 0x18F, lbl_805DAF34);
                        break;
                    }
                    kar_a2d_game_lib__near_8028967c((void *) arg0->unk4, 0xFFFF, arg0->unk10, arg0->unk14);
                    kar_a2d_game_lib__near_80289730((void *) arg0->unk4, 0xFFFF, arg0->unk10);
                    kar_a2d_game_lib__near_8028967c((void *) arg0->unk8, 0x20, arg0->unk10, arg0->unk14);
                    kar_a2d_game_lib__near_80289730((void *) arg0->unk8, 0x20, arg0->unk10);
                    return;
                }
                kar_a2d_bg5000__near_80340498(arg0);
            }
        }
        return;
    case 2:
        kar_a2d_bg5000__near_80340894(arg0, BgGetColorTable(g_bg)->unk18);
        return;
    case 3:
        kar_a2d_bg5000__near_80340894(arg0, BgGetColorTable(g_bg)->unk1C);
        return;
    case 4:
        kar_a2d_bg5000__near_80340894(arg0, BgGetColorTable(g_bg)->unk20);
        return;
    }
}

extern "C" void kar_a2d_bg5000__near_803411f4(BgObj *arg0, void *arg1) {
    void *p = *(void **) ((char *) arg1 + 4);
    p = *(void **) ((char *) p + 4);
    p = *(void **) ((char *) p + 0xC);
    void *var_r4 = *(void **) ((char *) p - 4);
    if (var_r4 == NULL) {
        var_r4 = &lbl_805DAF38;
    }
    if (kar_fl_indirectload__80391f10(lbl_804E79F8, var_r4) != 0) {
        KartIF **holder = (KartIF **) ((char *) arg1 + 0x2C);
        KartIF *kif = *holder;
        if ((kif != NULL) && (kif->v64() == 0)) {
            f32 mag = arg0->unk20;
            f32 a = fn_80296264(lbl_805E4488);
            f32 b = fn_8029626C(lbl_805E44FC) * a;
            f32 rate = lbl_805E4488 * (fn_802D4C30(lbl_805E44F8) * b);
            f32 c = fn_80296264(lbl_805E4488);
            f32 d = fn_8029626C(lbl_805E4488) * c;
            f32 e = fn_802D4C30(lbl_805E4500) * d;
            f32 f2 = lbl_805E4488 * e;
            Vec3f v;
            v.x = lbl_805E4480;
            v.y = lbl_805E4480;
            PSVECScale(&v, &v, (mag * rate) / f2, f2, e);
            kif->vD4(v.x, v.y, v.z);
        }
    }
}

extern "C" void kar_a2d_bg5000__near_80341360(BgObj *arg0, JobjXform *arg1) {
    void *p = *(void **) ((char *) arg1 + 4);
    p = *(void **) ((char *) p + 4);
    p = *(void **) ((char *) p + 0xC);
    void *var_r4 = *(void **) ((char *) p - 4);
    if (var_r4 == NULL) {
        var_r4 = &lbl_805DAF38;
    }
    if (kar_fl_indirectload__80391f10(lbl_804E79F8, var_r4) != 0) {
        f32 mag = arg0->unk20;
        f32 a = fn_80296264(lbl_805E4488);
        f32 b = fn_8029626C(lbl_805E44FC) * a;
        f32 rate = lbl_805E4488 * (fn_802D4C30(lbl_805E44F8) * b);
        f32 c = fn_80296264(lbl_805E4488);
        f32 d = fn_8029626C(lbl_805E4488) * c;
        f32 e = fn_802D4C30(lbl_805E4500) * d;
        f32 f2 = lbl_805E4488 * e;
        Vec3f v;
        v.x = lbl_805E4480;
        v.y = lbl_805E4480;
        PSVECScale(&v, &v, (mag * rate) / f2, f2, e);
        arg1->posX = v.x;
        arg1->posY = v.y;
        arg1->posZ = v.z;
    }
}

extern "C" void fn_8034148C(void) {
}

extern "C" void kar_a2d_bg5000__near_80341490(BgObj *arg0, JobjXform *arg1) {
    if ((arg0->unk4 != NULL) && (*(f32 *) &arg1->pad54[8] < lbl_805E4504)) {
        KartIF **holder = (KartIF **) ((char *) arg1 + 0x2C);
        KartIF *kif = *holder;
        if (kif != NULL) {
            s32 which = 0;
            void *p;
            p = *(void **) ((char *) arg1 + 4);
            p = *(void **) ((char *) p + 4);
            p = *(void **) ((char *) p + 0xC);
            void *v4 = *(void **) ((char *) p - 4);
            if (v4 == NULL) v4 = &lbl_805DAF38;
            if (kar_fl_indirectload__80391f10(lbl_804E7518 + 0x4F0, v4) != 0) which = 6;

            p = *(void **) ((char *) arg1 + 4);
            p = *(void **) ((char *) p + 4);
            p = *(void **) ((char *) p + 0xC);
            v4 = *(void **) ((char *) p - 4);
            if (v4 == NULL) v4 = &lbl_805DAF38;
            if (kar_fl_indirectload__80391f10(lbl_804E7518 + 0x504, v4) != 0) which = 5;

            p = *(void **) ((char *) arg1 + 4);
            p = *(void **) ((char *) p + 4);
            p = *(void **) ((char *) p + 0xC);
            v4 = *(void **) ((char *) p - 4);
            if (v4 == NULL) v4 = &lbl_805DAF38;
            if (kar_fl_indirectload__80391f10(lbl_804E7518 + 0x518, v4) != 0) which = 4;

            p = *(void **) ((char *) arg1 + 4);
            p = *(void **) ((char *) p + 4);
            p = *(void **) ((char *) p + 0xC);
            v4 = *(void **) ((char *) p - 4);
            if (v4 == NULL) v4 = &lbl_805DAF38;
            if (kar_fl_indirectload__80391f10(lbl_804E7518 + 0x52C, v4) != 0) which = 3;

            p = *(void **) ((char *) arg1 + 4);
            p = *(void **) ((char *) p + 4);
            p = *(void **) ((char *) p + 0xC);
            v4 = *(void **) ((char *) p - 4);
            if (v4 == NULL) v4 = &lbl_805DAF38;
            if (kar_fl_indirectload__80391f10(lbl_804E7518 + 0x540, v4) != 0) which = 2;

            p = *(void **) ((char *) arg1 + 4);
            p = *(void **) ((char *) p + 4);
            p = *(void **) ((char *) p + 0xC);
            v4 = *(void **) ((char *) p - 4);
            if (v4 == NULL) v4 = &lbl_805DAF38;
            if (kar_fl_indirectload__80391f10(lbl_804E7518 + 0x554, v4) != 0) which = 1;

            if (which != 0) {
                Vec3f v;
                kar_a2d_bg5000__near_80341860((f32 *) &v, arg0, which, kif->v64());
                kif->vD4(v.x, v.y, v.z);
            }
        }
    }
}

extern "C" void kar_a2d_bg5000__near_80341694(BgObj *arg0, JobjXform *arg1) {
    if (arg0->unk4 != NULL) {
        s32 which = 0;
        void *p;
        p = *(void **) ((char *) arg1 + 4);
        p = *(void **) ((char *) p + 4);
        p = *(void **) ((char *) p + 0xC);
        void *v4 = *(void **) ((char *) p - 4);
        if (v4 == NULL) v4 = &lbl_805DAF38;
        if (kar_fl_indirectload__80391f10(lbl_804E7518 + 0x4F0, v4) != 0) which = 6;

        p = *(void **) ((char *) arg1 + 4);
        p = *(void **) ((char *) p + 4);
        p = *(void **) ((char *) p + 0xC);
        v4 = *(void **) ((char *) p - 4);
        if (v4 == NULL) v4 = &lbl_805DAF38;
        if (kar_fl_indirectload__80391f10(lbl_804E7518 + 0x504, v4) != 0) which = 5;

        p = *(void **) ((char *) arg1 + 4);
        p = *(void **) ((char *) p + 4);
        p = *(void **) ((char *) p + 0xC);
        v4 = *(void **) ((char *) p - 4);
        if (v4 == NULL) v4 = &lbl_805DAF38;
        if (kar_fl_indirectload__80391f10(lbl_804E7518 + 0x518, v4) != 0) which = 4;

        p = *(void **) ((char *) arg1 + 4);
        p = *(void **) ((char *) p + 4);
        p = *(void **) ((char *) p + 0xC);
        v4 = *(void **) ((char *) p - 4);
        if (v4 == NULL) v4 = &lbl_805DAF38;
        if (kar_fl_indirectload__80391f10(lbl_804E7518 + 0x52C, v4) != 0) which = 3;

        p = *(void **) ((char *) arg1 + 4);
        p = *(void **) ((char *) p + 4);
        p = *(void **) ((char *) p + 0xC);
        v4 = *(void **) ((char *) p - 4);
        if (v4 == NULL) v4 = &lbl_805DAF38;
        if (kar_fl_indirectload__80391f10(lbl_804E7518 + 0x540, v4) != 0) which = 2;

        p = *(void **) ((char *) arg1 + 4);
        p = *(void **) ((char *) p + 4);
        p = *(void **) ((char *) p + 0xC);
        v4 = *(void **) ((char *) p - 4);
        if (v4 == NULL) v4 = &lbl_805DAF38;
        if (kar_fl_indirectload__80391f10(lbl_804E7518 + 0x554, v4) != 0) which = 1;

        if (which != 0) {
            Vec3f v;
            kar_a2d_bg5000__near_80341860((f32 *) &v, arg0, which, 0);
            arg1->posX = v.x;
            arg1->posY = v.y;
            arg1->posZ = v.z;
        }
    }
}

extern "C" void fn_8034185C(void) {
}


extern "C" void kar_a2d_bg5000__near_80341860(f32 *arg0, void *arg2, s32 kind, u8 arg3) {
    f32 v = lbl_805E4480;
    switch (kind) {
    case 1: {
        if (arg3 != 0) {
            BG_SELECT_TABLE(t)
            v = t->unk14;
        } else {
            BG_SELECT_TABLE(t)
            v = t->unk8;
        }
        break;
    }
    case 2: {
        if (arg3 != 0) {
            BG_SELECT_TABLE(t)
            v = t->unk10;
        } else {
            BG_SELECT_TABLE(t)
            v = t->unk4;
        }
        break;
    }
    case 3: {
        if (arg3 != 0) {
            BG_SELECT_TABLE(t)
            v = t->unkC;
        } else {
            BG_SELECT_TABLE(t)
            v = t->unk4;
        }
        break;
    }
    case 4: {
        if (arg3 != 0) {
            BG_SELECT_TABLE(t)
            v = t->unkC;
        } else {
            BG_SELECT_TABLE(t)
            v = t->unk4;
        }
        break;
    }
    case 5: {
        if (arg3 != 0) {
            BG_SELECT_TABLE(t)
            v = t->unk10;
        } else {
            BG_SELECT_TABLE(t)
            v = t->unk4;
        }
        break;
    }
    case 6: {
        if (arg3 != 0) {
            BG_SELECT_TABLE(t)
            v = t->unk14;
        } else {
            BG_SELECT_TABLE(t)
            v = t->unk8;
        }
        break;
    }
    }
    f32 a = fn_80296264(lbl_805E4488);
    f32 b = fn_8029626C(lbl_805E44FC) * a;
    f32 mag = lbl_805E4488 * (fn_802D4C30(lbl_805E44F8) * b);
    f32 c = fn_80296264(lbl_805E4488);
    f32 d = fn_8029626C(lbl_805E4488) * c;
    f32 e = fn_802D4C30(lbl_805E4500) * d;
    f32 f2 = lbl_805E4488 * e;
    Vec3f sc;
    sc.x = lbl_805E4480;
    sc.y = lbl_805E4480;
    PSVECScale(&sc, &sc, (v * mag) / f2, f2, e);
    arg0[0] = sc.x;
    arg0[1] = sc.y;
    arg0[2] = sc.z;
}

extern "C" void *kar_a2d_bg5000__near_80341c7c(BgManager *arg0, s16 arg1) {
    if (arg0 != NULL) {
        arg0->unk0 = lbl_804E7B10;
        lbl_805DDC50 = 0;
        RefObj **h1 = arg0->unk10;
        if (h1 != NULL) {
            (*h1)->Release(1);
        }
        RefObj **h2 = arg0->unkC;
        if (h2 != NULL) {
            (*h2)->Release(1);
        }
        BgObj *left = arg0->unk8;
        if (left != NULL) {
            kar_a2d_refract__near_80384600(left->unk11C, -1);
            *(void **) &left->unkCC = lbl_804BDF70;
            kar_a2d_effecthandle__near_8037b33c(&left->unkCC, 0);
            *(void **) &left->unkCC = lbl_804BDF2C;
            left->unkCC.v1c();
            *(void **) &left->unk7C = lbl_804BDF70;
            kar_a2d_effecthandle__near_8037b33c(&left->unk7C, 0);
            *(void **) &left->unk7C = lbl_804BDF2C;
            left->unk7C.v1c();
            *(void **) &left->unk14 = lbl_804D7300;
            left->unk38 = (GeneratorIface *) ((char *) lbl_804D7300 + 0x38);
            left->unk38 = (GeneratorIface *) lbl_804BF3C0;
            *(void **) &left->unk14 = lbl_804D7700;
            *(void **) &left->unk14 = lbl_804BF4DC;
            left->unk14.v1c();
            fn_8038CB78(left);
        }
        BgObj *right = arg0->unk4;
        if (right != NULL) {
            kar_a2d_refract__near_80384600(right->unk11C, -1);
            *(void **) &right->unkCC = lbl_804BDF70;
            kar_a2d_effecthandle__near_8037b33c(&right->unkCC, 0);
            *(void **) &right->unkCC = lbl_804BDF2C;
            right->unkCC.v1c();
            *(void **) &right->unk7C = lbl_804BDF70;
            kar_a2d_effecthandle__near_8037b33c(&right->unk7C, 0);
            *(void **) &right->unk7C = lbl_804BDF2C;
            right->unk7C.v1c();
            *(void **) &right->unk14 = lbl_804D7300;
            right->unk38 = (GeneratorIface *) ((char *) lbl_804D7300 + 0x38);
            right->unk38 = (GeneratorIface *) lbl_804BF3C0;
            *(void **) &right->unk14 = lbl_804D7700;
            *(void **) &right->unk14 = lbl_804BF4DC;
            right->unk14.v1c();
            fn_8038CB78(right);
        }
        arg0->unk0 = lbl_804BCE14;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void *kar_a2d_bg5000__near_80341f90(void) {
    void *r;
    if ((u32) ((DiagResult *) kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DB0D0, &lbl_805DB0C8, 0))->unk14 == 1) {
        r = lbl_804E83B0;
    } else {
        r = lbl_804E8474;
    }
    return r;
}

extern "C" void *kar_a2d_bg5000__near_80341fe0(u32 arg0) {
    if (arg0 == 0U) {
        return lbl_804E83B0;
    }
    return lbl_804E8474;
}

static char lbl_804E7CF0[] = "PostDrawEffect";

extern "C" void kar_a2d_bg5000__near_80341ffc(BgObj *arg0) {
    char * const base = lbl_804E7CF0;
    OSReport(base + 0x880);
    OSReport(base + 0x890);
    f32 v0 = *(f32 *) ((char *) arg0 + 0x0);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0x8b4);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v0);
    f32 v1 = *(f32 *) ((char *) arg0 + 0x4);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0x8d8);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v1);
    f32 v2 = *(f32 *) ((char *) arg0 + 0x8);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0x904);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v2);
    f32 v3 = *(f32 *) ((char *) arg0 + 0xc);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0x930);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v3);
    f32 v4 = *(f32 *) ((char *) arg0 + 0x10);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0x95c);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v4);
    f32 v5 = *(f32 *) ((char *) arg0 + 0x14);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0x988);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v5);
    f32 v6 = *(f32 *) ((char *) arg0 + 0x18);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0x9ac);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v6);
    f32 v7 = *(f32 *) ((char *) arg0 + 0x1c);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0x9d8);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v7);
    f32 v8 = *(f32 *) ((char *) arg0 + 0x20);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xa04);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v8);
    f32 v9 = *(f32 *) ((char *) arg0 + 0x24);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xa2c);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v9);
    f32 v10 = *(f32 *) ((char *) arg0 + 0x28);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xa54);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v10);
    f32 v11 = *(f32 *) ((char *) arg0 + 0x2c);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xa7c);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v11);
    f32 v12 = *(f32 *) ((char *) arg0 + 0x30);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xaa4);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v12);
    f32 v13 = *(f32 *) ((char *) arg0 + 0x34);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xad4);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v13);
    f32 v14 = *(f32 *) ((char *) arg0 + 0x38);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xb00);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v14);
    f32 v15 = *(f32 *) ((char *) arg0 + 0x3c);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xb28);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v15);
    f32 v16 = *(f32 *) ((char *) arg0 + 0x40);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xb50);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v16);
    f32 v17 = *(f32 *) ((char *) arg0 + 0x44);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xb78);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v17);
    f32 v18 = *(f32 *) ((char *) arg0 + 0x48);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xba0);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v18);
    f32 v19 = *(f32 *) ((char *) arg0 + 0x4c);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xbd0);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v19);
    f32 v20 = *(f32 *) ((char *) arg0 + 0x50);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xbfc);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v20);
    f32 v21 = *(f32 *) ((char *) arg0 + 0x54);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xc24);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v21);
    f32 v22 = *(f32 *) ((char *) arg0 + 0x58);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xc4c);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v22);
    f32 v23 = *(f32 *) ((char *) arg0 + 0x5c);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xc70);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v23);
    f32 v24 = *(f32 *) ((char *) arg0 + 0x60);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xc98);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v24);
    f32 v25 = *(f32 *) ((char *) arg0 + 0x64);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xcc8);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v25);
    f32 v26 = *(f32 *) ((char *) arg0 + 0x68);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xcf8);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v26);
    f32 v27 = *(f32 *) ((char *) arg0 + 0x6c);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xd20);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v27);
    f32 v28 = *(f32 *) ((char *) arg0 + 0x70);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xd48);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v28);
    f32 v29 = *(f32 *) ((char *) arg0 + 0x74);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xd6c);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v29);
    f32 v30 = *(f32 *) ((char *) arg0 + 0x78);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xd94);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v30);
    f32 v31 = *(f32 *) ((char *) arg0 + 0x7c);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xdc4);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v31);
    f32 v32 = *(f32 *) ((char *) arg0 + 0x80);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xdf4);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v32);
    f32 v33 = *(f32 *) ((char *) arg0 + 0x84);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xe1c);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v33);
    f32 v34 = *(f32 *) ((char *) arg0 + 0x88);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xe44);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v34);
    f32 v35 = *(f32 *) ((char *) arg0 + 0x8c);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xe68);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v35);
    f32 v36 = *(f32 *) ((char *) arg0 + 0x90);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xe90);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v36);
    f32 v37 = *(f32 *) ((char *) arg0 + 0x94);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xec0);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v37);
    f32 v38 = *(f32 *) ((char *) arg0 + 0x98);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xef0);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v38);
    f32 v39 = *(f32 *) ((char *) arg0 + 0x9c);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xf18);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v39);
    f32 v40 = *(f32 *) ((char *) arg0 + 0xa0);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xf40);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v40);
    f32 v41 = *(f32 *) ((char *) arg0 + 0xa4);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xf64);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v41);
    f32 v42 = *(f32 *) ((char *) arg0 + 0xa8);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xf8c);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v42);
    f32 v43 = *(f32 *) ((char *) arg0 + 0xac);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xfbc);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v43);
    f32 v44 = *(f32 *) ((char *) arg0 + 0xb0);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0xfec);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v44);
    f32 v45 = *(f32 *) ((char *) arg0 + 0xb4);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0x1004);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v45);
    f32 v46 = *(f32 *) ((char *) arg0 + 0xb8);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0x1014);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v46);
    f32 v47 = *(f32 *) ((char *) arg0 + 0xbc);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0x102c);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v47);
    f32 v48 = *(f32 *) ((char *) arg0 + 0xc0);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E0, base + 0x104c);
    OSReport(lbl_805DB0D8);
    OSReport(lbl_805DB0E8, v48);
    OSReport(lbl_805DB0F0);
}
