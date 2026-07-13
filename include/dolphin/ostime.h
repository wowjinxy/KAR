#ifndef _OSTIME_H_
#define _OSTIME_H_

#include <dolphin/types.h>

s64 OSGetTime(void);
u32 OSGetTick(void);
s64 __OSGetSystemTime(void);

#endif
