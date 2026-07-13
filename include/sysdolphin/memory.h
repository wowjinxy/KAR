#ifndef _memory_h_
#define _memory_h_

#include <dolphin/types.h>

typedef struct _HSD_MemCallbacks {
    void* (*alloc)(u32 size, u32 align, u32 flags);
    void (*free)(void* ptr);
    void (*clear)(void);
    u32 (*get_remain)(void);
    s32 (*check_own)(void* ptr);
} HSD_MemCallbacks;

void _HSD_MemSetCallbacks(HSD_MemCallbacks* callbacks, u32 size);
void* _HSD_MemAlloc(u32 size, u32 align, u32 flags);
u32 _HSD_MemGetRemain(void);
void _HSD_MemClear(void);
s32 _HSD_MemCheckOwn(void* ptr);
void* HSD_Alloc(u32 size);
void HSD_Free(void* ptr);

#endif
