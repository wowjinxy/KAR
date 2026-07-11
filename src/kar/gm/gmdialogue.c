#include "functions.h"
#include <dolphin/types.h>
#include <kar/gm/gmclearchecker.h>
#include <kar/gm/gmdialogue.h>
#include <kar/gm/gmdialoguestatus.h>
#include <kar/gm/gmmain.h>
#include <kar/gm/gmracenormal.h>
#include <kar/lb/lbhvqm.h>
#include <kar/shadow.h>

char kar_src_gmdialogue_80496f38[] = "gmdialogue.c";
char lbl_80497118[] =
    "======================================================\n\0"
    "[GmDialogue] Critical Error Please Report to Narita\n\0\0\0\0"
    "[GmDialogue] gmDialogueGCP2Status Result: %d\n\0\0\0"
    "[GmDialogue] gmDialogueGCP2Status out of switch, Result: %d\n\0\0\0";
char kar_src_gmdialoguesub_80497280[] = "gmdialoguesub.c";
char lbl_805D51B0[] = "0";
char lbl_805D51B8[] = "0";

void* kar_gmmain__near_80006c14(void);
void* kar_gmmain__near_80006eec(void);
void kar_gmlanmenu__80008220(void);
void kar_gmlanmenu__800082a0(s32 arg0);
void kar_gmviconfigure__near_8004f5e0(s32 arg0);
void kar_gmglobal__near_80007640(void);
void kar_gmglobal__near_80007808(void);
s32 kar_gmglobal__near_80007e8c(s32 arg0);
s32 kar_gmglobal__near_80007ee4(s32 arg0);
void kar_gmglobal__near_80007f6c(s32 arg0, s32 arg1);
s32 kar_gmglobal__near_80008038(s32 arg0);
void kar_gmglobal__near_800080c0(s32 arg0, s32 arg1);
void kar_gmautodemo__near_8000cd10(s32 arg0);
void* kar_gmautodemo__near_8000fcb0(void);
u64 kar_gmautodemo__near_8000ecf0(s32 arg0);
u64 kar_gmautodemo__near_8000ed10(s32 arg0);
void kar_gm_assets__asset_8000fc70(void);
void kar_movie_assets__8000a498(s32 arg0);
void kar_lbaudio__near_8005a474(void);
void kar_lbaudio__near_8005e1a8(s32 arg0);
void kar_lbaudio__near_80061620(void);
void kar_lbaudio__near_80061658(void);
void kar_lbaudio__near_80061734(void);
void kar_lbaudio__near_8006176c(s32 arg0);
void kar_lbkdcoll__near_800726f0(s32 arg0);
void kar_lbfile_queue_startup_resource_loads(void);
s32 kar_gmracenormal__8000ae50(void);
s32 kar_gmracenormal__800092fc(void);
s32 kar_vcgenerator__8000af38(void);
void fn_80018A04(void);
void fn_8000A444(s32 arg0);
s32 fn_8000A4EC(s32 arg0);
s32 fn_8000A570(void);
s32 fn_8000A5C4(void);
s32 fn_8000BA70(s32 arg0);
void fn_80045CA4(void);
void fn_80045E14(void);
void fn_80131848(void);
void fn_80131858(void);
void fn_801363BC(void);
void fn_801382D4(void);
void fn_80138324(s32 arg0, s32 arg1);
void fn_80138404(s32 arg0, s32 arg1);
void fn_80138448(void);
void fn_8013846C(void);
void fn_80138490(void);
void fn_801384C8(void);
void fn_801385D4(void);
void fn_801386B8(void);
void fn_8013876C(void);
void fn_80138E68(void);
void fn_80138EF4(void);
void fn_80138F1C(void);
void fn_80138FAC(void);
void fn_80139034(void);
void fn_80139058(void);
void fn_80139078(void);
void fn_80261CE8(s32 arg0);
void kar_mndialoguebg_request_cursor_slot_open_anim(s32 arg0);
void kar_mndialoguebg_request_cursor_slot_closed_anim(s32 arg0);
void kar_mndialoguebg_show_cursor_slot(s32 arg0);
void kar_mndialoguebg_hide_cursor_slot(s32 arg0);
void kar_mndialoguebg_set_sis_dialogue_box0_message_id(s32 arg0);
void kar_mndialoguebg_set_sis_dialogue_box1_message_id(s32 arg0);
void kar_mndialoguebg_set_sis_dialogue_box2_message_id(s32 arg0);
void kar_mnclearchecker_destroy_progressive_text_windows(void);
void kar_mnclearchecker_request_progressive_complete_panel_anim0(void);
void kar_mnclearchecker_request_progressive_complete_panel_anim1(void);
void kar_mnclearchecker_show_progressive_message5_after_panel_anim(void);
void kar_mnclearchecker_show_progressive_message6_after_panel_anim(void);
void kar_pltrick__near_802322a0(void* arg0, s32 arg1, s32 arg2);
void kar_pltrick__near_802322b0(void* arg0, s32 arg1, s32 arg2);
void kar_pltrick__near_802322d8(void* arg0);
void kar_pltrick__near_80232500(void* arg0);
void kar_lbaudio__near_8005e5d0(void);
void kar_lbaudio__near_8005e788(void);
void kar_mnclearchecker_create_progressive_text_windows(void);
void fn_80138F44(void);
void kar_osthread__near_803d9724(s32 arg0);
void* memset(void* dst, int val, unsigned long n);

extern s32 lbl_805DD540;
extern s32 lbl_805DD630;
extern u8 lbl_80496F20[];

typedef struct GmDialoguePlayerInit {
    s8 field_0;
    s8 field_1;
    s8 field_2;
    s8 field_3;
    u8 pad_4[0x2C];
} GmDialoguePlayerInit;

typedef struct GmDialogueInput {
    u32 raw_buttons;
    u8 pad_4[4];
    u32 buttons;
    u8 pad_C[0x38];
} GmDialogueInput;

typedef struct GmDialogueEntry {
    s8 id;
    u8 pad_1[3];
    s32 field_4;
    s32 field_8;
} GmDialogueEntry;

extern GmDialogueInput HSD_PadCopyStatus[];

#define REPORT_STATUS_ERROR(status, fmt)                                      \
    do {                                                                      \
        OSReport(&lbl_80497118[0]);                                           \
        OSReport(&lbl_80497118[0x38]);                                        \
        OSReport((fmt), (status));                                            \
        OSReport(&lbl_80497118[0]);                                           \
    } while (0)

#define MAP_GCP_STATUS(out_state, status)                                     \
    do {                                                                      \
        switch (status) {                                                     \
        case 1:                                                               \
        case 4:                                                               \
        case 11:                                                              \
        case 16:                                                              \
            REPORT_STATUS_ERROR(                                              \
                status, &lbl_80497118[0x70]);                                 \
            (out_state) = 0x10;                                               \
            break;                                                            \
        case 0:                                                               \
            (out_state) = 0;                                                  \
            break;                                                            \
        case 3:                                                               \
            (out_state) = 0x17;                                               \
            break;                                                            \
        case 2:                                                               \
        case 5:                                                               \
            (out_state) = 1;                                                  \
            break;                                                            \
        case 6:                                                               \
            (out_state) = 4;                                                  \
            break;                                                            \
        case 7:                                                               \
            (out_state) = 8;                                                  \
            break;                                                            \
        case 8:                                                               \
            (out_state) = 9;                                                  \
            break;                                                            \
        case 9:                                                               \
        case 10:                                                              \
            (out_state) = 0xA;                                                \
            break;                                                            \
        case 12:                                                              \
            (out_state) = 0xF;                                                \
            break;                                                            \
        case 13:                                                              \
            (out_state) = 0x10;                                               \
            break;                                                            \
        case 14:                                                              \
            (out_state) = 0x11;                                               \
            break;                                                            \
        case 15:                                                              \
            (out_state) = 0x15;                                               \
            break;                                                            \
        default:                                                              \
            REPORT_STATUS_ERROR(                                              \
                status, &lbl_80497118[0xA0]);                                 \
            (out_state) = 0x10;                                               \
            break;                                                            \
        }                                                                     \
    } while (0)

#define REPORT_STATUS_ERROR_MSG(status, fmt, msg)                             \
    do {                                                                      \
        OSReport(&(msg)[0]);                                                  \
        OSReport(&(msg)[0x38]);                                               \
        OSReport((fmt), (status));                                            \
        OSReport(&(msg)[0]);                                                  \
    } while (0)

#define MAP_GCP_STATUS_MSG(out_state, status, msg)                            \
    do {                                                                      \
        switch (status) {                                                     \
        case 1:                                                               \
        case 4:                                                               \
        case 11:                                                              \
        case 16:                                                              \
            REPORT_STATUS_ERROR_MSG(                                          \
                status, &(msg)[0x70], msg);                                   \
            (out_state) = 0x10;                                               \
            break;                                                            \
        case 0:                                                               \
            (out_state) = 0;                                                  \
            break;                                                            \
        case 3:                                                               \
            (out_state) = 0x17;                                               \
            break;                                                            \
        case 2:                                                               \
        case 5:                                                               \
            (out_state) = 1;                                                  \
            break;                                                            \
        case 6:                                                               \
            (out_state) = 4;                                                  \
            break;                                                            \
        case 7:                                                               \
            (out_state) = 8;                                                  \
            break;                                                            \
        case 8:                                                               \
            (out_state) = 9;                                                  \
            break;                                                            \
        case 9:                                                               \
        case 10:                                                              \
            (out_state) = 0xA;                                                \
            break;                                                            \
        case 12:                                                              \
            (out_state) = 0xF;                                                \
            break;                                                            \
        case 13:                                                              \
            (out_state) = 0x10;                                               \
            break;                                                            \
        case 14:                                                              \
            (out_state) = 0x11;                                               \
            break;                                                            \
        case 15:                                                              \
            (out_state) = 0x15;                                               \
            break;                                                            \
        default:                                                              \
            REPORT_STATUS_ERROR_MSG(                                          \
                status, &(msg)[0xA0], msg);                                   \
            (out_state) = 0x10;                                               \
            break;                                                            \
        }                                                                     \
    } while (0)

void kar_gmdialogue__near_800460bc(void)
{
    u8 trick[0x40];
    register u8* data;
    register u8* gm;
    GmDialoguePlayerInit* player;
    s32 i;

    gm = kar_gmmain__near_80006c14();
    fn_801385D4();
    fn_801386B8();
    fn_80045E14();
    *(s32*) &gm[0x33C] = 0;
    kar_lbaudio__near_8005e1a8(0x3A);
    kar_gm_assets__asset_8000fc70();
    data = *(u8**) ((u8*) kar_gmautodemo__near_8000fcb0() + 8);
    kar_lbkdcoll__near_800726f0(
        (s8) data[((s8) kar_gmracenormal__8000ae50() * 6) + 1]);

    gm = kar_gmmain__near_80006c14();
    kar_pltrick__near_802322d8(trick);
    i = 0;
    player = (GmDialoguePlayerInit*) &gm[0xAC8];
    do {
        kar_pltrick__near_802322a0(trick, i, player->field_2);
        kar_pltrick__near_802322b0(trick, i, player->field_3);
        i++;
        player++;
    }
    while (i < 4);
    kar_pltrick__near_80232500(trick);
    kar_lbfile_queue_startup_resource_loads();
    fn_80261CE8((s8) kar_gmracenormal__800092fc());
    kar_lbaudio__near_8005a474();
}

void kar_gmdialogue__near_800461a0(void)
{
    kar_lbaudio__near_8005e5d0();
    fn_8013876C();
}

void kar_gmdialogue__near_800461c4(void)
{
    fn_80045CA4();
}

void kar_gmdialogue__near_800461e4(void)
{
    u8* gm;

    gm = kar_gmmain__near_80006c14();
    if ((s8) kar_vcgenerator__8000af38() == 0) {
        if ((s8) kar_gmglobal__near_80007ee4(
                    kar_gmracenormal__8000ae50()) == 0) {
            kar_gmglobal__near_80007f6c(kar_gmracenormal__8000ae50(), 1);
            kar_gmglobal__near_800080c0(kar_gmracenormal__8000ae50(), 1);
        }
    } else if ((s8) kar_vcgenerator__8000af38() == 1) {
        if ((s8) kar_gmglobal__near_80008038(
                    kar_gmracenormal__8000ae50()) != 0) {
            kar_gmglobal__near_800080c0(kar_gmracenormal__8000ae50(), 0);
        }
    }

    fn_801382D4();
    fn_8013846C();
    fn_80138324(0xA, 0);
    fn_80138404(kar_gmracenormal__8000ae50(), 0);
    kar_lbaudio__near_8006176c(0x130000);
    *(s32*) &gm[0x340] = 0x1E;
}

void kar_gmdialogue__near_800462a4(void)
{
    fn_801384C8();
    kar_lbaudio__near_8005e788();
}

void kar_gmdialogue__near_800462c8(void)
{
    u8* gm;
    s32 timer;
    s32 i;
    GmDialoguePlayerInit* player;

    gm = kar_gmmain__near_80006c14();
    timer = *(s32*) &gm[0x340];
    if (timer > 0) {
        if ((*(s32*) &gm[0x340] = timer - 1) <= 0) {
            *(s32*) &gm[0x340] = 0;
            if ((s8) fn_8000BA70(kar_gmracenormal__8000ae50()) != -1) {
                fn_80138490();
            }
        }
    }

    player = (GmDialoguePlayerInit*) ((u8*) kar_gmmain__near_80006c14() +
                                      0xAC8);
    gm = kar_gmmain__near_80006c14();
    if (fn_8000A4EC(0xA) != 1) {
        if ((u32) fn_8000A570() != 0xFFFFFFFFU) {
            if (fn_8000A5C4() == 1) {
                kar_movie_assets__8000a498(0x100);
                kar_gmmain__near_800064f0();
            }
        } else {
            for (i = 0; i < 4; i++, player++) {
                if (player->field_0 == 0 &&
                    (HSD_PadCopyStatus[(u8) i].buttons & 0x1360) != 0) {
                    kar_lbaudio__near_80061658();
                    if (*(s32*) &gm[0x340] > 0) {
                        *(s32*) &gm[0x340] = 0;
                        if ((s8) fn_8000BA70(kar_gmracenormal__8000ae50()) !=
                            -1) {
                            fn_80138490();
                        }
                    }
                    fn_8000A444(i);
                    fn_80138448();
                    kar_movie_assets__8000a498(0x100);
                    kar_gmmain__near_800064f0();
                }
            }
        }
    }
}

void* kar_gmdialogue__near_8004640c(void)
{
    return (u8*) kar_gmmain__near_80006c14() + 0x484;
}

void kar_gmdialogue__near_80046d48(void)
{
    u8* work;

    work = (u8*) kar_gmmain__near_80006c14() + 0x484;
    memset(work, 0, 0x128);
    work[0] = 0;
    work[2] = 0;
    work[3] = 0;
    work[4] = 0;
    work[1] = 0;
    work[6] = 0;
}

void kar_gmdialogue__near_80046da0(void)
{
    u8* gm;

    gm = kar_gmmain__near_80006c14();
    gm[0x485] = 1;
}

void kar_gmdialogue__near_80046dc8(void)
{
    u8* gm;

    gm = kar_gmmain__near_80006c14();
    gm[0x485] = 0;
}

void kar_gmdialogue__near_80046df0(void)
{
    register u8* work;
    u8* ptr;
    s32 count;
    s32 offset;
    register s32 i;
    u8* fallback;

    work = (u8*) kar_gmmain__near_80006c14() + 0x484;
    count = 0;
    offset = 0;

    if (lbl_805DD630 >= 3 && (HSD_PadCopyStatus[0].raw_buttons & 0x28) == 0x28) {
        for (i = 0; i < 0x18; i++) {
            if ((s8) kar_gmglobal__near_80007ee4((s8) i) == 0) {
                kar_gmglobal__near_80007f6c((s8) i, 1);
                kar_gmglobal__near_800080c0((s8) i, 1);
            }
        }
    }

    ptr = work;
    for (i = 0; i < 3; i++) {
        ptr[8] = -1;
        *(s32*) &ptr[0x10] = 0;
        *(s32*) &ptr[0x0C] = 0;
        ptr[0x14] = -1;
        *(s32*) &ptr[0x1C] = 0;
        *(s32*) &ptr[0x18] = 0;
        ptr[0x20] = -1;
        *(s32*) &ptr[0x28] = 0;
        *(s32*) &ptr[0x24] = 0;
        ptr[0x2C] = -1;
        *(s32*) &ptr[0x34] = 0;
        *(s32*) &ptr[0x30] = 0;
        ptr[0x38] = -1;
        *(s32*) &ptr[0x40] = 0;
        *(s32*) &ptr[0x3C] = 0;
        ptr[0x44] = -1;
        *(s32*) &ptr[0x4C] = 0;
        *(s32*) &ptr[0x48] = 0;
        ptr[0x50] = -1;
        *(s32*) &ptr[0x58] = 0;
        *(s32*) &ptr[0x54] = 0;
        ptr[0x5C] = -1;
        *(s32*) &ptr[0x64] = 0;
        *(s32*) &ptr[0x60] = 0;
        ptr += 0x60;
    }

    fallback = lbl_80496F20;
    for (i = 0; i < 0x18; i++, fallback++) {
        if ((s8) kar_gmglobal__near_80007ee4((s8) i) != 0) {
            if (i == (s8) work[6]) {
                work[4] = count;
            }
            ptr = &work[offset];
            ptr[8] = i;
            *(s32*) &ptr[0x0C] = 1;
            if ((s8) kar_gmglobal__near_80008038((s8) i) != 0) {
                *(s32*) &ptr[0x10] = 1;
            }
            count++;
            offset += sizeof(GmDialogueEntry);
        } else if ((s8) *fallback != -1) {
            if ((kar_shadow__near_8007b650() != 0 &&
                 (s8) kar_gmglobal__near_80007e8c(*fallback) != 0) ||
                (kar_shadow__near_8007b650() == 0 &&
                 ClearChecker_CheckUnlocked(2, *fallback) != 0)) {
                ptr = &work[offset];
                ptr[8] = i;
                *(s32*) &ptr[0x0C] = 1;
                *(s32*) &ptr[0x10] = 1;
                kar_gmglobal__near_80007f6c((s8) i, 1);
                kar_gmglobal__near_800080c0((s8) i, 1);
                count++;
                offset += sizeof(GmDialogueEntry);
            }
        }
    }
    work[5] = count;
}

void kar_gmdialogue__near_8004730c(void)
{
    kar_gmmain__near_80006c14();
    fn_801363BC();
}

void kar_gmdialogue__near_80047330(void)
{
    kar_gmdialogue__near_80046430();
}

s32 kar_gmdialogue__near_80047350(void)
{
    u8* gm;

    gm = kar_gmmain__near_80006c14();
    return (s8) gm[0xD4D] == 0;
}

void kar_gmdialogue__near_80047380(void)
{
    u8* gm;

    gm = kar_gmmain__near_80006c14();
    gm[0xD4A] = 0x1E;
    gm[0xD4C] = 0;
    gm[0xD4D] = 0;
    gm[0xD4B] = 2;
    *(u16*) &gm[0xD4E] = 0;
    fn_80138FAC();
    fn_80139058();
    fn_80139034();
    kar_mnclearchecker_create_progressive_text_windows();
}

void kar_gmdialogue__near_800473d0(void)
{
    fn_80139078();
}

void kar_gmdialogue__near_800473f0(void)
{
    u8* gm;
    u64 held;
    u64 pressed;
    s32 decision;

    gm = kar_gmmain__near_80006c14();
    switch ((s8) gm[0xD4D]) {
    case 0:
        gm = kar_gmmain__near_80006c14();
        if (fn_8000A4EC((s8) gm[0xD4A]) != 1) {
            held = kar_gmautodemo__near_8000ed10(0x14);
            pressed = kar_gmautodemo__near_8000ecf0(0x14);

            if ((s8) gm[0xD4C] != 2 && (held & 0xC0003) != 0) {
                *(u16*) &gm[0xD4E] = 0;
                kar_lbaudio__near_80061620();
                if ((s8) gm[0xD4C] == 0) {
                    gm[0xD4C] = 1;
                } else {
                    gm[0xD4C] = 0;
                }
            }

            gm[0xD4B] = 2;
            if ((pressed & 0x100) != 0) {
                kar_lbaudio__near_80061658();
                if ((s8) gm[0xD4C] == 1) {
                    gm[0xD4B] = 1;
                } else {
                    gm[0xD4B] = 0;
                }
            }
        }

        gm = kar_gmmain__near_80006c14();
        if ((s8) gm[0xD4D] == 0) {
            (*(u16*) &gm[0xD4E])++;
            if (*(u16*) &gm[0xD4E] == 0x258) {
                if ((s8) gm[0xD4C] == 1) {
                    gm[0xD4B] = 1;
                } else {
                    gm[0xD4B] = 0;
                }
            }
        }

        gm = kar_gmmain__near_80006c14();
        decision = gm[0xD4B];
        if ((s8) decision == 0) {
            gm = kar_gmmain__near_80006c14();
            gm[0xD4D] = 1;
        } else if ((s8) decision == 1) {
            kar_osthread__near_803d9724(0);
            gm = kar_gmmain__near_80006c14();
            gm[0xD4D] = 4;
        }
        break;
    case 1:
        gm = kar_gmmain__near_80006c14();
        kar_gmviconfigure__near_8004f5e0(2);
        kar_osthread__near_803d9724(1);
        *(u16*) &gm[0xD4E] = 0;
        gm = kar_gmmain__near_80006c14();
        gm[0xD4D] = 2;
        break;
    case 2:
        gm = kar_gmmain__near_80006c14();
        if ((*(u16*) &gm[0xD4E])++ == 0x96) {
            gm = kar_gmmain__near_80006c14();
            gm[0xD4D] = 3;
        }
        break;
    case 3:
    case 4:
        pressed = kar_gmautodemo__near_8000ecf0(0x14);
        if ((pressed & 0x100) != 0) {
            kar_lbaudio__near_80061658();
            kar_gmmain__near_800064f0();
            kar_gmlanmenu__80008220();
        }
        break;
    }

    gm = kar_gmmain__near_80006c14();
    fn_80131848();
    switch ((s8) gm[0xD4D]) {
    case 0:
        if ((s8) gm[0xD4C] == 0) {
            kar_mnclearchecker_request_progressive_complete_panel_anim0();
        } else {
            kar_mnclearchecker_request_progressive_complete_panel_anim1();
        }
        break;
    case 1:
    case 2:
        fn_80131858();
        kar_mnclearchecker_destroy_progressive_text_windows();
        break;
    case 3:
        kar_mnclearchecker_show_progressive_message5_after_panel_anim();
        break;
    case 4:
        kar_mnclearchecker_show_progressive_message6_after_panel_anim();
        break;
    }
}

void kar_gmdialogue__near_800476b8(void)
{
    s32 status;

    status = -1;
    if (lbl_805DD540 == 0) {
        status = kar_lbhvqm__near_80079108();
    } else {
        if (kar_lbhvqm__near_8007865c() == 0 &&
            kar_lbhvqm__near_80078e30() == 0) {
            status = kar_lbhvqm__near_80079108();
        }
        kar_lbhvqm__near_80078cb0(0);
    }

    if (status != 1) {
        kar_gmmain__near_80006eec();
    } else {
        kar_gmglobal__near_80007640();
        switch (lbl_805DD540) {
        case 0:
            kar_gmautodemo__near_8000cd10(0);
            kar_gmlanmenu__800082a0(2);
            break;
        case 1:
            kar_gmautodemo__near_8000cd10(1);
            kar_gmlanmenu__800082a0(2);
            break;
        case 2:
            kar_gmglobal__near_80007808();
            fn_80018A04();
            kar_gmlanmenu__800082a0(3);
            break;
        default:
            kar_gmautodemo__near_8000cd10(0);
            kar_gmlanmenu__800082a0(2);
            break;
        }
        kar_gmlanmenu__80008220();
    }
}

void kar_gmdialogue__near_800477ac(void)
{
    kar_lbhvqm__near_80078cd0(1);
    switch (lbl_805DD540) {
    case 0:
        kar_gmautodemo__near_8000cd10(0);
        kar_gmlanmenu__800082a0(2);
        break;
    case 1:
        kar_gmautodemo__near_8000cd10(1);
        kar_gmlanmenu__800082a0(2);
        break;
    case 2:
        kar_gmglobal__near_80007808();
        fn_80018A04();
        kar_gmlanmenu__800082a0(3);
        break;
    default:
        kar_gmautodemo__near_8000cd10(0);
        kar_gmlanmenu__800082a0(2);
        break;
    }
}

#pragma push
#pragma dont_inline on
GmDialogueWork* kar_diagnostic__80047844(void)
{
    return kar_gmmain__near_80006c14();
}
#pragma pop

#pragma push
#pragma dont_inline on
void kar_gmdialogue__near_80047864(void)
{
    GmDialogueWork* work;

    work = kar_gmmain__near_80006c14();
    work->force_save_dialogue = 1;
}
#pragma pop

void kar_gmdialogue__8004788c(s32 state)
{
    GmDialogueWork* work;

    work = kar_gmmain__near_80006c14();
    if (((GmDialogueWork*) kar_gmmain__near_80006c14())->force_save_dialogue !=
            0 &&
        state == 0xA) {
        state = 0x10;
    }

    work->state = state;

    switch (work->state) {
    case 0:
        kar_gmdialoguesub__near_80048b10();
        break;
    case 1:
        kar_gmdialoguesub__near_80048b78();
        break;
    case 2:
        kar_gmdialoguesub__near_80048bac();
        break;
    case 3:
        kar_gmdialoguesub__near_80048be4();
        break;
    case 4:
        kar_gmdialoguestatus__near_80048c2c();
        break;
    case 5:
        kar_gmdialoguestatus__near_80048c64();
        break;
    case 6:
        kar_gmdialoguestatus__near_80048c9c();
        break;
    case 7:
        kar_gmdialoguestatus__near_80048cd4();
        break;
    case 8:
        kar_gmdialoguestatus__near_80048d1c();
        break;
    case 9:
        kar_gmdialoguestatus__near_80048d54();
        break;
    case 10:
        kar_gmdialoguestatus__near_80048d8c();
        break;
    case 11:
        kar_gmdialoguestatus__near_80048dc0();
        break;
    case 12:
        kar_gmdialoguestatus__near_80048df8();
        break;
    case 13:
        kar_gmdialoguestatus__near_80048e30();
        break;
    case 14:
        kar_gmdialoguestatus__near_80048e78();
        break;
    case 15:
        kar_gmdialoguestatus__near_80048eb0();
        break;
    case 16:
        kar_gmdialoguestatus__near_80048ee8();
        break;
    case 17:
        kar_gmdialoguestatus__near_80048f30();
        break;
    case 18:
        kar_gmdialoguestatus__80048f68();
        break;
    case 19:
        kar_gmdialoguestatus__near_80048f98();
        break;
    case 20:
        kar_gmdialoguestatus__near_80048fd0();
        break;
    case 21:
        kar_gmdialoguestatus__near_80049008();
        break;
    case 22:
        kar_gmdialoguestatus__80049040();
        break;
    case 23:
        kar_gmdialoguestatus__near_80049070();
        break;
    case 24:
        kar_gmdialoguestatus__near_800490a8();
        break;
    case 25:
        kar_gmdialoguestatus__near_800490d0();
        break;
    case 26:
        kar_gmdialoguestatus__near_800490f8();
        break;
    case 27:
        kar_gmdialoguestatus__near_80049120();
        break;
    case 28:
        kar_gmdialoguestatus__near_80049140();
        break;
    default:
        __assert(kar_src_gmdialogue_80496f38, 0xC5, lbl_805D51B0);
        break;
    }
}

void kar_gmdialogue__80047a08(void)
{
    GmDialogueWork* work;

    work = kar_gmmain__near_80006c14();
    switch (work->state) {
    case 0:
        kar_diag__800481dc();
        break;
    case 1:
        kar_gmdialoguesub__near_80048370();
        break;
    case 2:
        kar_gmdialoguesub__near_800483c0();
        break;
    case 3:
        kar_gmdialoguesub__near_8004840c();
        break;
    case 4:
        kar_gmdialoguesub__near_80048440();
        break;
    case 5:
        kar_gmdialoguesub__near_80048490();
        break;
    case 6:
        kar_gmdialoguesub__near_800484d8();
        break;
    case 7:
        kar_gmdialoguesub__near_80048514();
        break;
    case 8:
        kar_gmdialoguesub__near_80048548();
        break;
    case 9:
        kar_gmdialoguesub__near_8004857c();
        break;
    case 10:
        kar_gmdialoguesub__near_800485b0();
        break;
    case 11:
        kar_gmdialoguesub__near_80048600();
        break;
    case 12:
        kar_gmdialoguesub__near_80048644();
        break;
    case 13:
        kar_gmdialoguesub__near_80048678();
        break;
    case 14:
        kar_gmdialoguesub__near_800486ac();
        break;
    case 15:
        kar_gmdialoguesub__near_800486e0();
        break;
    case 16:
        kar_gmdialoguesub__near_80048714();
        break;
    case 17:
        kar_gmdialoguesub__near_80048748();
        break;
    case 18:
        kar_gmdialoguesub__8004877c();
        break;
    case 19:
        kar_gmdialoguesub__near_800487ac();
        break;
    case 20:
        kar_gmdialoguesub__near_80048800();
        break;
    case 21:
        kar_gmdialoguesub__near_80048854();
        break;
    case 22:
        kar_gmdialoguesub__80048888();
        break;
    case 23:
        kar_gmdialoguesub__near_800488b8();
        break;
    case 24:
        kar_diag__800488ec();
        break;
    case 25:
        kar_gmdialoguesub__near_80048a24();
        break;
    case 26:
        kar_gmdialoguesub__near_80048a70();
        break;
    case 27:
        kar_gmdialoguesub__near_80048a98();
        break;
    case 28:
        kar_gmdialoguesub__near_80048ad4();
        break;
    default:
        __assert(kar_src_gmdialogue_80496f38, 0x122, lbl_805D51B0);
        break;
    }
}

void kar_gmdialogue__near_80047b4c(void)
{
    GmDialogueWork* work;
    u64 held;
    u64 pressed;
    s32 play_sound;

    work = kar_gmmain__near_80006c14();
    if (fn_8000A4EC(work->field_0) == 1) {
        return;
    }

    held = kar_gmautodemo__near_8000ed10(0x14);
    pressed = kar_gmautodemo__near_8000ecf0(0x14);

    if (work->field_1 != 2 && (held & 0xC0003) != 0) {
        if (((GmDialogueWork*) kar_gmmain__near_80006c14())->field_6 != 0) {
            kar_lbaudio__near_80061620();
        }
        if (work->field_1 == 0) {
            work->field_1 = 1;
        } else {
            work->field_1 = 0;
        }
    }

    if (lbl_805DD630 >= 3 && (held & 0x400) != 0) {
        work->field_2++;
        if (work->field_2 > 0x20) {
            work->field_2 = 0;
        }
    }

    work->result = 2;
    if ((pressed & 0x1100) == 0) {
        return;
    }

    if (work->field_1 == 1) {
        if (work->field_6 != 0 &&
            ((GmDialogueWork*) kar_gmmain__near_80006c14())
                    ->force_save_dialogue != 0) {
            kar_lbaudio__near_80061734();
            kar_gmdialogue__8004788c(0x10);
            return;
        }

        switch (((GmDialogueWork*) kar_gmmain__near_80006c14())->state) {
        case 2:
        case 5:
        case 11:
        case 24:
        case 25:
        case 26:
        case 28:
            play_sound = 0;
            break;
        default:
            play_sound = 1;
            break;
        }
        if (play_sound != 0) {
            kar_lbaudio__near_80061658();
        }
        work->result = 1;
    } else {
        switch (((GmDialogueWork*) kar_gmmain__near_80006c14())->state) {
        case 2:
        case 5:
        case 11:
        case 24:
        case 25:
        case 26:
        case 28:
            play_sound = 0;
            break;
        default:
            play_sound = 1;
            break;
        }
        if (play_sound != 0) {
            kar_lbaudio__near_80061658();
        }
        work->result = 0;
    }
}

void kar_gmdialogue__near_80047d60(void)
{
    GmDialogueWork* work;

    kar_gmmain__near_80006c14();
    work = kar_gmmain__near_80006c14();
    memset(work, 0, 0xC);
    work->field_0 = 0x1E;
    work->field_1 = 2;
    work->field_2 = 0;
    work->field_3 = 3;
    work->field_4 = 4;
    work->state = 0x1A;
    work->field_6 = 0;
    work->result = 2;
    work->field_8 = 0x11;
    work->field_9 = 8;
    work->field_A = 0xA;
    work->force_save_dialogue = 0;

    fn_80138E68();
    fn_80138EF4();
    fn_80138F1C();
    kar_mndialoguebg_request_cursor_slot_closed_anim(0);
    kar_mndialoguebg_request_cursor_slot_closed_anim(1);

    if (kar_lbhvqm__near_80078e4c() == 0xD) {
        kar_lbhvqm__near_800786f8();
        kar_gmdialogue__8004788c(0x10);
    }

    work = kar_gmmain__near_80006c14();
    if (work->field_1 != 2) {
        if (work->field_1 == 0) {
            kar_mndialoguebg_request_cursor_slot_open_anim(0);
            kar_mndialoguebg_request_cursor_slot_closed_anim(1);
        } else {
            kar_mndialoguebg_request_cursor_slot_open_anim(1);
            kar_mndialoguebg_request_cursor_slot_closed_anim(0);
        }
    }

    switch (work->field_6) {
    case 0:
        work->field_3 = 7;
        work->field_4 = 7;
        kar_mndialoguebg_show_cursor_slot(1);
        kar_mndialoguebg_show_cursor_slot(0);
        break;
    case 1:
        work->field_3 = 3;
        work->field_4 = 4;
        kar_mndialoguebg_hide_cursor_slot(1);
        kar_mndialoguebg_hide_cursor_slot(0);
        break;
    case 2:
        work->field_3 = 2;
        work->field_4 = 5;
        kar_mndialoguebg_hide_cursor_slot(1);
        kar_mndialoguebg_hide_cursor_slot(0);
        break;
    }

    kar_mndialoguebg_set_sis_dialogue_box0_message_id((u8) work->field_2);
    kar_mndialoguebg_set_sis_dialogue_box1_message_id((u8) work->field_3);
    kar_mndialoguebg_set_sis_dialogue_box2_message_id((u8) work->field_4);
}

void kar_gmdialogue__near_80047f0c(void)
{
    kar_lbhvqm__near_80078e5c();
    fn_80138F44();
}

void kar_gmdialogue__near_80047f30(void)
{
    GmDialogueWork* work;
    s32 play_movie;

    kar_gmdialogue__near_80047b4c();
    kar_gmdialogue__80047a08();
    if (kar_lbhvqm__near_800786d4(kar_gmmain__near_80006c14()) != 0) {
        kar_lbhvqm__near_800786f8();
        work = kar_gmmain__near_80006c14();
        work->force_save_dialogue = 0;
        work = kar_gmmain__near_80006c14();
        switch (work->state) {
        case 3:
        case 7:
        case 13:
            play_movie = 1;
            break;
        default:
            play_movie = 0;
            break;
        }
        if (play_movie != 0) {
            kar_lbhvqm__near_80078720();
        } else {
            kar_gmdialogue__8004788c(0x1A);
        }
    }

    work = kar_gmmain__near_80006c14();
    if (work->field_1 != 2) {
        if (work->field_1 == 0) {
            kar_mndialoguebg_request_cursor_slot_open_anim(0);
            kar_mndialoguebg_request_cursor_slot_closed_anim(1);
        } else {
            kar_mndialoguebg_request_cursor_slot_open_anim(1);
            kar_mndialoguebg_request_cursor_slot_closed_anim(0);
        }
    }

    switch (work->field_6) {
    case 0:
        work->field_3 = 7;
        work->field_4 = 7;
        kar_mndialoguebg_show_cursor_slot(1);
        kar_mndialoguebg_show_cursor_slot(0);
        break;
    case 1:
        work->field_3 = 3;
        work->field_4 = 4;
        kar_mndialoguebg_hide_cursor_slot(1);
        kar_mndialoguebg_hide_cursor_slot(0);
        break;
    case 2:
        work->field_3 = 2;
        work->field_4 = 5;
        kar_mndialoguebg_hide_cursor_slot(1);
        kar_mndialoguebg_hide_cursor_slot(0);
        break;
    }

    kar_mndialoguebg_set_sis_dialogue_box0_message_id((u8) work->field_2);
    kar_mndialoguebg_set_sis_dialogue_box1_message_id((u8) work->field_3);
    kar_mndialoguebg_set_sis_dialogue_box2_message_id((u8) work->field_4);
}

s32 kar_diag__800480b8(s32 status)
{
    char* msg;
    s32 saved_status;

    saved_status = status;
    msg = lbl_80497118;
    switch (saved_status) {
    case 1:
    case 4:
    case 11:
    case 16:
        OSReport(&msg[0]);
        OSReport(&msg[0x38]);
        OSReport(&msg[0x70], saved_status);
        OSReport(&msg[0]);
        return 0x10;
    case 0:
        return 0;
    case 3:
        return 0x17;
    case 2:
    case 5:
        return 1;
    case 6:
        return 4;
    case 7:
        return 8;
    case 8:
        return 9;
    case 9:
    case 10:
        return 0xA;
    case 12:
        return 0xF;
    case 13:
        return 0x10;
    case 14:
        return 0x11;
    case 15:
        return 0x15;
    default:
        OSReport(&msg[0]);
        OSReport(&msg[0x38]);
        OSReport(&msg[0xA0], saved_status);
        OSReport(&msg[0]);
        return 0x10;
    }
}

void kar_diag__800481dc(void)
{
    char* msg;
    register s32 status;
    GmDialogueWork* work;

    msg = lbl_80497118;
    work = kar_diagnostic__80047844();
    if (work->result == 0) {
        if (kar_lbhvqm__near_80078cc0() != 0) {
            kar_lbhvqm__near_80078e40(0);
            kar_lbhvqm__near_80078990();
            kar_gmdialogue__8004788c(0x1C);
        } else if (kar_lbhvqm__near_8007901c() != 0) {
            kar_gmdialogue__8004788c(0x1C);
        } else {
            status = kar_lbhvqm__near_80078ce0(kar_gmmain__near_80006eec());
            MAP_GCP_STATUS_MSG(status, status, msg);
            kar_gmdialogue__8004788c(status);
        }
    } else if (work->result == 1) {
        kar_gmdialogue__8004788c(0x1B);
    }
}

void kar_gmdialoguesub__near_80048370(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    if (work->result == 0) {
        kar_lbhvqm__near_80078c3c();
        kar_gmdialogue__8004788c(2);
    } else if (work->result == 1) {
        kar_gmdialogue__8004788c(0x1B);
    }
}

void kar_gmdialoguesub__near_800483c0(void)
{
    s32 status;

    kar_diagnostic__80047844();
    status = kar_lbhvqm__near_8007863c();
    if (status != 0xB) {
        if (status == 0) {
            kar_lbhvqm__near_8007875c();
            kar_gmdialogue__8004788c(5);
        } else {
            kar_gmdialogue__8004788c(3);
        }
    }
}

void kar_gmdialoguesub__near_8004840c(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    if (work->result != 2) {
        kar_gmdialogue__8004788c(0x1A);
    }
}

void kar_gmdialoguesub__near_80048440(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    if (work->result == 0) {
        kar_lbhvqm__near_8007875c();
        kar_gmdialogue__8004788c(5);
    } else if (work->result == 1) {
        kar_gmdialogue__8004788c(0x1B);
    }
}

void kar_gmdialoguesub__near_80048490(void)
{
    s32 status;

    kar_diagnostic__80047844();
    status = kar_lbhvqm__near_8007863c();
    if (status != 0xB) {
        if (status == 0) {
            kar_gmdialogue__8004788c(6);
        } else {
            kar_gmdialogue__8004788c(7);
        }
    }
}

void kar_gmdialoguesub__near_800484d8(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    if (work->result != 2) {
        kar_lbhvqm__near_80078e40(0);
        kar_gmdialogue__8004788c(0x1C);
    }
}

void kar_gmdialoguesub__near_80048514(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    if (work->result != 2) {
        kar_gmdialogue__8004788c(0x1A);
    }
}

void kar_gmdialoguesub__near_80048548(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    if (work->result != 2) {
        kar_gmdialogue__8004788c(0x1B);
    }
}

void kar_gmdialoguesub__near_8004857c(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    if (work->result != 2) {
        kar_gmdialogue__8004788c(0x1B);
    }
}

void kar_gmdialoguesub__near_800485b0(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    if (work->result == 0) {
        kar_lbhvqm__near_80078c7c();
        kar_gmdialogue__8004788c(0xB);
    } else if (work->result == 1) {
        kar_gmdialogue__8004788c(0x1B);
    }
}

void kar_gmdialoguesub__near_80048600(void)
{
    s32 status;

    status = kar_lbhvqm__near_8007863c();
    if (status != 0xB) {
        if (status == 0) {
            kar_gmdialogue__8004788c(0xC);
        } else {
            kar_gmdialogue__8004788c(0xD);
        }
    }
}

void kar_gmdialoguesub__near_80048644(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    if (work->result != 2) {
        kar_gmdialogue__8004788c(4);
    }
}

void kar_gmdialoguesub__near_80048678(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    if (work->result != 2) {
        kar_gmdialogue__8004788c(0x1A);
    }
}

void kar_gmdialoguesub__near_800486ac(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    if (work->result != 2) {
        kar_gmdialogue__8004788c(0x1B);
    }
}

void kar_gmdialoguesub__near_800486e0(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    if (work->result != 2) {
        kar_gmdialogue__8004788c(0x1B);
    }
}

void kar_gmdialoguesub__near_80048714(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    if (work->result != 2) {
        kar_gmdialogue__8004788c(0x1B);
    }
}

void kar_gmdialoguesub__near_80048748(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    if (work->result != 2) {
        kar_gmdialogue__8004788c(0x1B);
    }
}

void kar_gmdialoguesub__8004877c(void)
{
    __assert(kar_src_gmdialoguesub_80497280, 0x1E2, lbl_805D51B8);
}

void kar_gmdialoguesub__near_800487ac(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    if (work->result == 0) {
        kar_lbhvqm__near_80078e40(4);
        kar_gmdialogue__8004788c(0x1C);
    } else if (work->result == 1) {
        kar_gmdialogue__8004788c(0x1A);
    }
}

void kar_gmdialoguesub__near_80048800(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    if (work->result == 0) {
        kar_lbhvqm__near_80078e40(4);
        kar_gmdialogue__8004788c(0x1C);
    } else if (work->result == 1) {
        kar_gmdialogue__8004788c(0x1A);
    }
}

void kar_gmdialoguesub__near_80048854(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    if (work->result != 2) {
        kar_gmdialogue__8004788c(0x1B);
    }
}

void kar_gmdialoguesub__80048888(void)
{
    __assert(kar_src_gmdialoguesub_80497280, 0x224, lbl_805D51B8);
}

void kar_gmdialoguesub__near_800488b8(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    if (work->result != 2) {
        kar_gmdialogue__8004788c(0);
    }
}

void kar_diag__800488ec(void)
{
    char* msg;
    register s32 status;

    msg = lbl_80497118;
    kar_diagnostic__80047844();
    status = kar_lbhvqm__near_8007863c();
    if (status != 0xB) {
        MAP_GCP_STATUS_MSG(status, status, msg);
        kar_gmdialogue__8004788c(status);
    }
}

void kar_gmdialoguesub__near_80048a24(void)
{
    s32 status;

    status = kar_lbhvqm__near_8007863c();
    if (status != 0xB) {
        if (status == 0 || status == 3) {
            kar_gmdialogue__8004788c(0x1C);
        } else {
            kar_gmdialogue__8004788c(0x1A);
        }
    }
}

void kar_gmdialoguesub__near_80048a70(void)
{
    kar_lbhvqm__near_80078720();
    kar_gmdialogue__8004788c(0x18);
}

void kar_gmdialoguesub__near_80048a98(void)
{
    if (kar_lbhvqm__near_80078cc0() != 0) {
        kar_gmdialogue__8004788c(0x13);
    } else {
        kar_gmdialogue__8004788c(0x14);
    }
}

void kar_gmdialoguesub__near_80048ad4(void)
{
    if (kar_gmracenormal__8000aea8() == 0x12) {
        kar_gmmain__near_800064f0();
        kar_gmlanmenu__80008220();
    } else {
        kar_gmmain__near_800064f0();
    }
}

void kar_gmdialoguesub__near_80048b10(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    if (kar_lbhvqm__near_80078cc0() != 0) {
        work->field_1 = 1;
        work->field_2 = 8;
        work->field_6 = 1;
    } else {
        work->field_1 = 0;
        work->field_2 = 9;
        work->field_6 = 1;
    }
}

void kar_gmdialoguesub__near_80048b78(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    work->field_1 = 1;
    work->field_2 = 0xA;
    work->field_6 = 1;
}

void kar_gmdialoguesub__near_80048bac(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    work->field_1 = 1;
    work->field_2 = 0xB;
    work->field_6 = 0;
}

void kar_gmdialoguesub__near_80048be4(void)
{
    GmDialogueWork* work;

    work = kar_diagnostic__80047844();
    kar_gmdialogue__near_80047864();
    work->field_1 = 1;
    work->field_2 = 0xC;
    work->field_6 = 0;
}
