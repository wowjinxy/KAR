#include <dolphin/types.h>

extern "C" {
#include <global.h>
}

extern "C" {
void HSD_JObjDispAll(void *jobj, void *pmtx, s32 which, u32 rendermode);
u8 kar_a2d_effecthandle__near_8037b61c(void *arg0);
void kar_a2d_game_effect__near_8037afd0(void *arg0, u8 arg1);
void *kar_a2d_effecthandle__8037b028(void *arg0, s32 arg1, s32 arg2, void *arg3, void *arg4, void *arg5);
void kar_a2d_grindrail__near_80323d14(void *arg0);
void HSD_ForeachAnim(void *obj, s32 type, u32 mask, void *func, s32 arg_type, ...);
void HSD_AObjSetRate(void *aobj, f32 rate);
void HSD_AObjSetCurrentFrame(void *aobj, f32 frame);
void HSD_JObjRemoveAnimAll(void *jobj);
void kar_a2d_game_audio__near_80379398(void *arg0);
}

static char kar_srcfile_jobj_h_805db210[7] = "jobj.h";
static char lbl_805DB218[5] = "jobj";
extern char lbl_804E9980[156];

extern char lbl_804EA548[];
extern char lbl_804E92B4[];
extern char lbl_804E91EC[];
extern f32 lbl_805E456C;

extern "C" void *kar_diag__803ad760(s32, s32, void *, void *, s32);
extern s32 lbl_805DDBC0;
extern void *lbl_805DB1C0;
extern void *lbl_805DB1B8;

struct DiagResult {
    char pad0[0x14];
    s32 unk14;
};

class RefObj {
public:
    virtual void Release(s32);
};

class DiagObj : public RefObj {
public:
    virtual void v04();
    virtual void Init();
    virtual s32 v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
};

class KartArg1Iface {
public:
    virtual void v00(s32);
};

extern "C" void * kar_a2d_bg8000__80342be4(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void kar_a2d_bg8000__near_80343a74(void * arg0);

extern "C" void kar_a2d_bg8000__near_80342e20(char * arg0) {
    u32 i;
    for (i = 0; i < *(u32 *) (arg0 + 8); i++) {
        kar_a2d_bg8000__near_80343a74((*(void ***) (arg0 + 0xc))[i]);
    }
    *(s32 *) (arg0 + 0x14) = 0;
    *(s32 *) (arg0 + 0x18) = 0;
    *(s32 *) (arg0 + 0x1c) = 0;
    *(s32 *) (arg0 + 0x20) = 0;
}

#pragma dont_inline on
extern "C" void kar_a2d_bg8000__near_80342e98(void * arg0_) {
    char *arg0 = (char *) arg0_;
    *(s32 *) (arg0 + 0x20) = -1;
}
#pragma dont_inline off

extern "C" void * kar_a2d_bg8000__near_803431e0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * kar_a2d_bg8000__near_803432b4(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * kar_a2d_bg8000__near_803433c0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void kar_a2d_bg8000__near_803434d4(void * arg0_) {
    char *arg0 = (char *) arg0_;
    kar_a2d_bg8000__near_80342e98(arg0 + 0x58);
    ((DiagObj *) (arg0 + 0x100))->v04();
}

extern "C" void kar_a2d_bg8000__near_80343518(void * arg0_) {
    char *arg0 = (char *) arg0_;
    if (*(s32 *) (arg0 + 0x18) != 30001) {
        kar_a2d_game_effect__near_8037afd0(arg0 + 0xc, 0);
        kar_a2d_effecthandle__8037b028(arg0 + 0xc, 10811, 0, 0, 0, 0);
    }
    if (*(u8 *) (arg0 + 0xf8) != 0) {
        kar_a2d_grindrail__near_80323d14(arg0 + 0x5c);
        kar_a2d_grindrail__near_80323d14(arg0 + 0x90);
        kar_a2d_grindrail__near_80323d14(arg0 + 0xc4);
    }
    ((DiagObj *) (arg0 + 0x100))->Init();
}

extern "C" void kar_a2d_bg8000__near_80343e88(void * arg0);

extern "C" void kar_a2d_bg8000__near_803435ac(char * arg0) {
    if (*(u8 *) (arg0 + 0x10) != 0) {
        u32 i;
        for (i = 0; i < *(u32 *) (arg0 + 8); i++) {
            kar_a2d_bg8000__near_80343e88((*(void ***) (arg0 + 0xc))[i]);
        }
    }
}

extern "C" void kar_a2d_bg8000__near_8034361c(char * arg0) {
    ((DiagObj *) (arg0 + 0x100))->v14();
}

extern "C" void kar_a2d_bg8000__near_803442bc(void * arg0);

extern "C" void kar_a2d_bg8000__near_80343648(char * arg0) {
    if (*(u8 *) (arg0 + 0x10) != 0) {
        u32 i;
        for (i = 0; i < *(u32 *) (arg0 + 8); i++) {
            kar_a2d_bg8000__near_803442bc((*(void ***) (arg0 + 0xc))[i]);
        }
    }
}

extern "C" void kar_a2d_bg8000__near_8034432c(void * arg0, void * arg1);

extern "C" void kar_a2d_bg8000__near_803436b8(void * arg0_, void * arg1) {
    char *arg0 = (char *) arg0_;
    if (*(u8 *) (arg0 + 0x110) != 0) {
        u32 i;
        for (i = 0; i < *(u32 *) (arg0 + 0x108); i++) {
            kar_a2d_bg8000__near_8034432c((*(void ***) (arg0 + 0x10c))[i], arg1);
        }
    }
}

extern "C" void kar_a2d_bg8000__near_80343738(char * arg0) {
    ((DiagObj *) (arg0 + 0x58))->Init();
}

extern "C" void kar_a2d_bg8000__near_80343764(void * arg0_, s32 arg1) {
    char *arg0 = (char *) arg0_;
    if (*(u8 *) (arg0 + 0xa0) != 0) {
        ((KartArg1Iface *) (arg0 + 4))->v00(arg1);
        ((KartArg1Iface *) (arg0 + 0x38))->v00(arg1);
        ((KartArg1Iface *) (arg0 + 0x6c))->v00(arg1);
        *(s32 *) (arg0 + 0xa4) = 0;
    }
}

extern "C" void * kar_a2d_bg8000__803437f0(void * arg0, void * arg1, void * arg2, void * arg3, s32 arg4, s32 arg5) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg5;
    return 0;
}

extern "C" void kar_a2d_bg8000__near_80343a94(void * arg0);

extern "C" void kar_a2d_bg8000__near_80343a74(void * arg0) {
    kar_a2d_bg8000__near_80343a94(arg0);
}

extern "C" f32 HSD_Randf(void);
extern "C" void kar_a2d_game_lib__near_802895c8(void *, u16, f32, f32);
extern "C" void kar_a2d_game_lib__near_80289590(void *, u16, f32);
extern "C" void kar_a2d_game_lib__near_80289768(void *, u16, f32);
extern char lbl_804E8474[0xb4];
extern char lbl_804E83B0[0xb4];
extern void *lbl_805DB0D0;
extern void *lbl_805DB0C8;
extern f32 lbl_805E4508;
extern f32 lbl_805E4514;

extern "C" void kar_a2d_bg8000__near_80343a94(void * arg0_) {
    char *arg0 = (char *) arg0_;
    *(s32 *) (arg0 + 0x18) = 0;
    u32 cond = ((DiagResult *) kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DB0D0, &lbl_805DB0C8, 0))->unk14;
    char *chosen = (cond == 1) ? lbl_804E83B0 : lbl_804E8474;
    f32 r = HSD_Randf();
    r = *(f32 *) (chosen + 0xb0) * r;
    *(u32 *) (arg0 + 0x1c) = (u32) r + 1;
    kar_a2d_game_lib__near_802895c8(*(void **) (arg0 + 4), 0xFFFF, lbl_805E4508, lbl_805E4514);
    kar_a2d_game_lib__near_80289590(*(void **) (arg0 + 4), 0xFFFF, lbl_805E4508);
    kar_a2d_game_lib__near_80289768(*(void **) (arg0 + 4), 0xFFFF, lbl_805E4508);
}

extern "C" void kar_a2d_bg8000__near_80343b58(void * arg0) {
    (void) arg0;
}

extern "C" void kar_a2d_bg8000__near_80343e88(void * arg0) {
    (void) arg0;
}

extern "C" void kar_a2d_bg8000__near_803442bc(void * arg0_) {
    char *arg0 = (char *) arg0_;
    if (*(s32 *) (arg0 + 0x18) == 4) {
        HSD_JObjDispAll(*(void **) (arg0 + 0xc), 0, 1, 0);
        HSD_JObjDispAll(*(void **) (arg0 + 0xc), 0, 4, 0);
        HSD_JObjDispAll(*(void **) (arg0 + 0xc), 0, 2, 0);
    }
}

extern "C" void kar_a2d_bg8000__near_8034432c(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void * kar_a2d_bg8000__803445ec(void * arg0, s8 arg1, void * arg2, void * arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
    return 0;
}

extern "C" void * kar_a2d_bg8000__near_803448a4(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_80344AB8(void) {
}

extern "C" void fn_80344ABC(void) {
}

extern "C" void * kar_a2d_bg8000__near_80344ac0(void) {
    u32 cond = ((DiagResult *) kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DB1C0, &lbl_805DB1B8, 0))->unk14;
    void *result = (cond == 1) ? lbl_804E91EC : lbl_804E92B4;
    return result;
}

extern "C" void * kar_a2d_bg8000__near_80344b10(u32 arg0) {
    if (arg0 == 0) {
        return lbl_804E91EC;
    }
    return lbl_804E92B4;
}

extern "C" void kar_a2d_bg8000__near_80344b2c(void * arg0) {
    (void) arg0;
}

extern "C" void * kar_a2d_bg8000__near_80345448(void * arg0, s32 arg_sp0) {
    (void) arg0;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_80345E10(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_80345EF0(void * arg0) {
    (void) arg0;
}

extern "C" void fn_80346044(void * arg0) {
    (void) arg0;
}

extern "C" u8 fn_803461E8(char * arg0) {
    return *(u8 *) (arg0 + 0x54);
}

extern "C" void fn_803461F0(void * arg0) {
    (void) arg0;
}

extern "C" void fn_803462D8(DiagObj * arg0) {
    arg0->Init();
}

extern "C" void fn_80348610(void * arg0, void * arg1);

extern "C" void fn_80346304(void * arg0_, void * arg1) {
    char *arg0 = (char *) arg0_;
    u32 i;
    for (i = 0; i < *(u32 *) (arg0 + 0x74); i++) {
        fn_80348610((*(void ***) (arg0 + 0x78))[i], arg1);
    }
}

extern f32 lbl_805E4568;
extern "C" void fn_803475D0(void * arg0, void * arg1);
extern "C" void fn_80348E40(char * arg0, char * arg1);
extern "C" void fn_803470C8(void * arg0, void * arg1);

extern "C" void fn_80346378(void * arg0_, char * arg1) {
    char *arg0 = (char *) arg0_;
    if (*(f32 *) (arg1 + 0x3c) < lbl_805E4568) {
        fn_803475D0(*(void **) (arg0 + 0x88), arg1);
        u32 i;
        for (i = 0; i < *(u32 *) (arg0 + 0x80); i++) {
            fn_80348E40((char *) (*(void ***) (arg0 + 0x84))[i], arg1);
        }
        for (i = 0; i < *(u32 *) (arg0 + 0x68); i++) {
            fn_803470C8((*(void ***) (arg0 + 0x6c))[i], arg1);
        }
    }
}

extern "C" void fn_80347884(void * arg0, void * arg1);
extern "C" void fn_80348A48(void * arg0, void * arg1);
extern "C" void fn_80348F00(char * arg0, char * arg1);

extern "C" void fn_80346434(void * arg0_, void * arg1) {
    char *arg0 = (char *) arg0_;
    fn_80347884(*(void **) (arg0 + 0x88), arg1);
    u32 i;
    for (i = 0; i < *(u32 *) (arg0 + 0x74); i++) {
        fn_80348A48((*(void ***) (arg0 + 0x78))[i], arg1);
    }
    for (i = 0; i < *(u32 *) (arg0 + 0x80); i++) {
        fn_80348F00((char *) (*(void ***) (arg0 + 0x84))[i], (char *) arg1);
    }
}

extern "C" void * fn_803464E0(void * arg0, void * arg1, void * arg2, void * arg3, void * arg4, void * arg5, void * arg6, s32 arg7, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg5;
    (void) arg6;
    (void) arg7;
    (void) arg_sp0;
    return 0;
}

extern DiagObj *lbl_805DDC60;
extern f64 lbl_805E4570;
extern "C" u32 fn_80346768(void * arg0, s32 arg1);

extern "C" void fn_803466C8(void * arg0_) {
    char *arg0 = (char *) arg0_;
    *(s32 *) (arg0 + 0x14) = 0;
    *(u8 *) (arg0 + 0x24) = 0;
    HSD_ForeachAnim(*(void **) (*(char **) arg0 + 4), 6, 0xFFFF, (void *) HSD_AObjSetRate, 1, lbl_805E4570);
    u32 cond = lbl_805DDC60->v14();
    if (cond != 0) {
        fn_80346768(arg0, 0);
    } else {
        fn_80346768(arg0, 4);
    }
    *(u8 *) (arg0 + 0x34) = 0;
}

extern "C" u32 fn_80346768(void * arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_8034685C(void * arg0) {
    (void) arg0;
}

extern "C" void fn_80347098(DiagObj ** arg0) {
    (*arg0)->Init();
}

extern "C" void fn_803470C8(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_80347278(void * arg0);

extern "C" void * fn_803471C4(void * arg0_, void * arg1, void * arg2) {
    char *arg0 = (char *) arg0_;
    f32 zero = lbl_805E456C;
    *(void **) (arg0 + 0) = arg1;
    *(f32 *) (arg0 + 0xc) = zero;
    *(f32 *) (arg0 + 8) = zero;
    *(f32 *) (arg0 + 4) = zero;
    *(void **) (arg0 + 0x10) = arg2;
    kar_a2d_game_audio__near_80379398(arg0 + 0x24);
    char *jobj = *(char **) arg0;
    if (jobj == 0) {
        __assert(kar_srcfile_jobj_h_805db210, 0x3E4, lbl_805DB218);
    }
    if (arg0 + 4 == 0) {
        __assert(kar_srcfile_jobj_h_805db210, 0x3E5, lbl_804E9980);
    }
    *(f32 *) (arg0 + 4) = *(f32 *) (jobj + 0x38);
    *(f32 *) (arg0 + 8) = *(f32 *) (jobj + 0x3c);
    *(f32 *) (arg0 + 0xc) = *(f32 *) (jobj + 0x40);
    HSD_JObjRemoveAnimAll(jobj);
    fn_80347278(arg0);
    return arg0;
}

extern "C" void fn_80347278(void * arg0_) {
    char *arg0 = (char *) arg0_;
    f32 v = lbl_805E456C;
    *(s32 *) (arg0 + 0x18) = 0;
    *(f32 *) (arg0 + 0x20) = v;
    *(f32 *) (arg0 + 0x1c) = v;
}

extern "C" void fn_80347290(void * arg0) {
    (void) arg0;
}

extern "C" void fn_803475D0(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
}

#pragma dont_inline on
extern "C" void fn_80347884(void * arg0_, void * arg1_) {
    char *arg0 = (char *) arg0_;
    char *arg1 = (char *) arg1_;
    *(u8 *) (arg0 + 0x60) = *(u8 *) (arg1 + 0x60);
}
#pragma dont_inline off

extern "C" void fn_8034794C(void * arg0, void * arg1, void * arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void fn_80347B04(void * arg0_, f32 farg0) {
    char *arg0 = (char *) arg0_;
    *(f32 *) (arg0 + 0x1c) += farg0;
    u32 cond = ((DiagResult *) kar_diag__803ad760(lbl_805DDBC0, 0, &lbl_805DB1C0, &lbl_805DB1B8, 0))->unk14;
    void *result = (cond == 1) ? lbl_804E91EC : lbl_804E92B4;
    f32 clamp = *(f32 *) ((char *) result + 0x10);
    if (*(f32 *) (arg0 + 0x1c) > clamp) {
        *(f32 *) (arg0 + 0x1c) = clamp;
    }
    f32 negClamp = -clamp;
    if (*(f32 *) (arg0 + 0x1c) < negClamp) {
        *(f32 *) (arg0 + 0x1c) = negClamp;
    }
}

extern "C" void fn_80347C40(void * arg0);

extern "C" void * fn_80347B94(char * arg0, void * arg1, void * arg2) {
    f32 zero = lbl_805E456C;
    *(void **) (arg0 + 0) = arg1;
    *(f32 *) (arg0 + 0xc) = zero;
    *(f32 *) (arg0 + 8) = zero;
    *(f32 *) (arg0 + 4) = zero;
    *(void **) (arg0 + 0x10) = arg2;
    char *jobj = *(char **) arg0;
    if (jobj == 0) {
        __assert(kar_srcfile_jobj_h_805db210, 0x3E4, lbl_805DB218);
    }
    if (arg0 + 4 == 0) {
        __assert(kar_srcfile_jobj_h_805db210, 0x3E5, lbl_804E9980);
    }
    *(f32 *) (arg0 + 4) = *(f32 *) (jobj + 0x38);
    *(f32 *) (arg0 + 8) = *(f32 *) (jobj + 0x3c);
    *(f32 *) (arg0 + 0xc) = *(f32 *) (jobj + 0x40);
    HSD_JObjRemoveAnimAll(*(void **) arg0);
    fn_80347C40(arg0);
    return arg0;
}

#pragma dont_inline on
extern "C" void fn_80347C40(void * arg0) {
    (void) arg0;
}
#pragma dont_inline off

extern "C" void fn_80347C44(void * arg0) {
    (void) arg0;
}

extern "C" void * fn_80347D54(void * arg0, void * arg1, s32 arg2, void * arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    return 0;
}

extern "C" void fn_80347E28(void * arg0) {
    (void) arg0;
}

extern "C" void fn_80348024(void * arg0_) {
    char *arg0 = (char *) arg0_;
    *(u8 *) (arg0 + 0x6c) = 0;
    *(u8 *) (arg0 + 0x70) = 0;
    *(u32 *) (arg0 + 0x54) = 0;
    *(u8 *) (arg0 + 0x6d) = 0;
    *(u8 *) (arg0 + 0x71) = 0;
    *(u32 *) (arg0 + 0x58) = 0;
    *(u8 *) (arg0 + 0x6e) = 0;
    *(u8 *) (arg0 + 0x72) = 0;
    *(u32 *) (arg0 + 0x5c) = 0;
    *(u8 *) (arg0 + 0x6f) = 0;
    *(u8 *) (arg0 + 0x73) = 0;
    *(u32 *) (arg0 + 0x60) = 0;
    *(u32 *) (arg0 + 0x64) = 0;
}

extern "C" void fn_80348060(void * arg0) {
    (void) arg0;
}

#pragma dont_inline on
extern "C" void fn_80348610(void * arg0_, void * arg1_) {
    char *arg0 = (char *) arg0_;
    char *arg1 = (char *) arg1_;
    *(u8 *) (arg0 + 0x60) = *(u8 *) (arg1 + 0x60);
}
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_80348A48(void * arg0_, void * arg1_) {
    char *arg0 = (char *) arg0_;
    char *arg1 = (char *) arg1_;
    *(u8 *) (arg0 + 0x60) = *(u8 *) (arg1 + 0x60);
}
#pragma dont_inline off

extern "C" void fn_80348B10(void * arg0, void * arg1, void * arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern char lbl_804E9CA4[12];
extern "C" void fn_80348D2C(void * arg0);

extern "C" void * fn_80348CE4(void * arg0_, void * arg1, void * arg2, void * arg3) {
    char **arg0 = (char **) arg0_;
    arg0[0] = lbl_804E9CA4;
    arg0[1] = (char *) arg1;
    arg0[2] = (char *) arg2;
    arg0[3] = (char *) arg3;
    fn_80348D2C(arg0_);
    return arg0_;
}

extern "C" void fn_80348D2C(void * arg0) {
    (void) arg0;
}

extern "C" void fn_80348D30(void * arg0) {
    (void) arg0;
}

extern "C" u8 kar_fl_indirectload__80391f10(void *, void *);
extern "C" void kar_object__near_80348fb4(void *out, void *arg1);
extern "C" f32 PSVECMag(void *, f32, f32);
extern char lbl_805DB220[4];
typedef void (*VtabFn0xd4)(void *, void *);

extern "C" void fn_80348E40(char * arg0, char * arg1) {
    char *tmp = *(char **) (arg1 + 4);
    tmp = *(char **) (tmp + 4);
    char *namePtr = *(char **) (tmp + 12);
    char *name = *(char **) (namePtr - 4);
    if (name == 0) {
        name = lbl_805DB220;
    }
    u8 r = kar_fl_indirectload__80391f10(name, *(void **) (arg0 + 8));
    if (r != 0) {
        char *ptr = *(char **) (arg1 + 0x2c);
        if (ptr != 0) {
            f32 vec[3];
            kar_object__near_80348fb4(vec, arg0);
            f32 mag = PSVECMag(vec, vec[1], vec[2]);
            if (mag > lbl_805E456C) {
                VtabFn0xd4 fn = (VtabFn0xd4) (*(void ***) ptr)[53];
                fn(ptr, vec);
            }
        }
    }
}

#pragma dont_inline on
extern "C" void fn_80348F00(char * arg0, char * arg1) {
    char *tmp = *(char **) (arg1 + 4);
    tmp = *(char **) (tmp + 4);
    char *namePtr = *(char **) (tmp + 12);
    char *name = *(char **) (namePtr - 4);
    if (name == 0) {
        name = lbl_805DB220;
    }
    u8 r = kar_fl_indirectload__80391f10(name, *(void **) (arg0 + 8));
    if (r != 0) {
        f32 vec[3];
        kar_object__near_80348fb4(vec, arg0);
        f32 mag = PSVECMag(vec, vec[1], vec[2]);
        if (mag > lbl_805E456C) {
            *(f32 *) (arg1 + 0x38) = vec[0];
            *(f32 *) (arg1 + 0x3c) = vec[1];
            *(f32 *) (arg1 + 0x40) = vec[2];
        }
    }
}

#pragma dont_inline on
extern "C" void kar_object__near_80348fb4(void * arg0_, void * arg1_) {
    char *arg0 = (char *) arg0_;
    char *arg1 = (char *) arg1_;
    *(f32 *) arg0 = *(f32 *) (arg1 + 0x60);
}
#pragma dont_inline off

extern "C" void * kar_object__near_803490c0(void * arg0, void * arg2, void * arg2_1) {
    (void) arg0;
    (void) arg2;
    (void) arg2_1;
    return 0;
}

extern "C" f32 kar_object__near_80349534(f32 farg0) {
    (void) farg0;
    return 0.0f;
}

extern "C" f32 kar_object__near_80349980(f32 farg0, s32 f32) {
    (void) farg0;
    (void) f32;
    return 0.0f;
}

extern "C" void kar_object__near_80349ddc(void * arg0) {
    (void) arg0;
}

extern "C" void fn_8034A07C(void) {
}

extern "C" void fn_8034A080(void) {
}

extern "C" void fn_8034A084(void * arg0_, f32 * arg1) {
    char *arg0 = (char *) arg0_;
    f32 x = arg1[0];
    f32 y = arg1[1];
    *(f32 *) (arg0 + 0x38) = x;
    f32 z = arg1[2];
    *(f32 *) (arg0 + 0x3c) = y;
    *(f32 *) (arg0 + 0x40) = z;
}

extern "C" void * kar_object__near_8034a0a0(void * arg0, s16 arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
    return 0;
}

extern "C" void kar_object__near_8034a4e8(void * arg0, void * arg1, s32 arg_sp0, s32 s32) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
    (void) s32;
}

extern "C" void kar_object__near_8034a63c(void * arg0, void * arg1, void * arg2, void * arg3, void * arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
}

extern "C" void kar_object__8034a74c(void * arg0, void * arg1, void * arg2, void * arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
}

extern "C" void * kar_object__near_8034a8f4(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * kar_object__near_8034a9c0(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * kar_object__near_8034aabc(char * arg0) {
    u32 idx = *(u32 *) (arg0 + 0x900);
    char *slot = arg0 + idx * 0x60;
    *(u32 *) (arg0 + 0x900) = *(u32 *) slot;
    *(u32 *) (arg0 + 0x904) = *(u32 *) (arg0 + 0x904) - 1;
    return slot;
}

extern "C" void kar_object__near_8034aae4(char * arg0, char * arg1) {
    u32 idx = (u32) (arg1 - arg0) / 0x60;
    *(u32 *) arg1 = *(u32 *) (arg0 + 0x900);
    *(u32 *) (arg0 + 0x900) = idx;
    *(u32 *) (arg0 + 0x904) = *(u32 *) (arg0 + 0x904) + 1;
}

extern "C" void * kar_object__near_8034ab14(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void kar_object__near_8034ac50(void * arg0_, u32 arg1) {
    char *arg0 = (char *) arg0_;
    *(u16 *) (arg0 + 0xc) = arg1;
    *(u8 *) (arg0 + 0x3c) = 1;
    if (arg1 == 1) {
        *(u32 *) (arg0 + 0x40) |= 1;
    } else {
        *(u32 *) (arg0 + 0x40) &= ~1;
    }
}

extern "C" s32 kar_object__near_8034ac84(void * arg0_, f32 * arg2, f32 farg0) {
    char *arg0 = (char *) arg0_;
    *(f32 *) (arg0 + 0x14) = farg0;
    ((DiagObj *) (arg0 + 0x18))->v20();
    f32 a = arg2[0];
    s32 result = -1;
    f32 b = arg2[1];
    *(f32 *) (arg0 + 0x44) = a;
    f32 c = arg2[2];
    *(f32 *) (arg0 + 0x48) = b;
    *(f32 *) (arg0 + 0x4c) = c;
    if (*(u16 *) (arg0 + 0xc) == 0) {
        result = *(u16 *) (arg0 + 0xe);
    }
    *(u16 *) (arg0 + 0xe) = 0xFFFF;
    return result;
}

extern "C" void * TopRideItem_Create(void * arg0, u8 arg1, void * arg2, void * arg3, s16 arg4, u8 arg5, u8 arg6, f32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg5;
    (void) arg6;
    (void) arg_sp0;
    return 0;
}

#pragma dont_inline on
extern "C" void * kar_object__8034b37c(void * arg0_, void * arg1_) {
    char *arg0 = (char *) arg0_;
    char *arg1 = (char *) arg1_;
    *(u8 *) (arg0 + 0x60) = *(u8 *) (arg1 + 0x60);
    return arg0;
}
#pragma dont_inline off

extern "C" void * TopRideItem_MgrInit(void * arg0, s32 arg1, void * arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    return 0;
}

extern "C" void TopRideItem_SpawnTimed(void * arg0, s32 arg1, void * arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void TopRideItem_SpawnAtPosition(void * arg0, s32 arg1, void * arg4, void * arg5, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg4;
    (void) arg5;
    (void) arg_sp0;
}

extern "C" void TopRideItem_Update(void * arg0) {
    (void) arg0;
}

extern "C" s32 kar_object__near_8034c924(void * arg0_) {
    char *arg0 = (char *) arg0_;
    s32 result = 0;
    if (((*(u16 *) (arg0 + 0x62) == 0) && (kar_a2d_effecthandle__near_8037b61c(arg0 + 0x78) == 0))
        || (*(u8 *) (arg0 + 0x4c) != 0)) {
        result = 1;
    }
    return result;
}

extern "C" void kar_object__near_8034c988(void * arg0) {
    (void) arg0;
}

extern s32 lbl_805DDBA4;
extern void *lbl_805DB2C0;
extern void *lbl_805DB2B8;

extern "C" void kar_object__near_8034ca20(void * arg0_) {
    char *arg0 = (char *) arg0_;
    if (*(u8 *) (arg0 + 0x68) != 0 && *(u16 *) (arg0 + 0x64) == 0) {
        if (*(u16 *) (arg0 + 0x62) >= 120
            || (*(s32 *) ((char *) kar_diag__803ad760(lbl_805DDBA4, 0, &lbl_805DB2C0, &lbl_805DB2B8, 0) + 0x58) & 1)) {
            ((DiagObj *) (arg0 + 0x6c))->Init();
        }
    }
}

extern "C" s32 strncmp(char *, char *, s32);
extern char lbl_805DB33C[4];
extern char lbl_805DB340[7];

extern "C" s32 kar_object__near_8034caa4(char ** arg1) {
    char *s = *(arg1 - 1);
    if (s == 0) {
        s = lbl_805DB33C;
    }
    u32 r = (strncmp(s, lbl_805DB340, 1) == 0) ? 1 : 0;
    return r;
}

extern "C" f32 kar_object__near_8034cae8(void * arg0, f32 farg0, f32 farg1) {
    (void) arg0;
    (void) farg0;
    (void) farg1;
    return 0.0f;
}

extern "C" u32 fn_8034CD48(void * arg0_, s32 arg1) {
    (void) arg1;
    char *arg0 = (char *) arg0_;
    s32 count = *(s32 *) (arg0 + 4);
    u32 result = 1;
    arg0 = *(char **) arg0;
    s32 offset = 8;
    s32 i;
    for (i = 1; i < count; i++) {
        f32 a = *(f32 *) (arg0 + offset);
        f32 b = *(f32 *) (arg0 + offset - 8);
        if (a < b) {
            break;
        }
        offset += 8;
        result++;
    }
    return result;
}

extern "C" void fn_8034CD90(void * arg0, void * arg1, s32 arg_sp0, s32 s32, void * arg4) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
    (void) s32;
    (void) arg4;
}

extern "C" void TopRideItem_AddToList(void * arg0, void * arg1, void * arg2, void * arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void fn_8034CF48(void * arg0, void * arg1, void * arg2) {
    (void) arg0;
    if (arg1 != 0) {
        kar_object__8034b37c(arg1, arg2);
    }
}

extern "C" void * fn_8034CF78(void * arg0, void * arg1, void * arg2, void * arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    return 0;
}

extern "C" s32 fn_8034D044(void * arg0_, f32 farg0) {
    char *arg0 = (char *) arg0_;
    char *base = *(char **) (arg0 + 0);
    s32 count = *(s32 *) (arg0 + 4);
    s32 offset;
    char *ptr = base;
    s32 i;
    for (offset = 0, i = 0; i < count; i++) {
        if (i != 0) {
            f32 a = *(f32 *) (base + offset - 8);
            f32 b = *(f32 *) (base + offset);
            if (a > b) {
                break;
            }
        }
        f32 c = *(f32 *) ptr;
        if (c > farg0) {
            break;
        }
        offset += 8;
        ptr += 8;
    }
    return i - 1;
}

extern "C" void * fn_8034D0A4(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_8034D1D0(char * arg0) {
    u32 idx = *(u32 *) (arg0 + 0x4ec0);
    char *slot = arg0 + idx * 0xfc;
    *(u32 *) (arg0 + 0x4ec0) = *(u32 *) slot;
    *(u32 *) (arg0 + 0x4ec4) = *(u32 *) (arg0 + 0x4ec4) - 1;
    return slot;
}

extern "C" void * TopRideItem_GetDataBase(void) {
    return lbl_804EA548;
}

extern "C" void * TopRideItem_GetDataByIndex(s32 idx) {
    switch (idx) {
    case 0: return lbl_804EA548;
    case 1: return lbl_804EA548 + 0x54;
    case 2: return lbl_804EA548 + 0xa0;
    case 3: return lbl_804EA548 + 0xd0;
    case 4: return lbl_804EA548 + 0x108;
    case 5: return lbl_804EA548 + 0x160;
    case 6: return lbl_804EA548 + 0x198;
    case 7: return lbl_804EA548 + 0x1dc;
    case 8: return lbl_804EA548 + 0x250;
    case 9: return lbl_804EA548 + 0x2d4;
    case 10: return lbl_804EA548 + 0x318;
    case 11: return lbl_804EA548 + 0x36c;
    case 12: return lbl_804EA548 + 0x3b0;
    case 13: return lbl_804EA548 + 0x424;
    case 14: return lbl_804EA548 + 0x47c;
    case 15: return lbl_804EA548 + 0x4c0;
    case 16: return lbl_804EA548 + 0x4e4;
    case 17: return lbl_804EA548 + 0x520;
    case 18: return lbl_804EA548 + 0x568;
    case 19: return lbl_804EA548 + 0x5a0;
    case 20: return lbl_804EA548 + 0x5e0;
    case 21: return lbl_804EA548 + 0x604;
    }
}

extern "C" void fn_8034D384(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_8034DB38(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_8034E0FC(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_8034E4E4(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_8034E9A4(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_8034F1C4(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_8034F684(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_8034FC88(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_80350440(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_80350CFC(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_803511E8(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_80351AB4(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_803521D0(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_80352DFC(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_80353734(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_80353E50(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_8035420C(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_80354738(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_80354EC0(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_80355498(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_80355B48(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_80355F04(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_80356254(void * arg0) {
    (void) arg0;
}

extern "C" u64 fn_803567D4(void * arg0, void * arg1, u32 arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" u64 fn_8035691C(void * arg0, void * arg1, u32 arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_80356A68(void * arg0, s32 arg1, s32 arg2, s8 arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    return 0;
}

extern "C" void TopRideItem_PartyBallUpdate(void * arg0, u8 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_8035774C(void * arg0) {
    (void) arg0;
}

extern "C" void * fn_803577EC(void * arg0, s32 arg_sp0) {
    (void) arg0;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_803583B8(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void fn_803589F4(void * arg0_) {
    *(s32 *) arg0_ = 0;
}

extern "C" void * fn_80358A00(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_8035903C(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_80359678(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_80359CB4(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_8035A2F0(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_8035A92C(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_8035AF68(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_8035B5A4(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_8035BBE0(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_8035C21C(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_8035C858(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_8035CE94(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_8035D4D0(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_8035DB0C(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_8035E148(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_8035E784(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_8035EDC0(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_8035F3FC(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_8035FA38(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_80360074(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_803606B0(void * arg0, s32 arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_80360CEC(void * arg0, void * arg1, s32 arg2, void * arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
    return 0;
}

extern "C" void fn_80360F24(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void * fn_80361A7C(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80361F74(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_803624E8(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_803627B4(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80362AF8(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8036312C(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80363470(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8036396C(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80364440(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8036501C(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80365518(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8036590C(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80365C10(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_803668D4(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80366E0C(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80367110(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80367224(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_803675A8(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80367924(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80367B74(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80367F3C(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80368050(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_80368128(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80368130(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80368138(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80368140(void * arg0) {
    (void) arg0;
}

extern "C" s32 fn_803683A4(char * arg0) {
    u32 x = *(u16 *) (arg0 + 0x62);
    return x == 0 ? 1 : 0;
}

extern "C" void fn_803683B4(void * arg0) {
    (void) arg0;
}

extern "C" void * fn_80368560(void * arg0, void * arg1, u16 arg2, s8 arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    return 0;
}

extern "C" void fn_8036899C(void * arg0) {
    (void) arg0;
}

extern char lbl_805DB668[4];
extern char lbl_805DB66C[5];
extern char lbl_804EF9F4[14];
extern char lbl_804EFA04[11];

extern "C" void fn_80368BA0(void * arg0_, void * arg1_) {
    char *arg0 = (char *) arg0_;
    char *arg1 = (char *) arg1_;
    char *tmp = *(char **) (arg1 + 4);
    tmp = *(char **) (tmp + 4);
    char *namePtr = *(char **) (tmp + 12);
    char *name = *(char **) (namePtr - 4);
    if (name == 0) {
        name = lbl_805DB668;
    }
    if (strncmp(name, lbl_805DB66C, 1) == 0
        || strncmp(lbl_804EF9F4, name, 13) == 0
        || strncmp(lbl_804EFA04, name, 10) == 0) {
        *(u16 *) (arg0 + 0x62) = 0;
    }
}

extern "C" void kar_object__near_80368c48(void * arg0, void * arg1, s32 arg_sp0, s32 s32, void * arg4) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
    (void) s32;
    (void) arg4;
}

extern "C" void kar_object__near_80368d00(void * arg0, void * arg1, void * arg2, void * arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void * kar_object__near_80368de4(void * arg0, void * arg1);

extern "C" void kar_object__near_80368db4(void * arg1, void * arg2, void * arg2_1, void * arg3) {
    (void) arg1;
    if (arg2 != 0) {
        kar_object__near_80368de4(arg2, arg2_1);
    }
    (void) arg3;
}

#pragma dont_inline on
extern "C" void * kar_object__near_80368de4(void * arg0_, void * arg1_) {
    char *arg0 = (char *) arg0_;
    char *arg1 = (char *) arg1_;
    *(u8 *) (arg0 + 0x60) = *(u8 *) (arg1 + 0x60);
    return arg0;
}
#pragma dont_inline off

extern "C" void * kar_object__near_80369010(char * arg0) {
    u32 idx = *(u32 *) (arg0 + 0x4600);
    char *slot = arg0 + idx * 0x118;
    *(u32 *) (arg0 + 0x4600) = *(u32 *) slot;
    *(u32 *) (arg0 + 0x4604) = *(u32 *) (arg0 + 0x4604) - 1;
    return slot;
}

extern "C" void fn_80369038(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80369040(s32 arg0) {
    (void) arg0;
}

extern "C" void kar_object__near_80369048(void * arg0) {
    (void) arg0;
}

extern "C" s32 fn_803690D8(char * arg0) {
    u32 t = (*(u32 *) (arg0 + 0xf4) == 0) ? 1 : 0;
    if (t) {
        t = (*(u32 *) (arg0 + 0xe0) == 0) ? 1 : 0;
    }
    return t;
}

extern "C" void kar_object__near_80369100(void * arg0, s32 arg1, void * arg2, s16 arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void * kar_object__near_80369424(void * arg0, s32 arg1, void * arg2, s16 arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    return 0;
}

extern "C" void kar_object__near_803696c8(void * arg0) {
    (void) arg0;
}

extern "C" void kar_object__near_80369830(void * arg0, void * arg1, s32 arg_sp0, s32 s32, void * arg4) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
    (void) s32;
    (void) arg4;
}

extern "C" void kar_object__near_803698e8(void * arg0, void * arg1, void * arg2, void * arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
}

extern "C" void * kar_object__near_80369b14(char * arg0) {
    u32 idx = *(u32 *) (arg0 + 0x4000);
    char *slot = arg0 + idx * 0x100;
    *(u32 *) (arg0 + 0x4000) = *(u32 *) slot;
    *(u32 *) (arg0 + 0x4004) = *(u32 *) (arg0 + 0x4004) - 1;
    return slot;
}

extern "C" void * kar_object__near_80369b3c(void * arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void kar_object__near_80369c04(void * arg0) {
    (void) arg0;
}

extern "C" u8 fn_80369C94(char * arg0) {
    return *(u8 *) (arg0 + 0x7c);
}

extern "C" void kar_object__near_8036ab9c(char * arg0);

extern "C" void kar_object__near_80369c9c(void * arg0_) {
    char *arg0 = (char *) arg0_;
    char *cur = *(char **) (arg0 + 0x14);
    char *sentinel = arg0 + 0x10;
    while (cur != sentinel) {
        kar_object__near_8036ab9c(cur + 8);
        cur = *(char **) (cur + 4);
    }
}

extern "C" void kar_object__near_80369ce8(void * arg0, void * arg3) {
    (void) arg0;
    (void) arg3;
}

extern "C" void * kar_object__near_80369d5c(void * arg0, void * arg1, s32 arg2, void * arg3, void * arg4, s16 arg5) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg5;
    return 0;
}

#pragma dont_inline on
extern "C" void * kar_object__8036a408(void * arg0_, void * arg1_) {
    char *arg0 = (char *) arg0_;
    char *arg1 = (char *) arg1_;
    *(u8 *) (arg0 + 0x60) = *(u8 *) (arg1 + 0x60);
    return arg0;
}
#pragma dont_inline off

extern "C" void kar_object__near_8036a89c(void * arg0) {
    (void) arg0;
}

extern "C" void kar_object__near_8036ac00(void * arg0);

extern "C" void kar_object__near_8036ab9c(char * arg0) {
    if (*(u16 *) (arg0 + 0x7e) == 0) {
        ((DiagObj *) (arg0 + 0x6c))->Init();
    }
}

extern "C" void kar_object__near_8036abd4(char * arg0) {
    if (*(u16 *) (arg0 + 0x7e) == 0) {
        kar_object__near_8036ac00(arg0);
    }
}

extern "C" void kar_object__near_8036ac00(void * arg0) {
    (void) arg0;
}

extern "C" void kar_object__near_8036ad58(void * arg0, void * arg1, s32 arg_sp0, s32 s32, void * arg4) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
    (void) s32;
    (void) arg4;
}

extern "C" void kar_object__near_8036ae5c(void * arg0, void * arg1, void * arg2, void * arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void kar_object__near_8036af10(void * arg1, void * arg2, void * arg2_1, void * arg3) {
    (void) arg1;
    if (arg2 != 0) {
        kar_object__8036a408(arg2, arg2_1);
    }
    (void) arg3;
}

extern "C" void * kar_object__near_8036af40(void * arg0, void * arg1, void * arg2, void * arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    return 0;
}

extern "C" void * kar_object__near_8036b00c(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * kar_object__near_8036b0b8(char * arg0) {
    u32 idx = *(u32 *) (arg0 + 0x6600);
    char *slot = arg0 + idx * 0x198;
    *(u32 *) (arg0 + 0x6600) = *(u32 *) slot;
    *(u32 *) (arg0 + 0x6604) = *(u32 *) (arg0 + 0x6604) - 1;
    return slot;
}

extern "C" void fn_8036B0E0(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_8036B0E8(s32 arg0) {
    (void) arg0;
}

extern "C" void kar_object__near_8036b0f0(void * arg0) {
    (void) arg0;
}

extern "C" u8 fn_8036B180(char * arg0) {
    return *(u8 *) (arg0 + 0xb4);
}

extern "C" void kar_object__near_8036b188(void * arg0_) {
    char *arg0 = (char *) arg0_;
    char *cur = *(char **) (arg0 + 0x14);
    char *sentinel = arg0 + 0x10;
    while (cur != sentinel) {
        ((DiagObj *) (cur + 0xb0))->Init();
        cur = *(char **) (cur + 4);
    }
}

extern "C" void * kar_object__near_8036b1e0(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * kar_object__8036b714(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void kar_object__near_8036b9a4(void * arg0) {
    (void) arg0;
}

extern "C" void PSVECSubtract(void *, void *, void *);
extern char lbl_805DB808[4];
extern char lbl_805DB80C[5];
extern char lbl_804F0334[14];
extern char lbl_804F0344[11];

extern "C" void kar_object__near_8036be48(void * arg0_, void * arg1_) {
    char *arg0 = (char *) arg0_;
    char *arg1 = (char *) arg1_;
    char *tmp = *(char **) (arg1 + 4);
    tmp = *(char **) (tmp + 4);
    char *namePtr = *(char **) (tmp + 12);
    char *name = *(char **) (namePtr - 4);
    if (name == 0) {
        name = lbl_805DB808;
    }
    if (strncmp(name, lbl_805DB80C, 1) == 0) {
        *(u8 *) (arg0 + 0xb4) = 1;
    } else if (strncmp(lbl_804F0334, name, 13) == 0
               || strncmp(lbl_804F0344, name, 10) == 0) {
        PSVECSubtract(arg0 + 0x2c, arg0 + 0x40, arg0 + 0x2c);
    }
}

extern "C" s32 fn_8036BF04(void) {
    return 0;
}

extern "C" void kar_object__near_8036bf0c(void * arg0, void * arg1, s32 arg_sp0, s32 s32, void * arg4) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
    (void) s32;
    (void) arg4;
}

extern "C" void fn_8036BFC4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_8036BFCC(s32 arg0) {
    (void) arg0;
}

extern "C" void kar_object__near_8036bfd4(void * arg0) {
    (void) arg0;
}

extern "C" u8 fn_8036C064(char * arg0) {
    return *(u8 *) (arg0 + 0x70);
}

extern "C" void kar_object__near_8036c06c(void * arg0_) {
    char *arg0 = (char *) arg0_;
    char *cur = *(char **) (arg0 + 0x14);
    char *sentinel = arg0 + 0x10;
    while (cur != sentinel) {
        if (*(u16 *) (cur + 0x82) == 0) {
            ((DiagObj *) (cur + 0x6c))->Init();
        }
        cur = *(char **) (cur + 4);
    }
}

extern "C" void * kar_object__near_8036c0d0(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * kar_object__8036c7dc(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void kar_object__near_8036cc04(void * arg0) {
    (void) arg0;
}
