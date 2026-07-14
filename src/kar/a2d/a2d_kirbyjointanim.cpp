#include <dolphin/types.h>

extern "C" {
#include <global.h>
#include <sysdolphin/jobj.h>
}

#define FU8(p, o) (*(u8 *) ((char *) (p) + (o)))
#define FS8(p, o) (*(s8 *) ((char *) (p) + (o)))
#define FU16(p, o) (*(u16 *) ((char *) (p) + (o)))
#define FS16(p, o) (*(s16 *) ((char *) (p) + (o)))
#define FU32(p, o) (*(u32 *) ((char *) (p) + (o)))
#define FS32(p, o) (*(s32 *) ((char *) (p) + (o)))
#define FF32(p, o) (*(f32 *) ((char *) (p) + (o)))
#define FP(p, o) (*(void **) ((char *) (p) + (o)))

#define GX_FIFO_F32 (*(volatile f32 *) 0xCC008000)

struct Vec3f {
    f32 x, y, z;
};

struct Vec4f {
    f32 x, y, z, w;
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

struct KJPartWithEffect {
    char pad0[0xC];
    GameEffectItem effect;
};

struct KJPartWithEffect10 {
    char pad0[0x10];
    GameEffectItem effect;
};

struct KJPartWithEffect8 {
    char pad0[0x8];
    GameEffectItem effect;
};

struct KJPartWithEffect18 {
    char pad0[0x18];
    GameEffectItem effect;
};

class VDispatch3 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

class VDispatch16 {
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
};

extern "C" {
void *fn_802DE0E4(void);
void *TopRideItem_GetDataBase(void);
void fn_802E498C(void *arg0, f32 *arg1);
void fn_8038CB78(void *arg0);
extern const f32 lbl_805E3AD0;
extern const f32 lbl_805E3EE8;
extern const f32 lbl_805E3C98;
extern const f32 lbl_805E3BC0;
extern char lbl_804DD0D8[0x808];
extern char lbl_804E09F4[0xC];
extern char lbl_804DB4D4[0x1BC];
extern char lbl_804DAAB4[0xC];
extern char lbl_804D6F5C[0xE4];
extern char lbl_804D1A98[0x80];
extern char lbl_804DB7B8[0xE0];
extern char lbl_804DC254[0xE4];
extern char lbl_804DBF80[0xC];
extern char lbl_804DC050[0xE0];
extern char lbl_804DB188[0xE0];
extern char lbl_804DB088[0xE0];
extern char lbl_804DB9C4[0xE0];
extern char lbl_804DB288[0x108];
extern char lbl_804BDF70[0x28];
extern char lbl_804BDF2C[0x28];
void kar_a2d_effecthandle__near_8037b33c(GameEffectItem *arg0, u8 arg1);
extern char lbl_804E0898[0xC];
extern char lbl_804E0E6C[0xC];
extern u32 lbl_805DDBC8;
extern u32 lbl_805DDBCC;
extern u32 lbl_805DDB30;
extern char kar_resrec_a2a2dbg_000f_804e0620[0x15C];
HSD_JObj *fn_8038D0A8(void *, s32);
void PSMTXCopy(Mtx src, Mtx dst);
/* "jobj.h" assert strings, owned by a2d_cpu_kirby */
extern char kar_srcfile_jobj_h_805d9800[7];
extern char lbl_805D9808[5];
extern char lbl_805D9810[4];
}

extern "C" {
void kar_a2d_kirbyjointanim__802efa2c(void * arg0, void * arg1, void * arg2, f32 farg0);
void kar_a2d_kirbyjointanim__near_802efd8c(void *arg0, void *arg1, void * arg2, f32 farg0);
void fn_802EFE1C(void * arg0);
void kar_a2d_kirbyjointanim__near_802efe44(void * arg0);
void kar_a2d_kirbyjointanim__near_802effb8(void * arg0, void * arg1, u32 arg2);
void kar_a2d_kirbyjointanim__near_802f0148(void * arg0, u32 arg1, f32 farg0);
void * kar_a2d_kirbyjointanim__near_802f0268(void * arg0, s32 arg1, s32 arg_sp0);
void * kar_a2d_kirbyjointanim__near_802f0944(void * arg0, void ** arg1, s32 arg_sp0);
void kar_a2d_kirbyjointanim__near_802f0a20(void * arg0, u8 * arg1);
void ** kar_diag__802f0a40(void * arg0, s32 arg1, u8 arg2, u8 arg3, void ** arg4, s32 arg_sp0);
void * kar_a2d_kirbyjointanim__near_802f0b60(void * arg0, s32 arg1, s32 arg2);
void kar_a2d_kirbyjointanim__near_802f0cc0(void *arg0);
void kar_a2d_kirbyjointanim__near_802f0d30(void * arg0, f32 * arg1, s32 arg2);
void kar_a2d_kirbyjointanim__near_802f10a4(void * arg0, u8 arg1, f32 * arg2);
void kar_a2d_kirbyjointanim__near_802f1188(void * arg0);
void kar_a2d_kirbyjointanim__near_802f11c0(void * arg0, f32 * arg1, u8 arg2);
void fn_802F13E8(void * arg0, f32 * arg1);
void fn_802F1594(void * arg0, f32 * arg1);
void fn_802F16A0(void * arg0, void * arg1);
void fn_802F1828(void * arg0);
void fn_802F1860(void * arg0);
void fn_802F189C(void * arg0);
void * fn_802F18D8(void * arg0);
s32 fn_802F1F0C(void * arg0);
s32 fn_802F2268(void * arg0);
void fn_802F242C(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0);
void fn_802F2AC0(void * arg0);
void fn_802F2D4C(void * arg0);
void fn_802F3084(void * arg0);
void * fn_802F3128(void * arg0);
void ** fn_802F32A0(void *arg0, s16 arg1);
void fn_802F33B8(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0);
void fn_802F3534(void * arg0);
void fn_802F37D8(void * arg0);
void fn_802F38F0(void * arg0);
void * fn_802F39A0(void * arg0, void * arg2);
void fn_802F3BD0(void * arg0);
void fn_802F3CFC(void * arg0);
void fn_802F3FE0(void * arg0);
void ** fn_802F4068(void *arg0);
void fn_802F4380(void * arg0);
void fn_802F4508(void * arg0);
void fn_802F488C(void * arg0);
void * fn_802F4A48(void * arg0, u32 arg2, void * arg3);
void fn_802F4D0C(void * arg0);
void fn_802F4E6C(void * arg0);
void fn_802F52A0(void * arg0);
void fn_802F53DC(void * arg0, u32 arg1, void * arg2);
f32 fn_802F5890(f32 farg0);
f32 fn_802F5CDC(f32 farg0);
void * fn_802F6138(void * arg0, u32 arg2, void * arg3, s16 arg4, s16 arg5);
void fn_802F6540(void * arg0);
void fn_802F66A0(void * arg0);
void fn_802F6AEC(void * arg0);
void * fn_802F6C28(void * arg0, u32 arg2, void * arg3, s16 arg4, s16 arg5);
void fn_802F7030(void * arg0);
void fn_802F7190(void * arg0);
void fn_802F75DC(void * arg0);
void * fn_802F7718(void * arg0, u16 arg2, void *arg3, s16 arg4);
void * fn_802F7B28(void * arg0);
void ** fn_802F7BF4(void *arg0, s16 arg1);
void fn_802F7D54(void * arg0);
void ** fn_802F7F24(void *arg0);
void fn_802F82F0(void * arg0);
void fn_802F8450(void * arg0);
void * fn_802F858C(void * arg0, s32 arg2);
void fn_802F88DC(void * arg0);
void fn_802F8920(void * arg0);
void * fn_802F8A5C(void * arg0, void * arg2, void * arg3, s16 arg4, s16 arg5);
void fn_802F8DD8(void * arg0);
void fn_802F90BC(void * arg0);
void * fn_802F958C(void * arg0, u16 arg2, f32 * arg3, s16 arg4);
void fn_802F99B0(void * arg0);
void fn_802F9C34(void * arg0);
void fn_802FA030(void * arg0);
void ** fn_802FA16C(void *arg0);
void fn_802FA5B4(void * arg0);
void fn_802FA734(void * arg0);
void fn_802FA8A8(void * arg0);
void fn_802FA9E4(void * arg0);
void * fn_802FAA88(void * arg0, u8 arg2);
void fn_802FAD0C(void * arg0);
void fn_802FAE80(void * arg0);
void fn_802FAFBC(void * arg0);
void * fn_802FB060(void * arg0, void * arg2, void * arg3, s16 arg4, s16 arg5);
void fn_802FB3A0(void * arg0);
void fn_802FB580(void * arg0);
void fn_802FBA00(void * arg0, s8 arg1);
void * fn_802FBAF0(void * arg0, void * arg2, void * arg3, s16 arg4);
void fn_802FBD44(void * arg0);
void fn_802FBEE4(void * arg0);
void ** fn_802FC1BC(void *arg0, s16 arg1);
s32 fn_802FC31C(void);
s32 fn_802FC324(void);
s32 fn_802FC32C(void);
s32 fn_802FC334(void);
s32 fn_802FC33C(void * arg0);
void ** fn_802FC35C(void *arg0, s16 arg1);
s32 fn_802FC48C(void);
s32 fn_802FC494(void);
s32 fn_802FC49C(void);
s32 fn_802FC4A4(void);
void ** fn_802FC4AC(void *arg0, s16 arg1);
s32 fn_802FC60C(void);
s32 fn_802FC614(void);
s32 fn_802FC61C(void);
s32 fn_802FC624(void);
s32 fn_802FC62C(void * arg0);
void ** fn_802FC654(void *arg0, s16 arg1);
s32 fn_802FC784(void);
s32 fn_802FC78C(void);
s32 fn_802FC794(void);
s32 fn_802FC79C(void * arg0);
void ** fn_802FC7F8(void *arg0, s16 arg1);
s32 fn_802FC98C(void);
void fn_802FC994(void ** arg0);
s32 fn_802FC9D4(void * arg0);
void ** fn_802FCAD4(void *arg0, s16 arg1);
s32 fn_802FCC7C(void);
void fn_802FCC84(void * arg0);
s32 fn_802FCDB0(void * arg0);
void ** fn_802FCE0C(void *arg0, s16 arg1);
s32 fn_802FCFB4(void);
s32 fn_802FCFBC(void * arg0);
s32 fn_802FCFE4(void);
void ** fn_802FCFEC(void *arg0, s16 arg1);
s32 fn_802FD194(void);
s32 fn_802FD19C(void * arg0);
void ** fn_802FD1C0(void *arg0, s16 arg1);
s32 fn_802FD3A4(void);
void fn_802FD3AC(void ** arg0);
s32 fn_802FD3EC(void * arg0);
s32 fn_802FD43C(void);
s32 fn_802FD444(void);
s32 fn_802FD44C(void * arg0);
void fn_802FD49C(void * arg0);
void ** fn_802FD5B0(void *arg0, s16 arg1);
void ** fn_802FD76C(void *arg0, s16 arg1);
s32 fn_802FD8E0(void);
f32 fn_802FD8E8(void);
f32 fn_802FD90C(void * arg0);
s32 fn_802FDA94(void * arg0);
void ** fn_802FDAE4(void *arg0, s16 arg1);
s32 fn_802FDC58(void);
f32 fn_802FDC60(void);
f32 fn_802FDC84(void * arg0);
s32 fn_802FDE0C(void * arg0);
void ** fn_802FDE5C(void *arg0, s16 arg1);
s32 fn_802FDFD0(void);
f32 fn_802FDFD8(void);
f32 fn_802FDFFC(void * arg0);
s32 fn_802FE184(void * arg0);
s32 fn_802FE1D4(void * arg0);
void ** fn_802FE1F4(void *arg0, s16 arg1);
s32 fn_802FE340(void);
s32 fn_802FE348(void);
s32 fn_802FE350(void * arg0);
void fn_802FE3A0(void);
f32 fn_802FE3A4(void);
s32 fn_802FE3AC(void);
s32 fn_802FE3B4(void);
s32 fn_802FE3BC(void);
s32 fn_802FE3C4(void);
s32 fn_802FE3CC(void);
s32 fn_802FE3D4(void);
s32 fn_802FE3DC(void);
s32 fn_802FE3E4(void);
s32 fn_802FE3EC(void * arg0);
void fn_802FE448(void);
void ** fn_802FE44C(void *arg0, s16 arg1);
s32 fn_802FE5E4(void);
s32 fn_802FE5EC(void);
s32 fn_802FE5F4(void);
s32 fn_802FE5FC(void);
s32 fn_802FE604(void);
s32 fn_802FE60C(void);
s32 fn_802FE614(void ** arg0);
s32 fn_802FE64C(void);
f32 fn_802FE654(void * arg0);
void fn_802FE674(f32 * arg0, void * arg1, f32 * arg2, f32 * arg3, f32 * arg4, f32 farg0);
void * fn_802FE890(void * arg0);
void ** fn_802FEBB0(void *arg0, s16 arg1);
void ** fn_802FEC4C(void *arg0, s16 arg1);
void fn_802FECB4(void *arg0);
void fn_802FECE0(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0);
void fn_802FED78(void * arg0);
void fn_802FEEC4(void * arg0);
void fn_802FEF68(void * arg0);
f32 fn_802FF540(f32 farg0);
void * fn_802FF98C(void * arg0, void * arg2, void * arg3, s32 arg_sp0);
void ** fn_802FFFFC(void *arg0, s16 arg1);
void fn_803000BC(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0);
void fn_80300180(void * arg0);
void fn_80300804(void * arg0);
void * fn_803008A8(void * arg0);
void fn_80300A80(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0);
void fn_80300BC8(void * arg0);
void fn_80300D14(void * arg0);
void * fn_80300DB8(void * arg0, void *** arg1);
void fn_803011A0(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0);
void fn_803016C0(void * arg0);
void fn_80301A64(void * arg0);
void * fn_80301B08(void * arg0);
void fn_80301CC8(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0);
void fn_80301DCC(f32 * arg0);
void fn_80301E34(void * arg0);
void fn_803020A4(void * arg0);
void * fn_80302148(void * arg0);
void fn_80302398(void * arg0, void *arg2);
void fn_80302440(void *arg0);
void fn_803024A8(void * arg0);
void fn_80302C60(void * arg0);
void * fn_80302D04(void * arg0);
void fn_80302F90(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0);
void fn_803032B0(void * arg0);
void fn_803033FC(void * arg0);
void * fn_803034A0(void * arg0);
void fn_80303678(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0);
void fn_803038F8(void * arg0);
void fn_803039F4(void * arg0);
void * fn_80303A98(void * arg0);
void fn_80303D64(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0);
f32 fn_80304248(f32 farg0);
void fn_803046A4(void * arg0);
void fn_8030481C(void * arg0);
void ** fn_803048E0(KJPartWithEffect10 *arg0, s16 arg1);
s32 fn_803049FC(void);
s32 fn_80304A04(void);
s32 fn_80304A0C(void * arg0);
void ** fn_80304A68(KJPartWithEffect *arg0, s16 arg1);
s32 fn_80304B48(void);
s32 fn_80304B50(void);
s32 fn_80304B58(void * arg0);
s32 fn_80304B68(void * arg0);
void ** fn_80304BC0(KJPartWithEffect18 *arg0, s16 arg1);
s32 fn_80304CB0(void);
s32 fn_80304CB8(void);
s32 fn_80304CC0(void * arg0);
s32 fn_80304CD0(void * arg0);
void ** fn_80304D18(void *arg0, s16 arg1);
s32 fn_80304DAC(void);
s32 fn_80304DB4(void);
s32 fn_80304DBC(void * arg0);
void ** fn_80304DD0(void *arg0, s16 arg1);
s32 fn_80304E64(void);
s32 fn_80304E6C(void);
s32 fn_80304E74(void * arg0);
void ** fn_80304E88(void *arg0, s16 arg1);
s32 fn_80305060(void);
s32 fn_80305068(void * arg0);
s32 fn_8030507C(void * arg0);
s32 fn_80305090(void);
s32 fn_80305098(void * arg0);
u8 fn_803050AC(void * arg0);
s32 fn_803050B4(void * arg0);
void fn_803050C8(void ** arg0);
s32 fn_803050F4(void * arg0);
s32 fn_80305108(void *arg0);
f32 fn_80305190(void);
f32 fn_803051B4(void);
f32 fn_803051D8(void * arg0);
void ** fn_803051F8(KJPartWithEffect8 *arg0, s16 arg1);
s32 fn_80305314(void);
s32 fn_8030531C(void);
s32 fn_80305324(void *arg0, f32 farg0);
f32 fn_80305390(void);
u32 fn_803053B4(void);
f32 fn_803053DC(void);
void ** fn_80305400(void *arg0, s16 arg1);
s32 fn_80305654(void);
s32 fn_8030565C(void);
s32 fn_80305664(void *arg0);
s32 fn_803056EC(void);
s32 fn_803056F4(void);
f32 fn_803056FC(void);
void ** fn_80305720(void *arg0, s16 arg1);
s32 fn_80305890(void);
s32 fn_80305898(void);
s32 fn_803058A0(void *arg0, f32 farg0);
f32 fn_8030590C(void);
void ** fn_80305930(void *arg0);
void fn_80305964(void *arg0);
void fn_8030599C(void *arg0);
void fn_803059D8(void *arg0);
void fn_80305A54(void *arg0);
void fn_80305A88(void *arg0);
void fn_80305ABC(void *arg0, u32 arg1);
void fn_80305B38(s32 ** arg0, void * arg1, s32 *** arg2, void * arg3);
void fn_80305BEC(s32 ** arg0, void * arg1, s32 *** arg2, void * arg3);
s32 * fn_80305CA0(void * arg0);
s32 * fn_80305CC8(void * arg0);
void * fn_80305CF0(void * arg0, void * arg1, void * arg2);
void kar_diag__80305ec8(void * arg0, void * arg1, u32 arg2, void * arg3, s32 arg_sp0);
void * fn_803065B8(void * arg0);
void * fn_8030668C(void * arg0);
void fn_803067B4(void * arg0);
void fn_803069B4(void * arg0);
void fn_80306ACC(void * arg0);
void fn_80306DDC(void * arg0);
void * fn_80306E80(void * arg0);
void fn_803070E4(void * arg0);
void fn_80307244(void * arg0);
void ** fn_803072E8(void *arg0, s16 arg1);
s32 fn_803073BC(void);
s32 fn_803073C4(void * arg0);
void ** fn_80307400(void *arg0, s16 arg1);
s32 fn_80307528(void);
s32 fn_80307530(void);
s32 fn_80307538(void);
s32 fn_80307540(void);
s32 fn_80307548(void);
void fn_80307550(void ** arg0);
s32 fn_8030757C(void * arg0);
void fn_8030759C(void);
void ** fn_803075A0(void *arg0, s16 arg1);
s32 fn_80307634(void);
s32 fn_8030763C(void);
void * fn_80307644(void * arg0);
void fn_80307974(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0);
f32 fn_80308524(f32 farg0);
f32 fn_80308980(f32 farg0);
void fn_80308DCC(void * arg0);
void fn_80308FD0(void * arg0);
void * fn_80309074(void * arg0);
void fn_80309534(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0);
void fn_80309698(void * arg0);
void fn_80309830(void * arg0);
void fn_8030992C(void * arg0);
void * fn_803099D0(void * arg0);
void fn_80309B18(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0);
void fn_80309D38(void *arg0, s32 arg1, f32 farg0);
void * fn_80309E98(void * arg0);
void fn_8030A248(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0);
void fn_8030A5BC(void * arg0);
void fn_8030A6B8(void * arg0);
void * fn_8030A75C(void * arg0, void *** arg1);
void ** fn_8030AA6C(void *arg0);
void fn_8030AB3C(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0);
void fn_8030B1F8(void * arg0);
void fn_8030B2F4(void * arg0);
void * fn_8030B398(void * arg0);
void ** fn_8030BA78(void *arg0, s16 arg1);
void fn_8030BB24(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0);
void fn_8030C334(void * arg0);
void fn_8030C430(void * arg0);
void ** fn_8030C4D4(void *arg0, s16 arg1);
s32 fn_8030C718(void);
s32 fn_8030C720(void);
s32 fn_8030C728(void);
s32 fn_8030C730(void *arg0, f32 farg0);
void fn_8030C79C(void *arg0);
void ** fn_8030C7C0(void *arg0, void ** arg1);
void fn_8030C868(void *arg0);
void ** fn_8030C8B0(void *arg0, s16 arg1);
s32 fn_8030CA54(void);
s32 fn_8030CA5C(void);
s32 fn_8030CA64(void *arg0, f32 farg0);
void ** fn_8030CAD0(void *arg0, s16 arg1);
s32 fn_8030CCF8(void);
s32 fn_8030CD00(void);
s32 fn_8030CD08(void);
s32 fn_8030CD10(void *arg0);
void ** fn_8030CDB0(void *arg0, s16 arg1);
s32 fn_8030CEF0(void);
s32 fn_8030CEF8(void);
s32 fn_8030CF00(void);
s32 fn_8030CF08(void *arg0, f32 farg0);
f32 fn_8030CF74(void);
f32 fn_8030CF98(void);
void ** fn_8030CFBC(void *arg0, s16 arg1);
s32 fn_8030D210(void);
s32 fn_8030D218(void);
s32 fn_8030D220(void);
s32 fn_8030D228(void);
s32 fn_8030D230(void);
s32 fn_8030D238(void *arg0, f32 farg0);
f32 fn_8030D2A4(void);
void fn_8030D2C8(void);
void ** fn_8030D2CC(void *arg0, s16 arg1);
s32 fn_8030D48C(void);
s32 fn_8030D494(void);
s32 fn_8030D49C(void *arg0, f32 farg0);
void fn_8030D508(void *arg0);
void * fn_8030D510(void);
void fn_8030D51C(f32 * arg0);
void * fn_8030D918(void * arg0, s32 arg_sp0);
void fn_8030F084(void * arg0, void *arg1, s32 arg_sp0);
void * fn_8030F318(void * arg0, s32 arg2, s32 arg_sp0);
void * fn_8030FCB4(void * arg0, void * arg2, s32 arg3, s32 arg_sp0);
void * fn_80310364(void * arg0, void * arg2, s32 arg3, s32 arg_sp0);
void * fn_80310758(void * arg0, void * arg2, s32 arg3, s32 arg_sp0);
void * fn_80310934(void * arg0, void * arg2, s32 arg3);
void * fn_80310E10(void * arg0);
void fn_803110BC(void * arg0, s32 arg1, s32 arg2, s32 arg3);
void * fn_80311170(void * arg0);
void fn_80311438(void * arg0, s32 arg1, s32 arg2, s32 arg3);
void * fn_803114FC(void * arg0, void * arg1);
void fn_80311A20(void * arg0);
void fn_80311CBC(s32 arg0);
void fn_80311CC4(s32 arg0);
void fn_80311CCC(s32 arg0);
void fn_80311CD4(s32 arg0);
void fn_80311CDC(s32 arg0);
void fn_80311CE4(s32 arg0);
void fn_80311CEC(s32 arg0);
void fn_80311CF4(s32 arg0);
void fn_80311CFC(s32 arg0);
void fn_80311D04(void * arg0, f32 * arg1, f32 * arg2, u8 arg3);
u16 fn_80311DB0(u8 arg0, f64 farg0, f32 farg1);
void fn_80311EA0(s16 arg0, f32 * arg1, f32 * arg2, u8 * arg3);
void fn_80311F2C(void * arg0);
void fn_80311F88(s32 * arg0, f32 farg0, f32 farg1);
s32 fn_80312000(s32 * arg0, s32 arg_sp0);
f32 fn_803120C0(s32 * arg0);
void kar_diag__803121ec(void *arg0, u16 * arg1, u32 arg2, u16 * arg3, s32 arg_sp0);
struct _struct_lbl_804E02D0_0x20 * fn_803124F0(void);
struct _struct_lbl_804E02D0_0x20 * fn_80312544(s32 arg0);
void fn_80312558(void);
s32 fn_80312650(s32 arg0);
s32 fn_80312668(s32 arg0);
s32 fn_80312680(s32 arg0);
s32 fn_80312698(void);
s32 fn_803126A0(s32 arg0);
s32 fn_803126B4(s32 arg0);
void ** fn_803126CC(void *arg0, void * arg1, s32 arg_sp0);
void ** fn_80312D4C(void *arg0, s16 arg1);
void fn_80312E50(void *arg0, s32 arg1);
s32 fn_80312ECC(void * arg0);
s32 fn_80312EF4(void * arg0);
s32 fn_80312F1C(void * arg0);
s32 fn_80312F44(void * arg0);
s32 fn_80312F6C(void * arg0);
s32 fn_80312F94(void * arg0);
void * fn_80312FBC(void * arg0, void * arg1);
void fn_80313140(void *arg1, void * arg2, f32 farg0, f32 farg1);
void ** fn_80313270(void *arg0, s16 arg1);
s32 fn_803132CC(void * arg1);
void ** fn_80313354(void *arg0, u32 arg1, s32 arg2, void * arg3, void * arg4, s32 arg5, s8 arg6, s32 arg_sp0);
void ** fn_80313A20(void *arg0, s16 arg1);
void ** fn_80313A84(void *arg0);
void fn_80313AC4(void * arg0, void * arg1, void * arg2, s32 arg_sp0);
void fn_80314068(void * arg0, void ** arg1);
void fn_803140A0(void * arg0, void ** arg1);
void fn_803140D8(void ** arg0, void ** arg1, void ** arg2);
void * fn_803140EC(void * arg0);
void ** fn_80314100(void *arg0, s16 arg1);
void ** fn_80314150(void *arg0, s16 arg1);
void ** fn_80314398(void *arg0, s16 arg1);
void fn_8031447C(void * arg0, s32 arg_sp0);
void fn_8031471C(void * arg0);
void fn_803147C4(void * arg0);
void * fn_8031483C(void * arg0, s32 arg1, void *arg2, f32 * arg3, f32 farg0);
void fn_80314934(void * arg0);
void * fn_803149E4(void * arg0, s32 arg1, void * arg2, u8 arg3, f32 farg0);
void fn_80314B6C(void * arg0, void * arg1, u8 arg2);
f32 fn_80314E54(f32 farg0);
f32 fn_803152B0(f32 farg0);
void * fn_803156FC(void * arg0, void *arg1, f32 * arg2, u8 arg3, u8 arg4, u8 arg5, f32 farg0);
s32 fn_803158A8(void * arg1);
void ** fn_803159AC(void *arg0, s16 arg1);
s32 fn_803159FC(void * arg1);
s32 fn_80315AB0(void);
void fn_80315AB8(void * arg1);
s32 fn_80315AF0(void * arg1);
s32 fn_80315B34(void * arg1);
s32 fn_80315BC0(void * arg1);
s32 fn_80315C04(void);
void kar_diag__80315c0c(void * arg0, void * arg1, u32 arg2, void *arg3, s32 arg_sp0);
void ** fn_80316128(void *arg0, s16 arg1);
void ** fn_80316188(void *arg0, s16 arg1);
void fn_803161E8(u32 * arg0);
void kar_diagnostic__80316220(void * arg0);
void ** kar_diagnostic__near_803162a0(void *arg0, s16 arg1);
void kar_diagnostic__80316300(void * arg0);
void ** kar_diagnostic__near_80316378(void *arg0, s16 arg1);
void ** kar_diagnostic__near_803163f8(void *arg0, s16 arg1);
void kar_diagnostic__80316458(void * arg0);
void kar_diagnostic__80316494(void *arg0);
void kar_diagnostic__near_80317018(void *arg1, void * arg2, f32 farg0, f32 farg1);
void kar_diagnostic__803170c8(void *arg0);
void ** kar_diagnostic__near_80317400(void *arg0, s16 arg1);
void kar_diagnostic__near_803174e4(void *arg0);
void kar_diagnostic__near_80317518(s32 arg0, void *arg1, s32 arg_sp0);
void ** kar_diagnostic__near_80317944(void *arg0, s16 arg1);
void ** kar_diagnostic__near_803179c8(void *arg0);
void ** kar_diagnostic__near_803179d0(void *arg0);
u32 kar_diagnostic__near_803179d8(void *arg0, void *arg1, void *arg2);
void kar_diagnostic__80317ce4(void *arg0, void *arg1);
void fn_80318E1C(void * arg0, s32 arg1, void * arg2, void * arg3);
s32 fn_80318F30(void * arg0, f32 * arg1, f32 * arg2, f32 * arg3, f32 * arg4);
void fn_80319440(void *arg0);
void fn_8031981C(void *arg1, void * arg2, void * arg3);
void fn_80319A44(void *arg1, void *arg2, void *arg3, s32 * arg_sp0);
void ** fn_80319BDC(void *arg0, f32 * arg1);
void ** fn_8031A74C(void *arg0, f32 farg0, f32 farg1);
u32 fn_8031B0FC(void *arg1);
u32 fn_8031B3C4(f32 farg1);
void fn_8031B474(f32 * arg0, f32 * arg1, s32 arg_sp0);
void kar_diag__8031b640(void *arg0, void * arg1, u32 arg2, f32 * arg3, s32 arg_sp0);
void kar_diag__8031bcdc(void *arg0, u32 arg1);
void ** kar_diagnostic__8031be7c(void *arg0, s16 arg1);
void ** kar_diagnostic__near_8031bedc(void *arg0, s16 arg1);
void kar_diagnostic__near_8031bf3c(f32 * arg0, f32 * arg1, f32 * arg2);
f32 * kar_diagnostic__near_8031bfdc(f32 * arg0, f32 * arg1, u8 * arg2);
f32 * kar_diagnostic__near_8031c144(f32 * arg0, f32 * arg1, u8 * arg2);
void kar_diagnostic__near_8031c2dc(f32 * arg0, f32 * arg1);
void kar_diagnostic__8031c358(void * arg0);
void kar_diagnostic__8031c3e0(u32 * arg0);
void fn_8031C418(void * arg0, void *arg1);
void fn_8031C664(void * arg0);
void ** fn_8031C7E8(void *arg0, s16 arg1);
void * fn_8031C844(void * arg0, s32 arg1, s32 arg2, s32 arg3);
void ** fn_8031CA7C(void *arg0, s16 arg1);
void fn_8031CB44(void * arg0);
void fn_8031CBE0(f32 * arg0);
void fn_8031CC00(void * arg0);
f32 fn_8031DA10(void);
void fn_8031DA18(void *arg0, s16 arg1, u32 arg2);
void fn_8031DA58(void *arg0);
void fn_8031DA78(void * arg0);
void ** fn_8031DB7C(void *arg0, s16 arg1);
void fn_8031DBC4(void * arg0);
void fn_8031DC48(void * arg0);
void fn_8031DD30(void * arg0);
void fn_8031DEAC(void * arg0, s32 arg1);
void fn_8031DF54(void * arg0);
void ** fn_8031DFFC(void *arg0, u8 arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg_sp8);
void ** fn_8031E508(void *arg0, s16 arg1);
void fn_8031E558(void * arg0, void * arg1);
void fn_8031E824(void * arg0, s32 arg1);
void ** fn_8031EA08(void *arg0, s16 arg1);
void ** fn_8031EAF8(void *arg0, s16 arg1);
void fn_8031EBB8(void);
void fn_8031EBBC(void * arg0);
void * fn_8031F0B0(void * arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void fn_8031F410(void * arg0);
void fn_8031F4BC(void * arg0, f32 farg0);
void fn_8031F4C4(void * arg0);
void fn_8031F52C(void * arg0);
void fn_8031F758(void * arg0);
void fn_80320204(void);
}

extern "C" void kar_a2d_kirbyjointanim__802efa2c(void * arg0, void * arg1, void * arg2, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)farg0;
}

extern "C" void kar_a2d_kirbyjointanim__near_802efd8c(void *arg0, void *arg1, void * arg2, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)farg0;
}

extern "C" void fn_802EFE1C(void * arg0) {
    (void)arg0;
}

#pragma dont_inline on
extern "C" void kar_a2d_kirbyjointanim__near_802efe44(void * arg0) {
    FU32(arg0, 0x0) = 0;
}
#pragma dont_inline off

#pragma dont_inline on
extern "C" void kar_a2d_kirbyjointanim__near_802effb8(void * arg0, void * arg1, u32 arg2) {
    (void)arg1;
    (void)arg2;
    FU32(arg0, 0x0) = 0;
}
#pragma dont_inline off

extern "C" void kar_a2d_kirbyjointanim__near_802f0148(void * arg0, u32 arg1, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)farg0;
}

extern "C" void * kar_a2d_kirbyjointanim__near_802f0268(void * arg0, s32 arg1, s32 arg_sp0) {
    (void)arg0;
    (void)arg1;
    (void)arg_sp0;
    return 0;
}

extern "C" void * kar_a2d_kirbyjointanim__near_802f0944(void * arg0, void ** arg1, s32 arg_sp0) {
    (void)arg0;
    (void)arg1;
    (void)arg_sp0;
    return 0;
}

extern "C" void kar_a2d_kirbyjointanim__near_802f0a20(void * arg0, u8 * arg1) {
    FU32(arg0, 0x0) = 0;
    void *addr4 = (char *) arg0 + 0x4;
    FU32(arg0, 0x4) = 0;
    u8 v = arg1[0];
    FU8(arg0, 0x8) = v;
    FP(arg0, 0xC) = addr4;
}

extern "C" void ** kar_diag__802f0a40(void * arg0, s32 arg1, u8 arg2, u8 arg3, void ** arg4, s32 arg_sp0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)arg4;
    (void)arg_sp0;
    return 0;
}

extern "C" void * kar_a2d_kirbyjointanim__near_802f0b60(void * arg0, s32 arg1, s32 arg2) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    return 0;
}

extern "C" void kar_a2d_kirbyjointanim__near_802f0cc0(void *arg0) {
    (void)arg0;
}

extern "C" void kar_a2d_kirbyjointanim__near_802f0d30(void * arg0, f32 * arg1, s32 arg2) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
}

extern "C" void kar_a2d_kirbyjointanim__near_802f10a4(void * arg0, u8 arg1, f32 * arg2) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
}

extern "C" void kar_a2d_kirbyjointanim__near_802f1188(void * arg0) {
    (void)arg0;
}

extern "C" void kar_a2d_kirbyjointanim__near_802f11c0(void * arg0, f32 * arg1, u8 arg2) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
}

extern "C" void fn_802F13E8(void * arg0, f32 * arg1) {
    (void)arg0;
    (void)arg1;
}

extern "C" void fn_802F1594(void * arg0, f32 * arg1) {
    (void)arg0;
    (void)arg1;
}

extern "C" void fn_802F16A0(void * arg0, void * arg1) {
    (void)arg0;
    (void)arg1;
}

extern "C" void fn_802F1828(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F1860(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F189C(void * arg0) {
    (void)arg0;
}

extern "C" void * fn_802F18D8(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" s32 fn_802F1F0C(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" s32 fn_802F2268(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_802F242C(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)farg0;
}

extern "C" void fn_802F2AC0(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F2D4C(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F3084(void * arg0) {
    if (FU32(FP(arg0, 0x4), 0x84) == 0 || (FU32(FP(arg0, 0x4), 0x84) & 1)) {
        FU32(FP(FP(arg0, 0x4), 0x474), 0x14) |= 0x10;
        ((VDispatch3 *) FP(FP(arg0, 0x4), 0x460))->v2();
        if (FU32(FP(arg0, 0x4), 0x78) < 0xE) {
            ((VDispatch3 *) FP(FP(arg0, 0x4), 0x540))->v2();
        }
    }
    ((VDispatch3 *) FP(FP(arg0, 0x4), 0x538))->v2();
}

extern "C" void * fn_802F3128(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void ** fn_802F32A0(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void fn_802F33B8(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)farg0;
}

extern "C" void fn_802F3534(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F37D8(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F38F0(void * arg0) {
    (void)arg0;
}

extern "C" void * fn_802F39A0(void * arg0, void * arg2) {
    (void)arg0;
    (void)arg2;
    return 0;
}

extern "C" void fn_802F3BD0(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F3CFC(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F3FE0(void * arg0) {
    (void)arg0;
}

extern "C" void ** fn_802F4068(void *arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_802F4380(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F4508(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F488C(void * arg0) {
    (void)arg0;
}

extern "C" void * fn_802F4A48(void * arg0, u32 arg2, void * arg3) {
    (void)arg0;
    (void)arg2;
    (void)arg3;
    return 0;
}

extern "C" void fn_802F4D0C(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F4E6C(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F52A0(void * arg0) {
    void *obj4 = FP(arg0, 4);
    HSD_JObj *jobj = (HSD_JObj *) FP(obj4, 0x464);
    HSD_JObjSetupMatrix(jobj);

    obj4 = FP(arg0, 4);
    HSD_JObj *jobj2 = (HSD_JObj *) FP(obj4, 0x464);
    void *th = FP(obj4, 0x4A8);
    Mtx *mtx = &jobj2->mtx;
    HSD_JObj *retrieved = fn_8038D0A8(th, 0);
    if (retrieved == NULL) {
        __assert(kar_srcfile_jobj_h_805d9800, 1173, lbl_805D9808);
    }
    if (mtx == NULL) {
        __assert(kar_srcfile_jobj_h_805d9800, 1174, lbl_805D9810);
    }
    PSMTXCopy(*mtx, retrieved->mtx);
    retrieved->flags |= (USER_DEF_MTX | MTX_INDEP_PARENT | MTX_INDEP_SRT);
    HSD_JObjSetMtxDirty(retrieved);

    obj4 = FP(arg0, 4);
    kar_a2d_kirbyjointanim__near_802efe44(FP(obj4, 0x4AC));
}

extern "C" void fn_802F53DC(void * arg0, u32 arg1, void * arg2) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
}

extern "C" f32 fn_802F5890(f32 farg0) {
    (void)farg0;
    return 0.0f;
}

extern "C" f32 fn_802F5CDC(f32 farg0) {
    (void)farg0;
    return 0.0f;
}

extern "C" void * fn_802F6138(void * arg0, u32 arg2, void * arg3, s16 arg4, s16 arg5) {
    (void)arg0;
    (void)arg2;
    (void)arg3;
    (void)arg4;
    (void)arg5;
    return 0;
}

extern "C" void fn_802F6540(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F66A0(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F6AEC(void * arg0) {
    HSD_JObj *jobj = (HSD_JObj *) FP(FP(arg0, 4), 0x464);
    HSD_JObjSetupMatrix(jobj);

    void *obj4 = FP(arg0, 4);
    HSD_JObj *jobj2 = (HSD_JObj *) FP(obj4, 0x464);
    void *th = FP(obj4, 0x4A8);
    Mtx *mtx = &jobj2->mtx;
    HSD_JObj *retrieved = fn_8038D0A8(th, 0);
    if (retrieved == NULL) {
        __assert(kar_srcfile_jobj_h_805d9800, 1173, lbl_805D9808);
    }
    if (mtx == NULL) {
        __assert(kar_srcfile_jobj_h_805d9800, 1174, lbl_805D9810);
    }
    PSMTXCopy(*mtx, retrieved->mtx);
    retrieved->flags |= (USER_DEF_MTX | MTX_INDEP_PARENT | MTX_INDEP_SRT);
    HSD_JObjSetMtxDirty(retrieved);

    obj4 = FP(arg0, 4);
    kar_a2d_kirbyjointanim__near_802efe44(FP(obj4, 0x4AC));
}

extern "C" void * fn_802F6C28(void * arg0, u32 arg2, void * arg3, s16 arg4, s16 arg5) {
    (void)arg0;
    (void)arg2;
    (void)arg3;
    (void)arg4;
    (void)arg5;
    return 0;
}

extern "C" void fn_802F7030(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F7190(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F75DC(void * arg0) {
    HSD_JObj *jobj = (HSD_JObj *) FP(FP(arg0, 4), 0x464);
    HSD_JObjSetupMatrix(jobj);

    void *obj4 = FP(arg0, 4);
    HSD_JObj *jobj2 = (HSD_JObj *) FP(obj4, 0x464);
    void *th = FP(obj4, 0x4A8);
    Mtx *mtx = &jobj2->mtx;
    HSD_JObj *retrieved = fn_8038D0A8(th, 0);
    if (retrieved == NULL) {
        __assert(kar_srcfile_jobj_h_805d9800, 1173, lbl_805D9808);
    }
    if (mtx == NULL) {
        __assert(kar_srcfile_jobj_h_805d9800, 1174, lbl_805D9810);
    }
    PSMTXCopy(*mtx, retrieved->mtx);
    retrieved->flags |= (USER_DEF_MTX | MTX_INDEP_PARENT | MTX_INDEP_SRT);
    HSD_JObjSetMtxDirty(retrieved);

    obj4 = FP(arg0, 4);
    kar_a2d_kirbyjointanim__near_802efe44(FP(obj4, 0x4AC));
}

extern "C" void * fn_802F7718(void * arg0, u16 arg2, void *arg3, s16 arg4) {
    (void)arg0;
    (void)arg2;
    (void)arg3;
    (void)arg4;
    return 0;
}

extern "C" void * fn_802F7B28(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void ** fn_802F7BF4(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void fn_802F7D54(void * arg0) {
    (void)arg0;
}

extern "C" void ** fn_802F7F24(void *arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_802F82F0(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F8450(void * arg0) {
    HSD_JObj *jobj = (HSD_JObj *) FP(FP(arg0, 4), 0x464);
    HSD_JObjSetupMatrix(jobj);

    void *obj4 = FP(arg0, 4);
    HSD_JObj *jobj2 = (HSD_JObj *) FP(obj4, 0x464);
    void *th = FP(obj4, 0x4A8);
    Mtx *mtx = &jobj2->mtx;
    HSD_JObj *retrieved = fn_8038D0A8(th, 0);
    if (retrieved == NULL) {
        __assert(kar_srcfile_jobj_h_805d9800, 1173, lbl_805D9808);
    }
    if (mtx == NULL) {
        __assert(kar_srcfile_jobj_h_805d9800, 1174, lbl_805D9810);
    }
    PSMTXCopy(*mtx, retrieved->mtx);
    retrieved->flags |= (USER_DEF_MTX | MTX_INDEP_PARENT | MTX_INDEP_SRT);
    HSD_JObjSetMtxDirty(retrieved);

    obj4 = FP(arg0, 4);
    kar_a2d_kirbyjointanim__near_802efe44(FP(obj4, 0x4AC));
}

extern "C" void * fn_802F858C(void * arg0, s32 arg2) {
    (void)arg0;
    (void)arg2;
    return 0;
}

extern "C" void fn_802F88DC(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F8920(void * arg0) {
    HSD_JObj *jobj = (HSD_JObj *) FP(FP(arg0, 4), 0x464);
    HSD_JObjSetupMatrix(jobj);

    void *obj4 = FP(arg0, 4);
    HSD_JObj *jobj2 = (HSD_JObj *) FP(obj4, 0x464);
    void *th = FP(obj4, 0x4A8);
    Mtx *mtx = &jobj2->mtx;
    HSD_JObj *retrieved = fn_8038D0A8(th, 0);
    if (retrieved == NULL) {
        __assert(kar_srcfile_jobj_h_805d9800, 1173, lbl_805D9808);
    }
    if (mtx == NULL) {
        __assert(kar_srcfile_jobj_h_805d9800, 1174, lbl_805D9810);
    }
    PSMTXCopy(*mtx, retrieved->mtx);
    retrieved->flags |= (USER_DEF_MTX | MTX_INDEP_PARENT | MTX_INDEP_SRT);
    HSD_JObjSetMtxDirty(retrieved);

    obj4 = FP(arg0, 4);
    kar_a2d_kirbyjointanim__near_802efe44(FP(obj4, 0x4AC));
}

extern "C" void * fn_802F8A5C(void * arg0, void * arg2, void * arg3, s16 arg4, s16 arg5) {
    (void)arg0;
    (void)arg2;
    (void)arg3;
    (void)arg4;
    (void)arg5;
    return 0;
}

extern "C" void fn_802F8DD8(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F90BC(void * arg0) {
    (void)arg0;
}

extern "C" void * fn_802F958C(void * arg0, u16 arg2, f32 * arg3, s16 arg4) {
    (void)arg0;
    (void)arg2;
    (void)arg3;
    (void)arg4;
    return 0;
}

extern "C" void fn_802F99B0(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802F9C34(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802FA030(void * arg0) {
    HSD_JObj *jobj = (HSD_JObj *) FP(FP(arg0, 4), 0x464);
    HSD_JObjSetupMatrix(jobj);

    void *obj4 = FP(arg0, 4);
    HSD_JObj *jobj2 = (HSD_JObj *) FP(obj4, 0x464);
    void *th = FP(obj4, 0x4A8);
    Mtx *mtx = &jobj2->mtx;
    HSD_JObj *retrieved = fn_8038D0A8(th, 0);
    if (retrieved == NULL) {
        __assert(kar_srcfile_jobj_h_805d9800, 1173, lbl_805D9808);
    }
    if (mtx == NULL) {
        __assert(kar_srcfile_jobj_h_805d9800, 1174, lbl_805D9810);
    }
    PSMTXCopy(*mtx, retrieved->mtx);
    retrieved->flags |= (USER_DEF_MTX | MTX_INDEP_PARENT | MTX_INDEP_SRT);
    HSD_JObjSetMtxDirty(retrieved);

    obj4 = FP(arg0, 4);
    kar_a2d_kirbyjointanim__near_802efe44(FP(obj4, 0x4AC));
}

extern "C" void ** fn_802FA16C(void *arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_802FA5B4(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802FA734(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802FA8A8(void * arg0) {
    HSD_JObj *jobj = (HSD_JObj *) FP(FP(arg0, 4), 0x464);
    HSD_JObjSetupMatrix(jobj);

    void *obj4 = FP(arg0, 4);
    HSD_JObj *jobj2 = (HSD_JObj *) FP(obj4, 0x464);
    void *th = FP(obj4, 0x4A8);
    Mtx *mtx = &jobj2->mtx;
    HSD_JObj *retrieved = fn_8038D0A8(th, 0);
    if (retrieved == NULL) {
        __assert(kar_srcfile_jobj_h_805d9800, 1173, lbl_805D9808);
    }
    if (mtx == NULL) {
        __assert(kar_srcfile_jobj_h_805d9800, 1174, lbl_805D9810);
    }
    PSMTXCopy(*mtx, retrieved->mtx);
    retrieved->flags |= (USER_DEF_MTX | MTX_INDEP_PARENT | MTX_INDEP_SRT);
    HSD_JObjSetMtxDirty(retrieved);

    obj4 = FP(arg0, 4);
    kar_a2d_kirbyjointanim__near_802efe44(FP(obj4, 0x4AC));
}

extern "C" void fn_802FA9E4(void * arg0) {
    if (FU32(FP(arg0, 0x4), 0x84) == 0 || (FU32(FP(arg0, 0x4), 0x84) & 1)) {
        FU32(FP(FP(arg0, 0x4), 0x474), 0x14) |= 0x10;
        ((VDispatch3 *) FP(FP(arg0, 0x4), 0x460))->v2();
        if (FU32(FP(arg0, 0x4), 0x78) < 0xE) {
            ((VDispatch3 *) FP(FP(arg0, 0x4), 0x540))->v2();
        }
    }
    ((VDispatch3 *) FP(FP(arg0, 0x4), 0x534))->v2();
}

extern "C" void * fn_802FAA88(void * arg0, u8 arg2) {
    (void)arg0;
    (void)arg2;
    return 0;
}

extern "C" void fn_802FAD0C(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802FAE80(void * arg0) {
    HSD_JObj *jobj = (HSD_JObj *) FP(FP(arg0, 4), 0x464);
    HSD_JObjSetupMatrix(jobj);

    void *obj4 = FP(arg0, 4);
    HSD_JObj *jobj2 = (HSD_JObj *) FP(obj4, 0x464);
    void *th = FP(obj4, 0x4A8);
    Mtx *mtx = &jobj2->mtx;
    HSD_JObj *retrieved = fn_8038D0A8(th, 0);
    if (retrieved == NULL) {
        __assert(kar_srcfile_jobj_h_805d9800, 1173, lbl_805D9808);
    }
    if (mtx == NULL) {
        __assert(kar_srcfile_jobj_h_805d9800, 1174, lbl_805D9810);
    }
    PSMTXCopy(*mtx, retrieved->mtx);
    retrieved->flags |= (USER_DEF_MTX | MTX_INDEP_PARENT | MTX_INDEP_SRT);
    HSD_JObjSetMtxDirty(retrieved);

    obj4 = FP(arg0, 4);
    kar_a2d_kirbyjointanim__near_802efe44(FP(obj4, 0x4AC));
}

extern "C" void fn_802FAFBC(void * arg0) {
    if (FU32(FP(arg0, 0x4), 0x84) == 0 || (FU32(FP(arg0, 0x4), 0x84) & 1)) {
        FU32(FP(FP(arg0, 0x4), 0x474), 0x14) |= 0x10;
        ((VDispatch3 *) FP(FP(arg0, 0x4), 0x460))->v2();
        if (FU32(FP(arg0, 0x4), 0x78) < 0xE) {
            ((VDispatch3 *) FP(FP(arg0, 0x4), 0x540))->v2();
        }
    }
    ((VDispatch3 *) FP(FP(arg0, 0x4), 0x544))->v2();
}

extern "C" void * fn_802FB060(void * arg0, void * arg2, void * arg3, s16 arg4, s16 arg5) {
    (void)arg0;
    (void)arg2;
    (void)arg3;
    (void)arg4;
    (void)arg5;
    return 0;
}

extern "C" void fn_802FB3A0(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802FB580(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802FBA00(void * arg0, s8 arg1) {
    (void)arg0;
    (void)arg1;
}

extern "C" void * fn_802FBAF0(void * arg0, void * arg2, void * arg3, s16 arg4) {
    (void)arg0;
    (void)arg2;
    (void)arg3;
    (void)arg4;
    return 0;
}

extern "C" void fn_802FBD44(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802FBEE4(void * arg0) {
    (void)arg0;
}

extern "C" void ** fn_802FC1BC(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_802FC31C(void) {
    return 15;
}

extern "C" s32 fn_802FC324(void) {
    return 1;
}

extern "C" s32 fn_802FC32C(void) {
    return 1;
}

extern "C" s32 fn_802FC334(void) {
    return 1;
}

extern "C" s32 fn_802FC33C(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void ** fn_802FC35C(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_802FC48C(void) {
    return 14;
}

extern "C" s32 fn_802FC494(void) {
    return 1;
}

extern "C" s32 fn_802FC49C(void) {
    return 1;
}

extern "C" s32 fn_802FC4A4(void) {
    return 0;
}

extern "C" void ** fn_802FC4AC(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_802FC60C(void) {
    return 13;
}

extern "C" s32 fn_802FC614(void) {
    return 1;
}

extern "C" s32 fn_802FC61C(void) {
    return 1;
}

extern "C" s32 fn_802FC624(void) {
    return 1;
}

extern "C" s32 fn_802FC62C(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void ** fn_802FC654(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_802FC784(void) {
    return 12;
}

extern "C" s32 fn_802FC78C(void) {
    return 0;
}

extern "C" s32 fn_802FC794(void) {
    return 1;
}

extern "C" s32 fn_802FC79C(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void ** fn_802FC7F8(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_802FC98C(void) {
    return 11;
}

extern "C" void fn_802FC994(void ** arg0) {
    (void)arg0;
}

extern "C" s32 fn_802FC9D4(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void ** fn_802FCAD4(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_802FCC7C(void) {
    return 10;
}

extern "C" void fn_802FCC84(void * arg0) {
    (void)arg0;
}

extern "C" s32 fn_802FCDB0(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void ** fn_802FCE0C(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_802FCFB4(void) {
    return 9;
}

extern "C" s32 fn_802FCFBC(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" s32 fn_802FCFE4(void) {
    return 1;
}

extern "C" void ** fn_802FCFEC(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_802FD194(void) {
    return 8;
}

extern "C" s32 fn_802FD19C(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void ** fn_802FD1C0(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_802FD3A4(void) {
    return 7;
}

extern "C" void fn_802FD3AC(void ** arg0) {
    (void)arg0;
}

extern "C" s32 fn_802FD3EC(void * arg0) {
    void *p = FP(arg0, 0x4);
    if ((f64) FU32(p, 0x58) >= FF32(arg0, 0x38)) {
        FU32(p, 0x7C) = 0;
        return 1;
    }
    return 0;
}

extern "C" s32 fn_802FD43C(void) {
    return 6;
}

extern "C" s32 fn_802FD444(void) {
    return 1;
}

extern "C" s32 fn_802FD44C(void * arg0) {
    void *p = FP(arg0, 0x4);
    if ((f64) FU32(p, 0x58) >= FF32(arg0, 0x38)) {
        FU32(p, 0x7C) = 0;
        return 1;
    }
    return 0;
}

extern "C" void fn_802FD49C(void * arg0) {
    (void)arg0;
}

extern "C" void ** fn_802FD5B0(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void ** fn_802FD76C(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_802FD8E0(void) {
    return 5;
}

extern "C" f32 fn_802FD8E8(void) {
    return FF32(fn_802DE0E4(), 0x2114);
}

extern "C" f32 fn_802FD90C(void * arg0) {
    (void)arg0;
    return 0.0f;
}

extern "C" s32 fn_802FDA94(void * arg0) {
    void *p = FP(arg0, 0x4);
    if ((f64) FU32(p, 0x58) >= FF32(arg0, 0x38)) {
        FU32(p, 0x7C) = 0;
        return 1;
    }
    return 0;
}

extern "C" void ** fn_802FDAE4(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_802FDC58(void) {
    return 4;
}

extern "C" f32 fn_802FDC60(void) {
    return FF32(fn_802DE0E4(), 0x2114);
}

extern "C" f32 fn_802FDC84(void * arg0) {
    (void)arg0;
    return 0.0f;
}

extern "C" s32 fn_802FDE0C(void * arg0) {
    void *p = FP(arg0, 0x4);
    if ((f64) FU32(p, 0x58) >= FF32(arg0, 0x38)) {
        FU32(p, 0x7C) = 0;
        return 1;
    }
    return 0;
}

extern "C" void ** fn_802FDE5C(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_802FDFD0(void) {
    return 3;
}

extern "C" f32 fn_802FDFD8(void) {
    return FF32(fn_802DE0E4(), 0x2114);
}

extern "C" f32 fn_802FDFFC(void * arg0) {
    (void)arg0;
    return 0.0f;
}

extern "C" s32 fn_802FE184(void * arg0) {
    void *p = FP(arg0, 0x4);
    if ((f64) FU32(p, 0x58) >= FF32(arg0, 0x34)) {
        FU32(p, 0x7C) = 0;
        return 1;
    }
    return 0;
}

extern "C" s32 fn_802FE1D4(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void ** fn_802FE1F4(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_802FE340(void) {
    return 2;
}

extern "C" s32 fn_802FE348(void) {
    return 1;
}

extern "C" s32 fn_802FE350(void * arg0) {
    void *p = FP(arg0, 0x4);
    if ((f64) FU32(p, 0x58) >= FF32(arg0, 0x38)) {
        FU32(p, 0x7C) = 0;
        return 1;
    }
    return 0;
}

extern "C" void fn_802FE3A0(void) {

}

extern "C" f32 fn_802FE3A4(void) {
    return lbl_805E3AD0;
}

extern "C" s32 fn_802FE3AC(void) {
    return 16;
}

extern "C" s32 fn_802FE3B4(void) {
    return 1;
}

extern "C" s32 fn_802FE3BC(void) {
    return 1;
}

extern "C" s32 fn_802FE3C4(void) {
    return 1;
}

extern "C" s32 fn_802FE3CC(void) {
    return 1;
}

extern "C" s32 fn_802FE3D4(void) {
    return 0;
}

extern "C" s32 fn_802FE3DC(void) {
    return 0;
}

extern "C" s32 fn_802FE3E4(void) {
    return 0;
}

extern "C" s32 fn_802FE3EC(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_802FE448(void) {

}

extern "C" void ** fn_802FE44C(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_802FE5E4(void) {
    return 1;
}

extern "C" s32 fn_802FE5EC(void) {
    return 1;
}

extern "C" s32 fn_802FE5F4(void) {
    return 1;
}

extern "C" s32 fn_802FE5FC(void) {
    return 1;
}

extern "C" s32 fn_802FE604(void) {
    return 0;
}

extern "C" s32 fn_802FE60C(void) {
    return 1;
}

extern "C" s32 fn_802FE614(void ** arg0) {
    (void)arg0;
    return 0;
}

extern "C" s32 fn_802FE64C(void) {
    return 1;
}

extern "C" f32 fn_802FE654(void * arg0) {
    if (FU8(arg0, 0xC) != 0) {
        return -FF32(arg0, 0x8);
    }
    return FF32(arg0, 0x8);
}

extern "C" void fn_802FE674(f32 * arg0, void * arg1, f32 * arg2, f32 * arg3, f32 * arg4, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)arg4;
    (void)farg0;
}

extern "C" void * fn_802FE890(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void ** fn_802FEBB0(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void ** fn_802FEC4C(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void fn_802FECB4(void *arg0) {
    ((VDispatch16 *) arg0)->v4();
}

extern "C" void fn_802FECE0(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)farg0;
}

extern "C" void fn_802FED78(void * arg0) {
    (void)arg0;
}

extern "C" void fn_802FEEC4(void * arg0) {
    if (FU32(FP(arg0, 0x4), 0x84) == 0 || (FU32(FP(arg0, 0x4), 0x84) & 1)) {
        FU32(FP(FP(arg0, 0x4), 0x474), 0x14) |= 0x10;
        ((VDispatch3 *) FP(FP(arg0, 0x4), 0x460))->v2();
        if (FU32(FP(arg0, 0x4), 0x78) < 0xE) {
            ((VDispatch3 *) FP(FP(arg0, 0x4), 0x540))->v2();
        }
    }
    ((VDispatch3 *) FP(FP(arg0, 0x4), 0x4F8))->v2();
}

extern "C" void fn_802FEF68(void * arg0) {
    (void)arg0;
}

extern "C" f32 fn_802FF540(f32 farg0) {
    (void)farg0;
    return 0.0f;
}

extern "C" void * fn_802FF98C(void * arg0, void * arg2, void * arg3, s32 arg_sp0) {
    (void)arg0;
    (void)arg2;
    (void)arg3;
    (void)arg_sp0;
    return 0;
}

extern "C" void ** fn_802FFFFC(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void fn_803000BC(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)farg0;
}

extern "C" void fn_80300180(void * arg0) {
    (void)arg0;
}

extern "C" void fn_80300804(void * arg0) {
    if (FU32(FP(arg0, 0x4), 0x84) == 0 || (FU32(FP(arg0, 0x4), 0x84) & 1)) {
        FU32(FP(FP(arg0, 0x4), 0x474), 0x14) |= 0x10;
        ((VDispatch3 *) FP(FP(arg0, 0x4), 0x460))->v2();
        if (FU32(FP(arg0, 0x4), 0x78) < 0xE) {
            ((VDispatch3 *) FP(FP(arg0, 0x4), 0x540))->v2();
        }
    }
    ((VDispatch3 *) FP(FP(arg0, 0x4), 0x4FC))->v2();
}

extern "C" void * fn_803008A8(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_80300A80(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)farg0;
}

extern "C" void fn_80300BC8(void * arg0) {
    (void)arg0;
}

extern "C" void fn_80300D14(void * arg0) {
    if (FU32(FP(arg0, 0x4), 0x84) == 0 || (FU32(FP(arg0, 0x4), 0x84) & 1)) {
        FU32(FP(FP(arg0, 0x4), 0x474), 0x14) |= 0x10;
        ((VDispatch3 *) FP(FP(arg0, 0x4), 0x460))->v2();
        if (FU32(FP(arg0, 0x4), 0x78) < 0xE) {
            ((VDispatch3 *) FP(FP(arg0, 0x4), 0x540))->v2();
        }
    }
    ((VDispatch3 *) FP(FP(arg0, 0x4), 0x514))->v2();
}

extern "C" void * fn_80300DB8(void * arg0, void *** arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void fn_803011A0(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)farg0;
}

extern "C" void fn_803016C0(void * arg0) {
    (void)arg0;
}

extern "C" void fn_80301A64(void * arg0) {
    if (FU32(FP(arg0, 0x4), 0x84) == 0 || (FU32(FP(arg0, 0x4), 0x84) & 1)) {
        FU32(FP(FP(arg0, 0x4), 0x474), 0x14) |= 0x10;
        ((VDispatch3 *) FP(FP(arg0, 0x4), 0x460))->v2();
        if (FU32(FP(arg0, 0x4), 0x78) < 0xE) {
            ((VDispatch3 *) FP(FP(arg0, 0x4), 0x540))->v2();
        }
    }
    ((VDispatch3 *) FP(FP(arg0, 0x4), 0x500))->v2();
}

extern "C" void * fn_80301B08(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_80301CC8(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)farg0;
}

extern "C" void fn_80301DCC(f32 * arg0) {
    (void)arg0;
}

extern "C" void fn_80301E34(void * arg0) {
    (void)arg0;
}

extern "C" void fn_803020A4(void * arg0) {
    if (FU32(FP(arg0, 0x4), 0x84) == 0 || (FU32(FP(arg0, 0x4), 0x84) & 1)) {
        FU32(FP(FP(arg0, 0x4), 0x474), 0x14) |= 0x10;
        ((VDispatch3 *) FP(FP(arg0, 0x4), 0x460))->v2();
        if (FU32(FP(arg0, 0x4), 0x78) < 0xE) {
            ((VDispatch3 *) FP(FP(arg0, 0x4), 0x540))->v2();
        }
    }
    ((VDispatch3 *) FP(FP(arg0, 0x4), 0x520))->v2();
}

extern "C" void * fn_80302148(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_80302398(void * arg0, void *arg2) {
    (void)arg0;
    (void)arg2;
}

extern "C" void fn_80302440(void *arg0) {
    (void)arg0;
}

extern "C" void fn_803024A8(void * arg0) {
    (void)arg0;
}

extern "C" void fn_80302C60(void * arg0) {
    if (FU32(FP(arg0, 0x4), 0x84) == 0 || (FU32(FP(arg0, 0x4), 0x84) & 1)) {
        FU32(FP(FP(arg0, 0x4), 0x474), 0x14) |= 0x10;
        ((VDispatch3 *) FP(FP(arg0, 0x4), 0x460))->v2();
        if (FU32(FP(arg0, 0x4), 0x78) < 0xE) {
            ((VDispatch3 *) FP(FP(arg0, 0x4), 0x540))->v2();
        }
    }
    ((VDispatch3 *) FP(FP(arg0, 0x4), 0x50C))->v2();
}

extern "C" void * fn_80302D04(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_80302F90(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)farg0;
}

extern "C" void fn_803032B0(void * arg0) {
    (void)arg0;
}

extern "C" void fn_803033FC(void * arg0) {
    if (FU32(FP(arg0, 0x4), 0x84) == 0 || (FU32(FP(arg0, 0x4), 0x84) & 1)) {
        FU32(FP(FP(arg0, 0x4), 0x474), 0x14) |= 0x10;
        ((VDispatch3 *) FP(FP(arg0, 0x4), 0x460))->v2();
        if (FU32(FP(arg0, 0x4), 0x78) < 0xE) {
            ((VDispatch3 *) FP(FP(arg0, 0x4), 0x540))->v2();
        }
    }
    ((VDispatch3 *) FP(FP(arg0, 0x4), 0x508))->v2();
}

extern "C" void * fn_803034A0(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_80303678(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)farg0;
}

extern "C" void fn_803038F8(void * arg0) {
    (void)arg0;
}

extern "C" void fn_803039F4(void * arg0) {
    if (FU32(FP(arg0, 0x4), 0x84) == 0 || (FU32(FP(arg0, 0x4), 0x84) & 1)) {
        FU32(FP(FP(arg0, 0x4), 0x474), 0x14) |= 0x10;
        ((VDispatch3 *) FP(FP(arg0, 0x4), 0x460))->v2();
        if (FU32(FP(arg0, 0x4), 0x78) < 0xE) {
            ((VDispatch3 *) FP(FP(arg0, 0x4), 0x540))->v2();
        }
    }
    ((VDispatch3 *) FP(FP(arg0, 0x4), 0x528))->v2();
}

extern "C" void * fn_80303A98(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_80303D64(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)farg0;
}

extern "C" f32 fn_80304248(f32 farg0) {
    (void)farg0;
    return 0.0f;
}

extern "C" void fn_803046A4(void * arg0) {
    (void)arg0;
}

extern "C" void fn_8030481C(void * arg0) {
    (void)arg0;
}

extern "C" void ** fn_803048E0(KJPartWithEffect10 *arg0, s16 arg1) {
    if (arg0 == NULL) {
        goto skip_all;
    }
    FP(arg0, 0) = lbl_804DB088;
    {
        void *obj4 = FP(arg0, 4);
        HSD_JObjSetFlagsAll((HSD_JObj *) FP(obj4, 0xBC4), 0x10);
        FU8(obj4, 0xBC8) = 0;
        FU32(obj4, 0xBCC) = 2;
        FF32(obj4, 0xBD8) = lbl_805E3BC0;
        FF32(obj4, 0xBD4) = lbl_805E3BC0;
        FF32(obj4, 0xBD0) = lbl_805E3BC0;
        FU32(obj4, 0xBDC) = 0;
    }
    if (&arg0->effect == NULL) {
        goto skip_effect;
    }
    *(void **) &arg0->effect = lbl_804BDF70;
    kar_a2d_effecthandle__near_8037b33c(&arg0->effect, 0);
    if (&arg0->effect == NULL) {
        goto skip_effect;
    }
    *(void **) &arg0->effect = lbl_804BDF2C;
    arg0->effect.v1c();
skip_effect:
    if (arg0 == NULL) {
        goto skip2;
    }
    FP(arg0, 0) = lbl_804D6F5C;
    kar_a2d_kirbyjointanim__near_802effb8(FP(FP(arg0, 4), 0x4AC), lbl_804DAAB4, 0);
    if (arg0 == NULL) {
        goto skip2;
    }
    FP(arg0, 0) = lbl_804D1A98;
skip2:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
skip_all:
    return (void **) arg0;
}

extern "C" s32 fn_803049FC(void) {
    return 25;
}

extern "C" s32 fn_80304A04(void) {
    return 1;
}

extern "C" s32 fn_80304A0C(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void ** fn_80304A68(KJPartWithEffect *arg0, s16 arg1) {
    if (arg0 == NULL) {
        goto skip_all;
    }
    FP(arg0, 0) = lbl_804DB188;
    if (&arg0->effect == NULL) {
        goto skip_effect;
    }
    *(void **) &arg0->effect = lbl_804BDF70;
    kar_a2d_effecthandle__near_8037b33c(&arg0->effect, 0);
    if (&arg0->effect == NULL) {
        goto skip_effect;
    }
    *(void **) &arg0->effect = lbl_804BDF2C;
    arg0->effect.v1c();
skip_effect:
    if (arg0 == NULL) {
        goto skip2;
    }
    FP(arg0, 0) = lbl_804D6F5C;
    kar_a2d_kirbyjointanim__near_802effb8(FP(FP(arg0, 4), 0x4AC), lbl_804DAAB4, 0);
    if (arg0 == NULL) {
        goto skip2;
    }
    FP(arg0, 0) = lbl_804D1A98;
skip2:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
skip_all:
    return (void **) arg0;
}

extern "C" s32 fn_80304B48(void) {
    return 24;
}

extern "C" s32 fn_80304B50(void) {
    return 1;
}

extern "C" s32 fn_80304B58(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" s32 fn_80304B68(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void ** fn_80304BC0(KJPartWithEffect18 *arg0, s16 arg1) {
    if (arg0 == NULL) {
        goto skip_all;
    }
    FP(arg0, 0) = lbl_804DB288;
    FU32(FP(arg0, 4), 0x90) += 1;
    if (&arg0->effect == NULL) {
        goto skip_effect;
    }
    *(void **) &arg0->effect = lbl_804BDF70;
    kar_a2d_effecthandle__near_8037b33c(&arg0->effect, 0);
    if (&arg0->effect == NULL) {
        goto skip_effect;
    }
    *(void **) &arg0->effect = lbl_804BDF2C;
    arg0->effect.v1c();
skip_effect:
    if (arg0 == NULL) {
        goto skip2;
    }
    FP(arg0, 0) = lbl_804D6F5C;
    kar_a2d_kirbyjointanim__near_802effb8(FP(FP(arg0, 4), 0x4AC), lbl_804DAAB4, 0);
    if (arg0 == NULL) {
        goto skip2;
    }
    FP(arg0, 0) = lbl_804D1A98;
skip2:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
skip_all:
    return (void **) arg0;
}

extern "C" s32 fn_80304CB0(void) {
    return 23;
}

extern "C" s32 fn_80304CB8(void) {
    return 1;
}

extern "C" s32 fn_80304CC0(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" s32 fn_80304CD0(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void ** fn_80304D18(void *arg0, s16 arg1) {
    if (arg0 == NULL) {
        goto skip_all;
    }
    FP(arg0, 0) = lbl_804DB4D4;
    if (arg0 == NULL) {
        goto skip2;
    }
    FP(arg0, 0) = lbl_804D6F5C;
    kar_a2d_kirbyjointanim__near_802effb8(FP(FP(arg0, 4), 0x4AC), lbl_804DAAB4, 0);
    if (arg0 == NULL) {
        goto skip2;
    }
    FP(arg0, 0) = lbl_804D1A98;
skip2:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
skip_all:
    return (void **) arg0;
}

extern "C" s32 fn_80304DAC(void) {
    return 22;
}

extern "C" s32 fn_80304DB4(void) {
    return 1;
}

extern "C" s32 fn_80304DBC(void * arg0) {
    u32 x = FU32(arg0, 0x8);
    return ((u32) (-(s32) x | x)) >> 31;
}

extern "C" void ** fn_80304DD0(void *arg0, s16 arg1) {
    if (arg0 == NULL) {
        goto skip_all;
    }
    FP(arg0, 0) = lbl_804DB7B8;
    if (arg0 == NULL) {
        goto skip2;
    }
    FP(arg0, 0) = lbl_804D6F5C;
    kar_a2d_kirbyjointanim__near_802effb8(FP(FP(arg0, 4), 0x4AC), lbl_804DAAB4, 0);
    if (arg0 == NULL) {
        goto skip2;
    }
    FP(arg0, 0) = lbl_804D1A98;
skip2:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
skip_all:
    return (void **) arg0;
}

extern "C" s32 fn_80304E64(void) {
    return 21;
}

extern "C" s32 fn_80304E6C(void) {
    return 1;
}

extern "C" s32 fn_80304E74(void * arg0) {
    u32 x = FU32(arg0, 0x8);
    return ((u32) (-(s32) x | x)) >> 31;
}

extern "C" void ** fn_80304E88(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_80305060(void) {
    return 20;
}

extern "C" s32 fn_80305068(void * arg0) {
    u32 x = FU32(arg0, 0xC);
    return ((u32) (-(s32) x | x)) >> 31;
}

extern "C" s32 fn_8030507C(void * arg0) {
    u32 x = FU32(arg0, 0xC);
    return ((u32) (-(s32) x | x)) >> 31;
}

extern "C" s32 fn_80305090(void) {
    return 1;
}

extern "C" s32 fn_80305098(void * arg0) {
    u32 x = FU32(arg0, 0xC);
    return ((u32) (-(s32) x | x)) >> 31;
}

extern "C" u8 fn_803050AC(void * arg0) {
    return FU8(arg0, 0x11);
}

extern "C" s32 fn_803050B4(void * arg0) {
    u32 x = FU32(arg0, 0xC);
    return ((u32) (-(s32) x | x)) >> 31;
}

extern "C" void fn_803050C8(void ** arg0) {
    ((VDispatch16 *) arg0)->v15();
}

extern "C" s32 fn_803050F4(void * arg0) {
    u32 x = FU32(arg0, 0xC);
    return ((u32) (-(s32) x | x)) >> 31;
}

extern "C" s32 fn_80305108(void *arg0) {
    (void)arg0;
    return 0;
}

extern "C" f32 fn_80305190(void) {
    return FF32(TopRideItem_GetDataBase(), 0x134);
}

extern "C" f32 fn_803051B4(void) {
    return FF32(TopRideItem_GetDataBase(), 0x138);
}

extern "C" f32 fn_803051D8(void * arg0) {
    if (FU8(arg0, 0x10) != 0) {
        return FF32(arg0, 0x8);
    }
    return -FF32(arg0, 0x8);
}

extern "C" void ** fn_803051F8(KJPartWithEffect8 *arg0, s16 arg1) {
    if (arg0 == NULL) {
        goto skip_all;
    }
    FP(arg0, 0) = lbl_804DB9C4;
    {
        void *obj4 = FP(arg0, 4);
        HSD_JObjSetFlagsAll((HSD_JObj *) FP(obj4, 0xBC4), 0x10);
        FU8(obj4, 0xBC8) = 0;
        FU32(obj4, 0xBCC) = 2;
        FF32(obj4, 0xBD8) = lbl_805E3BC0;
        FF32(obj4, 0xBD4) = lbl_805E3BC0;
        FF32(obj4, 0xBD0) = lbl_805E3BC0;
        FU32(obj4, 0xBDC) = 0;
    }
    if (&arg0->effect == NULL) {
        goto skip_effect;
    }
    *(void **) &arg0->effect = lbl_804BDF70;
    kar_a2d_effecthandle__near_8037b33c(&arg0->effect, 0);
    if (&arg0->effect == NULL) {
        goto skip_effect;
    }
    *(void **) &arg0->effect = lbl_804BDF2C;
    arg0->effect.v1c();
skip_effect:
    if (arg0 == NULL) {
        goto skip2;
    }
    FP(arg0, 0) = lbl_804D6F5C;
    kar_a2d_kirbyjointanim__near_802effb8(FP(FP(arg0, 4), 0x4AC), lbl_804DAAB4, 0);
    if (arg0 == NULL) {
        goto skip2;
    }
    FP(arg0, 0) = lbl_804D1A98;
skip2:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
skip_all:
    return (void **) arg0;
}

extern "C" s32 fn_80305314(void) {
    return 19;
}

extern "C" s32 fn_8030531C(void) {
    return 1;
}

extern "C" s32 fn_80305324(void *arg0, f32 farg0) {
    fn_802E498C(arg0, (f32 *) ((char *) TopRideItem_GetDataBase() + 0x17C));
    return (f64) FU32(FP(arg0, 0x4), 0x58) >= farg0;
}

extern "C" f32 fn_80305390(void) {
    return FF32(TopRideItem_GetDataBase(), 0x190);
}

extern "C" u32 fn_803053B4(void) {
    return 0;
}

extern "C" f32 fn_803053DC(void) {
    return FF32(TopRideItem_GetDataBase(), 0x18C);
}

extern "C" void ** fn_80305400(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_80305654(void) {
    return 18;
}

extern "C" s32 fn_8030565C(void) {
    return 1;
}

extern "C" s32 fn_80305664(void *arg0) {
    (void)arg0;
    return 0;
}

extern "C" s32 fn_803056EC(void) {
    return 0;
}

extern "C" s32 fn_803056F4(void) {
    return 1;
}

extern "C" f32 fn_803056FC(void) {
    return FF32(TopRideItem_GetDataBase(), 0xFC);
}

extern "C" void ** fn_80305720(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_80305890(void) {
    return 17;
}

extern "C" s32 fn_80305898(void) {
    return 1;
}

extern "C" s32 fn_803058A0(void *arg0, f32 farg0) {
    fn_802E498C(arg0, (f32 *) ((char *) TopRideItem_GetDataBase() + 0xBC));
    return (f64) FU32(FP(arg0, 0x4), 0x58) >= farg0;
}

extern "C" f32 fn_8030590C(void) {
    return FF32(TopRideItem_GetDataBase(), 0xCC);
}

extern "C" void ** fn_80305930(void *arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_80305964(void *arg0) {
    (void)arg0;
}

extern "C" void fn_8030599C(void *arg0) {
    (void)arg0;
}

extern "C" void fn_803059D8(void *arg0) {
    (void)arg0;
}

extern "C" void fn_80305A54(void *arg0) {
    (void)arg0;
}

extern "C" void fn_80305A88(void *arg0) {
    (void)arg0;
}

extern "C" void fn_80305ABC(void *arg0, u32 arg1) {
    (void)arg0;
    (void)arg1;
}

extern "C" void fn_80305B38(s32 ** arg0, void * arg1, s32 *** arg2, void * arg3) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
}

extern "C" void fn_80305BEC(s32 ** arg0, void * arg1, s32 *** arg2, void * arg3) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
}

extern "C" s32 * fn_80305CA0(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" s32 * fn_80305CC8(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void * fn_80305CF0(void * arg0, void * arg1, void * arg2) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    return 0;
}

extern "C" void kar_diag__80305ec8(void * arg0, void * arg1, u32 arg2, void * arg3, s32 arg_sp0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)arg_sp0;
}

extern "C" void * fn_803065B8(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void * fn_8030668C(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_803067B4(void * arg0) {
    (void)arg0;
}

extern "C" void fn_803069B4(void * arg0) {
    (void)arg0;
}

extern "C" void fn_80306ACC(void * arg0) {
    (void)arg0;
}

extern "C" void fn_80306DDC(void * arg0) {
    if (FU32(FP(arg0, 0x4), 0x84) == 0 || (FU32(FP(arg0, 0x4), 0x84) & 1)) {
        FU32(FP(FP(arg0, 0x4), 0x474), 0x14) |= 0x10;
        ((VDispatch3 *) FP(FP(arg0, 0x4), 0x460))->v2();
        if (FU32(FP(arg0, 0x4), 0x78) < 0xE) {
            ((VDispatch3 *) FP(FP(arg0, 0x4), 0x540))->v2();
        }
    }
    ((VDispatch3 *) FP(FP(arg0, 0x4), 0x4B4))->v2();
}

extern "C" void * fn_80306E80(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_803070E4(void * arg0) {
    (void)arg0;
}

extern "C" void fn_80307244(void * arg0) {
    if (FU32(FP(arg0, 0x4), 0x84) == 0 || (FU32(FP(arg0, 0x4), 0x84) & 1)) {
        FU32(FP(FP(arg0, 0x4), 0x474), 0x14) |= 0x10;
        ((VDispatch3 *) FP(FP(arg0, 0x4), 0x460))->v2();
        if (FU32(FP(arg0, 0x4), 0x78) < 0xE) {
            ((VDispatch3 *) FP(FP(arg0, 0x4), 0x540))->v2();
        }
    }
    ((VDispatch3 *) FP(FP(arg0, 0x4), 0x548))->v2();
}

extern "C" void ** fn_803072E8(void *arg0, s16 arg1) {
    if (arg0 == NULL) {
        goto skip_all;
    }
    FP(arg0, 0) = lbl_804DC050;
    void *obj4 = FP(arg0, 4);
    HSD_JObjSetFlagsAll((HSD_JObj *) FP(obj4, 0xBC4), 0x10);
    FU8(obj4, 0xBC8) = 0;
    FU32(obj4, 0xBCC) = 2;
    FF32(obj4, 0xBD8) = lbl_805E3C98;
    FF32(obj4, 0xBD4) = lbl_805E3C98;
    FF32(obj4, 0xBD0) = lbl_805E3C98;
    FU32(obj4, 0xBDC) = 0;
    if (arg0 == NULL) {
        goto skip2;
    }
    FP(arg0, 0) = lbl_804D6F5C;
    kar_a2d_kirbyjointanim__near_802effb8(FP(FP(arg0, 4), 0x4AC), lbl_804DBF80, 0);
    if (arg0 == NULL) {
        goto skip2;
    }
    FP(arg0, 0) = lbl_804D1A98;
skip2:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
skip_all:
    return (void **) arg0;
}

extern "C" s32 fn_803073BC(void) {
    return 0;
}

extern "C" s32 fn_803073C4(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void ** fn_80307400(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_80307528(void) {
    return 26;
}

extern "C" s32 fn_80307530(void) {
    return 1;
}

extern "C" s32 fn_80307538(void) {
    return 1;
}

extern "C" s32 fn_80307540(void) {
    return 1;
}

extern "C" s32 fn_80307548(void) {
    return 0;
}

extern "C" void fn_80307550(void ** arg0) {
    ((VDispatch16 *) arg0)->v15();
}

extern "C" s32 fn_8030757C(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_8030759C(void) {

}

extern "C" void ** fn_803075A0(void *arg0, s16 arg1) {
    if (arg0 == NULL) {
        goto skip_all;
    }
    FP(arg0, 0) = lbl_804DC254;
    if (arg0 == NULL) {
        goto skip2;
    }
    FP(arg0, 0) = lbl_804D6F5C;
    kar_a2d_kirbyjointanim__near_802effb8(FP(FP(arg0, 4), 0x4AC), lbl_804DBF80, 0);
    if (arg0 == NULL) {
        goto skip2;
    }
    FP(arg0, 0) = lbl_804D1A98;
skip2:
    if (arg1 > 0) {
        fn_8038CB78(arg0);
    }
skip_all:
    return (void **) arg0;
}

extern "C" s32 fn_80307634(void) {
    return 0;
}

extern "C" s32 fn_8030763C(void) {
    return 1;
}

extern "C" void * fn_80307644(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_80307974(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)farg0;
}

extern "C" f32 fn_80308524(f32 farg0) {
    (void)farg0;
    return 0.0f;
}

extern "C" f32 fn_80308980(f32 farg0) {
    (void)farg0;
    return 0.0f;
}

extern "C" void fn_80308DCC(void * arg0) {
    (void)arg0;
}

extern "C" void fn_80308FD0(void * arg0) {
    if (FU32(FP(arg0, 0x4), 0x84) == 0 || (FU32(FP(arg0, 0x4), 0x84) & 1)) {
        FU32(FP(FP(arg0, 0x4), 0x474), 0x14) |= 0x10;
        ((VDispatch3 *) FP(FP(arg0, 0x4), 0x460))->v2();
        if (FU32(FP(arg0, 0x4), 0x78) < 0xE) {
            ((VDispatch3 *) FP(FP(arg0, 0x4), 0x540))->v2();
        }
    }
    ((VDispatch3 *) FP(FP(arg0, 0x4), 0x53C))->v2();
}

extern "C" void * fn_80309074(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_80309534(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)farg0;
}

extern "C" void fn_80309698(void * arg0) {
    (void)arg0;
}

extern "C" void fn_80309830(void * arg0) {
    (void)arg0;
}

extern "C" void fn_8030992C(void * arg0) {
    if (FU32(FP(arg0, 0x4), 0x84) == 0 || (FU32(FP(arg0, 0x4), 0x84) & 1)) {
        FU32(FP(FP(arg0, 0x4), 0x474), 0x14) |= 0x10;
        ((VDispatch3 *) FP(FP(arg0, 0x4), 0x460))->v2();
        if (FU32(FP(arg0, 0x4), 0x78) < 0xE) {
            ((VDispatch3 *) FP(FP(arg0, 0x4), 0x540))->v2();
        }
    }
    ((VDispatch3 *) FP(FP(arg0, 0x4), 0x51C))->v2();
}

extern "C" void * fn_803099D0(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_80309B18(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)farg0;
}

extern "C" void fn_80309D38(void *arg0, s32 arg1, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)farg0;
}

extern "C" void * fn_80309E98(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_8030A248(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)farg0;
}

extern "C" void fn_8030A5BC(void * arg0) {
    (void)arg0;
}

extern "C" void fn_8030A6B8(void * arg0) {
    if (FU32(FP(arg0, 0x4), 0x84) == 0 || (FU32(FP(arg0, 0x4), 0x84) & 1)) {
        FU32(FP(FP(arg0, 0x4), 0x474), 0x14) |= 0x10;
        ((VDispatch3 *) FP(FP(arg0, 0x4), 0x460))->v2();
        if (FU32(FP(arg0, 0x4), 0x78) < 0xE) {
            ((VDispatch3 *) FP(FP(arg0, 0x4), 0x540))->v2();
        }
    }
    ((VDispatch3 *) FP(FP(arg0, 0x4), 0x504))->v2();
}

extern "C" void * fn_8030A75C(void * arg0, void *** arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void ** fn_8030AA6C(void *arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_8030AB3C(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)farg0;
}

extern "C" void fn_8030B1F8(void * arg0) {
    (void)arg0;
}

extern "C" void fn_8030B2F4(void * arg0) {
    if (FU32(FP(arg0, 0x4), 0x84) == 0 || (FU32(FP(arg0, 0x4), 0x84) & 1)) {
        FU32(FP(FP(arg0, 0x4), 0x474), 0x14) |= 0x10;
        ((VDispatch3 *) FP(FP(arg0, 0x4), 0x460))->v2();
        if (FU32(FP(arg0, 0x4), 0x78) < 0xE) {
            ((VDispatch3 *) FP(FP(arg0, 0x4), 0x540))->v2();
        }
    }
    ((VDispatch3 *) FP(FP(arg0, 0x4), 0x518))->v2();
}

extern "C" void * fn_8030B398(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void ** fn_8030BA78(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void fn_8030BB24(void *arg0, s32 arg1, s32 * arg2, s32 arg3, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)farg0;
}

extern "C" void fn_8030C334(void * arg0) {
    (void)arg0;
}

extern "C" void fn_8030C430(void * arg0) {
    if (FU32(FP(arg0, 0x4), 0x84) == 0 || (FU32(FP(arg0, 0x4), 0x84) & 1)) {
        FU32(FP(FP(arg0, 0x4), 0x474), 0x14) |= 0x10;
        ((VDispatch3 *) FP(FP(arg0, 0x4), 0x460))->v2();
        if (FU32(FP(arg0, 0x4), 0x78) < 0xE) {
            ((VDispatch3 *) FP(FP(arg0, 0x4), 0x540))->v2();
        }
    }
    ((VDispatch3 *) FP(FP(arg0, 0x4), 0x52C))->v2();
}

extern "C" void ** fn_8030C4D4(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_8030C718(void) {
    return 32;
}

extern "C" s32 fn_8030C720(void) {
    return 1;
}

extern "C" s32 fn_8030C728(void) {
    return 1;
}

extern "C" s32 fn_8030C730(void *arg0, f32 farg0) {
    fn_802E498C(arg0, (f32 *) ((char *) TopRideItem_GetDataBase() + 0x2F0));
    return (f64) FU32(FP(arg0, 0x4), 0x58) >= farg0;
}

extern "C" void fn_8030C79C(void *arg0) {
    (void)arg0;
}

extern "C" void ** fn_8030C7C0(void *arg0, void ** arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void fn_8030C868(void *arg0) {
    (void)arg0;
}

extern "C" void ** fn_8030C8B0(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_8030CA54(void) {
    return 31;
}

extern "C" s32 fn_8030CA5C(void) {
    return 1;
}

extern "C" s32 fn_8030CA64(void *arg0, f32 farg0) {
    fn_802E498C(arg0, (f32 *) ((char *) TopRideItem_GetDataBase() + 0x1F8));
    return (f64) FU32(FP(arg0, 0x4), 0x58) >= farg0;
}

extern "C" void ** fn_8030CAD0(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_8030CCF8(void) {
    return 30;
}

extern "C" s32 fn_8030CD00(void) {
    return 1;
}

extern "C" s32 fn_8030CD08(void) {
    return 1;
}

extern "C" s32 fn_8030CD10(void *arg0) {
    (void)arg0;
    return 0;
}

extern "C" void ** fn_8030CDB0(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_8030CEF0(void) {
    return 29;
}

extern "C" s32 fn_8030CEF8(void) {
    return 1;
}

extern "C" s32 fn_8030CF00(void) {
    return 0;
}

extern "C" s32 fn_8030CF08(void *arg0, f32 farg0) {
    fn_802E498C(arg0, (f32 *) ((char *) TopRideItem_GetDataBase() + 0x70));
    return (f64) FU32(FP(arg0, 0x4), 0x58) >= farg0;
}

extern "C" f32 fn_8030CF74(void) {
    return FF32(TopRideItem_GetDataBase(), 0x80);
}

extern "C" f32 fn_8030CF98(void) {
    return FF32(TopRideItem_GetDataBase(), 0x9C);
}

extern "C" void ** fn_8030CFBC(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_8030D210(void) {
    return 28;
}

extern "C" s32 fn_8030D218(void) {
    return 1;
}

extern "C" s32 fn_8030D220(void) {
    return 1;
}

extern "C" s32 fn_8030D228(void) {
    return 1;
}

extern "C" s32 fn_8030D230(void) {
    return 0;
}

extern "C" s32 fn_8030D238(void *arg0, f32 farg0) {
    fn_802E498C(arg0, (f32 *) ((char *) TopRideItem_GetDataBase() + 0x1B4));
    return (f64) FU32(FP(arg0, 0x4), 0x58) >= farg0;
}

extern "C" f32 fn_8030D2A4(void) {
    return FF32(TopRideItem_GetDataBase(), 0x1C4);
}

extern "C" void fn_8030D2C8(void) {

}

extern "C" void ** fn_8030D2CC(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_8030D48C(void) {
    return 27;
}

extern "C" s32 fn_8030D494(void) {
    return 1;
}

extern "C" s32 fn_8030D49C(void *arg0, f32 farg0) {
    fn_802E498C(arg0, (f32 *) ((char *) TopRideItem_GetDataBase() + 0x1C));
    return (f64) FU32(FP(arg0, 0x4), 0x58) >= farg0;
}

extern "C" void fn_8030D508(void *arg0) {
    (void)arg0;
}

extern "C" void * fn_8030D510(void) {
    return lbl_804DD0D8;
}

extern "C" void fn_8030D51C(f32 * arg0) {
    (void)arg0;
}

extern "C" void * fn_8030D918(void * arg0, s32 arg_sp0) {
    (void)arg0;
    (void)arg_sp0;
    return 0;
}

extern "C" void fn_8030F084(void * arg0, void *arg1, s32 arg_sp0) {
    (void)arg0;
    (void)arg1;
    (void)arg_sp0;
}

extern "C" void * fn_8030F318(void * arg0, s32 arg2, s32 arg_sp0) {
    (void)arg0;
    (void)arg2;
    (void)arg_sp0;
    return 0;
}

extern "C" void * fn_8030FCB4(void * arg0, void * arg2, s32 arg3, s32 arg_sp0) {
    (void)arg0;
    (void)arg2;
    (void)arg3;
    (void)arg_sp0;
    return 0;
}

extern "C" void * fn_80310364(void * arg0, void * arg2, s32 arg3, s32 arg_sp0) {
    (void)arg0;
    (void)arg2;
    (void)arg3;
    (void)arg_sp0;
    return 0;
}

extern "C" void * fn_80310758(void * arg0, void * arg2, s32 arg3, s32 arg_sp0) {
    (void)arg0;
    (void)arg2;
    (void)arg3;
    (void)arg_sp0;
    return 0;
}

extern "C" void * fn_80310934(void * arg0, void * arg2, s32 arg3) {
    (void)arg0;
    (void)arg2;
    (void)arg3;
    return 0;
}

extern "C" void * fn_80310E10(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_803110BC(void * arg0, s32 arg1, s32 arg2, s32 arg3) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
}

extern "C" void * fn_80311170(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_80311438(void * arg0, s32 arg1, s32 arg2, s32 arg3) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
}

extern "C" void * fn_803114FC(void * arg0, void * arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void fn_80311A20(void * arg0) {
    (void)arg0;
}

extern "C" void fn_80311CBC(s32 arg0) {
    (void)arg0;
}

extern "C" void fn_80311CC4(s32 arg0) {
    (void)arg0;
}

extern "C" void fn_80311CCC(s32 arg0) {
    (void)arg0;
}

extern "C" void fn_80311CD4(s32 arg0) {
    (void)arg0;
}

extern "C" void fn_80311CDC(s32 arg0) {
    (void)arg0;
}

extern "C" void fn_80311CE4(s32 arg0) {
    (void)arg0;
}

extern "C" void fn_80311CEC(s32 arg0) {
    (void)arg0;
}

extern "C" void fn_80311CF4(s32 arg0) {
    (void)arg0;
}

extern "C" void fn_80311CFC(s32 arg0) {
    (void)arg0;
}

extern "C" void fn_80311D04(void * arg0, f32 * arg1, f32 * arg2, u8 arg3) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
}

extern "C" u16 fn_80311DB0(u8 arg0, f64 farg0, f32 farg1) {
    (void)arg0;
    (void)farg0;
    (void)farg1;
    return 0;
}

extern "C" void fn_80311EA0(s16 arg0, f32 * arg1, f32 * arg2, u8 * arg3) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
}

extern "C" void fn_80311F2C(void * arg0) {
    (void)arg0;
}

extern "C" void fn_80311F88(s32 * arg0, f32 farg0, f32 farg1) {
    (void)arg0;
    (void)farg0;
    (void)farg1;
}

extern "C" s32 fn_80312000(s32 * arg0, s32 arg_sp0) {
    (void)arg0;
    (void)arg_sp0;
    return 0;
}

extern "C" f32 fn_803120C0(s32 * arg0) {
    (void)arg0;
    return 0.0f;
}

extern "C" void kar_diag__803121ec(void *arg0, u16 * arg1, u32 arg2, u16 * arg3, s32 arg_sp0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)arg_sp0;
}

extern "C" struct _struct_lbl_804E02D0_0x20 * fn_803124F0(void) {
    return 0;
}

extern "C" struct _struct_lbl_804E02D0_0x20 * fn_80312544(s32 arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_80312558(void) {

}

extern "C" s32 fn_80312650(s32 arg0) {
    return FU32(kar_resrec_a2a2dbg_000f_804e0620 + arg0 * 0x24, 0x4);
}

extern "C" s32 fn_80312668(s32 arg0) {
    return FU32(kar_resrec_a2a2dbg_000f_804e0620 + arg0 * 0x24, 0x8);
}

extern "C" s32 fn_80312680(s32 arg0) {
    return FU32(kar_resrec_a2a2dbg_000f_804e0620 + arg0 * 0x24, 0x20);
}

extern "C" s32 fn_80312698(void) {
    return 7;
}

extern "C" s32 fn_803126A0(s32 arg0) {
    (void)arg0;
    return 0;
}

extern "C" s32 fn_803126B4(s32 arg0) {
    return FU32(kar_resrec_a2a2dbg_000f_804e0620 + arg0 * 0x24, 0x8);
}

extern "C" void ** fn_803126CC(void *arg0, void * arg1, s32 arg_sp0) {
    (void)arg0;
    (void)arg1;
    (void)arg_sp0;
    return 0;
}

extern "C" void ** fn_80312D4C(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void fn_80312E50(void *arg0, s32 arg1) {
    (void)arg0;
    (void)arg1;
}

extern "C" s32 fn_80312ECC(void * arg0) {
    s8 idx = (s8) FU8(FP(FP(arg0, 0x4), 0x4), 0x3B);
    return FU32(kar_resrec_a2a2dbg_000f_804e0620 + idx * 0x24, 0x10);
}

extern "C" s32 fn_80312EF4(void * arg0) {
    s8 idx = (s8) FU8(FP(FP(arg0, 0x4), 0x4), 0x3B);
    return FU32(kar_resrec_a2a2dbg_000f_804e0620 + idx * 0x24, 0x14);
}

extern "C" s32 fn_80312F1C(void * arg0) {
    s8 idx = (s8) FU8(FP(FP(arg0, 0x4), 0x4), 0x3B);
    return FU32(kar_resrec_a2a2dbg_000f_804e0620 + idx * 0x24, 0x18);
}

extern "C" s32 fn_80312F44(void * arg0) {
    s8 idx = (s8) FU8(FP(FP(arg0, 0x4), 0x4), 0x3B);
    return FU32(kar_resrec_a2a2dbg_000f_804e0620 + idx * 0x24, 0x20);
}

extern "C" s32 fn_80312F6C(void * arg0) {
    s8 idx = (s8) FU8(FP(FP(arg0, 0x4), 0x4), 0x3B);
    return FU32(kar_resrec_a2a2dbg_000f_804e0620 + idx * 0x24, 0xC);
}

extern "C" s32 fn_80312F94(void * arg0) {
    s8 idx = (s8) FU8(FP(FP(arg0, 0x4), 0x4), 0x3B);
    return FU32(kar_resrec_a2a2dbg_000f_804e0620 + idx * 0x24, 0x1C);
}

extern "C" void * fn_80312FBC(void * arg0, void * arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void fn_80313140(void *arg1, void * arg2, f32 farg0, f32 farg1) {
    (void)arg1;
    (void)arg2;
    (void)farg0;
    (void)farg1;
}

extern "C" void ** fn_80313270(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" s32 fn_803132CC(void * arg1) {
    (void)arg1;
    return 0;
}

extern "C" void ** fn_80313354(void *arg0, u32 arg1, s32 arg2, void * arg3, void * arg4, s32 arg5, s8 arg6, s32 arg_sp0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)arg4;
    (void)arg5;
    (void)arg6;
    (void)arg_sp0;
    return 0;
}

extern "C" void ** fn_80313A20(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void ** fn_80313A84(void *arg0) {
    (void)arg0;
    return 0;
}

extern "C" void fn_80313AC4(void * arg0, void * arg1, void * arg2, s32 arg_sp0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg_sp0;
}

extern "C" void fn_80314068(void * arg0, void ** arg1) {
    (void)arg0;
    (void)arg1;
}

extern "C" void fn_803140A0(void * arg0, void ** arg1) {
    (void)arg0;
    (void)arg1;
}

extern "C" void fn_803140D8(void ** arg0, void ** arg1, void ** arg2) {
    u32 a = FU32(arg1, 0x0);
    u32 b = FU32(arg2, 0x0);
    FU32(arg0, 0x0) = a;
    FU32(arg0, 0x4) = b;
}

extern "C" void * fn_803140EC(void * arg0) {
    (void)arg0;
    return 0;
}

extern "C" void ** fn_80314100(void *arg0, s16 arg1) {
    if (arg0 != 0) {
        FP(arg0, 0x0) = lbl_804E09F4;
        lbl_805DDBC8 = 0;
        if ((s16) arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return (void **) arg0;
}

extern "C" void ** fn_80314150(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void ** fn_80314398(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void fn_8031447C(void * arg0, s32 arg_sp0) {
    (void)arg0;
    (void)arg_sp0;
}

extern "C" void fn_8031471C(void * arg0) {
    (void)arg0;
}

extern "C" void fn_803147C4(void * arg0) {
    (void)arg0;
}

extern "C" void * fn_8031483C(void * arg0, s32 arg1, void *arg2, f32 * arg3, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)farg0;
    return 0;
}

extern "C" void fn_80314934(void * arg0) {
    (void)arg0;
}

extern "C" void * fn_803149E4(void * arg0, s32 arg1, void * arg2, u8 arg3, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)farg0;
    return 0;
}

extern "C" void fn_80314B6C(void * arg0, void * arg1, u8 arg2) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
}

extern "C" f32 fn_80314E54(f32 farg0) {
    (void)farg0;
    return 0.0f;
}

extern "C" f32 fn_803152B0(f32 farg0) {
    (void)farg0;
    return 0.0f;
}

extern "C" void * fn_803156FC(void * arg0, void *arg1, f32 * arg2, u8 arg3, u8 arg4, u8 arg5, f32 farg0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)arg4;
    (void)arg5;
    (void)farg0;
    return 0;
}

extern "C" s32 fn_803158A8(void * arg1) {
    (void)arg1;
    return 0;
}

extern "C" void ** fn_803159AC(void *arg0, s16 arg1) {
    if (arg0 != 0) {
        FP(arg0, 0x0) = lbl_804E0898;
        lbl_805DDBCC = 0;
        if ((s16) arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return (void **) arg0;
}

extern "C" s32 fn_803159FC(void * arg1) {
    (void)arg1;
    return 0;
}

extern "C" s32 fn_80315AB0(void) {
    return 1;
}

extern "C" void fn_80315AB8(void * arg1) {
    (void)arg1;
}

extern "C" s32 fn_80315AF0(void * arg1) {
    (void)arg1;
    return 0;
}

extern "C" s32 fn_80315B34(void * arg1) {
    (void)arg1;
    return 0;
}

extern "C" s32 fn_80315BC0(void * arg1) {
    (void)arg1;
    return 0;
}

extern "C" s32 fn_80315C04(void) {
    return 1;
}

extern "C" void kar_diag__80315c0c(void * arg0, void * arg1, u32 arg2, void *arg3, s32 arg_sp0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)arg_sp0;
}

extern "C" void ** fn_80316128(void *arg0, s16 arg1) {
    if (arg0 != 0) {
        fn_803161E8((u32 *) arg0);
        if (FU32(arg0, 0x8) != 0) {
            fn_8038CB78((void *) FU32(arg0, 0x8));
        }
        if ((s16) arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return (void **) arg0;
}

extern "C" void ** fn_80316188(void *arg0, s16 arg1) {
    if (arg0 != 0) {
        kar_diagnostic__80316220((void *) arg0);
        if (FU32(arg0, 0x8) != 0) {
            fn_8038CB78((void *) FU32(arg0, 0x8));
        }
        if ((s16) arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return (void **) arg0;
}

extern "C" void fn_803161E8(u32 * arg0) {
    (void)arg0;
}

extern "C" void kar_diagnostic__80316220(void * arg0) {
    (void)arg0;
}

extern "C" void ** kar_diagnostic__near_803162a0(void *arg0, s16 arg1) {
    if (arg0 != 0) {
        kar_diagnostic__80316300((void *) arg0);
        if (FU32(arg0, 0x8) != 0) {
            fn_8038CB78((void *) FU32(arg0, 0x8));
        }
        if ((s16) arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return (void **) arg0;
}

extern "C" void kar_diagnostic__80316300(void * arg0) {
    (void)arg0;
}

extern "C" void ** kar_diagnostic__near_80316378(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void ** kar_diagnostic__near_803163f8(void *arg0, s16 arg1) {
    if (arg0 != 0) {
        kar_diagnostic__80316458((void *) arg0);
        if (FU32(arg0, 0x8) != 0) {
            fn_8038CB78((void *) FU32(arg0, 0x8));
        }
        if ((s16) arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return (void **) arg0;
}

extern "C" void kar_diagnostic__80316458(void * arg0) {
    (void)arg0;
}

extern "C" void kar_diagnostic__80316494(void *arg0) {
    (void)arg0;
}

extern "C" void kar_diagnostic__near_80317018(void *arg1, void * arg2, f32 farg0, f32 farg1) {
    (void)arg1;
    (void)arg2;
    (void)farg0;
    (void)farg1;
}

extern "C" void kar_diagnostic__803170c8(void *arg0) {
    (void)arg0;
}

extern "C" void ** kar_diagnostic__near_80317400(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void kar_diagnostic__near_803174e4(void *arg0) {
    (void)arg0;
}

extern "C" void kar_diagnostic__near_80317518(s32 arg0, void *arg1, s32 arg_sp0) {
    (void)arg0;
    (void)arg1;
    (void)arg_sp0;
}

extern "C" void ** kar_diagnostic__near_80317944(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void ** kar_diagnostic__near_803179c8(void *arg0) {
    return (void **) FP(arg0, 0x24);
}

extern "C" void ** kar_diagnostic__near_803179d0(void *arg0) {
    return (void **) FP(arg0, 0x20);
}

extern "C" u32 kar_diagnostic__near_803179d8(void *arg0, void *arg1, void *arg2) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    return 0;
}

extern "C" void kar_diagnostic__80317ce4(void *arg0, void *arg1) {
    (void)arg0;
    (void)arg1;
}

extern "C" void fn_80318E1C(void * arg0, s32 arg1, void * arg2, void * arg3) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
}

extern "C" s32 fn_80318F30(void * arg0, f32 * arg1, f32 * arg2, f32 * arg3, f32 * arg4) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)arg4;
    return 0;
}

extern "C" void fn_80319440(void *arg0) {
    (void)arg0;
}

extern "C" void fn_8031981C(void *arg1, void * arg2, void * arg3) {
    (void)arg1;
    (void)arg2;
    (void)arg3;
}

extern "C" void fn_80319A44(void *arg1, void *arg2, void *arg3, s32 * arg_sp0) {
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)arg_sp0;
}

extern "C" void ** fn_80319BDC(void *arg0, f32 * arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void ** fn_8031A74C(void *arg0, f32 farg0, f32 farg1) {
    (void)arg0;
    (void)farg0;
    (void)farg1;
    return 0;
}

extern "C" u32 fn_8031B0FC(void *arg1) {
    (void)arg1;
    return 0;
}

extern "C" u32 fn_8031B3C4(f32 farg1) {
    (void)farg1;
    return 0;
}

extern "C" void fn_8031B474(f32 * arg0, f32 * arg1, s32 arg_sp0) {
    (void)arg0;
    (void)arg1;
    (void)arg_sp0;
}

extern "C" void kar_diag__8031b640(void *arg0, void * arg1, u32 arg2, f32 * arg3, s32 arg_sp0) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)arg_sp0;
}

extern "C" void kar_diag__8031bcdc(void *arg0, u32 arg1) {
    (void)arg0;
    (void)arg1;
}

extern "C" void ** kar_diagnostic__8031be7c(void *arg0, s16 arg1) {
    if (arg0 != 0) {
        kar_diagnostic__8031c358((void *) arg0);
        if (FU32(arg0, 0x8) != 0) {
            fn_8038CB78((void *) FU32(arg0, 0x8));
        }
        if ((s16) arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return (void **) arg0;
}

extern "C" void ** kar_diagnostic__near_8031bedc(void *arg0, s16 arg1) {
    if (arg0 != 0) {
        kar_diagnostic__8031c3e0((u32 *) arg0);
        if (FU32(arg0, 0x8) != 0) {
            fn_8038CB78((void *) FU32(arg0, 0x8));
        }
        if ((s16) arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return (void **) arg0;
}

extern "C" void kar_diagnostic__near_8031bf3c(f32 * arg0, f32 * arg1, f32 * arg2) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
}

extern "C" f32 * kar_diagnostic__near_8031bfdc(f32 * arg0, f32 * arg1, u8 * arg2) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    return 0;
}

extern "C" f32 * kar_diagnostic__near_8031c144(f32 * arg0, f32 * arg1, u8 * arg2) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    return 0;
}

extern "C" void kar_diagnostic__near_8031c2dc(f32 * arg0, f32 * arg1) {
    (void)arg0;
    (void)arg1;
}

extern "C" void kar_diagnostic__8031c358(void * arg0) {
    (void)arg0;
}

extern "C" void kar_diagnostic__8031c3e0(u32 * arg0) {
    (void)arg0;
}

extern "C" void fn_8031C418(void * arg0, void *arg1) {
    (void)arg0;
    (void)arg1;
}

extern "C" void fn_8031C664(void * arg0) {
    (void)arg0;
}

extern "C" void ** fn_8031C7E8(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void * fn_8031C844(void * arg0, s32 arg1, s32 arg2, s32 arg3) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    return 0;
}

extern "C" void ** fn_8031CA7C(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void fn_8031CB44(void * arg0) {
    (void)arg0;
}

extern "C" void fn_8031CBE0(f32 * arg0) {
    f32 a = arg0[0];
    f32 b = arg0[1];
    GX_FIFO_F32 = a;
    GX_FIFO_F32 = b;
    GX_FIFO_F32 = arg0[2];
}

extern "C" void fn_8031CC00(void * arg0) {
    (void)arg0;
}

extern "C" f32 fn_8031DA10(void) {
    return lbl_805E3EE8;
}

extern "C" void fn_8031DA18(void *arg0, s16 arg1, u32 arg2) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
}

extern "C" void fn_8031DA58(void *arg0) {
    FU32(arg0, 0x4) = 0;
    FU32(arg0, 0x8) = FU32(arg0, 0x8) + FU32(arg0, 0x14);
    FU32(arg0, 0x14) = 0;
}

extern "C" void fn_8031DA78(void * arg0) {
    (void)arg0;
}

extern "C" void ** fn_8031DB7C(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void fn_8031DBC4(void * arg0) {
    (void)arg0;
}

extern "C" void fn_8031DC48(void * arg0) {
    (void)arg0;
}

extern "C" void fn_8031DD30(void * arg0) {
    (void)arg0;
}

extern "C" void fn_8031DEAC(void * arg0, s32 arg1) {
    (void)arg0;
    (void)arg1;
}

extern "C" void fn_8031DF54(void * arg0) {
    (void)arg0;
}

extern "C" void ** fn_8031DFFC(void *arg0, u8 arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg_sp8) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)arg4;
    (void)arg5;
    (void)arg6;
    (void)arg7;
    (void)arg_sp8;
    return 0;
}

extern "C" void ** fn_8031E508(void *arg0, s16 arg1) {
    if (arg0 != 0) {
        FP(arg0, 0x0) = lbl_804E0E6C;
        lbl_805DDB30 = 0;
        if ((s16) arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return (void **) arg0;
}

extern "C" void fn_8031E558(void * arg0, void * arg1) {
    (void)arg0;
    (void)arg1;
}

extern "C" void fn_8031E824(void * arg0, s32 arg1) {
    (void)arg0;
    (void)arg1;
}

extern "C" void ** fn_8031EA08(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void ** fn_8031EAF8(void *arg0, s16 arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

extern "C" void fn_8031EBB8(void) {

}

extern "C" void fn_8031EBBC(void * arg0) {
    (void)arg0;
}

extern "C" void * fn_8031F0B0(void * arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)arg4;
    (void)arg5;
    return 0;
}

extern "C" void fn_8031F410(void * arg0) {
    (void)arg0;
}

extern "C" void fn_8031F4BC(void * arg0, f32 farg0) {
    FF32(arg0, 0x1C) = farg0;
}

extern "C" void fn_8031F4C4(void * arg0) {
    (void)arg0;
}

extern "C" void fn_8031F52C(void * arg0) {
    (void)arg0;
}

extern "C" void fn_8031F758(void * arg0) {
    (void)arg0;
}

extern "C" void fn_80320204(void) {

}
