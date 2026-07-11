#ifndef __GMMAIN_H_
#define __GMMAIN_H_

#include <dolphin/types.h>

#if defined(VERSION_GKYJ01)
#define kar_gmmain__near_80005ce0 fn_80005C60
#elif defined(VERSION_GKYP01)
#define kar_gmmain__near_80005ce0 fn_80005DE8
#endif

u32 kar_gmmain__near_80005ce0(void);
void kar_gmmain__near_800064f0(void);
void* kar_gmmain__near_80006eec(void);

#endif // !__GMMAIN_H_
