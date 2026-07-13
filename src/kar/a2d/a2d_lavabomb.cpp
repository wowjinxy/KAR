#include <dolphin/types.h>

extern "C" {
#include <global.h>
}

extern "C" {

void HSD_JObjReqAnimAll(void *, f32);

s32 HSD_Randf(void);
s32 HSD_Randi(s32);

void *fn_8038CB28(s32);
void fn_8038CB78(void *);
void *fn_8038D0A8(s32, void *, u32, u8, s32);
void fn_803AD738(void *);
void *kar_diag__803ad760(s32, s32, void *, void *, s32);
void kar_diag__802affd8(void *, void *, s32, void **);
void kar_diag__802dd040(void *, void *, s32, f32 *);

void *kar_a2d_effecthandle__8037b028(void *, s32, s32, void *, void *, void *);
void kar_a2d_effecthandle__near_8037b33c(void *, u8);
u8 kar_a2d_effecthandle__near_8037b61c(void *);
void kar_a2d_game_audio__near_803792b8(s32);
void kar_a2d_game_effect__near_8037afd0(void *, u8);
void kar_a2d_game_lib__8028ad74(s32, void *);
void kar_a2d_game_lib__near_80289590(void *, u16, f32);
void kar_a2d_game_lib__near_80289730(void *, u16, f32);
void kar_a2d_game_lib__near_80289768(void *, u16, f32);
u8 kar_a2d_game_lib__near_802897e0(void *);
u8 kar_a2d_game_lib__near_80289874(void *);
u16 kar_a2d_game_lib__near_8028ac98(u16, u16, u16);
u8 kar_a2d_grindrail__80322118(void *, void *);
void kar_a2d_refract__near_803845f4(void *);
void kar_a2d_refract__near_80384600(void *, s16);
void kar_a2d_refract__near_803848e0(void *, s32, f32 *, f32);
void kar_a2d_refract__near_80384a80(void *);
void kar_a2d_refract__near_80384a98(void *);

s32 strcmp(const char *, const char *);
char *strcpy(char *, const char *);
s32 strlen(const char *);

extern const f32 lbl_805E3F78;
extern const f32 lbl_805E3F7C;
extern const f32 lbl_805E3F80;
extern const f32 lbl_805E3FD8;
extern const f32 lbl_805E3FDC;
extern const f32 lbl_805E3FE0;
extern const f32 lbl_805E3FF0;
extern const f32 lbl_805E4008;
extern const f32 lbl_805E4014;
extern const f32 lbl_805E4018;

extern s32 lbl_805DD9AC;
extern void *lbl_805DD9B0;
extern void *lbl_805DD9B4;

}

struct NamePair {
    void *a, *b;
};

extern "C" NamePair lbl_805DA57C;
extern "C" NamePair lbl_805DA574;

struct LB_ListNode {
    void *vtable;
    LB_ListNode *prev; //0x04
    LB_ListNode *next; //0x08
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

static inline s32 LB_ListNode_IsLinked(LB_ListNode *arg0) {
    s32 var_r4 = 0;
    if (arg0->prev != 0 || arg0->next != 0 || lbl_805DD9B0 == arg0) {
        var_r4 = 1;
    }
    return var_r4;
}

static inline void LB_ListNode_PushFront(LB_ListNode *arg0) {
    if (lbl_805DD9B0 != NULL) {
        arg0->next = (LB_ListNode *) lbl_805DD9B0;
        ((LB_ListNode *) lbl_805DD9B0)->prev = arg0;
        lbl_805DD9B0 = arg0;
    } else {
        lbl_805DD9B4 = arg0;
        lbl_805DD9B0 = arg0;
    }
    lbl_805DD9AC += 1;
}

static inline void LB_ListNode_PushBack(LB_ListNode *arg0) {
    if (lbl_805DD9B0 != NULL) {
        arg0->prev = (LB_ListNode *) lbl_805DD9B4;
        ((LB_ListNode *) lbl_805DD9B4)->next = arg0;
        lbl_805DD9B4 = arg0;
    } else {
        lbl_805DD9B4 = arg0;
        lbl_805DD9B0 = arg0;
    }
    lbl_805DD9AC += 1;
}

static inline void LB_ListNode_Remove(LB_ListNode *arg0) {
    LB_ListNode *prev = arg0->prev;
    if (prev == NULL) {
        LB_ListNode *next = arg0->next;
        lbl_805DD9B0 = next;
        if (next != NULL) {
            next->prev = NULL;
        }
    } else {
        prev->next = arg0->next;
    }
    LB_ListNode *next = arg0->next;
    if (next == NULL) {
        LB_ListNode *prev2 = arg0->prev;
        lbl_805DD9B4 = prev2;
        if (prev2 != NULL) {
            prev2->next = NULL;
        }
    } else {
        next->prev = arg0->prev;
    }
    arg0->next = NULL;
    arg0->prev = NULL;
    lbl_805DD9AC -= 1;
}

extern "C" void fn_8032115C(void) {
}

extern "C" void fn_80321CBC(void) {
}

extern "C" s32 fn_80321CC0(LB_ListNode *arg0) {
    return LB_ListNode_IsLinked(arg0);
}

extern "C" void fn_80321CF4(LB_ListNode *arg0) {
    LB_ListNode_PushFront(arg0);
}

extern "C" void fn_80321D2C(LB_ListNode *arg0) {
    LB_ListNode_PushBack(arg0);
}

extern "C" void kar_a2d_lavabomb__near_80321d68(LB_ListNode *arg0) {
    LB_ListNode_Remove(arg0);
}

extern "C" void kar_a2d_lavabomb__near_80321de4(LB_ListNode *arg0) {
    s32 id = (s32) arg0->prev;
    kar_diag__803ad760(id, 0, &lbl_805DA57C, &lbl_805DA574, 0);
}

extern "C" void kar_a2d_lavabomb__near_80321e18(LB_ListNode *arg0) {
    s32 id = (s32) arg0->next;
    kar_diag__803ad760(id, 0, &lbl_805DA57C, &lbl_805DA574, 0);
}

extern "C" void kar_a2d_lavabomb__near_80320e50(LBNodeBase *arg0) {
    arg0->PushBack();
}

extern "C" char lbl_804E1620[0xC];
extern "C" char lbl_804BDF70[0x28];
extern "C" char lbl_804BDF2C[0x28];
extern "C" char lbl_804E0EB8[0x10];
extern "C" char lbl_804E22E0[0x60];
extern "C" char lbl_804E2104[0xC];
extern "C" char lbl_804E2110[0x1C];
extern "C" void *lbl_805DDB2C;
extern "C" char lbl_804E21EC[0x74];
extern "C" char lbl_804E2260[0x50];
extern "C" char lbl_804BDB74[0x28];

extern "C" char *kar_a2d_lavabomb__near_80320de8(char *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void **) arg0 = lbl_804E2260;
        ((LBNodeBase *) arg0)->Remove();
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" char *kar_a2d_lavabomb__near_80320d4c(char *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void **) arg0 = lbl_804E21EC;
        *(void **) (arg0 + 0x14) = lbl_804E21EC + 0x28;
        if ((arg0 + 0x14) != NULL) {
            *(void **) (arg0 + 0x14) = lbl_804E2260;
            ((LBNodeBase *) (arg0 + 0x14))->Remove();
        }
        if (arg0 != NULL) {
            *(void **) arg0 = lbl_804BDB74;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma dont_inline on
extern "C" void fn_80321E4C(char *arg0, s16 arg1) {
    kar_a2d_lavabomb__near_80320d4c(arg0 - 0x14, arg1);
}
#pragma pop

struct LB_Bomb {
    void *vtable;    //0x00
    s32 unk4;        //0x04
    s32 unk8;        //0x08
    s32 unkC;        //0x0C
    void *unk10;     //0x10 jobj
    void *unk14;     //0x14 jobj / vec3f*
    void *unk18;     //0x18 jobj
    s32 unk1C;       //0x1C
    u16 *unk20;      //0x20 counter
    void *unk24;     //0x24
    s32 unk28;       //0x28 state
    u8 unk2C;        //0x2C flag
    u8 pad2D;
    u16 unk2E;       //0x2E timer
    char pad30[0x50 - 0x30];
    u8 unk50;        //0x50
    char pad51[0x54 - 0x51];
    char pad54[0xEC - 0x54];
    u16 unkEC;       //0xEC frame
    u16 padEE;
    char padF0[4];
    u16 unkF4;       //0xF4
};

extern "C" void kar_a2d_lavabomb__near_80320eb8(LB_Bomb *arg0);

extern "C" void kar_a2d_lavabomb__near_80320e7c(LB_Bomb *arg0) {
    arg0->unk28 = 2;
    kar_a2d_lavabomb__near_80320eb8(arg0);
    arg0->unk2C = 0;
}

extern "C" void kar_a2d_lavabomb__near_80320eb8(LB_Bomb *arg0) {
    if (arg0->unk28 == 2) {
        arg0->unk28 = 0;
        arg0->unk2E = 0;
        arg0->unkEC = 0;
        *arg0->unk20 += 1;
    }
}

struct Vec3f {
    f32 x, y, z;
};

class LBEffectorIF {
public:
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void SetPos(Vec3f *pos);
    virtual void SetRate(f32 val);
};

extern "C" void kar_a2d_lavabomb__near_80320ee8(LB_Bomb *arg0) {
    switch (arg0->unk28) {
    case 0:
        break;
    case 1:
        if (kar_a2d_game_lib__near_802897e0(arg0->unk10) != 0 || kar_a2d_game_lib__near_80289874(arg0->unk10) != 0) {
            if (arg0->unk28 == 1) {
                arg0->unk28 = 2;
                arg0->unk2E = kar_a2d_game_lib__near_8028ac98(0x28, 0, 2);
                HSD_JObjReqAnimAll(arg0->unk10, lbl_805E3F78);
                kar_a2d_game_lib__near_80289768(arg0->unk10, 0xFFFF, lbl_805E3F78);
            }
            arg0->unk2C = 0;
        } else {
            u16 t = arg0->unk2E;
            if (t != 0) {
                arg0->unk2E = t - 1;
            } else {
                arg0->unk2C = 0;
            }
        }
        if (arg0->unkEC == 2) {
            kar_a2d_game_effect__near_8037afd0((char *) arg0 + 0x54, 0);
            kar_a2d_effecthandle__8037b028((char *) arg0 + 0x54, 0x28B3, 1, arg0->unk14, 0, 0);
        }
        if (arg0->unkEC == 0x78) {
            kar_a2d_game_effect__near_8037afd0((char *) arg0 + 0xA0, 0);
            kar_a2d_effecthandle__8037b028((char *) arg0 + 0xA0, 0x28B6, 1, arg0->unk18, 0, 0);
        }
        if (arg0->unkEC >= 0x78 && kar_a2d_effecthandle__near_8037b61c((char *) arg0 + 0x54) != 0) {
            kar_a2d_effecthandle__near_8037b33c((char *) arg0 + 0x54, 1);
        }
        arg0->unkEC += 1;
        if (arg0->unkF4 != 0) {
            arg0->unkF4 -= 1;
            u16 f4 = arg0->unkF4;
            if (f4 == 0 || f4 > 0x21C) {
                kar_a2d_refract__near_80384a80((char *) arg0 + 0xF0);
            } else {
                kar_a2d_refract__near_80384a98((char *) arg0 + 0xF0);
            }
        }
        break;
    case 2:
        if (arg0->unk2E != 0) {
            arg0->unk2E -= 1;
        } else {
            arg0->unk28 = 0;
            arg0->unk2E = 0;
            arg0->unkEC = 0;
            *arg0->unk20 += 1;
        }
        break;
    }
    if (arg0->unk2C != 0) {
        Vec3f *src = (Vec3f *) arg0->unk14;
        Vec3f pos = *src;
        arg0->unk50 = 1;
        ((LBEffectorIF *) ((char *) arg0 + 0x30))->SetPos(&pos);
        ((LBEffectorIF *) ((char *) arg0 + 0x30))->SetRate(lbl_805E3F7C);
        return;
    }
    arg0->unk50 = 0;
}

struct MagmaPlate {
    void *unk0;
    void *unk4;
    s32 unk8;
    f32 unkC;
    f32 unk10;
    char pad14[0x4C - 0x14];
    f32 unk4C;
};

extern "C" void kar_a2d_lavabomb__near_80321e54(void *unused, MagmaPlate *arg1) {
    kar_a2d_game_lib__near_80289590(arg1->unk4, 0xFFFF, lbl_805E4008);
    kar_a2d_game_lib__near_80289768(arg1->unk4, 0xFFFF, lbl_805E4008);
    kar_a2d_game_lib__near_80289730(arg1->unk4, 0xFFFF, lbl_805E4008);
    arg1->unk0 = 0;
    arg1->unk8 = 0;
    arg1->unk10 = lbl_805E4008;
    arg1->unkC = lbl_805E4008;
    arg1->unk4C = lbl_805E4018;
}

extern "C" void kar_a2d_lavabomb__near_803212f4(char *arg0, u16 arg1, s32 arg2) {
    u16 maxCount = *(u16 *) (arg0 + 0x12 + arg2 * 2);
    u16 tryCount = arg1;
    if ((s32) tryCount > (s32) maxCount) {
        tryCount = maxCount;
    }
    kar_a2d_game_lib__8028ad74(tryCount, arg0 + 0x1A);
    u32 idx = 0;
    s32 byteOff = 0;
    while (idx < (u32) *(s32 *) (arg0 + 8)) {
        LB_Bomb *bomb = *(LB_Bomb **) (arg0 + 0xC + byteOff);
        if (arg2 == bomb->unk4) {
            char *p = arg0;
            s32 ctr = tryCount;
            if (ctr > 0) {
                do {
                    if ((s32) *(u16 *) (p + 0x1A) == bomb->unk8) {
                        s32 state = bomb->unk28;
                        if (state == 0 || state == 2) {
                            if (state == 0) {
                                *bomb->unk20 -= 1;
                            }
                            bomb->unk28 = 1;
                            HSD_JObjReqAnimAll(bomb->unk10, lbl_805E3F78);
                            kar_a2d_game_lib__near_80289768(bomb->unk10, 0xFFFF, lbl_805E3F80);
                            bomb->unk2E = kar_a2d_game_lib__near_8028ac98(0x78, 0, 2);
                            bomb->unkEC = 0;
                            bomb->unkF4 = 0x294;
                        }
                    } else {
                        p += 2;
                        ctr -= 1;
                    }
                } while (ctr != 0);
            }
        }
        byteOff += 4;
        idx += 1;
    }
}

extern "C" void kar_a2d_lavabomb__near_80321430(char *arg0, s32 arg1, f32 farg0) {
    u32 idx = 0;
    s32 byteOff = 0;
    while (idx < (u32) *(s32 *) (arg0 + 8)) {
        LB_Bomb *bomb = *(LB_Bomb **) (arg0 + 0xC + byteOff);
        if (arg1 == bomb->unk4) {
            u16 maxCount = *(u16 *) (arg0 + 0x12 + arg1 * 2);
            f32 invMax = 1.0f / (f32) maxCount;
            u16 *lo = bomb->unk20;
            u16 *hi = (u16 *) bomb->unk24;
            if (((invMax > farg0) && (*lo == *hi) && ((lbl_805E3FF0 * HSD_Randf()) < (farg0 / invMax))) ||
                ((invMax <= farg0) && (HSD_Randi((s32) *lo) == 0) && ((invMax * (f32) (*hi - *lo)) < farg0))) {
                s32 state = bomb->unk28;
                if (state == 0 || state == 2) {
                    if (state == 0) {
                        *lo -= 1;
                    }
                    bomb->unk28 = 1;
                    HSD_JObjReqAnimAll(bomb->unk10, lbl_805E3F78);
                    kar_a2d_game_lib__near_80289768(bomb->unk10, 0xFFFF, lbl_805E3F80);
                    bomb->unk2E = kar_a2d_game_lib__near_8028ac98(0x78, 0, 2);
                    bomb->unkEC = 0;
                    bomb->unkF4 = 0x294;
                }
            }
        }
        byteOff += 4;
        idx += 1;
    }
}

extern "C" const s32 lbl_805DDB7C;
extern "C" NamePair lbl_805DA6D0;
extern "C" NamePair lbl_805DA6C8;

extern "C" s32 kar_a2d_lavabomb__near_80321ed8(MagmaPlate *arg0) {
    s32 anyActive = 0;
    MagmaPlate *plate = arg0;
    s32 i;
    for (i = 0; i < 4; i++, plate = (MagmaPlate *) ((char *) plate + 0x54)) {
        s32 hitIdx = -1;
        char *a = *(char **) ((char *) plate->unk4 + 0x7C);
        char *b = *(char **) (a + 0x18);
        char *railData = *(char **) (b + 0x18);
        if (plate->unk0 != NULL) {
            anyActive = 1;
            if (kar_a2d_grindrail__80322118(arg0, plate) == 0) {
                void *h = plate->unk0;
                void **vt = *(void ***) h;
                ((void (*)(void *)) vt[0x32])(h);
                kar_a2d_game_lib__near_80289590(plate->unk4, 0xFFFF, lbl_805E4008);
                kar_a2d_game_lib__near_80289768(plate->unk4, 0xFFFF, lbl_805E4008);
                kar_a2d_game_lib__near_80289730(plate->unk4, 0xFFFF, lbl_805E4008);
                plate->unk0 = NULL;
                plate->unk8 = 0;
                plate->unk10 = lbl_805E4008;
                plate->unkC = lbl_805E4008;
                plate->unk4C = lbl_805E4018;
            }
            f32 t = plate->unk4C;
            s32 n = 0;
            if (t > 0.0f && t < lbl_805E4014) {
                f32 *dist = (f32 *) (railData + 0x10);
                while (dist[n + 1] < t) {
                    n++;
                }
                hitIdx = n;
            }
        }
        if (hitIdx != -1) {
            s32 step = (*(u8 *) railData != 1) ? 1 : 3;
            s16 count = *(s16 *) (railData + 2);
            s32 waveIdx = 0;
            Vec3f *waypoints = *(Vec3f **) (railData + 8);
            for (s32 j = 0; j < count; j++, waveIdx += step) {
                Vec3f *wp = waypoints + waveIdx;
                Vec3f pos = *wp;
                char *obj = (char *) kar_diag__803ad760(lbl_805DDB7C, 0, &lbl_805DA6D0, &lbl_805DA6C8, 0);
                f32 sp[10];
                sp[0] = pos.x;
                sp[1] = pos.y;
                sp[2] = pos.z;
                sp[3] = 0.0f;
                sp[4] = 0.0f;
                sp[5] = 0.0f;
                sp[6] = 0.0f;
                sp[7] = 0.0f;
                sp[8] = 0.0f;
                *(s32 *) &sp[9] = 2;
                s32 cnt44 = *(s32 *) (obj + 0x44);
                void *arr48 = *(void **) (obj + 0x48);
                kar_diag__802dd040(obj + 0x40, (char *) arr48 + cnt44 * 0x28, 1, sp);
            }
        }
    }
    return anyActive;
}

class LBElem;
typedef void (LBElem::*LBElemFn)();
typedef void (LBElem::*LBElemFnF)(f32);

extern "C" LBElemFn const lbl_804E1588;
extern "C" LBElemFn const lbl_804E1594;
extern "C" LBElemFn const lbl_804E15A0;
extern "C" LBElemFnF const lbl_804E15B8;
extern "C" LBElemFn const lbl_804E2018;
extern "C" LBElemFn const lbl_804E2024;
extern "C" LBElemFn const lbl_804E2030;

struct LBSmallArrA {
    char pad0[4];
    s32 count;
    LBElem **items;
    u16 padC;
    u16 unkE;
};

struct LBSmallArrB {
    char pad0[8];
    s32 count;
    LBElem **items;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
};

extern "C" void kar_a2d_lavabomb__near_80320208(LBSmallArrA *arg0) {
    LBElemFn pmf = lbl_804E1588;
    LBElem **p = arg0->items;
    LBElem **end = p + arg0->count;
    while (p != end) {
        ((*p)->*pmf)();
        p++;
    }
}

extern "C" void kar_a2d_lavabomb__near_8032028c(LBSmallArrA *arg0) {
    LBElemFn pmf = lbl_804E1594;
    LBElem **p = arg0->items;
    LBElem **end = p + arg0->count;
    while (p != end) {
        ((*p)->*pmf)();
        p++;
    }
}

extern "C" void kar_a2d_lavabomb__near_80320310(LBSmallArrA *arg0) {
    arg0->unkE = 0;
    LBElemFn pmf = lbl_804E15A0;
    LBElem **p = arg0->items;
    LBElem **end = p + arg0->count;
    while (p != end) {
        ((*p)->*pmf)();
        p++;
    }
}

extern "C" void kar_a2d_lavabomb__near_8032039c(LBSmallArrA *arg0, f32 farg0) {
    LBElemFnF pmf = lbl_804E15B8;
    LBElem **p = arg0->items;
    LBElem **end = p + arg0->count;
    while (p != end) {
        ((*p)->*pmf)(farg0);
        p++;
    }
}

extern "C" void kar_a2d_lavabomb__near_80321160(LBSmallArrB *arg0) {
    LBElemFn pmf = lbl_804E2018;
    LBElem **p = arg0->items;
    LBElem **end = p + arg0->count;
    while (p != end) {
        ((*p)->*pmf)();
        p++;
    }
}

extern "C" void kar_a2d_lavabomb__near_803211e4(LBSmallArrB *arg0) {
    LBElemFn pmf = lbl_804E2024;
    LBElem **p = arg0->items;
    LBElem **end = p + arg0->count;
    while (p != end) {
        ((*p)->*pmf)();
        p++;
    }
}

extern "C" void kar_a2d_lavabomb__near_80321268(LBSmallArrB *arg0) {
    arg0->unk18 = 0;
    LBElemFn pmf = lbl_804E2030;
    LBElem **p = arg0->items;
    LBElem **end = p + arg0->count;
    while (p != end) {
        ((*p)->*pmf)();
        p++;
    }
}

extern "C" void *kar_a2d_bg3000__near_8033ab00(void);
extern "C" f32 fn_80296264(f32);
extern "C" f32 fn_8029626C(f32);
extern "C" f32 fn_802D4C30(f32);
extern "C" char lbl_805DA548[4];

struct Bg3000Singleton {
    char pad0[0x6C];
    f32 unk6C;
    f32 unk70;
    f32 unk74;
};

struct LB_BombNamed {
    char pad0[0xC];
    char *unkC;
};

extern "C" void kar_a2d_lavabomb__near_803218dc(LBSmallArrB *arg0, char *arg1) {
    u32 i;
    s32 byteOff = 0;
    for (i = 0; i < (u32) arg0->count; i++, byteOff += 4) {
        void *handle = *(void **) (arg1 + 0x2C);
        if (handle != NULL) {
            char *name = *(char **) (*(char **) (*(char **) (arg1 + 4) + 4) + 0xC - 4);
            if (name == NULL) {
                name = lbl_805DA548;
            }
            LB_BombNamed *bomb = *(LB_BombNamed **) (*(char **) ((char *) arg0 + 0xC) + byteOff);
            void **vt = *(void ***) handle;
            f32 (*call94)(void *) = (f32 (*)(void *)) vt[0x94 / 4];
            u8 (*call64)(void *) = (u8 (*)(void *)) vt[0x64 / 4];
            if (strcmp(bomb->unkC, name) == 0 && call94(handle) < lbl_805E3FD8 && call64(handle) != 0) {
                Bg3000Singleton *bg = (Bg3000Singleton *) kar_a2d_bg3000__near_8033ab00();
                u32 count = (u32) bg->unk6C;
                f32 a = fn_80296264(lbl_805E3F80);
                f32 b = fn_8029626C(lbl_805E3FE0) * a;
                f32 rate = fn_802D4C30(lbl_805E3FDC) * b;
                f32 vol = (f32) count * (lbl_805E3F80 * rate);
                bg = (Bg3000Singleton *) kar_a2d_bg3000__near_8033ab00();
                u32 hi = (u32) bg->unk74;
                bg = (Bg3000Singleton *) kar_a2d_bg3000__near_8033ab00();
                u32 lo = (u32) bg->unk70;
                void (*call224)(void *, u32, f32 *, u32) = (void (*)(void *, u32, f32 *, u32)) vt[0xE0 / 4];
                call224(handle, lo, &vol, hi);
            }
        }
    }
}

struct LBCollection {
    char pad0[4];
    s32 count;
    void **items;
    u16 padC;
    u16 unkE;
    void *vtable;
};

extern "C" void kar_a2d_lavabomb__near_80320708(void) {
}

extern "C" LBCollection *kar_a2d_lavabomb__near_8032070c(LBCollection *arg0, s16 arg1) {
    if (arg0 != NULL) {
        arg0->vtable = lbl_804E1620;
        for (s32 i = 0; i < arg0->count; i++) {
            void *elem = arg0->items[i];
            if (elem != NULL) {
                ((void (*)(void *, s32)) (*(void ***) ((char *) elem + 0x1AC))[2])(elem, 1);
            }
        }
        if (arg0 != NULL && arg0 != NULL && arg0 != NULL && arg0->items != NULL) {
            fn_8038CB78(arg0->items);
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

struct LBHandle {
    void *vtable;
};

extern "C" LBHandle *kar_a2d_lavabomb__near_8032188c(LBHandle *arg0, s16 arg1) {
    if (arg0 != NULL) {
        arg0->vtable = lbl_804E2110;
        lbl_805DDB2C = NULL;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

struct LBArrHandle {
    void *vtable;
    char pad4[4];
    s32 count;
    void **items;
};

extern "C" char *kar_a2d_lavabomb__near_80321a6c(char *arg0, s16 arg1) {
    if (arg0 != NULL) {
        LBArrHandle *h = (LBArrHandle *) arg0;
        h->vtable = lbl_804E2104;
        for (s32 i = 0; i < h->count; i++) {
            void *elem = h->items[i];
            if (elem != NULL) {
                ((void (*)(s32)) (*(void ***) elem)[2])(1);
            }
        }
        if ((arg0 + 4) != NULL && (arg0 + 4) != NULL && (arg0 + 4) != NULL && h->items != NULL) {
            fn_8038CB78(h->items);
        }
        if (arg0 != NULL) {
            h->vtable = lbl_804E2110;
            lbl_805DDB2C = NULL;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" char *kar_a2d_lavabomb__near_80321b5c(char *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void **) arg0 = lbl_804E22E0;
        kar_a2d_refract__near_80384600(arg0 + 0xF0, -1);
        if ((arg0 + 0xA0) != NULL) {
            *(void **) (arg0 + 0xA0) = lbl_804BDF70;
            kar_a2d_effecthandle__near_8037b33c(arg0 + 0xA0, 0);
            if ((arg0 + 0xA0) != NULL) {
                *(void **) (arg0 + 0xA0) = lbl_804BDF2C;
                ((LBNodeBase *) (arg0 + 0xA0))->Remove();
            }
        }
        if ((arg0 + 0x54) != NULL) {
            *(void **) (arg0 + 0x54) = lbl_804BDF70;
            kar_a2d_effecthandle__near_8037b33c(arg0 + 0x54, 0);
            if ((arg0 + 0x54) != NULL) {
                *(void **) (arg0 + 0x54) = lbl_804BDF2C;
                ((LBNodeBase *) (arg0 + 0x54))->Remove();
            }
        }
        if ((arg0 + 0x30) != NULL) {
            *(void **) (arg0 + 0x30) = lbl_804E21EC;
            *(void **) (arg0 + 0x44) = lbl_804E21EC + 0x28;
            if ((arg0 + 0x44) != NULL) {
                *(void **) (arg0 + 0x44) = lbl_804E2260;
                ((LBNodeBase *) (arg0 + 0x44))->Remove();
            }
            if ((arg0 + 0x30) != NULL) {
                *(void **) (arg0 + 0x30) = lbl_804BDB74;
            }
        }
        if (arg0 != NULL) {
            *(void **) arg0 = lbl_804E0EB8;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}
