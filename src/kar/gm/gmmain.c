#include "functions.h"
#include <dolphin/types.h>
#include <kar/gm/gmclearchecker.h>
#include <kar/gm/gmdialogue.h>
#include <kar/gm/gmglobal.h>
#include <kar/gm/gmlanmenu.h>
#include <kar/gm/gmmain.h>
#include <kar/lb/lbaudio.h>
#include <sysdolphin/video.h>

typedef struct HSD_PadData HSD_PadData;
typedef struct HSD_PadRumbleListData HSD_PadRumbleListData;

typedef struct {
    u8 unk_00[0x43];
    s8 err;
} HSD_PadStatusLocal;

typedef union {
    u8 flags;
    struct {
        u8 b7 : 1;
        u8 b6 : 1;
        u8 b5 : 1;
        u8 b4 : 1;
        u8 b3 : 1;
        u8 b2_b1 : 2;
        u8 b0 : 1;
    };
} GmMainFlagByte;

typedef union {
    u8 flags;
    struct {
        u8 b7_b6 : 2;
        u8 b5 : 1;
        u8 b4 : 1;
        u8 b3 : 1;
        u8 b2_b1 : 2;
        u8 b0 : 1;
    };
} GmMainPackedFlagByte;

extern u8 lbl_805359D8[];
extern u8 HSD_PadState[];
extern HSD_PadStatusLocal HSD_PadMasterStatus[];

u8 lbl_80535300[0x694];
u8 lbl_80535994[0x44];
void* lbl_805DD568[2];
s32 lbl_805DD564;
s32 lbl_805DD560;
void* lbl_805DD558[2];
s32 lbl_805DD554;
s32 lbl_805DD550;
s32 lbl_805DD54C;
s32 lbl_805DD548;
s32 lbl_805DD540[2];
void* lbl_805DD538[2];
void (*lbl_805DD534)(void);
s32 lbl_805DD530;
s32 lbl_805DD52C;
s32 lbl_805DD528;
u8 lbl_805DD520[8];

void HSD_PadInit(u8 qnum, HSD_PadData* queue, HSD_PadData* queue2, u16 nb_list,
                 HSD_PadRumbleListData* listdatap);
void* memset(void* dst, int val, unsigned long n);
s8 fn_8000AAC4(void);
u8 kar_gmracenormal__8000aea8(void);
void HSD_PadReset(void);
void HSD_PadFlushQueue(s32 arg0);
void HSD_VIWaitXFBFlush(void);
void kar_lbaudio__near_8005a064(void);
u8 kar_lbaudio__near_800628a0(void);
void kar_lbaudio__near_8006293c(s32 arg0);
void kar_lbaudio__near_80062978(void);
void kar_lbhvqm__near_800782cc(void);
void kar_lbhvqm__near_80078cf0(void);
void kar_lbhvqm__near_80078e74(void);
void kar_lbhvqm__near_800791f8(void);
void kar_gmglobal__8000714c(void);
void kar_gmglobal__near_80008270(void);
void kar_gmglobal__near_80008898(void);
void kar_lbkdcoll__near_80071d7c(void);
s32 kar_lbkdcoll__near_80076088(void);
s32 kar_lbkdcoll__near_8007617c(void);
s32 kar_lbkdcoll__near_80076730(void);
s32 kar_lbkdcoll__near_80076850(void);
void kar_lbkdcoll__near_800769ac(void);
s32 kar_shadow__near_8007b624(void);
s32 kar_shadow__near_8007b640(void);
void* fn_803DF618(void);
void fn_80041664(void);
void fn_80041740(void);
void fn_800418F4(void);
void fn_8007CBB0(void);
void fn_80131878(void);
u32 kar_osthread__near_803d96b4(void);
void kar_osthread__near_803d9724(s32 arg0);

#define GMMAIN_BASE ((u8*) kar_gmmain__near_80006c14())
#define GMMAIN_FIELD_U8(offset) (*(u8*) (GMMAIN_BASE + (offset)))
#define GMMAIN_FIELD_U32(offset) (*(u32*) (GMMAIN_BASE + (offset)))
#define GMMAIN_FLAGS(base, offset) (*(GmMainFlagByte*) ((base) + (offset)))
#define GMMAIN_PACKED_FLAGS(base, offset)                                      \
    (*(GmMainPackedFlagByte*) ((base) + (offset)))

void fn_80005800(void)
{
    HSD_PadData* queue = (HSD_PadData*) lbl_80535300;

    HSD_PadInit(5, queue, (HSD_PadData*) ((u8*) queue + 0x104), 0xC,
                (HSD_PadRumbleListData*) ((u8*) queue + 0x514));

    HSD_PadState[0x4C] = 0;
    HSD_PadState[0x4D] = 1;
    HSD_PadState[0x4E] = 0x50;
    HSD_PadState[0x4F] = 0;
    HSD_PadState[0x56] = 0x50;
    HSD_PadState[0x50] = 1;
    HSD_PadState[0x51] = 0x8C;
    HSD_PadState[0x52] = 0;
    HSD_PadState[0x57] = 0x8C;
    HSD_PadState[0x44] = 0;
    HSD_PadState[0x45] = 0x32;
    *(f32*) (HSD_PadState + 0x48) = 0.5235988f;
    HSD_PadState[0x59] = 3;
}

void fn_80005894(void)
{
}

void* kar_gmmain__near_80005cbc(void)
{
    return GMMAIN_BASE + 0x7E0;
}

u32 kar_gmmain__near_80005ce0(void)
{
    return GMMAIN_FIELD_U32(0x7E4);
}

u32 kar_gmmain__near_80005d04(s32 bit)
{
    u8* base = kar_gmmain__near_80006c14();
    u64 mask = 1;
    u32 flags;

    flags = base[0x7F0];
    return flags & (u32) (mask << bit);
}

u8 kar_gmmain__near_80005d54(void)
{
    return GMMAIN_FIELD_U8(0x7F0);
}

void kar_gmmain__near_80005d78(s32 bit)
{
    u8* base = kar_gmmain__near_80006c14();
    u64 mask = 1;

    base[0x7F0] |= (u32) (mask << bit);
}

void kar_gmmain__near_80005dcc(s32 bit)
{
    u8* base = kar_gmmain__near_80006c14();
    u64 mask = 1;
    u32 inverse;

    inverse = ~((u32) (mask << bit));
    base[0x7F0] = base[0x7F0] & inverse;
}

#define PAD_MASTER(index) ((u8*) HSD_PadMasterStatus + ((u8) (index) * 0x44))
#define PAD_SOFT_RESET(index)                                                   \
    (*(s8*) (PAD_MASTER(index) + 0x43) == 0 &&                                  \
     (*(u32*) (PAD_MASTER(index) + 8) & 4) != 0 &&                              \
     (*(u32*) PAD_MASTER(index) & 0x20) != 0)

s32 fn_80005E24(void)
{
    s32 i;

    for (i = 0; i < 4; i++) {
        if (PAD_SOFT_RESET(i)) {
            return 1;
        }
    }

    return 0;
}

s32 kar_gmmain__near_80005f14(void)
{
    s32 i;
    u8* master = (u8*) HSD_PadMasterStatus;

    for (i = 0; i < 4; i++) {
        u8* pad = master + ((u8) i * 0x44);
        s8* err = (s8*) (pad + 0x43);

        if (*err == 0) {
            if (fn_8000AAC4()) {
                if (*err == 0 && (*(u32*) (pad + 8) & 4) != 0 &&
                    (*(u32*) pad & 0x20) != 0) {
                    return 1;
                }
            } else if ((*(u32*) (pad + 8) & 0x1000) != 0) {
                return 1;
            }
        }
    }

    return 0;
}

#define PAD_CSTICK_LEFT(index)                                                   \
    (*(s8*) (PAD_MASTER(index) + 0x43) == 0 &&                                  \
     (*(u32*) (PAD_MASTER(index) + 0xC) & 0x10) != 0)

s32 fn_80005FD4(void)
{
    s32 i;

    for (i = 0; i < 4; i++) {
        if (PAD_CSTICK_LEFT(i)) {
            return 1;
        }
    }

    return 0;
}

void kar_gmmain__near_8000631c(void)
{
    u8* base = kar_gmmain__near_80006c14();

    *(void**) (base + 0x7F4) = kar_gmmain__near_80005f14;
    *(void**) (base + 0x7F8) = fn_80005FD4;
}

void kar_gmmain__near_80006354(s8 value)
{
    u8* base = kar_gmmain__near_80006c14();

    base[0x828] = value;
}

u8 kar_gmmain__near_80006384(void)
{
    u8* base = kar_gmmain__near_80006c14();

    return base[0x828];
}

void kar_gmmain__near_800063a8(void)
{
    s32* state;
    u32 mode = kar_gmracenormal__8000aea8();
    u32 pads;

    lbl_805DD540[0] = 1;
    if (kar_shadow__near_8007b624() != 0) {
        kar_lbkdcoll__near_800769ac();
        lbl_805DD540[0] = 2;
    }

    state = lbl_805DD540;
    if (state[1] == 2) {
        lbl_805DD540[0] = 2;
    }

    if (mode == 0x0D && kar_gmdialogue__near_80047350() != 0) {
        lbl_805DD540[0] = 3;
    }

    kar_lbaudio__near_80062978();
    pads = *(u32*) PAD_MASTER(0);
    pads |= *(u32*) PAD_MASTER(1);
    pads |= *(u32*) PAD_MASTER(2);
    pads |= *(u32*) PAD_MASTER(3);
    if (state[1] == 1) {
        HSD_PadReset();
    }

    kar_lbhvqm__near_80078cf0();
    kar_gmglobal__8000714c();
    fn_80131878();
    kar_lbaudio__near_8005a064();
    kar_lbaudio__near_8005e788();
    kar_lbaudio__near_8005e5d0();
    kar_lbhvqm__near_800782cc();
    kar_lbhvqm__near_800791f8();
    kar_gmglobal__near_80008270();
    kar_gmglobal__near_80008898();

    if (lbl_805DD540[0] == 3) {
        if (fn_803DF618() != NULL &&
            ((pads & 0x200) != 0 || kar_osthread__near_803d96b4() == 1)) {
            kar_gmlanmenu__800082a0(0x0D);
        } else {
            kar_osthread__near_803d9724(0);
            kar_gmlanmenu__800082a0(0x12);
        }
    } else {
        kar_gmlanmenu__800082a0(0x12);
    }

    kar_gmlanmenu__80008220();
    HSD_VISetBlack(0);
}

void kar_gmmain__near_800064f0(void)
{
    u8* base = kar_gmmain__near_80006c14();

    base[0x7E0] = 1;
}

void kar_gmmain__near_80006518(void)
{
    u8* base = kar_gmmain__near_80006c14();

    base[0x829] = 1;
}

void kar_gmmain__near_80006b58(void)
{
    u8* base = kar_gmmain__near_80006c14();

    if (kar_shadow__near_8007b640() == 0) {
        HSD_PadFlushQueue(2);
    } else {
        fn_8007CBB0();
    }

    while ((s8) base[0x7E0] == 0) {
        kar_lbaudio__near_8006293c(0);
        kar_lbhvqm__near_80078e74();
        if (kar_lbkdcoll__near_80076088() != 0) {
            if (kar_lbkdcoll__near_8007617c() != 0) {
                break;
            }
        } else if (kar_lbkdcoll__near_80076730() != 0) {
            if (kar_lbkdcoll__near_80076850() != 0) {
                break;
            }
        } else if (kar_lbaudio__near_800628a0() != 0 &&
                   kar_gmmain__near_800067a4() != 0) {
            break;
        }
    }

    HSD_VIWaitXFBFlush();
    kar_lbkdcoll__near_80071d7c();
}

void* kar_gmmain__near_80006c14(void)
{
    return lbl_805359D8;
}

void* kar_gmmain__near_80006c20(void)
{
    return lbl_805359D8 + 0xD68;
}

s32 kar_gmmain__near_80006c30(void)
{
    return 0x7B0;
}

void* kar_gmmain__near_80006c38(void)
{
    return lbl_805359D8 + 0xCC8;
}

void kar_gmmain__near_80006c48(void)
{
    u8* data = lbl_805359D8 + 0xA94;

    memset(data, 0, 0x34);
    GMMAIN_FLAGS(data, 0x12).b7 = 1;
    GMMAIN_FLAGS(data, 0x12).b6 = 1;
    GMMAIN_FLAGS(data, 0x11).b4 = 0;
    GMMAIN_FLAGS(data, 0x12).b5 = 1;
    GMMAIN_PACKED_FLAGS(data, 0x13).b7_b6 = 0;
    GMMAIN_FLAGS(data, 0x11).b3 = 0;
    GMMAIN_FLAGS(data, 0x12).b4 = 1;
    GMMAIN_FLAGS(data, 0x11).b2_b1 = 1;
    GMMAIN_FLAGS(data, 0x13).b5 = 1;
    GMMAIN_FLAGS(data, 0x12).b3 = 0;
    GMMAIN_FLAGS(data, 0x11).b0 = 0;
    GMMAIN_FLAGS(data, 0x13).b4 = 1;
    GMMAIN_FLAGS(data, 0x12).b2_b1 = 1;
    data[1] = 1;
    data[2] = 1;
    data[3] = 0;
    data[4] = 0;
    data[5] = 0;
    data[0] = 0;
    data[6] = 0;
    *(u16*) (data + 8) = 0x78;
    *(u32*) (data + 0x0C) = 0;
    *(u32*) (data + 0x28) = 0;
    GMMAIN_FLAGS(data, 0x12).b4 = 0;
    GMMAIN_FLAGS(data, 0x13).b3 = 0;
    data[0x10] = 1;
    GMMAIN_FLAGS(data, 0x11).b5 = 0;
}

void kar_gmmain__near_80006d80(s8 index)
{
    s32 offset = index * 0x30;
    u8* list = lbl_805359D8 + 0xAC8;
    u8* entry = list + offset;

    memset(entry, 0, 0x30);
    entry[0] = 4;
    entry[1] = 0;
    entry[3] = 0;
    entry[4] = index;
    entry[5] = 1;
    entry[6] = index;
    entry[7] = -1;
    entry[8] = 8;
    entry[9] = 0;
    *(f32*) (entry + 0x0C) = 0.0f;
    *(f32*) (entry + 0x10) = 0.0f;
    *(f32*) (entry + 0x14) = 0.0f;
    *(f32*) (entry + 0x18) = 0.0f;
    *(f32*) (entry + 0x1C) = 0.0f;
    *(f32*) (entry + 0x20) = 0.0f;
    *(f32*) (entry + 0x24) = 0.0f;
    *(f32*) (entry + 0x28) = 0.0f;
    *(f32*) (entry + 0x2C) = 0.0f;
}

void kar_gmmain__near_80006e48(s8 index)
{
    s32 offset = index * 3;
    u8* list = lbl_805359D8 + 0xBB8;
    u8* entry = list + offset;

    memset(entry, 0, 3);
    entry[0] = -1;
    entry[1] = 0;
    entry[2] = -1;
}

void kar_gmmain__near_80006eb8(void)
{
    memset(lbl_805359D8 + 0xBC4, 0, 0x100);
}

void* kar_gmmain__near_80006eec(void)
{
    u8* data;
    u8* block;

    memset(kar_gmglobal__near_8000771c(), 0, 0x118);
    ClearChecker_ShuffleRewardSlots(0);
    memset(kar_gmglobal__near_8000772c(), 0, 0x128);
    ClearChecker_ShuffleRewardSlots(1);
    memset(kar_gmglobal__near_8000774c(), 0, 0x114);
    ClearChecker_ShuffleRewardSlots(2);
    fn_80041664();
    fn_80041740();
    fn_800418F4();

    data = kar_gmglobal__near_800077e0();
    memset(data, 0, 0x14);
    data[0] = 1;
    data[1] = 1;
    data[2] = 1;
    data[3] = 1;
    *(f32*) (data + 4) = 0.0f;
    data[8] = 0;
    data[9] = 0;
    data[0x0A] = 0;
    *(u32*) (data + 0x0C) = 0x221;
    *(u32*) (data + 0x10) = 0x221;

    data = lbl_805359D8 + 0x354;
    memset(data, 0, 0x20);
    GMMAIN_PACKED_FLAGS(data, 6).b7_b6 = 1;
    GMMAIN_PACKED_FLAGS(data, 6).b5 = 0;
    GMMAIN_PACKED_FLAGS(data, 6).b4 = 1;
    GMMAIN_PACKED_FLAGS(data, 6).b2_b1 = 1;
    data[0] = 0;
    *(u16*) (data + 2) = 0;
    *(u16*) (data + 4) = 0x78;
    data[8] = 0;
    data[9] = -1;
    data[0x0E] = 0;
    data[0x0F] = -1;
    data[0x12] = 0;
    data[0x13] = 0;
    data[0x14] = 0;
    data[0x15] = 0;

    block = lbl_805359D8 + 0x374;
    memset(block, 0, 0x1E);
    memset(block, 0, 0x0D);
    block[0] = 0;
    block[1] = 0;
    block[2] = 0;
    block[3] = 0;
    block[4] = 1;
    block[5] = 1;
    block[6] = 0;
    block[7] = 0;
    block[8] = 1;
    block[9] = 0;
    block[0x0A] = 0;
    block[0x0B] = 0;
    block[0x0C] = 0;
    block[0x0D] = -1;
    block[0x12] = 0;
    block[0x13] = -1;
    block[0x16] = 0;
    block[0x17] = 0;
    block[0x18] = 0;
    block[0x19] = 0;

    data = lbl_805359D8 + 0x394;
    memset(data, 0, 0xF0);
    GMMAIN_PACKED_FLAGS(data, 3).b7_b6 = 1;
    GMMAIN_PACKED_FLAGS(data, 3).b5 = 1;
    *(u16*) data = 0x12C;
    data[2] = 0;
    data[4] = 0;
    data[5] = -1;
    data[0xCA] = -1;
    data[0xCB] = -1;
    data[0xCC] = -1;
    data[0xCD] = -1;
    data[0xCF] = 0;
    data[0xD3] = 0;
    data[0xD0] = 0;
    data[0xD4] = 0;
    data[0xD1] = 0;
    data[0xD5] = 0;
    data[0xD2] = 0;
    data[0xD6] = 0;
}
