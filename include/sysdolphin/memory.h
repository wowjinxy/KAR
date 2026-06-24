#ifndef _memory_h_
#define _memory_h_

#include <dolphin/types.h>

void* HSD_Alloc(u32 size);
void HSD_Free(void* ptr);

#endif
