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

class VDispatch {
public:
    virtual void v0(s32);
    virtual u32 v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual u32 v8();
    virtual void v9();
    virtual u32 v10();
    virtual void v11();
    virtual void v12(s32);
    virtual u8 v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual u8 v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56(s32, void *);
};

class VColorWidget {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(void *);
    virtual void v4();
    virtual void v5(void *);
};

struct Color4 {
    u8 r, g, b, a;
};

struct Vec3f {
    f32 x, y, z;
};

class VGeom {
public:
    virtual Vec3f *v0();
    virtual f32 v1();
};

class VGeom2 {
public:
    virtual Vec3f *v0();
    virtual Vec3f *v1();
};

extern "C" {
extern char lbl_804D40F0[0x2A08];
extern char lbl_804D7F48[0x528];
extern char lbl_804D1A98[0x80];
extern char lbl_804D1EB8[0xC];
extern char lbl_804D1EE4[0xE0];
extern char lbl_804D20F0[0xE0];
extern char lbl_804D21F4[0xE0];
extern char lbl_804D6F5C[0xE4];

void kar_a2d_kirbyjointanim__near_802effb8(s32, void *, s32);
f32 fn_80296264(f32);
f32 fn_8029626C(f32);
extern char lbl_804F5230[0x3C];
extern char lbl_804F526C[0x3C];
extern char lbl_804F52A8[0x3C];
extern const f32 lbl_805E3690;
extern const f32 lbl_805E3728;
extern const f32 lbl_805E372C;
extern const f32 lbl_805E3734;
extern const f32 lbl_805E3730;
extern const f32 lbl_805E3780;
extern const f32 lbl_805E37A0;
extern const f32 lbl_805E3834;
extern const f32 lbl_805E3788;
extern const f32 lbl_805E3790;
extern const f32 lbl_805E3798;
extern const f32 lbl_805E378C;
extern const f32 lbl_805E3870;
extern const f32 lbl_805E3880;
extern const f32 lbl_805E3940;

f32 kar_diagnostic__802a07d8(void *, f32);
f32 kar_a2d_game_lib__near_802889d0(f32 *, f32 *, f32);
void * kar_a2d_gamesession__80289138(void);
extern f32 lbl_805DC8BC[];
extern char lbl_804CB3F8[0xD1C];
void *kar_a2d_gamehistory__near_802b585c(void *);
extern f32 lbl_805D9050;
extern f32 lbl_805D9054;
extern char lbl_804D22E4[0xC];
void HSD_JObjDisp(void *, void *, u32, u32);
extern char lbl_804F8404[0x124];
extern char lbl_804C0EC0[0x94];
extern char lbl_804C1058[0x94];
extern char lbl_805D8A20[0x8];
extern char lbl_805D8A28[0x8];
void *kar_a2d_gamehistory__near_802b57f4(void *);
void *kar_diag__803ad760(s32, s32, void *, void *, s32);
extern s32 lbl_805DDBC4;
extern char lbl_805D8EC0[0x8];
extern char lbl_805D8ED0[0x8];
extern char lbl_805D8ED8[0x8];
extern char lbl_804F3510[0x48];
extern char lbl_804BD724[0x28];
extern char lbl_804F32A8[0x48];
extern char lbl_804F54B8[0x98];
extern char lbl_804BD6A0[0x34];
extern char lbl_804BD658[0x28];

void HSD_JObjAnimAll(void *jobj);
void PSVECSubtract(void *, void *, void *);
void PSVECScale(void *, void *, f32);
void PSVECAdd(void *, void *, void *);
f32 PSVECSquareMag(void *);
void PSVECNormalize(void *, void *);
void *fn_803120C0(void *arg0);
void *kar_fl_indirectload__near_80393820(void *arg0);
void fn_8038CB78(void *arg0);
void *fn_802FB060(void *, void *, s32, s32, s32, s32);
void *fn_802F8A5C(void *, void *, s32, s32, s32, s32);
void *fn_802F858C(void *, void *, s32);
void *fn_802FAA88(void *, void *, s32);
void *fn_802F4068(void *, void *);
void *fn_802FA16C(void *, void *);
extern char lbl_805D90B0[0x8];
extern char lbl_805D90C8[0x8];
extern char lbl_805D9098[0x8];
void kar_a2d_game_audio__near_803792b8(s32);
extern s32 lbl_805DDC70;
extern char lbl_804D0E3C[0x38];
extern char lbl_804D0E8C[0x14];
extern char lbl_804D0F20[0x18];
extern char lbl_804BE104[0x28];
extern char lbl_804BE0C4[0x28];
extern char lbl_805D90D8[0x8];
extern char lbl_805D90E0[0x8];
extern char lbl_805D90E8[0x8];
void *fn_802F6138(void *, void *, s32, s32, s32, s32);
void *fn_802F6C28(void *, void *, s32, s32, s32, s32);
void *fn_802F7718(void *, void *, s32, s32, s32);
void *fn_802F7B28(void *, void *, s32, s32, s32);

extern void *lbl_805DD96C;
extern void *lbl_805DD974;
extern void *lbl_805DD97C;
extern void *lbl_805DD984;
extern void *lbl_805DD98C;

extern char lbl_804D7104[0x60];
extern char lbl_804D719C[0x60];
extern char lbl_804D7260[0x68];
extern char lbl_804D7300[0x68];
extern char lbl_804D743C[0x60];
extern char lbl_804D74D0[0x60];
extern char lbl_804D7568[0x68];
extern char lbl_804D7604[0x68];
extern char lbl_804D76A0[0x60];
extern char lbl_804D7700[0x38];
extern char lbl_804BDB74[0x28];
extern char lbl_804BF3C0[0x30];
extern char lbl_804BF4DC[0x28];
}

extern "C" {
void TopRide_CheckSessionFinalizeObjectives(void * arg0, s32 arg_sp0);
void TopRide_CheckPerCourseObjectives_B(void * arg0, s32 arg_sp0);
void * kar_a2d_gamesession__near_802b87dc(void * arg0, void ** arg1);
void TopRide_CheckPerCourseObjectives(void * arg0, s32 arg_sp0);
void kar_a2d_gamesession__near_802ba0dc(void);
u32 kar_a2d_gamesession__near_802ba0e0(void);
s32 fn_802BA114(u32 arg1);
void * fn_802BA2D8(void * arg0);
void fn_802BA850(void ** arg0);
void ** fn_802BA880(void ** arg0);
void * fn_802BA92C(void * arg0);
void * fn_802BA97C(void * arg0, void * arg1);
void * fn_802BA9C8(void * arg0);
void **** fn_802BAA18(void **** arg0, s16 arg1);
void **** fn_802BAAB4(void **** arg0, s16 arg1);
void **** fn_802BAB18(void **** arg0, s16 arg1);
void **** fn_802BAB78(void **** arg0);
u8 fn_802BABB4(void * arg0);
void fn_802BAD20(s32 arg0, void ** arg1, s32 arg2, s32 arg3);
void * fn_802BB4DC(void * arg0);
void * fn_802BC220(void * arg0, void *** arg1, u8 arg2, void * arg_sp0);
void * fn_802BC518(void * arg0, void *** arg1, s32 arg2, f32 farg0, f32 farg1);
void **** fn_802BC7E8(void **** arg0, s16 arg1);
void **** fn_802BC8B0(void **** arg0, s16 arg1);
void fn_802BC968(void * arg0, void ** arg1);
void * fn_802BD504(void * arg0);
void * fn_802BE1B8(void * arg0, void *** arg1, s32 arg2, f32 * arg3, f32 farg0, f32 farg1);
void fn_802BE48C(void * arg0, void ** arg1);
void * fn_802BE970(void * arg0);
void **** fn_802BEEC8(void **** arg0, s16 arg1);
void **** fn_802BF05C(void **** arg0, s16 arg1);
void fn_802BF160(void * arg0, void ** arg1);
void * fn_802BF1B8(void * arg0, f32 * arg1);
void **** fn_802BF298(void **** arg0, s16 arg1);
void **** fn_802BF360(void **** arg0, s16 arg1);
void ** fn_802BF41C(void ** arg0, s32 arg1);
void * fn_802BF5C4(void * arg0);
void * fn_802BFAE0(void * arg0);
void * fn_802C0560(void * arg0);
void * fn_802C08D8(void * arg0);
void * fn_802C1100(void * arg0);
void * fn_802C15E0(void * arg0);
void * fn_802C21C8(void * arg0);
void * fn_802C2AF8(void * arg0);
void fn_802C32F4(void * arg0);
void * fn_802C3414(void * arg0, f32 * arg2);
void * fn_802C368C(void * arg0);
void fn_802C3A1C(void * arg0);
void * fn_802C3ACC(void * arg0, s32 arg_sp0);
void fn_802C40E4(void ** arg0);
void fn_802C40FC(void ** arg0);
void fn_802C4114(void ** arg0);
void * fn_802C412C(void * arg0);
void * fn_802C4378(void * arg0);
void fn_802C4620(void * arg0);
void fn_802C48D0(void * arg0);
void fn_802C4A2C(s32 arg0);
void fn_802C4A34(s32 arg0);
void fn_802C4A3C(s32 arg0);
void fn_802C4A44(s32 arg0);
void fn_802C4A4C(s32 arg0);
void fn_802C4A54(s32 arg0);
void fn_802C4A5C(s32 arg0);
void fn_802C4A64(s32 arg0);
void fn_802C4A6C(s32 arg0);
void fn_802C4A74(s32 arg0);
void fn_802C4A7C(s32 arg0);
void fn_802C4A84(s32 arg0);
void fn_802C4A8C(s32 arg0);
void fn_802C4A94(s32 arg0);
void fn_802C4A9C(s32 arg0);
void fn_802C4AA4(s32 arg0);
void fn_802C4AAC(s32 arg0);
void fn_802C4AB4(s32 arg0);
void fn_802C4ABC(s32 arg0);
void fn_802C4AC4(s32 arg0);
void fn_802C4ACC(s32 arg0);
void fn_802C4AD4(s32 arg0);
void * fn_802C4ADC(void * arg0, void * arg1);
s32 fn_802C50AC(void * arg0, s32 arg_sp0);
void fn_802C5520(void * arg0);
void * fn_802C5574(void * arg0, void * arg1);
void * fn_802C5F14(void * arg0);
void * fn_802C601C(void * arg0);
void * fn_802C6130(void * arg0);
void * fn_802C6344(void * arg0);
void * fn_802C63F8(void * arg0);
void * fn_802C660C(void * arg0);
u8 fn_802C681C(void * arg0);
u8 fn_802C69E8(void * arg0);
void fn_802C6BE0(void * arg0);
u8 fn_802C6C04(void * arg0);
void ** fn_802C6DF8(void ** arg0, void ** arg1, void ** arg2);
void fn_802C7B48(void ** arg0);
void fn_802C7B54(void * arg0, u8 arg1);
void fn_802C80DC(char * arg0, s32 arg1, u32 arg2);
void fn_802C8100(s32 arg0, s32 arg1);
void fn_802C81CC(void * arg0, u8 arg1, s32 arg_sp0);
void ** fn_802C8294(void ** arg0, void ** arg1, void ** arg2);
void fn_802C85E8(void);
void fn_802C85EC(void * arg0);
f32 fn_802C89A0(f32 farg0);
f32 fn_802C8DFC(f32 farg0);
void ** fn_802C9248(void ** arg0, void ** arg1);
void fn_802C958C(void * arg0, u32 arg1);
void ** fn_802C9978(void ** arg0, void ** arg1);
void fn_802C9F4C(void ** arg0, s32 arg_sp0);
void fn_802CA134(void ** arg1, u32 arg2, u32 arg3, u8 arg4);
void ** fn_802CA598(void ** arg0, void ** arg1, s8 arg2);
void ** fn_802CA894(void ** arg0, void ** arg1, void ** arg2, s32 arg_sp0);
void fn_802CB234(void * arg0);
void fn_802CBB40(void * arg0);
void fn_802CBC50(void * arg0);
void **** fn_802CBF08(void **** arg0, s16 arg1);
void fn_802CBFEC(void * arg0);
void **** fn_802CC028(void **** arg0, s16 arg1);
void fn_802CC10C(void * arg0);
void ** fn_802CC148(void ** arg0);
void fn_802CD8DC(void ** arg0);
u8 fn_802CD8F0(void ** arg0, f32 * arg1, f32 * arg2, u32 arg3, u32 arg4, f32 farg0);
u8 fn_802CDF04(f32 * arg1, u32 * arg2, f32 * arg3, f32 * arg4, f32 * arg5);
void fn_802CE780(f32 * arg0, void ** arg1, f32 * arg2, f32 * arg3, f32 * arg4);
s8 fn_802CEA10(f32 * arg1, u32 arg2);
void fn_802CEC68(void ** arg0, u32 arg1);
void fn_802CF348(void ** arg0);
void fn_802CF3D4(void ** arg0, u32 arg1);
void fn_802CF6DC(void ** arg0);
void fn_802CF768(void ** arg0);
void fn_802CF83C(void * arg0);
f32 fn_802D06F0(f32 farg0);
f32 fn_802D0B4C(f32 farg0);
u8 fn_802D0F98(f32 * arg0, f32 * arg1, f32 * arg2, f32 * arg3);
void fn_802D10BC(f32 * arg0, f32 * arg1, f32 * arg2, f32 * arg3);
void fn_802D1204(f32 * arg0, f32 * arg1, f32 * arg2);
void fn_802D12D8(f32 * arg0, f32 * arg1, f32 * arg2, f32 * arg3, f32 * arg4);
f32 fn_802D1408(f32 * arg0, f32 * arg1);
void fn_802D14C0(void * arg0, f32 * arg1, f32 * arg2, void * arg3);
void fn_802D17F0(f32 * arg0, f32 * arg1, void * arg2);
void fn_802D1824(f32 * arg0, f32 * arg1, void * arg2);
void fn_802D1898(void * arg0, f32 farg0);
void fn_802D197C(void * arg0, f32 farg0);
void fn_802D1A60(void * arg0, f32 farg0, f32 farg1);
s8 fn_802D1C08(void * arg0);
void * fn_802D1C2C(void * arg0, void * arg1);
void fn_802D1D84(void * arg0);
void * fn_802D1FE8(void * arg0, void ** arg1, s8 arg2, u8 arg3, s8 arg4, void ** arg5, s32 arg_sp0);
void *** fn_802D3900(void *** arg0, void *** arg1);
void ** fn_802D3964(void ** arg0, void **** arg1, void ** arg2, void ** arg3);
void fn_802D3B68(void ** arg0, f32 (*arg1)[3][4]);
void *** fn_802D3C28(void *** arg0, void *** arg1);
void *** fn_802D3C8C(void *** arg0, void *** arg1);
u32 fn_802D3CF0(void **** arg0, s32 arg1);
void fn_802D3D14(void);
void **** fn_802D3D18(s32 arg0);
void * fn_802D3D6C(void * arg0);
void * fn_802D3DD4(void * arg0);
void * fn_802D3EC8(void * arg0);
void **** fn_802D3FAC(void **** arg0, s16 arg1);
void **** fn_802D4024(void **** arg0, s16 arg1);
void * fn_802D40AC(void * arg0, void * arg1);
void ** fn_802D4184(void ** arg0);
void **** fn_802D4200(void **** arg0, s16 arg1);
void * fn_802D4288(void * arg0, s32 arg1);
void fn_802D4338(void * arg0);
f32 * fn_802D4354(f32 * arg0, f32 farg0);
f32 * fn_802D43D8(f32 * arg0, f32 farg0);
void fn_802D445C(void * arg0, u8 arg1);
void fn_802D4678(void * arg0);
void fn_802D48BC(void * arg0, f64 farg0);
void fn_802D4AB0(void * arg0, u32 arg1);
void fn_802D4B3C(void * arg0, u32 arg1);
s32 fn_802D4B90(void);
s32 fn_802D4B98(void);
s32 fn_802D4BA0(void);
s32 fn_802D4BA8(void);
s32 fn_802D4BB0(void);
s32 fn_802D4BB8(void);
s32 fn_802D4BC0(void);
f32 fn_802D4BC8(void);
f32 fn_802D4BD0(void);
s32 fn_802D4BD8(void);
s32 fn_802D4BE0(void);
s32 fn_802D4BE8(void);
s32 fn_802D4BF0(void * arg0);
s32 fn_802D4C08(void);
s32 fn_802D4C10(void);
s32 fn_802D4C18(void);
s32 fn_802D4C20(void);
s32 fn_802D4C28(void);
f32 fn_802D4C30(f32 farg0);
f32 fn_802D4C3C(f32 farg0);
s32 fn_802D4C4C(void * arg0, f32 * arg1, f32 * arg2);
u8 fn_802D4D5C(void * arg0);
void ** fn_802D4D64(void ** arg0, u8 arg1, s8 arg2, s8 arg3, u8 arg4, void ** arg5, s8 arg6, void * arg7, f32 farg0, void * arg_sp8);
s32 fn_802D54EC(void * arg0);
void fn_802D5590(void * arg0);
s32 fn_802D55C0(void * arg0, s32 arg1, s32 * arg2, s32 arg3);
s32 fn_802D56BC(void * arg0);
s32 fn_802D5760(void * arg0, s32 arg1, s32 arg2);
s32 fn_802D5834(void * arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg_sp0);
s32 fn_802D5900(void * arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg_sp0);
s32 fn_802D59CC(void * arg0, s32 arg1, s32 arg2, s32 arg3);
s32 fn_802D5AA0(void * arg0, s32 arg1, s32 arg2, s32 arg3);
void fn_802D5B74(void * arg0);
void fn_802D5BE4(void * arg0, s32 arg1);
void fn_802D5C64(void * arg0, s32 arg1);
void fn_802D5CE4(void * arg0, s32 arg1, s32 arg2, s32 arg3);
s32 fn_802D5DA4(void * arg0, s32 arg1);
s32 fn_802D5E60(void * arg0);
void fn_802D5EC0(void * arg0, u8 arg1);
void fn_802D6C8C(f32 * arg0);
f32 fn_802D6D10(void * arg0);
u8 fn_802D6D48(void * arg0);
void fn_802D6D50(void * arg0, f32 * arg1);
void fn_802D7D44(void * arg0, f32 farg0);
void ** fn_802D7D4C(void ** arg0, s16 arg1);
void fn_802D7D94(void * arg0);
f32 fn_802D821C(f32 farg0);
f32 fn_802D8668(f32 farg0);
void fn_802D8AC4(void);
void fn_802D8AC8(void * arg0, s32 arg1);
void fn_802D8C84(void * arg0);
void fn_802D8CB4(void * arg0, s32 arg1);
void fn_802D928C(void * arg0, void * arg1, s8 arg2);
void fn_802D92B4(void * arg0);
void * fn_802D9308(void * arg0);
void fn_802D9394(void * arg0);
void **** fn_802D95A8(void **** arg0, s16 arg1);
void **** fn_802D962C(void **** arg0, s16 arg1);
s32 fn_802D96C0(void);
s32 fn_802D96C8(void);
s32 fn_802D96D0(void * arg0);
void fn_802D96E4(void * arg0);
void fn_802D9770(void * arg0);
void fn_802D97B8(void * arg0);
void fn_802D9800(f32 * arg0);
f32 fn_802D9870(void);
void fn_802D9878(f32 * arg0);
f32 fn_802D98E8(void);
u32 fn_802D98F0(void * arg0);
f32 fn_802D9A24(void);
f32 fn_802D9A2C(void);
f32 fn_802D9A34(void);
f32 fn_802D9A3C(void);
f32 fn_802D9A44(void);
void **** fn_802D9A4C(void **** arg0, s16 arg1);
s32 fn_802D9B2C(void);
s32 fn_802D9B34(void);
s32 fn_802D9B3C(void * arg0);
void **** fn_802D9B98(void **** arg0, s16 arg1);
s32 fn_802D9C2C(void);
void **** fn_802D9C34(void **** arg0, s16 arg1);
s32 fn_802D9CC8(void);
s32 fn_802D9CD0(void);
u8 fn_802D9CD8(void * arg0);
void fn_802D9CE0(f32 * arg0, void * arg1);
f32 fn_802D9CEC(void * arg0);
f32 fn_802D9CF4(void * arg0);
u8 fn_802D9CFC(void * arg0);
s32 fn_802D9D04(void * arg0);
s32 fn_802D9D14(void * arg0);
void fn_802D9D58(void * arg0, void * arg1);
void fn_802D9D74(void * arg0, void * arg1);
void fn_802D9D90(void * arg0, void * arg1);
u8 fn_802D9DAC(void * arg0);
f32 fn_802D9DB4(void * arg0);
s32 fn_802D9DBC(void * arg0);
s32 fn_802D9DC4(s32 arg0);
s32 fn_802D9DCC(void * arg0);
s32 fn_802D9DD4(void * arg0);
void fn_802D9DDC(void * arg0, void * arg1);
void fn_802D9DF8(void ** arg0, s32 arg1);
void fn_802D9E4C(void * arg0, f32 farg0);
void fn_802D9E54(void * arg0, f32 farg0);
s32 fn_802D9E5C(void * arg0);
void fn_802D9EC0(void * arg0);
s32 fn_802D9EF0(void * arg0);
void fn_802D9F2C(void * arg0);
void **** fn_802D9FF8(void **** arg0, s16 arg1);
void fn_802DA0F4(void * arg0);
void fn_802DA150(void * arg0);
void fn_802DA1C0(void * arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg_sp0);
void fn_802DA23C(void * arg0, void * arg1);
void fn_802DA258(void * arg0, f32 * arg1);
void fn_802DA2EC(void * arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg_sp0);
s8 fn_802DA368(void * arg0);
void fn_802DA380(s32 arg0);
void fn_802DA3A4(void * arg0, s32 arg1);
s32 fn_802DA3AC(void * arg0);
s32 fn_802DA3BC(void * arg0);
u8 fn_802DA3C4(void * arg0);
s32 fn_802DA3CC(void * arg0);
void fn_802DA3D4(void * arg0);
void **** fn_802DA444(void **** arg0, s16 arg1);
s32 fn_802DA550(void);
s32 fn_802DA558(void);
s32 fn_802DA560(void);
s32 fn_802DA568(void);
s32 fn_802DA570(void);
void fn_802DA578(void);
s32 fn_802DA57C(void);
s32 fn_802DA584(void);
s32 fn_802DA58C(void);
s32 fn_802DA594(void);
s32 fn_802DA59C(void);
s32 fn_802DA5A4(void);
s32 fn_802DA5AC(void);
s32 fn_802DA5B4(void);
s32 fn_802DA5BC(void);
void **** fn_802DA5C4(void **** arg0, s16 arg1);
s32 fn_802DA630(void);
f32 fn_802DA638(void * arg0, f32 * arg1, f32 farg0, f32 farg1);
f32 fn_802DA818(void * arg0, f32 * arg1, f32 farg0, f32 farg1);
f32 fn_802DA9F8(void * arg0, f32 * arg1, f32 farg0, f32 farg1);
f32 fn_802DABD8(f32 farg0);
void fn_802DABEC(f32 * arg0, f32 * arg1);
f32 fn_802DAC44(void * arg0, f32 * arg1, f32 farg0, f32 farg1);
f32 fn_802DAD90(void * arg0, f32 * arg1, f32 farg0, f32 farg1);
void fn_802DAED8(s32 ** arg0, void * arg1, s32 *** arg2, void ** arg3);
s32 * fn_802DAF8C(void * arg0);
void * fn_802DAFB4(void * arg0, void ** arg1, s32 arg2, s32 arg3, void * arg4);
void fn_802DB4EC(void * arg0);
void fn_802DB510(s32 * arg0, s32 arg1);
void fn_802DB518(void * arg0, s32 arg1);
void kar_diagnostic__802db74c(void ** arg0, s32 arg1);
u8 fn_802DC608(void ** arg0, void ** arg1);
u8 fn_802DC6D0(void ** arg0, void ** arg1);
void fn_802DC740(void * arg0);
f64 fn_802DC7DC(void ** arg1, void ** arg2);
void fn_802DCD00(void *** arg0, void *** arg1, u8 (*arg2)(void **, void **), s32 arg_sp0);
void kar_diag__802dd040(void ** arg0, void * arg1, u32 arg2, f32 * arg3, s32 arg_sp0);
void * fn_802DD7B4(void * arg0);
void ** fn_802DD880(void ** arg0);
void * fn_802DD94C(void * arg0);
void * fn_802DDA18(void * arg0);
void * fn_802DDAE4(void * arg0);
void * fn_802DDBB0(void * arg0);
void * fn_802DDBE8(void * arg0);
void * fn_802DDC94(void * arg0);
void * fn_802DDD40(void * arg0);
void * fn_802DDDEC(void * arg0);
void *fn_8038CB28(s32 size);
void fn_802DDF30(void *** arg0, void *** arg1, void *** arg2, u8 (*arg3)(void **, void **), s32 arg_sp0);
void fn_802DE038(void *** arg0, void *** arg1, u8 (*arg2)(void **, void **), s32 arg_sp0);
void * fn_802DE0E4(void);
void fn_802DE0F0(void * arg0, u32 arg1, s32 arg_sp0);
void fn_802DE418(void * arg0, u32 arg1, s32 arg_sp0);
void fn_802DE9A8(void * arg0);
void fn_802DF61C(void * arg0, void * arg1, u32 arg2, s32 arg_sp0);
void fn_802DF6F8(void * arg0, void * arg1, u32 arg2, s32 arg_sp0);
void ** fn_802DF844(void ** arg0);
void fn_802DF900(void * arg0, u8 arg1, s32 * arg2, u8 arg3, f32 farg0);
void fn_802E07A0(void * arg0, void ** arg1, void * arg2, s32 * arg3, s32 * arg4);
void fn_802E08F0(void * arg0, void * arg1, s32 arg2, s32 * arg3, s32 * arg4);
void fn_802E0AF8(f32 * arg0, void * arg1, f32 * arg3, f32 * arg4);
void fn_802E0FD4(void * arg0, void * arg1, f32 * arg2);
void fn_802E14F8(void * arg0, void * arg1, void * arg2, f32 * arg3);
void fn_802E1800(void * arg0, void * arg1, f32 * arg2);
void fn_802E1A4C(f32 * arg0, void * arg1, f32 * arg2, f32 * arg3, f32 farg0);
void fn_802E1D14(void * arg0);
void fn_802E2640(f32 * arg0, f32 * arg1, f32 farg0, f32 farg1, f32 farg2);
void fn_802E26DC(void * arg0);
void fn_802E28C4(void * arg0);
void fn_802E2F8C(void * arg0, u8 arg1, f32 farg0);
void fn_802E325C(void * arg0);
f32 fn_802E37F8(f32 farg0);
void fn_802E3C44(void * arg0);
void fn_802E3F00(void * arg0);
void fn_802E43DC(void * arg0);
void fn_802E4644(void * arg0);
void fn_802E48DC(void * arg0);
void fn_802E498C(void * arg0, f32 * arg1);
s32 fn_802E4A44(void);
void fn_802E4A4C(f32 * arg0, f32 farg0, f32 farg1, f32 farg2);
void fn_802E4E60(f32 * arg0, f32 * arg1, f32 farg0, f32 farg1);
void fn_802E5348(f32 * arg0, f32 * arg1, f32 farg0, f32 farg1);
void fn_802E5830(f32 * arg0, f32 * arg1, f32 farg0, f32 farg1);
void fn_802E5D18(f32 * arg0, f32 * arg1, f32 * arg2, f32 farg0);
void fn_802E5D74(f32 * arg0, f32 * arg1);
void fn_802E5DCC(f32 * arg0, f32 * arg1);
f32 fn_802E5E24(f32 * arg0, f32 * arg1, f32 farg0, f32 farg1);
void fn_802E6280(void);
void fn_802E62F8(void);
s32 fn_802E637C(char * arg0, s32 arg1);
void fn_802E6394(void * arg0);
s32 fn_802E6534(void * arg0, void ** arg1);
s32 fn_802E6630(void * arg0, void ** arg1);
s32 fn_802E6764(void * arg0, void ** arg1);
s32 fn_802E6898(void * arg0, void ** arg1);
f32 fn_802E6B2C(f32 farg0);
f32 fn_802E6F88(f32 farg0);
s32 fn_802E73D4(void * arg0, void ** arg1);
s32 fn_802E75B4(void * arg0, void ** arg1);
void fn_802E7798(void * arg0);
s32 fn_802E794C(void * arg0, void ** arg1);
s32 fn_802E79E0(void * arg0, void ** arg1);
void fn_802E7CB8(void * arg0);
s32 fn_802E7E6C(void * arg0, void ** arg1);
s32 fn_802E7F2C(void * arg0, void ** arg1);
u32 fn_802E7FE4(void * arg0, void ** arg1);
void fn_802E8134(void * arg0);
void **** fn_802E817C(void **** arg0, s16 arg1);
u32 fn_802E8228(void * arg0, void ** arg1);
void fn_802E8378(void * arg0);
void **** fn_802E83C0(void **** arg0, s16 arg1);
void fn_802E846C(s32 arg0);
void fn_802E8490(void * arg0);
void **** fn_802E84D8(void **** arg0, s16 arg1);
void fn_802E8584(s32 arg0);
void fn_802E85A8(void * arg0);
void **** fn_802E85F0(void **** arg0, s16 arg1);
u32 fn_802E869C(void * arg0, void ** arg1);
void fn_802E87EC(void * arg0);
void **** fn_802E8834(void **** arg0, s16 arg1);
void **** fn_802E88F8(void **** arg0, s16 arg1);
u32 fn_802E89A4(void * arg0, void ** arg1);
void fn_802E8AF4(void * arg0);
void **** fn_802E8B3C(void **** arg0, s16 arg1);
void fn_802E8BE8(s32 arg0);
void fn_802E8C0C(void * arg0);
void **** fn_802E8C54(void **** arg0, s16 arg1);
void fn_802E8D00(s32 arg0);
void fn_802E8D24(void * arg0);
void **** fn_802E8D6C(void **** arg0, s16 arg1);
s32 fn_802E8E18(void * arg0, void ** arg1);
void fn_802E9004(void * arg0);
void **** fn_802E904C(void **** arg0, s16 arg1);
void **** fn_802E90F8(void **** arg0, s16 arg1);
void fn_802E9170(s32 arg0);
void fn_802E9178(s32 arg0);
void fn_802E9180(s32 arg0);
void fn_802E9188(s32 arg0);
void fn_802E9190(s32 arg0);
void fn_802E9198(s32 arg0);
void fn_802E91A0(s32 arg0);
void fn_802E91A8(s32 arg0);
void fn_802E91B0(s32 arg0);
void fn_802E91B8(s32 arg0);
void * fn_802E91C0(void * arg0, void ** arg1);
void fn_802E9468(void * arg0);
void fn_802E9508(void * arg0, void * arg1, void * arg2);
void fn_802E99F8(f32 * arg0, f32 * arg1, void * arg2, f32 farg0);
void kar_diag__802e9aec(void * arg0, void * arg1, u8 * arg2);
void kar_diag__802e9e0c(void * arg0, void * arg1, u32 arg2, f32 * arg3, f32 arg_sp0);
void kar_diag__802ea3d4(void * arg0, u32 arg1);
void * fn_802EA580(void * arg0, s32 arg1);
void **** fn_802EA600(void **** arg0, s16 arg1);
f32 * fn_802EA65C(void);
void fn_802EA668(void * arg0);
s32 fn_802EB094(void * arg0, f32 * arg1);
u8 fn_802EBB98(void * arg0, f32 * arg1);
f32 fn_802EBFE8(f32 farg0);
f32 fn_802EC434(f32 farg0);
u8 fn_802EC890(void * arg0, f32 * arg1);
s32 fn_802ECB7C(void * arg0);
s32 fn_802ECC54(void * arg0, f32 * arg1);
u8 fn_802ED1D4(f32 * arg0, f32 * arg1, f32 * arg2, f32 farg0, f32 farg1);
s32 fn_802ED434(void * arg0, f32 * arg1);
}

extern "C" void TopRide_CheckSessionFinalizeObjectives(void * arg0, s32 arg_sp0) {
    (void) arg0;
    (void) arg_sp0;
}

extern "C" void TopRide_CheckPerCourseObjectives_B(void * arg0, s32 arg_sp0) {
    (void) arg0;
    (void) arg_sp0;
}

extern "C" void * kar_a2d_gamesession__near_802b87dc(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void TopRide_CheckPerCourseObjectives(void * arg0, s32 arg_sp0) {
    (void) arg0;
    (void) arg_sp0;
}

extern "C" void kar_a2d_gamesession__near_802ba0dc(void) {

}

extern "C" u32 kar_a2d_gamesession__near_802ba0e0(void) {
    void *obj = kar_a2d_gamesession__80289138();
    s32 v = FS32(obj, 0x20);
    if (v != 0) {
        return v;
    }
    return 0x7FFFFFFF;
}

extern "C" s32 fn_802BA114(u32 arg1) {
    (void) arg1;
    return 0;
}

extern "C" void * fn_802BA2D8(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void fn_802BA850(void ** arg0) {
    ((VDispatch *) arg0)->v12(0xA);
}

extern "C" void ** fn_802BA880(void ** arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802BA92C(void * arg0) {
    fn_802BA97C(arg0, lbl_805D8A20);
    *(void **) arg0 = (void *) lbl_804C0EC0;
    FP(arg0, 0x8) = (void *) (lbl_804C0EC0 + 0x10);
    FP(arg0, 0x38) = (void *) (lbl_804C0EC0 + 0x58);
    return arg0;
}

#pragma dont_inline on
extern "C" void * fn_802BA97C(void * arg0, void * arg1) {
    (void) arg1;
    kar_a2d_gamehistory__near_802b57f4(arg0);
    *(void **) arg0 = (void *) lbl_804F8404;
    FP(arg0, 0x8) = (void *) (lbl_804F8404 + 0x10);
    FP(arg0, 0x38) = (void *) (lbl_804F8404 + 0x58);
    return arg0;
}
#pragma dont_inline off

extern "C" void * fn_802BA9C8(void * arg0) {
    fn_802BA97C(arg0, lbl_805D8A28);
    *(void **) arg0 = (void *) lbl_804C1058;
    FP(arg0, 0x8) = (void *) (lbl_804C1058 + 0x10);
    FP(arg0, 0x38) = (void *) (lbl_804C1058 + 0x58);
    return arg0;
}

extern "C" void **** fn_802BAA18(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void **** fn_802BAAB4(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void **** fn_802BAB18(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void **** fn_802BAB78(void **** arg0) {
    kar_a2d_gamehistory__near_802b585c(arg0);
    *(void **) arg0 = (void *) lbl_804CB3F8;
    return arg0;
}

extern "C" u8 fn_802BABB4(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void fn_802BAD20(s32 arg0, void ** arg1, s32 arg2, s32 arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void * fn_802BB4DC(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802BC220(void * arg0, void *** arg1, u8 arg2, void * arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_802BC518(void * arg0, void *** arg1, s32 arg2, f32 farg0, f32 farg1) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) farg0;
    (void) farg1;
    return 0;
}

extern "C" void **** fn_802BC7E8(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void **** fn_802BC8B0(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802BC968(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void * fn_802BD504(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802BE1B8(void * arg0, void *** arg1, s32 arg2, f32 * arg3, f32 farg0, f32 farg1) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) farg0;
    (void) farg1;
    return 0;
}

extern "C" void fn_802BE48C(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void * fn_802BE970(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void **** fn_802BEEC8(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void **** fn_802BF05C(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802BF160(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void * fn_802BF1B8(void * arg0, f32 * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void **** fn_802BF298(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void **** fn_802BF360(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void ** fn_802BF41C(void ** arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802BF5C4(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802BFAE0(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802C0560(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802C08D8(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802C1100(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802C15E0(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802C21C8(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802C2AF8(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void fn_802C32F4(void * arg0) {
    (void) arg0;
}

extern "C" void * fn_802C3414(void * arg0, f32 * arg2) {
    (void) arg0;
    (void) arg2;
    return 0;
}

extern "C" void * fn_802C368C(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void fn_802C3A1C(void * arg0) {
    (void) arg0;
}

extern "C" void * fn_802C3ACC(void * arg0, s32 arg_sp0) {
    (void) arg0;
    (void) arg_sp0;
    return 0;
}

extern "C" void fn_802C40E4(void ** arg0) {
    FP(arg0, 0) = &lbl_804F52A8;
    FU32(arg0, 4) = 5;
}

extern "C" void fn_802C40FC(void ** arg0) {
    FP(arg0, 0) = &lbl_804F526C;
    FU32(arg0, 4) = 5;
}

extern "C" void fn_802C4114(void ** arg0) {
    FP(arg0, 0) = &lbl_804F5230;
    FU32(arg0, 4) = 5;
}

extern "C" void * fn_802C412C(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802C4378(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void fn_802C4620(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802C48D0(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802C4A2C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4A34(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4A3C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4A44(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4A4C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4A54(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4A5C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4A64(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4A6C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4A74(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4A7C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4A84(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4A8C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4A94(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4A9C(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4AA4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4AAC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4AB4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4ABC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4AC4(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4ACC(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802C4AD4(s32 arg0) {
    (void) arg0;
}

extern "C" void * fn_802C4ADC(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_802C50AC(void * arg0, s32 arg_sp0) {
    (void) arg0;
    (void) arg_sp0;
    return 0;
}

extern "C" void fn_802C5520(void * arg0) {
    (void) arg0;
}

extern "C" void * fn_802C5574(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_802C5F14(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802C601C(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802C6130(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802C6344(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802C63F8(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802C660C(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" u8 fn_802C681C(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" u8 fn_802C69E8(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void fn_802C6BE0(void * arg0) {
    HSD_JObjAnimAll(FP(arg0, 4));
}

extern "C" u8 fn_802C6C04(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void ** fn_802C6DF8(void ** arg0, void ** arg1, void ** arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    return 0;
}

extern "C" void fn_802C7B48(void ** arg0) {
    FU32(arg0, 0x0) = 0;
}

extern "C" void fn_802C7B54(void * arg0, u8 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802C80DC(char * arg0, s32 arg1, u32 arg2) {
    char *elem = arg0 + arg1 * 4;
    if (*(u32 *) (elem + 0x18) != arg2) {
        *(u32 *) (elem + 0x18) = arg2;
        *(u32 *) (elem + 0x48) = 0xA;
    }
}

extern "C" void fn_802C8100(s32 arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802C81CC(void * arg0, u8 arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void ** fn_802C8294(void ** arg0, void ** arg1, void ** arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    return 0;
}

extern "C" void fn_802C85E8(void) {

}

extern "C" void fn_802C85EC(void * arg0) {
    (void) arg0;
}

extern "C" f32 fn_802C89A0(f32 farg0) {
    (void) farg0;
    return 0.0f;
}

extern "C" f32 fn_802C8DFC(f32 farg0) {
    (void) farg0;
    return 0.0f;
}

extern "C" void ** fn_802C9248(void ** arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802C958C(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void ** fn_802C9978(void ** arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802C9F4C(void ** arg0, s32 arg_sp0) {
    (void) arg0;
    (void) arg_sp0;
}

extern "C" void fn_802CA134(void ** arg1, u32 arg2, u32 arg3, u8 arg4) {
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
}

extern "C" void ** fn_802CA598(void ** arg0, void ** arg1, s8 arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    return 0;
}

extern "C" void ** fn_802CA894(void ** arg0, void ** arg1, void ** arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void fn_802CB234(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802CBB40(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802CBC50(void * arg0) {
    (void) arg0;
}

extern "C" void **** fn_802CBF08(void **** arg0, s16 arg1) {
    void *e;
    void *e2;
    void *obj;
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804D0E3C;
    e = (char *) arg0 + 0x4C;
    if (e == 0) {
        goto skip1;
    }
    obj = FP(arg0, 0x4C);
    if (obj == 0) {
        goto skip1;
    }
    ((VDispatch *) obj)->v0(1);
skip1:
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804D0F20;
    e = (char *) arg0 + 0x10;
    if (e == 0) {
        goto skip2;
    }
    *(void **) ((char *) arg0 + 0x10) = (void *) &lbl_804BE104;
    if (FS32(arg0, 0x20) != -1) {
        kar_a2d_game_audio__near_803792b8(lbl_805DDC70);
    }
    e2 = (char *) arg0 + 0x10;
    if (e2 == 0) {
        goto skip2;
    }
    *(void **) ((char *) arg0 + 0x10) = (void *) &lbl_804BE0C4;
    ((VDispatch *) ((char *) arg0 + 0x10))->v5();
skip2:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void fn_802CBFEC(void * arg0) {
    if (FU8(arg0, 0xD) != 0) {
        ((VDispatch *) FP(arg0, 0x4C))->v2();
    }
}

extern "C" void **** fn_802CC028(void **** arg0, s16 arg1) {
    void *e;
    void *e2;
    void *obj;
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804D0E8C;
    e = (char *) arg0 + 0x4C;
    if (e == 0) {
        goto skip1;
    }
    obj = FP(arg0, 0x4C);
    if (obj == 0) {
        goto skip1;
    }
    ((VDispatch *) obj)->v0(1);
skip1:
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804D0F20;
    e = (char *) arg0 + 0x10;
    if (e == 0) {
        goto skip2;
    }
    *(void **) ((char *) arg0 + 0x10) = (void *) &lbl_804BE104;
    if (FS32(arg0, 0x20) != -1) {
        kar_a2d_game_audio__near_803792b8(lbl_805DDC70);
    }
    e2 = (char *) arg0 + 0x10;
    if (e2 == 0) {
        goto skip2;
    }
    *(void **) ((char *) arg0 + 0x10) = (void *) &lbl_804BE0C4;
    ((VDispatch *) ((char *) arg0 + 0x10))->v5();
skip2:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void fn_802CC10C(void * arg0) {
    if (FU8(arg0, 0xD) != 0) {
        ((VDispatch *) FP(arg0, 0x4C))->v2();
    }
}

extern "C" void ** fn_802CC148(void ** arg0) {
    (void) arg0;
    return 0;
}

extern "C" void fn_802CD8DC(void ** arg0) {
    f32 v = lbl_805E3690;
    FF32(arg0, 0x8) = v;
    FF32(arg0, 0x4) = v;
    FF32(arg0, 0x0) = v;
}

extern "C" u8 fn_802CD8F0(void ** arg0, f32 * arg1, f32 * arg2, u32 arg3, u32 arg4, f32 farg0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) farg0;
    return 0;
}

extern "C" u8 fn_802CDF04(f32 * arg1, u32 * arg2, f32 * arg3, f32 * arg4, f32 * arg5) {
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg5;
    return 0;
}

extern "C" void fn_802CE780(f32 * arg0, void ** arg1, f32 * arg2, f32 * arg3, f32 * arg4) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
}

extern "C" s8 fn_802CEA10(f32 * arg1, u32 arg2) {
    (void) arg1;
    (void) arg2;
    return 0;
}

extern "C" void fn_802CEC68(void ** arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802CF348(void ** arg0) {
    void *r1v = kar_diag__803ad760(lbl_805DDBC4, 0, lbl_805D8ED0, lbl_805D8EC0, 0);
    void *r2v = kar_diag__803ad760((s32) r1v, 0, lbl_805D8ED8, lbl_805D8ED0, 0);
    s32 i;
    for (i = 0; i < FS32(r2v, 0x24); i++) {
        fn_802CEC68(arg0, i);
    }
}

extern "C" void fn_802CF3D4(void ** arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802CF6DC(void ** arg0) {
    (void) arg0;
}

extern "C" void fn_802CF768(void ** arg0) {
    (void) arg0;
}

extern "C" void fn_802CF83C(void * arg0) {
    (void) arg0;
}

extern "C" f32 fn_802D06F0(f32 farg0) {
    (void) farg0;
    return 0.0f;
}

extern "C" f32 fn_802D0B4C(f32 farg0) {
    (void) farg0;
    return 0.0f;
}

extern "C" u8 fn_802D0F98(f32 * arg0, f32 * arg1, f32 * arg2, f32 * arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    return 0;
}

extern "C" void fn_802D10BC(f32 * arg0, f32 * arg1, f32 * arg2, f32 * arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void fn_802D1204(f32 * arg0, f32 * arg1, f32 * arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void fn_802D12D8(f32 * arg0, f32 * arg1, f32 * arg2, f32 * arg3, f32 * arg4) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
}

extern "C" f32 fn_802D1408(f32 * arg0, f32 * arg1) {
    (void) arg0;
    (void) arg1;
    return 0.0f;
}

extern "C" void fn_802D14C0(void * arg0, f32 * arg1, f32 * arg2, void * arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void fn_802D17F0(f32 * arg0, f32 * arg1, void * arg2) {
    *(Vec3f *) arg1 = *(Vec3f *) ((char *) arg0 + 4);
    *(Vec3f *) arg2 = *(Vec3f *) ((char *) arg0 + 16);
}

extern "C" void fn_802D1824(f32 * arg0, f32 * arg1, void * arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void fn_802D1898(void * arg0, f32 farg0) {
    Vec3f delta = *(Vec3f *) ((char *) arg0 + 0x10);
    PSVECSubtract(&delta, (char *) arg0 + 4, &delta);
    PSVECScale(&delta, &delta, farg0);
    Vec3f scaled = delta;
    Vec3f pos = *(Vec3f *) ((char *) arg0 + 4);
    PSVECAdd(&pos, &scaled, &pos);
    *(Vec3f *) ((char *) arg0 + 0x4C) = pos;
}

extern "C" void fn_802D197C(void * arg0, f32 farg0) {
    (void) arg0;
    (void) farg0;
}

extern "C" void fn_802D1A60(void * arg0, f32 farg0, f32 farg1) {
    (void) arg0;
    (void) farg0;
    (void) farg1;
}

extern "C" s8 fn_802D1C08(void * arg0) {
    return FF32(arg0, 0x64) != lbl_805DC8BC[0];
}

extern "C" void * fn_802D1C2C(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802D1D84(void * arg0) {
    (void) arg0;
}

extern "C" void * fn_802D1FE8(void * arg0, void ** arg1, s8 arg2, u8 arg3, s8 arg4, void ** arg5, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg5;
    (void) arg_sp0;
    return 0;
}

extern "C" void *** fn_802D3900(void *** arg0, void *** arg1) {
    void **n = *arg1;
    void **old = *arg0;
    if (old != n) {
        if (old != 0) {
            ((VDispatch *) old)->v0(1);
        }
        *arg0 = n;
    }
    return arg0;
}

extern "C" void ** fn_802D3964(void ** arg0, void **** arg1, void ** arg2, void ** arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    return 0;
}

extern "C" void fn_802D3B68(void ** arg0, f32 (*arg1)[3][4]) {
    (void) arg0;
    (void) arg1;
}

extern "C" void *** fn_802D3C28(void *** arg0, void *** arg1) {
    void **n = *arg1;
    void **old = *arg0;
    if (old != n) {
        if (old != 0) {
            ((VDispatch *) old)->v0(1);
        }
        *arg0 = n;
    }
    return arg0;
}

extern "C" void *** fn_802D3C8C(void *** arg0, void *** arg1) {
    void **n = *arg1;
    void **old = *arg0;
    if (old != n) {
        if (old != 0) {
            ((VDispatch *) old)->v0(1);
        }
        *arg0 = n;
    }
    return arg0;
}

extern "C" u32 fn_802D3CF0(void **** arg0, s32 arg1) {
    void *** table = *arg0;
    void ** v;
    if (table != 0) {
        v = (void **) table[arg1];
        if (v != 0) {
            return (u32) v;
        }
    }
    return 0;
}

extern "C" void fn_802D3D14(void) {

}

extern "C" void **** fn_802D3D18(s32 arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802D3D6C(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802D3DD4(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802D3EC8(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void **** fn_802D3FAC(void **** arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) lbl_804F3510;
    if (arg0 == 0) {
        goto skip1;
    }
    *(void **) arg0 = (void *) lbl_804BD724;
    ((VDispatch *) arg0)->v5();
skip1:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void **** fn_802D4024(void **** arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) lbl_804F32A8;
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) lbl_804F3510;
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) lbl_804BD724;
    ((VDispatch *) arg0)->v5();
skip2:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_802D40AC(void * arg0, void * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void ** fn_802D4184(void ** arg0) {
    (void) arg0;
    return 0;
}

extern "C" void **** fn_802D4200(void **** arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) lbl_804F54B8;
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) lbl_804BD6A0;
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) lbl_804BD658;
    ((VDispatch *) arg0)->v5();
skip2:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void * fn_802D4288(void * arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802D4338(void * arg0) {
    FU32(arg0, 0x18) = 0;
    FU32(arg0, 0x20) = 0;
    FF32(arg0, 0x24) = lbl_805E3728;
    FU8(arg0, 0x28) = 0;
}

extern "C" f32 * fn_802D4354(f32 * arg0, f32 farg0) {
    f32 a = fn_80296264(lbl_805E3728);
    a = fn_80296264(lbl_805E3728) * a;
    f32 b = fn_802D4C30(lbl_805E3734) * a;
    f32 c = lbl_805E3728 * b;
    *arg0 = farg0 * c;
    return arg0;
}

extern "C" f32 * fn_802D43D8(f32 * arg0, f32 farg0) {
    f32 a = fn_80296264(lbl_805E3728);
    a = fn_80296264(lbl_805E3728) * a;
    a = fn_80296264(lbl_805E3728) * a;
    f32 b = lbl_805E372C * a;
    *arg0 = farg0 * b;
    return arg0;
}

extern "C" void fn_802D445C(void * arg0, u8 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802D4678(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802D48BC(void * arg0, f64 farg0) {
    (void) arg0;
    (void) farg0;
}

extern "C" void fn_802D4AB0(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802D4B3C(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" s32 fn_802D4B90(void) {
    return 0;
}

extern "C" s32 fn_802D4B98(void) {
    return 0;
}

extern "C" s32 fn_802D4BA0(void) {
    return 0;
}

extern "C" s32 fn_802D4BA8(void) {
    return 0;
}

extern "C" s32 fn_802D4BB0(void) {
    return 0;
}

extern "C" s32 fn_802D4BB8(void) {
    return 0;
}

extern "C" s32 fn_802D4BC0(void) {
    return 0;
}

extern "C" f32 fn_802D4BC8(void) {
    return lbl_805E3730;
}

extern "C" f32 fn_802D4BD0(void) {
    return lbl_805E3728;
}

extern "C" s32 fn_802D4BD8(void) {
    return 0;
}

extern "C" s32 fn_802D4BE0(void) {
    return 0;
}

extern "C" s32 fn_802D4BE8(void) {
    return 1;
}

extern "C" s32 fn_802D4BF0(void * arg0) {
    s32 x = FS32(FP(arg0, 4), 0x84);
    return (u32) (-x | x) >> 31;
}

extern "C" s32 fn_802D4C08(void) {
    return 0;
}

extern "C" s32 fn_802D4C10(void) {
    return 1;
}

extern "C" s32 fn_802D4C18(void) {
    return 1;
}

extern "C" s32 fn_802D4C20(void) {
    return 0;
}

extern "C" s32 fn_802D4C28(void) {
    return 0;
}

#pragma dont_inline on
extern "C" f32 fn_802D4C30(f32 farg0) {
    return lbl_805E3728 / farg0;
}
#pragma dont_inline off

#pragma dont_inline on
extern "C" f32 fn_802D4C3C(f32 farg0) {
    f32 t = lbl_805E3728 / farg0;
    return t / farg0;
}
#pragma dont_inline off

extern "C" s32 fn_802D4C4C(void * arg0, f32 * arg1, f32 * arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    return 0;
}

extern "C" u8 fn_802D4D5C(void * arg0) {
    return FU8(arg0, 0xC);
}

extern "C" void ** fn_802D4D64(void ** arg0, u8 arg1, s8 arg2, s8 arg3, u8 arg4, void ** arg5, s8 arg6, void * arg7, f32 farg0, void * arg_sp8) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg5;
    (void) arg6;
    (void) arg7;
    (void) farg0;
    (void) arg_sp8;
    return 0;
}

extern "C" s32 fn_802D54EC(void * arg0) {
    void *d;
    if (((VDispatch *) arg0)->v45()) {
        goto fail;
    }
    d = FP(arg0, 0x7C);
    if (kar_diag__803ad760((s32) d, 0, lbl_805D90B0, lbl_805D9098, 0) != 0) {
        goto fail;
    }
    fn_802D8AC8(arg0, 1);
    ((VDispatch *) FP(arg0, 0x7C))->v0(-1);
    d = FP(arg0, 0x7C);
    if (d != NULL) {
        fn_802F4068(d, (char *) arg0 + 0x80);
    }
    return 1;
fail:
    return 0;
}

extern "C" void fn_802D5590(void * arg0) {
    ((VDispatch *) FP(arg0, 0x7C))->v15();
}

extern "C" s32 fn_802D55C0(void * arg0, s32 arg1, s32 * arg2, s32 arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    return 0;
}

extern "C" s32 fn_802D56BC(void * arg0) {
    void *d;
    if (((VDispatch *) arg0)->v45()) {
        goto fail;
    }
    d = FP(arg0, 0x7C);
    if (kar_diag__803ad760((s32) d, 0, lbl_805D90C8, lbl_805D9098, 0) != 0) {
        goto fail;
    }
    fn_802D8AC8(arg0, 1);
    ((VDispatch *) FP(arg0, 0x7C))->v0(-1);
    d = FP(arg0, 0x7C);
    if (d != NULL) {
        fn_802FA16C(d, (char *) arg0 + 0x80);
    }
    return 1;
fail:
    return 0;
}

extern "C" s32 fn_802D5760(void * arg0, s32 arg1, s32 arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    return 0;
}

extern "C" s32 fn_802D5834(void * arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg_sp0) {
    void *d;
    (void) arg_sp0;
    if (((VDispatch *) arg0)->v45()) {
        goto fail;
    }
    d = FP(arg0, 0x7C);
    if (kar_diag__803ad760((s32) d, 0, lbl_805D90D8, lbl_805D9098, 0) != 0) {
        goto fail;
    }
    fn_802D8AC8(arg0, 1);
    ((VDispatch *) FP(arg0, 0x7C))->v0(-1);
    d = FP(arg0, 0x7C);
    if (d != NULL) {
        fn_802F6138(d, (char *) arg0 + 0x80, arg1, arg2, arg3, arg4);
    }
    return 1;
fail:
    return 0;
}

extern "C" s32 fn_802D5900(void * arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg_sp0) {
    void *d;
    (void) arg_sp0;
    if (((VDispatch *) arg0)->v45()) {
        goto fail;
    }
    d = FP(arg0, 0x7C);
    if (kar_diag__803ad760((s32) d, 0, lbl_805D90E0, lbl_805D9098, 0) != 0) {
        goto fail;
    }
    fn_802D8AC8(arg0, 1);
    ((VDispatch *) FP(arg0, 0x7C))->v0(-1);
    d = FP(arg0, 0x7C);
    if (d != NULL) {
        fn_802F6C28(d, (char *) arg0 + 0x80, arg1, arg2, arg3, arg4);
    }
    return 1;
fail:
    return 0;
}

extern "C" s32 fn_802D59CC(void * arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *d;
    if (((VDispatch *) arg0)->v45()) {
        goto fail;
    }
    d = FP(arg0, 0x7C);
    if (kar_diag__803ad760((s32) d, 0, lbl_805D90E8, lbl_805D9098, 0) != 0) {
        goto fail;
    }
    fn_802D8AC8(arg0, 1);
    ((VDispatch *) FP(arg0, 0x7C))->v0(-1);
    d = FP(arg0, 0x7C);
    if (d != NULL) {
        fn_802F7718(d, (char *) arg0 + 0x80, arg1, arg2, arg3);
    }
    return 1;
fail:
    return 0;
}

extern "C" s32 fn_802D5AA0(void * arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *d;
    if (((VDispatch *) arg0)->v45()) {
        goto fail;
    }
    d = FP(arg0, 0x7C);
    if (kar_diag__803ad760((s32) d, 0, lbl_805D90E8, lbl_805D9098, 0) != 0) {
        goto fail;
    }
    fn_802D8AC8(arg0, 1);
    ((VDispatch *) FP(arg0, 0x7C))->v0(-1);
    d = FP(arg0, 0x7C);
    if (d != NULL) {
        fn_802F7B28(d, (char *) arg0 + 0x80, arg1, arg2, arg3);
    }
    return 1;
fail:
    return 0;
}

extern "C" void fn_802D5B74(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802D5BE4(void * arg0, s32 arg1) {
    void *d;
    if (((VDispatch *) FP(arg0, 0x7C))->v1() != 13) {
        ((VDispatch *) FP(arg0, 0x7C))->v0(-1);
        d = FP(arg0, 0x7C);
        if (d != NULL) {
            fn_802F858C(d, (char *) arg0 + 0x80, arg1);
        }
    }
}

extern "C" void fn_802D5C64(void * arg0, s32 arg1) {
    void *d;
    if (((VDispatch *) FP(arg0, 0x7C))->v1() != 13) {
        ((VDispatch *) FP(arg0, 0x7C))->v0(-1);
        d = FP(arg0, 0x7C);
        if (d != NULL) {
            fn_802FAA88(d, (char *) arg0 + 0x80, arg1);
        }
    }
}

extern "C" void fn_802D5CE4(void * arg0, s32 arg1, s32 arg2, s32 arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" s32 fn_802D5DA4(void * arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_802D5E60(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void fn_802D5EC0(void * arg0, u8 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802D6C8C(f32 * arg0) {
    (void) arg0;
}

extern "C" f32 fn_802D6D10(void * arg0) {
    f32 *fieldp = (f32 *) ((char *) arg0 + 0x2C);
    f32 *p;
    if (lbl_805D9050 < *fieldp) {
        p = fieldp;
    } else {
        p = &lbl_805D9050;
    }
    f32 v = *p;
    f32 *p2;
    if (lbl_805D9054 < v) {
        p2 = p;
    } else {
        p2 = &lbl_805D9054;
    }
    return *p2;
}

extern "C" u8 fn_802D6D48(void * arg0) {
    return FU8(arg0, 0x3F);
}

extern "C" void fn_802D6D50(void * arg0, f32 * arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802D7D44(void * arg0, f32 farg0) {
    FF32(arg0, 0x24) = farg0;
}

extern "C" void ** fn_802D7D4C(void ** arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = (void *) lbl_804D22E4;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_802D7D94(void * arg0) {
    (void) arg0;
}

extern "C" f32 fn_802D821C(f32 farg0) {
    (void) farg0;
    return 0.0f;
}

extern "C" f32 fn_802D8668(f32 farg0) {
    (void) farg0;
    return 0.0f;
}

extern "C" void fn_802D8AC4(void) {

}

extern "C" void fn_802D8AC8(void * arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802D8C84(void * arg0) {
    ((VDispatch *) FP(arg0, 0x7C))->v1();
}

extern "C" void fn_802D8CB4(void * arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802D928C(void * arg0, void * arg1, s8 arg2) {
    FU32(arg0, 0x18) = FU32(arg1, 0x0);
    FU32(arg0, 0x1C) = FU32(arg1, 0x4);
    FF32(arg0, 0x24) = lbl_805E3788;
    FS8(arg0, 0x28) = arg2;
    FU32(arg0, 0x20) = 0;
}

extern "C" void fn_802D92B4(void * arg0) {
    (void) arg0;
}

extern "C" void * fn_802D9308(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void fn_802D9394(void * arg0) {
    (void) arg0;
}

extern "C" void **** fn_802D95A8(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void **** fn_802D962C(void **** arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804D1EE4;
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804D6F5C;
    kar_a2d_kirbyjointanim__near_802effb8(FS32(FP(arg0, 4), 0x4AC), &lbl_804D1EB8, 0);
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804D1A98;
skip2:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" s32 fn_802D96C0(void) {
    return 0;
}

extern "C" s32 fn_802D96C8(void) {
    return 1;
}

extern "C" s32 fn_802D96D0(void * arg0) {
    return FU8(FP(arg0, 4), 0xBC8) == 0;
}

extern "C" void fn_802D96E4(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802D9770(void * arg0) {
    void *base = FP(arg0, 0x4);
    u32 v = FU32(base, 0x84);
    if (v == 0 || (v & 1) != 0) {
        ((VDispatch *) FP(base, 0x4A8))->v2();
    }
}

extern "C" void fn_802D97B8(void * arg0) {
    void *jobj = FP(FP(arg0, 0x4), 0x474);
    FU32(jobj, 0x14) &= ~0x10;
    HSD_JObjDisp(FP(FP(arg0, 0x4), 0x474), 0, 1, 0);
}

extern "C" void fn_802D9800(f32 * arg0) {
    f32 a = fn_80296264(lbl_805E3788);
    f32 b = fn_8029626C(lbl_805E3788) * a;
    f32 c = fn_802D4C3C(lbl_805E3788) * b;
    f32 d = lbl_805E3788 * c;
    *arg0 = lbl_805E3780 * d;
}

extern "C" f32 fn_802D9870(void) {
    return lbl_805E3788;
}

extern "C" void fn_802D9878(f32 * arg0) {
    f32 a = fn_80296264(lbl_805E3788);
    f32 b = fn_8029626C(lbl_805E3788) * a;
    f32 c = fn_802D4C3C(lbl_805E3788) * b;
    f32 d = lbl_805E3788 * c;
    *arg0 = lbl_805E3780 * d;
}

extern "C" f32 fn_802D98E8(void) {
    return lbl_805E3788;
}

extern "C" u32 fn_802D98F0(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" f32 fn_802D9A24(void) {
    return lbl_805E3788;
}

extern "C" f32 fn_802D9A2C(void) {
    return lbl_805E3788;
}

extern "C" f32 fn_802D9A34(void) {
    return lbl_805E3788;
}

extern "C" f32 fn_802D9A3C(void) {
    return lbl_805E3788;
}

extern "C" f32 fn_802D9A44(void) {
    return lbl_805E3780;
}

extern "C" void **** fn_802D9A4C(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_802D9B2C(void) {
    return 0;
}

extern "C" s32 fn_802D9B34(void) {
    return 1;
}

extern "C" s32 fn_802D9B3C(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void **** fn_802D9B98(void **** arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804D20F0;
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804D6F5C;
    kar_a2d_kirbyjointanim__near_802effb8(FS32(FP(arg0, 4), 0x4AC), &lbl_804D1EB8, 0);
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804D1A98;
skip2:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" s32 fn_802D9C2C(void) {
    return 0;
}

extern "C" void **** fn_802D9C34(void **** arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804D21F4;
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804D6F5C;
    kar_a2d_kirbyjointanim__near_802effb8(FS32(FP(arg0, 4), 0x4AC), &lbl_804D1EB8, 0);
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804D1A98;
skip2:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" s32 fn_802D9CC8(void) {
    return 0;
}

extern "C" s32 fn_802D9CD0(void) {
    return 1;
}

extern "C" u8 fn_802D9CD8(void * arg0) {
    return FU8(arg0, 0xD);
}

extern "C" void fn_802D9CE0(f32 * arg0, void * arg1) {
    FF32(arg0, 0x0) = FF32(arg1, 0x38);
}

extern "C" f32 fn_802D9CEC(void * arg0) {
    return FF32(arg0, 0x2C);
}

extern "C" f32 fn_802D9CF4(void * arg0) {
    return FF32(arg0, 0x30);
}

extern "C" u8 fn_802D9CFC(void * arg0) {
    return FU8(arg0, 0xAC);
}

extern "C" s32 fn_802D9D04(void * arg0) {
    return FU32(arg0, 0xDC) == 0;
}

extern "C" s32 fn_802D9D14(void * arg0) {
    s32 result = 0;
    if (FU8(arg0, 0xAC) == 0) {
        u32 word2;
        u32 word;
        f32 tmp = lbl_805E3780;
        word = *(u32 *) &tmp;
        word2 = word;
        if (FF32(arg0, 0xB4) > *(f32 *) &word2) {
            result = 1;
        }
    }
    return result;
}

extern "C" void fn_802D9D58(void * arg0, void * arg1) {
    FF32(arg0, 0x88) = FF32(arg1, 0);
    FF32(arg0, 0x8C) = FF32(arg1, 4);
    FF32(arg0, 0x90) = FF32(arg1, 8);
}

extern "C" void fn_802D9D74(void * arg0, void * arg1) {
    FF32(arg0, 0x94) = FF32(arg1, 0);
    FF32(arg0, 0x98) = FF32(arg1, 4);
    FF32(arg0, 0x9C) = FF32(arg1, 8);
}

extern "C" void fn_802D9D90(void * arg0, void * arg1) {
    FF32(arg0, 0xA0) = FF32(arg1, 0);
    FF32(arg0, 0xA4) = FF32(arg1, 4);
    FF32(arg0, 0xA8) = FF32(arg1, 8);
}

extern "C" u8 fn_802D9DAC(void * arg0) {
    return FU8(arg0, 0x130);
}

extern "C" f32 fn_802D9DB4(void * arg0) {
    return FF32(arg0, 0x138);
}

extern "C" s32 fn_802D9DBC(void * arg0) {
    return FU32(arg0, 0x134);
}

extern "C" s32 fn_802D9DC4(s32 arg0) {
    return arg0 + 0x13C;
}

extern "C" s32 fn_802D9DCC(void * arg0) {
    return FU32(arg0, 0x528);
}

extern "C" s32 fn_802D9DD4(void * arg0) {
    return FU32(arg0, 0x4E0);
}

extern "C" void fn_802D9DDC(void * arg0, void * arg1) {
    FF32(arg0, 0x4D0) = FF32(arg1, 0);
    FF32(arg0, 0x4D4) = FF32(arg1, 4);
    FF32(arg0, 0x4D8) = FF32(arg1, 8);
}

extern "C" void fn_802D9DF8(void ** arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802D9E4C(void * arg0, f32 farg0) {
    FF32(arg0, 0xC4) = farg0;
}

extern "C" void fn_802D9E54(void * arg0, f32 farg0) {
    FF32(arg0, 0xC8) = farg0;
}

extern "C" s32 fn_802D9E5C(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void fn_802D9EC0(void * arg0) {
    ((VDispatch *) FP(arg0, 0x7C))->v17();
}

extern "C" s32 fn_802D9EF0(void * arg0) {
    u8 v = ((VDispatch *) FP(arg0, 0x7C))->v13();
    return v == 0;
}

extern "C" void fn_802D9F2C(void * arg0) {
    (void) arg0;
}

extern "C" void **** fn_802D9FF8(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802DA0F4(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802DA150(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802DA1C0(void * arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg_sp0) {
    void *d;
    (void) arg_sp0;
    ((VDispatch *) FP(arg0, 0x7C))->v0(-1);
    d = FP(arg0, 0x7C);
    if (d != NULL) {
        fn_802FB060(d, (char *) arg0 + 0x80, arg1, arg2, arg3, arg4);
    }
}

extern "C" void fn_802DA23C(void * arg0, void * arg1) {
    FF32(arg0, 0x148) = FF32(arg1, 0);
    FF32(arg0, 0x14C) = FF32(arg1, 4);
    FF32(arg0, 0x150) = FF32(arg1, 8);
}

extern "C" void fn_802DA258(void * arg0, f32 * arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802DA2EC(void * arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg_sp0) {
    void *d;
    (void) arg_sp0;
    ((VDispatch *) FP(arg0, 0x7C))->v0(-1);
    d = FP(arg0, 0x7C);
    if (d != NULL) {
        fn_802F8A5C(d, (char *) arg0 + 0x80, arg1, arg2, arg3, arg4);
    }
}

extern "C" s8 fn_802DA368(void * arg0) {
    u8 old = FU8(arg0, 0x11);
    FS8(arg0, 0x11) = -1;
    return (s8) old;
}

extern "C" void fn_802DA380(s32 arg0) {
    fn_803120C0((void *) (arg0 + 0x64));
}

extern "C" void fn_802DA3A4(void * arg0, s32 arg1) {
    FU32(arg0, 0x108) = arg1;
}

extern "C" s32 fn_802DA3AC(void * arg0) {
    return FU32(arg0, 0x100) == 0;
}

extern "C" s32 fn_802DA3BC(void * arg0) {
    return FU32(arg0, 0x114);
}

extern "C" u8 fn_802DA3C4(void * arg0) {
    return FU8(arg0, 0x40);
}

extern "C" s32 fn_802DA3CC(void * arg0) {
    return FU32(arg0, 0x15C);
}

extern "C" void fn_802DA3D4(void * arg0) {
    f32 a = fn_80296264(lbl_805E3788);
    f32 b = fn_80296264(lbl_805E3788) * a;
    f32 c = fn_802D4C30(lbl_805E37A0) * b;
    f32 d = lbl_805E3788 * c;
    FF32(arg0, 0xC0) = lbl_805E3780 * d;
}

extern "C" void **** fn_802DA444(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_802DA550(void) {
    return 13;
}

extern "C" s32 fn_802DA558(void) {
    return 1;
}

extern "C" s32 fn_802DA560(void) {
    return 1;
}

extern "C" s32 fn_802DA568(void) {
    return 1;
}

extern "C" s32 fn_802DA570(void) {
    return 1;
}

extern "C" void fn_802DA578(void) {

}

extern "C" s32 fn_802DA57C(void) {
    return 1;
}

extern "C" s32 fn_802DA584(void) {
    return 1;
}

extern "C" s32 fn_802DA58C(void) {
    return 1;
}

extern "C" s32 fn_802DA594(void) {
    return 1;
}

extern "C" s32 fn_802DA59C(void) {
    return 1;
}

extern "C" s32 fn_802DA5A4(void) {
    return 0;
}

extern "C" s32 fn_802DA5AC(void) {
    return 1;
}

extern "C" s32 fn_802DA5B4(void) {
    return 1;
}

extern "C" s32 fn_802DA5BC(void) {
    return 1;
}

extern "C" void **** fn_802DA5C4(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_802DA630(void) {
    return 1;
}

extern "C" f32 fn_802DA638(void * arg0, f32 * arg1, f32 farg0, f32 farg1) {
    f32 a, b, c, d, ab, cd;

    {
        struct { void *ptr; s32 tag; } q;
        f32 t = fn_80296264(lbl_805E3788);
        f32 u;
        t = fn_80296264(lbl_805E3788) * t;
        u = fn_8029626C(lbl_805E37A0) * t;
        q.ptr = arg0;
        q.tag = 5;
        a = kar_diagnostic__802a07d8(&q, *arg1 / (lbl_805E3788 * u));
    }
    {
        struct { void *ptr; s32 tag; } q;
        f32 t = fn_80296264(lbl_805E3788);
        f32 u;
        t = fn_80296264(lbl_805E3788) * t;
        u = fn_8029626C(lbl_805E37A0) * t;
        q.ptr = (char *) arg0 + 60;
        q.tag = 5;
        b = kar_diagnostic__802a07d8(&q, *arg1 / (lbl_805E3788 * u));
    }
    ab = kar_a2d_game_lib__near_802889d0(&a, &b, farg1);

    {
        struct { void *ptr; s32 tag; } q;
        f32 t = fn_80296264(lbl_805E3788);
        f32 u;
        t = fn_80296264(lbl_805E3788) * t;
        u = fn_8029626C(lbl_805E37A0) * t;
        q.ptr = (char *) arg0 + 120;
        q.tag = 5;
        c = kar_diagnostic__802a07d8(&q, *arg1 / (lbl_805E3788 * u));
    }
    {
        struct { void *ptr; s32 tag; } q;
        f32 t = fn_80296264(lbl_805E3788);
        f32 u;
        t = fn_80296264(lbl_805E3788) * t;
        u = fn_8029626C(lbl_805E37A0) * t;
        q.ptr = (char *) arg0 + 180;
        q.tag = 5;
        d = kar_diagnostic__802a07d8(&q, *arg1 / (lbl_805E3788 * u));
    }
    cd = kar_a2d_game_lib__near_802889d0(&c, &d, farg1);

    return kar_a2d_game_lib__near_802889d0(&ab, &cd, farg0);
}

extern "C" f32 fn_802DA818(void * arg0, f32 * arg1, f32 farg0, f32 farg1) {
    f32 a, b, c, d, ab, cd;

    {
        struct { void *ptr; s32 tag; } q;
        f32 t = fn_80296264(lbl_805E3788);
        f32 u;
        t = fn_80296264(lbl_805E3790) * t;
        u = fn_8029626C(lbl_805E378C) * t;
        q.ptr = arg0;
        q.tag = 5;
        a = kar_diagnostic__802a07d8(&q, *arg1 / (lbl_805E3788 * u));
    }
    {
        struct { void *ptr; s32 tag; } q;
        f32 t = fn_80296264(lbl_805E3788);
        f32 u;
        t = fn_80296264(lbl_805E3790) * t;
        u = fn_8029626C(lbl_805E378C) * t;
        q.ptr = (char *) arg0 + 60;
        q.tag = 5;
        b = kar_diagnostic__802a07d8(&q, *arg1 / (lbl_805E3788 * u));
    }
    ab = kar_a2d_game_lib__near_802889d0(&a, &b, farg1);

    {
        struct { void *ptr; s32 tag; } q;
        f32 t = fn_80296264(lbl_805E3788);
        f32 u;
        t = fn_80296264(lbl_805E3790) * t;
        u = fn_8029626C(lbl_805E378C) * t;
        q.ptr = (char *) arg0 + 120;
        q.tag = 5;
        c = kar_diagnostic__802a07d8(&q, *arg1 / (lbl_805E3788 * u));
    }
    {
        struct { void *ptr; s32 tag; } q;
        f32 t = fn_80296264(lbl_805E3788);
        f32 u;
        t = fn_80296264(lbl_805E3790) * t;
        u = fn_8029626C(lbl_805E378C) * t;
        q.ptr = (char *) arg0 + 180;
        q.tag = 5;
        d = kar_diagnostic__802a07d8(&q, *arg1 / (lbl_805E3788 * u));
    }
    cd = kar_a2d_game_lib__near_802889d0(&c, &d, farg1);

    return kar_a2d_game_lib__near_802889d0(&ab, &cd, farg0);
}

extern "C" f32 fn_802DA9F8(void * arg0, f32 * arg1, f32 farg0, f32 farg1) {
    f32 a, b, c, d, ab, cd;

    {
        struct { void *ptr; s32 tag; } q;
        f32 t = fn_80296264(lbl_805E3788);
        f32 u;
        t = fn_80296264(lbl_805E3788) * t;
        u = fn_8029626C(lbl_805E3788) * t;
        q.ptr = arg0;
        q.tag = 5;
        a = kar_diagnostic__802a07d8(&q, *arg1 / (lbl_805E3798 * u));
    }
    {
        struct { void *ptr; s32 tag; } q;
        f32 t = fn_80296264(lbl_805E3788);
        f32 u;
        t = fn_80296264(lbl_805E3788) * t;
        u = fn_8029626C(lbl_805E3788) * t;
        q.ptr = (char *) arg0 + 60;
        q.tag = 5;
        b = kar_diagnostic__802a07d8(&q, *arg1 / (lbl_805E3798 * u));
    }
    ab = kar_a2d_game_lib__near_802889d0(&a, &b, farg1);

    {
        struct { void *ptr; s32 tag; } q;
        f32 t = fn_80296264(lbl_805E3788);
        f32 u;
        t = fn_80296264(lbl_805E3788) * t;
        u = fn_8029626C(lbl_805E3788) * t;
        q.ptr = (char *) arg0 + 120;
        q.tag = 5;
        c = kar_diagnostic__802a07d8(&q, *arg1 / (lbl_805E3798 * u));
    }
    {
        struct { void *ptr; s32 tag; } q;
        f32 t = fn_80296264(lbl_805E3788);
        f32 u;
        t = fn_80296264(lbl_805E3788) * t;
        u = fn_8029626C(lbl_805E3788) * t;
        q.ptr = (char *) arg0 + 180;
        q.tag = 5;
        d = kar_diagnostic__802a07d8(&q, *arg1 / (lbl_805E3798 * u));
    }
    cd = kar_a2d_game_lib__near_802889d0(&c, &d, farg1);

    return kar_a2d_game_lib__near_802889d0(&ab, &cd, farg0);
}

extern "C" f32 fn_802DABD8(f32 farg0) {
    f32 t = farg0 * lbl_805E3788;
    t = farg0 * t;
    return farg0 * t;
}

extern "C" void fn_802DABEC(f32 * arg0, f32 * arg1) {
    u32 tmp;
    f32 threshold = lbl_805E3780 * lbl_805E3834;
    f32 threshold2;
    tmp = *(u32 *) &threshold;
    threshold2 = *(f32 *) &tmp;
    f32 v = *arg1;
    u32 ge;
    ge = v >= threshold2;
    f32 neg;
    f32 *p;
    if (ge == 0) {
        neg = -v;
        p = &neg;
    } else {
        p = arg1;
    }
    *arg0 = *p;
}

extern "C" f32 fn_802DAC44(void * arg0, f32 * arg1, f32 farg0, f32 farg1) {
    (void) arg0;
    (void) arg1;
    (void) farg0;
    (void) farg1;
    return 0.0f;
}

extern "C" f32 fn_802DAD90(void * arg0, f32 * arg1, f32 farg0, f32 farg1) {
    (void) arg0;
    (void) arg1;
    (void) farg0;
    (void) farg1;
    return 0.0f;
}

extern "C" void fn_802DAED8(s32 ** arg0, void * arg1, s32 *** arg2, void ** arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" s32 * fn_802DAF8C(void * arg0) {
    u32 idx = FU32(arg0, 0x810);
    void *elem = (char *) arg0 + idx * 0x204;
    FU32(arg0, 0x810) = FU32(elem, 0x0);
    FU32(arg0, 0x814) -= 1;
    return (s32 *) elem;
}

extern "C" void * fn_802DAFB4(void * arg0, void ** arg1, s32 arg2, s32 arg3, void * arg4) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    return 0;
}

extern "C" void fn_802DB4EC(void * arg0) {
    fn_802DB510((s32 *) arg0, 0);
}

extern "C" void fn_802DB510(s32 * arg0, s32 arg1) {
    FU32(arg0, 0x0) = arg1;
}

extern "C" void fn_802DB518(void * arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void kar_diagnostic__802db74c(void ** arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" u8 fn_802DC608(void ** arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" u8 fn_802DC6D0(void ** arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802DC740(void * arg0) {
    (void) arg0;
}

extern "C" f64 fn_802DC7DC(void ** arg1, void ** arg2) {
    (void) arg1;
    (void) arg2;
    return 0.0;
}

extern "C" void fn_802DCD00(void *** arg0, void *** arg1, u8 (*arg2)(void **, void **), s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
}

extern "C" void kar_diag__802dd040(void ** arg0, void * arg1, u32 arg2, f32 * arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
}

extern "C" void * fn_802DD7B4(void * arg0) {
    void * volatile old = 0;
    void *n;
    FP(arg0, 0) = 0;
    FP(arg0, 4) = 0;
    n = fn_8038CB28(0x2C08);
    if (n != 0) {
        n = fn_802DDDEC(n);
    }
    {
        void * volatile tmp = n;
        tmp = 0;
        void * volatile dead = n;
        void * volatile commit = n;
        (void) dead;
        if (old != n) {
            if (old != 0) {
                lbl_805DD98C = 0;
                fn_8038CB78(old);
            }
            old = commit;
        }
        if (tmp != 0) {
            lbl_805DD98C = 0;
            fn_8038CB78(tmp);
        }
        FP(arg0, 8) = old;
        old = 0;
    }
    {
        void *node = (char *) arg0 + 0xC;
        FP(node, 4) = node;
        FP(arg0, 0xC) = node;
    }
    return arg0;
}

extern "C" void ** fn_802DD880(void ** arg0) {
    void * volatile old = 0;
    void *n;
    FP(arg0, 0) = 0;
    FP(arg0, 4) = 0;
    n = fn_8038CB28(0x4608);
    if (n != 0) {
        n = fn_802DDD40(n);
    }
    {
        void * volatile tmp = n;
        tmp = 0;
        void * volatile dead = n;
        void * volatile commit = n;
        (void) dead;
        if (old != n) {
            if (old != 0) {
                lbl_805DD984 = 0;
                fn_8038CB78(old);
            }
            old = commit;
        }
        if (tmp != 0) {
            lbl_805DD984 = 0;
            fn_8038CB78(tmp);
        }
        FP(arg0, 8) = old;
        old = 0;
    }
    {
        void *node = (char *) arg0 + 0xC;
        FP(node, 4) = node;
        FP(arg0, 0xC) = node;
    }
    return (void **) arg0;
}

extern "C" void * fn_802DD94C(void * arg0) {
    void * volatile old = 0;
    void *n;
    FP(arg0, 0) = 0;
    FP(arg0, 4) = 0;
    n = fn_8038CB28(0x4008);
    if (n != 0) {
        n = fn_802DDC94(n);
    }
    {
        void * volatile tmp = n;
        tmp = 0;
        void * volatile dead = n;
        void * volatile commit = n;
        (void) dead;
        if (old != n) {
            if (old != 0) {
                lbl_805DD97C = 0;
                fn_8038CB78(old);
            }
            old = commit;
        }
        if (tmp != 0) {
            lbl_805DD97C = 0;
            fn_8038CB78(tmp);
        }
        FP(arg0, 8) = old;
        old = 0;
    }
    {
        void *node = (char *) arg0 + 0xC;
        FP(node, 4) = node;
        FP(arg0, 0xC) = node;
    }
    return arg0;
}

extern "C" void * fn_802DDA18(void * arg0) {
    void * volatile old = 0;
    void *n;
    FP(arg0, 0) = 0;
    FP(arg0, 4) = 0;
    n = fn_8038CB28(0x7C08);
    if (n != 0) {
        n = fn_802DDBE8(n);
    }
    {
        void * volatile tmp = n;
        tmp = 0;
        void * volatile dead = n;
        void * volatile commit = n;
        (void) dead;
        if (old != n) {
            if (old != 0) {
                lbl_805DD974 = 0;
                fn_8038CB78(old);
            }
            old = commit;
        }
        if (tmp != 0) {
            lbl_805DD974 = 0;
            fn_8038CB78(tmp);
        }
        FP(arg0, 8) = old;
        old = 0;
    }
    {
        void *node = (char *) arg0 + 0xC;
        FP(node, 4) = node;
        FP(arg0, 0xC) = node;
    }
    return arg0;
}

extern "C" void * fn_802DDAE4(void * arg0) {
    void * volatile old = 0;
    void *n;
    FP(arg0, 0) = 0;
    FP(arg0, 4) = 0;
    n = fn_8038CB28(0x818);
    if (n != 0) {
        n = fn_802DDBB0(n);
    }
    {
        void * volatile tmp = n;
        tmp = 0;
        void * volatile dead = n;
        void * volatile commit = n;
        (void) dead;
        if (old != n) {
            if (old != 0) {
                lbl_805DD96C = 0;
                fn_8038CB78(old);
            }
            old = commit;
        }
        if (tmp != 0) {
            lbl_805DD96C = 0;
            fn_8038CB78(tmp);
        }
        FP(arg0, 8) = old;
        old = 0;
    }
    {
        void *node = (char *) arg0 + 0xC;
        FP(node, 4) = node;
        FP(arg0, 0xC) = node;
    }
    return arg0;
}

extern "C" void * fn_802DDBB0(void * arg0) {
    FU32(arg0, 0x0) = 1;
    FU32(arg0, 0x204) = 2;
    FU32(arg0, 0x408) = 3;
    FU32(arg0, 0x60C) = 0xFFFFFFFF;
    lbl_805DD96C = arg0;
    FU32(arg0, 0x810) = 0;
    FU32(arg0, 0x814) = 4;
    return arg0;
}

extern "C" void * fn_802DDBE8(void * arg0) {
    (void) arg0;
    return arg0;
}

extern "C" void * fn_802DDC94(void * arg0) {
    (void) arg0;
    return arg0;
}

extern "C" void * fn_802DDD40(void * arg0) {
    (void) arg0;
    return arg0;
}

extern "C" void * fn_802DDDEC(void * arg0) {
    (void) arg0;
    return arg0;
}

extern "C" void fn_802DDF30(void *** arg0, void *** arg1, void *** arg2, u8 (*arg3)(void **, void **), s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
}

extern "C" void fn_802DE038(void *** arg0, void *** arg1, u8 (*arg2)(void **, void **), s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
}

extern "C" void * fn_802DE0E4(void) {
    return &lbl_804D40F0;
}

extern "C" void fn_802DE0F0(void * arg0, u32 arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802DE418(void * arg0, u32 arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void fn_802DE9A8(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802DF61C(void * arg0, void * arg1, u32 arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
}

extern "C" void fn_802DF6F8(void * arg0, void * arg1, u32 arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
}

extern "C" void ** fn_802DF844(void ** arg0) {
    (void) arg0;
    return 0;
}

extern "C" void fn_802DF900(void * arg0, u8 arg1, s32 * arg2, u8 arg3, f32 farg0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) farg0;
}

extern "C" void fn_802E07A0(void * arg0, void ** arg1, void * arg2, s32 * arg3, s32 * arg4) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
}

extern "C" void fn_802E08F0(void * arg0, void * arg1, s32 arg2, s32 * arg3, s32 * arg4) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
}

extern "C" void fn_802E0AF8(f32 * arg0, void * arg1, f32 * arg3, f32 * arg4) {
    (void) arg0;
    (void) arg1;
    (void) arg3;
    (void) arg4;
}

extern "C" void fn_802E0FD4(void * arg0, void * arg1, f32 * arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void fn_802E14F8(void * arg0, void * arg1, void * arg2, f32 * arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void fn_802E1800(void * arg0, void * arg1, f32 * arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void fn_802E1A4C(f32 * arg0, void * arg1, f32 * arg2, f32 * arg3, f32 farg0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) farg0;
}

extern "C" void fn_802E1D14(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802E2640(f32 * arg0, f32 * arg1, f32 farg0, f32 farg1, f32 farg2) {
    (void) arg0;
    (void) arg1;
    (void) farg0;
    (void) farg1;
    (void) farg2;
}

extern "C" void fn_802E26DC(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802E28C4(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802E2F8C(void * arg0, u8 arg1, f32 farg0) {
    (void) arg0;
    (void) arg1;
    (void) farg0;
}

extern "C" void fn_802E325C(void * arg0) {
    (void) arg0;
}

extern "C" f32 fn_802E37F8(f32 farg0) {
    (void) farg0;
    return 0.0f;
}

extern "C" void fn_802E3C44(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802E3F00(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802E43DC(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802E4644(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802E48DC(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802E498C(void * arg0, f32 * arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" s32 fn_802E4A44(void) {
    return 0;
}

extern "C" void fn_802E4A4C(f32 * arg0, f32 farg0, f32 farg1, f32 farg2) {
    (void) arg0;
    (void) farg0;
    (void) farg1;
    (void) farg2;
}

extern "C" void fn_802E4E60(f32 * arg0, f32 * arg1, f32 farg0, f32 farg1) {
    (void) arg0;
    (void) arg1;
    (void) farg0;
    (void) farg1;
}

extern "C" void fn_802E5348(f32 * arg0, f32 * arg1, f32 farg0, f32 farg1) {
    (void) arg0;
    (void) arg1;
    (void) farg0;
    (void) farg1;
}

extern "C" void fn_802E5830(f32 * arg0, f32 * arg1, f32 farg0, f32 farg1) {
    (void) arg0;
    (void) arg1;
    (void) farg0;
    (void) farg1;
}

extern "C" void fn_802E5D18(f32 * arg0, f32 * arg1, f32 * arg2, f32 farg0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) farg0;
}

extern "C" void fn_802E5D74(f32 * arg0, f32 * arg1) {
    u32 tmp;
    f32 threshold = lbl_805E3870 * lbl_805E3880;
    f32 threshold2;
    tmp = *(u32 *) &threshold;
    threshold2 = *(f32 *) &tmp;
    f32 v = *arg1;
    u32 ge;
    ge = v >= threshold2;
    f32 neg;
    f32 *p;
    if (ge == 0) {
        neg = -v;
        p = &neg;
    } else {
        p = arg1;
    }
    *arg0 = *p;
}

extern "C" void fn_802E5DCC(f32 * arg0, f32 * arg1) {
    u32 tmp;
    f32 threshold = lbl_805E3870 * lbl_805E3940;
    f32 threshold2;
    tmp = *(u32 *) &threshold;
    threshold2 = *(f32 *) &tmp;
    f32 v = *arg1;
    u32 ge;
    ge = v >= threshold2;
    f32 neg;
    f32 *p;
    if (ge == 0) {
        neg = -v;
        p = &neg;
    } else {
        p = arg1;
    }
    *arg0 = *p;
}

extern "C" f32 fn_802E5E24(f32 * arg0, f32 * arg1, f32 farg0, f32 farg1) {
    (void) arg0;
    (void) arg1;
    (void) farg0;
    (void) farg1;
    return 0.0f;
}

extern "C" void fn_802E6280(void) {

}

extern "C" void fn_802E62F8(void) {

}

extern "C" s32 fn_802E637C(char * arg0, s32 arg1) {
    char *elem = arg0 + arg1 * 4;
    s32 result = *(u32 *) (elem + 0x10);
    *(u32 *) (elem + 0x10) = 0;
    return result;
}

extern "C" void fn_802E6394(void * arg0) {
    (void) arg0;
}

extern "C" s32 fn_802E6534(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_802E6630(void * arg0, void ** arg1) {
    VDispatch *o = (VDispatch *) arg1;
    Vec3f *b;
    Vec3f *p2;
    Vec3f norm;
    Vec3f pos;
    if (o->v45()) {
        return 0;
    }
    if (FU16(arg0, 0x48) == o->v10()) {
        return 0;
    }
    if (o->v8() == 8) {
        return 0;
    }
    b = ((VGeom2 *) ((char *) arg0 + 0x24))->v0();
    p2 = ((VGeom2 *) ((char *) arg0 + 0x24))->v1();
    pos = *p2;
    PSVECSubtract(&pos, b, &pos);
    norm = pos;
    PSVECNormalize(&norm, &norm);
    o->v56(0, &norm);
    return 1;
}

extern "C" s32 fn_802E6764(void * arg0, void ** arg1) {
    VDispatch *o = (VDispatch *) arg1;
    Vec3f *b;
    Vec3f *p2;
    Vec3f norm;
    Vec3f pos;
    if (o->v45()) {
        return 0;
    }
    if (FU16(arg0, 0x48) == o->v10()) {
        return 0;
    }
    if (o->v8() == 8) {
        return 0;
    }
    b = ((VGeom2 *) ((char *) arg0 + 0x24))->v0();
    p2 = ((VGeom2 *) ((char *) arg0 + 0x24))->v1();
    pos = *p2;
    PSVECSubtract(&pos, b, &pos);
    norm = pos;
    PSVECNormalize(&norm, &norm);
    o->v56(1, &norm);
    return 1;
}

extern "C" s32 fn_802E6898(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" f32 fn_802E6B2C(f32 farg0) {
    (void) farg0;
    return 0.0f;
}

extern "C" f32 fn_802E6F88(f32 farg0) {
    (void) farg0;
    return 0.0f;
}

extern "C" s32 fn_802E73D4(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_802E75B4(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802E7798(void * arg0) {
    (void) arg0;
}

extern "C" s32 fn_802E794C(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_802E79E0(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802E7CB8(void * arg0) {
    (void) arg0;
}

extern "C" s32 fn_802E7E6C(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_802E7F2C(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" u32 fn_802E7FE4(void * arg0, void ** arg1) {
    VGeom *o = (VGeom *) arg1;
    Vec3f *b;
    Vec3f pos;
    Vec3f sq;
    f32 distSq;
    f32 sumSq;
    b = ((VGeom *) ((char *) arg0 + 0x24))->v0();
    pos = *o->v0();
    PSVECSubtract(&pos, b, &pos);
    sq = pos;
    distSq = PSVECSquareMag(&sq);
    sumSq = ((VGeom *) ((char *) arg0 + 0x24))->v1() * ((VGeom *) ((char *) arg0 + 0x24))->v1()
          + o->v1() * o->v1();
    return distSq < sumSq;
}

extern "C" void fn_802E8134(void * arg0) {
    Color4 c;
    c.r = 0xFF;
    c.g = 0;
    c.b = 0xFF;
    c.a = 0xFF;
    ((VColorWidget *) ((char *) arg0 + 0x24))->v3(&c);
}

extern "C" void **** fn_802E817C(void **** arg0, s16 arg1) {
    void *e;
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804D7104;
    e = (char *) arg0 + 0x24;
    *(void **) e = (void *) ((char *) &lbl_804D7104 + 0x38);
    if (e == 0) {
        goto skip1;
    }
    *(void **) e = (void *) &lbl_804BDB74;
skip1:
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804D7700;
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804BF4DC;
    ((VDispatch *) arg0)->v5();
skip2:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" u32 fn_802E8228(void * arg0, void ** arg1) {
    VGeom *o = (VGeom *) arg1;
    Vec3f *b;
    Vec3f pos;
    Vec3f sq;
    f32 distSq;
    f32 sumSq;
    b = ((VGeom *) ((char *) arg0 + 0x24))->v0();
    pos = *o->v0();
    PSVECSubtract(&pos, b, &pos);
    sq = pos;
    distSq = PSVECSquareMag(&sq);
    sumSq = ((VGeom *) ((char *) arg0 + 0x24))->v1() * ((VGeom *) ((char *) arg0 + 0x24))->v1()
          + o->v1() * o->v1();
    return distSq < sumSq;
}

extern "C" void fn_802E8378(void * arg0) {
    Color4 c;
    c.r = 0xFF;
    c.g = 0;
    c.b = 0xFF;
    c.a = 0xFF;
    ((VColorWidget *) ((char *) arg0 + 0x24))->v3(&c);
}

extern "C" void **** fn_802E83C0(void **** arg0, s16 arg1) {
    void *e;
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804D719C;
    e = (char *) arg0 + 0x24;
    *(void **) e = (void *) ((char *) &lbl_804D719C + 0x38);
    if (e == 0) {
        goto skip1;
    }
    *(void **) e = (void *) &lbl_804BDB74;
skip1:
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804D7700;
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804BF4DC;
    ((VDispatch *) arg0)->v5();
skip2:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void fn_802E846C(s32 arg0) {
    kar_fl_indirectload__near_80393820((void *) (arg0 + 0x24));
}

extern "C" void fn_802E8490(void * arg0) {
    Color4 c;
    c.r = 0xFF;
    c.g = 0;
    c.b = 0xFF;
    c.a = 0xFF;
    ((VColorWidget *) ((char *) arg0 + 0x24))->v5(&c);
}

extern "C" void **** fn_802E84D8(void **** arg0, s16 arg1) {
    void *e;
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804D7260;
    e = (char *) arg0 + 0x24;
    *(void **) e = (void *) ((char *) &lbl_804D7260 + 0x38);
    if (e == 0) {
        goto skip1;
    }
    *(void **) e = (void *) &lbl_804BF3C0;
skip1:
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804D7700;
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804BF4DC;
    ((VDispatch *) arg0)->v5();
skip2:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void fn_802E8584(s32 arg0) {
    kar_fl_indirectload__near_80393820((void *) (arg0 + 0x24));
}

extern "C" void fn_802E85A8(void * arg0) {
    Color4 c;
    c.r = 0xFF;
    c.g = 0;
    c.b = 0xFF;
    c.a = 0xFF;
    ((VColorWidget *) ((char *) arg0 + 0x24))->v5(&c);
}

extern "C" void **** fn_802E85F0(void **** arg0, s16 arg1) {
    void *e;
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804D7300;
    e = (char *) arg0 + 0x24;
    *(void **) e = (void *) ((char *) &lbl_804D7300 + 0x38);
    if (e == 0) {
        goto skip1;
    }
    *(void **) e = (void *) &lbl_804BF3C0;
skip1:
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804D7700;
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804BF4DC;
    ((VDispatch *) arg0)->v5();
skip2:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" u32 fn_802E869C(void * arg0, void ** arg1) {
    VGeom *o = (VGeom *) arg1;
    Vec3f *b;
    Vec3f pos;
    Vec3f sq;
    f32 distSq;
    f32 sumSq;
    b = ((VGeom *) ((char *) arg0 + 0x24))->v0();
    pos = *o->v0();
    PSVECSubtract(&pos, b, &pos);
    sq = pos;
    distSq = PSVECSquareMag(&sq);
    sumSq = ((VGeom *) ((char *) arg0 + 0x24))->v1() * ((VGeom *) ((char *) arg0 + 0x24))->v1()
          + o->v1() * o->v1();
    return distSq < sumSq;
}

extern "C" void fn_802E87EC(void * arg0) {
    Color4 c;
    c.r = 0xFF;
    c.g = 0;
    c.b = 0xFF;
    c.a = 0xFF;
    ((VColorWidget *) ((char *) arg0 + 0x24))->v3(&c);
}

extern "C" void **** fn_802E8834(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void **** fn_802E88F8(void **** arg0, s16 arg1) {
    void *e;
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804D743C;
    e = (char *) arg0 + 0x24;
    *(void **) e = (void *) ((char *) &lbl_804D743C + 0x38);
    if (e == 0) {
        goto skip1;
    }
    *(void **) e = (void *) &lbl_804BDB74;
skip1:
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804D7700;
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804BF4DC;
    ((VDispatch *) arg0)->v5();
skip2:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" u32 fn_802E89A4(void * arg0, void ** arg1) {
    VGeom *o = (VGeom *) arg1;
    Vec3f *b;
    Vec3f pos;
    Vec3f sq;
    f32 distSq;
    f32 sumSq;
    b = ((VGeom *) ((char *) arg0 + 0x24))->v0();
    pos = *o->v0();
    PSVECSubtract(&pos, b, &pos);
    sq = pos;
    distSq = PSVECSquareMag(&sq);
    sumSq = ((VGeom *) ((char *) arg0 + 0x24))->v1() * ((VGeom *) ((char *) arg0 + 0x24))->v1()
          + o->v1() * o->v1();
    return distSq < sumSq;
}

extern "C" void fn_802E8AF4(void * arg0) {
    Color4 c;
    c.r = 0xFF;
    c.g = 0;
    c.b = 0xFF;
    c.a = 0xFF;
    ((VColorWidget *) ((char *) arg0 + 0x24))->v3(&c);
}

extern "C" void **** fn_802E8B3C(void **** arg0, s16 arg1) {
    void *e;
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804D74D0;
    e = (char *) arg0 + 0x24;
    *(void **) e = (void *) ((char *) &lbl_804D74D0 + 0x38);
    if (e == 0) {
        goto skip1;
    }
    *(void **) e = (void *) &lbl_804BDB74;
skip1:
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804D7700;
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804BF4DC;
    ((VDispatch *) arg0)->v5();
skip2:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void fn_802E8BE8(s32 arg0) {
    kar_fl_indirectload__near_80393820((void *) (arg0 + 0x24));
}

extern "C" void fn_802E8C0C(void * arg0) {
    Color4 c;
    c.r = 0xFF;
    c.g = 0;
    c.b = 0xFF;
    c.a = 0xFF;
    ((VColorWidget *) ((char *) arg0 + 0x24))->v5(&c);
}

extern "C" void **** fn_802E8C54(void **** arg0, s16 arg1) {
    void *e;
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804D7568;
    e = (char *) arg0 + 0x24;
    *(void **) e = (void *) ((char *) &lbl_804D7568 + 0x38);
    if (e == 0) {
        goto skip1;
    }
    *(void **) e = (void *) &lbl_804BF3C0;
skip1:
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804D7700;
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804BF4DC;
    ((VDispatch *) arg0)->v5();
skip2:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void fn_802E8D00(s32 arg0) {
    kar_fl_indirectload__near_80393820((void *) (arg0 + 0x24));
}

extern "C" void fn_802E8D24(void * arg0) {
    Color4 c;
    c.r = 0xFF;
    c.g = 0;
    c.b = 0xFF;
    c.a = 0xFF;
    ((VColorWidget *) ((char *) arg0 + 0x24))->v5(&c);
}

extern "C" void **** fn_802E8D6C(void **** arg0, s16 arg1) {
    void *e;
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804D7604;
    e = (char *) arg0 + 0x24;
    *(void **) e = (void *) ((char *) &lbl_804D7604 + 0x38);
    if (e == 0) {
        goto skip1;
    }
    *(void **) e = (void *) &lbl_804BF3C0;
skip1:
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804D7700;
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804BF4DC;
    ((VDispatch *) arg0)->v5();
skip2:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" s32 fn_802E8E18(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802E9004(void * arg0) {
    Color4 c;
    c.r = 0xFF;
    c.g = 0;
    c.b = 0xFF;
    c.a = 0xFF;
    ((VColorWidget *) ((char *) arg0 + 0x24))->v3(&c);
}

extern "C" void **** fn_802E904C(void **** arg0, s16 arg1) {
    void *e;
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) &lbl_804D76A0;
    e = (char *) arg0 + 0x24;
    *(void **) e = (void *) ((char *) &lbl_804D76A0 + 0x38);
    if (e == 0) {
        goto skip1;
    }
    *(void **) e = (void *) &lbl_804BDB74;
skip1:
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804D7700;
    if (arg0 == 0) {
        goto skip2;
    }
    *(void **) arg0 = (void *) &lbl_804BF4DC;
    ((VDispatch *) arg0)->v5();
skip2:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void **** fn_802E90F8(void **** arg0, s16 arg1) {
    if (arg0 == 0) {
        goto skip_all;
    }
    *(void **) arg0 = (void *) lbl_804D7700;
    if (arg0 == 0) {
        goto skip1;
    }
    *(void **) arg0 = (void *) lbl_804BF4DC;
    ((VDispatch *) arg0)->v5();
skip1:
    if (arg1 <= 0) {
        goto skip_all;
    }
    fn_8038CB78(arg0);
skip_all:
    return arg0;
}

extern "C" void fn_802E9170(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802E9178(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802E9180(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802E9188(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802E9190(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802E9198(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802E91A0(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802E91A8(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802E91B0(s32 arg0) {
    (void) arg0;
}

extern "C" void fn_802E91B8(s32 arg0) {
    (void) arg0;
}

extern "C" void * fn_802E91C0(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802E9468(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802E9508(void * arg0, void * arg1, void * arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void fn_802E99F8(f32 * arg0, f32 * arg1, void * arg2, f32 farg0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) farg0;
}

extern "C" void kar_diag__802e9aec(void * arg0, void * arg1, u8 * arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void kar_diag__802e9e0c(void * arg0, void * arg1, u32 arg2, f32 * arg3, f32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
}

extern "C" void kar_diag__802ea3d4(void * arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void * fn_802EA580(void * arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void **** fn_802EA600(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" f32 * fn_802EA65C(void) {
    return (f32 *) &lbl_804D7F48;
}

extern "C" void fn_802EA668(void * arg0) {
    (void) arg0;
}

extern "C" s32 fn_802EB094(void * arg0, f32 * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" u8 fn_802EBB98(void * arg0, f32 * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" f32 fn_802EBFE8(f32 farg0) {
    (void) farg0;
    return 0.0f;
}

extern "C" f32 fn_802EC434(f32 farg0) {
    (void) farg0;
    return 0.0f;
}

extern "C" u8 fn_802EC890(void * arg0, f32 * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_802ECB7C(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" s32 fn_802ECC54(void * arg0, f32 * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" u8 fn_802ED1D4(f32 * arg0, f32 * arg1, f32 * arg2, f32 farg0, f32 farg1) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) farg0;
    (void) farg1;
    return 0;
}

extern "C" s32 fn_802ED434(void * arg0, f32 * arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}
