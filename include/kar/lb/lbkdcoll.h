#ifndef _KAR_LB_LBKDCOLL_H_
#define _KAR_LB_LBKDCOLL_H_

#include <dolphin/types.h>

#if defined(VERSION_GKYJ01)
#define kar_lbkdcoll__near_800726f0 fn_80071E04
#define kar_lbkdcoll__near_80072aa0 fn_800721B4
#define kar_lbkdcoll__near_80072c90 fn_800723A4
#define kar_lbkdcoll__near_80076f8c fn_800766A0
#elif defined(VERSION_GKYP01)
#define kar_lbkdcoll__near_800726f0 fn_80073030
#define kar_lbkdcoll__near_80072aa0 fn_800733E0
#define kar_lbkdcoll__near_80072c90 fn_800735D0
#define kar_lbkdcoll__near_80076f8c fn_80077F98
#endif

s32 kar_lbkdcoll__near_800726e0(void);
void kar_lbkdcoll__near_800726f0(s32 arg0);
void kar_lbkdcoll__near_80072aa0(void);
void kar_lbkdcoll__near_80072c90(s32 arg0, char* archive_name, s32 arg2,
                                 s32 arg3, s32 arg4, s32 arg5, s32 arg6,
                                 s32 arg7, s32 arg8);
void kar_lbkdcoll__near_80075360(s32 arg0);
void kar_lbkdcoll__near_80075434(s32 arg0);
void kar_lbkdcoll__near_80076f8c(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                                 s32 arg4, f32 arg5, f32 arg6, f32 arg7,
                                 f32 arg8);

#endif
