#include "functions.h"
#include <dolphin/types.h>
#include "kar/gm/gmglobal.h"
#include "kar/gm/gmclearchecker.h"
#include "kar/gm/gmclearchecker_8004db74.h"
#include "kar/gm/gmmain.h"
#include "kar/shadow.h"

typedef struct {
  /* 0x0 */ u32 _0;
  /* 0x4 */ u32 _4;
  /* 0x8 */ u32 _8;
} HSD_PadCopyStatus_s;

extern HSD_PadCopyStatus_s HSD_PadCopyStatus;

extern GmMainData *kar_gmmain__near_80006c14(void);
extern s8 kar_gmracenormal__8000aea8(void);
extern s32 kar_plclearcheckerlib__near_8022c858(s32 arg0);
extern f32 fn_80281A0C(void);
extern s8 fn_8000C228(s8);
extern u32 kar_plclearcheckerlib__8022fccc(int, int);
extern void kar_lbaudio__near_8005e5d0(void);
extern void kar_gmlanmenu__800082a0(int);
extern void kar_gmlanmenu__80008220(void);
extern int fn_80282F70(void);
extern int fn_80281610(void);
extern int fn_80282F38(void);
extern void fn_80282EC8(int);
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
extern u32 kar_plclearcheckerlib__8022f19c(int);
extern int HSD_Randi(int);
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

static int lbl_805DD598 = 0;

inline
u16 CLAMP_16(u32 i) { return i > 0xffff ? 0xffff : (u16)i; }

inline
u8 CLAMP_8(u32 i) { return i > 0xff ? 0xff : (u8)i; }

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
        ClearChecker_SetNewUnlock(2, 0x4f);
      }
      if (kar_plclearcheckerlib__80230b90(i) != 0) {
        ClearChecker_SetNewUnlock(2, 0x30);
      }
      if (kar_plclearcheckerlib__80230b38(i) != 0) {
        ClearChecker_SetNewUnlock(2, 0x31);
      }
      if (kar_plclearcheckerlib__8022fa58(i) >= 8) {
        ClearChecker_SetNewUnlock(2, 0x34);
      }
      if (kar_plclearcheckerlib__8022fe28(i) != 0) {
        ClearChecker_SetNewUnlock(2, 0x36);
      }
      if (kar_plclearcheckerlib__8022fccc(i, 0x1d) != 0) {
        ClearChecker_SetNewUnlock(2, 0x3a);
      }
      if (kar_plclearcheckerlib__8022fccc(i, 0x20) != 0) {
        ClearChecker_SetNewUnlock(2, 0x3f);
      }
      if (kar_plclearcheckerlib__80230934(i) != 0) {
        ClearChecker_SetNewUnlock(2, 0x3e);
      }
      if (kar_plclearcheckerlib__8022fe80(i) != 0) {
        ClearChecker_SetNewUnlock(2, 0x38);
      }
      if (kar_plclearcheckerlib__80230240(i) != 0) {
        ClearChecker_SetNewUnlock(2, 0x42);
      }
      if (kar_plclearcheckerlib__8022fdc0(i) >= 0 &&
          kar_plclearcheckerlib__8022fdc0(i) <= 0x960) {
        ClearChecker_SetNewUnlock(2, 0x33);
      }
      if (kar_plclearcheckerlib__80230838(i) >= 5) {
        ClearChecker_SetNewUnlock(2, 0x39);
      }
      if (kar_plclearcheckerlib__8022ed50(i) != 0) {
        ClearChecker_SetNewUnlock(2, 0x46);
      }
      if (kar_plclearcheckerlib__8022eda8(i) != 0) {
        ClearChecker_SetNewUnlock(2, 0x47);
      }
      if (kar_plclearcheckerlib__8022faac(i) >= 0xa) {
        ClearChecker_SetNewUnlock(2, 0x48);
      }
      if (kar_plclearcheckerlib__8022ebdc(i) != 0) {
        ClearChecker_SetNewUnlock(2, 0x49);
      }
      if (kar_plclearcheckerlib__8022ec34(i) >= 3) {
        ClearChecker_SetNewUnlock(2, 0x4e);
      }

      sVar = kar_plclearchecker_get_state_u32_840(i);
      if (sVar != -1 && sVar <= 0x3c) {
        ClearChecker_SetNewUnlock(2, 0x4a);
      }

      if (kar_plclearcheckerlib__8022f898(i, 3) >= 10) {
        ClearChecker_SetNewUnlock(2, 0x50);
      }
      if (kar_plclearcheckerlib__8022f898(i, 5) >= 10) {
        ClearChecker_SetNewUnlock(2, 0x52);
      }
      if (kar_plclearcheckerlib__8022f898(i, 0xb) >= 10) {
        ClearChecker_SetNewUnlock(2, 0x54);
      }
      if (kar_plclearcheckerlib__8022f898(i, 0xf) >= 10) {
        ClearChecker_SetNewUnlock(2, 0x56);
      }
      if (kar_plclearcheckerlib__8022f898(i, 0x11) >= 10) {
        ClearChecker_SetNewUnlock(2, 0x58);
      }
      if (kar_plclearcheckerlib__8022f898(i, 9) >= 10) {
        ClearChecker_SetNewUnlock(2, 0x5a);
      }
      if (kar_plclearcheckerlib__8022f898(i, 0xd) >= 10) {
        ClearChecker_SetNewUnlock(2, 0x5c);
      }
      if (kar_plclearcheckerlib__8022f898(i, 0x27) >= 2) {
        ClearChecker_SetNewUnlock(2, 0x61);
      }
      if (kar_plclearcheckerlib__8022f898(i, 0x28) >= 3) {
        ClearChecker_SetNewUnlock(2, 0x62);
      }
      if (kar_plclearcheckerlib__8022f898(i, 0x30) >= 3) {
        ClearChecker_SetNewUnlock(2, 0x6b);
      }
      if (kar_plclearcheckerlib__8022f898(i, 0x31) >= 3) {
        ClearChecker_SetNewUnlock(2, 0x6c);
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
    ClearChecker_SetNewUnlock(2, 0);
  }
  if ((r26->_10C * 11.428572f) / 160934.4f >= 200.0f) {
    ClearChecker_SetNewUnlock(2, 1);
  }
  if (r26->_0FB >= 0x1e) {
    ClearChecker_SetNewUnlock(2, 0x5d);
  }
  if (r26->_106 >= 100) {
    ClearChecker_SetNewUnlock(2, 2);
  }
  if (r26->_106 >= 500) {
    ClearChecker_SetNewUnlock(2, 3);
  }
  if (r26->_106 >= 1000) {
    ClearChecker_SetNewUnlock(2, 4);
  }
  if (r26->_106 >= 3000) {
    ClearChecker_SetNewUnlock(2, 5);
  }
  if (r26->_108 >= 500) {
    ClearChecker_SetNewUnlock(2, 7);
  }
  if (r26->_108 >= 1000) {
    ClearChecker_SetNewUnlock(2, 8);
  }
  if (r26->_0F8 >= 3) {
    ClearChecker_SetNewUnlock(2, 0x5e);
  }
  if (r26->_0F9 >= 3) {
    ClearChecker_SetNewUnlock(2, 0x5f);
  }
  if (r26->_0FA >= 10) {
    ClearChecker_SetNewUnlock(2, 0x60);
  }
  if (r26->_0F5 >= 5) {
    ClearChecker_SetNewUnlock(2, 0x32);
  }
  if (r26->_0F7 >= 10) {
    ClearChecker_SetNewUnlock(2, 0x3b);
  }
  if (r26->_0FC >= 10) {
    ClearChecker_SetNewUnlock(2, 0x43);
  }
  if (r26->_0FE >= 10) {
    ClearChecker_SetNewUnlock(2, 0x3d);
  }
  if (r26->_0FD >= 5) {
    ClearChecker_SetNewUnlock(2, 0x4d);
  }

  r26->_0F6 = CLAMP_8(r26->_0F6 + kar_greventgenerator_get_kind_use_count(2));

  if (r26->_0F6 >= 3) {
    ClearChecker_SetNewUnlock(2, 0x35);
  }

  if (r31 == r22) {
    ClearChecker_SetNewUnlock(2, 0x4b);
  }
  if (r31 == r23) {
    ClearChecker_SetNewUnlock(2, 0x4c);
  }
  if (r24 >= 0x1e) {
    ClearChecker_SetNewUnlock(2, 0x44);
  }
  if (r30 >= 0x35) {
    ClearChecker_SetNewUnlock(2, 0x45);
  }
  if (r29 >= 0x29) {
    ClearChecker_SetNewUnlock(2, 0x41);
  }
  if (r28 >= 3) {
    ClearChecker_SetNewUnlock(2, 0x3c);
  }
  if (r27 >= 3) {
    ClearChecker_SetNewUnlock(2, 0x40);
  }
  if (r20 != 0 && r21 != 0) {
    ClearChecker_SetNewUnlock(2, 0x77);
  }

  for (i = 0; i < 5; i++) {
    if (kar_plclearcheckerlib__near_8022c858(i) == 0) {
      if (kar_plclearcheckerlib__8022f3a4(i, 0) != 0) {
        ClearChecker_SetNewUnlock(2, 0x6f);
      }
      if (kar_plclearcheckerlib__8022f3a4(i, 1) != 0) {
        ClearChecker_SetNewUnlock(2, 0x70);
      }
      if (kar_plclearcheckerlib__8022f3a4(i, 2) != 0) {
        ClearChecker_SetNewUnlock(2, 0x71);
      }
      if (kar_plclearcheckerlib__8022f3a4(i, 3) != 0) {
        ClearChecker_SetNewUnlock(2, 0x72);
      }
      if (kar_plclearcheckerlib__8022f3a4(i, 4) != 0) {
        ClearChecker_SetNewUnlock(2, 0x73);
      }
      if (kar_plclearcheckerlib__8022f3a4(i, 5) != 0) {
        ClearChecker_SetNewUnlock(2, 0x74);
      }
      if (kar_plclearcheckerlib__8022f3a4(i, 6) != 0) {
        ClearChecker_SetNewUnlock(2, 0x75);
      }
      if (kar_plclearcheckerlib__8022f3a4(i, 7) != 0) {
        ClearChecker_SetNewUnlock(2, 0x76);
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
        ClearChecker_SetNewUnlock(2, 6);
      }
      total += kar_plclearcheckerlib__80231510(i);
    }
  }
  total += r31->_110;
  if (total >= 36000) {
    ClearChecker_SetNewUnlock(2, 9);
  }
  if (total >= 108000) {
    ClearChecker_SetNewUnlock(2, 0xa);
  }
  if (total >= 432000) {
    ClearChecker_SetNewUnlock(2, 0xb);
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
    ClearChecker_SetNewUnlock(2, 12);
    if ((ClearChecker_GetClearKindFlags(2, 12) & 4) == 0) {
      ret++;
    }
  }
  if (total >= 20) {
    ClearChecker_SetNewUnlock(2, 13);
    if ((ClearChecker_GetClearKindFlags(2, 13) & 4) == 0) {
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
            ClearChecker_SetNewUnlock(2, 0x16);
          }
          if (r29->_21C[i] / 0.304788f >= 1000.0f) {
            ClearChecker_SetNewUnlock(2, 0x17);
          }
          if (kar_plclearcheckerlib__802315c0(i) >= 600) {
            ClearChecker_SetNewUnlock(2, 0x18);
          }
        }
        break;
      case 9:
        if (r29->_022[i] != 0) {
          r31->_100 = CLAMP_16(r31->_100 + r29->_208[i]);
          if (kar_plclearcheckerlib__802315c0(i) >= 900) {
            ClearChecker_SetNewUnlock(2, 0x1c);
          }
        }
        break;
      }
    }
  }

  switch (r30->_A94) {
  case 9:
    if (r31->_100 >= 1500) {
      ClearChecker_SetNewUnlock(2, 0x1e);
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
              ClearChecker_SetNewUnlock(2, 0xe);
            }
            if (r28->_088[i] <= 1200) {
              ClearChecker_SetNewUnlock(2, 0xf);
            }
            if (kar_plclearcheckerlib__near_8022c8b0(i) == 0 &&
                kar_plclearcheckerlib__near_8022c8e0(i) == 0 &&
                r28->_088[i] <= 1560) {
              ClearChecker_SetNewUnlock(2, 0x63);
            }
            if (kar_plclearcheckerlib__near_8022c8b0(i) == 0 &&
                kar_plclearcheckerlib__near_8022c8e0(i) == 7 &&
                r28->_088[i] <= 1020) {
              ClearChecker_SetNewUnlock(2, 0x64);
            }
          }
          break;
        case 1:
          if (r28->_022[i] != 0) {
            if (r28->_088[i] <= 1440) {
              ClearChecker_SetNewUnlock(2, 0x10);
            }
            if (r28->_088[i] <= 1200) {
              ClearChecker_SetNewUnlock(2, 0x11);
            }
            if (kar_plclearcheckerlib__near_8022c8b0(i) == 0 &&
                kar_plclearcheckerlib__near_8022c8e0(i) == 9 &&
                r28->_088[i] <= 1620) {
              ClearChecker_SetNewUnlock(2, 0x65);
            }
            if (kar_plclearcheckerlib__near_8022c8b0(i) == 0 &&
                kar_plclearcheckerlib__near_8022c8e0(i) == 2 &&
                r28->_088[i] <= 1740) {
              ClearChecker_SetNewUnlock(2, 0x66);
            }
          }
          break;
        case 2:
          if (r28->_022[i] != 0) {
            if (r28->_088[i] <= 2100) {
              ClearChecker_SetNewUnlock(2, 0x12);
            }
            if (r28->_088[i] <= 1620) {
              ClearChecker_SetNewUnlock(2, 0x13);
            }
            if (kar_plclearcheckerlib__near_8022c8b0(i) == 0 &&
                kar_plclearcheckerlib__near_8022c8e0(i) == 0xb &&
                r28->_088[i] <= 1680) {
              ClearChecker_SetNewUnlock(2, 0x67);
            }
            if (kar_plclearcheckerlib__near_8022c8b0(i) == 1 &&
                kar_plclearcheckerlib__near_8022c8e0(i) == 2 &&
                r28->_088[i] <= 1860) {
              ClearChecker_SetNewUnlock(2, 0x68);
            }
          }
          break;
        case 3:
          if (r28->_022[i] != 0) {
            if (r28->_088[i] <= 1440) {
              ClearChecker_SetNewUnlock(2, 0x14);
            }
            if (r28->_088[i] <= 1140) {
              ClearChecker_SetNewUnlock(2, 0x15);
            }
            if (kar_plclearcheckerlib__near_8022c8b0(i) == 0 &&
                kar_plclearcheckerlib__near_8022c8e0(i) == 0xc &&
                r28->_088[i] <= 1980) {
              ClearChecker_SetNewUnlock(2, 0x69);
            }
            if (kar_plclearcheckerlib__near_8022c8b0(i) == 1 &&
                kar_plclearcheckerlib__near_8022c8e0(i) == 3 &&
                r28->_088[i] <= 1440) {
              ClearChecker_SetNewUnlock(2, 0x6a);
            }
          }
          break;
        }
        break;
      case 9:
        if (r28->_022[i] != 0) {
          if (r28->_208[i] >= 150) {
            ClearChecker_SetNewUnlock(2, 0x19);
          }
          if (r28->_208[i] >= 200) {
            ClearChecker_SetNewUnlock(2, 0x1b);
          }
          if (r28->_208[i] == 90) {
            ClearChecker_SetNewUnlock(2, 0x1a);
          }
        }
        break;
      case 8:
        if (r28->_022[i] != 0) {
          if (r28->_21C[i] / 0.304788f >= 330.0f) {
            ClearChecker_SetNewUnlock(2, 0x1f);
          }
          if (r28->_21C[i] / 0.304788f >= 660.0f) {
            ClearChecker_SetNewUnlock(2, 0x20);
          }
          if (r28->_21C[i] / 0.304788f >= 1300.0f) {
            ClearChecker_SetNewUnlock(2, 0x21);
          }
          if (kar_plclearcheckerlib__802315c0(i) >= 1800) {
            ClearChecker_SetNewUnlock(2, 0x22);
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
          ClearChecker_SetNewUnlock(2, 0x2f);
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
      ClearChecker_SetNewUnlock(2, 0x1d);
    }
    break;
  case 0xe:
    if (r31->_102 >= 0x32) {
      ClearChecker_SetNewUnlock(2, 0x29);
    }
    if (r31->_102 >= 0x96) {
      ClearChecker_SetNewUnlock(2, 0x2a);
    }
    if (r26 >= 2) {
      ClearChecker_SetNewUnlock(2, 0x28);
    }
    break;
  case 0xd:
    if (r31->_104 >= 0x1f4) {
      ClearChecker_SetNewUnlock(2, 0x2d);
    }
    if (r31->_104 >= 0x5dc) {
      ClearChecker_SetNewUnlock(2, 0x2e);
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
            ClearChecker_SetNewUnlock(2, 0x23);
          }
          if (r30->_208[i] >= 10) {
            ClearChecker_SetNewUnlock(2, 0x51);
          }
          break;
        
          case 10:
          if (r30->_208[i] >= 5) {
            ClearChecker_SetNewUnlock(2, 0x24);
          }
          if (r30->_208[i] >= 10) {
            ClearChecker_SetNewUnlock(2, 0x53);
          }
          break;

        case 0xb:
          if (r30->_208[i] >= 5) {
            ClearChecker_SetNewUnlock(2, 0x25);
          }
          break;

        case 0xc:
          if (r30->_208[i] >= 5) {
            ClearChecker_SetNewUnlock(2, 0x26);
          }
          if (r30->_208[i] >= 10) {
            ClearChecker_SetNewUnlock(2, 0x55);
          }
          break;

        case 0xd:
          if (r30->_208[i] >= 5) {
            ClearChecker_SetNewUnlock(2, 0x27);
          }
          if (r30->_208[i] >= 10) {
            ClearChecker_SetNewUnlock(2, 0x57);
          }
          break;
        }
        break;
      case 0xd:
        switch (r31->_5AD) {
        case 7:
          if (r30->_208[i] >= 50) {
            ClearChecker_SetNewUnlock(2, 0x2b);
          }
          if (r30->_208[i] >= 75) {
            ClearChecker_SetNewUnlock(2, 0x59);
          }
          break;
        case 8:
          if (r30->_208[i] >= 30) {
            ClearChecker_SetNewUnlock(2, 0x2c);
          }
          if (r30->_208[i] >= 40) {
            ClearChecker_SetNewUnlock(2, 0x5b);
          }
          break;
        }
        break;
      }
    }
  }
}

void kar_gmclearchecker__near_8004f270(int unused) {
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

void kar_gmclearchecker__near_8004f33c(int unused) { fn_80282300(); }

void kar_gmclearchecker__near_8004f35c(int unused) { fn_8028236C(); }

void kar_gmclearchecker__near_8004f37c(int unused) { fn_80282004(); }

void kar_gmclearchecker__near_8004f39c(int unused) {
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

typedef void (*intFunc)(int);

typedef struct {
  /* 0x0 */ int _0;
  /* 0x4 */ intFunc _4;
  /* 0x8 */ int _8;
  /* 0xC */ int _C;
} lbl_80497768_sub;

lbl_80497768_sub lbl_80497768[] = {
    {0x000, NULL, 0x07, 0x11},
    {0x0DC, kar_gmclearchecker__near_8004f39c, 0x11, 0x11},
    {0x109, NULL, 0x0A, 0x11},
    {0x120, kar_gmclearchecker__near_8004f270, 0x11, 0x11},
    {0x12C, NULL, 0x0E, 0x11},
    {0x154, kar_gmclearchecker__near_8004f37c, 0x11, 0x11},
    {0x15E, NULL, 0x11, 0x07},
    {0x162, kar_gmclearchecker__near_8004f270, 0x11, 0x11},
    {0x172, NULL, 0x11, 0x0A},
    {0x1C0, kar_gmclearchecker__near_8004f270, 0x11, 0x11},
    {0x1DC, NULL, 0x09, 0x11},
    {0x23E, kar_gmclearchecker__near_8004f270, 0x11, 0x11},
    {0x280, NULL, 0x05, 0x11},
    {0x28E, NULL, 0x11, 0x0E},
    {0x2CE, kar_gmclearchecker__near_8004f270, 0x11, 0x11},
    {0x320, NULL, 0x11, 0x05},
    {0x334, NULL, 0x0C, 0x11},
    {0x352, NULL, 0x11, 0x09},
    {0x378, kar_gmclearchecker__near_8004f270, 0x11, 0x11},
    {0x384, NULL, 0x0D, 0x11},
    {0x421, NULL, 0x11, 0x0C},
    {0x433, NULL, 0x06, 0x11},
    {0x451, kar_gmclearchecker__near_8004f270, 0x11, 0x11},
    {0x486, kar_gmclearchecker__near_8004f270, 0x11, 0x11},
    {0x492, NULL, 0x11, 0x0D},
    {0x49C, NULL, 0x11, 0x06},
    {0x4BF, NULL, 0x02, 0x11},
    {0x524, kar_gmclearchecker__near_8004f270, 0x11, 0x11},
    {0x55A, NULL, 0x11, 0x02},
    {0x564, NULL, 0x00, 0x11},
    {0x59E, kar_gmclearchecker__near_8004f270, 0x11, 0x11},
    {0x618, NULL, 0x11, 0x00},
    {0x6AE, NULL, 0x10, 0x11},
    {0x6E0, NULL, 0x03, 0x11},
    {0x71A, kar_gmclearchecker__near_8004f270, 0x11, 0x11},
    {0x730, NULL, 0x11, 0x10},
    {0x7C4, kar_gmclearchecker__near_8004f270, 0x11, 0x11},
    {0x7DA, NULL, 0x11, 0x03},
    {0x898, NULL, 0x0B, 0x11},
    {0x898, NULL, 0x08, 0x11},
    {0x8CA, kar_gmclearchecker__near_8004f33c, 0x11, 0x11},
    {0x904, kar_gmclearchecker__near_8004f270, 0x11, 0x11},
    {0x92E, kar_gmclearchecker__near_8004f35c, 0x11, 0x11},
    {0x91A, NULL, 0x11, 0x0B},
    {0x954, kar_gmclearchecker__near_8004f270, 0x11, 0x11},
    {0x960, NULL, 0x0F, 0x11},
    {0x96A, NULL, 0x11, 0x08},
    {0x9F4, kar_gmclearchecker__near_8004f270, 0x11, 0x11},
    {0xA0A, NULL, 0x11, 0x0F},
    {0xB36, NULL, 0x04, 0x11},
    {0xB5C, kar_gmclearchecker__near_8004f270, 0x11, 0x11},
    {0xB72, NULL, 0x11, 0x04},
    {0xBA4, NULL, 0x01, 0x11},
    {0xC60, kar_gmclearchecker__near_8004f270, 0x11, 0x11},
    {0xC76, NULL, 0x11, 0x01},
    {-1, NULL, 0x11, 0x11},
};

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
    if (HSD_PadCopyStatus._8 & 0x1000) {
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
