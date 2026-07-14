#include <dolphin/types.h>
#include <dolphin/gx/gxtypes.h>

extern "C" {
#include <global.h>
#include <sysdolphin/jobj.h>
}

#define GX_TEX_S            0
#define GX_TEX_ST           1
#define GX_RGB565           0
#define GX_RGBA6            4
#define GX_RGBA8            5
#define GX_DIRECT           1
#define GX_QUADS            0x80
#define GX_VTXFMT0          0
#define GX_ALWAYS           7
#define GX_LESS             1
#define GX_PNMTX0           0

extern "C" {
void GXInvalidateVtxCache(void);
void GXClearVtxDesc(void);
void GXSetVtxAttrFmt(u32, u32, u32, u32, u32);
void GXSetVtxDesc(u32, u32);
void GXSetCurrentMtx(u32);
void GXLoadPosMtxImm(void *, u32);
void GXBegin(u32, u32, u16);
void GXSetZMode(u32, u32, u32);
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

class KartIF {
public:
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void *v24();
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
    virtual void v84();
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

class MatchNodeBase {
public:
    virtual ~MatchNodeBase();
    virtual u8 Match();
};

typedef u8 (MatchNodeBase::*MatchMemFn)();

struct DiagResult {
    char pad0[0x14];
    s32 unk14;
    void *unk18;
};

extern "C" {

void *kar_diag__803ad760(s32, s32, void *, void *, s32);
void kar_diag__802affd8(s32 *, s32, s32, void **);
void kar_diag__802b042c(s32 *, s32);
void kar_diagnostic__8029c5a4(u32 *);
void *kar_object__near_8036cc04(void *);
void *kar_object__8038d158(void *, s32, s32);

HSD_JObj *fn_8038D0A8(HSD_JObj *, const char *);

s32 HSD_CObjGetCurrent(void);
s32 HSD_CObjLoadDesc(s32, void *);
void HSD_CObjSetEyePosition(s32, Vec3f *);
void HSD_CObjGetEyePosition(s32, Vec3f *);
void HSD_CObjSetInterest(s32, Vec3f *, f32, f32);
void HSD_CObjGetInterest(s32, Vec3f *);
void HSD_CObjGetUpVector(s32, Vec3f *);
void HSD_CObjSetFov(s32, f32, f32);
void HSD_CObjAnim(s32);

s32 HSD_Randi(s32);
f32 HSD_Randf(void);

f64 kar_atan(f32);
f64 kar_atan2(f32, f32);
f64 tan(f64);

f32 fn_80296264(f32);
f32 fn_8029626C(f32);
f32 fn_802D4C30(f32);

void PSVECAdd(Vec3f *, const Vec3f *, const Vec3f *);
void PSVECSubtract(Vec3f *, const Vec3f *, const Vec3f *);
void PSVECScale(Vec3f *, const Vec3f *, f32);
void PSVECNormalize(Vec3f *, const Vec3f *);
void PSVECCrossProduct(Vec3f *, const Vec3f *, const Vec3f *);
f32 PSVECMag(const Vec3f *);
f32 PSVECDotProduct(const Vec3f *, const Vec3f *);

void __destroy_arr(void *, void *, s32, s32);
u8 __ptmf_scall(void *);
void abort(void);

void *fn_8038CB28(s32);
void fn_8038CB78(void *);
f32 *fn_8038CB50(s32, u8, void *);
void fn_8038CCAC(void *, void *);
void fn_8038D0E8(void *, void *, s32, f32);
void fn_803B4D80(void *, const char *, void *);

void *fn_802AFD4C(void **, void **);
void fn_802B0AB8(void *, s32, s32 *, void **);
void *fn_802DE0E4(s32, f32);
void *TopRideItem_GetDataBase(void);
void fn_802E99F8(Vec3f *, Vec3f *, Vec3f *, f32, f32);
void fn_802FE674(Vec3f *, Vec3f *, Vec3f *, s32, Vec3f *, f32);
void *fn_8031A74C(void *, f32, f32);
void *fn_803124F0(f32);
void fn_80319BDC(void *, s32);
void fn_80391644(void);
void *fn_803919FC(s32, void *);
s32 fn_8038BBE8(s32, const char *);
void splGetCardinalPoint(Vec3f *, void *, f32);
void fn_802905F8(void *);
void fn_80290588(void *);
void fn_80290518(void *);
void fn_802904A8(void *);
void fn_80290438(void *);

void fn_80297828(void **, void *, void **, void **);
void fn_80297B8C(void **, void *, void **, void **);
void fn_802978F4(void *);
void fn_8029B1D8(void *, void *);

void *kar_a2d_effecthandle__8037b028(void *, s32, s32, void *, void *, s32);
void kar_a2d_effecthandle__near_8037b33c(void *, u8);
u8 kar_a2d_effecthandle__near_8037b61c(void *);
void kar_a2d_game_audio__near_803792b8(s32);
void kar_a2d_game_audio__near_80379398(void *);
void kar_a2d_game_audio__near_803795ac(void *, void *);
void kar_a2d_game_audio__near_80379784(void *, s32, void *);
void kar_a2d_game_effect__near_8037afd0(void *, u8);
void kar_a2d_game_lib__near_80289158(Vec3f *, Vec3f *);
u8 kar_a2d_game_lib__near_80289374(f32 *, void *, void *);
f32 kar_a2d_game_lib__near_80289928(void);
f32 kar_a2d_game_lib__near_802899d0(void);
void kar_a2d_refract__near_80384ec4(Vec3f *, void *);
void kar_a2d_refract__near_80384f44(void);
void kar_a2d_refract__near_8038528c(void *, s32, void *, void *);
void kar_a2d_refract__near_803852b4(void *, s32, void *, void *);
void kar_a2d_refract__near_803852f0(void *, void *, void *);
s32 kar_a2d_refract__near_803855bc(void *);
void kar_a2d_wipeeffect__near_8037e9c8(void *, void *, void *, void *, void *, s32, f32);

s32 kar_lbaudio__near_8005df64(void);
s32 kar_lbaudio__near_8005dff8(s32);
s32 kar_lbaudio_alloc_vehicle_track_subtype_1(void);
s32 kar_lbaudio_alloc_weapon_track_subtype_1(void);
s32 kar_lbaudio_alloc_weapon_track_subtype_6(void);
void kar_lbaudio_build_hps_basename_table(void *);
s32 kar_lbaudio_is_track_handle_playing(s32);
void kar_lbaudio_mark_auto_track_started(s32);
void kar_lbaudio_release_track_handle_when_idle(s32);
f32 kar_lbvector_angle_between(Vec3f *, Vec3f *);
void kar_lbvector_rotate_about_axis(Vec3f *, Vec3f *, f32);
void kar_lbvector_rotate_about_cardinal_axis(Vec3f *, s32, f32);

s32 memcmp(const void *, const void *, u32);
void *memcpy(void *, const void *, u32);
s32 strcmp(const char *, const char *);
s32 strlen(const char *);
char *strncpy(char *, const char *, u32);

u8 CARDGetResultCode(s32);
s32 CARDInit(void *, void *);
s32 CARDProbeEx(s32, s32 *, s32 *);
void CARDMountAsync(s32, void *, void *, void *);
s32 CARDOpen(s32, const char *, void *);
void CARDClose(void *);
void CARDReadAsync(void *, void *, s32, s32, void *);
void CARDUnmount(s32);
void CARDCreateAsync(s32, const char *, u32, void *, void *);
void CARDGetStatus(s32, s32, void *);
void CARDSetStatusAsync(s32, s32, void *, void *);
void CARDWriteAsync(void *, void *, s32, s32, void *);

void OSReport(const char *, ...);

extern void *__files;
extern void *fn_802D7D4C;

extern char kar_srcfile_jobj_h_805db8a0[7];
extern char lbl_805DB8A8[5];
extern char lbl_804F0528[0xA];

extern char lbl_804BCEC0[];
extern char lbl_804BCEE8[];
extern char lbl_804BCF14[];
extern char lbl_804BCF3C[];
extern char lbl_804BCF64[];
extern char lbl_804BD26C[];
extern char lbl_804BD598[];
extern char lbl_804BD5BC[];
extern char lbl_804BDF2C[];
extern char lbl_804BDF70[];
extern char lbl_804BE210[];
extern char lbl_804BE238[];
extern char lbl_804BF078[];
extern char lbl_804BF0BC[];
extern char lbl_804BF0E4[];
extern char lbl_804BF1B0[];
extern char lbl_804BF288[];
extern char lbl_804BF3C0[];
extern char lbl_804BF4DC[];
extern char lbl_804C04D4[];
extern char lbl_804C04E0[];
extern char lbl_804C4B00[];
extern char lbl_804D7700[];
extern void *lbl_804E09E4;
extern void *lbl_804EA538;
extern const Vec3f lbl_804F07EC;
extern void *lbl_805DB918;
extern void *lbl_805DB920;
extern void *lbl_805DB930;
extern void *lbl_805DB938;
extern void *lbl_804F08DC;
extern Vec3f lbl_8048A580;
extern Vec3f lbl_8048A58C;
extern void *lbl_805DB958;
extern void *lbl_805DB960;
extern void *lbl_805DB968;
extern void *lbl_805DB978;
extern void *lbl_805DB9C0;
extern void *lbl_805DB9C8;
extern void *lbl_804F0D7C;
extern void *lbl_804F1010;
extern void *lbl_804F1004;
extern void *lbl_804F0FE8;
extern void *lbl_804F0F8C;
extern void *lbl_805DB9F0;
extern void *lbl_805DB9E8;
extern void *lbl_805DBA70;
extern void *lbl_805DBA68;
extern void *lbl_805DBA60;
extern void *lbl_805DBA58;
extern void *lbl_805DBAA0;
extern void *lbl_805DBA98;
extern void *lbl_805DBAB0;
extern void *lbl_805DBAA8;
void HSD_StateInvalidate(s32);
extern char lbl_8048A5A0[0xE00];
extern char lbl_804F130C[0x18];
extern char lbl_804F1318[0xC];
extern struct { s32 *unk0; char pad4[4]; s32 unk8; s32 unkC; } lbl_804F20F0[0x1B];
extern void *lbl_804F13E0;
extern void *lbl_804F2308;
extern void *lbl_80569840;
extern void *lbl_805DBB50;
extern void *lbl_805DBB40;
extern void *lbl_805DBA08;
extern void *lbl_805DBA00;
extern void *lbl_804F0F28;
extern void *lbl_804F0ECC;
s32 kar_a2d_effect_slideblur__near_80382bf4(s32 *, s32, s8);
extern void *lbl_804F4E38;
extern void *lbl_804F5208;
extern void *lbl_805DB8D0;
extern void *lbl_805DB8D8;
extern f32 lbl_805DC8BC;
extern void *lbl_805DD964;
extern void *lbl_805DD9A4;
extern void **lbl_805DDA88;
extern void **lbl_805DDA94;
extern void **lbl_805DDAB8;
extern void **lbl_805DDB34;
extern void **lbl_805DDB48;
extern void **lbl_805DDB50;
extern s32 lbl_805DDB6C;
extern void **lbl_805DDB70;
extern void **lbl_805DDB74;
extern void **lbl_805DDB78;
extern void **lbl_805DDB7C;
extern void **lbl_805DDB80;
extern void **lbl_805DDBAC;
extern void **lbl_805DDBB0;
extern void **lbl_805DDBC4;
extern void **lbl_805DDBC8;
extern u8 lbl_805DDC68;
extern void *lbl_805DDC70;
extern void **lbl_805DDC88;
extern u8 lbl_805DDC8C[2];
extern void *lbl_805DDC90;
extern void *lbl_805DDCA0;
extern u8 lbl_805DDCB0;
extern f32 lbl_805E4850;
extern f32 lbl_805E4854;
extern f32 lbl_805E4858;
extern f32 lbl_805E485C;
extern f32 lbl_805E4860;
extern f32 lbl_805E486C;
extern f32 lbl_805E4870;
extern f32 lbl_805E4890;
extern f64 lbl_805E48E0;
extern f64 lbl_805E48E8;
extern f64 lbl_805E48F0;
extern f32 lbl_805E48F8;
extern f32 lbl_805E48FC;
extern f32 lbl_805E4900;
extern f32 lbl_805E4904;
extern f32 lbl_805E4908;
extern f32 lbl_805E490C;
extern f32 lbl_805E4910;
extern f64 lbl_805E4918;
extern s32 lbl_805E6370;
extern s32 lbl_805E6374;

}

/* group1: shared "jobj.h" assert strings, owned by a2d_bg8000 */
static inline void SetTranslate_G1(HSD_JObj *jobj, Vec3f *tr) {
    if (jobj == NULL) {
        __assert(kar_srcfile_jobj_h_805db8a0, 0x3A9, lbl_805DB8A8);
    }
    if (tr == NULL) {
        __assert(kar_srcfile_jobj_h_805db8a0, 0x3AA, lbl_804F0528);
    }
    jobj->translate = *(Vec *) tr;
    if (!(jobj->flags & MTX_INDEP_SRT)) {
        HSD_JObjSetMtxDirty(jobj);
    }
}

/* group2: kurakko-local copy #1 (functions 8036edd8..8036fa8c) */
static char kar_srcfile_jobj_h_805db940[7] = "jobj.h";
static char lbl_805DB948[5] = "jobj";
static char lbl_805DB950[6] = "scale";
static char lbl_805DB980[7] = "rotate";
static char lbl_804F08D0[0xA] = "translate";

static inline void SetTranslate_G2(HSD_JObj *jobj, Vec3f *tr) {
    if (jobj == NULL) {
        __assert(kar_srcfile_jobj_h_805db940, 0x3A9, lbl_805DB948);
    }
    if (tr == NULL) {
        __assert(kar_srcfile_jobj_h_805db940, 0x3AA, lbl_804F08D0);
    }
    jobj->translate = *(Vec *) tr;
    if (!(jobj->flags & MTX_INDEP_SRT)) {
        HSD_JObjSetMtxDirty(jobj);
    }
}

static inline void SetTranslateJObjOnly_G2(HSD_JObj *jobj, Vec3f *tr) {
    if (jobj == NULL) {
        __assert(kar_srcfile_jobj_h_805db940, 0x3A9, lbl_805DB948);
    }
    jobj->translate = *(Vec *) tr;
    if (!(jobj->flags & MTX_INDEP_SRT)) {
        HSD_JObjSetMtxDirty(jobj);
    }
}

static inline void SetScale_G2(HSD_JObj *jobj, Vec3f *sc) {
    if (jobj == NULL) {
        __assert(kar_srcfile_jobj_h_805db940, 0x316, lbl_805DB948);
    }
    if (sc == NULL) {
        __assert(kar_srcfile_jobj_h_805db940, 0x317, lbl_805DB950);
    }
    jobj->scale = *(Vec *) sc;
    if (!(jobj->flags & MTX_INDEP_SRT)) {
        HSD_JObjSetMtxDirty(jobj);
    }
}

static inline void SetRotate_G2(HSD_JObj *jobj, Vec4f *rot) {
    if (jobj == NULL) {
        __assert(kar_srcfile_jobj_h_805db940, 0x290, lbl_805DB948);
    }
    if (rot == NULL) {
        __assert(kar_srcfile_jobj_h_805db940, 0x291, lbl_805DB980);
    }
    jobj->rotate = *(Quaternion *) rot;
    if (!(jobj->flags & MTX_INDEP_SRT)) {
        HSD_JObjSetMtxDirty(jobj);
    }
}

/* group3: kurakko-local copy #2 (functions 8037122c/803715dc) */
static char kar_srcfile_jobj_h_805db9d0[7] = "jobj.h";
static char lbl_805DB9D8[5] = "jobj";
static char lbl_805DB9E0[6] = "scale";
static char lbl_804F0DE8[0xA] = "translate";
static char lbl_804F0DF4[0x25] = "!(jobj->flags & USE_QUATERNION)";
static char kar_src_object_804f0db4[9] = "object.h";
static char lbl_804F0DC0[0x27] = "HSD_OBJ(o)->ref_count != HSD_OBJ_NOREF";

static inline void SetTranslate_G3(HSD_JObj *jobj, Vec3f *tr) {
    if (jobj == NULL) {
        __assert(kar_srcfile_jobj_h_805db9d0, 0x3A9, lbl_805DB9D8);
    }
    if (tr == NULL) {
        __assert(kar_srcfile_jobj_h_805db9d0, 0x3AA, lbl_804F0DE8);
    }
    jobj->translate = *(Vec *) tr;
    if (!(jobj->flags & MTX_INDEP_SRT)) {
        HSD_JObjSetMtxDirty(jobj);
    }
}

static inline void SetScale_G3(HSD_JObj *jobj, Vec3f *sc) {
    if (jobj == NULL) {
        __assert(kar_srcfile_jobj_h_805db9d0, 0x316, lbl_805DB9D8);
    }
    if (sc == NULL) {
        __assert(kar_srcfile_jobj_h_805db9d0, 0x317, lbl_805DB9E0);
    }
    jobj->scale = *(Vec *) sc;
    if (!(jobj->flags & MTX_INDEP_SRT)) {
        HSD_JObjSetMtxDirty(jobj);
    }
}

static inline void SetRotationZOnly_G3(HSD_JObj *jobj, f32 z) {
    if (jobj == NULL) {
        __assert(kar_srcfile_jobj_h_805db9d0, 0x2B8, lbl_805DB9D8);
    }
    if (jobj->flags & USE_QUATERNION) {
        __assert(kar_srcfile_jobj_h_805db9d0, 0x2B9, lbl_804F0DF4);
    }
    jobj->rotate.y = z;
    if (!(jobj->flags & MTX_INDEP_SRT)) {
        HSD_JObjSetMtxDirty(jobj);
    }
}

static inline void RefObjRelease(void *o) {
    __assert(kar_src_object_804f0db4, 0x5D, lbl_804F0DC0);
}

class GameEffectItemBase {
public:
    virtual void v00();
    virtual void v04();
    virtual void Init(const char *);
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void *GetNext();
};

struct PreCtorHdr {
    void *vtable;
    s32 a;
    s32 b;
};

static inline void PreConstruct(void *p, void *vtable) {
    PreCtorHdr *h = (PreCtorHdr *) p;
    h->vtable = vtable;
    h->a = 0;
    h->b = 0;
}

struct KurakkoObj {
    void *unk0;             //0x00  own vtable (manually managed, see PreConstruct)
    char pad4[0x60];        //0x04
    HSD_JObj jobj64;        //0x64  (embedded jobj)
    char padD0[4];          //0xd0
    HSD_JObj *unkD4;
    u8 unkD8;
    char padD9[3];
    char pad_widget_ec[0x28]; //0xec  effecthandle embed
    char pad114[0x28];      //0x114
    char pad13c[0x48];      //0x13c generator embed data
    char pad184[0x28];      //0x184 wipeeffect embed
    char pad1ac[0x1c];      //0x1ac audio embed
    char pad1c8[0x20];      //0x1c8
    char pad1e8[0x14];      //0x1e8
    char pad1fc[0x200];     //slack
};

extern "C" {
void kar_a2d_kurakko__near_8036dbf8(KurakkoObj *arg0);
void kar_a2d_kurakko__near_8036df38(KurakkoObj *arg0, u32 arg1);
f32 kar_a2d_kurakko__near_8036e2fc(f32 farg0);
void fn_8036E748(void *arg0, void *arg1);
void kar_a2d_kurakko__near_8036e764(void *arg0, MatchMemFn arg1);
void fn_8036E81C(char *arg0);
void fn_8036E824(char *arg0);
void kar_a2d_kurakko__near_8036e82c(void *arg0, u8 arg1);
u8 fn_8036E8CC(void *arg0);
void kar_a2d_kurakko__near_8036e8d4(void *arg0);
void *kar_a2d_kurakko__8036e92c(KurakkoObj *arg0, KartIF *arg1);
void *kar_a2d_kurakko__near_8036eba4(KurakkoObj *arg0, KurakkoObj *arg1);
void kar_a2d_kurakko__near_8036edd8(KurakkoObj *arg0);
void kar_a2d_kurakko__near_8036f1b8(KurakkoObj *arg0);
void kar_a2d_kurakko__near_8036f214(KurakkoObj *arg0);
void kar_a2d_kurakko__near_8036f57c(KurakkoObj *arg0);
void kar_a2d_kurakko__near_8036fa8c(KurakkoObj *arg0, u8 arg1);
void kar_a2d_kurakko__near_80370e24(void *arg0, void *arg1, s32 arg2);
void *kar_a2d_kurakko__near_80370edc(void *arg0, s32 arg1);
void kar_a2d_kurakko__near_80370f9c(void *arg0);
s32 fn_8037102C(void *arg0);
void kar_a2d_kurakko__near_8037103c(void *arg0);
void kar_a2d_kurakko__near_80371094(void *arg0);
void *kar_a2d_kurakko__near_8037113c(void *arg0, void *arg1, s32 arg2, s8 arg3);
void kar_a2d_kurakko__near_8037122c(void *arg0);
void kar_a2d_kurakko__near_803714d8(void *arg0, void *arg1, s32 arg2);
void kar_a2d_kurakko__near_803715dc(void *arg0, void *arg1, void *arg2, void *arg3);
void *kar_a2d_kurakko__near_8037182c(void *arg0);
f32 *kar_a2d_kurakko__near_803718f8(void *arg0);
void *kar_a2d_kurakko__near_80371940(void *arg0);
void *kar_a2d_kurakko__near_80371968(void *arg0, s32 *arg1);
void kar_a2d_kurakko__near_80371aa0(void *arg0);
void *kar_a2d_kurakko__near_80371b90(void *arg0);
void kar_a2d_kurakko__near_80371d88(f32 *arg0, void *arg2, void *arg3, void *arg4, Vec3f *arg5, f32 farg0);
f32 kar_a2d_kurakko__near_803724e0(f32 farg0);
f32 kar_a2d_kurakko__near_8037293c(f32 farg0);
void kar_a2d_kurakko__near_80372d88(void *arg0, void *arg1, f32 *arg2);
void *kar_a2d_kurakko__near_803738fc(void *arg0);
void kar_a2d_kurakko__near_803739fc(void *arg0, void *arg1, Vec3f *arg2);
void *kar_a2d_kurakko__near_80373cb4(void *arg0);
void kar_a2d_kurakko__near_80373d74(void *arg0, void *arg1, Vec3f *arg2);
void kar_a2d_kurakko__near_80374020(void *arg0);
void kar_a2d_kurakko__near_80374060(void *arg0, Vec3f *arg2);
void kar_a2d_kurakko__near_80374214(void *arg0, u32 arg1);
void kar_a2d_kurakko__near_803743c8(void *arg0, void *arg1, u32 arg2, void *arg3, s32 arg4);
f32 *kar_a2d_kurakko__near_80374964(f32 *arg0, s16 arg1);
void kar_a2d_kurakko__near_803749c4(void *arg0);
void fn_803749FC(char *arg0);
void fn_80374A04(char *arg0);
void fn_80374A0C(char *arg0);
void fn_80374A14(char *arg0);
void fn_80374A1C(char *arg0);
void kar_a2d_kurakko__near_80374a24(void *arg0, Vec3f *arg1, f32 farg0, f32 farg1);
f32 kar_a2d_kurakko__near_80375060(f32 farg0);
f32 kar_a2d_kurakko__near_803754bc(f32 farg0);
void kar_a2d_kurakko__near_80375908(void *arg0);
void kar_a2d_kurakko__near_80375e4c(void *arg0);
void kar_a2d_kurakko__near_80375fb4(void *arg0, void *arg1, f32 *arg2, f32 *arg3, s32 arg4);
void kar_a2d_kurakko__near_803763cc(void *arg0, void *arg1, void *arg2, void *arg3);
void *kar_a2d_kurakko__near_803764cc(void *arg0);
void kar_a2d_kurakko__near_803764f4(void *arg0, void *arg1, Vec3f *arg2, f32 farg0);
void kar_a2d_kurakko__near_803768d8(void);
void kar_a2d_kurakko__near_80376944(void);
void kar_a2d_kurakko__near_803769c8(void *arg0);
void kar_a2d_kurakko__near_80376bcc(void *arg0);
void kar_a2d_kurakko__near_80376c50(void *arg0, void *arg1, void *arg2, f32 farg0);
void *kar_a2d_kurakko__near_80376e18(void *arg0, s32 arg1);
void kar_a2d_kurakko__near_80376ee4(void *arg0, void *arg1);
s32 kar_a2d_kurakko__near_80376f94(void *arg0, const char *arg1);
void fn_803773C8(s32 arg0);
f32 *kar_a2d_kurakko__near_803773d8(f32 *arg0, s16 arg1);
void fn_80377444(s32 arg0);
void fn_80377454(s32 arg0);
void *kar_a2d_kurakko__near_80377464(void *arg0, s16 arg1);
s32 kar_a2d_kurakko__near_803774b4(void *arg0, const char *arg1);
void kar_a2d_kurakko__near_80377920(void *arg0, void *arg1, void *arg2);
void *kar_a2d_kurakko__near_803779c0(void *arg0, void *arg1);
void kar_a2d_kurakko__near_80377a1c(void *arg0);
void kar_a2d_kurakko__near_80377a70(void *arg0, void *arg1);
void kar_a2d_kurakko__near_80377a90(void *arg0, void *arg1, void *arg2);
s32 kar_a2d_kurakko__near_80377bf4(void);
void *kar_a2d_kurakko__near_80377bfc(void *unused, s32 arg1);
void kar_a2d_kurakko__near_80377c10(void *arg0, void *arg2);
void kar_a2d_kurakko__near_80377ca4(void *arg0, s32 arg2);
void kar_a2d_kurakko__near_80377cc8(void);
void kar_a2d_kurakko__near_80377dac(void);
u32 kar_a2d_kurakko__near_80378568(void *arg0);
void *kar_a2d_kurakko__near_803785b0(void);
void *kar_a2d_kurakko__near_803785bc(void *arg0);
f32 *kar_a2d_kurakko__near_80378900(f32 *arg0, s16 arg1);
}

typedef Vec3f *(*VCallGetPos)(void *);

static inline Vec3f *CallV00(void *obj) {
    void *vtable = *(void **) obj;
    VCallGetPos fn = *(VCallGetPos *) ((char *) vtable + 8);
    return fn(obj);
}

extern "C" void kar_a2d_kurakko__near_8036dbf8(KurakkoObj *arg0) {
    Vec3f *pos = CallV00(arg0);
    f32 *self1 = (f32 *) ((char *) arg0 + 0x1C0);
    self1[0] = pos->x;
    self1[1] = pos->y;
    self1[2] = pos->z;
    u16 timer = *(u16 *) ((char *) arg0 + 0x7A);
    if (timer == 0) {
        u32 spawnDelay = *(u32 *) ((char *) arg0 + 0x1E4);
        if (spawnDelay == 0U) {
            kar_object__near_8036cc04(arg0);
        } else {
            spawnDelay -= 1;
            *(u32 *) ((char *) arg0 + 0x1E4) = spawnDelay;
            Vec3f *accel = (Vec3f *) ((char *) arg0 + 0x2C);
            if (spawnDelay == 0U) {
                Vec3f *spawnVec = (Vec3f *) ((char *) arg0 + 0x190);
                *accel = *spawnVec;
                kar_a2d_kurakko__near_8036df38(arg0, 0xA);
            } else {
                accel->x = lbl_805E4850;
                accel->y = lbl_805E4850;
                accel->z = lbl_805E4850;
            }
        }
        Vec3f *pos2 = CallV00(arg0);
        HSD_JObj *j = fn_8038D0A8(&arg0->jobj64, NULL);
        SetTranslate_G1(j, pos2);
        Vec3f *pos3 = CallV00(arg0);
        f32 *self3 = (f32 *) ((char *) arg0 + 0x16C);
        self3[0] = pos3->x;
        self3[1] = pos3->y;
        self3[2] = pos3->z;
        *(f32 *) ((char *) arg0 + 0x184) = lbl_805E486C;
        return;
    }
    timer += 1;
    *(u16 *) ((char *) arg0 + 0x7A) = timer;
    if (timer > 0x78U) {
        s32 playing = kar_lbaudio_is_track_handle_playing(*(s32 *) ((char *) arg0 + 0xEC));
        if (playing == 0) {
            *(u8 *) ((char *) arg0 + 0x70) = 1;
        }
    }
    if ((u32) timer == (u32) *(u32 *) ((char *) TopRideItem_GetDataBase() + 0x35C)) {
        *(s32 *) ((char *) arg0 + 0x124) = 0;
    }
    f32 rate = *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x368);
    f32 scale = rate / lbl_805E4860;
    Vec3f *accel = (Vec3f *) ((char *) arg0 + 0x2C);
    PSVECScale(accel, accel, scale);
    if (arg0->unkD8 != 0) {
        HSD_JObj *j = arg0->unkD4;
        Vec3f *pos4 = CallV00(arg0);
        SetTranslate_G1(j, pos4);
    }
}

extern "C" void kar_a2d_kurakko__near_8036df38(KurakkoObj *arg0, u32 arg1) {
    if (*(u16 *) ((char *) arg0 + 0x7A) == 0) {
        char *cfg = (char *) TopRideItem_GetDataBase();
        kar_a2d_effecthandle__near_8037b33c((char *) arg0 + 0x7C, 0);
        Vec3f *pos = CallV00(arg0);
        HSD_JObj *j = arg0->unkD4;
        HSD_JObjClearFlagsAll(j, 0x10);
        HSD_JObjReqAnimAll(j, lbl_805E4850);
        arg0->unkD8 = 1;
        j->translate = *(Vec *) pos;
        *(u16 *) ((char *) arg0 + 0x7A) = 1U;

        Vec3f up = { lbl_805E4850, lbl_805E4854, lbl_805E4850 };
        Vec3f cross;
        Vec3f *accel = (Vec3f *) ((char *) arg0 + 0x2C);
        PSVECCrossProduct(&cross, accel, &up);
        if (PSVECMag(&cross) != lbl_805E4850) {
            PSVECNormalize(&cross, &cross);
        }

        f32 rnd = HSD_Randf() - lbl_805E4870;
        f32 spread = *(f32 *) (cfg + 0x360) * rnd;
        f32 a1 = fn_80296264(lbl_805E4854);
        f32 a2 = fn_80296264(lbl_805E4854) * a1;
        f32 a3 = fn_80296264(lbl_805E4854) * a2;
        f32 baseA = lbl_805E4890 * a3;
        f32 b1 = fn_80296264(lbl_805E4854);
        f32 b2 = fn_80296264(lbl_805E4854) * b1;
        f32 b3 = fn_80296264(lbl_805E4854) * b2;
        f32 baseB = kar_a2d_kurakko__near_8036e2fc((spread * baseA) / (lbl_805E4854 * b3));

        Vec3f dir = cross;
        PSVECScale(&dir, &dir, *(f32 *) (cfg + 0x340));
        PSVECScale(&dir, &dir, baseB);

        Vec3f p2 = *CallV00(arg0);
        PSVECAdd(&p2, &p2, &dir);
        void *particle = (char *) arg0 + 0x13C;
        typedef void (*ParticleFn20)(void *, Vec3f *);
        typedef void (*ParticleFn24)(void *, f32);
        void *pvtable = *(void **) particle;
        (*(ParticleFn20 *) ((char *) pvtable + 0x20))(particle, &p2);
        (*(ParticleFn24 *) ((char *) pvtable + 0x24))(particle, *(f32 *) (cfg + 0x340));

        u16 tone = *(u16 *) (cfg + 0x350);
        arg0->pad13c[0x1E] = (char) tone;
        *(u16 *) (arg0->pad13c + 0x1E) = tone;

        f32 c1 = fn_80296264((f32) tone);
        f32 c2 = fn_8029626C(lbl_805E485C) * c1;
        f32 hVal = *(f32 *) (cfg + 0x348) * (lbl_805E4854 * (fn_802D4C30(lbl_805E4858) * c2));
        *(f32 *) (arg0->pad13c + 0x14) = hVal;

        f32 d1 = fn_80296264(lbl_805E4854);
        f32 d2 = fn_80296264(lbl_805E4854) * d1;
        f32 wVal = *(f32 *) (cfg + 0x34C) * (lbl_805E4890 * (fn_80296264(lbl_805E4854) * d2));
        *(f32 *) (arg0->pad13c + 0x18) = wVal;

        *(u16 *) (arg0->pad13c + 0x20) = *(u16 *) (cfg + 0x354);
        *(u16 *) (arg0->pad13c + 0x22) = *(u16 *) (cfg + 0x358);
        *(s32 *) ((char *) arg0 + 0x124) = 1;
        u32 rate = *(u32 *) ((char *) arg0 + 0x1D0);
        if (rate < 4U) {
            *(s16 *) (arg0->pad13c + 0x1C) = (s16) rate;
        }
        kar_a2d_game_audio__near_80379784((char *) arg0 + 0xDC, 0x70016, (char *) arg0 + 0x1C0);
        kar_diag__803ad760((s32) lbl_805DDB80, 0, &lbl_805DB8D8, &lbl_805DB8D0, 0);
        kar_a2d_refract__near_80384f44();
        fn_8038D0A8(&arg0->jobj64, NULL);
        HSD_JObjSetFlagsAll((HSD_JObj *) 0, 0x10);
        arg0->pad1c8[0x1] = 0;
        *(s32 *) ((char *) arg0 + 0x24) = 0;
    }
}

extern "C" f32 kar_a2d_kurakko__near_8036e2fc(f32 farg0) {
    f32 x = farg0;
    if (x == lbl_805E4850) {
        return lbl_805E4850;
    }
    s32 neg = 0;
    if (x < lbl_805E4850) {
        x = -x;
        neg = 1;
    }
    while (x > (f32) lbl_805E48E0) {
        x = (f32) ((f64) x - lbl_805E48E0);
    }
    f32 result;
    if (x <= (f32) lbl_805E48E8) {
        if (x <= (f32) lbl_805E48F0) {
            if (x <= (f32) lbl_805E4918) {
                f32 x2 = x * x;
                result = x * (lbl_805E4854 - (x2 * -((x2 * -((lbl_805E4900 * x2) - lbl_805E48FC)) - lbl_805E48F8)));
            } else {
                f32 y = (f32) (lbl_805E48F0 - (f64) x);
                f32 y2 = y * y;
                result = lbl_805E4904 - (y2 * -((y2 * -((lbl_805E4910 * y2) - lbl_805E490C)) - lbl_805E4908));
            }
        } else {
            f32 y = (f32) (lbl_805E48E8 - (f64) x);
            if (y <= (f32) lbl_805E4918) {
                f32 y2 = y * y;
                result = y * (lbl_805E4854 - (y2 * -((y2 * -((lbl_805E4900 * y2) - lbl_805E48FC)) - lbl_805E48F8)));
            } else {
                f32 z = (f32) (lbl_805E48F0 - (f64) y);
                f32 z2 = z * z;
                result = lbl_805E4904 - (z2 * -((z2 * -((lbl_805E4910 * z2) - lbl_805E490C)) - lbl_805E4908));
            }
        }
    } else {
        f32 y = (f32) ((f64) x - lbl_805E48E8);
        f32 sub;
        if (y <= (f32) lbl_805E48F0) {
            if (y <= (f32) lbl_805E4918) {
                f32 y2 = y * y;
                sub = y * (lbl_805E4854 - (y2 * -((y2 * -((lbl_805E4900 * y2) - lbl_805E48FC)) - lbl_805E48F8)));
            } else {
                f32 z = (f32) (lbl_805E48F0 - (f64) y);
                f32 z2 = z * z;
                sub = lbl_805E4904 - (z2 * -((z2 * -((lbl_805E4910 * z2) - lbl_805E490C)) - lbl_805E4908));
            }
        } else {
            f32 z = (f32) (lbl_805E48E8 - (f64) y);
            if (z <= (f32) lbl_805E4918) {
                f32 z2 = z * z;
                sub = z * (lbl_805E4854 - (z2 * -((z2 * -((lbl_805E4900 * z2) - lbl_805E48FC)) - lbl_805E48F8)));
            } else {
                f32 w = (f32) (lbl_805E48F0 - (f64) z);
                f32 w2 = w * w;
                sub = lbl_805E4904 - (w2 * -((w2 * -((lbl_805E4910 * w2) - lbl_805E490C)) - lbl_805E4908));
            }
        }
        result = -sub;
    }
    if (neg) {
        return -result;
    }
    return result;
}

extern "C" void fn_8036E748(void *arg0, void *arg1) {
    f32 *out = (f32 *) ((char *) arg0 + 0x1B4);
    f32 *in = (f32 *) ((char *) arg1 + 0x1C);
    out[0] = in[0];
    out[1] = in[1];
    out[2] = in[2];
}

extern "C" void kar_a2d_kurakko__near_8036e764(void *arg0, MatchMemFn arg1) {
    MatchNodeBase *sentinel = (MatchNodeBase *) ((char *) arg0 + 0xC);
    MatchNodeBase *cur = *(MatchNodeBase **) ((char *) arg0 + 0x10);
    while (cur != sentinel) {
        if ((cur->*arg1)() != 0) {
            MatchNodeBase *scan = *(MatchNodeBase **) ((char *) cur + 4);
            while (scan != sentinel) {
                if ((scan->*arg1)() != 0) {
                    scan = *(MatchNodeBase **) ((char *) scan + 4);
                    continue;
                }
                break;
            }
            void *result;
            void *a = scan;
            void *b = cur;
            fn_80297828(&result, arg0, &b, &a);
            cur = (MatchNodeBase *) result;
            if (cur != sentinel) {
                continue;
            }
        }
        cur = *(MatchNodeBase **) ((char *) cur + 4);
    }
}

extern "C" void fn_8036E81C(char *arg0) {
    return fn_802978F4((void *) (arg0 - 0x14));
}

extern "C" void fn_8036E824(char *arg0) {
    return fn_802978F4((void *) (arg0 - 0x54));
}

extern "C" void kar_a2d_kurakko__near_8036e82c(void *arg0, u8 arg1) {
    void *sentinel = (char *) arg0 + 0x10;
    void *cur = *(void **) ((char *) arg0 + 0x14);
    while (cur != sentinel) {
        kar_a2d_kurakko__near_8036fa8c((KurakkoObj *) ((char *) cur + 8), arg1);
        cur = *(void **) ((char *) cur + 4);
    }
    Vec3f tmp1 = lbl_804F07EC;
    Vec3f tmp2 = lbl_804F07EC;
    kar_a2d_kurakko__near_80370e24((char *) arg0 + 4, (void *) &tmp1, 0);
}

extern "C" u8 fn_8036E8CC(void *arg0) {
    return *(u8 *) ((char *) arg0 + 0xCC);
}

extern "C" void kar_a2d_kurakko__near_8036e8d4(void *arg0) {
    void *sentinel = (char *) arg0 + 0x10;
    void *cur = *(void **) ((char *) arg0 + 0x14);
    while (cur != sentinel) {
        void *widget = (char *) cur + 0x94;
        void *vtable = *(void **) widget;
        typedef void (*Fn10)(void *);
        (*(Fn10 *) ((char *) vtable + 0x10))(widget);
        cur = *(void **) ((char *) cur + 4);
    }
}

extern "C" void *kar_a2d_kurakko__8036e92c(KurakkoObj *arg0, KartIF *arg1) {
    PreConstruct(arg0, &lbl_804BF0E4);
    ((GameEffectItemBase *) arg0)->Init("PostDrawEffect");
    arg0->unk0 = &lbl_804BF288;
    *(KartIF **) ((char *) arg0 + 0x84) = arg1;
    fn_8038CCAC((char *) arg0 + 0x8C, ((DiagResult *) kar_diag__803ad760((s32) lbl_805DDB50, 0, &lbl_805DB920, &lbl_805DB918, 0))->unk18);
    HSD_JObj *j98 = fn_8038D0A8((HSD_JObj *) ((char *) arg0 + 0x8C), lbl_804BF0E4 + 0x1B0);
    *(HSD_JObj **) ((char *) arg0 + 0x98) = j98;
    HSD_JObj *j9c = fn_8038D0A8((HSD_JObj *) ((char *) arg0 + 0x8C), lbl_804BF0E4 + 0x1C8);
    *(HSD_JObj **) ((char *) arg0 + 0x9C) = j9c;

    void *effect = (char *) arg0 + 0xEC;
    *(u8 *) ((char *) arg0 + 0xCC) = 0;
    *(s32 *) ((char *) arg0 + 0xD0) = 0;
    PreConstruct(effect, &lbl_804BDF2C);
    typedef void (*Fn10)(void *, s32);
    void *evt = *(void **) effect;
    (*(Fn10 *) ((char *) evt + 0x10))(effect, 0);
    *(void **) effect = &lbl_804BDF70;
    kar_a2d_effecthandle__8037b028(effect, -1, 0, 0, 0, 0);

    void *gen = (char *) arg0 + 0x138;
    PreConstruct(gen, &lbl_804BF4DC);
    typedef void (*Fn10b)(void *);
    void *gvt = *(void **) gen;
    (*(Fn10b *) ((char *) gvt + 0x10))(gen);
    *(void **) gen = &lbl_804D7700;
    *(s32 *) ((char *) gen + 0xC) = 0;
    *(s32 *) ((char *) gen + 0x20) = 0;
    void *nameBuf = lbl_804BF1B0 + 0x38;
    *(s32 *) ((char *) gen + 0x10) = 0;
    *(s32 *) ((char *) gen + 0x14) = 0;
    *(s32 *) ((char *) gen + 0x18) = 0;
    *(s32 *) ((char *) gen + 0x1C) = 0;
    *(void **) ((char *) gen + 0x24) = &lbl_804F5208;
    *(void **) ((char *) gen + 0x24) = &lbl_804BF3C0;
    *(f32 *) ((char *) gen + 0x28) = 0.0f;
    *(f32 *) ((char *) gen + 0x2C) = 0.0f;
    *(f32 *) ((char *) gen + 0x30) = 0.0f;
    *(f32 *) ((char *) gen + 0x34) = 1.0f;
    *(f32 *) ((char *) gen + 0x38) = 0.0f;
    *(f32 *) ((char *) gen + 0x3C) = 0.0f;
    *(f32 *) ((char *) gen + 0x40) = 1.0f;
    *(f32 *) ((char *) gen + 0x44) = 1.0f;
    *(void **) gen = &lbl_804BF1B0;
    *(void **) ((char *) gen + 0x24) = nameBuf;
    *(s32 *) ((char *) gen + 0x48) = 0x3C;
    kar_a2d_wipeeffect__near_8037e9c8((char *) arg0 + 0x184, nameBuf, &lbl_804BF1B0, &lbl_804BF3C0, &lbl_804F5208, 0, 0.0f);
    kar_a2d_game_audio__near_80379398((char *) arg0 + 0x1AC);

    void *w = (char *) arg0 + 0x1E8;
    PreConstruct(w, &lbl_804BE238);
    typedef void (*Fn10c)(void *);
    void *wvt = *(void **) w;
    (*(Fn10c *) ((char *) wvt + 0x10))(w);
    *(void **) w = &lbl_804BE210;
    *(s32 *) ((char *) w + 0xC) = -1;

    if (j98 == NULL) {
        __assert(lbl_804BF0E4 + 0x1D8, 0x2E, lbl_804BF0E4 + 0x1E8);
    }
    if (j9c == NULL) {
        __assert(lbl_804BF0E4 + 0x1D8, 0x2F, lbl_804BF0E4 + 0x1F8);
    }
    kar_a2d_kurakko__near_8036edd8(arg0);
    kar_a2d_kurakko__near_8036f1b8(arg0);
    return arg0;
}

extern "C" void *kar_a2d_kurakko__near_8036eba4(KurakkoObj *arg0, KurakkoObj *arg1) {
    PreConstruct(arg0, &lbl_804BF0E4);
    ((GameEffectItemBase *) arg0)->Init("PostDrawEffect");
    arg0->unk0 = &lbl_804BF288;
    *(s32 *) ((char *) arg0 + 0x84) = *(s32 *) ((char *) arg1 + 0x84);
    *(void **) ((char *) arg0 + 0x8C) = &lbl_804F4E38;
    void *w90 = *(void **) ((char *) arg1 + 0x90);
    *(void **) ((char *) arg0 + 0x90) = w90;
    *(s32 *) ((char *) arg0 + 0x94) = *(s32 *) ((char *) arg1 + 0x94);
    if (w90 != NULL) {
        u16 *cnt = (u16 *) ((char *) w90 + 4);
        *cnt = (u16) (*cnt + 1);
        if (*cnt == 0xFFFFU) {
            __assert(lbl_804BF0E4 + 0x204, 0x5D, lbl_804BF0E4 + 0x210);
        }
    }
    HSD_JObj *j98 = fn_8038D0A8((HSD_JObj *) ((char *) arg0 + 0x8C), lbl_804BF0E4 + 0x1B0);
    *(HSD_JObj **) ((char *) arg0 + 0x98) = j98;
    HSD_JObj *j9c = fn_8038D0A8((HSD_JObj *) ((char *) arg0 + 0x8C), lbl_804BF0E4 + 0x1C8);
    *(HSD_JObj **) ((char *) arg0 + 0x9C) = j9c;
    u8 cc = *(u8 *) ((char *) arg1 + 0xCC);
    *(s32 *) ((char *) arg0 + 0xA0) = *(s32 *) ((char *) arg1 + 0xA0);
    *(u8 *) ((char *) arg0 + 0xCC) = cc;
    *(s32 *) ((char *) arg0 + 0xD0) = *(s32 *) ((char *) arg1 + 0xD0);
    kar_a2d_game_effect__near_8037afd0((char *) arg0 + 0xEC, cc);

    void *gen = (char *) arg0 + 0x138;
    PreConstruct(gen, &lbl_804BF4DC);
    typedef void (*Fn10b)(void *);
    void *gvt = *(void **) gen;
    (*(Fn10b *) ((char *) gvt + 0x10))(gen);
    *(void **) gen = &lbl_804D7700;
    *(s32 *) ((char *) gen + 0xC) = 0;
    *(s32 *) ((char *) gen + 0x20) = 0;
    void *nameBuf = lbl_804BF1B0 + 0x38;
    *(s32 *) ((char *) gen + 0x10) = 0;
    *(s32 *) ((char *) gen + 0x14) = 0;
    *(s32 *) ((char *) gen + 0x18) = 0;
    *(s32 *) ((char *) gen + 0x1C) = 0;
    *(void **) ((char *) gen + 0x24) = &lbl_804F5208;
    *(void **) ((char *) gen + 0x24) = &lbl_804BF3C0;
    *(f32 *) ((char *) gen + 0x28) = 0.0f;
    *(f32 *) ((char *) gen + 0x2C) = 0.0f;
    *(f32 *) ((char *) gen + 0x30) = 0.0f;
    *(f32 *) ((char *) gen + 0x34) = 1.0f;
    *(f32 *) ((char *) gen + 0x38) = 0.0f;
    *(f32 *) ((char *) gen + 0x3C) = 0.0f;
    *(f32 *) ((char *) gen + 0x40) = 1.0f;
    *(f32 *) ((char *) gen + 0x44) = 1.0f;
    *(void **) gen = &lbl_804BF1B0;
    *(void **) ((char *) gen + 0x24) = nameBuf;
    *(s32 *) ((char *) gen + 0x48) = 0x3C;
    kar_a2d_wipeeffect__near_8037e9c8((char *) arg0 + 0x184, nameBuf, &lbl_804BF1B0, &lbl_804BF3C0, &lbl_804F5208, 0, 0.0f);
    kar_a2d_game_audio__near_803795ac((char *) arg0 + 0x1AC, (char *) arg1 + 0x1AC);

    void *w = (char *) arg0 + 0x1E8;
    PreConstruct(w, &lbl_804BE238);
    typedef void (*Fn10c)(void *);
    void *wvt = *(void **) w;
    (*(Fn10c *) ((char *) wvt + 0x10))(w);
    *(void **) w = &lbl_804BE210;
    *(s32 *) ((char *) w + 0xC) = -1;

    kar_a2d_kurakko__near_8036edd8(arg0);
    kar_a2d_kurakko__near_8036f1b8(arg0);
    return arg0;
}

extern "C" void kar_a2d_kurakko__near_8036edd8(KurakkoObj *arg0) {
    KartIF **kif = (KartIF **) ((char *) arg0 + 0x84);
    Vec3f *pos = (*kif)->v74();
    Vec3f tr = { pos->x, pos->y, pos->z };
    tr.y += 1.0f;
    HSD_JObj *j = fn_8038D0A8((HSD_JObj *) ((char *) arg0 + 0x8C), NULL);
    SetTranslate_G2(j, &tr);

    Vec3f sc = { 1.0f, 1.0f, 1.0f };
    PSVECScale(&sc, &sc, *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x548));
    HSD_JObj *j2 = fn_8038D0A8((HSD_JObj *) ((char *) arg0 + 0x8C), NULL);
    SetScale_G2(j2, &sc);

    *(s32 *) ((char *) arg0 + 0x88) = 0;
    f32 rad = *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x53C);
    *(f32 *) ((char *) arg0 + 0xC0) = 0.017453292f * rad;
    *(f32 *) ((char *) arg0 + 0xC4) = 0.0f;
    *(f32 *) ((char *) arg0 + 0xC8) = 0.0f;
    HSD_JObj *j9c = *(HSD_JObj **) ((char *) arg0 + 0x9C);
    Vec3f a4 = { j9c->translate.x, j9c->translate.y, j9c->translate.z };
    *(Vec3f *) ((char *) arg0 + 0xA4) = a4;
    *(Vec3f *) ((char *) arg0 + 0xB0) = a4;
    arg0->unkD8 = 0;
    *(s32 *) ((char *) arg0 + 0x144) = 0;
    *(f32 *) ((char *) arg0 + 0xBC) = 0.0f;

    struct SixVec { f32 a0, a4, a8, ac, b0, b4; };
    SixVec *box = (SixVec *) kar_diag__803ad760((s32) lbl_805DDBC4, 0, &lbl_805DB938, &lbl_805DB930, 0);
    f32 x0 = box->a0, y0 = box->a4, x1 = box->a8, y1 = box->ac;
    f32 dx = x1 - x0;
    f32 dz = y1 - y0;
    f32 mag2 = (dx * dx) + (dz * dz);
    f32 mag = 0.0f;
    if (mag2 > 0.0f) {
        f64 e0 = __frsqrte(mag2);
        f64 e1 = 0.5 * e0 * -(((f64) mag2 * (e0 * e0)) - 3.0);
        f64 e2 = 0.5 * e1 * -(((f64) mag2 * (e1 * e1)) - 3.0);
        mag = (f32) ((f64) mag2 * (0.5 * e2 * -(((f64) mag2 * (e2 * e2)) - 3.0)));
    }
    *(f32 *) ((char *) arg0 + 0xE8) = 0.5f * mag;
    Vec3f mid = { x0 + x1, y0, box->b0 };
    Vec3f half;
    PSVECScale(&half, &mid, 0.5f);
    *(Vec3f *) ((char *) arg0 + 0xDC) = half;
    f32 e4 = *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x558);
    f32 *pE4 = (f32 *) ((char *) arg0 + 0xE4);
    *pE4 = *pE4 + e4;
    f32 minE4 = *(f32 *) ((char *) fn_803124F0(e4) + 0x1C);
    if (*pE4 < minE4) {
        *pE4 = minE4;
    }
}

extern "C" void kar_a2d_kurakko__near_8036f1b8(KurakkoObj *arg0) {
    *(u32 *) ((char *) arg0 + 0xA0) = 0;
    f32 rate = *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x540);
    *(u32 *) ((char *) arg0 + 0xD0) = (u32) rate;
    fn_8038D0E8((char *) arg0 + 0x8C, &lbl_804F08DC, 1, rate);
    kar_a2d_kurakko__near_8036f214(arg0);
}

extern "C" void kar_a2d_kurakko__near_8036f214(KurakkoObj *arg0) {
    f32 spread = *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x550);
    HSD_JObj *j = fn_8038D0A8((HSD_JObj *) ((char *) arg0 + 0x8C), NULL);
    f32 *base = (f32 *) ((char *) arg0 + 0xC);
    base[0] = j->translate.x;
    base[1] = j->translate.y;
    base[2] = j->translate.z;
    f32 *base2 = (f32 *) ((char *) arg0 + 0x18);
    base2[0] = base[0];
    base2[1] = base[1] + 2.0f;
    base2[2] = base[2];
    f32 depth = *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x554);
    f32 r = HSD_Randf();
    f32 *end = (f32 *) ((char *) arg0 + 0x54);
    f32 *dc = (f32 *) ((char *) arg0 + 0xDC);
    end[0] = dc[0];
    end[1] = dc[1];
    f32 shift = 2.0f * (r - 0.5f) * depth;
    end[2] = dc[2];
    end[0] += shift;
    end[1] += spread + 1.0f;

    f32 *p2 = (f32 *) ((char *) arg0 + 0x60);
    p2[0] = dc[0]; p2[1] = dc[1]; p2[2] = dc[2];
    p2[0] += shift;
    p2[1] += spread + 2.0f;

    f32 *p3 = (f32 *) ((char *) arg0 + 0x6C);
    p3[0] = dc[0]; p3[1] = dc[1]; p3[2] = dc[2];
    p3[0] += shift;
    p3[1] += spread + 3.0f;

    f32 *p4 = (f32 *) ((char *) arg0 + 0x78);
    p4[0] = dc[0]; p4[1] = dc[1]; p4[2] = dc[2];
    p4[0] += shift;
    p4[1] += spread + 4.0f;

    f32 sideSign = (HSD_Randi(2) != 0) ? 1.0f : -1.0f;
    f32 *mid = (f32 *) ((char *) arg0 + 0x18);
    f32 sway = sideSign;
    f32 zsway = 0.0f;
    s32 i = 2;
    do {
        Vec3f swayVec = { sway, 0.0f, zsway };
        kar_lbvector_rotate_about_cardinal_axis(&swayVec, 2, (0.7853982f * (2.0f * (HSD_Randf() - 0.5f))) + 3.1415927f);
        sway = swayVec.x;
        zsway = swayVec.z;
        if (zsway < 0.0f) {
            zsway *= 0.5f;
        }
        f32 span = (3.0f * HSD_Randf()) + 20.0f;
        f32 t = (f32) i / 6.0f;
        i += 1;
        f32 s1 = 1.0f - t;
        mid[0] = (sway * span) + ((s1 * base[0]) + (t * end[0]));
        mid[1] = (spread * t) + ((s1 * base[1]) + (t * end[1]));
        mid[2] = (zsway * span) + ((s1 * base[2]) + (t * end[2]));
        mid += 3;
    } while (i < 6);
}

#define FU8(p, o) (*(u8 *) ((char *) (p) + (o)))
#define FS8(p, o) (*(s8 *) ((char *) (p) + (o)))
#define FU16(p, o) (*(u16 *) ((char *) (p) + (o)))
#define FS16(p, o) (*(s16 *) ((char *) (p) + (o)))
#define FU32(p, o) (*(u32 *) ((char *) (p) + (o)))
#define FS32(p, o) (*(s32 *) ((char *) (p) + (o)))
#define FF32(p, o) (*(f32 *) ((char *) (p) + (o)))
#define FP(p, o) (*(void **) ((char *) (p) + (o)))
#define FV3(p, o) (*(Vec3f *) ((char *) (p) + (o)))

static inline void SetTransFa8c(void *arg0, Vec3f *v) {
    HSD_JObj *j = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
    SetTranslate_G2(j, v);
}
static inline void SetScaleFa8c(void *arg0, Vec3f *v) {
    HSD_JObj *j = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
    SetScale_G2(j, v);
}

extern "C" void kar_a2d_kurakko__near_8036fa8c(KurakkoObj *arg0, u8 arg1) {
    const char *nameBase = "PostDrawEffect";
    Vec4f rot;
    if (kar_a2d_game_lib__near_80289374((f32 *) &rot, (char *) arg0 + 0xC0, (void *) nameBase) != 0) {
        HSD_JObj *j = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
        SetRotate_G2(j, &rot);
    }
    s32 state = FS32(arg0, 0xA0);
    switch (state) {
    case 0: {
        f32 t = 1.0f - ((f32) FU32(arg0, 0xD0) / *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x540));
        f32 tt = t;
        if (t == 1.0f) {
            tt = 0.999999f;
        }
        f32 idxF = 7.0f * tt;
        u32 idx = (u32) idxF;
        Vec3f p;
        splGetCardinalPoint(&p, (char *) arg0 + (idx * 0xC) + 0xC, idxF - (f32) idx);
        SetTransFa8c(arg0, &p);
        Vec3f s = *(Vec3f *) &lbl_8048A580;
        f32 rate = *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x548);
        PSVECScale(&s, &s, (t * *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x54C)) + rate);
        SetScaleFa8c(arg0, &s);
        if (FU32(arg0, 0xD0) == 0xC) {
            fn_8038D0E8((char *) arg0 + 0x8C, (void *) (nameBase + 0x32C), 1, 0.0f);
        }
        u32 timer = FU32(arg0, 0xD0);
        if (timer != 0) {
            FU32(arg0, 0xD0) = timer - 1;
        } else {
            FS32(arg0, 0xA0) = 1;
            FU32(arg0, 0x194) = 0x8C;
            FU32(arg0, 0x190) = 0x8C;
            FU8(arg0, 0x198) = 1;
            FU32(arg0, 0xD4) = 0U;
        }
        break;
    }
    case 1: {
        fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
        f32 t0 = kar_a2d_game_lib__near_802899d0();
        fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
        if ((kar_a2d_game_lib__near_80289928() - t0) == 1.0f) {
            f32 dur = *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x544);
            FU32(arg0, 0xD0) = (u32) dur;
            HSD_JObj *j = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
            FF32(arg0, 0xC) = j->translate.x;
            FF32(arg0, 0x10) = j->translate.y;
            FF32(arg0, 0x14) = j->translate.z;
            FS32(arg0, 0xA0) = 2;
            fn_8038D0E8((char *) arg0 + 0x8C, (void *) (nameBase + 0x278), 1, 0.0f);
            void *best = NULL;
            u32 bestVal = 0xFFFFFFFFU;
            typedef s32 (*FnBC0)(void *);
            typedef s32 (*Fn40)(void *);
            typedef void *(*Fn24)(void *);
            void *cur = kar_diag__803ad760((s32) lbl_805DDAB8, 0, &lbl_805DB960, &lbl_805DB958, 0);
            while (cur != NULL) {
                void *vt = *(void **) cur;
                if (cur != (void *) FP(arg0, 0x84) && cur != FP(arg0, 0x88) &&
                    (*(FnBC0 *) ((char *) vt + 0xC0))(cur) != 0 &&
                    (u32) (*(Fn40 *) ((char *) vt + 0x40))(cur) < bestVal) {
                    best = cur;
                    bestVal = (u32) (*(Fn40 *) ((char *) vt + 0x40))(cur);
                }
                cur = (*(Fn24 *) ((char *) vt + 0x24))(cur);
            }
            FP(arg0, 0x88) = best;
            FF32(arg0, 0xBC) = 0.0f;
        }
        break;
    }
    case 2: {
        void *kif88 = FP(arg0, 0x88);
        if (kif88 != NULL) {
            Vec3f *pos = ((KartIF *) kif88)->v74();
            f32 dur = *(f32 *) ((char *) fn_802DE0E4(pos->x, 0.0f) + 0x544);
            f32 t = (f32) FU32(arg0, 0xD0) / dur;
            f32 s = 1.0f - t;
            f32 s2 = s * s;
            Vec3f d;
            PSVECSubtract(pos, (Vec3f *) ((char *) arg0 + 0xC), &d);
            PSVECScale(&d, &d, (1.5f * s2) - (0.5f * s * s2));
            PSVECAdd(&d, (Vec3f *) ((char *) arg0 + 0xC), &d);
            f32 minZ = *(f32 *) ((char *) fn_803124F0(0.0f) + 0x1C);
            if (d.z < minZ) {
                d.z = minZ;
            }
            SetTransFa8c(arg0, &d);
        }
        u32 timer = FU32(arg0, 0xD0);
        if (timer != 0) {
            FU32(arg0, 0xD0) = timer - 1;
        } else {
            void *kif = FP(arg0, 0x88);
            s32 ok;
            if (kif == NULL) {
                ok = 0;
            } else {
                void *vt = *(void **) kif;
                typedef s32 (*FnBC)(void *);
                typedef u32 (*Fn28)(void *);
                if ((*(FnBC *) ((char *) vt + 0xBC))(kif) != 0 &&
                    (*(Fn28 *) ((char *) vt + 0x28))(kif) == 0x1CU) {
                    ok = 1;
                } else {
                    ok = 0;
                }
            }
            if (ok != 0) {
                FS32(arg0, 0xA0) = 4;
                kar_a2d_effect_slideblur__near_80382bf4((s32 *) ((char *) arg0 + 0x1A8), 2, 0);
                fn_8038D0E8((char *) arg0 + 0x8C, (void *) (nameBase + 0x288), 1, 0.0f);
            } else if (kif == NULL) {
                FU32(arg0, 0xD0) = 0xA0U;
                HSD_JObj *j = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
                FF32(arg0, 0xC) = j->translate.x;
                FF32(arg0, 0x10) = j->translate.y;
                FF32(arg0, 0x14) = j->translate.z;
                FS32(arg0, 0xA0) = 5;
                fn_8038D0E8((char *) arg0 + 0x8C, (void *) (nameBase + 0x278), 1, 0.0f);
                FU32(arg0, 0x194) = 0x50;
                FU32(arg0, 0x190) = 0x50;
                FU8(arg0, 0x198) = 0;
            } else {
                FS32(arg0, 0xD0) = 0x258;
                FS32(arg0, 0xA0) = 3;
            }
        }
        break;
    }
    case 3: {
        void *kif = FP(arg0, 0x88);
        s32 ok;
        if (kif == NULL) {
            ok = 0;
        } else {
            void *vt = *(void **) kif;
            typedef s32 (*FnBC)(void *);
            typedef u32 (*Fn28)(void *);
            if ((*(FnBC *) ((char *) vt + 0xBC))(kif) != 0 &&
                (*(Fn28 *) ((char *) vt + 0x28))(kif) == 0x1CU) {
                ok = 1;
            } else {
                ok = 0;
            }
        }
        if (ok != 0) {
            FS32(arg0, 0xA0) = 4;
            kar_a2d_effect_slideblur__near_80382bf4((s32 *) ((char *) arg0 + 0x1A8), 2, 0);
            fn_8038D0E8((char *) arg0 + 0x8C, (void *) (nameBase + 0x288), 1, 0.0f);
        } else {
            u32 timer = FU32(arg0, 0xD0);
            if (timer != 0) {
                FU32(arg0, 0xD0) = timer - 1;
            } else {
                f32 dur = *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x544);
                FU32(arg0, 0xD0) = (u32) dur;
                HSD_JObj *j = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
                FF32(arg0, 0xC) = j->translate.x;
                FF32(arg0, 0x10) = j->translate.y;
                FF32(arg0, 0x14) = j->translate.z;
                FS32(arg0, 0xA0) = 2;
                fn_8038D0E8((char *) arg0 + 0x8C, (void *) (nameBase + 0x278), 1, 0.0f);
                void *best = NULL;
                u32 bestVal = 0xFFFFFFFFU;
                typedef s32 (*FnBC0)(void *);
                typedef s32 (*Fn40)(void *);
                typedef void *(*Fn24)(void *);
                void *cur = kar_diag__803ad760((s32) lbl_805DDAB8, 0, &lbl_805DB960, &lbl_805DB958, 0);
                while (cur != NULL) {
                    void *cvt = *(void **) cur;
                    if (cur != (void *) FP(arg0, 0x84) && cur != FP(arg0, 0x88) &&
                        (*(FnBC0 *) ((char *) cvt + 0xC0))(cur) != 0 &&
                        (u32) (*(Fn40 *) ((char *) cvt + 0x40))(cur) < bestVal) {
                        best = cur;
                        bestVal = (u32) (*(Fn40 *) ((char *) cvt + 0x40))(cur);
                    }
                    cur = (*(Fn24 *) ((char *) cvt + 0x24))(cur);
                }
                FP(arg0, 0x88) = best;
                FF32(arg0, 0xBC) = 0.0f;
            }
            f32 minZ = *(f32 *) ((char *) fn_803124F0(0.0f) + 0x1C);
            void *kif2 = FP(arg0, 0x88);
            f32 z = ((KartIF *) kif2)->v74()->z;
            if (z < minZ) {
                z = minZ;
            }
            Vec3f xv3 = *((KartIF *) kif2)->v74();
            HSD_JObj *j2 = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
            SetTranslateJObjOnly_G2(j2, &xv3);
            HSD_JObj *j3 = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
            SetRotationZOnly_G3(j3, z);
        }
        break;
    }
    case 4: {
        f32 minZ = *(f32 *) ((char *) fn_803124F0(0.0f) + 0x1C);
        void *kif = FP(arg0, 0x88);
        f32 z = ((KartIF *) kif)->v74()->z;
        if (z < minZ) {
            z = minZ;
        }
        Vec3f xv = *((KartIF *) kif)->v74();
        HSD_JObj *j2 = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
        SetTranslateJObjOnly_G2(j2, &xv);
        HSD_JObj *j3 = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
        SetRotationZOnly_G3(j3, z);

        FS32(arg0, 0x144) = 1;
        HSD_JObj *j4 = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
        Vec3f tr4 = { j4->translate.x, j4->translate.y, j4->translate.z };
        void *kif88 = FP(arg0, 0x88);
        Vec3f *kp = ((KartIF *) kif88)->v74();
        Vec3f diff;
        diff.x = kp->y - 1.0f;
        diff.y = kp->z;
        diff.z = kp->x;
        typedef void (*Fn28c)(void *, Vec3f *, f32, f32);
        typedef void (*Fn2Cc)(void *, f32, f32);
        void *pw = (char *) arg0 + 0x15C;
        void *pvt = *(void **) pw;
        (*(Fn28c *) ((char *) pvt + 0x28))(pw, &tr4, diff.z, diff.x);
        (*(Fn2Cc *) ((char *) pvt + 0x2C))(pw, 1.0f, 1.0f);
        FS32(arg0, 0x180) = 0xA;
        fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
        f32 t2 = kar_a2d_game_lib__near_802899d0();
        fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
        if ((kar_a2d_game_lib__near_80289928() - t2) == 1.0f) {
            FS32(arg0, 0x144) = 0;
            u32 rd4 = FU32(arg0, 0xD4);
            s32 lt = rd4 < (u32) *(u32 *) ((char *) TopRideItem_GetDataBase() + 0x564);
            FU32(arg0, 0xD4) = rd4 + 1;
            f32 chance = *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x560);
            if (lt == 0 || HSD_Randf() > (0.01f * chance)) {
                FU32(arg0, 0xD0) = 0xA0U;
                HSD_JObj *j5 = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
                FF32(arg0, 0xC) = j5->translate.x;
                FF32(arg0, 0x10) = j5->translate.y;
                FF32(arg0, 0x14) = j5->translate.z;
                FS32(arg0, 0xA0) = 5;
                fn_8038D0E8((char *) arg0 + 0x8C, (void *) (nameBase + 0x278), 1, 0.0f);
                FU32(arg0, 0x194) = 0x50;
                FU32(arg0, 0x190) = 0x50;
                FU8(arg0, 0x198) = 0;
            } else {
                f32 dur = *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x544);
                FU32(arg0, 0xD0) = (u32) dur;
                HSD_JObj *j6 = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
                FF32(arg0, 0xC) = j6->translate.x;
                FF32(arg0, 0x10) = j6->translate.y;
                FF32(arg0, 0x14) = j6->translate.z;
                FS32(arg0, 0xA0) = 2;
                fn_8038D0E8((char *) arg0 + 0x8C, (void *) (nameBase + 0x278), 1, 0.0f);
                void *best = NULL;
                u32 bestVal = 0xFFFFFFFFU;
                typedef s32 (*FnBC0)(void *);
                typedef s32 (*Fn40)(void *);
                typedef void *(*Fn24)(void *);
                void *cur = kar_diag__803ad760((s32) lbl_805DDAB8, 0, &lbl_805DB960, &lbl_805DB958, 0);
                while (cur != NULL) {
                    void *cvt = *(void **) cur;
                    if (cur != (void *) FP(arg0, 0x84) && cur != FP(arg0, 0x88) &&
                        (*(FnBC0 *) ((char *) cvt + 0xC0))(cur) != 0 &&
                        (u32) (*(Fn40 *) ((char *) cvt + 0x40))(cur) < bestVal) {
                        best = cur;
                        bestVal = (u32) (*(Fn40 *) ((char *) cvt + 0x40))(cur);
                    }
                    cur = (*(Fn24 *) ((char *) cvt + 0x24))(cur);
                }
                FP(arg0, 0x88) = best;
                FF32(arg0, 0xBC) = 0.0f;
            }
        }
        break;
    }
    case 5: {
        Vec3f dc = FV3(arg0, 0xDC);
        Vec3f base = FV3(arg0, 0xC);
        f32 dt = FF32(arg0, 0xD0);
        f32 t = 1.0f - (dt / 160.0f);
        f32 t2 = t * t;
        Vec3f d;
        PSVECSubtract(&dc, &base, &d);
        PSVECScale(&d, &d, (1.5f * t2) - (0.5f * t * t2));
        PSVECAdd(&d, &base, &d);
        SetTransFa8c(arg0, &d);
        u32 timer = FU32(arg0, 0xD0);
        if (timer != 0) {
            FU32(arg0, 0xD0) = timer - 1;
        } else {
            FU8(arg0, 0xCC) = 1;
        }
        if (FU32(arg0, 0xD0) <= 0x28U) {
            Vec3f s = *(Vec3f *) &lbl_8048A58C;
            f32 rate2 = *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x54C);
            f32 rate1 = *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x548) + rate2;
            PSVECScale(&s, &s, ((0.1f + (f32) FU32(arg0, 0xD0)) / 40.0f) * rate1);
            SetScaleFa8c(arg0, &s);
        }
        break;
    }
    }
    fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
    HSD_JObjAnimAll((HSD_JObj *) 0);
    kar_a2d_kurakko__near_8036f57c(arg0);
    if (FS32(arg0, 0xA0) == 4) {
        void *kif = FP(arg0, 0x88);
        if (kif != NULL) {
            HSD_JObj *j = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
            Vec4f rot2 = { j->rotate.x, j->rotate.y, j->rotate.z, j->rotate.w };
            HSD_JObj *j2 = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
            Vec3f *kp = ((KartIF *) kif)->v74();
            Vec3f d;
            PSVECSubtract((Vec3f *) &j2->translate, kp, &d);
            kar_a2d_game_lib__near_80289158(&d, (Vec3f *) &rot2);
            HSD_JObj *j3 = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
            PSVECScale(&d, &d, j3->scale.x);
            HSD_JObj *j98 = *(HSD_JObj **) ((char *) arg0 + 0x98);
            SetTranslate_G2(j98, &d);
        }
    }
    if (arg1 == 0 && (s8) ((DiagResult *) kar_diag__803ad760((s32) lbl_805DDB50, 0, &lbl_805DB920, &lbl_805DB918, 0))->pad0[0x1C] == 0) {
        u32 timer8 = FU32(arg0, 0xD8);
        f32 flash = 0.0f;
        if (timer8 <= 0x78U) {
            flash = 1.0f - ((f32) timer8 / 120.0f);
        } else if (FS32(arg0, 0xA0) == 5) {
            u32 timerD0 = FU32(arg0, 0xD0);
            if (timerD0 <= 0x78U) {
                flash = 1.0f - ((f32) timerD0 / 120.0f);
            }
        }
        *(f32 *) ((char *) kar_diag__803ad760((s32) lbl_805DDB78, 0, &lbl_805DB978, &lbl_805DB968, 0) + 8) = flash;
    }
    FU32(arg0, 0xD8) = FU32(arg0, 0xD8) + 1;
}

extern "C" void kar_a2d_kurakko__near_8036f57c(KurakkoObj *arg0) {
    s32 state = FS32(arg0, 0xA0);
    switch (state) {
    case 4:
    case 2: {
        if (FP(arg0, 0x88) != NULL) {
            FF32(arg0, 0xBC) = FF32(arg0, 0xBC) + 0.01f;
            if (FF32(arg0, 0xBC) > 1.0f) {
                FF32(arg0, 0xBC) = 1.0f;
            }
        } else {
            FF32(arg0, 0xBC) = FF32(arg0, 0xBC) - 0.01f;
            if (FF32(arg0, 0xBC) < 0.0f) {
                FF32(arg0, 0xBC) = 0.0f;
            }
        }
        HSD_JObj *j9c = *(HSD_JObj **) ((char *) arg0 + 0x9C);
        f32 t = FF32(arg0, 0xBC);
        void *kif = FP(arg0, 0x88);
        Vec3f cur = { j9c->translate.x, j9c->translate.y, j9c->translate.z };
        f32 maxAngle = 0.017453292f * *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x55C);
        HSD_JObj *jr = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
        Vec3f dir;
        if (kif != NULL) {
            HSD_JObj *jbase = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
            Vec3f *kp = ((KartIF *) kif)->v74();
            Vec3f d;
            PSVECSubtract((Vec3f *) &jbase->translate, kp, &d);
            kar_a2d_game_lib__near_80289158(&d, (Vec3f *) &jr->rotate);
            PSVECNormalize(&d, &d);
            dir = d;
        } else {
            dir = FV3(arg0, 0xA4);
        }
        f32 s = 1.0f - t;
        Vec3f blend;
        blend.x = (cur.x * s) + (FF32(arg0, 0xB0) * t);
        blend.y = (cur.y * s) + (FF32(arg0, 0xB4) * t);
        blend.z = (cur.z * s) + (FF32(arg0, 0xB8) * t);
        f32 ang = kar_lbvector_angle_between(&dir, &blend);
        if (ang > maxAngle) {
            ang = maxAngle;
        }
        if (ang > 0.05235988f) {
            Vec3f axis;
            PSVECCrossProduct(&dir, &blend, &axis);
            PSVECNormalize(&axis, &axis);
            kar_lbvector_rotate_about_axis(&blend, &axis, -ang * t);
            SetTranslate_G2(j9c, &blend);
            FV3(arg0, 0xA4) = blend;
            return;
        }
        return;
    }
    case 5: {
        FF32(arg0, 0xBC) = FF32(arg0, 0xBC) - 0.05f;
        if (FF32(arg0, 0xBC) < 0.0f) {
            FF32(arg0, 0xBC) = 0.0f;
        }
        HSD_JObj *j9c = *(HSD_JObj **) ((char *) arg0 + 0x9C);
        f32 t = FF32(arg0, 0xBC);
        void *kif = FP(arg0, 0x88);
        Vec3f cur = { j9c->translate.x, j9c->translate.y, j9c->translate.z };
        f32 maxAngle = 0.017453292f * *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x55C);
        HSD_JObj *jr = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
        Vec3f dir;
        if (kif != NULL) {
            HSD_JObj *jbase = fn_8038D0A8((HSD_JObj *) FP(arg0, 0x8C), NULL);
            Vec3f *kp = ((KartIF *) kif)->v74();
            Vec3f d;
            PSVECSubtract((Vec3f *) &jbase->translate, kp, &d);
            kar_a2d_game_lib__near_80289158(&d, (Vec3f *) &jr->rotate);
            PSVECNormalize(&d, &d);
            dir = d;
        } else {
            dir = FV3(arg0, 0xA4);
        }
        f32 s = 1.0f - t;
        Vec3f blend;
        blend.x = (cur.x * s) + (FF32(arg0, 0xB0) * t);
        blend.y = (cur.y * s) + (FF32(arg0, 0xB4) * t);
        blend.z = (cur.z * s) + (FF32(arg0, 0xB8) * t);
        f32 ang = kar_lbvector_angle_between(&dir, &blend);
        if (ang > maxAngle) {
            ang = maxAngle;
        }
        if (ang > 0.05235988f) {
            Vec3f axis;
            PSVECCrossProduct(&dir, &blend, &axis);
            PSVECNormalize(&axis, &axis);
            kar_lbvector_rotate_about_axis(&blend, &axis, -ang * t);
            SetTranslate_G2(j9c, &blend);
            FV3(arg0, 0xA4) = blend;
        }
        break;
    }
    }
}

extern "C" void kar_a2d_kurakko__near_80370e24(void *arg0, void *arg1, s32 arg2) {
    void *sentinel = (char *) arg0 + 0xC;
    void *a = FP(arg0, 0x10);
    while (a != sentinel) {
        if (__ptmf_scall((char *) a + 8) != 0) {
            void *b = FP(a, 4);
            while (b != sentinel) {
                if (__ptmf_scall((char *) b + 8) != 0) {
                    b = FP(b, 4);
                    continue;
                }
                break;
            }
            void *result;
            void *bb = b;
            void *aa = a;
            fn_80297B8C(&result, arg0, &aa, &bb);
            a = result;
            if (a != sentinel) {
                continue;
            }
        }
        a = FP(a, 4);
    }
}

extern "C" void *kar_a2d_kurakko__near_80370edc(void *arg0, s32 arg1) {
    FP(arg0, 0) = &lbl_804BD598;
    lbl_805DDB48 = (void **) arg0;
    FP(arg0, 0) = &lbl_804BD5BC;
    kar_a2d_kurakko__near_8037182c((char *) arg0 + 4);
    u32 *rec = (u32 *) fn_803919FC(0x14, (void *) fn_8038BBE8(arg1, "OB1800.tm"));
    if (rec != NULL) {
        if (lbl_805DDCB0 != 0) {
            fn_80391644();
        }
    }
    u32 v = 0;
    if (rec != NULL && *rec != 0) {
        v = *(u32 *) *rec;
    }
    FU32(arg0, 0x18) = v;
    return arg0;
}

extern "C" void kar_a2d_kurakko__near_80370f9c(void *arg0) {
    void *sentinel = (char *) arg0 + 0x10;
    void *cur = FP(arg0, 0x14);
    while (cur != sentinel) {
        kar_a2d_kurakko__near_8037122c((char *) cur + 8);
        cur = FP(cur, 4);
    }
    kar_a2d_kurakko__near_803714d8((char *) arg0 + 4, (void *) &lbl_804F0D7C, 0);
}

extern "C" s32 fn_8037102C(void *arg0) {
    return FU32(arg0, 0x18) == 0;
}

extern "C" void kar_a2d_kurakko__near_8037103c(void *arg0) {
    void *sentinel = (char *) arg0 + 0x10;
    void *cur = FP(arg0, 0x14);
    while (cur != sentinel) {
        void *w = (char *) cur + 0x14;
        void *vt = *(void **) w;
        typedef void (*Fn10)(void *);
        (*(Fn10 *) ((char *) vt + 0x10))(w);
        cur = FP(cur, 4);
    }
}

extern "C" void kar_a2d_kurakko__near_80371094(void *arg0) {
    if ((u32) (6 - FS32(arg0, 8)) != 0U) {
        void *node = kar_a2d_kurakko__near_8037113c(NULL, NULL, 0, 0);
        void *listHead = (char *) arg0 + 0x10;
        kar_a2d_kurakko__near_803715dc(NULL, (char *) arg0 + 4, &listHead, node);
        RefObjRelease(NULL);
    }
}

extern "C" void *kar_a2d_kurakko__near_8037113c(void *arg0, void *arg1, s32 arg2, s8 arg3) {
    PreConstruct(arg0, &lbl_804BF078);
    ((GameEffectItemBase *) arg0)->Init(NULL);
    FP(arg0, 0) = &lbl_804BF0BC;
    fn_8038CCAC((char *) arg0 + 0xC, ((DiagResult *) kar_diag__803ad760((s32) lbl_805DDB48, 0, &lbl_805DB9C8, &lbl_805DB9C0, 0))->unk18);
    f32 t = *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x600);
    FU32(arg0, 0x18) = (u32) t;
    Vec3f *pos = ((KartIF *) arg1)->v74();
    FF32(arg0, 0x1C) = pos->x;
    FF32(arg0, 0x20) = pos->y;
    FF32(arg0, 0x24) = pos->z;
    FS32(arg0, 0x28) = arg2;
    FS8(arg0, 0x2C) = arg3;
    return arg0;
}

extern "C" void kar_a2d_kurakko__near_8037122c(void *arg0) {
    u32 total = FU32(arg0, 0x18);
    f32 dur = *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x600);
    f32 t = (f32) total / dur;
    Vec3f up = { 0.0f, -20.0f, 0.0f };
    Vec3f *kif = (Vec3f *) FP(arg0, 0x28);
    Vec3f interp;
    fn_802FE674(&interp, (Vec3f *) ((char *) arg0 + 0x1C), &up, (s32) ((KartIF *) kif)->v74(), &up, 1.0f - t);
    HSD_JObj *j = fn_8038D0A8((HSD_JObj *) FP(arg0, 0xC), NULL);
    SetTranslate_G3(j, &interp);
    KartIF *kif2 = (KartIF *) FP(arg0, 0x28);
    Vec3f *kp = kif2->v74();
    Vec3f d;
    PSVECSubtract(kp, (Vec3f *) ((char *) arg0 + 0x1C), &d);
    f32 yaw = (f32) kar_atan2(d.x, d.z);
    HSD_JObj *j2 = fn_8038D0A8((HSD_JObj *) FP(arg0, 0xC), NULL);
    SetRotationZOnly_G3(j2, yaw);
    void *jvt = (char *) arg0 + 0xC;
    typedef void (*FnC)(void *);
    (*(FnC *) ((char *) *(void **) jvt + 0xC))(jvt);
    u32 t2 = FU32(arg0, 0x18) - 1;
    FU32(arg0, 0x18) = t2;
    if (t2 == 0) {
        KartIF *kif3 = (KartIF *) FP(arg0, 0x28);
        typedef void (*Fn108)(void *, s8);
        void *kvt = *(void **) kif3;
        (*(Fn108 *) ((char *) kvt + 0x108))(kif3, FS8(arg0, 0x2C));
    }
}

extern "C" void kar_a2d_kurakko__near_803714d8(void *arg0, void *arg1, s32 arg2) {
    void *sentinel = (char *) arg0 + 0xC;
    void *a = FP(arg0, 0x10);
    while (a != sentinel) {
        if (__ptmf_scall((char *) a + 8) != 0) {
            void *b = FP(a, 4);
            while (b != sentinel) {
                if (__ptmf_scall((char *) b + 8) != 0) {
                    b = FP(b, 4);
                    continue;
                }
                break;
            }
            if (a != b) {
                void *bfirst = FP(b, 0);
                FP(FP(a, 0), 4) = FP(bfirst, 4);
                FP(FP(bfirst, 4), 4) = FP(a, 0);
                void *cur = a;
                while (cur != b) {
                    void *w8 = (char *) cur + 8;
                    void *vt = *(void **) w8;
                    typedef void (*Fn8)(void *, s32);
                    (*(Fn8 *) ((char *) vt + 8))(w8, -1);
                    void *next = FP(cur, 4);
                    fn_8029B1D8(lbl_805DD964, cur);
                    FS32(arg0, 4) = FS32(arg0, 4) - 1;
                    cur = next;
                }
            }
            a = b;
            if (b != sentinel) {
                continue;
            }
        }
        a = FP(a, 4);
    }
}

extern "C" void kar_a2d_kurakko__near_803715dc(void *arg0, void *arg1, void *arg2, void *arg3) {
    void *node = kar_a2d_kurakko__near_80371940(lbl_805DD964);
    void *w = (char *) node + 8;
    void *outNode = node;
    if (w != NULL) {
        PreConstruct(w, &lbl_804BF078);
        typedef void (*Fn10)(void *);
        void *vt = *(void **) w;
        (*(Fn10 *) ((char *) vt + 0x10))(w);
        FP(w, 0) = &lbl_804BF0BC;
        FP(w, 0xC) = &lbl_804F4E38;
        void *w10 = FP(arg3, 0x10);
        FP(w, 0x10) = w10;
        FS32(w, 0x14) = FS32(arg3, 0x14);
        if (w10 != NULL) {
            u16 *cnt = (u16 *) ((char *) w10 + 4);
            *cnt = (u16) (*cnt + 1);
            if (*cnt == 0xFFFFU) {
                RefObjRelease(NULL);
            }
        }
        FS32(w, 0x18) = FS32(arg3, 0x18);
        FF32(w, 0x1C) = FF32(arg3, 0x1C);
        FF32(w, 0x20) = FF32(arg3, 0x20);
        FS32(w, 0x24) = FS32(arg3, 0x24);
        FS32(w, 0x28) = FS32(arg3, 0x28);
        FU8(w, 0x2C) = FU8(arg3, 0x2C);
        f32 sc = *(f32 *) ((char *) TopRideItem_GetDataBase() + 0x20F8);
        Vec3f scv = { sc, sc, sc };
        HSD_JObj *j = fn_8038D0A8((HSD_JObj *) ((char *) w + 0xC), NULL);
        SetScale_G3(j, &scv);
        kar_object__8038d158((char *) w + 0xC, 0, 1);
        HSD_ForeachAnim(w10, (HSD_Type) 6, (HSD_TypeMask) 0xFFFF, (void *) &HSD_AObjSetRate, (AObj_Arg_Type) 1, 1.0f);
    }
    void *listHeadPtr = *(void **) arg2;
    void *n = outNode;
    FP(listHeadPtr, 4) = n;
    FP(n, 0) = listHeadPtr;
    *(void **) arg2 = n;
    FP(n, 4) = arg2;
    FS32(arg1, 4) = FS32(arg1, 4) + 1;
    *(void **) arg0 = n;
}

extern "C" void *kar_a2d_kurakko__near_8037182c(void *arg0) {
    FP(arg0, 0) = 0;
    FP(arg0, 4) = 0;
    void *n = fn_8038CB28(0x158);
    if (n != NULL) {
        n = kar_a2d_kurakko__near_803718f8(n);
    }
    void *keep = n;
    if (keep != NULL) {
        /* nothing */
    }
    FP(arg0, 8) = keep;
    void *dummy = (char *) arg0 + 0xC;
    FP(dummy, 4) = dummy;
    FP(arg0, 0xC) = dummy;
    return arg0;
}

extern "C" f32 *kar_a2d_kurakko__near_803718f8(void *arg0) {
    FS32(arg0, 0x150) = 0;
    lbl_805DD964 = arg0;
    FS32(arg0, 0) = 1;
    FS32(arg0, 0x38) = 2;
    FS32(arg0, 0x70) = 3;
    FS32(arg0, 0xA8) = 4;
    FS32(arg0, 0xE0) = 5;
    FS32(arg0, 0x118) = -1;
    FS32(arg0, 0x154) = 6;
    return (f32 *) arg0;
}

extern "C" void *kar_a2d_kurakko__near_80371940(void *arg0) {
    void *n = (char *) arg0 + (FS32(arg0, 0x150) * 0x38);
    FS32(arg0, 0x150) = *(s32 *) n;
    FS32(arg0, 0x154) = FS32(arg0, 0x154) - 1;
    return n;
}

extern "C" void *kar_a2d_kurakko__near_80371968(void *arg0, s32 *arg1) {
    FP(arg0, 0) = &lbl_804BD26C;
    FP(arg0, 4) = arg1;
    FS32(arg0, 8) = HSD_CObjLoadDesc(*arg1, &lbl_804BD26C);
    FP(arg0, 0xC) = &lbl_804BCEC0;
    lbl_805DDB7C = (void **) ((char *) arg0 + 0xC);
    PreConstruct(arg0, &lbl_804F1010);
    FF32(arg0, 0x1C) = 0.0f;
    FF32(arg0, 0x18) = 0.0f;
    FF32(arg0, 0x14) = 0.0f;
    FF32(arg0, 0x28) = 0.0f;
    FF32(arg0, 0x24) = 0.0f;
    FF32(arg0, 0x20) = 0.0f;
    FF32(arg0, 0x34) = 0.0f;
    FF32(arg0, 0x30) = 0.0f;
    FF32(arg0, 0x2C) = 0.0f;
    FS32(arg0, 0x40) = 0;
    FS32(arg0, 0x44) = 0;
    FS32(arg0, 0x48) = 0;
    FS32(arg0, 0x4C) = 1;
    FF32(arg0, 0x14) = 0.0f;
    FF32(arg0, 0x18) = 0.0f;
    FF32(arg0, 0x1C) = 0.0f;
    FF32(arg0, 0x20) = 0.0f;
    FF32(arg0, 0x24) = 0.0f;
    FF32(arg0, 0x28) = 1.0f;
    FF32(arg0, 0x2C) = 0.0f;
    FF32(arg0, 0x30) = 1.0f;
    FF32(arg0, 0x34) = 0.0f;
    f32 a = fn_80296264(0.0f);
    f32 b = fn_80296264(1.0f) * a;
    f32 c = fn_80296264(1.0f) * b;
    f32 rad = 0.017453292f * c;
    f32 deg30 = 30.0f * rad;
    FF32(arg0, 0x38) = deg30;
    FF32(arg0, 0x3C) = 1.33f;
    kar_a2d_kurakko__near_80374214((char *) arg0 + 0x40, 0x28U);
    return arg0;
}

extern "C" void kar_a2d_kurakko__near_80371aa0(void *arg0) {
    void *kif = FP(arg0, 0x10);
    typedef void (*Fn8)(void *, void *, void *);
    void *vt = *(void **) kif;
    (*(Fn8 *) ((char *) vt + 8))(kif, (char *) arg0 + 0x40, (char *) arg0 + 0x14);
    HSD_CObjSetEyePosition(FS32(arg0, 8), (Vec3f *) ((char *) arg0 + 0x14));
    Vec3f interest;
    PSVECAdd((Vec3f *) ((char *) arg0 + 0x14), (Vec3f *) ((char *) arg0 + 0x20), &interest);
    HSD_CObjSetInterest(FS32(arg0, 8), &interest, interest.y, interest.z);
    f32 a = fn_80296264(1.0f);
    f32 b = fn_80296264(1.0f) * a;
    f32 fov = fn_80296264(1.0f) * b;
    HSD_CObjSetFov(FS32(arg0, 8), FF32(arg0, 0x38) / (0.017453292f * fov), fov);
    HSD_CObjAnim(FS32(arg0, 8));
}

extern "C" void *kar_a2d_kurakko__near_80371b90(void *arg0) {
    FP(arg0, 0) = &lbl_804F1004;
    FP(arg0, 4) = &lbl_804BCEE8;
    lbl_805DDB78 = (void **) ((char *) arg0 + 4);
    PreConstruct((char *) arg0, &lbl_804F0FE8);
    FF32(arg0, 8) = 1.0f;
    FF32(arg0, 0xC) = 15.0f;
    FF32(arg0, 0x10) = 32.0f;
    FF32(arg0, 0x14) = 0.5f;
    FF32(arg0, 0x18) = 5.0f;
    f32 a1 = fn_80296264(1.0f);
    f32 b1 = fn_80296264(1.0f) * a1;
    f32 c1 = fn_80296264(1.0f) * b1;
    FF32(arg0, 0x1C) = 60.0f * (0.017453292f * c1);
    f32 a2 = fn_80296264(1.0f);
    f32 b2 = fn_80296264(1.0f) * a2;
    f32 c2 = fn_80296264(1.0f) * b2;
    FF32(arg0, 0x20) = 30.0f * (0.017453292f * c2);
    f32 a3 = fn_80296264(1.0f);
    f32 b3 = fn_80296264(1.0f) * a3;
    f32 c3 = fn_80296264(1.0f) * b3;
    FF32(arg0, 0x24) = 8.0f * (0.01f * c3);
    f32 a4 = fn_80296264(1.0f);
    f32 b4 = fn_80296264(1.0f) * a4;
    f32 c4 = fn_80296264(1.0f) * b4;
    FF32(arg0, 0x28) = 8.0f * (0.01f * c4);
    f32 a5 = fn_80296264(1.0f);
    f32 b5 = fn_80296264(1.0f) * a5;
    f32 c5 = fn_80296264(1.0f) * b5;
    FF32(arg0, 0x2C) = 25.0f * (0.01f * c5);
    f32 a6 = fn_80296264(1.0f);
    f32 b6 = fn_80296264(1.0f) * a6;
    f32 c6 = fn_80296264(1.0f) * b6;
    FF32(arg0, 0x30) = 50.0f * (0.01f * c6);
    FF32(arg0, 0x34) = 0.6f;
    FU8(arg0, 0x38) = 0;
    FU8(arg0, 0x39) = 0;
    return arg0;
}

extern "C" void kar_a2d_kurakko__near_80371d88(f32 *arg0, void *arg2, void *arg3, void *arg4, Vec3f *arg5, f32 farg0) {
    /* GX billboard render, unverified best-effort */
    Vec3f up = { 0.0f, 1.0f, 0.0f };
    Vec3f fwd;
    PSVECSubtract((Vec3f *) arg2, (Vec3f *) arg0, &fwd);
    PSVECNormalize(&fwd, &fwd);
    Vec3f side;
    PSVECCrossProduct(&fwd, &up, &side);
    PSVECNormalize(&side, &side);
    GXSetCurrentMtx(GX_PNMTX0);
    GXLoadPosMtxImm((f32 (*)[4]) ((char *) HSD_CObjGetCurrent() + 0x54), GX_PNMTX0);
    GXInvalidateVtxCache();
    GXClearVtxDesc();
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_TEX_ST, GX_RGBA6, 0U);
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_RGBA6, 0U);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4U);
    *(f32 *) 0xCC008000 = arg0[0];
    *(f32 *) 0xCC008000 = arg0[1];
    *(f32 *) 0xCC008000 = arg0[2];
    *(f32 *) 0xCC008000 = 0.0f;
    *(f32 *) 0xCC008000 = 0.0f;
}

extern "C" f32 kar_a2d_kurakko__near_803724e0(f32 farg0) {
    if (farg0 == 0.0f) {
        return 1.0f;
    }
    f64 x0 = (f64) farg0 + 1.5707963267948966;
    f32 x = (f32) x0;
    s32 neg = 0;
    if (x < 0.0f) {
        x = -x;
        neg = 1;
    }
    while (x > (f32) 6.283185307179586) {
        x = (f32) ((f64) x - 6.283185307179586);
    }
    f32 result;
    if (x <= (f32) 3.141592653589793) {
        if (x <= (f32) 1.5707963267948966) {
            if (x <= (f32) 0.7853981633974483) {
                f32 x2 = x * x;
                result = x * (1.0f - (x2 * -((x2 * -((0.00019587841f * x2) - 0.008332824f)) - 0.16666669f)));
            } else {
                f32 y = (f32) (1.5707963267948966 - (f64) x);
                f32 y2 = y * y;
                result = 0.9999998f - (y2 * -((y2 * -((0.0013400711f * y2) - 0.04163633f)) - 0.49999395f));
            }
        } else {
            f32 y = (f32) (3.141592653589793 - (f64) x);
            if (y <= (f32) 0.7853981633974483) {
                f32 y2 = y * y;
                result = y * (1.0f - (y2 * -((y2 * -((0.00019587841f * y2) - 0.008332824f)) - 0.16666669f)));
            } else {
                f32 z = (f32) (1.5707963267948966 - (f64) y);
                f32 z2 = z * z;
                result = 0.9999998f - (z2 * -((z2 * -((0.0013400711f * z2) - 0.04163633f)) - 0.49999395f));
            }
        }
    } else {
        f32 y = (f32) ((f64) x - 3.141592653589793);
        f32 sub;
        if (y <= (f32) 1.5707963267948966) {
            if (y <= (f32) 0.7853981633974483) {
                f32 y2 = y * y;
                sub = y * (1.0f - (y2 * -((y2 * -((0.00019587841f * y2) - 0.008332824f)) - 0.16666669f)));
            } else {
                f32 z = (f32) (1.5707963267948966 - (f64) y);
                f32 z2 = z * z;
                sub = 0.9999998f - (z2 * -((z2 * -((0.0013400711f * z2) - 0.04163633f)) - 0.49999395f));
            }
        } else {
            f32 z = (f32) (3.141592653589793 - (f64) y);
            if (z <= (f32) 0.7853981633974483) {
                f32 z2 = z * z;
                sub = z * (1.0f - (z2 * -((z2 * -((0.00019587841f * z2) - 0.008332824f)) - 0.16666669f)));
            } else {
                f32 w = (f32) (1.5707963267948966 - (f64) z);
                f32 w2 = w * w;
                sub = 0.9999998f - (w2 * -((w2 * -((0.0013400711f * w2) - 0.04163633f)) - 0.49999395f));
            }
        }
        result = -sub;
    }
    if (neg) {
        return -result;
    }
    return result;
}

extern "C" f32 kar_a2d_kurakko__near_8037293c(f32 farg0) {
    f32 x = farg0;
    if (x == 0.0f) {
        return 0.0f;
    }
    s32 neg = 0;
    if (x < 0.0f) {
        x = -x;
        neg = 1;
    }
    while (x > (f32) 6.283185307179586) {
        x = (f32) ((f64) x - 6.283185307179586);
    }
    f32 result;
    if (x <= (f32) 3.141592653589793) {
        if (x <= (f32) 1.5707963267948966) {
            if (x <= (f32) 0.7853981633974483) {
                f32 x2 = x * x;
                result = x * (1.0f - (x2 * -((x2 * -((0.00019587841f * x2) - 0.008332824f)) - 0.16666669f)));
            } else {
                f32 y = (f32) (1.5707963267948966 - (f64) x);
                f32 y2 = y * y;
                result = 0.9999998f - (y2 * -((y2 * -((0.0013400711f * y2) - 0.04163633f)) - 0.49999395f));
            }
        } else {
            f32 y = (f32) (3.141592653589793 - (f64) x);
            if (y <= (f32) 0.7853981633974483) {
                f32 y2 = y * y;
                result = y * (1.0f - (y2 * -((y2 * -((0.00019587841f * y2) - 0.008332824f)) - 0.16666669f)));
            } else {
                f32 z = (f32) (1.5707963267948966 - (f64) y);
                f32 z2 = z * z;
                result = 0.9999998f - (z2 * -((z2 * -((0.0013400711f * z2) - 0.04163633f)) - 0.49999395f));
            }
        }
    } else {
        f32 y = (f32) ((f64) x - 3.141592653589793);
        f32 sub;
        if (y <= (f32) 1.5707963267948966) {
            if (y <= (f32) 0.7853981633974483) {
                f32 y2 = y * y;
                sub = y * (1.0f - (y2 * -((y2 * -((0.00019587841f * y2) - 0.008332824f)) - 0.16666669f)));
            } else {
                f32 z = (f32) (1.5707963267948966 - (f64) y);
                f32 z2 = z * z;
                sub = 0.9999998f - (z2 * -((z2 * -((0.0013400711f * z2) - 0.04163633f)) - 0.49999395f));
            }
        } else {
            f32 z = (f32) (3.141592653589793 - (f64) y);
            if (z <= (f32) 0.7853981633974483) {
                f32 z2 = z * z;
                sub = z * (1.0f - (z2 * -((z2 * -((0.00019587841f * z2) - 0.008332824f)) - 0.16666669f)));
            } else {
                f32 w = (f32) (1.5707963267948966 - (f64) z);
                f32 w2 = w * w;
                sub = 0.9999998f - (w2 * -((w2 * -((0.0013400711f * w2) - 0.04163633f)) - 0.49999395f));
            }
        }
        result = -sub;
    }
    if (neg) {
        return -result;
    }
    return result;
}

extern "C" void kar_a2d_kurakko__near_80372d88(void *arg0, void *arg1, f32 *arg2) {
    /* lightning-bolt fork geometry generator; not transcribed (huge, low ROI) */
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void *kar_a2d_kurakko__near_803738fc(void *arg0) {
    FP(arg0, 0) = &lbl_804F1004;
    FP(arg0, 4) = &lbl_804BCF14;
    lbl_805DDB74 = (void **) ((char *) arg0 + 4);
    PreConstruct(arg0, &lbl_804F0F8C);
    FS32(arg0, 8) = 0;
    f32 a = fn_80296264(1.0f);
    f32 b = fn_80296264(1.0f) * a;
    f32 c = fn_80296264(1.0f) * b;
    f32 rad = 0.017453292f * c;
    FF32(arg0, 0xC) = 30.0f * rad;
    f32 a2 = fn_80296264(1.0f);
    f32 b2 = fn_80296264(1.0f) * a2;
    f32 c2 = fn_80296264(1.0f) * b2;
    FF32(arg0, 0x10) = 90.0f * (0.017453292f * c2);
    FF32(arg0, 0x14) = 0.033f;
    FF32(arg0, 0x18) = 35.0f;
    FF32(arg0, 0x1C) = 0.6f;
    return arg0;
}

extern "C" void kar_a2d_kurakko__near_803739fc(void *arg0, void *arg1, Vec3f *arg2) {
    f32 az = FF32(arg0, 0xC);
    f32 a1 = fn_80296264(1.0f);
    f32 b1 = fn_80296264(1.0f) * a1;
    f32 azN = az / (1.0f * b1);
    f32 el = FF32(arg0, 0x10);
    f32 a2 = fn_80296264(1.0f);
    f32 b2 = fn_80296264(1.0f) * a2;
    f32 elN = el / (1.0f * b2);
    f32 wobble = FF32(arg0, 0x14);
    void *branch = (char *) FP(arg1, 8) + (FS32(arg0, 8) * 0x28);
    if (wobble > 0.0f) {
        elN = (0.7662421f * (wobble * FF32(branch, 0))) + 1.5707964f;
        if (elN > 2.3370385f) {
            elN = 2.3370385f;
        }
        if (-elN < -2.3370385f) {
            elN = -2.3370385f;
        }
    }
    f32 cosA = kar_a2d_kurakko__near_803724e0(azN);
    f32 y = -kar_a2d_kurakko__near_8037293c(elN) * cosA;
    f32 z = -kar_a2d_kurakko__near_8037293c(azN);
    f32 cosA2 = kar_a2d_kurakko__near_803724e0(azN);
    arg2->x = -kar_a2d_kurakko__near_803724e0(elN) * cosA2;
    arg2->y = z;
    arg2->z = y;
    Vec3f scaled = *arg2;
    PSVECScale(&scaled, &scaled, FF32(arg0, 0x18));
    Vec3f base = FV3(branch, 0);
    Vec3f sum;
    PSVECAdd(&base, &scaled, &sum);
    *arg2 = sum;
    if ((u8) kar_diag__803ad760((s32) lbl_805DDB7C, 0, &lbl_805DB9F0, &lbl_805DB9E8, 0) != 0) {
        f32 t = FF32(arg0, 0x1C);
        Vec3f *off = (Vec3f *) kar_diag__803ad760((s32) lbl_805DDB80, 0, &lbl_805DBA08, &lbl_805DBA00, 0);
        Vec3f off2 = *off;
        PSVECScale(&off2, &off2, t);
        PSVECAdd(arg2, &off2, arg2);
    }
}

extern "C" void *kar_a2d_kurakko__near_80373cb4(void *arg0) {
    FP(arg0, 0) = &lbl_804F1004;
    FP(arg0, 4) = &lbl_804BCF3C;
    lbl_805DDB70 = (void **) ((char *) arg0 + 4);
    PreConstruct(arg0, &lbl_804F0F28);
    FS32(arg0, 8) = 0;
    f32 a = fn_80296264(1.0f);
    f32 b = fn_80296264(1.0f) * a;
    FF32(arg0, 0xC) = 30.0f * (0.017453292f * b);
    FF32(arg0, 0x10) = 15.0f;
    FF32(arg0, 0x14) = 0.6f;
    return arg0;
}

extern "C" void kar_a2d_kurakko__near_80373d74(void *arg0, void *arg1, Vec3f *arg2) {
    void *branch = (char *) FP(arg1, 8) + (FS32(arg0, 8) * 0x28);
    Vec3f eye;
    HSD_CObjGetEyePosition(0, &eye);
    Vec3f interest = { 15.0f, 0.0f, 0.0f };
    Vec3f diff;
    PSVECSubtract(&eye, (Vec3f *) branch, &diff);
    PSVECNormalize(&diff, &diff);
    f32 az = FF32(arg0, 0xC);
    f32 a1 = fn_80296264(1.0f);
    f32 b1 = fn_80296264(1.0f) * a1;
    f32 azN = az / (1.0f * b1);
    f32 z = diff.z * kar_a2d_kurakko__near_803724e0(azN);
    f32 y = -kar_a2d_kurakko__near_8037293c(azN);
    arg2->x = diff.x * kar_a2d_kurakko__near_803724e0(azN);
    arg2->y = y;
    arg2->z = z;
    Vec3f scaled = *arg2;
    PSVECScale(&scaled, &scaled, FF32(arg0, 0x10));
    Vec3f base = FV3(branch, 0);
    Vec3f sum;
    PSVECAdd(&base, &scaled, &sum);
    *arg2 = sum;
    if ((u8) kar_diag__803ad760((s32) lbl_805DDB7C, 0, &lbl_805DB9F0, &lbl_805DB9E8, 0) != 0) {
        f32 t = FF32(arg0, 0x14);
        Vec3f *off = (Vec3f *) kar_diag__803ad760((s32) lbl_805DDB80, 0, &lbl_805DBA08, &lbl_805DBA00, 0);
        Vec3f off2 = *off;
        PSVECScale(&off2, &off2, t);
        PSVECAdd(arg2, &off2, arg2);
    }
}

extern "C" void kar_a2d_kurakko__near_80374020(void *arg0) {
    FP(arg0, 0) = &lbl_804F1004;
    FP(arg0, 4) = &lbl_804BCF64;
    lbl_805DDB6C = (s32) ((char *) arg0 + 4);
    PreConstruct(arg0, &lbl_804F0ECC);
    FF32(arg0, 8) = 0.6f;
}

extern "C" void kar_a2d_kurakko__near_80374060(void *arg0, Vec3f *arg2) {
    Vec3f eye;
    HSD_CObjGetEyePosition(0, &eye);
    *arg2 = eye;
    Vec3f interest;
    HSD_CObjGetInterest(0, &interest);
    Vec3f dir;
    PSVECSubtract(&interest, arg2, &dir);
    FV3(arg2, 0xC) = dir;
    FF32(arg2, 0x18) = 0.0f;
    FF32(arg2, 0x1C) = 1.0f;
    FF32(arg2, 0x20) = 0.0f;
    if ((u8) kar_diag__803ad760((s32) lbl_805DDB7C, 0, &lbl_805DB9F0, &lbl_805DB9E8, 0) != 0) {
        f32 t = FF32(arg0, 0);
        Vec3f *off = (Vec3f *) kar_diag__803ad760((s32) lbl_805DDB80, 0, &lbl_805DBA08, &lbl_805DBA00, 0);
        Vec3f off2 = *off;
        PSVECScale(&off2, &off2, t);
        PSVECAdd(arg2, &off2, arg2);
    }
}

extern "C" void kar_a2d_kurakko__near_80374214(void *arg0, u32 arg1) {
    if (arg1 > FU32(arg0, 0)) {
        if (arg1 > 0x06666666U) {
            fn_803B4D80(&__files, "vector::reserve length error\n", &__files);
            abort();
        }
        u32 newCap = arg1;
        s32 newCount = 0;
        char *newData = (char *) fn_8038CB28(arg1 * 0x28);
        if (newData == NULL) {
            fn_803B4D80(&__files, "Memory allocation failure", &__files);
            abort();
        }
        char *dst = newData;
        char *src = (char *) FP(arg0, 8);
        char *srcEnd = src + (FS32(arg0, 4) * 0x28);
        while (src < srcEnd) {
            if (dst != NULL) {
                memcpy(dst, src, 0x28);
            }
            src += 0x28;
            dst += 0x28;
            newCount += 1;
        }
        u32 oldCap = FU32(arg0, 0);
        FU32(arg0, 0) = newCap;
        void *oldData = FP(arg0, 8);
        FP(arg0, 8) = newData;
        newData = (char *) oldData;
        s32 oldCount = FS32(arg0, 4);
        FS32(arg0, 4) = newCount;
        newCount = oldCount;
        kar_diagnostic__8029c5a4(&oldCap);
        if (newData != NULL) {
            fn_8038CB78(newData);
        }
    }
}

extern "C" void kar_a2d_kurakko__near_803743c8(void *arg0, void *arg1, u32 arg2, void *arg3, s32 arg4) {
    /* std::vector<Quaternion>::insert; not transcribed (huge, low ROI) */
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
}

extern "C" f32 *kar_a2d_kurakko__near_80374964(f32 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        kar_a2d_kurakko__near_803749c4(arg0);
        if (FU32(arg0, 8) != 0U) {
            fn_8038CB78(FP(arg0, 8));
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void kar_a2d_kurakko__near_803749c4(void *arg0) {
    FS32(arg0, 4) = 0;
}

extern "C" void fn_803749FC(char *arg0) {
    return fn_802905F8((void *) (arg0 - 0xC));
}

extern "C" void fn_80374A04(char *arg0) {
    return fn_80290588((void *) (arg0 - 4));
}

extern "C" void fn_80374A0C(char *arg0) {
    return fn_80290518((void *) (arg0 - 4));
}

extern "C" void fn_80374A14(char *arg0) {
    return fn_802904A8((void *) (arg0 - 4));
}

extern "C" void fn_80374A1C(char *arg0) {
    return fn_80290438((void *) (arg0 - 4));
}

extern "C" void kar_a2d_kurakko__near_80374a24(void *arg0, Vec3f *arg1, f32 farg0, f32 farg1) {
    /* lightning quad billboard GX draw; not fully transcribed (huge, low ROI) */
    (void) arg0;
    (void) arg1;
    (void) farg0;
    (void) farg1;
}

extern "C" f32 kar_a2d_kurakko__near_80375060(f32 farg0) {
    if (farg0 == 0.0f) {
        return 1.0f;
    }
    f64 x0 = (f64) farg0 + 1.5707963267948966;
    f32 x = (f32) x0;
    s32 neg = 0;
    if (x < 0.0f) {
        x = -x;
        neg = 1;
    }
    while (x > (f32) 6.283185307179586) {
        x = (f32) ((f64) x - 6.283185307179586);
    }
    f32 result;
    if (x <= (f32) 3.141592653589793) {
        if (x <= (f32) 1.5707963267948966) {
            if (x <= (f32) 0.7853981633974483) {
                f32 x2 = x * x;
                result = x * (1.0f - (x2 * -((x2 * -((0.00019587841f * x2) - 0.008332824f)) - 0.16666669f)));
            } else {
                f32 y = (f32) (1.5707963267948966 - (f64) x);
                f32 y2 = y * y;
                result = 0.9999998f - (y2 * -((y2 * -((0.0013400711f * y2) - 0.04163633f)) - 0.49999395f));
            }
        } else {
            f32 y = (f32) (3.141592653589793 - (f64) x);
            if (y <= (f32) 0.7853981633974483) {
                f32 y2 = y * y;
                result = y * (1.0f - (y2 * -((y2 * -((0.00019587841f * y2) - 0.008332824f)) - 0.16666669f)));
            } else {
                f32 z = (f32) (1.5707963267948966 - (f64) y);
                f32 z2 = z * z;
                result = 0.9999998f - (z2 * -((z2 * -((0.0013400711f * z2) - 0.04163633f)) - 0.49999395f));
            }
        }
    } else {
        f32 y = (f32) ((f64) x - 3.141592653589793);
        f32 sub;
        if (y <= (f32) 1.5707963267948966) {
            if (y <= (f32) 0.7853981633974483) {
                f32 y2 = y * y;
                sub = y * (1.0f - (y2 * -((y2 * -((0.00019587841f * y2) - 0.008332824f)) - 0.16666669f)));
            } else {
                f32 z = (f32) (1.5707963267948966 - (f64) y);
                f32 z2 = z * z;
                sub = 0.9999998f - (z2 * -((z2 * -((0.0013400711f * z2) - 0.04163633f)) - 0.49999395f));
            }
        } else {
            f32 z = (f32) (3.141592653589793 - (f64) y);
            if (z <= (f32) 0.7853981633974483) {
                f32 z2 = z * z;
                sub = z * (1.0f - (z2 * -((z2 * -((0.00019587841f * z2) - 0.008332824f)) - 0.16666669f)));
            } else {
                f32 w = (f32) (1.5707963267948966 - (f64) z);
                f32 w2 = w * w;
                sub = 0.9999998f - (w2 * -((w2 * -((0.0013400711f * w2) - 0.04163633f)) - 0.49999395f));
            }
        }
        result = -sub;
    }
    if (neg) {
        return -result;
    }
    return result;
}

extern "C" f32 kar_a2d_kurakko__near_803754bc(f32 farg0) {
    f32 x = farg0;
    if (x == 0.0f) {
        return 0.0f;
    }
    s32 neg = 0;
    if (x < 0.0f) {
        x = -x;
        neg = 1;
    }
    while (x > (f32) 6.283185307179586) {
        x = (f32) ((f64) x - 6.283185307179586);
    }
    f32 result;
    if (x <= (f32) 3.141592653589793) {
        if (x <= (f32) 1.5707963267948966) {
            if (x <= (f32) 0.7853981633974483) {
                f32 x2 = x * x;
                result = x * (1.0f - (x2 * -((x2 * -((0.00019587841f * x2) - 0.008332824f)) - 0.16666669f)));
            } else {
                f32 y = (f32) (1.5707963267948966 - (f64) x);
                f32 y2 = y * y;
                result = 0.9999998f - (y2 * -((y2 * -((0.0013400711f * y2) - 0.04163633f)) - 0.49999395f));
            }
        } else {
            f32 y = (f32) (3.141592653589793 - (f64) x);
            if (y <= (f32) 0.7853981633974483) {
                f32 y2 = y * y;
                result = y * (1.0f - (y2 * -((y2 * -((0.00019587841f * y2) - 0.008332824f)) - 0.16666669f)));
            } else {
                f32 z = (f32) (1.5707963267948966 - (f64) y);
                f32 z2 = z * z;
                result = 0.9999998f - (z2 * -((z2 * -((0.0013400711f * z2) - 0.04163633f)) - 0.49999395f));
            }
        }
    } else {
        f32 y = (f32) ((f64) x - 3.141592653589793);
        f32 sub;
        if (y <= (f32) 1.5707963267948966) {
            if (y <= (f32) 0.7853981633974483) {
                f32 y2 = y * y;
                sub = y * (1.0f - (y2 * -((y2 * -((0.00019587841f * y2) - 0.008332824f)) - 0.16666669f)));
            } else {
                f32 z = (f32) (1.5707963267948966 - (f64) y);
                f32 z2 = z * z;
                sub = 0.9999998f - (z2 * -((z2 * -((0.0013400711f * z2) - 0.04163633f)) - 0.49999395f));
            }
        } else {
            f32 z = (f32) (3.141592653589793 - (f64) y);
            if (z <= (f32) 0.7853981633974483) {
                f32 z2 = z * z;
                sub = z * (1.0f - (z2 * -((z2 * -((0.00019587841f * z2) - 0.008332824f)) - 0.16666669f)));
            } else {
                f32 w = (f32) (1.5707963267948966 - (f64) z);
                f32 w2 = w * w;
                sub = 0.9999998f - (w2 * -((w2 * -((0.0013400711f * w2) - 0.04163633f)) - 0.49999395f));
            }
        }
        result = -sub;
    }
    if (neg) {
        return -result;
    }
    return result;
}

extern "C" void kar_a2d_kurakko__near_80375908(void *arg0) {
    /* eye spark physics; not fully transcribed (large, low ROI) */
    (void) arg0;
}

extern "C" void kar_a2d_kurakko__near_80375e4c(void *arg0) {
    if (FF32(arg0, 0x20) != 0.0f) {
        GXSetCurrentMtx(GX_PNMTX0);
        GXLoadPosMtxImm((f32 (*)[4]) ((char *) HSD_CObjGetCurrent() + 0x54), GX_PNMTX0);
        f32 a1 = fn_80296264(1.0f);
        f32 b1 = fn_80296264(1.0f) * a1;
        f32 c1 = 1.0f * (fn_8029626C(0.016666668f) * b1);
        f32 spanA = FF32(arg0, 0x24) / c1;
        f32 a2 = fn_80296264(1.0f);
        f32 b2 = fn_80296264(1.0f) * a2;
        f32 c2 = 1.0f * (fn_8029626C(0.016666668f) * b2);
        f32 t = (FF32(arg0, 0x20) / c2) / spanA;
        f32 a3 = fn_80296264(1.0f);
        f32 b3 = fn_80296264(1.0f) * a3;
        f32 c3 = fn_8029626C(0.016666668f) * b3;
        f32 c1b = 1.0f * c3;
        f32 spanB = FF32(arg0, 0x20) / c1b;
        void *cbFn = FP(kar_diag__803ad760((s32) lbl_805DDBB0, 0, &lbl_805DBA70, &lbl_805DBA68, 0), 4);
        typedef void (*Fn10)(void *, void *, f32, f32);
        void *cvt = *(void **) cbFn;
        (*(Fn10 *) ((char *) cvt + 0x10))(cbFn, (char *) arg0 + 8, 0.1f * spanB, t);
    }
}

extern "C" void kar_a2d_kurakko__near_80375fb4(void *arg0, void *arg1, f32 *arg2, f32 *arg3, s32 arg4) {
    /* spark/eye jobj lookup + placement; not fully transcribed (large, low ROI) */
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
}

extern "C" void kar_a2d_kurakko__near_803763cc(void *arg0, void *arg1, void *arg2, void *arg3) {
    void *node = kar_a2d_kurakko__near_803764cc(lbl_805DD9A4);
    void *w = (char *) node + 8;
    if (w != NULL) {
        FS32(w, 0) = FS32(arg3, 0);
        FS32(w, 4) = FS32(arg3, 4);
        FF32(w, 8) = FF32(arg3, 8);
        FF32(w, 0xC) = FF32(arg3, 0xC);
        FF32(w, 0x10) = FF32(arg3, 0x10);
        FF32(w, 0x14) = FF32(arg3, 0x14);
        FF32(w, 0x18) = FF32(arg3, 0x18);
        FF32(w, 0x1C) = FF32(arg3, 0x1C);
        FF32(w, 0x20) = FF32(arg3, 0x20);
        FF32(w, 0x24) = FF32(arg3, 0x24);
        FF32(w, 0x28) = FF32(arg3, 0x28);
    }
    void *listHead = *(void **) arg2;
    void *n = node;
    FP(listHead, 4) = n;
    FP(n, 0) = listHead;
    *(void **) arg2 = n;
    FP(n, 4) = arg2;
    FS32(arg1, 4) = FS32(arg1, 4) + 1;
    *(void **) arg0 = n;
}

extern "C" void *kar_a2d_kurakko__near_803764cc(void *arg0) {
    void *n = (char *) arg0 + (FS32(arg0, 0x1A00) * 0x34);
    FS32(arg0, 0x1A00) = *(s32 *) n;
    FS32(arg0, 0x1A04) = FS32(arg0, 0x1A04) - 1;
    return n;
}

extern "C" void kar_a2d_kurakko__near_803764f4(void *arg0, void *arg1, Vec3f *arg2, f32 farg0) {
    Vec3f a, b;
    if (arg2->x != 0.0f || arg2->z != 0.0f) {
        Vec3f up = { 0.0f, 1.0f, 0.0f };
        Vec3f side;
        PSVECCrossProduct(arg2, &up, &side);
        Vec3f fwd;
        PSVECCrossProduct(&side, arg2, &fwd);
        PSVECNormalize(&side, &a);
        PSVECNormalize(&fwd, &b);
    } else {
        a.x = 0.0f; a.y = 1.0f; a.z = 0.0f;
        b.x = 0.0f; b.y = 0.0f; b.z = 1.0f;
    }
    f32 half = 0.5f * farg0;
    PSVECScale(&a, &a, half);
    PSVECScale(&b, &b, half);
    GXSetCurrentMtx(GX_PNMTX0);
    GXLoadPosMtxImm((f32 (*)[4]) ((char *) HSD_CObjGetCurrent() + 0x54), GX_PNMTX0);
    typedef void (*FnC)(void *);
    void *avt = *(void **) arg0;
    (*(FnC *) ((char *) avt + 0xC))(arg0);
    GXInvalidateVtxCache();
    GXClearVtxDesc();
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_TEX_ST, GX_RGBA6, 0U);
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_RGBA6, 0U);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4U);
    Vec3f p;
    PSVECSubtract((Vec3f *) arg1, &a, &p);
    PSVECSubtract(&p, &b, &p);
    *(f32 *) 0xCC008000 = p.x;
    *(f32 *) 0xCC008000 = p.y;
    *(f32 *) 0xCC008000 = p.z;
    *(f32 *) 0xCC008000 = 0.0f;
    *(f32 *) 0xCC008000 = 0.0f;
}

extern "C" void kar_a2d_kurakko__near_803768d8(void) {
    KartIF *cur = (KartIF *) kar_diag__803ad760((s32) lbl_805DDA88, 0, &lbl_805DBAA0, &lbl_805DBA98, 0);
    while (cur != NULL) {
        kar_a2d_kurakko__near_803769c8(cur);
        cur = (KartIF *) cur->v24();
    }
}

extern "C" void kar_a2d_kurakko__near_80376944(void) {
    GXSetZMode(GX_ENABLE, GX_LESS, GX_DISABLE);
    KartIF *cur = (KartIF *) kar_diag__803ad760((s32) lbl_805DDA88, 0, &lbl_805DBAA0, &lbl_805DBA98, 0);
    while (cur != NULL) {
        kar_a2d_kurakko__near_80376bcc(cur);
        cur = (KartIF *) cur->v24();
    }
    HSD_StateInvalidate(-1);
}

extern "C" void kar_a2d_kurakko__near_803769c8(void *arg0) {
    /* particle-spawn init; not fully transcribed (large, low ROI) */
    (void) arg0;
}

extern "C" void kar_a2d_kurakko__near_80376bcc(void *arg0) {
    if (FU8(arg0, 0x2D) != 0 && FU8(arg0, 0x2E) != 0 && FU8(arg0, 0x2C) != 0) {
        void *fn = FP(kar_diag__803ad760((s32) lbl_805DDBAC, 0, &lbl_805DBAB0, &lbl_805DBAA8, 0), 4);
        typedef void (*Fn10)(void *, void *, void *, f32);
        (*(Fn10 *) ((char *) *(void **) fn + 0x10))(fn, (char *) arg0 + 0xC, (char *) arg0 + 0x18, FF32(arg0, 0x24));
    }
}

extern "C" void kar_a2d_kurakko__near_80376c50(void *arg0, void *arg1, void *arg2, f32 farg0) {
    u8 a0 = FU8(arg1, 0);
    f32 inv = 1.0f - farg0;
    u8 b0 = FU8(arg2, 0);
    u8 r0 = (u8) ((f32) a0 * inv);
    for (s32 i = 1; i < 4; i++) {
        FU8(arg0, i) = (u8) ((f32) FU8(arg1, i) * inv);
    }
    u8 r1 = (u8) ((f32) b0 * farg0);
    for (s32 i = 1; i < 4; i++) {
        FU8(arg0, i) = (u8) (FU8(arg0, i) + (u8) ((f32) FU8(arg2, i) * farg0));
    }
    FU8(arg0, 0) = (u8) (r0 + r1);
}

extern "C" void *kar_a2d_kurakko__near_80376e18(void *arg0, s32 arg1) {
    FP(arg0, 0) = &lbl_804C04D4;
    lbl_805DDB34 = (void **) arg0;
    FP(arg0, 0) = &lbl_804C04E0;
    u8 t = lbl_805DDC68;
    kar_a2d_kurakko__near_80377a70((char *) arg0 + 4, &t);
    kar_a2d_refract__near_8038528c((char *) arg0 + 0x14, 3, &lbl_8048A5A0, (char *) &lbl_8048A5A0 + 0xC00);
    FS32(arg0, 0x68) = arg1;
    kar_a2d_refract__near_803852b4((char *) arg0 + 0x14, 1, (char *) &lbl_8048A5A0 + 0x400, (char *) &lbl_8048A5A0 + 0xC00);
    kar_a2d_refract__near_803852b4((char *) arg0 + 0x14, 2, (char *) &lbl_8048A5A0 + 0x800, (char *) &lbl_8048A5A0 + 0xC00);
    FU8(arg0, 0x65) = 0;
    return arg0;
}

extern "C" void kar_a2d_kurakko__near_80376ee4(void *arg0, void *arg1) {
    s32 count[1] = {0};
    kar_diag__802b042c((s32 *) count, FS32(arg1, 4));
    void *cur = FP(arg1, 0x10);
    while (cur != (char *) arg1 + 8) {
        kar_diag__802affd8((s32 *) count, 0, 1, (void **) ((char *) cur + 0xC));
        kar_a2d_kurakko__near_80377a1c(&cur);
    }
    kar_a2d_kurakko__near_803779c0(arg0, (void *) count);
}

extern "C" s32 kar_a2d_kurakko__near_80376f94(void *arg0, const char *arg1) {
    /* memcard load; not fully transcribed (large, low ROI) */
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_803773C8(s32 arg0) {
    lbl_805DDC8C[arg0] = 0;
}

extern "C" f32 *kar_a2d_kurakko__near_803773d8(f32 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        FP(arg0, 0) = lbl_804F130C;
        if (FS32(arg0, 0x18) != -1) {
            CARDClose((char *) arg0 + 4);
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80377444(s32 arg0) {
    lbl_805DDC8C[arg0] = 0;
}

extern "C" void fn_80377454(s32 arg0) {
    lbl_805DDC8C[arg0] = 0;
}

extern "C" void *kar_a2d_kurakko__near_80377464(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void **) arg0 = lbl_804F1318;
        lbl_805DDC88 = NULL;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" s32 kar_a2d_kurakko__near_803774b4(void *arg0, const char *arg1) {
    /* memcard save; not fully transcribed (large, low ROI) */
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void kar_a2d_kurakko__near_80377920(void *arg0, void *arg1, void *arg2) {
    void *cur = FP(arg1, 4);
    void *best = (char *) arg1 + 4;
    while (cur != NULL) {
        if (strcmp((char *) FP(cur, 0xC), *(char **) arg2) >= 0) {
            best = cur;
            cur = FP(cur, 0);
        } else {
            cur = FP(cur, 4);
        }
    }
    if (best == (char *) arg1 + 4 || strcmp(*(char **) arg2, (char *) FP(best, 0xC)) < 0) {
        *(void **) arg0 = (char *) arg1 + 4;
        return;
    }
    *(void **) arg0 = best;
}

extern "C" void *kar_a2d_kurakko__near_803779c0(void *arg0, void *arg1) {
    FP(arg0, 0) = 0;
    FP(arg0, 4) = 0;
    FP(arg0, 8) = 0;
    void *data = FP(arg1, 8);
    kar_a2d_kurakko__near_80377a90(data, (char *) data + (FS32(arg1, 4) * 4), 0);
    return arg0;
}

extern "C" void kar_a2d_kurakko__near_80377a1c(void *arg0) {
    void *n = *(void **) arg0;
    void *right = FP(n, 4);
    if (right != NULL) {
        while (FP(right, 0) != NULL) {
            right = FP(right, 0);
        }
        *(void **) arg0 = right;
        return;
    }
    void *cur = n;
    void *parent = (void *) (FS32(cur, 8) & 0xFFFFFFFE);
    while (cur == parent) {
        cur = parent;
        parent = (void *) (FS32(cur, 8) & 0xFFFFFFFE);
    }
    *(void **) arg0 = parent;
}

extern "C" void kar_a2d_kurakko__near_80377a70(void *arg0, void *arg1) {
    FP(arg0, 0) = 0;
    FP(arg0, 4) = 0;
    FU8(arg0, 8) = *(u8 *) arg1;
    FP(arg0, 0xC) = (char *) arg0 + 4;
}

extern "C" void kar_a2d_kurakko__near_80377a90(void *arg0, void *arg1, void *arg2) {
    /* raw pointer-array copy ctor; not fully transcribed (large, low ROI) */
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" s32 kar_a2d_kurakko__near_80377bf4(void) {
    return 0x16;
}

extern "C" void *kar_a2d_kurakko__near_80377bfc(void *unused, s32 arg1) {
    return FP(&lbl_804F20F0[arg1], 0);
}

extern "C" void kar_a2d_kurakko__near_80377c10(void *arg0, void *arg2) {
    s32 i = 0;
    while (strcmp((const char *) lbl_804F20F0[i].unk0, (const char *) arg2) != 0) {
        i += 1;
        if ((u32) i >= 0x16U) {
            break;
        }
    }
    FS32(arg0, 0) = (s32) lbl_804F20F0[i].unkC;
    FS32(arg0, 4) = (s32) lbl_804F20F0[i].unk8;
}

extern "C" void kar_a2d_kurakko__near_80377ca4(void *arg0, s32 arg2) {
    FS32(arg0, 0) = (s32) lbl_804F20F0[arg2].unkC;
    FS32(arg0, 4) = (s32) lbl_804F20F0[arg2].unk8;
}

extern "C" void kar_a2d_kurakko__near_80377cc8(void) {
    char *base = (char *) &lbl_804F13E0 + 0xD10;
    s32 off = 0;
    u32 i = 0;
    do {
        OSReport((const char *) &lbl_804F13E0, *(void **) base);
        OSReport((char *) &lbl_804F13E0 + 0xE80, FP(base, 4), FP(base, 8));
        char *entry = (char *) &lbl_804F13E0 + 0xD10 + off;
        s32 c = FS32(entry, 0xC);
        u32 count = kar_a2d_kurakko__near_80378568(entry);
        s32 j = 0;
        u32 k = 0;
        while (k < count) {
            char *item = (char *) FP(base, 0xC) + j;
            OSReport((char *) &lbl_804F13E0 + 0xEA4, item, FS32(item, 0), FS32(item, 4));
            j += 8;
            k += 1;
        }
        OSReport((char *) &lbl_804F13E0 + 0xEB4);
        i += 1;
        off += 0x10;
        base += 0x10;
    } while (i < 0x16U);
}

extern "C" void kar_a2d_kurakko__near_80377dac(void) {
}

extern "C" u32 kar_a2d_kurakko__near_80378568(void *arg0) {
    s32 count = FS32(arg0, 4);
    u32 idx = 1;
    s32 off = 8;
    if (count > 1) {
        s32 n = count - 1;
        do {
            char *e = (char *) FP(arg0, 0) + off;
            if (!(FF32(e, 0) < FF32(e, -8))) {
                off += 8;
                idx += 1;
                n -= 1;
                if (n != 0) {
                    continue;
                }
            }
            break;
        } while (1);
    }
    return idx;
}

extern "C" void *kar_a2d_kurakko__near_803785b0(void) {
    return &lbl_804F2308;
}

extern "C" void *kar_a2d_kurakko__near_803785bc(void *arg0) {
    FF32(arg0, 0xA0) = 0.0f;
    FF32(arg0, 0x9C) = 0.0f;
    FF32(arg0, 0x98) = 0.0f;
    FF32(arg0, 0xAC) = 0.0f;
    FF32(arg0, 0xA8) = 0.0f;
    FF32(arg0, 0xA4) = 0.0f;
    FF32(arg0, 0xB8) = 0.0f;
    FF32(arg0, 0xB4) = 0.0f;
    FF32(arg0, 0xB0) = 0.0f;
    lbl_805DDC70 = arg0;
    kar_lbaudio_build_hps_basename_table(&lbl_80569840);
    char *p = (char *) arg0;
    for (s32 i = 0; i < 4; i++) {
        FS32(p, 0) = 0;
        FS32(p, 4) = kar_lbaudio_alloc_weapon_track_subtype_1();
        FS32(p, 8) = kar_lbaudio_alloc_vehicle_track_subtype_1();
        FS32(p, 0xC) = kar_lbaudio__near_8005df64();
        FF32(p, 0x10) = 1.0f;
        FF32(p, 0x14) = 0.0f;
        p += 0x18;
    }
    p = (char *) arg0;
    for (s32 i = 0; i < 4; i++) {
        FS32(p, 0x60) = kar_lbaudio_alloc_vehicle_track_subtype_1();
        p += 4;
    }
    FS32(arg0, 0x88) = kar_lbaudio_alloc_weapon_track_subtype_6();
    FS32(arg0, 0x8C) = kar_lbaudio__near_8005df64();
    FS32(arg0, 0x90) = kar_lbaudio_alloc_weapon_track_subtype_6();
    FS32(arg0, 0x94) = kar_lbaudio__near_8005dff8(0);
    FS32(arg0, 0x70) = 0;
    FS32(arg0, 0x74) = 2;
    FS32(arg0, 0x78) = 1;
    FS32(arg0, 0x7C) = 0;
    FS32(arg0, 0x80) = 0;
    FS32(arg0, 0x84) = 0;
    Vec3f *box = (Vec3f *) ((char *) kar_diag__803ad760((s32) (u32) lbl_805DDBC4, 0, &lbl_805DBB50, &lbl_805DBB40, 0) + 0x30);
    Vec3f lo = box[0];
    Vec3f hi = box[1];
    Vec3f center;
    PSVECAdd(&lo, &hi, &center);
    Vec3f *out = (Vec3f *) ((char *) arg0 + 0x98);
    *out = center;
    PSVECScale(out, out, 0.5f);
    if (lo.x > hi.x) {
        FF32(arg0, 0xA4) = lo.x;
        FF32(arg0, 0xB0) = hi.x;
    } else {
        FF32(arg0, 0xB0) = lo.x;
        FF32(arg0, 0xA4) = hi.x;
    }
    if (lo.y > hi.y) {
        FF32(arg0, 0xA8) = lo.y;
        FF32(arg0, 0xB4) = hi.y;
    } else {
        FF32(arg0, 0xB4) = lo.y;
        FF32(arg0, 0xA8) = hi.y;
    }
    if (lo.z > hi.z) {
        FF32(arg0, 0xAC) = lo.z;
        FF32(arg0, 0xB8) = hi.z;
    } else {
        FF32(arg0, 0xB8) = lo.z;
        FF32(arg0, 0xAC) = hi.z;
    }
    Vec3f diff;
    PSVECSubtract(&hi, &lo, &diff);
    f32 mag2 = (diff.x * diff.x) + (diff.z * diff.z);
    f32 mag = 0.0f;
    if (mag2 > 0.0f) {
        f64 e0 = __frsqrte(mag2);
        f64 e1 = 0.5 * e0 * -(((f64) mag2 * (e0 * e0)) - 3.0);
        f64 e2 = 0.5 * e1 * -(((f64) mag2 * (e1 * e1)) - 3.0);
        mag = (f32) ((f64) mag2 * (0.5 * e2 * -(((f64) mag2 * (e2 * e2)) - 3.0)));
    }
    FF32(arg0, 0xBC) = 0.5f * mag;
    f32 diffx = FF32(arg0, 0xA4) - FF32(arg0, 0xB0);
    if (diffx < 0.0f) {
        diffx = -diffx;
    }
    FF32(arg0, 0xA0) = FF32(arg0, 0xA0) + ((0.5f * diffx) / (f32) tan(0.5235987901687622));
    return arg0;
}

extern "C" f32 *kar_a2d_kurakko__near_80378900(f32 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        char *p = (char *) arg0;
        for (s32 i = 0; i < 4; i++) {
            kar_lbaudio_mark_auto_track_started(FS32(p, 4));
            kar_lbaudio_mark_auto_track_started(FS32(p, 8));
            kar_lbaudio_release_track_handle_when_idle(FS32(p, 0xC));
            p += 0x18;
        }
        p = (char *) arg0;
        for (s32 i = 0; i < 4; i++) {
            kar_lbaudio_mark_auto_track_started(FS32(p, 0x60));
            p += 4;
        }
        kar_lbaudio_mark_auto_track_started(FS32(arg0, 0x88));
        kar_lbaudio_release_track_handle_when_idle(FS32(arg0, 0x8C));
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}
