#include "functions.h"
#include <dolphin/types.h>
#include "kar/gm/gmglobal.h"
#include "kar/gm/gmclearchecker.h"
#include "kar/gm/gmclearchecker_8004a648.h"

typedef struct {
  /* 0x0 */ u32 _0;
  /* 0x4 */ u32 _4;
  /* 0x8 */ u32 _8;
} lbl_8058B634_s;

extern lbl_8058B634_s lbl_8058B634;

extern void *lbl_80497B9C[];

typedef void (*intFunc)(int);

typedef struct {
  /* 0x0 */ int _0;
  /* 0x4 */ intFunc _4;
  /* 0x8 */ int _8;
  /* 0xC */ int _C;
} lbl_80497768_sub;

extern lbl_80497768_sub lbl_80497768[];

typedef int (*GmClearCheckerPredicate)(int number);
extern GmClearCheckerPredicate lbl_80497630[];

extern u8 lbl_80497674[];
extern u8 lbl_80497694[];

static int lbl_805DD598 = 0;

extern s32 kar_shadow__near_8007b650(void);
extern void kar_gmmain__near_800064f0(void);
extern GmMainData *kar_gmmain__near_80006c14(void);
extern void kar_lbaudio__near_8006176c(u32 sound_id);
extern u8 kar_mnclearchecker_get_main_state_or_assert_operating(void);
extern void kar_mnclearchecker_create_screen_and_sis_resources(u8 arg0,
                                                               u8 arg1);
extern s8 fn_8000AECC(void);
extern void fn_8000BC10(void);
extern s8 kar_gmracenormal__8000aea8(void);
extern s8 fn_8000AAC4(void);
extern s8 fn_8000A97C(void);
extern s8 kar_gmracenormal__8000af5c(void);
extern s8 kar_gmracenormal__8003d5f0(void);
extern s32 kar_plclearcheckerlib__near_8022c858(s32 arg0);
extern s32 kar_plclearcheckerlib__8023156c(s32 arg0);
extern s32 kar_plclearcheckerlib__8022eb88(s32 arg0);
extern s32 kar_plclearcheckerlib__8022eb10(s32 arg0, s32 arg1);
extern s32 kar_plclearcheckerlib__8022ea98(s32 arg0, s32 arg1);
extern s32 kar_plclearcheckerlib__802306d4(s32 arg0);
extern s32 fn_8000B1EC(s32 arg0);
extern s8 fn_8000979C(s32 arg0);
extern s8 fn_800092D8(void);
extern s32 fn_80261CE8(s32 arg0);
extern u8 fn_8000A300(void);
extern void kar_gmclearchecker__near_8004d248(s32 arg0);
extern void kar_gmclearchecker__near_8004d454(void);
extern void kar_gmclearchecker__near_8004d5d4(s32 arg0);
extern void kar_gmclearchecker__near_8004d8a8(s32 arg0);
extern s32 kar_gmclearchecker__near_8004ab90(void);
extern s32 kar_gmclearchecker__near_8004acf4(void);
extern s32 kar_gmclearchecker__near_8004ae50(void);
extern s32 kar_gmclearchecker__near_8004b1d0(void);
extern s32 kar_gmclearchecker__near_8004b2b8(void);
extern s32 kar_gmclearchecker__near_8004b404(void);
extern s32 kar_gmclearchecker__near_8004b814(void);
extern s32 kar_gmclearchecker__near_8004b968(void);
extern s32 kar_gmclearchecker__near_8004bb1c(void);
extern void kar_gmlanmenu__8000bba0(void);
extern void fn_80138D74(void);
extern void fn_80138E00(void);
extern f32 fn_80281A0C(void);
extern f32 fn_80009568(int);
extern s8 fn_8000C228(s8);
extern u32 kar_plclearcheckerlib__8022fccc(int, int);
extern s8 fn_8000916C(void);
extern int fn_8000A0F8(void);
extern int kar_plclearchecker_get_state_u32_82c(int);

extern void kar_lbaudio__near_8005e5d0(void);
extern void kar_gmlanmenu__800082a0(int);
extern void kar_gmlanmenu__80008220(void);
extern int fn_80282F70(void);
extern int fn_80281610(void);
extern int fn_80282F38(void);
extern void fn_80282EC8(int);
extern void shadowRendering(void);
extern int kar_lbaudio_alloc_weapon_track_subtype_0(void);
extern int kar_lbaudio__near_8005dbc8(void);
extern void kar_lbaudio_start_track(int, int, int);
extern f32 kar_plclearcheckerlib__80231614(int);
extern u32 kar_plclearcheckerlib__8022fa58(int);
extern u32 kar_plclearcheckerlib__80230b38(int);
extern u32 kar_plclearcheckerlib__80230b90(int);
extern u32 kar_plclearcheckerlib__8022f920(int);
extern u32 kar_plclearcheckerlib__8022fe28(int);
extern u32 kar_plclearcheckerlib__80230934(int);
extern u32 kar_plclearcheckerlib__8022fe80(int);
extern u32 kar_plclearcheckerlib__80230838(int);
extern u32 kar_plclearcheckerlib__8022faac(int);
extern u32 kar_plclearcheckerlib__8022ebdc(int);
extern u32 kar_plclearcheckerlib__8022ec34(int);
extern u32 kar_plclearcheckerlib__8022f898(int, int);
extern u32 kar_greventgenerator_get_kind_use_count(int);
extern u16 kar_plclearcheckerlib__8022f3a4(int, int);
extern u8 *kar_grlib2__near_800d57b0(void);
extern s8 fn_80009534(int);
extern int kar_plclearcheckerlib__802307e4(int);
extern int kar_plclearcheckerlib__8023077c(int, int);
extern u32 kar_plclearchecker_get_state_u32_7d4(int);
extern u32 kar_plclearchecker_get_state_u32_7d8(int);
extern u32 kar_plclearcheckerlib__8022f19c(int);
extern int HSD_Randi(int);
extern int kar_plclearchecker_get_flag_854_bit0(int);
extern int kar_plclearchecker_get_flag_854_bit1(int);
extern int kar_plclearchecker_get_flag_854_bit2(int);
extern int kar_plclearchecker_get_flag_854_bit5(int);
extern int kar_plclearchecker_get_flag_84c_bit5(int);
extern int kar_plclearchecker_get_flag_854_bit6(int);
extern int kar_plclearchecker_get_flag_84d_bit6(int);
extern int kar_plclearchecker_get_flag_854_bit7(int);
extern int kar_plclearchecker_get_flag_855_bit7(int);
extern u32 kar_plclearcheckerlib__802309e0(int);
extern u32 kar_plclearcheckerlib__80230728(int);
extern int kar_plclearchecker_get_state_u32_81c(int);
extern u32 kar_plclearcheckerlib__802308e0(int);
extern u32 kar_plclearcheckerlib__8023098c(int);
extern u32 kar_plclearcheckerlib__8022fd48(int);
extern u32 kar_plclearcheckerlib__80230a34(int);
extern u32 kar_plclearchecker_get_state_u32_7fc(int);
extern int kar_plclearchecker_get_state_u32_844(int);
extern u32 kar_plclearcheckerlib__80230a88(int);
extern int kar_plclearcheckerlib__802300b4(int);
extern u32 kar_plclearcheckerlib__80230ae0(int);
extern int kar_plclearcheckerlib__80230294(int);
extern int kar_plclearcheckerlib__8023002c(int, int);
extern u32 kar_plclearcheckerlib__8023088c(int);
extern int fn_800097D0(void);
extern int fn_802625F8(void);
extern s8 fn_80009190(void);
extern s16 fn_800091E4(void);
extern int kar_plclearcheckerlib__near_8022c910(int);
extern int fn_80009FB8(void);
extern int kar_plclearcheckerlib__8022f9bc(int);
extern int kar_plclearcheckerlib__8022f514(int);
extern int kar_plclearcheckerlib__8022f4c0(int);
extern int kar_plclearcheckerlib__8022f46c(int);
extern int kar_plclearcheckerlib__80230474(int);
extern int kar_plclearcheckerlib__8022f418(int);
extern int kar_plclearcheckerlib__80230be8(int);
extern int kar_plclearcheckerlib__80230420(int);
extern int kar_plclearcheckerlib__80230240(int);
extern int kar_plclearcheckerlib__8022fdc0(int);
extern int kar_plclearcheckerlib__8022ed50(int);
extern int kar_plclearcheckerlib__8022eda8(int);
extern int kar_plclearchecker_get_state_u32_840(int);
extern int kar_plclearchecker_get_flag_854_bit3(int);
extern int kar_plclearchecker_get_flag_854_bit4(int);
extern int kar_plclearcheckerlib__80230c3c(int);
extern int kar_plclearcheckerlib__80230c94(int);
extern int kar_plclearcheckerlib__80231510(int);
extern int kar_plclearcheckerlib__802315c0(int);
extern void fn_80282300(void);
extern void fn_8028236C(void);
extern void fn_80282004(void);
extern void fn_80281F10(void);
extern void fn_80281ECC(int);
extern void kar_pltrick__near_802339e4(void);
extern void kar_lbarealightzone__near_8007adb8(void);
extern void fn_80281660(void);
extern void fn_80281AD4(void);
extern void fn_80281BB4(void);
extern void fn_802823FC(int);
extern void kar_lbaudio__near_8005ab84(void);
extern void kar_lbaudio__near_8005e1a8(int);
extern void kar_lbaudio__near_8005a5b0(void);
extern void kar_lbvector__near_8006595c(void);
extern int fn_802819CC(void);
extern void fn_8028208C(int);
extern void fn_80281F4C(int);
extern void fn_80282058(int);
extern void fn_80281FA8(int);
extern void fn_80281904(void);
extern u32 fn_802819E8(void);
extern void fn_8028196C(void);
extern int kar_plclearcheckerlib__near_8022c8b0(int);
extern int kar_plclearcheckerlib__near_8022c8e0(int);
extern int kar_plclearcheckerlib__8022f568(int);

int kar_gmclearchecker__near_8004ac34(int);
int kar_gmclearchecker__near_8004afc0(int);
int kar_gmclearchecker__near_8004b23c(int);
int kar_gmclearchecker__near_8004b578(int);
int kar_gmclearchecker__near_8004b62c(int);
int kar_gmclearchecker__near_8004b720(int);
int kar_gmclearchecker__near_8004bcb4(int);
int kar_gmclearchecker__near_8004bd68(int);
int kar_gmclearchecker__near_8004be1c(int);
int kar_gmclearchecker__near_8004bed0(int);
int kar_gmclearchecker__near_8004bf84(int);
int kar_gmclearchecker__near_8004c038(int);
int kar_gmclearchecker__near_8004c0ec(int);
int kar_gmclearchecker__near_8004c1a0(int);
int kar_gmclearchecker__near_8004c2b4(int);
int kar_gmclearchecker__near_8004c4a4(int);
int kar_gmclearchecker__near_8004c5ac(int);
int kar_gmclearchecker__near_8004c6b4(int);
int kar_gmclearchecker__near_8004c7bc(int);
int kar_gmclearchecker__near_8004c8c4(int);
int kar_gmclearchecker__near_8004c9d0(int);
int kar_gmclearchecker__near_8004cad8(int);
int kar_gmclearchecker__near_8004cbe0(int);
int kar_gmclearchecker__near_8004cd5c(int);
int kar_gmclearchecker__near_8004ce64(int);
int kar_gmclearchecker__near_8004cfe0(int);

GmClearCheckerPredicate lbl_804975B8[30] = {
    &kar_gmclearchecker__near_8004ac34,
    &kar_gmclearchecker__near_8004ac34,
    &kar_gmclearchecker__near_8004afc0,
    &kar_gmclearchecker__near_8004afc0,
    &kar_gmclearchecker__near_8004afc0,
    &kar_gmclearchecker__near_8004afc0,
    &kar_gmclearchecker__near_8004b23c,
    &kar_gmclearchecker__near_8004b578,
    &kar_gmclearchecker__near_8004b62c,
    &kar_gmclearchecker__near_8004b720,
    &kar_gmclearchecker__near_8004bcb4,
    &kar_gmclearchecker__near_8004bd68,
    &kar_gmclearchecker__near_8004be1c,
    &kar_gmclearchecker__near_8004bed0,
    &kar_gmclearchecker__near_8004bf84,
    &kar_gmclearchecker__near_8004c038,
    &kar_gmclearchecker__near_8004c0ec,
    &kar_gmclearchecker__near_8004c1a0,
    &kar_gmclearchecker__near_8004c2b4,
    &kar_gmclearchecker__near_8004c4a4,
    &kar_gmclearchecker__near_8004c5ac,
    &kar_gmclearchecker__near_8004c6b4,
    &kar_gmclearchecker__near_8004c7bc,
    &kar_gmclearchecker__near_8004c8c4,
    &kar_gmclearchecker__near_8004c9d0,
    &kar_gmclearchecker__near_8004cad8,
    &kar_gmclearchecker__near_8004cbe0,
    &kar_gmclearchecker__near_8004cd5c,
    &kar_gmclearchecker__near_8004ce64,
    &kar_gmclearchecker__near_8004cfe0,
};

inline
u16 CLAMP_16(u32 i) { return i > 0xffff ? 0xffff : (u16)i; }

inline
u8 CLAMP_8(u32 i) { return i > 0xff ? 0xff : (u8)i; }

void kar_gmclearchecker__near_8004a648(void) {
  s32 minor;

  switch (kar_mnclearchecker_get_main_state_or_assert_operating()) {
  case 0xB:
    kar_gmglobal__near_800088c8(-1);
    kar_gmmain__near_800064f0();
    break;
  case 0xC:
    kar_lbaudio__near_8006176c(0x1000A);
    minor = fn_8000AECC();
    kar_gmglobal__near_800088c8((s8)(++minor > 0x22 ? 0x20 : minor));
    kar_gmmain__near_800064f0();
    break;
  case 0xD:
    kar_lbaudio__near_8006176c(0x1000A);
    minor = fn_8000AECC();
    kar_gmglobal__near_800088c8((s8)(--minor < 0x20 ? 0x22 : minor));
    kar_gmmain__near_800064f0();
    break;
  case 0xE:
    fn_8000BC10();
    switch (fn_8000AECC()) {
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

void kar_gmclearchecker__near_8004a768(void) {
  GmMainData *main = kar_gmmain__near_80006c14();
  s32 flag;
  s8 minor;

  fn_80138D74();
  flag = main->clearchecker_flag == 0;
  minor = fn_8000AECC() - 0x20;
  kar_mnclearchecker_create_screen_and_sis_resources(minor, flag);
  if (kar_gmracenormal__8000aea8() == 3) {
    kar_gmlanmenu__8000bba0();
  }
}

void kar_gmclearchecker__near_8004a7d0(void) { fn_80138E00(); }

void kar_gmclearchecker__near_8004a7f0(void) {
  GmMainData *main;
  GmClearCheckerPredicate predicate;
  s32 i;
  s32 index;
  s32 number;

  if (kar_shadow__near_8007b650() != 0) {
    return;
  }
  if (fn_8000AAC4() != 0) {
    return;
  }
  if (kar_gmracenormal__8000af5c() != 0) {
    return;
  }
  switch (fn_8000A97C()) {
  case 0:
    if (kar_gmracenormal__8000aea8() == 4) {
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

void kar_gmclearchecker__near_8004a90c(s32 arg0) {
  if (kar_shadow__near_8007b650() != 0) {
    return;
  }
  if (fn_8000AAC4() != 0) {
    return;
  }
  switch (kar_gmracenormal__8000af5c()) {
  case 0:
    if (kar_gmracenormal__8000aea8() == 4 &&
        kar_plclearcheckerlib__near_8022c858(arg0) == 0 &&
        kar_gmracenormal__8003d5f0() == 2) {
      kar_gmclearchecker__near_8004d8a8(arg0);
    }
  }
}

void kar_gmclearchecker__near_8004a994(s32 arg0) {
  s8 mode;

  if (kar_shadow__near_8007b650() != 0) {
    return;
  }
  if (fn_8000AAC4() != 0) {
    return;
  }
  switch (kar_gmracenormal__8000af5c()) {
  case 0:
    if (kar_gmracenormal__8000aea8() == 4 &&
        kar_plclearcheckerlib__near_8022c858(arg0) == 0) {
      mode = kar_gmracenormal__8003d5f0();
      if (mode == 0 && fn_8000A300() == 1) {
        if (fn_8000916C() == 0) {
          kar_gmclearchecker__near_8004d248(arg0);
        }
      } else if (mode == 1) {
        kar_gmclearchecker__near_8004d5d4(arg0);
      }
    }
  }
}

void kar_gmclearchecker__near_8004aa58(void) {
  GmGlobalData *global;
  s32 i;
  s32 number;

  if (kar_shadow__near_8007b650() != 0) {
    return;
  }
  if (fn_8000AAC4() != 0) {
    return;
  }

  switch (kar_gmracenormal__8000af5c()) {
  case 0:
    if (kar_gmracenormal__8000aea8() == 4) {
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

      if ((s8)fn_8000916C() == 1) {
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

s32 kar_gmclearchecker__near_8004ab90(void) {
  s8 mode;
  GmGlobalData *global;
  s32 i;
  s32 total;
  s32 player_state;
  s32 value;

  mode = kar_gmracenormal__8003d5f0();
  global = kar_gmglobal__near_8000771c();
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

int kar_gmclearchecker__near_8004ac34(int type) {
  s32 total = kar_gmclearchecker__near_8004ab90();
  s32 r27;

  if (type == 0) {
    r27 = 100;
  } else if (type == 1) {
    r27 = 300;
  }

  if (r27 <= total) {
    return 1;
  } else {
    return 0;
  }
}

s32 kar_gmclearchecker__near_8004acf4(void) {
  s8 mode;
  GmGlobalData *global;
  s32 i;
  s32 total;
  s32 player_state;

  mode = kar_gmracenormal__8003d5f0();
  global = kar_gmglobal__near_8000771c();
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

int kar_gmclearchecker__near_8004ad90(int type) {
  s32 total = kar_gmclearchecker__near_8004acf4();
  s32 r27;

  if (type == 2) {
    r27 = 108000;
  } else if (type == 3) {
    r27 = 216000;
  }

  if (r27 <= total) {
    return 1;
  } else {
    return 0;
  }
}

s32 kar_gmclearchecker__near_8004ae50(void) {
  s8 mode;
  GmGlobalData *global;
  s32 i;
  s32 total;
  s32 player_state;

  mode = kar_gmracenormal__8003d5f0();
  global = kar_gmglobal__near_8000771c();
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

s32 kar_gmclearchecker__near_8004b1d0(void) {
  GmGlobalData *global;
  s32 i;
  s32 total;

  global = kar_gmglobal__near_8000771c();
  total = global->clearchecker_total_3;
  for (i = 0; i < 5; i++) {
    if (kar_plclearcheckerlib__near_8022c858(i) == 0) {
      if ((s8)fn_8000979C(i) != 0) {
        total++;
      }
    }
  }

  return total;
}

int kar_gmclearchecker__near_8004aef8(int type) {
  u32 total = kar_gmclearchecker__near_8004ae50();
  int r27;

  if (type == 4) {
    r27 = 300;
  } else if (type == 5) {
    r27 = 1000;
  }

  if (total >= r27) {
    return 1;
  } else {
    return 0;
  }
}

static inline int kar_gmclearchecker__near_8004b578_sub() {
  int i;
  for (i = 0; i < 5; i++) {
    if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_8000979C(i) != 0) {
      return 1;
    }
  }
  return 0;
}

inline int kar_gmclearchecker__near_8004afc0_sub() {
  if (kar_gmracenormal__8003d5f0() == 0) {
    if (fn_8000916C() == 0) {
      if (kar_gmclearchecker__near_8004b578_sub()) {
        return 1;
      }
    } else if (fn_8000A0F8() <= 0) {
      return 1;
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004afc0(int arg) {
  u32 r31;
  u32 r30;
  int i;
  if (kar_gmclearchecker__near_8004afc0_sub()) {
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0) {
        r31 = 0;
        switch (arg) {
        case 6:
          r31 = kar_plclearcheckerlib__8023077c(i, 0xb);
          r31 += kar_plclearcheckerlib__8023077c(i, 0x23);
          r31 += kar_plclearcheckerlib__8023077c(i, 0x3b);
          r30 = 3;
          break;
        case 7:
          r31 = kar_plclearcheckerlib__8023077c(i, 0xd);
          r31 += kar_plclearcheckerlib__8023077c(i, 0x25);
          r31 += kar_plclearcheckerlib__8023077c(i, 0x3d);
          r30 = 3;
          break;
        case 8:
          r31 = kar_plclearcheckerlib__8023077c(i, 0x5);
          r31 += kar_plclearcheckerlib__8023077c(i, 0x1d);
          r31 += kar_plclearcheckerlib__8023077c(i, 0x35);
          r30 = 3;
          break;
        case 9:
          r31 = kar_plclearcheckerlib__8023077c(i, 0x8);
          r31 += kar_plclearcheckerlib__8023077c(i, 0x20);
          r31 += kar_plclearcheckerlib__8023077c(i, 0x38);
          r30 = 3;
          break;
        }
        if (r31 >= r30) {
          return 1;
        }
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004b23c(int type) {
  GmGlobalData *global;
  s32 total;
  s32 i;

  global = kar_gmglobal__near_8000771c();
  total = global->clearchecker_total_3;
  for (i = 0; i < 5; i++) {
    if (kar_plclearcheckerlib__near_8022c858(i) == 0) {
      if ((s8)fn_8000979C(i) != 0) {
        total++;
      }
    }
  }

  total = total >= 3;
  return total;
}

s32 kar_gmclearchecker__near_8004b2b8(void) {
  s8 mode;
  GmGlobalData *global;
  s32 total;
  s32 i;
  s32 player_state;

  mode = kar_gmracenormal__8003d5f0();
  global = kar_gmglobal__near_8000771c();
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

int kar_gmclearchecker__near_8004b354(void) {
  u32 total = kar_gmclearchecker__near_8004b2b8();
  if (total >= 200) {
    return 1;
  } else {
    return 0;
  }
}

s32 kar_gmclearchecker__near_8004b404(void) {
  s8 mode;
  GmGlobalData *global;
  s32 total;
  s32 i;
  s32 player_state;

  mode = kar_gmracenormal__8003d5f0();
  global = kar_gmglobal__near_8000771c();
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

s32 kar_gmclearchecker__near_8004b4b4(void) {
  u32 total = kar_gmclearchecker__near_8004b404();
  if (total >= 100) {
    return 1;
  } else {
    return 0;
  }
}

int kar_gmclearchecker__near_8004b578(int unused) {
  int i;

  if (kar_gmclearchecker__near_8004b578_sub() != 0) {
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          kar_plclearcheckerlib__802307e4(i) >= 5) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004b62c(int unused) {
  int i;

  if (kar_gmclearchecker__near_8004afc0_sub() != 0) {
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          kar_plclearchecker_get_state_u32_7d4(i) == 10) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004b720(int unused) {
  int i;

  if (kar_gmclearchecker__near_8004afc0_sub() != 0) {
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          kar_plclearchecker_get_state_u32_7d8(i) >= 15) {
        return 1;
      }
    }
  }
  return 0;
}

s32 kar_gmclearchecker__near_8004b814(void) {
  s8 mode;
  GmGlobalData *global;
  s32 total;
  s32 i;
  s32 player_state;

  mode = kar_gmracenormal__8003d5f0();
  global = kar_gmglobal__near_8000771c();
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

int kar_gmclearchecker__near_8004b8b4(void) {
  u32 total = kar_gmclearchecker__near_8004b814();
  if (total >= 10) {
    return 1;
  } else {
    return 0;
  }
}

s32 kar_gmclearchecker__near_8004b968(void) {
  s8 mode;
  GmGlobalData *global;
  s32 total;
  s32 i;
  s32 player_state;

  mode = kar_gmracenormal__8003d5f0();
  global = kar_gmglobal__near_8000771c();
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

int kar_gmclearchecker__near_8004ba08(void) {
  u32 total = kar_gmclearchecker__near_8004b968();
  if (total >= 0x14) {
    return 1;
  } else {
    return 0;
  }
}

int kar_gmclearchecker__near_8004babc(void) {
  int i;
  for (i = 0; i < 5; i++) {
    if (kar_plclearcheckerlib__near_8022c858(i) == 0 &&
        kar_plclearchecker_get_flag_84d_bit6(i) != 0) {
      return 1;
    }
  }
  return 0;
}

s32 kar_gmclearchecker__near_8004bb1c(void) {
  GmGlobalData *global;
  s32 total;
  s32 bit;

  global = kar_gmglobal__near_8000771c();
  total = global->clearchecker_total_8;
  bit = 1 << fn_80261CE8((s8)fn_800092D8());
  total |= bit;
  return total;
}

s32 kar_gmclearchecker__near_8004bb64(void) {
  int ret = 1;
  s32 total = kar_gmclearchecker__near_8004bb1c();
  int i;

  for (i = 0; i < 9; i++) {
    if ((total & (1 << i)) == 0 && i != 6) {
      ret = 0;
    }
  }
  return ret;
}

int kar_gmclearchecker__near_8004bcb4(int unused) {
  int i;

  if (kar_gmclearchecker__near_8004b578_sub() != 0) {
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          kar_plclearchecker_get_state_u32_82c(i) >= 3) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004bd68(int unused) {
  int i;

  if (kar_gmclearchecker__near_8004b578_sub() != 0) {
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          kar_plclearchecker_get_flag_854_bit7(i) != 0) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004be1c(int unused) {
  int i;

  if (kar_gmclearchecker__near_8004b578_sub() != 0) {
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          kar_plclearchecker_get_flag_854_bit5(i) != 0) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004bed0(int unused) {
  int i;

  if (kar_gmclearchecker__near_8004b578_sub() != 0) {
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          kar_plclearchecker_get_flag_854_bit6(i) != 0) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004bf84(int unused) {
  int i;

  if (kar_gmclearchecker__near_8004b578_sub() != 0) {
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          kar_plclearchecker_get_flag_854_bit2(i) != 0) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004c038(int unused) {
  int i;

  if (kar_gmclearchecker__near_8004b578_sub() != 0) {
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          kar_plclearchecker_get_flag_854_bit1(i) != 0) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004c0ec(int unused) {
  int i;

  if (kar_gmclearchecker__near_8004b578_sub() != 0) {
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          kar_plclearchecker_get_flag_854_bit0(i) != 0) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004c1a0(int unused) {
  int i;

  if (kar_gmclearchecker__near_8004b578_sub() != 0) {
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          kar_plclearchecker_get_flag_855_bit7(i) != 0) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004c254(int unused) {
  int i;
  for (i = 0; i < 5; i++) {
    if (kar_plclearcheckerlib__near_8022c858(i) == 0 &&
        kar_plclearcheckerlib__802309e0(i) >= 3) {
      return 1;
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004c2b4(int unused) {
  if (kar_gmclearchecker__near_8004afc0_sub() &&
      fn_80261CE8(fn_800092D8()) == 0) {
    int i;
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          (u32)kar_plclearcheckerlib__80230728(i) >= 20) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004c3bc(int unused) {
  if (fn_80261CE8(fn_800092D8()) == 0) {
    int i;
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 &&
          kar_plclearchecker_get_flag_84c_bit5(i) != 0) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004c430(int unused) {
  if (fn_80261CE8(fn_800092D8()) == 7) {
    int i;
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 &&
          kar_plclearchecker_get_state_u32_81c(i) >= 3) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004c4a4(int unused) {
  if (kar_gmclearchecker__near_8004afc0_sub() &&
      fn_80261CE8(fn_800092D8()) == 7) {
    int i;
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          (u32)kar_plclearcheckerlib__80230728(i) >= 20) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004c5ac(int unused) {
  if (kar_gmclearchecker__near_8004afc0_sub() &&
      fn_80261CE8(fn_800092D8()) == 3) {
    int i;
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          kar_plclearcheckerlib__802308e0(i) >= 7) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004c6b4(int unused) {
  if (kar_gmclearchecker__near_8004afc0_sub() &&
      fn_80261CE8(fn_800092D8()) == 3) {
    int i;
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          (u32)kar_plclearcheckerlib__8023098c(i) >= 2) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004c7bc(int unused) {
  if (kar_gmclearchecker__near_8004afc0_sub() &&
      fn_80261CE8(fn_800092D8()) == 3) {
    int i;
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          (u32)kar_plclearcheckerlib__80230728(i) >= 20) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004c8c4(int unused) {
  if (kar_gmclearchecker__near_8004afc0_sub() &&
      fn_80261CE8(fn_800092D8()) == 8) {
    int i;
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          kar_plclearcheckerlib__8022fccc(i, 0x20) >= 20) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004c9d0(int unused) {
  if (kar_gmclearchecker__near_8004afc0_sub() &&
      fn_80261CE8(fn_800092D8()) == 2) {
    int i;
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          kar_plclearcheckerlib__8022fd48(i) != 0) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004cad8(int unused) {
  if (kar_gmclearchecker__near_8004afc0_sub() &&
      fn_80261CE8(fn_800092D8()) == 2) {
    int i;
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          kar_plclearcheckerlib__80230a34(i) == 3) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004cbe0(int unused) {
  if (kar_gmclearchecker__near_8004afc0_sub() &&
      fn_80261CE8(fn_800092D8()) == 2) {
    int i;
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          (u32)kar_plclearchecker_get_state_u32_7fc(i) == 3) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004cce8(int unused) {
  if (fn_80261CE8(fn_800092D8()) == 5) {
    int i;
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 &&
          kar_plclearchecker_get_state_u32_844(i) >= 3) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004cd5c(int unused) {
  if (kar_gmclearchecker__near_8004afc0_sub() &&
      fn_80261CE8(fn_800092D8()) == 5) {
    int i;
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          (u32)kar_plclearcheckerlib__80230a88(i) == 0) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004ce64(int unused) {
  if (kar_gmclearchecker__near_8004afc0_sub() &&
      fn_80261CE8(fn_800092D8()) == 1) {
    int i;
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          kar_plclearcheckerlib__802300b4(i) != 0) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004cf6c(int unused) {
  if (fn_80261CE8(fn_800092D8()) == 1) {
    int i;
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 &&
          kar_plclearcheckerlib__80230ae0(i) != 0) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004cfe0(int unused) {
  if (kar_gmclearchecker__near_8004afc0_sub() &&
      fn_80261CE8(fn_800092D8()) == 1) {
    int i;
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_80009534(i) == 0 &&
          kar_plclearcheckerlib__80230294(i) != 0) {
        return 1;
      }
    }
  }
  return 0;
}

int kar_gmclearchecker__near_8004d0e8(void) {
  int ret = 1;
  int k, i, j;
  u8 *p;

  if (fn_80261CE8(fn_800092D8()) == 4) {
    p = kar_grlib2__near_800d57b0();
    for (i = 0; i < 13; p++, i++) {
      if (*p == 0) {
        continue;
      }
      
      for (j = 0; j < 8; j++) {
        if ((*p & (1 << j)) == 0) {
          continue;
        }

        for (k = 0; k < 5; k++) {
          if (kar_plclearcheckerlib__near_8022c858(k) == 0 &&
              kar_plclearcheckerlib__8023002c(k, j + i * 8)) {
            break;
          }
        }

        if (k == 5) {
          ret = 0;
        }
      }
    }
  } else {
    ret = 0;
  }
  return ret;
}

int kar_gmclearchecker__near_8004d1d4(void) {
  if (fn_80261CE8(fn_800092D8()) == 4) {
    int i;
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 &&
          (u32)kar_plclearcheckerlib__8023088c(i) != 0) {
        return 1;
      }
    }
  }
  return 0;
}

void kar_gmclearchecker__near_8004d248(s32 type) {
  int r31 = fn_800097D0();
  int r29 = fn_80261CE8(fn_800092D8());
  int i;
  int b[2];
  int a[2];
  if (fn_802625F8() == (s8)fn_80009190()) {
    switch (r29) {
    case 0:
      a[0] = 35;
      b[0] = 3780;
      a[1] = 25;
      b[1] = 4800;
      break;
    case 4:
      a[0] = 36;
      b[0] = 6960;
      a[1] = 26;
      b[1] = 8400;
      break;
    case 2:
      a[0] = 37;
      b[0] = 6300;
      a[1] = 27;
      b[1] = 7500;
      break;
    case 8:
      a[0] = 38;
      b[0] = 6960;
      a[1] = 29;
      b[1] = 8400;
      break;
    case 1:
      a[0] = 39;
      b[0] = 7260;
      a[1] = 13;
      b[1] = 8400;
      break;
    case 7:
      a[0] = 40;
      b[0] = 6960;
      a[1] = 17;
      b[1] = 8280;
      break;
    case 5:
      a[0] = 41;
      b[0] = 6480;
      a[1] = 18;
      b[1] = 7800;
      break;
    case 3:
      a[0] = 42;
      b[0] = 9600;
      a[1] = 19;
      b[1] = 11100;
      break;
    }
    for (i = 0; i < 2; i++) {
      if (r31 != 0 && b[i] != 0 && r31 <= b[i]) {
        if (((u8)kar_gmclearchecker__8004a130(0, (u8)a[i]) & 0x5) == 0) {
          kar_gmclearchecker__8004a054(0, (u8)a[i]);
        }
      }
    }
  }
}

void kar_gmclearchecker__near_8004d454(void) {
  int r30 = 0;
  int r31 = fn_80261CE8(fn_800092D8());
  s32 r29;
  int r28 = (s16)fn_800091E4() * 60;
  f32 f31;
  int i;
  switch (r31) {
  case 0:
    f31 = 4500.0f;
    r29 = 20;
    r30 = 7200;
    break;
  case 4:
    f31 = 6000.0f;
    r29 = 21;
    r30 = 7200;
    break;
  case 2:
    f31 = 4000.0f;
    r29 = 22;
    r30 = 7200;
    break;
  case 8:
    f31 = 5300.0f;
    r29 = 23;
    r30 = 7200;
    break;
  case 1:
    f31 = 4800.0f;
    r29 = 12;
    r30 = 7200;
    break;
  case 7:
    f31 = 5500.0f;
    r29 = 34;
    r30 = 7200;
    break;
  case 5:
    f31 = 4500.0f;
    r29 = 33;
    r30 = 7200;
    break;
  case 3:
    f31 = 5500.0f;
    r29 = 11;
    r30 = 7200;
    break;
  }
  for (i = 0; i < 5; i++) {
    if (kar_plclearcheckerlib__near_8022c858(i) == 0) {
      f32 f0 = fn_80009568(i) / 0.304788f;
      if (r28 != 0 && r30 != 0 && r28 == r30 && f0 >= f31 &&
          (kar_gmclearchecker__8004a130(0, r29) & 5) == 0) {
        kar_gmclearchecker__8004a054(0, r29);
      }
    }
  }
}

void kar_gmclearchecker__near_8004d5d4(s32 arg0) {
  int r31 = fn_800097D0();
  int r30 = fn_80261CE8(fn_800092D8());
  int i;
  u32 sp14[3];
  u32 sp8[3];
  s8 r0;
  sp14[0] = sp14[1] = sp14[2] = 0;
  r0 = kar_plclearcheckerlib__near_8022c910(arg0);

  switch (r30) {
  case 0:
    sp8[0] = 0x2b;
    sp8[1] = 0x2c;
    sp8[2] = 0x5d;
    sp14[0] = 4320;
    sp14[1] = 3600;
    if (r0 == 6) {
      sp14[2] = 3900;
    }
    break;
  case 4:
    sp8[0] = 0x2d;
    sp8[1] = 0x2e;
    sp8[2] = 0x69;
    sp14[0] = 12000;
    sp14[1] = 10560;
    if (r0 == 13) {
      sp14[2] = 10680;
    }
    break;
  case 2:
    sp8[0] = 0x2f;
    sp8[1] = 0x30;
    sp8[2] = 0x6c;
    sp14[0] = 11400;
    sp14[1] = 9600;
    if (r0 == 9) {
      sp14[2] = 9600;
    }
    break;
  case 8:
    sp8[0] = 0x31;
    sp8[1] = 0x32;
    sp8[2] = 0x71;
    sp14[0] = 11640;
    sp14[1] = 10200;
    if (r0 == 12) {
      sp14[2] = 11400;
    }
    break;
  case 1:
    sp8[0] = 0x33;
    sp8[1] = 0x34;
    sp8[2] = 0x73;
    sp14[0] = 12000;
    sp14[1] = 11040;
    if (r0 == 3) {
      sp14[2] = 11700;
    }
    break;
  case 7:
    sp8[0] = 0x35;
    sp8[1] = 0x36;
    sp8[2] = 0x75;
    sp14[0] = 11400;
    sp14[1] = 10500;
    if (r0 == 10) {
      sp14[2] = 10800;
    }
    break;
  case 5:
    sp8[0] = 0x37;
    sp8[1] = 0x38;
    sp8[2] = 0x76;
    sp14[0] = 11400;
    sp14[1] = 10080;
    if (r0 == 22) {
      sp14[2] = 10200;
    }
    break;
  case 3:
    sp8[0] = 0x39;
    sp8[1] = 0x3A;
    sp8[2] = 0x77;
    sp14[0] = 16200;
    sp14[1] = 14400;
    if (r0 == 0) {
      sp14[2] = 14100;
    }
    break;
  }
  if (r31 != 0) {
    for (i = 0; i < 3; i++) {
      if (sp14[i] != 0 && r31 <= sp14[i] &&
          (kar_gmclearchecker__8004a130(0, (u8)sp8[i]) & 5) == 0) {
        kar_gmclearchecker__8004a054(0, (u8)sp8[i]);
      }
    }
  }
}

void kar_gmclearchecker__near_8004d8a8(s32 arg0) {
  int r31 = fn_80009FB8();
  int r30 = fn_80261CE8(fn_800092D8());
  int i;
  int sp14[3];
  u32 sp8[3];
  s8 r0;
  sp14[0] = sp14[1] = sp14[2] = 0;
  r0 = kar_plclearcheckerlib__near_8022c910(arg0);

  switch (r30) {
  case 0:
    sp8[0] = 0x3b;
    sp8[1] = 0x3c;
    sp8[2] = 0x3d;
    sp14[0] = 1440;
    sp14[1] = 1260;
    if (r0 == 9) {
      sp14[2] = 1380;
    }
    break;
  case 4:
    sp8[0] = 0x3e;
    sp8[1] = 0x3f;
    sp8[2] = 0x40;
    sp14[0] = 4200;
    sp14[1] = 3420;
    if (r0 == 6) {
      sp14[2] = 3720;
    }
    break;
  case 2:
    sp8[0] = 0x41;
    sp8[1] = 0x42;
    sp8[2] = 0x43;
    sp14[0] = 3900;
    sp14[1] = 3180;
    if (r0 == 5) {
      sp14[2] = 3900;
    }
    break;
  case 8:
    sp8[0] = 0x44;
    sp8[1] = 0x45;
    sp8[2] = 0x46;
    sp14[0] = 4200;
    sp14[1] = 3480;
    if (r0 == 7) {
      sp14[2] = 4200;
    }
    break;
  case 1:
    sp8[0] = 0x47;
    sp8[1] = 0x48;
    sp8[2] = 0x49;
    sp14[0] = 4200;
    sp14[1] = 3660;
    if (r0 == 12) {
      sp14[2] = 3720;
    }
    break;
  case 7:
    sp8[0] = 0x4a;
    sp8[1] = 0x4b;
    sp8[2] = 0x4c;
    sp14[0] = 4020;
    sp14[1] = 3480;
    if (r0 == 2) {
      sp14[2] = 3480;
    }
    break;
  case 5:
    sp8[0] = 0x4d;
    sp8[1] = 0x4e;
    sp8[2] = 0x4f;
    sp14[0] = 3900;
    sp14[1] = 3360;
    if (r0 == 11) {
      sp14[2] = 3420;
    }
    break;
  case 3:
    sp8[0] = 0x50;
    sp8[1] = 0x51;
    sp8[2] = 0x52;
    sp14[0] = 5700;
    sp14[1] = 4800;
    if (r0 == 10) {
      sp14[2] = 5100;
    }
    break;
  }
  if (r31 != 0) {
    for (i = 0; i < 3; i++) {
      if (sp14[i] != 0 && r31 <= sp14[i] &&
          (kar_gmclearchecker__8004a130(0, (u8)sp8[i]) & 5) == 0) {
        kar_gmclearchecker__8004a054(0, (u8)sp8[i]);
      }
    }
  }
}

void kar_gmclearchecker__near_8004db74(void) {
  u32 r20;
  u32 r21;
  int r22;
  int r23;
  u32 r24;
  int i; // r25
  kar_gmglobal__near_8000774c_s *r26;
  int r31;
  u32 r30;
  u32 r29;
  u32 r28;
  u32 r27;

  // temps?
  f32 f1;
  int sVar;

  r26 = kar_gmglobal__near_8000774c();
  r31 = 0;
  r22 = 0;
  r23 = 0;
  r24 = 0;
  r30 = 0;
  r29 = 0;
  r28 = 0;
  r27 = 0;
  r20 = 0;
  r21 = 0;

  if (kar_shadow__near_8007b650() != 0) {
    return;
  }

  for (i = 0; i < 5; i++) {
    if (kar_plclearcheckerlib__near_8022c858(i) == 0) {
      f1 = r26->_10C + kar_plclearcheckerlib__80231614(i);
      r26->_10C = f1 > 87500000.0f ? 87500000.0f : f1;

      r26->_0FB = CLAMP_8(r26->_0FB + kar_plclearcheckerlib__8022f898(i, 0xd));

      r26->_106 = CLAMP_16(r26->_106 + kar_plclearcheckerlib__8022f920(i));

      r26->_108 = CLAMP_16(r26->_108 + kar_plclearcheckerlib__8022f9bc(i));

      r26->_0F8 = CLAMP_8(r26->_0F8 + kar_plclearcheckerlib__8022f514(i));

      r26->_0F9 = CLAMP_8(r26->_0F9 + kar_plclearcheckerlib__8022f4c0(i));

      r26->_0FA = CLAMP_8(r26->_0FA + kar_plclearcheckerlib__8022f46c(i));

      r26->_0F5 = CLAMP_8(r26->_0F5 + kar_plclearcheckerlib__8022fccc(i, 0x28));

      r26->_0F7 = CLAMP_8(r26->_0F7 + kar_plclearcheckerlib__8022fccc(i, 0x1d));

      r26->_0FC = CLAMP_8(r26->_0FC + kar_plclearcheckerlib__80230474(i));

      r26->_0FD = CLAMP_8(r26->_0FD + kar_plclearcheckerlib__8022f418(i));

      r26->_0FE = CLAMP_8(r26->_0FE + kar_plclearcheckerlib__80230be8(i));

      r27 += kar_plclearcheckerlib__80230420(i);
      if (kar_plclearcheckerlib__8022f920(i) >= 0x32) {
        kar_gmclearchecker__8004a054(2, 0x4f);
      }
      if (kar_plclearcheckerlib__80230b90(i) != 0) {
        kar_gmclearchecker__8004a054(2, 0x30);
      }
      if (kar_plclearcheckerlib__80230b38(i) != 0) {
        kar_gmclearchecker__8004a054(2, 0x31);
      }
      if (kar_plclearcheckerlib__8022fa58(i) >= 8) {
        kar_gmclearchecker__8004a054(2, 0x34);
      }
      if (kar_plclearcheckerlib__8022fe28(i) != 0) {
        kar_gmclearchecker__8004a054(2, 0x36);
      }
      if (kar_plclearcheckerlib__8022fccc(i, 0x1d) != 0) {
        kar_gmclearchecker__8004a054(2, 0x3a);
      }
      if (kar_plclearcheckerlib__8022fccc(i, 0x20) != 0) {
        kar_gmclearchecker__8004a054(2, 0x3f);
      }
      if (kar_plclearcheckerlib__80230934(i) != 0) {
        kar_gmclearchecker__8004a054(2, 0x3e);
      }
      if (kar_plclearcheckerlib__8022fe80(i) != 0) {
        kar_gmclearchecker__8004a054(2, 0x38);
      }
      if (kar_plclearcheckerlib__80230240(i) != 0) {
        kar_gmclearchecker__8004a054(2, 0x42);
      }
      if (kar_plclearcheckerlib__8022fdc0(i) >= 0 &&
          kar_plclearcheckerlib__8022fdc0(i) <= 0x960) {
        kar_gmclearchecker__8004a054(2, 0x33);
      }
      if (kar_plclearcheckerlib__80230838(i) >= 5) {
        kar_gmclearchecker__8004a054(2, 0x39);
      }
      if (kar_plclearcheckerlib__8022ed50(i) != 0) {
        kar_gmclearchecker__8004a054(2, 0x46);
      }
      if (kar_plclearcheckerlib__8022eda8(i) != 0) {
        kar_gmclearchecker__8004a054(2, 0x47);
      }
      if (kar_plclearcheckerlib__8022faac(i) >= 0xa) {
        kar_gmclearchecker__8004a054(2, 0x48);
      }
      if (kar_plclearcheckerlib__8022ebdc(i) != 0) {
        kar_gmclearchecker__8004a054(2, 0x49);
      }
      if (kar_plclearcheckerlib__8022ec34(i) >= 3) {
        kar_gmclearchecker__8004a054(2, 0x4e);
      }

      sVar = kar_plclearchecker_get_state_u32_840(i);
      if (sVar != -1 && sVar <= 0x3c) {
        kar_gmclearchecker__8004a054(2, 0x4a);
      }

      if (kar_plclearcheckerlib__8022f898(i, 3) >= 10) {
        kar_gmclearchecker__8004a054(2, 0x50);
      }
      if (kar_plclearcheckerlib__8022f898(i, 5) >= 10) {
        kar_gmclearchecker__8004a054(2, 0x52);
      }
      if (kar_plclearcheckerlib__8022f898(i, 0xb) >= 10) {
        kar_gmclearchecker__8004a054(2, 0x54);
      }
      if (kar_plclearcheckerlib__8022f898(i, 0xf) >= 10) {
        kar_gmclearchecker__8004a054(2, 0x56);
      }
      if (kar_plclearcheckerlib__8022f898(i, 0x11) >= 10) {
        kar_gmclearchecker__8004a054(2, 0x58);
      }
      if (kar_plclearcheckerlib__8022f898(i, 9) >= 10) {
        kar_gmclearchecker__8004a054(2, 0x5a);
      }
      if (kar_plclearcheckerlib__8022f898(i, 0xd) >= 10) {
        kar_gmclearchecker__8004a054(2, 0x5c);
      }
      if (kar_plclearcheckerlib__8022f898(i, 0x27) >= 2) {
        kar_gmclearchecker__8004a054(2, 0x61);
      }
      if (kar_plclearcheckerlib__8022f898(i, 0x28) >= 3) {
        kar_gmclearchecker__8004a054(2, 0x62);
      }
      if (kar_plclearcheckerlib__8022f898(i, 0x30) >= 3) {
        kar_gmclearchecker__8004a054(2, 0x6b);
      }
      if (kar_plclearcheckerlib__8022f898(i, 0x31) >= 3) {
        kar_gmclearchecker__8004a054(2, 0x6c);
      }
    }
    if (kar_plclearcheckerlib__near_8022c858(i) != 4) {
      r31++;
      if (kar_plclearchecker_get_flag_854_bit3(i) != 0) {
        r22++;
      }
      if (kar_plclearchecker_get_flag_854_bit4(i) != 0) {
        r23++;
      }
      r24 += kar_plclearcheckerlib__8022fccc(i, 0x26);
      r30 += kar_plclearcheckerlib__8022fccc(i, 0x22);
      r29 += kar_plclearcheckerlib__8022fccc(i, 0x23);
      r28 += kar_plclearcheckerlib__8022fccc(i, 0x25);
      if (kar_plclearcheckerlib__80230c3c(i) != 0) {
        r20 = 1;
      }
      if (kar_plclearcheckerlib__80230c94(i) != 0) {
        r21 = 1;
      }
    }
  }
  if ((r26->_10C * 11.428572f) / 160934.4f >= 60.0f) {
    kar_gmclearchecker__8004a054(2, 0);
  }
  if ((r26->_10C * 11.428572f) / 160934.4f >= 200.0f) {
    kar_gmclearchecker__8004a054(2, 1);
  }
  if (r26->_0FB >= 0x1e) {
    kar_gmclearchecker__8004a054(2, 0x5d);
  }
  if (r26->_106 >= 100) {
    kar_gmclearchecker__8004a054(2, 2);
  }
  if (r26->_106 >= 500) {
    kar_gmclearchecker__8004a054(2, 3);
  }
  if (r26->_106 >= 1000) {
    kar_gmclearchecker__8004a054(2, 4);
  }
  if (r26->_106 >= 3000) {
    kar_gmclearchecker__8004a054(2, 5);
  }
  if (r26->_108 >= 500) {
    kar_gmclearchecker__8004a054(2, 7);
  }
  if (r26->_108 >= 1000) {
    kar_gmclearchecker__8004a054(2, 8);
  }
  if (r26->_0F8 >= 3) {
    kar_gmclearchecker__8004a054(2, 0x5e);
  }
  if (r26->_0F9 >= 3) {
    kar_gmclearchecker__8004a054(2, 0x5f);
  }
  if (r26->_0FA >= 10) {
    kar_gmclearchecker__8004a054(2, 0x60);
  }
  if (r26->_0F5 >= 5) {
    kar_gmclearchecker__8004a054(2, 0x32);
  }
  if (r26->_0F7 >= 10) {
    kar_gmclearchecker__8004a054(2, 0x3b);
  }
  if (r26->_0FC >= 10) {
    kar_gmclearchecker__8004a054(2, 0x43);
  }
  if (r26->_0FE >= 10) {
    kar_gmclearchecker__8004a054(2, 0x3d);
  }
  if (r26->_0FD >= 5) {
    kar_gmclearchecker__8004a054(2, 0x4d);
  }

  r26->_0F6 = CLAMP_8(r26->_0F6 + kar_greventgenerator_get_kind_use_count(2));

  if (r26->_0F6 >= 3) {
    kar_gmclearchecker__8004a054(2, 0x35);
  }

  if (r31 == r22) {
    kar_gmclearchecker__8004a054(2, 0x4b);
  }
  if (r31 == r23) {
    kar_gmclearchecker__8004a054(2, 0x4c);
  }
  if (r24 >= 0x1e) {
    kar_gmclearchecker__8004a054(2, 0x44);
  }
  if (r30 >= 0x35) {
    kar_gmclearchecker__8004a054(2, 0x45);
  }
  if (r29 >= 0x29) {
    kar_gmclearchecker__8004a054(2, 0x41);
  }
  if (r28 >= 3) {
    kar_gmclearchecker__8004a054(2, 0x3c);
  }
  if (r27 >= 3) {
    kar_gmclearchecker__8004a054(2, 0x40);
  }
  if (r20 != 0 && r21 != 0) {
    kar_gmclearchecker__8004a054(2, 0x77);
  }

  for (i = 0; i < 5; i++) {
    if (kar_plclearcheckerlib__near_8022c858(i) == 0) {
      if (kar_plclearcheckerlib__8022f3a4(i, 0) != 0) {
        kar_gmclearchecker__8004a054(2, 0x6f);
      }
      if (kar_plclearcheckerlib__8022f3a4(i, 1) != 0) {
        kar_gmclearchecker__8004a054(2, 0x70);
      }
      if (kar_plclearcheckerlib__8022f3a4(i, 2) != 0) {
        kar_gmclearchecker__8004a054(2, 0x71);
      }
      if (kar_plclearcheckerlib__8022f3a4(i, 3) != 0) {
        kar_gmclearchecker__8004a054(2, 0x72);
      }
      if (kar_plclearcheckerlib__8022f3a4(i, 4) != 0) {
        kar_gmclearchecker__8004a054(2, 0x73);
      }
      if (kar_plclearcheckerlib__8022f3a4(i, 5) != 0) {
        kar_gmclearchecker__8004a054(2, 0x74);
      }
      if (kar_plclearcheckerlib__8022f3a4(i, 6) != 0) {
        kar_gmclearchecker__8004a054(2, 0x75);
      }
      if (kar_plclearcheckerlib__8022f3a4(i, 7) != 0) {
        kar_gmclearchecker__8004a054(2, 0x76);
      }
    }
  }
}

void kar_gmclearchecker__near_8004e5b8(void) {
  if (kar_shadow__near_8007b650() != 0) {
    return;
  }
}

void kar_gmclearchecker__near_8004e5dc(void) {
  int i;
  kar_gmglobal__near_8000774c_s *r31 = kar_gmglobal__near_8000774c();
  int total = 0;

  if (kar_shadow__near_8007b650() != 0) {
    return;
  }

  for (i = 0; i < 5; i++) {
    if (kar_plclearcheckerlib__near_8022c858(i) == 0) {
      total += kar_plclearcheckerlib__80231510(i);
    }
  }
  r31->_110 += total;
}

void kar_gmclearchecker__near_8004e660(void) {
  int i;
  kar_gmglobal__near_8000774c_s *r31 = kar_gmglobal__near_8000774c();
  u32 total = 0;
  if (kar_shadow__near_8007b650() != 0) {
    return;
  }
  for (i = 0; i < 5; i++) {
    if (kar_plclearcheckerlib__near_8022c858(i) == 0) {
      if (kar_plclearcheckerlib__8022f19c(i) >= 10) {
        kar_gmclearchecker__8004a054(2, 6);
      }
      total += kar_plclearcheckerlib__80231510(i);
    }
  }
  total += r31->_110;
  if (total >= 36000) {
    kar_gmclearchecker__8004a054(2, 9);
  }
  if (total >= 108000) {
    kar_gmclearchecker__8004a054(2, 0xa);
  }
  if (total >= 432000) {
    kar_gmclearchecker__8004a054(2, 0xb);
  }
}

s32 kar_gmclearchecker__near_8004e748(void) {
  int i, total;
  kar_gmglobal__near_8000774c_s *unused = kar_gmglobal__near_8000774c();
  int ret = 0;

  for (i = 0, total = 0; i < 24; i++) {
    total += fn_8000C228(i) != 0 ? 1 : 0;
  }

  if (total >= 10) {
    kar_gmclearchecker__8004a054(2, 12);
    if ((kar_gmclearchecker__8004a130(2, 12) & 4) == 0) {
      ret++;
    }
  }
  if (total >= 20) {
    kar_gmclearchecker__8004a054(2, 13);
    if ((kar_gmclearchecker__8004a130(2, 13) & 4) == 0) {
      ret++;
    }
  }
  return ret;
}

void kar_gmclearchecker__near_8004e810(void) {
  GmMainData *r30;
  kar_gmglobal__near_8000774c_s *r31;
  GmMainData_830 *r29;
  int i;

  r30 = kar_gmmain__near_80006c14();
  r29 = &r30->_830;
  r31 = kar_gmglobal__near_8000774c();

  for (i = 0; i < 5; i++) {
    if (kar_plclearcheckerlib__near_8022c858(i) == 0) {
      switch (r30->_A94) {
      case 11:
        if (r29->_022[i] != 0) {
          if (r29->_21C[i] / 0.304788f >= 500.0f) {
            kar_gmclearchecker__8004a054(2, 0x16);
          }
          if (r29->_21C[i] / 0.304788f >= 1000.0f) {
            kar_gmclearchecker__8004a054(2, 0x17);
          }
          if (kar_plclearcheckerlib__802315c0(i) >= 600) {
            kar_gmclearchecker__8004a054(2, 0x18);
          }
        }
        break;
      case 9:
        if (r29->_022[i] != 0) {
          r31->_100 = CLAMP_16(r31->_100 + r29->_208[i]);
          if (kar_plclearcheckerlib__802315c0(i) >= 900) {
            kar_gmclearchecker__8004a054(2, 0x1c);
          }
        }
        break;
      }
    }
  }

  switch (r30->_A94) {
  case 9:
    if (r31->_100 >= 1500) {
      kar_gmclearchecker__8004a054(2, 0x1e);
    }
  }
}

void kar_gmclearchecker__near_8004e998(void) {
  GmMainData *r30 = kar_gmmain__near_80006c14();
  GmMainData_830 *r28 = &r30->_830;
  kar_gmglobal__near_8000774c_s *r31 = kar_gmglobal__near_8000774c();
  s32 i;
  u32 r26 = 0;

  if (kar_shadow__near_8007b650() != 0) {
    return;
  }

  (void)kar_gmclearchecker__near_8004e748(); // inline

  for (i = 0; i < 5; i++) {
    if (kar_plclearcheckerlib__near_8022c858(i) == 0) {
      switch (r30->_A94) {
      case 7:
        switch (r30->_5AD) {
        case 0:
          if (r28->_022[i] != 0) {
            if (r28->_088[i] <= 1440) {
              kar_gmclearchecker__8004a054(2, 0xe);
            }
            if (r28->_088[i] <= 1200) {
              kar_gmclearchecker__8004a054(2, 0xf);
            }
            if (kar_plclearcheckerlib__near_8022c8b0(i) == 0 &&
                kar_plclearcheckerlib__near_8022c8e0(i) == 0 &&
                r28->_088[i] <= 1560) {
              kar_gmclearchecker__8004a054(2, 0x63);
            }
            if (kar_plclearcheckerlib__near_8022c8b0(i) == 0 &&
                kar_plclearcheckerlib__near_8022c8e0(i) == 7 &&
                r28->_088[i] <= 1020) {
              kar_gmclearchecker__8004a054(2, 0x64);
            }
          }
          break;
        case 1:
          if (r28->_022[i] != 0) {
            if (r28->_088[i] <= 1440) {
              kar_gmclearchecker__8004a054(2, 0x10);
            }
            if (r28->_088[i] <= 1200) {
              kar_gmclearchecker__8004a054(2, 0x11);
            }
            if (kar_plclearcheckerlib__near_8022c8b0(i) == 0 &&
                kar_plclearcheckerlib__near_8022c8e0(i) == 9 &&
                r28->_088[i] <= 1620) {
              kar_gmclearchecker__8004a054(2, 0x65);
            }
            if (kar_plclearcheckerlib__near_8022c8b0(i) == 0 &&
                kar_plclearcheckerlib__near_8022c8e0(i) == 2 &&
                r28->_088[i] <= 1740) {
              kar_gmclearchecker__8004a054(2, 0x66);
            }
          }
          break;
        case 2:
          if (r28->_022[i] != 0) {
            if (r28->_088[i] <= 2100) {
              kar_gmclearchecker__8004a054(2, 0x12);
            }
            if (r28->_088[i] <= 1620) {
              kar_gmclearchecker__8004a054(2, 0x13);
            }
            if (kar_plclearcheckerlib__near_8022c8b0(i) == 0 &&
                kar_plclearcheckerlib__near_8022c8e0(i) == 0xb &&
                r28->_088[i] <= 1680) {
              kar_gmclearchecker__8004a054(2, 0x67);
            }
            if (kar_plclearcheckerlib__near_8022c8b0(i) == 1 &&
                kar_plclearcheckerlib__near_8022c8e0(i) == 2 &&
                r28->_088[i] <= 1860) {
              kar_gmclearchecker__8004a054(2, 0x68);
            }
          }
          break;
        case 3:
          if (r28->_022[i] != 0) {
            if (r28->_088[i] <= 1440) {
              kar_gmclearchecker__8004a054(2, 0x14);
            }
            if (r28->_088[i] <= 1140) {
              kar_gmclearchecker__8004a054(2, 0x15);
            }
            if (kar_plclearcheckerlib__near_8022c8b0(i) == 0 &&
                kar_plclearcheckerlib__near_8022c8e0(i) == 0xc &&
                r28->_088[i] <= 1980) {
              kar_gmclearchecker__8004a054(2, 0x69);
            }
            if (kar_plclearcheckerlib__near_8022c8b0(i) == 1 &&
                kar_plclearcheckerlib__near_8022c8e0(i) == 3 &&
                r28->_088[i] <= 1440) {
              kar_gmclearchecker__8004a054(2, 0x6a);
            }
          }
          break;
        }
        break;
      case 9:
        if (r28->_022[i] != 0) {
          if (r28->_208[i] >= 150) {
            kar_gmclearchecker__8004a054(2, 0x19);
          }
          if (r28->_208[i] >= 200) {
            kar_gmclearchecker__8004a054(2, 0x1b);
          }
          if (r28->_208[i] == 90) {
            kar_gmclearchecker__8004a054(2, 0x1a);
          }
        }
        break;
      case 8:
        if (r28->_022[i] != 0) {
          if (r28->_21C[i] / 0.304788f >= 330.0f) {
            kar_gmclearchecker__8004a054(2, 0x1f);
          }
          if (r28->_21C[i] / 0.304788f >= 660.0f) {
            kar_gmclearchecker__8004a054(2, 0x20);
          }
          if (r28->_21C[i] / 0.304788f >= 1300.0f) {
            kar_gmclearchecker__8004a054(2, 0x21);
          }
          if (kar_plclearcheckerlib__802315c0(i) >= 1800) {
            kar_gmclearchecker__8004a054(2, 0x22);
          }
        }
        break;
      case 14:
        r31->_102 = CLAMP_16(r31->_102 + r28->_208[i]);
        break;
      case 13:
        r31->_104 = CLAMP_16(r31->_104 + r28->_208[i]);
        break;
      case 18: {
        u32 uVar = kar_plclearcheckerlib__8022f568(i);
        if (uVar > 0 && uVar <= 3600) {
          kar_gmclearchecker__8004a054(2, 0x2f);
        }
      } break;
      }
    }
    if (kar_plclearcheckerlib__near_8022c858(i) != 4 && r30->_A94 == 0xe &&
        r30->_5AD == 9) {
      r26 += kar_plclearcheckerlib__8022fccc(i, 0x17);
    }
  }

  switch (r30->_A94) {
  case 9:
    r31->_0F4 = CLAMP_8(r31->_0F4 + 1);
    if (r31->_0F4 >= 0xf) {
      kar_gmclearchecker__8004a054(2, 0x1d);
    }
    break;
  case 0xe:
    if (r31->_102 >= 0x32) {
      kar_gmclearchecker__8004a054(2, 0x29);
    }
    if (r31->_102 >= 0x96) {
      kar_gmclearchecker__8004a054(2, 0x2a);
    }
    if (r26 >= 2) {
      kar_gmclearchecker__8004a054(2, 0x28);
    }
    break;
  case 0xd:
    if (r31->_104 >= 0x1f4) {
      kar_gmclearchecker__8004a054(2, 0x2d);
    }
    if (r31->_104 >= 0x5dc) {
      kar_gmclearchecker__8004a054(2, 0x2e);
    }
    break;
  }
}

void kar_gmclearchecker__near_8004f03c(void) {
  GmMainData *r31 = kar_gmmain__near_80006c14();
  GmMainData_830 *r30 = &r31->_830;
  int i;
  if (kar_shadow__near_8007b650() != 0) {
    return;
  }
  for (i = 0; i < 5; i++) {
    if (kar_plclearcheckerlib__near_8022c858(i) == 0)
    {
      switch (r31->_A94) {
      case 0xe:
        switch (r31->_5AD) {
        case 9:
          if (r30->_208[i] >= 5) {
            kar_gmclearchecker__8004a054(2, 0x23);
          }
          if (r30->_208[i] >= 10) {
            kar_gmclearchecker__8004a054(2, 0x51);
          }
          break;
        
          case 10:
          if (r30->_208[i] >= 5) {
            kar_gmclearchecker__8004a054(2, 0x24);
          }
          if (r30->_208[i] >= 10) {
            kar_gmclearchecker__8004a054(2, 0x53);
          }
          break;

        case 0xb:
          if (r30->_208[i] >= 5) {
            kar_gmclearchecker__8004a054(2, 0x25);
          }
          break;

        case 0xc:
          if (r30->_208[i] >= 5) {
            kar_gmclearchecker__8004a054(2, 0x26);
          }
          if (r30->_208[i] >= 10) {
            kar_gmclearchecker__8004a054(2, 0x55);
          }
          break;

        case 0xd:
          if (r30->_208[i] >= 5) {
            kar_gmclearchecker__8004a054(2, 0x27);
          }
          if (r30->_208[i] >= 10) {
            kar_gmclearchecker__8004a054(2, 0x57);
          }
          break;
        }
        break;
      case 0xd:
        switch (r31->_5AD) {
        case 7:
          if (r30->_208[i] >= 50) {
            kar_gmclearchecker__8004a054(2, 0x2b);
          }
          if (r30->_208[i] >= 75) {
            kar_gmclearchecker__8004a054(2, 0x59);
          }
          break;
        case 8:
          if (r30->_208[i] >= 30) {
            kar_gmclearchecker__8004a054(2, 0x2c);
          }
          if (r30->_208[i] >= 40) {
            kar_gmclearchecker__8004a054(2, 0x5b);
          }
          break;
        }
        break;
      }
    }
  }
}

void kar_gmclearchecker__near_8004f270(void) {
  int r31 = kar_lbaudio_alloc_weapon_track_subtype_0();
  int r30 = kar_lbaudio__near_8005dbc8();

  switch (HSD_Randi(4)) {
  case 0:
    kar_lbaudio_start_track(0x12002e, r31, r30);
    break;
  case 1:
    kar_lbaudio_start_track(0x12002f, r31, r30);
    break;
  case 2:
    kar_lbaudio_start_track(0x120030, r31, r30);
    break;
  case 3:
    kar_lbaudio_start_track(0x120031, r31, r30);
    break;
  }
}

void kar_gmclearchecker__near_8004f33c(void) { fn_80282300(); }

void kar_gmclearchecker__near_8004f35c(void) { fn_8028236C(); }

void kar_gmclearchecker__near_8004f37c(void) { fn_80282004(); }

void kar_gmclearchecker__near_8004f39c(void) {
  fn_80281F10();
  fn_80281ECC(7);
}

void kar_gmclearchecker__near_8004f3c4(void) {
  lbl_805DD598 = 0;
  kar_pltrick__near_802339e4();
  kar_lbarealightzone__near_8007adb8();
  fn_80281660();
  fn_80281AD4();
  fn_80281BB4();
  fn_802823FC(1);
  kar_lbaudio__near_8005ab84();
  kar_lbaudio__near_8005e1a8(0x2c);
  kar_lbaudio__near_8005a5b0();
  kar_lbvector__near_8006595c();
}

void kar_gmclearchecker__near_8004f418(void) {
  kar_lbaudio__near_8005e5d0();
  if (kar_gmracenormal__8000aea8() == 12) {
    kar_gmlanmenu__800082a0(0x10);
    kar_gmlanmenu__80008220();
  }
}

static inline
void kar_gmclearchecker__near_8004f454_inline(void) {
  lbl_80497768_sub *a;
  int r31 = (int)fn_80281A0C();

  if (fn_802819CC() == 0) {
    a = lbl_80497768;
    r31++;
    for (; a->_0 >= 0; a++) {
      if (r31 == a->_0) {
        if (a->_4 != NULL) {
          a->_4(r31);
        }
        if (a->_8 != 17) {
          fn_8028208C(a->_8);
          fn_80281F4C(a->_8);
        }
      }
      if (r31 == a->_0) {
        if (a->_C != 17) {
          fn_80282058(a->_C);
          fn_80281FA8(a->_C);
        }
      }
    }
  }
}

void kar_gmclearchecker__near_8004f454(void) {
  if (fn_802819CC()) {
    if (lbl_805DD598 == 0) {
      fn_80281904();
    }
    if (fn_802819E8() == 0) {
      fn_8028196C();
    }
    lbl_805DD598 = 1;
  } else {
    lbl_805DD598 = 0;
  }

  kar_gmclearchecker__near_8004f454_inline();
  if (fn_80282F70() == 0) {
    if (lbl_8058B634._8 & 0x1000) {
      fn_80282EC8(60);
    }
    if (fn_80281610() != 0) {
      fn_80282EC8(60);
    }
  } else if (fn_80282F38() != 0) {
    kar_gmglobal__near_800088c8(-1);
    kar_gmmain__near_800064f0();
  }
}

void kar_gmclearchecker__near_8004f5b0(void) { shadowRendering(); }

void *kar_gmclearchecker__near_8004f5d0(void) { return lbl_80497B9C[0]; }
