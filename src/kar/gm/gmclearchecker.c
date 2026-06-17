#include "functions.h"
#include <dolphin/types.h>

typedef struct GmGlobalSaveData GmGlobalSaveData;
typedef struct GmGlobalData GmGlobalData;
typedef struct GmClearCheckerSharedData GmClearCheckerSharedData;
typedef struct GmMainData GmMainData;
typedef s32 (*GmClearCheckerPredicate)(s32 number);

struct GmGlobalSaveData {
    u8 pad_0[0x7C];
    u8 clearchecker_flags[0x78];
};

struct GmGlobalData {
    u8 pad_000[0xF4];
    s32 clearchecker_total_0;
    s32 clearchecker_total_1;
    s32 clearchecker_total_2;
    s32 clearchecker_total_3;
    s32 clearchecker_total_4;
    s32 clearchecker_total_5;
    s32 clearchecker_total_6;
    s32 clearchecker_total_7;
    s32 clearchecker_total_8;
};

struct GmClearCheckerSharedData {
    u8 pad_000[0x174];
    u8* type_tables[3];
    char type_error[0x1C];
    char source_file[0x11];
};

struct GmMainData {
    u8 pad_00[0x2B];
    s8 clearchecker_flag;
    u8 pad_2C[0xA5C];
    s32 clearchecker_index;
};

extern GmClearCheckerSharedData lbl_804973E8;
extern GmClearCheckerPredicate lbl_804975B8[];
extern GmClearCheckerPredicate lbl_80497630[];
extern u8 lbl_80497674[];
extern u8 lbl_80497694[];
extern u32 lbl_805DD590;

char lbl_80497568[] = "error Clearchecker Type %d\n";
char kar_src_gmclearchecker_80497584[] = "gmclearchecker.c";
char lbl_80497598[] = "error Clearchecker Number %d\n";
u8 lbl_805D51D0[] = ".!,";
char lbl_805D51D4[] = "0";

extern void OSReport(const char*, ...);
GmGlobalSaveData* kar_gmglobal__800076a0();
GmGlobalData* kar_gmglobal__near_8000771c(void);
s32 kar_shadow__near_8007b650(void);
u32 kar_gmmain__near_80005ce0(void);
void kar_gmmain__near_800064f0(void);
GmMainData* kar_gmmain__near_80006c14(void);
void kar_gmglobal__near_800088c8(s32 value);
void kar_lbaudio__near_8006176c(u32 sound_id);
u8 kar_mnclearchecker_get_main_state_or_assert_operating(void);
void kar_mnclearchecker_create_screen_and_sis_resources(u8 arg0, u8 arg1);
s32 fn_8000AECC(void);
void fn_8000BC10(void);
s32 kar_gmracenormal__8000aea8(void);
s32 fn_8000AAC4(void);
s32 fn_8000A97C(void);
s32 kar_gmracenormal__8000af5c(void);
s32 kar_gmracenormal__8003d5f0(void);
s32 kar_plclearcheckerlib__near_8022c858(s32 arg0);
s32 kar_plclearcheckerlib__8023156c(s32 arg0);
s32 kar_plclearcheckerlib__8022eb88(s32 arg0);
s32 kar_plclearcheckerlib__8022eb10(s32 arg0, s32 arg1);
s32 kar_plclearcheckerlib__8022ea98(s32 arg0, s32 arg1);
s32 kar_plclearcheckerlib__802306d4(s32 arg0);
s32 fn_8000B1EC(s32 arg0);
s32 fn_8000979C(s32 arg0);
s32 fn_800092D8(void);
s32 fn_80261CE8(s32 arg0);
u32 fn_8000A300(void);
s32 fn_8000916C(void);
void kar_gmclearchecker__near_8004d248(s32 arg0);
void kar_gmclearchecker__near_8004d454(void);
void kar_gmclearchecker__near_8004d5d4(s32 arg0);
void kar_gmclearchecker__near_8004d8a8(s32 arg0);
s32 kar_gmclearchecker__near_8004ab90(void);
s32 kar_gmclearchecker__near_8004acf4(void);
s32 kar_gmclearchecker__near_8004ae50(void);
s32 kar_gmclearchecker__near_8004b1d0(void);
s32 kar_gmclearchecker__near_8004b2b8(void);
s32 kar_gmclearchecker__near_8004b404(void);
s32 kar_gmclearchecker__near_8004b814(void);
s32 kar_gmclearchecker__near_8004b968(void);
s32 kar_gmclearchecker__near_8004bb1c(void);
void kar_gmlanmenu__8000bba0(void);
void fn_80138D74(void);
void fn_80138E00(void);

#define GMCC_TYPE_COUNT 3
#define GMCC_NUMBER_COUNT 0x78

#define CHECK_TYPE(type, line)                                     \
    do {                                                           \
        if ((u8) (type) >= GMCC_TYPE_COUNT) {                      \
            OSReport(lbl_80497568, (u8) (type));                   \
            __assert(kar_src_gmclearchecker_80497584, line,        \
                     lbl_805D51D4);                                \
        }                                                          \
    } while (0)

#define CHECK_TYPE_WITH_BASE(base, type, line)                     \
    do {                                                           \
        if ((u8) (type) >= GMCC_TYPE_COUNT) {                      \
            OSReport((base)->type_error, (u8) (type));             \
            __assert((base)->source_file, line, lbl_805D51D4);     \
        }                                                          \
    } while (0)

#define CHECK_NUMBER(number, line)                                 \
    do {                                                           \
        if ((u8) (number) >= GMCC_NUMBER_COUNT) {                  \
            OSReport(lbl_80497598, (u8) (number));                 \
            __assert(kar_src_gmclearchecker_80497584, line,        \
                     lbl_805D51D4);                                \
        }                                                          \
    } while (0)

u8 kar_gmclearchecker__80049c20(s32 type)
{
    CHECK_TYPE(type, 0x41);
    return lbl_805D51D0[(u8) type];
}

u8 kar_gmclearchecker__80049c84(s32 type, s32 index)
{
    GmClearCheckerSharedData* base = &lbl_804973E8;
    u8** tables;
    u32 type_offset;
    u32 offset;

    CHECK_TYPE_WITH_BASE(base, type, 0x37);
    offset = (u8) index * 3 + 2;
    tables = (u8**) ((u8*) base + 0x174);
    type_offset = (u8) type << 2;
    return (*(u8**) ((u8*) tables + type_offset))[offset];
}

u8 kar_gmclearchecker__80049d10(s32 type, s32 index)
{
    GmClearCheckerSharedData* base = &lbl_804973E8;
    u8** tables;
    u32 type_offset;
    u32 offset;

    CHECK_TYPE_WITH_BASE(base, type, 0x37);
    offset = (u8) index * 3;
    tables = (u8**) ((u8*) base + 0x174);
    type_offset = (u8) type << 2;
    return (*(u8**) ((u8*) tables + type_offset))[offset];
}

u8 kar_gmclearchecker__80049d98(s32 type, s32 index)
{
    GmClearCheckerSharedData* base = &lbl_804973E8;
    u8** tables;
    u32 type_offset;
    u32 offset;

    CHECK_TYPE_WITH_BASE(base, type, 0x37);
    offset = (u8) index * 3 + 1;
    tables = (u8**) ((u8*) base + 0x174);
    type_offset = (u8) type << 2;
    return (*(u8**) ((u8*) tables + type_offset))[offset];
}

u8 kar_gmclearchecker__80049e24(s32 type, s32 index)
{
    u8* entry;
    GmGlobalSaveData* save;
    GmClearCheckerSharedData* base = &lbl_804973E8;
    u8** tables;
    u32 type_offset;
    u32 offset;

    CHECK_TYPE_WITH_BASE(base, type, 0x37);
    offset = (u8) index * 3;
    tables = (u8**) ((u8*) base + 0x174);
    type_offset = (u8) type << 2;
    entry = *(u8**) ((u8*) tables + type_offset) + offset;
    save = kar_gmglobal__800076a0(type);
    return (save->clearchecker_flags[entry[2]] >> 3) & 1;
}

void kar_gmclearchecker__80049ec4(s32 type, s32 number, u8* out_index, u8* out_value)
{
    GmClearCheckerSharedData* base = &lbl_804973E8;
    GmGlobalSaveData* save = kar_gmglobal__800076a0(type);
    u32 number_u = (u8) number;

    if ((save->clearchecker_flags[number_u] & 6) != 0) {
        u32 type_u = (u8) type;
        u32 type_offset = type_u << 2;
        u8** tables = (u8**) ((u8*) base + 0x174);
        u8* counts = lbl_805D51D0;
        u32 i = 0;

        while (i < counts[type_u]) {
            u8* entry;
            u32 offset;

            CHECK_TYPE_WITH_BASE(base, type, 0x37);
            offset = (u8) i * 3;
            entry = *(u8**) ((u8*) tables + type_offset) + offset;
            if (number_u == entry[2]) {
                *out_index = i;
                *out_value = entry[1];
                return;
            }
            i++;
        }
    }

    *out_index = 0xFF;
}

void kar_gmclearchecker__80049fcc(s32 arg0, s32 number)
{
    GmGlobalSaveData* save = kar_gmglobal__800076a0(arg0);

    if (kar_shadow__near_8007b650() == 0) {
        CHECK_NUMBER(number, 0x94);
        save->clearchecker_flags[(u8) number] |= 1;
    }
}

#pragma push
#pragma dont_inline on
void kar_gmclearchecker__8004a054(s32 arg0, s32 number)
{
    GmGlobalSaveData* save = kar_gmglobal__800076a0(arg0);

    if (kar_shadow__near_8007b650() == 0) {
        CHECK_NUMBER(number, 0xA5);
        save = (GmGlobalSaveData*) ((u8*) save + (u8) number);
        if ((save->clearchecker_flags[0] & 5) == 0) {
            u32 frame = kar_gmmain__near_80005ce0();
            if (lbl_805DD590 != frame) {
                kar_lbaudio__near_8006176c(0x10008);
                lbl_805DD590 = kar_gmmain__near_80005ce0();
            }
        }
        save->clearchecker_flags[0] |= 1;
    }
}
#pragma pop

void kar_gmclearchecker__near_8004a10c(void)
{
    lbl_805DD590 = kar_gmmain__near_80005ce0();
}

#pragma push
#pragma dont_inline on
u8 kar_gmclearchecker__8004a130(s32 arg0, s32 number)
{
    GmGlobalSaveData* save = kar_gmglobal__800076a0(arg0);

    CHECK_NUMBER(number, 0xC6);
    return save->clearchecker_flags[(u8) number];
}
#pragma pop

s32 kar_gmclearchecker__near_8004a1a4(void)
{
    GmGlobalSaveData* save = kar_gmglobal__800076a0();
    s32 i;

    if (kar_shadow__near_8007b650() != 0) {
        return 0;
    }

    for (i = 0; i < GMCC_NUMBER_COUNT; i++) {
        u8 flags = save->clearchecker_flags[i];
        if ((flags & 4) == 0 && (flags & 1) != 0) {
            return 1;
        }
    }

    return 0;
}

void kar_gmclearchecker__near_8004a648(void)
{
    s32 minor;

    switch (kar_mnclearchecker_get_main_state_or_assert_operating()) {
    case 0xB:
        kar_gmglobal__near_800088c8(-1);
        kar_gmmain__near_800064f0();
        break;
    case 0xC:
        kar_lbaudio__near_8006176c(0x1000A);
        minor = (s8) fn_8000AECC();
        kar_gmglobal__near_800088c8((s8) (++minor > 0x22 ? 0x20 : minor));
        kar_gmmain__near_800064f0();
        break;
    case 0xD:
        kar_lbaudio__near_8006176c(0x1000A);
        minor = (s8) fn_8000AECC();
        kar_gmglobal__near_800088c8((s8) (--minor < 0x20 ? 0x22 : minor));
        kar_gmmain__near_800064f0();
        break;
    case 0xE:
        fn_8000BC10();
        switch ((s8) fn_8000AECC()) {
        case 0x20:
            kar_gmglobal__near_800088c8(0x1C);
            break;
        case 0x21:
            kar_gmglobal__near_800088c8(0x1D);
            break;
        case 0x22:
            kar_gmglobal__near_800088c8(0x1E);
            break;
        }
        kar_gmmain__near_800064f0();
        break;
    }
}

void kar_gmclearchecker__near_8004a768(void)
{
    GmMainData* main = kar_gmmain__near_80006c14();
    s32 flag;
    s32 minor;

    fn_80138D74();
    flag = main->clearchecker_flag == 0;
    minor = fn_8000AECC() - 0x20;
    kar_mnclearchecker_create_screen_and_sis_resources((u8) minor, (u8) flag);
    if ((s8) kar_gmracenormal__8000aea8() == 3) {
        kar_gmlanmenu__8000bba0();
    }
}

void kar_gmclearchecker__near_8004a7d0(void)
{
    fn_80138E00();
}

void kar_gmclearchecker__near_8004a7f0(void)
{
    GmMainData* main;
    GmClearCheckerPredicate predicate;
    s32 i;
    s32 index;
    s32 number;

    if (kar_shadow__near_8007b650() != 0) {
        return;
    }
    if ((s8) fn_8000AAC4() != 0) {
        return;
    }
    if ((s8) kar_gmracenormal__8000af5c() != 0) {
        return;
    }
    switch ((s8) fn_8000A97C()) {
    case 0:
        if ((s8) kar_gmracenormal__8000aea8() == 4) {
            main = kar_gmmain__near_80006c14();
            for (i = 0; i < 4; i++) {
                index = main->clearchecker_index;
                number = lbl_80497694[index];
                if ((kar_gmclearchecker__8004a130(0, number) & 5) == 0) {
                    index = main->clearchecker_index;
                    predicate = lbl_80497630[index];
                    if (predicate != NULL && predicate(number) == 1) {
                        kar_gmclearchecker__8004a054(0, number);
                    }
                }
                main->clearchecker_index++;
                if (main->clearchecker_index >= 0x11) {
                    main->clearchecker_index = 0;
                }
            }
        }
    }
}

void kar_gmclearchecker__near_8004a90c(s32 arg0)
{
    if (kar_shadow__near_8007b650() != 0) {
        return;
    }
    if ((s8) fn_8000AAC4() != 0) {
        return;
    }
    switch ((s8) kar_gmracenormal__8000af5c()) {
    case 0:
        if ((s8) kar_gmracenormal__8000aea8() == 4) {
            if (kar_plclearcheckerlib__near_8022c858(arg0) == 0) {
                if ((s8) kar_gmracenormal__8003d5f0() == 2) {
                    kar_gmclearchecker__near_8004d8a8(arg0);
                }
            }
        }
    }
}

void kar_gmclearchecker__near_8004a994(s32 arg0)
{
    s32 mode;

    if (kar_shadow__near_8007b650() != 0) {
        return;
    }
    if ((s8) fn_8000AAC4() != 0) {
        return;
    }
    if ((s8) kar_gmracenormal__8000af5c() == 0) {
        if ((s8) kar_gmracenormal__8000aea8() == 4) {
            if (kar_plclearcheckerlib__near_8022c858(arg0) == 0) {
                mode = kar_gmracenormal__8003d5f0();
                if ((s8) mode == 0) {
                    if ((u8) fn_8000A300() == 1) {
                        if ((s8) fn_8000916C() != 0) {
                            return;
                        }
                        kar_gmclearchecker__near_8004d248(arg0);
                        return;
                    }
                }
                if ((s8) mode == 1) {
                    kar_gmclearchecker__near_8004d5d4(arg0);
                }
            }
        }
    }
}

void kar_gmclearchecker__near_8004aa58(void)
{
    GmGlobalData* global;
    s32 i;
    s32 number;

    if (kar_shadow__near_8007b650() != 0) {
        return;
    }
    if ((s8) fn_8000AAC4() != 0) {
        return;
    }

    switch ((s8) kar_gmracenormal__8000af5c()) {
    case 0:
        if ((s8) kar_gmracenormal__8000aea8() == 4) {
            global = kar_gmglobal__near_8000771c();
            for (i = 0; i < 0x1E; i++) {
                number = lbl_80497674[i];
                if ((kar_gmclearchecker__8004a130(0, number) & 5) == 0) {
                    GmClearCheckerPredicate predicate = lbl_804975B8[i];

                    if (predicate != NULL && predicate(number) == 1) {
                        kar_gmclearchecker__8004a054(0, number);
                    }
                }
            }

            if ((s8) fn_8000916C() == 1) {
                kar_gmclearchecker__near_8004d454();
            }

            global->clearchecker_total_0 = kar_gmclearchecker__near_8004ab90();
            global->clearchecker_total_1 = kar_gmclearchecker__near_8004acf4();
            global->clearchecker_total_2 = kar_gmclearchecker__near_8004ae50();
            global->clearchecker_total_3 = kar_gmclearchecker__near_8004b1d0();
            global->clearchecker_total_4 = kar_gmclearchecker__near_8004b2b8();
            global->clearchecker_total_5 = kar_gmclearchecker__near_8004b404();
            global->clearchecker_total_6 = kar_gmclearchecker__near_8004b814();
            global->clearchecker_total_7 = kar_gmclearchecker__near_8004b968();
            global->clearchecker_total_8 = kar_gmclearchecker__near_8004bb1c();
        }
    }
}

s32 kar_gmclearchecker__near_8004ab90(void)
{
    s32 mode;
    GmGlobalData* global;
    s32 i;
    s32 total;
    s32 player_state;
    s32 value;

    mode = kar_gmracenormal__8003d5f0();
    global = kar_gmglobal__near_8000771c();
    mode = (s8) mode;
    total = 0;
    for (i = 0; i < 5; i++) {
        player_state = kar_plclearcheckerlib__near_8022c858(i);
        if (player_state == 0 || (player_state == 1 && mode == 1)) {
            value = fn_8000B1EC(i);
            if (value > 0) {
                total += value;
            }
        }
    }

    total += global->clearchecker_total_0;
    return total;
}

s32 kar_gmclearchecker__near_8004acf4(void)
{
    s32 mode;
    GmGlobalData* global;
    s32 i;
    s32 total;
    s32 player_state;

    mode = kar_gmracenormal__8003d5f0();
    global = kar_gmglobal__near_8000771c();
    mode = (s8) mode;
    total = 0;
    for (i = 0; i < 5; i++) {
        player_state = kar_plclearcheckerlib__near_8022c858(i);
        if (player_state == 0 || (player_state == 1 && mode == 1)) {
            total += kar_plclearcheckerlib__8023156c(i);
        }
    }

    total += global->clearchecker_total_1;
    return total;
}

s32 kar_gmclearchecker__near_8004ae50(void)
{
    s32 mode;
    GmGlobalData* global;
    s32 i;
    s32 total;
    s32 player_state;

    mode = kar_gmracenormal__8003d5f0();
    global = kar_gmglobal__near_8000771c();
    mode = (s8) mode;
    total = 0;
    for (i = 0; i < 5; i++) {
        player_state = kar_plclearcheckerlib__near_8022c858(i);
        if (player_state == 0 || (player_state == 1 && mode == 1)) {
            total += kar_plclearcheckerlib__8022eb88(i);
            total += kar_plclearcheckerlib__802306d4(i);
        }
    }

    total += global->clearchecker_total_2;
    return total;
}

s32 kar_gmclearchecker__near_8004b1d0(void)
{
    GmGlobalData* global;
    s32 i;
    s32 total;

    global = kar_gmglobal__near_8000771c();
    total = global->clearchecker_total_3;
    for (i = 0; i < 5; i++) {
        if (kar_plclearcheckerlib__near_8022c858(i) == 0) {
            if ((s8) fn_8000979C(i) != 0) {
                total++;
            }
        }
    }

    return total;
}

s32 kar_gmclearchecker__near_8004b23c(void)
{
    GmGlobalData* global;
    s32 total;
    s32 i;

    global = kar_gmglobal__near_8000771c();
    total = global->clearchecker_total_3;
    for (i = 0; i < 5; i++) {
        if (kar_plclearcheckerlib__near_8022c858(i) == 0) {
            if ((s8) fn_8000979C(i) != 0) {
                total++;
            }
        }
    }

    total = total >= 3;
    return total;
}

s32 kar_gmclearchecker__near_8004b2b8(void)
{
    s32 mode;
    GmGlobalData* global;
    s32 total;
    s32 i;
    s32 player_state;

    mode = kar_gmracenormal__8003d5f0();
    global = kar_gmglobal__near_8000771c();
    mode = (s8) mode;
    total = 0;
    for (i = 0; i < 5; i++) {
        player_state = kar_plclearcheckerlib__near_8022c858(i);
        if (player_state == 0 || (player_state == 1 && mode == 1)) {
            total += kar_plclearcheckerlib__802306d4(i);
        }
    }

    total += global->clearchecker_total_4;
    return total;
}

s32 kar_gmclearchecker__near_8004b404(void)
{
    s32 mode;
    GmGlobalData* global;
    s32 total;
    s32 i;
    s32 player_state;

    mode = kar_gmracenormal__8003d5f0();
    global = kar_gmglobal__near_8000771c();
    mode = (s8) mode;
    total = 0;
    for (i = 0; i < 5; i++) {
        player_state = kar_plclearcheckerlib__near_8022c858(i);
        if (player_state == 0 || (player_state == 1 && mode == 1)) {
            total += kar_plclearcheckerlib__8022eb10(i, 0xF);
            total += kar_plclearcheckerlib__8022eb10(i, 0x15);
        }
    }

    total += global->clearchecker_total_5;
    return total;
}

s32 kar_gmclearchecker__near_8004b814(void)
{
    s32 mode;
    GmGlobalData* global;
    s32 total;
    s32 i;
    s32 player_state;

    mode = kar_gmracenormal__8003d5f0();
    global = kar_gmglobal__near_8000771c();
    mode = (s8) mode;
    total = 0;
    for (i = 0; i < 5; i++) {
        player_state = kar_plclearcheckerlib__near_8022c858(i);
        if (player_state == 0 || (player_state == 1 && mode == 1)) {
            total += kar_plclearcheckerlib__8022eb10(i, 0x10);
        }
    }

    total += global->clearchecker_total_6;
    return total;
}

s32 kar_gmclearchecker__near_8004b968(void)
{
    s32 mode;
    GmGlobalData* global;
    s32 total;
    s32 i;
    s32 player_state;

    mode = kar_gmracenormal__8003d5f0();
    global = kar_gmglobal__near_8000771c();
    mode = (s8) mode;
    total = 0;
    for (i = 0; i < 5; i++) {
        player_state = kar_plclearcheckerlib__near_8022c858(i);
        if (player_state == 0 || (player_state == 1 && mode == 1)) {
            total += kar_plclearcheckerlib__8022ea98(i, 0x10);
        }
    }

    total += global->clearchecker_total_7;
    return total;
}

s32 kar_gmclearchecker__near_8004bb1c(void)
{
    GmGlobalData* global;
    s32 total;
    s32 bit;

    global = kar_gmglobal__near_8000771c();
    total = global->clearchecker_total_8;
    bit = 1 << fn_80261CE8((s8) fn_800092D8());
    total |= bit;
    return total;
}
