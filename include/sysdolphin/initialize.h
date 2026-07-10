#ifndef _initialize_h_
#define _initialize_h_

#include <global.h>

#include <dolphin/gx/gxtypes.h>
#include <sysdolphin/video.h>

typedef struct _HSD_MemReport
{
    u32 total;
    u32 system;
    u32 xfb;
    u32 gxfifo;
    u32 heap;
} HSD_MemReport;

typedef s32 OSHeapHandle;

typedef enum _HSD_InitParam {
    HSD_INIT_FIFO_SIZE,
    HSD_INIT_XFB_MAX_NUM,
    HSD_INIT_HEAP_MAX_NUM,
    HSD_INIT_AUDIO_HEAP_SIZE,
    HSD_INIT_RENDER_MODE_OBJ,
    HSD_INIT_HEAP_MAX_SIZE,
    HSD_INIT_NEXT_ARENA,
    HSD_INIT_FILL_PATTERN,
    HSD_INIT_MEMORY_CALLBACKS
} HSD_InitParam;

void HSD_Init(void);
void HSD_GXSetFifoObj(GXFifoObj* fifo);
void HSD_DVDInit(void);
void* HSD_AllocateFIFO(u32 size);
void** HSD_AllocateXFB(s32 nbuffer, GXRenderModeObj* rmode);
void HSD_GXInit(void);
void HSD_OSInit(void);
OSHeapHandle HSD_GetHeap(void);
void HSD_SetHeap(OSHeapHandle handle);
void HSD_GetNextArena(void** lo, void** hi);
void HSD_ClearHeap(void);
HSD_RenderPass HSD_GetCurrentRenderPass(void);
void HSD_StartRender(HSD_RenderPass pass);
void HSD_EndRender(void);
void HSD_ObjInit(void);
void HSD_ObjDumpStat(void);
bool HSD_SetInitParameter(HSD_InitParam param, ...);

#endif
