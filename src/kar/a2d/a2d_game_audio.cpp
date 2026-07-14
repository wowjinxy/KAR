#include <dolphin/types.h>

extern "C" {
#include <global.h>
}

struct Vec3 {
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
    virtual void v20();
    virtual DiagObj *GetNext();
};

struct SoundHandle : public DiagObj {
    s32 pad4;   //0x04
    s32 pad8;   //0x08
    s32 unkC;   //0x0C
    s32 unk10;  //0x10
    s32 unk14;  //0x14
    s32 unk18;  //0x18
    u8 unk1C;   //0x1C
    u8 pad1D[3];
    s32 unk20;  //0x20
    s32 unk24;  //0x24
    f32 unk28;  //0x28
    f32 unk2C;  //0x2C
    f32 unk30;  //0x30
    u8 unk34;   //0x34
    u8 pad35[3];
    s32 unk38;  //0x38
};

struct EngineChannel {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 pad10[8];
};

struct EngineAudioState {
    EngineChannel ch[4]; //0x00
    s32 unk60[4];        //0x60
    s32 unk70;           //0x70
    s32 unk74;           //0x74
    s32 unk78;           //0x78
    s32 unk7C;           //0x7C
    s32 unk80;           //0x80
    s32 unk84;           //0x84
    s32 unk88;           //0x88
    s32 unk8C;           //0x8C
    u8 pad90[0x8];       //0x90
    Vec3 unk98;          //0x98
    Vec3 unkA4;          //0xA4
    Vec3 unkB0;          //0xB0
};

struct GameCameraPos {
    u8 pad0[0xC];
    Vec3 pos; //0xC
};

struct GameCamera {
    u8 pad0[0x24];
    GameCameraPos *unk24; //0x24
    GameCameraPos *unk28; //0x28
};

struct GameCameraHolder {
    u8 pad0[0x8];
    GameCamera *unk8; //0x8
};

class KirbyBase {
public:
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
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
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual s32 GetPanAngle();
};

struct KirbyMgr {
    u8 pad0[0x8];
    KirbyBase *kirbies[4]; //0x8
};

extern "C" {

void *kar_diag__803ad760(s32, s32, void *, void *, s32);

void PSVECAdd(void *, void *, void *);
void PSVECSubtract(void *, void *, void *);
void PSVECScale(void *, void *, f32);
void PSVECNormalize(void *, void *);
f32 PSVECMag(void *);
f64 kar_atan2(f32, f32);

s32 kar_lbaudio__near_8005b8ac(void);
s32 kar_lbaudio__near_8005e184(void);
void kar_lbaudio__near_8005e1a8(s32);
void kar_lbaudio__near_8005e574(void);
void kar_lbaudio__near_8005e788(void);
s32 kar_lbaudio__near_8005f57c(s32, s32, s32);
s32 kar_lbaudio__near_8005f59c(s32, s32, s32);
s32 kar_lbaudio__near_8005f5bc(s32, s32);
void kar_lbaudio__near_8005f688(s32, s32, f32);
s32 kar_lbaudio__near_8005f6a8(void *, s32);
void kar_lbaudio__near_8005fca0(s32, s32);
void kar_lbaudio__near_80061224(void *, void *, void *);
s32 kar_lbaudio_is_track_handle_playing(s32);
void kar_lbaudio_set_track_mode_fixed_position(s32, s32, f32);
void kar_lbaudio_stop_track_handle_chain(void *);

extern volatile f32 lbl_805E4B08;
extern f32 lbl_805DC8BC[];
extern s32 lbl_805DDB18;
extern s32 lbl_805DDB44;
extern s32 lbl_805DDB7C;
extern void *lbl_805DDC70;
extern s32 lbl_804F2978[];
extern s32 lbl_80569840[];
extern char lbl_804BE0C4[];
extern char lbl_804BE104[];

extern char lbl_804F2468[];
extern char lbl_804F2474[];
extern char lbl_804F2488[];
extern char lbl_804F2A74[];
extern char lbl_804F2A80[];
extern char lbl_804F2A98[];
extern char lbl_804F2AA4[];
extern char lbl_804F2AB0[];
extern char lbl_804F2AC8[];

}

#define FLT_MAX lbl_805DC8BC[0]

struct FloatArr3 {
    f32 v[3];
};

struct FloatArr5 {
    f32 v[5];
};

struct IntArr4 {
    s32 v[4];
};

extern const Vec3 lbl_8048B3A0 = {0.0f, 1.0f, 0.0f};
extern const f32 lbl_8048B3AC[5] = {0.0f, 1.0f, 0.9f, 0.8f, 0.7f};
extern const s32 lbl_8048B3C0[4] = {0, 50, -50, 100};

extern const f32 lbl_805E4B50;

struct NamePair {
    char *a;
    char *b;
};

NamePair lbl_805DBB58 = {lbl_804F2474, 0};
NamePair lbl_805DBB60 = {lbl_804F2468, lbl_804F2488};
NamePair lbl_805DBB68 = {lbl_804F2A80, 0};
NamePair lbl_805DBB70 = {lbl_804F2A74, lbl_804F2A98};
NamePair lbl_805DBB78 = {lbl_804F2AB0, 0};
NamePair lbl_805DBB80 = {lbl_804F2AA4, lbl_804F2AC8};

extern "C" u8 kar_a2d_game_audio__near_803792dc(void *unused, s32 arg1, s32 arg2);
extern "C" u8 kar_a2d_game_audio__near_80379310(void *unused, s32 arg1, s32 arg2);
extern "C" s32 kar_a2d_game_audio__near_803799b8(SoundHandle *arg0);

extern "C" void kar_a2d_game_audio__803789c4(EngineAudioState *arg0) {
    GameCamera *cam;
    Vec3 delta;
    FloatArr3 outVec;
    f32 selA, selB, selC;
    f32 absX, absY, absZ;
    f32 ratioA, ratioB, ratioC;
    f32 t_ratio;
    s32 i;
    KirbyMgr *kirbyMgr;
    SoundHandle *item;

    cam = ((GameCameraHolder *) kar_diag__803ad760(lbl_805DDB7C, 0, &lbl_805DBB70, &lbl_805DBB68, 0))->unk8;
    ((s32 *) &outVec)[0] = ((s32 *) &lbl_8048B3A0)[0];
    ((s32 *) &outVec)[1] = ((s32 *) &lbl_8048B3A0)[1];
    ((s32 *) &outVec)[2] = ((s32 *) &lbl_8048B3A0)[2];
    PSVECSubtract(&cam->unk28->pos, &cam->unk24->pos, &delta);

    if (delta.x > lbl_805E4B08) {
        selA = arg0->unkA4.x;
    } else {
        selA = arg0->unkB0.x;
    }
    if (delta.y > lbl_805E4B08) {
        selB = arg0->unkA4.y;
    } else {
        selB = arg0->unkB0.y;
    }
    if (delta.z > lbl_805E4B08) {
        selC = arg0->unkA4.z;
    } else {
        selC = arg0->unkB0.z;
    }

    if (delta.x < lbl_805E4B08) {
        absX = -delta.x;
    } else {
        absX = delta.x;
    }
    if (absX > 0.0001f) {
        ratioA = (selA - cam->unk24->pos.x) / delta.x;
    } else {
        ratioA = FLT_MAX;
    }

    if (delta.y < lbl_805E4B08) {
        absY = -delta.y;
    } else {
        absY = delta.y;
    }
    if (absY > 0.0001f) {
        ratioB = (selB - cam->unk24->pos.y) / delta.y;
    } else {
        ratioB = FLT_MAX;
    }

    if (delta.z < lbl_805E4B08) {
        absZ = -delta.z;
    } else {
        absZ = delta.z;
    }
    if (absZ > 0.0001f) {
        ratioC = (selC - cam->unk24->pos.z) / delta.z;
    } else {
        ratioC = FLT_MAX;
    }

    if (ratioB < ratioC) {
        if (ratioB < ratioA) {
            t_ratio = ratioB;
        } else {
            t_ratio = ratioA;
        }
    } else if (ratioC < ratioA) {
        t_ratio = ratioC;
    } else {
        t_ratio = ratioA;
    }
    assert_line(0xC1, t_ratio != FLT_MAX);

    PSVECScale(&delta, &delta, t_ratio);
    PSVECAdd(&delta, &cam->unk24->pos, &delta);
    kar_lbaudio__near_80061224(&cam->unk24->pos, &delta, &outVec);

    for (i = 0; i < 4; i++) {
        if (((KirbyMgr *) kar_diag__803ad760(lbl_805DDB44, 0, &lbl_805DBB60, &lbl_805DBB58, 0))->kirbies[i] != NULL) {
            KirbyBase *kirby = ((KirbyMgr *) kar_diag__803ad760(lbl_805DDB44, 0, &lbl_805DBB60, &lbl_805DBB58, 0))->kirbies[i];
            kar_lbaudio_set_track_mode_fixed_position(arg0->ch[i].unkC, kirby->GetPanAngle(), lbl_805E4B08);
        }
    }

    item = (SoundHandle *) kar_diag__803ad760(lbl_805DDB18, 0, &lbl_805DBB80, &lbl_805DBB78, 0);
    while (item != NULL) {
        Vec3 *posPtr = (Vec3 *) &item->unk28;
        if (posPtr != NULL && kar_lbaudio_is_track_handle_playing(item->unk10)) {
            Vec3 rel;
            PSVECSubtract(posPtr, &arg0->unk98, &rel);
            rel.z = lbl_805E4B08;
            if (PSVECMag(&rel) > lbl_805E4B08) {
                f32 angle;
                PSVECNormalize(&rel, &rel);
                angle = (f32) kar_atan2(-rel.x, rel.y);
                kar_lbaudio__near_8005f688(item->unk10, (s32) (57.29578f * angle) + 0xB3, angle);
            }
        }
        if (item->unk34 != 0) {
            if (item->unk38 > 0) {
                item->unk38 -= 1;
            } else {
                kar_lbaudio__near_8005fca0(0xFF, 0x3C);
                item->unk34 = 0;
            }
        }
        item = (SoundHandle *) item->GetNext();
    }
}

extern "C" void kar_a2d_game_audio__near_80378d9c(void *unused, s32 arg1) {
    if (kar_lbaudio__near_8005e184() != 0) {
        kar_lbaudio__near_8005e574();
    }
    kar_lbaudio__near_8005e1a8(arg1);
}

extern "C" void kar_a2d_game_audio__near_80378ddc(void) {
    kar_lbaudio__near_8005e574();
    kar_lbaudio__near_8005e788();
    kar_lbaudio__near_8005b8ac();
}

extern "C" s32 kar_a2d_game_audio__near_80378e04(EngineAudioState *arg0, s32 arg1) {
    return kar_lbaudio__near_8005f59c(arg1, arg0->unk88, arg0->unk8C);
}

extern "C" void kar_a2d_game_audio__near_80378e34(EngineAudioState *arg0, s32 unused1, s32 arg2, s32 arg3) {
    s32 kind = *(&arg0->ch[arg2].unk0);
    f32 vol = (f32) arg3;
    FloatArr5 tiers = *(FloatArr5 *) &lbl_8048B3AC;

    if (arg0->unk74 == kind || arg0->unk74 == 3) {
        vol *= 0.4f;
    }
    if (arg0->unk78 == 1 || arg0->unk78 == kind) {
        vol *= tiers.v[arg0->unk80];
    } else if (arg0->unk78 == 2 || arg0->unk78 == kind) {
        vol *= tiers.v[arg0->unk84];
    } else if (arg0->unk78 == 3) {
        vol *= tiers.v[arg0->unk80 + arg0->unk84];
    }
    kar_a2d_game_audio__near_80379310(arg0, unused1, (s32) vol);
}

extern "C" void kar_a2d_game_audio__near_80378f44(EngineAudioState *arg0, s32 unused1, s32 arg2, s32 arg3) {
    s32 kind = arg0->ch[arg2].unk0;

    if (arg0->unk7C == kind || arg0->unk7C == 3) {
        IntArr4 pans = *(IntArr4 *) &lbl_8048B3C0;
        kar_a2d_game_audio__near_803792dc(arg0, unused1, arg3 + pans.v[arg2]);
    }
}

extern "C" s32 kar_a2d_game_audio__near_80378fb4(EngineAudioState *arg0, s32 arg1, s32 arg2, u8 arg3, u8 arg4) {
    s32 vol0 = arg4 ? arg0->ch[arg2].unk4 : arg0->ch[arg2].unk8;
    s32 handle;
    EngineChannel *chan = &arg0->ch[arg2];

    if (arg0->unk70 == chan->unk0 || arg0->unk70 == 3) {
        handle = -1;
        goto done;
    }
    handle = kar_lbaudio__near_8005f57c(arg1, vol0, chan->unkC);
    if (handle != -1 && arg3 != 0) {
        FloatArr5 tiers = *(FloatArr5 *) &lbl_8048B3AC;
        f32 vol = 255.0f;
        if (arg0->unk74 == chan->unk0 || arg0->unk74 == 3) {
            vol *= 0.4f;
        }
        if (arg0->unk78 == 1 || arg0->unk78 == chan->unk0) {
            vol *= tiers.v[arg0->unk80];
        } else if (arg0->unk78 == 2 || arg0->unk78 == chan->unk0) {
            vol *= tiers.v[arg0->unk84];
        } else if (arg0->unk78 == 3) {
            vol *= tiers.v[arg0->unk80 + arg0->unk84];
        }
        kar_a2d_game_audio__near_80379310(arg0, handle, (s32) vol);
        if (arg0->unk7C == chan->unk0 || arg0->unk7C == 3) {
            IntArr4 pans = *(IntArr4 *) &lbl_8048B3C0;
            kar_a2d_game_audio__near_803792dc(arg0, handle, pans.v[arg2]);
        }
    }
done:
    return handle;
}

extern "C" s32 kar_a2d_game_audio__near_8037919c(EngineAudioState *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 kind = arg0->unk70;
    s32 vol = arg0->unk60[arg3];
    if (kind == arg0->ch[arg2].unk0 || kind == 3) {
        return -1;
    }
    return kar_lbaudio__near_8005f57c(arg1, vol, arg0->ch[arg2].unkC);
}

extern "C" void kar_a2d_game_audio__near_803791fc(EngineAudioState *arg0, s32 arg1, s32 arg2) {
    s32 countA = 0, countB = 0;
    s32 v;

    arg0->ch[arg1].unk0 = arg2;

    v = arg0->ch[0].unk0;
    if (v == 1) {
        countA = 1;
    } else if (v == 2) {
        countB = 1;
    }
    v = arg0->ch[1].unk0;
    if (v == 1) {
        countA += 1;
    } else if (v == 2) {
        countB += 1;
    }
    v = arg0->ch[2].unk0;
    if (v == 1) {
        countA += 1;
    } else if (v == 2) {
        countB += 1;
    }
    v = arg0->ch[3].unk0;
    if (v == 1) {
        countA += 1;
    } else if (v == 2) {
        countB += 1;
    }
    arg0->unk80 = countA;
    arg0->unk84 = countB;
}

extern "C" void kar_a2d_game_audio__near_80379298(void) {
    kar_lbaudio__near_8005e788();
}

extern "C" void kar_a2d_game_audio__near_803792b8(void *unused, s32 arg1) {
    kar_lbaudio_stop_track_handle_chain((void *) arg1);
}

extern "C" u8 kar_a2d_game_audio__near_803792dc(void *unused, s32 arg1, s32 arg2) {
    return kar_lbaudio__near_8005f6a8((void *) arg1, arg2) != 0;
}

extern "C" u8 kar_a2d_game_audio__near_80379310(void *unused, s32 arg1, s32 arg2) {
    return kar_lbaudio__near_8005f5bc(arg1, arg2) != 0;
}

extern "C" s32 kar_a2d_game_audio__near_80379344(void *unused, s32 arg1) {
    s32 idx = arg1 - 0x10000;
    if (idx >= 0 && (u32) idx < 0x3FU) {
        return lbl_804F2978[idx];
    }
    return 0;
}

extern "C" s32 kar_a2d_game_audio__near_80379374(void *unused, s32 arg1) {
    if (arg1 < 0x44) {
        return lbl_80569840[arg1];
    }
    return 0;
}

extern "C" SoundHandle *kar_a2d_game_audio__near_80379398(SoundHandle *arg0) {
    *(void **) arg0 = lbl_804BE0C4;
    arg0->pad4 = 0;
    arg0->pad8 = 0;
    arg0->Init();
    *(void **) arg0 = lbl_804BE104;
    arg0->unkC = 0;
    arg0->unk10 = -1;
    arg0->unk14 = -1;
    arg0->unk30 = lbl_805E4B50;
    arg0->unk2C = lbl_805E4B50;
    arg0->unk28 = lbl_805E4B50;
    arg0->unk20 = 0;
    arg0->unk34 = 0;
    return arg0;
}

extern "C" SoundHandle *kar_a2d_game_audio__near_80379424(SoundHandle *arg0, s32 arg1, s8 arg2) {
    *(void **) arg0 = lbl_804BE0C4;
    arg0->pad4 = 0;
    arg0->pad8 = 0;
    arg0->Init();
    *(void **) arg0 = lbl_804BE104;
    arg0->unkC = 0;
    arg0->unk10 = -1;
    arg0->unk14 = -1;
    arg0->unk30 = lbl_805E4B50;
    arg0->unk2C = lbl_805E4B50;
    arg0->unk28 = lbl_805E4B50;
    arg0->unk20 = 0;
    arg0->unk34 = 0;
    arg0->unkC = 1;
    arg0->unk18 = arg1;
    arg0->unk1C = arg2;
    arg0->unk24 = 4;
    return arg0;
}

extern "C" SoundHandle *kar_a2d_game_audio__near_803794e0(SoundHandle *arg0, s32 arg1, s32 arg2, s8 arg3) {
    *(void **) arg0 = lbl_804BE0C4;
    arg0->pad4 = 0;
    arg0->pad8 = 0;
    arg0->Init();
    *(void **) arg0 = lbl_804BE104;
    arg0->unkC = 0;
    arg0->unk10 = -1;
    arg0->unk14 = -1;
    arg0->unk30 = lbl_805E4B50;
    arg0->unk2C = lbl_805E4B50;
    arg0->unk28 = lbl_805E4B50;
    arg0->unk20 = 0;
    arg0->unk34 = 0;
    arg0->unkC = 1;
    arg0->unk18 = arg1;
    arg0->unk20 = arg2;
    arg0->unk1C = arg3;
    arg0->unk24 = 4;
    return arg0;
}

extern "C" SoundHandle *kar_a2d_game_audio__near_803795ac(SoundHandle *arg0, SoundHandle *arg1) {
    *(void **) arg0 = lbl_804BE0C4;
    arg0->pad4 = 0;
    arg0->pad8 = 0;
    arg0->Init();
    *(void **) arg0 = lbl_804BE104;
    if (lbl_805DDC70 != NULL) {
        arg0->unkC = arg1->unkC;
        arg0->unk10 = arg1->unk10;
        arg0->unk14 = arg1->unk14;
        arg0->unk18 = arg1->unk18;
        arg0->unk1C = arg1->unk1C;
        arg0->unk24 = arg1->unk24;
        arg0->unk28 = arg1->unk28;
        arg0->unk2C = arg1->unk2C;
        arg0->unk30 = arg1->unk30;
        arg0->unk34 = arg1->unk34;
        arg0->unk38 = arg1->unk38;
    }
    return arg0;
}

#pragma push
#pragma dont_inline on
extern "C" s32 kar_a2d_game_audio__near_8037967c(SoundHandle *arg0, s32 arg1, Vec3 *arg2) {
    s32 result = 0;

    switch (arg0->unkC) {
    case 0:
        arg0->unk10 = kar_a2d_game_audio__near_80378e04((EngineAudioState *) lbl_805DDC70, arg1);
        if (arg0->unk10 != -1) {
            if (arg2 != NULL) {
                arg0->unk28 = arg2->x;
                arg0->unk2C = arg2->y;
                arg0->unk30 = arg2->z;
            }
            arg0->unk14 = arg1;
            result = 1;
        }
        break;
    case 1:
        if (arg0->unk24 == 4) {
            arg0->unk10 = kar_a2d_game_audio__near_80378fb4((EngineAudioState *) lbl_805DDC70, arg1, arg0->unk18, arg0->unk20 != 0, arg0->unk1C);
        } else {
            arg0->unk10 = kar_a2d_game_audio__near_8037919c((EngineAudioState *) lbl_805DDC70, arg1, arg0->unk18, arg0->unk24);
        }
        if (arg0->unk10 != -1) {
            arg0->unk14 = arg1;
            result = 1;
        }
        break;
    }
    return result;
}
#pragma pop

#pragma push
#pragma dont_inline on
extern "C" s32 kar_a2d_game_audio__near_80379784(SoundHandle *arg0, s32 arg1, Vec3 *arg2) {
    s32 result;

    kar_a2d_game_audio__near_803799b8(arg0);
    result = 0;
    switch (arg0->unkC) {
    case 0:
        arg0->unk10 = kar_a2d_game_audio__near_80378e04((EngineAudioState *) lbl_805DDC70, arg1);
        if (arg0->unk10 != -1) {
            if (arg2 != NULL) {
                arg0->unk28 = arg2->x;
                arg0->unk2C = arg2->y;
                arg0->unk30 = arg2->z;
            }
            arg0->unk14 = arg1;
            result = 1;
        }
        break;
    case 1:
        if (arg0->unk24 == 4) {
            arg0->unk10 = kar_a2d_game_audio__near_80378fb4((EngineAudioState *) lbl_805DDC70, arg1, arg0->unk18, arg0->unk20 != 0, arg0->unk1C);
        } else {
            arg0->unk10 = kar_a2d_game_audio__near_8037919c((EngineAudioState *) lbl_805DDC70, arg1, arg0->unk18, arg0->unk24);
        }
        if (arg0->unk10 != -1) {
            arg0->unk14 = arg1;
            result = 1;
        }
        break;
    }
    return result;
}
#pragma pop

#pragma push
#pragma dont_inline on
extern "C" s32 kar_a2d_game_audio__near_8037989c(SoundHandle *arg0, s32 arg1) {
    s32 result;
    s32 playing = kar_lbaudio_is_track_handle_playing(arg0->unk10);

    if (((u32) (-playing | playing) >> 31) && arg1 == arg0->unk14) {
        return 1;
    }
    kar_a2d_game_audio__near_803799b8(arg0);
    result = 0;
    switch (arg0->unkC) {
    case 0:
        arg0->unk10 = kar_a2d_game_audio__near_80378e04((EngineAudioState *) lbl_805DDC70, arg1);
        if (arg0->unk10 != -1) {
            arg0->unk14 = arg1;
            result = 1;
        }
        break;
    case 1:
        if (arg0->unk24 == 4) {
            arg0->unk10 = kar_a2d_game_audio__near_80378fb4((EngineAudioState *) lbl_805DDC70, arg1, arg0->unk18, arg0->unk20 != 0, arg0->unk1C);
        } else {
            arg0->unk10 = kar_a2d_game_audio__near_8037919c((EngineAudioState *) lbl_805DDC70, arg1, arg0->unk18, arg0->unk24);
        }
        if (arg0->unk10 != -1) {
            arg0->unk14 = arg1;
            result = 1;
        }
        break;
    }
    return result;
}
#pragma pop

#pragma push
#pragma dont_inline on
extern "C" s32 kar_a2d_game_audio__near_803799b8(SoundHandle *arg0) {
    s32 handle = arg0->unk10;
    if (handle != -1) {
        kar_a2d_game_audio__near_803792b8((void *) lbl_805DDC70, handle);
        arg0->unk10 = -1;
        arg0->unk14 = -1;
        return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma dont_inline on
extern "C" u8 kar_a2d_game_audio__near_80379a0c(SoundHandle *arg0, s32 arg1) {
    u8 result = kar_a2d_game_audio__near_803792dc((EngineAudioState *) lbl_805DDC70, arg0->unk10, arg1);
    if (result != 0 && arg0->unkC == 1 && arg0->unk20 != 0) {
        kar_a2d_game_audio__near_80378f44((EngineAudioState *) lbl_805DDC70, arg0->unk10, arg0->unk18, arg1);
    }
    return result;
}
#pragma pop

#pragma push
#pragma dont_inline on
extern "C" u8 kar_a2d_game_audio__near_80379a94(SoundHandle *arg0, s32 arg1) {
    u8 result = kar_a2d_game_audio__near_80379310((EngineAudioState *) lbl_805DDC70, arg0->unk10, arg1);
    if (result != 0 && arg0->unkC == 1 && arg0->unk20 != 0) {
        kar_a2d_game_audio__near_80378e34((EngineAudioState *) lbl_805DDC70, arg0->unk10, arg0->unk18, arg1);
    }
    return result;
}
#pragma pop

const f32 lbl_805E4B50 = 0.0f;
