#include "functions.h"
#include <dolphin/types.h>

typedef struct PlClearCheckerTemplate PlClearCheckerTemplate;
typedef struct PlClearCheckerBlock44 PlClearCheckerBlock44;

struct PlClearCheckerBlock44 {
    u32 words[9];
};

struct PlClearCheckerTemplate {
    void* unk_000;
    void* unk_004;
    u8 pad_008[0x2C];
    f32 unk_034;
    f32 unk_038;
    void* cl_object;
    void* unk_040;
    PlClearCheckerBlock44 block_044;
    u8 pad_068[0x26];
    u8 unk_08E;
    u8 unk_08F;
    u8 unk_090;
    u8 unk_091;
    u8 unk_092;
    u8 unk_093;
    u8 pad_094[0x2];
    u16 unk_096;
    u8 pad_098[0x10];
    void* unk_0A8;
    u8 pad_0AC[0x85C];
    volatile u8 flags_908;
    u8 pad_909[0x3];
};

extern PlClearCheckerTemplate plclearchecker_player_template_table[5];
extern f32 lbl_805E2A28;

#define PLCC_TEMPLATE(slot)                                                                   \
    ((PlClearCheckerTemplate*) ((u8*) plclearchecker_player_template_table +                  \
                                ((slot) * sizeof(PlClearCheckerTemplate))))
#define PLCC_FLAGS16(slot) (*(volatile u16*) &PLCC_TEMPLATE(slot)->flags_908)

f32 fn_801C7668(void* obj);
void fn_801C841C(void* obj);
void fn_801C85A8(u8 arg0, u8 arg1);
void fn_80191F5C(void* obj);
void fn_80191F74(void* obj);
void fn_80191F80(void* obj);
void fn_80191C38(void* obj);
void fn_80191CFC(void* obj);
void fn_80191D0C(void* obj);
void fn_80192084(void* obj);
void fn_80192288(void* obj);
void fn_80192380(void* obj);
void fn_801923B8(void* obj);
void fn_801C7698(void* obj);
void* fn_801C8000(void* obj);
void fn_801C8C18(void* obj);

f32 kar_plclearcheckerlib__near_8022c7e0(s32 slot)
{
    if (PLCC_TEMPLATE(slot)->unk_040 != NULL) {
        return fn_801C7668(PLCC_TEMPLATE(slot)->unk_040);
    }
    return lbl_805E2A28;
}

void kar_plclearcheckerlib__near_8022c824(s32 slot)
{
    fn_80191F5C(PLCC_TEMPLATE(slot)->cl_object);
}

void* kar_plclearcheckerlib__near_8022c858(s32 slot)
{
    return plclearchecker_player_template_table[slot].unk_000;
}

void kar_gmracenormal__8022c86c(s32 slot, void* value)
{
    plclearchecker_player_template_table[slot].unk_000 = value;
}

void* kar_cmreplay__8022c880(s32 slot)
{
    return PLCC_TEMPLATE(slot)->unk_004;
}

void kar_plclearcheckerlib__near_8022c898(s32 slot, void* value)
{
    PLCC_TEMPLATE(slot)->unk_004 = value;
}

u8 kar_plclearcheckerlib__near_8022c8b0(s32 slot)
{
    return PLCC_TEMPLATE(slot)->unk_08E;
}

void kar_plclearcheckerlib__near_8022c8c8(s32 slot, u8 value)
{
    PLCC_TEMPLATE(slot)->unk_08E = value;
}

u8 kar_plclearcheckerlib__near_8022c8e0(s32 slot)
{
    return PLCC_TEMPLATE(slot)->unk_08F;
}

void kar_plclearcheckerlib__near_8022c8f8(s32 slot, u8 value)
{
    PLCC_TEMPLATE(slot)->unk_08F = value;
}

void kar_plclearcheckerlib__near_8022c910(s32 slot)
{
    fn_801C85A8(PLCC_TEMPLATE(slot)->unk_08E, PLCC_TEMPLATE(slot)->unk_08F);
}

u8 kar_plclearcheckerlib__near_8022c948(s32 slot)
{
    return PLCC_TEMPLATE(slot)->unk_090;
}

void kar_plclearcheckerlib__near_8022c960(s32 slot, u8 value)
{
    PLCC_TEMPLATE(slot)->unk_090 = value;
}

u8 kar_plclearcheckerlib__near_8022c978(s32 slot)
{
    return PLCC_TEMPLATE(slot)->unk_091;
}

void kar_plclearcheckerlib__near_8022c990(s32 slot, u8 value)
{
    PLCC_TEMPLATE(slot)->unk_091 = value;
}

u8 kar_plclearcheckerlib__near_8022c9a8(s32 slot)
{
    return PLCC_TEMPLATE(slot)->unk_092;
}

void kar_plclearcheckerlib__near_8022c9c0(s32 slot, u8 value)
{
    PLCC_TEMPLATE(slot)->unk_092 = value;
}

u8 kar_plclearcheckerlib__near_8022c9d8(s32 slot)
{
    return PLCC_TEMPLATE(slot)->unk_093;
}

void kar_plclearcheckerlib__near_8022c9f0(s32 slot, u8 value)
{
    PLCC_TEMPLATE(slot)->unk_093 = value;
}

f32 kar_plclearcheckerlib__near_8022ca08(s32 slot)
{
    return PLCC_TEMPLATE(slot)->unk_034;
}

void kar_plclearcheckerlib__near_8022ca20(s32 slot, f32 value)
{
    PLCC_TEMPLATE(slot)->unk_034 = value;
}

void kar_plclearcheckerlib__near_8022ca38(s32 slot, f32 value)
{
    PLCC_TEMPLATE(slot)->unk_034 = value;
    if (PLCC_TEMPLATE(slot)->unk_040 != NULL) {
        fn_801C841C(PLCC_TEMPLATE(slot)->unk_040);
    }
}

f32 kar_plclearcheckerlib__near_8022ca78(s32 slot)
{
    return PLCC_TEMPLATE(slot)->unk_038;
}

void kar_plclearcheckerlib__near_8022ca90(s32 slot, f32 value)
{
    PLCC_TEMPLATE(slot)->unk_038 = value;
}

u16 kar_plclearcheckerlib__near_8022caa8(s32 slot)
{
    return PLCC_TEMPLATE(slot)->unk_096;
}

void kar_plclearcheckerlib__near_8022cac0(s32 slot, u16 value)
{
    PLCC_TEMPLATE(slot)->unk_096 = value;
}

void kar_plclearcheckerlib__near_8022cad8(s32 slot)
{
    fn_80192288(PLCC_TEMPLATE(slot)->cl_object);
}

void kar_plclearcheckerlib__near_8022cb0c(s32 slot)
{
    fn_80192380(PLCC_TEMPLATE(slot)->cl_object);
}

void kar_plclearcheckerlib__near_8022cb40(s32 slot)
{
    fn_801923B8(PLCC_TEMPLATE(slot)->cl_object);
}

void* kar_cmreplay__8022cb74(s32 slot)
{
    return PLCC_TEMPLATE(slot)->cl_object;
}

void kar_plclearchecker_call_clobject_func_191f74(s32 slot)
{
    fn_80191F74(PLCC_TEMPLATE(slot)->cl_object);
}

void kar_plclearcheckerlib__near_8022cbc0(s32 slot)
{
    fn_80191F80(PLCC_TEMPLATE(slot)->cl_object);
}

u32 kar_plclearcheckerlib__near_8022cbf4(s32 slot)
{
    return (PLCC_TEMPLATE(slot)->flags_908 >> 6) & 1;
}

void kar_plclearcheckerlib__near_8022cc10(s32 slot, u32 value)
{
    PlClearCheckerTemplate* template = PLCC_TEMPLATE(slot);
    u8 flags = template->flags_908;

    template->flags_908 = (flags & ~0x40) | ((value & 1) << 6);
}

void kar_cmreplay__8022cc30(s32 slot)
{
    fn_80191CFC(PLCC_TEMPLATE(slot)->cl_object);
}

u32 kar_plclearcheckerlib__near_8022cc64(s32 slot)
{
    return (PLCC_TEMPLATE(slot)->flags_908 >> 5) & 1;
}

void kar_plclearcheckerlib__near_8022cc80(s32 slot, u32 value)
{
    PlClearCheckerTemplate* template = PLCC_TEMPLATE(slot);
    u8 flags = template->flags_908;

    template->flags_908 = (flags & ~0x20) | ((value & 1) << 5);
}

void kar_plclearcheckerlib__near_8022cca0(s32 slot, u32 value)
{
    PlClearCheckerTemplate* template = PLCC_TEMPLATE(slot);
    u8 flags = template->flags_908;
    u32 group = ((flags >> 2) & 7) | value;

    template->flags_908 = (flags & ~0x1C) | ((group & 7) << 2);
}

void kar_plclearcheckerlib__near_8022ccc8(s32 slot, u32 value)
{
    PlClearCheckerTemplate* template = PLCC_TEMPLATE(slot);
    u8 flags = template->flags_908;

    template->flags_908 = (flags & ~0x1C) | ((value & 7) << 2);
}

u32 kar_plclearcheckerlib__near_8022cce8(s32 slot)
{
    return (PLCC_TEMPLATE(slot)->flags_908 >> 2) & 7;
}

u32 kar_plclearcheckerlib__near_8022cd04(s32 slot)
{
    u32 group = (PLCC_TEMPLATE(slot)->flags_908 >> 2) & 7;
    u32 bit;
    u32 count = 0;

    bit = 0;
    if (group & (1 << bit)) {
        count++;
    }
    bit = 1;
    if (group & (1 << bit)) {
        count++;
    }
    bit = 2;
    if (group & (1 << bit)) {
        count++;
    }
    return count;
}

void kar_plclearcheckerlib__near_8022cd64(s32 slot, u32 value)
{
    PlClearCheckerTemplate* template = PLCC_TEMPLATE(slot);
    u16 flags = *(volatile u16*) &template->flags_908;
    u32 group = ((flags >> 7) & 7) | value;

    *(volatile u16*) &template->flags_908 = (flags & ~0x380) | ((group & 7) << 7);
}

void kar_plclearcheckerlib__near_8022cd8c(s32 slot, u32 value)
{
    PlClearCheckerTemplate* template = PLCC_TEMPLATE(slot);
    u16 flags = *(volatile u16*) &template->flags_908;

    *(volatile u16*) &template->flags_908 = (flags & ~0x380) | ((value & 7) << 7);
}

u32 kar_plclearcheckerlib__near_8022cdac(s32 slot)
{
    return (PLCC_FLAGS16(slot) >> 7) & 7;
}

u32 kar_plclearcheckerlib__near_8022cdc8(s32 slot)
{
    u32 group = (PLCC_FLAGS16(slot) >> 7) & 7;
    u32 bit;
    u32 count = 0;

    bit = 0;
    if (group & (1 << bit)) {
        count++;
    }
    bit = 1;
    if (group & (1 << bit)) {
        count++;
    }
    bit = 2;
    if (group & (1 << bit)) {
        count++;
    }
    return count;
}

void kar_plclearcheckerlib__near_8022ce28(void)
{
    s32 i;

    for (i = 0; i < 5; i++) {
        if (plclearchecker_player_template_table[i].cl_object != NULL &&
            plclearchecker_player_template_table[i].unk_040 != NULL) {
            fn_80191C38(plclearchecker_player_template_table[i].cl_object);
            fn_801C7698(plclearchecker_player_template_table[i].unk_040);
        }
    }
}

void kar_plclearcheckerlib__near_8022ce94(s32 slot)
{
    if (PLCC_TEMPLATE(slot)->unk_040 != NULL) {
        fn_801C8C18(PLCC_TEMPLATE(slot)->unk_040);
    } else {
        fn_80192084(PLCC_TEMPLATE(slot)->cl_object);
    }
}

void* kar_plclearcheckerlib__near_8022cedc(s32 slot)
{
    if (PLCC_TEMPLATE(slot)->unk_040 != NULL) {
        return fn_801C8000(PLCC_TEMPLATE(slot)->unk_040);
    }
    return NULL;
}

void kar_plclearcheckerlib__near_8022cf20(s32 slot)
{
    fn_80191D0C(PLCC_TEMPLATE(slot)->cl_object);
}

void kar_plclearcheckerlib__near_8022cf54(s32 slot, void* value)
{
    PLCC_TEMPLATE(slot)->unk_040 = value;
}

void kar_plclearcheckerlib__near_8022cf6c(s32 slot, PlClearCheckerBlock44* out)
{
    *out = PLCC_TEMPLATE(slot)->block_044;
}

void kar_plclearcheckerlib__near_8022cfc8(s32 slot, PlClearCheckerBlock44* value)
{
    PLCC_TEMPLATE(slot)->block_044 = *value;
}

void* kar_plclearcheckerlib__near_8022d024(s32 slot)
{
    return PLCC_TEMPLATE(slot)->unk_0A8;
}

void kar_plclearcheckerlib__near_8022d03c(s32 slot, void* value)
{
    PLCC_TEMPLATE(slot)->unk_0A8 = value;
}
