#include <dolphin/types.h>
#include <dolphin/gx/gxtypes.h>

extern "C" {
#include <global.h>
}

class RefObj {
public:
    virtual void Release(s32);
};

struct ArchiveResult {
    void **unk0;
    void **unk4;
    void ***unk8;
};

struct ArchiveHolder {
    s32 pad0;
    s32 unk4;
    s32 unk8;
    u16 unkC;
    u16 unkE;
    s32 unk10;
};

class WipeCameraHolder : public RefObj {
public:
    ArchiveResult *unk4;
    void *unk8;
    void *unkC;
    s32 unk10;
    s32 unk14;
    u8 unk18;
    u8 pad19[3];
    void *unk1C;
};

class WipeModelHolder : public RefObj {
public:
    s32 pad4[6];
    void *unk1C;
    s32 unk20;
    void *unk24;
    s32 pad28;
};

class JobjModelHolder : public RefObj {
public:
    void *unk4;
    void *unk8;
};

class ParticleHolder : public RefObj {
public:
    s32 unk4;
    void *unk8;
    void *unkC;
    s32 unk10;
};

class WipeCamera2Holder : public RefObj {
public:
    void *unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
};

class Slot4Obj : public RefObj {
public:
};

class Slot8Obj : public RefObj {
public:
    void *unk4;
};

struct GameEffectEmbedB {
    s32 head[6];
    void *archives[7];
};

struct GameEffect {
    void *unk0;
    s32 unk4;
    void *unk8;
    s32 unkC[6];
    GameEffectEmbedB unk24;
    ParticleHolder *unk58;
    WipeCamera2Holder *unk5C;
    WipeCameraHolder *unk60;
    WipeModelHolder *unk64;
    Slot4Obj *unk68;
    Slot8Obj *unk6C;
    JobjModelHolder *unk70;
    ArchiveHolder *unk74;
};

struct Vec3f {
    f32 x, y, z;
};

struct Vec4f {
    f32 x, y, z, w;
};

struct ParticleBuf {
    s32 pad0[2];  //0x00
    Vec3f pos;    //0x08
    Vec4f quat;   //0x14
};

struct ParticleHandle {
    s32 pad0[21];       //0x00
    ParticleBuf *unk54; //0x54
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

struct GameEffectItem : public GameEffectItemBase {
    s32 unk4;     //0x04
    s32 unk8;     //0x08
    s32 unkC;     //0x0C type
    s32 unk10;    //0x10 kind
    s32 unk14;    //0x14
    s32 unk18;    //0x18
    s32 unk1C;    //0x1C
    s32 unk20;    //0x20
    Vec3f *unk24; //0x24
    Vec4f *unk28; //0x28
    s32 unk2C;    //0x2C
    s32 unk30;    //0x30
    s32 unk34;    //0x34
    u8 unk38;     //0x38
    u8 unk39;     //0x39
    ParticleHandle *unk3C; //0x3C
    void *unk40;  //0x40
    s32 unk44;    //0x44
    u16 unk48;    //0x48
};

extern "C" {

extern char lbl_804F2B30[]; /* "ModelEffectRipple" */

void GXInvalidateVtxCache(void);
void GXInvalidateTexAll(void);

BOOL HSD_CObjSetCurrent(void *cobj);
void HSD_CObjEndCurrent(void);
void HSD_StateSetColorUpdate(u32 enable);

void kar_psdisp__80433f00(u32, s32);
void kar_a2d_effecthandle__near_8037dc54(void *, s32);
void *kar_diag__803ad760(s32, s32, void *, void *, s32);

void *kar_a2d_effecthandle__8037b028(void *, s32, s32, void *, void *, s32);
void kar_a2d_game_effect__near_8037af90(GameEffectItem *);
extern char lbl_804BDF2C[0x28];
extern char lbl_804BDF70[0x28];

void kar_particle__near_8042b840(u16, s32);
void kar_psinterpret__near_80430394(u16);

}

#define ASSERT2(line, cond, file, str) \
    ((cond) ? ((void) 0) : __assert(file, line, str))

class DiagObj {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual DiagObj *GetNext();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
};

extern "C" {
extern char lbl_804F2B44[]; /* "ObjCollect<ModelEffectRipple>" */
extern char lbl_804F2B64[]; /* "" */
extern char lbl_804F2B80[]; /* "ObjCollect<PostDrawEffect>" */
extern char lbl_804F2B70[]; /* "PostDrawEffect" */
extern char lbl_804F2B9C[]; /* "" */
extern char lbl_804F2BB8[]; /* "ObjCollect<EffectLantern>" */
extern char lbl_804F2BA8[]; /* "EffectLantern" */
extern char lbl_804F2BD4[]; /* "" */
extern char lbl_804F2BEC[]; /* "ObjCollect<CommicSign>" */
extern char lbl_804F2BE0[]; /* "CommicSign" */
extern char lbl_804F2C04[]; /* "" */
extern char lbl_804F2C1C[]; /* "ObjCollect<GameScript>" */
extern char lbl_804F2C50[]; /* "ObjCollect<EffectMapFade>" */
extern char lbl_804F2C40[]; /* "EffectMapFade" */
extern char lbl_804F2C6C[]; /* "" */
extern char lbl_804F2C88[]; /* "ObjCollect<EffectHandle>" */
extern char lbl_804F2C78[]; /* "EffectHandle" */
extern char lbl_804F2CA4[]; /* "" */
extern char lbl_804F2CC8[]; /* "Singleton<GameEffect>" */
extern char lbl_804F2CBC[]; /* "GameEffect" */
extern char lbl_804F2CE0[]; /* "" */
extern char lbl_804F2E64[]; /* "ObjCollect<ModelEffect>" */
extern char lbl_804F2E58[]; /* "ModelEffect" */
extern char lbl_804F2E7C[]; /* "" */
extern char lbl_804F2E9C[]; /* "Singleton<CommicSignContainer>" */
extern char lbl_804F2EF8[]; /* "Singleton<EffectMapFadeContainer>" */
extern char lbl_804F2F54[]; /* "Singleton<EffectSlideBlurMgr>" */
extern char lbl_804F2FB0[]; /* "Singleton<EffectLanternContainer>" */
extern char lbl_804F300C[]; /* "Singleton<WipeEffectContainer>" */
extern char lbl_804F3068[]; /* "Singleton<PostDrawEffectContainer>" */
extern char lbl_804F30C8[]; /* "Singleton<ModelEffectContainer>" */
}

struct NamePair {
    char *a;
    char *b;
};

static NamePair lbl_805DBB88 = {lbl_804F2B44, 0};
static NamePair lbl_805DBB90 = {lbl_804F2B30, lbl_804F2B64};
static NamePair lbl_805DBB98 = {lbl_804F2B80, 0};
static NamePair lbl_805DBBA0 = {lbl_804F2B70, lbl_804F2B9C};
static NamePair lbl_805DBBA8 = {lbl_804F2BB8, 0};
static NamePair lbl_805DBBB0 = {lbl_804F2BA8, lbl_804F2BD4};
static NamePair lbl_805DBBB8 = {lbl_804F2BEC, 0};
static NamePair lbl_805DBBC0 = {lbl_804F2BE0, lbl_804F2C04};
static NamePair lbl_805DBBC8 = {lbl_804F2C1C, 0};
static NamePair lbl_805DBBD0 = {lbl_804F2C50, 0};
static NamePair lbl_805DBBD8 = {lbl_804F2C40, lbl_804F2C6C};
static NamePair lbl_805DBBE0 = {lbl_804F2C88, 0};
static NamePair lbl_805DBBE8 = {lbl_804F2C78, lbl_804F2CA4};
static NamePair lbl_805DBBF0 = {lbl_804F2CC8, 0};
static NamePair lbl_805DBBF8 = {lbl_804F2CBC, lbl_804F2CE0};
static char lbl_805DBC00[6] = "model";
static char lbl_805DBC08[6] = "jobj_";
static NamePair lbl_805DBC10 = {lbl_804F2E64, 0};
static NamePair lbl_805DBC18 = {lbl_804F2E58, lbl_804F2E7C};
static NamePair lbl_805DBC20 = {lbl_804F2E9C, 0};
static NamePair lbl_805DBC28 = {lbl_804F2EF8, 0};
static NamePair lbl_805DBC30 = {lbl_804F2F54, 0};
static NamePair lbl_805DBC38 = {lbl_804F2FB0, 0};
static NamePair lbl_805DBC40 = {lbl_804F300C, 0};
static NamePair lbl_805DBC48 = {lbl_804F3068, 0};
static NamePair lbl_805DBC50 = {lbl_804F30C8, 0};

extern "C" s32 lbl_805DDA58;
extern "C" s32 lbl_805DDAE8;
extern "C" s32 lbl_805DDADC;
extern "C" s32 lbl_805DDA4C;

extern "C" {
s32 lbl_805DDA28;
s32 lbl_805DDA2C;
s32 lbl_805DDA30;
}

class JobjMgrObj : public DiagObj {
public:
    s32 pad4;
    s32 pad8;
    void *unkC;
    void *unk10;
};

extern "C" {
void *kar_a2d_wipeeffect__near_8037efb0(void *, void *);
void kar_a2d_wipeeffect__8037e3cc(void *, void *);
void kar_a2d_wipeeffect__near_8037e42c(void *, void *, void *);
void *kar_a2d_effecthandle__near_8037cf54(u32);
void *kar_a2d_effecthandle__near_8037e14c(void *, void *);

void *HSD_CObjLoadDesc(void *);
void *HSD_LObjLoadDesc(void *);
void *HSD_JObjLoadJoint(void *);
void HSD_JObjSetFlagsAll(void *, u32);

void kar_lbarchive__near_80059520(s32, void *, const char *, ...);

void kar_a2d_wipeeffect__near_8037f3bc(void *, s32);
void kar_a2d_effecthandle__near_8037e210(void *);
void kar_a2d_wipeeffect__near_8037ea38(void *);
void kar_a2d_effect_slideblur__near_80381f78(void *);
void kar_a2d_effecthandle__near_8037b33c(GameEffectItem *, s32);
void PSVECAdd(void *, void *, void *);
void psInterpretParticles(s32);
void kar_generator__near_804324ec(s32);
void kar_generator__near_80433154(s32);
void kar_a2d_wipeeffect__near_8037e48c(void *);
void kar_a2d_effect_slideblur__near_803805b4(void *);
}

extern "C" s32 lbl_805DDB00;
extern "C" s32 lbl_805DDAF4;

extern "C" {
void *fn_8038CB28(s32);
void kar_a2d_game_lib__near_8028b050(void *, s32, s32, s32, void *);
s32 kar_a2d_game_lib__near_8028b11c(s32, s32);
}

namespace {
extern "C" void kar_a2d_game_lib__near_8028b050(void *, s32, s32, s32);
}

extern "C" {
extern void *lbl_805DDB90;
extern void *lbl_805DDB94;
extern void *lbl_805DDB98;
extern void *lbl_805DDB9C;
extern void *lbl_805DDBA0;
extern void *lbl_805DDBDC;
extern void *lbl_805DDBE0;
extern void *lbl_805DDBE4;

extern char lbl_804BCF90[0xC];
extern char lbl_804BCFBC[0xC];
extern char lbl_804BCFEC[0xC];
extern char lbl_804BD01C[0xC];
extern char lbl_804BD048[0xC];
extern char lbl_804BD074[0xC];
extern char lbl_804BD0A4[0xC];
extern char lbl_804BD0D4[0xC];
extern char lbl_804BD100[0xC];
extern char lbl_804BD12C[0xC];
extern char lbl_804BD15C[0xC];
extern char lbl_804BD18C[0xC];
extern char lbl_804BD1B8[0xC];
extern char lbl_804BD1E8[0xC];
extern char lbl_804BD20C[0xC];
extern char lbl_804BD230[0xC];
}

struct GameEffectSlots {
    char pad[0xC];
    u16 unkC;
    u16 unkE;
};

extern "C" void kar_a2d_game_effect__80379f94(GameEffect *arg0, u32 arg1) {
    char *base = lbl_804F2B30;
    void *sp14 = NULL;
    void *sp10;
    void *spC;
    void *sp8;

    kar_lbarchive__near_80059520(arg0->unk74->unk4, &sp14, base + 0x22C, 0);
    ASSERT2(0xAB, sp14, base + 0x248, base + 0x25C);
    WipeModelHolder *wm = arg0->unk64;
    wm->unk1C = sp14;
    if (wm->unk1C != NULL) {
        DiagObj *obj = (DiagObj *) kar_diag__803ad760(lbl_805DDAE8, 0, &lbl_805DBBB0, &lbl_805DBBA8, 0);
        while (obj != NULL) {
            kar_a2d_wipeeffect__near_8037efb0(obj, sp14);
            obj = obj->GetNext();
        }
    }

    sp10 = NULL;
    kar_lbarchive__near_80059520(arg0->unk74->unk4, &sp10, base + 0x268, 0);
    ASSERT2(0xB1, sp10, base + 0x248, base + 0x280);
    WipeCameraHolder *wc = arg0->unk60;
    wc->unk4 = (ArchiveResult *) sp10;
    if (wc->unk4 != NULL) {
        void *model = *wc->unk4->unk0;
        ASSERT2(0x7D, model, base + 0x28C, lbl_805DBC00);
        kar_a2d_wipeeffect__8037e3cc(wc, *(void **) model);
        kar_a2d_wipeeffect__near_8037e42c(wc, model, wc->unk1C);
        wc->unk8 = HSD_CObjLoadDesc(*wc->unk4->unk4);
        wc->unkC = HSD_LObjLoadDesc(**wc->unk4->unk8);
    }

    sp10 = NULL;
    kar_lbarchive__near_80059520(arg0->unk74->unk4, &sp10, base + 0x2A0, 0);
    ASSERT2(0xB7, sp10, base + 0x248, base + 0x280);
    JobjModelHolder *jm = arg0->unk70;
    ArchiveResult *ar = (ArchiveResult *) sp10;
    void *model = *ar->unk0;
    ASSERT2(0xBE, model, base + 0x2B8, lbl_805DBC00);
    jm->unk4 = model;
    JobjMgrObj *obj2 = (JobjMgrObj *) kar_diag__803ad760(lbl_805DDADC, 0, &lbl_805DBBC0, &lbl_805DBBB8, 0);
    while (obj2 != NULL) {
        void *m = jm->unk4;
        if (m != NULL) {
            obj2->unkC = m;
            void *deref = *(void **) m;
            if (obj2->unk10 == NULL) {
                obj2->unk10 = HSD_JObjLoadJoint(deref);
                ASSERT2(0x48, obj2->unk10, base + 0x2B8, lbl_805DBC08);
                HSD_JObjSetFlagsAll(obj2->unk10, 0x10);
            }
        }
        obj2 = (JobjMgrObj *) obj2->GetNext();
    }
    jm->unk8 = HSD_CObjLoadDesc(*ar->unk4);

    sp10 = NULL;
    kar_lbarchive__near_80059520(arg0->unk74->unk4, &sp10, base + 0x2CC, 0);
    if (sp14 != NULL) {
        arg0->unk58->unk10 = *(s32 *) *(void **) sp10;
    }

    for (u32 i = 0; i < 7; i++) {
        spC = NULL;
        kar_lbarchive__near_80059520(arg0->unk74->unk4, &spC, (const char *) kar_a2d_effecthandle__near_8037cf54(i), 0);
        ASSERT2(0xC3, spC, base + 0x248, base + 0x2E4);
        arg0->unk24.archives[i] = spC;
    }

    if (arg1 != 0U) {
        sp8 = NULL;
        kar_lbarchive__near_80059520(arg0->unk74->unk8, &sp8, base + 0x2F0, 0);
        if (sp8 != NULL) {
            arg0->unk58->unk8 = sp8;
            DiagObj *obj = (DiagObj *) kar_diag__803ad760(lbl_805DDA4C, 0, &lbl_805DBB90, &lbl_805DBB88, 0);
            while (obj != NULL) {
                kar_a2d_effecthandle__near_8037e14c(obj, sp8);
                obj = obj->GetNext();
            }
        }
        sp8 = NULL;
        kar_lbarchive__near_80059520(arg0->unk74->unk8, &sp8, base + 0x30C, 0);
        if (sp8 != NULL) {
            arg0->unk58->unkC = sp8;
        }
    }
}

extern "C" GameEffect *kar_a2d_game_effect__near_8037a3b0(GameEffect *arg0, s32 arg1, ArchiveHolder *arg2) {
    s32 mode = arg1;
    *(void **) arg0 = lbl_804BD20C;
    lbl_805DDB90 = arg0;
    *(void **) arg0 = lbl_804BD230;
    arg0->unk58 = NULL;
    arg0->unk5C = NULL;
    arg0->unk60 = NULL;
    arg0->unk64 = NULL;
    arg0->unk68 = NULL;
    arg0->unk6C = NULL;
    arg0->unk70 = NULL;
    arg0->unk74 = arg2;
    lbl_805DDB90 = arg0;

    kar_a2d_game_lib__near_8028b050(&arg0->unk24, 0x294, 0x1E0, 4, arg0);
    kar_a2d_game_lib__near_8028b050(&arg0->unkC, 0x294, 0x1E0, 4);
    arg0->unk8 = (void *) kar_a2d_game_lib__near_8028b11c(0x280, 0x1E0);

    {
        ParticleHolder *n = (ParticleHolder *) fn_8038CB28(0x14);
        if (n != NULL) {
            *(void **) n = lbl_804BD1B8;
            lbl_805DDBA0 = n;
            *(void **) n = lbl_804BD1E8;
            n->unk4 = 0;
            n->unk8 = NULL;
            n->unkC = NULL;
            n->unk10 = 0;
        }
        ParticleHolder * volatile tmp = n;
        tmp = NULL;
        ParticleHolder * volatile dead = n;
        ParticleHolder * volatile commit = n;
        ParticleHolder *old = arg0->unk58;
        if (old != n) {
            if (old != NULL) {
                old->Release(1);
            }
            arg0->unk58 = commit;
        }
        if (tmp != NULL) {
            tmp->Release(1);
        }
    }

    {
        WipeCamera2Holder *n = (WipeCamera2Holder *) fn_8038CB28(0x18);
        if (n != NULL) {
            *(void **) n = lbl_804BD15C;
            lbl_805DDBE4 = n;
            *(void **) n = lbl_804BD18C;
            n->unk4 = &arg0->unk24;
            n->unkC = kar_a2d_game_lib__near_8028b11c(0x280, 0x1E0);
            n->unk8 = arg1;
            n->unk10 = *(u16 *) ((char *) n->unk4 + 4);
            n->unk14 = *(u16 *) ((char *) n->unk4 + 6);
        }
        WipeCamera2Holder * volatile tmp = n;
        tmp = NULL;
        WipeCamera2Holder * volatile dead = n;
        WipeCamera2Holder * volatile commit = n;
        WipeCamera2Holder *old = arg0->unk5C;
        if (old != n) {
            if (old != NULL) {
                old->Release(1);
            }
            arg0->unk5C = commit;
        }
        if (tmp != NULL) {
            tmp->Release(1);
        }
    }

    {
        WipeCameraHolder *n = (WipeCameraHolder *) fn_8038CB28(0x20);
        if (n != NULL) {
            *(void **) n = lbl_804BD100;
            lbl_805DDB9C = n;
            *(void **) n = lbl_804BD12C;
            n->unk4 = NULL;
            n->unk10 = 0;
            n->unk8 = NULL;
            n->unkC = NULL;
            n->unk14 = kar_a2d_game_lib__near_8028b11c(0x280, 0x1E0);
            n->unk18 = 0;
            n->unk1C = NULL;
        }
        WipeCameraHolder * volatile tmp = n;
        tmp = NULL;
        WipeCameraHolder * volatile dead = n;
        WipeCameraHolder * volatile commit = n;
        WipeCameraHolder *old = arg0->unk60;
        if (old != n) {
            if (old != NULL) {
                old->Release(1);
            }
            arg0->unk60 = commit;
        }
        if (tmp != NULL) {
            tmp->Release(1);
        }
    }

    {
        WipeModelHolder *n = (WipeModelHolder *) fn_8038CB28(0x2C);
        if (n != NULL) {
            *(void **) n = lbl_804BD0A4;
            lbl_805DDBE0 = n;
            *(void **) n = lbl_804BD0D4;
            kar_a2d_game_lib__near_8028b050(&n->pad4[0], 0x294, 0x1E0, 4);
            n->unk24 = (void *) kar_a2d_game_lib__near_8028b11c(0x280, 0x1E0);
            n->unk20 = arg1;
        }
        WipeModelHolder * volatile tmp = n;
        tmp = NULL;
        WipeModelHolder * volatile dead = n;
        WipeModelHolder * volatile commit = n;
        WipeModelHolder *old = arg0->unk64;
        if (old != n) {
            if (old != NULL) {
                old->Release(1);
            }
            arg0->unk64 = commit;
        }
        if (tmp != NULL) {
            tmp->Release(1);
        }
    }

    {
        Slot4Obj *n = (Slot4Obj *) fn_8038CB28(4);
        if (n != NULL) {
            *(void **) n = lbl_804BD048;
            lbl_805DDB98 = n;
            *(void **) n = lbl_804BD074;
        }
        Slot4Obj * volatile tmp = n;
        tmp = NULL;
        Slot4Obj * volatile dead = n;
        Slot4Obj * volatile commit = n;
        Slot4Obj *old = arg0->unk68;
        if (old != n) {
            if (old != NULL) {
                old->Release(1);
            }
            arg0->unk68 = commit;
        }
        if (tmp != NULL) {
            tmp->Release(1);
        }
    }

    {
        Slot8Obj *n = (Slot8Obj *) fn_8038CB28(8);
        if (n != NULL) {
            *(void **) n = lbl_804BCFEC;
            lbl_805DDB94 = n;
            *(void **) n = lbl_804BD01C;
            n->unk4 = (void *) kar_a2d_game_lib__near_8028b11c(0x280, 0x1E0);
        }
        Slot8Obj * volatile tmp = n;
        tmp = NULL;
        Slot8Obj * volatile dead = n;
        Slot8Obj * volatile commit = n;
        Slot8Obj *old = arg0->unk6C;
        if (old != n) {
            if (old != NULL) {
                old->Release(1);
            }
            arg0->unk6C = commit;
        }
        if (tmp != NULL) {
            tmp->Release(1);
        }
    }

    {
        JobjModelHolder *n = (JobjModelHolder *) fn_8038CB28(0xC);
        if (n != NULL) {
            *(void **) n = lbl_804BCF90;
            lbl_805DDBDC = n;
            *(void **) n = lbl_804BCFBC;
            n->unk4 = NULL;
        }
        JobjModelHolder * volatile tmp = n;
        tmp = NULL;
        JobjModelHolder * volatile dead = n;
        JobjModelHolder * volatile commit = n;
        JobjModelHolder *old = arg0->unk70;
        if (old != n) {
            if (old != NULL) {
                old->Release(1);
            }
            arg0->unk70 = commit;
        }
        if (tmp != NULL) {
            tmp->Release(1);
        }
    }

    arg0->unk4 = mode;
    kar_generator__near_80433154(mode);
    kar_a2d_game_effect__80379f94(arg0, arg2->unk10);
    return arg0;
}

extern "C" void GameEffect_UpdateAllEffects(GameEffect *arg0) {
    DiagObj *obj;
    WipeModelHolder *wm = arg0->unk64;
    obj = (DiagObj *) kar_diag__803ad760(lbl_805DDAE8, 0, &lbl_805DBBB0, &lbl_805DBBA8, 0);
    while (obj != NULL) {
        kar_a2d_wipeeffect__near_8037f3bc(obj, wm->unk20);
        obj = obj->GetNext();
    }

    obj = (DiagObj *) kar_diag__803ad760(lbl_805DDA4C, 0, &lbl_805DBB90, &lbl_805DBB88, 0);
    while (obj != NULL) {
        kar_a2d_effecthandle__near_8037e210(obj);
        obj = obj->GetNext();
    }

    obj = (DiagObj *) kar_diag__803ad760(lbl_805DDA58, 0, &lbl_805DBC18, &lbl_805DBC10, 0);
    while (obj != NULL) {
        obj->v28();
        obj = obj->GetNext();
    }

    obj = (DiagObj *) kar_diag__803ad760(lbl_805DDA28, 0, &lbl_805DBBD8, &lbl_805DBBD0, 0);
    while (obj != NULL) {
        kar_a2d_wipeeffect__near_8037ea38(obj);
        obj = obj->GetNext();
    }

    obj = (DiagObj *) kar_diag__803ad760(lbl_805DDADC, 0, &lbl_805DBBC0, &lbl_805DBBB8, 0);
    while (obj != NULL) {
        kar_a2d_effect_slideblur__near_80381f78(obj);
        obj = obj->GetNext();
    }

    GameEffectItem *item = (GameEffectItem *) kar_diag__803ad760(lbl_805DDAF4, 0, &lbl_805DBBE8, &lbl_805DBBE0, 0);
    while (item != NULL) {
        if (item->unkC != 0x7531) {
            item->unk14 += 1;
            void (*fn) (GameEffectItem *) = (void (*) (GameEffectItem *)) item->unk40;
            if (fn != NULL) {
                fn(item);
            }
        }
        item = item->GetNext();
    }

    item = (GameEffectItem *) kar_diag__803ad760(lbl_805DDAF4, 0, &lbl_805DBBE8, &lbl_805DBBE0, 0);
    while (item != NULL) {
        if (item->unkC != 0x7531) {
            if (item->unk34 != 0) {
                item->unk34 -= 1;
            } else if (item->unk38 != 0) {
                kar_a2d_effecthandle__near_8037b33c(item, 0);
            } else if (item->unk10 == 2) {
                Vec3f *va = item->unk24;
                Vec4f *vb = item->unk28;
                if (va != NULL || vb != NULL) {
                    ParticleHandle *ph = item->unk3C;
                    if (ph != NULL) {
                        ParticleBuf *pb = ph->unk54;
                        if (pb != NULL) {
                            if (va != NULL) {
                                pb->pos = *va;
                            }
                            if (vb != NULL) {
                                ph->unk54->quat = *vb;
                            }
                            if (item->unk39 != 0) {
                                Vec3f *dst = &ph->unk54->pos;
                                PSVECAdd(dst, &item->unk18, dst);
                            }
                        }
                    }
                }
            }
        }
        item = item->GetNext();
    }

    psInterpretParticles(0);
    kar_generator__near_804324ec(0);

    obj = (DiagObj *) kar_diag__803ad760(lbl_805DDB00, 0, &lbl_805DBBA0, &lbl_805DBB98, 0);
    while (obj != NULL) {
        obj->v44();
        obj = obj->GetNext();
    }

    kar_a2d_wipeeffect__near_8037e48c(arg0->unk60);
    kar_a2d_effect_slideblur__near_803805b4(arg0->unk68);
}

extern "C" void kar_a2d_game_effect__near_8037ad0c(void *arg0) {
    DiagObj *obj;

    GXInvalidateVtxCache();
    GXInvalidateTexAll();
    if (HSD_CObjSetCurrent(*(void **) ((char *) arg0 + 4))) {
        obj = (DiagObj *) kar_diag__803ad760(lbl_805DDA58, 0, &lbl_805DBC18, &lbl_805DBC10, 0);
        while (obj != NULL) {
            obj->v2c();
            obj = obj->GetNext();
        }
        kar_psdisp__80433f00(0xFFFF, 0);
        HSD_StateSetColorUpdate(GX_ENABLE);
        kar_psdisp__80433f00(0xFFFF, 1);
        HSD_StateSetColorUpdate(GX_ENABLE);
        kar_psdisp__80433f00(0xFFFF, 2);
        HSD_CObjEndCurrent();
    }
    kar_a2d_effecthandle__near_8037dc54(*(void **) ((char *) arg0 + 0x5C), 0);
}

extern "C" u16 kar_a2d_game_effect__near_8037adf8(void *arg0, s32 arg1) {
    if (arg1 > 0x3E7) {
        return (*(GameEffectSlots **) ((char *) arg0 + 0x74))->unkE;
    }
    return (*(GameEffectSlots **) ((char *) arg0 + 0x74))->unkC;
}

struct EffectDesc {
    s32 pad0[3];
    s32 unkC;
    s32 unk10;
    s32 pad14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    void *unk24;
    s32 pad28[2];
    s32 unk30;
};

extern "C" void *kar_a2d_game_effect__near_8037ae18(GameEffectItem *arg0, EffectDesc *arg1) {
    s32 type;

    *(void **) arg0 = lbl_804BDF2C;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->Init();
    *(void **) arg0 = lbl_804BDF70;
    kar_a2d_game_effect__near_8037af90(arg0);
    type = arg1->unkC;
    if (type != 0x7531) {
        if (type == -1) {
            kar_a2d_effecthandle__8037b028(arg0, -1, 0, 0, 0, 0);
        } else {
            switch (arg1->unk10) {
            case 0:
                kar_a2d_effecthandle__8037b028(arg0, type, 0, 0, 0, 0);
                break;
            case 1:
                kar_a2d_effecthandle__8037b028(arg0, type, 1, (void *) arg1->unk30, 0, 0);
                break;
            case 2: {
                s32 v18 = arg1->unk18;
                s32 v1c = arg1->unk1C;
                s32 v20 = arg1->unk20;
                s32 tmp[3];
                tmp[0] = v18;
                tmp[1] = v1c;
                tmp[2] = v20;
                kar_a2d_effecthandle__8037b028(arg0, type, 3, 0, tmp, 0);
                break;
            }
            case 3:
                kar_a2d_effecthandle__8037b028(arg0, type, 2, 0, arg1->unk24, 0);
                break;
            default:
                kar_a2d_effecthandle__8037b028(arg0, -1, 0, 0, 0, 0);
                break;
            }
        }
    }
    return arg0;
}

extern "C" void kar_a2d_game_effect__near_8037af90(GameEffectItem *arg0) {
    arg0->unkC = 0x7531;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    arg0->unk40 = 0;
    arg0->unk44 = 0;
    arg0->unk3C = 0;
    arg0->unk38 = 0;
    arg0->unk39 = 0;
    arg0->unk48 = 0;
    arg0->unk30 = 0;
    arg0->unk24 = 0;
    arg0->unk28 = 0;
    arg0->unk2C = 0;
}

extern "C" void kar_a2d_game_effect__near_8037afd0(GameEffectItem *arg0, u8 arg1) {
    u8 keep;
    void *particle;

    keep = arg1;
    particle = arg0->unk3C;
    if (particle != NULL) {
        if (*(u32 *) ((char *) particle + 0x10) != 0U) {
            keep = 1;
        }
        if (keep != 0) {
            kar_particle__near_8042b840(arg0->unk48, 0);
            return;
        }
        kar_psinterpret__near_80430394(arg0->unk48);
    }
}
