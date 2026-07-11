#ifndef __KAR_SHADOW_H_
#define __KAR_SHADOW_H_

#include <dolphin/types.h>

#if defined(VERSION_GKYJ01)
#define kar_shadow__near_8007b650 fn_8007ABD8
#elif defined(VERSION_GKYP01)
#define kar_shadow__near_8007b650 fn_8007C7F8
#endif

s32 kar_shadow__near_8007b650(void);
u8 kar_shadow__near_8007b990(void);
void shadowRendering(void);

#endif
