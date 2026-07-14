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

struct VtObj {
    void *vt0;
};

class SelfCall4 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

/* slot 0x10 (idx2), 2-arg */
class SelfCall3_2 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2(void *);
};

/* slot 0x38 (idx12), 1-arg */
class SelfCall13 {
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
};

/* slot 0x68 (idx24), 1 u32 arg */
class SelfCall25_u32 {
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24(u32);
};

typedef void (*VF_v_p)(void *);
typedef void (*VF_v_pp)(void *, void *);
typedef void (*VF_v_pu8)(void *, u8);

#define VTBL(p, o) (*(void **) ((char *) (*(void ***) (p)) + (o)))

extern "C" {

void *fn_8038CB28(s32 size);
void fn_8038CB78(void *ptr);
void fn_8039E780(s32);
s32 fn_802AB198(s32);
s32 fn_802AB70C(s32);
void fn_802AB318();
void *__construct_array(void *arr, void (*ctor)(void *), void *ehSpec, s32 count, s32 elemSize);
s32 kar_diag__803ad760(s32 classId, s32 hint, void *nameA, void *nameB, s32 flag);
s32 kar_a2d_game_lib__near_802889ec(s32, void *);
void kar_a2d_game_audio__near_80379398(void *, void *, void *);
void *kar_a2d_gamesession__80287040();
void *kar_a2d_gamesession__80289138();
s32 ClearChecker_GetClearKindFlags(s32, u8);
void OSReport(const char *, ...);

extern s32 lbl_805DDBB4;
extern s32 lbl_805DDC00;
extern void *lbl_805DDB84;

struct NamePair {
    void *a, *b;
};

extern NamePair lbl_805D84B0;
extern NamePair lbl_805D84A8;
extern NamePair lbl_805D85F0;
extern NamePair lbl_805D8604;
extern NamePair lbl_805D8614;
extern char lbl_805D85F8[7];  /* "cursor" */
extern char lbl_805D8600[4];
extern char lbl_805D860C[6];  /* "carve" */

extern char lbl_804BBE28[64];
extern char lbl_804BBFF4[64];
extern char lbl_804BC344[64];
extern char lbl_804BC374[64];
extern char lbl_804BC3BC[64];
extern char lbl_804BC3DC[64];
extern char lbl_804BC430[64];
extern char lbl_804BC454[64];
extern char lbl_804BC4A4[64];
extern char lbl_804BD3EC[64];
extern char lbl_804BD410[64];
extern char lbl_804BFA40[64];
extern char lbl_804C0B30[64];
extern char lbl_804C0BE4[64];
extern char lbl_804C4D3C[64];
extern char lbl_804F5078[64];
extern char lbl_804F58DC[64];
extern char lbl_804F5970[64];
extern char lbl_804F59EC[64];
extern char lbl_804F60F0[64];
extern char lbl_804F6134[64];
extern char lbl_804F66FC[64];
extern char lbl_804F6790[64];
extern char lbl_804F67D8[64];
extern char lbl_804F6F70[64];

extern char lbl_804C4D58[0x2200];
extern char lbl_804C6468[0x1E4];
extern char lbl_804C6674[0x838];
extern char lbl_804C6668[0xa];
extern char lbl_804C665C[0xb];
extern char lbl_804C7180[0x200];
extern char lbl_804C75F4[0x164];
extern char lbl_804C7F40[0x1A]; /* "course record=%d time=%d\n" */

extern char kar_sjis_804c664c[0x10];

}

static char kar_src_a2d_gamehistory_804c54bc[] = "a2d_gamehistory.cpp";
static char lbl_804C54D0[] = "no < GameHistory::FLAG_MAX";

#define ASSERT2(line, cond, str) \
    ((cond) ? ((void) 0) : __assert(kar_src_a2d_gamehistory_804c54bc, line, str))

extern "C" void *kar_a2d_gamehistory__near_802b4cac(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        FP(arg0, 0) = &lbl_804C4D3C;
        if (arg0 != NULL) {
            FP(arg0, 0) = &lbl_804BFA40;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" s32 fn_802B4D08(void) {
    return 0;
}

extern "C" void kar_a2d_gamehistory__near_802b4d10(s32 arg0) {
    lbl_805DDC00 = arg0;
}

extern "C" void *kar_a2d_gamehistory__near_802b4d18(void *arg0) {
    return arg0;
}

extern "C" void *kar_a2d_gamehistory__near_802b4f94(void *arg0, u32 arg1, s32 arg2, s16 arg3) {
    return arg0;
}

struct Obj5414 {
    void *vt0;
    u8 pad4[0x28 - 4];
    void *emb28vt;
    u8 pad2C[0x30 - 0x2C];
    void *emb30vt;
};

extern "C" void *kar_a2d_gamehistory__near_802b5414(Obj5414 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        arg0->vt0 = &lbl_804F6F70;
        if (&arg0->emb30vt != 0) {
            arg0->emb30vt = &lbl_804F5970;
            if (&arg0->emb30vt != 0) {
                arg0->emb30vt = &lbl_804F5078;
                if (&arg0->emb30vt != 0) {
                    arg0->emb30vt = &lbl_804BC430;
                }
            }
        }
        if (arg0 != NULL) {
            arg0->vt0 = &lbl_804BC3DC;
            if (&arg0->emb28vt != 0) {
                arg0->emb28vt = &lbl_804F59EC;
                if (&arg0->emb28vt != 0) {
                    arg0->emb28vt = &lbl_804BC3BC;
                }
            }
            if (arg0 != NULL) {
                arg0->vt0 = &lbl_804BC374;
                if (arg0 != NULL) {
                    arg0->vt0 = &lbl_804BC344;
                    ((SelfCall4 *) arg0)->v3();
                }
            }
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

struct Obj551c {
    void *vt0;
    u8 pad4[8 - 4];
    void *emb8vt;
    u8 padC[0x30 - 0xC];
    void *emb30vt;
    u8 pad34[0x3C - 0x34];
    void *emb3Cvt;
};

extern "C" void *kar_a2d_gamehistory__near_802b551c(Obj551c *arg0, s16 arg1) {
    if (arg0 != NULL) {
        arg0->vt0 = &lbl_804F66FC;
        arg0->emb8vt = (char *) &lbl_804F66FC + 0x10;
        if (&arg0->emb3Cvt != 0) {
            arg0->emb3Cvt = &lbl_804F59EC;
            if (&arg0->emb3Cvt != 0) {
                arg0->emb3Cvt = &lbl_804BC3BC;
            }
        }
        if (&arg0->emb8vt != 0) {
            arg0->emb8vt = &lbl_804BC3DC;
            if ((u32) arg0 + 0x30 != 0) {
                arg0->emb30vt = &lbl_804F59EC;
                if ((u32) arg0 + 0x30 != 0) {
                    arg0->emb30vt = &lbl_804BC3BC;
                }
            }
            if (&arg0->emb8vt != 0) {
                arg0->emb8vt = &lbl_804BC374;
                if (&arg0->emb8vt != 0) {
                    arg0->emb8vt = &lbl_804BC344;
                    ((SelfCall4 *) &arg0->emb8vt)->v3();
                }
            }
        }
        if (arg0 != NULL) {
            arg0->vt0 = &lbl_804BC454;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_802B5630(s32 *arg0) {
    *arg0 = 0;
}

struct Obj563c {
    void *vt0;         // 0x00
    u32 unk4;           // 0x04
    u32 unk8;            // 0x08
    u32 unkC;             // 0x0C
    u32 unk10;             // 0x10
    u32 unk14;              // 0x14
    u16 unk18;                // 0x18
    u16 unk1A;                 // 0x1A
    u16 unk1C;                  // 0x1C
    u16 unk1E;                   // 0x1E
    u8 unk20;                     // 0x20
    u8 pad21[3];
    void *unk24;                   // 0x24
    void *emb28vt;                   // 0x28
    u32 unk2C;                        // 0x2C
    void *emb30vt;                      // 0x30
    u8 unk34, unk35, unk36, unk37;        // 0x34-0x37
    f32 unk38;                              // 0x38
    u32 unk3C;                                // 0x3C
    void *unk40;                                // 0x40
    void *unk44;                                  // 0x44
    u8 unk48;                                       // 0x48
    u8 pad49[3];
    u8 unk4C;                                          // 0x4C
};

extern "C" void *kar_a2d_gamehistory__near_802b563c(Obj563c *arg0, void *arg1, u8 arg2) {
    void *nameStr;
    void *sp8;
    s32 iconIdx;

    arg0->vt0 = &lbl_804BC344;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    arg0->vt0 = &lbl_804BC374;
    arg0->unk18 = 0;
    arg0->unk1A = 0;
    arg0->unk1C = 0;
    arg0->unk1E = 0;
    arg0->unk20 = 0;
    arg0->unk24 = 0;
    arg0->vt0 = &lbl_804BC3DC;
    arg0->emb28vt = &lbl_804BC3BC;
    arg0->emb28vt = &lbl_804F59EC;
    arg0->unk2C = 0;
    arg0->unk24 = &arg0->emb28vt;
    arg0->vt0 = &lbl_804F58DC;
    arg0->emb30vt = &lbl_804BC430;
    arg0->emb30vt = &lbl_804F5078;
    arg0->unk34 = 0xFF;
    arg0->unk35 = 0xFF;
    arg0->unk36 = 0xFF;
    arg0->unk37 = 0xFF;
    arg0->unk38 = 1.0f;
    arg0->emb30vt = &lbl_804F5970;
    arg0->unk3C = 0;
    arg0->unk34 = 0;
    arg0->unk35 = 0;
    arg0->unk36 = 0;
    arg0->unk37 = 0xFF;
    arg0->unk40 = arg1;
    ((SelfCall13 *) arg0)->v12();
    arg0->unk44 = &lbl_804BC454;
    arg0->unk48 = 0;
    nameStr = &lbl_804C6674;
    arg0->vt0 = &lbl_804BC4A4;
    arg0->unk44 = (char *) &lbl_804BC4A4 + 0x48;
    arg0->unk4C = arg2;
    arg0->unk4C = arg2;
    if ((u8) arg0->unk4C != 0) {
        nameStr = &lbl_804C6668;
    }
    sp8 = nameStr;
    if (nameStr != NULL) {
        iconIdx = kar_a2d_game_lib__near_802889ec(kar_diag__803ad760(lbl_805DDBB4, 0, &lbl_805D84B0, &lbl_805D84A8, 0) + 4, &sp8) + 4;
    } else {
        iconIdx = 0;
    }
    arg0->unk2C = iconIdx;
    arg0->unk38 = 0.75f;
    return arg0;
}

extern "C" void *kar_a2d_gamehistory__near_802b585c(void *arg0);

struct Obj57f4 {
    void *vt0;
    u8 pad4[8 - 4];
    void *unk8;
    u8 padC[0x38 - 0xC];
    void *unk38;
    u8 pad3C[0xA0 - 0x3C];
    void *unkA0;
    u8 padA4[0x114 - 0xA4];
    void *unk114;
};

extern "C" void *kar_a2d_gamehistory__near_802b57f4(Obj57f4 *arg0) {
    void *vt;

    fn_8039E780(0);
    vt = &lbl_804BBFF4;
    arg0->vt0 = vt;
    arg0->unk8 = (char *) vt + 0x10;
    arg0->unk38 = (char *) vt + 0x58;
    kar_a2d_gamehistory__near_802b585c((char *) arg0 + 0x118);
    arg0->unk114 = (char *) arg0 + 0x118;
    arg0->unkA0 = arg0->unk114;
    return arg0;
}

struct Obj585c {
    void *vt0;      // 0x00
    u32 unk4;         // 0x04
    u32 unk8;          // 0x08
    u32 unkC;           // 0x0C
    u32 unk10;            // 0x10
    u32 unk14;             // 0x14
    u16 unk18;               // 0x18
    u16 unk1A;                 // 0x1A
    u16 unk1C;                   // 0x1C
    u16 unk1E;                     // 0x1E
    u8 unk20;                        // 0x20
    u8 pad21[3];
    void *unk24;                        // 0x24
    void *e28_vt;                          // 0x28
    u32 e28_unk4;                           // 0x2C
    void *e28_subvt;                          // 0x30
    u32 e28_unkC;                               // 0x34
    void *e28_sub2vt;                             // 0x38
    u32 e28_unk14;                                  // 0x3C
    u8 e28_unk18;                                     // 0x40
    u8 e28_unk19;                                       // 0x41
    u8 pad42[2];
    f32 e28_unk1C;                                       // 0x44
    f32 e28_unk20;                                         // 0x48
    f32 e28_unk24;                                           // 0x4C
    f32 e28_unk28;                                             // 0x50
    void *e54_vt;                                                // 0x54
    u32 e54_unk4;                                                  // 0x58
    u32 e54_unk8;                                                    // 0x5C
    u32 e54_unkC;                                                      // 0x60
    u32 e54_unk10;                                                       // 0x64
    u32 e54_unk14;                                                         // 0x68
    u16 e54_unk18;                                                           // 0x6C
    u16 e54_unk1A;                                                             // 0x6E
    u16 e54_unk1C;                                                              // 0x70
    u16 e54_unk1E;                                                               // 0x72
    u8 e54_unk20;                                                                 // 0x74
    u8 pad75[3];
    u32 e54_unk24;                                                                 // 0x78
    void *e54_subvt;                                                                // 0x7C
    u32 e54_unk2C;                                                                    // 0x80
    void *e54_sub2vt;                                                                   // 0x84
    u32 e54_unk34;                                                                        // 0x88
    u32 e54_unk38;                                                                          // 0x8C
    f32 e54_unk3C;                                                                            // 0x90
};

extern "C" void *kar_a2d_gamehistory__near_802b585c(void *arg0v) {
    Obj585c *arg0 = (Obj585c *) arg0v;
    const char *name;
    void *sp;
    s32 var8;

    arg0->vt0 = &lbl_804BC344;
    name = "bar";
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    arg0->vt0 = &lbl_804BC374;
    arg0->unk18 = 0;
    arg0->unk1A = 0;
    arg0->unk1C = 0;
    arg0->unk1E = 0;
    arg0->unk20 = 0;
    arg0->unk24 = 0;
    arg0->vt0 = &lbl_804F6134;
    arg0->e28_vt = &lbl_804BC3BC;
    arg0->e28_vt = &lbl_804F59EC;
    arg0->e28_unk4 = 0;
    arg0->e28_vt = &lbl_804F60F0;
    arg0->e28_subvt = &lbl_804BC3BC;
    arg0->e28_subvt = &lbl_804F59EC;
    sp = (void *) name;
    if (name != NULL) {
        var8 = kar_a2d_game_lib__near_802889ec(kar_diag__803ad760(lbl_805DDBB4, 0, &lbl_805D84B0, &lbl_805D84A8, 0) + 4, &sp) + 4;
    } else {
        var8 = 0;
    }
    arg0->e28_unkC = var8;
    arg0->e28_sub2vt = &lbl_804BC3BC;
    name = "carve_s";
    arg0->e28_sub2vt = &lbl_804F59EC;
    sp = (void *) name;
    if (name != NULL) {
        var8 = kar_a2d_game_lib__near_802889ec(kar_diag__803ad760(lbl_805DDBB4, 0, &lbl_805D84B0, &lbl_805D84A8, 0) + 4, &sp) + 4;
    } else {
        var8 = 0;
    }
    arg0->e28_unk14 = var8;
    name = "carve";
    arg0->e28_unk18 = 0;
    arg0->e28_unk19 = 0;
    arg0->e28_unk1C = 0.0f;
    arg0->e28_unk20 = 1.0f;
    arg0->e28_unk24 = 0.0f;
    arg0->e28_unk28 = 1.0f;
    sp = (void *) name;
    if (name != NULL) {
        var8 = kar_a2d_game_lib__near_802889ec(kar_diag__803ad760(lbl_805DDBB4, 0, &lbl_805D84B0, &lbl_805D84A8, 0) + 4, &sp) + 4;
    } else {
        var8 = 0;
    }
    arg0->e28_unk4 = var8;
    arg0->unk24 = &arg0->e28_vt;
    arg0->vt0 = &lbl_804F67D8;
    arg0->e54_vt = &lbl_804BC344;
    name = "arrow_r";
    arg0->e54_unk4 = 0;
    arg0->e54_unk8 = 0;
    arg0->e54_vt = &lbl_804BC374;
    arg0->e54_unkC = 0;
    arg0->e54_unk10 = 0;
    arg0->e54_unk14 = 0;
    arg0->e54_unk18 = 0;
    arg0->e54_unk1A = 0;
    arg0->e54_unk1C = 0;
    arg0->e54_unk1E = 0;
    arg0->e54_unk20 = 0;
    arg0->e54_unk24 = 0;
    arg0->e54_vt = &lbl_804F6790;
    arg0->e54_subvt = &lbl_804BC3BC;
    arg0->e54_subvt = &lbl_804F59EC;
    sp = (void *) name;
    if (name != NULL) {
        var8 = kar_a2d_game_lib__near_802889ec(kar_diag__803ad760(lbl_805DDBB4, 0, &lbl_805D84B0, &lbl_805D84A8, 0) + 4, &sp) + 4;
    } else {
        var8 = 0;
    }
    arg0->e54_unk2C = var8;
    arg0->e54_sub2vt = &lbl_804BC3BC;
    name = "cursor";
    arg0->e54_sub2vt = &lbl_804F59EC;
    sp = (void *) name;
    if (name != NULL) {
        var8 = kar_a2d_game_lib__near_802889ec(kar_diag__803ad760(lbl_805DDBB4, 0, &lbl_805D84B0, &lbl_805D84A8, 0) + 4, &sp) + 4;
    } else {
        var8 = 0;
    }
    arg0->e54_unk34 = var8;
    arg0->e54_unk38 = 0;
    arg0->e54_unk3C = 0.0f;
    ((SelfCall3_2 *) &arg0->e54_vt)->v2(arg0);
    arg0->unk1C = 0x64;
    arg0->unk20 = 1;
    arg0->unk1E = 0xC8;
    arg0->unk20 = 1;
    return arg0v;
}

struct Obj5b80 {
    void *vt0;
    u8 pad4[0x28 - 4];
    void *emb28vt;
    u8 pad2C[0x30 - 0x2C];
    void *emb30vt;
};

extern "C" void *kar_a2d_gamehistory__near_802b5b80(Obj5b80 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        arg0->vt0 = &lbl_804F6790;
        if (&arg0->emb30vt != 0) {
            arg0->emb30vt = &lbl_804F59EC;
            if (&arg0->emb30vt != 0) {
                arg0->emb30vt = &lbl_804BC3BC;
            }
        }
        if (&arg0->emb28vt != 0) {
            arg0->emb28vt = &lbl_804F59EC;
            if (&arg0->emb28vt != 0) {
                arg0->emb28vt = &lbl_804BC3BC;
            }
        }
        if (arg0 != NULL) {
            arg0->vt0 = &lbl_804BC374;
            if (arg0 != NULL) {
                arg0->vt0 = &lbl_804BC344;
                ((SelfCall4 *) arg0)->v3();
            }
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

struct Obj5c60 {
    void *vt0;
    u8 pad4[0x28 - 4];
    void *emb28vt;
    u8 pad2C[0x30 - 0x2C];
    void *emb30vt;
    u8 pad34[0x38 - 0x34];
    void *emb38vt;
};

extern "C" void *kar_a2d_gamehistory__near_802b5c60(Obj5c60 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        arg0->vt0 = &lbl_804F6134;
        if (&arg0->emb28vt != 0) {
            arg0->emb28vt = &lbl_804F60F0;
            if ((u32) arg0 + 0x38 != 0) {
                arg0->emb38vt = &lbl_804F59EC;
                if ((u32) arg0 + 0x38 != 0) {
                    arg0->emb38vt = &lbl_804BC3BC;
                }
            }
        }
        if ((u32) arg0 + 0x30 != 0) {
            arg0->emb30vt = &lbl_804F59EC;
            if ((u32) arg0 + 0x30 != 0) {
                arg0->emb30vt = &lbl_804BC3BC;
            }
        }
        if (&arg0->emb28vt != 0) {
            arg0->emb28vt = &lbl_804F59EC;
            if (&arg0->emb28vt != 0) {
                arg0->emb28vt = &lbl_804BC3BC;
            }
        }
        if (arg0 != NULL) {
            arg0->vt0 = &lbl_804BC374;
            if (arg0 != NULL) {
                arg0->vt0 = &lbl_804BC344;
                ((SelfCall4 *) arg0)->v3();
            }
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

struct Obj5d7c {
    void *vt0;
    u8 pad4[8 - 4];
    void *emb8vt;
    u8 padC[0x10 - 0xC];
    void *emb10vt;
};

extern "C" void *kar_a2d_gamehistory__near_802b5d7c(Obj5d7c *arg0, s16 arg1) {
    if (arg0 != NULL) {
        arg0->vt0 = &lbl_804F60F0;
        if (&arg0->emb10vt != 0) {
            arg0->emb10vt = &lbl_804F59EC;
            if (&arg0->emb10vt != 0) {
                arg0->emb10vt = &lbl_804BC3BC;
            }
        }
        if (&arg0->emb8vt != 0) {
            arg0->emb8vt = &lbl_804F59EC;
            if (&arg0->emb8vt != 0) {
                arg0->emb8vt = &lbl_804BC3BC;
            }
        }
        if (arg0 != NULL) {
            arg0->vt0 = &lbl_804F59EC;
            if (arg0 != NULL) {
                arg0->vt0 = &lbl_804BC3BC;
            }
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

class GameHistory {
public:
    enum { FLAG_MAX = 0x78 };
};

struct FlagWidget {
    void *vt;
    u8 pad[0x64];
};

typedef void (*VF_v_pu32)(void *, u32);

extern "C" void kar_a2d_gamehistory__802b5e3c(void *arg0) {
    char *cur;
    u32 no;
    s32 flags;
    FlagWidget *rec;
    u8 masked;
    u32 b;

    no = 0;
    cur = (char *) arg0;
    do {
        ASSERT2(0x18, no < GameHistory::FLAG_MAX, lbl_804C54D0);
        flags = ClearChecker_GetClearKindFlags(1, (u8) no);
        rec = *(FlagWidget **) (cur + 0x1FC);
        masked = (u8) (flags & 5);
        b = (u32) (-(s32) masked | masked) >> 31;
        ((SelfCall25_u32 *) rec)->v24(b);
        no += 1;
        cur += 4;
    } while (no < GameHistory::FLAG_MAX);
    {
        VtObj *self = (VtObj *) ((char *) arg0 + 8);
        ((SelfCall13 *) self)->v12();
    }
}

extern "C" void *kar_a2d_gamehistory__near_802b5ef8(void *arg0) {
    return arg0;
}

extern "C" void *kar_a2d_gamehistory__near_802b6a90(void *arg0, void *arg1, s16 arg2, s16 arg3) {
    return arg0;
}

extern "C" void Checklist_LoadTopRideStats(void *arg0) {
}

struct Obj74b4 {
    void *vt0;
    u8 pad4[0x28 - 4];
    void *emb28vt;
};

extern "C" void *kar_a2d_gamehistory__near_802b74b4(Obj74b4 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        arg0->vt0 = &lbl_804C75F4;
        if (arg0 != NULL) {
            arg0->vt0 = &lbl_804BC3DC;
            if (&arg0->emb28vt != 0) {
                arg0->emb28vt = &lbl_804F59EC;
                if (&arg0->emb28vt != 0) {
                    arg0->emb28vt = &lbl_804BC3BC;
                }
            }
            if (arg0 != NULL) {
                arg0->vt0 = &lbl_804BC374;
                if (arg0 != NULL) {
                    arg0->vt0 = &lbl_804BC344;
                    ((SelfCall4 *) arg0)->v3();
                }
            }
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_802B757C(void *arg0) {
    kar_a2d_gamehistory__802b5e3c((char *) arg0 - 8);
}

extern "C" void fn_802B7584(s32 arg0) {
    fn_802AB198(arg0 - 8);
}

extern "C" void fn_802B758C(s32 arg0) {
    fn_802AB198(arg0 - 0x38);
}

extern "C" void fn_802B7594(void *arg0) {
    Checklist_LoadTopRideStats((char *) arg0 - 8);
}

extern "C" void fn_802B759C(s32 arg0) {
    fn_802AB70C(arg0 - 8);
}

extern "C" void fn_802B75A4(s32 arg0) {
    fn_802AB70C(arg0 - 0x38);
}

extern "C" void *kar_a2d_gamehistory__near_802b75ac(void *arg0, s8 arg1, s8 arg2, s8 arg3, s8 arg4) {
    return arg0;
}
