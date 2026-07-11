#ifndef _GOBJPROC_H_
#define _GOBJPROC_H_

#include <dolphin/types.h>

typedef void (*HSD_DebugConsoleCallback)(void* context, ...);

void HSD_Panic(const char* file, s32 line, const char* msg);
HSD_DebugConsoleCallback
HSD_SetDebugConsoleCallback(HSD_DebugConsoleCallback callback);

#endif
