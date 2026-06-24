#include "functions.h"
#include <dolphin/types.h>
#include <kar/gm/gmlanmenu.h>
#include <kar/mn/mnlandialogue.h>
#include <kar/mn/mnlannumber.h>


u8 lbl_80497AE8[] = {
    0x00, 0x00, 0x00, 0x00, 0x02, 0x80, 0x01, 0xE0, 0x01, 0xE0, 0x00, 0x1E,
    0x00, 0x00, 0x02, 0x94, 0x01, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
    0x06, 0x06, 0x08, 0x08, 0x0A, 0x0C, 0x0A, 0x08, 0x08, 0x00, 0x00, 0x00,
};

u8 lbl_80497B24[] = {
    0x00, 0x00, 0x00, 0x00, 0x02, 0x80, 0x01, 0xE0, 0x01, 0xE0, 0x00, 0x1E,
    0x00, 0x00, 0x02, 0x94, 0x01, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
    0x06, 0x06, 0x00, 0x00, 0x15, 0x16, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 lbl_80497B60[] = {
    0x00, 0x00, 0x00, 0x02, 0x02, 0x80, 0x01, 0xE0, 0x01, 0xE0, 0x00, 0x1E,
    0x00, 0x00, 0x02, 0x94, 0x01, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
    0x06, 0x06, 0x08, 0x08, 0x0A, 0x0C, 0x0A, 0x08, 0x08, 0x00, 0x00, 0x00,
};

void *lbl_80497B9C[3] = { // passed to HSD_SetInitParameter as param 2
    lbl_80497AE8,
    lbl_80497B24,
    lbl_80497B60,
};

typedef struct GmViConfigCopy GmViConfigCopy;
typedef struct GmViConfigState GmViConfigState;

struct GmViConfigCopy {
    u32 words[15];
};

struct GmViConfigState {
    u8 pad_00[0x10];
    s8 field_10;
    s8 field_11;
    u8 pad_12[0x02];
    s32 field_14;
};

const u64 lbl_80489480[] = {
    0xFFAABD00FFE85200ull,
    0x5AC9FF00A8FA8200ull,
    0xFFFFFF00E260FF00ull,
    0x5E3D2500FF293600ull,
};

const u32 lbl_804894A0[] = {
    0x3FEF5C29, 0x3FEF5C29, 0x3FEF5C29, 0x3FEF5C29, 0x40666666,
    0x40933333, 0x400CCCCD, 0x4019999A, 0x40C00000, 0x41066666,
    0x3FEF5C29, 0x40400000, 0x3FEF5C29, 0x403A5E35, 0x3FEF5C29,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

const u32 lbl_804894EC[] = {
    0x00000000, 0x00000000, 0x40E66666, 0x41499999,
    0x40A66666, 0x00000000, 0x00000000,
};

const u32 lbl_80489508[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000,
};

const u32 lbl_80489530[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000,
};

const u32 lbl_80489558[] = {
    0x40BBD70A, 0x40BBD70A, 0x40BBD70A, 0x40BBD70A, 0x40666666,
    0x40A66666, 0x40BBD70A, 0x40BBD70A, 0x40C00000, 0x41066666,
    0x40BBD70A, 0x40DBD70A, 0x40BBD70A, 0x40BBD70A, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x41000000, 0x41400000, 0x41100000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000,
    0x3F800000, 0x00000000,
};

const u32 lbl_804895D8[] = {
    0x01010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000002, 0x00000002, 0x00000001, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000,
    0x00000000,
};

char kar_srcfile_gmviconfigure_c_80497ba8[] = "gmviconfigure.c";
u64 lbl_80537430[8];
char lbl_805D51D8[] = "0";

void HSD_VISetConfigure(void* configure);
s32 kar_shadow__near_8007b650(void);
void kar_gmglobal__near_800088c8(s32 arg0);
void fn_801390E0(void);
void fn_80139188(void);
void fn_801391C8(void);
void kar_lbkdcoll__near_80072aa0(void);
void kar_lbfile_wait_for_group6_loads(void);
void kar_pltrick__near_8023295c(void);
s32 kar_lbhvqm__near_80078d24(void);
void fn_801391F0(void);
extern void shadowRendering(void);

void kar_gmclearchecker__near_8004f5b0(void) { shadowRendering(); }

void *kar_gmclearchecker__near_8004f5d0(void) { return lbl_80497B9C[0]; }


void kar_gmviconfigure__near_8004f5e0(s32 arg0)
{
    if (arg0 >= 3) {
        __assert(kar_srcfile_gmviconfigure_c_80497ba8, 0xA7, lbl_805D51D8);
    }

    if (arg0 >= 3) {
        __assert(kar_srcfile_gmviconfigure_c_80497ba8, 0x86, lbl_805D51D8);
    }

    HSD_VISetConfigure(lbl_80497B9C[arg0]);
}

void kar_gmviconfigure__near_8004f654(void)
{
    if (kar_shadow__near_8007b650() == 0) {
        *(GmViConfigCopy*) lbl_80537430 = *(const GmViConfigCopy*) lbl_804895D8;
    }
}

void kar_gmviconfigure__near_8004f714(void)
{
    GmViConfigState* state = (GmViConfigState*) lbl_80537430;

    if (state->field_11 != 0) {
        state->field_11 = 0;
        state->field_10 = 1;
    } else if (state->field_10 != 0) {
        kar_gmglobal__near_800088c8(0x28);
        state->field_10 = 0;
    }
}

void kar_gmviconfigure__near_8004f77c(void)
{
    GmViConfigState* state = (GmViConfigState*) lbl_80537430;

    fn_801390E0();
    fn_80139188();
    fn_801391C8();
    kar_gmlanmenu_show_lan_bg_panel();
    kar_mnlannumber_show_panel();
    kar_mnlandialogue_show_panel();
    kar_mnlandialogue_show_connect_panel();
    kar_mnlandialogue_show_wait_panel();
    kar_mnlandialogue_show_select_panel();
    kar_mnlandialogue_show_airride_panel();
    kar_mnlandialogue_show_city_panel();
    kar_mnlandialogue_show_time_panel();
    kar_gmlanmenu_set_sis_lan_box0_message_id_adjusted(7);
    kar_gmlanmenu_set_sis_lan_box1_message_id(7);
    kar_gmlanmenu_set_sis_lan_box4_message_id(7);
    kar_gmlanmenu_set_sis_lan_box2_message_id(7);
    kar_gmlanmenu_set_sis_lan_box3_message_id(7);
    kar_mnlandialogue_request_connect_panel_state0_anim();
    kar_lbkdcoll__near_80072aa0();
    kar_lbfile_wait_for_group6_loads();
    kar_pltrick__near_8023295c();
    kar_gmlanmenu__80277748();

    if (((GmViConfigState*) lbl_80537430)->field_14 == 2) {
        if (kar_lbhvqm__near_80078d24() == 0) {
            state->field_14 = 1;
        }
    }
}

void kar_gmviconfigure__near_8004f83c(void)
{
    fn_801391F0();
}
