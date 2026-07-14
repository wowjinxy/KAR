#include <dolphin/types.h>

extern "C" {
#include <global.h>
}

#define FU8(p, o) (*(u8 *) ((char *) (p) + (o)))
#define FS8(p, o) (*(s8 *) ((char *) (p) + (o)))
#define FU16(p, o) (*(u16 *) ((char *) (p) + (o)))
#define FS16(p, o) (*(s16 *) ((char *) (p) + (o)))
#define FU32(p, o) (*(u32 *) ((char *) (p) + (o)))
#define FS32(p, o) (*(s32 *) ((char *) (p) + (o)))
#define FF32(p, o) (*(f32 *) ((char *) (p) + (o)))
#define FP(p, o) (*(void **) ((char *) (p) + (o)))

class VDispatch5 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

class VDispatch8 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

class VDispatch8R {
public:
    virtual void *v0();
    virtual void *v1();
    virtual void *v2();
    virtual void *v3();
    virtual void *v4();
    virtual void *v5();
    virtual void *v6();
    virtual void *v7();
};

class VDispatch1I {
public:
    virtual void v0(s32);
};

extern "C" {
extern const f32 lbl_805E3310;
extern const f32 lbl_805E3358;
extern const f32 lbl_805E335C;
extern const f32 lbl_805E336C;
extern void *lbl_805D7610;
void kar_gmmain__near_80006c38(void);
void kar_gmlanmenu__near_80052fb8(void);
void kar_a2d_effecthandle__near_8037cfec(void);
void fn_8029CF8C(void * arg0);
void *kar_diag__803ad760(s32, s32, void *, void *, s32);
extern char lbl_805D7498[8];
extern char lbl_805D74A0[8];
extern char lbl_805D74C0[8];
extern char lbl_805D74D0[8];
extern char lbl_805D7518[8];
extern char lbl_805D7598[8];
extern char lbl_805D7618[8];
extern char lbl_805D7620[8];
extern char lbl_805D7628[8];
extern char lbl_805D7630[8];
extern char lbl_805D7638[8];
extern char lbl_805D7640[8];
extern char lbl_805D7648[8];
extern char lbl_805D7650[8];
extern char lbl_805D7688[8];
extern char lbl_805D7690[8];
extern char lbl_805D76B0[8];
extern char lbl_805D76B8[8];
extern char lbl_805D76C0[8];
extern char lbl_805D76C8[8];
extern char lbl_805D76D0[8];
extern char lbl_805D76D8[8];
extern char lbl_805D7760[8];
extern char lbl_805D7768[8];
extern char lbl_805D7770[8];
extern char lbl_805D7778[8];
extern char lbl_805D7790[8];
extern char lbl_805D7798[8];
extern char lbl_805D77A0[8];
extern char lbl_805D77A8[8];
extern char lbl_805D77B0[8];
extern char lbl_805D77B8[8];
extern char lbl_805D77C0[8];
extern char lbl_805D77C8[8];
extern char lbl_805D77D0[8];
extern char lbl_805D77D8[8];
extern char lbl_805D7A04[8];
extern char lbl_805D7A0C[8];
extern char lbl_805D7A1C[8];
extern char lbl_805D7A2C[8];
extern char lbl_805D7A34[8];
extern char lbl_805D7A3C[8];
extern char lbl_805D7A44[8];
extern char lbl_805D7A4C[8];
extern char lbl_805D7A54[8];
extern char lbl_805D7A5C[8];
extern char lbl_805D7A64[8];
extern char lbl_805D7A6C[8];
extern char lbl_805D7A7C[8];
extern char lbl_805D7A84[8];
extern char lbl_805D7AA4[8];
extern char lbl_805D7AAC[8];
extern char lbl_805D7AEC[8];
extern char lbl_805D7AF4[8];
extern char lbl_805D7B04[8];
extern char lbl_805D7B0C[8];
extern char lbl_805D7B14[8];
extern char lbl_805D7B1C[8];
extern char lbl_805D7C94[8];
extern char lbl_805D7C9C[8];
extern char lbl_805D7CA4[8];
extern char lbl_805D7CAC[8];
extern char lbl_805D7CC4[8];
extern char lbl_805D7CCC[8];
void fn_8038CB78(void * arg0);
}

extern "C" {
extern char lbl_804BC338[0xC];
extern char lbl_804BCDD8[0xC];
extern char lbl_804BCDF0[0xC];
extern char lbl_804BCE4C[0xC];
extern char lbl_804BCE74[0xC];
extern char lbl_804BCEC0[0xC];
extern char lbl_804BCEE8[0xC];
extern char lbl_804BCF14[0xC];
extern char lbl_804BCF3C[0xC];
extern char lbl_804BCF64[0xC];
extern char lbl_804BCF90[0xC];
extern char lbl_804BCFEC[0xC];
extern char lbl_804BD048[0xC];
extern char lbl_804BD074[0xC];
extern char lbl_804BD0A4[0xC];
extern char lbl_804BD100[0xC];
extern char lbl_804BD15C[0xC];
extern char lbl_804BD1B8[0xC];
extern char lbl_804BD1E8[0xC];
extern char lbl_804BD20C[0xC];
extern char lbl_804BD298[0xC];
extern char lbl_804BD3A4[0xC];
extern char lbl_804BD3EC[0xC];
extern char lbl_804BD434[0xC];
extern char lbl_804BD458[0xC];
extern char lbl_804BD47C[0xC];
extern char lbl_804BD4A0[0xC];
extern char lbl_804BD4C0[0xC];
extern char lbl_804BD4E4[0xC];
extern char lbl_804BD504[0xC];
extern char lbl_804BD528[0xC];
extern char lbl_804BD548[0xC];
extern char lbl_804BD560[0xC];
extern char lbl_804BD56C[0xC];
extern char lbl_804BD578[0xC];
extern char lbl_804BD598[0xC];
extern char lbl_804BD5BC[0xC];
extern char lbl_804BD5C8[0xC];
extern char lbl_804BDEA0[0xC];
extern char lbl_804BDEC0[0xC];
extern char lbl_804BDEE4[0xC];
extern char lbl_804BDF04[0xC];
extern char lbl_804BDFD8[0xC];
extern char lbl_804BE000[0xC];
extern char lbl_804BE078[0xC];
extern char lbl_804BE0A0[0xC];
extern char lbl_804BE260[0xC];
extern char lbl_804BE26C[0xC];
extern char lbl_804BE2B4[0xC];
extern char lbl_804BE2F8[0xC];
extern char lbl_804BE304[0xC];
extern char lbl_804BE348[0xC];
extern char lbl_804BE354[0xC];
extern char lbl_804BE3A4[0xC];
extern char lbl_804BE3BC[0xC];
extern char lbl_804BE400[0xC];
extern char lbl_804BE40C[0xC];
extern char lbl_804BE454[0xC];
extern char lbl_804C04D4[0xC];
extern s32 lbl_805DDB34;
extern s32 lbl_805DDB38;
extern s32 lbl_805DDB3C;
extern s32 lbl_805DDB40;
extern s32 lbl_805DDB44;
extern s32 lbl_805DDB48;
extern s32 lbl_805DDB4C;
extern s32 lbl_805DDB50;
extern s32 lbl_805DDB54;
extern s32 lbl_805DDB58;
extern s32 lbl_805DDB5C;
extern s32 lbl_805DDB60;
extern s32 lbl_805DDB64;
extern s32 lbl_805DDB68;
extern s32 lbl_805DDB6C;
extern s32 lbl_805DDB70;
extern s32 lbl_805DDB74;
extern s32 lbl_805DDB78;
extern s32 lbl_805DDB7C;
extern s32 lbl_805DDB80;
extern s32 lbl_805DDB84;
extern s32 lbl_805DDB88;
extern s32 lbl_805DDB8C;
extern s32 lbl_805DDB90;
extern s32 lbl_805DDB94;
extern s32 lbl_805DDB98;
extern s32 lbl_805DDB9C;
extern s32 lbl_805DDBA0;
extern s32 lbl_805DDBA4;
extern s32 lbl_805DDBA8;
extern s32 lbl_805DDBAC;
extern s32 lbl_805DDBB0;
extern s32 lbl_805DDBB8;
extern s32 lbl_805DDBC0;
extern s32 lbl_805DDBC4;
extern s32 lbl_805DDBD0;
extern s32 lbl_805DDBD4;
extern s32 lbl_805DDBD8;
extern s32 lbl_805DDBDC;
extern s32 lbl_805DDBE0;
extern s32 lbl_805DDBE4;
extern s32 lbl_805DDBE8;
extern s32 lbl_805DDBEC;
}

extern "C" {
extern char lbl_804BC1D8[0x28];
extern char lbl_804BC344[0x30];
extern char lbl_804BD658[0x28];
extern char lbl_804BD6D4[0x28];
extern char lbl_804BD724[0x28];
extern char lbl_804BD7B4[0x28];
extern char lbl_804BD820[0x28];
extern char lbl_804BD848[0x28];
extern char lbl_804BD934[0x28];
extern char lbl_804BDABC[0x28];
extern char lbl_804BDB4C[0x28];
extern char lbl_804BDBC0[0x28];
extern char lbl_804BDCBC[0x28];
extern char lbl_804BDD30[0x28];
extern char lbl_804BDD98[0x28];
extern char lbl_804BDE38[0x28];
extern char lbl_804BDF2C[0x28];
extern char lbl_804BE0C4[0x28];
extern char lbl_804BE1B0[0x28];
extern char lbl_804BE238[0x28];
extern char lbl_804BEFE4[0x28];
extern char lbl_804BF078[0x28];
extern char lbl_804BF0E4[0x28];
extern char lbl_804BF238[0x28];
extern char lbl_804BF2B4[0x28];
extern char lbl_804BF2DC[0x28];
extern char lbl_804BF398[0x28];
extern char lbl_804BF48C[0x28];
extern char lbl_804BF4B4[0x28];
extern char lbl_804BF4DC[0x28];
extern char lbl_804BF504[0x28];
}

extern "C" {
extern void *lbl_805DD9BC;
extern void *lbl_805DD9C0;
extern void *lbl_805DD9C8;
extern void *lbl_805DD9CC;
extern void *lbl_805DD9D4;
extern void *lbl_805DD9D8;
extern void *lbl_805DD9E0;
extern void *lbl_805DD9E4;
extern void *lbl_805DD9EC;
extern void *lbl_805DD9F0;
extern void *lbl_805DD9F8;
extern void *lbl_805DD9FC;
extern void *lbl_805DDA04;
extern void *lbl_805DDA08;
extern void *lbl_805DDA10;
extern void *lbl_805DDA14;
extern void *lbl_805DDA1C;
extern void *lbl_805DDA20;
extern void *lbl_805DDA28;
extern void *lbl_805DDA2C;
extern void *lbl_805DDA34;
extern void *lbl_805DDA38;
extern void *lbl_805DDA40;
extern void *lbl_805DDA44;
extern void *lbl_805DDA4C;
extern void *lbl_805DDA50;
extern void *lbl_805DDA58;
extern void *lbl_805DDA5C;
extern void *lbl_805DDA64;
extern void *lbl_805DDA68;
extern void *lbl_805DDA70;
extern void *lbl_805DDA74;
extern void *lbl_805DDA7C;
extern void *lbl_805DDA80;
extern void *lbl_805DDA88;
extern void *lbl_805DDA8C;
extern void *lbl_805DDA94;
extern void *lbl_805DDA98;
extern void *lbl_805DDAA0;
extern void *lbl_805DDAA4;
extern void *lbl_805DDAAC;
extern void *lbl_805DDAB0;
extern void *lbl_805DDAB8;
extern void *lbl_805DDABC;
extern void *lbl_805DDAC4;
extern void *lbl_805DDAC8;
extern void *lbl_805DDAD0;
extern void *lbl_805DDAD4;
extern void *lbl_805DDADC;
extern void *lbl_805DDAE0;
extern void *lbl_805DDAE8;
extern void *lbl_805DDAEC;
extern void *lbl_805DDAF4;
extern void *lbl_805DDAF8;
extern void *lbl_805DDB00;
extern void *lbl_805DDB04;
extern void *lbl_805DDB0C;
extern void *lbl_805DDB10;
extern void *lbl_805DDB18;
extern void *lbl_805DDB1C;
extern void *lbl_805DDB24;
extern void *lbl_805DDB28;
extern s32 lbl_805DD9B8;
extern s32 lbl_805DD9C4;
extern s32 lbl_805DD9D0;
extern s32 lbl_805DD9DC;
extern s32 lbl_805DD9E8;
extern s32 lbl_805DD9F4;
extern s32 lbl_805DDA00;
extern s32 lbl_805DDA0C;
extern s32 lbl_805DDA18;
extern s32 lbl_805DDA24;
extern s32 lbl_805DDA30;
extern s32 lbl_805DDA3C;
extern s32 lbl_805DDA48;
extern s32 lbl_805DDA54;
extern s32 lbl_805DDA60;
extern s32 lbl_805DDA6C;
extern s32 lbl_805DDA78;
extern s32 lbl_805DDA84;
extern s32 lbl_805DDA90;
extern s32 lbl_805DDA9C;
extern s32 lbl_805DDAA8;
extern s32 lbl_805DDAB4;
extern s32 lbl_805DDAC0;
extern s32 lbl_805DDACC;
extern s32 lbl_805DDAD8;
extern s32 lbl_805DDAE4;
extern s32 lbl_805DDAF0;
extern s32 lbl_805DDAFC;
extern s32 lbl_805DDB08;
extern s32 lbl_805DDB14;
extern s32 lbl_805DDB20;
}

extern "C" {
extern char lbl_804BC430[0x24];
extern char lbl_804BD254[0x1C];
extern char lbl_804BE658[0x1C];
extern char lbl_804BE6B4[0x1C];
extern char lbl_804BE710[0x1C];
extern char lbl_804BE76C[0x1C];
extern char lbl_804BE7C8[0x1C];
extern char lbl_804BE824[0x1C];
extern char lbl_804BE880[0x1C];
extern char lbl_804BE8E0[0x1C];
extern char lbl_804BE940[0x1C];
extern char lbl_804BE9A0[0x1C];
extern char lbl_804BEA00[0x1C];
extern char lbl_804BEA60[0x1C];
extern char lbl_804BEAC0[0x1C];
extern char lbl_804BEB2C[0x1C];
extern char lbl_804BEB80[0x1C];
extern char lbl_804BEBD4[0x1C];
extern char lbl_804BEC28[0x1C];
extern char lbl_804BEC7C[0x1C];
extern char lbl_804BECD0[0x1C];
extern char lbl_804BED24[0x1C];
extern char lbl_804BED78[0x1C];
extern char lbl_804BEDD4[0x1C];
extern char lbl_804BEE30[0x1C];
extern char lbl_804BEE8C[0x1C];
extern char lbl_804BEEE8[0x1C];
extern char lbl_804BEF44[0x1C];
extern char lbl_804BEFA0[0x1C];
extern char lbl_804BF99C[0x18];
extern char lbl_804BF9DC[0x14];
extern char lbl_804BFA40[0x18];
extern char lbl_804BFA54[0x1C];
extern char lbl_804F1134[0x28];
extern char lbl_804F5078[0x18];
extern char lbl_804BC3BC[0x20];
extern char lbl_804BC454[0x10];
extern char lbl_804BE14C[0xC];
extern char lbl_804BD614[0xC];
extern char lbl_804D1A98[0x80];
extern char lbl_804BCE40[0xC];
extern char lbl_804BCE14[0x2C];
extern char lbl_804BDB74[0x28];
extern char lbl_804BF3C0[0x30];
extern char lbl_804BFB00[0x30];
extern char lbl_804C0470[0x20];
extern char lbl_804C4B00[0xC];
extern char lbl_804BE5FC[0x1C];
extern char lbl_804F120C[0x1C];
}

extern "C" void * kar_a2d_game_lib__near_80287d58(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BC1D8;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" {
extern char lbl_804BC200[0x28];
}

extern "C" void * kar_a2d_game_lib__near_80287dc0(void * arg0, s16 arg1) {
    if (!arg0) goto ret;
    *(void **) arg0 = (void *) &lbl_804BC200;
    if (!arg0) goto after_ctor;
    *(void **) arg0 = (void *) &lbl_804BC1D8;
    ((VDispatch8 *) arg0)->v5();
after_ctor:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
ret:
    return arg0;
}

extern "C" void kar_a2d_game_lib__near_80287e38(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void kar_a2d_game_lib__near_80288500(void * arg0, void * arg1);

extern "C" void kar_a2d_game_lib__near_80287e84(void * arg0, void * arg1) {
    kar_a2d_game_lib__near_80288500((char *) arg0 + 16, arg1);
}

extern "C" void kar_a2d_game_lib__near_80287ea8(void * arg0) {
    (void) arg0;
}

extern "C" void * kar_a2d_game_lib__near_80287ef8(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void ** kar_a2d_game_lib__near_80288054(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BC338;
        lbl_805DDBB8 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * kar_a2d_game_lib__near_802880a4(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BC344;
        ((VDispatch8 *) arg0)->v3();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" {
extern char lbl_804BC374[0x28];
}

extern "C" void * kar_a2d_game_lib__near_8028810c(void * arg0, s16 arg1) {
    if (!arg0) goto ret;
    *(void **) arg0 = (void *) &lbl_804BC374;
    if (!arg0) goto after_ctor;
    *(void **) arg0 = (void *) &lbl_804BC344;
    ((VDispatch8 *) arg0)->v3();
after_ctor:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
ret:
    return arg0;
}

extern "C" void ** kar_a2d_game_lib__near_80288184(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BC3BC;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * kar_a2d_game_lib__near_802881cc(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void *** kar_a2d_game_lib__near_80288284(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BC430;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" s32 fn_802882CC(void * arg0, s32 arg1) {
    (void) arg0;
    return arg1;
}

extern "C" void *** kar_a2d_game_lib__near_802882d4(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BC454;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_8028831C(void) {

}

extern "C" void kar_a2d_game_lib__near_80288320(void * arg0) {
    (void) arg0;
}

extern "C" void * kar_a2d_game_lib__near_802883b4(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_802884EC(void * arg0) {
    u32 x = FU32(arg0, 0x4);
    return (s32) (((u32) (-(s32) x | x)) >> 31);
}

extern "C" void kar_a2d_game_lib__near_80288500(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void * kar_a2d_game_lib__near_80288534(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void kar_a2d_game_lib__near_802885e8(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x10), 0, &lbl_805D74D0, &lbl_805D74C0, 0);
}

extern "C" void kar_a2d_game_lib__near_8028861c(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x14), 0, &lbl_805D74D0, &lbl_805D74C0, 0);
}

extern "C" void kar_a2d_game_lib__near_80288650(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D74D0, &lbl_805D74C0, 0);
}

extern "C" void kar_a2d_game_lib__near_80288684(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D74D0, &lbl_805D74C0, 0);
}

extern "C" void kar_a2d_game_lib__near_802886b8(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0xC), 0, &lbl_805D74D0, &lbl_805D74C0, 0);
}

extern "C" s32 fn_802886EC(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDAA0 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_80288720(void * arg0) {
    if (lbl_805DDAA0 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDAA0;
        *(void **) ((char *) lbl_805DDAA0 + 0x4) = arg0;
        lbl_805DDAA0 = arg0;
    } else {
        lbl_805DDAA4 = arg0;
        lbl_805DDAA0 = arg0;
    }
    lbl_805DDA9C = lbl_805DDA9C + 1;
}

extern "C" void fn_80288758(void * arg0) {
    if (lbl_805DDAA0 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDAA4;
        *(void **) ((char *) lbl_805DDAA4 + 0x8) = arg0;
        lbl_805DDAA4 = arg0;
    } else {
        lbl_805DDAA4 = arg0;
        lbl_805DDAA0 = arg0;
    }
    lbl_805DDA9C = lbl_805DDA9C + 1;
}

extern "C" void kar_a2d_game_lib__near_80288794(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDAA0 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDAA4 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDA9C = lbl_805DDA9C - 1;
}

extern "C" void kar_a2d_game_lib__near_80288810(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7518, &lbl_805D7598, 0);
}

extern "C" void kar_a2d_game_lib__near_80288844(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7518, &lbl_805D7598, 0);
}

extern "C" s32 fn_80288878(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDAAC == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_802888AC(void * arg0) {
    if (lbl_805DDAAC != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDAAC;
        *(void **) ((char *) lbl_805DDAAC + 0x4) = arg0;
        lbl_805DDAAC = arg0;
    } else {
        lbl_805DDAB0 = arg0;
        lbl_805DDAAC = arg0;
    }
    lbl_805DDAA8 = lbl_805DDAA8 + 1;
}

extern "C" void fn_802888E4(void * arg0) {
    if (lbl_805DDAAC != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDAB0;
        *(void **) ((char *) lbl_805DDAB0 + 0x8) = arg0;
        lbl_805DDAB0 = arg0;
    } else {
        lbl_805DDAB0 = arg0;
        lbl_805DDAAC = arg0;
    }
    lbl_805DDAA8 = lbl_805DDAA8 + 1;
}

extern "C" void kar_a2d_game_lib__near_80288920(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDAAC = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDAB0 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDAA8 = lbl_805DDAA8 - 1;
}

extern "C" void kar_a2d_game_lib__near_8028899c(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D74A0, &lbl_805D7498, 0);
}

extern "C" f32 kar_a2d_game_lib__near_802889d0(f32 * arg0, f32 * arg1, f32 farg0) {
    return arg1[0] * farg0 + arg0[0] * (lbl_805E3310 - farg0);
}

extern "C" void * kar_a2d_game_lib__near_802889ec(void * arg0, void ** arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
    return 0;
}

extern "C" void kar_diagnostic__80288bd0(void * arg0);

extern "C" void * kar_a2d_game_lib__near_80288ad4(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        kar_diagnostic__80288bd0(arg0);
        if (FP(arg0, 8) != 0) {
            fn_8038CB78(FP(arg0, 8));
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void kar_a2d_game_lib__near_80288b34(void * arg0) {
    (void) arg0;
}

extern "C" void kar_diagnostic__80288bd0(void * arg0) {
    (void) arg0;
}

extern "C" void * kar_a2d_game_lib__near_80288c48(void * arg0, s32 arg1, u8 arg2, u8 arg3, void ** arg4, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg_sp0;
    return 0;
}

extern "C" void kar_diagnostic__80288d60(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void kar_a2d_game_lib__near_80288f50(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void kar_a2d_game_lib__near_80288fd0(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_80289050(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80289058(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80289060(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80289068(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80289070(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80289078(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80289080(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80289088(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80289090(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80289098(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802890A0(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802890A8(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802890B0(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802890B8(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802890C0(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802890C8(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802890D0(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802890D8(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802890E0(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802890E8(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802890F0(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802890F8(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80289100(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80289108(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80289110(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80289118(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80289120(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80289128(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_80289130(s32 arg0) {
    (void) arg0;
}

extern "C" void kar_a2d_gamesession__80289138(void) {
    kar_gmmain__near_80006c38();
}

extern "C" s32 kar_a2d_game_lib__near_80289158(s32 arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void kar_a2d_game_lib__near_802891c8(void * arg0, void * arg1, s32 arg2, f32 farg0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) farg0;
}

extern "C" s32 kar_a2d_game_lib__near_80289374(s32 arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void kar_a2d_game_lib__802894bc(s32 arg0, void * arg1, s32 arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" {
void HSD_AObjReqAnim(void *, f32);
void HSD_ForeachAnim(void *, s32, u32, void *, s32, ...);
}

extern "C" void kar_a2d_game_lib__near_80289590(void * arg0, u32 arg1, f32 farg0) {
    HSD_ForeachAnim(arg0, 6, arg1, (void *) &HSD_AObjReqAnim, 1, farg0);
}

extern "C" {
void HSD_AObjSetFlags(void *, u32);
void HSD_AObjClearFlags(void *, u32);
void HSD_AObjSetRewindFrame(void *, f32);
void HSD_AObjSetEndFrame(void *, f32);
}

extern "C" void kar_a2d_game_lib__near_802895c8(void * arg0, u32 arg1, f32 farg0, f32 farg1) {
    HSD_ForeachAnim(arg0, 6, arg1, (void *) &HSD_AObjClearFlags, 3, 0x20000000);
    HSD_ForeachAnim(arg0, 6, arg1, (void *) &HSD_AObjSetRewindFrame, 1, farg0);
    HSD_ForeachAnim(arg0, 6, arg1, (void *) &HSD_AObjSetEndFrame, 1, farg1);
}

extern "C" void kar_a2d_game_lib__near_8028967c(void * arg0, u32 arg1, f32 farg0, f32 farg1) {
    HSD_ForeachAnim(arg0, 6, arg1, (void *) &HSD_AObjSetFlags, 3, 0x20000000);
    HSD_ForeachAnim(arg0, 6, arg1, (void *) &HSD_AObjSetRewindFrame, 1, farg0);
    HSD_ForeachAnim(arg0, 6, arg1, (void *) &HSD_AObjSetEndFrame, 1, farg1);
}

extern "C" {
void HSD_AObjSetCurrentFrame(void *, f32);
void HSD_AObjSetRate(void *, f32);
}

extern "C" void kar_a2d_game_lib__near_80289730(void * arg0, u32 arg1, f32 farg0) {
    HSD_ForeachAnim(arg0, 6, arg1, (void *) &HSD_AObjSetCurrentFrame, 1, farg0);
}

extern "C" void kar_a2d_game_lib__near_80289768(void * arg0, u32 arg1, f32 farg0) {
    HSD_ForeachAnim(arg0, 6, arg1, (void *) &HSD_AObjSetRate, 1, farg0);
}

extern "C" void kar_a2d_game_lib__near_802897a0(void * arg0, s32 * arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" u8 kar_a2d_game_lib__near_802897e0(void) {
    return 0;
}

extern "C" void kar_a2d_game_lib__near_80289834(void * arg0, s32 * arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" s32 kar_a2d_game_lib__near_80289874(void) {
    return 0;
}

extern "C" void kar_a2d_game_lib__near_802898cc(s32 * arg0, f32 * arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" f32 kar_a2d_game_lib__near_80289928(void) {
    return 0.0f;
}

extern "C" void kar_a2d_game_lib__near_80289974(s32 * arg0, f32 * arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" f32 kar_a2d_game_lib__near_802899d0(void) {
    return 0.0f;
}

extern "C" void * kar_a2d_game_lib__near_80289a1c(void * arg0, void * arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * kar_a2d_game_lib__near_80289d64(void * arg0) {
    void *v = *(void **) ((char *) arg0 - 0x4);
    if (v != 0) {
        return v;
    }
    return &lbl_805D7610;
}

extern "C" void * kar_a2d_game_lib__near_80289d78(void * arg0, void * arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * kar_a2d_game_lib__near_8028a10c(void * arg0) {
    void *v = *(void **) ((char *) arg0 - 0x4);
    if (v != 0) {
        return v;
    }
    return &lbl_805D7610;
}

extern "C" void * kar_a2d_game_lib__near_8028a120(void * arg0, void * arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * kar_a2d_game_lib__near_8028a5f4(void * arg0, void * arg1, void * arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    return 0;
}

extern "C" void * kar_a2d_game_lib__near_8028a66c(void * arg0, void * arg1, void * arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    return 0;
}

extern "C" void kar_a2d_game_lib__near_8028a700(void * arg0, void * arg1, void * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
}

extern "C" void kar_a2d_game_lib__near_8028ac28(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void kar_a2d_game_lib__near_8028ac78(void) {
    kar_gmlanmenu__near_80052fb8();
}

extern "C" s32 kar_a2d_game_lib__near_8028ac98(u16 arg0, u16 arg1, u16 arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    return 0;
}

extern "C" void kar_a2d_game_lib__8028ad74(s32 arg0, s32 arg1, u16 * arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
}

extern "C" void kar_a2d_game_lib__near_8028aec0(f32 * arg0, s32 arg1, void * arg2, f32 * arg3, f32 * arg4, f32 farg0, f32 farg1) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) farg0;
    (void) farg1;
}

extern "C" void * kar_a2d_game_lib__near_8028b050(void * arg0, u16 arg1, u16 arg2, u32 arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    return 0;
}

extern "C" void kar_a2d_game_lib__near_8028b0d0(void ** arg0) {
    (void) arg0;
}

extern "C" s32 kar_a2d_game_lib__near_8028b11c(s16 arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void kar_a2d_game_lib__near_8028b234(void * arg0) {
    (void) arg0;
}

extern "C" void kar_a2d_game_lib__near_8028b2cc(void) {

}

extern "C" void kar_a2d_game_lib__near_8028b358(f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5, f32 farg6, f32 farg7) {
    (void) farg0;
    (void) farg1;
    (void) farg2;
    (void) farg3;
    (void) farg4;
    (void) farg5;
    (void) farg6;
    (void) farg7;
}

extern "C" void kar_a2d_game_lib__8028b460(void * arg0, s32 arg_sp0) {
    (void) arg0;
    (void) arg_sp0;
}

extern "C" void * kar_a2_assets__asset_8028b974(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * kar_a2d_game_lib__near_8028bd68(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * kar_a2d_game_lib__near_8028bdec(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * kar_a2d_game_lib__near_8028be6c(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * kar_a2d_game_lib__near_8028beec(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * kar_a2d_game_lib__near_8028bf4c(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * kar_a2d_game_lib__near_8028bfb0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * TopRide_GameSessionInit(void * arg0, void * arg1, void * arg2, u8 arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
    return 0;
}

extern "C" void ** kar_a2d_game_lib__near_8028c830(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BE14C;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * kar_a2d_game_lib__near_8028c878(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * kar_a2d_game_lib__near_8028cb8c(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        void *inner = FP(arg0, 0);
        if (inner != 0) {
            ((VDispatch1I *) inner)->v0(1);
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * kar_a2d_game_lib__near_8028cbf8(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8028D0B0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8028DA40(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void ** fn_8028DE08(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BD614;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8028DE50(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8028DF40(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" {
extern char lbl_804BDDD8[0x28];
void HSD_JObjUnref(void *);
}

extern "C" void * fn_8028DFC8(void * arg0, s16 arg1) {
    if (!arg0) goto ret;
    *(void **) arg0 = (void *) &lbl_804BDDD8;
    HSD_JObjUnref(FP(arg0, 0xC));
    FP(arg0, 0xC) = 0;
    if (!arg0) goto after_ctor;
    *(void **) arg0 = (void *) &lbl_804BDD98;
    ((VDispatch8 *) arg0)->v5();
after_ctor:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
ret:
    return arg0;
}

extern "C" void * fn_8028E058(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void ** fn_8028E0E0(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804D1A98;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8028E128(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" {
void fn_80296A14(void ***, void *, void ***, void ***);
extern s32 lbl_805DD99C;
extern s32 lbl_805DD9A0;
}

extern "C" void * fn_8028E1F8(void * arg0, s16 arg1) {
    if (!arg0) goto ret;
    for (int i = 0; i < 3; i++) {
        if (!arg0) goto after;
    }
    {
        char *u = (char *) arg0 + 12;
        s32 t = FU32(arg0, 16);
        void *dst;
        fn_80296A14((void ***) &dst, arg0, (void ***) &t, (void ***) &u);
    }
    for (int i = 0; i < 4; i++) {
        if ((s32) arg0 + 8 == 0) goto after;
    }
    {
        void *v = (void *) FU32(arg0, 8);
        if (v != 0) {
            lbl_805DD99C = 0;
            fn_8038CB78(v);
        }
    }
    for (int i = 0; i < 4; i++) {
        if (!arg0) goto after;
    }
    {
        void *v = (void *) FU32(arg0, 0);
        if (v != 0) {
            lbl_805DD9A0 = 0;
            fn_8038CB78(v);
        }
    }
after:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
ret:
    return arg0;
}

extern "C" void * fn_8028E2D8(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" {
void * fn_8028E3C0(void *, s16);
void * fn_8028E520(void *, s16);
void * fn_8028E680(void *, s16);
void * fn_8028E7E0(void *, s16);
void * fn_8028E940(void *, s16);
void * fn_8028EAA0(void *, s16);
void * fn_8028EC00(void *, s16);
void * fn_80290A18(void *, s16);
}

extern "C" void * fn_8028E340(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BD5BC;
        fn_8028E3C0((char *) arg0 + 4, -1);
        if (arg0 != 0) {
            *(void **) arg0 = (void *) &lbl_804BD598;
            lbl_805DDB48 = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8028E3C0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8028E4A0(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BD578;
        fn_8028E520((char *) arg0 + 4, -1);
        if (arg0 != 0) {
            *(void **) arg0 = (void *) &lbl_804BD56C;
            lbl_805DDB64 = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8028E520(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8028E600(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BD560;
        fn_8028E680((char *) arg0 + 4, -1);
        if (arg0 != 0) {
            *(void **) arg0 = (void *) &lbl_804BD548;
            lbl_805DDB60 = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8028E680(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8028E760(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BD528;
        fn_8028E7E0((char *) arg0 + 4, -1);
        if (arg0 != 0) {
            *(void **) arg0 = (void *) &lbl_804BD504;
            lbl_805DDB5C = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8028E7E0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8028E8C0(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BD4E4;
        fn_8028E940((char *) arg0 + 4, -1);
        if (arg0 != 0) {
            *(void **) arg0 = (void *) &lbl_804BD4C0;
            lbl_805DDB58 = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8028E940(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8028EA20(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BD4A0;
        fn_8028EAA0((char *) arg0 + 4, -1);
        if (arg0 != 0) {
            *(void **) arg0 = (void *) &lbl_804BD47C;
            lbl_805DDB54 = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8028EAA0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8028EB80(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BD458;
        fn_8028EC00((char *) arg0 + 4, -1);
        if (arg0 != 0) {
            *(void **) arg0 = (void *) &lbl_804BD434;
            lbl_805DDB50 = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8028EC00(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8028ECE0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8028EDA4(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        void *inner = FP(arg0, 0);
        if (inner != 0) {
            ((VDispatch1I *) inner)->v0(1);
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_8028EE10(void * arg0) {
    FU32(arg0, 0x0) = 0;
}

extern "C" void * fn_8028EE1C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" {
extern char lbl_804BE188[0x28];
}

extern "C" void * fn_8028EEF0(void * arg0, s16 arg1) {
    if (!arg0) goto ret;
    *(void **) arg0 = (void *) &lbl_804BE188;
    if (!arg0) goto after_ctor;
    *(void **) arg0 = (void *) &lbl_804BE1B0;
    ((VDispatch8 *) arg0)->v5();
after_ctor:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
ret:
    return arg0;
}

extern "C" void * fn_8028EF68(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BE1B0;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_8028EFD0(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" {
extern char lbl_804BE210[0x28];
}

extern "C" void * fn_8028EFFC(void * arg0, s16 arg1) {
    if (!arg0) goto ret;
    *(void **) arg0 = (void *) &lbl_804BE210;
    if (!arg0) goto after_ctor;
    *(void **) arg0 = (void *) &lbl_804BE238;
    ((VDispatch8 *) arg0)->v5();
after_ctor:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
ret:
    return arg0;
}

extern "C" void * fn_8028F074(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BE238;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void kar_object__8028f0dc(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void * fn_8028F108(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8028F19C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8028F4A8(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8028F584(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8028F62C(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        void *inner = FP(arg0, 0);
        if (inner != 0) {
            ((VDispatch1I *) inner)->v0(1);
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8028F698(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BE260;
        if (arg0 != 0) {
            *(void **) arg0 = (void *) &lbl_804BE26C;
            lbl_805DDB88 = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void *** fn_8028F6FC(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BE26C;
        lbl_805DDB88 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8028F74C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void ** fn_8028F7EC(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BE2B4;
        lbl_805DDBE8 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8028F83C(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BE2F8;
        if (arg0 != 0) {
            *(void **) arg0 = (void *) &lbl_804BE304;
            lbl_805DDBD4 = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void *** fn_8028F8A0(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BE304;
        lbl_805DDBD4 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8028F8F0(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BE348;
        if (arg0 != 0) {
            *(void **) arg0 = (void *) &lbl_804BE354;
            lbl_805DDBA8 = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void *** fn_8028F954(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BE354;
        lbl_805DDBA8 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8028F9A4(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void *** fn_8028FA40(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804F120C;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void ** fn_8028FA88(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BE3A4;
        lbl_805DDBAC = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8028FAD8(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void *** fn_8028FB80(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804F1134;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8028FBC8(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void ** fn_8028FCA8(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BE3BC;
        lbl_805DDBB0 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8028FCF8(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        void *inner = FP(arg0, 0);
        if (inner != 0) {
            ((VDispatch1I *) inner)->v0(1);
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void *** fn_8028FD64(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BD254;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_8028FDAC(void) {

}

extern "C" void * fn_8028FDD0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8028FF84(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BD1E8;
        if (arg0 != 0) {
            *(void **) arg0 = (void *) &lbl_804BD1B8;
            lbl_805DDBA0 = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" {
extern char lbl_804BD18C[0x28];
}

extern "C" void * fn_8028FFE8(void * arg0, s16 arg1) {
    if (!arg0) goto ret;
    *(void **) arg0 = (void *) &lbl_804BD18C;
    kar_a2d_game_lib__near_8028b234(FP(arg0, 0xC));
    if (!arg0) goto after_ctor;
    *(void **) arg0 = (void *) &lbl_804BD15C;
    lbl_805DDBE4 = 0;
after_ctor:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
ret:
    return arg0;
}

extern "C" void * fn_80290064(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802901E0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80290264(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BD074;
        if (arg0 != 0) {
            *(void **) arg0 = (void *) &lbl_804BD048;
            lbl_805DDB98 = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" {
extern char lbl_804BD01C[0x28];
}

extern "C" void * fn_802902C8(void * arg0, s16 arg1) {
    if (!arg0) goto ret;
    *(void **) arg0 = (void *) &lbl_804BD01C;
    kar_a2d_game_lib__near_8028b234(FP(arg0, 0x4));
    if (!arg0) goto after_ctor;
    *(void **) arg0 = (void *) &lbl_804BCFEC;
    lbl_805DDB94 = 0;
after_ctor:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
ret:
    return arg0;
}

extern "C" void * fn_80290344(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" {
extern char lbl_804F0ECC[0x24];
extern char lbl_804F0F28[0x24];
extern char lbl_804F0F8C[0x24];
extern char lbl_804F0FE8[0x24];
}

extern "C" void * fn_80290438(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804F0ECC;
        FP(arg0, 4) = (void *) (lbl_804F0ECC + 12);
        if ((s32) arg0 + 4 != 0) {
            FP(arg0, 4) = (void *) &lbl_804BCF64;
            lbl_805DDB6C = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_802904A8(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804F0F28;
        FP(arg0, 4) = (void *) (lbl_804F0F28 + 12);
        if ((s32) arg0 + 4 != 0) {
            FP(arg0, 4) = (void *) &lbl_804BCF3C;
            lbl_805DDB70 = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_80290518(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804F0F8C;
        FP(arg0, 4) = (void *) (lbl_804F0F8C + 12);
        if ((s32) arg0 + 4 != 0) {
            FP(arg0, 4) = (void *) &lbl_804BCF14;
            lbl_805DDB74 = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_80290588(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804F0FE8;
        FP(arg0, 4) = (void *) (lbl_804F0FE8 + 12);
        if ((s32) arg0 + 4 != 0) {
            FP(arg0, 4) = (void *) &lbl_804BCEE8;
            lbl_805DDB78 = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_802905F8(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80290728(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80290814(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void ** fn_80290908(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BCE40;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void ** fn_80290950(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BCE14;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_80290998(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BE400;
        fn_80290A18((char *) arg0 + 4, -1);
        if (arg0 != 0) {
            *(void **) arg0 = (void *) &lbl_804BE40C;
            lbl_805DDB38 = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_80290A18(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void *** fn_80290AF8(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BE40C;
        lbl_805DDB38 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_80290B48(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BCDF0;
        if (arg0 != 0) {
            *(void **) arg0 = (void *) &lbl_804BCDD8;
            lbl_805DDB80 = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_80290BAC(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80290C38(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80290C98(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void fn_80290CE8(void * arg0) {
    (void) arg0;
}

extern "C" void *** fn_80290D18(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BE454;
        lbl_805DDBEC = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_80290D68(void * arg0, s16 arg1, void * arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
    return 0;
}

extern "C" void fn_80291670(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802917F0(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7778, &lbl_805D7770, 0);
}

extern "C" void *** fn_80291824(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BCDD8;
        lbl_805DDB80 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80291874(void) {

}

extern "C" void fn_80291878(void) {

}

extern "C" s32 fn_8029187C(void) {
    return 0;
}

extern "C" s32 fn_802918B4(void) {
    return 0;
}

extern "C" u8 fn_802918F8(void) {
    return 0;
}

extern "C" void fn_80291930(void) {

}

extern "C" void fn_80291934(void) {

}

extern "C" void fn_80291938(void) {

}

extern "C" void ** fn_8029193C(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BCE4C;
        lbl_805DDBC4 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void ** fn_8029198C(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BCE74;
        lbl_805DDBC0 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void ** fn_802919DC(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BCEC0;
        lbl_805DDB7C = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void ** fn_80291A2C(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BCEE8;
        lbl_805DDB78 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void ** fn_80291A7C(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BCF14;
        lbl_805DDB74 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void ** fn_80291ACC(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BCF3C;
        lbl_805DDB70 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void ** fn_80291B1C(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BCF64;
        lbl_805DDB6C = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void ** fn_80291B6C(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BCF90;
        lbl_805DDBDC = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void ** fn_80291BBC(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BCFEC;
        lbl_805DDB94 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void *** fn_80291C0C(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BD048;
        lbl_805DDB98 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void ** fn_80291C5C(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BD0A4;
        lbl_805DDBE0 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void ** fn_80291CAC(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BD100;
        lbl_805DDB9C = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void ** fn_80291CFC(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BD15C;
        lbl_805DDBE4 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void *** fn_80291D4C(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BD1B8;
        lbl_805DDBA0 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void ** fn_80291D9C(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BD20C;
        lbl_805DDB90 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" u8 fn_80291DEC(void ** arg0, f32 * arg1, f32 * arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    return 0;
}

extern "C" void fn_80291E58(void * arg0) {
    (void) arg0;
}

extern "C" {
s32 HSD_CObjSetCurrent(void *);
extern s32 lbl_805DDC90;
}

extern "C" s32 fn_80291E7C(void * arg0) {
    s32 r = HSD_CObjSetCurrent(*(void **) ((char *) arg0 + 8));
    lbl_805DDC90 = (s32) arg0;
    return (u32) (-r | r) >> 31;
}

extern "C" {
void HSD_CObjEndCurrent(void);
}

extern "C" void fn_80291EBC(void) {
    HSD_CObjEndCurrent();
    lbl_805DDC90 = 0;
}

extern "C" void ** fn_80291EE4(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BD298;
        lbl_805DDB40 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_80291F34(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80291FB4(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" {
extern char lbl_804BD2E4[0x28];
void __destroy_arr(void *, void *(*)(void *, s16), s32, s32);
}

extern "C" void * fn_8029207C(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BD2E4;
        __destroy_arr((char *) arg0 + 8, fn_8028F62C, 4, 4);
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_802920EC(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8029216C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802921EC(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80292294(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" {
extern char lbl_804BD35C[0x28];
}

extern "C" void * fn_8029232C(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BD35C;
        __destroy_arr((char *) arg0 + 8, fn_8028F62C, 4, 2);
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void ** fn_8029239C(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BD3A4;
        lbl_805DDB3C = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void ** fn_802923EC(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BD3EC;
        lbl_805DDB84 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void *** fn_8029243C(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BD434;
        lbl_805DDB50 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void *** fn_8029248C(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BD47C;
        lbl_805DDB54 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void *** fn_802924DC(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BD4C0;
        lbl_805DDB58 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void *** fn_8029252C(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BD504;
        lbl_805DDB5C = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void *** fn_8029257C(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BD548;
        lbl_805DDB60 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void *** fn_802925CC(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BD56C;
        lbl_805DDB64 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void *** fn_8029261C(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BD598;
        lbl_805DDB48 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void ** fn_8029266C(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BD5C8;
        lbl_805DDBA4 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_802926BC(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void * fn_802926E8(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BD658;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" {
extern char lbl_804BD6A0[0x28];
}

extern "C" void * fn_80292750(void * arg0, s16 arg1) {
    if (!arg0) goto ret;
    *(void **) arg0 = (void *) &lbl_804BD6A0;
    if (!arg0) goto after_ctor;
    *(void **) arg0 = (void *) &lbl_804BD658;
    ((VDispatch8 *) arg0)->v5();
after_ctor:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
ret:
    return arg0;
}

extern "C" void fn_802927C8(void * arg0) {
    FF32(arg0, 0x14) = lbl_805E3358;
}

extern "C" void fn_802927D4(void * arg0, f32 farg0) {
    (void) arg0;
    (void) farg0;
}

extern "C" void fn_802927F4(void) {

}

extern "C" void fn_802927F8(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7630, &lbl_805D7628, 0);
}

extern "C" void * fn_8029282C(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BD6D4;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_80292894(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_8029292C(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7620, &lbl_805D7618, 0);
}

extern "C" void fn_80292960(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void * fn_8029298C(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BD724;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_802929F4(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_80292A7C(void) {
    return 0;
}

extern "C" void fn_80292A84(void * arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_80292AB4(void) {
    kar_a2d_effecthandle__near_8037cfec();
}

extern "C" void fn_80292AD4(void * arg0, f32 * arg1, f32 * arg2) {
    (void) arg0;
    *arg1 = lbl_805E336C;
    *arg2 = lbl_805E336C;
}

extern "C" void fn_80292AE4(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_80292B10(void * arg0) {
    (void) arg0;
}

extern "C" {
void PSMTXIdentity(f32 (*)[3][4]);
}

extern "C" void fn_80292B40(void * arg0, f32 (*arg1)[3][4]) {
    PSMTXIdentity(arg1);
}

extern "C" void fn_80292B64(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7640, &lbl_805D7638, 0);
}

extern "C" void * fn_80292B98(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BD7B4;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" {
extern char lbl_804BD7DC[0x28];
}

extern "C" void * fn_80292C00(void * arg0, s16 arg1) {
    if (!arg0) goto ret;
    *(void **) arg0 = (void *) &lbl_804BD7DC;
    HSD_JObjUnref(FP(arg0, 0x10));
    FP(arg0, 0x10) = 0;
    if (!arg0) goto after_ctor;
    *(void **) arg0 = (void *) &lbl_804BD7B4;
    ((VDispatch8 *) arg0)->v5();
after_ctor:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
ret:
    return arg0;
}

extern "C" void fn_80292C90(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void * fn_80292CBC(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BD820;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80292D24(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7650, &lbl_805D7648, 0);
}

extern "C" void fn_80292D58(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void * fn_80292D84(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BD848;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" {
extern char lbl_804BD870[0x28];
}

extern "C" void * fn_80292DEC(void * arg0, s16 arg1) {
    if (!arg0) goto ret;
    *(void **) arg0 = (void *) &lbl_804BD870;
    if (!arg0) goto after_ctor;
    *(void **) arg0 = (void *) &lbl_804BD848;
    ((VDispatch8 *) arg0)->v5();
after_ctor:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
ret:
    return arg0;
}

extern "C" void * fn_80292E64(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_80292EEC(void * arg0, s32 arg1, s32 arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void * fn_80292F20(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_80292FF0(void * arg0) {
    FU32(arg0, 0xC) = 1;
}

extern "C" void * fn_80292FFC(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BD934;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" {
extern char lbl_804BD95C[0x28];
}

extern "C" void * fn_80293064(void * arg0, s16 arg1) {
    if (!arg0) goto ret;
    *(void **) arg0 = (void *) &lbl_804BD95C;
    if (!arg0) goto after_ctor;
    *(void **) arg0 = (void *) &lbl_804BD934;
    ((VDispatch8 *) arg0)->v5();
after_ctor:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
ret:
    return arg0;
}

extern "C" void fn_802930DC(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void * fn_80293108(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BDABC;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" {
extern char lbl_804BDB04[0x28];
}

extern "C" void * fn_80293170(void * arg0, s16 arg1) {
    if (!arg0) goto ret;
    *(void **) arg0 = (void *) &lbl_804BDB04;
    if (!arg0) goto after_ctor;
    *(void **) arg0 = (void *) &lbl_804BDABC;
    ((VDispatch8 *) arg0)->v5();
after_ctor:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
ret:
    return arg0;
}

extern "C" void * fn_802931E8(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BDB4C;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void *** fn_80293250(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BDB74;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" s32 kar_object__80293298(s32 arg0) {
    return (s32) ((char *) arg0 + 0x4);
}

extern "C" void kar_object__near_802932a0(void * arg0, void * arg1) {
    f32 a = FF32(arg1, 0x0);
    f32 b = FF32(arg1, 0x4);
    FF32(arg0, 0x4) = a;
    a = FF32(arg1, 0x8);
    FF32(arg0, 0x8) = b;
    FF32(arg0, 0xC) = a;
}

extern "C" f32 fn_802932BC(void * arg0) {
    return FF32(arg0, 0x10);
}

extern "C" void kar_object__near_802932c4(void * arg0, f32 farg0) {
    FF32(arg0, 0x10) = farg0;
}

extern "C" u32 kar_object__near_802932cc(void ** arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void kar_object__near_80293418(void ** arg0) {
    (void) arg0;
}

extern "C" void * kar_object__near_802934e8(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BDBC0;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80293550(void) {

}

extern "C" void fn_80293554(void) {

}

extern "C" void fn_80293558(void) {

}

extern "C" s32 fn_8029355C(void) {
    return 1;
}

extern "C" u8 fn_80293564(void * arg0) {
    return FU8(arg0, 0x4C);
}

extern "C" void fn_8029356C(void * arg0) {
    FU8(arg0, 0x4C) = 1;
}

extern "C" void * kar_object__near_80293578(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * kar_object__near_80293614(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void kar_object__802936ec(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void * fn_80293718(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BDCBC;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" {
extern char lbl_804BDD08[0x28];
}

extern "C" void * fn_80293780(void * arg0, s16 arg1) {
    if (!arg0) goto ret;
    *(void **) arg0 = (void *) &lbl_804BDD08;
    if (!arg0) goto after_ctor;
    *(void **) arg0 = (void *) &lbl_804BDCBC;
    ((VDispatch8 *) arg0)->v5();
after_ctor:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
ret:
    return arg0;
}

extern "C" void fn_802937F8(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D76C8, &lbl_805D76C0, 0);
}

extern "C" void * fn_8029382C(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BDD30;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_80293894(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8029392C(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BDD98;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80293994(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802939F4(void * arg0) {
    (void) arg0;
}

extern "C" void * fn_80293A64(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80293CA4(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BDE38;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_80293D0C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void ** fn_80293DA8(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BDEA0;
        lbl_805DDB44 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void *** fn_80293DF8(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BDEC0;
        lbl_805DDB68 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_80293E48(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BDEE4;
        if (arg0 != 0) {
            *(void **) arg0 = (void *) &lbl_804BDEC0;
            lbl_805DDB68 = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void ** fn_80293EAC(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BDF04;
        lbl_805DDB4C = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80293EFC(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void * fn_80293F28(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BDF2C;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_80293F90(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void ** fn_802940C4(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BDFD8;
        lbl_805DDBD0 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void ** fn_80294114(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BE000;
        lbl_805DDBD8 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_80294164(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802941F8(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void *** fn_802942BC(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BE078;
        lbl_805DDB8C = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8029430C(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BE0A0;
        if (arg0 != 0) {
            *(void **) arg0 = (void *) &lbl_804BE078;
            lbl_805DDB8C = 0;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_80294370(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BE0C4;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_802943D8(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_80294538(s32 * arg0) {
    (void) arg0;
}

extern "C" void fn_802945B4(s32 * arg0) {
    (void) arg0;
}

extern "C" s32 fn_80294630(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDA34 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_80294664(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void fn_80294690(void * arg0) {
    if (lbl_805DDA34 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDA34;
        *(void **) ((char *) lbl_805DDA34 + 0x4) = arg0;
        lbl_805DDA34 = arg0;
    } else {
        lbl_805DDA38 = arg0;
        lbl_805DDA34 = arg0;
    }
    lbl_805DDA30 = lbl_805DDA30 + 1;
}

extern "C" void fn_802946C8(void * arg0) {
    if (lbl_805DDA34 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDA38;
        *(void **) ((char *) lbl_805DDA38 + 0x8) = arg0;
        lbl_805DDA38 = arg0;
    } else {
        lbl_805DDA38 = arg0;
        lbl_805DDA34 = arg0;
    }
    lbl_805DDA30 = lbl_805DDA30 + 1;
}

extern "C" void fn_80294704(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDA34 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDA38 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDA30 = lbl_805DDA30 - 1;
}

extern "C" void fn_80294780(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7A84, &lbl_805D7A7C, 0);
}

extern "C" void fn_802947B4(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7A84, &lbl_805D7A7C, 0);
}

extern "C" s32 fn_802947E8(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDA40 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_8029481C(void * arg0) {
    if (lbl_805DDA40 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDA40;
        *(void **) ((char *) lbl_805DDA40 + 0x4) = arg0;
        lbl_805DDA40 = arg0;
    } else {
        lbl_805DDA44 = arg0;
        lbl_805DDA40 = arg0;
    }
    lbl_805DDA3C = lbl_805DDA3C + 1;
}

extern "C" void fn_80294854(void * arg0) {
    if (lbl_805DDA40 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDA44;
        *(void **) ((char *) lbl_805DDA44 + 0x8) = arg0;
        lbl_805DDA44 = arg0;
    } else {
        lbl_805DDA44 = arg0;
        lbl_805DDA40 = arg0;
    }
    lbl_805DDA3C = lbl_805DDA3C + 1;
}

extern "C" void fn_80294890(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDA40 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDA44 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDA3C = lbl_805DDA3C - 1;
}

extern "C" void fn_8029490C(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7B0C, &lbl_805D7B04, 0);
}

extern "C" void fn_80294940(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7B0C, &lbl_805D7B04, 0);
}

extern "C" s32 fn_80294974(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDA4C == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_802949A8(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void fn_802949D4(void * arg0) {
    if (lbl_805DDA4C != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDA4C;
        *(void **) ((char *) lbl_805DDA4C + 0x4) = arg0;
        lbl_805DDA4C = arg0;
    } else {
        lbl_805DDA50 = arg0;
        lbl_805DDA4C = arg0;
    }
    lbl_805DDA48 = lbl_805DDA48 + 1;
}

extern "C" void fn_80294A0C(void * arg0) {
    if (lbl_805DDA4C != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDA50;
        *(void **) ((char *) lbl_805DDA50 + 0x8) = arg0;
        lbl_805DDA50 = arg0;
    } else {
        lbl_805DDA50 = arg0;
        lbl_805DDA4C = arg0;
    }
    lbl_805DDA48 = lbl_805DDA48 + 1;
}

extern "C" void fn_80294A48(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDA4C = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDA50 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDA48 = lbl_805DDA48 - 1;
}

extern "C" void fn_80294AC4(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D76C8, &lbl_805D76C0, 0);
}

extern "C" s32 fn_80294AF8(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDA58 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void kar_a2d_modeleffect__80294b2c(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void fn_80294B58(void * arg0) {
    if (lbl_805DDA58 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDA58;
        *(void **) ((char *) lbl_805DDA58 + 0x4) = arg0;
        lbl_805DDA58 = arg0;
    } else {
        lbl_805DDA5C = arg0;
        lbl_805DDA58 = arg0;
    }
    lbl_805DDA54 = lbl_805DDA54 + 1;
}

extern "C" void fn_80294B90(void * arg0) {
    if (lbl_805DDA58 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDA5C;
        *(void **) ((char *) lbl_805DDA5C + 0x8) = arg0;
        lbl_805DDA5C = arg0;
    } else {
        lbl_805DDA5C = arg0;
        lbl_805DDA58 = arg0;
    }
    lbl_805DDA54 = lbl_805DDA54 + 1;
}

extern "C" void fn_80294BCC(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDA58 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDA5C = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDA54 = lbl_805DDA54 - 1;
}

extern "C" void fn_80294C48(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7A6C, &lbl_805D7A64, 0);
}

extern "C" void fn_80294C7C(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7A6C, &lbl_805D7A64, 0);
}

extern "C" s32 fn_80294CB0(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDA70 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_80294CE4(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void fn_80294D10(void * arg0) {
    if (lbl_805DDA70 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDA70;
        *(void **) ((char *) lbl_805DDA70 + 0x4) = arg0;
        lbl_805DDA70 = arg0;
    } else {
        lbl_805DDA74 = arg0;
        lbl_805DDA70 = arg0;
    }
    lbl_805DDA6C = lbl_805DDA6C + 1;
}

extern "C" void fn_80294D48(void * arg0) {
    if (lbl_805DDA70 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDA74;
        *(void **) ((char *) lbl_805DDA74 + 0x8) = arg0;
        lbl_805DDA74 = arg0;
    } else {
        lbl_805DDA74 = arg0;
        lbl_805DDA70 = arg0;
    }
    lbl_805DDA6C = lbl_805DDA6C + 1;
}

extern "C" void fn_80294D84(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDA70 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDA74 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDA6C = lbl_805DDA6C - 1;
}

extern "C" void fn_80294E00(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7A4C, &lbl_805D7A44, 0);
}

extern "C" void fn_80294E34(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7A4C, &lbl_805D7A44, 0);
}

extern "C" s32 fn_80294E68(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDA7C == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_80294E9C(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void fn_80294EC8(void * arg0) {
    if (lbl_805DDA7C != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDA7C;
        *(void **) ((char *) lbl_805DDA7C + 0x4) = arg0;
        lbl_805DDA7C = arg0;
    } else {
        lbl_805DDA80 = arg0;
        lbl_805DDA7C = arg0;
    }
    lbl_805DDA78 = lbl_805DDA78 + 1;
}

extern "C" void fn_80294F00(void * arg0) {
    if (lbl_805DDA7C != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDA80;
        *(void **) ((char *) lbl_805DDA80 + 0x8) = arg0;
        lbl_805DDA80 = arg0;
    } else {
        lbl_805DDA80 = arg0;
        lbl_805DDA7C = arg0;
    }
    lbl_805DDA78 = lbl_805DDA78 + 1;
}

extern "C" void fn_80294F3C(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDA7C = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDA80 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDA78 = lbl_805DDA78 - 1;
}

extern "C" void fn_80294FB8(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D76B0, &lbl_805D7690, 0);
}

extern "C" void fn_80294FEC(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D76B0, &lbl_805D7690, 0);
}

extern "C" s32 fn_80295020(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDA88 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_80295054(void * arg0) {
    if (lbl_805DDA88 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDA88;
        *(void **) ((char *) lbl_805DDA88 + 0x4) = arg0;
        lbl_805DDA88 = arg0;
    } else {
        lbl_805DDA8C = arg0;
        lbl_805DDA88 = arg0;
    }
    lbl_805DDA84 = lbl_805DDA84 + 1;
}

extern "C" void fn_8029508C(void * arg0) {
    if (lbl_805DDA88 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDA8C;
        *(void **) ((char *) lbl_805DDA8C + 0x8) = arg0;
        lbl_805DDA8C = arg0;
    } else {
        lbl_805DDA8C = arg0;
        lbl_805DDA88 = arg0;
    }
    lbl_805DDA84 = lbl_805DDA84 + 1;
}

extern "C" void fn_802950C8(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDA88 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDA8C = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDA84 = lbl_805DDA84 - 1;
}

extern "C" void fn_80295144(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7A5C, &lbl_805D7A54, 0);
}

extern "C" void fn_80295178(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7A5C, &lbl_805D7A54, 0);
}

extern "C" s32 fn_802951AC(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDA94 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_802951E0(void * arg0) {
    if (lbl_805DDA94 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDA94;
        *(void **) ((char *) lbl_805DDA94 + 0x4) = arg0;
        lbl_805DDA94 = arg0;
    } else {
        lbl_805DDA98 = arg0;
        lbl_805DDA94 = arg0;
    }
    lbl_805DDA90 = lbl_805DDA90 + 1;
}

extern "C" void fn_80295218(void * arg0) {
    if (lbl_805DDA94 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDA98;
        *(void **) ((char *) lbl_805DDA98 + 0x8) = arg0;
        lbl_805DDA98 = arg0;
    } else {
        lbl_805DDA98 = arg0;
        lbl_805DDA94 = arg0;
    }
    lbl_805DDA90 = lbl_805DDA90 + 1;
}

extern "C" void fn_80295254(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDA94 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDA98 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDA90 = lbl_805DDA90 - 1;
}

extern "C" void fn_802952D0(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7A3C, &lbl_805D7A34, 0);
}

extern "C" void fn_80295304(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7A3C, &lbl_805D7A34, 0);
}

extern "C" s32 fn_80295338(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDAB8 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_8029536C(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void fn_80295398(void * arg0) {
    if (lbl_805DDAB8 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDAB8;
        *(void **) ((char *) lbl_805DDAB8 + 0x4) = arg0;
        lbl_805DDAB8 = arg0;
    } else {
        lbl_805DDABC = arg0;
        lbl_805DDAB8 = arg0;
    }
    lbl_805DDAB4 = lbl_805DDAB4 + 1;
}

extern "C" void fn_802953D0(void * arg0) {
    if (lbl_805DDAB8 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDABC;
        *(void **) ((char *) lbl_805DDABC + 0x8) = arg0;
        lbl_805DDABC = arg0;
    } else {
        lbl_805DDABC = arg0;
        lbl_805DDAB8 = arg0;
    }
    lbl_805DDAB4 = lbl_805DDAB4 + 1;
}

extern "C" void fn_8029540C(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDAB8 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDABC = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDAB4 = lbl_805DDAB4 - 1;
}

extern "C" void fn_80295488(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7778, &lbl_805D7770, 0);
}

extern "C" s32 fn_802954BC(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDAC4 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_802954F0(void * arg0) {
    if (lbl_805DDAC4 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDAC4;
        *(void **) ((char *) lbl_805DDAC4 + 0x4) = arg0;
        lbl_805DDAC4 = arg0;
    } else {
        lbl_805DDAC8 = arg0;
        lbl_805DDAC4 = arg0;
    }
    lbl_805DDAC0 = lbl_805DDAC0 + 1;
}

extern "C" void fn_80295528(void * arg0) {
    if (lbl_805DDAC4 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDAC8;
        *(void **) ((char *) lbl_805DDAC8 + 0x8) = arg0;
        lbl_805DDAC8 = arg0;
    } else {
        lbl_805DDAC8 = arg0;
        lbl_805DDAC4 = arg0;
    }
    lbl_805DDAC0 = lbl_805DDAC0 + 1;
}

extern "C" void fn_80295564(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDAC4 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDAC8 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDAC0 = lbl_805DDAC0 - 1;
}

extern "C" void fn_802955E0(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7A2C, &lbl_805D7A1C, 0);
}

extern "C" void fn_80295614(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7A2C, &lbl_805D7A1C, 0);
}

extern "C" s32 fn_80295648(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDAD0 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_8029567C(void * arg0) {
    if (lbl_805DDAD0 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDAD0;
        *(void **) ((char *) lbl_805DDAD0 + 0x4) = arg0;
        lbl_805DDAD0 = arg0;
    } else {
        lbl_805DDAD4 = arg0;
        lbl_805DDAD0 = arg0;
    }
    lbl_805DDACC = lbl_805DDACC + 1;
}

extern "C" void fn_802956B4(void * arg0) {
    if (lbl_805DDAD0 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDAD4;
        *(void **) ((char *) lbl_805DDAD4 + 0x8) = arg0;
        lbl_805DDAD4 = arg0;
    } else {
        lbl_805DDAD4 = arg0;
        lbl_805DDAD0 = arg0;
    }
    lbl_805DDACC = lbl_805DDACC + 1;
}

extern "C" void fn_802956F0(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDAD0 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDAD4 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDACC = lbl_805DDACC - 1;
}

extern "C" void fn_8029576C(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7650, &lbl_805D7648, 0);
}

extern "C" s32 fn_802957A0(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDADC == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_802957D4(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void fn_80295800(void * arg0) {
    if (lbl_805DDADC != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDADC;
        *(void **) ((char *) lbl_805DDADC + 0x4) = arg0;
        lbl_805DDADC = arg0;
    } else {
        lbl_805DDAE0 = arg0;
        lbl_805DDADC = arg0;
    }
    lbl_805DDAD8 = lbl_805DDAD8 + 1;
}

extern "C" void fn_80295838(void * arg0) {
    if (lbl_805DDADC != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDAE0;
        *(void **) ((char *) lbl_805DDAE0 + 0x8) = arg0;
        lbl_805DDAE0 = arg0;
    } else {
        lbl_805DDAE0 = arg0;
        lbl_805DDADC = arg0;
    }
    lbl_805DDAD8 = lbl_805DDAD8 + 1;
}

extern "C" void fn_80295874(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDADC = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDAE0 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDAD8 = lbl_805DDAD8 - 1;
}

extern "C" void fn_802958F0(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7640, &lbl_805D7638, 0);
}

extern "C" s32 fn_80295924(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDAE8 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_80295958(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void fn_80295984(void * arg0) {
    if (lbl_805DDAE8 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDAE8;
        *(void **) ((char *) lbl_805DDAE8 + 0x4) = arg0;
        lbl_805DDAE8 = arg0;
    } else {
        lbl_805DDAEC = arg0;
        lbl_805DDAE8 = arg0;
    }
    lbl_805DDAE4 = lbl_805DDAE4 + 1;
}

extern "C" void fn_802959BC(void * arg0) {
    if (lbl_805DDAE8 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDAEC;
        *(void **) ((char *) lbl_805DDAEC + 0x8) = arg0;
        lbl_805DDAEC = arg0;
    } else {
        lbl_805DDAEC = arg0;
        lbl_805DDAE8 = arg0;
    }
    lbl_805DDAE4 = lbl_805DDAE4 + 1;
}

extern "C" void fn_802959F8(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDAE8 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDAEC = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDAE4 = lbl_805DDAE4 - 1;
}

extern "C" void fn_80295A74(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7630, &lbl_805D7628, 0);
}

extern "C" s32 fn_80295AA8(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDAF4 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_80295ADC(void * arg0) {
    if (lbl_805DDAF4 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDAF4;
        *(void **) ((char *) lbl_805DDAF4 + 0x4) = arg0;
        lbl_805DDAF4 = arg0;
    } else {
        lbl_805DDAF8 = arg0;
        lbl_805DDAF4 = arg0;
    }
    lbl_805DDAF0 = lbl_805DDAF0 + 1;
}

extern "C" void fn_80295B14(void * arg0) {
    if (lbl_805DDAF4 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDAF8;
        *(void **) ((char *) lbl_805DDAF8 + 0x8) = arg0;
        lbl_805DDAF8 = arg0;
    } else {
        lbl_805DDAF8 = arg0;
        lbl_805DDAF4 = arg0;
    }
    lbl_805DDAF0 = lbl_805DDAF0 + 1;
}

extern "C" void fn_80295B50(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDAF4 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDAF8 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDAF0 = lbl_805DDAF0 - 1;
}

extern "C" void fn_80295BCC(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7AAC, &lbl_805D7AA4, 0);
}

extern "C" void fn_80295C00(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7AAC, &lbl_805D7AA4, 0);
}

extern "C" s32 fn_80295C34(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDB00 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_80295C68(void * arg0) {
    if (lbl_805DDB00 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDB00;
        *(void **) ((char *) lbl_805DDB00 + 0x4) = arg0;
        lbl_805DDB00 = arg0;
    } else {
        lbl_805DDB04 = arg0;
        lbl_805DDB00 = arg0;
    }
    lbl_805DDAFC = lbl_805DDAFC + 1;
}

extern "C" void fn_80295CA0(void * arg0) {
    if (lbl_805DDB00 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDB04;
        *(void **) ((char *) lbl_805DDB04 + 0x8) = arg0;
        lbl_805DDB04 = arg0;
    } else {
        lbl_805DDB04 = arg0;
        lbl_805DDB00 = arg0;
    }
    lbl_805DDAFC = lbl_805DDAFC + 1;
}

extern "C" void fn_80295CDC(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDB00 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDB04 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDAFC = lbl_805DDAFC - 1;
}

extern "C" void fn_80295D58(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7620, &lbl_805D7618, 0);
}

extern "C" s32 fn_80295D8C(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDB0C == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_80295DC0(void * arg0) {
    if (lbl_805DDB0C != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDB0C;
        *(void **) ((char *) lbl_805DDB0C + 0x4) = arg0;
        lbl_805DDB0C = arg0;
    } else {
        lbl_805DDB10 = arg0;
        lbl_805DDB0C = arg0;
    }
    lbl_805DDB08 = lbl_805DDB08 + 1;
}

extern "C" void fn_80295DF8(void * arg0) {
    if (lbl_805DDB0C != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDB10;
        *(void **) ((char *) lbl_805DDB10 + 0x8) = arg0;
        lbl_805DDB10 = arg0;
    } else {
        lbl_805DDB10 = arg0;
        lbl_805DDB0C = arg0;
    }
    lbl_805DDB08 = lbl_805DDB08 + 1;
}

extern "C" void fn_80295E34(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDB0C = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDB10 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDB08 = lbl_805DDB08 - 1;
}

extern "C" void fn_80295EB0(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7B1C, &lbl_805D7B14, 0);
}

extern "C" void fn_80295EE4(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7B1C, &lbl_805D7B14, 0);
}

extern "C" s32 fn_80295F18(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDB18 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_80295F4C(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void fn_80295F78(void * arg0) {
    if (lbl_805DDB18 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDB18;
        *(void **) ((char *) lbl_805DDB18 + 0x4) = arg0;
        lbl_805DDB18 = arg0;
    } else {
        lbl_805DDB1C = arg0;
        lbl_805DDB18 = arg0;
    }
    lbl_805DDB14 = lbl_805DDB14 + 1;
}

extern "C" void fn_80295FB0(void * arg0) {
    if (lbl_805DDB18 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDB1C;
        *(void **) ((char *) lbl_805DDB1C + 0x8) = arg0;
        lbl_805DDB1C = arg0;
    } else {
        lbl_805DDB1C = arg0;
        lbl_805DDB18 = arg0;
    }
    lbl_805DDB14 = lbl_805DDB14 + 1;
}

extern "C" void fn_80295FEC(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDB18 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDB1C = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDB14 = lbl_805DDB14 - 1;
}

extern "C" void fn_80296068(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7AF4, &lbl_805D7AEC, 0);
}

extern "C" void fn_8029609C(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7AF4, &lbl_805D7AEC, 0);
}

extern "C" s32 fn_802960D0(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDB24 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_80296104(void * arg0) {
    if (lbl_805DDB24 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDB24;
        *(void **) ((char *) lbl_805DDB24 + 0x4) = arg0;
        lbl_805DDB24 = arg0;
    } else {
        lbl_805DDB28 = arg0;
        lbl_805DDB24 = arg0;
    }
    lbl_805DDB20 = lbl_805DDB20 + 1;
}

extern "C" void fn_8029613C(void * arg0) {
    if (lbl_805DDB24 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDB28;
        *(void **) ((char *) lbl_805DDB28 + 0x8) = arg0;
        lbl_805DDB28 = arg0;
    } else {
        lbl_805DDB28 = arg0;
        lbl_805DDB24 = arg0;
    }
    lbl_805DDB20 = lbl_805DDB20 + 1;
}

extern "C" void fn_80296178(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDB24 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDB28 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDB20 = lbl_805DDB20 - 1;
}

extern "C" void fn_802961F4(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7A0C, &lbl_805D7A04, 0);
}

extern "C" void fn_80296228(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7A0C, &lbl_805D7A04, 0);
}

extern "C" void fn_8029625C(s32 * arg0, s32 arg1) {
    FU32(arg0, 0x0) = arg1;
}

extern "C" f32 fn_80296264(void) {
    return lbl_805E335C;
}

extern "C" f32 fn_8029626C(f32 farg0) {
    return farg0 * lbl_805E335C;
}

extern "C" void kar_diag__80296278(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" {
void fn_8029C568(void *);
void kar_diagnostic__8029c5a4(void *);
void fn_8029C5E0(void *);
}

extern "C" void * fn_80296368(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        fn_8029C568(arg0);
        if (FP(arg0, 8) != 0) {
            fn_8038CB78(FP(arg0, 8));
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_802963C8(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        kar_diagnostic__8029c5a4(arg0);
        if (FP(arg0, 8) != 0) {
            fn_8038CB78(FP(arg0, 8));
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_80296428(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        fn_8029C5E0(arg0);
        if (FP(arg0, 8) != 0) {
            fn_8038CB78(FP(arg0, 8));
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80296488(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_80296858(void) {

}

extern "C" void fn_8029685C(void) {

}

extern "C" void fn_80296860(void * arg0, void * arg1) {
    (void) arg0;
    fn_8038CB78(arg1);
}

extern "C" s32 fn_80296884(void * arg0) {
    return (s32) ((char *) arg0 + 0x4);
}

extern "C" void fn_8029688C(void) {

}

extern "C" void fn_80296890(void) {

}

extern "C" void fn_80296894(void *** arg0, void * arg1, void *** arg2, void *** arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void * fn_80296948(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void fn_80296A14(void *** arg0, void * arg1, void *** arg2, void *** arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void * fn_80296AE0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_80296C70(void *** arg0, void * arg1, void *** arg2, void *** arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void * fn_80296D3C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_80297040(void *** arg0, void * arg1, void *** arg2, void *** arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void * fn_8029710C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_80297358(void *** arg0, void * arg1, void *** arg2, void *** arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void * fn_80297424(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802975C0(void *** arg0, void * arg1, void *** arg2, void *** arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void * fn_8029768C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_80297828(void *** arg0, void * arg1, void *** arg2, void *** arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void * fn_802978F4(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_80297B8C(void *** arg0, void * arg1, void *** arg2, void *** arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void * fn_80297C58(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_80297E78(void *** arg0, void * arg1, void *** arg2, void *** arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void * fn_80297F44(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_80297FE8(void *** arg0, void * arg1, void *** arg2, void *** arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" {
extern char lbl_804BF034[0x28];
}

extern "C" void * fn_802980B4(void * arg0, s16 arg1) {
    if (!arg0) goto ret;
    *(void **) arg0 = (void *) &lbl_804BF034;
    if (!arg0) goto after_ctor;
    *(void **) arg0 = (void *) &lbl_804BEFE4;
    ((VDispatch8 *) arg0)->v5();
after_ctor:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
ret:
    return arg0;
}

extern "C" void * fn_8029812C(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802981F8(void * arg0, s32 * arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg5;
    return 0;
}

extern "C" void * fn_8029840C(void * arg0, s32 * arg1, s16 arg2, s16 arg3, u32 arg4) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    return 0;
}

extern "C" void * fn_80298630(void * arg0, s32 * arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg5;
    return 0;
}

extern "C" void * fn_80298844(void * arg0, s32 * arg1, s16 arg2, s16 arg3, u32 arg4) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    return 0;
}

extern "C" void * fn_80298A68(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BE5FC;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F120C;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" u16 fn_80298AC4(void * arg0) {
    return FU16(arg0, 0x4);
}

extern "C" u16 fn_80298ACC(void * arg0) {
    return FU16(arg0, 0x6);
}

extern "C" void * fn_80298AD4(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BE658;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F120C;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80298B30(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BE6B4;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F120C;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80298B8C(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BE710;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F120C;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80298BE8(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BE76C;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F120C;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80298C44(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BE7C8;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F120C;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80298CA0(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BE824;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F120C;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80298CFC(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BE880;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F120C;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80298D58(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BE8E0;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F120C;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80298DB4(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BE940;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F120C;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80298E10(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BE9A0;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F120C;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80298E6C(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BEA00;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F120C;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80298EC8(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BEA60;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F120C;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80298F24(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BEAC0;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F120C;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80298F80(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BEB2C;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F1134;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" u16 fn_80298FDC(void * arg0) {
    return FU16(arg0, 0x4);
}

extern "C" u16 fn_80298FE4(void * arg0) {
    return FU16(arg0, 0x6);
}

extern "C" void * fn_80298FEC(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BEB80;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F1134;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80299048(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BEBD4;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F1134;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_802990A4(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BEC28;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F1134;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80299100(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BEC7C;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F1134;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_8029915C(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BECD0;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F1134;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_802991B8(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BED24;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F1134;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80299214(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BED78;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F1134;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80299270(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BEDD4;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F1134;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_802992CC(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BEE30;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F1134;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80299328(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BEE8C;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F1134;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80299384(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BEEE8;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F1134;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_802993E0(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BEF44;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F1134;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_8029943C(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BEFA0;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804F1134;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_80299498(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BEFE4;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_80299500(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BF078;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80299568(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D77D8, &lbl_805D77D0, 0);
}

extern "C" void * fn_8029959C(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BF0E4;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" {
u8 kar_fl_indirectload__near_80393820(void **, void **);
}

extern "C" void fn_80299604(void * arg0, void ** arg1) {
    kar_fl_indirectload__near_80393820((void **) ((char *) arg0 + 36), arg1);
}

extern "C" s32 fn_80299628(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802996B8(void * arg0) {
    (void) arg0;
}

extern "C" s32 fn_80299700(s32 arg0) {
    return (s32) ((char *) arg0 + 0x4);
}

extern "C" s32 fn_80299708(s32 arg0) {
    return (s32) ((char *) arg0 + 0x10);
}

extern "C" f32 fn_80299710(void * arg0) {
    return FF32(arg0, 0x1C);
}

extern "C" f32 fn_80299718(void * arg0) {
    return FF32(arg0, 0x20);
}

extern "C" void fn_80299720(void * arg0, void * arg1, void * arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void fn_80299754(void * arg0, f32 farg0, f32 farg1) {
    FF32(arg0, 0x1C) = farg0;
    FF32(arg0, 0x20) = farg1;
}

extern "C" void fn_80299760(void ** arg0) {
    (void) arg0;
}

extern "C" void kar_object__802998e0(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void * fn_8029990C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802999B8(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D76D8, &lbl_805D76D0, 0);
}

extern "C" void * fn_802999EC(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BF238;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" {
extern char lbl_804BF260[0x28];
}

extern "C" void * fn_80299A54(void * arg0, s16 arg1) {
    if (!arg0) goto ret;
    *(void **) arg0 = (void *) &lbl_804BF260;
    if (!arg0) goto after_ctor;
    *(void **) arg0 = (void *) &lbl_804BF238;
    ((VDispatch8 *) arg0)->v5();
after_ctor:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
ret:
    return arg0;
}

extern "C" void fn_80299ACC(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D77D8, &lbl_805D77D0, 0);
}

extern "C" void fn_80299B00(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D77C8, &lbl_805D77C0, 0);
}

extern "C" void * fn_80299B34(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BF2B4;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80299B9C(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D77B8, &lbl_805D77B0, 0);
}

extern "C" void fn_80299BD0(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void * fn_80299BFC(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BF2DC;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80299C64(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x5C), 0, &lbl_805D77B8, &lbl_805D77B0, 0);
}

extern "C" s32 fn_80299C98(void) {
    return 0;
}

extern "C" void fn_80299CA0(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D77A8, &lbl_805D77A0, 0);
}

extern "C" void fn_80299CD4(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void * fn_80299D00(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BF398;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void *** fn_80299D68(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BF3C0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80299DB0(void * arg0, void ** arg1) {
    kar_fl_indirectload__near_80393820((void **) ((char *) arg0 + 36), arg1);
}

extern "C" u8 fn_80299DD4(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_80299E68(void * arg0) {
    (void) arg0;
}

extern "C" void * fn_80299EB0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_80299F5C(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7798, &lbl_805D7790, 0);
}

extern "C" void * fn_80299F90(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BF48C;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80299FF8(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7768, &lbl_805D7760, 0);
}

extern "C" void * fn_8029A02C(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BF4B4;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8029A094(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BF4DC;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_8029A0FC(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D76B8, &lbl_805D7688, 0);
}

extern "C" void fn_8029A130(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D76B8, &lbl_805D7688, 0);
}

extern "C" void * fn_8029A164(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        *(void **) arg0 = (void *) &lbl_804BF504;
        ((VDispatch8 *) arg0)->v5();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_8029A1CC(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x58), 0, &lbl_805D76B8, &lbl_805D7688, 0);
}

extern "C" void fn_8029A200(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x5C), 0, &lbl_805D76B8, &lbl_805D7688, 0);
}

extern "C" void fn_8029A234(void * arg0) {
    (void) arg0;
}

extern "C" void fn_8029A2C8(void * arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" {
void GXInvalidateTexAll(void);
void fn_80391B1C(void);
void fn_80391C70(void *, void *, s32, void *, s32, void *);
void fn_80391C1C(void *, void *, s32, void *);
}

extern "C" void fn_8029A354(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C70(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 9, (void *) FU32(arg0, 8), 2, (void *) FU32(arg0, 0xC));
}

extern "C" void fn_8029A3D0(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C70(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 9, (void *) FU32(arg0, 8), 1, (void *) FU32(arg0, 0xC));
}

extern "C" void fn_8029A44C(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C70(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 9, (void *) FU32(arg0, 8), 0, (void *) FU32(arg0, 0xC));
}

extern "C" void fn_8029A4C8(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C70(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 8, (void *) FU32(arg0, 8), 2, (void *) FU32(arg0, 0xC));
}

extern "C" void fn_8029A544(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C70(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 8, (void *) FU32(arg0, 8), 1, (void *) FU32(arg0, 0xC));
}

extern "C" void fn_8029A5C0(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C70(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 8, (void *) FU32(arg0, 8), 0, (void *) FU32(arg0, 0xC));
}

extern "C" void fn_8029A63C(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C1C(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 14, (void *) FU32(arg0, 8));
}

extern "C" void fn_8029A6B0(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C1C(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 6, (void *) FU32(arg0, 8));
}

extern "C" void fn_8029A724(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C1C(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 5, (void *) FU32(arg0, 8));
}

extern "C" void fn_8029A798(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C1C(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 4, (void *) FU32(arg0, 8));
}

extern "C" void fn_8029A80C(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C1C(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 3, (void *) FU32(arg0, 8));
}

extern "C" void fn_8029A880(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C1C(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 2, (void *) FU32(arg0, 8));
}

extern "C" void fn_8029A8F4(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C1C(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 1, (void *) FU32(arg0, 8));
}

extern "C" void fn_8029A968(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C1C(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 0, (void *) FU32(arg0, 8));
}

extern "C" void fn_8029A9DC(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C70(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 9, (void *) FU32(arg0, 8), 2, (void *) FU32(arg0, 0xC));
}

extern "C" void fn_8029AA58(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C70(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 9, (void *) FU32(arg0, 8), 1, (void *) FU32(arg0, 0xC));
}

extern "C" void fn_8029AAD4(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C70(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 9, (void *) FU32(arg0, 8), 0, (void *) FU32(arg0, 0xC));
}

extern "C" void fn_8029AB50(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C70(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 8, (void *) FU32(arg0, 8), 2, (void *) FU32(arg0, 0xC));
}

extern "C" void fn_8029ABCC(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C70(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 8, (void *) FU32(arg0, 8), 1, (void *) FU32(arg0, 0xC));
}

extern "C" void fn_8029AC48(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C70(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 8, (void *) FU32(arg0, 8), 0, (void *) FU32(arg0, 0xC));
}

extern "C" void fn_8029ACC4(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C1C(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 14, (void *) FU32(arg0, 8));
}

extern "C" void fn_8029AD38(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C1C(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 6, (void *) FU32(arg0, 8));
}

extern "C" void fn_8029ADAC(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C1C(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 5, (void *) FU32(arg0, 8));
}

extern "C" void fn_8029AE20(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C1C(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 4, (void *) FU32(arg0, 8));
}

extern "C" void fn_8029AE94(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C1C(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 3, (void *) FU32(arg0, 8));
}

extern "C" void fn_8029AF08(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C1C(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 2, (void *) FU32(arg0, 8));
}

extern "C" void fn_8029AF7C(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C1C(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 1, (void *) FU32(arg0, 8));
}

extern "C" void fn_8029AFF0(void * arg0) {
    GXInvalidateTexAll();
    fn_80391B1C();
    fn_80391C1C(((VDispatch8R *) arg0)->v3(), ((VDispatch8R *) arg0)->v4(), 0, (void *) FU32(arg0, 8));
}

extern "C" void fn_8029B064(void * arg0) {
    (void) arg0;
}

extern "C" void fn_8029B1A8(void * arg0, void ** arg1) {
    *(u32 *) arg1 = FU32(arg0, 1536);
    FU32(arg0, 1536) = (u32) ((char *) arg1 - (char *) arg0) / 48;
    FU32(arg0, 1540) = FU32(arg0, 1540) + 1;
}

extern "C" void fn_8029B1D8(void * arg0, void ** arg1) {
    *(u32 *) arg1 = FU32(arg0, 336);
    FU32(arg0, 336) = (u32) ((char *) arg1 - (char *) arg0) / 56;
    FU32(arg0, 340) = FU32(arg0, 340) + 1;
}

extern "C" void fn_8029B214(void * arg0, void ** arg1) {
    *(u32 *) arg1 = FU32(arg0, 2064);
    FU32(arg0, 2064) = (u32) ((char *) arg1 - (char *) arg0) / 516;
    FU32(arg0, 2068) = FU32(arg0, 2068) + 1;
}

extern "C" void fn_8029B244(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_8029B280(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_8029B2A4(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_8029B2E0(void * arg0, void ** arg1) {
    *(u32 *) arg1 = FU32(arg0, 11264);
    FU32(arg0, 11264) = (u32) ((char *) arg1 - (char *) arg0) / 352;
    FU32(arg0, 11268) = FU32(arg0, 11268) + 1;
}

extern "C" void fn_8029B310(void * arg0, void ** arg1) {
    *(u32 *) arg1 = FU32(arg0, 26112);
    FU32(arg0, 26112) = (u32) ((char *) arg1 - (char *) arg0) / 408;
    FU32(arg0, 26116) = FU32(arg0, 26116) + 1;
}

extern "C" void fn_8029B340(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_8029B37C(void * arg0) {
    (void) arg0;
}

extern "C" void fn_8029B4A8(void * arg0, s32 * arg1) {
    *(u32 *) arg1 = FU32(arg0, 6656);
    FU32(arg0, 6656) = (u32) ((char *) arg1 - (char *) arg0) / 52;
    FU32(arg0, 6660) = FU32(arg0, 6660) + 1;
}

extern "C" s32 fn_8029B4D8(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DD9BC == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_8029B50C(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void fn_8029B538(void * arg0) {
    if (lbl_805DD9BC != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DD9BC;
        *(void **) ((char *) lbl_805DD9BC + 0x4) = arg0;
        lbl_805DD9BC = arg0;
    } else {
        lbl_805DD9C0 = arg0;
        lbl_805DD9BC = arg0;
    }
    lbl_805DD9B8 = lbl_805DD9B8 + 1;
}

extern "C" void fn_8029B570(void * arg0) {
    if (lbl_805DD9BC != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DD9C0;
        *(void **) ((char *) lbl_805DD9C0 + 0x8) = arg0;
        lbl_805DD9C0 = arg0;
    } else {
        lbl_805DD9C0 = arg0;
        lbl_805DD9BC = arg0;
    }
    lbl_805DD9B8 = lbl_805DD9B8 + 1;
}

extern "C" void fn_8029B5AC(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DD9BC = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DD9C0 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DD9B8 = lbl_805DD9B8 - 1;
}

extern "C" void fn_8029B628(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7C9C, &lbl_805D7C94, 0);
}

extern "C" void fn_8029B65C(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7C9C, &lbl_805D7C94, 0);
}

extern "C" s32 fn_8029B690(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DD9C8 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_8029B6C4(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void fn_8029B6F0(void * arg0) {
    if (lbl_805DD9C8 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DD9C8;
        *(void **) ((char *) lbl_805DD9C8 + 0x4) = arg0;
        lbl_805DD9C8 = arg0;
    } else {
        lbl_805DD9CC = arg0;
        lbl_805DD9C8 = arg0;
    }
    lbl_805DD9C4 = lbl_805DD9C4 + 1;
}

extern "C" void fn_8029B728(void * arg0) {
    if (lbl_805DD9C8 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DD9CC;
        *(void **) ((char *) lbl_805DD9CC + 0x8) = arg0;
        lbl_805DD9CC = arg0;
    } else {
        lbl_805DD9CC = arg0;
        lbl_805DD9C8 = arg0;
    }
    lbl_805DD9C4 = lbl_805DD9C4 + 1;
}

extern "C" void fn_8029B764(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DD9C8 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DD9CC = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DD9C4 = lbl_805DD9C4 - 1;
}

extern "C" void fn_8029B7E0(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7CAC, &lbl_805D7CA4, 0);
}

extern "C" void fn_8029B814(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7CAC, &lbl_805D7CA4, 0);
}

extern "C" s32 fn_8029B848(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DD9D4 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_8029B87C(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void fn_8029B8A8(void * arg0) {
    if (lbl_805DD9D4 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DD9D4;
        *(void **) ((char *) lbl_805DD9D4 + 0x4) = arg0;
        lbl_805DD9D4 = arg0;
    } else {
        lbl_805DD9D8 = arg0;
        lbl_805DD9D4 = arg0;
    }
    lbl_805DD9D0 = lbl_805DD9D0 + 1;
}

extern "C" void fn_8029B8E0(void * arg0) {
    if (lbl_805DD9D4 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DD9D8;
        *(void **) ((char *) lbl_805DD9D8 + 0x8) = arg0;
        lbl_805DD9D8 = arg0;
    } else {
        lbl_805DD9D8 = arg0;
        lbl_805DD9D4 = arg0;
    }
    lbl_805DD9D0 = lbl_805DD9D0 + 1;
}

extern "C" void fn_8029B91C(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DD9D4 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DD9D8 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DD9D0 = lbl_805DD9D0 - 1;
}

extern "C" void fn_8029B998(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D77D8, &lbl_805D77D0, 0);
}

extern "C" s32 fn_8029B9CC(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DD9E0 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_8029BA00(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void fn_8029BA2C(void * arg0) {
    if (lbl_805DD9E0 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DD9E0;
        *(void **) ((char *) lbl_805DD9E0 + 0x4) = arg0;
        lbl_805DD9E0 = arg0;
    } else {
        lbl_805DD9E4 = arg0;
        lbl_805DD9E0 = arg0;
    }
    lbl_805DD9DC = lbl_805DD9DC + 1;
}

extern "C" void fn_8029BA64(void * arg0) {
    if (lbl_805DD9E0 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DD9E4;
        *(void **) ((char *) lbl_805DD9E4 + 0x8) = arg0;
        lbl_805DD9E4 = arg0;
    } else {
        lbl_805DD9E4 = arg0;
        lbl_805DD9E0 = arg0;
    }
    lbl_805DD9DC = lbl_805DD9DC + 1;
}

extern "C" void fn_8029BAA0(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DD9E0 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DD9E4 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DD9DC = lbl_805DD9DC - 1;
}

extern "C" void fn_8029BB1C(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D77C8, &lbl_805D77C0, 0);
}

extern "C" s32 fn_8029BB50(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DD9EC == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_8029BB84(void * arg0) {
    if (lbl_805DD9EC != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DD9EC;
        *(void **) ((char *) lbl_805DD9EC + 0x4) = arg0;
        lbl_805DD9EC = arg0;
    } else {
        lbl_805DD9F0 = arg0;
        lbl_805DD9EC = arg0;
    }
    lbl_805DD9E8 = lbl_805DD9E8 + 1;
}

extern "C" void fn_8029BBBC(void * arg0) {
    if (lbl_805DD9EC != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DD9F0;
        *(void **) ((char *) lbl_805DD9F0 + 0x8) = arg0;
        lbl_805DD9F0 = arg0;
    } else {
        lbl_805DD9F0 = arg0;
        lbl_805DD9EC = arg0;
    }
    lbl_805DD9E8 = lbl_805DD9E8 + 1;
}

extern "C" void fn_8029BBF8(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DD9EC = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DD9F0 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DD9E8 = lbl_805DD9E8 - 1;
}

extern "C" void fn_8029BC74(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D77B8, &lbl_805D77B0, 0);
}

extern "C" s32 fn_8029BCA8(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DD9F8 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_8029BCDC(void * arg0) {
    if (lbl_805DD9F8 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DD9F8;
        *(void **) ((char *) lbl_805DD9F8 + 0x4) = arg0;
        lbl_805DD9F8 = arg0;
    } else {
        lbl_805DD9FC = arg0;
        lbl_805DD9F8 = arg0;
    }
    lbl_805DD9F4 = lbl_805DD9F4 + 1;
}

extern "C" void fn_8029BD14(void * arg0) {
    if (lbl_805DD9F8 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DD9FC;
        *(void **) ((char *) lbl_805DD9FC + 0x8) = arg0;
        lbl_805DD9FC = arg0;
    } else {
        lbl_805DD9FC = arg0;
        lbl_805DD9F8 = arg0;
    }
    lbl_805DD9F4 = lbl_805DD9F4 + 1;
}

extern "C" void fn_8029BD50(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DD9F8 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DD9FC = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DD9F4 = lbl_805DD9F4 - 1;
}

extern "C" void fn_8029BDCC(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D77A8, &lbl_805D77A0, 0);
}

extern "C" s32 fn_8029BE00(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDA04 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_8029BE34(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void fn_8029BE60(void * arg0) {
    if (lbl_805DDA04 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDA04;
        *(void **) ((char *) lbl_805DDA04 + 0x4) = arg0;
        lbl_805DDA04 = arg0;
    } else {
        lbl_805DDA08 = arg0;
        lbl_805DDA04 = arg0;
    }
    lbl_805DDA00 = lbl_805DDA00 + 1;
}

extern "C" void fn_8029BE98(void * arg0) {
    if (lbl_805DDA04 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDA08;
        *(void **) ((char *) lbl_805DDA08 + 0x8) = arg0;
        lbl_805DDA08 = arg0;
    } else {
        lbl_805DDA08 = arg0;
        lbl_805DDA04 = arg0;
    }
    lbl_805DDA00 = lbl_805DDA00 + 1;
}

extern "C" void fn_8029BED4(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDA04 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDA08 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDA00 = lbl_805DDA00 - 1;
}

extern "C" void fn_8029BF50(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7798, &lbl_805D7790, 0);
}

extern "C" s32 fn_8029BF84(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDA10 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_8029BFB8(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void fn_8029BFE4(void * arg0) {
    if (lbl_805DDA10 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDA10;
        *(void **) ((char *) lbl_805DDA10 + 0x4) = arg0;
        lbl_805DDA10 = arg0;
    } else {
        lbl_805DDA14 = arg0;
        lbl_805DDA10 = arg0;
    }
    lbl_805DDA0C = lbl_805DDA0C + 1;
}

extern "C" void fn_8029C01C(void * arg0) {
    if (lbl_805DDA10 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDA14;
        *(void **) ((char *) lbl_805DDA14 + 0x8) = arg0;
        lbl_805DDA14 = arg0;
    } else {
        lbl_805DDA14 = arg0;
        lbl_805DDA10 = arg0;
    }
    lbl_805DDA0C = lbl_805DDA0C + 1;
}

extern "C" void fn_8029C058(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDA10 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDA14 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDA0C = lbl_805DDA0C - 1;
}

extern "C" void fn_8029C0D4(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7768, &lbl_805D7760, 0);
}

extern "C" s32 fn_8029C108(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDA1C == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_8029C13C(void * arg0) {
    if (lbl_805DDA1C != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDA1C;
        *(void **) ((char *) lbl_805DDA1C + 0x4) = arg0;
        lbl_805DDA1C = arg0;
    } else {
        lbl_805DDA20 = arg0;
        lbl_805DDA1C = arg0;
    }
    lbl_805DDA18 = lbl_805DDA18 + 1;
}

extern "C" void fn_8029C174(void * arg0) {
    if (lbl_805DDA1C != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDA20;
        *(void **) ((char *) lbl_805DDA20 + 0x8) = arg0;
        lbl_805DDA20 = arg0;
    } else {
        lbl_805DDA20 = arg0;
        lbl_805DDA1C = arg0;
    }
    lbl_805DDA18 = lbl_805DDA18 + 1;
}

extern "C" void fn_8029C1B0(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDA1C = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDA20 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDA18 = lbl_805DDA18 - 1;
}

extern "C" void fn_8029C22C(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D7CCC, &lbl_805D7CC4, 0);
}

extern "C" void fn_8029C260(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x8), 0, &lbl_805D7CCC, &lbl_805D7CC4, 0);
}

extern "C" s32 fn_8029C294(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDA28 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_8029C2C8(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void fn_8029C2F4(void * arg0) {
    if (lbl_805DDA28 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDA28;
        *(void **) ((char *) lbl_805DDA28 + 0x4) = arg0;
        lbl_805DDA28 = arg0;
    } else {
        lbl_805DDA2C = arg0;
        lbl_805DDA28 = arg0;
    }
    lbl_805DDA24 = lbl_805DDA24 + 1;
}

extern "C" void fn_8029C32C(void * arg0) {
    if (lbl_805DDA28 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDA2C;
        *(void **) ((char *) lbl_805DDA2C + 0x8) = arg0;
        lbl_805DDA2C = arg0;
    } else {
        lbl_805DDA2C = arg0;
        lbl_805DDA28 = arg0;
    }
    lbl_805DDA24 = lbl_805DDA24 + 1;
}

extern "C" void fn_8029C368(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDA28 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDA2C = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDA24 = lbl_805DDA24 - 1;
}

extern "C" void fn_8029C3E4(void * arg0) {
    kar_diag__803ad760(FU32(arg0, 0x4), 0, &lbl_805D76D8, &lbl_805D76D0, 0);
}

extern "C" s32 fn_8029C418(void * arg0) {
    s32 result = 0;
    if (*(void **) ((char *) arg0 + 0x4) != 0 || *(void **) ((char *) arg0 + 0x8) != 0 || lbl_805DDA64 == arg0) {
        result = 1;
    }
    return result;
}

extern "C" void fn_8029C44C(void ** arg0) {
    ((VDispatch5 *) arg0)->v4();
}

extern "C" void fn_8029C478(void * arg0) {
    if (lbl_805DDA64 != 0) {
        *(void **) ((char *) arg0 + 0x8) = lbl_805DDA64;
        *(void **) ((char *) lbl_805DDA64 + 0x4) = arg0;
        lbl_805DDA64 = arg0;
    } else {
        lbl_805DDA68 = arg0;
        lbl_805DDA64 = arg0;
    }
    lbl_805DDA60 = lbl_805DDA60 + 1;
}

extern "C" void fn_8029C4B0(void * arg0) {
    if (lbl_805DDA64 != 0) {
        *(void **) ((char *) arg0 + 0x4) = lbl_805DDA68;
        *(void **) ((char *) lbl_805DDA68 + 0x8) = arg0;
        lbl_805DDA68 = arg0;
    } else {
        lbl_805DDA68 = arg0;
        lbl_805DDA64 = arg0;
    }
    lbl_805DDA60 = lbl_805DDA60 + 1;
}

extern "C" void fn_8029C4EC(void * arg0) {
    void *next = *(void **) ((char *) arg0 + 0x4);
    if (next == 0) {
        void *prev = *(void **) ((char *) arg0 + 0x8);
        lbl_805DDA64 = prev;
        if (prev != 0) {
            *(void **) ((char *) prev + 0x4) = 0;
        }
    } else {
        *(void **) ((char *) next + 0x8) = *(void **) ((char *) arg0 + 0x8);
    }
    void *prev2 = *(void **) ((char *) arg0 + 0x8);
    if (prev2 == 0) {
        void *next2 = *(void **) ((char *) arg0 + 0x4);
        lbl_805DDA68 = next2;
        if (next2 != 0) {
            *(void **) ((char *) next2 + 0x8) = 0;
        }
    } else {
        *(void **) ((char *) prev2 + 0x4) = *(void **) ((char *) arg0 + 0x4);
    }
    *(void **) ((char *) arg0 + 0x8) = 0;
    *(void **) ((char *) arg0 + 0x4) = 0;
    lbl_805DDA60 = lbl_805DDA60 - 1;
}

extern "C" void fn_8029C568(void * arg0) {
    (void) arg0;
}

extern "C" void kar_diagnostic__8029c5a4(void * arg0) {
    (void) arg0;
}

extern "C" void fn_8029C5E0(void * arg0) {
    (void) arg0;
}

extern "C" void fn_8029C618(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_8029C620(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_8029C628(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_8029C630(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_8029C638(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_8029C640(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_8029C648(s32 arg0) {
    (void) arg0;
}

extern "C" u8 fn_8029C650(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" s32 fn_8029CF24(s32 arg0) {
    return (s32) ((char *) arg0 + 0x94);
}

extern "C" s32 fn_8029CF2C(void) {
    return 1;
}

extern "C" void fn_8029CF34(void * arg0, s32 * arg1, s32 * arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" s32 fn_8029CF48(void) {
    return 0;
}

extern "C" s32 fn_8029CF50(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" s32 fn_8029CF7C(void) {
    return 1;
}

extern "C" s32 fn_8029CF84(void) {
    return 0;
}

#pragma dont_inline on
extern "C" void fn_8029CF8C(void * arg0) {
    FU32(arg0, 0x0) = 0;
}
#pragma dont_inline off

extern "C" s32 fn_8029D6FC(void) {
    return 0;
}

extern "C" void fn_8029D704(void) {
    HSD_CObjEndCurrent();
    lbl_805DDC90 = 0;
}

extern "C" s32 fn_8029D72C(void * arg0) {
    s32 r = HSD_CObjSetCurrent(*(void **) ((char *) arg0 + 8));
    lbl_805DDC90 = (s32) arg0;
    return (u32) (-r | r) >> 31;
}

extern "C" void * fn_8029D76C(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_8029DE08(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BFA54;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804BFA40;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void *** fn_8029DE64(void *** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void **) &lbl_804BFA40;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" s32 fn_8029DEAC(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_8029E334(void * arg0, void * arg1, u8 arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    return 0;
}

extern "C" void * fn_8029EC44(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BF99C;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804BD254;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_8029ECA0(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804BF9DC;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804BD254;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" s32 fn_8029ECFC(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_8029EDA4(void * arg0, void * arg1, u8 arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    return 0;
}

extern "C" s32 fn_8029EFE8(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void fn_802A0428(f32 * arg0, void * arg1) {
    FF32(arg0, 0x0) = FF32(arg1, 0xB4);
}

extern "C" s32 fn_802A0434(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" u8 fn_802A0488(void * arg0) {
    return FU8(arg0, 0xF);
}

extern "C" s32 fn_802A0490(void * arg0) {
    return FU32(arg0, 0x1C);
}

extern "C" u8 fn_802A0498(void * arg0) {
    return FU8(arg0, 0x10);
}

extern "C" s32 fn_802A04A0(void * arg0) {
    return FU32(arg0, 0x20);
}

extern "C" u8 fn_802A04A8(void * arg0) {
    return FU8(arg0, 0x3E);
}

extern "C" void * fn_802A04B0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802A051C(void * arg0) {
    (void) arg0;
}

extern "C" u8 fn_802A0548(void * arg0) {
    return FU8(arg0, 0xD);
}

extern "C" u8 fn_802A0550(void * arg0) {
    return FU8(arg0, 0xC);
}

extern "C" s32 fn_802A0558(void) {
    return 1;
}

extern "C" void * fn_802A0560(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802A05CC(void * arg0) {
    fn_8029CF8C(arg0);
}

extern "C" s32 fn_802A05EC(void) {
    return 0;
}

extern "C" s32 fn_802A05F4(void) {
    return 1;
}

extern "C" u8 fn_802A05FC(void * arg0) {
    return FU8(arg0, 0xC);
}

extern "C" u8 fn_802A0604(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" s32 fn_802A0658(void) {
    return 1;
}

extern "C" u8 fn_802A0660(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" s32 fn_802A06B4(void) {
    return 1;
}

extern "C" u8 fn_802A06BC(void * arg0, f32 * arg1, f32 * arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    return 0;
}

extern "C" void * fn_802A0754(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_802A07C0(void) {
    return 0;
}

extern "C" s32 fn_802A07C8(void) {
    return 0;
}

extern "C" s32 fn_802A07D0(void) {
    return 1;
}

extern "C" f32 kar_diagnostic__802a07d8(void ** arg0, f32 farg0) {
    (void) arg0;
    (void) farg0;
    return 0.0f;
}

extern "C" s32 fn_802A0884(void ** arg0) {
    (void) arg0;
    return 0;
}

extern "C" void fn_802A08CC(void * arg0, s32 * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" s32 fn_802A0984(void * arg0, f32 farg0) {
    (void) arg0;
    (void) farg0;
    return 0;
}

extern "C" void * fn_802A09E4(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void ** fn_802A0AC4(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804BFB00;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_802A0B0C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A0CC8(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802A0DD4(void * arg0, u8 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A0E88(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802A0EE8(void * arg0, s32 arg1) {
    FU8(arg0, 0xB24) = 1;
    FU32(arg0, 0xB28) = arg1;
}

extern "C" s32 fn_802A0EF8(void * arg0, s32 arg1) {
    s32 *arr = (s32 *) ((char *) arg0 + 0xB30);
    return arr[arg1];
}

extern "C" void fn_802A0F08(void * arg0, s32 arg1, s32 arg2) {
    s32 *arr = (s32 *) ((char *) arg0 + 0xB30);
    arr[arg1] = arg2;
}

extern "C" s32 fn_802A0F18(void * arg0) {
    return FU32(arg0, 0xB40);
}

extern "C" u8 fn_802A0F20(void * arg0) {
    return FU8(arg0, 0xB44);
}

extern "C" void fn_802A0F28(void * arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void * fn_802A0F98(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_802A1A0C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A1CEC(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A1E50(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A2114(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A2258(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A2368(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A2454(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A24F8(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A25E4(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A28C0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A2B9C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A2C1C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A32E4(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A3B88(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A3D58(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A3E7C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A4038(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A419C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A4414(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A4524(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A4724(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A487C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A4B3C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A4D60(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A509C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A51E4(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A5264(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A5710(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A5974(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A5C0C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A5D34(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        void *inner = FP(arg0, 0);
        if (inner != 0) {
            ((VDispatch1I *) inner)->v0(1);
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_802A5DA0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A6038(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A6148(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A63E0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A649C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A6734(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A6808(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A6AA0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A6BD4(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A6E6C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A6F40(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A71D8(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A72D0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A7568(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A76F0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A7988(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A7B40(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A7DD8(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A7ED0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A8168(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A8290(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A8528(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A8620(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A88B8(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A8A40(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A8CD8(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A8E0C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A90A4(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A919C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A9434(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A94CC(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A9764(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A9844(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A9ADC(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A9BEC(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A9E84(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802A9F58(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AA1F0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AA2DC(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AA574(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AA60C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AA8A4(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AA930(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AA9C8(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AAA38(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AAAA8(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AAB18(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AAD08(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AAE4C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AAEAC(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AAF90(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AB198(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AB318(void * arg0, s16 arg1) {
    if (arg0 != 0) {
        void *inner = FP(arg0, 0);
        if (inner != 0) {
            ((VDispatch1I *) inner)->v0(1);
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_802AB384(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AB70C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802ABA8C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802ABD44(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802ABE0C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802ABFB4(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AC0A0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AC1C0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AC240(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AC570(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AC644(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AC6F4(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AC7B8(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_802AC850(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void fn_802ACE18(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802ADCEC(void * arg0) {
    (void) arg0;
}

extern "C" f32 fn_802ADD18(f32 farg0) {
    (void) farg0;
    return 0.0f;
}

extern "C" f32 fn_802AE174(f32 farg0) {
    (void) farg0;
    return 0.0f;
}

extern "C" void fn_802AE5C0(f32 * arg0, void * arg1) {
    FF32(arg0, 0x0) = FF32(arg1, 0x34);
}

extern "C" s32 fn_802AE5CC(s32 arg0) {
    return (s32) ((char *) arg0 + 0xA0);
}

extern "C" void * fn_802AE5D4(void * arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804F5078;
    if (arg0 == 0) {
        goto skip_second;
    }
    *(void **) arg0 = (void *) &lbl_804BC430;
skip_second:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void ** fn_802AE630(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804C0470;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_802AE678(void) {

}

extern "C" s32 fn_802AEC6C(s32 arg0) {
    return (s32) ((char *) arg0 + 0x13C);
}

extern "C" void fn_802AEC74(void) {

}

extern "C" void fn_802AEC78(void) {

}

extern "C" void fn_802AEC7C(void * arg0, s32 arg1, s32 arg2, s32 * arg3, s32 * arg4) {
    (void) arg1;
    (void) arg2;
    *arg3 = FU32(arg0, 0x4);
    *arg4 = FU32(arg0, 0x8);
}

extern "C" void fn_802AEC90(void * arg0, s32 arg1) {
    FU32(arg0, 0x4) += arg1;
}

extern "C" void fn_802AECA0(void * arg0) {
    FU32(arg0, 0x4) = 0;
}

extern "C" void * fn_802AECAC(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_802AEDB8(void) {
    return 1;
}

extern "C" void ** fn_802AEDC0(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804C04D4;
        lbl_805DDB34 = 0;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_802AEE10(void * arg0) {
    (void) arg0;
}

extern "C" s32 fn_802AEE5C(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" {
extern char lbl_805D800C[8];
extern char lbl_805D7F20[8];
u8 fn_8039A7BC(void *, s32);
void kar_a2d_effect_slideblur__near_80381a44(void);
void kar_a2d_effect_slideblur__near_80381a50(void);
}

extern "C" void fn_802AEE6C(void * arg0, s32 arg1) {
    if (FU8(arg0, 4) != 0) {
        if (fn_8039A7BC(kar_diag__803ad760(arg1, 0, &lbl_805D800C, &lbl_805D7F20, 0), 5) != 0) {
            kar_a2d_effect_slideblur__near_80381a44();
            kar_a2d_effect_slideblur__near_80381a50();
        }
    }
}

extern "C" void fn_802AEEC4(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802AEF98(void) {

}

extern "C" u8 fn_802AEF9C(void * arg0) {
    return FU8(arg0, 0xC4);
}

extern "C" void fn_802AEFA4(void * arg0, u8 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802AF02C(void) {

}

extern "C" void fn_802AF030(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802AF050(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802AF098(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802AF1C0(void * arg0) {
    (void) arg0;
}

extern "C" void * fn_802AF384(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AF3CC(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802AF410(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AF548(void * arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AF6C0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AF7C8(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AF834(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AF87C(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802AF8C0(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802AFA10(s32 arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802AFA78(void * arg0) {
    (void) arg0;
}

extern "C" {
void kar_a2d_bg8000__near_80344ac0(void);
void kar_a2d_bg8000__near_80344b2c(void);
void kar_a2d_bg5000__near_80341f90(void);
void kar_a2d_bg5000__near_80341ffc(void);
void kar_a2d_bg4000__near_8033ebb0(void);
void kar_a2d_bg4000__near_8033ec1c(void);
void kar_a2d_bg3000__near_8033ab00(void);
void kar_a2d_bg3000__near_8033ab6c(void);
void kar_a2d_grindrail__near_80334c3c(void);
void kar_a2d_grindrail__near_80334ca8(void);
}

extern "C" void fn_802AFAE4(void * arg0, s32 arg1) {
    if (FU8(arg0, 4) != 0) {
        if (fn_8039A7BC(kar_diag__803ad760(arg1, 0, &lbl_805D800C, &lbl_805D7F20, 0), 5) != 0) {
            kar_a2d_bg8000__near_80344ac0();
            kar_a2d_bg8000__near_80344b2c();
        }
    }
}

extern "C" void fn_802AFB3C(void * arg0, s32 arg1) {
    if (FU8(arg0, 4) != 0) {
        if (fn_8039A7BC(kar_diag__803ad760(arg1, 0, &lbl_805D800C, &lbl_805D7F20, 0), 5) != 0) {
            kar_a2d_bg5000__near_80341f90();
            kar_a2d_bg5000__near_80341ffc();
        }
    }
}

extern "C" void fn_802AFB94(void * arg0, s32 arg1) {
    if (FU8(arg0, 4) != 0) {
        if (fn_8039A7BC(kar_diag__803ad760(arg1, 0, &lbl_805D800C, &lbl_805D7F20, 0), 5) != 0) {
            kar_a2d_bg4000__near_8033ebb0();
            kar_a2d_bg4000__near_8033ec1c();
        }
    }
}

extern "C" void fn_802AFBEC(void * arg0, s32 arg1) {
    if (FU8(arg0, 4) != 0) {
        if (fn_8039A7BC(kar_diag__803ad760(arg1, 0, &lbl_805D800C, &lbl_805D7F20, 0), 5) != 0) {
            kar_a2d_bg3000__near_8033ab00();
            kar_a2d_bg3000__near_8033ab6c();
        }
    }
}

extern "C" void fn_802AFC44(void * arg0, s32 arg1) {
    if (FU8(arg0, 4) != 0) {
        if (fn_8039A7BC(kar_diag__803ad760(arg1, 0, &lbl_805D800C, &lbl_805D7F20, 0), 5) != 0) {
            kar_a2d_grindrail__near_80334c3c();
            kar_a2d_grindrail__near_80334ca8();
        }
    }
}

extern "C" void fn_802AFC9C(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802AFCF4(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void * fn_802AFD4C(void ** arg0, void ** arg1, void * arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_802AFECC(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802AFF5C(void * arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void kar_diag__802affd8(void * arg0, void ** arg1, u32 arg2, void ** arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
}

extern "C" void kar_diag__802b042c(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802B0598(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B0A14(void) {

}

extern "C" void fn_802B0A18(void) {

}

extern "C" void fn_802B0A1C(void) {

}

extern "C" void fn_802B0A20(void * arg0, void * arg1) {
    (void) arg0;
    fn_8038CB78(arg1);
}

extern "C" s32 fn_802B0A44(void * arg0) {
    return (s32) ((char *) arg0 + 0x4);
}

extern "C" void fn_802B0A4C(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802B0AB4(void) {

}

extern "C" void fn_802B0AB8(void ** arg0, s32 * arg1, void *** arg2, f32 ** arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
}

extern "C" void fn_802B0B88(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void ** fn_802B0D84(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) &lbl_804C4B00;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_802B0DCC(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B0FC8(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B11C4(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B13C0(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B15BC(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B17B8(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B19B4(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B1BB0(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B1DAC(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B1FA8(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B21A4(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B23A0(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B259C(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B2798(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B2994(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B2B90(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B2D8C(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B2F88(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B3184(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B3380(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B357C(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802B3778(void * arg0, void *** arg1, void *** arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
}

extern "C" void * kar_diag__802b3860(void ** arg0, s32 arg1, u8 arg2, u8 arg3, void ** arg4, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg_sp0;
    return 0;
}

extern "C" void fn_802B3968(void * arg0, void ** arg1, void * arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void ** fn_802B3998(void ** arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802B39D8(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_802B3A1C(s32 arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802B3A4C(void * arg0, void * arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
    return 0;
}

extern "C" s32 fn_802B3B6C(void ** arg0) {
    return (s32) ((char *) arg0 + 0x4);
}

extern "C" void fn_802B3B74(void *** arg0, void * arg1, void *** arg2, void *** arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void fn_802B3C24(void * arg0) {
    void *p = (char *) arg0 + 0x4;
    FU32(arg0, 0x0) = 0;
    FP(p, 0x4) = p;
    FP(p, 0x0) = p;
}

extern "C" void fn_802B3C3C(void ** arg0) {
    void *p = (char *) arg0 + 0x4;
    FU32(arg0, 0x0) = 0;
    FP(p, 0x4) = p;
    FP(p, 0x0) = p;
}

extern "C" void fn_802B3C54(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3C5C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3C64(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3C6C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3C74(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3C7C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3C84(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3C8C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3C94(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3C9C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3CA4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3CAC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3CB4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3CBC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3CC4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3CCC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3CD4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3CDC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3CE4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3CEC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3CF4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3CFC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D04(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D0C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D14(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D1C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D24(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D2C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D34(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D3C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D44(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D4C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D54(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D5C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D64(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D6C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D74(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D7C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D84(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D8C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D94(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3D9C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3DA4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3DAC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3DB4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3DBC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3DC4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3DCC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3DD4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3DDC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3DE4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3DEC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3DF4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3DFC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E04(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E0C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E14(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E1C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E24(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E2C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E34(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E3C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E44(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E4C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E54(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E5C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E64(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E6C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E74(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E7C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E84(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E8C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E94(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3E9C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3EA4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3EAC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3EB4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3EBC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3EC4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3ECC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3ED4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3EDC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3EE4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3EEC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3EF4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3EFC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F04(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F0C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F14(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F1C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F24(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F2C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F34(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F3C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F44(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F4C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F54(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F5C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F64(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F6C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F74(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F7C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F84(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F8C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F94(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3F9C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3FA4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3FAC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3FB4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3FBC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3FC4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3FCC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3FD4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3FDC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3FE4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3FEC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3FF4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B3FFC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B4004(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B400C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B4014(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B401C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B4024(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B402C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B4034(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B403C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B4044(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B404C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B4054(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B405C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B4064(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B406C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B4074(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B407C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B4084(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B408C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B4094(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B409C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B40A4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B40AC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B40B4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B40BC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B40C4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B40CC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B40D4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B40DC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B40E4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B40EC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B40F4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B40FC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802B4104(s32 arg0) {
    (void) arg0;
}

extern "C" void * fn_802B410C(void * arg0, s32 arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
    return 0;
}

extern "C" s32 fn_802B434C(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void fn_802B4620(void * arg0) {
    (void) arg0;
}
