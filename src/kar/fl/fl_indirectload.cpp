#include <dolphin/types.h>
#include <dolphin/gx/gxtypes.h>

extern "C" {
#include <global.h>
#include <sysdolphin/class.h>
#include <sysdolphin/jobj.h>
#include <sysdolphin/dobj.h>
#include <sysdolphin/mobj.h>
#include <sysdolphin/pobj.h>
#include <sysdolphin/class_new.h>
#include <functions.h>
}

#define GX_TEVDIRECT 0

extern "C" {

void GXSetTevDirect(u32 tevstage);
void GXSetNumIndStages(s32 n);
void HSD_StateInvalidate(s32 mask);

void HSD_SetMaterialColor(GXColor, GXColor, GXColor, void *, f32);
void HSD_SetMaterialShininess(void *, f32);
void HSD_SetupRenderModeWithCustomPE(u32, void *);
void HSD_SetupTevStage(void *);
void HSD_StateAssignTev(void);
void HSD_StateInitTev(void);
void HSD_TExpSetupTev(void *, void *);

void HSD_MtxAlloc(void);
void HSD_RObjLoadDesc(s32);
void HSD_DObjSetDefaultClass(HSD_DObjInfo *);
void HSD_MObjSetDefaultClass(HSD_MObjInfo *);

void HSD_PadRumbleOffH(u8);
void HSD_PadRumbleOffN(u8);
void HSD_PadRumbleOn(u8);

extern const f32 lbl_805E4FA8;

extern HSD_DObjInfo hsdDObj;

void *fn_8038CB78(void *arg0);
s32 fn_8038BC80(void *, u32);
void fn_803B6C88(void *, void *, s32, s32);
void fn_803CE604(u32, void *, s32);
void fn_803CE8E0(u32, s32, s32);
void fn_803CEC68(s32, s32, s32, u8, s32, s32);
void fn_803CECD0(s32, s32, s32, s32, u8, s32);

f32 kar_a2d_game_lib__near_802889d0(f32 *, f32 *, f32);
s32 kar_a2d_kurakko__near_80378568(void **);
void *kar_diag__803ad760(s32, s32, void *, void *, s32);
f32 kar_diag__near_8038b844(void *, void *, f32);
f32 kar_diagnostic__802a07d8(void **, void *, f32);

char *strchr(char *, s32);
s32 strncmp(char *, char *, s32);

}

#pragma push
#pragma inline_max_size(600)
extern "C" u8 kar_fl_indirectload__80391f10(s8 *arg0, s8 *arg1) {
    s8 c0, c1;
    while ((c0 = *arg0) != 0 && (c1 = *arg1) != 0) {
        if (c0 == c1 || c0 == '?') {
            arg0++;
            arg1++;
            continue;
        }
        if (c0 == '*') {
            arg0++;
            if (*arg0 == 0) {
                return 1;
            }
            while (*arg1 != 0) {
                if (kar_fl_indirectload__80391f10(arg0, arg1) != 0) {
                    return 1;
                }
                arg1++;
            }
            break;
        }
        break;
    }
    while (*arg0 == '*') arg0++;
    return (*arg0 == 0) && (*arg1 == 0);
}
#pragma pop

struct TexExtRow {
    void *unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};
extern TexExtRow lbl_8048B458[];

extern "C" s32 kar_fl_indirectload__near_80392398(void *arg0, char *arg1, s32 arg2, s32 arg3, s32 *arg4, void **arg5, s32 *arg6) {
    return 0;
}

extern "C" void kar_fl_indirectload__near_8039254c(void *arg0) {
    struct T {
        u16 unk0;
        u16 unk2;
        u16 unk4;
        u16 unk6;
        u16 unk8;
        u16 unkA;
        u8 unkC;
        u8 unkD;
        u8 unkE;
        u8 unkF;
        u8 unk10;
        u8 unk11;
        u8 unk12;
        u8 unk13;
        u8 unk14;
        u8 unk15;
        u8 unk16;
        u8 unk17;
    };
    T *t = (T *) arg0;
    t->unk0 = 0xA;
    t->unk2 = 0xA;
    t->unk4 = 0x32;
    t->unk6 = 0x32;
    t->unk8 = 0x64;
    t->unkA = 0x64;
    t->unkC = 0xFF;
    t->unkD = 0;
    t->unkE = 0xFF;
    t->unkF = 0x40;
    t->unk10 = 0xFF;
    t->unk11 = 0;
    t->unk12 = 0xFF;
    t->unk13 = 0x80;
    t->unk14 = 0xFF;
    t->unk15 = 0;
    t->unk16 = 0xFF;
    t->unk17 = 0xFF;
}

extern "C" void kar_fl_indirectload__near_803925b4(void *arg0) {
}

extern "C" void kar_fl_indirectload__near_80392ae4(void **arg0, s32 *arg1) {
}

extern "C" f32 kar_fl_indirectload__near_80392f78(f32 farg0) {
    return farg0;
}

extern "C" f32 kar_fl_indirectload__near_803933d4(f32 farg0) {
    return farg0;
}

extern "C" u8 kar_fl_indirectload__near_80393820(void **arg0, void **arg1) {
    return 0;
}

extern "C" void kar_fl_indirectload__near_80393af0(void **arg0, s32 *arg1) {
}

extern "C" f32 kar_fl_indirectload__near_803943b8(f32 farg0, f32 farg1, f32 farg2) {
    return farg0;
}

extern "C" f32 kar_fl_indirectload__near_80394814(f32 farg0) {
    return farg0;
}

extern "C" void kar_fl_indirectload__near_80394c60(char *arg0) {
    for (u32 i = 0; i < 4; i++) {
        HSD_PadRumbleOffN((u8) i);
        *(f32 *) (arg0 + 4) = lbl_805E4FA8;
        *(s32 *) (arg0 + 0x14) = 2;
        arg0 += 4;
    }
}

struct NamePair {
    char *a;
    char *b;
};

class RcListItem {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual RcListItem *GetNext();
    virtual void v8();
    virtual void v9();
    virtual u8 v10();
    s32 pad4[2];
    void *unkC;
    s32 unk10;
    f32 unk14;
};

extern "C" s32 lbl_805DDB24;
extern "C" NamePair lbl_805DC130;
extern "C" NamePair lbl_805DC128;

extern "C" s32 kar_fl_indirectload__near_80394e64(f32 *arg0, f32 farg0);

extern "C" void kar_fl_indirectload__near_80394cd4(void *arg0) {
    u8 *arg0b = (u8 *) arg0;
    if (arg0b[0x24] != 0 && arg0b[0x29] != 0) {
        f32 vals[4];
        vals[3] = lbl_805E4FA8;
        vals[2] = lbl_805E4FA8;
        vals[1] = lbl_805E4FA8;
        vals[0] = lbl_805E4FA8;
        RcListItem *item = (RcListItem *) kar_diag__803ad760(lbl_805DDB24, 0, &lbl_805DC130, &lbl_805DC128, 0);
        while (item != NULL) {
            if (arg0b[item->unk10 + 0x25] != 0) {
                item->v10();
                f32 *dst = &vals[item->unk10];
                f32 *src = (item->unk14 < *dst) ? dst : &item->unk14;
                *dst = *src;
            }
            item = item->GetNext();
        }
        u8 *p = arg0b;
        f32 *v = vals;
        u32 i;
        for (i = 0; i < 4; i++) {
            if (arg0b[i + 0x25] != 0) {
                *(s32 *) (p + 0x14) = kar_fl_indirectload__near_80394e64((f32 *) (p + 4), *v);
                switch (*(s32 *) (p + 0x14)) {
                case 0:
                    HSD_PadRumbleOn((u8) i);
                    break;
                case 1:
                    HSD_PadRumbleOffH((u8) i);
                    break;
                case 2:
                    HSD_PadRumbleOffN((u8) i);
                    break;
                }
            }
            p += 4;
            v += 1;
        }
    }
}

extern "C" s32 kar_fl_indirectload__near_80394e64(f32 *arg0, f32 farg0) {
    return 0;
}

extern "C" void kar_fl_indirectload__near_8039509c(void *arg0) {
}

extern "C" char lbl_804F5230[0x3C] = {0};

extern "C" char lbl_804F5440[0x3C] = {
    ' ', ' ', ' ', ' ', 'R', 'c', 'P', 'o', 'o', 'l', ',', '\n', 0, 0, 0, 0,
    'R', 'c', 'O', 'n', '(', '%', 'd', ')', ',', '\n', 0, 0,
    'R', 'c', 'O', 'f', 'f', 'N', '(', '%', 'd', ')', ',', '\n', 0, 0, 0, 0,
    'R', 'c', 'O', 'f', 'f', 'H', '(', '%', 'd', ')', ',', '\n', 0, 0, 0, 0,
};

extern "C" void kar_fl_indirectload__near_80395490(void) {
    OSReport(lbl_804F5440);
}

extern "C" char lbl_805DC14C[5];

extern "C" void kar_fl_indirectload__near_803954bc(void *arg0, s32 *arg1) {
    char * const base = lbl_804F5230;
    OSReport(lbl_805DC14C);
    switch (arg1[0]) {
    case 0:
        OSReport(base + 0x220, arg1[1]);
        break;
    case 1:
        OSReport(base + 0x22C, arg1[1]);
        break;
    case 2:
        OSReport(base + 0x23C, arg1[1]);
        break;
    }
}

extern "C" char lbl_804F547C[0x11] = "    RcLoop(%d),\n";

extern "C" void kar_fl_indirectload__near_80395560(void) {
    OSReport(lbl_804F547C);
}

extern "C" void kar_fl_indirectload__near_803955bc(void *arg0, u32 arg1, u32 arg2);

struct UnpackTriple {
    void *unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" void kar_fl_indirectload__near_8039558c(void *arg0) {
    UnpackTriple *t = (UnpackTriple *) arg0;
    kar_fl_indirectload__near_803955bc(t->unk0, t->unk4, t->unk8);
}

#pragma dont_inline on
extern "C" void kar_fl_indirectload__near_803955bc(void *arg0, u32 arg1, u32 arg2) {
    *(u32 *) arg0 = arg1 ^ arg2;
}
#pragma dont_inline off

extern "C" u32 kar_fl_indirectload__near_803959cc(u32 *arg0, u32 *arg1) {
    u32 r = 0;
    if (arg0[0] != arg1[0] || arg0[1] != arg1[1]) {
        r = 1;
    }
    return r;
}

extern "C" u8 kar_fl_indirectload__near_803959fc(u32 *arg0, u32 *arg1) {
    u32 r = 0;
    if (arg0[0] == arg1[0] && arg0[1] == arg1[1]) {
        r = 1;
    }
    return (u8) r;
}

extern "C" void kar_fl_indirectload__near_80395a2c(u32 *arg0, u32 *arg1, u32 *arg2) {
    u32 v1 = arg1[0];
    u32 v2 = arg2[0];
    arg0[0] = v1;
    arg0[1] = v2;
}

struct RcCurveList {
    void *unk0;
    void *unk4;
    u32 unk8;
};

extern "C" void kar_fl_indirectload__near_80395a40(RcCurveList *arg0, void *arg1) {
    if (arg0->unk8 == 0) {
        arg0->unk4 = arg1;
        arg0->unk8 = 1;
    } else if (arg1 != arg0->unk4) {
        kar_fl_indirectload__near_803955bc(arg0->unk0, (u32) arg0->unk4, arg0->unk8);
        arg0->unk4 = arg1;
        arg0->unk8 = 1;
    } else {
        arg0->unk8 += 1;
    }
}

extern "C" char lbl_804F5580[0x18] = {0};
extern "C" char lbl_804F5598[0x18] = {0};

extern "C" void *kar_fl_indirectload__near_80395abc(void **arg0, s16 arg1) {
    if (arg0 != NULL) {
        *arg0 = lbl_804F5598;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80395B04(void *arg0) {
    ((u32 *) arg0)[0] = 0;
    ((u32 *) arg0)[1] = 0;
}

extern "C" void kar_fl_indirectload__near_80395b14(void *arg0) {
}

extern "C" void *kar_fl_indirectload__near_80395e2c(void **arg0, s16 arg1) {
    if (arg0 != NULL) {
        *arg0 = lbl_804F5580;
        if (arg0 != NULL) {
            *arg0 = lbl_804F5598;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

struct FloatCurveArr {
    f32 *unk0;
    s32 unk4;
};

class RcCurvePlayer {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void SetValue(f32);
    char pad4[0x10];
    f32 unk14;
    u32 unk18;
    s32 unk1C;
    u32 unk20;
    f32 unk24;
    u8 unk28;
};

extern "C" f32 kar_fl_indirectload__near_80395fbc(FloatCurveArr *arg0, f32 farg0);
extern "C" f64 lbl_805E4FB0;

static inline f32 u32_to_f32_biased(u32 v) {
    f64 d;
    ((u32 *) &d)[0] = 0x43300000;
    ((u32 *) &d)[1] = v;
    return (f32) (d - lbl_805E4FB0);
}

extern "C" void kar_fl_indirectload__near_80395e88(void *arg0) {
    RcCurvePlayer *obj = (RcCurvePlayer *) arg0;
    if (obj->unk18 == 0) {
        obj->unk14 = lbl_805E4FA8;
        return;
    }
    FloatCurveArr tmp;
    tmp.unk0 = (f32 *) obj->unk18;
    tmp.unk4 = obj->unk1C;
    obj->SetValue(obj->unk24 * kar_fl_indirectload__near_80395fbc(&tmp, u32_to_f32_biased(obj->unk20)));
    s32 count = kar_a2d_kurakko__near_80378568((void **) &tmp);
    u32 old20 = obj->unk20;
    f32 lastX = tmp.unk0[(count - 1) * 2];
    f32 oldF = u32_to_f32_biased(old20);
    obj->unk20 = old20 + 1;
    if (lastX <= oldF) {
        obj->unk20 = 0;
        if (obj->unk28 == 0) {
            obj->unk18 = 0;
            obj->SetValue(lbl_805E4FA8);
        }
    }
}

extern "C" void fn_80395F8C(s32 *arg0) {
    arg0[6] += 2;
}

extern "C" void fn_80395F9C(s32 *arg0) {
    arg0[6] += 2;
}

extern "C" void fn_80395FAC(s32 *arg0) {
    arg0[6] += 2;
}

extern "C" s32 kar_fl_indirectload__near_80396068(FloatCurveArr *arg0, f32 farg0);

extern "C" f32 kar_fl_indirectload__near_80395fbc(FloatCurveArr *arg0, f32 farg0) {
    s32 idx = kar_fl_indirectload__near_80396068(arg0, farg0);
    if (idx < 0) {
        return ((f32 *) arg0->unk0)[1];
    }
    s32 count = kar_a2d_kurakko__near_80378568((void **) arg0);
    if (idx >= count - 1) {
        s32 count2 = kar_a2d_kurakko__near_80378568((void **) arg0);
        return arg0->unk0[count2 * 2 - 1];
    }
    char *p1 = (char *) arg0->unk0 + idx * 8;
    char *p2 = (char *) arg0->unk0 + (idx + 1) * 8;
    return kar_diag__near_8038b844(p1, p2, farg0);
}

extern "C" s32 kar_fl_indirectload__near_80396068(FloatCurveArr *arg0, f32 farg0) {
    f32 *base = arg0->unk0;
    s32 count = arg0->unk4;
    s32 offset = 0;
    f32 *cur = base;
    s32 i;
    for (i = 0; i < count; i++) {
        if (i != 0) {
            f32 *p = base + offset;
            if (p[-2] > p[0]) {
                break;
            }
        }
        if (cur[0] > farg0) {
            break;
        }
        offset += 2;
        cur += 2;
    }
    return i - 1;
}

extern "C" void kar_fl_indirectload__near_803960c8(HSD_JObj *jobj, Mtx vmtx, Mtx pmtx, HSD_TrspMask trsp_mask, u32 rendermode) {
    hsdJObj.disp(jobj, vmtx, pmtx, trsp_mask, rendermode);
}

static char lbl_804F55B0[0x54];
static char lbl_804F5604[0x54];
static unsigned char lbl_804F5658[0xF8] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x66, 0x6F, 0x72, 0x63, 0x65, 0x5F, 0x69, 0x6E, 0x64, 0x69, 0x72, 0x65,
    0x63, 0x74, 0x5F, 0x63, 0x6C, 0x61, 0x73, 0x73, 0x5F, 0x6C, 0x69, 0x62, 0x72, 0x61, 0x72, 0x79,
    0x00, 0x00, 0x00, 0x00, 0x66, 0x6F, 0x72, 0x63, 0x65, 0x5F, 0x69, 0x6E, 0x64, 0x69, 0x72, 0x65,
    0x63, 0x74, 0x5F, 0x6D, 0x6F, 0x62, 0x6A, 0x00, 0x66, 0x6F, 0x72, 0x63, 0x65, 0x5F, 0x69, 0x6E,
    0x64, 0x69, 0x72, 0x65, 0x63, 0x74, 0x5F, 0x64, 0x6F, 0x62, 0x6A, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01,
    0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03,
};

extern "C" void kar_fl_indirectload__near_803960f8(void) {
    char * const base = lbl_804F55B0;
    hsdInitClassInfo((HSD_ClassInfo *) base, (HSD_ClassInfo *) &hsdJObj, base + 0x13C, base + 0x15C, 0x54, 0x88);
    ((HSD_JObjInfo *) base)->disp = kar_fl_indirectload__near_803960c8;
}

extern "C" void kar_fl_indirectload__near_80396154(HSD_DObj *dobj, Mtx vmtx, Mtx pmtx, u32 rendermode) {
    hsdDObj.disp(dobj, vmtx, pmtx, rendermode);
    for (u32 i = 0; i < 0x10; i++) {
        GXSetTevDirect(i);
    }
    GXSetNumIndStages(0);
    HSD_StateInvalidate(-1);
}

extern "C" void kar_fl_indirectload__near_803961b4(void) {
    char * const base = lbl_804F55B0;
    hsdInitClassInfo((HSD_ClassInfo *) (base + 0xA8), (HSD_ClassInfo *) &hsdDObj, base + 0x13C, base + 0x170, 0x48, 0x18);
    ((HSD_DObjInfo *) (base + 0xA8))->disp = kar_fl_indirectload__near_80396154;
}

extern "C" void kar_fl_indirectload__80396210(void *arg0) {
}

extern "C" void kar_fl_indirectload__near_80396724(HSD_MObj *mobj, u32 rendermode) {
}

extern "C" void kar_fl_indirectload__near_80396948(void) {
    char * const base = lbl_804F55B0;
    hsdInitClassInfo((HSD_ClassInfo *) (base + 0x54), (HSD_ClassInfo *) &hsdMObj, base + 0x13C, base + 0x15C, 0x54, 0x20);
    ((HSD_MObjInfo *) (base + 0x54))->setup = kar_fl_indirectload__near_80396724;
}

extern "C" s32 kar_fl_indirectload__near_803969a4(HSD_PObj *pobj, HSD_PObjDesc *desc) {
    return 0;
}

extern "C" void kar_fl_indirectload__near_80396c30(void) {
    char * const base = lbl_804F55B0;
    hsdInitClassInfo((HSD_ClassInfo *) (base + 0xF0), (HSD_ClassInfo *) &hsdPObj, base + 0x13C, base + 0x1D0, 0x4C, 0x1C);
    ((HSD_PObjInfo *) (base + 0xF0))->load = kar_fl_indirectload__near_803969a4;
}

#pragma dont_inline on
extern "C" void *kar_fl_indirectload__80396c8c(void *arg0, void *arg1, void *arg2, u8 arg3, u8 arg4) {
    *(volatile u8 *) &arg3 = arg3 ^ arg4;
    return NULL;
}
#pragma dont_inline off

extern "C" u8 lbl_805DC170;
extern "C" char lbl_805DC174[5];
extern "C" u8 lbl_804F5794[0xB];

extern "C" unsigned char kar_src_fl_indirectload_804f5750[0x44] = {
    0x66, 0x6C, 0x5F, 0x69, 0x6E, 0x64, 0x69, 0x72, 0x65, 0x63, 0x74, 0x6C, 0x6F, 0x61, 0x64, 0x2E,
    0x63, 0x70, 0x70, 0x00, 0x63, 0x6C, 0x69, 0x73, 0x74, 0x2D, 0x3E, 0x74, 0x79, 0x70, 0x65, 0x20,
    0x3D, 0x3D, 0x20, 0x48, 0x53, 0x44, 0x5F, 0x54, 0x45, 0x5F, 0x43, 0x4E, 0x53, 0x54, 0x00, 0x00,
    0x66, 0x6F, 0x72, 0x63, 0x65, 0x5F, 0x69, 0x6E, 0x64, 0x69, 0x72, 0x65, 0x63, 0x74, 0x5F, 0x70,
    0x6F, 0x62, 0x6A, 0x00,
};

extern "C" void *kar_fl_indirectload__80396e88(char *arg0, void *arg1, u8 arg2) {
    if (arg0 == NULL) {
        return NULL;
    }
    char *name = *(char **) (arg0 - 4);
    if (name == NULL) {
        name = (char *) &lbl_805DC170;
    }
    HSD_JObj *jobj;
    u8 matched = kar_fl_indirectload__80391f10((s8 *) lbl_804F5794, (s8 *) name);
    char *className = *(char **) arg0;
    HSD_ClassInfo *found = NULL;
    if (className != NULL) {
        found = hsdSearchClassInfo(className);
    }
    if (found == NULL) {
        jobj = HSD_JObjAlloc();
    } else {
        jobj = (HSD_JObj *) hsdNew(found);
        if (jobj == NULL) {
            __assert((char *) kar_src_fl_indirectload_804f5750, 0x26B, lbl_805DC174);
        }
    }
    kar_fl_indirectload__80396c8c(jobj, arg0, arg1, matched, arg2);
    return jobj;
}

extern "C" u8 lbl_805DDCB8;

extern "C" void *kar_fl_indirectload__80396f54(void *arg0) {
    lbl_805DDCB8 = 0;
    char *name1 = *(char **) ((char *) arg0 - 4);
    if (name1 == NULL) {
        name1 = (char *) &lbl_805DC170;
    }
    u32 matched1 = kar_fl_indirectload__80391f10((s8 *) lbl_804F5794, (s8 *) name1) != 0;
    void *jobj;
    if (arg0 == NULL) {
        jobj = NULL;
    } else {
        char *name2 = *(char **) ((char *) arg0 - 4);
        if (name2 == NULL) {
            name2 = (char *) &lbl_805DC170;
        }
        u8 matched2 = kar_fl_indirectload__80391f10((s8 *) lbl_804F5794, (s8 *) name2);
        char *className = *(char **) arg0;
        HSD_ClassInfo *found = NULL;
        if (className != NULL) {
            found = hsdSearchClassInfo(className);
        }
        if (found == NULL) {
            jobj = HSD_JObjAlloc();
        } else {
            jobj = hsdNew(found);
            if (jobj == NULL) {
                __assert((char *) kar_src_fl_indirectload_804f5750, 0x26B, lbl_805DC174);
            }
        }
        kar_fl_indirectload__80396c8c(jobj, arg0, NULL, matched2, matched1);
    }
    HSD_JObjResolveRefsAll((HSD_JObj *) jobj, (HSD_Joint *) arg0);
    HSD_DObjSetDefaultClass(NULL);
    HSD_MObjSetDefaultClass(NULL);
    return jobj;
}

extern "C" u32 kar_fl_indirectload__near_80397080(s32 arg0) {
    extern s32 lbl_804F57A0[0x10];
    return lbl_804F57A0[arg0];
}

extern "C" void kar_fl_indirectload__near_80397094(void *arg0) {
}

extern "C" void kar_fl_indirectload__near_803973a4(void *arg0) {
}

extern "C" s32 lbl_805DDAA0;
extern "C" NamePair lbl_805DC198;
extern "C" NamePair lbl_805DC1A0;
extern "C" s32 lbl_805DDAAC;
extern "C" NamePair lbl_805DC188;
extern "C" NamePair lbl_805DC190;

extern "C" void kar_fl_indirectload__near_80397970(void) {
    kar_diag__803ad760(lbl_805DDAA0, 0, &lbl_805DC198, &lbl_805DC1A0, 0);
}

extern "C" void kar_fl_indirectload__near_80397c28(s32 arg0, void *arg1, void *arg2, s32 arg3, s32 arg4);

extern "C" void kar_fl_indirectload__near_803979a4(void *arg0) {
    RcListItem *item = (RcListItem *) kar_diag__803ad760(lbl_805DDAAC, 0, &lbl_805DC190, &lbl_805DC188, 0);
    while (item != NULL) {
        if (item->v10() != 0) {
            kar_fl_indirectload__near_80397c28((s32) arg0, item->unkC, item, 0, 0);
        }
        item = item->GetNext();
    }
}

extern "C" void kar_fl_indirectload__near_80397a48(void *arg0) {
}

#pragma dont_inline on
extern "C" void kar_fl_indirectload__near_80397c28(s32 arg0, void *arg1, void *arg2, s32 arg3, s32 arg4) {
    *(volatile s32 *) &arg0 = arg1 != NULL;
}
#pragma dont_inline off

class RcCallbackObj {
public:
    virtual void v0();
    virtual s32 v1();
    virtual void v2();
    virtual s32 v3();
};

struct RcCallbackHolder {
    char pad[0x24];
    RcCallbackObj *unk24;
};

extern "C" s32 kar_fl_indirectload__near_80398090(RcCallbackHolder *arg0) {
    RcCallbackObj *obj = arg0->unk24;
    if (obj != NULL) {
        return obj->v1();
    }
    return 0;
}

extern "C" s32 kar_fl_indirectload__near_803980d0(RcCallbackHolder *arg0) {
    RcCallbackObj *obj = arg0->unk24;
    if (obj != NULL) {
        return obj->v3();
    }
    return 0;
}

extern "C" void kar_fl_indirectload__near_80398110(void *arg0, void **arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
}

extern "C" char lbl_805DC1B8[6];

extern "C" char *kar_fl_indirectload__near_80398690(void *arg0, char *arg1) {
    char *paren = strchr(arg1, '(');
    s32 len = paren - arg1;
    if (strncmp(arg1, lbl_805DC1B8, len) == 0) {
        arg1 += len;
    }
    return arg1;
}

extern "C" void kar_fl_indirectload__near_803986f0(void *arg0) {
}
