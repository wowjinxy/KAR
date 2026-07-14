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
    virtual void v1c(s32);
    virtual void v20();
    virtual GameEffectItem *GetNext();
};

class BgFxItemBase {
public:
    virtual ~BgFxItemBase();
    virtual u8 Match();
};

typedef u8 (BgFxItemBase::*BgFxMatchFn)();

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

struct BgFxNode {
    s32 unk0;
    BgFxNode *next;
};

struct BgFxSlot {
    s32 unk0;
    char pad4[0x180];
};

struct BgFxPool {
    BgFxSlot elems[32];
    s32 head;
    s32 count;
};

struct BgFxListMgr {
    s32 unk0;
    s32 unk4;
    BgFxPool *pool;
    BgFxNode head;
};

struct DiagCollection {
    void *vtable;
    s32 count;
    void **items;
};

struct DiagResult {
    char pad0[0x14];
    s32 unk14;
    void *unk18;
};

struct MeteorNode {
    s32 unk0;
    BgFxNode *unk4;
    void *unk8;
    char padC[0x14 - 0xC];
    u32 unk14;
    char pad18[0x2C - 0x18];
    u8 unk2C_unused;
    char pad2D[0x34 - 0x2D];
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    char pad40[0x60 - 0x40];
    s32 unk60;
    char pad64[0x68 - 0x64];
    s32 unk68;
    char pad6C[0x94 - 0x6C];
    char pad94[0xE8 - 0x94];
    GameEffectItem unkE8;
    char pad134[0x140 - 0x134];
    f32 unk140;
    s32 unk144;
    char pad148[0x168 - 0x148];
    f32 unk168;
    f32 unk16C;
    f32 unk170;
    s32 unk174;
    u8 unk178;
    char pad179[0x17C - 0x179];
    u32 unk17C;
    u8 unk180;
    char pad181[0x184 - 0x181];
};

struct BgObj {
    void *vtable;              //0x00
    char lbArrA[0x14];         //0x04
    char lbArrB[0x3C];         //0x18
    DiagCollection coll;        //0x54
    BgFxListMgr fxList;         //0x60
    s32 unk74;
    GameEffectItem fx78;        //0x78
    void *unkC4;
    u8 unkC8;
    u8 unkC9;
    char pad[0x300];
};

extern "C" {

void *kar_diag__803ad760(s32, s32, void *, void *, s32);
void kar_diag__802affd8(void *, void *, s32, void **);
void kar_diag__802b042c(void *, s32);

void *fn_8038CB28(s32);
void fn_8038CB78(void *);
void *fn_8038D0A8(void *, void *);
void *fn_80313A84(void *, s32, void *);
void *fn_803158A8(void *, void *);
void fn_80316128(void *, s32);
void *fn_8030D510(void);

u8 __ptmf_scall(void *);

f32 fn_80296264(u32);
f32 fn_8029626C(f32);
f32 fn_802D4C30(f32);

void HSD_ForeachAnim(void *, s32, u32, void *, s32, f64);
void HSD_JObjClearFlagsAll(void *, s32);
void HSD_JObjSetFlags(s32);
void HSD_JObjSetMtxDirtySub(void *);
void HSD_JObjUnref(void);
f32 HSD_Randf(void);
s32 HSD_Randi(s32);
f32 PSVECDotProduct(f32 *, f32 *);
f32 PSVECMag(f32 *);
void PSVECNormalize(f32 *, f32 *);

extern void *HSD_AObjSetCurrentFrame;
extern void *HSD_AObjSetRate;

u8 kar_fl_indirectload__80391f10(void *, void *);

void *kar_a2d_bg5000__8033fc54(void *, u8, void *, void *, void *, s32, void *, s32);
void *kar_a2d_bg5000__80340348(void *, s8, void *, void *);
void kar_a2d_bg5000__80340d88(void *);
void kar_a2d_bg5000__near_8034011c(void *);
void kar_a2d_bg5000__near_803411f4(void *, void *);
void kar_a2d_bg5000__near_80341360(void *, void *);
void kar_a2d_bg5000__near_80341490(void *, void *);
void kar_a2d_bg5000__near_80341694(void *, void *);

void kar_a2d_effect_slideblur__near_80382bc8(s32, void *, s32);

void *kar_a2d_effecthandle__8037b028(void *, s32, s32, void *, void *, void *, f32);
void kar_a2d_effecthandle__near_8037b33c(void *, u8);
void *kar_a2d_effecthandle__near_8037cf7c(void);

void kar_a2d_game_audio__near_80379398(void *);
void kar_a2d_game_audio__near_80379784(void *, s32, void *);

void kar_a2d_game_effect__near_8037afd0(void *, u8);

void kar_a2d_game_lib__near_802891c8(f32 *, f32 *, f32);
void kar_a2d_game_lib__near_8028967c(void *, u16, f32, f32);
void kar_a2d_game_lib__near_80289730(void *, u16, f32);
void kar_a2d_game_lib__near_80289768(void *, u16, f32);

void kar_a2d_grindrail__near_80324440(s32);
void kar_a2d_grindrail__near_80324560(void *, void *);

void kar_a2d_lavabomb__803215f8(void *, void *, s32);
void kar_a2d_lavabomb__near_80320208(void *);
void kar_a2d_lavabomb__near_8032028c(void *);
void kar_a2d_lavabomb__near_80320310(void *);
void kar_a2d_lavabomb__near_80320430(void *, void *, s32, s32);
void kar_a2d_lavabomb__near_80320708(void *);
void kar_a2d_lavabomb__near_80321160(void *);
void kar_a2d_lavabomb__near_803211e4(void *);
void kar_a2d_lavabomb__near_80321268(void *);
void kar_a2d_lavabomb__near_803212f4(void *, u16, s32);
void kar_a2d_lavabomb__near_80321430(void *, s32, f32);
void kar_a2d_lavabomb__near_803218dc(void *, void *);

void kar_a2d_refract__near_80384600(void *, s32);
void kar_a2d_refract__near_80384ea4(u32, u32, f32, f32, f32);
void kar_a2d_refract__near_80384f44(void);

void kar_a2d_soundhandle__80379b1c(void *, s32, u32);

void kar_grcoll__803d1978(s32, f32, f32, f32);
void *kar_object__8038d158(void *, s32, s32);

void OSReport(const char *, ...);

extern s32 lbl_805DDBC0;
extern s32 lbl_805DDBC8;
extern s32 lbl_805DDB80;

extern char lbl_804BCE14[];
extern char lbl_804BD724[];
extern char lbl_804BDB74[0x28];
extern char lbl_804BDBC0[];
extern char lbl_804BDBE8[];
extern char lbl_804BDCBC[];
extern char lbl_804BDD08[];
extern char lbl_804BDF2C[0x28];
extern char lbl_804BDF70[0x28];
extern char lbl_804BE0C4[];
extern char lbl_804BE104[];
extern char lbl_804BE210[];
extern char lbl_804BE238[];
extern char lbl_804BF3C0[];
extern char lbl_804BF4DC[];
extern char lbl_804D7300[];
extern char lbl_804D7700[];
extern char lbl_804E0EB8[0x10];
extern char lbl_804E1620[];
extern char lbl_804E2104[];
extern char lbl_804E2110[];
extern char lbl_804F3510[];
extern char lbl_804F4E38[];

extern void *lbl_805DDC48;
extern s32 lbl_805DDC70;
extern s32 lbl_805DDC78;
extern void *lbl_805DDCA0;
extern s32 lbl_805DDB2C;

extern f32 lbl_804E6320;
extern f32 lbl_804E63A4;

extern char lbl_804E5C60[];

extern const f32 lbl_805E43D8; /* 0.0F */
extern const f32 lbl_805E43DC; /* 5.0F */
extern const f32 lbl_805E43E0; /* 1.0F */
extern const f64 lbl_805E43E8; /* 0.5 */
extern const f64 lbl_805E43F0; /* 3.0 */
extern const f32 lbl_805E43F8; /* 0.01F */
extern const f32 lbl_805E43FC; /* 0.05F */
extern const f32 lbl_805E4400; /* 2.0F */
extern const f32 lbl_805E4404; /* 3600.0F */
extern const f32 lbl_805E4408; /* -10.0F */
extern const f32 lbl_805E440C; /* 0.2F */
extern const f64 lbl_805E4410; /* 0.0 */
extern const f32 lbl_805E4418; /* 0.5F */
extern const f32 lbl_805E441C; /* 1000.0F */
extern const f32 lbl_805E4420; /* 0.016666668F */
extern const f32 lbl_805E4424; /* -1.0F */
extern const f32 lbl_805E4428; /* -0.05F */
extern const f32 lbl_805E442C; /* 50.0F */
extern const f32 lbl_805E4430; /* 0.8F */
extern const f32 lbl_805E4434; /* 5.4F */
extern const f32 lbl_805E4438; /* -0.4F */
extern const f32 lbl_805E443C; /* 9.0F */
extern const f32 lbl_805E4440; /* 17.0F */
extern const f32 lbl_805E4444; /* 24.0F */
extern const f32 lbl_805E4448; /* 25.0F */
extern const f32 lbl_805E444C; /* 32.0F */
extern const f32 lbl_805E4450; /* 8.0F */
extern const f32 lbl_805E4454; /* -0.5F */
extern const f32 lbl_805E4458; /* 0.0011111111F */
extern const f32 lbl_805E445C; /* 100.0F */
extern const f32 lbl_805E4460; /* -0.3F */
extern const f32 lbl_805E4464; /* 1.4F */
extern const f32 lbl_805E4468; /* -0.7F */
extern const f64 lbl_805E4470; /* 4503599627370496.0 */
extern const f32 lbl_805E4478; /* 0.07F */
extern const f32 lbl_805E447C; /* 16.0F */
extern const f32 lbl_805E4480; /* 0.0F */
extern const f32 lbl_805E4484; /* 1023.0F */
extern const f32 lbl_805E4488; /* 1.0F */

}

extern "C" void *lbl_805DACC8[2];
extern "C" void *lbl_805DACD0[2];
extern "C" void *lbl_805DADE0[2];
extern "C" void *lbl_805DADE8[2];
static char kar_srcfile_jobj_h_805dae0c[7] = "jobj.h";
static char lbl_805DAE14[5] = "jobj";
extern "C" s32 lbl_805DAE1C;
extern "C" void *lbl_805DAE28[2];
extern "C" void *lbl_805DAE30[2];
extern "C" void *lbl_805DAEE0[2];
extern "C" void *lbl_805DAEE8[2];
extern "C" void *lbl_805DAEF0[2];
extern "C" void *lbl_805DAEF8[2];
static char lbl_805DAF00[5] = "    ";
static char lbl_805DAF08[8] = "/// %s\n";
static char lbl_805DAF10[6] = "%ff,\n";
static char lbl_805DAF18[4] = "};\n";

extern "C" void *lbl_805DD944;
extern "C" s32 lbl_805DD948;
extern "C" void *lbl_805DD94C;
extern "C" void *lbl_805DD950;
extern "C" void *lbl_805DD954;
extern "C" void *lbl_805DD958;
extern "C" void *lbl_805DD95C;
extern "C" void *lbl_805DD960;

extern "C" void *lbl_804E68D4[12];
extern "C" void *lbl_804E6904[16];
extern "C" void *lbl_804E6C74[20];
extern "C" void *lbl_804E6D04[32];
extern "C" char lbl_804E6E30[0x134];
extern "C" char lbl_804E7008[0x30];
extern "C" char lbl_804E7518[0x1c];
extern "C" char lbl_804E7614[0x4c];
extern "C" char lbl_804E7660[0x4c];
extern "C" char lbl_804E7AB4[0x10];
extern "C" char lbl_804E7ADC[0x10];
extern "C" char lbl_804E7B10[0x40];
extern "C" void *lbl_8048A3D8[42];

#define ASSERT2(line, cond, file, str) \
    ((cond) ? ((void) 0) : __assert(file, line, str))

extern "C" MeteorNode *kar_a2d_bg4000__near_8033c7d8(MeteorNode *, void *, void *, void *, void *, void *);
extern "C" void kar_a2d_bg4000__near_8033ce08(MeteorNode *);
extern "C" void kar_a2d_bg4000__near_8033d904(void *, MeteorNode *);
extern "C" BgObj *kar_a2d_bg4000__near_8033e050(BgObj *, s16);
extern "C" MeteorNode *kar_a2d_bg4000__near_8033e298(MeteorNode *, s16);
extern "C" void kar_a2d_bg4000__near_8033e604(BgFxNode **, BgFxListMgr *, BgFxNode **, BgFxNode **);
extern "C" void *kar_a2d_bg4000__near_8033e934(BgFxListMgr *);
extern "C" BgFxPool *kar_a2d_bg4000__near_8033ea00(BgFxPool *);
extern "C" BgFxSlot *kar_a2d_bg4000__near_8033eb44(BgFxPool *);
extern "C" void kar_a2d_bg4000__near_8033eb6c(BgFxPool *, void *);
extern "C" MeteorNode *kar_a2d_bg4000__near_8033d70c(MeteorNode *, s16);

static inline void *DiagLookup18(void) {
    return ((DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DACD0, &lbl_805DACC8, 0))->unk18;
}

extern "C" void *kar_a2d_bg4000__8033b394(BgObj *arg0, s32 arg1) {
    DiagResult *d;
    GameEffectItem *fx;
    void *sp10, *spC, *sp8;
    void *sel;

    arg0->vtable = lbl_804BCE14;
    arg0->vtable = lbl_804E7008;

    d = (DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DACD0, &lbl_805DACC8, 0);
    kar_a2d_lavabomb__near_80320430(arg0->lbArrA, arg0->vtable, (s32) d->unk18, 6);

    d = (DiagResult *) kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DACD0, &lbl_805DACC8, 0);
    kar_a2d_lavabomb__803215f8(arg0->lbArrB, arg0->vtable, (s32) d->unk18);

    arg0->coll.vtable = 0;
    arg0->coll.count = 0;
    arg0->coll.items = 0;

    kar_a2d_bg4000__near_8033e934((BgFxListMgr *) &arg0->fxList);

    fx = &arg0->fx78;
    *(void **) fx = lbl_804BDF2C;
    fx->unk4 = 0;
    fx->unk8 = 0;
    fx->Init();
    *(void **) fx = lbl_804BDF70;
    kar_a2d_effecthandle__8037b028(fx, -1, 0, NULL, NULL, 0, 0.0f);

    arg0->unkC8 = 0;
    arg0->unkC9 = 0;
    lbl_805DDC48 = arg0;

    kar_diag__802b042c(&arg0->coll, 3);

    sel = fn_8038CB28(0x148);
    if (sel != NULL) {
        void *jA = DiagLookup18();
        void *jB = DiagLookup18();
        void *jC = DiagLookup18();
        void *r1 = fn_8038D0A8(jA, lbl_804E5C60 + 0xBCC);
        sel = kar_a2d_bg4000__near_8033c7d8((MeteorNode *) sel, jC, lbl_804E5C60 + 0xBA8, fn_8038D0A8(jB, lbl_804E5C60 + 0xBBC), r1, NULL);
    }
    sp10 = sel;
    kar_diag__802affd8(&arg0->coll, arg0->coll.items + arg0->coll.count, 1, &sp10);

    sel = fn_8038CB28(0x148);
    if (sel != NULL) {
        void *jA = DiagLookup18();
        void *jB = DiagLookup18();
        void *jC = DiagLookup18();
        void *r1 = fn_8038D0A8(jA, lbl_804E5C60 + 0xBFC);
        sel = kar_a2d_bg4000__near_8033c7d8((MeteorNode *) sel, jC, lbl_804E5C60 + 0xBD8, fn_8038D0A8(jB, lbl_804E5C60 + 0xBEC), r1, (void *) 1);
    }
    spC = sel;
    kar_diag__802affd8(&arg0->coll, arg0->coll.items + arg0->coll.count, 1, &spC);

    sel = fn_8038CB28(0x148);
    if (sel != NULL) {
        void *jA = DiagLookup18();
        void *jB = DiagLookup18();
        void *jC = DiagLookup18();
        void *r1 = fn_8038D0A8(jA, lbl_804E5C60 + 0xC2C);
        sel = kar_a2d_bg4000__near_8033c7d8((MeteorNode *) sel, jC, lbl_804E5C60 + 0xC08, fn_8038D0A8(jB, lbl_804E5C60 + 0xC1C), r1, (void *) 2);
    }
    sp8 = sel;
    kar_diag__802affd8(&arg0->coll, arg0->coll.items + arg0->coll.count, 1, &sp8);

    arg0->unk74 = ((s32 *) fn_803158A8(arg0, lbl_804E5C60 + 0xC38))[2];
    arg0->unkC4 = fn_8038D0A8(DiagLookup18(), lbl_804E5C60 + 0xC44);
    if (arg0->unkC4 == NULL) {
        assert_line(0x108, arg0->unkC4 != NULL);
    }
    ((void (*)(void *)) ((void **) arg0->vtable)[6])(arg0);
    return arg0;
}

extern "C" BgFxListMgr *kar_a2d_bg4000__near_8033b7b0(BgFxListMgr *arg0, s16 arg1) {
    if (arg0 != NULL) {
        if (arg0 != NULL && arg0 != NULL && arg0 != NULL) {
            BgFxNode *sp10 = &arg0->head;
            BgFxNode *spC = arg0->head.next;
            BgFxNode *sp8;
            kar_a2d_bg4000__near_8033e604(&sp8, arg0, &spC, &sp10);
            if (((char *) arg0 + 8) != NULL && ((char *) arg0 + 8) != NULL &&
                ((char *) arg0 + 8) != NULL && ((char *) arg0 + 8) != NULL &&
                arg0->pool != NULL) {
                lbl_805DD944 = NULL;
                fn_8038CB78(arg0->pool);
            }
            if (arg0 != NULL && arg0 != NULL && arg0 != NULL && arg0 != NULL &&
                (u32) arg0->unk0 != 0U) {
                lbl_805DD948 = 0;
                fn_8038CB78((void *) arg0->unk0);
            }
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void kar_a2d_bg4000__near_8033b890(BgObj *arg0) {
    void **p;
    void **end;
    BgFxNode *sp10, *spC, *sp8;

    kar_a2d_lavabomb__near_80320310(arg0->lbArrA);
    kar_a2d_lavabomb__near_80321268(arg0->lbArrB);

    p = arg0->coll.items;
    end = p + arg0->coll.count;
    while (p != end) {
        __ptmf_scall(*p);
        p++;
    }

    sp10 = &arg0->fxList.head;
    spC = arg0->fxList.head.next;
    kar_a2d_bg4000__near_8033e604(&sp8, &arg0->fxList, &spC, &sp10);
}

extern "C" void kar_a2d_bg4000__near_8033b954(BgObj *arg0) {
    void **p;
    void **end;
    MeteorNode *node;

    kar_a2d_lavabomb__near_80320208(arg0->lbArrA);
    kar_a2d_lavabomb__near_80321160(arg0->lbArrB);

    p = arg0->coll.items;
    end = p + arg0->coll.count;
    while (p != end) {
        __ptmf_scall(*p);
        p++;
    }

    node = (MeteorNode *) arg0->fxList.head.next;
    while (node != (MeteorNode *) &arg0->fxList.head) {
        switch (node->unk17C) {
        case 0:
            kar_a2d_game_effect__near_8037afd0(&node->unkE8, 0);
            kar_a2d_effecthandle__8037b028(&node->unkE8, 0x28AC, 1, fn_8038D0A8(node->unk8, NULL), NULL, 0, 0.0f);
            node->unk17C = 1;
            break;
        case 1:
            if (node->unk38 < 0.0f) {
                node->unk2C_unused = 1;
                node->unk17C = 2;
            }
            break;
        case 2: {
            f32 mag;
            Vec3f v;
            v.x = node->unk34;
            v.y = node->unk38;
            v.z = node->unk3C;
            mag = PSVECMag(&v.x);
            if (mag != 0.0f) {
                PSVECNormalize(&v.x, &v.x);
                fn_8038D0A8(node->unk8, NULL);
                kar_a2d_game_lib__near_802891c8(&v.x, &v.x, mag);
            }
            if (node->unk68 == 1) {
                fn_8038D0A8(node->unk8, NULL);
                HSD_JObjSetFlags(0x10);
                *((u8 *) node + 0x99) = 0;
                kar_a2d_game_effect__near_8037afd0(&node->unkE8, 0);
                kar_a2d_effecthandle__8037b028(&node->unkE8, 0x28AF, 3, NULL, NULL, 0, 0.0f);
                node->unk68 = 0x78;
                node->unk34 = 0.0f;
                node->unk38 = 0.0f;
                node->unk3C = 0.0f;
                node->unk17C = 3;
            }
            break;
        }
        default:
            if (node->unk68 > 0) {
                node->unk68 -= 1;
            }
            break;
        }
        if (PSVECMag(&node->unk34) < 0.05f) {
            kar_a2d_effecthandle__near_8037b33c(&node->unkE8, 0);
        }
        kar_diag__803ad760(lbl_805DDBC8, 0, &lbl_805DACD0, &lbl_805DACC8, 0);
        node->unk38 = (f32) -((2.0f * ((f32) ((DiagResult *) fn_8030D510())->unk14 / 3600.0f)) - node->unk38);
        node = (MeteorNode *) node->unk4;
    }
}

extern "C" s32 fn_8033BEEC(MeteorNode *arg0) {
    return arg0->unk60 <= 0 ? 1 : 0;
}

extern "C" void kar_a2d_bg4000__near_8033bf00(BgObj *arg0) {
    BgFxNode *node;
    BgFxNode *end = &arg0->fxList.head;

    kar_a2d_lavabomb__near_8032028c(arg0->lbArrA);
    kar_a2d_lavabomb__near_803211e4(arg0->lbArrB);

    node = arg0->fxList.head.next;
    while (node != end) {
        __ptmf_scall((char *) node + 8);
        node = node->next;
    }
}

extern "C" void kar_a2d_bg4000__near_8033bf94(BgObj *arg0) {
    ((DiagObj *) &arg0->coll)->Init();
}

extern "C" void kar_a2d_bg4000__near_8033bfc0(BgObj *arg0, void *arg1) {
    u32 i;
    for (i = 0; i < (u32) arg0->coll.count; i++) {
        kar_a2d_bg4000__near_8033d904(arg0->coll.items[i], (MeteorNode *) arg1);
    }
}

extern "C" void kar_a2d_bg4000__near_8033c034(void *arg0, MeteorNode *arg1) {
    if (arg1->unk3C < lbl_805E43E0) {
        kar_a2d_lavabomb__near_80320708((char *) arg0 + 4);
        kar_a2d_lavabomb__near_803218dc((char *) arg0 + 0x18, arg1);
    }
}

extern "C" MeteorNode *kar_a2d_bg4000__near_8033c08c(MeteorNode *arg0, s32 arg1, f32 *arg2) {
    kar_a2d_grindrail__near_80324440(4);
    arg0->unk0 = (s32) &lbl_804E6E30;

    *(char **) ((char *) arg0 + 0x94) = lbl_804BDCBC;
    *(s32 *) ((char *) arg0 + 0x98) = 0;
    *(s32 *) ((char *) arg0 + 0x9C) = 0;

    arg0->unk140 = 1.0f;
    arg0->unk144 = 7;

    kar_a2d_game_audio__near_80379398((char *) arg0 + 0x12C);
    arg0->unk170 = 0.0f;
    arg0->unk16C = 0.0f;
    arg0->unk168 = 0.0f;
    arg0->unk174 = 0;
    arg0->unk178 = 0;

    kar_object__8038d158((char *) arg0 + 0x54, 0, 1);
    HSD_ForeachAnim(arg0->unk8, 6, 0xFFFF, &HSD_AObjSetRate, 1, 0.0);
    HSD_ForeachAnim(arg0->unk8, 6, 0xFFFF, &HSD_AObjSetCurrentFrame, 1, 0.0);

    return arg0;
}

extern "C" void kar_a2d_bg4000__near_8033c660(MeteorNode *arg0, Vec3f *arg1) {
    if (arg0->unk60 > 1) {
        if (arg0->unk178 == 0) {
            arg0->unk178 = 1;
            arg0->unk168 = arg1->x;
            arg0->unk16C = arg1->y;
            arg0->unk170 = arg1->z;
            kar_a2d_game_audio__near_80379784((char *) arg0 + 0x12C, 0x8000C, &arg0->unk168);
        }
        if (((u32) arg0->unk174 > 1U) && (arg1->z < -0.05f)) {
            kar_a2d_game_effect__near_8037afd0((char *) arg0 + 0x94, 0);
            kar_a2d_effecthandle__8037b028((char *) arg0 + 0x94, 0x28AF, 3, NULL, NULL, 0, 0.0f);
            arg0->unk60 -= 0x32;
            if (arg0->unk60 < 1) {
                arg0->unk60 = 1;
            }
        }
    }
}

extern "C" void fn_8033C788(MeteorNode *arg0) {
    if (arg0->unk60 > 1) {
        arg0->unk60 -= 1;
        if (arg0->unk60 < 1) {
            arg0->unk60 = 1;
        }
    }
}

extern "C" void fn_8033C7B4(MeteorNode *arg0) {
    arg0->unk14 = 0;
}

extern "C" void fn_8033C7C0(MeteorNode *arg0) {
    if (arg0->unk14 != 0) {
        arg0->unk14 -= 1;
    }
}

extern "C" MeteorNode *kar_a2d_bg4000__near_8033c7d8(MeteorNode *arg0, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5) {
    void *sp1C;

    arg0->unk0 = (s32) arg5;
    arg0->unk4 = (BgFxNode *) arg3;
    arg0->unk8 = arg4;

    *(char **) ((char *) arg0 + 0x34) = lbl_804BDF2C;
    *(s32 *) ((char *) arg0 + 0x38) = 0;
    *(s32 *) ((char *) arg0 + 0x3C) = 0;
    *(char **) ((char *) arg0 + 0x34) = lbl_804BDF70;
    kar_a2d_effecthandle__8037b028((char *) arg0 + 0x34, -1, 0, NULL, NULL, 0, 0.0f);

    kar_a2d_game_audio__near_80379398((char *) arg0 + 0x80);

    sp1C = NULL;
    kar_a2d_bg4000__near_8033ce08(arg0);
    if (sp1C != NULL) {
        fn_80316128(sp1C, 0);
        fn_8038CB78(sp1C);
    }
    return arg0;
}

extern "C" MeteorNode *kar_a2d_bg4000__near_8033cd80(MeteorNode *arg0, s16 arg1) {
    if (arg0 != NULL) {
        arg0->unk0 = (s32) &lbl_804E6D04;
        if (arg0 != NULL) {
            arg0->unk0 = (s32) lbl_804F3510;
            if (arg0 != NULL) {
                arg0->unk0 = (s32) lbl_804BD724;
                ((DiagObj *) &arg0->unk0)->v1c();
            }
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void kar_a2d_bg4000__near_8033ce08(MeteorNode *arg0) {
    void **p;
    void **end;
    char *base = (char *) arg0;

    *(s32 *) (base + 0x28) = 0;
    *(u8 *) (base + 0x2C) = 0;
    *(s32 *) (base + 0x30) = 0;
    *(s32 *) (base + 0x13C) = 0;
    *(u8 *) (base + 0x114) = 0;
    kar_a2d_game_lib__near_80289768(arg0->unk8, 0xFFFF, lbl_805E43E0);
    kar_a2d_game_lib__near_8028967c(arg0->unk8, 0xFFFF, lbl_805E43E0, lbl_805E4450);
    kar_a2d_game_lib__near_80289730(arg0->unk8, 0xFFFF, lbl_805E43E0);
    *(f32 *) (base + 0x140) = lbl_805E43E0;
    *(s32 *) (base + 0x144) = 7;
    HSD_JObjClearFlagsAll(arg0->unk8, 0x10);

    p = *(void ***) (base + 0x14);
    end = p + *(s32 *) (base + 0x10);
    while (p != end) {
        __ptmf_scall(*p);
        p++;
    }
}

extern "C" void kar_a2d_bg4000__near_8033cf04(MeteorNode *arg0) {
    if (arg0->unk68 != 0) {
        arg0->unk68 -= 1;
    }
    if (arg0->unk144 != 0) {
        arg0->unk144 -= 1;
        if (arg0->unk144 == 0) {
            switch ((u32) arg0->unk140) {
            case 0x41100000:
                arg0->unk140 = 17.0f;
                arg0->unk144 = 7;
                break;
            case 0x41880000:
                arg0->unk140 = 25.0f;
                arg0->unk144 = 7;
                break;
            case 0x41C80000:
                arg0->unk140 = 1.0f;
                arg0->unk144 = 7;
                break;
            }
        }
    }
}

extern "C" MeteorNode *kar_a2d_bg4000__near_8033d70c(MeteorNode *arg0, s16 arg1) {
    if (arg0 != NULL) {
        arg0->unk0 = (s32) lbl_804BDBE8;
        if (arg0 != NULL) {
            arg0->unk0 = (s32) lbl_804BDB74;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void kar_a2d_bg4000__near_8033d904(void *arg0, MeteorNode *arg1) {
    (void) arg0;
    (void) arg1;
}

struct RotAccum {
    char pad[0x60];
    f32 angle;
    f32 rate;
};

extern "C" void kar_a2d_bg4000__near_8033dfa0(RotAccum *arg0, s32 arg1) {
    kar_grcoll__803d1978(arg1, lbl_805E43D8, arg0->angle, lbl_805E43D8);
    arg0->angle = arg0->angle + arg0->rate;
    if (arg0->angle > lbl_805E4400) {
        arg0->angle = arg0->angle - lbl_805E4400;
    }
}

extern "C" void fn_8033E004(void *arg0, f32 *arg1) {
    arg1[0] = lbl_805E4418;
    arg1[1] = lbl_805E43D8;
    arg1[2] = *(f32 *) ((char *) arg0 + 104);
    arg1[3] = lbl_805E43D8;
    arg1[4] = lbl_805E4418;
    arg1[5] = *(f32 *) ((char *) arg0 + 104);
}

extern "C" void kar_a2d_bg4000__near_8033e030(void) {
    kar_a2d_effecthandle__near_8037cf7c();
}

extern "C" BgObj *kar_a2d_bg4000__near_8033e050(BgObj *arg0, s16 arg1) {
    u32 i;

    if (arg0 != NULL) {
        arg0->vtable = lbl_804E7008;
        for (i = 0; i < (u32) arg0->coll.count; i++) {
            kar_a2d_bg4000__near_8033e298((MeteorNode *) arg0->coll.items[i], 1);
        }
        lbl_805DDC48 = NULL;
        if (&arg0->fx78 != NULL) {
            *(void **) &arg0->fx78 = lbl_804BDF70;
            kar_a2d_effecthandle__near_8037b33c(&arg0->fx78, 0);
        }
        if (&arg0->fx78 != NULL) {
            *(void **) &arg0->fx78 = lbl_804BDF2C;
            ((DiagObj *) &arg0->fx78)->v1c();
        }

        kar_a2d_bg4000__near_8033b7b0(&arg0->fxList, -1);

        if (&arg0->coll != NULL && &arg0->coll != NULL && &arg0->coll != NULL &&
            arg0->coll.items != NULL) {
            fn_8038CB78(arg0->coll.items);
        }
        if (arg0->lbArrB != NULL) {
            u32 j;
            *(char **) arg0->lbArrB = lbl_804E2104;
            for (j = 0; j < *(u32 *) (arg0->lbArrB + 8); j++) {
                void *elem = (*(void ****) (arg0->lbArrB + 0xC))[j];
                if (elem != NULL) {
                    ((RefObj *) elem)->Release(1);
                }
            }
            if (arg0->lbArrB + 4 != NULL && *(void ***) (arg0->lbArrB + 4) != NULL) {
                fn_8038CB78(*(void **) (arg0->lbArrB + 4));
            }
            if (arg0->lbArrB != NULL) {
                *(char **) arg0->lbArrB = lbl_804E2110;
                lbl_805DDB2C = 0;
            }
        }
        if (arg0->lbArrA != NULL) {
            u32 k;
            *(char **) arg0->lbArrA = lbl_804E1620;
            for (k = 0; k < *(u32 *) (arg0->lbArrA + 4); k++) {
                char *elem = (char *) (*(void ****) (arg0->lbArrA + 8))[k];
                if (elem != NULL) {
                    ((RefObj *) *(void **) (elem + 0x1AC))->Release(1);
                }
            }
            if (arg0->lbArrA != NULL && arg0->lbArrA != NULL && arg0->lbArrA != NULL &&
                *(void ***) (arg0->lbArrA + 8) != NULL) {
                fn_8038CB78(*(void **) (arg0->lbArrA + 8));
            }
        }
        if (arg0 != NULL) {
            arg0->vtable = lbl_804BCE14;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" MeteorNode *kar_a2d_bg4000__near_8033e298(MeteorNode *arg0, s16 arg1) {
    if (arg0 != NULL) {
        kar_a2d_game_effect__near_8037afd0(&arg0->unkE8, 0);
        kar_a2d_effecthandle__near_8037b33c(&arg0->unkE8, 0);
        fn_8038CB78(arg0);
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void kar_a2d_bg4000__near_8033e500(BgFxListMgr *arg0, BgFxMatchFn arg1, s32 arg2) {
    BgFxNode *cur = arg0->head.next;
    BgFxNode *end = &arg0->head;

    while (cur != end) {
        if ((((BgFxItemBase *) ((char *) cur + 8))->*arg1)()) {
            BgFxNode *scan = cur->next;
            while (scan != end) {
                if (!(((BgFxItemBase *) ((char *) scan + 8))->*arg1)()) {
                    break;
                }
                scan = scan->next;
            }
            if (cur != scan) {
                while (cur != scan) {
                    BgFxNode *dead;
                    ((GameEffectItemBase *) ((char *) cur + 8))->v1c(-1);
                    dead = cur;
                    cur = cur->next;
                    kar_a2d_bg4000__near_8033eb6c((BgFxPool *) lbl_805DD944, dead);
                    arg0->unk0 -= 1;
                }
            }
            cur = scan;
            if (scan == end) {
                break;
            }
        } else {
            cur = cur->next;
        }
    }
}

extern "C" void kar_a2d_bg4000__near_8033e604(BgFxNode **arg0, BgFxListMgr *arg1, BgFxNode **arg2, BgFxNode **arg3) {
    BgFxNode *first = *arg2;
    BgFxNode *last = *arg3;

    if (first == last) {
        *arg0 = last;
        return;
    }
    {
        BgFxNode *p = (BgFxNode *) first->unk0;
        BgFxNode *q = (BgFxNode *) last->unk0;
        BgFxNode *newNext = q->next;
        p->next = newNext;
        newNext->unk0 = (s32) p;
    }
    while (*arg2 != *arg3) {
        BgFxNode *n = *arg2;
        ((GameEffectItemBase *) ((char *) n + 8))->v1c(-1);
        *arg2 = n->next;
        kar_a2d_bg4000__near_8033eb6c((BgFxPool *) lbl_805DD944, n);
        arg1->unk4 -= 1;
    }
    *arg0 = *arg3;
}

extern "C" void kar_a2d_bg4000__near_8033e6d0(BgFxListMgr *arg0, s32 arg1, void *arg2, void *arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void *kar_a2d_bg4000__near_8033e934(BgFxListMgr *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    {
        BgFxPool * volatile old = NULL;
        BgFxPool *n = (BgFxPool *) fn_8038CB28(0x3088);
        if (n != NULL) {
            n = kar_a2d_bg4000__near_8033ea00(n);
        }
        BgFxPool * volatile tmp = n;
        tmp = NULL;
        BgFxPool * volatile dead = n;
        BgFxPool * volatile commit = n;
        if (old != n) {
            if (old != NULL) {
                lbl_805DD944 = NULL;
                fn_8038CB78(old);
            }
            old = commit;
        }
        if (tmp != NULL) {
            lbl_805DD944 = NULL;
            fn_8038CB78(tmp);
        }
        arg0->pool = old;
        old = NULL;
    }
    arg0->head.unk0 = (s32) &arg0->head;
    arg0->head.next = &arg0->head;
    return arg0;
}

extern "C" BgFxPool *kar_a2d_bg4000__near_8033ea00(BgFxPool *arg0) {
    u32 i = 0;
    arg0->head = 0;
    lbl_805DD944 = arg0;
    while (i < 31U) {
        arg0->elems[i].unk0 = i + 1;
        i++;
    }
    arg0->elems[31].unk0 = -1;
    arg0->count = 0x20;
    return arg0;
}

extern "C" BgFxSlot *kar_a2d_bg4000__near_8033eb44(BgFxPool *arg0) {
    BgFxSlot *slot = &arg0->elems[arg0->head];
    arg0->head = slot->unk0;
    arg0->count -= 1;
    return slot;
}

extern "C" void kar_a2d_bg4000__near_8033eb6c(BgFxPool *arg0, void *arg1) {
    BgFxSlot *slot = (BgFxSlot *) arg1;
    u32 byteDiff = (u32) ((char *) slot - (char *) arg0);
    u32 idx = byteDiff / sizeof(BgFxSlot);
    slot->unk0 = arg0->head;
    arg0->head = idx;
    arg0->count += 1;
}

extern "C" void fn_8033EBA8(char *arg0) {
    kar_a2d_bg4000__near_8033d70c((MeteorNode *) (arg0 - 0x14), 0);
}

extern "C" void *kar_a2d_bg4000__near_8033ebb0(void) {
    u32 cond = (u32) ((DiagResult *) kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DAEF8, &lbl_805DAEF0, 0))->unk14;
    return (cond == 1U) ? lbl_804E7614 : lbl_804E7660;
}

extern "C" void *kar_a2d_bg4000__near_8033ec00(u32 arg0) {
    if (arg0 == 0U) {
        return lbl_804E7614;
    }
    return lbl_804E7660;
}

extern "C" void kar_a2d_bg4000__near_8033ec1c(BgObj *arg0) {
    (void) arg0;
}

extern "C" void *kar_a2d_bg4000__near_8033f0fc(void *arg0, s32 arg1) {
    (void) arg0;
    return arg0;
}

extern "C" void *kar_a2d_bg4000__near_8033f9e8(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void **) arg0 = lbl_804E7AB4;
        if (arg0 != NULL) {
            *(void **) arg0 = lbl_804E0EB8;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void *kar_a2d_bg4000__near_8033fa44(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void **) arg0 = lbl_804E7ADC;
        if (arg0 != NULL) {
            *(void **) arg0 = lbl_804E0EB8;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

struct RibbonState {
    char pad0[4];
    void *jobjA;
    void *jobjB;
    f32 width;
    char pad10[8];
    s32 unk18;
    s32 unk1C;
    f32 unk20;
};

struct RibbonOwner {
    char pad0[12];
    RibbonState *sub;
};

extern "C" void kar_a2d_bg4000__near_8033faa0(RibbonOwner *arg0) {
    DiagResult *d;
    char *table;
    RibbonState *s = arg0->sub;

    s->unk18 = 0;
    s->unk1C = 0;
    s->unk20 = lbl_805E4480;

    d = (DiagResult *) kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DAEF8, &lbl_805DAEF0, 0);
    table = ((u32) d->unk14 == 1U) ? lbl_804E7614 : lbl_804E7660;
    s->width = *(f32 *) (table + 40);

    kar_a2d_game_lib__near_8028967c(s->jobjB, 0xFFFF, lbl_805E4480, lbl_805E4484);
    kar_a2d_game_lib__near_80289730(s->jobjB, 0xFFFF, lbl_805E4480);
    kar_a2d_game_lib__near_80289768(s->jobjB, 0xFFFF, lbl_805E4488);
    kar_a2d_game_lib__near_80289768(s->jobjA, 0xFFFF, s->width);
    kar_a2d_game_lib__near_80289768(s->jobjB, 32, s->width);
}

extern "C" void kar_a2d_bg4000__near_8033fb7c(void *arg0) {
    kar_a2d_bg5000__near_8034011c(*(void **) ((char *) arg0 + 4));
    kar_a2d_bg5000__near_8034011c(*(void **) ((char *) arg0 + 8));
    kar_a2d_bg5000__80340d88(*(void **) ((char *) arg0 + 0xC));
}

extern "C" void fn_8033FBBC(void) {
}

extern "C" void fn_8033FBC0(void) {
}

extern "C" void kar_a2d_bg4000__near_8033fbc4(void *arg0, void *arg1) {
    kar_a2d_bg5000__near_803411f4(*(void **) ((char *) arg0 + 0xC), arg1);
    kar_a2d_bg5000__near_80341490(*(void **) ((char *) arg0 + 0x10), arg1);
}

extern "C" void kar_a2d_bg4000__near_8033fc0c(void *arg0, void *arg1) {
    kar_a2d_bg5000__near_80341360(*(void **) ((char *) arg0 + 0xC), arg1);
    kar_a2d_bg5000__near_80341694(*(void **) ((char *) arg0 + 0x10), arg1);
}
