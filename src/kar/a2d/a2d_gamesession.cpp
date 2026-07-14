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
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(s32);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
};

extern "C" {
extern char lbl_804D40F0[0x2A08];
extern char lbl_804D7F48[0x528];
extern char lbl_804F5230[0x3C];
extern char lbl_804F526C[0x3C];
extern char lbl_804F52A8[0x3C];
extern const f32 lbl_805E3690;
extern const f32 lbl_805E3728;
extern const f32 lbl_805E3730;
extern const f32 lbl_805E3780;
extern const f32 lbl_805E3788;

void HSD_JObjAnimAll(void *jobj);
void *fn_803120C0(void *arg0);
void *kar_fl_indirectload__near_80393820(void *arg0);
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
void * fn_802BA97C(void * arg0);
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
void fn_802DA638(void * arg0, f32 * arg1, f32 farg0, f32 farg1);
void fn_802DA818(void * arg0, f32 * arg1, f32 farg0, f32 farg1);
void fn_802DA9F8(void * arg0, f32 * arg1, f32 farg0, f32 farg1);
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
void fn_802DDBB0(void * arg0);
void fn_802DDBE8(void * arg0);
void fn_802DDC94(void * arg0);
void fn_802DDD40(void * arg0);
void fn_802DDDEC(void * arg0);
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
    return 0;
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
    (void) arg0;
    return 0;
}

extern "C" void * fn_802BA97C(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802BA9C8(void * arg0) {
    (void) arg0;
    return 0;
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
    (void) arg0;
    return 0;
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
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802CBFEC(void * arg0) {
    (void) arg0;
}

extern "C" void **** fn_802CC028(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802CC10C(void * arg0) {
    (void) arg0;
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
    (void) arg0;
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
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void fn_802D1824(f32 * arg0, f32 * arg1, void * arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void fn_802D1898(void * arg0, f32 farg0) {
    (void) arg0;
    (void) farg0;
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
    (void) arg0;
    return 0;
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
    (void) arg0;
    (void) arg1;
    return 0;
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
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void *** fn_802D3C8C(void *** arg0, void *** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" u32 fn_802D3CF0(void **** arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
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
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void **** fn_802D4024(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
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
    (void) arg0;
    (void) arg1;
    return 0;
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
    (void) arg0;
    (void) farg0;
    return 0;
}

extern "C" f32 * fn_802D43D8(f32 * arg0, f32 farg0) {
    (void) arg0;
    (void) farg0;
    return 0;
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

extern "C" f32 fn_802D4C30(f32 farg0) {
    return lbl_805E3728 / farg0;
}

extern "C" f32 fn_802D4C3C(f32 farg0) {
    f32 t = lbl_805E3728 / farg0;
    return t / farg0;
}

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
    (void) arg0;
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
    (void) arg0;
    return 0;
}

extern "C" s32 fn_802D5760(void * arg0, s32 arg1, s32 arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    return 0;
}

extern "C" s32 fn_802D5834(void * arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg_sp0;
    return 0;
}

extern "C" s32 fn_802D5900(void * arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg_sp0;
    return 0;
}

extern "C" s32 fn_802D59CC(void * arg0, s32 arg1, s32 arg2, s32 arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    return 0;
}

extern "C" s32 fn_802D5AA0(void * arg0, s32 arg1, s32 arg2, s32 arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    return 0;
}

extern "C" void fn_802D5B74(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802D5BE4(void * arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802D5C64(void * arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
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
    (void) arg0;
    return 0.0f;
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
    (void) arg0;
    (void) arg1;
    return 0;
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
    (void) arg0;
    (void) arg1;
    (void) arg2;
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
    (void) arg0;
    (void) arg1;
    return 0;
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
    (void) arg0;
}

extern "C" void fn_802D97B8(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802D9800(f32 * arg0) {
    (void) arg0;
}

extern "C" f32 fn_802D9870(void) {
    return lbl_805E3788;
}

extern "C" void fn_802D9878(f32 * arg0) {
    (void) arg0;
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
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_802D9C2C(void) {
    return 0;
}

extern "C" void **** fn_802D9C34(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
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
    (void) arg0;
    return 0;
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
    (void) arg0;
    return 0;
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
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg_sp0;
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
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg_sp0;
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
    (void) arg0;
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

extern "C" void fn_802DA638(void * arg0, f32 * arg1, f32 farg0, f32 farg1) {
    (void) arg0;
    (void) arg1;
    (void) farg0;
    (void) farg1;
}

extern "C" void fn_802DA818(void * arg0, f32 * arg1, f32 farg0, f32 farg1) {
    (void) arg0;
    (void) arg1;
    (void) farg0;
    (void) farg1;
}

extern "C" void fn_802DA9F8(void * arg0, f32 * arg1, f32 farg0, f32 farg1) {
    (void) arg0;
    (void) arg1;
    (void) farg0;
    (void) farg1;
}

extern "C" f32 fn_802DABD8(f32 farg0) {
    f32 t = farg0 * lbl_805E3788;
    t = farg0 * t;
    return farg0 * t;
}

extern "C" void fn_802DABEC(f32 * arg0, f32 * arg1) {
    (void) arg0;
    (void) arg1;
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
    (void) arg0;
    return 0;
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
    (void) arg0;
    return 0;
}

extern "C" void ** fn_802DD880(void ** arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802DD94C(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802DDA18(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void * fn_802DDAE4(void * arg0) {
    (void) arg0;
    return 0;
}

extern "C" void fn_802DDBB0(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802DDBE8(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802DDC94(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802DDD40(void * arg0) {
    (void) arg0;
}

extern "C" void fn_802DDDEC(void * arg0) {
    (void) arg0;
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
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_802E5DCC(f32 * arg0, f32 * arg1) {
    (void) arg0;
    (void) arg1;
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
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_802E6764(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
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
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802E8134(void * arg0) {
    (void) arg0;
}

extern "C" void **** fn_802E817C(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" u32 fn_802E8228(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802E8378(void * arg0) {
    (void) arg0;
}

extern "C" void **** fn_802E83C0(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802E846C(s32 arg0) {
    kar_fl_indirectload__near_80393820((void *) (arg0 + 0x24));
}

extern "C" void fn_802E8490(void * arg0) {
    (void) arg0;
}

extern "C" void **** fn_802E84D8(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802E8584(s32 arg0) {
    kar_fl_indirectload__near_80393820((void *) (arg0 + 0x24));
}

extern "C" void fn_802E85A8(void * arg0) {
    (void) arg0;
}

extern "C" void **** fn_802E85F0(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" u32 fn_802E869C(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802E87EC(void * arg0) {
    (void) arg0;
}

extern "C" void **** fn_802E8834(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void **** fn_802E88F8(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" u32 fn_802E89A4(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802E8AF4(void * arg0) {
    (void) arg0;
}

extern "C" void **** fn_802E8B3C(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802E8BE8(s32 arg0) {
    kar_fl_indirectload__near_80393820((void *) (arg0 + 0x24));
}

extern "C" void fn_802E8C0C(void * arg0) {
    (void) arg0;
}

extern "C" void **** fn_802E8C54(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802E8D00(s32 arg0) {
    kar_fl_indirectload__near_80393820((void *) (arg0 + 0x24));
}

extern "C" void fn_802E8D24(void * arg0) {
    (void) arg0;
}

extern "C" void **** fn_802E8D6C(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_802E8E18(void * arg0, void ** arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_802E9004(void * arg0) {
    (void) arg0;
}

extern "C" void **** fn_802E904C(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void **** fn_802E90F8(void **** arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
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
