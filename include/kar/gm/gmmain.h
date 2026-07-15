#ifndef __GMMAIN_H_
#define __GMMAIN_H_

#include <dolphin/types.h>

#if defined(VERSION_GKYJ01)
#define kar_gmmain__near_80005ce0 fn_80005C60
#elif defined(VERSION_GKYP01)
#define kar_gmmain__near_80005ce0 fn_80005DE8
#endif

u32 kar_gmmain__near_80005ce0(void);
void* kar_gmmain__near_80005cbc(void);
s32 kar_gmmain__near_80005d04(s32 bit);
s32 kar_gmmain__near_80005d54(void);
void kar_gmmain__near_80005d78(s32 bit);
void kar_gmmain__near_80005dcc(s32 bit);
s32 kar_gmmain__near_80005f14(void);
void kar_gmmain__near_8000631c(void);
void kar_gmmain__near_80006354(s8 value);
u8 kar_gmmain__near_80006384(void);
void kar_gmmain__near_800063a8(void);
void kar_gmmain__near_800064f0(void);
void kar_gmmain__near_80006518(void);
void kar_gmmain__near_80006540(void* callbacks);
s32 kar_gmmain__near_800067a4(void);
void kar_gmmain__near_80006b58(void);
void* kar_gmmain__near_80006c14(void);
void* kar_gmmain__near_80006c20(void);
s32 kar_gmmain__near_80006c30(void);
void* kar_gmmain__near_80006c38(void);
void kar_gmmain__near_80006c48(void);
void kar_gmmain__near_80006d80(s8 index);
void kar_gmmain__near_80006e48(s8 index);
void kar_gmmain__near_80006eb8(void);
void* kar_gmmain__near_80006eec(void);

#endif // !__GMMAIN_H_
