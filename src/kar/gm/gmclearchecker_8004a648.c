#include "functions.h"
#include <dolphin/types.h>
#include "kar/gm/gmglobal.h"
#include "kar/gm/gmclearchecker.h"
#include "kar/gm/gmclearchecker_8004a648.h"

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
extern f32 fn_80009568(int);
extern u32 kar_plclearcheckerlib__8022fccc(int, int);
extern s8 fn_8000916C(void);
extern int fn_8000A0F8(void);
extern int kar_plclearchecker_get_state_u32_82c(int);
extern u8 *kar_grlib2__near_800d57b0(void);
extern s8 fn_80009534(int);
extern int kar_plclearcheckerlib__802307e4(int);
extern int kar_plclearcheckerlib__8023077c(int, int);
extern u32 kar_plclearchecker_get_state_u32_7d4(int);
extern u32 kar_plclearchecker_get_state_u32_7d8(int);
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

typedef int (*GmClearCheckerPredicate)(int number);

GmClearCheckerPredicate AirRide_ClearCheckerMainPredicates[30] = {
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

GmClearCheckerPredicate AirRide_ClearCheckerSecondaryPredicates[] = {
	&kar_gmclearchecker__near_8004ad90,
	&kar_gmclearchecker__near_8004ad90,
	&kar_gmclearchecker__near_8004aef8,
	&kar_gmclearchecker__near_8004aef8,
	&kar_gmclearchecker__near_8004b354,
	&kar_gmclearchecker__near_8004b4b4,
	&kar_gmclearchecker__near_8004b8b4,
	&kar_gmclearchecker__near_8004ba08,
	&kar_gmclearchecker__near_8004babc,
	&kar_gmclearchecker__near_8004bb64,
	&kar_gmclearchecker__near_8004c254,
	&kar_gmclearchecker__near_8004c3bc,
	&kar_gmclearchecker__near_8004c430,
	&kar_gmclearchecker__near_8004cce8,
	&kar_gmclearchecker__near_8004cf6c,
	&kar_gmclearchecker__near_8004d0e8,
	&kar_gmclearchecker__near_8004d1d4,
};

u8 AirRide_ClearCheckerMainRewardKinds[] = {
    0x00, 0x01, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x10, 0x1C, 0x1E, 0x55,
    0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5F, 0x62, 0x63, 0x64,
    0x65, 0x66, 0x67, 0x68, 0x6A, 0x6D, 0x6E, 0x70,
};

u8 AirRide_ClearCheckerSecondaryRewardKinds[] = {
    0x02, 0x03, 0x04, 0x05, 0x0E, 0x0F, 0x1F, 0x20, 0x53, 0x54,
    0x5E, 0x60, 0x61, 0x6B, 0x6F, 0x72, 0x74,
};

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
    kar_gmglobal__near_800088c8(++minor > 0x22 ? 0x20 : minor);
    kar_gmmain__near_800064f0();
    break;
  case 0xD:
    kar_lbaudio__near_8006176c(0x1000A);
    minor = fn_8000AECC();
    kar_gmglobal__near_800088c8(--minor < 0x20 ? 0x22 : minor);
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

void Checklist_LoadScreenResources(void) {
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

void Checklist_UnloadScreenResources(void) { fn_80138E00(); }

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
        number = AirRide_ClearCheckerSecondaryRewardKinds[index];
        if ((ClearChecker_GetClearKindFlags(0, number) & 5) == 0) {
          index = main->clearchecker_index;
          predicate = AirRide_ClearCheckerSecondaryPredicates[index];
          if (predicate != NULL && predicate(number) == 1) {
            ClearChecker_SetNewUnlock(0, number);
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

void AirRide_UpdateClearCheckerUnlocksAndTotals(void) {
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
        number = AirRide_ClearCheckerMainRewardKinds[i];
        if ((ClearChecker_GetClearKindFlags(0, number) & 5) == 0) {
          GmClearCheckerPredicate predicate = AirRide_ClearCheckerMainPredicates[i];

          if (predicate != NULL && predicate(number) == 1) {
            ClearChecker_SetNewUnlock(0, number);
          }
        }
      }

      if (fn_8000916C() == 1) {
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

static inline int kar_gmclearchecker__near_8004b578_sub(void) {
  int i;
  for (i = 0; i < 5; i++) {
    if (kar_plclearcheckerlib__near_8022c858(i) == 0 && fn_8000979C(i) != 0) {
      return 1;
    }
  }
  return 0;
}

inline int kar_gmclearchecker__near_8004afc0_sub(void) {
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

s32 kar_gmclearchecker__near_8004b1d0(void) {
  GmGlobalData *global;
  s32 i;
  s32 total;

  global = kar_gmglobal__near_8000771c();
  total = global->clearchecker_total_3;
  for (i = 0; i < 5; i++) {
    if (kar_plclearcheckerlib__near_8022c858(i) == 0) {
      if (fn_8000979C(i) != 0) {
        total++;
      }
    }
  }

  return total;
}

int kar_gmclearchecker__near_8004b23c(int type) {
  GmGlobalData *global;
  s32 total;
  s32 i;

  global = kar_gmglobal__near_8000771c();
  total = global->clearchecker_total_3;
  for (i = 0; i < 5; i++) {
    if (kar_plclearcheckerlib__near_8022c858(i) == 0) {
      if (fn_8000979C(i) != 0) {
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

int kar_gmclearchecker__near_8004b354(int unused) {
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

int kar_gmclearchecker__near_8004b4b4(int unused) {
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

int kar_gmclearchecker__near_8004b8b4(int unused) {
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

int kar_gmclearchecker__near_8004ba08(int unused) {
  u32 total = kar_gmclearchecker__near_8004b968();
  if (total >= 0x14) {
    return 1;
  } else {
    return 0;
  }
}

int kar_gmclearchecker__near_8004babc(int unused) {
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
  bit = 1 << fn_80261CE8(fn_800092D8());
  total |= bit;
  return total;
}

int kar_gmclearchecker__near_8004bb64(int unused) {
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
          kar_plclearcheckerlib__80230728(i) >= 20) {
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
          kar_plclearcheckerlib__80230728(i) >= 20) {
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
          kar_plclearcheckerlib__8023098c(i) >= 2) {
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
          kar_plclearcheckerlib__80230728(i) >= 20) {
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
          kar_plclearchecker_get_state_u32_7fc(i) == 3) {
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
          kar_plclearcheckerlib__80230a88(i) == 0) {
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

int kar_gmclearchecker__near_8004d0e8(int unused) {
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

int kar_gmclearchecker__near_8004d1d4(int unused) {
  if (fn_80261CE8(fn_800092D8()) == 4) {
    int i;
    for (i = 0; i < 5; i++) {
      if (kar_plclearcheckerlib__near_8022c858(i) == 0 &&
          kar_plclearcheckerlib__8023088c(i) != 0) {
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
  if (fn_802625F8() == fn_80009190()) {
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
        if (((u8)ClearChecker_GetClearKindFlags(0, (u8)a[i]) & 0x5) == 0) {
          ClearChecker_SetNewUnlock(0, (u8)a[i]);
        }
      }
    }
  }
}

void kar_gmclearchecker__near_8004d454(void) {
  int r30 = 0;
  int r31 = fn_80261CE8(fn_800092D8());
  s32 r29;
  int r28 = fn_800091E4() * 60;
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
          (ClearChecker_GetClearKindFlags(0, r29) & 5) == 0) {
        ClearChecker_SetNewUnlock(0, r29);
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
          (ClearChecker_GetClearKindFlags(0, (u8)sp8[i]) & 5) == 0) {
        ClearChecker_SetNewUnlock(0, (u8)sp8[i]);
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
          (ClearChecker_GetClearKindFlags(0, (u8)sp8[i]) & 5) == 0) {
        ClearChecker_SetNewUnlock(0, (u8)sp8[i]);
      }
    }
  }
}
