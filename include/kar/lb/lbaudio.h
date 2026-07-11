#ifndef __LBAUDIO_H_
#define __LBAUDIO_H_

#include <dolphin/types.h>

#if defined(VERSION_GKYJ01)
#define kar_lbaudio__near_8006176c fn_80060E94
#elif defined(VERSION_GKYP01)
#define kar_lbaudio__near_8006176c fn_8006207C
#endif

void kar_lbaudio__near_8005e1a8(s32 arg0);
void kar_lbaudio__near_8005e5d0(void);
void kar_lbaudio__near_80061658(void);
void kar_lbaudio__near_8006176c(u32 sound_id);

#endif
