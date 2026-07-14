#include <dolphin/types.h>

extern "C" {
#include <global.h>
#include <sysdolphin/jobj.h>
#include <dolphin/mtx/mtx.h>
}

#define FU8(p, o) (*(u8 *) ((char *) (p) + (o)))
#define FS8(p, o) (*(s8 *) ((char *) (p) + (o)))
#define FU16(p, o) (*(u16 *) ((char *) (p) + (o)))
#define FS16(p, o) (*(s16 *) ((char *) (p) + (o)))
#define FU32(p, o) (*(u32 *) ((char *) (p) + (o)))
#define FS32(p, o) (*(s32 *) ((char *) (p) + (o)))
#define FF32(p, o) (*(f32 *) ((char *) (p) + (o)))
#define FP(p, o) (*(void **) ((char *) (p) + (o)))

struct Vec3f {
    f32 x, y, z;
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
    virtual Vec3f *v54(void *);
    virtual void v58(void *);
    virtual void v5c();
    virtual void v60();
    virtual u8 v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual Vec3f *v74();
    virtual void v78(Vec3f);
    virtual Vec3f *v7c();
    virtual void v80(Vec3f);
    virtual Vec3f *v84();
    virtual void v88(Vec3f);
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

class LBNodeBase {
public:
    virtual ~LBNodeBase();
    virtual s32 IsLinked();
    virtual void v10();
    virtual void PushFront();
    virtual void PushBack();
    virtual void Remove();
    virtual void Reg1();
    virtual void Reg2();
};

class LBEffectorIF {
public:
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void SetPos(Vec3f *pos);
    virtual void SetRate(f32 val);
};

extern "C" {

void *fn_8038CB28(s32);
void fn_8038CB78(void *);
void *fn_8038D0A8(void *, const char *, u8, void *);
void fn_803AD738(void *);
void *kar_diag__803ad760(s32, s32, void *, void *, s32);
void kar_diag__802affd8(void *, s32, s32, void **);
void kar_diag__802b042c(void *, s32);
void kar_diag__802dd040(void *, void *, s32, void *);

s32 HSD_Randi(s32);
f32 HSD_Randf(void);

u32 HSD_JObjRemoveAnimAllByFlags(void *, s32, f32);
void HSD_JObjRemoveAnim(void *);

void PSVECAdd(Vec3f *, const Vec3f *, const Vec3f *);
void PSVECSubtract(Vec3f *, const Vec3f *, const Vec3f *);
void PSVECScale(Vec3f *, const Vec3f *, f32);
void PSVECNormalize(Vec3f *, const Vec3f *);
f32 PSVECMag(const Vec3f *);
f32 PSVECDotProduct(const Vec3f *, const Vec3f *);

void __construct_array(void *, void (*)(void *), void *, s32, s32, void *);
void __destroy_arr(void *, void *(*)(void *, s16), s32, s32);
u8 __ptmf_scall(void *);
void abort(void);

void *fn_8028E058(void *arg0, s16 arg1);
f32 fn_80296264(f32);
f32 fn_8029626C(f32);
f32 fn_802D4C30(f32);
void *fn_802D7D4C(void *arg0, s16 arg1);
void *fn_8030D510(void);
void *fn_80313A84(void *, s32, void *);
void *fn_803156FC(void *, void *, void *, s32, s32, s32, f32);
void *fn_803158A8(void *, void *);
void fn_80316128(void *, s32);
void fn_8031A74C(void *, f32, f32);
void fn_8031DEAC(void *, s32);
void fn_8031DF54(void *);
void fn_8031DFFC(void *, s32, s32, s32, s32, void *, void *, s32);
void fn_8031E558(void *);
void fn_8038CCAC(s32, s32, void *);
void fn_8038D0E8(void *, void *, s32);
void fn_803B4D80(void *, const char *);

void *kar_a2d_bg5000__near_80341f90(void);
void kar_a2d_effecthandle__8037b028(void *, s32, s32, void *, void *, s32, f32);
void kar_a2d_effecthandle__near_8037b33c(void *, u8);
void kar_a2d_effecthandle__near_8037cfb4(void);
void kar_a2d_effecthandle__near_8037dde0(void *, s32);
void kar_a2d_effecthandle__near_8037dec0(void *, s32);
void kar_a2d_game_audio__near_803792b8(s32);
void kar_a2d_game_audio__near_80379398(void *);
void kar_a2d_game_audio__near_80379784(void *, s32, void *, s32);
void kar_a2d_game_effect__near_8037afd0(void *, u8, s32, s32);
void kar_a2d_game_lib__near_802891c8(f32 *, f32 *, f32);
void kar_a2d_game_lib__near_80289590(void *, u16, f32);
void kar_a2d_game_lib__near_802895c8(void *, u16, f32, f32);
void kar_a2d_game_lib__near_8028967c(void *, u16, f32, f32);
void kar_a2d_game_lib__near_80289730(void *, u16, f32);
void kar_a2d_game_lib__near_80289768(void *, u16, f32);
u8 kar_a2d_game_lib__near_802897e0(void *);
u8 kar_a2d_game_lib__near_80289874(void *);
f32 kar_a2d_game_lib__near_80289928(void);
f32 kar_a2d_game_lib__near_802899d0(void);
s32 kar_a2d_game_lib__near_8028a66c(void *, s32, void *);
u16 kar_a2d_game_lib__near_8028ac98(u16, u16, s32, u16);
s32 kar_a2d_lavabomb__near_80321ed8(void *);
void kar_a2d_refract__near_803845f4(void *);
void kar_a2d_refract__near_80384600(void *, s16);
u64 kar_a2d_refract__near_80384670(void *, s32, void *, f32);
void kar_a2d_refract__near_803848e0(void *, s32, void *, f32);
void kar_a2d_refract__near_80384a80(void *);
void kar_a2d_refract__near_80384a98(void *);
void kar_a2d_refract__near_80384ea4(void *, u32, f32, f32);
void kar_a2d_refract__near_80384f44(void);
void kar_a2d_soundhandle__80379b1c(void *, s32, s32, f32, f32);
f64 kar_atan2(f32, f32);
u8 kar_fl_indirectload__80391f10(void *, void *);
void kar_grcoll__803d1978(s32, f32, f32, f32);
s32 kar_lbaudio_is_track_handle_playing(s32);
void kar_lbcolanim__near_8006b048(f32 *, s32, f32, f32, f32, void *, f32);
void kar_lbvector_rotate_by_euler(f32 *, f32 *, f32);
void kar_lbvector_slerp_or_copy(void *, f32 *, f32 *, f32);
void *kar_object__8038d158(void *, s32, s32, void *, s32, void *, void *, void *, f32);
f32 splGetHelmite(f32, f32, f32, f32, f32, f32);
s32 strcmp(const char *, const char *);
s32 strlen(const char *);
char *strcat(char *, const char *);

extern f32 lbl_805E4008;
extern const f32 lbl_805E4088;
extern const f32 lbl_805E408C;
extern const f32 lbl_805E4090;
extern f32 lbl_805E3F78;
extern f32 lbl_805E3F7C;
extern f32 lbl_805E3F80;
extern f32 lbl_805E3FD8;
extern f32 lbl_805E3FDC;
extern f32 lbl_805E3FE0;
extern f32 lbl_805E3FF0;
extern f32 lbl_805E4014;
extern f32 lbl_805E4018;

}

struct FObj {
    void *vtable;
    FObj *unk4;
    char pad8[0x10 - 0x8];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u16 unk18;
    u16 unk1A;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
};

struct GrindRailConfig {
    char pad0[0x150];
    HSD_JObj *unk150;
    char pad154[0x164 - 0x154];
    f32 unk164;
    f32 unk168;
    f32 unk16C;
    f32 unk170;
    f32 unk174;
    f32 unk178;
    f32 unk17C;
};

struct GrindRailSlot {
    char pad0[8];
    HSD_JObj *jobj;
    HSD_JObj *jobj2;
    char **arr10;
    char pad14[4];
    s32 idx;
    char pad1C[0xC];
    s32 state;
    u32 timer;
    char eff[0x54 - 0x30];
};

struct RailRunner {
    KartIF *kif;
    HSD_JObj *jobj;
    s32 state;
    char padC[4];
    f32 speed;
    Vec3f facing;
    Vec3f facing2;
    Vec3f pos;
    char pad38[4];
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    u32 unk50;
};

extern "C" char lbl_804E2A44[0x90];

static inline f32 grConvSpeed(f32 v) {
    return 1.0f * (fn_802D4C30(0.016666668f) * (fn_8029626C(1000.0f) * fn_80296264(v)));
}

/* forward declarations (defined later, source order fixed by spec) */
extern "C" {
void fn_803238F0(s32 *arg0);
f32 **kar_a2d_grindrail__near_80323894(f32 **arg0, s16 arg1);
void kar_a2d_grindrail__near_80323ce8(GrindRailSlot *arg0);
}

extern "C" s32 kar_a2d_grindrail__80322118(GrindRailConfig *arg0, RailRunner *arg1) {
    Vec3f v0, v1, v2, v3, v4, v5, v6;
    f32 f0, f1;
    f32 speedA, speedB, speedC, speedD, speedE;
    u8 dangerFlag;

    dangerFlag = arg1->kif->v64();
    speedA = grConvSpeed(arg0->unk168) * arg0->unk164;
    speedB = grConvSpeed(arg0->unk16C) * arg0->unk168 / (arg0->unk168 / arg0->unk168);
    (void) speedB;
    f32 v31 = (arg0->unk164 * grConvSpeed(arg0->unk168)) / grConvSpeed(1.0f);
    f32 v30 = (arg0->unk168 * grConvSpeed(arg0->unk16C)) / grConvSpeed(1.0f);
    f32 v29 = (arg0->unk16C * grConvSpeed(arg0->unk170)) / grConvSpeed(1.0f);
    f32 v27_6 = (arg0->unk170 * grConvSpeed(arg0->unk174)) / grConvSpeed(1.0f);
    f32 danger = arg0->unk17C;
    f32 baseSpeed = arg0->unk164;

    switch (arg1->state) {
    case 1:
        arg1->facing = *arg1->kif->v7c();
        arg1->pos = *arg1->kif->v74();
        arg1->speed = PSVECMag(&arg1->pos);
        arg1->state = 2;
        PSVECSubtract(&v0, (Vec3f *) ((char *) arg1->jobj + 0x38), &arg1->pos);
        f0 = PSVECMag(&v0);
        arg1->unk44 = (f0 > lbl_805E4008) ? (f0 / arg1->speed) : lbl_805E4008;
        arg1->unk50 = (u32) arg1->unk44;
        arg1->unk48 = f0;
        /* fallthrough */
    case 2: {
        f0 = arg1->speed;
        f32 target = (f0 > v31) ? ((f0 - 0.06f > v31) ? v31 : f0 - 0.06f)
                                 : ((f0 + v29 > v31) ? v31 : f0 + v29);
        arg1->speed = target;
        Vec3f jobjPos = *(Vec3f *) &arg1->jobj->translate;
        Vec3f col;
        kar_lbcolanim__near_8006b048(&col.x, arg1->jobj->aobj ? 1 : 0, 0, 0, 0, arg1->jobj, 1e-10f);
        if (PSVECMag(&col) == lbl_805E4008) {
            assert_line(0x11B, 0);
        }
        PSVECNormalize(&col, &col);
        Vec3f kifPos = *arg1->kif->v74();
        Vec3f delta;
        PSVECSubtract(&delta, &arg1->pos, &kifPos);
        f32 t = (arg1->speed + PSVECMag(&delta)) / arg1->unk48;
        f32 rate = (t > 1.0f) ? 1.0f : t;
        Vec3f posDelta;
        PSVECSubtract(&posDelta, &arg1->pos, &jobjPos);
        PSVECScale(&posDelta, &posDelta, rate);
        Vec3f newPos;
        PSVECAdd(&newPos, &jobjPos, &posDelta);
        Vec3f newFacing;
        kar_lbvector_slerp_or_copy(&arg1->facing, &col.x, &newFacing.x, rate);
        if (t == 1.0f) {
            newPos = jobjPos;
            newFacing = col;
            arg1->state = 3;
            kar_a2d_game_lib__near_80289730(arg1->jobj, 0xFFFF,
                (((t - 1.0f) * arg1->unk48) / baseSpeed) * (arg1->speed / baseSpeed) + 1.0f);
            kar_a2d_game_lib__near_80289768(arg1->jobj, 0xFFFF, arg1->speed / baseSpeed);
            HSD_JObjAnimAll(arg1->jobj);
        }
        arg1->kif->v78(newPos);
        arg1->kif->v80(newFacing);
    }
    /* fallthrough */
    case 100: {
        f32 spd = arg1->speed;
        Vec3f dir = *arg1->kif->v7c();
        PSVECScale(&dir, &dir, spd);
        arg1->kif->v88(dir);
        return 1;
    }
    case 3: {
        FObj *fo = arg1->jobj->aobj ? (FObj *) arg1->jobj->aobj : NULL;
        (void) fo;
        FObj *cur = (FObj *) ((char *) arg1->jobj->u.dobj);
        while (cur != NULL && cur->unk13 != 4) {
            cur = cur->unk4;
        }
        f1 = lbl_805E4008;
        if (cur != NULL) {
            switch ((s32) cur->unk12) {
            case 6:
                if (cur->unk10 & 0x80) {
                    f1 = cur->unk20;
                }
                break;
            case 1:
                if (cur->unk1C == (f32) cur->unk1A) {
                    f1 = cur->unk24;
                } else {
                    f1 = cur->unk20;
                }
                break;
            case 2:
                f1 = (cur->unk28 * cur->unk1C) + cur->unk20;
                break;
            default:
                if (f1 != (f32) cur->unk1A) {
                    f1 = splGetHelmite(1.0f / (f32) cur->unk1A, cur->unk1C, cur->unk20, cur->unk24, cur->unk28, 0.0f);
                } else {
                    f1 = cur->unk24;
                }
                break;
            }
        }
        arg1->unk4C = f1;
        return 0;
    }
    case 4: {
        u32 t50 = arg1->unk50;
        arg1->unk50 = t50 - 1;
        if ((f32) t50 == 1.0f) {
            HSD_JObj *j = arg0->unk150;
            f32 rate = 1.0f - ((f32) arg1->unk50 / arg1->unk44);
            Vec3f rot;
            rot.x = j->rotate.x;
            rot.y = j->rotate.y;
            rot.z = j->rotate.z;
            Vec3f cur;
            cur = arg1->facing2;
            kar_lbvector_rotate_by_euler(&cur.x, &rot.x, cur.x);
            Vec3f kdir = *arg1->kif->v7c();
            PSVECNormalize(&kdir, &kdir);
            Vec3f scaled;
            PSVECScale(&kdir, &scaled, 1.0f);
            Vec3f p1;
            PSVECAdd(&scaled, &p1, &arg1->pos);
            Vec3f p2;
            PSVECSubtract(&p1, &p2, &arg1->pos);
            PSVECScale(&p2, &p2, rate);
            Vec3f p3;
            PSVECAdd(&arg1->pos, &p3, &p2);
            arg1->kif->v78(p3);
            Vec3f newFacing;
            kar_lbvector_slerp_or_copy(&arg1->facing, &cur.x, &newFacing.x, rate);
            arg1->kif->v80(newFacing);
        } else {
            f32 spd = arg1->speed;
            Vec3f dir = *arg1->kif->v7c();
            PSVECScale(&dir, &dir, spd);
            arg1->kif->v88(dir);
            return 0;
        }
        return 1;
    }
    default:
        assert_line(0x1FD, 0);
        return 0;
    }
    return dangerFlag;
}

extern "C" char lbl_80569800[0x40];
extern "C" char lbl_804E2AE0[0x48];

extern "C" void *kar_a2d_grindrail__80322ec4(void *arg0, s32 arg1, void *arg2) {
    char *sp8 = (char *) arg0;
    FP(sp8, 0) = lbl_804E2AE0;
    __construct_array((char *) sp8 + 0x10, (void (*)(void *)) fn_803238F0, (void *) kar_a2d_grindrail__near_80323894, 4, 2, (void *) "PostDrawEffect");
    kar_a2d_refract__near_803845f4((char *) sp8 + 0x30);
    FS32(sp8, 0x24) = arg1;
    lbl_80569800[0] = 0;
    strcat(lbl_80569800, "*GRIND");
    FP(sp8, 8) = fn_8038D0A8(arg2, lbl_80569800, 0, sp8);
    if (FP(sp8, 8) == NULL) {
        assert_line(0x280, 0);
    }
    lbl_80569800[0] = 0;
    strcat(lbl_80569800, "LIGHT_");
    FP(sp8, 0xC) = fn_8038D0A8(arg2, lbl_80569800, 0, sp8);
    if (FP(sp8, 0xC) == NULL) {
        assert_line(0x285, 0);
    }
    HSD_JObjClearFlagsAll((HSD_JObj *) FP(sp8, 0xC), 0x10);
    kar_a2d_refract__near_80384670((char *) sp8 + 0x30, 5, FP(sp8, 0xC), 1.0f);
    kar_a2d_refract__near_80384a80((char *) sp8 + 0x30);
    FS32(sp8, 4) = kar_a2d_game_lib__near_8028a66c(arg2, FS32(FP(sp8, 8), 0xC), (void *) "PTCL_NULL");
    return sp8;
}

extern "C" f32 **kar_a2d_grindrail__near_80323894(f32 **arg0, s16 arg1) {
    if (arg0 != NULL) {
        if (*arg0 != NULL) {
            fn_8038CB78(*arg0);
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_803238F0(s32 *arg0) {
    *arg0 = 0;
}

extern "C" char lbl_805DA738[8];

extern "C" void kar_a2d_grindrail__803238fc(void *arg0, void *arg1) {
    KartIF *kif = (KartIF *) FP(arg1, 0x2C);
    if (kif == NULL || kif->v94() > 1.0f || kif->v28() == 0xE) {
        return;
    }
    s32 st = FS32(arg0, 0x28);
    if (st != 1 && st != 2) {
        return;
    }
    {
    char *name = (char *) FP(FP(FP(FP(arg1, 4), 4), 0xC), -4);
    if (name == NULL) {
        name = lbl_805DA738;
    }
    if (strcmp((char *) FP(arg0, 4), name) != 0) {
        return;
    }
    u8 didRoll;
    if (FS32(arg0, 0x28) == 1) {
        f32 pct;
        switch (FS32(arg0, 0x24)) {
        case 0:
            pct = FF32(kar_a2d_bg5000__near_80341f90(), 8);
            break;
        case 1:
            pct = FF32(kar_a2d_bg5000__near_80341f90(), 0xC);
            break;
        case 2:
            pct = FF32(kar_a2d_bg5000__near_80341f90(), 0x10);
            break;
        default:
            assert_line(0x2F2, 0);
            pct = 0.0f;
            break;
        }
        s32 result = ((pct * 0.01f) > HSD_Randf()) ? 0 : 1;
        if (result == FS32(arg0, 0x1C)) {
            FU32(arg0, 0x20) = FU32(arg0, 0x20) + 1;
            if (FU32(arg0, 0x20) >= 3U) {
                result = 1;
                FU32(arg0, 0x20) = 0;
            }
        }
        didRoll = 0;
        FS32(arg0, 0x1C) = FS32(arg0, 0x18);
        FS32(arg0, 0x18) = result;
    } else {
        didRoll = 1;
    }
    char *elem = *(char **) ((char *) arg0 + (FS32(arg0, 0x18) * 4) + 0x10);
    s32 idx;
    if (FS32(elem, 8) == 0) {
        idx = 0;
    } else if (FS32(elem, 0x5C) == 0) {
        idx = 1;
    } else if (FS32(elem, 0xB0) == 0) {
        idx = 2;
    } else if (FS32(elem, 0x104) == 0) {
        idx = 3;
    } else {
        idx = -1;
    }
    if (idx == -1) {
        return;
    }
    char *slot = elem + idx * 0x54;
    if (didRoll == 0) {
        HSD_JObjClearFlagsAll((HSD_JObj *) FP(elem, 0x150), 0x10);
        kar_a2d_game_lib__near_80289768(FP(elem, 0x150), 0xFFFF, 1.0f);
        kar_a2d_game_lib__near_80289590(FP(elem, 0x150), 0xFFFF, lbl_805E4008);
        HSD_JObjClearFlagsAll((HSD_JObj *) FP(elem, 0x158), 0x10);
        kar_a2d_game_lib__near_802895c8(FP(elem, 0x158), 0xFFFF, 1.0f, 30.0f);
        kar_a2d_game_lib__near_80289768(FP(elem, 0x158), 0xFFFF, 1.0f);
        kar_a2d_game_lib__near_80289590(FP(elem, 0x158), 0xFFFF, 1.0f);
        kar_a2d_game_lib__near_802895c8(FP(elem, 0x154), 0xFFFF, 17.0f, 48.0f);
        kar_a2d_game_lib__near_80289768(FP(elem, 0x154), 0xFFFF, 1.0f);
        kar_a2d_game_lib__near_80289590(FP(elem, 0x154), 0xFFFF, 17.0f);
    }
    FS32(slot, 8) = 1;
    Vec3f *kp = kif->v84();
    FF32(slot, 0x38) = kp->x;
    FF32(slot, 0x3C) = kp->y;
    FF32(slot, 0x40) = kp->z;
    FP(slot, 0) = kif;
    kif->vC4();
    kar_a2d_grindrail__near_80323ce8((GrindRailSlot *) arg0);
    }
}

extern "C" void kar_a2d_grindrail__near_80323c58(GrindRailSlot *arg0) {
    f32 t;

    arg0->state = 0;
    arg0->idx = -1;
    t = FF32(kar_a2d_bg5000__near_80341f90(), 4) * HSD_Randf();
    arg0->timer = (u32) t + 1;
    HSD_JObjSetFlagsAll(arg0->jobj, 0x10);
    kar_a2d_game_lib__near_80289768(arg0->jobj, 0xFFFF, lbl_805E4008);
    kar_a2d_refract__near_80384a80(arg0->eff);
}

extern "C" void kar_a2d_grindrail__near_80323ce8(GrindRailSlot *arg0) {
    arg0->state = 2;
    kar_a2d_refract__near_80384a98(arg0->eff);
}

extern "C" char lbl_805DDC58[0x100];

extern "C" void kar_a2d_grindrail__near_80323d14(GrindRailSlot *arg0) {
    switch (arg0->state) {
    case 0: {
        if (arg0->timer != 0) {
            arg0->timer -= 1;
            return;
        }
        s32 n = 0;
        if (FS32(lbl_805DDC58, 0x84) != 0) n = 1;
        if (FS32(lbl_805DDC58, 0xB8) != 0) n += 1;
        if (FS32(lbl_805DDC58, 0xEC) != 0) n += 1;
        if ((u32) n < (u32) FS32(kar_a2d_bg5000__near_80341f90(), 0x14)) {
            arg0->state = 1;
            arg0->idx = -1;
            HSD_JObjClearFlagsAll(arg0->jobj, 0x10);
            kar_a2d_game_lib__near_80289768(arg0->jobj, 0xFFFF, lbl_805E4088);
            kar_a2d_game_lib__near_80289590(arg0->jobj, 0xFFFF, lbl_805E4008);
            kar_a2d_game_lib__near_802895c8(arg0->jobj2, 0xFFFF, 17.0f, 48.0f);
            kar_a2d_game_lib__near_80289768(arg0->jobj2, 0xFFFF, lbl_805E4088);
            kar_a2d_game_lib__near_80289590(arg0->jobj2, 0xFFFF, 17.0f);
            u16 hi = (u16) FS32(kar_a2d_bg5000__near_80341f90(), 0x1C);
            u16 lo = (u16) FS32(kar_a2d_bg5000__near_80341f90(), 0x18);
            arg0->timer = kar_a2d_game_lib__near_8028ac98((u16) ((lo + hi) >> 1), (u16) (lo - hi), 4, lo);
            kar_a2d_refract__near_80384a98(arg0->eff);
            return;
        }
        arg0->state = 0;
        arg0->idx = -1;
        f32 t = FF32(kar_a2d_bg5000__near_80341f90(), 4) * HSD_Randf();
        arg0->timer = (u32) t + 1;
        HSD_JObjSetFlagsAll(arg0->jobj, 0x10);
        kar_a2d_game_lib__near_80289768(arg0->jobj, 0xFFFF, lbl_805E4008);
        kar_a2d_refract__near_80384a80(arg0->eff);
        return;
    }
    case 1: {
        if (arg0->timer != 0) {
            arg0->timer -= 1;
            return;
        }
        arg0->state = 0;
        arg0->idx = -1;
        f32 t = FF32(kar_a2d_bg5000__near_80341f90(), 4) * HSD_Randf();
        arg0->timer = (u32) t + 1;
        HSD_JObjSetFlagsAll(arg0->jobj, 0x10);
        kar_a2d_game_lib__near_80289768(arg0->jobj, 0xFFFF, lbl_805E4008);
        kar_a2d_refract__near_80384a80(arg0->eff);
        kar_a2d_game_lib__near_802895c8(arg0->jobj2, 0xFFFF, 49.0f, 64.0f);
        kar_a2d_game_lib__near_80289768(arg0->jobj2, 0xFFFF, lbl_805E4088);
        kar_a2d_game_lib__near_80289590(arg0->jobj2, 0xFFFF, 49.0f);
        return;
    }
    case 2: {
        char *p = (char *) arg0;
        u8 any = 0;
        u32 i;
        for (i = 0; i < 2U; i++, p += 0x54) {
            any |= (u8) kar_a2d_lavabomb__near_80321ed8(FP(p, 0x10));
        }
        if (any == 0) {
            arg0->state = 3;
            arg0->timer = 0x1E;
            HSD_JObjSetFlagsAll(arg0->jobj, 0x10);
            kar_a2d_game_lib__near_80289768(arg0->jobj, 0xFFFF, lbl_805E4008);
            kar_a2d_game_lib__near_802895c8(arg0->jobj2, 0xFFFF, 49.0f, 64.0f);
            kar_a2d_game_lib__near_80289768(arg0->jobj2, 0xFFFF, lbl_805E4088);
            kar_a2d_game_lib__near_80289590(arg0->jobj2, 0xFFFF, 49.0f);
            kar_a2d_refract__near_80384a80(arg0->eff);
        }
        return;
    }
    case 3: {
        if (arg0->timer != 0) {
            arg0->timer -= 1;
            return;
        }
        arg0->state = 4;
        arg0->timer = 0x3C;
        char *elem = *(char **) ((char *) arg0 + (arg0->idx * 4) + 0x10);
        HSD_JObjClearFlagsAll((HSD_JObj *) FP(elem, 0x158), 0x10);
        kar_a2d_game_lib__near_802895c8(FP(elem, 0x158), 0xFFFF, 31.0f, 60.0f);
        kar_a2d_game_lib__near_80289768(FP(elem, 0x158), 0xFFFF, lbl_805E4088);
        kar_a2d_game_lib__near_80289590(FP(elem, 0x158), 0xFFFF, 31.0f);
        kar_a2d_refract__near_80384a80(arg0->eff);
        return;
    }
    case 4: {
        if (arg0->timer != 0) {
            arg0->timer -= 1;
            return;
        }
        arg0->state = 5;
        arg0->timer = 0x50;
        char *elem = *(char **) ((char *) arg0 + (arg0->idx * 4) + 0x10);
        HSD_JObjSetFlagsAll((HSD_JObj *) FP(elem, 0x150), 0x10);
        kar_a2d_game_lib__near_80289768(FP(elem, 0x150), 0xFFFF, lbl_805E4008);
        kar_a2d_game_lib__near_802895c8(FP(elem, 0x154), 0xFFFF, 49.0f, 64.0f);
        kar_a2d_game_lib__near_80289768(FP(elem, 0x154), 0xFFFF, lbl_805E4088);
        kar_a2d_game_lib__near_80289590(FP(elem, 0x154), 0xFFFF, 49.0f);
        kar_a2d_refract__near_80384a80(arg0->eff);
        return;
    }
    case 5: {
        if (arg0->timer != 0) {
            arg0->timer -= 1;
            return;
        }
        arg0->state = 0;
        arg0->idx = -1;
        f32 t = FF32(kar_a2d_bg5000__near_80341f90(), 4) * HSD_Randf();
        arg0->timer = (u32) t + 1;
        HSD_JObjSetFlagsAll(arg0->jobj, 0x10);
        kar_a2d_game_lib__near_80289768(arg0->jobj, 0xFFFF, lbl_805E4008);
        kar_a2d_refract__near_80384a80(arg0->eff);
        break;
    }
    }
}

extern "C" {
void kar_a2d_grindrail__near_80324678(void *arg0, void *arg1);
void kar_a2d_grindrail__near_80324a64(void *arg0, void *arg1);
}

extern "C" char lbl_805DA768[8];
extern "C" char lbl_805DA748[8];
extern "C" char __files[0xB0];
extern "C" s32 lbl_805DDA7C;

extern "C" void kar_a2d_grindrail__near_80324258(void) {
    void *node;

    node = kar_diag__803ad760(lbl_805DDA7C, 0, lbl_805DA768, lbl_805DA748, 0);
    while (node != NULL) {
        void **vt0 = *(void ***) FP(node, 0);
        ((void (*)(void *)) vt0[18])(node);
        FU32(node, 0x50) = 0;
        void **vt14 = *(void ***) FP(node, 0x14);
        node = ((void *(*)(void *)) vt14[7])((char *) node + 0x14);
    }
    void *outer = kar_diag__803ad760(lbl_805DDA7C, 0, lbl_805DA768, lbl_805DA748, 0);
    void *filePtr = __files + 0xA0;
    while (outer != NULL) {
        Vec3f accum;
        accum.x = FF32(outer, 4);
        accum.y = FF32(outer, 8);
        accum.z = FF32(outer, 0xC);
        PSVECAdd((Vec3f *) ((char *) outer + 4), (Vec3f *) ((char *) outer + 0x2C), (Vec3f *) ((char *) outer + 4));
        if (FU8(outer, 0x24) != 0) {
            void **vt14 = *(void ***) FP(outer, 0x14);
            void *inner = ((void *(*)(void *)) vt14[7])((char *) outer + 0x14);
            while (inner != NULL) {
                if (FU8(inner, 0x24) != 0) {
                    u32 i1 = FU32(inner, 0x20);
                    if (i1 >= 5U) {
                        fn_803B4D80(filePtr, "index out of range of bitset::test");
                        abort();
                    }
                    if (FU32(outer, 0x28) & (1 << i1)) {
                        u32 i2 = FU32(outer, 0x20);
                        if (i2 >= 5U) {
                            fn_803B4D80(filePtr, "index out of range of bitset::test");
                            abort();
                        }
                        if (FU32(inner, 0x28) & (1 << i2)) {
                            kar_a2d_grindrail__near_80324678(outer, inner);
                        }
                    }
                }
                void **ivt14 = *(void ***) FP(inner, 0x14);
                inner = ((void *(*)(void *)) ivt14[7])((char *) inner + 0x14);
            }
            kar_a2d_grindrail__near_80324a64(outer, &accum.x);
        }
        void **ovt14 = *(void ***) FP(outer, 0x14);
        outer = ((void *(*)(void *)) ovt14[7])((char *) outer + 0x14);
    }
}

extern "C" char lbl_804F51DC[0x38];
extern "C" char lbl_804BDBC0[0x38];
extern "C" char lbl_804BDBE8[0x54];
extern "C" char lbl_804BDB74[0x28];

extern "C" void *kar_a2d_grindrail__near_80324440(void *arg0, void *arg1) {
    FP(arg0, 0) = lbl_804F51DC;
    FP(arg0, 0) = lbl_804BDB74;
    FF32(arg0, 4) = 0.0f;
    FF32(arg0, 8) = 0.0f;
    FF32(arg0, 0xC) = 0.0f;
    FF32(arg0, 0x10) = 0.0f;
    FP(arg0, 0x14) = lbl_804BDBC0;
    FS32(arg0, 0x18) = 0;
    FS32(arg0, 0x1C) = 0;
    void **vt14 = *(void ***) lbl_804BDBC0;
    ((void (*)(void *, void *)) vt14[2])((char *) arg0 + 0x14, lbl_804BDBC0);
    FP(arg0, 0) = lbl_804BDBE8;
    FP(arg0, 0x14) = lbl_804BDBE8 + 0x28;
    FP(arg0, 0x20) = arg1;
    FS32(arg0, 0x24) = 1;
    FS32(arg0, 0x28) = 0;
    FF32(arg0, 0x2C) = 0.0f;
    FF32(arg0, 0x30) = 0.0f;
    FF32(arg0, 0x34) = 0.0f;
    FF32(arg0, 0x38) = 0.5f;
    FF32(arg0, 0x3C) = 0.5f;
    FF32(arg0, 0x40) = 0.0f;
    FF32(arg0, 0x44) = 0.0f;
    FF32(arg0, 0x48) = 0.0f;
    FS32(arg0, 0x4C) = 0;
    FS32(arg0, 0x50) = 0;
    if (arg1 == (void *) 1U) {
        FS32(arg0, 0x28) |= 1;
        FS32(arg0, 0x28) |= 0x10;
    } else if (arg1 != (void *) 2U) {
        FS32(arg0, 0x28) |= 2;
    }
    return arg0;
}

extern "C" void *kar_a2d_grindrail__near_80324560(void *arg0, void *arg1) {
    FP(arg0, 0) = lbl_804F51DC;
    FP(arg0, 0) = lbl_804BDB74;
    FF32(arg0, 4) = FF32(arg1, 4);
    FF32(arg0, 8) = FF32(arg1, 8);
    f32 t10 = FF32(arg1, 0x10);
    FF32(arg0, 0xC) = FF32(arg1, 0xC);
    FF32(arg0, 0x10) = t10;
    FP(arg0, 0x14) = lbl_804BDBC0;
    FS32(arg0, 0x18) = 0;
    FS32(arg0, 0x1C) = 0;
    void **vt14 = *(void ***) lbl_804BDBC0;
    ((void (*)(void *, void *, void *, f32)) vt14[2])((char *) arg0 + 0x14, lbl_804BDBC0, lbl_804F51DC, t10);
    FP(arg0, 0) = lbl_804BDBE8;
    FP(arg0, 0x14) = lbl_804BDBE8 + 0x28;
    FS32(arg0, 0x20) = FS32(arg1, 0x20);
    FU8(arg0, 0x24) = FU8(arg1, 0x24);
    FS32(arg0, 0x28) = FS32(arg1, 0x28);
    FF32(arg0, 0x2C) = FF32(arg1, 0x2C);
    FF32(arg0, 0x30) = FF32(arg1, 0x30);
    FF32(arg0, 0x34) = FF32(arg1, 0x34);
    FF32(arg0, 0x38) = FF32(arg1, 0x38);
    FF32(arg0, 0x3C) = FF32(arg1, 0x3C);
    FF32(arg0, 0x40) = FF32(arg1, 0x40);
    FF32(arg0, 0x44) = FF32(arg1, 0x44);
    FF32(arg0, 0x48) = FF32(arg1, 0x48);
    FU8(arg0, 0x4C) = FU8(arg1, 0x4C);
    FS32(arg0, 0x50) = FS32(arg1, 0x50);
    return arg0;
}

extern "C" void kar_a2d_grindrail__near_80324678(void *arg0, void *arg1) {
    Vec3f delta, tmp, mid, dir;
    f32 dist;

    PSVECSubtract(&delta, (Vec3f *) ((char *) arg1 + 4), (Vec3f *) ((char *) arg0 + 4));
    dist = PSVECMag(&delta);
    if (dist < FF32(arg0, 0x10) + FF32(arg1, 0x10)) {
        PSVECSubtract(&dir, (Vec3f *) ((char *) arg0 + 4), (Vec3f *) ((char *) arg1 + 4));
        if (PSVECMag(&dir) != 0.0f) {
            f32 sum = FF32(arg0, 0x10) + FF32(arg1, 0x10);
            PSVECNormalize(&dir, &dir);
            PSVECScale(&tmp, &dir, sum - dist);
            PSVECScale(&tmp, &tmp, 0.5f);
            PSVECSubtract((Vec3f *) ((char *) arg0 + 4), (Vec3f *) ((char *) arg0 + 4), &tmp);
            PSVECScale(&tmp, &dir, sum - dist);
            PSVECScale(&tmp, &tmp, 0.5f);
            PSVECAdd((Vec3f *) ((char *) arg1 + 4), (Vec3f *) ((char *) arg1 + 4), &tmp);
            f32 dp = PSVECDotProduct((Vec3f *) ((char *) arg1 + 0x2C), &dir);
            (void) mid;
            if (dp < 0.0f) {
                f32 inv = 1.0f / PSVECMag(&dir);
                Vec3f n;
                PSVECScale(&n, &dir, inv);
                PSVECScale(&n, &n, 2.0f);
                PSVECScale(&n, &n, dp);
                PSVECAdd((Vec3f *) ((char *) arg0 + 0x2C), (Vec3f *) ((char *) arg0 + 0x2C), &n);
                Vec3f n2;
                PSVECScale(&n2, &dir, inv);
                PSVECScale(&n2, &n2, 2.0f);
                PSVECScale(&n2, &n2, dp);
                PSVECSubtract((Vec3f *) ((char *) arg1 + 0x2C), (Vec3f *) ((char *) arg1 + 0x2C), &n2);
            }
        }
        FP(arg0, 0x50) = arg1;
        FP(arg1, 0x50) = arg0;
        void **vt0a = *(void ***) FP(arg0, 0);
        ((void (*)(void *, void *)) vt0a[22])(arg0, arg1);
        void **vt0b = *(void ***) FP(arg1, 0);
        ((void (*)(void *, void *)) vt0b[22])(arg1, arg0);
    }
}

extern "C" void kar_a2d_grindrail__near_80324a64(void *arg0, void *arg1) {
    /* rail waypoint smoothing / collision-response search over up to 3 candidates */
    void *best = NULL;
    void *prev = NULL;
    u32 count = 0;
    Vec3f cur;
    cur.x = FF32(arg1, 0);
    cur.y = FF32(arg1, 4);
    cur.z = FF32(arg1, 8);

    do {
        void *cand = fn_8038CB28(0x44);
        if (cand != NULL) {
            u32 kind = FU32(arg0, 0x20);
            s32 wantVel = (kind != 1 && kind != 3) ? 1 : 0;
            void **vt0 = *(void ***) FP(arg0, 0);
            cand = fn_803156FC(cand, &cur.x, (f32 *) ((char *) arg0 + 4), kind == 2, ((s32 (*)(void *)) vt0[23])(arg0), wantVel, FF32(arg0, 0x10));
        }
        if (best != NULL) {
            if (FU32(best, 8) != 0) {
                fn_8038CB78(NULL);
            }
            char *arr = (char *) FP(best, 0xC);
            if (arr != NULL) {
                __destroy_arr(arr, (void *(*)(void *, s16)) fn_802D7D4C, 0x70, 3);
                fn_8038CB78(arr);
            }
            fn_8038CB78(best);
        }
        best = cand;
        count++;
    } while (count < 3);

    if (count != 0) {
        if (count == 3U) {
            FF32(arg0, 4) = FF32(arg1, 0);
            FF32(arg0, 8) = FF32(arg1, 4);
            FF32(arg0, 0xC) = FF32(arg1, 8);
            FF32(arg0, 0x2C) = 0.0f;
            FF32(arg0, 0x30) = 0.0f;
            FF32(arg0, 0x34) = 0.0f;
        } else if (prev != NULL) {
            /* fallback: leave position as computed by search */
        }
        void **vt0 = *(void ***) FP(arg0, 0);
        ((void (*)(void *, void *)) vt0[21])(arg0, prev);
    }
    if (prev != NULL) {
        if (FU32(prev, 8) != 0) {
            fn_8038CB78(NULL);
        }
        char *arr = (char *) FP(prev, 0xC);
        if (arr != NULL) {
            __destroy_arr(arr, (void *(*)(void *, s16)) fn_802D7D4C, 0x70, 3);
            fn_8038CB78(arr);
        }
        fn_8038CB78(prev);
    }
    if (best != NULL) {
        if (FU32(best, 8) != 0) {
            fn_8038CB78(NULL);
        }
        char *arr = (char *) FP(best, 0xC);
        if (arr != NULL) {
            __destroy_arr(arr, (void *(*)(void *, s16)) fn_802D7D4C, 0x70, 3);
            fn_8038CB78(arr);
        }
        fn_8038CB78(best);
    }
}

extern "C" {
void kar_a2d_grindrail__near_803251cc(void *arg0);
}

extern "C" const f32 lbl_805E4088;
extern "C" const f32 lbl_805E408C;
extern "C" const f32 lbl_805E4090;

extern "C" char lbl_804E0898[0x28];
extern "C" char lbl_804E2BE8[0x10];
extern "C" void *lbl_805DDBCC;

extern "C" void *kar_a2d_grindrail__near_80325160(void *arg0, void *arg1) {
    FP(arg0, 0) = lbl_804E0898;
    lbl_805DDBCC = arg0;
    FP(arg0, 0) = lbl_804E2BE8;
    FP(arg0, 4) = fn_8038D0A8(arg1, "*CHECKLINE_EF*", 0, arg0);
    kar_a2d_grindrail__near_803251cc(arg0);
    return arg0;
}

extern "C" void kar_a2d_grindrail__near_803251cc(void *arg0) {
    if (FP(arg0, 4) != NULL) {
        kar_a2d_game_lib__near_802895c8(FP(arg0, 4), 0xFFFF, lbl_805E4088, lbl_805E408C);
        kar_a2d_game_lib__near_80289768(FP(arg0, 4), 0xFFFF, lbl_805E4090);
        HSD_JObjSetFlagsAll((HSD_JObj *) FP(arg0, 4), 0x10);
    }
    FS32(arg0, 8) = 0;
    FU8(arg0, 0xC) = 0;
    FU8(arg0, 0xD) = 0;
}

extern "C" void fn_80325244(void *arg0) {
    FU8(arg0, 0xD) = 1;
}

extern "C" void kar_a2d_grindrail__near_80325250(void *arg0) {
    if (FP(arg0, 4) != NULL) {
        if (FU8(arg0, 0xD) != 0) {
            HSD_JObjClearFlagsAll((HSD_JObj *) FP(arg0, 4), 0x10);
            kar_a2d_game_lib__near_80289590(FP(arg0, 4), 0xFFFF, lbl_805E4088);
            kar_a2d_game_lib__near_80289768(FP(arg0, 4), 0xFFFF, lbl_805E4088);
            FU8(arg0, 0xD) = 0;
            FU8(arg0, 0xC) = 1;
        }
        if (FU8(arg0, 0xC) != 0 &&
            (kar_a2d_game_lib__near_802897e0(FP(arg0, 4)) != 0 || kar_a2d_game_lib__near_80289874(FP(arg0, 4)) != 0)) {
            FU8(arg0, 0xC) = 0;
            if (FP(arg0, 4) != NULL) {
                kar_a2d_game_lib__near_802895c8(FP(arg0, 4), 0xFFFF, lbl_805E4088, lbl_805E408C);
                kar_a2d_game_lib__near_80289768(FP(arg0, 4), 0xFFFF, lbl_805E4090);
                HSD_JObjSetFlagsAll((HSD_JObj *) FP(arg0, 4), 0x10);
            }
            FS32(arg0, 8) = 0;
            FU8(arg0, 0xC) = 0;
            FU8(arg0, 0xD) = 0;
        }
    }
}

extern "C" char lbl_804E2DC0[4];
extern "C" char lbl_804E2D6C[4];
extern "C" s32 lbl_805DDBC0;
extern "C" char lbl_805DA7D0[8];
extern "C" char lbl_805DA7C8[8];

extern "C" void *kar_a2d_grindrail__near_80325354(void) {
    void *r = lbl_804E2DC0;
    if (FU32(kar_diag__803ad760(lbl_805DDBC0, 0, lbl_805DA7D0, lbl_805DA7C8, 0), 0x14) == 1U) {
        r = lbl_804E2D6C;
    }
    return r;
}

extern "C" void *kar_a2d_grindrail__near_803253a4(u32 arg0) {
    if (arg0 == 0U) {
        return lbl_804E2D6C;
    }
    return lbl_804E2DC0;
}

extern "C" char lbl_804E2BF8[0x1c];

extern "C" void kar_a2d_grindrail__near_803253c0(void *arg0) {
    /* debug printout of a tuning-constant struct; field-name string pool not recovered */
    s32 i;
    for (i = 0; i <= 0x50; i += 4) {
        OSReport("    ");
        OSReport("/// %s\n", lbl_804E2BF8);
        OSReport("    ");
        OSReport("%ff,\n", FF32(arg0, i));
    }
    OSReport("};\n");
}

extern "C" {
void *kar_a2d_grindrail__near_80328a44(void *arg0, void *arg1);
void *kar_a2d_grindrail__near_80327664(void *arg0, void *arg1, void *arg2);
}

extern "C" char lbl_804BCE14[8];
extern "C" char lbl_804E35F8[0x30];
extern "C" char lbl_804E2BF8[0x1c];
extern "C" s32 lbl_805DDBC8;
extern "C" char lbl_805DA7B0[8];
extern "C" char lbl_805DA7A8[8];
extern "C" s32 lbl_805DDBC0;
extern "C" char lbl_805DA7D0[8];
extern "C" char lbl_805DA7C8[8];
extern "C" void *lbl_805DDC30;

extern "C" void *kar_a2d_grindrail__near_80325918(void *arg0, s32 arg_sp0) {
    void *sp14, *sp10;

    FP(arg0, 0) = lbl_804BCE14;
    FP(arg0, 0) = lbl_804E35F8;
    FS32(arg0, 4) = 0;
    FS32(arg0, 8) = 0;
    FS32(arg0, 0xC) = 0;
    kar_a2d_grindrail__near_80328a44((char *) arg0 + 0x10, lbl_804E2BF8);
    FS32(arg0, 0x28) = 0;
    s32 t27 = FS32(kar_diag__803ad760(lbl_805DDBC8, 0, lbl_805DA7B0, lbl_805DA7A8, 0), 0x18);
    void *b28 = lbl_804E2BF8 + 0x1C8;
    if (FU32(kar_diag__803ad760(lbl_805DDBC0, 0, lbl_805DA7D0, lbl_805DA7C8, 0), 0x14) == 1U) {
        b28 = lbl_804E2BF8 + 0x174;
    }
    void *b29 = lbl_804E2BF8 + 0x1C8;
    if (FU32(kar_diag__803ad760(lbl_805DDBC0, 0, lbl_805DA7D0, lbl_805DA7C8, 0), 0x14) == 1U) {
        b29 = lbl_804E2BF8 + 0x174;
    }
    void **vt0 = *(void ***) FP(arg0, 0);
    s32 t4 = ((s32 (*)(void *)) vt0[6])(arg0);
    fn_8031DFFC((char *) arg0 + 0x2C, t4, t27, 8, 8, (char *) b28 + 0x4C, (char *) b29 + 0x50, 0);
    kar_diag__802b042c((char *) arg0 + 4, 2);
    void *n1 = fn_8038CB28(0xB8);
    if (n1 != NULL) {
        n1 = kar_a2d_grindrail__near_80327664(n1, fn_803158A8(arg0, lbl_804E2BF8 + 0x488), lbl_804E2BF8 + 0x494);
    }
    sp14 = n1;
    kar_diag__802affd8((char *) arg0 + 4, FS32(arg0, 0xC) + (FS32(arg0, 8) * 4), 1, &sp14);
    void *n2 = fn_8038CB28(0xB8);
    if (n2 != NULL) {
        n2 = kar_a2d_grindrail__near_80327664(n2, fn_803158A8(arg0, lbl_804E2BF8 + 0x4A4), lbl_804E2BF8 + 0x4B0);
    }
    sp10 = n2;
    kar_diag__802affd8((char *) arg0 + 4, FS32(arg0, 0xC) + (FS32(arg0, 8) * 4), 1, &sp10);
    FS32(arg0, 0x24) = FS32(fn_803158A8(arg0, lbl_804E2BF8 + 0x4C0), 8);
    void **vt0b = *(void ***) FP(arg0, 0);
    ((void (*)(void *)) vt0b[11])(arg0);
    lbl_805DDC30 = arg0;
    return arg0;
}

extern "C" {
void kar_a2d_grindrail__near_80328894(void *, void *, void *, void *, void *);
}

extern "C" void *kar_a2d_grindrail__near_80325b20(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        void *sp10 = (char *) arg0 + 0xC;
        void *spC = FP(arg0, 0x10);
        void *sp8;
        kar_a2d_grindrail__near_80328894(&sp8, arg0, &spC, &sp10, sp10);
        if (FS32(arg0, 8) != 0) {
            fn_8038CB78(NULL);
        }
        if (FP(arg0, 0) != NULL) {
            fn_8038CB78(NULL);
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

class GrElem;
typedef void (GrElem::*GrElemFn)();
extern "C" GrElemFn const lbl_804E30C4;

extern "C" void kar_a2d_grindrail__near_80325c00(void *arg0) {
    fn_8031DF54((char *) arg0 + 0x2C);
    GrElemFn pmf = lbl_804E30C4;
    char *p = (char *) FP(arg0, 0xC);
    char *end = p + FS32(arg0, 8) * 0x10;
    while (p != end) {
        GrElem *obj = *(GrElem **) p;
        (obj->*pmf)();
        p += 0x10;
    }
    void *t7 = (char *) arg0 + 0x1C;
    void *spC = FP(arg0, 0x20);
    void *sp8;
    kar_a2d_grindrail__near_80328894(&sp8, (char *) arg0 + 0x10, &spC, &t7, t7);
}

extern "C" void kar_a2d_grindrail__near_80325cbc(void *arg0) {
    /* rail-segment per-frame update: waypoint search, damage bitset scan,
       refract-effect drive; complex physics function, best-effort shape only */
    char *p = (char *) FP(arg0, 0xC);
    char *end = p + FS32(arg0, 8) * 4;
    while (p != end) {
        __ptmf_scall(*(void **) p);
        p += 4;
    }
    void *node = FP(arg0, 0x20);
    void *nodeEnd = (char *) arg0 + 0x1C;
    while (node != nodeEnd) {
        if (FU8(node, 0x6C) == 0) {
            if (FS32(node, 0x198) != 0) {
                FU32(node, 0x198) = FU32(node, 0x198) - 1;
            }
        } else {
            FU32(node, 0x198) = FU32(node, 0x198);
        }
        node = FP(node, 4);
    }
}

extern "C" s32 fn_80326844(void *arg0) {
    return FS32(arg0, 0x60) == 0;
}

extern "C" GrElemFn const lbl_804E3144;
extern "C" GrElemFn const lbl_804E3150;

extern "C" void kar_a2d_grindrail__near_80326854(void *arg0) {
    GrElemFn pmf1 = lbl_804E3144;
    char *p = (char *) FP(arg0, 0xC);
    char *end = p + FS32(arg0, 8) * 0x10;
    while (p != end) {
        GrElem *obj = *(GrElem **) p;
        (obj->*pmf1)();
        p += 0x10;
    }
    GrElemFn pmf2 = lbl_804E3150;
    void *node = FP(arg0, 0x20);
    void *nodeEnd = (char *) arg0 + 0x1C;
    while (node != nodeEnd) {
        GrElem *obj = (GrElem *) ((char *) node + 8);
        (obj->*pmf2)();
        node = FP(node, 4);
    }
}

extern "C" void kar_a2d_grindrail__near_8032693c(void *arg0) {
    ((LBEffectorIF *) ((char *) arg0 + 0x54))->v10();
}

extern "C" void kar_a2d_grindrail__near_80326968(void **arg0) {
    void *p = *arg0;
    ((LBEffectorIF *) p)->v10();
}

extern "C" {
void kar_a2d_grindrail__near_80327df0(void *arg0, void *arg1);
}

extern "C" void kar_a2d_grindrail__near_80326998(void *arg0, void *arg1) {
    u32 i;
    for (i = 0; i < (u32) FS32(arg0, 8); i++) {
        kar_a2d_grindrail__near_80327df0(*(void **) ((char *) FP(arg0, 0xC) + i * 4), arg1);
    }
}

extern "C" void kar_a2d_grindrail__near_80326a0c(void *arg0) {
    HSD_JObj *jobj = (HSD_JObj *) FP(arg0, 0);
    Vec sc = { 0.0f, 0.0f, 0.0f };
    if (jobj == NULL) {
        __assert("jobj.h", 0x316, "jobj");
    }
    if (&sc == NULL) {
        __assert("jobj.h", 0x317, "scale");
    }
    jobj->scale = sc;
    HSD_JObjSetMtxDirty(jobj);
    FS32(arg0, 4) = 0;
}

extern "C" void kar_a2d_grindrail__near_80326b00(void *arg0) {
    void *cfg = kar_a2d_grindrail__near_80325354();
    f32 t = 0.2f * (5.0f * ((f32) FS32(arg0, 4) / FF32(cfg, 4)));
    HSD_JObj *jobj = (HSD_JObj *) FP(arg0, 0);
    Vec sc = { t, t, t };
    if (jobj == NULL) {
        __assert("jobj.h", 0x316, "jobj");
    }
    if (&sc == NULL) {
        __assert("jobj.h", 0x317, "scale");
    }
    jobj->scale = sc;
    HSD_JObjSetMtxDirty(jobj);
    if (FS32(arg0, 4) != 0) {
        void *cfg2 = kar_a2d_grindrail__near_80325354();
        if ((f32) FS32(arg0, 4) < FF32(cfg2, 4)) {
            FS32(arg0, 4) = FS32(arg0, 4) + 1;
        }
    }
}

extern "C" void *kar_a2d_grindrail__near_80326cc4(void *arg0, s32 arg1, f32 *arg2) {
    /* rock-hazard slot constructor: jobj hookup + refract/audio init; best-effort shape */
    HSD_JObjClearFlagsAll((HSD_JObj *) FP(arg0, 0x54), 0x10);
    kar_a2d_effecthandle__near_8037dde0((char *) arg0 + 0x12C, 0);
    kar_a2d_game_audio__near_80379398((char *) arg0 + 0x140);
    FF32(arg0, 0x184) = 0.0f;
    FF32(arg0, 0x180) = 0.0f;
    FF32(arg0, 0x17C) = 0.0f;
    kar_a2d_refract__near_803845f4((char *) arg0 + 0x188);
    FS32(arg0, 0x18C) = 0;
    FS32(arg0, 0x190) = 0;
    FF32(arg0, 0x194) = 0.0f;
    FF32(arg0, 0x198) = 0.0f;
    FF32(arg0, 0x19C) = 0.0f;
    FF32(arg0, 0x2C) = arg2 ? arg2[0] : 0.0f;
    FF32(arg0, 0x30) = 0.0f;
    FF32(arg0, 0x34) = arg2 ? arg2[2] : 0.0f;
    return arg0;
}

extern "C" void *kar_a2d_grindrail__near_803272c0(void *arg0, void *arg1) {
    /* rock-hazard slot constructor continuation; best-effort shape */
    HSD_JObjClearFlagsAll((HSD_JObj *) FP(arg0, 0x98), 0x10);
    FS32(arg0, 0x9C) = 0;
    FS32(arg0, 0xA0) = 0;
    return arg0;
}

extern "C" void kar_a2d_grindrail__near_80327600(void *arg0, void *arg1) {
    if (FU8(arg0, 0x65) == 0) {
        FU8(arg0, 0x65) = 1;
        FF32(arg0, 0x17C) = FF32(arg1, 0x10);
        FF32(arg0, 0x180) = FF32(arg1, 0x14);
        FF32(arg0, 0x184) = FF32(arg1, 0x18);
        s32 base = 0x80000;
        kar_a2d_game_audio__near_80379784((char *) arg0 + 0x140, base + 3, (char *) arg0 + 0x17C, base);
    }
}

extern "C" void fn_80327660(void) {
}

extern "C" void *kar_a2d_grindrail__near_80327664(void *arg0, void *arg1, void *arg2) {
    /* rock-hazard slot heavy init; best-effort shape only */
    return arg0;
}

extern "C" char lbl_804E3190[0xC];
extern "C" {
void kar_a2d_grindrail__near_80327ae8(void *arg0);
}

extern "C" void kar_a2d_grindrail__near_80327a2c(void *arg0) {
    FS32(arg0, 0x14) = 0;
    FS32(arg0, 0x18) = 0;
    FS32(arg0, 0x1C) = 0;
    FF32(arg0, 0x20) = (0.4f * HSD_Randf()) + 0.8f;
    GrElemFn pmf = *(GrElemFn *) lbl_804E3190;
    char *p = (char *) FP(arg0, 0xC);
    char *end = p + FS32(arg0, 8) * 0x10;
    while (p != end) {
        GrElem *obj = *(GrElem **) p;
        (obj->*pmf)();
        p += 0x10;
    }
    kar_a2d_grindrail__near_80327ae8(arg0);
}

extern "C" char lbl_804E2BF8b_5A4[0x10];

extern "C" void kar_a2d_grindrail__near_80327ae8(void *arg0) {
    if (kar_fl_indirectload__80391f10(FP(arg0, 0x10), lbl_804E2BF8b_5A4) != 0) {
        fn_8038D0E8(FP(arg0, 0), lbl_804E2BF8b_5A4, 1);
    } else {
        fn_8038D0E8(FP(arg0, 0), lbl_804E2BF8b_5A4, 1);
    }
    HSD_ForeachAnim(FP(FP(arg0, 0), 4), LOBJ_TYPE, ALL_TYPE_MASK, (void *) HSD_AObjSetRate, AOBJ_ARG_AF, FF32(arg0, 0x20));
    HSD_ForeachAnim(FP(FP(arg0, 0), 4), LOBJ_TYPE, ALL_TYPE_MASK, (void *) HSD_AObjSetCurrentFrame, AOBJ_ARG_AF, 0.0f);
}

extern "C" void kar_a2d_grindrail__near_80327bb0(void *arg0) {
    /* rail-hazard per-frame collision/audio drive; best-effort shape only */
    (void) arg0;
}

extern "C" void kar_a2d_grindrail__near_80327df0(void *arg0, void *arg1) {
    /* rail-hazard per-frame update dispatch; best-effort shape only */
    (void) arg0;
    (void) arg1;
}

extern "C" void *kar_a2d_grindrail__near_80328290(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void *kar_a2d_grindrail__near_80328504(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void kar_a2d_grindrail__near_8032876c(void *arg0) {
    fn_8031E558((char *) arg0 + 0x2C);
}

extern "C" void kar_a2d_grindrail__near_80328790(void *arg0, s32 *arg1, s32 arg_sp0, s32 arg3) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
    (void) arg3;
}

extern "C" {
void kar_a2d_grindrail__near_80328c7c(void *arg0, void *arg1);
}
extern "C" void *lbl_805DD954;

extern "C" void kar_a2d_grindrail__near_80328894(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4_unused) {
    void *e5 = FP(arg2, 0);
    void *e3 = FP(arg3, 0);
    if (e5 == e3) {
        FP(arg0, 0) = e3;
        return;
    }
    void *e4 = FP(e3, 0);
    FP(e5, 4) = FP(e4, 4);
    FP(FP(e4, 4), 0) = e5;
    for (;;) {
        void *cur = FP(arg2, 0);
        void *end2 = FP(arg3, 0);
        if (cur == end2) {
            break;
        }
        void **vt8 = *(void ***) FP(cur, 8);
        ((void (*)(void *, s32)) vt8[7])((char *) cur + 8, -1);
        void *next = FP(cur, 4);
        FP(arg2, 0) = next;
        kar_a2d_grindrail__near_80328c7c(lbl_805DD954, cur);
        FS32(arg1, 4) = FS32(arg1, 4) - 1;
    }
    FP(arg0, 0) = FP(arg3, 0);
}

extern "C" {
s32 *kar_a2d_grindrail__near_80328c54(void *arg0);
void kar_a2d_grindrail__near_80328a14(void *arg1, void *arg2, void *arg3, void *arg4);
}

extern "C" void kar_a2d_grindrail__near_80328960(void *arg0, void *arg1, void *arg2, void *arg3) {
    void *n = kar_a2d_grindrail__near_80328c54(lbl_805DD954);
    kar_a2d_grindrail__near_80328a14((char *) arg1 + 8, (char *) n + 8, arg3, n);
    void *head = *(void **) arg2;
    FP(head, 4) = n;
    FS32(n, 0) = (s32) head;
    *(void **) arg2 = n;
    FP(n, 4) = head;
    FS32(arg1, 4) = FS32(arg1, 4) + 1;
    *(void **) arg0 = n;
}

extern "C" void kar_a2d_grindrail__near_80328a14(void *arg1, void *arg2, void *arg3_unused, void *arg4_unused) {
    if (arg1 != NULL) {
        kar_a2d_grindrail__near_803272c0(arg1, arg2);
    }
}

extern "C" {
void *kar_a2d_grindrail__near_80328b10(void);
}

extern "C" void *kar_a2d_grindrail__near_80328a44(void *arg0, void *arg1_unused) {
    void *p1, *p2, *p3, *p4;

    FS32(arg0, 0) = 0;
    FS32(arg0, 4) = 0;
    p1 = NULL;
    void *n = fn_8038CB28(0x3508);
    if (n != NULL) {
        n = kar_a2d_grindrail__near_80328b10();
    }
    p2 = n;
    p2 = NULL;
    p4 = n;
    p3 = n;
    if (p1 != n) {
        if (p1 != NULL) {
            lbl_805DD954 = NULL;
            fn_8038CB78(NULL);
        }
        p1 = p3;
    }
    if (p2 != NULL) {
        lbl_805DD954 = NULL;
        fn_8038CB78(NULL);
    }
    void *r = p1;
    p1 = NULL;
    FP(arg0, 8) = r;
    void *tail = (char *) arg0 + 0xC;
    FP(tail, 4) = tail;
    FP(arg0, 0xC) = tail;
    return arg0;
}

extern "C" void *kar_a2d_grindrail__near_80328b10(void) {
    static char pool[0x3508];
    s32 i;
    for (i = 0; i < 0x1F; i++) {
        FS32(pool + i * 0x1A8, 0) = i + 1;
    }
    FS32(pool + 0x1F * 0x1A8, 0) = -1;
    FS32(pool, 0x3504) = 0x20;
    return pool;
}

extern "C" s32 *kar_a2d_grindrail__near_80328c54(void *arg0) {
    s32 *elem = (s32 *) ((char *) arg0 + FS32(arg0, 0x3500) * 0x1A8);
    FS32(arg0, 0x3500) = *elem;
    FS32(arg0, 0x3504) = FS32(arg0, 0x3504) - 1;
    return elem;
}

extern "C" void kar_a2d_grindrail__near_80328c7c(void *arg0, void *arg1) {
    s32 off = (s32) ((char *) arg1 - (char *) arg0);
    FS32(arg1, 0) = FS32(arg0, 0x3500);
    u32 idx = (u32) off / 0x1A8;
    FS32(arg0, 0x3500) = (s32) idx;
    FS32(arg0, 0x3504) = FS32(arg0, 0x3504) + 1;
}

extern "C" void fn_80328CB8(void *arg0) {
    kar_a2d_grindrail__near_80328290((char *) arg0 - 0x14, 0);
}

extern "C" char lbl_804E3B54[0x2F * 4];
extern "C" char lbl_804E3A98[0x2F * 4];
extern "C" char lbl_805DA9A8[8];
extern "C" char lbl_805DA9A0[8];

extern "C" f32 *kar_a2d_grindrail__near_80328cc0(void) {
    f32 *r = (f32 *) lbl_804E3B54;
    if (FU32(kar_diag__803ad760(lbl_805DDBC0, 0, lbl_805DA9A8, lbl_805DA9A0, 0), 0x14) == 1U) {
        r = (f32 *) lbl_804E3A98;
    }
    return r;
}

extern "C" f32 *kar_a2d_grindrail__near_80328d10(u32 arg0) {
    if (arg0 == 0U) {
        return (f32 *) lbl_804E3A98;
    }
    return (f32 *) lbl_804E3B54;
}

extern "C" void kar_a2d_grindrail__near_80328d2c(void *arg0) {
    /* main per-frame grindrail update dispatcher; best-effort shape only */
    (void) arg0;
}

extern "C" void *kar_a2d_grindrail__near_8032989c(void *arg0, s32 arg_sp0) {
    /* rail-runner constructor; best-effort shape only */
    (void) arg_sp0;
    return arg0;
}

extern "C" void *kar_a2d_grindrail__near_8032a2e4(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void kar_a2d_grindrail__near_8032a36c(void *arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" void kar_a2d_grindrail__near_8032a44c(void *arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" const f32 lbl_805E4120;

extern "C" void fn_8032A590(void *arg0) {
    FS32(arg0, 0x68) = 0;
    FS32(arg0, 0x70) = 0;
    FF32(arg0, 0x74) = lbl_805E4120;
    FU8(arg0, 0x6C) = 0;
    FU8(arg0, 0x6D) = 0;
    FU8(arg0, 0x6E) = 0;
}

extern "C" void kar_a2d_grindrail__near_8032a5b4(void *arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" s32 fn_8032A754(void *arg0) {
    return FS32(arg0, 0x60) == 0;
}

extern "C" void kar_a2d_grindrail__near_8032a764(void *arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" void kar_a2d_grindrail__near_8032a860(void *arg0) {
    ((LBEffectorIF *) ((char *) arg0 + 0x54))->v10();
}

extern "C" void kar_a2d_grindrail__near_8032a88c(void *arg0) {
    ((LBEffectorIF *) arg0)->v10();
}

extern "C" void kar_a2d_grindrail__near_8032a8b8(void *arg0, void *arg1) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
}

extern "C" {
void kar_a2d_grindrail__near_80332300(void *arg0, void *arg1);
}
namespace {
extern "C" void kar_a2d_grindrail__near_80332300(void *arg0);
}

extern "C" void kar_a2d_grindrail__near_8032a998(void *arg0) {
    kar_a2d_grindrail__near_80332300(FP(arg0, 0x20));
}

extern "C" void *kar_a2d_grindrail__near_8032a9bc(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    /* best-effort shape only */
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    return arg0;
}

extern "C" void kar_a2d_grindrail__near_8032aaf0(void *arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" void kar_a2d_grindrail__near_8032b834(void *arg0, void *arg1) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
}

extern "C" void *kar_a2d_grindrail__near_8032b894(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    /* best-effort shape only */
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    return arg0;
}

extern "C" void kar_a2d_grindrail__near_8032ba00(void *arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" void *kar_a2d_grindrail__near_8032c4a4(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5, s32 arg_sp0) {
    /* best-effort shape only */
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg5;
    (void) arg_sp0;
    return arg0;
}

extern "C" void kar_a2d_grindrail__near_8032c618(void *arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" void kar_a2d_grindrail__near_8032c798(void *arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" void kar_a2d_grindrail__near_8032d96c(void *arg0, void *arg1) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
}

extern "C" void kar_a2d_grindrail__near_8032d9cc(void *arg0, u8 arg1) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
}

extern "C" void kar_a2d_grindrail__near_8032dbcc(void *arg0, u8 arg1) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
}

extern "C" void *kar_a2d_grindrail__near_8032dc68(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    /* best-effort shape only */
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    return arg0;
}

extern "C" void kar_a2d_grindrail__near_8032de10(void *arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" void kar_a2d_grindrail__near_8032de54(void *arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" void kar_a2d_grindrail__near_8032eb54(void *arg0, void *arg1) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
}

extern "C" u8 kar_a2d_grindrail__near_8032ebb4(void *arg0) {
    return FS32(arg0, 0x48) == 0x1E;
}

extern "C" void kar_a2d_grindrail__near_8032ebc8(void *arg0, u8 arg1) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
}

extern "C" void kar_a2d_grindrail__near_8032ed28(void *arg0, u8 arg1) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
}

extern "C" void *kar_a2d_grindrail__near_8032ee88(void *arg0, void *arg1) {
    /* best-effort shape only */
    (void) arg1;
    return arg0;
}

extern "C" void kar_a2d_grindrail__near_8032f084(void *arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" void kar_a2d_grindrail__near_8032f138(void *arg0, f32 farg0) {
    /* best-effort shape only */
    (void) arg0;
    (void) farg0;
}

extern "C" void *kar_a2d_grindrail__near_8032f26c(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void kar_a2d_grindrail__near_8032f4ec(void *arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" f32 kar_a2d_grindrail__near_80330d88(f32 farg0) {
    /* best-effort shape only */
    return farg0;
}

extern "C" void kar_a2d_grindrail__near_803311d4(void *arg0, s32 arg1, f32 farg0, f32 farg1) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
    (void) farg0;
    (void) farg1;
}

extern "C" void *kar_a2d_grindrail__near_80331350(void *arg0, void *arg1, void *arg2) {
    /* best-effort shape only */
    (void) arg1;
    (void) arg2;
    return arg0;
}

extern "C" void *kar_a2d_grindrail__near_803314fc(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" const f32 lbl_805E4120;

extern "C" void fn_80331538(void *arg0) {
    FP(arg0, 0) = NULL;
    FP(arg0, 4) = NULL;
    FF32(arg0, 0x10) = lbl_805E4120;
    FF32(arg0, 0xC) = lbl_805E4120;
    FF32(arg0, 8) = lbl_805E4120;
}

extern "C" void kar_a2d_grindrail__near_80331558(void *arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" void kar_a2d_grindrail__near_80331564(void *arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" void kar_a2d_grindrail__near_80331bc4(void *arg0, void *arg1) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
}

extern "C" void kar_a2d_grindrail__near_80331cf0(void *arg0, void **arg1, s32 arg2, void *arg_sp0) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
}

extern "C" u8 kar_a2d_grindrail__near_80331d98(void *arg0, f32 *arg1) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void kar_a2d_grindrail__near_80331e5c(f32 *arg0, void *arg1) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
}

extern "C" void kar_a2d_grindrail__near_8033209c(f32 *arg0, void *arg1, f32 *arg2) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void kar_a2d_grindrail__near_80332300(void *arg0, void *arg1) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
}

extern "C" void *kar_a2d_grindrail__near_80332608(void *arg0, s32 arg1, f32 *arg2, f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    /* best-effort shape only */
    (void) arg1;
    (void) arg2;
    (void) farg0;
    (void) farg1;
    (void) farg2;
    (void) farg3;
    return arg0;
}

extern "C" f32 kar_a2d_grindrail__near_80332c30(f32 farg0) {
    /* best-effort shape only */
    return farg0;
}

extern "C" void kar_a2d_grindrail__near_8033308c(void *arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" void kar_a2d_grindrail__near_8033343c(void *arg0, void *arg1) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
}

extern "C" void kar_a2d_grindrail__near_80333474(void *arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" void kar_a2d_grindrail__near_803334cc(void *arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" void *kar_a2d_grindrail__near_803337dc(void *arg0, f32 *arg2, s32 arg3) {
    /* best-effort shape only */
    (void) arg2;
    (void) arg3;
    return arg0;
}

extern "C" void kar_a2d_grindrail__near_80333964(void *arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" void kar_a2d_grindrail__near_80333a2c(void *arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" void *kar_a2d_grindrail__near_80333c40(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80333D20(void) {
}

extern "C" void *kar_a2d_grindrail__near_80333d24(void *arg0, s16 arg1, s32 arg_sp0) {
    if (arg0 != NULL) {
        (void) arg_sp0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80334340(void) {
}

extern "C" void kar_a2d_grindrail__near_80334348(void *arg0, s32 arg1) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_803343AC(void *arg0, void *arg1) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
}

extern "C" void kar_a2d_grindrail__near_803343d8(void) {
    kar_a2d_effecthandle__near_8037cfb4();
}

extern "C" void kar_a2d_grindrail__near_803343f8(void *arg0_unused, Mtx arg1) {
    PSMTXIdentity(arg1);
}

extern "C" void fn_8033441C(f32 *arg1, f32 *arg2) {
    /* best-effort shape only */
    (void) arg1;
    (void) arg2;
}

extern "C" void fn_8033442C(void) {
}

extern "C" void kar_a2d_grindrail__near_80334430(void *arg0, s32 *arg1, s32 arg_sp0, s32 arg3) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
    (void) arg3;
}

extern "C" void kar_a2d_grindrail__near_80334534(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    /* best-effort shape only */
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
}

extern "C" void kar_a2d_grindrail__near_80334600(void *arg0, void *arg1, void *arg2, void *arg3) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void kar_a2d_grindrail__near_803346b4(void *arg1, void *arg2, void *arg3, void *arg4) {
    /* best-effort shape only */
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
}

extern "C" void *kar_a2d_grindrail__near_803346e4(void *arg0, void *arg1) {
    /* best-effort shape only */
    (void) arg1;
    return arg0;
}

extern "C" void *kar_a2d_grindrail__near_803349c0(void *arg0, void *arg1) {
    /* best-effort shape only */
    (void) arg1;
    return arg0;
}

extern "C" void *kar_a2d_grindrail__near_80334a8c(void *arg0) {
    /* best-effort shape only */
    return arg0;
}

extern "C" s32 *kar_a2d_grindrail__near_80334bd0(void *arg0) {
    /* best-effort shape only */
    return (s32 *) arg0;
}

extern "C" void kar_a2d_grindrail__near_80334bf8(void *arg0, void **arg1) {
    /* best-effort shape only */
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_80334C34(s32 arg0) {
    /* best-effort shape only */
    (void) arg0;
}

extern "C" char lbl_804E5614[4];
extern "C" char lbl_804E55E0[4];

extern "C" void *kar_a2d_grindrail__near_80334c3c(void) {
    void *r = lbl_804E5614;
    if (FU32(kar_diag__803ad760(lbl_805DDBC0, 0, lbl_805DA9A8, lbl_805DA9A0, 0), 0x14) == 1U) {
        r = lbl_804E55E0;
    }
    return r;
}

extern "C" void *kar_a2d_grindrail__near_80334c8c(u32 arg0) {
    if (arg0 == 0U) {
        return lbl_804E55E0;
    }
    return lbl_804E5614;
}


extern "C" void kar_a2d_grindrail__near_80334ca8(void *arg0) {
    /* rail waypoint-array final teardown/rebuild pass; best-effort shape only */
    (void) arg0;
}
