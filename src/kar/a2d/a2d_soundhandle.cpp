#include <dolphin/types.h>

extern "C" {
#include <global.h>
int kar_lbaudio__near_80061834(int, int, int);
int kar_lbaudio_is_track_handle_playing(void);
}

enum { AudienceLevelMax = 3 };

struct SoundHandle {
    char pad0[0xC];
    int unkC;   //0x0C
    int unk10;  //0x10
};

static const int lbl_8048B3D0[3][3] = {
    {0x00060037, 0x00060038, 0x00060039},
    {0x00060033, 0x00060034, 0x00060034},
    {0x00060035, 0x00060036, 0x00060036},
};

extern "C" int kar_a2d_soundhandle__80379b1c(SoundHandle *h, int row, unsigned int level) {
    int track;
    bool playing;
    assert_line(0xBE, level < AudienceLevelMax);
    track = lbl_8048B3D0[row][level];
    if (h->unkC != -1 && track == h->unk10) {
        playing = kar_lbaudio_is_track_handle_playing();
        if (playing) {
            return 0;
        }
    }
    h->unkC = kar_lbaudio__near_80061834(track, 0x7F, 0);
    if (h->unkC != -1) {
        h->unk10 = track;
        return 1;
    }
    return 0;
}

struct NamePair {
    char *a;
    char *b;
};

struct EffectWobbleSource {
    f32 x;    //0x00
    s32 pad4; //0x04
    f32 z;    //0x08
};

struct ParticleTypeHandle {
    char pad0[0x1C];
    u16 unk1C; //0x1C
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
    char pad4[0x28];             //0x04
    EffectWobbleSource *unk2C;   //0x2C
    char pad30[0xC];             //0x30
    ParticleTypeHandle *unk3C;   //0x3C
};

struct ArchiveEntryResult {
    char pad0[2];
    u16 unk2; //0x02
};

struct Placement3f {
    f32 x, y, z;
};

static Placement3f lbl_804F2CB0 = {0.0f, 0.0f, 0.0f};

static char lbl_804F2B30[] = "ModelEffectRipple";

struct SoundOwner {
    char pad0[0x4];
    s32 unk4;                          //0x04
    s32 unk8;                          //0x08
    u16 unkC;                          //0x0C
    u16 unkE;                          //0x0E
    char pad10[0x4C];
    int (*unk5C)(u32);                 //0x5C
    char pad60[0x2C];
    ParticleTypeHandle *unk8C;         //0x8C
    char pad90[0xC];
    u16 unk9C;                         //0x9C
    char pad9E[2];
    f32 unkA0;                         //0xA0
    f32 unkA4;                         //0xA4
    f32 unkA8;                         //0xA8
    f32 unkAC;                         //0xAC
};

extern "C" {
extern s32 lbl_805DDAF4;
extern s32 lbl_805DDB90;
extern NamePair lbl_805DBBE0;
extern NamePair lbl_805DBBE8;
extern NamePair lbl_805DBBF0;
extern NamePair lbl_805DBBF8;
extern void (*lbl_805DE36C)(u32, SoundOwner *);

void *kar_diag__803ad760(s32, s32, void *, void *, s32);

void kar_lbarchive__near_80059520(s32, void *, const char *, ...);
void kar_particle__near_8042ad44(s32, const char *);
void kar_particle__near_8042ba60(void *, void *);
void kar_particle__8042abe8(u16, void *, void *, void *, void *);
void kar_psinterpret__near_80430298(s32);
void kar_psdisp__near_80437bf0(s32, s32);
void HSD_JObjSetJSoundCallback(void *);
void HSD_JObjSetDPtclCallback(void *);
void HSD_JObjSetPtclTargetCallback(void *);
void kar_generator__near_80433098();
void kar_generator__near_804328a0();
void kar_particle__near_8042b6a0();
void kar_a2d_soundhandle__near_80379de4(void *, u32);
}

static inline GameEffectItem *kar_a2d_soundhandle__FindByHandle(GameEffectItem *item, ParticleTypeHandle *owner) {
    while (item != NULL) {
        ParticleTypeHandle *handle = item->unk3C;
        if (handle != NULL && handle->unk1C == owner->unk1C && item->unk2C != NULL) {
            return item;
        }
        item = item->GetNext();
    }
    return NULL;
}

extern "C" int kar_a2d_soundhandle__near_80379bf8(SoundOwner *arg0) {
    ParticleTypeHandle *owner;
    GameEffectItem *item;

    owner = arg0->unk8C;
    item = (GameEffectItem *) kar_diag__803ad760(lbl_805DDAF4, 0, &lbl_805DBBE8, &lbl_805DBBE0, 0);
    item = kar_a2d_soundhandle__FindByHandle(item, owner);
    if (item != NULL && item->unk2C != NULL) {
        arg0->unk9C = (u16) (arg0->unk9C | 2);
        arg0->unkAC = 1.0f;
        arg0->unkA0 = item->unk2C->x;
        arg0->unkA4 = 0.0f;
        arg0->unkA8 = item->unk2C->z;
    }
    return 0;
}

extern "C" int kar_a2d_soundhandle__near_80379cdc(u32 arg0) {
    void *item = kar_diag__803ad760(lbl_805DDB90, 0, &lbl_805DBBF8, &lbl_805DBBF0, 0);
    kar_a2d_soundhandle__near_80379de4(item, arg0);
    return 0;
}

static inline GameEffectItem *kar_a2d_soundhandle__FindById(GameEffectItem *item, u32 id) {
    while (item != NULL) {
        if (((u32) item->unk3C == id) && (item->unk2C != NULL)) {
            return item;
        }
        item = item->GetNext();
    }
    return NULL;
}

extern "C" void kar_a2d_soundhandle__near_80379d28(u32 arg0, SoundOwner *arg1) {
    GameEffectItem *item;

    if (arg0 != 0U) {
        item = (GameEffectItem *) kar_diag__803ad760(lbl_805DDAF4, 0, &lbl_805DBBE8, &lbl_805DBBE0, 0);
        item = kar_a2d_soundhandle__FindById(item, arg0);
        if (item != NULL && item->unk2C != NULL) {
            kar_particle__near_8042ba60(arg1, &lbl_804F2CB0);
        }
    }
    arg1->unk5C = kar_a2d_soundhandle__near_80379cdc;
}

extern "C" void kar_a2d_soundhandle__near_80379de4(void *unused, u32 arg1) {
    GameEffectItem *item;

    item = (GameEffectItem *) kar_diag__803ad760(lbl_805DDAF4, 0, &lbl_805DBBE8, &lbl_805DBBE0, 0);
    while (item != NULL) {
        if ((u32) item->unk3C == arg1) {
            item->unk3C = NULL;
            return;
        }
        item = item->GetNext();
    }
}

extern "C" void kar_a2d_soundhandle__near_80379e58(SoundOwner *arg0) {
    ArchiveEntryResult *sp10;
    ArchiveEntryResult *sp14;
    ArchiveEntryResult *sp18;
    ArchiveEntryResult *sp1C;

    kar_particle__near_8042ad44(0, lbl_804F2B30);
    kar_psinterpret__near_80430298(0);
    kar_psdisp__near_80437bf0(0x40, 0x80);
    HSD_JObjSetJSoundCallback(kar_generator__near_80433098);
    HSD_JObjSetDPtclCallback(kar_generator__near_804328a0);
    HSD_JObjSetPtclTargetCallback(kar_particle__near_8042b6a0);
    lbl_805DE36C = kar_a2d_soundhandle__near_80379d28;
    kar_lbarchive__near_80059520(arg0->unk4, &sp10, "a2dcommon_form", &sp18, "a2dcommon_ptcl", &sp1C, "a2dcommon_ref", &sp14, "a2dcommon_texg", 0);
    arg0->unkC = sp18->unk2;
    kar_particle__8042abe8(arg0->unkC, sp18, sp14, sp1C, sp10);
    kar_lbarchive__near_80059520(arg0->unk8, &sp10, "course_form", &sp18, "course_ptcl", &sp1C, "course_ref", &sp14, "course_texg", 0);
    arg0->unkE = sp18->unk2;
    kar_particle__8042abe8(arg0->unkE, sp18, sp14, sp1C, sp10);
}
