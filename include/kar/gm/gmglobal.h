#ifndef __GMGLOBAL_H_
#define __GMGLOBAL_H_

#include <dolphin/types.h>

typedef struct {
  /* 0x000 */ u32 _0;
  /* 0x004 */ u8 pad_0[120];
  /* 0x124 */ u8 clearchecker_flags[120];
} GmGlobalSaveData;

typedef struct {
  /* 0x000 */ u8 pad_000[0xF4];
  /* 0x0F4 */ s32 clearchecker_total_0;
  /* 0x0F8 */ s32 clearchecker_total_1;
  /* 0x0FC */ s32 clearchecker_total_2;
  /* 0x100 */ s32 clearchecker_total_3;
  /* 0x104 */ s32 clearchecker_total_4;
  /* 0x108 */ s32 clearchecker_total_5;
  /* 0x10C */ s32 clearchecker_total_6;
  /* 0x110 */ s32 clearchecker_total_7;
  /* 0x114 */ s32 clearchecker_total_8;
} GmGlobalData;

typedef struct  {
  /* 0x000 */ u8 pad_000[0x174];
  /* 0x174 */ u8 *type_tables[3];
  /* 0x180 */ char type_error[0x1C];
  /* 0x19C */ char source_file[0x11];
} GmClearCheckerSharedData;

typedef struct {
  /* 0x000 */ u8 pad[0x22];
  /* 0x022 */ s8 _022[5];
  artificial_padding(0x22, 0x88, s8[5]);
  /* 0x022 */ int _088[5];
  artificial_padding(0x88, 0x208, int[5]);
  /* 0x208 */ int _208[5];
  /* 0x21C */ f32 _21C[5];
} GmMainData_830;

typedef struct {
  /* 0x000 */ u8 pad_00[0x2B];
  /* 0x02B */ s8 clearchecker_flag;
  artificial_padding(0x2b, 0x5ad, s8);
  /* 0x5AD */ s8 _5AD;
  artificial_padding(0x5ad, 0x830, s8);
  /* 0x830 */ GmMainData_830 _830;
  artificial_padding(0x830, 0xa88, GmMainData_830);
  /* 0xA88 */ s32 clearchecker_index;
  artificial_padding(0xa88, 0xa94, s32);
  /* 0xA94 */ s8 _A94;
} GmMainData;


typedef struct {
  /* 0x000 */ u8 pad[0xf4];
  /* 0x0F4 */ u8 _0F4;
  /* 0x0F5 */ u8 _0F5;
  /* 0x0F6 */ u8 _0F6;
  /* 0x0F7 */ u8 _0F7;
  /* 0x0F8 */ u8 _0F8;
  /* 0x0F9 */ u8 _0F9;
  /* 0x0FA */ u8 _0FA;
  /* 0x0FB */ u8 _0FB;
  /* 0x0FC */ u8 _0FC;
  /* 0x0FD */ u8 _0FD;
  /* 0x0FE */ u8 _0FE;
  /* 0x0FF */ u8 _0FF;
  /* 0x100 */ u16 _100;
  /* 0x102 */ u16 _102;
  /* 0x104 */ u16 _104;
  /* 0x106 */ u16 _106;
  /* 0x108 */ u16 _108;
  /* 0x10A */ u16 _10A; // unused?
  /* 0x10C */ f32 _10C;
  /* 0x110 */ int _110;
} kar_gmglobal__near_8000774c_s;

GmGlobalSaveData *kar_gmglobal__800076a0(int);
void kar_gmglobal__near_80007640(void);
GmGlobalData *kar_gmglobal__near_8000771c(void);
void kar_gmglobal__near_80007808(void);
s32 kar_gmglobal__near_80007e8c(s32 arg0);
s32 kar_gmglobal__near_80007ee4(s32 arg0);
void kar_gmglobal__near_80007f6c(s32 arg0, s32 arg1);
s32 kar_gmglobal__near_80008038(s32 arg0);
void kar_gmglobal__near_800080c0(s32 arg0, s32 arg1);
void kar_gmglobal__near_800088c8(s8 value);
kar_gmglobal__near_8000774c_s *kar_gmglobal__near_8000774c();

#endif // !__GMGLOBAL_H_
